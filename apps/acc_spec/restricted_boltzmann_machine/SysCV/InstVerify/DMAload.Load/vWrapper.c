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
struct l_class_OC_model_DMAload;
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
typedef struct l_class_OC_model_DMAload l_class_OC_model_DMAload;
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

struct l_class_OC_model_DMAload {
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
extern struct l_class_OC_model_DMAload GM;
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
extern unsigned int rd_complete;
extern struct l_struct_OC_rbm IMPL;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
bool _ZN13model_DMAload9assumps_0Elllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_class_OC_SysCArray1D _ZN13model_DMAload17cppUpdateFun_dataElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIhLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int __gxx_personality_v0(int vararg_dummy_arg,...);
void _Unwind_Resume_or_Rethrow(unsigned char *);
struct l_class_OC_SysCArray1D *_ZN8type_memIhLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZSt9terminatev(void);
unsigned long long _ZN13model_DMAload14cppUpdateFun_iElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_DMAload24cppUpdateFun_rd_completeElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_DMAload23cppUpdateFun_rd_grantedElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_DMAload23cppUpdateFun_rd_requestElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN13model_DMAload6updateElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
static void __cxx_global_var_init(void);
void _ZN13model_DMAloadC1Ev(struct l_class_OC_model_DMAload *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13model_DMAloadD1Ev(struct l_class_OC_model_DMAload *llvm_cbe_this) __ATTRIBUTE_WEAK__;
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
void __CPROVER_assume(bool );
unsigned int *_ZN13sc_signal_u32cvRjEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned char *_ZN11SysCArray2DIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void __CPROVER_assert(bool , unsigned char *);
bool __CPROVER_array_equal(unsigned char *, unsigned char *);
unsigned char *_ZN11SysCArray2DIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
void __CPROVER_array_copy(unsigned char *, unsigned char *);
void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this);
static void __cxx_global_var_init21(void);
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
void _ZN13model_DMAloadD2Ev(struct l_class_OC_model_DMAload *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13model_DMAloadC2Ev(struct l_class_OC_model_DMAload *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
static void _GLOBAL__I_a(void) __ATTRIBUTE_CTOR__;
void abort(void);


/* Global Variable Declarations */
extern struct l_class_OC_model_DMAload GM;
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
extern unsigned int rd_complete;
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
struct l_class_OC_model_DMAload GM;
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
unsigned int rd_complete;
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
static struct l_unnamed9 _OC_str16 = { "rd_complete_match" };
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

bool _ZN13model_DMAload9assumps_0Elllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__1;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_cppVar_242;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_243;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__13;
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
  llvm_cbe_tmp__14 = *((&llvm_cbe_tmp__13->field13));
  *(&llvm_cbe_cppVar_243) = (((unsigned char )(bool )(llvm_cbe_tmp__14 == 1ull)));
  llvm_cbe_tmp__15 = *(&llvm_cbe_cppVar_243);
  return (((((bool )llvm_cbe_tmp__15&1u))&1));
}


struct l_class_OC_SysCArray1D _ZN13model_DMAload17cppUpdateFun_dataElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__16;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_cppVar_230;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_231;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_236;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_237;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_232;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_233;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_234;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_238;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_240;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__28;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__29;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_235;    /* Address-exposed local */
  bool llvm_cbe_tmp__30;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_239;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__31;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__32;
  unsigned long long llvm_cbe_tmp__33;
  unsigned long long llvm_cbe_tmp__34;
  unsigned long long llvm_cbe_tmp__35;
  unsigned long long llvm_cbe_tmp__36;
  unsigned char llvm_cbe_tmp__37;
  unsigned long long llvm_cbe_tmp__38;
  unsigned long long llvm_cbe_tmp__39;
  unsigned long long llvm_cbe_tmp__40;
  unsigned long long llvm_cbe_tmp__41;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__42;
  unsigned long long llvm_cbe_tmp__43;
  unsigned long long llvm_cbe_tmp__44;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__45;
  unsigned long long llvm_cbe_tmp__46;
  unsigned long long llvm_cbe_tmp__47;
  unsigned long long llvm_cbe_tmp__48;
  unsigned long long llvm_cbe_tmp__49;
  unsigned char llvm_cbe_tmp__50;
  unsigned long long llvm_cbe_tmp__51;
  unsigned long long llvm_cbe_tmp__52;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__53;
  unsigned long long llvm_cbe_tmp__54;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__55;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__56;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__57;
  bool llvm_cbe_tmp__58;

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
  llvm_cbe_tmp__32 = *(&llvm_cbe_tmp__16);
  _ZN8type_memIhLj512EEC1Ev((&llvm_cbe_cppVar_234));
  _ZN8type_memIhLj512EEC1Ev((&llvm_cbe_cppVar_240));
  _ZN8type_memIhLj512EEC1Ev((&llvm_cbe_cppVar_235));
  *(&llvm_cbe_tmp__30) = ((0) & 1);
  _ZN8type_memIhLj512EEC1Ev(llvm_cbe_agg_2e_result);
  llvm_cbe_tmp__33 = *((&llvm_cbe_tmp__32->field15));
  llvm_cbe_tmp__34 = *((&llvm_cbe_tmp__32->field21));
  *(&llvm_cbe_cppVar_230) = ((((signed long long )(((signed long long )llvm_cbe_tmp__33) >> ((signed long long )0ull)))) & llvm_cbe_tmp__34);
  llvm_cbe_tmp__35 = *((&llvm_cbe_tmp__32->field3));
  llvm_cbe_tmp__36 = *(&llvm_cbe_cppVar_230);
  *(&llvm_cbe_cppVar_231) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__35) < ((signed long long )llvm_cbe_tmp__36))));
  llvm_cbe_tmp__37 = *(&llvm_cbe_cppVar_231);
  if ((((((bool )llvm_cbe_tmp__37&1u))&1))) {
    goto llvm_cbe_tmp__59;
  } else {
    goto llvm_cbe_tmp__60;
  }

llvm_cbe_tmp__59:
  llvm_cbe_tmp__38 = *((&llvm_cbe_tmp__32->field3));
  llvm_cbe_tmp__39 = *((&llvm_cbe_tmp__32->field23));
  *(&llvm_cbe_cppVar_232) = ((((signed long long )(((signed long long )llvm_cbe_tmp__38) >> ((signed long long )0ull)))) & llvm_cbe_tmp__39);
  llvm_cbe_tmp__40 = *(&llvm_cbe_tmp__24);
  llvm_cbe_tmp__41 = *((&llvm_cbe_tmp__32->field22));
  *(&llvm_cbe_cppVar_233) = ((((signed long long )(((signed long long )llvm_cbe_tmp__40) >> ((signed long long )0ull)))) & llvm_cbe_tmp__41);
  llvm_cbe_tmp__42 = _ZN8type_memIhLj512EEaSERKS0_((&llvm_cbe_cppVar_234), ((&llvm_cbe_tmp__32->field0)));
  llvm_cbe_tmp__43 = *(&llvm_cbe_cppVar_232);
  llvm_cbe_tmp__44 = *(&llvm_cbe_cppVar_233);
  _ZN8type_memIhLj512EE2wrEll((&llvm_cbe_cppVar_234), llvm_cbe_tmp__43, llvm_cbe_tmp__44);
  llvm_cbe_tmp__45 = _ZN8type_memIhLj512EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_234));
  goto llvm_cbe_tmp__61;

llvm_cbe_tmp__60:
  llvm_cbe_tmp__46 = *((&llvm_cbe_tmp__32->field15));
  llvm_cbe_tmp__47 = *((&llvm_cbe_tmp__32->field21));
  *(&llvm_cbe_cppVar_236) = ((((signed long long )(((signed long long )llvm_cbe_tmp__46) >> ((signed long long )0ull)))) & llvm_cbe_tmp__47);
  llvm_cbe_tmp__48 = *((&llvm_cbe_tmp__32->field3));
  llvm_cbe_tmp__49 = *(&llvm_cbe_cppVar_236);
  *(&llvm_cbe_cppVar_237) = (((unsigned char )(bool )(llvm_cbe_tmp__48 == llvm_cbe_tmp__49)));
  llvm_cbe_tmp__50 = *(&llvm_cbe_cppVar_237);
  if ((((((bool )llvm_cbe_tmp__50&1u))&1))) {
    goto llvm_cbe_tmp__62;
  } else {
    goto llvm_cbe_tmp__63;
  }

llvm_cbe_tmp__62:
  llvm_cbe_tmp__51 = *((&llvm_cbe_tmp__32->field15));
  llvm_cbe_tmp__52 = *((&llvm_cbe_tmp__32->field23));
  *(&llvm_cbe_cppVar_238) = ((((signed long long )(((signed long long )llvm_cbe_tmp__51) >> ((signed long long )0ull)))) & llvm_cbe_tmp__52);
  llvm_cbe_tmp__53 = _ZN8type_memIhLj512EEaSERKS0_((&llvm_cbe_cppVar_240), ((&llvm_cbe_tmp__32->field0)));
  llvm_cbe_tmp__54 = *(&llvm_cbe_cppVar_238);
  _ZN8type_memIhLj512EE2wrEll((&llvm_cbe_cppVar_240), llvm_cbe_tmp__54, 1ull);
  llvm_cbe_tmp__55 = _ZN8type_memIhLj512EEaSERKS0_((&llvm_cbe_cppVar_235), (&llvm_cbe_cppVar_240));
  goto llvm_cbe_tmp__64;

llvm_cbe_tmp__63:
  llvm_cbe_tmp__56 = _ZN8type_memIhLj512EEaSERKS0_((&llvm_cbe_cppVar_235), ((&llvm_cbe_tmp__32->field0)));
  goto llvm_cbe_tmp__64;

llvm_cbe_tmp__64:
  llvm_cbe_tmp__57 = _ZN8type_memIhLj512EEaSERKS0_(llvm_cbe_agg_2e_result, (&llvm_cbe_cppVar_235));
  goto llvm_cbe_tmp__61;

llvm_cbe_tmp__61:
  *(&llvm_cbe_tmp__30) = ((1) & 1);
  *(&llvm_cbe_tmp__31) = 1u;
  llvm_cbe_tmp__58 = ((*(&llvm_cbe_tmp__30))&1);
  if (llvm_cbe_tmp__58) {
    goto llvm_cbe_tmp__65;
  } else {
    goto llvm_cbe_tmp__66;
  }

llvm_cbe_tmp__66:
  _ZN8type_memIhLj512EED1Ev(llvm_cbe_agg_2e_result);
  goto llvm_cbe_tmp__65;

llvm_cbe_tmp__65:
  _ZN8type_memIhLj512EED1Ev((&llvm_cbe_cppVar_235));
  _ZN8type_memIhLj512EED1Ev((&llvm_cbe_cppVar_240));
  _ZN8type_memIhLj512EED1Ev((&llvm_cbe_cppVar_234));
  return StructReturn;
}


void _ZN8type_memIhLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__67;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__68;

  *(&llvm_cbe_tmp__67) = llvm_cbe_this;
  llvm_cbe_tmp__68 = *(&llvm_cbe_tmp__67);
  _ZN8type_memIhLj512EEC2Ev(llvm_cbe_tmp__68);
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIhLj512EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__69;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__70;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__71;
  unsigned char *llvm_cbe_tmp__72;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__73;
  unsigned char *llvm_cbe_tmp__74;

  *(&llvm_cbe_tmp__69) = llvm_cbe_this;
  *(&llvm_cbe_tmp__70) = llvm_cbe_r;
  llvm_cbe_tmp__71 = *(&llvm_cbe_tmp__69);
  llvm_cbe_tmp__72 = *((&llvm_cbe_tmp__71->field0));
  llvm_cbe_tmp__73 = *(&llvm_cbe_tmp__70);
  llvm_cbe_tmp__74 = *((&llvm_cbe_tmp__73->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__72, llvm_cbe_tmp__74);
  return llvm_cbe_tmp__71;
}


void _ZN8type_memIhLj512EE2wrEll(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_addr, unsigned long long llvm_cbe_data) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__75;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__76;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__77;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__78;
  unsigned long long llvm_cbe_tmp__79;
  unsigned long long llvm_cbe_tmp__80;
  unsigned char *llvm_cbe_tmp__81;

  *(&llvm_cbe_tmp__75) = llvm_cbe_this;
  *(&llvm_cbe_tmp__76) = llvm_cbe_addr;
  *(&llvm_cbe_tmp__77) = llvm_cbe_data;
  llvm_cbe_tmp__78 = *(&llvm_cbe_tmp__75);
  llvm_cbe_tmp__79 = *(&llvm_cbe_tmp__77);
  llvm_cbe_tmp__80 = *(&llvm_cbe_tmp__76);
  llvm_cbe_tmp__81 = *((&llvm_cbe_tmp__78->field0));
  *((&llvm_cbe_tmp__81[((signed long long )llvm_cbe_tmp__80)])) = (((unsigned char )llvm_cbe_tmp__79));
  return;
}


