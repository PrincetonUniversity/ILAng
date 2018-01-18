# 1 "t266.cudafe1.gpu"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3
# 1 "<command-line>" 2
# 1 "t266.cudafe1.gpu"
typedef char __nv_bool;
# 1482 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
struct CUstream_st;
# 54 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
enum cudaDataType_t {
# 56 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_R_16F = 2,
# 57 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_C_16F = 6,
# 58 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_R_32F = 0,
# 59 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_C_32F = 4,
# 60 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_R_64F = 1,
# 61 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_C_64F = 5,
# 62 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_R_8I = 3,
# 63 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_C_8I = 7,
# 64 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_R_8U,
# 65 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_C_8U,
# 66 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_R_32I,
# 67 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_C_32I,
# 68 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_R_32U,
# 69 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
CUDA_C_32U};
# 73 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
enum libraryPropertyType_t {
# 75 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
MAJOR_VERSION,
# 76 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
MINOR_VERSION,
# 77 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
PATCH_LEVEL};
# 181 "/usr/include/libio.h" 3
enum __codecvt_result {
# 183 "/usr/include/libio.h" 3
__codecvt_ok,
# 184 "/usr/include/libio.h" 3
__codecvt_partial,
# 185 "/usr/include/libio.h" 3
__codecvt_error,
# 186 "/usr/include/libio.h" 3
__codecvt_noconv};
# 191 "/usr/include/math.h" 3
enum _ZUt_ {
# 192 "/usr/include/math.h" 3
FP_NAN,
# 195 "/usr/include/math.h" 3
FP_INFINITE,
# 198 "/usr/include/math.h" 3
FP_ZERO,
# 201 "/usr/include/math.h" 3
FP_SUBNORMAL,
# 204 "/usr/include/math.h" 3
FP_NORMAL};
# 289 "/usr/include/math.h" 3
enum _LIB_VERSION_TYPE {
# 290 "/usr/include/math.h" 3
_IEEE_ = (-1),
# 291 "/usr/include/math.h" 3
_SVID_,
# 292 "/usr/include/math.h" 3
_XOPEN_,
# 293 "/usr/include/math.h" 3
_POSIX_,
# 294 "/usr/include/math.h" 3
_ISOC_};
# 48 "/usr/include/ctype.h" 3
enum _ZUt0_ {
# 49 "/usr/include/ctype.h" 3
_ISupper = 256,
# 50 "/usr/include/ctype.h" 3
_ISlower = 512,
# 51 "/usr/include/ctype.h" 3
_ISalpha = 1024,
# 52 "/usr/include/ctype.h" 3
_ISdigit = 2048,
# 53 "/usr/include/ctype.h" 3
_ISxdigit = 4096,
# 54 "/usr/include/ctype.h" 3
_ISspace = 8192,
# 55 "/usr/include/ctype.h" 3
_ISprint = 16384,
# 56 "/usr/include/ctype.h" 3
_ISgraph = 32768,
# 57 "/usr/include/ctype.h" 3
_ISblank = 1,
# 58 "/usr/include/ctype.h" 3
_IScntrl,
# 59 "/usr/include/ctype.h" 3
_ISpunct = 4,
# 60 "/usr/include/ctype.h" 3
_ISalnum = 8};
# 33 "/usr/include/pthread.h" 3
enum _ZUt1_ {
# 34 "/usr/include/pthread.h" 3
PTHREAD_CREATE_JOINABLE,
# 36 "/usr/include/pthread.h" 3
PTHREAD_CREATE_DETACHED};
# 43 "/usr/include/pthread.h" 3
enum _ZUt2_ {
# 44 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_TIMED_NP,
# 45 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_RECURSIVE_NP,
# 46 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_ERRORCHECK_NP,
# 47 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_ADAPTIVE_NP,
# 50 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_NORMAL = 0,
# 51 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_RECURSIVE,
# 52 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_ERRORCHECK,
# 53 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_DEFAULT = 0,
# 57 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_FAST_NP = 0};
# 65 "/usr/include/pthread.h" 3
enum _ZUt3_ {
# 66 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_STALLED,
# 67 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_STALLED_NP = 0,
# 68 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_ROBUST,
# 69 "/usr/include/pthread.h" 3
PTHREAD_MUTEX_ROBUST_NP = 1};
# 77 "/usr/include/pthread.h" 3
enum _ZUt4_ {
# 78 "/usr/include/pthread.h" 3
PTHREAD_PRIO_NONE,
# 79 "/usr/include/pthread.h" 3
PTHREAD_PRIO_INHERIT,
# 80 "/usr/include/pthread.h" 3
PTHREAD_PRIO_PROTECT};
# 126 "/usr/include/pthread.h" 3
enum _ZUt5_ {
# 127 "/usr/include/pthread.h" 3
PTHREAD_RWLOCK_PREFER_READER_NP,
# 128 "/usr/include/pthread.h" 3
PTHREAD_RWLOCK_PREFER_WRITER_NP,
# 129 "/usr/include/pthread.h" 3
PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
# 130 "/usr/include/pthread.h" 3
PTHREAD_RWLOCK_DEFAULT_NP = 0};
# 167 "/usr/include/pthread.h" 3
enum _ZUt6_ {
# 168 "/usr/include/pthread.h" 3
PTHREAD_INHERIT_SCHED,
# 170 "/usr/include/pthread.h" 3
PTHREAD_EXPLICIT_SCHED};
# 177 "/usr/include/pthread.h" 3
enum _ZUt7_ {
# 178 "/usr/include/pthread.h" 3
PTHREAD_SCOPE_SYSTEM,
# 180 "/usr/include/pthread.h" 3
PTHREAD_SCOPE_PROCESS};
# 187 "/usr/include/pthread.h" 3
enum _ZUt8_ {
# 188 "/usr/include/pthread.h" 3
PTHREAD_PROCESS_PRIVATE,
# 190 "/usr/include/pthread.h" 3
PTHREAD_PROCESS_SHARED};
# 211 "/usr/include/pthread.h" 3
enum _ZUt9_ {
# 212 "/usr/include/pthread.h" 3
PTHREAD_CANCEL_ENABLE,
# 214 "/usr/include/pthread.h" 3
PTHREAD_CANCEL_DISABLE};
# 218 "/usr/include/pthread.h" 3
enum _ZUt10_ {
# 219 "/usr/include/pthread.h" 3
PTHREAD_CANCEL_DEFERRED,
# 221 "/usr/include/pthread.h" 3
PTHREAD_CANCEL_ASYNCHRONOUS};
# 72 "/usr/include/wctype.h" 3
enum _ZUt11_ {
# 73 "/usr/include/wctype.h" 3
__ISwupper,
# 74 "/usr/include/wctype.h" 3
__ISwlower,
# 75 "/usr/include/wctype.h" 3
__ISwalpha,
# 76 "/usr/include/wctype.h" 3
__ISwdigit,
# 77 "/usr/include/wctype.h" 3
__ISwxdigit,
# 78 "/usr/include/wctype.h" 3
__ISwspace,
# 79 "/usr/include/wctype.h" 3
__ISwprint,
# 80 "/usr/include/wctype.h" 3
__ISwgraph,
# 81 "/usr/include/wctype.h" 3
__ISwblank,
# 82 "/usr/include/wctype.h" 3
__ISwcntrl,
# 83 "/usr/include/wctype.h" 3
__ISwpunct,
# 84 "/usr/include/wctype.h" 3
__ISwalnum,
# 86 "/usr/include/wctype.h" 3
_ISwupper = 16777216,
# 87 "/usr/include/wctype.h" 3
_ISwlower = 33554432,
# 88 "/usr/include/wctype.h" 3
_ISwalpha = 67108864,
# 89 "/usr/include/wctype.h" 3
_ISwdigit = 134217728,
# 90 "/usr/include/wctype.h" 3
_ISwxdigit = 268435456,
# 91 "/usr/include/wctype.h" 3
_ISwspace = 536870912,
# 92 "/usr/include/wctype.h" 3
_ISwprint = 1073741824,
# 93 "/usr/include/wctype.h" 3
_ISwgraph = (-2147483647-1),
# 94 "/usr/include/wctype.h" 3
_ISwblank = 65536,
# 95 "/usr/include/wctype.h" 3
_ISwcntrl = 131072,
# 96 "/usr/include/wctype.h" 3
_ISwpunct = 262144,
# 97 "/usr/include/wctype.h" 3
_ISwalnum = 524288};
# 271 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUipcMem_flags_enum {
# 272 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS = 1};
# 280 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUmemAttach_flags_enum {
# 281 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ATTACH_GLOBAL = 1,
# 282 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ATTACH_HOST,
# 283 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ATTACH_SINGLE = 4};
# 289 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUctx_flags_enum {
# 290 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_SCHED_AUTO,
# 291 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_SCHED_SPIN,
# 292 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_SCHED_YIELD,
# 293 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_SCHED_BLOCKING_SYNC = 4,
# 294 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_BLOCKING_SYNC = 4,
# 297 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_SCHED_MASK = 7,
# 298 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_MAP_HOST,
# 299 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_LMEM_RESIZE_TO_MAX = 16,
# 300 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CTX_FLAGS_MASK = 31};
# 306 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUstream_flags_enum {
# 307 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_DEFAULT,
# 308 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_NON_BLOCKING};
# 334 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUevent_flags_enum {
# 335 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_EVENT_DEFAULT,
# 336 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_EVENT_BLOCKING_SYNC,
# 337 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_EVENT_DISABLE_TIMING,
# 338 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_EVENT_INTERPROCESS = 4};
# 345 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUstreamWaitValue_flags_enum {
# 346 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_WAIT_VALUE_GEQ,
# 348 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_WAIT_VALUE_EQ,
# 349 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_WAIT_VALUE_AND,
# 350 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_WAIT_VALUE_FLUSH = 1073741824};
# 362 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUstreamWriteValue_flags_enum {
# 363 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_WRITE_VALUE_DEFAULT,
# 364 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER};
# 375 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUstreamBatchMemOpType_enum {
# 376 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_MEM_OP_WAIT_VALUE_32 = 1,
# 377 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_MEM_OP_WRITE_VALUE_32,
# 378 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES};
# 418 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUoccupancy_flags_enum {
# 419 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_OCCUPANCY_DEFAULT,
# 420 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE};
# 426 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUarray_format_enum {
# 427 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT8 = 1,
# 428 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT16,
# 429 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_AD_FORMAT_UNSIGNED_INT32,
# 430 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_AD_FORMAT_SIGNED_INT8 = 8,
# 431 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_AD_FORMAT_SIGNED_INT16,
# 432 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_AD_FORMAT_SIGNED_INT32,
# 433 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_AD_FORMAT_HALF = 16,
# 434 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_AD_FORMAT_FLOAT = 32};
# 440 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUaddress_mode_enum {
# 441 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TR_ADDRESS_MODE_WRAP,
# 442 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TR_ADDRESS_MODE_CLAMP,
# 443 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TR_ADDRESS_MODE_MIRROR,
# 444 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TR_ADDRESS_MODE_BORDER};
# 450 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUfilter_mode_enum {
# 451 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TR_FILTER_MODE_POINT,
# 452 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TR_FILTER_MODE_LINEAR};
# 458 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUdevice_attribute_enum {
# 459 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1,
# 460 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X,
# 461 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y,
# 462 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z,
# 463 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X,
# 464 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y,
# 465 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z,
# 466 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK,
# 467 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8,
# 468 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY,
# 469 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_WARP_SIZE,
# 470 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_PITCH,
# 471 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK,
# 472 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12,
# 473 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CLOCK_RATE,
# 474 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT,
# 475 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP,
# 476 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT,
# 477 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT,
# 478 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_INTEGRATED,
# 479 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY,
# 480 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE,
# 481 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH,
# 482 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH,
# 483 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT,
# 484 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH,
# 485 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT,
# 486 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH,
# 487 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH,
# 488 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT,
# 489 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS,
# 490 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH = 27,
# 491 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT,
# 492 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES,
# 493 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT,
# 494 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS,
# 495 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_ECC_ENABLED,
# 496 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_BUS_ID,
# 497 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID,
# 498 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_TCC_DRIVER,
# 499 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE,
# 500 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH,
# 501 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE,
# 502 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR,
# 503 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT,
# 504 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING,
# 505 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH,
# 506 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS,
# 507 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_TEX2D_GATHER,
# 508 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH,
# 509 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT,
# 510 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE,
# 511 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE,
# 512 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE,
# 513 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID,
# 514 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT,
# 515 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH,
# 516 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH,
# 517 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS,
# 518 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH,
# 519 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH,
# 520 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT,
# 521 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH,
# 522 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT,
# 523 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH,
# 524 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH,
# 525 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS,
# 526 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH,
# 527 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT,
# 528 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LAYERS,
# 529 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH,
# 530 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH,
# 531 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS,
# 532 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH,
# 533 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH,
# 534 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT,
# 535 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH,
# 536 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_WIDTH,
# 537 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_HEIGHT,
# 538 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR,
# 539 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR,
# 540 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH,
# 541 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_STREAM_PRIORITIES_SUPPORTED,
# 542 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_GLOBAL_L1_CACHE_SUPPORTED,
# 543 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_LOCAL_L1_CACHE_SUPPORTED,
# 544 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR,
# 545 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_MULTIPROCESSOR,
# 546 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MANAGED_MEMORY,
# 547 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD,
# 548 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD_GROUP_ID,
# 549 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_HOST_NATIVE_ATOMIC_SUPPORTED,
# 550 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_SINGLE_TO_DOUBLE_PRECISION_PERF_RATIO,
# 551 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS,
# 552 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS,
# 553 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_COMPUTE_PREEMPTION_SUPPORTED,
# 554 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM,
# 555 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_ATTRIBUTE_MAX};
# 577 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUpointer_attribute_enum {
# 578 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_POINTER_ATTRIBUTE_CONTEXT = 1,
# 579 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_POINTER_ATTRIBUTE_MEMORY_TYPE,
# 580 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_POINTER_ATTRIBUTE_DEVICE_POINTER,
# 581 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_POINTER_ATTRIBUTE_HOST_POINTER,
# 582 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_POINTER_ATTRIBUTE_P2P_TOKENS,
# 583 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_POINTER_ATTRIBUTE_SYNC_MEMOPS,
# 584 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_POINTER_ATTRIBUTE_BUFFER_ID,
# 585 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_POINTER_ATTRIBUTE_IS_MANAGED};
# 591 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUfunction_attribute_enum {
# 597 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK,
# 604 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES,
# 610 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES,
# 615 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES,
# 620 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_NUM_REGS,
# 629 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_PTX_VERSION,
# 638 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_BINARY_VERSION,
# 644 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_CACHE_MODE_CA,
# 646 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_ATTRIBUTE_MAX};
# 652 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUfunc_cache_enum {
# 653 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_CACHE_PREFER_NONE,
# 654 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_CACHE_PREFER_SHARED,
# 655 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_CACHE_PREFER_L1,
# 656 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_FUNC_CACHE_PREFER_EQUAL};
# 662 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUsharedconfig_enum {
# 663 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE,
# 664 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE,
# 665 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE};
# 671 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUmemorytype_enum {
# 672 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEMORYTYPE_HOST = 1,
# 673 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEMORYTYPE_DEVICE,
# 674 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEMORYTYPE_ARRAY,
# 675 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEMORYTYPE_UNIFIED};
# 681 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUcomputemode_enum {
# 682 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_COMPUTEMODE_DEFAULT,
# 683 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_COMPUTEMODE_PROHIBITED = 2,
# 684 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_COMPUTEMODE_EXCLUSIVE_PROCESS};
# 690 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUmem_advise_enum {
# 691 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ADVISE_SET_READ_MOSTLY = 1,
# 692 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ADVISE_UNSET_READ_MOSTLY,
# 693 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ADVISE_SET_PREFERRED_LOCATION,
# 694 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ADVISE_UNSET_PREFERRED_LOCATION,
# 695 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ADVISE_SET_ACCESSED_BY,
# 696 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_ADVISE_UNSET_ACCESSED_BY};
# 699 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUmem_range_attribute_enum {
# 700 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY = 1,
# 701 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION,
# 702 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY,
# 703 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION};
# 709 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUjit_option_enum {
# 716 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_MAX_REGISTERS,
# 731 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_THREADS_PER_BLOCK,
# 739 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_WALL_TIME,
# 748 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_INFO_LOG_BUFFER,
# 757 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES,
# 766 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER,
# 775 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES,
# 783 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_OPTIMIZATION_LEVEL,
# 791 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_TARGET_FROM_CUCONTEXT,
# 799 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_TARGET,
# 808 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_FALLBACK_STRATEGY,
# 816 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_GENERATE_DEBUG_INFO,
# 823 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_LOG_VERBOSE,
# 830 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_GENERATE_LINE_INFO,
# 838 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_CACHE_MODE,
# 843 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_NEW_SM3X_OPT,
# 844 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_FAST_COMPILE,
# 846 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_NUM_OPTIONS};
# 853 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUjit_target_enum {
# 855 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_10 = 10,
# 856 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_11,
# 857 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_12,
# 858 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_13,
# 859 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_20 = 20,
# 860 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_21,
# 861 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_30 = 30,
# 862 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_32 = 32,
# 863 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_35 = 35,
# 864 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_37 = 37,
# 865 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_50 = 50,
# 866 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_52 = 52,
# 867 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_53,
# 868 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_60 = 60,
# 869 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_61,
# 870 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_TARGET_COMPUTE_62};
# 876 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUjit_fallback_enum {
# 878 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_PREFER_PTX,
# 880 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_PREFER_BINARY};
# 887 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUjit_cacheMode_enum {
# 889 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_CACHE_OPTION_NONE,
# 890 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_CACHE_OPTION_CG,
# 891 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_CACHE_OPTION_CA};
# 897 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUjitInputType_enum {
# 903 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_INPUT_CUBIN,
# 909 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_INPUT_PTX,
# 915 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_INPUT_FATBINARY,
# 921 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_INPUT_OBJECT,
# 927 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_INPUT_LIBRARY,
# 929 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_JIT_NUM_INPUT_TYPES};
# 939 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUgraphicsRegisterFlags_enum {
# 940 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_NONE,
# 941 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY,
# 942 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD,
# 943 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST = 4,
# 944 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER = 8};
# 950 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUgraphicsMapResourceFlags_enum {
# 951 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE,
# 952 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY,
# 953 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD};
# 959 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUarray_cubemap_face_enum {
# 960 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_X,
# 961 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_X,
# 962 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Y,
# 963 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Y,
# 964 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CUBEMAP_FACE_POSITIVE_Z,
# 965 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_CUBEMAP_FACE_NEGATIVE_Z};
# 971 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUlimit_enum {
# 972 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_LIMIT_STACK_SIZE,
# 973 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_LIMIT_PRINTF_FIFO_SIZE,
# 974 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_LIMIT_MALLOC_HEAP_SIZE,
# 975 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH,
# 976 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT,
# 977 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_LIMIT_MAX};
# 983 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUresourcetype_enum {
# 984 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RESOURCE_TYPE_ARRAY,
# 985 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RESOURCE_TYPE_MIPMAPPED_ARRAY,
# 986 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RESOURCE_TYPE_LINEAR,
# 987 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RESOURCE_TYPE_PITCH2D};
# 993 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum cudaError_enum {
# 999 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_SUCCESS,
# 1005 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_VALUE,
# 1011 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_OUT_OF_MEMORY,
# 1017 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NOT_INITIALIZED,
# 1022 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_DEINITIALIZED,
# 1029 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_PROFILER_DISABLED,
# 1037 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_PROFILER_NOT_INITIALIZED,
# 1044 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_PROFILER_ALREADY_STARTED,
# 1051 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_PROFILER_ALREADY_STOPPED,
# 1057 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NO_DEVICE = 100,
# 1063 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_DEVICE,
# 1070 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_IMAGE = 200,
# 1080 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_CONTEXT,
# 1089 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_CURRENT,
# 1094 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_MAP_FAILED = 205,
# 1099 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_UNMAP_FAILED,
# 1105 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_ARRAY_IS_MAPPED,
# 1110 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_ALREADY_MAPPED,
# 1118 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NO_BINARY_FOR_GPU,
# 1123 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_ALREADY_ACQUIRED,
# 1128 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NOT_MAPPED,
# 1134 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_ARRAY,
# 1140 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NOT_MAPPED_AS_POINTER,
# 1146 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_ECC_UNCORRECTABLE,
# 1152 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_UNSUPPORTED_LIMIT,
# 1159 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_CONTEXT_ALREADY_IN_USE,
# 1165 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_PEER_ACCESS_UNSUPPORTED,
# 1170 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_PTX,
# 1175 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_GRAPHICS_CONTEXT,
# 1181 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NVLINK_UNCORRECTABLE,
# 1186 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_SOURCE = 300,
# 1191 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_FILE_NOT_FOUND,
# 1196 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
# 1201 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
# 1206 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_OPERATING_SYSTEM,
# 1212 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_HANDLE = 400,
# 1218 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NOT_FOUND = 500,
# 1226 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NOT_READY = 600,
# 1235 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_ILLEGAL_ADDRESS = 700,
# 1246 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
# 1257 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_LAUNCH_TIMEOUT,
# 1263 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING,
# 1270 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED,
# 1277 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_PEER_ACCESS_NOT_ENABLED,
# 1283 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE = 708,
# 1290 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_CONTEXT_IS_DESTROYED,
# 1298 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_ASSERT,
# 1305 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_TOO_MANY_PEERS,
# 1311 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED,
# 1317 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED,
# 1326 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_HARDWARE_STACK_ERROR,
# 1334 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_ILLEGAL_INSTRUCTION,
# 1343 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_MISALIGNED_ADDRESS,
# 1354 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_ADDRESS_SPACE,
# 1362 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_INVALID_PC,
# 1372 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_LAUNCH_FAILED,
# 1378 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NOT_PERMITTED = 800,
# 1384 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_NOT_SUPPORTED,
# 1389 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CUDA_ERROR_UNKNOWN = 999};
# 1395 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUdevice_P2PAttribute_enum {
# 1396 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK = 1,
# 1397 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED,
# 1398 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED};
# 1650 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
enum CUresourceViewFormat_enum {
# 1652 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_NONE,
# 1653 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_1X8,
# 1654 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_2X8,
# 1655 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_4X8,
# 1656 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_1X8,
# 1657 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_2X8,
# 1658 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_4X8,
# 1659 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_1X16,
# 1660 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_2X16,
# 1661 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_4X16,
# 1662 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_1X16,
# 1663 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_2X16,
# 1664 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_4X16,
# 1665 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_1X32,
# 1666 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_2X32,
# 1667 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UINT_4X32,
# 1668 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_1X32,
# 1669 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_2X32,
# 1670 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SINT_4X32,
# 1671 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_FLOAT_1X16,
# 1672 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_FLOAT_2X16,
# 1673 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_FLOAT_4X16,
# 1674 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_FLOAT_1X32,
# 1675 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_FLOAT_2X32,
# 1676 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_FLOAT_4X32,
# 1677 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UNSIGNED_BC1,
# 1678 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UNSIGNED_BC2,
# 1679 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UNSIGNED_BC3,
# 1680 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UNSIGNED_BC4,
# 1681 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SIGNED_BC4,
# 1682 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UNSIGNED_BC5,
# 1683 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SIGNED_BC5,
# 1684 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UNSIGNED_BC6H,
# 1685 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_SIGNED_BC6H,
# 1686 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
CU_RES_VIEW_FORMAT_UNSIGNED_BC7};
# 60 "/usr/include/c++/4.8.2/exception" 3
struct _ZSt9exception;
# 54 "/usr/include/c++/4.8.2/new" 3
struct _ZSt9bad_alloc;
# 128 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt9__is_voidIvEUt_E {
# 128 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt9__is_voidIvE7__valueE = 1};
# 148 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIbEUt_E {
# 148 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIbE7__valueE = 1};
# 155 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIcEUt_E {
# 155 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIcE7__valueE = 1};
# 162 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIaEUt_E {
# 162 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIaE7__valueE = 1};
# 169 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIhEUt_E {
# 169 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIhE7__valueE = 1};
# 177 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIwEUt_E {
# 177 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIwE7__valueE = 1};
# 201 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIsEUt_E {
# 201 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIsE7__valueE = 1};
# 208 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerItEUt_E {
# 208 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerItE7__valueE = 1};
# 215 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIiEUt_E {
# 215 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIiE7__valueE = 1};
# 222 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIjEUt_E {
# 222 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIjE7__valueE = 1};
# 229 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIlEUt_E {
# 229 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIlE7__valueE = 1};
# 236 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerImEUt_E {
# 236 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerImE7__valueE = 1};
# 243 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIxEUt_E {
# 243 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIxE7__valueE = 1};
# 250 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIyEUt_E {
# 250 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIyE7__valueE = 1};
# 268 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt13__is_floatingIfEUt_E {
# 268 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt13__is_floatingIfE7__valueE = 1};
# 275 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt13__is_floatingIdEUt_E {
# 275 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt13__is_floatingIdE7__valueE = 1};
# 282 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt13__is_floatingIeEUt_E {
# 282 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt13__is_floatingIeE7__valueE = 1};
# 358 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt9__is_charIcEUt_E {
# 358 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt9__is_charIcE7__valueE = 1};
# 366 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt9__is_charIwEUt_E {
# 366 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt9__is_charIwE7__valueE = 1};
# 381 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt9__is_byteIcEUt_E {
# 381 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt9__is_byteIcE7__valueE = 1};
# 388 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt9__is_byteIaEUt_E {
# 388 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt9__is_byteIaE7__valueE = 1};
# 395 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt9__is_byteIhEUt_E {
# 395 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt9__is_byteIhE7__valueE = 1};
# 138 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIeEUt_E {
# 138 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIeE7__valueE};
# 138 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIdEUt_E {
# 138 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIdE7__valueE};
# 138 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
enum _ZNSt12__is_integerIfEUt_E {
# 138 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
_ZNSt12__is_integerIfE7__valueE};
# 475 "/usr/include/c++/4.8.2/bits/locale_classes.h" 3
struct _ZNSt6locale5_ImplE;
# 304 "/usr/include/c++/4.8.2/bits/locale_classes.h" 3
enum _ZNSt6localeUt_E {
# 304 "/usr/include/c++/4.8.2/bits/locale_classes.h" 3
_ZNSt6locale18_S_categories_sizeE = 12};
# 62 "/usr/include/c++/4.8.2/bits/locale_classes.h" 3
struct _ZSt6locale;
# 51 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
enum _ZSt13_Ios_Fmtflags {
# 53 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt12_S_boolalpha = 1,
# 54 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_dec,
# 55 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt8_S_fixed = 4,
# 56 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_hex = 8,
# 57 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt11_S_internal = 16,
# 58 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt7_S_left = 32,
# 59 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_oct = 64,
# 60 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt8_S_right = 128,
# 61 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt13_S_scientific = 256,
# 62 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt11_S_showbase = 512,
# 63 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt12_S_showpoint = 1024,
# 64 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt10_S_showpos = 2048,
# 65 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt9_S_skipws = 4096,
# 66 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt10_S_unitbuf = 8192,
# 67 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt12_S_uppercase = 16384,
# 68 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt14_S_adjustfield = 176,
# 69 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt12_S_basefield = 74,
# 70 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt13_S_floatfield = 260,
# 71 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt19_S_ios_fmtflags_end = 65536};
# 103 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
enum _ZSt13_Ios_Openmode {
# 105 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_app = 1,
# 106 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_ate,
# 107 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_bin = 4,
# 108 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt5_S_in = 8,
# 109 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_out = 16,
# 110 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt8_S_trunc = 32,
# 111 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt19_S_ios_openmode_end = 65536};
# 143 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
enum _ZSt12_Ios_Iostate {
# 145 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt10_S_goodbit,
# 146 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt9_S_badbit,
# 147 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt9_S_eofbit,
# 148 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt10_S_failbit = 4,
# 149 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt18_S_ios_iostate_end = 65536};
# 181 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
enum _ZSt12_Ios_Seekdir {
# 183 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_beg,
# 184 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_cur,
# 185 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt6_S_end,
# 186 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt18_S_ios_seekdir_end = 65536};
# 419 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
enum _ZNSt8ios_base5eventE {
# 421 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZNSt8ios_base11erase_eventE,
# 422 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZNSt8ios_base11imbue_eventE,
# 423 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZNSt8ios_base13copyfmt_eventE};
# 460 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base14_Callback_listE;
# 499 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base6_WordsE;
# 511 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
enum _ZNSt8ios_baseUt_E {
# 511 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZNSt8ios_base18_S_local_word_sizeE = 8};
# 533 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base4InitE;
# 199 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZSt8ios_base;
# 1524 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
enum _ZNSt10__num_baseUt_E {
# 1525 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base9_S_ominusE,
# 1526 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base8_S_oplusE,
# 1527 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base5_S_oxE,
# 1528 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base5_S_oXE,
# 1529 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base10_S_odigitsE,
# 1530 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base14_S_odigits_endE = 20,
# 1531 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base11_S_oudigitsE = 20,
# 1532 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base15_S_oudigits_endE = 36,
# 1533 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base5_S_oeE = 18,
# 1534 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base5_S_oEE = 34,
# 1535 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base7_S_oendE = 36};
# 1550 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
enum _ZNSt10__num_baseUt0_E {
# 1551 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base9_S_iminusE,
# 1552 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base8_S_iplusE,
# 1553 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base5_S_ixE,
# 1554 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base5_S_iXE,
# 1555 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base8_S_izeroE,
# 1556 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base5_S_ieE = 18,
# 1557 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base5_S_iEE = 24,
# 1558 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
_ZNSt10__num_base7_S_iendE = 26};
# 212 "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 1 3
# 38 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 3
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/host_defines.h" 1 3
# 39 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 2 3





typedef __attribute__((device_builtin_texture_type)) unsigned long long __texture_type__;
typedef __attribute__((device_builtin_surface_type)) unsigned long long __surface_type__;
# 196 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 3
extern __attribute__((device)) __attribute__((used)) void* malloc(size_t);
extern __attribute__((device)) __attribute__((used)) void free(void*);


static __attribute__((device)) void __nv_sized_free(void *p, size_t sz) { free(p); }
static __attribute__((device)) void __nv_sized_array_free(void *p, size_t sz) { free(p); }


extern __attribute__((device)) void __assertfail(
  const void *message,
  const void *file,
  unsigned int line,
  const void *function,
  size_t charsize);
# 254 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 3
static __attribute__((device)) void __assert_fail(
  const char *__assertion,
  const char *__file,
  unsigned int __line,
  const char *__function)
{
  __assertfail(
    (const void *)__assertion,
    (const void *)__file,
                  __line,
    (const void *)__function,
    sizeof(char));
}
# 284 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 3
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 1 3
# 56 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_types.h" 1 3
# 53 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_types.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/host_defines.h" 1 3
# 54 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_types.h" 2 3







enum __attribute__((device_builtin)) cudaRoundMode
{
    cudaRoundNearest,
    cudaRoundZero,
    cudaRoundPosInf,
    cudaRoundMinInf
};
# 57 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3


# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 1 3
# 156 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
enum __attribute__((device_builtin)) cudaError
{





