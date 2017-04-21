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

struct l_unnamed6 { unsigned int array[624]; };

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
  struct l_unnamed6 field29;
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

struct l_unnamed0 { unsigned char array[12]; };

struct l_unnamed10 { unsigned char array[15]; };

struct l_unnamed11 { unsigned char array[10]; };

struct l_unnamed12 { unsigned char array[23]; };

struct l_unnamed13 { unsigned char array[13]; };

struct l_unnamed14 { unsigned char array[21]; };

struct l_unnamed15 { unsigned char array[19]; };

struct l_unnamed16 { unsigned char array[8]; };

struct l_unnamed17 { unsigned char array[4]; };

struct l_unnamed18 { unsigned char array[9]; };

struct l_unnamed19 { unsigned char array[5]; };

struct l_unnamed3 {
  unsigned int field0;
  void  (*field1) (void);
};

struct l_unnamed20 { struct l_unnamed3 array[1]; };

struct l_unnamed21 { float array[5]; };

struct l_unnamed4 { unsigned char array[16]; };

struct l_unnamed5 { unsigned char array[11]; };

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
void __CPROVER_assert(bool , unsigned char *);
bool __CPROVER_array_equal(unsigned char *, unsigned char *);
void __CPROVER_array_copy(unsigned char *, unsigned char *);
void __CPROVER_assume(bool );
float *_ZN11SysCArray1DIfLj5EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_idx) __ATTRIBUTE_WEAK__;
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
static struct l_unnamed0 _OC_str;
static struct l_unnamed4 _OC_str1;
static struct l_unnamed5 _OC_str2;
static struct l_unnamed7 _OC_str3;
static struct l_unnamed8 _OC_str4;
static struct l_unnamed4 _OC_str5;
static struct l_unnamed4 _OC_str6;
static struct l_unnamed9 _OC_str7;
static struct l_unnamed7 _OC_str8;
static struct l_unnamed10 _OC_str9;
static struct l_unnamed4 _OC_str10;
static struct l_unnamed7 _OC_str11;
static struct l_unnamed7 _OC_str12;
static struct l_unnamed10 _OC_str13;
static struct l_unnamed4 _OC_str14;
static struct l_unnamed10 _OC_str15;
static struct l_unnamed11 _OC_str16;
static struct l_unnamed12 _OC_str17;
static struct l_unnamed4 _OC_str18;
static struct l_unnamed4 _OC_str19;
static struct l_unnamed4 _OC_str20;
static struct l_unnamed13 _OC_str21;
static struct l_unnamed10 _OC_str22;
static struct l_unnamed4 _OC_str23;
static struct l_unnamed8 _OC_str24;
static struct l_unnamed8 _OC_str25;
static struct l_unnamed5 _OC_str26;
static struct l_unnamed14 _OC_str27;
static struct l_unnamed8 _OC_str28;
static struct l_unnamed15 _OC_str29;
static struct l_unnamed11 _OC_str30;
static struct l_unnamed16 _OC_str31;
extern struct l_struct_OC_rbm IMPL;
static struct l_unnamed17 _OC_str33;
static struct l_unnamed17 _OC_str34;
static struct l_unnamed18 _OC_str35;
static struct l_unnamed11 _OC_str36;
static struct l_unnamed5 _OC_str37;
static struct l_unnamed18 _OC_str38;
static struct l_unnamed16 _OC_str39;
static struct l_unnamed18 _OC_str40;
static struct l_unnamed11 _OC_str41;
static struct l_unnamed5 _OC_str42;
static struct l_unnamed18 _OC_str43;
static struct l_unnamed18 _OC_str44;
static struct l_unnamed19 _OC_str45;
static struct l_unnamed11 _OC_str46;
static struct l_unnamed4 _OC_str47;
static struct l_unnamed7 _OC_str48;
static struct l_unnamed10 _OC_str49;
static struct l_unnamed10 _OC_str50;
static struct l_unnamed15 _OC_str51;
static struct l_unnamed4 _OC_str52;


/* Global Variable Definitions and Initialization */
unsigned short divide_p1;
unsigned short divide_p2;
unsigned short divide_r;
unsigned short rand_r;
unsigned short sigmoid_p1;
unsigned short sigmoid_r;
unsigned short to_int_exp_p1;
unsigned short to_int_exp_r;
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
static struct l_unnamed0 _OC_str = { "Config done" };
static struct l_unnamed4 _OC_str1 = { "init_done_match" };
static struct l_unnamed5 _OC_str2 = { "done_match" };
static struct l_unnamed7 _OC_str3 = { "num_hidden_match" };
static struct l_unnamed8 _OC_str4 = { "num_visible_match" };
static struct l_unnamed4 _OC_str5 = { "num_users_match" };
static struct l_unnamed4 _OC_str6 = { "num_loops_match" };
static struct l_unnamed9 _OC_str7 = { "num_testusers_match" };
static struct l_unnamed7 _OC_str8 = { "num_movies_match" };
static struct l_unnamed10 _OC_str9 = { "rd_index_match" };
static struct l_unnamed4 _OC_str10 = { "rd_length_match" };
static struct l_unnamed7 _OC_str11 = { "rd_request_match" };
static struct l_unnamed7 _OC_str12 = { "wr_request_match" };
static struct l_unnamed10 _OC_str13 = { "wr_index_match" };
static struct l_unnamed4 _OC_str14 = { "wr_length_match" };
static struct l_unnamed10 _OC_str15 = { "data_out_match" };
static struct l_unnamed11 _OC_str16 = { "upc_match" };
static struct l_unnamed12 _OC_str17 = { "train_input_done_match" };
static struct l_unnamed4 _OC_str18 = { "train_sum_match" };
static struct l_unnamed4 _OC_str19 = { "train_max_match" };
static struct l_unnamed4 _OC_str20 = { "sumOfpow2_match" };
static struct l_unnamed13 _OC_str21 = { "jstate_match" };
static struct l_unnamed10 _OC_str22 = { "per_v_pc_match" };
static struct l_unnamed4 _OC_str23 = { "train_upc_match" };
static struct l_unnamed8 _OC_str24 = { "train_v_cnt_match" };
static struct l_unnamed8 _OC_str25 = { "train_h_cnt_match" };
static struct l_unnamed5 _OC_str26 = { "data_match" };
static struct l_unnamed14 _OC_str27 = { "predict_result_match" };
static struct l_unnamed8 _OC_str28 = { "hidden_unit_match" };
static struct l_unnamed15 _OC_str29 = { "visible_unit_match" };
static struct l_unnamed11 _OC_str30 = { "pos_match" };
static struct l_unnamed16 _OC_str31 = { "ind-inv" };
struct l_struct_OC_rbm IMPL;
static struct l_unnamed17 _OC_str33 = { "clk" };
static struct l_unnamed17 _OC_str34 = { "rst" };
static struct l_unnamed18 _OC_str35 = { "rd_index" };
static struct l_unnamed11 _OC_str36 = { "rd_length" };
static struct l_unnamed5 _OC_str37 = { "rd_request" };
static struct l_unnamed18 _OC_str38 = { "rd_grant" };
static struct l_unnamed16 _OC_str39 = { "data_in" };
static struct l_unnamed18 _OC_str40 = { "wr_index" };
static struct l_unnamed11 _OC_str41 = { "wr_length" };
static struct l_unnamed5 _OC_str42 = { "wr_request" };
static struct l_unnamed18 _OC_str43 = { "wr_grant" };
static struct l_unnamed18 _OC_str44 = { "data_out" };
static struct l_unnamed19 _OC_str45 = { "done" };
static struct l_unnamed11 _OC_str46 = { "cond_done" };
static struct l_unnamed4 _OC_str47 = { "conf_num_hidden" };
static struct l_unnamed7 _OC_str48 = { "conf_num_visible" };
static struct l_unnamed10 _OC_str49 = { "conf_num_users" };
static struct l_unnamed10 _OC_str50 = { "conf_num_loops" };
static struct l_unnamed15 _OC_str51 = { "conf_num_testusers" };
static struct l_unnamed4 _OC_str52 = { "conf_num_movies" };


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
  unsigned long long llvm_cbe_tmp__8;
  unsigned long long llvm_cbe_tmp__9;
  unsigned long long llvm_cbe_tmp__10;
  unsigned long long llvm_cbe_tmp__11;

  *(&llvm_cbe_tmp__1) = llvm_cbe_cppVar_480;
  *(&llvm_cbe_tmp__2) = llvm_cbe_cppVar_481;
  llvm_cbe_tmp__3 = *(&llvm_cbe_tmp__1);
  llvm_cbe_tmp__4 = *(&divide_p1);
  if ((llvm_cbe_tmp__3 == (((unsigned long long )(unsigned short )llvm_cbe_tmp__4)))) {
    goto llvm_cbe_tmp__12;
  } else {
    goto llvm_cbe_tmp__13;
  }

llvm_cbe_tmp__12:
  llvm_cbe_tmp__5 = *(&llvm_cbe_tmp__2);
  llvm_cbe_tmp__6 = *(&divide_p2);
  if ((llvm_cbe_tmp__5 == (((unsigned long long )(unsigned short )llvm_cbe_tmp__6)))) {
    goto llvm_cbe_tmp__14;
  } else {
    goto llvm_cbe_tmp__13;
  }

llvm_cbe_tmp__14:
  llvm_cbe_tmp__7 = *(&divide_r);
  *(&llvm_cbe_ret) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__7));
  goto llvm_cbe_tmp__13;

llvm_cbe_tmp__13:
  llvm_cbe_tmp__8 = *(&llvm_cbe_tmp__1);
  *(&divide_p1) = (((unsigned short )llvm_cbe_tmp__8));
  llvm_cbe_tmp__9 = *(&llvm_cbe_tmp__2);
  *(&divide_p2) = (((unsigned short )llvm_cbe_tmp__9));
  llvm_cbe_tmp__10 = *(&llvm_cbe_ret);
  *(&divide_r) = (((unsigned short )llvm_cbe_tmp__10));
  llvm_cbe_tmp__11 = *(&llvm_cbe_ret);
  return (((unsigned short )llvm_cbe_tmp__11));
}


unsigned short _Z4randv(void) {
  unsigned short llvm_cbe_tmp__15;

  llvm_cbe_tmp__15 = *(&rand_r);
  return llvm_cbe_tmp__15;
}


unsigned short _Z7sigmoidl(unsigned long long llvm_cbe_cppVar_486) {
  unsigned long long llvm_cbe_tmp__16;    /* Address-exposed local */
  unsigned long long llvm_cbe_ret;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__17;
  unsigned long long llvm_cbe_tmp__18;
  unsigned short llvm_cbe_tmp__19;
  unsigned long long llvm_cbe_tmp__20;
  unsigned long long llvm_cbe_tmp__21;
  unsigned long long llvm_cbe_tmp__22;

  *(&llvm_cbe_tmp__16) = llvm_cbe_cppVar_486;
  llvm_cbe_tmp__17 = *(&sigmoid_p1);
  llvm_cbe_tmp__18 = *(&llvm_cbe_tmp__16);
  if (((((unsigned long long )(unsigned short )llvm_cbe_tmp__17)) == llvm_cbe_tmp__18)) {
    goto llvm_cbe_tmp__23;
  } else {
    goto llvm_cbe_tmp__24;
  }

llvm_cbe_tmp__23:
  llvm_cbe_tmp__19 = *(&sigmoid_r);
  *(&llvm_cbe_ret) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__19));
  goto llvm_cbe_tmp__24;

llvm_cbe_tmp__24:
  llvm_cbe_tmp__20 = *(&llvm_cbe_ret);
  *(&sigmoid_r) = (((unsigned short )llvm_cbe_tmp__20));
  llvm_cbe_tmp__21 = *(&llvm_cbe_tmp__16);
  *(&sigmoid_p1) = (((unsigned short )llvm_cbe_tmp__21));
  llvm_cbe_tmp__22 = *(&llvm_cbe_ret);
  return (((unsigned short )llvm_cbe_tmp__22));
}


unsigned short _Z10to_int_expl(unsigned long long llvm_cbe_cppVar_489) {
  unsigned long long llvm_cbe_tmp__25;    /* Address-exposed local */
  unsigned long long llvm_cbe_ret;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__26;
  unsigned long long llvm_cbe_tmp__27;
  unsigned short llvm_cbe_tmp__28;
  unsigned long long llvm_cbe_tmp__29;
  unsigned long long llvm_cbe_tmp__30;
  unsigned long long llvm_cbe_tmp__31;

  *(&llvm_cbe_tmp__25) = llvm_cbe_cppVar_489;
  llvm_cbe_tmp__26 = *(&to_int_exp_p1);
  llvm_cbe_tmp__27 = *(&llvm_cbe_tmp__25);
  if (((((unsigned long long )(unsigned short )llvm_cbe_tmp__26)) == llvm_cbe_tmp__27)) {
    goto llvm_cbe_tmp__32;
  } else {
    goto llvm_cbe_tmp__33;
  }

llvm_cbe_tmp__32:
  llvm_cbe_tmp__28 = *(&sigmoid_r);
  *(&llvm_cbe_ret) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__28));
  goto llvm_cbe_tmp__33;

llvm_cbe_tmp__33:
  llvm_cbe_tmp__29 = *(&llvm_cbe_ret);
  *(&to_int_exp_r) = (((unsigned short )llvm_cbe_tmp__29));
  llvm_cbe_tmp__30 = *(&llvm_cbe_tmp__25);
  *(&to_int_exp_p1) = (((unsigned short )llvm_cbe_tmp__30));
  llvm_cbe_tmp__31 = *(&llvm_cbe_ret);
  return (((unsigned short )llvm_cbe_tmp__31));
}


bool _ZN11model_train9assumps_0Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__34;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__35;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__36;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__37;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__38;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__39;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__40;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__41;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__42;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__43;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__44;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__45;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1196;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_1197;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__46;
  unsigned long long llvm_cbe_tmp__47;
  unsigned char llvm_cbe_tmp__48;

  *(&llvm_cbe_tmp__34) = llvm_cbe_this;
  *(&llvm_cbe_tmp__35) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__36) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__37) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__38) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__39) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__40) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__41) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__42) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__43) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__44) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__45) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__46 = *(&llvm_cbe_tmp__34);
  llvm_cbe_tmp__47 = *((&llvm_cbe_tmp__46->field26));
  *(&llvm_cbe_cppVar_1197) = (((unsigned char )(bool )(llvm_cbe_tmp__47 == 1ull)));
  llvm_cbe_tmp__48 = *(&llvm_cbe_cppVar_1197);
  return (((((bool )llvm_cbe_tmp__48&1u))&1));
}


struct l_class_OC_SysCArray1D _ZN11model_train18cppUpdateFun_edgesElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__49;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__50;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__51;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__52;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__53;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__54;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__55;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__56;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__57;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__58;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__59;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__60;    /* Address-exposed local */
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
  unsigned char *llvm_cbe_tmp__61;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__62;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_951;    /* Address-exposed local */
  bool llvm_cbe_tmp__63;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__64;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__65;
  unsigned long long llvm_cbe_tmp__66;
  unsigned char llvm_cbe_tmp__67;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__68;
  unsigned long long llvm_cbe_tmp__69;
  unsigned char llvm_cbe_tmp__70;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__71;
  unsigned long long llvm_cbe_tmp__72;
  unsigned char llvm_cbe_tmp__73;
  unsigned long long llvm_cbe_tmp__74;
  unsigned long long llvm_cbe_tmp__75;
  unsigned long long llvm_cbe_tmp__76;
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
  unsigned char llvm_cbe_tmp__101;
  unsigned char llvm_cbe_tmp__102;
  bool llvm_cbe_tmp__103;
  bool llvm_cbe_tmp__104;
  bool llvm_cbe_tmp__104__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__105;
  unsigned char llvm_cbe_tmp__106;
  unsigned char llvm_cbe_tmp__107;
  bool llvm_cbe_tmp__108;
  bool llvm_cbe_tmp__109;
  bool llvm_cbe_tmp__109__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__110;
  unsigned long long llvm_cbe_tmp__111;
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
  unsigned long long llvm_cbe_tmp__123;
  unsigned char llvm_cbe_tmp__124;
  unsigned char llvm_cbe_tmp__125;
  unsigned char llvm_cbe_tmp__126;
  bool llvm_cbe_tmp__127;
  bool llvm_cbe_tmp__128;
  bool llvm_cbe_tmp__128__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__129;
  unsigned long long llvm_cbe_tmp__130;
  unsigned long long llvm_cbe_tmp__131;
  unsigned long long llvm_cbe_tmp__132;
  unsigned long long llvm_cbe_tmp__133;
  unsigned long long llvm_cbe_tmp__134;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__135;
  unsigned long long llvm_cbe_tmp__136;
  unsigned long long llvm_cbe_tmp__137;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__138;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__139;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__140;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__141;
  bool llvm_cbe_tmp__142;

  *(&llvm_cbe_tmp__49) = llvm_cbe_this;
  *(&llvm_cbe_tmp__50) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__51) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__52) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__53) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__54) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__55) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__56) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__57) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__58) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__59) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__60) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__65 = *(&llvm_cbe_tmp__49);
  _ZN8type_memIhLj65536EEC1Ev((&llvm_cbe_cppVar_989));
  _ZN8type_memIhLj65536EEC1Ev((&llvm_cbe_cppVar_954));
  _ZN8type_memIhLj65536EEC1Ev((&llvm_cbe_cppVar_951));
  *(&llvm_cbe_tmp__63) = ((0) & 1);
  _ZN8type_memIhLj65536EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__66 = *((&llvm_cbe_tmp__65->field29));
  *(&llvm_cbe_cppVar_950) = (((unsigned char )(bool )(llvm_cbe_tmp__66 == 0ull)));
  llvm_cbe_tmp__67 = *(&llvm_cbe_cppVar_950);
  if ((((((bool )llvm_cbe_tmp__67&1u))&1))) {
    goto llvm_cbe_tmp__143;
  } else {
    goto llvm_cbe_tmp__144;
  }

llvm_cbe_tmp__143:
  llvm_cbe_tmp__68 = _ZN8type_memIhLj65536EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__65->field3)));
  goto llvm_cbe_tmp__145;

llvm_cbe_tmp__144:
  llvm_cbe_tmp__69 = *((&llvm_cbe_tmp__65->field29));
  *(&llvm_cbe_cppVar_953) = (((unsigned char )(bool )(llvm_cbe_tmp__69 == 1ull)));
  llvm_cbe_tmp__70 = *(&llvm_cbe_cppVar_953);
  if ((((((bool )llvm_cbe_tmp__70&1u))&1))) {
    goto llvm_cbe_tmp__146;
  } else {
    goto llvm_cbe_tmp__147;
  }

llvm_cbe_tmp__146:
  llvm_cbe_tmp__71 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_951), ((&llvm_cbe_tmp__65->field3)));
  goto llvm_cbe_tmp__148;

llvm_cbe_tmp__147:
  llvm_cbe_tmp__72 = *((&llvm_cbe_tmp__65->field29));
  *(&llvm_cbe_cppVar_956) = (((unsigned char )(bool )(llvm_cbe_tmp__72 == 2ull)));
  llvm_cbe_tmp__73 = *(&llvm_cbe_cppVar_956);
  if ((((((bool )llvm_cbe_tmp__73&1u))&1))) {
    goto llvm_cbe_tmp__149;
  } else {
    goto llvm_cbe_tmp__150;
  }

llvm_cbe_tmp__149:
  llvm_cbe_tmp__74 = *((&llvm_cbe_tmp__65->field30));
  *(&llvm_cbe_cppVar_958) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__74))));
  llvm_cbe_tmp__75 = *(&llvm_cbe_cppVar_958);
  llvm_cbe_tmp__76 = *((&llvm_cbe_tmp__65->field39));
  *(&llvm_cbe_cppVar_958) = (llvm_cbe_tmp__75 & llvm_cbe_tmp__76);
  llvm_cbe_tmp__77 = *(&llvm_cbe_cppVar_958);
  llvm_cbe_tmp__78 = *((&llvm_cbe_tmp__65->field25));
  *(&llvm_cbe_cppVar_959) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__77) + ((unsigned long long )llvm_cbe_tmp__78))));
  llvm_cbe_tmp__79 = *(&llvm_cbe_cppVar_959);
  llvm_cbe_tmp__80 = *((&llvm_cbe_tmp__65->field39));
  *(&llvm_cbe_cppVar_959) = (llvm_cbe_tmp__79 & llvm_cbe_tmp__80);
  llvm_cbe_tmp__81 = *((&llvm_cbe_tmp__65->field30));
  *(&llvm_cbe_cppVar_962) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__81))));
  llvm_cbe_tmp__82 = *(&llvm_cbe_cppVar_962);
  llvm_cbe_tmp__83 = *((&llvm_cbe_tmp__65->field39));
  *(&llvm_cbe_cppVar_962) = (llvm_cbe_tmp__82 & llvm_cbe_tmp__83);
  llvm_cbe_tmp__84 = *(&llvm_cbe_cppVar_962);
  llvm_cbe_tmp__85 = *((&llvm_cbe_tmp__65->field25));
  *(&llvm_cbe_cppVar_963) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__84) + ((unsigned long long )llvm_cbe_tmp__85))));
  llvm_cbe_tmp__86 = *(&llvm_cbe_cppVar_963);
  llvm_cbe_tmp__87 = *((&llvm_cbe_tmp__65->field39));
  *(&llvm_cbe_cppVar_963) = (llvm_cbe_tmp__86 & llvm_cbe_tmp__87);
  llvm_cbe_tmp__88 = *(&llvm_cbe_cppVar_963);
  llvm_cbe_tmp__89 = _ZN8type_memIbLj65536EE2rdEl(((&llvm_cbe_tmp__65->field16)), llvm_cbe_tmp__88);
  *(&llvm_cbe_cppVar_964) = llvm_cbe_tmp__89;
  llvm_cbe_tmp__90 = *(&llvm_cbe_cppVar_964);
  *(&llvm_cbe_cppVar_966) = (((unsigned char )(bool )(llvm_cbe_tmp__90 != 0ull)));
  llvm_cbe_tmp__91 = *((&llvm_cbe_tmp__65->field25));
  llvm_cbe_tmp__92 = *((&llvm_cbe_tmp__65->field43));
  *(&llvm_cbe_cppVar_967) = ((((signed long long )(((signed long long )llvm_cbe_tmp__91) >> ((signed long long )0ull)))) & llvm_cbe_tmp__92);
  llvm_cbe_tmp__93 = *(&llvm_cbe_cppVar_967);
  llvm_cbe_tmp__94 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__65->field4)), llvm_cbe_tmp__93);
  *(&llvm_cbe_cppVar_968) = llvm_cbe_tmp__94;
  llvm_cbe_tmp__95 = *(&llvm_cbe_cppVar_968);
  *(&llvm_cbe_cppVar_970) = (((unsigned char )(bool )(llvm_cbe_tmp__95 != 0ull)));
  llvm_cbe_tmp__96 = *((&llvm_cbe_tmp__65->field30));
  llvm_cbe_tmp__97 = *((&llvm_cbe_tmp__65->field45));
  *(&llvm_cbe_cppVar_971) = ((((signed long long )(((signed long long )llvm_cbe_tmp__96) >> ((signed long long )0ull)))) & llvm_cbe_tmp__97);
  llvm_cbe_tmp__98 = *(&llvm_cbe_cppVar_971);
  llvm_cbe_tmp__99 = _ZN8type_memIbLj512EE2rdEl(((&llvm_cbe_tmp__65->field33)), llvm_cbe_tmp__98);
  *(&llvm_cbe_cppVar_972) = llvm_cbe_tmp__99;
  llvm_cbe_tmp__100 = *(&llvm_cbe_cppVar_972);
  *(&llvm_cbe_cppVar_974) = (((unsigned char )(bool )(llvm_cbe_tmp__100 != 0ull)));
  llvm_cbe_tmp__101 = *(&llvm_cbe_cppVar_970);
  if ((((((bool )llvm_cbe_tmp__101&1u))&1))) {
    goto llvm_cbe_tmp__151;
  } else {
    llvm_cbe_tmp__104__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__152;
  }

llvm_cbe_tmp__151:
  llvm_cbe_tmp__102 = *(&llvm_cbe_cppVar_974);
  llvm_cbe_tmp__103 = ((((bool )llvm_cbe_tmp__102&1u))&1);
  llvm_cbe_tmp__104__PHI_TEMPORARY = llvm_cbe_tmp__103;   /* for PHI node */
  goto llvm_cbe_tmp__152;

llvm_cbe_tmp__152:
  llvm_cbe_tmp__104 = ((llvm_cbe_tmp__104__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_975) = (((unsigned char )(bool )llvm_cbe_tmp__104));
  llvm_cbe_tmp__105 = *(&llvm_cbe_cppVar_975);
  *(&llvm_cbe_cppVar_976) = (((unsigned char )(bool )((((((((bool )llvm_cbe_tmp__105&1u))&1)) ^ 1)&1))));
  llvm_cbe_tmp__106 = *(&llvm_cbe_cppVar_966);
  if ((((((bool )llvm_cbe_tmp__106&1u))&1))) {
    goto llvm_cbe_tmp__153;
  } else {
    llvm_cbe_tmp__109__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__154;
  }

llvm_cbe_tmp__153:
  llvm_cbe_tmp__107 = *(&llvm_cbe_cppVar_976);
  llvm_cbe_tmp__108 = ((((bool )llvm_cbe_tmp__107&1u))&1);
  llvm_cbe_tmp__109__PHI_TEMPORARY = llvm_cbe_tmp__108;   /* for PHI node */
  goto llvm_cbe_tmp__154;

llvm_cbe_tmp__154:
  llvm_cbe_tmp__109 = ((llvm_cbe_tmp__109__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_977) = (((unsigned char )(bool )llvm_cbe_tmp__109));
  llvm_cbe_tmp__110 = *(&llvm_cbe_cppVar_977);
  if ((((((bool )llvm_cbe_tmp__110&1u))&1))) {
    goto llvm_cbe_tmp__155;
  } else {
    goto llvm_cbe_tmp__156;
  }

llvm_cbe_tmp__155:
  llvm_cbe_tmp__111 = *((&llvm_cbe_tmp__65->field30));
  *(&llvm_cbe_cppVar_979) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__111))));
  llvm_cbe_tmp__112 = *(&llvm_cbe_cppVar_979);
  llvm_cbe_tmp__113 = *((&llvm_cbe_tmp__65->field39));
  *(&llvm_cbe_cppVar_979) = (llvm_cbe_tmp__112 & llvm_cbe_tmp__113);
  llvm_cbe_tmp__114 = *(&llvm_cbe_cppVar_979);
  llvm_cbe_tmp__115 = *((&llvm_cbe_tmp__65->field25));
  *(&llvm_cbe_cppVar_980) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__114) + ((unsigned long long )llvm_cbe_tmp__115))));
  llvm_cbe_tmp__116 = *(&llvm_cbe_cppVar_980);
  llvm_cbe_tmp__117 = *((&llvm_cbe_tmp__65->field39));
  *(&llvm_cbe_cppVar_980) = (llvm_cbe_tmp__116 & llvm_cbe_tmp__117);
  llvm_cbe_tmp__118 = *(&llvm_cbe_cppVar_980);
  llvm_cbe_tmp__119 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__65->field3)), llvm_cbe_tmp__118);
  *(&llvm_cbe_cppVar_981) = llvm_cbe_tmp__119;
  llvm_cbe_tmp__120 = *(&llvm_cbe_cppVar_981);
  *(&llvm_cbe_cppVar_983) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__120) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__121 = *(&llvm_cbe_cppVar_983);
  llvm_cbe_tmp__122 = *((&llvm_cbe_tmp__65->field44));
  *(&llvm_cbe_cppVar_983) = (llvm_cbe_tmp__121 & llvm_cbe_tmp__122);
  llvm_cbe_tmp__123 = *(&llvm_cbe_cppVar_983);
  *(&llvm_cbe_cppVar_960) = llvm_cbe_tmp__123;
  goto llvm_cbe_tmp__157;

llvm_cbe_tmp__156:
  llvm_cbe_tmp__124 = *(&llvm_cbe_cppVar_966);
  *(&llvm_cbe_cppVar_985) = (((unsigned char )(bool )((((((((bool )llvm_cbe_tmp__124&1u))&1)) ^ 1)&1))));
  llvm_cbe_tmp__125 = *(&llvm_cbe_cppVar_985);
  if ((((((bool )llvm_cbe_tmp__125&1u))&1))) {
    goto llvm_cbe_tmp__158;
  } else {
    llvm_cbe_tmp__128__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__159;
  }

llvm_cbe_tmp__158:
  llvm_cbe_tmp__126 = *(&llvm_cbe_cppVar_975);
  llvm_cbe_tmp__127 = ((((bool )llvm_cbe_tmp__126&1u))&1);
  llvm_cbe_tmp__128__PHI_TEMPORARY = llvm_cbe_tmp__127;   /* for PHI node */
  goto llvm_cbe_tmp__159;

llvm_cbe_tmp__159:
  llvm_cbe_tmp__128 = ((llvm_cbe_tmp__128__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_986) = (((unsigned char )(bool )llvm_cbe_tmp__128));
  llvm_cbe_tmp__129 = *(&llvm_cbe_cppVar_986);
  llvm_cbe_tmp__130 = *(&llvm_cbe_cppVar_981);
  if ((((((bool )llvm_cbe_tmp__129&1u))&1))) {
    goto llvm_cbe_tmp__160;
  } else {
    goto llvm_cbe_tmp__161;
  }

llvm_cbe_tmp__160:
  *(&llvm_cbe_cppVar_988) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__130) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__131 = *(&llvm_cbe_cppVar_988);
  llvm_cbe_tmp__132 = *((&llvm_cbe_tmp__65->field44));
  *(&llvm_cbe_cppVar_988) = (llvm_cbe_tmp__131 & llvm_cbe_tmp__132);
  llvm_cbe_tmp__133 = *(&llvm_cbe_cppVar_988);
  *(&llvm_cbe_cppVar_984) = llvm_cbe_tmp__133;
  goto llvm_cbe_tmp__162;

llvm_cbe_tmp__161:
  *(&llvm_cbe_cppVar_984) = llvm_cbe_tmp__130;
  goto llvm_cbe_tmp__162;

llvm_cbe_tmp__162:
  llvm_cbe_tmp__134 = *(&llvm_cbe_cppVar_984);
  *(&llvm_cbe_cppVar_960) = llvm_cbe_tmp__134;
  goto llvm_cbe_tmp__157;

llvm_cbe_tmp__157:
  llvm_cbe_tmp__135 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_989), ((&llvm_cbe_tmp__65->field3)));
  llvm_cbe_tmp__136 = *(&llvm_cbe_cppVar_959);
  llvm_cbe_tmp__137 = *(&llvm_cbe_cppVar_960);
  _ZN8type_memIhLj65536EE2wrEll((&llvm_cbe_cppVar_989), llvm_cbe_tmp__136, llvm_cbe_tmp__137);
  llvm_cbe_tmp__138 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_954), (&llvm_cbe_cppVar_989));
  goto llvm_cbe_tmp__163;

llvm_cbe_tmp__150:
  llvm_cbe_tmp__139 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_954), ((&llvm_cbe_tmp__65->field3)));
  goto llvm_cbe_tmp__163;

llvm_cbe_tmp__163:
  llvm_cbe_tmp__140 = _ZN8type_memIhLj65536EEaSERKS0_((&llvm_cbe_cppVar_951), (&llvm_cbe_cppVar_954));
  goto llvm_cbe_tmp__148;

llvm_cbe_tmp__148:
  llvm_cbe_tmp__141 = _ZN8type_memIhLj65536EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_951));
  goto llvm_cbe_tmp__145;

llvm_cbe_tmp__145:
  *(&llvm_cbe_tmp__63) = ((1) & 1);
  *(&llvm_cbe_tmp__64) = 1u;
  llvm_cbe_tmp__142 = ((*(&llvm_cbe_tmp__63))&1);
  if (llvm_cbe_tmp__142) {
    goto llvm_cbe_tmp__164;
  } else {
    goto llvm_cbe_tmp__165;
  }

llvm_cbe_tmp__165:
  _ZN8type_memIhLj65536EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__164;

llvm_cbe_tmp__164:
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_951));
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_954));
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_989));
  return StructReturn;
}


void _ZN8type_memIhLj65536EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__166;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__167;

  *(&llvm_cbe_tmp__166) = llvm_cbe_this;
  llvm_cbe_tmp__167 = *(&llvm_cbe_tmp__166);
  _ZN8type_memIhLj65536EEC2Ev(llvm_cbe_tmp__167);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIhLj65536EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__168;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__169;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__170;
  unsigned char *llvm_cbe_tmp__171;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__172;
  unsigned char *llvm_cbe_tmp__173;

  *(&llvm_cbe_tmp__168) = llvm_cbe_this;
  *(&llvm_cbe_tmp__169) = llvm_cbe_r;
  llvm_cbe_tmp__170 = *(&llvm_cbe_tmp__168);
  llvm_cbe_tmp__171 = *((&llvm_cbe_tmp__170->field0));
  llvm_cbe_tmp__172 = *(&llvm_cbe_tmp__169);
  llvm_cbe_tmp__173 = *((&llvm_cbe_tmp__172->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__171, llvm_cbe_tmp__173);
  return llvm_cbe_tmp__170;
}


unsigned long long _ZN8type_memIbLj65536EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__174;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__175;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__176;
  unsigned long long llvm_cbe_tmp__177;
  unsigned char *llvm_cbe_tmp__178;
  unsigned char llvm_cbe_tmp__179;

  *(&llvm_cbe_tmp__174) = llvm_cbe_this;
  *(&llvm_cbe_tmp__175) = llvm_cbe_addr;
  llvm_cbe_tmp__176 = *(&llvm_cbe_tmp__174);
  llvm_cbe_tmp__177 = *(&llvm_cbe_tmp__175);
  llvm_cbe_tmp__178 = *((&llvm_cbe_tmp__176->field0));
  llvm_cbe_tmp__179 = *((&llvm_cbe_tmp__178[((signed long long )llvm_cbe_tmp__177)]));
  return (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__179&1u))&1))));
}


unsigned long long _ZN8type_memIbLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__180;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__181;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__182;
  unsigned long long llvm_cbe_tmp__183;
  unsigned char *llvm_cbe_tmp__184;
  unsigned char llvm_cbe_tmp__185;

  *(&llvm_cbe_tmp__180) = llvm_cbe_this;
  *(&llvm_cbe_tmp__181) = llvm_cbe_addr;
  llvm_cbe_tmp__182 = *(&llvm_cbe_tmp__180);
  llvm_cbe_tmp__183 = *(&llvm_cbe_tmp__181);
  llvm_cbe_tmp__184 = *((&llvm_cbe_tmp__182->field0));
  llvm_cbe_tmp__185 = *((&llvm_cbe_tmp__184[((signed long long )llvm_cbe_tmp__183)]));
  return (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__185&1u))&1))));
}


unsigned long long _ZN8type_memIbLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__186;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__187;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__188;
  unsigned long long llvm_cbe_tmp__189;
  unsigned char *llvm_cbe_tmp__190;
  unsigned char llvm_cbe_tmp__191;

  *(&llvm_cbe_tmp__186) = llvm_cbe_this;
  *(&llvm_cbe_tmp__187) = llvm_cbe_addr;
  llvm_cbe_tmp__188 = *(&llvm_cbe_tmp__186);
  llvm_cbe_tmp__189 = *(&llvm_cbe_tmp__187);
  llvm_cbe_tmp__190 = *((&llvm_cbe_tmp__188->field0));
  llvm_cbe_tmp__191 = *((&llvm_cbe_tmp__190[((signed long long )llvm_cbe_tmp__189)]));
  return (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__191&1u))&1))));
}


unsigned long long _ZN8type_memIhLj65536EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__192;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__193;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__194;
  unsigned long long llvm_cbe_tmp__195;
  unsigned char *llvm_cbe_tmp__196;
  unsigned char llvm_cbe_tmp__197;

  *(&llvm_cbe_tmp__192) = llvm_cbe_this;
  *(&llvm_cbe_tmp__193) = llvm_cbe_addr;
  llvm_cbe_tmp__194 = *(&llvm_cbe_tmp__192);
  llvm_cbe_tmp__195 = *(&llvm_cbe_tmp__193);
  llvm_cbe_tmp__196 = *((&llvm_cbe_tmp__194->field0));
  llvm_cbe_tmp__197 = *((&llvm_cbe_tmp__196[((signed long long )llvm_cbe_tmp__195)]));
  return (((unsigned long long )(unsigned char )llvm_cbe_tmp__197));
}


void _ZN8type_memIhLj65536EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__198;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__199;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__200;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__201;
  unsigned long long llvm_cbe_tmp__202;
  unsigned long long llvm_cbe_tmp__203;
  unsigned char *llvm_cbe_tmp__204;

  *(&llvm_cbe_tmp__198) = llvm_cbe_this;
  *(&llvm_cbe_tmp__199) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__200) = llvm_cbe_data;
  llvm_cbe_tmp__201 = *(&llvm_cbe_tmp__198);
  llvm_cbe_tmp__202 = *(&llvm_cbe_tmp__200);
  llvm_cbe_tmp__203 = *(&llvm_cbe_tmp__199);
  llvm_cbe_tmp__204 = *((&llvm_cbe_tmp__201->field0));
  *((&llvm_cbe_tmp__204[((signed long long )llvm_cbe_tmp__203)])) = (((unsigned char )llvm_cbe_tmp__202));
  return;
}


void _ZN8type_memIhLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__205;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__206;

  *(&llvm_cbe_tmp__205) = llvm_cbe_this;
  llvm_cbe_tmp__206 = *(&llvm_cbe_tmp__205);
  _ZN8type_memIhLj65536EED2Ev(llvm_cbe_tmp__206);
  return;
}


struct l_class_OC_SysCArray1D _ZN11model_train24cppUpdateFun_hidden_unitElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__207;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__208;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__209;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__210;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__211;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__212;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__213;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__214;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__215;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__216;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__217;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__218;    /* Address-exposed local */
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
  unsigned char *llvm_cbe_tmp__219;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__220;    /* Address-exposed local */
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
  bool llvm_cbe_tmp__221;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__222;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__223;
  unsigned long long llvm_cbe_tmp__224;
  unsigned char llvm_cbe_tmp__225;
  unsigned long long llvm_cbe_tmp__226;
  unsigned long long llvm_cbe_tmp__227;
  unsigned long long llvm_cbe_tmp__228;
  unsigned long long llvm_cbe_tmp__229;
  unsigned long long llvm_cbe_tmp__230;
  unsigned long long llvm_cbe_tmp__231;
  unsigned long long llvm_cbe_tmp__232;
  unsigned char llvm_cbe_tmp__233;
  unsigned char llvm_cbe_tmp__234;
  bool llvm_cbe_tmp__235;
  bool llvm_cbe_tmp__236;
  bool llvm_cbe_tmp__236__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__237;
  unsigned long long llvm_cbe_tmp__238;
  unsigned long long llvm_cbe_tmp__239;
  unsigned char llvm_cbe_tmp__240;
  unsigned long long llvm_cbe_tmp__241;
  unsigned long long llvm_cbe_tmp__242;
  unsigned short llvm_cbe_tmp__243;
  unsigned long long llvm_cbe_tmp__244;
  unsigned char llvm_cbe_tmp__245;
  unsigned long long llvm_cbe_tmp__246;
  unsigned long long llvm_cbe_tmp__247;
  unsigned long long llvm_cbe_tmp__248;
  unsigned long long llvm_cbe_tmp__249;
  unsigned long long llvm_cbe_tmp__250;
  unsigned long long llvm_cbe_tmp__251;
  unsigned char llvm_cbe_tmp__252;
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
  unsigned long long llvm_cbe_tmp__269__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__270;
  unsigned long long llvm_cbe_tmp__271;
  unsigned long long llvm_cbe_tmp__272;
  unsigned long long llvm_cbe_tmp__273;
  unsigned long long llvm_cbe_tmp__274;
  unsigned long long llvm_cbe_tmp__275;
  unsigned long long llvm_cbe_tmp__276;
  unsigned long long llvm_cbe_tmp__277;
  unsigned long long llvm_cbe_tmp__278;
  unsigned long long llvm_cbe_tmp__279;
  unsigned long long llvm_cbe_tmp__280;
  unsigned long long llvm_cbe_tmp__281;
  unsigned short llvm_cbe_tmp__282;
  unsigned long long llvm_cbe_tmp__283;
  unsigned long long llvm_cbe_tmp__284;
  unsigned char llvm_cbe_tmp__285;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__286;
  unsigned long long llvm_cbe_tmp__287;
  unsigned long long llvm_cbe_tmp__288;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__289;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__290;
  unsigned long long llvm_cbe_tmp__291;
  unsigned long long llvm_cbe_tmp__292;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__293;
  unsigned long long llvm_cbe_tmp__294;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__295;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__296;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__297;
  unsigned long long llvm_cbe_tmp__298;
  unsigned char llvm_cbe_tmp__299;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__300;
  unsigned long long llvm_cbe_tmp__301;
  unsigned char llvm_cbe_tmp__302;
  bool llvm_cbe_tmp__303;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__304;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__305;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__306;
  bool llvm_cbe_tmp__307;

  *(&llvm_cbe_tmp__207) = llvm_cbe_this;
  *(&llvm_cbe_tmp__208) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__209) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__210) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__211) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__212) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__213) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__214) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__215) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__216) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__217) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__218) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__223 = *(&llvm_cbe_tmp__207);
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1028));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1000));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1030));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_994));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1034));
  _ZN8type_memIbLj128EEC1Ev((&llvm_cbe_cppVar_1031));
  *(&llvm_cbe_tmp__221) = ((0) & 1);
  _ZN8type_memIbLj128EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__224 = *((&llvm_cbe_tmp__223->field29));
  *(&llvm_cbe_cppVar_993) = (((unsigned char )(bool )(llvm_cbe_tmp__224 == 0ull)));
  llvm_cbe_tmp__225 = *(&llvm_cbe_cppVar_993);
  if ((((((bool )llvm_cbe_tmp__225&1u))&1))) {
    goto llvm_cbe_tmp__308;
  } else {
    goto llvm_cbe_tmp__309;
  }

llvm_cbe_tmp__308:
  llvm_cbe_tmp__226 = *((&llvm_cbe_tmp__223->field30));
  llvm_cbe_tmp__227 = *((&llvm_cbe_tmp__223->field14));
  *(&llvm_cbe_cppVar_995) = (((unsigned char )(bool )(llvm_cbe_tmp__226 == llvm_cbe_tmp__227)));
  llvm_cbe_tmp__228 = *((&llvm_cbe_tmp__223->field9));
  *(&llvm_cbe_cppVar_997) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__228) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__229 = *(&llvm_cbe_cppVar_997);
  llvm_cbe_tmp__230 = *((&llvm_cbe_tmp__223->field39));
  *(&llvm_cbe_cppVar_997) = (llvm_cbe_tmp__229 & llvm_cbe_tmp__230);
  llvm_cbe_tmp__231 = *((&llvm_cbe_tmp__223->field25));
  llvm_cbe_tmp__232 = *(&llvm_cbe_cppVar_997);
  *(&llvm_cbe_cppVar_998) = (((unsigned char )(bool )(llvm_cbe_tmp__231 == llvm_cbe_tmp__232)));
  llvm_cbe_tmp__233 = *(&llvm_cbe_cppVar_995);
  if ((((((bool )llvm_cbe_tmp__233&1u))&1))) {
    goto llvm_cbe_tmp__310;
  } else {
    llvm_cbe_tmp__236__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__311;
  }

llvm_cbe_tmp__310:
  llvm_cbe_tmp__234 = *(&llvm_cbe_cppVar_998);
  llvm_cbe_tmp__235 = ((((bool )llvm_cbe_tmp__234&1u))&1);
  llvm_cbe_tmp__236__PHI_TEMPORARY = llvm_cbe_tmp__235;   /* for PHI node */
  goto llvm_cbe_tmp__311;

llvm_cbe_tmp__311:
  llvm_cbe_tmp__236 = ((llvm_cbe_tmp__236__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_999) = (((unsigned char )(bool )llvm_cbe_tmp__236));
  llvm_cbe_tmp__237 = *(&llvm_cbe_cppVar_999);
  if ((((((bool )llvm_cbe_tmp__237&1u))&1))) {
    goto llvm_cbe_tmp__312;
  } else {
    goto llvm_cbe_tmp__313;
  }

llvm_cbe_tmp__312:
  llvm_cbe_tmp__238 = *((&llvm_cbe_tmp__223->field30));
  llvm_cbe_tmp__239 = *((&llvm_cbe_tmp__223->field14));
  *(&llvm_cbe_cppVar_1001) = (((unsigned char )(bool )(llvm_cbe_tmp__238 == llvm_cbe_tmp__239)));
  llvm_cbe_tmp__240 = *(&llvm_cbe_cppVar_1001);
  if ((((((bool )llvm_cbe_tmp__240&1u))&1))) {
    goto llvm_cbe_tmp__314;
  } else {
    goto llvm_cbe_tmp__315;
  }

llvm_cbe_tmp__314:
  llvm_cbe_tmp__241 = *((&llvm_cbe_tmp__223->field25));
  llvm_cbe_tmp__242 = *((&llvm_cbe_tmp__223->field43));
  *(&llvm_cbe_cppVar_1002) = ((((signed long long )(((signed long long )llvm_cbe_tmp__241) >> ((signed long long )0ull)))) & llvm_cbe_tmp__242);
  llvm_cbe_tmp__243 = _Z4randv();
  *(&llvm_cbe_cppVar_1004) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__243));
  llvm_cbe_tmp__244 = *((&llvm_cbe_tmp__223->field30));
  *(&llvm_cbe_cppVar_1007) = (((unsigned char )(bool )(llvm_cbe_tmp__244 == 0ull)));
  llvm_cbe_tmp__245 = *(&llvm_cbe_cppVar_1007);
  if ((((((bool )llvm_cbe_tmp__245&1u))&1))) {
    goto llvm_cbe_tmp__316;
  } else {
    goto llvm_cbe_tmp__317;
  }

llvm_cbe_tmp__316:
  *(&llvm_cbe_cppVar_1005) = 0ull;
  goto llvm_cbe_tmp__318;

llvm_cbe_tmp__317:
  llvm_cbe_tmp__246 = *((&llvm_cbe_tmp__223->field28));
  *(&llvm_cbe_cppVar_1005) = llvm_cbe_tmp__246;
  goto llvm_cbe_tmp__318;

llvm_cbe_tmp__318:
  llvm_cbe_tmp__247 = *((&llvm_cbe_tmp__223->field30));
  llvm_cbe_tmp__248 = *((&llvm_cbe_tmp__223->field45));
  *(&llvm_cbe_cppVar_1010) = ((((signed long long )(((signed long long )llvm_cbe_tmp__247) >> ((signed long long )0ull)))) & llvm_cbe_tmp__248);
  llvm_cbe_tmp__249 = *(&llvm_cbe_cppVar_1010);
  llvm_cbe_tmp__250 = _ZN8type_memIhLj512EE2rdEl(((&llvm_cbe_tmp__223->field0)), llvm_cbe_tmp__249);
  *(&llvm_cbe_cppVar_1011) = llvm_cbe_tmp__250;
  llvm_cbe_tmp__251 = *(&llvm_cbe_cppVar_1011);
  *(&llvm_cbe_cppVar_1013) = (((unsigned char )(bool )(llvm_cbe_tmp__251 == 1ull)));
  llvm_cbe_tmp__252 = *(&llvm_cbe_cppVar_1013);
  if ((((((bool )llvm_cbe_tmp__252&1u))&1))) {
    goto llvm_cbe_tmp__319;
  } else {
    goto llvm_cbe_tmp__320;
  }

llvm_cbe_tmp__319:
  llvm_cbe_tmp__253 = *((&llvm_cbe_tmp__223->field30));
  *(&llvm_cbe_cppVar_1015) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__253))));
  llvm_cbe_tmp__254 = *(&llvm_cbe_cppVar_1015);
  llvm_cbe_tmp__255 = *((&llvm_cbe_tmp__223->field39));
  *(&llvm_cbe_cppVar_1015) = (llvm_cbe_tmp__254 & llvm_cbe_tmp__255);
  llvm_cbe_tmp__256 = *(&llvm_cbe_cppVar_1015);
  llvm_cbe_tmp__257 = *((&llvm_cbe_tmp__223->field25));
  *(&llvm_cbe_cppVar_1016) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__256) + ((unsigned long long )llvm_cbe_tmp__257))));
  llvm_cbe_tmp__258 = *(&llvm_cbe_cppVar_1016);
  llvm_cbe_tmp__259 = *((&llvm_cbe_tmp__223->field39));
  *(&llvm_cbe_cppVar_1016) = (llvm_cbe_tmp__258 & llvm_cbe_tmp__259);
  llvm_cbe_tmp__260 = *(&llvm_cbe_cppVar_1016);
  llvm_cbe_tmp__261 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__223->field3)), llvm_cbe_tmp__260);
  *(&llvm_cbe_cppVar_1017) = llvm_cbe_tmp__261;
  llvm_cbe_tmp__262 = *(&llvm_cbe_cppVar_1017);
  llvm_cbe_tmp__263 = *((&llvm_cbe_tmp__223->field43));
  *(&llvm_cbe_cppVar_1018) = ((((signed long long )(((signed long long )llvm_cbe_tmp__262) >> ((signed long long )1ull)))) & llvm_cbe_tmp__263);
  llvm_cbe_tmp__264 = *(&llvm_cbe_cppVar_1018);
  llvm_cbe_tmp__265 = *((&llvm_cbe_tmp__223->field47));
  llvm_cbe_tmp__266 = *(&llvm_cbe_cppVar_1018);
  if (((llvm_cbe_tmp__264 & llvm_cbe_tmp__265) != 0ull)) {
    goto llvm_cbe_tmp__321;
  } else {
    llvm_cbe_tmp__269__PHI_TEMPORARY = llvm_cbe_tmp__266;   /* for PHI node */
    goto llvm_cbe_tmp__322;
  }

llvm_cbe_tmp__321:
  llvm_cbe_tmp__267 = *((&llvm_cbe_tmp__223->field49));
  llvm_cbe_tmp__268 = llvm_cbe_tmp__266 | llvm_cbe_tmp__267;
  llvm_cbe_tmp__269__PHI_TEMPORARY = llvm_cbe_tmp__268;   /* for PHI node */
  goto llvm_cbe_tmp__322;

llvm_cbe_tmp__322:
  llvm_cbe_tmp__269 = llvm_cbe_tmp__269__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_1019) = llvm_cbe_tmp__269;
  llvm_cbe_tmp__270 = *(&llvm_cbe_cppVar_1017);
  llvm_cbe_tmp__271 = *((&llvm_cbe_tmp__223->field38));
  *(&llvm_cbe_cppVar_1020) = ((((signed long long )(((signed long long )llvm_cbe_tmp__270) >> ((signed long long )0ull)))) & llvm_cbe_tmp__271);
  llvm_cbe_tmp__272 = *(&llvm_cbe_cppVar_1019);
  llvm_cbe_tmp__273 = *(&llvm_cbe_cppVar_1020);
  *(&llvm_cbe_cppVar_1021) = ((llvm_cbe_tmp__272 << 1ull) | llvm_cbe_tmp__273);
  llvm_cbe_tmp__274 = *(&llvm_cbe_cppVar_1021);
  llvm_cbe_tmp__275 = *((&llvm_cbe_tmp__223->field39));
  *(&llvm_cbe_cppVar_1021) = (llvm_cbe_tmp__274 & llvm_cbe_tmp__275);
  llvm_cbe_tmp__276 = *(&llvm_cbe_cppVar_1021);
  *(&llvm_cbe_cppVar_1009) = llvm_cbe_tmp__276;
  goto llvm_cbe_tmp__323;

llvm_cbe_tmp__320:
  *(&llvm_cbe_cppVar_1009) = 0ull;
  goto llvm_cbe_tmp__323;

llvm_cbe_tmp__323:
  llvm_cbe_tmp__277 = *(&llvm_cbe_cppVar_1005);
  llvm_cbe_tmp__278 = *(&llvm_cbe_cppVar_1009);
  *(&llvm_cbe_cppVar_1023) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__277) + ((unsigned long long )llvm_cbe_tmp__278))));
  llvm_cbe_tmp__279 = *(&llvm_cbe_cppVar_1023);
  llvm_cbe_tmp__280 = *((&llvm_cbe_tmp__223->field39));
  *(&llvm_cbe_cppVar_1023) = (llvm_cbe_tmp__279 & llvm_cbe_tmp__280);
  llvm_cbe_tmp__281 = *(&llvm_cbe_cppVar_1023);
  llvm_cbe_tmp__282 = _Z7sigmoidl(llvm_cbe_tmp__281);
  *(&llvm_cbe_cppVar_1024) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__282));
  llvm_cbe_tmp__283 = *(&llvm_cbe_cppVar_1004);
  llvm_cbe_tmp__284 = *(&llvm_cbe_cppVar_1024);
  *(&llvm_cbe_cppVar_1025) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__283) < ((signed long long )llvm_cbe_tmp__284))));
  llvm_cbe_tmp__285 = *(&llvm_cbe_cppVar_1025);
  if ((((((bool )llvm_cbe_tmp__285&1u))&1))) {
    goto llvm_cbe_tmp__324;
  } else {
    goto llvm_cbe_tmp__325;
  }

llvm_cbe_tmp__324:
  *(&llvm_cbe_cppVar_1003) = 1ull;
  goto llvm_cbe_tmp__326;

llvm_cbe_tmp__325:
  *(&llvm_cbe_cppVar_1003) = 0ull;
  goto llvm_cbe_tmp__326;

llvm_cbe_tmp__326:
  llvm_cbe_tmp__286 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1028), ((&llvm_cbe_tmp__223->field4)));
  llvm_cbe_tmp__287 = *(&llvm_cbe_cppVar_1002);
  llvm_cbe_tmp__288 = *(&llvm_cbe_cppVar_1003);
  _ZN8type_memIbLj128EE2wrEll((&llvm_cbe_cppVar_1028), llvm_cbe_tmp__287, llvm_cbe_tmp__288);
  llvm_cbe_tmp__289 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1000), (&llvm_cbe_cppVar_1028));
  goto llvm_cbe_tmp__327;

llvm_cbe_tmp__315:
  llvm_cbe_tmp__290 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1000), ((&llvm_cbe_tmp__223->field4)));
  goto llvm_cbe_tmp__327;

llvm_cbe_tmp__327:
  llvm_cbe_tmp__291 = *((&llvm_cbe_tmp__223->field9));
  llvm_cbe_tmp__292 = *((&llvm_cbe_tmp__223->field43));
  *(&llvm_cbe_cppVar_1029) = ((((signed long long )(((signed long long )llvm_cbe_tmp__291) >> ((signed long long )0ull)))) & llvm_cbe_tmp__292);
  llvm_cbe_tmp__293 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1030), (&llvm_cbe_cppVar_1000));
  llvm_cbe_tmp__294 = *(&llvm_cbe_cppVar_1029);
  _ZN8type_memIbLj128EE2wrEll((&llvm_cbe_cppVar_1030), llvm_cbe_tmp__294, 1ull);
  llvm_cbe_tmp__295 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_994), (&llvm_cbe_cppVar_1030));
  goto llvm_cbe_tmp__328;

llvm_cbe_tmp__313:
  llvm_cbe_tmp__296 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_994), (&llvm_cbe_cppVar_1000));
  goto llvm_cbe_tmp__328;

llvm_cbe_tmp__328:
  llvm_cbe_tmp__297 = _ZN8type_memIbLj128EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_994));
  goto llvm_cbe_tmp__329;

llvm_cbe_tmp__309:
  llvm_cbe_tmp__298 = *((&llvm_cbe_tmp__223->field29));
  *(&llvm_cbe_cppVar_1033) = (((unsigned char )(bool )(llvm_cbe_tmp__298 == 1ull)));
  llvm_cbe_tmp__299 = *(&llvm_cbe_cppVar_1033);
  if ((((((bool )llvm_cbe_tmp__299&1u))&1))) {
    goto llvm_cbe_tmp__330;
  } else {
    goto llvm_cbe_tmp__331;
  }

llvm_cbe_tmp__330:
  llvm_cbe_tmp__300 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1031), ((&llvm_cbe_tmp__223->field4)));
  goto llvm_cbe_tmp__332;

llvm_cbe_tmp__331:
  llvm_cbe_tmp__301 = *((&llvm_cbe_tmp__223->field29));
  *(&llvm_cbe_cppVar_1036) = (((unsigned char )(bool )(llvm_cbe_tmp__301 == 2ull)));
  llvm_cbe_tmp__302 = *(&llvm_cbe_cppVar_1036);
  llvm_cbe_tmp__303 = ((((bool )llvm_cbe_tmp__302&1u))&1);
  llvm_cbe_tmp__304 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1034), ((&llvm_cbe_tmp__223->field4)));
  llvm_cbe_tmp__305 = _ZN8type_memIbLj128EEaSERKS0_((&llvm_cbe_cppVar_1031), (&llvm_cbe_cppVar_1034));
  goto llvm_cbe_tmp__332;

llvm_cbe_tmp__332:
  llvm_cbe_tmp__306 = _ZN8type_memIbLj128EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1031));
  goto llvm_cbe_tmp__329;

llvm_cbe_tmp__329:
  *(&llvm_cbe_tmp__221) = ((1) & 1);
  *(&llvm_cbe_tmp__222) = 1u;
  llvm_cbe_tmp__307 = ((*(&llvm_cbe_tmp__221))&1);
  if (llvm_cbe_tmp__307) {
    goto llvm_cbe_tmp__333;
  } else {
    goto llvm_cbe_tmp__334;
  }

llvm_cbe_tmp__334:
  _ZN8type_memIbLj128EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__333;

llvm_cbe_tmp__333:
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1031));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1034));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_994));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1030));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1000));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1028));
  return StructReturn;
}


void _ZN8type_memIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__335;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__336;

  *(&llvm_cbe_tmp__335) = llvm_cbe_this;
  llvm_cbe_tmp__336 = *(&llvm_cbe_tmp__335);
  _ZN8type_memIbLj128EEC2Ev(llvm_cbe_tmp__336);
  return;
}


unsigned long long _ZN8type_memIhLj512EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__337;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__338;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__339;
  unsigned long long llvm_cbe_tmp__340;
  unsigned char *llvm_cbe_tmp__341;
  unsigned char llvm_cbe_tmp__342;

  *(&llvm_cbe_tmp__337) = llvm_cbe_this;
  *(&llvm_cbe_tmp__338) = llvm_cbe_addr;
  llvm_cbe_tmp__339 = *(&llvm_cbe_tmp__337);
  llvm_cbe_tmp__340 = *(&llvm_cbe_tmp__338);
  llvm_cbe_tmp__341 = *((&llvm_cbe_tmp__339->field0));
  llvm_cbe_tmp__342 = *((&llvm_cbe_tmp__341[((signed long long )llvm_cbe_tmp__340)]));
  return (((unsigned long long )(unsigned char )llvm_cbe_tmp__342));
}


struct l_class_OC_SysCArray1D *_ZN8type_memIbLj128EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__343;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__344;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__345;
  unsigned char *llvm_cbe_tmp__346;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__347;
  unsigned char *llvm_cbe_tmp__348;

  *(&llvm_cbe_tmp__343) = llvm_cbe_this;
  *(&llvm_cbe_tmp__344) = llvm_cbe_r;
  llvm_cbe_tmp__345 = *(&llvm_cbe_tmp__343);
  llvm_cbe_tmp__346 = *((&llvm_cbe_tmp__345->field0));
  llvm_cbe_tmp__347 = *(&llvm_cbe_tmp__344);
  llvm_cbe_tmp__348 = *((&llvm_cbe_tmp__347->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__346, llvm_cbe_tmp__348);
  return llvm_cbe_tmp__345;
}


void _ZN8type_memIbLj128EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__349;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__350;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__351;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__352;
  unsigned long long llvm_cbe_tmp__353;
  unsigned long long llvm_cbe_tmp__354;
  unsigned char *llvm_cbe_tmp__355;

  *(&llvm_cbe_tmp__349) = llvm_cbe_this;
  *(&llvm_cbe_tmp__350) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__351) = llvm_cbe_data;
  llvm_cbe_tmp__352 = *(&llvm_cbe_tmp__349);
  llvm_cbe_tmp__353 = *(&llvm_cbe_tmp__351);
  llvm_cbe_tmp__354 = *(&llvm_cbe_tmp__350);
  llvm_cbe_tmp__355 = *((&llvm_cbe_tmp__352->field0));
  *((&llvm_cbe_tmp__355[((signed long long )llvm_cbe_tmp__354)])) = (((unsigned char )(bool )(llvm_cbe_tmp__353 != 0ull)));
  return;
}


void _ZN8type_memIbLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__356;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__357;

  *(&llvm_cbe_tmp__356) = llvm_cbe_this;
  llvm_cbe_tmp__357 = *(&llvm_cbe_tmp__356);
  _ZN8type_memIbLj128EED2Ev(llvm_cbe_tmp__357);
  return;
}


unsigned long long _ZN11model_train18cppUpdateFun_indexElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__358;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__359;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__360;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__361;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__362;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__363;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__364;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__365;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__366;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__367;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__368;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__369;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__370;
  unsigned long long llvm_cbe_tmp__371;
  unsigned char llvm_cbe_tmp__372;
  unsigned long long llvm_cbe_tmp__373;
  unsigned long long llvm_cbe_tmp__374;
  unsigned char llvm_cbe_tmp__375;
  unsigned long long llvm_cbe_tmp__376;
  unsigned long long llvm_cbe_tmp__377;
  unsigned char llvm_cbe_tmp__378;
  unsigned long long llvm_cbe_tmp__379;
  unsigned long long llvm_cbe_tmp__380;
  unsigned long long llvm_cbe_tmp__381;
  unsigned long long llvm_cbe_tmp__382;
  unsigned char llvm_cbe_tmp__383;
  unsigned char llvm_cbe_tmp__384;
  bool llvm_cbe_tmp__385;
  bool llvm_cbe_tmp__386;
  bool llvm_cbe_tmp__386__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__387;
  unsigned long long llvm_cbe_tmp__388;
  unsigned long long llvm_cbe_tmp__389;
  unsigned long long llvm_cbe_tmp__390;
  unsigned long long llvm_cbe_tmp__391;
  unsigned long long llvm_cbe_tmp__392;
  unsigned long long llvm_cbe_tmp__393;
  unsigned long long llvm_cbe_tmp__394;
  unsigned char llvm_cbe_tmp__395;
  unsigned char llvm_cbe_tmp__396;
  bool llvm_cbe_tmp__397;
  bool llvm_cbe_tmp__398;
  bool llvm_cbe_tmp__398__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__399;
  unsigned long long llvm_cbe_tmp__400;
  unsigned long long llvm_cbe_tmp__401;
  unsigned long long llvm_cbe_tmp__402;
  unsigned long long llvm_cbe_tmp__403;
  unsigned long long llvm_cbe_tmp__404;
  unsigned long long llvm_cbe_tmp__405;
  unsigned long long llvm_cbe_tmp__406;
  unsigned long long llvm_cbe_tmp__407;
  unsigned long long llvm_cbe_tmp__408;
  unsigned long long llvm_cbe_tmp__409;
  unsigned long long llvm_cbe_tmp__410;

  *(&llvm_cbe_tmp__358) = llvm_cbe_this;
  *(&llvm_cbe_tmp__359) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__360) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__361) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__362) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__363) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__364) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__365) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__366) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__367) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__368) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__369) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__370 = *(&llvm_cbe_tmp__358);
  llvm_cbe_tmp__371 = *((&llvm_cbe_tmp__370->field29));
  *(&llvm_cbe_cppVar_492) = (((unsigned char )(bool )(llvm_cbe_tmp__371 == 0ull)));
  llvm_cbe_tmp__372 = *(&llvm_cbe_cppVar_492);
  if ((((((bool )llvm_cbe_tmp__372&1u))&1))) {
    goto llvm_cbe_tmp__411;
  } else {
    goto llvm_cbe_tmp__412;
  }

llvm_cbe_tmp__411:
  llvm_cbe_tmp__373 = *((&llvm_cbe_tmp__370->field5));
  *(&llvm_cbe_cppVar_490) = llvm_cbe_tmp__373;
  goto llvm_cbe_tmp__413;

llvm_cbe_tmp__412:
  llvm_cbe_tmp__374 = *((&llvm_cbe_tmp__370->field29));
  *(&llvm_cbe_cppVar_495) = (((unsigned char )(bool )(llvm_cbe_tmp__374 == 1ull)));
  llvm_cbe_tmp__375 = *(&llvm_cbe_cppVar_495);
  if ((((((bool )llvm_cbe_tmp__375&1u))&1))) {
    goto llvm_cbe_tmp__414;
  } else {
    goto llvm_cbe_tmp__415;
  }

llvm_cbe_tmp__414:
  llvm_cbe_tmp__376 = *((&llvm_cbe_tmp__370->field5));
  *(&llvm_cbe_cppVar_493) = llvm_cbe_tmp__376;
  goto llvm_cbe_tmp__416;

llvm_cbe_tmp__415:
  llvm_cbe_tmp__377 = *((&llvm_cbe_tmp__370->field29));
  *(&llvm_cbe_cppVar_498) = (((unsigned char )(bool )(llvm_cbe_tmp__377 == 2ull)));
  llvm_cbe_tmp__378 = *(&llvm_cbe_cppVar_498);
  if ((((((bool )llvm_cbe_tmp__378&1u))&1))) {
    goto llvm_cbe_tmp__417;
  } else {
    goto llvm_cbe_tmp__418;
  }

llvm_cbe_tmp__417:
  llvm_cbe_tmp__379 = *((&llvm_cbe_tmp__370->field25));
  llvm_cbe_tmp__380 = *((&llvm_cbe_tmp__370->field9));
  *(&llvm_cbe_cppVar_500) = (((unsigned char )(bool )(llvm_cbe_tmp__379 == llvm_cbe_tmp__380)));
  llvm_cbe_tmp__381 = *((&llvm_cbe_tmp__370->field30));
  llvm_cbe_tmp__382 = *((&llvm_cbe_tmp__370->field14));
  *(&llvm_cbe_cppVar_501) = (((unsigned char )(bool )(llvm_cbe_tmp__381 == llvm_cbe_tmp__382)));
  llvm_cbe_tmp__383 = *(&llvm_cbe_cppVar_500);
  if ((((((bool )llvm_cbe_tmp__383&1u))&1))) {
    goto llvm_cbe_tmp__419;
  } else {
    llvm_cbe_tmp__386__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__420;
  }

llvm_cbe_tmp__419:
  llvm_cbe_tmp__384 = *(&llvm_cbe_cppVar_501);
  llvm_cbe_tmp__385 = ((((bool )llvm_cbe_tmp__384&1u))&1);
  llvm_cbe_tmp__386__PHI_TEMPORARY = llvm_cbe_tmp__385;   /* for PHI node */
  goto llvm_cbe_tmp__420;

llvm_cbe_tmp__420:
  llvm_cbe_tmp__386 = ((llvm_cbe_tmp__386__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_502) = (((unsigned char )(bool )llvm_cbe_tmp__386));
  llvm_cbe_tmp__387 = *(&llvm_cbe_cppVar_502);
  if ((((((bool )llvm_cbe_tmp__387&1u))&1))) {
    goto llvm_cbe_tmp__421;
  } else {
    goto llvm_cbe_tmp__422;
  }

llvm_cbe_tmp__421:
  llvm_cbe_tmp__388 = *((&llvm_cbe_tmp__370->field13));
  *(&llvm_cbe_cppVar_505) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__388) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__389 = *(&llvm_cbe_cppVar_505);
  llvm_cbe_tmp__390 = *((&llvm_cbe_tmp__370->field39));
  *(&llvm_cbe_cppVar_505) = (llvm_cbe_tmp__389 & llvm_cbe_tmp__390);
  llvm_cbe_tmp__391 = *((&llvm_cbe_tmp__370->field5));
  llvm_cbe_tmp__392 = *(&llvm_cbe_cppVar_505);
  *(&llvm_cbe_cppVar_506) = (((unsigned char )(bool )(llvm_cbe_tmp__391 == llvm_cbe_tmp__392)));
  llvm_cbe_tmp__393 = *((&llvm_cbe_tmp__370->field8));
  llvm_cbe_tmp__394 = *((&llvm_cbe_tmp__370->field10));
  *(&llvm_cbe_cppVar_507) = (((unsigned char )(bool )(llvm_cbe_tmp__393 != llvm_cbe_tmp__394)));
  llvm_cbe_tmp__395 = *(&llvm_cbe_cppVar_506);
  if ((((((bool )llvm_cbe_tmp__395&1u))&1))) {
    goto llvm_cbe_tmp__423;
  } else {
    llvm_cbe_tmp__398__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__424;
  }

llvm_cbe_tmp__423:
  llvm_cbe_tmp__396 = *(&llvm_cbe_cppVar_507);
  llvm_cbe_tmp__397 = ((((bool )llvm_cbe_tmp__396&1u))&1);
  llvm_cbe_tmp__398__PHI_TEMPORARY = llvm_cbe_tmp__397;   /* for PHI node */
  goto llvm_cbe_tmp__424;

llvm_cbe_tmp__424:
  llvm_cbe_tmp__398 = ((llvm_cbe_tmp__398__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_508) = (((unsigned char )(bool )llvm_cbe_tmp__398));
  llvm_cbe_tmp__399 = *(&llvm_cbe_cppVar_508);
  if ((((((bool )llvm_cbe_tmp__399&1u))&1))) {
    goto llvm_cbe_tmp__425;
  } else {
    goto llvm_cbe_tmp__426;
  }

llvm_cbe_tmp__425:
  *(&llvm_cbe_cppVar_503) = 0ull;
  goto llvm_cbe_tmp__427;

llvm_cbe_tmp__426:
  llvm_cbe_tmp__400 = *((&llvm_cbe_tmp__370->field5));
  *(&llvm_cbe_cppVar_511) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__400) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__401 = *(&llvm_cbe_cppVar_511);
  llvm_cbe_tmp__402 = *((&llvm_cbe_tmp__370->field39));
  *(&llvm_cbe_cppVar_511) = (llvm_cbe_tmp__401 & llvm_cbe_tmp__402);
  llvm_cbe_tmp__403 = *(&llvm_cbe_cppVar_511);
  *(&llvm_cbe_cppVar_503) = llvm_cbe_tmp__403;
  goto llvm_cbe_tmp__427;

llvm_cbe_tmp__427:
  llvm_cbe_tmp__404 = *(&llvm_cbe_cppVar_503);
  *(&llvm_cbe_cppVar_499) = llvm_cbe_tmp__404;
  goto llvm_cbe_tmp__428;

llvm_cbe_tmp__422:
  llvm_cbe_tmp__405 = *((&llvm_cbe_tmp__370->field5));
  *(&llvm_cbe_cppVar_499) = llvm_cbe_tmp__405;
  goto llvm_cbe_tmp__428;

llvm_cbe_tmp__428:
  llvm_cbe_tmp__406 = *(&llvm_cbe_cppVar_499);
  *(&llvm_cbe_cppVar_496) = llvm_cbe_tmp__406;
  goto llvm_cbe_tmp__429;

llvm_cbe_tmp__418:
  llvm_cbe_tmp__407 = *((&llvm_cbe_tmp__370->field5));
  *(&llvm_cbe_cppVar_496) = llvm_cbe_tmp__407;
  goto llvm_cbe_tmp__429;

llvm_cbe_tmp__429:
  llvm_cbe_tmp__408 = *(&llvm_cbe_cppVar_496);
  *(&llvm_cbe_cppVar_493) = llvm_cbe_tmp__408;
  goto llvm_cbe_tmp__416;

llvm_cbe_tmp__416:
  llvm_cbe_tmp__409 = *(&llvm_cbe_cppVar_493);
  *(&llvm_cbe_cppVar_490) = llvm_cbe_tmp__409;
  goto llvm_cbe_tmp__413;

llvm_cbe_tmp__413:
  llvm_cbe_tmp__410 = *(&llvm_cbe_cppVar_490);
  return llvm_cbe_tmp__410;
}


unsigned long long _ZN11model_train19cppUpdateFun_jstateElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__430;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__431;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__432;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__433;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__434;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__435;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__436;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__437;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__438;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__439;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__440;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__441;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_514;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_515;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_518;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_519;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_547;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_548;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_525;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_527;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_528;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_521;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_522;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_523;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_532;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_533;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_534;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_539;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_540;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_541;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_543;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_544;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_545;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_529;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_530;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_526;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_524;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_536;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_537;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_535;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_542;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_538;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_531;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_520;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_546;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_517;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_513;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_516;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__442;
  unsigned long long llvm_cbe_tmp__443;
  unsigned char llvm_cbe_tmp__444;
  unsigned long long llvm_cbe_tmp__445;
  unsigned char llvm_cbe_tmp__446;
  unsigned long long llvm_cbe_tmp__447;
  unsigned char llvm_cbe_tmp__448;
  unsigned char llvm_cbe_tmp__449;
  bool llvm_cbe_tmp__450;
  bool llvm_cbe_tmp__451;
  bool llvm_cbe_tmp__451__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__452;
  unsigned long long llvm_cbe_tmp__453;
  unsigned long long llvm_cbe_tmp__454;
  unsigned char llvm_cbe_tmp__455;
  unsigned long long llvm_cbe_tmp__456;
  unsigned char llvm_cbe_tmp__457;
  unsigned long long llvm_cbe_tmp__458;
  unsigned long long llvm_cbe_tmp__459;
  unsigned long long llvm_cbe_tmp__460;
  unsigned long long llvm_cbe_tmp__461;
  unsigned long long llvm_cbe_tmp__462;
  unsigned long long llvm_cbe_tmp__463;
  unsigned long long llvm_cbe_tmp__464;
  unsigned char llvm_cbe_tmp__465;
  unsigned char llvm_cbe_tmp__466;
  bool llvm_cbe_tmp__467;
  bool llvm_cbe_tmp__468;
  bool llvm_cbe_tmp__468__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__469;
  unsigned char llvm_cbe_tmp__470;
  unsigned long long llvm_cbe_tmp__471;
  unsigned long long llvm_cbe_tmp__472;
  unsigned long long llvm_cbe_tmp__473;
  unsigned long long llvm_cbe_tmp__474;
  unsigned long long llvm_cbe_tmp__475;
  unsigned long long llvm_cbe_tmp__476;
  unsigned char llvm_cbe_tmp__477;
  unsigned char llvm_cbe_tmp__478;
  bool llvm_cbe_tmp__479;
  bool llvm_cbe_tmp__480;
  bool llvm_cbe_tmp__480__PHI_TEMPORARY;
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
  unsigned long long llvm_cbe_tmp__496;
  unsigned long long llvm_cbe_tmp__497;
  unsigned long long llvm_cbe_tmp__498;
  unsigned long long llvm_cbe_tmp__499;

  *(&llvm_cbe_tmp__430) = llvm_cbe_this;
  *(&llvm_cbe_tmp__431) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__432) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__433) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__434) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__435) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__436) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__437) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__438) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__439) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__440) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__441) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__442 = *(&llvm_cbe_tmp__430);
  llvm_cbe_tmp__443 = *((&llvm_cbe_tmp__442->field29));
  *(&llvm_cbe_cppVar_515) = (((unsigned char )(bool )(llvm_cbe_tmp__443 == 0ull)));
  llvm_cbe_tmp__444 = *(&llvm_cbe_cppVar_515);
  if ((((((bool )llvm_cbe_tmp__444&1u))&1))) {
    goto llvm_cbe_tmp__500;
  } else {
    goto llvm_cbe_tmp__501;
  }

llvm_cbe_tmp__500:
  *(&llvm_cbe_cppVar_513) = 0ull;
  goto llvm_cbe_tmp__502;

llvm_cbe_tmp__501:
  llvm_cbe_tmp__445 = *((&llvm_cbe_tmp__442->field29));
  *(&llvm_cbe_cppVar_519) = (((unsigned char )(bool )(llvm_cbe_tmp__445 == 1ull)));
  llvm_cbe_tmp__446 = *(&llvm_cbe_cppVar_519);
  if ((((((bool )llvm_cbe_tmp__446&1u))&1))) {
    goto llvm_cbe_tmp__503;
  } else {
    goto llvm_cbe_tmp__504;
  }

llvm_cbe_tmp__503:
  llvm_cbe_tmp__447 = *((&llvm_cbe_tmp__442->field15));
  *(&llvm_cbe_cppVar_522) = (((unsigned char )(bool )(llvm_cbe_tmp__447 == 0ull)));
  llvm_cbe_tmp__448 = *(&llvm_cbe_cppVar_519);
  if ((((((bool )llvm_cbe_tmp__448&1u))&1))) {
    goto llvm_cbe_tmp__505;
  } else {
    llvm_cbe_tmp__451__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__506;
  }

llvm_cbe_tmp__505:
  llvm_cbe_tmp__449 = *(&llvm_cbe_cppVar_522);
  llvm_cbe_tmp__450 = ((((bool )llvm_cbe_tmp__449&1u))&1);
  llvm_cbe_tmp__451__PHI_TEMPORARY = llvm_cbe_tmp__450;   /* for PHI node */
  goto llvm_cbe_tmp__506;

llvm_cbe_tmp__506:
  llvm_cbe_tmp__451 = ((llvm_cbe_tmp__451__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_523) = (((unsigned char )(bool )llvm_cbe_tmp__451));
  llvm_cbe_tmp__452 = *(&llvm_cbe_cppVar_523);
  if ((((((bool )llvm_cbe_tmp__452&1u))&1))) {
    goto llvm_cbe_tmp__507;
  } else {
    goto llvm_cbe_tmp__508;
  }

llvm_cbe_tmp__507:
  llvm_cbe_tmp__453 = *((&llvm_cbe_tmp__442->field25));
  llvm_cbe_tmp__454 = *((&llvm_cbe_tmp__442->field9));
  *(&llvm_cbe_cppVar_525) = (((unsigned char )(bool )(llvm_cbe_tmp__453 == llvm_cbe_tmp__454)));
  llvm_cbe_tmp__455 = *(&llvm_cbe_cppVar_525);
  llvm_cbe_tmp__456 = *((&llvm_cbe_tmp__442->field7));
  if ((((((bool )llvm_cbe_tmp__455&1u))&1))) {
    goto llvm_cbe_tmp__509;
  } else {
    goto llvm_cbe_tmp__510;
  }

llvm_cbe_tmp__509:
  *(&llvm_cbe_cppVar_528) = (((unsigned char )(bool )(llvm_cbe_tmp__456 == 4ull)));
  llvm_cbe_tmp__457 = *(&llvm_cbe_cppVar_528);
  if ((((((bool )llvm_cbe_tmp__457&1u))&1))) {
    goto llvm_cbe_tmp__511;
  } else {
    goto llvm_cbe_tmp__512;
  }

llvm_cbe_tmp__511:
  *(&llvm_cbe_cppVar_526) = 0ull;
  goto llvm_cbe_tmp__513;

llvm_cbe_tmp__512:
  llvm_cbe_tmp__458 = *((&llvm_cbe_tmp__442->field7));
  *(&llvm_cbe_cppVar_530) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__458) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__459 = *(&llvm_cbe_cppVar_530);
  llvm_cbe_tmp__460 = *((&llvm_cbe_tmp__442->field39));
  *(&llvm_cbe_cppVar_530) = (llvm_cbe_tmp__459 & llvm_cbe_tmp__460);
  llvm_cbe_tmp__461 = *(&llvm_cbe_cppVar_530);
  *(&llvm_cbe_cppVar_526) = llvm_cbe_tmp__461;
  goto llvm_cbe_tmp__513;

llvm_cbe_tmp__513:
  llvm_cbe_tmp__462 = *(&llvm_cbe_cppVar_526);
  *(&llvm_cbe_cppVar_524) = llvm_cbe_tmp__462;
  goto llvm_cbe_tmp__514;

llvm_cbe_tmp__510:
  *(&llvm_cbe_cppVar_524) = llvm_cbe_tmp__456;
  goto llvm_cbe_tmp__514;

llvm_cbe_tmp__514:
  llvm_cbe_tmp__463 = *(&llvm_cbe_cppVar_524);
  *(&llvm_cbe_cppVar_520) = llvm_cbe_tmp__463;
  goto llvm_cbe_tmp__515;

llvm_cbe_tmp__508:
  llvm_cbe_tmp__464 = *((&llvm_cbe_tmp__442->field15));
  *(&llvm_cbe_cppVar_533) = (((unsigned char )(bool )(llvm_cbe_tmp__464 == 1ull)));
  llvm_cbe_tmp__465 = *(&llvm_cbe_cppVar_519);
  if ((((((bool )llvm_cbe_tmp__465&1u))&1))) {
    goto llvm_cbe_tmp__516;
  } else {
    llvm_cbe_tmp__468__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__517;
  }

llvm_cbe_tmp__516:
  llvm_cbe_tmp__466 = *(&llvm_cbe_cppVar_533);
  llvm_cbe_tmp__467 = ((((bool )llvm_cbe_tmp__466&1u))&1);
  llvm_cbe_tmp__468__PHI_TEMPORARY = llvm_cbe_tmp__467;   /* for PHI node */
  goto llvm_cbe_tmp__517;

llvm_cbe_tmp__517:
  llvm_cbe_tmp__468 = ((llvm_cbe_tmp__468__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_534) = (((unsigned char )(bool )llvm_cbe_tmp__468));
  llvm_cbe_tmp__469 = *(&llvm_cbe_cppVar_534);
  if ((((((bool )llvm_cbe_tmp__469&1u))&1))) {
    goto llvm_cbe_tmp__518;
  } else {
    goto llvm_cbe_tmp__519;
  }

llvm_cbe_tmp__518:
  llvm_cbe_tmp__470 = *(&llvm_cbe_cppVar_528);
  if ((((((bool )llvm_cbe_tmp__470&1u))&1))) {
    goto llvm_cbe_tmp__520;
  } else {
    goto llvm_cbe_tmp__521;
  }

llvm_cbe_tmp__520:
  *(&llvm_cbe_cppVar_535) = 0ull;
  goto llvm_cbe_tmp__522;

llvm_cbe_tmp__521:
  llvm_cbe_tmp__471 = *((&llvm_cbe_tmp__442->field7));
  *(&llvm_cbe_cppVar_537) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__471) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__472 = *(&llvm_cbe_cppVar_537);
  llvm_cbe_tmp__473 = *((&llvm_cbe_tmp__442->field39));
  *(&llvm_cbe_cppVar_537) = (llvm_cbe_tmp__472 & llvm_cbe_tmp__473);
  llvm_cbe_tmp__474 = *(&llvm_cbe_cppVar_537);
  *(&llvm_cbe_cppVar_535) = llvm_cbe_tmp__474;
  goto llvm_cbe_tmp__522;

llvm_cbe_tmp__522:
  llvm_cbe_tmp__475 = *(&llvm_cbe_cppVar_535);
  *(&llvm_cbe_cppVar_531) = llvm_cbe_tmp__475;
  goto llvm_cbe_tmp__523;

llvm_cbe_tmp__519:
  llvm_cbe_tmp__476 = *((&llvm_cbe_tmp__442->field15));
  *(&llvm_cbe_cppVar_540) = (((unsigned char )(bool )(llvm_cbe_tmp__476 == 2ull)));
  llvm_cbe_tmp__477 = *(&llvm_cbe_cppVar_519);
  if ((((((bool )llvm_cbe_tmp__477&1u))&1))) {
    goto llvm_cbe_tmp__524;
  } else {
    llvm_cbe_tmp__480__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__525;
  }

llvm_cbe_tmp__524:
  llvm_cbe_tmp__478 = *(&llvm_cbe_cppVar_540);
  llvm_cbe_tmp__479 = ((((bool )llvm_cbe_tmp__478&1u))&1);
  llvm_cbe_tmp__480__PHI_TEMPORARY = llvm_cbe_tmp__479;   /* for PHI node */
  goto llvm_cbe_tmp__525;

llvm_cbe_tmp__525:
  llvm_cbe_tmp__480 = ((llvm_cbe_tmp__480__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_541) = (((unsigned char )(bool )llvm_cbe_tmp__480));
  llvm_cbe_tmp__481 = *(&llvm_cbe_cppVar_541);
  if ((((((bool )llvm_cbe_tmp__481&1u))&1))) {
    goto llvm_cbe_tmp__526;
  } else {
    goto llvm_cbe_tmp__527;
  }

llvm_cbe_tmp__526:
  llvm_cbe_tmp__482 = *(&llvm_cbe_cppVar_535);
  *(&llvm_cbe_cppVar_538) = llvm_cbe_tmp__482;
  goto llvm_cbe_tmp__528;

llvm_cbe_tmp__527:
  llvm_cbe_tmp__483 = *((&llvm_cbe_tmp__442->field15));
  *(&llvm_cbe_cppVar_544) = (((unsigned char )(bool )(llvm_cbe_tmp__483 == 3ull)));
  llvm_cbe_tmp__484 = *(&llvm_cbe_cppVar_519);
  if ((((((bool )llvm_cbe_tmp__484&1u))&1))) {
    goto llvm_cbe_tmp__529;
  } else {
    llvm_cbe_tmp__487__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__530;
  }

llvm_cbe_tmp__529:
  llvm_cbe_tmp__485 = *(&llvm_cbe_cppVar_544);
  llvm_cbe_tmp__486 = ((((bool )llvm_cbe_tmp__485&1u))&1);
  llvm_cbe_tmp__487__PHI_TEMPORARY = llvm_cbe_tmp__486;   /* for PHI node */
  goto llvm_cbe_tmp__530;

llvm_cbe_tmp__530:
  llvm_cbe_tmp__487 = ((llvm_cbe_tmp__487__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_545) = (((unsigned char )(bool )llvm_cbe_tmp__487));
  llvm_cbe_tmp__488 = *(&llvm_cbe_cppVar_545);
  if ((((((bool )llvm_cbe_tmp__488&1u))&1))) {
    goto llvm_cbe_tmp__531;
  } else {
    goto llvm_cbe_tmp__532;
  }

llvm_cbe_tmp__531:
  llvm_cbe_tmp__489 = *(&llvm_cbe_cppVar_535);
  *(&llvm_cbe_cppVar_542) = llvm_cbe_tmp__489;
  goto llvm_cbe_tmp__533;

llvm_cbe_tmp__532:
  llvm_cbe_tmp__490 = *((&llvm_cbe_tmp__442->field7));
  *(&llvm_cbe_cppVar_542) = llvm_cbe_tmp__490;
  goto llvm_cbe_tmp__533;

llvm_cbe_tmp__533:
  llvm_cbe_tmp__491 = *(&llvm_cbe_cppVar_542);
  *(&llvm_cbe_cppVar_538) = llvm_cbe_tmp__491;
  goto llvm_cbe_tmp__528;

llvm_cbe_tmp__528:
  llvm_cbe_tmp__492 = *(&llvm_cbe_cppVar_538);
  *(&llvm_cbe_cppVar_531) = llvm_cbe_tmp__492;
  goto llvm_cbe_tmp__523;

llvm_cbe_tmp__523:
  llvm_cbe_tmp__493 = *(&llvm_cbe_cppVar_531);
  *(&llvm_cbe_cppVar_520) = llvm_cbe_tmp__493;
  goto llvm_cbe_tmp__515;

llvm_cbe_tmp__515:
  llvm_cbe_tmp__494 = *(&llvm_cbe_cppVar_520);
  *(&llvm_cbe_cppVar_517) = llvm_cbe_tmp__494;
  goto llvm_cbe_tmp__534;

llvm_cbe_tmp__504:
  llvm_cbe_tmp__495 = *((&llvm_cbe_tmp__442->field29));
  *(&llvm_cbe_cppVar_548) = (((unsigned char )(bool )(llvm_cbe_tmp__495 == 2ull)));
  llvm_cbe_tmp__496 = *((&llvm_cbe_tmp__442->field7));
  *(&llvm_cbe_cppVar_546) = llvm_cbe_tmp__496;
  llvm_cbe_tmp__497 = *(&llvm_cbe_cppVar_546);
  *(&llvm_cbe_cppVar_517) = llvm_cbe_tmp__497;
  goto llvm_cbe_tmp__534;

llvm_cbe_tmp__534:
  llvm_cbe_tmp__498 = *(&llvm_cbe_cppVar_517);
  *(&llvm_cbe_cppVar_513) = llvm_cbe_tmp__498;
  goto llvm_cbe_tmp__502;

llvm_cbe_tmp__502:
  llvm_cbe_tmp__499 = *(&llvm_cbe_cppVar_513);
  return llvm_cbe_tmp__499;
}


unsigned long long _ZN11model_train23cppUpdateFun_loop_countElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__535;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__536;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__537;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__538;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__539;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__540;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__541;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__542;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__543;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__544;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__545;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__546;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__547;
  unsigned long long llvm_cbe_tmp__548;
  unsigned char llvm_cbe_tmp__549;
  unsigned long long llvm_cbe_tmp__550;
  unsigned long long llvm_cbe_tmp__551;
  unsigned char llvm_cbe_tmp__552;
  unsigned long long llvm_cbe_tmp__553;
  unsigned long long llvm_cbe_tmp__554;
  unsigned char llvm_cbe_tmp__555;
  unsigned long long llvm_cbe_tmp__556;
  unsigned long long llvm_cbe_tmp__557;
  unsigned long long llvm_cbe_tmp__558;
  unsigned long long llvm_cbe_tmp__559;
  unsigned char llvm_cbe_tmp__560;
  unsigned char llvm_cbe_tmp__561;
  bool llvm_cbe_tmp__562;
  bool llvm_cbe_tmp__563;
  bool llvm_cbe_tmp__563__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__564;
  unsigned long long llvm_cbe_tmp__565;
  unsigned long long llvm_cbe_tmp__566;
  unsigned long long llvm_cbe_tmp__567;
  unsigned long long llvm_cbe_tmp__568;
  unsigned char llvm_cbe_tmp__569;
  unsigned char llvm_cbe_tmp__570;
  bool llvm_cbe_tmp__571;
  bool llvm_cbe_tmp__572;
  bool llvm_cbe_tmp__572__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__573;
  unsigned long long llvm_cbe_tmp__574;
  unsigned char llvm_cbe_tmp__575;
  unsigned char llvm_cbe_tmp__576;
  bool llvm_cbe_tmp__577;
  bool llvm_cbe_tmp__578;
  bool llvm_cbe_tmp__578__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__579;
  unsigned long long llvm_cbe_tmp__580;
  unsigned long long llvm_cbe_tmp__581;
  unsigned long long llvm_cbe_tmp__582;
  unsigned long long llvm_cbe_tmp__583;
  unsigned long long llvm_cbe_tmp__584;
  unsigned long long llvm_cbe_tmp__585;
  unsigned long long llvm_cbe_tmp__586;
  unsigned long long llvm_cbe_tmp__587;
  unsigned long long llvm_cbe_tmp__588;

  *(&llvm_cbe_tmp__535) = llvm_cbe_this;
  *(&llvm_cbe_tmp__536) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__537) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__538) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__539) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__540) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__541) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__542) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__543) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__544) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__545) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__546) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__547 = *(&llvm_cbe_tmp__535);
  llvm_cbe_tmp__548 = *((&llvm_cbe_tmp__547->field29));
  *(&llvm_cbe_cppVar_552) = (((unsigned char )(bool )(llvm_cbe_tmp__548 == 0ull)));
  llvm_cbe_tmp__549 = *(&llvm_cbe_cppVar_552);
  if ((((((bool )llvm_cbe_tmp__549&1u))&1))) {
    goto llvm_cbe_tmp__589;
  } else {
    goto llvm_cbe_tmp__590;
  }

llvm_cbe_tmp__589:
  llvm_cbe_tmp__550 = *((&llvm_cbe_tmp__547->field8));
  *(&llvm_cbe_cppVar_550) = llvm_cbe_tmp__550;
  goto llvm_cbe_tmp__591;

llvm_cbe_tmp__590:
  llvm_cbe_tmp__551 = *((&llvm_cbe_tmp__547->field29));
  *(&llvm_cbe_cppVar_555) = (((unsigned char )(bool )(llvm_cbe_tmp__551 == 1ull)));
  llvm_cbe_tmp__552 = *(&llvm_cbe_cppVar_555);
  if ((((((bool )llvm_cbe_tmp__552&1u))&1))) {
    goto llvm_cbe_tmp__592;
  } else {
    goto llvm_cbe_tmp__593;
  }

llvm_cbe_tmp__592:
  llvm_cbe_tmp__553 = *((&llvm_cbe_tmp__547->field8));
  *(&llvm_cbe_cppVar_553) = llvm_cbe_tmp__553;
  goto llvm_cbe_tmp__594;

llvm_cbe_tmp__593:
  llvm_cbe_tmp__554 = *((&llvm_cbe_tmp__547->field29));
  *(&llvm_cbe_cppVar_558) = (((unsigned char )(bool )(llvm_cbe_tmp__554 == 2ull)));
  llvm_cbe_tmp__555 = *(&llvm_cbe_cppVar_558);
  if ((((((bool )llvm_cbe_tmp__555&1u))&1))) {
    goto llvm_cbe_tmp__595;
  } else {
    goto llvm_cbe_tmp__596;
  }

llvm_cbe_tmp__595:
  llvm_cbe_tmp__556 = *((&llvm_cbe_tmp__547->field25));
  llvm_cbe_tmp__557 = *((&llvm_cbe_tmp__547->field9));
  *(&llvm_cbe_cppVar_560) = (((unsigned char )(bool )(llvm_cbe_tmp__556 == llvm_cbe_tmp__557)));
  llvm_cbe_tmp__558 = *((&llvm_cbe_tmp__547->field30));
  llvm_cbe_tmp__559 = *((&llvm_cbe_tmp__547->field14));
  *(&llvm_cbe_cppVar_561) = (((unsigned char )(bool )(llvm_cbe_tmp__558 == llvm_cbe_tmp__559)));
  llvm_cbe_tmp__560 = *(&llvm_cbe_cppVar_560);
  if ((((((bool )llvm_cbe_tmp__560&1u))&1))) {
    goto llvm_cbe_tmp__597;
  } else {
    llvm_cbe_tmp__563__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__598;
  }

llvm_cbe_tmp__597:
  llvm_cbe_tmp__561 = *(&llvm_cbe_cppVar_561);
  llvm_cbe_tmp__562 = ((((bool )llvm_cbe_tmp__561&1u))&1);
  llvm_cbe_tmp__563__PHI_TEMPORARY = llvm_cbe_tmp__562;   /* for PHI node */
  goto llvm_cbe_tmp__598;

llvm_cbe_tmp__598:
  llvm_cbe_tmp__563 = ((llvm_cbe_tmp__563__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_562) = (((unsigned char )(bool )llvm_cbe_tmp__563));
  llvm_cbe_tmp__564 = *((&llvm_cbe_tmp__547->field13));
  *(&llvm_cbe_cppVar_564) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__564) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__565 = *(&llvm_cbe_cppVar_564);
  llvm_cbe_tmp__566 = *((&llvm_cbe_tmp__547->field39));
  *(&llvm_cbe_cppVar_564) = (llvm_cbe_tmp__565 & llvm_cbe_tmp__566);
  llvm_cbe_tmp__567 = *((&llvm_cbe_tmp__547->field5));
  llvm_cbe_tmp__568 = *(&llvm_cbe_cppVar_564);
  *(&llvm_cbe_cppVar_565) = (((unsigned char )(bool )(llvm_cbe_tmp__567 == llvm_cbe_tmp__568)));
  llvm_cbe_tmp__569 = *(&llvm_cbe_cppVar_562);
  if ((((((bool )llvm_cbe_tmp__569&1u))&1))) {
    goto llvm_cbe_tmp__599;
  } else {
    llvm_cbe_tmp__572__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__600;
  }

llvm_cbe_tmp__599:
  llvm_cbe_tmp__570 = *(&llvm_cbe_cppVar_565);
  llvm_cbe_tmp__571 = ((((bool )llvm_cbe_tmp__570&1u))&1);
  llvm_cbe_tmp__572__PHI_TEMPORARY = llvm_cbe_tmp__571;   /* for PHI node */
  goto llvm_cbe_tmp__600;

llvm_cbe_tmp__600:
  llvm_cbe_tmp__572 = ((llvm_cbe_tmp__572__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_566) = (((unsigned char )(bool )llvm_cbe_tmp__572));
  llvm_cbe_tmp__573 = *((&llvm_cbe_tmp__547->field8));
  llvm_cbe_tmp__574 = *((&llvm_cbe_tmp__547->field10));
  *(&llvm_cbe_cppVar_567) = (((unsigned char )(bool )(llvm_cbe_tmp__573 != llvm_cbe_tmp__574)));
  llvm_cbe_tmp__575 = *(&llvm_cbe_cppVar_566);
  if ((((((bool )llvm_cbe_tmp__575&1u))&1))) {
    goto llvm_cbe_tmp__601;
  } else {
    llvm_cbe_tmp__578__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__602;
  }

llvm_cbe_tmp__601:
  llvm_cbe_tmp__576 = *(&llvm_cbe_cppVar_567);
  llvm_cbe_tmp__577 = ((((bool )llvm_cbe_tmp__576&1u))&1);
  llvm_cbe_tmp__578__PHI_TEMPORARY = llvm_cbe_tmp__577;   /* for PHI node */
  goto llvm_cbe_tmp__602;

llvm_cbe_tmp__602:
  llvm_cbe_tmp__578 = ((llvm_cbe_tmp__578__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_568) = (((unsigned char )(bool )llvm_cbe_tmp__578));
  llvm_cbe_tmp__579 = *(&llvm_cbe_cppVar_568);
  llvm_cbe_tmp__580 = *((&llvm_cbe_tmp__547->field8));
  if ((((((bool )llvm_cbe_tmp__579&1u))&1))) {
    goto llvm_cbe_tmp__603;
  } else {
    goto llvm_cbe_tmp__604;
  }

llvm_cbe_tmp__603:
  *(&llvm_cbe_cppVar_570) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__580) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__581 = *(&llvm_cbe_cppVar_570);
  llvm_cbe_tmp__582 = *((&llvm_cbe_tmp__547->field39));
  *(&llvm_cbe_cppVar_570) = (llvm_cbe_tmp__581 & llvm_cbe_tmp__582);
  llvm_cbe_tmp__583 = *(&llvm_cbe_cppVar_570);
  *(&llvm_cbe_cppVar_559) = llvm_cbe_tmp__583;
  goto llvm_cbe_tmp__605;

llvm_cbe_tmp__604:
  *(&llvm_cbe_cppVar_559) = llvm_cbe_tmp__580;
  goto llvm_cbe_tmp__605;

llvm_cbe_tmp__605:
  llvm_cbe_tmp__584 = *(&llvm_cbe_cppVar_559);
  *(&llvm_cbe_cppVar_556) = llvm_cbe_tmp__584;
  goto llvm_cbe_tmp__606;

llvm_cbe_tmp__596:
  llvm_cbe_tmp__585 = *((&llvm_cbe_tmp__547->field8));
  *(&llvm_cbe_cppVar_556) = llvm_cbe_tmp__585;
  goto llvm_cbe_tmp__606;

llvm_cbe_tmp__606:
  llvm_cbe_tmp__586 = *(&llvm_cbe_cppVar_556);
  *(&llvm_cbe_cppVar_553) = llvm_cbe_tmp__586;
  goto llvm_cbe_tmp__594;

llvm_cbe_tmp__594:
  llvm_cbe_tmp__587 = *(&llvm_cbe_cppVar_553);
  *(&llvm_cbe_cppVar_550) = llvm_cbe_tmp__587;
  goto llvm_cbe_tmp__591;

llvm_cbe_tmp__591:
  llvm_cbe_tmp__588 = *(&llvm_cbe_cppVar_550);
  return llvm_cbe_tmp__588;
}


unsigned long long _ZN11model_train21cppUpdateFun_per_v_pcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__607;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__608;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__609;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__610;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__611;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__612;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__613;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__614;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__615;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__616;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__617;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__618;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__619;
  unsigned long long llvm_cbe_tmp__620;
  unsigned char llvm_cbe_tmp__621;
  unsigned long long llvm_cbe_tmp__622;
  unsigned char llvm_cbe_tmp__623;
  unsigned long long llvm_cbe_tmp__624;
  unsigned char llvm_cbe_tmp__625;
  unsigned char llvm_cbe_tmp__626;
  bool llvm_cbe_tmp__627;
  bool llvm_cbe_tmp__628;
  bool llvm_cbe_tmp__628__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__629;
  unsigned long long llvm_cbe_tmp__630;
  unsigned long long llvm_cbe_tmp__631;
  unsigned long long llvm_cbe_tmp__632;
  unsigned char llvm_cbe_tmp__633;
  unsigned char llvm_cbe_tmp__634;
  bool llvm_cbe_tmp__635;
  bool llvm_cbe_tmp__636;
  bool llvm_cbe_tmp__636__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__637;
  unsigned long long llvm_cbe_tmp__638;
  unsigned long long llvm_cbe_tmp__639;
  unsigned long long llvm_cbe_tmp__640;
  unsigned char llvm_cbe_tmp__641;
  unsigned char llvm_cbe_tmp__642;
  bool llvm_cbe_tmp__643;
  bool llvm_cbe_tmp__644;
  bool llvm_cbe_tmp__644__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__645;
  unsigned char llvm_cbe_tmp__646;
  unsigned long long llvm_cbe_tmp__647;
  unsigned long long llvm_cbe_tmp__648;
  unsigned long long llvm_cbe_tmp__649;
  unsigned char llvm_cbe_tmp__650;
  unsigned char llvm_cbe_tmp__651;
  bool llvm_cbe_tmp__652;
  bool llvm_cbe_tmp__653;
  bool llvm_cbe_tmp__653__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__654;
  unsigned char llvm_cbe_tmp__655;
  unsigned long long llvm_cbe_tmp__656;
  unsigned long long llvm_cbe_tmp__657;
  unsigned long long llvm_cbe_tmp__658;
  unsigned char llvm_cbe_tmp__659;
  unsigned char llvm_cbe_tmp__660;
  bool llvm_cbe_tmp__661;
  bool llvm_cbe_tmp__662;
  bool llvm_cbe_tmp__662__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__663;
  unsigned char llvm_cbe_tmp__664;
  unsigned long long llvm_cbe_tmp__665;
  unsigned long long llvm_cbe_tmp__666;
  unsigned long long llvm_cbe_tmp__667;
  unsigned long long llvm_cbe_tmp__668;
  unsigned long long llvm_cbe_tmp__669;
  unsigned long long llvm_cbe_tmp__670;
  unsigned long long llvm_cbe_tmp__671;
  unsigned long long llvm_cbe_tmp__672;
  unsigned long long llvm_cbe_tmp__673;
  unsigned char llvm_cbe_tmp__674;
  unsigned char llvm_cbe_tmp__675;
  bool llvm_cbe_tmp__676;
  bool llvm_cbe_tmp__677;
  bool llvm_cbe_tmp__677__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__678;
  unsigned long long llvm_cbe_tmp__679;
  unsigned long long llvm_cbe_tmp__680;
  unsigned long long llvm_cbe_tmp__681;
  unsigned long long llvm_cbe_tmp__682;
  unsigned long long llvm_cbe_tmp__683;
  unsigned long long llvm_cbe_tmp__684;
  unsigned long long llvm_cbe_tmp__685;
  unsigned long long llvm_cbe_tmp__686;
  unsigned long long llvm_cbe_tmp__687;
  unsigned long long llvm_cbe_tmp__688;
  unsigned long long llvm_cbe_tmp__689;
  unsigned long long llvm_cbe_tmp__690;

  *(&llvm_cbe_tmp__607) = llvm_cbe_this;
  *(&llvm_cbe_tmp__608) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__609) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__610) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__611) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__612) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__613) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__614) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__615) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__616) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__617) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__618) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__619 = *(&llvm_cbe_tmp__607);
  llvm_cbe_tmp__620 = *((&llvm_cbe_tmp__619->field29));
  *(&llvm_cbe_cppVar_574) = (((unsigned char )(bool )(llvm_cbe_tmp__620 == 0ull)));
  llvm_cbe_tmp__621 = *(&llvm_cbe_cppVar_574);
  if ((((((bool )llvm_cbe_tmp__621&1u))&1))) {
    goto llvm_cbe_tmp__691;
  } else {
    goto llvm_cbe_tmp__692;
  }

llvm_cbe_tmp__691:
  *(&llvm_cbe_cppVar_572) = 0ull;
  goto llvm_cbe_tmp__693;

llvm_cbe_tmp__692:
  llvm_cbe_tmp__622 = *((&llvm_cbe_tmp__619->field29));
  *(&llvm_cbe_cppVar_578) = (((unsigned char )(bool )(llvm_cbe_tmp__622 == 1ull)));
  llvm_cbe_tmp__623 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__623&1u))&1))) {
    goto llvm_cbe_tmp__694;
  } else {
    goto llvm_cbe_tmp__695;
  }

llvm_cbe_tmp__694:
  llvm_cbe_tmp__624 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_581) = (((unsigned char )(bool )(llvm_cbe_tmp__624 == 0ull)));
  llvm_cbe_tmp__625 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__625&1u))&1))) {
    goto llvm_cbe_tmp__696;
  } else {
    llvm_cbe_tmp__628__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__697;
  }

llvm_cbe_tmp__696:
  llvm_cbe_tmp__626 = *(&llvm_cbe_cppVar_581);
  llvm_cbe_tmp__627 = ((((bool )llvm_cbe_tmp__626&1u))&1);
  llvm_cbe_tmp__628__PHI_TEMPORARY = llvm_cbe_tmp__627;   /* for PHI node */
  goto llvm_cbe_tmp__697;

llvm_cbe_tmp__697:
  llvm_cbe_tmp__628 = ((llvm_cbe_tmp__628__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_582) = (((unsigned char )(bool )llvm_cbe_tmp__628));
  llvm_cbe_tmp__629 = *(&llvm_cbe_cppVar_582);
  if ((((((bool )llvm_cbe_tmp__629&1u))&1))) {
    goto llvm_cbe_tmp__698;
  } else {
    goto llvm_cbe_tmp__699;
  }

llvm_cbe_tmp__698:
  llvm_cbe_tmp__630 = *((&llvm_cbe_tmp__619->field7));
  *(&llvm_cbe_cppVar_585) = (((unsigned char )(bool )(llvm_cbe_tmp__630 == 4ull)));
  llvm_cbe_tmp__631 = *((&llvm_cbe_tmp__619->field25));
  llvm_cbe_tmp__632 = *((&llvm_cbe_tmp__619->field9));
  *(&llvm_cbe_cppVar_586) = (((unsigned char )(bool )(llvm_cbe_tmp__631 == llvm_cbe_tmp__632)));
  llvm_cbe_tmp__633 = *(&llvm_cbe_cppVar_585);
  if ((((((bool )llvm_cbe_tmp__633&1u))&1))) {
    goto llvm_cbe_tmp__700;
  } else {
    llvm_cbe_tmp__636__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__701;
  }

llvm_cbe_tmp__700:
  llvm_cbe_tmp__634 = *(&llvm_cbe_cppVar_586);
  llvm_cbe_tmp__635 = ((((bool )llvm_cbe_tmp__634&1u))&1);
  llvm_cbe_tmp__636__PHI_TEMPORARY = llvm_cbe_tmp__635;   /* for PHI node */
  goto llvm_cbe_tmp__701;

llvm_cbe_tmp__701:
  llvm_cbe_tmp__636 = ((llvm_cbe_tmp__636__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_587) = (((unsigned char )(bool )llvm_cbe_tmp__636));
  llvm_cbe_tmp__637 = *(&llvm_cbe_cppVar_587);
  if ((((((bool )llvm_cbe_tmp__637&1u))&1))) {
    goto llvm_cbe_tmp__702;
  } else {
    goto llvm_cbe_tmp__703;
  }

llvm_cbe_tmp__702:
  *(&llvm_cbe_cppVar_583) = 1ull;
  goto llvm_cbe_tmp__704;

llvm_cbe_tmp__703:
  llvm_cbe_tmp__638 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_583) = llvm_cbe_tmp__638;
  goto llvm_cbe_tmp__704;

llvm_cbe_tmp__704:
  llvm_cbe_tmp__639 = *(&llvm_cbe_cppVar_583);
  *(&llvm_cbe_cppVar_579) = llvm_cbe_tmp__639;
  goto llvm_cbe_tmp__705;

llvm_cbe_tmp__699:
  llvm_cbe_tmp__640 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_591) = (((unsigned char )(bool )(llvm_cbe_tmp__640 == 1ull)));
  llvm_cbe_tmp__641 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__641&1u))&1))) {
    goto llvm_cbe_tmp__706;
  } else {
    llvm_cbe_tmp__644__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__707;
  }

llvm_cbe_tmp__706:
  llvm_cbe_tmp__642 = *(&llvm_cbe_cppVar_591);
  llvm_cbe_tmp__643 = ((((bool )llvm_cbe_tmp__642&1u))&1);
  llvm_cbe_tmp__644__PHI_TEMPORARY = llvm_cbe_tmp__643;   /* for PHI node */
  goto llvm_cbe_tmp__707;

llvm_cbe_tmp__707:
  llvm_cbe_tmp__644 = ((llvm_cbe_tmp__644__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_592) = (((unsigned char )(bool )llvm_cbe_tmp__644));
  llvm_cbe_tmp__645 = *(&llvm_cbe_cppVar_592);
  if ((((((bool )llvm_cbe_tmp__645&1u))&1))) {
    goto llvm_cbe_tmp__708;
  } else {
    goto llvm_cbe_tmp__709;
  }

llvm_cbe_tmp__708:
  llvm_cbe_tmp__646 = *(&llvm_cbe_cppVar_585);
  if ((((((bool )llvm_cbe_tmp__646&1u))&1))) {
    goto llvm_cbe_tmp__710;
  } else {
    goto llvm_cbe_tmp__711;
  }

llvm_cbe_tmp__710:
  *(&llvm_cbe_cppVar_593) = 2ull;
  goto llvm_cbe_tmp__712;

llvm_cbe_tmp__711:
  llvm_cbe_tmp__647 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_593) = llvm_cbe_tmp__647;
  goto llvm_cbe_tmp__712;

llvm_cbe_tmp__712:
  llvm_cbe_tmp__648 = *(&llvm_cbe_cppVar_593);
  *(&llvm_cbe_cppVar_589) = llvm_cbe_tmp__648;
  goto llvm_cbe_tmp__713;

llvm_cbe_tmp__709:
  llvm_cbe_tmp__649 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_597) = (((unsigned char )(bool )(llvm_cbe_tmp__649 == 2ull)));
  llvm_cbe_tmp__650 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__650&1u))&1))) {
    goto llvm_cbe_tmp__714;
  } else {
    llvm_cbe_tmp__653__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__715;
  }

llvm_cbe_tmp__714:
  llvm_cbe_tmp__651 = *(&llvm_cbe_cppVar_597);
  llvm_cbe_tmp__652 = ((((bool )llvm_cbe_tmp__651&1u))&1);
  llvm_cbe_tmp__653__PHI_TEMPORARY = llvm_cbe_tmp__652;   /* for PHI node */
  goto llvm_cbe_tmp__715;

llvm_cbe_tmp__715:
  llvm_cbe_tmp__653 = ((llvm_cbe_tmp__653__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_598) = (((unsigned char )(bool )llvm_cbe_tmp__653));
  llvm_cbe_tmp__654 = *(&llvm_cbe_cppVar_598);
  if ((((((bool )llvm_cbe_tmp__654&1u))&1))) {
    goto llvm_cbe_tmp__716;
  } else {
    goto llvm_cbe_tmp__717;
  }

llvm_cbe_tmp__716:
  llvm_cbe_tmp__655 = *(&llvm_cbe_cppVar_585);
  if ((((((bool )llvm_cbe_tmp__655&1u))&1))) {
    goto llvm_cbe_tmp__718;
  } else {
    goto llvm_cbe_tmp__719;
  }

llvm_cbe_tmp__718:
  *(&llvm_cbe_cppVar_599) = 3ull;
  goto llvm_cbe_tmp__720;

llvm_cbe_tmp__719:
  llvm_cbe_tmp__656 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_599) = llvm_cbe_tmp__656;
  goto llvm_cbe_tmp__720;

llvm_cbe_tmp__720:
  llvm_cbe_tmp__657 = *(&llvm_cbe_cppVar_599);
  *(&llvm_cbe_cppVar_595) = llvm_cbe_tmp__657;
  goto llvm_cbe_tmp__721;

llvm_cbe_tmp__717:
  llvm_cbe_tmp__658 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_603) = (((unsigned char )(bool )(llvm_cbe_tmp__658 == 3ull)));
  llvm_cbe_tmp__659 = *(&llvm_cbe_cppVar_578);
  if ((((((bool )llvm_cbe_tmp__659&1u))&1))) {
    goto llvm_cbe_tmp__722;
  } else {
    llvm_cbe_tmp__662__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__723;
  }

llvm_cbe_tmp__722:
  llvm_cbe_tmp__660 = *(&llvm_cbe_cppVar_603);
  llvm_cbe_tmp__661 = ((((bool )llvm_cbe_tmp__660&1u))&1);
  llvm_cbe_tmp__662__PHI_TEMPORARY = llvm_cbe_tmp__661;   /* for PHI node */
  goto llvm_cbe_tmp__723;

llvm_cbe_tmp__723:
  llvm_cbe_tmp__662 = ((llvm_cbe_tmp__662__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_604) = (((unsigned char )(bool )llvm_cbe_tmp__662));
  llvm_cbe_tmp__663 = *(&llvm_cbe_cppVar_604);
  if ((((((bool )llvm_cbe_tmp__663&1u))&1))) {
    goto llvm_cbe_tmp__724;
  } else {
    goto llvm_cbe_tmp__725;
  }

llvm_cbe_tmp__724:
  llvm_cbe_tmp__664 = *(&llvm_cbe_cppVar_585);
  if ((((((bool )llvm_cbe_tmp__664&1u))&1))) {
    goto llvm_cbe_tmp__726;
  } else {
    goto llvm_cbe_tmp__727;
  }

llvm_cbe_tmp__726:
  llvm_cbe_tmp__665 = *((&llvm_cbe_tmp__619->field30));
  *(&llvm_cbe_cppVar_608) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__665) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__666 = *(&llvm_cbe_cppVar_608);
  llvm_cbe_tmp__667 = *((&llvm_cbe_tmp__619->field39));
  *(&llvm_cbe_cppVar_608) = (llvm_cbe_tmp__666 & llvm_cbe_tmp__667);
  llvm_cbe_tmp__668 = *(&llvm_cbe_cppVar_608);
  llvm_cbe_tmp__669 = *((&llvm_cbe_tmp__619->field14));
  *(&llvm_cbe_cppVar_609) = (((unsigned char )(bool )(llvm_cbe_tmp__668 == llvm_cbe_tmp__669)));
  llvm_cbe_tmp__670 = *((&llvm_cbe_tmp__619->field30));
  *(&llvm_cbe_cppVar_611) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__670) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__671 = *(&llvm_cbe_cppVar_611);
  llvm_cbe_tmp__672 = *((&llvm_cbe_tmp__619->field39));
  *(&llvm_cbe_cppVar_611) = (llvm_cbe_tmp__671 & llvm_cbe_tmp__672);
  llvm_cbe_tmp__673 = *(&llvm_cbe_cppVar_611);
  *(&llvm_cbe_cppVar_613) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__673) >= ((signed long long )500ull))));
  llvm_cbe_tmp__674 = *(&llvm_cbe_cppVar_609);
  if ((((((bool )llvm_cbe_tmp__674&1u))&1))) {
    llvm_cbe_tmp__677__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__728;
  } else {
    goto llvm_cbe_tmp__729;
  }

llvm_cbe_tmp__729:
  llvm_cbe_tmp__675 = *(&llvm_cbe_cppVar_613);
  llvm_cbe_tmp__676 = ((((bool )llvm_cbe_tmp__675&1u))&1);
  llvm_cbe_tmp__677__PHI_TEMPORARY = llvm_cbe_tmp__676;   /* for PHI node */
  goto llvm_cbe_tmp__728;

llvm_cbe_tmp__728:
  llvm_cbe_tmp__677 = ((llvm_cbe_tmp__677__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_614) = (((unsigned char )(bool )llvm_cbe_tmp__677));
  *(&llvm_cbe_cppVar_606) = 0ull;
  llvm_cbe_tmp__678 = *(&llvm_cbe_cppVar_606);
  *(&llvm_cbe_cppVar_605) = llvm_cbe_tmp__678;
  goto llvm_cbe_tmp__730;

llvm_cbe_tmp__727:
  llvm_cbe_tmp__679 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_605) = llvm_cbe_tmp__679;
  goto llvm_cbe_tmp__730;

llvm_cbe_tmp__730:
  llvm_cbe_tmp__680 = *(&llvm_cbe_cppVar_605);
  *(&llvm_cbe_cppVar_601) = llvm_cbe_tmp__680;
  goto llvm_cbe_tmp__731;

llvm_cbe_tmp__725:
  llvm_cbe_tmp__681 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_601) = llvm_cbe_tmp__681;
  goto llvm_cbe_tmp__731;

llvm_cbe_tmp__731:
  llvm_cbe_tmp__682 = *(&llvm_cbe_cppVar_601);
  *(&llvm_cbe_cppVar_595) = llvm_cbe_tmp__682;
  goto llvm_cbe_tmp__721;

llvm_cbe_tmp__721:
  llvm_cbe_tmp__683 = *(&llvm_cbe_cppVar_595);
  *(&llvm_cbe_cppVar_589) = llvm_cbe_tmp__683;
  goto llvm_cbe_tmp__713;

llvm_cbe_tmp__713:
  llvm_cbe_tmp__684 = *(&llvm_cbe_cppVar_589);
  *(&llvm_cbe_cppVar_579) = llvm_cbe_tmp__684;
  goto llvm_cbe_tmp__705;

llvm_cbe_tmp__705:
  llvm_cbe_tmp__685 = *(&llvm_cbe_cppVar_579);
  *(&llvm_cbe_cppVar_576) = llvm_cbe_tmp__685;
  goto llvm_cbe_tmp__732;

llvm_cbe_tmp__695:
  llvm_cbe_tmp__686 = *((&llvm_cbe_tmp__619->field29));
  *(&llvm_cbe_cppVar_617) = (((unsigned char )(bool )(llvm_cbe_tmp__686 == 2ull)));
  llvm_cbe_tmp__687 = *((&llvm_cbe_tmp__619->field15));
  *(&llvm_cbe_cppVar_615) = llvm_cbe_tmp__687;
  llvm_cbe_tmp__688 = *(&llvm_cbe_cppVar_615);
  *(&llvm_cbe_cppVar_576) = llvm_cbe_tmp__688;
  goto llvm_cbe_tmp__732;

llvm_cbe_tmp__732:
  llvm_cbe_tmp__689 = *(&llvm_cbe_cppVar_576);
  *(&llvm_cbe_cppVar_572) = llvm_cbe_tmp__689;
  goto llvm_cbe_tmp__693;

llvm_cbe_tmp__693:
  llvm_cbe_tmp__690 = *(&llvm_cbe_cppVar_572);
  return llvm_cbe_tmp__690;
}


struct l_class_OC_SysCArray1D _ZN11model_train16cppUpdateFun_posElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__733;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__734;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__735;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__736;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__737;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__738;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__739;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__740;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__741;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__742;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__743;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__744;    /* Address-exposed local */
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
  bool llvm_cbe_tmp__745;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__746;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__747;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__748;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__749;
  unsigned long long llvm_cbe_tmp__750;
  unsigned char llvm_cbe_tmp__751;
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
  unsigned char llvm_cbe_tmp__764;
  unsigned long long llvm_cbe_tmp__765;
  unsigned long long llvm_cbe_tmp__766;
  unsigned long long llvm_cbe_tmp__767;
  unsigned long long llvm_cbe_tmp__768;
  unsigned long long llvm_cbe_tmp__769;
  unsigned long long llvm_cbe_tmp__770;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__771;
  unsigned long long llvm_cbe_tmp__772;
  unsigned long long llvm_cbe_tmp__773;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__774;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__775;
  bool llvm_cbe_tmp__776;

  *(&llvm_cbe_tmp__733) = llvm_cbe_this;
  *(&llvm_cbe_tmp__734) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__735) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__736) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__737) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__738) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__739) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__740) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__741) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__742) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__743) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__744) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__749 = *(&llvm_cbe_tmp__733);
  _ZN8type_memIbLj65536EEC1Ev((&llvm_cbe_cppVar_1054));
  *(&llvm_cbe_tmp__745) = ((0) & 1);
  _ZN8type_memIbLj65536EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__750 = *((&llvm_cbe_tmp__749->field29));
  *(&llvm_cbe_cppVar_1040) = (((unsigned char )(bool )(llvm_cbe_tmp__750 == 3ull)));
  llvm_cbe_tmp__751 = *(&llvm_cbe_cppVar_1040);
  if ((((((bool )llvm_cbe_tmp__751&1u))&1))) {
    goto llvm_cbe_tmp__777;
  } else {
    goto llvm_cbe_tmp__778;
  }

llvm_cbe_tmp__777:
  llvm_cbe_tmp__752 = *((&llvm_cbe_tmp__749->field30));
  *(&llvm_cbe_cppVar_1042) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__752))));
  llvm_cbe_tmp__753 = *(&llvm_cbe_cppVar_1042);
  llvm_cbe_tmp__754 = *((&llvm_cbe_tmp__749->field39));
  *(&llvm_cbe_cppVar_1042) = (llvm_cbe_tmp__753 & llvm_cbe_tmp__754);
  llvm_cbe_tmp__755 = *(&llvm_cbe_cppVar_1042);
  llvm_cbe_tmp__756 = *((&llvm_cbe_tmp__749->field25));
  *(&llvm_cbe_cppVar_1043) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__755) + ((unsigned long long )llvm_cbe_tmp__756))));
  llvm_cbe_tmp__757 = *(&llvm_cbe_cppVar_1043);
  llvm_cbe_tmp__758 = *((&llvm_cbe_tmp__749->field39));
  *(&llvm_cbe_cppVar_1043) = (llvm_cbe_tmp__757 & llvm_cbe_tmp__758);
  llvm_cbe_tmp__759 = *((&llvm_cbe_tmp__749->field30));
  llvm_cbe_tmp__760 = *((&llvm_cbe_tmp__749->field45));
  *(&llvm_cbe_cppVar_1045) = ((((signed long long )(((signed long long )llvm_cbe_tmp__759) >> ((signed long long )0ull)))) & llvm_cbe_tmp__760);
  llvm_cbe_tmp__761 = *(&llvm_cbe_cppVar_1045);
  llvm_cbe_tmp__762 = _ZN8type_memIhLj512EE2rdEl(((&llvm_cbe_tmp__749->field0)), llvm_cbe_tmp__761);
  *(&llvm_cbe_cppVar_1046) = llvm_cbe_tmp__762;
  llvm_cbe_tmp__763 = *(&llvm_cbe_cppVar_1046);
  *(&llvm_cbe_cppVar_1048) = (((unsigned char )(bool )(llvm_cbe_tmp__763 != 0ull)));
  llvm_cbe_tmp__764 = *(&llvm_cbe_cppVar_1048);
  if ((((((bool )llvm_cbe_tmp__764&1u))&1))) {
    goto llvm_cbe_tmp__779;
  } else {
    goto llvm_cbe_tmp__780;
  }

llvm_cbe_tmp__779:
  *(&llvm_cbe_cppVar_1044) = 1ull;
  goto llvm_cbe_tmp__781;

llvm_cbe_tmp__780:
  *(&llvm_cbe_cppVar_1044) = 0ull;
  goto llvm_cbe_tmp__781;

llvm_cbe_tmp__781:
  llvm_cbe_tmp__765 = *((&llvm_cbe_tmp__749->field25));
  llvm_cbe_tmp__766 = *((&llvm_cbe_tmp__749->field43));
  *(&llvm_cbe_cppVar_1051) = ((((signed long long )(((signed long long )llvm_cbe_tmp__765) >> ((signed long long )0ull)))) & llvm_cbe_tmp__766);
  llvm_cbe_tmp__767 = *(&llvm_cbe_cppVar_1051);
  llvm_cbe_tmp__768 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__749->field4)), llvm_cbe_tmp__767);
  *(&llvm_cbe_cppVar_1052) = llvm_cbe_tmp__768;
  llvm_cbe_tmp__769 = *(&llvm_cbe_cppVar_1044);
  llvm_cbe_tmp__770 = *(&llvm_cbe_cppVar_1052);
  *(&llvm_cbe_cppVar_1053) = (llvm_cbe_tmp__769 & llvm_cbe_tmp__770);
  llvm_cbe_tmp__771 = _ZN8type_memIbLj65536EEaSERKS0_((&llvm_cbe_cppVar_1054), ((&llvm_cbe_tmp__749->field16)));
  llvm_cbe_tmp__772 = *(&llvm_cbe_cppVar_1043);
  llvm_cbe_tmp__773 = *(&llvm_cbe_cppVar_1053);
  _ZN8type_memIbLj65536EE2wrEll((&llvm_cbe_cppVar_1054), llvm_cbe_tmp__772, llvm_cbe_tmp__773);
  llvm_cbe_tmp__774 = _ZN8type_memIbLj65536EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1054));
  goto llvm_cbe_tmp__782;

llvm_cbe_tmp__778:
  llvm_cbe_tmp__775 = _ZN8type_memIbLj65536EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__749->field16)));
  goto llvm_cbe_tmp__782;

llvm_cbe_tmp__782:
  *(&llvm_cbe_tmp__745) = ((1) & 1);
  *(&llvm_cbe_tmp__748) = 1u;
  llvm_cbe_tmp__776 = ((*(&llvm_cbe_tmp__745))&1);
  if (llvm_cbe_tmp__776) {
    goto llvm_cbe_tmp__783;
  } else {
    goto llvm_cbe_tmp__784;
  }

llvm_cbe_tmp__784:
  _ZN8type_memIbLj65536EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__783;

llvm_cbe_tmp__783:
  _ZN8type_memIbLj65536EED1Ev((&llvm_cbe_cppVar_1054));
  return StructReturn;
}


void _ZN8type_memIbLj65536EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__785;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__786;

  *(&llvm_cbe_tmp__785) = llvm_cbe_this;
  llvm_cbe_tmp__786 = *(&llvm_cbe_tmp__785);
  _ZN8type_memIbLj65536EEC2Ev(llvm_cbe_tmp__786);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIbLj65536EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__787;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__788;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__789;
  unsigned char *llvm_cbe_tmp__790;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__791;
  unsigned char *llvm_cbe_tmp__792;

  *(&llvm_cbe_tmp__787) = llvm_cbe_this;
  *(&llvm_cbe_tmp__788) = llvm_cbe_r;
  llvm_cbe_tmp__789 = *(&llvm_cbe_tmp__787);
  llvm_cbe_tmp__790 = *((&llvm_cbe_tmp__789->field0));
  llvm_cbe_tmp__791 = *(&llvm_cbe_tmp__788);
  llvm_cbe_tmp__792 = *((&llvm_cbe_tmp__791->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__790, llvm_cbe_tmp__792);
  return llvm_cbe_tmp__789;
}


void _ZN8type_memIbLj65536EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__793;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__794;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__795;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__796;
  unsigned long long llvm_cbe_tmp__797;
  unsigned long long llvm_cbe_tmp__798;
  unsigned char *llvm_cbe_tmp__799;

  *(&llvm_cbe_tmp__793) = llvm_cbe_this;
  *(&llvm_cbe_tmp__794) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__795) = llvm_cbe_data;
  llvm_cbe_tmp__796 = *(&llvm_cbe_tmp__793);
  llvm_cbe_tmp__797 = *(&llvm_cbe_tmp__795);
  llvm_cbe_tmp__798 = *(&llvm_cbe_tmp__794);
  llvm_cbe_tmp__799 = *((&llvm_cbe_tmp__796->field0));
  *((&llvm_cbe_tmp__799[((signed long long )llvm_cbe_tmp__798)])) = (((unsigned char )(bool )(llvm_cbe_tmp__797 != 0ull)));
  return;
}


void _ZN8type_memIbLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__800;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__801;

  *(&llvm_cbe_tmp__800) = llvm_cbe_this;
  llvm_cbe_tmp__801 = *(&llvm_cbe_tmp__800);
  _ZN8type_memIbLj65536EED2Ev(llvm_cbe_tmp__801);
  return;
}


struct l_unnamed1 _ZN11model_train17cppUpdateFun_pow2Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_unnamed1 StructReturn;  /* Struct return temporary */
  struct l_unnamed1 *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__802;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__803;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__804;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__805;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__806;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__807;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__808;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__809;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__810;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__811;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__812;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__813;    /* Address-exposed local */
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
  unsigned char *llvm_cbe_tmp__814;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__815;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1070;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1066;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1062;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1083;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1059;    /* Address-exposed local */
  bool llvm_cbe_tmp__816;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__817;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__818;
  unsigned long long llvm_cbe_tmp__819;
  unsigned char llvm_cbe_tmp__820;
  struct l_unnamed1 *llvm_cbe_tmp__821;
  unsigned long long llvm_cbe_tmp__822;
  unsigned char llvm_cbe_tmp__823;
  unsigned long long llvm_cbe_tmp__824;
  unsigned char llvm_cbe_tmp__825;
  unsigned char llvm_cbe_tmp__826;
  bool llvm_cbe_tmp__827;
  bool llvm_cbe_tmp__828;
  bool llvm_cbe_tmp__828__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__829;
  struct l_unnamed1 *llvm_cbe_tmp__830;
  unsigned long long llvm_cbe_tmp__831;
  unsigned char llvm_cbe_tmp__832;
  unsigned char llvm_cbe_tmp__833;
  bool llvm_cbe_tmp__834;
  bool llvm_cbe_tmp__835;
  bool llvm_cbe_tmp__835__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__836;
  struct l_unnamed1 *llvm_cbe_tmp__837;
  unsigned long long llvm_cbe_tmp__838;
  unsigned char llvm_cbe_tmp__839;
  unsigned char llvm_cbe_tmp__840;
  bool llvm_cbe_tmp__841;
  bool llvm_cbe_tmp__842;
  bool llvm_cbe_tmp__842__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__843;
  unsigned long long llvm_cbe_tmp__844;
  unsigned long long llvm_cbe_tmp__845;
  unsigned long long llvm_cbe_tmp__846;
  unsigned long long llvm_cbe_tmp__847;
  unsigned long long llvm_cbe_tmp__848;
  unsigned long long llvm_cbe_tmp__849;
  unsigned long long llvm_cbe_tmp__850;
  unsigned short llvm_cbe_tmp__851;
  struct l_unnamed1 *llvm_cbe_tmp__852;
  unsigned long long llvm_cbe_tmp__853;
  unsigned long long llvm_cbe_tmp__854;
  struct l_unnamed1 *llvm_cbe_tmp__855;
  unsigned long long llvm_cbe_tmp__856;
  unsigned char llvm_cbe_tmp__857;
  unsigned char llvm_cbe_tmp__858;
  bool llvm_cbe_tmp__859;
  bool llvm_cbe_tmp__860;
  bool llvm_cbe_tmp__860__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__861;
  bool llvm_cbe_tmp__862;
  struct l_unnamed1 *llvm_cbe_tmp__863;
  struct l_unnamed1 *llvm_cbe_tmp__864;
  struct l_unnamed1 *llvm_cbe_tmp__865;
  struct l_unnamed1 *llvm_cbe_tmp__866;
  struct l_unnamed1 *llvm_cbe_tmp__867;
  unsigned long long llvm_cbe_tmp__868;
  unsigned char llvm_cbe_tmp__869;
  bool llvm_cbe_tmp__870;
  struct l_unnamed1 *llvm_cbe_tmp__871;
  struct l_unnamed1 *llvm_cbe_tmp__872;
  struct l_unnamed1 *llvm_cbe_tmp__873;
  bool llvm_cbe_tmp__874;

  *(&llvm_cbe_tmp__802) = llvm_cbe_this;
  *(&llvm_cbe_tmp__803) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__804) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__805) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__806) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__807) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__808) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__809) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__810) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__811) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__812) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__813) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__818 = *(&llvm_cbe_tmp__802);
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1078));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1079));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1070));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1066));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1062));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1083));
  _ZN8type_memIjLj8EEC1Ev((&llvm_cbe_cppVar_1059));
  *(&llvm_cbe_tmp__816) = ((0) & 1);
  _ZN8type_memIjLj8EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__819 = *((&llvm_cbe_tmp__818->field29));
  *(&llvm_cbe_cppVar_1058) = (((unsigned char )(bool )(llvm_cbe_tmp__819 == 0ull)));
  llvm_cbe_tmp__820 = *(&llvm_cbe_cppVar_1058);
  if ((((((bool )llvm_cbe_tmp__820&1u))&1))) {
    goto llvm_cbe_tmp__875;
  } else {
    goto llvm_cbe_tmp__876;
  }

llvm_cbe_tmp__875:
  llvm_cbe_tmp__821 = _ZN8type_memIjLj8EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__818->field17)));
  goto llvm_cbe_tmp__877;

llvm_cbe_tmp__876:
  llvm_cbe_tmp__822 = *((&llvm_cbe_tmp__818->field29));
  *(&llvm_cbe_cppVar_1061) = (((unsigned char )(bool )(llvm_cbe_tmp__822 == 1ull)));
  llvm_cbe_tmp__823 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__823&1u))&1))) {
    goto llvm_cbe_tmp__878;
  } else {
    goto llvm_cbe_tmp__879;
  }

llvm_cbe_tmp__878:
  llvm_cbe_tmp__824 = *((&llvm_cbe_tmp__818->field15));
  *(&llvm_cbe_cppVar_1064) = (((unsigned char )(bool )(llvm_cbe_tmp__824 == 0ull)));
  llvm_cbe_tmp__825 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__825&1u))&1))) {
    goto llvm_cbe_tmp__880;
  } else {
    llvm_cbe_tmp__828__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__881;
  }

llvm_cbe_tmp__880:
  llvm_cbe_tmp__826 = *(&llvm_cbe_cppVar_1064);
  llvm_cbe_tmp__827 = ((((bool )llvm_cbe_tmp__826&1u))&1);
  llvm_cbe_tmp__828__PHI_TEMPORARY = llvm_cbe_tmp__827;   /* for PHI node */
  goto llvm_cbe_tmp__881;

llvm_cbe_tmp__881:
  llvm_cbe_tmp__828 = ((llvm_cbe_tmp__828__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1065) = (((unsigned char )(bool )llvm_cbe_tmp__828));
  llvm_cbe_tmp__829 = *(&llvm_cbe_cppVar_1065);
  if ((((((bool )llvm_cbe_tmp__829&1u))&1))) {
    goto llvm_cbe_tmp__882;
  } else {
    goto llvm_cbe_tmp__883;
  }

llvm_cbe_tmp__882:
  llvm_cbe_tmp__830 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1062), ((&llvm_cbe_tmp__818->field17)));
  goto llvm_cbe_tmp__884;

llvm_cbe_tmp__883:
  llvm_cbe_tmp__831 = *((&llvm_cbe_tmp__818->field15));
  *(&llvm_cbe_cppVar_1068) = (((unsigned char )(bool )(llvm_cbe_tmp__831 == 1ull)));
  llvm_cbe_tmp__832 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__832&1u))&1))) {
    goto llvm_cbe_tmp__885;
  } else {
    llvm_cbe_tmp__835__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__886;
  }

llvm_cbe_tmp__885:
  llvm_cbe_tmp__833 = *(&llvm_cbe_cppVar_1068);
  llvm_cbe_tmp__834 = ((((bool )llvm_cbe_tmp__833&1u))&1);
  llvm_cbe_tmp__835__PHI_TEMPORARY = llvm_cbe_tmp__834;   /* for PHI node */
  goto llvm_cbe_tmp__886;

llvm_cbe_tmp__886:
  llvm_cbe_tmp__835 = ((llvm_cbe_tmp__835__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1069) = (((unsigned char )(bool )llvm_cbe_tmp__835));
  llvm_cbe_tmp__836 = *(&llvm_cbe_cppVar_1069);
  if ((((((bool )llvm_cbe_tmp__836&1u))&1))) {
    goto llvm_cbe_tmp__887;
  } else {
    goto llvm_cbe_tmp__888;
  }

llvm_cbe_tmp__887:
  llvm_cbe_tmp__837 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1066), ((&llvm_cbe_tmp__818->field17)));
  goto llvm_cbe_tmp__889;

llvm_cbe_tmp__888:
  llvm_cbe_tmp__838 = *((&llvm_cbe_tmp__818->field15));
  *(&llvm_cbe_cppVar_1072) = (((unsigned char )(bool )(llvm_cbe_tmp__838 == 2ull)));
  llvm_cbe_tmp__839 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__839&1u))&1))) {
    goto llvm_cbe_tmp__890;
  } else {
    llvm_cbe_tmp__842__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__891;
  }

llvm_cbe_tmp__890:
  llvm_cbe_tmp__840 = *(&llvm_cbe_cppVar_1072);
  llvm_cbe_tmp__841 = ((((bool )llvm_cbe_tmp__840&1u))&1);
  llvm_cbe_tmp__842__PHI_TEMPORARY = llvm_cbe_tmp__841;   /* for PHI node */
  goto llvm_cbe_tmp__891;

llvm_cbe_tmp__891:
  llvm_cbe_tmp__842 = ((llvm_cbe_tmp__842__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1073) = (((unsigned char )(bool )llvm_cbe_tmp__842));
  llvm_cbe_tmp__843 = *(&llvm_cbe_cppVar_1073);
  if ((((((bool )llvm_cbe_tmp__843&1u))&1))) {
    goto llvm_cbe_tmp__892;
  } else {
    goto llvm_cbe_tmp__893;
  }

llvm_cbe_tmp__892:
  llvm_cbe_tmp__844 = *((&llvm_cbe_tmp__818->field7));
  llvm_cbe_tmp__845 = *((&llvm_cbe_tmp__818->field40));
  *(&llvm_cbe_cppVar_1074) = ((((signed long long )(((signed long long )llvm_cbe_tmp__844) >> ((signed long long )0ull)))) & llvm_cbe_tmp__845);
  llvm_cbe_tmp__846 = *((&llvm_cbe_tmp__818->field7));
  llvm_cbe_tmp__847 = *((&llvm_cbe_tmp__818->field40));
  *(&llvm_cbe_cppVar_1075) = ((((signed long long )(((signed long long )llvm_cbe_tmp__846) >> ((signed long long )0ull)))) & llvm_cbe_tmp__847);
  llvm_cbe_tmp__848 = *(&llvm_cbe_cppVar_1075);
  llvm_cbe_tmp__849 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__818->field32)), llvm_cbe_tmp__848);
  *(&llvm_cbe_cppVar_1076) = llvm_cbe_tmp__849;
  llvm_cbe_tmp__850 = *(&llvm_cbe_cppVar_1076);
  llvm_cbe_tmp__851 = _Z10to_int_expl(llvm_cbe_tmp__850);
  *(&llvm_cbe_cppVar_1077) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__851));
  llvm_cbe_tmp__852 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1078), ((&llvm_cbe_tmp__818->field17)));
  llvm_cbe_tmp__853 = *(&llvm_cbe_cppVar_1074);
  llvm_cbe_tmp__854 = *(&llvm_cbe_cppVar_1077);
  _ZN8type_memIjLj8EE2wrEll((&llvm_cbe_cppVar_1078), llvm_cbe_tmp__853, llvm_cbe_tmp__854);
  llvm_cbe_tmp__855 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1070), (&llvm_cbe_cppVar_1078));
  goto llvm_cbe_tmp__894;

llvm_cbe_tmp__893:
  llvm_cbe_tmp__856 = *((&llvm_cbe_tmp__818->field15));
  *(&llvm_cbe_cppVar_1081) = (((unsigned char )(bool )(llvm_cbe_tmp__856 == 3ull)));
  llvm_cbe_tmp__857 = *(&llvm_cbe_cppVar_1061);
  if ((((((bool )llvm_cbe_tmp__857&1u))&1))) {
    goto llvm_cbe_tmp__895;
  } else {
    llvm_cbe_tmp__860__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__896;
  }

llvm_cbe_tmp__895:
  llvm_cbe_tmp__858 = *(&llvm_cbe_cppVar_1081);
  llvm_cbe_tmp__859 = ((((bool )llvm_cbe_tmp__858&1u))&1);
  llvm_cbe_tmp__860__PHI_TEMPORARY = llvm_cbe_tmp__859;   /* for PHI node */
  goto llvm_cbe_tmp__896;

llvm_cbe_tmp__896:
  llvm_cbe_tmp__860 = ((llvm_cbe_tmp__860__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1082) = (((unsigned char )(bool )llvm_cbe_tmp__860));
  llvm_cbe_tmp__861 = *(&llvm_cbe_cppVar_1082);
  llvm_cbe_tmp__862 = ((((bool )llvm_cbe_tmp__861&1u))&1);
  llvm_cbe_tmp__863 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1079), ((&llvm_cbe_tmp__818->field17)));
  llvm_cbe_tmp__864 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1070), (&llvm_cbe_cppVar_1079));
  goto llvm_cbe_tmp__894;

llvm_cbe_tmp__894:
  llvm_cbe_tmp__865 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1066), (&llvm_cbe_cppVar_1070));
  goto llvm_cbe_tmp__889;

llvm_cbe_tmp__889:
  llvm_cbe_tmp__866 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1062), (&llvm_cbe_cppVar_1066));
  goto llvm_cbe_tmp__884;

llvm_cbe_tmp__884:
  llvm_cbe_tmp__867 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1059), (&llvm_cbe_cppVar_1062));
  goto llvm_cbe_tmp__897;

llvm_cbe_tmp__879:
  llvm_cbe_tmp__868 = *((&llvm_cbe_tmp__818->field29));
  *(&llvm_cbe_cppVar_1085) = (((unsigned char )(bool )(llvm_cbe_tmp__868 == 2ull)));
  llvm_cbe_tmp__869 = *(&llvm_cbe_cppVar_1085);
  llvm_cbe_tmp__870 = ((((bool )llvm_cbe_tmp__869&1u))&1);
  llvm_cbe_tmp__871 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1083), ((&llvm_cbe_tmp__818->field17)));
  llvm_cbe_tmp__872 = _ZN8type_memIjLj8EEaSERKS0_((&llvm_cbe_cppVar_1059), (&llvm_cbe_cppVar_1083));
  goto llvm_cbe_tmp__897;

llvm_cbe_tmp__897:
  llvm_cbe_tmp__873 = _ZN8type_memIjLj8EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1059));
  goto llvm_cbe_tmp__877;

llvm_cbe_tmp__877:
  *(&llvm_cbe_tmp__816) = ((1) & 1);
  *(&llvm_cbe_tmp__817) = 1u;
  llvm_cbe_tmp__874 = ((*(&llvm_cbe_tmp__816))&1);
  if (llvm_cbe_tmp__874) {
    goto llvm_cbe_tmp__898;
  } else {
    goto llvm_cbe_tmp__899;
  }

llvm_cbe_tmp__899:
  _ZN8type_memIjLj8EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__898;

llvm_cbe_tmp__898:
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
  struct l_unnamed1 *llvm_cbe_tmp__900;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__901;

  *(&llvm_cbe_tmp__900) = llvm_cbe_this;
  llvm_cbe_tmp__901 = *(&llvm_cbe_tmp__900);
  _ZN8type_memIjLj8EEC2Ev(llvm_cbe_tmp__901);
  return;
}


struct l_unnamed1 *_ZN8type_memIjLj8EEaSERKS0_(struct l_unnamed1 *llvm_cbe_this, struct l_unnamed1 *llvm_cbe_r) {
  struct l_unnamed1 *llvm_cbe_tmp__902;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__903;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__904;
  unsigned int *llvm_cbe_tmp__905;
  struct l_unnamed1 *llvm_cbe_tmp__906;
  unsigned int *llvm_cbe_tmp__907;

  *(&llvm_cbe_tmp__902) = llvm_cbe_this;
  *(&llvm_cbe_tmp__903) = llvm_cbe_r;
  llvm_cbe_tmp__904 = *(&llvm_cbe_tmp__902);
  llvm_cbe_tmp__905 = *((&llvm_cbe_tmp__904->field0));
  llvm_cbe_tmp__906 = *(&llvm_cbe_tmp__903);
  llvm_cbe_tmp__907 = *((&llvm_cbe_tmp__906->field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__905)), (((unsigned char *)llvm_cbe_tmp__907)));
  return llvm_cbe_tmp__904;
}


unsigned long long _ZN8type_memItLj8EE2rdEl(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_unnamed2 *llvm_cbe_tmp__908;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__909;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__910;
  unsigned long long llvm_cbe_tmp__911;
  unsigned short *llvm_cbe_tmp__912;
  unsigned short llvm_cbe_tmp__913;

  *(&llvm_cbe_tmp__908) = llvm_cbe_this;
  *(&llvm_cbe_tmp__909) = llvm_cbe_addr;
  llvm_cbe_tmp__910 = *(&llvm_cbe_tmp__908);
  llvm_cbe_tmp__911 = *(&llvm_cbe_tmp__909);
  llvm_cbe_tmp__912 = *((&llvm_cbe_tmp__910->field0));
  llvm_cbe_tmp__913 = *((&llvm_cbe_tmp__912[((signed long long )llvm_cbe_tmp__911)]));
  return (((unsigned long long )(unsigned short )llvm_cbe_tmp__913));
}


void _ZN8type_memIjLj8EE2wrEll(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_unnamed1 *llvm_cbe_tmp__914;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__915;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__916;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__917;
  unsigned long long llvm_cbe_tmp__918;
  unsigned long long llvm_cbe_tmp__919;
  unsigned int *llvm_cbe_tmp__920;

  *(&llvm_cbe_tmp__914) = llvm_cbe_this;
  *(&llvm_cbe_tmp__915) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__916) = llvm_cbe_data;
  llvm_cbe_tmp__917 = *(&llvm_cbe_tmp__914);
  llvm_cbe_tmp__918 = *(&llvm_cbe_tmp__916);
  llvm_cbe_tmp__919 = *(&llvm_cbe_tmp__915);
  llvm_cbe_tmp__920 = *((&llvm_cbe_tmp__917->field0));
  *((&llvm_cbe_tmp__920[((signed long long )llvm_cbe_tmp__919)])) = (((unsigned int )llvm_cbe_tmp__918));
  return;
}


void _ZN8type_memIjLj8EED1Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__921;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__922;

  *(&llvm_cbe_tmp__921) = llvm_cbe_this;
  llvm_cbe_tmp__922 = *(&llvm_cbe_tmp__921);
  _ZN8type_memIjLj8EED2Ev(llvm_cbe_tmp__922);
  return;
}


unsigned long long _ZN11model_train22cppUpdateFun_sumOfpow2Elllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__923;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__924;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__925;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__926;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__927;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__928;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__929;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__930;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__931;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__932;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__933;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__934;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__935;
  unsigned long long llvm_cbe_tmp__936;
  unsigned char llvm_cbe_tmp__937;
  unsigned long long llvm_cbe_tmp__938;
  unsigned long long llvm_cbe_tmp__939;
  unsigned char llvm_cbe_tmp__940;
  unsigned long long llvm_cbe_tmp__941;
  unsigned char llvm_cbe_tmp__942;
  unsigned char llvm_cbe_tmp__943;
  bool llvm_cbe_tmp__944;
  bool llvm_cbe_tmp__945;
  bool llvm_cbe_tmp__945__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__946;
  unsigned long long llvm_cbe_tmp__947;
  unsigned long long llvm_cbe_tmp__948;
  unsigned char llvm_cbe_tmp__949;
  unsigned char llvm_cbe_tmp__950;
  bool llvm_cbe_tmp__951;
  bool llvm_cbe_tmp__952;
  bool llvm_cbe_tmp__952__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__953;
  unsigned long long llvm_cbe_tmp__954;
  unsigned long long llvm_cbe_tmp__955;
  unsigned char llvm_cbe_tmp__956;
  unsigned char llvm_cbe_tmp__957;
  bool llvm_cbe_tmp__958;
  bool llvm_cbe_tmp__959;
  bool llvm_cbe_tmp__959__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__960;
  unsigned long long llvm_cbe_tmp__961;
  unsigned char llvm_cbe_tmp__962;
  unsigned long long llvm_cbe_tmp__963;
  unsigned long long llvm_cbe_tmp__964;
  unsigned long long llvm_cbe_tmp__965;
  unsigned long long llvm_cbe_tmp__966;
  unsigned long long llvm_cbe_tmp__967;
  unsigned long long llvm_cbe_tmp__968;
  unsigned short llvm_cbe_tmp__969;
  unsigned long long llvm_cbe_tmp__970;
  unsigned long long llvm_cbe_tmp__971;
  unsigned long long llvm_cbe_tmp__972;
  unsigned long long llvm_cbe_tmp__973;
  unsigned long long llvm_cbe_tmp__974;
  unsigned long long llvm_cbe_tmp__975;
  unsigned long long llvm_cbe_tmp__976;
  unsigned long long llvm_cbe_tmp__977;
  unsigned long long llvm_cbe_tmp__978;
  unsigned long long llvm_cbe_tmp__979;
  unsigned char llvm_cbe_tmp__980;
  unsigned char llvm_cbe_tmp__981;
  bool llvm_cbe_tmp__982;
  bool llvm_cbe_tmp__983;
  bool llvm_cbe_tmp__983__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__984;
  unsigned long long llvm_cbe_tmp__985;
  unsigned long long llvm_cbe_tmp__986;
  unsigned long long llvm_cbe_tmp__987;
  unsigned long long llvm_cbe_tmp__988;
  unsigned long long llvm_cbe_tmp__989;
  unsigned long long llvm_cbe_tmp__990;
  unsigned long long llvm_cbe_tmp__991;
  unsigned long long llvm_cbe_tmp__992;
  unsigned long long llvm_cbe_tmp__993;

  *(&llvm_cbe_tmp__923) = llvm_cbe_this;
  *(&llvm_cbe_tmp__924) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__925) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__926) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__927) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__928) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__929) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__930) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__931) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__932) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__933) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__934) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__935 = *(&llvm_cbe_tmp__923);
  llvm_cbe_tmp__936 = *((&llvm_cbe_tmp__935->field29));
  *(&llvm_cbe_cppVar_621) = (((unsigned char )(bool )(llvm_cbe_tmp__936 == 0ull)));
  llvm_cbe_tmp__937 = *(&llvm_cbe_cppVar_621);
  if ((((((bool )llvm_cbe_tmp__937&1u))&1))) {
    goto llvm_cbe_tmp__994;
  } else {
    goto llvm_cbe_tmp__995;
  }

llvm_cbe_tmp__994:
  llvm_cbe_tmp__938 = *((&llvm_cbe_tmp__935->field24));
  *(&llvm_cbe_cppVar_619) = llvm_cbe_tmp__938;
  goto llvm_cbe_tmp__996;

llvm_cbe_tmp__995:
  llvm_cbe_tmp__939 = *((&llvm_cbe_tmp__935->field29));
  *(&llvm_cbe_cppVar_624) = (((unsigned char )(bool )(llvm_cbe_tmp__939 == 1ull)));
  llvm_cbe_tmp__940 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__940&1u))&1))) {
    goto llvm_cbe_tmp__997;
  } else {
    goto llvm_cbe_tmp__998;
  }

llvm_cbe_tmp__997:
  llvm_cbe_tmp__941 = *((&llvm_cbe_tmp__935->field15));
  *(&llvm_cbe_cppVar_627) = (((unsigned char )(bool )(llvm_cbe_tmp__941 == 0ull)));
  llvm_cbe_tmp__942 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__942&1u))&1))) {
    goto llvm_cbe_tmp__999;
  } else {
    llvm_cbe_tmp__945__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1000;
  }

llvm_cbe_tmp__999:
  llvm_cbe_tmp__943 = *(&llvm_cbe_cppVar_627);
  llvm_cbe_tmp__944 = ((((bool )llvm_cbe_tmp__943&1u))&1);
  llvm_cbe_tmp__945__PHI_TEMPORARY = llvm_cbe_tmp__944;   /* for PHI node */
  goto llvm_cbe_tmp__1000;

llvm_cbe_tmp__1000:
  llvm_cbe_tmp__945 = ((llvm_cbe_tmp__945__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_628) = (((unsigned char )(bool )llvm_cbe_tmp__945));
  llvm_cbe_tmp__946 = *(&llvm_cbe_cppVar_628);
  if ((((((bool )llvm_cbe_tmp__946&1u))&1))) {
    goto llvm_cbe_tmp__1001;
  } else {
    goto llvm_cbe_tmp__1002;
  }

llvm_cbe_tmp__1001:
  llvm_cbe_tmp__947 = *((&llvm_cbe_tmp__935->field24));
  *(&llvm_cbe_cppVar_625) = llvm_cbe_tmp__947;
  goto llvm_cbe_tmp__1003;

llvm_cbe_tmp__1002:
  llvm_cbe_tmp__948 = *((&llvm_cbe_tmp__935->field15));
  *(&llvm_cbe_cppVar_631) = (((unsigned char )(bool )(llvm_cbe_tmp__948 == 1ull)));
  llvm_cbe_tmp__949 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__949&1u))&1))) {
    goto llvm_cbe_tmp__1004;
  } else {
    llvm_cbe_tmp__952__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1005;
  }

llvm_cbe_tmp__1004:
  llvm_cbe_tmp__950 = *(&llvm_cbe_cppVar_631);
  llvm_cbe_tmp__951 = ((((bool )llvm_cbe_tmp__950&1u))&1);
  llvm_cbe_tmp__952__PHI_TEMPORARY = llvm_cbe_tmp__951;   /* for PHI node */
  goto llvm_cbe_tmp__1005;

llvm_cbe_tmp__1005:
  llvm_cbe_tmp__952 = ((llvm_cbe_tmp__952__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_632) = (((unsigned char )(bool )llvm_cbe_tmp__952));
  llvm_cbe_tmp__953 = *(&llvm_cbe_cppVar_632);
  if ((((((bool )llvm_cbe_tmp__953&1u))&1))) {
    goto llvm_cbe_tmp__1006;
  } else {
    goto llvm_cbe_tmp__1007;
  }

llvm_cbe_tmp__1006:
  llvm_cbe_tmp__954 = *((&llvm_cbe_tmp__935->field24));
  *(&llvm_cbe_cppVar_629) = llvm_cbe_tmp__954;
  goto llvm_cbe_tmp__1008;

llvm_cbe_tmp__1007:
  llvm_cbe_tmp__955 = *((&llvm_cbe_tmp__935->field15));
  *(&llvm_cbe_cppVar_635) = (((unsigned char )(bool )(llvm_cbe_tmp__955 == 2ull)));
  llvm_cbe_tmp__956 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__956&1u))&1))) {
    goto llvm_cbe_tmp__1009;
  } else {
    llvm_cbe_tmp__959__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1010;
  }

llvm_cbe_tmp__1009:
  llvm_cbe_tmp__957 = *(&llvm_cbe_cppVar_635);
  llvm_cbe_tmp__958 = ((((bool )llvm_cbe_tmp__957&1u))&1);
  llvm_cbe_tmp__959__PHI_TEMPORARY = llvm_cbe_tmp__958;   /* for PHI node */
  goto llvm_cbe_tmp__1010;

llvm_cbe_tmp__1010:
  llvm_cbe_tmp__959 = ((llvm_cbe_tmp__959__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_636) = (((unsigned char )(bool )llvm_cbe_tmp__959));
  llvm_cbe_tmp__960 = *(&llvm_cbe_cppVar_636);
  if ((((((bool )llvm_cbe_tmp__960&1u))&1))) {
    goto llvm_cbe_tmp__1011;
  } else {
    goto llvm_cbe_tmp__1012;
  }

llvm_cbe_tmp__1011:
  llvm_cbe_tmp__961 = *((&llvm_cbe_tmp__935->field7));
  *(&llvm_cbe_cppVar_639) = (((unsigned char )(bool )(llvm_cbe_tmp__961 == 0ull)));
  llvm_cbe_tmp__962 = *(&llvm_cbe_cppVar_639);
  if ((((((bool )llvm_cbe_tmp__962&1u))&1))) {
    goto llvm_cbe_tmp__1013;
  } else {
    goto llvm_cbe_tmp__1014;
  }

llvm_cbe_tmp__1013:
  *(&llvm_cbe_cppVar_637) = 0ull;
  goto llvm_cbe_tmp__1015;

llvm_cbe_tmp__1014:
  llvm_cbe_tmp__963 = *((&llvm_cbe_tmp__935->field24));
  *(&llvm_cbe_cppVar_637) = llvm_cbe_tmp__963;
  goto llvm_cbe_tmp__1015;

llvm_cbe_tmp__1015:
  llvm_cbe_tmp__964 = *((&llvm_cbe_tmp__935->field7));
  llvm_cbe_tmp__965 = *((&llvm_cbe_tmp__935->field40));
  *(&llvm_cbe_cppVar_641) = ((((signed long long )(((signed long long )llvm_cbe_tmp__964) >> ((signed long long )0ull)))) & llvm_cbe_tmp__965);
  llvm_cbe_tmp__966 = *(&llvm_cbe_cppVar_641);
  llvm_cbe_tmp__967 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__935->field32)), llvm_cbe_tmp__966);
  *(&llvm_cbe_cppVar_642) = llvm_cbe_tmp__967;
  llvm_cbe_tmp__968 = *(&llvm_cbe_cppVar_642);
  llvm_cbe_tmp__969 = _Z10to_int_expl(llvm_cbe_tmp__968);
  *(&llvm_cbe_cppVar_643) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__969));
  llvm_cbe_tmp__970 = *(&llvm_cbe_cppVar_643);
  llvm_cbe_tmp__971 = *((&llvm_cbe_tmp__935->field41));
  *(&llvm_cbe_cppVar_644) = ((((signed long long )(((signed long long )llvm_cbe_tmp__970) >> ((signed long long )0ull)))) & llvm_cbe_tmp__971);
  llvm_cbe_tmp__972 = *(&llvm_cbe_cppVar_644);
  llvm_cbe_tmp__973 = *((&llvm_cbe_tmp__935->field41));
  *(&llvm_cbe_cppVar_645) = (llvm_cbe_tmp__972 & llvm_cbe_tmp__973);
  llvm_cbe_tmp__974 = *(&llvm_cbe_cppVar_637);
  llvm_cbe_tmp__975 = *(&llvm_cbe_cppVar_645);
  *(&llvm_cbe_cppVar_646) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__974) + ((unsigned long long )llvm_cbe_tmp__975))));
  llvm_cbe_tmp__976 = *(&llvm_cbe_cppVar_646);
  llvm_cbe_tmp__977 = *((&llvm_cbe_tmp__935->field42));
  *(&llvm_cbe_cppVar_646) = (llvm_cbe_tmp__976 & llvm_cbe_tmp__977);
  llvm_cbe_tmp__978 = *(&llvm_cbe_cppVar_646);
  *(&llvm_cbe_cppVar_633) = llvm_cbe_tmp__978;
  goto llvm_cbe_tmp__1016;

llvm_cbe_tmp__1012:
  llvm_cbe_tmp__979 = *((&llvm_cbe_tmp__935->field15));
  *(&llvm_cbe_cppVar_649) = (((unsigned char )(bool )(llvm_cbe_tmp__979 == 3ull)));
  llvm_cbe_tmp__980 = *(&llvm_cbe_cppVar_624);
  if ((((((bool )llvm_cbe_tmp__980&1u))&1))) {
    goto llvm_cbe_tmp__1017;
  } else {
    llvm_cbe_tmp__983__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1018;
  }

llvm_cbe_tmp__1017:
  llvm_cbe_tmp__981 = *(&llvm_cbe_cppVar_649);
  llvm_cbe_tmp__982 = ((((bool )llvm_cbe_tmp__981&1u))&1);
  llvm_cbe_tmp__983__PHI_TEMPORARY = llvm_cbe_tmp__982;   /* for PHI node */
  goto llvm_cbe_tmp__1018;

llvm_cbe_tmp__1018:
  llvm_cbe_tmp__983 = ((llvm_cbe_tmp__983__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_650) = (((unsigned char )(bool )llvm_cbe_tmp__983));
  llvm_cbe_tmp__984 = *((&llvm_cbe_tmp__935->field24));
  *(&llvm_cbe_cppVar_647) = llvm_cbe_tmp__984;
  llvm_cbe_tmp__985 = *(&llvm_cbe_cppVar_647);
  *(&llvm_cbe_cppVar_633) = llvm_cbe_tmp__985;
  goto llvm_cbe_tmp__1016;

llvm_cbe_tmp__1016:
  llvm_cbe_tmp__986 = *(&llvm_cbe_cppVar_633);
  *(&llvm_cbe_cppVar_629) = llvm_cbe_tmp__986;
  goto llvm_cbe_tmp__1008;

llvm_cbe_tmp__1008:
  llvm_cbe_tmp__987 = *(&llvm_cbe_cppVar_629);
  *(&llvm_cbe_cppVar_625) = llvm_cbe_tmp__987;
  goto llvm_cbe_tmp__1003;

llvm_cbe_tmp__1003:
  llvm_cbe_tmp__988 = *(&llvm_cbe_cppVar_625);
  *(&llvm_cbe_cppVar_622) = llvm_cbe_tmp__988;
  goto llvm_cbe_tmp__1019;

llvm_cbe_tmp__998:
  llvm_cbe_tmp__989 = *((&llvm_cbe_tmp__935->field29));
  *(&llvm_cbe_cppVar_653) = (((unsigned char )(bool )(llvm_cbe_tmp__989 == 2ull)));
  llvm_cbe_tmp__990 = *((&llvm_cbe_tmp__935->field24));
  *(&llvm_cbe_cppVar_651) = llvm_cbe_tmp__990;
  llvm_cbe_tmp__991 = *(&llvm_cbe_cppVar_651);
  *(&llvm_cbe_cppVar_622) = llvm_cbe_tmp__991;
  goto llvm_cbe_tmp__1019;

llvm_cbe_tmp__1019:
  llvm_cbe_tmp__992 = *(&llvm_cbe_cppVar_622);
  *(&llvm_cbe_cppVar_619) = llvm_cbe_tmp__992;
  goto llvm_cbe_tmp__996;

llvm_cbe_tmp__996:
  llvm_cbe_tmp__993 = *(&llvm_cbe_cppVar_619);
  return llvm_cbe_tmp__993;
}


unsigned long long _ZN11model_train24cppUpdateFun_train_h_cntElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1020;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1021;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1022;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1023;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1024;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1025;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1026;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1027;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1028;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1029;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1030;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1031;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__1032;
  unsigned long long llvm_cbe_tmp__1033;
  unsigned char llvm_cbe_tmp__1034;
  unsigned long long llvm_cbe_tmp__1035;
  unsigned long long llvm_cbe_tmp__1036;
  unsigned char llvm_cbe_tmp__1037;
  unsigned long long llvm_cbe_tmp__1038;
  unsigned long long llvm_cbe_tmp__1039;
  unsigned long long llvm_cbe_tmp__1040;
  unsigned long long llvm_cbe_tmp__1041;
  unsigned long long llvm_cbe_tmp__1042;
  unsigned char llvm_cbe_tmp__1043;
  unsigned long long llvm_cbe_tmp__1044;
  unsigned long long llvm_cbe_tmp__1045;
  unsigned long long llvm_cbe_tmp__1046;
  unsigned long long llvm_cbe_tmp__1047;
  unsigned long long llvm_cbe_tmp__1048;
  unsigned long long llvm_cbe_tmp__1049;
  unsigned long long llvm_cbe_tmp__1050;
  unsigned long long llvm_cbe_tmp__1051;
  unsigned char llvm_cbe_tmp__1052;
  unsigned long long llvm_cbe_tmp__1053;
  unsigned char llvm_cbe_tmp__1054;
  unsigned char llvm_cbe_tmp__1055;
  bool llvm_cbe_tmp__1056;
  bool llvm_cbe_tmp__1057;
  bool llvm_cbe_tmp__1057__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1058;
  unsigned long long llvm_cbe_tmp__1059;
  unsigned long long llvm_cbe_tmp__1060;
  unsigned char llvm_cbe_tmp__1061;
  unsigned long long llvm_cbe_tmp__1062;
  unsigned long long llvm_cbe_tmp__1063;
  unsigned long long llvm_cbe_tmp__1064;
  unsigned long long llvm_cbe_tmp__1065;
  unsigned long long llvm_cbe_tmp__1066;
  unsigned long long llvm_cbe_tmp__1067;
  unsigned char llvm_cbe_tmp__1068;
  unsigned char llvm_cbe_tmp__1069;
  bool llvm_cbe_tmp__1070;
  bool llvm_cbe_tmp__1071;
  bool llvm_cbe_tmp__1071__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1072;
  unsigned long long llvm_cbe_tmp__1073;
  unsigned long long llvm_cbe_tmp__1074;
  unsigned char llvm_cbe_tmp__1075;
  unsigned char llvm_cbe_tmp__1076;
  bool llvm_cbe_tmp__1077;
  bool llvm_cbe_tmp__1078;
  bool llvm_cbe_tmp__1078__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1079;
  unsigned long long llvm_cbe_tmp__1080;
  unsigned long long llvm_cbe_tmp__1081;
  unsigned char llvm_cbe_tmp__1082;
  unsigned char llvm_cbe_tmp__1083;
  bool llvm_cbe_tmp__1084;
  bool llvm_cbe_tmp__1085;
  bool llvm_cbe_tmp__1085__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1086;
  unsigned long long llvm_cbe_tmp__1087;
  unsigned long long llvm_cbe_tmp__1088;
  unsigned long long llvm_cbe_tmp__1089;
  unsigned long long llvm_cbe_tmp__1090;
  unsigned long long llvm_cbe_tmp__1091;
  unsigned char llvm_cbe_tmp__1092;
  unsigned long long llvm_cbe_tmp__1093;
  unsigned long long llvm_cbe_tmp__1094;
  unsigned char llvm_cbe_tmp__1095;
  unsigned long long llvm_cbe_tmp__1096;
  unsigned long long llvm_cbe_tmp__1097;
  unsigned long long llvm_cbe_tmp__1098;
  unsigned long long llvm_cbe_tmp__1099;
  unsigned long long llvm_cbe_tmp__1100;
  unsigned long long llvm_cbe_tmp__1101;
  unsigned char llvm_cbe_tmp__1102;
  unsigned long long llvm_cbe_tmp__1103;
  unsigned long long llvm_cbe_tmp__1104;
  unsigned char llvm_cbe_tmp__1105;
  unsigned long long llvm_cbe_tmp__1106;
  unsigned long long llvm_cbe_tmp__1107;
  unsigned long long llvm_cbe_tmp__1108;
  unsigned long long llvm_cbe_tmp__1109;
  unsigned long long llvm_cbe_tmp__1110;
  unsigned long long llvm_cbe_tmp__1111;
  unsigned long long llvm_cbe_tmp__1112;
  unsigned long long llvm_cbe_tmp__1113;
  unsigned long long llvm_cbe_tmp__1114;

  *(&llvm_cbe_tmp__1020) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1021) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1022) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1023) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1024) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1025) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1026) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1027) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1028) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1029) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1030) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1031) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1032 = *(&llvm_cbe_tmp__1020);
  llvm_cbe_tmp__1033 = *((&llvm_cbe_tmp__1032->field29));
  *(&llvm_cbe_cppVar_657) = (((unsigned char )(bool )(llvm_cbe_tmp__1033 == 0ull)));
  llvm_cbe_tmp__1034 = *(&llvm_cbe_cppVar_657);
  if ((((((bool )llvm_cbe_tmp__1034&1u))&1))) {
    goto llvm_cbe_tmp__1115;
  } else {
    goto llvm_cbe_tmp__1116;
  }

llvm_cbe_tmp__1115:
  llvm_cbe_tmp__1035 = *((&llvm_cbe_tmp__1032->field30));
  llvm_cbe_tmp__1036 = *((&llvm_cbe_tmp__1032->field14));
  *(&llvm_cbe_cppVar_659) = (((unsigned char )(bool )(llvm_cbe_tmp__1035 == llvm_cbe_tmp__1036)));
  llvm_cbe_tmp__1037 = *(&llvm_cbe_cppVar_659);
  if ((((((bool )llvm_cbe_tmp__1037&1u))&1))) {
    goto llvm_cbe_tmp__1117;
  } else {
    goto llvm_cbe_tmp__1118;
  }

llvm_cbe_tmp__1117:
  llvm_cbe_tmp__1038 = *((&llvm_cbe_tmp__1032->field9));
  *(&llvm_cbe_cppVar_662) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1038) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__1039 = *(&llvm_cbe_cppVar_662);
  llvm_cbe_tmp__1040 = *((&llvm_cbe_tmp__1032->field39));
  *(&llvm_cbe_cppVar_662) = (llvm_cbe_tmp__1039 & llvm_cbe_tmp__1040);
  llvm_cbe_tmp__1041 = *((&llvm_cbe_tmp__1032->field25));
  llvm_cbe_tmp__1042 = *(&llvm_cbe_cppVar_662);
  *(&llvm_cbe_cppVar_663) = (((unsigned char )(bool )(llvm_cbe_tmp__1041 == llvm_cbe_tmp__1042)));
  llvm_cbe_tmp__1043 = *(&llvm_cbe_cppVar_663);
  if ((((((bool )llvm_cbe_tmp__1043&1u))&1))) {
    goto llvm_cbe_tmp__1119;
  } else {
    goto llvm_cbe_tmp__1120;
  }

llvm_cbe_tmp__1119:
  *(&llvm_cbe_cppVar_660) = 0ull;
  goto llvm_cbe_tmp__1121;

llvm_cbe_tmp__1120:
  llvm_cbe_tmp__1044 = *((&llvm_cbe_tmp__1032->field25));
  *(&llvm_cbe_cppVar_666) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1044) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1045 = *(&llvm_cbe_cppVar_666);
  llvm_cbe_tmp__1046 = *((&llvm_cbe_tmp__1032->field39));
  *(&llvm_cbe_cppVar_666) = (llvm_cbe_tmp__1045 & llvm_cbe_tmp__1046);
  llvm_cbe_tmp__1047 = *(&llvm_cbe_cppVar_666);
  *(&llvm_cbe_cppVar_660) = llvm_cbe_tmp__1047;
  goto llvm_cbe_tmp__1121;

llvm_cbe_tmp__1121:
  llvm_cbe_tmp__1048 = *(&llvm_cbe_cppVar_660);
  *(&llvm_cbe_cppVar_658) = llvm_cbe_tmp__1048;
  goto llvm_cbe_tmp__1122;

llvm_cbe_tmp__1118:
  llvm_cbe_tmp__1049 = *((&llvm_cbe_tmp__1032->field25));
  *(&llvm_cbe_cppVar_658) = llvm_cbe_tmp__1049;
  goto llvm_cbe_tmp__1122;

llvm_cbe_tmp__1122:
  llvm_cbe_tmp__1050 = *(&llvm_cbe_cppVar_658);
  *(&llvm_cbe_cppVar_655) = llvm_cbe_tmp__1050;
  goto llvm_cbe_tmp__1123;

llvm_cbe_tmp__1116:
  llvm_cbe_tmp__1051 = *((&llvm_cbe_tmp__1032->field29));
  *(&llvm_cbe_cppVar_669) = (((unsigned char )(bool )(llvm_cbe_tmp__1051 == 1ull)));
  llvm_cbe_tmp__1052 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1052&1u))&1))) {
    goto llvm_cbe_tmp__1124;
  } else {
    goto llvm_cbe_tmp__1125;
  }

llvm_cbe_tmp__1124:
  llvm_cbe_tmp__1053 = *((&llvm_cbe_tmp__1032->field15));
  *(&llvm_cbe_cppVar_672) = (((unsigned char )(bool )(llvm_cbe_tmp__1053 == 0ull)));
  llvm_cbe_tmp__1054 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1054&1u))&1))) {
    goto llvm_cbe_tmp__1126;
  } else {
    llvm_cbe_tmp__1057__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1127;
  }

llvm_cbe_tmp__1126:
  llvm_cbe_tmp__1055 = *(&llvm_cbe_cppVar_672);
  llvm_cbe_tmp__1056 = ((((bool )llvm_cbe_tmp__1055&1u))&1);
  llvm_cbe_tmp__1057__PHI_TEMPORARY = llvm_cbe_tmp__1056;   /* for PHI node */
  goto llvm_cbe_tmp__1127;

llvm_cbe_tmp__1127:
  llvm_cbe_tmp__1057 = ((llvm_cbe_tmp__1057__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_673) = (((unsigned char )(bool )llvm_cbe_tmp__1057));
  llvm_cbe_tmp__1058 = *(&llvm_cbe_cppVar_673);
  if ((((((bool )llvm_cbe_tmp__1058&1u))&1))) {
    goto llvm_cbe_tmp__1128;
  } else {
    goto llvm_cbe_tmp__1129;
  }

llvm_cbe_tmp__1128:
  llvm_cbe_tmp__1059 = *((&llvm_cbe_tmp__1032->field25));
  llvm_cbe_tmp__1060 = *((&llvm_cbe_tmp__1032->field9));
  *(&llvm_cbe_cppVar_675) = (((unsigned char )(bool )(llvm_cbe_tmp__1059 == llvm_cbe_tmp__1060)));
  llvm_cbe_tmp__1061 = *(&llvm_cbe_cppVar_675);
  if ((((((bool )llvm_cbe_tmp__1061&1u))&1))) {
    goto llvm_cbe_tmp__1130;
  } else {
    goto llvm_cbe_tmp__1131;
  }

llvm_cbe_tmp__1130:
  *(&llvm_cbe_cppVar_674) = 0ull;
  goto llvm_cbe_tmp__1132;

llvm_cbe_tmp__1131:
  llvm_cbe_tmp__1062 = *((&llvm_cbe_tmp__1032->field25));
  *(&llvm_cbe_cppVar_677) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1062) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1063 = *(&llvm_cbe_cppVar_677);
  llvm_cbe_tmp__1064 = *((&llvm_cbe_tmp__1032->field39));
  *(&llvm_cbe_cppVar_677) = (llvm_cbe_tmp__1063 & llvm_cbe_tmp__1064);
  llvm_cbe_tmp__1065 = *(&llvm_cbe_cppVar_677);
  *(&llvm_cbe_cppVar_674) = llvm_cbe_tmp__1065;
  goto llvm_cbe_tmp__1132;

llvm_cbe_tmp__1132:
  llvm_cbe_tmp__1066 = *(&llvm_cbe_cppVar_674);
  *(&llvm_cbe_cppVar_670) = llvm_cbe_tmp__1066;
  goto llvm_cbe_tmp__1133;

llvm_cbe_tmp__1129:
  llvm_cbe_tmp__1067 = *((&llvm_cbe_tmp__1032->field15));
  *(&llvm_cbe_cppVar_680) = (((unsigned char )(bool )(llvm_cbe_tmp__1067 == 1ull)));
  llvm_cbe_tmp__1068 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1068&1u))&1))) {
    goto llvm_cbe_tmp__1134;
  } else {
    llvm_cbe_tmp__1071__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1135;
  }

llvm_cbe_tmp__1134:
  llvm_cbe_tmp__1069 = *(&llvm_cbe_cppVar_680);
  llvm_cbe_tmp__1070 = ((((bool )llvm_cbe_tmp__1069&1u))&1);
  llvm_cbe_tmp__1071__PHI_TEMPORARY = llvm_cbe_tmp__1070;   /* for PHI node */
  goto llvm_cbe_tmp__1135;

llvm_cbe_tmp__1135:
  llvm_cbe_tmp__1071 = ((llvm_cbe_tmp__1071__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_681) = (((unsigned char )(bool )llvm_cbe_tmp__1071));
  llvm_cbe_tmp__1072 = *(&llvm_cbe_cppVar_681);
  if ((((((bool )llvm_cbe_tmp__1072&1u))&1))) {
    goto llvm_cbe_tmp__1136;
  } else {
    goto llvm_cbe_tmp__1137;
  }

llvm_cbe_tmp__1136:
  llvm_cbe_tmp__1073 = *((&llvm_cbe_tmp__1032->field25));
  *(&llvm_cbe_cppVar_678) = llvm_cbe_tmp__1073;
  goto llvm_cbe_tmp__1138;

llvm_cbe_tmp__1137:
  llvm_cbe_tmp__1074 = *((&llvm_cbe_tmp__1032->field15));
  *(&llvm_cbe_cppVar_684) = (((unsigned char )(bool )(llvm_cbe_tmp__1074 == 2ull)));
  llvm_cbe_tmp__1075 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1075&1u))&1))) {
    goto llvm_cbe_tmp__1139;
  } else {
    llvm_cbe_tmp__1078__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1140;
  }

llvm_cbe_tmp__1139:
  llvm_cbe_tmp__1076 = *(&llvm_cbe_cppVar_684);
  llvm_cbe_tmp__1077 = ((((bool )llvm_cbe_tmp__1076&1u))&1);
  llvm_cbe_tmp__1078__PHI_TEMPORARY = llvm_cbe_tmp__1077;   /* for PHI node */
  goto llvm_cbe_tmp__1140;

llvm_cbe_tmp__1140:
  llvm_cbe_tmp__1078 = ((llvm_cbe_tmp__1078__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_685) = (((unsigned char )(bool )llvm_cbe_tmp__1078));
  llvm_cbe_tmp__1079 = *(&llvm_cbe_cppVar_685);
  if ((((((bool )llvm_cbe_tmp__1079&1u))&1))) {
    goto llvm_cbe_tmp__1141;
  } else {
    goto llvm_cbe_tmp__1142;
  }

llvm_cbe_tmp__1141:
  llvm_cbe_tmp__1080 = *((&llvm_cbe_tmp__1032->field25));
  *(&llvm_cbe_cppVar_682) = llvm_cbe_tmp__1080;
  goto llvm_cbe_tmp__1143;

llvm_cbe_tmp__1142:
  llvm_cbe_tmp__1081 = *((&llvm_cbe_tmp__1032->field15));
  *(&llvm_cbe_cppVar_688) = (((unsigned char )(bool )(llvm_cbe_tmp__1081 == 3ull)));
  llvm_cbe_tmp__1082 = *(&llvm_cbe_cppVar_669);
  if ((((((bool )llvm_cbe_tmp__1082&1u))&1))) {
    goto llvm_cbe_tmp__1144;
  } else {
    llvm_cbe_tmp__1085__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1145;
  }

llvm_cbe_tmp__1144:
  llvm_cbe_tmp__1083 = *(&llvm_cbe_cppVar_688);
  llvm_cbe_tmp__1084 = ((((bool )llvm_cbe_tmp__1083&1u))&1);
  llvm_cbe_tmp__1085__PHI_TEMPORARY = llvm_cbe_tmp__1084;   /* for PHI node */
  goto llvm_cbe_tmp__1145;

llvm_cbe_tmp__1145:
  llvm_cbe_tmp__1085 = ((llvm_cbe_tmp__1085__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_689) = (((unsigned char )(bool )llvm_cbe_tmp__1085));
  llvm_cbe_tmp__1086 = *((&llvm_cbe_tmp__1032->field25));
  *(&llvm_cbe_cppVar_686) = llvm_cbe_tmp__1086;
  llvm_cbe_tmp__1087 = *(&llvm_cbe_cppVar_686);
  *(&llvm_cbe_cppVar_682) = llvm_cbe_tmp__1087;
  goto llvm_cbe_tmp__1143;

llvm_cbe_tmp__1143:
  llvm_cbe_tmp__1088 = *(&llvm_cbe_cppVar_682);
  *(&llvm_cbe_cppVar_678) = llvm_cbe_tmp__1088;
  goto llvm_cbe_tmp__1138;

llvm_cbe_tmp__1138:
  llvm_cbe_tmp__1089 = *(&llvm_cbe_cppVar_678);
  *(&llvm_cbe_cppVar_670) = llvm_cbe_tmp__1089;
  goto llvm_cbe_tmp__1133;

llvm_cbe_tmp__1133:
  llvm_cbe_tmp__1090 = *(&llvm_cbe_cppVar_670);
  *(&llvm_cbe_cppVar_667) = llvm_cbe_tmp__1090;
  goto llvm_cbe_tmp__1146;

llvm_cbe_tmp__1125:
  llvm_cbe_tmp__1091 = *((&llvm_cbe_tmp__1032->field29));
  *(&llvm_cbe_cppVar_692) = (((unsigned char )(bool )(llvm_cbe_tmp__1091 == 3ull)));
  llvm_cbe_tmp__1092 = *(&llvm_cbe_cppVar_692);
  if ((((((bool )llvm_cbe_tmp__1092&1u))&1))) {
    goto llvm_cbe_tmp__1147;
  } else {
    goto llvm_cbe_tmp__1148;
  }

llvm_cbe_tmp__1147:
  llvm_cbe_tmp__1093 = *((&llvm_cbe_tmp__1032->field25));
  llvm_cbe_tmp__1094 = *((&llvm_cbe_tmp__1032->field9));
  *(&llvm_cbe_cppVar_694) = (((unsigned char )(bool )(llvm_cbe_tmp__1093 == llvm_cbe_tmp__1094)));
  llvm_cbe_tmp__1095 = *(&llvm_cbe_cppVar_694);
  if ((((((bool )llvm_cbe_tmp__1095&1u))&1))) {
    goto llvm_cbe_tmp__1149;
  } else {
    goto llvm_cbe_tmp__1150;
  }

llvm_cbe_tmp__1149:
  *(&llvm_cbe_cppVar_693) = 0ull;
  goto llvm_cbe_tmp__1151;

llvm_cbe_tmp__1150:
  llvm_cbe_tmp__1096 = *((&llvm_cbe_tmp__1032->field25));
  *(&llvm_cbe_cppVar_696) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1096) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1097 = *(&llvm_cbe_cppVar_696);
  llvm_cbe_tmp__1098 = *((&llvm_cbe_tmp__1032->field39));
  *(&llvm_cbe_cppVar_696) = (llvm_cbe_tmp__1097 & llvm_cbe_tmp__1098);
  llvm_cbe_tmp__1099 = *(&llvm_cbe_cppVar_696);
  *(&llvm_cbe_cppVar_693) = llvm_cbe_tmp__1099;
  goto llvm_cbe_tmp__1151;

llvm_cbe_tmp__1151:
  llvm_cbe_tmp__1100 = *(&llvm_cbe_cppVar_693);
  *(&llvm_cbe_cppVar_690) = llvm_cbe_tmp__1100;
  goto llvm_cbe_tmp__1152;

llvm_cbe_tmp__1148:
  llvm_cbe_tmp__1101 = *((&llvm_cbe_tmp__1032->field29));
  *(&llvm_cbe_cppVar_699) = (((unsigned char )(bool )(llvm_cbe_tmp__1101 == 2ull)));
  llvm_cbe_tmp__1102 = *(&llvm_cbe_cppVar_699);
  llvm_cbe_tmp__1103 = *((&llvm_cbe_tmp__1032->field25));
  if ((((((bool )llvm_cbe_tmp__1102&1u))&1))) {
    goto llvm_cbe_tmp__1153;
  } else {
    goto llvm_cbe_tmp__1154;
  }

llvm_cbe_tmp__1153:
  llvm_cbe_tmp__1104 = *((&llvm_cbe_tmp__1032->field9));
  *(&llvm_cbe_cppVar_701) = (((unsigned char )(bool )(llvm_cbe_tmp__1103 == llvm_cbe_tmp__1104)));
  llvm_cbe_tmp__1105 = *(&llvm_cbe_cppVar_701);
  if ((((((bool )llvm_cbe_tmp__1105&1u))&1))) {
    goto llvm_cbe_tmp__1155;
  } else {
    goto llvm_cbe_tmp__1156;
  }

llvm_cbe_tmp__1155:
  *(&llvm_cbe_cppVar_700) = 0ull;
  goto llvm_cbe_tmp__1157;

llvm_cbe_tmp__1156:
  llvm_cbe_tmp__1106 = *((&llvm_cbe_tmp__1032->field25));
  *(&llvm_cbe_cppVar_703) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1106) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1107 = *(&llvm_cbe_cppVar_703);
  llvm_cbe_tmp__1108 = *((&llvm_cbe_tmp__1032->field39));
  *(&llvm_cbe_cppVar_703) = (llvm_cbe_tmp__1107 & llvm_cbe_tmp__1108);
  llvm_cbe_tmp__1109 = *(&llvm_cbe_cppVar_703);
  *(&llvm_cbe_cppVar_700) = llvm_cbe_tmp__1109;
  goto llvm_cbe_tmp__1157;

llvm_cbe_tmp__1157:
  llvm_cbe_tmp__1110 = *(&llvm_cbe_cppVar_700);
  *(&llvm_cbe_cppVar_697) = llvm_cbe_tmp__1110;
  goto llvm_cbe_tmp__1158;

llvm_cbe_tmp__1154:
  *(&llvm_cbe_cppVar_697) = llvm_cbe_tmp__1103;
  goto llvm_cbe_tmp__1158;

llvm_cbe_tmp__1158:
  llvm_cbe_tmp__1111 = *(&llvm_cbe_cppVar_697);
  *(&llvm_cbe_cppVar_690) = llvm_cbe_tmp__1111;
  goto llvm_cbe_tmp__1152;

llvm_cbe_tmp__1152:
  llvm_cbe_tmp__1112 = *(&llvm_cbe_cppVar_690);
  *(&llvm_cbe_cppVar_667) = llvm_cbe_tmp__1112;
  goto llvm_cbe_tmp__1146;

llvm_cbe_tmp__1146:
  llvm_cbe_tmp__1113 = *(&llvm_cbe_cppVar_667);
  *(&llvm_cbe_cppVar_655) = llvm_cbe_tmp__1113;
  goto llvm_cbe_tmp__1123;

llvm_cbe_tmp__1123:
  llvm_cbe_tmp__1114 = *(&llvm_cbe_cppVar_655);
  return llvm_cbe_tmp__1114;
}


unsigned long long _ZN11model_train29cppUpdateFun_train_input_doneElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1159;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1160;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1161;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1162;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1163;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1164;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1165;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1166;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1167;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1168;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1169;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1170;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__1171;
  unsigned long long llvm_cbe_tmp__1172;
  unsigned char llvm_cbe_tmp__1173;
  unsigned long long llvm_cbe_tmp__1174;
  unsigned long long llvm_cbe_tmp__1175;
  unsigned char llvm_cbe_tmp__1176;
  unsigned long long llvm_cbe_tmp__1177;
  unsigned long long llvm_cbe_tmp__1178;
  unsigned char llvm_cbe_tmp__1179;
  unsigned long long llvm_cbe_tmp__1180;
  unsigned long long llvm_cbe_tmp__1181;
  unsigned long long llvm_cbe_tmp__1182;
  unsigned long long llvm_cbe_tmp__1183;
  unsigned char llvm_cbe_tmp__1184;
  unsigned char llvm_cbe_tmp__1185;
  bool llvm_cbe_tmp__1186;
  bool llvm_cbe_tmp__1187;
  bool llvm_cbe_tmp__1187__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1188;
  unsigned long long llvm_cbe_tmp__1189;
  unsigned long long llvm_cbe_tmp__1190;
  unsigned long long llvm_cbe_tmp__1191;
  unsigned long long llvm_cbe_tmp__1192;
  unsigned long long llvm_cbe_tmp__1193;
  unsigned long long llvm_cbe_tmp__1194;

  *(&llvm_cbe_tmp__1159) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1160) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1161) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1162) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1163) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1164) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1165) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1166) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1167) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1168) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1169) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1170) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1171 = *(&llvm_cbe_tmp__1159);
  llvm_cbe_tmp__1172 = *((&llvm_cbe_tmp__1171->field29));
  *(&llvm_cbe_cppVar_707) = (((unsigned char )(bool )(llvm_cbe_tmp__1172 == 0ull)));
  llvm_cbe_tmp__1173 = *(&llvm_cbe_cppVar_707);
  if ((((((bool )llvm_cbe_tmp__1173&1u))&1))) {
    goto llvm_cbe_tmp__1195;
  } else {
    goto llvm_cbe_tmp__1196;
  }

llvm_cbe_tmp__1195:
  llvm_cbe_tmp__1174 = *((&llvm_cbe_tmp__1171->field26));
  *(&llvm_cbe_cppVar_705) = llvm_cbe_tmp__1174;
  goto llvm_cbe_tmp__1197;

llvm_cbe_tmp__1196:
  llvm_cbe_tmp__1175 = *((&llvm_cbe_tmp__1171->field29));
  *(&llvm_cbe_cppVar_710) = (((unsigned char )(bool )(llvm_cbe_tmp__1175 == 1ull)));
  llvm_cbe_tmp__1176 = *(&llvm_cbe_cppVar_710);
  if ((((((bool )llvm_cbe_tmp__1176&1u))&1))) {
    goto llvm_cbe_tmp__1198;
  } else {
    goto llvm_cbe_tmp__1199;
  }

llvm_cbe_tmp__1198:
  llvm_cbe_tmp__1177 = *((&llvm_cbe_tmp__1171->field26));
  *(&llvm_cbe_cppVar_708) = llvm_cbe_tmp__1177;
  goto llvm_cbe_tmp__1200;

llvm_cbe_tmp__1199:
  llvm_cbe_tmp__1178 = *((&llvm_cbe_tmp__1171->field29));
  *(&llvm_cbe_cppVar_713) = (((unsigned char )(bool )(llvm_cbe_tmp__1178 == 2ull)));
  llvm_cbe_tmp__1179 = *(&llvm_cbe_cppVar_713);
  if ((((((bool )llvm_cbe_tmp__1179&1u))&1))) {
    goto llvm_cbe_tmp__1201;
  } else {
    goto llvm_cbe_tmp__1202;
  }

llvm_cbe_tmp__1201:
  llvm_cbe_tmp__1180 = *((&llvm_cbe_tmp__1171->field25));
  llvm_cbe_tmp__1181 = *((&llvm_cbe_tmp__1171->field9));
  *(&llvm_cbe_cppVar_715) = (((unsigned char )(bool )(llvm_cbe_tmp__1180 == llvm_cbe_tmp__1181)));
  llvm_cbe_tmp__1182 = *((&llvm_cbe_tmp__1171->field30));
  llvm_cbe_tmp__1183 = *((&llvm_cbe_tmp__1171->field14));
  *(&llvm_cbe_cppVar_716) = (((unsigned char )(bool )(llvm_cbe_tmp__1182 == llvm_cbe_tmp__1183)));
  llvm_cbe_tmp__1184 = *(&llvm_cbe_cppVar_715);
  if ((((((bool )llvm_cbe_tmp__1184&1u))&1))) {
    goto llvm_cbe_tmp__1203;
  } else {
    llvm_cbe_tmp__1187__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1204;
  }

llvm_cbe_tmp__1203:
  llvm_cbe_tmp__1185 = *(&llvm_cbe_cppVar_716);
  llvm_cbe_tmp__1186 = ((((bool )llvm_cbe_tmp__1185&1u))&1);
  llvm_cbe_tmp__1187__PHI_TEMPORARY = llvm_cbe_tmp__1186;   /* for PHI node */
  goto llvm_cbe_tmp__1204;

llvm_cbe_tmp__1204:
  llvm_cbe_tmp__1187 = ((llvm_cbe_tmp__1187__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_717) = (((unsigned char )(bool )llvm_cbe_tmp__1187));
  llvm_cbe_tmp__1188 = *(&llvm_cbe_cppVar_717);
  if ((((((bool )llvm_cbe_tmp__1188&1u))&1))) {
    goto llvm_cbe_tmp__1205;
  } else {
    goto llvm_cbe_tmp__1206;
  }

llvm_cbe_tmp__1205:
  *(&llvm_cbe_cppVar_714) = 0ull;
  goto llvm_cbe_tmp__1207;

llvm_cbe_tmp__1206:
  llvm_cbe_tmp__1189 = *((&llvm_cbe_tmp__1171->field26));
  *(&llvm_cbe_cppVar_714) = llvm_cbe_tmp__1189;
  goto llvm_cbe_tmp__1207;

llvm_cbe_tmp__1207:
  llvm_cbe_tmp__1190 = *(&llvm_cbe_cppVar_714);
  *(&llvm_cbe_cppVar_711) = llvm_cbe_tmp__1190;
  goto llvm_cbe_tmp__1208;

llvm_cbe_tmp__1202:
  llvm_cbe_tmp__1191 = *((&llvm_cbe_tmp__1171->field26));
  *(&llvm_cbe_cppVar_711) = llvm_cbe_tmp__1191;
  goto llvm_cbe_tmp__1208;

llvm_cbe_tmp__1208:
  llvm_cbe_tmp__1192 = *(&llvm_cbe_cppVar_711);
  *(&llvm_cbe_cppVar_708) = llvm_cbe_tmp__1192;
  goto llvm_cbe_tmp__1200;

llvm_cbe_tmp__1200:
  llvm_cbe_tmp__1193 = *(&llvm_cbe_cppVar_708);
  *(&llvm_cbe_cppVar_705) = llvm_cbe_tmp__1193;
  goto llvm_cbe_tmp__1197;

llvm_cbe_tmp__1197:
  llvm_cbe_tmp__1194 = *(&llvm_cbe_cppVar_705);
  return llvm_cbe_tmp__1194;
}


unsigned long long _ZN11model_train22cppUpdateFun_train_maxElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1209;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1210;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1211;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1212;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1213;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1214;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1215;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1216;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1217;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1218;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1219;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1220;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__1221;
  unsigned long long llvm_cbe_tmp__1222;
  unsigned char llvm_cbe_tmp__1223;
  unsigned long long llvm_cbe_tmp__1224;
  unsigned long long llvm_cbe_tmp__1225;
  unsigned char llvm_cbe_tmp__1226;
  unsigned long long llvm_cbe_tmp__1227;
  unsigned char llvm_cbe_tmp__1228;
  unsigned char llvm_cbe_tmp__1229;
  bool llvm_cbe_tmp__1230;
  bool llvm_cbe_tmp__1231;
  bool llvm_cbe_tmp__1231__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1232;
  unsigned long long llvm_cbe_tmp__1233;
  unsigned long long llvm_cbe_tmp__1234;
  unsigned char llvm_cbe_tmp__1235;
  unsigned long long llvm_cbe_tmp__1236;
  unsigned char llvm_cbe_tmp__1237;
  unsigned long long llvm_cbe_tmp__1238;
  unsigned long long llvm_cbe_tmp__1239;
  unsigned long long llvm_cbe_tmp__1240;
  unsigned long long llvm_cbe_tmp__1241;
  unsigned long long llvm_cbe_tmp__1242;
  unsigned long long llvm_cbe_tmp__1243;
  unsigned char llvm_cbe_tmp__1244;
  unsigned long long llvm_cbe_tmp__1245;
  unsigned long long llvm_cbe_tmp__1246;
  unsigned long long llvm_cbe_tmp__1247;
  unsigned long long llvm_cbe_tmp__1248;
  unsigned long long llvm_cbe_tmp__1249;
  unsigned long long llvm_cbe_tmp__1250;
  unsigned long long llvm_cbe_tmp__1251;
  unsigned long long llvm_cbe_tmp__1252;
  unsigned long long llvm_cbe_tmp__1253;
  unsigned long long llvm_cbe_tmp__1254;
  unsigned long long llvm_cbe_tmp__1255;
  unsigned long long llvm_cbe_tmp__1256;
  unsigned long long llvm_cbe_tmp__1257;
  unsigned long long llvm_cbe_tmp__1258;
  unsigned long long llvm_cbe_tmp__1259;
  unsigned long long llvm_cbe_tmp__1260;
  unsigned long long llvm_cbe_tmp__1261;
  unsigned long long llvm_cbe_tmp__1261__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1262;
  unsigned long long llvm_cbe_tmp__1263;
  unsigned long long llvm_cbe_tmp__1264;
  unsigned long long llvm_cbe_tmp__1265;
  unsigned long long llvm_cbe_tmp__1266;
  unsigned long long llvm_cbe_tmp__1267;
  unsigned long long llvm_cbe_tmp__1268;
  unsigned long long llvm_cbe_tmp__1269;
  unsigned long long llvm_cbe_tmp__1270;
  unsigned long long llvm_cbe_tmp__1271;
  unsigned long long llvm_cbe_tmp__1272;
  unsigned long long llvm_cbe_tmp__1273;
  unsigned char llvm_cbe_tmp__1274;
  unsigned long long llvm_cbe_tmp__1275;
  unsigned long long llvm_cbe_tmp__1276;
  unsigned long long llvm_cbe_tmp__1277;
  unsigned long long llvm_cbe_tmp__1278;
  unsigned long long llvm_cbe_tmp__1279;
  unsigned long long llvm_cbe_tmp__1280;
  unsigned long long llvm_cbe_tmp__1281;
  unsigned long long llvm_cbe_tmp__1282;
  unsigned long long llvm_cbe_tmp__1282__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1283;
  unsigned long long llvm_cbe_tmp__1284;
  unsigned long long llvm_cbe_tmp__1285;
  unsigned long long llvm_cbe_tmp__1286;
  unsigned long long llvm_cbe_tmp__1287;
  unsigned long long llvm_cbe_tmp__1288;
  unsigned long long llvm_cbe_tmp__1288__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1289;
  unsigned long long llvm_cbe_tmp__1290;
  unsigned long long llvm_cbe_tmp__1291;
  unsigned long long llvm_cbe_tmp__1292;
  unsigned long long llvm_cbe_tmp__1293;
  unsigned long long llvm_cbe_tmp__1294;
  unsigned long long llvm_cbe_tmp__1295;
  unsigned char llvm_cbe_tmp__1296;
  unsigned char llvm_cbe_tmp__1297;
  bool llvm_cbe_tmp__1298;
  bool llvm_cbe_tmp__1299;
  bool llvm_cbe_tmp__1299__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1300;
  unsigned long long llvm_cbe_tmp__1301;
  unsigned char llvm_cbe_tmp__1302;
  unsigned long long llvm_cbe_tmp__1303;
  unsigned long long llvm_cbe_tmp__1304;
  unsigned long long llvm_cbe_tmp__1305;
  unsigned long long llvm_cbe_tmp__1306;
  unsigned long long llvm_cbe_tmp__1307;
  unsigned long long llvm_cbe_tmp__1308;
  unsigned char llvm_cbe_tmp__1309;
  unsigned char llvm_cbe_tmp__1310;
  bool llvm_cbe_tmp__1311;
  bool llvm_cbe_tmp__1312;
  bool llvm_cbe_tmp__1312__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1313;
  unsigned long long llvm_cbe_tmp__1314;
  unsigned long long llvm_cbe_tmp__1315;
  unsigned char llvm_cbe_tmp__1316;
  unsigned char llvm_cbe_tmp__1317;
  bool llvm_cbe_tmp__1318;
  bool llvm_cbe_tmp__1319;
  bool llvm_cbe_tmp__1319__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1320;
  unsigned long long llvm_cbe_tmp__1321;
  unsigned long long llvm_cbe_tmp__1322;
  unsigned long long llvm_cbe_tmp__1323;
  unsigned long long llvm_cbe_tmp__1324;
  unsigned long long llvm_cbe_tmp__1325;
  unsigned long long llvm_cbe_tmp__1326;
  unsigned long long llvm_cbe_tmp__1327;
  unsigned long long llvm_cbe_tmp__1328;
  unsigned long long llvm_cbe_tmp__1329;

  *(&llvm_cbe_tmp__1209) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1210) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1211) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1212) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1213) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1214) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1215) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1216) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1217) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1218) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1219) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1220) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1221 = *(&llvm_cbe_tmp__1209);
  llvm_cbe_tmp__1222 = *((&llvm_cbe_tmp__1221->field29));
  *(&llvm_cbe_cppVar_722) = (((unsigned char )(bool )(llvm_cbe_tmp__1222 == 0ull)));
  llvm_cbe_tmp__1223 = *(&llvm_cbe_cppVar_722);
  if ((((((bool )llvm_cbe_tmp__1223&1u))&1))) {
    goto llvm_cbe_tmp__1330;
  } else {
    goto llvm_cbe_tmp__1331;
  }

llvm_cbe_tmp__1330:
  llvm_cbe_tmp__1224 = *((&llvm_cbe_tmp__1221->field27));
  *(&llvm_cbe_cppVar_720) = llvm_cbe_tmp__1224;
  goto llvm_cbe_tmp__1332;

llvm_cbe_tmp__1331:
  llvm_cbe_tmp__1225 = *((&llvm_cbe_tmp__1221->field29));
  *(&llvm_cbe_cppVar_725) = (((unsigned char )(bool )(llvm_cbe_tmp__1225 == 1ull)));
  llvm_cbe_tmp__1226 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1226&1u))&1))) {
    goto llvm_cbe_tmp__1333;
  } else {
    goto llvm_cbe_tmp__1334;
  }

llvm_cbe_tmp__1333:
  llvm_cbe_tmp__1227 = *((&llvm_cbe_tmp__1221->field15));
  *(&llvm_cbe_cppVar_728) = (((unsigned char )(bool )(llvm_cbe_tmp__1227 == 0ull)));
  llvm_cbe_tmp__1228 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1228&1u))&1))) {
    goto llvm_cbe_tmp__1335;
  } else {
    llvm_cbe_tmp__1231__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1336;
  }

llvm_cbe_tmp__1335:
  llvm_cbe_tmp__1229 = *(&llvm_cbe_cppVar_728);
  llvm_cbe_tmp__1230 = ((((bool )llvm_cbe_tmp__1229&1u))&1);
  llvm_cbe_tmp__1231__PHI_TEMPORARY = llvm_cbe_tmp__1230;   /* for PHI node */
  goto llvm_cbe_tmp__1336;

llvm_cbe_tmp__1336:
  llvm_cbe_tmp__1231 = ((llvm_cbe_tmp__1231__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_729) = (((unsigned char )(bool )llvm_cbe_tmp__1231));
  llvm_cbe_tmp__1232 = *(&llvm_cbe_cppVar_729);
  if ((((((bool )llvm_cbe_tmp__1232&1u))&1))) {
    goto llvm_cbe_tmp__1337;
  } else {
    goto llvm_cbe_tmp__1338;
  }

llvm_cbe_tmp__1337:
  llvm_cbe_tmp__1233 = *((&llvm_cbe_tmp__1221->field25));
  llvm_cbe_tmp__1234 = *((&llvm_cbe_tmp__1221->field9));
  *(&llvm_cbe_cppVar_731) = (((unsigned char )(bool )(llvm_cbe_tmp__1233 == llvm_cbe_tmp__1234)));
  llvm_cbe_tmp__1235 = *(&llvm_cbe_cppVar_731);
  if ((((((bool )llvm_cbe_tmp__1235&1u))&1))) {
    goto llvm_cbe_tmp__1339;
  } else {
    goto llvm_cbe_tmp__1340;
  }

llvm_cbe_tmp__1339:
  llvm_cbe_tmp__1236 = *((&llvm_cbe_tmp__1221->field25));
  *(&llvm_cbe_cppVar_735) = (((unsigned char )(bool )(llvm_cbe_tmp__1236 == 0ull)));
  llvm_cbe_tmp__1237 = *(&llvm_cbe_cppVar_735);
  if ((((((bool )llvm_cbe_tmp__1237&1u))&1))) {
    goto llvm_cbe_tmp__1341;
  } else {
    goto llvm_cbe_tmp__1342;
  }

llvm_cbe_tmp__1341:
  *(&llvm_cbe_cppVar_733) = 0ull;
  goto llvm_cbe_tmp__1343;

llvm_cbe_tmp__1342:
  llvm_cbe_tmp__1238 = *((&llvm_cbe_tmp__1221->field28));
  *(&llvm_cbe_cppVar_733) = llvm_cbe_tmp__1238;
  goto llvm_cbe_tmp__1343;

llvm_cbe_tmp__1343:
  llvm_cbe_tmp__1239 = *((&llvm_cbe_tmp__1221->field25));
  llvm_cbe_tmp__1240 = *((&llvm_cbe_tmp__1221->field43));
  *(&llvm_cbe_cppVar_738) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1239) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1240);
  llvm_cbe_tmp__1241 = *(&llvm_cbe_cppVar_738);
  llvm_cbe_tmp__1242 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__1221->field4)), llvm_cbe_tmp__1241);
  *(&llvm_cbe_cppVar_739) = llvm_cbe_tmp__1242;
  llvm_cbe_tmp__1243 = *(&llvm_cbe_cppVar_739);
  *(&llvm_cbe_cppVar_741) = (((unsigned char )(bool )(llvm_cbe_tmp__1243 == 1ull)));
  llvm_cbe_tmp__1244 = *(&llvm_cbe_cppVar_741);
  if ((((((bool )llvm_cbe_tmp__1244&1u))&1))) {
    goto llvm_cbe_tmp__1344;
  } else {
    goto llvm_cbe_tmp__1345;
  }

llvm_cbe_tmp__1344:
  llvm_cbe_tmp__1245 = *((&llvm_cbe_tmp__1221->field30));
  *(&llvm_cbe_cppVar_743) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__1245))));
  llvm_cbe_tmp__1246 = *(&llvm_cbe_cppVar_743);
  llvm_cbe_tmp__1247 = *((&llvm_cbe_tmp__1221->field39));
  *(&llvm_cbe_cppVar_743) = (llvm_cbe_tmp__1246 & llvm_cbe_tmp__1247);
  llvm_cbe_tmp__1248 = *(&llvm_cbe_cppVar_743);
  llvm_cbe_tmp__1249 = *((&llvm_cbe_tmp__1221->field25));
  *(&llvm_cbe_cppVar_744) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1248) + ((unsigned long long )llvm_cbe_tmp__1249))));
  llvm_cbe_tmp__1250 = *(&llvm_cbe_cppVar_744);
  llvm_cbe_tmp__1251 = *((&llvm_cbe_tmp__1221->field39));
  *(&llvm_cbe_cppVar_744) = (llvm_cbe_tmp__1250 & llvm_cbe_tmp__1251);
  llvm_cbe_tmp__1252 = *(&llvm_cbe_cppVar_744);
  llvm_cbe_tmp__1253 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1221->field3)), llvm_cbe_tmp__1252);
  *(&llvm_cbe_cppVar_745) = llvm_cbe_tmp__1253;
  llvm_cbe_tmp__1254 = *(&llvm_cbe_cppVar_745);
  llvm_cbe_tmp__1255 = *((&llvm_cbe_tmp__1221->field43));
  *(&llvm_cbe_cppVar_746) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1254) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1255);
  llvm_cbe_tmp__1256 = *(&llvm_cbe_cppVar_746);
  llvm_cbe_tmp__1257 = *((&llvm_cbe_tmp__1221->field47));
  llvm_cbe_tmp__1258 = *(&llvm_cbe_cppVar_746);
  if (((llvm_cbe_tmp__1256 & llvm_cbe_tmp__1257) != 0ull)) {
    goto llvm_cbe_tmp__1346;
  } else {
    llvm_cbe_tmp__1261__PHI_TEMPORARY = llvm_cbe_tmp__1258;   /* for PHI node */
    goto llvm_cbe_tmp__1347;
  }

llvm_cbe_tmp__1346:
  llvm_cbe_tmp__1259 = *((&llvm_cbe_tmp__1221->field49));
  llvm_cbe_tmp__1260 = llvm_cbe_tmp__1258 | llvm_cbe_tmp__1259;
  llvm_cbe_tmp__1261__PHI_TEMPORARY = llvm_cbe_tmp__1260;   /* for PHI node */
  goto llvm_cbe_tmp__1347;

llvm_cbe_tmp__1347:
  llvm_cbe_tmp__1261 = llvm_cbe_tmp__1261__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_747) = llvm_cbe_tmp__1261;
  llvm_cbe_tmp__1262 = *(&llvm_cbe_cppVar_745);
  llvm_cbe_tmp__1263 = *((&llvm_cbe_tmp__1221->field38));
  *(&llvm_cbe_cppVar_748) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1262) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1263);
  llvm_cbe_tmp__1264 = *(&llvm_cbe_cppVar_747);
  llvm_cbe_tmp__1265 = *(&llvm_cbe_cppVar_748);
  *(&llvm_cbe_cppVar_749) = ((llvm_cbe_tmp__1264 << 1ull) | llvm_cbe_tmp__1265);
  llvm_cbe_tmp__1266 = *(&llvm_cbe_cppVar_749);
  llvm_cbe_tmp__1267 = *((&llvm_cbe_tmp__1221->field39));
  *(&llvm_cbe_cppVar_749) = (llvm_cbe_tmp__1266 & llvm_cbe_tmp__1267);
  llvm_cbe_tmp__1268 = *(&llvm_cbe_cppVar_749);
  *(&llvm_cbe_cppVar_737) = llvm_cbe_tmp__1268;
  goto llvm_cbe_tmp__1348;

llvm_cbe_tmp__1345:
  *(&llvm_cbe_cppVar_737) = 0ull;
  goto llvm_cbe_tmp__1348;

llvm_cbe_tmp__1348:
  llvm_cbe_tmp__1269 = *(&llvm_cbe_cppVar_733);
  llvm_cbe_tmp__1270 = *(&llvm_cbe_cppVar_737);
  *(&llvm_cbe_cppVar_750) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1269) + ((unsigned long long )llvm_cbe_tmp__1270))));
  llvm_cbe_tmp__1271 = *(&llvm_cbe_cppVar_750);
  llvm_cbe_tmp__1272 = *((&llvm_cbe_tmp__1221->field39));
  *(&llvm_cbe_cppVar_750) = (llvm_cbe_tmp__1271 & llvm_cbe_tmp__1272);
  llvm_cbe_tmp__1273 = *((&llvm_cbe_tmp__1221->field7));
  *(&llvm_cbe_cppVar_753) = (((unsigned char )(bool )(llvm_cbe_tmp__1273 == 0ull)));
  llvm_cbe_tmp__1274 = *(&llvm_cbe_cppVar_753);
  if ((((((bool )llvm_cbe_tmp__1274&1u))&1))) {
    goto llvm_cbe_tmp__1349;
  } else {
    goto llvm_cbe_tmp__1350;
  }

llvm_cbe_tmp__1349:
  *(&llvm_cbe_cppVar_755) = 18446744073709550616ull;
  llvm_cbe_tmp__1275 = *(&llvm_cbe_cppVar_755);
  *(&llvm_cbe_cppVar_751) = llvm_cbe_tmp__1275;
  goto llvm_cbe_tmp__1351;

llvm_cbe_tmp__1350:
  llvm_cbe_tmp__1276 = *((&llvm_cbe_tmp__1221->field27));
  *(&llvm_cbe_cppVar_751) = llvm_cbe_tmp__1276;
  goto llvm_cbe_tmp__1351;

llvm_cbe_tmp__1351:
  llvm_cbe_tmp__1277 = *(&llvm_cbe_cppVar_750);
  llvm_cbe_tmp__1278 = *((&llvm_cbe_tmp__1221->field46));
  llvm_cbe_tmp__1279 = *(&llvm_cbe_cppVar_750);
  if (((llvm_cbe_tmp__1277 & llvm_cbe_tmp__1278) != 0ull)) {
    goto llvm_cbe_tmp__1352;
  } else {
    llvm_cbe_tmp__1282__PHI_TEMPORARY = llvm_cbe_tmp__1279;   /* for PHI node */
    goto llvm_cbe_tmp__1353;
  }

llvm_cbe_tmp__1352:
  llvm_cbe_tmp__1280 = *((&llvm_cbe_tmp__1221->field48));
  llvm_cbe_tmp__1281 = llvm_cbe_tmp__1279 | llvm_cbe_tmp__1280;
  llvm_cbe_tmp__1282__PHI_TEMPORARY = llvm_cbe_tmp__1281;   /* for PHI node */
  goto llvm_cbe_tmp__1353;

llvm_cbe_tmp__1353:
  llvm_cbe_tmp__1282 = llvm_cbe_tmp__1282__PHI_TEMPORARY;
  llvm_cbe_tmp__1283 = *(&llvm_cbe_cppVar_751);
  llvm_cbe_tmp__1284 = *((&llvm_cbe_tmp__1221->field46));
  llvm_cbe_tmp__1285 = *(&llvm_cbe_cppVar_751);
  if (((llvm_cbe_tmp__1283 & llvm_cbe_tmp__1284) != 0ull)) {
    goto llvm_cbe_tmp__1354;
  } else {
    llvm_cbe_tmp__1288__PHI_TEMPORARY = llvm_cbe_tmp__1285;   /* for PHI node */
    goto llvm_cbe_tmp__1355;
  }

llvm_cbe_tmp__1354:
  llvm_cbe_tmp__1286 = *((&llvm_cbe_tmp__1221->field48));
  llvm_cbe_tmp__1287 = llvm_cbe_tmp__1285 | llvm_cbe_tmp__1286;
  llvm_cbe_tmp__1288__PHI_TEMPORARY = llvm_cbe_tmp__1287;   /* for PHI node */
  goto llvm_cbe_tmp__1355;

llvm_cbe_tmp__1355:
  llvm_cbe_tmp__1288 = llvm_cbe_tmp__1288__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_756) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1282) > ((signed long long )llvm_cbe_tmp__1288))));
  llvm_cbe_tmp__1289 = *(&llvm_cbe_cppVar_756);
  if ((((((bool )llvm_cbe_tmp__1289&1u))&1))) {
    goto llvm_cbe_tmp__1356;
  } else {
    goto llvm_cbe_tmp__1357;
  }

llvm_cbe_tmp__1356:
  llvm_cbe_tmp__1290 = *(&llvm_cbe_cppVar_750);
  *(&llvm_cbe_cppVar_732) = llvm_cbe_tmp__1290;
  goto llvm_cbe_tmp__1358;

llvm_cbe_tmp__1357:
  llvm_cbe_tmp__1291 = *(&llvm_cbe_cppVar_751);
  *(&llvm_cbe_cppVar_732) = llvm_cbe_tmp__1291;
  goto llvm_cbe_tmp__1358;

llvm_cbe_tmp__1358:
  llvm_cbe_tmp__1292 = *(&llvm_cbe_cppVar_732);
  *(&llvm_cbe_cppVar_730) = llvm_cbe_tmp__1292;
  goto llvm_cbe_tmp__1359;

llvm_cbe_tmp__1340:
  llvm_cbe_tmp__1293 = *((&llvm_cbe_tmp__1221->field27));
  *(&llvm_cbe_cppVar_730) = llvm_cbe_tmp__1293;
  goto llvm_cbe_tmp__1359;

llvm_cbe_tmp__1359:
  llvm_cbe_tmp__1294 = *(&llvm_cbe_cppVar_730);
  *(&llvm_cbe_cppVar_726) = llvm_cbe_tmp__1294;
  goto llvm_cbe_tmp__1360;

llvm_cbe_tmp__1338:
  llvm_cbe_tmp__1295 = *((&llvm_cbe_tmp__1221->field15));
  *(&llvm_cbe_cppVar_759) = (((unsigned char )(bool )(llvm_cbe_tmp__1295 == 1ull)));
  llvm_cbe_tmp__1296 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1296&1u))&1))) {
    goto llvm_cbe_tmp__1361;
  } else {
    llvm_cbe_tmp__1299__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1362;
  }

llvm_cbe_tmp__1361:
  llvm_cbe_tmp__1297 = *(&llvm_cbe_cppVar_759);
  llvm_cbe_tmp__1298 = ((((bool )llvm_cbe_tmp__1297&1u))&1);
  llvm_cbe_tmp__1299__PHI_TEMPORARY = llvm_cbe_tmp__1298;   /* for PHI node */
  goto llvm_cbe_tmp__1362;

llvm_cbe_tmp__1362:
  llvm_cbe_tmp__1299 = ((llvm_cbe_tmp__1299__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_760) = (((unsigned char )(bool )llvm_cbe_tmp__1299));
  llvm_cbe_tmp__1300 = *(&llvm_cbe_cppVar_760);
  if ((((((bool )llvm_cbe_tmp__1300&1u))&1))) {
    goto llvm_cbe_tmp__1363;
  } else {
    goto llvm_cbe_tmp__1364;
  }

llvm_cbe_tmp__1363:
  llvm_cbe_tmp__1301 = *((&llvm_cbe_tmp__1221->field7));
  *(&llvm_cbe_cppVar_763) = (((unsigned char )(bool )(llvm_cbe_tmp__1301 == 0ull)));
  llvm_cbe_tmp__1302 = *(&llvm_cbe_cppVar_763);
  llvm_cbe_tmp__1303 = *((&llvm_cbe_tmp__1221->field27));
  if ((((((bool )llvm_cbe_tmp__1302&1u))&1))) {
    goto llvm_cbe_tmp__1365;
  } else {
    goto llvm_cbe_tmp__1366;
  }

llvm_cbe_tmp__1365:
  *(&llvm_cbe_cppVar_765) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1303) - ((unsigned long long )62ull))));
  llvm_cbe_tmp__1304 = *(&llvm_cbe_cppVar_765);
  llvm_cbe_tmp__1305 = *((&llvm_cbe_tmp__1221->field39));
  *(&llvm_cbe_cppVar_765) = (llvm_cbe_tmp__1304 & llvm_cbe_tmp__1305);
  llvm_cbe_tmp__1306 = *(&llvm_cbe_cppVar_765);
  *(&llvm_cbe_cppVar_761) = llvm_cbe_tmp__1306;
  goto llvm_cbe_tmp__1367;

llvm_cbe_tmp__1366:
  *(&llvm_cbe_cppVar_761) = llvm_cbe_tmp__1303;
  goto llvm_cbe_tmp__1367;

llvm_cbe_tmp__1367:
  llvm_cbe_tmp__1307 = *(&llvm_cbe_cppVar_761);
  *(&llvm_cbe_cppVar_757) = llvm_cbe_tmp__1307;
  goto llvm_cbe_tmp__1368;

llvm_cbe_tmp__1364:
  llvm_cbe_tmp__1308 = *((&llvm_cbe_tmp__1221->field15));
  *(&llvm_cbe_cppVar_768) = (((unsigned char )(bool )(llvm_cbe_tmp__1308 == 2ull)));
  llvm_cbe_tmp__1309 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1309&1u))&1))) {
    goto llvm_cbe_tmp__1369;
  } else {
    llvm_cbe_tmp__1312__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1370;
  }

llvm_cbe_tmp__1369:
  llvm_cbe_tmp__1310 = *(&llvm_cbe_cppVar_768);
  llvm_cbe_tmp__1311 = ((((bool )llvm_cbe_tmp__1310&1u))&1);
  llvm_cbe_tmp__1312__PHI_TEMPORARY = llvm_cbe_tmp__1311;   /* for PHI node */
  goto llvm_cbe_tmp__1370;

llvm_cbe_tmp__1370:
  llvm_cbe_tmp__1312 = ((llvm_cbe_tmp__1312__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_769) = (((unsigned char )(bool )llvm_cbe_tmp__1312));
  llvm_cbe_tmp__1313 = *(&llvm_cbe_cppVar_769);
  if ((((((bool )llvm_cbe_tmp__1313&1u))&1))) {
    goto llvm_cbe_tmp__1371;
  } else {
    goto llvm_cbe_tmp__1372;
  }

llvm_cbe_tmp__1371:
  llvm_cbe_tmp__1314 = *((&llvm_cbe_tmp__1221->field27));
  *(&llvm_cbe_cppVar_766) = llvm_cbe_tmp__1314;
  goto llvm_cbe_tmp__1373;

llvm_cbe_tmp__1372:
  llvm_cbe_tmp__1315 = *((&llvm_cbe_tmp__1221->field15));
  *(&llvm_cbe_cppVar_772) = (((unsigned char )(bool )(llvm_cbe_tmp__1315 == 3ull)));
  llvm_cbe_tmp__1316 = *(&llvm_cbe_cppVar_725);
  if ((((((bool )llvm_cbe_tmp__1316&1u))&1))) {
    goto llvm_cbe_tmp__1374;
  } else {
    llvm_cbe_tmp__1319__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1375;
  }

llvm_cbe_tmp__1374:
  llvm_cbe_tmp__1317 = *(&llvm_cbe_cppVar_772);
  llvm_cbe_tmp__1318 = ((((bool )llvm_cbe_tmp__1317&1u))&1);
  llvm_cbe_tmp__1319__PHI_TEMPORARY = llvm_cbe_tmp__1318;   /* for PHI node */
  goto llvm_cbe_tmp__1375;

llvm_cbe_tmp__1375:
  llvm_cbe_tmp__1319 = ((llvm_cbe_tmp__1319__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_773) = (((unsigned char )(bool )llvm_cbe_tmp__1319));
  llvm_cbe_tmp__1320 = *((&llvm_cbe_tmp__1221->field27));
  *(&llvm_cbe_cppVar_770) = llvm_cbe_tmp__1320;
  llvm_cbe_tmp__1321 = *(&llvm_cbe_cppVar_770);
  *(&llvm_cbe_cppVar_766) = llvm_cbe_tmp__1321;
  goto llvm_cbe_tmp__1373;

llvm_cbe_tmp__1373:
  llvm_cbe_tmp__1322 = *(&llvm_cbe_cppVar_766);
  *(&llvm_cbe_cppVar_757) = llvm_cbe_tmp__1322;
  goto llvm_cbe_tmp__1368;

llvm_cbe_tmp__1368:
  llvm_cbe_tmp__1323 = *(&llvm_cbe_cppVar_757);
  *(&llvm_cbe_cppVar_726) = llvm_cbe_tmp__1323;
  goto llvm_cbe_tmp__1360;

llvm_cbe_tmp__1360:
  llvm_cbe_tmp__1324 = *(&llvm_cbe_cppVar_726);
  *(&llvm_cbe_cppVar_723) = llvm_cbe_tmp__1324;
  goto llvm_cbe_tmp__1376;

llvm_cbe_tmp__1334:
  llvm_cbe_tmp__1325 = *((&llvm_cbe_tmp__1221->field29));
  *(&llvm_cbe_cppVar_776) = (((unsigned char )(bool )(llvm_cbe_tmp__1325 == 2ull)));
  llvm_cbe_tmp__1326 = *((&llvm_cbe_tmp__1221->field27));
  *(&llvm_cbe_cppVar_774) = llvm_cbe_tmp__1326;
  llvm_cbe_tmp__1327 = *(&llvm_cbe_cppVar_774);
  *(&llvm_cbe_cppVar_723) = llvm_cbe_tmp__1327;
  goto llvm_cbe_tmp__1376;

llvm_cbe_tmp__1376:
  llvm_cbe_tmp__1328 = *(&llvm_cbe_cppVar_723);
  *(&llvm_cbe_cppVar_720) = llvm_cbe_tmp__1328;
  goto llvm_cbe_tmp__1332;

llvm_cbe_tmp__1332:
  llvm_cbe_tmp__1329 = *(&llvm_cbe_cppVar_720);
  return llvm_cbe_tmp__1329;
}


unsigned long long _ZN11model_train22cppUpdateFun_train_sumElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1377;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1378;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1379;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1380;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1381;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1382;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1383;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1384;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1385;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1386;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1387;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1388;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__1389;
  unsigned long long llvm_cbe_tmp__1390;
  unsigned char llvm_cbe_tmp__1391;
  unsigned long long llvm_cbe_tmp__1392;
  unsigned char llvm_cbe_tmp__1393;
  unsigned long long llvm_cbe_tmp__1394;
  unsigned long long llvm_cbe_tmp__1395;
  unsigned long long llvm_cbe_tmp__1396;
  unsigned long long llvm_cbe_tmp__1397;
  unsigned long long llvm_cbe_tmp__1398;
  unsigned long long llvm_cbe_tmp__1399;
  unsigned char llvm_cbe_tmp__1400;
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
  unsigned long long llvm_cbe_tmp__1414;
  unsigned long long llvm_cbe_tmp__1415;
  unsigned long long llvm_cbe_tmp__1416;
  unsigned long long llvm_cbe_tmp__1417;
  unsigned long long llvm_cbe_tmp__1417__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1418;
  unsigned long long llvm_cbe_tmp__1419;
  unsigned long long llvm_cbe_tmp__1420;
  unsigned long long llvm_cbe_tmp__1421;
  unsigned long long llvm_cbe_tmp__1422;
  unsigned long long llvm_cbe_tmp__1423;
  unsigned long long llvm_cbe_tmp__1424;
  unsigned long long llvm_cbe_tmp__1425;
  unsigned long long llvm_cbe_tmp__1426;
  unsigned long long llvm_cbe_tmp__1427;
  unsigned long long llvm_cbe_tmp__1428;
  unsigned long long llvm_cbe_tmp__1429;
  unsigned long long llvm_cbe_tmp__1430;
  unsigned char llvm_cbe_tmp__1431;
  unsigned long long llvm_cbe_tmp__1432;
  unsigned char llvm_cbe_tmp__1433;
  unsigned char llvm_cbe_tmp__1434;
  bool llvm_cbe_tmp__1435;
  bool llvm_cbe_tmp__1436;
  bool llvm_cbe_tmp__1436__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1437;
  unsigned long long llvm_cbe_tmp__1438;
  unsigned char llvm_cbe_tmp__1439;
  unsigned long long llvm_cbe_tmp__1440;
  unsigned long long llvm_cbe_tmp__1441;
  unsigned long long llvm_cbe_tmp__1442;
  unsigned long long llvm_cbe_tmp__1443;
  unsigned long long llvm_cbe_tmp__1444;
  unsigned long long llvm_cbe_tmp__1445;
  unsigned char llvm_cbe_tmp__1446;
  unsigned long long llvm_cbe_tmp__1447;
  unsigned long long llvm_cbe_tmp__1448;
  unsigned long long llvm_cbe_tmp__1449;
  unsigned long long llvm_cbe_tmp__1450;
  unsigned long long llvm_cbe_tmp__1451;
  unsigned long long llvm_cbe_tmp__1452;
  unsigned long long llvm_cbe_tmp__1453;
  unsigned long long llvm_cbe_tmp__1454;
  unsigned long long llvm_cbe_tmp__1455;
  unsigned long long llvm_cbe_tmp__1456;
  unsigned long long llvm_cbe_tmp__1456__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1457;
  unsigned long long llvm_cbe_tmp__1458;
  unsigned long long llvm_cbe_tmp__1459;
  unsigned long long llvm_cbe_tmp__1460;
  unsigned long long llvm_cbe_tmp__1461;
  unsigned long long llvm_cbe_tmp__1462;
  unsigned long long llvm_cbe_tmp__1463;
  unsigned long long llvm_cbe_tmp__1464;
  unsigned long long llvm_cbe_tmp__1465;
  unsigned long long llvm_cbe_tmp__1466;
  unsigned long long llvm_cbe_tmp__1467;
  unsigned long long llvm_cbe_tmp__1468;
  unsigned long long llvm_cbe_tmp__1469;
  unsigned char llvm_cbe_tmp__1470;
  unsigned char llvm_cbe_tmp__1471;
  bool llvm_cbe_tmp__1472;
  bool llvm_cbe_tmp__1473;
  bool llvm_cbe_tmp__1473__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1474;
  unsigned long long llvm_cbe_tmp__1475;
  unsigned long long llvm_cbe_tmp__1476;
  unsigned char llvm_cbe_tmp__1477;
  unsigned char llvm_cbe_tmp__1478;
  bool llvm_cbe_tmp__1479;
  bool llvm_cbe_tmp__1480;
  bool llvm_cbe_tmp__1480__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1481;
  unsigned long long llvm_cbe_tmp__1482;
  unsigned long long llvm_cbe_tmp__1483;
  unsigned char llvm_cbe_tmp__1484;
  unsigned char llvm_cbe_tmp__1485;
  bool llvm_cbe_tmp__1486;
  bool llvm_cbe_tmp__1487;
  bool llvm_cbe_tmp__1487__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1488;
  unsigned long long llvm_cbe_tmp__1489;
  unsigned long long llvm_cbe_tmp__1490;
  unsigned long long llvm_cbe_tmp__1491;
  unsigned long long llvm_cbe_tmp__1492;
  unsigned long long llvm_cbe_tmp__1493;
  unsigned long long llvm_cbe_tmp__1494;
  unsigned long long llvm_cbe_tmp__1495;
  unsigned long long llvm_cbe_tmp__1496;
  unsigned long long llvm_cbe_tmp__1497;

  *(&llvm_cbe_tmp__1377) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1378) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1379) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1380) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1381) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1382) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1383) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1384) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1385) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1386) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1387) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1388) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1389 = *(&llvm_cbe_tmp__1377);
  llvm_cbe_tmp__1390 = *((&llvm_cbe_tmp__1389->field29));
  *(&llvm_cbe_cppVar_780) = (((unsigned char )(bool )(llvm_cbe_tmp__1390 == 0ull)));
  llvm_cbe_tmp__1391 = *(&llvm_cbe_cppVar_780);
  if ((((((bool )llvm_cbe_tmp__1391&1u))&1))) {
    goto llvm_cbe_tmp__1498;
  } else {
    goto llvm_cbe_tmp__1499;
  }

llvm_cbe_tmp__1498:
  llvm_cbe_tmp__1392 = *((&llvm_cbe_tmp__1389->field30));
  *(&llvm_cbe_cppVar_783) = (((unsigned char )(bool )(llvm_cbe_tmp__1392 == 0ull)));
  llvm_cbe_tmp__1393 = *(&llvm_cbe_cppVar_783);
  if ((((((bool )llvm_cbe_tmp__1393&1u))&1))) {
    goto llvm_cbe_tmp__1500;
  } else {
    goto llvm_cbe_tmp__1501;
  }

llvm_cbe_tmp__1500:
  *(&llvm_cbe_cppVar_781) = 0ull;
  goto llvm_cbe_tmp__1502;

llvm_cbe_tmp__1501:
  llvm_cbe_tmp__1394 = *((&llvm_cbe_tmp__1389->field28));
  *(&llvm_cbe_cppVar_781) = llvm_cbe_tmp__1394;
  goto llvm_cbe_tmp__1502;

llvm_cbe_tmp__1502:
  llvm_cbe_tmp__1395 = *((&llvm_cbe_tmp__1389->field30));
  llvm_cbe_tmp__1396 = *((&llvm_cbe_tmp__1389->field45));
  *(&llvm_cbe_cppVar_786) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1395) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1396);
  llvm_cbe_tmp__1397 = *(&llvm_cbe_cppVar_786);
  llvm_cbe_tmp__1398 = _ZN8type_memIhLj512EE2rdEl(((&llvm_cbe_tmp__1389->field0)), llvm_cbe_tmp__1397);
  *(&llvm_cbe_cppVar_787) = llvm_cbe_tmp__1398;
  llvm_cbe_tmp__1399 = *(&llvm_cbe_cppVar_787);
  *(&llvm_cbe_cppVar_789) = (((unsigned char )(bool )(llvm_cbe_tmp__1399 == 1ull)));
  llvm_cbe_tmp__1400 = *(&llvm_cbe_cppVar_789);
  if ((((((bool )llvm_cbe_tmp__1400&1u))&1))) {
    goto llvm_cbe_tmp__1503;
  } else {
    goto llvm_cbe_tmp__1504;
  }

llvm_cbe_tmp__1503:
  llvm_cbe_tmp__1401 = *((&llvm_cbe_tmp__1389->field30));
  *(&llvm_cbe_cppVar_791) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__1401))));
  llvm_cbe_tmp__1402 = *(&llvm_cbe_cppVar_791);
  llvm_cbe_tmp__1403 = *((&llvm_cbe_tmp__1389->field39));
  *(&llvm_cbe_cppVar_791) = (llvm_cbe_tmp__1402 & llvm_cbe_tmp__1403);
  llvm_cbe_tmp__1404 = *(&llvm_cbe_cppVar_791);
  llvm_cbe_tmp__1405 = *((&llvm_cbe_tmp__1389->field25));
  *(&llvm_cbe_cppVar_792) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1404) + ((unsigned long long )llvm_cbe_tmp__1405))));
  llvm_cbe_tmp__1406 = *(&llvm_cbe_cppVar_792);
  llvm_cbe_tmp__1407 = *((&llvm_cbe_tmp__1389->field39));
  *(&llvm_cbe_cppVar_792) = (llvm_cbe_tmp__1406 & llvm_cbe_tmp__1407);
  llvm_cbe_tmp__1408 = *(&llvm_cbe_cppVar_792);
  llvm_cbe_tmp__1409 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1389->field3)), llvm_cbe_tmp__1408);
  *(&llvm_cbe_cppVar_793) = llvm_cbe_tmp__1409;
  llvm_cbe_tmp__1410 = *(&llvm_cbe_cppVar_793);
  llvm_cbe_tmp__1411 = *((&llvm_cbe_tmp__1389->field43));
  *(&llvm_cbe_cppVar_794) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1410) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1411);
  llvm_cbe_tmp__1412 = *(&llvm_cbe_cppVar_794);
  llvm_cbe_tmp__1413 = *((&llvm_cbe_tmp__1389->field47));
  llvm_cbe_tmp__1414 = *(&llvm_cbe_cppVar_794);
  if (((llvm_cbe_tmp__1412 & llvm_cbe_tmp__1413) != 0ull)) {
    goto llvm_cbe_tmp__1505;
  } else {
    llvm_cbe_tmp__1417__PHI_TEMPORARY = llvm_cbe_tmp__1414;   /* for PHI node */
    goto llvm_cbe_tmp__1506;
  }

llvm_cbe_tmp__1505:
  llvm_cbe_tmp__1415 = *((&llvm_cbe_tmp__1389->field49));
  llvm_cbe_tmp__1416 = llvm_cbe_tmp__1414 | llvm_cbe_tmp__1415;
  llvm_cbe_tmp__1417__PHI_TEMPORARY = llvm_cbe_tmp__1416;   /* for PHI node */
  goto llvm_cbe_tmp__1506;

llvm_cbe_tmp__1506:
  llvm_cbe_tmp__1417 = llvm_cbe_tmp__1417__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_795) = llvm_cbe_tmp__1417;
  llvm_cbe_tmp__1418 = *(&llvm_cbe_cppVar_793);
  llvm_cbe_tmp__1419 = *((&llvm_cbe_tmp__1389->field38));
  *(&llvm_cbe_cppVar_796) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1418) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1419);
  llvm_cbe_tmp__1420 = *(&llvm_cbe_cppVar_795);
  llvm_cbe_tmp__1421 = *(&llvm_cbe_cppVar_796);
  *(&llvm_cbe_cppVar_797) = ((llvm_cbe_tmp__1420 << 1ull) | llvm_cbe_tmp__1421);
  llvm_cbe_tmp__1422 = *(&llvm_cbe_cppVar_797);
  llvm_cbe_tmp__1423 = *((&llvm_cbe_tmp__1389->field39));
  *(&llvm_cbe_cppVar_797) = (llvm_cbe_tmp__1422 & llvm_cbe_tmp__1423);
  llvm_cbe_tmp__1424 = *(&llvm_cbe_cppVar_797);
  *(&llvm_cbe_cppVar_785) = llvm_cbe_tmp__1424;
  goto llvm_cbe_tmp__1507;

llvm_cbe_tmp__1504:
  *(&llvm_cbe_cppVar_785) = 0ull;
  goto llvm_cbe_tmp__1507;

llvm_cbe_tmp__1507:
  llvm_cbe_tmp__1425 = *(&llvm_cbe_cppVar_781);
  llvm_cbe_tmp__1426 = *(&llvm_cbe_cppVar_785);
  *(&llvm_cbe_cppVar_799) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1425) + ((unsigned long long )llvm_cbe_tmp__1426))));
  llvm_cbe_tmp__1427 = *(&llvm_cbe_cppVar_799);
  llvm_cbe_tmp__1428 = *((&llvm_cbe_tmp__1389->field39));
  *(&llvm_cbe_cppVar_799) = (llvm_cbe_tmp__1427 & llvm_cbe_tmp__1428);
  llvm_cbe_tmp__1429 = *(&llvm_cbe_cppVar_799);
  *(&llvm_cbe_cppVar_778) = llvm_cbe_tmp__1429;
  goto llvm_cbe_tmp__1508;

llvm_cbe_tmp__1499:
  llvm_cbe_tmp__1430 = *((&llvm_cbe_tmp__1389->field29));
  *(&llvm_cbe_cppVar_802) = (((unsigned char )(bool )(llvm_cbe_tmp__1430 == 1ull)));
  llvm_cbe_tmp__1431 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1431&1u))&1))) {
    goto llvm_cbe_tmp__1509;
  } else {
    goto llvm_cbe_tmp__1510;
  }

llvm_cbe_tmp__1509:
  llvm_cbe_tmp__1432 = *((&llvm_cbe_tmp__1389->field15));
  *(&llvm_cbe_cppVar_805) = (((unsigned char )(bool )(llvm_cbe_tmp__1432 == 0ull)));
  llvm_cbe_tmp__1433 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1433&1u))&1))) {
    goto llvm_cbe_tmp__1511;
  } else {
    llvm_cbe_tmp__1436__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1512;
  }

llvm_cbe_tmp__1511:
  llvm_cbe_tmp__1434 = *(&llvm_cbe_cppVar_805);
  llvm_cbe_tmp__1435 = ((((bool )llvm_cbe_tmp__1434&1u))&1);
  llvm_cbe_tmp__1436__PHI_TEMPORARY = llvm_cbe_tmp__1435;   /* for PHI node */
  goto llvm_cbe_tmp__1512;

llvm_cbe_tmp__1512:
  llvm_cbe_tmp__1436 = ((llvm_cbe_tmp__1436__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_806) = (((unsigned char )(bool )llvm_cbe_tmp__1436));
  llvm_cbe_tmp__1437 = *(&llvm_cbe_cppVar_806);
  if ((((((bool )llvm_cbe_tmp__1437&1u))&1))) {
    goto llvm_cbe_tmp__1513;
  } else {
    goto llvm_cbe_tmp__1514;
  }

llvm_cbe_tmp__1513:
  llvm_cbe_tmp__1438 = *((&llvm_cbe_tmp__1389->field25));
  *(&llvm_cbe_cppVar_809) = (((unsigned char )(bool )(llvm_cbe_tmp__1438 == 0ull)));
  llvm_cbe_tmp__1439 = *(&llvm_cbe_cppVar_809);
  if ((((((bool )llvm_cbe_tmp__1439&1u))&1))) {
    goto llvm_cbe_tmp__1515;
  } else {
    goto llvm_cbe_tmp__1516;
  }

llvm_cbe_tmp__1515:
  *(&llvm_cbe_cppVar_807) = 0ull;
  goto llvm_cbe_tmp__1517;

llvm_cbe_tmp__1516:
  llvm_cbe_tmp__1440 = *((&llvm_cbe_tmp__1389->field28));
  *(&llvm_cbe_cppVar_807) = llvm_cbe_tmp__1440;
  goto llvm_cbe_tmp__1517;

llvm_cbe_tmp__1517:
  llvm_cbe_tmp__1441 = *((&llvm_cbe_tmp__1389->field25));
  llvm_cbe_tmp__1442 = *((&llvm_cbe_tmp__1389->field43));
  *(&llvm_cbe_cppVar_812) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1441) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1442);
  llvm_cbe_tmp__1443 = *(&llvm_cbe_cppVar_812);
  llvm_cbe_tmp__1444 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__1389->field4)), llvm_cbe_tmp__1443);
  *(&llvm_cbe_cppVar_813) = llvm_cbe_tmp__1444;
  llvm_cbe_tmp__1445 = *(&llvm_cbe_cppVar_813);
  *(&llvm_cbe_cppVar_815) = (((unsigned char )(bool )(llvm_cbe_tmp__1445 == 1ull)));
  llvm_cbe_tmp__1446 = *(&llvm_cbe_cppVar_815);
  if ((((((bool )llvm_cbe_tmp__1446&1u))&1))) {
    goto llvm_cbe_tmp__1518;
  } else {
    goto llvm_cbe_tmp__1519;
  }

llvm_cbe_tmp__1518:
  llvm_cbe_tmp__1447 = *(&llvm_cbe_cppVar_792);
  llvm_cbe_tmp__1448 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1389->field3)), llvm_cbe_tmp__1447);
  *(&llvm_cbe_cppVar_816) = llvm_cbe_tmp__1448;
  llvm_cbe_tmp__1449 = *(&llvm_cbe_cppVar_816);
  llvm_cbe_tmp__1450 = *((&llvm_cbe_tmp__1389->field43));
  *(&llvm_cbe_cppVar_817) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1449) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1450);
  llvm_cbe_tmp__1451 = *(&llvm_cbe_cppVar_817);
  llvm_cbe_tmp__1452 = *((&llvm_cbe_tmp__1389->field47));
  llvm_cbe_tmp__1453 = *(&llvm_cbe_cppVar_817);
  if (((llvm_cbe_tmp__1451 & llvm_cbe_tmp__1452) != 0ull)) {
    goto llvm_cbe_tmp__1520;
  } else {
    llvm_cbe_tmp__1456__PHI_TEMPORARY = llvm_cbe_tmp__1453;   /* for PHI node */
    goto llvm_cbe_tmp__1521;
  }

llvm_cbe_tmp__1520:
  llvm_cbe_tmp__1454 = *((&llvm_cbe_tmp__1389->field49));
  llvm_cbe_tmp__1455 = llvm_cbe_tmp__1453 | llvm_cbe_tmp__1454;
  llvm_cbe_tmp__1456__PHI_TEMPORARY = llvm_cbe_tmp__1455;   /* for PHI node */
  goto llvm_cbe_tmp__1521;

llvm_cbe_tmp__1521:
  llvm_cbe_tmp__1456 = llvm_cbe_tmp__1456__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_818) = llvm_cbe_tmp__1456;
  llvm_cbe_tmp__1457 = *(&llvm_cbe_cppVar_816);
  llvm_cbe_tmp__1458 = *((&llvm_cbe_tmp__1389->field38));
  *(&llvm_cbe_cppVar_819) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1457) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1458);
  llvm_cbe_tmp__1459 = *(&llvm_cbe_cppVar_818);
  llvm_cbe_tmp__1460 = *(&llvm_cbe_cppVar_819);
  *(&llvm_cbe_cppVar_820) = ((llvm_cbe_tmp__1459 << 1ull) | llvm_cbe_tmp__1460);
  llvm_cbe_tmp__1461 = *(&llvm_cbe_cppVar_820);
  llvm_cbe_tmp__1462 = *((&llvm_cbe_tmp__1389->field39));
  *(&llvm_cbe_cppVar_820) = (llvm_cbe_tmp__1461 & llvm_cbe_tmp__1462);
  llvm_cbe_tmp__1463 = *(&llvm_cbe_cppVar_820);
  *(&llvm_cbe_cppVar_811) = llvm_cbe_tmp__1463;
  goto llvm_cbe_tmp__1522;

llvm_cbe_tmp__1519:
  *(&llvm_cbe_cppVar_811) = 0ull;
  goto llvm_cbe_tmp__1522;

llvm_cbe_tmp__1522:
  llvm_cbe_tmp__1464 = *(&llvm_cbe_cppVar_807);
  llvm_cbe_tmp__1465 = *(&llvm_cbe_cppVar_811);
  *(&llvm_cbe_cppVar_821) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1464) + ((unsigned long long )llvm_cbe_tmp__1465))));
  llvm_cbe_tmp__1466 = *(&llvm_cbe_cppVar_821);
  llvm_cbe_tmp__1467 = *((&llvm_cbe_tmp__1389->field39));
  *(&llvm_cbe_cppVar_821) = (llvm_cbe_tmp__1466 & llvm_cbe_tmp__1467);
  llvm_cbe_tmp__1468 = *(&llvm_cbe_cppVar_821);
  *(&llvm_cbe_cppVar_803) = llvm_cbe_tmp__1468;
  goto llvm_cbe_tmp__1523;

llvm_cbe_tmp__1514:
  llvm_cbe_tmp__1469 = *((&llvm_cbe_tmp__1389->field15));
  *(&llvm_cbe_cppVar_824) = (((unsigned char )(bool )(llvm_cbe_tmp__1469 == 1ull)));
  llvm_cbe_tmp__1470 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1470&1u))&1))) {
    goto llvm_cbe_tmp__1524;
  } else {
    llvm_cbe_tmp__1473__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1525;
  }

llvm_cbe_tmp__1524:
  llvm_cbe_tmp__1471 = *(&llvm_cbe_cppVar_824);
  llvm_cbe_tmp__1472 = ((((bool )llvm_cbe_tmp__1471&1u))&1);
  llvm_cbe_tmp__1473__PHI_TEMPORARY = llvm_cbe_tmp__1472;   /* for PHI node */
  goto llvm_cbe_tmp__1525;

llvm_cbe_tmp__1525:
  llvm_cbe_tmp__1473 = ((llvm_cbe_tmp__1473__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_825) = (((unsigned char )(bool )llvm_cbe_tmp__1473));
  llvm_cbe_tmp__1474 = *(&llvm_cbe_cppVar_825);
  if ((((((bool )llvm_cbe_tmp__1474&1u))&1))) {
    goto llvm_cbe_tmp__1526;
  } else {
    goto llvm_cbe_tmp__1527;
  }

llvm_cbe_tmp__1526:
  llvm_cbe_tmp__1475 = *((&llvm_cbe_tmp__1389->field28));
  *(&llvm_cbe_cppVar_822) = llvm_cbe_tmp__1475;
  goto llvm_cbe_tmp__1528;

llvm_cbe_tmp__1527:
  llvm_cbe_tmp__1476 = *((&llvm_cbe_tmp__1389->field15));
  *(&llvm_cbe_cppVar_828) = (((unsigned char )(bool )(llvm_cbe_tmp__1476 == 2ull)));
  llvm_cbe_tmp__1477 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1477&1u))&1))) {
    goto llvm_cbe_tmp__1529;
  } else {
    llvm_cbe_tmp__1480__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1530;
  }

llvm_cbe_tmp__1529:
  llvm_cbe_tmp__1478 = *(&llvm_cbe_cppVar_828);
  llvm_cbe_tmp__1479 = ((((bool )llvm_cbe_tmp__1478&1u))&1);
  llvm_cbe_tmp__1480__PHI_TEMPORARY = llvm_cbe_tmp__1479;   /* for PHI node */
  goto llvm_cbe_tmp__1530;

llvm_cbe_tmp__1530:
  llvm_cbe_tmp__1480 = ((llvm_cbe_tmp__1480__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_829) = (((unsigned char )(bool )llvm_cbe_tmp__1480));
  llvm_cbe_tmp__1481 = *(&llvm_cbe_cppVar_829);
  if ((((((bool )llvm_cbe_tmp__1481&1u))&1))) {
    goto llvm_cbe_tmp__1531;
  } else {
    goto llvm_cbe_tmp__1532;
  }

llvm_cbe_tmp__1531:
  llvm_cbe_tmp__1482 = *((&llvm_cbe_tmp__1389->field28));
  *(&llvm_cbe_cppVar_826) = llvm_cbe_tmp__1482;
  goto llvm_cbe_tmp__1533;

llvm_cbe_tmp__1532:
  llvm_cbe_tmp__1483 = *((&llvm_cbe_tmp__1389->field15));
  *(&llvm_cbe_cppVar_832) = (((unsigned char )(bool )(llvm_cbe_tmp__1483 == 3ull)));
  llvm_cbe_tmp__1484 = *(&llvm_cbe_cppVar_802);
  if ((((((bool )llvm_cbe_tmp__1484&1u))&1))) {
    goto llvm_cbe_tmp__1534;
  } else {
    llvm_cbe_tmp__1487__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1535;
  }

llvm_cbe_tmp__1534:
  llvm_cbe_tmp__1485 = *(&llvm_cbe_cppVar_832);
  llvm_cbe_tmp__1486 = ((((bool )llvm_cbe_tmp__1485&1u))&1);
  llvm_cbe_tmp__1487__PHI_TEMPORARY = llvm_cbe_tmp__1486;   /* for PHI node */
  goto llvm_cbe_tmp__1535;

llvm_cbe_tmp__1535:
  llvm_cbe_tmp__1487 = ((llvm_cbe_tmp__1487__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_833) = (((unsigned char )(bool )llvm_cbe_tmp__1487));
  llvm_cbe_tmp__1488 = *((&llvm_cbe_tmp__1389->field28));
  *(&llvm_cbe_cppVar_830) = llvm_cbe_tmp__1488;
  llvm_cbe_tmp__1489 = *(&llvm_cbe_cppVar_830);
  *(&llvm_cbe_cppVar_826) = llvm_cbe_tmp__1489;
  goto llvm_cbe_tmp__1533;

llvm_cbe_tmp__1533:
  llvm_cbe_tmp__1490 = *(&llvm_cbe_cppVar_826);
  *(&llvm_cbe_cppVar_822) = llvm_cbe_tmp__1490;
  goto llvm_cbe_tmp__1528;

llvm_cbe_tmp__1528:
  llvm_cbe_tmp__1491 = *(&llvm_cbe_cppVar_822);
  *(&llvm_cbe_cppVar_803) = llvm_cbe_tmp__1491;
  goto llvm_cbe_tmp__1523;

llvm_cbe_tmp__1523:
  llvm_cbe_tmp__1492 = *(&llvm_cbe_cppVar_803);
  *(&llvm_cbe_cppVar_800) = llvm_cbe_tmp__1492;
  goto llvm_cbe_tmp__1536;

llvm_cbe_tmp__1510:
  llvm_cbe_tmp__1493 = *((&llvm_cbe_tmp__1389->field29));
  *(&llvm_cbe_cppVar_836) = (((unsigned char )(bool )(llvm_cbe_tmp__1493 == 2ull)));
  llvm_cbe_tmp__1494 = *((&llvm_cbe_tmp__1389->field28));
  *(&llvm_cbe_cppVar_834) = llvm_cbe_tmp__1494;
  llvm_cbe_tmp__1495 = *(&llvm_cbe_cppVar_834);
  *(&llvm_cbe_cppVar_800) = llvm_cbe_tmp__1495;
  goto llvm_cbe_tmp__1536;

llvm_cbe_tmp__1536:
  llvm_cbe_tmp__1496 = *(&llvm_cbe_cppVar_800);
  *(&llvm_cbe_cppVar_778) = llvm_cbe_tmp__1496;
  goto llvm_cbe_tmp__1508;

llvm_cbe_tmp__1508:
  llvm_cbe_tmp__1497 = *(&llvm_cbe_cppVar_778);
  return llvm_cbe_tmp__1497;
}


unsigned long long _ZN11model_train22cppUpdateFun_train_upcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1537;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1538;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1539;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1540;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1541;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1542;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1543;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1544;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1545;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1546;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1547;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1548;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__1549;
  unsigned long long llvm_cbe_tmp__1550;
  unsigned char llvm_cbe_tmp__1551;
  unsigned long long llvm_cbe_tmp__1552;
  unsigned long long llvm_cbe_tmp__1553;
  unsigned long long llvm_cbe_tmp__1554;
  unsigned long long llvm_cbe_tmp__1555;
  unsigned long long llvm_cbe_tmp__1556;
  unsigned long long llvm_cbe_tmp__1557;
  unsigned long long llvm_cbe_tmp__1558;
  unsigned char llvm_cbe_tmp__1559;
  unsigned char llvm_cbe_tmp__1560;
  bool llvm_cbe_tmp__1561;
  bool llvm_cbe_tmp__1562;
  bool llvm_cbe_tmp__1562__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1563;
  unsigned long long llvm_cbe_tmp__1564;
  unsigned long long llvm_cbe_tmp__1565;
  unsigned char llvm_cbe_tmp__1566;
  unsigned long long llvm_cbe_tmp__1567;
  unsigned char llvm_cbe_tmp__1568;
  unsigned char llvm_cbe_tmp__1569;
  bool llvm_cbe_tmp__1570;
  bool llvm_cbe_tmp__1571;
  bool llvm_cbe_tmp__1571__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1572;
  unsigned char llvm_cbe_tmp__1573;
  unsigned char llvm_cbe_tmp__1574;
  bool llvm_cbe_tmp__1575;
  bool llvm_cbe_tmp__1576;
  bool llvm_cbe_tmp__1576__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1577;
  unsigned long long llvm_cbe_tmp__1578;
  unsigned long long llvm_cbe_tmp__1579;
  unsigned long long llvm_cbe_tmp__1580;
  unsigned long long llvm_cbe_tmp__1581;
  unsigned long long llvm_cbe_tmp__1582;
  unsigned long long llvm_cbe_tmp__1583;
  unsigned long long llvm_cbe_tmp__1584;
  unsigned long long llvm_cbe_tmp__1585;
  unsigned char llvm_cbe_tmp__1586;
  unsigned char llvm_cbe_tmp__1587;
  bool llvm_cbe_tmp__1588;
  bool llvm_cbe_tmp__1589;
  bool llvm_cbe_tmp__1589__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1590;
  unsigned char llvm_cbe_tmp__1591;
  bool llvm_cbe_tmp__1592;
  bool llvm_cbe_tmp__1593;
  bool llvm_cbe_tmp__1593__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1594;
  unsigned long long llvm_cbe_tmp__1595;
  unsigned long long llvm_cbe_tmp__1596;
  unsigned char llvm_cbe_tmp__1597;
  unsigned long long llvm_cbe_tmp__1598;
  unsigned long long llvm_cbe_tmp__1599;
  unsigned long long llvm_cbe_tmp__1600;
  unsigned long long llvm_cbe_tmp__1601;
  unsigned char llvm_cbe_tmp__1602;
  unsigned char llvm_cbe_tmp__1603;
  bool llvm_cbe_tmp__1604;
  bool llvm_cbe_tmp__1605;
  bool llvm_cbe_tmp__1605__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1606;
  unsigned long long llvm_cbe_tmp__1607;
  unsigned long long llvm_cbe_tmp__1608;
  unsigned char llvm_cbe_tmp__1609;
  unsigned long long llvm_cbe_tmp__1610;
  unsigned long long llvm_cbe_tmp__1611;
  unsigned long long llvm_cbe_tmp__1612;
  unsigned long long llvm_cbe_tmp__1613;
  unsigned char llvm_cbe_tmp__1614;
  unsigned char llvm_cbe_tmp__1615;
  bool llvm_cbe_tmp__1616;
  bool llvm_cbe_tmp__1617;
  bool llvm_cbe_tmp__1617__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1618;
  unsigned long long llvm_cbe_tmp__1619;
  unsigned long long llvm_cbe_tmp__1620;
  unsigned long long llvm_cbe_tmp__1621;
  unsigned long long llvm_cbe_tmp__1622;
  unsigned long long llvm_cbe_tmp__1623;

  *(&llvm_cbe_tmp__1537) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1538) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1539) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1540) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1541) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1542) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1543) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1544) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1545) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1546) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1547) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1548) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1549 = *(&llvm_cbe_tmp__1537);
  llvm_cbe_tmp__1550 = *((&llvm_cbe_tmp__1549->field29));
  *(&llvm_cbe_cppVar_840) = (((unsigned char )(bool )(llvm_cbe_tmp__1550 == 0ull)));
  llvm_cbe_tmp__1551 = *(&llvm_cbe_cppVar_840);
  if ((((((bool )llvm_cbe_tmp__1551&1u))&1))) {
    goto llvm_cbe_tmp__1624;
  } else {
    goto llvm_cbe_tmp__1625;
  }

llvm_cbe_tmp__1624:
  llvm_cbe_tmp__1552 = *((&llvm_cbe_tmp__1549->field30));
  llvm_cbe_tmp__1553 = *((&llvm_cbe_tmp__1549->field14));
  *(&llvm_cbe_cppVar_842) = (((unsigned char )(bool )(llvm_cbe_tmp__1552 == llvm_cbe_tmp__1553)));
  llvm_cbe_tmp__1554 = *((&llvm_cbe_tmp__1549->field9));
  *(&llvm_cbe_cppVar_844) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1554) - ((unsigned long long )1ull))));
  llvm_cbe_tmp__1555 = *(&llvm_cbe_cppVar_844);
  llvm_cbe_tmp__1556 = *((&llvm_cbe_tmp__1549->field39));
  *(&llvm_cbe_cppVar_844) = (llvm_cbe_tmp__1555 & llvm_cbe_tmp__1556);
  llvm_cbe_tmp__1557 = *((&llvm_cbe_tmp__1549->field25));
  llvm_cbe_tmp__1558 = *(&llvm_cbe_cppVar_844);
  *(&llvm_cbe_cppVar_845) = (((unsigned char )(bool )(llvm_cbe_tmp__1557 == llvm_cbe_tmp__1558)));
  llvm_cbe_tmp__1559 = *(&llvm_cbe_cppVar_842);
  if ((((((bool )llvm_cbe_tmp__1559&1u))&1))) {
    goto llvm_cbe_tmp__1626;
  } else {
    llvm_cbe_tmp__1562__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1627;
  }

llvm_cbe_tmp__1626:
  llvm_cbe_tmp__1560 = *(&llvm_cbe_cppVar_845);
  llvm_cbe_tmp__1561 = ((((bool )llvm_cbe_tmp__1560&1u))&1);
  llvm_cbe_tmp__1562__PHI_TEMPORARY = llvm_cbe_tmp__1561;   /* for PHI node */
  goto llvm_cbe_tmp__1627;

llvm_cbe_tmp__1627:
  llvm_cbe_tmp__1562 = ((llvm_cbe_tmp__1562__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_846) = (((unsigned char )(bool )llvm_cbe_tmp__1562));
  llvm_cbe_tmp__1563 = *(&llvm_cbe_cppVar_846);
  if ((((((bool )llvm_cbe_tmp__1563&1u))&1))) {
    goto llvm_cbe_tmp__1628;
  } else {
    goto llvm_cbe_tmp__1629;
  }

llvm_cbe_tmp__1628:
  *(&llvm_cbe_cppVar_841) = 1ull;
  goto llvm_cbe_tmp__1630;

llvm_cbe_tmp__1629:
  *(&llvm_cbe_cppVar_841) = 0ull;
  goto llvm_cbe_tmp__1630;

llvm_cbe_tmp__1630:
  llvm_cbe_tmp__1564 = *(&llvm_cbe_cppVar_841);
  *(&llvm_cbe_cppVar_838) = llvm_cbe_tmp__1564;
  goto llvm_cbe_tmp__1631;

llvm_cbe_tmp__1625:
  llvm_cbe_tmp__1565 = *((&llvm_cbe_tmp__1549->field29));
  *(&llvm_cbe_cppVar_851) = (((unsigned char )(bool )(llvm_cbe_tmp__1565 == 1ull)));
  llvm_cbe_tmp__1566 = *(&llvm_cbe_cppVar_851);
  if ((((((bool )llvm_cbe_tmp__1566&1u))&1))) {
    goto llvm_cbe_tmp__1632;
  } else {
    goto llvm_cbe_tmp__1633;
  }

llvm_cbe_tmp__1632:
  llvm_cbe_tmp__1567 = *((&llvm_cbe_tmp__1549->field15));
  *(&llvm_cbe_cppVar_854) = (((unsigned char )(bool )(llvm_cbe_tmp__1567 == 3ull)));
  llvm_cbe_tmp__1568 = *(&llvm_cbe_cppVar_851);
  if ((((((bool )llvm_cbe_tmp__1568&1u))&1))) {
    goto llvm_cbe_tmp__1634;
  } else {
    llvm_cbe_tmp__1571__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1635;
  }

llvm_cbe_tmp__1634:
  llvm_cbe_tmp__1569 = *(&llvm_cbe_cppVar_854);
  llvm_cbe_tmp__1570 = ((((bool )llvm_cbe_tmp__1569&1u))&1);
  llvm_cbe_tmp__1571__PHI_TEMPORARY = llvm_cbe_tmp__1570;   /* for PHI node */
  goto llvm_cbe_tmp__1635;

llvm_cbe_tmp__1635:
  llvm_cbe_tmp__1571 = ((llvm_cbe_tmp__1571__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_855) = (((unsigned char )(bool )llvm_cbe_tmp__1571));
  llvm_cbe_tmp__1572 = *((&llvm_cbe_tmp__1549->field7));
  *(&llvm_cbe_cppVar_857) = (((unsigned char )(bool )(llvm_cbe_tmp__1572 == 4ull)));
  llvm_cbe_tmp__1573 = *(&llvm_cbe_cppVar_855);
  if ((((((bool )llvm_cbe_tmp__1573&1u))&1))) {
    goto llvm_cbe_tmp__1636;
  } else {
    llvm_cbe_tmp__1576__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1637;
  }

llvm_cbe_tmp__1636:
  llvm_cbe_tmp__1574 = *(&llvm_cbe_cppVar_857);
  llvm_cbe_tmp__1575 = ((((bool )llvm_cbe_tmp__1574&1u))&1);
  llvm_cbe_tmp__1576__PHI_TEMPORARY = llvm_cbe_tmp__1575;   /* for PHI node */
  goto llvm_cbe_tmp__1637;

llvm_cbe_tmp__1637:
  llvm_cbe_tmp__1576 = ((llvm_cbe_tmp__1576__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_858) = (((unsigned char )(bool )llvm_cbe_tmp__1576));
  llvm_cbe_tmp__1577 = *((&llvm_cbe_tmp__1549->field30));
  *(&llvm_cbe_cppVar_860) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1577) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1578 = *(&llvm_cbe_cppVar_860);
  llvm_cbe_tmp__1579 = *((&llvm_cbe_tmp__1549->field39));
  *(&llvm_cbe_cppVar_860) = (llvm_cbe_tmp__1578 & llvm_cbe_tmp__1579);
  llvm_cbe_tmp__1580 = *(&llvm_cbe_cppVar_860);
  llvm_cbe_tmp__1581 = *((&llvm_cbe_tmp__1549->field14));
  *(&llvm_cbe_cppVar_861) = (((unsigned char )(bool )(llvm_cbe_tmp__1580 == llvm_cbe_tmp__1581)));
  llvm_cbe_tmp__1582 = *((&llvm_cbe_tmp__1549->field30));
  *(&llvm_cbe_cppVar_863) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1582) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1583 = *(&llvm_cbe_cppVar_863);
  llvm_cbe_tmp__1584 = *((&llvm_cbe_tmp__1549->field39));
  *(&llvm_cbe_cppVar_863) = (llvm_cbe_tmp__1583 & llvm_cbe_tmp__1584);
  llvm_cbe_tmp__1585 = *(&llvm_cbe_cppVar_863);
  *(&llvm_cbe_cppVar_865) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1585) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1586 = *(&llvm_cbe_cppVar_861);
  if ((((((bool )llvm_cbe_tmp__1586&1u))&1))) {
    llvm_cbe_tmp__1589__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1638;
  } else {
    goto llvm_cbe_tmp__1639;
  }

llvm_cbe_tmp__1639:
  llvm_cbe_tmp__1587 = *(&llvm_cbe_cppVar_865);
  llvm_cbe_tmp__1588 = ((((bool )llvm_cbe_tmp__1587&1u))&1);
  llvm_cbe_tmp__1589__PHI_TEMPORARY = llvm_cbe_tmp__1588;   /* for PHI node */
  goto llvm_cbe_tmp__1638;

llvm_cbe_tmp__1638:
  llvm_cbe_tmp__1589 = ((llvm_cbe_tmp__1589__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_866) = (((unsigned char )(bool )llvm_cbe_tmp__1589));
  llvm_cbe_tmp__1590 = *(&llvm_cbe_cppVar_858);
  if ((((((bool )llvm_cbe_tmp__1590&1u))&1))) {
    goto llvm_cbe_tmp__1640;
  } else {
    llvm_cbe_tmp__1593__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1641;
  }

llvm_cbe_tmp__1640:
  llvm_cbe_tmp__1591 = *(&llvm_cbe_cppVar_866);
  llvm_cbe_tmp__1592 = ((((bool )llvm_cbe_tmp__1591&1u))&1);
  llvm_cbe_tmp__1593__PHI_TEMPORARY = llvm_cbe_tmp__1592;   /* for PHI node */
  goto llvm_cbe_tmp__1641;

llvm_cbe_tmp__1641:
  llvm_cbe_tmp__1593 = ((llvm_cbe_tmp__1593__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_867) = (((unsigned char )(bool )llvm_cbe_tmp__1593));
  llvm_cbe_tmp__1594 = *(&llvm_cbe_cppVar_867);
  if ((((((bool )llvm_cbe_tmp__1594&1u))&1))) {
    goto llvm_cbe_tmp__1642;
  } else {
    goto llvm_cbe_tmp__1643;
  }

llvm_cbe_tmp__1642:
  *(&llvm_cbe_cppVar_852) = 3ull;
  goto llvm_cbe_tmp__1644;

llvm_cbe_tmp__1643:
  *(&llvm_cbe_cppVar_852) = 1ull;
  goto llvm_cbe_tmp__1644;

llvm_cbe_tmp__1644:
  llvm_cbe_tmp__1595 = *(&llvm_cbe_cppVar_852);
  *(&llvm_cbe_cppVar_849) = llvm_cbe_tmp__1595;
  goto llvm_cbe_tmp__1645;

llvm_cbe_tmp__1633:
  llvm_cbe_tmp__1596 = *((&llvm_cbe_tmp__1549->field29));
  *(&llvm_cbe_cppVar_871) = (((unsigned char )(bool )(llvm_cbe_tmp__1596 == 3ull)));
  llvm_cbe_tmp__1597 = *(&llvm_cbe_cppVar_871);
  if ((((((bool )llvm_cbe_tmp__1597&1u))&1))) {
    goto llvm_cbe_tmp__1646;
  } else {
    goto llvm_cbe_tmp__1647;
  }

llvm_cbe_tmp__1646:
  llvm_cbe_tmp__1598 = *((&llvm_cbe_tmp__1549->field25));
  llvm_cbe_tmp__1599 = *((&llvm_cbe_tmp__1549->field9));
  *(&llvm_cbe_cppVar_873) = (((unsigned char )(bool )(llvm_cbe_tmp__1598 == llvm_cbe_tmp__1599)));
  llvm_cbe_tmp__1600 = *((&llvm_cbe_tmp__1549->field30));
  llvm_cbe_tmp__1601 = *((&llvm_cbe_tmp__1549->field14));
  *(&llvm_cbe_cppVar_874) = (((unsigned char )(bool )(llvm_cbe_tmp__1600 == llvm_cbe_tmp__1601)));
  llvm_cbe_tmp__1602 = *(&llvm_cbe_cppVar_873);
  if ((((((bool )llvm_cbe_tmp__1602&1u))&1))) {
    goto llvm_cbe_tmp__1648;
  } else {
    llvm_cbe_tmp__1605__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1649;
  }

llvm_cbe_tmp__1648:
  llvm_cbe_tmp__1603 = *(&llvm_cbe_cppVar_874);
  llvm_cbe_tmp__1604 = ((((bool )llvm_cbe_tmp__1603&1u))&1);
  llvm_cbe_tmp__1605__PHI_TEMPORARY = llvm_cbe_tmp__1604;   /* for PHI node */
  goto llvm_cbe_tmp__1649;

llvm_cbe_tmp__1649:
  llvm_cbe_tmp__1605 = ((llvm_cbe_tmp__1605__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_875) = (((unsigned char )(bool )llvm_cbe_tmp__1605));
  llvm_cbe_tmp__1606 = *(&llvm_cbe_cppVar_875);
  if ((((((bool )llvm_cbe_tmp__1606&1u))&1))) {
    goto llvm_cbe_tmp__1650;
  } else {
    goto llvm_cbe_tmp__1651;
  }

llvm_cbe_tmp__1650:
  *(&llvm_cbe_cppVar_872) = 2ull;
  goto llvm_cbe_tmp__1652;

llvm_cbe_tmp__1651:
  *(&llvm_cbe_cppVar_872) = 3ull;
  goto llvm_cbe_tmp__1652;

llvm_cbe_tmp__1652:
  llvm_cbe_tmp__1607 = *(&llvm_cbe_cppVar_872);
  *(&llvm_cbe_cppVar_869) = llvm_cbe_tmp__1607;
  goto llvm_cbe_tmp__1653;

llvm_cbe_tmp__1647:
  llvm_cbe_tmp__1608 = *((&llvm_cbe_tmp__1549->field29));
  *(&llvm_cbe_cppVar_879) = (((unsigned char )(bool )(llvm_cbe_tmp__1608 == 2ull)));
  llvm_cbe_tmp__1609 = *(&llvm_cbe_cppVar_879);
  if ((((((bool )llvm_cbe_tmp__1609&1u))&1))) {
    goto llvm_cbe_tmp__1654;
  } else {
    goto llvm_cbe_tmp__1655;
  }

llvm_cbe_tmp__1654:
  llvm_cbe_tmp__1610 = *((&llvm_cbe_tmp__1549->field25));
  llvm_cbe_tmp__1611 = *((&llvm_cbe_tmp__1549->field9));
  *(&llvm_cbe_cppVar_881) = (((unsigned char )(bool )(llvm_cbe_tmp__1610 == llvm_cbe_tmp__1611)));
  llvm_cbe_tmp__1612 = *((&llvm_cbe_tmp__1549->field30));
  llvm_cbe_tmp__1613 = *((&llvm_cbe_tmp__1549->field14));
  *(&llvm_cbe_cppVar_882) = (((unsigned char )(bool )(llvm_cbe_tmp__1612 == llvm_cbe_tmp__1613)));
  llvm_cbe_tmp__1614 = *(&llvm_cbe_cppVar_881);
  if ((((((bool )llvm_cbe_tmp__1614&1u))&1))) {
    goto llvm_cbe_tmp__1656;
  } else {
    llvm_cbe_tmp__1617__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1657;
  }

llvm_cbe_tmp__1656:
  llvm_cbe_tmp__1615 = *(&llvm_cbe_cppVar_882);
  llvm_cbe_tmp__1616 = ((((bool )llvm_cbe_tmp__1615&1u))&1);
  llvm_cbe_tmp__1617__PHI_TEMPORARY = llvm_cbe_tmp__1616;   /* for PHI node */
  goto llvm_cbe_tmp__1657;

llvm_cbe_tmp__1657:
  llvm_cbe_tmp__1617 = ((llvm_cbe_tmp__1617__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_883) = (((unsigned char )(bool )llvm_cbe_tmp__1617));
  *(&llvm_cbe_cppVar_880) = 2ull;
  llvm_cbe_tmp__1618 = *(&llvm_cbe_cppVar_880);
  *(&llvm_cbe_cppVar_877) = llvm_cbe_tmp__1618;
  goto llvm_cbe_tmp__1658;

llvm_cbe_tmp__1655:
  llvm_cbe_tmp__1619 = *((&llvm_cbe_tmp__1549->field29));
  *(&llvm_cbe_cppVar_877) = llvm_cbe_tmp__1619;
  goto llvm_cbe_tmp__1658;

llvm_cbe_tmp__1658:
  llvm_cbe_tmp__1620 = *(&llvm_cbe_cppVar_877);
  *(&llvm_cbe_cppVar_869) = llvm_cbe_tmp__1620;
  goto llvm_cbe_tmp__1653;

llvm_cbe_tmp__1653:
  llvm_cbe_tmp__1621 = *(&llvm_cbe_cppVar_869);
  *(&llvm_cbe_cppVar_849) = llvm_cbe_tmp__1621;
  goto llvm_cbe_tmp__1645;

llvm_cbe_tmp__1645:
  llvm_cbe_tmp__1622 = *(&llvm_cbe_cppVar_849);
  *(&llvm_cbe_cppVar_838) = llvm_cbe_tmp__1622;
  goto llvm_cbe_tmp__1631;

llvm_cbe_tmp__1631:
  llvm_cbe_tmp__1623 = *(&llvm_cbe_cppVar_838);
  return llvm_cbe_tmp__1623;
}


unsigned long long _ZN11model_train24cppUpdateFun_train_v_cntElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1659;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1660;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1661;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1662;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1663;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1664;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1665;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1666;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1667;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1668;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1669;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1670;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__1671;
  unsigned long long llvm_cbe_tmp__1672;
  unsigned char llvm_cbe_tmp__1673;
  unsigned long long llvm_cbe_tmp__1674;
  unsigned long long llvm_cbe_tmp__1675;
  unsigned char llvm_cbe_tmp__1676;
  unsigned long long llvm_cbe_tmp__1677;
  unsigned long long llvm_cbe_tmp__1678;
  unsigned long long llvm_cbe_tmp__1679;
  unsigned long long llvm_cbe_tmp__1680;
  unsigned long long llvm_cbe_tmp__1681;
  unsigned long long llvm_cbe_tmp__1682;
  unsigned char llvm_cbe_tmp__1683;
  unsigned long long llvm_cbe_tmp__1684;
  unsigned char llvm_cbe_tmp__1685;
  unsigned char llvm_cbe_tmp__1686;
  bool llvm_cbe_tmp__1687;
  bool llvm_cbe_tmp__1688;
  bool llvm_cbe_tmp__1688__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1689;
  unsigned char llvm_cbe_tmp__1690;
  unsigned char llvm_cbe_tmp__1691;
  bool llvm_cbe_tmp__1692;
  bool llvm_cbe_tmp__1693;
  bool llvm_cbe_tmp__1693__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1694;
  unsigned long long llvm_cbe_tmp__1695;
  unsigned long long llvm_cbe_tmp__1696;
  unsigned long long llvm_cbe_tmp__1697;
  unsigned long long llvm_cbe_tmp__1698;
  unsigned long long llvm_cbe_tmp__1699;
  unsigned long long llvm_cbe_tmp__1700;
  unsigned long long llvm_cbe_tmp__1701;
  unsigned long long llvm_cbe_tmp__1702;
  unsigned long long llvm_cbe_tmp__1703;
  unsigned char llvm_cbe_tmp__1704;
  unsigned char llvm_cbe_tmp__1705;
  bool llvm_cbe_tmp__1706;
  bool llvm_cbe_tmp__1707;
  bool llvm_cbe_tmp__1707__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1708;
  unsigned long long llvm_cbe_tmp__1709;
  unsigned long long llvm_cbe_tmp__1710;
  unsigned long long llvm_cbe_tmp__1711;
  unsigned long long llvm_cbe_tmp__1712;
  unsigned long long llvm_cbe_tmp__1713;
  unsigned long long llvm_cbe_tmp__1714;
  unsigned long long llvm_cbe_tmp__1715;
  unsigned char llvm_cbe_tmp__1716;
  unsigned long long llvm_cbe_tmp__1717;
  unsigned long long llvm_cbe_tmp__1718;
  unsigned char llvm_cbe_tmp__1719;
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
  unsigned char llvm_cbe_tmp__1730;
  unsigned long long llvm_cbe_tmp__1731;
  unsigned long long llvm_cbe_tmp__1732;
  unsigned char llvm_cbe_tmp__1733;
  unsigned long long llvm_cbe_tmp__1734;
  unsigned long long llvm_cbe_tmp__1735;
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

  *(&llvm_cbe_tmp__1659) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1660) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1661) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1662) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1663) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1664) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1665) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1666) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1667) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1668) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1669) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1670) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1671 = *(&llvm_cbe_tmp__1659);
  llvm_cbe_tmp__1672 = *((&llvm_cbe_tmp__1671->field29));
  *(&llvm_cbe_cppVar_887) = (((unsigned char )(bool )(llvm_cbe_tmp__1672 == 0ull)));
  llvm_cbe_tmp__1673 = *(&llvm_cbe_cppVar_887);
  if ((((((bool )llvm_cbe_tmp__1673&1u))&1))) {
    goto llvm_cbe_tmp__1748;
  } else {
    goto llvm_cbe_tmp__1749;
  }

llvm_cbe_tmp__1748:
  llvm_cbe_tmp__1674 = *((&llvm_cbe_tmp__1671->field30));
  llvm_cbe_tmp__1675 = *((&llvm_cbe_tmp__1671->field14));
  *(&llvm_cbe_cppVar_889) = (((unsigned char )(bool )(llvm_cbe_tmp__1674 == llvm_cbe_tmp__1675)));
  llvm_cbe_tmp__1676 = *(&llvm_cbe_cppVar_889);
  if ((((((bool )llvm_cbe_tmp__1676&1u))&1))) {
    goto llvm_cbe_tmp__1750;
  } else {
    goto llvm_cbe_tmp__1751;
  }

llvm_cbe_tmp__1750:
  *(&llvm_cbe_cppVar_888) = 0ull;
  goto llvm_cbe_tmp__1752;

llvm_cbe_tmp__1751:
  llvm_cbe_tmp__1677 = *((&llvm_cbe_tmp__1671->field30));
  *(&llvm_cbe_cppVar_892) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1677) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1678 = *(&llvm_cbe_cppVar_892);
  llvm_cbe_tmp__1679 = *((&llvm_cbe_tmp__1671->field39));
  *(&llvm_cbe_cppVar_892) = (llvm_cbe_tmp__1678 & llvm_cbe_tmp__1679);
  llvm_cbe_tmp__1680 = *(&llvm_cbe_cppVar_892);
  *(&llvm_cbe_cppVar_888) = llvm_cbe_tmp__1680;
  goto llvm_cbe_tmp__1752;

llvm_cbe_tmp__1752:
  llvm_cbe_tmp__1681 = *(&llvm_cbe_cppVar_888);
  *(&llvm_cbe_cppVar_885) = llvm_cbe_tmp__1681;
  goto llvm_cbe_tmp__1753;

llvm_cbe_tmp__1749:
  llvm_cbe_tmp__1682 = *((&llvm_cbe_tmp__1671->field29));
  *(&llvm_cbe_cppVar_895) = (((unsigned char )(bool )(llvm_cbe_tmp__1682 == 1ull)));
  llvm_cbe_tmp__1683 = *(&llvm_cbe_cppVar_895);
  if ((((((bool )llvm_cbe_tmp__1683&1u))&1))) {
    goto llvm_cbe_tmp__1754;
  } else {
    goto llvm_cbe_tmp__1755;
  }

llvm_cbe_tmp__1754:
  llvm_cbe_tmp__1684 = *((&llvm_cbe_tmp__1671->field15));
  *(&llvm_cbe_cppVar_898) = (((unsigned char )(bool )(llvm_cbe_tmp__1684 == 3ull)));
  llvm_cbe_tmp__1685 = *(&llvm_cbe_cppVar_895);
  if ((((((bool )llvm_cbe_tmp__1685&1u))&1))) {
    goto llvm_cbe_tmp__1756;
  } else {
    llvm_cbe_tmp__1688__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1757;
  }

llvm_cbe_tmp__1756:
  llvm_cbe_tmp__1686 = *(&llvm_cbe_cppVar_898);
  llvm_cbe_tmp__1687 = ((((bool )llvm_cbe_tmp__1686&1u))&1);
  llvm_cbe_tmp__1688__PHI_TEMPORARY = llvm_cbe_tmp__1687;   /* for PHI node */
  goto llvm_cbe_tmp__1757;

llvm_cbe_tmp__1757:
  llvm_cbe_tmp__1688 = ((llvm_cbe_tmp__1688__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_899) = (((unsigned char )(bool )llvm_cbe_tmp__1688));
  llvm_cbe_tmp__1689 = *((&llvm_cbe_tmp__1671->field7));
  *(&llvm_cbe_cppVar_901) = (((unsigned char )(bool )(llvm_cbe_tmp__1689 == 4ull)));
  llvm_cbe_tmp__1690 = *(&llvm_cbe_cppVar_899);
  if ((((((bool )llvm_cbe_tmp__1690&1u))&1))) {
    goto llvm_cbe_tmp__1758;
  } else {
    llvm_cbe_tmp__1693__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1759;
  }

llvm_cbe_tmp__1758:
  llvm_cbe_tmp__1691 = *(&llvm_cbe_cppVar_901);
  llvm_cbe_tmp__1692 = ((((bool )llvm_cbe_tmp__1691&1u))&1);
  llvm_cbe_tmp__1693__PHI_TEMPORARY = llvm_cbe_tmp__1692;   /* for PHI node */
  goto llvm_cbe_tmp__1759;

llvm_cbe_tmp__1759:
  llvm_cbe_tmp__1693 = ((llvm_cbe_tmp__1693__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_902) = (((unsigned char )(bool )llvm_cbe_tmp__1693));
  llvm_cbe_tmp__1694 = *(&llvm_cbe_cppVar_902);
  llvm_cbe_tmp__1695 = *((&llvm_cbe_tmp__1671->field30));
  if ((((((bool )llvm_cbe_tmp__1694&1u))&1))) {
    goto llvm_cbe_tmp__1760;
  } else {
    goto llvm_cbe_tmp__1761;
  }

llvm_cbe_tmp__1760:
  *(&llvm_cbe_cppVar_905) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1695) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1696 = *(&llvm_cbe_cppVar_905);
  llvm_cbe_tmp__1697 = *((&llvm_cbe_tmp__1671->field39));
  *(&llvm_cbe_cppVar_905) = (llvm_cbe_tmp__1696 & llvm_cbe_tmp__1697);
  llvm_cbe_tmp__1698 = *(&llvm_cbe_cppVar_905);
  llvm_cbe_tmp__1699 = *((&llvm_cbe_tmp__1671->field14));
  *(&llvm_cbe_cppVar_906) = (((unsigned char )(bool )(llvm_cbe_tmp__1698 == llvm_cbe_tmp__1699)));
  llvm_cbe_tmp__1700 = *((&llvm_cbe_tmp__1671->field30));
  *(&llvm_cbe_cppVar_908) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1700) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1701 = *(&llvm_cbe_cppVar_908);
  llvm_cbe_tmp__1702 = *((&llvm_cbe_tmp__1671->field39));
  *(&llvm_cbe_cppVar_908) = (llvm_cbe_tmp__1701 & llvm_cbe_tmp__1702);
  llvm_cbe_tmp__1703 = *(&llvm_cbe_cppVar_908);
  *(&llvm_cbe_cppVar_910) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__1703) >= ((signed long long )500ull))));
  llvm_cbe_tmp__1704 = *(&llvm_cbe_cppVar_906);
  if ((((((bool )llvm_cbe_tmp__1704&1u))&1))) {
    llvm_cbe_tmp__1707__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__1762;
  } else {
    goto llvm_cbe_tmp__1763;
  }

llvm_cbe_tmp__1763:
  llvm_cbe_tmp__1705 = *(&llvm_cbe_cppVar_910);
  llvm_cbe_tmp__1706 = ((((bool )llvm_cbe_tmp__1705&1u))&1);
  llvm_cbe_tmp__1707__PHI_TEMPORARY = llvm_cbe_tmp__1706;   /* for PHI node */
  goto llvm_cbe_tmp__1762;

llvm_cbe_tmp__1762:
  llvm_cbe_tmp__1707 = ((llvm_cbe_tmp__1707__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_911) = (((unsigned char )(bool )llvm_cbe_tmp__1707));
  llvm_cbe_tmp__1708 = *(&llvm_cbe_cppVar_911);
  if ((((((bool )llvm_cbe_tmp__1708&1u))&1))) {
    goto llvm_cbe_tmp__1764;
  } else {
    goto llvm_cbe_tmp__1765;
  }

llvm_cbe_tmp__1764:
  *(&llvm_cbe_cppVar_903) = 0ull;
  goto llvm_cbe_tmp__1766;

llvm_cbe_tmp__1765:
  llvm_cbe_tmp__1709 = *((&llvm_cbe_tmp__1671->field30));
  *(&llvm_cbe_cppVar_913) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1709) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__1710 = *(&llvm_cbe_cppVar_913);
  llvm_cbe_tmp__1711 = *((&llvm_cbe_tmp__1671->field39));
  *(&llvm_cbe_cppVar_913) = (llvm_cbe_tmp__1710 & llvm_cbe_tmp__1711);
  llvm_cbe_tmp__1712 = *(&llvm_cbe_cppVar_913);
  *(&llvm_cbe_cppVar_903) = llvm_cbe_tmp__1712;
  goto llvm_cbe_tmp__1766;

llvm_cbe_tmp__1766:
  llvm_cbe_tmp__1713 = *(&llvm_cbe_cppVar_903);
  *(&llvm_cbe_cppVar_896) = llvm_cbe_tmp__1713;
  goto llvm_cbe_tmp__1767;

llvm_cbe_tmp__1761:
  *(&llvm_cbe_cppVar_896) = llvm_cbe_tmp__1695;
  goto llvm_cbe_tmp__1767;

llvm_cbe_tmp__1767:
  llvm_cbe_tmp__1714 = *(&llvm_cbe_cppVar_896);
  *(&llvm_cbe_cppVar_893) = llvm_cbe_tmp__1714;
  goto llvm_cbe_tmp__1768;

llvm_cbe_tmp__1755:
  llvm_cbe_tmp__1715 = *((&llvm_cbe_tmp__1671->field29));
  *(&llvm_cbe_cppVar_916) = (((unsigned char )(bool )(llvm_cbe_tmp__1715 == 3ull)));
  llvm_cbe_tmp__1716 = *(&llvm_cbe_cppVar_916);
  if ((((((bool )llvm_cbe_tmp__1716&1u))&1))) {
    goto llvm_cbe_tmp__1769;
  } else {
    goto llvm_cbe_tmp__1770;
  }

llvm_cbe_tmp__1769:
  llvm_cbe_tmp__1717 = *((&llvm_cbe_tmp__1671->field25));
  llvm_cbe_tmp__1718 = *((&llvm_cbe_tmp__1671->field9));
  *(&llvm_cbe_cppVar_918) = (((unsigned char )(bool )(llvm_cbe_tmp__1717 == llvm_cbe_tmp__1718)));
  llvm_cbe_tmp__1719 = *(&llvm_cbe_cppVar_918);
  llvm_cbe_tmp__1720 = *((&llvm_cbe_tmp__1671->field30));
  if ((((((bool )llvm_cbe_tmp__1719&1u))&1))) {
    goto llvm_cbe_tmp__1771;
  } else {
    goto llvm_cbe_tmp__1772;
  }

llvm_cbe_tmp__1771:
  llvm_cbe_tmp__1721 = *((&llvm_cbe_tmp__1671->field14));
  *(&llvm_cbe_cppVar_920) = (((unsigned char )(bool )(llvm_cbe_tmp__1720 == llvm_cbe_tmp__1721)));
  llvm_cbe_tmp__1722 = *(&llvm_cbe_cppVar_920);
  if ((((((bool )llvm_cbe_tmp__1722&1u))&1))) {
    goto llvm_cbe_tmp__1773;
  } else {
    goto llvm_cbe_tmp__1774;
  }

llvm_cbe_tmp__1773:
  *(&llvm_cbe_cppVar_919) = 0ull;
  goto llvm_cbe_tmp__1775;

llvm_cbe_tmp__1774:
  llvm_cbe_tmp__1723 = *((&llvm_cbe_tmp__1671->field30));
  *(&llvm_cbe_cppVar_922) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1723) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1724 = *(&llvm_cbe_cppVar_922);
  llvm_cbe_tmp__1725 = *((&llvm_cbe_tmp__1671->field39));
  *(&llvm_cbe_cppVar_922) = (llvm_cbe_tmp__1724 & llvm_cbe_tmp__1725);
  llvm_cbe_tmp__1726 = *(&llvm_cbe_cppVar_922);
  *(&llvm_cbe_cppVar_919) = llvm_cbe_tmp__1726;
  goto llvm_cbe_tmp__1775;

llvm_cbe_tmp__1775:
  llvm_cbe_tmp__1727 = *(&llvm_cbe_cppVar_919);
  *(&llvm_cbe_cppVar_917) = llvm_cbe_tmp__1727;
  goto llvm_cbe_tmp__1776;

llvm_cbe_tmp__1772:
  *(&llvm_cbe_cppVar_917) = llvm_cbe_tmp__1720;
  goto llvm_cbe_tmp__1776;

llvm_cbe_tmp__1776:
  llvm_cbe_tmp__1728 = *(&llvm_cbe_cppVar_917);
  *(&llvm_cbe_cppVar_914) = llvm_cbe_tmp__1728;
  goto llvm_cbe_tmp__1777;

llvm_cbe_tmp__1770:
  llvm_cbe_tmp__1729 = *((&llvm_cbe_tmp__1671->field29));
  *(&llvm_cbe_cppVar_925) = (((unsigned char )(bool )(llvm_cbe_tmp__1729 == 2ull)));
  llvm_cbe_tmp__1730 = *(&llvm_cbe_cppVar_925);
  if ((((((bool )llvm_cbe_tmp__1730&1u))&1))) {
    goto llvm_cbe_tmp__1778;
  } else {
    goto llvm_cbe_tmp__1779;
  }

llvm_cbe_tmp__1778:
  llvm_cbe_tmp__1731 = *((&llvm_cbe_tmp__1671->field25));
  llvm_cbe_tmp__1732 = *((&llvm_cbe_tmp__1671->field9));
  *(&llvm_cbe_cppVar_927) = (((unsigned char )(bool )(llvm_cbe_tmp__1731 == llvm_cbe_tmp__1732)));
  llvm_cbe_tmp__1733 = *(&llvm_cbe_cppVar_927);
  llvm_cbe_tmp__1734 = *((&llvm_cbe_tmp__1671->field30));
  if ((((((bool )llvm_cbe_tmp__1733&1u))&1))) {
    goto llvm_cbe_tmp__1780;
  } else {
    goto llvm_cbe_tmp__1781;
  }

llvm_cbe_tmp__1780:
  llvm_cbe_tmp__1735 = *((&llvm_cbe_tmp__1671->field14));
  *(&llvm_cbe_cppVar_929) = (((unsigned char )(bool )(llvm_cbe_tmp__1734 == llvm_cbe_tmp__1735)));
  llvm_cbe_tmp__1736 = *(&llvm_cbe_cppVar_929);
  llvm_cbe_tmp__1737 = *((&llvm_cbe_tmp__1671->field30));
  if ((((((bool )llvm_cbe_tmp__1736&1u))&1))) {
    goto llvm_cbe_tmp__1782;
  } else {
    goto llvm_cbe_tmp__1783;
  }

llvm_cbe_tmp__1782:
  *(&llvm_cbe_cppVar_928) = llvm_cbe_tmp__1737;
  goto llvm_cbe_tmp__1784;

llvm_cbe_tmp__1783:
  *(&llvm_cbe_cppVar_931) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1737) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__1738 = *(&llvm_cbe_cppVar_931);
  llvm_cbe_tmp__1739 = *((&llvm_cbe_tmp__1671->field39));
  *(&llvm_cbe_cppVar_931) = (llvm_cbe_tmp__1738 & llvm_cbe_tmp__1739);
  llvm_cbe_tmp__1740 = *(&llvm_cbe_cppVar_931);
  *(&llvm_cbe_cppVar_928) = llvm_cbe_tmp__1740;
  goto llvm_cbe_tmp__1784;

llvm_cbe_tmp__1784:
  llvm_cbe_tmp__1741 = *(&llvm_cbe_cppVar_928);
  *(&llvm_cbe_cppVar_926) = llvm_cbe_tmp__1741;
  goto llvm_cbe_tmp__1785;

llvm_cbe_tmp__1781:
  *(&llvm_cbe_cppVar_926) = llvm_cbe_tmp__1734;
  goto llvm_cbe_tmp__1785;

llvm_cbe_tmp__1785:
  llvm_cbe_tmp__1742 = *(&llvm_cbe_cppVar_926);
  *(&llvm_cbe_cppVar_923) = llvm_cbe_tmp__1742;
  goto llvm_cbe_tmp__1786;

llvm_cbe_tmp__1779:
  llvm_cbe_tmp__1743 = *((&llvm_cbe_tmp__1671->field30));
  *(&llvm_cbe_cppVar_923) = llvm_cbe_tmp__1743;
  goto llvm_cbe_tmp__1786;

llvm_cbe_tmp__1786:
  llvm_cbe_tmp__1744 = *(&llvm_cbe_cppVar_923);
  *(&llvm_cbe_cppVar_914) = llvm_cbe_tmp__1744;
  goto llvm_cbe_tmp__1777;

llvm_cbe_tmp__1777:
  llvm_cbe_tmp__1745 = *(&llvm_cbe_cppVar_914);
  *(&llvm_cbe_cppVar_893) = llvm_cbe_tmp__1745;
  goto llvm_cbe_tmp__1768;

llvm_cbe_tmp__1768:
  llvm_cbe_tmp__1746 = *(&llvm_cbe_cppVar_893);
  *(&llvm_cbe_cppVar_885) = llvm_cbe_tmp__1746;
  goto llvm_cbe_tmp__1753;

llvm_cbe_tmp__1753:
  llvm_cbe_tmp__1747 = *(&llvm_cbe_cppVar_885);
  return llvm_cbe_tmp__1747;
}


unsigned long long _ZN11model_train16cppUpdateFun_upcElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__1787;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1788;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1789;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1790;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1791;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1792;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1793;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1794;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1795;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1796;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1797;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1798;    /* Address-exposed local */
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
  struct l_class_OC_model_train *llvm_cbe_tmp__1799;
  unsigned long long llvm_cbe_tmp__1800;
  unsigned char llvm_cbe_tmp__1801;
  unsigned long long llvm_cbe_tmp__1802;
  unsigned long long llvm_cbe_tmp__1803;
  unsigned char llvm_cbe_tmp__1804;
  unsigned long long llvm_cbe_tmp__1805;
  unsigned long long llvm_cbe_tmp__1806;
  unsigned char llvm_cbe_tmp__1807;
  unsigned long long llvm_cbe_tmp__1808;
  unsigned long long llvm_cbe_tmp__1809;
  unsigned long long llvm_cbe_tmp__1810;
  unsigned long long llvm_cbe_tmp__1811;
  unsigned char llvm_cbe_tmp__1812;
  unsigned char llvm_cbe_tmp__1813;
  bool llvm_cbe_tmp__1814;
  bool llvm_cbe_tmp__1815;
  bool llvm_cbe_tmp__1815__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1816;
  unsigned long long llvm_cbe_tmp__1817;
  unsigned long long llvm_cbe_tmp__1818;
  unsigned long long llvm_cbe_tmp__1819;
  unsigned long long llvm_cbe_tmp__1820;
  unsigned long long llvm_cbe_tmp__1821;
  unsigned long long llvm_cbe_tmp__1822;

  *(&llvm_cbe_tmp__1787) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1788) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1789) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1790) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1791) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1792) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1793) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1794) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1795) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1796) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1797) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1798) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1799 = *(&llvm_cbe_tmp__1787);
  llvm_cbe_tmp__1800 = *((&llvm_cbe_tmp__1799->field29));
  *(&llvm_cbe_cppVar_935) = (((unsigned char )(bool )(llvm_cbe_tmp__1800 == 0ull)));
  llvm_cbe_tmp__1801 = *(&llvm_cbe_cppVar_935);
  if ((((((bool )llvm_cbe_tmp__1801&1u))&1))) {
    goto llvm_cbe_tmp__1823;
  } else {
    goto llvm_cbe_tmp__1824;
  }

llvm_cbe_tmp__1823:
  llvm_cbe_tmp__1802 = *((&llvm_cbe_tmp__1799->field31));
  *(&llvm_cbe_cppVar_933) = llvm_cbe_tmp__1802;
  goto llvm_cbe_tmp__1825;

llvm_cbe_tmp__1824:
  llvm_cbe_tmp__1803 = *((&llvm_cbe_tmp__1799->field29));
  *(&llvm_cbe_cppVar_938) = (((unsigned char )(bool )(llvm_cbe_tmp__1803 == 1ull)));
  llvm_cbe_tmp__1804 = *(&llvm_cbe_cppVar_938);
  if ((((((bool )llvm_cbe_tmp__1804&1u))&1))) {
    goto llvm_cbe_tmp__1826;
  } else {
    goto llvm_cbe_tmp__1827;
  }

llvm_cbe_tmp__1826:
  llvm_cbe_tmp__1805 = *((&llvm_cbe_tmp__1799->field31));
  *(&llvm_cbe_cppVar_936) = llvm_cbe_tmp__1805;
  goto llvm_cbe_tmp__1828;

llvm_cbe_tmp__1827:
  llvm_cbe_tmp__1806 = *((&llvm_cbe_tmp__1799->field29));
  *(&llvm_cbe_cppVar_941) = (((unsigned char )(bool )(llvm_cbe_tmp__1806 == 2ull)));
  llvm_cbe_tmp__1807 = *(&llvm_cbe_cppVar_941);
  if ((((((bool )llvm_cbe_tmp__1807&1u))&1))) {
    goto llvm_cbe_tmp__1829;
  } else {
    goto llvm_cbe_tmp__1830;
  }

llvm_cbe_tmp__1829:
  llvm_cbe_tmp__1808 = *((&llvm_cbe_tmp__1799->field25));
  llvm_cbe_tmp__1809 = *((&llvm_cbe_tmp__1799->field9));
  *(&llvm_cbe_cppVar_943) = (((unsigned char )(bool )(llvm_cbe_tmp__1808 == llvm_cbe_tmp__1809)));
  llvm_cbe_tmp__1810 = *((&llvm_cbe_tmp__1799->field30));
  llvm_cbe_tmp__1811 = *((&llvm_cbe_tmp__1799->field14));
  *(&llvm_cbe_cppVar_944) = (((unsigned char )(bool )(llvm_cbe_tmp__1810 == llvm_cbe_tmp__1811)));
  llvm_cbe_tmp__1812 = *(&llvm_cbe_cppVar_943);
  if ((((((bool )llvm_cbe_tmp__1812&1u))&1))) {
    goto llvm_cbe_tmp__1831;
  } else {
    llvm_cbe_tmp__1815__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1832;
  }

llvm_cbe_tmp__1831:
  llvm_cbe_tmp__1813 = *(&llvm_cbe_cppVar_944);
  llvm_cbe_tmp__1814 = ((((bool )llvm_cbe_tmp__1813&1u))&1);
  llvm_cbe_tmp__1815__PHI_TEMPORARY = llvm_cbe_tmp__1814;   /* for PHI node */
  goto llvm_cbe_tmp__1832;

llvm_cbe_tmp__1832:
  llvm_cbe_tmp__1815 = ((llvm_cbe_tmp__1815__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_945) = (((unsigned char )(bool )llvm_cbe_tmp__1815));
  llvm_cbe_tmp__1816 = *(&llvm_cbe_cppVar_945);
  if ((((((bool )llvm_cbe_tmp__1816&1u))&1))) {
    goto llvm_cbe_tmp__1833;
  } else {
    goto llvm_cbe_tmp__1834;
  }

llvm_cbe_tmp__1833:
  *(&llvm_cbe_cppVar_942) = 0ull;
  goto llvm_cbe_tmp__1835;

llvm_cbe_tmp__1834:
  llvm_cbe_tmp__1817 = *((&llvm_cbe_tmp__1799->field31));
  *(&llvm_cbe_cppVar_942) = llvm_cbe_tmp__1817;
  goto llvm_cbe_tmp__1835;

llvm_cbe_tmp__1835:
  llvm_cbe_tmp__1818 = *(&llvm_cbe_cppVar_942);
  *(&llvm_cbe_cppVar_939) = llvm_cbe_tmp__1818;
  goto llvm_cbe_tmp__1836;

llvm_cbe_tmp__1830:
  llvm_cbe_tmp__1819 = *((&llvm_cbe_tmp__1799->field31));
  *(&llvm_cbe_cppVar_939) = llvm_cbe_tmp__1819;
  goto llvm_cbe_tmp__1836;

llvm_cbe_tmp__1836:
  llvm_cbe_tmp__1820 = *(&llvm_cbe_cppVar_939);
  *(&llvm_cbe_cppVar_936) = llvm_cbe_tmp__1820;
  goto llvm_cbe_tmp__1828;

llvm_cbe_tmp__1828:
  llvm_cbe_tmp__1821 = *(&llvm_cbe_cppVar_936);
  *(&llvm_cbe_cppVar_933) = llvm_cbe_tmp__1821;
  goto llvm_cbe_tmp__1825;

llvm_cbe_tmp__1825:
  llvm_cbe_tmp__1822 = *(&llvm_cbe_cppVar_933);
  return llvm_cbe_tmp__1822;
}


struct l_unnamed2 _ZN11model_train28cppUpdateFun_visibleEnergiesElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_unnamed2 StructReturn;  /* Struct return temporary */
  struct l_unnamed2 *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__1837;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1838;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1839;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1840;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1841;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1842;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1843;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1844;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1845;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1846;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1847;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1848;    /* Address-exposed local */
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
  unsigned char *llvm_cbe_tmp__1849;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1850;    /* Address-exposed local */
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
  bool llvm_cbe_tmp__1851;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1103;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1852;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__1853;
  unsigned long long llvm_cbe_tmp__1854;
  unsigned char llvm_cbe_tmp__1855;
  struct l_unnamed2 *llvm_cbe_tmp__1856;
  unsigned long long llvm_cbe_tmp__1857;
  unsigned char llvm_cbe_tmp__1858;
  unsigned long long llvm_cbe_tmp__1859;
  unsigned char llvm_cbe_tmp__1860;
  unsigned char llvm_cbe_tmp__1861;
  bool llvm_cbe_tmp__1862;
  bool llvm_cbe_tmp__1863;
  bool llvm_cbe_tmp__1863__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1864;
  unsigned long long llvm_cbe_tmp__1865;
  unsigned long long llvm_cbe_tmp__1866;
  unsigned char llvm_cbe_tmp__1867;
  unsigned long long llvm_cbe_tmp__1868;
  unsigned long long llvm_cbe_tmp__1869;
  unsigned long long llvm_cbe_tmp__1870;
  unsigned char llvm_cbe_tmp__1871;
  unsigned long long llvm_cbe_tmp__1872;
  unsigned long long llvm_cbe_tmp__1873;
  unsigned long long llvm_cbe_tmp__1874;
  unsigned long long llvm_cbe_tmp__1875;
  unsigned long long llvm_cbe_tmp__1876;
  unsigned long long llvm_cbe_tmp__1877;
  unsigned char llvm_cbe_tmp__1878;
  unsigned long long llvm_cbe_tmp__1879;
  unsigned long long llvm_cbe_tmp__1880;
  unsigned long long llvm_cbe_tmp__1881;
  unsigned long long llvm_cbe_tmp__1882;
  unsigned long long llvm_cbe_tmp__1883;
  unsigned long long llvm_cbe_tmp__1884;
  unsigned long long llvm_cbe_tmp__1885;
  unsigned long long llvm_cbe_tmp__1886;
  unsigned long long llvm_cbe_tmp__1887;
  unsigned long long llvm_cbe_tmp__1888;
  unsigned long long llvm_cbe_tmp__1889;
  unsigned long long llvm_cbe_tmp__1890;
  unsigned long long llvm_cbe_tmp__1891;
  unsigned long long llvm_cbe_tmp__1892;
  unsigned long long llvm_cbe_tmp__1893;
  unsigned long long llvm_cbe_tmp__1894;
  unsigned long long llvm_cbe_tmp__1895;
  unsigned long long llvm_cbe_tmp__1895__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__1896;
  unsigned long long llvm_cbe_tmp__1897;
  unsigned long long llvm_cbe_tmp__1898;
  unsigned long long llvm_cbe_tmp__1899;
  unsigned long long llvm_cbe_tmp__1900;
  unsigned long long llvm_cbe_tmp__1901;
  unsigned long long llvm_cbe_tmp__1902;
  unsigned long long llvm_cbe_tmp__1903;
  unsigned long long llvm_cbe_tmp__1904;
  unsigned long long llvm_cbe_tmp__1905;
  unsigned long long llvm_cbe_tmp__1906;
  struct l_unnamed2 *llvm_cbe_tmp__1907;
  unsigned long long llvm_cbe_tmp__1908;
  unsigned long long llvm_cbe_tmp__1909;
  struct l_unnamed2 *llvm_cbe_tmp__1910;
  struct l_unnamed2 *llvm_cbe_tmp__1911;
  struct l_unnamed2 *llvm_cbe_tmp__1912;
  unsigned long long llvm_cbe_tmp__1913;
  unsigned char llvm_cbe_tmp__1914;
  unsigned char llvm_cbe_tmp__1915;
  bool llvm_cbe_tmp__1916;
  bool llvm_cbe_tmp__1917;
  bool llvm_cbe_tmp__1917__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1918;
  unsigned long long llvm_cbe_tmp__1919;
  unsigned long long llvm_cbe_tmp__1920;
  unsigned long long llvm_cbe_tmp__1921;
  unsigned long long llvm_cbe_tmp__1922;
  unsigned long long llvm_cbe_tmp__1923;
  unsigned long long llvm_cbe_tmp__1924;
  unsigned long long llvm_cbe_tmp__1925;
  unsigned char llvm_cbe_tmp__1926;
  unsigned long long llvm_cbe_tmp__1927;
  unsigned long long llvm_cbe_tmp__1928;
  unsigned long long llvm_cbe_tmp__1929;
  unsigned long long llvm_cbe_tmp__1930;
  unsigned long long llvm_cbe_tmp__1931;
  unsigned long long llvm_cbe_tmp__1932;
  unsigned long long llvm_cbe_tmp__1933;
  unsigned long long llvm_cbe_tmp__1934;
  struct l_unnamed2 *llvm_cbe_tmp__1935;
  unsigned long long llvm_cbe_tmp__1936;
  unsigned long long llvm_cbe_tmp__1937;
  struct l_unnamed2 *llvm_cbe_tmp__1938;
  unsigned long long llvm_cbe_tmp__1939;
  unsigned char llvm_cbe_tmp__1940;
  unsigned char llvm_cbe_tmp__1941;
  bool llvm_cbe_tmp__1942;
  bool llvm_cbe_tmp__1943;
  bool llvm_cbe_tmp__1943__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1944;
  struct l_unnamed2 *llvm_cbe_tmp__1945;
  unsigned long long llvm_cbe_tmp__1946;
  unsigned char llvm_cbe_tmp__1947;
  unsigned char llvm_cbe_tmp__1948;
  bool llvm_cbe_tmp__1949;
  bool llvm_cbe_tmp__1950;
  bool llvm_cbe_tmp__1950__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__1951;
  bool llvm_cbe_tmp__1952;
  struct l_unnamed2 *llvm_cbe_tmp__1953;
  struct l_unnamed2 *llvm_cbe_tmp__1954;
  struct l_unnamed2 *llvm_cbe_tmp__1955;
  struct l_unnamed2 *llvm_cbe_tmp__1956;
  struct l_unnamed2 *llvm_cbe_tmp__1957;
  unsigned long long llvm_cbe_tmp__1958;
  unsigned char llvm_cbe_tmp__1959;
  bool llvm_cbe_tmp__1960;
  struct l_unnamed2 *llvm_cbe_tmp__1961;
  struct l_unnamed2 *llvm_cbe_tmp__1962;
  struct l_unnamed2 *llvm_cbe_tmp__1963;
  bool llvm_cbe_tmp__1964;

  *(&llvm_cbe_tmp__1837) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1838) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__1839) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__1840) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__1841) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__1842) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__1843) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__1844) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__1845) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__1846) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__1847) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__1848) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__1853 = *(&llvm_cbe_tmp__1837);
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1118));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1097));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1132));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1137));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1133));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1119));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1093));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1141));
  _ZN8type_memItLj8EEC1Ev((&llvm_cbe_cppVar_1090));
  *(&llvm_cbe_tmp__1851) = ((0) & 1);
  _ZN8type_memItLj8EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__1854 = *((&llvm_cbe_tmp__1853->field29));
  *(&llvm_cbe_cppVar_1089) = (((unsigned char )(bool )(llvm_cbe_tmp__1854 == 0ull)));
  llvm_cbe_tmp__1855 = *(&llvm_cbe_cppVar_1089);
  if ((((((bool )llvm_cbe_tmp__1855&1u))&1))) {
    goto llvm_cbe_tmp__1965;
  } else {
    goto llvm_cbe_tmp__1966;
  }

llvm_cbe_tmp__1965:
  llvm_cbe_tmp__1856 = _ZN8type_memItLj8EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__1853->field32)));
  goto llvm_cbe_tmp__1967;

llvm_cbe_tmp__1966:
  llvm_cbe_tmp__1857 = *((&llvm_cbe_tmp__1853->field29));
  *(&llvm_cbe_cppVar_1092) = (((unsigned char )(bool )(llvm_cbe_tmp__1857 == 1ull)));
  llvm_cbe_tmp__1858 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1858&1u))&1))) {
    goto llvm_cbe_tmp__1968;
  } else {
    goto llvm_cbe_tmp__1969;
  }

llvm_cbe_tmp__1968:
  llvm_cbe_tmp__1859 = *((&llvm_cbe_tmp__1853->field15));
  *(&llvm_cbe_cppVar_1095) = (((unsigned char )(bool )(llvm_cbe_tmp__1859 == 0ull)));
  llvm_cbe_tmp__1860 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1860&1u))&1))) {
    goto llvm_cbe_tmp__1970;
  } else {
    llvm_cbe_tmp__1863__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1971;
  }

llvm_cbe_tmp__1970:
  llvm_cbe_tmp__1861 = *(&llvm_cbe_cppVar_1095);
  llvm_cbe_tmp__1862 = ((((bool )llvm_cbe_tmp__1861&1u))&1);
  llvm_cbe_tmp__1863__PHI_TEMPORARY = llvm_cbe_tmp__1862;   /* for PHI node */
  goto llvm_cbe_tmp__1971;

llvm_cbe_tmp__1971:
  llvm_cbe_tmp__1863 = ((llvm_cbe_tmp__1863__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1096) = (((unsigned char )(bool )llvm_cbe_tmp__1863));
  llvm_cbe_tmp__1864 = *(&llvm_cbe_cppVar_1096);
  if ((((((bool )llvm_cbe_tmp__1864&1u))&1))) {
    goto llvm_cbe_tmp__1972;
  } else {
    goto llvm_cbe_tmp__1973;
  }

llvm_cbe_tmp__1972:
  llvm_cbe_tmp__1865 = *((&llvm_cbe_tmp__1853->field25));
  llvm_cbe_tmp__1866 = *((&llvm_cbe_tmp__1853->field9));
  *(&llvm_cbe_cppVar_1098) = (((unsigned char )(bool )(llvm_cbe_tmp__1865 == llvm_cbe_tmp__1866)));
  llvm_cbe_tmp__1867 = *(&llvm_cbe_cppVar_1098);
  if ((((((bool )llvm_cbe_tmp__1867&1u))&1))) {
    goto llvm_cbe_tmp__1974;
  } else {
    goto llvm_cbe_tmp__1975;
  }

llvm_cbe_tmp__1974:
  llvm_cbe_tmp__1868 = *((&llvm_cbe_tmp__1853->field7));
  llvm_cbe_tmp__1869 = *((&llvm_cbe_tmp__1853->field40));
  *(&llvm_cbe_cppVar_1099) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1868) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1869);
  llvm_cbe_tmp__1870 = *((&llvm_cbe_tmp__1853->field25));
  *(&llvm_cbe_cppVar_1102) = (((unsigned char )(bool )(llvm_cbe_tmp__1870 == 0ull)));
  llvm_cbe_tmp__1871 = *(&llvm_cbe_cppVar_1102);
  if ((((((bool )llvm_cbe_tmp__1871&1u))&1))) {
    goto llvm_cbe_tmp__1976;
  } else {
    goto llvm_cbe_tmp__1977;
  }

llvm_cbe_tmp__1976:
  *(&llvm_cbe_cppVar_1100) = 0ull;
  goto llvm_cbe_tmp__1978;

llvm_cbe_tmp__1977:
  llvm_cbe_tmp__1872 = *((&llvm_cbe_tmp__1853->field28));
  *(&llvm_cbe_cppVar_1100) = llvm_cbe_tmp__1872;
  goto llvm_cbe_tmp__1978;

llvm_cbe_tmp__1978:
  llvm_cbe_tmp__1873 = *((&llvm_cbe_tmp__1853->field25));
  llvm_cbe_tmp__1874 = *((&llvm_cbe_tmp__1853->field43));
  *(&llvm_cbe_cppVar_1105) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1873) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1874);
  llvm_cbe_tmp__1875 = *(&llvm_cbe_cppVar_1105);
  llvm_cbe_tmp__1876 = _ZN8type_memIbLj128EE2rdEl(((&llvm_cbe_tmp__1853->field4)), llvm_cbe_tmp__1875);
  *(&llvm_cbe_cppVar_1106) = llvm_cbe_tmp__1876;
  llvm_cbe_tmp__1877 = *(&llvm_cbe_cppVar_1106);
  *(&llvm_cbe_cppVar_1108) = (((unsigned char )(bool )(llvm_cbe_tmp__1877 == 1ull)));
  llvm_cbe_tmp__1878 = *(&llvm_cbe_cppVar_1108);
  if ((((((bool )llvm_cbe_tmp__1878&1u))&1))) {
    goto llvm_cbe_tmp__1979;
  } else {
    goto llvm_cbe_tmp__1980;
  }

llvm_cbe_tmp__1979:
  llvm_cbe_tmp__1879 = *((&llvm_cbe_tmp__1853->field30));
  *(&llvm_cbe_cppVar_1110) = (((unsigned long long )(((unsigned long long )101ull) * ((unsigned long long )llvm_cbe_tmp__1879))));
  llvm_cbe_tmp__1880 = *(&llvm_cbe_cppVar_1110);
  llvm_cbe_tmp__1881 = *((&llvm_cbe_tmp__1853->field39));
  *(&llvm_cbe_cppVar_1110) = (llvm_cbe_tmp__1880 & llvm_cbe_tmp__1881);
  llvm_cbe_tmp__1882 = *(&llvm_cbe_cppVar_1110);
  llvm_cbe_tmp__1883 = *((&llvm_cbe_tmp__1853->field25));
  *(&llvm_cbe_cppVar_1111) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1882) + ((unsigned long long )llvm_cbe_tmp__1883))));
  llvm_cbe_tmp__1884 = *(&llvm_cbe_cppVar_1111);
  llvm_cbe_tmp__1885 = *((&llvm_cbe_tmp__1853->field39));
  *(&llvm_cbe_cppVar_1111) = (llvm_cbe_tmp__1884 & llvm_cbe_tmp__1885);
  llvm_cbe_tmp__1886 = *(&llvm_cbe_cppVar_1111);
  llvm_cbe_tmp__1887 = _ZN8type_memIhLj65536EE2rdEl(((&llvm_cbe_tmp__1853->field3)), llvm_cbe_tmp__1886);
  *(&llvm_cbe_cppVar_1112) = llvm_cbe_tmp__1887;
  llvm_cbe_tmp__1888 = *(&llvm_cbe_cppVar_1112);
  llvm_cbe_tmp__1889 = *((&llvm_cbe_tmp__1853->field43));
  *(&llvm_cbe_cppVar_1113) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1888) >> ((signed long long )1ull)))) & llvm_cbe_tmp__1889);
  llvm_cbe_tmp__1890 = *(&llvm_cbe_cppVar_1113);
  llvm_cbe_tmp__1891 = *((&llvm_cbe_tmp__1853->field47));
  llvm_cbe_tmp__1892 = *(&llvm_cbe_cppVar_1113);
  if (((llvm_cbe_tmp__1890 & llvm_cbe_tmp__1891) != 0ull)) {
    goto llvm_cbe_tmp__1981;
  } else {
    llvm_cbe_tmp__1895__PHI_TEMPORARY = llvm_cbe_tmp__1892;   /* for PHI node */
    goto llvm_cbe_tmp__1982;
  }

llvm_cbe_tmp__1981:
  llvm_cbe_tmp__1893 = *((&llvm_cbe_tmp__1853->field49));
  llvm_cbe_tmp__1894 = llvm_cbe_tmp__1892 | llvm_cbe_tmp__1893;
  llvm_cbe_tmp__1895__PHI_TEMPORARY = llvm_cbe_tmp__1894;   /* for PHI node */
  goto llvm_cbe_tmp__1982;

llvm_cbe_tmp__1982:
  llvm_cbe_tmp__1895 = llvm_cbe_tmp__1895__PHI_TEMPORARY;
  *(&llvm_cbe_cppVar_1114) = llvm_cbe_tmp__1895;
  llvm_cbe_tmp__1896 = *(&llvm_cbe_cppVar_1112);
  llvm_cbe_tmp__1897 = *((&llvm_cbe_tmp__1853->field38));
  *(&llvm_cbe_cppVar_1115) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1896) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1897);
  llvm_cbe_tmp__1898 = *(&llvm_cbe_cppVar_1114);
  llvm_cbe_tmp__1899 = *(&llvm_cbe_cppVar_1115);
  *(&llvm_cbe_cppVar_1116) = ((llvm_cbe_tmp__1898 << 1ull) | llvm_cbe_tmp__1899);
  llvm_cbe_tmp__1900 = *(&llvm_cbe_cppVar_1116);
  llvm_cbe_tmp__1901 = *((&llvm_cbe_tmp__1853->field39));
  *(&llvm_cbe_cppVar_1116) = (llvm_cbe_tmp__1900 & llvm_cbe_tmp__1901);
  llvm_cbe_tmp__1902 = *(&llvm_cbe_cppVar_1116);
  *(&llvm_cbe_cppVar_1104) = llvm_cbe_tmp__1902;
  goto llvm_cbe_tmp__1983;

llvm_cbe_tmp__1980:
  *(&llvm_cbe_cppVar_1104) = 0ull;
  goto llvm_cbe_tmp__1983;

llvm_cbe_tmp__1983:
  llvm_cbe_tmp__1903 = *(&llvm_cbe_cppVar_1100);
  llvm_cbe_tmp__1904 = *(&llvm_cbe_cppVar_1104);
  *(&llvm_cbe_cppVar_1117) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1903) + ((unsigned long long )llvm_cbe_tmp__1904))));
  llvm_cbe_tmp__1905 = *(&llvm_cbe_cppVar_1117);
  llvm_cbe_tmp__1906 = *((&llvm_cbe_tmp__1853->field39));
  *(&llvm_cbe_cppVar_1117) = (llvm_cbe_tmp__1905 & llvm_cbe_tmp__1906);
  llvm_cbe_tmp__1907 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1118), ((&llvm_cbe_tmp__1853->field32)));
  llvm_cbe_tmp__1908 = *(&llvm_cbe_cppVar_1099);
  llvm_cbe_tmp__1909 = *(&llvm_cbe_cppVar_1117);
  _ZN8type_memItLj8EE2wrEll((&llvm_cbe_cppVar_1118), llvm_cbe_tmp__1908, llvm_cbe_tmp__1909);
  llvm_cbe_tmp__1910 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1097), (&llvm_cbe_cppVar_1118));
  goto llvm_cbe_tmp__1984;

llvm_cbe_tmp__1975:
  llvm_cbe_tmp__1911 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1097), ((&llvm_cbe_tmp__1853->field32)));
  goto llvm_cbe_tmp__1984;

llvm_cbe_tmp__1984:
  llvm_cbe_tmp__1912 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1093), (&llvm_cbe_cppVar_1097));
  goto llvm_cbe_tmp__1985;

llvm_cbe_tmp__1973:
  llvm_cbe_tmp__1913 = *((&llvm_cbe_tmp__1853->field15));
  *(&llvm_cbe_cppVar_1121) = (((unsigned char )(bool )(llvm_cbe_tmp__1913 == 1ull)));
  llvm_cbe_tmp__1914 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1914&1u))&1))) {
    goto llvm_cbe_tmp__1986;
  } else {
    llvm_cbe_tmp__1917__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1987;
  }

llvm_cbe_tmp__1986:
  llvm_cbe_tmp__1915 = *(&llvm_cbe_cppVar_1121);
  llvm_cbe_tmp__1916 = ((((bool )llvm_cbe_tmp__1915&1u))&1);
  llvm_cbe_tmp__1917__PHI_TEMPORARY = llvm_cbe_tmp__1916;   /* for PHI node */
  goto llvm_cbe_tmp__1987;

llvm_cbe_tmp__1987:
  llvm_cbe_tmp__1917 = ((llvm_cbe_tmp__1917__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1122) = (((unsigned char )(bool )llvm_cbe_tmp__1917));
  llvm_cbe_tmp__1918 = *(&llvm_cbe_cppVar_1122);
  if ((((((bool )llvm_cbe_tmp__1918&1u))&1))) {
    goto llvm_cbe_tmp__1988;
  } else {
    goto llvm_cbe_tmp__1989;
  }

llvm_cbe_tmp__1988:
  llvm_cbe_tmp__1919 = *((&llvm_cbe_tmp__1853->field7));
  llvm_cbe_tmp__1920 = *((&llvm_cbe_tmp__1853->field40));
  *(&llvm_cbe_cppVar_1123) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1919) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1920);
  llvm_cbe_tmp__1921 = *((&llvm_cbe_tmp__1853->field7));
  llvm_cbe_tmp__1922 = *((&llvm_cbe_tmp__1853->field40));
  *(&llvm_cbe_cppVar_1124) = ((((signed long long )(((signed long long )llvm_cbe_tmp__1921) >> ((signed long long )0ull)))) & llvm_cbe_tmp__1922);
  llvm_cbe_tmp__1923 = *(&llvm_cbe_cppVar_1124);
  llvm_cbe_tmp__1924 = _ZN8type_memItLj8EE2rdEl(((&llvm_cbe_tmp__1853->field32)), llvm_cbe_tmp__1923);
  *(&llvm_cbe_cppVar_1125) = llvm_cbe_tmp__1924;
  llvm_cbe_tmp__1925 = *((&llvm_cbe_tmp__1853->field7));
  *(&llvm_cbe_cppVar_1128) = (((unsigned char )(bool )(llvm_cbe_tmp__1925 == 0ull)));
  llvm_cbe_tmp__1926 = *(&llvm_cbe_cppVar_1128);
  llvm_cbe_tmp__1927 = *((&llvm_cbe_tmp__1853->field27));
  if ((((((bool )llvm_cbe_tmp__1926&1u))&1))) {
    goto llvm_cbe_tmp__1990;
  } else {
    goto llvm_cbe_tmp__1991;
  }

llvm_cbe_tmp__1990:
  *(&llvm_cbe_cppVar_1130) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1927) - ((unsigned long long )62ull))));
  llvm_cbe_tmp__1928 = *(&llvm_cbe_cppVar_1130);
  llvm_cbe_tmp__1929 = *((&llvm_cbe_tmp__1853->field39));
  *(&llvm_cbe_cppVar_1130) = (llvm_cbe_tmp__1928 & llvm_cbe_tmp__1929);
  llvm_cbe_tmp__1930 = *(&llvm_cbe_cppVar_1130);
  *(&llvm_cbe_cppVar_1126) = llvm_cbe_tmp__1930;
  goto llvm_cbe_tmp__1992;

llvm_cbe_tmp__1991:
  *(&llvm_cbe_cppVar_1126) = llvm_cbe_tmp__1927;
  goto llvm_cbe_tmp__1992;

llvm_cbe_tmp__1992:
  llvm_cbe_tmp__1931 = *(&llvm_cbe_cppVar_1125);
  llvm_cbe_tmp__1932 = *(&llvm_cbe_cppVar_1126);
  *(&llvm_cbe_cppVar_1131) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__1931) - ((unsigned long long )llvm_cbe_tmp__1932))));
  llvm_cbe_tmp__1933 = *(&llvm_cbe_cppVar_1131);
  llvm_cbe_tmp__1934 = *((&llvm_cbe_tmp__1853->field39));
  *(&llvm_cbe_cppVar_1131) = (llvm_cbe_tmp__1933 & llvm_cbe_tmp__1934);
  llvm_cbe_tmp__1935 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1132), ((&llvm_cbe_tmp__1853->field32)));
  llvm_cbe_tmp__1936 = *(&llvm_cbe_cppVar_1123);
  llvm_cbe_tmp__1937 = *(&llvm_cbe_cppVar_1131);
  _ZN8type_memItLj8EE2wrEll((&llvm_cbe_cppVar_1132), llvm_cbe_tmp__1936, llvm_cbe_tmp__1937);
  llvm_cbe_tmp__1938 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1119), (&llvm_cbe_cppVar_1132));
  goto llvm_cbe_tmp__1993;

llvm_cbe_tmp__1989:
  llvm_cbe_tmp__1939 = *((&llvm_cbe_tmp__1853->field15));
  *(&llvm_cbe_cppVar_1135) = (((unsigned char )(bool )(llvm_cbe_tmp__1939 == 2ull)));
  llvm_cbe_tmp__1940 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1940&1u))&1))) {
    goto llvm_cbe_tmp__1994;
  } else {
    llvm_cbe_tmp__1943__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__1995;
  }

llvm_cbe_tmp__1994:
  llvm_cbe_tmp__1941 = *(&llvm_cbe_cppVar_1135);
  llvm_cbe_tmp__1942 = ((((bool )llvm_cbe_tmp__1941&1u))&1);
  llvm_cbe_tmp__1943__PHI_TEMPORARY = llvm_cbe_tmp__1942;   /* for PHI node */
  goto llvm_cbe_tmp__1995;

llvm_cbe_tmp__1995:
  llvm_cbe_tmp__1943 = ((llvm_cbe_tmp__1943__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1136) = (((unsigned char )(bool )llvm_cbe_tmp__1943));
  llvm_cbe_tmp__1944 = *(&llvm_cbe_cppVar_1136);
  if ((((((bool )llvm_cbe_tmp__1944&1u))&1))) {
    goto llvm_cbe_tmp__1996;
  } else {
    goto llvm_cbe_tmp__1997;
  }

llvm_cbe_tmp__1996:
  llvm_cbe_tmp__1945 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1133), ((&llvm_cbe_tmp__1853->field32)));
  goto llvm_cbe_tmp__1998;

llvm_cbe_tmp__1997:
  llvm_cbe_tmp__1946 = *((&llvm_cbe_tmp__1853->field15));
  *(&llvm_cbe_cppVar_1139) = (((unsigned char )(bool )(llvm_cbe_tmp__1946 == 3ull)));
  llvm_cbe_tmp__1947 = *(&llvm_cbe_cppVar_1092);
  if ((((((bool )llvm_cbe_tmp__1947&1u))&1))) {
    goto llvm_cbe_tmp__1999;
  } else {
    llvm_cbe_tmp__1950__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2000;
  }

llvm_cbe_tmp__1999:
  llvm_cbe_tmp__1948 = *(&llvm_cbe_cppVar_1139);
  llvm_cbe_tmp__1949 = ((((bool )llvm_cbe_tmp__1948&1u))&1);
  llvm_cbe_tmp__1950__PHI_TEMPORARY = llvm_cbe_tmp__1949;   /* for PHI node */
  goto llvm_cbe_tmp__2000;

llvm_cbe_tmp__2000:
  llvm_cbe_tmp__1950 = ((llvm_cbe_tmp__1950__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1140) = (((unsigned char )(bool )llvm_cbe_tmp__1950));
  llvm_cbe_tmp__1951 = *(&llvm_cbe_cppVar_1140);
  llvm_cbe_tmp__1952 = ((((bool )llvm_cbe_tmp__1951&1u))&1);
  llvm_cbe_tmp__1953 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1137), ((&llvm_cbe_tmp__1853->field32)));
  llvm_cbe_tmp__1954 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1133), (&llvm_cbe_cppVar_1137));
  goto llvm_cbe_tmp__1998;

llvm_cbe_tmp__1998:
  llvm_cbe_tmp__1955 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1119), (&llvm_cbe_cppVar_1133));
  goto llvm_cbe_tmp__1993;

llvm_cbe_tmp__1993:
  llvm_cbe_tmp__1956 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1093), (&llvm_cbe_cppVar_1119));
  goto llvm_cbe_tmp__1985;

llvm_cbe_tmp__1985:
  llvm_cbe_tmp__1957 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1090), (&llvm_cbe_cppVar_1093));
  goto llvm_cbe_tmp__2001;

llvm_cbe_tmp__1969:
  llvm_cbe_tmp__1958 = *((&llvm_cbe_tmp__1853->field29));
  *(&llvm_cbe_cppVar_1143) = (((unsigned char )(bool )(llvm_cbe_tmp__1958 == 2ull)));
  llvm_cbe_tmp__1959 = *(&llvm_cbe_cppVar_1143);
  llvm_cbe_tmp__1960 = ((((bool )llvm_cbe_tmp__1959&1u))&1);
  llvm_cbe_tmp__1961 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1141), ((&llvm_cbe_tmp__1853->field32)));
  llvm_cbe_tmp__1962 = _ZN8type_memItLj8EEaSERKS0_((&llvm_cbe_cppVar_1090), (&llvm_cbe_cppVar_1141));
  goto llvm_cbe_tmp__2001;

llvm_cbe_tmp__2001:
  llvm_cbe_tmp__1963 = _ZN8type_memItLj8EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1090));
  goto llvm_cbe_tmp__1967;

llvm_cbe_tmp__1967:
  *(&llvm_cbe_tmp__1851) = ((1) & 1);
  *(&llvm_cbe_tmp__1852) = 1u;
  llvm_cbe_tmp__1964 = ((*(&llvm_cbe_tmp__1851))&1);
  if (llvm_cbe_tmp__1964) {
    goto llvm_cbe_tmp__2002;
  } else {
    goto llvm_cbe_tmp__2003;
  }

llvm_cbe_tmp__2003:
  _ZN8type_memItLj8EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__2002;

llvm_cbe_tmp__2002:
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
  struct l_unnamed2 *llvm_cbe_tmp__2004;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2005;

  *(&llvm_cbe_tmp__2004) = llvm_cbe_this;
  llvm_cbe_tmp__2005 = *(&llvm_cbe_tmp__2004);
  _ZN8type_memItLj8EEC2Ev(llvm_cbe_tmp__2005);
  return;
}


struct l_unnamed2 *_ZN8type_memItLj8EEaSERKS0_(struct l_unnamed2 *llvm_cbe_this, struct l_unnamed2 *llvm_cbe_r) {
  struct l_unnamed2 *llvm_cbe_tmp__2006;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2007;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2008;
  unsigned short *llvm_cbe_tmp__2009;
  struct l_unnamed2 *llvm_cbe_tmp__2010;
  unsigned short *llvm_cbe_tmp__2011;

  *(&llvm_cbe_tmp__2006) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2007) = llvm_cbe_r;
  llvm_cbe_tmp__2008 = *(&llvm_cbe_tmp__2006);
  llvm_cbe_tmp__2009 = *((&llvm_cbe_tmp__2008->field0));
  llvm_cbe_tmp__2010 = *(&llvm_cbe_tmp__2007);
  llvm_cbe_tmp__2011 = *((&llvm_cbe_tmp__2010->field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__2009)), (((unsigned char *)llvm_cbe_tmp__2011)));
  return llvm_cbe_tmp__2008;
}


void _ZN8type_memItLj8EE2wrEll(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_unnamed2 *llvm_cbe_tmp__2012;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2013;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2014;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2015;
  unsigned long long llvm_cbe_tmp__2016;
  unsigned long long llvm_cbe_tmp__2017;
  unsigned short *llvm_cbe_tmp__2018;

  *(&llvm_cbe_tmp__2012) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2013) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__2014) = llvm_cbe_data;
  llvm_cbe_tmp__2015 = *(&llvm_cbe_tmp__2012);
  llvm_cbe_tmp__2016 = *(&llvm_cbe_tmp__2014);
  llvm_cbe_tmp__2017 = *(&llvm_cbe_tmp__2013);
  llvm_cbe_tmp__2018 = *((&llvm_cbe_tmp__2015->field0));
  *((&llvm_cbe_tmp__2018[((signed long long )llvm_cbe_tmp__2017)])) = (((unsigned short )llvm_cbe_tmp__2016));
  return;
}


void _ZN8type_memItLj8EED1Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__2019;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__2020;

  *(&llvm_cbe_tmp__2019) = llvm_cbe_this;
  llvm_cbe_tmp__2020 = *(&llvm_cbe_tmp__2019);
  _ZN8type_memItLj8EED2Ev(llvm_cbe_tmp__2020);
  return;
}


struct l_class_OC_SysCArray1D _ZN11model_train25cppUpdateFun_visible_unitElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_train *llvm_cbe_tmp__2021;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2022;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2023;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2024;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2025;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2026;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2027;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2028;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2029;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2030;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2031;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2032;    /* Address-exposed local */
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
  unsigned char *llvm_cbe_tmp__2033;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2034;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1167;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1163;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1159;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1155;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1151;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1188;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_1187;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1192;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1148;    /* Address-exposed local */
  bool llvm_cbe_tmp__2035;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2036;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__2037;
  unsigned long long llvm_cbe_tmp__2038;
  unsigned char llvm_cbe_tmp__2039;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2040;
  unsigned long long llvm_cbe_tmp__2041;
  unsigned char llvm_cbe_tmp__2042;
  unsigned long long llvm_cbe_tmp__2043;
  unsigned char llvm_cbe_tmp__2044;
  unsigned char llvm_cbe_tmp__2045;
  bool llvm_cbe_tmp__2046;
  bool llvm_cbe_tmp__2047;
  bool llvm_cbe_tmp__2047__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2048;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2049;
  unsigned long long llvm_cbe_tmp__2050;
  unsigned char llvm_cbe_tmp__2051;
  unsigned char llvm_cbe_tmp__2052;
  bool llvm_cbe_tmp__2053;
  bool llvm_cbe_tmp__2054;
  bool llvm_cbe_tmp__2054__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2055;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2056;
  unsigned long long llvm_cbe_tmp__2057;
  unsigned char llvm_cbe_tmp__2058;
  unsigned char llvm_cbe_tmp__2059;
  bool llvm_cbe_tmp__2060;
  bool llvm_cbe_tmp__2061;
  bool llvm_cbe_tmp__2061__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2062;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2063;
  unsigned long long llvm_cbe_tmp__2064;
  unsigned char llvm_cbe_tmp__2065;
  unsigned char llvm_cbe_tmp__2066;
  bool llvm_cbe_tmp__2067;
  bool llvm_cbe_tmp__2068;
  bool llvm_cbe_tmp__2068__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2069;
  unsigned long long llvm_cbe_tmp__2070;
  unsigned long long llvm_cbe_tmp__2071;
  unsigned long long llvm_cbe_tmp__2072;
  unsigned long long llvm_cbe_tmp__2073;
  unsigned long long llvm_cbe_tmp__2074;
  unsigned long long llvm_cbe_tmp__2075;
  unsigned long long llvm_cbe_tmp__2076;
  unsigned long long llvm_cbe_tmp__2077;
  unsigned long long llvm_cbe_tmp__2078;
  unsigned long long llvm_cbe_tmp__2079;
  unsigned char llvm_cbe_tmp__2080;
  unsigned char llvm_cbe_tmp__2081;
  bool llvm_cbe_tmp__2082;
  bool llvm_cbe_tmp__2083;
  bool llvm_cbe_tmp__2083__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2084;
  unsigned char llvm_cbe_tmp__2085;
  bool llvm_cbe_tmp__2086;
  bool llvm_cbe_tmp__2087;
  bool llvm_cbe_tmp__2087__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__2088;
  unsigned long long llvm_cbe_tmp__2089;
  unsigned long long llvm_cbe_tmp__2090;
  unsigned long long llvm_cbe_tmp__2091;
  unsigned long long llvm_cbe_tmp__2092;
  unsigned long long llvm_cbe_tmp__2093;
  unsigned long long llvm_cbe_tmp__2094;
  unsigned long long llvm_cbe_tmp__2095;
  unsigned long long llvm_cbe_tmp__2096;
  unsigned long long llvm_cbe_tmp__2097;
  unsigned long long llvm_cbe_tmp__2098;
  unsigned long long llvm_cbe_tmp__2099;
  unsigned long long llvm_cbe_tmp__2100;
  unsigned short llvm_cbe_tmp__2101;
  unsigned short llvm_cbe_tmp__2102;
  unsigned long long llvm_cbe_tmp__2103;
  unsigned long long llvm_cbe_tmp__2104;
  unsigned char llvm_cbe_tmp__2105;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2106;
  unsigned long long llvm_cbe_tmp__2107;
  unsigned long long llvm_cbe_tmp__2108;
  unsigned long long llvm_cbe_tmp__2109;
  unsigned long long llvm_cbe_tmp__2110;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2111;
  unsigned long long llvm_cbe_tmp__2112;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2113;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2114;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2115;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2116;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2117;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2118;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2119;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2120;
  unsigned long long llvm_cbe_tmp__2121;
  unsigned char llvm_cbe_tmp__2122;
  bool llvm_cbe_tmp__2123;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2124;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2125;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2126;
  bool llvm_cbe_tmp__2127;

  *(&llvm_cbe_tmp__2021) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2022) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2023) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2024) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2025) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2026) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2027) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2028) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2029) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2030) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2031) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2032) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2037 = *(&llvm_cbe_tmp__2021);
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1189));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1191));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1167));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1163));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1159));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1155));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1151));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1192));
  _ZN8type_memIbLj512EEC1Ev((&llvm_cbe_cppVar_1148));
  *(&llvm_cbe_tmp__2035) = ((0) & 1);
  _ZN8type_memIbLj512EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__2038 = *((&llvm_cbe_tmp__2037->field29));
  *(&llvm_cbe_cppVar_1147) = (((unsigned char )(bool )(llvm_cbe_tmp__2038 == 0ull)));
  llvm_cbe_tmp__2039 = *(&llvm_cbe_cppVar_1147);
  if ((((((bool )llvm_cbe_tmp__2039&1u))&1))) {
    goto llvm_cbe_tmp__2128;
  } else {
    goto llvm_cbe_tmp__2129;
  }

llvm_cbe_tmp__2128:
  llvm_cbe_tmp__2040 = _ZN8type_memIbLj512EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__2037->field33)));
  goto llvm_cbe_tmp__2130;

llvm_cbe_tmp__2129:
  llvm_cbe_tmp__2041 = *((&llvm_cbe_tmp__2037->field29));
  *(&llvm_cbe_cppVar_1150) = (((unsigned char )(bool )(llvm_cbe_tmp__2041 == 1ull)));
  llvm_cbe_tmp__2042 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2042&1u))&1))) {
    goto llvm_cbe_tmp__2131;
  } else {
    goto llvm_cbe_tmp__2132;
  }

llvm_cbe_tmp__2131:
  llvm_cbe_tmp__2043 = *((&llvm_cbe_tmp__2037->field15));
  *(&llvm_cbe_cppVar_1153) = (((unsigned char )(bool )(llvm_cbe_tmp__2043 == 0ull)));
  llvm_cbe_tmp__2044 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2044&1u))&1))) {
    goto llvm_cbe_tmp__2133;
  } else {
    llvm_cbe_tmp__2047__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2134;
  }

llvm_cbe_tmp__2133:
  llvm_cbe_tmp__2045 = *(&llvm_cbe_cppVar_1153);
  llvm_cbe_tmp__2046 = ((((bool )llvm_cbe_tmp__2045&1u))&1);
  llvm_cbe_tmp__2047__PHI_TEMPORARY = llvm_cbe_tmp__2046;   /* for PHI node */
  goto llvm_cbe_tmp__2134;

llvm_cbe_tmp__2134:
  llvm_cbe_tmp__2047 = ((llvm_cbe_tmp__2047__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1154) = (((unsigned char )(bool )llvm_cbe_tmp__2047));
  llvm_cbe_tmp__2048 = *(&llvm_cbe_cppVar_1154);
  if ((((((bool )llvm_cbe_tmp__2048&1u))&1))) {
    goto llvm_cbe_tmp__2135;
  } else {
    goto llvm_cbe_tmp__2136;
  }

llvm_cbe_tmp__2135:
  llvm_cbe_tmp__2049 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1151), ((&llvm_cbe_tmp__2037->field33)));
  goto llvm_cbe_tmp__2137;

llvm_cbe_tmp__2136:
  llvm_cbe_tmp__2050 = *((&llvm_cbe_tmp__2037->field15));
  *(&llvm_cbe_cppVar_1157) = (((unsigned char )(bool )(llvm_cbe_tmp__2050 == 1ull)));
  llvm_cbe_tmp__2051 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2051&1u))&1))) {
    goto llvm_cbe_tmp__2138;
  } else {
    llvm_cbe_tmp__2054__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2139;
  }

llvm_cbe_tmp__2138:
  llvm_cbe_tmp__2052 = *(&llvm_cbe_cppVar_1157);
  llvm_cbe_tmp__2053 = ((((bool )llvm_cbe_tmp__2052&1u))&1);
  llvm_cbe_tmp__2054__PHI_TEMPORARY = llvm_cbe_tmp__2053;   /* for PHI node */
  goto llvm_cbe_tmp__2139;

llvm_cbe_tmp__2139:
  llvm_cbe_tmp__2054 = ((llvm_cbe_tmp__2054__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1158) = (((unsigned char )(bool )llvm_cbe_tmp__2054));
  llvm_cbe_tmp__2055 = *(&llvm_cbe_cppVar_1158);
  if ((((((bool )llvm_cbe_tmp__2055&1u))&1))) {
    goto llvm_cbe_tmp__2140;
  } else {
    goto llvm_cbe_tmp__2141;
  }

llvm_cbe_tmp__2140:
  llvm_cbe_tmp__2056 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1155), ((&llvm_cbe_tmp__2037->field33)));
  goto llvm_cbe_tmp__2142;

llvm_cbe_tmp__2141:
  llvm_cbe_tmp__2057 = *((&llvm_cbe_tmp__2037->field15));
  *(&llvm_cbe_cppVar_1161) = (((unsigned char )(bool )(llvm_cbe_tmp__2057 == 2ull)));
  llvm_cbe_tmp__2058 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2058&1u))&1))) {
    goto llvm_cbe_tmp__2143;
  } else {
    llvm_cbe_tmp__2061__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2144;
  }

llvm_cbe_tmp__2143:
  llvm_cbe_tmp__2059 = *(&llvm_cbe_cppVar_1161);
  llvm_cbe_tmp__2060 = ((((bool )llvm_cbe_tmp__2059&1u))&1);
  llvm_cbe_tmp__2061__PHI_TEMPORARY = llvm_cbe_tmp__2060;   /* for PHI node */
  goto llvm_cbe_tmp__2144;

llvm_cbe_tmp__2144:
  llvm_cbe_tmp__2061 = ((llvm_cbe_tmp__2061__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1162) = (((unsigned char )(bool )llvm_cbe_tmp__2061));
  llvm_cbe_tmp__2062 = *(&llvm_cbe_cppVar_1162);
  if ((((((bool )llvm_cbe_tmp__2062&1u))&1))) {
    goto llvm_cbe_tmp__2145;
  } else {
    goto llvm_cbe_tmp__2146;
  }

llvm_cbe_tmp__2145:
  llvm_cbe_tmp__2063 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1159), ((&llvm_cbe_tmp__2037->field33)));
  goto llvm_cbe_tmp__2147;

llvm_cbe_tmp__2146:
  llvm_cbe_tmp__2064 = *((&llvm_cbe_tmp__2037->field15));
  *(&llvm_cbe_cppVar_1165) = (((unsigned char )(bool )(llvm_cbe_tmp__2064 == 3ull)));
  llvm_cbe_tmp__2065 = *(&llvm_cbe_cppVar_1150);
  if ((((((bool )llvm_cbe_tmp__2065&1u))&1))) {
    goto llvm_cbe_tmp__2148;
  } else {
    llvm_cbe_tmp__2068__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2149;
  }

llvm_cbe_tmp__2148:
  llvm_cbe_tmp__2066 = *(&llvm_cbe_cppVar_1165);
  llvm_cbe_tmp__2067 = ((((bool )llvm_cbe_tmp__2066&1u))&1);
  llvm_cbe_tmp__2068__PHI_TEMPORARY = llvm_cbe_tmp__2067;   /* for PHI node */
  goto llvm_cbe_tmp__2149;

llvm_cbe_tmp__2149:
  llvm_cbe_tmp__2068 = ((llvm_cbe_tmp__2068__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1166) = (((unsigned char )(bool )llvm_cbe_tmp__2068));
  llvm_cbe_tmp__2069 = *(&llvm_cbe_cppVar_1166);
  if ((((((bool )llvm_cbe_tmp__2069&1u))&1))) {
    goto llvm_cbe_tmp__2150;
  } else {
    goto llvm_cbe_tmp__2151;
  }

llvm_cbe_tmp__2150:
  llvm_cbe_tmp__2070 = *((&llvm_cbe_tmp__2037->field7));
  *(&llvm_cbe_cppVar_1169) = (((unsigned char )(bool )(llvm_cbe_tmp__2070 == 4ull)));
  llvm_cbe_tmp__2071 = *((&llvm_cbe_tmp__2037->field30));
  *(&llvm_cbe_cppVar_1171) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2071) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2072 = *(&llvm_cbe_cppVar_1171);
  llvm_cbe_tmp__2073 = *((&llvm_cbe_tmp__2037->field39));
  *(&llvm_cbe_cppVar_1171) = (llvm_cbe_tmp__2072 & llvm_cbe_tmp__2073);
  llvm_cbe_tmp__2074 = *(&llvm_cbe_cppVar_1171);
  llvm_cbe_tmp__2075 = *((&llvm_cbe_tmp__2037->field14));
  *(&llvm_cbe_cppVar_1172) = (((unsigned char )(bool )(llvm_cbe_tmp__2074 == llvm_cbe_tmp__2075)));
  llvm_cbe_tmp__2076 = *((&llvm_cbe_tmp__2037->field30));
  *(&llvm_cbe_cppVar_1174) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2076) + ((unsigned long long )5ull))));
  llvm_cbe_tmp__2077 = *(&llvm_cbe_cppVar_1174);
  llvm_cbe_tmp__2078 = *((&llvm_cbe_tmp__2037->field39));
  *(&llvm_cbe_cppVar_1174) = (llvm_cbe_tmp__2077 & llvm_cbe_tmp__2078);
  llvm_cbe_tmp__2079 = *(&llvm_cbe_cppVar_1174);
  *(&llvm_cbe_cppVar_1176) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__2079) >= ((signed long long )500ull))));
  llvm_cbe_tmp__2080 = *(&llvm_cbe_cppVar_1172);
  if ((((((bool )llvm_cbe_tmp__2080&1u))&1))) {
    llvm_cbe_tmp__2083__PHI_TEMPORARY = 1;   /* for PHI node */
    goto llvm_cbe_tmp__2152;
  } else {
    goto llvm_cbe_tmp__2153;
  }

llvm_cbe_tmp__2153:
  llvm_cbe_tmp__2081 = *(&llvm_cbe_cppVar_1176);
  llvm_cbe_tmp__2082 = ((((bool )llvm_cbe_tmp__2081&1u))&1);
  llvm_cbe_tmp__2083__PHI_TEMPORARY = llvm_cbe_tmp__2082;   /* for PHI node */
  goto llvm_cbe_tmp__2152;

llvm_cbe_tmp__2152:
  llvm_cbe_tmp__2083 = ((llvm_cbe_tmp__2083__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1177) = (((unsigned char )(bool )llvm_cbe_tmp__2083));
  llvm_cbe_tmp__2084 = *(&llvm_cbe_cppVar_1169);
  if ((((((bool )llvm_cbe_tmp__2084&1u))&1))) {
    goto llvm_cbe_tmp__2154;
  } else {
    llvm_cbe_tmp__2087__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__2155;
  }

llvm_cbe_tmp__2154:
  llvm_cbe_tmp__2085 = *(&llvm_cbe_cppVar_1177);
  llvm_cbe_tmp__2086 = ((((bool )llvm_cbe_tmp__2085&1u))&1);
  llvm_cbe_tmp__2087__PHI_TEMPORARY = llvm_cbe_tmp__2086;   /* for PHI node */
  goto llvm_cbe_tmp__2155;

llvm_cbe_tmp__2155:
  llvm_cbe_tmp__2087 = ((llvm_cbe_tmp__2087__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_1178) = (((unsigned char )(bool )llvm_cbe_tmp__2087));
  llvm_cbe_tmp__2088 = *(&llvm_cbe_cppVar_1178);
  if ((((((bool )llvm_cbe_tmp__2088&1u))&1))) {
    goto llvm_cbe_tmp__2156;
  } else {
    goto llvm_cbe_tmp__2157;
  }

llvm_cbe_tmp__2156:
  llvm_cbe_tmp__2089 = *((&llvm_cbe_tmp__2037->field30));
  llvm_cbe_tmp__2090 = *((&llvm_cbe_tmp__2037->field7));
  *(&llvm_cbe_cppVar_1179) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__2089) + ((unsigned long long )llvm_cbe_tmp__2090))));
  llvm_cbe_tmp__2091 = *(&llvm_cbe_cppVar_1179);
  llvm_cbe_tmp__2092 = *((&llvm_cbe_tmp__2037->field39));
  *(&llvm_cbe_cppVar_1179) = (llvm_cbe_tmp__2091 & llvm_cbe_tmp__2092);
  llvm_cbe_tmp__2093 = *(&llvm_cbe_cppVar_1179);
  llvm_cbe_tmp__2094 = *((&llvm_cbe_tmp__2037->field45));
  *(&llvm_cbe_cppVar_1180) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2093) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2094);
  llvm_cbe_tmp__2095 = *((&llvm_cbe_tmp__2037->field7));
  llvm_cbe_tmp__2096 = *((&llvm_cbe_tmp__2037->field40));
  *(&llvm_cbe_cppVar_1182) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2095) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2096);
  llvm_cbe_tmp__2097 = *(&llvm_cbe_cppVar_1182);
  llvm_cbe_tmp__2098 = _ZN8type_memIjLj8EE2rdEl(((&llvm_cbe_tmp__2037->field17)), llvm_cbe_tmp__2097);
  *(&llvm_cbe_cppVar_1183) = llvm_cbe_tmp__2098;
  llvm_cbe_tmp__2099 = *(&llvm_cbe_cppVar_1183);
  llvm_cbe_tmp__2100 = *((&llvm_cbe_tmp__2037->field24));
  llvm_cbe_tmp__2101 = _Z6dividell(llvm_cbe_tmp__2099, llvm_cbe_tmp__2100);
  *(&llvm_cbe_cppVar_1184) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__2101));
  llvm_cbe_tmp__2102 = _Z4randv();
  *(&llvm_cbe_cppVar_1185) = (((unsigned long long )(unsigned short )llvm_cbe_tmp__2102));
  llvm_cbe_tmp__2103 = *(&llvm_cbe_cppVar_1184);
  llvm_cbe_tmp__2104 = *(&llvm_cbe_cppVar_1185);
  *(&llvm_cbe_cppVar_1186) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__2103) > ((signed long long )llvm_cbe_tmp__2104))));
  llvm_cbe_tmp__2105 = *(&llvm_cbe_cppVar_1186);
  if ((((((bool )llvm_cbe_tmp__2105&1u))&1))) {
    goto llvm_cbe_tmp__2158;
  } else {
    goto llvm_cbe_tmp__2159;
  }

llvm_cbe_tmp__2158:
  *(&llvm_cbe_cppVar_1181) = 1ull;
  goto llvm_cbe_tmp__2160;

llvm_cbe_tmp__2159:
  *(&llvm_cbe_cppVar_1181) = 0ull;
  goto llvm_cbe_tmp__2160;

llvm_cbe_tmp__2160:
  llvm_cbe_tmp__2106 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1189), ((&llvm_cbe_tmp__2037->field33)));
  llvm_cbe_tmp__2107 = *(&llvm_cbe_cppVar_1180);
  llvm_cbe_tmp__2108 = *(&llvm_cbe_cppVar_1181);
  _ZN8type_memIbLj512EE2wrEll((&llvm_cbe_cppVar_1189), llvm_cbe_tmp__2107, llvm_cbe_tmp__2108);
  llvm_cbe_tmp__2109 = *((&llvm_cbe_tmp__2037->field14));
  llvm_cbe_tmp__2110 = *((&llvm_cbe_tmp__2037->field45));
  *(&llvm_cbe_cppVar_1190) = ((((signed long long )(((signed long long )llvm_cbe_tmp__2109) >> ((signed long long )0ull)))) & llvm_cbe_tmp__2110);
  llvm_cbe_tmp__2111 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1191), (&llvm_cbe_cppVar_1189));
  llvm_cbe_tmp__2112 = *(&llvm_cbe_cppVar_1190);
  _ZN8type_memIbLj512EE2wrEll((&llvm_cbe_cppVar_1191), llvm_cbe_tmp__2112, 1ull);
  llvm_cbe_tmp__2113 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1167), (&llvm_cbe_cppVar_1191));
  goto llvm_cbe_tmp__2161;

llvm_cbe_tmp__2157:
  llvm_cbe_tmp__2114 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1167), (&llvm_cbe_cppVar_1189));
  goto llvm_cbe_tmp__2161;

llvm_cbe_tmp__2161:
  llvm_cbe_tmp__2115 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1163), (&llvm_cbe_cppVar_1167));
  goto llvm_cbe_tmp__2162;

llvm_cbe_tmp__2151:
  llvm_cbe_tmp__2116 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1163), ((&llvm_cbe_tmp__2037->field33)));
  goto llvm_cbe_tmp__2162;

llvm_cbe_tmp__2162:
  llvm_cbe_tmp__2117 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1159), (&llvm_cbe_cppVar_1163));
  goto llvm_cbe_tmp__2147;

llvm_cbe_tmp__2147:
  llvm_cbe_tmp__2118 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1155), (&llvm_cbe_cppVar_1159));
  goto llvm_cbe_tmp__2142;

llvm_cbe_tmp__2142:
  llvm_cbe_tmp__2119 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1151), (&llvm_cbe_cppVar_1155));
  goto llvm_cbe_tmp__2137;

llvm_cbe_tmp__2137:
  llvm_cbe_tmp__2120 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1148), (&llvm_cbe_cppVar_1151));
  goto llvm_cbe_tmp__2163;

llvm_cbe_tmp__2132:
  llvm_cbe_tmp__2121 = *((&llvm_cbe_tmp__2037->field29));
  *(&llvm_cbe_cppVar_1194) = (((unsigned char )(bool )(llvm_cbe_tmp__2121 == 2ull)));
  llvm_cbe_tmp__2122 = *(&llvm_cbe_cppVar_1194);
  llvm_cbe_tmp__2123 = ((((bool )llvm_cbe_tmp__2122&1u))&1);
  llvm_cbe_tmp__2124 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1192), ((&llvm_cbe_tmp__2037->field33)));
  llvm_cbe_tmp__2125 = _ZN8type_memIbLj512EEaSERKS0_((&llvm_cbe_cppVar_1148), (&llvm_cbe_cppVar_1192));
  goto llvm_cbe_tmp__2163;

llvm_cbe_tmp__2163:
  llvm_cbe_tmp__2126 = _ZN8type_memIbLj512EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_1148));
  goto llvm_cbe_tmp__2130;

llvm_cbe_tmp__2130:
  *(&llvm_cbe_tmp__2035) = ((1) & 1);
  *(&llvm_cbe_tmp__2036) = 1u;
  llvm_cbe_tmp__2127 = ((*(&llvm_cbe_tmp__2035))&1);
  if (llvm_cbe_tmp__2127) {
    goto llvm_cbe_tmp__2164;
  } else {
    goto llvm_cbe_tmp__2165;
  }

llvm_cbe_tmp__2165:
  _ZN8type_memIbLj512EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__2164;

llvm_cbe_tmp__2164:
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
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2166;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2167;

  *(&llvm_cbe_tmp__2166) = llvm_cbe_this;
  llvm_cbe_tmp__2167 = *(&llvm_cbe_tmp__2166);
  _ZN8type_memIbLj512EEC2Ev(llvm_cbe_tmp__2167);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIbLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2168;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2169;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2170;
  unsigned char *llvm_cbe_tmp__2171;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2172;
  unsigned char *llvm_cbe_tmp__2173;

  *(&llvm_cbe_tmp__2168) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2169) = llvm_cbe_r;
  llvm_cbe_tmp__2170 = *(&llvm_cbe_tmp__2168);
  llvm_cbe_tmp__2171 = *((&llvm_cbe_tmp__2170->field0));
  llvm_cbe_tmp__2172 = *(&llvm_cbe_tmp__2169);
  llvm_cbe_tmp__2173 = *((&llvm_cbe_tmp__2172->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2171, llvm_cbe_tmp__2173);
  return llvm_cbe_tmp__2170;
}


unsigned long long _ZN8type_memIjLj8EE2rdEl(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_unnamed1 *llvm_cbe_tmp__2174;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2175;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__2176;
  unsigned long long llvm_cbe_tmp__2177;
  unsigned int *llvm_cbe_tmp__2178;
  unsigned int llvm_cbe_tmp__2179;

  *(&llvm_cbe_tmp__2174) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2175) = llvm_cbe_addr;
  llvm_cbe_tmp__2176 = *(&llvm_cbe_tmp__2174);
  llvm_cbe_tmp__2177 = *(&llvm_cbe_tmp__2175);
  llvm_cbe_tmp__2178 = *((&llvm_cbe_tmp__2176->field0));
  llvm_cbe_tmp__2179 = *((&llvm_cbe_tmp__2178[((signed long long )llvm_cbe_tmp__2177)]));
  return (((unsigned long long )(unsigned int )llvm_cbe_tmp__2179));
}


void _ZN8type_memIbLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2180;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2181;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2182;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2183;
  unsigned long long llvm_cbe_tmp__2184;
  unsigned long long llvm_cbe_tmp__2185;
  unsigned char *llvm_cbe_tmp__2186;

  *(&llvm_cbe_tmp__2180) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2181) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__2182) = llvm_cbe_data;
  llvm_cbe_tmp__2183 = *(&llvm_cbe_tmp__2180);
  llvm_cbe_tmp__2184 = *(&llvm_cbe_tmp__2182);
  llvm_cbe_tmp__2185 = *(&llvm_cbe_tmp__2181);
  llvm_cbe_tmp__2186 = *((&llvm_cbe_tmp__2183->field0));
  *((&llvm_cbe_tmp__2186[((signed long long )llvm_cbe_tmp__2185)])) = (((unsigned char )(bool )(llvm_cbe_tmp__2184 != 0ull)));
  return;
}


void _ZN8type_memIbLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2187;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2188;

  *(&llvm_cbe_tmp__2187) = llvm_cbe_this;
  llvm_cbe_tmp__2188 = *(&llvm_cbe_tmp__2187);
  _ZN8type_memIbLj512EED2Ev(llvm_cbe_tmp__2188);
  return;
}


void _ZN11model_train6updateElllllllllll(struct l_class_OC_model_train *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_train *llvm_cbe_tmp__2189;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2190;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2191;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2192;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2193;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2194;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2195;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2196;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2197;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2198;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2199;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2200;    /* Address-exposed local */
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
  unsigned char *llvm_cbe_tmp__2201;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2202;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1055;    /* Address-exposed local */
  struct l_unnamed1 llvm_cbe_cppVar_1086;    /* Address-exposed local */
  struct l_unnamed2 llvm_cbe_cppVar_1144;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_1195;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2203;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__2204;
  unsigned long long llvm_cbe_tmp__2205;
  unsigned long long llvm_cbe_tmp__2206;
  unsigned long long llvm_cbe_tmp__2207;
  unsigned long long llvm_cbe_tmp__2208;
  unsigned long long llvm_cbe_tmp__2209;
  unsigned long long llvm_cbe_tmp__2210;
  unsigned long long llvm_cbe_tmp__2211;
  unsigned long long llvm_cbe_tmp__2212;
  unsigned long long llvm_cbe_tmp__2213;
  unsigned long long llvm_cbe_tmp__2214;
  unsigned long long llvm_cbe_tmp__2215;
  unsigned long long llvm_cbe_tmp__2216;
  unsigned long long llvm_cbe_tmp__2217;
  unsigned long long llvm_cbe_tmp__2218;
  unsigned long long llvm_cbe_tmp__2219;
  unsigned long long llvm_cbe_tmp__2220;
  unsigned long long llvm_cbe_tmp__2221;
  unsigned long long llvm_cbe_tmp__2222;
  unsigned long long llvm_cbe_tmp__2223;
  unsigned long long llvm_cbe_tmp__2224;
  unsigned long long llvm_cbe_tmp__2225;
  unsigned long long llvm_cbe_tmp__2226;
  unsigned long long llvm_cbe_tmp__2227;
  unsigned long long llvm_cbe_tmp__2228;
  unsigned long long llvm_cbe_tmp__2229;
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
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2427;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2428;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2429;
  struct l_unnamed1 *llvm_cbe_tmp__2430;
  struct l_unnamed2 *llvm_cbe_tmp__2431;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2432;

  *(&llvm_cbe_tmp__2189) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2190) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__2191) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__2192) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__2193) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__2194) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__2195) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__2196) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__2197) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__2198) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__2199) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__2200) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__2204 = *(&llvm_cbe_tmp__2189);
  llvm_cbe_tmp__2205 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2206 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2207 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2208 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2209 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2210 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2211 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2212 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2213 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2214 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2215 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2216 = _ZN11model_train18cppUpdateFun_indexElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2205, llvm_cbe_tmp__2206, llvm_cbe_tmp__2207, llvm_cbe_tmp__2208, llvm_cbe_tmp__2209, llvm_cbe_tmp__2210, llvm_cbe_tmp__2211, llvm_cbe_tmp__2212, llvm_cbe_tmp__2213, llvm_cbe_tmp__2214, llvm_cbe_tmp__2215);
  *(&llvm_cbe_cppVar_512) = llvm_cbe_tmp__2216;
  llvm_cbe_tmp__2217 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2218 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2219 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2220 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2221 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2222 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2223 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2224 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2225 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2226 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2227 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2228 = _ZN11model_train19cppUpdateFun_jstateElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2217, llvm_cbe_tmp__2218, llvm_cbe_tmp__2219, llvm_cbe_tmp__2220, llvm_cbe_tmp__2221, llvm_cbe_tmp__2222, llvm_cbe_tmp__2223, llvm_cbe_tmp__2224, llvm_cbe_tmp__2225, llvm_cbe_tmp__2226, llvm_cbe_tmp__2227);
  *(&llvm_cbe_cppVar_549) = llvm_cbe_tmp__2228;
  llvm_cbe_tmp__2229 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2230 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2231 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2232 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2233 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2234 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2235 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2236 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2237 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2238 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2239 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2240 = _ZN11model_train23cppUpdateFun_loop_countElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2229, llvm_cbe_tmp__2230, llvm_cbe_tmp__2231, llvm_cbe_tmp__2232, llvm_cbe_tmp__2233, llvm_cbe_tmp__2234, llvm_cbe_tmp__2235, llvm_cbe_tmp__2236, llvm_cbe_tmp__2237, llvm_cbe_tmp__2238, llvm_cbe_tmp__2239);
  *(&llvm_cbe_cppVar_571) = llvm_cbe_tmp__2240;
  llvm_cbe_tmp__2241 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2242 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2243 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2244 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2245 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2246 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2247 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2248 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2249 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2250 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2251 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2252 = _ZN11model_train21cppUpdateFun_per_v_pcElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2241, llvm_cbe_tmp__2242, llvm_cbe_tmp__2243, llvm_cbe_tmp__2244, llvm_cbe_tmp__2245, llvm_cbe_tmp__2246, llvm_cbe_tmp__2247, llvm_cbe_tmp__2248, llvm_cbe_tmp__2249, llvm_cbe_tmp__2250, llvm_cbe_tmp__2251);
  *(&llvm_cbe_cppVar_618) = llvm_cbe_tmp__2252;
  llvm_cbe_tmp__2253 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2254 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2255 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2256 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2257 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2258 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2259 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2260 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2261 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2262 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2263 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2264 = _ZN11model_train22cppUpdateFun_sumOfpow2Elllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2253, llvm_cbe_tmp__2254, llvm_cbe_tmp__2255, llvm_cbe_tmp__2256, llvm_cbe_tmp__2257, llvm_cbe_tmp__2258, llvm_cbe_tmp__2259, llvm_cbe_tmp__2260, llvm_cbe_tmp__2261, llvm_cbe_tmp__2262, llvm_cbe_tmp__2263);
  *(&llvm_cbe_cppVar_654) = llvm_cbe_tmp__2264;
  llvm_cbe_tmp__2265 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2266 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2267 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2268 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2269 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2270 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2271 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2272 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2273 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2274 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2275 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2276 = _ZN11model_train24cppUpdateFun_train_h_cntElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2265, llvm_cbe_tmp__2266, llvm_cbe_tmp__2267, llvm_cbe_tmp__2268, llvm_cbe_tmp__2269, llvm_cbe_tmp__2270, llvm_cbe_tmp__2271, llvm_cbe_tmp__2272, llvm_cbe_tmp__2273, llvm_cbe_tmp__2274, llvm_cbe_tmp__2275);
  *(&llvm_cbe_cppVar_704) = llvm_cbe_tmp__2276;
  llvm_cbe_tmp__2277 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2278 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2279 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2280 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2281 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2282 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2283 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2284 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2285 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2286 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2287 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2288 = _ZN11model_train29cppUpdateFun_train_input_doneElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2277, llvm_cbe_tmp__2278, llvm_cbe_tmp__2279, llvm_cbe_tmp__2280, llvm_cbe_tmp__2281, llvm_cbe_tmp__2282, llvm_cbe_tmp__2283, llvm_cbe_tmp__2284, llvm_cbe_tmp__2285, llvm_cbe_tmp__2286, llvm_cbe_tmp__2287);
  *(&llvm_cbe_cppVar_719) = llvm_cbe_tmp__2288;
  llvm_cbe_tmp__2289 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2290 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2291 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2292 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2293 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2294 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2295 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2296 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2297 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2298 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2299 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2300 = _ZN11model_train22cppUpdateFun_train_maxElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2289, llvm_cbe_tmp__2290, llvm_cbe_tmp__2291, llvm_cbe_tmp__2292, llvm_cbe_tmp__2293, llvm_cbe_tmp__2294, llvm_cbe_tmp__2295, llvm_cbe_tmp__2296, llvm_cbe_tmp__2297, llvm_cbe_tmp__2298, llvm_cbe_tmp__2299);
  *(&llvm_cbe_cppVar_777) = llvm_cbe_tmp__2300;
  llvm_cbe_tmp__2301 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2302 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2303 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2304 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2305 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2306 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2307 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2308 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2309 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2310 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2311 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2312 = _ZN11model_train22cppUpdateFun_train_sumElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2301, llvm_cbe_tmp__2302, llvm_cbe_tmp__2303, llvm_cbe_tmp__2304, llvm_cbe_tmp__2305, llvm_cbe_tmp__2306, llvm_cbe_tmp__2307, llvm_cbe_tmp__2308, llvm_cbe_tmp__2309, llvm_cbe_tmp__2310, llvm_cbe_tmp__2311);
  *(&llvm_cbe_cppVar_837) = llvm_cbe_tmp__2312;
  llvm_cbe_tmp__2313 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2314 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2315 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2316 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2317 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2318 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2319 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2320 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2321 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2322 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2323 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2324 = _ZN11model_train22cppUpdateFun_train_upcElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2313, llvm_cbe_tmp__2314, llvm_cbe_tmp__2315, llvm_cbe_tmp__2316, llvm_cbe_tmp__2317, llvm_cbe_tmp__2318, llvm_cbe_tmp__2319, llvm_cbe_tmp__2320, llvm_cbe_tmp__2321, llvm_cbe_tmp__2322, llvm_cbe_tmp__2323);
  *(&llvm_cbe_cppVar_884) = llvm_cbe_tmp__2324;
  llvm_cbe_tmp__2325 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2326 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2327 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2328 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2329 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2330 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2331 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2332 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2333 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2334 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2335 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2336 = _ZN11model_train24cppUpdateFun_train_v_cntElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2325, llvm_cbe_tmp__2326, llvm_cbe_tmp__2327, llvm_cbe_tmp__2328, llvm_cbe_tmp__2329, llvm_cbe_tmp__2330, llvm_cbe_tmp__2331, llvm_cbe_tmp__2332, llvm_cbe_tmp__2333, llvm_cbe_tmp__2334, llvm_cbe_tmp__2335);
  *(&llvm_cbe_cppVar_932) = llvm_cbe_tmp__2336;
  llvm_cbe_tmp__2337 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2338 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2339 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2340 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2341 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2342 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2343 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2344 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2345 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2346 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2347 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_tmp__2348 = _ZN11model_train16cppUpdateFun_upcElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2337, llvm_cbe_tmp__2338, llvm_cbe_tmp__2339, llvm_cbe_tmp__2340, llvm_cbe_tmp__2341, llvm_cbe_tmp__2342, llvm_cbe_tmp__2343, llvm_cbe_tmp__2344, llvm_cbe_tmp__2345, llvm_cbe_tmp__2346, llvm_cbe_tmp__2347);
  *(&llvm_cbe_cppVar_947) = llvm_cbe_tmp__2348;
  llvm_cbe_tmp__2349 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2350 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2351 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2352 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2353 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2354 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2355 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2356 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2357 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2358 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2359 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_cppVar_990 = _ZN11model_train18cppUpdateFun_edgesElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2349, llvm_cbe_tmp__2350, llvm_cbe_tmp__2351, llvm_cbe_tmp__2352, llvm_cbe_tmp__2353, llvm_cbe_tmp__2354, llvm_cbe_tmp__2355, llvm_cbe_tmp__2356, llvm_cbe_tmp__2357, llvm_cbe_tmp__2358, llvm_cbe_tmp__2359);
  llvm_cbe_tmp__2360 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2361 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2362 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2363 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2364 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2365 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2366 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2367 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2368 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2369 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2370 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_cppVar_1037 = _ZN11model_train24cppUpdateFun_hidden_unitElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2360, llvm_cbe_tmp__2361, llvm_cbe_tmp__2362, llvm_cbe_tmp__2363, llvm_cbe_tmp__2364, llvm_cbe_tmp__2365, llvm_cbe_tmp__2366, llvm_cbe_tmp__2367, llvm_cbe_tmp__2368, llvm_cbe_tmp__2369, llvm_cbe_tmp__2370);
  llvm_cbe_tmp__2371 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2372 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2373 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2374 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2375 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2376 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2377 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2378 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2379 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2380 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2381 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_cppVar_1055 = _ZN11model_train16cppUpdateFun_posElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2371, llvm_cbe_tmp__2372, llvm_cbe_tmp__2373, llvm_cbe_tmp__2374, llvm_cbe_tmp__2375, llvm_cbe_tmp__2376, llvm_cbe_tmp__2377, llvm_cbe_tmp__2378, llvm_cbe_tmp__2379, llvm_cbe_tmp__2380, llvm_cbe_tmp__2381);
  llvm_cbe_tmp__2382 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2383 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2384 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2385 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2386 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2387 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2388 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2389 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2390 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2391 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2392 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_cppVar_1086 = _ZN11model_train17cppUpdateFun_pow2Elllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2382, llvm_cbe_tmp__2383, llvm_cbe_tmp__2384, llvm_cbe_tmp__2385, llvm_cbe_tmp__2386, llvm_cbe_tmp__2387, llvm_cbe_tmp__2388, llvm_cbe_tmp__2389, llvm_cbe_tmp__2390, llvm_cbe_tmp__2391, llvm_cbe_tmp__2392);
  llvm_cbe_tmp__2393 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2394 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2395 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2396 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2397 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2398 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2399 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2400 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2401 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2402 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2403 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_cppVar_1144 = _ZN11model_train28cppUpdateFun_visibleEnergiesElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2393, llvm_cbe_tmp__2394, llvm_cbe_tmp__2395, llvm_cbe_tmp__2396, llvm_cbe_tmp__2397, llvm_cbe_tmp__2398, llvm_cbe_tmp__2399, llvm_cbe_tmp__2400, llvm_cbe_tmp__2401, llvm_cbe_tmp__2402, llvm_cbe_tmp__2403);
  llvm_cbe_tmp__2404 = *(&llvm_cbe_tmp__2190);
  llvm_cbe_tmp__2405 = *(&llvm_cbe_tmp__2191);
  llvm_cbe_tmp__2406 = *(&llvm_cbe_tmp__2192);
  llvm_cbe_tmp__2407 = *(&llvm_cbe_tmp__2193);
  llvm_cbe_tmp__2408 = *(&llvm_cbe_tmp__2194);
  llvm_cbe_tmp__2409 = *(&llvm_cbe_tmp__2195);
  llvm_cbe_tmp__2410 = *(&llvm_cbe_tmp__2196);
  llvm_cbe_tmp__2411 = *(&llvm_cbe_tmp__2197);
  llvm_cbe_tmp__2412 = *(&llvm_cbe_tmp__2198);
  llvm_cbe_tmp__2413 = *(&llvm_cbe_tmp__2199);
  llvm_cbe_tmp__2414 = *(&llvm_cbe_tmp__2200);
  llvm_cbe_cppVar_1195 = _ZN11model_train25cppUpdateFun_visible_unitElllllllllll(llvm_cbe_tmp__2204, llvm_cbe_tmp__2404, llvm_cbe_tmp__2405, llvm_cbe_tmp__2406, llvm_cbe_tmp__2407, llvm_cbe_tmp__2408, llvm_cbe_tmp__2409, llvm_cbe_tmp__2410, llvm_cbe_tmp__2411, llvm_cbe_tmp__2412, llvm_cbe_tmp__2413, llvm_cbe_tmp__2414);
  llvm_cbe_tmp__2415 = *(&llvm_cbe_cppVar_512);
  *((&llvm_cbe_tmp__2204->field5)) = llvm_cbe_tmp__2415;
  llvm_cbe_tmp__2416 = *(&llvm_cbe_cppVar_549);
  *((&llvm_cbe_tmp__2204->field7)) = llvm_cbe_tmp__2416;
  llvm_cbe_tmp__2417 = *(&llvm_cbe_cppVar_571);
  *((&llvm_cbe_tmp__2204->field8)) = llvm_cbe_tmp__2417;
  llvm_cbe_tmp__2418 = *(&llvm_cbe_cppVar_618);
  *((&llvm_cbe_tmp__2204->field15)) = llvm_cbe_tmp__2418;
  llvm_cbe_tmp__2419 = *(&llvm_cbe_cppVar_654);
  *((&llvm_cbe_tmp__2204->field24)) = llvm_cbe_tmp__2419;
  llvm_cbe_tmp__2420 = *(&llvm_cbe_cppVar_704);
  *((&llvm_cbe_tmp__2204->field25)) = llvm_cbe_tmp__2420;
  llvm_cbe_tmp__2421 = *(&llvm_cbe_cppVar_719);
  *((&llvm_cbe_tmp__2204->field26)) = llvm_cbe_tmp__2421;
  llvm_cbe_tmp__2422 = *(&llvm_cbe_cppVar_777);
  *((&llvm_cbe_tmp__2204->field27)) = llvm_cbe_tmp__2422;
  llvm_cbe_tmp__2423 = *(&llvm_cbe_cppVar_837);
  *((&llvm_cbe_tmp__2204->field28)) = llvm_cbe_tmp__2423;
  llvm_cbe_tmp__2424 = *(&llvm_cbe_cppVar_884);
  *((&llvm_cbe_tmp__2204->field29)) = llvm_cbe_tmp__2424;
  llvm_cbe_tmp__2425 = *(&llvm_cbe_cppVar_932);
  *((&llvm_cbe_tmp__2204->field30)) = llvm_cbe_tmp__2425;
  llvm_cbe_tmp__2426 = *(&llvm_cbe_cppVar_947);
  *((&llvm_cbe_tmp__2204->field31)) = llvm_cbe_tmp__2426;
  llvm_cbe_tmp__2427 = _ZN8type_memIhLj65536EEaSERKS0_(((&llvm_cbe_tmp__2204->field3)), (&llvm_cbe_cppVar_990));
  llvm_cbe_tmp__2428 = _ZN8type_memIbLj128EEaSERKS0_(((&llvm_cbe_tmp__2204->field4)), (&llvm_cbe_cppVar_1037));
  llvm_cbe_tmp__2429 = _ZN8type_memIbLj65536EEaSERKS0_(((&llvm_cbe_tmp__2204->field16)), (&llvm_cbe_cppVar_1055));
  llvm_cbe_tmp__2430 = _ZN8type_memIjLj8EEaSERKS0_(((&llvm_cbe_tmp__2204->field17)), (&llvm_cbe_cppVar_1086));
  llvm_cbe_tmp__2431 = _ZN8type_memItLj8EEaSERKS0_(((&llvm_cbe_tmp__2204->field32)), (&llvm_cbe_cppVar_1144));
  llvm_cbe_tmp__2432 = _ZN8type_memIbLj512EEaSERKS0_(((&llvm_cbe_tmp__2204->field33)), (&llvm_cbe_cppVar_1195));
  *(&llvm_cbe_tmp__2203) = 1u;
  _ZN8type_memIbLj512EED1Ev((&llvm_cbe_cppVar_1195));
  _ZN8type_memItLj8EED1Ev((&llvm_cbe_cppVar_1144));
  _ZN8type_memIjLj8EED1Ev((&llvm_cbe_cppVar_1086));
  _ZN8type_memIbLj65536EED1Ev((&llvm_cbe_cppVar_1055));
  _ZN8type_memIbLj128EED1Ev((&llvm_cbe_cppVar_1037));
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_990));
  return;
}


static void __cxx_global_var_init(void) {
  unsigned int llvm_cbe_tmp__2433;

  _ZN11model_trainC1Ev((&GM));
  llvm_cbe_tmp__2433 = __cxa_atexit(((void  (*) (unsigned char *))_ZN11model_trainD1Ev), ((unsigned char *)(&GM)), ((unsigned char *)(&__dso_handle)));
  return;
}


void _ZN11model_trainC1Ev(struct l_class_OC_model_train *llvm_cbe_this) {
  struct l_class_OC_model_train *llvm_cbe_tmp__2434;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__2435;

  *(&llvm_cbe_tmp__2434) = llvm_cbe_this;
  llvm_cbe_tmp__2435 = *(&llvm_cbe_tmp__2434);
  _ZN11model_trainC2Ev(llvm_cbe_tmp__2435);
  return;
}


void _ZN11model_trainD1Ev(struct l_class_OC_model_train *llvm_cbe_this) {
  struct l_class_OC_model_train *llvm_cbe_tmp__2436;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__2437;

  *(&llvm_cbe_tmp__2436) = llvm_cbe_this;
  llvm_cbe_tmp__2437 = *(&llvm_cbe_tmp__2436);
  _ZN11model_trainD2Ev(llvm_cbe_tmp__2437);
  return;
}


void _Z4waitv(void) {
  unsigned int llvm_cbe_tmp__2438;

  llvm_cbe_tmp__2438 = *(&cycleCnt);
  *(&cycleCnt) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2438) + ((unsigned int )1u))));
  return;
}


void _Z15reset_signal_isib(unsigned int llvm_cbe_tmp__2439, bool llvm_cbe_tmp__2440) {
  unsigned int llvm_cbe_tmp__2441;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2442;    /* Address-exposed local */

  *(&llvm_cbe_tmp__2441) = llvm_cbe_tmp__2439;
  *(&llvm_cbe_tmp__2442) = (((unsigned char )(bool )llvm_cbe_tmp__2440));
  return;
}


void _Z14set_stack_sizei(unsigned int llvm_cbe_tmp__2443) {
  unsigned int llvm_cbe_tmp__2444;    /* Address-exposed local */

  *(&llvm_cbe_tmp__2444) = llvm_cbe_tmp__2443;
  return;
}


unsigned long long _Z8_c_16_15f(float llvm_cbe_in) {
  float llvm_cbe_tmp__2445;    /* Address-exposed local */
  float llvm_cbe_tmp__2446;

  *(&llvm_cbe_tmp__2445) = llvm_cbe_in;
  llvm_cbe_tmp__2446 = *(&llvm_cbe_tmp__2445);
  return ((((signed long long )(((float )(llvm_cbe_tmp__2446 * 0x1p+1))))) & 65535ull);
}


float _Z8_b_16_15l(unsigned long long llvm_cbe_in) {
  unsigned long long llvm_cbe_tmp__2447;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2448;

  *(&llvm_cbe_tmp__2447) = llvm_cbe_in;
  llvm_cbe_tmp__2448 = *(&llvm_cbe_tmp__2447);
  return (((float )((((double )(signed long long )(llvm_cbe_tmp__2448 & 65535ull))) / 0x1p+1)));
}


void _ZN3rbm6configEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2449;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2450;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2451;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2452;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2453;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2454;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2455;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2456;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2457;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2458;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2459;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2460;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2461;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2462;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2463;
  bool llvm_cbe_tmp__2464;
  unsigned int llvm_cbe_tmp__2465;
  unsigned int llvm_cbe_tmp__2466;
  unsigned int llvm_cbe_tmp__2467;
  unsigned int llvm_cbe_tmp__2468;
  unsigned int llvm_cbe_tmp__2469;
  unsigned int llvm_cbe_tmp__2470;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2471;
  unsigned int llvm_cbe_tmp__2472;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2473;

  *(&llvm_cbe_tmp__2449) = llvm_cbe_this;
  llvm_cbe_tmp__2463 = *(&llvm_cbe_tmp__2449);
  *(&llvm_cbe_tmp__2450) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field30)), (&llvm_cbe_tmp__2450));
  *(&llvm_cbe_tmp__2451) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field31)), (&llvm_cbe_tmp__2451));
  *(&llvm_cbe_tmp__2452) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field32)), (&llvm_cbe_tmp__2452));
  *(&llvm_cbe_tmp__2453) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field33)), (&llvm_cbe_tmp__2453));
  *(&llvm_cbe_tmp__2454) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field35)), (&llvm_cbe_tmp__2454));
  *(&llvm_cbe_tmp__2455) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2463->field36)), (&llvm_cbe_tmp__2455));
  _Z4waitv();
  goto llvm_cbe_tmp__2474;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2474:
  _Z4waitv();
  llvm_cbe_tmp__2464 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2463->field13))))&1);
  if ((((llvm_cbe_tmp__2464 ^ 1)&1))) {
    goto llvm_cbe_tmp__2474;
  } else {
    goto llvm_cbe_tmp__2475;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2475:
  llvm_cbe_tmp__2465 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2463->field14)));
  *(&llvm_cbe_tmp__2456) = (((unsigned short )llvm_cbe_tmp__2465));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field30)), (&llvm_cbe_tmp__2456));
  llvm_cbe_tmp__2466 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2463->field15)));
  *(&llvm_cbe_tmp__2457) = (((unsigned short )llvm_cbe_tmp__2466));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field31)), (&llvm_cbe_tmp__2457));
  llvm_cbe_tmp__2467 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2463->field16)));
  *(&llvm_cbe_tmp__2458) = (((unsigned short )llvm_cbe_tmp__2467));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field32)), (&llvm_cbe_tmp__2458));
  llvm_cbe_tmp__2468 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2463->field17)));
  *(&llvm_cbe_tmp__2459) = (((unsigned short )llvm_cbe_tmp__2468));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field33)), (&llvm_cbe_tmp__2459));
  llvm_cbe_tmp__2469 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2463->field18)));
  *(&llvm_cbe_tmp__2460) = (((unsigned short )llvm_cbe_tmp__2469));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field34)), (&llvm_cbe_tmp__2460));
  llvm_cbe_tmp__2470 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2463->field19)));
  *(&llvm_cbe_tmp__2461) = (((unsigned short )llvm_cbe_tmp__2470));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2463->field35)), (&llvm_cbe_tmp__2461));
  llvm_cbe_tmp__2471 = _ZNSt6iocoutlsEPKc((&_ZSt4cout), ((&_OC_str.array[((signed int )0u)])));
  llvm_cbe_tmp__2472 = *(&_ZSt4endl);
  llvm_cbe_tmp__2473 = _ZNSt6iocoutlsEi(llvm_cbe_tmp__2471, llvm_cbe_tmp__2472);
  *(&llvm_cbe_tmp__2462) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2463->field36)), (&llvm_cbe_tmp__2462));
  goto llvm_cbe_tmp__2476;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2476:
  _Z4waitv();
  goto llvm_cbe_tmp__2476;

  } while (1); /* end of syntactic loop '' */
}


void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__2477;    /* Address-exposed local */
  unsigned short *llvm_cbe_tmp__2478;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__2479;
  unsigned short *llvm_cbe_tmp__2480;
  unsigned short llvm_cbe_tmp__2481;

  *(&llvm_cbe_tmp__2477) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2478) = llvm_cbe_d;
  llvm_cbe_tmp__2479 = *(&llvm_cbe_tmp__2477);
  llvm_cbe_tmp__2480 = *(&llvm_cbe_tmp__2478);
  llvm_cbe_tmp__2481 = *llvm_cbe_tmp__2480;
  *((&llvm_cbe_tmp__2479->field0)) = llvm_cbe_tmp__2481;
  return;
}


void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2482;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2483;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2484;
  unsigned char *llvm_cbe_tmp__2485;
  unsigned char llvm_cbe_tmp__2486;

  *(&llvm_cbe_tmp__2482) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2483) = llvm_cbe_d;
  llvm_cbe_tmp__2484 = *(&llvm_cbe_tmp__2482);
  llvm_cbe_tmp__2485 = *(&llvm_cbe_tmp__2483);
  llvm_cbe_tmp__2486 = *llvm_cbe_tmp__2485;
  *((&llvm_cbe_tmp__2484->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2486&1u))&1))));
  return;
}


bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2487;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2488;
  unsigned char llvm_cbe_tmp__2489;

  *(&llvm_cbe_tmp__2487) = llvm_cbe_this;
  llvm_cbe_tmp__2488 = *(&llvm_cbe_tmp__2487);
  llvm_cbe_tmp__2489 = *((&llvm_cbe_tmp__2488->field0));
  return (((((bool )llvm_cbe_tmp__2489&1u))&1));
}


unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2490;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2491;
  unsigned int llvm_cbe_tmp__2492;

  *(&llvm_cbe_tmp__2490) = llvm_cbe_this;
  llvm_cbe_tmp__2491 = *(&llvm_cbe_tmp__2490);
  llvm_cbe_tmp__2492 = *((&llvm_cbe_tmp__2491->field0));
  return llvm_cbe_tmp__2492;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_tmp__2493) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2494;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2495;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2496;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2497;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2498;

  *(&llvm_cbe_tmp__2495) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2496) = llvm_cbe_tmp__2493;
  llvm_cbe_tmp__2497 = *(&llvm_cbe_tmp__2495);
  llvm_cbe_tmp__2498 = *(&llvm_cbe_tmp__2494);
  return llvm_cbe_tmp__2498;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEi(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned int llvm_cbe_tmp__2499) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2500;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2501;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2502;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2503;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2504;

  *(&llvm_cbe_tmp__2501) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2502) = llvm_cbe_tmp__2499;
  llvm_cbe_tmp__2503 = *(&llvm_cbe_tmp__2501);
  llvm_cbe_tmp__2504 = *(&llvm_cbe_tmp__2500);
  return llvm_cbe_tmp__2504;
}


void _ZN3rbm4loadEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2505;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2506;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2507;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2508;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2509;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2510;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2511;    /* Address-exposed local */
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
  unsigned int llvm_cbe_tmp__2512;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2513;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2514;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2515;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned char llvm_cbe_rate;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2516;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2517;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2518;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2519;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2520;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2521;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2522;    /* Address-exposed local */
  unsigned short llvm_cbe_i1;    /* Address-exposed local */
  unsigned char llvm_cbe_rate2;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2523;
  bool llvm_cbe_tmp__2524;
  bool llvm_cbe_tmp__2525;
  unsigned short llvm_cbe_tmp__2526;
  unsigned short llvm_cbe_tmp__2527;
  unsigned short llvm_cbe_tmp__2528;
  unsigned short llvm_cbe_tmp__2529;
  unsigned short llvm_cbe_tmp__2530;
  unsigned short llvm_cbe_tmp__2531;
  unsigned int llvm_cbe_tmp__2532;
  unsigned short llvm_cbe_tmp__2533;
  unsigned int llvm_cbe_tmp__2534;
  bool llvm_cbe_tmp__2535;
  bool llvm_cbe_tmp__2536;
  unsigned short llvm_cbe_tmp__2537;
  unsigned int llvm_cbe_tmp__2538;
  unsigned short llvm_cbe_tmp__2539;
  unsigned short llvm_cbe_tmp__2540;
  unsigned short llvm_cbe_tmp__2541;
  unsigned short llvm_cbe_tmp__2542;
  unsigned short llvm_cbe_tmp__2543;
  unsigned int llvm_cbe_tmp__2544;
  unsigned int llvm_cbe_tmp__2545;
  unsigned char llvm_cbe_tmp__2546;
  unsigned short llvm_cbe_tmp__2547;
  unsigned char llvm_cbe_tmp__2548;
  unsigned char *llvm_cbe_tmp__2549;
  unsigned short llvm_cbe_tmp__2550;
  unsigned int llvm_cbe_tmp__2551;
  unsigned char llvm_cbe_tmp__2552;
  unsigned char *llvm_cbe_tmp__2553;
  unsigned short llvm_cbe_tmp__2554;
  unsigned int llvm_cbe_tmp__2555;
  bool llvm_cbe_tmp__2556;
  bool llvm_cbe_tmp__2557;
  bool llvm_cbe_tmp__2558;
  bool llvm_cbe_tmp__2559;
  unsigned short llvm_cbe_tmp__2560;
  unsigned short llvm_cbe_tmp__2561;
  unsigned int llvm_cbe_tmp__2562;
  unsigned short llvm_cbe_tmp__2563;
  unsigned int llvm_cbe_tmp__2564;
  unsigned short llvm_cbe_tmp__2565;
  unsigned short llvm_cbe_tmp__2566;
  unsigned int llvm_cbe_tmp__2567;
  unsigned short llvm_cbe_tmp__2568;
  unsigned int llvm_cbe_tmp__2569;
  unsigned int llvm_cbe_tmp__2570;
  unsigned short llvm_cbe_tmp__2571;
  unsigned short llvm_cbe_tmp__2572;
  unsigned int llvm_cbe_tmp__2573;
  unsigned int llvm_cbe_tmp__2574;
  unsigned int llvm_cbe_tmp__2575;
  unsigned int llvm_cbe_tmp__2576;
  unsigned int llvm_cbe_tmp__2577;
  unsigned short llvm_cbe_tmp__2578;
  unsigned int llvm_cbe_tmp__2579;
  bool llvm_cbe_tmp__2580;
  bool llvm_cbe_tmp__2581;
  unsigned short llvm_cbe_tmp__2582;
  unsigned int llvm_cbe_tmp__2583;
  unsigned short llvm_cbe_tmp__2584;
  unsigned short llvm_cbe_tmp__2585;
  unsigned short llvm_cbe_tmp__2586;
  unsigned short llvm_cbe_tmp__2587;
  unsigned short llvm_cbe_tmp__2588;
  unsigned int llvm_cbe_tmp__2589;
  unsigned int llvm_cbe_tmp__2590;
  unsigned char llvm_cbe_tmp__2591;
  unsigned short llvm_cbe_tmp__2592;
  unsigned char llvm_cbe_tmp__2593;
  unsigned char *llvm_cbe_tmp__2594;
  unsigned short llvm_cbe_tmp__2595;
  unsigned int llvm_cbe_tmp__2596;
  unsigned char llvm_cbe_tmp__2597;
  unsigned char *llvm_cbe_tmp__2598;

  *(&llvm_cbe_tmp__2505) = llvm_cbe_this;
  llvm_cbe_tmp__2523 = *(&llvm_cbe_tmp__2505);
  *(&llvm_cbe_tmp__2506) = ((unsigned char )1);
  llvm_cbe_tmp__2524 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2523->field36)), (&llvm_cbe_tmp__2506)))&1);
  *(&llvm_cbe_tmp__2507) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2523->field2)), (&llvm_cbe_tmp__2507));
  *(&llvm_cbe_tmp__2508) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2523->field3)), (&llvm_cbe_tmp__2508));
  *(&llvm_cbe_tmp__2509) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field4)), (&llvm_cbe_tmp__2509));
  *(&llvm_cbe_tmp__2510) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field37)), (&llvm_cbe_tmp__2510));
  *(&llvm_cbe_tmp__2511) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field38)), (&llvm_cbe_tmp__2511));
  goto llvm_cbe_tmp__2599;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2599:
  _Z4waitv();
  llvm_cbe_tmp__2525 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field36))))&1);
  if ((((llvm_cbe_tmp__2525 ^ 1)&1))) {
    goto llvm_cbe_tmp__2599;
  } else {
    goto llvm_cbe_tmp__2600;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2600:
  *(&llvm_cbe_index) = ((unsigned short )0);
  *(&llvm_cbe_loop_count) = ((unsigned short )0);
  *(&llvm_cbe_pingpong) = ((unsigned char )0);
  llvm_cbe_tmp__2526 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2523->field31)));
  *(&llvm_cbe_nv) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2526));
  llvm_cbe_tmp__2527 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2523->field34)));
  *(&llvm_cbe_ntu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2527));
  llvm_cbe_tmp__2528 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2523->field32)));
  *(&llvm_cbe_nu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2528));
  llvm_cbe_tmp__2529 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2523->field33)));
  *(&llvm_cbe_nlp) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2529));
  llvm_cbe_tmp__2530 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2523->field35)));
  *(&llvm_cbe_nm) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2530));
  *(&upc) = 0u;
  llvm_cbe_tmp__2531 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp__2512) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2531));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2523->field2)), (&llvm_cbe_tmp__2512));
  llvm_cbe_tmp__2532 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__2513) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__2532))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2523->field3)), (&llvm_cbe_tmp__2513));
  llvm_cbe_tmp__2533 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2534 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2533)) == llvm_cbe_tmp__2534)) {
    goto llvm_cbe_tmp__2601;
  } else {
    goto llvm_cbe_tmp__2602;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2601:
  _Z4waitv();
  llvm_cbe_tmp__2535 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field40))))&1);
  if ((((llvm_cbe_tmp__2535 ^ 1)&1))) {
    goto llvm_cbe_tmp__2601;
  } else {
    goto llvm_cbe_tmp__2602;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2602:
  *(&llvm_cbe_tmp__2514) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field4)), (&llvm_cbe_tmp__2514));
  goto llvm_cbe_tmp__2603;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2603:
  _Z4waitv();
  *(&upc) = 1u;
  llvm_cbe_tmp__2536 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field5))))&1);
  if ((((llvm_cbe_tmp__2536 ^ 1)&1))) {
    goto llvm_cbe_tmp__2603;
  } else {
    goto llvm_cbe_tmp__2604;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2604:
  *(&llvm_cbe_tmp__2515) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field4)), (&llvm_cbe_tmp__2515));
  llvm_cbe_tmp__2537 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2538 = *(&llvm_cbe_nu);
  *(&llvm_cbe_tmp1) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2537))) * ((unsigned int )llvm_cbe_tmp__2538))))));
  llvm_cbe_tmp__2539 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__2540 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp2) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2539))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2540))))))));
  llvm_cbe_tmp__2541 = *(&llvm_cbe_tmp2);
  *(&llvm_cbe_pingpong) = (((unsigned char )(bool )((((signed int )(((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2541))) % ((signed int )2u)))) != 0u)));
  *(&llvm_cbe_i) = ((unsigned short )0);
  goto llvm_cbe_tmp__2605;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2605:
  llvm_cbe_tmp__2542 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2542))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__2606;
  } else {
    goto llvm_cbe_tmp__2607;
  }

llvm_cbe_tmp__2608:
  llvm_cbe_tmp__2545 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2523->field6)));
  *(&llvm_cbe_rate) = (((unsigned char )llvm_cbe_tmp__2545));
  _Z4waitv();
  llvm_cbe_tmp__2546 = *(&llvm_cbe_rate);
  llvm_cbe_tmp__2547 = *(&llvm_cbe_i);
  llvm_cbe_tmp__2548 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__2549 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2523->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2548&1u))&1)))));
  *((&llvm_cbe_tmp__2549[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2547)))])) = llvm_cbe_tmp__2546;
  llvm_cbe_tmp__2550 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2550) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2605;

llvm_cbe_tmp__2606:
  llvm_cbe_tmp__2543 = *(&llvm_cbe_i);
  llvm_cbe_tmp__2544 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2543)) == llvm_cbe_tmp__2544)) {
    goto llvm_cbe_tmp__2607;
  } else {
    goto llvm_cbe_tmp__2608;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2607:
  _Z4waitv();
  llvm_cbe_tmp__2551 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__2552 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__2553 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2523->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2552&1u))&1)))));
  *((&llvm_cbe_tmp__2553[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__2551)))])) = ((unsigned char )1);
  *(&upc) = 2u;
  goto llvm_cbe_tmp__2609;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2609:
  llvm_cbe_tmp__2554 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2555 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2554)) != llvm_cbe_tmp__2555)) {
    goto llvm_cbe_tmp__2610;
  } else {
    goto llvm_cbe_tmp__2611;
  }

llvm_cbe_tmp__2612:
  _Z4waitv();
  llvm_cbe_tmp__2596 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__2597 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__2598 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2523->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2597&1u))&1)))));
  *((&llvm_cbe_tmp__2598[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__2596)))])) = ((unsigned char )1);
  goto llvm_cbe_tmp__2609;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2613:
  llvm_cbe_tmp__2587 = *(&llvm_cbe_i1);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2587))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__2614;
  } else {
    goto llvm_cbe_tmp__2612;
  }

llvm_cbe_tmp__2615:
  llvm_cbe_tmp__2590 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2523->field6)));
  *(&llvm_cbe_rate2) = (((unsigned char )llvm_cbe_tmp__2590));
  _Z4waitv();
  llvm_cbe_tmp__2591 = *(&llvm_cbe_rate2);
  llvm_cbe_tmp__2592 = *(&llvm_cbe_i1);
  llvm_cbe_tmp__2593 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__2594 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2523->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2593&1u))&1)))));
  *((&llvm_cbe_tmp__2594[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2592)))])) = llvm_cbe_tmp__2591;
  llvm_cbe_tmp__2595 = *(&llvm_cbe_i1);
  *(&llvm_cbe_i1) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2595) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2613;

llvm_cbe_tmp__2614:
  llvm_cbe_tmp__2588 = *(&llvm_cbe_i1);
  llvm_cbe_tmp__2589 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2588)) == llvm_cbe_tmp__2589)) {
    goto llvm_cbe_tmp__2612;
  } else {
    goto llvm_cbe_tmp__2615;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2616:
  *(&llvm_cbe_tmp__2522) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field4)), (&llvm_cbe_tmp__2522));
  llvm_cbe_tmp__2582 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2583 = *(&llvm_cbe_nu);
  *(&llvm_cbe_tmp1) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2582))) * ((unsigned int )llvm_cbe_tmp__2583))))));
  llvm_cbe_tmp__2584 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__2585 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp2) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2584))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2585))))))));
  llvm_cbe_tmp__2586 = *(&llvm_cbe_tmp2);
  *(&llvm_cbe_pingpong) = (((unsigned char )(bool )((((signed int )(((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2586))) % ((signed int )2u)))) != 0u)));
  *(&llvm_cbe_i1) = ((unsigned short )0);
  goto llvm_cbe_tmp__2613;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2617:
  _Z4waitv();
  llvm_cbe_tmp__2581 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field5))))&1);
  if ((((llvm_cbe_tmp__2581 ^ 1)&1))) {
    goto llvm_cbe_tmp__2617;
  } else {
    goto llvm_cbe_tmp__2616;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2618:
  *(&llvm_cbe_tmp__2521) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field4)), (&llvm_cbe_tmp__2521));
  goto llvm_cbe_tmp__2617;

llvm_cbe_tmp__2619:
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2523->field2)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__2577 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__2520) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__2577))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2523->field3)), (&llvm_cbe_tmp__2520));
  llvm_cbe_tmp__2578 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2579 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2578)) == llvm_cbe_tmp__2579)) {
    goto llvm_cbe_tmp__2620;
  } else {
    goto llvm_cbe_tmp__2618;
  }

llvm_cbe_tmp__2621:
  llvm_cbe_tmp__2570 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__2571 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2570) * ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2571))))));
  llvm_cbe_tmp__2572 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2573 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2572)) == llvm_cbe_tmp__2573)) {
    goto llvm_cbe_tmp__2622;
  } else {
    goto llvm_cbe_tmp__2619;
  }

llvm_cbe_tmp__2623:
  llvm_cbe_tmp__2566 = *(&llvm_cbe_index);
  llvm_cbe_tmp__2567 = *(&llvm_cbe_ntu);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2566)) == llvm_cbe_tmp__2567)) {
    goto llvm_cbe_tmp__2624;
  } else {
    goto llvm_cbe_tmp__2621;
  }

llvm_cbe_tmp__2625:
  llvm_cbe_tmp__2560 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2560))) + ((unsigned int )1u))))));
  llvm_cbe_tmp__2561 = *(&llvm_cbe_index);
  llvm_cbe_tmp__2562 = *(&llvm_cbe_nu);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2561)) == llvm_cbe_tmp__2562)) {
    goto llvm_cbe_tmp__2626;
  } else {
    goto llvm_cbe_tmp__2623;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2627:
  _Z4waitv();
  llvm_cbe_tmp__2557 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field39))))&1);
  if (llvm_cbe_tmp__2557) {
    goto llvm_cbe_tmp__2627;
  } else {
    goto llvm_cbe_tmp__2625;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2628:
  *(&llvm_cbe_tmp__2517) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field37)), (&llvm_cbe_tmp__2517));
  goto llvm_cbe_tmp__2627;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2629:
  _Z4waitv();
  llvm_cbe_tmp__2556 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field39))))&1);
  if ((((llvm_cbe_tmp__2556 ^ 1)&1))) {
    goto llvm_cbe_tmp__2629;
  } else {
    goto llvm_cbe_tmp__2628;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2610:
  *(&llvm_cbe_tmp__2516) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field37)), (&llvm_cbe_tmp__2516));
  *(&upc) = 2u;
  goto llvm_cbe_tmp__2629;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2630:
  _Z4waitv();
  llvm_cbe_tmp__2559 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field42))))&1);
  if (llvm_cbe_tmp__2559) {
    goto llvm_cbe_tmp__2630;
  } else {
    goto llvm_cbe_tmp__2625;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2631:
  *(&llvm_cbe_tmp__2519) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field38)), (&llvm_cbe_tmp__2519));
  goto llvm_cbe_tmp__2630;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2632:
  _Z4waitv();
  llvm_cbe_tmp__2558 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field42))))&1);
  if ((((llvm_cbe_tmp__2558 ^ 1)&1))) {
    goto llvm_cbe_tmp__2632;
  } else {
    goto llvm_cbe_tmp__2631;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2611:
  *(&llvm_cbe_tmp__2518) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2523->field38)), (&llvm_cbe_tmp__2518));
  *(&upc) = 2u;
  goto llvm_cbe_tmp__2632;

llvm_cbe_tmp__2626:
  llvm_cbe_tmp__2563 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2564 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2563)) != llvm_cbe_tmp__2564)) {
    goto llvm_cbe_tmp__2633;
  } else {
    goto llvm_cbe_tmp__2623;
  }

llvm_cbe_tmp__2633:
  llvm_cbe_tmp__2565 = *(&llvm_cbe_loop_count);
  *(&llvm_cbe_loop_count) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2565))) + ((unsigned int )1u))))));
  *(&llvm_cbe_index) = ((unsigned short )0);
  goto llvm_cbe_tmp__2623;

llvm_cbe_tmp__2624:
  llvm_cbe_tmp__2568 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__2569 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2568)) == llvm_cbe_tmp__2569)) {
    goto llvm_cbe_tmp__2634;
  } else {
    goto llvm_cbe_tmp__2621;
  }

llvm_cbe_tmp__2622:
  llvm_cbe_tmp__2574 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__2575 = *(&llvm_cbe_nu);
  llvm_cbe_tmp__2576 = *(&llvm_cbe_dma_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2576) + ((unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2574) * ((unsigned int )llvm_cbe_tmp__2575))))))));
  goto llvm_cbe_tmp__2619;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2620:
  _Z4waitv();
  llvm_cbe_tmp__2580 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2523->field40))))&1);
  if ((((llvm_cbe_tmp__2580 ^ 1)&1))) {
    goto llvm_cbe_tmp__2620;
  } else {
    goto llvm_cbe_tmp__2618;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2634:
  _Z4waitv();
  *(&upc) = 3u;
  goto llvm_cbe_tmp__2634;

  } while (1); /* end of syntactic loop '' */
}


bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2635;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__2636;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__2637;
  unsigned char *llvm_cbe_tmp__2638;
  unsigned char llvm_cbe_tmp__2639;
  unsigned char llvm_cbe_tmp__2640;

  *(&llvm_cbe_tmp__2635) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2636) = llvm_cbe_d;
  llvm_cbe_tmp__2637 = *(&llvm_cbe_tmp__2635);
  llvm_cbe_tmp__2638 = *(&llvm_cbe_tmp__2636);
  llvm_cbe_tmp__2639 = *llvm_cbe_tmp__2638;
  *((&llvm_cbe_tmp__2637->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2639&1u))&1))));
  llvm_cbe_tmp__2640 = *((&llvm_cbe_tmp__2637->field0));
  return (((((bool )llvm_cbe_tmp__2640&1u))&1));
}


void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2641;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__2642;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2643;
  unsigned int *llvm_cbe_tmp__2644;
  unsigned int llvm_cbe_tmp__2645;

  *(&llvm_cbe_tmp__2641) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2642) = llvm_cbe_d;
  llvm_cbe_tmp__2643 = *(&llvm_cbe_tmp__2641);
  llvm_cbe_tmp__2644 = *(&llvm_cbe_tmp__2642);
  llvm_cbe_tmp__2645 = *llvm_cbe_tmp__2644;
  *((&llvm_cbe_tmp__2643->field0)) = llvm_cbe_tmp__2645;
  return;
}


unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__2646;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__2647;
  unsigned short llvm_cbe_tmp__2648;

  *(&llvm_cbe_tmp__2646) = llvm_cbe_this;
  llvm_cbe_tmp__2647 = *(&llvm_cbe_tmp__2646);
  llvm_cbe_tmp__2648 = *((&llvm_cbe_tmp__2647->field0));
  return llvm_cbe_tmp__2648;
}


unsigned char *_ZN13SysCArray2DstIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__2649;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__2650;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2651;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__2652;
  unsigned int llvm_cbe_tmp__2653;
  unsigned char *llvm_cbe_tmp__2654;
  unsigned int llvm_cbe_tmp__2655;
  unsigned char *llvm_cbe_tmp__2656;
  unsigned char *llvm_cbe_tmp__2657;

  *(&llvm_cbe_tmp__2650) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2651) = llvm_cbe_Xidx;
  llvm_cbe_tmp__2652 = *(&llvm_cbe_tmp__2650);
  llvm_cbe_tmp__2653 = *(&llvm_cbe_tmp__2651);
  if ((llvm_cbe_tmp__2653 == 0u)) {
    goto llvm_cbe_tmp__2658;
  } else {
    goto llvm_cbe_tmp__2659;
  }

llvm_cbe_tmp__2658:
  llvm_cbe_tmp__2654 = *((&llvm_cbe_tmp__2652->field1));
  *(&llvm_cbe_tmp__2649) = llvm_cbe_tmp__2654;
  goto llvm_cbe_tmp__2660;

llvm_cbe_tmp__2659:
  llvm_cbe_tmp__2655 = *(&llvm_cbe_tmp__2651);
  llvm_cbe_tmp__2656 = *((&llvm_cbe_tmp__2652->field0));
  *(&llvm_cbe_tmp__2649) = ((&llvm_cbe_tmp__2656[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2655) * ((unsigned int )512u)))))))]));
  goto llvm_cbe_tmp__2660;

llvm_cbe_tmp__2660:
  llvm_cbe_tmp__2657 = *(&llvm_cbe_tmp__2649);
  return llvm_cbe_tmp__2657;
}


void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2661;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2662;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2663;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2664;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2665;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2666;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2667;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2668;    /* Address-exposed local */
  unsigned short llvm_cbe_ntu;    /* Address-exposed local */
  unsigned short llvm_cbe_nm;    /* Address-exposed local */
  unsigned int llvm_cbe_index;    /* Address-exposed local */
  unsigned char llvm_cbe_rating;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2669;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2670;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2671;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2672;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2673;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2674;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2675;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2676;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2677;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2678;
  bool llvm_cbe_tmp__2679;
  bool llvm_cbe_tmp__2680;
  unsigned short llvm_cbe_tmp__2681;
  unsigned short llvm_cbe_tmp__2682;
  unsigned int llvm_cbe_tmp__2683;
  unsigned short llvm_cbe_tmp__2684;
  bool llvm_cbe_tmp__2685;
  bool llvm_cbe_tmp__2686;
  unsigned short llvm_cbe_tmp__2687;
  unsigned int llvm_cbe_tmp__2688;
  unsigned short llvm_cbe_tmp__2689;
  unsigned int llvm_cbe_tmp__2690;
  bool llvm_cbe_tmp__2691;
  unsigned short llvm_cbe_tmp__2692;
  unsigned short llvm_cbe_tmp__2693;
  unsigned short llvm_cbe_tmp__2694;
  unsigned short llvm_cbe_tmp__2695;
  unsigned char *llvm_cbe_tmp__2696;
  unsigned char llvm_cbe_tmp__2697;
  unsigned char llvm_cbe_tmp__2698;
  unsigned short llvm_cbe_tmp__2699;

  *(&llvm_cbe_tmp__2661) = llvm_cbe_this;
  llvm_cbe_tmp__2678 = *(&llvm_cbe_tmp__2661);
  *(&llvm_cbe_tmp__2662) = ((unsigned char )1);
  llvm_cbe_tmp__2679 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2678->field36)), (&llvm_cbe_tmp__2662)))&1);
  *(&llvm_cbe_tmp__2663) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2678->field8)), (&llvm_cbe_tmp__2663));
  *(&llvm_cbe_tmp__2664) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2678->field7)), (&llvm_cbe_tmp__2664));
  *(&llvm_cbe_tmp__2665) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field9)), (&llvm_cbe_tmp__2665));
  *(&llvm_cbe_tmp__2666) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field44)), (&llvm_cbe_tmp__2666));
  *(&llvm_cbe_tmp__2667) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field45)), (&llvm_cbe_tmp__2667));
  *(&llvm_cbe_tmp__2668) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field12)), (&llvm_cbe_tmp__2668));
  goto llvm_cbe_tmp__2700;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2700:
  _Z4waitv();
  llvm_cbe_tmp__2680 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2678->field36))))&1);
  if ((((llvm_cbe_tmp__2680 ^ 1)&1))) {
    goto llvm_cbe_tmp__2700;
  } else {
    goto llvm_cbe_tmp__2701;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2701:
  llvm_cbe_tmp__2681 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2678->field34)));
  *(&llvm_cbe_ntu) = llvm_cbe_tmp__2681;
  llvm_cbe_tmp__2682 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2678->field35)));
  *(&llvm_cbe_nm) = llvm_cbe_tmp__2682;
  *(&llvm_cbe_index) = 0u;
  goto llvm_cbe_tmp__2702;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2702:
  llvm_cbe_tmp__2683 = *(&llvm_cbe_index);
  llvm_cbe_tmp__2684 = *(&llvm_cbe_ntu);
  if ((llvm_cbe_tmp__2683 == (((unsigned int )(unsigned short )llvm_cbe_tmp__2684)))) {
    goto llvm_cbe_tmp__2703;
  } else {
    goto llvm_cbe_tmp__2704;
  }

llvm_cbe_tmp__2705:
  *(&llvm_cbe_tmp__2677) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field45)), (&llvm_cbe_tmp__2677));
  goto llvm_cbe_tmp__2702;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2706:
  llvm_cbe_tmp__2692 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2692))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__2707;
  } else {
    goto llvm_cbe_tmp__2705;
  }

llvm_cbe_tmp__2708:
  llvm_cbe_tmp__2695 = *(&llvm_cbe_i);
  llvm_cbe_tmp__2696 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2678->field28)), 0u);
  llvm_cbe_tmp__2697 = *((&llvm_cbe_tmp__2696[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2695)))]));
  *(&llvm_cbe_rating) = llvm_cbe_tmp__2697;
  _Z4waitv();
  llvm_cbe_tmp__2698 = *(&llvm_cbe_rating);
  *(&llvm_cbe_tmp__2676) = (((unsigned int )(unsigned char )llvm_cbe_tmp__2698));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2678->field11)), (&llvm_cbe_tmp__2676));
  llvm_cbe_tmp__2699 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2699) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2706;

llvm_cbe_tmp__2707:
  llvm_cbe_tmp__2693 = *(&llvm_cbe_i);
  llvm_cbe_tmp__2694 = *(&llvm_cbe_nm);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2693)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__2694)))) {
    goto llvm_cbe_tmp__2705;
  } else {
    goto llvm_cbe_tmp__2708;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2709:
  *(&llvm_cbe_tmp__2675) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field9)), (&llvm_cbe_tmp__2675));
  *(&llvm_cbe_i) = ((unsigned short )0);
  goto llvm_cbe_tmp__2706;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2710:
  _Z4waitv();
  llvm_cbe_tmp__2691 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2678->field10))))&1);
  if ((((llvm_cbe_tmp__2691 ^ 1)&1))) {
    goto llvm_cbe_tmp__2710;
  } else {
    goto llvm_cbe_tmp__2709;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2711:
  *(&llvm_cbe_tmp__2671) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field44)), (&llvm_cbe_tmp__2671));
  *(&llvm_cbe_tmp__2672) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field45)), (&llvm_cbe_tmp__2672));
  llvm_cbe_tmp__2687 = *(&llvm_cbe_nm);
  llvm_cbe_tmp__2688 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2687))) * ((unsigned int )llvm_cbe_tmp__2688))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2678->field7)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__2689 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2678->field35)));
  *(&llvm_cbe_tmp__2673) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2689));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2678->field8)), (&llvm_cbe_tmp__2673));
  llvm_cbe_tmp__2690 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__2690) + ((unsigned int )1u))));
  *(&llvm_cbe_tmp__2674) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field9)), (&llvm_cbe_tmp__2674));
  goto llvm_cbe_tmp__2710;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2712:
  _Z4waitv();
  llvm_cbe_tmp__2686 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2678->field43))))&1);
  if (llvm_cbe_tmp__2686) {
    goto llvm_cbe_tmp__2712;
  } else {
    goto llvm_cbe_tmp__2711;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2713:
  *(&llvm_cbe_tmp__2670) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field44)), (&llvm_cbe_tmp__2670));
  goto llvm_cbe_tmp__2712;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2704:
  _Z4waitv();
  llvm_cbe_tmp__2685 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2678->field43))))&1);
  if ((((llvm_cbe_tmp__2685 ^ 1)&1))) {
    goto llvm_cbe_tmp__2704;
  } else {
    goto llvm_cbe_tmp__2713;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2703:
  *(&llvm_cbe_tmp__2669) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2678->field12)), (&llvm_cbe_tmp__2669));
  goto llvm_cbe_tmp__2714;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2714:
  _Z4waitv();
  goto llvm_cbe_tmp__2714;

  } while (1); /* end of syntactic loop '' */
}


unsigned char *_ZN13SysCArray2DstIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2Dst *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__2715;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__2716;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2717;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__2718;
  unsigned int llvm_cbe_tmp__2719;
  unsigned char *llvm_cbe_tmp__2720;
  unsigned int llvm_cbe_tmp__2721;
  unsigned char *llvm_cbe_tmp__2722;
  unsigned char *llvm_cbe_tmp__2723;

  *(&llvm_cbe_tmp__2716) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2717) = llvm_cbe_Xidx;
  llvm_cbe_tmp__2718 = *(&llvm_cbe_tmp__2716);
  llvm_cbe_tmp__2719 = *(&llvm_cbe_tmp__2717);
  if ((llvm_cbe_tmp__2719 == 0u)) {
    goto llvm_cbe_tmp__2724;
  } else {
    goto llvm_cbe_tmp__2725;
  }

llvm_cbe_tmp__2724:
  llvm_cbe_tmp__2720 = *((&llvm_cbe_tmp__2718->field1));
  *(&llvm_cbe_tmp__2715) = llvm_cbe_tmp__2720;
  goto llvm_cbe_tmp__2726;

llvm_cbe_tmp__2725:
  llvm_cbe_tmp__2721 = *(&llvm_cbe_tmp__2717);
  llvm_cbe_tmp__2722 = *((&llvm_cbe_tmp__2718->field0));
  *(&llvm_cbe_tmp__2715) = ((&llvm_cbe_tmp__2722[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2721) * ((unsigned int )128u)))))))]));
  goto llvm_cbe_tmp__2726;

llvm_cbe_tmp__2726:
  llvm_cbe_tmp__2723 = *(&llvm_cbe_tmp__2715);
  return llvm_cbe_tmp__2723;
}


void _ZN3rbm9train_rbmEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2727;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2728;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2729;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2730;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2731;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2732;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2733;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2734;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2735;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2736;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2737;    /* Address-exposed local */
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
  unsigned char llvm_cbe_tmp__2738;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2739;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2740;    /* Address-exposed local */
  float llvm_cbe_de;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2741;
  bool llvm_cbe_tmp__2742;
  bool llvm_cbe_tmp__2743;
  unsigned long long llvm_cbe_tmp__2744;
  unsigned long long llvm_cbe_tmp__2745;
  unsigned long long llvm_cbe_tmp__2746;
  unsigned long long llvm_cbe_tmp__2747;
  unsigned long long llvm_cbe_tmp__2748;
  unsigned long long llvm_cbe_tmp__2749;
  unsigned short llvm_cbe_tmp__2750;
  unsigned short llvm_cbe_tmp__2751;
  unsigned short llvm_cbe_tmp__2752;
  unsigned short llvm_cbe_tmp__2753;
  unsigned int llvm_cbe_tmp__2754;
  unsigned int llvm_cbe_tmp__2755;

  *(&llvm_cbe_tmp__2727) = llvm_cbe_this;
  llvm_cbe_tmp__2741 = *(&llvm_cbe_tmp__2727);
  *(&llvm_cbe_tmp__2728) = ((unsigned char )1);
  llvm_cbe_tmp__2742 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2741->field36)), (&llvm_cbe_tmp__2728)))&1);
  *(&llvm_cbe_tmp__2729) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2741->field39)), (&llvm_cbe_tmp__2729));
  *(&llvm_cbe_tmp__2730) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2741->field40)), (&llvm_cbe_tmp__2730));
  *(&llvm_cbe_tmp__2731) = 625u;
  _ZN15sc_signal_int325writeERKi(((&llvm_cbe_tmp__2741->field41)), (&llvm_cbe_tmp__2731));
  goto llvm_cbe_tmp__2756;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2756:
  _Z4waitv();
  llvm_cbe_tmp__2743 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2741->field36))))&1);
  if ((((llvm_cbe_tmp__2743 ^ 1)&1))) {
    goto llvm_cbe_tmp__2756;
  } else {
    goto llvm_cbe_tmp__2757;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2757:
  llvm_cbe_tmp__2744 = *((&GM.field9));
  *(&llvm_cbe_tmp__2732) = (((unsigned short )llvm_cbe_tmp__2744));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2741->field30)), (&llvm_cbe_tmp__2732));
  llvm_cbe_tmp__2745 = *((&GM.field14));
  *(&llvm_cbe_tmp__2733) = (((unsigned short )llvm_cbe_tmp__2745));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2741->field31)), (&llvm_cbe_tmp__2733));
  llvm_cbe_tmp__2746 = *((&GM.field13));
  *(&llvm_cbe_tmp__2734) = (((unsigned short )llvm_cbe_tmp__2746));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2741->field32)), (&llvm_cbe_tmp__2734));
  llvm_cbe_tmp__2747 = *((&GM.field10));
  *(&llvm_cbe_tmp__2735) = (((unsigned short )llvm_cbe_tmp__2747));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2741->field33)), (&llvm_cbe_tmp__2735));
  llvm_cbe_tmp__2748 = *((&GM.field12));
  *(&llvm_cbe_tmp__2736) = (((unsigned short )llvm_cbe_tmp__2748));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2741->field34)), (&llvm_cbe_tmp__2736));
  llvm_cbe_tmp__2749 = *((&GM.field11));
  *(&llvm_cbe_tmp__2737) = (((unsigned short )llvm_cbe_tmp__2749));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__2741->field35)), (&llvm_cbe_tmp__2737));
  llvm_cbe_tmp__2750 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2741->field31)));
  *(&llvm_cbe_nv) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2750));
  llvm_cbe_tmp__2751 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2741->field30)));
  *(&llvm_cbe_nh) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2751));
  llvm_cbe_tmp__2752 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2741->field32)));
  *(&llvm_cbe_nu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2752));
  llvm_cbe_tmp__2753 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2741->field33)));
  *(&llvm_cbe_nlp) = (((unsigned int )(unsigned short )llvm_cbe_tmp__2753));
  *(&llvm_cbe_current_loop) = 0u;
  *(&llvm_cbe_pingpong) = ((unsigned char )0);
  *(&upc) = 2u;
  llvm_cbe_tmp__2754 = *(&llvm_cbe_nh);
  llvm_cbe_tmp__2755 = *(&llvm_cbe_nv);
  _ZN3rbm26activateVisibleUnits_trainEtt(llvm_cbe_tmp__2741, (((unsigned short )llvm_cbe_tmp__2754)), (((unsigned short )llvm_cbe_tmp__2755)));
  return;
}


void _ZN15sc_signal_int325writeERKi(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2758;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__2759;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__2760;
  unsigned int *llvm_cbe_tmp__2761;
  unsigned int llvm_cbe_tmp__2762;

  *(&llvm_cbe_tmp__2758) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2759) = llvm_cbe_d;
  llvm_cbe_tmp__2760 = *(&llvm_cbe_tmp__2758);
  llvm_cbe_tmp__2761 = *(&llvm_cbe_tmp__2759);
  llvm_cbe_tmp__2762 = *llvm_cbe_tmp__2761;
  *((&llvm_cbe_tmp__2760->field0)) = llvm_cbe_tmp__2762;
  return;
}


float *_ZN11SysCArray2DIfLj501ELj101EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__2763;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2764;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__2765;
  unsigned int llvm_cbe_tmp__2766;
  float *llvm_cbe_tmp__2767;

  *(&llvm_cbe_tmp__2763) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2764) = llvm_cbe_Xidx;
  llvm_cbe_tmp__2765 = *(&llvm_cbe_tmp__2763);
  llvm_cbe_tmp__2766 = *(&llvm_cbe_tmp__2764);
  llvm_cbe_tmp__2767 = *((&llvm_cbe_tmp__2765->field0));
  return ((&llvm_cbe_tmp__2767[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2766) * ((unsigned int )101u)))))))]));
}


void _ZN3rbm25activateHiddenUnits_trainEbtt(struct l_struct_OC_rbm *llvm_cbe_this, bool llvm_cbe_pingpong, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2768;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2769;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2770;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2771;    /* Address-exposed local */
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
  struct l_struct_OC_rbm *llvm_cbe_tmp__2772;
  unsigned short llvm_cbe_tmp__2773;
  unsigned short llvm_cbe_tmp__2774;
  unsigned short llvm_cbe_tmp__2775;
  unsigned short llvm_cbe_tmp__2776;
  unsigned short llvm_cbe_tmp__2777;
  unsigned short llvm_cbe_tmp__2778;
  unsigned short llvm_cbe_tmp__2779;
  unsigned char llvm_cbe_tmp__2780;
  unsigned char *llvm_cbe_tmp__2781;
  unsigned char llvm_cbe_tmp__2782;
  unsigned char llvm_cbe_tmp__2783;
  unsigned short llvm_cbe_tmp__2784;
  unsigned short llvm_cbe_tmp__2785;
  float *llvm_cbe_tmp__2786;
  float llvm_cbe_tmp__2787;
  float llvm_cbe_tmp__2788;
  float llvm_cbe_tmp__2789;
  unsigned short llvm_cbe_tmp__2790;
  float llvm_cbe_tmp__2791;
  unsigned long long llvm_cbe_tmp__2792;
  unsigned short llvm_cbe_tmp__2793;
  float llvm_cbe_tmp__2794;
  float llvm_cbe_tmp__2795;
  float llvm_cbe_tmp__2796;
  float llvm_cbe_tmp__2797;
  unsigned char llvm_cbe_tmp__2798;
  unsigned char llvm_cbe_tmp__2799;
  unsigned short llvm_cbe_tmp__2800;
  unsigned char *llvm_cbe_tmp__2801;
  unsigned short llvm_cbe_tmp__2802;
  unsigned short llvm_cbe_tmp__2803;
  unsigned char *llvm_cbe_tmp__2804;

  *(&llvm_cbe_tmp__2768) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2769) = (((unsigned char )(bool )llvm_cbe_pingpong));
  *(&llvm_cbe_tmp__2770) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__2771) = llvm_cbe_nv;
  llvm_cbe_tmp__2772 = *(&llvm_cbe_tmp__2768);
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__2805;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2805:
  llvm_cbe_tmp__2773 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2773))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__2806;
  } else {
    goto llvm_cbe_tmp__2807;
  }

llvm_cbe_tmp__2808:
  llvm_cbe_tmp__2799 = *(&llvm_cbe_th);
  llvm_cbe_tmp__2800 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2801 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__2772->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__2800)));
  *llvm_cbe_tmp__2801 = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2799&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__2802 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2802) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2805;

llvm_cbe_tmp__2809:
  *(&llvm_cbe_th) = ((unsigned char )1);
  goto llvm_cbe_tmp__2808;

llvm_cbe_tmp__2810:
  llvm_cbe_tmp__2791 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__2792 = _Z8_c_16_15f(llvm_cbe_tmp__2791);
  llvm_cbe_tmp__2793 = _Z7sigmoidl(llvm_cbe_tmp__2792);
  llvm_cbe_tmp__2794 = _Z8_b_16_15l((((unsigned long long )(unsigned short )llvm_cbe_tmp__2793)));
  *(&llvm_cbe_prob) = llvm_cbe_tmp__2794;
  llvm_cbe_tmp__2795 = _ZN3rbm8rand_genEv(llvm_cbe_tmp__2772);
  *(&llvm_cbe_RAND) = llvm_cbe_tmp__2795;
  llvm_cbe_tmp__2796 = *(&llvm_cbe_RAND);
  llvm_cbe_tmp__2797 = *(&llvm_cbe_prob);
  *(&llvm_cbe_comp) = (((unsigned char )(bool )(llvm_fcmp_olt(llvm_cbe_tmp__2796, llvm_cbe_tmp__2797))));
  llvm_cbe_tmp__2798 = *(&llvm_cbe_comp);
  if ((((((bool )llvm_cbe_tmp__2798&1u))&1))) {
    goto llvm_cbe_tmp__2809;
  } else {
    goto llvm_cbe_tmp__2811;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__2812:
  llvm_cbe_tmp__2776 = *(&llvm_cbe_v);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2776))) < ((signed int )501u))) {
    goto llvm_cbe_tmp__2813;
  } else {
    goto llvm_cbe_tmp__2810;
  }

llvm_cbe_tmp__2814:
  llvm_cbe_tmp__2790 = *(&llvm_cbe_v);
  *(&llvm_cbe_v) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2790) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__2812;

llvm_cbe_tmp__2815:
  llvm_cbe_tmp__2784 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2785 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2786 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__2772->field23)), (((unsigned int )(unsigned short )llvm_cbe_tmp__2785)));
  llvm_cbe_tmp__2787 = *((&llvm_cbe_tmp__2786[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2784)))]));
  *(&llvm_cbe_tmp) = llvm_cbe_tmp__2787;
  llvm_cbe_tmp__2788 = *(&llvm_cbe_tmp);
  llvm_cbe_tmp__2789 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__2789 + llvm_cbe_tmp__2788)));
  _Z4waitv();
  goto llvm_cbe_tmp__2814;

llvm_cbe_tmp__2816:
  *(&per_v_pc) = 0u;
  *(&train_upc) = 0u;
  llvm_cbe_tmp__2779 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2780 = *(&llvm_cbe_tmp__2769);
  llvm_cbe_tmp__2781 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2772->field20)), ((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__2780&1u))&1)))) & 0u));
  llvm_cbe_tmp__2782 = *((&llvm_cbe_tmp__2781[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2779)))]));
  *(&llvm_cbe_current_data) = llvm_cbe_tmp__2782;
  _Z4waitv();
  llvm_cbe_tmp__2783 = *(&llvm_cbe_current_data);
  if (((((unsigned int )(unsigned char )llvm_cbe_tmp__2783)) == 1u)) {
    goto llvm_cbe_tmp__2815;
  } else {
    goto llvm_cbe_tmp__2814;
  }

llvm_cbe_tmp__2813:
  llvm_cbe_tmp__2777 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2778 = *(&llvm_cbe_tmp__2771);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2777)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2778))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__2810;
  } else {
    goto llvm_cbe_tmp__2816;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2817:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_v) = ((unsigned short )0);
  goto llvm_cbe_tmp__2812;

llvm_cbe_tmp__2806:
  llvm_cbe_tmp__2774 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2775 = *(&llvm_cbe_tmp__2770);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2774)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__2775)))) {
    goto llvm_cbe_tmp__2807;
  } else {
    goto llvm_cbe_tmp__2817;
  }

llvm_cbe_tmp__2811:
  *(&llvm_cbe_th) = ((unsigned char )0);
  goto llvm_cbe_tmp__2808;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__2807:
  llvm_cbe_tmp__2803 = *(&llvm_cbe_tmp__2770);
  llvm_cbe_tmp__2804 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__2772->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__2803)));
  *llvm_cbe_tmp__2804 = ((unsigned char )1);
  _Z4waitv();
  *(&per_v_pc) = 0u;
  *(&train_upc) = 1u;
  return;
}


unsigned char *_ZN11SysCArray1DIbLj128EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2818;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2819;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2820;
  unsigned int llvm_cbe_tmp__2821;
  unsigned char *llvm_cbe_tmp__2822;

  *(&llvm_cbe_tmp__2818) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2819) = llvm_cbe_idx;
  llvm_cbe_tmp__2820 = *(&llvm_cbe_tmp__2818);
  llvm_cbe_tmp__2821 = *(&llvm_cbe_tmp__2819);
  llvm_cbe_tmp__2822 = *((&llvm_cbe_tmp__2820->field0));
  return ((&llvm_cbe_tmp__2822[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__2821)))]));
}


unsigned char *_ZN11SysCArray2DIbLj501ELj101EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2823;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2824;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__2825;
  unsigned int llvm_cbe_tmp__2826;
  unsigned char *llvm_cbe_tmp__2827;

  *(&llvm_cbe_tmp__2823) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2824) = llvm_cbe_Xidx;
  llvm_cbe_tmp__2825 = *(&llvm_cbe_tmp__2823);
  llvm_cbe_tmp__2826 = *(&llvm_cbe_tmp__2824);
  llvm_cbe_tmp__2827 = *((&llvm_cbe_tmp__2825->field0));
  return ((&llvm_cbe_tmp__2827[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__2826) * ((unsigned int )101u)))))))]));
}


void _ZN3rbm26activateVisibleUnits_trainEtt(struct l_struct_OC_rbm *llvm_cbe_this, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__2828;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2829;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__2830;    /* Address-exposed local */
  unsigned short llvm_cbe_v;    /* Address-exposed local */
  unsigned short llvm_cbe_h;    /* Address-exposed local */
  float llvm_cbe_sum;    /* Address-exposed local */
  float llvm_cbe_max;    /* Address-exposed local */
  float llvm_cbe_probs;    /* Address-exposed local */
  float llvm_cbe_RAND;    /* Address-exposed local */
  struct l_unnamed21 llvm_cbe_pow2;    /* Address-exposed local */
  float llvm_cbe_sumOfpow2;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp;    /* Address-exposed local */
  float llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned short llvm_cbe_j;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2831;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2832;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2833;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2834;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2835;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2836;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2837;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2838;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2839;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2840;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2841;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2842;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__2843;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__2844;    /* Address-exposed local */
  float llvm_cbe_ve_current;    /* Address-exposed local */
  float llvm_cbe_dp;    /* Address-exposed local */
  float llvm_cbe_dp1;    /* Address-exposed local */
  unsigned char llvm_cbe_tmpb;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__2845;
  bool llvm_cbe_tmp__2846;
  bool llvm_cbe_tmp__2847;
  bool llvm_cbe_tmp__2848;
  bool llvm_cbe_tmp__2849;
  unsigned char llvm_cbe_tmp__2850;
  unsigned int llvm_cbe_tmp__2851;
  unsigned int llvm_cbe_tmp__2852;
  unsigned int llvm_cbe_tmp__2853;
  unsigned int llvm_cbe_tmp__2854;
  unsigned int llvm_cbe_tmp__2855;
  unsigned int llvm_cbe_tmp__2856;
  unsigned char llvm_cbe_tmp__2857;
  unsigned long long llvm_cbe_tmp__2858;
  unsigned long long llvm_cbe_tmp__2859;
  unsigned long long llvm_cbe_tmp__2860;
  unsigned long long llvm_cbe_tmp__2861;
  unsigned long long llvm_cbe_tmp__2862;
  unsigned char llvm_cbe_tmp__2863;
  unsigned int llvm_cbe_tmp__2864;
  unsigned char llvm_cbe_tmp__2865;
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
  unsigned char *llvm_cbe_tmp__2877;
  unsigned char *llvm_cbe_tmp__2878;
  unsigned char *llvm_cbe_tmp__2879;
  unsigned char *llvm_cbe_tmp__2880;
  float *llvm_cbe_tmp__2881;
  unsigned char *llvm_cbe_tmp__2882;
  unsigned char *llvm_cbe_tmp__2883;
  unsigned char *llvm_cbe_tmp__2884;
  unsigned char *llvm_cbe_tmp__2885;
  unsigned char *llvm_cbe_tmp__2886;
  float *llvm_cbe_tmp__2887;
  unsigned short *llvm_cbe_tmp__2888;
  unsigned int *llvm_cbe_tmp__2889;
  unsigned char *llvm_cbe_tmp__2890;
  unsigned char *llvm_cbe_tmp__2891;
  unsigned short llvm_cbe_tmp__2892;
  unsigned short llvm_cbe_tmp__2893;
  unsigned short llvm_cbe_tmp__2894;
  unsigned short llvm_cbe_tmp__2895;
  unsigned short llvm_cbe_tmp__2896;
  unsigned char *llvm_cbe_tmp__2897;
  unsigned char llvm_cbe_tmp__2898;
  unsigned short llvm_cbe_tmp__2899;
  unsigned short llvm_cbe_tmp__2900;
  unsigned short llvm_cbe_tmp__2901;
  float *llvm_cbe_tmp__2902;
  float llvm_cbe_tmp__2903;
  unsigned char llvm_cbe_tmp__2904;
  unsigned short llvm_cbe_tmp__2905;
  unsigned short llvm_cbe_tmp__2906;
  unsigned short llvm_cbe_tmp__2907;
  unsigned char llvm_cbe_tmp__2908;
  unsigned int llvm_cbe_tmp__2909;
  unsigned int llvm_cbe_tmp__2910;
  unsigned int llvm_cbe_tmp__2911;
  unsigned int llvm_cbe_tmp__2912;
  unsigned int llvm_cbe_tmp__2913;
  unsigned int llvm_cbe_tmp__2914;
  unsigned char llvm_cbe_tmp__2915;
  unsigned char llvm_cbe_tmp__2916;
  unsigned int llvm_cbe_tmp__2917;
  unsigned char llvm_cbe_tmp__2918;
  bool llvm_cbe_tmp__2919;
  unsigned long long llvm_cbe_tmp__2920;
  bool llvm_cbe_tmp__2921;
  unsigned long long llvm_cbe_tmp__2922;
  unsigned short llvm_cbe_tmp__2923;
  unsigned long long llvm_cbe_tmp__2924;
  unsigned short llvm_cbe_tmp__2925;
  unsigned long long llvm_cbe_tmp__2926;
  unsigned short llvm_cbe_tmp__2927;
  unsigned long long llvm_cbe_tmp__2928;
  unsigned short llvm_cbe_tmp__2929;
  unsigned long long llvm_cbe_tmp__2930;
  unsigned short llvm_cbe_tmp__2931;
  unsigned long long llvm_cbe_tmp__2932;
  unsigned short llvm_cbe_tmp__2933;
  unsigned long long llvm_cbe_tmp__2934;
  unsigned int llvm_cbe_tmp__2935;
  unsigned long long llvm_cbe_tmp__2936;
  unsigned int llvm_cbe_tmp__2937;
  unsigned long long llvm_cbe_tmp__2938;
  bool llvm_cbe_tmp__2939;
  unsigned long long llvm_cbe_tmp__2940;
  bool llvm_cbe_tmp__2941;
  unsigned long long llvm_cbe_tmp__2942;
  unsigned int llvm_cbe_tmp__2943;
  unsigned long long llvm_cbe_tmp__2944;
  unsigned int llvm_cbe_tmp__2945;
  unsigned long long llvm_cbe_tmp__2946;
  unsigned int llvm_cbe_tmp__2947;
  unsigned long long llvm_cbe_tmp__2948;
  unsigned int llvm_cbe_tmp__2949;
  unsigned long long llvm_cbe_tmp__2950;
  bool llvm_cbe_tmp__2951;
  unsigned long long llvm_cbe_tmp__2952;
  float llvm_cbe_tmp__2953;
  unsigned long long llvm_cbe_tmp__2954;
  float llvm_cbe_tmp__2955;
  unsigned long long llvm_cbe_tmp__2956;
  float llvm_cbe_tmp__2957;
  unsigned long long llvm_cbe_tmp__2958;
  unsigned short llvm_cbe_tmp__2959;
  unsigned long long llvm_cbe_tmp__2960;
  unsigned int llvm_cbe_tmp__2961;
  unsigned long long llvm_cbe_tmp__2962;
  unsigned int llvm_cbe_tmp__2963;
  unsigned long long llvm_cbe_tmp__2964;
  unsigned short llvm_cbe_tmp__2965;
  unsigned long long llvm_cbe_tmp__2966;
  unsigned short llvm_cbe_tmp__2967;
  unsigned long long llvm_cbe_tmp__2968;
  unsigned char *llvm_cbe_tmp__2969;
  unsigned char *llvm_cbe_tmp__2970;
  bool llvm_cbe_tmp__2971;
  unsigned char *llvm_cbe_tmp__2972;
  unsigned char *llvm_cbe_tmp__2973;
  bool llvm_cbe_tmp__2974;
  unsigned char *llvm_cbe_tmp__2975;
  unsigned char *llvm_cbe_tmp__2976;
  bool llvm_cbe_tmp__2977;
  unsigned char *llvm_cbe_tmp__2978;
  unsigned char *llvm_cbe_tmp__2979;
  bool llvm_cbe_tmp__2980;
  unsigned char *llvm_cbe_tmp__2981;
  unsigned char *llvm_cbe_tmp__2982;
  bool llvm_cbe_tmp__2983;
  unsigned short llvm_cbe_tmp__2984;
  unsigned short llvm_cbe_tmp__2985;
  unsigned short llvm_cbe_tmp__2986;
  unsigned short llvm_cbe_tmp__2987;
  float llvm_cbe_tmp__2988;
  float llvm_cbe_tmp__2989;
  unsigned short llvm_cbe_tmp__2990;
  float llvm_cbe_tmp__2991;
  unsigned short llvm_cbe_tmp__2992;
  float *llvm_cbe_tmp__2993;
  float llvm_cbe_tmp__2994;
  float llvm_cbe_tmp__2995;
  float llvm_cbe_tmp__2996;
  unsigned short llvm_cbe_tmp__2997;
  unsigned short llvm_cbe_tmp__2998;
  unsigned char llvm_cbe_tmp__2999;
  unsigned int llvm_cbe_tmp__3000;
  unsigned int llvm_cbe_tmp__3001;
  unsigned int llvm_cbe_tmp__3002;
  unsigned int llvm_cbe_tmp__3003;
  unsigned int llvm_cbe_tmp__3004;
  unsigned int llvm_cbe_tmp__3005;
  unsigned char llvm_cbe_tmp__3006;
  unsigned char llvm_cbe_tmp__3007;
  unsigned int llvm_cbe_tmp__3008;
  unsigned char llvm_cbe_tmp__3009;
  bool llvm_cbe_tmp__3010;
  unsigned long long llvm_cbe_tmp__3011;
  bool llvm_cbe_tmp__3012;
  unsigned long long llvm_cbe_tmp__3013;
  unsigned short llvm_cbe_tmp__3014;
  unsigned long long llvm_cbe_tmp__3015;
  unsigned short llvm_cbe_tmp__3016;
  unsigned long long llvm_cbe_tmp__3017;
  unsigned short llvm_cbe_tmp__3018;
  unsigned long long llvm_cbe_tmp__3019;
  unsigned short llvm_cbe_tmp__3020;
  unsigned long long llvm_cbe_tmp__3021;
  unsigned short llvm_cbe_tmp__3022;
  unsigned long long llvm_cbe_tmp__3023;
  unsigned short llvm_cbe_tmp__3024;
  unsigned long long llvm_cbe_tmp__3025;
  unsigned int llvm_cbe_tmp__3026;
  unsigned long long llvm_cbe_tmp__3027;
  unsigned int llvm_cbe_tmp__3028;
  unsigned long long llvm_cbe_tmp__3029;
  bool llvm_cbe_tmp__3030;
  unsigned long long llvm_cbe_tmp__3031;
  bool llvm_cbe_tmp__3032;
  unsigned long long llvm_cbe_tmp__3033;
  unsigned int llvm_cbe_tmp__3034;
  unsigned long long llvm_cbe_tmp__3035;
  unsigned int llvm_cbe_tmp__3036;
  unsigned long long llvm_cbe_tmp__3037;
  unsigned int llvm_cbe_tmp__3038;
  unsigned long long llvm_cbe_tmp__3039;
  unsigned int llvm_cbe_tmp__3040;
  unsigned long long llvm_cbe_tmp__3041;
  bool llvm_cbe_tmp__3042;
  unsigned long long llvm_cbe_tmp__3043;
  float llvm_cbe_tmp__3044;
  unsigned long long llvm_cbe_tmp__3045;
  float llvm_cbe_tmp__3046;
  unsigned long long llvm_cbe_tmp__3047;
  float llvm_cbe_tmp__3048;
  unsigned long long llvm_cbe_tmp__3049;
  unsigned short llvm_cbe_tmp__3050;
  unsigned long long llvm_cbe_tmp__3051;
  unsigned int llvm_cbe_tmp__3052;
  unsigned long long llvm_cbe_tmp__3053;
  unsigned int llvm_cbe_tmp__3054;
  unsigned long long llvm_cbe_tmp__3055;
  unsigned short llvm_cbe_tmp__3056;
  unsigned long long llvm_cbe_tmp__3057;
  unsigned short llvm_cbe_tmp__3058;
  unsigned long long llvm_cbe_tmp__3059;
  unsigned char *llvm_cbe_tmp__3060;
  unsigned char *llvm_cbe_tmp__3061;
  bool llvm_cbe_tmp__3062;
  unsigned char *llvm_cbe_tmp__3063;
  unsigned char *llvm_cbe_tmp__3064;
  bool llvm_cbe_tmp__3065;
  unsigned char *llvm_cbe_tmp__3066;
  unsigned char *llvm_cbe_tmp__3067;
  bool llvm_cbe_tmp__3068;
  unsigned char *llvm_cbe_tmp__3069;
  unsigned char *llvm_cbe_tmp__3070;
  bool llvm_cbe_tmp__3071;
  unsigned char *llvm_cbe_tmp__3072;
  unsigned char *llvm_cbe_tmp__3073;
  bool llvm_cbe_tmp__3074;

  *(&llvm_cbe_tmp__2828) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2829) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__2830) = llvm_cbe_nv;
  llvm_cbe_tmp__2845 = *(&llvm_cbe_tmp__2828);
  *(&llvm_cbe_tmp__2831) = ((unsigned char )1);
  llvm_cbe_tmp__2846 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2845->field36)), (&llvm_cbe_tmp__2831)))&1);
  *(&llvm_cbe_tmp__2832) = ((unsigned char )1);
  llvm_cbe_tmp__2847 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2845->field37)), (&llvm_cbe_tmp__2832)))&1);
  *((&GM.field15)) = 0ull;
  *(&llvm_cbe_tmp__2833) = ((unsigned char )0);
  llvm_cbe_tmp__2848 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2845->field12)), (&llvm_cbe_tmp__2833)))&1);
  *((&GM.field29)) = 1ull;
  *(&rst_inp) = ((unsigned char )0);
  *((&GM.field31)) = 2ull;
  *(&llvm_cbe_tmp__2834) = ((unsigned char )0);
  llvm_cbe_tmp__2849 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__2845->field38)), (&llvm_cbe_tmp__2834)))&1);
  *(&upc) = 2u;
  llvm_cbe_tmp__2850 = *(&conf_done_inp);
  *((&((&llvm_cbe_tmp__2845->field13))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2850&1u))&1))));
  llvm_cbe_tmp__2851 = *(&conf_num_hidden_inp);
  *((&((&llvm_cbe_tmp__2845->field14))->field0)) = llvm_cbe_tmp__2851;
  llvm_cbe_tmp__2852 = *(&conf_num_visible_inp);
  *((&((&llvm_cbe_tmp__2845->field15))->field0)) = llvm_cbe_tmp__2852;
  llvm_cbe_tmp__2853 = *(&conf_num_users_inp);
  *((&((&llvm_cbe_tmp__2845->field16))->field0)) = llvm_cbe_tmp__2853;
  llvm_cbe_tmp__2854 = *(&conf_num_loops_inp);
  *((&((&llvm_cbe_tmp__2845->field17))->field0)) = llvm_cbe_tmp__2854;
  llvm_cbe_tmp__2855 = *(&conf_num_testusers_inp);
  *((&((&llvm_cbe_tmp__2845->field18))->field0)) = llvm_cbe_tmp__2855;
  llvm_cbe_tmp__2856 = *(&conf_num_movies_inp);
  *((&((&llvm_cbe_tmp__2845->field19))->field0)) = llvm_cbe_tmp__2856;
  llvm_cbe_tmp__2857 = *(&rst_inp);
  *((&((&llvm_cbe_tmp__2845->field1))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2857&1u))&1))));
  llvm_cbe_tmp__2858 = *((&GM.field6));
  *(&llvm_cbe_tmp__2835) = (((unsigned char )(bool )(llvm_cbe_tmp__2858 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2845->field36)), (&llvm_cbe_tmp__2835));
  llvm_cbe_tmp__2859 = *((&GM.field2));
  *(&llvm_cbe_tmp__2836) = (((unsigned char )(bool )(llvm_cbe_tmp__2859 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2845->field12)), (&llvm_cbe_tmp__2836));
  llvm_cbe_tmp__2860 = *((&GM.field21));
  *(&llvm_cbe_tmp__2837) = (((unsigned int )llvm_cbe_tmp__2860));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2845->field2)), (&llvm_cbe_tmp__2837));
  llvm_cbe_tmp__2861 = *((&GM.field22));
  *(&llvm_cbe_tmp__2838) = (((unsigned int )llvm_cbe_tmp__2861));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2845->field3)), (&llvm_cbe_tmp__2838));
  llvm_cbe_tmp__2862 = *((&GM.field23));
  *(&llvm_cbe_tmp__2839) = (((unsigned char )(bool )(llvm_cbe_tmp__2862 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2845->field4)), (&llvm_cbe_tmp__2839));
  llvm_cbe_tmp__2863 = *(&rd_grant_inp);
  *((&((&llvm_cbe_tmp__2845->field5))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2863&1u))&1))));
  llvm_cbe_tmp__2864 = *(&data_in_inp);
  *((&((&llvm_cbe_tmp__2845->field6))->field0)) = llvm_cbe_tmp__2864;
  llvm_cbe_tmp__2865 = *(&wr_grant_inp);
  *((&((&llvm_cbe_tmp__2845->field10))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2865&1u))&1))));
  llvm_cbe_tmp__2866 = *((&GM.field37));
  *(&llvm_cbe_tmp__2840) = (((unsigned char )(bool )(llvm_cbe_tmp__2866 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2845->field9)), (&llvm_cbe_tmp__2840));
  llvm_cbe_tmp__2867 = *((&GM.field35));
  *(&llvm_cbe_tmp__2841) = (((unsigned int )llvm_cbe_tmp__2867));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2845->field7)), (&llvm_cbe_tmp__2841));
  llvm_cbe_tmp__2868 = *((&GM.field36));
  *(&llvm_cbe_tmp__2842) = (((unsigned int )llvm_cbe_tmp__2868));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2845->field8)), (&llvm_cbe_tmp__2842));
  llvm_cbe_tmp__2869 = *((&GM.field1));
  *(&llvm_cbe_tmp__2843) = (((unsigned int )llvm_cbe_tmp__2869));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__2845->field11)), (&llvm_cbe_tmp__2843));
  llvm_cbe_tmp__2870 = *((&GM.field26));
  *(&llvm_cbe_tmp__2844) = (((unsigned char )(bool )(llvm_cbe_tmp__2870 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__2845->field37)), (&llvm_cbe_tmp__2844));
  llvm_cbe_tmp__2871 = *((&GM.field28));
  *(&llvm_cbe_sum) = (((float )((((double )(signed long long )(llvm_cbe_tmp__2871 & 65535ull))) / 0x1p+1)));
  llvm_cbe_tmp__2872 = *((&GM.field27));
  *(&llvm_cbe_max) = (((float )((((double )(signed long long )(llvm_cbe_tmp__2872 & 65535ull))) / 0x1p+1)));
  llvm_cbe_tmp__2873 = *((&GM.field24));
  *(&llvm_cbe_sumOfpow2) = (((float )((((double )(unsigned long long )llvm_cbe_tmp__2873)) / 0x1p+0)));
  llvm_cbe_tmp__2874 = *((&GM.field7));
  *(&llvm_cbe_j) = (((unsigned short )llvm_cbe_tmp__2874));
  llvm_cbe_tmp__2875 = *((&GM.field30));
  *(&llvm_cbe_v) = (((unsigned short )llvm_cbe_tmp__2875));
  llvm_cbe_tmp__2876 = *((&GM.field25));
  *(&llvm_cbe_h) = (((unsigned short )llvm_cbe_tmp__2876));
  llvm_cbe_tmp__2877 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2845->field20)), 0u);
  llvm_cbe_tmp__2878 = *((&GM.field0.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2877, llvm_cbe_tmp__2878);
  llvm_cbe_tmp__2879 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2845->field28)), 0u);
  llvm_cbe_tmp__2880 = *((&GM.field19.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2879, llvm_cbe_tmp__2880);
  llvm_cbe_tmp__2881 = *((&((&llvm_cbe_tmp__2845->field23))->field0));
  llvm_cbe_tmp__2882 = *((&GM.field3.field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__2881)), llvm_cbe_tmp__2882);
  llvm_cbe_tmp__2883 = *((&((&llvm_cbe_tmp__2845->field22))->field0));
  llvm_cbe_tmp__2884 = *((&GM.field4.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2883, llvm_cbe_tmp__2884);
  llvm_cbe_tmp__2885 = *((&((&llvm_cbe_tmp__2845->field21))->field0));
  llvm_cbe_tmp__2886 = *((&GM.field33.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2885, llvm_cbe_tmp__2886);
  llvm_cbe_tmp__2887 = *((&((&llvm_cbe_tmp__2845->field26))->field0));
  llvm_cbe_tmp__2888 = *((&GM.field32.field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__2887)), (((unsigned char *)llvm_cbe_tmp__2888)));
  llvm_cbe_tmp__2889 = *((&GM.field17.field0));
  __CPROVER_array_copy((((unsigned char *)((&llvm_cbe_pow2.array[((signed int )0u)])))), (((unsigned char *)llvm_cbe_tmp__2889)));
  llvm_cbe_tmp__2890 = *((&((&llvm_cbe_tmp__2845->field24))->field0));
  llvm_cbe_tmp__2891 = *((&GM.field16.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__2890, llvm_cbe_tmp__2891);
  llvm_cbe_tmp__2892 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2893 = *(&llvm_cbe_tmp__2829);
  __CPROVER_assume((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2892))) <= ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2893)))));
  llvm_cbe_tmp__2894 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2895 = *(&llvm_cbe_tmp__2830);
  __CPROVER_assume((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2894))) < ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2895)))));
  llvm_cbe_tmp__2896 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2897 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__2845->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__2896)));
  llvm_cbe_tmp__2898 = *llvm_cbe_tmp__2897;
  *(&llvm_cbe_tmp2) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__2898&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__2899 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2900 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2901 = *(&llvm_cbe_j);
  llvm_cbe_tmp__2902 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__2845->field23)), (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2900))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2901)))))));
  llvm_cbe_tmp__2903 = *((&llvm_cbe_tmp__2902[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__2899)))]));
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__2903;
  _Z4waitv();
  llvm_cbe_tmp__2904 = *(&llvm_cbe_tmp2);
  if ((((((bool )llvm_cbe_tmp__2904&1u))&1))) {
    goto llvm_cbe_tmp__3075;
  } else {
    goto llvm_cbe_tmp__3076;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3077:
  llvm_cbe_tmp__2905 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2905))) < ((signed int )101u))) {
    goto llvm_cbe_tmp__3078;
  } else {
    goto llvm_cbe_tmp__3079;
  }

llvm_cbe_tmp__3080:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__3077;

llvm_cbe_tmp__3081:
  llvm_cbe_tmp__2997 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2997) + ((unsigned short )((unsigned short )1)))))));
  llvm_cbe_tmp__2998 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2998))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3080;
  } else {
    goto llvm_cbe_tmp__3082;
  }

llvm_cbe_tmp__3083:
  llvm_cbe_tmp__2996 = *(&llvm_cbe_sum);
  *(&llvm_cbe_max) = llvm_cbe_tmp__2996;
  goto llvm_cbe_tmp__3081;

llvm_cbe_tmp__3079:
  llvm_cbe_tmp__2991 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__2992 = *(&llvm_cbe_j);
  llvm_cbe_tmp__2993 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__2845->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__2992)));
  *llvm_cbe_tmp__2993 = llvm_cbe_tmp__2991;
  _Z4waitv();
  llvm_cbe_tmp__2994 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__2995 = *(&llvm_cbe_max);
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__2994, llvm_cbe_tmp__2995))) {
    goto llvm_cbe_tmp__3083;
  } else {
    goto llvm_cbe_tmp__3081;
  }

llvm_cbe_tmp__3078:
  llvm_cbe_tmp__2906 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2907 = *(&llvm_cbe_tmp__2829);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__2906)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2907))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__3079;
  } else {
    goto llvm_cbe_tmp__3084;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3084:
  llvm_cbe_tmp__2908 = *(&conf_done_inp);
  llvm_cbe_tmp__2909 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__2910 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__2911 = *(&conf_num_users_inp);
  llvm_cbe_tmp__2912 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__2913 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__2914 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__2915 = *(&rst_inp);
  llvm_cbe_tmp__2916 = *(&rd_grant_inp);
  llvm_cbe_tmp__2917 = *(&data_in_inp);
  llvm_cbe_tmp__2918 = *(&wr_grant_inp);
  _ZN11model_train6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2908&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2909)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2910)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2911)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2912)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2913)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2914)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2915&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2916&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__2917)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2918&1u))&1)))));
  llvm_cbe_tmp__2919 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field36))))&1);
  llvm_cbe_tmp__2920 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2919)) == llvm_cbe_tmp__2920), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__2921 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field12))))&1);
  llvm_cbe_tmp__2922 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2921)) == llvm_cbe_tmp__2922), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__2923 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field30)));
  llvm_cbe_tmp__2924 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2923)) == llvm_cbe_tmp__2924), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__2925 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field31)));
  llvm_cbe_tmp__2926 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2925)) == llvm_cbe_tmp__2926), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__2927 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field32)));
  llvm_cbe_tmp__2928 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2927)) == llvm_cbe_tmp__2928), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__2929 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field33)));
  llvm_cbe_tmp__2930 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2929)) == llvm_cbe_tmp__2930), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__2931 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field34)));
  llvm_cbe_tmp__2932 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2931)) == llvm_cbe_tmp__2932), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__2933 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field35)));
  llvm_cbe_tmp__2934 = *((&GM.field11));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2933)) == llvm_cbe_tmp__2934), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__2935 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field2)));
  llvm_cbe_tmp__2936 = *((&GM.field21));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2935)) == llvm_cbe_tmp__2936), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__2937 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field3)));
  llvm_cbe_tmp__2938 = *((&GM.field22));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2937)) == llvm_cbe_tmp__2938), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__2939 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field4))))&1);
  llvm_cbe_tmp__2940 = *((&GM.field23));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2939)) == llvm_cbe_tmp__2940), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__2941 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field9))))&1);
  llvm_cbe_tmp__2942 = *((&GM.field37));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2941)) == llvm_cbe_tmp__2942), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__2943 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field7)));
  llvm_cbe_tmp__2944 = *((&GM.field35));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2943)) == llvm_cbe_tmp__2944), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__2945 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field8)));
  llvm_cbe_tmp__2946 = *((&GM.field36));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2945)) == llvm_cbe_tmp__2946), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__2947 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field11)));
  llvm_cbe_tmp__2948 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2947)) == llvm_cbe_tmp__2948), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__2949 = *(&upc);
  llvm_cbe_tmp__2950 = *((&GM.field31));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2949)) == llvm_cbe_tmp__2950), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__2951 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field37))))&1);
  llvm_cbe_tmp__2952 = *((&GM.field26));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__2951)) == llvm_cbe_tmp__2952), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__2953 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__2954 = *((&GM.field28));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__2953)), ((((double )(signed long long )(llvm_cbe_tmp__2954 & 65535ull))) / 0x1p+1))), ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__2955 = *(&llvm_cbe_max);
  llvm_cbe_tmp__2956 = *((&GM.field27));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__2955)), ((((double )(signed long long )(llvm_cbe_tmp__2956 & 65535ull))) / 0x1p+1))), ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__2957 = *(&llvm_cbe_sumOfpow2);
  llvm_cbe_tmp__2958 = *((&GM.field24));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__2957)), ((((double )(unsigned long long )llvm_cbe_tmp__2958)) / 0x1p+0))), ((&_OC_str20.array[((signed int )0u)])));
  llvm_cbe_tmp__2959 = *(&llvm_cbe_j);
  llvm_cbe_tmp__2960 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2959)) == llvm_cbe_tmp__2960), ((&_OC_str21.array[((signed int )0u)])));
  llvm_cbe_tmp__2961 = *(&per_v_pc);
  llvm_cbe_tmp__2962 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2961)) == llvm_cbe_tmp__2962), ((&_OC_str22.array[((signed int )0u)])));
  llvm_cbe_tmp__2963 = *(&train_upc);
  llvm_cbe_tmp__2964 = *((&GM.field29));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__2963)) == llvm_cbe_tmp__2964), ((&_OC_str23.array[((signed int )0u)])));
  llvm_cbe_tmp__2965 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2966 = *((&GM.field30));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2965)) == llvm_cbe_tmp__2966), ((&_OC_str24.array[((signed int )0u)])));
  llvm_cbe_tmp__2967 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2968 = *((&GM.field25));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__2967)) == llvm_cbe_tmp__2968), ((&_OC_str25.array[((signed int )0u)])));
  llvm_cbe_tmp__2969 = *((&GM.field0.field0));
  llvm_cbe_tmp__2970 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2845->field20)), 0u);
  llvm_cbe_tmp__2971 = ((__CPROVER_array_equal(llvm_cbe_tmp__2969, llvm_cbe_tmp__2970))&1);
  __CPROVER_assert(llvm_cbe_tmp__2971, ((&_OC_str26.array[((signed int )0u)])));
  llvm_cbe_tmp__2972 = *((&GM.field19.field0));
  llvm_cbe_tmp__2973 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2845->field28)), 0u);
  llvm_cbe_tmp__2974 = ((__CPROVER_array_equal(llvm_cbe_tmp__2972, llvm_cbe_tmp__2973))&1);
  __CPROVER_assert(llvm_cbe_tmp__2974, ((&_OC_str27.array[((signed int )0u)])));
  llvm_cbe_tmp__2975 = *((&GM.field4.field0));
  llvm_cbe_tmp__2976 = *((&((&llvm_cbe_tmp__2845->field22))->field0));
  llvm_cbe_tmp__2977 = ((__CPROVER_array_equal(llvm_cbe_tmp__2975, llvm_cbe_tmp__2976))&1);
  __CPROVER_assert(llvm_cbe_tmp__2977, ((&_OC_str28.array[((signed int )0u)])));
  llvm_cbe_tmp__2978 = *((&GM.field33.field0));
  llvm_cbe_tmp__2979 = *((&((&llvm_cbe_tmp__2845->field21))->field0));
  llvm_cbe_tmp__2980 = ((__CPROVER_array_equal(llvm_cbe_tmp__2978, llvm_cbe_tmp__2979))&1);
  __CPROVER_assert(llvm_cbe_tmp__2980, ((&_OC_str29.array[((signed int )0u)])));
  llvm_cbe_tmp__2981 = *((&GM.field16.field0));
  llvm_cbe_tmp__2982 = *((&((&llvm_cbe_tmp__2845->field24))->field0));
  llvm_cbe_tmp__2983 = ((__CPROVER_array_equal(llvm_cbe_tmp__2981, llvm_cbe_tmp__2982))&1);
  __CPROVER_assert(llvm_cbe_tmp__2983, ((&_OC_str30.array[((signed int )0u)])));
  llvm_cbe_tmp__2984 = *(&llvm_cbe_h);
  llvm_cbe_tmp__2985 = *(&llvm_cbe_tmp__2829);
  __CPROVER_assert((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2984))) <= ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2985)))), ((&_OC_str31.array[((signed int )0u)])));
  llvm_cbe_tmp__2986 = *(&llvm_cbe_v);
  llvm_cbe_tmp__2987 = *(&llvm_cbe_tmp__2830);
  __CPROVER_assert((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2986))) < ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__2987)))), ((&_OC_str31.array[((signed int )0u)])));
  goto llvm_cbe_tmp__3085;

llvm_cbe_tmp__3075:
  llvm_cbe_tmp__2988 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__2989 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__2989 + llvm_cbe_tmp__2988)));
  goto llvm_cbe_tmp__3076;

llvm_cbe_tmp__3076:
  _Z4waitv();
  llvm_cbe_tmp__2990 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__2990) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3077;

llvm_cbe_tmp__3082:
  *(&per_v_pc) = 1u;
  *(&train_upc) = 1u;
  llvm_cbe_tmp__2999 = *(&conf_done_inp);
  llvm_cbe_tmp__3000 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__3001 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__3002 = *(&conf_num_users_inp);
  llvm_cbe_tmp__3003 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__3004 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__3005 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__3006 = *(&rst_inp);
  llvm_cbe_tmp__3007 = *(&rd_grant_inp);
  llvm_cbe_tmp__3008 = *(&data_in_inp);
  llvm_cbe_tmp__3009 = *(&wr_grant_inp);
  _ZN11model_train6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__2999&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3000)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3001)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3002)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3003)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3004)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3005)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3006&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3007&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__3008)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__3009&1u))&1)))));
  llvm_cbe_tmp__3010 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field36))))&1);
  llvm_cbe_tmp__3011 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3010)) == llvm_cbe_tmp__3011), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__3012 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field12))))&1);
  llvm_cbe_tmp__3013 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3012)) == llvm_cbe_tmp__3013), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__3014 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field30)));
  llvm_cbe_tmp__3015 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3014)) == llvm_cbe_tmp__3015), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__3016 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field31)));
  llvm_cbe_tmp__3017 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3016)) == llvm_cbe_tmp__3017), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__3018 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field32)));
  llvm_cbe_tmp__3019 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3018)) == llvm_cbe_tmp__3019), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__3020 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field33)));
  llvm_cbe_tmp__3021 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3020)) == llvm_cbe_tmp__3021), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__3022 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field34)));
  llvm_cbe_tmp__3023 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3022)) == llvm_cbe_tmp__3023), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__3024 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__2845->field35)));
  llvm_cbe_tmp__3025 = *((&GM.field11));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3024)) == llvm_cbe_tmp__3025), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__3026 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field2)));
  llvm_cbe_tmp__3027 = *((&GM.field21));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3026)) == llvm_cbe_tmp__3027), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__3028 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field3)));
  llvm_cbe_tmp__3029 = *((&GM.field22));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3028)) == llvm_cbe_tmp__3029), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__3030 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field4))))&1);
  llvm_cbe_tmp__3031 = *((&GM.field23));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3030)) == llvm_cbe_tmp__3031), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__3032 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field9))))&1);
  llvm_cbe_tmp__3033 = *((&GM.field37));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3032)) == llvm_cbe_tmp__3033), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__3034 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field7)));
  llvm_cbe_tmp__3035 = *((&GM.field35));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3034)) == llvm_cbe_tmp__3035), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__3036 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field8)));
  llvm_cbe_tmp__3037 = *((&GM.field36));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3036)) == llvm_cbe_tmp__3037), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__3038 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__2845->field11)));
  llvm_cbe_tmp__3039 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3038)) == llvm_cbe_tmp__3039), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__3040 = *(&upc);
  llvm_cbe_tmp__3041 = *((&GM.field31));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3040)) == llvm_cbe_tmp__3041), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__3042 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__2845->field37))))&1);
  llvm_cbe_tmp__3043 = *((&GM.field26));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__3042)) == llvm_cbe_tmp__3043), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__3044 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3045 = *((&GM.field28));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3044)), ((((double )(signed long long )(llvm_cbe_tmp__3045 & 65535ull))) / 0x1p+1))), ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__3046 = *(&llvm_cbe_max);
  llvm_cbe_tmp__3047 = *((&GM.field27));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3046)), ((((double )(signed long long )(llvm_cbe_tmp__3047 & 65535ull))) / 0x1p+1))), ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__3048 = *(&llvm_cbe_sumOfpow2);
  llvm_cbe_tmp__3049 = *((&GM.field24));
  __CPROVER_assert((llvm_fcmp_oeq((((double )llvm_cbe_tmp__3048)), ((((double )(unsigned long long )llvm_cbe_tmp__3049)) / 0x1p+0))), ((&_OC_str20.array[((signed int )0u)])));
  llvm_cbe_tmp__3050 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3051 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3050)) == llvm_cbe_tmp__3051), ((&_OC_str21.array[((signed int )0u)])));
  llvm_cbe_tmp__3052 = *(&per_v_pc);
  llvm_cbe_tmp__3053 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3052)) == llvm_cbe_tmp__3053), ((&_OC_str22.array[((signed int )0u)])));
  llvm_cbe_tmp__3054 = *(&train_upc);
  llvm_cbe_tmp__3055 = *((&GM.field29));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__3054)) == llvm_cbe_tmp__3055), ((&_OC_str23.array[((signed int )0u)])));
  llvm_cbe_tmp__3056 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3057 = *((&GM.field30));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3056)) == llvm_cbe_tmp__3057), ((&_OC_str24.array[((signed int )0u)])));
  llvm_cbe_tmp__3058 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3059 = *((&GM.field25));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__3058)) == llvm_cbe_tmp__3059), ((&_OC_str25.array[((signed int )0u)])));
  llvm_cbe_tmp__3060 = *((&GM.field0.field0));
  llvm_cbe_tmp__3061 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__2845->field20)), 0u);
  llvm_cbe_tmp__3062 = ((__CPROVER_array_equal(llvm_cbe_tmp__3060, llvm_cbe_tmp__3061))&1);
  __CPROVER_assert(llvm_cbe_tmp__3062, ((&_OC_str26.array[((signed int )0u)])));
  llvm_cbe_tmp__3063 = *((&GM.field19.field0));
  llvm_cbe_tmp__3064 = _ZN13SysCArray2DstIhLj2ELj128EEixEj(((&llvm_cbe_tmp__2845->field28)), 0u);
  llvm_cbe_tmp__3065 = ((__CPROVER_array_equal(llvm_cbe_tmp__3063, llvm_cbe_tmp__3064))&1);
  __CPROVER_assert(llvm_cbe_tmp__3065, ((&_OC_str27.array[((signed int )0u)])));
  llvm_cbe_tmp__3066 = *((&GM.field4.field0));
  llvm_cbe_tmp__3067 = *((&((&llvm_cbe_tmp__2845->field22))->field0));
  llvm_cbe_tmp__3068 = ((__CPROVER_array_equal(llvm_cbe_tmp__3066, llvm_cbe_tmp__3067))&1);
  __CPROVER_assert(llvm_cbe_tmp__3068, ((&_OC_str28.array[((signed int )0u)])));
  llvm_cbe_tmp__3069 = *((&GM.field33.field0));
  llvm_cbe_tmp__3070 = *((&((&llvm_cbe_tmp__2845->field21))->field0));
  llvm_cbe_tmp__3071 = ((__CPROVER_array_equal(llvm_cbe_tmp__3069, llvm_cbe_tmp__3070))&1);
  __CPROVER_assert(llvm_cbe_tmp__3071, ((&_OC_str29.array[((signed int )0u)])));
  llvm_cbe_tmp__3072 = *((&GM.field16.field0));
  llvm_cbe_tmp__3073 = *((&((&llvm_cbe_tmp__2845->field24))->field0));
  llvm_cbe_tmp__3074 = ((__CPROVER_array_equal(llvm_cbe_tmp__3072, llvm_cbe_tmp__3073))&1);
  __CPROVER_assert(llvm_cbe_tmp__3074, ((&_OC_str30.array[((signed int )0u)])));
  goto llvm_cbe_tmp__3085;

llvm_cbe_tmp__3085:
  return;
}


unsigned char *_ZN11SysCArray1DIbLj512EEixEj(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3086;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3087;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3088;
  unsigned int llvm_cbe_tmp__3089;
  unsigned char *llvm_cbe_tmp__3090;

  *(&llvm_cbe_tmp__3086) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3087) = llvm_cbe_idx;
  llvm_cbe_tmp__3088 = *(&llvm_cbe_tmp__3086);
  llvm_cbe_tmp__3089 = *(&llvm_cbe_tmp__3087);
  llvm_cbe_tmp__3090 = *((&llvm_cbe_tmp__3088->field0));
  return ((&llvm_cbe_tmp__3090[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3089)))]));
}


float *_ZN11SysCArray1DIfLj5EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_idx) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3091;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3092;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3093;
  unsigned int llvm_cbe_tmp__3094;
  float *llvm_cbe_tmp__3095;

  *(&llvm_cbe_tmp__3091) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3092) = llvm_cbe_idx;
  llvm_cbe_tmp__3093 = *(&llvm_cbe_tmp__3091);
  llvm_cbe_tmp__3094 = *(&llvm_cbe_tmp__3092);
  llvm_cbe_tmp__3095 = *((&llvm_cbe_tmp__3093->field0));
  return ((&llvm_cbe_tmp__3095[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3094)))]));
}


void _ZN3rbm27activateHiddenUnits_predictEbtt(struct l_struct_OC_rbm *llvm_cbe_this, bool llvm_cbe_pingpong, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3096;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__3097;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3098;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3099;    /* Address-exposed local */
  unsigned short llvm_cbe_h;    /* Address-exposed local */
  unsigned short llvm_cbe_v;    /* Address-exposed local */
  float llvm_cbe_sum;    /* Address-exposed local */
  float llvm_cbe_tmp;    /* Address-exposed local */
  float llvm_cbe_prob;    /* Address-exposed local */
  float llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned char llvm_cbe_current_data;    /* Address-exposed local */
  unsigned char llvm_cbe_comp;    /* Address-exposed local */
  unsigned char llvm_cbe_th;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3100;
  unsigned short llvm_cbe_tmp__3101;
  unsigned short llvm_cbe_tmp__3102;
  unsigned short llvm_cbe_tmp__3103;
  unsigned short llvm_cbe_tmp__3104;
  unsigned short llvm_cbe_tmp__3105;
  unsigned short llvm_cbe_tmp__3106;
  unsigned short llvm_cbe_tmp__3107;
  unsigned char llvm_cbe_tmp__3108;
  unsigned char *llvm_cbe_tmp__3109;
  unsigned char llvm_cbe_tmp__3110;
  unsigned char llvm_cbe_tmp__3111;
  unsigned short llvm_cbe_tmp__3112;
  unsigned short llvm_cbe_tmp__3113;
  float *llvm_cbe_tmp__3114;
  float llvm_cbe_tmp__3115;
  float llvm_cbe_tmp__3116;
  float llvm_cbe_tmp__3117;
  unsigned short llvm_cbe_tmp__3118;
  float llvm_cbe_tmp__3119;
  unsigned long long llvm_cbe_tmp__3120;
  unsigned short llvm_cbe_tmp__3121;
  float llvm_cbe_tmp__3122;
  float llvm_cbe_tmp__3123;
  unsigned char llvm_cbe_tmp__3124;
  unsigned char llvm_cbe_tmp__3125;
  unsigned short llvm_cbe_tmp__3126;
  unsigned char *llvm_cbe_tmp__3127;
  unsigned short llvm_cbe_tmp__3128;
  unsigned short llvm_cbe_tmp__3129;
  unsigned char *llvm_cbe_tmp__3130;

  *(&llvm_cbe_tmp__3096) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3097) = (((unsigned char )(bool )llvm_cbe_pingpong));
  *(&llvm_cbe_tmp__3098) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__3099) = llvm_cbe_nv;
  llvm_cbe_tmp__3100 = *(&llvm_cbe_tmp__3096);
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__3131;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3131:
  llvm_cbe_tmp__3101 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3101))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__3132;
  } else {
    goto llvm_cbe_tmp__3133;
  }

llvm_cbe_tmp__3134:
  llvm_cbe_tmp__3125 = *(&llvm_cbe_th);
  llvm_cbe_tmp__3126 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3127 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3100->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3126)));
  *llvm_cbe_tmp__3127 = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3125&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__3128 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3128) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3131;

llvm_cbe_tmp__3135:
  *(&llvm_cbe_th) = ((unsigned char )1);
  goto llvm_cbe_tmp__3134;

llvm_cbe_tmp__3136:
  llvm_cbe_tmp__3119 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3120 = _Z8_c_16_15f(llvm_cbe_tmp__3119);
  llvm_cbe_tmp__3121 = _Z7sigmoidl(llvm_cbe_tmp__3120);
  llvm_cbe_tmp__3122 = _Z8_b_16_15l((((unsigned long long )(unsigned short )llvm_cbe_tmp__3121)));
  *(&llvm_cbe_prob) = llvm_cbe_tmp__3122;
  llvm_cbe_tmp__3123 = *(&llvm_cbe_prob);
  *(&llvm_cbe_comp) = (((unsigned char )(bool )(llvm_fcmp_olt(0x1p-1, llvm_cbe_tmp__3123))));
  llvm_cbe_tmp__3124 = *(&llvm_cbe_comp);
  if ((((((bool )llvm_cbe_tmp__3124&1u))&1))) {
    goto llvm_cbe_tmp__3135;
  } else {
    goto llvm_cbe_tmp__3137;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3138:
  llvm_cbe_tmp__3104 = *(&llvm_cbe_v);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3104))) < ((signed int )501u))) {
    goto llvm_cbe_tmp__3139;
  } else {
    goto llvm_cbe_tmp__3136;
  }

llvm_cbe_tmp__3140:
  llvm_cbe_tmp__3118 = *(&llvm_cbe_v);
  *(&llvm_cbe_v) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3118) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3138;

llvm_cbe_tmp__3141:
  llvm_cbe_tmp__3112 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3113 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3114 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__3100->field23)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3113)));
  llvm_cbe_tmp__3115 = *((&llvm_cbe_tmp__3114[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3112)))]));
  *(&llvm_cbe_tmp) = llvm_cbe_tmp__3115;
  _Z4waitv();
  llvm_cbe_tmp__3116 = *(&llvm_cbe_tmp);
  llvm_cbe_tmp__3117 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__3117 + llvm_cbe_tmp__3116)));
  goto llvm_cbe_tmp__3140;

llvm_cbe_tmp__3142:
  llvm_cbe_tmp__3107 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3108 = *(&llvm_cbe_tmp__3097);
  llvm_cbe_tmp__3109 = _ZN13SysCArray2DstIhLj2ELj512EEixEj(((&llvm_cbe_tmp__3100->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3108&1u))&1)))));
  llvm_cbe_tmp__3110 = *((&llvm_cbe_tmp__3109[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3107)))]));
  *(&llvm_cbe_current_data) = llvm_cbe_tmp__3110;
  _Z4waitv();
  llvm_cbe_tmp__3111 = *(&llvm_cbe_current_data);
  if (((((unsigned int )(unsigned char )llvm_cbe_tmp__3111)) == 1u)) {
    goto llvm_cbe_tmp__3141;
  } else {
    goto llvm_cbe_tmp__3140;
  }

llvm_cbe_tmp__3139:
  llvm_cbe_tmp__3105 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3106 = *(&llvm_cbe_tmp__3099);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3105)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3106))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__3136;
  } else {
    goto llvm_cbe_tmp__3142;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3143:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_v) = ((unsigned short )0);
  goto llvm_cbe_tmp__3138;

llvm_cbe_tmp__3132:
  llvm_cbe_tmp__3102 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3103 = *(&llvm_cbe_tmp__3098);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3102)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__3103)))) {
    goto llvm_cbe_tmp__3133;
  } else {
    goto llvm_cbe_tmp__3143;
  }

llvm_cbe_tmp__3137:
  *(&llvm_cbe_th) = ((unsigned char )0);
  goto llvm_cbe_tmp__3134;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3133:
  llvm_cbe_tmp__3129 = *(&llvm_cbe_tmp__3098);
  llvm_cbe_tmp__3130 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3100->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3129)));
  *llvm_cbe_tmp__3130 = ((unsigned char )1);
  _Z4waitv();
  return;
}


void _ZN3rbm28activateVisibleUnits_predictEtt(struct l_struct_OC_rbm *llvm_cbe_this, unsigned short llvm_cbe_nh, unsigned short llvm_cbe_nv) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3144;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3145;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__3146;    /* Address-exposed local */
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
  float llvm_cbe_dp;    /* Address-exposed local */
  float llvm_cbe_dp1;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3147;
  unsigned short llvm_cbe_tmp__3148;
  unsigned short llvm_cbe_tmp__3149;
  unsigned short llvm_cbe_tmp__3150;
  unsigned short llvm_cbe_tmp__3151;
  unsigned short llvm_cbe_tmp__3152;
  unsigned short llvm_cbe_tmp__3153;
  unsigned short llvm_cbe_tmp__3154;
  unsigned short llvm_cbe_tmp__3155;
  unsigned char *llvm_cbe_tmp__3156;
  unsigned char llvm_cbe_tmp__3157;
  unsigned short llvm_cbe_tmp__3158;
  unsigned short llvm_cbe_tmp__3159;
  unsigned short llvm_cbe_tmp__3160;
  float *llvm_cbe_tmp__3161;
  float llvm_cbe_tmp__3162;
  unsigned char llvm_cbe_tmp__3163;
  float llvm_cbe_tmp__3164;
  float llvm_cbe_tmp__3165;
  unsigned short llvm_cbe_tmp__3166;
  float llvm_cbe_tmp__3167;
  unsigned short llvm_cbe_tmp__3168;
  float *llvm_cbe_tmp__3169;
  float llvm_cbe_tmp__3170;
  float llvm_cbe_tmp__3171;
  float llvm_cbe_tmp__3172;
  unsigned short llvm_cbe_tmp__3173;
  float llvm_cbe_tmp__3174;
  unsigned short llvm_cbe_tmp__3175;
  unsigned short llvm_cbe_tmp__3176;
  float *llvm_cbe_tmp__3177;
  float llvm_cbe_tmp__3178;
  float llvm_cbe_tmp__3179;
  float llvm_cbe_tmp__3180;
  unsigned short llvm_cbe_tmp__3181;
  float *llvm_cbe_tmp__3182;
  unsigned short llvm_cbe_tmp__3183;
  unsigned short llvm_cbe_tmp__3184;
  unsigned short llvm_cbe_tmp__3185;
  float *llvm_cbe_tmp__3186;
  float llvm_cbe_tmp__3187;
  float llvm_cbe_tmp__3188;
  unsigned long long llvm_cbe_tmp__3189;
  unsigned short llvm_cbe_tmp__3190;
  float llvm_cbe_tmp__3191;
  float llvm_cbe_tmp__3192;
  float llvm_cbe_tmp__3193;
  float llvm_cbe_tmp__3194;
  unsigned short llvm_cbe_tmp__3195;
  unsigned short llvm_cbe_tmp__3196;
  unsigned short llvm_cbe_tmp__3197;
  unsigned short llvm_cbe_tmp__3198;
  float llvm_cbe_tmp__3199;
  float llvm_cbe_tmp__3200;
  float llvm_cbe_tmp__3201;
  unsigned short llvm_cbe_tmp__3202;
  float llvm_cbe_tmp__3203;
  float llvm_cbe_tmp__3204;
  unsigned short llvm_cbe_tmp__3205;
  float llvm_cbe_tmp__3206;
  unsigned long long llvm_cbe_tmp__3207;
  unsigned short llvm_cbe_tmp__3208;
  unsigned short llvm_cbe_tmp__3209;
  unsigned char llvm_cbe_tmp__3210;
  unsigned short llvm_cbe_tmp__3211;
  unsigned short llvm_cbe_tmp__3212;
  unsigned char *llvm_cbe_tmp__3213;
  unsigned short llvm_cbe_tmp__3214;
  unsigned short llvm_cbe_tmp__3215;
  unsigned short llvm_cbe_tmp__3216;
  unsigned char *llvm_cbe_tmp__3217;

  *(&llvm_cbe_tmp__3144) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3145) = llvm_cbe_nh;
  *(&llvm_cbe_tmp__3146) = llvm_cbe_nv;
  llvm_cbe_tmp__3147 = *(&llvm_cbe_tmp__3144);
  *(&llvm_cbe_v) = ((unsigned short )0);
  goto llvm_cbe_tmp__3218;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3218:
  llvm_cbe_tmp__3148 = *(&llvm_cbe_v);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3148))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__3219;
  } else {
    goto llvm_cbe_tmp__3220;
  }

llvm_cbe_tmp__3221:
  llvm_cbe_tmp__3215 = *(&llvm_cbe_v);
  *(&llvm_cbe_v) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3215))) + ((unsigned int )5u))))));
  goto llvm_cbe_tmp__3218;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3222:
  llvm_cbe_tmp__3208 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3208))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3223;
  } else {
    goto llvm_cbe_tmp__3221;
  }

llvm_cbe_tmp__3224:
  _Z4waitv();
  llvm_cbe_tmp__3214 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3214) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3222;

llvm_cbe_tmp__3225:
  *llvm_cbe_tmp__3213 = ((unsigned char )1);
  goto llvm_cbe_tmp__3224;

llvm_cbe_tmp__3223:
  llvm_cbe_tmp__3209 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3210 = *(&llvm_cbe_prediction);
  llvm_cbe_tmp__3211 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3212 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3213 = _ZN11SysCArray1DIbLj512EEixEj(((&llvm_cbe_tmp__3147->field27)), (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3211))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3212)))))));
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3209)) == (((unsigned int )(unsigned char )llvm_cbe_tmp__3210)))) {
    goto llvm_cbe_tmp__3225;
  } else {
    goto llvm_cbe_tmp__3226;
  }

llvm_cbe_tmp__3226:
  *llvm_cbe_tmp__3213 = ((unsigned char )0);
  goto llvm_cbe_tmp__3224;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3227:
  llvm_cbe_tmp__3206 = *(&llvm_cbe_expectation);
  llvm_cbe_tmp__3207 = _Z6round_l((((signed long long )llvm_cbe_tmp__3206)));
  *(&llvm_cbe_prediction) = (((unsigned char )llvm_cbe_tmp__3207));
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3222;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3228:
  llvm_cbe_tmp__3197 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3197))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3229;
  } else {
    goto llvm_cbe_tmp__3227;
  }

llvm_cbe_tmp__3229:
  llvm_cbe_tmp__3198 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3199 = *((&llvm_cbe_pow2.array[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3198)))]));
  *(&llvm_cbe_dp1) = llvm_cbe_tmp__3199;
  _Z4waitv();
  llvm_cbe_tmp__3200 = *(&llvm_cbe_dp1);
  llvm_cbe_tmp__3201 = *(&llvm_cbe_sumOfpow2);
  *(&llvm_cbe_probs) = (((float )(llvm_cbe_tmp__3200 / llvm_cbe_tmp__3201)));
  llvm_cbe_tmp__3202 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3203 = *(&llvm_cbe_probs);
  llvm_cbe_tmp__3204 = *(&llvm_cbe_expectation);
  *(&llvm_cbe_expectation) = (((float )(llvm_cbe_tmp__3204 + (((float )((((float )(signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3202)))) * llvm_cbe_tmp__3203))))));
  llvm_cbe_tmp__3205 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3205) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3228;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3230:
  *(&llvm_cbe_expectation) = 0x0p+0;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3228;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3231:
  llvm_cbe_tmp__3184 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3184))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3232;
  } else {
    goto llvm_cbe_tmp__3230;
  }

llvm_cbe_tmp__3232:
  llvm_cbe_tmp__3185 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3186 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3147->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3185)));
  llvm_cbe_tmp__3187 = *llvm_cbe_tmp__3186;
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3187;
  _Z4waitv();
  llvm_cbe_tmp__3188 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3189 = _Z8_c_16_15f(llvm_cbe_tmp__3188);
  llvm_cbe_tmp__3190 = _Z10to_int_expl(llvm_cbe_tmp__3189);
  llvm_cbe_tmp__3191 = _Z8_b_16_15l((((unsigned long long )(unsigned short )llvm_cbe_tmp__3190)));
  *(&llvm_cbe_dp) = llvm_cbe_tmp__3191;
  llvm_cbe_tmp__3192 = *(&llvm_cbe_dp);
  llvm_cbe_tmp__3193 = *(&llvm_cbe_sumOfpow2);
  *(&llvm_cbe_sumOfpow2) = (((float )(llvm_cbe_tmp__3193 + llvm_cbe_tmp__3192)));
  llvm_cbe_tmp__3194 = *(&llvm_cbe_dp);
  llvm_cbe_tmp__3195 = *(&llvm_cbe_j);
  *((&llvm_cbe_pow2.array[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3195)))])) = llvm_cbe_tmp__3194;
  llvm_cbe_tmp__3196 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3196) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3231;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3233:
  *(&llvm_cbe_sumOfpow2) = 0x0p+0;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3231;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3234:
  llvm_cbe_tmp__3175 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3175))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3235;
  } else {
    goto llvm_cbe_tmp__3233;
  }

llvm_cbe_tmp__3235:
  llvm_cbe_tmp__3176 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3177 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3147->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3176)));
  llvm_cbe_tmp__3178 = *llvm_cbe_tmp__3177;
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3178;
  _Z4waitv();
  llvm_cbe_tmp__3179 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3180 = *(&llvm_cbe_max);
  llvm_cbe_tmp__3181 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3182 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3147->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3181)));
  *llvm_cbe_tmp__3182 = (((float )(llvm_cbe_tmp__3179 - llvm_cbe_tmp__3180)));
  _Z4waitv();
  llvm_cbe_tmp__3183 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3183) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3234;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3236:
  llvm_cbe_tmp__3174 = *(&llvm_cbe_max);
  *(&llvm_cbe_max) = (((float )(llvm_cbe_tmp__3174 - 0x1.fp+4)));
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3234;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3237:
  llvm_cbe_tmp__3151 = *(&llvm_cbe_j);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3151))) < ((signed int )5u))) {
    goto llvm_cbe_tmp__3238;
  } else {
    goto llvm_cbe_tmp__3236;
  }

llvm_cbe_tmp__3239:
  llvm_cbe_tmp__3173 = *(&llvm_cbe_j);
  *(&llvm_cbe_j) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3173) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3237;

llvm_cbe_tmp__3240:
  llvm_cbe_tmp__3172 = *(&llvm_cbe_sum);
  *(&llvm_cbe_max) = llvm_cbe_tmp__3172;
  goto llvm_cbe_tmp__3239;

llvm_cbe_tmp__3241:
  llvm_cbe_tmp__3167 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3168 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3169 = _ZN11SysCArray1DIfLj5EEixEj(((&llvm_cbe_tmp__3147->field26)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3168)));
  *llvm_cbe_tmp__3169 = llvm_cbe_tmp__3167;
  _Z4waitv();
  llvm_cbe_tmp__3170 = *(&llvm_cbe_sum);
  llvm_cbe_tmp__3171 = *(&llvm_cbe_max);
  if ((llvm_fcmp_ogt(llvm_cbe_tmp__3170, llvm_cbe_tmp__3171))) {
    goto llvm_cbe_tmp__3240;
  } else {
    goto llvm_cbe_tmp__3239;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__3242:
  llvm_cbe_tmp__3152 = *(&llvm_cbe_h);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3152))) < ((signed int )101u))) {
    goto llvm_cbe_tmp__3243;
  } else {
    goto llvm_cbe_tmp__3241;
  }

llvm_cbe_tmp__3244:
  _Z4waitv();
  llvm_cbe_tmp__3166 = *(&llvm_cbe_h);
  *(&llvm_cbe_h) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__3166) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__3242;

llvm_cbe_tmp__3245:
  llvm_cbe_tmp__3155 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3156 = _ZN11SysCArray1DIbLj128EEixEj(((&llvm_cbe_tmp__3147->field22)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3155)));
  llvm_cbe_tmp__3157 = *llvm_cbe_tmp__3156;
  *(&llvm_cbe_tmp2) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__3157&1u))&1))));
  _Z4waitv();
  llvm_cbe_tmp__3158 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3159 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3160 = *(&llvm_cbe_j);
  llvm_cbe_tmp__3161 = _ZN11SysCArray2DIfLj501ELj101EEixEj(((&llvm_cbe_tmp__3147->field23)), (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3159))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3160)))))));
  llvm_cbe_tmp__3162 = *((&llvm_cbe_tmp__3161[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__3158)))]));
  *(&llvm_cbe_tmp1) = llvm_cbe_tmp__3162;
  _Z4waitv();
  llvm_cbe_tmp__3163 = *(&llvm_cbe_tmp2);
  if ((((((bool )llvm_cbe_tmp__3163&1u))&1))) {
    goto llvm_cbe_tmp__3246;
  } else {
    goto llvm_cbe_tmp__3244;
  }

llvm_cbe_tmp__3243:
  llvm_cbe_tmp__3153 = *(&llvm_cbe_h);
  llvm_cbe_tmp__3154 = *(&llvm_cbe_tmp__3145);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3153)) == (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__3154))) + ((unsigned int )1u)))))) {
    goto llvm_cbe_tmp__3241;
  } else {
    goto llvm_cbe_tmp__3245;
  }

llvm_cbe_tmp__3246:
  llvm_cbe_tmp__3164 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__3165 = *(&llvm_cbe_sum);
  *(&llvm_cbe_sum) = (((float )(llvm_cbe_tmp__3165 + llvm_cbe_tmp__3164)));
  goto llvm_cbe_tmp__3244;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3238:
  *(&llvm_cbe_sum) = 0x0p+0;
  *(&llvm_cbe_h) = ((unsigned short )0);
  goto llvm_cbe_tmp__3242;

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3247:
  *(&llvm_cbe_max) = -0x1.f4p+8;
  *(&llvm_cbe_j) = ((unsigned short )0);
  goto llvm_cbe_tmp__3237;

llvm_cbe_tmp__3219:
  llvm_cbe_tmp__3149 = *(&llvm_cbe_v);
  llvm_cbe_tmp__3150 = *(&llvm_cbe_tmp__3146);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__3149)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__3150)))) {
    goto llvm_cbe_tmp__3220;
  } else {
    goto llvm_cbe_tmp__3247;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__3220:
  llvm_cbe_tmp__3216 = *(&llvm_cbe_tmp__3146);
  llvm_cbe_tmp__3217 = _ZN11SysCArray1DIbLj512EEixEj(((&llvm_cbe_tmp__3147->field27)), (((unsigned int )(unsigned short )llvm_cbe_tmp__3216)));
  *llvm_cbe_tmp__3217 = ((unsigned char )1);
  _Z4waitv();
  return;
}


static void __cxx_global_var_init32(void) {
  _ZN3rbmC1Ev((&IMPL));
  return;
}


void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3248;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3249;

  *(&llvm_cbe_tmp__3248) = llvm_cbe_this;
  llvm_cbe_tmp__3249 = *(&llvm_cbe_tmp__3248);
  _ZN3rbmC2Ev(llvm_cbe_tmp__3249);
  return;
}


unsigned int main(void) {
  unsigned int llvm_cbe_tmp__3250;    /* Address-exposed local */
  _GLOBAL__I_a();  CODE_FOR_MAIN();
  *(&llvm_cbe_tmp__3250) = 0u;
  _ZN3rbm9train_rbmEv((&IMPL));
  return 0u;
}


void _ZN8type_memIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3251;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3252;
  unsigned char *llvm_cbe_tmp__3253;

  *(&llvm_cbe_tmp__3251) = llvm_cbe_this;
  llvm_cbe_tmp__3252 = *(&llvm_cbe_tmp__3251);
  llvm_cbe_tmp__3253 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3252->field0)) = llvm_cbe_tmp__3253;
  return;
}


void _ZN8type_memItLj8EEC2Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__3254;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3255;
  unsigned char *llvm_cbe_tmp__3256;

  *(&llvm_cbe_tmp__3254) = llvm_cbe_this;
  llvm_cbe_tmp__3255 = *(&llvm_cbe_tmp__3254);
  llvm_cbe_tmp__3256 = __CPROVER_malloc(16ull);
  *((&llvm_cbe_tmp__3255->field0)) = (((unsigned short *)llvm_cbe_tmp__3256));
  return;
}


void _ZN8type_memIjLj8EEC2Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__3257;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3258;
  unsigned char *llvm_cbe_tmp__3259;

  *(&llvm_cbe_tmp__3257) = llvm_cbe_this;
  llvm_cbe_tmp__3258 = *(&llvm_cbe_tmp__3257);
  llvm_cbe_tmp__3259 = __CPROVER_malloc(32ull);
  *((&llvm_cbe_tmp__3258->field0)) = (((unsigned int *)llvm_cbe_tmp__3259));
  return;
}


void _ZN8type_memIbLj65536EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3260;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3261;
  unsigned char *llvm_cbe_tmp__3262;

  *(&llvm_cbe_tmp__3260) = llvm_cbe_this;
  llvm_cbe_tmp__3261 = *(&llvm_cbe_tmp__3260);
  llvm_cbe_tmp__3262 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3261->field0)) = llvm_cbe_tmp__3262;
  return;
}


void _ZN8type_memIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3263;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3264;
  unsigned char *llvm_cbe_tmp__3265;

  *(&llvm_cbe_tmp__3263) = llvm_cbe_this;
  llvm_cbe_tmp__3264 = *(&llvm_cbe_tmp__3263);
  llvm_cbe_tmp__3265 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3264->field0)) = llvm_cbe_tmp__3265;
  return;
}


void _ZN8type_memIhLj65536EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3266;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3267;
  unsigned char *llvm_cbe_tmp__3268;

  *(&llvm_cbe_tmp__3266) = llvm_cbe_this;
  llvm_cbe_tmp__3267 = *(&llvm_cbe_tmp__3266);
  llvm_cbe_tmp__3268 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3267->field0)) = llvm_cbe_tmp__3268;
  return;
}


void _ZN8type_memIbLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3269;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3270;

  *(&llvm_cbe_tmp__3269) = llvm_cbe_this;
  llvm_cbe_tmp__3270 = *(&llvm_cbe_tmp__3269);
  return;
}


void _ZN8type_memItLj8EED2Ev(struct l_unnamed2 *llvm_cbe_this) {
  struct l_unnamed2 *llvm_cbe_tmp__3271;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3272;

  *(&llvm_cbe_tmp__3271) = llvm_cbe_this;
  llvm_cbe_tmp__3272 = *(&llvm_cbe_tmp__3271);
  return;
}


void _ZN8type_memIjLj8EED2Ev(struct l_unnamed1 *llvm_cbe_this) {
  struct l_unnamed1 *llvm_cbe_tmp__3273;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3274;

  *(&llvm_cbe_tmp__3273) = llvm_cbe_this;
  llvm_cbe_tmp__3274 = *(&llvm_cbe_tmp__3273);
  return;
}


void _ZN8type_memIbLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3275;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3276;

  *(&llvm_cbe_tmp__3275) = llvm_cbe_this;
  llvm_cbe_tmp__3276 = *(&llvm_cbe_tmp__3275);
  return;
}


void _ZN8type_memIbLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3277;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3278;

  *(&llvm_cbe_tmp__3277) = llvm_cbe_this;
  llvm_cbe_tmp__3278 = *(&llvm_cbe_tmp__3277);
  return;
}


void _ZN8type_memIhLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3279;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3280;

  *(&llvm_cbe_tmp__3279) = llvm_cbe_this;
  llvm_cbe_tmp__3280 = *(&llvm_cbe_tmp__3279);
  return;
}


void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__3281;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__3282;
  unsigned char *llvm_cbe_tmp__3283;
  unsigned char llvm_cbe_tmp__3284;
  unsigned char *llvm_cbe_tmp__3285;
  unsigned char llvm_cbe_tmp__3286;
  unsigned char *llvm_cbe_tmp__3287;
  unsigned char llvm_cbe_tmp__3288;
  unsigned char *llvm_cbe_tmp__3289;
  unsigned char llvm_cbe_tmp__3290;
  unsigned char *llvm_cbe_tmp__3291;
  unsigned char llvm_cbe_tmp__3292;

  *(&llvm_cbe_tmp__3281) = llvm_cbe_this;
  llvm_cbe_tmp__3282 = *(&llvm_cbe_tmp__3281);
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3282->field0)), ((&_OC_str33.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3282->field1)), ((&_OC_str34.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field2)), ((&_OC_str35.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field3)), ((&_OC_str36.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3282->field4)), ((&_OC_str37.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3282->field5)), ((&_OC_str38.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field6)), ((&_OC_str39.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field7)), ((&_OC_str40.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field8)), ((&_OC_str41.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3282->field9)), ((&_OC_str42.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3282->field10)), ((&_OC_str43.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field11)), ((&_OC_str44.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3282->field12)), ((&_OC_str45.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__3282->field13)), ((&_OC_str46.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field14)), ((&_OC_str47.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field15)), ((&_OC_str48.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field16)), ((&_OC_str49.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field17)), ((&_OC_str50.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field18)), ((&_OC_str51.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__3282->field19)), ((&_OC_str52.array[((signed int )0u)])));
  _ZN13SysCArray2DstIhLj2ELj512EEC1Ev(((&llvm_cbe_tmp__3282->field20)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__3282->field21)));
  _ZN11SysCArray1DIbLj128EEC1Ev(((&llvm_cbe_tmp__3282->field22)));
  _ZN11SysCArray2DIfLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3282->field23)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3282->field24)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__3282->field25)));
  _ZN11SysCArray1DIfLj5EEC1Ev(((&llvm_cbe_tmp__3282->field26)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__3282->field27)));
  _ZN13SysCArray2DstIhLj2ELj128EEC1Ev(((&llvm_cbe_tmp__3282->field28)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3282->field30)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3282->field31)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3282->field32)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3282->field33)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3282->field34)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__3282->field35)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field36)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field37)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field38)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field39)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field40)));
  _ZN15sc_signal_int32C1Ev(((&llvm_cbe_tmp__3282->field41)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field42)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field43)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field44)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__3282->field45)));
  llvm_cbe_tmp__3283 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3282->field1)));
  llvm_cbe_tmp__3284 = *llvm_cbe_tmp__3283;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3284&1u))&1)))), 0);
  llvm_cbe_tmp__3285 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3282->field1)));
  llvm_cbe_tmp__3286 = *llvm_cbe_tmp__3285;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3286&1u))&1)))), 0);
  llvm_cbe_tmp__3287 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3282->field1)));
  llvm_cbe_tmp__3288 = *llvm_cbe_tmp__3287;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3288&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__3289 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3282->field1)));
  llvm_cbe_tmp__3290 = *llvm_cbe_tmp__3289;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3290&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__3291 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__3282->field1)));
  llvm_cbe_tmp__3292 = *llvm_cbe_tmp__3291;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__3292&1u))&1)))), 0);
  return;
}


void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3293;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3294;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3295;
  unsigned char *llvm_cbe_tmp__3296;

  *(&llvm_cbe_tmp__3293) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3294) = llvm_cbe_p;
  llvm_cbe_tmp__3295 = *(&llvm_cbe_tmp__3293);
  llvm_cbe_tmp__3296 = *(&llvm_cbe_tmp__3294);
  _ZN14sc_signal_boolC2EPKc(llvm_cbe_tmp__3295, llvm_cbe_tmp__3296);
  return;
}


void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3297;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3298;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3299;
  unsigned char *llvm_cbe_tmp__3300;

  *(&llvm_cbe_tmp__3297) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3298) = llvm_cbe_p;
  llvm_cbe_tmp__3299 = *(&llvm_cbe_tmp__3297);
  llvm_cbe_tmp__3300 = *(&llvm_cbe_tmp__3298);
  _ZN13sc_signal_u32C2EPKc(llvm_cbe_tmp__3299, llvm_cbe_tmp__3300);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3301;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3302;

  *(&llvm_cbe_tmp__3301) = llvm_cbe_this;
  llvm_cbe_tmp__3302 = *(&llvm_cbe_tmp__3301);
  _ZN13SysCArray2DstIhLj2ELj512EEC2Ev(llvm_cbe_tmp__3302);
  return;
}


void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3303;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3304;

  *(&llvm_cbe_tmp__3303) = llvm_cbe_this;
  llvm_cbe_tmp__3304 = *(&llvm_cbe_tmp__3303);
  _ZN11SysCArray1DIbLj512EEC2Ev(llvm_cbe_tmp__3304);
  return;
}


void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3305;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3306;

  *(&llvm_cbe_tmp__3305) = llvm_cbe_this;
  llvm_cbe_tmp__3306 = *(&llvm_cbe_tmp__3305);
  _ZN11SysCArray1DIbLj128EEC2Ev(llvm_cbe_tmp__3306);
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3307;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3308;

  *(&llvm_cbe_tmp__3307) = llvm_cbe_this;
  llvm_cbe_tmp__3308 = *(&llvm_cbe_tmp__3307);
  _ZN11SysCArray2DIfLj501ELj101EEC2Ev(llvm_cbe_tmp__3308);
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3309;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3310;

  *(&llvm_cbe_tmp__3309) = llvm_cbe_this;
  llvm_cbe_tmp__3310 = *(&llvm_cbe_tmp__3309);
  _ZN11SysCArray2DIbLj501ELj101EEC2Ev(llvm_cbe_tmp__3310);
  return;
}


void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3311;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3312;

  *(&llvm_cbe_tmp__3311) = llvm_cbe_this;
  llvm_cbe_tmp__3312 = *(&llvm_cbe_tmp__3311);
  _ZN11SysCArray1DIfLj5EEC2Ev(llvm_cbe_tmp__3312);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3313;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3314;

  *(&llvm_cbe_tmp__3313) = llvm_cbe_this;
  llvm_cbe_tmp__3314 = *(&llvm_cbe_tmp__3313);
  _ZN13SysCArray2DstIhLj2ELj128EEC2Ev(llvm_cbe_tmp__3314);
  return;
}


void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3315;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3316;

  *(&llvm_cbe_tmp__3315) = llvm_cbe_this;
  llvm_cbe_tmp__3316 = *(&llvm_cbe_tmp__3315);
  _ZN13sc_signal_u16C2Ev(llvm_cbe_tmp__3316);
  return;
}


void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3317;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3318;

  *(&llvm_cbe_tmp__3317) = llvm_cbe_this;
  llvm_cbe_tmp__3318 = *(&llvm_cbe_tmp__3317);
  _ZN14sc_signal_boolC2Ev(llvm_cbe_tmp__3318);
  return;
}


void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3319;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3320;

  *(&llvm_cbe_tmp__3319) = llvm_cbe_this;
  llvm_cbe_tmp__3320 = *(&llvm_cbe_tmp__3319);
  _ZN15sc_signal_int32C2Ev(llvm_cbe_tmp__3320);
  return;
}


unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3321;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3322;

  *(&llvm_cbe_tmp__3321) = llvm_cbe_this;
  llvm_cbe_tmp__3322 = *(&llvm_cbe_tmp__3321);
  return ((&llvm_cbe_tmp__3322->field0));
}


void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3323;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3324;

  *(&llvm_cbe_tmp__3323) = llvm_cbe_this;
  llvm_cbe_tmp__3324 = *(&llvm_cbe_tmp__3323);
  return;
}


void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3325;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3326;

  *(&llvm_cbe_tmp__3325) = llvm_cbe_this;
  llvm_cbe_tmp__3326 = *(&llvm_cbe_tmp__3325);
  return;
}


void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3327;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__3328;

  *(&llvm_cbe_tmp__3327) = llvm_cbe_this;
  llvm_cbe_tmp__3328 = *(&llvm_cbe_tmp__3327);
  return;
}


void _ZN13SysCArray2DstIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3329;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3330;
  unsigned char *llvm_cbe_tmp__3331;
  unsigned char *llvm_cbe_tmp__3332;

  *(&llvm_cbe_tmp__3329) = llvm_cbe_this;
  llvm_cbe_tmp__3330 = *(&llvm_cbe_tmp__3329);
  llvm_cbe_tmp__3331 = __CPROVER_malloc(256ull);
  *((&llvm_cbe_tmp__3330->field0)) = llvm_cbe_tmp__3331;
  llvm_cbe_tmp__3332 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3330->field1)) = llvm_cbe_tmp__3332;
  return;
}


void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3333;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3334;
  unsigned char *llvm_cbe_tmp__3335;

  *(&llvm_cbe_tmp__3333) = llvm_cbe_this;
  llvm_cbe_tmp__3334 = *(&llvm_cbe_tmp__3333);
  llvm_cbe_tmp__3335 = __CPROVER_malloc(20ull);
  *((&llvm_cbe_tmp__3334->field0)) = (((float *)llvm_cbe_tmp__3335));
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3336;    /* Address-exposed local */
  unsigned int llvm_cbe_eqsize;    /* Address-exposed local */
  unsigned int llvm_cbe_acsize;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3337;
  unsigned int llvm_cbe_tmp__3338;
  unsigned int llvm_cbe_tmp__3339;
  unsigned int llvm_cbe_tmp__3340;
  unsigned int llvm_cbe_tmp__3341;
  unsigned int llvm_cbe_tmp__3342;
  unsigned int llvm_cbe_tmp__3343;
  unsigned int llvm_cbe_tmp__3344;
  unsigned int llvm_cbe_tmp__3345;
  unsigned int llvm_cbe_tmp__3346;
  unsigned int llvm_cbe_tmp__3347;
  unsigned int llvm_cbe_tmp__3348;
  unsigned int llvm_cbe_tmp__3349;
  unsigned int llvm_cbe_tmp__3350;
  unsigned int llvm_cbe_tmp__3351;
  unsigned int llvm_cbe_tmp__3352;
  unsigned int llvm_cbe_tmp__3353;
  unsigned int llvm_cbe_tmp__3354;
  unsigned int llvm_cbe_tmp__3355;
  unsigned int llvm_cbe_tmp__3356;
  unsigned int llvm_cbe_tmp__3357;
  unsigned int llvm_cbe_tmp__3358;
  unsigned int llvm_cbe_tmp__3359;
  unsigned int llvm_cbe_tmp__3360;
  unsigned int llvm_cbe_tmp__3361;
  unsigned int llvm_cbe_tmp__3362;
  unsigned int llvm_cbe_tmp__3363;
  unsigned int llvm_cbe_tmp__3364;
  unsigned int llvm_cbe_tmp__3365;
  unsigned int llvm_cbe_tmp__3366;
  unsigned int llvm_cbe_tmp__3367;
  unsigned int llvm_cbe_tmp__3368;
  unsigned int llvm_cbe_tmp__3369;
  unsigned int llvm_cbe_tmp__3370;
  unsigned char *llvm_cbe_tmp__3371;

  *(&llvm_cbe_tmp__3336) = llvm_cbe_this;
  llvm_cbe_tmp__3337 = *(&llvm_cbe_tmp__3336);
  *(&llvm_cbe_acsize) = 50601u;
  llvm_cbe_tmp__3338 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3338 == 1u)) {
    goto llvm_cbe_tmp__3372;
  } else {
    goto llvm_cbe_tmp__3373;
  }

llvm_cbe_tmp__3372:
  *(&llvm_cbe_eqsize) = 1u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3373:
  llvm_cbe_tmp__3339 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3339 == 2u)) {
    goto llvm_cbe_tmp__3375;
  } else {
    goto llvm_cbe_tmp__3376;
  }

llvm_cbe_tmp__3375:
  *(&llvm_cbe_eqsize) = 2u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3376:
  llvm_cbe_tmp__3340 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3341 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3340) > ((unsigned int )2u)) & (((unsigned int )llvm_cbe_tmp__3341) <= ((unsigned int )4u)))&1))) {
    goto llvm_cbe_tmp__3377;
  } else {
    goto llvm_cbe_tmp__3378;
  }

llvm_cbe_tmp__3377:
  *(&llvm_cbe_eqsize) = 4u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3378:
  llvm_cbe_tmp__3342 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3343 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3342) > ((unsigned int )4u)) & (((unsigned int )llvm_cbe_tmp__3343) <= ((unsigned int )8u)))&1))) {
    goto llvm_cbe_tmp__3379;
  } else {
    goto llvm_cbe_tmp__3380;
  }

llvm_cbe_tmp__3379:
  *(&llvm_cbe_eqsize) = 8u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3380:
  llvm_cbe_tmp__3344 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3345 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3344) > ((unsigned int )8u)) & (((unsigned int )llvm_cbe_tmp__3345) <= ((unsigned int )16u)))&1))) {
    goto llvm_cbe_tmp__3381;
  } else {
    goto llvm_cbe_tmp__3382;
  }

llvm_cbe_tmp__3381:
  *(&llvm_cbe_eqsize) = 16u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3382:
  llvm_cbe_tmp__3346 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3347 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3346) > ((unsigned int )16u)) & (((unsigned int )llvm_cbe_tmp__3347) <= ((unsigned int )32u)))&1))) {
    goto llvm_cbe_tmp__3383;
  } else {
    goto llvm_cbe_tmp__3384;
  }

llvm_cbe_tmp__3383:
  *(&llvm_cbe_eqsize) = 32u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3384:
  llvm_cbe_tmp__3348 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3349 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3348) > ((unsigned int )32u)) & (((unsigned int )llvm_cbe_tmp__3349) <= ((unsigned int )64u)))&1))) {
    goto llvm_cbe_tmp__3385;
  } else {
    goto llvm_cbe_tmp__3386;
  }

llvm_cbe_tmp__3385:
  *(&llvm_cbe_eqsize) = 64u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3386:
  llvm_cbe_tmp__3350 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3351 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3350) > ((unsigned int )64u)) & (((unsigned int )llvm_cbe_tmp__3351) <= ((unsigned int )128u)))&1))) {
    goto llvm_cbe_tmp__3387;
  } else {
    goto llvm_cbe_tmp__3388;
  }

llvm_cbe_tmp__3387:
  *(&llvm_cbe_eqsize) = 128u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3388:
  llvm_cbe_tmp__3352 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3353 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3352) > ((unsigned int )128u)) & (((unsigned int )llvm_cbe_tmp__3353) <= ((unsigned int )256u)))&1))) {
    goto llvm_cbe_tmp__3389;
  } else {
    goto llvm_cbe_tmp__3390;
  }

llvm_cbe_tmp__3389:
  *(&llvm_cbe_eqsize) = 256u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3390:
  llvm_cbe_tmp__3354 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3355 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3354) > ((unsigned int )256u)) & (((unsigned int )llvm_cbe_tmp__3355) <= ((unsigned int )512u)))&1))) {
    goto llvm_cbe_tmp__3391;
  } else {
    goto llvm_cbe_tmp__3392;
  }

llvm_cbe_tmp__3391:
  *(&llvm_cbe_eqsize) = 512u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3392:
  llvm_cbe_tmp__3356 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3357 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3356) > ((unsigned int )512u)) & (((unsigned int )llvm_cbe_tmp__3357) <= ((unsigned int )1024u)))&1))) {
    goto llvm_cbe_tmp__3393;
  } else {
    goto llvm_cbe_tmp__3394;
  }

llvm_cbe_tmp__3393:
  *(&llvm_cbe_eqsize) = 1024u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3394:
  llvm_cbe_tmp__3358 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3359 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3358) > ((unsigned int )1024u)) & (((unsigned int )llvm_cbe_tmp__3359) <= ((unsigned int )2048u)))&1))) {
    goto llvm_cbe_tmp__3395;
  } else {
    goto llvm_cbe_tmp__3396;
  }

llvm_cbe_tmp__3395:
  *(&llvm_cbe_eqsize) = 2048u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3396:
  llvm_cbe_tmp__3360 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3361 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3360) > ((unsigned int )2048u)) & (((unsigned int )llvm_cbe_tmp__3361) <= ((unsigned int )4096u)))&1))) {
    goto llvm_cbe_tmp__3397;
  } else {
    goto llvm_cbe_tmp__3398;
  }

llvm_cbe_tmp__3397:
  *(&llvm_cbe_eqsize) = 4096u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3398:
  llvm_cbe_tmp__3362 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3363 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3362) > ((unsigned int )4096u)) & (((unsigned int )llvm_cbe_tmp__3363) <= ((unsigned int )8192u)))&1))) {
    goto llvm_cbe_tmp__3399;
  } else {
    goto llvm_cbe_tmp__3400;
  }

llvm_cbe_tmp__3399:
  *(&llvm_cbe_eqsize) = 8192u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3400:
  llvm_cbe_tmp__3364 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3365 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3364) > ((unsigned int )8192u)) & (((unsigned int )llvm_cbe_tmp__3365) <= ((unsigned int )16384u)))&1))) {
    goto llvm_cbe_tmp__3401;
  } else {
    goto llvm_cbe_tmp__3402;
  }

llvm_cbe_tmp__3401:
  *(&llvm_cbe_eqsize) = 16384u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3402:
  llvm_cbe_tmp__3366 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3367 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3366) > ((unsigned int )16384u)) & (((unsigned int )llvm_cbe_tmp__3367) <= ((unsigned int )32768u)))&1))) {
    goto llvm_cbe_tmp__3403;
  } else {
    goto llvm_cbe_tmp__3404;
  }

llvm_cbe_tmp__3403:
  *(&llvm_cbe_eqsize) = 32768u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3404:
  llvm_cbe_tmp__3368 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3369 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3368) > ((unsigned int )32768u)) & (((unsigned int )llvm_cbe_tmp__3369) <= ((unsigned int )65536u)))&1))) {
    goto llvm_cbe_tmp__3405;
  } else {
    goto llvm_cbe_tmp__3374;
  }

llvm_cbe_tmp__3405:
  *(&llvm_cbe_eqsize) = 65536u;
  goto llvm_cbe_tmp__3374;

llvm_cbe_tmp__3374:
  llvm_cbe_tmp__3370 = *(&llvm_cbe_eqsize);
  llvm_cbe_tmp__3371 = __CPROVER_malloc((((unsigned long long )(((unsigned long long )1ull) * ((unsigned long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3370)))))));
  *((&llvm_cbe_tmp__3337->field0)) = llvm_cbe_tmp__3371;
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3406;    /* Address-exposed local */
  unsigned int llvm_cbe_eqsize;    /* Address-exposed local */
  unsigned int llvm_cbe_acsize;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__3407;
  unsigned int llvm_cbe_tmp__3408;
  unsigned int llvm_cbe_tmp__3409;
  unsigned int llvm_cbe_tmp__3410;
  unsigned int llvm_cbe_tmp__3411;
  unsigned int llvm_cbe_tmp__3412;
  unsigned int llvm_cbe_tmp__3413;
  unsigned int llvm_cbe_tmp__3414;
  unsigned int llvm_cbe_tmp__3415;
  unsigned int llvm_cbe_tmp__3416;
  unsigned int llvm_cbe_tmp__3417;
  unsigned int llvm_cbe_tmp__3418;
  unsigned int llvm_cbe_tmp__3419;
  unsigned int llvm_cbe_tmp__3420;
  unsigned int llvm_cbe_tmp__3421;
  unsigned int llvm_cbe_tmp__3422;
  unsigned int llvm_cbe_tmp__3423;
  unsigned int llvm_cbe_tmp__3424;
  unsigned int llvm_cbe_tmp__3425;
  unsigned int llvm_cbe_tmp__3426;
  unsigned int llvm_cbe_tmp__3427;
  unsigned int llvm_cbe_tmp__3428;
  unsigned int llvm_cbe_tmp__3429;
  unsigned int llvm_cbe_tmp__3430;
  unsigned int llvm_cbe_tmp__3431;
  unsigned int llvm_cbe_tmp__3432;
  unsigned int llvm_cbe_tmp__3433;
  unsigned int llvm_cbe_tmp__3434;
  unsigned int llvm_cbe_tmp__3435;
  unsigned int llvm_cbe_tmp__3436;
  unsigned int llvm_cbe_tmp__3437;
  unsigned int llvm_cbe_tmp__3438;
  unsigned int llvm_cbe_tmp__3439;
  unsigned int llvm_cbe_tmp__3440;
  unsigned char *llvm_cbe_tmp__3441;

  *(&llvm_cbe_tmp__3406) = llvm_cbe_this;
  llvm_cbe_tmp__3407 = *(&llvm_cbe_tmp__3406);
  *(&llvm_cbe_acsize) = 50601u;
  llvm_cbe_tmp__3408 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3408 == 1u)) {
    goto llvm_cbe_tmp__3442;
  } else {
    goto llvm_cbe_tmp__3443;
  }

llvm_cbe_tmp__3442:
  *(&llvm_cbe_eqsize) = 1u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3443:
  llvm_cbe_tmp__3409 = *(&llvm_cbe_acsize);
  if ((llvm_cbe_tmp__3409 == 2u)) {
    goto llvm_cbe_tmp__3445;
  } else {
    goto llvm_cbe_tmp__3446;
  }

llvm_cbe_tmp__3445:
  *(&llvm_cbe_eqsize) = 2u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3446:
  llvm_cbe_tmp__3410 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3411 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3410) > ((unsigned int )2u)) & (((unsigned int )llvm_cbe_tmp__3411) <= ((unsigned int )4u)))&1))) {
    goto llvm_cbe_tmp__3447;
  } else {
    goto llvm_cbe_tmp__3448;
  }

llvm_cbe_tmp__3447:
  *(&llvm_cbe_eqsize) = 4u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3448:
  llvm_cbe_tmp__3412 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3413 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3412) > ((unsigned int )4u)) & (((unsigned int )llvm_cbe_tmp__3413) <= ((unsigned int )8u)))&1))) {
    goto llvm_cbe_tmp__3449;
  } else {
    goto llvm_cbe_tmp__3450;
  }

llvm_cbe_tmp__3449:
  *(&llvm_cbe_eqsize) = 8u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3450:
  llvm_cbe_tmp__3414 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3415 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3414) > ((unsigned int )8u)) & (((unsigned int )llvm_cbe_tmp__3415) <= ((unsigned int )16u)))&1))) {
    goto llvm_cbe_tmp__3451;
  } else {
    goto llvm_cbe_tmp__3452;
  }

llvm_cbe_tmp__3451:
  *(&llvm_cbe_eqsize) = 16u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3452:
  llvm_cbe_tmp__3416 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3417 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3416) > ((unsigned int )16u)) & (((unsigned int )llvm_cbe_tmp__3417) <= ((unsigned int )32u)))&1))) {
    goto llvm_cbe_tmp__3453;
  } else {
    goto llvm_cbe_tmp__3454;
  }

llvm_cbe_tmp__3453:
  *(&llvm_cbe_eqsize) = 32u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3454:
  llvm_cbe_tmp__3418 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3419 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3418) > ((unsigned int )32u)) & (((unsigned int )llvm_cbe_tmp__3419) <= ((unsigned int )64u)))&1))) {
    goto llvm_cbe_tmp__3455;
  } else {
    goto llvm_cbe_tmp__3456;
  }

llvm_cbe_tmp__3455:
  *(&llvm_cbe_eqsize) = 64u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3456:
  llvm_cbe_tmp__3420 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3421 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3420) > ((unsigned int )64u)) & (((unsigned int )llvm_cbe_tmp__3421) <= ((unsigned int )128u)))&1))) {
    goto llvm_cbe_tmp__3457;
  } else {
    goto llvm_cbe_tmp__3458;
  }

llvm_cbe_tmp__3457:
  *(&llvm_cbe_eqsize) = 128u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3458:
  llvm_cbe_tmp__3422 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3423 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3422) > ((unsigned int )128u)) & (((unsigned int )llvm_cbe_tmp__3423) <= ((unsigned int )256u)))&1))) {
    goto llvm_cbe_tmp__3459;
  } else {
    goto llvm_cbe_tmp__3460;
  }

llvm_cbe_tmp__3459:
  *(&llvm_cbe_eqsize) = 256u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3460:
  llvm_cbe_tmp__3424 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3425 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3424) > ((unsigned int )256u)) & (((unsigned int )llvm_cbe_tmp__3425) <= ((unsigned int )512u)))&1))) {
    goto llvm_cbe_tmp__3461;
  } else {
    goto llvm_cbe_tmp__3462;
  }

llvm_cbe_tmp__3461:
  *(&llvm_cbe_eqsize) = 512u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3462:
  llvm_cbe_tmp__3426 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3427 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3426) > ((unsigned int )512u)) & (((unsigned int )llvm_cbe_tmp__3427) <= ((unsigned int )1024u)))&1))) {
    goto llvm_cbe_tmp__3463;
  } else {
    goto llvm_cbe_tmp__3464;
  }

llvm_cbe_tmp__3463:
  *(&llvm_cbe_eqsize) = 1024u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3464:
  llvm_cbe_tmp__3428 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3429 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3428) > ((unsigned int )1024u)) & (((unsigned int )llvm_cbe_tmp__3429) <= ((unsigned int )2048u)))&1))) {
    goto llvm_cbe_tmp__3465;
  } else {
    goto llvm_cbe_tmp__3466;
  }

llvm_cbe_tmp__3465:
  *(&llvm_cbe_eqsize) = 2048u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3466:
  llvm_cbe_tmp__3430 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3431 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3430) > ((unsigned int )2048u)) & (((unsigned int )llvm_cbe_tmp__3431) <= ((unsigned int )4096u)))&1))) {
    goto llvm_cbe_tmp__3467;
  } else {
    goto llvm_cbe_tmp__3468;
  }

llvm_cbe_tmp__3467:
  *(&llvm_cbe_eqsize) = 4096u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3468:
  llvm_cbe_tmp__3432 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3433 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3432) > ((unsigned int )4096u)) & (((unsigned int )llvm_cbe_tmp__3433) <= ((unsigned int )8192u)))&1))) {
    goto llvm_cbe_tmp__3469;
  } else {
    goto llvm_cbe_tmp__3470;
  }

llvm_cbe_tmp__3469:
  *(&llvm_cbe_eqsize) = 8192u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3470:
  llvm_cbe_tmp__3434 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3435 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3434) > ((unsigned int )8192u)) & (((unsigned int )llvm_cbe_tmp__3435) <= ((unsigned int )16384u)))&1))) {
    goto llvm_cbe_tmp__3471;
  } else {
    goto llvm_cbe_tmp__3472;
  }

llvm_cbe_tmp__3471:
  *(&llvm_cbe_eqsize) = 16384u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3472:
  llvm_cbe_tmp__3436 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3437 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3436) > ((unsigned int )16384u)) & (((unsigned int )llvm_cbe_tmp__3437) <= ((unsigned int )32768u)))&1))) {
    goto llvm_cbe_tmp__3473;
  } else {
    goto llvm_cbe_tmp__3474;
  }

llvm_cbe_tmp__3473:
  *(&llvm_cbe_eqsize) = 32768u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3474:
  llvm_cbe_tmp__3438 = *(&llvm_cbe_acsize);
  llvm_cbe_tmp__3439 = *(&llvm_cbe_acsize);
  if (((((((unsigned int )llvm_cbe_tmp__3438) > ((unsigned int )32768u)) & (((unsigned int )llvm_cbe_tmp__3439) <= ((unsigned int )65536u)))&1))) {
    goto llvm_cbe_tmp__3475;
  } else {
    goto llvm_cbe_tmp__3444;
  }

llvm_cbe_tmp__3475:
  *(&llvm_cbe_eqsize) = 65536u;
  goto llvm_cbe_tmp__3444;

llvm_cbe_tmp__3444:
  llvm_cbe_tmp__3440 = *(&llvm_cbe_eqsize);
  llvm_cbe_tmp__3441 = __CPROVER_malloc((((unsigned long long )(((unsigned long long )4ull) * ((unsigned long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__3440)))))));
  *((&llvm_cbe_tmp__3407->field0)) = (((float *)llvm_cbe_tmp__3441));
  return;
}


void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3476;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3477;
  unsigned char *llvm_cbe_tmp__3478;

  *(&llvm_cbe_tmp__3476) = llvm_cbe_this;
  llvm_cbe_tmp__3477 = *(&llvm_cbe_tmp__3476);
  llvm_cbe_tmp__3478 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3477->field0)) = llvm_cbe_tmp__3478;
  return;
}


void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3479;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3480;
  unsigned char *llvm_cbe_tmp__3481;

  *(&llvm_cbe_tmp__3479) = llvm_cbe_this;
  llvm_cbe_tmp__3480 = *(&llvm_cbe_tmp__3479);
  llvm_cbe_tmp__3481 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3480->field0)) = llvm_cbe_tmp__3481;
  return;
}


void _ZN13SysCArray2DstIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2Dst *llvm_cbe_this) {
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3482;    /* Address-exposed local */
  struct l_class_OC_SysCArray2Dst *llvm_cbe_tmp__3483;
  unsigned char *llvm_cbe_tmp__3484;
  unsigned char *llvm_cbe_tmp__3485;

  *(&llvm_cbe_tmp__3482) = llvm_cbe_this;
  llvm_cbe_tmp__3483 = *(&llvm_cbe_tmp__3482);
  llvm_cbe_tmp__3484 = __CPROVER_malloc(1024ull);
  *((&llvm_cbe_tmp__3483->field0)) = llvm_cbe_tmp__3484;
  llvm_cbe_tmp__3485 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3483->field1)) = llvm_cbe_tmp__3485;
  return;
}


void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3486;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3487;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__3488;

  *(&llvm_cbe_tmp__3486) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3487) = llvm_cbe_p;
  llvm_cbe_tmp__3488 = *(&llvm_cbe_tmp__3486);
  return;
}


void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3489;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3490;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__3491;

  *(&llvm_cbe_tmp__3489) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3490) = llvm_cbe_p;
  llvm_cbe_tmp__3491 = *(&llvm_cbe_tmp__3489);
  return;
}


void _ZN11model_trainD2Ev(struct l_class_OC_model_train *llvm_cbe_this) {
  struct l_class_OC_model_train *llvm_cbe_tmp__3492;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3493;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3494;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__3495;

  *(&llvm_cbe_tmp__3492) = llvm_cbe_this;
  llvm_cbe_tmp__3495 = *(&llvm_cbe_tmp__3492);
  _ZN8type_memIbLj512EED1Ev(((&llvm_cbe_tmp__3495->field33)));
  _ZN8type_memItLj8EED1Ev(((&llvm_cbe_tmp__3495->field32)));
  _ZN8type_memIhLj128EED1Ev(((&llvm_cbe_tmp__3495->field19)));
  _ZN8type_memIjLj8EED1Ev(((&llvm_cbe_tmp__3495->field17)));
  _ZN8type_memIbLj65536EED1Ev(((&llvm_cbe_tmp__3495->field16)));
  _ZN8type_memIbLj128EED1Ev(((&llvm_cbe_tmp__3495->field4)));
  _ZN8type_memIhLj65536EED1Ev(((&llvm_cbe_tmp__3495->field3)));
  _ZN8type_memIhLj512EED1Ev(((&llvm_cbe_tmp__3495->field0)));
  return;
}


void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3496;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3497;

  *(&llvm_cbe_tmp__3496) = llvm_cbe_this;
  llvm_cbe_tmp__3497 = *(&llvm_cbe_tmp__3496);
  _ZN8type_memIhLj128EED2Ev(llvm_cbe_tmp__3497);
  return;
}


void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3498;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3499;

  *(&llvm_cbe_tmp__3498) = llvm_cbe_this;
  llvm_cbe_tmp__3499 = *(&llvm_cbe_tmp__3498);
  _ZN8type_memIhLj512EED2Ev(llvm_cbe_tmp__3499);
  return;
}


void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3500;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3501;

  *(&llvm_cbe_tmp__3500) = llvm_cbe_this;
  llvm_cbe_tmp__3501 = *(&llvm_cbe_tmp__3500);
  return;
}


void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3502;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3503;

  *(&llvm_cbe_tmp__3502) = llvm_cbe_this;
  llvm_cbe_tmp__3503 = *(&llvm_cbe_tmp__3502);
  return;
}


void _ZN11model_trainC2Ev(struct l_class_OC_model_train *llvm_cbe_this) {
  struct l_class_OC_model_train *llvm_cbe_tmp__3504;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__3505;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__3506;    /* Address-exposed local */
  struct l_class_OC_model_train *llvm_cbe_tmp__3507;
  unsigned long long llvm_cbe_tmp__3508;
  unsigned long long llvm_cbe_tmp__3509;

  *(&llvm_cbe_tmp__3504) = llvm_cbe_this;
  llvm_cbe_tmp__3507 = *(&llvm_cbe_tmp__3504);
  _ZN8type_memIhLj512EEC1El(((&llvm_cbe_tmp__3507->field0)), 0ull);
  _ZN8type_memIhLj65536EEC1El(((&llvm_cbe_tmp__3507->field3)), 0ull);
  _ZN8type_memIbLj128EEC1El(((&llvm_cbe_tmp__3507->field4)), 0ull);
  _ZN8type_memIbLj65536EEC1El(((&llvm_cbe_tmp__3507->field16)), 0ull);
  _ZN8type_memIjLj8EEC1El(((&llvm_cbe_tmp__3507->field17)), 0ull);
  _ZN8type_memIhLj128EEC1El(((&llvm_cbe_tmp__3507->field19)), 0ull);
  _ZN8type_memItLj8EEC1El(((&llvm_cbe_tmp__3507->field32)), 0ull);
  _ZN8type_memIbLj512EEC1El(((&llvm_cbe_tmp__3507->field33)), 0ull);
  *((&llvm_cbe_tmp__3507->field38)) = 1ull;
  *((&llvm_cbe_tmp__3507->field39)) = 65535ull;
  *((&llvm_cbe_tmp__3507->field40)) = 7ull;
  *((&llvm_cbe_tmp__3507->field41)) = 4294967295ull;
  *((&llvm_cbe_tmp__3507->field42)) = ((unsigned long long )/*UNDEF*/0);
  *((&llvm_cbe_tmp__3507->field43)) = 127ull;
  *((&llvm_cbe_tmp__3507->field44)) = 255ull;
  *((&llvm_cbe_tmp__3507->field45)) = 511ull;
  *((&llvm_cbe_tmp__3507->field46)) = 32768ull;
  *((&llvm_cbe_tmp__3507->field47)) = 64ull;
  llvm_cbe_tmp__3508 = *((&llvm_cbe_tmp__3507->field39));
  *((&llvm_cbe_tmp__3507->field48)) = (llvm_cbe_tmp__3508 ^ 18446744073709551615ull);
  llvm_cbe_tmp__3509 = *((&llvm_cbe_tmp__3507->field43));
  *((&llvm_cbe_tmp__3507->field49)) = (llvm_cbe_tmp__3509 ^ 18446744073709551615ull);
  return;
}


void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3510;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3511;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3512;
  unsigned long long llvm_cbe_tmp__3513;

  *(&llvm_cbe_tmp__3510) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3511) = llvm_cbe_def;
  llvm_cbe_tmp__3512 = *(&llvm_cbe_tmp__3510);
  llvm_cbe_tmp__3513 = *(&llvm_cbe_tmp__3511);
  _ZN8type_memIhLj512EEC2El(llvm_cbe_tmp__3512, llvm_cbe_tmp__3513);
  return;
}


void _ZN8type_memIhLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3514;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3515;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3516;
  unsigned long long llvm_cbe_tmp__3517;

  *(&llvm_cbe_tmp__3514) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3515) = llvm_cbe_def;
  llvm_cbe_tmp__3516 = *(&llvm_cbe_tmp__3514);
  llvm_cbe_tmp__3517 = *(&llvm_cbe_tmp__3515);
  _ZN8type_memIhLj65536EEC2El(llvm_cbe_tmp__3516, llvm_cbe_tmp__3517);
  return;
}


void _ZN8type_memIbLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3518;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3519;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3520;
  unsigned long long llvm_cbe_tmp__3521;

  *(&llvm_cbe_tmp__3518) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3519) = llvm_cbe_def;
  llvm_cbe_tmp__3520 = *(&llvm_cbe_tmp__3518);
  llvm_cbe_tmp__3521 = *(&llvm_cbe_tmp__3519);
  _ZN8type_memIbLj128EEC2El(llvm_cbe_tmp__3520, llvm_cbe_tmp__3521);
  return;
}


void _ZN8type_memIbLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3522;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3523;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3524;
  unsigned long long llvm_cbe_tmp__3525;

  *(&llvm_cbe_tmp__3522) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3523) = llvm_cbe_def;
  llvm_cbe_tmp__3524 = *(&llvm_cbe_tmp__3522);
  llvm_cbe_tmp__3525 = *(&llvm_cbe_tmp__3523);
  _ZN8type_memIbLj65536EEC2El(llvm_cbe_tmp__3524, llvm_cbe_tmp__3525);
  return;
}


void _ZN8type_memIjLj8EEC1El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed1 *llvm_cbe_tmp__3526;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3527;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3528;
  unsigned long long llvm_cbe_tmp__3529;

  *(&llvm_cbe_tmp__3526) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3527) = llvm_cbe_def;
  llvm_cbe_tmp__3528 = *(&llvm_cbe_tmp__3526);
  llvm_cbe_tmp__3529 = *(&llvm_cbe_tmp__3527);
  _ZN8type_memIjLj8EEC2El(llvm_cbe_tmp__3528, llvm_cbe_tmp__3529);
  return;
}


void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3530;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3531;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3532;
  unsigned long long llvm_cbe_tmp__3533;

  *(&llvm_cbe_tmp__3530) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3531) = llvm_cbe_def;
  llvm_cbe_tmp__3532 = *(&llvm_cbe_tmp__3530);
  llvm_cbe_tmp__3533 = *(&llvm_cbe_tmp__3531);
  _ZN8type_memIhLj128EEC2El(llvm_cbe_tmp__3532, llvm_cbe_tmp__3533);
  return;
}


void _ZN8type_memItLj8EEC1El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed2 *llvm_cbe_tmp__3534;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3535;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3536;
  unsigned long long llvm_cbe_tmp__3537;

  *(&llvm_cbe_tmp__3534) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3535) = llvm_cbe_def;
  llvm_cbe_tmp__3536 = *(&llvm_cbe_tmp__3534);
  llvm_cbe_tmp__3537 = *(&llvm_cbe_tmp__3535);
  _ZN8type_memItLj8EEC2El(llvm_cbe_tmp__3536, llvm_cbe_tmp__3537);
  return;
}


void _ZN8type_memIbLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3538;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3539;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3540;
  unsigned long long llvm_cbe_tmp__3541;

  *(&llvm_cbe_tmp__3538) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3539) = llvm_cbe_def;
  llvm_cbe_tmp__3540 = *(&llvm_cbe_tmp__3538);
  llvm_cbe_tmp__3541 = *(&llvm_cbe_tmp__3539);
  _ZN8type_memIbLj512EEC2El(llvm_cbe_tmp__3540, llvm_cbe_tmp__3541);
  return;
}


void _ZN8type_memIbLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3542;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3543;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3544;
  unsigned char *llvm_cbe_tmp__3545;

  *(&llvm_cbe_tmp__3542) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3543) = llvm_cbe_def;
  llvm_cbe_tmp__3544 = *(&llvm_cbe_tmp__3542);
  llvm_cbe_tmp__3545 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3544->field0)) = llvm_cbe_tmp__3545;
  return;
}


void _ZN8type_memItLj8EEC2El(struct l_unnamed2 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed2 *llvm_cbe_tmp__3546;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3547;    /* Address-exposed local */
  struct l_unnamed2 *llvm_cbe_tmp__3548;
  unsigned char *llvm_cbe_tmp__3549;

  *(&llvm_cbe_tmp__3546) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3547) = llvm_cbe_def;
  llvm_cbe_tmp__3548 = *(&llvm_cbe_tmp__3546);
  llvm_cbe_tmp__3549 = __CPROVER_malloc(16ull);
  *((&llvm_cbe_tmp__3548->field0)) = (((unsigned short *)llvm_cbe_tmp__3549));
  return;
}


void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3550;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3551;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3552;
  unsigned char *llvm_cbe_tmp__3553;

  *(&llvm_cbe_tmp__3550) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3551) = llvm_cbe_def;
  llvm_cbe_tmp__3552 = *(&llvm_cbe_tmp__3550);
  llvm_cbe_tmp__3553 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3552->field0)) = llvm_cbe_tmp__3553;
  return;
}


void _ZN8type_memIjLj8EEC2El(struct l_unnamed1 *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_unnamed1 *llvm_cbe_tmp__3554;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3555;    /* Address-exposed local */
  struct l_unnamed1 *llvm_cbe_tmp__3556;
  unsigned char *llvm_cbe_tmp__3557;

  *(&llvm_cbe_tmp__3554) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3555) = llvm_cbe_def;
  llvm_cbe_tmp__3556 = *(&llvm_cbe_tmp__3554);
  llvm_cbe_tmp__3557 = __CPROVER_malloc(32ull);
  *((&llvm_cbe_tmp__3556->field0)) = (((unsigned int *)llvm_cbe_tmp__3557));
  return;
}


void _ZN8type_memIbLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3558;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3559;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3560;
  unsigned char *llvm_cbe_tmp__3561;

  *(&llvm_cbe_tmp__3558) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3559) = llvm_cbe_def;
  llvm_cbe_tmp__3560 = *(&llvm_cbe_tmp__3558);
  llvm_cbe_tmp__3561 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3560->field0)) = llvm_cbe_tmp__3561;
  return;
}


void _ZN8type_memIbLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3562;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3563;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3564;
  unsigned char *llvm_cbe_tmp__3565;

  *(&llvm_cbe_tmp__3562) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3563) = llvm_cbe_def;
  llvm_cbe_tmp__3564 = *(&llvm_cbe_tmp__3562);
  llvm_cbe_tmp__3565 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__3564->field0)) = llvm_cbe_tmp__3565;
  return;
}


void _ZN8type_memIhLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3566;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3567;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3568;
  unsigned char *llvm_cbe_tmp__3569;

  *(&llvm_cbe_tmp__3566) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3567) = llvm_cbe_def;
  llvm_cbe_tmp__3568 = *(&llvm_cbe_tmp__3566);
  llvm_cbe_tmp__3569 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__3568->field0)) = llvm_cbe_tmp__3569;
  return;
}


void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3570;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3571;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__3572;
  unsigned char *llvm_cbe_tmp__3573;

  *(&llvm_cbe_tmp__3570) = llvm_cbe_this;
  *(&llvm_cbe_tmp__3571) = llvm_cbe_def;
  llvm_cbe_tmp__3572 = *(&llvm_cbe_tmp__3570);
  llvm_cbe_tmp__3573 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__3572->field0)) = llvm_cbe_tmp__3573;
  return;
}


static void _GLOBAL__I_a(void) {
  __cxx_global_var_init();
  __cxx_global_var_init32();
  return;
}

