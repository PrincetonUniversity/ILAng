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
struct l_class_OC_model_store;
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
typedef struct l_class_OC_model_store l_class_OC_model_store;
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

struct l_class_OC_model_store {
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
  unsigned long long field10;
  struct l_class_OC_SysCArray1D field11;
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
  unsigned long long field23;
  unsigned long long field24;
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

struct l_unnamed0 { unsigned char array[11]; };

struct l_unnamed1 { unsigned char array[15]; };

struct l_unnamed10 { unsigned char array[20]; };

struct l_unnamed11 { unsigned char array[5]; };

struct l_unnamed12 { unsigned char array[8]; };

struct l_unnamed13 { unsigned char array[21]; };

struct l_unnamed14 { unsigned char array[4]; };

struct l_unnamed15 { unsigned char array[9]; };

struct l_unnamed16 { unsigned char array[10]; };

struct l_unnamed17 { unsigned char array[19]; };

struct l_unnamed5 {
  unsigned int field0;
  void  (*field1) (void);
};

struct l_unnamed18 { struct l_unnamed5 array[1]; };

struct l_unnamed2 { unsigned char array[12]; };

struct l_unnamed7 { unsigned char array[16]; };

struct l_unnamed8 { unsigned char array[17]; };

struct l_unnamed9 { unsigned char array[18]; };


/* External Global Variable Declarations */
extern struct l_class_OC_model_store GM;
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
extern unsigned int wr_complete;
extern struct l_struct_OC_rbm IMPL;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
bool _ZN11model_store9assumps_0Elllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_store21cppUpdateFun_data_outElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN8type_memIhLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) __ATTRIBUTE_WEAK__;
unsigned long long _ZN11model_store14cppUpdateFun_iElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_store24cppUpdateFun_wr_completeElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_store23cppUpdateFun_wr_grantedElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN11model_store23cppUpdateFun_wr_requestElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN11model_store6updateElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
static void __cxx_global_var_init(void);
void _ZN11model_storeC1Ev(struct l_class_OC_model_store *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11model_storeD1Ev(struct l_class_OC_model_store *llvm_cbe_this) __ATTRIBUTE_WEAK__;
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
void __CPROVER_assume(bool );
unsigned int *_ZN13sc_signal_u32cvRjEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned short *_ZN13sc_signal_u16cvRtEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned char *_ZN11SysCArray2DIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void __CPROVER_assert(bool , unsigned char *);
bool __CPROVER_array_equal(unsigned char *, unsigned char *);
void __CPROVER_array_copy(unsigned char *, unsigned char *);
unsigned short _Z10nondet_intv(void);
static void __cxx_global_var_init21(void);
void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int main(void);
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
unsigned char *__CPROVER_malloc(unsigned long long );
void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_unnamed4 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_unnamed3 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11SysCArray2DIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) __ATTRIBUTE_WEAK__;
void _ZN11model_storeD2Ev(struct l_class_OC_model_store *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int __gxx_personality_v0(int vararg_dummy_arg,...);
void _Unwind_Resume_or_Rethrow(unsigned char *);
void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZSt9terminatev(void);
void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN11model_storeC2Ev(struct l_class_OC_model_store *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
static void _GLOBAL__I_a(void) __ATTRIBUTE_CTOR__;
void abort(void);


/* Global Variable Declarations */
extern struct l_class_OC_model_store GM;
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
extern unsigned int wr_complete;
static struct l_unnamed2 _OC_str;
static struct l_unnamed7 _OC_str1;
static struct l_unnamed0 _OC_str2;
static struct l_unnamed8 _OC_str3;
static struct l_unnamed9 _OC_str4;
static struct l_unnamed7 _OC_str5;
static struct l_unnamed7 _OC_str6;
static struct l_unnamed10 _OC_str7;
static struct l_unnamed8 _OC_str8;
static struct l_unnamed1 _OC_str9;
static struct l_unnamed7 _OC_str10;
static struct l_unnamed8 _OC_str11;
static struct l_unnamed8 _OC_str12;
static struct l_unnamed1 _OC_str13;
static struct l_unnamed7 _OC_str14;
static struct l_unnamed1 _OC_str15;
static struct l_unnamed9 _OC_str16;
static struct l_unnamed12 _OC_str17;
static struct l_unnamed0 _OC_str18;
static struct l_unnamed13 _OC_str19;
static struct l_unnamed12 _OC_str20;
extern struct l_struct_OC_rbm IMPL;
static struct l_unnamed14 _OC_str22;
static struct l_unnamed14 _OC_str23;
static struct l_unnamed15 _OC_str24;
static struct l_unnamed16 _OC_str25;
static struct l_unnamed0 _OC_str26;
static struct l_unnamed15 _OC_str27;
static struct l_unnamed12 _OC_str28;
static struct l_unnamed15 _OC_str29;
static struct l_unnamed16 _OC_str30;
static struct l_unnamed0 _OC_str31;
static struct l_unnamed15 _OC_str32;
static struct l_unnamed15 _OC_str33;
static struct l_unnamed11 _OC_str34;
static struct l_unnamed16 _OC_str35;
static struct l_unnamed7 _OC_str36;
static struct l_unnamed8 _OC_str37;
static struct l_unnamed1 _OC_str38;
static struct l_unnamed1 _OC_str39;
static struct l_unnamed17 _OC_str40;
static struct l_unnamed7 _OC_str41;


/* Global Variable Definitions and Initialization */
struct l_class_OC_model_store GM;
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
unsigned int wr_complete;
static struct l_unnamed2 _OC_str = { "Config done" };
static struct l_unnamed7 _OC_str1 = { "init_done_match" };
static struct l_unnamed0 _OC_str2 = { "done_match" };
static struct l_unnamed8 _OC_str3 = { "num_hidden_match" };
static struct l_unnamed9 _OC_str4 = { "num_visible_match" };
static struct l_unnamed7 _OC_str5 = { "num_users_match" };
static struct l_unnamed7 _OC_str6 = { "num_loops_match" };
static struct l_unnamed10 _OC_str7 = { "num_testusers_match" };
static struct l_unnamed8 _OC_str8 = { "num_movies_match" };
static struct l_unnamed1 _OC_str9 = { "rd_index_match" };
static struct l_unnamed7 _OC_str10 = { "rd_length_match" };
static struct l_unnamed8 _OC_str11 = { "rd_request_match" };
static struct l_unnamed8 _OC_str12 = { "wr_request_match" };
static struct l_unnamed1 _OC_str13 = { "wr_index_match" };
static struct l_unnamed7 _OC_str14 = { "wr_length_match" };
static struct l_unnamed1 _OC_str15 = { "data_out_match" };
static struct l_unnamed9 _OC_str16 = { "wr_complete_match" };
static struct l_unnamed12 _OC_str17 = { "i_match" };
static struct l_unnamed0 _OC_str18 = { "data_match" };
static struct l_unnamed13 _OC_str19 = { "predict_result_match" };
static struct l_unnamed12 _OC_str20 = { "ind-inv" };
struct l_struct_OC_rbm IMPL;
static struct l_unnamed14 _OC_str22 = { "clk" };
static struct l_unnamed14 _OC_str23 = { "rst" };
static struct l_unnamed15 _OC_str24 = { "rd_index" };
static struct l_unnamed16 _OC_str25 = { "rd_length" };
static struct l_unnamed0 _OC_str26 = { "rd_request" };
static struct l_unnamed15 _OC_str27 = { "rd_grant" };
static struct l_unnamed12 _OC_str28 = { "data_in" };
static struct l_unnamed15 _OC_str29 = { "wr_index" };
static struct l_unnamed16 _OC_str30 = { "wr_length" };
static struct l_unnamed0 _OC_str31 = { "wr_request" };
static struct l_unnamed15 _OC_str32 = { "wr_grant" };
static struct l_unnamed15 _OC_str33 = { "data_out" };
static struct l_unnamed11 _OC_str34 = { "done" };
static struct l_unnamed16 _OC_str35 = { "cond_done" };
static struct l_unnamed7 _OC_str36 = { "conf_num_hidden" };
static struct l_unnamed8 _OC_str37 = { "conf_num_visible" };
static struct l_unnamed1 _OC_str38 = { "conf_num_users" };
static struct l_unnamed1 _OC_str39 = { "conf_num_loops" };
static struct l_unnamed17 _OC_str40 = { "conf_num_testusers" };
static struct l_unnamed7 _OC_str41 = { "conf_num_movies" };


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

bool _ZN11model_store9assumps_0Elllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_store *llvm_cbe_tmp__1;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_cppVar_299;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_300;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__13;
  unsigned long long llvm_cbe_tmp__14;
  unsigned char llvm_cbe_tmp__15;

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
  llvm_cbe_tmp__13 = *(&llvm_cbe_tmp__1);
  llvm_cbe_tmp__14 = *((&llvm_cbe_tmp__13->field18));
  *(&llvm_cbe_cppVar_300) = (((unsigned char )(bool )(llvm_cbe_tmp__14 == 1ull)));
  llvm_cbe_tmp__15 = *(&llvm_cbe_cppVar_300);
  return (((((bool )llvm_cbe_tmp__15&1u))&1));
}


unsigned long long _ZN11model_store21cppUpdateFun_data_outElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_store *llvm_cbe_tmp__16;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__17;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__18;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__19;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__20;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__21;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__22;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__23;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__24;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__25;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__26;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__27;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_277;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_278;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_279;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__28;
  unsigned long long llvm_cbe_tmp__29;
  unsigned long long llvm_cbe_tmp__30;
  unsigned long long llvm_cbe_tmp__31;
  unsigned long long llvm_cbe_tmp__32;
  unsigned long long llvm_cbe_tmp__33;
  unsigned long long llvm_cbe_tmp__34;
  unsigned long long llvm_cbe_tmp__35;

  *(&llvm_cbe_tmp__16) = llvm_cbe_this;
  *(&llvm_cbe_tmp__17) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__18) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__19) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__20) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__21) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__22) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__23) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__24) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__25) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__26) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__27) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__28 = *(&llvm_cbe_tmp__16);
  llvm_cbe_tmp__29 = *((&llvm_cbe_tmp__28->field3));
  llvm_cbe_tmp__30 = *((&llvm_cbe_tmp__28->field23));
  *(&llvm_cbe_cppVar_277) = ((((signed long long )(((signed long long )llvm_cbe_tmp__29) >> ((signed long long )0ull)))) & llvm_cbe_tmp__30);
  llvm_cbe_tmp__31 = *(&llvm_cbe_cppVar_277);
  llvm_cbe_tmp__32 = _ZN8type_memIhLj128EE2rdEl(((&llvm_cbe_tmp__28->field11)), llvm_cbe_tmp__31);
  *(&llvm_cbe_cppVar_278) = llvm_cbe_tmp__32;
  llvm_cbe_tmp__33 = *(&llvm_cbe_cppVar_278);
  llvm_cbe_tmp__34 = *((&llvm_cbe_tmp__28->field24));
  *(&llvm_cbe_cppVar_279) = (llvm_cbe_tmp__33 & llvm_cbe_tmp__34);
  llvm_cbe_tmp__35 = *(&llvm_cbe_cppVar_279);
  return llvm_cbe_tmp__35;
}


unsigned long long _ZN8type_memIhLj128EE2rdEl(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__36;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__37;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__38;
  unsigned long long llvm_cbe_tmp__39;
  unsigned char *llvm_cbe_tmp__40;
  unsigned char llvm_cbe_tmp__41;

  *(&llvm_cbe_tmp__36) = llvm_cbe_this;
  *(&llvm_cbe_tmp__37) = llvm_cbe_addr;
  llvm_cbe_tmp__38 = *(&llvm_cbe_tmp__36);
  llvm_cbe_tmp__39 = *(&llvm_cbe_tmp__37);
  llvm_cbe_tmp__40 = *((&llvm_cbe_tmp__38->field0));
  llvm_cbe_tmp__41 = *((&llvm_cbe_tmp__40[((signed long long )llvm_cbe_tmp__39)]));
  return (((unsigned long long )(unsigned char )llvm_cbe_tmp__41));
}


unsigned long long _ZN11model_store14cppUpdateFun_iElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_store *llvm_cbe_tmp__42;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__43;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__44;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__45;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__46;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__47;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__48;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__49;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__50;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__51;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__52;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__53;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_282;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_283;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_284;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_281;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__54;
  unsigned long long llvm_cbe_tmp__55;
  unsigned long long llvm_cbe_tmp__56;
  unsigned char llvm_cbe_tmp__57;
  unsigned long long llvm_cbe_tmp__58;
  unsigned long long llvm_cbe_tmp__59;
  unsigned long long llvm_cbe_tmp__60;
  unsigned long long llvm_cbe_tmp__61;
  unsigned long long llvm_cbe_tmp__62;

  *(&llvm_cbe_tmp__42) = llvm_cbe_this;
  *(&llvm_cbe_tmp__43) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__44) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__45) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__46) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__47) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__48) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__49) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__50) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__51) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__52) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__53) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__54 = *(&llvm_cbe_tmp__42);
  llvm_cbe_tmp__55 = *((&llvm_cbe_tmp__54->field3));
  llvm_cbe_tmp__56 = *((&llvm_cbe_tmp__54->field7));
  *(&llvm_cbe_cppVar_282) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__55) < ((signed long long )llvm_cbe_tmp__56))));
  llvm_cbe_tmp__57 = *(&llvm_cbe_cppVar_282);
  llvm_cbe_tmp__58 = *((&llvm_cbe_tmp__54->field3));
  if ((((((bool )llvm_cbe_tmp__57&1u))&1))) {
    goto llvm_cbe_tmp__63;
  } else {
    goto llvm_cbe_tmp__64;
  }

