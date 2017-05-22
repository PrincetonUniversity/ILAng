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
struct l_class_OC_model_RBM;
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
struct l_unnamed2;
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
typedef struct l_class_OC_model_RBM l_class_OC_model_RBM;
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
typedef struct l_unnamed2 l_unnamed2;
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
  unsigned char *field0;
  unsigned char *field1;
};

struct l_class_OC_model_RBM {
  struct l_class_OC_SysCArray1D field0;
  unsigned long long field1;
  unsigned long long field2;
  unsigned long long field3;
  unsigned long long field4;
  unsigned long long field5;
  unsigned long long field6;
  unsigned long long field7;
  unsigned long long field8;
  unsigned long long field9;
  struct l_class_OC_SysCArray1D field10;
  unsigned long long field11;
  unsigned long long field12;
  unsigned long long field13;
  unsigned long long field14;
  unsigned long long field15;
  unsigned long long field16;
  unsigned long long field17;
  unsigned long long field18;
  unsigned long long field19;
  unsigned long long field20;
  unsigned long long field21;
  unsigned long long field22;
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

struct l_unnamed3 {
  float *field0;
  float *field1;
};

struct l_unnamed4 {
  float *field0;
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
  struct l_class_OC_SysCArray2D field20;
  struct l_class_OC_SysCArray1D field21;
  struct l_class_OC_SysCArray1D field22;
  struct l_unnamed3 field23;
  struct l_class_OC_SysCArray2D field24;
  struct l_class_OC_SysCArray2D field25;
  struct l_unnamed4 field26;
  struct l_class_OC_SysCArray1D field27;
  struct l_class_OC_SysCArray2D field28;
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

struct l_unnamed0 { unsigned char array[16]; };

struct l_unnamed1 { unsigned char array[11]; };

struct l_unnamed10 { unsigned char array[20]; };

struct l_unnamed11 { unsigned char array[21]; };

struct l_unnamed12 { unsigned char array[4]; };

struct l_unnamed13 { unsigned char array[9]; };

struct l_unnamed14 { unsigned char array[10]; };

struct l_unnamed15 { unsigned char array[8]; };

struct l_unnamed16 { unsigned char array[5]; };

struct l_unnamed17 { unsigned char array[19]; };

struct l_unnamed5 {
  unsigned int field0;
  void  (*field1) (void);
};

struct l_unnamed18 { struct l_unnamed5 array[1]; };

struct l_unnamed2 { unsigned char array[15]; };

struct l_unnamed7 { unsigned char array[12]; };

struct l_unnamed8 { unsigned char array[17]; };

struct l_unnamed9 { unsigned char array[18]; };


/* External Global Variable Declarations */
extern struct l_class_OC_model_RBM GM;
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
extern struct l_struct_OC_rbm IMPL;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
struct l_class_OC_SysCArray1D _ZN9model_RBM17cppUpdateFun_dataElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIhLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int __gxx_personality_v0(int vararg_dummy_arg,...);
void _Unwind_Resume_or_Rethrow(unsigned char *);
struct l_class_OC_SysCArray1D *_ZN8type_memIhLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZSt9terminatev(void);
unsigned long long _ZN9model_RBM21cppUpdateFun_data_outElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN8type_memIhLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
unsigned long long _ZN9model_RBM17cppUpdateFun_doneElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM22cppUpdateFun_init_doneElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM23cppUpdateFun_num_hiddenElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM22cppUpdateFun_num_loopsElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM23cppUpdateFun_num_moviesElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM26cppUpdateFun_num_testusersElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM22cppUpdateFun_num_usersElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM24cppUpdateFun_num_visibleElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM24cppUpdateFun_rd_completeElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM23cppUpdateFun_rd_grantedElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM21cppUpdateFun_rd_indexElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM22cppUpdateFun_rd_lengthElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM23cppUpdateFun_rd_requestElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM24cppUpdateFun_wr_completeElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM23cppUpdateFun_wr_grantedElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM21cppUpdateFun_wr_indexElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM22cppUpdateFun_wr_lengthElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN9model_RBM23cppUpdateFun_wr_requestElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN9model_RBM6updateElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
static void __cxx_global_var_init(void);
void _ZN9model_RBMC1Ev(struct l_class_OC_model_RBM *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN9model_RBMD1Ev(struct l_class_OC_model_RBM *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int __cxa_atexit(void  (*) (unsigned char *), unsigned char *, unsigned char *);
void _Z4waitv(void);
void _Z15reset_signal_isib(unsigned int , bool );
void _Z14set_stack_sizei(unsigned int );
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
unsigned char *_ZN11SysCArray2DIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this);
void __CPROVER_array_copy(unsigned char *, unsigned char *);
unsigned char *_ZN11SysCArray2DIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void __CPROVER_assert(bool , unsigned char *);
bool __CPROVER_array_equal(unsigned char *, unsigned char *);
static void __cxx_global_var_init17(void);
void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int main(void);
void _ZN8type_memIhLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned char *__CPROVER_malloc(unsigned long long );
void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_unnamed3 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_unnamed4 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_unnamed4 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_unnamed3 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN9model_RBMD2Ev(struct l_class_OC_model_RBM *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN9model_RBMC2Ev(struct l_class_OC_model_RBM *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
static void _GLOBAL__I_a(void) __ATTRIBUTE_CTOR__;
void abort(void);


/* Global Variable Declarations */
extern struct l_class_OC_model_RBM GM;
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
static struct l_unnamed7 _OC_str;
static struct l_unnamed0 _OC_str1;
static struct l_unnamed1 _OC_str2;
static struct l_unnamed8 _OC_str3;
static struct l_unnamed9 _OC_str4;
static struct l_unnamed0 _OC_str5;
static struct l_unnamed0 _OC_str6;
static struct l_unnamed10 _OC_str7;
static struct l_unnamed8 _OC_str8;
static struct l_unnamed2 _OC_str9;
static struct l_unnamed0 _OC_str10;
static struct l_unnamed8 _OC_str11;
static struct l_unnamed2 _OC_str12;
static struct l_unnamed0 _OC_str13;
static struct l_unnamed2 _OC_str14;
static struct l_unnamed1 _OC_str15;
static struct l_unnamed11 _OC_str16;
extern struct l_struct_OC_rbm IMPL;
static struct l_unnamed12 _OC_str18;
static struct l_unnamed12 _OC_str19;
static struct l_unnamed13 _OC_str20;
static struct l_unnamed14 _OC_str21;
static struct l_unnamed1 _OC_str22;
static struct l_unnamed13 _OC_str23;
static struct l_unnamed15 _OC_str24;
static struct l_unnamed13 _OC_str25;
static struct l_unnamed14 _OC_str26;
static struct l_unnamed1 _OC_str27;
static struct l_unnamed13 _OC_str28;
static struct l_unnamed13 _OC_str29;
static struct l_unnamed16 _OC_str30;
static struct l_unnamed14 _OC_str31;
static struct l_unnamed0 _OC_str32;
static struct l_unnamed8 _OC_str33;
static struct l_unnamed2 _OC_str34;
static struct l_unnamed2 _OC_str35;
static struct l_unnamed17 _OC_str36;
static struct l_unnamed0 _OC_str37;


/* Global Variable Definitions and Initialization */
struct l_class_OC_model_RBM GM;
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
static struct l_unnamed7 _OC_str = { "Config done" };
static struct l_unnamed0 _OC_str1 = { "init_done_match" };
static struct l_unnamed1 _OC_str2 = { "done_match" };
static struct l_unnamed8 _OC_str3 = { "num_hidden_match" };
static struct l_unnamed9 _OC_str4 = { "num_visible_match" };
static struct l_unnamed0 _OC_str5 = { "num_users_match" };
static struct l_unnamed0 _OC_str6 = { "num_loops_match" };
static struct l_unnamed10 _OC_str7 = { "num_testusers_match" };
static struct l_unnamed8 _OC_str8 = { "num_movies_match" };
static struct l_unnamed2 _OC_str9 = { "rd_index_match" };
static struct l_unnamed0 _OC_str10 = { "rd_length_match" };
static struct l_unnamed8 _OC_str11 = { "rd_request_match" };
static struct l_unnamed2 _OC_str12 = { "wr_index_match" };
static struct l_unnamed0 _OC_str13 = { "wr_length_match" };
static struct l_unnamed2 _OC_str14 = { "data_out_match" };
static struct l_unnamed1 _OC_str15 = { "data_match" };
static struct l_unnamed11 _OC_str16 = { "predict_result_match" };
struct l_struct_OC_rbm IMPL;
static struct l_unnamed12 _OC_str18 = { "clk" };
static struct l_unnamed12 _OC_str19 = { "rst" };
static struct l_unnamed13 _OC_str20 = { "rd_index" };
static struct l_unnamed14 _OC_str21 = { "rd_length" };
static struct l_unnamed1 _OC_str22 = { "rd_request" };
static struct l_unnamed13 _OC_str23 = { "rd_grant" };
static struct l_unnamed15 _OC_str24 = { "data_in" };
static struct l_unnamed13 _OC_str25 = { "wr_index" };
static struct l_unnamed14 _OC_str26 = { "wr_length" };
static struct l_unnamed1 _OC_str27 = { "wr_request" };
static struct l_unnamed13 _OC_str28 = { "wr_grant" };
static struct l_unnamed13 _OC_str29 = { "data_out" };
static struct l_unnamed16 _OC_str30 = { "done" };
static struct l_unnamed14 _OC_str31 = { "cond_done" };
static struct l_unnamed0 _OC_str32 = { "conf_num_hidden" };
static struct l_unnamed8 _OC_str33 = { "conf_num_visible" };
static struct l_unnamed2 _OC_str34 = { "conf_num_users" };
static struct l_unnamed2 _OC_str35 = { "conf_num_loops" };
static struct l_unnamed17 _OC_str36 = { "conf_num_testusers" };
static struct l_unnamed0 _OC_str37 = { "conf_num_movies" };


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

struct l_class_OC_SysCArray1D _ZN9model_RBM17cppUpdateFun_dataElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_RBM *llvm_cbe_tmp__1;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__2;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__3;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__4;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__5;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__6;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__7;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__8;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__9;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__10;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__11;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__12;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_174;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_175;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_176;    /* Address-exposed local */
  bool llvm_cbe_tmp__13;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__14;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__15;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_169;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_170;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_171;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_172;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_173;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__16;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__17;
  unsigned long long llvm_cbe_tmp__18;
  unsigned long long llvm_cbe_tmp__19;
  unsigned char llvm_cbe_tmp__20;
  unsigned char llvm_cbe_tmp__21;
  bool llvm_cbe_tmp__22;
  bool llvm_cbe_tmp__23;
  bool llvm_cbe_tmp__23__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__24;
  unsigned long long llvm_cbe_tmp__25;
  unsigned long long llvm_cbe_tmp__26;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__27;
  unsigned long long llvm_cbe_tmp__28;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__29;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__30;
  bool llvm_cbe_tmp__31;

  *(&llvm_cbe_tmp__1) = llvm_cbe_this;
  *(&llvm_cbe_tmp__2) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__3) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__4) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__5) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__6) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__7) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__8) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__9) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__10) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__11) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__12) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__17 = *(&llvm_cbe_tmp__1);
  _ZN8type_memIhLj512EEC1Ev((&llvm_cbe_cppVar_176));
  *(&llvm_cbe_tmp__13) = ((0) & 1);
  _ZN8type_memIhLj512EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__18 = *((&llvm_cbe_tmp__17->field15));
  *(&llvm_cbe_cppVar_170) = (((unsigned char )(bool )(llvm_cbe_tmp__18 == 1ull)));
  llvm_cbe_tmp__19 = *(&llvm_cbe_tmp__10);
  *(&llvm_cbe_cppVar_172) = (((unsigned char )(bool )(llvm_cbe_tmp__19 == 1ull)));
  llvm_cbe_tmp__20 = *(&llvm_cbe_cppVar_170);
  if ((((((bool )llvm_cbe_tmp__20&1u))&1))) {
    goto llvm_cbe_tmp__32;
  } else {
    llvm_cbe_tmp__23__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__33;
  }

llvm_cbe_tmp__32:
  llvm_cbe_tmp__21 = *(&llvm_cbe_cppVar_172);
  llvm_cbe_tmp__22 = ((((bool )llvm_cbe_tmp__21&1u))&1);
  llvm_cbe_tmp__23__PHI_TEMPORARY = llvm_cbe_tmp__22;   /* for PHI node */
  goto llvm_cbe_tmp__33;

llvm_cbe_tmp__33:
  llvm_cbe_tmp__23 = ((llvm_cbe_tmp__23__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_173) = (((unsigned char )(bool )llvm_cbe_tmp__23));
  llvm_cbe_tmp__24 = *(&llvm_cbe_cppVar_173);
  if ((((((bool )llvm_cbe_tmp__24&1u))&1))) {
    goto llvm_cbe_tmp__34;
  } else {
    goto llvm_cbe_tmp__35;
  }

llvm_cbe_tmp__34:
  llvm_cbe_tmp__25 = *(&llvm_cbe_tmp__9);
  llvm_cbe_tmp__26 = *((&llvm_cbe_tmp__17->field22));
  *(&llvm_cbe_cppVar_175) = ((((signed long long )(((signed long long )llvm_cbe_tmp__25) >> ((signed long long )0ull)))) & llvm_cbe_tmp__26);
  llvm_cbe_tmp__27 = _ZN8type_memIhLj512EEaSERKS0_((&llvm_cbe_cppVar_176), ((&llvm_cbe_tmp__17->field0)));
  llvm_cbe_tmp__28 = *(&llvm_cbe_cppVar_175);
  _ZN8type_memIhLj512EE2wrEll((&llvm_cbe_cppVar_176), 0ull, llvm_cbe_tmp__28);
  llvm_cbe_tmp__29 = _ZN8type_memIhLj512EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_176));
  goto llvm_cbe_tmp__36;

llvm_cbe_tmp__35:
  llvm_cbe_tmp__30 = _ZN8type_memIhLj512EEaSERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__17->field0)));
  goto llvm_cbe_tmp__36;

llvm_cbe_tmp__36:
  *(&llvm_cbe_tmp__13) = ((1) & 1);
  *(&llvm_cbe_tmp__16) = 1u;
  llvm_cbe_tmp__31 = ((*(&llvm_cbe_tmp__13))&1);
  if (llvm_cbe_tmp__31) {
    goto llvm_cbe_tmp__37;
  } else {
    goto llvm_cbe_tmp__38;
  }

llvm_cbe_tmp__38:
  _ZN8type_memIhLj512EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__37;

llvm_cbe_tmp__37:
  _ZN8type_memIhLj512EED1Ev((&llvm_cbe_cppVar_176));
  return StructReturn;
}


void _ZN8type_memIhLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__39;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__40;

  *(&llvm_cbe_tmp__39) = llvm_cbe_this;
  llvm_cbe_tmp__40 = *(&llvm_cbe_tmp__39);
  _ZN8type_memIhLj512EEC2Ev(llvm_cbe_tmp__40);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIhLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__41;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__42;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__43;
  unsigned char *llvm_cbe_tmp__44;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__45;
  unsigned char *llvm_cbe_tmp__46;

  *(&llvm_cbe_tmp__41) = llvm_cbe_this;
  *(&llvm_cbe_tmp__42) = llvm_cbe_r;
  llvm_cbe_tmp__43 = *(&llvm_cbe_tmp__41);
  llvm_cbe_tmp__44 = *((&llvm_cbe_tmp__43->field0));
  llvm_cbe_tmp__45 = *(&llvm_cbe_tmp__42);
  llvm_cbe_tmp__46 = *((&llvm_cbe_tmp__45->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__44, llvm_cbe_tmp__46);
  return llvm_cbe_tmp__43;
}


void _ZN8type_memIhLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__47;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__48;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__49;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__50;
  unsigned long long llvm_cbe_tmp__51;
  unsigned long long llvm_cbe_tmp__52;
  unsigned char *llvm_cbe_tmp__53;

  *(&llvm_cbe_tmp__47) = llvm_cbe_this;
  *(&llvm_cbe_tmp__48) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__49) = llvm_cbe_data;
  llvm_cbe_tmp__50 = *(&llvm_cbe_tmp__47);
  llvm_cbe_tmp__51 = *(&llvm_cbe_tmp__49);
  llvm_cbe_tmp__52 = *(&llvm_cbe_tmp__48);
  llvm_cbe_tmp__53 = *((&llvm_cbe_tmp__50->field0));
  *((&llvm_cbe_tmp__53[((signed long long )llvm_cbe_tmp__52)])) = (((unsigned char )llvm_cbe_tmp__51));
  return;
}


void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__54;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__55;

  *(&llvm_cbe_tmp__54) = llvm_cbe_this;
  llvm_cbe_tmp__55 = *(&llvm_cbe_tmp__54);
  _ZN8type_memIhLj512EED2Ev(llvm_cbe_tmp__55);
  return;
}


unsigned long long _ZN9model_RBM21cppUpdateFun_data_outElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__56;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__57;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__58;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__59;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__60;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__61;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__62;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__63;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__64;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__65;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__66;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__67;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_36;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_37;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_38;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_33;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_34;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_35;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_32;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__68;
  unsigned long long llvm_cbe_tmp__69;
  unsigned long long llvm_cbe_tmp__70;
  unsigned long long llvm_cbe_tmp__71;
  unsigned char llvm_cbe_tmp__72;
  unsigned long long llvm_cbe_tmp__73;
  unsigned long long llvm_cbe_tmp__74;
  unsigned long long llvm_cbe_tmp__75;
  unsigned long long llvm_cbe_tmp__76;
  unsigned long long llvm_cbe_tmp__77;
  unsigned long long llvm_cbe_tmp__78;

  *(&llvm_cbe_tmp__56) = llvm_cbe_this;
  *(&llvm_cbe_tmp__57) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__58) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__59) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__60) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__61) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__62) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__63) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__64) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__65) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__66) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__67) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__68 = *(&llvm_cbe_tmp__56);
  llvm_cbe_tmp__69 = *((&llvm_cbe_tmp__68->field20));
  llvm_cbe_tmp__70 = *(&llvm_cbe_tmp__67);
  *(&llvm_cbe_cppVar_33) = (llvm_cbe_tmp__69 & llvm_cbe_tmp__70);
  llvm_cbe_tmp__71 = *(&llvm_cbe_cppVar_33);
  *(&llvm_cbe_cppVar_35) = (((unsigned char )(bool )(llvm_cbe_tmp__71 == 1ull)));
  llvm_cbe_tmp__72 = *(&llvm_cbe_cppVar_35);
  if ((((((bool )llvm_cbe_tmp__72&1u))&1))) {
    goto llvm_cbe_tmp__79;
  } else {
    goto llvm_cbe_tmp__80;
  }

llvm_cbe_tmp__79:
  llvm_cbe_tmp__73 = _ZN8type_memIhLj128EE2rdEl(((&llvm_cbe_tmp__68->field10)), 0ull);
  *(&llvm_cbe_cppVar_37) = llvm_cbe_tmp__73;
  llvm_cbe_tmp__74 = *(&llvm_cbe_cppVar_37);
  llvm_cbe_tmp__75 = *((&llvm_cbe_tmp__68->field22));
  *(&llvm_cbe_cppVar_38) = (llvm_cbe_tmp__74 & llvm_cbe_tmp__75);
  llvm_cbe_tmp__76 = *(&llvm_cbe_cppVar_38);
  *(&llvm_cbe_cppVar_32) = llvm_cbe_tmp__76;
  goto llvm_cbe_tmp__81;

llvm_cbe_tmp__80:
  llvm_cbe_tmp__77 = *((&llvm_cbe_tmp__68->field1));
  *(&llvm_cbe_cppVar_32) = llvm_cbe_tmp__77;
  goto llvm_cbe_tmp__81;

llvm_cbe_tmp__81:
  llvm_cbe_tmp__78 = *(&llvm_cbe_cppVar_32);
  return llvm_cbe_tmp__78;
}


unsigned long long _ZN8type_memIhLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__82;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__83;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__84;
  unsigned long long llvm_cbe_tmp__85;
  unsigned char *llvm_cbe_tmp__86;
  unsigned char llvm_cbe_tmp__87;

  *(&llvm_cbe_tmp__82) = llvm_cbe_this;
  *(&llvm_cbe_tmp__83) = llvm_cbe_addr;
  llvm_cbe_tmp__84 = *(&llvm_cbe_tmp__82);
  llvm_cbe_tmp__85 = *(&llvm_cbe_tmp__83);
  llvm_cbe_tmp__86 = *((&llvm_cbe_tmp__84->field0));
  llvm_cbe_tmp__87 = *((&llvm_cbe_tmp__86[((signed long long )llvm_cbe_tmp__85)]));
  return (((unsigned long long )(unsigned char )llvm_cbe_tmp__87));
}


unsigned long long _ZN9model_RBM17cppUpdateFun_doneElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__88;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__89;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__90;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__91;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__92;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__93;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__94;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__95;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__96;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__97;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__98;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__99;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__100;
  unsigned long long llvm_cbe_tmp__101;

  *(&llvm_cbe_tmp__88) = llvm_cbe_this;
  *(&llvm_cbe_tmp__89) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__90) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__91) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__92) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__93) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__94) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__95) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__96) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__97) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__98) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__99) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__100 = *(&llvm_cbe_tmp__88);
  llvm_cbe_tmp__101 = *((&llvm_cbe_tmp__100->field2));
  return llvm_cbe_tmp__101;
}