    cudaSuccess = 0,





    cudaErrorMissingConfiguration = 1,





    cudaErrorMemoryAllocation = 2,





    cudaErrorInitializationError = 3,
# 191 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorLaunchFailure = 4,
# 200 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorPriorLaunchFailure = 5,
# 210 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorLaunchTimeout = 6,
# 219 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorLaunchOutOfResources = 7,





    cudaErrorInvalidDeviceFunction = 8,
# 234 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorInvalidConfiguration = 9,





    cudaErrorInvalidDevice = 10,





    cudaErrorInvalidValue = 11,





    cudaErrorInvalidPitchValue = 12,





    cudaErrorInvalidSymbol = 13,




    cudaErrorMapBufferObjectFailed = 14,




    cudaErrorUnmapBufferObjectFailed = 15,





    cudaErrorInvalidHostPointer = 16,





    cudaErrorInvalidDevicePointer = 17,





    cudaErrorInvalidTexture = 18,





    cudaErrorInvalidTextureBinding = 19,






    cudaErrorInvalidChannelDescriptor = 20,





    cudaErrorInvalidMemcpyDirection = 21,
# 315 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorAddressOfConstant = 22,
# 324 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorTextureFetchFailed = 23,
# 333 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorTextureNotBound = 24,
# 342 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorSynchronizationError = 25,