void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__82;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__83;

  *(&llvm_cbe_tmp__82) = llvm_cbe_this;
  llvm_cbe_tmp__83 = *(&llvm_cbe_tmp__82);
  _ZN8type_memIhLj512EED2Ev(llvm_cbe_tmp__83);
  return;
}


unsigned long long _ZN13model_DMAload14cppUpdateFun_iElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__84;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__85;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__86;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__87;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__88;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__89;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__90;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__91;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__92;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__93;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__94;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__95;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_211;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_212;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_213;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_214;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_210;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__96;
  unsigned long long llvm_cbe_tmp__97;
  unsigned long long llvm_cbe_tmp__98;
  unsigned long long llvm_cbe_tmp__99;
  unsigned long long llvm_cbe_tmp__100;
  unsigned char llvm_cbe_tmp__101;
  unsigned long long llvm_cbe_tmp__102;
  unsigned long long llvm_cbe_tmp__103;
  unsigned long long llvm_cbe_tmp__104;
  unsigned long long llvm_cbe_tmp__105;
  unsigned long long llvm_cbe_tmp__106;

  *(&llvm_cbe_tmp__84) = llvm_cbe_this;
  *(&llvm_cbe_tmp__85) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__86) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__87) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__88) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__89) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__90) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__91) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__92) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__93) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__94) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__95) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__96 = *(&llvm_cbe_tmp__84);
  llvm_cbe_tmp__97 = *((&llvm_cbe_tmp__96->field15));
  llvm_cbe_tmp__98 = *((&llvm_cbe_tmp__96->field21));
  *(&llvm_cbe_cppVar_211) = ((((signed long long )(((signed long long )llvm_cbe_tmp__97) >> ((signed long long )0ull)))) & llvm_cbe_tmp__98);
  llvm_cbe_tmp__99 = *((&llvm_cbe_tmp__96->field3));
  llvm_cbe_tmp__100 = *(&llvm_cbe_cppVar_211);
  *(&llvm_cbe_cppVar_212) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__99) < ((signed long long )llvm_cbe_tmp__100))));
  llvm_cbe_tmp__101 = *(&llvm_cbe_cppVar_212);
  llvm_cbe_tmp__102 = *((&llvm_cbe_tmp__96->field3));
  if ((((((bool )llvm_cbe_tmp__101&1u))&1))) {
    goto llvm_cbe_tmp__107;
  } else {
    goto llvm_cbe_tmp__108;
  }

llvm_cbe_tmp__107:
  *(&llvm_cbe_cppVar_214) = (((unsigned long long )(((unsigned long long )llvm_cbe_tmp__102) + ((unsigned long long )1ull))));
  llvm_cbe_tmp__103 = *(&llvm_cbe_cppVar_214);
  llvm_cbe_tmp__104 = *((&llvm_cbe_tmp__96->field21));
  *(&llvm_cbe_cppVar_214) = (llvm_cbe_tmp__103 & llvm_cbe_tmp__104);
  llvm_cbe_tmp__105 = *(&llvm_cbe_cppVar_214);
  *(&llvm_cbe_cppVar_210) = llvm_cbe_tmp__105;
  goto llvm_cbe_tmp__109;

llvm_cbe_tmp__108:
  *(&llvm_cbe_cppVar_210) = llvm_cbe_tmp__102;
  goto llvm_cbe_tmp__109;

llvm_cbe_tmp__109:
  llvm_cbe_tmp__106 = *(&llvm_cbe_cppVar_210);
  return llvm_cbe_tmp__106;
}


unsigned long long _ZN13model_DMAload24cppUpdateFun_rd_completeElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__110;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__111;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__112;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__113;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__114;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__115;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__116;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__117;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__118;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__119;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__120;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__121;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_217;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_218;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_216;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_219;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_220;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__122;
  unsigned long long llvm_cbe_tmp__123;
  unsigned long long llvm_cbe_tmp__124;
  unsigned long long llvm_cbe_tmp__125;
  unsigned long long llvm_cbe_tmp__126;
  unsigned char llvm_cbe_tmp__127;
  unsigned long long llvm_cbe_tmp__128;

  *(&llvm_cbe_tmp__110) = llvm_cbe_this;
  *(&llvm_cbe_tmp__111) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__112) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__113) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__114) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__115) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__116) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__117) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__118) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__119) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__120) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__121) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__122 = *(&llvm_cbe_tmp__110);
  llvm_cbe_tmp__123 = *((&llvm_cbe_tmp__122->field15));
  llvm_cbe_tmp__124 = *((&llvm_cbe_tmp__122->field21));
  *(&llvm_cbe_cppVar_217) = ((((signed long long )(((signed long long )llvm_cbe_tmp__123) >> ((signed long long )0ull)))) & llvm_cbe_tmp__124);
  llvm_cbe_tmp__125 = *((&llvm_cbe_tmp__122->field3));
  llvm_cbe_tmp__126 = *(&llvm_cbe_cppVar_217);
  *(&llvm_cbe_cppVar_218) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__125) < ((signed long long )llvm_cbe_tmp__126))));
  llvm_cbe_tmp__127 = *(&llvm_cbe_cppVar_218);
  if ((((((bool )llvm_cbe_tmp__127&1u))&1))) {
    goto llvm_cbe_tmp__129;
  } else {
    goto llvm_cbe_tmp__130;
  }

llvm_cbe_tmp__129:
  *(&llvm_cbe_cppVar_216) = 0ull;
  goto llvm_cbe_tmp__131;

llvm_cbe_tmp__130:
  *(&llvm_cbe_cppVar_216) = 1ull;
  goto llvm_cbe_tmp__131;

llvm_cbe_tmp__131:
  llvm_cbe_tmp__128 = *(&llvm_cbe_cppVar_216);
  return llvm_cbe_tmp__128;
}


unsigned long long _ZN13model_DMAload23cppUpdateFun_rd_grantedElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__132;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__133;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__134;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__135;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__136;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__137;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__138;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__139;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__140;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__141;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__142;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__143;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_223;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_224;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_222;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_225;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__144;
  unsigned long long llvm_cbe_tmp__145;
  unsigned long long llvm_cbe_tmp__146;
  unsigned long long llvm_cbe_tmp__147;
  unsigned long long llvm_cbe_tmp__148;
  unsigned char llvm_cbe_tmp__149;
  unsigned long long llvm_cbe_tmp__150;
  unsigned long long llvm_cbe_tmp__151;

  *(&llvm_cbe_tmp__132) = llvm_cbe_this;
  *(&llvm_cbe_tmp__133) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__134) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__135) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__136) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__137) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__138) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__139) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__140) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__141) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__142) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__143) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__144 = *(&llvm_cbe_tmp__132);
  llvm_cbe_tmp__145 = *((&llvm_cbe_tmp__144->field15));
  llvm_cbe_tmp__146 = *((&llvm_cbe_tmp__144->field21));
  *(&llvm_cbe_cppVar_223) = ((((signed long long )(((signed long long )llvm_cbe_tmp__145) >> ((signed long long )0ull)))) & llvm_cbe_tmp__146);
  llvm_cbe_tmp__147 = *((&llvm_cbe_tmp__144->field3));
  llvm_cbe_tmp__148 = *(&llvm_cbe_cppVar_223);
  *(&llvm_cbe_cppVar_224) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__147) < ((signed long long )llvm_cbe_tmp__148))));
  llvm_cbe_tmp__149 = *(&llvm_cbe_cppVar_224);
  if ((((((bool )llvm_cbe_tmp__149&1u))&1))) {
    goto llvm_cbe_tmp__152;
  } else {
    goto llvm_cbe_tmp__153;
  }

llvm_cbe_tmp__152:
  llvm_cbe_tmp__150 = *((&llvm_cbe_tmp__144->field13));
  *(&llvm_cbe_cppVar_222) = llvm_cbe_tmp__150;
  goto llvm_cbe_tmp__154;

llvm_cbe_tmp__153:
  *(&llvm_cbe_cppVar_222) = 0ull;
  goto llvm_cbe_tmp__154;

llvm_cbe_tmp__154:
  llvm_cbe_tmp__151 = *(&llvm_cbe_cppVar_222);
  return llvm_cbe_tmp__151;
}


unsigned long long _ZN13model_DMAload23cppUpdateFun_rd_requestElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__155;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__156;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__157;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__158;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__159;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__160;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__161;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__162;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__163;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__164;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__165;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__166;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_227;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__167;

  *(&llvm_cbe_tmp__155) = llvm_cbe_this;
  *(&llvm_cbe_tmp__156) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__157) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__158) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__159) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__160) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__161) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__162) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__163) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__164) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__165) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__166) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__167 = *(&llvm_cbe_tmp__155);
  return 0ull;
}