unsigned long long _ZN9model_RBM22cppUpdateFun_init_doneElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__102;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__103;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__104;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__105;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__106;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__107;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__108;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__109;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__110;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__111;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__112;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__113;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_42;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_43;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_46;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_47;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_48;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_49;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_50;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_51;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_52;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_53;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_44;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_54;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_45;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_41;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__114;
  unsigned long long llvm_cbe_tmp__115;
  unsigned char llvm_cbe_tmp__116;
  unsigned long long llvm_cbe_tmp__117;
  unsigned long long llvm_cbe_tmp__118;
  unsigned char llvm_cbe_tmp__119;
  unsigned char llvm_cbe_tmp__120;
  bool llvm_cbe_tmp__121;
  bool llvm_cbe_tmp__122;
  bool llvm_cbe_tmp__122__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__123;
  unsigned char llvm_cbe_tmp__124;
  unsigned char llvm_cbe_tmp__125;
  bool llvm_cbe_tmp__126;
  bool llvm_cbe_tmp__127;
  bool llvm_cbe_tmp__127__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__128;
  unsigned long long llvm_cbe_tmp__129;
  unsigned long long llvm_cbe_tmp__130;
  unsigned long long llvm_cbe_tmp__131;

  *(&llvm_cbe_tmp__102) = llvm_cbe_this;
  *(&llvm_cbe_tmp__103) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__104) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__105) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__106) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__107) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__108) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__109) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__110) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__111) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__112) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__113) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__114 = *(&llvm_cbe_tmp__102);
  llvm_cbe_tmp__115 = *(&llvm_cbe_tmp__112);
  *(&llvm_cbe_cppVar_43) = (((unsigned char )(bool )(llvm_cbe_tmp__115 == 1ull)));
  llvm_cbe_tmp__116 = *(&llvm_cbe_cppVar_43);
  if ((((((bool )llvm_cbe_tmp__116&1u))&1))) {
    goto llvm_cbe_tmp__132;
  } else {
    goto llvm_cbe_tmp__133;
  }

llvm_cbe_tmp__132:
  *(&llvm_cbe_cppVar_41) = 0ull;
  goto llvm_cbe_tmp__134;

llvm_cbe_tmp__133:
  llvm_cbe_tmp__117 = *(&llvm_cbe_tmp__112);
  *(&llvm_cbe_cppVar_47) = (((unsigned char )(bool )(llvm_cbe_tmp__117 == 0ull)));
  llvm_cbe_tmp__118 = *((&llvm_cbe_tmp__114->field3));
  *(&llvm_cbe_cppVar_49) = (((unsigned char )(bool )(llvm_cbe_tmp__118 == 0ull)));
  llvm_cbe_tmp__119 = *(&llvm_cbe_cppVar_47);
  if ((((((bool )llvm_cbe_tmp__119&1u))&1))) {
    goto llvm_cbe_tmp__135;
  } else {
    llvm_cbe_tmp__122__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__136;
  }

llvm_cbe_tmp__135:
  llvm_cbe_tmp__120 = *(&llvm_cbe_cppVar_49);
  llvm_cbe_tmp__121 = ((((bool )llvm_cbe_tmp__120&1u))&1);
  llvm_cbe_tmp__122__PHI_TEMPORARY = llvm_cbe_tmp__121;   /* for PHI node */
  goto llvm_cbe_tmp__136;

llvm_cbe_tmp__136:
  llvm_cbe_tmp__122 = ((llvm_cbe_tmp__122__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_50) = (((unsigned char )(bool )llvm_cbe_tmp__122));
  llvm_cbe_tmp__123 = *(&llvm_cbe_tmp__103);
  *(&llvm_cbe_cppVar_52) = (((unsigned char )(bool )(llvm_cbe_tmp__123 == 1ull)));
  llvm_cbe_tmp__124 = *(&llvm_cbe_cppVar_50);
  if ((((((bool )llvm_cbe_tmp__124&1u))&1))) {
    goto llvm_cbe_tmp__137;
  } else {
    llvm_cbe_tmp__127__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__138;
  }

llvm_cbe_tmp__137:
  llvm_cbe_tmp__125 = *(&llvm_cbe_cppVar_52);
  llvm_cbe_tmp__126 = ((((bool )llvm_cbe_tmp__125&1u))&1);
  llvm_cbe_tmp__127__PHI_TEMPORARY = llvm_cbe_tmp__126;   /* for PHI node */
  goto llvm_cbe_tmp__138;

llvm_cbe_tmp__138:
  llvm_cbe_tmp__127 = ((llvm_cbe_tmp__127__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_53) = (((unsigned char )(bool )llvm_cbe_tmp__127));
  llvm_cbe_tmp__128 = *(&llvm_cbe_cppVar_53);
  if ((((((bool )llvm_cbe_tmp__128&1u))&1))) {
    goto llvm_cbe_tmp__139;
  } else {
    goto llvm_cbe_tmp__140;
  }

llvm_cbe_tmp__139:
  *(&llvm_cbe_cppVar_45) = 1ull;
  goto llvm_cbe_tmp__141;

llvm_cbe_tmp__140:
  llvm_cbe_tmp__129 = *((&llvm_cbe_tmp__114->field3));
  *(&llvm_cbe_cppVar_45) = llvm_cbe_tmp__129;
  goto llvm_cbe_tmp__141;

llvm_cbe_tmp__141:
  llvm_cbe_tmp__130 = *(&llvm_cbe_cppVar_45);
  *(&llvm_cbe_cppVar_41) = llvm_cbe_tmp__130;
  goto llvm_cbe_tmp__134;

llvm_cbe_tmp__134:
  llvm_cbe_tmp__131 = *(&llvm_cbe_cppVar_41);
  return llvm_cbe_tmp__131;
}


unsigned long long _ZN9model_RBM23cppUpdateFun_num_hiddenElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__142;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__143;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__144;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__145;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__146;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__147;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__148;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__149;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__150;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__151;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__152;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__153;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_57;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_58;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_61;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_62;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_63;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_64;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_65;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_66;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_67;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_68;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_59;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_69;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_60;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_56;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__154;
  unsigned long long llvm_cbe_tmp__155;
  unsigned char llvm_cbe_tmp__156;
  unsigned long long llvm_cbe_tmp__157;
  unsigned long long llvm_cbe_tmp__158;
  unsigned char llvm_cbe_tmp__159;
  unsigned char llvm_cbe_tmp__160;
  bool llvm_cbe_tmp__161;
  bool llvm_cbe_tmp__162;
  bool llvm_cbe_tmp__162__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__163;
  unsigned char llvm_cbe_tmp__164;
  unsigned char llvm_cbe_tmp__165;
  bool llvm_cbe_tmp__166;
  bool llvm_cbe_tmp__167;
  bool llvm_cbe_tmp__167__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__168;
  unsigned long long llvm_cbe_tmp__169;
  unsigned long long llvm_cbe_tmp__170;
  unsigned long long llvm_cbe_tmp__171;
  unsigned long long llvm_cbe_tmp__172;
  unsigned long long llvm_cbe_tmp__173;
  unsigned long long llvm_cbe_tmp__174;

  *(&llvm_cbe_tmp__142) = llvm_cbe_this;
  *(&llvm_cbe_tmp__143) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__144) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__145) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__146) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__147) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__148) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__149) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__150) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__151) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__152) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__153) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__154 = *(&llvm_cbe_tmp__142);
  llvm_cbe_tmp__155 = *(&llvm_cbe_tmp__152);
  *(&llvm_cbe_cppVar_58) = (((unsigned char )(bool )(llvm_cbe_tmp__155 == 1ull)));
  llvm_cbe_tmp__156 = *(&llvm_cbe_cppVar_58);
  if ((((((bool )llvm_cbe_tmp__156&1u))&1))) {
    goto llvm_cbe_tmp__175;
  } else {
    goto llvm_cbe_tmp__176;
  }

llvm_cbe_tmp__175:
  *(&llvm_cbe_cppVar_56) = 0ull;
  goto llvm_cbe_tmp__177;

llvm_cbe_tmp__176:
  llvm_cbe_tmp__157 = *(&llvm_cbe_tmp__152);
  *(&llvm_cbe_cppVar_62) = (((unsigned char )(bool )(llvm_cbe_tmp__157 == 0ull)));
  llvm_cbe_tmp__158 = *((&llvm_cbe_tmp__154->field3));
  *(&llvm_cbe_cppVar_64) = (((unsigned char )(bool )(llvm_cbe_tmp__158 == 0ull)));
  llvm_cbe_tmp__159 = *(&llvm_cbe_cppVar_62);
  if ((((((bool )llvm_cbe_tmp__159&1u))&1))) {
    goto llvm_cbe_tmp__178;
  } else {
    llvm_cbe_tmp__162__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__179;
  }

llvm_cbe_tmp__178:
  llvm_cbe_tmp__160 = *(&llvm_cbe_cppVar_64);
  llvm_cbe_tmp__161 = ((((bool )llvm_cbe_tmp__160&1u))&1);
  llvm_cbe_tmp__162__PHI_TEMPORARY = llvm_cbe_tmp__161;   /* for PHI node */
  goto llvm_cbe_tmp__179;

llvm_cbe_tmp__179:
  llvm_cbe_tmp__162 = ((llvm_cbe_tmp__162__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_65) = (((unsigned char )(bool )llvm_cbe_tmp__162));
  llvm_cbe_tmp__163 = *(&llvm_cbe_tmp__143);
  *(&llvm_cbe_cppVar_67) = (((unsigned char )(bool )(llvm_cbe_tmp__163 == 1ull)));
  llvm_cbe_tmp__164 = *(&llvm_cbe_cppVar_65);
  if ((((((bool )llvm_cbe_tmp__164&1u))&1))) {
    goto llvm_cbe_tmp__180;
  } else {
    llvm_cbe_tmp__167__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__181;
  }

llvm_cbe_tmp__180:
  llvm_cbe_tmp__165 = *(&llvm_cbe_cppVar_67);
  llvm_cbe_tmp__166 = ((((bool )llvm_cbe_tmp__165&1u))&1);
  llvm_cbe_tmp__167__PHI_TEMPORARY = llvm_cbe_tmp__166;   /* for PHI node */
  goto llvm_cbe_tmp__181;

llvm_cbe_tmp__181:
  llvm_cbe_tmp__167 = ((llvm_cbe_tmp__167__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_68) = (((unsigned char )(bool )llvm_cbe_tmp__167));
  llvm_cbe_tmp__168 = *(&llvm_cbe_cppVar_68);
  if ((((((bool )llvm_cbe_tmp__168&1u))&1))) {
    goto llvm_cbe_tmp__182;
  } else {
    goto llvm_cbe_tmp__183;
  }

llvm_cbe_tmp__182:
  llvm_cbe_tmp__169 = *(&llvm_cbe_tmp__144);
  llvm_cbe_tmp__170 = *((&llvm_cbe_tmp__154->field21));
  *(&llvm_cbe_cppVar_69) = ((((signed long long )(((signed long long )llvm_cbe_tmp__169) >> ((signed long long )0ull)))) & llvm_cbe_tmp__170);
  llvm_cbe_tmp__171 = *(&llvm_cbe_cppVar_69);
  *(&llvm_cbe_cppVar_60) = llvm_cbe_tmp__171;
  goto llvm_cbe_tmp__184;

llvm_cbe_tmp__183:
  llvm_cbe_tmp__172 = *((&llvm_cbe_tmp__154->field4));
  *(&llvm_cbe_cppVar_60) = llvm_cbe_tmp__172;
  goto llvm_cbe_tmp__184;

llvm_cbe_tmp__184:
  llvm_cbe_tmp__173 = *(&llvm_cbe_cppVar_60);
  *(&llvm_cbe_cppVar_56) = llvm_cbe_tmp__173;
  goto llvm_cbe_tmp__177;

llvm_cbe_tmp__177:
  llvm_cbe_tmp__174 = *(&llvm_cbe_cppVar_56);
  return llvm_cbe_tmp__174;
}


unsigned long long _ZN9model_RBM22cppUpdateFun_num_loopsElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__185;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__186;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__187;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__188;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__189;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__190;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__191;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__192;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__193;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__194;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__195;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__196;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_72;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_73;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_76;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_77;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_78;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_79;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_80;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_81;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_82;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_83;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_74;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_84;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_75;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_71;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__197;
  unsigned long long llvm_cbe_tmp__198;
  unsigned char llvm_cbe_tmp__199;
  unsigned long long llvm_cbe_tmp__200;
  unsigned long long llvm_cbe_tmp__201;
  unsigned char llvm_cbe_tmp__202;
  unsigned char llvm_cbe_tmp__203;
  bool llvm_cbe_tmp__204;
  bool llvm_cbe_tmp__205;
  bool llvm_cbe_tmp__205__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__206;
  unsigned char llvm_cbe_tmp__207;
  unsigned char llvm_cbe_tmp__208;
  bool llvm_cbe_tmp__209;
  bool llvm_cbe_tmp__210;
  bool llvm_cbe_tmp__210__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__211;
  unsigned long long llvm_cbe_tmp__212;
  unsigned long long llvm_cbe_tmp__213;
  unsigned long long llvm_cbe_tmp__214;
  unsigned long long llvm_cbe_tmp__215;
  unsigned long long llvm_cbe_tmp__216;
  unsigned long long llvm_cbe_tmp__217;

  *(&llvm_cbe_tmp__185) = llvm_cbe_this;
  *(&llvm_cbe_tmp__186) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__187) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__188) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__189) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__190) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__191) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__192) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__193) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__194) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__195) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__196) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__197 = *(&llvm_cbe_tmp__185);
  llvm_cbe_tmp__198 = *(&llvm_cbe_tmp__195);
  *(&llvm_cbe_cppVar_73) = (((unsigned char )(bool )(llvm_cbe_tmp__198 == 1ull)));
  llvm_cbe_tmp__199 = *(&llvm_cbe_cppVar_73);
  if ((((((bool )llvm_cbe_tmp__199&1u))&1))) {
    goto llvm_cbe_tmp__218;
  } else {
    goto llvm_cbe_tmp__219;
  }

llvm_cbe_tmp__218:
  *(&llvm_cbe_cppVar_71) = 0ull;
  goto llvm_cbe_tmp__220;

llvm_cbe_tmp__219:
  llvm_cbe_tmp__200 = *(&llvm_cbe_tmp__195);
  *(&llvm_cbe_cppVar_77) = (((unsigned char )(bool )(llvm_cbe_tmp__200 == 0ull)));
  llvm_cbe_tmp__201 = *((&llvm_cbe_tmp__197->field3));
  *(&llvm_cbe_cppVar_79) = (((unsigned char )(bool )(llvm_cbe_tmp__201 == 0ull)));
  llvm_cbe_tmp__202 = *(&llvm_cbe_cppVar_77);
  if ((((((bool )llvm_cbe_tmp__202&1u))&1))) {
    goto llvm_cbe_tmp__221;
  } else {
    llvm_cbe_tmp__205__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__222;
  }

llvm_cbe_tmp__221:
  llvm_cbe_tmp__203 = *(&llvm_cbe_cppVar_79);
  llvm_cbe_tmp__204 = ((((bool )llvm_cbe_tmp__203&1u))&1);
  llvm_cbe_tmp__205__PHI_TEMPORARY = llvm_cbe_tmp__204;   /* for PHI node */
  goto llvm_cbe_tmp__222;

llvm_cbe_tmp__222:
  llvm_cbe_tmp__205 = ((llvm_cbe_tmp__205__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_80) = (((unsigned char )(bool )llvm_cbe_tmp__205));
  llvm_cbe_tmp__206 = *(&llvm_cbe_tmp__186);
  *(&llvm_cbe_cppVar_82) = (((unsigned char )(bool )(llvm_cbe_tmp__206 == 1ull)));
  llvm_cbe_tmp__207 = *(&llvm_cbe_cppVar_80);
  if ((((((bool )llvm_cbe_tmp__207&1u))&1))) {
    goto llvm_cbe_tmp__223;
  } else {
    llvm_cbe_tmp__210__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__224;
  }

llvm_cbe_tmp__223:
  llvm_cbe_tmp__208 = *(&llvm_cbe_cppVar_82);
  llvm_cbe_tmp__209 = ((((bool )llvm_cbe_tmp__208&1u))&1);
  llvm_cbe_tmp__210__PHI_TEMPORARY = llvm_cbe_tmp__209;   /* for PHI node */
  goto llvm_cbe_tmp__224;

llvm_cbe_tmp__224:
  llvm_cbe_tmp__210 = ((llvm_cbe_tmp__210__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_83) = (((unsigned char )(bool )llvm_cbe_tmp__210));
  llvm_cbe_tmp__211 = *(&llvm_cbe_cppVar_83);
  if ((((((bool )llvm_cbe_tmp__211&1u))&1))) {
    goto llvm_cbe_tmp__225;
  } else {
    goto llvm_cbe_tmp__226;
  }

llvm_cbe_tmp__225:
  llvm_cbe_tmp__212 = *(&llvm_cbe_tmp__188);
  llvm_cbe_tmp__213 = *((&llvm_cbe_tmp__197->field21));
  *(&llvm_cbe_cppVar_84) = ((((signed long long )(((signed long long )llvm_cbe_tmp__212) >> ((signed long long )0ull)))) & llvm_cbe_tmp__213);
  llvm_cbe_tmp__214 = *(&llvm_cbe_cppVar_84);
  *(&llvm_cbe_cppVar_75) = llvm_cbe_tmp__214;
  goto llvm_cbe_tmp__227;

llvm_cbe_tmp__226:
  llvm_cbe_tmp__215 = *((&llvm_cbe_tmp__197->field5));
  *(&llvm_cbe_cppVar_75) = llvm_cbe_tmp__215;
  goto llvm_cbe_tmp__227;

llvm_cbe_tmp__227:
  llvm_cbe_tmp__216 = *(&llvm_cbe_cppVar_75);
  *(&llvm_cbe_cppVar_71) = llvm_cbe_tmp__216;
  goto llvm_cbe_tmp__220;

llvm_cbe_tmp__220:
  llvm_cbe_tmp__217 = *(&llvm_cbe_cppVar_71);
  return llvm_cbe_tmp__217;
}


unsigned long long _ZN9model_RBM23cppUpdateFun_num_moviesElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__228;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__229;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__230;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__231;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__232;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__233;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__234;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__235;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__236;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__237;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__238;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__239;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_87;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_88;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_91;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_92;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_93;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_94;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_95;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_96;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_97;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_98;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_89;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_99;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_90;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_86;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__240;
  unsigned long long llvm_cbe_tmp__241;
  unsigned char llvm_cbe_tmp__242;
  unsigned long long llvm_cbe_tmp__243;
  unsigned long long llvm_cbe_tmp__244;
  unsigned char llvm_cbe_tmp__245;
  unsigned char llvm_cbe_tmp__246;
  bool llvm_cbe_tmp__247;
  bool llvm_cbe_tmp__248;
  bool llvm_cbe_tmp__248__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__249;
  unsigned char llvm_cbe_tmp__250;
  unsigned char llvm_cbe_tmp__251;
  bool llvm_cbe_tmp__252;
  bool llvm_cbe_tmp__253;
  bool llvm_cbe_tmp__253__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__254;
  unsigned long long llvm_cbe_tmp__255;
  unsigned long long llvm_cbe_tmp__256;
  unsigned long long llvm_cbe_tmp__257;
  unsigned long long llvm_cbe_tmp__258;
  unsigned long long llvm_cbe_tmp__259;
  unsigned long long llvm_cbe_tmp__260;

  *(&llvm_cbe_tmp__228) = llvm_cbe_this;
  *(&llvm_cbe_tmp__229) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__230) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__231) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__232) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__233) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__234) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__235) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__236) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__237) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__238) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__239) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__240 = *(&llvm_cbe_tmp__228);
  llvm_cbe_tmp__241 = *(&llvm_cbe_tmp__238);
  *(&llvm_cbe_cppVar_88) = (((unsigned char )(bool )(llvm_cbe_tmp__241 == 1ull)));
  llvm_cbe_tmp__242 = *(&llvm_cbe_cppVar_88);
  if ((((((bool )llvm_cbe_tmp__242&1u))&1))) {
    goto llvm_cbe_tmp__261;
  } else {
    goto llvm_cbe_tmp__262;
  }

llvm_cbe_tmp__261:
  *(&llvm_cbe_cppVar_86) = 0ull;
  goto llvm_cbe_tmp__263;

llvm_cbe_tmp__262:
  llvm_cbe_tmp__243 = *(&llvm_cbe_tmp__238);
  *(&llvm_cbe_cppVar_92) = (((unsigned char )(bool )(llvm_cbe_tmp__243 == 0ull)));
  llvm_cbe_tmp__244 = *((&llvm_cbe_tmp__240->field3));
  *(&llvm_cbe_cppVar_94) = (((unsigned char )(bool )(llvm_cbe_tmp__244 == 0ull)));
  llvm_cbe_tmp__245 = *(&llvm_cbe_cppVar_92);
  if ((((((bool )llvm_cbe_tmp__245&1u))&1))) {
    goto llvm_cbe_tmp__264;
  } else {
    llvm_cbe_tmp__248__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__265;
  }

llvm_cbe_tmp__264:
  llvm_cbe_tmp__246 = *(&llvm_cbe_cppVar_94);
  llvm_cbe_tmp__247 = ((((bool )llvm_cbe_tmp__246&1u))&1);
  llvm_cbe_tmp__248__PHI_TEMPORARY = llvm_cbe_tmp__247;   /* for PHI node */
  goto llvm_cbe_tmp__265;

