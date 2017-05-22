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
struct l_class_OC_model_compute;
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
typedef struct l_class_OC_model_compute l_class_OC_model_compute;
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

struct l_class_OC_model_compute {
  struct l_class_OC_SysCArray1D field0;
  unsigned long long field1;
  unsigned long long field2;
  struct l_class_OC_SysCArray1D field3;
  unsigned long long field4;
  unsigned long long field5;
  unsigned long long field6;
  unsigned long long field7;
  unsigned long long field8;
  unsigned long long field9;
  unsigned long long field10;
  unsigned long long field11;
  unsigned long long field12;
  unsigned long long field13;
  struct l_class_OC_SysCArray1D field14;
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
  unsigned long long field25;
  unsigned long long field26;
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

struct l_unnamed10 { unsigned char array[8]; };

struct l_unnamed11 { unsigned char array[15]; };

struct l_unnamed12 { unsigned char array[10]; };

struct l_unnamed13 { unsigned char array[23]; };

struct l_unnamed14 { unsigned char array[25]; };

struct l_unnamed15 { unsigned char array[21]; };

struct l_unnamed16 { unsigned char array[4]; };

struct l_unnamed17 { unsigned char array[9]; };

struct l_unnamed18 { unsigned char array[5]; };

struct l_unnamed19 { unsigned char array[19]; };

struct l_unnamed2 { unsigned char array[12]; };

struct l_unnamed5 {
  unsigned int field0;
  void  (*field1) (void);
};

struct l_unnamed20 { struct l_unnamed5 array[1]; };

struct l_unnamed7 { unsigned char array[17]; };

struct l_unnamed8 { unsigned char array[18]; };

struct l_unnamed9 { unsigned char array[20]; };


/* External Global Variable Declarations */
extern struct l_class_OC_model_compute GM;
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
extern unsigned int upc;
extern unsigned int rd_complete;
extern struct l_struct_OC_rbm IMPL;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
bool _ZN13model_compute9assumps_0Elllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_class_OC_SysCArray1D _ZN13model_compute18cppUpdateFun_edgesElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN8type_memIhLj65536EEC1ERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
unsigned long long _ZN13model_compute18cppUpdateFun_indexElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_compute23cppUpdateFun_loop_countElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_compute31cppUpdateFun_predict_input_doneElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_compute24cppUpdateFun_rd_completeElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_compute21cppUpdateFun_rd_indexElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_compute22cppUpdateFun_rd_lengthElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_compute23cppUpdateFun_rd_requestElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_compute29cppUpdateFun_train_input_doneElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
unsigned long long _ZN13model_compute16cppUpdateFun_upcElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
void _ZN13model_compute6updateElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant);
struct l_class_OC_SysCArray1D *_ZN8type_memIhLj65536EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
unsigned int __gxx_personality_v0(int vararg_dummy_arg,...);
void _Unwind_Resume_or_Rethrow(unsigned char *);
void _ZN8type_memIhLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZSt9terminatev(void);
static void __cxx_global_var_init(void);
void _ZN13model_computeC1Ev(struct l_class_OC_model_compute *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13model_computeD1Ev(struct l_class_OC_model_compute *llvm_cbe_this) __ATTRIBUTE_WEAK__;
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
void __CPROVER_array_copy(unsigned char *, unsigned char *);
unsigned char *_ZN11SysCArray2DIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
unsigned char *_ZN11SysCArray2DIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) __ATTRIBUTE_WEAK__;
unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void __CPROVER_assert(bool , unsigned char *);
bool __CPROVER_array_equal(unsigned char *, unsigned char *);
void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this);
static void __cxx_global_var_init24(void);
void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) __ATTRIBUTE_WEAK__;
unsigned int main(void);
void _ZN8type_memIhLj65536EEC2ERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) __ATTRIBUTE_WEAK__;
unsigned char *__CPROVER_malloc(unsigned long long );
void _ZN8type_memIhLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
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
void _ZN13model_computeD2Ev(struct l_class_OC_model_compute *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN13model_computeC2Ev(struct l_class_OC_model_compute *llvm_cbe_this) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) __ATTRIBUTE_WEAK__;
static void _GLOBAL__I_a(void) __ATTRIBUTE_CTOR__;
void abort(void);


/* Global Variable Declarations */
extern struct l_class_OC_model_compute GM;
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
extern unsigned int upc;
extern unsigned int rd_complete;
static struct l_unnamed2 _OC_str;
static struct l_unnamed0 _OC_str1;
static struct l_unnamed1 _OC_str2;
static struct l_unnamed7 _OC_str3;
static struct l_unnamed8 _OC_str4;
static struct l_unnamed0 _OC_str5;
static struct l_unnamed0 _OC_str6;
static struct l_unnamed9 _OC_str7;
static struct l_unnamed7 _OC_str8;
static struct l_unnamed11 _OC_str9;
static struct l_unnamed0 _OC_str10;
static struct l_unnamed7 _OC_str11;
static struct l_unnamed7 _OC_str12;
static struct l_unnamed11 _OC_str13;
static struct l_unnamed0 _OC_str14;
static struct l_unnamed11 _OC_str15;
static struct l_unnamed8 _OC_str16;
static struct l_unnamed2 _OC_str17;
static struct l_unnamed7 _OC_str18;
static struct l_unnamed12 _OC_str19;
static struct l_unnamed13 _OC_str20;
static struct l_unnamed14 _OC_str21;
static struct l_unnamed1 _OC_str22;
static struct l_unnamed15 _OC_str23;
extern struct l_struct_OC_rbm IMPL;
static struct l_unnamed16 _OC_str25;
static struct l_unnamed16 _OC_str26;
static struct l_unnamed17 _OC_str27;
static struct l_unnamed12 _OC_str28;
static struct l_unnamed1 _OC_str29;
static struct l_unnamed17 _OC_str30;
static struct l_unnamed10 _OC_str31;
static struct l_unnamed17 _OC_str32;
static struct l_unnamed12 _OC_str33;
static struct l_unnamed1 _OC_str34;
static struct l_unnamed17 _OC_str35;
static struct l_unnamed17 _OC_str36;
static struct l_unnamed18 _OC_str37;
static struct l_unnamed12 _OC_str38;
static struct l_unnamed0 _OC_str39;
static struct l_unnamed7 _OC_str40;
static struct l_unnamed11 _OC_str41;
static struct l_unnamed11 _OC_str42;
static struct l_unnamed19 _OC_str43;
static struct l_unnamed0 _OC_str44;


/* Global Variable Definitions and Initialization */
struct l_class_OC_model_compute GM;
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
unsigned int upc;
unsigned int rd_complete;
static struct l_unnamed2 _OC_str = { "Config done" };
static struct l_unnamed0 _OC_str1 = { "init_done_match" };
static struct l_unnamed1 _OC_str2 = { "done_match" };
static struct l_unnamed7 _OC_str3 = { "num_hidden_match" };
static struct l_unnamed8 _OC_str4 = { "num_visible_match" };
static struct l_unnamed0 _OC_str5 = { "num_users_match" };
static struct l_unnamed0 _OC_str6 = { "num_loops_match" };
static struct l_unnamed9 _OC_str7 = { "num_testusers_match" };
static struct l_unnamed7 _OC_str8 = { "num_movies_match" };
static struct l_unnamed11 _OC_str9 = { "rd_index_match" };
static struct l_unnamed0 _OC_str10 = { "rd_length_match" };
static struct l_unnamed7 _OC_str11 = { "rd_request_match" };
static struct l_unnamed7 _OC_str12 = { "wr_request_match" };
static struct l_unnamed11 _OC_str13 = { "wr_index_match" };
static struct l_unnamed0 _OC_str14 = { "wr_length_match" };
static struct l_unnamed11 _OC_str15 = { "data_out_match" };
static struct l_unnamed8 _OC_str16 = { "rd_complete_match" };
static struct l_unnamed2 _OC_str17 = { "index_match" };
static struct l_unnamed7 _OC_str18 = { "loop_count_match" };
static struct l_unnamed12 _OC_str19 = { "upc_match" };
static struct l_unnamed13 _OC_str20 = { "train_input_done_match" };
static struct l_unnamed14 _OC_str21 = { "predict_input_done_match" };
static struct l_unnamed1 _OC_str22 = { "data_match" };
static struct l_unnamed15 _OC_str23 = { "predict_result_match" };
struct l_struct_OC_rbm IMPL;
static struct l_unnamed16 _OC_str25 = { "clk" };
static struct l_unnamed16 _OC_str26 = { "rst" };
static struct l_unnamed17 _OC_str27 = { "rd_index" };
static struct l_unnamed12 _OC_str28 = { "rd_length" };
static struct l_unnamed1 _OC_str29 = { "rd_request" };
static struct l_unnamed17 _OC_str30 = { "rd_grant" };
static struct l_unnamed10 _OC_str31 = { "data_in" };
static struct l_unnamed17 _OC_str32 = { "wr_index" };
static struct l_unnamed12 _OC_str33 = { "wr_length" };
static struct l_unnamed1 _OC_str34 = { "wr_request" };
static struct l_unnamed17 _OC_str35 = { "wr_grant" };
static struct l_unnamed17 _OC_str36 = { "data_out" };
static struct l_unnamed18 _OC_str37 = { "done" };
static struct l_unnamed12 _OC_str38 = { "cond_done" };
static struct l_unnamed0 _OC_str39 = { "conf_num_hidden" };
static struct l_unnamed7 _OC_str40 = { "conf_num_visible" };
static struct l_unnamed11 _OC_str41 = { "conf_num_users" };
static struct l_unnamed11 _OC_str42 = { "conf_num_loops" };
static struct l_unnamed19 _OC_str43 = { "conf_num_testusers" };
static struct l_unnamed0 _OC_str44 = { "conf_num_movies" };


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

bool _ZN13model_compute9assumps_0Elllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__1;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_cppVar_424;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_425;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_426;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_427;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_428;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__13;
  unsigned long long llvm_cbe_tmp__14;
  unsigned long long llvm_cbe_tmp__15;
  unsigned char llvm_cbe_tmp__16;
  unsigned char llvm_cbe_tmp__17;
  bool llvm_cbe_tmp__18;
  bool llvm_cbe_tmp__19;
  bool llvm_cbe_tmp__19__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__20;

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
  llvm_cbe_tmp__14 = *((&llvm_cbe_tmp__13->field5));
  *(&llvm_cbe_cppVar_425) = (((unsigned char )(bool )(llvm_cbe_tmp__14 == 1ull)));
  llvm_cbe_tmp__15 = *((&llvm_cbe_tmp__13->field2));
  *(&llvm_cbe_cppVar_427) = (((unsigned char )(bool )(llvm_cbe_tmp__15 == 0ull)));
  llvm_cbe_tmp__16 = *(&llvm_cbe_cppVar_425);
  if ((((((bool )llvm_cbe_tmp__16&1u))&1))) {
    goto llvm_cbe_tmp__21;
  } else {
    llvm_cbe_tmp__19__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__22;
  }

llvm_cbe_tmp__21:
  llvm_cbe_tmp__17 = *(&llvm_cbe_cppVar_427);
  llvm_cbe_tmp__18 = ((((bool )llvm_cbe_tmp__17&1u))&1);
  llvm_cbe_tmp__19__PHI_TEMPORARY = llvm_cbe_tmp__18;   /* for PHI node */
  goto llvm_cbe_tmp__22;

llvm_cbe_tmp__22:
  llvm_cbe_tmp__19 = ((llvm_cbe_tmp__19__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_428) = (((unsigned char )(bool )llvm_cbe_tmp__19));
  llvm_cbe_tmp__20 = *(&llvm_cbe_cppVar_428);
  return (((((bool )llvm_cbe_tmp__20&1u))&1));
}


struct l_class_OC_SysCArray1D _ZN13model_compute18cppUpdateFun_edgesElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_SysCArray1D StructReturn;  /* Struct return temporary */
  struct l_class_OC_SysCArray1D *llvm_cbe_agg_2e_result = &StructReturn;
  struct l_class_OC_model_compute *llvm_cbe_tmp__23;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__24;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__25;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__26;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__27;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__28;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__29;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__30;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__31;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__32;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__33;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__34;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__35;

  *(&llvm_cbe_tmp__23) = llvm_cbe_this;
  *(&llvm_cbe_tmp__24) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__25) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__26) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__27) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__28) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__29) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__30) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__31) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__32) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__33) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__34) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__35 = *(&llvm_cbe_tmp__23);
  _ZN8type_memIhLj65536EEC1ERKS0_(llvm_cbe_agg_2e_result, ((&llvm_cbe_tmp__35->field3)));
  return StructReturn;
}


void _ZN8type_memIhLj65536EEC1ERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__36;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__37;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__38;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__39;

  *(&llvm_cbe_tmp__36) = llvm_cbe_this;
  *(&llvm_cbe_tmp__37) = llvm_cbe_r;
  llvm_cbe_tmp__38 = *(&llvm_cbe_tmp__36);
  llvm_cbe_tmp__39 = *(&llvm_cbe_tmp__37);
  _ZN8type_memIhLj65536EEC2ERKS0_(llvm_cbe_tmp__38, llvm_cbe_tmp__39);
  return;
}


unsigned long long _ZN13model_compute18cppUpdateFun_indexElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__40;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__41;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__42;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__43;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__44;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__45;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__46;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__47;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__48;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__49;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__50;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__51;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__52;
  unsigned long long llvm_cbe_tmp__53;

  *(&llvm_cbe_tmp__40) = llvm_cbe_this;
  *(&llvm_cbe_tmp__41) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__42) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__43) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__44) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__45) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__46) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__47) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__48) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__49) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__50) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__51) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__52 = *(&llvm_cbe_tmp__40);
  llvm_cbe_tmp__53 = *((&llvm_cbe_tmp__52->field4));
  return llvm_cbe_tmp__53;
}


unsigned long long _ZN13model_compute23cppUpdateFun_loop_countElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__54;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__55;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__56;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__57;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__58;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__59;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__60;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__61;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__62;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__63;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__64;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__65;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__66;
  unsigned long long llvm_cbe_tmp__67;

  *(&llvm_cbe_tmp__54) = llvm_cbe_this;
  *(&llvm_cbe_tmp__55) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__56) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__57) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__58) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__59) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__60) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__61) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__62) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__63) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__64) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__65) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__66 = *(&llvm_cbe_tmp__54);
  llvm_cbe_tmp__67 = *((&llvm_cbe_tmp__66->field6));
  return llvm_cbe_tmp__67;
}


unsigned long long _ZN13model_compute31cppUpdateFun_predict_input_doneElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__68;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__69;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__70;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__71;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__72;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__73;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__74;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__75;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__76;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__77;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__78;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__79;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_340;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_341;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_342;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_343;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_344;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_346;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_345;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_339;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_348;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_347;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__80;
  unsigned long long llvm_cbe_tmp__81;
  unsigned long long llvm_cbe_tmp__82;
  unsigned char llvm_cbe_tmp__83;
  unsigned char llvm_cbe_tmp__84;
  bool llvm_cbe_tmp__85;
  bool llvm_cbe_tmp__86;
  bool llvm_cbe_tmp__86__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__87;
  unsigned long long llvm_cbe_tmp__88;
  unsigned long long llvm_cbe_tmp__89;
  unsigned char llvm_cbe_tmp__90;
  unsigned long long llvm_cbe_tmp__91;
  unsigned long long llvm_cbe_tmp__92;
  unsigned long long llvm_cbe_tmp__93;

  *(&llvm_cbe_tmp__68) = llvm_cbe_this;
  *(&llvm_cbe_tmp__69) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__70) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__71) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__72) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__73) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__74) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__75) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__76) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__77) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__78) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__79) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__80 = *(&llvm_cbe_tmp__68);
  llvm_cbe_tmp__81 = *((&llvm_cbe_tmp__80->field20));
  *(&llvm_cbe_cppVar_341) = (((unsigned char )(bool )(llvm_cbe_tmp__81 == 1ull)));
  llvm_cbe_tmp__82 = *((&llvm_cbe_tmp__80->field15));
  *(&llvm_cbe_cppVar_343) = (((unsigned char )(bool )(llvm_cbe_tmp__82 == 1ull)));
  llvm_cbe_tmp__83 = *(&llvm_cbe_cppVar_341);
  if ((((((bool )llvm_cbe_tmp__83&1u))&1))) {
    goto llvm_cbe_tmp__94;
  } else {
    llvm_cbe_tmp__86__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__95;
  }

llvm_cbe_tmp__94:
  llvm_cbe_tmp__84 = *(&llvm_cbe_cppVar_343);
  llvm_cbe_tmp__85 = ((((bool )llvm_cbe_tmp__84&1u))&1);
  llvm_cbe_tmp__86__PHI_TEMPORARY = llvm_cbe_tmp__85;   /* for PHI node */
  goto llvm_cbe_tmp__95;