void _ZN13model_DMAload6updateElllllllllll(struct l_class_OC_model_DMAload *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__168;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__169;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__170;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__171;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__172;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__173;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__174;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__175;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__176;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__177;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__178;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__179;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_215;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_221;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_226;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_228;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_241;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__180;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__181;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__182;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__183;
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
  unsigned long long llvm_cbe_tmp__206;
  unsigned long long llvm_cbe_tmp__207;
  unsigned long long llvm_cbe_tmp__208;
  unsigned long long llvm_cbe_tmp__209;
  unsigned long long llvm_cbe_tmp__210;
  unsigned long long llvm_cbe_tmp__211;
  unsigned long long llvm_cbe_tmp__212;
  unsigned long long llvm_cbe_tmp__213;
  unsigned long long llvm_cbe_tmp__214;
  unsigned long long llvm_cbe_tmp__215;
  unsigned long long llvm_cbe_tmp__216;
  unsigned long long llvm_cbe_tmp__217;
  unsigned long long llvm_cbe_tmp__218;
  unsigned long long llvm_cbe_tmp__219;
  unsigned long long llvm_cbe_tmp__220;
  unsigned long long llvm_cbe_tmp__221;
  unsigned long long llvm_cbe_tmp__222;
  unsigned long long llvm_cbe_tmp__223;
  unsigned long long llvm_cbe_tmp__224;
  unsigned long long llvm_cbe_tmp__225;
  unsigned long long llvm_cbe_tmp__226;
  unsigned long long llvm_cbe_tmp__227;
  unsigned long long llvm_cbe_tmp__228;
  unsigned long long llvm_cbe_tmp__229;
  unsigned long long llvm_cbe_tmp__230;
  unsigned long long llvm_cbe_tmp__231;
  unsigned long long llvm_cbe_tmp__232;
  unsigned long long llvm_cbe_tmp__233;
  unsigned long long llvm_cbe_tmp__234;
  unsigned long long llvm_cbe_tmp__235;
  unsigned long long llvm_cbe_tmp__236;
  unsigned long long llvm_cbe_tmp__237;
  unsigned long long llvm_cbe_tmp__238;
  unsigned long long llvm_cbe_tmp__239;
  unsigned long long llvm_cbe_tmp__240;
  unsigned long long llvm_cbe_tmp__241;
  unsigned long long llvm_cbe_tmp__242;
  unsigned long long llvm_cbe_tmp__243;
  unsigned long long llvm_cbe_tmp__244;
  unsigned long long llvm_cbe_tmp__245;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__246;

  *(&llvm_cbe_tmp__168) = llvm_cbe_this;
  *(&llvm_cbe_tmp__169) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__170) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__171) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__172) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__173) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__174) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__175) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__176) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__177) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__178) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__179) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__183 = *(&llvm_cbe_tmp__168);
  llvm_cbe_tmp__184 = *(&llvm_cbe_tmp__169);
  llvm_cbe_tmp__185 = *(&llvm_cbe_tmp__170);
  llvm_cbe_tmp__186 = *(&llvm_cbe_tmp__171);
  llvm_cbe_tmp__187 = *(&llvm_cbe_tmp__172);
  llvm_cbe_tmp__188 = *(&llvm_cbe_tmp__173);
  llvm_cbe_tmp__189 = *(&llvm_cbe_tmp__174);
  llvm_cbe_tmp__190 = *(&llvm_cbe_tmp__175);
  llvm_cbe_tmp__191 = *(&llvm_cbe_tmp__176);
  llvm_cbe_tmp__192 = *(&llvm_cbe_tmp__177);
  llvm_cbe_tmp__193 = *(&llvm_cbe_tmp__178);
  llvm_cbe_tmp__194 = *(&llvm_cbe_tmp__179);
  llvm_cbe_tmp__195 = _ZN13model_DMAload14cppUpdateFun_iElllllllllll(llvm_cbe_tmp__183, llvm_cbe_tmp__184, llvm_cbe_tmp__185, llvm_cbe_tmp__186, llvm_cbe_tmp__187, llvm_cbe_tmp__188, llvm_cbe_tmp__189, llvm_cbe_tmp__190, llvm_cbe_tmp__191, llvm_cbe_tmp__192, llvm_cbe_tmp__193, llvm_cbe_tmp__194);
  *(&llvm_cbe_cppVar_215) = llvm_cbe_tmp__195;
  llvm_cbe_tmp__196 = *(&llvm_cbe_tmp__169);
  llvm_cbe_tmp__197 = *(&llvm_cbe_tmp__170);
  llvm_cbe_tmp__198 = *(&llvm_cbe_tmp__171);
  llvm_cbe_tmp__199 = *(&llvm_cbe_tmp__172);
  llvm_cbe_tmp__200 = *(&llvm_cbe_tmp__173);
  llvm_cbe_tmp__201 = *(&llvm_cbe_tmp__174);
  llvm_cbe_tmp__202 = *(&llvm_cbe_tmp__175);
  llvm_cbe_tmp__203 = *(&llvm_cbe_tmp__176);
  llvm_cbe_tmp__204 = *(&llvm_cbe_tmp__177);
  llvm_cbe_tmp__205 = *(&llvm_cbe_tmp__178);
  llvm_cbe_tmp__206 = *(&llvm_cbe_tmp__179);
  llvm_cbe_tmp__207 = _ZN13model_DMAload24cppUpdateFun_rd_completeElllllllllll(llvm_cbe_tmp__183, llvm_cbe_tmp__196, llvm_cbe_tmp__197, llvm_cbe_tmp__198, llvm_cbe_tmp__199, llvm_cbe_tmp__200, llvm_cbe_tmp__201, llvm_cbe_tmp__202, llvm_cbe_tmp__203, llvm_cbe_tmp__204, llvm_cbe_tmp__205, llvm_cbe_tmp__206);
  *(&llvm_cbe_cppVar_221) = llvm_cbe_tmp__207;
  llvm_cbe_tmp__208 = *(&llvm_cbe_tmp__169);
  llvm_cbe_tmp__209 = *(&llvm_cbe_tmp__170);
  llvm_cbe_tmp__210 = *(&llvm_cbe_tmp__171);
  llvm_cbe_tmp__211 = *(&llvm_cbe_tmp__172);
  llvm_cbe_tmp__212 = *(&llvm_cbe_tmp__173);
  llvm_cbe_tmp__213 = *(&llvm_cbe_tmp__174);
  llvm_cbe_tmp__214 = *(&llvm_cbe_tmp__175);
  llvm_cbe_tmp__215 = *(&llvm_cbe_tmp__176);
  llvm_cbe_tmp__216 = *(&llvm_cbe_tmp__177);
  llvm_cbe_tmp__217 = *(&llvm_cbe_tmp__178);
  llvm_cbe_tmp__218 = *(&llvm_cbe_tmp__179);
  llvm_cbe_tmp__219 = _ZN13model_DMAload23cppUpdateFun_rd_grantedElllllllllll(llvm_cbe_tmp__183, llvm_cbe_tmp__208, llvm_cbe_tmp__209, llvm_cbe_tmp__210, llvm_cbe_tmp__211, llvm_cbe_tmp__212, llvm_cbe_tmp__213, llvm_cbe_tmp__214, llvm_cbe_tmp__215, llvm_cbe_tmp__216, llvm_cbe_tmp__217, llvm_cbe_tmp__218);
  *(&llvm_cbe_cppVar_226) = llvm_cbe_tmp__219;
  llvm_cbe_tmp__220 = *(&llvm_cbe_tmp__169);
  llvm_cbe_tmp__221 = *(&llvm_cbe_tmp__170);
  llvm_cbe_tmp__222 = *(&llvm_cbe_tmp__171);
  llvm_cbe_tmp__223 = *(&llvm_cbe_tmp__172);
  llvm_cbe_tmp__224 = *(&llvm_cbe_tmp__173);
  llvm_cbe_tmp__225 = *(&llvm_cbe_tmp__174);
  llvm_cbe_tmp__226 = *(&llvm_cbe_tmp__175);
  llvm_cbe_tmp__227 = *(&llvm_cbe_tmp__176);
  llvm_cbe_tmp__228 = *(&llvm_cbe_tmp__177);
  llvm_cbe_tmp__229 = *(&llvm_cbe_tmp__178);
  llvm_cbe_tmp__230 = *(&llvm_cbe_tmp__179);
  llvm_cbe_tmp__231 = _ZN13model_DMAload23cppUpdateFun_rd_requestElllllllllll(llvm_cbe_tmp__183, llvm_cbe_tmp__220, llvm_cbe_tmp__221, llvm_cbe_tmp__222, llvm_cbe_tmp__223, llvm_cbe_tmp__224, llvm_cbe_tmp__225, llvm_cbe_tmp__226, llvm_cbe_tmp__227, llvm_cbe_tmp__228, llvm_cbe_tmp__229, llvm_cbe_tmp__230);
  *(&llvm_cbe_cppVar_228) = llvm_cbe_tmp__231;
  llvm_cbe_tmp__232 = *(&llvm_cbe_tmp__169);
  llvm_cbe_tmp__233 = *(&llvm_cbe_tmp__170);
  llvm_cbe_tmp__234 = *(&llvm_cbe_tmp__171);
  llvm_cbe_tmp__235 = *(&llvm_cbe_tmp__172);
  llvm_cbe_tmp__236 = *(&llvm_cbe_tmp__173);
  llvm_cbe_tmp__237 = *(&llvm_cbe_tmp__174);
  llvm_cbe_tmp__238 = *(&llvm_cbe_tmp__175);
  llvm_cbe_tmp__239 = *(&llvm_cbe_tmp__176);
  llvm_cbe_tmp__240 = *(&llvm_cbe_tmp__177);
  llvm_cbe_tmp__241 = *(&llvm_cbe_tmp__178);
  llvm_cbe_tmp__242 = *(&llvm_cbe_tmp__179);
  llvm_cbe_cppVar_241 = _ZN13model_DMAload17cppUpdateFun_dataElllllllllll(llvm_cbe_tmp__183, llvm_cbe_tmp__232, llvm_cbe_tmp__233, llvm_cbe_tmp__234, llvm_cbe_tmp__235, llvm_cbe_tmp__236, llvm_cbe_tmp__237, llvm_cbe_tmp__238, llvm_cbe_tmp__239, llvm_cbe_tmp__240, llvm_cbe_tmp__241, llvm_cbe_tmp__242);
  llvm_cbe_tmp__243 = *(&llvm_cbe_cppVar_215);
  *((&llvm_cbe_tmp__183->field3)) = llvm_cbe_tmp__243;
  llvm_cbe_tmp__244 = *(&llvm_cbe_cppVar_221);
  *((&llvm_cbe_tmp__183->field12)) = llvm_cbe_tmp__244;
  llvm_cbe_tmp__245 = *(&llvm_cbe_cppVar_226);
  *((&llvm_cbe_tmp__183->field13)) = llvm_cbe_tmp__245;
  *((&llvm_cbe_tmp__183->field16)) = 0ull;
  llvm_cbe_tmp__246 = _ZN8type_memIhLj512EEaSERKS0_(((&llvm_cbe_tmp__183->field0)), (&llvm_cbe_cppVar_241));
  *(&llvm_cbe_tmp__182) = 1u;
  _ZN8type_memIhLj512EED1Ev((&llvm_cbe_cppVar_241));
  return;
}


static void __cxx_global_var_init(void) {
  unsigned int llvm_cbe_tmp__247;

  _ZN13model_DMAloadC1Ev((&GM));
  llvm_cbe_tmp__247 = __cxa_atexit(((void  (*) (unsigned char *))_ZN13model_DMAloadD1Ev), ((unsigned char *)(&GM)), ((unsigned char *)(&__dso_handle)));
  return;
}


void _ZN13model_DMAloadC1Ev(struct l_class_OC_model_DMAload *llvm_cbe_this) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__248;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__249;

  *(&llvm_cbe_tmp__248) = llvm_cbe_this;
  llvm_cbe_tmp__249 = *(&llvm_cbe_tmp__248);
  _ZN13model_DMAloadC2Ev(llvm_cbe_tmp__249);
  return;
}


void _ZN13model_DMAloadD1Ev(struct l_class_OC_model_DMAload *llvm_cbe_this) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__250;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__251;

  *(&llvm_cbe_tmp__250) = llvm_cbe_this;
  llvm_cbe_tmp__251 = *(&llvm_cbe_tmp__250);
  _ZN13model_DMAloadD2Ev(llvm_cbe_tmp__251);
  return;
}


void _Z4waitv(void) {
  unsigned int llvm_cbe_tmp__252;

  llvm_cbe_tmp__252 = *(&cycleCnt);
  *(&cycleCnt) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__252) + ((unsigned int )1u))));
  return;
}


void _Z15reset_signal_isib(unsigned int llvm_cbe_tmp__253, bool llvm_cbe_tmp__254) {
  unsigned int llvm_cbe_tmp__255;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__256;    /* Address-exposed local */

  *(&llvm_cbe_tmp__255) = llvm_cbe_tmp__253;
  *(&llvm_cbe_tmp__256) = (((unsigned char )(bool )llvm_cbe_tmp__254));
  return;
}


void _Z14set_stack_sizei(unsigned int llvm_cbe_tmp__257) {
  unsigned int llvm_cbe_tmp__258;    /* Address-exposed local */

  *(&llvm_cbe_tmp__258) = llvm_cbe_tmp__257;
  return;
}


void _ZN3rbm6configEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__259;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__260;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__261;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__262;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__263;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__264;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__265;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__266;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__267;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__268;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__269;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__270;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__271;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__272;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__273;
  bool llvm_cbe_tmp__274;
  unsigned int llvm_cbe_tmp__275;
  unsigned int llvm_cbe_tmp__276;
  unsigned int llvm_cbe_tmp__277;
  unsigned int llvm_cbe_tmp__278;
  unsigned int llvm_cbe_tmp__279;
  unsigned int llvm_cbe_tmp__280;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__281;
  unsigned int llvm_cbe_tmp__282;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__283;

  *(&llvm_cbe_tmp__259) = llvm_cbe_this;
  llvm_cbe_tmp__273 = *(&llvm_cbe_tmp__259);
  *(&llvm_cbe_tmp__260) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field30)), (&llvm_cbe_tmp__260));
  *(&llvm_cbe_tmp__261) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field31)), (&llvm_cbe_tmp__261));
  *(&llvm_cbe_tmp__262) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field32)), (&llvm_cbe_tmp__262));
  *(&llvm_cbe_tmp__263) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field33)), (&llvm_cbe_tmp__263));
  *(&llvm_cbe_tmp__264) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field35)), (&llvm_cbe_tmp__264));
  *(&llvm_cbe_tmp__265) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__273->field36)), (&llvm_cbe_tmp__265));
  _Z4waitv();
  goto llvm_cbe_tmp__284;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__284:
  _Z4waitv();
  llvm_cbe_tmp__274 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__273->field13))))&1);
  if ((((llvm_cbe_tmp__274 ^ 1)&1))) {
    goto llvm_cbe_tmp__284;
  } else {
    goto llvm_cbe_tmp__285;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__285:
  llvm_cbe_tmp__275 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__273->field14)));
  *(&llvm_cbe_tmp__266) = (((unsigned short )llvm_cbe_tmp__275));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field30)), (&llvm_cbe_tmp__266));
  llvm_cbe_tmp__276 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__273->field15)));
  *(&llvm_cbe_tmp__267) = (((unsigned short )llvm_cbe_tmp__276));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field31)), (&llvm_cbe_tmp__267));
  llvm_cbe_tmp__277 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__273->field16)));
  *(&llvm_cbe_tmp__268) = (((unsigned short )llvm_cbe_tmp__277));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field32)), (&llvm_cbe_tmp__268));
  llvm_cbe_tmp__278 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__273->field17)));
  *(&llvm_cbe_tmp__269) = (((unsigned short )llvm_cbe_tmp__278));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field33)), (&llvm_cbe_tmp__269));
  llvm_cbe_tmp__279 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__273->field18)));
  *(&llvm_cbe_tmp__270) = (((unsigned short )llvm_cbe_tmp__279));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field34)), (&llvm_cbe_tmp__270));
  llvm_cbe_tmp__280 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__273->field19)));
  *(&llvm_cbe_tmp__271) = (((unsigned short )llvm_cbe_tmp__280));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__273->field35)), (&llvm_cbe_tmp__271));
  llvm_cbe_tmp__281 = _ZNSt6iocoutlsEPKc((&_ZSt4cout), ((&_OC_str.array[((signed int )0u)])));
  llvm_cbe_tmp__282 = *(&_ZSt4endl);
  llvm_cbe_tmp__283 = _ZNSt6iocoutlsEi(llvm_cbe_tmp__281, llvm_cbe_tmp__282);
  *(&llvm_cbe_tmp__272) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__273->field36)), (&llvm_cbe_tmp__272));
  goto llvm_cbe_tmp__286;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__286:
  _Z4waitv();
  goto llvm_cbe_tmp__286;

  } while (1); /* end of syntactic loop '' */
}