    cudaErrorInvalidFilterSetting = 26,





    cudaErrorInvalidNormSetting = 27,







    cudaErrorMixedDeviceExecution = 28,






    cudaErrorCudartUnloading = 29,




    cudaErrorUnknown = 30,







    cudaErrorNotYetImplemented = 31,
# 391 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorMemoryValueTooLarge = 32,






    cudaErrorInvalidResourceHandle = 33,







    cudaErrorNotReady = 34,






    cudaErrorInsufficientDriver = 35,
# 426 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorSetOnActiveProcess = 36,





    cudaErrorInvalidSurface = 37,





    cudaErrorNoDevice = 38,





    cudaErrorECCUncorrectable = 39,




    cudaErrorSharedObjectSymbolNotFound = 40,




    cudaErrorSharedObjectInitFailed = 41,





    cudaErrorUnsupportedLimit = 42,





    cudaErrorDuplicateVariableName = 43,





    cudaErrorDuplicateTextureName = 44,





    cudaErrorDuplicateSurfaceName = 45,
# 488 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorDevicesUnavailable = 46,




    cudaErrorInvalidKernelImage = 47,







    cudaErrorNoKernelImageForDevice = 48,
# 514 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorIncompatibleDriverContext = 49,






    cudaErrorPeerAccessAlreadyEnabled = 50,






