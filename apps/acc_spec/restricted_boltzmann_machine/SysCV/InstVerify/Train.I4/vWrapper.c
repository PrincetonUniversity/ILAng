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
struct l_class_OC_model_train;
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
struct l_unnamed22;
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
typedef struct l_class_OC_model_train l_class_OC_model_train;
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
typedef struct l_unnamed22 l_unnamed22;
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

struct l_class_OC_model_train {
  struct l_class_OC_SysCArray1D field0;
  unsigned long long field1;
  unsigned long long field2;
  struct l_class_OC_SysCArray1D field3;
  struct l_class_OC_SysCArray1D field4;
  unsigned long long field5;
  unsigned long long field6;
  unsigned long long field7;
  unsigned long long field8;
  unsigned long long field9;
  unsigned long long field10;
  unsigned long long field11;
  unsigned long long field12;
  unsigned long long field13;
  unsigned long long field14;
  unsigned long long field15;
  struct l_class_OC_SysCArray1D field16;
  struct l_unnamed1 field17;
  unsigned long long field18;
  struct l_class_OC_SysCArray1D field19;
  unsigned long long field20;
  unsigned long long field21;
  unsigned long long field22;
  unsigned long long field23;
  unsigned long long field24;
  unsigned long long field25;
  unsigned long long field26;
  unsigned long long field27;
  unsigned long long field28;
  unsigned long long field29;
  unsigned long long field30;
  unsigned long long field31;
  struct l_unnamed2 field32;
  struct l_class_OC_SysCArray1D field33;
  unsigned long long field34;
  unsigned long long field35;
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

struct l_unnamed10 { unsigned char array[20]; };

struct l_unnamed11 { unsigned char array[15]; };

struct l_unnamed12 { unsigned char array[21]; };

struct l_unnamed13 { unsigned char array[10]; };

struct l_unnamed14 { unsigned char array[8]; };

struct l_unnamed15 { unsigned char array[23]; };

struct l_unnamed16 { unsigned char array[13]; };

struct l_unnamed17 { unsigned char array[4]; };

struct l_unnamed18 { unsigned char array[9]; };

struct l_unnamed19 { unsigned char array[5]; };

struct l_unnamed20 { unsigned char array[19]; };

struct l_unnamed3 {
  unsigned int field0;
  void  (*field1) (void);
};

struct l_unnamed21 { struct l_unnamed3 array[1]; };

struct l_unnamed22 { float array[5]; };

struct l_unnamed5 { unsigned char array[12]; };

struct l_unnamed6 { unsigned char array[16]; };

struct l_unnamed7 { unsigned char array[11]; };

struct l_unnamed8 { unsigned char array[17]; };

struct l_unnamed9 { unsigned char array[18]; };


/* External Global Variable Declarations */
extern unsigned short divide_p1;
extern unsigned short divide_p2;
extern unsigned short divide_r;
extern unsigned short rand_r;
extern unsigned short sigmoid_p1;
extern unsigned short sigmoid_r;
extern unsigned short to_int_exp_p1;
extern unsigned short to_int_exp_r;
extern unsigned char t;
extern struct l_class_OC_model_train GM;
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
extern unsigned int train_upc;
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
bool _ZN11model_train9assumps_0Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_class_OC_SysCArray1D _ZN11model_train18cppUpdateFun_edgesElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIhLj65536EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int __gxx_personality_v0(int vararg_dummy_arg,...);
void _Unwind_Resume_or_Rethrow(unsigned char *);
struct l_class_OC_SysCArray1D *_ZN8type_memIhLj65536EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memIbLj65536EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memIbLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memIbLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memIhLj65536EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZSt9terminatev(void);
struct l_class_OC_SysCArray1D _ZN11model_train24cppUpdateFun_hidden_unitElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memIhLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D *_ZN8type_memIbLj128EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned long long _ZN11model_train18cppUpdateFun_indexElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train19cppUpdateFun_jstateElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train23cppUpdateFun_loop_countElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train21cppUpdateFun_per_v_pcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_class_OC_SysCArray1D _ZN11model_train16cppUpdateFun_posElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIbLj65536EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D *_ZN8type_memIbLj65536EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj65536EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_unnamed1 _ZN11model_train17cppUpdateFun_pow2Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIjLj8EEC1Ev(struct l_unnamed1 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_unnamed1 *_ZN8type_memIjLj8EEaSERKS0_(struct l_unnamed1 *llvm_cbe_this, struct l_unnamed1 *llvm_cbe_r) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memItLj8EE2rdEl(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EE2wrEll(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EED1Ev(struct l_unnamed1 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned long long _ZN11model_train22cppUpdateFun_sumOfpow2Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train24cppUpdateFun_train_h_cntElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train29cppUpdateFun_train_input_doneElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train22cppUpdateFun_train_maxElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train22cppUpdateFun_train_sumElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train22cppUpdateFun_train_upcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train24cppUpdateFun_train_v_cntElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_train16cppUpdateFun_upcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_unnamed2 _ZN11model_train28cppUpdateFun_visibleEnergiesElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memItLj8EEC1Ev(struct l_unnamed2 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_unnamed2 *_ZN8type_memItLj8EEaSERKS0_(struct l_unnamed2 *llvm_cbe_this, struct l_unnamed2 *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EE2wrEll(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EED1Ev(struct l_unnamed2 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D _ZN11model_train25cppUpdateFun_visible_unitElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_class_OC_SysCArray1D *_ZN8type_memIbLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
unsigned long long _ZN8type_memIjLj8EE2rdEl(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11model_train6updateElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
static void __cxx_global_var_init(void);
void _ZN11model_trainC1Ev(struct l_class_OC_model_train *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11model_trainD1Ev(struct l_class_OC_model_train *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int __cxa_atexit(void  (*) (unsigned char *), unsigned char *, unsigned char *);
void _Z4waitv(void);
void _Z15reset_signal_isib(unsigned int , bool );
void _Z14set_stack_sizei(unsigned int );
unsigned long long _Z8_c_16_15f(float llvm_cbe_in);
float _Z8_b_16_15l(unsigned long long llvm_cbe_in);
void _ZN3rbm6configEv(struct l_struct_OC_rbm *llvm_cbe_this);
void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) __ATTRIBUTE_WEAK__;
bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *) __ATTRIBUTE_WEAK__;
struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEi(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned int ) __ATTRIBUTE_WEAK__;
void _ZN3rbm4loadEv(struct l_struct_OC_rbm *llvm_cbe_this);
bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) __ATTRIBUTE_WEAK__;
unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned char *_ZN13SysCArray2DstIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this);
unsigned char *_ZN13SysCArray2DstIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void _ZN3rbm9train_rbmEv(struct l_struct_OC_rbm *llvm_cbe_this);
void _ZN15sc_signal_int325writeERKi(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) __ATTRIBUTE_WEAK__;
float *_ZN11SysCArray2DIfLj501ELj101EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void _ZN3rbm25activateHiddenUnits_trainEbtt(struct l_struct_OC_rbm *llvm_cbe_this, bool llvm_cbe_pingpong, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv);
unsigned char *_ZN11SysCArray1DIbLj128EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) __ATTRIBUTE_WEAK__;
unsigned char *_ZN11SysCArray2DIbLj501ELj101EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void _ZN3rbm26activateVisibleUnits_trainEtt(struct l_struct_OC_rbm *llvm_cbe_this, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv);
unsigned char *_ZN11SysCArray1DIbLj512EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) __ATTRIBUTE_WEAK__;
float _ZN3rbm8rand_genEv(struct l_struct_OC_rbm *);
bool __CPROVER_array_equal(unsigned char *, unsigned char *);
float *_ZN11SysCArray1DIfLj5EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_idx) __ATTRIBUTE_WEAK__;
void __CPROVER_array_copy(unsigned char *, unsigned char *);
void _ZN3rbm27activateHiddenUnits_predictEbtt(struct l_struct_OC_rbm *llvm_cbe_this, bool llvm_cbe_pingpong, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv);
void _ZN3rbm28activateVisibleUnits_predictEtt(struct l_struct_OC_rbm *llvm_cbe_this, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv);
unsigned long long _Z6round_l(unsigned long long );
static void __cxx_global_var_init32(void);
void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int main(void);
void _ZN8type_memIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned char *__CPROVER_malloc(unsigned long long );
void _ZN8type_memItLj8EEC2Ev(struct l_unnamed2 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EEC2Ev(struct l_unnamed1 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj65536EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EED2Ev(struct l_unnamed2 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EED2Ev(struct l_unnamed1 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
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
void _ZN11model_trainD2Ev(struct l_class_OC_model_train *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11model_trainC2Ev(struct l_class_OC_model_train *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EEC1El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EEC1El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memItLj8EEC2El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIjLj8EEC2El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIbLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
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
extern unsigned char t;
static struct l_unnamed0 _OC_str;
extern struct l_class_OC_model_train GM;
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
extern unsigned int train_upc;
extern unsigned int upc;
static struct l_unnamed5 _OC_str1;
static struct l_unnamed6 _OC_str2;
static struct l_unnamed7 _OC_str3;
static struct l_unnamed8 _OC_str4;
static struct l_unnamed9 _OC_str5;
static struct l_unnamed6 _OC_str6;
static struct l_unnamed6 _OC_str7;
static struct l_unnamed10 _OC_str8;
static struct l_unnamed8 _OC_str9;
static struct l_unnamed11 _OC_str10;
static struct l_unnamed6 _OC_str11;
static struct l_unnamed8 _OC_str12;
static struct l_unnamed8 _OC_str13;
static struct l_unnamed11 _OC_str14;
static struct l_unnamed6 _OC_str15;
static struct l_unnamed11 _OC_str16;
static struct l_unnamed13 _OC_str17;
static struct l_unnamed15 _OC_str18;
static struct l_unnamed6 _OC_str19;
static struct l_unnamed6 _OC_str20;
static struct l_unnamed16 _OC_str21;
static struct l_unnamed6 _OC_str22;
static struct l_unnamed9 _OC_str23;
static struct l_unnamed9 _OC_str24;
static struct l_unnamed7 _OC_str25;
static struct l_unnamed12 _OC_str26;
static struct l_unnamed9 _OC_str27;
static struct l_unnamed13 _OC_str28;
static struct l_unnamed6 _OC_str29;
static struct l_unnamed11 _OC_str30;
static struct l_unnamed14 _OC_str31;
extern struct l_struct_OC_rbm IMPL;
static struct l_unnamed17 _OC_str33;
static struct l_unnamed17 _OC_str34;
static struct l_unnamed18 _OC_str35;
static struct l_unnamed13 _OC_str36;
static struct l_unnamed7 _OC_str37;
static struct l_unnamed18 _OC_str38;
static struct l_unnamed14 _OC_str39;
static struct l_unnamed18 _OC_str40;
static struct l_unnamed13 _OC_str41;
static struct l_unnamed7 _OC_str42;
static struct l_unnamed18 _OC_str43;
static struct l_unnamed18 _OC_str44;
static struct l_unnamed19 _OC_str45;
static struct l_unnamed13 _OC_str46;
static struct l_unnamed6 _OC_str47;
static struct l_unnamed8 _OC_str48;
static struct l_unnamed11 _OC_str49;
static struct l_unnamed11 _OC_str50;
static struct l_unnamed20 _OC_str51;
static struct l_unnamed6 _OC_str52;


/* Global Variable Definitions and Initialization */
unsigned short divide_p1;
unsigned short divide_p2;
unsigned short divide_r;
unsigned short rand_r;
unsigned short sigmoid_p1;
unsigned short sigmoid_r;
unsigned short to_int_exp_p1;
unsigned short to_int_exp_r;
unsigned char t;
static struct l_unnamed0 _OC_str = { "test3" };
struct l_class_OC_model_train GM;
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
unsigned int train_upc;
unsigned int upc;
static struct l_unnamed5 _OC_str1 = { "Config done" };
static struct l_unnamed6 _OC_str2 = { "init_done_match" };
static struct l_unnamed7 _OC_str3 = { "done_match" };
static struct l_unnamed8 _OC_str4 = { "num_hidden_match" };
static struct l_unnamed9 _OC_str5 = { "num_visible_match" };
static struct l_unnamed6 _OC_str6 = { "num_users_match" };
static struct l_unnamed6 _OC_str7 = { "num_loops_match" };
static struct l_unnamed10 _OC_str8 = { "num_testusers_match" };
static struct l_unnamed8 _OC_str9 = { "num_movies_match" };
static struct l_unnamed11 _OC_str10 = { "rd_index_match" };
static struct l_unnamed6 _OC_str11 = { "rd_length_match" };
static struct l_unnamed8 _OC_str12 = { "rd_request_match" };
static struct l_unnamed8 _OC_str13 = { "wr_request_match" };
static struct l_unnamed11 _OC_str14 = { "wr_index_match" };
static struct l_unnamed6 _OC_str15 = { "wr_length_match" };
static struct l_unnamed11 _OC_str16 = { "data_out_match" };
static struct l_unnamed13 _OC_str17 = { "upc_match" };
static struct l_unnamed15 _OC_str18 = { "train_input_done_match" };
static struct l_unnamed6 _OC_str19 = { "train_sum_match" };
static struct l_unnamed6 _OC_str20 = { "sumOfpow2_match" };
static struct l_unnamed16 _OC_str21 = { "jstate_match" };
static struct l_unnamed6 _OC_str22 = { "train_upc_match" };
static struct l_unnamed9 _OC_str23 = { "train_v_cnt_match" };
static struct l_unnamed9 _OC_str24 = { "train_h_cnt_match" };
static struct l_unnamed7 _OC_str25 = { "data_match" };
static struct l_unnamed12 _OC_str26 = { "predict_result_match" };
static struct l_unnamed9 _OC_str27 = { "hidden_unit_match" };
static struct l_unnamed13 _OC_str28 = { "pos_match" };
static struct l_unnamed6 _OC_str29 = { "train_max_match" };
static struct l_unnamed11 _OC_str30 = { "per_v_pc_match" };
static struct l_unnamed14 _OC_str31 = { "ind-inv" };
struct l_struct_OC_rbm IMPL;
static struct l_unnamed17 _OC_str33 = { "clk" };
static struct l_unnamed17 _OC_str34 = { "rst" };
static struct l_unnamed18 _OC_str35 = { "rd_index" };
static struct l_unnamed13 _OC_str36 = { "rd_length" };
static struct l_unnamed7 _OC_str37 = { "rd_request" };
static struct l_unnamed18 _OC_str38 = { "rd_grant" };
static struct l_unnamed14 _OC_str39 = { "data_in" };
static struct l_unnamed18 _OC_str40 = { "wr_index" };
static struct l_unnamed13 _OC_str41 = { "wr_length" };
static struct l_unnamed7 _OC_str42 = { "wr_request" };
static struct l_unnamed18 _OC_str43 = { "wr_grant" };
static struct l_unnamed18 _OC_str44 = { "data_out" };
static struct l_unnamed19 _OC_str45 = { "done" };
static struct l_unnamed13 _OC_str46 = { "cond_done" };
static struct l_unnamed6 _OC_str47 = { "conf_num_hidden" };
static struct l_unnamed8 _OC_str48 = { "conf_num_visible" };
static struct l_unnamed11 _OC_str49 = { "conf_num_users" };
static struct l_unnamed11 _OC_str50 = { "conf_num_loops" };
static struct l_unnamed20 _OC_str51 = { "conf_num_testusers" };
static struct l_unnamed6 _OC_str52 = { "conf_num_movies" };


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


bool _ZN11model_train9assumps_0Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__37;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__38;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__39;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__40;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__41;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__42;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__43;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__44;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__45;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__46;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__47;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__48;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1196;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1197;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__49;
  unsigned long long llvm_cbe_tmp__50;
  unsigned char llvm_cbe_tmp__51;

  *(&llvm_cbe_tmp__37) = llvm_cbe_this;
  *(&llvm_cbe_tmp__38) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__39) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__40) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__41) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__42) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__43) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__44) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__45) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__46) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__47) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__48) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__49 = *(&llvm_cbe_tmp__37);
  llvm_cbe_tmp__50 = *((&llvm_cbe_tmp__49->field26));
  *(&llvm_cbe_cppVar_1197) = (((unsigned char )(bool )(llvm_cbe_tmp__50 == 1ull)));
  llvm_cbe_tmp__51 = *(&llvm_cbe_cppVar_1197);
  return (((((bool )llvm_cbe_tmp__51&1u))&1));
}


struct l_class_OC_SysCArray1D _ZN11model_train18cppUpdateFun_edgesElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__52;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__53;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__54;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__55;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__56;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__57;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__58;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__59;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__60;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__61;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__62;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__63;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_949;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_950;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_952;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_953;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_955;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_956;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_961;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_962;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_963;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_964;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_965;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_966;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_967;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_968;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_969;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_970;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_971;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_972;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_973;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_974;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_975;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_978;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_979;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_980;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_981;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_976;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_977;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_982;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_983;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_985;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_986;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_987;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_988;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_984;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_960;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_957;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_958;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_959;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_989;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_954;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__64;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__65;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_951;    /* Address-exposed local */
  bool llvm_cbe_tmp__66;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__67;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__68;
  unsigned long long llvm_cbe_tmp__69;
  unsigned char llvm_cbe_tmp__70;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__71;
  unsigned long long llvm_cbe_tmp__72;
  unsigned char llvm_cbe_tmp__73;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__74;
  unsigned long long llvm_cbe_tmp__75;
  unsigned char llvm_cbe_tmp__76;
  unsigned long long llvm_cbe_tmp__77;
  unsigned long long llvm_cbe_tmp__78;
  unsigned long long llvm_cbe_tmp__79;
  unsigned long long llvm_cbe_tmp__80;
  unsigned long long llvm_cbe_tmp__81;
  unsigned long long llvm_cbe_tmp__82;
  unsigned long long llvm_cbe_tmp__83;
  unsigned long long llvm_cbe_tmp__84;
  unsigned long long llvm_cbe_tmp__85;
  unsigned long long llvm_cbe_tmp__86;
  unsigned long long llvm_cbe_tmp__87;
  unsigned long long llvm_cbe_tmp__88;
  unsigned long long llvm_cbe_tmp__89;
  unsigned long long llvm_cbe_tmp__90;
  unsigned long long llvm_cbe_tmp__91;
  unsigned long long llvm_cbe_tmp__92;
  unsigned long long llvm_cbe_tmp__93;
  unsigned long long llvm_cbe_tmp__94;
  unsigned long long llvm_cbe_tmp__95;
  unsigned long long llvm_cbe_tmp__96;
  unsigned long long llvm_cbe_tmp__97;
  unsigned long long llvm_cbe_tmp__98;
  unsigned long long llvm_cbe_tmp__99;
  unsigned long long llvm_cbe_tmp__100;
  unsigned long long llvm_cbe_tmp__101;
  unsigned long long llvm_cbe_tmp__102;
  unsigned long long llvm_cbe_tmp__103;
  unsigned char llvm_cbe_tmp__104;
  unsigned char llvm_cbe_tmp__105;
  bool llvm_cbe_tmp__106;
  bool llvm_cbe_tmp__107;
  bool llvm_cbe_tmp__107__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__108;
  unsigned char llvm_cbe_tmp__109;
  unsigned char llvm_cbe_tmp__110;
  bool llvm_cbe_tmp__111;
  bool llvm_cbe_tmp__112;
  bool llvm_cbe_tmp__112__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__113;
  unsigned long long llvm_cbe_tmp__114;
  unsigned long long llvm_cbe_tmp__115;
  unsigned long long llvm_cbe_tmp__116;
  unsigned long long llvm_cbe_tmp__117;
  unsigned long long llvm_cbe_tmp__118;
  unsigned long long llvm_cbe_tmp__119;
  unsigned long long llvm_cbe_tmp__120;
  unsigned long long llvm_cbe_tmp__121;
  unsigned long long llvm_cbe_tmp__122;
  unsigned long long llvm_cbe_tmp__123;
  unsigned long long llvm_cbe_tmp__124;
  unsigned long long llvm_cbe_tmp__125;
  unsigned long long llvm_cbe_tmp__126;
  unsigned char llvm_cbe_tmp__127;
  unsigned char llvm_cbe_tmp__128;
  unsigned char llvm_cbe_tmp__129;
  bool llvm_cbe_tmp__130;
  bool llvm_cbe_tmp__131;
  bool llvm_cbe_tmp__131__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__132;
  unsigned long long llvm_cbe_tmp__133;
  unsigned long long llvm_cbe_tmp__134;
  unsigned long long llvm_cbe_tmp__135;
  unsigned long long llvm_cbe_tmp__136;
  unsigned long long llvm_cbe_tmp__137;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__138;
  unsigned long long llvm_cbe_tmp__139;
  unsigned long long llvm_cbe_tmp__140;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__141;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__142;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__143;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__144;
  bool llvm_cbe_tmp__145;

  *(&llvm_cbe_tmp__52) = llvm_cbe_this;
  *(&llvm_cbe_tmp__53) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__54) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__55) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__56) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__57) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__58) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__59) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__60) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__61) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__62) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__63) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__68 = *(&llvm_cbe_tmp__52);
  _ZN8type_memIhLj65536EEC1Ev((&llvm_cbe_cppVar_989));
  _ZN8type_memIhLj65536EEC1Ev((&llvm_cbe_cppVar_954));
  _ZN8type_memIhLj65536EEC1Ev((&llvm_cbe_cppVar_951));
  *(&llvm_cbe_tmp__66) = ((0) & 1);
  _ZN8type_memIhLj65536EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__69 = *((&llvm_cbe_tmp__68->field29));
  *(&llvm_cbe_cppVar_950) = (((unsigned char )(bool )(llvm_cbe_tmp__69 == 0ull)));
  llvm_cbe_tmp__70 = *(&llvm_cbe_cppVar_950);
  if ((((((bool )llvm_cbe_tmp__70&1u))&1))) {
    goto llvm_cbe_tmp__146;
  } else {
    goto llvm_cbe_tmp__147;
  }

llvm_cbe_tmp__146:
  llvm_cbe_tmp__71 = _ZN8type_memIhLj65536EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__68->field3)));
  goto llvm_cbe_tmp__148;

llvm_cbe_tmp__147:
  llvm_cbe_tmp__72 = *((&llvm_cbe_tmp__68->field29));
  *(&llvm_cbe_cppVar_953) = (((unsigned char )(bool )(llvm_cbe_tmp__72 == 1ull)));
  llvm_cbe_tmp__73 = *(&llvm_cbe_cppVar_953);
  if ((((((bool )llvm_cbe_tmp__73&1u))&1))) {
    goto llvm_cbe_tmp__149;
  } else {
    goto llvm_cbe_tmp__150;
  }

llvm_cbe_tmp__149:
  llvm_cbe_tmp__74 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_951), ((&llvm_cbe_tmp__68->field3)));
  goto llvm_cbe_tmp__151;

llvm_cbe_tmp__150:
  llvm_cbe_tmp__75 = *((&llvm_cbe_tmp__68->field29));
  *(&llvm_cbe_cppVar_956) = (((unsigned char )(bool )(llvm_cbe_tmp__75 == 2ull)));
  llvm_cbe_tmp__76 = *(&llvm_cbe_cppVar_956);
  if ((((((bool )llvm_cbe_tmp__76&1u))&1))) {
    goto llvm_cbe_tmp__152;
  } else {
    goto llvm_cbe_tmp__153;
  }

llvm_cbe_tmp__152:
  llvm_cbe_tmp__77 = *((&llvm_cbe_tmp__68->field30));
  *(&llvm_cbe_cppVar_958) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__77))));
  llvm_cbe_tmp__78 = *(&llvm_cbe_cppVar_958);
  llvm_cbe_tmp__79 = *((&llvm_cbe_tmp__68->field39));
  *(&llvm_cbe_cppVar_958) = (llvm_cbe_tmp__78 & llvm_cbe_tmp__79);
  llvm_cbe_tmp__80 = *(&llvm_cbe_cppVar_958);
  llvm_cbe_tmp__81 = *((&llvm_cbe_tmp__68->field25));
  *(&llvm_cbe_cppVar_959) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__80) + ((unsigned long long )llvm_cbe_tmp__81))));
  llvm_cbe_tmp__82 = *(&llvm_cbe_cppVar_959);
  llvm_cbe_tmp__83 = *((&llvm_cbe_tmp__68->field39));
  *(&llvm_cbe_cppVar_959) = (llvm_cbe_tmp__82 & llvm_cbe_tmp__83);
  llvm_cbe_tmp__84 = *((&llvm_cbe_tmp__68->field30));
  *(&llvm_cbe_cppVar_962) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__84))));
  llvm_cbe_tmp__85 = *(&llvm_cbe_cppVar_962);
  llvm_cbe_tmp__86 = *((&llvm_cbe_tmp__68->field39));
  *(&llvm_cbe_cppVar_962) = (llvm_cbe_tmp__85 & llvm_cbe_tmp__86);
  llvm_cbe_tmp__87 = *(&llvm_cbe_cppVar_962);
  llvm_cbe_tmp__88 = *((&llvm_cbe_tmp__68->field25));
  *(&llvm_cbe_cppVar_963) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__87) + ((unsigned long long )llvm_cbe_tmp__88))));
  llvm_cbe_tmp__89 = *(&llvm_cbe_cppVar_963);
  llvm_cbe_tmp__90 = *((&llvm_cbe_tmp__68->field39));
  *(&llvm_cbe_cppVar_963) = (llvm_cbe_tmp__89 & llvm_cbe_tmp__90);
  llvm_cbe_tmp__91 = *(&llvm_cbe_cppVar_963);
  llvm_cbe_tmp__92 = _ZN8type_memIbLj65536EE2rdEl(((&llvm_cbe_tmp__68->field16)), llvm_cbe_tmp__91);
  *(&llvm_cbe_cppVar_964) = llvm_cbe_tmp__92;
  llvm_cbe_tmp__93 = *(&llvm_cbe_cppVar_964);
  *(&llvm_cbe_cppVar_966) = (((unsigned char )(bool )(llvm_cbe_tmp__93 != 0ull)));
  llvm_cbe_tmp__94 = *((&llvm_cbe_tmp__68->field25));
  llvm_cbe_tmp__95 = *((&llvm_cbe_tmp__68->field43));
  *(&llvm_cbe_cppVar_967) = ((((signed long long )(((signed long long )llvm_cbe_tmp__94) >> ((signed long long )0ull)))) & llvm_cbe_tmp__95);
  llvm_cbe_tmp__96 = *(&llvm_cbe_cppVar_967);
  llvm_cbe_tmp__97 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__68->field4)), llvm_cbe_tmp__96);
  *(&llvm_cbe_cppVar_968) = llvm_cbe_tmp__97;
  llvm_cbe_tmp__98 = *(&llvm_cbe_cppVar_968);
  *(&llvm_cbe_cppVar_970) = (((unsigned char )(bool )(llvm_cbe_tmp__98 != 0ull)));
  llvm_cbe_tmp__99 = *((&llvm_cbe_tmp__68->field30));
  llvm_cbe_tmp__100 = *((&llvm_cbe_tmp__68->field45));
  *(&llvm_cbe_cppVar_971) = ((((signed long long )(((signed long long )llvm_cbe_tmp__99) >> ((signed long long )0ull)))) & llvm_cbe_tmp__100);
  llvm_cbe_tmp__101 = *(&llvm_cbe_cppVar_971);
  llvm_cbe_tmp__102 = _ZN8type_memIbLj512EE2rdEl(((&llvm_cbe_tmp__68->field33)), llvm_cbe_tmp__101);
  *(&llvm_cbe_cppVar_972) = llvm_cbe_tmp__102;
  llvm_cbe_tmp__103 = *(&llvm_cbe_cppVar_972);
  *(&llvm_cbe_cppVar_974) = (((unsigned char )(bool )(llvm_cbe_tmp__103 != 0ull)));
  llvm_cbe_tmp__104 = *(&llvm_cbe_cppVar_970);
  if ((((((bool )llvm_cbe_tmp__104&1u))&1))) {
    goto llvm_cbe_tmp__154;
  } else {
    llvm_cbe_tmp__107__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__155;
  }

llvm_cbe_tmp__154:
  llvm_cbe_tmp__105 = *(&llvm_cbe_cppVar_974);
  llvm_cbe_tmp__106 = ((((bool )llvm_cbe_tmp__105&1u))&1);
  llvm_cbe_tmp__107__PHI_TEMPORARY = llvm_cbe_tmp__106;   /* for PHI node */
  goto llvm_cbe_tmp__155;

llvm_cbe_tmp__155:
  llvm_cbe_tmp__107 = ((llvm_cbe_tmp__107__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_975) = (((unsigned char )(bool )llvm_cbe_tmp__107));
  llvm_cbe_tmp__108 = *(&llvm_cbe_cppVar_975);
  *(&llvm_cbe_cppVar_976) = (((unsigned char )(bool )((((((((bool )llvm_cbe_tmp__108&1u))&1)) ^ 1)&1))));
  llvm_cbe_tmp__109 = *(&llvm_cbe_cppVar_966);
  if ((((((bool )llvm_cbe_tmp__109&1u))&1))) {
    goto llvm_cbe_tmp__156;
  } else {
    llvm_cbe_tmp__112__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__157;
  }

llvm_cbe_tmp__156:
  llvm_cbe_tmp__110 = *(&llvm_cbe_cppVar_976);
  llvm_cbe_tmp__111 = ((((bool )llvm_cbe_tmp__110&1u))&1);
  llvm_cbe_tmp__112__PHI_TEMPORARY = llvm_cbe_tmp__111;   /* for PHI node */
  goto llvm_cbe_tmp__157;

llvm_cbe_tmp__157:
  llvm_cbe_tmp__112 = ((llvm_cbe_tmp__112__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_977) = (((unsigned char )(bool )llvm_cbe_tmp__112));
  llvm_cbe_tmp__113 = *(&llvm_cbe_cppVar_977);
  if ((((((bool )llvm_cbe_tmp__113&1u))&1))) {
    goto llvm_cbe_tmp__158;
  } else {
    goto llvm_cbe_tmp__159;
  }

llvm_cbe_tmp__158:
  llvm_cbe_tmp__114 = *((&llvm_cbe_tmp__68->field30));
  *(&llvm_cbe_cppVar_979) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__114))));
  llvm_cbe_tmp__115 = *(&llvm_cbe_cppVar_979);
  llvm_cbe_tmp__116 = *((&llvm_cbe_tmp__68->field39));
  *(&llvm_cbe_cppVar_979) = (llvm_cbe_tmp__115 & llvm_cbe_tmp__116);
  llvm_cbe_tmp__117 = *(&llvm_cbe_cppVar_979);
  llvm_cbe_tmp__118 = *((&llvm_cbe_tmp__68->field25));
  *(&llvm_cbe_cppVar_980) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__117) + ((unsigned long long )llvm_cbe_tmp__118))));
  llvm_cbe_tmp__119 = *(&llvm_cbe_cppVar_980);
  llvm_cbe_tmp__120 = *((&llvm_cbe_tmp__68->field39));
  *(&llvm_cbe_cppVar_980) = (llvm_cbe_tmp__119 & llvm_cbe_tmp__120);
  llvm_cbe_tmp__121 = *(&llvm_cbe_cppVar_980);
  llvm_cbe_tmp__122 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__68->field3)), llvm_cbe_tmp__121);
  *(&llvm_cbe_cppVar_981) = llvm_cbe_tmp__122;
  llvm_cbe_tmp__123 = *(&llvm_cbe_cppVar_981);
  *(&llvm_cbe_cppVar_983) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__123) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__124 = *(&llvm_cbe_cppVar_983);
  llvm_cbe_tmp__125 = *((&llvm_cbe_tmp__68->field44));
  *(&llvm_cbe_cppVar_983) = (llvm_cbe_tmp__124 & llvm_cbe_tmp__125);
  llvm_cbe_tmp__126 = *(&llvm_cbe_cppVar_983);
  *(&llvm_cbe_cppVar_960) = llvm_cbe_tmp__126;
  goto llvm_cbe_tmp__160;

llvm_cbe_tmp__159:
  llvm_cbe_tmp__127 = *(&llvm_cbe_cppVar_966);
  *(&llvm_cbe_cppVar_985) = (((unsigned char )(bool )((((((((bool )llvm_cbe_tmp__127&1u))&1)) ^ 1)&1))));
  llvm_cbe_tmp__128 = *(&llvm_cbe_cppVar_985);
  if ((((((bool )llvm_cbe_tmp__128&1u))&1))) {
    goto llvm_cbe_tmp__161;
  } else {
    llvm_cbe_tmp__131__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__162;
  }

llvm_cbe_tmp__161:
  llvm_cbe_tmp__129 = *(&llvm_cbe_cppVar_975);
  llvm_cbe_tmp__130 = ((((bool )llvm_cbe_tmp__129&1u))&1);
  llvm_cbe_tmp__131__PHI_TEMPORARY = llvm_cbe_tmp__130;   /* for PHI node */
  goto llvm_cbe_tmp__162;

llvm_cbe_tmp__162:
  llvm_cbe_tmp__131 = ((llvm_cbe_tmp__131__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_986) = (((unsigned char )(bool )llvm_cbe_tmp__131));
  llvm_cbe_tmp__132 = *(&llvm_cbe_cppVar_986);
  llvm_cbe_tmp__133 = *(&llvm_cbe_cppVar_981);
  if ((((((bool )llvm_cbe_tmp__132&1u))&1))) {
    goto llvm_cbe_tmp__163;
  } else {
    goto llvm_cbe_tmp__164;
  }

llvm_cbe_tmp__163:
  *(&llvm_cbe_cppVar_988) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__133) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__134 = *(&llvm_cbe_cppVar_988);
  llvm_cbe_tmp__135 = *((&llvm_cbe_tmp__68->field44));
  *(&llvm_cbe_cppVar_988) = (llvm_cbe_tmp__134 & llvm_cbe_tmp__135);
  llvm_cbe_tmp__136 = *(&llvm_cbe_cppVar_988);
  *(&llvm_cbe_cppVar_984) = llvm_cbe_tmp__136;
  goto llvm_cbe_tmp__165;

llvm_cbe_tmp__164:
  *(&llvm_cbe_cppVar_984) = llvm_cbe_tmp__133;
  goto llvm_cbe_tmp__165;

llvm_cbe_tmp__165:
  llvm_cbe_tmp__137 = *(&llvm_cbe_cppVar_984);
  *(&llvm_cbe_cppVar_960) = llvm_cbe_tmp__137;
  goto llvm_cbe_tmp__160;

llvm_cbe_tmp__160:
  llvm_cbe_tmp__138 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_989), ((&llvm_cbe_tmp__68->field3)));
  llvm_cbe_tmp__139 = *(&llvm_cbe_cppVar_959);
  llvm_cbe_tmp__140 = *(&llvm_cbe_cppVar_960);
  _ZN8type_memIhLj65536EE2wrEll((&llvm_cbe_cppVar_989), llvm_cbe_tmp__139, llvm_cbe_tmp__140);
  llvm_cbe_tmp__141 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_954), (&llvm_cbe_cppVar_989));
  goto llvm_cbe_tmp__166;

llvm_cbe_tmp__153:
  llvm_cbe_tmp__142 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_954), ((&llvm_cbe_tmp__68->field3)));
  goto llvm_cbe_tmp__166;

llvm_cbe_tmp__166:
  llvm_cbe_tmp__143 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_951), (&llvm_cbe_cppVar_954));
  goto llvm_cbe_tmp__151;

llvm_cbe_tmp__151:
  llvm_cbe_tmp__144 = _ZN8type_memIhLj65536EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_951));
  goto llvm_cbe_tmp__148;

llvm_cbe_tmp__148:
  *(&llvm_cbe_tmp__66) = ((1) & 1);
  *(&llvm_cbe_tmp__67) = 1u;
  llvm_cbe_tmp__145 = ((*(&llvm_cbe_tmp__66))&1);
  if (llvm_cbe_tmp__145) {
    goto llvm_cbe_tmp__167;
  } else {
    goto llvm_cbe_tmp__168;
  }

llvm_cbe_tmp__168:
  _ZN8type_memIhLj65536EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__167;

llvm_cbe_tmp__167:
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_951));
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_954));
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_989));
  return StructReturn;
}


void _ZN8type_memIhLj65536EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__169;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__170;

  *(&llvm_cbe_tmp__169) = llvm_cbe_this;
  llvm_cbe_tmp__170 = *(&llvm_cbe_tmp__169);
  _ZN8type_memIhLj65536EEC2Ev(llvm_cbe_tmp__170);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIhLj65536EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__171;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__172;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__173;
  unsigned char *llvm_cbe_tmp__174;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__175;
  unsigned char *llvm_cbe_tmp__176;

  *(&llvm_cbe_tmp__171) = llvm_cbe_this;
  *(&llvm_cbe_tmp__172) = llvm_cbe_r;
  llvm_cbe_tmp__173 = *(&llvm_cbe_tmp__171);
  llvm_cbe_tmp__174 = *((&llvm_cbe_tmp__173->field0));
  llvm_cbe_tmp__175 = *(&llvm_cbe_tmp__172);
  llvm_cbe_tmp__176 = *((&llvm_cbe_tmp__175->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__174, llvm_cbe_tmp__176);
  return llvm_cbe_tmp__173;
}


unsigned long long _ZN8type_memIbLj65536EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__177;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__178;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__179;
  unsigned long long llvm_cbe_tmp__180;
  unsigned char *llvm_cbe_tmp__181;
  unsigned char llvm_cbe_tmp__182;

  *(&llvm_cbe_tmp__177) = llvm_cbe_this;
  *(&llvm_cbe_tmp__178) = llvm_cbe_addr;
  llvm_cbe_tmp__179 = *(&llvm_cbe_tmp__177);
  llvm_cbe_tmp__180 = *(&llvm_cbe_tmp__178);
  llvm_cbe_tmp__181 = *((&llvm_cbe_tmp__179->field0));
  llvm_cbe_tmp__182 = *((&llvm_cbe_tmp__181[((signed long long )llvm_cbe_tmp__180)]));
  return (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__182&1u))&1))));
}


unsigned long long _ZN8type_memIbLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__183;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__184;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__185;
  unsigned long long llvm_cbe_tmp__186;
  unsigned char *llvm_cbe_tmp__187;
  unsigned char llvm_cbe_tmp__188;

  *(&llvm_cbe_tmp__183) = llvm_cbe_this;
  *(&llvm_cbe_tmp__184) = llvm_cbe_addr;
  llvm_cbe_tmp__185 = *(&llvm_cbe_tmp__183);
  llvm_cbe_tmp__186 = *(&llvm_cbe_tmp__184);
  llvm_cbe_tmp__187 = *((&llvm_cbe_tmp__185->field0));
  llvm_cbe_tmp__188 = *((&llvm_cbe_tmp__187[((signed long long )llvm_cbe_tmp__186)]));
  return (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__188&1u))&1))));
}


unsigned long long _ZN8type_memIbLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__189;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__190;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__191;
  unsigned long long llvm_cbe_tmp__192;
  unsigned char *llvm_cbe_tmp__193;
  unsigned char llvm_cbe_tmp__194;

  *(&llvm_cbe_tmp__189) = llvm_cbe_this;
  *(&llvm_cbe_tmp__190) = llvm_cbe_addr;
  llvm_cbe_tmp__191 = *(&llvm_cbe_tmp__189);
  llvm_cbe_tmp__192 = *(&llvm_cbe_tmp__190);
  llvm_cbe_tmp__193 = *((&llvm_cbe_tmp__191->field0));
  llvm_cbe_tmp__194 = *((&llvm_cbe_tmp__193[((signed long long )llvm_cbe_tmp__192)]));
  return (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__194&1u))&1))));
}


unsigned long long _ZN8type_memIhLj65536EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__195;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__196;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__197;
  unsigned long long llvm_cbe_tmp__198;
  unsigned char *llvm_cbe_tmp__199;
  unsigned char llvm_cbe_tmp__200;

  *(&llvm_cbe_tmp__195) = llvm_cbe_this;
  *(&llvm_cbe_tmp__196) = llvm_cbe_addr;
  llvm_cbe_tmp__197 = *(&llvm_cbe_tmp__195);
  llvm_cbe_tmp__198 = *(&llvm_cbe_tmp__196);
  llvm_cbe_tmp__199 = *((&llvm_cbe_tmp__197->field0));
  llvm_cbe_tmp__200 = *((&llvm_cbe_tmp__199[((signed long long )llvm_cbe_tmp__198)]));
  return (((unsigned long long )(unsigned char )llvm_cbe_tmp__200));
}


void _ZN8type_memIhLj65536EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__201;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__202;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__203;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__204;
  unsigned long long llvm_cbe_tmp__205;
  unsigned long long llvm_cbe_tmp__206;
  unsigned char *llvm_cbe_tmp__207;

  *(&llvm_cbe_tmp__201) = llvm_cbe_this;
  *(&llvm_cbe_tmp__202) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__203) = llvm_cbe_data;
  llvm_cbe_tmp__204 = *(&llvm_cbe_tmp__201);
  llvm_cbe_tmp__205 = *(&llvm_cbe_tmp__203);
  llvm_cbe_tmp__206 = *(&llvm_cbe_tmp__202);
  llvm_cbe_tmp__207 = *((&llvm_cbe_tmp__204->field0));
  *((&llvm_cbe_tmp__207[((signed long long )llvm_cbe_tmp__206)])) = (((unsigned char )llvm_cbe_tmp__205));
  return;
}


void _ZN8type_memIhLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__208;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__209;

  *(&llvm_cbe_tmp__208) = llvm_cbe_this;
  llvm_cbe_tmp__209 = *(&llvm_cbe_tmp__208);
  _ZN8type_memIhLj65536EED2Ev(llvm_cbe_tmp__209);
  return;
}


struct l_class_OC_SysCArray1D _ZN11model_train24cppUpdateFun_hidden_unitElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__210;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__211;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__212;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__213;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__214;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__215;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__216;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__217;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__218;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__219;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__220;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__221;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_992;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_993;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1032;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1033;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1035;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1036;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1014;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1015;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1016;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1006;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1007;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1008;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1005;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1010;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1011;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1012;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1013;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1017;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1018;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1019;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1020;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1021;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1022;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1009;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1023;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1004;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1024;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1025;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1003;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1001;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1002;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1028;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1000;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__222;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__223;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_995;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_996;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_997;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_998;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_999;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1029;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1030;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_994;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1027;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1026;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1034;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1031;    /* Address-exposed local */
  bool llvm_cbe_tmp__224;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__225;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__226;
  unsigned long long llvm_cbe_tmp__227;
  unsigned char llvm_cbe_tmp__228;
  unsigned long long llvm_cbe_tmp__229;
  unsigned long long llvm_cbe_tmp__230;
  unsigned long long llvm_cbe_tmp__231;
  unsigned long long llvm_cbe_tmp__232;
  unsigned long long llvm_cbe_tmp__233;
  unsigned long long llvm_cbe_tmp__234;
  unsigned long long llvm_cbe_tmp__235;
  unsigned char llvm_cbe_tmp__236;
  unsigned char llvm_cbe_tmp__237;
  bool llvm_cbe_tmp__238;
  bool llvm_cbe_tmp__239;
  bool llvm_cbe_tmp__239__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__240;
  unsigned long long llvm_cbe_tmp__241;
  unsigned long long llvm_cbe_tmp__242;
  unsigned char llvm_cbe_tmp__243;
  unsigned long long llvm_cbe_tmp__244;
  unsigned long long llvm_cbe_tmp__245;
  unsigned short llvm_cbe_tmp__246;
  unsigned long long llvm_cbe_tmp__247;
  unsigned char llvm_cbe_tmp__248;
  unsigned long long llvm_cbe_tmp__249;
  unsigned long long llvm_cbe_tmp__250;
  unsigned long long llvm_cbe_tmp__251;
  unsigned long long llvm_cbe_tmp__252;
  unsigned long long llvm_cbe_tmp__253;
  unsigned long long llvm_cbe_tmp__254;
  unsigned char llvm_cbe_tmp__255;
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
  unsigned long long llvm_cbe_tmp__272__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__273;
  unsigned long long llvm_cbe_tmp__274;
  unsigned long long llvm_cbe_tmp__275;
  unsigned long long llvm_cbe_tmp__276;
  unsigned long long llvm_cbe_tmp__277;
  unsigned long long llvm_cbe_tmp__278;
  unsigned long long llvm_cbe_tmp__279;
  unsigned long long llvm_cbe_tmp__280;
  unsigned long long llvm_cbe_tmp__281;
  unsigned long long llvm_cbe_tmp__282;
  unsigned long long llvm_cbe_tmp__283;
  unsigned long long llvm_cbe_tmp__284;
  unsigned short llvm_cbe_tmp__285;
  unsigned long long llvm_cbe_tmp__286;
  unsigned long long llvm_cbe_tmp__287;
  unsigned char llvm_cbe_tmp__288;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__289;
  unsigned long long llvm_cbe_tmp__290;
  unsigned long long llvm_cbe_tmp__291;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__292;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__293;
  unsigned long long llvm_cbe_tmp__294;
  unsigned long long llvm_cbe_tmp__295;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__296;
  unsigned long long llvm_cbe_tmp__297;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__298;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__299;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__300;
  unsigned long long llvm_cbe_tmp__301;
  unsigned char llvm_cbe_tmp__302;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__303;
  unsigned long long llvm_cbe_tmp__304;
  unsigned char llvm_cbe_tmp__305;
  bool llvm_cbe_tmp__306;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__307;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__308;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__309;
  bool llvm_cbe_tmp__310;

  *(&llvm_cbe_tmp__210) = llvm_cbe_this;
  *(&llvm_cbe_tmp__211) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__212) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__213) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__214) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__215) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__216) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__217) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__218) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__219) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__220) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__221) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__226 = *(&llvm_cbe_tmp__210);
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1028));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1000));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1030));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_994));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1034));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1031));
  *(&llvm_cbe_tmp__224) = ((0) & 1);
  _ZN8type_memIbLj128EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__227 = *((&llvm_cbe_tmp__226->field29));
  *(&llvm_cbe_cppVar_993) = (((unsigned char )(bool )(llvm_cbe_tmp__227 == 0ull)));
  llvm_cbe_tmp__228 = *(&llvm_cbe_cppVar_993);
  if ((((((bool )llvm_cbe_tmp__228&1u))&1))) {
    goto llvm_cbe_tmp__311;
  } else {
    goto llvm_cbe_tmp__312;
  }

llvm_cbe_tmp__311:
  llvm_cbe_tmp__229 = *((&llvm_cbe_tmp__226->field30));
  llvm_cbe_tmp__230 = *((&llvm_cbe_tmp__226->field14));
  *(&llvm_cbe_cppVar_995) = (((unsigned char )(bool )(llvm_cbe_tmp__229 == llvm_cbe_tmp__230)));
  llvm_cbe_tmp__231 = *((&llvm_cbe_tmp__226->field9));
  *(&llvm_cbe_cppVar_997) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__231) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__232 = *(&llvm_cbe_cppVar_997);
  llvm_cbe_tmp__233 = *((&llvm_cbe_tmp__226->field39));
  *(&llvm_cbe_cppVar_997) = (llvm_cbe_tmp__232 & llvm_cbe_tmp__233);
  llvm_cbe_tmp__234 = *((&llvm_cbe_tmp__226->field25));
  llvm_cbe_tmp__235 = *(&llvm_cbe_cppVar_997);
  *(&llvm_cbe_cppVar_998) = (((unsigned char )(bool )(llvm_cbe_tmp__234 == llvm_cbe_tmp__235)));
  llvm_cbe_tmp__236 = *(&llvm_cbe_cppVar_995);
  if ((((((bool )llvm_cbe_tmp__236&1u))&1))) {
    goto llvm_cbe_tmp__313;
  } else {
    llvm_cbe_tmp__239__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__314;
  }

llvm_cbe_tmp__313:
  llvm_cbe_tmp__237 = *(&llvm_cbe_cppVar_998);
  llvm_cbe_tmp__238 = ((((bool )llvm_cbe_tmp__237&1u))&1);
  llvm_cbe_tmp__239__PHI_TEMPORARY = llvm_cbe_tmp__238;   /* for PHI node */
  goto llvm_cbe_tmp__314;

llvm_cbe_tmp__314:
  llvm_cbe_tmp__239 = ((llvm_cbe_tmp__239__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_999) = (((unsigned char )(bool )llvm_cbe_tmp__239));
  llvm_cbe_tmp__240 = *(&llvm_cbe_cppVar_999);
  if ((((((bool )llvm_cbe_tmp__240&1u))&1))) {
    goto llvm_cbe_tmp__315;
  } else {
    goto llvm_cbe_tmp__316;
  }

llvm_cbe_tmp__315:
  llvm_cbe_tmp__241 = *((&llvm_cbe_tmp__226->field30));
  llvm_cbe_tmp__242 = *((&llvm_cbe_tmp__226->field14));
  *(&llvm_cbe_cppVar_1001) = (((unsigned char )(bool )(llvm_cbe_tmp__241 == llvm_cbe_tmp__242)));
  llvm_cbe_tmp__243 = *(&llvm_cbe_cppVar_1001);
  if ((((((bool )llvm_cbe_tmp__243&1u))&1))) {
    goto llvm_cbe_tmp__317;
  } else {
    goto llvm_cbe_tmp__318;
  }

llvm_cbe_tmp__317:
  llvm_cbe_tmp__244 = *((&llvm_cbe_tmp__226->field25));
  llvm_cbe_tmp__245 = *((&llvm_cbe_tmp__226->field43));
  *(&llvm_cbe_cppVar_1002) = ((((signed long long )(((signed long long )llvm_cbe_tmp__244) >> ((signed long long )0ull)))) & llvm_cbe_tmp__245);
  llvm_cbe_tmp__246 = _Z4randv();
  *(&llvm_cbe_cppVar_1004) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__246));
  llvm_cbe_tmp__247 = *((&llvm_cbe_tmp__226->field30));
  *(&llvm_cbe_cppVar_1007) = (((unsigned char )(bool )(llvm_cbe_tmp__247 == 0ull)));
  llvm_cbe_tmp__248 = *(&llvm_cbe_cppVar_1007);
  if ((((((bool )llvm_cbe_tmp__248&1u))&1))) {
    goto llvm_cbe_tmp__319;
  } else {
    goto llvm_cbe_tmp__320;
  }

llvm_cbe_tmp__319:
  *(&llvm_cbe_cppVar_1005) = 0ull;
  goto llvm_cbe_tmp__321;

llvm_cbe_tmp__320:
  llvm_cbe_tmp__249 = *((&llvm_cbe_tmp__226->field28));
  *(&llvm_cbe_cppVar_1005) = llvm_cbe_tmp__249;
  goto llvm_cbe_tmp__321;

llvm_cbe_tmp__321:
  llvm_cbe_tmp__250 = *((&llvm_cbe_tmp__226->field30));
  llvm_cbe_tmp__251 = *((&llvm_cbe_tmp__226->field45));
  *(&llvm_cbe_cppVar_1010) = ((((signed long long )(((signed long long )llvm_cbe_tmp__250) >> ((signed long long )0ull)))) & llvm_cbe_tmp__251);
  llvm_cbe_tmp__252 = *(&llvm_cbe_cppVar_1010);
  llvm_cbe_tmp__253 = _ZN8type_memIhLj512EE2rdEl(((&llvm_cbe_tmp__226->field0)), llvm_cbe_tmp__252);
  *(&llvm_cbe_cppVar_1011) = llvm_cbe_tmp__253;
  llvm_cbe_tmp__254 = *(&llvm_cbe_cppVar_1011);
  *(&llvm_cbe_cppVar_1013) = (((unsigned char )(bool )(llvm_cbe_tmp__254 == 1ull)));
  llvm_cbe_tmp__255 = *(&llvm_cbe_cppVar_1013);
  if ((((((bool )llvm_cbe_tmp__255&1u))&1))) {
    goto llvm_cbe_tmp__322;
  } else {
    goto llvm_cbe_tmp__323;
  }

llvm_cbe_tmp__322:
  llvm_cbe_tmp__256 = *((&llvm_cbe_tmp__226->field30));
  *(&llvm_cbe_cppVar_1015) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__256))));
  llvm_cbe_tmp__257 = *(&llvm_cbe_cppVar_1015);
  llvm_cbe_tmp__258 = *((&llvm_cbe_tmp__226->field39));
  *(&llvm_cbe_cppVar_1015) = (llvm_cbe_tmp__257 & llvm_cbe_tmp__258);
  llvm_cbe_tmp__259 = *(&llvm_cbe_cppVar_1015);
  llvm_cbe_tmp__260 = *((&llvm_cbe_tmp__226->field25));
  *(&llvm_cbe_cppVar_1016) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__259) + ((unsigned long long )llvm_cbe_tmp__260))));
  llvm_cbe_tmp__261 = *(&llvm_cbe_cppVar_1016);
  llvm_cbe_tmp__262 = *((&llvm_cbe_tmp__226->field39));
  *(&llvm_cbe_cppVar_1016) = (llvm_cbe_tmp__261 & llvm_cbe_tmp__262);
  llvm_cbe_tmp__263 = *(&llvm_cbe_cppVar_1016);
  llvm_cbe_tmp__264 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__226->field3)), llvm_cbe_tmp__263);
  *(&llvm_cbe_cppVar_1017) = llvm_cbe_tmp__264;
  llvm_cbe_tmp__265 = *(&llvm_cbe_cppVar_1017);
  llvm_cbe_tmp__266 = *((&llvm_cbe_tmp__226->field43));
  *(&llvm_cbe_cppVar_1018) = ((((signed long long )(((signed long long )llvm_cbe_tmp__265) >> ((signed long long )1ull)))) & llvm_cbe_tmp__266);
  llvm_cbe_tmp__267 = *(&llvm_cbe_cppVar_1018);
  llvm_cbe_tmp__268 = *((&llvm_cbe_tmp__226->field47));
  llvm_cbe_tmp__269 = *(&llvm_cbe_cppVar_1018);
  if (((llvm_cbe_tmp__267 & llvm_cbe_tmp__268) != 0ull)) {
    goto llvm_cbe_tmp__324;
  } else {
    llvm_cbe_tmp__272__PHI_TEMPORARY = llvm_cbe_tmp__269;   /* for PHI node */
    goto llvm_cbe_tmp__325;
  }

llvm_cbe_tmp__324:
  llvm_cbe_tmp__270 = *((&llvm_cbe_tmp__226->field49));
  llvm_cbe_tmp__271 = llvm_cbe_tmp__269 | llvm_cbe_tmp__270;
  llvm_cbe_tmp__272__PHI_TEMPORARY = llvm_cbe_tmp__271;   /* for PHI node */
  goto llvm_cbe_tmp__325;

llvm_cbe_tmp__325:
  llvm_cbe_tmp__272 = llvm_cbe_tmp__272__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_1019) = llvm_cbe_tmp__272;
  llvm_cbe_tmp__273 = *(&llvm_cbe_cppVar_1017);
  llvm_cbe_tmp__274 = *((&llvm_cbe_tmp__226->field38));
  *(&llvm_cbe_cppVar_1020) = ((((signed long long )(((signed long long )llvm_cbe_tmp__273) >> ((signed long long )0ull)))) & llvm_cbe_tmp__274);
  llvm_cbe_tmp__275 = *(&llvm_cbe_cppVar_1019);
  llvm_cbe_tmp__276 = *(&llvm_cbe_cppVar_1020);
  *(&llvm_cbe_cppVar_1021) = ((llvm_cbe_tmp__275 << 1ull) | llvm_cbe_tmp__276);
  llvm_cbe_tmp__277 = *(&llvm_cbe_cppVar_1021);
  llvm_cbe_tmp__278 = *((&llvm_cbe_tmp__226->field39));
  *(&llvm_cbe_cppVar_1021) = (llvm_cbe_tmp__277 & llvm_cbe_tmp__278);
  llvm_cbe_tmp__279 = *(&llvm_cbe_cppVar_1021);
  *(&llvm_cbe_cppVar_1009) = llvm_cbe_tmp__279;
  goto llvm_cbe_tmp__326;

llvm_cbe_tmp__323:
  *(&llvm_cbe_cppVar_1009) = 0ull;
  goto llvm_cbe_tmp__326;

llvm_cbe_tmp__326:
  llvm_cbe_tmp__280 = *(&llvm_cbe_cppVar_1005);
  llvm_cbe_tmp__281 = *(&llvm_cbe_cppVar_1009);
  *(&llvm_cbe_cppVar_1023) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__280) + ((unsigned long long )llvm_cbe_tmp__281))));
  llvm_cbe_tmp__282 = *(&llvm_cbe_cppVar_1023);
  llvm_cbe_tmp__283 = *((&llvm_cbe_tmp__226->field39));
  *(&llvm_cbe_cppVar_1023) = (llvm_cbe_tmp__282 & llvm_cbe_tmp__283);
  llvm_cbe_tmp__284 = *(&llvm_cbe_cppVar_1023);
  llvm_cbe_tmp__285 = _Z7sigmoidl(llvm_cbe_tmp__284);
  *(&llvm_cbe_cppVar_1024) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__285));
  llvm_cbe_tmp__286 = *(&llvm_cbe_cppVar_1004);
  llvm_cbe_tmp__287 = *(&llvm_cbe_cppVar_1024);
  *(&llvm_cbe_cppVar_1025) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__286) < ((signed long long )llvm_cbe_tmp__287))));
  llvm_cbe_tmp__288 = *(&llvm_cbe_cppVar_1025);
  if ((((((bool )llvm_cbe_tmp__288&1u))&1))) {
    goto llvm_cbe_tmp__327;
  } else {
    goto llvm_cbe_tmp__328;
  }

llvm_cbe_tmp__327:
  *(&llvm_cbe_cppVar_1003) = 1ull;
  goto llvm_cbe_tmp__329;

llvm_cbe_tmp__328:
  *(&llvm_cbe_cppVar_1003) = 0ull;
  goto llvm_cbe_tmp__329;

llvm_cbe_tmp__329:
  llvm_cbe_tmp__289 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1028), ((&llvm_cbe_tmp__226->field4)));
  llvm_cbe_tmp__290 = *(&llvm_cbe_cppVar_1002);
  llvm_cbe_tmp__291 = *(&llvm_cbe_cppVar_1003);
  _ZN8type_memIbLj128EE2wrEll((&llvm_cbe_cppVar_1028), llvm_cbe_tmp__290, llvm_cbe_tmp__291);
  llvm_cbe_tmp__292 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1000), (&llvm_cbe_cppVar_1028));
  goto llvm_cbe_tmp__330;

llvm_cbe_tmp__318:
  llvm_cbe_tmp__293 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1000), ((&llvm_cbe_tmp__226->field4)));
  goto llvm_cbe_tmp__330;

llvm_cbe_tmp__330:
  llvm_cbe_tmp__294 = *((&llvm_cbe_tmp__226->field9));
  llvm_cbe_tmp__295 = *((&llvm_cbe_tmp__226->field43));
  *(&llvm_cbe_cppVar_1029) = ((((signed long long )(((signed long long )llvm_cbe_tmp__294) >> ((signed long long )0ull)))) & llvm_cbe_tmp__295);
  llvm_cbe_tmp__296 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1030), (&llvm_cbe_cppVar_1000));
  llvm_cbe_tmp__297 = *(&llvm_cbe_cppVar_1029);
  _ZN8type_memIbLj128EE2wrEll((&llvm_cbe_cppVar_1030), llvm_cbe_tmp__297, 1ull);
  llvm_cbe_tmp__298 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_994), (&llvm_cbe_cppVar_1030));
  goto llvm_cbe_tmp__331;

llvm_cbe_tmp__316:
  llvm_cbe_tmp__299 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_994), (&llvm_cbe_cppVar_1000));
  goto llvm_cbe_tmp__331;

llvm_cbe_tmp__331:
  llvm_cbe_tmp__300 = _ZN8type_memIbLj128EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_994));
  goto llvm_cbe_tmp__332;

llvm_cbe_tmp__312:
  llvm_cbe_tmp__301 = *((&llvm_cbe_tmp__226->field29));
  *(&llvm_cbe_cppVar_1033) = (((unsigned char )(bool )(llvm_cbe_tmp__301 == 1ull)));
  llvm_cbe_tmp__302 = *(&llvm_cbe_cppVar_1033);
  if ((((((bool )llvm_cbe_tmp__302&1u))&1))) {
    goto llvm_cbe_tmp__333;
  } else {
    goto llvm_cbe_tmp__334;
  }

llvm_cbe_tmp__333:
  llvm_cbe_tmp__303 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1031), ((&llvm_cbe_tmp__226->field4)));
  goto llvm_cbe_tmp__335;

llvm_cbe_tmp__334:
  llvm_cbe_tmp__304 = *((&llvm_cbe_tmp__226->field29));
  *(&llvm_cbe_cppVar_1036) = (((unsigned char )(bool )(llvm_cbe_tmp__304 == 2ull)));
  llvm_cbe_tmp__305 = *(&llvm_cbe_cppVar_1036);
  llvm_cbe_tmp__306 = ((((bool )llvm_cbe_tmp__305&1u))&1);
  llvm_cbe_tmp__307 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1034), ((&llvm_cbe_tmp__226->field4)));
  llvm_cbe_tmp__308 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1031), (&llvm_cbe_cppVar_1034));
  goto llvm_cbe_tmp__335;

llvm_cbe_tmp__335:
  llvm_cbe_tmp__309 = _ZN8type_memIbLj128EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1031));
  goto llvm_cbe_tmp__332;

llvm_cbe_tmp__332:
  *(&llvm_cbe_tmp__224) = ((1) & 1);
  *(&llvm_cbe_tmp__225) = 1u;
  llvm_cbe_tmp__310 = ((*(&llvm_cbe_tmp__224))&1);
  if (llvm_cbe_tmp__310) {
    goto llvm_cbe_tmp__336;
  } else {
    goto llvm_cbe_tmp__337;
  }

llvm_cbe_tmp__337:
  _ZN8type_memIbLj128EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__336;

llvm_cbe_tmp__336:
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1031));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1034));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_994));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1030));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1000));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1028));
  return StructReturn;
}


void _ZN8type_memIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__338;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__339;

  *(&llvm_cbe_tmp__338) = llvm_cbe_this;
  llvm_cbe_tmp__339 = *(&llvm_cbe_tmp__338);
  _ZN8type_memIbLj128EEC2Ev(llvm_cbe_tmp__339);
  return;
}


unsigned long long _ZN8type_memIhLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__340;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__341;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__342;
  unsigned long long llvm_cbe_tmp__343;
  unsigned char *llvm_cbe_tmp__344;
  unsigned char llvm_cbe_tmp__345;

  *(&llvm_cbe_tmp__340) = llvm_cbe_this;
  *(&llvm_cbe_tmp__341) = llvm_cbe_addr;
  llvm_cbe_tmp__342 = *(&llvm_cbe_tmp__340);
  llvm_cbe_tmp__343 = *(&llvm_cbe_tmp__341);
  llvm_cbe_tmp__344 = *((&llvm_cbe_tmp__342->field0));
  llvm_cbe_tmp__345 = *((&llvm_cbe_tmp__344[((signed long long )llvm_cbe_tmp__343)]));
  return (((unsigned long long )(unsigned char )llvm_cbe_tmp__345));
}


struct l_class_OC_SysCArray1D *_ZN8type_memIbLj128EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__346;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__347;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__348;
  unsigned char *llvm_cbe_tmp__349;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__350;
  unsigned char *llvm_cbe_tmp__351;

  *(&llvm_cbe_tmp__346) = llvm_cbe_this;
  *(&llvm_cbe_tmp__347) = llvm_cbe_r;
  llvm_cbe_tmp__348 = *(&llvm_cbe_tmp__346);
  llvm_cbe_tmp__349 = *((&llvm_cbe_tmp__348->field0));
  llvm_cbe_tmp__350 = *(&llvm_cbe_tmp__347);
  llvm_cbe_tmp__351 = *((&llvm_cbe_tmp__350->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__349, llvm_cbe_tmp__351);
  return llvm_cbe_tmp__348;
}


void _ZN8type_memIbLj128EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__352;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__353;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__354;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__355;
  unsigned long long llvm_cbe_tmp__356;
  unsigned long long llvm_cbe_tmp__357;
  unsigned char *llvm_cbe_tmp__358;

  *(&llvm_cbe_tmp__352) = llvm_cbe_this;
  *(&llvm_cbe_tmp__353) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__354) = llvm_cbe_data;
  llvm_cbe_tmp__355 = *(&llvm_cbe_tmp__352);
  llvm_cbe_tmp__356 = *(&llvm_cbe_tmp__354);
  llvm_cbe_tmp__357 = *(&llvm_cbe_tmp__353);
  llvm_cbe_tmp__358 = *((&llvm_cbe_tmp__355->field0));
  *((&llvm_cbe_tmp__358[((signed long long )llvm_cbe_tmp__357)])) = (((unsigned char )(bool )(llvm_cbe_tmp__356 != 0ull)));
  return;
}


void _ZN8type_memIbLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__359;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__360;

  *(&llvm_cbe_tmp__359) = llvm_cbe_this;
  llvm_cbe_tmp__360 = *(&llvm_cbe_tmp__359);
  _ZN8type_memIbLj128EED2Ev(llvm_cbe_tmp__360);
  return;
}


unsigned long long _ZN11model_train18cppUpdateFun_indexElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__361;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__362;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__363;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__364;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__365;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__366;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__367;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__368;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__369;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__370;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__371;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__372;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_491;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_492;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_494;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_495;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_497;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_498;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_500;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_501;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_502;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_504;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_505;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_506;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_507;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_508;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_510;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_511;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_503;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_499;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_496;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_493;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_490;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_509;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__373;
  unsigned long long llvm_cbe_tmp__374;
  unsigned char llvm_cbe_tmp__375;
  unsigned long long llvm_cbe_tmp__376;
  unsigned long long llvm_cbe_tmp__377;
  unsigned char llvm_cbe_tmp__378;
  unsigned long long llvm_cbe_tmp__379;
  unsigned long long llvm_cbe_tmp__380;
  unsigned char llvm_cbe_tmp__381;
  unsigned long long llvm_cbe_tmp__382;
  unsigned long long llvm_cbe_tmp__383;
  unsigned long long llvm_cbe_tmp__384;
  unsigned long long llvm_cbe_tmp__385;
  unsigned char llvm_cbe_tmp__386;
  unsigned char llvm_cbe_tmp__387;
  bool llvm_cbe_tmp__388;
  bool llvm_cbe_tmp__389;
  bool llvm_cbe_tmp__389__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__390;
  unsigned long long llvm_cbe_tmp__391;
  unsigned long long llvm_cbe_tmp__392;
  unsigned long long llvm_cbe_tmp__393;
  unsigned long long llvm_cbe_tmp__394;
  unsigned long long llvm_cbe_tmp__395;
  unsigned long long llvm_cbe_tmp__396;
  unsigned long long llvm_cbe_tmp__397;
  unsigned char llvm_cbe_tmp__398;
  unsigned char llvm_cbe_tmp__399;
  bool llvm_cbe_tmp__400;
  bool llvm_cbe_tmp__401;
  bool llvm_cbe_tmp__401__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__402;
  unsigned long long llvm_cbe_tmp__403;
  unsigned long long llvm_cbe_tmp__404;
  unsigned long long llvm_cbe_tmp__405;
  unsigned long long llvm_cbe_tmp__406;
  unsigned long long llvm_cbe_tmp__407;
  unsigned long long llvm_cbe_tmp__408;
  unsigned long long llvm_cbe_tmp__409;
  unsigned long long llvm_cbe_tmp__410;
  unsigned long long llvm_cbe_tmp__411;
  unsigned long long llvm_cbe_tmp__412;
  unsigned long long llvm_cbe_tmp__413;

  *(&llvm_cbe_tmp__361) = llvm_cbe_this;
  *(&llvm_cbe_tmp__362) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__363) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__364) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__365) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__366) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__367) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__368) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__369) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__370) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__371) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__372) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__373 = *(&llvm_cbe_tmp__361);
  llvm_cbe_tmp__374 = *((&llvm_cbe_tmp__373->field29));
  *(&llvm_cbe_cppVar_492) = (((unsigned char )(bool )(llvm_cbe_tmp__374 == 0ull)));
  llvm_cbe_tmp__375 = *(&llvm_cbe_cppVar_492);
  if ((((((bool )llvm_cbe_tmp__375&1u))&1))) {
    goto llvm_cbe_tmp__414;
  } else {
    goto llvm_cbe_tmp__415;
  }

llvm_cbe_tmp__414:
  llvm_cbe_tmp__376 = *((&llvm_cbe_tmp__373->field5));
  *(&llvm_cbe_cppVar_490) = llvm_cbe_tmp__376;
  goto llvm_cbe_tmp__416;

llvm_cbe_tmp__415:
  llvm_cbe_tmp__377 = *((&llvm_cbe_tmp__373->field29));
  *(&llvm_cbe_cppVar_495) = (((unsigned char )(bool )(llvm_cbe_tmp__377 == 1ull)));
  llvm_cbe_tmp__378 = *(&llvm_cbe_cppVar_495);
  if ((((((bool )llvm_cbe_tmp__378&1u))&1))) {
    goto llvm_cbe_tmp__417;
  } else {
    goto llvm_cbe_tmp__418;
  }

llvm_cbe_tmp__417:
  llvm_cbe_tmp__379 = *((&llvm_cbe_tmp__373->field5));
  *(&llvm_cbe_cppVar_493) = llvm_cbe_tmp__379;
  goto llvm_cbe_tmp__419;

llvm_cbe_tmp__418:
  llvm_cbe_tmp__380 = *((&llvm_cbe_tmp__373->field29));
  *(&llvm_cbe_cppVar_498) = (((unsigned char )(bool )(llvm_cbe_tmp__380 == 2ull)));
  llvm_cbe_tmp__381 = *(&llvm_cbe_cppVar_498);
  if ((((((bool )llvm_cbe_tmp__381&1u))&1))) {
    goto llvm_cbe_tmp__420;
  } else {
    goto llvm_cbe_tmp__421;
  }

llvm_cbe_tmp__420:
  llvm_cbe_tmp__382 = *((&llvm_cbe_tmp__373->field25));
  llvm_cbe_tmp__383 = *((&llvm_cbe_tmp__373->field9));
  *(&llvm_cbe_cppVar_500) = (((unsigned char )(bool )(llvm_cbe_tmp__382 == llvm_cbe_tmp__383)));
  llvm_cbe_tmp__384 = *((&llvm_cbe_tmp__373->field30));
  llvm_cbe_tmp__385 = *((&llvm_cbe_tmp__373->field14));
  *(&llvm_cbe_cppVar_501) = (((unsigned char )(bool )(llvm_cbe_tmp__384 == llvm_cbe_tmp__385)));
  llvm_cbe_tmp__386 = *(&llvm_cbe_cppVar_500);
  if ((((((bool )llvm_cbe_tmp__386&1u))&1))) {
    goto llvm_cbe_tmp__422;
  } else {
    llvm_cbe_tmp__389__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__423;
  }

llvm_cbe_tmp__422:
  llvm_cbe_tmp__387 = *(&llvm_cbe_cppVar_501);
  llvm_cbe_tmp__388 = ((((bool )llvm_cbe_tmp__387&1u))&1);
  llvm_cbe_tmp__389__PHI_TEMPORARY = llvm_cbe_tmp__388;   /* for PHI node */
  goto llvm_cbe_tmp__423;

llvm_cbe_tmp__423:
  llvm_cbe_tmp__389 = ((llvm_cbe_tmp__389__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_502) = (((unsigned char )(bool )llvm_cbe_tmp__389));
  llvm_cbe_tmp__390 = *(&llvm_cbe_cppVar_502);
  if ((((((bool )llvm_cbe_tmp__390&1u))&1))) {
    goto llvm_cbe_tmp__424;
  } else {
    goto llvm_cbe_tmp__425;
  }

llvm_cbe_tmp__424:
  llvm_cbe_tmp__391 = *((&llvm_cbe_tmp__373->field13));
  *(&llvm_cbe_cppVar_505) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__391) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__392 = *(&llvm_cbe_cppVar_505);
  llvm_cbe_tmp__393 = *((&llvm_cbe_tmp__373->field39));
  *(&llvm_cbe_cppVar_505) = (llvm_cbe_tmp__392 & llvm_cbe_tmp__393);
  llvm_cbe_tmp__394 = *((&llvm_cbe_tmp__373->field5));
  llvm_cbe_tmp__395 = *(&llvm_cbe_cppVar_505);
  *(&llvm_cbe_cppVar_506) = (((unsigned char )(bool )(llvm_cbe_tmp__394 == llvm_cbe_tmp__395)));
  llvm_cbe_tmp__396 = *((&llvm_cbe_tmp__373->field8));
  llvm_cbe_tmp__397 = *((&llvm_cbe_tmp__373->field10));
  *(&llvm_cbe_cppVar_507) = (((unsigned char )(bool )(llvm_cbe_tmp__396 != llvm_cbe_tmp__397)));
  llvm_cbe_tmp__398 = *(&llvm_cbe_cppVar_506);
  if ((((((bool )llvm_cbe_tmp__398&1u))&1))) {
    goto llvm_cbe_tmp__426;
  } else {
    llvm_cbe_tmp__401__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__427;
  }

llvm_cbe_tmp__426:
  llvm_cbe_tmp__399 = *(&llvm_cbe_cppVar_507);
  llvm_cbe_tmp__400 = ((((bool )llvm_cbe_tmp__399&1u))&1);
  llvm_cbe_tmp__401__PHI_TEMPORARY = llvm_cbe_tmp__400;   /* for PHI node */
  goto llvm_cbe_tmp__427;

llvm_cbe_tmp__427:
  llvm_cbe_tmp__401 = ((llvm_cbe_tmp__401__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_508) = (((unsigned char )(bool )llvm_cbe_tmp__401));
  llvm_cbe_tmp__402 = *(&llvm_cbe_cppVar_508);
  if ((((((bool )llvm_cbe_tmp__402&1u))&1))) {
    goto llvm_cbe_tmp__428;
  } else {
    goto llvm_cbe_tmp__429;
  }

llvm_cbe_tmp__428:
  *(&llvm_cbe_cppVar_503) = 0ull;
  goto llvm_cbe_tmp__430;

llvm_cbe_tmp__429:
  llvm_cbe_tmp__403 = *((&llvm_cbe_tmp__373->field5));
  *(&llvm_cbe_cppVar_511) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__403) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__404 = *(&llvm_cbe_cppVar_511);
  llvm_cbe_tmp__405 = *((&llvm_cbe_tmp__373->field39));
  *(&llvm_cbe_cppVar_511) = (llvm_cbe_tmp__404 & llvm_cbe_tmp__405);
  llvm_cbe_tmp__406 = *(&llvm_cbe_cppVar_511);
  *(&llvm_cbe_cppVar_503) = llvm_cbe_tmp__406;
  goto llvm_cbe_tmp__430;

llvm_cbe_tmp__430:
  llvm_cbe_tmp__407 = *(&llvm_cbe_cppVar_503);
  *(&llvm_cbe_cppVar_499) = llvm_cbe_tmp__407;
  goto llvm_cbe_tmp__431;

llvm_cbe_tmp__425:
  llvm_cbe_tmp__408 = *((&llvm_cbe_tmp__373->field5));
  *(&llvm_cbe_cppVar_499) = llvm_cbe_tmp__408;
  goto llvm_cbe_tmp__431;

llvm_cbe_tmp__431:
  llvm_cbe_tmp__409 = *(&llvm_cbe_cppVar_499);
  *(&llvm_cbe_cppVar_496) = llvm_cbe_tmp__409;
  goto llvm_cbe_tmp__432;

llvm_cbe_tmp__421:
  llvm_cbe_tmp__410 = *((&llvm_cbe_tmp__373->field5));
  *(&llvm_cbe_cppVar_496) = llvm_cbe_tmp__410;
  goto llvm_cbe_tmp__432;

llvm_cbe_tmp__432:
  llvm_cbe_tmp__411 = *(&llvm_cbe_cppVar_496);
  *(&llvm_cbe_cppVar_493) = llvm_cbe_tmp__411;
  goto llvm_cbe_tmp__419;

llvm_cbe_tmp__419:
  llvm_cbe_tmp__412 = *(&llvm_cbe_cppVar_493);
  *(&llvm_cbe_cppVar_490) = llvm_cbe_tmp__412;
  goto llvm_cbe_tmp__416;

llvm_cbe_tmp__416:
  llvm_cbe_tmp__413 = *(&llvm_cbe_cppVar_490);
  return llvm_cbe_tmp__413;
}


unsigned long long _ZN11model_train19cppUpdateFun_jstateElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__433;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__434;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__435;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__436;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__437;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__438;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__439;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__440;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__441;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__442;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__443;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__444;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_43;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_35;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_26;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_14;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_52;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_53;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_51;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_11;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_7;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_8;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_9;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_10;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_12;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_13;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_15;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_16;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_17;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_18;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_20;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_22;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_23;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_24;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_25;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_21;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_19;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_27;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_28;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_29;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_30;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_32;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_33;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_34;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_31;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_36;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_37;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_38;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_39;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_41;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_42;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_40;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_44;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_45;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_46;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_47;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_49;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_50;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_48;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__445;
  unsigned long long llvm_cbe_tmp__446;
  unsigned char llvm_cbe_tmp__447;
  unsigned long long llvm_cbe_tmp__448;
  unsigned char llvm_cbe_tmp__449;
  unsigned long long llvm_cbe_tmp__450;
  unsigned long long llvm_cbe_tmp__451;
  unsigned char llvm_cbe_tmp__452;
  unsigned char llvm_cbe_tmp__453;
  bool llvm_cbe_tmp__454;
  bool llvm_cbe_tmp__455;
  bool llvm_cbe_tmp__455__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__456;
  unsigned long long llvm_cbe_tmp__457;
  unsigned long long llvm_cbe_tmp__458;
  unsigned char llvm_cbe_tmp__459;
  unsigned long long llvm_cbe_tmp__460;
  unsigned char llvm_cbe_tmp__461;
  unsigned long long llvm_cbe_tmp__462;
  unsigned long long llvm_cbe_tmp__463;
  unsigned long long llvm_cbe_tmp__464;
  unsigned long long llvm_cbe_tmp__465;
  unsigned long long llvm_cbe_tmp__466;
  unsigned long long llvm_cbe_tmp__467;
  unsigned long long llvm_cbe_tmp__468;
  unsigned long long llvm_cbe_tmp__469;
  unsigned char llvm_cbe_tmp__470;
  unsigned char llvm_cbe_tmp__471;
  bool llvm_cbe_tmp__472;
  bool llvm_cbe_tmp__473;
  bool llvm_cbe_tmp__473__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__474;
  unsigned long long llvm_cbe_tmp__475;
  unsigned char llvm_cbe_tmp__476;
  unsigned long long llvm_cbe_tmp__477;
  unsigned long long llvm_cbe_tmp__478;
  unsigned long long llvm_cbe_tmp__479;
  unsigned long long llvm_cbe_tmp__480;
  unsigned long long llvm_cbe_tmp__481;
  unsigned long long llvm_cbe_tmp__482;
  unsigned long long llvm_cbe_tmp__483;
  unsigned char llvm_cbe_tmp__484;
  unsigned char llvm_cbe_tmp__485;
  bool llvm_cbe_tmp__486;
  bool llvm_cbe_tmp__487;
  bool llvm_cbe_tmp__487__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__488;
  unsigned long long llvm_cbe_tmp__489;
  unsigned char llvm_cbe_tmp__490;
  unsigned long long llvm_cbe_tmp__491;
  unsigned long long llvm_cbe_tmp__492;
  unsigned long long llvm_cbe_tmp__493;
  unsigned long long llvm_cbe_tmp__494;
  unsigned long long llvm_cbe_tmp__495;
  unsigned long long llvm_cbe_tmp__496;
  unsigned long long llvm_cbe_tmp__497;
  unsigned char llvm_cbe_tmp__498;
  unsigned char llvm_cbe_tmp__499;
  bool llvm_cbe_tmp__500;
  bool llvm_cbe_tmp__501;
  bool llvm_cbe_tmp__501__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__502;
  unsigned long long llvm_cbe_tmp__503;
  unsigned char llvm_cbe_tmp__504;
  unsigned long long llvm_cbe_tmp__505;
  unsigned long long llvm_cbe_tmp__506;
  unsigned long long llvm_cbe_tmp__507;
  unsigned long long llvm_cbe_tmp__508;
  unsigned long long llvm_cbe_tmp__509;
  unsigned long long llvm_cbe_tmp__510;
  unsigned long long llvm_cbe_tmp__511;
  unsigned long long llvm_cbe_tmp__512;
  unsigned long long llvm_cbe_tmp__513;
  unsigned long long llvm_cbe_tmp__514;
  unsigned long long llvm_cbe_tmp__515;
  unsigned long long llvm_cbe_tmp__516;
  unsigned long long llvm_cbe_tmp__517;

  *(&llvm_cbe_tmp__433) = llvm_cbe_this;
  *(&llvm_cbe_tmp__434) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__435) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__436) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__437) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__438) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__439) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__440) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__441) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__442) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__443) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__444) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__445 = *(&llvm_cbe_tmp__433);
  llvm_cbe_tmp__446 = *((&llvm_cbe_tmp__445->field29));
  *(&llvm_cbe_cppVar_9) = (((unsigned char )(bool )(llvm_cbe_tmp__446 == 0ull)));
  llvm_cbe_tmp__447 = *(&llvm_cbe_cppVar_9);
  if ((((((bool )llvm_cbe_tmp__447&1u))&1))) {
    goto llvm_cbe_tmp__518;
  } else {
    goto llvm_cbe_tmp__519;
  }

llvm_cbe_tmp__518:
  *(&llvm_cbe_cppVar_7) = 0ull;
  goto llvm_cbe_tmp__520;

llvm_cbe_tmp__519:
  llvm_cbe_tmp__448 = *((&llvm_cbe_tmp__445->field29));
  *(&llvm_cbe_cppVar_13) = (((unsigned char )(bool )(llvm_cbe_tmp__448 == 1ull)));
  llvm_cbe_tmp__449 = *(&llvm_cbe_cppVar_13);
  llvm_cbe_tmp__450 = *((&llvm_cbe_tmp__445->field29));
  if ((((((bool )llvm_cbe_tmp__449&1u))&1))) {
    goto llvm_cbe_tmp__521;
  } else {
    goto llvm_cbe_tmp__522;
  }

llvm_cbe_tmp__521:
  *(&llvm_cbe_cppVar_15) = (((unsigned char )(bool )(llvm_cbe_tmp__450 == 1ull)));
  llvm_cbe_tmp__451 = *((&llvm_cbe_tmp__445->field15));
  *(&llvm_cbe_cppVar_17) = (((unsigned char )(bool )(llvm_cbe_tmp__451 == 0ull)));
  llvm_cbe_tmp__452 = *(&llvm_cbe_cppVar_15);
  if ((((((bool )llvm_cbe_tmp__452&1u))&1))) {
    goto llvm_cbe_tmp__523;
  } else {
    llvm_cbe_tmp__455__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__524;
  }

llvm_cbe_tmp__523:
  llvm_cbe_tmp__453 = *(&llvm_cbe_cppVar_17);
  llvm_cbe_tmp__454 = ((((bool )llvm_cbe_tmp__453&1u))&1);
  llvm_cbe_tmp__455__PHI_TEMPORARY = llvm_cbe_tmp__454;   /* for PHI node */
  goto llvm_cbe_tmp__524;

llvm_cbe_tmp__524:
  llvm_cbe_tmp__455 = ((llvm_cbe_tmp__455__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_18) = (((unsigned char )(bool )llvm_cbe_tmp__455));
  llvm_cbe_tmp__456 = *(&llvm_cbe_cppVar_18);
  if ((((((bool )llvm_cbe_tmp__456&1u))&1))) {
    goto llvm_cbe_tmp__525;
  } else {
    goto llvm_cbe_tmp__526;
  }

llvm_cbe_tmp__525:
  llvm_cbe_tmp__457 = *((&llvm_cbe_tmp__445->field25));
  llvm_cbe_tmp__458 = *((&llvm_cbe_tmp__445->field9));
  *(&llvm_cbe_cppVar_20) = (((unsigned char )(bool )(llvm_cbe_tmp__457 == llvm_cbe_tmp__458)));
  llvm_cbe_tmp__459 = *(&llvm_cbe_cppVar_20);
  llvm_cbe_tmp__460 = *((&llvm_cbe_tmp__445->field7));
  if ((((((bool )llvm_cbe_tmp__459&1u))&1))) {
    goto llvm_cbe_tmp__527;
  } else {
    goto llvm_cbe_tmp__528;
  }

llvm_cbe_tmp__527:
  *(&llvm_cbe_cppVar_23) = (((unsigned char )(bool )(llvm_cbe_tmp__460 == 4ull)));
  llvm_cbe_tmp__461 = *(&llvm_cbe_cppVar_23);
  if ((((((bool )llvm_cbe_tmp__461&1u))&1))) {
    goto llvm_cbe_tmp__529;
  } else {
    goto llvm_cbe_tmp__530;
  }

llvm_cbe_tmp__529:
  *(&llvm_cbe_cppVar_21) = 0ull;
  goto llvm_cbe_tmp__531;

llvm_cbe_tmp__530:
  llvm_cbe_tmp__462 = *((&llvm_cbe_tmp__445->field7));
  *(&llvm_cbe_cppVar_25) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__462) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__463 = *(&llvm_cbe_cppVar_25);
  llvm_cbe_tmp__464 = *((&llvm_cbe_tmp__445->field39));
  *(&llvm_cbe_cppVar_25) = (llvm_cbe_tmp__463 & llvm_cbe_tmp__464);
  llvm_cbe_tmp__465 = *(&llvm_cbe_cppVar_25);
  *(&llvm_cbe_cppVar_21) = llvm_cbe_tmp__465;
  goto llvm_cbe_tmp__531;

llvm_cbe_tmp__531:
  llvm_cbe_tmp__466 = *(&llvm_cbe_cppVar_21);
  *(&llvm_cbe_cppVar_19) = llvm_cbe_tmp__466;
  goto llvm_cbe_tmp__532;

llvm_cbe_tmp__528:
  *(&llvm_cbe_cppVar_19) = llvm_cbe_tmp__460;
  goto llvm_cbe_tmp__532;

llvm_cbe_tmp__532:
  llvm_cbe_tmp__467 = *(&llvm_cbe_cppVar_19);
  *(&llvm_cbe_cppVar_14) = llvm_cbe_tmp__467;
  goto llvm_cbe_tmp__533;

llvm_cbe_tmp__526:
  llvm_cbe_tmp__468 = *((&llvm_cbe_tmp__445->field29));
  *(&llvm_cbe_cppVar_27) = (((unsigned char )(bool )(llvm_cbe_tmp__468 == 1ull)));
  llvm_cbe_tmp__469 = *((&llvm_cbe_tmp__445->field15));
  *(&llvm_cbe_cppVar_29) = (((unsigned char )(bool )(llvm_cbe_tmp__469 == 1ull)));
  llvm_cbe_tmp__470 = *(&llvm_cbe_cppVar_27);
  if ((((((bool )llvm_cbe_tmp__470&1u))&1))) {
    goto llvm_cbe_tmp__534;
  } else {
    llvm_cbe_tmp__473__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__535;
  }

llvm_cbe_tmp__534:
  llvm_cbe_tmp__471 = *(&llvm_cbe_cppVar_29);
  llvm_cbe_tmp__472 = ((((bool )llvm_cbe_tmp__471&1u))&1);
  llvm_cbe_tmp__473__PHI_TEMPORARY = llvm_cbe_tmp__472;   /* for PHI node */
  goto llvm_cbe_tmp__535;

llvm_cbe_tmp__535:
  llvm_cbe_tmp__473 = ((llvm_cbe_tmp__473__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_30) = (((unsigned char )(bool )llvm_cbe_tmp__473));
  llvm_cbe_tmp__474 = *(&llvm_cbe_cppVar_30);
  if ((((((bool )llvm_cbe_tmp__474&1u))&1))) {
    goto llvm_cbe_tmp__536;
  } else {
    goto llvm_cbe_tmp__537;
  }

llvm_cbe_tmp__536:
  llvm_cbe_tmp__475 = *((&llvm_cbe_tmp__445->field7));
  *(&llvm_cbe_cppVar_32) = (((unsigned char )(bool )(llvm_cbe_tmp__475 == 4ull)));
  llvm_cbe_tmp__476 = *(&llvm_cbe_cppVar_32);
  if ((((((bool )llvm_cbe_tmp__476&1u))&1))) {
    goto llvm_cbe_tmp__538;
  } else {
    goto llvm_cbe_tmp__539;
  }

llvm_cbe_tmp__538:
  *(&llvm_cbe_cppVar_31) = 0ull;
  goto llvm_cbe_tmp__540;

llvm_cbe_tmp__539:
  llvm_cbe_tmp__477 = *((&llvm_cbe_tmp__445->field7));
  *(&llvm_cbe_cppVar_34) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__477) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__478 = *(&llvm_cbe_cppVar_34);
  llvm_cbe_tmp__479 = *((&llvm_cbe_tmp__445->field39));
  *(&llvm_cbe_cppVar_34) = (llvm_cbe_tmp__478 & llvm_cbe_tmp__479);
  llvm_cbe_tmp__480 = *(&llvm_cbe_cppVar_34);
  *(&llvm_cbe_cppVar_31) = llvm_cbe_tmp__480;
  goto llvm_cbe_tmp__540;

llvm_cbe_tmp__540:
  llvm_cbe_tmp__481 = *(&llvm_cbe_cppVar_31);
  *(&llvm_cbe_cppVar_26) = llvm_cbe_tmp__481;
  goto llvm_cbe_tmp__541;

llvm_cbe_tmp__537:
  llvm_cbe_tmp__482 = *((&llvm_cbe_tmp__445->field29));
  *(&llvm_cbe_cppVar_36) = (((unsigned char )(bool )(llvm_cbe_tmp__482 == 1ull)));
  llvm_cbe_tmp__483 = *((&llvm_cbe_tmp__445->field15));
  *(&llvm_cbe_cppVar_38) = (((unsigned char )(bool )(llvm_cbe_tmp__483 == 2ull)));
  llvm_cbe_tmp__484 = *(&llvm_cbe_cppVar_36);
  if ((((((bool )llvm_cbe_tmp__484&1u))&1))) {
    goto llvm_cbe_tmp__542;
  } else {
    llvm_cbe_tmp__487__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__543;
  }

llvm_cbe_tmp__542:
  llvm_cbe_tmp__485 = *(&llvm_cbe_cppVar_38);
  llvm_cbe_tmp__486 = ((((bool )llvm_cbe_tmp__485&1u))&1);
  llvm_cbe_tmp__487__PHI_TEMPORARY = llvm_cbe_tmp__486;   /* for PHI node */
  goto llvm_cbe_tmp__543;

llvm_cbe_tmp__543:
  llvm_cbe_tmp__487 = ((llvm_cbe_tmp__487__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_39) = (((unsigned char )(bool )llvm_cbe_tmp__487));
  llvm_cbe_tmp__488 = *(&llvm_cbe_cppVar_39);
  if ((((((bool )llvm_cbe_tmp__488&1u))&1))) {
    goto llvm_cbe_tmp__544;
  } else {
    goto llvm_cbe_tmp__545;
  }

llvm_cbe_tmp__544:
  llvm_cbe_tmp__489 = *((&llvm_cbe_tmp__445->field7));
  *(&llvm_cbe_cppVar_41) = (((unsigned char )(bool )(llvm_cbe_tmp__489 == 4ull)));
  llvm_cbe_tmp__490 = *(&llvm_cbe_cppVar_41);
  if ((((((bool )llvm_cbe_tmp__490&1u))&1))) {
    goto llvm_cbe_tmp__546;
  } else {
    goto llvm_cbe_tmp__547;
  }

llvm_cbe_tmp__546:
  *(&llvm_cbe_cppVar_40) = 0ull;
  goto llvm_cbe_tmp__548;

llvm_cbe_tmp__547:
  llvm_cbe_tmp__491 = *((&llvm_cbe_tmp__445->field7));
  *(&llvm_cbe_cppVar_42) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__491) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__492 = *(&llvm_cbe_cppVar_42);
  llvm_cbe_tmp__493 = *((&llvm_cbe_tmp__445->field39));
  *(&llvm_cbe_cppVar_42) = (llvm_cbe_tmp__492 & llvm_cbe_tmp__493);
  llvm_cbe_tmp__494 = *(&llvm_cbe_cppVar_42);
  *(&llvm_cbe_cppVar_40) = llvm_cbe_tmp__494;
  goto llvm_cbe_tmp__548;

llvm_cbe_tmp__548:
  llvm_cbe_tmp__495 = *(&llvm_cbe_cppVar_40);
  *(&llvm_cbe_cppVar_35) = llvm_cbe_tmp__495;
  goto llvm_cbe_tmp__549;

llvm_cbe_tmp__545:
  llvm_cbe_tmp__496 = *((&llvm_cbe_tmp__445->field29));
  *(&llvm_cbe_cppVar_44) = (((unsigned char )(bool )(llvm_cbe_tmp__496 == 1ull)));
  llvm_cbe_tmp__497 = *((&llvm_cbe_tmp__445->field15));
  *(&llvm_cbe_cppVar_46) = (((unsigned char )(bool )(llvm_cbe_tmp__497 == 3ull)));
  llvm_cbe_tmp__498 = *(&llvm_cbe_cppVar_44);
  if ((((((bool )llvm_cbe_tmp__498&1u))&1))) {
    goto llvm_cbe_tmp__550;
  } else {
    llvm_cbe_tmp__501__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__551;
  }

llvm_cbe_tmp__550:
  llvm_cbe_tmp__499 = *(&llvm_cbe_cppVar_46);
  llvm_cbe_tmp__500 = ((((bool )llvm_cbe_tmp__499&1u))&1);
  llvm_cbe_tmp__501__PHI_TEMPORARY = llvm_cbe_tmp__500;   /* for PHI node */
  goto llvm_cbe_tmp__551;

llvm_cbe_tmp__551:
  llvm_cbe_tmp__501 = ((llvm_cbe_tmp__501__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_47) = (((unsigned char )(bool )llvm_cbe_tmp__501));
  llvm_cbe_tmp__502 = *(&llvm_cbe_cppVar_47);
  llvm_cbe_tmp__503 = *((&llvm_cbe_tmp__445->field7));
  if ((((((bool )llvm_cbe_tmp__502&1u))&1))) {
    goto llvm_cbe_tmp__552;
  } else {
    goto llvm_cbe_tmp__553;
  }

llvm_cbe_tmp__552:
  *(&llvm_cbe_cppVar_49) = (((unsigned char )(bool )(llvm_cbe_tmp__503 == 4ull)));
  llvm_cbe_tmp__504 = *(&llvm_cbe_cppVar_49);
  if ((((((bool )llvm_cbe_tmp__504&1u))&1))) {
    goto llvm_cbe_tmp__554;
  } else {
    goto llvm_cbe_tmp__555;
  }

llvm_cbe_tmp__554:
  *(&llvm_cbe_cppVar_48) = 0ull;
  goto llvm_cbe_tmp__556;

llvm_cbe_tmp__555:
  llvm_cbe_tmp__505 = *((&llvm_cbe_tmp__445->field7));
  *(&llvm_cbe_cppVar_50) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__505) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__506 = *(&llvm_cbe_cppVar_50);
  llvm_cbe_tmp__507 = *((&llvm_cbe_tmp__445->field39));
  *(&llvm_cbe_cppVar_50) = (llvm_cbe_tmp__506 & llvm_cbe_tmp__507);
  llvm_cbe_tmp__508 = *(&llvm_cbe_cppVar_50);
  *(&llvm_cbe_cppVar_48) = llvm_cbe_tmp__508;
  goto llvm_cbe_tmp__556;

llvm_cbe_tmp__556:
  llvm_cbe_tmp__509 = *(&llvm_cbe_cppVar_48);
  *(&llvm_cbe_cppVar_43) = llvm_cbe_tmp__509;
  goto llvm_cbe_tmp__557;

llvm_cbe_tmp__553:
  *(&llvm_cbe_cppVar_43) = llvm_cbe_tmp__503;
  goto llvm_cbe_tmp__557;

llvm_cbe_tmp__557:
  llvm_cbe_tmp__510 = *(&llvm_cbe_cppVar_43);
  *(&llvm_cbe_cppVar_35) = llvm_cbe_tmp__510;
  goto llvm_cbe_tmp__549;

llvm_cbe_tmp__549:
  llvm_cbe_tmp__511 = *(&llvm_cbe_cppVar_35);
  *(&llvm_cbe_cppVar_26) = llvm_cbe_tmp__511;
  goto llvm_cbe_tmp__541;

llvm_cbe_tmp__541:
  llvm_cbe_tmp__512 = *(&llvm_cbe_cppVar_26);
  *(&llvm_cbe_cppVar_14) = llvm_cbe_tmp__512;
  goto llvm_cbe_tmp__533;

llvm_cbe_tmp__533:
  llvm_cbe_tmp__513 = *(&llvm_cbe_cppVar_14);
  *(&llvm_cbe_cppVar_11) = llvm_cbe_tmp__513;
  goto llvm_cbe_tmp__558;

llvm_cbe_tmp__522:
  *(&llvm_cbe_cppVar_53) = (((unsigned char )(bool )(llvm_cbe_tmp__450 == 2ull)));
  llvm_cbe_tmp__514 = *((&llvm_cbe_tmp__445->field7));
  *(&llvm_cbe_cppVar_51) = llvm_cbe_tmp__514;
  llvm_cbe_tmp__515 = *(&llvm_cbe_cppVar_51);
  *(&llvm_cbe_cppVar_11) = llvm_cbe_tmp__515;
  goto llvm_cbe_tmp__558;

llvm_cbe_tmp__558:
  llvm_cbe_tmp__516 = *(&llvm_cbe_cppVar_11);
  *(&llvm_cbe_cppVar_7) = llvm_cbe_tmp__516;
  goto llvm_cbe_tmp__520;

llvm_cbe_tmp__520:
  llvm_cbe_tmp__517 = *(&llvm_cbe_cppVar_7);
  return llvm_cbe_tmp__517;
}


unsigned long long _ZN11model_train23cppUpdateFun_loop_countElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__559;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__560;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__561;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__562;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__563;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__564;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__565;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__566;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__567;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__568;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__569;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__570;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_551;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_552;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_554;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_555;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_557;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_558;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_560;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_561;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_562;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_563;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_564;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_565;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_566;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_567;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_568;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_569;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_570;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_559;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_556;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_553;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_550;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__571;
  unsigned long long llvm_cbe_tmp__572;
  unsigned char llvm_cbe_tmp__573;
  unsigned long long llvm_cbe_tmp__574;
  unsigned long long llvm_cbe_tmp__575;
  unsigned char llvm_cbe_tmp__576;
  unsigned long long llvm_cbe_tmp__577;
  unsigned long long llvm_cbe_tmp__578;
  unsigned char llvm_cbe_tmp__579;
  unsigned long long llvm_cbe_tmp__580;
  unsigned long long llvm_cbe_tmp__581;
  unsigned long long llvm_cbe_tmp__582;
  unsigned long long llvm_cbe_tmp__583;
  unsigned char llvm_cbe_tmp__584;
  unsigned char llvm_cbe_tmp__585;
  bool llvm_cbe_tmp__586;
  bool llvm_cbe_tmp__587;
  bool llvm_cbe_tmp__587__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__588;
  unsigned long long llvm_cbe_tmp__589;
  unsigned long long llvm_cbe_tmp__590;
  unsigned long long llvm_cbe_tmp__591;
  unsigned long long llvm_cbe_tmp__592;
  unsigned char llvm_cbe_tmp__593;
  unsigned char llvm_cbe_tmp__594;
  bool llvm_cbe_tmp__595;
  bool llvm_cbe_tmp__596;
  bool llvm_cbe_tmp__596__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__597;
  unsigned long long llvm_cbe_tmp__598;
  unsigned char llvm_cbe_tmp__599;
  unsigned char llvm_cbe_tmp__600;
  bool llvm_cbe_tmp__601;
  bool llvm_cbe_tmp__602;
  bool llvm_cbe_tmp__602__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__603;
  unsigned long long llvm_cbe_tmp__604;
  unsigned long long llvm_cbe_tmp__605;
  unsigned long long llvm_cbe_tmp__606;
  unsigned long long llvm_cbe_tmp__607;
  unsigned long long llvm_cbe_tmp__608;
  unsigned long long llvm_cbe_tmp__609;
  unsigned long long llvm_cbe_tmp__610;
  unsigned long long llvm_cbe_tmp__611;
  unsigned long long llvm_cbe_tmp__612;

  *(&llvm_cbe_tmp__559) = llvm_cbe_this;
  *(&llvm_cbe_tmp__560) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__561) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__562) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__563) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__564) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__565) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__566) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__567) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__568) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__569) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__570) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__571 = *(&llvm_cbe_tmp__559);
  llvm_cbe_tmp__572 = *((&llvm_cbe_tmp__571->field29));
  *(&llvm_cbe_cppVar_552) = (((unsigned char )(bool )(llvm_cbe_tmp__572 == 0ull)));
  llvm_cbe_tmp__573 = *(&llvm_cbe_cppVar_552);
  if ((((((bool )llvm_cbe_tmp__573&1u))&1))) {
    goto llvm_cbe_tmp__613;
  } else {
    goto llvm_cbe_tmp__614;
  }

llvm_cbe_tmp__613:
  llvm_cbe_tmp__574 = *((&llvm_cbe_tmp__571->field8));
  *(&llvm_cbe_cppVar_550) = llvm_cbe_tmp__574;
  goto llvm_cbe_tmp__615;

llvm_cbe_tmp__614:
  llvm_cbe_tmp__575 = *((&llvm_cbe_tmp__571->field29));
  *(&llvm_cbe_cppVar_555) = (((unsigned char )(bool )(llvm_cbe_tmp__575 == 1ull)));
  llvm_cbe_tmp__576 = *(&llvm_cbe_cppVar_555);
  if ((((((bool )llvm_cbe_tmp__576&1u))&1))) {
    goto llvm_cbe_tmp__616;
  } else {
    goto llvm_cbe_tmp__617;
  }

llvm_cbe_tmp__616:
  llvm_cbe_tmp__577 = *((&llvm_cbe_tmp__571->field8));
  *(&llvm_cbe_cppVar_553) = llvm_cbe_tmp__577;
  goto llvm_cbe_tmp__618;

llvm_cbe_tmp__617:
  llvm_cbe_tmp__578 = *((&llvm_cbe_tmp__571->field29));
  *(&llvm_cbe_cppVar_558) = (((unsigned char )(bool )(llvm_cbe_tmp__578 == 2ull)));
  llvm_cbe_tmp__579 = *(&llvm_cbe_cppVar_558);
  if ((((((bool )llvm_cbe_tmp__579&1u))&1))) {
    goto llvm_cbe_tmp__619;
  } else {
    goto llvm_cbe_tmp__620;
  }

llvm_cbe_tmp__619:
  llvm_cbe_tmp__580 = *((&llvm_cbe_tmp__571->field25));
  llvm_cbe_tmp__581 = *((&llvm_cbe_tmp__571->field9));
  *(&llvm_cbe_cppVar_560) = (((unsigned char )(bool )(llvm_cbe_tmp__580 == llvm_cbe_tmp__581)));
  llvm_cbe_tmp__582 = *((&llvm_cbe_tmp__571->field30));
  llvm_cbe_tmp__583 = *((&llvm_cbe_tmp__571->field14));
  *(&llvm_cbe_cppVar_561) = (((unsigned char )(bool )(llvm_cbe_tmp__582 == llvm_cbe_tmp__583)));
  llvm_cbe_tmp__584 = *(&llvm_cbe_cppVar_560);
  if ((((((bool )llvm_cbe_tmp__584&1u))&1))) {
    goto llvm_cbe_tmp__621;
  } else {
    llvm_cbe_tmp__587__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__622;
  }

llvm_cbe_tmp__621:
  llvm_cbe_tmp__585 = *(&llvm_cbe_cppVar_561);
  llvm_cbe_tmp__586 = ((((bool )llvm_cbe_tmp__585&1u))&1);
  llvm_cbe_tmp__587__PHI_TEMPORARY = llvm_cbe_tmp__586;   /* for PHI node */
  goto llvm_cbe_tmp__622;

llvm_cbe_tmp__622:
  llvm_cbe_tmp__587 = ((llvm_cbe_tmp__587__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_562) = (((unsigned char )(bool )llvm_cbe_tmp__587));
  llvm_cbe_tmp__588 = *((&llvm_cbe_tmp__571->field13));
  *(&llvm_cbe_cppVar_564) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__588) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__589 = *(&llvm_cbe_cppVar_564);
  llvm_cbe_tmp__590 = *((&llvm_cbe_tmp__571->field39));
  *(&llvm_cbe_cppVar_564) = (llvm_cbe_tmp__589 & llvm_cbe_tmp__590);
  llvm_cbe_tmp__591 = *((&llvm_cbe_tmp__571->field5));
  llvm_cbe_tmp__592 = *(&llvm_cbe_cppVar_564);
  *(&llvm_cbe_cppVar_565) = (((unsigned char )(bool )(llvm_cbe_tmp__591 == llvm_cbe_tmp__592)));
  llvm_cbe_tmp__593 = *(&llvm_cbe_cppVar_562);
  if ((((((bool )llvm_cbe_tmp__593&1u))&1))) {
    goto llvm_cbe_tmp__623;
  } else {
    llvm_cbe_tmp__596__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__624;
  }

llvm_cbe_tmp__623:
  llvm_cbe_tmp__594 = *(&llvm_cbe_cppVar_565);
  llvm_cbe_tmp__595 = ((((bool )llvm_cbe_tmp__594&1u))&1);
  llvm_cbe_tmp__596__PHI_TEMPORARY = llvm_cbe_tmp__595;   /* for PHI node */
  goto llvm_cbe_tmp__624;

llvm_cbe_tmp__624:
  llvm_cbe_tmp__596 = ((llvm_cbe_tmp__596__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_566) = (((unsigned char )(bool )llvm_cbe_tmp__596));
  llvm_cbe_tmp__597 = *((&llvm_cbe_tmp__571->field8));
  llvm_cbe_tmp__598 = *((&llvm_cbe_tmp__571->field10));
  *(&llvm_cbe_cppVar_567) = (((unsigned char )(bool )(llvm_cbe_tmp__597 != llvm_cbe_tmp__598)));
  llvm_cbe_tmp__599 = *(&llvm_cbe_cppVar_566);
  if ((((((bool )llvm_cbe_tmp__599&1u))&1))) {
    goto llvm_cbe_tmp__625;
  } else {
    llvm_cbe_tmp__602__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__626;
  }

llvm_cbe_tmp__625:
  llvm_cbe_tmp__600 = *(&llvm_cbe_cppVar_567);
  llvm_cbe_tmp__601 = ((((bool )llvm_cbe_tmp__600&1u))&1);
  llvm_cbe_tmp__602__PHI_TEMPORARY = llvm_cbe_tmp__601;   /* for PHI node */
  goto llvm_cbe_tmp__626;

llvm_cbe_tmp__626:
  llvm_cbe_tmp__602 = ((llvm_cbe_tmp__602__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_568) = (((unsigned char )(bool )llvm_cbe_tmp__602));
  llvm_cbe_tmp__603 = *(&llvm_cbe_cppVar_568);
  llvm_cbe_tmp__604 = *((&llvm_cbe_tmp__571->field8));
  if ((((((bool )llvm_cbe_tmp__603&1u))&1))) {
    goto llvm_cbe_tmp__627;
  } else {
    goto llvm_cbe_tmp__628;
  }

llvm_cbe_tmp__627:
  *(&llvm_cbe_cppVar_570) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__604) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__605 = *(&llvm_cbe_cppVar_570);
  llvm_cbe_tmp__606 = *((&llvm_cbe_tmp__571->field39));
  *(&llvm_cbe_cppVar_570) = (llvm_cbe_tmp__605 & llvm_cbe_tmp__606);
  llvm_cbe_tmp__607 = *(&llvm_cbe_cppVar_570);
  *(&llvm_cbe_cppVar_559) = llvm_cbe_tmp__607;
  goto llvm_cbe_tmp__629;

llvm_cbe_tmp__628:
  *(&llvm_cbe_cppVar_559) = llvm_cbe_tmp__604;
  goto llvm_cbe_tmp__629;

llvm_cbe_tmp__629:
  llvm_cbe_tmp__608 = *(&llvm_cbe_cppVar_559);
  *(&llvm_cbe_cppVar_556) = llvm_cbe_tmp__608;
  goto llvm_cbe_tmp__630;

llvm_cbe_tmp__620:
  llvm_cbe_tmp__609 = *((&llvm_cbe_tmp__571->field8));
  *(&llvm_cbe_cppVar_556) = llvm_cbe_tmp__609;
  goto llvm_cbe_tmp__630;

llvm_cbe_tmp__630:
  llvm_cbe_tmp__610 = *(&llvm_cbe_cppVar_556);
  *(&llvm_cbe_cppVar_553) = llvm_cbe_tmp__610;
  goto llvm_cbe_tmp__618;

llvm_cbe_tmp__618:
  llvm_cbe_tmp__611 = *(&llvm_cbe_cppVar_553);
  *(&llvm_cbe_cppVar_550) = llvm_cbe_tmp__611;
  goto llvm_cbe_tmp__615;

llvm_cbe_tmp__615:
  llvm_cbe_tmp__612 = *(&llvm_cbe_cppVar_550);
  return llvm_cbe_tmp__612;
}


unsigned long long _ZN11model_train21cppUpdateFun_per_v_pcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__631;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__632;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__633;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__634;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__635;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__636;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__637;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__638;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__639;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__640;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__641;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__642;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_573;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_574;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_577;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_578;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_616;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_617;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_586;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_584;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_585;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_607;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_608;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_609;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_610;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_611;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_612;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_613;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_614;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_580;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_581;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_582;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_590;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_591;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_592;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_596;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_597;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_598;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_602;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_603;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_604;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_587;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_583;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_593;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_599;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_606;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_605;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_601;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_595;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_589;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_579;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_575;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_588;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_594;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_600;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_615;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_576;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_572;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__643;
  unsigned long long llvm_cbe_tmp__644;
  unsigned char llvm_cbe_tmp__645;
  unsigned long long llvm_cbe_tmp__646;
  unsigned char llvm_cbe_tmp__647;
  unsigned long long llvm_cbe_tmp__648;
  unsigned char llvm_cbe_tmp__649;
  unsigned char llvm_cbe_tmp__650;
  bool llvm_cbe_tmp__651;
  bool llvm_cbe_tmp__652;
  bool llvm_cbe_tmp__652__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__653;
  unsigned long long llvm_cbe_tmp__654;
  unsigned long long llvm_cbe_tmp__655;
  unsigned long long llvm_cbe_tmp__656;
  unsigned char llvm_cbe_tmp__657;
  unsigned char llvm_cbe_tmp__658;
  bool llvm_cbe_tmp__659;
  bool llvm_cbe_tmp__660;
  bool llvm_cbe_tmp__660__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__661;
  unsigned long long llvm_cbe_tmp__662;
  unsigned long long llvm_cbe_tmp__663;
  unsigned long long llvm_cbe_tmp__664;
  unsigned char llvm_cbe_tmp__665;
  unsigned char llvm_cbe_tmp__666;
  bool llvm_cbe_tmp__667;
  bool llvm_cbe_tmp__668;
  bool llvm_cbe_tmp__668__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__669;
  unsigned char llvm_cbe_tmp__670;
  unsigned char llvm_cbe_tmp__671;
  unsigned long long llvm_cbe_tmp__672;
  unsigned long long llvm_cbe_tmp__673;
  unsigned long long llvm_cbe_tmp__674;
  unsigned char llvm_cbe_tmp__675;
  unsigned char llvm_cbe_tmp__676;
  bool llvm_cbe_tmp__677;
  bool llvm_cbe_tmp__678;
  bool llvm_cbe_tmp__678__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__679;
  unsigned char llvm_cbe_tmp__680;
  unsigned long long llvm_cbe_tmp__681;
  unsigned long long llvm_cbe_tmp__682;
  unsigned long long llvm_cbe_tmp__683;
  unsigned char llvm_cbe_tmp__684;
  unsigned char llvm_cbe_tmp__685;
  bool llvm_cbe_tmp__686;
  bool llvm_cbe_tmp__687;
  bool llvm_cbe_tmp__687__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__688;
  unsigned char llvm_cbe_tmp__689;
  unsigned long long llvm_cbe_tmp__690;
  unsigned long long llvm_cbe_tmp__691;
  unsigned long long llvm_cbe_tmp__692;
  unsigned long long llvm_cbe_tmp__693;
  unsigned long long llvm_cbe_tmp__694;
  unsigned long long llvm_cbe_tmp__695;
  unsigned long long llvm_cbe_tmp__696;
  unsigned long long llvm_cbe_tmp__697;
  unsigned long long llvm_cbe_tmp__698;
  unsigned char llvm_cbe_tmp__699;
  unsigned char llvm_cbe_tmp__700;
  bool llvm_cbe_tmp__701;
  bool llvm_cbe_tmp__702;
  bool llvm_cbe_tmp__702__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__703;
  unsigned long long llvm_cbe_tmp__704;
  unsigned long long llvm_cbe_tmp__705;
  unsigned long long llvm_cbe_tmp__706;
  unsigned long long llvm_cbe_tmp__707;
  unsigned long long llvm_cbe_tmp__708;
  unsigned long long llvm_cbe_tmp__709;
  unsigned long long llvm_cbe_tmp__710;
  unsigned long long llvm_cbe_tmp__711;
  unsigned long long llvm_cbe_tmp__712;
  unsigned long long llvm_cbe_tmp__713;
  unsigned long long llvm_cbe_tmp__714;
  unsigned long long llvm_cbe_tmp__715;

  *(&llvm_cbe_tmp__631) = llvm_cbe_this;
  *(&llvm_cbe_tmp__632) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__633) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__634) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__635) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__636) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__637) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__638) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__639) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__640) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__641) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__642) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__643 = *(&llvm_cbe_tmp__631);
  llvm_cbe_tmp__644 = *((&llvm_cbe_tmp__643->field29));
  *(&llvm_cbe_cppVar_574) = (((unsigned char )(bool )(llvm_cbe_tmp__644 == 0ull)));
  llvm_cbe_tmp__645 = *(&llvm_cbe_cppVar_574);
  if ((((((bool )llvm_cbe_tmp__645&1u))&1))) {
    goto llvm_cbe_tmp__716;
  } else {
    goto llvm_cbe_tmp__717;
  }

llvm_cbe_tmp__716:
  *(&llvm_cbe_cppVar_572) = 0ull;
  goto llvm_cbe_tmp__718;

llvm_cbe_tmp__717:
  llvm_cbe_tmp__646 = *((&llvm_cbe_tmp__643->field29));
  *(&llvm_cbe_cppVar_578) = (((unsigned char )(bool )(llvm_cbe_tmp__646 == 1ull)));
  llvm_cbe_tmp__647 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__647&1u))&1))) {
    goto llvm_cbe_tmp__719;
  } else {
    goto llvm_cbe_tmp__720;
  }

llvm_cbe_tmp__719:
  llvm_cbe_tmp__648 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_581) = (((unsigned char )(bool )(llvm_cbe_tmp__648 == 0ull)));
  llvm_cbe_tmp__649 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__649&1u))&1))) {
    goto llvm_cbe_tmp__721;
  } else {
    llvm_cbe_tmp__652__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__722;
  }

llvm_cbe_tmp__721:
  llvm_cbe_tmp__650 = *(&llvm_cbe_cppVar_581);
  llvm_cbe_tmp__651 = ((((bool )llvm_cbe_tmp__650&1u))&1);
  llvm_cbe_tmp__652__PHI_TEMPORARY = llvm_cbe_tmp__651;   /* for PHI node */
  goto llvm_cbe_tmp__722;

llvm_cbe_tmp__722:
  llvm_cbe_tmp__652 = ((llvm_cbe_tmp__652__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_582) = (((unsigned char )(bool )llvm_cbe_tmp__652));
  llvm_cbe_tmp__653 = *(&llvm_cbe_cppVar_582);
  if ((((((bool )llvm_cbe_tmp__653&1u))&1))) {
    goto llvm_cbe_tmp__723;
  } else {
    goto llvm_cbe_tmp__724;
  }

llvm_cbe_tmp__723:
  llvm_cbe_tmp__654 = *((&llvm_cbe_tmp__643->field7));
  *(&llvm_cbe_cppVar_585) = (((unsigned char )(bool )(llvm_cbe_tmp__654 == 4ull)));
  llvm_cbe_tmp__655 = *((&llvm_cbe_tmp__643->field25));
  llvm_cbe_tmp__656 = *((&llvm_cbe_tmp__643->field9));
  *(&llvm_cbe_cppVar_586) = (((unsigned char )(bool )(llvm_cbe_tmp__655 == llvm_cbe_tmp__656)));
  llvm_cbe_tmp__657 = *(&llvm_cbe_cppVar_585);
  if ((((((bool )llvm_cbe_tmp__657&1u))&1))) {
    goto llvm_cbe_tmp__725;
  } else {
    llvm_cbe_tmp__660__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__726;
  }

llvm_cbe_tmp__725:
  llvm_cbe_tmp__658 = *(&llvm_cbe_cppVar_586);
  llvm_cbe_tmp__659 = ((((bool )llvm_cbe_tmp__658&1u))&1);
  llvm_cbe_tmp__660__PHI_TEMPORARY = llvm_cbe_tmp__659;   /* for PHI node */
  goto llvm_cbe_tmp__726;

llvm_cbe_tmp__726:
  llvm_cbe_tmp__660 = ((llvm_cbe_tmp__660__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_587) = (((unsigned char )(bool )llvm_cbe_tmp__660));
  llvm_cbe_tmp__661 = *(&llvm_cbe_cppVar_587);
  if ((((((bool )llvm_cbe_tmp__661&1u))&1))) {
    goto llvm_cbe_tmp__727;
  } else {
    goto llvm_cbe_tmp__728;
  }

llvm_cbe_tmp__727:
  *(&llvm_cbe_cppVar_583) = 1ull;
  goto llvm_cbe_tmp__729;

llvm_cbe_tmp__728:
  llvm_cbe_tmp__662 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_583) = llvm_cbe_tmp__662;
  goto llvm_cbe_tmp__729;

llvm_cbe_tmp__729:
  llvm_cbe_tmp__663 = *(&llvm_cbe_cppVar_583);
  *(&llvm_cbe_cppVar_579) = llvm_cbe_tmp__663;
  goto llvm_cbe_tmp__730;

llvm_cbe_tmp__724:
  llvm_cbe_tmp__664 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_591) = (((unsigned char )(bool )(llvm_cbe_tmp__664 == 1ull)));
  llvm_cbe_tmp__665 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__665&1u))&1))) {
    goto llvm_cbe_tmp__731;
  } else {
    llvm_cbe_tmp__668__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__732;
  }

llvm_cbe_tmp__731:
  llvm_cbe_tmp__666 = *(&llvm_cbe_cppVar_591);
  llvm_cbe_tmp__667 = ((((bool )llvm_cbe_tmp__666&1u))&1);
  llvm_cbe_tmp__668__PHI_TEMPORARY = llvm_cbe_tmp__667;   /* for PHI node */
  goto llvm_cbe_tmp__732;

llvm_cbe_tmp__732:
  llvm_cbe_tmp__668 = ((llvm_cbe_tmp__668__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_592) = (((unsigned char )(bool )llvm_cbe_tmp__668));
  llvm_cbe_tmp__669 = *((&llvm_cbe_tmp__643->field7));
  *(&llvm_cbe_cppVar_585) = (((unsigned char )(bool )(llvm_cbe_tmp__669 == 4ull)));
  llvm_cbe_tmp__670 = *(&llvm_cbe_cppVar_592);
  if ((((((bool )llvm_cbe_tmp__670&1u))&1))) {
    goto llvm_cbe_tmp__733;
  } else {
    goto llvm_cbe_tmp__734;
  }

llvm_cbe_tmp__733:
  llvm_cbe_tmp__671 = *(&llvm_cbe_cppVar_585);
  if ((((((bool )llvm_cbe_tmp__671&1u))&1))) {
    goto llvm_cbe_tmp__735;
  } else {
    goto llvm_cbe_tmp__736;
  }

llvm_cbe_tmp__735:
  *(&llvm_cbe_cppVar_593) = 2ull;
  goto llvm_cbe_tmp__737;

llvm_cbe_tmp__736:
  llvm_cbe_tmp__672 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_593) = llvm_cbe_tmp__672;
  goto llvm_cbe_tmp__737;

llvm_cbe_tmp__737:
  llvm_cbe_tmp__673 = *(&llvm_cbe_cppVar_593);
  *(&llvm_cbe_cppVar_589) = llvm_cbe_tmp__673;
  goto llvm_cbe_tmp__738;

llvm_cbe_tmp__734:
  llvm_cbe_tmp__674 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_597) = (((unsigned char )(bool )(llvm_cbe_tmp__674 == 2ull)));
  llvm_cbe_tmp__675 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__675&1u))&1))) {
    goto llvm_cbe_tmp__739;
  } else {
    llvm_cbe_tmp__678__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__740;
  }

llvm_cbe_tmp__739:
  llvm_cbe_tmp__676 = *(&llvm_cbe_cppVar_597);
  llvm_cbe_tmp__677 = ((((bool )llvm_cbe_tmp__676&1u))&1);
  llvm_cbe_tmp__678__PHI_TEMPORARY = llvm_cbe_tmp__677;   /* for PHI node */
  goto llvm_cbe_tmp__740;

llvm_cbe_tmp__740:
  llvm_cbe_tmp__678 = ((llvm_cbe_tmp__678__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_598) = (((unsigned char )(bool )llvm_cbe_tmp__678));
  llvm_cbe_tmp__679 = *(&llvm_cbe_cppVar_598);
  if ((((((bool )llvm_cbe_tmp__679&1u))&1))) {
    goto llvm_cbe_tmp__741;
  } else {
    goto llvm_cbe_tmp__742;
  }

llvm_cbe_tmp__741:
  llvm_cbe_tmp__680 = *(&llvm_cbe_cppVar_585);
  if ((((((bool )llvm_cbe_tmp__680&1u))&1))) {
    goto llvm_cbe_tmp__743;
  } else {
    goto llvm_cbe_tmp__744;
  }

llvm_cbe_tmp__743:
  *(&llvm_cbe_cppVar_599) = 3ull;
  goto llvm_cbe_tmp__745;

llvm_cbe_tmp__744:
  llvm_cbe_tmp__681 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_599) = llvm_cbe_tmp__681;
  goto llvm_cbe_tmp__745;

llvm_cbe_tmp__745:
  llvm_cbe_tmp__682 = *(&llvm_cbe_cppVar_599);
  *(&llvm_cbe_cppVar_595) = llvm_cbe_tmp__682;
  goto llvm_cbe_tmp__746;

llvm_cbe_tmp__742:
  llvm_cbe_tmp__683 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_603) = (((unsigned char )(bool )(llvm_cbe_tmp__683 == 3ull)));
  llvm_cbe_tmp__684 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__684&1u))&1))) {
    goto llvm_cbe_tmp__747;
  } else {
    llvm_cbe_tmp__687__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__748;
  }

llvm_cbe_tmp__747:
  llvm_cbe_tmp__685 = *(&llvm_cbe_cppVar_603);
  llvm_cbe_tmp__686 = ((((bool )llvm_cbe_tmp__685&1u))&1);
  llvm_cbe_tmp__687__PHI_TEMPORARY = llvm_cbe_tmp__686;   /* for PHI node */
  goto llvm_cbe_tmp__748;

llvm_cbe_tmp__748:
  llvm_cbe_tmp__687 = ((llvm_cbe_tmp__687__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_604) = (((unsigned char )(bool )llvm_cbe_tmp__687));
  llvm_cbe_tmp__688 = *(&llvm_cbe_cppVar_604);
  if ((((((bool )llvm_cbe_tmp__688&1u))&1))) {
    goto llvm_cbe_tmp__749;
  } else {
    goto llvm_cbe_tmp__750;
  }

llvm_cbe_tmp__749:
  llvm_cbe_tmp__689 = *(&llvm_cbe_cppVar_585);
  if ((((((bool )llvm_cbe_tmp__689&1u))&1))) {
    goto llvm_cbe_tmp__751;
  } else {
    goto llvm_cbe_tmp__752;
  }

llvm_cbe_tmp__751:
  llvm_cbe_tmp__690 = *((&llvm_cbe_tmp__643->field30));
  *(&llvm_cbe_cppVar_608) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__690) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__691 = *(&llvm_cbe_cppVar_608);
  llvm_cbe_tmp__692 = *((&llvm_cbe_tmp__643->field39));
  *(&llvm_cbe_cppVar_608) = (llvm_cbe_tmp__691 & llvm_cbe_tmp__692);
  llvm_cbe_tmp__693 = *(&llvm_cbe_cppVar_608);
  llvm_cbe_tmp__694 = *((&llvm_cbe_tmp__643->field14));
  *(&llvm_cbe_cppVar_609) = (((unsigned char )(bool )(llvm_cbe_tmp__693 == llvm_cbe_tmp__694)));
  llvm_cbe_tmp__695 = *((&llvm_cbe_tmp__643->field30));
  *(&llvm_cbe_cppVar_611) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__695) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__696 = *(&llvm_cbe_cppVar_611);
  llvm_cbe_tmp__697 = *((&llvm_cbe_tmp__643->field39));
  *(&llvm_cbe_cppVar_611) = (llvm_cbe_tmp__696 & llvm_cbe_tmp__697);
  llvm_cbe_tmp__698 = *(&llvm_cbe_cppVar_611);
  *(&llvm_cbe_cppVar_613) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__698) >= ((signed long long )500ull))));
  llvm_cbe_tmp__699 = *(&llvm_cbe_cppVar_609);
  if ((((((bool )llvm_cbe_tmp__699&1u))&1))) {
    llvm_cbe_tmp__702__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__753;
  } else {
    goto llvm_cbe_tmp__754;
  }

llvm_cbe_tmp__754:
  llvm_cbe_tmp__700 = *(&llvm_cbe_cppVar_613);
  llvm_cbe_tmp__701 = ((((bool )llvm_cbe_tmp__700&1u))&1);
  llvm_cbe_tmp__702__PHI_TEMPORARY = llvm_cbe_tmp__701;   /* for PHI node */
  goto llvm_cbe_tmp__753;

llvm_cbe_tmp__753:
  llvm_cbe_tmp__702 = ((llvm_cbe_tmp__702__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_614) = (((unsigned char )(bool )llvm_cbe_tmp__702));
  *(&llvm_cbe_cppVar_606) = 0ull;
  llvm_cbe_tmp__703 = *(&llvm_cbe_cppVar_606);
  *(&llvm_cbe_cppVar_605) = llvm_cbe_tmp__703;
  goto llvm_cbe_tmp__755;

llvm_cbe_tmp__752:
  llvm_cbe_tmp__704 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_605) = llvm_cbe_tmp__704;
  goto llvm_cbe_tmp__755;

llvm_cbe_tmp__755:
  llvm_cbe_tmp__705 = *(&llvm_cbe_cppVar_605);
  *(&llvm_cbe_cppVar_601) = llvm_cbe_tmp__705;
  goto llvm_cbe_tmp__756;

llvm_cbe_tmp__750:
  llvm_cbe_tmp__706 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_601) = llvm_cbe_tmp__706;
  goto llvm_cbe_tmp__756;

llvm_cbe_tmp__756:
  llvm_cbe_tmp__707 = *(&llvm_cbe_cppVar_601);
  *(&llvm_cbe_cppVar_595) = llvm_cbe_tmp__707;
  goto llvm_cbe_tmp__746;

llvm_cbe_tmp__746:
  llvm_cbe_tmp__708 = *(&llvm_cbe_cppVar_595);
  *(&llvm_cbe_cppVar_589) = llvm_cbe_tmp__708;
  goto llvm_cbe_tmp__738;

llvm_cbe_tmp__738:
  llvm_cbe_tmp__709 = *(&llvm_cbe_cppVar_589);
  *(&llvm_cbe_cppVar_579) = llvm_cbe_tmp__709;
  goto llvm_cbe_tmp__730;

llvm_cbe_tmp__730:
  llvm_cbe_tmp__710 = *(&llvm_cbe_cppVar_579);
  *(&llvm_cbe_cppVar_576) = llvm_cbe_tmp__710;
  goto llvm_cbe_tmp__757;

llvm_cbe_tmp__720:
  llvm_cbe_tmp__711 = *((&llvm_cbe_tmp__643->field29));
  *(&llvm_cbe_cppVar_617) = (((unsigned char )(bool )(llvm_cbe_tmp__711 == 2ull)));
  llvm_cbe_tmp__712 = *((&llvm_cbe_tmp__643->field15));
  *(&llvm_cbe_cppVar_615) = llvm_cbe_tmp__712;
  llvm_cbe_tmp__713 = *(&llvm_cbe_cppVar_615);
  *(&llvm_cbe_cppVar_576) = llvm_cbe_tmp__713;
  goto llvm_cbe_tmp__757;

llvm_cbe_tmp__757:
  llvm_cbe_tmp__714 = *(&llvm_cbe_cppVar_576);
  *(&llvm_cbe_cppVar_572) = llvm_cbe_tmp__714;
  goto llvm_cbe_tmp__718;

llvm_cbe_tmp__718:
  llvm_cbe_tmp__715 = *(&llvm_cbe_cppVar_572);
  return llvm_cbe_tmp__715;
}


struct l_class_OC_SysCArray1D _ZN11model_train16cppUpdateFun_posElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__758;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__759;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__760;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__761;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__762;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__763;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__764;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__765;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__766;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__767;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__768;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__769;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1039;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1040;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1045;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1046;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1047;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1048;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1044;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1051;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1052;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1053;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1041;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1042;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1043;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1054;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1050;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1049;    /* Address-exposed local */
  bool llvm_cbe_tmp__770;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__771;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__772;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__773;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__774;
  unsigned long long llvm_cbe_tmp__775;
  unsigned char llvm_cbe_tmp__776;
  unsigned long long llvm_cbe_tmp__777;
  unsigned long long llvm_cbe_tmp__778;
  unsigned long long llvm_cbe_tmp__779;
  unsigned long long llvm_cbe_tmp__780;
  unsigned long long llvm_cbe_tmp__781;
  unsigned long long llvm_cbe_tmp__782;
  unsigned long long llvm_cbe_tmp__783;
  unsigned long long llvm_cbe_tmp__784;
  unsigned long long llvm_cbe_tmp__785;
  unsigned long long llvm_cbe_tmp__786;
  unsigned long long llvm_cbe_tmp__787;
  unsigned long long llvm_cbe_tmp__788;
  unsigned char llvm_cbe_tmp__789;
  unsigned long long llvm_cbe_tmp__790;
  unsigned long long llvm_cbe_tmp__791;
  unsigned long long llvm_cbe_tmp__792;
  unsigned long long llvm_cbe_tmp__793;
  unsigned long long llvm_cbe_tmp__794;
  unsigned long long llvm_cbe_tmp__795;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__796;
  unsigned long long llvm_cbe_tmp__797;
  unsigned long long llvm_cbe_tmp__798;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__799;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__800;
  bool llvm_cbe_tmp__801;

  *(&llvm_cbe_tmp__758) = llvm_cbe_this;
  *(&llvm_cbe_tmp__759) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__760) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__761) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__762) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__763) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__764) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__765) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__766) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__767) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__768) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__769) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__774 = *(&llvm_cbe_tmp__758);
  _ZN8type_memIbLj65536EEC1Ev((&llvm_cbe_cppVar_1054));
  *(&llvm_cbe_tmp__770) = ((0) & 1);
  _ZN8type_memIbLj65536EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__775 = *((&llvm_cbe_tmp__774->field29));
  *(&llvm_cbe_cppVar_1040) = (((unsigned char )(bool )(llvm_cbe_tmp__775 == 3ull)));
  llvm_cbe_tmp__776 = *(&llvm_cbe_cppVar_1040);
  if ((((((bool )llvm_cbe_tmp__776&1u))&1))) {
    goto llvm_cbe_tmp__802;
  } else {
    goto llvm_cbe_tmp__803;
  }

llvm_cbe_tmp__802:
  llvm_cbe_tmp__777 = *((&llvm_cbe_tmp__774->field30));
  *(&llvm_cbe_cppVar_1042) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__777))));
  llvm_cbe_tmp__778 = *(&llvm_cbe_cppVar_1042);
  llvm_cbe_tmp__779 = *((&llvm_cbe_tmp__774->field39));
  *(&llvm_cbe_cppVar_1042) = (llvm_cbe_tmp__778 & llvm_cbe_tmp__779);
  llvm_cbe_tmp__780 = *(&llvm_cbe_cppVar_1042);
  llvm_cbe_tmp__781 = *((&llvm_cbe_tmp__774->field25));
  *(&llvm_cbe_cppVar_1043) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__780) + ((unsigned long long )llvm_cbe_tmp__781))));
  llvm_cbe_tmp__782 = *(&llvm_cbe_cppVar_1043);
  llvm_cbe_tmp__783 = *((&llvm_cbe_tmp__774->field39));
  *(&llvm_cbe_cppVar_1043) = (llvm_cbe_tmp__782 & llvm_cbe_tmp__783);
  llvm_cbe_tmp__784 = *((&llvm_cbe_tmp__774->field30));
  llvm_cbe_tmp__785 = *((&llvm_cbe_tmp__774->field45));
  *(&llvm_cbe_cppVar_1045) = ((((signed long long )(((signed long long )llvm_cbe_tmp__784) >> ((signed long long )0ull)))) & llvm_cbe_tmp__785);
  llvm_cbe_tmp__786 = *(&llvm_cbe_cppVar_1045);
  llvm_cbe_tmp__787 = _ZN8type_memIhLj512EE2rdEl(((&llvm_cbe_tmp__774->field0)), llvm_cbe_tmp__786);
  *(&llvm_cbe_cppVar_1046) = llvm_cbe_tmp__787;
  llvm_cbe_tmp__788 = *(&llvm_cbe_cppVar_1046);
  *(&llvm_cbe_cppVar_1048) = (((unsigned char )(bool )(llvm_cbe_tmp__788 != 0ull)));
  llvm_cbe_tmp__789 = *(&llvm_cbe_cppVar_1048);
  if ((((((bool )llvm_cbe_tmp__789&1u))&1))) {
    goto llvm_cbe_tmp__804;
  } else {
    goto llvm_cbe_tmp__805;
  }

llvm_cbe_tmp__804:
  *(&llvm_cbe_cppVar_1044) = 1ull;
  goto llvm_cbe_tmp__806;

llvm_cbe_tmp__805:
  *(&llvm_cbe_cppVar_1044) = 0ull;
  goto llvm_cbe_tmp__806;

llvm_cbe_tmp__806:
  llvm_cbe_tmp__790 = *((&llvm_cbe_tmp__774->field25));
  llvm_cbe_tmp__791 = *((&llvm_cbe_tmp__774->field43));
  *(&llvm_cbe_cppVar_1051) = ((((signed long long )(((signed long long )llvm_cbe_tmp__790) >> ((signed long long )0ull)))) & llvm_cbe_tmp__791);
  llvm_cbe_tmp__792 = *(&llvm_cbe_cppVar_1051);
  llvm_cbe_tmp__793 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__774->field4)), llvm_cbe_tmp__792);
  *(&llvm_cbe_cppVar_1052) = llvm_cbe_tmp__793;
  llvm_cbe_tmp__794 = *(&llvm_cbe_cppVar_1044);
  llvm_cbe_tmp__795 = *(&llvm_cbe_cppVar_1052);
  *(&llvm_cbe_cppVar_1053) = (llvm_cbe_tmp__794 & llvm_cbe_tmp__795);
  llvm_cbe_tmp__796 = _ZN8type_memIbLj65536EEaSERKS0_((&llvm_cbe_cppVar_1054), ((&llvm_cbe_tmp__774->field16)));
  llvm_cbe_tmp__797 = *(&llvm_cbe_cppVar_1043);
  llvm_cbe_tmp__798 = *(&llvm_cbe_cppVar_1053);
  _ZN8type_memIbLj65536EE2wrEll((&llvm_cbe_cppVar_1054), llvm_cbe_tmp__797, llvm_cbe_tmp__798);
  llvm_cbe_tmp__799 = _ZN8type_memIbLj65536EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1054));
  goto llvm_cbe_tmp__807;

llvm_cbe_tmp__803:
  llvm_cbe_tmp__800 = _ZN8type_memIbLj65536EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__774->field16)));
  goto llvm_cbe_tmp__807;

llvm_cbe_tmp__807:
  *(&llvm_cbe_tmp__770) = ((1) & 1);
  *(&llvm_cbe_tmp__773) = 1u;
  llvm_cbe_tmp__801 = ((*(&llvm_cbe_tmp__770))&1);
  if (llvm_cbe_tmp__801) {
    goto llvm_cbe_tmp__808;
  } else {
    goto llvm_cbe_tmp__809;
  }

llvm_cbe_tmp__809:
  _ZN8type_memIbLj65536EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__808;

llvm_cbe_tmp__808:
  _ZN8type_memIbLj65536EED1Ev((&llvm_cbe_cppVar_1054));
  return StructReturn;
}


void _ZN8type_memIbLj65536EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__810;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__811;

  *(&llvm_cbe_tmp__810) = llvm_cbe_this;
  llvm_cbe_tmp__811 = *(&llvm_cbe_tmp__810);
  _ZN8type_memIbLj65536EEC2Ev(llvm_cbe_tmp__811);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIbLj65536EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__812;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__813;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__814;
  unsigned char *llvm_cbe_tmp__815;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__816;
  unsigned char *llvm_cbe_tmp__817;

  *(&llvm_cbe_tmp__812) = llvm_cbe_this;
  *(&llvm_cbe_tmp__813) = llvm_cbe_r;
  llvm_cbe_tmp__814 = *(&llvm_cbe_tmp__812);
  llvm_cbe_tmp__815 = *((&llvm_cbe_tmp__814->field0));
  llvm_cbe_tmp__816 = *(&llvm_cbe_tmp__813);
  llvm_cbe_tmp__817 = *((&llvm_cbe_tmp__816->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__815, llvm_cbe_tmp__817);
  return llvm_cbe_tmp__814;
}


void _ZN8type_memIbLj65536EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__818;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__819;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__820;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__821;
  unsigned long long llvm_cbe_tmp__822;
  unsigned long long llvm_cbe_tmp__823;
  unsigned char *llvm_cbe_tmp__824;

  *(&llvm_cbe_tmp__818) = llvm_cbe_this;
  *(&llvm_cbe_tmp__819) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__820) = llvm_cbe_data;
  llvm_cbe_tmp__821 = *(&llvm_cbe_tmp__818);
  llvm_cbe_tmp__822 = *(&llvm_cbe_tmp__820);
  llvm_cbe_tmp__823 = *(&llvm_cbe_tmp__819);
  llvm_cbe_tmp__824 = *((&llvm_cbe_tmp__821->field0));
  *((&llvm_cbe_tmp__824[((signed long long )llvm_cbe_tmp__823)])) = (((unsigned char )(bool )(llvm_cbe_tmp__822 != 0ull)));
  return;
}


void _ZN8type_memIbLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__825;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__826;

  *(&llvm_cbe_tmp__825) = llvm_cbe_this;
  llvm_cbe_tmp__826 = *(&llvm_cbe_tmp__825);
  _ZN8type_memIbLj65536EED2Ev(llvm_cbe_tmp__826);
  return;
}


struct l_unnamed1 _ZN11model_train17cppUpdateFun_pow2Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_unnamed1 StructReturn;  /* Struct return temporary */
  struct l_unnamed1 *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__827;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__828;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__829;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__830;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__831;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__832;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__833;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__834;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__835;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__836;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__837;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__838;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1057;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1058;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1060;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1061;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1084;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1085;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1063;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1064;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1065;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1067;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1068;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1069;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1071;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1072;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1073;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1080;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1081;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1082;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1075;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1076;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1077;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1074;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1078;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1079;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__839;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__840;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1070;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1066;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1062;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1083;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1059;    /* Address-exposed local */
  bool llvm_cbe_tmp__841;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__842;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__843;
  unsigned long long llvm_cbe_tmp__844;
  unsigned char llvm_cbe_tmp__845;
  struct l_unnamed1 *llvm_cbe_tmp__846;
  unsigned long long llvm_cbe_tmp__847;
  unsigned char llvm_cbe_tmp__848;
  unsigned long long llvm_cbe_tmp__849;
  unsigned char llvm_cbe_tmp__850;
  unsigned char llvm_cbe_tmp__851;
  bool llvm_cbe_tmp__852;
  bool llvm_cbe_tmp__853;
  bool llvm_cbe_tmp__853__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__854;
  struct l_unnamed1 *llvm_cbe_tmp__855;
  unsigned long long llvm_cbe_tmp__856;
  unsigned char llvm_cbe_tmp__857;
  unsigned char llvm_cbe_tmp__858;
  bool llvm_cbe_tmp__859;
  bool llvm_cbe_tmp__860;
  bool llvm_cbe_tmp__860__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__861;
  struct l_unnamed1 *llvm_cbe_tmp__862;
  unsigned long long llvm_cbe_tmp__863;
  unsigned char llvm_cbe_tmp__864;
  unsigned char llvm_cbe_tmp__865;
  bool llvm_cbe_tmp__866;
  bool llvm_cbe_tmp__867;
  bool llvm_cbe_tmp__867__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__868;
  unsigned long long llvm_cbe_tmp__869;
  unsigned long long llvm_cbe_tmp__870;
  unsigned long long llvm_cbe_tmp__871;
  unsigned long long llvm_cbe_tmp__872;
  unsigned long long llvm_cbe_tmp__873;
  unsigned long long llvm_cbe_tmp__874;
  unsigned long long llvm_cbe_tmp__875;
  unsigned short llvm_cbe_tmp__876;
  struct l_unnamed1 *llvm_cbe_tmp__877;
  unsigned long long llvm_cbe_tmp__878;
  unsigned long long llvm_cbe_tmp__879;
  struct l_unnamed1 *llvm_cbe_tmp__880;
  unsigned long long llvm_cbe_tmp__881;
  unsigned char llvm_cbe_tmp__882;
  unsigned char llvm_cbe_tmp__883;
  bool llvm_cbe_tmp__884;
  bool llvm_cbe_tmp__885;
  bool llvm_cbe_tmp__885__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__886;
  bool llvm_cbe_tmp__887;
  struct l_unnamed1 *llvm_cbe_tmp__888;
  struct l_unnamed1 *llvm_cbe_tmp__889;
  struct l_unnamed1 *llvm_cbe_tmp__890;
  struct l_unnamed1 *llvm_cbe_tmp__891;
  struct l_unnamed1 *llvm_cbe_tmp__892;
  unsigned long long llvm_cbe_tmp__893;
  unsigned char llvm_cbe_tmp__894;
  bool llvm_cbe_tmp__895;
  struct l_unnamed1 *llvm_cbe_tmp__896;
  struct l_unnamed1 *llvm_cbe_tmp__897;
  struct l_unnamed1 *llvm_cbe_tmp__898;
  bool llvm_cbe_tmp__899;

  *(&llvm_cbe_tmp__827) = llvm_cbe_this;
  *(&llvm_cbe_tmp__828) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__829) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__830) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__831) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__832) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__833) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__834) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__835) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__836) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__837) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__838) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__843 = *(&llvm_cbe_tmp__827);
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1078));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1079));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1070));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1066));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1062));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1083));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1059));
  *(&llvm_cbe_tmp__841) = ((0) & 1);
  _ZN8type_memIjLj8EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__844 = *((&llvm_cbe_tmp__843->field29));
  *(&llvm_cbe_cppVar_1058) = (((unsigned char )(bool )(llvm_cbe_tmp__844 == 0ull)));
  llvm_cbe_tmp__845 = *(&llvm_cbe_cppVar_1058);
  if ((((((bool )llvm_cbe_tmp__845&1u))&1))) {
    goto llvm_cbe_tmp__900;
  } else {
    goto llvm_cbe_tmp__901;
  }

llvm_cbe_tmp__900:
  llvm_cbe_tmp__846 = _ZN8type_memIjLj8EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__843->field17)));
  goto llvm_cbe_tmp__902;

llvm_cbe_tmp__901:
  llvm_cbe_tmp__847 = *((&llvm_cbe_tmp__843->field29));
  *(&llvm_cbe_cppVar_1061) = (((unsigned char )(bool )(llvm_cbe_tmp__847 == 1ull)));
  llvm_cbe_tmp__848 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__848&1u))&1))) {
    goto llvm_cbe_tmp__903;
  } else {
    goto llvm_cbe_tmp__904;
  }

llvm_cbe_tmp__903:
  llvm_cbe_tmp__849 = *((&llvm_cbe_tmp__843->field15));
  *(&llvm_cbe_cppVar_1064) = (((unsigned char )(bool )(llvm_cbe_tmp__849 == 0ull)));
  llvm_cbe_tmp__850 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__850&1u))&1))) {
    goto llvm_cbe_tmp__905;
  } else {
    llvm_cbe_tmp__853__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__906;
  }

llvm_cbe_tmp__905:
  llvm_cbe_tmp__851 = *(&llvm_cbe_cppVar_1064);
  llvm_cbe_tmp__852 = ((((bool )llvm_cbe_tmp__851&1u))&1);
  llvm_cbe_tmp__853__PHI_TEMPORARY = llvm_cbe_tmp__852;   /* for PHI node */
  goto llvm_cbe_tmp__906;

llvm_cbe_tmp__906:
  llvm_cbe_tmp__853 = ((llvm_cbe_tmp__853__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1065) = (((unsigned char )(bool )llvm_cbe_tmp__853));
  llvm_cbe_tmp__854 = *(&llvm_cbe_cppVar_1065);
  if ((((((bool )llvm_cbe_tmp__854&1u))&1))) {
    goto llvm_cbe_tmp__907;
  } else {
    goto llvm_cbe_tmp__908;
  }

llvm_cbe_tmp__907:
  llvm_cbe_tmp__855 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1062), ((&llvm_cbe_tmp__843->field17)));
  goto llvm_cbe_tmp__909;

llvm_cbe_tmp__908:
  llvm_cbe_tmp__856 = *((&llvm_cbe_tmp__843->field15));
  *(&llvm_cbe_cppVar_1068) = (((unsigned char )(bool )(llvm_cbe_tmp__856 == 1ull)));
  llvm_cbe_tmp__857 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__857&1u))&1))) {
    goto llvm_cbe_tmp__910;
  } else {
    llvm_cbe_tmp__860__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__911;
  }

llvm_cbe_tmp__910:
  llvm_cbe_tmp__858 = *(&llvm_cbe_cppVar_1068);
  llvm_cbe_tmp__859 = ((((bool )llvm_cbe_tmp__858&1u))&1);
  llvm_cbe_tmp__860__PHI_TEMPORARY = llvm_cbe_tmp__859;   /* for PHI node */
  goto llvm_cbe_tmp__911;

llvm_cbe_tmp__911:
  llvm_cbe_tmp__860 = ((llvm_cbe_tmp__860__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1069) = (((unsigned char )(bool )llvm_cbe_tmp__860));
  llvm_cbe_tmp__861 = *(&llvm_cbe_cppVar_1069);
  if ((((((bool )llvm_cbe_tmp__861&1u))&1))) {
    goto llvm_cbe_tmp__912;
  } else {
    goto llvm_cbe_tmp__913;
  }

llvm_cbe_tmp__912:
  llvm_cbe_tmp__862 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1066), ((&llvm_cbe_tmp__843->field17)));
  goto llvm_cbe_tmp__914;

llvm_cbe_tmp__913:
  llvm_cbe_tmp__863 = *((&llvm_cbe_tmp__843->field15));
  *(&llvm_cbe_cppVar_1072) = (((unsigned char )(bool )(llvm_cbe_tmp__863 == 2ull)));
  llvm_cbe_tmp__864 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__864&1u))&1))) {
    goto llvm_cbe_tmp__915;
  } else {
    llvm_cbe_tmp__867__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__916;
  }

llvm_cbe_tmp__915:
  llvm_cbe_tmp__865 = *(&llvm_cbe_cppVar_1072);
  llvm_cbe_tmp__866 = ((((bool )llvm_cbe_tmp__865&1u))&1);
  llvm_cbe_tmp__867__PHI_TEMPORARY = llvm_cbe_tmp__866;   /* for PHI node */
  goto llvm_cbe_tmp__916;

llvm_cbe_tmp__916:
  llvm_cbe_tmp__867 = ((llvm_cbe_tmp__867__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1073) = (((unsigned char )(bool )llvm_cbe_tmp__867));
  llvm_cbe_tmp__868 = *(&llvm_cbe_cppVar_1073);
  if ((((((bool )llvm_cbe_tmp__868&1u))&1))) {
    goto llvm_cbe_tmp__917;
  } else {
    goto llvm_cbe_tmp__918;
  }

llvm_cbe_tmp__917:
  llvm_cbe_tmp__869 = *((&llvm_cbe_tmp__843->field7));
  llvm_cbe_tmp__870 = *((&llvm_cbe_tmp__843->field40));
  *(&llvm_cbe_cppVar_1074) = ((((signed long long )(((signed long long )llvm_cbe_tmp__869) >> ((signed long long )0ull)))) & llvm_cbe_tmp__870);
  llvm_cbe_tmp__871 = *((&llvm_cbe_tmp__843->field7));
  llvm_cbe_tmp__872 = *((&llvm_cbe_tmp__843->field40));
  *(&llvm_cbe_cppVar_1075) = ((((signed long long )(((signed long long )llvm_cbe_tmp__871) >> ((signed long long )0ull)))) & llvm_cbe_tmp__872);
  llvm_cbe_tmp__873 = *(&llvm_cbe_cppVar_1075);
  llvm_cbe_tmp__874 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__843->field32)), llvm_cbe_tmp__873);
  *(&llvm_cbe_cppVar_1076) = llvm_cbe_tmp__874;
  llvm_cbe_tmp__875 = *(&llvm_cbe_cppVar_1076);
  llvm_cbe_tmp__876 = _Z10to_int_expl(llvm_cbe_tmp__875);
  *(&llvm_cbe_cppVar_1077) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__876));
  llvm_cbe_tmp__877 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1078), ((&llvm_cbe_tmp__843->field17)));
  llvm_cbe_tmp__878 = *(&llvm_cbe_cppVar_1074);
  llvm_cbe_tmp__879 = *(&llvm_cbe_cppVar_1077);
  _ZN8type_memIjLj8EE2wrEll((&llvm_cbe_cppVar_1078), llvm_cbe_tmp__878, llvm_cbe_tmp__879);
  llvm_cbe_tmp__880 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1070), (&llvm_cbe_cppVar_1078));
  goto llvm_cbe_tmp__919;

llvm_cbe_tmp__918:
  llvm_cbe_tmp__881 = *((&llvm_cbe_tmp__843->field15));
  *(&llvm_cbe_cppVar_1081) = (((unsigned char )(bool )(llvm_cbe_tmp__881 == 3ull)));
  llvm_cbe_tmp__882 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__882&1u))&1))) {
    goto llvm_cbe_tmp__920;
  } else {
    llvm_cbe_tmp__885__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__921;
  }

llvm_cbe_tmp__920:
  llvm_cbe_tmp__883 = *(&llvm_cbe_cppVar_1081);
  llvm_cbe_tmp__884 = ((((bool )llvm_cbe_tmp__883&1u))&1);
  llvm_cbe_tmp__885__PHI_TEMPORARY = llvm_cbe_tmp__884;   /* for PHI node */
  goto llvm_cbe_tmp__921;

llvm_cbe_tmp__921:
  llvm_cbe_tmp__885 = ((llvm_cbe_tmp__885__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1082) = (((unsigned char )(bool )llvm_cbe_tmp__885));
  llvm_cbe_tmp__886 = *(&llvm_cbe_cppVar_1082);
  llvm_cbe_tmp__887 = ((((bool )llvm_cbe_tmp__886&1u))&1);
  llvm_cbe_tmp__888 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1079), ((&llvm_cbe_tmp__843->field17)));
  llvm_cbe_tmp__889 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1070), (&llvm_cbe_cppVar_1079));
  goto llvm_cbe_tmp__919;

llvm_cbe_tmp__919:
  llvm_cbe_tmp__890 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1066), (&llvm_cbe_cppVar_1070));
  goto llvm_cbe_tmp__914;

llvm_cbe_tmp__914:
  llvm_cbe_tmp__891 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1062), (&llvm_cbe_cppVar_1066));
  goto llvm_cbe_tmp__909;

llvm_cbe_tmp__909:
  llvm_cbe_tmp__892 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1059), (&llvm_cbe_cppVar_1062));
  goto llvm_cbe_tmp__922;

llvm_cbe_tmp__904:
  llvm_cbe_tmp__893 = *((&llvm_cbe_tmp__843->field29));
  *(&llvm_cbe_cppVar_1085) = (((unsigned char )(bool )(llvm_cbe_tmp__893 == 2ull)));
  llvm_cbe_tmp__894 = *(&llvm_cbe_cppVar_1085);
  llvm_cbe_tmp__895 = ((((bool )llvm_cbe_tmp__894&1u))&1);
  llvm_cbe_tmp__896 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1083), ((&llvm_cbe_tmp__843->field17)));
  llvm_cbe_tmp__897 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1059), (&llvm_cbe_cppVar_1083));
  goto llvm_cbe_tmp__922;

llvm_cbe_tmp__922:
  llvm_cbe_tmp__898 = _ZN8type_memIjLj8EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1059));
  goto llvm_cbe_tmp__902;

llvm_cbe_tmp__902:
  *(&llvm_cbe_tmp__841) = ((1) & 1);
  *(&llvm_cbe_tmp__842) = 1u;
  llvm_cbe_tmp__899 = ((*(&llvm_cbe_tmp__841))&1);
  if (llvm_cbe_tmp__899) {
    goto llvm_cbe_tmp__923;
  } else {
    goto llvm_cbe_tmp__924;
  }

llvm_cbe_tmp__924:
  _ZN8type_memIjLj8EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__923;

llvm_cbe_tmp__923:
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1059));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1083));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1062));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1066));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1070));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1079));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1078));
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


unsigned long long _ZN11model_train22cppUpdateFun_sumOfpow2Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__948;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_cppVar_620;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_621;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_623;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_624;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_652;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_653;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_626;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_627;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_628;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_630;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_631;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_632;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_634;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_635;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_636;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_648;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_649;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_650;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_641;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_642;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_643;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_644;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_645;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_638;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_639;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_637;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_646;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_647;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_633;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_629;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_625;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_651;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_622;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_619;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_640;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__960;
  unsigned long long llvm_cbe_tmp__961;
  unsigned char llvm_cbe_tmp__962;
  unsigned long long llvm_cbe_tmp__963;
  unsigned long long llvm_cbe_tmp__964;
  unsigned char llvm_cbe_tmp__965;
  unsigned long long llvm_cbe_tmp__966;
  unsigned char llvm_cbe_tmp__967;
  unsigned char llvm_cbe_tmp__968;
  bool llvm_cbe_tmp__969;
  bool llvm_cbe_tmp__970;
  bool llvm_cbe_tmp__970__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__971;
  unsigned long long llvm_cbe_tmp__972;
  unsigned long long llvm_cbe_tmp__973;
  unsigned char llvm_cbe_tmp__974;
  unsigned char llvm_cbe_tmp__975;
  bool llvm_cbe_tmp__976;
  bool llvm_cbe_tmp__977;
  bool llvm_cbe_tmp__977__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__978;
  unsigned long long llvm_cbe_tmp__979;
  unsigned long long llvm_cbe_tmp__980;
  unsigned char llvm_cbe_tmp__981;
  unsigned char llvm_cbe_tmp__982;
  bool llvm_cbe_tmp__983;
  bool llvm_cbe_tmp__984;
  bool llvm_cbe_tmp__984__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__985;
  unsigned long long llvm_cbe_tmp__986;
  unsigned char llvm_cbe_tmp__987;
  unsigned long long llvm_cbe_tmp__988;
  unsigned long long llvm_cbe_tmp__989;
  unsigned long long llvm_cbe_tmp__990;
  unsigned long long llvm_cbe_tmp__991;
  unsigned long long llvm_cbe_tmp__992;
  unsigned long long llvm_cbe_tmp__993;
  unsigned short llvm_cbe_tmp__994;
  unsigned long long llvm_cbe_tmp__995;
  unsigned long long llvm_cbe_tmp__996;
  unsigned long long llvm_cbe_tmp__997;
  unsigned long long llvm_cbe_tmp__998;
  unsigned long long llvm_cbe_tmp__999;
  unsigned long long llvm_cbe_tmp__1000;
  unsigned long long llvm_cbe_tmp__1001;
  unsigned long long llvm_cbe_tmp__1002;
  unsigned long long llvm_cbe_tmp__1003;
  unsigned long long llvm_cbe_tmp__1004;
  unsigned char llvm_cbe_tmp__1005;
  unsigned char llvm_cbe_tmp__1006;
  bool llvm_cbe_tmp__1007;
  bool llvm_cbe_tmp__1008;
  bool llvm_cbe_tmp__1008__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1009;
  unsigned long long llvm_cbe_tmp__1010;
  unsigned long long llvm_cbe_tmp__1011;
  unsigned long long llvm_cbe_tmp__1012;
  unsigned long long llvm_cbe_tmp__1013;
  unsigned long long llvm_cbe_tmp__1014;
  unsigned long long llvm_cbe_tmp__1015;
  unsigned long long llvm_cbe_tmp__1016;
  unsigned long long llvm_cbe_tmp__1017;
  unsigned long long llvm_cbe_tmp__1018;

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
  llvm_cbe_tmp__961 = *((&llvm_cbe_tmp__960->field29));
  *(&llvm_cbe_cppVar_621) = (((unsigned char )(bool )(llvm_cbe_tmp__961 == 0ull)));
  llvm_cbe_tmp__962 = *(&llvm_cbe_cppVar_621);
  if ((((((bool )llvm_cbe_tmp__962&1u))&1))) {
    goto llvm_cbe_tmp__1019;
  } else {
    goto llvm_cbe_tmp__1020;
  }

llvm_cbe_tmp__1019:
  llvm_cbe_tmp__963 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_619) = llvm_cbe_tmp__963;
  goto llvm_cbe_tmp__1021;

llvm_cbe_tmp__1020:
  llvm_cbe_tmp__964 = *((&llvm_cbe_tmp__960->field29));
  *(&llvm_cbe_cppVar_624) = (((unsigned char )(bool )(llvm_cbe_tmp__964 == 1ull)));
  llvm_cbe_tmp__965 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__965&1u))&1))) {
    goto llvm_cbe_tmp__1022;
  } else {
    goto llvm_cbe_tmp__1023;
  }

llvm_cbe_tmp__1022:
  llvm_cbe_tmp__966 = *((&llvm_cbe_tmp__960->field15));
  *(&llvm_cbe_cppVar_627) = (((unsigned char )(bool )(llvm_cbe_tmp__966 == 0ull)));
  llvm_cbe_tmp__967 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__967&1u))&1))) {
    goto llvm_cbe_tmp__1024;
  } else {
    llvm_cbe_tmp__970__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1025;
  }

llvm_cbe_tmp__1024:
  llvm_cbe_tmp__968 = *(&llvm_cbe_cppVar_627);
  llvm_cbe_tmp__969 = ((((bool )llvm_cbe_tmp__968&1u))&1);
  llvm_cbe_tmp__970__PHI_TEMPORARY = llvm_cbe_tmp__969;   /* for PHI node */
  goto llvm_cbe_tmp__1025;

llvm_cbe_tmp__1025:
  llvm_cbe_tmp__970 = ((llvm_cbe_tmp__970__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_628) = (((unsigned char )(bool )llvm_cbe_tmp__970));
  llvm_cbe_tmp__971 = *(&llvm_cbe_cppVar_628);
  if ((((((bool )llvm_cbe_tmp__971&1u))&1))) {
    goto llvm_cbe_tmp__1026;
  } else {
    goto llvm_cbe_tmp__1027;
  }

llvm_cbe_tmp__1026:
  llvm_cbe_tmp__972 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_625) = llvm_cbe_tmp__972;
  goto llvm_cbe_tmp__1028;

llvm_cbe_tmp__1027:
  llvm_cbe_tmp__973 = *((&llvm_cbe_tmp__960->field15));
  *(&llvm_cbe_cppVar_631) = (((unsigned char )(bool )(llvm_cbe_tmp__973 == 1ull)));
  llvm_cbe_tmp__974 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__974&1u))&1))) {
    goto llvm_cbe_tmp__1029;
  } else {
    llvm_cbe_tmp__977__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1030;
  }

llvm_cbe_tmp__1029:
  llvm_cbe_tmp__975 = *(&llvm_cbe_cppVar_631);
  llvm_cbe_tmp__976 = ((((bool )llvm_cbe_tmp__975&1u))&1);
  llvm_cbe_tmp__977__PHI_TEMPORARY = llvm_cbe_tmp__976;   /* for PHI node */
  goto llvm_cbe_tmp__1030;

llvm_cbe_tmp__1030:
  llvm_cbe_tmp__977 = ((llvm_cbe_tmp__977__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_632) = (((unsigned char )(bool )llvm_cbe_tmp__977));
  llvm_cbe_tmp__978 = *(&llvm_cbe_cppVar_632);
  if ((((((bool )llvm_cbe_tmp__978&1u))&1))) {
    goto llvm_cbe_tmp__1031;
  } else {
    goto llvm_cbe_tmp__1032;
  }

llvm_cbe_tmp__1031:
  llvm_cbe_tmp__979 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_629) = llvm_cbe_tmp__979;
  goto llvm_cbe_tmp__1033;

llvm_cbe_tmp__1032:
  llvm_cbe_tmp__980 = *((&llvm_cbe_tmp__960->field15));
  *(&llvm_cbe_cppVar_635) = (((unsigned char )(bool )(llvm_cbe_tmp__980 == 2ull)));
  llvm_cbe_tmp__981 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__981&1u))&1))) {
    goto llvm_cbe_tmp__1034;
  } else {
    llvm_cbe_tmp__984__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1035;
  }

llvm_cbe_tmp__1034:
  llvm_cbe_tmp__982 = *(&llvm_cbe_cppVar_635);
  llvm_cbe_tmp__983 = ((((bool )llvm_cbe_tmp__982&1u))&1);
  llvm_cbe_tmp__984__PHI_TEMPORARY = llvm_cbe_tmp__983;   /* for PHI node */
  goto llvm_cbe_tmp__1035;

llvm_cbe_tmp__1035:
  llvm_cbe_tmp__984 = ((llvm_cbe_tmp__984__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_636) = (((unsigned char )(bool )llvm_cbe_tmp__984));
  llvm_cbe_tmp__985 = *(&llvm_cbe_cppVar_636);
  if ((((((bool )llvm_cbe_tmp__985&1u))&1))) {
    goto llvm_cbe_tmp__1036;
  } else {
    goto llvm_cbe_tmp__1037;
  }

llvm_cbe_tmp__1036:
  llvm_cbe_tmp__986 = *((&llvm_cbe_tmp__960->field7));
  *(&llvm_cbe_cppVar_639) = (((unsigned char )(bool )(llvm_cbe_tmp__986 == 0ull)));
  llvm_cbe_tmp__987 = *(&llvm_cbe_cppVar_639);
  if ((((((bool )llvm_cbe_tmp__987&1u))&1))) {
    goto llvm_cbe_tmp__1038;
  } else {
    goto llvm_cbe_tmp__1039;
  }

llvm_cbe_tmp__1038:
  *(&llvm_cbe_cppVar_637) = 0ull;
  goto llvm_cbe_tmp__1040;

llvm_cbe_tmp__1039:
  llvm_cbe_tmp__988 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_637) = llvm_cbe_tmp__988;
  goto llvm_cbe_tmp__1040;

llvm_cbe_tmp__1040:
  llvm_cbe_tmp__989 = *((&llvm_cbe_tmp__960->field7));
  llvm_cbe_tmp__990 = *((&llvm_cbe_tmp__960->field40));
  *(&llvm_cbe_cppVar_641) = ((((signed long long )(((signed long long )llvm_cbe_tmp__989) >> ((signed long long )0ull)))) & llvm_cbe_tmp__990);
  llvm_cbe_tmp__991 = *(&llvm_cbe_cppVar_641);
  llvm_cbe_tmp__992 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__960->field32)), llvm_cbe_tmp__991);
  *(&llvm_cbe_cppVar_642) = llvm_cbe_tmp__992;
  llvm_cbe_tmp__993 = *(&llvm_cbe_cppVar_642);
  llvm_cbe_tmp__994 = _Z10to_int_expl(llvm_cbe_tmp__993);
  *(&llvm_cbe_cppVar_643) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__994));
  llvm_cbe_tmp__995 = *(&llvm_cbe_cppVar_643);
  llvm_cbe_tmp__996 = *((&llvm_cbe_tmp__960->field41));
  *(&llvm_cbe_cppVar_644) = ((((signed long long )(((signed long long )llvm_cbe_tmp__995) >> ((signed long long )0ull)))) & llvm_cbe_tmp__996);
  llvm_cbe_tmp__997 = *(&llvm_cbe_cppVar_644);
  llvm_cbe_tmp__998 = *((&llvm_cbe_tmp__960->field41));
  *(&llvm_cbe_cppVar_645) = (llvm_cbe_tmp__997 & llvm_cbe_tmp__998);
  llvm_cbe_tmp__999 = *(&llvm_cbe_cppVar_637);
  llvm_cbe_tmp__1000 = *(&llvm_cbe_cppVar_645);
  *(&llvm_cbe_cppVar_646) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__999) + ((unsigned long long )llvm_cbe_tmp__1000))));
  llvm_cbe_tmp__1001 = *(&llvm_cbe_cppVar_646);
  llvm_cbe_tmp__1002 = *((&llvm_cbe_tmp__960->field42));
  *(&llvm_cbe_cppVar_646) = (llvm_cbe_tmp__1001 & llvm_cbe_tmp__1002);
  llvm_cbe_tmp__1003 = *(&llvm_cbe_cppVar_646);
  *(&llvm_cbe_cppVar_633) = llvm_cbe_tmp__1003;
  goto llvm_cbe_tmp__1041;

llvm_cbe_tmp__1037:
  llvm_cbe_tmp__1004 = *((&llvm_cbe_tmp__960->field15));
  *(&llvm_cbe_cppVar_649) = (((unsigned char )(bool )(llvm_cbe_tmp__1004 == 3ull)));
  llvm_cbe_tmp__1005 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__1005&1u))&1))) {
    goto llvm_cbe_tmp__1042;
  } else {
    llvm_cbe_tmp__1008__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1043;
  }

llvm_cbe_tmp__1042:
  llvm_cbe_tmp__1006 = *(&llvm_cbe_cppVar_649);
  llvm_cbe_tmp__1007 = ((((bool )llvm_cbe_tmp__1006&1u))&1);
  llvm_cbe_tmp__1008__PHI_TEMPORARY = llvm_cbe_tmp__1007;   /* for PHI node */
  goto llvm_cbe_tmp__1043;

llvm_cbe_tmp__1043:
  llvm_cbe_tmp__1008 = ((llvm_cbe_tmp__1008__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_650) = (((unsigned char )(bool )llvm_cbe_tmp__1008));
  llvm_cbe_tmp__1009 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_647) = llvm_cbe_tmp__1009;
  llvm_cbe_tmp__1010 = *(&llvm_cbe_cppVar_647);
  *(&llvm_cbe_cppVar_633) = llvm_cbe_tmp__1010;
  goto llvm_cbe_tmp__1041;

llvm_cbe_tmp__1041:
  llvm_cbe_tmp__1011 = *(&llvm_cbe_cppVar_633);
  *(&llvm_cbe_cppVar_629) = llvm_cbe_tmp__1011;
  goto llvm_cbe_tmp__1033;

llvm_cbe_tmp__1033:
  llvm_cbe_tmp__1012 = *(&llvm_cbe_cppVar_629);
  *(&llvm_cbe_cppVar_625) = llvm_cbe_tmp__1012;
  goto llvm_cbe_tmp__1028;

llvm_cbe_tmp__1028:
  llvm_cbe_tmp__1013 = *(&llvm_cbe_cppVar_625);
  *(&llvm_cbe_cppVar_622) = llvm_cbe_tmp__1013;
  goto llvm_cbe_tmp__1044;

llvm_cbe_tmp__1023:
  llvm_cbe_tmp__1014 = *((&llvm_cbe_tmp__960->field29));
  *(&llvm_cbe_cppVar_653) = (((unsigned char )(bool )(llvm_cbe_tmp__1014 == 2ull)));
  llvm_cbe_tmp__1015 = *((&llvm_cbe_tmp__960->field24));
  *(&llvm_cbe_cppVar_651) = llvm_cbe_tmp__1015;
  llvm_cbe_tmp__1016 = *(&llvm_cbe_cppVar_651);
  *(&llvm_cbe_cppVar_622) = llvm_cbe_tmp__1016;
  goto llvm_cbe_tmp__1044;

llvm_cbe_tmp__1044:
  llvm_cbe_tmp__1017 = *(&llvm_cbe_cppVar_622);
  *(&llvm_cbe_cppVar_619) = llvm_cbe_tmp__1017;
  goto llvm_cbe_tmp__1021;

llvm_cbe_tmp__1021:
  llvm_cbe_tmp__1018 = *(&llvm_cbe_cppVar_619);
  return llvm_cbe_tmp__1018;
}


unsigned long long _ZN11model_train24cppUpdateFun_train_h_cntElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1045;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1046;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1047;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1048;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1049;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1050;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1051;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1052;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1053;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1054;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1055;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1056;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_656;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_657;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_668;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_669;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_691;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_692;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_698;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_699;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_659;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_661;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_662;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_663;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_665;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_666;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_660;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_658;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_675;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_671;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_672;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_673;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_679;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_680;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_681;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_683;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_684;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_685;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_687;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_688;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_689;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_676;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_677;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_674;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_686;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_682;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_678;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_670;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_694;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_695;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_696;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_693;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_701;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_702;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_703;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_700;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_697;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_690;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_667;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_655;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_664;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1057;
  unsigned long long llvm_cbe_tmp__1058;
  unsigned char llvm_cbe_tmp__1059;
  unsigned long long llvm_cbe_tmp__1060;
  unsigned long long llvm_cbe_tmp__1061;
  unsigned char llvm_cbe_tmp__1062;
  unsigned long long llvm_cbe_tmp__1063;
  unsigned long long llvm_cbe_tmp__1064;
  unsigned long long llvm_cbe_tmp__1065;
  unsigned long long llvm_cbe_tmp__1066;
  unsigned long long llvm_cbe_tmp__1067;
  unsigned char llvm_cbe_tmp__1068;
  unsigned long long llvm_cbe_tmp__1069;
  unsigned long long llvm_cbe_tmp__1070;
  unsigned long long llvm_cbe_tmp__1071;
  unsigned long long llvm_cbe_tmp__1072;
  unsigned long long llvm_cbe_tmp__1073;
  unsigned long long llvm_cbe_tmp__1074;
  unsigned long long llvm_cbe_tmp__1075;
  unsigned long long llvm_cbe_tmp__1076;
  unsigned char llvm_cbe_tmp__1077;
  unsigned long long llvm_cbe_tmp__1078;
  unsigned char llvm_cbe_tmp__1079;
  unsigned char llvm_cbe_tmp__1080;
  bool llvm_cbe_tmp__1081;
  bool llvm_cbe_tmp__1082;
  bool llvm_cbe_tmp__1082__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1083;
  unsigned long long llvm_cbe_tmp__1084;
  unsigned long long llvm_cbe_tmp__1085;
  unsigned char llvm_cbe_tmp__1086;
  unsigned long long llvm_cbe_tmp__1087;
  unsigned long long llvm_cbe_tmp__1088;
  unsigned long long llvm_cbe_tmp__1089;
  unsigned long long llvm_cbe_tmp__1090;
  unsigned long long llvm_cbe_tmp__1091;
  unsigned long long llvm_cbe_tmp__1092;
  unsigned char llvm_cbe_tmp__1093;
  unsigned char llvm_cbe_tmp__1094;
  bool llvm_cbe_tmp__1095;
  bool llvm_cbe_tmp__1096;
  bool llvm_cbe_tmp__1096__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1097;
  unsigned long long llvm_cbe_tmp__1098;
  unsigned long long llvm_cbe_tmp__1099;
  unsigned char llvm_cbe_tmp__1100;
  unsigned char llvm_cbe_tmp__1101;
  bool llvm_cbe_tmp__1102;
  bool llvm_cbe_tmp__1103;
  bool llvm_cbe_tmp__1103__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1104;
  unsigned long long llvm_cbe_tmp__1105;
  unsigned long long llvm_cbe_tmp__1106;
  unsigned char llvm_cbe_tmp__1107;
  unsigned char llvm_cbe_tmp__1108;
  bool llvm_cbe_tmp__1109;
  bool llvm_cbe_tmp__1110;
  bool llvm_cbe_tmp__1110__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1111;
  unsigned long long llvm_cbe_tmp__1112;
  unsigned long long llvm_cbe_tmp__1113;
  unsigned long long llvm_cbe_tmp__1114;
  unsigned long long llvm_cbe_tmp__1115;
  unsigned long long llvm_cbe_tmp__1116;
  unsigned char llvm_cbe_tmp__1117;
  unsigned long long llvm_cbe_tmp__1118;
  unsigned long long llvm_cbe_tmp__1119;
  unsigned char llvm_cbe_tmp__1120;
  unsigned long long llvm_cbe_tmp__1121;
  unsigned long long llvm_cbe_tmp__1122;
  unsigned long long llvm_cbe_tmp__1123;
  unsigned long long llvm_cbe_tmp__1124;
  unsigned long long llvm_cbe_tmp__1125;
  unsigned long long llvm_cbe_tmp__1126;
  unsigned char llvm_cbe_tmp__1127;
  unsigned long long llvm_cbe_tmp__1128;
  unsigned long long llvm_cbe_tmp__1129;
  unsigned char llvm_cbe_tmp__1130;
  unsigned long long llvm_cbe_tmp__1131;
  unsigned long long llvm_cbe_tmp__1132;
  unsigned long long llvm_cbe_tmp__1133;
  unsigned long long llvm_cbe_tmp__1134;
  unsigned long long llvm_cbe_tmp__1135;
  unsigned long long llvm_cbe_tmp__1136;
  unsigned long long llvm_cbe_tmp__1137;
  unsigned long long llvm_cbe_tmp__1138;
  unsigned long long llvm_cbe_tmp__1139;

  *(&llvm_cbe_tmp__1045) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1046) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1047) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1048) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1049) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1050) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1051) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1052) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1053) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1054) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1055) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1056) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1057 = *(&llvm_cbe_tmp__1045);
  llvm_cbe_tmp__1058 = *((&llvm_cbe_tmp__1057->field29));
  *(&llvm_cbe_cppVar_657) = (((unsigned char )(bool )(llvm_cbe_tmp__1058 == 0ull)));
  llvm_cbe_tmp__1059 = *(&llvm_cbe_cppVar_657);
  if ((((((bool )llvm_cbe_tmp__1059&1u))&1))) {
    goto llvm_cbe_tmp__1140;
  } else {
    goto llvm_cbe_tmp__1141;
  }

llvm_cbe_tmp__1140:
  llvm_cbe_tmp__1060 = *((&llvm_cbe_tmp__1057->field30));
  llvm_cbe_tmp__1061 = *((&llvm_cbe_tmp__1057->field14));
  *(&llvm_cbe_cppVar_659) = (((unsigned char )(bool )(llvm_cbe_tmp__1060 == llvm_cbe_tmp__1061)));
  llvm_cbe_tmp__1062 = *(&llvm_cbe_cppVar_659);
  if ((((((bool )llvm_cbe_tmp__1062&1u))&1))) {
    goto llvm_cbe_tmp__1142;
  } else {
    goto llvm_cbe_tmp__1143;
  }

llvm_cbe_tmp__1142:
  llvm_cbe_tmp__1063 = *((&llvm_cbe_tmp__1057->field9));
  *(&llvm_cbe_cppVar_662) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1063) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__1064 = *(&llvm_cbe_cppVar_662);
  llvm_cbe_tmp__1065 = *((&llvm_cbe_tmp__1057->field39));
  *(&llvm_cbe_cppVar_662) = (llvm_cbe_tmp__1064 & llvm_cbe_tmp__1065);
  llvm_cbe_tmp__1066 = *((&llvm_cbe_tmp__1057->field25));
  llvm_cbe_tmp__1067 = *(&llvm_cbe_cppVar_662);
  *(&llvm_cbe_cppVar_663) = (((unsigned char )(bool )(llvm_cbe_tmp__1066 == llvm_cbe_tmp__1067)));
  llvm_cbe_tmp__1068 = *(&llvm_cbe_cppVar_663);
  if ((((((bool )llvm_cbe_tmp__1068&1u))&1))) {
    goto llvm_cbe_tmp__1144;
  } else {
    goto llvm_cbe_tmp__1145;
  }

llvm_cbe_tmp__1144:
  *(&llvm_cbe_cppVar_660) = 0ull;
  goto llvm_cbe_tmp__1146;

llvm_cbe_tmp__1145:
  llvm_cbe_tmp__1069 = *((&llvm_cbe_tmp__1057->field25));
  *(&llvm_cbe_cppVar_666) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1069) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1070 = *(&llvm_cbe_cppVar_666);
  llvm_cbe_tmp__1071 = *((&llvm_cbe_tmp__1057->field39));
  *(&llvm_cbe_cppVar_666) = (llvm_cbe_tmp__1070 & llvm_cbe_tmp__1071);
  llvm_cbe_tmp__1072 = *(&llvm_cbe_cppVar_666);
  *(&llvm_cbe_cppVar_660) = llvm_cbe_tmp__1072;
  goto llvm_cbe_tmp__1146;

llvm_cbe_tmp__1146:
  llvm_cbe_tmp__1073 = *(&llvm_cbe_cppVar_660);
  *(&llvm_cbe_cppVar_658) = llvm_cbe_tmp__1073;
  goto llvm_cbe_tmp__1147;

llvm_cbe_tmp__1143:
  llvm_cbe_tmp__1074 = *((&llvm_cbe_tmp__1057->field25));
  *(&llvm_cbe_cppVar_658) = llvm_cbe_tmp__1074;
  goto llvm_cbe_tmp__1147;

llvm_cbe_tmp__1147:
  llvm_cbe_tmp__1075 = *(&llvm_cbe_cppVar_658);
  *(&llvm_cbe_cppVar_655) = llvm_cbe_tmp__1075;
  goto llvm_cbe_tmp__1148;

llvm_cbe_tmp__1141:
  llvm_cbe_tmp__1076 = *((&llvm_cbe_tmp__1057->field29));
  *(&llvm_cbe_cppVar_669) = (((unsigned char )(bool )(llvm_cbe_tmp__1076 == 1ull)));
  llvm_cbe_tmp__1077 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1077&1u))&1))) {
    goto llvm_cbe_tmp__1149;
  } else {
    goto llvm_cbe_tmp__1150;
  }

llvm_cbe_tmp__1149:
  llvm_cbe_tmp__1078 = *((&llvm_cbe_tmp__1057->field15));
  *(&llvm_cbe_cppVar_672) = (((unsigned char )(bool )(llvm_cbe_tmp__1078 == 0ull)));
  llvm_cbe_tmp__1079 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1079&1u))&1))) {
    goto llvm_cbe_tmp__1151;
  } else {
    llvm_cbe_tmp__1082__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1152;
  }

llvm_cbe_tmp__1151:
  llvm_cbe_tmp__1080 = *(&llvm_cbe_cppVar_672);
  llvm_cbe_tmp__1081 = ((((bool )llvm_cbe_tmp__1080&1u))&1);
  llvm_cbe_tmp__1082__PHI_TEMPORARY = llvm_cbe_tmp__1081;   /* for PHI node */
  goto llvm_cbe_tmp__1152;

llvm_cbe_tmp__1152:
  llvm_cbe_tmp__1082 = ((llvm_cbe_tmp__1082__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_673) = (((unsigned char )(bool )llvm_cbe_tmp__1082));
  llvm_cbe_tmp__1083 = *(&llvm_cbe_cppVar_673);
  if ((((((bool )llvm_cbe_tmp__1083&1u))&1))) {
    goto llvm_cbe_tmp__1153;
  } else {
    goto llvm_cbe_tmp__1154;
  }

llvm_cbe_tmp__1153:
  llvm_cbe_tmp__1084 = *((&llvm_cbe_tmp__1057->field25));
  llvm_cbe_tmp__1085 = *((&llvm_cbe_tmp__1057->field9));
  *(&llvm_cbe_cppVar_675) = (((unsigned char )(bool )(llvm_cbe_tmp__1084 == llvm_cbe_tmp__1085)));
  llvm_cbe_tmp__1086 = *(&llvm_cbe_cppVar_675);
  if ((((((bool )llvm_cbe_tmp__1086&1u))&1))) {
    goto llvm_cbe_tmp__1155;
  } else {
    goto llvm_cbe_tmp__1156;
  }

llvm_cbe_tmp__1155:
  *(&llvm_cbe_cppVar_674) = 0ull;
  goto llvm_cbe_tmp__1157;

llvm_cbe_tmp__1156:
  llvm_cbe_tmp__1087 = *((&llvm_cbe_tmp__1057->field25));
  *(&llvm_cbe_cppVar_677) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1087) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1088 = *(&llvm_cbe_cppVar_677);
  llvm_cbe_tmp__1089 = *((&llvm_cbe_tmp__1057->field39));
  *(&llvm_cbe_cppVar_677) = (llvm_cbe_tmp__1088 & llvm_cbe_tmp__1089);
  llvm_cbe_tmp__1090 = *(&llvm_cbe_cppVar_677);
  *(&llvm_cbe_cppVar_674) = llvm_cbe_tmp__1090;
  goto llvm_cbe_tmp__1157;

llvm_cbe_tmp__1157:
  llvm_cbe_tmp__1091 = *(&llvm_cbe_cppVar_674);
  *(&llvm_cbe_cppVar_670) = llvm_cbe_tmp__1091;
  goto llvm_cbe_tmp__1158;

llvm_cbe_tmp__1154:
  llvm_cbe_tmp__1092 = *((&llvm_cbe_tmp__1057->field15));
  *(&llvm_cbe_cppVar_680) = (((unsigned char )(bool )(llvm_cbe_tmp__1092 == 1ull)));
  llvm_cbe_tmp__1093 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1093&1u))&1))) {
    goto llvm_cbe_tmp__1159;
  } else {
    llvm_cbe_tmp__1096__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1160;
  }

llvm_cbe_tmp__1159:
  llvm_cbe_tmp__1094 = *(&llvm_cbe_cppVar_680);
  llvm_cbe_tmp__1095 = ((((bool )llvm_cbe_tmp__1094&1u))&1);
  llvm_cbe_tmp__1096__PHI_TEMPORARY = llvm_cbe_tmp__1095;   /* for PHI node */
  goto llvm_cbe_tmp__1160;

llvm_cbe_tmp__1160:
  llvm_cbe_tmp__1096 = ((llvm_cbe_tmp__1096__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_681) = (((unsigned char )(bool )llvm_cbe_tmp__1096));
  llvm_cbe_tmp__1097 = *(&llvm_cbe_cppVar_681);
  if ((((((bool )llvm_cbe_tmp__1097&1u))&1))) {
    goto llvm_cbe_tmp__1161;
  } else {
    goto llvm_cbe_tmp__1162;
  }

llvm_cbe_tmp__1161:
  llvm_cbe_tmp__1098 = *((&llvm_cbe_tmp__1057->field25));
  *(&llvm_cbe_cppVar_678) = llvm_cbe_tmp__1098;
  goto llvm_cbe_tmp__1163;

llvm_cbe_tmp__1162:
  llvm_cbe_tmp__1099 = *((&llvm_cbe_tmp__1057->field15));
  *(&llvm_cbe_cppVar_684) = (((unsigned char )(bool )(llvm_cbe_tmp__1099 == 2ull)));
  llvm_cbe_tmp__1100 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1100&1u))&1))) {
    goto llvm_cbe_tmp__1164;
  } else {
    llvm_cbe_tmp__1103__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1165;
  }

llvm_cbe_tmp__1164:
  llvm_cbe_tmp__1101 = *(&llvm_cbe_cppVar_684);
  llvm_cbe_tmp__1102 = ((((bool )llvm_cbe_tmp__1101&1u))&1);
  llvm_cbe_tmp__1103__PHI_TEMPORARY = llvm_cbe_tmp__1102;   /* for PHI node */
  goto llvm_cbe_tmp__1165;

llvm_cbe_tmp__1165:
  llvm_cbe_tmp__1103 = ((llvm_cbe_tmp__1103__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_685) = (((unsigned char )(bool )llvm_cbe_tmp__1103));
  llvm_cbe_tmp__1104 = *(&llvm_cbe_cppVar_685);
  if ((((((bool )llvm_cbe_tmp__1104&1u))&1))) {
    goto llvm_cbe_tmp__1166;
  } else {
    goto llvm_cbe_tmp__1167;
  }

llvm_cbe_tmp__1166:
  llvm_cbe_tmp__1105 = *((&llvm_cbe_tmp__1057->field25));
  *(&llvm_cbe_cppVar_682) = llvm_cbe_tmp__1105;
  goto llvm_cbe_tmp__1168;

llvm_cbe_tmp__1167:
  llvm_cbe_tmp__1106 = *((&llvm_cbe_tmp__1057->field15));
  *(&llvm_cbe_cppVar_688) = (((unsigned char )(bool )(llvm_cbe_tmp__1106 == 3ull)));
  llvm_cbe_tmp__1107 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1107&1u))&1))) {
    goto llvm_cbe_tmp__1169;
  } else {
    llvm_cbe_tmp__1110__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1170;
  }

llvm_cbe_tmp__1169:
  llvm_cbe_tmp__1108 = *(&llvm_cbe_cppVar_688);
  llvm_cbe_tmp__1109 = ((((bool )llvm_cbe_tmp__1108&1u))&1);
  llvm_cbe_tmp__1110__PHI_TEMPORARY = llvm_cbe_tmp__1109;   /* for PHI node */
  goto llvm_cbe_tmp__1170;

llvm_cbe_tmp__1170:
  llvm_cbe_tmp__1110 = ((llvm_cbe_tmp__1110__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_689) = (((unsigned char )(bool )llvm_cbe_tmp__1110));
  llvm_cbe_tmp__1111 = *((&llvm_cbe_tmp__1057->field25));
  *(&llvm_cbe_cppVar_686) = llvm_cbe_tmp__1111;
  llvm_cbe_tmp__1112 = *(&llvm_cbe_cppVar_686);
  *(&llvm_cbe_cppVar_682) = llvm_cbe_tmp__1112;
  goto llvm_cbe_tmp__1168;

llvm_cbe_tmp__1168:
  llvm_cbe_tmp__1113 = *(&llvm_cbe_cppVar_682);
  *(&llvm_cbe_cppVar_678) = llvm_cbe_tmp__1113;
  goto llvm_cbe_tmp__1163;

llvm_cbe_tmp__1163:
  llvm_cbe_tmp__1114 = *(&llvm_cbe_cppVar_678);
  *(&llvm_cbe_cppVar_670) = llvm_cbe_tmp__1114;
  goto llvm_cbe_tmp__1158;

llvm_cbe_tmp__1158:
  llvm_cbe_tmp__1115 = *(&llvm_cbe_cppVar_670);
  *(&llvm_cbe_cppVar_667) = llvm_cbe_tmp__1115;
  goto llvm_cbe_tmp__1171;

llvm_cbe_tmp__1150:
  llvm_cbe_tmp__1116 = *((&llvm_cbe_tmp__1057->field29));
  *(&llvm_cbe_cppVar_692) = (((unsigned char )(bool )(llvm_cbe_tmp__1116 == 3ull)));
  llvm_cbe_tmp__1117 = *(&llvm_cbe_cppVar_692);
  if ((((((bool )llvm_cbe_tmp__1117&1u))&1))) {
    goto llvm_cbe_tmp__1172;
  } else {
    goto llvm_cbe_tmp__1173;
  }

llvm_cbe_tmp__1172:
  llvm_cbe_tmp__1118 = *((&llvm_cbe_tmp__1057->field25));
  llvm_cbe_tmp__1119 = *((&llvm_cbe_tmp__1057->field9));
  *(&llvm_cbe_cppVar_694) = (((unsigned char )(bool )(llvm_cbe_tmp__1118 == llvm_cbe_tmp__1119)));
  llvm_cbe_tmp__1120 = *(&llvm_cbe_cppVar_694);
  if ((((((bool )llvm_cbe_tmp__1120&1u))&1))) {
    goto llvm_cbe_tmp__1174;
  } else {
    goto llvm_cbe_tmp__1175;
  }

llvm_cbe_tmp__1174:
  *(&llvm_cbe_cppVar_693) = 0ull;
  goto llvm_cbe_tmp__1176;

llvm_cbe_tmp__1175:
  llvm_cbe_tmp__1121 = *((&llvm_cbe_tmp__1057->field25));
  *(&llvm_cbe_cppVar_696) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1121) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1122 = *(&llvm_cbe_cppVar_696);
  llvm_cbe_tmp__1123 = *((&llvm_cbe_tmp__1057->field39));
  *(&llvm_cbe_cppVar_696) = (llvm_cbe_tmp__1122 & llvm_cbe_tmp__1123);
  llvm_cbe_tmp__1124 = *(&llvm_cbe_cppVar_696);
  *(&llvm_cbe_cppVar_693) = llvm_cbe_tmp__1124;
  goto llvm_cbe_tmp__1176;

llvm_cbe_tmp__1176:
  llvm_cbe_tmp__1125 = *(&llvm_cbe_cppVar_693);
  *(&llvm_cbe_cppVar_690) = llvm_cbe_tmp__1125;
  goto llvm_cbe_tmp__1177;

llvm_cbe_tmp__1173:
  llvm_cbe_tmp__1126 = *((&llvm_cbe_tmp__1057->field29));
  *(&llvm_cbe_cppVar_699) = (((unsigned char )(bool )(llvm_cbe_tmp__1126 == 2ull)));
  llvm_cbe_tmp__1127 = *(&llvm_cbe_cppVar_699);
  llvm_cbe_tmp__1128 = *((&llvm_cbe_tmp__1057->field25));
  if ((((((bool )llvm_cbe_tmp__1127&1u))&1))) {
    goto llvm_cbe_tmp__1178;
  } else {
    goto llvm_cbe_tmp__1179;
  }

llvm_cbe_tmp__1178:
  llvm_cbe_tmp__1129 = *((&llvm_cbe_tmp__1057->field9));
  *(&llvm_cbe_cppVar_701) = (((unsigned char )(bool )(llvm_cbe_tmp__1128 == llvm_cbe_tmp__1129)));
  llvm_cbe_tmp__1130 = *(&llvm_cbe_cppVar_701);
  if ((((((bool )llvm_cbe_tmp__1130&1u))&1))) {
    goto llvm_cbe_tmp__1180;
  } else {
    goto llvm_cbe_tmp__1181;
  }

llvm_cbe_tmp__1180:
  *(&llvm_cbe_cppVar_700) = 0ull;
  goto llvm_cbe_tmp__1182;

llvm_cbe_tmp__1181:
  llvm_cbe_tmp__1131 = *((&llvm_cbe_tmp__1057->field25));
  *(&llvm_cbe_cppVar_703) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1131) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1132 = *(&llvm_cbe_cppVar_703);
  llvm_cbe_tmp__1133 = *((&llvm_cbe_tmp__1057->field39));
  *(&llvm_cbe_cppVar_703) = (llvm_cbe_tmp__1132 & llvm_cbe_tmp__1133);
  llvm_cbe_tmp__1134 = *(&llvm_cbe_cppVar_703);
  *(&llvm_cbe_cppVar_700) = llvm_cbe_tmp__1134;
  goto llvm_cbe_tmp__1182;

llvm_cbe_tmp__1182:
  llvm_cbe_tmp__1135 = *(&llvm_cbe_cppVar_700);
  *(&llvm_cbe_cppVar_697) = llvm_cbe_tmp__1135;
  goto llvm_cbe_tmp__1183;

llvm_cbe_tmp__1179:
  *(&llvm_cbe_cppVar_697) = llvm_cbe_tmp__1128;
  goto llvm_cbe_tmp__1183;

llvm_cbe_tmp__1183:
  llvm_cbe_tmp__1136 = *(&llvm_cbe_cppVar_697);
  *(&llvm_cbe_cppVar_690) = llvm_cbe_tmp__1136;
  goto llvm_cbe_tmp__1177;

llvm_cbe_tmp__1177:
  llvm_cbe_tmp__1137 = *(&llvm_cbe_cppVar_690);
  *(&llvm_cbe_cppVar_667) = llvm_cbe_tmp__1137;
  goto llvm_cbe_tmp__1171;

llvm_cbe_tmp__1171:
  llvm_cbe_tmp__1138 = *(&llvm_cbe_cppVar_667);
  *(&llvm_cbe_cppVar_655) = llvm_cbe_tmp__1138;
  goto llvm_cbe_tmp__1148;

llvm_cbe_tmp__1148:
  llvm_cbe_tmp__1139 = *(&llvm_cbe_cppVar_655);
  return llvm_cbe_tmp__1139;
}


unsigned long long _ZN11model_train29cppUpdateFun_train_input_doneElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1184;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1185;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1186;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1187;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1188;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1189;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1190;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1191;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1192;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1193;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1194;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1195;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_706;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_707;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_709;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_710;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_712;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_713;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_718;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_715;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_716;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_717;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_714;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_711;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_708;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_705;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1196;
  unsigned long long llvm_cbe_tmp__1197;
  unsigned char llvm_cbe_tmp__1198;
  unsigned long long llvm_cbe_tmp__1199;
  unsigned long long llvm_cbe_tmp__1200;
  unsigned char llvm_cbe_tmp__1201;
  unsigned long long llvm_cbe_tmp__1202;
  unsigned long long llvm_cbe_tmp__1203;
  unsigned char llvm_cbe_tmp__1204;
  unsigned long long llvm_cbe_tmp__1205;
  unsigned long long llvm_cbe_tmp__1206;
  unsigned long long llvm_cbe_tmp__1207;
  unsigned long long llvm_cbe_tmp__1208;
  unsigned char llvm_cbe_tmp__1209;
  unsigned char llvm_cbe_tmp__1210;
  bool llvm_cbe_tmp__1211;
  bool llvm_cbe_tmp__1212;
  bool llvm_cbe_tmp__1212__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1213;
  unsigned long long llvm_cbe_tmp__1214;
  unsigned long long llvm_cbe_tmp__1215;
  unsigned long long llvm_cbe_tmp__1216;
  unsigned long long llvm_cbe_tmp__1217;
  unsigned long long llvm_cbe_tmp__1218;
  unsigned long long llvm_cbe_tmp__1219;

  *(&llvm_cbe_tmp__1184) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1185) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1186) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1187) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1188) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1189) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1190) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1191) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1192) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1193) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1194) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1195) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1196 = *(&llvm_cbe_tmp__1184);
  llvm_cbe_tmp__1197 = *((&llvm_cbe_tmp__1196->field29));
  *(&llvm_cbe_cppVar_707) = (((unsigned char )(bool )(llvm_cbe_tmp__1197 == 0ull)));
  llvm_cbe_tmp__1198 = *(&llvm_cbe_cppVar_707);
  if ((((((bool )llvm_cbe_tmp__1198&1u))&1))) {
    goto llvm_cbe_tmp__1220;
  } else {
    goto llvm_cbe_tmp__1221;
  }

llvm_cbe_tmp__1220:
  llvm_cbe_tmp__1199 = *((&llvm_cbe_tmp__1196->field26));
  *(&llvm_cbe_cppVar_705) = llvm_cbe_tmp__1199;
  goto llvm_cbe_tmp__1222;

llvm_cbe_tmp__1221:
  llvm_cbe_tmp__1200 = *((&llvm_cbe_tmp__1196->field29));
  *(&llvm_cbe_cppVar_710) = (((unsigned char )(bool )(llvm_cbe_tmp__1200 == 1ull)));
  llvm_cbe_tmp__1201 = *(&llvm_cbe_cppVar_710);
  if ((((((bool )llvm_cbe_tmp__1201&1u))&1))) {
    goto llvm_cbe_tmp__1223;
  } else {
    goto llvm_cbe_tmp__1224;
  }

llvm_cbe_tmp__1223:
  llvm_cbe_tmp__1202 = *((&llvm_cbe_tmp__1196->field26));
  *(&llvm_cbe_cppVar_708) = llvm_cbe_tmp__1202;
  goto llvm_cbe_tmp__1225;

llvm_cbe_tmp__1224:
  llvm_cbe_tmp__1203 = *((&llvm_cbe_tmp__1196->field29));
  *(&llvm_cbe_cppVar_713) = (((unsigned char )(bool )(llvm_cbe_tmp__1203 == 2ull)));
  llvm_cbe_tmp__1204 = *(&llvm_cbe_cppVar_713);
  if ((((((bool )llvm_cbe_tmp__1204&1u))&1))) {
    goto llvm_cbe_tmp__1226;
  } else {
    goto llvm_cbe_tmp__1227;
  }

llvm_cbe_tmp__1226:
  llvm_cbe_tmp__1205 = *((&llvm_cbe_tmp__1196->field25));
  llvm_cbe_tmp__1206 = *((&llvm_cbe_tmp__1196->field9));
  *(&llvm_cbe_cppVar_715) = (((unsigned char )(bool )(llvm_cbe_tmp__1205 == llvm_cbe_tmp__1206)));
  llvm_cbe_tmp__1207 = *((&llvm_cbe_tmp__1196->field30));
  llvm_cbe_tmp__1208 = *((&llvm_cbe_tmp__1196->field14));
  *(&llvm_cbe_cppVar_716) = (((unsigned char )(bool )(llvm_cbe_tmp__1207 == llvm_cbe_tmp__1208)));
  llvm_cbe_tmp__1209 = *(&llvm_cbe_cppVar_715);
  if ((((((bool )llvm_cbe_tmp__1209&1u))&1))) {
    goto llvm_cbe_tmp__1228;
  } else {
    llvm_cbe_tmp__1212__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1229;
  }

llvm_cbe_tmp__1228:
  llvm_cbe_tmp__1210 = *(&llvm_cbe_cppVar_716);
  llvm_cbe_tmp__1211 = ((((bool )llvm_cbe_tmp__1210&1u))&1);
  llvm_cbe_tmp__1212__PHI_TEMPORARY = llvm_cbe_tmp__1211;   /* for PHI node */
  goto llvm_cbe_tmp__1229;

llvm_cbe_tmp__1229:
  llvm_cbe_tmp__1212 = ((llvm_cbe_tmp__1212__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_717) = (((unsigned char )(bool )llvm_cbe_tmp__1212));
  llvm_cbe_tmp__1213 = *(&llvm_cbe_cppVar_717);
  if ((((((bool )llvm_cbe_tmp__1213&1u))&1))) {
    goto llvm_cbe_tmp__1230;
  } else {
    goto llvm_cbe_tmp__1231;
  }

llvm_cbe_tmp__1230:
  *(&llvm_cbe_cppVar_714) = 0ull;
  goto llvm_cbe_tmp__1232;

llvm_cbe_tmp__1231:
  llvm_cbe_tmp__1214 = *((&llvm_cbe_tmp__1196->field26));
  *(&llvm_cbe_cppVar_714) = llvm_cbe_tmp__1214;
  goto llvm_cbe_tmp__1232;

llvm_cbe_tmp__1232:
  llvm_cbe_tmp__1215 = *(&llvm_cbe_cppVar_714);
  *(&llvm_cbe_cppVar_711) = llvm_cbe_tmp__1215;
  goto llvm_cbe_tmp__1233;

llvm_cbe_tmp__1227:
  llvm_cbe_tmp__1216 = *((&llvm_cbe_tmp__1196->field26));
  *(&llvm_cbe_cppVar_711) = llvm_cbe_tmp__1216;
  goto llvm_cbe_tmp__1233;

llvm_cbe_tmp__1233:
  llvm_cbe_tmp__1217 = *(&llvm_cbe_cppVar_711);
  *(&llvm_cbe_cppVar_708) = llvm_cbe_tmp__1217;
  goto llvm_cbe_tmp__1225;

llvm_cbe_tmp__1225:
  llvm_cbe_tmp__1218 = *(&llvm_cbe_cppVar_708);
  *(&llvm_cbe_cppVar_705) = llvm_cbe_tmp__1218;
  goto llvm_cbe_tmp__1222;

llvm_cbe_tmp__1222:
  llvm_cbe_tmp__1219 = *(&llvm_cbe_cppVar_705);
  return llvm_cbe_tmp__1219;
}


unsigned long long _ZN11model_train22cppUpdateFun_train_maxElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1234;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1235;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1236;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1237;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1238;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1239;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1240;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1241;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1242;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1243;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1244;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1245;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_721;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_722;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_724;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_725;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_775;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_776;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_742;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_743;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_744;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_731;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_727;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_728;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_729;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_758;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_759;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_760;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_767;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_768;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_769;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_771;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_772;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_773;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_734;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_735;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_733;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_738;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_739;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_740;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_741;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_745;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_746;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_747;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_748;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_749;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_737;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_750;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_752;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_753;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_754;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_755;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_751;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_756;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_732;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_730;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_764;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_762;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_763;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_765;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_761;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_770;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_766;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_757;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_726;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_774;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_723;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_720;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_736;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1246;
  unsigned long long llvm_cbe_tmp__1247;
  unsigned char llvm_cbe_tmp__1248;
  unsigned long long llvm_cbe_tmp__1249;
  unsigned long long llvm_cbe_tmp__1250;
  unsigned char llvm_cbe_tmp__1251;
  unsigned long long llvm_cbe_tmp__1252;
  unsigned char llvm_cbe_tmp__1253;
  unsigned char llvm_cbe_tmp__1254;
  bool llvm_cbe_tmp__1255;
  bool llvm_cbe_tmp__1256;
  bool llvm_cbe_tmp__1256__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1257;
  unsigned long long llvm_cbe_tmp__1258;
  unsigned long long llvm_cbe_tmp__1259;
  unsigned char llvm_cbe_tmp__1260;
  unsigned long long llvm_cbe_tmp__1261;
  unsigned char llvm_cbe_tmp__1262;
  unsigned long long llvm_cbe_tmp__1263;
  unsigned long long llvm_cbe_tmp__1264;
  unsigned long long llvm_cbe_tmp__1265;
  unsigned long long llvm_cbe_tmp__1266;
  unsigned long long llvm_cbe_tmp__1267;
  unsigned long long llvm_cbe_tmp__1268;
  unsigned char llvm_cbe_tmp__1269;
  unsigned long long llvm_cbe_tmp__1270;
  unsigned long long llvm_cbe_tmp__1271;
  unsigned long long llvm_cbe_tmp__1272;
  unsigned long long llvm_cbe_tmp__1273;
  unsigned long long llvm_cbe_tmp__1274;
  unsigned long long llvm_cbe_tmp__1275;
  unsigned long long llvm_cbe_tmp__1276;
  unsigned long long llvm_cbe_tmp__1277;
  unsigned long long llvm_cbe_tmp__1278;
  unsigned long long llvm_cbe_tmp__1279;
  unsigned long long llvm_cbe_tmp__1280;
  unsigned long long llvm_cbe_tmp__1281;
  unsigned long long llvm_cbe_tmp__1282;
  unsigned long long llvm_cbe_tmp__1283;
  unsigned long long llvm_cbe_tmp__1284;
  unsigned long long llvm_cbe_tmp__1285;
  unsigned long long llvm_cbe_tmp__1286;
  unsigned long long llvm_cbe_tmp__1286__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1287;
  unsigned long long llvm_cbe_tmp__1288;
  unsigned long long llvm_cbe_tmp__1289;
  unsigned long long llvm_cbe_tmp__1290;
  unsigned long long llvm_cbe_tmp__1291;
  unsigned long long llvm_cbe_tmp__1292;
  unsigned long long llvm_cbe_tmp__1293;
  unsigned long long llvm_cbe_tmp__1294;
  unsigned long long llvm_cbe_tmp__1295;
  unsigned long long llvm_cbe_tmp__1296;
  unsigned long long llvm_cbe_tmp__1297;
  unsigned long long llvm_cbe_tmp__1298;
  unsigned char llvm_cbe_tmp__1299;
  unsigned long long llvm_cbe_tmp__1300;
  unsigned long long llvm_cbe_tmp__1301;
  unsigned long long llvm_cbe_tmp__1302;
  unsigned long long llvm_cbe_tmp__1303;
  unsigned long long llvm_cbe_tmp__1304;
  unsigned long long llvm_cbe_tmp__1305;
  unsigned long long llvm_cbe_tmp__1306;
  unsigned long long llvm_cbe_tmp__1307;
  unsigned long long llvm_cbe_tmp__1307__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1308;
  unsigned long long llvm_cbe_tmp__1309;
  unsigned long long llvm_cbe_tmp__1310;
  unsigned long long llvm_cbe_tmp__1311;
  unsigned long long llvm_cbe_tmp__1312;
  unsigned long long llvm_cbe_tmp__1313;
  unsigned long long llvm_cbe_tmp__1313__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1314;
  unsigned long long llvm_cbe_tmp__1315;
  unsigned long long llvm_cbe_tmp__1316;
  unsigned long long llvm_cbe_tmp__1317;
  unsigned long long llvm_cbe_tmp__1318;
  unsigned long long llvm_cbe_tmp__1319;
  unsigned long long llvm_cbe_tmp__1320;
  unsigned char llvm_cbe_tmp__1321;
  unsigned char llvm_cbe_tmp__1322;
  bool llvm_cbe_tmp__1323;
  bool llvm_cbe_tmp__1324;
  bool llvm_cbe_tmp__1324__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1325;
  unsigned long long llvm_cbe_tmp__1326;
  unsigned char llvm_cbe_tmp__1327;
  unsigned long long llvm_cbe_tmp__1328;
  unsigned long long llvm_cbe_tmp__1329;
  unsigned long long llvm_cbe_tmp__1330;
  unsigned long long llvm_cbe_tmp__1331;
  unsigned long long llvm_cbe_tmp__1332;
  unsigned long long llvm_cbe_tmp__1333;
  unsigned char llvm_cbe_tmp__1334;
  unsigned char llvm_cbe_tmp__1335;
  bool llvm_cbe_tmp__1336;
  bool llvm_cbe_tmp__1337;
  bool llvm_cbe_tmp__1337__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1338;
  unsigned long long llvm_cbe_tmp__1339;
  unsigned long long llvm_cbe_tmp__1340;
  unsigned char llvm_cbe_tmp__1341;
  unsigned char llvm_cbe_tmp__1342;
  bool llvm_cbe_tmp__1343;
  bool llvm_cbe_tmp__1344;
  bool llvm_cbe_tmp__1344__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1345;
  unsigned long long llvm_cbe_tmp__1346;
  unsigned long long llvm_cbe_tmp__1347;
  unsigned long long llvm_cbe_tmp__1348;
  unsigned long long llvm_cbe_tmp__1349;
  unsigned long long llvm_cbe_tmp__1350;
  unsigned long long llvm_cbe_tmp__1351;
  unsigned long long llvm_cbe_tmp__1352;
  unsigned long long llvm_cbe_tmp__1353;
  unsigned long long llvm_cbe_tmp__1354;

  *(&llvm_cbe_tmp__1234) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1235) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1236) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1237) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1238) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1239) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1240) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1241) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1242) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1243) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1244) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1245) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1246 = *(&llvm_cbe_tmp__1234);
  llvm_cbe_tmp__1247 = *((&llvm_cbe_tmp__1246->field29));
  *(&llvm_cbe_cppVar_722) = (((unsigned char )(bool )(llvm_cbe_tmp__1247 == 0ull)));
  llvm_cbe_tmp__1248 = *(&llvm_cbe_cppVar_722);
  if ((((((bool )llvm_cbe_tmp__1248&1u))&1))) {
    goto llvm_cbe_tmp__1355;
  } else {
    goto llvm_cbe_tmp__1356;
  }

llvm_cbe_tmp__1355:
  llvm_cbe_tmp__1249 = *((&llvm_cbe_tmp__1246->field27));
  *(&llvm_cbe_cppVar_720) = llvm_cbe_tmp__1249;
  goto llvm_cbe_tmp__1357;

llvm_cbe_tmp__1356:
  llvm_cbe_tmp__1250 = *((&llvm_cbe_tmp__1246->field29));
  *(&llvm_cbe_cppVar_725) = (((unsigned char )(bool )(llvm_cbe_tmp__1250 == 1ull)));
  llvm_cbe_tmp__1251 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1251&1u))&1))) {
    goto llvm_cbe_tmp__1358;
  } else {
    goto llvm_cbe_tmp__1359;
  }

llvm_cbe_tmp__1358:
  llvm_cbe_tmp__1252 = *((&llvm_cbe_tmp__1246->field15));
  *(&llvm_cbe_cppVar_728) = (((unsigned char )(bool )(llvm_cbe_tmp__1252 == 0ull)));
  llvm_cbe_tmp__1253 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1253&1u))&1))) {
    goto llvm_cbe_tmp__1360;
  } else {
    llvm_cbe_tmp__1256__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1361;
  }

llvm_cbe_tmp__1360:
  llvm_cbe_tmp__1254 = *(&llvm_cbe_cppVar_728);
  llvm_cbe_tmp__1255 = ((((bool )llvm_cbe_tmp__1254&1u))&1);
  llvm_cbe_tmp__1256__PHI_TEMPORARY = llvm_cbe_tmp__1255;   /* for PHI node */
  goto llvm_cbe_tmp__1361;

llvm_cbe_tmp__1361:
  llvm_cbe_tmp__1256 = ((llvm_cbe_tmp__1256__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_729) = (((unsigned char )(bool )llvm_cbe_tmp__1256));
  llvm_cbe_tmp__1257 = *(&llvm_cbe_cppVar_729);
  if ((((((bool )llvm_cbe_tmp__1257&1u))&1))) {
    goto llvm_cbe_tmp__1362;
  } else {
    goto llvm_cbe_tmp__1363;
  }

llvm_cbe_tmp__1362:
  llvm_cbe_tmp__1258 = *((&llvm_cbe_tmp__1246->field25));
  llvm_cbe_tmp__1259 = *((&llvm_cbe_tmp__1246->field9));
  *(&llvm_cbe_cppVar_731) = (((unsigned char )(bool )(llvm_cbe_tmp__1258 == llvm_cbe_tmp__1259)));
  llvm_cbe_tmp__1260 = *(&llvm_cbe_cppVar_731);
  if ((((((bool )llvm_cbe_tmp__1260&1u))&1))) {
    goto llvm_cbe_tmp__1364;
  } else {
    goto llvm_cbe_tmp__1365;
  }

llvm_cbe_tmp__1364:
  llvm_cbe_tmp__1261 = *((&llvm_cbe_tmp__1246->field25));
  *(&llvm_cbe_cppVar_735) = (((unsigned char )(bool )(llvm_cbe_tmp__1261 == 0ull)));
  llvm_cbe_tmp__1262 = *(&llvm_cbe_cppVar_735);
  if ((((((bool )llvm_cbe_tmp__1262&1u))&1))) {
    goto llvm_cbe_tmp__1366;
  } else {
    goto llvm_cbe_tmp__1367;
  }

llvm_cbe_tmp__1366:
  *(&llvm_cbe_cppVar_733) = 0ull;
  goto llvm_cbe_tmp__1368;

llvm_cbe_tmp__1367:
  llvm_cbe_tmp__1263 = *((&llvm_cbe_tmp__1246->field28));
  *(&llvm_cbe_cppVar_733) = llvm_cbe_tmp__1263;
  goto llvm_cbe_tmp__1368;

llvm_cbe_tmp__1368:
  llvm_cbe_tmp__1264 = *((&llvm_cbe_tmp__1246->field25));
  llvm_cbe_tmp__1265 = *((&llvm_cbe_tmp__1246->field43));
  *(&llvm_cbe_cppVar_738) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1264) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1265);
  llvm_cbe_tmp__1266 = *(&llvm_cbe_cppVar_738);
  llvm_cbe_tmp__1267 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__1246->field4)), llvm_cbe_tmp__1266);
  *(&llvm_cbe_cppVar_739) = llvm_cbe_tmp__1267;
  llvm_cbe_tmp__1268 = *(&llvm_cbe_cppVar_739);
  *(&llvm_cbe_cppVar_741) = (((unsigned char )(bool )(llvm_cbe_tmp__1268 == 1ull)));
  llvm_cbe_tmp__1269 = *(&llvm_cbe_cppVar_741);
  if ((((((bool )llvm_cbe_tmp__1269&1u))&1))) {
    goto llvm_cbe_tmp__1369;
  } else {
    goto llvm_cbe_tmp__1370;
  }

llvm_cbe_tmp__1369:
  llvm_cbe_tmp__1270 = *((&llvm_cbe_tmp__1246->field30));
  *(&llvm_cbe_cppVar_743) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__1270))));
  llvm_cbe_tmp__1271 = *(&llvm_cbe_cppVar_743);
  llvm_cbe_tmp__1272 = *((&llvm_cbe_tmp__1246->field39));
  *(&llvm_cbe_cppVar_743) = (llvm_cbe_tmp__1271 & llvm_cbe_tmp__1272);
  llvm_cbe_tmp__1273 = *(&llvm_cbe_cppVar_743);
  llvm_cbe_tmp__1274 = *((&llvm_cbe_tmp__1246->field25));
  *(&llvm_cbe_cppVar_744) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1273) + ((unsigned long long )llvm_cbe_tmp__1274))));
  llvm_cbe_tmp__1275 = *(&llvm_cbe_cppVar_744);
  llvm_cbe_tmp__1276 = *((&llvm_cbe_tmp__1246->field39));
  *(&llvm_cbe_cppVar_744) = (llvm_cbe_tmp__1275 & llvm_cbe_tmp__1276);
  llvm_cbe_tmp__1277 = *(&llvm_cbe_cppVar_744);
  llvm_cbe_tmp__1278 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1246->field3)), llvm_cbe_tmp__1277);
  *(&llvm_cbe_cppVar_745) = llvm_cbe_tmp__1278;
  llvm_cbe_tmp__1279 = *(&llvm_cbe_cppVar_745);
  llvm_cbe_tmp__1280 = *((&llvm_cbe_tmp__1246->field43));
  *(&llvm_cbe_cppVar_746) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1279) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1280);
  llvm_cbe_tmp__1281 = *(&llvm_cbe_cppVar_746);
  llvm_cbe_tmp__1282 = *((&llvm_cbe_tmp__1246->field47));
  llvm_cbe_tmp__1283 = *(&llvm_cbe_cppVar_746);
  if (((llvm_cbe_tmp__1281 & llvm_cbe_tmp__1282) != 0ull)) {
    goto llvm_cbe_tmp__1371;
  } else {
    llvm_cbe_tmp__1286__PHI_TEMPORARY = llvm_cbe_tmp__1283;   /* for PHI node */
    goto llvm_cbe_tmp__1372;
  }

llvm_cbe_tmp__1371:
  llvm_cbe_tmp__1284 = *((&llvm_cbe_tmp__1246->field49));
  llvm_cbe_tmp__1285 = llvm_cbe_tmp__1283 | llvm_cbe_tmp__1284;
  llvm_cbe_tmp__1286__PHI_TEMPORARY = llvm_cbe_tmp__1285;   /* for PHI node */
  goto llvm_cbe_tmp__1372;

llvm_cbe_tmp__1372:
  llvm_cbe_tmp__1286 = llvm_cbe_tmp__1286__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_747) = llvm_cbe_tmp__1286;
  llvm_cbe_tmp__1287 = *(&llvm_cbe_cppVar_745);
  llvm_cbe_tmp__1288 = *((&llvm_cbe_tmp__1246->field38));
  *(&llvm_cbe_cppVar_748) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1287) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1288);
  llvm_cbe_tmp__1289 = *(&llvm_cbe_cppVar_747);
  llvm_cbe_tmp__1290 = *(&llvm_cbe_cppVar_748);
  *(&llvm_cbe_cppVar_749) = ((llvm_cbe_tmp__1289 << 1ull) | llvm_cbe_tmp__1290);
  llvm_cbe_tmp__1291 = *(&llvm_cbe_cppVar_749);
  llvm_cbe_tmp__1292 = *((&llvm_cbe_tmp__1246->field39));
  *(&llvm_cbe_cppVar_749) = (llvm_cbe_tmp__1291 & llvm_cbe_tmp__1292);
  llvm_cbe_tmp__1293 = *(&llvm_cbe_cppVar_749);
  *(&llvm_cbe_cppVar_737) = llvm_cbe_tmp__1293;
  goto llvm_cbe_tmp__1373;

llvm_cbe_tmp__1370:
  *(&llvm_cbe_cppVar_737) = 0ull;
  goto llvm_cbe_tmp__1373;

llvm_cbe_tmp__1373:
  llvm_cbe_tmp__1294 = *(&llvm_cbe_cppVar_733);
  llvm_cbe_tmp__1295 = *(&llvm_cbe_cppVar_737);
  *(&llvm_cbe_cppVar_750) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1294) + ((unsigned long long )llvm_cbe_tmp__1295))));
  llvm_cbe_tmp__1296 = *(&llvm_cbe_cppVar_750);
  llvm_cbe_tmp__1297 = *((&llvm_cbe_tmp__1246->field39));
  *(&llvm_cbe_cppVar_750) = (llvm_cbe_tmp__1296 & llvm_cbe_tmp__1297);
  llvm_cbe_tmp__1298 = *((&llvm_cbe_tmp__1246->field7));
  *(&llvm_cbe_cppVar_753) = (((unsigned char )(bool )(llvm_cbe_tmp__1298 == 0ull)));
  llvm_cbe_tmp__1299 = *(&llvm_cbe_cppVar_753);
  if ((((((bool )llvm_cbe_tmp__1299&1u))&1))) {
    goto llvm_cbe_tmp__1374;
  } else {
    goto llvm_cbe_tmp__1375;
  }

llvm_cbe_tmp__1374:
  *(&llvm_cbe_cppVar_755) = 18446744073709550616ull;
  llvm_cbe_tmp__1300 = *(&llvm_cbe_cppVar_755);
  *(&llvm_cbe_cppVar_751) = llvm_cbe_tmp__1300;
  goto llvm_cbe_tmp__1376;

llvm_cbe_tmp__1375:
  llvm_cbe_tmp__1301 = *((&llvm_cbe_tmp__1246->field27));
  *(&llvm_cbe_cppVar_751) = llvm_cbe_tmp__1301;
  goto llvm_cbe_tmp__1376;

llvm_cbe_tmp__1376:
  llvm_cbe_tmp__1302 = *(&llvm_cbe_cppVar_750);
  llvm_cbe_tmp__1303 = *((&llvm_cbe_tmp__1246->field46));
  llvm_cbe_tmp__1304 = *(&llvm_cbe_cppVar_750);
  if (((llvm_cbe_tmp__1302 & llvm_cbe_tmp__1303) != 0ull)) {
    goto llvm_cbe_tmp__1377;
  } else {
    llvm_cbe_tmp__1307__PHI_TEMPORARY = llvm_cbe_tmp__1304;   /* for PHI node */
    goto llvm_cbe_tmp__1378;
  }

llvm_cbe_tmp__1377:
  llvm_cbe_tmp__1305 = *((&llvm_cbe_tmp__1246->field48));
  llvm_cbe_tmp__1306 = llvm_cbe_tmp__1304 | llvm_cbe_tmp__1305;
  llvm_cbe_tmp__1307__PHI_TEMPORARY = llvm_cbe_tmp__1306;   /* for PHI node */
  goto llvm_cbe_tmp__1378;

llvm_cbe_tmp__1378:
  llvm_cbe_tmp__1307 = llvm_cbe_tmp__1307__PHI_TEMPORARY;
  llvm_cbe_tmp__1308 = *(&llvm_cbe_cppVar_751);
  llvm_cbe_tmp__1309 = *((&llvm_cbe_tmp__1246->field46));
  llvm_cbe_tmp__1310 = *(&llvm_cbe_cppVar_751);
  if (((llvm_cbe_tmp__1308 & llvm_cbe_tmp__1309) != 0ull)) {
    goto llvm_cbe_tmp__1379;
  } else {
    llvm_cbe_tmp__1313__PHI_TEMPORARY = llvm_cbe_tmp__1310;   /* for PHI node */
    goto llvm_cbe_tmp__1380;
  }

llvm_cbe_tmp__1379:
  llvm_cbe_tmp__1311 = *((&llvm_cbe_tmp__1246->field48));
  llvm_cbe_tmp__1312 = llvm_cbe_tmp__1310 | llvm_cbe_tmp__1311;
  llvm_cbe_tmp__1313__PHI_TEMPORARY = llvm_cbe_tmp__1312;   /* for PHI node */
  goto llvm_cbe_tmp__1380;

llvm_cbe_tmp__1380:
  llvm_cbe_tmp__1313 = llvm_cbe_tmp__1313__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_756) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1307) > ((signed long long )llvm_cbe_tmp__1313))));
  llvm_cbe_tmp__1314 = *(&llvm_cbe_cppVar_756);
  if ((((((bool )llvm_cbe_tmp__1314&1u))&1))) {
    goto llvm_cbe_tmp__1381;
  } else {
    goto llvm_cbe_tmp__1382;
  }

llvm_cbe_tmp__1381:
  llvm_cbe_tmp__1315 = *(&llvm_cbe_cppVar_750);
  *(&llvm_cbe_cppVar_732) = llvm_cbe_tmp__1315;
  goto llvm_cbe_tmp__1383;

llvm_cbe_tmp__1382:
  llvm_cbe_tmp__1316 = *(&llvm_cbe_cppVar_751);
  *(&llvm_cbe_cppVar_732) = llvm_cbe_tmp__1316;
  goto llvm_cbe_tmp__1383;

llvm_cbe_tmp__1383:
  llvm_cbe_tmp__1317 = *(&llvm_cbe_cppVar_732);
  *(&llvm_cbe_cppVar_730) = llvm_cbe_tmp__1317;
  goto llvm_cbe_tmp__1384;

llvm_cbe_tmp__1365:
  llvm_cbe_tmp__1318 = *((&llvm_cbe_tmp__1246->field27));
  *(&llvm_cbe_cppVar_730) = llvm_cbe_tmp__1318;
  goto llvm_cbe_tmp__1384;

llvm_cbe_tmp__1384:
  llvm_cbe_tmp__1319 = *(&llvm_cbe_cppVar_730);
  *(&llvm_cbe_cppVar_726) = llvm_cbe_tmp__1319;
  goto llvm_cbe_tmp__1385;

llvm_cbe_tmp__1363:
  llvm_cbe_tmp__1320 = *((&llvm_cbe_tmp__1246->field15));
  *(&llvm_cbe_cppVar_759) = (((unsigned char )(bool )(llvm_cbe_tmp__1320 == 1ull)));
  llvm_cbe_tmp__1321 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1321&1u))&1))) {
    goto llvm_cbe_tmp__1386;
  } else {
    llvm_cbe_tmp__1324__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1387;
  }

llvm_cbe_tmp__1386:
  llvm_cbe_tmp__1322 = *(&llvm_cbe_cppVar_759);
  llvm_cbe_tmp__1323 = ((((bool )llvm_cbe_tmp__1322&1u))&1);
  llvm_cbe_tmp__1324__PHI_TEMPORARY = llvm_cbe_tmp__1323;   /* for PHI node */
  goto llvm_cbe_tmp__1387;

llvm_cbe_tmp__1387:
  llvm_cbe_tmp__1324 = ((llvm_cbe_tmp__1324__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_760) = (((unsigned char )(bool )llvm_cbe_tmp__1324));
  llvm_cbe_tmp__1325 = *(&llvm_cbe_cppVar_760);
  if ((((((bool )llvm_cbe_tmp__1325&1u))&1))) {
    goto llvm_cbe_tmp__1388;
  } else {
    goto llvm_cbe_tmp__1389;
  }

llvm_cbe_tmp__1388:
  llvm_cbe_tmp__1326 = *((&llvm_cbe_tmp__1246->field7));
  *(&llvm_cbe_cppVar_763) = (((unsigned char )(bool )(llvm_cbe_tmp__1326 == 0ull)));
  llvm_cbe_tmp__1327 = *(&llvm_cbe_cppVar_763);
  llvm_cbe_tmp__1328 = *((&llvm_cbe_tmp__1246->field27));
  if ((((((bool )llvm_cbe_tmp__1327&1u))&1))) {
    goto llvm_cbe_tmp__1390;
  } else {
    goto llvm_cbe_tmp__1391;
  }

llvm_cbe_tmp__1390:
  *(&llvm_cbe_cppVar_765) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1328) - ((unsigned long long )62ull))));
  llvm_cbe_tmp__1329 = *(&llvm_cbe_cppVar_765);
  llvm_cbe_tmp__1330 = *((&llvm_cbe_tmp__1246->field39));
  *(&llvm_cbe_cppVar_765) = (llvm_cbe_tmp__1329 & llvm_cbe_tmp__1330);
  llvm_cbe_tmp__1331 = *(&llvm_cbe_cppVar_765);
  *(&llvm_cbe_cppVar_761) = llvm_cbe_tmp__1331;
  goto llvm_cbe_tmp__1392;

llvm_cbe_tmp__1391:
  *(&llvm_cbe_cppVar_761) = llvm_cbe_tmp__1328;
  goto llvm_cbe_tmp__1392;

llvm_cbe_tmp__1392:
  llvm_cbe_tmp__1332 = *(&llvm_cbe_cppVar_761);
  *(&llvm_cbe_cppVar_757) = llvm_cbe_tmp__1332;
  goto llvm_cbe_tmp__1393;

llvm_cbe_tmp__1389:
  llvm_cbe_tmp__1333 = *((&llvm_cbe_tmp__1246->field15));
  *(&llvm_cbe_cppVar_768) = (((unsigned char )(bool )(llvm_cbe_tmp__1333 == 2ull)));
  llvm_cbe_tmp__1334 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1334&1u))&1))) {
    goto llvm_cbe_tmp__1394;
  } else {
    llvm_cbe_tmp__1337__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1395;
  }

llvm_cbe_tmp__1394:
  llvm_cbe_tmp__1335 = *(&llvm_cbe_cppVar_768);
  llvm_cbe_tmp__1336 = ((((bool )llvm_cbe_tmp__1335&1u))&1);
  llvm_cbe_tmp__1337__PHI_TEMPORARY = llvm_cbe_tmp__1336;   /* for PHI node */
  goto llvm_cbe_tmp__1395;

llvm_cbe_tmp__1395:
  llvm_cbe_tmp__1337 = ((llvm_cbe_tmp__1337__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_769) = (((unsigned char )(bool )llvm_cbe_tmp__1337));
  llvm_cbe_tmp__1338 = *(&llvm_cbe_cppVar_769);
  if ((((((bool )llvm_cbe_tmp__1338&1u))&1))) {
    goto llvm_cbe_tmp__1396;
  } else {
    goto llvm_cbe_tmp__1397;
  }

llvm_cbe_tmp__1396:
  llvm_cbe_tmp__1339 = *((&llvm_cbe_tmp__1246->field27));
  *(&llvm_cbe_cppVar_766) = llvm_cbe_tmp__1339;
  goto llvm_cbe_tmp__1398;

llvm_cbe_tmp__1397:
  llvm_cbe_tmp__1340 = *((&llvm_cbe_tmp__1246->field15));
  *(&llvm_cbe_cppVar_772) = (((unsigned char )(bool )(llvm_cbe_tmp__1340 == 3ull)));
  llvm_cbe_tmp__1341 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1341&1u))&1))) {
    goto llvm_cbe_tmp__1399;
  } else {
    llvm_cbe_tmp__1344__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1400;
  }

llvm_cbe_tmp__1399:
  llvm_cbe_tmp__1342 = *(&llvm_cbe_cppVar_772);
  llvm_cbe_tmp__1343 = ((((bool )llvm_cbe_tmp__1342&1u))&1);
  llvm_cbe_tmp__1344__PHI_TEMPORARY = llvm_cbe_tmp__1343;   /* for PHI node */
  goto llvm_cbe_tmp__1400;

llvm_cbe_tmp__1400:
  llvm_cbe_tmp__1344 = ((llvm_cbe_tmp__1344__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_773) = (((unsigned char )(bool )llvm_cbe_tmp__1344));
  llvm_cbe_tmp__1345 = *((&llvm_cbe_tmp__1246->field27));
  *(&llvm_cbe_cppVar_770) = llvm_cbe_tmp__1345;
  llvm_cbe_tmp__1346 = *(&llvm_cbe_cppVar_770);
  *(&llvm_cbe_cppVar_766) = llvm_cbe_tmp__1346;
  goto llvm_cbe_tmp__1398;

llvm_cbe_tmp__1398:
  llvm_cbe_tmp__1347 = *(&llvm_cbe_cppVar_766);
  *(&llvm_cbe_cppVar_757) = llvm_cbe_tmp__1347;
  goto llvm_cbe_tmp__1393;

llvm_cbe_tmp__1393:
  llvm_cbe_tmp__1348 = *(&llvm_cbe_cppVar_757);
  *(&llvm_cbe_cppVar_726) = llvm_cbe_tmp__1348;
  goto llvm_cbe_tmp__1385;

llvm_cbe_tmp__1385:
  llvm_cbe_tmp__1349 = *(&llvm_cbe_cppVar_726);
  *(&llvm_cbe_cppVar_723) = llvm_cbe_tmp__1349;
  goto llvm_cbe_tmp__1401;

llvm_cbe_tmp__1359:
  llvm_cbe_tmp__1350 = *((&llvm_cbe_tmp__1246->field29));
  *(&llvm_cbe_cppVar_776) = (((unsigned char )(bool )(llvm_cbe_tmp__1350 == 2ull)));
  llvm_cbe_tmp__1351 = *((&llvm_cbe_tmp__1246->field27));
  *(&llvm_cbe_cppVar_774) = llvm_cbe_tmp__1351;
  llvm_cbe_tmp__1352 = *(&llvm_cbe_cppVar_774);
  *(&llvm_cbe_cppVar_723) = llvm_cbe_tmp__1352;
  goto llvm_cbe_tmp__1401;

llvm_cbe_tmp__1401:
  llvm_cbe_tmp__1353 = *(&llvm_cbe_cppVar_723);
  *(&llvm_cbe_cppVar_720) = llvm_cbe_tmp__1353;
  goto llvm_cbe_tmp__1357;

llvm_cbe_tmp__1357:
  llvm_cbe_tmp__1354 = *(&llvm_cbe_cppVar_720);
  return llvm_cbe_tmp__1354;
}


unsigned long long _ZN11model_train22cppUpdateFun_train_sumElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1402;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1403;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1404;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1405;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1406;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1407;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1408;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1409;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1410;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1411;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1412;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1413;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_779;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_780;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_801;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_802;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_835;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_836;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_790;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_791;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_792;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_782;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_783;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_784;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_781;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_786;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_787;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_788;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_789;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_793;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_794;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_795;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_796;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_797;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_798;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_785;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_799;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_804;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_805;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_806;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_823;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_824;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_825;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_827;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_828;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_829;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_831;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_832;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_833;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_808;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_809;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_807;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_812;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_813;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_814;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_815;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_816;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_817;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_818;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_819;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_820;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_811;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_821;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_830;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_826;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_822;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_803;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_834;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_800;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_778;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_810;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1414;
  unsigned long long llvm_cbe_tmp__1415;
  unsigned char llvm_cbe_tmp__1416;
  unsigned long long llvm_cbe_tmp__1417;
  unsigned char llvm_cbe_tmp__1418;
  unsigned long long llvm_cbe_tmp__1419;
  unsigned long long llvm_cbe_tmp__1420;
  unsigned long long llvm_cbe_tmp__1421;
  unsigned long long llvm_cbe_tmp__1422;
  unsigned long long llvm_cbe_tmp__1423;
  unsigned long long llvm_cbe_tmp__1424;
  unsigned char llvm_cbe_tmp__1425;
  unsigned long long llvm_cbe_tmp__1426;
  unsigned long long llvm_cbe_tmp__1427;
  unsigned long long llvm_cbe_tmp__1428;
  unsigned long long llvm_cbe_tmp__1429;
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
  unsigned long long llvm_cbe_tmp__1440;
  unsigned long long llvm_cbe_tmp__1441;
  unsigned long long llvm_cbe_tmp__1442;
  unsigned long long llvm_cbe_tmp__1442__PHI_TEMPORARY;
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
  unsigned long long llvm_cbe_tmp__1453;
  unsigned long long llvm_cbe_tmp__1454;
  unsigned long long llvm_cbe_tmp__1455;
  unsigned char llvm_cbe_tmp__1456;
  unsigned long long llvm_cbe_tmp__1457;
  unsigned char llvm_cbe_tmp__1458;
  unsigned char llvm_cbe_tmp__1459;
  bool llvm_cbe_tmp__1460;
  bool llvm_cbe_tmp__1461;
  bool llvm_cbe_tmp__1461__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1462;
  unsigned long long llvm_cbe_tmp__1463;
  unsigned char llvm_cbe_tmp__1464;
  unsigned long long llvm_cbe_tmp__1465;
  unsigned long long llvm_cbe_tmp__1466;
  unsigned long long llvm_cbe_tmp__1467;
  unsigned long long llvm_cbe_tmp__1468;
  unsigned long long llvm_cbe_tmp__1469;
  unsigned long long llvm_cbe_tmp__1470;
  unsigned char llvm_cbe_tmp__1471;
  unsigned long long llvm_cbe_tmp__1472;
  unsigned long long llvm_cbe_tmp__1473;
  unsigned long long llvm_cbe_tmp__1474;
  unsigned long long llvm_cbe_tmp__1475;
  unsigned long long llvm_cbe_tmp__1476;
  unsigned long long llvm_cbe_tmp__1477;
  unsigned long long llvm_cbe_tmp__1478;
  unsigned long long llvm_cbe_tmp__1479;
  unsigned long long llvm_cbe_tmp__1480;
  unsigned long long llvm_cbe_tmp__1481;
  unsigned long long llvm_cbe_tmp__1481__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1482;
  unsigned long long llvm_cbe_tmp__1483;
  unsigned long long llvm_cbe_tmp__1484;
  unsigned long long llvm_cbe_tmp__1485;
  unsigned long long llvm_cbe_tmp__1486;
  unsigned long long llvm_cbe_tmp__1487;
  unsigned long long llvm_cbe_tmp__1488;
  unsigned long long llvm_cbe_tmp__1489;
  unsigned long long llvm_cbe_tmp__1490;
  unsigned long long llvm_cbe_tmp__1491;
  unsigned long long llvm_cbe_tmp__1492;
  unsigned long long llvm_cbe_tmp__1493;
  unsigned long long llvm_cbe_tmp__1494;
  unsigned char llvm_cbe_tmp__1495;
  unsigned char llvm_cbe_tmp__1496;
  bool llvm_cbe_tmp__1497;
  bool llvm_cbe_tmp__1498;
  bool llvm_cbe_tmp__1498__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1499;
  unsigned long long llvm_cbe_tmp__1500;
  unsigned long long llvm_cbe_tmp__1501;
  unsigned char llvm_cbe_tmp__1502;
  unsigned char llvm_cbe_tmp__1503;
  bool llvm_cbe_tmp__1504;
  bool llvm_cbe_tmp__1505;
  bool llvm_cbe_tmp__1505__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1506;
  unsigned long long llvm_cbe_tmp__1507;
  unsigned long long llvm_cbe_tmp__1508;
  unsigned char llvm_cbe_tmp__1509;
  unsigned char llvm_cbe_tmp__1510;
  bool llvm_cbe_tmp__1511;
  bool llvm_cbe_tmp__1512;
  bool llvm_cbe_tmp__1512__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1513;
  unsigned long long llvm_cbe_tmp__1514;
  unsigned long long llvm_cbe_tmp__1515;
  unsigned long long llvm_cbe_tmp__1516;
  unsigned long long llvm_cbe_tmp__1517;
  unsigned long long llvm_cbe_tmp__1518;
  unsigned long long llvm_cbe_tmp__1519;
  unsigned long long llvm_cbe_tmp__1520;
  unsigned long long llvm_cbe_tmp__1521;
  unsigned long long llvm_cbe_tmp__1522;

  *(&llvm_cbe_tmp__1402) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1403) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1404) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1405) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1406) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1407) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1408) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1409) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1410) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1411) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1412) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1413) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1414 = *(&llvm_cbe_tmp__1402);
  llvm_cbe_tmp__1415 = *((&llvm_cbe_tmp__1414->field29));
  *(&llvm_cbe_cppVar_780) = (((unsigned char )(bool )(llvm_cbe_tmp__1415 == 0ull)));
  llvm_cbe_tmp__1416 = *(&llvm_cbe_cppVar_780);
  if ((((((bool )llvm_cbe_tmp__1416&1u))&1))) {
    goto llvm_cbe_tmp__1523;
  } else {
    goto llvm_cbe_tmp__1524;
  }

llvm_cbe_tmp__1523:
  llvm_cbe_tmp__1417 = *((&llvm_cbe_tmp__1414->field30));
  *(&llvm_cbe_cppVar_783) = (((unsigned char )(bool )(llvm_cbe_tmp__1417 == 0ull)));
  llvm_cbe_tmp__1418 = *(&llvm_cbe_cppVar_783);
  if ((((((bool )llvm_cbe_tmp__1418&1u))&1))) {
    goto llvm_cbe_tmp__1525;
  } else {
    goto llvm_cbe_tmp__1526;
  }

llvm_cbe_tmp__1525:
  *(&llvm_cbe_cppVar_781) = 0ull;
  goto llvm_cbe_tmp__1527;

llvm_cbe_tmp__1526:
  llvm_cbe_tmp__1419 = *((&llvm_cbe_tmp__1414->field28));
  *(&llvm_cbe_cppVar_781) = llvm_cbe_tmp__1419;
  goto llvm_cbe_tmp__1527;

llvm_cbe_tmp__1527:
  llvm_cbe_tmp__1420 = *((&llvm_cbe_tmp__1414->field30));
  llvm_cbe_tmp__1421 = *((&llvm_cbe_tmp__1414->field45));
  *(&llvm_cbe_cppVar_786) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1420) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1421);
  llvm_cbe_tmp__1422 = *(&llvm_cbe_cppVar_786);
  llvm_cbe_tmp__1423 = _ZN8type_memIhLj512EE2rdEl(((&llvm_cbe_tmp__1414->field0)), llvm_cbe_tmp__1422);
  *(&llvm_cbe_cppVar_787) = llvm_cbe_tmp__1423;
  llvm_cbe_tmp__1424 = *(&llvm_cbe_cppVar_787);
  *(&llvm_cbe_cppVar_789) = (((unsigned char )(bool )(llvm_cbe_tmp__1424 == 1ull)));
  llvm_cbe_tmp__1425 = *(&llvm_cbe_cppVar_789);
  if ((((((bool )llvm_cbe_tmp__1425&1u))&1))) {
    goto llvm_cbe_tmp__1528;
  } else {
    goto llvm_cbe_tmp__1529;
  }

llvm_cbe_tmp__1528:
  llvm_cbe_tmp__1426 = *((&llvm_cbe_tmp__1414->field30));
  *(&llvm_cbe_cppVar_791) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__1426))));
  llvm_cbe_tmp__1427 = *(&llvm_cbe_cppVar_791);
  llvm_cbe_tmp__1428 = *((&llvm_cbe_tmp__1414->field39));
  *(&llvm_cbe_cppVar_791) = (llvm_cbe_tmp__1427 & llvm_cbe_tmp__1428);
  llvm_cbe_tmp__1429 = *(&llvm_cbe_cppVar_791);
  llvm_cbe_tmp__1430 = *((&llvm_cbe_tmp__1414->field25));
  *(&llvm_cbe_cppVar_792) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1429) + ((unsigned long long )llvm_cbe_tmp__1430))));
  llvm_cbe_tmp__1431 = *(&llvm_cbe_cppVar_792);
  llvm_cbe_tmp__1432 = *((&llvm_cbe_tmp__1414->field39));
  *(&llvm_cbe_cppVar_792) = (llvm_cbe_tmp__1431 & llvm_cbe_tmp__1432);
  llvm_cbe_tmp__1433 = *(&llvm_cbe_cppVar_792);
  llvm_cbe_tmp__1434 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1414->field3)), llvm_cbe_tmp__1433);
  *(&llvm_cbe_cppVar_793) = llvm_cbe_tmp__1434;
  llvm_cbe_tmp__1435 = *(&llvm_cbe_cppVar_793);
  llvm_cbe_tmp__1436 = *((&llvm_cbe_tmp__1414->field43));
  *(&llvm_cbe_cppVar_794) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1435) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1436);
  llvm_cbe_tmp__1437 = *(&llvm_cbe_cppVar_794);
  llvm_cbe_tmp__1438 = *((&llvm_cbe_tmp__1414->field47));
  llvm_cbe_tmp__1439 = *(&llvm_cbe_cppVar_794);
  if (((llvm_cbe_tmp__1437 & llvm_cbe_tmp__1438) != 0ull)) {
    goto llvm_cbe_tmp__1530;
  } else {
    llvm_cbe_tmp__1442__PHI_TEMPORARY = llvm_cbe_tmp__1439;   /* for PHI node */
    goto llvm_cbe_tmp__1531;
  }

llvm_cbe_tmp__1530:
  llvm_cbe_tmp__1440 = *((&llvm_cbe_tmp__1414->field49));
  llvm_cbe_tmp__1441 = llvm_cbe_tmp__1439 | llvm_cbe_tmp__1440;
  llvm_cbe_tmp__1442__PHI_TEMPORARY = llvm_cbe_tmp__1441;   /* for PHI node */
  goto llvm_cbe_tmp__1531;

llvm_cbe_tmp__1531:
  llvm_cbe_tmp__1442 = llvm_cbe_tmp__1442__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_795) = llvm_cbe_tmp__1442;
  llvm_cbe_tmp__1443 = *(&llvm_cbe_cppVar_793);
  llvm_cbe_tmp__1444 = *((&llvm_cbe_tmp__1414->field38));
  *(&llvm_cbe_cppVar_796) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1443) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1444);
  llvm_cbe_tmp__1445 = *(&llvm_cbe_cppVar_795);
  llvm_cbe_tmp__1446 = *(&llvm_cbe_cppVar_796);
  *(&llvm_cbe_cppVar_797) = ((llvm_cbe_tmp__1445 << 1ull) | llvm_cbe_tmp__1446);
  llvm_cbe_tmp__1447 = *(&llvm_cbe_cppVar_797);
  llvm_cbe_tmp__1448 = *((&llvm_cbe_tmp__1414->field39));
  *(&llvm_cbe_cppVar_797) = (llvm_cbe_tmp__1447 & llvm_cbe_tmp__1448);
  llvm_cbe_tmp__1449 = *(&llvm_cbe_cppVar_797);
  *(&llvm_cbe_cppVar_785) = llvm_cbe_tmp__1449;
  goto llvm_cbe_tmp__1532;

llvm_cbe_tmp__1529:
  *(&llvm_cbe_cppVar_785) = 0ull;
  goto llvm_cbe_tmp__1532;

llvm_cbe_tmp__1532:
  llvm_cbe_tmp__1450 = *(&llvm_cbe_cppVar_781);
  llvm_cbe_tmp__1451 = *(&llvm_cbe_cppVar_785);
  *(&llvm_cbe_cppVar_799) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1450) + ((unsigned long long )llvm_cbe_tmp__1451))));
  llvm_cbe_tmp__1452 = *(&llvm_cbe_cppVar_799);
  llvm_cbe_tmp__1453 = *((&llvm_cbe_tmp__1414->field39));
  *(&llvm_cbe_cppVar_799) = (llvm_cbe_tmp__1452 & llvm_cbe_tmp__1453);
  llvm_cbe_tmp__1454 = *(&llvm_cbe_cppVar_799);
  *(&llvm_cbe_cppVar_778) = llvm_cbe_tmp__1454;
  goto llvm_cbe_tmp__1533;

llvm_cbe_tmp__1524:
  llvm_cbe_tmp__1455 = *((&llvm_cbe_tmp__1414->field29));
  *(&llvm_cbe_cppVar_802) = (((unsigned char )(bool )(llvm_cbe_tmp__1455 == 1ull)));
  llvm_cbe_tmp__1456 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1456&1u))&1))) {
    goto llvm_cbe_tmp__1534;
  } else {
    goto llvm_cbe_tmp__1535;
  }

llvm_cbe_tmp__1534:
  llvm_cbe_tmp__1457 = *((&llvm_cbe_tmp__1414->field15));
  *(&llvm_cbe_cppVar_805) = (((unsigned char )(bool )(llvm_cbe_tmp__1457 == 0ull)));
  llvm_cbe_tmp__1458 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1458&1u))&1))) {
    goto llvm_cbe_tmp__1536;
  } else {
    llvm_cbe_tmp__1461__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1537;
  }

llvm_cbe_tmp__1536:
  llvm_cbe_tmp__1459 = *(&llvm_cbe_cppVar_805);
  llvm_cbe_tmp__1460 = ((((bool )llvm_cbe_tmp__1459&1u))&1);
  llvm_cbe_tmp__1461__PHI_TEMPORARY = llvm_cbe_tmp__1460;   /* for PHI node */
  goto llvm_cbe_tmp__1537;

llvm_cbe_tmp__1537:
  llvm_cbe_tmp__1461 = ((llvm_cbe_tmp__1461__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_806) = (((unsigned char )(bool )llvm_cbe_tmp__1461));
  llvm_cbe_tmp__1462 = *(&llvm_cbe_cppVar_806);
  if ((((((bool )llvm_cbe_tmp__1462&1u))&1))) {
    goto llvm_cbe_tmp__1538;
  } else {
    goto llvm_cbe_tmp__1539;
  }

llvm_cbe_tmp__1538:
  llvm_cbe_tmp__1463 = *((&llvm_cbe_tmp__1414->field25));
  *(&llvm_cbe_cppVar_809) = (((unsigned char )(bool )(llvm_cbe_tmp__1463 == 0ull)));
  llvm_cbe_tmp__1464 = *(&llvm_cbe_cppVar_809);
  if ((((((bool )llvm_cbe_tmp__1464&1u))&1))) {
    goto llvm_cbe_tmp__1540;
  } else {
    goto llvm_cbe_tmp__1541;
  }

llvm_cbe_tmp__1540:
  *(&llvm_cbe_cppVar_807) = 0ull;
  goto llvm_cbe_tmp__1542;

llvm_cbe_tmp__1541:
  llvm_cbe_tmp__1465 = *((&llvm_cbe_tmp__1414->field28));
  *(&llvm_cbe_cppVar_807) = llvm_cbe_tmp__1465;
  goto llvm_cbe_tmp__1542;

llvm_cbe_tmp__1542:
  llvm_cbe_tmp__1466 = *((&llvm_cbe_tmp__1414->field25));
  llvm_cbe_tmp__1467 = *((&llvm_cbe_tmp__1414->field43));
  *(&llvm_cbe_cppVar_812) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1466) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1467);
  llvm_cbe_tmp__1468 = *(&llvm_cbe_cppVar_812);
  llvm_cbe_tmp__1469 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__1414->field4)), llvm_cbe_tmp__1468);
  *(&llvm_cbe_cppVar_813) = llvm_cbe_tmp__1469;
  llvm_cbe_tmp__1470 = *(&llvm_cbe_cppVar_813);
  *(&llvm_cbe_cppVar_815) = (((unsigned char )(bool )(llvm_cbe_tmp__1470 == 1ull)));
  llvm_cbe_tmp__1471 = *(&llvm_cbe_cppVar_815);
  if ((((((bool )llvm_cbe_tmp__1471&1u))&1))) {
    goto llvm_cbe_tmp__1543;
  } else {
    goto llvm_cbe_tmp__1544;
  }

llvm_cbe_tmp__1543:
  llvm_cbe_tmp__1472 = *(&llvm_cbe_cppVar_792);
  llvm_cbe_tmp__1473 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1414->field3)), llvm_cbe_tmp__1472);
  *(&llvm_cbe_cppVar_816) = llvm_cbe_tmp__1473;
  llvm_cbe_tmp__1474 = *(&llvm_cbe_cppVar_816);
  llvm_cbe_tmp__1475 = *((&llvm_cbe_tmp__1414->field43));
  *(&llvm_cbe_cppVar_817) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1474) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1475);
  llvm_cbe_tmp__1476 = *(&llvm_cbe_cppVar_817);
  llvm_cbe_tmp__1477 = *((&llvm_cbe_tmp__1414->field47));
  llvm_cbe_tmp__1478 = *(&llvm_cbe_cppVar_817);
  if (((llvm_cbe_tmp__1476 & llvm_cbe_tmp__1477) != 0ull)) {
    goto llvm_cbe_tmp__1545;
  } else {
    llvm_cbe_tmp__1481__PHI_TEMPORARY = llvm_cbe_tmp__1478;   /* for PHI node */
    goto llvm_cbe_tmp__1546;
  }

llvm_cbe_tmp__1545:
  llvm_cbe_tmp__1479 = *((&llvm_cbe_tmp__1414->field49));
  llvm_cbe_tmp__1480 = llvm_cbe_tmp__1478 | llvm_cbe_tmp__1479;
  llvm_cbe_tmp__1481__PHI_TEMPORARY = llvm_cbe_tmp__1480;   /* for PHI node */
  goto llvm_cbe_tmp__1546;

llvm_cbe_tmp__1546:
  llvm_cbe_tmp__1481 = llvm_cbe_tmp__1481__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_818) = llvm_cbe_tmp__1481;
  llvm_cbe_tmp__1482 = *(&llvm_cbe_cppVar_816);
  llvm_cbe_tmp__1483 = *((&llvm_cbe_tmp__1414->field38));
  *(&llvm_cbe_cppVar_819) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1482) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1483);
  llvm_cbe_tmp__1484 = *(&llvm_cbe_cppVar_818);
  llvm_cbe_tmp__1485 = *(&llvm_cbe_cppVar_819);
  *(&llvm_cbe_cppVar_820) = ((llvm_cbe_tmp__1484 << 1ull) | llvm_cbe_tmp__1485);
  llvm_cbe_tmp__1486 = *(&llvm_cbe_cppVar_820);
  llvm_cbe_tmp__1487 = *((&llvm_cbe_tmp__1414->field39));
  *(&llvm_cbe_cppVar_820) = (llvm_cbe_tmp__1486 & llvm_cbe_tmp__1487);
  llvm_cbe_tmp__1488 = *(&llvm_cbe_cppVar_820);
  *(&llvm_cbe_cppVar_811) = llvm_cbe_tmp__1488;
  goto llvm_cbe_tmp__1547;

llvm_cbe_tmp__1544:
  *(&llvm_cbe_cppVar_811) = 0ull;
  goto llvm_cbe_tmp__1547;

llvm_cbe_tmp__1547:
  llvm_cbe_tmp__1489 = *(&llvm_cbe_cppVar_807);
  llvm_cbe_tmp__1490 = *(&llvm_cbe_cppVar_811);
  *(&llvm_cbe_cppVar_821) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1489) + ((unsigned long long )llvm_cbe_tmp__1490))));
  llvm_cbe_tmp__1491 = *(&llvm_cbe_cppVar_821);
  llvm_cbe_tmp__1492 = *((&llvm_cbe_tmp__1414->field39));
  *(&llvm_cbe_cppVar_821) = (llvm_cbe_tmp__1491 & llvm_cbe_tmp__1492);
  llvm_cbe_tmp__1493 = *(&llvm_cbe_cppVar_821);
  *(&llvm_cbe_cppVar_803) = llvm_cbe_tmp__1493;
  goto llvm_cbe_tmp__1548;

llvm_cbe_tmp__1539:
  llvm_cbe_tmp__1494 = *((&llvm_cbe_tmp__1414->field15));
  *(&llvm_cbe_cppVar_824) = (((unsigned char )(bool )(llvm_cbe_tmp__1494 == 1ull)));
  llvm_cbe_tmp__1495 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1495&1u))&1))) {
    goto llvm_cbe_tmp__1549;
  } else {
    llvm_cbe_tmp__1498__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1550;
  }

llvm_cbe_tmp__1549:
  llvm_cbe_tmp__1496 = *(&llvm_cbe_cppVar_824);
  llvm_cbe_tmp__1497 = ((((bool )llvm_cbe_tmp__1496&1u))&1);
  llvm_cbe_tmp__1498__PHI_TEMPORARY = llvm_cbe_tmp__1497;   /* for PHI node */
  goto llvm_cbe_tmp__1550;

llvm_cbe_tmp__1550:
  llvm_cbe_tmp__1498 = ((llvm_cbe_tmp__1498__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_825) = (((unsigned char )(bool )llvm_cbe_tmp__1498));
  llvm_cbe_tmp__1499 = *(&llvm_cbe_cppVar_825);
  if ((((((bool )llvm_cbe_tmp__1499&1u))&1))) {
    goto llvm_cbe_tmp__1551;
  } else {
    goto llvm_cbe_tmp__1552;
  }

llvm_cbe_tmp__1551:
  llvm_cbe_tmp__1500 = *((&llvm_cbe_tmp__1414->field28));
  *(&llvm_cbe_cppVar_822) = llvm_cbe_tmp__1500;
  goto llvm_cbe_tmp__1553;

llvm_cbe_tmp__1552:
  llvm_cbe_tmp__1501 = *((&llvm_cbe_tmp__1414->field15));
  *(&llvm_cbe_cppVar_828) = (((unsigned char )(bool )(llvm_cbe_tmp__1501 == 2ull)));
  llvm_cbe_tmp__1502 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1502&1u))&1))) {
    goto llvm_cbe_tmp__1554;
  } else {
    llvm_cbe_tmp__1505__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1555;
  }

llvm_cbe_tmp__1554:
  llvm_cbe_tmp__1503 = *(&llvm_cbe_cppVar_828);
  llvm_cbe_tmp__1504 = ((((bool )llvm_cbe_tmp__1503&1u))&1);
  llvm_cbe_tmp__1505__PHI_TEMPORARY = llvm_cbe_tmp__1504;   /* for PHI node */
  goto llvm_cbe_tmp__1555;

llvm_cbe_tmp__1555:
  llvm_cbe_tmp__1505 = ((llvm_cbe_tmp__1505__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_829) = (((unsigned char )(bool )llvm_cbe_tmp__1505));
  llvm_cbe_tmp__1506 = *(&llvm_cbe_cppVar_829);
  if ((((((bool )llvm_cbe_tmp__1506&1u))&1))) {
    goto llvm_cbe_tmp__1556;
  } else {
    goto llvm_cbe_tmp__1557;
  }

llvm_cbe_tmp__1556:
  llvm_cbe_tmp__1507 = *((&llvm_cbe_tmp__1414->field28));
  *(&llvm_cbe_cppVar_826) = llvm_cbe_tmp__1507;
  goto llvm_cbe_tmp__1558;

llvm_cbe_tmp__1557:
  llvm_cbe_tmp__1508 = *((&llvm_cbe_tmp__1414->field15));
  *(&llvm_cbe_cppVar_832) = (((unsigned char )(bool )(llvm_cbe_tmp__1508 == 3ull)));
  llvm_cbe_tmp__1509 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1509&1u))&1))) {
    goto llvm_cbe_tmp__1559;
  } else {
    llvm_cbe_tmp__1512__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1560;
  }

llvm_cbe_tmp__1559:
  llvm_cbe_tmp__1510 = *(&llvm_cbe_cppVar_832);
  llvm_cbe_tmp__1511 = ((((bool )llvm_cbe_tmp__1510&1u))&1);
  llvm_cbe_tmp__1512__PHI_TEMPORARY = llvm_cbe_tmp__1511;   /* for PHI node */
  goto llvm_cbe_tmp__1560;

llvm_cbe_tmp__1560:
  llvm_cbe_tmp__1512 = ((llvm_cbe_tmp__1512__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_833) = (((unsigned char )(bool )llvm_cbe_tmp__1512));
  llvm_cbe_tmp__1513 = *((&llvm_cbe_tmp__1414->field28));
  *(&llvm_cbe_cppVar_830) = llvm_cbe_tmp__1513;
  llvm_cbe_tmp__1514 = *(&llvm_cbe_cppVar_830);
  *(&llvm_cbe_cppVar_826) = llvm_cbe_tmp__1514;
  goto llvm_cbe_tmp__1558;

llvm_cbe_tmp__1558:
  llvm_cbe_tmp__1515 = *(&llvm_cbe_cppVar_826);
  *(&llvm_cbe_cppVar_822) = llvm_cbe_tmp__1515;
  goto llvm_cbe_tmp__1553;

llvm_cbe_tmp__1553:
  llvm_cbe_tmp__1516 = *(&llvm_cbe_cppVar_822);
  *(&llvm_cbe_cppVar_803) = llvm_cbe_tmp__1516;
  goto llvm_cbe_tmp__1548;

llvm_cbe_tmp__1548:
  llvm_cbe_tmp__1517 = *(&llvm_cbe_cppVar_803);
  *(&llvm_cbe_cppVar_800) = llvm_cbe_tmp__1517;
  goto llvm_cbe_tmp__1561;

llvm_cbe_tmp__1535:
  llvm_cbe_tmp__1518 = *((&llvm_cbe_tmp__1414->field29));
  *(&llvm_cbe_cppVar_836) = (((unsigned char )(bool )(llvm_cbe_tmp__1518 == 2ull)));
  llvm_cbe_tmp__1519 = *((&llvm_cbe_tmp__1414->field28));
  *(&llvm_cbe_cppVar_834) = llvm_cbe_tmp__1519;
  llvm_cbe_tmp__1520 = *(&llvm_cbe_cppVar_834);
  *(&llvm_cbe_cppVar_800) = llvm_cbe_tmp__1520;
  goto llvm_cbe_tmp__1561;

llvm_cbe_tmp__1561:
  llvm_cbe_tmp__1521 = *(&llvm_cbe_cppVar_800);
  *(&llvm_cbe_cppVar_778) = llvm_cbe_tmp__1521;
  goto llvm_cbe_tmp__1533;

llvm_cbe_tmp__1533:
  llvm_cbe_tmp__1522 = *(&llvm_cbe_cppVar_778);
  return llvm_cbe_tmp__1522;
}


unsigned long long _ZN11model_train22cppUpdateFun_train_upcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1562;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1563;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1564;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1565;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1566;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1567;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1568;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1569;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1570;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1571;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1572;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1573;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_839;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_840;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_848;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_850;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_851;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_847;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_870;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_871;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_868;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_878;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_879;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_876;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_842;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_843;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_844;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_845;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_846;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_841;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_856;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_857;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_859;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_860;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_861;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_862;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_863;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_864;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_865;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_866;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_853;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_854;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_855;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_858;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_867;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_852;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_873;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_874;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_875;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_872;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_881;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_882;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_883;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_880;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_877;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_869;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_849;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_838;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1574;
  unsigned long long llvm_cbe_tmp__1575;
  unsigned char llvm_cbe_tmp__1576;
  unsigned long long llvm_cbe_tmp__1577;
  unsigned long long llvm_cbe_tmp__1578;
  unsigned long long llvm_cbe_tmp__1579;
  unsigned long long llvm_cbe_tmp__1580;
  unsigned long long llvm_cbe_tmp__1581;
  unsigned long long llvm_cbe_tmp__1582;
  unsigned long long llvm_cbe_tmp__1583;
  unsigned char llvm_cbe_tmp__1584;
  unsigned char llvm_cbe_tmp__1585;
  bool llvm_cbe_tmp__1586;
  bool llvm_cbe_tmp__1587;
  bool llvm_cbe_tmp__1587__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1588;
  unsigned long long llvm_cbe_tmp__1589;
  unsigned long long llvm_cbe_tmp__1590;
  unsigned char llvm_cbe_tmp__1591;
  unsigned long long llvm_cbe_tmp__1592;
  unsigned char llvm_cbe_tmp__1593;
  unsigned char llvm_cbe_tmp__1594;
  bool llvm_cbe_tmp__1595;
  bool llvm_cbe_tmp__1596;
  bool llvm_cbe_tmp__1596__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1597;
  unsigned char llvm_cbe_tmp__1598;
  unsigned char llvm_cbe_tmp__1599;
  bool llvm_cbe_tmp__1600;
  bool llvm_cbe_tmp__1601;
  bool llvm_cbe_tmp__1601__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1602;
  unsigned long long llvm_cbe_tmp__1603;
  unsigned long long llvm_cbe_tmp__1604;
  unsigned long long llvm_cbe_tmp__1605;
  unsigned long long llvm_cbe_tmp__1606;
  unsigned long long llvm_cbe_tmp__1607;
  unsigned long long llvm_cbe_tmp__1608;
  unsigned long long llvm_cbe_tmp__1609;
  unsigned long long llvm_cbe_tmp__1610;
  unsigned char llvm_cbe_tmp__1611;
  unsigned char llvm_cbe_tmp__1612;
  bool llvm_cbe_tmp__1613;
  bool llvm_cbe_tmp__1614;
  bool llvm_cbe_tmp__1614__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1615;
  unsigned char llvm_cbe_tmp__1616;
  bool llvm_cbe_tmp__1617;
  bool llvm_cbe_tmp__1618;
  bool llvm_cbe_tmp__1618__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1619;
  unsigned long long llvm_cbe_tmp__1620;
  unsigned long long llvm_cbe_tmp__1621;
  unsigned char llvm_cbe_tmp__1622;
  unsigned long long llvm_cbe_tmp__1623;
  unsigned long long llvm_cbe_tmp__1624;
  unsigned long long llvm_cbe_tmp__1625;
  unsigned long long llvm_cbe_tmp__1626;
  unsigned char llvm_cbe_tmp__1627;
  unsigned char llvm_cbe_tmp__1628;
  bool llvm_cbe_tmp__1629;
  bool llvm_cbe_tmp__1630;
  bool llvm_cbe_tmp__1630__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1631;
  unsigned long long llvm_cbe_tmp__1632;
  unsigned long long llvm_cbe_tmp__1633;
  unsigned char llvm_cbe_tmp__1634;
  unsigned long long llvm_cbe_tmp__1635;
  unsigned long long llvm_cbe_tmp__1636;
  unsigned long long llvm_cbe_tmp__1637;
  unsigned long long llvm_cbe_tmp__1638;
  unsigned char llvm_cbe_tmp__1639;
  unsigned char llvm_cbe_tmp__1640;
  bool llvm_cbe_tmp__1641;
  bool llvm_cbe_tmp__1642;
  bool llvm_cbe_tmp__1642__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1643;
  unsigned long long llvm_cbe_tmp__1644;
  unsigned long long llvm_cbe_tmp__1645;
  unsigned long long llvm_cbe_tmp__1646;
  unsigned long long llvm_cbe_tmp__1647;
  unsigned long long llvm_cbe_tmp__1648;

  *(&llvm_cbe_tmp__1562) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1563) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1564) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1565) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1566) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1567) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1568) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1569) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1570) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1571) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1572) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1573) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1574 = *(&llvm_cbe_tmp__1562);
  llvm_cbe_tmp__1575 = *((&llvm_cbe_tmp__1574->field29));
  *(&llvm_cbe_cppVar_840) = (((unsigned char )(bool )(llvm_cbe_tmp__1575 == 0ull)));
  llvm_cbe_tmp__1576 = *(&llvm_cbe_cppVar_840);
  if ((((((bool )llvm_cbe_tmp__1576&1u))&1))) {
    goto llvm_cbe_tmp__1649;
  } else {
    goto llvm_cbe_tmp__1650;
  }

llvm_cbe_tmp__1649:
  llvm_cbe_tmp__1577 = *((&llvm_cbe_tmp__1574->field30));
  llvm_cbe_tmp__1578 = *((&llvm_cbe_tmp__1574->field14));
  *(&llvm_cbe_cppVar_842) = (((unsigned char )(bool )(llvm_cbe_tmp__1577 == llvm_cbe_tmp__1578)));
  llvm_cbe_tmp__1579 = *((&llvm_cbe_tmp__1574->field9));
  *(&llvm_cbe_cppVar_844) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1579) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__1580 = *(&llvm_cbe_cppVar_844);
  llvm_cbe_tmp__1581 = *((&llvm_cbe_tmp__1574->field39));
  *(&llvm_cbe_cppVar_844) = (llvm_cbe_tmp__1580 & llvm_cbe_tmp__1581);
  llvm_cbe_tmp__1582 = *((&llvm_cbe_tmp__1574->field25));
  llvm_cbe_tmp__1583 = *(&llvm_cbe_cppVar_844);
  *(&llvm_cbe_cppVar_845) = (((unsigned char )(bool )(llvm_cbe_tmp__1582 == llvm_cbe_tmp__1583)));
  llvm_cbe_tmp__1584 = *(&llvm_cbe_cppVar_842);
  if ((((((bool )llvm_cbe_tmp__1584&1u))&1))) {
    goto llvm_cbe_tmp__1651;
  } else {
    llvm_cbe_tmp__1587__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1652;
  }

llvm_cbe_tmp__1651:
  llvm_cbe_tmp__1585 = *(&llvm_cbe_cppVar_845);
  llvm_cbe_tmp__1586 = ((((bool )llvm_cbe_tmp__1585&1u))&1);
  llvm_cbe_tmp__1587__PHI_TEMPORARY = llvm_cbe_tmp__1586;   /* for PHI node */
  goto llvm_cbe_tmp__1652;

llvm_cbe_tmp__1652:
  llvm_cbe_tmp__1587 = ((llvm_cbe_tmp__1587__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_846) = (((unsigned char )(bool )llvm_cbe_tmp__1587));
  llvm_cbe_tmp__1588 = *(&llvm_cbe_cppVar_846);
  if ((((((bool )llvm_cbe_tmp__1588&1u))&1))) {
    goto llvm_cbe_tmp__1653;
  } else {
    goto llvm_cbe_tmp__1654;
  }

llvm_cbe_tmp__1653:
  *(&llvm_cbe_cppVar_841) = 1ull;
  goto llvm_cbe_tmp__1655;

llvm_cbe_tmp__1654:
  *(&llvm_cbe_cppVar_841) = 0ull;
  goto llvm_cbe_tmp__1655;

llvm_cbe_tmp__1655:
  llvm_cbe_tmp__1589 = *(&llvm_cbe_cppVar_841);
  *(&llvm_cbe_cppVar_838) = llvm_cbe_tmp__1589;
  goto llvm_cbe_tmp__1656;

llvm_cbe_tmp__1650:
  llvm_cbe_tmp__1590 = *((&llvm_cbe_tmp__1574->field29));
  *(&llvm_cbe_cppVar_851) = (((unsigned char )(bool )(llvm_cbe_tmp__1590 == 1ull)));
  llvm_cbe_tmp__1591 = *(&llvm_cbe_cppVar_851);
  if ((((((bool )llvm_cbe_tmp__1591&1u))&1))) {
    goto llvm_cbe_tmp__1657;
  } else {
    goto llvm_cbe_tmp__1658;
  }

llvm_cbe_tmp__1657:
  llvm_cbe_tmp__1592 = *((&llvm_cbe_tmp__1574->field15));
  *(&llvm_cbe_cppVar_854) = (((unsigned char )(bool )(llvm_cbe_tmp__1592 == 3ull)));
  llvm_cbe_tmp__1593 = *(&llvm_cbe_cppVar_851);
  if ((((((bool )llvm_cbe_tmp__1593&1u))&1))) {
    goto llvm_cbe_tmp__1659;
  } else {
    llvm_cbe_tmp__1596__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1660;
  }

llvm_cbe_tmp__1659:
  llvm_cbe_tmp__1594 = *(&llvm_cbe_cppVar_854);
  llvm_cbe_tmp__1595 = ((((bool )llvm_cbe_tmp__1594&1u))&1);
  llvm_cbe_tmp__1596__PHI_TEMPORARY = llvm_cbe_tmp__1595;   /* for PHI node */
  goto llvm_cbe_tmp__1660;

llvm_cbe_tmp__1660:
  llvm_cbe_tmp__1596 = ((llvm_cbe_tmp__1596__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_855) = (((unsigned char )(bool )llvm_cbe_tmp__1596));
  llvm_cbe_tmp__1597 = *((&llvm_cbe_tmp__1574->field7));
  *(&llvm_cbe_cppVar_857) = (((unsigned char )(bool )(llvm_cbe_tmp__1597 == 4ull)));
  llvm_cbe_tmp__1598 = *(&llvm_cbe_cppVar_855);
  if ((((((bool )llvm_cbe_tmp__1598&1u))&1))) {
    goto llvm_cbe_tmp__1661;
  } else {
    llvm_cbe_tmp__1601__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1662;
  }

llvm_cbe_tmp__1661:
  llvm_cbe_tmp__1599 = *(&llvm_cbe_cppVar_857);
  llvm_cbe_tmp__1600 = ((((bool )llvm_cbe_tmp__1599&1u))&1);
  llvm_cbe_tmp__1601__PHI_TEMPORARY = llvm_cbe_tmp__1600;   /* for PHI node */
  goto llvm_cbe_tmp__1662;

llvm_cbe_tmp__1662:
  llvm_cbe_tmp__1601 = ((llvm_cbe_tmp__1601__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_858) = (((unsigned char )(bool )llvm_cbe_tmp__1601));
  llvm_cbe_tmp__1602 = *((&llvm_cbe_tmp__1574->field30));
  *(&llvm_cbe_cppVar_860) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1602) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1603 = *(&llvm_cbe_cppVar_860);
  llvm_cbe_tmp__1604 = *((&llvm_cbe_tmp__1574->field39));
  *(&llvm_cbe_cppVar_860) = (llvm_cbe_tmp__1603 & llvm_cbe_tmp__1604);
  llvm_cbe_tmp__1605 = *(&llvm_cbe_cppVar_860);
  llvm_cbe_tmp__1606 = *((&llvm_cbe_tmp__1574->field14));
  *(&llvm_cbe_cppVar_861) = (((unsigned char )(bool )(llvm_cbe_tmp__1605 == llvm_cbe_tmp__1606)));
  llvm_cbe_tmp__1607 = *((&llvm_cbe_tmp__1574->field30));
  *(&llvm_cbe_cppVar_863) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1607) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1608 = *(&llvm_cbe_cppVar_863);
  llvm_cbe_tmp__1609 = *((&llvm_cbe_tmp__1574->field39));
  *(&llvm_cbe_cppVar_863) = (llvm_cbe_tmp__1608 & llvm_cbe_tmp__1609);
  llvm_cbe_tmp__1610 = *(&llvm_cbe_cppVar_863);
  *(&llvm_cbe_cppVar_865) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1610) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1611 = *(&llvm_cbe_cppVar_861);
  if ((((((bool )llvm_cbe_tmp__1611&1u))&1))) {
    llvm_cbe_tmp__1614__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1663;
  } else {
    goto llvm_cbe_tmp__1664;
  }

llvm_cbe_tmp__1664:
  llvm_cbe_tmp__1612 = *(&llvm_cbe_cppVar_865);
  llvm_cbe_tmp__1613 = ((((bool )llvm_cbe_tmp__1612&1u))&1);
  llvm_cbe_tmp__1614__PHI_TEMPORARY = llvm_cbe_tmp__1613;   /* for PHI node */
  goto llvm_cbe_tmp__1663;

llvm_cbe_tmp__1663:
  llvm_cbe_tmp__1614 = ((llvm_cbe_tmp__1614__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_866) = (((unsigned char )(bool )llvm_cbe_tmp__1614));
  llvm_cbe_tmp__1615 = *(&llvm_cbe_cppVar_858);
  if ((((((bool )llvm_cbe_tmp__1615&1u))&1))) {
    goto llvm_cbe_tmp__1665;
  } else {
    llvm_cbe_tmp__1618__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1666;
  }

llvm_cbe_tmp__1665:
  llvm_cbe_tmp__1616 = *(&llvm_cbe_cppVar_866);
  llvm_cbe_tmp__1617 = ((((bool )llvm_cbe_tmp__1616&1u))&1);
  llvm_cbe_tmp__1618__PHI_TEMPORARY = llvm_cbe_tmp__1617;   /* for PHI node */
  goto llvm_cbe_tmp__1666;

llvm_cbe_tmp__1666:
  llvm_cbe_tmp__1618 = ((llvm_cbe_tmp__1618__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_867) = (((unsigned char )(bool )llvm_cbe_tmp__1618));
  llvm_cbe_tmp__1619 = *(&llvm_cbe_cppVar_867);
  if ((((((bool )llvm_cbe_tmp__1619&1u))&1))) {
    goto llvm_cbe_tmp__1667;
  } else {
    goto llvm_cbe_tmp__1668;
  }

llvm_cbe_tmp__1667:
  *(&llvm_cbe_cppVar_852) = 3ull;
  goto llvm_cbe_tmp__1669;

llvm_cbe_tmp__1668:
  *(&llvm_cbe_cppVar_852) = 1ull;
  goto llvm_cbe_tmp__1669;

llvm_cbe_tmp__1669:
  llvm_cbe_tmp__1620 = *(&llvm_cbe_cppVar_852);
  *(&llvm_cbe_cppVar_849) = llvm_cbe_tmp__1620;
  goto llvm_cbe_tmp__1670;

llvm_cbe_tmp__1658:
  llvm_cbe_tmp__1621 = *((&llvm_cbe_tmp__1574->field29));
  *(&llvm_cbe_cppVar_871) = (((unsigned char )(bool )(llvm_cbe_tmp__1621 == 3ull)));
  llvm_cbe_tmp__1622 = *(&llvm_cbe_cppVar_871);
  if ((((((bool )llvm_cbe_tmp__1622&1u))&1))) {
    goto llvm_cbe_tmp__1671;
  } else {
    goto llvm_cbe_tmp__1672;
  }

llvm_cbe_tmp__1671:
  llvm_cbe_tmp__1623 = *((&llvm_cbe_tmp__1574->field25));
  llvm_cbe_tmp__1624 = *((&llvm_cbe_tmp__1574->field9));
  *(&llvm_cbe_cppVar_873) = (((unsigned char )(bool )(llvm_cbe_tmp__1623 == llvm_cbe_tmp__1624)));
  llvm_cbe_tmp__1625 = *((&llvm_cbe_tmp__1574->field30));
  llvm_cbe_tmp__1626 = *((&llvm_cbe_tmp__1574->field14));
  *(&llvm_cbe_cppVar_874) = (((unsigned char )(bool )(llvm_cbe_tmp__1625 == llvm_cbe_tmp__1626)));
  llvm_cbe_tmp__1627 = *(&llvm_cbe_cppVar_873);
  if ((((((bool )llvm_cbe_tmp__1627&1u))&1))) {
    goto llvm_cbe_tmp__1673;
  } else {
    llvm_cbe_tmp__1630__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1674;
  }

llvm_cbe_tmp__1673:
  llvm_cbe_tmp__1628 = *(&llvm_cbe_cppVar_874);
  llvm_cbe_tmp__1629 = ((((bool )llvm_cbe_tmp__1628&1u))&1);
  llvm_cbe_tmp__1630__PHI_TEMPORARY = llvm_cbe_tmp__1629;   /* for PHI node */
  goto llvm_cbe_tmp__1674;

llvm_cbe_tmp__1674:
  llvm_cbe_tmp__1630 = ((llvm_cbe_tmp__1630__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_875) = (((unsigned char )(bool )llvm_cbe_tmp__1630));
  llvm_cbe_tmp__1631 = *(&llvm_cbe_cppVar_875);
  if ((((((bool )llvm_cbe_tmp__1631&1u))&1))) {
    goto llvm_cbe_tmp__1675;
  } else {
    goto llvm_cbe_tmp__1676;
  }

llvm_cbe_tmp__1675:
  *(&llvm_cbe_cppVar_872) = 2ull;
  goto llvm_cbe_tmp__1677;

llvm_cbe_tmp__1676:
  *(&llvm_cbe_cppVar_872) = 3ull;
  goto llvm_cbe_tmp__1677;

llvm_cbe_tmp__1677:
  llvm_cbe_tmp__1632 = *(&llvm_cbe_cppVar_872);
  *(&llvm_cbe_cppVar_869) = llvm_cbe_tmp__1632;
  goto llvm_cbe_tmp__1678;

llvm_cbe_tmp__1672:
  llvm_cbe_tmp__1633 = *((&llvm_cbe_tmp__1574->field29));
  *(&llvm_cbe_cppVar_879) = (((unsigned char )(bool )(llvm_cbe_tmp__1633 == 2ull)));
  llvm_cbe_tmp__1634 = *(&llvm_cbe_cppVar_879);
  if ((((((bool )llvm_cbe_tmp__1634&1u))&1))) {
    goto llvm_cbe_tmp__1679;
  } else {
    goto llvm_cbe_tmp__1680;
  }

llvm_cbe_tmp__1679:
  llvm_cbe_tmp__1635 = *((&llvm_cbe_tmp__1574->field25));
  llvm_cbe_tmp__1636 = *((&llvm_cbe_tmp__1574->field9));
  *(&llvm_cbe_cppVar_881) = (((unsigned char )(bool )(llvm_cbe_tmp__1635 == llvm_cbe_tmp__1636)));
  llvm_cbe_tmp__1637 = *((&llvm_cbe_tmp__1574->field30));
  llvm_cbe_tmp__1638 = *((&llvm_cbe_tmp__1574->field14));
  *(&llvm_cbe_cppVar_882) = (((unsigned char )(bool )(llvm_cbe_tmp__1637 == llvm_cbe_tmp__1638)));
  llvm_cbe_tmp__1639 = *(&llvm_cbe_cppVar_881);
  if ((((((bool )llvm_cbe_tmp__1639&1u))&1))) {
    goto llvm_cbe_tmp__1681;
  } else {
    llvm_cbe_tmp__1642__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1682;
  }

llvm_cbe_tmp__1681:
  llvm_cbe_tmp__1640 = *(&llvm_cbe_cppVar_882);
  llvm_cbe_tmp__1641 = ((((bool )llvm_cbe_tmp__1640&1u))&1);
  llvm_cbe_tmp__1642__PHI_TEMPORARY = llvm_cbe_tmp__1641;   /* for PHI node */
  goto llvm_cbe_tmp__1682;

llvm_cbe_tmp__1682:
  llvm_cbe_tmp__1642 = ((llvm_cbe_tmp__1642__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_883) = (((unsigned char )(bool )llvm_cbe_tmp__1642));
  *(&llvm_cbe_cppVar_880) = 2ull;
  llvm_cbe_tmp__1643 = *(&llvm_cbe_cppVar_880);
  *(&llvm_cbe_cppVar_877) = llvm_cbe_tmp__1643;
  goto llvm_cbe_tmp__1683;

llvm_cbe_tmp__1680:
  llvm_cbe_tmp__1644 = *((&llvm_cbe_tmp__1574->field29));
  *(&llvm_cbe_cppVar_877) = llvm_cbe_tmp__1644;
  goto llvm_cbe_tmp__1683;

llvm_cbe_tmp__1683:
  llvm_cbe_tmp__1645 = *(&llvm_cbe_cppVar_877);
  *(&llvm_cbe_cppVar_869) = llvm_cbe_tmp__1645;
  goto llvm_cbe_tmp__1678;

llvm_cbe_tmp__1678:
  llvm_cbe_tmp__1646 = *(&llvm_cbe_cppVar_869);
  *(&llvm_cbe_cppVar_849) = llvm_cbe_tmp__1646;
  goto llvm_cbe_tmp__1670;

llvm_cbe_tmp__1670:
  llvm_cbe_tmp__1647 = *(&llvm_cbe_cppVar_849);
  *(&llvm_cbe_cppVar_838) = llvm_cbe_tmp__1647;
  goto llvm_cbe_tmp__1656;

llvm_cbe_tmp__1656:
  llvm_cbe_tmp__1648 = *(&llvm_cbe_cppVar_838);
  return llvm_cbe_tmp__1648;
}


unsigned long long _ZN11model_train24cppUpdateFun_train_v_cntElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1684;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1685;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1686;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1687;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1688;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1689;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1690;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1691;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1692;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1693;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1694;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1695;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_886;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_887;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_894;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_895;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_915;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_916;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_924;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_925;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_889;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_891;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_892;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_888;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_900;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_901;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_904;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_905;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_906;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_907;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_908;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_909;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_910;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_911;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_897;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_898;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_899;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_902;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_912;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_913;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_903;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_896;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_918;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_920;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_921;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_922;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_919;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_917;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_927;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_929;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_930;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_931;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_928;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_926;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_923;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_914;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_893;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_885;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_890;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1696;
  unsigned long long llvm_cbe_tmp__1697;
  unsigned char llvm_cbe_tmp__1698;
  unsigned long long llvm_cbe_tmp__1699;
  unsigned long long llvm_cbe_tmp__1700;
  unsigned char llvm_cbe_tmp__1701;
  unsigned long long llvm_cbe_tmp__1702;
  unsigned long long llvm_cbe_tmp__1703;
  unsigned long long llvm_cbe_tmp__1704;
  unsigned long long llvm_cbe_tmp__1705;
  unsigned long long llvm_cbe_tmp__1706;
  unsigned long long llvm_cbe_tmp__1707;
  unsigned char llvm_cbe_tmp__1708;
  unsigned long long llvm_cbe_tmp__1709;
  unsigned char llvm_cbe_tmp__1710;
  unsigned char llvm_cbe_tmp__1711;
  bool llvm_cbe_tmp__1712;
  bool llvm_cbe_tmp__1713;
  bool llvm_cbe_tmp__1713__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1714;
  unsigned char llvm_cbe_tmp__1715;
  unsigned char llvm_cbe_tmp__1716;
  bool llvm_cbe_tmp__1717;
  bool llvm_cbe_tmp__1718;
  bool llvm_cbe_tmp__1718__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1719;
  unsigned long long llvm_cbe_tmp__1720;
  unsigned long long llvm_cbe_tmp__1721;
  unsigned long long llvm_cbe_tmp__1722;
  unsigned long long llvm_cbe_tmp__1723;
  unsigned long long llvm_cbe_tmp__1724;
  unsigned long long llvm_cbe_tmp__1725;
  unsigned long long llvm_cbe_tmp__1726;
  unsigned long long llvm_cbe_tmp__1727;
  unsigned long long llvm_cbe_tmp__1728;
  unsigned char llvm_cbe_tmp__1729;
  unsigned char llvm_cbe_tmp__1730;
  bool llvm_cbe_tmp__1731;
  bool llvm_cbe_tmp__1732;
  bool llvm_cbe_tmp__1732__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1733;
  unsigned long long llvm_cbe_tmp__1734;
  unsigned long long llvm_cbe_tmp__1735;
  unsigned long long llvm_cbe_tmp__1736;
  unsigned long long llvm_cbe_tmp__1737;
  unsigned long long llvm_cbe_tmp__1738;
  unsigned long long llvm_cbe_tmp__1739;
  unsigned long long llvm_cbe_tmp__1740;
  unsigned char llvm_cbe_tmp__1741;
  unsigned long long llvm_cbe_tmp__1742;
  unsigned long long llvm_cbe_tmp__1743;
  unsigned char llvm_cbe_tmp__1744;
  unsigned long long llvm_cbe_tmp__1745;
  unsigned long long llvm_cbe_tmp__1746;
  unsigned char llvm_cbe_tmp__1747;
  unsigned long long llvm_cbe_tmp__1748;
  unsigned long long llvm_cbe_tmp__1749;
  unsigned long long llvm_cbe_tmp__1750;
  unsigned long long llvm_cbe_tmp__1751;
  unsigned long long llvm_cbe_tmp__1752;
  unsigned long long llvm_cbe_tmp__1753;
  unsigned long long llvm_cbe_tmp__1754;
  unsigned char llvm_cbe_tmp__1755;
  unsigned long long llvm_cbe_tmp__1756;
  unsigned long long llvm_cbe_tmp__1757;
  unsigned char llvm_cbe_tmp__1758;
  unsigned long long llvm_cbe_tmp__1759;
  unsigned long long llvm_cbe_tmp__1760;
  unsigned char llvm_cbe_tmp__1761;
  unsigned long long llvm_cbe_tmp__1762;
  unsigned long long llvm_cbe_tmp__1763;
  unsigned long long llvm_cbe_tmp__1764;
  unsigned long long llvm_cbe_tmp__1765;
  unsigned long long llvm_cbe_tmp__1766;
  unsigned long long llvm_cbe_tmp__1767;
  unsigned long long llvm_cbe_tmp__1768;
  unsigned long long llvm_cbe_tmp__1769;
  unsigned long long llvm_cbe_tmp__1770;
  unsigned long long llvm_cbe_tmp__1771;
  unsigned long long llvm_cbe_tmp__1772;

  *(&llvm_cbe_tmp__1684) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1685) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1686) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1687) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1688) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1689) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1690) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1691) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1692) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1693) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1694) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1695) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1696 = *(&llvm_cbe_tmp__1684);
  llvm_cbe_tmp__1697 = *((&llvm_cbe_tmp__1696->field29));
  *(&llvm_cbe_cppVar_887) = (((unsigned char )(bool )(llvm_cbe_tmp__1697 == 0ull)));
  llvm_cbe_tmp__1698 = *(&llvm_cbe_cppVar_887);
  if ((((((bool )llvm_cbe_tmp__1698&1u))&1))) {
    goto llvm_cbe_tmp__1773;
  } else {
    goto llvm_cbe_tmp__1774;
  }

llvm_cbe_tmp__1773:
  llvm_cbe_tmp__1699 = *((&llvm_cbe_tmp__1696->field30));
  llvm_cbe_tmp__1700 = *((&llvm_cbe_tmp__1696->field14));
  *(&llvm_cbe_cppVar_889) = (((unsigned char )(bool )(llvm_cbe_tmp__1699 == llvm_cbe_tmp__1700)));
  llvm_cbe_tmp__1701 = *(&llvm_cbe_cppVar_889);
  if ((((((bool )llvm_cbe_tmp__1701&1u))&1))) {
    goto llvm_cbe_tmp__1775;
  } else {
    goto llvm_cbe_tmp__1776;
  }

llvm_cbe_tmp__1775:
  *(&llvm_cbe_cppVar_888) = 0ull;
  goto llvm_cbe_tmp__1777;

llvm_cbe_tmp__1776:
  llvm_cbe_tmp__1702 = *((&llvm_cbe_tmp__1696->field30));
  *(&llvm_cbe_cppVar_892) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1702) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1703 = *(&llvm_cbe_cppVar_892);
  llvm_cbe_tmp__1704 = *((&llvm_cbe_tmp__1696->field39));
  *(&llvm_cbe_cppVar_892) = (llvm_cbe_tmp__1703 & llvm_cbe_tmp__1704);
  llvm_cbe_tmp__1705 = *(&llvm_cbe_cppVar_892);
  *(&llvm_cbe_cppVar_888) = llvm_cbe_tmp__1705;
  goto llvm_cbe_tmp__1777;

llvm_cbe_tmp__1777:
  llvm_cbe_tmp__1706 = *(&llvm_cbe_cppVar_888);
  *(&llvm_cbe_cppVar_885) = llvm_cbe_tmp__1706;
  goto llvm_cbe_tmp__1778;

llvm_cbe_tmp__1774:
  llvm_cbe_tmp__1707 = *((&llvm_cbe_tmp__1696->field29));
  *(&llvm_cbe_cppVar_895) = (((unsigned char )(bool )(llvm_cbe_tmp__1707 == 1ull)));
  llvm_cbe_tmp__1708 = *(&llvm_cbe_cppVar_895);
  if ((((((bool )llvm_cbe_tmp__1708&1u))&1))) {
    goto llvm_cbe_tmp__1779;
  } else {
    goto llvm_cbe_tmp__1780;
  }

llvm_cbe_tmp__1779:
  llvm_cbe_tmp__1709 = *((&llvm_cbe_tmp__1696->field15));
  *(&llvm_cbe_cppVar_898) = (((unsigned char )(bool )(llvm_cbe_tmp__1709 == 3ull)));
  llvm_cbe_tmp__1710 = *(&llvm_cbe_cppVar_895);
  if ((((((bool )llvm_cbe_tmp__1710&1u))&1))) {
    goto llvm_cbe_tmp__1781;
  } else {
    llvm_cbe_tmp__1713__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1782;
  }

llvm_cbe_tmp__1781:
  llvm_cbe_tmp__1711 = *(&llvm_cbe_cppVar_898);
  llvm_cbe_tmp__1712 = ((((bool )llvm_cbe_tmp__1711&1u))&1);
  llvm_cbe_tmp__1713__PHI_TEMPORARY = llvm_cbe_tmp__1712;   /* for PHI node */
  goto llvm_cbe_tmp__1782;

llvm_cbe_tmp__1782:
  llvm_cbe_tmp__1713 = ((llvm_cbe_tmp__1713__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_899) = (((unsigned char )(bool )llvm_cbe_tmp__1713));
  llvm_cbe_tmp__1714 = *((&llvm_cbe_tmp__1696->field7));
  *(&llvm_cbe_cppVar_901) = (((unsigned char )(bool )(llvm_cbe_tmp__1714 == 4ull)));
  llvm_cbe_tmp__1715 = *(&llvm_cbe_cppVar_899);
  if ((((((bool )llvm_cbe_tmp__1715&1u))&1))) {
    goto llvm_cbe_tmp__1783;
  } else {
    llvm_cbe_tmp__1718__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1784;
  }

llvm_cbe_tmp__1783:
  llvm_cbe_tmp__1716 = *(&llvm_cbe_cppVar_901);
  llvm_cbe_tmp__1717 = ((((bool )llvm_cbe_tmp__1716&1u))&1);
  llvm_cbe_tmp__1718__PHI_TEMPORARY = llvm_cbe_tmp__1717;   /* for PHI node */
  goto llvm_cbe_tmp__1784;

llvm_cbe_tmp__1784:
  llvm_cbe_tmp__1718 = ((llvm_cbe_tmp__1718__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_902) = (((unsigned char )(bool )llvm_cbe_tmp__1718));
  llvm_cbe_tmp__1719 = *(&llvm_cbe_cppVar_902);
  llvm_cbe_tmp__1720 = *((&llvm_cbe_tmp__1696->field30));
  if ((((((bool )llvm_cbe_tmp__1719&1u))&1))) {
    goto llvm_cbe_tmp__1785;
  } else {
    goto llvm_cbe_tmp__1786;
  }

llvm_cbe_tmp__1785:
  *(&llvm_cbe_cppVar_905) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1720) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1721 = *(&llvm_cbe_cppVar_905);
  llvm_cbe_tmp__1722 = *((&llvm_cbe_tmp__1696->field39));
  *(&llvm_cbe_cppVar_905) = (llvm_cbe_tmp__1721 & llvm_cbe_tmp__1722);
  llvm_cbe_tmp__1723 = *(&llvm_cbe_cppVar_905);
  llvm_cbe_tmp__1724 = *((&llvm_cbe_tmp__1696->field14));
  *(&llvm_cbe_cppVar_906) = (((unsigned char )(bool )(llvm_cbe_tmp__1723 == llvm_cbe_tmp__1724)));
  llvm_cbe_tmp__1725 = *((&llvm_cbe_tmp__1696->field30));
  *(&llvm_cbe_cppVar_908) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1725) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1726 = *(&llvm_cbe_cppVar_908);
  llvm_cbe_tmp__1727 = *((&llvm_cbe_tmp__1696->field39));
  *(&llvm_cbe_cppVar_908) = (llvm_cbe_tmp__1726 & llvm_cbe_tmp__1727);
  llvm_cbe_tmp__1728 = *(&llvm_cbe_cppVar_908);
  *(&llvm_cbe_cppVar_910) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1728) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1729 = *(&llvm_cbe_cppVar_906);
  if ((((((bool )llvm_cbe_tmp__1729&1u))&1))) {
    llvm_cbe_tmp__1732__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1787;
  } else {
    goto llvm_cbe_tmp__1788;
  }

llvm_cbe_tmp__1788:
  llvm_cbe_tmp__1730 = *(&llvm_cbe_cppVar_910);
  llvm_cbe_tmp__1731 = ((((bool )llvm_cbe_tmp__1730&1u))&1);
  llvm_cbe_tmp__1732__PHI_TEMPORARY = llvm_cbe_tmp__1731;   /* for PHI node */
  goto llvm_cbe_tmp__1787;

llvm_cbe_tmp__1787:
  llvm_cbe_tmp__1732 = ((llvm_cbe_tmp__1732__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_911) = (((unsigned char )(bool )llvm_cbe_tmp__1732));
  llvm_cbe_tmp__1733 = *(&llvm_cbe_cppVar_911);
  if ((((((bool )llvm_cbe_tmp__1733&1u))&1))) {
    goto llvm_cbe_tmp__1789;
  } else {
    goto llvm_cbe_tmp__1790;
  }

llvm_cbe_tmp__1789:
  *(&llvm_cbe_cppVar_903) = 0ull;
  goto llvm_cbe_tmp__1791;

llvm_cbe_tmp__1790:
  llvm_cbe_tmp__1734 = *((&llvm_cbe_tmp__1696->field30));
  *(&llvm_cbe_cppVar_913) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1734) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1735 = *(&llvm_cbe_cppVar_913);
  llvm_cbe_tmp__1736 = *((&llvm_cbe_tmp__1696->field39));
  *(&llvm_cbe_cppVar_913) = (llvm_cbe_tmp__1735 & llvm_cbe_tmp__1736);
  llvm_cbe_tmp__1737 = *(&llvm_cbe_cppVar_913);
  *(&llvm_cbe_cppVar_903) = llvm_cbe_tmp__1737;
  goto llvm_cbe_tmp__1791;

llvm_cbe_tmp__1791:
  llvm_cbe_tmp__1738 = *(&llvm_cbe_cppVar_903);
  *(&llvm_cbe_cppVar_896) = llvm_cbe_tmp__1738;
  goto llvm_cbe_tmp__1792;

llvm_cbe_tmp__1786:
  *(&llvm_cbe_cppVar_896) = llvm_cbe_tmp__1720;
  goto llvm_cbe_tmp__1792;

llvm_cbe_tmp__1792:
  llvm_cbe_tmp__1739 = *(&llvm_cbe_cppVar_896);
  *(&llvm_cbe_cppVar_893) = llvm_cbe_tmp__1739;
  goto llvm_cbe_tmp__1793;

llvm_cbe_tmp__1780:
  llvm_cbe_tmp__1740 = *((&llvm_cbe_tmp__1696->field29));
  *(&llvm_cbe_cppVar_916) = (((unsigned char )(bool )(llvm_cbe_tmp__1740 == 3ull)));
  llvm_cbe_tmp__1741 = *(&llvm_cbe_cppVar_916);
  if ((((((bool )llvm_cbe_tmp__1741&1u))&1))) {
    goto llvm_cbe_tmp__1794;
  } else {
    goto llvm_cbe_tmp__1795;
  }

llvm_cbe_tmp__1794:
  llvm_cbe_tmp__1742 = *((&llvm_cbe_tmp__1696->field25));
  llvm_cbe_tmp__1743 = *((&llvm_cbe_tmp__1696->field9));
  *(&llvm_cbe_cppVar_918) = (((unsigned char )(bool )(llvm_cbe_tmp__1742 == llvm_cbe_tmp__1743)));
  llvm_cbe_tmp__1744 = *(&llvm_cbe_cppVar_918);
  llvm_cbe_tmp__1745 = *((&llvm_cbe_tmp__1696->field30));
  if ((((((bool )llvm_cbe_tmp__1744&1u))&1))) {
    goto llvm_cbe_tmp__1796;
  } else {
    goto llvm_cbe_tmp__1797;
  }

llvm_cbe_tmp__1796:
  llvm_cbe_tmp__1746 = *((&llvm_cbe_tmp__1696->field14));
  *(&llvm_cbe_cppVar_920) = (((unsigned char )(bool )(llvm_cbe_tmp__1745 == llvm_cbe_tmp__1746)));
  llvm_cbe_tmp__1747 = *(&llvm_cbe_cppVar_920);
  if ((((((bool )llvm_cbe_tmp__1747&1u))&1))) {
    goto llvm_cbe_tmp__1798;
  } else {
    goto llvm_cbe_tmp__1799;
  }

llvm_cbe_tmp__1798:
  *(&llvm_cbe_cppVar_919) = 0ull;
  goto llvm_cbe_tmp__1800;

llvm_cbe_tmp__1799:
  llvm_cbe_tmp__1748 = *((&llvm_cbe_tmp__1696->field30));
  *(&llvm_cbe_cppVar_922) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1748) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1749 = *(&llvm_cbe_cppVar_922);
  llvm_cbe_tmp__1750 = *((&llvm_cbe_tmp__1696->field39));
  *(&llvm_cbe_cppVar_922) = (llvm_cbe_tmp__1749 & llvm_cbe_tmp__1750);
  llvm_cbe_tmp__1751 = *(&llvm_cbe_cppVar_922);
  *(&llvm_cbe_cppVar_919) = llvm_cbe_tmp__1751;
  goto llvm_cbe_tmp__1800;

llvm_cbe_tmp__1800:
  llvm_cbe_tmp__1752 = *(&llvm_cbe_cppVar_919);
  *(&llvm_cbe_cppVar_917) = llvm_cbe_tmp__1752;
  goto llvm_cbe_tmp__1801;

llvm_cbe_tmp__1797:
  *(&llvm_cbe_cppVar_917) = llvm_cbe_tmp__1745;
  goto llvm_cbe_tmp__1801;

llvm_cbe_tmp__1801:
  llvm_cbe_tmp__1753 = *(&llvm_cbe_cppVar_917);
  *(&llvm_cbe_cppVar_914) = llvm_cbe_tmp__1753;
  goto llvm_cbe_tmp__1802;

llvm_cbe_tmp__1795:
  llvm_cbe_tmp__1754 = *((&llvm_cbe_tmp__1696->field29));
  *(&llvm_cbe_cppVar_925) = (((unsigned char )(bool )(llvm_cbe_tmp__1754 == 2ull)));
  llvm_cbe_tmp__1755 = *(&llvm_cbe_cppVar_925);
  if ((((((bool )llvm_cbe_tmp__1755&1u))&1))) {
    goto llvm_cbe_tmp__1803;
  } else {
    goto llvm_cbe_tmp__1804;
  }

llvm_cbe_tmp__1803:
  llvm_cbe_tmp__1756 = *((&llvm_cbe_tmp__1696->field25));
  llvm_cbe_tmp__1757 = *((&llvm_cbe_tmp__1696->field9));
  *(&llvm_cbe_cppVar_927) = (((unsigned char )(bool )(llvm_cbe_tmp__1756 == llvm_cbe_tmp__1757)));
  llvm_cbe_tmp__1758 = *(&llvm_cbe_cppVar_927);
  llvm_cbe_tmp__1759 = *((&llvm_cbe_tmp__1696->field30));
  if ((((((bool )llvm_cbe_tmp__1758&1u))&1))) {
    goto llvm_cbe_tmp__1805;
  } else {
    goto llvm_cbe_tmp__1806;
  }

llvm_cbe_tmp__1805:
  llvm_cbe_tmp__1760 = *((&llvm_cbe_tmp__1696->field14));
  *(&llvm_cbe_cppVar_929) = (((unsigned char )(bool )(llvm_cbe_tmp__1759 == llvm_cbe_tmp__1760)));
  llvm_cbe_tmp__1761 = *(&llvm_cbe_cppVar_929);
  llvm_cbe_tmp__1762 = *((&llvm_cbe_tmp__1696->field30));
  if ((((((bool )llvm_cbe_tmp__1761&1u))&1))) {
    goto llvm_cbe_tmp__1807;
  } else {
    goto llvm_cbe_tmp__1808;
  }

llvm_cbe_tmp__1807:
  *(&llvm_cbe_cppVar_928) = llvm_cbe_tmp__1762;
  goto llvm_cbe_tmp__1809;

llvm_cbe_tmp__1808:
  *(&llvm_cbe_cppVar_931) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1762) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1763 = *(&llvm_cbe_cppVar_931);
  llvm_cbe_tmp__1764 = *((&llvm_cbe_tmp__1696->field39));
  *(&llvm_cbe_cppVar_931) = (llvm_cbe_tmp__1763 & llvm_cbe_tmp__1764);
  llvm_cbe_tmp__1765 = *(&llvm_cbe_cppVar_931);
  *(&llvm_cbe_cppVar_928) = llvm_cbe_tmp__1765;
  goto llvm_cbe_tmp__1809;

llvm_cbe_tmp__1809:
  llvm_cbe_tmp__1766 = *(&llvm_cbe_cppVar_928);
  *(&llvm_cbe_cppVar_926) = llvm_cbe_tmp__1766;
  goto llvm_cbe_tmp__1810;

llvm_cbe_tmp__1806:
  *(&llvm_cbe_cppVar_926) = llvm_cbe_tmp__1759;
  goto llvm_cbe_tmp__1810;

llvm_cbe_tmp__1810:
  llvm_cbe_tmp__1767 = *(&llvm_cbe_cppVar_926);
  *(&llvm_cbe_cppVar_923) = llvm_cbe_tmp__1767;
  goto llvm_cbe_tmp__1811;

llvm_cbe_tmp__1804:
  llvm_cbe_tmp__1768 = *((&llvm_cbe_tmp__1696->field30));
  *(&llvm_cbe_cppVar_923) = llvm_cbe_tmp__1768;
  goto llvm_cbe_tmp__1811;

llvm_cbe_tmp__1811:
  llvm_cbe_tmp__1769 = *(&llvm_cbe_cppVar_923);
  *(&llvm_cbe_cppVar_914) = llvm_cbe_tmp__1769;
  goto llvm_cbe_tmp__1802;

llvm_cbe_tmp__1802:
  llvm_cbe_tmp__1770 = *(&llvm_cbe_cppVar_914);
  *(&llvm_cbe_cppVar_893) = llvm_cbe_tmp__1770;
  goto llvm_cbe_tmp__1793;

llvm_cbe_tmp__1793:
  llvm_cbe_tmp__1771 = *(&llvm_cbe_cppVar_893);
  *(&llvm_cbe_cppVar_885) = llvm_cbe_tmp__1771;
  goto llvm_cbe_tmp__1778;

llvm_cbe_tmp__1778:
  llvm_cbe_tmp__1772 = *(&llvm_cbe_cppVar_885);
  return llvm_cbe_tmp__1772;
}


unsigned long long _ZN11model_train16cppUpdateFun_upcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1812;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1813;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1814;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1815;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1816;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1817;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1818;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1819;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1820;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1821;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1822;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1823;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_946;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_934;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_935;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_937;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_938;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_940;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_941;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_943;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_944;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_945;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_942;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_939;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_936;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_933;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1824;
  unsigned long long llvm_cbe_tmp__1825;
  unsigned char llvm_cbe_tmp__1826;
  unsigned long long llvm_cbe_tmp__1827;
  unsigned long long llvm_cbe_tmp__1828;
  unsigned char llvm_cbe_tmp__1829;
  unsigned long long llvm_cbe_tmp__1830;
  unsigned long long llvm_cbe_tmp__1831;
  unsigned char llvm_cbe_tmp__1832;
  unsigned long long llvm_cbe_tmp__1833;
  unsigned long long llvm_cbe_tmp__1834;
  unsigned long long llvm_cbe_tmp__1835;
  unsigned long long llvm_cbe_tmp__1836;
  unsigned char llvm_cbe_tmp__1837;
  unsigned char llvm_cbe_tmp__1838;
  bool llvm_cbe_tmp__1839;
  bool llvm_cbe_tmp__1840;
  bool llvm_cbe_tmp__1840__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1841;
  unsigned long long llvm_cbe_tmp__1842;
  unsigned long long llvm_cbe_tmp__1843;
  unsigned long long llvm_cbe_tmp__1844;
  unsigned long long llvm_cbe_tmp__1845;
  unsigned long long llvm_cbe_tmp__1846;
  unsigned long long llvm_cbe_tmp__1847;

  *(&llvm_cbe_tmp__1812) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1813) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1814) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1815) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1816) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1817) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1818) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1819) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1820) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1821) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1822) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1823) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1824 = *(&llvm_cbe_tmp__1812);
  llvm_cbe_tmp__1825 = *((&llvm_cbe_tmp__1824->field29));
  *(&llvm_cbe_cppVar_935) = (((unsigned char )(bool )(llvm_cbe_tmp__1825 == 0ull)));
  llvm_cbe_tmp__1826 = *(&llvm_cbe_cppVar_935);
  if ((((((bool )llvm_cbe_tmp__1826&1u))&1))) {
    goto llvm_cbe_tmp__1848;
  } else {
    goto llvm_cbe_tmp__1849;
  }

llvm_cbe_tmp__1848:
  llvm_cbe_tmp__1827 = *((&llvm_cbe_tmp__1824->field31));
  *(&llvm_cbe_cppVar_933) = llvm_cbe_tmp__1827;
  goto llvm_cbe_tmp__1850;

llvm_cbe_tmp__1849:
  llvm_cbe_tmp__1828 = *((&llvm_cbe_tmp__1824->field29));
  *(&llvm_cbe_cppVar_938) = (((unsigned char )(bool )(llvm_cbe_tmp__1828 == 1ull)));
  llvm_cbe_tmp__1829 = *(&llvm_cbe_cppVar_938);
  if ((((((bool )llvm_cbe_tmp__1829&1u))&1))) {
    goto llvm_cbe_tmp__1851;
  } else {
    goto llvm_cbe_tmp__1852;
  }

llvm_cbe_tmp__1851:
  llvm_cbe_tmp__1830 = *((&llvm_cbe_tmp__1824->field31));
  *(&llvm_cbe_cppVar_936) = llvm_cbe_tmp__1830;
  goto llvm_cbe_tmp__1853;

llvm_cbe_tmp__1852:
  llvm_cbe_tmp__1831 = *((&llvm_cbe_tmp__1824->field29));
  *(&llvm_cbe_cppVar_941) = (((unsigned char )(bool )(llvm_cbe_tmp__1831 == 2ull)));
  llvm_cbe_tmp__1832 = *(&llvm_cbe_cppVar_941);
  if ((((((bool )llvm_cbe_tmp__1832&1u))&1))) {
    goto llvm_cbe_tmp__1854;
  } else {
    goto llvm_cbe_tmp__1855;
  }

llvm_cbe_tmp__1854:
  llvm_cbe_tmp__1833 = *((&llvm_cbe_tmp__1824->field25));
  llvm_cbe_tmp__1834 = *((&llvm_cbe_tmp__1824->field9));
  *(&llvm_cbe_cppVar_943) = (((unsigned char )(bool )(llvm_cbe_tmp__1833 == llvm_cbe_tmp__1834)));
  llvm_cbe_tmp__1835 = *((&llvm_cbe_tmp__1824->field30));
  llvm_cbe_tmp__1836 = *((&llvm_cbe_tmp__1824->field14));
  *(&llvm_cbe_cppVar_944) = (((unsigned char )(bool )(llvm_cbe_tmp__1835 == llvm_cbe_tmp__1836)));
  llvm_cbe_tmp__1837 = *(&llvm_cbe_cppVar_943);
  if ((((((bool )llvm_cbe_tmp__1837&1u))&1))) {
    goto llvm_cbe_tmp__1856;
  } else {
    llvm_cbe_tmp__1840__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1857;
  }

llvm_cbe_tmp__1856:
  llvm_cbe_tmp__1838 = *(&llvm_cbe_cppVar_944);
  llvm_cbe_tmp__1839 = ((((bool )llvm_cbe_tmp__1838&1u))&1);
  llvm_cbe_tmp__1840__PHI_TEMPORARY = llvm_cbe_tmp__1839;   /* for PHI node */
  goto llvm_cbe_tmp__1857;

llvm_cbe_tmp__1857:
  llvm_cbe_tmp__1840 = ((llvm_cbe_tmp__1840__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_945) = (((unsigned char )(bool )llvm_cbe_tmp__1840));
  llvm_cbe_tmp__1841 = *(&llvm_cbe_cppVar_945);
  if ((((((bool )llvm_cbe_tmp__1841&1u))&1))) {
    goto llvm_cbe_tmp__1858;
  } else {
    goto llvm_cbe_tmp__1859;
  }

llvm_cbe_tmp__1858:
  *(&llvm_cbe_cppVar_942) = 0ull;
  goto llvm_cbe_tmp__1860;

llvm_cbe_tmp__1859:
  llvm_cbe_tmp__1842 = *((&llvm_cbe_tmp__1824->field31));
  *(&llvm_cbe_cppVar_942) = llvm_cbe_tmp__1842;
  goto llvm_cbe_tmp__1860;

llvm_cbe_tmp__1860:
  llvm_cbe_tmp__1843 = *(&llvm_cbe_cppVar_942);
  *(&llvm_cbe_cppVar_939) = llvm_cbe_tmp__1843;
  goto llvm_cbe_tmp__1861;

llvm_cbe_tmp__1855:
  llvm_cbe_tmp__1844 = *((&llvm_cbe_tmp__1824->field31));
  *(&llvm_cbe_cppVar_939) = llvm_cbe_tmp__1844;
  goto llvm_cbe_tmp__1861;

llvm_cbe_tmp__1861:
  llvm_cbe_tmp__1845 = *(&llvm_cbe_cppVar_939);
  *(&llvm_cbe_cppVar_936) = llvm_cbe_tmp__1845;
  goto llvm_cbe_tmp__1853;

llvm_cbe_tmp__1853:
  llvm_cbe_tmp__1846 = *(&llvm_cbe_cppVar_936);
  *(&llvm_cbe_cppVar_933) = llvm_cbe_tmp__1846;
  goto llvm_cbe_tmp__1850;

llvm_cbe_tmp__1850:
  llvm_cbe_tmp__1847 = *(&llvm_cbe_cppVar_933);
  return llvm_cbe_tmp__1847;
}


struct l_unnamed2 _ZN11model_train28cppUpdateFun_visibleEnergiesElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_unnamed2 StructReturn;  /* Struct return temporary */
  struct l_unnamed2 *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__1862;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1863;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1864;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1865;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1866;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1867;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1868;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1869;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1870;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1871;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1872;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1873;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1088;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1089;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1091;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1092;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1142;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1143;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1109;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1110;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1111;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1098;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1094;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1095;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1096;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1120;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1121;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1122;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1134;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1135;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1136;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1138;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1139;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1140;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1101;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1102;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1100;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1105;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1106;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1107;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1108;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1112;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1113;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1114;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1115;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1116;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1104;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1117;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1099;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1118;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1097;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1874;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1875;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1129;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1127;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1128;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1130;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1126;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1124;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1125;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1131;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1123;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1132;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1137;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1133;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1119;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1093;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1141;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1090;    /* Address-exposed local */
  bool llvm_cbe_tmp__1876;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1103;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1877;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1878;
  unsigned long long llvm_cbe_tmp__1879;
  unsigned char llvm_cbe_tmp__1880;
  struct l_unnamed2 *llvm_cbe_tmp__1881;
  unsigned long long llvm_cbe_tmp__1882;
  unsigned char llvm_cbe_tmp__1883;
  unsigned long long llvm_cbe_tmp__1884;
  unsigned char llvm_cbe_tmp__1885;
  unsigned char llvm_cbe_tmp__1886;
  bool llvm_cbe_tmp__1887;
  bool llvm_cbe_tmp__1888;
  bool llvm_cbe_tmp__1888__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1889;
  unsigned long long llvm_cbe_tmp__1890;
  unsigned long long llvm_cbe_tmp__1891;
  unsigned char llvm_cbe_tmp__1892;
  unsigned long long llvm_cbe_tmp__1893;
  unsigned long long llvm_cbe_tmp__1894;
  unsigned long long llvm_cbe_tmp__1895;
  unsigned char llvm_cbe_tmp__1896;
  unsigned long long llvm_cbe_tmp__1897;
  unsigned long long llvm_cbe_tmp__1898;
  unsigned long long llvm_cbe_tmp__1899;
  unsigned long long llvm_cbe_tmp__1900;
  unsigned long long llvm_cbe_tmp__1901;
  unsigned long long llvm_cbe_tmp__1902;
  unsigned char llvm_cbe_tmp__1903;
  unsigned long long llvm_cbe_tmp__1904;
  unsigned long long llvm_cbe_tmp__1905;
  unsigned long long llvm_cbe_tmp__1906;
  unsigned long long llvm_cbe_tmp__1907;
  unsigned long long llvm_cbe_tmp__1908;
  unsigned long long llvm_cbe_tmp__1909;
  unsigned long long llvm_cbe_tmp__1910;
  unsigned long long llvm_cbe_tmp__1911;
  unsigned long long llvm_cbe_tmp__1912;
  unsigned long long llvm_cbe_tmp__1913;
  unsigned long long llvm_cbe_tmp__1914;
  unsigned long long llvm_cbe_tmp__1915;
  unsigned long long llvm_cbe_tmp__1916;
  unsigned long long llvm_cbe_tmp__1917;
  unsigned long long llvm_cbe_tmp__1918;
  unsigned long long llvm_cbe_tmp__1919;
  unsigned long long llvm_cbe_tmp__1920;
  unsigned long long llvm_cbe_tmp__1920__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1921;
  unsigned long long llvm_cbe_tmp__1922;
  unsigned long long llvm_cbe_tmp__1923;
  unsigned long long llvm_cbe_tmp__1924;
  unsigned long long llvm_cbe_tmp__1925;
  unsigned long long llvm_cbe_tmp__1926;
  unsigned long long llvm_cbe_tmp__1927;
  unsigned long long llvm_cbe_tmp__1928;
  unsigned long long llvm_cbe_tmp__1929;
  unsigned long long llvm_cbe_tmp__1930;
  unsigned long long llvm_cbe_tmp__1931;
  struct l_unnamed2 *llvm_cbe_tmp__1932;
  unsigned long long llvm_cbe_tmp__1933;
  unsigned long long llvm_cbe_tmp__1934;
  struct l_unnamed2 *llvm_cbe_tmp__1935;
  struct l_unnamed2 *llvm_cbe_tmp__1936;
  struct l_unnamed2 *llvm_cbe_tmp__1937;
  unsigned long long llvm_cbe_tmp__1938;
  unsigned char llvm_cbe_tmp__1939;
  unsigned char llvm_cbe_tmp__1940;
  bool llvm_cbe_tmp__1941;
  bool llvm_cbe_tmp__1942;
  bool llvm_cbe_tmp__1942__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1943;
  unsigned long long llvm_cbe_tmp__1944;
  unsigned long long llvm_cbe_tmp__1945;
  unsigned long long llvm_cbe_tmp__1946;
  unsigned long long llvm_cbe_tmp__1947;
  unsigned long long llvm_cbe_tmp__1948;
  unsigned long long llvm_cbe_tmp__1949;
  unsigned long long llvm_cbe_tmp__1950;
  unsigned char llvm_cbe_tmp__1951;
  unsigned long long llvm_cbe_tmp__1952;
  unsigned long long llvm_cbe_tmp__1953;
  unsigned long long llvm_cbe_tmp__1954;
  unsigned long long llvm_cbe_tmp__1955;
  unsigned long long llvm_cbe_tmp__1956;
  unsigned long long llvm_cbe_tmp__1957;
  unsigned long long llvm_cbe_tmp__1958;
  unsigned long long llvm_cbe_tmp__1959;
  struct l_unnamed2 *llvm_cbe_tmp__1960;
  unsigned long long llvm_cbe_tmp__1961;
  unsigned long long llvm_cbe_tmp__1962;
  struct l_unnamed2 *llvm_cbe_tmp__1963;
  unsigned long long llvm_cbe_tmp__1964;
  unsigned char llvm_cbe_tmp__1965;
  unsigned char llvm_cbe_tmp__1966;
  bool llvm_cbe_tmp__1967;
  bool llvm_cbe_tmp__1968;
  bool llvm_cbe_tmp__1968__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1969;
  struct l_unnamed2 *llvm_cbe_tmp__1970;
  unsigned long long llvm_cbe_tmp__1971;
  unsigned char llvm_cbe_tmp__1972;
  unsigned char llvm_cbe_tmp__1973;
  bool llvm_cbe_tmp__1974;
  bool llvm_cbe_tmp__1975;
  bool llvm_cbe_tmp__1975__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1976;
  bool llvm_cbe_tmp__1977;
  struct l_unnamed2 *llvm_cbe_tmp__1978;
  struct l_unnamed2 *llvm_cbe_tmp__1979;
  struct l_unnamed2 *llvm_cbe_tmp__1980;
  struct l_unnamed2 *llvm_cbe_tmp__1981;
  struct l_unnamed2 *llvm_cbe_tmp__1982;
  unsigned long long llvm_cbe_tmp__1983;
  unsigned char llvm_cbe_tmp__1984;
  bool llvm_cbe_tmp__1985;
  struct l_unnamed2 *llvm_cbe_tmp__1986;
  struct l_unnamed2 *llvm_cbe_tmp__1987;
  struct l_unnamed2 *llvm_cbe_tmp__1988;
  bool llvm_cbe_tmp__1989;

  *(&llvm_cbe_tmp__1862) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1863) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1864) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1865) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1866) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1867) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1868) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1869) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1870) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1871) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1872) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1873) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1878 = *(&llvm_cbe_tmp__1862);
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1118));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1097));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1132));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1137));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1133));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1119));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1093));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1141));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1090));
  *(&llvm_cbe_tmp__1876) = ((0) & 1);
  _ZN8type_memItLj8EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__1879 = *((&llvm_cbe_tmp__1878->field29));
  *(&llvm_cbe_cppVar_1089) = (((unsigned char )(bool )(llvm_cbe_tmp__1879 == 0ull)));
  llvm_cbe_tmp__1880 = *(&llvm_cbe_cppVar_1089);
  if ((((((bool )llvm_cbe_tmp__1880&1u))&1))) {
    goto llvm_cbe_tmp__1990;
  } else {
    goto llvm_cbe_tmp__1991;
  }

llvm_cbe_tmp__1990:
  llvm_cbe_tmp__1881 = _ZN8type_memItLj8EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__1878->field32)));
  goto llvm_cbe_tmp__1992;

llvm_cbe_tmp__1991:
  llvm_cbe_tmp__1882 = *((&llvm_cbe_tmp__1878->field29));
  *(&llvm_cbe_cppVar_1092) = (((unsigned char )(bool )(llvm_cbe_tmp__1882 == 1ull)));
  llvm_cbe_tmp__1883 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1883&1u))&1))) {
    goto llvm_cbe_tmp__1993;
  } else {
    goto llvm_cbe_tmp__1994;
  }

llvm_cbe_tmp__1993:
  llvm_cbe_tmp__1884 = *((&llvm_cbe_tmp__1878->field15));
  *(&llvm_cbe_cppVar_1095) = (((unsigned char )(bool )(llvm_cbe_tmp__1884 == 0ull)));
  llvm_cbe_tmp__1885 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1885&1u))&1))) {
    goto llvm_cbe_tmp__1995;
  } else {
    llvm_cbe_tmp__1888__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1996;
  }

llvm_cbe_tmp__1995:
  llvm_cbe_tmp__1886 = *(&llvm_cbe_cppVar_1095);
  llvm_cbe_tmp__1887 = ((((bool )llvm_cbe_tmp__1886&1u))&1);
  llvm_cbe_tmp__1888__PHI_TEMPORARY = llvm_cbe_tmp__1887;   /* for PHI node */
  goto llvm_cbe_tmp__1996;

llvm_cbe_tmp__1996:
  llvm_cbe_tmp__1888 = ((llvm_cbe_tmp__1888__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1096) = (((unsigned char )(bool )llvm_cbe_tmp__1888));
  llvm_cbe_tmp__1889 = *(&llvm_cbe_cppVar_1096);
  if ((((((bool )llvm_cbe_tmp__1889&1u))&1))) {
    goto llvm_cbe_tmp__1997;
  } else {
    goto llvm_cbe_tmp__1998;
  }

llvm_cbe_tmp__1997:
  llvm_cbe_tmp__1890 = *((&llvm_cbe_tmp__1878->field25));
  llvm_cbe_tmp__1891 = *((&llvm_cbe_tmp__1878->field9));
  *(&llvm_cbe_cppVar_1098) = (((unsigned char )(bool )(llvm_cbe_tmp__1890 == llvm_cbe_tmp__1891)));
  llvm_cbe_tmp__1892 = *(&llvm_cbe_cppVar_1098);
  if ((((((bool )llvm_cbe_tmp__1892&1u))&1))) {
    goto llvm_cbe_tmp__1999;
  } else {
    goto llvm_cbe_tmp__2000;
  }

llvm_cbe_tmp__1999:
  llvm_cbe_tmp__1893 = *((&llvm_cbe_tmp__1878->field7));
  llvm_cbe_tmp__1894 = *((&llvm_cbe_tmp__1878->field40));
  *(&llvm_cbe_cppVar_1099) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1893) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1894);
  llvm_cbe_tmp__1895 = *((&llvm_cbe_tmp__1878->field25));
  *(&llvm_cbe_cppVar_1102) = (((unsigned char )(bool )(llvm_cbe_tmp__1895 == 0ull)));
  llvm_cbe_tmp__1896 = *(&llvm_cbe_cppVar_1102);
  if ((((((bool )llvm_cbe_tmp__1896&1u))&1))) {
    goto llvm_cbe_tmp__2001;
  } else {
    goto llvm_cbe_tmp__2002;
  }

llvm_cbe_tmp__2001:
  *(&llvm_cbe_cppVar_1100) = 0ull;
  goto llvm_cbe_tmp__2003;

llvm_cbe_tmp__2002:
  llvm_cbe_tmp__1897 = *((&llvm_cbe_tmp__1878->field28));
  *(&llvm_cbe_cppVar_1100) = llvm_cbe_tmp__1897;
  goto llvm_cbe_tmp__2003;

llvm_cbe_tmp__2003:
  llvm_cbe_tmp__1898 = *((&llvm_cbe_tmp__1878->field25));
  llvm_cbe_tmp__1899 = *((&llvm_cbe_tmp__1878->field43));
  *(&llvm_cbe_cppVar_1105) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1898) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1899);
  llvm_cbe_tmp__1900 = *(&llvm_cbe_cppVar_1105);
  llvm_cbe_tmp__1901 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__1878->field4)), llvm_cbe_tmp__1900);
  *(&llvm_cbe_cppVar_1106) = llvm_cbe_tmp__1901;
  llvm_cbe_tmp__1902 = *(&llvm_cbe_cppVar_1106);
  *(&llvm_cbe_cppVar_1108) = (((unsigned char )(bool )(llvm_cbe_tmp__1902 == 1ull)));
  llvm_cbe_tmp__1903 = *(&llvm_cbe_cppVar_1108);
  if ((((((bool )llvm_cbe_tmp__1903&1u))&1))) {
    goto llvm_cbe_tmp__2004;
  } else {
    goto llvm_cbe_tmp__2005;
  }

llvm_cbe_tmp__2004:
  llvm_cbe_tmp__1904 = *((&llvm_cbe_tmp__1878->field30));
  *(&llvm_cbe_cppVar_1110) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__1904))));
  llvm_cbe_tmp__1905 = *(&llvm_cbe_cppVar_1110);
  llvm_cbe_tmp__1906 = *((&llvm_cbe_tmp__1878->field39));
  *(&llvm_cbe_cppVar_1110) = (llvm_cbe_tmp__1905 & llvm_cbe_tmp__1906);
  llvm_cbe_tmp__1907 = *(&llvm_cbe_cppVar_1110);
  llvm_cbe_tmp__1908 = *((&llvm_cbe_tmp__1878->field25));
  *(&llvm_cbe_cppVar_1111) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1907) + ((unsigned long long )llvm_cbe_tmp__1908))));
  llvm_cbe_tmp__1909 = *(&llvm_cbe_cppVar_1111);
  llvm_cbe_tmp__1910 = *((&llvm_cbe_tmp__1878->field39));
  *(&llvm_cbe_cppVar_1111) = (llvm_cbe_tmp__1909 & llvm_cbe_tmp__1910);
  llvm_cbe_tmp__1911 = *(&llvm_cbe_cppVar_1111);
  llvm_cbe_tmp__1912 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1878->field3)), llvm_cbe_tmp__1911);
  *(&llvm_cbe_cppVar_1112) = llvm_cbe_tmp__1912;
  llvm_cbe_tmp__1913 = *(&llvm_cbe_cppVar_1112);
  llvm_cbe_tmp__1914 = *((&llvm_cbe_tmp__1878->field43));
  *(&llvm_cbe_cppVar_1113) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1913) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1914);
  llvm_cbe_tmp__1915 = *(&llvm_cbe_cppVar_1113);
  llvm_cbe_tmp__1916 = *((&llvm_cbe_tmp__1878->field47));
  llvm_cbe_tmp__1917 = *(&llvm_cbe_cppVar_1113);
  if (((llvm_cbe_tmp__1915 & llvm_cbe_tmp__1916) != 0ull)) {
    goto llvm_cbe_tmp__2006;
  } else {
    llvm_cbe_tmp__1920__PHI_TEMPORARY = llvm_cbe_tmp__1917;   /* for PHI node */
    goto llvm_cbe_tmp__2007;
  }

llvm_cbe_tmp__2006:
  llvm_cbe_tmp__1918 = *((&llvm_cbe_tmp__1878->field49));
  llvm_cbe_tmp__1919 = llvm_cbe_tmp__1917 | llvm_cbe_tmp__1918;
  llvm_cbe_tmp__1920__PHI_TEMPORARY = llvm_cbe_tmp__1919;   /* for PHI node */
  goto llvm_cbe_tmp__2007;

llvm_cbe_tmp__2007:
  llvm_cbe_tmp__1920 = llvm_cbe_tmp__1920__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_1114) = llvm_cbe_tmp__1920;
  llvm_cbe_tmp__1921 = *(&llvm_cbe_cppVar_1112);
  llvm_cbe_tmp__1922 = *((&llvm_cbe_tmp__1878->field38));
  *(&llvm_cbe_cppVar_1115) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1921) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1922);
  llvm_cbe_tmp__1923 = *(&llvm_cbe_cppVar_1114);
  llvm_cbe_tmp__1924 = *(&llvm_cbe_cppVar_1115);
  *(&llvm_cbe_cppVar_1116) = ((llvm_cbe_tmp__1923 << 1ull) | llvm_cbe_tmp__1924);
  llvm_cbe_tmp__1925 = *(&llvm_cbe_cppVar_1116);
  llvm_cbe_tmp__1926 = *((&llvm_cbe_tmp__1878->field39));
  *(&llvm_cbe_cppVar_1116) = (llvm_cbe_tmp__1925 & llvm_cbe_tmp__1926);
  llvm_cbe_tmp__1927 = *(&llvm_cbe_cppVar_1116);
  *(&llvm_cbe_cppVar_1104) = llvm_cbe_tmp__1927;
  goto llvm_cbe_tmp__2008;

llvm_cbe_tmp__2005:
  *(&llvm_cbe_cppVar_1104) = 0ull;
  goto llvm_cbe_tmp__2008;

llvm_cbe_tmp__2008:
  llvm_cbe_tmp__1928 = *(&llvm_cbe_cppVar_1100);
  llvm_cbe_tmp__1929 = *(&llvm_cbe_cppVar_1104);
  *(&llvm_cbe_cppVar_1117) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1928) + ((unsigned long long )llvm_cbe_tmp__1929))));
  llvm_cbe_tmp__1930 = *(&llvm_cbe_cppVar_1117);
  llvm_cbe_tmp__1931 = *((&llvm_cbe_tmp__1878->field39));
  *(&llvm_cbe_cppVar_1117) = (llvm_cbe_tmp__1930 & llvm_cbe_tmp__1931);
  llvm_cbe_tmp__1932 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1118), ((&llvm_cbe_tmp__1878->field32)));
  llvm_cbe_tmp__1933 = *(&llvm_cbe_cppVar_1099);
  llvm_cbe_tmp__1934 = *(&llvm_cbe_cppVar_1117);
  _ZN8type_memItLj8EE2wrEll((&llvm_cbe_cppVar_1118), llvm_cbe_tmp__1933, llvm_cbe_tmp__1934);
  llvm_cbe_tmp__1935 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1097), (&llvm_cbe_cppVar_1118));
  goto llvm_cbe_tmp__2009;

llvm_cbe_tmp__2000:
  llvm_cbe_tmp__1936 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1097), ((&llvm_cbe_tmp__1878->field32)));
  goto llvm_cbe_tmp__2009;

llvm_cbe_tmp__2009:
  llvm_cbe_tmp__1937 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1093), (&llvm_cbe_cppVar_1097));
  goto llvm_cbe_tmp__2010;

llvm_cbe_tmp__1998:
  llvm_cbe_tmp__1938 = *((&llvm_cbe_tmp__1878->field15));
  *(&llvm_cbe_cppVar_1121) = (((unsigned char )(bool )(llvm_cbe_tmp__1938 == 1ull)));
  llvm_cbe_tmp__1939 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1939&1u))&1))) {
    goto llvm_cbe_tmp__2011;
  } else {
    llvm_cbe_tmp__1942__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2012;
  }

llvm_cbe_tmp__2011:
  llvm_cbe_tmp__1940 = *(&llvm_cbe_cppVar_1121);
  llvm_cbe_tmp__1941 = ((((bool )llvm_cbe_tmp__1940&1u))&1);
  llvm_cbe_tmp__1942__PHI_TEMPORARY = llvm_cbe_tmp__1941;   /* for PHI node */
  goto llvm_cbe_tmp__2012;

llvm_cbe_tmp__2012:
  llvm_cbe_tmp__1942 = ((llvm_cbe_tmp__1942__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1122) = (((unsigned char )(bool )llvm_cbe_tmp__1942));
  llvm_cbe_tmp__1943 = *(&llvm_cbe_cppVar_1122);
  if ((((((bool )llvm_cbe_tmp__1943&1u))&1))) {
    goto llvm_cbe_tmp__2013;
  } else {
    goto llvm_cbe_tmp__2014;
  }

llvm_cbe_tmp__2013:
  llvm_cbe_tmp__1944 = *((&llvm_cbe_tmp__1878->field7));
  llvm_cbe_tmp__1945 = *((&llvm_cbe_tmp__1878->field40));
  *(&llvm_cbe_cppVar_1123) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1944) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1945);
  llvm_cbe_tmp__1946 = *((&llvm_cbe_tmp__1878->field7));
  llvm_cbe_tmp__1947 = *((&llvm_cbe_tmp__1878->field40));
  *(&llvm_cbe_cppVar_1124) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1946) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1947);
  llvm_cbe_tmp__1948 = *(&llvm_cbe_cppVar_1124);
  llvm_cbe_tmp__1949 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__1878->field32)), llvm_cbe_tmp__1948);
  *(&llvm_cbe_cppVar_1125) = llvm_cbe_tmp__1949;
  llvm_cbe_tmp__1950 = *((&llvm_cbe_tmp__1878->field7));
  *(&llvm_cbe_cppVar_1128) = (((unsigned char )(bool )(llvm_cbe_tmp__1950 == 0ull)));
  llvm_cbe_tmp__1951 = *(&llvm_cbe_cppVar_1128);
  llvm_cbe_tmp__1952 = *((&llvm_cbe_tmp__1878->field27));
  if ((((((bool )llvm_cbe_tmp__1951&1u))&1))) {
    goto llvm_cbe_tmp__2015;
  } else {
    goto llvm_cbe_tmp__2016;
  }

llvm_cbe_tmp__2015:
  *(&llvm_cbe_cppVar_1130) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1952) - ((unsigned long long )62ull))));
  llvm_cbe_tmp__1953 = *(&llvm_cbe_cppVar_1130);
  llvm_cbe_tmp__1954 = *((&llvm_cbe_tmp__1878->field39));
  *(&llvm_cbe_cppVar_1130) = (llvm_cbe_tmp__1953 & llvm_cbe_tmp__1954);
  llvm_cbe_tmp__1955 = *(&llvm_cbe_cppVar_1130);
  *(&llvm_cbe_cppVar_1126) = llvm_cbe_tmp__1955;
  goto llvm_cbe_tmp__2017;

llvm_cbe_tmp__2016:
  *(&llvm_cbe_cppVar_1126) = llvm_cbe_tmp__1952;
  goto llvm_cbe_tmp__2017;

llvm_cbe_tmp__2017:
  llvm_cbe_tmp__1956 = *(&llvm_cbe_cppVar_1125);
  llvm_cbe_tmp__1957 = *(&llvm_cbe_cppVar_1126);
  *(&llvm_cbe_cppVar_1131) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1956) - ((unsigned long long )llvm_cbe_tmp__1957))));
  llvm_cbe_tmp__1958 = *(&llvm_cbe_cppVar_1131);
  llvm_cbe_tmp__1959 = *((&llvm_cbe_tmp__1878->field39));
  *(&llvm_cbe_cppVar_1131) = (llvm_cbe_tmp__1958 & llvm_cbe_tmp__1959);
  llvm_cbe_tmp__1960 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1132), ((&llvm_cbe_tmp__1878->field32)));
  llvm_cbe_tmp__1961 = *(&llvm_cbe_cppVar_1123);
  llvm_cbe_tmp__1962 = *(&llvm_cbe_cppVar_1131);
  _ZN8type_memItLj8EE2wrEll((&llvm_cbe_cppVar_1132), llvm_cbe_tmp__1961, llvm_cbe_tmp__1962);
  llvm_cbe_tmp__1963 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1119), (&llvm_cbe_cppVar_1132));
  goto llvm_cbe_tmp__2018;

llvm_cbe_tmp__2014:
  llvm_cbe_tmp__1964 = *((&llvm_cbe_tmp__1878->field15));
  *(&llvm_cbe_cppVar_1135) = (((unsigned char )(bool )(llvm_cbe_tmp__1964 == 2ull)));
  llvm_cbe_tmp__1965 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1965&1u))&1))) {
    goto llvm_cbe_tmp__2019;
  } else {
    llvm_cbe_tmp__1968__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2020;
  }

llvm_cbe_tmp__2019:
  llvm_cbe_tmp__1966 = *(&llvm_cbe_cppVar_1135);
  llvm_cbe_tmp__1967 = ((((bool )llvm_cbe_tmp__1966&1u))&1);
  llvm_cbe_tmp__1968__PHI_TEMPORARY = llvm_cbe_tmp__1967;   /* for PHI node */
  goto llvm_cbe_tmp__2020;

llvm_cbe_tmp__2020:
  llvm_cbe_tmp__1968 = ((llvm_cbe_tmp__1968__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1136) = (((unsigned char )(bool )llvm_cbe_tmp__1968));
  llvm_cbe_tmp__1969 = *(&llvm_cbe_cppVar_1136);
  if ((((((bool )llvm_cbe_tmp__1969&1u))&1))) {
    goto llvm_cbe_tmp__2021;
  } else {
    goto llvm_cbe_tmp__2022;
  }

llvm_cbe_tmp__2021:
  llvm_cbe_tmp__1970 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1133), ((&llvm_cbe_tmp__1878->field32)));
  goto llvm_cbe_tmp__2023;

llvm_cbe_tmp__2022:
  llvm_cbe_tmp__1971 = *((&llvm_cbe_tmp__1878->field15));
  *(&llvm_cbe_cppVar_1139) = (((unsigned char )(bool )(llvm_cbe_tmp__1971 == 3ull)));
  llvm_cbe_tmp__1972 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1972&1u))&1))) {
    goto llvm_cbe_tmp__2024;
  } else {
    llvm_cbe_tmp__1975__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2025;
  }

llvm_cbe_tmp__2024:
  llvm_cbe_tmp__1973 = *(&llvm_cbe_cppVar_1139);
  llvm_cbe_tmp__1974 = ((((bool )llvm_cbe_tmp__1973&1u))&1);
  llvm_cbe_tmp__1975__PHI_TEMPORARY = llvm_cbe_tmp__1974;   /* for PHI node */
  goto llvm_cbe_tmp__2025;

llvm_cbe_tmp__2025:
  llvm_cbe_tmp__1975 = ((llvm_cbe_tmp__1975__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1140) = (((unsigned char )(bool )llvm_cbe_tmp__1975));
  llvm_cbe_tmp__1976 = *(&llvm_cbe_cppVar_1140);
  llvm_cbe_tmp__1977 = ((((bool )llvm_cbe_tmp__1976&1u))&1);
  llvm_cbe_tmp__1978 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1137), ((&llvm_cbe_tmp__1878->field32)));
  llvm_cbe_tmp__1979 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1133), (&llvm_cbe_cppVar_1137));
  goto llvm_cbe_tmp__2023;

llvm_cbe_tmp__2023:
  llvm_cbe_tmp__1980 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1119), (&llvm_cbe_cppVar_1133));
  goto llvm_cbe_tmp__2018;

llvm_cbe_tmp__2018:
  llvm_cbe_tmp__1981 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1093), (&llvm_cbe_cppVar_1119));
  goto llvm_cbe_tmp__2010;

llvm_cbe_tmp__2010:
  llvm_cbe_tmp__1982 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1090), (&llvm_cbe_cppVar_1093));
  goto llvm_cbe_tmp__2026;

llvm_cbe_tmp__1994:
  llvm_cbe_tmp__1983 = *((&llvm_cbe_tmp__1878->field29));
  *(&llvm_cbe_cppVar_1143) = (((unsigned char )(bool )(llvm_cbe_tmp__1983 == 2ull)));
  llvm_cbe_tmp__1984 = *(&llvm_cbe_cppVar_1143);
  llvm_cbe_tmp__1985 = ((((bool )llvm_cbe_tmp__1984&1u))&1);
  llvm_cbe_tmp__1986 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1141), ((&llvm_cbe_tmp__1878->field32)));
  llvm_cbe_tmp__1987 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1090), (&llvm_cbe_cppVar_1141));
  goto llvm_cbe_tmp__2026;

llvm_cbe_tmp__2026:
  llvm_cbe_tmp__1988 = _ZN8type_memItLj8EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1090));
  goto llvm_cbe_tmp__1992;

llvm_cbe_tmp__1992:
  *(&llvm_cbe_tmp__1876) = ((1) & 1);
  *(&llvm_cbe_tmp__1877) = 1u;
  llvm_cbe_tmp__1989 = ((*(&llvm_cbe_tmp__1876))&1);
  if (llvm_cbe_tmp__1989) {
    goto llvm_cbe_tmp__2027;
  } else {
    goto llvm_cbe_tmp__2028;
  }

llvm_cbe_tmp__2028:
  _ZN8type_memItLj8EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__2027;

llvm_cbe_tmp__2027:
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1090));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1141));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1093));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1119));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1133));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1137));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1132));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1097));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1118));
  return StructReturn;
}


void _ZN8type_memItLj8EEC1Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__2029;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2030;

  *(&llvm_cbe_tmp__2029) = llvm_cbe_this;
  llvm_cbe_tmp__2030 = *(&llvm_cbe_tmp__2029);
  _ZN8type_memItLj8EEC2Ev(llvm_cbe_tmp__2030);
  return;
}


struct l_unnamed2 *_ZN8type_memItLj8EEaSERKS0_(struct l_unnamed2 *llvm_cbe_this, struct l_unnamed2 *llvm_cbe_r) {
  struct l_unnamed2 *llvm_cbe_tmp__2031;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2032;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2033;
  unsigned short *llvm_cbe_tmp__2034;
  struct l_unnamed2 *llvm_cbe_tmp__2035;
  unsigned short *llvm_cbe_tmp__2036;

  *(&llvm_cbe_tmp__2031) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2032) = llvm_cbe_r;
  llvm_cbe_tmp__2033 = *(&llvm_cbe_tmp__2031);
  llvm_cbe_tmp__2034 = *((&llvm_cbe_tmp__2033->field0));
  llvm_cbe_tmp__2035 = *(&llvm_cbe_tmp__2032);
  llvm_cbe_tmp__2036 = *((&llvm_cbe_tmp__2035->field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__2034)), (((unsigned char *)llvm_cbe_tmp__2036)));
  return llvm_cbe_tmp__2033;
}


void _ZN8type_memItLj8EE2wrEll(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_unnamed2 *llvm_cbe_tmp__2037;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2038;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2039;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2040;
  unsigned long long llvm_cbe_tmp__2041;
  unsigned long long llvm_cbe_tmp__2042;
  unsigned short *llvm_cbe_tmp__2043;

  *(&llvm_cbe_tmp__2037) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2038) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__2039) = llvm_cbe_data;
  llvm_cbe_tmp__2040 = *(&llvm_cbe_tmp__2037);
  llvm_cbe_tmp__2041 = *(&llvm_cbe_tmp__2039);
  llvm_cbe_tmp__2042 = *(&llvm_cbe_tmp__2038);
  llvm_cbe_tmp__2043 = *((&llvm_cbe_tmp__2040->field0));
  *((&llvm_cbe_tmp__2043[((signed long long )llvm_cbe_tmp__2042)])) = (((unsigned short )llvm_cbe_tmp__2041));
  return;
}


void _ZN8type_memItLj8EED1Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__2044;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2045;

  *(&llvm_cbe_tmp__2044) = llvm_cbe_this;
  llvm_cbe_tmp__2045 = *(&llvm_cbe_tmp__2044);
  _ZN8type_memItLj8EED2Ev(llvm_cbe_tmp__2045);
  return;
}


struct l_class_OC_SysCArray1D _ZN11model_train25cppUpdateFun_visible_unitElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__2046;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2047;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2048;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2049;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2050;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2051;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2052;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2053;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2054;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2055;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2056;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2057;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1146;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1147;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1149;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1150;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1193;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1194;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1168;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1169;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1170;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1171;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1172;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1173;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1174;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1175;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1176;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1177;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1152;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1153;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1154;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1156;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1157;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1158;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1160;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1161;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1162;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1164;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1165;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1166;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1182;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1183;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1184;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1185;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1186;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1181;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1179;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1180;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1189;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1178;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1190;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1191;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2058;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2059;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1167;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1163;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1159;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1155;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1151;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1188;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1187;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1192;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1148;    /* Address-exposed local */
  bool llvm_cbe_tmp__2060;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2061;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__2062;
  unsigned long long llvm_cbe_tmp__2063;
  unsigned char llvm_cbe_tmp__2064;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2065;
  unsigned long long llvm_cbe_tmp__2066;
  unsigned char llvm_cbe_tmp__2067;
  unsigned long long llvm_cbe_tmp__2068;
  unsigned char llvm_cbe_tmp__2069;
  unsigned char llvm_cbe_tmp__2070;
  bool llvm_cbe_tmp__2071;
  bool llvm_cbe_tmp__2072;
  bool llvm_cbe_tmp__2072__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2073;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2074;
  unsigned long long llvm_cbe_tmp__2075;
  unsigned char llvm_cbe_tmp__2076;
  unsigned char llvm_cbe_tmp__2077;
  bool llvm_cbe_tmp__2078;
  bool llvm_cbe_tmp__2079;
  bool llvm_cbe_tmp__2079__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2080;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2081;
  unsigned long long llvm_cbe_tmp__2082;
  unsigned char llvm_cbe_tmp__2083;
  unsigned char llvm_cbe_tmp__2084;
  bool llvm_cbe_tmp__2085;
  bool llvm_cbe_tmp__2086;
  bool llvm_cbe_tmp__2086__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2087;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2088;
  unsigned long long llvm_cbe_tmp__2089;
  unsigned char llvm_cbe_tmp__2090;
  unsigned char llvm_cbe_tmp__2091;
  bool llvm_cbe_tmp__2092;
  bool llvm_cbe_tmp__2093;
  bool llvm_cbe_tmp__2093__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2094;
  unsigned long long llvm_cbe_tmp__2095;
  unsigned long long llvm_cbe_tmp__2096;
  unsigned long long llvm_cbe_tmp__2097;
  unsigned long long llvm_cbe_tmp__2098;
  unsigned long long llvm_cbe_tmp__2099;
  unsigned long long llvm_cbe_tmp__2100;
  unsigned long long llvm_cbe_tmp__2101;
  unsigned long long llvm_cbe_tmp__2102;
  unsigned long long llvm_cbe_tmp__2103;
  unsigned long long llvm_cbe_tmp__2104;
  unsigned char llvm_cbe_tmp__2105;
  unsigned char llvm_cbe_tmp__2106;
  bool llvm_cbe_tmp__2107;
  bool llvm_cbe_tmp__2108;
  bool llvm_cbe_tmp__2108__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2109;
  unsigned char llvm_cbe_tmp__2110;
  bool llvm_cbe_tmp__2111;
  bool llvm_cbe_tmp__2112;
  bool llvm_cbe_tmp__2112__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2113;
  unsigned long long llvm_cbe_tmp__2114;
  unsigned long long llvm_cbe_tmp__2115;
  unsigned long long llvm_cbe_tmp__2116;
  unsigned long long llvm_cbe_tmp__2117;
  unsigned long long llvm_cbe_tmp__2118;
  unsigned long long llvm_cbe_tmp__2119;
  unsigned long long llvm_cbe_tmp__2120;
  unsigned long long llvm_cbe_tmp__2121;
  unsigned long long llvm_cbe_tmp__2122;
  unsigned long long llvm_cbe_tmp__2123;
  unsigned long long llvm_cbe_tmp__2124;
  unsigned long long llvm_cbe_tmp__2125;
  unsigned short llvm_cbe_tmp__2126;
  unsigned short llvm_cbe_tmp__2127;
  unsigned long long llvm_cbe_tmp__2128;
  unsigned long long llvm_cbe_tmp__2129;
  unsigned char llvm_cbe_tmp__2130;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2131;
  unsigned long long llvm_cbe_tmp__2132;
  unsigned long long llvm_cbe_tmp__2133;
  unsigned long long llvm_cbe_tmp__2134;
  unsigned long long llvm_cbe_tmp__2135;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2136;
  unsigned long long llvm_cbe_tmp__2137;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2138;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2139;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2140;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2141;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2142;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2143;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2144;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2145;
  unsigned long long llvm_cbe_tmp__2146;
  unsigned char llvm_cbe_tmp__2147;
  bool llvm_cbe_tmp__2148;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2149;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2150;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2151;
  bool llvm_cbe_tmp__2152;

  *(&llvm_cbe_tmp__2046) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2047) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2048) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2049) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2050) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2051) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2052) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2053) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2054) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2055) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2056) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2057) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2062 = *(&llvm_cbe_tmp__2046);
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1189));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1191));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1167));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1163));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1159));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1155));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1151));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1192));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1148));
  *(&llvm_cbe_tmp__2060) = ((0) & 1);
  _ZN8type_memIbLj512EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__2063 = *((&llvm_cbe_tmp__2062->field29));
  *(&llvm_cbe_cppVar_1147) = (((unsigned char )(bool )(llvm_cbe_tmp__2063 == 0ull)));
  llvm_cbe_tmp__2064 = *(&llvm_cbe_cppVar_1147);
  if ((((((bool )llvm_cbe_tmp__2064&1u))&1))) {
    goto llvm_cbe_tmp__2153;
  } else {
    goto llvm_cbe_tmp__2154;
  }

llvm_cbe_tmp__2153:
  llvm_cbe_tmp__2065 = _ZN8type_memIbLj512EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__2062->field33)));
  goto llvm_cbe_tmp__2155;

llvm_cbe_tmp__2154:
  llvm_cbe_tmp__2066 = *((&llvm_cbe_tmp__2062->field29));
  *(&llvm_cbe_cppVar_1150) = (((unsigned char )(bool )(llvm_cbe_tmp__2066 == 1ull)));
  llvm_cbe_tmp__2067 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2067&1u))&1))) {
    goto llvm_cbe_tmp__2156;
  } else {
    goto llvm_cbe_tmp__2157;
  }

llvm_cbe_tmp__2156:
  llvm_cbe_tmp__2068 = *((&llvm_cbe_tmp__2062->field15));
  *(&llvm_cbe_cppVar_1153) = (((unsigned char )(bool )(llvm_cbe_tmp__2068 == 0ull)));
  llvm_cbe_tmp__2069 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2069&1u))&1))) {
    goto llvm_cbe_tmp__2158;
  } else {
    llvm_cbe_tmp__2072__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2159;
  }

llvm_cbe_tmp__2158:
  llvm_cbe_tmp__2070 = *(&llvm_cbe_cppVar_1153);
  llvm_cbe_tmp__2071 = ((((bool )llvm_cbe_tmp__2070&1u))&1);
  llvm_cbe_tmp__2072__PHI_TEMPORARY = llvm_cbe_tmp__2071;   /* for PHI node */
  goto llvm_cbe_tmp__2159;

llvm_cbe_tmp__2159:
  llvm_cbe_tmp__2072 = ((llvm_cbe_tmp__2072__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1154) = (((unsigned char )(bool )llvm_cbe_tmp__2072));
  llvm_cbe_tmp__2073 = *(&llvm_cbe_cppVar_1154);
  if ((((((bool )llvm_cbe_tmp__2073&1u))&1))) {
    goto llvm_cbe_tmp__2160;
  } else {
    goto llvm_cbe_tmp__2161;
  }

llvm_cbe_tmp__2160:
  llvm_cbe_tmp__2074 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1151), ((&llvm_cbe_tmp__2062->field33)));
  goto llvm_cbe_tmp__2162;

llvm_cbe_tmp__2161:
  llvm_cbe_tmp__2075 = *((&llvm_cbe_tmp__2062->field15));
  *(&llvm_cbe_cppVar_1157) = (((unsigned char )(bool )(llvm_cbe_tmp__2075 == 1ull)));
  llvm_cbe_tmp__2076 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2076&1u))&1))) {
    goto llvm_cbe_tmp__2163;
  } else {
    llvm_cbe_tmp__2079__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2164;
  }

llvm_cbe_tmp__2163:
  llvm_cbe_tmp__2077 = *(&llvm_cbe_cppVar_1157);
  llvm_cbe_tmp__2078 = ((((bool )llvm_cbe_tmp__2077&1u))&1);
  llvm_cbe_tmp__2079__PHI_TEMPORARY = llvm_cbe_tmp__2078;   /* for PHI node */
  goto llvm_cbe_tmp__2164;

llvm_cbe_tmp__2164:
  llvm_cbe_tmp__2079 = ((llvm_cbe_tmp__2079__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1158) = (((unsigned char )(bool )llvm_cbe_tmp__2079));
  llvm_cbe_tmp__2080 = *(&llvm_cbe_cppVar_1158);
  if ((((((bool )llvm_cbe_tmp__2080&1u))&1))) {
    goto llvm_cbe_tmp__2165;
  } else {
    goto llvm_cbe_tmp__2166;
  }

llvm_cbe_tmp__2165:
  llvm_cbe_tmp__2081 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1155), ((&llvm_cbe_tmp__2062->field33)));
  goto llvm_cbe_tmp__2167;

llvm_cbe_tmp__2166:
  llvm_cbe_tmp__2082 = *((&llvm_cbe_tmp__2062->field15));
  *(&llvm_cbe_cppVar_1161) = (((unsigned char )(bool )(llvm_cbe_tmp__2082 == 2ull)));
  llvm_cbe_tmp__2083 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2083&1u))&1))) {
    goto llvm_cbe_tmp__2168;
  } else {
    llvm_cbe_tmp__2086__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2169;
  }

llvm_cbe_tmp__2168:
  llvm_cbe_tmp__2084 = *(&llvm_cbe_cppVar_1161);
  llvm_cbe_tmp__2085 = ((((bool )llvm_cbe_tmp__2084&1u))&1);
  llvm_cbe_tmp__2086__PHI_TEMPORARY = llvm_cbe_tmp__2085;   /* for PHI node */
  goto llvm_cbe_tmp__2169;

llvm_cbe_tmp__2169:
  llvm_cbe_tmp__2086 = ((llvm_cbe_tmp__2086__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1162) = (((unsigned char )(bool )llvm_cbe_tmp__2086));
  llvm_cbe_tmp__2087 = *(&llvm_cbe_cppVar_1162);
  if ((((((bool )llvm_cbe_tmp__2087&1u))&1))) {
    goto llvm_cbe_tmp__2170;
  } else {
    goto llvm_cbe_tmp__2171;
  }

llvm_cbe_tmp__2170:
  llvm_cbe_tmp__2088 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1159), ((&llvm_cbe_tmp__2062->field33)));
  goto llvm_cbe_tmp__2172;

llvm_cbe_tmp__2171:
  llvm_cbe_tmp__2089 = *((&llvm_cbe_tmp__2062->field15));
  *(&llvm_cbe_cppVar_1165) = (((unsigned char )(bool )(llvm_cbe_tmp__2089 == 3ull)));
  llvm_cbe_tmp__2090 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2090&1u))&1))) {
    goto llvm_cbe_tmp__2173;
  } else {
    llvm_cbe_tmp__2093__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2174;
  }

llvm_cbe_tmp__2173:
  llvm_cbe_tmp__2091 = *(&llvm_cbe_cppVar_1165);
  llvm_cbe_tmp__2092 = ((((bool )llvm_cbe_tmp__2091&1u))&1);
  llvm_cbe_tmp__2093__PHI_TEMPORARY = llvm_cbe_tmp__2092;   /* for PHI node */
  goto llvm_cbe_tmp__2174;

llvm_cbe_tmp__2174:
  llvm_cbe_tmp__2093 = ((llvm_cbe_tmp__2093__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1166) = (((unsigned char )(bool )llvm_cbe_tmp__2093));
  llvm_cbe_tmp__2094 = *(&llvm_cbe_cppVar_1166);
  if ((((((bool )llvm_cbe_tmp__2094&1u))&1))) {
    goto llvm_cbe_tmp__2175;
  } else {
    goto llvm_cbe_tmp__2176;
  }

llvm_cbe_tmp__2175:
  llvm_cbe_tmp__2095 = *((&llvm_cbe_tmp__2062->field7));
  *(&llvm_cbe_cppVar_1169) = (((unsigned char )(bool )(llvm_cbe_tmp__2095 == 4ull)));
  llvm_cbe_tmp__2096 = *((&llvm_cbe_tmp__2062->field30));
  *(&llvm_cbe_cppVar_1171) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2096) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2097 = *(&llvm_cbe_cppVar_1171);
  llvm_cbe_tmp__2098 = *((&llvm_cbe_tmp__2062->field39));
  *(&llvm_cbe_cppVar_1171) = (llvm_cbe_tmp__2097 & llvm_cbe_tmp__2098);
  llvm_cbe_tmp__2099 = *(&llvm_cbe_cppVar_1171);
  llvm_cbe_tmp__2100 = *((&llvm_cbe_tmp__2062->field14));
  *(&llvm_cbe_cppVar_1172) = (((unsigned char )(bool )(llvm_cbe_tmp__2099 == llvm_cbe_tmp__2100)));
  llvm_cbe_tmp__2101 = *((&llvm_cbe_tmp__2062->field30));
  *(&llvm_cbe_cppVar_1174) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2101) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2102 = *(&llvm_cbe_cppVar_1174);
  llvm_cbe_tmp__2103 = *((&llvm_cbe_tmp__2062->field39));
  *(&llvm_cbe_cppVar_1174) = (llvm_cbe_tmp__2102 & llvm_cbe_tmp__2103);
  llvm_cbe_tmp__2104 = *(&llvm_cbe_cppVar_1174);
  *(&llvm_cbe_cppVar_1176) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__2104) >= ((signed long long )500ull))));
  llvm_cbe_tmp__2105 = *(&llvm_cbe_cppVar_1172);
  if ((((((bool )llvm_cbe_tmp__2105&1u))&1))) {
    llvm_cbe_tmp__2108__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__2177;
  } else {
    goto llvm_cbe_tmp__2178;
  }

llvm_cbe_tmp__2178:
  llvm_cbe_tmp__2106 = *(&llvm_cbe_cppVar_1176);
  llvm_cbe_tmp__2107 = ((((bool )llvm_cbe_tmp__2106&1u))&1);
  llvm_cbe_tmp__2108__PHI_TEMPORARY = llvm_cbe_tmp__2107;   /* for PHI node */
  goto llvm_cbe_tmp__2177;

llvm_cbe_tmp__2177:
  llvm_cbe_tmp__2108 = ((llvm_cbe_tmp__2108__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1177) = (((unsigned char )(bool )llvm_cbe_tmp__2108));
  llvm_cbe_tmp__2109 = *(&llvm_cbe_cppVar_1169);
  if ((((((bool )llvm_cbe_tmp__2109&1u))&1))) {
    goto llvm_cbe_tmp__2179;
  } else {
    llvm_cbe_tmp__2112__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2180;
  }

llvm_cbe_tmp__2179:
  llvm_cbe_tmp__2110 = *(&llvm_cbe_cppVar_1177);
  llvm_cbe_tmp__2111 = ((((bool )llvm_cbe_tmp__2110&1u))&1);
  llvm_cbe_tmp__2112__PHI_TEMPORARY = llvm_cbe_tmp__2111;   /* for PHI node */
  goto llvm_cbe_tmp__2180;

llvm_cbe_tmp__2180:
  llvm_cbe_tmp__2112 = ((llvm_cbe_tmp__2112__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1178) = (((unsigned char )(bool )llvm_cbe_tmp__2112));
  llvm_cbe_tmp__2113 = *(&llvm_cbe_cppVar_1178);
  if ((((((bool )llvm_cbe_tmp__2113&1u))&1))) {
    goto llvm_cbe_tmp__2181;
  } else {
    goto llvm_cbe_tmp__2182;
  }

llvm_cbe_tmp__2181:
  llvm_cbe_tmp__2114 = *((&llvm_cbe_tmp__2062->field30));
  llvm_cbe_tmp__2115 = *((&llvm_cbe_tmp__2062->field7));
  *(&llvm_cbe_cppVar_1179) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2114) + ((unsigned long long )llvm_cbe_tmp__2115))));
  llvm_cbe_tmp__2116 = *(&llvm_cbe_cppVar_1179);
  llvm_cbe_tmp__2117 = *((&llvm_cbe_tmp__2062->field39));
  *(&llvm_cbe_cppVar_1179) = (llvm_cbe_tmp__2116 & llvm_cbe_tmp__2117);
  llvm_cbe_tmp__2118 = *(&llvm_cbe_cppVar_1179);
  llvm_cbe_tmp__2119 = *((&llvm_cbe_tmp__2062->field45));
  *(&llvm_cbe_cppVar_1180) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2118) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2119);
  llvm_cbe_tmp__2120 = *((&llvm_cbe_tmp__2062->field7));
  llvm_cbe_tmp__2121 = *((&llvm_cbe_tmp__2062->field40));
  *(&llvm_cbe_cppVar_1182) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2120) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2121);
  llvm_cbe_tmp__2122 = *(&llvm_cbe_cppVar_1182);
  llvm_cbe_tmp__2123 = _ZN8type_memIjLj8EE2rdEl(((&llvm_cbe_tmp__2062->field17)), llvm_cbe_tmp__2122);
  *(&llvm_cbe_cppVar_1183) = llvm_cbe_tmp__2123;
  llvm_cbe_tmp__2124 = *(&llvm_cbe_cppVar_1183);
  llvm_cbe_tmp__2125 = *((&llvm_cbe_tmp__2062->field24));
  llvm_cbe_tmp__2126 = _Z6dividell(llvm_cbe_tmp__2124, llvm_cbe_tmp__2125);
  *(&llvm_cbe_cppVar_1184) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__2126));
  llvm_cbe_tmp__2127 = _Z4randv();
  *(&llvm_cbe_cppVar_1185) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__2127));
  llvm_cbe_tmp__2128 = *(&llvm_cbe_cppVar_1184);
  llvm_cbe_tmp__2129 = *(&llvm_cbe_cppVar_1185);
  *(&llvm_cbe_cppVar_1186) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__2128) > ((signed long long )llvm_cbe_tmp__2129))));
  llvm_cbe_tmp__2130 = *(&llvm_cbe_cppVar_1186);
  if ((((((bool )llvm_cbe_tmp__2130&1u))&1))) {
    goto llvm_cbe_tmp__2183;
  } else {
    goto llvm_cbe_tmp__2184;
  }

llvm_cbe_tmp__2183:
  *(&llvm_cbe_cppVar_1181) = 1ull;
  goto llvm_cbe_tmp__2185;

llvm_cbe_tmp__2184:
  *(&llvm_cbe_cppVar_1181) = 0ull;
  goto llvm_cbe_tmp__2185;

llvm_cbe_tmp__2185:
  llvm_cbe_tmp__2131 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1189), ((&llvm_cbe_tmp__2062->field33)));
  llvm_cbe_tmp__2132 = *(&llvm_cbe_cppVar_1180);
  llvm_cbe_tmp__2133 = *(&llvm_cbe_cppVar_1181);
  _ZN8type_memIbLj512EE2wrEll((&llvm_cbe_cppVar_1189), llvm_cbe_tmp__2132, llvm_cbe_tmp__2133);
  llvm_cbe_tmp__2134 = *((&llvm_cbe_tmp__2062->field14));
  llvm_cbe_tmp__2135 = *((&llvm_cbe_tmp__2062->field45));
  *(&llvm_cbe_cppVar_1190) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2134) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2135);
  llvm_cbe_tmp__2136 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1191), (&llvm_cbe_cppVar_1189));
  llvm_cbe_tmp__2137 = *(&llvm_cbe_cppVar_1190);
  _ZN8type_memIbLj512EE2wrEll((&llvm_cbe_cppVar_1191), llvm_cbe_tmp__2137, 1ull);
  llvm_cbe_tmp__2138 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1167), (&llvm_cbe_cppVar_1191));
  goto llvm_cbe_tmp__2186;

llvm_cbe_tmp__2182:
  llvm_cbe_tmp__2139 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1167), (&llvm_cbe_cppVar_1189));
  goto llvm_cbe_tmp__2186;

llvm_cbe_tmp__2186:
  llvm_cbe_tmp__2140 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1163), (&llvm_cbe_cppVar_1167));
  goto llvm_cbe_tmp__2187;

llvm_cbe_tmp__2176:
  llvm_cbe_tmp__2141 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1163), ((&llvm_cbe_tmp__2062->field33)));
  goto llvm_cbe_tmp__2187;

llvm_cbe_tmp__2187:
  llvm_cbe_tmp__2142 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1159), (&llvm_cbe_cppVar_1163));
  goto llvm_cbe_tmp__2172;

llvm_cbe_tmp__2172:
  llvm_cbe_tmp__2143 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1155), (&llvm_cbe_cppVar_1159));
  goto llvm_cbe_tmp__2167;

llvm_cbe_tmp__2167:
  llvm_cbe_tmp__2144 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1151), (&llvm_cbe_cppVar_1155));
  goto llvm_cbe_tmp__2162;

llvm_cbe_tmp__2162:
  llvm_cbe_tmp__2145 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1148), (&llvm_cbe_cppVar_1151));
  goto llvm_cbe_tmp__2188;

llvm_cbe_tmp__2157:
  llvm_cbe_tmp__2146 = *((&llvm_cbe_tmp__2062->field29));
  *(&llvm_cbe_cppVar_1194) = (((unsigned char )(bool )(llvm_cbe_tmp__2146 == 2ull)));
  llvm_cbe_tmp__2147 = *(&llvm_cbe_cppVar_1194);
  llvm_cbe_tmp__2148 = ((((bool )llvm_cbe_tmp__2147&1u))&1);
  llvm_cbe_tmp__2149 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1192), ((&llvm_cbe_tmp__2062->field33)));
  llvm_cbe_tmp__2150 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1148), (&llvm_cbe_cppVar_1192));
  goto llvm_cbe_tmp__2188;

llvm_cbe_tmp__2188:
  llvm_cbe_tmp__2151 = _ZN8type_memIbLj512EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1148));
  goto llvm_cbe_tmp__2155;

llvm_cbe_tmp__2155:
  *(&llvm_cbe_tmp__2060) = ((1) & 1);
  *(&llvm_cbe_tmp__2061) = 1u;
  llvm_cbe_tmp__2152 = ((*(&llvm_cbe_tmp__2060))&1);
  if (llvm_cbe_tmp__2152) {
    goto llvm_cbe_tmp__2189;
  } else {
    goto llvm_cbe_tmp__2190;
  }

llvm_cbe_tmp__2190:
  _ZN8type_memIbLj512EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__2189;

llvm_cbe_tmp__2189:
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1148));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1192));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1151));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1155));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1159));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1163));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1167));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1191));
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1189));
  return StructReturn;
}


void _ZN8type_memIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2191;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2192;

  *(&llvm_cbe_tmp__2191) = llvm_cbe_this;
  llvm_cbe_tmp__2192 = *(&llvm_cbe_tmp__2191);
  _ZN8type_memIbLj512EEC2Ev(llvm_cbe_tmp__2192);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIbLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2193;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2194;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2195;
  unsigned char *llvm_cbe_tmp__2196;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2197;
  unsigned char *llvm_cbe_tmp__2198;

  *(&llvm_cbe_tmp__2193) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2194) = llvm_cbe_r;
  llvm_cbe_tmp__2195 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2196 = *((&llvm_cbe_tmp__2195->field0));
  llvm_cbe_tmp__2197 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2198 = *((&llvm_cbe_tmp__2197->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2196, llvm_cbe_tmp__2198);
  return llvm_cbe_tmp__2195;
}


unsigned long long _ZN8type_memIjLj8EE2rdEl(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_unnamed1 *llvm_cbe_tmp__2199;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2200;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__2201;
  unsigned long long llvm_cbe_tmp__2202;
  unsigned int *llvm_cbe_tmp__2203;
  unsigned int llvm_cbe_tmp__2204;

  *(&llvm_cbe_tmp__2199) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2200) = llvm_cbe_addr;
  llvm_cbe_tmp__2201 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2202 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2203 = *((&llvm_cbe_tmp__2201->field0));
  llvm_cbe_tmp__2204 = *((&llvm_cbe_tmp__2203[((signed long long )llvm_cbe_tmp__2202)]));
  return (((unsigned long long )(unsigned int )llvm_cbe_tmp__2204));
}


void _ZN8type_memIbLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2205;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2206;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2207;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2208;
  unsigned long long llvm_cbe_tmp__2209;
  unsigned long long llvm_cbe_tmp__2210;
  unsigned char *llvm_cbe_tmp__2211;

  *(&llvm_cbe_tmp__2205) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2206) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__2207) = llvm_cbe_data;
  llvm_cbe_tmp__2208 = *(&llvm_cbe_tmp__2205);
  llvm_cbe_tmp__2209 = *(&llvm_cbe_tmp__2207);
  llvm_cbe_tmp__2210 = *(&llvm_cbe_tmp__2206);
  llvm_cbe_tmp__2211 = *((&llvm_cbe_tmp__2208->field0));
  *((&llvm_cbe_tmp__2211[((signed long long )llvm_cbe_tmp__2210)])) = (((unsigned char )(bool )(llvm_cbe_tmp__2209 != 0ull)));
  return;
}


void _ZN8type_memIbLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2212;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2213;

  *(&llvm_cbe_tmp__2212) = llvm_cbe_this;
  llvm_cbe_tmp__2213 = *(&llvm_cbe_tmp__2212);
  _ZN8type_memIbLj512EED2Ev(llvm_cbe_tmp__2213);
  return;
}


void _ZN11model_train6updateElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__2214;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2215;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2216;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2217;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2218;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2219;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2220;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2221;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2222;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2223;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2224;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2225;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_512;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_549;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_571;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_618;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_654;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_704;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_719;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_777;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_837;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_884;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_932;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_947;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_990;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1037;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2226;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2227;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1055;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1086;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1144;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1195;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2228;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__2229;
  unsigned long long llvm_cbe_tmp__2230;
  unsigned long long llvm_cbe_tmp__2231;
  unsigned long long llvm_cbe_tmp__2232;
  unsigned long long llvm_cbe_tmp__2233;
  unsigned long long llvm_cbe_tmp__2234;
  unsigned long long llvm_cbe_tmp__2235;
  unsigned long long llvm_cbe_tmp__2236;
  unsigned long long llvm_cbe_tmp__2237;
  unsigned long long llvm_cbe_tmp__2238;
  unsigned long long llvm_cbe_tmp__2239;
  unsigned long long llvm_cbe_tmp__2240;
  unsigned long long llvm_cbe_tmp__2241;
  unsigned long long llvm_cbe_tmp__2242;
  unsigned long long llvm_cbe_tmp__2243;
  unsigned long long llvm_cbe_tmp__2244;
  unsigned long long llvm_cbe_tmp__2245;
  unsigned long long llvm_cbe_tmp__2246;
  unsigned long long llvm_cbe_tmp__2247;
  unsigned long long llvm_cbe_tmp__2248;
  unsigned long long llvm_cbe_tmp__2249;
  unsigned long long llvm_cbe_tmp__2250;
  unsigned long long llvm_cbe_tmp__2251;
  unsigned long long llvm_cbe_tmp__2252;
  unsigned long long llvm_cbe_tmp__2253;
  unsigned long long llvm_cbe_tmp__2254;
  unsigned long long llvm_cbe_tmp__2255;
  unsigned long long llvm_cbe_tmp__2256;
  unsigned long long llvm_cbe_tmp__2257;
  unsigned long long llvm_cbe_tmp__2258;
  unsigned long long llvm_cbe_tmp__2259;
  unsigned long long llvm_cbe_tmp__2260;
  unsigned long long llvm_cbe_tmp__2261;
  unsigned long long llvm_cbe_tmp__2262;
  unsigned long long llvm_cbe_tmp__2263;
  unsigned long long llvm_cbe_tmp__2264;
  unsigned long long llvm_cbe_tmp__2265;
  unsigned long long llvm_cbe_tmp__2266;
  unsigned long long llvm_cbe_tmp__2267;
  unsigned long long llvm_cbe_tmp__2268;
  unsigned long long llvm_cbe_tmp__2269;
  unsigned long long llvm_cbe_tmp__2270;
  unsigned long long llvm_cbe_tmp__2271;
  unsigned long long llvm_cbe_tmp__2272;
  unsigned long long llvm_cbe_tmp__2273;
  unsigned long long llvm_cbe_tmp__2274;
  unsigned long long llvm_cbe_tmp__2275;
  unsigned long long llvm_cbe_tmp__2276;
  unsigned long long llvm_cbe_tmp__2277;
  unsigned long long llvm_cbe_tmp__2278;
  unsigned long long llvm_cbe_tmp__2279;
  unsigned long long llvm_cbe_tmp__2280;
  unsigned long long llvm_cbe_tmp__2281;
  unsigned long long llvm_cbe_tmp__2282;
  unsigned long long llvm_cbe_tmp__2283;
  unsigned long long llvm_cbe_tmp__2284;
  unsigned long long llvm_cbe_tmp__2285;
  unsigned long long llvm_cbe_tmp__2286;
  unsigned long long llvm_cbe_tmp__2287;
  unsigned long long llvm_cbe_tmp__2288;
  unsigned long long llvm_cbe_tmp__2289;
  unsigned long long llvm_cbe_tmp__2290;
  unsigned long long llvm_cbe_tmp__2291;
  unsigned long long llvm_cbe_tmp__2292;
  unsigned long long llvm_cbe_tmp__2293;
  unsigned long long llvm_cbe_tmp__2294;
  unsigned long long llvm_cbe_tmp__2295;
  unsigned long long llvm_cbe_tmp__2296;
  unsigned long long llvm_cbe_tmp__2297;
  unsigned long long llvm_cbe_tmp__2298;
  unsigned long long llvm_cbe_tmp__2299;
  unsigned long long llvm_cbe_tmp__2300;
  unsigned long long llvm_cbe_tmp__2301;
  unsigned long long llvm_cbe_tmp__2302;
  unsigned long long llvm_cbe_tmp__2303;
  unsigned long long llvm_cbe_tmp__2304;
  unsigned long long llvm_cbe_tmp__2305;
  unsigned long long llvm_cbe_tmp__2306;
  unsigned long long llvm_cbe_tmp__2307;
  unsigned long long llvm_cbe_tmp__2308;
  unsigned long long llvm_cbe_tmp__2309;
  unsigned long long llvm_cbe_tmp__2310;
  unsigned long long llvm_cbe_tmp__2311;
  unsigned long long llvm_cbe_tmp__2312;
  unsigned long long llvm_cbe_tmp__2313;
  unsigned long long llvm_cbe_tmp__2314;
  unsigned long long llvm_cbe_tmp__2315;
  unsigned long long llvm_cbe_tmp__2316;
  unsigned long long llvm_cbe_tmp__2317;
  unsigned long long llvm_cbe_tmp__2318;
  unsigned long long llvm_cbe_tmp__2319;
  unsigned long long llvm_cbe_tmp__2320;
  unsigned long long llvm_cbe_tmp__2321;
  unsigned long long llvm_cbe_tmp__2322;
  unsigned long long llvm_cbe_tmp__2323;
  unsigned long long llvm_cbe_tmp__2324;
  unsigned long long llvm_cbe_tmp__2325;
  unsigned long long llvm_cbe_tmp__2326;
  unsigned long long llvm_cbe_tmp__2327;
  unsigned long long llvm_cbe_tmp__2328;
  unsigned long long llvm_cbe_tmp__2329;
  unsigned long long llvm_cbe_tmp__2330;
  unsigned long long llvm_cbe_tmp__2331;
  unsigned long long llvm_cbe_tmp__2332;
  unsigned long long llvm_cbe_tmp__2333;
  unsigned long long llvm_cbe_tmp__2334;
  unsigned long long llvm_cbe_tmp__2335;
  unsigned long long llvm_cbe_tmp__2336;
  unsigned long long llvm_cbe_tmp__2337;
  unsigned long long llvm_cbe_tmp__2338;
  unsigned long long llvm_cbe_tmp__2339;
  unsigned long long llvm_cbe_tmp__2340;
  unsigned long long llvm_cbe_tmp__2341;
  unsigned long long llvm_cbe_tmp__2342;
  unsigned long long llvm_cbe_tmp__2343;
  unsigned long long llvm_cbe_tmp__2344;
  unsigned long long llvm_cbe_tmp__2345;
  unsigned long long llvm_cbe_tmp__2346;
  unsigned long long llvm_cbe_tmp__2347;
  unsigned long long llvm_cbe_tmp__2348;
  unsigned long long llvm_cbe_tmp__2349;
  unsigned long long llvm_cbe_tmp__2350;
  unsigned long long llvm_cbe_tmp__2351;
  unsigned long long llvm_cbe_tmp__2352;
  unsigned long long llvm_cbe_tmp__2353;
  unsigned long long llvm_cbe_tmp__2354;
  unsigned long long llvm_cbe_tmp__2355;
  unsigned long long llvm_cbe_tmp__2356;
  unsigned long long llvm_cbe_tmp__2357;
  unsigned long long llvm_cbe_tmp__2358;
  unsigned long long llvm_cbe_tmp__2359;
  unsigned long long llvm_cbe_tmp__2360;
  unsigned long long llvm_cbe_tmp__2361;
  unsigned long long llvm_cbe_tmp__2362;
  unsigned long long llvm_cbe_tmp__2363;
  unsigned long long llvm_cbe_tmp__2364;
  unsigned long long llvm_cbe_tmp__2365;
  unsigned long long llvm_cbe_tmp__2366;
  unsigned long long llvm_cbe_tmp__2367;
  unsigned long long llvm_cbe_tmp__2368;
  unsigned long long llvm_cbe_tmp__2369;
  unsigned long long llvm_cbe_tmp__2370;
  unsigned long long llvm_cbe_tmp__2371;
  unsigned long long llvm_cbe_tmp__2372;
  unsigned long long llvm_cbe_tmp__2373;
  unsigned long long llvm_cbe_tmp__2374;
  unsigned long long llvm_cbe_tmp__2375;
  unsigned long long llvm_cbe_tmp__2376;
  unsigned long long llvm_cbe_tmp__2377;
  unsigned long long llvm_cbe_tmp__2378;
  unsigned long long llvm_cbe_tmp__2379;
  unsigned long long llvm_cbe_tmp__2380;
  unsigned long long llvm_cbe_tmp__2381;
  unsigned long long llvm_cbe_tmp__2382;
  unsigned long long llvm_cbe_tmp__2383;
  unsigned long long llvm_cbe_tmp__2384;
  unsigned long long llvm_cbe_tmp__2385;
  unsigned long long llvm_cbe_tmp__2386;
  unsigned long long llvm_cbe_tmp__2387;
  unsigned long long llvm_cbe_tmp__2388;
  unsigned long long llvm_cbe_tmp__2389;
  unsigned long long llvm_cbe_tmp__2390;
  unsigned long long llvm_cbe_tmp__2391;
  unsigned long long llvm_cbe_tmp__2392;
  unsigned long long llvm_cbe_tmp__2393;
  unsigned long long llvm_cbe_tmp__2394;
  unsigned long long llvm_cbe_tmp__2395;
  unsigned long long llvm_cbe_tmp__2396;
  unsigned long long llvm_cbe_tmp__2397;
  unsigned long long llvm_cbe_tmp__2398;
  unsigned long long llvm_cbe_tmp__2399;
  unsigned long long llvm_cbe_tmp__2400;
  unsigned long long llvm_cbe_tmp__2401;
  unsigned long long llvm_cbe_tmp__2402;
  unsigned long long llvm_cbe_tmp__2403;
  unsigned long long llvm_cbe_tmp__2404;
  unsigned long long llvm_cbe_tmp__2405;
  unsigned long long llvm_cbe_tmp__2406;
  unsigned long long llvm_cbe_tmp__2407;
  unsigned long long llvm_cbe_tmp__2408;
  unsigned long long llvm_cbe_tmp__2409;
  unsigned long long llvm_cbe_tmp__2410;
  unsigned long long llvm_cbe_tmp__2411;
  unsigned long long llvm_cbe_tmp__2412;
  unsigned long long llvm_cbe_tmp__2413;
  unsigned long long llvm_cbe_tmp__2414;
  unsigned long long llvm_cbe_tmp__2415;
  unsigned long long llvm_cbe_tmp__2416;
  unsigned long long llvm_cbe_tmp__2417;
  unsigned long long llvm_cbe_tmp__2418;
  unsigned long long llvm_cbe_tmp__2419;
  unsigned long long llvm_cbe_tmp__2420;
  unsigned long long llvm_cbe_tmp__2421;
  unsigned long long llvm_cbe_tmp__2422;
  unsigned long long llvm_cbe_tmp__2423;
  unsigned long long llvm_cbe_tmp__2424;
  unsigned long long llvm_cbe_tmp__2425;
  unsigned long long llvm_cbe_tmp__2426;
  unsigned long long llvm_cbe_tmp__2427;
  unsigned long long llvm_cbe_tmp__2428;
  unsigned long long llvm_cbe_tmp__2429;
  unsigned long long llvm_cbe_tmp__2430;
  unsigned long long llvm_cbe_tmp__2431;
  unsigned long long llvm_cbe_tmp__2432;
  unsigned long long llvm_cbe_tmp__2433;
  unsigned long long llvm_cbe_tmp__2434;
  unsigned long long llvm_cbe_tmp__2435;
  unsigned long long llvm_cbe_tmp__2436;
  unsigned long long llvm_cbe_tmp__2437;
  unsigned long long llvm_cbe_tmp__2438;
  unsigned long long llvm_cbe_tmp__2439;
  unsigned long long llvm_cbe_tmp__2440;
  unsigned long long llvm_cbe_tmp__2441;
  unsigned long long llvm_cbe_tmp__2442;
  unsigned long long llvm_cbe_tmp__2443;
  unsigned long long llvm_cbe_tmp__2444;
  unsigned long long llvm_cbe_tmp__2445;
  unsigned long long llvm_cbe_tmp__2446;
  unsigned long long llvm_cbe_tmp__2447;
  unsigned long long llvm_cbe_tmp__2448;
  unsigned long long llvm_cbe_tmp__2449;
  unsigned long long llvm_cbe_tmp__2450;
  unsigned long long llvm_cbe_tmp__2451;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2452;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2453;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2454;
  struct l_unnamed1 *llvm_cbe_tmp__2455;
  struct l_unnamed2 *llvm_cbe_tmp__2456;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2457;

  *(&llvm_cbe_tmp__2214) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2215) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2216) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2217) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2218) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2219) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2220) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2221) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2222) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2223) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2224) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2225) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2229 = *(&llvm_cbe_tmp__2214);
  llvm_cbe_tmp__2230 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2231 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2232 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2233 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2234 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2235 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2236 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2237 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2238 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2239 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2240 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2241 = _ZN11model_train18cppUpdateFun_indexElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2230, llvm_cbe_tmp__2231, llvm_cbe_tmp__2232, llvm_cbe_tmp__2233, llvm_cbe_tmp__2234, llvm_cbe_tmp__2235, llvm_cbe_tmp__2236, llvm_cbe_tmp__2237, llvm_cbe_tmp__2238, llvm_cbe_tmp__2239, llvm_cbe_tmp__2240);
  *(&llvm_cbe_cppVar_512) = llvm_cbe_tmp__2241;
  llvm_cbe_tmp__2242 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2243 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2244 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2245 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2246 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2247 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2248 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2249 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2250 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2251 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2252 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2253 = _ZN11model_train19cppUpdateFun_jstateElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2242, llvm_cbe_tmp__2243, llvm_cbe_tmp__2244, llvm_cbe_tmp__2245, llvm_cbe_tmp__2246, llvm_cbe_tmp__2247, llvm_cbe_tmp__2248, llvm_cbe_tmp__2249, llvm_cbe_tmp__2250, llvm_cbe_tmp__2251, llvm_cbe_tmp__2252);
  *(&llvm_cbe_cppVar_549) = llvm_cbe_tmp__2253;
  llvm_cbe_tmp__2254 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2255 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2256 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2257 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2258 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2259 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2260 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2261 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2262 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2263 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2264 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2265 = _ZN11model_train23cppUpdateFun_loop_countElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2254, llvm_cbe_tmp__2255, llvm_cbe_tmp__2256, llvm_cbe_tmp__2257, llvm_cbe_tmp__2258, llvm_cbe_tmp__2259, llvm_cbe_tmp__2260, llvm_cbe_tmp__2261, llvm_cbe_tmp__2262, llvm_cbe_tmp__2263, llvm_cbe_tmp__2264);
  *(&llvm_cbe_cppVar_571) = llvm_cbe_tmp__2265;
  llvm_cbe_tmp__2266 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2267 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2268 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2269 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2270 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2271 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2272 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2273 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2274 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2275 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2276 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2277 = _ZN11model_train21cppUpdateFun_per_v_pcElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2266, llvm_cbe_tmp__2267, llvm_cbe_tmp__2268, llvm_cbe_tmp__2269, llvm_cbe_tmp__2270, llvm_cbe_tmp__2271, llvm_cbe_tmp__2272, llvm_cbe_tmp__2273, llvm_cbe_tmp__2274, llvm_cbe_tmp__2275, llvm_cbe_tmp__2276);
  *(&llvm_cbe_cppVar_618) = llvm_cbe_tmp__2277;
  llvm_cbe_tmp__2278 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2279 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2280 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2281 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2282 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2283 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2284 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2285 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2286 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2287 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2288 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2289 = _ZN11model_train22cppUpdateFun_sumOfpow2Elllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2278, llvm_cbe_tmp__2279, llvm_cbe_tmp__2280, llvm_cbe_tmp__2281, llvm_cbe_tmp__2282, llvm_cbe_tmp__2283, llvm_cbe_tmp__2284, llvm_cbe_tmp__2285, llvm_cbe_tmp__2286, llvm_cbe_tmp__2287, llvm_cbe_tmp__2288);
  *(&llvm_cbe_cppVar_654) = llvm_cbe_tmp__2289;
  llvm_cbe_tmp__2290 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2291 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2292 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2293 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2294 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2295 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2296 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2297 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2298 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2299 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2300 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2301 = _ZN11model_train24cppUpdateFun_train_h_cntElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2290, llvm_cbe_tmp__2291, llvm_cbe_tmp__2292, llvm_cbe_tmp__2293, llvm_cbe_tmp__2294, llvm_cbe_tmp__2295, llvm_cbe_tmp__2296, llvm_cbe_tmp__2297, llvm_cbe_tmp__2298, llvm_cbe_tmp__2299, llvm_cbe_tmp__2300);
  *(&llvm_cbe_cppVar_704) = llvm_cbe_tmp__2301;
  llvm_cbe_tmp__2302 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2303 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2304 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2305 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2306 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2307 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2308 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2309 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2310 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2311 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2312 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2313 = _ZN11model_train29cppUpdateFun_train_input_doneElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2302, llvm_cbe_tmp__2303, llvm_cbe_tmp__2304, llvm_cbe_tmp__2305, llvm_cbe_tmp__2306, llvm_cbe_tmp__2307, llvm_cbe_tmp__2308, llvm_cbe_tmp__2309, llvm_cbe_tmp__2310, llvm_cbe_tmp__2311, llvm_cbe_tmp__2312);
  *(&llvm_cbe_cppVar_719) = llvm_cbe_tmp__2313;
  llvm_cbe_tmp__2314 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2315 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2316 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2317 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2318 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2319 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2320 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2321 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2322 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2323 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2324 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2325 = _ZN11model_train22cppUpdateFun_train_maxElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2314, llvm_cbe_tmp__2315, llvm_cbe_tmp__2316, llvm_cbe_tmp__2317, llvm_cbe_tmp__2318, llvm_cbe_tmp__2319, llvm_cbe_tmp__2320, llvm_cbe_tmp__2321, llvm_cbe_tmp__2322, llvm_cbe_tmp__2323, llvm_cbe_tmp__2324);
  *(&llvm_cbe_cppVar_777) = llvm_cbe_tmp__2325;
  llvm_cbe_tmp__2326 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2327 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2328 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2329 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2330 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2331 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2332 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2333 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2334 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2335 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2336 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2337 = _ZN11model_train22cppUpdateFun_train_sumElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2326, llvm_cbe_tmp__2327, llvm_cbe_tmp__2328, llvm_cbe_tmp__2329, llvm_cbe_tmp__2330, llvm_cbe_tmp__2331, llvm_cbe_tmp__2332, llvm_cbe_tmp__2333, llvm_cbe_tmp__2334, llvm_cbe_tmp__2335, llvm_cbe_tmp__2336);
  *(&llvm_cbe_cppVar_837) = llvm_cbe_tmp__2337;
  llvm_cbe_tmp__2338 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2339 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2340 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2341 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2342 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2343 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2344 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2345 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2346 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2347 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2348 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2349 = _ZN11model_train22cppUpdateFun_train_upcElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2338, llvm_cbe_tmp__2339, llvm_cbe_tmp__2340, llvm_cbe_tmp__2341, llvm_cbe_tmp__2342, llvm_cbe_tmp__2343, llvm_cbe_tmp__2344, llvm_cbe_tmp__2345, llvm_cbe_tmp__2346, llvm_cbe_tmp__2347, llvm_cbe_tmp__2348);
  *(&llvm_cbe_cppVar_884) = llvm_cbe_tmp__2349;
  llvm_cbe_tmp__2350 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2351 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2352 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2353 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2354 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2355 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2356 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2357 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2358 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2359 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2360 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2361 = _ZN11model_train24cppUpdateFun_train_v_cntElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2350, llvm_cbe_tmp__2351, llvm_cbe_tmp__2352, llvm_cbe_tmp__2353, llvm_cbe_tmp__2354, llvm_cbe_tmp__2355, llvm_cbe_tmp__2356, llvm_cbe_tmp__2357, llvm_cbe_tmp__2358, llvm_cbe_tmp__2359, llvm_cbe_tmp__2360);
  *(&llvm_cbe_cppVar_932) = llvm_cbe_tmp__2361;
  llvm_cbe_tmp__2362 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2363 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2364 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2365 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2366 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2367 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2368 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2369 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2370 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2371 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2372 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_tmp__2373 = _ZN11model_train16cppUpdateFun_upcElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2362, llvm_cbe_tmp__2363, llvm_cbe_tmp__2364, llvm_cbe_tmp__2365, llvm_cbe_tmp__2366, llvm_cbe_tmp__2367, llvm_cbe_tmp__2368, llvm_cbe_tmp__2369, llvm_cbe_tmp__2370, llvm_cbe_tmp__2371, llvm_cbe_tmp__2372);
  *(&llvm_cbe_cppVar_947) = llvm_cbe_tmp__2373;
  llvm_cbe_tmp__2374 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2375 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2376 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2377 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2378 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2379 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2380 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2381 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2382 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2383 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2384 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_cppVar_990 = _ZN11model_train18cppUpdateFun_edgesElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2374, llvm_cbe_tmp__2375, llvm_cbe_tmp__2376, llvm_cbe_tmp__2377, llvm_cbe_tmp__2378, llvm_cbe_tmp__2379, llvm_cbe_tmp__2380, llvm_cbe_tmp__2381, llvm_cbe_tmp__2382, llvm_cbe_tmp__2383, llvm_cbe_tmp__2384);
  llvm_cbe_tmp__2385 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2386 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2387 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2388 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2389 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2390 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2391 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2392 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2393 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2394 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2395 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_cppVar_1037 = _ZN11model_train24cppUpdateFun_hidden_unitElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2385, llvm_cbe_tmp__2386, llvm_cbe_tmp__2387, llvm_cbe_tmp__2388, llvm_cbe_tmp__2389, llvm_cbe_tmp__2390, llvm_cbe_tmp__2391, llvm_cbe_tmp__2392, llvm_cbe_tmp__2393, llvm_cbe_tmp__2394, llvm_cbe_tmp__2395);
  llvm_cbe_tmp__2396 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2397 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2398 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2399 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2400 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2401 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2402 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2403 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2404 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2405 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2406 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_cppVar_1055 = _ZN11model_train16cppUpdateFun_posElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2396, llvm_cbe_tmp__2397, llvm_cbe_tmp__2398, llvm_cbe_tmp__2399, llvm_cbe_tmp__2400, llvm_cbe_tmp__2401, llvm_cbe_tmp__2402, llvm_cbe_tmp__2403, llvm_cbe_tmp__2404, llvm_cbe_tmp__2405, llvm_cbe_tmp__2406);
  llvm_cbe_tmp__2407 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2408 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2409 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2410 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2411 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2412 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2413 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2414 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2415 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2416 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2417 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_cppVar_1086 = _ZN11model_train17cppUpdateFun_pow2Elllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2407, llvm_cbe_tmp__2408, llvm_cbe_tmp__2409, llvm_cbe_tmp__2410, llvm_cbe_tmp__2411, llvm_cbe_tmp__2412, llvm_cbe_tmp__2413, llvm_cbe_tmp__2414, llvm_cbe_tmp__2415, llvm_cbe_tmp__2416, llvm_cbe_tmp__2417);
  llvm_cbe_tmp__2418 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2419 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2420 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2421 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2422 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2423 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2424 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2425 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2426 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2427 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2428 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_cppVar_1144 = _ZN11model_train28cppUpdateFun_visibleEnergiesElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2418, llvm_cbe_tmp__2419, llvm_cbe_tmp__2420, llvm_cbe_tmp__2421, llvm_cbe_tmp__2422, llvm_cbe_tmp__2423, llvm_cbe_tmp__2424, llvm_cbe_tmp__2425, llvm_cbe_tmp__2426, llvm_cbe_tmp__2427, llvm_cbe_tmp__2428);
  llvm_cbe_tmp__2429 = *(&llvm_cbe_tmp__2215);
  llvm_cbe_tmp__2430 = *(&llvm_cbe_tmp__2216);
  llvm_cbe_tmp__2431 = *(&llvm_cbe_tmp__2217);
  llvm_cbe_tmp__2432 = *(&llvm_cbe_tmp__2218);
  llvm_cbe_tmp__2433 = *(&llvm_cbe_tmp__2219);
  llvm_cbe_tmp__2434 = *(&llvm_cbe_tmp__2220);
  llvm_cbe_tmp__2435 = *(&llvm_cbe_tmp__2221);
  llvm_cbe_tmp__2436 = *(&llvm_cbe_tmp__2222);
  llvm_cbe_tmp__2437 = *(&llvm_cbe_tmp__2223);
  llvm_cbe_tmp__2438 = *(&llvm_cbe_tmp__2224);
  llvm_cbe_tmp__2439 = *(&llvm_cbe_tmp__2225);
  llvm_cbe_cppVar_1195 = _ZN11model_train25cppUpdateFun_visible_unitElllllllllll(llvm_cbe_tmp__2229, llvm_cbe_tmp__2429, llvm_cbe_tmp__2430, llvm_cbe_tmp__2431, llvm_cbe_tmp__2432, llvm_cbe_tmp__2433, llvm_cbe_tmp__2434, llvm_cbe_tmp__2435, llvm_cbe_tmp__2436, llvm_cbe_tmp__2437, llvm_cbe_tmp__2438, llvm_cbe_tmp__2439);
  llvm_cbe_tmp__2440 = *(&llvm_cbe_cppVar_512);
  *((&llvm_cbe_tmp__2229->field5)) = llvm_cbe_tmp__2440;
  llvm_cbe_tmp__2441 = *(&llvm_cbe_cppVar_549);
  *((&llvm_cbe_tmp__2229->field7)) = llvm_cbe_tmp__2441;
  llvm_cbe_tmp__2442 = *(&llvm_cbe_cppVar_571);
  *((&llvm_cbe_tmp__2229->field8)) = llvm_cbe_tmp__2442;
  llvm_cbe_tmp__2443 = *(&llvm_cbe_cppVar_618);
  *((&llvm_cbe_tmp__2229->field15)) = llvm_cbe_tmp__2443;
  llvm_cbe_tmp__2444 = *(&llvm_cbe_cppVar_654);
  *((&llvm_cbe_tmp__2229->field24)) = llvm_cbe_tmp__2444;
  llvm_cbe_tmp__2445 = *(&llvm_cbe_cppVar_704);
  *((&llvm_cbe_tmp__2229->field25)) = llvm_cbe_tmp__2445;
  llvm_cbe_tmp__2446 = *(&llvm_cbe_cppVar_719);
  *((&llvm_cbe_tmp__2229->field26)) = llvm_cbe_tmp__2446;
  llvm_cbe_tmp__2447 = *(&llvm_cbe_cppVar_777);
  *((&llvm_cbe_tmp__2229->field27)) = llvm_cbe_tmp__2447;
  llvm_cbe_tmp__2448 = *(&llvm_cbe_cppVar_837);
  *((&llvm_cbe_tmp__2229->field28)) = llvm_cbe_tmp__2448;
  llvm_cbe_tmp__2449 = *(&llvm_cbe_cppVar_884);
  *((&llvm_cbe_tmp__2229->field29)) = llvm_cbe_tmp__2449;
  llvm_cbe_tmp__2450 = *(&llvm_cbe_cppVar_932);
  *((&llvm_cbe_tmp__2229->field30)) = llvm_cbe_tmp__2450;
  llvm_cbe_tmp__2451 = *(&llvm_cbe_cppVar_947);
  *((&llvm_cbe_tmp__2229->field31)) = llvm_cbe_tmp__2451;
  llvm_cbe_tmp__2452 = _ZN8type_memIhLj65536EEaSERKS0_(((&llvm_cbe_tmp__2229->field3)), (&llvm_cbe_cppVar_990));
  llvm_cbe_tmp__2453 = _ZN8type_memIbLj128EEaSERKS0_(((&llvm_cbe_tmp__2229->field4)), (&llvm_cbe_cppVar_1037));
  llvm_cbe_tmp__2454 = _ZN8type_memIbLj65536EEaSERKS0_(((&llvm_cbe_tmp__2229->field16)), (&llvm_cbe_cppVar_1055));
  llvm_cbe_tmp__2455 = _ZN8type_memIjLj8EEaSERKS0_(((&llvm_cbe_tmp__2229->field17)), (&llvm_cbe_cppVar_1086));
  llvm_cbe_tmp__2456 = _ZN8type_memItLj8EEaSERKS0_(((&llvm_cbe_tmp__2229->field32)), (&llvm_cbe_cppVar_1144));
  llvm_cbe_tmp__2457 = _ZN8type_memIbLj512EEaSERKS0_(((&llvm_cbe_tmp__2229->field33)), (&llvm_cbe_cppVar_1195));
  *(&llvm_cbe_tmp__2228) = 1u;
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1195));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1144));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1086));
  _ZN8type_memIbLj65536EED1Ev((&llvm_cbe_cppVar_1055));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1037));
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_990));
  return;
}


static void __cxx_global_var_init(void) {
  unsigned int llvm_cbe_tmp__2458;

  _ZN11model_trainC1Ev((&GM));
  llvm_cbe_tmp__2458 = __cxa_atexit(((void  (*) (unsigned char *))_ZN11model_trainD1Ev), ((unsigned char *)(&GM)), ((unsigned char *)(&__dso_handle)));
  return;
}


void _ZN11model_trainC1Ev(struct l_class_OC_model_train *llvm_cbe_this) {
  struct l_class_OC_model_train *llvm_cbe_tmp__2459;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__2460;

  *(&llvm_cbe_tmp__2459) = llvm_cbe_this;
  llvm_cbe_tmp__2460 = *(&llvm_cbe_tmp__2459);
  _ZN11model_trainC2Ev(llvm_cbe_tmp__2460);
  return;
}


void _ZN11model_trainD1Ev(struct l_class_OC_model_train *llvm_cbe_this) {
  struct l_class_OC_model_train *llvm_cbe_tmp__2461;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__2462;

  *(&llvm_cbe_tmp__2461) = llvm_cbe_this;
  llvm_cbe_tmp__2462 = *(&llvm_cbe_tmp__2461);
  _ZN11model_trainD2Ev(llvm_cbe_tmp__2462);
  return;
}


void _Z4waitv(void) {
  unsigned int llvm_cbe_tmp__2463;

  llvm_cbe_tmp__2463 = *(&cycleCnt);
  *(&cycleCnt) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2463) + ((unsigned int )1u))));
  return;
}


void _Z15reset_signal_isib(unsigned int llvm_cbe_tmp__2464, bool llvm_cbe_tmp__2465) {
  unsigned int llvm_cbe_tmp__2466;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2467;    /* Address-exposed local */

  *(&llvm_cbe_tmp__2466) = llvm_cbe_tmp__2464;
  *(&llvm_cbe_tmp__2467) = (((unsigned char )(bool )llvm_cbe_tmp__2465));
  return;
}


void _Z14set_stack_sizei(unsigned int llvm_cbe_tmp__2468) {
  unsigned int llvm_cbe_tmp__2469;    /* Address-exposed local */

  *(&llvm_cbe_tmp__2469) = llvm_cbe_tmp__2468;
  return;
}


unsigned long long _Z8_c_16_15f(float llvm_cbe_in) {
  float llvm_cbe_tmp__2470;    /* Address-exposed local */
  float llvm_cbe_tmp__2471;

  *(&llvm_cbe_tmp__2470) = llvm_cbe_in;
  llvm_cbe_tmp__2471 = *(&llvm_cbe_tmp__2470);
  return ((((signed long long )(((float )(llvm_cbe_tmp__2471 * 0x1p+1))))) & 65535ull);
}


float _Z8_b_16_15l(unsigned long long llvm_cbe_in) {
  unsigned long long llvm_cbe_tmp__2472;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2473;

  *(&llvm_cbe_tmp__2472) = llvm_cbe_in;
  llvm_cbe_tmp__2473 = *(&llvm_cbe_tmp__2472);
  return (((float )((((double )(signed long long )(llvm_cbe_tmp__2473 & 65535ull))) / 0x1p+1)));
}


void _ZN3rbm6configEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2474;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2475;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2476;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2477;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2478;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2479;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2480;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2481;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2482;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2483;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2484;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2485;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2486;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2487;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2488;
  bool llvm_cbe_tmp__2489;
  unsigned int llvm_cbe_tmp__2490;
  unsigned int llvm_cbe_tmp__2491;
  unsigned int llvm_cbe_tmp__2492;
  unsigned int llvm_cbe_tmp__2493;
  unsigned int llvm_cbe_tmp__2494;
  unsigned int llvm_cbe_tmp__2495;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2496;
  unsigned int llvm_cbe_tmp__2497;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2498;

  *(&llvm_cbe_tmp__2474) = llvm_cbe_this;
  llvm_cbe_tmp__2488 = *(&llvm_cbe_tmp__2474);
  *(&llvm_cbe_tmp__2475) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field30)), (&llvm_cbe_tmp__2475));
  *(&llvm_cbe_tmp__2476) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field31)), (&llvm_cbe_tmp__2476));
  *(&llvm_cbe_tmp__2477) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field32)), (&llvm_cbe_tmp__2477));
  *(&llvm_cbe_tmp__2478) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field33)), (&llvm_cbe_tmp__2478));
  *(&llvm_cbe_tmp__2479) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field35)), (&llvm_cbe_tmp__2479));
  *(&llvm_cbe_tmp__2480) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2488->field36)), (&llvm_cbe_tmp__2480));
  _Z4waitv();
  goto llvm_cbe_tmp__2499;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2499:
  _Z4waitv();
  llvm_cbe_tmp__2489 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2488->field13))))&1);
  if ((((llvm_cbe_tmp__2489 ^ 1)&1))) {
    goto llvm_cbe_tmp__2499;
  } else {
    goto llvm_cbe_tmp__2500;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2500:
  llvm_cbe_tmp__2490 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2488->field14)));
  *(&llvm_cbe_tmp__2481) = (((unsigned short )llvm_cbe_tmp__2490));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field30)), (&llvm_cbe_tmp__2481));
  llvm_cbe_tmp__2491 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2488->field15)));
  *(&llvm_cbe_tmp__2482) = (((unsigned short )llvm_cbe_tmp__2491));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field31)), (&llvm_cbe_tmp__2482));
  llvm_cbe_tmp__2492 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2488->field16)));
  *(&llvm_cbe_tmp__2483) = (((unsigned short )llvm_cbe_tmp__2492));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field32)), (&llvm_cbe_tmp__2483));
  llvm_cbe_tmp__2493 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2488->field17)));
  *(&llvm_cbe_tmp__2484) = (((unsigned short )llvm_cbe_tmp__2493));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field33)), (&llvm_cbe_tmp__2484));
  llvm_cbe_tmp__2494 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2488->field18)));
  *(&llvm_cbe_tmp__2485) = (((unsigned short )llvm_cbe_tmp__2494));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field34)), (&llvm_cbe_tmp__2485));
  llvm_cbe_tmp__2495 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2488->field19)));
  *(&llvm_cbe_tmp__2486) = (((unsigned short )llvm_cbe_tmp__2495));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2488->field35)), (&llvm_cbe_tmp__2486));
  llvm_cbe_tmp__2496 = _ZNSt6iocoutlsEPKc((&_ZSt4cout), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__2497 = *(&_ZSt4endl);
  llvm_cbe_tmp__2498 = _ZNSt6iocoutlsEi(llvm_cbe_tmp__2496, llvm_cbe_tmp__2497);
  *(&llvm_cbe_tmp__2487) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2488->field36)), (&llvm_cbe_tmp__2487));
  goto llvm_cbe_tmp__2501;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2501:
  _Z4waitv();
  goto llvm_cbe_tmp__2501;

  } while (1); /* end of syntactic loop '' */
}


void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__2502;    /* Address-exposed local */
  unsigned short *llvm_cbe_tmp__2503;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__2504;
  unsigned short *llvm_cbe_tmp__2505;
  unsigned short llvm_cbe_tmp__2506;

  *(&llvm_cbe_tmp__2502) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2503) = llvm_cbe_d;
  llvm_cbe_tmp__2504 = *(&llvm_cbe_tmp__2502);
  llvm_cbe_tmp__2505 = *(&llvm_cbe_tmp__2503);
  llvm_cbe_tmp__2506 = *llvm_cbe_tmp__2505;
  *((&llvm_cbe_tmp__2504->field0)) = llvm_cbe_tmp__2506;
  return;
}


void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2507;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2508;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2509;
  unsigned char *llvm_cbe_tmp__2510;
  unsigned char llvm_cbe_tmp__2511;

  *(&llvm_cbe_tmp__2507) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2508) = llvm_cbe_d;
  llvm_cbe_tmp__2509 = *(&llvm_cbe_tmp__2507);
  llvm_cbe_tmp__2510 = *(&llvm_cbe_tmp__2508);
  llvm_cbe_tmp__2511 = *llvm_cbe_tmp__2510;
  *((&llvm_cbe_tmp__2509->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2511&1u))&1))));
  return;
}


bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2512;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2513;
  unsigned char llvm_cbe_tmp__2514;

  *(&llvm_cbe_tmp__2512) = llvm_cbe_this;
  llvm_cbe_tmp__2513 = *(&llvm_cbe_tmp__2512);
  llvm_cbe_tmp__2514 = *((&llvm_cbe_tmp__2513->field0));
  return (((((bool )llvm_cbe_tmp__2514&1u))&1));
}


unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2515;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2516;
  unsigned int llvm_cbe_tmp__2517;

  *(&llvm_cbe_tmp__2515) = llvm_cbe_this;
  llvm_cbe_tmp__2516 = *(&llvm_cbe_tmp__2515);
  llvm_cbe_tmp__2517 = *((&llvm_cbe_tmp__2516->field0));
  return llvm_cbe_tmp__2517;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_tmp__2518) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2519;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2520;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2521;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2522;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2523;

  *(&llvm_cbe_tmp__2520) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2521) = llvm_cbe_tmp__2518;
  llvm_cbe_tmp__2522 = *(&llvm_cbe_tmp__2520);
  llvm_cbe_tmp__2523 = *(&llvm_cbe_tmp__2519);
  return llvm_cbe_tmp__2523;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEi(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned int llvm_cbe_tmp__2524) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2525;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2526;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2527;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2528;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2529;

  *(&llvm_cbe_tmp__2526) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2527) = llvm_cbe_tmp__2524;
  llvm_cbe_tmp__2528 = *(&llvm_cbe_tmp__2526);
  llvm_cbe_tmp__2529 = *(&llvm_cbe_tmp__2525);
  return llvm_cbe_tmp__2529;
}


void _ZN3rbm4loadEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2530;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2531;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2532;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2533;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2534;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2535;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2536;    /* Address-exposed local */
  unsigned short llvm_cbe_index;    /* Address-exposed local */
  unsigned short llvm_cbe_loop_count;    /* Address-exposed local */
  unsigned char llvm_cbe_pingpong;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned int llvm_cbe_nv;    /* Address-exposed local */
  unsigned int llvm_cbe_ntu;    /* Address-exposed local */
  unsigned int llvm_cbe_nu;    /* Address-exposed local */
  unsigned int llvm_cbe_nlp;    /* Address-exposed local */
  unsigned int llvm_cbe_nm;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2537;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2538;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2539;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2540;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned char llvm_cbe_rate;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2541;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2542;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2543;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2544;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2545;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2546;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2547;    /* Address-exposed local */
  unsigned short llvm_cbe_i1;    /* Address-exposed local */
  unsigned char llvm_cbe_rate2;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2548;
  bool llvm_cbe_tmp__2549;
  bool llvm_cbe_tmp__2550;
  unsigned short llvm_cbe_tmp__2551;
  unsigned short llvm_cbe_tmp__2552;
  unsigned short llvm_cbe_tmp__2553;
  unsigned short llvm_cbe_tmp__2554;
  unsigned short llvm_cbe_tmp__2555;
  unsigned short llvm_cbe_tmp__2556;
  unsigned int llvm_cbe_tmp__2557;
  unsigned short llvm_cbe_tmp__2558;
  unsigned int llvm_cbe_tmp__2559;
  bool llvm_cbe_tmp__2560;
  bool llvm_cbe_tmp__2561;
  unsigned short llvm_cbe_tmp__2562;
  unsigned int llvm_cbe_tmp__2563;
  unsigned short llvm_cbe_tmp__2564;
  unsigned short llvm_cbe_tmp__2565;
  unsigned short llvm_cbe_tmp__2566;
  unsigned short llvm_cbe_tmp__2567;
  unsigned short llvm_cbe_tmp__2568;
  unsigned int llvm_cbe_tmp__2569;
  unsigned int llvm_cbe_tmp__2570;
  unsigned char llvm_cbe_tmp__2571;
  unsigned short llvm_cbe_tmp__2572;
  unsigned char llvm_cbe_tmp__2573;
  unsigned char *llvm_cbe_tmp__2574;
  unsigned short llvm_cbe_tmp__2575;
  unsigned int llvm_cbe_tmp__2576;
  unsigned char llvm_cbe_tmp__2577;
  unsigned char *llvm_cbe_tmp__2578;
  unsigned short llvm_cbe_tmp__2579;
  unsigned int llvm_cbe_tmp__2580;
  bool llvm_cbe_tmp__2581;
  bool llvm_cbe_tmp__2582;
  bool llvm_cbe_tmp__2583;
  bool llvm_cbe_tmp__2584;
  unsigned short llvm_cbe_tmp__2585;
  unsigned short llvm_cbe_tmp__2586;
  unsigned int llvm_cbe_tmp__2587;
  unsigned short llvm_cbe_tmp__2588;
  unsigned int llvm_cbe_tmp__2589;
  unsigned short llvm_cbe_tmp__2590;
  unsigned short llvm_cbe_tmp__2591;
  unsigned int llvm_cbe_tmp__2592;
  unsigned short llvm_cbe_tmp__2593;
  unsigned int llvm_cbe_tmp__2594;
  unsigned int llvm_cbe_tmp__2595;
  unsigned short llvm_cbe_tmp__2596;
  unsigned short llvm_cbe_tmp__2597;
  unsigned int llvm_cbe_tmp__2598;
  unsigned int llvm_cbe_tmp__2599;
  unsigned int llvm_cbe_tmp__2600;
  unsigned int llvm_cbe_tmp__2601;
  unsigned int llvm_cbe_tmp__2602;
  unsigned short llvm_cbe_tmp__2603;
  unsigned int llvm_cbe_tmp__2604;
  bool llvm_cbe_tmp__2605;
  bool llvm_cbe_tmp__2606;
  unsigned short llvm_cbe_tmp__2607;
  unsigned int llvm_cbe_tmp__2608;
  unsigned short llvm_cbe_tmp__2609;
  unsigned short llvm_cbe_tmp__2610;
  unsigned short llvm_cbe_tmp__2611;
  unsigned short llvm_cbe_tmp__2612;
  unsigned short llvm_cbe_tmp__2613;
  unsigned int llvm_cbe_tmp__2614;
  unsigned int llvm_cbe_tmp__2615;
  unsigned char llvm_cbe_tmp__2616;
  unsigned short llvm_cbe_tmp__2617;
  unsigned char llvm_cbe_tmp__2618;
  unsigned char *llvm_cbe_tmp__2619;
  unsigned short llvm_cbe_tmp__2620;
  unsigned int llvm_cbe_tmp__2621;
  unsigned char llvm_cbe_tmp__2622;
  unsigned char *llvm_cbe_tmp__2623;

  *(&llvm_cbe_tmp__2530) = llvm_cbe_this;
  llvm_cbe_tmp__2548 = *(&llvm_cbe_tmp__2530);
  *(&llvm_cbe_tmp__2531) = ((unsigned char )1);
  llvm_cbe_tmp__2549 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2548->field36)), (&llvm_cbe_tmp__2531)))&1);
  *(&llvm_cbe_tmp__2532) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2548->field2)), (&llvm_cbe_tmp__2532));
  *(&llvm_cbe_tmp__2533) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2548->field3)), (&llvm_cbe_tmp__2533));
  *(&llvm_cbe_tmp__2534) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field4)), (&llvm_cbe_tmp__2534));
  *(&llvm_cbe_tmp__2535) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field37)), (&llvm_cbe_tmp__2535));
  *(&llvm_cbe_tmp__2536) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field38)), (&llvm_cbe_tmp__2536));
  goto llvm_cbe_tmp__2624;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2624:
  _Z4waitv();
  llvm_cbe_tmp__2550 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field36))))&1);
  if ((((llvm_cbe_tmp__2550 ^ 1)&1))) {
    goto llvm_cbe_tmp__2624;
  } else {
    goto llvm_cbe_tmp__2625;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2625:
  *(&llvm_cbe_index) = ((unsigned short )0);
  *(&llvm_cbe_loop_count) = ((unsigned short )0);
  *(&llvm_cbe_pingpong) = ((unsigned char )0);
  llvm_cbe_tmp__2551 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2548->field31)));
  *(&llvm_cbe_nv) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2551));
  llvm_cbe_tmp__2552 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2548->field34)));
  *(&llvm_cbe_ntu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2552));
  llvm_cbe_tmp__2553 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2548->field32)));
  *(&llvm_cbe_nu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2553));
  llvm_cbe_tmp__2554 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2548->field33)));
  *(&llvm_cbe_nlp) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2554));
  llvm_cbe_tmp__2555 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2548->field35)));
  *(&llvm_cbe_nm) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2555));
  *(&upc) = 0u;
  llvm_cbe_tmp__2556 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp__2537) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2556));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2548->field2)), (&llvm_cbe_tmp__2537));
  llvm_cbe_tmp__2557 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__2538) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__2557))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2548->field3)), (&llvm_cbe_tmp__2538));
  llvm_cbe_tmp__2558 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2559 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2558)) == llvm_cbe_tmp__2559)) {
    goto llvm_cbe_tmp__2626;
  } else {
    goto llvm_cbe_tmp__2627;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2626:
  _Z4waitv();
  llvm_cbe_tmp__2560 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field40))))&1);
  if ((((llvm_cbe_tmp__2560 ^ 1)&1))) {
    goto llvm_cbe_tmp__2626;
  } else {
    goto llvm_cbe_tmp__2627;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2627:
  *(&llvm_cbe_tmp__2539) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field4)), (&llvm_cbe_tmp__2539));
  goto llvm_cbe_tmp__2628;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2628:
  _Z4waitv();
  *(&upc) = 1u;
  llvm_cbe_tmp__2561 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field5))))&1);
  if ((((llvm_cbe_tmp__2561 ^ 1)&1))) {
    goto llvm_cbe_tmp__2628;
  } else {
    goto llvm_cbe_tmp__2629;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2629:
  *(&llvm_cbe_tmp__2540) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field4)), (&llvm_cbe_tmp__2540));
  llvm_cbe_tmp__2562 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2563 = *(&llvm_cbe_nu);
  *(&llvm_cbe_tmp1) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2562))) * ((unsigned int )llvm_cbe_tmp__2563))))));
  llvm_cbe_tmp__2564 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__2565 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp2) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2564))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2565))))))));
  llvm_cbe_tmp__2566 = *(&llvm_cbe_tmp2);
  *(&llvm_cbe_pingpong) = (((unsigned char )(bool )((((signed int )(((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2566))) % ((signed int )2u)))) != 0u)));
  *(&llvm_cbe_i) = ((unsigned short )0);
  goto llvm_cbe_tmp__2630;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2630:
  llvm_cbe_tmp__2567 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2567))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__2631;
  } else {
    goto llvm_cbe_tmp__2632;
  }

llvm_cbe_tmp__2633:
  llvm_cbe_tmp__2570 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2548->field6)));
  *(&llvm_cbe_rate) = (((unsigned char )llvm_cbe_tmp__2570));
  _Z4waitv();
  llvm_cbe_tmp__2571 = *(&llvm_cbe_rate);
  llvm_cbe_tmp__2572 = *(&llvm_cbe_i);
  llvm_cbe_tmp__2573 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__2574 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2548->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2573&1u))&1)))));
  *((&llvm_cbe_tmp__2574[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2572)))])) = llvm_cbe_tmp__2571;
  llvm_cbe_tmp__2575 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2575) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2630;

llvm_cbe_tmp__2631:
  llvm_cbe_tmp__2568 = *(&llvm_cbe_i);
  llvm_cbe_tmp__2569 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2568)) == llvm_cbe_tmp__2569)) {
    goto llvm_cbe_tmp__2632;
  } else {
    goto llvm_cbe_tmp__2633;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2632:
  _Z4waitv();
  llvm_cbe_tmp__2576 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__2577 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__2578 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2548->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2577&1u))&1)))));
  *((&llvm_cbe_tmp__2578[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__2576)))])) = ((unsigned char )1);
  *(&upc) = 2u;
  goto llvm_cbe_tmp__2634;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2634:
  llvm_cbe_tmp__2579 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2580 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2579)) != llvm_cbe_tmp__2580)) {
    goto llvm_cbe_tmp__2635;
  } else {
    goto llvm_cbe_tmp__2636;
  }

llvm_cbe_tmp__2637:
  _Z4waitv();
  llvm_cbe_tmp__2621 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__2622 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__2623 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2548->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2622&1u))&1)))));
  *((&llvm_cbe_tmp__2623[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__2621)))])) = ((unsigned char )1);
  goto llvm_cbe_tmp__2634;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2638:
  llvm_cbe_tmp__2612 = *(&llvm_cbe_i1);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2612))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__2639;
  } else {
    goto llvm_cbe_tmp__2637;
  }

llvm_cbe_tmp__2640:
  llvm_cbe_tmp__2615 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2548->field6)));
  *(&llvm_cbe_rate2) = (((unsigned char )llvm_cbe_tmp__2615));
  _Z4waitv();
  llvm_cbe_tmp__2616 = *(&llvm_cbe_rate2);
  llvm_cbe_tmp__2617 = *(&llvm_cbe_i1);
  llvm_cbe_tmp__2618 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__2619 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2548->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2618&1u))&1)))));
  *((&llvm_cbe_tmp__2619[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2617)))])) = llvm_cbe_tmp__2616;
  llvm_cbe_tmp__2620 = *(&llvm_cbe_i1);
  *(&llvm_cbe_i1) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2620) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2638;

llvm_cbe_tmp__2639:
  llvm_cbe_tmp__2613 = *(&llvm_cbe_i1);
  llvm_cbe_tmp__2614 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2613)) == llvm_cbe_tmp__2614)) {
    goto llvm_cbe_tmp__2637;
  } else {
    goto llvm_cbe_tmp__2640;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2641:
  *(&llvm_cbe_tmp__2547) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field4)), (&llvm_cbe_tmp__2547));
  llvm_cbe_tmp__2607 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2608 = *(&llvm_cbe_nu);
  *(&llvm_cbe_tmp1) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2607))) * ((unsigned int )llvm_cbe_tmp__2608))))));
  llvm_cbe_tmp__2609 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__2610 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp2) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2609))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2610))))))));
  llvm_cbe_tmp__2611 = *(&llvm_cbe_tmp2);
  *(&llvm_cbe_pingpong) = (((unsigned char )(bool )((((signed int )(((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2611))) % ((signed int )2u)))) != 0u)));
  *(&llvm_cbe_i1) = ((unsigned short )0);
  goto llvm_cbe_tmp__2638;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2642:
  _Z4waitv();
  llvm_cbe_tmp__2606 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field5))))&1);
  if ((((llvm_cbe_tmp__2606 ^ 1)&1))) {
    goto llvm_cbe_tmp__2642;
  } else {
    goto llvm_cbe_tmp__2641;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2643:
  *(&llvm_cbe_tmp__2546) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field4)), (&llvm_cbe_tmp__2546));
  goto llvm_cbe_tmp__2642;

llvm_cbe_tmp__2644:
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2548->field2)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__2602 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__2545) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__2602))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2548->field3)), (&llvm_cbe_tmp__2545));
  llvm_cbe_tmp__2603 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2604 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2603)) == llvm_cbe_tmp__2604)) {
    goto llvm_cbe_tmp__2645;
  } else {
    goto llvm_cbe_tmp__2643;
  }

llvm_cbe_tmp__2646:
  llvm_cbe_tmp__2595 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__2596 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2595) * ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2596))))));
  llvm_cbe_tmp__2597 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2598 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2597)) == llvm_cbe_tmp__2598)) {
    goto llvm_cbe_tmp__2647;
  } else {
    goto llvm_cbe_tmp__2644;
  }

llvm_cbe_tmp__2648:
  llvm_cbe_tmp__2591 = *(&llvm_cbe_index);
  llvm_cbe_tmp__2592 = *(&llvm_cbe_ntu);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2591)) == llvm_cbe_tmp__2592)) {
    goto llvm_cbe_tmp__2649;
  } else {
    goto llvm_cbe_tmp__2646;
  }

llvm_cbe_tmp__2650:
  llvm_cbe_tmp__2585 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2585))) + ((unsigned int )1u))))));
  llvm_cbe_tmp__2586 = *(&llvm_cbe_index);
  llvm_cbe_tmp__2587 = *(&llvm_cbe_nu);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2586)) == llvm_cbe_tmp__2587)) {
    goto llvm_cbe_tmp__2651;
  } else {
    goto llvm_cbe_tmp__2648;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2652:
  _Z4waitv();
  llvm_cbe_tmp__2582 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field39))))&1);
  if (llvm_cbe_tmp__2582) {
    goto llvm_cbe_tmp__2652;
  } else {
    goto llvm_cbe_tmp__2650;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2653:
  *(&llvm_cbe_tmp__2542) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field37)), (&llvm_cbe_tmp__2542));
  goto llvm_cbe_tmp__2652;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2654:
  _Z4waitv();
  llvm_cbe_tmp__2581 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field39))))&1);
  if ((((llvm_cbe_tmp__2581 ^ 1)&1))) {
    goto llvm_cbe_tmp__2654;
  } else {
    goto llvm_cbe_tmp__2653;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2635:
  *(&llvm_cbe_tmp__2541) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field37)), (&llvm_cbe_tmp__2541));
  *(&upc) = 2u;
  goto llvm_cbe_tmp__2654;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2655:
  _Z4waitv();
  llvm_cbe_tmp__2584 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field42))))&1);
  if (llvm_cbe_tmp__2584) {
    goto llvm_cbe_tmp__2655;
  } else {
    goto llvm_cbe_tmp__2650;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2656:
  *(&llvm_cbe_tmp__2544) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field38)), (&llvm_cbe_tmp__2544));
  goto llvm_cbe_tmp__2655;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2657:
  _Z4waitv();
  llvm_cbe_tmp__2583 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field42))))&1);
  if ((((llvm_cbe_tmp__2583 ^ 1)&1))) {
    goto llvm_cbe_tmp__2657;
  } else {
    goto llvm_cbe_tmp__2656;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2636:
  *(&llvm_cbe_tmp__2543) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2548->field38)), (&llvm_cbe_tmp__2543));
  *(&upc) = 2u;
  goto llvm_cbe_tmp__2657;

llvm_cbe_tmp__2651:
  llvm_cbe_tmp__2588 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2589 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2588)) != llvm_cbe_tmp__2589)) {
    goto llvm_cbe_tmp__2658;
  } else {
    goto llvm_cbe_tmp__2648;
  }

llvm_cbe_tmp__2658:
  llvm_cbe_tmp__2590 = *(&llvm_cbe_loop_count);
  *(&llvm_cbe_loop_count) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2590))) + ((unsigned int )1u))))));
  *(&llvm_cbe_index) = ((unsigned short )0);
  goto llvm_cbe_tmp__2648;

llvm_cbe_tmp__2649:
  llvm_cbe_tmp__2593 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2594 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2593)) == llvm_cbe_tmp__2594)) {
    goto llvm_cbe_tmp__2659;
  } else {
    goto llvm_cbe_tmp__2646;
  }

llvm_cbe_tmp__2647:
  llvm_cbe_tmp__2599 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__2600 = *(&llvm_cbe_nu);
  llvm_cbe_tmp__2601 = *(&llvm_cbe_dma_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2601) + ((unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2599) * ((unsigned int )llvm_cbe_tmp__2600))))))));
  goto llvm_cbe_tmp__2644;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2645:
  _Z4waitv();
  llvm_cbe_tmp__2605 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2548->field40))))&1);
  if ((((llvm_cbe_tmp__2605 ^ 1)&1))) {
    goto llvm_cbe_tmp__2645;
  } else {
    goto llvm_cbe_tmp__2643;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2659:
  _Z4waitv();
  *(&upc) = 3u;
  goto llvm_cbe_tmp__2659;

  } while (1); /* end of syntactic loop '' */
}


bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2660;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2661;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2662;
  unsigned char *llvm_cbe_tmp__2663;
  unsigned char llvm_cbe_tmp__2664;
  unsigned char llvm_cbe_tmp__2665;

  *(&llvm_cbe_tmp__2660) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2661) = llvm_cbe_d;
  llvm_cbe_tmp__2662 = *(&llvm_cbe_tmp__2660);
  llvm_cbe_tmp__2663 = *(&llvm_cbe_tmp__2661);
  llvm_cbe_tmp__2664 = *llvm_cbe_tmp__2663;
  *((&llvm_cbe_tmp__2662->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2664&1u))&1))));
  llvm_cbe_tmp__2665 = *((&llvm_cbe_tmp__2662->field0));
  return (((((bool )llvm_cbe_tmp__2665&1u))&1));
}


void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2666;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__2667;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2668;
  unsigned int *llvm_cbe_tmp__2669;
  unsigned int llvm_cbe_tmp__2670;

  *(&llvm_cbe_tmp__2666) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2667) = llvm_cbe_d;
  llvm_cbe_tmp__2668 = *(&llvm_cbe_tmp__2666);
  llvm_cbe_tmp__2669 = *(&llvm_cbe_tmp__2667);
  llvm_cbe_tmp__2670 = *llvm_cbe_tmp__2669;
  *((&llvm_cbe_tmp__2668->field0)) = llvm_cbe_tmp__2670;
  return;
}


unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__2671;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__2672;
  unsigned short llvm_cbe_tmp__2673;

  *(&llvm_cbe_tmp__2671) = llvm_cbe_this;
  llvm_cbe_tmp__2672 = *(&llvm_cbe_tmp__2671);
  llvm_cbe_tmp__2673 = *((&llvm_cbe_tmp__2672->field0));
  return llvm_cbe_tmp__2673;
}


unsigned char *_ZN13SysCArray2DstIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__2674;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__2675;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2676;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__2677;
  unsigned int llvm_cbe_tmp__2678;
  unsigned char *llvm_cbe_tmp__2679;
  unsigned int llvm_cbe_tmp__2680;
  unsigned char *llvm_cbe_tmp__2681;
  unsigned char *llvm_cbe_tmp__2682;

  *(&llvm_cbe_tmp__2675) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2676) = llvm_cbe_Xidx;
  llvm_cbe_tmp__2677 = *(&llvm_cbe_tmp__2675);
  llvm_cbe_tmp__2678 = *(&llvm_cbe_tmp__2676);
  if ((llvm_cbe_tmp__2678 == 0u)) {
    goto llvm_cbe_tmp__2683;
  } else {
    goto llvm_cbe_tmp__2684;
  }

llvm_cbe_tmp__2683:
  llvm_cbe_tmp__2679 = *((&llvm_cbe_tmp__2677->field1));
  *(&llvm_cbe_tmp__2674) = llvm_cbe_tmp__2679;
  goto llvm_cbe_tmp__2685;

llvm_cbe_tmp__2684:
  llvm_cbe_tmp__2680 = *(&llvm_cbe_tmp__2676);
  llvm_cbe_tmp__2681 = *((&llvm_cbe_tmp__2677->field0));
  *(&llvm_cbe_tmp__2674) = ((&llvm_cbe_tmp__2681[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2680) * ((unsigned int )512u)))))))]));
  goto llvm_cbe_tmp__2685;

llvm_cbe_tmp__2685:
  llvm_cbe_tmp__2682 = *(&llvm_cbe_tmp__2674);
  return llvm_cbe_tmp__2682;
}


void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2686;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2687;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2688;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2689;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2690;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2691;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2692;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2693;    /* Address-exposed local */
  unsigned short llvm_cbe_ntu;    /* Address-exposed local */
  unsigned short llvm_cbe_nm;    /* Address-exposed local */
  unsigned int llvm_cbe_index;    /* Address-exposed local */
  unsigned char llvm_cbe_rating;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2694;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2695;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2696;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2697;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2698;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2699;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2700;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2701;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2702;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2703;
  bool llvm_cbe_tmp__2704;
  bool llvm_cbe_tmp__2705;
  unsigned short llvm_cbe_tmp__2706;
  unsigned short llvm_cbe_tmp__2707;
  unsigned int llvm_cbe_tmp__2708;
  unsigned short llvm_cbe_tmp__2709;
  bool llvm_cbe_tmp__2710;
  bool llvm_cbe_tmp__2711;
  unsigned short llvm_cbe_tmp__2712;
  unsigned int llvm_cbe_tmp__2713;
  unsigned short llvm_cbe_tmp__2714;
  unsigned int llvm_cbe_tmp__2715;
  bool llvm_cbe_tmp__2716;
  unsigned short llvm_cbe_tmp__2717;
  unsigned short llvm_cbe_tmp__2718;
  unsigned short llvm_cbe_tmp__2719;
  unsigned short llvm_cbe_tmp__2720;
  unsigned char *llvm_cbe_tmp__2721;
  unsigned char llvm_cbe_tmp__2722;
  unsigned char llvm_cbe_tmp__2723;
  unsigned short llvm_cbe_tmp__2724;

  *(&llvm_cbe_tmp__2686) = llvm_cbe_this;
  llvm_cbe_tmp__2703 = *(&llvm_cbe_tmp__2686);
  *(&llvm_cbe_tmp__2687) = ((unsigned char )1);
  llvm_cbe_tmp__2704 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2703->field36)), (&llvm_cbe_tmp__2687)))&1);
  *(&llvm_cbe_tmp__2688) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2703->field8)), (&llvm_cbe_tmp__2688));
  *(&llvm_cbe_tmp__2689) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2703->field7)), (&llvm_cbe_tmp__2689));
  *(&llvm_cbe_tmp__2690) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field9)), (&llvm_cbe_tmp__2690));
  *(&llvm_cbe_tmp__2691) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field44)), (&llvm_cbe_tmp__2691));
  *(&llvm_cbe_tmp__2692) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field45)), (&llvm_cbe_tmp__2692));
  *(&llvm_cbe_tmp__2693) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field12)), (&llvm_cbe_tmp__2693));
  goto llvm_cbe_tmp__2725;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2725:
  _Z4waitv();
  llvm_cbe_tmp__2705 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2703->field36))))&1);
  if ((((llvm_cbe_tmp__2705 ^ 1)&1))) {
    goto llvm_cbe_tmp__2725;
  } else {
    goto llvm_cbe_tmp__2726;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2726:
  llvm_cbe_tmp__2706 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2703->field34)));
  *(&llvm_cbe_ntu) = llvm_cbe_tmp__2706;
  llvm_cbe_tmp__2707 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2703->field35)));
  *(&llvm_cbe_nm) = llvm_cbe_tmp__2707;
  *(&llvm_cbe_index) = 0u;
  goto llvm_cbe_tmp__2727;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2727:
  llvm_cbe_tmp__2708 = *(&llvm_cbe_index);
  llvm_cbe_tmp__2709 = *(&llvm_cbe_ntu);
  if ((llvm_cbe_tmp__2708 == (((unsigned int )(unsigned short )llvm_cbe_tmp__2709)))) {
    goto llvm_cbe_tmp__2728;
  } else {
    goto llvm_cbe_tmp__2729;
  }

llvm_cbe_tmp__2730:
  *(&llvm_cbe_tmp__2702) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field45)), (&llvm_cbe_tmp__2702));
  goto llvm_cbe_tmp__2727;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2731:
  llvm_cbe_tmp__2717 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2717))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__2732;
  } else {
    goto llvm_cbe_tmp__2730;
  }

llvm_cbe_tmp__2733:
  llvm_cbe_tmp__2720 = *(&llvm_cbe_i);
  llvm_cbe_tmp__2721 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2703->field28)), 0u);
  llvm_cbe_tmp__2722 = *((&llvm_cbe_tmp__2721[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2720)))]));
  *(&llvm_cbe_rating) = llvm_cbe_tmp__2722;
  _Z4waitv();
  llvm_cbe_tmp__2723 = *(&llvm_cbe_rating);
  *(&llvm_cbe_tmp__2701) = (((unsigned int )(unsigned char )llvm_cbe_tmp__2723));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2703->field11)), (&llvm_cbe_tmp__2701));
  llvm_cbe_tmp__2724 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2724) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2731;

llvm_cbe_tmp__2732:
  llvm_cbe_tmp__2718 = *(&llvm_cbe_i);
  llvm_cbe_tmp__2719 = *(&llvm_cbe_nm);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2718)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__2719)))) {
    goto llvm_cbe_tmp__2730;
  } else {
    goto llvm_cbe_tmp__2733;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2734:
  *(&llvm_cbe_tmp__2700) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field9)), (&llvm_cbe_tmp__2700));
  *(&llvm_cbe_i) = ((unsigned short )0);
  goto llvm_cbe_tmp__2731;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2735:
  _Z4waitv();
  llvm_cbe_tmp__2716 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2703->field10))))&1);
  if ((((llvm_cbe_tmp__2716 ^ 1)&1))) {
    goto llvm_cbe_tmp__2735;
  } else {
    goto llvm_cbe_tmp__2734;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2736:
  *(&llvm_cbe_tmp__2696) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field44)), (&llvm_cbe_tmp__2696));
  *(&llvm_cbe_tmp__2697) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field45)), (&llvm_cbe_tmp__2697));
  llvm_cbe_tmp__2712 = *(&llvm_cbe_nm);
  llvm_cbe_tmp__2713 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2712))) * ((unsigned int )llvm_cbe_tmp__2713))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2703->field7)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__2714 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2703->field35)));
  *(&llvm_cbe_tmp__2698) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2714));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2703->field8)), (&llvm_cbe_tmp__2698));
  llvm_cbe_tmp__2715 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2715) + ((unsigned int )1u))));
  *(&llvm_cbe_tmp__2699) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field9)), (&llvm_cbe_tmp__2699));
  goto llvm_cbe_tmp__2735;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2737:
  _Z4waitv();
  llvm_cbe_tmp__2711 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2703->field43))))&1);
  if (llvm_cbe_tmp__2711) {
    goto llvm_cbe_tmp__2737;
  } else {
    goto llvm_cbe_tmp__2736;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2738:
  *(&llvm_cbe_tmp__2695) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field44)), (&llvm_cbe_tmp__2695));
  goto llvm_cbe_tmp__2737;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2729:
  _Z4waitv();
  llvm_cbe_tmp__2710 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2703->field43))))&1);
  if ((((llvm_cbe_tmp__2710 ^ 1)&1))) {
    goto llvm_cbe_tmp__2729;
  } else {
    goto llvm_cbe_tmp__2738;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2728:
  *(&llvm_cbe_tmp__2694) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2703->field12)), (&llvm_cbe_tmp__2694));
  goto llvm_cbe_tmp__2739;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2739:
  _Z4waitv();
  goto llvm_cbe_tmp__2739;

  } while (1); /* end of syntactic loop '' */
}


unsigned char *_ZN13SysCArray2DstIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__2740;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__2741;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2742;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__2743;
  unsigned int llvm_cbe_tmp__2744;
  unsigned char *llvm_cbe_tmp__2745;
  unsigned int llvm_cbe_tmp__2746;
  unsigned char *llvm_cbe_tmp__2747;
  unsigned char *llvm_cbe_tmp__2748;

  *(&llvm_cbe_tmp__2741) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2742) = llvm_cbe_Xidx;
  llvm_cbe_tmp__2743 = *(&llvm_cbe_tmp__2741);
  llvm_cbe_tmp__2744 = *(&llvm_cbe_tmp__2742);
  if ((llvm_cbe_tmp__2744 == 0u)) {
    goto llvm_cbe_tmp__2749;
  } else {
    goto llvm_cbe_tmp__2750;
  }

llvm_cbe_tmp__2749:
  llvm_cbe_tmp__2745 = *((&llvm_cbe_tmp__2743->field1));
  *(&llvm_cbe_tmp__2740) = llvm_cbe_tmp__2745;
  goto llvm_cbe_tmp__2751;

llvm_cbe_tmp__2750:
  llvm_cbe_tmp__2746 = *(&llvm_cbe_tmp__2742);
  llvm_cbe_tmp__2747 = *((&llvm_cbe_tmp__2743->field0));
  *(&llvm_cbe_tmp__2740) = ((&llvm_cbe_tmp__2747[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2746) * ((unsigned int )128u)))))))]));
  goto llvm_cbe_tmp__2751;

llvm_cbe_tmp__2751:
  llvm_cbe_tmp__2748 = *(&llvm_cbe_tmp__2740);
  return llvm_cbe_tmp__2748;
}


void _ZN3rbm9train_rbmEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2752;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2753;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2754;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2755;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2756;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2757;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2758;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2759;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2760;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2761;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2762;    /* Address-exposed local */
  unsigned int llvm_cbe_nv;    /* Address-exposed local */
  unsigned int llvm_cbe_nh;    /* Address-exposed local */
  unsigned int llvm_cbe_nu;    /* Address-exposed local */
  unsigned int llvm_cbe_nlp;    /* Address-exposed local */
  unsigned int llvm_cbe_user;    /* Address-exposed local */
  unsigned int llvm_cbe_current_loop;    /* Address-exposed local */
  unsigned int llvm_cbe_v;    /* Address-exposed local */
  unsigned int llvm_cbe_h;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp3;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp4;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp5;    /* Address-exposed local */
  unsigned char llvm_cbe_pingpong;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned char llvm_cbe_bool1;    /* Address-exposed local */
  unsigned char llvm_cbe_bool2;    /* Address-exposed local */
  float llvm_cbe_tmp;    /* Address-exposed local */
  unsigned int llvm_cbe_current_h;    /* Address-exposed local */
  unsigned int llvm_cbe_current_v;    /* Address-exposed local */
  unsigned int llvm_cbe_vlp;    /* Address-exposed local */
  unsigned int llvm_cbe_hlp;    /* Address-exposed local */
  unsigned int llvm_cbe_vrest_;    /* Address-exposed local */
  unsigned int llvm_cbe_hrest_;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2763;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2764;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2765;    /* Address-exposed local */
  float llvm_cbe_de;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2766;
  bool llvm_cbe_tmp__2767;
  bool llvm_cbe_tmp__2768;
  unsigned long long llvm_cbe_tmp__2769;
  unsigned long long llvm_cbe_tmp__2770;
  unsigned long long llvm_cbe_tmp__2771;
  unsigned long long llvm_cbe_tmp__2772;
  unsigned long long llvm_cbe_tmp__2773;
  unsigned long long llvm_cbe_tmp__2774;
  unsigned short llvm_cbe_tmp__2775;
  unsigned short llvm_cbe_tmp__2776;
  unsigned short llvm_cbe_tmp__2777;
  unsigned short llvm_cbe_tmp__2778;
  unsigned int llvm_cbe_tmp__2779;
  unsigned int llvm_cbe_tmp__2780;

  *(&llvm_cbe_tmp__2752) = llvm_cbe_this;
  llvm_cbe_tmp__2766 = *(&llvm_cbe_tmp__2752);
  *(&llvm_cbe_tmp__2753) = ((unsigned char )1);
  llvm_cbe_tmp__2767 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2766->field36)), (&llvm_cbe_tmp__2753)))&1);
  *(&llvm_cbe_tmp__2754) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2766->field39)), (&llvm_cbe_tmp__2754));
  *(&llvm_cbe_tmp__2755) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2766->field40)), (&llvm_cbe_tmp__2755));
  *(&llvm_cbe_tmp__2756) = 625u;
  _ZN15sc_signal_int325writeERKi(((&llvm_cbe_tmp__2766->field41)), (&llvm_cbe_tmp__2756));
  goto llvm_cbe_tmp__2781;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2781:
  _Z4waitv();
  llvm_cbe_tmp__2768 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2766->field36))))&1);
  if ((((llvm_cbe_tmp__2768 ^ 1)&1))) {
    goto llvm_cbe_tmp__2781;
  } else {
    goto llvm_cbe_tmp__2782;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2782:
  llvm_cbe_tmp__2769 = *((&GM.field9));
  *(&llvm_cbe_tmp__2757) = (((unsigned short )llvm_cbe_tmp__2769));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2766->field30)), (&llvm_cbe_tmp__2757));
  llvm_cbe_tmp__2770 = *((&GM.field14));
  *(&llvm_cbe_tmp__2758) = (((unsigned short )llvm_cbe_tmp__2770));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2766->field31)), (&llvm_cbe_tmp__2758));
  llvm_cbe_tmp__2771 = *((&GM.field13));
  *(&llvm_cbe_tmp__2759) = (((unsigned short )llvm_cbe_tmp__2771));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2766->field32)), (&llvm_cbe_tmp__2759));
  llvm_cbe_tmp__2772 = *((&GM.field10));
  *(&llvm_cbe_tmp__2760) = (((unsigned short )llvm_cbe_tmp__2772));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2766->field33)), (&llvm_cbe_tmp__2760));
  llvm_cbe_tmp__2773 = *((&GM.field12));
  *(&llvm_cbe_tmp__2761) = (((unsigned short )llvm_cbe_tmp__2773));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2766->field34)), (&llvm_cbe_tmp__2761));
  llvm_cbe_tmp__2774 = *((&GM.field11));
  *(&llvm_cbe_tmp__2762) = (((unsigned short )llvm_cbe_tmp__2774));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2766->field35)), (&llvm_cbe_tmp__2762));
  llvm_cbe_tmp__2775 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2766->field31)));
  *(&llvm_cbe_nv) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2775));
  llvm_cbe_tmp__2776 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2766->field30)));
  *(&llvm_cbe_nh) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2776));
  llvm_cbe_tmp__2777 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2766->field32)));
  *(&llvm_cbe_nu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2777));
  llvm_cbe_tmp__2778 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2766->field33)));
  *(&llvm_cbe_nlp) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2778));
  *(&llvm_cbe_current_loop) = 0u;
  *(&llvm_cbe_pingpong) = ((unsigned char )0);
  *(&upc) = 2u;
  llvm_cbe_tmp__2779 = *(&llvm_cbe_nh);
  llvm_cbe_tmp__2780 = *(&llvm_cbe_nv);
  _ZN3rbm26activateVisibleUnits_trainEtt(llvm_cbe_tmp__2766, (((unsigned short )llvm_cbe_tmp__2779)), (((unsigned short )llvm_cbe_tmp__2780)));
  return;
}


void _ZN15sc_signal_int325writeERKi(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2783;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__2784;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2785;
  unsigned int *llvm_cbe_tmp__2786;
  unsigned int llvm_cbe_tmp__2787;

  *(&llvm_cbe_tmp__2783) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2784) = llvm_cbe_d;
  llvm_cbe_tmp__2785 = *(&llvm_cbe_tmp__2783);
  llvm_cbe_tmp__2786 = *(&llvm_cbe_tmp__2784);
  llvm_cbe_tmp__2787 = *llvm_cbe_tmp__2786;
  *((&llvm_cbe_tmp__2785->field0)) = llvm_cbe_tmp__2787;
  return;
}


float *_ZN11SysCArray2DIfLj501ELj101EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__2788;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2789;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__2790;
  unsigned int llvm_cbe_tmp__2791;
  float *llvm_cbe_tmp__2792;

  *(&llvm_cbe_tmp__2788) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2789) = llvm_cbe_Xidx;
  llvm_cbe_tmp__2790 = *(&llvm_cbe_tmp__2788);
  llvm_cbe_tmp__2791 = *(&llvm_cbe_tmp__2789);
  llvm_cbe_tmp__2792 = *((&llvm_cbe_tmp__2790->field0));
  return ((&llvm_cbe_tmp__2792[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2791) * ((unsigned int )101u)))))))]));
}


void _ZN3rbm25activateHiddenUnits_trainEbtt(struct l_struct_OC_rbm *llvm_cbe_this, bool llvm_cbe_pingpong, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2793;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2794;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2795;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2796;    /* Address-exposed local */
  unsigned short llvm_cbe_h;    /* Address-exposed local */
  unsigned short llvm_cbe_v;    /* Address-exposed local */
  float llvm_cbe_sum;    /* Address-exposed local */
  float llvm_cbe_tmp;    /* Address-exposed local */
  float llvm_cbe_prob;    /* Address-exposed local */
  float llvm_cbe_RAND;    /* Address-exposed local */
  unsigned char llvm_cbe_current_data;    /* Address-exposed local */
  float llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_comp;    /* Address-exposed local */
  unsigned char llvm_cbe_th;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2797;
  unsigned short llvm_cbe_tmp__2798;
  unsigned short llvm_cbe_tmp__2799;
  unsigned short llvm_cbe_tmp__2800;
  unsigned short llvm_cbe_tmp__2801;
  unsigned short llvm_cbe_tmp__2802;
  unsigned short llvm_cbe_tmp__2803;
  unsigned short llvm_cbe_tmp__2804;
  unsigned char llvm_cbe_tmp__2805;
  unsigned char *llvm_cbe_tmp__2806;
  unsigned char llvm_cbe_tmp__2807;
  unsigned char llvm_cbe_tmp__2808;
  unsigned short llvm_cbe_tmp__2809;
  unsigned short llvm_cbe_tmp__2810;
  float *llvm_cbe_tmp__2811;
  float llvm_cbe_tmp__2812;
  float llvm_cbe_tmp__2813;
  float llvm_cbe_tmp__2814;
  unsigned short llvm_cbe_tmp__2815;
  float llvm_cbe_tmp__2816;
  unsigned long long llvm_cbe_tmp__2817;
  unsigned short llvm_cbe_tmp__2818;
  float llvm_cbe_tmp__2819;
  float llvm_cbe_tmp__2820;
  float llvm_cbe_tmp__2821;
  float llvm_cbe_tmp__2822;
  unsigned char llvm_cbe_tmp__2823;
  unsigned char llvm_cbe_tmp__2824;
  unsigned short llvm_cbe_tmp__2825;
  unsigned char *llvm_cbe_tmp__2826;
  unsigned short llvm_cbe_tmp__2827;
  unsigned short llvm_cbe_tmp__2828;
  unsigned char *llvm_cbe_tmp__2829;

  *(&llvm_cbe_tmp__2793) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2794) = (((unsigned char )(bool )llvm_cbe_pingpong));
  *(&llvm_cbe_tmp__2795) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__2796) = llvm_cbe_nv;
  llvm_cbe_tmp__2797 = *(&llvm_cbe_tmp__2793);
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__2830;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2830:
  llvm_cbe_tmp__2798 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2798))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__2831;
  } else {
    goto llvm_cbe_tmp__2832;
  }

llvm_cbe_tmp__2833:
  llvm_cbe_tmp__2824 = *(&llvm_cbe_th);
  llvm_cbe_tmp__2825 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2826 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__2797->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__2825)));
  *llvm_cbe_tmp__2826 = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2824&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__2827 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2827) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2830;

llvm_cbe_tmp__2834:
  *(&llvm_cbe_th) = ((unsigned char )1);
  goto llvm_cbe_tmp__2833;

llvm_cbe_tmp__2835:
  llvm_cbe_tmp__2816 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__2817 = _Z8_c_16_15f(llvm_cbe_tmp__2816);
  llvm_cbe_tmp__2818 = _Z7sigmoidl(llvm_cbe_tmp__2817);
  llvm_cbe_tmp__2819 = _Z8_b_16_15l((((unsigned long long )(unsigned short )llvm_cbe_tmp__2818)));
  *(&llvm_cbe_prob) = llvm_cbe_tmp__2819;
  llvm_cbe_tmp__2820 = _ZN3rbm8rand_genEv(llvm_cbe_tmp__2797);
  *(&llvm_cbe_RAND) = llvm_cbe_tmp__2820;
  llvm_cbe_tmp__2821 = *(&llvm_cbe_RAND);
  llvm_cbe_tmp__2822 = *(&llvm_cbe_prob);
  *(&llvm_cbe_comp) = (((unsigned char )(bool )(llvm_fcmp_olt(llvm_cbe_tmp__2821, llvm_cbe_tmp__2822))));
  llvm_cbe_tmp__2823 = *(&llvm_cbe_comp);
  if ((((((bool )llvm_cbe_tmp__2823&1u))&1))) {
    goto llvm_cbe_tmp__2834;
  } else {
    goto llvm_cbe_tmp__2836;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2837:
  llvm_cbe_tmp__2801 = *(&llvm_cbe_v);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2801))) < ((signed int )501u))) {
    goto llvm_cbe_tmp__2838;
  } else {
    goto llvm_cbe_tmp__2835;
  }

llvm_cbe_tmp__2839:
  llvm_cbe_tmp__2815 = *(&llvm_cbe_v);
  *(&llvm_cbe_v) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2815) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2837;

llvm_cbe_tmp__2840:
  llvm_cbe_tmp__2809 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2810 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2811 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__2797->field23)), (((unsigned int )(unsigned short )llvm_cbe_tmp__2810)));
  llvm_cbe_tmp__2812 = *((&llvm_cbe_tmp__2811[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2809)))]));
  *(&llvm_cbe_tmp) = llvm_cbe_tmp__2812;
  llvm_cbe_tmp__2813 = *(&llvm_cbe_tmp);
  llvm_cbe_tmp__2814 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__2814 + llvm_cbe_tmp__2813)));
  _Z4waitv();
  goto llvm_cbe_tmp__2839;

llvm_cbe_tmp__2841:
  *(&per_v_pc) = 0u;
  *(&train_upc) = 0u;
  llvm_cbe_tmp__2804 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2805 = *(&llvm_cbe_tmp__2794);
  llvm_cbe_tmp__2806 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2797->field20)), ((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2805&1u))&1)))) & 0u));
  llvm_cbe_tmp__2807 = *((&llvm_cbe_tmp__2806[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2804)))]));
  *(&llvm_cbe_current_data) = llvm_cbe_tmp__2807;
  _Z4waitv();
  llvm_cbe_tmp__2808 = *(&llvm_cbe_current_data);
  if (((((unsigned int )(unsigned char )llvm_cbe_tmp__2808)) == 1u)) {
    goto llvm_cbe_tmp__2840;
  } else {
    goto llvm_cbe_tmp__2839;
  }

llvm_cbe_tmp__2838:
  llvm_cbe_tmp__2802 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2803 = *(&llvm_cbe_tmp__2796);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2802)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2803))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__2835;
  } else {
    goto llvm_cbe_tmp__2841;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2842:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_v) = ((unsigned short )0);
  goto llvm_cbe_tmp__2837;

llvm_cbe_tmp__2831:
  llvm_cbe_tmp__2799 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2800 = *(&llvm_cbe_tmp__2795);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2799)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__2800)))) {
    goto llvm_cbe_tmp__2832;
  } else {
    goto llvm_cbe_tmp__2842;
  }

llvm_cbe_tmp__2836:
  *(&llvm_cbe_th) = ((unsigned char )0);
  goto llvm_cbe_tmp__2833;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2832:
  llvm_cbe_tmp__2828 = *(&llvm_cbe_tmp__2795);
  llvm_cbe_tmp__2829 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__2797->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__2828)));
  *llvm_cbe_tmp__2829 = ((unsigned char )1);
  _Z4waitv();
  *(&per_v_pc) = 0u;
  *(&train_upc) = 1u;
  return;
}


unsigned char *_ZN11SysCArray1DIbLj128EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2843;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2844;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2845;
  unsigned int llvm_cbe_tmp__2846;
  unsigned char *llvm_cbe_tmp__2847;

  *(&llvm_cbe_tmp__2843) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2844) = llvm_cbe_idx;
  llvm_cbe_tmp__2845 = *(&llvm_cbe_tmp__2843);
  llvm_cbe_tmp__2846 = *(&llvm_cbe_tmp__2844);
  llvm_cbe_tmp__2847 = *((&llvm_cbe_tmp__2845->field0));
  return ((&llvm_cbe_tmp__2847[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__2846)))]));
}


unsigned char *_ZN11SysCArray2DIbLj501ELj101EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2848;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2849;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2850;
  unsigned int llvm_cbe_tmp__2851;
  unsigned char *llvm_cbe_tmp__2852;

  *(&llvm_cbe_tmp__2848) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2849) = llvm_cbe_Xidx;
  llvm_cbe_tmp__2850 = *(&llvm_cbe_tmp__2848);
  llvm_cbe_tmp__2851 = *(&llvm_cbe_tmp__2849);
  llvm_cbe_tmp__2852 = *((&llvm_cbe_tmp__2850->field0));
  return ((&llvm_cbe_tmp__2852[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2851) * ((unsigned int )101u)))))))]));
}


void _ZN3rbm26activateVisibleUnits_trainEtt(struct l_struct_OC_rbm *llvm_cbe_this, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2853;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2854;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2855;    /* Address-exposed local */
  unsigned short llvm_cbe_v;    /* Address-exposed local */
  unsigned short llvm_cbe_h;    /* Address-exposed local */
  float llvm_cbe_sum;    /* Address-exposed local */
  float llvm_cbe_max;    /* Address-exposed local */
  float llvm_cbe_probs;    /* Address-exposed local */
  float llvm_cbe_RAND;    /* Address-exposed local */
  struct l_unnamed22 llvm_cbe_pow2;    /* Address-exposed local */
  float llvm_cbe_sumOfpow2;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp;    /* Address-exposed local */
  float llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned short llvm_cbe_j;    /* Address-exposed local */
  float llvm_cbe_ve_current;    /* Address-exposed local */
  float llvm_cbe_dp;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2856;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2857;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2858;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2859;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2860;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2861;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2862;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2863;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2864;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2865;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2866;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2867;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2868;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2869;    /* Address-exposed local */
  float llvm_cbe_dp1;    /* Address-exposed local */
  unsigned char llvm_cbe_tmpb;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2870;
  bool llvm_cbe_tmp__2871;
  bool llvm_cbe_tmp__2872;
  bool llvm_cbe_tmp__2873;
  bool llvm_cbe_tmp__2874;
  unsigned char llvm_cbe_tmp__2875;
  unsigned int llvm_cbe_tmp__2876;
  unsigned int llvm_cbe_tmp__2877;
  unsigned int llvm_cbe_tmp__2878;
  unsigned int llvm_cbe_tmp__2879;
  unsigned int llvm_cbe_tmp__2880;
  unsigned int llvm_cbe_tmp__2881;
  unsigned char llvm_cbe_tmp__2882;
  unsigned long long llvm_cbe_tmp__2883;
  unsigned long long llvm_cbe_tmp__2884;
  unsigned long long llvm_cbe_tmp__2885;
  unsigned long long llvm_cbe_tmp__2886;
  unsigned long long llvm_cbe_tmp__2887;
  unsigned char llvm_cbe_tmp__2888;
  unsigned int llvm_cbe_tmp__2889;
  unsigned char llvm_cbe_tmp__2890;
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
  unsigned char *llvm_cbe_tmp__2902;
  unsigned char *llvm_cbe_tmp__2903;
  unsigned char *llvm_cbe_tmp__2904;
  unsigned char *llvm_cbe_tmp__2905;
  float *llvm_cbe_tmp__2906;
  unsigned char *llvm_cbe_tmp__2907;
  unsigned char *llvm_cbe_tmp__2908;
  unsigned char *llvm_cbe_tmp__2909;
  unsigned char *llvm_cbe_tmp__2910;
  unsigned char *llvm_cbe_tmp__2911;
  unsigned short *llvm_cbe_tmp__2912;
  unsigned short llvm_cbe_tmp__2913;
  float *llvm_cbe_tmp__2914;
  unsigned short *llvm_cbe_tmp__2915;
  unsigned short llvm_cbe_tmp__2916;
  float *llvm_cbe_tmp__2917;
  unsigned short *llvm_cbe_tmp__2918;
  unsigned short llvm_cbe_tmp__2919;
  float *llvm_cbe_tmp__2920;
  unsigned short *llvm_cbe_tmp__2921;
  unsigned short llvm_cbe_tmp__2922;
  float *llvm_cbe_tmp__2923;
  unsigned short *llvm_cbe_tmp__2924;
  unsigned short llvm_cbe_tmp__2925;
  float *llvm_cbe_tmp__2926;
  unsigned int *llvm_cbe_tmp__2927;
  unsigned char *llvm_cbe_tmp__2928;
  unsigned char *llvm_cbe_tmp__2929;
  unsigned short llvm_cbe_tmp__2930;
  unsigned short llvm_cbe_tmp__2931;
  float llvm_cbe_tmp__2932;
  float llvm_cbe_tmp__2933;
  float llvm_cbe_tmp__2934;
  unsigned short llvm_cbe_tmp__2935;
  float llvm_cbe_tmp__2936;
  float llvm_cbe_tmp__2937;
  unsigned short llvm_cbe_tmp__2938;
  unsigned short llvm_cbe_tmp__2939;
  unsigned short llvm_cbe_tmp__2940;
  unsigned short llvm_cbe_tmp__2941;
  unsigned short llvm_cbe_tmp__2942;
  unsigned short llvm_cbe_tmp__2943;
  unsigned char llvm_cbe_tmp__2944;
  unsigned int llvm_cbe_tmp__2945;
  unsigned int llvm_cbe_tmp__2946;
  unsigned int llvm_cbe_tmp__2947;
  unsigned int llvm_cbe_tmp__2948;
  unsigned int llvm_cbe_tmp__2949;
  unsigned int llvm_cbe_tmp__2950;
  unsigned char llvm_cbe_tmp__2951;
  unsigned char llvm_cbe_tmp__2952;
  unsigned int llvm_cbe_tmp__2953;
  unsigned char llvm_cbe_tmp__2954;
  bool llvm_cbe_tmp__2955;
  unsigned long long llvm_cbe_tmp__2956;
  bool llvm_cbe_tmp__2957;
  unsigned long long llvm_cbe_tmp__2958;
  unsigned short llvm_cbe_tmp__2959;
  unsigned long long llvm_cbe_tmp__2960;
  unsigned short llvm_cbe_tmp__2961;
  unsigned long long llvm_cbe_tmp__2962;
  unsigned short llvm_cbe_tmp__2963;
  unsigned long long llvm_cbe_tmp__2964;
  unsigned short llvm_cbe_tmp__2965;
  unsigned long long llvm_cbe_tmp__2966;
  unsigned short llvm_cbe_tmp__2967;
  unsigned long long llvm_cbe_tmp__2968;
  unsigned short llvm_cbe_tmp__2969;
  unsigned long long llvm_cbe_tmp__2970;
  unsigned int llvm_cbe_tmp__2971;
  unsigned long long llvm_cbe_tmp__2972;
  unsigned int llvm_cbe_tmp__2973;
  unsigned long long llvm_cbe_tmp__2974;
  bool llvm_cbe_tmp__2975;
  unsigned long long llvm_cbe_tmp__2976;
  bool llvm_cbe_tmp__2977;
  unsigned long long llvm_cbe_tmp__2978;
  unsigned int llvm_cbe_tmp__2979;
  unsigned long long llvm_cbe_tmp__2980;
  unsigned int llvm_cbe_tmp__2981;
  unsigned long long llvm_cbe_tmp__2982;
  unsigned int llvm_cbe_tmp__2983;
  unsigned long long llvm_cbe_tmp__2984;
  unsigned int llvm_cbe_tmp__2985;
  unsigned long long llvm_cbe_tmp__2986;
  bool llvm_cbe_tmp__2987;
  unsigned long long llvm_cbe_tmp__2988;
  float llvm_cbe_tmp__2989;
  unsigned long long llvm_cbe_tmp__2990;
  float llvm_cbe_tmp__2991;
  unsigned long long llvm_cbe_tmp__2992;
  unsigned short llvm_cbe_tmp__2993;
  unsigned long long llvm_cbe_tmp__2994;
  unsigned short llvm_cbe_tmp__2995;
  unsigned long long llvm_cbe_tmp__2996;
  bool llvm_cbe_tmp__2997;
  bool llvm_cbe_tmp__2997__PHI_TEMPORARY;
  unsigned int llvm_cbe_tmp__2998;
  unsigned long long llvm_cbe_tmp__2999;
  unsigned short llvm_cbe_tmp__3000;
  unsigned long long llvm_cbe_tmp__3001;
  unsigned short llvm_cbe_tmp__3002;
  unsigned long long llvm_cbe_tmp__3003;
  unsigned char *llvm_cbe_tmp__3004;
  unsigned char *llvm_cbe_tmp__3005;
  bool llvm_cbe_tmp__3006;
  unsigned char *llvm_cbe_tmp__3007;
  unsigned char *llvm_cbe_tmp__3008;
  bool llvm_cbe_tmp__3009;
  unsigned char *llvm_cbe_tmp__3010;
  unsigned char *llvm_cbe_tmp__3011;
  bool llvm_cbe_tmp__3012;
  unsigned char *llvm_cbe_tmp__3013;
  unsigned char *llvm_cbe_tmp__3014;
  bool llvm_cbe_tmp__3015;
  float llvm_cbe_tmp__3016;
  unsigned short llvm_cbe_tmp__3017;
  float *llvm_cbe_tmp__3018;
  float llvm_cbe_tmp__3019;
  float llvm_cbe_tmp__3020;
  float llvm_cbe_tmp__3021;
  unsigned short llvm_cbe_tmp__3022;
  float llvm_cbe_tmp__3023;
  unsigned short llvm_cbe_tmp__3024;
  unsigned short llvm_cbe_tmp__3025;
  float *llvm_cbe_tmp__3026;
  float llvm_cbe_tmp__3027;
  float llvm_cbe_tmp__3028;
  float llvm_cbe_tmp__3029;
  float llvm_cbe_tmp__3030;
  unsigned short llvm_cbe_tmp__3031;
  float *llvm_cbe_tmp__3032;
  unsigned short llvm_cbe_tmp__3033;
  unsigned short llvm_cbe_tmp__3034;
  unsigned short llvm_cbe_tmp__3035;
  float *llvm_cbe_tmp__3036;
  float llvm_cbe_tmp__3037;
  float llvm_cbe_tmp__3038;
  unsigned long long llvm_cbe_tmp__3039;
  unsigned short llvm_cbe_tmp__3040;
  float llvm_cbe_tmp__3041;
  float llvm_cbe_tmp__3042;
  float llvm_cbe_tmp__3043;
  unsigned short llvm_cbe_tmp__3044;
  unsigned short llvm_cbe_tmp__3045;
  unsigned short llvm_cbe_tmp__3046;
  unsigned char llvm_cbe_tmp__3047;
  unsigned int llvm_cbe_tmp__3048;
  unsigned int llvm_cbe_tmp__3049;
  unsigned int llvm_cbe_tmp__3050;
  unsigned int llvm_cbe_tmp__3051;
  unsigned int llvm_cbe_tmp__3052;
  unsigned int llvm_cbe_tmp__3053;
  unsigned char llvm_cbe_tmp__3054;
  unsigned char llvm_cbe_tmp__3055;
  unsigned int llvm_cbe_tmp__3056;
  unsigned char llvm_cbe_tmp__3057;
  bool llvm_cbe_tmp__3058;
  unsigned long long llvm_cbe_tmp__3059;
  bool llvm_cbe_tmp__3060;
  unsigned long long llvm_cbe_tmp__3061;
  unsigned short llvm_cbe_tmp__3062;
  unsigned long long llvm_cbe_tmp__3063;
  unsigned short llvm_cbe_tmp__3064;
  unsigned long long llvm_cbe_tmp__3065;
  unsigned short llvm_cbe_tmp__3066;
  unsigned long long llvm_cbe_tmp__3067;
  unsigned short llvm_cbe_tmp__3068;
  unsigned long long llvm_cbe_tmp__3069;
  unsigned short llvm_cbe_tmp__3070;
  unsigned long long llvm_cbe_tmp__3071;
  unsigned short llvm_cbe_tmp__3072;
  unsigned long long llvm_cbe_tmp__3073;
  unsigned int llvm_cbe_tmp__3074;
  unsigned long long llvm_cbe_tmp__3075;
  unsigned int llvm_cbe_tmp__3076;
  unsigned long long llvm_cbe_tmp__3077;
  bool llvm_cbe_tmp__3078;
  unsigned long long llvm_cbe_tmp__3079;
  bool llvm_cbe_tmp__3080;
  unsigned long long llvm_cbe_tmp__3081;
  unsigned int llvm_cbe_tmp__3082;
  unsigned long long llvm_cbe_tmp__3083;
  unsigned int llvm_cbe_tmp__3084;
  unsigned long long llvm_cbe_tmp__3085;
  unsigned int llvm_cbe_tmp__3086;
  unsigned long long llvm_cbe_tmp__3087;
  unsigned int llvm_cbe_tmp__3088;
  unsigned long long llvm_cbe_tmp__3089;
  bool llvm_cbe_tmp__3090;
  unsigned long long llvm_cbe_tmp__3091;
  float llvm_cbe_tmp__3092;
  unsigned long long llvm_cbe_tmp__3093;
  float llvm_cbe_tmp__3094;
  unsigned long long llvm_cbe_tmp__3095;
  float llvm_cbe_tmp__3096;
  unsigned long long llvm_cbe_tmp__3097;
  unsigned short llvm_cbe_tmp__3098;
  unsigned long long llvm_cbe_tmp__3099;
  unsigned int llvm_cbe_tmp__3100;
  unsigned long long llvm_cbe_tmp__3101;
  unsigned int llvm_cbe_tmp__3102;
  unsigned long long llvm_cbe_tmp__3103;
  unsigned short llvm_cbe_tmp__3104;
  unsigned long long llvm_cbe_tmp__3105;
  unsigned short llvm_cbe_tmp__3106;
  unsigned long long llvm_cbe_tmp__3107;
  unsigned char *llvm_cbe_tmp__3108;
  unsigned char *llvm_cbe_tmp__3109;
  bool llvm_cbe_tmp__3110;
  unsigned char *llvm_cbe_tmp__3111;
  unsigned char *llvm_cbe_tmp__3112;
  bool llvm_cbe_tmp__3113;
  unsigned char *llvm_cbe_tmp__3114;
  unsigned char *llvm_cbe_tmp__3115;
  bool llvm_cbe_tmp__3116;
  unsigned char *llvm_cbe_tmp__3117;
  unsigned char *llvm_cbe_tmp__3118;
  bool llvm_cbe_tmp__3119;
  unsigned short llvm_cbe_tmp__3120;
  unsigned char llvm_cbe_tmp__3121;
  unsigned short llvm_cbe_tmp__3122;
  unsigned short llvm_cbe_tmp__3123;
  unsigned char *llvm_cbe_tmp__3124;
  unsigned short llvm_cbe_tmp__3125;
  unsigned short llvm_cbe_tmp__3126;
  unsigned short llvm_cbe_tmp__3127;
  unsigned short llvm_cbe_tmp__3128;
  unsigned char *llvm_cbe_tmp__3129;
  unsigned char llvm_cbe_tmp__3130;
  unsigned int llvm_cbe_tmp__3131;
  unsigned int llvm_cbe_tmp__3132;
  unsigned int llvm_cbe_tmp__3133;
  unsigned int llvm_cbe_tmp__3134;
  unsigned int llvm_cbe_tmp__3135;
  unsigned int llvm_cbe_tmp__3136;
  unsigned char llvm_cbe_tmp__3137;
  unsigned char llvm_cbe_tmp__3138;
  unsigned int llvm_cbe_tmp__3139;
  unsigned char llvm_cbe_tmp__3140;
  bool llvm_cbe_tmp__3141;
  unsigned long long llvm_cbe_tmp__3142;
  bool llvm_cbe_tmp__3143;
  unsigned long long llvm_cbe_tmp__3144;
  unsigned short llvm_cbe_tmp__3145;
  unsigned long long llvm_cbe_tmp__3146;
  unsigned short llvm_cbe_tmp__3147;
  unsigned long long llvm_cbe_tmp__3148;
  unsigned short llvm_cbe_tmp__3149;
  unsigned long long llvm_cbe_tmp__3150;
  unsigned short llvm_cbe_tmp__3151;
  unsigned long long llvm_cbe_tmp__3152;
  unsigned short llvm_cbe_tmp__3153;
  unsigned long long llvm_cbe_tmp__3154;
  unsigned short llvm_cbe_tmp__3155;
  unsigned long long llvm_cbe_tmp__3156;
  unsigned int llvm_cbe_tmp__3157;
  unsigned long long llvm_cbe_tmp__3158;
  unsigned int llvm_cbe_tmp__3159;
  unsigned long long llvm_cbe_tmp__3160;
  bool llvm_cbe_tmp__3161;
  unsigned long long llvm_cbe_tmp__3162;
  bool llvm_cbe_tmp__3163;
  unsigned long long llvm_cbe_tmp__3164;
  unsigned int llvm_cbe_tmp__3165;
  unsigned long long llvm_cbe_tmp__3166;
  unsigned int llvm_cbe_tmp__3167;
  unsigned long long llvm_cbe_tmp__3168;
  unsigned int llvm_cbe_tmp__3169;
  unsigned long long llvm_cbe_tmp__3170;
  unsigned int llvm_cbe_tmp__3171;
  unsigned long long llvm_cbe_tmp__3172;
  bool llvm_cbe_tmp__3173;
  unsigned long long llvm_cbe_tmp__3174;
  float llvm_cbe_tmp__3175;
  unsigned long long llvm_cbe_tmp__3176;
  float llvm_cbe_tmp__3177;
  unsigned long long llvm_cbe_tmp__3178;
  float llvm_cbe_tmp__3179;
  unsigned long long llvm_cbe_tmp__3180;
  unsigned short llvm_cbe_tmp__3181;
  unsigned long long llvm_cbe_tmp__3182;
  unsigned short llvm_cbe_tmp__3183;
  unsigned long long llvm_cbe_tmp__3184;
  bool llvm_cbe_tmp__3185;
  bool llvm_cbe_tmp__3185__PHI_TEMPORARY;
  unsigned int llvm_cbe_tmp__3186;
  unsigned long long llvm_cbe_tmp__3187;
  unsigned int llvm_cbe_tmp__3188;
  unsigned long long llvm_cbe_tmp__3189;
  unsigned short llvm_cbe_tmp__3190;
  unsigned long long llvm_cbe_tmp__3191;
  unsigned short llvm_cbe_tmp__3192;
  unsigned long long llvm_cbe_tmp__3193;
  unsigned char *llvm_cbe_tmp__3194;
  unsigned char *llvm_cbe_tmp__3195;
  bool llvm_cbe_tmp__3196;
  unsigned char *llvm_cbe_tmp__3197;
  unsigned char *llvm_cbe_tmp__3198;
  bool llvm_cbe_tmp__3199;
  unsigned char *llvm_cbe_tmp__3200;
  unsigned char *llvm_cbe_tmp__3201;
  bool llvm_cbe_tmp__3202;
  unsigned char *llvm_cbe_tmp__3203;
  unsigned char *llvm_cbe_tmp__3204;
  bool llvm_cbe_tmp__3205;

  *(&llvm_cbe_tmp__2853) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2854) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__2855) = llvm_cbe_nv;
  llvm_cbe_tmp__2870 = *(&llvm_cbe_tmp__2853);
  *(&per_v_pc) = 3u;
  *(&train_upc) = 1u;
  *(&llvm_cbe_tmp__2856) = ((unsigned char )1);
  llvm_cbe_tmp__2871 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2870->field36)), (&llvm_cbe_tmp__2856)))&1);
  *(&llvm_cbe_tmp__2857) = ((unsigned char )1);
  llvm_cbe_tmp__2872 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2870->field37)), (&llvm_cbe_tmp__2857)))&1);
  *((&GM.field15)) = 3ull;
  *(&llvm_cbe_tmp__2858) = ((unsigned char )0);
  llvm_cbe_tmp__2873 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2870->field12)), (&llvm_cbe_tmp__2858)))&1);
  *((&GM.field29)) = 1ull;
  *(&rst_inp) = ((unsigned char )0);
  *((&GM.field31)) = 2ull;
  *(&llvm_cbe_tmp__2859) = ((unsigned char )0);
  llvm_cbe_tmp__2874 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2870->field38)), (&llvm_cbe_tmp__2859)))&1);
  *(&upc) = 2u;
  llvm_cbe_tmp__2875 = *(&conf_done_inp);
  *((&((&llvm_cbe_tmp__2870->field13))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2875&1u))&1))));
  llvm_cbe_tmp__2876 = *(&conf_num_hidden_inp);
  *((&((&llvm_cbe_tmp__2870->field14))->field0)) = llvm_cbe_tmp__2876;
  llvm_cbe_tmp__2877 = *(&conf_num_visible_inp);
  *((&((&llvm_cbe_tmp__2870->field15))->field0)) = llvm_cbe_tmp__2877;
  llvm_cbe_tmp__2878 = *(&conf_num_users_inp);
  *((&((&llvm_cbe_tmp__2870->field16))->field0)) = llvm_cbe_tmp__2878;
  llvm_cbe_tmp__2879 = *(&conf_num_loops_inp);
  *((&((&llvm_cbe_tmp__2870->field17))->field0)) = llvm_cbe_tmp__2879;
  llvm_cbe_tmp__2880 = *(&conf_num_testusers_inp);
  *((&((&llvm_cbe_tmp__2870->field18))->field0)) = llvm_cbe_tmp__2880;
  llvm_cbe_tmp__2881 = *(&conf_num_movies_inp);
  *((&((&llvm_cbe_tmp__2870->field19))->field0)) = llvm_cbe_tmp__2881;
  llvm_cbe_tmp__2882 = *(&rst_inp);
  *((&((&llvm_cbe_tmp__2870->field1))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2882&1u))&1))));
  llvm_cbe_tmp__2883 = *((&GM.field6));
  *(&llvm_cbe_tmp__2860) = (((unsigned char )(bool )(llvm_cbe_tmp__2883 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2870->field36)), (&llvm_cbe_tmp__2860));
  llvm_cbe_tmp__2884 = *((&GM.field2));
  *(&llvm_cbe_tmp__2861) = (((unsigned char )(bool )(llvm_cbe_tmp__2884 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2870->field12)), (&llvm_cbe_tmp__2861));
  llvm_cbe_tmp__2885 = *((&GM.field21));
  *(&llvm_cbe_tmp__2862) = (((unsigned int )llvm_cbe_tmp__2885));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2870->field2)), (&llvm_cbe_tmp__2862));
  llvm_cbe_tmp__2886 = *((&GM.field22));
  *(&llvm_cbe_tmp__2863) = (((unsigned int )llvm_cbe_tmp__2886));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2870->field3)), (&llvm_cbe_tmp__2863));
  llvm_cbe_tmp__2887 = *((&GM.field23));
  *(&llvm_cbe_tmp__2864) = (((unsigned char )(bool )(llvm_cbe_tmp__2887 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2870->field4)), (&llvm_cbe_tmp__2864));
  llvm_cbe_tmp__2888 = *(&rd_grant_inp);
  *((&((&llvm_cbe_tmp__2870->field5))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2888&1u))&1))));
  llvm_cbe_tmp__2889 = *(&data_in_inp);
  *((&((&llvm_cbe_tmp__2870->field6))->field0)) = llvm_cbe_tmp__2889;
  llvm_cbe_tmp__2890 = *(&wr_grant_inp);
  *((&((&llvm_cbe_tmp__2870->field10))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2890&1u))&1))));
  llvm_cbe_tmp__2891 = *((&GM.field37));
  *(&llvm_cbe_tmp__2865) = (((unsigned char )(bool )(llvm_cbe_tmp__2891 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2870->field9)), (&llvm_cbe_tmp__2865));
  llvm_cbe_tmp__2892 = *((&GM.field35));
  *(&llvm_cbe_tmp__2866) = (((unsigned int )llvm_cbe_tmp__2892));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2870->field7)), (&llvm_cbe_tmp__2866));
  llvm_cbe_tmp__2893 = *((&GM.field36));
  *(&llvm_cbe_tmp__2867) = (((unsigned int )llvm_cbe_tmp__2893));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2870->field8)), (&llvm_cbe_tmp__2867));
  llvm_cbe_tmp__2894 = *((&GM.field1));
  *(&llvm_cbe_tmp__2868) = (((unsigned int )llvm_cbe_tmp__2894));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2870->field11)), (&llvm_cbe_tmp__2868));
  llvm_cbe_tmp__2895 = *((&GM.field26));
  *(&llvm_cbe_tmp__2869) = (((unsigned char )(bool )(llvm_cbe_tmp__2895 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2870->field37)), (&llvm_cbe_tmp__2869));
  llvm_cbe_tmp__2896 = *((&GM.field28));
  *(&llvm_cbe_sum) = (((float )((((double )(signed long long )(llvm_cbe_tmp__2896 & 65535ull))) / 0x1p+1)));
  llvm_cbe_tmp__2897 = *((&GM.field27));
  *(&llvm_cbe_max) = (((float )((((double )(signed long long )(llvm_cbe_tmp__2897 & 65535ull))) / 0x1p+1)));
  llvm_cbe_tmp__2898 = *((&GM.field24));
  *(&llvm_cbe_sumOfpow2) = (((float )((((double )(unsigned long long )llvm_cbe_tmp__2898)) / 0x1p+0)));
  *((&GM.field7)) = 4ull;
  llvm_cbe_tmp__2899 = *((&GM.field7));
  *(&llvm_cbe_j) = (((unsigned short )llvm_cbe_tmp__2899));
  llvm_cbe_tmp__2900 = *((&GM.field30));
  *(&llvm_cbe_v) = (((unsigned short )llvm_cbe_tmp__2900));
  llvm_cbe_tmp__2901 = *((&GM.field25));
  *(&llvm_cbe_h) = (((unsigned short )llvm_cbe_tmp__2901));
  llvm_cbe_tmp__2902 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2870->field20)), 0u);
  llvm_cbe_tmp__2903 = *((&GM.field0.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2902, llvm_cbe_tmp__2903);
  llvm_cbe_tmp__2904 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2870->field28)), 0u);
  llvm_cbe_tmp__2905 = *((&GM.field19.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2904, llvm_cbe_tmp__2905);
  llvm_cbe_tmp__2906 = *((&((&llvm_cbe_tmp__2870->field23))->field0));
  llvm_cbe_tmp__2907 = *((&GM.field3.field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__2906)), llvm_cbe_tmp__2907);
  llvm_cbe_tmp__2908 = *((&((&llvm_cbe_tmp__2870->field22))->field0));
  llvm_cbe_tmp__2909 = *((&GM.field4.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2908, llvm_cbe_tmp__2909);
  llvm_cbe_tmp__2910 = *((&((&llvm_cbe_tmp__2870->field21))->field0));
  llvm_cbe_tmp__2911 = *((&GM.field33.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2910, llvm_cbe_tmp__2911);
  llvm_cbe_tmp__2912 = *((&GM.field32.field0));
  llvm_cbe_tmp__2913 = *((&(*llvm_cbe_tmp__2912)));
  llvm_cbe_tmp__2914 = *((&((&llvm_cbe_tmp__2870->field26))->field0));
  *((&(*llvm_cbe_tmp__2914))) = (((float )((((double )(signed int )((((unsigned int )(unsigned short )llvm_cbe_tmp__2913)) & 65535u))) / 0x1p+1)));
  llvm_cbe_tmp__2915 = *((&GM.field32.field0));
  llvm_cbe_tmp__2916 = *((&llvm_cbe_tmp__2915[((signed long long )1ull)]));
  llvm_cbe_tmp__2917 = *((&((&llvm_cbe_tmp__2870->field26))->field0));
  *((&llvm_cbe_tmp__2917[((signed long long )1ull)])) = (((float )((((double )(signed int )((((unsigned int )(unsigned short )llvm_cbe_tmp__2916)) & 65535u))) / 0x1p+1)));
  llvm_cbe_tmp__2918 = *((&GM.field32.field0));
  llvm_cbe_tmp__2919 = *((&llvm_cbe_tmp__2918[((signed long long )2ull)]));
  llvm_cbe_tmp__2920 = *((&((&llvm_cbe_tmp__2870->field26))->field0));
  *((&llvm_cbe_tmp__2920[((signed long long )2ull)])) = (((float )((((double )(signed int )((((unsigned int )(unsigned short )llvm_cbe_tmp__2919)) & 65535u))) / 0x1p+1)));
  llvm_cbe_tmp__2921 = *((&GM.field32.field0));
  llvm_cbe_tmp__2922 = *((&llvm_cbe_tmp__2921[((signed long long )3ull)]));
  llvm_cbe_tmp__2923 = *((&((&llvm_cbe_tmp__2870->field26))->field0));
  *((&llvm_cbe_tmp__2923[((signed long long )3ull)])) = (((float )((((double )(signed int )((((unsigned int )(unsigned short )llvm_cbe_tmp__2922)) & 65535u))) / 0x1p+1)));
  llvm_cbe_tmp__2924 = *((&GM.field32.field0));
  llvm_cbe_tmp__2925 = *((&llvm_cbe_tmp__2924[((signed long long )4ull)]));
  llvm_cbe_tmp__2926 = *((&((&llvm_cbe_tmp__2870->field26))->field0));
  *((&llvm_cbe_tmp__2926[((signed long long )4ull)])) = (((float )((((double )(signed int )((((unsigned int )(unsigned short )llvm_cbe_tmp__2925)) & 65535u))) / 0x1p+1)));
  llvm_cbe_tmp__2927 = *((&GM.field17.field0));
  __CPROVER_array_copy((((unsigned char *)((&llvm_cbe_pow2.array[((signed int )0u)])))), (((unsigned char *)llvm_cbe_tmp__2927)));
  llvm_cbe_tmp__2928 = *((&((&llvm_cbe_tmp__2870->field24))->field0));
  llvm_cbe_tmp__2929 = *((&GM.field16.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2928, llvm_cbe_tmp__2929);
  llvm_cbe_tmp__2930 = _Z4randv();
  *(&llvm_cbe_RAND) = (((float )((((double )(unsigned long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2930)))) / 0x1p+63)));
  llvm_cbe_tmp__2931 = *(&llvm_cbe_j);
  llvm_cbe_tmp__2932 = *((&llvm_cbe_pow2.array[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2931)))]));
  *(&llvm_cbe_dp1) = llvm_cbe_tmp__2932;
  _Z4waitv();
  llvm_cbe_tmp__2933 = *(&llvm_cbe_dp1);
  llvm_cbe_tmp__2934 = *(&llvm_cbe_sumOfpow2);
  llvm_cbe_tmp__2935 = _Z6dividell(((((signed long long )llvm_cbe_tmp__2933)) & 4294967295ull), (((signed long long )llvm_cbe_tmp__2934)));
  *(&llvm_cbe_probs) = (((float )(unsigned short )llvm_cbe_tmp__2935));
  *(&llvm_cbe_tmpb) = ((unsigned char )0);
  llvm_cbe_tmp__2936 = *(&llvm_cbe_RAND);
  llvm_cbe_tmp__2937 = *(&llvm_cbe_probs);
  if ((llvm_fcmp_olt(llvm_cbe_tmp__2936, llvm_cbe_tmp__2937))) {
    goto llvm_cbe_tmp__3206;
  } else {
    goto llvm_cbe_tmp__3207;
  }

llvm_cbe_tmp__3208:
  llvm_cbe_tmp__2944 = *(&conf_done_inp);
  llvm_cbe_tmp__2945 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__2946 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__2947 = *(&conf_num_users_inp);
  llvm_cbe_tmp__2948 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__2949 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__2950 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__2951 = *(&rst_inp);
  llvm_cbe_tmp__2952 = *(&rd_grant_inp);
  llvm_cbe_tmp__2953 = *(&data_in_inp);
  llvm_cbe_tmp__2954 = *(&wr_grant_inp);
  _ZN11model_train6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2944&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2945)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2946)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2947)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2948)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2949)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2950)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2951&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2952&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2953)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2954&1u))&1)))));
  llvm_cbe_tmp__2955 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field36))))&1);
  llvm_cbe_tmp__2956 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2955)) == llvm_cbe_tmp__2956), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__2957 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field12))))&1);
  llvm_cbe_tmp__2958 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2957)) == llvm_cbe_tmp__2958), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__2959 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field30)));
  llvm_cbe_tmp__2960 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2959)) == llvm_cbe_tmp__2960), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__2961 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field31)));
  llvm_cbe_tmp__2962 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2961)) == llvm_cbe_tmp__2962), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__2963 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field32)));
  llvm_cbe_tmp__2964 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2963)) == llvm_cbe_tmp__2964), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__2965 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field33)));
  llvm_cbe_tmp__2966 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2965)) == llvm_cbe_tmp__2966), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__2967 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field34)));
  llvm_cbe_tmp__2968 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2967)) == llvm_cbe_tmp__2968), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__2969 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field35)));
  llvm_cbe_tmp__2970 = *((&GM.field11));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2969)) == llvm_cbe_tmp__2970), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__2971 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field2)));
  llvm_cbe_tmp__2972 = *((&GM.field21));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2971)) == llvm_cbe_tmp__2972), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__2973 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field3)));
  llvm_cbe_tmp__2974 = *((&GM.field22));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2973)) == llvm_cbe_tmp__2974), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__2975 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field4))))&1);
  llvm_cbe_tmp__2976 = *((&GM.field23));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2975)) == llvm_cbe_tmp__2976), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__2977 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field9))))&1);
  llvm_cbe_tmp__2978 = *((&GM.field37));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2977)) == llvm_cbe_tmp__2978), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__2979 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field7)));
  llvm_cbe_tmp__2980 = *((&GM.field35));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2979)) == llvm_cbe_tmp__2980), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__2981 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field8)));
  llvm_cbe_tmp__2982 = *((&GM.field36));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2981)) == llvm_cbe_tmp__2982), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__2983 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field11)));
  llvm_cbe_tmp__2984 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2983)) == llvm_cbe_tmp__2984), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__2985 = *(&upc);
  llvm_cbe_tmp__2986 = *((&GM.field31));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2985)) == llvm_cbe_tmp__2986), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__2987 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field37))))&1);
  llvm_cbe_tmp__2988 = *((&GM.field26));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2987)) == llvm_cbe_tmp__2988), ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__2989 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__2990 = *((&GM.field28));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__2989)), ((((double )(signed long long )(llvm_cbe_tmp__2990 & 65535ull))) / 0x1p+1))), ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__2991 = *(&llvm_cbe_sumOfpow2);
  llvm_cbe_tmp__2992 = *((&GM.field24));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__2991)), ((((double )(unsigned long long )llvm_cbe_tmp__2992)) / 0x1p+0))), ((&_OC_str20.array[((signed int )0u)])));
  llvm_cbe_tmp__2993 = *(&llvm_cbe_j);
  llvm_cbe_tmp__2994 = *((&GM.field7));
  if (((((unsigned long long )(unsigned short )llvm_cbe_tmp__2993)) == llvm_cbe_tmp__2994)) {
    llvm_cbe_tmp__2997__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__3209;
  } else {
    goto llvm_cbe_tmp__3210;
  }

llvm_cbe_tmp__3210:
  llvm_cbe_tmp__2995 = *(&llvm_cbe_j);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2995)) == 5u)) {
    goto llvm_cbe_tmp__3211;
  } else {
    llvm_cbe_tmp__2997__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__3209;
  }

llvm_cbe_tmp__3211:
  llvm_cbe_tmp__2996 = *((&GM.field7));
  llvm_cbe_tmp__2997__PHI_TEMPORARY = (llvm_cbe_tmp__2996 == 0ull);   /* for PHI node */
  goto llvm_cbe_tmp__3209;

llvm_cbe_tmp__3209:
  llvm_cbe_tmp__2997 = ((llvm_cbe_tmp__2997__PHI_TEMPORARY)&1);
  __CPROVER_assert(llvm_cbe_tmp__2997, ((&_OC_str21.array[((signed int )0u)])));
  llvm_cbe_tmp__2998 = *(&train_upc);
  llvm_cbe_tmp__2999 = *((&GM.field29));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2998)) == llvm_cbe_tmp__2999), ((&_OC_str22.array[((signed int )0u)])));
  llvm_cbe_tmp__3000 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3001 = *((&GM.field30));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3000)) == llvm_cbe_tmp__3001), ((&_OC_str23.array[((signed int )0u)])));
  llvm_cbe_tmp__3002 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3003 = *((&GM.field25));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3002)) == llvm_cbe_tmp__3003), ((&_OC_str24.array[((signed int )0u)])));
  llvm_cbe_tmp__3004 = *((&GM.field0.field0));
  llvm_cbe_tmp__3005 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2870->field20)), 0u);
  llvm_cbe_tmp__3006 = ((__CPROVER_array_equal(llvm_cbe_tmp__3004, llvm_cbe_tmp__3005))&1);
  __CPROVER_assert(llvm_cbe_tmp__3006, ((&_OC_str25.array[((signed int )0u)])));
  llvm_cbe_tmp__3007 = *((&GM.field19.field0));
  llvm_cbe_tmp__3008 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2870->field28)), 0u);
  llvm_cbe_tmp__3009 = ((__CPROVER_array_equal(llvm_cbe_tmp__3007, llvm_cbe_tmp__3008))&1);
  __CPROVER_assert(llvm_cbe_tmp__3009, ((&_OC_str26.array[((signed int )0u)])));
  llvm_cbe_tmp__3010 = *((&GM.field4.field0));
  llvm_cbe_tmp__3011 = *((&((&llvm_cbe_tmp__2870->field22))->field0));
  llvm_cbe_tmp__3012 = ((__CPROVER_array_equal(llvm_cbe_tmp__3010, llvm_cbe_tmp__3011))&1);
  __CPROVER_assert(llvm_cbe_tmp__3012, ((&_OC_str27.array[((signed int )0u)])));
  llvm_cbe_tmp__3013 = *((&GM.field16.field0));
  llvm_cbe_tmp__3014 = *((&((&llvm_cbe_tmp__2870->field24))->field0));
  llvm_cbe_tmp__3015 = ((__CPROVER_array_equal(llvm_cbe_tmp__3013, llvm_cbe_tmp__3014))&1);
  __CPROVER_assert(llvm_cbe_tmp__3015, ((&_OC_str28.array[((signed int )0u)])));
  goto llvm_cbe_tmp__3212;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3213:
  llvm_cbe_tmp__3046 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3046))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3214;
  } else {
    goto llvm_cbe_tmp__3215;
  }

llvm_cbe_tmp__3216:
  *(&per_v_pc) = 3u;
  *(&train_upc) = 1u;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3213;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3217:
  llvm_cbe_tmp__3034 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3034))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3218;
  } else {
    goto llvm_cbe_tmp__3216;
  }

llvm_cbe_tmp__3218:
  *(&per_v_pc) = 2u;
  *(&train_upc) = 1u;
  llvm_cbe_tmp__3035 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3036 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__2870->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3035)));
  llvm_cbe_tmp__3037 = *llvm_cbe_tmp__3036;
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3037;
  _Z4waitv();
  llvm_cbe_tmp__3038 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3039 = _Z8_c_16_15f(llvm_cbe_tmp__3038);
  llvm_cbe_tmp__3040 = _Z10to_int_expl(llvm_cbe_tmp__3039);
  *(&llvm_cbe_dp) = (((float )(unsigned short )llvm_cbe_tmp__3040));
  llvm_cbe_tmp__3041 = *(&llvm_cbe_dp);
  llvm_cbe_tmp__3042 = *(&llvm_cbe_sumOfpow2);
  *(&llvm_cbe_sumOfpow2) = (((float )(llvm_cbe_tmp__3042 + llvm_cbe_tmp__3041)));
  llvm_cbe_tmp__3043 = *(&llvm_cbe_dp);
  llvm_cbe_tmp__3044 = *(&llvm_cbe_j);
  *((&llvm_cbe_pow2.array[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3044)))])) = llvm_cbe_tmp__3043;
  llvm_cbe_tmp__3045 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3045) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3217;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3219:
  *(&per_v_pc) = 2u;
  *(&train_upc) = 1u;
  *(&llvm_cbe_sumOfpow2) = 0x0p+0;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3217;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3220:
  llvm_cbe_tmp__3024 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3024))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3221;
  } else {
    goto llvm_cbe_tmp__3219;
  }

llvm_cbe_tmp__3221:
  *(&per_v_pc) = 1u;
  *(&train_upc) = 1u;
  llvm_cbe_tmp__3025 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3026 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__2870->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3025)));
  llvm_cbe_tmp__3027 = *llvm_cbe_tmp__3026;
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3027;
  _Z4waitv();
  llvm_cbe_tmp__3028 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3029 = *(&llvm_cbe_max);
  *(&llvm_cbe_ve_current) = (((float )(llvm_cbe_tmp__3028 - llvm_cbe_tmp__3029)));
  _Z4waitv();
  llvm_cbe_tmp__3030 = *(&llvm_cbe_ve_current);
  llvm_cbe_tmp__3031 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3032 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__2870->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3031)));
  *llvm_cbe_tmp__3032 = llvm_cbe_tmp__3030;
  _Z4waitv();
  llvm_cbe_tmp__3033 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3033) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3220;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3222:
  *(&per_v_pc) = 1u;
  *(&train_upc) = 1u;
  llvm_cbe_tmp__3023 = *(&llvm_cbe_max);
  *(&llvm_cbe_max) = (((float )(llvm_cbe_tmp__3023 - 0x1.fp+4)));
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3220;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3223:
  llvm_cbe_tmp__2940 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2940))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3224;
  } else {
    goto llvm_cbe_tmp__3222;
  }

llvm_cbe_tmp__3225:
  llvm_cbe_tmp__3022 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3022) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3223;

llvm_cbe_tmp__3226:
  llvm_cbe_tmp__3021 = *(&llvm_cbe_sum);
  *(&llvm_cbe_max) = llvm_cbe_tmp__3021;
  goto llvm_cbe_tmp__3225;

llvm_cbe_tmp__3227:
  llvm_cbe_tmp__3016 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3017 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3018 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__2870->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3017)));
  *llvm_cbe_tmp__3018 = llvm_cbe_tmp__3016;
  _Z4waitv();
  llvm_cbe_tmp__3019 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3020 = *(&llvm_cbe_max);
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__3019, llvm_cbe_tmp__3020))) {
    goto llvm_cbe_tmp__3226;
  } else {
    goto llvm_cbe_tmp__3225;
  }

llvm_cbe_tmp__3224:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_h) = ((unsigned short )0);
  llvm_cbe_tmp__2941 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2941))) < ((signed int )101u))) {
    goto llvm_cbe_tmp__3228;
  } else {
    goto llvm_cbe_tmp__3227;
  }

llvm_cbe_tmp__3228:
  llvm_cbe_tmp__2942 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2943 = *(&llvm_cbe_tmp__2854);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2942)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2943))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__3227;
  } else {
    goto llvm_cbe_tmp__3208;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3229:
  *(&llvm_cbe_max) = -0x1.f4p+8;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3223;

llvm_cbe_tmp__3230:
  llvm_cbe_tmp__2938 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2939 = *(&llvm_cbe_tmp__2855);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2938)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__2939)))) {
    goto llvm_cbe_tmp__3231;
  } else {
    goto llvm_cbe_tmp__3229;
  }

llvm_cbe_tmp__3215:
  llvm_cbe_tmp__3126 = *(&llvm_cbe_v);
  *(&llvm_cbe_v) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3126))) + ((unsigned int )5u))))));
  llvm_cbe_tmp__3127 = *(&llvm_cbe_v);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3127))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__3230;
  } else {
    goto llvm_cbe_tmp__3231;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3214:
  llvm_cbe_tmp__3047 = *(&conf_done_inp);
  llvm_cbe_tmp__3048 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__3049 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__3050 = *(&conf_num_users_inp);
  llvm_cbe_tmp__3051 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__3052 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__3053 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__3054 = *(&rst_inp);
  llvm_cbe_tmp__3055 = *(&rd_grant_inp);
  llvm_cbe_tmp__3056 = *(&data_in_inp);
  llvm_cbe_tmp__3057 = *(&wr_grant_inp);
  _ZN11model_train6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3047&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3048)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3049)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3050)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3051)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3052)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3053)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3054&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3055&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3056)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3057&1u))&1)))));
  llvm_cbe_tmp__3058 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field36))))&1);
  llvm_cbe_tmp__3059 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3058)) == llvm_cbe_tmp__3059), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__3060 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field12))))&1);
  llvm_cbe_tmp__3061 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3060)) == llvm_cbe_tmp__3061), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__3062 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field30)));
  llvm_cbe_tmp__3063 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3062)) == llvm_cbe_tmp__3063), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__3064 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field31)));
  llvm_cbe_tmp__3065 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3064)) == llvm_cbe_tmp__3065), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__3066 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field32)));
  llvm_cbe_tmp__3067 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3066)) == llvm_cbe_tmp__3067), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__3068 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field33)));
  llvm_cbe_tmp__3069 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3068)) == llvm_cbe_tmp__3069), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__3070 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field34)));
  llvm_cbe_tmp__3071 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3070)) == llvm_cbe_tmp__3071), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__3072 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field35)));
  llvm_cbe_tmp__3073 = *((&GM.field11));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3072)) == llvm_cbe_tmp__3073), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__3074 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field2)));
  llvm_cbe_tmp__3075 = *((&GM.field21));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3074)) == llvm_cbe_tmp__3075), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__3076 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field3)));
  llvm_cbe_tmp__3077 = *((&GM.field22));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3076)) == llvm_cbe_tmp__3077), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__3078 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field4))))&1);
  llvm_cbe_tmp__3079 = *((&GM.field23));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3078)) == llvm_cbe_tmp__3079), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__3080 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field9))))&1);
  llvm_cbe_tmp__3081 = *((&GM.field37));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3080)) == llvm_cbe_tmp__3081), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__3082 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field7)));
  llvm_cbe_tmp__3083 = *((&GM.field35));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3082)) == llvm_cbe_tmp__3083), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__3084 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field8)));
  llvm_cbe_tmp__3085 = *((&GM.field36));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3084)) == llvm_cbe_tmp__3085), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__3086 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field11)));
  llvm_cbe_tmp__3087 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3086)) == llvm_cbe_tmp__3087), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__3088 = *(&upc);
  llvm_cbe_tmp__3089 = *((&GM.field31));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3088)) == llvm_cbe_tmp__3089), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__3090 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field37))))&1);
  llvm_cbe_tmp__3091 = *((&GM.field26));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3090)) == llvm_cbe_tmp__3091), ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__3092 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3093 = *((&GM.field28));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3092)), ((((double )(signed long long )(llvm_cbe_tmp__3093 & 65535ull))) / 0x1p+1))), ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__3094 = *(&llvm_cbe_max);
  llvm_cbe_tmp__3095 = *((&GM.field27));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3094)), ((((double )(signed long long )(llvm_cbe_tmp__3095 & 65535ull))) / 0x1p+1))), ((&_OC_str29.array[((signed int )0u)])));
  llvm_cbe_tmp__3096 = *(&llvm_cbe_sumOfpow2);
  llvm_cbe_tmp__3097 = *((&GM.field24));
  __CPROVER_assert(((((unsigned int )llvm_cbe_tmp__3096)) == (((unsigned int )llvm_cbe_tmp__3097))), ((&_OC_str20.array[((signed int )0u)])));
  llvm_cbe_tmp__3098 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3099 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3098)) == llvm_cbe_tmp__3099), ((&_OC_str21.array[((signed int )0u)])));
  llvm_cbe_tmp__3100 = *(&per_v_pc);
  llvm_cbe_tmp__3101 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3100)) == llvm_cbe_tmp__3101), ((&_OC_str30.array[((signed int )0u)])));
  llvm_cbe_tmp__3102 = *(&train_upc);
  llvm_cbe_tmp__3103 = *((&GM.field29));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3102)) == llvm_cbe_tmp__3103), ((&_OC_str22.array[((signed int )0u)])));
  llvm_cbe_tmp__3104 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3105 = *((&GM.field30));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3104)) == llvm_cbe_tmp__3105), ((&_OC_str23.array[((signed int )0u)])));
  llvm_cbe_tmp__3106 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3107 = *((&GM.field25));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3106)) == llvm_cbe_tmp__3107), ((&_OC_str24.array[((signed int )0u)])));
  llvm_cbe_tmp__3108 = *((&GM.field0.field0));
  llvm_cbe_tmp__3109 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2870->field20)), 0u);
  llvm_cbe_tmp__3110 = ((__CPROVER_array_equal(llvm_cbe_tmp__3108, llvm_cbe_tmp__3109))&1);
  __CPROVER_assert(llvm_cbe_tmp__3110, ((&_OC_str25.array[((signed int )0u)])));
  llvm_cbe_tmp__3111 = *((&GM.field19.field0));
  llvm_cbe_tmp__3112 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2870->field28)), 0u);
  llvm_cbe_tmp__3113 = ((__CPROVER_array_equal(llvm_cbe_tmp__3111, llvm_cbe_tmp__3112))&1);
  __CPROVER_assert(llvm_cbe_tmp__3113, ((&_OC_str26.array[((signed int )0u)])));
  llvm_cbe_tmp__3114 = *((&GM.field4.field0));
  llvm_cbe_tmp__3115 = *((&((&llvm_cbe_tmp__2870->field22))->field0));
  llvm_cbe_tmp__3116 = ((__CPROVER_array_equal(llvm_cbe_tmp__3114, llvm_cbe_tmp__3115))&1);
  __CPROVER_assert(llvm_cbe_tmp__3116, ((&_OC_str27.array[((signed int )0u)])));
  llvm_cbe_tmp__3117 = *((&GM.field16.field0));
  llvm_cbe_tmp__3118 = *((&((&llvm_cbe_tmp__2870->field24))->field0));
  llvm_cbe_tmp__3119 = ((__CPROVER_array_equal(llvm_cbe_tmp__3117, llvm_cbe_tmp__3118))&1);
  __CPROVER_assert(llvm_cbe_tmp__3119, ((&_OC_str28.array[((signed int )0u)])));
  llvm_cbe_tmp__3120 = *(&llvm_cbe_j);
  __CPROVER_assert((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3120))) < ((signed int )5u)), ((&_OC_str31.array[((signed int )0u)])));
  goto llvm_cbe_tmp__3212;

llvm_cbe_tmp__3206:
  *(&llvm_cbe_tmpb) = ((unsigned char )1);
  goto llvm_cbe_tmp__3207;

llvm_cbe_tmp__3207:
  llvm_cbe_tmp__3121 = *(&llvm_cbe_tmpb);
  llvm_cbe_tmp__3122 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3123 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3124 = _ZN11SysCArray1DIbLj512EEixEj(((&llvm_cbe_tmp__2870->field21)), (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3122))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3123)))))));
  *llvm_cbe_tmp__3124 = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3121&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__3125 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3125) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3213;

llvm_cbe_tmp__3231:
  llvm_cbe_tmp__3128 = *(&llvm_cbe_tmp__2855);
  llvm_cbe_tmp__3129 = _ZN11SysCArray1DIbLj512EEixEj(((&llvm_cbe_tmp__2870->field21)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3128)));
  *llvm_cbe_tmp__3129 = ((unsigned char )1);
  _Z4waitv();
  *(&per_v_pc) = 0u;
  *(&train_upc) = 2u;
  llvm_cbe_tmp__3130 = *(&conf_done_inp);
  llvm_cbe_tmp__3131 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__3132 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__3133 = *(&conf_num_users_inp);
  llvm_cbe_tmp__3134 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__3135 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__3136 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__3137 = *(&rst_inp);
  llvm_cbe_tmp__3138 = *(&rd_grant_inp);
  llvm_cbe_tmp__3139 = *(&data_in_inp);
  llvm_cbe_tmp__3140 = *(&wr_grant_inp);
  _ZN11model_train6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3130&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3131)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3132)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3133)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3134)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3135)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3136)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3137&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3138&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3139)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3140&1u))&1)))));
  llvm_cbe_tmp__3141 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field36))))&1);
  llvm_cbe_tmp__3142 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3141)) == llvm_cbe_tmp__3142), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__3143 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field12))))&1);
  llvm_cbe_tmp__3144 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3143)) == llvm_cbe_tmp__3144), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__3145 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field30)));
  llvm_cbe_tmp__3146 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3145)) == llvm_cbe_tmp__3146), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__3147 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field31)));
  llvm_cbe_tmp__3148 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3147)) == llvm_cbe_tmp__3148), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__3149 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field32)));
  llvm_cbe_tmp__3150 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3149)) == llvm_cbe_tmp__3150), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__3151 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field33)));
  llvm_cbe_tmp__3152 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3151)) == llvm_cbe_tmp__3152), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__3153 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field34)));
  llvm_cbe_tmp__3154 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3153)) == llvm_cbe_tmp__3154), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__3155 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2870->field35)));
  llvm_cbe_tmp__3156 = *((&GM.field11));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3155)) == llvm_cbe_tmp__3156), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__3157 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field2)));
  llvm_cbe_tmp__3158 = *((&GM.field21));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3157)) == llvm_cbe_tmp__3158), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__3159 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field3)));
  llvm_cbe_tmp__3160 = *((&GM.field22));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3159)) == llvm_cbe_tmp__3160), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__3161 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field4))))&1);
  llvm_cbe_tmp__3162 = *((&GM.field23));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3161)) == llvm_cbe_tmp__3162), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__3163 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field9))))&1);
  llvm_cbe_tmp__3164 = *((&GM.field37));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3163)) == llvm_cbe_tmp__3164), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__3165 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field7)));
  llvm_cbe_tmp__3166 = *((&GM.field35));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3165)) == llvm_cbe_tmp__3166), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__3167 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field8)));
  llvm_cbe_tmp__3168 = *((&GM.field36));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3167)) == llvm_cbe_tmp__3168), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__3169 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2870->field11)));
  llvm_cbe_tmp__3170 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3169)) == llvm_cbe_tmp__3170), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__3171 = *(&upc);
  llvm_cbe_tmp__3172 = *((&GM.field31));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3171)) == llvm_cbe_tmp__3172), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__3173 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2870->field37))))&1);
  llvm_cbe_tmp__3174 = *((&GM.field26));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3173)) == llvm_cbe_tmp__3174), ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__3175 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3176 = *((&GM.field28));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3175)), ((((double )(signed long long )(llvm_cbe_tmp__3176 & 65535ull))) / 0x1p+1))), ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__3177 = *(&llvm_cbe_max);
  llvm_cbe_tmp__3178 = *((&GM.field27));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3177)), ((((double )(signed long long )(llvm_cbe_tmp__3178 & 65535ull))) / 0x1p+1))), ((&_OC_str29.array[((signed int )0u)])));
  llvm_cbe_tmp__3179 = *(&llvm_cbe_sumOfpow2);
  llvm_cbe_tmp__3180 = *((&GM.field24));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3179)), ((((double )(unsigned long long )llvm_cbe_tmp__3180)) / 0x1p+0))), ((&_OC_str20.array[((signed int )0u)])));
  llvm_cbe_tmp__3181 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3182 = *((&GM.field7));
  if (((((unsigned long long )(unsigned short )llvm_cbe_tmp__3181)) == llvm_cbe_tmp__3182)) {
    llvm_cbe_tmp__3185__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__3232;
  } else {
    goto llvm_cbe_tmp__3233;
  }

llvm_cbe_tmp__3233:
  llvm_cbe_tmp__3183 = *(&llvm_cbe_j);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3183)) == 5u)) {
    goto llvm_cbe_tmp__3234;
  } else {
    llvm_cbe_tmp__3185__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__3232;
  }

llvm_cbe_tmp__3234:
  llvm_cbe_tmp__3184 = *((&GM.field7));
  llvm_cbe_tmp__3185__PHI_TEMPORARY = (llvm_cbe_tmp__3184 == 0ull);   /* for PHI node */
  goto llvm_cbe_tmp__3232;

llvm_cbe_tmp__3232:
  llvm_cbe_tmp__3185 = ((llvm_cbe_tmp__3185__PHI_TEMPORARY)&1);
  __CPROVER_assert(llvm_cbe_tmp__3185, ((&_OC_str21.array[((signed int )0u)])));
  llvm_cbe_tmp__3186 = *(&per_v_pc);
  llvm_cbe_tmp__3187 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3186)) == llvm_cbe_tmp__3187), ((&_OC_str30.array[((signed int )0u)])));
  llvm_cbe_tmp__3188 = *(&train_upc);
  llvm_cbe_tmp__3189 = *((&GM.field29));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3188)) == llvm_cbe_tmp__3189), ((&_OC_str22.array[((signed int )0u)])));
  llvm_cbe_tmp__3190 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3191 = *((&GM.field30));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3190)) == llvm_cbe_tmp__3191), ((&_OC_str23.array[((signed int )0u)])));
  llvm_cbe_tmp__3192 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3193 = *((&GM.field25));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3192)) == llvm_cbe_tmp__3193), ((&_OC_str24.array[((signed int )0u)])));
  llvm_cbe_tmp__3194 = *((&GM.field0.field0));
  llvm_cbe_tmp__3195 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2870->field20)), 0u);
  llvm_cbe_tmp__3196 = ((__CPROVER_array_equal(llvm_cbe_tmp__3194, llvm_cbe_tmp__3195))&1);
  __CPROVER_assert(llvm_cbe_tmp__3196, ((&_OC_str25.array[((signed int )0u)])));
  llvm_cbe_tmp__3197 = *((&GM.field19.field0));
  llvm_cbe_tmp__3198 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2870->field28)), 0u);
  llvm_cbe_tmp__3199 = ((__CPROVER_array_equal(llvm_cbe_tmp__3197, llvm_cbe_tmp__3198))&1);
  __CPROVER_assert(llvm_cbe_tmp__3199, ((&_OC_str26.array[((signed int )0u)])));
  llvm_cbe_tmp__3200 = *((&GM.field4.field0));
  llvm_cbe_tmp__3201 = *((&((&llvm_cbe_tmp__2870->field22))->field0));
  llvm_cbe_tmp__3202 = ((__CPROVER_array_equal(llvm_cbe_tmp__3200, llvm_cbe_tmp__3201))&1);
  __CPROVER_assert(llvm_cbe_tmp__3202, ((&_OC_str27.array[((signed int )0u)])));
  llvm_cbe_tmp__3203 = *((&GM.field16.field0));
  llvm_cbe_tmp__3204 = *((&((&llvm_cbe_tmp__2870->field24))->field0));
  llvm_cbe_tmp__3205 = ((__CPROVER_array_equal(llvm_cbe_tmp__3203, llvm_cbe_tmp__3204))&1);
  __CPROVER_assert(llvm_cbe_tmp__3205, ((&_OC_str28.array[((signed int )0u)])));
  goto llvm_cbe_tmp__3212;

llvm_cbe_tmp__3212:
  return;
}


unsigned char *_ZN11SysCArray1DIbLj512EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3235;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3236;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3237;
  unsigned int llvm_cbe_tmp__3238;
  unsigned char *llvm_cbe_tmp__3239;

  *(&llvm_cbe_tmp__3235) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3236) = llvm_cbe_idx;
  llvm_cbe_tmp__3237 = *(&llvm_cbe_tmp__3235);
  llvm_cbe_tmp__3238 = *(&llvm_cbe_tmp__3236);
  llvm_cbe_tmp__3239 = *((&llvm_cbe_tmp__3237->field0));
  return ((&llvm_cbe_tmp__3239[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3238)))]));
}


float *_ZN11SysCArray1DIfLj5EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3240;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3241;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3242;
  unsigned int llvm_cbe_tmp__3243;
  float *llvm_cbe_tmp__3244;

  *(&llvm_cbe_tmp__3240) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3241) = llvm_cbe_idx;
  llvm_cbe_tmp__3242 = *(&llvm_cbe_tmp__3240);
  llvm_cbe_tmp__3243 = *(&llvm_cbe_tmp__3241);
  llvm_cbe_tmp__3244 = *((&llvm_cbe_tmp__3242->field0));
  return ((&llvm_cbe_tmp__3244[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3243)))]));
}


void _ZN3rbm27activateHiddenUnits_predictEbtt(struct l_struct_OC_rbm *llvm_cbe_this, bool llvm_cbe_pingpong, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3245;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3246;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3247;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3248;    /* Address-exposed local */
  unsigned short llvm_cbe_h;    /* Address-exposed local */
  unsigned short llvm_cbe_v;    /* Address-exposed local */
  float llvm_cbe_sum;    /* Address-exposed local */
  float llvm_cbe_tmp;    /* Address-exposed local */
  float llvm_cbe_prob;    /* Address-exposed local */
  float llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_current_data;    /* Address-exposed local */
  unsigned char llvm_cbe_comp;    /* Address-exposed local */
  unsigned char llvm_cbe_th;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3249;
  unsigned short llvm_cbe_tmp__3250;
  unsigned short llvm_cbe_tmp__3251;
  unsigned short llvm_cbe_tmp__3252;
  unsigned short llvm_cbe_tmp__3253;
  unsigned short llvm_cbe_tmp__3254;
  unsigned short llvm_cbe_tmp__3255;
  unsigned short llvm_cbe_tmp__3256;
  unsigned char llvm_cbe_tmp__3257;
  unsigned char *llvm_cbe_tmp__3258;
  unsigned char llvm_cbe_tmp__3259;
  unsigned char llvm_cbe_tmp__3260;
  unsigned short llvm_cbe_tmp__3261;
  unsigned short llvm_cbe_tmp__3262;
  float *llvm_cbe_tmp__3263;
  float llvm_cbe_tmp__3264;
  float llvm_cbe_tmp__3265;
  float llvm_cbe_tmp__3266;
  unsigned short llvm_cbe_tmp__3267;
  float llvm_cbe_tmp__3268;
  unsigned long long llvm_cbe_tmp__3269;
  unsigned short llvm_cbe_tmp__3270;
  float llvm_cbe_tmp__3271;
  float llvm_cbe_tmp__3272;
  unsigned char llvm_cbe_tmp__3273;
  unsigned char llvm_cbe_tmp__3274;
  unsigned short llvm_cbe_tmp__3275;
  unsigned char *llvm_cbe_tmp__3276;
  unsigned short llvm_cbe_tmp__3277;
  unsigned short llvm_cbe_tmp__3278;
  unsigned char *llvm_cbe_tmp__3279;

  *(&llvm_cbe_tmp__3245) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3246) = (((unsigned char )(bool )llvm_cbe_pingpong));
  *(&llvm_cbe_tmp__3247) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__3248) = llvm_cbe_nv;
  llvm_cbe_tmp__3249 = *(&llvm_cbe_tmp__3245);
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__3280;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3280:
  llvm_cbe_tmp__3250 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3250))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__3281;
  } else {
    goto llvm_cbe_tmp__3282;
  }

llvm_cbe_tmp__3283:
  llvm_cbe_tmp__3274 = *(&llvm_cbe_th);
  llvm_cbe_tmp__3275 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3276 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3249->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3275)));
  *llvm_cbe_tmp__3276 = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3274&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__3277 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3277) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3280;

llvm_cbe_tmp__3284:
  *(&llvm_cbe_th) = ((unsigned char )1);
  goto llvm_cbe_tmp__3283;

llvm_cbe_tmp__3285:
  llvm_cbe_tmp__3268 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3269 = _Z8_c_16_15f(llvm_cbe_tmp__3268);
  llvm_cbe_tmp__3270 = _Z7sigmoidl(llvm_cbe_tmp__3269);
  llvm_cbe_tmp__3271 = _Z8_b_16_15l((((unsigned long long )(unsigned short )llvm_cbe_tmp__3270)));
  *(&llvm_cbe_prob) = llvm_cbe_tmp__3271;
  llvm_cbe_tmp__3272 = *(&llvm_cbe_prob);
  *(&llvm_cbe_comp) = (((unsigned char )(bool )(llvm_fcmp_olt(0x1p-1, llvm_cbe_tmp__3272))));
  llvm_cbe_tmp__3273 = *(&llvm_cbe_comp);
  if ((((((bool )llvm_cbe_tmp__3273&1u))&1))) {
    goto llvm_cbe_tmp__3284;
  } else {
    goto llvm_cbe_tmp__3286;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3287:
  llvm_cbe_tmp__3253 = *(&llvm_cbe_v);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3253))) < ((signed int )501u))) {
    goto llvm_cbe_tmp__3288;
  } else {
    goto llvm_cbe_tmp__3285;
  }

llvm_cbe_tmp__3289:
  llvm_cbe_tmp__3267 = *(&llvm_cbe_v);
  *(&llvm_cbe_v) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3267) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3287;

llvm_cbe_tmp__3290:
  llvm_cbe_tmp__3261 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3262 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3263 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__3249->field23)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3262)));
  llvm_cbe_tmp__3264 = *((&llvm_cbe_tmp__3263[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3261)))]));
  *(&llvm_cbe_tmp) = llvm_cbe_tmp__3264;
  _Z4waitv();
  llvm_cbe_tmp__3265 = *(&llvm_cbe_tmp);
  llvm_cbe_tmp__3266 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__3266 + llvm_cbe_tmp__3265)));
  goto llvm_cbe_tmp__3289;

llvm_cbe_tmp__3291:
  llvm_cbe_tmp__3256 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3257 = *(&llvm_cbe_tmp__3246);
  llvm_cbe_tmp__3258 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__3249->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3257&1u))&1)))));
  llvm_cbe_tmp__3259 = *((&llvm_cbe_tmp__3258[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3256)))]));
  *(&llvm_cbe_current_data) = llvm_cbe_tmp__3259;
  _Z4waitv();
  llvm_cbe_tmp__3260 = *(&llvm_cbe_current_data);
  if (((((unsigned int )(unsigned char )llvm_cbe_tmp__3260)) == 1u)) {
    goto llvm_cbe_tmp__3290;
  } else {
    goto llvm_cbe_tmp__3289;
  }

llvm_cbe_tmp__3288:
  llvm_cbe_tmp__3254 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3255 = *(&llvm_cbe_tmp__3248);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3254)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3255))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__3285;
  } else {
    goto llvm_cbe_tmp__3291;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3292:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_v) = ((unsigned short )0);
  goto llvm_cbe_tmp__3287;

llvm_cbe_tmp__3281:
  llvm_cbe_tmp__3251 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3252 = *(&llvm_cbe_tmp__3247);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3251)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__3252)))) {
    goto llvm_cbe_tmp__3282;
  } else {
    goto llvm_cbe_tmp__3292;
  }

llvm_cbe_tmp__3286:
  *(&llvm_cbe_th) = ((unsigned char )0);
  goto llvm_cbe_tmp__3283;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3282:
  llvm_cbe_tmp__3278 = *(&llvm_cbe_tmp__3247);
  llvm_cbe_tmp__3279 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3249->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3278)));
  *llvm_cbe_tmp__3279 = ((unsigned char )1);
  _Z4waitv();
  return;
}


void _ZN3rbm28activateVisibleUnits_predictEtt(struct l_struct_OC_rbm *llvm_cbe_this, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3293;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3294;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3295;    /* Address-exposed local */
  unsigned short llvm_cbe_v;    /* Address-exposed local */
  unsigned short llvm_cbe_h;    /* Address-exposed local */
  float llvm_cbe_sum;    /* Address-exposed local */
  float llvm_cbe_max;    /* Address-exposed local */
  float llvm_cbe_probs;    /* Address-exposed local */
  struct l_unnamed22 llvm_cbe_pow2;    /* Address-exposed local */
  float llvm_cbe_sumOfpow2;    /* Address-exposed local */
  float llvm_cbe_expectation;    /* Address-exposed local */
  unsigned char llvm_cbe_prediction;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp;    /* Address-exposed local */
  float llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned short llvm_cbe_j;    /* Address-exposed local */
  float llvm_cbe_dp;    /* Address-exposed local */
  float llvm_cbe_dp1;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3296;
  unsigned short llvm_cbe_tmp__3297;
  unsigned short llvm_cbe_tmp__3298;
  unsigned short llvm_cbe_tmp__3299;
  unsigned short llvm_cbe_tmp__3300;
  unsigned short llvm_cbe_tmp__3301;
  unsigned short llvm_cbe_tmp__3302;
  unsigned short llvm_cbe_tmp__3303;
  unsigned short llvm_cbe_tmp__3304;
  unsigned char *llvm_cbe_tmp__3305;
  unsigned char llvm_cbe_tmp__3306;
  unsigned short llvm_cbe_tmp__3307;
  unsigned short llvm_cbe_tmp__3308;
  unsigned short llvm_cbe_tmp__3309;
  float *llvm_cbe_tmp__3310;
  float llvm_cbe_tmp__3311;
  unsigned char llvm_cbe_tmp__3312;
  float llvm_cbe_tmp__3313;
  float llvm_cbe_tmp__3314;
  unsigned short llvm_cbe_tmp__3315;
  float llvm_cbe_tmp__3316;
  unsigned short llvm_cbe_tmp__3317;
  float *llvm_cbe_tmp__3318;
  float llvm_cbe_tmp__3319;
  float llvm_cbe_tmp__3320;
  float llvm_cbe_tmp__3321;
  unsigned short llvm_cbe_tmp__3322;
  float llvm_cbe_tmp__3323;
  unsigned short llvm_cbe_tmp__3324;
  unsigned short llvm_cbe_tmp__3325;
  float *llvm_cbe_tmp__3326;
  float llvm_cbe_tmp__3327;
  float llvm_cbe_tmp__3328;
  float llvm_cbe_tmp__3329;
  unsigned short llvm_cbe_tmp__3330;
  float *llvm_cbe_tmp__3331;
  unsigned short llvm_cbe_tmp__3332;
  unsigned short llvm_cbe_tmp__3333;
  unsigned short llvm_cbe_tmp__3334;
  float *llvm_cbe_tmp__3335;
  float llvm_cbe_tmp__3336;
  float llvm_cbe_tmp__3337;
  unsigned long long llvm_cbe_tmp__3338;
  unsigned short llvm_cbe_tmp__3339;
  float llvm_cbe_tmp__3340;
  float llvm_cbe_tmp__3341;
  float llvm_cbe_tmp__3342;
  float llvm_cbe_tmp__3343;
  unsigned short llvm_cbe_tmp__3344;
  unsigned short llvm_cbe_tmp__3345;
  unsigned short llvm_cbe_tmp__3346;
  unsigned short llvm_cbe_tmp__3347;
  float llvm_cbe_tmp__3348;
  float llvm_cbe_tmp__3349;
  float llvm_cbe_tmp__3350;
  unsigned short llvm_cbe_tmp__3351;
  float llvm_cbe_tmp__3352;
  float llvm_cbe_tmp__3353;
  unsigned short llvm_cbe_tmp__3354;
  float llvm_cbe_tmp__3355;
  unsigned long long llvm_cbe_tmp__3356;
  unsigned short llvm_cbe_tmp__3357;
  unsigned short llvm_cbe_tmp__3358;
  unsigned char llvm_cbe_tmp__3359;
  unsigned short llvm_cbe_tmp__3360;
  unsigned short llvm_cbe_tmp__3361;
  unsigned char *llvm_cbe_tmp__3362;
  unsigned short llvm_cbe_tmp__3363;
  unsigned short llvm_cbe_tmp__3364;
  unsigned short llvm_cbe_tmp__3365;
  unsigned char *llvm_cbe_tmp__3366;

  *(&llvm_cbe_tmp__3293) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3294) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__3295) = llvm_cbe_nv;
  llvm_cbe_tmp__3296 = *(&llvm_cbe_tmp__3293);
  *(&llvm_cbe_v) = ((unsigned short )0);
  goto llvm_cbe_tmp__3367;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3367:
  llvm_cbe_tmp__3297 = *(&llvm_cbe_v);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3297))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__3368;
  } else {
    goto llvm_cbe_tmp__3369;
  }

llvm_cbe_tmp__3370:
  llvm_cbe_tmp__3364 = *(&llvm_cbe_v);
  *(&llvm_cbe_v) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3364))) + ((unsigned int )5u))))));
  goto llvm_cbe_tmp__3367;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3371:
  llvm_cbe_tmp__3357 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3357))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3372;
  } else {
    goto llvm_cbe_tmp__3370;
  }

llvm_cbe_tmp__3373:
  _Z4waitv();
  llvm_cbe_tmp__3363 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3363) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3371;

llvm_cbe_tmp__3374:
  *llvm_cbe_tmp__3362 = ((unsigned char )1);
  goto llvm_cbe_tmp__3373;

llvm_cbe_tmp__3372:
  llvm_cbe_tmp__3358 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3359 = *(&llvm_cbe_prediction);
  llvm_cbe_tmp__3360 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3361 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3362 = _ZN11SysCArray1DIbLj512EEixEj(((&llvm_cbe_tmp__3296->field27)), (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3360))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3361)))))));
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3358)) == (((unsigned int )(unsigned char )llvm_cbe_tmp__3359)))) {
    goto llvm_cbe_tmp__3374;
  } else {
    goto llvm_cbe_tmp__3375;
  }

llvm_cbe_tmp__3375:
  *llvm_cbe_tmp__3362 = ((unsigned char )0);
  goto llvm_cbe_tmp__3373;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3376:
  llvm_cbe_tmp__3355 = *(&llvm_cbe_expectation);
  llvm_cbe_tmp__3356 = _Z6round_l((((signed long long )llvm_cbe_tmp__3355)));
  *(&llvm_cbe_prediction) = (((unsigned char )llvm_cbe_tmp__3356));
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3371;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3377:
  llvm_cbe_tmp__3346 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3346))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3378;
  } else {
    goto llvm_cbe_tmp__3376;
  }

llvm_cbe_tmp__3378:
  llvm_cbe_tmp__3347 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3348 = *((&llvm_cbe_pow2.array[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3347)))]));
  *(&llvm_cbe_dp1) = llvm_cbe_tmp__3348;
  _Z4waitv();
  llvm_cbe_tmp__3349 = *(&llvm_cbe_dp1);
  llvm_cbe_tmp__3350 = *(&llvm_cbe_sumOfpow2);
  *(&llvm_cbe_probs) = (((float )(llvm_cbe_tmp__3349 / llvm_cbe_tmp__3350)));
  llvm_cbe_tmp__3351 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3352 = *(&llvm_cbe_probs);
  llvm_cbe_tmp__3353 = *(&llvm_cbe_expectation);
  *(&llvm_cbe_expectation) = (((float )(llvm_cbe_tmp__3353 + (((float )((((float )(signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3351)))) * llvm_cbe_tmp__3352))))));
  llvm_cbe_tmp__3354 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3354) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3377;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3379:
  *(&llvm_cbe_expectation) = 0x0p+0;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3377;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3380:
  llvm_cbe_tmp__3333 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3333))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3381;
  } else {
    goto llvm_cbe_tmp__3379;
  }

llvm_cbe_tmp__3381:
  llvm_cbe_tmp__3334 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3335 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3296->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3334)));
  llvm_cbe_tmp__3336 = *llvm_cbe_tmp__3335;
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3336;
  _Z4waitv();
  llvm_cbe_tmp__3337 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3338 = _Z8_c_16_15f(llvm_cbe_tmp__3337);
  llvm_cbe_tmp__3339 = _Z10to_int_expl(llvm_cbe_tmp__3338);
  llvm_cbe_tmp__3340 = _Z8_b_16_15l((((unsigned long long )(unsigned short )llvm_cbe_tmp__3339)));
  *(&llvm_cbe_dp) = llvm_cbe_tmp__3340;
  llvm_cbe_tmp__3341 = *(&llvm_cbe_dp);
  llvm_cbe_tmp__3342 = *(&llvm_cbe_sumOfpow2);
  *(&llvm_cbe_sumOfpow2) = (((float )(llvm_cbe_tmp__3342 + llvm_cbe_tmp__3341)));
  llvm_cbe_tmp__3343 = *(&llvm_cbe_dp);
  llvm_cbe_tmp__3344 = *(&llvm_cbe_j);
  *((&llvm_cbe_pow2.array[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3344)))])) = llvm_cbe_tmp__3343;
  llvm_cbe_tmp__3345 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3345) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3380;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3382:
  *(&llvm_cbe_sumOfpow2) = 0x0p+0;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3380;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3383:
  llvm_cbe_tmp__3324 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3324))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3384;
  } else {
    goto llvm_cbe_tmp__3382;
  }

llvm_cbe_tmp__3384:
  llvm_cbe_tmp__3325 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3326 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3296->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3325)));
  llvm_cbe_tmp__3327 = *llvm_cbe_tmp__3326;
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3327;
  _Z4waitv();
  llvm_cbe_tmp__3328 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3329 = *(&llvm_cbe_max);
  llvm_cbe_tmp__3330 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3331 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3296->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3330)));
  *llvm_cbe_tmp__3331 = (((float )(llvm_cbe_tmp__3328 - llvm_cbe_tmp__3329)));
  _Z4waitv();
  llvm_cbe_tmp__3332 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3332) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3383;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3385:
  llvm_cbe_tmp__3323 = *(&llvm_cbe_max);
  *(&llvm_cbe_max) = (((float )(llvm_cbe_tmp__3323 - 0x1.fp+4)));
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3383;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3386:
  llvm_cbe_tmp__3300 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3300))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3387;
  } else {
    goto llvm_cbe_tmp__3385;
  }

llvm_cbe_tmp__3388:
  llvm_cbe_tmp__3322 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3322) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3386;

llvm_cbe_tmp__3389:
  llvm_cbe_tmp__3321 = *(&llvm_cbe_sum);
  *(&llvm_cbe_max) = llvm_cbe_tmp__3321;
  goto llvm_cbe_tmp__3388;

llvm_cbe_tmp__3390:
  llvm_cbe_tmp__3316 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3317 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3318 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3296->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3317)));
  *llvm_cbe_tmp__3318 = llvm_cbe_tmp__3316;
  _Z4waitv();
  llvm_cbe_tmp__3319 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3320 = *(&llvm_cbe_max);
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__3319, llvm_cbe_tmp__3320))) {
    goto llvm_cbe_tmp__3389;
  } else {
    goto llvm_cbe_tmp__3388;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3391:
  llvm_cbe_tmp__3301 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3301))) < ((signed int )101u))) {
    goto llvm_cbe_tmp__3392;
  } else {
    goto llvm_cbe_tmp__3390;
  }

llvm_cbe_tmp__3393:
  _Z4waitv();
  llvm_cbe_tmp__3315 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3315) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3391;

llvm_cbe_tmp__3394:
  llvm_cbe_tmp__3304 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3305 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3296->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3304)));
  llvm_cbe_tmp__3306 = *llvm_cbe_tmp__3305;
  *(&llvm_cbe_tmp2) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3306&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__3307 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3308 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3309 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3310 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__3296->field23)), (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3308))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3309)))))));
  llvm_cbe_tmp__3311 = *((&llvm_cbe_tmp__3310[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3307)))]));
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3311;
  _Z4waitv();
  llvm_cbe_tmp__3312 = *(&llvm_cbe_tmp2);
  if ((((((bool )llvm_cbe_tmp__3312&1u))&1))) {
    goto llvm_cbe_tmp__3395;
  } else {
    goto llvm_cbe_tmp__3393;
  }

llvm_cbe_tmp__3392:
  llvm_cbe_tmp__3302 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3303 = *(&llvm_cbe_tmp__3294);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3302)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3303))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__3390;
  } else {
    goto llvm_cbe_tmp__3394;
  }

llvm_cbe_tmp__3395:
  llvm_cbe_tmp__3313 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3314 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__3314 + llvm_cbe_tmp__3313)));
  goto llvm_cbe_tmp__3393;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3387:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__3391;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3396:
  *(&llvm_cbe_max) = -0x1.f4p+8;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3386;

llvm_cbe_tmp__3368:
  llvm_cbe_tmp__3298 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3299 = *(&llvm_cbe_tmp__3295);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3298)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__3299)))) {
    goto llvm_cbe_tmp__3369;
  } else {
    goto llvm_cbe_tmp__3396;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3369:
  llvm_cbe_tmp__3365 = *(&llvm_cbe_tmp__3295);
  llvm_cbe_tmp__3366 = _ZN11SysCArray1DIbLj512EEixEj(((&llvm_cbe_tmp__3296->field27)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3365)));
  *llvm_cbe_tmp__3366 = ((unsigned char )1);
  _Z4waitv();
  return;
}


static void __cxx_global_var_init32(void) {
  _ZN3rbmC1Ev((&IMPL));
  return;
}


void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3397;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3398;

  *(&llvm_cbe_tmp__3397) = llvm_cbe_this;
  llvm_cbe_tmp__3398 = *(&llvm_cbe_tmp__3397);
  _ZN3rbmC2Ev(llvm_cbe_tmp__3398);
  return;
}


unsigned int main(void) {
  unsigned int llvm_cbe_tmp__3399;    /* Address-exposed local */
  _GLOBAL__I_a();  CODE_FOR_MAIN();
  *(&llvm_cbe_tmp__3399) = 0u;
  _ZN3rbm9train_rbmEv((&IMPL));
  return 0u;
}


void _ZN8type_memIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3400;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3401;
  unsigned char *llvm_cbe_tmp__3402;

  *(&llvm_cbe_tmp__3400) = llvm_cbe_this;
  llvm_cbe_tmp__3401 = *(&llvm_cbe_tmp__3400);
  llvm_cbe_tmp__3402 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3401->field0)) = llvm_cbe_tmp__3402;
  return;
}


void _ZN8type_memItLj8EEC2Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__3403;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3404;
  unsigned char *llvm_cbe_tmp__3405;

  *(&llvm_cbe_tmp__3403) = llvm_cbe_this;
  llvm_cbe_tmp__3404 = *(&llvm_cbe_tmp__3403);
  llvm_cbe_tmp__3405 = __CPROVER_malloc(16ull);
  *((&llvm_cbe_tmp__3404->field0)) = (((unsigned short *)llvm_cbe_tmp__3405));
  return;
}


void _ZN8type_memIjLj8EEC2Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__3406;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3407;
  unsigned char *llvm_cbe_tmp__3408;

  *(&llvm_cbe_tmp__3406) = llvm_cbe_this;
  llvm_cbe_tmp__3407 = *(&llvm_cbe_tmp__3406);
  llvm_cbe_tmp__3408 = __CPROVER_malloc(32ull);
  *((&llvm_cbe_tmp__3407->field0)) = (((unsigned int *)llvm_cbe_tmp__3408));
  return;
}


void _ZN8type_memIbLj65536EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3409;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3410;
  unsigned char *llvm_cbe_tmp__3411;

  *(&llvm_cbe_tmp__3409) = llvm_cbe_this;
  llvm_cbe_tmp__3410 = *(&llvm_cbe_tmp__3409);
  llvm_cbe_tmp__3411 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3410->field0)) = llvm_cbe_tmp__3411;
  return;
}


void _ZN8type_memIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3412;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3413;
  unsigned char *llvm_cbe_tmp__3414;

  *(&llvm_cbe_tmp__3412) = llvm_cbe_this;
  llvm_cbe_tmp__3413 = *(&llvm_cbe_tmp__3412);
  llvm_cbe_tmp__3414 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3413->field0)) = llvm_cbe_tmp__3414;
  return;
}


void _ZN8type_memIhLj65536EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3415;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3416;
  unsigned char *llvm_cbe_tmp__3417;

  *(&llvm_cbe_tmp__3415) = llvm_cbe_this;
  llvm_cbe_tmp__3416 = *(&llvm_cbe_tmp__3415);
  llvm_cbe_tmp__3417 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3416->field0)) = llvm_cbe_tmp__3417;
  return;
}


void _ZN8type_memIbLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3418;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3419;

  *(&llvm_cbe_tmp__3418) = llvm_cbe_this;
  llvm_cbe_tmp__3419 = *(&llvm_cbe_tmp__3418);
  return;
}


void _ZN8type_memItLj8EED2Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__3420;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3421;

  *(&llvm_cbe_tmp__3420) = llvm_cbe_this;
  llvm_cbe_tmp__3421 = *(&llvm_cbe_tmp__3420);
  return;
}


void _ZN8type_memIjLj8EED2Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__3422;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3423;

  *(&llvm_cbe_tmp__3422) = llvm_cbe_this;
  llvm_cbe_tmp__3423 = *(&llvm_cbe_tmp__3422);
  return;
}


void _ZN8type_memIbLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3424;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3425;

  *(&llvm_cbe_tmp__3424) = llvm_cbe_this;
  llvm_cbe_tmp__3425 = *(&llvm_cbe_tmp__3424);
  return;
}


void _ZN8type_memIbLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3426;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3427;

  *(&llvm_cbe_tmp__3426) = llvm_cbe_this;
  llvm_cbe_tmp__3427 = *(&llvm_cbe_tmp__3426);
  return;
}


void _ZN8type_memIhLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3428;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3429;

  *(&llvm_cbe_tmp__3428) = llvm_cbe_this;
  llvm_cbe_tmp__3429 = *(&llvm_cbe_tmp__3428);
  return;
}


void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3430;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3431;
  unsigned char *llvm_cbe_tmp__3432;
  unsigned char llvm_cbe_tmp__3433;
  unsigned char *llvm_cbe_tmp__3434;
  unsigned char llvm_cbe_tmp__3435;
  unsigned char *llvm_cbe_tmp__3436;
  unsigned char llvm_cbe_tmp__3437;
  unsigned char *llvm_cbe_tmp__3438;
  unsigned char llvm_cbe_tmp__3439;
  unsigned char *llvm_cbe_tmp__3440;
  unsigned char llvm_cbe_tmp__3441;

  *(&llvm_cbe_tmp__3430) = llvm_cbe_this;
  llvm_cbe_tmp__3431 = *(&llvm_cbe_tmp__3430);
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3431->field0)), ((&_OC_str33.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3431->field1)), ((&_OC_str34.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field2)), ((&_OC_str35.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field3)), ((&_OC_str36.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3431->field4)), ((&_OC_str37.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3431->field5)), ((&_OC_str38.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field6)), ((&_OC_str39.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field7)), ((&_OC_str40.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field8)), ((&_OC_str41.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3431->field9)), ((&_OC_str42.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3431->field10)), ((&_OC_str43.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field11)), ((&_OC_str44.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3431->field12)), ((&_OC_str45.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3431->field13)), ((&_OC_str46.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field14)), ((&_OC_str47.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field15)), ((&_OC_str48.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field16)), ((&_OC_str49.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field17)), ((&_OC_str50.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field18)), ((&_OC_str51.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3431->field19)), ((&_OC_str52.array[((signed int )0u)])));
  _ZN13SysCArray2DstIhLj2ELj512EEC1Ev(((&llvm_cbe_tmp__3431->field20)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__3431->field21)));
  _ZN11SysCArray1DIbLj128EEC1Ev(((&llvm_cbe_tmp__3431->field22)));
  _ZN11SysCArray2DIfLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3431->field23)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3431->field24)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3431->field25)));
  _ZN11SysCArray1DIfLj5EEC1Ev(((&llvm_cbe_tmp__3431->field26)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__3431->field27)));
  _ZN13SysCArray2DstIhLj2ELj128EEC1Ev(((&llvm_cbe_tmp__3431->field28)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3431->field30)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3431->field31)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3431->field32)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3431->field33)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3431->field34)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3431->field35)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field36)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field37)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field38)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field39)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field40)));
  _ZN15sc_signal_int32C1Ev(((&llvm_cbe_tmp__3431->field41)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field42)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field43)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field44)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3431->field45)));
  llvm_cbe_tmp__3432 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3431->field1)));
  llvm_cbe_tmp__3433 = *llvm_cbe_tmp__3432;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3433&1u))&1)))), 0);
  llvm_cbe_tmp__3434 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3431->field1)));
  llvm_cbe_tmp__3435 = *llvm_cbe_tmp__3434;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3435&1u))&1)))), 0);
  llvm_cbe_tmp__3436 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3431->field1)));
  llvm_cbe_tmp__3437 = *llvm_cbe_tmp__3436;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3437&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__3438 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3431->field1)));
  llvm_cbe_tmp__3439 = *llvm_cbe_tmp__3438;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3439&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__3440 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3431->field1)));
  llvm_cbe_tmp__3441 = *llvm_cbe_tmp__3440;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3441&1u))&1)))), 0);
  return;
}


void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3442;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3443;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3444;
  unsigned char *llvm_cbe_tmp__3445;

  *(&llvm_cbe_tmp__3442) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3443) = llvm_cbe_p;
  llvm_cbe_tmp__3444 = *(&llvm_cbe_tmp__3442);
  llvm_cbe_tmp__3445 = *(&llvm_cbe_tmp__3443);
  _ZN14sc_signal_boolC2EPKc(llvm_cbe_tmp__3444, llvm_cbe_tmp__3445);
  return;
}


void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3446;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3447;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3448;
  unsigned char *llvm_cbe_tmp__3449;

  *(&llvm_cbe_tmp__3446) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3447) = llvm_cbe_p;
  llvm_cbe_tmp__3448 = *(&llvm_cbe_tmp__3446);
  llvm_cbe_tmp__3449 = *(&llvm_cbe_tmp__3447);
  _ZN13sc_signal_u32C2EPKc(llvm_cbe_tmp__3448, llvm_cbe_tmp__3449);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3450;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3451;

  *(&llvm_cbe_tmp__3450) = llvm_cbe_this;
  llvm_cbe_tmp__3451 = *(&llvm_cbe_tmp__3450);
  _ZN13SysCArray2DstIhLj2ELj512EEC2Ev(llvm_cbe_tmp__3451);
  return;
}


void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3452;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3453;

  *(&llvm_cbe_tmp__3452) = llvm_cbe_this;
  llvm_cbe_tmp__3453 = *(&llvm_cbe_tmp__3452);
  _ZN11SysCArray1DIbLj512EEC2Ev(llvm_cbe_tmp__3453);
  return;
}


void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3454;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3455;

  *(&llvm_cbe_tmp__3454) = llvm_cbe_this;
  llvm_cbe_tmp__3455 = *(&llvm_cbe_tmp__3454);
  _ZN11SysCArray1DIbLj128EEC2Ev(llvm_cbe_tmp__3455);
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3456;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3457;

  *(&llvm_cbe_tmp__3456) = llvm_cbe_this;
  llvm_cbe_tmp__3457 = *(&llvm_cbe_tmp__3456);
  _ZN11SysCArray2DIfLj501ELj101EEC2Ev(llvm_cbe_tmp__3457);
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3458;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3459;

  *(&llvm_cbe_tmp__3458) = llvm_cbe_this;
  llvm_cbe_tmp__3459 = *(&llvm_cbe_tmp__3458);
  _ZN11SysCArray2DIbLj501ELj101EEC2Ev(llvm_cbe_tmp__3459);
  return;
}


void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3460;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3461;

  *(&llvm_cbe_tmp__3460) = llvm_cbe_this;
  llvm_cbe_tmp__3461 = *(&llvm_cbe_tmp__3460);
  _ZN11SysCArray1DIfLj5EEC2Ev(llvm_cbe_tmp__3461);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3462;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3463;

  *(&llvm_cbe_tmp__3462) = llvm_cbe_this;
  llvm_cbe_tmp__3463 = *(&llvm_cbe_tmp__3462);
  _ZN13SysCArray2DstIhLj2ELj128EEC2Ev(llvm_cbe_tmp__3463);
  return;
}


void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3464;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3465;

  *(&llvm_cbe_tmp__3464) = llvm_cbe_this;
  llvm_cbe_tmp__3465 = *(&llvm_cbe_tmp__3464);
  _ZN13sc_signal_u16C2Ev(llvm_cbe_tmp__3465);
  return;
}


void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3466;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3467;

  *(&llvm_cbe_tmp__3466) = llvm_cbe_this;
  llvm_cbe_tmp__3467 = *(&llvm_cbe_tmp__3466);
  _ZN14sc_signal_boolC2Ev(llvm_cbe_tmp__3467);
  return;
}


void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3468;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3469;

  *(&llvm_cbe_tmp__3468) = llvm_cbe_this;
  llvm_cbe_tmp__3469 = *(&llvm_cbe_tmp__3468);
  _ZN15sc_signal_int32C2Ev(llvm_cbe_tmp__3469);
  return;
}


unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3470;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3471;

  *(&llvm_cbe_tmp__3470) = llvm_cbe_this;
  llvm_cbe_tmp__3471 = *(&llvm_cbe_tmp__3470);
  return ((&llvm_cbe_tmp__3471->field0));
}


void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3472;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3473;

  *(&llvm_cbe_tmp__3472) = llvm_cbe_this;
  llvm_cbe_tmp__3473 = *(&llvm_cbe_tmp__3472);
  return;
}


void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3474;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3475;

  *(&llvm_cbe_tmp__3474) = llvm_cbe_this;
  llvm_cbe_tmp__3475 = *(&llvm_cbe_tmp__3474);
  return;
}


void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3476;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3477;

  *(&llvm_cbe_tmp__3476) = llvm_cbe_this;
  llvm_cbe_tmp__3477 = *(&llvm_cbe_tmp__3476);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3478;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3479;
  unsigned char *llvm_cbe_tmp__3480;
  unsigned char *llvm_cbe_tmp__3481;

  *(&llvm_cbe_tmp__3478) = llvm_cbe_this;
  llvm_cbe_tmp__3479 = *(&llvm_cbe_tmp__3478);
  llvm_cbe_tmp__3480 = __CPROVER_malloc(256ull);
  *((&llvm_cbe_tmp__3479->field0)) = llvm_cbe_tmp__3480;
  llvm_cbe_tmp__3481 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3479->field1)) = llvm_cbe_tmp__3481;
  return;
}


void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3482;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3483;
  unsigned char *llvm_cbe_tmp__3484;

  *(&llvm_cbe_tmp__3482) = llvm_cbe_this;
  llvm_cbe_tmp__3483 = *(&llvm_cbe_tmp__3482);
  llvm_cbe_tmp__3484 = __CPROVER_malloc(20ull);
  *((&llvm_cbe_tmp__3483->field0)) = (((float *)llvm_cbe_tmp__3484));
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3485;    /* Address-exposed local */
  unsigned int llvm_cbe_eqsize;    /* Address-exposed local */
  unsigned int llvm_cbe_acsize;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3486;
  unsigned int llvm_cbe_tmp__3487;
  unsigned int llvm_cbe_tmp__3488;
  unsigned int llvm_cbe_tmp__3489;
  unsigned int llvm_cbe_tmp__3490;
  unsigned int llvm_cbe_tmp__3491;
  unsigned int llvm_cbe_tmp__3492;
  unsigned int llvm_cbe_tmp__3493;
  unsigned int llvm_cbe_tmp__3494;
  unsigned int llvm_cbe_tmp__3495;
  unsigned int llvm_cbe_tmp__3496;
  unsigned int llvm_cbe_tmp__3497;
  unsigned int llvm_cbe_tmp__3498;
  unsigned int llvm_cbe_tmp__3499;
  unsigned int llvm_cbe_tmp__3500;
  unsigned int llvm_cbe_tmp__3501;
  unsigned int llvm_cbe_tmp__3502;
  unsigned int llvm_cbe_tmp__3503;
  unsigned int llvm_cbe_tmp__3504;
  unsigned int llvm_cbe_tmp__3505;
  unsigned int llvm_cbe_tmp__3506;
  unsigned int llvm_cbe_tmp__3507;
  unsigned int llvm_cbe_tmp__3508;
  unsigned int llvm_cbe_tmp__3509;
  unsigned int llvm_cbe_tmp__3510;
  unsigned int llvm_cbe_tmp__3511;
  unsigned int llvm_cbe_tmp__3512;
  unsigned int llvm_cbe_tmp__3513;
  unsigned int llvm_cbe_tmp__3514;
  unsigned int llvm_cbe_tmp__3515;
  unsigned int llvm_cbe_tmp__3516;
  unsigned int llvm_cbe_tmp__3517;
  unsigned int llvm_cbe_tmp__3518;
  unsigned int llvm_cbe_tmp__3519;
  unsigned char *llvm_cbe_tmp__3520;

  *(&llvm_cbe_tmp__3485) = llvm_cbe_this;
  llvm_cbe_tmp__3486 = *(&llvm_cbe_tmp__3485);
  *(&llvm_cbe_acsize) = 50601u;
  llvm_cbe_tmp__3487 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3487 == 1u)) {
    goto llvm_cbe_tmp__3521;
  } else {
    goto llvm_cbe_tmp__3522;
  }

llvm_cbe_tmp__3521:
  *(&llvm_cbe_eqsize) = 1u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3522:
  llvm_cbe_tmp__3488 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3488 == 2u)) {
    goto llvm_cbe_tmp__3524;
  } else {
    goto llvm_cbe_tmp__3525;
  }

llvm_cbe_tmp__3524:
  *(&llvm_cbe_eqsize) = 2u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3525:
  llvm_cbe_tmp__3489 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3490 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3489) > ((unsigned int )2u)) & (((unsigned int )llvm_cbe_tmp__3490) <= ((unsigned int )4u)))&1))) {
    goto llvm_cbe_tmp__3526;
  } else {
    goto llvm_cbe_tmp__3527;
  }

llvm_cbe_tmp__3526:
  *(&llvm_cbe_eqsize) = 4u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3527:
  llvm_cbe_tmp__3491 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3492 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3491) > ((unsigned int )4u)) & (((unsigned int )llvm_cbe_tmp__3492) <= ((unsigned int )8u)))&1))) {
    goto llvm_cbe_tmp__3528;
  } else {
    goto llvm_cbe_tmp__3529;
  }

llvm_cbe_tmp__3528:
  *(&llvm_cbe_eqsize) = 8u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3529:
  llvm_cbe_tmp__3493 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3494 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3493) > ((unsigned int )8u)) & (((unsigned int )llvm_cbe_tmp__3494) <= ((unsigned int )16u)))&1))) {
    goto llvm_cbe_tmp__3530;
  } else {
    goto llvm_cbe_tmp__3531;
  }

llvm_cbe_tmp__3530:
  *(&llvm_cbe_eqsize) = 16u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3531:
  llvm_cbe_tmp__3495 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3496 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3495) > ((unsigned int )16u)) & (((unsigned int )llvm_cbe_tmp__3496) <= ((unsigned int )32u)))&1))) {
    goto llvm_cbe_tmp__3532;
  } else {
    goto llvm_cbe_tmp__3533;
  }

llvm_cbe_tmp__3532:
  *(&llvm_cbe_eqsize) = 32u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3533:
  llvm_cbe_tmp__3497 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3498 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3497) > ((unsigned int )32u)) & (((unsigned int )llvm_cbe_tmp__3498) <= ((unsigned int )64u)))&1))) {
    goto llvm_cbe_tmp__3534;
  } else {
    goto llvm_cbe_tmp__3535;
  }

llvm_cbe_tmp__3534:
  *(&llvm_cbe_eqsize) = 64u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3535:
  llvm_cbe_tmp__3499 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3500 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3499) > ((unsigned int )64u)) & (((unsigned int )llvm_cbe_tmp__3500) <= ((unsigned int )128u)))&1))) {
    goto llvm_cbe_tmp__3536;
  } else {
    goto llvm_cbe_tmp__3537;
  }

llvm_cbe_tmp__3536:
  *(&llvm_cbe_eqsize) = 128u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3537:
  llvm_cbe_tmp__3501 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3502 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3501) > ((unsigned int )128u)) & (((unsigned int )llvm_cbe_tmp__3502) <= ((unsigned int )256u)))&1))) {
    goto llvm_cbe_tmp__3538;
  } else {
    goto llvm_cbe_tmp__3539;
  }

llvm_cbe_tmp__3538:
  *(&llvm_cbe_eqsize) = 256u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3539:
  llvm_cbe_tmp__3503 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3504 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3503) > ((unsigned int )256u)) & (((unsigned int )llvm_cbe_tmp__3504) <= ((unsigned int )512u)))&1))) {
    goto llvm_cbe_tmp__3540;
  } else {
    goto llvm_cbe_tmp__3541;
  }

llvm_cbe_tmp__3540:
  *(&llvm_cbe_eqsize) = 512u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3541:
  llvm_cbe_tmp__3505 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3506 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3505) > ((unsigned int )512u)) & (((unsigned int )llvm_cbe_tmp__3506) <= ((unsigned int )1024u)))&1))) {
    goto llvm_cbe_tmp__3542;
  } else {
    goto llvm_cbe_tmp__3543;
  }

llvm_cbe_tmp__3542:
  *(&llvm_cbe_eqsize) = 1024u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3543:
  llvm_cbe_tmp__3507 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3508 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3507) > ((unsigned int )1024u)) & (((unsigned int )llvm_cbe_tmp__3508) <= ((unsigned int )2048u)))&1))) {
    goto llvm_cbe_tmp__3544;
  } else {
    goto llvm_cbe_tmp__3545;
  }

llvm_cbe_tmp__3544:
  *(&llvm_cbe_eqsize) = 2048u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3545:
  llvm_cbe_tmp__3509 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3510 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3509) > ((unsigned int )2048u)) & (((unsigned int )llvm_cbe_tmp__3510) <= ((unsigned int )4096u)))&1))) {
    goto llvm_cbe_tmp__3546;
  } else {
    goto llvm_cbe_tmp__3547;
  }

llvm_cbe_tmp__3546:
  *(&llvm_cbe_eqsize) = 4096u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3547:
  llvm_cbe_tmp__3511 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3512 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3511) > ((unsigned int )4096u)) & (((unsigned int )llvm_cbe_tmp__3512) <= ((unsigned int )8192u)))&1))) {
    goto llvm_cbe_tmp__3548;
  } else {
    goto llvm_cbe_tmp__3549;
  }

llvm_cbe_tmp__3548:
  *(&llvm_cbe_eqsize) = 8192u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3549:
  llvm_cbe_tmp__3513 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3514 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3513) > ((unsigned int )8192u)) & (((unsigned int )llvm_cbe_tmp__3514) <= ((unsigned int )16384u)))&1))) {
    goto llvm_cbe_tmp__3550;
  } else {
    goto llvm_cbe_tmp__3551;
  }

llvm_cbe_tmp__3550:
  *(&llvm_cbe_eqsize) = 16384u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3551:
  llvm_cbe_tmp__3515 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3516 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3515) > ((unsigned int )16384u)) & (((unsigned int )llvm_cbe_tmp__3516) <= ((unsigned int )32768u)))&1))) {
    goto llvm_cbe_tmp__3552;
  } else {
    goto llvm_cbe_tmp__3553;
  }

llvm_cbe_tmp__3552:
  *(&llvm_cbe_eqsize) = 32768u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3553:
  llvm_cbe_tmp__3517 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3518 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3517) > ((unsigned int )32768u)) & (((unsigned int )llvm_cbe_tmp__3518) <= ((unsigned int )65536u)))&1))) {
    goto llvm_cbe_tmp__3554;
  } else {
    goto llvm_cbe_tmp__3523;
  }

llvm_cbe_tmp__3554:
  *(&llvm_cbe_eqsize) = 65536u;
  goto llvm_cbe_tmp__3523;

llvm_cbe_tmp__3523:
  llvm_cbe_tmp__3519 = *(&llvm_cbe_eqsize);
  llvm_cbe_tmp__3520 = __CPROVER_malloc((((unsigned long long )(((unsigned long long )1ull) * ((unsigned long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3519)))))));
  *((&llvm_cbe_tmp__3486->field0)) = llvm_cbe_tmp__3520;
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3555;    /* Address-exposed local */
  unsigned int llvm_cbe_eqsize;    /* Address-exposed local */
  unsigned int llvm_cbe_acsize;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3556;
  unsigned int llvm_cbe_tmp__3557;
  unsigned int llvm_cbe_tmp__3558;
  unsigned int llvm_cbe_tmp__3559;
  unsigned int llvm_cbe_tmp__3560;
  unsigned int llvm_cbe_tmp__3561;
  unsigned int llvm_cbe_tmp__3562;
  unsigned int llvm_cbe_tmp__3563;
  unsigned int llvm_cbe_tmp__3564;
  unsigned int llvm_cbe_tmp__3565;
  unsigned int llvm_cbe_tmp__3566;
  unsigned int llvm_cbe_tmp__3567;
  unsigned int llvm_cbe_tmp__3568;
  unsigned int llvm_cbe_tmp__3569;
  unsigned int llvm_cbe_tmp__3570;
  unsigned int llvm_cbe_tmp__3571;
  unsigned int llvm_cbe_tmp__3572;
  unsigned int llvm_cbe_tmp__3573;
  unsigned int llvm_cbe_tmp__3574;
  unsigned int llvm_cbe_tmp__3575;
  unsigned int llvm_cbe_tmp__3576;
  unsigned int llvm_cbe_tmp__3577;
  unsigned int llvm_cbe_tmp__3578;
  unsigned int llvm_cbe_tmp__3579;
  unsigned int llvm_cbe_tmp__3580;
  unsigned int llvm_cbe_tmp__3581;
  unsigned int llvm_cbe_tmp__3582;
  unsigned int llvm_cbe_tmp__3583;
  unsigned int llvm_cbe_tmp__3584;
  unsigned int llvm_cbe_tmp__3585;
  unsigned int llvm_cbe_tmp__3586;
  unsigned int llvm_cbe_tmp__3587;
  unsigned int llvm_cbe_tmp__3588;
  unsigned int llvm_cbe_tmp__3589;
  unsigned char *llvm_cbe_tmp__3590;

  *(&llvm_cbe_tmp__3555) = llvm_cbe_this;
  llvm_cbe_tmp__3556 = *(&llvm_cbe_tmp__3555);
  *(&llvm_cbe_acsize) = 50601u;
  llvm_cbe_tmp__3557 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3557 == 1u)) {
    goto llvm_cbe_tmp__3591;
  } else {
    goto llvm_cbe_tmp__3592;
  }

llvm_cbe_tmp__3591:
  *(&llvm_cbe_eqsize) = 1u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3592:
  llvm_cbe_tmp__3558 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3558 == 2u)) {
    goto llvm_cbe_tmp__3594;
  } else {
    goto llvm_cbe_tmp__3595;
  }

llvm_cbe_tmp__3594:
  *(&llvm_cbe_eqsize) = 2u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3595:
  llvm_cbe_tmp__3559 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3560 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3559) > ((unsigned int )2u)) & (((unsigned int )llvm_cbe_tmp__3560) <= ((unsigned int )4u)))&1))) {
    goto llvm_cbe_tmp__3596;
  } else {
    goto llvm_cbe_tmp__3597;
  }

llvm_cbe_tmp__3596:
  *(&llvm_cbe_eqsize) = 4u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3597:
  llvm_cbe_tmp__3561 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3562 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3561) > ((unsigned int )4u)) & (((unsigned int )llvm_cbe_tmp__3562) <= ((unsigned int )8u)))&1))) {
    goto llvm_cbe_tmp__3598;
  } else {
    goto llvm_cbe_tmp__3599;
  }

llvm_cbe_tmp__3598:
  *(&llvm_cbe_eqsize) = 8u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3599:
  llvm_cbe_tmp__3563 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3564 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3563) > ((unsigned int )8u)) & (((unsigned int )llvm_cbe_tmp__3564) <= ((unsigned int )16u)))&1))) {
    goto llvm_cbe_tmp__3600;
  } else {
    goto llvm_cbe_tmp__3601;
  }

llvm_cbe_tmp__3600:
  *(&llvm_cbe_eqsize) = 16u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3601:
  llvm_cbe_tmp__3565 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3566 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3565) > ((unsigned int )16u)) & (((unsigned int )llvm_cbe_tmp__3566) <= ((unsigned int )32u)))&1))) {
    goto llvm_cbe_tmp__3602;
  } else {
    goto llvm_cbe_tmp__3603;
  }

llvm_cbe_tmp__3602:
  *(&llvm_cbe_eqsize) = 32u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3603:
  llvm_cbe_tmp__3567 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3568 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3567) > ((unsigned int )32u)) & (((unsigned int )llvm_cbe_tmp__3568) <= ((unsigned int )64u)))&1))) {
    goto llvm_cbe_tmp__3604;
  } else {
    goto llvm_cbe_tmp__3605;
  }

llvm_cbe_tmp__3604:
  *(&llvm_cbe_eqsize) = 64u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3605:
  llvm_cbe_tmp__3569 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3570 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3569) > ((unsigned int )64u)) & (((unsigned int )llvm_cbe_tmp__3570) <= ((unsigned int )128u)))&1))) {
    goto llvm_cbe_tmp__3606;
  } else {
    goto llvm_cbe_tmp__3607;
  }

llvm_cbe_tmp__3606:
  *(&llvm_cbe_eqsize) = 128u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3607:
  llvm_cbe_tmp__3571 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3572 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3571) > ((unsigned int )128u)) & (((unsigned int )llvm_cbe_tmp__3572) <= ((unsigned int )256u)))&1))) {
    goto llvm_cbe_tmp__3608;
  } else {
    goto llvm_cbe_tmp__3609;
  }

llvm_cbe_tmp__3608:
  *(&llvm_cbe_eqsize) = 256u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3609:
  llvm_cbe_tmp__3573 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3574 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3573) > ((unsigned int )256u)) & (((unsigned int )llvm_cbe_tmp__3574) <= ((unsigned int )512u)))&1))) {
    goto llvm_cbe_tmp__3610;
  } else {
    goto llvm_cbe_tmp__3611;
  }

llvm_cbe_tmp__3610:
  *(&llvm_cbe_eqsize) = 512u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3611:
  llvm_cbe_tmp__3575 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3576 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3575) > ((unsigned int )512u)) & (((unsigned int )llvm_cbe_tmp__3576) <= ((unsigned int )1024u)))&1))) {
    goto llvm_cbe_tmp__3612;
  } else {
    goto llvm_cbe_tmp__3613;
  }

llvm_cbe_tmp__3612:
  *(&llvm_cbe_eqsize) = 1024u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3613:
  llvm_cbe_tmp__3577 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3578 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3577) > ((unsigned int )1024u)) & (((unsigned int )llvm_cbe_tmp__3578) <= ((unsigned int )2048u)))&1))) {
    goto llvm_cbe_tmp__3614;
  } else {
    goto llvm_cbe_tmp__3615;
  }

llvm_cbe_tmp__3614:
  *(&llvm_cbe_eqsize) = 2048u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3615:
  llvm_cbe_tmp__3579 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3580 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3579) > ((unsigned int )2048u)) & (((unsigned int )llvm_cbe_tmp__3580) <= ((unsigned int )4096u)))&1))) {
    goto llvm_cbe_tmp__3616;
  } else {
    goto llvm_cbe_tmp__3617;
  }

llvm_cbe_tmp__3616:
  *(&llvm_cbe_eqsize) = 4096u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3617:
  llvm_cbe_tmp__3581 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3582 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3581) > ((unsigned int )4096u)) & (((unsigned int )llvm_cbe_tmp__3582) <= ((unsigned int )8192u)))&1))) {
    goto llvm_cbe_tmp__3618;
  } else {
    goto llvm_cbe_tmp__3619;
  }

llvm_cbe_tmp__3618:
  *(&llvm_cbe_eqsize) = 8192u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3619:
  llvm_cbe_tmp__3583 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3584 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3583) > ((unsigned int )8192u)) & (((unsigned int )llvm_cbe_tmp__3584) <= ((unsigned int )16384u)))&1))) {
    goto llvm_cbe_tmp__3620;
  } else {
    goto llvm_cbe_tmp__3621;
  }

llvm_cbe_tmp__3620:
  *(&llvm_cbe_eqsize) = 16384u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3621:
  llvm_cbe_tmp__3585 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3586 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3585) > ((unsigned int )16384u)) & (((unsigned int )llvm_cbe_tmp__3586) <= ((unsigned int )32768u)))&1))) {
    goto llvm_cbe_tmp__3622;
  } else {
    goto llvm_cbe_tmp__3623;
  }

llvm_cbe_tmp__3622:
  *(&llvm_cbe_eqsize) = 32768u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3623:
  llvm_cbe_tmp__3587 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3588 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3587) > ((unsigned int )32768u)) & (((unsigned int )llvm_cbe_tmp__3588) <= ((unsigned int )65536u)))&1))) {
    goto llvm_cbe_tmp__3624;
  } else {
    goto llvm_cbe_tmp__3593;
  }

llvm_cbe_tmp__3624:
  *(&llvm_cbe_eqsize) = 65536u;
  goto llvm_cbe_tmp__3593;

llvm_cbe_tmp__3593:
  llvm_cbe_tmp__3589 = *(&llvm_cbe_eqsize);
  llvm_cbe_tmp__3590 = __CPROVER_malloc((((unsigned long long )(((unsigned long long )4ull) * ((unsigned long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3589)))))));
  *((&llvm_cbe_tmp__3556->field0)) = (((float *)llvm_cbe_tmp__3590));
  return;
}


void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3625;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3626;
  unsigned char *llvm_cbe_tmp__3627;

  *(&llvm_cbe_tmp__3625) = llvm_cbe_this;
  llvm_cbe_tmp__3626 = *(&llvm_cbe_tmp__3625);
  llvm_cbe_tmp__3627 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3626->field0)) = llvm_cbe_tmp__3627;
  return;
}


void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3628;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3629;
  unsigned char *llvm_cbe_tmp__3630;

  *(&llvm_cbe_tmp__3628) = llvm_cbe_this;
  llvm_cbe_tmp__3629 = *(&llvm_cbe_tmp__3628);
  llvm_cbe_tmp__3630 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3629->field0)) = llvm_cbe_tmp__3630;
  return;
}


void _ZN13SysCArray2DstIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3631;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3632;
  unsigned char *llvm_cbe_tmp__3633;
  unsigned char *llvm_cbe_tmp__3634;

  *(&llvm_cbe_tmp__3631) = llvm_cbe_this;
  llvm_cbe_tmp__3632 = *(&llvm_cbe_tmp__3631);
  llvm_cbe_tmp__3633 = __CPROVER_malloc(1024ull);
  *((&llvm_cbe_tmp__3632->field0)) = llvm_cbe_tmp__3633;
  llvm_cbe_tmp__3634 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3632->field1)) = llvm_cbe_tmp__3634;
  return;
}


void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3635;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3636;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3637;

  *(&llvm_cbe_tmp__3635) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3636) = llvm_cbe_p;
  llvm_cbe_tmp__3637 = *(&llvm_cbe_tmp__3635);
  return;
}


void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3638;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3639;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3640;

  *(&llvm_cbe_tmp__3638) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3639) = llvm_cbe_p;
  llvm_cbe_tmp__3640 = *(&llvm_cbe_tmp__3638);
  return;
}


void _ZN11model_trainD2Ev(struct l_class_OC_model_train *llvm_cbe_this) {
  struct l_class_OC_model_train *llvm_cbe_tmp__3641;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3642;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3643;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__3644;

  *(&llvm_cbe_tmp__3641) = llvm_cbe_this;
  llvm_cbe_tmp__3644 = *(&llvm_cbe_tmp__3641);
  _ZN8type_memIbLj512EED1Ev(((&llvm_cbe_tmp__3644->field33)));
  _ZN8type_memItLj8EED1Ev(((&llvm_cbe_tmp__3644->field32)));
  _ZN8type_memIhLj128EED1Ev(((&llvm_cbe_tmp__3644->field19)));
  _ZN8type_memIjLj8EED1Ev(((&llvm_cbe_tmp__3644->field17)));
  _ZN8type_memIbLj65536EED1Ev(((&llvm_cbe_tmp__3644->field16)));
  _ZN8type_memIbLj128EED1Ev(((&llvm_cbe_tmp__3644->field4)));
  _ZN8type_memIhLj65536EED1Ev(((&llvm_cbe_tmp__3644->field3)));
  _ZN8type_memIhLj512EED1Ev(((&llvm_cbe_tmp__3644->field0)));
  return;
}


void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3645;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3646;

  *(&llvm_cbe_tmp__3645) = llvm_cbe_this;
  llvm_cbe_tmp__3646 = *(&llvm_cbe_tmp__3645);
  _ZN8type_memIhLj128EED2Ev(llvm_cbe_tmp__3646);
  return;
}


void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3647;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3648;

  *(&llvm_cbe_tmp__3647) = llvm_cbe_this;
  llvm_cbe_tmp__3648 = *(&llvm_cbe_tmp__3647);
  _ZN8type_memIhLj512EED2Ev(llvm_cbe_tmp__3648);
  return;
}


void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3649;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3650;

  *(&llvm_cbe_tmp__3649) = llvm_cbe_this;
  llvm_cbe_tmp__3650 = *(&llvm_cbe_tmp__3649);
  return;
}


void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3651;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3652;

  *(&llvm_cbe_tmp__3651) = llvm_cbe_this;
  llvm_cbe_tmp__3652 = *(&llvm_cbe_tmp__3651);
  return;
}


void _ZN11model_trainC2Ev(struct l_class_OC_model_train *llvm_cbe_this) {
  struct l_class_OC_model_train *llvm_cbe_tmp__3653;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3654;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3655;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__3656;
  unsigned long long llvm_cbe_tmp__3657;
  unsigned long long llvm_cbe_tmp__3658;

  *(&llvm_cbe_tmp__3653) = llvm_cbe_this;
  llvm_cbe_tmp__3656 = *(&llvm_cbe_tmp__3653);
  _ZN8type_memIhLj512EEC1El(((&llvm_cbe_tmp__3656->field0)), 0ull);
  _ZN8type_memIhLj65536EEC1El(((&llvm_cbe_tmp__3656->field3)), 0ull);
  _ZN8type_memIbLj128EEC1El(((&llvm_cbe_tmp__3656->field4)), 0ull);
  _ZN8type_memIbLj65536EEC1El(((&llvm_cbe_tmp__3656->field16)), 0ull);
  _ZN8type_memIjLj8EEC1El(((&llvm_cbe_tmp__3656->field17)), 0ull);
  _ZN8type_memIhLj128EEC1El(((&llvm_cbe_tmp__3656->field19)), 0ull);
  _ZN8type_memItLj8EEC1El(((&llvm_cbe_tmp__3656->field32)), 0ull);
  _ZN8type_memIbLj512EEC1El(((&llvm_cbe_tmp__3656->field33)), 0ull);
  *((&llvm_cbe_tmp__3656->field38)) = 1ull;
  *((&llvm_cbe_tmp__3656->field39)) = 65535ull;
  *((&llvm_cbe_tmp__3656->field40)) = 7ull;
  *((&llvm_cbe_tmp__3656->field41)) = 4294967295ull;
  *((&llvm_cbe_tmp__3656->field42)) = 18446744073709551615ull;
  *((&llvm_cbe_tmp__3656->field43)) = 127ull;
  *((&llvm_cbe_tmp__3656->field44)) = 255ull;
  *((&llvm_cbe_tmp__3656->field45)) = 511ull;
  *((&llvm_cbe_tmp__3656->field46)) = 32768ull;
  *((&llvm_cbe_tmp__3656->field47)) = 64ull;
  llvm_cbe_tmp__3657 = *((&llvm_cbe_tmp__3656->field39));
  *((&llvm_cbe_tmp__3656->field48)) = (llvm_cbe_tmp__3657 ^ 18446744073709551615ull);
  llvm_cbe_tmp__3658 = *((&llvm_cbe_tmp__3656->field43));
  *((&llvm_cbe_tmp__3656->field49)) = (llvm_cbe_tmp__3658 ^ 18446744073709551615ull);
  return;
}


void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3659;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3660;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3661;
  unsigned long long llvm_cbe_tmp__3662;

  *(&llvm_cbe_tmp__3659) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3660) = llvm_cbe_def;
  llvm_cbe_tmp__3661 = *(&llvm_cbe_tmp__3659);
  llvm_cbe_tmp__3662 = *(&llvm_cbe_tmp__3660);
  _ZN8type_memIhLj512EEC2El(llvm_cbe_tmp__3661, llvm_cbe_tmp__3662);
  return;
}


void _ZN8type_memIhLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3663;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3664;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3665;
  unsigned long long llvm_cbe_tmp__3666;

  *(&llvm_cbe_tmp__3663) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3664) = llvm_cbe_def;
  llvm_cbe_tmp__3665 = *(&llvm_cbe_tmp__3663);
  llvm_cbe_tmp__3666 = *(&llvm_cbe_tmp__3664);
  _ZN8type_memIhLj65536EEC2El(llvm_cbe_tmp__3665, llvm_cbe_tmp__3666);
  return;
}


void _ZN8type_memIbLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3667;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3668;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3669;
  unsigned long long llvm_cbe_tmp__3670;

  *(&llvm_cbe_tmp__3667) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3668) = llvm_cbe_def;
  llvm_cbe_tmp__3669 = *(&llvm_cbe_tmp__3667);
  llvm_cbe_tmp__3670 = *(&llvm_cbe_tmp__3668);
  _ZN8type_memIbLj128EEC2El(llvm_cbe_tmp__3669, llvm_cbe_tmp__3670);
  return;
}


void _ZN8type_memIbLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3671;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3672;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3673;
  unsigned long long llvm_cbe_tmp__3674;

  *(&llvm_cbe_tmp__3671) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3672) = llvm_cbe_def;
  llvm_cbe_tmp__3673 = *(&llvm_cbe_tmp__3671);
  llvm_cbe_tmp__3674 = *(&llvm_cbe_tmp__3672);
  _ZN8type_memIbLj65536EEC2El(llvm_cbe_tmp__3673, llvm_cbe_tmp__3674);
  return;
}


void _ZN8type_memIjLj8EEC1El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed1 *llvm_cbe_tmp__3675;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3676;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3677;
  unsigned long long llvm_cbe_tmp__3678;

  *(&llvm_cbe_tmp__3675) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3676) = llvm_cbe_def;
  llvm_cbe_tmp__3677 = *(&llvm_cbe_tmp__3675);
  llvm_cbe_tmp__3678 = *(&llvm_cbe_tmp__3676);
  _ZN8type_memIjLj8EEC2El(llvm_cbe_tmp__3677, llvm_cbe_tmp__3678);
  return;
}


void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3679;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3680;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3681;
  unsigned long long llvm_cbe_tmp__3682;

  *(&llvm_cbe_tmp__3679) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3680) = llvm_cbe_def;
  llvm_cbe_tmp__3681 = *(&llvm_cbe_tmp__3679);
  llvm_cbe_tmp__3682 = *(&llvm_cbe_tmp__3680);
  _ZN8type_memIhLj128EEC2El(llvm_cbe_tmp__3681, llvm_cbe_tmp__3682);
  return;
}


void _ZN8type_memItLj8EEC1El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed2 *llvm_cbe_tmp__3683;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3684;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3685;
  unsigned long long llvm_cbe_tmp__3686;

  *(&llvm_cbe_tmp__3683) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3684) = llvm_cbe_def;
  llvm_cbe_tmp__3685 = *(&llvm_cbe_tmp__3683);
  llvm_cbe_tmp__3686 = *(&llvm_cbe_tmp__3684);
  _ZN8type_memItLj8EEC2El(llvm_cbe_tmp__3685, llvm_cbe_tmp__3686);
  return;
}


void _ZN8type_memIbLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3687;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3688;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3689;
  unsigned long long llvm_cbe_tmp__3690;

  *(&llvm_cbe_tmp__3687) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3688) = llvm_cbe_def;
  llvm_cbe_tmp__3689 = *(&llvm_cbe_tmp__3687);
  llvm_cbe_tmp__3690 = *(&llvm_cbe_tmp__3688);
  _ZN8type_memIbLj512EEC2El(llvm_cbe_tmp__3689, llvm_cbe_tmp__3690);
  return;
}


void _ZN8type_memIbLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3691;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3692;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3693;
  unsigned char *llvm_cbe_tmp__3694;

  *(&llvm_cbe_tmp__3691) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3692) = llvm_cbe_def;
  llvm_cbe_tmp__3693 = *(&llvm_cbe_tmp__3691);
  llvm_cbe_tmp__3694 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3693->field0)) = llvm_cbe_tmp__3694;
  return;
}


void _ZN8type_memItLj8EEC2El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed2 *llvm_cbe_tmp__3695;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3696;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3697;
  unsigned char *llvm_cbe_tmp__3698;

  *(&llvm_cbe_tmp__3695) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3696) = llvm_cbe_def;
  llvm_cbe_tmp__3697 = *(&llvm_cbe_tmp__3695);
  llvm_cbe_tmp__3698 = __CPROVER_malloc(16ull);
  *((&llvm_cbe_tmp__3697->field0)) = (((unsigned short *)llvm_cbe_tmp__3698));
  return;
}


void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3699;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3700;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3701;
  unsigned char *llvm_cbe_tmp__3702;

  *(&llvm_cbe_tmp__3699) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3700) = llvm_cbe_def;
  llvm_cbe_tmp__3701 = *(&llvm_cbe_tmp__3699);
  llvm_cbe_tmp__3702 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3701->field0)) = llvm_cbe_tmp__3702;
  return;
}


void _ZN8type_memIjLj8EEC2El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed1 *llvm_cbe_tmp__3703;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3704;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3705;
  unsigned char *llvm_cbe_tmp__3706;

  *(&llvm_cbe_tmp__3703) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3704) = llvm_cbe_def;
  llvm_cbe_tmp__3705 = *(&llvm_cbe_tmp__3703);
  llvm_cbe_tmp__3706 = __CPROVER_malloc(32ull);
  *((&llvm_cbe_tmp__3705->field0)) = (((unsigned int *)llvm_cbe_tmp__3706));
  return;
}


void _ZN8type_memIbLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3707;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3708;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3709;
  unsigned char *llvm_cbe_tmp__3710;

  *(&llvm_cbe_tmp__3707) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3708) = llvm_cbe_def;
  llvm_cbe_tmp__3709 = *(&llvm_cbe_tmp__3707);
  llvm_cbe_tmp__3710 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3709->field0)) = llvm_cbe_tmp__3710;
  return;
}


void _ZN8type_memIbLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3711;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3712;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3713;
  unsigned char *llvm_cbe_tmp__3714;

  *(&llvm_cbe_tmp__3711) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3712) = llvm_cbe_def;
  llvm_cbe_tmp__3713 = *(&llvm_cbe_tmp__3711);
  llvm_cbe_tmp__3714 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3713->field0)) = llvm_cbe_tmp__3714;
  return;
}


void _ZN8type_memIhLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3715;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3716;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3717;
  unsigned char *llvm_cbe_tmp__3718;

  *(&llvm_cbe_tmp__3715) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3716) = llvm_cbe_def;
  llvm_cbe_tmp__3717 = *(&llvm_cbe_tmp__3715);
  llvm_cbe_tmp__3718 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3717->field0)) = llvm_cbe_tmp__3718;
  return;
}


void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3719;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3720;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3721;
  unsigned char *llvm_cbe_tmp__3722;

  *(&llvm_cbe_tmp__3719) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3720) = llvm_cbe_def;
  llvm_cbe_tmp__3721 = *(&llvm_cbe_tmp__3719);
  llvm_cbe_tmp__3722 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3721->field0)) = llvm_cbe_tmp__3722;
  return;
}


static void _GLOBAL__I_a(void) {
  __cxx_global_var_init();
  __cxx_global_var_init32();
  return;
}

