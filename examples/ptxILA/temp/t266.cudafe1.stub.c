#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wcast-qual"
#define __NV_CUBIN_HANDLE_STORAGE__ static
#include "crt/host_runtime.h"
#include "t266.fatbin.c"
extern void __device_stub__Z3dotPfS_S_(float *, float *, float *);
static void __nv_cudaEntityRegisterCallback(void **);
static void __sti____cudaRegisterAll_12_t266_cpp1_ii_f26a2827(void) __attribute__((__constructor__));
void __device_stub__Z3dotPfS_S_(float *__par0, float *__par1, float *__par2){__cudaSetupArgSimple(__par0, 0UL);__cudaSetupArgSimple(__par1, 8UL);__cudaSetupArgSimple(__par2, 16UL);__cudaLaunch(((char *)((void ( *)(float *, float *, float *))dot)));}
# 13 "t266.cu"
void dot( float *__cuda_0,float *__cuda_1,float *__cuda_2)
# 13 "t266.cu"
{__device_stub__Z3dotPfS_S_( __cuda_0,__cuda_1,__cuda_2);
# 28 "t266.cu"
}
# 1 "t266.cudafe1.stub.c"
static void __nv_cudaEntityRegisterCallback( void **__T20) {  __nv_dummy_param_ref(__T20); __nv_save_fatbinhandle_for_managed_rt(__T20); __cudaRegisterEntry(__T20, ((void ( *)(float *, float *, float *))dot), _Z3dotPfS_S_, (-1)); }
static void __sti____cudaRegisterAll_12_t266_cpp1_ii_f26a2827(void) {  __cudaRegisterBinary(__nv_cudaEntityRegisterCallback);  }

#pragma GCC diagnostic pop