    cudaErrorPeerAccessNotEnabled = 51,





    cudaErrorDeviceAlreadyInUse = 54,






    cudaErrorProfilerDisabled = 55,







    cudaErrorProfilerNotInitialized = 56,






    cudaErrorProfilerAlreadyStarted = 57,






     cudaErrorProfilerAlreadyStopped = 58,







    cudaErrorAssert = 59,






    cudaErrorTooManyPeers = 60,





    cudaErrorHostMemoryAlreadyRegistered = 61,





    cudaErrorHostMemoryNotRegistered = 62,




    cudaErrorOperatingSystem = 63,





    cudaErrorPeerAccessUnsupported = 64,






    cudaErrorLaunchMaxDepthExceeded = 65,







    cudaErrorLaunchFileScopedTex = 66,







    cudaErrorLaunchFileScopedSurf = 67,
# 639 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorSyncDepthExceeded = 68,
# 651 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorLaunchPendingCountExceeded = 69,




    cudaErrorNotPermitted = 70,





    cudaErrorNotSupported = 71,
# 671 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorHardwareStackError = 72,







    cudaErrorIllegalInstruction = 73,
# 688 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorMisalignedAddress = 74,
# 699 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    cudaErrorInvalidAddressSpace = 75,







    cudaErrorInvalidPc = 76,