void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__287;    /* Address-exposed local */
  unsigned short *llvm_cbe_tmp__288;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__289;
  unsigned short *llvm_cbe_tmp__290;
  unsigned short llvm_cbe_tmp__291;

  *(&llvm_cbe_tmp__287) = llvm_cbe_this;
  *(&llvm_cbe_tmp__288) = llvm_cbe_d;
  llvm_cbe_tmp__289 = *(&llvm_cbe_tmp__287);
  llvm_cbe_tmp__290 = *(&llvm_cbe_tmp__288);
  llvm_cbe_tmp__291 = *llvm_cbe_tmp__290;
  *((&llvm_cbe_tmp__289->field0)) = llvm_cbe_tmp__291;
  return;
}


void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__292;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__293;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__294;
  unsigned char *llvm_cbe_tmp__295;
  unsigned char llvm_cbe_tmp__296;

  *(&llvm_cbe_tmp__292) = llvm_cbe_this;
  *(&llvm_cbe_tmp__293) = llvm_cbe_d;
  llvm_cbe_tmp__294 = *(&llvm_cbe_tmp__292);
  llvm_cbe_tmp__295 = *(&llvm_cbe_tmp__293);
  llvm_cbe_tmp__296 = *llvm_cbe_tmp__295;
  *((&llvm_cbe_tmp__294->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__296&1u))&1))));
  return;
}


bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__297;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__298;
  unsigned char llvm_cbe_tmp__299;

  *(&llvm_cbe_tmp__297) = llvm_cbe_this;
  llvm_cbe_tmp__298 = *(&llvm_cbe_tmp__297);
  llvm_cbe_tmp__299 = *((&llvm_cbe_tmp__298->field0));
  return (((((bool )llvm_cbe_tmp__299&1u))&1));
}


unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__300;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__301;
  unsigned int llvm_cbe_tmp__302;

  *(&llvm_cbe_tmp__300) = llvm_cbe_this;
  llvm_cbe_tmp__301 = *(&llvm_cbe_tmp__300);
  llvm_cbe_tmp__302 = *((&llvm_cbe_tmp__301->field0));
  return llvm_cbe_tmp__302;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_tmp__303) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__304;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__305;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__306;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__307;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__308;

  *(&llvm_cbe_tmp__305) = llvm_cbe_this;
  *(&llvm_cbe_tmp__306) = llvm_cbe_tmp__303;
  llvm_cbe_tmp__307 = *(&llvm_cbe_tmp__305);
  llvm_cbe_tmp__308 = *(&llvm_cbe_tmp__304);
  return llvm_cbe_tmp__308;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEi(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned int llvm_cbe_tmp__309) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__310;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__311;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__312;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__313;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__314;

  *(&llvm_cbe_tmp__311) = llvm_cbe_this;
  *(&llvm_cbe_tmp__312) = llvm_cbe_tmp__309;
  llvm_cbe_tmp__313 = *(&llvm_cbe_tmp__311);
  llvm_cbe_tmp__314 = *(&llvm_cbe_tmp__310);
  return llvm_cbe_tmp__314;
}