llvm_cbe_tmp__63:
  *(&llvm_cbe_cppVar_284) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__58) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__59 = *(&llvm_cbe_cppVar_284);
  llvm_cbe_tmp__60 = *((&llvm_cbe_tmp__54->field22));
  *(&llvm_cbe_cppVar_284) = (llvm_cbe_tmp__59 & llvm_cbe_tmp__60);
  llvm_cbe_tmp__61 = *(&llvm_cbe_cppVar_284);
  *(&llvm_cbe_cppVar_281) = llvm_cbe_tmp__61;
  goto llvm_cbe_tmp__65;

llvm_cbe_tmp__64:
  *(&llvm_cbe_cppVar_281) = llvm_cbe_tmp__58;
  goto llvm_cbe_tmp__65;

llvm_cbe_tmp__65:
  llvm_cbe_tmp__62 = *(&llvm_cbe_cppVar_281);
  return llvm_cbe_tmp__62;
}


unsigned long long _ZN11model_store24cppUpdateFun_wr_completeElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_store *llvm_cbe_tmp__66;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__67;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__68;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__69;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__70;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__71;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__72;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__73;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__74;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__75;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__76;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__77;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_287;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_286;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_288;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__78;
  unsigned long long llvm_cbe_tmp__79;
  unsigned long long llvm_cbe_tmp__80;
  unsigned char llvm_cbe_tmp__81;
  unsigned long long llvm_cbe_tmp__82;
  unsigned long long llvm_cbe_tmp__83;

  *(&llvm_cbe_tmp__66) = llvm_cbe_this;
  *(&llvm_cbe_tmp__67) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__68) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__69) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__70) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__71) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__72) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__73) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__74) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__75) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__76) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__77) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__78 = *(&llvm_cbe_tmp__66);
  llvm_cbe_tmp__79 = *((&llvm_cbe_tmp__78->field3));
  llvm_cbe_tmp__80 = *((&llvm_cbe_tmp__78->field7));
  *(&llvm_cbe_cppVar_287) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__79) < ((signed long long )llvm_cbe_tmp__80))));
  llvm_cbe_tmp__81 = *(&llvm_cbe_cppVar_287);
  if ((((((bool )llvm_cbe_tmp__81&1u))&1))) {
    goto llvm_cbe_tmp__84;
  } else {
    goto llvm_cbe_tmp__85;
  }

llvm_cbe_tmp__84:
  llvm_cbe_tmp__82 = *((&llvm_cbe_tmp__78->field17));
  *(&llvm_cbe_cppVar_286) = llvm_cbe_tmp__82;
  goto llvm_cbe_tmp__86;

llvm_cbe_tmp__85:
  *(&llvm_cbe_cppVar_286) = 1ull;
  goto llvm_cbe_tmp__86;

llvm_cbe_tmp__86:
  llvm_cbe_tmp__83 = *(&llvm_cbe_cppVar_286);
  return llvm_cbe_tmp__83;
}


unsigned long long _ZN11model_store23cppUpdateFun_wr_grantedElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_store *llvm_cbe_tmp__87;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__88;    /* Address-exposed local */
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
  unsigned char llvm_cbe_cppVar_291;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_290;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_292;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__99;
  unsigned long long llvm_cbe_tmp__100;
  unsigned long long llvm_cbe_tmp__101;
  unsigned char llvm_cbe_tmp__102;
  unsigned long long llvm_cbe_tmp__103;
  unsigned long long llvm_cbe_tmp__104;

  *(&llvm_cbe_tmp__87) = llvm_cbe_this;
  *(&llvm_cbe_tmp__88) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__89) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__90) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__91) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__92) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__93) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__94) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__95) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__96) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__97) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__98) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__99 = *(&llvm_cbe_tmp__87);
  llvm_cbe_tmp__100 = *((&llvm_cbe_tmp__99->field3));
  llvm_cbe_tmp__101 = *((&llvm_cbe_tmp__99->field7));
  *(&llvm_cbe_cppVar_291) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__100) < ((signed long long )llvm_cbe_tmp__101))));
  llvm_cbe_tmp__102 = *(&llvm_cbe_cppVar_291);
  if ((((((bool )llvm_cbe_tmp__102&1u))&1))) {
    goto llvm_cbe_tmp__105;
  } else {
    goto llvm_cbe_tmp__106;
  }

llvm_cbe_tmp__105:
  llvm_cbe_tmp__103 = *((&llvm_cbe_tmp__99->field18));
  *(&llvm_cbe_cppVar_290) = llvm_cbe_tmp__103;
  goto llvm_cbe_tmp__107;

llvm_cbe_tmp__106:
  *(&llvm_cbe_cppVar_290) = 0ull;
  goto llvm_cbe_tmp__107;

llvm_cbe_tmp__107:
  llvm_cbe_tmp__104 = *(&llvm_cbe_cppVar_290);
  return llvm_cbe_tmp__104;
}


unsigned long long _ZN11model_store23cppUpdateFun_wr_requestElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_store *llvm_cbe_tmp__108;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__109;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__110;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__111;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__112;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__113;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__114;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__115;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__116;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__117;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__118;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__119;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_295;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_296;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_294;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_297;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__120;
  unsigned long long llvm_cbe_tmp__121;
  unsigned char llvm_cbe_tmp__122;
  unsigned long long llvm_cbe_tmp__123;
  unsigned long long llvm_cbe_tmp__124;

  *(&llvm_cbe_tmp__108) = llvm_cbe_this;
  *(&llvm_cbe_tmp__109) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__110) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__111) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__112) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__113) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__114) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__115) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__116) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__117) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__118) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__119) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__120 = *(&llvm_cbe_tmp__108);
  llvm_cbe_tmp__121 = *((&llvm_cbe_tmp__120->field3));
  *(&llvm_cbe_cppVar_296) = (((unsigned char )(bool )(llvm_cbe_tmp__121 == 0ull)));
  llvm_cbe_tmp__122 = *(&llvm_cbe_cppVar_296);
  if ((((((bool )llvm_cbe_tmp__122&1u))&1))) {
    goto llvm_cbe_tmp__125;
  } else {
    goto llvm_cbe_tmp__126;
  }

llvm_cbe_tmp__125:
  *(&llvm_cbe_cppVar_294) = 0ull;
  goto llvm_cbe_tmp__127;

llvm_cbe_tmp__126:
  llvm_cbe_tmp__123 = *((&llvm_cbe_tmp__120->field21));
  *(&llvm_cbe_cppVar_294) = llvm_cbe_tmp__123;
  goto llvm_cbe_tmp__127;

llvm_cbe_tmp__127:
  llvm_cbe_tmp__124 = *(&llvm_cbe_cppVar_294);
  return llvm_cbe_tmp__124;
}


void _ZN11model_store6updateElllllllllll(struct l_class_OC_model_store *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_store *llvm_cbe_tmp__128;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__129;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__130;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__131;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__132;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__133;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__134;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__135;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__136;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__137;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__138;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__139;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_280;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_285;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_289;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_293;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_298;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__140;
  unsigned long long llvm_cbe_tmp__141;
  unsigned long long llvm_cbe_tmp__142;
  unsigned long long llvm_cbe_tmp__143;
  unsigned long long llvm_cbe_tmp__144;
  unsigned long long llvm_cbe_tmp__145;
  unsigned long long llvm_cbe_tmp__146;
  unsigned long long llvm_cbe_tmp__147;
  unsigned long long llvm_cbe_tmp__148;
  unsigned long long llvm_cbe_tmp__149;
  unsigned long long llvm_cbe_tmp__150;
  unsigned long long llvm_cbe_tmp__151;
  unsigned long long llvm_cbe_tmp__152;
  unsigned long long llvm_cbe_tmp__153;
  unsigned long long llvm_cbe_tmp__154;
  unsigned long long llvm_cbe_tmp__155;
  unsigned long long llvm_cbe_tmp__156;
  unsigned long long llvm_cbe_tmp__157;
  unsigned long long llvm_cbe_tmp__158;
  unsigned long long llvm_cbe_tmp__159;
  unsigned long long llvm_cbe_tmp__160;
  unsigned long long llvm_cbe_tmp__161;
  unsigned long long llvm_cbe_tmp__162;
  unsigned long long llvm_cbe_tmp__163;
  unsigned long long llvm_cbe_tmp__164;
  unsigned long long llvm_cbe_tmp__165;
  unsigned long long llvm_cbe_tmp__166;
  unsigned long long llvm_cbe_tmp__167;
  unsigned long long llvm_cbe_tmp__168;
  unsigned long long llvm_cbe_tmp__169;
  unsigned long long llvm_cbe_tmp__170;
  unsigned long long llvm_cbe_tmp__171;
  unsigned long long llvm_cbe_tmp__172;
  unsigned long long llvm_cbe_tmp__173;
  unsigned long long llvm_cbe_tmp__174;
  unsigned long long llvm_cbe_tmp__175;
  unsigned long long llvm_cbe_tmp__176;
  unsigned long long llvm_cbe_tmp__177;
  unsigned long long llvm_cbe_tmp__178;
  unsigned long long llvm_cbe_tmp__179;
  unsigned long long llvm_cbe_tmp__180;
  unsigned long long llvm_cbe_tmp__181;
  unsigned long long llvm_cbe_tmp__182;
  unsigned long long llvm_cbe_tmp__183;
  unsigned long long llvm_cbe_tmp__184;
  unsigned long long llvm_cbe_tmp__185;
  unsigned long long llvm_cbe_tmp__186;
  unsigned long long llvm_cbe_tmp__187;
  unsigned long long llvm_cbe_tmp__188;
  unsigned long long llvm_cbe_tmp__189;
  unsigned long long llvm_cbe_tmp__190;
  unsigned long long llvm_cbe_tmp__191;
  unsigned long long llvm_cbe_tmp__192;
  unsigned long long llvm_cbe_tmp__193;
  unsigned long long llvm_cbe_tmp__194;
  unsigned long long llvm_cbe_tmp__195;
  unsigned long long llvm_cbe_tmp__196;
  unsigned long long llvm_cbe_tmp__197;
  unsigned long long llvm_cbe_tmp__198;
  unsigned long long llvm_cbe_tmp__199;
  unsigned long long llvm_cbe_tmp__200;
  unsigned long long llvm_cbe_tmp__201;
  unsigned long long llvm_cbe_tmp__202;
  unsigned long long llvm_cbe_tmp__203;
  unsigned long long llvm_cbe_tmp__204;
  unsigned long long llvm_cbe_tmp__205;

  *(&llvm_cbe_tmp__128) = llvm_cbe_this;
  *(&llvm_cbe_tmp__129) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__130) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__131) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__132) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__133) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__134) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__135) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__136) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__137) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__138) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__139) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__140 = *(&llvm_cbe_tmp__128);
  llvm_cbe_tmp__141 = *(&llvm_cbe_tmp__129);
  llvm_cbe_tmp__142 = *(&llvm_cbe_tmp__130);
  llvm_cbe_tmp__143 = *(&llvm_cbe_tmp__131);
  llvm_cbe_tmp__144 = *(&llvm_cbe_tmp__132);
  llvm_cbe_tmp__145 = *(&llvm_cbe_tmp__133);
  llvm_cbe_tmp__146 = *(&llvm_cbe_tmp__134);
  llvm_cbe_tmp__147 = *(&llvm_cbe_tmp__135);
  llvm_cbe_tmp__148 = *(&llvm_cbe_tmp__136);
  llvm_cbe_tmp__149 = *(&llvm_cbe_tmp__137);
  llvm_cbe_tmp__150 = *(&llvm_cbe_tmp__138);
  llvm_cbe_tmp__151 = *(&llvm_cbe_tmp__139);
  llvm_cbe_tmp__152 = _ZN11model_store21cppUpdateFun_data_outElllllllllll(llvm_cbe_tmp__140, llvm_cbe_tmp__141, llvm_cbe_tmp__142, llvm_cbe_tmp__143, llvm_cbe_tmp__144, llvm_cbe_tmp__145, llvm_cbe_tmp__146, llvm_cbe_tmp__147, llvm_cbe_tmp__148, llvm_cbe_tmp__149, llvm_cbe_tmp__150, llvm_cbe_tmp__151);
  *(&llvm_cbe_cppVar_280) = llvm_cbe_tmp__152;
  llvm_cbe_tmp__153 = *(&llvm_cbe_tmp__129);
  llvm_cbe_tmp__154 = *(&llvm_cbe_tmp__130);
  llvm_cbe_tmp__155 = *(&llvm_cbe_tmp__131);
  llvm_cbe_tmp__156 = *(&llvm_cbe_tmp__132);
  llvm_cbe_tmp__157 = *(&llvm_cbe_tmp__133);
  llvm_cbe_tmp__158 = *(&llvm_cbe_tmp__134);
  llvm_cbe_tmp__159 = *(&llvm_cbe_tmp__135);
  llvm_cbe_tmp__160 = *(&llvm_cbe_tmp__136);
  llvm_cbe_tmp__161 = *(&llvm_cbe_tmp__137);
  llvm_cbe_tmp__162 = *(&llvm_cbe_tmp__138);
  llvm_cbe_tmp__163 = *(&llvm_cbe_tmp__139);
  llvm_cbe_tmp__164 = _ZN11model_store14cppUpdateFun_iElllllllllll(llvm_cbe_tmp__140, llvm_cbe_tmp__153, llvm_cbe_tmp__154, llvm_cbe_tmp__155, llvm_cbe_tmp__156, llvm_cbe_tmp__157, llvm_cbe_tmp__158, llvm_cbe_tmp__159, llvm_cbe_tmp__160, llvm_cbe_tmp__161, llvm_cbe_tmp__162, llvm_cbe_tmp__163);
  *(&llvm_cbe_cppVar_285) = llvm_cbe_tmp__164;
  llvm_cbe_tmp__165 = *(&llvm_cbe_tmp__129);
  llvm_cbe_tmp__166 = *(&llvm_cbe_tmp__130);
  llvm_cbe_tmp__167 = *(&llvm_cbe_tmp__131);
  llvm_cbe_tmp__168 = *(&llvm_cbe_tmp__132);
  llvm_cbe_tmp__169 = *(&llvm_cbe_tmp__133);
  llvm_cbe_tmp__170 = *(&llvm_cbe_tmp__134);
  llvm_cbe_tmp__171 = *(&llvm_cbe_tmp__135);
  llvm_cbe_tmp__172 = *(&llvm_cbe_tmp__136);
  llvm_cbe_tmp__173 = *(&llvm_cbe_tmp__137);
  llvm_cbe_tmp__174 = *(&llvm_cbe_tmp__138);
  llvm_cbe_tmp__175 = *(&llvm_cbe_tmp__139);
  llvm_cbe_tmp__176 = _ZN11model_store24cppUpdateFun_wr_completeElllllllllll(llvm_cbe_tmp__140, llvm_cbe_tmp__165, llvm_cbe_tmp__166, llvm_cbe_tmp__167, llvm_cbe_tmp__168, llvm_cbe_tmp__169, llvm_cbe_tmp__170, llvm_cbe_tmp__171, llvm_cbe_tmp__172, llvm_cbe_tmp__173, llvm_cbe_tmp__174, llvm_cbe_tmp__175);
  *(&llvm_cbe_cppVar_289) = llvm_cbe_tmp__176;
  llvm_cbe_tmp__177 = *(&llvm_cbe_tmp__129);
  llvm_cbe_tmp__178 = *(&llvm_cbe_tmp__130);
  llvm_cbe_tmp__179 = *(&llvm_cbe_tmp__131);
  llvm_cbe_tmp__180 = *(&llvm_cbe_tmp__132);
  llvm_cbe_tmp__181 = *(&llvm_cbe_tmp__133);
  llvm_cbe_tmp__182 = *(&llvm_cbe_tmp__134);
  llvm_cbe_tmp__183 = *(&llvm_cbe_tmp__135);
  llvm_cbe_tmp__184 = *(&llvm_cbe_tmp__136);
  llvm_cbe_tmp__185 = *(&llvm_cbe_tmp__137);
  llvm_cbe_tmp__186 = *(&llvm_cbe_tmp__138);
  llvm_cbe_tmp__187 = *(&llvm_cbe_tmp__139);
  llvm_cbe_tmp__188 = _ZN11model_store23cppUpdateFun_wr_grantedElllllllllll(llvm_cbe_tmp__140, llvm_cbe_tmp__177, llvm_cbe_tmp__178, llvm_cbe_tmp__179, llvm_cbe_tmp__180, llvm_cbe_tmp__181, llvm_cbe_tmp__182, llvm_cbe_tmp__183, llvm_cbe_tmp__184, llvm_cbe_tmp__185, llvm_cbe_tmp__186, llvm_cbe_tmp__187);
  *(&llvm_cbe_cppVar_293) = llvm_cbe_tmp__188;
  llvm_cbe_tmp__189 = *(&llvm_cbe_tmp__129);
  llvm_cbe_tmp__190 = *(&llvm_cbe_tmp__130);
  llvm_cbe_tmp__191 = *(&llvm_cbe_tmp__131);
  llvm_cbe_tmp__192 = *(&llvm_cbe_tmp__132);
  llvm_cbe_tmp__193 = *(&llvm_cbe_tmp__133);
  llvm_cbe_tmp__194 = *(&llvm_cbe_tmp__134);
  llvm_cbe_tmp__195 = *(&llvm_cbe_tmp__135);
  llvm_cbe_tmp__196 = *(&llvm_cbe_tmp__136);
  llvm_cbe_tmp__197 = *(&llvm_cbe_tmp__137);
  llvm_cbe_tmp__198 = *(&llvm_cbe_tmp__138);
  llvm_cbe_tmp__199 = *(&llvm_cbe_tmp__139);
  llvm_cbe_tmp__200 = _ZN11model_store23cppUpdateFun_wr_requestElllllllllll(llvm_cbe_tmp__140, llvm_cbe_tmp__189, llvm_cbe_tmp__190, llvm_cbe_tmp__191, llvm_cbe_tmp__192, llvm_cbe_tmp__193, llvm_cbe_tmp__194, llvm_cbe_tmp__195, llvm_cbe_tmp__196, llvm_cbe_tmp__197, llvm_cbe_tmp__198, llvm_cbe_tmp__199);
  *(&llvm_cbe_cppVar_298) = llvm_cbe_tmp__200;
  llvm_cbe_tmp__201 = *(&llvm_cbe_cppVar_280);
  *((&llvm_cbe_tmp__140->field1)) = llvm_cbe_tmp__201;
  llvm_cbe_tmp__202 = *(&llvm_cbe_cppVar_285);
  *((&llvm_cbe_tmp__140->field3)) = llvm_cbe_tmp__202;
  llvm_cbe_tmp__203 = *(&llvm_cbe_cppVar_289);
  *((&llvm_cbe_tmp__140->field17)) = llvm_cbe_tmp__203;
  llvm_cbe_tmp__204 = *(&llvm_cbe_cppVar_293);
  *((&llvm_cbe_tmp__140->field18)) = llvm_cbe_tmp__204;
  llvm_cbe_tmp__205 = *(&llvm_cbe_cppVar_298);
  *((&llvm_cbe_tmp__140->field21)) = llvm_cbe_tmp__205;
  return;
}