llvm_cbe_tmp__95:
  llvm_cbe_tmp__86 = ((llvm_cbe_tmp__86__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_344) = (((unsigned char )(bool )llvm_cbe_tmp__86));
  llvm_cbe_tmp__87 = *(&llvm_cbe_cppVar_344);
  if ((((((bool )llvm_cbe_tmp__87&1u))&1))) {
    goto llvm_cbe_tmp__96;
  } else {
    goto llvm_cbe_tmp__97;
  }

llvm_cbe_tmp__96:
  llvm_cbe_tmp__88 = *((&llvm_cbe_tmp__80->field6));
  llvm_cbe_tmp__89 = *((&llvm_cbe_tmp__80->field8));
  *(&llvm_cbe_cppVar_346) = (((unsigned char )(bool )(llvm_cbe_tmp__88 == llvm_cbe_tmp__89)));
  llvm_cbe_tmp__90 = *(&llvm_cbe_cppVar_346);
  if ((((((bool )llvm_cbe_tmp__90&1u))&1))) {
    goto llvm_cbe_tmp__98;
  } else {
    goto llvm_cbe_tmp__99;
  }

llvm_cbe_tmp__98:
  *(&llvm_cbe_cppVar_345) = 1ull;
  goto llvm_cbe_tmp__100;

llvm_cbe_tmp__99:
  *(&llvm_cbe_cppVar_345) = 0ull;
  goto llvm_cbe_tmp__100;

llvm_cbe_tmp__100:
  llvm_cbe_tmp__91 = *(&llvm_cbe_cppVar_345);
  *(&llvm_cbe_cppVar_339) = llvm_cbe_tmp__91;
  goto llvm_cbe_tmp__101;

llvm_cbe_tmp__97:
  llvm_cbe_tmp__92 = *((&llvm_cbe_tmp__80->field13));
  *(&llvm_cbe_cppVar_339) = llvm_cbe_tmp__92;
  goto llvm_cbe_tmp__101;

llvm_cbe_tmp__101:
  llvm_cbe_tmp__93 = *(&llvm_cbe_cppVar_339);
  return llvm_cbe_tmp__93;
}


unsigned long long _ZN13model_compute24cppUpdateFun_rd_completeElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__102;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_cppVar_355;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_356;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_357;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_358;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_359;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_354;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_350;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_353;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_351;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_352;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__114;
  unsigned long long llvm_cbe_tmp__115;
  unsigned char llvm_cbe_tmp__116;
  unsigned long long llvm_cbe_tmp__117;
  unsigned long long llvm_cbe_tmp__118;
  unsigned char llvm_cbe_tmp__119;
  unsigned char llvm_cbe_tmp__120;
  bool llvm_cbe_tmp__121;
  bool llvm_cbe_tmp__122;
  bool llvm_cbe_tmp__122__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__123;
  unsigned long long llvm_cbe_tmp__124;
  unsigned long long llvm_cbe_tmp__125;
  unsigned long long llvm_cbe_tmp__126;

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
  llvm_cbe_tmp__115 = *((&llvm_cbe_tmp__114->field20));
  *(&llvm_cbe_cppVar_352) = (((unsigned char )(bool )(llvm_cbe_tmp__115 == 0ull)));
  llvm_cbe_tmp__116 = *(&llvm_cbe_cppVar_352);
  if ((((((bool )llvm_cbe_tmp__116&1u))&1))) {
    goto llvm_cbe_tmp__127;
  } else {
    goto llvm_cbe_tmp__128;
  }

llvm_cbe_tmp__127:
  *(&llvm_cbe_cppVar_350) = 0ull;
  goto llvm_cbe_tmp__129;

llvm_cbe_tmp__128:
  llvm_cbe_tmp__117 = *((&llvm_cbe_tmp__114->field20));
  *(&llvm_cbe_cppVar_356) = (((unsigned char )(bool )(llvm_cbe_tmp__117 == 1ull)));
  llvm_cbe_tmp__118 = *((&llvm_cbe_tmp__114->field15));
  *(&llvm_cbe_cppVar_358) = (((unsigned char )(bool )(llvm_cbe_tmp__118 == 1ull)));
  llvm_cbe_tmp__119 = *(&llvm_cbe_cppVar_356);
  if ((((((bool )llvm_cbe_tmp__119&1u))&1))) {
    goto llvm_cbe_tmp__130;
  } else {
    llvm_cbe_tmp__122__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__131;
  }

llvm_cbe_tmp__130:
  llvm_cbe_tmp__120 = *(&llvm_cbe_cppVar_358);
  llvm_cbe_tmp__121 = ((((bool )llvm_cbe_tmp__120&1u))&1);
  llvm_cbe_tmp__122__PHI_TEMPORARY = llvm_cbe_tmp__121;   /* for PHI node */
  goto llvm_cbe_tmp__131;

llvm_cbe_tmp__131:
  llvm_cbe_tmp__122 = ((llvm_cbe_tmp__122__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_359) = (((unsigned char )(bool )llvm_cbe_tmp__122));
  llvm_cbe_tmp__123 = *(&llvm_cbe_cppVar_359);
  if ((((((bool )llvm_cbe_tmp__123&1u))&1))) {
    goto llvm_cbe_tmp__132;
  } else {
    goto llvm_cbe_tmp__133;
  }

llvm_cbe_tmp__132:
  *(&llvm_cbe_cppVar_354) = 0ull;
  goto llvm_cbe_tmp__134;

llvm_cbe_tmp__133:
  llvm_cbe_tmp__124 = *((&llvm_cbe_tmp__114->field15));
  *(&llvm_cbe_cppVar_354) = llvm_cbe_tmp__124;
  goto llvm_cbe_tmp__134;

llvm_cbe_tmp__134:
  llvm_cbe_tmp__125 = *(&llvm_cbe_cppVar_354);
  *(&llvm_cbe_cppVar_350) = llvm_cbe_tmp__125;
  goto llvm_cbe_tmp__129;

llvm_cbe_tmp__129:
  llvm_cbe_tmp__126 = *(&llvm_cbe_cppVar_350);
  return llvm_cbe_tmp__126;
}


unsigned long long _ZN13model_compute21cppUpdateFun_rd_indexElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__135;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__136;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__137;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__138;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__139;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__140;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__141;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__142;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__143;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__144;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__145;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__146;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_364;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_361;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_362;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_363;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__147;
  unsigned long long llvm_cbe_tmp__148;
  unsigned char llvm_cbe_tmp__149;
  unsigned long long llvm_cbe_tmp__150;
  unsigned long long llvm_cbe_tmp__151;
  unsigned long long llvm_cbe_tmp__152;
  unsigned long long llvm_cbe_tmp__153;
  unsigned long long llvm_cbe_tmp__154;

  *(&llvm_cbe_tmp__135) = llvm_cbe_this;
  *(&llvm_cbe_tmp__136) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__137) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__138) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__139) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__140) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__141) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__142) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__143) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__144) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__145) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__146) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__147 = *(&llvm_cbe_tmp__135);
  llvm_cbe_tmp__148 = *((&llvm_cbe_tmp__147->field20));
  *(&llvm_cbe_cppVar_363) = (((unsigned char )(bool )(llvm_cbe_tmp__148 == 0ull)));
  llvm_cbe_tmp__149 = *(&llvm_cbe_cppVar_363);
  if ((((((bool )llvm_cbe_tmp__149&1u))&1))) {
    goto llvm_cbe_tmp__155;
  } else {
    goto llvm_cbe_tmp__156;
  }

llvm_cbe_tmp__155:
  llvm_cbe_tmp__150 = *((&llvm_cbe_tmp__147->field4));
  llvm_cbe_tmp__151 = *((&llvm_cbe_tmp__147->field25));
  *(&llvm_cbe_cppVar_364) = (llvm_cbe_tmp__150 & llvm_cbe_tmp__151);
  llvm_cbe_tmp__152 = *(&llvm_cbe_cppVar_364);
  *(&llvm_cbe_cppVar_361) = llvm_cbe_tmp__152;
  goto llvm_cbe_tmp__157;

llvm_cbe_tmp__156:
  llvm_cbe_tmp__153 = *((&llvm_cbe_tmp__147->field16));
  *(&llvm_cbe_cppVar_361) = llvm_cbe_tmp__153;
  goto llvm_cbe_tmp__157;

llvm_cbe_tmp__157:
  llvm_cbe_tmp__154 = *(&llvm_cbe_cppVar_361);
  return llvm_cbe_tmp__154;
}


unsigned long long _ZN13model_compute22cppUpdateFun_rd_lengthElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__158;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__159;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__160;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__161;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__162;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__163;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__164;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__165;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__166;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__167;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__168;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__169;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_369;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_371;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_366;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_370;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_367;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_368;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__170;
  unsigned long long llvm_cbe_tmp__171;
  unsigned char llvm_cbe_tmp__172;
  unsigned long long llvm_cbe_tmp__173;
  unsigned long long llvm_cbe_tmp__174;
  unsigned long long llvm_cbe_tmp__175;
  unsigned long long llvm_cbe_tmp__176;
  unsigned long long llvm_cbe_tmp__177;
  unsigned long long llvm_cbe_tmp__178;
  unsigned long long llvm_cbe_tmp__179;
  unsigned long long llvm_cbe_tmp__180;

  *(&llvm_cbe_tmp__158) = llvm_cbe_this;
  *(&llvm_cbe_tmp__159) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__160) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__161) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__162) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__163) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__164) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__165) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__166) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__167) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__168) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__169) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__170 = *(&llvm_cbe_tmp__158);
  llvm_cbe_tmp__171 = *((&llvm_cbe_tmp__170->field20));
  *(&llvm_cbe_cppVar_368) = (((unsigned char )(bool )(llvm_cbe_tmp__171 == 0ull)));
  llvm_cbe_tmp__172 = *(&llvm_cbe_cppVar_368);
  if ((((((bool )llvm_cbe_tmp__172&1u))&1))) {
    goto llvm_cbe_tmp__181;
  } else {
    goto llvm_cbe_tmp__182;
  }

llvm_cbe_tmp__181:
  llvm_cbe_tmp__173 = *((&llvm_cbe_tmp__170->field9));
  llvm_cbe_tmp__174 = *((&llvm_cbe_tmp__170->field25));
  *(&llvm_cbe_cppVar_370) = (llvm_cbe_tmp__173 & llvm_cbe_tmp__174);
  llvm_cbe_tmp__175 = *(&llvm_cbe_cppVar_370);
  *(&llvm_cbe_cppVar_371) = (((unsigned long long )(((unsigned long long )5ull) * ((unsigned long long )llvm_cbe_tmp__175))));
  llvm_cbe_tmp__176 = *(&llvm_cbe_cppVar_371);
  llvm_cbe_tmp__177 = *((&llvm_cbe_tmp__170->field26));
  *(&llvm_cbe_cppVar_371) = (llvm_cbe_tmp__176 & llvm_cbe_tmp__177);
  llvm_cbe_tmp__178 = *(&llvm_cbe_cppVar_371);
  *(&llvm_cbe_cppVar_366) = llvm_cbe_tmp__178;
  goto llvm_cbe_tmp__183;

llvm_cbe_tmp__182:
  llvm_cbe_tmp__179 = *((&llvm_cbe_tmp__170->field17));
  *(&llvm_cbe_cppVar_366) = llvm_cbe_tmp__179;
  goto llvm_cbe_tmp__183;

llvm_cbe_tmp__183:
  llvm_cbe_tmp__180 = *(&llvm_cbe_cppVar_366);
  return llvm_cbe_tmp__180;
}


unsigned long long _ZN13model_compute23cppUpdateFun_rd_requestElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__184;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__185;    /* Address-exposed local */
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
  unsigned long long llvm_cbe_cppVar_373;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_376;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_374;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_375;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__196;
  unsigned long long llvm_cbe_tmp__197;
  unsigned char llvm_cbe_tmp__198;
  unsigned long long llvm_cbe_tmp__199;
  unsigned long long llvm_cbe_tmp__200;

  *(&llvm_cbe_tmp__184) = llvm_cbe_this;
  *(&llvm_cbe_tmp__185) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__186) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__187) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__188) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__189) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__190) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__191) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__192) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__193) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__194) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__195) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__196 = *(&llvm_cbe_tmp__184);
  llvm_cbe_tmp__197 = *((&llvm_cbe_tmp__196->field20));
  *(&llvm_cbe_cppVar_375) = (((unsigned char )(bool )(llvm_cbe_tmp__197 == 0ull)));
  llvm_cbe_tmp__198 = *(&llvm_cbe_cppVar_375);
  if ((((((bool )llvm_cbe_tmp__198&1u))&1))) {
    goto llvm_cbe_tmp__201;
  } else {
    goto llvm_cbe_tmp__202;
  }

llvm_cbe_tmp__201:
  *(&llvm_cbe_cppVar_373) = 1ull;
  goto llvm_cbe_tmp__203;

llvm_cbe_tmp__202:
  llvm_cbe_tmp__199 = *((&llvm_cbe_tmp__196->field18));
  *(&llvm_cbe_cppVar_373) = llvm_cbe_tmp__199;
  goto llvm_cbe_tmp__203;

llvm_cbe_tmp__203:
  llvm_cbe_tmp__200 = *(&llvm_cbe_cppVar_373);
  return llvm_cbe_tmp__200;
}


unsigned long long _ZN13model_compute29cppUpdateFun_train_input_doneElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__204;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__205;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__206;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__207;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__208;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__209;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__210;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__211;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__212;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__213;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__214;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__215;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_379;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_380;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_381;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_382;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_383;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_385;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_384;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_378;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_387;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_386;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__216;
  unsigned long long llvm_cbe_tmp__217;
  unsigned long long llvm_cbe_tmp__218;
  unsigned char llvm_cbe_tmp__219;
  unsigned char llvm_cbe_tmp__220;
  bool llvm_cbe_tmp__221;
  bool llvm_cbe_tmp__222;
  bool llvm_cbe_tmp__222__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__223;
  unsigned long long llvm_cbe_tmp__224;
  unsigned long long llvm_cbe_tmp__225;
  unsigned char llvm_cbe_tmp__226;
  unsigned long long llvm_cbe_tmp__227;
  unsigned long long llvm_cbe_tmp__228;
  unsigned long long llvm_cbe_tmp__229;

  *(&llvm_cbe_tmp__204) = llvm_cbe_this;
  *(&llvm_cbe_tmp__205) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__206) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__207) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__208) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__209) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__210) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__211) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__212) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__213) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__214) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__215) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__216 = *(&llvm_cbe_tmp__204);
  llvm_cbe_tmp__217 = *((&llvm_cbe_tmp__216->field20));
  *(&llvm_cbe_cppVar_380) = (((unsigned char )(bool )(llvm_cbe_tmp__217 == 1ull)));
  llvm_cbe_tmp__218 = *((&llvm_cbe_tmp__216->field15));
  *(&llvm_cbe_cppVar_382) = (((unsigned char )(bool )(llvm_cbe_tmp__218 == 1ull)));
  llvm_cbe_tmp__219 = *(&llvm_cbe_cppVar_380);
  if ((((((bool )llvm_cbe_tmp__219&1u))&1))) {
    goto llvm_cbe_tmp__230;
  } else {
    llvm_cbe_tmp__222__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__231;
  }

llvm_cbe_tmp__230:
  llvm_cbe_tmp__220 = *(&llvm_cbe_cppVar_382);
  llvm_cbe_tmp__221 = ((((bool )llvm_cbe_tmp__220&1u))&1);
  llvm_cbe_tmp__222__PHI_TEMPORARY = llvm_cbe_tmp__221;   /* for PHI node */
  goto llvm_cbe_tmp__231;

llvm_cbe_tmp__231:
  llvm_cbe_tmp__222 = ((llvm_cbe_tmp__222__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_383) = (((unsigned char )(bool )llvm_cbe_tmp__222));
  llvm_cbe_tmp__223 = *(&llvm_cbe_cppVar_383);
  if ((((((bool )llvm_cbe_tmp__223&1u))&1))) {
    goto llvm_cbe_tmp__232;
  } else {
    goto llvm_cbe_tmp__233;
  }

llvm_cbe_tmp__232:
  llvm_cbe_tmp__224 = *((&llvm_cbe_tmp__216->field6));
  llvm_cbe_tmp__225 = *((&llvm_cbe_tmp__216->field8));
  *(&llvm_cbe_cppVar_385) = (((unsigned char )(bool )(((signed long long )llvm_cbe_tmp__224) < ((signed long long )llvm_cbe_tmp__225))));
  llvm_cbe_tmp__226 = *(&llvm_cbe_cppVar_385);
  if ((((((bool )llvm_cbe_tmp__226&1u))&1))) {
    goto llvm_cbe_tmp__234;
  } else {
    goto llvm_cbe_tmp__235;
  }

llvm_cbe_tmp__234:
  *(&llvm_cbe_cppVar_384) = 1ull;
  goto llvm_cbe_tmp__236;

llvm_cbe_tmp__235:
  *(&llvm_cbe_cppVar_384) = 0ull;
  goto llvm_cbe_tmp__236;

llvm_cbe_tmp__236:
  llvm_cbe_tmp__227 = *(&llvm_cbe_cppVar_384);
  *(&llvm_cbe_cppVar_378) = llvm_cbe_tmp__227;
  goto llvm_cbe_tmp__237;

llvm_cbe_tmp__233:
  llvm_cbe_tmp__228 = *((&llvm_cbe_tmp__216->field19));
  *(&llvm_cbe_cppVar_378) = llvm_cbe_tmp__228;
  goto llvm_cbe_tmp__237;

llvm_cbe_tmp__237:
  llvm_cbe_tmp__229 = *(&llvm_cbe_cppVar_378);
  return llvm_cbe_tmp__229;
}


