#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wcast-qual"
#define __NV_CUBIN_HANDLE_STORAGE__ static
#include "crt/host_runtime.h"
#include "tbar.fatbin.c"
extern void __device_stub__Z3dotPiS_S_(int *, int *, int *);
static void __nv_cudaEntityRegisterCallback(void **);
static void __sti____cudaRegisterAll_12_tbar_cpp1_ii_703abff6(void) __attribute__((__constructor__));
void __device_stub__Z3dotPiS_S_(int *__par0, int *__par1, int *__par2){__cudaSetupArgSimple(__par0, 0UL);__cudaSetupArgSimple(__par1, 8UL);__cudaSetupArgSimple(__par2, 16UL);__cudaLaunch(((char *)((void ( *)(int *, int *, int *))dot)));}
# 64 "tbar.cu"
void dot( int *__cuda_0,int *__cuda_1,int *__cuda_2)
# 64 "tbar.cu"
{__device_stub__Z3dotPiS_S_( __cuda_0,__cuda_1,__cuda_2);
# 105 "tbar.cu"
}
# 1 "tbar.cudafe1.stub.c"
static void __nv_cudaEntityRegisterCallback( void **__T20) {  __nv_dummy_param_ref(__T20); __nv_save_fatbinhandle_for_managed_rt(__T20); __cudaRegisterEntry(__T20, ((void ( *)(int *, int *, int *))dot), _Z3dotPiS_S_, (-1)); }
static void __sti____cudaRegisterAll_12_tbar_cpp1_ii_703abff6(void) {  __cudaRegisterBinary(__nv_cudaEntityRegisterCallback);  }

#pragma GCC diagnostic pop