static void __cxx_global_var_init(void) {
  unsigned int llvm_cbe_tmp__206;

  _ZN11model_storeC1Ev((&GM));
  llvm_cbe_tmp__206 = __cxa_atexit(((void  (*) (unsigned char *))_ZN11model_storeD1Ev), ((unsigned char *)(&GM)), ((unsigned char *)(&__dso_handle)));
  return;
}


void _ZN11model_storeC1Ev(struct l_class_OC_model_store *llvm_cbe_this) {
  struct l_class_OC_model_store *llvm_cbe_tmp__207;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__208;

  *(&llvm_cbe_tmp__207) = llvm_cbe_this;
  llvm_cbe_tmp__208 = *(&llvm_cbe_tmp__207);
  _ZN11model_storeC2Ev(llvm_cbe_tmp__208);
  return;
}


void _ZN11model_storeD1Ev(struct l_class_OC_model_store *llvm_cbe_this) {
  struct l_class_OC_model_store *llvm_cbe_tmp__209;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__210;

  *(&llvm_cbe_tmp__209) = llvm_cbe_this;
  llvm_cbe_tmp__210 = *(&llvm_cbe_tmp__209);
  _ZN11model_storeD2Ev(llvm_cbe_tmp__210);
  return;
}


void _Z4waitv(void) {
  unsigned int llvm_cbe_tmp__211;

  llvm_cbe_tmp__211 = *(&cycleCnt);
  *(&cycleCnt) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__211) + ((unsigned int )1u))));
  return;
}


void _Z15reset_signal_isib(unsigned int llvm_cbe_tmp__212, bool llvm_cbe_tmp__213) {
  unsigned int llvm_cbe_tmp__214;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__215;    /* Address-exposed local */

  *(&llvm_cbe_tmp__214) = llvm_cbe_tmp__212;
  *(&llvm_cbe_tmp__215) = (((unsigned char )(bool )llvm_cbe_tmp__213));
  return;
}


void _Z14set_stack_sizei(unsigned int llvm_cbe_tmp__216) {
  unsigned int llvm_cbe_tmp__217;    /* Address-exposed local */

  *(&llvm_cbe_tmp__217) = llvm_cbe_tmp__216;
  return;
}


void _ZN3rbm6configEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__218;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__219;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__220;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__221;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__222;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__223;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__224;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__225;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__226;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__227;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__228;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__229;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__230;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__231;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__232;
  bool llvm_cbe_tmp__233;
  unsigned int llvm_cbe_tmp__234;
  unsigned int llvm_cbe_tmp__235;
  unsigned int llvm_cbe_tmp__236;
  unsigned int llvm_cbe_tmp__237;
  unsigned int llvm_cbe_tmp__238;
  unsigned int llvm_cbe_tmp__239;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__240;
  unsigned int llvm_cbe_tmp__241;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__242;

  *(&llvm_cbe_tmp__218) = llvm_cbe_this;
  llvm_cbe_tmp__232 = *(&llvm_cbe_tmp__218);
  *(&llvm_cbe_tmp__219) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field30)), (&llvm_cbe_tmp__219));
  *(&llvm_cbe_tmp__220) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field31)), (&llvm_cbe_tmp__220));
  *(&llvm_cbe_tmp__221) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field32)), (&llvm_cbe_tmp__221));
  *(&llvm_cbe_tmp__222) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field33)), (&llvm_cbe_tmp__222));
  *(&llvm_cbe_tmp__223) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field35)), (&llvm_cbe_tmp__223));
  *(&llvm_cbe_tmp__224) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__232->field36)), (&llvm_cbe_tmp__224));
  _Z4waitv();
  goto llvm_cbe_tmp__243;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__243:
  _Z4waitv();
  llvm_cbe_tmp__233 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__232->field13))))&1);
  if ((((llvm_cbe_tmp__233 ^ 1)&1))) {
    goto llvm_cbe_tmp__243;
  } else {
    goto llvm_cbe_tmp__244;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__244:
  llvm_cbe_tmp__234 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__232->field14)));
  *(&llvm_cbe_tmp__225) = (((unsigned short )llvm_cbe_tmp__234));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field30)), (&llvm_cbe_tmp__225));
  llvm_cbe_tmp__235 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__232->field15)));
  *(&llvm_cbe_tmp__226) = (((unsigned short )llvm_cbe_tmp__235));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field31)), (&llvm_cbe_tmp__226));
  llvm_cbe_tmp__236 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__232->field16)));
  *(&llvm_cbe_tmp__227) = (((unsigned short )llvm_cbe_tmp__236));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field32)), (&llvm_cbe_tmp__227));
  llvm_cbe_tmp__237 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__232->field17)));
  *(&llvm_cbe_tmp__228) = (((unsigned short )llvm_cbe_tmp__237));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field33)), (&llvm_cbe_tmp__228));
  llvm_cbe_tmp__238 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__232->field18)));
  *(&llvm_cbe_tmp__229) = (((unsigned short )llvm_cbe_tmp__238));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field34)), (&llvm_cbe_tmp__229));
  llvm_cbe_tmp__239 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__232->field19)));
  *(&llvm_cbe_tmp__230) = (((unsigned short )llvm_cbe_tmp__239));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__232->field35)), (&llvm_cbe_tmp__230));
  llvm_cbe_tmp__240 = _ZNSt6iocoutlsEPKc((&_ZSt4cout), ((&_OC_str.array[((signed int )0u)])));
  llvm_cbe_tmp__241 = *(&_ZSt4endl);
  llvm_cbe_tmp__242 = _ZNSt6iocoutlsEi(llvm_cbe_tmp__240, llvm_cbe_tmp__241);
  *(&llvm_cbe_tmp__231) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__232->field36)), (&llvm_cbe_tmp__231));
  goto llvm_cbe_tmp__245;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__245:
  _Z4waitv();
  goto llvm_cbe_tmp__245;

  } while (1); /* end of syntactic loop '' */
}


void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__246;    /* Address-exposed local */
  unsigned short *llvm_cbe_tmp__247;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__248;
  unsigned short *llvm_cbe_tmp__249;
  unsigned short llvm_cbe_tmp__250;

  *(&llvm_cbe_tmp__246) = llvm_cbe_this;
  *(&llvm_cbe_tmp__247) = llvm_cbe_d;
  llvm_cbe_tmp__248 = *(&llvm_cbe_tmp__246);
  llvm_cbe_tmp__249 = *(&llvm_cbe_tmp__247);
  llvm_cbe_tmp__250 = *llvm_cbe_tmp__249;
  *((&llvm_cbe_tmp__248->field0)) = llvm_cbe_tmp__250;
  return;
}


void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__251;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__252;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__253;
  unsigned char *llvm_cbe_tmp__254;
  unsigned char llvm_cbe_tmp__255;

  *(&llvm_cbe_tmp__251) = llvm_cbe_this;
  *(&llvm_cbe_tmp__252) = llvm_cbe_d;
  llvm_cbe_tmp__253 = *(&llvm_cbe_tmp__251);
  llvm_cbe_tmp__254 = *(&llvm_cbe_tmp__252);
  llvm_cbe_tmp__255 = *llvm_cbe_tmp__254;
  *((&llvm_cbe_tmp__253->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__255&1u))&1))));
  return;
}


bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__256;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__257;
  unsigned char llvm_cbe_tmp__258;

  *(&llvm_cbe_tmp__256) = llvm_cbe_this;
  llvm_cbe_tmp__257 = *(&llvm_cbe_tmp__256);
  llvm_cbe_tmp__258 = *((&llvm_cbe_tmp__257->field0));
  return (((((bool )llvm_cbe_tmp__258&1u))&1));
}


unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__259;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__260;
  unsigned int llvm_cbe_tmp__261;

  *(&llvm_cbe_tmp__259) = llvm_cbe_this;
  llvm_cbe_tmp__260 = *(&llvm_cbe_tmp__259);
  llvm_cbe_tmp__261 = *((&llvm_cbe_tmp__260->field0));
  return llvm_cbe_tmp__261;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_tmp__262) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__263;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__264;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__265;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__266;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__267;

  *(&llvm_cbe_tmp__264) = llvm_cbe_this;
  *(&llvm_cbe_tmp__265) = llvm_cbe_tmp__262;
  llvm_cbe_tmp__266 = *(&llvm_cbe_tmp__264);
  llvm_cbe_tmp__267 = *(&llvm_cbe_tmp__263);
  return llvm_cbe_tmp__267;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEi(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned int llvm_cbe_tmp__268) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__269;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__270;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__271;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__272;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__273;

  *(&llvm_cbe_tmp__270) = llvm_cbe_this;
  *(&llvm_cbe_tmp__271) = llvm_cbe_tmp__268;
  llvm_cbe_tmp__272 = *(&llvm_cbe_tmp__270);
  llvm_cbe_tmp__273 = *(&llvm_cbe_tmp__269);
  return llvm_cbe_tmp__273;
}