    cudaErrorIllegalAddress = 77,





    cudaErrorInvalidPtx = 78,




    cudaErrorInvalidGraphicsContext = 79,





    cudaErrorNvlinkUncorrectable = 80,




    cudaErrorStartupFailure = 0x7f,







    cudaErrorApiFailureBase = 10000
};




enum __attribute__((device_builtin)) cudaChannelFormatKind
{
    cudaChannelFormatKindSigned = 0,
    cudaChannelFormatKindUnsigned = 1,
    cudaChannelFormatKindFloat = 2,
    cudaChannelFormatKindNone = 3
};




struct __attribute__((device_builtin)) cudaChannelFormatDesc
{
    int x;
    int y;
    int z;
    int w;
    enum cudaChannelFormatKind f;
};




typedef struct cudaArray *cudaArray_t;




typedef const struct cudaArray *cudaArray_const_t;

struct cudaArray;




typedef struct cudaMipmappedArray *cudaMipmappedArray_t;




typedef const struct cudaMipmappedArray *cudaMipmappedArray_const_t;

struct cudaMipmappedArray;




enum __attribute__((device_builtin)) cudaMemoryType
{
    cudaMemoryTypeHost = 1,
    cudaMemoryTypeDevice = 2
};




enum __attribute__((device_builtin)) cudaMemcpyKind
{
    cudaMemcpyHostToHost = 0,
    cudaMemcpyHostToDevice = 1,
    cudaMemcpyDeviceToHost = 2,
    cudaMemcpyDeviceToDevice = 3,
    cudaMemcpyDefault = 4
};






struct __attribute__((device_builtin)) cudaPitchedPtr
{
    void *ptr;
    size_t pitch;
    size_t xsize;
    size_t ysize;
};






struct __attribute__((device_builtin)) cudaExtent
{
    size_t width;
    size_t height;
    size_t depth;
};






struct __attribute__((device_builtin)) cudaPos
{
    size_t x;
    size_t y;
    size_t z;
};




struct __attribute__((device_builtin)) cudaMemcpy3DParms
{
    cudaArray_t srcArray;
    struct cudaPos srcPos;
    struct cudaPitchedPtr srcPtr;

    cudaArray_t dstArray;
    struct cudaPos dstPos;
    struct cudaPitchedPtr dstPtr;

    struct cudaExtent extent;
    enum cudaMemcpyKind kind;
};




struct __attribute__((device_builtin)) cudaMemcpy3DPeerParms
{
    cudaArray_t srcArray;
    struct cudaPos srcPos;
    struct cudaPitchedPtr srcPtr;
    int srcDevice;

    cudaArray_t dstArray;
    struct cudaPos dstPos;
    struct cudaPitchedPtr dstPtr;
    int dstDevice;

    struct cudaExtent extent;
};




struct cudaGraphicsResource;




enum __attribute__((device_builtin)) cudaGraphicsRegisterFlags
{
    cudaGraphicsRegisterFlagsNone = 0,
    cudaGraphicsRegisterFlagsReadOnly = 1,
    cudaGraphicsRegisterFlagsWriteDiscard = 2,
    cudaGraphicsRegisterFlagsSurfaceLoadStore = 4,
    cudaGraphicsRegisterFlagsTextureGather = 8
};




enum __attribute__((device_builtin)) cudaGraphicsMapFlags
{
    cudaGraphicsMapFlagsNone = 0,
    cudaGraphicsMapFlagsReadOnly = 1,
    cudaGraphicsMapFlagsWriteDiscard = 2
};




enum __attribute__((device_builtin)) cudaGraphicsCubeFace
{
    cudaGraphicsCubeFacePositiveX = 0x00,
    cudaGraphicsCubeFaceNegativeX = 0x01,
    cudaGraphicsCubeFacePositiveY = 0x02,
    cudaGraphicsCubeFaceNegativeY = 0x03,
    cudaGraphicsCubeFacePositiveZ = 0x04,
    cudaGraphicsCubeFaceNegativeZ = 0x05
};




enum __attribute__((device_builtin)) cudaResourceType
{
    cudaResourceTypeArray = 0x00,
    cudaResourceTypeMipmappedArray = 0x01,
    cudaResourceTypeLinear = 0x02,
    cudaResourceTypePitch2D = 0x03
};




enum __attribute__((device_builtin)) cudaResourceViewFormat
{
    cudaResViewFormatNone = 0x00,
    cudaResViewFormatUnsignedChar1 = 0x01,
    cudaResViewFormatUnsignedChar2 = 0x02,
    cudaResViewFormatUnsignedChar4 = 0x03,
    cudaResViewFormatSignedChar1 = 0x04,
    cudaResViewFormatSignedChar2 = 0x05,
    cudaResViewFormatSignedChar4 = 0x06,
    cudaResViewFormatUnsignedShort1 = 0x07,
    cudaResViewFormatUnsignedShort2 = 0x08,
    cudaResViewFormatUnsignedShort4 = 0x09,
    cudaResViewFormatSignedShort1 = 0x0a,
    cudaResViewFormatSignedShort2 = 0x0b,
    cudaResViewFormatSignedShort4 = 0x0c,
    cudaResViewFormatUnsignedInt1 = 0x0d,
    cudaResViewFormatUnsignedInt2 = 0x0e,
    cudaResViewFormatUnsignedInt4 = 0x0f,
    cudaResViewFormatSignedInt1 = 0x10,
    cudaResViewFormatSignedInt2 = 0x11,
    cudaResViewFormatSignedInt4 = 0x12,
    cudaResViewFormatHalf1 = 0x13,
    cudaResViewFormatHalf2 = 0x14,
    cudaResViewFormatHalf4 = 0x15,
    cudaResViewFormatFloat1 = 0x16,
    cudaResViewFormatFloat2 = 0x17,
    cudaResViewFormatFloat4 = 0x18,
    cudaResViewFormatUnsignedBlockCompressed1 = 0x19,
    cudaResViewFormatUnsignedBlockCompressed2 = 0x1a,
    cudaResViewFormatUnsignedBlockCompressed3 = 0x1b,
    cudaResViewFormatUnsignedBlockCompressed4 = 0x1c,
    cudaResViewFormatSignedBlockCompressed4 = 0x1d,
    cudaResViewFormatUnsignedBlockCompressed5 = 0x1e,
    cudaResViewFormatSignedBlockCompressed5 = 0x1f,
    cudaResViewFormatUnsignedBlockCompressed6H = 0x20,
    cudaResViewFormatSignedBlockCompressed6H = 0x21,
    cudaResViewFormatUnsignedBlockCompressed7 = 0x22
};




struct __attribute__((device_builtin)) cudaResourceDesc {
 enum cudaResourceType resType;

 union {
  struct {
   cudaArray_t array;
  } array;
        struct {
            cudaMipmappedArray_t mipmap;
        } mipmap;
  struct {
   void *devPtr;
   struct cudaChannelFormatDesc desc;
   size_t sizeInBytes;
  } linear;
  struct {
   void *devPtr;
   struct cudaChannelFormatDesc desc;
   size_t width;
   size_t height;
   size_t pitchInBytes;
  } pitch2D;
 } res;
};




struct __attribute__((device_builtin)) cudaResourceViewDesc
{
    enum cudaResourceViewFormat format;
    size_t width;
    size_t height;
    size_t depth;
    unsigned int firstMipmapLevel;
    unsigned int lastMipmapLevel;
    unsigned int firstLayer;
    unsigned int lastLayer;
};




struct __attribute__((device_builtin)) cudaPointerAttributes
{




    enum cudaMemoryType memoryType;
# 1044 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    int device;





    void *devicePointer;





    void *hostPointer;




    int isManaged;
};




struct __attribute__((device_builtin)) cudaFuncAttributes
{





   size_t sharedSizeBytes;





   size_t constSizeBytes;




   size_t localSizeBytes;






   int maxThreadsPerBlock;




   int numRegs;






   int ptxVersion;






   int binaryVersion;