unsigned long long _ZN13model_compute16cppUpdateFun_upcElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__238;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__239;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__240;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__241;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__242;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__243;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__244;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__245;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__246;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__247;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__248;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__249;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_394;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_395;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_396;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_397;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_398;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_400;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_401;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_402;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_403;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_404;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_407;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_408;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_409;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_410;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_411;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_413;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_414;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_415;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_416;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_417;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_419;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_420;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_392;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_405;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_421;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_418;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_412;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_406;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_399;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_393;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_389;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_390;    /* Address-exposed local */
  unsigned char llvm_cbe_cppVar_391;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__250;
  unsigned long long llvm_cbe_tmp__251;
  unsigned char llvm_cbe_tmp__252;
  unsigned long long llvm_cbe_tmp__253;
  unsigned long long llvm_cbe_tmp__254;
  unsigned char llvm_cbe_tmp__255;
  unsigned char llvm_cbe_tmp__256;
  bool llvm_cbe_tmp__257;
  bool llvm_cbe_tmp__258;
  bool llvm_cbe_tmp__258__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__259;
  unsigned long long llvm_cbe_tmp__260;
  unsigned long long llvm_cbe_tmp__261;
  unsigned char llvm_cbe_tmp__262;
  unsigned char llvm_cbe_tmp__263;
  bool llvm_cbe_tmp__264;
  bool llvm_cbe_tmp__265;
  bool llvm_cbe_tmp__265__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__266;
  unsigned long long llvm_cbe_tmp__267;
  unsigned long long llvm_cbe_tmp__268;
  unsigned char llvm_cbe_tmp__269;
  unsigned char llvm_cbe_tmp__270;
  bool llvm_cbe_tmp__271;
  bool llvm_cbe_tmp__272;
  bool llvm_cbe_tmp__272__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__273;
  unsigned long long llvm_cbe_tmp__274;
  unsigned long long llvm_cbe_tmp__275;
  unsigned char llvm_cbe_tmp__276;
  unsigned char llvm_cbe_tmp__277;
  bool llvm_cbe_tmp__278;
  bool llvm_cbe_tmp__279;
  bool llvm_cbe_tmp__279__PHI_TEMPORARY;
  unsigned char llvm_cbe_tmp__280;
  unsigned long long llvm_cbe_tmp__281;
  unsigned char llvm_cbe_tmp__282;
  unsigned long long llvm_cbe_tmp__283;
  unsigned long long llvm_cbe_tmp__284;
  unsigned long long llvm_cbe_tmp__285;
  unsigned long long llvm_cbe_tmp__286;
  unsigned long long llvm_cbe_tmp__287;
  unsigned long long llvm_cbe_tmp__288;
  unsigned long long llvm_cbe_tmp__289;

  *(&llvm_cbe_tmp__238) = llvm_cbe_this;
  *(&llvm_cbe_tmp__239) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__240) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__241) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__242) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__243) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__244) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__245) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__246) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__247) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__248) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__249) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__250 = *(&llvm_cbe_tmp__238);
  llvm_cbe_tmp__251 = *((&llvm_cbe_tmp__250->field20));
  *(&llvm_cbe_cppVar_391) = (((unsigned char )(bool )(llvm_cbe_tmp__251 == 0ull)));
  llvm_cbe_tmp__252 = *(&llvm_cbe_cppVar_391);
  if ((((((bool )llvm_cbe_tmp__252&1u))&1))) {
    goto llvm_cbe_tmp__290;
  } else {
    goto llvm_cbe_tmp__291;
  }

llvm_cbe_tmp__290:
  *(&llvm_cbe_cppVar_389) = 1ull;
  goto llvm_cbe_tmp__292;

llvm_cbe_tmp__291:
  llvm_cbe_tmp__253 = *((&llvm_cbe_tmp__250->field20));
  *(&llvm_cbe_cppVar_395) = (((unsigned char )(bool )(llvm_cbe_tmp__253 == 1ull)));
  llvm_cbe_tmp__254 = *((&llvm_cbe_tmp__250->field15));
  *(&llvm_cbe_cppVar_397) = (((unsigned char )(bool )(llvm_cbe_tmp__254 == 0ull)));
  llvm_cbe_tmp__255 = *(&llvm_cbe_cppVar_395);
  if ((((((bool )llvm_cbe_tmp__255&1u))&1))) {
    goto llvm_cbe_tmp__293;
  } else {
    llvm_cbe_tmp__258__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__294;
  }

llvm_cbe_tmp__293:
  llvm_cbe_tmp__256 = *(&llvm_cbe_cppVar_397);
  llvm_cbe_tmp__257 = ((((bool )llvm_cbe_tmp__256&1u))&1);
  llvm_cbe_tmp__258__PHI_TEMPORARY = llvm_cbe_tmp__257;   /* for PHI node */
  goto llvm_cbe_tmp__294;

llvm_cbe_tmp__294:
  llvm_cbe_tmp__258 = ((llvm_cbe_tmp__258__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_398) = (((unsigned char )(bool )llvm_cbe_tmp__258));
  llvm_cbe_tmp__259 = *(&llvm_cbe_cppVar_398);
  llvm_cbe_tmp__260 = *((&llvm_cbe_tmp__250->field20));
  if ((((((bool )llvm_cbe_tmp__259&1u))&1))) {
    goto llvm_cbe_tmp__295;
  } else {
    goto llvm_cbe_tmp__296;
  }

llvm_cbe_tmp__295:
  *(&llvm_cbe_cppVar_393) = llvm_cbe_tmp__260;
  goto llvm_cbe_tmp__297;

llvm_cbe_tmp__296:
  *(&llvm_cbe_cppVar_401) = (((unsigned char )(bool )(llvm_cbe_tmp__260 == 1ull)));
  llvm_cbe_tmp__261 = *((&llvm_cbe_tmp__250->field15));
  *(&llvm_cbe_cppVar_403) = (((unsigned char )(bool )(llvm_cbe_tmp__261 == 1ull)));
  llvm_cbe_tmp__262 = *(&llvm_cbe_cppVar_401);
  if ((((((bool )llvm_cbe_tmp__262&1u))&1))) {
    goto llvm_cbe_tmp__298;
  } else {
    llvm_cbe_tmp__265__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__299;
  }

llvm_cbe_tmp__298:
  llvm_cbe_tmp__263 = *(&llvm_cbe_cppVar_403);
  llvm_cbe_tmp__264 = ((((bool )llvm_cbe_tmp__263&1u))&1);
  llvm_cbe_tmp__265__PHI_TEMPORARY = llvm_cbe_tmp__264;   /* for PHI node */
  goto llvm_cbe_tmp__299;

llvm_cbe_tmp__299:
  llvm_cbe_tmp__265 = ((llvm_cbe_tmp__265__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_404) = (((unsigned char )(bool )llvm_cbe_tmp__265));
  llvm_cbe_tmp__266 = *(&llvm_cbe_cppVar_404);
  if ((((((bool )llvm_cbe_tmp__266&1u))&1))) {
    goto llvm_cbe_tmp__300;
  } else {
    goto llvm_cbe_tmp__301;
  }

llvm_cbe_tmp__300:
  *(&llvm_cbe_cppVar_399) = 2ull;
  goto llvm_cbe_tmp__302;

llvm_cbe_tmp__301:
  llvm_cbe_tmp__267 = *((&llvm_cbe_tmp__250->field20));
  *(&llvm_cbe_cppVar_408) = (((unsigned char )(bool )(llvm_cbe_tmp__267 == 2ull)));
  llvm_cbe_tmp__268 = *((&llvm_cbe_tmp__250->field19));
  *(&llvm_cbe_cppVar_410) = (((unsigned char )(bool )(llvm_cbe_tmp__268 == 1ull)));
  llvm_cbe_tmp__269 = *(&llvm_cbe_cppVar_408);
  if ((((((bool )llvm_cbe_tmp__269&1u))&1))) {
    goto llvm_cbe_tmp__303;
  } else {
    llvm_cbe_tmp__272__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__304;
  }

llvm_cbe_tmp__303:
  llvm_cbe_tmp__270 = *(&llvm_cbe_cppVar_410);
  llvm_cbe_tmp__271 = ((((bool )llvm_cbe_tmp__270&1u))&1);
  llvm_cbe_tmp__272__PHI_TEMPORARY = llvm_cbe_tmp__271;   /* for PHI node */
  goto llvm_cbe_tmp__304;

llvm_cbe_tmp__304:
  llvm_cbe_tmp__272 = ((llvm_cbe_tmp__272__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_411) = (((unsigned char )(bool )llvm_cbe_tmp__272));
  llvm_cbe_tmp__273 = *(&llvm_cbe_cppVar_411);
  if ((((((bool )llvm_cbe_tmp__273&1u))&1))) {
    goto llvm_cbe_tmp__305;
  } else {
    goto llvm_cbe_tmp__306;
  }

llvm_cbe_tmp__305:
  *(&llvm_cbe_cppVar_406) = 2ull;
  goto llvm_cbe_tmp__307;

llvm_cbe_tmp__306:
  llvm_cbe_tmp__274 = *((&llvm_cbe_tmp__250->field20));
  *(&llvm_cbe_cppVar_414) = (((unsigned char )(bool )(llvm_cbe_tmp__274 == 2ull)));
  llvm_cbe_tmp__275 = *((&llvm_cbe_tmp__250->field13));
  *(&llvm_cbe_cppVar_416) = (((unsigned char )(bool )(llvm_cbe_tmp__275 == 1ull)));
  llvm_cbe_tmp__276 = *(&llvm_cbe_cppVar_414);
  if ((((((bool )llvm_cbe_tmp__276&1u))&1))) {
    goto llvm_cbe_tmp__308;
  } else {
    llvm_cbe_tmp__279__PHI_TEMPORARY = 0;   /* for PHI node */
    goto llvm_cbe_tmp__309;
  }

llvm_cbe_tmp__308:
  llvm_cbe_tmp__277 = *(&llvm_cbe_cppVar_416);
  llvm_cbe_tmp__278 = ((((bool )llvm_cbe_tmp__277&1u))&1);
  llvm_cbe_tmp__279__PHI_TEMPORARY = llvm_cbe_tmp__278;   /* for PHI node */
  goto llvm_cbe_tmp__309;

llvm_cbe_tmp__309:
  llvm_cbe_tmp__279 = ((llvm_cbe_tmp__279__PHI_TEMPORARY)&1);
  *(&llvm_cbe_cppVar_417) = (((unsigned char )(bool )llvm_cbe_tmp__279));
  llvm_cbe_tmp__280 = *(&llvm_cbe_cppVar_417);
  if ((((((bool )llvm_cbe_tmp__280&1u))&1))) {
    goto llvm_cbe_tmp__310;
  } else {
    goto llvm_cbe_tmp__311;
  }

llvm_cbe_tmp__310:
  *(&llvm_cbe_cppVar_412) = 2ull;
  goto llvm_cbe_tmp__312;

llvm_cbe_tmp__311:
  llvm_cbe_tmp__281 = *((&llvm_cbe_tmp__250->field20));
  *(&llvm_cbe_cppVar_420) = (((unsigned char )(bool )(llvm_cbe_tmp__281 == 3ull)));
  llvm_cbe_tmp__282 = *(&llvm_cbe_cppVar_420);
  if ((((((bool )llvm_cbe_tmp__282&1u))&1))) {
    goto llvm_cbe_tmp__313;
  } else {
    goto llvm_cbe_tmp__314;
  }

llvm_cbe_tmp__313:
  *(&llvm_cbe_cppVar_418) = 3ull;
  goto llvm_cbe_tmp__315;

llvm_cbe_tmp__314:
  llvm_cbe_tmp__283 = *((&llvm_cbe_tmp__250->field20));
  *(&llvm_cbe_cppVar_418) = llvm_cbe_tmp__283;
  goto llvm_cbe_tmp__315;

llvm_cbe_tmp__315:
  llvm_cbe_tmp__284 = *(&llvm_cbe_cppVar_418);
  *(&llvm_cbe_cppVar_412) = llvm_cbe_tmp__284;
  goto llvm_cbe_tmp__312;

llvm_cbe_tmp__312:
  llvm_cbe_tmp__285 = *(&llvm_cbe_cppVar_412);
  *(&llvm_cbe_cppVar_406) = llvm_cbe_tmp__285;
  goto llvm_cbe_tmp__307;

llvm_cbe_tmp__307:
  llvm_cbe_tmp__286 = *(&llvm_cbe_cppVar_406);
  *(&llvm_cbe_cppVar_399) = llvm_cbe_tmp__286;
  goto llvm_cbe_tmp__302;

llvm_cbe_tmp__302:
  llvm_cbe_tmp__287 = *(&llvm_cbe_cppVar_399);
  *(&llvm_cbe_cppVar_393) = llvm_cbe_tmp__287;
  goto llvm_cbe_tmp__297;

llvm_cbe_tmp__297:
  llvm_cbe_tmp__288 = *(&llvm_cbe_cppVar_393);
  *(&llvm_cbe_cppVar_389) = llvm_cbe_tmp__288;
  goto llvm_cbe_tmp__292;

llvm_cbe_tmp__292:
  llvm_cbe_tmp__289 = *(&llvm_cbe_cppVar_389);
  return llvm_cbe_tmp__289;
}


void _ZN13model_compute6updateElllllllllll(struct l_class_OC_model_compute *llvm_cbe_this, unsigned long long llvm_cbe_conf_done, unsigned long long llvm_cbe_conf_num_hidden, unsigned long long llvm_cbe_conf_num_loops, unsigned long long llvm_cbe_conf_num_movies, unsigned long long llvm_cbe_conf_num_testusers, unsigned long long llvm_cbe_conf_num_users, unsigned long long llvm_cbe_conf_num_visible, unsigned long long llvm_cbe_data_in, unsigned long long llvm_cbe_rd_grant, unsigned long long llvm_cbe_rst, unsigned long long llvm_cbe_wr_grant) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__316;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__317;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__318;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__319;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__320;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__321;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__322;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__323;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__324;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__325;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__326;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__327;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_337;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_338;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_349;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_360;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_365;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_372;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_377;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_388;    /* Address-exposed local */
  unsigned long long llvm_cbe_cppVar_422;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D llvm_cbe_cppVar_423;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__328;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__329;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__330;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__331;
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
  unsigned long long llvm_cbe_tmp__342;
  unsigned long long llvm_cbe_tmp__343;
  unsigned long long llvm_cbe_tmp__344;
  unsigned long long llvm_cbe_tmp__345;
  unsigned long long llvm_cbe_tmp__346;
  unsigned long long llvm_cbe_tmp__347;
  unsigned long long llvm_cbe_tmp__348;
  unsigned long long llvm_cbe_tmp__349;
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
  unsigned long long llvm_cbe_tmp__379;
  unsigned long long llvm_cbe_tmp__380;
  unsigned long long llvm_cbe_tmp__381;
  unsigned long long llvm_cbe_tmp__382;
  unsigned long long llvm_cbe_tmp__383;
  unsigned long long llvm_cbe_tmp__384;
  unsigned long long llvm_cbe_tmp__385;
  unsigned long long llvm_cbe_tmp__386;
  unsigned long long llvm_cbe_tmp__387;
  unsigned long long llvm_cbe_tmp__388;
  unsigned long long llvm_cbe_tmp__389;
  unsigned long long llvm_cbe_tmp__390;
  unsigned long long llvm_cbe_tmp__391;
  unsigned long long llvm_cbe_tmp__392;
  unsigned long long llvm_cbe_tmp__393;
  unsigned long long llvm_cbe_tmp__394;
  unsigned long long llvm_cbe_tmp__395;
  unsigned long long llvm_cbe_tmp__396;
  unsigned long long llvm_cbe_tmp__397;
  unsigned long long llvm_cbe_tmp__398;
  unsigned long long llvm_cbe_tmp__399;
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
  unsigned long long llvm_cbe_tmp__411;
  unsigned long long llvm_cbe_tmp__412;
  unsigned long long llvm_cbe_tmp__413;
  unsigned long long llvm_cbe_tmp__414;
  unsigned long long llvm_cbe_tmp__415;
  unsigned long long llvm_cbe_tmp__416;
  unsigned long long llvm_cbe_tmp__417;
  unsigned long long llvm_cbe_tmp__418;
  unsigned long long llvm_cbe_tmp__419;
  unsigned long long llvm_cbe_tmp__420;
  unsigned long long llvm_cbe_tmp__421;
  unsigned long long llvm_cbe_tmp__422;
  unsigned long long llvm_cbe_tmp__423;
  unsigned long long llvm_cbe_tmp__424;
  unsigned long long llvm_cbe_tmp__425;
  unsigned long long llvm_cbe_tmp__426;
  unsigned long long llvm_cbe_tmp__427;
  unsigned long long llvm_cbe_tmp__428;
  unsigned long long llvm_cbe_tmp__429;
  unsigned long long llvm_cbe_tmp__430;
  unsigned long long llvm_cbe_tmp__431;
  unsigned long long llvm_cbe_tmp__432;
  unsigned long long llvm_cbe_tmp__433;
  unsigned long long llvm_cbe_tmp__434;
  unsigned long long llvm_cbe_tmp__435;
  unsigned long long llvm_cbe_tmp__436;
  unsigned long long llvm_cbe_tmp__437;
  unsigned long long llvm_cbe_tmp__438;
  unsigned long long llvm_cbe_tmp__439;
  unsigned long long llvm_cbe_tmp__440;
  unsigned long long llvm_cbe_tmp__441;
  unsigned long long llvm_cbe_tmp__442;
  unsigned long long llvm_cbe_tmp__443;
  unsigned long long llvm_cbe_tmp__444;
  unsigned long long llvm_cbe_tmp__445;
  unsigned long long llvm_cbe_tmp__446;
  unsigned long long llvm_cbe_tmp__447;
  unsigned long long llvm_cbe_tmp__448;
  unsigned long long llvm_cbe_tmp__449;
  unsigned long long llvm_cbe_tmp__450;
  unsigned long long llvm_cbe_tmp__451;
  unsigned long long llvm_cbe_tmp__452;
  unsigned long long llvm_cbe_tmp__453;
  unsigned long long llvm_cbe_tmp__454;
  unsigned long long llvm_cbe_tmp__455;
  unsigned long long llvm_cbe_tmp__456;
  unsigned long long llvm_cbe_tmp__457;
  unsigned long long llvm_cbe_tmp__458;
  unsigned long long llvm_cbe_tmp__459;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__460;

  *(&llvm_cbe_tmp__316) = llvm_cbe_this;
  *(&llvm_cbe_tmp__317) = llvm_cbe_conf_done;
  *(&llvm_cbe_tmp__318) = llvm_cbe_conf_num_hidden;
  *(&llvm_cbe_tmp__319) = llvm_cbe_conf_num_loops;
  *(&llvm_cbe_tmp__320) = llvm_cbe_conf_num_movies;
  *(&llvm_cbe_tmp__321) = llvm_cbe_conf_num_testusers;
  *(&llvm_cbe_tmp__322) = llvm_cbe_conf_num_users;
  *(&llvm_cbe_tmp__323) = llvm_cbe_conf_num_visible;
  *(&llvm_cbe_tmp__324) = llvm_cbe_data_in;
  *(&llvm_cbe_tmp__325) = llvm_cbe_rd_grant;
  *(&llvm_cbe_tmp__326) = llvm_cbe_rst;
  *(&llvm_cbe_tmp__327) = llvm_cbe_wr_grant;
  llvm_cbe_tmp__331 = *(&llvm_cbe_tmp__316);
  llvm_cbe_tmp__332 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__333 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__334 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__335 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__336 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__337 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__338 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__339 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__340 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__341 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__342 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__343 = _ZN13model_compute18cppUpdateFun_indexElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__332, llvm_cbe_tmp__333, llvm_cbe_tmp__334, llvm_cbe_tmp__335, llvm_cbe_tmp__336, llvm_cbe_tmp__337, llvm_cbe_tmp__338, llvm_cbe_tmp__339, llvm_cbe_tmp__340, llvm_cbe_tmp__341, llvm_cbe_tmp__342);
  *(&llvm_cbe_cppVar_337) = llvm_cbe_tmp__343;
  llvm_cbe_tmp__344 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__345 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__346 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__347 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__348 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__349 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__350 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__351 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__352 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__353 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__354 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__355 = _ZN13model_compute23cppUpdateFun_loop_countElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__344, llvm_cbe_tmp__345, llvm_cbe_tmp__346, llvm_cbe_tmp__347, llvm_cbe_tmp__348, llvm_cbe_tmp__349, llvm_cbe_tmp__350, llvm_cbe_tmp__351, llvm_cbe_tmp__352, llvm_cbe_tmp__353, llvm_cbe_tmp__354);
  *(&llvm_cbe_cppVar_338) = llvm_cbe_tmp__355;
  llvm_cbe_tmp__356 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__357 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__358 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__359 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__360 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__361 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__362 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__363 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__364 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__365 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__366 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__367 = _ZN13model_compute31cppUpdateFun_predict_input_doneElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__356, llvm_cbe_tmp__357, llvm_cbe_tmp__358, llvm_cbe_tmp__359, llvm_cbe_tmp__360, llvm_cbe_tmp__361, llvm_cbe_tmp__362, llvm_cbe_tmp__363, llvm_cbe_tmp__364, llvm_cbe_tmp__365, llvm_cbe_tmp__366);
  *(&llvm_cbe_cppVar_349) = llvm_cbe_tmp__367;
  llvm_cbe_tmp__368 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__369 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__370 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__371 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__372 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__373 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__374 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__375 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__376 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__377 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__378 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__379 = _ZN13model_compute24cppUpdateFun_rd_completeElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__368, llvm_cbe_tmp__369, llvm_cbe_tmp__370, llvm_cbe_tmp__371, llvm_cbe_tmp__372, llvm_cbe_tmp__373, llvm_cbe_tmp__374, llvm_cbe_tmp__375, llvm_cbe_tmp__376, llvm_cbe_tmp__377, llvm_cbe_tmp__378);
  *(&llvm_cbe_cppVar_360) = llvm_cbe_tmp__379;
  llvm_cbe_tmp__380 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__381 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__382 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__383 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__384 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__385 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__386 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__387 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__388 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__389 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__390 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__391 = _ZN13model_compute21cppUpdateFun_rd_indexElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__380, llvm_cbe_tmp__381, llvm_cbe_tmp__382, llvm_cbe_tmp__383, llvm_cbe_tmp__384, llvm_cbe_tmp__385, llvm_cbe_tmp__386, llvm_cbe_tmp__387, llvm_cbe_tmp__388, llvm_cbe_tmp__389, llvm_cbe_tmp__390);
  *(&llvm_cbe_cppVar_365) = llvm_cbe_tmp__391;
  llvm_cbe_tmp__392 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__393 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__394 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__395 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__396 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__397 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__398 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__399 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__400 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__401 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__402 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__403 = _ZN13model_compute22cppUpdateFun_rd_lengthElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__392, llvm_cbe_tmp__393, llvm_cbe_tmp__394, llvm_cbe_tmp__395, llvm_cbe_tmp__396, llvm_cbe_tmp__397, llvm_cbe_tmp__398, llvm_cbe_tmp__399, llvm_cbe_tmp__400, llvm_cbe_tmp__401, llvm_cbe_tmp__402);
  *(&llvm_cbe_cppVar_372) = llvm_cbe_tmp__403;
  llvm_cbe_tmp__404 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__405 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__406 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__407 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__408 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__409 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__410 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__411 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__412 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__413 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__414 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__415 = _ZN13model_compute23cppUpdateFun_rd_requestElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__404, llvm_cbe_tmp__405, llvm_cbe_tmp__406, llvm_cbe_tmp__407, llvm_cbe_tmp__408, llvm_cbe_tmp__409, llvm_cbe_tmp__410, llvm_cbe_tmp__411, llvm_cbe_tmp__412, llvm_cbe_tmp__413, llvm_cbe_tmp__414);
  *(&llvm_cbe_cppVar_377) = llvm_cbe_tmp__415;
  llvm_cbe_tmp__416 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__417 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__418 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__419 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__420 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__421 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__422 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__423 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__424 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__425 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__426 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__427 = _ZN13model_compute29cppUpdateFun_train_input_doneElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__416, llvm_cbe_tmp__417, llvm_cbe_tmp__418, llvm_cbe_tmp__419, llvm_cbe_tmp__420, llvm_cbe_tmp__421, llvm_cbe_tmp__422, llvm_cbe_tmp__423, llvm_cbe_tmp__424, llvm_cbe_tmp__425, llvm_cbe_tmp__426);
  *(&llvm_cbe_cppVar_388) = llvm_cbe_tmp__427;
  llvm_cbe_tmp__428 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__429 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__430 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__431 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__432 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__433 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__434 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__435 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__436 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__437 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__438 = *(&llvm_cbe_tmp__327);
  llvm_cbe_tmp__439 = _ZN13model_compute16cppUpdateFun_upcElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__428, llvm_cbe_tmp__429, llvm_cbe_tmp__430, llvm_cbe_tmp__431, llvm_cbe_tmp__432, llvm_cbe_tmp__433, llvm_cbe_tmp__434, llvm_cbe_tmp__435, llvm_cbe_tmp__436, llvm_cbe_tmp__437, llvm_cbe_tmp__438);
  *(&llvm_cbe_cppVar_422) = llvm_cbe_tmp__439;
  llvm_cbe_tmp__440 = *(&llvm_cbe_tmp__317);
  llvm_cbe_tmp__441 = *(&llvm_cbe_tmp__318);
  llvm_cbe_tmp__442 = *(&llvm_cbe_tmp__319);
  llvm_cbe_tmp__443 = *(&llvm_cbe_tmp__320);
  llvm_cbe_tmp__444 = *(&llvm_cbe_tmp__321);
  llvm_cbe_tmp__445 = *(&llvm_cbe_tmp__322);
  llvm_cbe_tmp__446 = *(&llvm_cbe_tmp__323);
  llvm_cbe_tmp__447 = *(&llvm_cbe_tmp__324);
  llvm_cbe_tmp__448 = *(&llvm_cbe_tmp__325);
  llvm_cbe_tmp__449 = *(&llvm_cbe_tmp__326);
  llvm_cbe_tmp__450 = *(&llvm_cbe_tmp__327);
  llvm_cbe_cppVar_423 = _ZN13model_compute18cppUpdateFun_edgesElllllllllll(llvm_cbe_tmp__331, llvm_cbe_tmp__440, llvm_cbe_tmp__441, llvm_cbe_tmp__442, llvm_cbe_tmp__443, llvm_cbe_tmp__444, llvm_cbe_tmp__445, llvm_cbe_tmp__446, llvm_cbe_tmp__447, llvm_cbe_tmp__448, llvm_cbe_tmp__449, llvm_cbe_tmp__450);
  llvm_cbe_tmp__451 = *(&llvm_cbe_cppVar_337);
  *((&llvm_cbe_tmp__331->field4)) = llvm_cbe_tmp__451;
  llvm_cbe_tmp__452 = *(&llvm_cbe_cppVar_338);
  *((&llvm_cbe_tmp__331->field6)) = llvm_cbe_tmp__452;
  llvm_cbe_tmp__453 = *(&llvm_cbe_cppVar_349);
  *((&llvm_cbe_tmp__331->field13)) = llvm_cbe_tmp__453;
  llvm_cbe_tmp__454 = *(&llvm_cbe_cppVar_360);
  *((&llvm_cbe_tmp__331->field15)) = llvm_cbe_tmp__454;
  llvm_cbe_tmp__455 = *(&llvm_cbe_cppVar_365);
  *((&llvm_cbe_tmp__331->field16)) = llvm_cbe_tmp__455;
  llvm_cbe_tmp__456 = *(&llvm_cbe_cppVar_372);
  *((&llvm_cbe_tmp__331->field17)) = llvm_cbe_tmp__456;
  llvm_cbe_tmp__457 = *(&llvm_cbe_cppVar_377);
  *((&llvm_cbe_tmp__331->field18)) = llvm_cbe_tmp__457;
  llvm_cbe_tmp__458 = *(&llvm_cbe_cppVar_388);
  *((&llvm_cbe_tmp__331->field19)) = llvm_cbe_tmp__458;
  llvm_cbe_tmp__459 = *(&llvm_cbe_cppVar_422);
  *((&llvm_cbe_tmp__331->field20)) = llvm_cbe_tmp__459;
  llvm_cbe_tmp__460 = _ZN8type_memIhLj65536EEaSERKS0_(((&llvm_cbe_tmp__331->field3)), (&llvm_cbe_cppVar_423));
  *(&llvm_cbe_tmp__330) = 1u;
  _ZN8type_memIhLj65536EED1Ev((&llvm_cbe_cppVar_423));
  return;
}