void _ZN3rbm4loadEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__274;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__275;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__276;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__277;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__278;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__279;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__280;    /* Address-exposed local */
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
  unsigned int llvm_cbe_tmp__281;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__282;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__283;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__284;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned char llvm_cbe_rate;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__285;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__286;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__287;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__288;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__289;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__290;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__291;    /* Address-exposed local */
  unsigned short llvm_cbe_i1;    /* Address-exposed local */
  unsigned char llvm_cbe_rate2;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__292;
  bool llvm_cbe_tmp__293;
  bool llvm_cbe_tmp__294;
  unsigned short llvm_cbe_tmp__295;
  unsigned short llvm_cbe_tmp__296;
  unsigned short llvm_cbe_tmp__297;
  unsigned short llvm_cbe_tmp__298;
  unsigned short llvm_cbe_tmp__299;
  unsigned short llvm_cbe_tmp__300;
  unsigned int llvm_cbe_tmp__301;
  unsigned short llvm_cbe_tmp__302;
  unsigned int llvm_cbe_tmp__303;
  bool llvm_cbe_tmp__304;
  bool llvm_cbe_tmp__305;
  unsigned short llvm_cbe_tmp__306;
  unsigned int llvm_cbe_tmp__307;
  unsigned short llvm_cbe_tmp__308;
  unsigned short llvm_cbe_tmp__309;
  unsigned short llvm_cbe_tmp__310;
  unsigned short llvm_cbe_tmp__311;
  unsigned short llvm_cbe_tmp__312;
  unsigned int llvm_cbe_tmp__313;
  unsigned int llvm_cbe_tmp__314;
  unsigned char llvm_cbe_tmp__315;
  unsigned short llvm_cbe_tmp__316;
  unsigned char llvm_cbe_tmp__317;
  unsigned char *llvm_cbe_tmp__318;
  unsigned short llvm_cbe_tmp__319;
  unsigned int llvm_cbe_tmp__320;
  unsigned char llvm_cbe_tmp__321;
  unsigned char *llvm_cbe_tmp__322;
  unsigned short llvm_cbe_tmp__323;
  unsigned int llvm_cbe_tmp__324;
  bool llvm_cbe_tmp__325;
  bool llvm_cbe_tmp__326;
  bool llvm_cbe_tmp__327;
  bool llvm_cbe_tmp__328;
  unsigned short llvm_cbe_tmp__329;
  unsigned short llvm_cbe_tmp__330;
  unsigned int llvm_cbe_tmp__331;
  unsigned short llvm_cbe_tmp__332;
  unsigned int llvm_cbe_tmp__333;
  unsigned short llvm_cbe_tmp__334;
  unsigned short llvm_cbe_tmp__335;
  unsigned int llvm_cbe_tmp__336;
  unsigned short llvm_cbe_tmp__337;
  unsigned int llvm_cbe_tmp__338;
  unsigned int llvm_cbe_tmp__339;
  unsigned short llvm_cbe_tmp__340;
  unsigned short llvm_cbe_tmp__341;
  unsigned int llvm_cbe_tmp__342;
  unsigned int llvm_cbe_tmp__343;
  unsigned int llvm_cbe_tmp__344;
  unsigned int llvm_cbe_tmp__345;
  unsigned int llvm_cbe_tmp__346;
  unsigned short llvm_cbe_tmp__347;
  unsigned int llvm_cbe_tmp__348;
  bool llvm_cbe_tmp__349;
  bool llvm_cbe_tmp__350;
  unsigned short llvm_cbe_tmp__351;
  unsigned int llvm_cbe_tmp__352;
  unsigned short llvm_cbe_tmp__353;
  unsigned short llvm_cbe_tmp__354;
  unsigned short llvm_cbe_tmp__355;
  unsigned short llvm_cbe_tmp__356;
  unsigned short llvm_cbe_tmp__357;
  unsigned int llvm_cbe_tmp__358;
  unsigned int llvm_cbe_tmp__359;
  unsigned char llvm_cbe_tmp__360;
  unsigned short llvm_cbe_tmp__361;
  unsigned char llvm_cbe_tmp__362;
  unsigned char *llvm_cbe_tmp__363;
  unsigned short llvm_cbe_tmp__364;
  unsigned int llvm_cbe_tmp__365;
  unsigned char llvm_cbe_tmp__366;
  unsigned char *llvm_cbe_tmp__367;

  *(&llvm_cbe_tmp__274) = llvm_cbe_this;
  llvm_cbe_tmp__292 = *(&llvm_cbe_tmp__274);
  *(&llvm_cbe_tmp__275) = ((unsigned char )1);
  llvm_cbe_tmp__293 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__292->field36)), (&llvm_cbe_tmp__275)))&1);
  *(&llvm_cbe_tmp__276) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__292->field2)), (&llvm_cbe_tmp__276));
  *(&llvm_cbe_tmp__277) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__292->field3)), (&llvm_cbe_tmp__277));
  *(&llvm_cbe_tmp__278) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field4)), (&llvm_cbe_tmp__278));
  *(&llvm_cbe_tmp__279) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field37)), (&llvm_cbe_tmp__279));
  *(&llvm_cbe_tmp__280) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field38)), (&llvm_cbe_tmp__280));
  goto llvm_cbe_tmp__368;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__368:
  _Z4waitv();
  llvm_cbe_tmp__294 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field36))))&1);
  if ((((llvm_cbe_tmp__294 ^ 1)&1))) {
    goto llvm_cbe_tmp__368;
  } else {
    goto llvm_cbe_tmp__369;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__369:
  llvm_cbe_tmp__295 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__292->field31)));
  *(&llvm_cbe_nv) = (((unsigned int )(unsigned short )llvm_cbe_tmp__295));
  llvm_cbe_tmp__296 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__292->field34)));
  *(&llvm_cbe_ntu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__296));
  llvm_cbe_tmp__297 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__292->field32)));
  *(&llvm_cbe_nu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__297));
  llvm_cbe_tmp__298 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__292->field33)));
  *(&llvm_cbe_nlp) = (((unsigned int )(unsigned short )llvm_cbe_tmp__298));
  llvm_cbe_tmp__299 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__292->field35)));
  *(&llvm_cbe_nm) = (((unsigned int )(unsigned short )llvm_cbe_tmp__299));
  *(&llvm_cbe_index) = ((unsigned short )0);
  *(&llvm_cbe_loop_count) = ((unsigned short )0);
  *(&llvm_cbe_pingpong) = ((unsigned char )0);
  llvm_cbe_tmp__300 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp__281) = (((unsigned int )(unsigned short )llvm_cbe_tmp__300));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__292->field2)), (&llvm_cbe_tmp__281));
  llvm_cbe_tmp__301 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__282) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__301))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__292->field3)), (&llvm_cbe_tmp__282));
  llvm_cbe_tmp__302 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__303 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__302)) == llvm_cbe_tmp__303)) {
    goto llvm_cbe_tmp__370;
  } else {
    goto llvm_cbe_tmp__371;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__370:
  _Z4waitv();
  llvm_cbe_tmp__304 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field40))))&1);
  if ((((llvm_cbe_tmp__304 ^ 1)&1))) {
    goto llvm_cbe_tmp__370;
  } else {
    goto llvm_cbe_tmp__371;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__371:
  *(&llvm_cbe_tmp__283) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field4)), (&llvm_cbe_tmp__283));
  goto llvm_cbe_tmp__372;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__372:
  _Z4waitv();
  llvm_cbe_tmp__305 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field5))))&1);
  if ((((llvm_cbe_tmp__305 ^ 1)&1))) {
    goto llvm_cbe_tmp__372;
  } else {
    goto llvm_cbe_tmp__373;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__373:
  *(&llvm_cbe_tmp__284) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field4)), (&llvm_cbe_tmp__284));
  llvm_cbe_tmp__306 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__307 = *(&llvm_cbe_nu);
  *(&llvm_cbe_tmp1) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__306))) * ((unsigned int )llvm_cbe_tmp__307))))));
  llvm_cbe_tmp__308 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__309 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp2) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__308))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__309))))))));
  llvm_cbe_tmp__310 = *(&llvm_cbe_tmp2);
  *(&llvm_cbe_pingpong) = (((unsigned char )(bool )((((signed int )(((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__310))) % ((signed int )2u)))) != 0u)));
  *(&llvm_cbe_i) = ((unsigned short )0);
  goto llvm_cbe_tmp__374;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__374:
  llvm_cbe_tmp__311 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__311))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__375;
  } else {
    goto llvm_cbe_tmp__376;
  }

llvm_cbe_tmp__377:
  llvm_cbe_tmp__314 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__292->field6)));
  *(&llvm_cbe_rate) = (((unsigned char )llvm_cbe_tmp__314));
  _Z4waitv();
  llvm_cbe_tmp__315 = *(&llvm_cbe_rate);
  llvm_cbe_tmp__316 = *(&llvm_cbe_i);
  llvm_cbe_tmp__317 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__318 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__292->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__317&1u))&1)))));
  *((&llvm_cbe_tmp__318[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__316)))])) = llvm_cbe_tmp__315;
  llvm_cbe_tmp__319 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__319) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__374;

llvm_cbe_tmp__375:
  llvm_cbe_tmp__312 = *(&llvm_cbe_i);
  llvm_cbe_tmp__313 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__312)) == llvm_cbe_tmp__313)) {
    goto llvm_cbe_tmp__376;
  } else {
    goto llvm_cbe_tmp__377;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__376:
  _Z4waitv();
  llvm_cbe_tmp__320 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__321 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__322 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__292->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__321&1u))&1)))));
  *((&llvm_cbe_tmp__322[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__320)))])) = ((unsigned char )1);
  goto llvm_cbe_tmp__378;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__378:
  llvm_cbe_tmp__323 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__324 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__323)) != llvm_cbe_tmp__324)) {
    goto llvm_cbe_tmp__379;
  } else {
    goto llvm_cbe_tmp__380;
  }

llvm_cbe_tmp__381:
  _Z4waitv();
  llvm_cbe_tmp__365 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__366 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__367 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__292->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__366&1u))&1)))));
  *((&llvm_cbe_tmp__367[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__365)))])) = ((unsigned char )1);
  goto llvm_cbe_tmp__378;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__382:
  llvm_cbe_tmp__356 = *(&llvm_cbe_i1);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__356))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__383;
  } else {
    goto llvm_cbe_tmp__381;
  }

llvm_cbe_tmp__384:
  llvm_cbe_tmp__359 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__292->field6)));
  *(&llvm_cbe_rate2) = (((unsigned char )llvm_cbe_tmp__359));
  _Z4waitv();
  llvm_cbe_tmp__360 = *(&llvm_cbe_rate2);
  llvm_cbe_tmp__361 = *(&llvm_cbe_i1);
  llvm_cbe_tmp__362 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__363 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__292->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__362&1u))&1)))));
  *((&llvm_cbe_tmp__363[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__361)))])) = llvm_cbe_tmp__360;
  llvm_cbe_tmp__364 = *(&llvm_cbe_i1);
  *(&llvm_cbe_i1) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__364) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__382;

llvm_cbe_tmp__383:
  llvm_cbe_tmp__357 = *(&llvm_cbe_i1);
  llvm_cbe_tmp__358 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__357)) == llvm_cbe_tmp__358)) {
    goto llvm_cbe_tmp__381;
  } else {
    goto llvm_cbe_tmp__384;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__385:
  *(&llvm_cbe_tmp__291) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field4)), (&llvm_cbe_tmp__291));
  llvm_cbe_tmp__351 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__352 = *(&llvm_cbe_nu);
  *(&llvm_cbe_tmp1) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__351))) * ((unsigned int )llvm_cbe_tmp__352))))));
  llvm_cbe_tmp__353 = *(&llvm_cbe_tmp1);
  llvm_cbe_tmp__354 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp2) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__353))) + ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__354))))))));
  llvm_cbe_tmp__355 = *(&llvm_cbe_tmp2);
  *(&llvm_cbe_pingpong) = (((unsigned char )(bool )((((signed int )(((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__355))) % ((signed int )2u)))) != 0u)));
  *(&llvm_cbe_i1) = ((unsigned short )0);
  goto llvm_cbe_tmp__382;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__386:
  _Z4waitv();
  llvm_cbe_tmp__350 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field5))))&1);
  if ((((llvm_cbe_tmp__350 ^ 1)&1))) {
    goto llvm_cbe_tmp__386;
  } else {
    goto llvm_cbe_tmp__385;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__387:
  *(&llvm_cbe_tmp__290) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field4)), (&llvm_cbe_tmp__290));
  goto llvm_cbe_tmp__386;

llvm_cbe_tmp__388:
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__292->field2)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__346 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__289) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__346))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__292->field3)), (&llvm_cbe_tmp__289));
  llvm_cbe_tmp__347 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__348 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__347)) == llvm_cbe_tmp__348)) {
    goto llvm_cbe_tmp__389;
  } else {
    goto llvm_cbe_tmp__387;
  }

llvm_cbe_tmp__390:
  llvm_cbe_tmp__339 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__340 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__339) * ((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__340))))));
  llvm_cbe_tmp__341 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__342 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__341)) == llvm_cbe_tmp__342)) {
    goto llvm_cbe_tmp__391;
  } else {
    goto llvm_cbe_tmp__388;
  }

llvm_cbe_tmp__392:
  llvm_cbe_tmp__335 = *(&llvm_cbe_index);
  llvm_cbe_tmp__336 = *(&llvm_cbe_ntu);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__335)) == llvm_cbe_tmp__336)) {
    goto llvm_cbe_tmp__393;
  } else {
    goto llvm_cbe_tmp__390;
  }