llvm_cbe_tmp__265:
  llvm_cbe_tmp__248 = ((llvm_cbe_tmp__248__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_95) = (((unsigned char )(bool )llvm_cbe_tmp__248));
  llvm_cbe_tmp__249 = *(&llvm_cbe_tmp__229);
  *(&llvm_cbe_cppVar_97) = (((unsigned char )(bool )(llvm_cbe_tmp__249 == 1ull)));
  llvm_cbe_tmp__250 = *(&llvm_cbe_cppVar_95);
  if ((((((bool )llvm_cbe_tmp__250&1u))&1))) {
    goto llvm_cbe_tmp__266;
  } else {
    llvm_cbe_tmp__253__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__267;
  }

llvm_cbe_tmp__266:
  llvm_cbe_tmp__251 = *(&llvm_cbe_cppVar_97);
  llvm_cbe_tmp__252 = ((((bool )llvm_cbe_tmp__251&1u))&1);
  llvm_cbe_tmp__253__PHI_TEMPORARY = llvm_cbe_tmp__252;   /* for PHI node */
  goto llvm_cbe_tmp__267;

llvm_cbe_tmp__267:
  llvm_cbe_tmp__253 = ((llvm_cbe_tmp__253__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_98) = (((unsigned char )(bool )llvm_cbe_tmp__253));
  llvm_cbe_tmp__254 = *(&llvm_cbe_cppVar_98);
  if ((((((bool )llvm_cbe_tmp__254&1u))&1))) {
    goto llvm_cbe_tmp__268;
  } else {
    goto llvm_cbe_tmp__269;
  }

llvm_cbe_tmp__268:
  llvm_cbe_tmp__255 = *(&llvm_cbe_tmp__232);
  llvm_cbe_tmp__256 = *((&llvm_cbe_tmp__240->field21));
  *(&llvm_cbe_cppVar_99) = ((((signed long long )(((signed long long )llvm_cbe_tmp__255) >> ((signed long long )0ull)))) & llvm_cbe_tmp__256);
  llvm_cbe_tmp__257 = *(&llvm_cbe_cppVar_99);
  *(&llvm_cbe_cppVar_90) = llvm_cbe_tmp__257;
  goto llvm_cbe_tmp__270;

llvm_cbe_tmp__269:
  llvm_cbe_tmp__258 = *((&llvm_cbe_tmp__240->field6));
  *(&llvm_cbe_cppVar_90) = llvm_cbe_tmp__258;
  goto llvm_cbe_tmp__270;

llvm_cbe_tmp__270:
  llvm_cbe_tmp__259 = *(&llvm_cbe_cppVar_90);
  *(&llvm_cbe_cppVar_86) = llvm_cbe_tmp__259;
  goto llvm_cbe_tmp__263;

llvm_cbe_tmp__263:
  llvm_cbe_tmp__260 = *(&llvm_cbe_cppVar_86);
  return llvm_cbe_tmp__260;
}


unsigned long long _ZN9model_RBM26cppUpdateFun_num_testusersElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__271;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__272;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__273;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__274;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__275;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__276;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__277;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__278;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__279;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__280;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__281;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__282;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_102;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_103;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_106;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_107;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_108;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_109;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_110;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_111;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_112;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_113;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_104;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_114;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_105;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_101;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__283;
  unsigned long long llvm_cbe_tmp__284;
  unsigned char llvm_cbe_tmp__285;
  unsigned long long llvm_cbe_tmp__286;
  unsigned long long llvm_cbe_tmp__287;
  unsigned char llvm_cbe_tmp__288;
  unsigned char llvm_cbe_tmp__289;
  bool llvm_cbe_tmp__290;
  bool llvm_cbe_tmp__291;
  bool llvm_cbe_tmp__291__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__292;
  unsigned char llvm_cbe_tmp__293;
  unsigned char llvm_cbe_tmp__294;
  bool llvm_cbe_tmp__295;
  bool llvm_cbe_tmp__296;
  bool llvm_cbe_tmp__296__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__297;
  unsigned long long llvm_cbe_tmp__298;
  unsigned long long llvm_cbe_tmp__299;
  unsigned long long llvm_cbe_tmp__300;
  unsigned long long llvm_cbe_tmp__301;
  unsigned long long llvm_cbe_tmp__302;
  unsigned long long llvm_cbe_tmp__303;

  *(&llvm_cbe_tmp__271) = llvm_cbe_this;
  *(&llvm_cbe_tmp__272) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__273) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__274) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__275) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__276) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__277) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__278) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__279) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__280) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__281) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__282) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__283 = *(&llvm_cbe_tmp__271);
  llvm_cbe_tmp__284 = *(&llvm_cbe_tmp__281);
  *(&llvm_cbe_cppVar_103) = (((unsigned char )(bool )(llvm_cbe_tmp__284 == 1ull)));
  llvm_cbe_tmp__285 = *(&llvm_cbe_cppVar_103);
  if ((((((bool )llvm_cbe_tmp__285&1u))&1))) {
    goto llvm_cbe_tmp__304;
  } else {
    goto llvm_cbe_tmp__305;
  }

llvm_cbe_tmp__304:
  *(&llvm_cbe_cppVar_101) = 0ull;
  goto llvm_cbe_tmp__306;

llvm_cbe_tmp__305:
  llvm_cbe_tmp__286 = *(&llvm_cbe_tmp__281);
  *(&llvm_cbe_cppVar_107) = (((unsigned char )(bool )(llvm_cbe_tmp__286 == 0ull)));
  llvm_cbe_tmp__287 = *((&llvm_cbe_tmp__283->field3));
  *(&llvm_cbe_cppVar_109) = (((unsigned char )(bool )(llvm_cbe_tmp__287 == 0ull)));
  llvm_cbe_tmp__288 = *(&llvm_cbe_cppVar_107);
  if ((((((bool )llvm_cbe_tmp__288&1u))&1))) {
    goto llvm_cbe_tmp__307;
  } else {
    llvm_cbe_tmp__291__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__308;
  }

llvm_cbe_tmp__307:
  llvm_cbe_tmp__289 = *(&llvm_cbe_cppVar_109);
  llvm_cbe_tmp__290 = ((((bool )llvm_cbe_tmp__289&1u))&1);
  llvm_cbe_tmp__291__PHI_TEMPORARY = llvm_cbe_tmp__290;   /* for PHI node */
  goto llvm_cbe_tmp__308;

llvm_cbe_tmp__308:
  llvm_cbe_tmp__291 = ((llvm_cbe_tmp__291__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_110) = (((unsigned char )(bool )llvm_cbe_tmp__291));
  llvm_cbe_tmp__292 = *(&llvm_cbe_tmp__272);
  *(&llvm_cbe_cppVar_112) = (((unsigned char )(bool )(llvm_cbe_tmp__292 == 1ull)));
  llvm_cbe_tmp__293 = *(&llvm_cbe_cppVar_110);
  if ((((((bool )llvm_cbe_tmp__293&1u))&1))) {
    goto llvm_cbe_tmp__309;
  } else {
    llvm_cbe_tmp__296__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__310;
  }

llvm_cbe_tmp__309:
  llvm_cbe_tmp__294 = *(&llvm_cbe_cppVar_112);
  llvm_cbe_tmp__295 = ((((bool )llvm_cbe_tmp__294&1u))&1);
  llvm_cbe_tmp__296__PHI_TEMPORARY = llvm_cbe_tmp__295;   /* for PHI node */
  goto llvm_cbe_tmp__310;

llvm_cbe_tmp__310:
  llvm_cbe_tmp__296 = ((llvm_cbe_tmp__296__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_113) = (((unsigned char )(bool )llvm_cbe_tmp__296));
  llvm_cbe_tmp__297 = *(&llvm_cbe_cppVar_113);
  if ((((((bool )llvm_cbe_tmp__297&1u))&1))) {
    goto llvm_cbe_tmp__311;
  } else {
    goto llvm_cbe_tmp__312;
  }

llvm_cbe_tmp__311:
  llvm_cbe_tmp__298 = *(&llvm_cbe_tmp__276);
  llvm_cbe_tmp__299 = *((&llvm_cbe_tmp__283->field21));
  *(&llvm_cbe_cppVar_114) = ((((signed long long )(((signed long long )llvm_cbe_tmp__298) >> ((signed long long )0ull)))) & llvm_cbe_tmp__299);
  llvm_cbe_tmp__300 = *(&llvm_cbe_cppVar_114);
  *(&llvm_cbe_cppVar_105) = llvm_cbe_tmp__300;
  goto llvm_cbe_tmp__313;

llvm_cbe_tmp__312:
  llvm_cbe_tmp__301 = *((&llvm_cbe_tmp__283->field7));
  *(&llvm_cbe_cppVar_105) = llvm_cbe_tmp__301;
  goto llvm_cbe_tmp__313;

llvm_cbe_tmp__313:
  llvm_cbe_tmp__302 = *(&llvm_cbe_cppVar_105);
  *(&llvm_cbe_cppVar_101) = llvm_cbe_tmp__302;
  goto llvm_cbe_tmp__306;

llvm_cbe_tmp__306:
  llvm_cbe_tmp__303 = *(&llvm_cbe_cppVar_101);
  return llvm_cbe_tmp__303;
}


unsigned long long _ZN9model_RBM22cppUpdateFun_num_usersElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__314;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__315;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__316;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__317;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__318;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__319;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__320;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__321;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__322;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__323;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__324;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__325;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_117;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_118;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_121;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_122;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_123;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_124;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_125;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_126;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_127;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_128;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_119;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_129;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_120;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_116;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__326;
  unsigned long long llvm_cbe_tmp__327;
  unsigned char llvm_cbe_tmp__328;
  unsigned long long llvm_cbe_tmp__329;
  unsigned long long llvm_cbe_tmp__330;
  unsigned char llvm_cbe_tmp__331;
  unsigned char llvm_cbe_tmp__332;
  bool llvm_cbe_tmp__333;
  bool llvm_cbe_tmp__334;
  bool llvm_cbe_tmp__334__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__335;
  unsigned char llvm_cbe_tmp__336;
  unsigned char llvm_cbe_tmp__337;
  bool llvm_cbe_tmp__338;
  bool llvm_cbe_tmp__339;
  bool llvm_cbe_tmp__339__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__340;
  unsigned long long llvm_cbe_tmp__341;
  unsigned long long llvm_cbe_tmp__342;
  unsigned long long llvm_cbe_tmp__343;
  unsigned long long llvm_cbe_tmp__344;
  unsigned long long llvm_cbe_tmp__345;
  unsigned long long llvm_cbe_tmp__346;

  *(&llvm_cbe_tmp__314) = llvm_cbe_this;
  *(&llvm_cbe_tmp__315) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__316) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__317) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__318) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__319) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__320) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__321) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__322) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__323) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__324) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__325) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__326 = *(&llvm_cbe_tmp__314);
  llvm_cbe_tmp__327 = *(&llvm_cbe_tmp__324);
  *(&llvm_cbe_cppVar_118) = (((unsigned char )(bool )(llvm_cbe_tmp__327 == 1ull)));
  llvm_cbe_tmp__328 = *(&llvm_cbe_cppVar_118);
  if ((((((bool )llvm_cbe_tmp__328&1u))&1))) {
    goto llvm_cbe_tmp__347;
  } else {
    goto llvm_cbe_tmp__348;
  }

llvm_cbe_tmp__347:
  *(&llvm_cbe_cppVar_116) = 0ull;
  goto llvm_cbe_tmp__349;

llvm_cbe_tmp__348:
  llvm_cbe_tmp__329 = *(&llvm_cbe_tmp__324);
  *(&llvm_cbe_cppVar_122) = (((unsigned char )(bool )(llvm_cbe_tmp__329 == 0ull)));
  llvm_cbe_tmp__330 = *((&llvm_cbe_tmp__326->field3));
  *(&llvm_cbe_cppVar_124) = (((unsigned char )(bool )(llvm_cbe_tmp__330 == 0ull)));
  llvm_cbe_tmp__331 = *(&llvm_cbe_cppVar_122);
  if ((((((bool )llvm_cbe_tmp__331&1u))&1))) {
    goto llvm_cbe_tmp__350;
  } else {
    llvm_cbe_tmp__334__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__351;
  }

llvm_cbe_tmp__350:
  llvm_cbe_tmp__332 = *(&llvm_cbe_cppVar_124);
  llvm_cbe_tmp__333 = ((((bool )llvm_cbe_tmp__332&1u))&1);
  llvm_cbe_tmp__334__PHI_TEMPORARY = llvm_cbe_tmp__333;   /* for PHI node */
  goto llvm_cbe_tmp__351;

llvm_cbe_tmp__351:
  llvm_cbe_tmp__334 = ((llvm_cbe_tmp__334__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_125) = (((unsigned char )(bool )llvm_cbe_tmp__334));
  llvm_cbe_tmp__335 = *(&llvm_cbe_tmp__315);
  *(&llvm_cbe_cppVar_127) = (((unsigned char )(bool )(llvm_cbe_tmp__335 == 1ull)));
  llvm_cbe_tmp__336 = *(&llvm_cbe_cppVar_125);
  if ((((((bool )llvm_cbe_tmp__336&1u))&1))) {
    goto llvm_cbe_tmp__352;
  } else {
    llvm_cbe_tmp__339__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__353;
  }

llvm_cbe_tmp__352:
  llvm_cbe_tmp__337 = *(&llvm_cbe_cppVar_127);
  llvm_cbe_tmp__338 = ((((bool )llvm_cbe_tmp__337&1u))&1);
  llvm_cbe_tmp__339__PHI_TEMPORARY = llvm_cbe_tmp__338;   /* for PHI node */
  goto llvm_cbe_tmp__353;

llvm_cbe_tmp__353:
  llvm_cbe_tmp__339 = ((llvm_cbe_tmp__339__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_128) = (((unsigned char )(bool )llvm_cbe_tmp__339));
  llvm_cbe_tmp__340 = *(&llvm_cbe_cppVar_128);
  if ((((((bool )llvm_cbe_tmp__340&1u))&1))) {
    goto llvm_cbe_tmp__354;
  } else {
    goto llvm_cbe_tmp__355;
  }

llvm_cbe_tmp__354:
  llvm_cbe_tmp__341 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__342 = *((&llvm_cbe_tmp__326->field21));
  *(&llvm_cbe_cppVar_129) = ((((signed long long )(((signed long long )llvm_cbe_tmp__341) >> ((signed long long )0ull)))) & llvm_cbe_tmp__342);
  llvm_cbe_tmp__343 = *(&llvm_cbe_cppVar_129);
  *(&llvm_cbe_cppVar_120) = llvm_cbe_tmp__343;
  goto llvm_cbe_tmp__356;

llvm_cbe_tmp__355:
  llvm_cbe_tmp__344 = *((&llvm_cbe_tmp__326->field8));
  *(&llvm_cbe_cppVar_120) = llvm_cbe_tmp__344;
  goto llvm_cbe_tmp__356;

llvm_cbe_tmp__356:
  llvm_cbe_tmp__345 = *(&llvm_cbe_cppVar_120);
  *(&llvm_cbe_cppVar_116) = llvm_cbe_tmp__345;
  goto llvm_cbe_tmp__349;

llvm_cbe_tmp__349:
  llvm_cbe_tmp__346 = *(&llvm_cbe_cppVar_116);
  return llvm_cbe_tmp__346;
}


unsigned long long _ZN9model_RBM24cppUpdateFun_num_visibleElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__357;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__358;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_cppVar_132;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_133;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_136;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_137;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_138;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_139;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_140;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_141;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_142;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_143;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_134;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_144;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_135;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_131;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__369;
  unsigned long long llvm_cbe_tmp__370;
  unsigned char llvm_cbe_tmp__371;
  unsigned long long llvm_cbe_tmp__372;
  unsigned long long llvm_cbe_tmp__373;
  unsigned char llvm_cbe_tmp__374;
  unsigned char llvm_cbe_tmp__375;
  bool llvm_cbe_tmp__376;
  bool llvm_cbe_tmp__377;
  bool llvm_cbe_tmp__377__PHI_TEMPORARY;
  unsigned long long llvm_cbe_tmp__378;
  unsigned char llvm_cbe_tmp__379;
  unsigned char llvm_cbe_tmp__380;
  bool llvm_cbe_tmp__381;
  bool llvm_cbe_tmp__382;
  bool llvm_cbe_tmp__382__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__383;
  unsigned long long llvm_cbe_tmp__384;
  unsigned long long llvm_cbe_tmp__385;
  unsigned long long llvm_cbe_tmp__386;
  unsigned long long llvm_cbe_tmp__387;
  unsigned long long llvm_cbe_tmp__388;
  unsigned long long llvm_cbe_tmp__389;

  *(&llvm_cbe_tmp__357) = llvm_cbe_this;
  *(&llvm_cbe_tmp__358) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__359) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__360) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__361) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__362) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__363) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__364) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__365) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__366) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__367) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__368) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__369 = *(&llvm_cbe_tmp__357);
  llvm_cbe_tmp__370 = *(&llvm_cbe_tmp__367);
  *(&llvm_cbe_cppVar_133) = (((unsigned char )(bool )(llvm_cbe_tmp__370 == 1ull)));
  llvm_cbe_tmp__371 = *(&llvm_cbe_cppVar_133);
  if ((((((bool )llvm_cbe_tmp__371&1u))&1))) {
    goto llvm_cbe_tmp__390;
  } else {
    goto llvm_cbe_tmp__391;
  }

llvm_cbe_tmp__390:
  *(&llvm_cbe_cppVar_131) = 0ull;
  goto llvm_cbe_tmp__392;

llvm_cbe_tmp__391:
  llvm_cbe_tmp__372 = *(&llvm_cbe_tmp__367);
  *(&llvm_cbe_cppVar_137) = (((unsigned char )(bool )(llvm_cbe_tmp__372 == 0ull)));
  llvm_cbe_tmp__373 = *((&llvm_cbe_tmp__369->field3));
  *(&llvm_cbe_cppVar_139) = (((unsigned char )(bool )(llvm_cbe_tmp__373 == 0ull)));
  llvm_cbe_tmp__374 = *(&llvm_cbe_cppVar_137);
  if ((((((bool )llvm_cbe_tmp__374&1u))&1))) {
    goto llvm_cbe_tmp__393;
  } else {
    llvm_cbe_tmp__377__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__394;
  }

llvm_cbe_tmp__393:
  llvm_cbe_tmp__375 = *(&llvm_cbe_cppVar_139);
  llvm_cbe_tmp__376 = ((((bool )llvm_cbe_tmp__375&1u))&1);
  llvm_cbe_tmp__377__PHI_TEMPORARY = llvm_cbe_tmp__376;   /* for PHI node */
  goto llvm_cbe_tmp__394;

llvm_cbe_tmp__394:
  llvm_cbe_tmp__377 = ((llvm_cbe_tmp__377__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_140) = (((unsigned char )(bool )llvm_cbe_tmp__377));
  llvm_cbe_tmp__378 = *(&llvm_cbe_tmp__358);
  *(&llvm_cbe_cppVar_142) = (((unsigned char )(bool )(llvm_cbe_tmp__378 == 1ull)));
  llvm_cbe_tmp__379 = *(&llvm_cbe_cppVar_140);
  if ((((((bool )llvm_cbe_tmp__379&1u))&1))) {
    goto llvm_cbe_tmp__395;
  } else {
    llvm_cbe_tmp__382__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__396;
  }

llvm_cbe_tmp__395:
  llvm_cbe_tmp__380 = *(&llvm_cbe_cppVar_142);
  llvm_cbe_tmp__381 = ((((bool )llvm_cbe_tmp__380&1u))&1);
  llvm_cbe_tmp__382__PHI_TEMPORARY = llvm_cbe_tmp__381;   /* for PHI node */
  goto llvm_cbe_tmp__396;

llvm_cbe_tmp__396:
  llvm_cbe_tmp__382 = ((llvm_cbe_tmp__382__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_143) = (((unsigned char )(bool )llvm_cbe_tmp__382));
  llvm_cbe_tmp__383 = *(&llvm_cbe_cppVar_143);
  if ((((((bool )llvm_cbe_tmp__383&1u))&1))) {
    goto llvm_cbe_tmp__397;
  } else {
    goto llvm_cbe_tmp__398;
  }

llvm_cbe_tmp__397:
  llvm_cbe_tmp__384 = *(&llvm_cbe_tmp__364);
  llvm_cbe_tmp__385 = *((&llvm_cbe_tmp__369->field21));
  *(&llvm_cbe_cppVar_144) = ((((signed long long )(((signed long long )llvm_cbe_tmp__384) >> ((signed long long )0ull)))) & llvm_cbe_tmp__385);
  llvm_cbe_tmp__386 = *(&llvm_cbe_cppVar_144);
  *(&llvm_cbe_cppVar_135) = llvm_cbe_tmp__386;
  goto llvm_cbe_tmp__399;

llvm_cbe_tmp__398:
  llvm_cbe_tmp__387 = *((&llvm_cbe_tmp__369->field9));
  *(&llvm_cbe_cppVar_135) = llvm_cbe_tmp__387;
  goto llvm_cbe_tmp__399;

llvm_cbe_tmp__399:
  llvm_cbe_tmp__388 = *(&llvm_cbe_cppVar_135);
  *(&llvm_cbe_cppVar_131) = llvm_cbe_tmp__388;
  goto llvm_cbe_tmp__392;

llvm_cbe_tmp__392:
  llvm_cbe_tmp__389 = *(&llvm_cbe_cppVar_131);
  return llvm_cbe_tmp__389;
}


unsigned long long _ZN9model_RBM24cppUpdateFun_rd_completeElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__400;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__401;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__402;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__403;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__404;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__405;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__406;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__407;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__408;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__409;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__410;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__411;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__412;
  unsigned long long llvm_cbe_tmp__413;

  *(&llvm_cbe_tmp__400) = llvm_cbe_this;
  *(&llvm_cbe_tmp__401) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__402) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__403) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__404) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__405) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__406) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__407) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__408) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__409) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__410) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__411) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__412 = *(&llvm_cbe_tmp__400);
  llvm_cbe_tmp__413 = *((&llvm_cbe_tmp__412->field11));
  return llvm_cbe_tmp__413;
}


unsigned long long _ZN9model_RBM23cppUpdateFun_rd_grantedElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__414;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__415;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__416;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__417;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__418;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__419;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__420;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__421;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__422;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__423;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__424;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__425;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_147;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_148;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_149;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_150;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_151;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_152;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_153;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__426;
  unsigned long long llvm_cbe_tmp__427;
  unsigned long long llvm_cbe_tmp__428;
  unsigned char llvm_cbe_tmp__429;
  unsigned char llvm_cbe_tmp__430;
  bool llvm_cbe_tmp__431;
  bool llvm_cbe_tmp__432;
  bool llvm_cbe_tmp__432__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__433;
  unsigned long long llvm_cbe_tmp__434;
  unsigned long long llvm_cbe_tmp__435;

  *(&llvm_cbe_tmp__414) = llvm_cbe_this;
  *(&llvm_cbe_tmp__415) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__416) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__417) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__418) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__419) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__420) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__421) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__422) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__423) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__424) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__425) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__426 = *(&llvm_cbe_tmp__414);
  llvm_cbe_tmp__427 = *((&llvm_cbe_tmp__426->field15));
  *(&llvm_cbe_cppVar_149) = (((unsigned char )(bool )(llvm_cbe_tmp__427 == 1ull)));
  llvm_cbe_tmp__428 = *(&llvm_cbe_tmp__423);
  *(&llvm_cbe_cppVar_151) = (((unsigned char )(bool )(llvm_cbe_tmp__428 == 1ull)));
  llvm_cbe_tmp__429 = *(&llvm_cbe_cppVar_149);
  if ((((((bool )llvm_cbe_tmp__429&1u))&1))) {
    goto llvm_cbe_tmp__436;
  } else {
    llvm_cbe_tmp__432__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__437;
  }