struct l_class_OC_SysCArray1D *_ZN8type_memIhLj65536EEaSERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__461;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__462;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__463;
  unsigned char *llvm_cbe_tmp__464;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__465;
  unsigned char *llvm_cbe_tmp__466;

  *(&llvm_cbe_tmp__461) = llvm_cbe_this;
  *(&llvm_cbe_tmp__462) = llvm_cbe_r;
  llvm_cbe_tmp__463 = *(&llvm_cbe_tmp__461);
  llvm_cbe_tmp__464 = *((&llvm_cbe_tmp__463->field0));
  llvm_cbe_tmp__465 = *(&llvm_cbe_tmp__462);
  llvm_cbe_tmp__466 = *((&llvm_cbe_tmp__465->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__464, llvm_cbe_tmp__466);
  return llvm_cbe_tmp__463;
}


void _ZN8type_memIhLj65536EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__467;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__468;

  *(&llvm_cbe_tmp__467) = llvm_cbe_this;
  llvm_cbe_tmp__468 = *(&llvm_cbe_tmp__467);
  _ZN8type_memIhLj65536EED2Ev(llvm_cbe_tmp__468);
  return;
}


static void __cxx_global_var_init(void) {
  unsigned int llvm_cbe_tmp__469;

  _ZN13model_computeC1Ev((&GM));
  llvm_cbe_tmp__469 = __cxa_atexit(((void  (*) (unsigned char *))_ZN13model_computeD1Ev), ((unsigned char *)(&GM)), ((unsigned char *)(&__dso_handle)));
  return;
}


void _ZN13model_computeC1Ev(struct l_class_OC_model_compute *llvm_cbe_this) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__470;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__471;

  *(&llvm_cbe_tmp__470) = llvm_cbe_this;
  llvm_cbe_tmp__471 = *(&llvm_cbe_tmp__470);
  _ZN13model_computeC2Ev(llvm_cbe_tmp__471);
  return;
}


void _ZN13model_computeD1Ev(struct l_class_OC_model_compute *llvm_cbe_this) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__472;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__473;

  *(&llvm_cbe_tmp__472) = llvm_cbe_this;
  llvm_cbe_tmp__473 = *(&llvm_cbe_tmp__472);
  _ZN13model_computeD2Ev(llvm_cbe_tmp__473);
  return;
}


void _Z4waitv(void) {
  unsigned int llvm_cbe_tmp__474;

  llvm_cbe_tmp__474 = *(&cycleCnt);
  *(&cycleCnt) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__474) + ((unsigned int )1u))));
  return;
}


void _Z15reset_signal_isib(unsigned int llvm_cbe_tmp__475, bool llvm_cbe_tmp__476) {
  unsigned int llvm_cbe_tmp__477;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__478;    /* Address-exposed local */

  *(&llvm_cbe_tmp__477) = llvm_cbe_tmp__475;
  *(&llvm_cbe_tmp__478) = (((unsigned char )(bool )llvm_cbe_tmp__476));
  return;
}


void _Z14set_stack_sizei(unsigned int llvm_cbe_tmp__479) {
  unsigned int llvm_cbe_tmp__480;    /* Address-exposed local */

  *(&llvm_cbe_tmp__480) = llvm_cbe_tmp__479;
  return;
}


void _ZN3rbm6configEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__481;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__482;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__483;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__484;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__485;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__486;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__487;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__488;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__489;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__490;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__491;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__492;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__493;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__494;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__495;
  bool llvm_cbe_tmp__496;
  unsigned int llvm_cbe_tmp__497;
  unsigned int llvm_cbe_tmp__498;
  unsigned int llvm_cbe_tmp__499;
  unsigned int llvm_cbe_tmp__500;
  unsigned int llvm_cbe_tmp__501;
  unsigned int llvm_cbe_tmp__502;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__503;
  unsigned int llvm_cbe_tmp__504;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__505;

  *(&llvm_cbe_tmp__481) = llvm_cbe_this;
  llvm_cbe_tmp__495 = *(&llvm_cbe_tmp__481);
  *(&llvm_cbe_tmp__482) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field30)), (&llvm_cbe_tmp__482));
  *(&llvm_cbe_tmp__483) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field31)), (&llvm_cbe_tmp__483));
  *(&llvm_cbe_tmp__484) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field32)), (&llvm_cbe_tmp__484));
  *(&llvm_cbe_tmp__485) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field33)), (&llvm_cbe_tmp__485));
  *(&llvm_cbe_tmp__486) = ((unsigned short )0);
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field35)), (&llvm_cbe_tmp__486));
  *(&llvm_cbe_tmp__487) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__495->field36)), (&llvm_cbe_tmp__487));
  _Z4waitv();
  goto llvm_cbe_tmp__506;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__506:
  _Z4waitv();
  llvm_cbe_tmp__496 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__495->field13))))&1);
  if ((((llvm_cbe_tmp__496 ^ 1)&1))) {
    goto llvm_cbe_tmp__506;
  } else {
    goto llvm_cbe_tmp__507;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__507:
  llvm_cbe_tmp__497 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__495->field14)));
  *(&llvm_cbe_tmp__488) = (((unsigned short )llvm_cbe_tmp__497));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field30)), (&llvm_cbe_tmp__488));
  llvm_cbe_tmp__498 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__495->field15)));
  *(&llvm_cbe_tmp__489) = (((unsigned short )llvm_cbe_tmp__498));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field31)), (&llvm_cbe_tmp__489));
  llvm_cbe_tmp__499 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__495->field16)));
  *(&llvm_cbe_tmp__490) = (((unsigned short )llvm_cbe_tmp__499));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field32)), (&llvm_cbe_tmp__490));
  llvm_cbe_tmp__500 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__495->field17)));
  *(&llvm_cbe_tmp__491) = (((unsigned short )llvm_cbe_tmp__500));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field33)), (&llvm_cbe_tmp__491));
  llvm_cbe_tmp__501 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__495->field18)));
  *(&llvm_cbe_tmp__492) = (((unsigned short )llvm_cbe_tmp__501));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field34)), (&llvm_cbe_tmp__492));
  llvm_cbe_tmp__502 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__495->field19)));
  *(&llvm_cbe_tmp__493) = (((unsigned short )llvm_cbe_tmp__502));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__495->field35)), (&llvm_cbe_tmp__493));
  llvm_cbe_tmp__503 = _ZNSt6iocoutlsEPKc((&_ZSt4cout), ((&_OC_str.array[((signed int )0u)])));
  llvm_cbe_tmp__504 = *(&_ZSt4endl);
  llvm_cbe_tmp__505 = _ZNSt6iocoutlsEi(llvm_cbe_tmp__503, llvm_cbe_tmp__504);
  *(&llvm_cbe_tmp__494) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__495->field36)), (&llvm_cbe_tmp__494));
  goto llvm_cbe_tmp__508;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__508:
  _Z4waitv();
  goto llvm_cbe_tmp__508;

  } while (1); /* end of syntactic loop '' */
}