llvm_cbe_tmp__394:
  llvm_cbe_tmp__329 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__329))) + ((unsigned int )1u))))));
  llvm_cbe_tmp__330 = *(&llvm_cbe_index);
  llvm_cbe_tmp__331 = *(&llvm_cbe_nu);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__330)) == llvm_cbe_tmp__331)) {
    goto llvm_cbe_tmp__395;
  } else {
    goto llvm_cbe_tmp__392;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__396:
  _Z4waitv();
  llvm_cbe_tmp__326 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field39))))&1);
  if (llvm_cbe_tmp__326) {
    goto llvm_cbe_tmp__396;
  } else {
    goto llvm_cbe_tmp__394;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__397:
  *(&llvm_cbe_tmp__286) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field37)), (&llvm_cbe_tmp__286));
  goto llvm_cbe_tmp__396;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__398:
  _Z4waitv();
  llvm_cbe_tmp__325 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field39))))&1);
  if ((((llvm_cbe_tmp__325 ^ 1)&1))) {
    goto llvm_cbe_tmp__398;
  } else {
    goto llvm_cbe_tmp__397;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__379:
  *(&llvm_cbe_tmp__285) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field37)), (&llvm_cbe_tmp__285));
  goto llvm_cbe_tmp__398;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__399:
  _Z4waitv();
  llvm_cbe_tmp__328 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field42))))&1);
  if (llvm_cbe_tmp__328) {
    goto llvm_cbe_tmp__399;
  } else {
    goto llvm_cbe_tmp__394;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__400:
  *(&llvm_cbe_tmp__288) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field38)), (&llvm_cbe_tmp__288));
  goto llvm_cbe_tmp__399;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__401:
  _Z4waitv();
  llvm_cbe_tmp__327 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field42))))&1);
  if ((((llvm_cbe_tmp__327 ^ 1)&1))) {
    goto llvm_cbe_tmp__401;
  } else {
    goto llvm_cbe_tmp__400;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__380:
  *(&llvm_cbe_tmp__287) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__292->field38)), (&llvm_cbe_tmp__287));
  goto llvm_cbe_tmp__401;

llvm_cbe_tmp__395:
  llvm_cbe_tmp__332 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__333 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__332)) != llvm_cbe_tmp__333)) {
    goto llvm_cbe_tmp__402;
  } else {
    goto llvm_cbe_tmp__392;
  }

llvm_cbe_tmp__402:
  llvm_cbe_tmp__334 = *(&llvm_cbe_loop_count);
  *(&llvm_cbe_loop_count) = (((unsigned short )(((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__334))) + ((unsigned int )1u))))));
  *(&llvm_cbe_index) = ((unsigned short )0);
  goto llvm_cbe_tmp__392;

llvm_cbe_tmp__393:
  llvm_cbe_tmp__337 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__338 = *(&llvm_cbe_nlp);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__337)) == llvm_cbe_tmp__338)) {
    goto llvm_cbe_tmp__403;
  } else {
    goto llvm_cbe_tmp__390;
  }

llvm_cbe_tmp__391:
  llvm_cbe_tmp__343 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__344 = *(&llvm_cbe_nu);
  llvm_cbe_tmp__345 = *(&llvm_cbe_dma_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__345) + ((unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__343) * ((unsigned int )llvm_cbe_tmp__344))))))));
  goto llvm_cbe_tmp__388;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__389:
  _Z4waitv();
  llvm_cbe_tmp__349 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__292->field40))))&1);
  if ((((llvm_cbe_tmp__349 ^ 1)&1))) {
    goto llvm_cbe_tmp__389;
  } else {
    goto llvm_cbe_tmp__387;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__403:
  _Z4waitv();
  goto llvm_cbe_tmp__403;

  } while (1); /* end of syntactic loop '' */
}


bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__404;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__405;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__406;
  unsigned char *llvm_cbe_tmp__407;
  unsigned char llvm_cbe_tmp__408;
  unsigned char llvm_cbe_tmp__409;

  *(&llvm_cbe_tmp__404) = llvm_cbe_this;
  *(&llvm_cbe_tmp__405) = llvm_cbe_d;
  llvm_cbe_tmp__406 = *(&llvm_cbe_tmp__404);
  llvm_cbe_tmp__407 = *(&llvm_cbe_tmp__405);
  llvm_cbe_tmp__408 = *llvm_cbe_tmp__407;
  *((&llvm_cbe_tmp__406->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__408&1u))&1))));
  llvm_cbe_tmp__409 = *((&llvm_cbe_tmp__406->field0));
  return (((((bool )llvm_cbe_tmp__409&1u))&1));
}


void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__410;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__411;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__412;
  unsigned int *llvm_cbe_tmp__413;
  unsigned int llvm_cbe_tmp__414;

  *(&llvm_cbe_tmp__410) = llvm_cbe_this;
  *(&llvm_cbe_tmp__411) = llvm_cbe_d;
  llvm_cbe_tmp__412 = *(&llvm_cbe_tmp__410);
  llvm_cbe_tmp__413 = *(&llvm_cbe_tmp__411);
  llvm_cbe_tmp__414 = *llvm_cbe_tmp__413;
  *((&llvm_cbe_tmp__412->field0)) = llvm_cbe_tmp__414;
  return;
}


unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__415;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__416;
  unsigned short llvm_cbe_tmp__417;

  *(&llvm_cbe_tmp__415) = llvm_cbe_this;
  llvm_cbe_tmp__416 = *(&llvm_cbe_tmp__415);
  llvm_cbe_tmp__417 = *((&llvm_cbe_tmp__416->field0));
  return llvm_cbe_tmp__417;
}


unsigned char *_ZN11SysCArray2DIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__418;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__419;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__420;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__421;
  unsigned int llvm_cbe_tmp__422;
  unsigned char *llvm_cbe_tmp__423;
  unsigned int llvm_cbe_tmp__424;
  unsigned char *llvm_cbe_tmp__425;
  unsigned char *llvm_cbe_tmp__426;

  *(&llvm_cbe_tmp__419) = llvm_cbe_this;
  *(&llvm_cbe_tmp__420) = llvm_cbe_Xidx;
  llvm_cbe_tmp__421 = *(&llvm_cbe_tmp__419);
  llvm_cbe_tmp__422 = *(&llvm_cbe_tmp__420);
  if ((llvm_cbe_tmp__422 == 0u)) {
    goto llvm_cbe_tmp__427;
  } else {
    goto llvm_cbe_tmp__428;
  }

llvm_cbe_tmp__427:
  llvm_cbe_tmp__423 = *((&llvm_cbe_tmp__421->field1));
  *(&llvm_cbe_tmp__418) = llvm_cbe_tmp__423;
  goto llvm_cbe_tmp__429;

llvm_cbe_tmp__428:
  llvm_cbe_tmp__424 = *(&llvm_cbe_tmp__420);
  llvm_cbe_tmp__425 = *((&llvm_cbe_tmp__421->field0));
  *(&llvm_cbe_tmp__418) = ((&llvm_cbe_tmp__425[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__424) * ((unsigned int )512u)))))))]));
  goto llvm_cbe_tmp__429;

llvm_cbe_tmp__429:
  llvm_cbe_tmp__426 = *(&llvm_cbe_tmp__418);
  return llvm_cbe_tmp__426;
}