llvm_cbe_tmp__436:
  llvm_cbe_tmp__430 = *(&llvm_cbe_cppVar_151);
  llvm_cbe_tmp__431 = ((((bool )llvm_cbe_tmp__430&1u))&1);
  llvm_cbe_tmp__432__PHI_TEMPORARY = llvm_cbe_tmp__431;   /* for PHI node */
  goto llvm_cbe_tmp__437;

llvm_cbe_tmp__437:
  llvm_cbe_tmp__432 = ((llvm_cbe_tmp__432__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_152) = (((unsigned char )(bool )llvm_cbe_tmp__432));
  llvm_cbe_tmp__433 = *(&llvm_cbe_cppVar_152);
  if ((((((bool )llvm_cbe_tmp__433&1u))&1))) {
    goto llvm_cbe_tmp__438;
  } else {
    goto llvm_cbe_tmp__439;
  }

llvm_cbe_tmp__438:
  *(&llvm_cbe_cppVar_147) = 1ull;
  goto llvm_cbe_tmp__440;

llvm_cbe_tmp__439:
  llvm_cbe_tmp__434 = *((&llvm_cbe_tmp__426->field12));
  *(&llvm_cbe_cppVar_147) = llvm_cbe_tmp__434;
  goto llvm_cbe_tmp__440;

llvm_cbe_tmp__440:
  llvm_cbe_tmp__435 = *(&llvm_cbe_cppVar_147);
  return llvm_cbe_tmp__435;
}


unsigned long long _ZN9model_RBM21cppUpdateFun_rd_indexElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__441;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__442;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__443;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__444;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__445;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__446;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__447;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__448;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__449;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__450;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__451;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__452;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__453;
  unsigned long long llvm_cbe_tmp__454;

  *(&llvm_cbe_tmp__441) = llvm_cbe_this;
  *(&llvm_cbe_tmp__442) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__443) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__444) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__445) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__446) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__447) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__448) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__449) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__450) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__451) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__452) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__453 = *(&llvm_cbe_tmp__441);
  llvm_cbe_tmp__454 = *((&llvm_cbe_tmp__453->field13));
  return llvm_cbe_tmp__454;
}


unsigned long long _ZN9model_RBM22cppUpdateFun_rd_lengthElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__455;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__456;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__457;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__458;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__459;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__460;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__461;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__462;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__463;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__464;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__465;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__466;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__467;
  unsigned long long llvm_cbe_tmp__468;

  *(&llvm_cbe_tmp__455) = llvm_cbe_this;
  *(&llvm_cbe_tmp__456) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__457) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__458) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__459) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__460) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__461) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__462) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__463) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__464) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__465) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__466) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__467 = *(&llvm_cbe_tmp__455);
  llvm_cbe_tmp__468 = *((&llvm_cbe_tmp__467->field14));
  return llvm_cbe_tmp__468;
}


unsigned long long _ZN9model_RBM23cppUpdateFun_rd_requestElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__469;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__470;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__471;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__472;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__473;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__474;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__475;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__476;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__477;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__478;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__479;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__480;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__481;
  unsigned long long llvm_cbe_tmp__482;

  *(&llvm_cbe_tmp__469) = llvm_cbe_this;
  *(&llvm_cbe_tmp__470) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__471) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__472) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__473) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__474) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__475) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__476) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__477) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__478) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__479) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__480) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__481 = *(&llvm_cbe_tmp__469);
  llvm_cbe_tmp__482 = *((&llvm_cbe_tmp__481->field15));
  return llvm_cbe_tmp__482;
}


unsigned long long _ZN9model_RBM24cppUpdateFun_wr_completeElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__483;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__484;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__485;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__486;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__487;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__488;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__489;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__490;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__491;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__492;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__493;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__494;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__495;
  unsigned long long llvm_cbe_tmp__496;

  *(&llvm_cbe_tmp__483) = llvm_cbe_this;
  *(&llvm_cbe_tmp__484) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__485) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__486) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__487) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__488) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__489) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__490) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__491) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__492) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__493) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__494) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__495 = *(&llvm_cbe_tmp__483);
  llvm_cbe_tmp__496 = *((&llvm_cbe_tmp__495->field16));
  return llvm_cbe_tmp__496;
}


unsigned long long _ZN9model_RBM23cppUpdateFun_wr_grantedElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__497;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__498;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__499;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__500;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__501;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__502;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__503;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__504;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__505;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__506;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__507;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__508;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_163;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_160;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_161;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_162;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_159;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__509;
  unsigned long long llvm_cbe_tmp__510;
  unsigned long long llvm_cbe_tmp__511;
  unsigned long long llvm_cbe_tmp__512;
  unsigned char llvm_cbe_tmp__513;
  unsigned long long llvm_cbe_tmp__514;
  unsigned long long llvm_cbe_tmp__515;

  *(&llvm_cbe_tmp__497) = llvm_cbe_this;
  *(&llvm_cbe_tmp__498) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__499) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__500) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__501) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__502) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__503) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__504) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__505) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__506) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__507) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__508) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__509 = *(&llvm_cbe_tmp__497);
  llvm_cbe_tmp__510 = *((&llvm_cbe_tmp__509->field20));
  llvm_cbe_tmp__511 = *(&llvm_cbe_tmp__508);
  *(&llvm_cbe_cppVar_160) = (llvm_cbe_tmp__510 & llvm_cbe_tmp__511);
  llvm_cbe_tmp__512 = *(&llvm_cbe_cppVar_160);
  *(&llvm_cbe_cppVar_162) = (((unsigned char )(bool )(llvm_cbe_tmp__512 == 1ull)));
  llvm_cbe_tmp__513 = *(&llvm_cbe_cppVar_162);
  if ((((((bool )llvm_cbe_tmp__513&1u))&1))) {
    goto llvm_cbe_tmp__516;
  } else {
    goto llvm_cbe_tmp__517;
  }

llvm_cbe_tmp__516:
  *(&llvm_cbe_cppVar_159) = 1ull;
  goto llvm_cbe_tmp__518;

llvm_cbe_tmp__517:
  llvm_cbe_tmp__514 = *((&llvm_cbe_tmp__509->field17));
  *(&llvm_cbe_cppVar_159) = llvm_cbe_tmp__514;
  goto llvm_cbe_tmp__518;

llvm_cbe_tmp__518:
  llvm_cbe_tmp__515 = *(&llvm_cbe_cppVar_159);
  return llvm_cbe_tmp__515;
}


unsigned long long _ZN9model_RBM21cppUpdateFun_wr_indexElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__519;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__520;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__521;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__522;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__523;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__524;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__525;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__526;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__527;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__528;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__529;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__530;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__531;
  unsigned long long llvm_cbe_tmp__532;

  *(&llvm_cbe_tmp__519) = llvm_cbe_this;
  *(&llvm_cbe_tmp__520) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__521) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__522) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__523) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__524) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__525) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__526) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__527) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__528) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__529) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__530) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__531 = *(&llvm_cbe_tmp__519);
  llvm_cbe_tmp__532 = *((&llvm_cbe_tmp__531->field18));
  return llvm_cbe_tmp__532;
}


unsigned long long _ZN9model_RBM22cppUpdateFun_wr_lengthElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__533;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__534;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__535;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__536;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__537;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__538;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__539;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__540;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__541;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__542;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__543;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__544;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__545;
  unsigned long long llvm_cbe_tmp__546;

  *(&llvm_cbe_tmp__533) = llvm_cbe_this;
  *(&llvm_cbe_tmp__534) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__535) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__536) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__537) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__538) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__539) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__540) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__541) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__542) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__543) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__544) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__545 = *(&llvm_cbe_tmp__533);
  llvm_cbe_tmp__546 = *((&llvm_cbe_tmp__545->field19));
  return llvm_cbe_tmp__546;
}


unsigned long long _ZN9model_RBM23cppUpdateFun_wr_requestElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__547;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__548;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__549;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__550;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__551;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__552;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__553;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__554;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__555;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__556;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__557;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__558;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__559;
  unsigned long long llvm_cbe_tmp__560;

  *(&llvm_cbe_tmp__547) = llvm_cbe_this;
  *(&llvm_cbe_tmp__548) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__549) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__550) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__551) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__552) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__553) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__554) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__555) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__556) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__557) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__558) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__559 = *(&llvm_cbe_tmp__547);
  llvm_cbe_tmp__560 = *((&llvm_cbe_tmp__559->field20));
  return llvm_cbe_tmp__560;
}