void _ZN13sc_signal_u165writeERKt(struct l_class_OC_sc_signal_u16 *llvm_cbe_this, unsigned short *llvm_cbe_d) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__509;    /* Address-exposed local */
  unsigned short *llvm_cbe_tmp__510;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__511;
  unsigned short *llvm_cbe_tmp__512;
  unsigned short llvm_cbe_tmp__513;

  *(&llvm_cbe_tmp__509) = llvm_cbe_this;
  *(&llvm_cbe_tmp__510) = llvm_cbe_d;
  llvm_cbe_tmp__511 = *(&llvm_cbe_tmp__509);
  llvm_cbe_tmp__512 = *(&llvm_cbe_tmp__510);
  llvm_cbe_tmp__513 = *llvm_cbe_tmp__512;
  *((&llvm_cbe_tmp__511->field0)) = llvm_cbe_tmp__513;
  return;
}


void _ZN14sc_signal_bool5writeERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__514;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__515;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__516;
  unsigned char *llvm_cbe_tmp__517;
  unsigned char llvm_cbe_tmp__518;

  *(&llvm_cbe_tmp__514) = llvm_cbe_this;
  *(&llvm_cbe_tmp__515) = llvm_cbe_d;
  llvm_cbe_tmp__516 = *(&llvm_cbe_tmp__514);
  llvm_cbe_tmp__517 = *(&llvm_cbe_tmp__515);
  llvm_cbe_tmp__518 = *llvm_cbe_tmp__517;
  *((&llvm_cbe_tmp__516->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__518&1u))&1))));
  return;
}


bool _ZN14sc_signal_bool4readEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__519;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__520;
  unsigned char llvm_cbe_tmp__521;

  *(&llvm_cbe_tmp__519) = llvm_cbe_this;
  llvm_cbe_tmp__520 = *(&llvm_cbe_tmp__519);
  llvm_cbe_tmp__521 = *((&llvm_cbe_tmp__520->field0));
  return (((((bool )llvm_cbe_tmp__521&1u))&1));
}


unsigned int _ZN13sc_signal_u324readEv(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__522;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__523;
  unsigned int llvm_cbe_tmp__524;

  *(&llvm_cbe_tmp__522) = llvm_cbe_this;
  llvm_cbe_tmp__523 = *(&llvm_cbe_tmp__522);
  llvm_cbe_tmp__524 = *((&llvm_cbe_tmp__523->field0));
  return llvm_cbe_tmp__524;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_tmp__525) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__526;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__527;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__528;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__529;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__530;

  *(&llvm_cbe_tmp__527) = llvm_cbe_this;
  *(&llvm_cbe_tmp__528) = llvm_cbe_tmp__525;
  llvm_cbe_tmp__529 = *(&llvm_cbe_tmp__527);
  llvm_cbe_tmp__530 = *(&llvm_cbe_tmp__526);
  return llvm_cbe_tmp__530;
}


struct l_class_OC_sc_signal_bool *_ZNSt6iocoutlsEi(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned int llvm_cbe_tmp__531) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__532;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__533;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__534;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__535;
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__536;

  *(&llvm_cbe_tmp__533) = llvm_cbe_this;
  *(&llvm_cbe_tmp__534) = llvm_cbe_tmp__531;
  llvm_cbe_tmp__535 = *(&llvm_cbe_tmp__533);
  llvm_cbe_tmp__536 = *(&llvm_cbe_tmp__532);
  return llvm_cbe_tmp__536;
}


void _ZN3rbm4loadEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__537;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__538;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__539;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__540;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__541;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__542;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__543;    /* Address-exposed local */
  unsigned short llvm_cbe_index;    /* Address-exposed local */
  unsigned short llvm_cbe_loop_count;    /* Address-exposed local */
  unsigned char llvm_cbe_pingpong;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp1;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp2;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__544;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__545;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__546;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__547;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__548;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__549;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__550;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__551;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__552;    /* Address-exposed local */
  unsigned short llvm_cbe_tmp__553;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__554;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__555;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__556;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__557;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__558;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__559;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__560;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__561;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__562;    /* Address-exposed local */
  unsigned int llvm_cbe_nv;    /* Address-exposed local */
  unsigned int llvm_cbe_ntu;    /* Address-exposed local */
  unsigned int llvm_cbe_nu;    /* Address-exposed local */
  unsigned int llvm_cbe_nlp;    /* Address-exposed local */
  unsigned int llvm_cbe_nm;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__563;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__564;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__565;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__566;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned char llvm_cbe_rate;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__567;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__568;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__569;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__570;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__571;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__572;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__573;    /* Address-exposed local */
  unsigned short llvm_cbe_i1;    /* Address-exposed local */
  unsigned char llvm_cbe_rate2;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__574;
  bool llvm_cbe_tmp__575;
  bool llvm_cbe_tmp__576;
  bool llvm_cbe_tmp__577;
  bool llvm_cbe_tmp__578;
  unsigned char llvm_cbe_tmp__579;
  unsigned int llvm_cbe_tmp__580;
  unsigned int llvm_cbe_tmp__581;
  unsigned int llvm_cbe_tmp__582;
  unsigned int llvm_cbe_tmp__583;
  unsigned int llvm_cbe_tmp__584;
  unsigned int llvm_cbe_tmp__585;
  unsigned char llvm_cbe_tmp__586;
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
  unsigned char llvm_cbe_tmp__598;
  unsigned int llvm_cbe_tmp__599;
  unsigned char llvm_cbe_tmp__600;
  unsigned long long llvm_cbe_tmp__601;
  unsigned long long llvm_cbe_tmp__602;
  unsigned long long llvm_cbe_tmp__603;
  unsigned long long llvm_cbe_tmp__604;
  unsigned long long llvm_cbe_tmp__605;
  unsigned long long llvm_cbe_tmp__606;
  unsigned long long llvm_cbe_tmp__607;
  unsigned long long llvm_cbe_tmp__608;
  unsigned char *llvm_cbe_tmp__609;
  unsigned char *llvm_cbe_tmp__610;
  unsigned char *llvm_cbe_tmp__611;
  unsigned char *llvm_cbe_tmp__612;
  float *llvm_cbe_tmp__613;
  unsigned char *llvm_cbe_tmp__614;
  unsigned short llvm_cbe_tmp__615;
  unsigned short llvm_cbe_tmp__616;
  unsigned short llvm_cbe_tmp__617;
  unsigned short llvm_cbe_tmp__618;
  unsigned short llvm_cbe_tmp__619;
  unsigned short llvm_cbe_tmp__620;
  unsigned int llvm_cbe_tmp__621;
  unsigned short llvm_cbe_tmp__622;
  unsigned int llvm_cbe_tmp__623;
  unsigned char llvm_cbe_tmp__624;
  unsigned int llvm_cbe_tmp__625;
  unsigned int llvm_cbe_tmp__626;
  unsigned int llvm_cbe_tmp__627;
  unsigned int llvm_cbe_tmp__628;
  unsigned int llvm_cbe_tmp__629;
  unsigned int llvm_cbe_tmp__630;
  unsigned char llvm_cbe_tmp__631;
  unsigned char llvm_cbe_tmp__632;
  unsigned int llvm_cbe_tmp__633;
  unsigned char llvm_cbe_tmp__634;
  bool llvm_cbe_tmp__635;
  unsigned long long llvm_cbe_tmp__636;
  bool llvm_cbe_tmp__637;
  unsigned long long llvm_cbe_tmp__638;
  unsigned short llvm_cbe_tmp__639;
  unsigned long long llvm_cbe_tmp__640;
  unsigned short llvm_cbe_tmp__641;
  unsigned long long llvm_cbe_tmp__642;
  unsigned short llvm_cbe_tmp__643;
  unsigned long long llvm_cbe_tmp__644;
  unsigned short llvm_cbe_tmp__645;
  unsigned long long llvm_cbe_tmp__646;
  unsigned short llvm_cbe_tmp__647;
  unsigned long long llvm_cbe_tmp__648;
  unsigned short llvm_cbe_tmp__649;
  unsigned long long llvm_cbe_tmp__650;
  unsigned int llvm_cbe_tmp__651;
  unsigned long long llvm_cbe_tmp__652;
  unsigned int llvm_cbe_tmp__653;
  unsigned long long llvm_cbe_tmp__654;
  bool llvm_cbe_tmp__655;
  unsigned long long llvm_cbe_tmp__656;
  bool llvm_cbe_tmp__657;
  unsigned long long llvm_cbe_tmp__658;
  unsigned int llvm_cbe_tmp__659;
  unsigned long long llvm_cbe_tmp__660;
  unsigned int llvm_cbe_tmp__661;
  unsigned long long llvm_cbe_tmp__662;
  unsigned int llvm_cbe_tmp__663;
  unsigned long long llvm_cbe_tmp__664;
  unsigned int llvm_cbe_tmp__665;
  unsigned long long llvm_cbe_tmp__666;
  unsigned short llvm_cbe_tmp__667;
  unsigned long long llvm_cbe_tmp__668;
  unsigned short llvm_cbe_tmp__669;
  unsigned long long llvm_cbe_tmp__670;
  unsigned int llvm_cbe_tmp__671;
  unsigned long long llvm_cbe_tmp__672;
  bool llvm_cbe_tmp__673;
  unsigned long long llvm_cbe_tmp__674;
  bool llvm_cbe_tmp__675;
  unsigned long long llvm_cbe_tmp__676;
  unsigned char *llvm_cbe_tmp__677;
  unsigned char *llvm_cbe_tmp__678;
  bool llvm_cbe_tmp__679;
  unsigned char *llvm_cbe_tmp__680;
  unsigned char *llvm_cbe_tmp__681;
  bool llvm_cbe_tmp__682;

  *(&llvm_cbe_tmp__537) = llvm_cbe_this;
  llvm_cbe_tmp__574 = *(&llvm_cbe_tmp__537);
  *(&llvm_cbe_tmp__538) = ((unsigned char )1);
  llvm_cbe_tmp__575 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__574->field36)), (&llvm_cbe_tmp__538)))&1);
  *(&llvm_cbe_tmp__539) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field2)), (&llvm_cbe_tmp__539));
  *(&llvm_cbe_tmp__540) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field3)), (&llvm_cbe_tmp__540));
  *(&llvm_cbe_tmp__541) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field4)), (&llvm_cbe_tmp__541));
  *(&llvm_cbe_tmp__542) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field37)), (&llvm_cbe_tmp__542));
  *(&llvm_cbe_tmp__543) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field38)), (&llvm_cbe_tmp__543));
  goto llvm_cbe_tmp__683;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__683:
  _Z4waitv();
  llvm_cbe_tmp__576 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__574->field36))))&1);
  if ((((llvm_cbe_tmp__576 ^ 1)&1))) {
    goto llvm_cbe_tmp__683;
  } else {
    goto llvm_cbe_tmp__684;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__684:
  *(&llvm_cbe_index) = ((unsigned short )0);
  *(&llvm_cbe_loop_count) = ((unsigned short )0);
  *(&llvm_cbe_pingpong) = ((unsigned char )0);
  *(&rst_inp) = ((unsigned char )0);
  *(&llvm_cbe_tmp__544) = ((unsigned char )1);
  llvm_cbe_tmp__577 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__574->field36)), (&llvm_cbe_tmp__544)))&1);
  *(&llvm_cbe_tmp__545) = ((unsigned char )0);
  llvm_cbe_tmp__578 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__574->field12)), (&llvm_cbe_tmp__545)))&1);
  llvm_cbe_tmp__579 = *(&conf_done_inp);
  *((&((&llvm_cbe_tmp__574->field13))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__579&1u))&1))));
  llvm_cbe_tmp__580 = *(&conf_num_hidden_inp);
  *((&((&llvm_cbe_tmp__574->field14))->field0)) = llvm_cbe_tmp__580;
  llvm_cbe_tmp__581 = *(&conf_num_visible_inp);
  *((&((&llvm_cbe_tmp__574->field15))->field0)) = llvm_cbe_tmp__581;
  llvm_cbe_tmp__582 = *(&conf_num_users_inp);
  *((&((&llvm_cbe_tmp__574->field16))->field0)) = llvm_cbe_tmp__582;
  llvm_cbe_tmp__583 = *(&conf_num_loops_inp);
  *((&((&llvm_cbe_tmp__574->field17))->field0)) = llvm_cbe_tmp__583;
  llvm_cbe_tmp__584 = *(&conf_num_testusers_inp);
  *((&((&llvm_cbe_tmp__574->field18))->field0)) = llvm_cbe_tmp__584;
  llvm_cbe_tmp__585 = *(&conf_num_movies_inp);
  *((&((&llvm_cbe_tmp__574->field19))->field0)) = llvm_cbe_tmp__585;
  llvm_cbe_tmp__586 = *(&rst_inp);
  *((&((&llvm_cbe_tmp__574->field1))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__586&1u))&1))));
  llvm_cbe_tmp__587 = *((&GM.field5));
  *(&llvm_cbe_tmp__546) = (((unsigned char )(bool )(llvm_cbe_tmp__587 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field36)), (&llvm_cbe_tmp__546));
  llvm_cbe_tmp__588 = *((&GM.field2));
  *(&llvm_cbe_tmp__547) = (((unsigned char )(bool )(llvm_cbe_tmp__588 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field12)), (&llvm_cbe_tmp__547));
  llvm_cbe_tmp__589 = *((&GM.field7));
  *(&llvm_cbe_tmp__548) = (((unsigned short )llvm_cbe_tmp__589));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__574->field30)), (&llvm_cbe_tmp__548));
  llvm_cbe_tmp__590 = *((&GM.field12));
  *(&llvm_cbe_tmp__549) = (((unsigned short )llvm_cbe_tmp__590));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__574->field31)), (&llvm_cbe_tmp__549));
  llvm_cbe_tmp__591 = *((&GM.field11));
  *(&llvm_cbe_tmp__550) = (((unsigned short )llvm_cbe_tmp__591));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__574->field32)), (&llvm_cbe_tmp__550));
  llvm_cbe_tmp__592 = *((&GM.field8));
  *(&llvm_cbe_tmp__551) = (((unsigned short )llvm_cbe_tmp__592));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__574->field33)), (&llvm_cbe_tmp__551));
  llvm_cbe_tmp__593 = *((&GM.field10));
  *(&llvm_cbe_tmp__552) = (((unsigned short )llvm_cbe_tmp__593));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__574->field34)), (&llvm_cbe_tmp__552));
  llvm_cbe_tmp__594 = *((&GM.field9));
  *(&llvm_cbe_tmp__553) = (((unsigned short )llvm_cbe_tmp__594));
  _ZN13sc_signal_u165writeERKt(((&llvm_cbe_tmp__574->field35)), (&llvm_cbe_tmp__553));
  llvm_cbe_tmp__595 = *((&GM.field16));
  *(&llvm_cbe_tmp__554) = (((unsigned int )llvm_cbe_tmp__595));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field2)), (&llvm_cbe_tmp__554));
  llvm_cbe_tmp__596 = *((&GM.field17));
  *(&llvm_cbe_tmp__555) = (((unsigned int )llvm_cbe_tmp__596));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field3)), (&llvm_cbe_tmp__555));
  llvm_cbe_tmp__597 = *((&GM.field18));
  *(&llvm_cbe_tmp__556) = (((unsigned char )(bool )(llvm_cbe_tmp__597 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field4)), (&llvm_cbe_tmp__556));
  llvm_cbe_tmp__598 = *(&rd_grant_inp);
  *((&((&llvm_cbe_tmp__574->field5))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__598&1u))&1))));
  llvm_cbe_tmp__599 = *(&data_in_inp);
  *((&((&llvm_cbe_tmp__574->field6))->field0)) = llvm_cbe_tmp__599;
  llvm_cbe_tmp__600 = *(&wr_grant_inp);
  *((&((&llvm_cbe_tmp__574->field10))->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__600&1u))&1))));
  llvm_cbe_tmp__601 = *((&GM.field24));
  *(&llvm_cbe_tmp__557) = (((unsigned char )(bool )(llvm_cbe_tmp__601 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field9)), (&llvm_cbe_tmp__557));
  llvm_cbe_tmp__602 = *((&GM.field22));
  *(&llvm_cbe_tmp__558) = (((unsigned int )llvm_cbe_tmp__602));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field7)), (&llvm_cbe_tmp__558));
  llvm_cbe_tmp__603 = *((&GM.field23));
  *(&llvm_cbe_tmp__559) = (((unsigned int )llvm_cbe_tmp__603));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field8)), (&llvm_cbe_tmp__559));
  llvm_cbe_tmp__604 = *((&GM.field1));
  *(&llvm_cbe_tmp__560) = (((unsigned int )llvm_cbe_tmp__604));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field11)), (&llvm_cbe_tmp__560));
  llvm_cbe_tmp__605 = *((&GM.field4));
  *(&llvm_cbe_index) = (((unsigned short )llvm_cbe_tmp__605));
  llvm_cbe_tmp__606 = *((&GM.field6));
  *(&llvm_cbe_loop_count) = (((unsigned short )llvm_cbe_tmp__606));
  llvm_cbe_tmp__607 = *((&GM.field19));
  *(&llvm_cbe_tmp__561) = (((unsigned char )(bool )(llvm_cbe_tmp__607 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field37)), (&llvm_cbe_tmp__561));
  llvm_cbe_tmp__608 = *((&GM.field13));
  *(&llvm_cbe_tmp__562) = (((unsigned char )(bool )(llvm_cbe_tmp__608 != 0ull)));
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field38)), (&llvm_cbe_tmp__562));
  llvm_cbe_tmp__609 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__574->field20)), 0u);
  llvm_cbe_tmp__610 = *((&GM.field0.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__609, llvm_cbe_tmp__610);
  llvm_cbe_tmp__611 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__574->field28)), 0u);
  llvm_cbe_tmp__612 = *((&GM.field14.field0));
  __CPROVER_array_copy(llvm_cbe_tmp__611, llvm_cbe_tmp__612);
  llvm_cbe_tmp__613 = *((&((&llvm_cbe_tmp__574->field23))->field0));
  llvm_cbe_tmp__614 = *((&GM.field3.field0));
  __CPROVER_array_copy((((unsigned char *)llvm_cbe_tmp__613)), llvm_cbe_tmp__614);
  llvm_cbe_tmp__615 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field31)));
  *(&llvm_cbe_nv) = (((unsigned int )(unsigned short )llvm_cbe_tmp__615));
  llvm_cbe_tmp__616 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field34)));
  *(&llvm_cbe_ntu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__616));
  llvm_cbe_tmp__617 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field32)));
  *(&llvm_cbe_nu) = (((unsigned int )(unsigned short )llvm_cbe_tmp__617));
  llvm_cbe_tmp__618 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field33)));
  *(&llvm_cbe_nlp) = (((unsigned int )(unsigned short )llvm_cbe_tmp__618));
  llvm_cbe_tmp__619 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field35)));
  *(&llvm_cbe_nm) = (((unsigned int )(unsigned short )llvm_cbe_tmp__619));
  *(&upc) = 0u;
  llvm_cbe_tmp__620 = *(&llvm_cbe_index);
  *(&llvm_cbe_tmp__563) = (((unsigned int )(unsigned short )llvm_cbe_tmp__620));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field2)), (&llvm_cbe_tmp__563));
  llvm_cbe_tmp__621 = *(&llvm_cbe_nm);
  *(&llvm_cbe_tmp__564) = (((unsigned int )(((unsigned int )5u) * ((unsigned int )llvm_cbe_tmp__621))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__574->field3)), (&llvm_cbe_tmp__564));
  llvm_cbe_tmp__622 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__623 = *(&llvm_cbe_nlp);
  *(&llvm_cbe_tmp__565) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__574->field4)), (&llvm_cbe_tmp__565));
  _Z4waitv();
  *(&upc) = 1u;
  llvm_cbe_tmp__624 = *(&conf_done_inp);
  llvm_cbe_tmp__625 = *(&conf_num_hidden_inp);
  llvm_cbe_tmp__626 = *(&conf_num_visible_inp);
  llvm_cbe_tmp__627 = *(&conf_num_users_inp);
  llvm_cbe_tmp__628 = *(&conf_num_loops_inp);
  llvm_cbe_tmp__629 = *(&conf_num_testusers_inp);
  llvm_cbe_tmp__630 = *(&conf_num_movies_inp);
  llvm_cbe_tmp__631 = *(&rst_inp);
  llvm_cbe_tmp__632 = *(&rd_grant_inp);
  llvm_cbe_tmp__633 = *(&data_in_inp);
  llvm_cbe_tmp__634 = *(&wr_grant_inp);
  _ZN13model_compute6updateElllllllllll((&GM), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__624&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__625)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__626)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__627)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__628)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__629)), (((unsigned long long )(unsigned int )llvm_cbe_tmp__630)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__631&1u))&1)))), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__632&1u))&1)))), (((unsigned long long )(unsigned int )llvm_cbe_tmp__633)), (((unsigned long long )(bool )(((((bool )llvm_cbe_tmp__634&1u))&1)))));
  llvm_cbe_tmp__635 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__574->field36))))&1);
  llvm_cbe_tmp__636 = *((&GM.field5));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__635)) == llvm_cbe_tmp__636), ((&_OC_str1.array[((signed int )0u)])));
  llvm_cbe_tmp__637 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__574->field12))))&1);
  llvm_cbe_tmp__638 = *((&GM.field2));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__637)) == llvm_cbe_tmp__638), ((&_OC_str2.array[((signed int )0u)])));
  llvm_cbe_tmp__639 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field30)));
  llvm_cbe_tmp__640 = *((&GM.field7));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__639)) == llvm_cbe_tmp__640), ((&_OC_str3.array[((signed int )0u)])));
  llvm_cbe_tmp__641 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field31)));
  llvm_cbe_tmp__642 = *((&GM.field12));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__641)) == llvm_cbe_tmp__642), ((&_OC_str4.array[((signed int )0u)])));
  llvm_cbe_tmp__643 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field32)));
  llvm_cbe_tmp__644 = *((&GM.field11));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__643)) == llvm_cbe_tmp__644), ((&_OC_str5.array[((signed int )0u)])));
  llvm_cbe_tmp__645 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field33)));
  llvm_cbe_tmp__646 = *((&GM.field8));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__645)) == llvm_cbe_tmp__646), ((&_OC_str6.array[((signed int )0u)])));
  llvm_cbe_tmp__647 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field34)));
  llvm_cbe_tmp__648 = *((&GM.field10));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__647)) == llvm_cbe_tmp__648), ((&_OC_str7.array[((signed int )0u)])));
  llvm_cbe_tmp__649 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__574->field35)));
  llvm_cbe_tmp__650 = *((&GM.field9));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__649)) == llvm_cbe_tmp__650), ((&_OC_str8.array[((signed int )0u)])));
  llvm_cbe_tmp__651 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__574->field2)));
  llvm_cbe_tmp__652 = *((&GM.field16));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__651)) == llvm_cbe_tmp__652), ((&_OC_str9.array[((signed int )0u)])));
  llvm_cbe_tmp__653 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__574->field3)));
  llvm_cbe_tmp__654 = *((&GM.field17));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__653)) == llvm_cbe_tmp__654), ((&_OC_str10.array[((signed int )0u)])));
  llvm_cbe_tmp__655 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__574->field4))))&1);
  llvm_cbe_tmp__656 = *((&GM.field18));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__655)) == llvm_cbe_tmp__656), ((&_OC_str11.array[((signed int )0u)])));
  llvm_cbe_tmp__657 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__574->field9))))&1);
  llvm_cbe_tmp__658 = *((&GM.field24));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__657)) == llvm_cbe_tmp__658), ((&_OC_str12.array[((signed int )0u)])));
  llvm_cbe_tmp__659 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__574->field7)));
  llvm_cbe_tmp__660 = *((&GM.field22));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__659)) == llvm_cbe_tmp__660), ((&_OC_str13.array[((signed int )0u)])));
  llvm_cbe_tmp__661 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__574->field8)));
  llvm_cbe_tmp__662 = *((&GM.field23));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__661)) == llvm_cbe_tmp__662), ((&_OC_str14.array[((signed int )0u)])));
  llvm_cbe_tmp__663 = _ZN13sc_signal_u324readEv(((&llvm_cbe_tmp__574->field11)));
  llvm_cbe_tmp__664 = *((&GM.field1));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__663)) == llvm_cbe_tmp__664), ((&_OC_str15.array[((signed int )0u)])));
  llvm_cbe_tmp__665 = *(&rd_complete);
  llvm_cbe_tmp__666 = *((&GM.field15));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__665)) == llvm_cbe_tmp__666), ((&_OC_str16.array[((signed int )0u)])));
  llvm_cbe_tmp__667 = *(&llvm_cbe_index);
  llvm_cbe_tmp__668 = *((&GM.field4));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__667)) == llvm_cbe_tmp__668), ((&_OC_str17.array[((signed int )0u)])));
  llvm_cbe_tmp__669 = *(&llvm_cbe_loop_count);
  llvm_cbe_tmp__670 = *((&GM.field6));
  __CPROVER_assert(((((unsigned long long )(unsigned short )llvm_cbe_tmp__669)) == llvm_cbe_tmp__670), ((&_OC_str18.array[((signed int )0u)])));
  llvm_cbe_tmp__671 = *(&upc);
  llvm_cbe_tmp__672 = *((&GM.field20));
  __CPROVER_assert(((((unsigned long long )(unsigned int )llvm_cbe_tmp__671)) == llvm_cbe_tmp__672), ((&_OC_str19.array[((signed int )0u)])));
  llvm_cbe_tmp__673 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__574->field37))))&1);
  llvm_cbe_tmp__674 = *((&GM.field19));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__673)) == llvm_cbe_tmp__674), ((&_OC_str20.array[((signed int )0u)])));
  llvm_cbe_tmp__675 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__574->field38))))&1);
  llvm_cbe_tmp__676 = *((&GM.field13));
  __CPROVER_assert(((((unsigned long long )(bool )llvm_cbe_tmp__675)) == llvm_cbe_tmp__676), ((&_OC_str21.array[((signed int )0u)])));
  llvm_cbe_tmp__677 = *((&GM.field0.field0));
  llvm_cbe_tmp__678 = _ZN11SysCArray2DIhLj2ELj512EEixEj(((&llvm_cbe_tmp__574->field20)), 0u);
  llvm_cbe_tmp__679 = ((__CPROVER_array_equal(llvm_cbe_tmp__677, llvm_cbe_tmp__678))&1);
  __CPROVER_assert(llvm_cbe_tmp__679, ((&_OC_str22.array[((signed int )0u)])));
  llvm_cbe_tmp__680 = *((&GM.field14.field0));
  llvm_cbe_tmp__681 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__574->field28)), 0u);
  llvm_cbe_tmp__682 = ((__CPROVER_array_equal(llvm_cbe_tmp__680, llvm_cbe_tmp__681))&1);
  __CPROVER_assert(llvm_cbe_tmp__682, ((&_OC_str23.array[((signed int )0u)])));
  return;
}