void _ZN3rbm4loadEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__315;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__316;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__317;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__318;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__319;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__320;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__321;    /* Address-exposed local */
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
  unsigned int llvm_cbe_tmp__322;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__323;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned char llvm_cbe_rate;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__324;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__325;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__326;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__327;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__328;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__329;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__330;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__331;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__332;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__333;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__334;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__335;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__336;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__337;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__338;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__339;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__340;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__341;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__342;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__343;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__344;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__345;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__346;    /* Address-exposed local */
  unsigned short llvm_cbe_i1;    /* Address-exposed local */
  unsigned char llvm_cbe_rate2;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__347;
  bool llvm_cbe_tmp__348;
  bool llvm_cbe_tmp__349;
  unsigned int llvm_cbe_tmp__350;
  unsigned int llvm_cbe_tmp__351;
  unsigned int llvm_cbe_tmp__352;
  unsigned int llvm_cbe_tmp__353;
  unsigned int llvm_cbe_tmp__354;
  unsigned int llvm_cbe_tmp__355;
  unsigned short llvm_cbe_tmp__356;
  unsigned short llvm_cbe_tmp__357;
  unsigned short llvm_cbe_tmp__358;
  unsigned short llvm_cbe_tmp__359;
  unsigned short llvm_cbe_tmp__360;
  unsigned int llvm_cbe_tmp__361;
  unsigned int *llvm_cbe_tmp__362;
  unsigned int llvm_cbe_tmp__363;
  unsigned short llvm_cbe_tmp__364;
  unsigned int llvm_cbe_tmp__365;
  bool llvm_cbe_tmp__366;
  unsigned char llvm_cbe_tmp__367;
  unsigned int llvm_cbe_tmp__368;
  unsigned int llvm_cbe_tmp__369;
  unsigned int llvm_cbe_tmp__370;
  unsigned int llvm_cbe_tmp__371;
  unsigned int llvm_cbe_tmp__372;
  unsigned int llvm_cbe_tmp__373;
  unsigned char llvm_cbe_tmp__374;
  unsigned long long llvm_cbe_tmp__375;
  unsigned long long llvm_cbe_tmp__376;
  unsigned long long llvm_cbe_tmp__377;
  unsigned long long llvm_cbe_tmp__378;
  unsigned long long llvm_cbe_tmp__379;
  unsigned long long llvm_cbe_tmp__380;
  unsigned long long llvm_cbe_tmp__381;
  unsigned long long llvm_cbe_tmp__382;
  unsigned long long llvm_cbe_tmp__383;
  unsigned long long llvm_cbe_tmp__384;
  unsigned long long llvm_cbe_tmp__385;
  unsigned char llvm_cbe_tmp__386;
  unsigned int llvm_cbe_tmp__387;
  unsigned char llvm_cbe_tmp__388;
  unsigned long long llvm_cbe_tmp__389;
  unsigned long long llvm_cbe_tmp__390;
  unsigned long long llvm_cbe_tmp__391;
  unsigned long long llvm_cbe_tmp__392;
  unsigned long long llvm_cbe_tmp__393;
  unsigned char *llvm_cbe_tmp__394;
  unsigned char *llvm_cbe_tmp__395;
  unsigned char *llvm_cbe_tmp__396;
  unsigned char *llvm_cbe_tmp__397;
  unsigned short llvm_cbe_tmp__398;
  unsigned int llvm_cbe_tmp__399;
  unsigned short llvm_cbe_tmp__400;
  unsigned short llvm_cbe_tmp__401;
  unsigned short llvm_cbe_tmp__402;
  unsigned int llvm_cbe_tmp__403;
  unsigned int llvm_cbe_tmp__404;
  unsigned char llvm_cbe_tmp__405;
  unsigned short llvm_cbe_tmp__406;
  unsigned char llvm_cbe_tmp__407;
  unsigned char *llvm_cbe_tmp__408;
  unsigned char llvm_cbe_tmp__409;
  unsigned int llvm_cbe_tmp__410;
  unsigned int llvm_cbe_tmp__411;
  unsigned int llvm_cbe_tmp__412;
  unsigned int llvm_cbe_tmp__413;
  unsigned int llvm_cbe_tmp__414;
  unsigned int llvm_cbe_tmp__415;
  unsigned char llvm_cbe_tmp__416;
  unsigned char llvm_cbe_tmp__417;
  unsigned int llvm_cbe_tmp__418;
  unsigned char llvm_cbe_tmp__419;
  bool llvm_cbe_tmp__420;
  unsigned long long llvm_cbe_tmp__421;
  bool llvm_cbe_tmp__422;
  unsigned long long llvm_cbe_tmp__423;
  unsigned short llvm_cbe_tmp__424;
  unsigned long long llvm_cbe_tmp__425;
  unsigned short llvm_cbe_tmp__426;
  unsigned long long llvm_cbe_tmp__427;
  unsigned short llvm_cbe_tmp__428;
  unsigned long long llvm_cbe_tmp__429;
  unsigned short llvm_cbe_tmp__430;
  unsigned long long llvm_cbe_tmp__431;
  unsigned short llvm_cbe_tmp__432;
  unsigned long long llvm_cbe_tmp__433;
  unsigned short llvm_cbe_tmp__434;
  unsigned long long llvm_cbe_tmp__435;
  unsigned int llvm_cbe_tmp__436;
  unsigned long long llvm_cbe_tmp__437;
  unsigned int llvm_cbe_tmp__438;
  unsigned long long llvm_cbe_tmp__439;
  bool llvm_cbe_tmp__440;
  unsigned long long llvm_cbe_tmp__441;
  bool llvm_cbe_tmp__442;
  unsigned long long llvm_cbe_tmp__443;
  unsigned int llvm_cbe_tmp__444;
  unsigned long long llvm_cbe_tmp__445;
  unsigned int llvm_cbe_tmp__446;
  unsigned long long llvm_cbe_tmp__447;
  unsigned int llvm_cbe_tmp__448;
  unsigned long long llvm_cbe_tmp__449;
  unsigned int llvm_cbe_tmp__450;
  unsigned long long llvm_cbe_tmp__451;
  unsigned short llvm_cbe_tmp__452;
  unsigned long long llvm_cbe_tmp__453;
  unsigned char *llvm_cbe_tmp__454;
  unsigned char *llvm_cbe_tmp__455;
  bool llvm_cbe_tmp__456;
  unsigned char *llvm_cbe_tmp__457;
  unsigned char *llvm_cbe_tmp__458;
  bool llvm_cbe_tmp__459;
  unsigned short llvm_cbe_tmp__460;
  unsigned int llvm_cbe_tmp__461;
  unsigned int llvm_cbe_tmp__462;
  unsigned char llvm_cbe_tmp__463;
  unsigned char *llvm_cbe_tmp__464;
  unsigned char llvm_cbe_tmp__465;
  unsigned int llvm_cbe_tmp__466;
  unsigned int llvm_cbe_tmp__467;
  unsigned int llvm_cbe_tmp__468;
  unsigned int llvm_cbe_tmp__469;
  unsigned int llvm_cbe_tmp__470;
  unsigned int llvm_cbe_tmp__471;
  unsigned char llvm_cbe_tmp__472;
  unsigned char llvm_cbe_tmp__473;
  unsigned int llvm_cbe_tmp__474;
  unsigned char llvm_cbe_tmp__475;
  bool llvm_cbe_tmp__476;
  unsigned long long llvm_cbe_tmp__477;
  bool llvm_cbe_tmp__478;
  unsigned long long llvm_cbe_tmp__479;
  unsigned short llvm_cbe_tmp__480;
  unsigned long long llvm_cbe_tmp__481;
  unsigned short llvm_cbe_tmp__482;
  unsigned long long llvm_cbe_tmp__483;
  unsigned short llvm_cbe_tmp__484;
  unsigned long long llvm_cbe_tmp__485;
  unsigned short llvm_cbe_tmp__486;
  unsigned long long llvm_cbe_tmp__487;
  unsigned short llvm_cbe_tmp__488;
  unsigned long long llvm_cbe_tmp__489;
  unsigned short llvm_cbe_tmp__490;
  unsigned long long llvm_cbe_tmp__491;
  unsigned int llvm_cbe_tmp__492;
  unsigned long long llvm_cbe_tmp__493;
  unsigned int llvm_cbe_tmp__494;
  unsigned long long llvm_cbe_tmp__495;
  bool llvm_cbe_tmp__496;
  unsigned long long llvm_cbe_tmp__497;
  bool llvm_cbe_tmp__498;
  unsigned long long llvm_cbe_tmp__499;
  unsigned int llvm_cbe_tmp__500;
  unsigned long long llvm_cbe_tmp__501;
  unsigned int llvm_cbe_tmp__502;
  unsigned long long llvm_cbe_tmp__503;
  unsigned int llvm_cbe_tmp__504;
  unsigned long long llvm_cbe_tmp__505;
  unsigned int llvm_cbe_tmp__506;
  unsigned long long llvm_cbe_tmp__507;
  unsigned char *llvm_cbe_tmp__508;
  unsigned char *llvm_cbe_tmp__509;
  bool llvm_cbe_tmp__510;
  unsigned char *llvm_cbe_tmp__511;
  unsigned char *llvm_cbe_tmp__512;
  bool llvm_cbe_tmp__513;

  *(&llvm_cbe_tmp__315) = llvm_cbe_this;
  llvm_cbe_tmp__347 = *(&llvm_cbe_tmp__315);
  *(&llvm_cbe_tmp__316) = ((unsigned char )1);
  llvm_cbe_tmp__348 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__347->field36)), (&llvm_cbe_tmp__316)))&1);
  *(&llvm_cbe_tmp__317) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field2)), (&llvm_cbe_tmp__317));
  *(&llvm_cbe_tmp__318) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field3)), (&llvm_cbe_tmp__318));
  *(&llvm_cbe_tmp__319) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__347->field4)), (&llvm_cbe_tmp__319));
  *(&llvm_cbe_tmp__320) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__347->field37)), (&llvm_cbe_tmp__320));
  *(&llvm_cbe_tmp__321) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__347->field38)), (&llvm_cbe_tmp__321));
  goto llvm_cbe_tmp__514;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__514:
  _Z4waitv();
  llvm_cbe_tmp__349 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field36))))&1);
  if ((((llvm_cbe_tmp__349 ^ 1)&1))) {
    goto llvm_cbe_tmp__514;
  } else {
    goto llvm_cbe_tmp__515;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__515:
  llvm_cbe_tmp__350 = *(&conf_num_hidden_inp);
  *((&((&llvm_cbe_tmp__347->field14))->field0)) = llvm_cbe_tmp__350;
  llvm_cbe_tmp__351 = *(&conf_num_visible_inp);
  *((&((&llvm_cbe_tmp__347->field15))->field0)) = llvm_cbe_tmp__351;
  llvm_cbe_tmp__352 = *(&conf_num_users_inp);
  *((&((&llvm_cbe_tmp__347->field16))->field0)) = llvm_cbe_tmp__352;
  llvm_cbe_tmp__353 = *(&conf_num_loops_inp);
  *((&((&llvm_cbe_tmp__347->field17))->field0)) = llvm_cbe_tmp__353;
  llvm_cbe_tmp__354 = *(&conf_num_testusers_inp);
  *((&((&llvm_cbe_tmp__347->field18))->field0)) = llvm_cbe_tmp__354;
  llvm_cbe_tmp__355 = *(&conf_num_movies_inp);
  *((&((&llvm_cbe_tmp__347->field19))->field0)) = llvm_cbe_tmp__355;
  llvm_cbe_tmp__356 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field31)));
  *(&llvm_cbe_nv) = (((unsigned int )(unsigned short )llvm_cbe_tmp__356));
  llvm_cbe_tmp__357 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field34)));
  *(&llvm_cbe_ntu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__357));
  llvm_cbe_tmp__358 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field32)));
  *(&llvm_cbe_nu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__358));
  llvm_cbe_tmp__359 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field33)));
  *(&llvm_cbe_nlp) = (((unsigned int )(unsigned short )llvm_cbe_tmp__359));
  llvm_cbe_tmp__360 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field35)));
  *(&llvm_cbe_nm) = (((unsigned int )(unsigned short )llvm_cbe_tmp__360));
  llvm_cbe_tmp__361 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__362 = _ZN13sc_signal_u32cvRjEv(((&llvm_cbe_tmp__347->field3)));
  llvm_cbe_tmp__363 = *llvm_cbe_tmp__362;
  __CPROVER_assume((llvm_cbe_tmp__361 == llvm_cbe_tmp__363));
  *(&llvm_cbe_index) = ((unsigned short )0);
  *(&llvm_cbe_loop_count) = ((unsigned short )0);
  *(&llvm_cbe_pingpong) = ((unsigned char )0);
  llvm_cbe_tmp__364 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp__322) = (((unsigned int )(unsigned short )llvm_cbe_tmp__364));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field2)), (&llvm_cbe_tmp__322));
  llvm_cbe_tmp__365 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__323) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__365))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field3)), (&llvm_cbe_tmp__323));
  *(&conf_done_inp) = ((unsigned char )1);
  *(&llvm_cbe_tmp__324) = ((unsigned char )1);
  llvm_cbe_tmp__366 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__347->field36)), (&llvm_cbe_tmp__324)))&1);
  *((&GM.field13)) = 1ull;
  *((&GM.field16)) = 1ull;
  *(&rst_inp) = ((unsigned char )0);
  *((&GM.field12)) = 0ull;
  llvm_cbe_tmp__367 = *(&conf_done_inp);
  *((&((&llvm_cbe_tmp__347->field13))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__367&1u))&1))));
  llvm_cbe_tmp__368 = *(&conf_num_hidden_inp);
  *((&((&llvm_cbe_tmp__347->field14))->field0)) = llvm_cbe_tmp__368;
  llvm_cbe_tmp__369 = *(&conf_num_visible_inp);
  *((&((&llvm_cbe_tmp__347->field15))->field0)) = llvm_cbe_tmp__369;
  llvm_cbe_tmp__370 = *(&conf_num_users_inp);
  *((&((&llvm_cbe_tmp__347->field16))->field0)) = llvm_cbe_tmp__370;
  llvm_cbe_tmp__371 = *(&conf_num_loops_inp);
  *((&((&llvm_cbe_tmp__347->field17))->field0)) = llvm_cbe_tmp__371;
  llvm_cbe_tmp__372 = *(&conf_num_testusers_inp);
  *((&((&llvm_cbe_tmp__347->field18))->field0)) = llvm_cbe_tmp__372;
  llvm_cbe_tmp__373 = *(&conf_num_movies_inp);
  *((&((&llvm_cbe_tmp__347->field19))->field0)) = llvm_cbe_tmp__373;
  llvm_cbe_tmp__374 = *(&rst_inp);
  *((&((&llvm_cbe_tmp__347->field1))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__374&1u))&1))));
  llvm_cbe_tmp__375 = *((&GM.field4));
  *(&llvm_cbe_tmp__325) = (((unsigned char )(bool )(llvm_cbe_tmp__375 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__347->field36)), (&llvm_cbe_tmp__325));
  llvm_cbe_tmp__376 = *((&GM.field2));
  *(&llvm_cbe_tmp__326) = (((unsigned char )(bool )(llvm_cbe_tmp__376 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__347->field12)), (&llvm_cbe_tmp__326));
  llvm_cbe_tmp__377 = *((&GM.field5));
  *(&llvm_cbe_tmp__327) = (((unsigned short )llvm_cbe_tmp__377));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__347->field30)), (&llvm_cbe_tmp__327));
  llvm_cbe_tmp__378 = *((&GM.field10));
  *(&llvm_cbe_tmp__328) = (((unsigned short )llvm_cbe_tmp__378));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__347->field31)), (&llvm_cbe_tmp__328));
  llvm_cbe_tmp__379 = *((&GM.field9));
  *(&llvm_cbe_tmp__329) = (((unsigned short )llvm_cbe_tmp__379));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__347->field32)), (&llvm_cbe_tmp__329));
  llvm_cbe_tmp__380 = *((&GM.field6));
  *(&llvm_cbe_tmp__330) = (((unsigned short )llvm_cbe_tmp__380));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__347->field33)), (&llvm_cbe_tmp__330));
  llvm_cbe_tmp__381 = *((&GM.field8));
  *(&llvm_cbe_tmp__331) = (((unsigned short )llvm_cbe_tmp__381));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__347->field34)), (&llvm_cbe_tmp__331));
  llvm_cbe_tmp__382 = *((&GM.field7));
  *(&llvm_cbe_tmp__332) = (((unsigned short )llvm_cbe_tmp__382));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__347->field35)), (&llvm_cbe_tmp__332));
  llvm_cbe_tmp__383 = *((&GM.field14));
  *(&llvm_cbe_tmp__333) = (((unsigned int )llvm_cbe_tmp__383));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field2)), (&llvm_cbe_tmp__333));
  llvm_cbe_tmp__384 = *((&GM.field15));
  *(&llvm_cbe_tmp__334) = (((unsigned int )llvm_cbe_tmp__384));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field3)), (&llvm_cbe_tmp__334));
  llvm_cbe_tmp__385 = *((&GM.field16));
  *(&llvm_cbe_tmp__335) = (((unsigned char )(bool )(llvm_cbe_tmp__385 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__347->field4)), (&llvm_cbe_tmp__335));
  llvm_cbe_tmp__386 = *(&rd_grant_inp);
  *((&((&llvm_cbe_tmp__347->field5))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__386&1u))&1))));
  llvm_cbe_tmp__387 = *(&data_in_inp);
  *((&((&llvm_cbe_tmp__347->field6))->field0)) = llvm_cbe_tmp__387;
  llvm_cbe_tmp__388 = *(&wr_grant_inp);
  *((&((&llvm_cbe_tmp__347->field10))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__388&1u))&1))));
  llvm_cbe_tmp__389 = *((&GM.field20));
  *(&llvm_cbe_tmp__336) = (((unsigned char )(bool )(llvm_cbe_tmp__389 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__347->field9)), (&llvm_cbe_tmp__336));
  llvm_cbe_tmp__390 = *((&GM.field18));
  *(&llvm_cbe_tmp__337) = (((unsigned int )llvm_cbe_tmp__390));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field7)), (&llvm_cbe_tmp__337));
  llvm_cbe_tmp__391 = *((&GM.field19));
  *(&llvm_cbe_tmp__338) = (((unsigned int )llvm_cbe_tmp__391));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field8)), (&llvm_cbe_tmp__338));
  llvm_cbe_tmp__392 = *((&GM.field1));
  *(&llvm_cbe_tmp__339) = (((unsigned int )llvm_cbe_tmp__392));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__347->field11)), (&llvm_cbe_tmp__339));
  llvm_cbe_tmp__393 = *((&GM.field3));
  *(&llvm_cbe_i) = (((unsigned short )llvm_cbe_tmp__393));
  llvm_cbe_tmp__394 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__347->field20)), 0u);
  llvm_cbe_tmp__395 = *((&GM.field0.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__394, llvm_cbe_tmp__395);
  llvm_cbe_tmp__396 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__347->field28)), 0u);
  llvm_cbe_tmp__397 = *((&GM.field11.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__396, llvm_cbe_tmp__397);
  llvm_cbe_tmp__398 = *(&llvm_cbe_i);
  llvm_cbe_tmp__399 = *(&llvm_cbe_nv);
  __CPROVER_assume((((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__398))) < ((unsigned int )llvm_cbe_tmp__399)));
  llvm_cbe_tmp__400 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__400) + ((unsigned short )((unsigned short )1)))))));
  llvm_cbe_tmp__401 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__401))) < ((signed int )500u))) {
    goto llvm_cbe_tmp__516;
  } else {
    goto llvm_cbe_tmp__517;
  }

llvm_cbe_tmp__516:
  llvm_cbe_tmp__402 = *(&llvm_cbe_i);
  llvm_cbe_tmp__403 = *(&llvm_cbe_nv);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__402)) == llvm_cbe_tmp__403)) {
    goto llvm_cbe_tmp__517;
  } else {
    goto llvm_cbe_tmp__518;
  }