   int cacheModeCA;
};




enum __attribute__((device_builtin)) cudaFuncCache
{
    cudaFuncCachePreferNone = 0,
    cudaFuncCachePreferShared = 1,
    cudaFuncCachePreferL1 = 2,
    cudaFuncCachePreferEqual = 3
};





enum __attribute__((device_builtin)) cudaSharedMemConfig
{
    cudaSharedMemBankSizeDefault = 0,
    cudaSharedMemBankSizeFourByte = 1,
    cudaSharedMemBankSizeEightByte = 2
};




enum __attribute__((device_builtin)) cudaComputeMode
{
    cudaComputeModeDefault = 0,
    cudaComputeModeExclusive = 1,
    cudaComputeModeProhibited = 2,
    cudaComputeModeExclusiveProcess = 3
};




enum __attribute__((device_builtin)) cudaLimit
{
    cudaLimitStackSize = 0x00,
    cudaLimitPrintfFifoSize = 0x01,
    cudaLimitMallocHeapSize = 0x02,
    cudaLimitDevRuntimeSyncDepth = 0x03,
    cudaLimitDevRuntimePendingLaunchCount = 0x04
};




enum __attribute__((device_builtin)) cudaMemoryAdvise
{
    cudaMemAdviseSetReadMostly = 1,
    cudaMemAdviseUnsetReadMostly = 2,
    cudaMemAdviseSetPreferredLocation = 3,
    cudaMemAdviseUnsetPreferredLocation = 4,
    cudaMemAdviseSetAccessedBy = 5,
    cudaMemAdviseUnsetAccessedBy = 6
};




enum __attribute__((device_builtin)) cudaMemRangeAttribute
{
    cudaMemRangeAttributeReadMostly = 1,
    cudaMemRangeAttributePreferredLocation = 2,
    cudaMemRangeAttributeAccessedBy = 3,
    cudaMemRangeAttributeLastPrefetchLocation = 4
};




enum __attribute__((device_builtin)) cudaOutputMode
{
    cudaKeyValuePair = 0x00,
    cudaCSV = 0x01
};




enum __attribute__((device_builtin)) cudaDeviceAttr
{
    cudaDevAttrMaxThreadsPerBlock = 1,
    cudaDevAttrMaxBlockDimX = 2,
    cudaDevAttrMaxBlockDimY = 3,
    cudaDevAttrMaxBlockDimZ = 4,
    cudaDevAttrMaxGridDimX = 5,
    cudaDevAttrMaxGridDimY = 6,
    cudaDevAttrMaxGridDimZ = 7,
    cudaDevAttrMaxSharedMemoryPerBlock = 8,
    cudaDevAttrTotalConstantMemory = 9,
    cudaDevAttrWarpSize = 10,
    cudaDevAttrMaxPitch = 11,
    cudaDevAttrMaxRegistersPerBlock = 12,
    cudaDevAttrClockRate = 13,
    cudaDevAttrTextureAlignment = 14,
    cudaDevAttrGpuOverlap = 15,
    cudaDevAttrMultiProcessorCount = 16,
    cudaDevAttrKernelExecTimeout = 17,
    cudaDevAttrIntegrated = 18,
    cudaDevAttrCanMapHostMemory = 19,
    cudaDevAttrComputeMode = 20,
    cudaDevAttrMaxTexture1DWidth = 21,
    cudaDevAttrMaxTexture2DWidth = 22,
    cudaDevAttrMaxTexture2DHeight = 23,
    cudaDevAttrMaxTexture3DWidth = 24,
    cudaDevAttrMaxTexture3DHeight = 25,
    cudaDevAttrMaxTexture3DDepth = 26,
    cudaDevAttrMaxTexture2DLayeredWidth = 27,
    cudaDevAttrMaxTexture2DLayeredHeight = 28,
    cudaDevAttrMaxTexture2DLayeredLayers = 29,
    cudaDevAttrSurfaceAlignment = 30,
    cudaDevAttrConcurrentKernels = 31,
    cudaDevAttrEccEnabled = 32,
    cudaDevAttrPciBusId = 33,
    cudaDevAttrPciDeviceId = 34,
    cudaDevAttrTccDriver = 35,
    cudaDevAttrMemoryClockRate = 36,
    cudaDevAttrGlobalMemoryBusWidth = 37,
    cudaDevAttrL2CacheSize = 38,
    cudaDevAttrMaxThreadsPerMultiProcessor = 39,
    cudaDevAttrAsyncEngineCount = 40,
    cudaDevAttrUnifiedAddressing = 41,
    cudaDevAttrMaxTexture1DLayeredWidth = 42,
    cudaDevAttrMaxTexture1DLayeredLayers = 43,
    cudaDevAttrMaxTexture2DGatherWidth = 45,
    cudaDevAttrMaxTexture2DGatherHeight = 46,
    cudaDevAttrMaxTexture3DWidthAlt = 47,
    cudaDevAttrMaxTexture3DHeightAlt = 48,
    cudaDevAttrMaxTexture3DDepthAlt = 49,
    cudaDevAttrPciDomainId = 50,
    cudaDevAttrTexturePitchAlignment = 51,
    cudaDevAttrMaxTextureCubemapWidth = 52,
    cudaDevAttrMaxTextureCubemapLayeredWidth = 53,
    cudaDevAttrMaxTextureCubemapLayeredLayers = 54,
    cudaDevAttrMaxSurface1DWidth = 55,
    cudaDevAttrMaxSurface2DWidth = 56,
    cudaDevAttrMaxSurface2DHeight = 57,
    cudaDevAttrMaxSurface3DWidth = 58,
    cudaDevAttrMaxSurface3DHeight = 59,
    cudaDevAttrMaxSurface3DDepth = 60,
    cudaDevAttrMaxSurface1DLayeredWidth = 61,
    cudaDevAttrMaxSurface1DLayeredLayers = 62,
    cudaDevAttrMaxSurface2DLayeredWidth = 63,
    cudaDevAttrMaxSurface2DLayeredHeight = 64,
    cudaDevAttrMaxSurface2DLayeredLayers = 65,
    cudaDevAttrMaxSurfaceCubemapWidth = 66,
    cudaDevAttrMaxSurfaceCubemapLayeredWidth = 67,
    cudaDevAttrMaxSurfaceCubemapLayeredLayers = 68,
    cudaDevAttrMaxTexture1DLinearWidth = 69,
    cudaDevAttrMaxTexture2DLinearWidth = 70,
    cudaDevAttrMaxTexture2DLinearHeight = 71,
    cudaDevAttrMaxTexture2DLinearPitch = 72,
    cudaDevAttrMaxTexture2DMipmappedWidth = 73,
    cudaDevAttrMaxTexture2DMipmappedHeight = 74,
    cudaDevAttrComputeCapabilityMajor = 75,
    cudaDevAttrComputeCapabilityMinor = 76,
    cudaDevAttrMaxTexture1DMipmappedWidth = 77,
    cudaDevAttrStreamPrioritiesSupported = 78,
    cudaDevAttrGlobalL1CacheSupported = 79,
    cudaDevAttrLocalL1CacheSupported = 80,
    cudaDevAttrMaxSharedMemoryPerMultiprocessor = 81,
    cudaDevAttrMaxRegistersPerMultiprocessor = 82,
    cudaDevAttrManagedMemory = 83,
    cudaDevAttrIsMultiGpuBoard = 84,
    cudaDevAttrMultiGpuBoardGroupID = 85,
    cudaDevAttrHostNativeAtomicSupported = 86,
    cudaDevAttrSingleToDoublePrecisionPerfRatio = 87,
    cudaDevAttrPageableMemoryAccess = 88,
    cudaDevAttrConcurrentManagedAccess = 89,
    cudaDevAttrComputePreemptionSupported = 90,
    cudaDevAttrCanUseHostPointerForRegisteredMem = 91
};





enum __attribute__((device_builtin)) cudaDeviceP2PAttr {
    cudaDevP2PAttrPerformanceRank = 1,
    cudaDevP2PAttrAccessSupported = 2,
    cudaDevP2PAttrNativeAtomicSupported = 3
};



struct __attribute__((device_builtin)) cudaDeviceProp
{
    char name[256];
    size_t totalGlobalMem;
    size_t sharedMemPerBlock;
    int regsPerBlock;
    int warpSize;
    size_t memPitch;
    int maxThreadsPerBlock;
    int maxThreadsDim[3];
    int maxGridSize[3];
    int clockRate;
    size_t totalConstMem;
    int major;
    int minor;
    size_t textureAlignment;
    size_t texturePitchAlignment;
    int deviceOverlap;
    int multiProcessorCount;
    int kernelExecTimeoutEnabled;
    int integrated;
    int canMapHostMemory;
    int computeMode;
    int maxTexture1D;
    int maxTexture1DMipmap;
    int maxTexture1DLinear;
    int maxTexture2D[2];
    int maxTexture2DMipmap[2];
    int maxTexture2DLinear[3];
    int maxTexture2DGather[2];
    int maxTexture3D[3];
    int maxTexture3DAlt[3];
    int maxTextureCubemap;
    int maxTexture1DLayered[2];
    int maxTexture2DLayered[3];
    int maxTextureCubemapLayered[2];
    int maxSurface1D;
    int maxSurface2D[2];
    int maxSurface3D[3];
    int maxSurface1DLayered[2];
    int maxSurface2DLayered[3];
    int maxSurfaceCubemap;
    int maxSurfaceCubemapLayered[2];
    size_t surfaceAlignment;
    int concurrentKernels;
    int ECCEnabled;
    int pciBusID;
    int pciDeviceID;
    int pciDomainID;
    int tccDriver;
    int asyncEngineCount;
    int unifiedAddressing;
    int memoryClockRate;
    int memoryBusWidth;
    int l2CacheSize;
    int maxThreadsPerMultiProcessor;
    int streamPrioritiesSupported;
    int globalL1CacheSupported;
    int localL1CacheSupported;
    size_t sharedMemPerMultiprocessor;
    int regsPerMultiprocessor;
    int managedMemory;
    int isMultiGpuBoard;
    int multiGpuBoardGroupID;
    int hostNativeAtomicSupported;
    int singleToDoublePrecisionPerfRatio;
    int pageableMemoryAccess;
    int concurrentManagedAccess;
};
# 1455 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
typedef __attribute__((device_builtin)) struct __attribute__((device_builtin)) cudaIpcEventHandle_st
{
    char reserved[64];
}cudaIpcEventHandle_t;




typedef __attribute__((device_builtin)) struct __attribute__((device_builtin)) cudaIpcMemHandle_st
{
    char reserved[64];
}cudaIpcMemHandle_t;
# 1477 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
typedef __attribute__((device_builtin)) enum cudaError cudaError_t;




typedef __attribute__((device_builtin)) struct CUstream_st *cudaStream_t;




typedef __attribute__((device_builtin)) struct CUevent_st *cudaEvent_t;




typedef __attribute__((device_builtin)) struct cudaGraphicsResource *cudaGraphicsResource_t;




typedef __attribute__((device_builtin)) struct CUuuid_st cudaUUID_t;




typedef __attribute__((device_builtin)) enum cudaOutputMode cudaOutputMode_t;
# 60 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3


# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 1 3
# 59 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 1 3
# 60 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 2 3
# 84 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 3
enum __attribute__((device_builtin)) cudaSurfaceBoundaryMode
{
    cudaBoundaryModeZero = 0,
    cudaBoundaryModeClamp = 1,
    cudaBoundaryModeTrap = 2
};




enum __attribute__((device_builtin)) cudaSurfaceFormatMode
{
    cudaFormatModeForced = 0,
    cudaFormatModeAuto = 1
};




struct __attribute__((device_builtin)) surfaceReference
{



