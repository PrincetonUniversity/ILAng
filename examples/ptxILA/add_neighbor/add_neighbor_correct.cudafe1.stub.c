#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wcast-qual"
#define __NV_CUBIN_HANDLE_STORAGE__ static
#include "crt/host_runtime.h"
#include "add_neighbor_correct.fatbin.c"
extern void __device_stub__Z13add_neighbourPii(int *, int);
static void __nv_cudaEntityRegisterCallback(void **);
static void __sti____cudaRegisterAll_28_add_neighbor_correct_cpp1_ii_98686d1f(void) __attribute__((__constructor__));
void __device_stub__Z13add_neighbourPii(int *__par0, int __par1){__cudaSetupArgSimple(__par0, 0UL);__cudaSetupArgSimple(__par1, 8UL);__cudaLaunch(((char *)((void ( *)(int *, int))add_neighbour)));}
# 13 "add_neighbor_correct.cu"
void add_neighbour( int *__cuda_0,int __cuda_1)
# 13 "add_neighbor_correct.cu"
{__device_stub__Z13add_neighbourPii( __cuda_0,__cuda_1);
# 20 "add_neighbor_correct.cu"
}
# 1 "add_neighbor_correct.cudafe1.stub.c"
static void __nv_cudaEntityRegisterCallback( void **__T20) {  __nv_dummy_param_ref(__T20); __nv_save_fatbinhandle_for_managed_rt(__T20); __cudaRegisterEntry(__T20, ((void ( *)(int *, int))add_neighbour), _Z13add_neighbourPii, (-1)); }
static void __sti____cudaRegisterAll_28_add_neighbor_correct_cpp1_ii_98686d1f(void) {  __cudaRegisterBinary(__nv_cudaEntityRegisterCallback);  }

#pragma GCC diagnostic pop