void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__430;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__431;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__432;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__433;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__434;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__435;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__436;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__437;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__438;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__439;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__440;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__441;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__442;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__443;    /* Address-exposed local */
  unsigned short llvm_cbe_ntu;    /* Address-exposed local */
  unsigned short llvm_cbe_nm;    /* Address-exposed local */
  unsigned int llvm_cbe_index;    /* Address-exposed local */
  unsigned char llvm_cbe_rating;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__444;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__445;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__446;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__447;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__448;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__449;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__450;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__451;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__452;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__453;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__454;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__455;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__456;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__457;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__458;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__459;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__460;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__461;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__462;
  bool llvm_cbe_tmp__463;
  bool llvm_cbe_tmp__464;
  unsigned long long llvm_cbe_tmp__465;
  unsigned long long llvm_cbe_tmp__466;
  unsigned long long llvm_cbe_tmp__467;
  unsigned long long llvm_cbe_tmp__468;
  unsigned long long llvm_cbe_tmp__469;
  unsigned long long llvm_cbe_tmp__470;
  unsigned short llvm_cbe_tmp__471;
  unsigned short llvm_cbe_tmp__472;
  unsigned int *llvm_cbe_tmp__473;
  unsigned int llvm_cbe_tmp__474;
  unsigned short *llvm_cbe_tmp__475;
  unsigned short llvm_cbe_tmp__476;
  bool llvm_cbe_tmp__477;
  unsigned char llvm_cbe_tmp__478;
  unsigned int llvm_cbe_tmp__479;
  unsigned int llvm_cbe_tmp__480;
  unsigned int llvm_cbe_tmp__481;
  unsigned int llvm_cbe_tmp__482;
  unsigned int llvm_cbe_tmp__483;
  unsigned int llvm_cbe_tmp__484;
  unsigned char llvm_cbe_tmp__485;
  unsigned long long llvm_cbe_tmp__486;
  unsigned long long llvm_cbe_tmp__487;
  unsigned long long llvm_cbe_tmp__488;
  unsigned long long llvm_cbe_tmp__489;
  unsigned long long llvm_cbe_tmp__490;
  unsigned long long llvm_cbe_tmp__491;
  unsigned long long llvm_cbe_tmp__492;
  unsigned long long llvm_cbe_tmp__493;
  unsigned long long llvm_cbe_tmp__494;
  unsigned long long llvm_cbe_tmp__495;
  unsigned long long llvm_cbe_tmp__496;
  unsigned char llvm_cbe_tmp__497;
  unsigned int llvm_cbe_tmp__498;
  unsigned char llvm_cbe_tmp__499;
  unsigned long long llvm_cbe_tmp__500;
  unsigned long long llvm_cbe_tmp__501;
  unsigned long long llvm_cbe_tmp__502;
  unsigned long long llvm_cbe_tmp__503;
  unsigned long long llvm_cbe_tmp__504;
  unsigned char *llvm_cbe_tmp__505;
  unsigned char *llvm_cbe_tmp__506;
  unsigned char *llvm_cbe_tmp__507;
  unsigned char *llvm_cbe_tmp__508;
  unsigned short llvm_cbe_tmp__509;
  unsigned short llvm_cbe_tmp__510;
  unsigned short llvm_cbe_tmp__511;
  unsigned short llvm_cbe_tmp__512;
  unsigned short llvm_cbe_tmp__513;
  unsigned short llvm_cbe_tmp__514;
  unsigned short llvm_cbe_tmp__515;
  unsigned short llvm_cbe_tmp__516;
  unsigned char *llvm_cbe_tmp__517;
  unsigned char llvm_cbe_tmp__518;
  unsigned char llvm_cbe_tmp__519;
  unsigned char llvm_cbe_tmp__520;
  unsigned int llvm_cbe_tmp__521;
  unsigned int llvm_cbe_tmp__522;
  unsigned int llvm_cbe_tmp__523;
  unsigned int llvm_cbe_tmp__524;
  unsigned int llvm_cbe_tmp__525;
  unsigned int llvm_cbe_tmp__526;
  unsigned char llvm_cbe_tmp__527;
  unsigned char llvm_cbe_tmp__528;
  unsigned int llvm_cbe_tmp__529;
  unsigned char llvm_cbe_tmp__530;
  bool llvm_cbe_tmp__531;
  unsigned long long llvm_cbe_tmp__532;
  bool llvm_cbe_tmp__533;
  unsigned long long llvm_cbe_tmp__534;
  unsigned short llvm_cbe_tmp__535;
  unsigned long long llvm_cbe_tmp__536;
  unsigned short llvm_cbe_tmp__537;
  unsigned long long llvm_cbe_tmp__538;
  unsigned short llvm_cbe_tmp__539;
  unsigned long long llvm_cbe_tmp__540;
  unsigned short llvm_cbe_tmp__541;
  unsigned long long llvm_cbe_tmp__542;
  unsigned short llvm_cbe_tmp__543;
  unsigned long long llvm_cbe_tmp__544;
  unsigned short llvm_cbe_tmp__545;
  unsigned long long llvm_cbe_tmp__546;
  unsigned int llvm_cbe_tmp__547;
  unsigned long long llvm_cbe_tmp__548;
  unsigned int llvm_cbe_tmp__549;
  unsigned long long llvm_cbe_tmp__550;
  bool llvm_cbe_tmp__551;
  unsigned long long llvm_cbe_tmp__552;
  bool llvm_cbe_tmp__553;
  unsigned long long llvm_cbe_tmp__554;
  unsigned int llvm_cbe_tmp__555;
  unsigned long long llvm_cbe_tmp__556;
  unsigned int llvm_cbe_tmp__557;
  unsigned long long llvm_cbe_tmp__558;
  unsigned int llvm_cbe_tmp__559;
  unsigned long long llvm_cbe_tmp__560;
  unsigned int llvm_cbe_tmp__561;
  unsigned long long llvm_cbe_tmp__562;
  unsigned short llvm_cbe_tmp__563;
  unsigned long long llvm_cbe_tmp__564;
  unsigned char *llvm_cbe_tmp__565;
  unsigned char *llvm_cbe_tmp__566;
  bool llvm_cbe_tmp__567;
  unsigned char *llvm_cbe_tmp__568;
  unsigned char *llvm_cbe_tmp__569;
  bool llvm_cbe_tmp__570;
  unsigned short llvm_cbe_tmp__571;
  unsigned short llvm_cbe_tmp__572;
  unsigned char llvm_cbe_tmp__573;
  unsigned int llvm_cbe_tmp__574;
  unsigned int llvm_cbe_tmp__575;
  unsigned int llvm_cbe_tmp__576;
  unsigned int llvm_cbe_tmp__577;
  unsigned int llvm_cbe_tmp__578;
  unsigned int llvm_cbe_tmp__579;
  unsigned char llvm_cbe_tmp__580;
  unsigned char llvm_cbe_tmp__581;
  unsigned int llvm_cbe_tmp__582;
  unsigned char llvm_cbe_tmp__583;
  bool llvm_cbe_tmp__584;
  unsigned long long llvm_cbe_tmp__585;
  bool llvm_cbe_tmp__586;
  unsigned long long llvm_cbe_tmp__587;
  unsigned short llvm_cbe_tmp__588;
  unsigned long long llvm_cbe_tmp__589;
  unsigned short llvm_cbe_tmp__590;
  unsigned long long llvm_cbe_tmp__591;
  unsigned short llvm_cbe_tmp__592;
  unsigned long long llvm_cbe_tmp__593;
  unsigned short llvm_cbe_tmp__594;
  unsigned long long llvm_cbe_tmp__595;
  unsigned short llvm_cbe_tmp__596;
  unsigned long long llvm_cbe_tmp__597;
  unsigned short llvm_cbe_tmp__598;
  unsigned long long llvm_cbe_tmp__599;
  unsigned int llvm_cbe_tmp__600;
  unsigned long long llvm_cbe_tmp__601;
  unsigned int llvm_cbe_tmp__602;
  unsigned long long llvm_cbe_tmp__603;
  bool llvm_cbe_tmp__604;
  unsigned long long llvm_cbe_tmp__605;
  bool llvm_cbe_tmp__606;
  unsigned long long llvm_cbe_tmp__607;
  unsigned int llvm_cbe_tmp__608;
  unsigned long long llvm_cbe_tmp__609;
  unsigned int llvm_cbe_tmp__610;
  unsigned long long llvm_cbe_tmp__611;
  unsigned int llvm_cbe_tmp__612;
  unsigned long long llvm_cbe_tmp__613;
  unsigned int llvm_cbe_tmp__614;
  unsigned long long llvm_cbe_tmp__615;
  unsigned short llvm_cbe_tmp__616;
  unsigned long long llvm_cbe_tmp__617;
  unsigned char *llvm_cbe_tmp__618;
  unsigned char *llvm_cbe_tmp__619;
  bool llvm_cbe_tmp__620;
  unsigned char *llvm_cbe_tmp__621;
  unsigned char *llvm_cbe_tmp__622;
  bool llvm_cbe_tmp__623;

  *(&llvm_cbe_tmp__430) = llvm_cbe_this;
  llvm_cbe_tmp__462 = *(&llvm_cbe_tmp__430);
  *(&llvm_cbe_tmp__431) = ((unsigned char )1);
  llvm_cbe_tmp__463 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__462->field36)), (&llvm_cbe_tmp__431)))&1);
  *(&llvm_cbe_tmp__432) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__462->field8)), (&llvm_cbe_tmp__432));
  *(&llvm_cbe_tmp__433) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__462->field7)), (&llvm_cbe_tmp__433));
  *(&llvm_cbe_tmp__434) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field9)), (&llvm_cbe_tmp__434));
  *(&llvm_cbe_tmp__435) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field44)), (&llvm_cbe_tmp__435));
  *(&llvm_cbe_tmp__436) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field45)), (&llvm_cbe_tmp__436));
  *(&llvm_cbe_tmp__437) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field12)), (&llvm_cbe_tmp__437));
  goto llvm_cbe_tmp__624;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__624:
  _Z4waitv();
  llvm_cbe_tmp__464 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field36))))&1);
  if ((((llvm_cbe_tmp__464 ^ 1)&1))) {
    goto llvm_cbe_tmp__624;
  } else {
    goto llvm_cbe_tmp__625;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__625:
  llvm_cbe_tmp__465 = *((&GM.field5));
  *(&llvm_cbe_tmp__438) = (((unsigned short )llvm_cbe_tmp__465));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field30)), (&llvm_cbe_tmp__438));
  llvm_cbe_tmp__466 = *((&GM.field10));
  *(&llvm_cbe_tmp__439) = (((unsigned short )llvm_cbe_tmp__466));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field31)), (&llvm_cbe_tmp__439));
  llvm_cbe_tmp__467 = *((&GM.field9));
  *(&llvm_cbe_tmp__440) = (((unsigned short )llvm_cbe_tmp__467));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field32)), (&llvm_cbe_tmp__440));
  llvm_cbe_tmp__468 = *((&GM.field6));
  *(&llvm_cbe_tmp__441) = (((unsigned short )llvm_cbe_tmp__468));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field33)), (&llvm_cbe_tmp__441));
  llvm_cbe_tmp__469 = *((&GM.field8));
  *(&llvm_cbe_tmp__442) = (((unsigned short )llvm_cbe_tmp__469));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field34)), (&llvm_cbe_tmp__442));
  llvm_cbe_tmp__470 = *((&GM.field7));
  *(&llvm_cbe_tmp__443) = (((unsigned short )llvm_cbe_tmp__470));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field35)), (&llvm_cbe_tmp__443));
  llvm_cbe_tmp__471 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field34)));
  *(&llvm_cbe_ntu) = llvm_cbe_tmp__471;
  llvm_cbe_tmp__472 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field35)));
  *(&llvm_cbe_nm) = llvm_cbe_tmp__472;
  *(&llvm_cbe_index) = 0u;
  llvm_cbe_tmp__473 = _ZN13sc_signal_u32cvRjEv(((&llvm_cbe_tmp__462->field8)));
  llvm_cbe_tmp__474 = *llvm_cbe_tmp__473;
  llvm_cbe_tmp__475 = _ZN13sc_signal_u16cvRtEv(((&llvm_cbe_tmp__462->field35)));
  llvm_cbe_tmp__476 = *llvm_cbe_tmp__475;
  __CPROVER_assume((llvm_cbe_tmp__474 == (((unsigned int )(unsigned short )llvm_cbe_tmp__476))));
  *(&conf_done_inp) = ((unsigned char )1);
  *(&llvm_cbe_tmp__445) = ((unsigned char )1);
  llvm_cbe_tmp__477 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__462->field36)), (&llvm_cbe_tmp__445)))&1);
  *((&GM.field17)) = 0ull;
  *((&GM.field21)) = 1ull;
  *((&GM.field18)) = 1ull;
  *(&rst_inp) = ((unsigned char )0);
  llvm_cbe_tmp__478 = *(&conf_done_inp);
  *((&((&llvm_cbe_tmp__462->field13))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__478&1u))&1))));
  llvm_cbe_tmp__479 = *(&conf_num_hidden_inp);
  *((&((&llvm_cbe_tmp__462->field14))->field0)) = llvm_cbe_tmp__479;
  llvm_cbe_tmp__480 = *(&conf_num_visible_inp);
  *((&((&llvm_cbe_tmp__462->field15))->field0)) = llvm_cbe_tmp__480;
  llvm_cbe_tmp__481 = *(&conf_num_users_inp);
  *((&((&llvm_cbe_tmp__462->field16))->field0)) = llvm_cbe_tmp__481;
  llvm_cbe_tmp__482 = *(&conf_num_loops_inp);
  *((&((&llvm_cbe_tmp__462->field17))->field0)) = llvm_cbe_tmp__482;
  llvm_cbe_tmp__483 = *(&conf_num_testusers_inp);
  *((&((&llvm_cbe_tmp__462->field18))->field0)) = llvm_cbe_tmp__483;
  llvm_cbe_tmp__484 = *(&conf_num_movies_inp);
  *((&((&llvm_cbe_tmp__462->field19))->field0)) = llvm_cbe_tmp__484;
  llvm_cbe_tmp__485 = *(&rst_inp);
  *((&((&llvm_cbe_tmp__462->field1))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__485&1u))&1))));
  llvm_cbe_tmp__486 = *((&GM.field4));
  *(&llvm_cbe_tmp__446) = (((unsigned char )(bool )(llvm_cbe_tmp__486 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field36)), (&llvm_cbe_tmp__446));
  llvm_cbe_tmp__487 = *((&GM.field2));
  *(&llvm_cbe_tmp__447) = (((unsigned char )(bool )(llvm_cbe_tmp__487 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field12)), (&llvm_cbe_tmp__447));
  llvm_cbe_tmp__488 = *((&GM.field5));
  *(&llvm_cbe_tmp__448) = (((unsigned short )llvm_cbe_tmp__488));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field30)), (&llvm_cbe_tmp__448));
  llvm_cbe_tmp__489 = *((&GM.field10));
  *(&llvm_cbe_tmp__449) = (((unsigned short )llvm_cbe_tmp__489));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field31)), (&llvm_cbe_tmp__449));
  llvm_cbe_tmp__490 = *((&GM.field9));
  *(&llvm_cbe_tmp__450) = (((unsigned short )llvm_cbe_tmp__490));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field32)), (&llvm_cbe_tmp__450));
  llvm_cbe_tmp__491 = *((&GM.field6));
  *(&llvm_cbe_tmp__451) = (((unsigned short )llvm_cbe_tmp__491));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field33)), (&llvm_cbe_tmp__451));
  llvm_cbe_tmp__492 = *((&GM.field8));
  *(&llvm_cbe_tmp__452) = (((unsigned short )llvm_cbe_tmp__492));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field34)), (&llvm_cbe_tmp__452));
  llvm_cbe_tmp__493 = *((&GM.field7));
  *(&llvm_cbe_tmp__453) = (((unsigned short )llvm_cbe_tmp__493));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__462->field35)), (&llvm_cbe_tmp__453));
  llvm_cbe_tmp__494 = *((&GM.field14));
  *(&llvm_cbe_tmp__454) = (((unsigned int )llvm_cbe_tmp__494));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__462->field2)), (&llvm_cbe_tmp__454));
  llvm_cbe_tmp__495 = *((&GM.field15));
  *(&llvm_cbe_tmp__455) = (((unsigned int )llvm_cbe_tmp__495));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__462->field3)), (&llvm_cbe_tmp__455));
  llvm_cbe_tmp__496 = *((&GM.field16));
  *(&llvm_cbe_tmp__456) = (((unsigned char )(bool )(llvm_cbe_tmp__496 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field4)), (&llvm_cbe_tmp__456));
  llvm_cbe_tmp__497 = *(&rd_grant_inp);
  *((&((&llvm_cbe_tmp__462->field5))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__497&1u))&1))));
  llvm_cbe_tmp__498 = *(&data_in_inp);
  *((&((&llvm_cbe_tmp__462->field6))->field0)) = llvm_cbe_tmp__498;
  llvm_cbe_tmp__499 = *(&wr_grant_inp);
  *((&((&llvm_cbe_tmp__462->field10))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__499&1u))&1))));
  llvm_cbe_tmp__500 = *((&GM.field21));
  *(&llvm_cbe_tmp__457) = (((unsigned char )(bool )(llvm_cbe_tmp__500 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field9)), (&llvm_cbe_tmp__457));
  llvm_cbe_tmp__501 = *((&GM.field19));
  *(&llvm_cbe_tmp__458) = (((unsigned int )llvm_cbe_tmp__501));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__462->field7)), (&llvm_cbe_tmp__458));
  llvm_cbe_tmp__502 = *((&GM.field20));
  *(&llvm_cbe_tmp__459) = (((unsigned int )llvm_cbe_tmp__502));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__462->field8)), (&llvm_cbe_tmp__459));
  llvm_cbe_tmp__503 = *((&GM.field1));
  *(&llvm_cbe_tmp__460) = (((unsigned int )llvm_cbe_tmp__503));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__462->field11)), (&llvm_cbe_tmp__460));
  llvm_cbe_tmp__504 = *((&GM.field3));
  *(&llvm_cbe_i) = (((unsigned short )llvm_cbe_tmp__504));
  llvm_cbe_tmp__505 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__462->field20)), 0u);
  llvm_cbe_tmp__506 = *((&GM.field0.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__505, llvm_cbe_tmp__506);
  llvm_cbe_tmp__507 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__462->field28)), 0u);
  llvm_cbe_tmp__508 = *((&GM.field11.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__507, llvm_cbe_tmp__508);
  llvm_cbe_tmp__509 = _Z10nondet_intv();
  *(&llvm_cbe_i) = llvm_cbe_tmp__509;
  llvm_cbe_tmp__510 = *(&llvm_cbe_i);
  llvm_cbe_tmp__511 = *(&llvm_cbe_nm);
  __CPROVER_assume((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__510))) < ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__511)))));
  llvm_cbe_tmp__512 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__512) + ((unsigned short )((unsigned short )1)))))));
  llvm_cbe_tmp__513 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__513))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__626;
  } else {
    goto llvm_cbe_tmp__627;
  }

llvm_cbe_tmp__626:
  llvm_cbe_tmp__514 = *(&llvm_cbe_i);
  llvm_cbe_tmp__515 = *(&llvm_cbe_nm);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__514)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__515)))) {
    goto llvm_cbe_tmp__627;
  } else {
    goto llvm_cbe_tmp__628;
  }