llvm_cbe_tmp__518:
  llvm_cbe_tmp__404 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field6)));
  *(&llvm_cbe_rate) = (((unsigned char )llvm_cbe_tmp__404));
  _Z4waitv();
  llvm_cbe_tmp__405 = *(&llvm_cbe_rate);
  llvm_cbe_tmp__406 = *(&llvm_cbe_i);
  llvm_cbe_tmp__407 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__408 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__347->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__407&1u))&1)))));
  *((&llvm_cbe_tmp__408[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__406)))])) = llvm_cbe_tmp__405;
  *(&rd_complete) = 0u;
  llvm_cbe_tmp__409 = *(&conf_done_inp);
  llvm_cbe_tmp__410 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__411 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__412 = *(&conf_num_users_inp);
  llvm_cbe_tmp__413 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__414 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__415 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__416 = *(&rst_inp);
  llvm_cbe_tmp__417 = *(&rd_grant_inp);
  llvm_cbe_tmp__418 = *(&data_in_inp);
  llvm_cbe_tmp__419 = *(&wr_grant_inp);
  _ZN13model_DMAload6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__409&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__410)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__411)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__412)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__413)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__414)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__415)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__416&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__417&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__418)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__419&1u))&1)))));
  llvm_cbe_tmp__420 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field36))))&1);
  llvm_cbe_tmp__421 = *((&GM.field4));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__420)) == llvm_cbe_tmp__421), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__422 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field12))))&1);
  llvm_cbe_tmp__423 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__422)) == llvm_cbe_tmp__423), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__424 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field30)));
  llvm_cbe_tmp__425 = *((&GM.field5));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__424)) == llvm_cbe_tmp__425), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__426 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field31)));
  llvm_cbe_tmp__427 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__426)) == llvm_cbe_tmp__427), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__428 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field32)));
  llvm_cbe_tmp__429 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__428)) == llvm_cbe_tmp__429), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__430 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field33)));
  llvm_cbe_tmp__431 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__430)) == llvm_cbe_tmp__431), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__432 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field34)));
  llvm_cbe_tmp__433 = *((&GM.field8));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__432)) == llvm_cbe_tmp__433), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__434 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field35)));
  llvm_cbe_tmp__435 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__434)) == llvm_cbe_tmp__435), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__436 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field2)));
  llvm_cbe_tmp__437 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__436)) == llvm_cbe_tmp__437), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__438 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field3)));
  llvm_cbe_tmp__439 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__438)) == llvm_cbe_tmp__439), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__440 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field4))))&1);
  llvm_cbe_tmp__441 = *((&GM.field16));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__440)) == llvm_cbe_tmp__441), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__442 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field9))))&1);
  llvm_cbe_tmp__443 = *((&GM.field20));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__442)) == llvm_cbe_tmp__443), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__444 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field7)));
  llvm_cbe_tmp__445 = *((&GM.field18));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__444)) == llvm_cbe_tmp__445), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__446 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field8)));
  llvm_cbe_tmp__447 = *((&GM.field19));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__446)) == llvm_cbe_tmp__447), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__448 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field11)));
  llvm_cbe_tmp__449 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__448)) == llvm_cbe_tmp__449), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__450 = *(&rd_complete);
  llvm_cbe_tmp__451 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__450)) == llvm_cbe_tmp__451), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__452 = *(&llvm_cbe_i);
  llvm_cbe_tmp__453 = *((&GM.field3));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__452)) == llvm_cbe_tmp__453), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__454 = *((&GM.field0.field0));
  llvm_cbe_tmp__455 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__347->field20)), 0u);
  llvm_cbe_tmp__456 = ((__CPROVER_array_equal(llvm_cbe_tmp__454, llvm_cbe_tmp__455))&1);
  __CPROVER_assert(llvm_cbe_tmp__456, ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__457 = *((&GM.field11.field0));
  llvm_cbe_tmp__458 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__347->field28)), 0u);
  llvm_cbe_tmp__459 = ((__CPROVER_array_equal(llvm_cbe_tmp__457, llvm_cbe_tmp__458))&1);
  __CPROVER_assert(llvm_cbe_tmp__459, ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__460 = *(&llvm_cbe_i);
  llvm_cbe_tmp__461 = *(&llvm_cbe_nv);
  __CPROVER_assert((((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__460))) < ((unsigned int )llvm_cbe_tmp__461)), ((&_OC_str20.array[((signed int )0u)])));
  goto llvm_cbe_tmp__519;

llvm_cbe_tmp__517:
  _Z4waitv();
  llvm_cbe_tmp__462 = *(&llvm_cbe_nv);
  llvm_cbe_tmp__463 = *(&llvm_cbe_pingpong);
  llvm_cbe_tmp__464 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__347->field20)), (((unsigned int )(bool )(((((bool )llvm_cbe_tmp__463&1u))&1)))));
  *((&llvm_cbe_tmp__464[((signed long long )(((unsigned long long )(unsigned int )llvm_cbe_tmp__462)))])) = ((unsigned char )1);
  *(&rd_complete) = 1u;
  llvm_cbe_tmp__465 = *(&conf_done_inp);
  llvm_cbe_tmp__466 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__467 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__468 = *(&conf_num_users_inp);
  llvm_cbe_tmp__469 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__470 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__471 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__472 = *(&rst_inp);
  llvm_cbe_tmp__473 = *(&rd_grant_inp);
  llvm_cbe_tmp__474 = *(&data_in_inp);
  llvm_cbe_tmp__475 = *(&wr_grant_inp);
  _ZN13model_DMAload6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__465&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__466)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__467)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__468)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__469)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__470)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__471)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__472&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__473&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__474)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__475&1u))&1)))));
  llvm_cbe_tmp__476 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field36))))&1);
  llvm_cbe_tmp__477 = *((&GM.field4));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__476)) == llvm_cbe_tmp__477), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__478 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field12))))&1);
  llvm_cbe_tmp__479 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__478)) == llvm_cbe_tmp__479), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__480 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field30)));
  llvm_cbe_tmp__481 = *((&GM.field5));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__480)) == llvm_cbe_tmp__481), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__482 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field31)));
  llvm_cbe_tmp__483 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__482)) == llvm_cbe_tmp__483), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__484 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field32)));
  llvm_cbe_tmp__485 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__484)) == llvm_cbe_tmp__485), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__486 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field33)));
  llvm_cbe_tmp__487 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__486)) == llvm_cbe_tmp__487), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__488 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field34)));
  llvm_cbe_tmp__489 = *((&GM.field8));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__488)) == llvm_cbe_tmp__489), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__490 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__347->field35)));
  llvm_cbe_tmp__491 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__490)) == llvm_cbe_tmp__491), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__492 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field2)));
  llvm_cbe_tmp__493 = *((&GM.field14));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__492)) == llvm_cbe_tmp__493), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__494 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field3)));
  llvm_cbe_tmp__495 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__494)) == llvm_cbe_tmp__495), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__496 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field4))))&1);
  llvm_cbe_tmp__497 = *((&GM.field16));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__496)) == llvm_cbe_tmp__497), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__498 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__347->field9))))&1);
  llvm_cbe_tmp__499 = *((&GM.field20));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__498)) == llvm_cbe_tmp__499), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__500 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field7)));
  llvm_cbe_tmp__501 = *((&GM.field18));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__500)) == llvm_cbe_tmp__501), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__502 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field8)));
  llvm_cbe_tmp__503 = *((&GM.field19));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__502)) == llvm_cbe_tmp__503), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__504 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__347->field11)));
  llvm_cbe_tmp__505 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__504)) == llvm_cbe_tmp__505), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__506 = *(&rd_complete);
  llvm_cbe_tmp__507 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__506)) == llvm_cbe_tmp__507), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__508 = *((&GM.field0.field0));
  llvm_cbe_tmp__509 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__347->field20)), 0u);
  llvm_cbe_tmp__510 = ((__CPROVER_array_equal(llvm_cbe_tmp__508, llvm_cbe_tmp__509))&1);
  __CPROVER_assert(llvm_cbe_tmp__510, ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__511 = *((&GM.field11.field0));
  llvm_cbe_tmp__512 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__347->field28)), 0u);
  llvm_cbe_tmp__513 = ((__CPROVER_array_equal(llvm_cbe_tmp__511, llvm_cbe_tmp__512))&1);
  __CPROVER_assert(llvm_cbe_tmp__513, ((&_OC_str19.array[((signed int )0u)])));
  goto llvm_cbe_tmp__519;

llvm_cbe_tmp__519:
  return;
}


bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__520;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__521;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__522;
  unsigned char *llvm_cbe_tmp__523;
  unsigned char llvm_cbe_tmp__524;
  unsigned char llvm_cbe_tmp__525;

  *(&llvm_cbe_tmp__520) = llvm_cbe_this;
  *(&llvm_cbe_tmp__521) = llvm_cbe_d;
  llvm_cbe_tmp__522 = *(&llvm_cbe_tmp__520);
  llvm_cbe_tmp__523 = *(&llvm_cbe_tmp__521);
  llvm_cbe_tmp__524 = *llvm_cbe_tmp__523;
  *((&llvm_cbe_tmp__522->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__524&1u))&1))));
  llvm_cbe_tmp__525 = *((&llvm_cbe_tmp__522->field0));
  return (((((bool )llvm_cbe_tmp__525&1u))&1));
}


void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__526;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__527;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__528;
  unsigned int *llvm_cbe_tmp__529;
  unsigned int llvm_cbe_tmp__530;

  *(&llvm_cbe_tmp__526) = llvm_cbe_this;
  *(&llvm_cbe_tmp__527) = llvm_cbe_d;
  llvm_cbe_tmp__528 = *(&llvm_cbe_tmp__526);
  llvm_cbe_tmp__529 = *(&llvm_cbe_tmp__527);
  llvm_cbe_tmp__530 = *llvm_cbe_tmp__529;
  *((&llvm_cbe_tmp__528->field0)) = llvm_cbe_tmp__530;
  return;
}


unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__531;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__532;
  unsigned short llvm_cbe_tmp__533;

  *(&llvm_cbe_tmp__531) = llvm_cbe_this;
  llvm_cbe_tmp__532 = *(&llvm_cbe_tmp__531);
  llvm_cbe_tmp__533 = *((&llvm_cbe_tmp__532->field0));
  return llvm_cbe_tmp__533;
}


unsigned int *_ZN13sc_signal_u32cvRjEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__534;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__535;

  *(&llvm_cbe_tmp__534) = llvm_cbe_this;
  llvm_cbe_tmp__535 = *(&llvm_cbe_tmp__534);
  return ((&llvm_cbe_tmp__535->field0));
}


unsigned char *_ZN11SysCArray2DIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__536;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__537;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__538;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__539;
  unsigned int llvm_cbe_tmp__540;
  unsigned char *llvm_cbe_tmp__541;
  unsigned int llvm_cbe_tmp__542;
  unsigned char *llvm_cbe_tmp__543;
  unsigned char *llvm_cbe_tmp__544;

  *(&llvm_cbe_tmp__537) = llvm_cbe_this;
  *(&llvm_cbe_tmp__538) = llvm_cbe_Xidx;
  llvm_cbe_tmp__539 = *(&llvm_cbe_tmp__537);
  llvm_cbe_tmp__540 = *(&llvm_cbe_tmp__538);
  if ((llvm_cbe_tmp__540 == 0u)) {
    goto llvm_cbe_tmp__545;
  } else {
    goto llvm_cbe_tmp__546;
  }

llvm_cbe_tmp__545:
  llvm_cbe_tmp__541 = *((&llvm_cbe_tmp__539->field1));
  *(&llvm_cbe_tmp__536) = llvm_cbe_tmp__541;
  goto llvm_cbe_tmp__547;

llvm_cbe_tmp__546:
  llvm_cbe_tmp__542 = *(&llvm_cbe_tmp__538);
  llvm_cbe_tmp__543 = *((&llvm_cbe_tmp__539->field0));
  *(&llvm_cbe_tmp__536) = ((&llvm_cbe_tmp__543[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__542) * ((unsigned int )512u)))))))]));
  goto llvm_cbe_tmp__547;

llvm_cbe_tmp__547:
  llvm_cbe_tmp__544 = *(&llvm_cbe_tmp__536);
  return llvm_cbe_tmp__544;
}


unsigned char *_ZN11SysCArray2DIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__548;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__549;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__550;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__551;
  unsigned int llvm_cbe_tmp__552;
  unsigned char *llvm_cbe_tmp__553;
  unsigned int llvm_cbe_tmp__554;
  unsigned char *llvm_cbe_tmp__555;
  unsigned char *llvm_cbe_tmp__556;

  *(&llvm_cbe_tmp__549) = llvm_cbe_this;
  *(&llvm_cbe_tmp__550) = llvm_cbe_Xidx;
  llvm_cbe_tmp__551 = *(&llvm_cbe_tmp__549);
  llvm_cbe_tmp__552 = *(&llvm_cbe_tmp__550);
  if ((llvm_cbe_tmp__552 == 0u)) {
    goto llvm_cbe_tmp__557;
  } else {
    goto llvm_cbe_tmp__558;
  }

llvm_cbe_tmp__557:
  llvm_cbe_tmp__553 = *((&llvm_cbe_tmp__551->field1));
  *(&llvm_cbe_tmp__548) = llvm_cbe_tmp__553;
  goto llvm_cbe_tmp__559;

llvm_cbe_tmp__558:
  llvm_cbe_tmp__554 = *(&llvm_cbe_tmp__550);
  llvm_cbe_tmp__555 = *((&llvm_cbe_tmp__551->field0));
  *(&llvm_cbe_tmp__548) = ((&llvm_cbe_tmp__555[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__554) * ((unsigned int )128u)))))))]));
  goto llvm_cbe_tmp__559;

llvm_cbe_tmp__559:
  llvm_cbe_tmp__556 = *(&llvm_cbe_tmp__548);
  return llvm_cbe_tmp__556;
}