bool _ZN14sc_signal_boolaSERKb(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_d) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__685;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__686;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__687;
  unsigned char *llvm_cbe_tmp__688;
  unsigned char llvm_cbe_tmp__689;
  unsigned char llvm_cbe_tmp__690;

  *(&llvm_cbe_tmp__685) = llvm_cbe_this;
  *(&llvm_cbe_tmp__686) = llvm_cbe_d;
  llvm_cbe_tmp__687 = *(&llvm_cbe_tmp__685);
  llvm_cbe_tmp__688 = *(&llvm_cbe_tmp__686);
  llvm_cbe_tmp__689 = *llvm_cbe_tmp__688;
  *((&llvm_cbe_tmp__687->field0)) = (((unsigned char )(bool )(((((bool )llvm_cbe_tmp__689&1u))&1))));
  llvm_cbe_tmp__690 = *((&llvm_cbe_tmp__687->field0));
  return (((((bool )llvm_cbe_tmp__690&1u))&1));
}


void _ZN13sc_signal_u325writeERKj(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned int *llvm_cbe_d) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__691;    /* Address-exposed local */
  unsigned int *llvm_cbe_tmp__692;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__693;
  unsigned int *llvm_cbe_tmp__694;
  unsigned int llvm_cbe_tmp__695;

  *(&llvm_cbe_tmp__691) = llvm_cbe_this;
  *(&llvm_cbe_tmp__692) = llvm_cbe_d;
  llvm_cbe_tmp__693 = *(&llvm_cbe_tmp__691);
  llvm_cbe_tmp__694 = *(&llvm_cbe_tmp__692);
  llvm_cbe_tmp__695 = *llvm_cbe_tmp__694;
  *((&llvm_cbe_tmp__693->field0)) = llvm_cbe_tmp__695;
  return;
}


unsigned char *_ZN11SysCArray2DIhLj2ELj512EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__696;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__697;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__698;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__699;
  unsigned int llvm_cbe_tmp__700;
  unsigned char *llvm_cbe_tmp__701;
  unsigned int llvm_cbe_tmp__702;
  unsigned char *llvm_cbe_tmp__703;
  unsigned char *llvm_cbe_tmp__704;

  *(&llvm_cbe_tmp__697) = llvm_cbe_this;
  *(&llvm_cbe_tmp__698) = llvm_cbe_Xidx;
  llvm_cbe_tmp__699 = *(&llvm_cbe_tmp__697);
  llvm_cbe_tmp__700 = *(&llvm_cbe_tmp__698);
  if ((llvm_cbe_tmp__700 == 0u)) {
    goto llvm_cbe_tmp__705;
  } else {
    goto llvm_cbe_tmp__706;
  }

llvm_cbe_tmp__705:
  llvm_cbe_tmp__701 = *((&llvm_cbe_tmp__699->field1));
  *(&llvm_cbe_tmp__696) = llvm_cbe_tmp__701;
  goto llvm_cbe_tmp__707;

llvm_cbe_tmp__706:
  llvm_cbe_tmp__702 = *(&llvm_cbe_tmp__698);
  llvm_cbe_tmp__703 = *((&llvm_cbe_tmp__699->field0));
  *(&llvm_cbe_tmp__696) = ((&llvm_cbe_tmp__703[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__702) * ((unsigned int )512u)))))))]));
  goto llvm_cbe_tmp__707;

llvm_cbe_tmp__707:
  llvm_cbe_tmp__704 = *(&llvm_cbe_tmp__696);
  return llvm_cbe_tmp__704;
}


unsigned char *_ZN11SysCArray2DIhLj2ELj128EEixEj(struct l_class_OC_SysCArray2D *llvm_cbe_this, unsigned int llvm_cbe_Xidx) {
  unsigned char *llvm_cbe_tmp__708;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__709;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__710;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__711;
  unsigned int llvm_cbe_tmp__712;
  unsigned char *llvm_cbe_tmp__713;
  unsigned int llvm_cbe_tmp__714;
  unsigned char *llvm_cbe_tmp__715;
  unsigned char *llvm_cbe_tmp__716;

  *(&llvm_cbe_tmp__709) = llvm_cbe_this;
  *(&llvm_cbe_tmp__710) = llvm_cbe_Xidx;
  llvm_cbe_tmp__711 = *(&llvm_cbe_tmp__709);
  llvm_cbe_tmp__712 = *(&llvm_cbe_tmp__710);
  if ((llvm_cbe_tmp__712 == 0u)) {
    goto llvm_cbe_tmp__717;
  } else {
    goto llvm_cbe_tmp__718;
  }

llvm_cbe_tmp__717:
  llvm_cbe_tmp__713 = *((&llvm_cbe_tmp__711->field1));
  *(&llvm_cbe_tmp__708) = llvm_cbe_tmp__713;
  goto llvm_cbe_tmp__719;

llvm_cbe_tmp__718:
  llvm_cbe_tmp__714 = *(&llvm_cbe_tmp__710);
  llvm_cbe_tmp__715 = *((&llvm_cbe_tmp__711->field0));
  *(&llvm_cbe_tmp__708) = ((&llvm_cbe_tmp__715[((signed long long )(((unsigned long long )(unsigned int )(((unsigned int )(((unsigned int )llvm_cbe_tmp__714) * ((unsigned int )128u)))))))]));
  goto llvm_cbe_tmp__719;

llvm_cbe_tmp__719:
  llvm_cbe_tmp__716 = *(&llvm_cbe_tmp__708);
  return llvm_cbe_tmp__716;
}