llvm_cbe_tmp__628:
  llvm_cbe_tmp__516 = *(&llvm_cbe_i);
  llvm_cbe_tmp__517 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__462->field28)), 0u);
  llvm_cbe_tmp__518 = *((&llvm_cbe_tmp__517[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__516)))]));
  *(&llvm_cbe_rating) = llvm_cbe_tmp__518;
  _Z4waitv();
  llvm_cbe_tmp__519 = *(&llvm_cbe_rating);
  *(&llvm_cbe_tmp__444) = (((unsigned int )(unsigned char )llvm_cbe_tmp__519));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__462->field11)), (&llvm_cbe_tmp__444));
  *(&wr_complete) = 0u;
  llvm_cbe_tmp__520 = *(&conf_done_inp);
  llvm_cbe_tmp__521 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__522 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__523 = *(&conf_num_users_inp);
  llvm_cbe_tmp__524 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__525 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__526 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__527 = *(&rst_inp);
  llvm_cbe_tmp__528 = *(&rd_grant_inp);
  llvm_cbe_tmp__529 = *(&data_in_inp);
  llvm_cbe_tmp__530 = *(&wr_grant_inp);
  _ZN11model_store6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__520&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__521)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__522)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__523)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__524)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__525)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__526)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__527&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__528&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__529)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__530&1u))&1)))));
  llvm_cbe_tmp__531 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field36))))&1);
  llvm_cbe_tmp__532 = *((&GM.field4));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__531)) == llvm_cbe_tmp__532), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__533 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field12))))&1);
  llvm_cbe_tmp__534 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__533)) == llvm_cbe_tmp__534), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__535 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field30)));
  llvm_cbe_tmp__536 = *((&GM.field5));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__535)) == llvm_cbe_tmp__536), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__537 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field31)));
  llvm_cbe_tmp__538 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__537)) == llvm_cbe_tmp__538), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__539 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field32)));
  llvm_cbe_tmp__540 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__539)) == llvm_cbe_tmp__540), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__541 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field33)));
  llvm_cbe_tmp__542 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__541)) == llvm_cbe_tmp__542), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__543 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field34)));
  llvm_cbe_tmp__544 = *((&GM.field8));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__543)) == llvm_cbe_tmp__544), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__545 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field35)));
  llvm_cbe_tmp__546 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__545)) == llvm_cbe_tmp__546), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__547 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field2)));
  llvm_cbe_tmp__548 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__547)) == llvm_cbe_tmp__548), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__549 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field3)));
  llvm_cbe_tmp__550 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__549)) == llvm_cbe_tmp__550), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__551 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field4))))&1);
  llvm_cbe_tmp__552 = *((&GM.field16));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__551)) == llvm_cbe_tmp__552), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__553 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field9))))&1);
  llvm_cbe_tmp__554 = *((&GM.field21));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__553)) == llvm_cbe_tmp__554), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__555 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field7)));
  llvm_cbe_tmp__556 = *((&GM.field19));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__555)) == llvm_cbe_tmp__556), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__557 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field8)));
  llvm_cbe_tmp__558 = *((&GM.field20));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__557)) == llvm_cbe_tmp__558), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__559 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field11)));
  llvm_cbe_tmp__560 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__559)) == llvm_cbe_tmp__560), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__561 = *(&wr_complete);
  llvm_cbe_tmp__562 = *((&GM.field17));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__561)) == llvm_cbe_tmp__562), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__563 = *(&llvm_cbe_i);
  llvm_cbe_tmp__564 = *((&GM.field3));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__563)) == llvm_cbe_tmp__564), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__565 = *((&GM.field0.field0));
  llvm_cbe_tmp__566 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__462->field20)), 0u);
  llvm_cbe_tmp__567 = ((__CPROVER_array_equal(llvm_cbe_tmp__565, llvm_cbe_tmp__566))&1);
  __CPROVER_assert(llvm_cbe_tmp__567, ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__568 = *((&GM.field11.field0));
  llvm_cbe_tmp__569 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__462->field28)), 0u);
  llvm_cbe_tmp__570 = ((__CPROVER_array_equal(llvm_cbe_tmp__568, llvm_cbe_tmp__569))&1);
  __CPROVER_assert(llvm_cbe_tmp__570, ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__571 = *(&llvm_cbe_i);
  llvm_cbe_tmp__572 = *(&llvm_cbe_nm);
  __CPROVER_assert((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__571))) < ((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__572)))), ((&_OC_str20.array[((signed int )0u)])));
  goto llvm_cbe_tmp__629;

llvm_cbe_tmp__627:
  *(&llvm_cbe_tmp__461) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__462->field45)), (&llvm_cbe_tmp__461));
  *(&wr_complete) = 1u;
  llvm_cbe_tmp__573 = *(&conf_done_inp);
  llvm_cbe_tmp__574 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__575 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__576 = *(&conf_num_users_inp);
  llvm_cbe_tmp__577 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__578 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__579 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__580 = *(&rst_inp);
  llvm_cbe_tmp__581 = *(&rd_grant_inp);
  llvm_cbe_tmp__582 = *(&data_in_inp);
  llvm_cbe_tmp__583 = *(&wr_grant_inp);
  _ZN11model_store6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__573&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__574)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__575)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__576)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__577)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__578)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__579)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__580&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__581&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__582)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__583&1u))&1)))));
  llvm_cbe_tmp__584 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field36))))&1);
  llvm_cbe_tmp__585 = *((&GM.field4));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__584)) == llvm_cbe_tmp__585), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__586 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field12))))&1);
  llvm_cbe_tmp__587 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__586)) == llvm_cbe_tmp__587), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__588 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field30)));
  llvm_cbe_tmp__589 = *((&GM.field5));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__588)) == llvm_cbe_tmp__589), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__590 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field31)));
  llvm_cbe_tmp__591 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__590)) == llvm_cbe_tmp__591), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__592 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field32)));
  llvm_cbe_tmp__593 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__592)) == llvm_cbe_tmp__593), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__594 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field33)));
  llvm_cbe_tmp__595 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__594)) == llvm_cbe_tmp__595), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__596 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field34)));
  llvm_cbe_tmp__597 = *((&GM.field8));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__596)) == llvm_cbe_tmp__597), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__598 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__462->field35)));
  llvm_cbe_tmp__599 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__598)) == llvm_cbe_tmp__599), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__600 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field2)));
  llvm_cbe_tmp__601 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__600)) == llvm_cbe_tmp__601), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__602 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field3)));
  llvm_cbe_tmp__603 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__602)) == llvm_cbe_tmp__603), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__604 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field4))))&1);
  llvm_cbe_tmp__605 = *((&GM.field16));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__604)) == llvm_cbe_tmp__605), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__606 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__462->field9))))&1);
  llvm_cbe_tmp__607 = *((&GM.field21));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__606)) == llvm_cbe_tmp__607), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__608 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field7)));
  llvm_cbe_tmp__609 = *((&GM.field19));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__608)) == llvm_cbe_tmp__609), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__610 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field8)));
  llvm_cbe_tmp__611 = *((&GM.field20));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__610)) == llvm_cbe_tmp__611), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__612 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__462->field11)));
  llvm_cbe_tmp__613 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__612)) == llvm_cbe_tmp__613), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__614 = *(&wr_complete);
  llvm_cbe_tmp__615 = *((&GM.field17));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__614)) == llvm_cbe_tmp__615), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__616 = *(&llvm_cbe_i);
  llvm_cbe_tmp__617 = *((&GM.field3));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__616)) == llvm_cbe_tmp__617), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__618 = *((&GM.field0.field0));
  llvm_cbe_tmp__619 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__462->field20)), 0u);
  llvm_cbe_tmp__620 = ((__CPROVER_array_equal(llvm_cbe_tmp__618, llvm_cbe_tmp__619))&1);
  __CPROVER_assert(llvm_cbe_tmp__620, ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__621 = *((&GM.field11.field0));
  llvm_cbe_tmp__622 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__462->field28)), 0u);
  llvm_cbe_tmp__623 = ((__CPROVER_array_equal(llvm_cbe_tmp__621, llvm_cbe_tmp__622))&1);
  __CPROVER_assert(llvm_cbe_tmp__623, ((&_OC_str19.array[((signed int )0u)])));
  goto llvm_cbe_tmp__629;

llvm_cbe_tmp__629:
  return;
}


unsigned int *_ZN13sc_signal_u32cvRjEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__630;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__631;

  *(&llvm_cbe_tmp__630) = llvm_cbe_this;
  llvm_cbe_tmp__631 = *(&llvm_cbe_tmp__630);
  return ((&llvm_cbe_tmp__631->field0));
}


unsigned short *_ZN13sc_signal_u16cvRtEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__632;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__633;

  *(&llvm_cbe_tmp__632) = llvm_cbe_this;
  llvm_cbe_tmp__633 = *(&llvm_cbe_tmp__632);
  return ((&llvm_cbe_tmp__633->field0));
}


unsigned char *_ZN11SysCArray2DIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__634;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__635;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__636;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__637;
  unsigned int llvm_cbe_tmp__638;
  unsigned char *llvm_cbe_tmp__639;
  unsigned int llvm_cbe_tmp__640;
  unsigned char *llvm_cbe_tmp__641;
  unsigned char *llvm_cbe_tmp__642;

  *(&llvm_cbe_tmp__635) = llvm_cbe_this;
  *(&llvm_cbe_tmp__636) = llvm_cbe_Xidx;
  llvm_cbe_tmp__637 = *(&llvm_cbe_tmp__635);
  llvm_cbe_tmp__638 = *(&llvm_cbe_tmp__636);
  if ((llvm_cbe_tmp__638 == 0u)) {
    goto llvm_cbe_tmp__643;
  } else {
    goto llvm_cbe_tmp__644;
  }

llvm_cbe_tmp__643:
  llvm_cbe_tmp__639 = *((&llvm_cbe_tmp__637->field1));
  *(&llvm_cbe_tmp__634) = llvm_cbe_tmp__639;
  goto llvm_cbe_tmp__645;

llvm_cbe_tmp__644:
  llvm_cbe_tmp__640 = *(&llvm_cbe_tmp__636);
  llvm_cbe_tmp__641 = *((&llvm_cbe_tmp__637->field0));
  *(&llvm_cbe_tmp__634) = ((&llvm_cbe_tmp__641[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__640) * ((unsigned int )128u)))))))]));
  goto llvm_cbe_tmp__645;

llvm_cbe_tmp__645:
  llvm_cbe_tmp__642 = *(&llvm_cbe_tmp__634);
  return llvm_cbe_tmp__642;
}


static void __cxx_global_var_init21(void) {
  _ZN3rbmC1Ev((&IMPL));
  return;
}


void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__646;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__647;

  *(&llvm_cbe_tmp__646) = llvm_cbe_this;
  llvm_cbe_tmp__647 = *(&llvm_cbe_tmp__646);
  _ZN3rbmC2Ev(llvm_cbe_tmp__647);
  return;
}


unsigned int main(void) {
  unsigned int llvm_cbe_tmp__648;    /* Address-exposed local */
  _GLOBAL__I_a();  CODE_FOR_MAIN();
  *(&llvm_cbe_tmp__648) = 0u;
  _ZN3rbm5storeEv((&IMPL));
  return 0u;
}


void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__649;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__650;
  unsigned char *llvm_cbe_tmp__651;
  unsigned char llvm_cbe_tmp__652;
  unsigned char *llvm_cbe_tmp__653;
  unsigned char llvm_cbe_tmp__654;
  unsigned char *llvm_cbe_tmp__655;
  unsigned char llvm_cbe_tmp__656;
  unsigned char *llvm_cbe_tmp__657;
  unsigned char llvm_cbe_tmp__658;
  unsigned char *llvm_cbe_tmp__659;
  unsigned char llvm_cbe_tmp__660;

  *(&llvm_cbe_tmp__649) = llvm_cbe_this;
  llvm_cbe_tmp__650 = *(&llvm_cbe_tmp__649);
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__650->field0)), ((&_OC_str22.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__650->field1)), ((&_OC_str23.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field2)), ((&_OC_str24.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field3)), ((&_OC_str25.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__650->field4)), ((&_OC_str26.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__650->field5)), ((&_OC_str27.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field6)), ((&_OC_str28.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field7)), ((&_OC_str29.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field8)), ((&_OC_str30.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__650->field9)), ((&_OC_str31.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__650->field10)), ((&_OC_str32.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field11)), ((&_OC_str33.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__650->field12)), ((&_OC_str34.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__650->field13)), ((&_OC_str35.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field14)), ((&_OC_str36.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field15)), ((&_OC_str37.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field16)), ((&_OC_str38.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field17)), ((&_OC_str39.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field18)), ((&_OC_str40.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__650->field19)), ((&_OC_str41.array[((signed int )0u)])));
  _ZN11SysCArray2DIhLj2ELj512EEC1Ev(((&llvm_cbe_tmp__650->field20)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__650->field21)));
  _ZN11SysCArray1DIbLj128EEC1Ev(((&llvm_cbe_tmp__650->field22)));
  _ZN11SysCArray2DIfLj501ELj101EEC1Ev(((&llvm_cbe_tmp__650->field23)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__650->field24)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__650->field25)));
  _ZN11SysCArray1DIfLj5EEC1Ev(((&llvm_cbe_tmp__650->field26)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__650->field27)));
  _ZN11SysCArray2DIhLj2ELj128EEC1Ev(((&llvm_cbe_tmp__650->field28)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__650->field30)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__650->field31)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__650->field32)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__650->field33)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__650->field34)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__650->field35)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field36)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field37)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field38)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field39)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field40)));
  _ZN15sc_signal_int32C1Ev(((&llvm_cbe_tmp__650->field41)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field42)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field43)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field44)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__650->field45)));
  llvm_cbe_tmp__651 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__650->field1)));
  llvm_cbe_tmp__652 = *llvm_cbe_tmp__651;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__652&1u))&1)))), 0);
  llvm_cbe_tmp__653 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__650->field1)));
  llvm_cbe_tmp__654 = *llvm_cbe_tmp__653;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__654&1u))&1)))), 0);
  llvm_cbe_tmp__655 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__650->field1)));
  llvm_cbe_tmp__656 = *llvm_cbe_tmp__655;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__656&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__657 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__650->field1)));
  llvm_cbe_tmp__658 = *llvm_cbe_tmp__657;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__658&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__659 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__650->field1)));
  llvm_cbe_tmp__660 = *llvm_cbe_tmp__659;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__660&1u))&1)))), 0);
  return;
}


void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__661;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__662;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__663;
  unsigned char *llvm_cbe_tmp__664;

  *(&llvm_cbe_tmp__661) = llvm_cbe_this;
  *(&llvm_cbe_tmp__662) = llvm_cbe_p;
  llvm_cbe_tmp__663 = *(&llvm_cbe_tmp__661);
  llvm_cbe_tmp__664 = *(&llvm_cbe_tmp__662);
  _ZN14sc_signal_boolC2EPKc(llvm_cbe_tmp__663, llvm_cbe_tmp__664);
  return;
}