void _ZN9model_RBM6updateElllllllllll(struct l_class_OC_model_RBM *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__561;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__562;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__563;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__564;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__565;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__566;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__567;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__568;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__569;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__570;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__571;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__572;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_39;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_40;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_55;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_70;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_85;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_100;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_115;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_130;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_145;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_146;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_154;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_155;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_156;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_157;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_158;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_164;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_165;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_166;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_167;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_177;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__573;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__574;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__575;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__576;
  unsigned long long llvm_cbe_tmp__577;
  unsigned long long llvm_cbe_tmp__578;
  unsigned long long llvm_cbe_tmp__579;
  unsigned long long llvm_cbe_tmp__580;
  unsigned long long llvm_cbe_tmp__581;
  unsigned long long llvm_cbe_tmp__582;
  unsigned long long llvm_cbe_tmp__583;
  unsigned long long llvm_cbe_tmp__584;
  unsigned long long llvm_cbe_tmp__585;
  unsigned long long llvm_cbe_tmp__586;
  unsigned long long llvm_cbe_tmp__587;
  unsigned long long llvm_cbe_tmp__588;
  unsigned long long llvm_cbe_tmp__589;
  unsigned long long llvm_cbe_tmp__590;
  unsigned long long llvm_cbe_tmp__591;
  unsigned long long llvm_cbe_tmp__592;
  unsigned long long llvm_cbe_tmp__593;
  unsigned long long llvm_cbe_tmp__594;
  unsigned long long llvm_cbe_tmp__595;
  unsigned long long llvm_cbe_tmp__596;
  unsigned long long llvm_cbe_tmp__597;
  unsigned long long llvm_cbe_tmp__598;
  unsigned long long llvm_cbe_tmp__599;
  unsigned long long llvm_cbe_tmp__600;
  unsigned long long llvm_cbe_tmp__601;
  unsigned long long llvm_cbe_tmp__602;
  unsigned long long llvm_cbe_tmp__603;
  unsigned long long llvm_cbe_tmp__604;
  unsigned long long llvm_cbe_tmp__605;
  unsigned long long llvm_cbe_tmp__606;
  unsigned long long llvm_cbe_tmp__607;
  unsigned long long llvm_cbe_tmp__608;
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
  unsigned long long llvm_cbe_tmp__620;
  unsigned long long llvm_cbe_tmp__621;
  unsigned long long llvm_cbe_tmp__622;
  unsigned long long llvm_cbe_tmp__623;
  unsigned long long llvm_cbe_tmp__624;
  unsigned long long llvm_cbe_tmp__625;
  unsigned long long llvm_cbe_tmp__626;
  unsigned long long llvm_cbe_tmp__627;
  unsigned long long llvm_cbe_tmp__628;
  unsigned long long llvm_cbe_tmp__629;
  unsigned long long llvm_cbe_tmp__630;
  unsigned long long llvm_cbe_tmp__631;
  unsigned long long llvm_cbe_tmp__632;
  unsigned long long llvm_cbe_tmp__633;
  unsigned long long llvm_cbe_tmp__634;
  unsigned long long llvm_cbe_tmp__635;
  unsigned long long llvm_cbe_tmp__636;
  unsigned long long llvm_cbe_tmp__637;
  unsigned long long llvm_cbe_tmp__638;
  unsigned long long llvm_cbe_tmp__639;
  unsigned long long llvm_cbe_tmp__640;
  unsigned long long llvm_cbe_tmp__641;
  unsigned long long llvm_cbe_tmp__642;
  unsigned long long llvm_cbe_tmp__643;
  unsigned long long llvm_cbe_tmp__644;
  unsigned long long llvm_cbe_tmp__645;
  unsigned long long llvm_cbe_tmp__646;
  unsigned long long llvm_cbe_tmp__647;
  unsigned long long llvm_cbe_tmp__648;
  unsigned long long llvm_cbe_tmp__649;
  unsigned long long llvm_cbe_tmp__650;
  unsigned long long llvm_cbe_tmp__651;
  unsigned long long llvm_cbe_tmp__652;
  unsigned long long llvm_cbe_tmp__653;
  unsigned long long llvm_cbe_tmp__654;
  unsigned long long llvm_cbe_tmp__655;
  unsigned long long llvm_cbe_tmp__656;
  unsigned long long llvm_cbe_tmp__657;
  unsigned long long llvm_cbe_tmp__658;
  unsigned long long llvm_cbe_tmp__659;
  unsigned long long llvm_cbe_tmp__660;
  unsigned long long llvm_cbe_tmp__661;
  unsigned long long llvm_cbe_tmp__662;
  unsigned long long llvm_cbe_tmp__663;
  unsigned long long llvm_cbe_tmp__664;
  unsigned long long llvm_cbe_tmp__665;
  unsigned long long llvm_cbe_tmp__666;
  unsigned long long llvm_cbe_tmp__667;
  unsigned long long llvm_cbe_tmp__668;
  unsigned long long llvm_cbe_tmp__669;
  unsigned long long llvm_cbe_tmp__670;
  unsigned long long llvm_cbe_tmp__671;
  unsigned long long llvm_cbe_tmp__672;
  unsigned long long llvm_cbe_tmp__673;
  unsigned long long llvm_cbe_tmp__674;
  unsigned long long llvm_cbe_tmp__675;
  unsigned long long llvm_cbe_tmp__676;
  unsigned long long llvm_cbe_tmp__677;
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
  unsigned long long llvm_cbe_tmp__691;
  unsigned long long llvm_cbe_tmp__692;
  unsigned long long llvm_cbe_tmp__693;
  unsigned long long llvm_cbe_tmp__694;
  unsigned long long llvm_cbe_tmp__695;
  unsigned long long llvm_cbe_tmp__696;
  unsigned long long llvm_cbe_tmp__697;
  unsigned long long llvm_cbe_tmp__698;
  unsigned long long llvm_cbe_tmp__699;
  unsigned long long llvm_cbe_tmp__700;
  unsigned long long llvm_cbe_tmp__701;
  unsigned long long llvm_cbe_tmp__702;
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
  unsigned long long llvm_cbe_tmp__716;
  unsigned long long llvm_cbe_tmp__717;
  unsigned long long llvm_cbe_tmp__718;
  unsigned long long llvm_cbe_tmp__719;
  unsigned long long llvm_cbe_tmp__720;
  unsigned long long llvm_cbe_tmp__721;
  unsigned long long llvm_cbe_tmp__722;
  unsigned long long llvm_cbe_tmp__723;
  unsigned long long llvm_cbe_tmp__724;
  unsigned long long llvm_cbe_tmp__725;
  unsigned long long llvm_cbe_tmp__726;
  unsigned long long llvm_cbe_tmp__727;
  unsigned long long llvm_cbe_tmp__728;
  unsigned long long llvm_cbe_tmp__729;
  unsigned long long llvm_cbe_tmp__730;
  unsigned long long llvm_cbe_tmp__731;
  unsigned long long llvm_cbe_tmp__732;
  unsigned long long llvm_cbe_tmp__733;
  unsigned long long llvm_cbe_tmp__734;
  unsigned long long llvm_cbe_tmp__735;
  unsigned long long llvm_cbe_tmp__736;
  unsigned long long llvm_cbe_tmp__737;
  unsigned long long llvm_cbe_tmp__738;
  unsigned long long llvm_cbe_tmp__739;
  unsigned long long llvm_cbe_tmp__740;
  unsigned long long llvm_cbe_tmp__741;
  unsigned long long llvm_cbe_tmp__742;
  unsigned long long llvm_cbe_tmp__743;
  unsigned long long llvm_cbe_tmp__744;
  unsigned long long llvm_cbe_tmp__745;
  unsigned long long llvm_cbe_tmp__746;
  unsigned long long llvm_cbe_tmp__747;
  unsigned long long llvm_cbe_tmp__748;
  unsigned long long llvm_cbe_tmp__749;
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
  unsigned long long llvm_cbe_tmp__764;
  unsigned long long llvm_cbe_tmp__765;
  unsigned long long llvm_cbe_tmp__766;
  unsigned long long llvm_cbe_tmp__767;
  unsigned long long llvm_cbe_tmp__768;
  unsigned long long llvm_cbe_tmp__769;
  unsigned long long llvm_cbe_tmp__770;
  unsigned long long llvm_cbe_tmp__771;
  unsigned long long llvm_cbe_tmp__772;
  unsigned long long llvm_cbe_tmp__773;
  unsigned long long llvm_cbe_tmp__774;
  unsigned long long llvm_cbe_tmp__775;
  unsigned long long llvm_cbe_tmp__776;
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
  unsigned long long llvm_cbe_tmp__789;
  unsigned long long llvm_cbe_tmp__790;
  unsigned long long llvm_cbe_tmp__791;
  unsigned long long llvm_cbe_tmp__792;
  unsigned long long llvm_cbe_tmp__793;
  unsigned long long llvm_cbe_tmp__794;
  unsigned long long llvm_cbe_tmp__795;
  unsigned long long llvm_cbe_tmp__796;
  unsigned long long llvm_cbe_tmp__797;
  unsigned long long llvm_cbe_tmp__798;
  unsigned long long llvm_cbe_tmp__799;
  unsigned long long llvm_cbe_tmp__800;
  unsigned long long llvm_cbe_tmp__801;
  unsigned long long llvm_cbe_tmp__802;
  unsigned long long llvm_cbe_tmp__803;
  unsigned long long llvm_cbe_tmp__804;
  unsigned long long llvm_cbe_tmp__805;
  unsigned long long llvm_cbe_tmp__806;
  unsigned long long llvm_cbe_tmp__807;
  unsigned long long llvm_cbe_tmp__808;
  unsigned long long llvm_cbe_tmp__809;
  unsigned long long llvm_cbe_tmp__810;
  unsigned long long llvm_cbe_tmp__811;
  unsigned long long llvm_cbe_tmp__812;
  unsigned long long llvm_cbe_tmp__813;
  unsigned long long llvm_cbe_tmp__814;
  unsigned long long llvm_cbe_tmp__815;
  unsigned long long llvm_cbe_tmp__816;
  unsigned long long llvm_cbe_tmp__817;
  unsigned long long llvm_cbe_tmp__818;
  unsigned long long llvm_cbe_tmp__819;
  unsigned long long llvm_cbe_tmp__820;
  unsigned long long llvm_cbe_tmp__821;
  unsigned long long llvm_cbe_tmp__822;
  unsigned long long llvm_cbe_tmp__823;
  unsigned long long llvm_cbe_tmp__824;
  unsigned long long llvm_cbe_tmp__825;
  unsigned long long llvm_cbe_tmp__826;
  unsigned long long llvm_cbe_tmp__827;
  unsigned long long llvm_cbe_tmp__828;
  unsigned long long llvm_cbe_tmp__829;
  unsigned long long llvm_cbe_tmp__830;
  unsigned long long llvm_cbe_tmp__831;
  unsigned long long llvm_cbe_tmp__832;
  unsigned long long llvm_cbe_tmp__833;
  unsigned long long llvm_cbe_tmp__834;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__835;

  *(&llvm_cbe_tmp__561) = llvm_cbe_this;
  *(&llvm_cbe_tmp__562) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__563) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__564) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__565) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__566) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__567) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__568) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__569) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__570) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__571) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__572) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__576 = *(&llvm_cbe_tmp__561);
  llvm_cbe_tmp__577 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__578 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__579 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__580 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__581 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__582 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__583 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__584 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__585 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__586 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__587 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__588 = _ZN9model_RBM21cppUpdateFun_data_outElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__577, llvm_cbe_tmp__578, llvm_cbe_tmp__579, llvm_cbe_tmp__580, llvm_cbe_tmp__581, llvm_cbe_tmp__582, llvm_cbe_tmp__583, llvm_cbe_tmp__584, llvm_cbe_tmp__585, llvm_cbe_tmp__586, llvm_cbe_tmp__587);
  *(&llvm_cbe_cppVar_39) = llvm_cbe_tmp__588;
  llvm_cbe_tmp__589 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__590 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__591 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__592 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__593 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__594 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__595 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__596 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__597 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__598 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__599 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__600 = _ZN9model_RBM17cppUpdateFun_doneElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__589, llvm_cbe_tmp__590, llvm_cbe_tmp__591, llvm_cbe_tmp__592, llvm_cbe_tmp__593, llvm_cbe_tmp__594, llvm_cbe_tmp__595, llvm_cbe_tmp__596, llvm_cbe_tmp__597, llvm_cbe_tmp__598, llvm_cbe_tmp__599);
  *(&llvm_cbe_cppVar_40) = llvm_cbe_tmp__600;
  llvm_cbe_tmp__601 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__602 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__603 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__604 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__605 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__606 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__607 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__608 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__609 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__610 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__611 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__612 = _ZN9model_RBM22cppUpdateFun_init_doneElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__601, llvm_cbe_tmp__602, llvm_cbe_tmp__603, llvm_cbe_tmp__604, llvm_cbe_tmp__605, llvm_cbe_tmp__606, llvm_cbe_tmp__607, llvm_cbe_tmp__608, llvm_cbe_tmp__609, llvm_cbe_tmp__610, llvm_cbe_tmp__611);
  *(&llvm_cbe_cppVar_55) = llvm_cbe_tmp__612;
  llvm_cbe_tmp__613 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__614 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__615 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__616 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__617 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__618 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__619 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__620 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__621 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__622 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__623 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__624 = _ZN9model_RBM23cppUpdateFun_num_hiddenElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__613, llvm_cbe_tmp__614, llvm_cbe_tmp__615, llvm_cbe_tmp__616, llvm_cbe_tmp__617, llvm_cbe_tmp__618, llvm_cbe_tmp__619, llvm_cbe_tmp__620, llvm_cbe_tmp__621, llvm_cbe_tmp__622, llvm_cbe_tmp__623);
  *(&llvm_cbe_cppVar_70) = llvm_cbe_tmp__624;
  llvm_cbe_tmp__625 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__626 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__627 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__628 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__629 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__630 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__631 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__632 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__633 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__634 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__635 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__636 = _ZN9model_RBM22cppUpdateFun_num_loopsElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__625, llvm_cbe_tmp__626, llvm_cbe_tmp__627, llvm_cbe_tmp__628, llvm_cbe_tmp__629, llvm_cbe_tmp__630, llvm_cbe_tmp__631, llvm_cbe_tmp__632, llvm_cbe_tmp__633, llvm_cbe_tmp__634, llvm_cbe_tmp__635);
  *(&llvm_cbe_cppVar_85) = llvm_cbe_tmp__636;
  llvm_cbe_tmp__637 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__638 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__639 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__640 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__641 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__642 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__643 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__644 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__645 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__646 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__647 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__648 = _ZN9model_RBM23cppUpdateFun_num_moviesElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__637, llvm_cbe_tmp__638, llvm_cbe_tmp__639, llvm_cbe_tmp__640, llvm_cbe_tmp__641, llvm_cbe_tmp__642, llvm_cbe_tmp__643, llvm_cbe_tmp__644, llvm_cbe_tmp__645, llvm_cbe_tmp__646, llvm_cbe_tmp__647);
  *(&llvm_cbe_cppVar_100) = llvm_cbe_tmp__648;
  llvm_cbe_tmp__649 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__650 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__651 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__652 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__653 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__654 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__655 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__656 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__657 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__658 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__659 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__660 = _ZN9model_RBM26cppUpdateFun_num_testusersElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__649, llvm_cbe_tmp__650, llvm_cbe_tmp__651, llvm_cbe_tmp__652, llvm_cbe_tmp__653, llvm_cbe_tmp__654, llvm_cbe_tmp__655, llvm_cbe_tmp__656, llvm_cbe_tmp__657, llvm_cbe_tmp__658, llvm_cbe_tmp__659);
  *(&llvm_cbe_cppVar_115) = llvm_cbe_tmp__660;
  llvm_cbe_tmp__661 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__662 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__663 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__664 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__665 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__666 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__667 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__668 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__669 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__670 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__671 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__672 = _ZN9model_RBM22cppUpdateFun_num_usersElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__661, llvm_cbe_tmp__662, llvm_cbe_tmp__663, llvm_cbe_tmp__664, llvm_cbe_tmp__665, llvm_cbe_tmp__666, llvm_cbe_tmp__667, llvm_cbe_tmp__668, llvm_cbe_tmp__669, llvm_cbe_tmp__670, llvm_cbe_tmp__671);
  *(&llvm_cbe_cppVar_130) = llvm_cbe_tmp__672;
  llvm_cbe_tmp__673 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__674 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__675 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__676 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__677 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__678 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__679 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__680 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__681 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__682 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__683 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__684 = _ZN9model_RBM24cppUpdateFun_num_visibleElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__673, llvm_cbe_tmp__674, llvm_cbe_tmp__675, llvm_cbe_tmp__676, llvm_cbe_tmp__677, llvm_cbe_tmp__678, llvm_cbe_tmp__679, llvm_cbe_tmp__680, llvm_cbe_tmp__681, llvm_cbe_tmp__682, llvm_cbe_tmp__683);
  *(&llvm_cbe_cppVar_145) = llvm_cbe_tmp__684;
  llvm_cbe_tmp__685 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__686 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__687 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__688 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__689 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__690 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__691 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__692 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__693 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__694 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__695 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__696 = _ZN9model_RBM24cppUpdateFun_rd_completeElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__685, llvm_cbe_tmp__686, llvm_cbe_tmp__687, llvm_cbe_tmp__688, llvm_cbe_tmp__689, llvm_cbe_tmp__690, llvm_cbe_tmp__691, llvm_cbe_tmp__692, llvm_cbe_tmp__693, llvm_cbe_tmp__694, llvm_cbe_tmp__695);
  *(&llvm_cbe_cppVar_146) = llvm_cbe_tmp__696;
  llvm_cbe_tmp__697 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__698 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__699 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__700 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__701 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__702 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__703 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__704 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__705 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__706 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__707 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__708 = _ZN9model_RBM23cppUpdateFun_rd_grantedElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__697, llvm_cbe_tmp__698, llvm_cbe_tmp__699, llvm_cbe_tmp__700, llvm_cbe_tmp__701, llvm_cbe_tmp__702, llvm_cbe_tmp__703, llvm_cbe_tmp__704, llvm_cbe_tmp__705, llvm_cbe_tmp__706, llvm_cbe_tmp__707);
  *(&llvm_cbe_cppVar_154) = llvm_cbe_tmp__708;
  llvm_cbe_tmp__709 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__710 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__711 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__712 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__713 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__714 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__715 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__716 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__717 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__718 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__719 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__720 = _ZN9model_RBM21cppUpdateFun_rd_indexElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__709, llvm_cbe_tmp__710, llvm_cbe_tmp__711, llvm_cbe_tmp__712, llvm_cbe_tmp__713, llvm_cbe_tmp__714, llvm_cbe_tmp__715, llvm_cbe_tmp__716, llvm_cbe_tmp__717, llvm_cbe_tmp__718, llvm_cbe_tmp__719);
  *(&llvm_cbe_cppVar_155) = llvm_cbe_tmp__720;
  llvm_cbe_tmp__721 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__722 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__723 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__724 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__725 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__726 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__727 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__728 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__729 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__730 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__731 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__732 = _ZN9model_RBM22cppUpdateFun_rd_lengthElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__721, llvm_cbe_tmp__722, llvm_cbe_tmp__723, llvm_cbe_tmp__724, llvm_cbe_tmp__725, llvm_cbe_tmp__726, llvm_cbe_tmp__727, llvm_cbe_tmp__728, llvm_cbe_tmp__729, llvm_cbe_tmp__730, llvm_cbe_tmp__731);
  *(&llvm_cbe_cppVar_156) = llvm_cbe_tmp__732;
  llvm_cbe_tmp__733 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__734 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__735 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__736 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__737 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__738 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__739 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__740 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__741 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__742 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__743 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__744 = _ZN9model_RBM23cppUpdateFun_rd_requestElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__733, llvm_cbe_tmp__734, llvm_cbe_tmp__735, llvm_cbe_tmp__736, llvm_cbe_tmp__737, llvm_cbe_tmp__738, llvm_cbe_tmp__739, llvm_cbe_tmp__740, llvm_cbe_tmp__741, llvm_cbe_tmp__742, llvm_cbe_tmp__743);
  *(&llvm_cbe_cppVar_157) = llvm_cbe_tmp__744;
  llvm_cbe_tmp__745 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__746 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__747 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__748 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__749 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__750 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__751 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__752 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__753 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__754 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__755 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__756 = _ZN9model_RBM24cppUpdateFun_wr_completeElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__745, llvm_cbe_tmp__746, llvm_cbe_tmp__747, llvm_cbe_tmp__748, llvm_cbe_tmp__749, llvm_cbe_tmp__750, llvm_cbe_tmp__751, llvm_cbe_tmp__752, llvm_cbe_tmp__753, llvm_cbe_tmp__754, llvm_cbe_tmp__755);
  *(&llvm_cbe_cppVar_158) = llvm_cbe_tmp__756;
  llvm_cbe_tmp__757 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__758 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__759 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__760 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__761 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__762 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__763 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__764 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__765 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__766 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__767 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__768 = _ZN9model_RBM23cppUpdateFun_wr_grantedElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__757, llvm_cbe_tmp__758, llvm_cbe_tmp__759, llvm_cbe_tmp__760, llvm_cbe_tmp__761, llvm_cbe_tmp__762, llvm_cbe_tmp__763, llvm_cbe_tmp__764, llvm_cbe_tmp__765, llvm_cbe_tmp__766, llvm_cbe_tmp__767);
  *(&llvm_cbe_cppVar_164) = llvm_cbe_tmp__768;
  llvm_cbe_tmp__769 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__770 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__771 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__772 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__773 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__774 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__775 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__776 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__777 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__778 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__779 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__780 = _ZN9model_RBM21cppUpdateFun_wr_indexElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__769, llvm_cbe_tmp__770, llvm_cbe_tmp__771, llvm_cbe_tmp__772, llvm_cbe_tmp__773, llvm_cbe_tmp__774, llvm_cbe_tmp__775, llvm_cbe_tmp__776, llvm_cbe_tmp__777, llvm_cbe_tmp__778, llvm_cbe_tmp__779);
  *(&llvm_cbe_cppVar_165) = llvm_cbe_tmp__780;
  llvm_cbe_tmp__781 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__782 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__783 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__784 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__785 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__786 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__787 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__788 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__789 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__790 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__791 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__792 = _ZN9model_RBM22cppUpdateFun_wr_lengthElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__781, llvm_cbe_tmp__782, llvm_cbe_tmp__783, llvm_cbe_tmp__784, llvm_cbe_tmp__785, llvm_cbe_tmp__786, llvm_cbe_tmp__787, llvm_cbe_tmp__788, llvm_cbe_tmp__789, llvm_cbe_tmp__790, llvm_cbe_tmp__791);
  *(&llvm_cbe_cppVar_166) = llvm_cbe_tmp__792;
  llvm_cbe_tmp__793 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__794 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__795 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__796 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__797 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__798 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__799 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__800 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__801 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__802 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__803 = *(&llvm_cbe_tmp__572);
  llvm_cbe_tmp__804 = _ZN9model_RBM23cppUpdateFun_wr_requestElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__793, llvm_cbe_tmp__794, llvm_cbe_tmp__795, llvm_cbe_tmp__796, llvm_cbe_tmp__797, llvm_cbe_tmp__798, llvm_cbe_tmp__799, llvm_cbe_tmp__800, llvm_cbe_tmp__801, llvm_cbe_tmp__802, llvm_cbe_tmp__803);
  *(&llvm_cbe_cppVar_167) = llvm_cbe_tmp__804;
  llvm_cbe_tmp__805 = *(&llvm_cbe_tmp__562);
  llvm_cbe_tmp__806 = *(&llvm_cbe_tmp__563);
  llvm_cbe_tmp__807 = *(&llvm_cbe_tmp__564);
  llvm_cbe_tmp__808 = *(&llvm_cbe_tmp__565);
  llvm_cbe_tmp__809 = *(&llvm_cbe_tmp__566);
  llvm_cbe_tmp__810 = *(&llvm_cbe_tmp__567);
  llvm_cbe_tmp__811 = *(&llvm_cbe_tmp__568);
  llvm_cbe_tmp__812 = *(&llvm_cbe_tmp__569);
  llvm_cbe_tmp__813 = *(&llvm_cbe_tmp__570);
  llvm_cbe_tmp__814 = *(&llvm_cbe_tmp__571);
  llvm_cbe_tmp__815 = *(&llvm_cbe_tmp__572);
  llvm_cbe_cppVar_177 = _ZN9model_RBM17cppUpdateFun_dataElllllllllll(llvm_cbe_tmp__576, llvm_cbe_tmp__805, llvm_cbe_tmp__806, llvm_cbe_tmp__807, llvm_cbe_tmp__808, llvm_cbe_tmp__809, llvm_cbe_tmp__810, llvm_cbe_tmp__811, llvm_cbe_tmp__812, llvm_cbe_tmp__813, llvm_cbe_tmp__814, llvm_cbe_tmp__815);
  llvm_cbe_tmp__816 = *(&llvm_cbe_cppVar_39);
  *((&llvm_cbe_tmp__576->field1)) = llvm_cbe_tmp__816;
  llvm_cbe_tmp__817 = *(&llvm_cbe_cppVar_40);
  *((&llvm_cbe_tmp__576->field2)) = llvm_cbe_tmp__817;
  llvm_cbe_tmp__818 = *(&llvm_cbe_cppVar_55);
  *((&llvm_cbe_tmp__576->field3)) = llvm_cbe_tmp__818;
  llvm_cbe_tmp__819 = *(&llvm_cbe_cppVar_70);
  *((&llvm_cbe_tmp__576->field4)) = llvm_cbe_tmp__819;
  llvm_cbe_tmp__820 = *(&llvm_cbe_cppVar_85);
  *((&llvm_cbe_tmp__576->field5)) = llvm_cbe_tmp__820;
  llvm_cbe_tmp__821 = *(&llvm_cbe_cppVar_100);
  *((&llvm_cbe_tmp__576->field6)) = llvm_cbe_tmp__821;
  llvm_cbe_tmp__822 = *(&llvm_cbe_cppVar_115);
  *((&llvm_cbe_tmp__576->field7)) = llvm_cbe_tmp__822;
  llvm_cbe_tmp__823 = *(&llvm_cbe_cppVar_130);
  *((&llvm_cbe_tmp__576->field8)) = llvm_cbe_tmp__823;
  llvm_cbe_tmp__824 = *(&llvm_cbe_cppVar_145);
  *((&llvm_cbe_tmp__576->field9)) = llvm_cbe_tmp__824;
  llvm_cbe_tmp__825 = *(&llvm_cbe_cppVar_146);
  *((&llvm_cbe_tmp__576->field11)) = llvm_cbe_tmp__825;
  llvm_cbe_tmp__826 = *(&llvm_cbe_cppVar_154);
  *((&llvm_cbe_tmp__576->field12)) = llvm_cbe_tmp__826;
  llvm_cbe_tmp__827 = *(&llvm_cbe_cppVar_155);
  *((&llvm_cbe_tmp__576->field13)) = llvm_cbe_tmp__827;
  llvm_cbe_tmp__828 = *(&llvm_cbe_cppVar_156);
  *((&llvm_cbe_tmp__576->field14)) = llvm_cbe_tmp__828;
  llvm_cbe_tmp__829 = *(&llvm_cbe_cppVar_157);
  *((&llvm_cbe_tmp__576->field15)) = llvm_cbe_tmp__829;
  llvm_cbe_tmp__830 = *(&llvm_cbe_cppVar_158);
  *((&llvm_cbe_tmp__576->field16)) = llvm_cbe_tmp__830;
  llvm_cbe_tmp__831 = *(&llvm_cbe_cppVar_164);
  *((&llvm_cbe_tmp__576->field17)) = llvm_cbe_tmp__831;
  llvm_cbe_tmp__832 = *(&llvm_cbe_cppVar_165);
  *((&llvm_cbe_tmp__576->field18)) = llvm_cbe_tmp__832;
  llvm_cbe_tmp__833 = *(&llvm_cbe_cppVar_166);
  *((&llvm_cbe_tmp__576->field19)) = llvm_cbe_tmp__833;
  llvm_cbe_tmp__834 = *(&llvm_cbe_cppVar_167);
  *((&llvm_cbe_tmp__576->field20)) = llvm_cbe_tmp__834;
  llvm_cbe_tmp__835 = _ZN8type_memIhLj512EEaSERKS0_(((&llvm_cbe_tmp__576->field0)), (&llvm_cbe_cppVar_177));
  *(&llvm_cbe_tmp__575) = 1u;
  _ZN8type_memIhLj512EED1Ev((&llvm_cbe_cppVar_177));
  return;
}


static void __cxx_global_var_init(void) {
  unsigned int llvm_cbe_tmp__836;

  _ZN9model_RBMC1Ev((&GM));
  llvm_cbe_tmp__836 = __cxa_atexit(((void  (*) (unsigned char *))_ZN9model_RBMD1Ev), ((unsigned char *)(&GM)), ((unsigned char *)(&__dso_handle)));
  return;
}


void _ZN9model_RBMC1Ev(struct l_class_OC_model_RBM *llvm_cbe_this) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__837;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__838;

  *(&llvm_cbe_tmp__837) = llvm_cbe_this;
  llvm_cbe_tmp__838 = *(&llvm_cbe_tmp__837);
  _ZN9model_RBMC2Ev(llvm_cbe_tmp__838);
  return;
}


void _ZN9model_RBMD1Ev(struct l_class_OC_model_RBM *llvm_cbe_this) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__839;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__840;

  *(&llvm_cbe_tmp__839) = llvm_cbe_this;
  llvm_cbe_tmp__840 = *(&llvm_cbe_tmp__839);
  _ZN9model_RBMD2Ev(llvm_cbe_tmp__840);
  return;
}


void _Z4waitv(void) {
  unsigned int llvm_cbe_tmp__841;

  llvm_cbe_tmp__841 = *(&cycleCnt);
  *(&cycleCnt) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__841) + ((unsigned int )1u))));
  return;
}


void _Z15reset_signal_isib(unsigned int llvm_cbe_tmp__842, bool llvm_cbe_tmp__843) {
  unsigned int llvm_cbe_tmp__844;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__845;    /* Address-exposed local */

  *(&llvm_cbe_tmp__844) = llvm_cbe_tmp__842;
  *(&llvm_cbe_tmp__845) = (((unsigned char )(bool )llvm_cbe_tmp__843));
  return;
}


void _Z14set_stack_sizei(unsigned int llvm_cbe_tmp__846) {
  unsigned int llvm_cbe_tmp__847;    /* Address-exposed local */

  *(&llvm_cbe_tmp__847) = llvm_cbe_tmp__846;
  return;
}


void _ZN3rbm6configEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__848;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__849;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__850;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__851;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__852;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__853;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__854;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__855;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__856;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__857;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__858;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__859;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__860;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__861;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__862;
  bool llvm_cbe_tmp__863;
  unsigned int llvm_cbe_tmp__864;
  unsigned int llvm_cbe_tmp__865;
  unsigned int llvm_cbe_tmp__866;
  unsigned int llvm_cbe_tmp__867;
  unsigned int llvm_cbe_tmp__868;
  unsigned int llvm_cbe_tmp__869;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__870;
  unsigned int llvm_cbe_tmp__871;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__872;

  *(&llvm_cbe_tmp__848) = llvm_cbe_this;
  llvm_cbe_tmp__862 = *(&llvm_cbe_tmp__848);
  *(&llvm_cbe_tmp__849) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field30)), (&llvm_cbe_tmp__849));
  *(&llvm_cbe_tmp__850) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field31)), (&llvm_cbe_tmp__850));
  *(&llvm_cbe_tmp__851) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field32)), (&llvm_cbe_tmp__851));
  *(&llvm_cbe_tmp__852) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field33)), (&llvm_cbe_tmp__852));
  *(&llvm_cbe_tmp__853) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field35)), (&llvm_cbe_tmp__853));
  *(&llvm_cbe_tmp__854) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__862->field36)), (&llvm_cbe_tmp__854));
  _Z4waitv();
  goto llvm_cbe_tmp__873;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__873:
  _Z4waitv();
  llvm_cbe_tmp__863 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__862->field13))))&1);
  if ((((llvm_cbe_tmp__863 ^ 1)&1))) {
    goto llvm_cbe_tmp__873;
  } else {
    goto llvm_cbe_tmp__874;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__874:
  llvm_cbe_tmp__864 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__862->field14)));
  *(&llvm_cbe_tmp__855) = (((unsigned short )llvm_cbe_tmp__864));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field30)), (&llvm_cbe_tmp__855));
  llvm_cbe_tmp__865 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__862->field15)));
  *(&llvm_cbe_tmp__856) = (((unsigned short )llvm_cbe_tmp__865));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field31)), (&llvm_cbe_tmp__856));
  llvm_cbe_tmp__866 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__862->field16)));
  *(&llvm_cbe_tmp__857) = (((unsigned short )llvm_cbe_tmp__866));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field32)), (&llvm_cbe_tmp__857));
  llvm_cbe_tmp__867 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__862->field17)));
  *(&llvm_cbe_tmp__858) = (((unsigned short )llvm_cbe_tmp__867));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field33)), (&llvm_cbe_tmp__858));
  llvm_cbe_tmp__868 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__862->field18)));
  *(&llvm_cbe_tmp__859) = (((unsigned short )llvm_cbe_tmp__868));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field34)), (&llvm_cbe_tmp__859));
  llvm_cbe_tmp__869 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__862->field19)));
  *(&llvm_cbe_tmp__860) = (((unsigned short )llvm_cbe_tmp__869));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__862->field35)), (&llvm_cbe_tmp__860));
  llvm_cbe_tmp__870 = _ZNSt6iocoutlsEPKc((&_ZSt4cout), ((&_OC_str.array[((signed int )0u)])));
  llvm_cbe_tmp__871 = *(&_ZSt4endl);
  llvm_cbe_tmp__872 = _ZNSt6iocoutlsEi(llvm_cbe_tmp__870, llvm_cbe_tmp__871);
  *(&llvm_cbe_tmp__861) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__862->field36)), (&llvm_cbe_tmp__861));
  goto llvm_cbe_tmp__875;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__875:
  _Z4waitv();
  goto llvm_cbe_tmp__875;

  } while (1); /* end of syntactic loop '' */
}


void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__876;    /* Address-exposed local */
  unsigned short *llvm_cbe_tmp__877;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__878;
  unsigned short *llvm_cbe_tmp__879;
  unsigned short llvm_cbe_tmp__880;

  *(&llvm_cbe_tmp__876) = llvm_cbe_this;
  *(&llvm_cbe_tmp__877) = llvm_cbe_d;
  llvm_cbe_tmp__878 = *(&llvm_cbe_tmp__876);
  llvm_cbe_tmp__879 = *(&llvm_cbe_tmp__877);
  llvm_cbe_tmp__880 = *llvm_cbe_tmp__879;
  *((&llvm_cbe_tmp__878->field0)) = llvm_cbe_tmp__880;
  return;
}