unsigned short _ZN13sc_signal_u164readEv(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__720;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__721;
  unsigned short llvm_cbe_tmp__722;

  *(&llvm_cbe_tmp__720) = llvm_cbe_this;
  llvm_cbe_tmp__721 = *(&llvm_cbe_tmp__720);
  llvm_cbe_tmp__722 = *((&llvm_cbe_tmp__721->field0));
  return llvm_cbe_tmp__722;
}


void _ZN3rbm5storeEv(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__723;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__724;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__725;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__726;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__727;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__728;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__729;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__730;    /* Address-exposed local */
  unsigned short llvm_cbe_ntu;    /* Address-exposed local */
  unsigned short llvm_cbe_nm;    /* Address-exposed local */
  unsigned int llvm_cbe_index;    /* Address-exposed local */
  unsigned char llvm_cbe_rating;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__731;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__732;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__733;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__734;    /* Address-exposed local */
  unsigned int llvm_cbe_dma_index;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__735;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__736;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__737;    /* Address-exposed local */
  unsigned short llvm_cbe_i;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__738;    /* Address-exposed local */
  unsigned char llvm_cbe_tmp__739;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__740;
  bool llvm_cbe_tmp__741;
  bool llvm_cbe_tmp__742;
  unsigned short llvm_cbe_tmp__743;
  unsigned short llvm_cbe_tmp__744;
  unsigned int llvm_cbe_tmp__745;
  unsigned short llvm_cbe_tmp__746;
  bool llvm_cbe_tmp__747;
  bool llvm_cbe_tmp__748;
  unsigned short llvm_cbe_tmp__749;
  unsigned int llvm_cbe_tmp__750;
  unsigned short llvm_cbe_tmp__751;
  unsigned int llvm_cbe_tmp__752;
  bool llvm_cbe_tmp__753;
  unsigned short llvm_cbe_tmp__754;
  unsigned short llvm_cbe_tmp__755;
  unsigned short llvm_cbe_tmp__756;
  unsigned short llvm_cbe_tmp__757;
  unsigned char *llvm_cbe_tmp__758;
  unsigned char llvm_cbe_tmp__759;
  unsigned char llvm_cbe_tmp__760;
  unsigned short llvm_cbe_tmp__761;

  *(&llvm_cbe_tmp__723) = llvm_cbe_this;
  llvm_cbe_tmp__740 = *(&llvm_cbe_tmp__723);
  *(&llvm_cbe_tmp__724) = ((unsigned char )1);
  llvm_cbe_tmp__741 = ((_ZN14sc_signal_boolaSERKb(((&llvm_cbe_tmp__740->field36)), (&llvm_cbe_tmp__724)))&1);
  *(&llvm_cbe_tmp__725) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__740->field8)), (&llvm_cbe_tmp__725));
  *(&llvm_cbe_tmp__726) = 0u;
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__740->field7)), (&llvm_cbe_tmp__726));
  *(&llvm_cbe_tmp__727) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field9)), (&llvm_cbe_tmp__727));
  *(&llvm_cbe_tmp__728) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field44)), (&llvm_cbe_tmp__728));
  *(&llvm_cbe_tmp__729) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field45)), (&llvm_cbe_tmp__729));
  *(&llvm_cbe_tmp__730) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field12)), (&llvm_cbe_tmp__730));
  goto llvm_cbe_tmp__762;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__762:
  _Z4waitv();
  llvm_cbe_tmp__742 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__740->field36))))&1);
  if ((((llvm_cbe_tmp__742 ^ 1)&1))) {
    goto llvm_cbe_tmp__762;
  } else {
    goto llvm_cbe_tmp__763;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__763:
  llvm_cbe_tmp__743 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__740->field34)));
  *(&llvm_cbe_ntu) = llvm_cbe_tmp__743;
  llvm_cbe_tmp__744 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__740->field35)));
  *(&llvm_cbe_nm) = llvm_cbe_tmp__744;
  *(&llvm_cbe_index) = 0u;
  goto llvm_cbe_tmp__764;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__764:
  llvm_cbe_tmp__745 = *(&llvm_cbe_index);
  llvm_cbe_tmp__746 = *(&llvm_cbe_ntu);
  if ((llvm_cbe_tmp__745 == (((unsigned int )(unsigned short )llvm_cbe_tmp__746)))) {
    goto llvm_cbe_tmp__765;
  } else {
    goto llvm_cbe_tmp__766;
  }

llvm_cbe_tmp__767:
  *(&llvm_cbe_tmp__739) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field45)), (&llvm_cbe_tmp__739));
  goto llvm_cbe_tmp__764;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__768:
  llvm_cbe_tmp__754 = *(&llvm_cbe_i);
  if ((((signed int )(((unsigned int )(unsigned short )llvm_cbe_tmp__754))) < ((signed int )100u))) {
    goto llvm_cbe_tmp__769;
  } else {
    goto llvm_cbe_tmp__767;
  }

llvm_cbe_tmp__770:
  llvm_cbe_tmp__757 = *(&llvm_cbe_i);
  llvm_cbe_tmp__758 = _ZN11SysCArray2DIhLj2ELj128EEixEj(((&llvm_cbe_tmp__740->field28)), 0u);
  llvm_cbe_tmp__759 = *((&llvm_cbe_tmp__758[((signed long long )(((unsigned long long )(unsigned short )llvm_cbe_tmp__757)))]));
  *(&llvm_cbe_rating) = llvm_cbe_tmp__759;
  _Z4waitv();
  llvm_cbe_tmp__760 = *(&llvm_cbe_rating);
  *(&llvm_cbe_tmp__738) = (((unsigned int )(unsigned char )llvm_cbe_tmp__760));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__740->field11)), (&llvm_cbe_tmp__738));
  llvm_cbe_tmp__761 = *(&llvm_cbe_i);
  *(&llvm_cbe_i) = (((unsigned short )(((unsigned short )(((unsigned short )llvm_cbe_tmp__761) + ((unsigned short )((unsigned short )1)))))));
  goto llvm_cbe_tmp__768;

llvm_cbe_tmp__769:
  llvm_cbe_tmp__755 = *(&llvm_cbe_i);
  llvm_cbe_tmp__756 = *(&llvm_cbe_nm);
  if (((((unsigned int )(unsigned short )llvm_cbe_tmp__755)) == (((unsigned int )(unsigned short )llvm_cbe_tmp__756)))) {
    goto llvm_cbe_tmp__767;
  } else {
    goto llvm_cbe_tmp__770;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__771:
  *(&llvm_cbe_tmp__737) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field9)), (&llvm_cbe_tmp__737));
  *(&llvm_cbe_i) = ((unsigned short )0);
  goto llvm_cbe_tmp__768;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__772:
  _Z4waitv();
  llvm_cbe_tmp__753 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__740->field10))))&1);
  if ((((llvm_cbe_tmp__753 ^ 1)&1))) {
    goto llvm_cbe_tmp__772;
  } else {
    goto llvm_cbe_tmp__771;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__773:
  *(&llvm_cbe_tmp__733) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field44)), (&llvm_cbe_tmp__733));
  *(&llvm_cbe_tmp__734) = ((unsigned char )0);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field45)), (&llvm_cbe_tmp__734));
  llvm_cbe_tmp__749 = *(&llvm_cbe_nm);
  llvm_cbe_tmp__750 = *(&llvm_cbe_index);
  *(&llvm_cbe_dma_index) = (((unsigned int )(((unsigned int )(((unsigned int )(unsigned short )llvm_cbe_tmp__749))) * ((unsigned int )llvm_cbe_tmp__750))));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__740->field7)), (&llvm_cbe_dma_index));
  llvm_cbe_tmp__751 = _ZN13sc_signal_u164readEv(((&llvm_cbe_tmp__740->field35)));
  *(&llvm_cbe_tmp__735) = (((unsigned int )(unsigned short )llvm_cbe_tmp__751));
  _ZN13sc_signal_u325writeERKj(((&llvm_cbe_tmp__740->field8)), (&llvm_cbe_tmp__735));
  llvm_cbe_tmp__752 = *(&llvm_cbe_index);
  *(&llvm_cbe_index) = (((unsigned int )(((unsigned int )llvm_cbe_tmp__752) + ((unsigned int )1u))));
  *(&llvm_cbe_tmp__736) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field9)), (&llvm_cbe_tmp__736));
  goto llvm_cbe_tmp__772;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__774:
  _Z4waitv();
  llvm_cbe_tmp__748 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__740->field43))))&1);
  if (llvm_cbe_tmp__748) {
    goto llvm_cbe_tmp__774;
  } else {
    goto llvm_cbe_tmp__773;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__775:
  *(&llvm_cbe_tmp__732) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field44)), (&llvm_cbe_tmp__732));
  goto llvm_cbe_tmp__774;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__766:
  _Z4waitv();
  llvm_cbe_tmp__747 = ((_ZN14sc_signal_bool4readEv(((&llvm_cbe_tmp__740->field43))))&1);
  if ((((llvm_cbe_tmp__747 ^ 1)&1))) {
    goto llvm_cbe_tmp__766;
  } else {
    goto llvm_cbe_tmp__775;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__765:
  *(&llvm_cbe_tmp__731) = ((unsigned char )1);
  _ZN14sc_signal_bool5writeERKb(((&llvm_cbe_tmp__740->field12)), (&llvm_cbe_tmp__731));
  goto llvm_cbe_tmp__776;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__776:
  _Z4waitv();
  goto llvm_cbe_tmp__776;

  } while (1); /* end of syntactic loop '' */
}


static void __cxx_global_var_init24(void) {
  _ZN3rbmC1Ev((&IMPL));
  return;
}


void _ZN3rbmC1Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__777;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__778;

  *(&llvm_cbe_tmp__777) = llvm_cbe_this;
  llvm_cbe_tmp__778 = *(&llvm_cbe_tmp__777);
  _ZN3rbmC2Ev(llvm_cbe_tmp__778);
  return;
}


unsigned int main(void) {
  unsigned int llvm_cbe_tmp__779;    /* Address-exposed local */
  _GLOBAL__I_a();  CODE_FOR_MAIN();
  *(&llvm_cbe_tmp__779) = 0u;
  _ZN3rbm4loadEv((&IMPL));
  return 0u;
}


void _ZN8type_memIhLj65536EEC2ERKS0_(struct l_class_OC_SysCArray1D *llvm_cbe_this, struct l_class_OC_SysCArray1D *llvm_cbe_r) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__780;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__781;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__782;
  unsigned char *llvm_cbe_tmp__783;
  unsigned char *llvm_cbe_tmp__784;
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__785;
  unsigned char *llvm_cbe_tmp__786;

  *(&llvm_cbe_tmp__780) = llvm_cbe_this;
  *(&llvm_cbe_tmp__781) = llvm_cbe_r;
  llvm_cbe_tmp__782 = *(&llvm_cbe_tmp__780);
  llvm_cbe_tmp__783 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__782->field0)) = llvm_cbe_tmp__783;
  llvm_cbe_tmp__784 = *((&llvm_cbe_tmp__782->field0));
  llvm_cbe_tmp__785 = *(&llvm_cbe_tmp__781);
  llvm_cbe_tmp__786 = *((&llvm_cbe_tmp__785->field0));
  __CPROVER_array_copy(llvm_cbe_tmp__784, llvm_cbe_tmp__786);
  return;
}


void _ZN8type_memIhLj65536EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__787;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__788;

  *(&llvm_cbe_tmp__787) = llvm_cbe_this;
  llvm_cbe_tmp__788 = *(&llvm_cbe_tmp__787);
  return;
}


void _ZN3rbmC2Ev(struct l_struct_OC_rbm *llvm_cbe_this) {
  struct l_struct_OC_rbm *llvm_cbe_tmp__789;    /* Address-exposed local */
  struct l_struct_OC_rbm *llvm_cbe_tmp__790;
  unsigned char *llvm_cbe_tmp__791;
  unsigned char llvm_cbe_tmp__792;
  unsigned char *llvm_cbe_tmp__793;
  unsigned char llvm_cbe_tmp__794;
  unsigned char *llvm_cbe_tmp__795;
  unsigned char llvm_cbe_tmp__796;
  unsigned char *llvm_cbe_tmp__797;
  unsigned char llvm_cbe_tmp__798;
  unsigned char *llvm_cbe_tmp__799;
  unsigned char llvm_cbe_tmp__800;

  *(&llvm_cbe_tmp__789) = llvm_cbe_this;
  llvm_cbe_tmp__790 = *(&llvm_cbe_tmp__789);
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__790->field0)), ((&_OC_str25.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__790->field1)), ((&_OC_str26.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field2)), ((&_OC_str27.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field3)), ((&_OC_str28.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__790->field4)), ((&_OC_str29.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__790->field5)), ((&_OC_str30.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field6)), ((&_OC_str31.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field7)), ((&_OC_str32.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field8)), ((&_OC_str33.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__790->field9)), ((&_OC_str34.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__790->field10)), ((&_OC_str35.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field11)), ((&_OC_str36.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__790->field12)), ((&_OC_str37.array[((signed int )0u)])));
  _ZN14sc_signal_boolC1EPKc(((&llvm_cbe_tmp__790->field13)), ((&_OC_str38.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field14)), ((&_OC_str39.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field15)), ((&_OC_str40.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field16)), ((&_OC_str41.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field17)), ((&_OC_str42.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field18)), ((&_OC_str43.array[((signed int )0u)])));
  _ZN13sc_signal_u32C1EPKc(((&llvm_cbe_tmp__790->field19)), ((&_OC_str44.array[((signed int )0u)])));
  _ZN11SysCArray2DIhLj2ELj512EEC1Ev(((&llvm_cbe_tmp__790->field20)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__790->field21)));
  _ZN11SysCArray1DIbLj128EEC1Ev(((&llvm_cbe_tmp__790->field22)));
  _ZN11SysCArray2DIfLj501ELj101EEC1Ev(((&llvm_cbe_tmp__790->field23)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__790->field24)));
  _ZN11SysCArray2DIbLj501ELj101EEC1Ev(((&llvm_cbe_tmp__790->field25)));
  _ZN11SysCArray1DIfLj5EEC1Ev(((&llvm_cbe_tmp__790->field26)));
  _ZN11SysCArray1DIbLj512EEC1Ev(((&llvm_cbe_tmp__790->field27)));
  _ZN11SysCArray2DIhLj2ELj128EEC1Ev(((&llvm_cbe_tmp__790->field28)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__790->field30)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__790->field31)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__790->field32)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__790->field33)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__790->field34)));
  _ZN13sc_signal_u16C1Ev(((&llvm_cbe_tmp__790->field35)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field36)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field37)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field38)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field39)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field40)));
  _ZN15sc_signal_int32C1Ev(((&llvm_cbe_tmp__790->field41)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field42)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field43)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field44)));
  _ZN14sc_signal_boolC1Ev(((&llvm_cbe_tmp__790->field45)));
  llvm_cbe_tmp__791 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__790->field1)));
  llvm_cbe_tmp__792 = *llvm_cbe_tmp__791;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__792&1u))&1)))), 0);
  llvm_cbe_tmp__793 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__790->field1)));
  llvm_cbe_tmp__794 = *llvm_cbe_tmp__793;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__794&1u))&1)))), 0);
  llvm_cbe_tmp__795 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__790->field1)));
  llvm_cbe_tmp__796 = *llvm_cbe_tmp__795;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__796&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__797 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__790->field1)));
  llvm_cbe_tmp__798 = *llvm_cbe_tmp__797;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__798&1u))&1)))), 0);
  _Z14set_stack_sizei(5242880u);
  llvm_cbe_tmp__799 = _ZN14sc_signal_boolcvRbEv(((&llvm_cbe_tmp__790->field1)));
  llvm_cbe_tmp__800 = *llvm_cbe_tmp__799;
  _Z15reset_signal_isib((((unsigned int )(bool )(((((bool )llvm_cbe_tmp__800&1u))&1)))), 0);
  return;
}


void _ZN14sc_signal_boolC1EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__801;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__802;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__803;
  unsigned char *llvm_cbe_tmp__804;

  *(&llvm_cbe_tmp__801) = llvm_cbe_this;
  *(&llvm_cbe_tmp__802) = llvm_cbe_p;
  llvm_cbe_tmp__803 = *(&llvm_cbe_tmp__801);
  llvm_cbe_tmp__804 = *(&llvm_cbe_tmp__802);
  _ZN14sc_signal_boolC2EPKc(llvm_cbe_tmp__803, llvm_cbe_tmp__804);
  return;
}


void _ZN13sc_signal_u32C1EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__805;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__806;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__807;
  unsigned char *llvm_cbe_tmp__808;

  *(&llvm_cbe_tmp__805) = llvm_cbe_this;
  *(&llvm_cbe_tmp__806) = llvm_cbe_p;
  llvm_cbe_tmp__807 = *(&llvm_cbe_tmp__805);
  llvm_cbe_tmp__808 = *(&llvm_cbe_tmp__806);
  _ZN13sc_signal_u32C2EPKc(llvm_cbe_tmp__807, llvm_cbe_tmp__808);
  return;
}