void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__665;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__666;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__667;
  unsigned char *llvm_cbe_tmp__668;

  *(&llvm_cbe_tmp__665) = llvm_cbe_this;
  *(&llvm_cbe_tmp__666) = llvm_cbe_p;
  llvm_cbe_tmp__667 = *(&llvm_cbe_tmp__665);
  llvm_cbe_tmp__668 = *(&llvm_cbe_tmp__666);
  _ZN13sc_signal_u32C2EPKc(llvm_cbe_tmp__667, llvm_cbe_tmp__668);
  return;
}


void _ZN11SysCArray2DIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__669;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__670;

  *(&llvm_cbe_tmp__669) = llvm_cbe_this;
  llvm_cbe_tmp__670 = *(&llvm_cbe_tmp__669);
  _ZN11SysCArray2DIhLj2ELj512EEC2Ev(llvm_cbe_tmp__670);
  return;
}


void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__671;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__672;

  *(&llvm_cbe_tmp__671) = llvm_cbe_this;
  llvm_cbe_tmp__672 = *(&llvm_cbe_tmp__671);
  _ZN11SysCArray1DIbLj512EEC2Ev(llvm_cbe_tmp__672);
  return;
}


void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__673;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__674;

  *(&llvm_cbe_tmp__673) = llvm_cbe_this;
  llvm_cbe_tmp__674 = *(&llvm_cbe_tmp__673);
  _ZN11SysCArray1DIbLj128EEC2Ev(llvm_cbe_tmp__674);
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_unnamed3 *llvm_cbe_this) {
  struct l_unnamed3 *llvm_cbe_tmp__675;    /* Address-exposed local */
  struct l_unnamed3 *llvm_cbe_tmp__676;

  *(&llvm_cbe_tmp__675) = llvm_cbe_this;
  llvm_cbe_tmp__676 = *(&llvm_cbe_tmp__675);
  _ZN11SysCArray2DIfLj501ELj101EEC2Ev(llvm_cbe_tmp__676);
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__677;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__678;

  *(&llvm_cbe_tmp__677) = llvm_cbe_this;
  llvm_cbe_tmp__678 = *(&llvm_cbe_tmp__677);
  _ZN11SysCArray2DIbLj501ELj101EEC2Ev(llvm_cbe_tmp__678);
  return;
}


void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_unnamed4 *llvm_cbe_this) {
  struct l_unnamed4 *llvm_cbe_tmp__679;    /* Address-exposed local */
  struct l_unnamed4 *llvm_cbe_tmp__680;

  *(&llvm_cbe_tmp__679) = llvm_cbe_this;
  llvm_cbe_tmp__680 = *(&llvm_cbe_tmp__679);
  _ZN11SysCArray1DIfLj5EEC2Ev(llvm_cbe_tmp__680);
  return;
}


void _ZN11SysCArray2DIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__681;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__682;

  *(&llvm_cbe_tmp__681) = llvm_cbe_this;
  llvm_cbe_tmp__682 = *(&llvm_cbe_tmp__681);
  _ZN11SysCArray2DIhLj2ELj128EEC2Ev(llvm_cbe_tmp__682);
  return;
}


void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__683;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__684;

  *(&llvm_cbe_tmp__683) = llvm_cbe_this;
  llvm_cbe_tmp__684 = *(&llvm_cbe_tmp__683);
  _ZN13sc_signal_u16C2Ev(llvm_cbe_tmp__684);
  return;
}


void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__685;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__686;

  *(&llvm_cbe_tmp__685) = llvm_cbe_this;
  llvm_cbe_tmp__686 = *(&llvm_cbe_tmp__685);
  _ZN14sc_signal_boolC2Ev(llvm_cbe_tmp__686);
  return;
}


void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__687;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__688;

  *(&llvm_cbe_tmp__687) = llvm_cbe_this;
  llvm_cbe_tmp__688 = *(&llvm_cbe_tmp__687);
  _ZN15sc_signal_int32C2Ev(llvm_cbe_tmp__688);
  return;
}


unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__689;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__690;

  *(&llvm_cbe_tmp__689) = llvm_cbe_this;
  llvm_cbe_tmp__690 = *(&llvm_cbe_tmp__689);
  return ((&llvm_cbe_tmp__690->field0));
}


void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__691;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__692;

  *(&llvm_cbe_tmp__691) = llvm_cbe_this;
  llvm_cbe_tmp__692 = *(&llvm_cbe_tmp__691);
  return;
}


void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__693;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__694;

  *(&llvm_cbe_tmp__693) = llvm_cbe_this;
  llvm_cbe_tmp__694 = *(&llvm_cbe_tmp__693);
  return;
}


void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__695;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__696;

  *(&llvm_cbe_tmp__695) = llvm_cbe_this;
  llvm_cbe_tmp__696 = *(&llvm_cbe_tmp__695);
  return;
}


void _ZN11SysCArray2DIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__697;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__698;
  unsigned char *llvm_cbe_tmp__699;
  unsigned char *llvm_cbe_tmp__700;

  *(&llvm_cbe_tmp__697) = llvm_cbe_this;
  llvm_cbe_tmp__698 = *(&llvm_cbe_tmp__697);
  llvm_cbe_tmp__699 = __CPROVER_malloc(256ull);
  *((&llvm_cbe_tmp__698->field0)) = llvm_cbe_tmp__699;
  llvm_cbe_tmp__700 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__698->field1)) = llvm_cbe_tmp__700;
  return;
}


void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_unnamed4 *llvm_cbe_this) {
  struct l_unnamed4 *llvm_cbe_tmp__701;    /* Address-exposed local */
  struct l_unnamed4 *llvm_cbe_tmp__702;
  unsigned char *llvm_cbe_tmp__703;

  *(&llvm_cbe_tmp__701) = llvm_cbe_this;
  llvm_cbe_tmp__702 = *(&llvm_cbe_tmp__701);
  llvm_cbe_tmp__703 = __CPROVER_malloc(20ull);
  *((&llvm_cbe_tmp__702->field0)) = (((float *)llvm_cbe_tmp__703));
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__704;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__705;
  unsigned char *llvm_cbe_tmp__706;
  unsigned char *llvm_cbe_tmp__707;

  *(&llvm_cbe_tmp__704) = llvm_cbe_this;
  llvm_cbe_tmp__705 = *(&llvm_cbe_tmp__704);
  llvm_cbe_tmp__706 = __CPROVER_malloc(50601ull);
  *((&llvm_cbe_tmp__705->field0)) = llvm_cbe_tmp__706;
  llvm_cbe_tmp__707 = __CPROVER_malloc(101ull);
  *((&llvm_cbe_tmp__705->field1)) = llvm_cbe_tmp__707;
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_unnamed3 *llvm_cbe_this) {
  struct l_unnamed3 *llvm_cbe_tmp__708;    /* Address-exposed local */
  struct l_unnamed3 *llvm_cbe_tmp__709;
  unsigned char *llvm_cbe_tmp__710;
  unsigned char *llvm_cbe_tmp__711;

  *(&llvm_cbe_tmp__708) = llvm_cbe_this;
  llvm_cbe_tmp__709 = *(&llvm_cbe_tmp__708);
  llvm_cbe_tmp__710 = __CPROVER_malloc(202404ull);
  *((&llvm_cbe_tmp__709->field0)) = (((float *)llvm_cbe_tmp__710));
  llvm_cbe_tmp__711 = __CPROVER_malloc(404ull);
  *((&llvm_cbe_tmp__709->field1)) = (((float *)llvm_cbe_tmp__711));
  return;
}


void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__712;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__713;
  unsigned char *llvm_cbe_tmp__714;

  *(&llvm_cbe_tmp__712) = llvm_cbe_this;
  llvm_cbe_tmp__713 = *(&llvm_cbe_tmp__712);
  llvm_cbe_tmp__714 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__713->field0)) = llvm_cbe_tmp__714;
  return;
}


void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__715;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__716;
  unsigned char *llvm_cbe_tmp__717;

  *(&llvm_cbe_tmp__715) = llvm_cbe_this;
  llvm_cbe_tmp__716 = *(&llvm_cbe_tmp__715);
  llvm_cbe_tmp__717 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__716->field0)) = llvm_cbe_tmp__717;
  return;
}


void _ZN11SysCArray2DIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__718;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__719;
  unsigned char *llvm_cbe_tmp__720;
  unsigned char *llvm_cbe_tmp__721;

  *(&llvm_cbe_tmp__718) = llvm_cbe_this;
  llvm_cbe_tmp__719 = *(&llvm_cbe_tmp__718);
  llvm_cbe_tmp__720 = __CPROVER_malloc(1024ull);
  *((&llvm_cbe_tmp__719->field0)) = llvm_cbe_tmp__720;
  llvm_cbe_tmp__721 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__719->field1)) = llvm_cbe_tmp__721;
  return;
}


void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__722;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__723;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__724;

  *(&llvm_cbe_tmp__722) = llvm_cbe_this;
  *(&llvm_cbe_tmp__723) = llvm_cbe_p;
  llvm_cbe_tmp__724 = *(&llvm_cbe_tmp__722);
  return;
}


void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__725;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__726;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__727;

  *(&llvm_cbe_tmp__725) = llvm_cbe_this;
  *(&llvm_cbe_tmp__726) = llvm_cbe_p;
  llvm_cbe_tmp__727 = *(&llvm_cbe_tmp__725);
  return;
}


void _ZN11model_storeD2Ev(struct l_class_OC_model_store *llvm_cbe_this) {
  struct l_class_OC_model_store *llvm_cbe_tmp__728;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__729;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__730;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__731;

  *(&llvm_cbe_tmp__728) = llvm_cbe_this;
  llvm_cbe_tmp__731 = *(&llvm_cbe_tmp__728);
  _ZN8type_memIhLj128EED1Ev(((&llvm_cbe_tmp__731->field11)));
  _ZN8type_memIhLj512EED1Ev(((&llvm_cbe_tmp__731->field0)));
  return;
}


void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__732;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__733;

  *(&llvm_cbe_tmp__732) = llvm_cbe_this;
  llvm_cbe_tmp__733 = *(&llvm_cbe_tmp__732);
  _ZN8type_memIhLj128EED2Ev(llvm_cbe_tmp__733);
  return;
}


void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__734;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__735;

  *(&llvm_cbe_tmp__734) = llvm_cbe_this;
  llvm_cbe_tmp__735 = *(&llvm_cbe_tmp__734);
  _ZN8type_memIhLj512EED2Ev(llvm_cbe_tmp__735);
  return;
}


void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__736;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__737;

  *(&llvm_cbe_tmp__736) = llvm_cbe_this;
  llvm_cbe_tmp__737 = *(&llvm_cbe_tmp__736);
  return;
}


void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__738;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__739;

  *(&llvm_cbe_tmp__738) = llvm_cbe_this;
  llvm_cbe_tmp__739 = *(&llvm_cbe_tmp__738);
  return;
}


void _ZN11model_storeC2Ev(struct l_class_OC_model_store *llvm_cbe_this) {
  struct l_class_OC_model_store *llvm_cbe_tmp__740;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__741;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__742;    /* Address-exposed local */
  struct l_class_OC_model_store *llvm_cbe_tmp__743;

  *(&llvm_cbe_tmp__740) = llvm_cbe_this;
  llvm_cbe_tmp__743 = *(&llvm_cbe_tmp__740);
  _ZN8type_memIhLj512EEC1El(((&llvm_cbe_tmp__743->field0)), 0ull);
  _ZN8type_memIhLj128EEC1El(((&llvm_cbe_tmp__743->field11)), 0ull);
  *((&llvm_cbe_tmp__743->field22)) = 65535ull;
  *((&llvm_cbe_tmp__743->field23)) = 127ull;
  *((&llvm_cbe_tmp__743->field24)) = 255ull;
  return;
}


void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__744;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__745;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__746;
  unsigned long long llvm_cbe_tmp__747;

  *(&llvm_cbe_tmp__744) = llvm_cbe_this;
  *(&llvm_cbe_tmp__745) = llvm_cbe_def;
  llvm_cbe_tmp__746 = *(&llvm_cbe_tmp__744);
  llvm_cbe_tmp__747 = *(&llvm_cbe_tmp__745);
  _ZN8type_memIhLj512EEC2El(llvm_cbe_tmp__746, llvm_cbe_tmp__747);
  return;
}


void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__748;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__749;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__750;
  unsigned long long llvm_cbe_tmp__751;

  *(&llvm_cbe_tmp__748) = llvm_cbe_this;
  *(&llvm_cbe_tmp__749) = llvm_cbe_def;
  llvm_cbe_tmp__750 = *(&llvm_cbe_tmp__748);
  llvm_cbe_tmp__751 = *(&llvm_cbe_tmp__749);
  _ZN8type_memIhLj128EEC2El(llvm_cbe_tmp__750, llvm_cbe_tmp__751);
  return;
}


void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__752;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__753;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__754;
  unsigned char *llvm_cbe_tmp__755;

  *(&llvm_cbe_tmp__752) = llvm_cbe_this;
  *(&llvm_cbe_tmp__753) = llvm_cbe_def;
  llvm_cbe_tmp__754 = *(&llvm_cbe_tmp__752);
  llvm_cbe_tmp__755 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__754->field0)) = llvm_cbe_tmp__755;
  return;
}


void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__756;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__757;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__758;
  unsigned char *llvm_cbe_tmp__759;

  *(&llvm_cbe_tmp__756) = llvm_cbe_this;
  *(&llvm_cbe_tmp__757) = llvm_cbe_def;
  llvm_cbe_tmp__758 = *(&llvm_cbe_tmp__756);
  llvm_cbe_tmp__759 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__758->field0)) = llvm_cbe_tmp__759;
  return;
}


static void _GLOBAL__I_a(void) {
  __cxx_global_var_init();
  __cxx_global_var_init21();
  return;
}