void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__881;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__882;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__883;
  unsigned char *llvm_cbe_tmp__884;
  unsigned char llvm_cbe_tmp__885;

  *(&llvm_cbe_tmp__881) = llvm_cbe_this;
  *(&llvm_cbe_tmp__882) = llvm_cbe_d;
  llvm_cbe_tmp__883 = *(&llvm_cbe_tmp__881);
  llvm_cbe_tmp__884 = *(&llvm_cbe_tmp__882);
  llvm_cbe_tmp__885 = *llvm_cbe_tmp__884;
  *((&llvm_cbe_tmp__883->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__885&1u))&1))));
  return;
}


bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__886;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__887;
  unsigned char llvm_cbe_tmp__888;

  *(&llvm_cbe_tmp__886) = llvm_cbe_this;
  llvm_cbe_tmp__887 = *(&llvm_cbe_tmp__886);
  llvm_cbe_tmp__888 = *((&llvm_cbe_tmp__887->field0));
  return (((((bool )llvm_cbe_tmp__888&1u))&1));
}


unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__889;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__890;
  unsigned int llvm_cbe_tmp__891;

  *(&llvm_cbe_tmp__889) = llvm_cbe_this;
  llvm_cbe_tmp__890 = *(&llvm_cbe_tmp__889);
  llvm_cbe_tmp__891 = *((&llvm_cbe_tmp__890->field0));
  return llvm_cbe_tmp__891;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_tmp__892) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__893;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__894;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__895;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__896;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__897;

  *(&llvm_cbe_tmp__894) = llvm_cbe_this;
  *(&llvm_cbe_tmp__895) = llvm_cbe_tmp__892;
  llvm_cbe_tmp__896 = *(&llvm_cbe_tmp__894);
  llvm_cbe_tmp__897 = *(&llvm_cbe_tmp__893);
  return llvm_cbe_tmp__897;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEi(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned int llvm_cbe_tmp__898) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__899;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__900;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__901;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__902;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__903;

  *(&llvm_cbe_tmp__900) = llvm_cbe_this;
  *(&llvm_cbe_tmp__901) = llvm_cbe_tmp__898;
  llvm_cbe_tmp__902 = *(&llvm_cbe_tmp__900);
  llvm_cbe_tmp__903 = *(&llvm_cbe_tmp__899);
  return llvm_cbe_tmp__903;
}


void _ZN3rbm4loadEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__904;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__905;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__906;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__907;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__908;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__909;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__910;    /* Address-exposed local */
  unsigned int llvm_cbe_nv;    /* Address-exposed local */
  unsigned int llvm_cbe_ntu;    /* Address-exposed local */
  unsigned int llvm_cbe_nu;    /* Address-exposed local */
  unsigned int llvm_cbe_nlp;    /* Address-exposed local */
  unsigned int llvm_cbe_nm;    /* Address-exposed local */
  unsigned short llvm_cbe_index;    /* Address-exposed local */
  unsigned short llvm_cbe_loop_count;    /* Address-exposed local */
  unsigned char llvm_cbe_pingpong;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__911;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__912;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__913;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__914;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned char llvm_cbe_rate;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__915;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__916;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__917;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__918;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__919;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__920;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__921;    /* Address-exposed local */
  unsigned short llvm_cbe_i1;    /* Address-exposed local */
  unsigned char llvm_cbe_rate2;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__922;
  bool llvm_cbe_tmp__923;
  bool llvm_cbe_tmp__924;
  unsigned short llvm_cbe_tmp__925;
  unsigned short llvm_cbe_tmp__926;
  unsigned short llvm_cbe_tmp__927;
  unsigned short llvm_cbe_tmp__928;
  unsigned short llvm_cbe_tmp__929;
  unsigned short llvm_cbe_tmp__930;
  unsigned int llvm_cbe_tmp__931;
  unsigned short llvm_cbe_tmp__932;
  unsigned int llvm_cbe_tmp__933;
  bool llvm_cbe_tmp__934;
  bool llvm_cbe_tmp__935;
  unsigned short llvm_cbe_tmp__936;
  unsigned int llvm_cbe_tmp__937;
  unsigned short llvm_cbe_tmp__938;
  unsigned short llvm_cbe_tmp__939;
  unsigned short llvm_cbe_tmp__940;
  unsigned short llvm_cbe_tmp__941;
  unsigned short llvm_cbe_tmp__942;
  unsigned int llvm_cbe_tmp__943;
  unsigned int llvm_cbe_tmp__944;
  unsigned char llvm_cbe_tmp__945;
  unsigned short llvm_cbe_tmp__946;
  unsigned char llvm_cbe_tmp__947;
  unsigned char *llvm_cbe_tmp__948;
  unsigned short llvm_cbe_tmp__949;
  unsigned int llvm_cbe_tmp__950;
  unsigned char llvm_cbe_tmp__951;
  unsigned char *llvm_cbe_tmp__952;
  unsigned short llvm_cbe_tmp__953;
  unsigned int llvm_cbe_tmp__954;
  bool llvm_cbe_tmp__955;
  bool llvm_cbe_tmp__956;
  bool llvm_cbe_tmp__957;
  bool llvm_cbe_tmp__958;
  unsigned short llvm_cbe_tmp__959;
  unsigned short llvm_cbe_tmp__960;
  unsigned int llvm_cbe_tmp__961;
  unsigned short llvm_cbe_tmp__962;
  unsigned int llvm_cbe_tmp__963;
  unsigned short llvm_cbe_tmp__964;
  unsigned short llvm_cbe_tmp__965;
  unsigned int llvm_cbe_tmp__966;
  unsigned short llvm_cbe_tmp__967;
  unsigned int llvm_cbe_tmp__968;
  unsigned int llvm_cbe_tmp__969;
  unsigned short llvm_cbe_tmp__970;
  unsigned short llvm_cbe_tmp__971;
  unsigned int llvm_cbe_tmp__972;
  unsigned int llvm_cbe_tmp__973;
  unsigned int llvm_cbe_tmp__974;
  unsigned int llvm_cbe_tmp__975;
  unsigned int llvm_cbe_tmp__976;
  unsigned short llvm_cbe_tmp__977;
  unsigned int llvm_cbe_tmp__978;
  bool llvm_cbe_tmp__979;
  bool llvm_cbe_tmp__980;
  unsigned short llvm_cbe_tmp__981;
  unsigned int llvm_cbe_tmp__982;
  unsigned short llvm_cbe_tmp__983;
  unsigned short llvm_cbe_tmp__984;
  unsigned short llvm_cbe_tmp__985;
  unsigned short llvm_cbe_tmp__986;
  unsigned short llvm_cbe_tmp__987;
  unsigned int llvm_cbe_tmp__988;
  unsigned int llvm_cbe_tmp__989;
  unsigned char llvm_cbe_tmp__990;
  unsigned short llvm_cbe_tmp__991;
  unsigned char llvm_cbe_tmp__992;
  unsigned char *llvm_cbe_tmp__993;
  unsigned short llvm_cbe_tmp__994;
  unsigned int llvm_cbe_tmp__995;
  unsigned char llvm_cbe_tmp__996;
  unsigned char *llvm_cbe_tmp__997;

  *(&llvm_cbe_tmp__904) = llvm_cbe_this;
  llvm_cbe_tmp__922 = *(&llvm_cbe_tmp__904);
  *(&llvm_cbe_tmp__905) = ((unsigned char )1);
  llvm_cbe_tmp__923 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__922->field36)), (&llvm_cbe_tmp__905)))&1);
  *(&llvm_cbe_tmp__906) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__922->field2)), (&llvm_cbe_tmp__906));
  *(&llvm_cbe_tmp__907) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__922->field3)), (&llvm_cbe_tmp__907));
  *(&llvm_cbe_tmp__908) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field4)), (&llvm_cbe_tmp__908));
  *(&llvm_cbe_tmp__909) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field37)), (&llvm_cbe_tmp__909));
  *(&llvm_cbe_tmp__910) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field38)), (&llvm_cbe_tmp__910));
  goto llvm_cbe_tmp__998;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__998:
  _Z4waitv();
  llvm_cbe_tmp__924 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field36))))&1);
  if ((((llvm_cbe_tmp__924 ^ 1)&1))) {
    goto llvm_cbe_tmp__998;
  } else {
    goto llvm_cbe_tmp__999;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__999:
  llvm_cbe_tmp__925 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__922->field31)));
  *(&llvm_cbe_nv) = (((unsigned int )(unsigned short )llvm_cbe_tmp__925));
  llvm_cbe_tmp__926 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__922->field34)));
  *(&llvm_cbe_ntu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__926));
  llvm_cbe_tmp__927 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__922->field32)));
  *(&llvm_cbe_nu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__927));
  llvm_cbe_tmp__928 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__922->field33)));
  *(&llvm_cbe_nlp) = (((unsigned int )(unsigned short )llvm_cbe_tmp__928));
  llvm_cbe_tmp__929 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__922->field35)));
  *(&llvm_cbe_nm) = (((unsigned int )(unsigned short )llvm_cbe_tmp__929));
  *(&llvm_cbe_index) = ((unsigned short )0);
  *(&llvm_cbe_loop_count) = ((unsigned short )0);
  *(&llvm_cbe_pingpong) = ((unsigned char )0);
  llvm_cbe_tmp__930 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp__911) = (((unsigned int )(unsigned short )llvm_cbe_tmp__930));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__922->field2)), (&llvm_cbe_tmp__911));
  llvm_cbe_tmp__931 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__912) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__931))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__922->field3)), (&llvm_cbe_tmp__912));
  llvm_cbe_tmp__932 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__933 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__932)) == llvm_cbe_tmp__933)) {
    goto llvm_cbe_tmp__1000;
  } else {
    goto llvm_cbe_tmp__1001;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1000:
  _Z4waitv();
  llvm_cbe_tmp__934 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field40))))&1);
  if ((((llvm_cbe_tmp__934 ^ 1)&1))) {
    goto llvm_cbe_tmp__1000;
  } else {
    goto llvm_cbe_tmp__1001;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1001:
  *(&llvm_cbe_tmp__913) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field4)), (&llvm_cbe_tmp__913));
  goto llvm_cbe_tmp__1002;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1002:
  _Z4waitv();
  llvm_cbe_tmp__935 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field5))))&1);
  if ((((llvm_cbe_tmp__935 ^ 1)&1))) {
    goto llvm_cbe_tmp__1002;
  } else {
    goto llvm_cbe_tmp__1003;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1003:
  *(&llvm_cbe_tmp__914) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field4)), (&llvm_cbe_tmp__914));
  llvm_cbe_tmp__936 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__937 = *(&llvm_cbe_nu);
  *(&llvm_cbe_tmp1) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__936))) * ((unsigned int )llvm_cbe_tmp__937))))));
  llvm_cbe_tmp__938 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__939 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp2) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__938))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__939))))))));
  llvm_cbe_tmp__940 = *(&llvm_cbe_tmp2);
  *(&llvm_cbe_pingpong) = (((unsigned char )(bool )((((signed int )(((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__940))) % ((signed int )2u)))) != 0u)));
  *(&llvm_cbe_i) = ((unsigned short )0);
  goto llvm_cbe_tmp__1004;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1004:
  llvm_cbe_tmp__941 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__941))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__1005;
  } else {
    goto llvm_cbe_tmp__1006;
  }

llvm_cbe_tmp__1007:
  llvm_cbe_tmp__944 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__922->field6)));
  *(&llvm_cbe_rate) = (((unsigned char )llvm_cbe_tmp__944));
  _Z4waitv();
  llvm_cbe_tmp__945 = *(&llvm_cbe_rate);
  llvm_cbe_tmp__946 = *(&llvm_cbe_i);
  llvm_cbe_tmp__947 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__948 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__922->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__947&1u))&1)))));
  *((&llvm_cbe_tmp__948[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__946)))])) = llvm_cbe_tmp__945;
  llvm_cbe_tmp__949 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__949) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__1004;

llvm_cbe_tmp__1005:
  llvm_cbe_tmp__942 = *(&llvm_cbe_i);
  llvm_cbe_tmp__943 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__942)) == llvm_cbe_tmp__943)) {
    goto llvm_cbe_tmp__1006;
  } else {
    goto llvm_cbe_tmp__1007;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1006:
  _Z4waitv();
  llvm_cbe_tmp__950 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__951 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__952 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__922->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__951&1u))&1)))));
  *((&llvm_cbe_tmp__952[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__950)))])) = ((unsigned char )1);
  goto llvm_cbe_tmp__1008;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1008:
  llvm_cbe_tmp__953 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__954 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__953)) != llvm_cbe_tmp__954)) {
    goto llvm_cbe_tmp__1009;
  } else {
    goto llvm_cbe_tmp__1010;
  }

llvm_cbe_tmp__1011:
  _Z4waitv();
  llvm_cbe_tmp__995 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__996 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__997 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__922->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__996&1u))&1)))));
  *((&llvm_cbe_tmp__997[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__995)))])) = ((unsigned char )1);
  goto llvm_cbe_tmp__1008;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1012:
  llvm_cbe_tmp__986 = *(&llvm_cbe_i1);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__986))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__1013;
  } else {
    goto llvm_cbe_tmp__1011;
  }

llvm_cbe_tmp__1014:
  llvm_cbe_tmp__989 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__922->field6)));
  *(&llvm_cbe_rate2) = (((unsigned char )llvm_cbe_tmp__989));
  _Z4waitv();
  llvm_cbe_tmp__990 = *(&llvm_cbe_rate2);
  llvm_cbe_tmp__991 = *(&llvm_cbe_i1);
  llvm_cbe_tmp__992 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__993 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__922->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__992&1u))&1)))));
  *((&llvm_cbe_tmp__993[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__991)))])) = llvm_cbe_tmp__990;
  llvm_cbe_tmp__994 = *(&llvm_cbe_i1);
  *(&llvm_cbe_i1) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__994) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__1012;

llvm_cbe_tmp__1013:
  llvm_cbe_tmp__987 = *(&llvm_cbe_i1);
  llvm_cbe_tmp__988 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__987)) == llvm_cbe_tmp__988)) {
    goto llvm_cbe_tmp__1011;
  } else {
    goto llvm_cbe_tmp__1014;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1015:
  *(&llvm_cbe_tmp__921) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field4)), (&llvm_cbe_tmp__921));
  llvm_cbe_tmp__981 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__982 = *(&llvm_cbe_nu);
  *(&llvm_cbe_tmp1) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__981))) * ((unsigned int )llvm_cbe_tmp__982))))));
  llvm_cbe_tmp__983 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__984 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp2) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__983))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__984))))))));
  llvm_cbe_tmp__985 = *(&llvm_cbe_tmp2);
  *(&llvm_cbe_pingpong) = (((unsigned char )(bool )((((signed int )(((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__985))) % ((signed int )2u)))) != 0u)));
  *(&llvm_cbe_i1) = ((unsigned short )0);
  goto llvm_cbe_tmp__1012;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1016:
  _Z4waitv();
  llvm_cbe_tmp__980 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field5))))&1);
  if ((((llvm_cbe_tmp__980 ^ 1)&1))) {
    goto llvm_cbe_tmp__1016;
  } else {
    goto llvm_cbe_tmp__1015;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1017:
  *(&llvm_cbe_tmp__920) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field4)), (&llvm_cbe_tmp__920));
  goto llvm_cbe_tmp__1016;

llvm_cbe_tmp__1018:
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__922->field2)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__976 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__919) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__976))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__922->field3)), (&llvm_cbe_tmp__919));
  llvm_cbe_tmp__977 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__978 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__977)) == llvm_cbe_tmp__978)) {
    goto llvm_cbe_tmp__1019;
  } else {
    goto llvm_cbe_tmp__1017;
  }

llvm_cbe_tmp__1020:
  llvm_cbe_tmp__969 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__970 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__969) * ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__970))))));
  llvm_cbe_tmp__971 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__972 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__971)) == llvm_cbe_tmp__972)) {
    goto llvm_cbe_tmp__1021;
  } else {
    goto llvm_cbe_tmp__1018;
  }

llvm_cbe_tmp__1022:
  llvm_cbe_tmp__965 = *(&llvm_cbe_index);
  llvm_cbe_tmp__966 = *(&llvm_cbe_ntu);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__965)) == llvm_cbe_tmp__966)) {
    goto llvm_cbe_tmp__1023;
  } else {
    goto llvm_cbe_tmp__1020;
  }

llvm_cbe_tmp__1024:
  llvm_cbe_tmp__959 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__959))) + ((unsigned int )1u))))));
  llvm_cbe_tmp__960 = *(&llvm_cbe_index);
  llvm_cbe_tmp__961 = *(&llvm_cbe_nu);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__960)) == llvm_cbe_tmp__961)) {
    goto llvm_cbe_tmp__1025;
  } else {
    goto llvm_cbe_tmp__1022;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1026:
  _Z4waitv();
  llvm_cbe_tmp__956 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field39))))&1);
  if (llvm_cbe_tmp__956) {
    goto llvm_cbe_tmp__1026;
  } else {
    goto llvm_cbe_tmp__1024;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1027:
  *(&llvm_cbe_tmp__916) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field37)), (&llvm_cbe_tmp__916));
  goto llvm_cbe_tmp__1026;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1028:
  _Z4waitv();
  llvm_cbe_tmp__955 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field39))))&1);
  if ((((llvm_cbe_tmp__955 ^ 1)&1))) {
    goto llvm_cbe_tmp__1028;
  } else {
    goto llvm_cbe_tmp__1027;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1009:
  *(&llvm_cbe_tmp__915) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field37)), (&llvm_cbe_tmp__915));
  goto llvm_cbe_tmp__1028;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1029:
  _Z4waitv();
  llvm_cbe_tmp__958 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field42))))&1);
  if (llvm_cbe_tmp__958) {
    goto llvm_cbe_tmp__1029;
  } else {
    goto llvm_cbe_tmp__1024;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1030:
  *(&llvm_cbe_tmp__918) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field38)), (&llvm_cbe_tmp__918));
  goto llvm_cbe_tmp__1029;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1031:
  _Z4waitv();
  llvm_cbe_tmp__957 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field42))))&1);
  if ((((llvm_cbe_tmp__957 ^ 1)&1))) {
    goto llvm_cbe_tmp__1031;
  } else {
    goto llvm_cbe_tmp__1030;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1010:
  *(&llvm_cbe_tmp__917) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__922->field38)), (&llvm_cbe_tmp__917));
  goto llvm_cbe_tmp__1031;

llvm_cbe_tmp__1025:
  llvm_cbe_tmp__962 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__963 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__962)) != llvm_cbe_tmp__963)) {
    goto llvm_cbe_tmp__1032;
  } else {
    goto llvm_cbe_tmp__1022;
  }

llvm_cbe_tmp__1032:
  llvm_cbe_tmp__964 = *(&llvm_cbe_loop_count);
  *(&llvm_cbe_loop_count) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__964))) + ((unsigned int )1u))))));
  *(&llvm_cbe_index) = ((unsigned short )0);
  goto llvm_cbe_tmp__1022;

llvm_cbe_tmp__1023:
  llvm_cbe_tmp__967 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__968 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__967)) == llvm_cbe_tmp__968)) {
    goto llvm_cbe_tmp__1033;
  } else {
    goto llvm_cbe_tmp__1020;
  }

llvm_cbe_tmp__1021:
  llvm_cbe_tmp__973 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__974 = *(&llvm_cbe_nu);
  llvm_cbe_tmp__975 = *(&llvm_cbe_dma_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__975) + ((unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__973) * ((unsigned int )llvm_cbe_tmp__974))))))));
  goto llvm_cbe_tmp__1018;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1019:
  _Z4waitv();
  llvm_cbe_tmp__979 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__922->field40))))&1);
  if ((((llvm_cbe_tmp__979 ^ 1)&1))) {
    goto llvm_cbe_tmp__1019;
  } else {
    goto llvm_cbe_tmp__1017;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1033:
  _Z4waitv();
  goto llvm_cbe_tmp__1033;

  } while (1); /* end of syntactic loop '' */
}


bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1034;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1035;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1036;
  unsigned char *llvm_cbe_tmp__1037;
  unsigned char llvm_cbe_tmp__1038;
  unsigned char llvm_cbe_tmp__1039;

  *(&llvm_cbe_tmp__1034) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1035) = llvm_cbe_d;
  llvm_cbe_tmp__1036 = *(&llvm_cbe_tmp__1034);
  llvm_cbe_tmp__1037 = *(&llvm_cbe_tmp__1035);
  llvm_cbe_tmp__1038 = *llvm_cbe_tmp__1037;
  *((&llvm_cbe_tmp__1036->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__1038&1u))&1))));
  llvm_cbe_tmp__1039 = *((&llvm_cbe_tmp__1036->field0));
  return (((((bool )llvm_cbe_tmp__1039&1u))&1));
}


void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1040;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__1041;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1042;
  unsigned int *llvm_cbe_tmp__1043;
  unsigned int llvm_cbe_tmp__1044;

  *(&llvm_cbe_tmp__1040) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1041) = llvm_cbe_d;
  llvm_cbe_tmp__1042 = *(&llvm_cbe_tmp__1040);
  llvm_cbe_tmp__1043 = *(&llvm_cbe_tmp__1041);
  llvm_cbe_tmp__1044 = *llvm_cbe_tmp__1043;
  *((&llvm_cbe_tmp__1042->field0)) = llvm_cbe_tmp__1044;
  return;
}


unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__1045;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__1046;
  unsigned short llvm_cbe_tmp__1047;

  *(&llvm_cbe_tmp__1045) = llvm_cbe_this;
  llvm_cbe_tmp__1046 = *(&llvm_cbe_tmp__1045);
  llvm_cbe_tmp__1047 = *((&llvm_cbe_tmp__1046->field0));
  return llvm_cbe_tmp__1047;
}