void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__560;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__561;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__562;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__563;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__564;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__565;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__566;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__567;    /* Address-exposed local */
  unsigned short llvm_cbe_ntu;    /* Address-exposed local */
  unsigned short llvm_cbe_nm;    /* Address-exposed local */
  unsigned int llvm_cbe_index;    /* Address-exposed local */
  unsigned char llvm_cbe_rating;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__568;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__569;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__570;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__571;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__572;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__573;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__574;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__575;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__576;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__577;
  bool llvm_cbe_tmp__578;
  bool llvm_cbe_tmp__579;
  unsigned short llvm_cbe_tmp__580;
  unsigned short llvm_cbe_tmp__581;
  unsigned int llvm_cbe_tmp__582;
  unsigned short llvm_cbe_tmp__583;
  bool llvm_cbe_tmp__584;
  bool llvm_cbe_tmp__585;
  unsigned short llvm_cbe_tmp__586;
  unsigned int llvm_cbe_tmp__587;
  unsigned short llvm_cbe_tmp__588;
  unsigned int llvm_cbe_tmp__589;
  bool llvm_cbe_tmp__590;
  unsigned short llvm_cbe_tmp__591;
  unsigned short llvm_cbe_tmp__592;
  unsigned short llvm_cbe_tmp__593;
  unsigned short llvm_cbe_tmp__594;
  unsigned char *llvm_cbe_tmp__595;
  unsigned char llvm_cbe_tmp__596;
  unsigned char llvm_cbe_tmp__597;
  unsigned short llvm_cbe_tmp__598;

  *(&llvm_cbe_tmp__560) = llvm_cbe_this;
  llvm_cbe_tmp__577 = *(&llvm_cbe_tmp__560);
  *(&llvm_cbe_tmp__561) = ((unsigned char )1);
  llvm_cbe_tmp__578 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__577->field36)), (&llvm_cbe_tmp__561)))&1);
  *(&llvm_cbe_tmp__562) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__577->field8)), (&llvm_cbe_tmp__562));
  *(&llvm_cbe_tmp__563) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__577->field7)), (&llvm_cbe_tmp__563));
  *(&llvm_cbe_tmp__564) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field9)), (&llvm_cbe_tmp__564));
  *(&llvm_cbe_tmp__565) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field44)), (&llvm_cbe_tmp__565));
  *(&llvm_cbe_tmp__566) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field45)), (&llvm_cbe_tmp__566));
  *(&llvm_cbe_tmp__567) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field12)), (&llvm_cbe_tmp__567));
  goto llvm_cbe_tmp__599;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__599:
  _Z4waitv();
  llvm_cbe_tmp__579 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__577->field36))))&1);
  if ((((llvm_cbe_tmp__579 ^ 1)&1))) {
    goto llvm_cbe_tmp__599;
  } else {
    goto llvm_cbe_tmp__600;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__600:
  llvm_cbe_tmp__580 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__577->field34)));
  *(&llvm_cbe_ntu) = llvm_cbe_tmp__580;
  llvm_cbe_tmp__581 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__577->field35)));
  *(&llvm_cbe_nm) = llvm_cbe_tmp__581;
  *(&llvm_cbe_index) = 0u;
  goto llvm_cbe_tmp__601;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__601:
  llvm_cbe_tmp__582 = *(&llvm_cbe_index);
  llvm_cbe_tmp__583 = *(&llvm_cbe_ntu);
  if ((llvm_cbe_tmp__582 == (((unsigned int )(unsigned short )llvm_cbe_tmp__583)))) {
    goto llvm_cbe_tmp__602;
  } else {
    goto llvm_cbe_tmp__603;
  }

llvm_cbe_tmp__604:
  *(&llvm_cbe_tmp__576) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field45)), (&llvm_cbe_tmp__576));
  goto llvm_cbe_tmp__601;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__605:
  llvm_cbe_tmp__591 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__591))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__606;
  } else {
    goto llvm_cbe_tmp__604;
  }

llvm_cbe_tmp__607:
  llvm_cbe_tmp__594 = *(&llvm_cbe_i);
  llvm_cbe_tmp__595 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__577->field28)), 0u);
  llvm_cbe_tmp__596 = *((&llvm_cbe_tmp__595[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__594)))]));
  *(&llvm_cbe_rating) = llvm_cbe_tmp__596;
  _Z4waitv();
  llvm_cbe_tmp__597 = *(&llvm_cbe_rating);
  *(&llvm_cbe_tmp__575) = (((unsigned int )(unsigned char )llvm_cbe_tmp__597));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__577->field11)), (&llvm_cbe_tmp__575));
  llvm_cbe_tmp__598 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__598) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__605;

llvm_cbe_tmp__606:
  llvm_cbe_tmp__592 = *(&llvm_cbe_i);
  llvm_cbe_tmp__593 = *(&llvm_cbe_nm);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__592)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__593)))) {
    goto llvm_cbe_tmp__604;
  } else {
    goto llvm_cbe_tmp__607;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__608:
  *(&llvm_cbe_tmp__574) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field9)), (&llvm_cbe_tmp__574));
  *(&llvm_cbe_i) = ((unsigned short )0);
  goto llvm_cbe_tmp__605;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__609:
  _Z4waitv();
  llvm_cbe_tmp__590 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__577->field10))))&1);
  if ((((llvm_cbe_tmp__590 ^ 1)&1))) {
    goto llvm_cbe_tmp__609;
  } else {
    goto llvm_cbe_tmp__608;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__610:
  *(&llvm_cbe_tmp__570) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field44)), (&llvm_cbe_tmp__570));
  *(&llvm_cbe_tmp__571) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field45)), (&llvm_cbe_tmp__571));
  llvm_cbe_tmp__586 = *(&llvm_cbe_nm);
  llvm_cbe_tmp__587 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__586))) * ((unsigned int )llvm_cbe_tmp__587))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__577->field7)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__588 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__577->field35)));
  *(&llvm_cbe_tmp__572) = (((unsigned int )(unsigned short )llvm_cbe_tmp__588));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__577->field8)), (&llvm_cbe_tmp__572));
  llvm_cbe_tmp__589 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__589) + ((unsigned int )1u))));
  *(&llvm_cbe_tmp__573) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field9)), (&llvm_cbe_tmp__573));
  goto llvm_cbe_tmp__609;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__611:
  _Z4waitv();
  llvm_cbe_tmp__585 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__577->field43))))&1);
  if (llvm_cbe_tmp__585) {
    goto llvm_cbe_tmp__611;
  } else {
    goto llvm_cbe_tmp__610;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__612:
  *(&llvm_cbe_tmp__569) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field44)), (&llvm_cbe_tmp__569));
  goto llvm_cbe_tmp__611;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__603:
  _Z4waitv();
  llvm_cbe_tmp__584 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__577->field43))))&1);
  if ((((llvm_cbe_tmp__584 ^ 1)&1))) {
    goto llvm_cbe_tmp__603;
  } else {
    goto llvm_cbe_tmp__612;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__602:
  *(&llvm_cbe_tmp__568) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__577->field12)), (&llvm_cbe_tmp__568));
  goto llvm_cbe_tmp__613;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__613:
  _Z4waitv();
  goto llvm_cbe_tmp__613;

  } while (1); /* end of syntactic loop '' */
}


static void __cxx_global_var_init21(void) {
  _ZN3rbmC1Ev((&IMPL));
  return;
}


void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__614;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__615;

  *(&llvm_cbe_tmp__614) = llvm_cbe_this;
  llvm_cbe_tmp__615 = *(&llvm_cbe_tmp__614);
  _ZN3rbmC2Ev(llvm_cbe_tmp__615);
  return;
}


unsigned int main(void) {
  unsigned int llvm_cbe_tmp__616;    /* Address-exposed local */
  _GLOBAL__I_a();  CODE_FOR_MAIN();
  *(&llvm_cbe_tmp__616) = 0u;
  _ZN3rbm4loadEv((&IMPL));
  return 0u;
}


void _ZN8type_memIhLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__617;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__618;
  unsigned char *llvm_cbe_tmp__619;

  *(&llvm_cbe_tmp__617) = llvm_cbe_this;
  llvm_cbe_tmp__618 = *(&llvm_cbe_tmp__617);
  llvm_cbe_tmp__619 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__618->field0)) = llvm_cbe_tmp__619;
  return;
}


void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__620;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__621;

  *(&llvm_cbe_tmp__620) = llvm_cbe_this;
  llvm_cbe_tmp__621 = *(&llvm_cbe_tmp__620);
  return;
}


void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__622;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__623;
  unsigned char *llvm_cbe_tmp__624;
  unsigned char llvm_cbe_tmp__625;
  unsigned char *llvm_cbe_tmp__626;
  unsigned char llvm_cbe_tmp__627;
  unsigned char *llvm_cbe_tmp__628;
  unsigned char llvm_cbe_tmp__629;
  unsigned char *llvm_cbe_tmp__630;
  unsigned char llvm_cbe_tmp__631;
  unsigned char *llvm_cbe_tmp__632;
  unsigned char llvm_cbe_tmp__633;

  *(&llvm_cbe_tmp__622) = llvm_cbe_this;
  llvm_cbe_tmp__623 = *(&llvm_cbe_tmp__622);
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__623->field0)), ((&_OC_str22.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__623->field1)), ((&_OC_str23.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field2)), ((&_OC_str24.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field3)), ((&_OC_str25.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__623->field4)), ((&_OC_str26.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__623->field5)), ((&_OC_str27.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field6)), ((&_OC_str28.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field7)), ((&_OC_str29.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field8)), ((&_OC_str30.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__623->field9)), ((&_OC_str31.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__623->field10)), ((&_OC_str32.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field11)), ((&_OC_str33.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__623->field12)), ((&_OC_str34.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__623->field13)), ((&_OC_str35.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field14)), ((&_OC_str36.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field15)), ((&_OC_str37.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field16)), ((&_OC_str38.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field17)), ((&_OC_str39.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field18)), ((&_OC_str40.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__623->field19)), ((&_OC_str41.array[((signed int )0u)])));
  _ZN11SysCArray2DIhLj2ELj512EEC1Ev(((&llvm_cbe_tmp__623->field20)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__623->field21)));
  _ZN11SysCArray1DIbLj128EEC1Ev(((&llvm_cbe_tmp__623->field22)));
  _ZN11SysCArray2DIfLj501ELj101EEC1Ev(((&llvm_cbe_tmp__623->field23)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__623->field24)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__623->field25)));
  _ZN11SysCArray1DIfLj5EEC1Ev(((&llvm_cbe_tmp__623->field26)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__623->field27)));
  _ZN11SysCArray2DIhLj2ELj128EEC1Ev(((&llvm_cbe_tmp__623->field28)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__623->field30)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__623->field31)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__623->field32)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__623->field33)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__623->field34)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__623->field35)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field36)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field37)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field38)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field39)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field40)));
  _ZN15sc_signal_int32C1Ev(((&llvm_cbe_tmp__623->field41)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field42)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field43)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field44)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__623->field45)));
  llvm_cbe_tmp__624 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__623->field1)));
  llvm_cbe_tmp__625 = *llvm_cbe_tmp__624;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__625&1u))&1)))), 0);
  llvm_cbe_tmp__626 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__623->field1)));
  llvm_cbe_tmp__627 = *llvm_cbe_tmp__626;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__627&1u))&1)))), 0);
  llvm_cbe_tmp__628 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__623->field1)));
  llvm_cbe_tmp__629 = *llvm_cbe_tmp__628;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__629&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__630 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__623->field1)));
  llvm_cbe_tmp__631 = *llvm_cbe_tmp__630;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__631&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__632 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__623->field1)));
  llvm_cbe_tmp__633 = *llvm_cbe_tmp__632;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__633&1u))&1)))), 0);
  return;
}


void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__634;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__635;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__636;
  unsigned char *llvm_cbe_tmp__637;

  *(&llvm_cbe_tmp__634) = llvm_cbe_this;
  *(&llvm_cbe_tmp__635) = llvm_cbe_p;
  llvm_cbe_tmp__636 = *(&llvm_cbe_tmp__634);
  llvm_cbe_tmp__637 = *(&llvm_cbe_tmp__635);
  _ZN14sc_signal_boolC2EPKc(llvm_cbe_tmp__636, llvm_cbe_tmp__637);
  return;
}


void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__638;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__639;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__640;
  unsigned char *llvm_cbe_tmp__641;

  *(&llvm_cbe_tmp__638) = llvm_cbe_this;
  *(&llvm_cbe_tmp__639) = llvm_cbe_p;
  llvm_cbe_tmp__640 = *(&llvm_cbe_tmp__638);
  llvm_cbe_tmp__641 = *(&llvm_cbe_tmp__639);
  _ZN13sc_signal_u32C2EPKc(llvm_cbe_tmp__640, llvm_cbe_tmp__641);
  return;
}