void _ZN11SysCArray2DIhLj2ELj512EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__809;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__810;

  *(&llvm_cbe_tmp__809) = llvm_cbe_this;
  llvm_cbe_tmp__810 = *(&llvm_cbe_tmp__809);
  _ZN11SysCArray2DIhLj2ELj512EEC2Ev(llvm_cbe_tmp__810);
  return;
}


void _ZN11SysCArray1DIbLj512EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__811;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__812;

  *(&llvm_cbe_tmp__811) = llvm_cbe_this;
  llvm_cbe_tmp__812 = *(&llvm_cbe_tmp__811);
  _ZN11SysCArray1DIbLj512EEC2Ev(llvm_cbe_tmp__812);
  return;
}


void _ZN11SysCArray1DIbLj128EEC1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__813;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__814;

  *(&llvm_cbe_tmp__813) = llvm_cbe_this;
  llvm_cbe_tmp__814 = *(&llvm_cbe_tmp__813);
  _ZN11SysCArray1DIbLj128EEC2Ev(llvm_cbe_tmp__814);
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC1Ev(struct l_unnamed3 *llvm_cbe_this) {
  struct l_unnamed3 *llvm_cbe_tmp__815;    /* Address-exposed local */
  struct l_unnamed3 *llvm_cbe_tmp__816;

  *(&llvm_cbe_tmp__815) = llvm_cbe_this;
  llvm_cbe_tmp__816 = *(&llvm_cbe_tmp__815);
  _ZN11SysCArray2DIfLj501ELj101EEC2Ev(llvm_cbe_tmp__816);
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__817;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__818;

  *(&llvm_cbe_tmp__817) = llvm_cbe_this;
  llvm_cbe_tmp__818 = *(&llvm_cbe_tmp__817);
  _ZN11SysCArray2DIbLj501ELj101EEC2Ev(llvm_cbe_tmp__818);
  return;
}


void _ZN11SysCArray1DIfLj5EEC1Ev(struct l_unnamed4 *llvm_cbe_this) {
  struct l_unnamed4 *llvm_cbe_tmp__819;    /* Address-exposed local */
  struct l_unnamed4 *llvm_cbe_tmp__820;

  *(&llvm_cbe_tmp__819) = llvm_cbe_this;
  llvm_cbe_tmp__820 = *(&llvm_cbe_tmp__819);
  _ZN11SysCArray1DIfLj5EEC2Ev(llvm_cbe_tmp__820);
  return;
}


void _ZN11SysCArray2DIhLj2ELj128EEC1Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__821;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__822;

  *(&llvm_cbe_tmp__821) = llvm_cbe_this;
  llvm_cbe_tmp__822 = *(&llvm_cbe_tmp__821);
  _ZN11SysCArray2DIhLj2ELj128EEC2Ev(llvm_cbe_tmp__822);
  return;
}


void _ZN13sc_signal_u16C1Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__823;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__824;

  *(&llvm_cbe_tmp__823) = llvm_cbe_this;
  llvm_cbe_tmp__824 = *(&llvm_cbe_tmp__823);
  _ZN13sc_signal_u16C2Ev(llvm_cbe_tmp__824);
  return;
}


void _ZN14sc_signal_boolC1Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__825;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__826;

  *(&llvm_cbe_tmp__825) = llvm_cbe_this;
  llvm_cbe_tmp__826 = *(&llvm_cbe_tmp__825);
  _ZN14sc_signal_boolC2Ev(llvm_cbe_tmp__826);
  return;
}


void _ZN15sc_signal_int32C1Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__827;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__828;

  *(&llvm_cbe_tmp__827) = llvm_cbe_this;
  llvm_cbe_tmp__828 = *(&llvm_cbe_tmp__827);
  _ZN15sc_signal_int32C2Ev(llvm_cbe_tmp__828);
  return;
}


unsigned char *_ZN14sc_signal_boolcvRbEv(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__829;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__830;

  *(&llvm_cbe_tmp__829) = llvm_cbe_this;
  llvm_cbe_tmp__830 = *(&llvm_cbe_tmp__829);
  return ((&llvm_cbe_tmp__830->field0));
}


void _ZN15sc_signal_int32C2Ev(struct l_class_OC_sc_signal_int32 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__831;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__832;

  *(&llvm_cbe_tmp__831) = llvm_cbe_this;
  llvm_cbe_tmp__832 = *(&llvm_cbe_tmp__831);
  return;
}


void _ZN14sc_signal_boolC2Ev(struct l_class_OC_sc_signal_bool *llvm_cbe_this) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__833;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__834;

  *(&llvm_cbe_tmp__833) = llvm_cbe_this;
  llvm_cbe_tmp__834 = *(&llvm_cbe_tmp__833);
  return;
}


void _ZN13sc_signal_u16C2Ev(struct l_class_OC_sc_signal_u16 *llvm_cbe_this) {
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__835;    /* Address-exposed local */
  struct l_class_OC_sc_signal_u16 *llvm_cbe_tmp__836;

  *(&llvm_cbe_tmp__835) = llvm_cbe_this;
  llvm_cbe_tmp__836 = *(&llvm_cbe_tmp__835);
  return;
}


void _ZN11SysCArray2DIhLj2ELj128EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__837;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__838;
  unsigned char *llvm_cbe_tmp__839;
  unsigned char *llvm_cbe_tmp__840;

  *(&llvm_cbe_tmp__837) = llvm_cbe_this;
  llvm_cbe_tmp__838 = *(&llvm_cbe_tmp__837);
  llvm_cbe_tmp__839 = __CPROVER_malloc(256ull);
  *((&llvm_cbe_tmp__838->field0)) = llvm_cbe_tmp__839;
  llvm_cbe_tmp__840 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__838->field1)) = llvm_cbe_tmp__840;
  return;
}


void _ZN11SysCArray1DIfLj5EEC2Ev(struct l_unnamed4 *llvm_cbe_this) {
  struct l_unnamed4 *llvm_cbe_tmp__841;    /* Address-exposed local */
  struct l_unnamed4 *llvm_cbe_tmp__842;
  unsigned char *llvm_cbe_tmp__843;

  *(&llvm_cbe_tmp__841) = llvm_cbe_this;
  llvm_cbe_tmp__842 = *(&llvm_cbe_tmp__841);
  llvm_cbe_tmp__843 = __CPROVER_malloc(20ull);
  *((&llvm_cbe_tmp__842->field0)) = (((float *)llvm_cbe_tmp__843));
  return;
}


void _ZN11SysCArray2DIbLj501ELj101EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__844;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__845;
  unsigned char *llvm_cbe_tmp__846;
  unsigned char *llvm_cbe_tmp__847;

  *(&llvm_cbe_tmp__844) = llvm_cbe_this;
  llvm_cbe_tmp__845 = *(&llvm_cbe_tmp__844);
  llvm_cbe_tmp__846 = __CPROVER_malloc(50601ull);
  *((&llvm_cbe_tmp__845->field0)) = llvm_cbe_tmp__846;
  llvm_cbe_tmp__847 = __CPROVER_malloc(101ull);
  *((&llvm_cbe_tmp__845->field1)) = llvm_cbe_tmp__847;
  return;
}


void _ZN11SysCArray2DIfLj501ELj101EEC2Ev(struct l_unnamed3 *llvm_cbe_this) {
  struct l_unnamed3 *llvm_cbe_tmp__848;    /* Address-exposed local */
  struct l_unnamed3 *llvm_cbe_tmp__849;
  unsigned char *llvm_cbe_tmp__850;
  unsigned char *llvm_cbe_tmp__851;

  *(&llvm_cbe_tmp__848) = llvm_cbe_this;
  llvm_cbe_tmp__849 = *(&llvm_cbe_tmp__848);
  llvm_cbe_tmp__850 = __CPROVER_malloc(202404ull);
  *((&llvm_cbe_tmp__849->field0)) = (((float *)llvm_cbe_tmp__850));
  llvm_cbe_tmp__851 = __CPROVER_malloc(404ull);
  *((&llvm_cbe_tmp__849->field1)) = (((float *)llvm_cbe_tmp__851));
  return;
}


void _ZN11SysCArray1DIbLj128EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__852;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__853;
  unsigned char *llvm_cbe_tmp__854;

  *(&llvm_cbe_tmp__852) = llvm_cbe_this;
  llvm_cbe_tmp__853 = *(&llvm_cbe_tmp__852);
  llvm_cbe_tmp__854 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__853->field0)) = llvm_cbe_tmp__854;
  return;
}


void _ZN11SysCArray1DIbLj512EEC2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__855;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__856;
  unsigned char *llvm_cbe_tmp__857;

  *(&llvm_cbe_tmp__855) = llvm_cbe_this;
  llvm_cbe_tmp__856 = *(&llvm_cbe_tmp__855);
  llvm_cbe_tmp__857 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__856->field0)) = llvm_cbe_tmp__857;
  return;
}


void _ZN11SysCArray2DIhLj2ELj512EEC2Ev(struct l_class_OC_SysCArray2D *llvm_cbe_this) {
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__858;    /* Address-exposed local */
  struct l_class_OC_SysCArray2D *llvm_cbe_tmp__859;
  unsigned char *llvm_cbe_tmp__860;
  unsigned char *llvm_cbe_tmp__861;

  *(&llvm_cbe_tmp__858) = llvm_cbe_this;
  llvm_cbe_tmp__859 = *(&llvm_cbe_tmp__858);
  llvm_cbe_tmp__860 = __CPROVER_malloc(1024ull);
  *((&llvm_cbe_tmp__859->field0)) = llvm_cbe_tmp__860;
  llvm_cbe_tmp__861 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__859->field1)) = llvm_cbe_tmp__861;
  return;
}


void _ZN13sc_signal_u32C2EPKc(struct l_class_OC_sc_signal_int32 *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__862;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__863;    /* Address-exposed local */
  struct l_class_OC_sc_signal_int32 *llvm_cbe_tmp__864;

  *(&llvm_cbe_tmp__862) = llvm_cbe_this;
  *(&llvm_cbe_tmp__863) = llvm_cbe_p;
  llvm_cbe_tmp__864 = *(&llvm_cbe_tmp__862);
  return;
}


void _ZN14sc_signal_boolC2EPKc(struct l_class_OC_sc_signal_bool *llvm_cbe_this, unsigned char *llvm_cbe_p) {
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__865;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__866;    /* Address-exposed local */
  struct l_class_OC_sc_signal_bool *llvm_cbe_tmp__867;

  *(&llvm_cbe_tmp__865) = llvm_cbe_this;
  *(&llvm_cbe_tmp__866) = llvm_cbe_p;
  llvm_cbe_tmp__867 = *(&llvm_cbe_tmp__865);
  return;
}


void _ZN13model_computeD2Ev(struct l_class_OC_model_compute *llvm_cbe_this) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__868;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__869;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__870;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__871;

  *(&llvm_cbe_tmp__868) = llvm_cbe_this;
  llvm_cbe_tmp__871 = *(&llvm_cbe_tmp__868);
  _ZN8type_memIhLj128EED1Ev(((&llvm_cbe_tmp__871->field14)));
  _ZN8type_memIhLj65536EED1Ev(((&llvm_cbe_tmp__871->field3)));
  _ZN8type_memIhLj512EED1Ev(((&llvm_cbe_tmp__871->field0)));
  return;
}


void _ZN8type_memIhLj128EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__872;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__873;

  *(&llvm_cbe_tmp__872) = llvm_cbe_this;
  llvm_cbe_tmp__873 = *(&llvm_cbe_tmp__872);
  _ZN8type_memIhLj128EED2Ev(llvm_cbe_tmp__873);
  return;
}


void _ZN8type_memIhLj512EED1Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__874;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__875;

  *(&llvm_cbe_tmp__874) = llvm_cbe_this;
  llvm_cbe_tmp__875 = *(&llvm_cbe_tmp__874);
  _ZN8type_memIhLj512EED2Ev(llvm_cbe_tmp__875);
  return;
}


void _ZN8type_memIhLj512EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__876;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__877;

  *(&llvm_cbe_tmp__876) = llvm_cbe_this;
  llvm_cbe_tmp__877 = *(&llvm_cbe_tmp__876);
  return;
}


void _ZN8type_memIhLj128EED2Ev(struct l_class_OC_SysCArray1D *llvm_cbe_this) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__878;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__879;

  *(&llvm_cbe_tmp__878) = llvm_cbe_this;
  llvm_cbe_tmp__879 = *(&llvm_cbe_tmp__878);
  return;
}


void _ZN13model_computeC2Ev(struct l_class_OC_model_compute *llvm_cbe_this) {
  struct l_class_OC_model_compute *llvm_cbe_tmp__880;    /* Address-exposed local */
  unsigned char *llvm_cbe_tmp__881;    /* Address-exposed local */
  unsigned int llvm_cbe_tmp__882;    /* Address-exposed local */
  struct l_class_OC_model_compute *llvm_cbe_tmp__883;

  *(&llvm_cbe_tmp__880) = llvm_cbe_this;
  llvm_cbe_tmp__883 = *(&llvm_cbe_tmp__880);
  _ZN8type_memIhLj512EEC1El(((&llvm_cbe_tmp__883->field0)), 0ull);
  _ZN8type_memIhLj65536EEC1El(((&llvm_cbe_tmp__883->field3)), 0ull);
  _ZN8type_memIhLj128EEC1El(((&llvm_cbe_tmp__883->field14)), 0ull);
  *((&llvm_cbe_tmp__883->field25)) = 65535ull;
  *((&llvm_cbe_tmp__883->field26)) = 4294967295ull;
  return;
}


void _ZN8type_memIhLj512EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__884;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__885;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__886;
  unsigned long long llvm_cbe_tmp__887;

  *(&llvm_cbe_tmp__884) = llvm_cbe_this;
  *(&llvm_cbe_tmp__885) = llvm_cbe_def;
  llvm_cbe_tmp__886 = *(&llvm_cbe_tmp__884);
  llvm_cbe_tmp__887 = *(&llvm_cbe_tmp__885);
  _ZN8type_memIhLj512EEC2El(llvm_cbe_tmp__886, llvm_cbe_tmp__887);
  return;
}


void _ZN8type_memIhLj65536EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__888;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__889;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__890;
  unsigned long long llvm_cbe_tmp__891;

  *(&llvm_cbe_tmp__888) = llvm_cbe_this;
  *(&llvm_cbe_tmp__889) = llvm_cbe_def;
  llvm_cbe_tmp__890 = *(&llvm_cbe_tmp__888);
  llvm_cbe_tmp__891 = *(&llvm_cbe_tmp__889);
  _ZN8type_memIhLj65536EEC2El(llvm_cbe_tmp__890, llvm_cbe_tmp__891);
  return;
}


void _ZN8type_memIhLj128EEC1El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__892;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__893;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__894;
  unsigned long long llvm_cbe_tmp__895;

  *(&llvm_cbe_tmp__892) = llvm_cbe_this;
  *(&llvm_cbe_tmp__893) = llvm_cbe_def;
  llvm_cbe_tmp__894 = *(&llvm_cbe_tmp__892);
  llvm_cbe_tmp__895 = *(&llvm_cbe_tmp__893);
  _ZN8type_memIhLj128EEC2El(llvm_cbe_tmp__894, llvm_cbe_tmp__895);
  return;
}


void _ZN8type_memIhLj128EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__896;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__897;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__898;
  unsigned char *llvm_cbe_tmp__899;

  *(&llvm_cbe_tmp__896) = llvm_cbe_this;
  *(&llvm_cbe_tmp__897) = llvm_cbe_def;
  llvm_cbe_tmp__898 = *(&llvm_cbe_tmp__896);
  llvm_cbe_tmp__899 = __CPROVER_malloc(128ull);
  *((&llvm_cbe_tmp__898->field0)) = llvm_cbe_tmp__899;
  return;
}


void _ZN8type_memIhLj65536EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__900;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__901;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__902;
  unsigned char *llvm_cbe_tmp__903;

  *(&llvm_cbe_tmp__900) = llvm_cbe_this;
  *(&llvm_cbe_tmp__901) = llvm_cbe_def;
  llvm_cbe_tmp__902 = *(&llvm_cbe_tmp__900);
  llvm_cbe_tmp__903 = __CPROVER_malloc(65536ull);
  *((&llvm_cbe_tmp__902->field0)) = llvm_cbe_tmp__903;
  return;
}


void _ZN8type_memIhLj512EEC2El(struct l_class_OC_SysCArray1D *llvm_cbe_this, unsigned long long llvm_cbe_def) {
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__904;    /* Address-exposed local */
  unsigned long long llvm_cbe_tmp__905;    /* Address-exposed local */
  struct l_class_OC_SysCArray1D *llvm_cbe_tmp__906;
  unsigned char *llvm_cbe_tmp__907;

  *(&llvm_cbe_tmp__904) = llvm_cbe_this;
  *(&llvm_cbe_tmp__905) = llvm_cbe_def;
  llvm_cbe_tmp__906 = *(&llvm_cbe_tmp__904);
  llvm_cbe_tmp__907 = __CPROVER_malloc(512ull);
  *((&llvm_cbe_tmp__906->field0)) = llvm_cbe_tmp__907;
  return;
}


static void _GLOBAL__I_a(void) {
  __cxx_global_var_init();
  __cxx_global_var_init24();
  return;
}