unsigned char *_ZN11SysCArray2DIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__1048;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1049;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1050;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1051;
  unsigned int llvm_cbe_tmp__1052;
  unsigned char *llvm_cbe_tmp__1053;
  unsigned int llvm_cbe_tmp__1054;
  unsigned char *llvm_cbe_tmp__1055;
  unsigned char *llvm_cbe_tmp__1056;

  *(&llvm_cbe_tmp__1049) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1050) = llvm_cbe_Xidx;
  llvm_cbe_tmp__1051 = *(&llvm_cbe_tmp__1049);
  llvm_cbe_tmp__1052 = *(&llvm_cbe_tmp__1050);
  if ((llvm_cbe_tmp__1052 == 0u)) {
    goto llvm_cbe_tmp__1057;
  } else {
    goto llvm_cbe_tmp__1058;
  }

llvm_cbe_tmp__1057:
  llvm_cbe_tmp__1053 = *((&llvm_cbe_tmp__1051->field1));
  *(&llvm_cbe_tmp__1048) = llvm_cbe_tmp__1053;
  goto llvm_cbe_tmp__1059;

llvm_cbe_tmp__1058:
  llvm_cbe_tmp__1054 = *(&llvm_cbe_tmp__1050);
  llvm_cbe_tmp__1055 = *((&llvm_cbe_tmp__1051->field0));
  *(&llvm_cbe_tmp__1048) = ((&llvm_cbe_tmp__1055[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__1054) * ((unsigned int )512u)))))))]));
  goto llvm_cbe_tmp__1059;

llvm_cbe_tmp__1059:
  llvm_cbe_tmp__1056 = *(&llvm_cbe_tmp__1048);
  return llvm_cbe_tmp__1056;
}


void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__1060;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1061;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1062;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1063;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1064;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1065;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1066;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1067;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1068;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1069;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1070;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1071;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1072;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1073;    /* Address-exposed local */
  unsigned short llvm_cbe_ntu;    /* Address-exposed local */
  unsigned short llvm_cbe_nm;    /* Address-exposed local */
  unsigned int llvm_cbe_index;    /* Address-exposed local */
  unsigned char llvm_cbe_rating;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1074;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1075;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1076;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1077;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1078;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1079;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1080;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1081;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1082;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1083;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1084;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1085;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1086;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1087;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__1088;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1089;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1090;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1091;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1092;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1093;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1094;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1095;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1096;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1097;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__1098;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__1099;
  bool llvm_cbe_tmp__1100;
  bool llvm_cbe_tmp__1101;
  unsigned long long llvm_cbe_tmp__1102;
  unsigned long long llvm_cbe_tmp__1103;
  unsigned long long llvm_cbe_tmp__1104;
  unsigned long long llvm_cbe_tmp__1105;
  unsigned long long llvm_cbe_tmp__1106;
  unsigned long long llvm_cbe_tmp__1107;
  unsigned short llvm_cbe_tmp__1108;
  unsigned short llvm_cbe_tmp__1109;
  bool llvm_cbe_tmp__1110;
  bool llvm_cbe_tmp__1111;
  unsigned short llvm_cbe_tmp__1112;
  unsigned int llvm_cbe_tmp__1113;
  unsigned short llvm_cbe_tmp__1114;
  unsigned int llvm_cbe_tmp__1115;
  bool llvm_cbe_tmp__1116;
  unsigned char llvm_cbe_tmp__1117;
  unsigned int llvm_cbe_tmp__1118;
  unsigned int llvm_cbe_tmp__1119;
  unsigned int llvm_cbe_tmp__1120;
  unsigned int llvm_cbe_tmp__1121;
  unsigned int llvm_cbe_tmp__1122;
  unsigned int llvm_cbe_tmp__1123;
  unsigned char llvm_cbe_tmp__1124;
  unsigned long long llvm_cbe_tmp__1125;
  unsigned long long llvm_cbe_tmp__1126;
  unsigned long long llvm_cbe_tmp__1127;
  unsigned long long llvm_cbe_tmp__1128;
  unsigned long long llvm_cbe_tmp__1129;
  unsigned long long llvm_cbe_tmp__1130;
  unsigned long long llvm_cbe_tmp__1131;
  unsigned long long llvm_cbe_tmp__1132;
  unsigned long long llvm_cbe_tmp__1133;
  unsigned long long llvm_cbe_tmp__1134;
  unsigned long long llvm_cbe_tmp__1135;
  unsigned char llvm_cbe_tmp__1136;
  unsigned int llvm_cbe_tmp__1137;
  unsigned char llvm_cbe_tmp__1138;
  unsigned long long llvm_cbe_tmp__1139;
  unsigned long long llvm_cbe_tmp__1140;
  unsigned long long llvm_cbe_tmp__1141;
  unsigned long long llvm_cbe_tmp__1142;
  unsigned char *llvm_cbe_tmp__1143;
  unsigned char *llvm_cbe_tmp__1144;
  unsigned char *llvm_cbe_tmp__1145;
  unsigned char *llvm_cbe_tmp__1146;
  bool llvm_cbe_tmp__1147;
  unsigned short llvm_cbe_tmp__1148;
  unsigned short llvm_cbe_tmp__1149;
  unsigned short llvm_cbe_tmp__1150;
  unsigned short llvm_cbe_tmp__1151;
  unsigned char *llvm_cbe_tmp__1152;
  unsigned char llvm_cbe_tmp__1153;
  unsigned char llvm_cbe_tmp__1154;
  unsigned char llvm_cbe_tmp__1155;
  unsigned int llvm_cbe_tmp__1156;
  unsigned int llvm_cbe_tmp__1157;
  unsigned int llvm_cbe_tmp__1158;
  unsigned int llvm_cbe_tmp__1159;
  unsigned int llvm_cbe_tmp__1160;
  unsigned int llvm_cbe_tmp__1161;
  unsigned char llvm_cbe_tmp__1162;
  unsigned char llvm_cbe_tmp__1163;
  unsigned int llvm_cbe_tmp__1164;
  unsigned char llvm_cbe_tmp__1165;
  bool llvm_cbe_tmp__1166;
  unsigned long long llvm_cbe_tmp__1167;
  bool llvm_cbe_tmp__1168;
  unsigned long long llvm_cbe_tmp__1169;
  unsigned short llvm_cbe_tmp__1170;
  unsigned long long llvm_cbe_tmp__1171;
  unsigned short llvm_cbe_tmp__1172;
  unsigned long long llvm_cbe_tmp__1173;
  unsigned short llvm_cbe_tmp__1174;
  unsigned long long llvm_cbe_tmp__1175;
  unsigned short llvm_cbe_tmp__1176;
  unsigned long long llvm_cbe_tmp__1177;
  unsigned short llvm_cbe_tmp__1178;
  unsigned long long llvm_cbe_tmp__1179;
  unsigned short llvm_cbe_tmp__1180;
  unsigned long long llvm_cbe_tmp__1181;
  unsigned int llvm_cbe_tmp__1182;
  unsigned long long llvm_cbe_tmp__1183;
  unsigned int llvm_cbe_tmp__1184;
  unsigned long long llvm_cbe_tmp__1185;
  bool llvm_cbe_tmp__1186;
  unsigned long long llvm_cbe_tmp__1187;
  unsigned int llvm_cbe_tmp__1188;
  unsigned long long llvm_cbe_tmp__1189;
  unsigned int llvm_cbe_tmp__1190;
  unsigned long long llvm_cbe_tmp__1191;
  unsigned int llvm_cbe_tmp__1192;
  unsigned long long llvm_cbe_tmp__1193;
  unsigned char *llvm_cbe_tmp__1194;
  unsigned char *llvm_cbe_tmp__1195;
  bool llvm_cbe_tmp__1196;
  unsigned char *llvm_cbe_tmp__1197;
  unsigned char *llvm_cbe_tmp__1198;
  bool llvm_cbe_tmp__1199;
  unsigned int llvm_cbe_tmp__1200;
  unsigned short llvm_cbe_tmp__1201;

  *(&llvm_cbe_tmp__1060) = llvm_cbe_this;
  llvm_cbe_tmp__1099 = *(&llvm_cbe_tmp__1060);
  *(&llvm_cbe_tmp__1061) = ((unsigned char )1);
  llvm_cbe_tmp__1100 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__1099->field36)), (&llvm_cbe_tmp__1061)))&1);
  *(&llvm_cbe_tmp__1062) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field8)), (&llvm_cbe_tmp__1062));
  *(&llvm_cbe_tmp__1063) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field7)), (&llvm_cbe_tmp__1063));
  *(&llvm_cbe_tmp__1064) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field9)), (&llvm_cbe_tmp__1064));
  *(&llvm_cbe_tmp__1065) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field44)), (&llvm_cbe_tmp__1065));
  *(&llvm_cbe_tmp__1066) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field45)), (&llvm_cbe_tmp__1066));
  *(&llvm_cbe_tmp__1067) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field12)), (&llvm_cbe_tmp__1067));
  goto llvm_cbe_tmp__1202;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1202:
  _Z4waitv();
  llvm_cbe_tmp__1101 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__1099->field36))))&1);
  if ((((llvm_cbe_tmp__1101 ^ 1)&1))) {
    goto llvm_cbe_tmp__1202;
  } else {
    goto llvm_cbe_tmp__1203;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1203:
  llvm_cbe_tmp__1102 = *((&GM.field4));
  *(&llvm_cbe_tmp__1068) = (((unsigned short )llvm_cbe_tmp__1102));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field30)), (&llvm_cbe_tmp__1068));
  llvm_cbe_tmp__1103 = *((&GM.field9));
  *(&llvm_cbe_tmp__1069) = (((unsigned short )llvm_cbe_tmp__1103));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field31)), (&llvm_cbe_tmp__1069));
  llvm_cbe_tmp__1104 = *((&GM.field8));
  *(&llvm_cbe_tmp__1070) = (((unsigned short )llvm_cbe_tmp__1104));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field32)), (&llvm_cbe_tmp__1070));
  llvm_cbe_tmp__1105 = *((&GM.field5));
  *(&llvm_cbe_tmp__1071) = (((unsigned short )llvm_cbe_tmp__1105));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field33)), (&llvm_cbe_tmp__1071));
  llvm_cbe_tmp__1106 = *((&GM.field7));
  *(&llvm_cbe_tmp__1072) = (((unsigned short )llvm_cbe_tmp__1106));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field34)), (&llvm_cbe_tmp__1072));
  llvm_cbe_tmp__1107 = *((&GM.field6));
  *(&llvm_cbe_tmp__1073) = (((unsigned short )llvm_cbe_tmp__1107));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field35)), (&llvm_cbe_tmp__1073));
  llvm_cbe_tmp__1108 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field34)));
  *(&llvm_cbe_ntu) = llvm_cbe_tmp__1108;
  llvm_cbe_tmp__1109 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field35)));
  *(&llvm_cbe_nm) = llvm_cbe_tmp__1109;
  *(&llvm_cbe_index) = 0u;
  goto llvm_cbe_tmp__1204;

llvm_cbe_tmp__1205:
  *(&llvm_cbe_tmp__1074) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field12)), (&llvm_cbe_tmp__1074));
  goto llvm_cbe_tmp__1206;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1206:
  _Z4waitv();
  goto llvm_cbe_tmp__1206;

  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1204:
  *(&llvm_cbe_tmp__1080) = ((unsigned char )1);
  llvm_cbe_tmp__1116 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__1099->field9)), (&llvm_cbe_tmp__1080)))&1);
  *(&wr_grant_inp) = ((unsigned char )1);
  *((&GM.field20)) = 1ull;
  llvm_cbe_tmp__1117 = *(&conf_done_inp);
  *((&((&llvm_cbe_tmp__1099->field13))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__1117&1u))&1))));
  llvm_cbe_tmp__1118 = *(&conf_num_hidden_inp);
  *((&((&llvm_cbe_tmp__1099->field14))->field0)) = llvm_cbe_tmp__1118;
  llvm_cbe_tmp__1119 = *(&conf_num_visible_inp);
  *((&((&llvm_cbe_tmp__1099->field15))->field0)) = llvm_cbe_tmp__1119;
  llvm_cbe_tmp__1120 = *(&conf_num_users_inp);
  *((&((&llvm_cbe_tmp__1099->field16))->field0)) = llvm_cbe_tmp__1120;
  llvm_cbe_tmp__1121 = *(&conf_num_loops_inp);
  *((&((&llvm_cbe_tmp__1099->field17))->field0)) = llvm_cbe_tmp__1121;
  llvm_cbe_tmp__1122 = *(&conf_num_testusers_inp);
  *((&((&llvm_cbe_tmp__1099->field18))->field0)) = llvm_cbe_tmp__1122;
  llvm_cbe_tmp__1123 = *(&conf_num_movies_inp);
  *((&((&llvm_cbe_tmp__1099->field19))->field0)) = llvm_cbe_tmp__1123;
  llvm_cbe_tmp__1124 = *(&rst_inp);
  *((&((&llvm_cbe_tmp__1099->field1))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__1124&1u))&1))));
  llvm_cbe_tmp__1125 = *((&GM.field3));
  *(&llvm_cbe_tmp__1081) = (((unsigned char )(bool )(llvm_cbe_tmp__1125 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field36)), (&llvm_cbe_tmp__1081));
  llvm_cbe_tmp__1126 = *((&GM.field2));
  *(&llvm_cbe_tmp__1082) = (((unsigned char )(bool )(llvm_cbe_tmp__1126 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field12)), (&llvm_cbe_tmp__1082));
  llvm_cbe_tmp__1127 = *((&GM.field4));
  *(&llvm_cbe_tmp__1083) = (((unsigned short )llvm_cbe_tmp__1127));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field30)), (&llvm_cbe_tmp__1083));
  llvm_cbe_tmp__1128 = *((&GM.field9));
  *(&llvm_cbe_tmp__1084) = (((unsigned short )llvm_cbe_tmp__1128));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field31)), (&llvm_cbe_tmp__1084));
  llvm_cbe_tmp__1129 = *((&GM.field8));
  *(&llvm_cbe_tmp__1085) = (((unsigned short )llvm_cbe_tmp__1129));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field32)), (&llvm_cbe_tmp__1085));
  llvm_cbe_tmp__1130 = *((&GM.field5));
  *(&llvm_cbe_tmp__1086) = (((unsigned short )llvm_cbe_tmp__1130));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field33)), (&llvm_cbe_tmp__1086));
  llvm_cbe_tmp__1131 = *((&GM.field7));
  *(&llvm_cbe_tmp__1087) = (((unsigned short )llvm_cbe_tmp__1131));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field34)), (&llvm_cbe_tmp__1087));
  llvm_cbe_tmp__1132 = *((&GM.field6));
  *(&llvm_cbe_tmp__1088) = (((unsigned short )llvm_cbe_tmp__1132));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__1099->field35)), (&llvm_cbe_tmp__1088));
  llvm_cbe_tmp__1133 = *((&GM.field13));
  *(&llvm_cbe_tmp__1089) = (((unsigned int )llvm_cbe_tmp__1133));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field2)), (&llvm_cbe_tmp__1089));
  llvm_cbe_tmp__1134 = *((&GM.field14));
  *(&llvm_cbe_tmp__1090) = (((unsigned int )llvm_cbe_tmp__1134));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field3)), (&llvm_cbe_tmp__1090));
  llvm_cbe_tmp__1135 = *((&GM.field15));
  *(&llvm_cbe_tmp__1091) = (((unsigned char )(bool )(llvm_cbe_tmp__1135 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field4)), (&llvm_cbe_tmp__1091));
  llvm_cbe_tmp__1136 = *(&rd_grant_inp);
  *((&((&llvm_cbe_tmp__1099->field5))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__1136&1u))&1))));
  llvm_cbe_tmp__1137 = *(&data_in_inp);
  *((&((&llvm_cbe_tmp__1099->field6))->field0)) = llvm_cbe_tmp__1137;
  llvm_cbe_tmp__1138 = *(&wr_grant_inp);
  *((&((&llvm_cbe_tmp__1099->field10))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__1138&1u))&1))));
  llvm_cbe_tmp__1139 = *((&GM.field20));
  *(&llvm_cbe_tmp__1092) = (((unsigned char )(bool )(llvm_cbe_tmp__1139 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field9)), (&llvm_cbe_tmp__1092));
  llvm_cbe_tmp__1140 = *((&GM.field18));
  *(&llvm_cbe_tmp__1093) = (((unsigned int )llvm_cbe_tmp__1140));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field7)), (&llvm_cbe_tmp__1093));
  llvm_cbe_tmp__1141 = *((&GM.field19));
  *(&llvm_cbe_tmp__1094) = (((unsigned int )llvm_cbe_tmp__1141));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field8)), (&llvm_cbe_tmp__1094));
  llvm_cbe_tmp__1142 = *((&GM.field1));
  *(&llvm_cbe_tmp__1095) = (((unsigned int )llvm_cbe_tmp__1142));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field11)), (&llvm_cbe_tmp__1095));
  llvm_cbe_tmp__1143 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__1099->field20)), 0u);
  llvm_cbe_tmp__1144 = *((&GM.field0.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__1143, llvm_cbe_tmp__1144);
  llvm_cbe_tmp__1145 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__1099->field28)), 0u);
  llvm_cbe_tmp__1146 = *((&GM.field10.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__1145, llvm_cbe_tmp__1146);
  llvm_cbe_tmp__1147 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__1099->field10))))&1);
  if ((((llvm_cbe_tmp__1147 ^ 1)&1))) {
    goto llvm_cbe_tmp__1207;
  } else {
    goto llvm_cbe_tmp__1208;
  }

llvm_cbe_tmp__1207:
  _Z4waitv();
  goto llvm_cbe_tmp__1204;

llvm_cbe_tmp__1209:
  *(&llvm_cbe_tmp__1076) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field44)), (&llvm_cbe_tmp__1076));
  *(&llvm_cbe_tmp__1077) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field45)), (&llvm_cbe_tmp__1077));
  llvm_cbe_tmp__1112 = *(&llvm_cbe_nm);
  llvm_cbe_tmp__1113 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__1112))) * ((unsigned int )llvm_cbe_tmp__1113))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field7)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__1114 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field35)));
  *(&llvm_cbe_tmp__1078) = (((unsigned int )(unsigned short )llvm_cbe_tmp__1114));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field8)), (&llvm_cbe_tmp__1078));
  llvm_cbe_tmp__1115 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__1115) + ((unsigned int )1u))));
  *(&llvm_cbe_tmp__1079) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field9)), (&llvm_cbe_tmp__1079));
  goto llvm_cbe_tmp__1207;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1210:
  _Z4waitv();
  llvm_cbe_tmp__1111 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__1099->field43))))&1);
  if (llvm_cbe_tmp__1111) {
    goto llvm_cbe_tmp__1210;
  } else {
    goto llvm_cbe_tmp__1209;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1211:
  *(&llvm_cbe_tmp__1075) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field44)), (&llvm_cbe_tmp__1075));
  goto llvm_cbe_tmp__1210;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__1212:
  _Z4waitv();
  llvm_cbe_tmp__1110 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__1099->field43))))&1);
  if ((((llvm_cbe_tmp__1110 ^ 1)&1))) {
    goto llvm_cbe_tmp__1212;
  } else {
    goto llvm_cbe_tmp__1211;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1213:
  *(&llvm_cbe_tmp__1098) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field45)), (&llvm_cbe_tmp__1098));
  llvm_cbe_tmp__1200 = *(&llvm_cbe_index);
  llvm_cbe_tmp__1201 = *(&llvm_cbe_ntu);
  if ((llvm_cbe_tmp__1200 == (((unsigned int )(unsigned short )llvm_cbe_tmp__1201)))) {
    goto llvm_cbe_tmp__1205;
  } else {
    goto llvm_cbe_tmp__1212;
  }

llvm_cbe_tmp__1208:
  *(&llvm_cbe_tmp__1096) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__1099->field9)), (&llvm_cbe_tmp__1096));
  *(&llvm_cbe_i) = ((unsigned short )0);
  llvm_cbe_tmp__1148 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__1148))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__1214;
  } else {
    goto llvm_cbe_tmp__1213;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__1214:
  llvm_cbe_tmp__1149 = *(&llvm_cbe_i);
  llvm_cbe_tmp__1150 = *(&llvm_cbe_nm);
  llvm_cbe_tmp__1151 = *(&llvm_cbe_i);
  llvm_cbe_tmp__1152 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__1099->field28)), 0u);
  llvm_cbe_tmp__1153 = *((&llvm_cbe_tmp__1152[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__1151)))]));
  *(&llvm_cbe_rating) = llvm_cbe_tmp__1153;
  _Z4waitv();
  llvm_cbe_tmp__1154 = *(&llvm_cbe_rating);
  *(&llvm_cbe_tmp__1097) = (((unsigned int )(unsigned char )llvm_cbe_tmp__1154));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__1099->field11)), (&llvm_cbe_tmp__1097));
  llvm_cbe_tmp__1155 = *(&conf_done_inp);
  llvm_cbe_tmp__1156 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__1157 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__1158 = *(&conf_num_users_inp);
  llvm_cbe_tmp__1159 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__1160 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__1161 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__1162 = *(&rst_inp);
  llvm_cbe_tmp__1163 = *(&rd_grant_inp);
  llvm_cbe_tmp__1164 = *(&data_in_inp);
  llvm_cbe_tmp__1165 = *(&wr_grant_inp);
  _ZN9model_RBM6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__1155&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__1156)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__1157)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__1158)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__1159)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__1160)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__1161)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__1162&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__1163&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__1164)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__1165&1u))&1)))));
  llvm_cbe_tmp__1166 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__1099->field36))))&1);
  llvm_cbe_tmp__1167 = *((&GM.field3));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__1166)) == llvm_cbe_tmp__1167), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__1168 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__1099->field12))))&1);
  llvm_cbe_tmp__1169 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__1168)) == llvm_cbe_tmp__1169), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__1170 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field30)));
  llvm_cbe_tmp__1171 = *((&GM.field4));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__1170)) == llvm_cbe_tmp__1171), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__1172 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field31)));
  llvm_cbe_tmp__1173 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__1172)) == llvm_cbe_tmp__1173), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__1174 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field32)));
  llvm_cbe_tmp__1175 = *((&GM.field8));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__1174)) == llvm_cbe_tmp__1175), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__1176 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field33)));
  llvm_cbe_tmp__1177 = *((&GM.field5));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__1176)) == llvm_cbe_tmp__1177), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__1178 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field34)));
  llvm_cbe_tmp__1179 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__1178)) == llvm_cbe_tmp__1179), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__1180 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__1099->field35)));
  llvm_cbe_tmp__1181 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__1180)) == llvm_cbe_tmp__1181), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__1182 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__1099->field2)));
  llvm_cbe_tmp__1183 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__1182)) == llvm_cbe_tmp__1183), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__1184 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__1099->field3)));
  llvm_cbe_tmp__1185 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__1184)) == llvm_cbe_tmp__1185), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__1186 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__1099->field4))))&1);
  llvm_cbe_tmp__1187 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__1186)) == llvm_cbe_tmp__1187), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__1188 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__1099->field7)));
  llvm_cbe_tmp__1189 = *((&GM.field18));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__1188)) == llvm_cbe_tmp__1189), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__1190 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__1099->field8)));
  llvm_cbe_tmp__1191 = *((&GM.field19));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__1190)) == llvm_cbe_tmp__1191), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__1192 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__1099->field11)));
  llvm_cbe_tmp__1193 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__1192)) == llvm_cbe_tmp__1193), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__1194 = *((&GM.field0.field0));
  llvm_cbe_tmp__1195 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__1099->field20)), 0u);
  llvm_cbe_tmp__1196 = ((__CPROVER_array_equal(llvm_cbe_tmp__1194, llvm_cbe_tmp__1195))&1);
  __CPROVER_assert(llvm_cbe_tmp__1196, ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__1197 = *((&GM.field10.field0));
  llvm_cbe_tmp__1198 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__1099->field28)), 0u);
  llvm_cbe_tmp__1199 = ((__CPROVER_array_equal(llvm_cbe_tmp__1197, llvm_cbe_tmp__1198))&1);
  __CPROVER_assert(llvm_cbe_tmp__1199, ((&_OC_str16.array[((signed int )0u)])));
  return;
}


