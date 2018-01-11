#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wcast-qual"
#define __NV_CUBIN_HANDLE_STORAGE__ static
#include "crt/host_runtime.h"
#include "t266.fatbin.c"
extern void __device_stub__Z3dotPi(int *);
static void __nv_cudaEntityRegisterCallback(void **);
static void __sti____cudaRegisterAll_12_t266_cpp1_ii__Z3dotPi(void) __attribute__((__constructor__));
void __device_stub__Z3dotPi(int *__par0){__cudaSetupArgSimple(__par0, 0UL);__cudaLaunch(((char *)((void ( *)(int *))dot)));}
# 13 "t266.cu"
void dot( int *__cuda_0)
# 13 "t266.cu"
{__device_stub__Z3dotPi( __cuda_0);
# 35 "t266.cu"
}
# 1 "t266.cudafe1.stub.c"
static void __nv_cudaEntityRegisterCallback( void **__T20) {  __nv_dummy_param_ref(__T20); __nv_save_fatbinhandle_for_managed_rt(__T20); __cudaRegisterEntry(__T20, ((void ( *)(int *))dot), _Z3dotPi, (-1)); }
static void __sti____cudaRegisterAll_12_t266_cpp1_ii__Z3dotPi(void) {  __cudaRegisterBinary(__nv_cudaEntityRegisterCallback);  }

#pragma GCC diagnostic pop