    struct cudaChannelFormatDesc channelDesc;
};




typedef __attribute__((device_builtin)) unsigned long long cudaSurfaceObject_t;
# 63 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/texture_types.h" 1 3
# 84 "/usr/local/cuda-8.0/targets/x86_64-linux/include/texture_types.h" 3
enum __attribute__((device_builtin)) cudaTextureAddressMode
{
    cudaAddressModeWrap = 0,
    cudaAddressModeClamp = 1,
    cudaAddressModeMirror = 2,
    cudaAddressModeBorder = 3
};




enum __attribute__((device_builtin)) cudaTextureFilterMode
{
    cudaFilterModePoint = 0,
    cudaFilterModeLinear = 1
};




enum __attribute__((device_builtin)) cudaTextureReadMode
{
    cudaReadModeElementType = 0,
    cudaReadModeNormalizedFloat = 1
};




struct __attribute__((device_builtin)) textureReference
{



    int normalized;



    enum cudaTextureFilterMode filterMode;



    enum cudaTextureAddressMode addressMode[3];



    struct cudaChannelFormatDesc channelDesc;



    int sRGB;



    unsigned int maxAnisotropy;



    enum cudaTextureFilterMode mipmapFilterMode;



    float mipmapLevelBias;



    float minMipmapLevelClamp;



    float maxMipmapLevelClamp;
    int __cudaReserved[15];
};




struct __attribute__((device_builtin)) cudaTextureDesc
{



    enum cudaTextureAddressMode addressMode[3];



    enum cudaTextureFilterMode filterMode;



    enum cudaTextureReadMode readMode;



    int sRGB;



    float borderColor[4];



    int normalizedCoords;



    unsigned int maxAnisotropy;



    enum cudaTextureFilterMode mipmapFilterMode;



    float mipmapLevelBias;



    float minMipmapLevelClamp;