void _ZN11SysCArray2DIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__642;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__643;

  *(&llvm_cbe_tmp__642) = llvm_cbe_this;
  llvm_cbe_tmp__643 = *(&llvm_cbe_tmp__642);
  _ZN11SysCArray2DIhLj2ELj512EEC2Ev(llvm_cbe_tmp__643);
  return;
}


void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__644;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__645;

  *(&llvm_cbe_tmp__644) = llvm_cbe_this;
  llvm_cbe_tmp__645 = *(&llvm_cbe_tmp__644);
  _ZN11SysCArray1DIbLj512EEC2Ev(llvm_cbe_tmp__645);
  return;
}


void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__646;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__647;

  *(&llvm_cbe_tmp__646) = llvm_cbe_this;
  llvm_cbe_tmp__647 = *(&llvm_cbe_tmp__646);
  _ZN11SysCArray1DIbLj128EEC2Ev(llvm_cbe_tmp__647);
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_unnamed3 *llvm_cbe_this) {
  struct l_unnamed3 *llvm_cbe_tmp__648;    /* Address-exposed local */
  struct l_unnamed3 *llvm_cbe_tmp__649;

  *(&llvm_cbe_tmp__648) = llvm_cbe_this;
  llvm_cbe_tmp__649 = *(&llvm_cbe_tmp__648);
  _ZN11SysCArray2DIfLj501ELj101EEC2Ev(llvm_cbe_tmp__649);
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__650;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__651;

  *(&llvm_cbe_tmp__650) = llvm_cbe_this;
  llvm_cbe_tmp__651 = *(&llvm_cbe_tmp__650);
  _ZN11SysCArray2DIbLj501ELj101EEC2Ev(llvm_cbe_tmp__651);
  return;
}


void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_unnamed4 *llvm_cbe_this) {
  struct l_unnamed4 *llvm_cbe_tmp__652;    /* Address-exposed local */
  struct l_unnamed4 *llvm_cbe_tmp__653;

  *(&llvm_cbe_tmp__652) = llvm_cbe_this;
  llvm_cbe_tmp__653 = *(&llvm_cbe_tmp__652);
  _ZN11SysCArray1DIfLj5EEC2Ev(llvm_cbe_tmp__653);
  return;
}


void _ZN11SysCArray2DIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__654;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__655;

  *(&llvm_cbe_tmp__654) = llvm_cbe_this;
  llvm_cbe_tmp__655 = *(&llvm_cbe_tmp__654);
  _ZN11SysCArray2DIhLj2ELj128EEC2Ev(llvm_cbe_tmp__655);
  return;
}


void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__656;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__657;

  *(&llvm_cbe_tmp__656) = llvm_cbe_this;
  llvm_cbe_tmp__657 = *(&llvm_cbe_tmp__656);
  _ZN13sc_signal_u16C2Ev(llvm_cbe_tmp__657);
  return;
}


void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__658;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__659;

  *(&llvm_cbe_tmp__658) = llvm_cbe_this;
  llvm_cbe_tmp__659 = *(&llvm_cbe_tmp__658);
  _ZN14sc_signal_boolC2Ev(llvm_cbe_tmp__659);
  return;
}


void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__660;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__661;

  *(&llvm_cbe_tmp__660) = llvm_cbe_this;
  llvm_cbe_tmp__661 = *(&llvm_cbe_tmp__660);
  _ZN15sc_signal_int32C2Ev(llvm_cbe_tmp__661);
  return;
}


unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__662;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__663;

  *(&llvm_cbe_tmp__662) = llvm_cbe_this;
  llvm_cbe_tmp__663 = *(&llvm_cbe_tmp__662);
  return ((&llvm_cbe_tmp__663->field0));
}


void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__664;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__665;

  *(&llvm_cbe_tmp__664) = llvm_cbe_this;
  llvm_cbe_tmp__665 = *(&llvm_cbe_tmp__664);
  return;
}


void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__666;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__667;

  *(&llvm_cbe_tmp__666) = llvm_cbe_this;
  llvm_cbe_tmp__667 = *(&llvm_cbe_tmp__666);
  return;
}


void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__668;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__669;

  *(&llvm_cbe_tmp__668) = llvm_cbe_this;
  llvm_cbe_tmp__669 = *(&llvm_cbe_tmp__668);
  return;
}


void _ZN11SysCArray2DIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__670;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__671;
  unsigned char *llvm_cbe_tmp__672;
  unsigned char *llvm_cbe_tmp__673;

  *(&llvm_cbe_tmp__670) = llvm_cbe_this;
  llvm_cbe_tmp__671 = *(&llvm_cbe_tmp__670);
  llvm_cbe_tmp__672 = __CPROVER_malloc(256ull);
  *((&llvm_cbe_tmp__671->field0)) = llvm_cbe_tmp__672;
  llvm_cbe_tmp__673 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__671->field1)) = llvm_cbe_tmp__673;
  return;
}


void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_unnamed4 *llvm_cbe_this) {
  struct l_unnamed4 *llvm_cbe_tmp__674;    /* Address-exposed local */
  struct l_unnamed4 *llvm_cbe_tmp__675;
  unsigned char *llvm_cbe_tmp__676;

  *(&llvm_cbe_tmp__674) = llvm_cbe_this;
  llvm_cbe_tmp__675 = *(&llvm_cbe_tmp__674);
  llvm_cbe_tmp__676 = __CPROVER_malloc(20ull);
  *((&llvm_cbe_tmp__675->field0)) = (((float *)llvm_cbe_tmp__676));
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__677;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__678;
  unsigned char *llvm_cbe_tmp__679;
  unsigned char *llvm_cbe_tmp__680;

  *(&llvm_cbe_tmp__677) = llvm_cbe_this;
  llvm_cbe_tmp__678 = *(&llvm_cbe_tmp__677);
  llvm_cbe_tmp__679 = __CPROVER_malloc(50601ull);
  *((&llvm_cbe_tmp__678->field0)) = llvm_cbe_tmp__679;
  llvm_cbe_tmp__680 = __CPROVER_malloc(101ull);
  *((&llvm_cbe_tmp__678->field1)) = llvm_cbe_tmp__680;
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_unnamed3 *llvm_cbe_this) {
  struct l_unnamed3 *llvm_cbe_tmp__681;    /* Address-exposed local */
  struct l_unnamed3 *llvm_cbe_tmp__682;
  unsigned char *llvm_cbe_tmp__683;
  unsigned char *llvm_cbe_tmp__684;

  *(&llvm_cbe_tmp__681) = llvm_cbe_this;
  llvm_cbe_tmp__682 = *(&llvm_cbe_tmp__681);
  llvm_cbe_tmp__683 = __CPROVER_malloc(202404ull);
  *((&llvm_cbe_tmp__682->field0)) = (((float *)llvm_cbe_tmp__683));
  llvm_cbe_tmp__684 = __CPROVER_malloc(404ull);
  *((&llvm_cbe_tmp__682->field1)) = (((float *)llvm_cbe_tmp__684));
  return;
}


void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__685;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__686;
  unsigned char *llvm_cbe_tmp__687;

  *(&llvm_cbe_tmp__685) = llvm_cbe_this;
  llvm_cbe_tmp__686 = *(&llvm_cbe_tmp__685);
  llvm_cbe_tmp__687 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__686->field0)) = llvm_cbe_tmp__687;
  return;
}


void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__688;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__689;
  unsigned char *llvm_cbe_tmp__690;

  *(&llvm_cbe_tmp__688) = llvm_cbe_this;
  llvm_cbe_tmp__689 = *(&llvm_cbe_tmp__688);
  llvm_cbe_tmp__690 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__689->field0)) = llvm_cbe_tmp__690;
  return;
}


void _ZN11SysCArray2DIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__691;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__692;
  unsigned char *llvm_cbe_tmp__693;
  unsigned char *llvm_cbe_tmp__694;

  *(&llvm_cbe_tmp__691) = llvm_cbe_this;
  llvm_cbe_tmp__692 = *(&llvm_cbe_tmp__691);
  llvm_cbe_tmp__693 = __CPROVER_malloc(1024ull);
  *((&llvm_cbe_tmp__692->field0)) = llvm_cbe_tmp__693;
  llvm_cbe_tmp__694 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__692->field1)) = llvm_cbe_tmp__694;
  return;
}


void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__695;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__696;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__697;

  *(&llvm_cbe_tmp__695) = llvm_cbe_this;
  *(&llvm_cbe_tmp__696) = llvm_cbe_p;
  llvm_cbe_tmp__697 = *(&llvm_cbe_tmp__695);
  return;
}


void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__698;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__699;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__700;

  *(&llvm_cbe_tmp__698) = llvm_cbe_this;
  *(&llvm_cbe_tmp__699) = llvm_cbe_p;
  llvm_cbe_tmp__700 = *(&llvm_cbe_tmp__698);
  return;
}


void _ZN13model_DMAloadD2Ev(struct l_class_OC_model_DMAload *llvm_cbe_this) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__701;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__702;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__703;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__704;

  *(&llvm_cbe_tmp__701) = llvm_cbe_this;
  llvm_cbe_tmp__704 = *(&llvm_cbe_tmp__701);
  _ZN8type_memIhLj128EED1Ev(((&llvm_cbe_tmp__704->field11)));
  _ZN8type_memIhLj512EED1Ev(((&llvm_cbe_tmp__704->field0)));
  return;
}


void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__705;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__706;

  *(&llvm_cbe_tmp__705) = llvm_cbe_this;
  llvm_cbe_tmp__706 = *(&llvm_cbe_tmp__705);
  _ZN8type_memIhLj128EED2Ev(llvm_cbe_tmp__706);
  return;
}


void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__707;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__708;

  *(&llvm_cbe_tmp__707) = llvm_cbe_this;
  llvm_cbe_tmp__708 = *(&llvm_cbe_tmp__707);
  return;
}


void _ZN13model_DMAloadC2Ev(struct l_class_OC_model_DMAload *llvm_cbe_this) {
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__709;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__710;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__711;    /* Address-exposed local */
  struct l_class_OC_model_DMAload *llvm_cbe_tmp__712;

  *(&llvm_cbe_tmp__709) = llvm_cbe_this;
  llvm_cbe_tmp__712 = *(&llvm_cbe_tmp__709);
  _ZN8type_memIhLj512EEC1El(((&llvm_cbe_tmp__712->field0)), 0ull);
  _ZN8type_memIhLj128EEC1El(((&llvm_cbe_tmp__712->field11)), 0ull);
  *((&llvm_cbe_tmp__712->field21)) = 65535ull;
  *((&llvm_cbe_tmp__712->field22)) = 255ull;
  *((&llvm_cbe_tmp__712->field23)) = 511ull;
  return;
}


void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__713;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__714;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__715;
  unsigned long long llvm_cbe_tmp__716;

  *(&llvm_cbe_tmp__713) = llvm_cbe_this;
  *(&llvm_cbe_tmp__714) = llvm_cbe_def;
  llvm_cbe_tmp__715 = *(&llvm_cbe_tmp__713);
  llvm_cbe_tmp__716 = *(&llvm_cbe_tmp__714);
  _ZN8type_memIhLj512EEC2El(llvm_cbe_tmp__715, llvm_cbe_tmp__716);
  return;
}


void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__717;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__718;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__719;
  unsigned long long llvm_cbe_tmp__720;

  *(&llvm_cbe_tmp__717) = llvm_cbe_this;
  *(&llvm_cbe_tmp__718) = llvm_cbe_def;
  llvm_cbe_tmp__719 = *(&llvm_cbe_tmp__717);
  llvm_cbe_tmp__720 = *(&llvm_cbe_tmp__718);
  _ZN8type_memIhLj128EEC2El(llvm_cbe_tmp__719, llvm_cbe_tmp__720);
  return;
}


void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__721;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__722;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__723;
  unsigned char *llvm_cbe_tmp__724;

  *(&llvm_cbe_tmp__721) = llvm_cbe_this;
  *(&llvm_cbe_tmp__722) = llvm_cbe_def;
  llvm_cbe_tmp__723 = *(&llvm_cbe_tmp__721);
  llvm_cbe_tmp__724 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__723->field0)) = llvm_cbe_tmp__724;
  return;
}


void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__725;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__726;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__727;
  unsigned char *llvm_cbe_tmp__728;

  *(&llvm_cbe_tmp__725) = llvm_cbe_this;
  *(&llvm_cbe_tmp__726) = llvm_cbe_def;
  llvm_cbe_tmp__727 = *(&llvm_cbe_tmp__725);
  llvm_cbe_tmp__728 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__727->field0)) = llvm_cbe_tmp__728;
  return;
}


static void _GLOBAL__I_a(void) {
  __cxx_global_var_init();
  __cxx_global_var_init21();
  return;
}