unsigned char *_ZN11SysCArray2DIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__1215;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1216;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1217;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1218;
  unsigned int llvm_cbe_tmp__1219;
  unsigned char *llvm_cbe_tmp__1220;
  unsigned int llvm_cbe_tmp__1221;
  unsigned char *llvm_cbe_tmp__1222;
  unsigned char *llvm_cbe_tmp__1223;

  *(&llvm_cbe_tmp__1216) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1217) = llvm_cbe_Xidx;
  llvm_cbe_tmp__1218 = *(&llvm_cbe_tmp__1216);
  llvm_cbe_tmp__1219 = *(&llvm_cbe_tmp__1217);
  if ((llvm_cbe_tmp__1219 == 0u)) {
    goto llvm_cbe_tmp__1224;
  } else {
    goto llvm_cbe_tmp__1225;
  }

llvm_cbe_tmp__1224:
  llvm_cbe_tmp__1220 = *((&llvm_cbe_tmp__1218->field1));
  *(&llvm_cbe_tmp__1215) = llvm_cbe_tmp__1220;
  goto llvm_cbe_tmp__1226;

llvm_cbe_tmp__1225:
  llvm_cbe_tmp__1221 = *(&llvm_cbe_tmp__1217);
  llvm_cbe_tmp__1222 = *((&llvm_cbe_tmp__1218->field0));
  *(&llvm_cbe_tmp__1215) = ((&llvm_cbe_tmp__1222[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__1221) * ((unsigned int )128u)))))))]));
  goto llvm_cbe_tmp__1226;

llvm_cbe_tmp__1226:
  llvm_cbe_tmp__1223 = *(&llvm_cbe_tmp__1215);
  return llvm_cbe_tmp__1223;
}


static void __cxx_global_var_init17(void) {
  _ZN3rbmC1Ev((&IMPL));
  return;
}


void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__1227;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__1228;

  *(&llvm_cbe_tmp__1227) = llvm_cbe_this;
  llvm_cbe_tmp__1228 = *(&llvm_cbe_tmp__1227);
  _ZN3rbmC2Ev(llvm_cbe_tmp__1228);
  return;
}


unsigned int main(void) {
  unsigned int llvm_cbe_tmp__1229;    /* Address-exposed local */
  _GLOBAL__I_a();  CODE_FOR_MAIN();
  *(&llvm_cbe_tmp__1229) = 0u;
  _ZN3rbm5storeEv((&IMPL));
  return 0u;
}


void _ZN8type_memIhLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1230;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1231;
  unsigned char *llvm_cbe_tmp__1232;

  *(&llvm_cbe_tmp__1230) = llvm_cbe_this;
  llvm_cbe_tmp__1231 = *(&llvm_cbe_tmp__1230);
  llvm_cbe_tmp__1232 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__1231->field0)) = llvm_cbe_tmp__1232;
  return;
}


void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1233;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1234;

  *(&llvm_cbe_tmp__1233) = llvm_cbe_this;
  llvm_cbe_tmp__1234 = *(&llvm_cbe_tmp__1233);
  return;
}


void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__1235;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__1236;
  unsigned char *llvm_cbe_tmp__1237;
  unsigned char llvm_cbe_tmp__1238;
  unsigned char *llvm_cbe_tmp__1239;
  unsigned char llvm_cbe_tmp__1240;
  unsigned char *llvm_cbe_tmp__1241;
  unsigned char llvm_cbe_tmp__1242;
  unsigned char *llvm_cbe_tmp__1243;
  unsigned char llvm_cbe_tmp__1244;
  unsigned char *llvm_cbe_tmp__1245;
  unsigned char llvm_cbe_tmp__1246;

  *(&llvm_cbe_tmp__1235) = llvm_cbe_this;
  llvm_cbe_tmp__1236 = *(&llvm_cbe_tmp__1235);
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__1236->field0)), ((&_OC_str18.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__1236->field1)), ((&_OC_str19.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field2)), ((&_OC_str20.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field3)), ((&_OC_str21.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__1236->field4)), ((&_OC_str22.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__1236->field5)), ((&_OC_str23.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field6)), ((&_OC_str24.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field7)), ((&_OC_str25.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field8)), ((&_OC_str26.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__1236->field9)), ((&_OC_str27.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__1236->field10)), ((&_OC_str28.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field11)), ((&_OC_str29.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__1236->field12)), ((&_OC_str30.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__1236->field13)), ((&_OC_str31.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field14)), ((&_OC_str32.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field15)), ((&_OC_str33.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field16)), ((&_OC_str34.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field17)), ((&_OC_str35.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field18)), ((&_OC_str36.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__1236->field19)), ((&_OC_str37.array[((signed int )0u)])));
  _ZN11SysCArray2DIhLj2ELj512EEC1Ev(((&llvm_cbe_tmp__1236->field20)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__1236->field21)));
  _ZN11SysCArray1DIbLj128EEC1Ev(((&llvm_cbe_tmp__1236->field22)));
  _ZN11SysCArray2DIfLj501ELj101EEC1Ev(((&llvm_cbe_tmp__1236->field23)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__1236->field24)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__1236->field25)));
  _ZN11SysCArray1DIfLj5EEC1Ev(((&llvm_cbe_tmp__1236->field26)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__1236->field27)));
  _ZN11SysCArray2DIhLj2ELj128EEC1Ev(((&llvm_cbe_tmp__1236->field28)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__1236->field30)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__1236->field31)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__1236->field32)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__1236->field33)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__1236->field34)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__1236->field35)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field36)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field37)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field38)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field39)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field40)));
  _ZN15sc_signal_int32C1Ev(((&llvm_cbe_tmp__1236->field41)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field42)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field43)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field44)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__1236->field45)));
  llvm_cbe_tmp__1237 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__1236->field1)));
  llvm_cbe_tmp__1238 = *llvm_cbe_tmp__1237;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__1238&1u))&1)))), 0);
  llvm_cbe_tmp__1239 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__1236->field1)));
  llvm_cbe_tmp__1240 = *llvm_cbe_tmp__1239;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__1240&1u))&1)))), 0);
  llvm_cbe_tmp__1241 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__1236->field1)));
  llvm_cbe_tmp__1242 = *llvm_cbe_tmp__1241;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__1242&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__1243 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__1236->field1)));
  llvm_cbe_tmp__1244 = *llvm_cbe_tmp__1243;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__1244&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__1245 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__1236->field1)));
  llvm_cbe_tmp__1246 = *llvm_cbe_tmp__1245;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__1246&1u))&1)))), 0);
  return;
}


void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1247;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1248;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1249;
  unsigned char *llvm_cbe_tmp__1250;

  *(&llvm_cbe_tmp__1247) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1248) = llvm_cbe_p;
  llvm_cbe_tmp__1249 = *(&llvm_cbe_tmp__1247);
  llvm_cbe_tmp__1250 = *(&llvm_cbe_tmp__1248);
  _ZN14sc_signal_boolC2EPKc(llvm_cbe_tmp__1249, llvm_cbe_tmp__1250);
  return;
}


void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1251;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1252;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1253;
  unsigned char *llvm_cbe_tmp__1254;

  *(&llvm_cbe_tmp__1251) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1252) = llvm_cbe_p;
  llvm_cbe_tmp__1253 = *(&llvm_cbe_tmp__1251);
  llvm_cbe_tmp__1254 = *(&llvm_cbe_tmp__1252);
  _ZN13sc_signal_u32C2EPKc(llvm_cbe_tmp__1253, llvm_cbe_tmp__1254);
  return;
}


void _ZN11SysCArray2DIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1255;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1256;

  *(&llvm_cbe_tmp__1255) = llvm_cbe_this;
  llvm_cbe_tmp__1256 = *(&llvm_cbe_tmp__1255);
  _ZN11SysCArray2DIhLj2ELj512EEC2Ev(llvm_cbe_tmp__1256);
  return;
}


void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1257;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1258;

  *(&llvm_cbe_tmp__1257) = llvm_cbe_this;
  llvm_cbe_tmp__1258 = *(&llvm_cbe_tmp__1257);
  _ZN11SysCArray1DIbLj512EEC2Ev(llvm_cbe_tmp__1258);
  return;
}


void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1259;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1260;

  *(&llvm_cbe_tmp__1259) = llvm_cbe_this;
  llvm_cbe_tmp__1260 = *(&llvm_cbe_tmp__1259);
  _ZN11SysCArray1DIbLj128EEC2Ev(llvm_cbe_tmp__1260);
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_unnamed3 *llvm_cbe_this) {
  struct l_unnamed3 *llvm_cbe_tmp__1261;    /* Address-exposed local */
  struct l_unnamed3 *llvm_cbe_tmp__1262;

  *(&llvm_cbe_tmp__1261) = llvm_cbe_this;
  llvm_cbe_tmp__1262 = *(&llvm_cbe_tmp__1261);
  _ZN11SysCArray2DIfLj501ELj101EEC2Ev(llvm_cbe_tmp__1262);
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1263;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1264;

  *(&llvm_cbe_tmp__1263) = llvm_cbe_this;
  llvm_cbe_tmp__1264 = *(&llvm_cbe_tmp__1263);
  _ZN11SysCArray2DIbLj501ELj101EEC2Ev(llvm_cbe_tmp__1264);
  return;
}


void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_unnamed4 *llvm_cbe_this) {
  struct l_unnamed4 *llvm_cbe_tmp__1265;    /* Address-exposed local */
  struct l_unnamed4 *llvm_cbe_tmp__1266;

  *(&llvm_cbe_tmp__1265) = llvm_cbe_this;
  llvm_cbe_tmp__1266 = *(&llvm_cbe_tmp__1265);
  _ZN11SysCArray1DIfLj5EEC2Ev(llvm_cbe_tmp__1266);
  return;
}


void _ZN11SysCArray2DIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1267;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1268;

  *(&llvm_cbe_tmp__1267) = llvm_cbe_this;
  llvm_cbe_tmp__1268 = *(&llvm_cbe_tmp__1267);
  _ZN11SysCArray2DIhLj2ELj128EEC2Ev(llvm_cbe_tmp__1268);
  return;
}


void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__1269;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__1270;

  *(&llvm_cbe_tmp__1269) = llvm_cbe_this;
  llvm_cbe_tmp__1270 = *(&llvm_cbe_tmp__1269);
  _ZN13sc_signal_u16C2Ev(llvm_cbe_tmp__1270);
  return;
}


void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1271;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1272;

  *(&llvm_cbe_tmp__1271) = llvm_cbe_this;
  llvm_cbe_tmp__1272 = *(&llvm_cbe_tmp__1271);
  _ZN14sc_signal_boolC2Ev(llvm_cbe_tmp__1272);
  return;
}


void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1273;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1274;

  *(&llvm_cbe_tmp__1273) = llvm_cbe_this;
  llvm_cbe_tmp__1274 = *(&llvm_cbe_tmp__1273);
  _ZN15sc_signal_int32C2Ev(llvm_cbe_tmp__1274);
  return;
}


unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1275;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1276;

  *(&llvm_cbe_tmp__1275) = llvm_cbe_this;
  llvm_cbe_tmp__1276 = *(&llvm_cbe_tmp__1275);
  return ((&llvm_cbe_tmp__1276->field0));
}


void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1277;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1278;

  *(&llvm_cbe_tmp__1277) = llvm_cbe_this;
  llvm_cbe_tmp__1278 = *(&llvm_cbe_tmp__1277);
  return;
}


void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1279;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1280;

  *(&llvm_cbe_tmp__1279) = llvm_cbe_this;
  llvm_cbe_tmp__1280 = *(&llvm_cbe_tmp__1279);
  return;
}


void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__1281;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__1282;

  *(&llvm_cbe_tmp__1281) = llvm_cbe_this;
  llvm_cbe_tmp__1282 = *(&llvm_cbe_tmp__1281);
  return;
}


void _ZN11SysCArray2DIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1283;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1284;
  unsigned char *llvm_cbe_tmp__1285;
  unsigned char *llvm_cbe_tmp__1286;

  *(&llvm_cbe_tmp__1283) = llvm_cbe_this;
  llvm_cbe_tmp__1284 = *(&llvm_cbe_tmp__1283);
  llvm_cbe_tmp__1285 = __CPROVER_malloc(256ull);
  *((&llvm_cbe_tmp__1284->field0)) = llvm_cbe_tmp__1285;
  llvm_cbe_tmp__1286 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__1284->field1)) = llvm_cbe_tmp__1286;
  return;
}


void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_unnamed4 *llvm_cbe_this) {
  struct l_unnamed4 *llvm_cbe_tmp__1287;    /* Address-exposed local */
  struct l_unnamed4 *llvm_cbe_tmp__1288;
  unsigned char *llvm_cbe_tmp__1289;

  *(&llvm_cbe_tmp__1287) = llvm_cbe_this;
  llvm_cbe_tmp__1288 = *(&llvm_cbe_tmp__1287);
  llvm_cbe_tmp__1289 = __CPROVER_malloc(20ull);
  *((&llvm_cbe_tmp__1288->field0)) = (((float *)llvm_cbe_tmp__1289));
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1290;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1291;
  unsigned char *llvm_cbe_tmp__1292;
  unsigned char *llvm_cbe_tmp__1293;

  *(&llvm_cbe_tmp__1290) = llvm_cbe_this;
  llvm_cbe_tmp__1291 = *(&llvm_cbe_tmp__1290);
  llvm_cbe_tmp__1292 = __CPROVER_malloc(50601ull);
  *((&llvm_cbe_tmp__1291->field0)) = llvm_cbe_tmp__1292;
  llvm_cbe_tmp__1293 = __CPROVER_malloc(101ull);
  *((&llvm_cbe_tmp__1291->field1)) = llvm_cbe_tmp__1293;
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_unnamed3 *llvm_cbe_this) {
  struct l_unnamed3 *llvm_cbe_tmp__1294;    /* Address-exposed local */
  struct l_unnamed3 *llvm_cbe_tmp__1295;
  unsigned char *llvm_cbe_tmp__1296;
  unsigned char *llvm_cbe_tmp__1297;

  *(&llvm_cbe_tmp__1294) = llvm_cbe_this;
  llvm_cbe_tmp__1295 = *(&llvm_cbe_tmp__1294);
  llvm_cbe_tmp__1296 = __CPROVER_malloc(202404ull);
  *((&llvm_cbe_tmp__1295->field0)) = (((float *)llvm_cbe_tmp__1296));
  llvm_cbe_tmp__1297 = __CPROVER_malloc(404ull);
  *((&llvm_cbe_tmp__1295->field1)) = (((float *)llvm_cbe_tmp__1297));
  return;
}


void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1298;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1299;
  unsigned char *llvm_cbe_tmp__1300;

  *(&llvm_cbe_tmp__1298) = llvm_cbe_this;
  llvm_cbe_tmp__1299 = *(&llvm_cbe_tmp__1298);
  llvm_cbe_tmp__1300 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__1299->field0)) = llvm_cbe_tmp__1300;
  return;
}


void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1301;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1302;
  unsigned char *llvm_cbe_tmp__1303;

  *(&llvm_cbe_tmp__1301) = llvm_cbe_this;
  llvm_cbe_tmp__1302 = *(&llvm_cbe_tmp__1301);
  llvm_cbe_tmp__1303 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__1302->field0)) = llvm_cbe_tmp__1303;
  return;
}


void _ZN11SysCArray2DIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1304;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__1305;
  unsigned char *llvm_cbe_tmp__1306;
  unsigned char *llvm_cbe_tmp__1307;

  *(&llvm_cbe_tmp__1304) = llvm_cbe_this;
  llvm_cbe_tmp__1305 = *(&llvm_cbe_tmp__1304);
  llvm_cbe_tmp__1306 = __CPROVER_malloc(1024ull);
  *((&llvm_cbe_tmp__1305->field0)) = llvm_cbe_tmp__1306;
  llvm_cbe_tmp__1307 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__1305->field1)) = llvm_cbe_tmp__1307;
  return;
}


void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1308;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1309;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__1310;

  *(&llvm_cbe_tmp__1308) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1309) = llvm_cbe_p;
  llvm_cbe_tmp__1310 = *(&llvm_cbe_tmp__1308);
  return;
}


void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1311;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1312;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__1313;

  *(&llvm_cbe_tmp__1311) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1312) = llvm_cbe_p;
  llvm_cbe_tmp__1313 = *(&llvm_cbe_tmp__1311);
  return;
}


void _ZN9model_RBMD2Ev(struct l_class_OC_model_RBM *llvm_cbe_this) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__1314;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1315;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1316;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__1317;

  *(&llvm_cbe_tmp__1314) = llvm_cbe_this;
  llvm_cbe_tmp__1317 = *(&llvm_cbe_tmp__1314);
  _ZN8type_memIhLj128EED1Ev(((&llvm_cbe_tmp__1317->field10)));
  _ZN8type_memIhLj512EED1Ev(((&llvm_cbe_tmp__1317->field0)));
  return;
}


void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1318;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1319;

  *(&llvm_cbe_tmp__1318) = llvm_cbe_this;
  llvm_cbe_tmp__1319 = *(&llvm_cbe_tmp__1318);
  _ZN8type_memIhLj128EED2Ev(llvm_cbe_tmp__1319);
  return;
}


void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1320;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1321;

  *(&llvm_cbe_tmp__1320) = llvm_cbe_this;
  llvm_cbe_tmp__1321 = *(&llvm_cbe_tmp__1320);
  return;
}


void _ZN9model_RBMC2Ev(struct l_class_OC_model_RBM *llvm_cbe_this) {
  struct l_class_OC_model_RBM *llvm_cbe_tmp__1322;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__1323;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__1324;    /* Address-exposed local */
  struct l_class_OC_model_RBM *llvm_cbe_tmp__1325;

  *(&llvm_cbe_tmp__1322) = llvm_cbe_this;
  llvm_cbe_tmp__1325 = *(&llvm_cbe_tmp__1322);
  _ZN8type_memIhLj512EEC1El(((&llvm_cbe_tmp__1325->field0)), 0ull);
  _ZN8type_memIhLj128EEC1El(((&llvm_cbe_tmp__1325->field10)), 0ull);
  *((&llvm_cbe_tmp__1325->field21)) = 65535ull;
  *((&llvm_cbe_tmp__1325->field22)) = 255ull;
  return;
}


void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1326;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1327;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1328;
  unsigned long long llvm_cbe_tmp__1329;

  *(&llvm_cbe_tmp__1326) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1327) = llvm_cbe_def;
  llvm_cbe_tmp__1328 = *(&llvm_cbe_tmp__1326);
  llvm_cbe_tmp__1329 = *(&llvm_cbe_tmp__1327);
  _ZN8type_memIhLj512EEC2El(llvm_cbe_tmp__1328, llvm_cbe_tmp__1329);
  return;
}


void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1330;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1331;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1332;
  unsigned long long llvm_cbe_tmp__1333;

  *(&llvm_cbe_tmp__1330) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1331) = llvm_cbe_def;
  llvm_cbe_tmp__1332 = *(&llvm_cbe_tmp__1330);
  llvm_cbe_tmp__1333 = *(&llvm_cbe_tmp__1331);
  _ZN8type_memIhLj128EEC2El(llvm_cbe_tmp__1332, llvm_cbe_tmp__1333);
  return;
}


void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1334;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1335;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1336;
  unsigned char *llvm_cbe_tmp__1337;

  *(&llvm_cbe_tmp__1334) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1335) = llvm_cbe_def;
  llvm_cbe_tmp__1336 = *(&llvm_cbe_tmp__1334);
  llvm_cbe_tmp__1337 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__1336->field0)) = llvm_cbe_tmp__1337;
  return;
}


void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1338;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__1339;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__1340;
  unsigned char *llvm_cbe_tmp__1341;

  *(&llvm_cbe_tmp__1338) = llvm_cbe_this;
  *(&llvm_cbe_tmp__1339) = llvm_cbe_def;
  llvm_cbe_tmp__1340 = *(&llvm_cbe_tmp__1338);
  llvm_cbe_tmp__1341 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__1340->field0)) = llvm_cbe_tmp__1341;
  return;
}


static void _GLOBAL__I_a(void) {
  __cxx_global_var_init();
  __cxx_global_var_init17();
  return;
}