    float maxMipmapLevelClamp;
};




typedef __attribute__((device_builtin)) unsigned long long cudaTextureObject_t;
# 64 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 1 3
# 61 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/builtin_types.h" 1 3
# 56 "/usr/local/cuda-8.0/targets/x86_64-linux/include/builtin_types.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_types.h" 1 3
# 57 "/usr/local/cuda-8.0/targets/x86_64-linux/include/builtin_types.h" 2 3





# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 1 3
# 63 "/usr/local/cuda-8.0/targets/x86_64-linux/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/texture_types.h" 1 3
# 64 "/usr/local/cuda-8.0/targets/x86_64-linux/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 1 3
# 64 "/usr/local/cuda-8.0/targets/x86_64-linux/include/builtin_types.h" 2 3
# 62 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 2 3
# 98 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 3
struct __attribute__((device_builtin)) char1
{
    signed char x;
};

struct __attribute__((device_builtin)) uchar1
{
    unsigned char x;
};


struct __attribute__((device_builtin)) __attribute__((aligned(2))) char2
{
    signed char x, y;
};

struct __attribute__((device_builtin)) __attribute__((aligned(2))) uchar2
{
    unsigned char x, y;
};

struct __attribute__((device_builtin)) char3
{
    signed char x, y, z;
};

struct __attribute__((device_builtin)) uchar3
{
    unsigned char x, y, z;
};

struct __attribute__((device_builtin)) __attribute__((aligned(4))) char4
{
    signed char x, y, z, w;
};

struct __attribute__((device_builtin)) __attribute__((aligned(4))) uchar4
{
    unsigned char x, y, z, w;
};

struct __attribute__((device_builtin)) short1
{
    short x;
};

struct __attribute__((device_builtin)) ushort1
{
    unsigned short x;
};

struct __attribute__((device_builtin)) __attribute__((aligned(4))) short2
{
    short x, y;
};

struct __attribute__((device_builtin)) __attribute__((aligned(4))) ushort2
{
    unsigned short x, y;
};

struct __attribute__((device_builtin)) short3
{
    short x, y, z;
};

struct __attribute__((device_builtin)) ushort3
{
    unsigned short x, y, z;
};

struct __attribute__((device_builtin)) __attribute__((aligned(8))) short4 { short x; short y; short z; short w; };
struct __attribute__((device_builtin)) __attribute__((aligned(8))) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; };

struct __attribute__((device_builtin)) int1
{
    int x;
};

struct __attribute__((device_builtin)) uint1
{
    unsigned int x;
};

struct __attribute__((device_builtin)) __attribute__((aligned(8))) int2 { int x; int y; };
struct __attribute__((device_builtin)) __attribute__((aligned(8))) uint2 { unsigned int x; unsigned int y; };

struct __attribute__((device_builtin)) int3
{
    int x, y, z;
};

struct __attribute__((device_builtin)) uint3
{
    unsigned int x, y, z;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) int4
{
    int x, y, z, w;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) uint4
{
    unsigned int x, y, z, w;
};

struct __attribute__((device_builtin)) long1
{
    long int x;
};

struct __attribute__((device_builtin)) ulong1
{
    unsigned long x;
};






struct __attribute__((device_builtin)) __attribute__((aligned(2*sizeof(long int)))) long2
{
    long int x, y;
};

struct __attribute__((device_builtin)) __attribute__((aligned(2*sizeof(unsigned long int)))) ulong2
{
    unsigned long int x, y;
};



struct __attribute__((device_builtin)) long3
{
    long int x, y, z;
};

struct __attribute__((device_builtin)) ulong3
{
    unsigned long int x, y, z;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) long4
{
    long int x, y, z, w;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) ulong4
{
    unsigned long int x, y, z, w;
};

struct __attribute__((device_builtin)) float1
{
    float x;
};
# 274 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 3
struct __attribute__((device_builtin)) __attribute__((aligned(8))) float2 { float x; float y; };




struct __attribute__((device_builtin)) float3
{
    float x, y, z;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) float4
{
    float x, y, z, w;
};

struct __attribute__((device_builtin)) longlong1
{
    long long int x;
};

struct __attribute__((device_builtin)) ulonglong1
{
    unsigned long long int x;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) longlong2
{
    long long int x, y;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) ulonglong2
{
    unsigned long long int x, y;
};

struct __attribute__((device_builtin)) longlong3
{
    long long int x, y, z;
};

struct __attribute__((device_builtin)) ulonglong3
{
    unsigned long long int x, y, z;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) longlong4
{
    long long int x, y, z ,w;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) ulonglong4
{
    unsigned long long int x, y, z, w;
};

struct __attribute__((device_builtin)) double1
{
    double x;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) double2
{
    double x, y;
};

struct __attribute__((device_builtin)) double3
{
    double x, y, z;
};

struct __attribute__((device_builtin)) __attribute__((aligned(16))) double4
{
    double x, y, z, w;
};
# 362 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 3
typedef __attribute__((device_builtin)) struct char1 char1;
typedef __attribute__((device_builtin)) struct uchar1 uchar1;
typedef __attribute__((device_builtin)) struct char2 char2;
typedef __attribute__((device_builtin)) struct uchar2 uchar2;
typedef __attribute__((device_builtin)) struct char3 char3;
typedef __attribute__((device_builtin)) struct uchar3 uchar3;
typedef __attribute__((device_builtin)) struct char4 char4;
typedef __attribute__((device_builtin)) struct uchar4 uchar4;
typedef __attribute__((device_builtin)) struct short1 short1;
typedef __attribute__((device_builtin)) struct ushort1 ushort1;
typedef __attribute__((device_builtin)) struct short2 short2;
typedef __attribute__((device_builtin)) struct ushort2 ushort2;
typedef __attribute__((device_builtin)) struct short3 short3;
typedef __attribute__((device_builtin)) struct ushort3 ushort3;
typedef __attribute__((device_builtin)) struct short4 short4;
typedef __attribute__((device_builtin)) struct ushort4 ushort4;
typedef __attribute__((device_builtin)) struct int1 int1;
typedef __attribute__((device_builtin)) struct uint1 uint1;
typedef __attribute__((device_builtin)) struct int2 int2;
typedef __attribute__((device_builtin)) struct uint2 uint2;
typedef __attribute__((device_builtin)) struct int3 int3;
typedef __attribute__((device_builtin)) struct uint3 uint3;
typedef __attribute__((device_builtin)) struct int4 int4;
typedef __attribute__((device_builtin)) struct uint4 uint4;
typedef __attribute__((device_builtin)) struct long1 long1;
typedef __attribute__((device_builtin)) struct ulong1 ulong1;
typedef __attribute__((device_builtin)) struct long2 long2;
typedef __attribute__((device_builtin)) struct ulong2 ulong2;
typedef __attribute__((device_builtin)) struct long3 long3;
typedef __attribute__((device_builtin)) struct ulong3 ulong3;
typedef __attribute__((device_builtin)) struct long4 long4;
typedef __attribute__((device_builtin)) struct ulong4 ulong4;
typedef __attribute__((device_builtin)) struct float1 float1;
typedef __attribute__((device_builtin)) struct float2 float2;
typedef __attribute__((device_builtin)) struct float3 float3;
typedef __attribute__((device_builtin)) struct float4 float4;
typedef __attribute__((device_builtin)) struct longlong1 longlong1;
typedef __attribute__((device_builtin)) struct ulonglong1 ulonglong1;
typedef __attribute__((device_builtin)) struct longlong2 longlong2;
typedef __attribute__((device_builtin)) struct ulonglong2 ulonglong2;
typedef __attribute__((device_builtin)) struct longlong3 longlong3;
typedef __attribute__((device_builtin)) struct ulonglong3 ulonglong3;
typedef __attribute__((device_builtin)) struct longlong4 longlong4;
typedef __attribute__((device_builtin)) struct ulonglong4 ulonglong4;
typedef __attribute__((device_builtin)) struct double1 double1;
typedef __attribute__((device_builtin)) struct double2 double2;
typedef __attribute__((device_builtin)) struct double3 double3;
typedef __attribute__((device_builtin)) struct double4 double4;







struct __attribute__((device_builtin)) dim3
{
    unsigned int x, y, z;





};

typedef __attribute__((device_builtin)) struct dim3 dim3;
# 64 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3
# 285 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 2 3
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_launch_parameters.h" 1 3
# 71 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_launch_parameters.h" 3
uint3 __attribute__((device_builtin)) extern const threadIdx;
uint3 __attribute__((device_builtin)) extern const blockIdx;
dim3 __attribute__((device_builtin)) extern const blockDim;
dim3 __attribute__((device_builtin)) extern const gridDim;
int __attribute__((device_builtin)) extern const warpSize;
# 286 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/crt/storage_class.h" 1 3
# 286 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 2 3
# 214 "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h" 2 3
# 1857 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/c++config.h" 3
typedef unsigned long _ZSt6size_t;
# 1858 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/c++config.h" 3
typedef long _ZSt9ptrdiff_t;
# 60 "/usr/include/c++/4.8.2/exception" 3
struct _ZSt9exception { const long *__vptr;};
# 54 "/usr/include/c++/4.8.2/new" 3
struct _ZSt9bad_alloc { struct _ZSt9exception __b_St9exception;};
# 98 "/usr/include/c++/4.8.2/bits/postypes.h" 3
typedef _ZSt9ptrdiff_t _ZSt10streamsize;
# 62 "/usr/include/c++/4.8.2/bits/locale_classes.h" 3
struct _ZSt6locale {
# 280 "/usr/include/c++/4.8.2/bits/locale_classes.h" 3
struct _ZNSt6locale5_ImplE *_M_impl;};
# 255 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
typedef enum _ZSt13_Ios_Fmtflags _ZNSt8ios_base8fmtflagsE;
# 330 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
typedef enum _ZSt12_Ios_Iostate _ZNSt8ios_base7iostateE;
# 499 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base6_WordsE {
# 501 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
void *_M_pword;
# 502 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
long _M_iword;};
# 533 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base4InitE {char __nv_no_debug_dummy_end_padding_0;};
# 199 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZSt8ios_base { const long *__vptr;
# 452 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt10streamsize _M_precision;
# 453 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZSt10streamsize _M_width;
# 454 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZNSt8ios_base8fmtflagsE _M_flags;
# 455 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZNSt8ios_base7iostateE _M_exception;
# 456 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
_ZNSt8ios_base7iostateE _M_streambuf_state;
# 490 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base14_Callback_listE *_M_callbacks;
# 507 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base6_WordsE _M_word_zero;
# 512 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base6_WordsE _M_local_word[8];
# 515 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
int _M_word_size;
# 516 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZNSt8ios_base6_WordsE *_M_word;
# 522 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
struct _ZSt6locale _M_ios_locale;};
# 223 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h"
extern __attribute__((device)) __attribute__((__externally_visible__)) __attribute__((visibility("default"))) void *malloc(_ZSt6size_t);
# 225 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h"
extern __attribute__((device)) __attribute__((__externally_visible__)) __attribute__((__nothrow__)) __attribute__((visibility("default"))) void free(void *);
# 129 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h"
 __attribute__((device_builtin)) extern __attribute__((device)) int printf(const char *__restrict__, ...);
# 13 "t266.cu"
__attribute__((global)) extern void _Z3dotPi(int *);
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h" 1
# 249 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h"
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 1 3
# 10327 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.hpp" 1 3
# 10328 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 2 3



# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.h" 1 3
# 270 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.hpp" 1 3
# 271 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.h" 2 3
# 10332 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 2 3
# 250 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h" 2
# 15 "t266.cu" 2
# 13 "t266.cu"
__attribute__((global)) void _Z3dotPi(
# 13 "t266.cu"
int *a){
# 13 "t266.cu"
{
# 18 "t266.cu"
 int __cuda_local_var_33150_9_non_const_tid;
# 18 "t266.cu"
__cuda_local_var_33150_9_non_const_tid = ((int)(threadIdx.x));
# 19 "t266.cu"
if (__cuda_local_var_33150_9_non_const_tid > 1)
# 19 "t266.cu"
{
# 20 "t266.cu"
 int __cuda_local_var_33152_13_non_const_t0;
# 21 "t266.cu"
 int __cuda_local_var_33153_13_non_const_t1;
# 20 "t266.cu"
__cuda_local_var_33152_13_non_const_t0 = (a[(__cuda_local_var_33150_9_non_const_tid - 2)]);
# 21 "t266.cu"
__cuda_local_var_33153_13_non_const_t1 = (a[__cuda_local_var_33150_9_non_const_tid]);
# 23 "t266.cu"
(a[__cuda_local_var_33150_9_non_const_tid]) = (__cuda_local_var_33152_13_non_const_t0 + __cuda_local_var_33153_13_non_const_t1);
# 25 "t266.cu"
}
# 25 "t266.cu"
else
# 25 "t266.cu"
{
# 26 "t266.cu"
 int __cuda_local_var_33158_13_non_const_t0;
# 27 "t266.cu"
 int __cuda_local_var_33159_13_non_const_t1;
# 26 "t266.cu"
__cuda_local_var_33158_13_non_const_t0 = (a[__cuda_local_var_33150_9_non_const_tid]);
# 27 "t266.cu"
__cuda_local_var_33159_13_non_const_t1 = (a[(__cuda_local_var_33150_9_non_const_tid + 2)]);
# 29 "t266.cu"
(a[__cuda_local_var_33150_9_non_const_tid]) = (__cuda_local_var_33158_13_non_const_t0 + __cuda_local_var_33159_13_non_const_t1);
# 31 "t266.cu"
}
# 35 "t266.cu"
}}
