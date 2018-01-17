# 1 "t266.cu"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
# 1
#pragma GCC diagnostic push
# 1
#pragma GCC diagnostic ignored "-Wunused-variable"
# 1
#pragma GCC diagnostic ignored "-Wunused-function"
# 1
static char __nv_inited_managed_rt = 0; static void **__nv_fatbinhandle_for_managed_rt; static void __nv_save_fatbinhandle_for_managed_rt(void **in){__nv_fatbinhandle_for_managed_rt = in;} static char __nv_init_managed_rt_with_module(void **); static inline void __nv_init_managed_rt(void) { __nv_inited_managed_rt = (__nv_inited_managed_rt ? __nv_inited_managed_rt                 : __nv_init_managed_rt_with_module(__nv_fatbinhandle_for_managed_rt));}
# 1
#pragma GCC diagnostic pop
# 1
#pragma GCC diagnostic ignored "-Wunused-variable"

# 1
#define __nv_is_extended_device_lambda_closure_type(X) false
#define __nv_is_extended_host_device_lambda_closure_type(X) false

# 1
# 56 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda_runtime.h"
#pragma GCC diagnostic push
# 59
#pragma GCC diagnostic ignored "-Wunused-function"
# 61 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_types.h"
#if 0
# 61
enum cudaRoundMode { 
# 63
cudaRoundNearest, 
# 64
cudaRoundZero, 
# 65
cudaRoundPosInf, 
# 66
cudaRoundMinInf
# 67
}; 
#endif
# 147 "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h" 3
typedef long ptrdiff_t; 
# 212
typedef unsigned long size_t; 
#include "crt/host_runtime.h"
# 156 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 156
enum cudaError { 
# 163
cudaSuccess, 
# 169
cudaErrorMissingConfiguration, 
# 175
cudaErrorMemoryAllocation, 
# 181
cudaErrorInitializationError, 
# 191
cudaErrorLaunchFailure, 
# 200
cudaErrorPriorLaunchFailure, 
# 210
cudaErrorLaunchTimeout, 
# 219
cudaErrorLaunchOutOfResources, 
# 225
cudaErrorInvalidDeviceFunction, 
# 234
cudaErrorInvalidConfiguration, 
# 240
cudaErrorInvalidDevice, 
# 246
cudaErrorInvalidValue, 
# 252
cudaErrorInvalidPitchValue, 
# 258
cudaErrorInvalidSymbol, 
# 263
cudaErrorMapBufferObjectFailed, 
# 268
cudaErrorUnmapBufferObjectFailed, 
# 274
cudaErrorInvalidHostPointer, 
# 280
cudaErrorInvalidDevicePointer, 
# 286
cudaErrorInvalidTexture, 
# 292
cudaErrorInvalidTextureBinding, 
# 299
cudaErrorInvalidChannelDescriptor, 
# 305
cudaErrorInvalidMemcpyDirection, 
# 315
cudaErrorAddressOfConstant, 
# 324
cudaErrorTextureFetchFailed, 
# 333
cudaErrorTextureNotBound, 
# 342
cudaErrorSynchronizationError, 
# 348
cudaErrorInvalidFilterSetting, 
# 354
cudaErrorInvalidNormSetting, 
# 362
cudaErrorMixedDeviceExecution, 
# 369
cudaErrorCudartUnloading, 
# 374
cudaErrorUnknown, 
# 382
cudaErrorNotYetImplemented, 
# 391
cudaErrorMemoryValueTooLarge, 
# 398
cudaErrorInvalidResourceHandle, 
# 406
cudaErrorNotReady, 
# 413
cudaErrorInsufficientDriver, 
# 426
cudaErrorSetOnActiveProcess, 
# 432
cudaErrorInvalidSurface, 
# 438
cudaErrorNoDevice, 
# 444
cudaErrorECCUncorrectable, 
# 449
cudaErrorSharedObjectSymbolNotFound, 
# 454
cudaErrorSharedObjectInitFailed, 
# 460
cudaErrorUnsupportedLimit, 
# 466
cudaErrorDuplicateVariableName, 
# 472
cudaErrorDuplicateTextureName, 
# 478
cudaErrorDuplicateSurfaceName, 
# 488
cudaErrorDevicesUnavailable, 
# 493
cudaErrorInvalidKernelImage, 
# 501
cudaErrorNoKernelImageForDevice, 
# 514
cudaErrorIncompatibleDriverContext, 
# 521
cudaErrorPeerAccessAlreadyEnabled, 
# 528
cudaErrorPeerAccessNotEnabled, 
# 534
cudaErrorDeviceAlreadyInUse = 54, 
# 541
cudaErrorProfilerDisabled, 
# 549
cudaErrorProfilerNotInitialized, 
# 556
cudaErrorProfilerAlreadyStarted, 
# 563
cudaErrorProfilerAlreadyStopped, 
# 571
cudaErrorAssert, 
# 578
cudaErrorTooManyPeers, 
# 584
cudaErrorHostMemoryAlreadyRegistered, 
# 590
cudaErrorHostMemoryNotRegistered, 
# 595
cudaErrorOperatingSystem, 
# 601
cudaErrorPeerAccessUnsupported, 
# 608
cudaErrorLaunchMaxDepthExceeded, 
# 616
cudaErrorLaunchFileScopedTex, 
# 624
cudaErrorLaunchFileScopedSurf, 
# 639
cudaErrorSyncDepthExceeded, 
# 651
cudaErrorLaunchPendingCountExceeded, 
# 656
cudaErrorNotPermitted, 
# 662
cudaErrorNotSupported, 
# 671
cudaErrorHardwareStackError, 
# 679
cudaErrorIllegalInstruction, 
# 688
cudaErrorMisalignedAddress, 
# 699
cudaErrorInvalidAddressSpace, 
# 707
cudaErrorInvalidPc, 
# 715
cudaErrorIllegalAddress, 
# 721
cudaErrorInvalidPtx, 
# 726
cudaErrorInvalidGraphicsContext, 
# 732
cudaErrorNvlinkUncorrectable, 
# 737
cudaErrorStartupFailure = 127, 
# 745
cudaErrorApiFailureBase = 10000
# 746
}; 
#endif
# 751 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 751
enum cudaChannelFormatKind { 
# 753
cudaChannelFormatKindSigned, 
# 754
cudaChannelFormatKindUnsigned, 
# 755
cudaChannelFormatKindFloat, 
# 756
cudaChannelFormatKindNone
# 757
}; 
#endif
# 762 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 762
struct cudaChannelFormatDesc { 
# 764
int x; 
# 765
int y; 
# 766
int z; 
# 767
int w; 
# 768
cudaChannelFormatKind f; 
# 769
}; 
#endif
# 774 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
typedef struct cudaArray *cudaArray_t; 
# 779
typedef const cudaArray *cudaArray_const_t; 
# 781
struct cudaArray; 
# 786
typedef struct cudaMipmappedArray *cudaMipmappedArray_t; 
# 791
typedef const cudaMipmappedArray *cudaMipmappedArray_const_t; 
# 793
struct cudaMipmappedArray; 
# 798
#if 0
# 798
enum cudaMemoryType { 
# 800
cudaMemoryTypeHost = 1, 
# 801
cudaMemoryTypeDevice
# 802
}; 
#endif
# 807 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 807
enum cudaMemcpyKind { 
# 809
cudaMemcpyHostToHost, 
# 810
cudaMemcpyHostToDevice, 
# 811
cudaMemcpyDeviceToHost, 
# 812
cudaMemcpyDeviceToDevice, 
# 813
cudaMemcpyDefault
# 814
}; 
#endif
# 821 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 821
struct cudaPitchedPtr { 
# 823
void *ptr; 
# 824
::size_t pitch; 
# 825
::size_t xsize; 
# 826
::size_t ysize; 
# 827
}; 
#endif
# 834 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 834
struct cudaExtent { 
# 836
::size_t width; 
# 837
::size_t height; 
# 838
::size_t depth; 
# 839
}; 
#endif
# 846 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 846
struct cudaPos { 
# 848
::size_t x; 
# 849
::size_t y; 
# 850
::size_t z; 
# 851
}; 
#endif
# 856 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 856
struct cudaMemcpy3DParms { 
# 858
cudaArray_t srcArray; 
# 859
cudaPos srcPos; 
# 860
cudaPitchedPtr srcPtr; 
# 862
cudaArray_t dstArray; 
# 863
cudaPos dstPos; 
# 864
cudaPitchedPtr dstPtr; 
# 866
cudaExtent extent; 
# 867
cudaMemcpyKind kind; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
# 868
}; 
#endif
# 873 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 873
struct cudaMemcpy3DPeerParms { 
# 875
cudaArray_t srcArray; 
# 876
cudaPos srcPos; 
# 877
cudaPitchedPtr srcPtr; 
# 878
int srcDevice; 
# 880
cudaArray_t dstArray; 
# 881
cudaPos dstPos; 
# 882
cudaPitchedPtr dstPtr; 
# 883
int dstDevice; 
# 885
cudaExtent extent; 
# 886
}; 
#endif
# 891 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
struct cudaGraphicsResource; 
# 896
#if 0
# 896
enum cudaGraphicsRegisterFlags { 
# 898
cudaGraphicsRegisterFlagsNone, 
# 899
cudaGraphicsRegisterFlagsReadOnly, 
# 900
cudaGraphicsRegisterFlagsWriteDiscard, 
# 901
cudaGraphicsRegisterFlagsSurfaceLoadStore = 4, 
# 902
cudaGraphicsRegisterFlagsTextureGather = 8
# 903
}; 
#endif
# 908 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 908
enum cudaGraphicsMapFlags { 
# 910
cudaGraphicsMapFlagsNone, 
# 911
cudaGraphicsMapFlagsReadOnly, 
# 912
cudaGraphicsMapFlagsWriteDiscard
# 913
}; 
#endif
# 918 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 918
enum cudaGraphicsCubeFace { 
# 920
cudaGraphicsCubeFacePositiveX, 
# 921
cudaGraphicsCubeFaceNegativeX, 
# 922
cudaGraphicsCubeFacePositiveY, 
# 923
cudaGraphicsCubeFaceNegativeY, 
# 924
cudaGraphicsCubeFacePositiveZ, 
# 925
cudaGraphicsCubeFaceNegativeZ
# 926
}; 
#endif
# 931 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 931
enum cudaResourceType { 
# 933
cudaResourceTypeArray, 
# 934
cudaResourceTypeMipmappedArray, 
# 935
cudaResourceTypeLinear, 
# 936
cudaResourceTypePitch2D
# 937
}; 
#endif
# 942 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 942
enum cudaResourceViewFormat { 
# 944
cudaResViewFormatNone, 
# 945
cudaResViewFormatUnsignedChar1, 
# 946
cudaResViewFormatUnsignedChar2, 
# 947
cudaResViewFormatUnsignedChar4, 
# 948
cudaResViewFormatSignedChar1, 
# 949
cudaResViewFormatSignedChar2, 
# 950
cudaResViewFormatSignedChar4, 
# 951
cudaResViewFormatUnsignedShort1, 
# 952
cudaResViewFormatUnsignedShort2, 
# 953
cudaResViewFormatUnsignedShort4, 
# 954
cudaResViewFormatSignedShort1, 
# 955
cudaResViewFormatSignedShort2, 
# 956
cudaResViewFormatSignedShort4, 
# 957
cudaResViewFormatUnsignedInt1, 
# 958
cudaResViewFormatUnsignedInt2, 
# 959
cudaResViewFormatUnsignedInt4, 
# 960
cudaResViewFormatSignedInt1, 
# 961
cudaResViewFormatSignedInt2, 
# 962
cudaResViewFormatSignedInt4, 
# 963
cudaResViewFormatHalf1, 
# 964
cudaResViewFormatHalf2, 
# 965
cudaResViewFormatHalf4, 
# 966
cudaResViewFormatFloat1, 
# 967
cudaResViewFormatFloat2, 
# 968
cudaResViewFormatFloat4, 
# 969
cudaResViewFormatUnsignedBlockCompressed1, 
# 970
cudaResViewFormatUnsignedBlockCompressed2, 
# 971
cudaResViewFormatUnsignedBlockCompressed3, 
# 972
cudaResViewFormatUnsignedBlockCompressed4, 
# 973
cudaResViewFormatSignedBlockCompressed4, 
# 974
cudaResViewFormatUnsignedBlockCompressed5, 
# 975
cudaResViewFormatSignedBlockCompressed5, 
# 976
cudaResViewFormatUnsignedBlockCompressed6H, 
# 977
cudaResViewFormatSignedBlockCompressed6H, 
# 978
cudaResViewFormatUnsignedBlockCompressed7
# 979
}; 
#endif
# 984 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 984
struct cudaResourceDesc { 
# 985
cudaResourceType resType; 
# 987
union { 
# 988
struct { 
# 989
cudaArray_t array; 
# 990
} array; 
# 991
struct { 
# 992
cudaMipmappedArray_t mipmap; 
# 993
} mipmap; 
# 994
struct { 
# 995
void *devPtr; 
# 996
cudaChannelFormatDesc desc; 
# 997
::size_t sizeInBytes; 
# 998
} linear; 
# 999
struct { 
# 1000
void *devPtr; 
# 1001
cudaChannelFormatDesc desc; 
# 1002
::size_t width; 
# 1003
::size_t height; 
# 1004
::size_t pitchInBytes; 
# 1005
} pitch2D; 
# 1006
} res; 
# 1007
}; 
#endif
# 1012 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1012
struct cudaResourceViewDesc { 
# 1014
cudaResourceViewFormat format; 
# 1015
::size_t width; 
# 1016
::size_t height; 
# 1017
::size_t depth; 
# 1018
unsigned firstMipmapLevel; 
# 1019
unsigned lastMipmapLevel; 
# 1020
unsigned firstLayer; 
# 1021
unsigned lastLayer; 
# 1022
}; 
#endif
# 1027 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1027
struct cudaPointerAttributes { 
# 1033
cudaMemoryType memoryType; 
# 1044
int device; 
# 1050
void *devicePointer; 
# 1056
void *hostPointer; 
# 1061
int isManaged; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
# 1062
}; 
#endif
# 1067 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1067
struct cudaFuncAttributes { 
# 1074
::size_t sharedSizeBytes; 
# 1080
::size_t constSizeBytes; 
# 1085
::size_t localSizeBytes; 
# 1092
int maxThreadsPerBlock; 
# 1097
int numRegs; 
# 1104
int ptxVersion; 
# 1111
int binaryVersion; 
# 1117
int cacheModeCA; 
# 1118
}; 
#endif
# 1123 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1123
enum cudaFuncCache { 
# 1125
cudaFuncCachePreferNone, 
# 1126
cudaFuncCachePreferShared, 
# 1127
cudaFuncCachePreferL1, 
# 1128
cudaFuncCachePreferEqual
# 1129
}; 
#endif
# 1135 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1135
enum cudaSharedMemConfig { 
# 1137
cudaSharedMemBankSizeDefault, 
# 1138
cudaSharedMemBankSizeFourByte, 
# 1139
cudaSharedMemBankSizeEightByte
# 1140
}; 
#endif
# 1145 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1145
enum cudaComputeMode { 
# 1147
cudaComputeModeDefault, 
# 1148
cudaComputeModeExclusive, 
# 1149
cudaComputeModeProhibited, 
# 1150
cudaComputeModeExclusiveProcess
# 1151
}; 
#endif
# 1156 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1156
enum cudaLimit { 
# 1158
cudaLimitStackSize, 
# 1159
cudaLimitPrintfFifoSize, 
# 1160
cudaLimitMallocHeapSize, 
# 1161
cudaLimitDevRuntimeSyncDepth, 
# 1162
cudaLimitDevRuntimePendingLaunchCount
# 1163
}; 
#endif
# 1168 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1168
enum cudaMemoryAdvise { 
# 1170
cudaMemAdviseSetReadMostly = 1, 
# 1171
cudaMemAdviseUnsetReadMostly, 
# 1172
cudaMemAdviseSetPreferredLocation, 
# 1173
cudaMemAdviseUnsetPreferredLocation, 
# 1174
cudaMemAdviseSetAccessedBy, 
# 1175
cudaMemAdviseUnsetAccessedBy
# 1176
}; 
#endif
# 1181 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1181
enum cudaMemRangeAttribute { 
# 1183
cudaMemRangeAttributeReadMostly = 1, 
# 1184
cudaMemRangeAttributePreferredLocation, 
# 1185
cudaMemRangeAttributeAccessedBy, 
# 1186
cudaMemRangeAttributeLastPrefetchLocation
# 1187
}; 
#endif
# 1192 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1192
enum cudaOutputMode { 
# 1194
cudaKeyValuePair, 
# 1195
cudaCSV
# 1196
}; 
#endif
# 1201 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1201
enum cudaDeviceAttr { 
# 1203
cudaDevAttrMaxThreadsPerBlock = 1, 
# 1204
cudaDevAttrMaxBlockDimX, 
# 1205
cudaDevAttrMaxBlockDimY, 
# 1206
cudaDevAttrMaxBlockDimZ, 
# 1207
cudaDevAttrMaxGridDimX, 
# 1208
cudaDevAttrMaxGridDimY, 
# 1209
cudaDevAttrMaxGridDimZ, 
# 1210
cudaDevAttrMaxSharedMemoryPerBlock, 
# 1211
cudaDevAttrTotalConstantMemory, 
# 1212
cudaDevAttrWarpSize, 
# 1213
cudaDevAttrMaxPitch, 
# 1214
cudaDevAttrMaxRegistersPerBlock, 
# 1215
cudaDevAttrClockRate, 
# 1216
cudaDevAttrTextureAlignment, 
# 1217
cudaDevAttrGpuOverlap, 
# 1218
cudaDevAttrMultiProcessorCount, 
# 1219
cudaDevAttrKernelExecTimeout, 
# 1220
cudaDevAttrIntegrated, 
# 1221
cudaDevAttrCanMapHostMemory, 
# 1222
cudaDevAttrComputeMode, 
# 1223
cudaDevAttrMaxTexture1DWidth, 
# 1224
cudaDevAttrMaxTexture2DWidth, 
# 1225
cudaDevAttrMaxTexture2DHeight, 
# 1226
cudaDevAttrMaxTexture3DWidth, 
# 1227
cudaDevAttrMaxTexture3DHeight, 
# 1228
cudaDevAttrMaxTexture3DDepth, 
# 1229
cudaDevAttrMaxTexture2DLayeredWidth, 
# 1230
cudaDevAttrMaxTexture2DLayeredHeight, 
# 1231
cudaDevAttrMaxTexture2DLayeredLayers, 
# 1232
cudaDevAttrSurfaceAlignment, 
# 1233
cudaDevAttrConcurrentKernels, 
# 1234
cudaDevAttrEccEnabled, 
# 1235
cudaDevAttrPciBusId, 
# 1236
cudaDevAttrPciDeviceId, 
# 1237
cudaDevAttrTccDriver, 
# 1238
cudaDevAttrMemoryClockRate, 
# 1239
cudaDevAttrGlobalMemoryBusWidth, 
# 1240
cudaDevAttrL2CacheSize, 
# 1241
cudaDevAttrMaxThreadsPerMultiProcessor, 
# 1242
cudaDevAttrAsyncEngineCount, 
# 1243
cudaDevAttrUnifiedAddressing, 
# 1244
cudaDevAttrMaxTexture1DLayeredWidth, 
# 1245
cudaDevAttrMaxTexture1DLayeredLayers, 
# 1246
cudaDevAttrMaxTexture2DGatherWidth = 45, 
# 1247
cudaDevAttrMaxTexture2DGatherHeight, 
# 1248
cudaDevAttrMaxTexture3DWidthAlt, 
# 1249
cudaDevAttrMaxTexture3DHeightAlt, 
# 1250
cudaDevAttrMaxTexture3DDepthAlt, 
# 1251
cudaDevAttrPciDomainId, 
# 1252
cudaDevAttrTexturePitchAlignment, 
# 1253
cudaDevAttrMaxTextureCubemapWidth, 
# 1254
cudaDevAttrMaxTextureCubemapLayeredWidth, 
# 1255
cudaDevAttrMaxTextureCubemapLayeredLayers, 
# 1256
cudaDevAttrMaxSurface1DWidth, 
# 1257
cudaDevAttrMaxSurface2DWidth, 
# 1258
cudaDevAttrMaxSurface2DHeight, 
# 1259
cudaDevAttrMaxSurface3DWidth, 
# 1260
cudaDevAttrMaxSurface3DHeight, 
# 1261
cudaDevAttrMaxSurface3DDepth, 
# 1262
cudaDevAttrMaxSurface1DLayeredWidth, 
# 1263
cudaDevAttrMaxSurface1DLayeredLayers, 
# 1264
cudaDevAttrMaxSurface2DLayeredWidth, 
# 1265
cudaDevAttrMaxSurface2DLayeredHeight, 
# 1266
cudaDevAttrMaxSurface2DLayeredLayers, 
# 1267
cudaDevAttrMaxSurfaceCubemapWidth, 
# 1268
cudaDevAttrMaxSurfaceCubemapLayeredWidth, 
# 1269
cudaDevAttrMaxSurfaceCubemapLayeredLayers, 
# 1270
cudaDevAttrMaxTexture1DLinearWidth, 
# 1271
cudaDevAttrMaxTexture2DLinearWidth, 
# 1272
cudaDevAttrMaxTexture2DLinearHeight, 
# 1273
cudaDevAttrMaxTexture2DLinearPitch, 
# 1274
cudaDevAttrMaxTexture2DMipmappedWidth, 
# 1275
cudaDevAttrMaxTexture2DMipmappedHeight, 
# 1276
cudaDevAttrComputeCapabilityMajor, 
# 1277
cudaDevAttrComputeCapabilityMinor, 
# 1278
cudaDevAttrMaxTexture1DMipmappedWidth, 
# 1279
cudaDevAttrStreamPrioritiesSupported, 
# 1280
cudaDevAttrGlobalL1CacheSupported, 
# 1281
cudaDevAttrLocalL1CacheSupported, 
# 1282
cudaDevAttrMaxSharedMemoryPerMultiprocessor, 
# 1283
cudaDevAttrMaxRegistersPerMultiprocessor, 
# 1284
cudaDevAttrManagedMemory, 
# 1285
cudaDevAttrIsMultiGpuBoard, 
# 1286
cudaDevAttrMultiGpuBoardGroupID, 
# 1287
cudaDevAttrHostNativeAtomicSupported, 
# 1288
cudaDevAttrSingleToDoublePrecisionPerfRatio, 
# 1289
cudaDevAttrPageableMemoryAccess, 
# 1290
cudaDevAttrConcurrentManagedAccess, 
# 1291
cudaDevAttrComputePreemptionSupported, 
# 1292
cudaDevAttrCanUseHostPointerForRegisteredMem
# 1293
}; 
#endif
# 1299 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1299
enum cudaDeviceP2PAttr { 
# 1300
cudaDevP2PAttrPerformanceRank = 1, 
# 1301
cudaDevP2PAttrAccessSupported, 
# 1302
cudaDevP2PAttrNativeAtomicSupported
# 1303
}; 
#endif
# 1307 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
# 1307
struct cudaDeviceProp { 
# 1309
char name[256]; 
# 1310
::size_t totalGlobalMem; 
# 1311
::size_t sharedMemPerBlock; 
# 1312
int regsPerBlock; 
# 1313
int warpSize; 
# 1314
::size_t memPitch; 
# 1315
int maxThreadsPerBlock; 
# 1316
int maxThreadsDim[3]; 
# 1317
int maxGridSize[3]; 
# 1318
int clockRate; 
# 1319
::size_t totalConstMem; 
# 1320
int major; 
# 1321
int minor; 
# 1322
::size_t textureAlignment; 
# 1323
::size_t texturePitchAlignment; 
# 1324
int deviceOverlap; 
# 1325
int multiProcessorCount; 
# 1326
int kernelExecTimeoutEnabled; 
# 1327
int integrated; 
# 1328
int canMapHostMemory; 
# 1329
int computeMode; 
# 1330
int maxTexture1D; 
# 1331
int maxTexture1DMipmap; 
# 1332
int maxTexture1DLinear; 
# 1333
int maxTexture2D[2]; 
# 1334
int maxTexture2DMipmap[2]; 
# 1335
int maxTexture2DLinear[3]; 
# 1336
int maxTexture2DGather[2]; 
# 1337
int maxTexture3D[3]; 
# 1338
int maxTexture3DAlt[3]; 
# 1339
int maxTextureCubemap; 
# 1340
int maxTexture1DLayered[2]; 
# 1341
int maxTexture2DLayered[3]; 
# 1342
int maxTextureCubemapLayered[2]; 
# 1343
int maxSurface1D; 
# 1344
int maxSurface2D[2]; 
# 1345
int maxSurface3D[3]; 
# 1346
int maxSurface1DLayered[2]; 
# 1347
int maxSurface2DLayered[3]; 
# 1348
int maxSurfaceCubemap; 
# 1349
int maxSurfaceCubemapLayered[2]; 
# 1350
::size_t surfaceAlignment; 
# 1351
int concurrentKernels; 
# 1352
int ECCEnabled; 
# 1353
int pciBusID; 
# 1354
int pciDeviceID; 
# 1355
int pciDomainID; 
# 1356
int tccDriver; 
# 1357
int asyncEngineCount; 
# 1358
int unifiedAddressing; 
# 1359
int memoryClockRate; 
# 1360
int memoryBusWidth; 
# 1361
int l2CacheSize; 
# 1362
int maxThreadsPerMultiProcessor; 
# 1363
int streamPrioritiesSupported; 
# 1364
int globalL1CacheSupported; 
# 1365
int localL1CacheSupported; 
# 1366
::size_t sharedMemPerMultiprocessor; 
# 1367
int regsPerMultiprocessor; 
# 1368
int managedMemory; 
# 1369
int isMultiGpuBoard; 
# 1370
int multiGpuBoardGroupID; 
# 1371
int hostNativeAtomicSupported; 
# 1372
int singleToDoublePrecisionPerfRatio; 
# 1373
int pageableMemoryAccess; 
# 1374
int concurrentManagedAccess; 
# 1375
}; 
#endif
# 1458 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef 
# 1455
struct cudaIpcEventHandle_st { 
# 1457
char reserved[64]; 
# 1458
} cudaIpcEventHandle_t; 
#endif
# 1466 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef 
# 1463
struct cudaIpcMemHandle_st { 
# 1465
char reserved[64]; 
# 1466
} cudaIpcMemHandle_t; 
#endif
# 1477 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef cudaError 
# 1477
cudaError_t; 
#endif
# 1482 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUstream_st *
# 1482
cudaStream_t; 
#endif
# 1487 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUevent_st *
# 1487
cudaEvent_t; 
#endif
# 1492 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef cudaGraphicsResource *
# 1492
cudaGraphicsResource_t; 
#endif
# 1497 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef struct CUuuid_st 
# 1497
cudaUUID_t; 
#endif
# 1502 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_types.h"
#if 0
typedef cudaOutputMode 
# 1502
cudaOutputMode_t; 
#endif
# 84 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_types.h"
#if 0
# 84
enum cudaSurfaceBoundaryMode { 
# 86
cudaBoundaryModeZero, 
# 87
cudaBoundaryModeClamp, 
# 88
cudaBoundaryModeTrap
# 89
}; 
#endif
# 94 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_types.h"
#if 0
# 94
enum cudaSurfaceFormatMode { 
# 96
cudaFormatModeForced, 
# 97
cudaFormatModeAuto
# 98
}; 
#endif
# 103 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_types.h"
#if 0
# 103
struct surfaceReference { 
# 108
cudaChannelFormatDesc channelDesc; 
# 109
}; 
#endif
# 114 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_types.h"
#if 0
typedef unsigned long long 
# 114
cudaSurfaceObject_t; 
#endif
# 84 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 84
enum cudaTextureAddressMode { 
# 86
cudaAddressModeWrap, 
# 87
cudaAddressModeClamp, 
# 88
cudaAddressModeMirror, 
# 89
cudaAddressModeBorder
# 90
}; 
#endif
# 95 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 95
enum cudaTextureFilterMode { 
# 97
cudaFilterModePoint, 
# 98
cudaFilterModeLinear
# 99
}; 
#endif
# 104 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 104
enum cudaTextureReadMode { 
# 106
cudaReadModeElementType, 
# 107
cudaReadModeNormalizedFloat
# 108
}; 
#endif
# 113 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 113
struct textureReference { 
# 118
int normalized; 
# 122
cudaTextureFilterMode filterMode; 
# 126
cudaTextureAddressMode addressMode[3]; 
# 130
cudaChannelFormatDesc channelDesc; 
# 134
int sRGB; 
# 138
unsigned maxAnisotropy; 
# 142
cudaTextureFilterMode mipmapFilterMode; 
# 146
float mipmapLevelBias; 
# 150
float minMipmapLevelClamp; 
# 154
float maxMipmapLevelClamp; 
# 155
int __cudaReserved[15]; 
# 156
}; 
#endif
# 161 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
# 161
struct cudaTextureDesc { 
# 166
cudaTextureAddressMode addressMode[3]; 
# 170
cudaTextureFilterMode filterMode; 
# 174
cudaTextureReadMode readMode; 
# 178
int sRGB; 
# 182
float borderColor[4]; 
# 186
int normalizedCoords; 
# 190
unsigned maxAnisotropy; 
# 194
cudaTextureFilterMode mipmapFilterMode; 
# 198
float mipmapLevelBias; 
# 202
float minMipmapLevelClamp; 
# 206
float maxMipmapLevelClamp; 
# 207
}; 
#endif
# 212 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_types.h"
#if 0
typedef unsigned long long 
# 212
cudaTextureObject_t; 
#endif
# 98 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 98
struct char1 { 
# 100
signed char x; 
# 101
}; 
#endif
# 103 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 103
struct uchar1 { 
# 105
unsigned char x; 
# 106
}; 
#endif
# 109 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 109
struct __attribute((aligned(2))) char2 { 
# 111
signed char x, y; 
# 112
}; 
#endif
# 114 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 114
struct __attribute((aligned(2))) uchar2 { 
# 116
unsigned char x, y; 
# 117
}; 
#endif
# 119 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 119
struct char3 { 
# 121
signed char x, y, z; 
# 122
}; 
#endif
# 124 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 124
struct uchar3 { 
# 126
unsigned char x, y, z; 
# 127
}; 
#endif
# 129 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 129
struct __attribute((aligned(4))) char4 { 
# 131
signed char x, y, z, w; 
# 132
}; 
#endif
# 134 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 134
struct __attribute((aligned(4))) uchar4 { 
# 136
unsigned char x, y, z, w; 
# 137
}; 
#endif
# 139 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 139
struct short1 { 
# 141
short x; 
# 142
}; 
#endif
# 144 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 144
struct ushort1 { 
# 146
unsigned short x; 
# 147
}; 
#endif
# 149 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 149
struct __attribute((aligned(4))) short2 { 
# 151
short x, y; 
# 152
}; 
#endif
# 154 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 154
struct __attribute((aligned(4))) ushort2 { 
# 156
unsigned short x, y; 
# 157
}; 
#endif
# 159 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 159
struct short3 { 
# 161
short x, y, z; 
# 162
}; 
#endif
# 164 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 164
struct ushort3 { 
# 166
unsigned short x, y, z; 
# 167
}; 
#endif
# 169 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 169
struct __attribute((aligned(8))) short4 { short x; short y; short z; short w; }; 
#endif
# 170 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 170
struct __attribute((aligned(8))) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; }; 
#endif
# 172 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 172
struct int1 { 
# 174
int x; 
# 175
}; 
#endif
# 177 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 177
struct uint1 { 
# 179
unsigned x; 
# 180
}; 
#endif
# 182 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 182
struct __attribute((aligned(8))) int2 { int x; int y; }; 
#endif
# 183 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 183
struct __attribute((aligned(8))) uint2 { unsigned x; unsigned y; }; 
#endif
# 185 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 185
struct int3 { 
# 187
int x, y, z; 
# 188
}; 
#endif
# 190 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 190
struct uint3 { 
# 192
unsigned x, y, z; 
# 193
}; 
#endif
# 195 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 195
struct __attribute((aligned(16))) int4 { 
# 197
int x, y, z, w; 
# 198
}; 
#endif
# 200 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 200
struct __attribute((aligned(16))) uint4 { 
# 202
unsigned x, y, z, w; 
# 203
}; 
#endif
# 205 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 205
struct long1 { 
# 207
long x; 
# 208
}; 
#endif
# 210 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 210
struct ulong1 { 
# 212
unsigned long x; 
# 213
}; 
#endif
# 220 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 220
struct __attribute((aligned((2) * sizeof(long)))) long2 { 
# 222
long x, y; 
# 223
}; 
#endif
# 225 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 225
struct __attribute((aligned((2) * sizeof(unsigned long)))) ulong2 { 
# 227
unsigned long x, y; 
# 228
}; 
#endif
# 232 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 232
struct long3 { 
# 234
long x, y, z; 
# 235
}; 
#endif
# 237 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 237
struct ulong3 { 
# 239
unsigned long x, y, z; 
# 240
}; 
#endif
# 242 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 242
struct __attribute((aligned(16))) long4 { 
# 244
long x, y, z, w; 
# 245
}; 
#endif
# 247 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 247
struct __attribute((aligned(16))) ulong4 { 
# 249
unsigned long x, y, z, w; 
# 250
}; 
#endif
# 252 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 252
struct float1 { 
# 254
float x; 
# 255
}; 
#endif
# 274 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 274
struct __attribute((aligned(8))) float2 { float x; float y; }; 
#endif
# 279 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 279
struct float3 { 
# 281
float x, y, z; 
# 282
}; 
#endif
# 284 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 284
struct __attribute((aligned(16))) float4 { 
# 286
float x, y, z, w; 
# 287
}; 
#endif
# 289 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 289
struct longlong1 { 
# 291
long long x; 
# 292
}; 
#endif
# 294 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 294
struct ulonglong1 { 
# 296
unsigned long long x; 
# 297
}; 
#endif
# 299 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 299
struct __attribute((aligned(16))) longlong2 { 
# 301
long long x, y; 
# 302
}; 
#endif
# 304 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 304
struct __attribute((aligned(16))) ulonglong2 { 
# 306
unsigned long long x, y; 
# 307
}; 
#endif
# 309 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 309
struct longlong3 { 
# 311
long long x, y, z; 
# 312
}; 
#endif
# 314 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 314
struct ulonglong3 { 
# 316
unsigned long long x, y, z; 
# 317
}; 
#endif
# 319 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 319
struct __attribute((aligned(16))) longlong4 { 
# 321
long long x, y, z, w; 
# 322
}; 
#endif
# 324 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 324
struct __attribute((aligned(16))) ulonglong4 { 
# 326
unsigned long long x, y, z, w; 
# 327
}; 
#endif
# 329 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 329
struct double1 { 
# 331
double x; 
# 332
}; 
#endif
# 334 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 334
struct __attribute((aligned(16))) double2 { 
# 336
double x, y; 
# 337
}; 
#endif
# 339 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 339
struct double3 { 
# 341
double x, y, z; 
# 342
}; 
#endif
# 344 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 344
struct __attribute((aligned(16))) double4 { 
# 346
double x, y, z, w; 
# 347
}; 
#endif
# 362 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef char1 
# 362
char1; 
#endif
# 363 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uchar1 
# 363
uchar1; 
#endif
# 364 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef char2 
# 364
char2; 
#endif
# 365 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uchar2 
# 365
uchar2; 
#endif
# 366 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef char3 
# 366
char3; 
#endif
# 367 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uchar3 
# 367
uchar3; 
#endif
# 368 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef char4 
# 368
char4; 
#endif
# 369 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uchar4 
# 369
uchar4; 
#endif
# 370 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef short1 
# 370
short1; 
#endif
# 371 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ushort1 
# 371
ushort1; 
#endif
# 372 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef short2 
# 372
short2; 
#endif
# 373 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ushort2 
# 373
ushort2; 
#endif
# 374 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef short3 
# 374
short3; 
#endif
# 375 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ushort3 
# 375
ushort3; 
#endif
# 376 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef short4 
# 376
short4; 
#endif
# 377 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ushort4 
# 377
ushort4; 
#endif
# 378 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef int1 
# 378
int1; 
#endif
# 379 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uint1 
# 379
uint1; 
#endif
# 380 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef int2 
# 380
int2; 
#endif
# 381 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uint2 
# 381
uint2; 
#endif
# 382 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef int3 
# 382
int3; 
#endif
# 383 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uint3 
# 383
uint3; 
#endif
# 384 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef int4 
# 384
int4; 
#endif
# 385 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef uint4 
# 385
uint4; 
#endif
# 386 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef long1 
# 386
long1; 
#endif
# 387 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulong1 
# 387
ulong1; 
#endif
# 388 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef long2 
# 388
long2; 
#endif
# 389 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulong2 
# 389
ulong2; 
#endif
# 390 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef long3 
# 390
long3; 
#endif
# 391 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulong3 
# 391
ulong3; 
#endif
# 392 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef long4 
# 392
long4; 
#endif
# 393 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulong4 
# 393
ulong4; 
#endif
# 394 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef float1 
# 394
float1; 
#endif
# 395 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef float2 
# 395
float2; 
#endif
# 396 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef float3 
# 396
float3; 
#endif
# 397 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef float4 
# 397
float4; 
#endif
# 398 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef longlong1 
# 398
longlong1; 
#endif
# 399 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulonglong1 
# 399
ulonglong1; 
#endif
# 400 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef longlong2 
# 400
longlong2; 
#endif
# 401 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulonglong2 
# 401
ulonglong2; 
#endif
# 402 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef longlong3 
# 402
longlong3; 
#endif
# 403 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulonglong3 
# 403
ulonglong3; 
#endif
# 404 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef longlong4 
# 404
longlong4; 
#endif
# 405 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef ulonglong4 
# 405
ulonglong4; 
#endif
# 406 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef double1 
# 406
double1; 
#endif
# 407 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef double2 
# 407
double2; 
#endif
# 408 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef double3 
# 408
double3; 
#endif
# 409 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef double4 
# 409
double4; 
#endif
# 417 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
# 417
struct dim3 { 
# 419
unsigned x, y, z; 
# 425
}; 
#endif
# 427 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_types.h"
#if 0
typedef dim3 
# 427
dim3; 
#endif
# 70 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/library_types.h"
typedef 
# 54
enum cudaDataType_t { 
# 56
CUDA_R_16F = 2, 
# 57
CUDA_C_16F = 6, 
# 58
CUDA_R_32F = 0, 
# 59
CUDA_C_32F = 4, 
# 60
CUDA_R_64F = 1, 
# 61
CUDA_C_64F = 5, 
# 62
CUDA_R_8I = 3, 
# 63
CUDA_C_8I = 7, 
# 64
CUDA_R_8U, 
# 65
CUDA_C_8U, 
# 66
CUDA_R_32I, 
# 67
CUDA_C_32I, 
# 68
CUDA_R_32U, 
# 69
CUDA_C_32U
# 70
} cudaDataType; 
# 78
typedef 
# 73
enum libraryPropertyType_t { 
# 75
MAJOR_VERSION, 
# 76
MINOR_VERSION, 
# 77
PATCH_LEVEL
# 78
} libraryPropertyType; 
# 104 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda_device_runtime_api.h"
extern "C" {
# 106
extern cudaError_t cudaDeviceGetAttribute(int * value, cudaDeviceAttr attr, int device); 
# 107
extern cudaError_t cudaDeviceGetLimit(::size_t * pValue, cudaLimit limit); 
# 108
extern cudaError_t cudaDeviceGetCacheConfig(cudaFuncCache * pCacheConfig); 
# 109
extern cudaError_t cudaDeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig); 
# 110
extern cudaError_t cudaDeviceSynchronize(); 
# 111
extern cudaError_t cudaGetLastError(); 
# 112
extern cudaError_t cudaPeekAtLastError(); 
# 113
extern const char *cudaGetErrorString(cudaError_t error); 
# 114
extern const char *cudaGetErrorName(cudaError_t error); 
# 115
extern cudaError_t cudaGetDeviceCount(int * count); 
# 116
extern cudaError_t cudaGetDevice(int * device); 
# 117
extern cudaError_t cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned flags); 
# 118
extern cudaError_t cudaStreamDestroy(cudaStream_t stream); 
# 119
extern cudaError_t cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
# 120
__attribute__((unused)) extern cudaError_t cudaStreamWaitEvent_ptsz(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
# 121
extern cudaError_t cudaEventCreateWithFlags(cudaEvent_t * event, unsigned flags); 
# 122
extern cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream); 
# 123
__attribute__((unused)) extern cudaError_t cudaEventRecord_ptsz(cudaEvent_t event, cudaStream_t stream); 
# 124
extern cudaError_t cudaEventDestroy(cudaEvent_t event); 
# 125
extern cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, const void * func); 
# 126
extern cudaError_t cudaFree(void * devPtr); 
# 127
extern cudaError_t cudaMalloc(void ** devPtr, ::size_t size); 
# 128
extern cudaError_t cudaMemcpyAsync(void * dst, const void * src, ::size_t count, cudaMemcpyKind kind, cudaStream_t stream); 
# 129
__attribute__((unused)) extern cudaError_t cudaMemcpyAsync_ptsz(void * dst, const void * src, ::size_t count, cudaMemcpyKind kind, cudaStream_t stream); 
# 130
extern cudaError_t cudaMemcpy2DAsync(void * dst, ::size_t dpitch, const void * src, ::size_t spitch, ::size_t width, ::size_t height, cudaMemcpyKind kind, cudaStream_t stream); 
# 131
__attribute__((unused)) extern cudaError_t cudaMemcpy2DAsync_ptsz(void * dst, ::size_t dpitch, const void * src, ::size_t spitch, ::size_t width, ::size_t height, cudaMemcpyKind kind, cudaStream_t stream); 
# 132
extern cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms * p, cudaStream_t stream); 
# 133
__attribute__((unused)) extern cudaError_t cudaMemcpy3DAsync_ptsz(const cudaMemcpy3DParms * p, cudaStream_t stream); 
# 134
extern cudaError_t cudaMemsetAsync(void * devPtr, int value, ::size_t count, cudaStream_t stream); 
# 135
__attribute__((unused)) extern cudaError_t cudaMemsetAsync_ptsz(void * devPtr, int value, ::size_t count, cudaStream_t stream); 
# 136
extern cudaError_t cudaMemset2DAsync(void * devPtr, ::size_t pitch, int value, ::size_t width, ::size_t height, cudaStream_t stream); 
# 137
__attribute__((unused)) extern cudaError_t cudaMemset2DAsync_ptsz(void * devPtr, ::size_t pitch, int value, ::size_t width, ::size_t height, cudaStream_t stream); 
# 138
extern cudaError_t cudaMemset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream); 
# 139
__attribute__((unused)) extern cudaError_t cudaMemset3DAsync_ptsz(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream); 
# 140
extern cudaError_t cudaRuntimeGetVersion(int * runtimeVersion); 
# 161
__attribute__((unused)) extern void *cudaGetParameterBuffer(::size_t alignment, ::size_t size); 
# 189
__attribute__((unused)) extern void *cudaGetParameterBufferV2(void * func, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize); 
# 190
__attribute__((unused)) extern cudaError_t cudaLaunchDevice_ptsz(void * func, void * parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream); 
# 191
__attribute__((unused)) extern cudaError_t cudaLaunchDeviceV2_ptsz(void * parameterBuffer, cudaStream_t stream); 
# 209
__attribute__((unused)) extern cudaError_t cudaLaunchDevice(void * func, void * parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream); 
# 210
__attribute__((unused)) extern cudaError_t cudaLaunchDeviceV2(void * parameterBuffer, cudaStream_t stream); 
# 213
extern cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, const void * func, int blockSize, ::size_t dynamicSmemSize); 
# 214
extern cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, const void * func, int blockSize, ::size_t dynamicSmemSize, unsigned flags); 
# 216
}
# 218
template< class T> static inline cudaError_t cudaMalloc(T ** devPtr, ::size_t size); 
# 219
template< class T> static inline cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, T * entry); 
# 220
template< class T> static inline cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, T func, int blockSize, ::size_t dynamicSmemSize); 
# 221
template< class T> static inline cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, T func, int blockSize, ::size_t dynamicSmemSize, unsigned flags); 
# 219 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda_runtime_api.h"
extern "C" {
# 252
extern cudaError_t cudaDeviceReset(); 
# 269
extern cudaError_t cudaDeviceSynchronize(); 
# 344
extern cudaError_t cudaDeviceSetLimit(cudaLimit limit, ::size_t value); 
# 373
extern cudaError_t cudaDeviceGetLimit(::size_t * pValue, cudaLimit limit); 
# 404
extern cudaError_t cudaDeviceGetCacheConfig(cudaFuncCache * pCacheConfig); 
# 439
extern cudaError_t cudaDeviceGetStreamPriorityRange(int * leastPriority, int * greatestPriority); 
# 481
extern cudaError_t cudaDeviceSetCacheConfig(cudaFuncCache cacheConfig); 
# 510
extern cudaError_t cudaDeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig); 
# 552
extern cudaError_t cudaDeviceSetSharedMemConfig(cudaSharedMemConfig config); 
# 575
extern cudaError_t cudaDeviceGetByPCIBusId(int * device, const char * pciBusId); 
# 602
extern cudaError_t cudaDeviceGetPCIBusId(char * pciBusId, int len, int device); 
# 644
extern cudaError_t cudaIpcGetEventHandle(cudaIpcEventHandle_t * handle, cudaEvent_t event); 
# 679
extern cudaError_t cudaIpcOpenEventHandle(cudaEvent_t * event, cudaIpcEventHandle_t handle); 
# 717
extern cudaError_t cudaIpcGetMemHandle(cudaIpcMemHandle_t * handle, void * devPtr); 
# 767
extern cudaError_t cudaIpcOpenMemHandle(void ** devPtr, cudaIpcMemHandle_t handle, unsigned flags); 
# 797
extern cudaError_t cudaIpcCloseMemHandle(void * devPtr); 
# 837
extern cudaError_t cudaThreadExit(); 
# 861
extern cudaError_t cudaThreadSynchronize(); 
# 908
extern cudaError_t cudaThreadSetLimit(cudaLimit limit, ::size_t value); 
# 939
extern cudaError_t cudaThreadGetLimit(::size_t * pValue, cudaLimit limit); 
# 974
extern cudaError_t cudaThreadGetCacheConfig(cudaFuncCache * pCacheConfig); 
# 1020
extern cudaError_t cudaThreadSetCacheConfig(cudaFuncCache cacheConfig); 
# 1074
extern cudaError_t cudaGetLastError(); 
# 1115
extern cudaError_t cudaPeekAtLastError(); 
# 1130
extern const char *cudaGetErrorName(cudaError_t error); 
# 1145
extern const char *cudaGetErrorString(cudaError_t error); 
# 1175
extern cudaError_t cudaGetDeviceCount(int * count); 
# 1421
extern cudaError_t cudaGetDeviceProperties(cudaDeviceProp * prop, int device); 
# 1593
extern cudaError_t cudaDeviceGetAttribute(int * value, cudaDeviceAttr attr, int device); 
# 1628
extern cudaError_t cudaDeviceGetP2PAttribute(int * value, cudaDeviceP2PAttr attr, int srcDevice, int dstDevice); 
# 1647
extern cudaError_t cudaChooseDevice(int * device, const cudaDeviceProp * prop); 
# 1681
extern cudaError_t cudaSetDevice(int device); 
# 1698
extern cudaError_t cudaGetDevice(int * device); 
# 1727
extern cudaError_t cudaSetValidDevices(int * device_arr, int len); 
# 1789
extern cudaError_t cudaSetDeviceFlags(unsigned flags); 
# 1830
extern cudaError_t cudaGetDeviceFlags(unsigned * flags); 
# 1867
extern cudaError_t cudaStreamCreate(cudaStream_t * pStream); 
# 1896
extern cudaError_t cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned flags); 
# 1939
extern cudaError_t cudaStreamCreateWithPriority(cudaStream_t * pStream, unsigned flags, int priority); 
# 1963
extern cudaError_t cudaStreamGetPriority(cudaStream_t hStream, int * priority); 
# 1984
extern cudaError_t cudaStreamGetFlags(cudaStream_t hStream, unsigned * flags); 
# 2005
extern cudaError_t cudaStreamDestroy(cudaStream_t stream); 
# 2037
extern cudaError_t cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
# 2051
typedef void (*cudaStreamCallback_t)(cudaStream_t stream, cudaError_t status, void * userData); 
# 2108
extern cudaError_t cudaStreamAddCallback(cudaStream_t stream, cudaStreamCallback_t callback, void * userData, unsigned flags); 
# 2128
extern cudaError_t cudaStreamSynchronize(cudaStream_t stream); 
# 2149
extern cudaError_t cudaStreamQuery(cudaStream_t stream); 
# 2220
extern cudaError_t cudaStreamAttachMemAsync(cudaStream_t stream, void * devPtr, ::size_t length = 0, unsigned flags = 4); 
# 2256
extern cudaError_t cudaEventCreate(cudaEvent_t * event); 
# 2290
extern cudaError_t cudaEventCreateWithFlags(cudaEvent_t * event, unsigned flags); 
# 2321
extern cudaError_t cudaEventRecord(cudaEvent_t event, cudaStream_t stream = 0); 
# 2353
extern cudaError_t cudaEventQuery(cudaEvent_t event); 
# 2385
extern cudaError_t cudaEventSynchronize(cudaEvent_t event); 
# 2410
extern cudaError_t cudaEventDestroy(cudaEvent_t event); 
# 2451
extern cudaError_t cudaEventElapsedTime(float * ms, cudaEvent_t start, cudaEvent_t end); 
# 2510
extern cudaError_t cudaLaunchKernel(const void * func, dim3 gridDim, dim3 blockDim, void ** args, ::size_t sharedMem, cudaStream_t stream); 
# 2560
extern cudaError_t cudaFuncSetCacheConfig(const void * func, cudaFuncCache cacheConfig); 
# 2614
extern cudaError_t cudaFuncSetSharedMemConfig(const void * func, cudaSharedMemConfig config); 
# 2648
extern cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, const void * func); 
# 2671
extern cudaError_t cudaSetDoubleForDevice(double * d); 
# 2694
extern cudaError_t cudaSetDoubleForHost(double * d); 
# 2750
extern cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, const void * func, int blockSize, ::size_t dynamicSMemSize); 
# 2794
extern cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, const void * func, int blockSize, ::size_t dynamicSMemSize, unsigned flags); 
# 2845
extern cudaError_t cudaConfigureCall(dim3 gridDim, dim3 blockDim, ::size_t sharedMem = 0, cudaStream_t stream = 0); 
# 2874
extern cudaError_t cudaSetupArgument(const void * arg, ::size_t size, ::size_t offset); 
# 2912
extern cudaError_t cudaLaunch(const void * func); 
# 3030
extern cudaError_t cudaMallocManaged(void ** devPtr, ::size_t size, unsigned flags = 1); 
# 3056
extern cudaError_t cudaMalloc(void ** devPtr, ::size_t size); 
# 3085
extern cudaError_t cudaMallocHost(void ** ptr, ::size_t size); 
# 3124
extern cudaError_t cudaMallocPitch(void ** devPtr, ::size_t * pitch, ::size_t width, ::size_t height); 
# 3166
extern cudaError_t cudaMallocArray(cudaArray_t * array, const cudaChannelFormatDesc * desc, ::size_t width, ::size_t height = 0, unsigned flags = 0); 
# 3193
extern cudaError_t cudaFree(void * devPtr); 
# 3213
extern cudaError_t cudaFreeHost(void * ptr); 
# 3235
extern cudaError_t cudaFreeArray(cudaArray_t array); 
# 3257
extern cudaError_t cudaFreeMipmappedArray(cudaMipmappedArray_t mipmappedArray); 
# 3316
extern cudaError_t cudaHostAlloc(void ** pHost, ::size_t size, unsigned flags); 
# 3393
extern cudaError_t cudaHostRegister(void * ptr, ::size_t size, unsigned flags); 
# 3412
extern cudaError_t cudaHostUnregister(void * ptr); 
# 3454
extern cudaError_t cudaHostGetDevicePointer(void ** pDevice, void * pHost, unsigned flags); 
# 3473
extern cudaError_t cudaHostGetFlags(unsigned * pFlags, void * pHost); 
# 3508
extern cudaError_t cudaMalloc3D(cudaPitchedPtr * pitchedDevPtr, cudaExtent extent); 
# 3643
extern cudaError_t cudaMalloc3DArray(cudaArray_t * array, const cudaChannelFormatDesc * desc, cudaExtent extent, unsigned flags = 0); 
# 3764
extern cudaError_t cudaMallocMipmappedArray(cudaMipmappedArray_t * mipmappedArray, const cudaChannelFormatDesc * desc, cudaExtent extent, unsigned numLevels, unsigned flags = 0); 
# 3790
extern cudaError_t cudaGetMipmappedArrayLevel(cudaArray_t * levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned level); 
# 3890
extern cudaError_t cudaMemcpy3D(const cudaMemcpy3DParms * p); 
# 3918
extern cudaError_t cudaMemcpy3DPeer(const cudaMemcpy3DPeerParms * p); 
# 4029
extern cudaError_t cudaMemcpy3DAsync(const cudaMemcpy3DParms * p, cudaStream_t stream = 0); 
# 4052
extern cudaError_t cudaMemcpy3DPeerAsync(const cudaMemcpy3DPeerParms * p, cudaStream_t stream = 0); 
# 4071
extern cudaError_t cudaMemGetInfo(::size_t * free, ::size_t * total); 
# 4092
extern cudaError_t cudaArrayGetInfo(cudaChannelFormatDesc * desc, cudaExtent * extent, unsigned * flags, cudaArray_t array); 
# 4130
extern cudaError_t cudaMemcpy(void * dst, const void * src, ::size_t count, cudaMemcpyKind kind); 
# 4162
extern cudaError_t cudaMemcpyPeer(void * dst, int dstDevice, const void * src, int srcDevice, ::size_t count); 
# 4200
extern cudaError_t cudaMemcpyToArray(cudaArray_t dst, ::size_t wOffset, ::size_t hOffset, const void * src, ::size_t count, cudaMemcpyKind kind); 
# 4237
extern cudaError_t cudaMemcpyFromArray(void * dst, cudaArray_const_t src, ::size_t wOffset, ::size_t hOffset, ::size_t count, cudaMemcpyKind kind); 
# 4275
extern cudaError_t cudaMemcpyArrayToArray(cudaArray_t dst, ::size_t wOffsetDst, ::size_t hOffsetDst, cudaArray_const_t src, ::size_t wOffsetSrc, ::size_t hOffsetSrc, ::size_t count, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice); 
# 4320
extern cudaError_t cudaMemcpy2D(void * dst, ::size_t dpitch, const void * src, ::size_t spitch, ::size_t width, ::size_t height, cudaMemcpyKind kind); 
# 4366
extern cudaError_t cudaMemcpy2DToArray(cudaArray_t dst, ::size_t wOffset, ::size_t hOffset, const void * src, ::size_t spitch, ::size_t width, ::size_t height, cudaMemcpyKind kind); 
# 4412
extern cudaError_t cudaMemcpy2DFromArray(void * dst, ::size_t dpitch, cudaArray_const_t src, ::size_t wOffset, ::size_t hOffset, ::size_t width, ::size_t height, cudaMemcpyKind kind); 
# 4455
extern cudaError_t cudaMemcpy2DArrayToArray(cudaArray_t dst, ::size_t wOffsetDst, ::size_t hOffsetDst, cudaArray_const_t src, ::size_t wOffsetSrc, ::size_t hOffsetSrc, ::size_t width, ::size_t height, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice); 
# 4493
extern cudaError_t cudaMemcpyToSymbol(const void * symbol, const void * src, ::size_t count, ::size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyHostToDevice); 
# 4531
extern cudaError_t cudaMemcpyFromSymbol(void * dst, const void * symbol, ::size_t count, ::size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyDeviceToHost); 
# 4582
extern cudaError_t cudaMemcpyAsync(void * dst, const void * src, ::size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 4614
extern cudaError_t cudaMemcpyPeerAsync(void * dst, int dstDevice, const void * src, int srcDevice, ::size_t count, cudaStream_t stream = 0); 
# 4660
extern cudaError_t cudaMemcpyToArrayAsync(cudaArray_t dst, ::size_t wOffset, ::size_t hOffset, const void * src, ::size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 4705
extern cudaError_t cudaMemcpyFromArrayAsync(void * dst, cudaArray_const_t src, ::size_t wOffset, ::size_t hOffset, ::size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 4765
extern cudaError_t cudaMemcpy2DAsync(void * dst, ::size_t dpitch, const void * src, ::size_t spitch, ::size_t width, ::size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 4820
extern cudaError_t cudaMemcpy2DToArrayAsync(cudaArray_t dst, ::size_t wOffset, ::size_t hOffset, const void * src, ::size_t spitch, ::size_t width, ::size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 4874
extern cudaError_t cudaMemcpy2DFromArrayAsync(void * dst, ::size_t dpitch, cudaArray_const_t src, ::size_t wOffset, ::size_t hOffset, ::size_t width, ::size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 4920
extern cudaError_t cudaMemcpyToSymbolAsync(const void * symbol, const void * src, ::size_t count, ::size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 4966
extern cudaError_t cudaMemcpyFromSymbolAsync(void * dst, const void * symbol, ::size_t count, ::size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0); 
# 4992
extern cudaError_t cudaMemset(void * devPtr, int value, ::size_t count); 
# 5022
extern cudaError_t cudaMemset2D(void * devPtr, ::size_t pitch, int value, ::size_t width, ::size_t height); 
# 5065
extern cudaError_t cudaMemset3D(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent); 
# 5097
extern cudaError_t cudaMemsetAsync(void * devPtr, int value, ::size_t count, cudaStream_t stream = 0); 
# 5134
extern cudaError_t cudaMemset2DAsync(void * devPtr, ::size_t pitch, int value, ::size_t width, ::size_t height, cudaStream_t stream = 0); 
# 5184
extern cudaError_t cudaMemset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream = 0); 
# 5207
extern cudaError_t cudaGetSymbolAddress(void ** devPtr, const void * symbol); 
# 5229
extern cudaError_t cudaGetSymbolSize(::size_t * size, const void * symbol); 
# 5296
extern cudaError_t cudaMemPrefetchAsync(const void * devPtr, ::size_t count, int dstDevice, cudaStream_t stream = 0); 
# 5382
extern cudaError_t cudaMemAdvise(const void * devPtr, ::size_t count, cudaMemoryAdvise advice, int device); 
# 5438
extern cudaError_t cudaMemRangeGetAttribute(void * data, ::size_t dataSize, cudaMemRangeAttribute attribute, const void * devPtr, ::size_t count); 
# 5474
extern cudaError_t cudaMemRangeGetAttributes(void ** data, ::size_t * dataSizes, cudaMemRangeAttribute * attributes, ::size_t numAttributes, const void * devPtr, ::size_t count); 
# 5627
extern cudaError_t cudaPointerGetAttributes(cudaPointerAttributes * attributes, const void * ptr); 
# 5665
extern cudaError_t cudaDeviceCanAccessPeer(int * canAccessPeer, int device, int peerDevice); 
# 5704
extern cudaError_t cudaDeviceEnablePeerAccess(int peerDevice, unsigned flags); 
# 5723
extern cudaError_t cudaDeviceDisablePeerAccess(int peerDevice); 
# 5783
extern cudaError_t cudaGraphicsUnregisterResource(cudaGraphicsResource_t resource); 
# 5815
extern cudaError_t cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t resource, unsigned flags); 
# 5851
extern cudaError_t cudaGraphicsMapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream = 0); 
# 5883
extern cudaError_t cudaGraphicsUnmapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream = 0); 
# 5912
extern cudaError_t cudaGraphicsResourceGetMappedPointer(void ** devPtr, ::size_t * size, cudaGraphicsResource_t resource); 
# 5946
extern cudaError_t cudaGraphicsSubResourceGetMappedArray(cudaArray_t * array, cudaGraphicsResource_t resource, unsigned arrayIndex, unsigned mipLevel); 
# 5971
extern cudaError_t cudaGraphicsResourceGetMappedMipmappedArray(cudaMipmappedArray_t * mipmappedArray, cudaGraphicsResource_t resource); 
# 6011
extern cudaError_t cudaGetChannelDesc(cudaChannelFormatDesc * desc, cudaArray_const_t array); 
# 6046
extern cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, cudaChannelFormatKind f); 
# 6093
extern cudaError_t cudaBindTexture(::size_t * offset, const textureReference * texref, const void * devPtr, const cudaChannelFormatDesc * desc, ::size_t size = ((2147483647) * 2U) + 1U); 
# 6144
extern cudaError_t cudaBindTexture2D(::size_t * offset, const textureReference * texref, const void * devPtr, const cudaChannelFormatDesc * desc, ::size_t width, ::size_t height, ::size_t pitch); 
# 6172
extern cudaError_t cudaBindTextureToArray(const textureReference * texref, cudaArray_const_t array, const cudaChannelFormatDesc * desc); 
# 6200
extern cudaError_t cudaBindTextureToMipmappedArray(const textureReference * texref, cudaMipmappedArray_const_t mipmappedArray, const cudaChannelFormatDesc * desc); 
# 6221
extern cudaError_t cudaUnbindTexture(const textureReference * texref); 
# 6246
extern cudaError_t cudaGetTextureAlignmentOffset(::size_t * offset, const textureReference * texref); 
# 6271
extern cudaError_t cudaGetTextureReference(const textureReference ** texref, const void * symbol); 
# 6311
extern cudaError_t cudaBindSurfaceToArray(const surfaceReference * surfref, cudaArray_const_t array, const cudaChannelFormatDesc * desc); 
# 6330
extern cudaError_t cudaGetSurfaceReference(const surfaceReference ** surfref, const void * symbol); 
# 6556
extern cudaError_t cudaCreateTextureObject(cudaTextureObject_t * pTexObject, const cudaResourceDesc * pResDesc, const cudaTextureDesc * pTexDesc, const cudaResourceViewDesc * pResViewDesc); 
# 6571
extern cudaError_t cudaDestroyTextureObject(cudaTextureObject_t texObject); 
# 6587
extern cudaError_t cudaGetTextureObjectResourceDesc(cudaResourceDesc * pResDesc, cudaTextureObject_t texObject); 
# 6603
extern cudaError_t cudaGetTextureObjectTextureDesc(cudaTextureDesc * pTexDesc, cudaTextureObject_t texObject); 
# 6620
extern cudaError_t cudaGetTextureObjectResourceViewDesc(cudaResourceViewDesc * pResViewDesc, cudaTextureObject_t texObject); 
# 6659
extern cudaError_t cudaCreateSurfaceObject(cudaSurfaceObject_t * pSurfObject, const cudaResourceDesc * pResDesc); 
# 6674
extern cudaError_t cudaDestroySurfaceObject(cudaSurfaceObject_t surfObject); 
# 6689
extern cudaError_t cudaGetSurfaceObjectResourceDesc(cudaResourceDesc * pResDesc, cudaSurfaceObject_t surfObject); 
# 6716
extern cudaError_t cudaDriverGetVersion(int * driverVersion); 
# 6733
extern cudaError_t cudaRuntimeGetVersion(int * runtimeVersion); 
# 6738
extern cudaError_t cudaGetExportTable(const void ** ppExportTable, const cudaUUID_t * pExportTableId); 
# 6964
}
# 107 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/channel_descriptor.h"
template< class T> inline cudaChannelFormatDesc cudaCreateChannelDesc() 
# 108
{ 
# 109
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone); 
# 110
} 
# 112
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf() 
# 113
{ 
# 114
int e = (((int)sizeof(unsigned short)) * 8); 
# 116
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 117
} 
# 119
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf1() 
# 120
{ 
# 121
int e = (((int)sizeof(unsigned short)) * 8); 
# 123
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 124
} 
# 126
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf2() 
# 127
{ 
# 128
int e = (((int)sizeof(unsigned short)) * 8); 
# 130
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
# 131
} 
# 133
static inline cudaChannelFormatDesc cudaCreateChannelDescHalf4() 
# 134
{ 
# 135
int e = (((int)sizeof(unsigned short)) * 8); 
# 137
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
# 138
} 
# 140
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char> () 
# 141
{ 
# 142
int e = (((int)sizeof(char)) * 8); 
# 147
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 149
} 
# 151
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> () 
# 152
{ 
# 153
int e = (((int)sizeof(signed char)) * 8); 
# 155
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 156
} 
# 158
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> () 
# 159
{ 
# 160
int e = (((int)sizeof(unsigned char)) * 8); 
# 162
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 163
} 
# 165
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> () 
# 166
{ 
# 167
int e = (((int)sizeof(signed char)) * 8); 
# 169
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 170
} 
# 172
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> () 
# 173
{ 
# 174
int e = (((int)sizeof(unsigned char)) * 8); 
# 176
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 177
} 
# 179
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> () 
# 180
{ 
# 181
int e = (((int)sizeof(signed char)) * 8); 
# 183
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 184
} 
# 186
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> () 
# 187
{ 
# 188
int e = (((int)sizeof(unsigned char)) * 8); 
# 190
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 191
} 
# 193
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> () 
# 194
{ 
# 195
int e = (((int)sizeof(signed char)) * 8); 
# 197
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 198
} 
# 200
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> () 
# 201
{ 
# 202
int e = (((int)sizeof(unsigned char)) * 8); 
# 204
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 205
} 
# 207
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short> () 
# 208
{ 
# 209
int e = (((int)sizeof(short)) * 8); 
# 211
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 212
} 
# 214
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> () 
# 215
{ 
# 216
int e = (((int)sizeof(unsigned short)) * 8); 
# 218
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 219
} 
# 221
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> () 
# 222
{ 
# 223
int e = (((int)sizeof(short)) * 8); 
# 225
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 226
} 
# 228
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> () 
# 229
{ 
# 230
int e = (((int)sizeof(unsigned short)) * 8); 
# 232
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 233
} 
# 235
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> () 
# 236
{ 
# 237
int e = (((int)sizeof(short)) * 8); 
# 239
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 240
} 
# 242
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> () 
# 243
{ 
# 244
int e = (((int)sizeof(unsigned short)) * 8); 
# 246
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 247
} 
# 249
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> () 
# 250
{ 
# 251
int e = (((int)sizeof(short)) * 8); 
# 253
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 254
} 
# 256
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> () 
# 257
{ 
# 258
int e = (((int)sizeof(unsigned short)) * 8); 
# 260
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 261
} 
# 263
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int> () 
# 264
{ 
# 265
int e = (((int)sizeof(int)) * 8); 
# 267
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 268
} 
# 270
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> () 
# 271
{ 
# 272
int e = (((int)sizeof(unsigned)) * 8); 
# 274
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 275
} 
# 277
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> () 
# 278
{ 
# 279
int e = (((int)sizeof(int)) * 8); 
# 281
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
# 282
} 
# 284
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> () 
# 285
{ 
# 286
int e = (((int)sizeof(unsigned)) * 8); 
# 288
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
# 289
} 
# 291
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> () 
# 292
{ 
# 293
int e = (((int)sizeof(int)) * 8); 
# 295
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
# 296
} 
# 298
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> () 
# 299
{ 
# 300
int e = (((int)sizeof(unsigned)) * 8); 
# 302
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
# 303
} 
# 305
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> () 
# 306
{ 
# 307
int e = (((int)sizeof(int)) * 8); 
# 309
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
# 310
} 
# 312
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> () 
# 313
{ 
# 314
int e = (((int)sizeof(unsigned)) * 8); 
# 316
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
# 317
} 
# 379
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float> () 
# 380
{ 
# 381
int e = (((int)sizeof(float)) * 8); 
# 383
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 384
} 
# 386
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> () 
# 387
{ 
# 388
int e = (((int)sizeof(float)) * 8); 
# 390
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
# 391
} 
# 393
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> () 
# 394
{ 
# 395
int e = (((int)sizeof(float)) * 8); 
# 397
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
# 398
} 
# 400
template<> inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> () 
# 401
{ 
# 402
int e = (((int)sizeof(float)) * 8); 
# 404
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
# 405
} 
# 79 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/driver_functions.h"
static inline cudaPitchedPtr make_cudaPitchedPtr(void *d, ::size_t p, ::size_t xsz, ::size_t ysz) 
# 80
{ 
# 81
cudaPitchedPtr s; 
# 83
(s.ptr) = d; 
# 84
(s.pitch) = p; 
# 85
(s.xsize) = xsz; 
# 86
(s.ysize) = ysz; 
# 88
return s; 
# 89
} 
# 106
static inline cudaPos make_cudaPos(::size_t x, ::size_t y, ::size_t z) 
# 107
{ 
# 108
cudaPos p; 
# 110
(p.x) = x; 
# 111
(p.y) = y; 
# 112
(p.z) = z; 
# 114
return p; 
# 115
} 
# 132
static inline cudaExtent make_cudaExtent(::size_t w, ::size_t h, ::size_t d) 
# 133
{ 
# 134
cudaExtent e; 
# 136
(e.width) = w; 
# 137
(e.height) = h; 
# 138
(e.depth) = d; 
# 140
return e; 
# 141
} 
# 75 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/vector_functions.hpp"
static inline char1 make_char1(signed char x) 
# 76
{ 
# 77
char1 t; (t.x) = x; return t; 
# 78
} 
# 80
static inline uchar1 make_uchar1(unsigned char x) 
# 81
{ 
# 82
uchar1 t; (t.x) = x; return t; 
# 83
} 
# 85
static inline char2 make_char2(signed char x, signed char y) 
# 86
{ 
# 87
char2 t; (t.x) = x; (t.y) = y; return t; 
# 88
} 
# 90
static inline uchar2 make_uchar2(unsigned char x, unsigned char y) 
# 91
{ 
# 92
uchar2 t; (t.x) = x; (t.y) = y; return t; 
# 93
} 
# 95
static inline char3 make_char3(signed char x, signed char y, signed char z) 
# 96
{ 
# 97
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 98
} 
# 100
static inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z) 
# 101
{ 
# 102
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 103
} 
# 105
static inline char4 make_char4(signed char x, signed char y, signed char z, signed char w) 
# 106
{ 
# 107
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 108
} 
# 110
static inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w) 
# 111
{ 
# 112
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 113
} 
# 115
static inline short1 make_short1(short x) 
# 116
{ 
# 117
short1 t; (t.x) = x; return t; 
# 118
} 
# 120
static inline ushort1 make_ushort1(unsigned short x) 
# 121
{ 
# 122
ushort1 t; (t.x) = x; return t; 
# 123
} 
# 125
static inline short2 make_short2(short x, short y) 
# 126
{ 
# 127
short2 t; (t.x) = x; (t.y) = y; return t; 
# 128
} 
# 130
static inline ushort2 make_ushort2(unsigned short x, unsigned short y) 
# 131
{ 
# 132
ushort2 t; (t.x) = x; (t.y) = y; return t; 
# 133
} 
# 135
static inline short3 make_short3(short x, short y, short z) 
# 136
{ 
# 137
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 138
} 
# 140
static inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z) 
# 141
{ 
# 142
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 143
} 
# 145
static inline short4 make_short4(short x, short y, short z, short w) 
# 146
{ 
# 147
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 148
} 
# 150
static inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w) 
# 151
{ 
# 152
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 153
} 
# 155
static inline int1 make_int1(int x) 
# 156
{ 
# 157
int1 t; (t.x) = x; return t; 
# 158
} 
# 160
static inline uint1 make_uint1(unsigned x) 
# 161
{ 
# 162
uint1 t; (t.x) = x; return t; 
# 163
} 
# 165
static inline int2 make_int2(int x, int y) 
# 166
{ 
# 167
int2 t; (t.x) = x; (t.y) = y; return t; 
# 168
} 
# 170
static inline uint2 make_uint2(unsigned x, unsigned y) 
# 171
{ 
# 172
uint2 t; (t.x) = x; (t.y) = y; return t; 
# 173
} 
# 175
static inline int3 make_int3(int x, int y, int z) 
# 176
{ 
# 177
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 178
} 
# 180
static inline uint3 make_uint3(unsigned x, unsigned y, unsigned z) 
# 181
{ 
# 182
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 183
} 
# 185
static inline int4 make_int4(int x, int y, int z, int w) 
# 186
{ 
# 187
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 188
} 
# 190
static inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w) 
# 191
{ 
# 192
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 193
} 
# 195
static inline long1 make_long1(long x) 
# 196
{ 
# 197
long1 t; (t.x) = x; return t; 
# 198
} 
# 200
static inline ulong1 make_ulong1(unsigned long x) 
# 201
{ 
# 202
ulong1 t; (t.x) = x; return t; 
# 203
} 
# 205
static inline long2 make_long2(long x, long y) 
# 206
{ 
# 207
long2 t; (t.x) = x; (t.y) = y; return t; 
# 208
} 
# 210
static inline ulong2 make_ulong2(unsigned long x, unsigned long y) 
# 211
{ 
# 212
ulong2 t; (t.x) = x; (t.y) = y; return t; 
# 213
} 
# 215
static inline long3 make_long3(long x, long y, long z) 
# 216
{ 
# 217
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 218
} 
# 220
static inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z) 
# 221
{ 
# 222
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 223
} 
# 225
static inline long4 make_long4(long x, long y, long z, long w) 
# 226
{ 
# 227
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 228
} 
# 230
static inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w) 
# 231
{ 
# 232
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 233
} 
# 235
static inline float1 make_float1(float x) 
# 236
{ 
# 237
float1 t; (t.x) = x; return t; 
# 238
} 
# 240
static inline float2 make_float2(float x, float y) 
# 241
{ 
# 242
float2 t; (t.x) = x; (t.y) = y; return t; 
# 243
} 
# 245
static inline float3 make_float3(float x, float y, float z) 
# 246
{ 
# 247
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 248
} 
# 250
static inline float4 make_float4(float x, float y, float z, float w) 
# 251
{ 
# 252
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 253
} 
# 255
static inline longlong1 make_longlong1(long long x) 
# 256
{ 
# 257
longlong1 t; (t.x) = x; return t; 
# 258
} 
# 260
static inline ulonglong1 make_ulonglong1(unsigned long long x) 
# 261
{ 
# 262
ulonglong1 t; (t.x) = x; return t; 
# 263
} 
# 265
static inline longlong2 make_longlong2(long long x, long long y) 
# 266
{ 
# 267
longlong2 t; (t.x) = x; (t.y) = y; return t; 
# 268
} 
# 270
static inline ulonglong2 make_ulonglong2(unsigned long long x, unsigned long long y) 
# 271
{ 
# 272
ulonglong2 t; (t.x) = x; (t.y) = y; return t; 
# 273
} 
# 275
static inline longlong3 make_longlong3(long long x, long long y, long long z) 
# 276
{ 
# 277
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 278
} 
# 280
static inline ulonglong3 make_ulonglong3(unsigned long long x, unsigned long long y, unsigned long long z) 
# 281
{ 
# 282
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 283
} 
# 285
static inline longlong4 make_longlong4(long long x, long long y, long long z, long long w) 
# 286
{ 
# 287
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 288
} 
# 290
static inline ulonglong4 make_ulonglong4(unsigned long long x, unsigned long long y, unsigned long long z, unsigned long long w) 
# 291
{ 
# 292
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 293
} 
# 295
static inline double1 make_double1(double x) 
# 296
{ 
# 297
double1 t; (t.x) = x; return t; 
# 298
} 
# 300
static inline double2 make_double2(double x, double y) 
# 301
{ 
# 302
double2 t; (t.x) = x; (t.y) = y; return t; 
# 303
} 
# 305
static inline double3 make_double3(double x, double y, double z) 
# 306
{ 
# 307
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
# 308
} 
# 310
static inline double4 make_double4(double x, double y, double z, double w) 
# 311
{ 
# 312
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
# 313
} 
# 27 "/usr/include/string.h" 3
extern "C" {
# 42
extern void *memcpy(void *__restrict__ __dest, const void *__restrict__ __src, ::size_t __n) throw()
# 43
 __attribute((__nonnull__(1, 2))); 
# 46
extern void *memmove(void * __dest, const void * __src, ::size_t __n) throw()
# 47
 __attribute((__nonnull__(1, 2))); 
# 54
extern void *memccpy(void *__restrict__ __dest, const void *__restrict__ __src, int __c, ::size_t __n) throw()
# 56
 __attribute((__nonnull__(1, 2))); 
# 62
extern void *memset(void * __s, int __c, ::size_t __n) throw() __attribute((__nonnull__(1))); 
# 65
extern int memcmp(const void * __s1, const void * __s2, ::size_t __n) throw()
# 66
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 70
extern "C++" {
# 72
extern void *memchr(void * __s, int __c, ::size_t __n) throw() __asm__("memchr")
# 73
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 74
extern const void *memchr(const void * __s, int __c, ::size_t __n) throw() __asm__("memchr")
# 75
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 90
}
# 101
extern "C++" void *rawmemchr(void * __s, int __c) throw() __asm__("rawmemchr")
# 102
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 103
extern "C++" const void *rawmemchr(const void * __s, int __c) throw() __asm__("rawmemchr")
# 104
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 112
extern "C++" void *memrchr(void * __s, int __c, ::size_t __n) throw() __asm__("memrchr")
# 113
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 114
extern "C++" const void *memrchr(const void * __s, int __c, ::size_t __n) throw() __asm__("memrchr")
# 115
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 125
extern char *strcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 126
 __attribute((__nonnull__(1, 2))); 
# 128
extern char *strncpy(char *__restrict__ __dest, const char *__restrict__ __src, ::size_t __n) throw()
# 130
 __attribute((__nonnull__(1, 2))); 
# 133
extern char *strcat(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 134
 __attribute((__nonnull__(1, 2))); 
# 136
extern char *strncat(char *__restrict__ __dest, const char *__restrict__ __src, ::size_t __n) throw()
# 137
 __attribute((__nonnull__(1, 2))); 
# 140
extern int strcmp(const char * __s1, const char * __s2) throw()
# 141
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 143
extern int strncmp(const char * __s1, const char * __s2, ::size_t __n) throw()
# 144
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 147
extern int strcoll(const char * __s1, const char * __s2) throw()
# 148
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 150
extern ::size_t strxfrm(char *__restrict__ __dest, const char *__restrict__ __src, ::size_t __n) throw()
# 152
 __attribute((__nonnull__(2))); 
# 39 "/usr/include/xlocale.h" 3
typedef 
# 27
struct __locale_struct { 
# 30
struct __locale_data *__locales[13]; 
# 33
const unsigned short *__ctype_b; 
# 34
const int *__ctype_tolower; 
# 35
const int *__ctype_toupper; 
# 38
const char *__names[13]; 
# 39
} *__locale_t; 
# 42
typedef __locale_t locale_t; 
# 162 "/usr/include/string.h" 3
extern int strcoll_l(const char * __s1, const char * __s2, __locale_t __l) throw()
# 163
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 3))); 
# 165
extern ::size_t strxfrm_l(char * __dest, const char * __src, ::size_t __n, __locale_t __l) throw()
# 166
 __attribute((__nonnull__(2, 4))); 
# 172
extern char *strdup(const char * __s) throw()
# 173
 __attribute((__malloc__)) __attribute((__nonnull__(1))); 
# 180
extern char *strndup(const char * __string, ::size_t __n) throw()
# 181
 __attribute((__malloc__)) __attribute((__nonnull__(1))); 
# 210
extern "C++" {
# 212
extern char *strchr(char * __s, int __c) throw() __asm__("strchr")
# 213
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 214
extern const char *strchr(const char * __s, int __c) throw() __asm__("strchr")
# 215
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 230
}
# 237
extern "C++" {
# 239
extern char *strrchr(char * __s, int __c) throw() __asm__("strrchr")
# 240
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 241
extern const char *strrchr(const char * __s, int __c) throw() __asm__("strrchr")
# 242
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 257
}
# 268
extern "C++" char *strchrnul(char * __s, int __c) throw() __asm__("strchrnul")
# 269
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 270
extern "C++" const char *strchrnul(const char * __s, int __c) throw() __asm__("strchrnul")
# 271
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 281
extern ::size_t strcspn(const char * __s, const char * __reject) throw()
# 282
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 285
extern ::size_t strspn(const char * __s, const char * __accept) throw()
# 286
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 289
extern "C++" {
# 291
extern char *strpbrk(char * __s, const char * __accept) throw() __asm__("strpbrk")
# 292
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 293
extern const char *strpbrk(const char * __s, const char * __accept) throw() __asm__("strpbrk")
# 294
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 309
}
# 316
extern "C++" {
# 318
extern char *strstr(char * __haystack, const char * __needle) throw() __asm__("strstr")
# 319
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 320
extern const char *strstr(const char * __haystack, const char * __needle) throw() __asm__("strstr")
# 321
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 336
}
# 344
extern char *strtok(char *__restrict__ __s, const char *__restrict__ __delim) throw()
# 345
 __attribute((__nonnull__(2))); 
# 350
extern char *__strtok_r(char *__restrict__ __s, const char *__restrict__ __delim, char **__restrict__ __save_ptr) throw()
# 353
 __attribute((__nonnull__(2, 3))); 
# 355
extern char *strtok_r(char *__restrict__ __s, const char *__restrict__ __delim, char **__restrict__ __save_ptr) throw()
# 357
 __attribute((__nonnull__(2, 3))); 
# 363
extern "C++" char *strcasestr(char * __haystack, const char * __needle) throw() __asm__("strcasestr")
# 364
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 365
extern "C++" const char *strcasestr(const char * __haystack, const char * __needle) throw() __asm__("strcasestr")
# 367
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 378
extern void *memmem(const void * __haystack, ::size_t __haystacklen, const void * __needle, ::size_t __needlelen) throw()
# 380
 __attribute((__pure__)) __attribute((__nonnull__(1, 3))); 
# 384
extern void *__mempcpy(void *__restrict__ __dest, const void *__restrict__ __src, ::size_t __n) throw()
# 386
 __attribute((__nonnull__(1, 2))); 
# 387
extern void *mempcpy(void *__restrict__ __dest, const void *__restrict__ __src, ::size_t __n) throw()
# 389
 __attribute((__nonnull__(1, 2))); 
# 395
extern ::size_t strlen(const char * __s) throw()
# 396
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 402
extern ::size_t strnlen(const char * __string, ::size_t __maxlen) throw()
# 403
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 409
extern char *strerror(int __errnum) throw(); 
# 434
extern char *strerror_r(int __errnum, char * __buf, ::size_t __buflen) throw()
# 435
 __attribute((__nonnull__(2))); 
# 441
extern char *strerror_l(int __errnum, __locale_t __l) throw(); 
# 447
extern void __bzero(void * __s, ::size_t __n) throw() __attribute((__nonnull__(1))); 
# 451
extern void bcopy(const void * __src, void * __dest, ::size_t __n) throw()
# 452
 __attribute((__nonnull__(1, 2))); 
# 455
extern void bzero(void * __s, ::size_t __n) throw() __attribute((__nonnull__(1))); 
# 458
extern int bcmp(const void * __s1, const void * __s2, ::size_t __n) throw()
# 459
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 463
extern "C++" {
# 465
extern char *index(char * __s, int __c) throw() __asm__("index")
# 466
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 467
extern const char *index(const char * __s, int __c) throw() __asm__("index")
# 468
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 483
}
# 491
extern "C++" {
# 493
extern char *rindex(char * __s, int __c) throw() __asm__("rindex")
# 494
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 495
extern const char *rindex(const char * __s, int __c) throw() __asm__("rindex")
# 496
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 511
}
# 519
extern int ffs(int __i) throw() __attribute((const)); 
# 524
extern int ffsl(long __l) throw() __attribute((const)); 
# 526
__extension__ extern int ffsll(long long __ll) throw()
# 527
 __attribute((const)); 
# 532
extern int strcasecmp(const char * __s1, const char * __s2) throw()
# 533
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 536
extern int strncasecmp(const char * __s1, const char * __s2, ::size_t __n) throw()
# 537
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 543
extern int strcasecmp_l(const char * __s1, const char * __s2, __locale_t __loc) throw()
# 545
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 3))); 
# 547
extern int strncasecmp_l(const char * __s1, const char * __s2, ::size_t __n, __locale_t __loc) throw()
# 549
 __attribute((__pure__)) __attribute((__nonnull__(1, 2, 4))); 
# 555
extern char *strsep(char **__restrict__ __stringp, const char *__restrict__ __delim) throw()
# 557
 __attribute((__nonnull__(1, 2))); 
# 562
extern char *strsignal(int __sig) throw(); 
# 565
extern char *__stpcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 566
 __attribute((__nonnull__(1, 2))); 
# 567
extern char *stpcpy(char *__restrict__ __dest, const char *__restrict__ __src) throw()
# 568
 __attribute((__nonnull__(1, 2))); 
# 572
extern char *__stpncpy(char *__restrict__ __dest, const char *__restrict__ __src, ::size_t __n) throw()
# 574
 __attribute((__nonnull__(1, 2))); 
# 575
extern char *stpncpy(char *__restrict__ __dest, const char *__restrict__ __src, ::size_t __n) throw()
# 577
 __attribute((__nonnull__(1, 2))); 
# 582
extern int strverscmp(const char * __s1, const char * __s2) throw()
# 583
 __attribute((__pure__)) __attribute((__nonnull__(1, 2))); 
# 586
extern char *strfry(char * __string) throw() __attribute((__nonnull__(1))); 
# 589
extern void *memfrob(void * __s, ::size_t __n) throw() __attribute((__nonnull__(1))); 
# 597
extern "C++" char *basename(char * __filename) throw() __asm__("basename")
# 598
 __attribute((__nonnull__(1))); 
# 599
extern "C++" const char *basename(const char * __filename) throw() __asm__("basename")
# 600
 __attribute((__nonnull__(1))); 
# 642
}
# 29 "/usr/include/time.h" 3
extern "C" {
# 30 "/usr/include/bits/types.h" 3
typedef unsigned char __u_char; 
# 31
typedef unsigned short __u_short; 
# 32
typedef unsigned __u_int; 
# 33
typedef unsigned long __u_long; 
# 36
typedef signed char __int8_t; 
# 37
typedef unsigned char __uint8_t; 
# 38
typedef signed short __int16_t; 
# 39
typedef unsigned short __uint16_t; 
# 40
typedef signed int __int32_t; 
# 41
typedef unsigned __uint32_t; 
# 43
typedef signed long __int64_t; 
# 44
typedef unsigned long __uint64_t; 
# 52
typedef long __quad_t; 
# 53
typedef unsigned long __u_quad_t; 
# 133
typedef unsigned long __dev_t; 
# 134
typedef unsigned __uid_t; 
# 135
typedef unsigned __gid_t; 
# 136
typedef unsigned long __ino_t; 
# 137
typedef unsigned long __ino64_t; 
# 138
typedef unsigned __mode_t; 
# 139
typedef unsigned long __nlink_t; 
# 140
typedef long __off_t; 
# 141
typedef long __off64_t; 
# 142
typedef int __pid_t; 
# 143
typedef struct { int __val[2]; } __fsid_t; 
# 144
typedef long __clock_t; 
# 145
typedef unsigned long __rlim_t; 
# 146
typedef unsigned long __rlim64_t; 
# 147
typedef unsigned __id_t; 
# 148
typedef long __time_t; 
# 149
typedef unsigned __useconds_t; 
# 150
typedef long __suseconds_t; 
# 152
typedef int __daddr_t; 
# 153
typedef int __key_t; 
# 156
typedef int __clockid_t; 
# 159
typedef void *__timer_t; 
# 162
typedef long __blksize_t; 
# 167
typedef long __blkcnt_t; 
# 168
typedef long __blkcnt64_t; 
# 171
typedef unsigned long __fsblkcnt_t; 
# 172
typedef unsigned long __fsblkcnt64_t; 
# 175
typedef unsigned long __fsfilcnt_t; 
# 176
typedef unsigned long __fsfilcnt64_t; 
# 179
typedef long __fsword_t; 
# 181
typedef long __ssize_t; 
# 184
typedef long __syscall_slong_t; 
# 186
typedef unsigned long __syscall_ulong_t; 
# 190
typedef __off64_t __loff_t; 
# 191
typedef __quad_t *__qaddr_t; 
# 192
typedef char *__caddr_t; 
# 195
typedef long __intptr_t; 
# 198
typedef unsigned __socklen_t; 
# 30 "/usr/include/bits/time.h" 3
struct timeval { 
# 32
__time_t tv_sec; 
# 33
__suseconds_t tv_usec; 
# 34
}; 
# 25 "/usr/include/bits/timex.h" 3
struct timex { 
# 27
unsigned modes; 
# 28
__syscall_slong_t offset; 
# 29
__syscall_slong_t freq; 
# 30
__syscall_slong_t maxerror; 
# 31
__syscall_slong_t esterror; 
# 32
int status; 
# 33
__syscall_slong_t constant; 
# 34
__syscall_slong_t precision; 
# 35
__syscall_slong_t tolerance; 
# 36
timeval time; 
# 37
__syscall_slong_t tick; 
# 38
__syscall_slong_t ppsfreq; 
# 39
__syscall_slong_t jitter; 
# 40
int shift; 
# 41
__syscall_slong_t stabil; 
# 42
__syscall_slong_t jitcnt; 
# 43
__syscall_slong_t calcnt; 
# 44
__syscall_slong_t errcnt; 
# 45
__syscall_slong_t stbcnt; 
# 47
int tai; 
# 50
int:32; int:32; int:32; int:32; 
# 51
int:32; int:32; int:32; int:32; 
# 52
int:32; int:32; int:32; 
# 53
}; 
# 88 "/usr/include/bits/time.h" 3
extern "C" {
# 91
extern int clock_adjtime(__clockid_t __clock_id, timex * __utx) throw(); 
# 93
}
# 59 "/usr/include/time.h" 3
typedef __clock_t clock_t; 
# 75
typedef __time_t time_t; 
# 91
typedef __clockid_t clockid_t; 
# 103
typedef __timer_t timer_t; 
# 120
struct timespec { 
# 122
__time_t tv_sec; 
# 123
__syscall_slong_t tv_nsec; 
# 124
}; 
# 133
struct tm { 
# 135
int tm_sec; 
# 136
int tm_min; 
# 137
int tm_hour; 
# 138
int tm_mday; 
# 139
int tm_mon; 
# 140
int tm_year; 
# 141
int tm_wday; 
# 142
int tm_yday; 
# 143
int tm_isdst; 
# 146
long tm_gmtoff; 
# 147
const char *tm_zone; 
# 152
}; 
# 161
struct itimerspec { 
# 163
timespec it_interval; 
# 164
timespec it_value; 
# 165
}; 
# 168
struct sigevent; 
# 174
typedef __pid_t pid_t; 
# 189
extern clock_t clock() throw(); 
# 192
extern time_t time(time_t * __timer) throw(); 
# 195
extern double difftime(time_t __time1, time_t __time0) throw()
# 196
 __attribute((const)); 
# 199
extern time_t mktime(tm * __tp) throw(); 
# 205
extern ::size_t strftime(char *__restrict__ __s, ::size_t __maxsize, const char *__restrict__ __format, const tm *__restrict__ __tp) throw(); 
# 213
extern char *strptime(const char *__restrict__ __s, const char *__restrict__ __fmt, tm * __tp) throw(); 
# 223
extern ::size_t strftime_l(char *__restrict__ __s, ::size_t __maxsize, const char *__restrict__ __format, const tm *__restrict__ __tp, __locale_t __loc) throw(); 
# 230
extern char *strptime_l(const char *__restrict__ __s, const char *__restrict__ __fmt, tm * __tp, __locale_t __loc) throw(); 
# 239
extern tm *gmtime(const time_t * __timer) throw(); 
# 243
extern tm *localtime(const time_t * __timer) throw(); 
# 249
extern tm *gmtime_r(const time_t *__restrict__ __timer, tm *__restrict__ __tp) throw(); 
# 254
extern tm *localtime_r(const time_t *__restrict__ __timer, tm *__restrict__ __tp) throw(); 
# 261
extern char *asctime(const tm * __tp) throw(); 
# 264
extern char *ctime(const time_t * __timer) throw(); 
# 272
extern char *asctime_r(const tm *__restrict__ __tp, char *__restrict__ __buf) throw(); 
# 276
extern char *ctime_r(const time_t *__restrict__ __timer, char *__restrict__ __buf) throw(); 
# 282
extern char *__tzname[2]; 
# 283
extern int __daylight; 
# 284
extern long __timezone; 
# 289
extern char *tzname[2]; 
# 293
extern void tzset() throw(); 
# 297
extern int daylight; 
# 298
extern long timezone; 
# 304
extern int stime(const time_t * __when) throw(); 
# 319
extern time_t timegm(tm * __tp) throw(); 
# 322
extern time_t timelocal(tm * __tp) throw(); 
# 325
extern int dysize(int __year) throw() __attribute((const)); 
# 334
extern int nanosleep(const timespec * __requested_time, timespec * __remaining); 
# 339
extern int clock_getres(clockid_t __clock_id, timespec * __res) throw(); 
# 342
extern int clock_gettime(clockid_t __clock_id, timespec * __tp) throw(); 
# 345
extern int clock_settime(clockid_t __clock_id, const timespec * __tp) throw(); 
# 353
extern int clock_nanosleep(clockid_t __clock_id, int __flags, const timespec * __req, timespec * __rem); 
# 358
extern int clock_getcpuclockid(pid_t __pid, clockid_t * __clock_id) throw(); 
# 363
extern int timer_create(clockid_t __clock_id, sigevent *__restrict__ __evp, timer_t *__restrict__ __timerid) throw(); 
# 368
extern int timer_delete(timer_t __timerid) throw(); 
# 371
extern int timer_settime(timer_t __timerid, int __flags, const itimerspec *__restrict__ __value, itimerspec *__restrict__ __ovalue) throw(); 
# 376
extern int timer_gettime(timer_t __timerid, itimerspec * __value) throw(); 
# 380
extern int timer_getoverrun(timer_t __timerid) throw(); 
# 386
extern int timespec_get(timespec * __ts, int __base) throw()
# 387
 __attribute((__nonnull__(1))); 
# 403
extern int getdate_err; 
# 412
extern tm *getdate(const char * __string); 
# 426
extern int getdate_r(const char *__restrict__ __string, tm *__restrict__ __resbufp); 
# 430
}
# 68 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h"
extern "C" {
# 71
extern clock_t clock() throw(); 
# 72
extern void *memset(void *, int, ::size_t) throw(); 
# 73
extern void *memcpy(void *, const void *, ::size_t) throw(); 
# 75
}
# 93 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/math_functions.h"
extern "C" {
# 164
extern int abs(int) throw(); 
# 165
extern long labs(long) throw(); 
# 166
extern long long llabs(long long) throw(); 
# 216
extern double fabs(double x) throw(); 
# 257
extern float fabsf(float x) throw(); 
# 261
extern inline int min(int, int); 
# 263
extern inline unsigned umin(unsigned, unsigned); 
# 264
extern inline long long llmin(long long, long long); 
# 265
extern inline unsigned long long ullmin(unsigned long long, unsigned long long); 
# 286
extern float fminf(float x, float y) throw(); 
# 306
extern double fmin(double x, double y) throw(); 
# 313
extern inline int max(int, int); 
# 315
extern inline unsigned umax(unsigned, unsigned); 
# 316
extern inline long long llmax(long long, long long); 
# 317
extern inline unsigned long long ullmax(unsigned long long, unsigned long long); 
# 338
extern float fmaxf(float x, float y) throw(); 
# 358
extern double fmax(double, double) throw(); 
# 402
extern double sin(double x) throw(); 
# 435
extern double cos(double x) throw(); 
# 454
extern void sincos(double x, double * sptr, double * cptr) throw(); 
# 470
extern void sincosf(float x, float * sptr, float * cptr) throw(); 
# 515
extern double tan(double x) throw(); 
# 584
extern double sqrt(double x) throw(); 
# 656
extern double rsqrt(double x); 
# 726
extern float rsqrtf(float x); 
# 782
extern double log2(double x) throw(); 
# 807
extern double exp2(double x) throw(); 
# 832
extern float exp2f(float x) throw(); 
# 859
extern double exp10(double x) throw(); 
# 882
extern float exp10f(float x) throw(); 
# 928
extern double expm1(double x) throw(); 
# 973
extern float expm1f(float x) throw(); 
# 1028
extern float log2f(float x) throw(); 
# 1082
extern double log10(double x) throw(); 
# 1153
extern double log(double x) throw(); 
# 1247
extern double log1p(double x) throw(); 
# 1344
extern float log1pf(float x) throw(); 
# 1419
extern double floor(double x) throw(); 
# 1458
extern double exp(double x) throw(); 
# 1489
extern double cosh(double x) throw(); 
# 1519
extern double sinh(double x) throw(); 
# 1549
extern double tanh(double x) throw(); 
# 1584
extern double acosh(double x) throw(); 
# 1622
extern float acoshf(float x) throw(); 
# 1638
extern double asinh(double x) throw(); 
# 1654
extern float asinhf(float x) throw(); 
# 1708
extern double atanh(double x) throw(); 
# 1762
extern float atanhf(float x) throw(); 
# 1821
extern double ldexp(double x, int exp) throw(); 
# 1877
extern float ldexpf(float x, int exp) throw(); 
# 1929
extern double logb(double x) throw(); 
# 1984
extern float logbf(float x) throw(); 
# 2014
extern int ilogb(double x) throw(); 
# 2044
extern int ilogbf(float x) throw(); 
# 2120
extern double scalbn(double x, int n) throw(); 
# 2196
extern float scalbnf(float x, int n) throw(); 
# 2272
extern double scalbln(double x, long n) throw(); 
# 2348
extern float scalblnf(float x, long n) throw(); 
# 2426
extern double frexp(double x, int * nptr) throw(); 
# 2501
extern float frexpf(float x, int * nptr) throw(); 
# 2515
extern double round(double x) throw(); 
# 2532
extern float roundf(float x) throw(); 
# 2550
extern long lround(double x) throw(); 
# 2568
extern long lroundf(float x) throw(); 
# 2586
extern long long llround(double x) throw(); 
# 2604
extern long long llroundf(float x) throw(); 
# 2656
extern float rintf(float x) throw(); 
# 2672
extern long lrint(double x) throw(); 
# 2688
extern long lrintf(float x) throw(); 
# 2704
extern long long llrint(double x) throw(); 
# 2720
extern long long llrintf(float x) throw(); 
# 2773
extern double nearbyint(double x) throw(); 
# 2826
extern float nearbyintf(float x) throw(); 
# 2888
extern double ceil(double x) throw(); 
# 2900
extern double trunc(double x) throw(); 
# 2915
extern float truncf(float x) throw(); 
# 2941
extern double fdim(double x, double y) throw(); 
# 2967
extern float fdimf(float x, float y) throw(); 
# 3003
extern double atan2(double y, double x) throw(); 
# 3034
extern double atan(double x) throw(); 
# 3057
extern double acos(double x) throw(); 
# 3089
extern double asin(double x) throw(); 
# 3135
extern double hypot(double x, double y) throw(); 
# 3187
extern double rhypot(double x, double y) throw(); 
# 3233
extern float hypotf(float x, float y) throw(); 
# 3285
extern float rhypotf(float x, float y) throw(); 
# 3332
extern double norm3d(double a, double b, double c) throw(); 
# 3383
extern double rnorm3d(double a, double b, double c) throw(); 
# 3432
extern double norm4d(double a, double b, double c, double d) throw(); 
# 3488
extern double rnorm4d(double a, double b, double c, double d) throw(); 
# 3533
extern double norm(int dim, const double * t) throw(); 
# 3584
extern double rnorm(int dim, const double * t) throw(); 
# 3636
extern float rnormf(int dim, const float * a) throw(); 
# 3680
extern float normf(int dim, const float * a) throw(); 
# 3725
extern float norm3df(float a, float b, float c) throw(); 
# 3776
extern float rnorm3df(float a, float b, float c) throw(); 
# 3825
extern float norm4df(float a, float b, float c, float d) throw(); 
# 3881
extern float rnorm4df(float a, float b, float c, float d) throw(); 
# 3965
extern double cbrt(double x) throw(); 
# 4051
extern float cbrtf(float x) throw(); 
# 4106
extern double rcbrt(double x); 
# 4156
extern float rcbrtf(float x); 
# 4216
extern double sinpi(double x); 
# 4276
extern float sinpif(float x); 
# 4328
extern double cospi(double x); 
# 4380
extern float cospif(float x); 
# 4410
extern void sincospi(double x, double * sptr, double * cptr); 
# 4440
extern void sincospif(float x, float * sptr, float * cptr); 
# 4752
extern double pow(double x, double y) throw(); 
# 4808
extern double modf(double x, double * iptr) throw(); 
# 4867
extern double fmod(double x, double y) throw(); 
# 4953
extern double remainder(double x, double y) throw(); 
# 5043
extern float remainderf(float x, float y) throw(); 
# 5097
extern double remquo(double x, double y, int * quo) throw(); 
# 5151
extern float remquof(float x, float y, int * quo) throw(); 
# 5192
extern double j0(double x) throw(); 
# 5234
extern float j0f(float x) throw(); 
# 5295
extern double j1(double x) throw(); 
# 5356
extern float j1f(float x) throw(); 
# 5399
extern double jn(int n, double x) throw(); 
# 5442
extern float jnf(int n, float x) throw(); 
# 5494
extern double y0(double x) throw(); 
# 5546
extern float y0f(float x) throw(); 
# 5598
extern double y1(double x) throw(); 
# 5650
extern float y1f(float x) throw(); 
# 5703
extern double yn(int n, double x) throw(); 
# 5756
extern float ynf(int n, float x) throw(); 
# 5783
extern double cyl_bessel_i0(double x) throw(); 
# 5809
extern float cyl_bessel_i0f(float x) throw(); 
# 5836
extern double cyl_bessel_i1(double x) throw(); 
# 5862
extern float cyl_bessel_i1f(float x) throw(); 
# 5945
extern double erf(double x) throw(); 
# 6027
extern float erff(float x) throw(); 
# 6091
extern double erfinv(double y); 
# 6148
extern float erfinvf(float y); 
# 6187
extern double erfc(double x) throw(); 
# 6225
extern float erfcf(float x) throw(); 
# 6353
extern double lgamma(double x) throw(); 
# 6416
extern double erfcinv(double y); 
# 6472
extern float erfcinvf(float y); 
# 6530
extern double normcdfinv(double y); 
# 6588
extern float normcdfinvf(float y); 
# 6631
extern double normcdf(double y); 
# 6674
extern float normcdff(float y); 
# 6749
extern double erfcx(double x); 
# 6824
extern float erfcxf(float x); 
# 6958
extern float lgammaf(float x) throw(); 
# 7067
extern double tgamma(double x) throw(); 
# 7176
extern float tgammaf(float x) throw(); 
# 7189
extern double copysign(double x, double y) throw(); 
# 7202
extern float copysignf(float x, float y) throw(); 
# 7239
extern double nextafter(double x, double y) throw(); 
# 7276
extern float nextafterf(float x, float y) throw(); 
# 7292
extern double nan(const char * tagp) throw(); 
# 7308
extern float nanf(const char * tagp) throw(); 
# 7315
extern int __isinff(float) throw(); 
# 7316
extern int __isnanf(float) throw(); 
# 7326
extern int __finite(double) throw(); 
# 7327
extern int __finitef(float) throw(); 
# 7328
extern int __signbit(double) throw(); 
# 7329
extern int __isnan(double) throw(); 
# 7330
extern int __isinf(double) throw(); 
# 7333
extern int __signbitf(float) throw(); 
# 7492
extern double fma(double x, double y, double z) throw(); 
# 7650
extern float fmaf(float x, float y, float z) throw(); 
# 7661
extern int __signbitl(long double) throw(); 
# 7667
extern int __finitel(long double) throw(); 
# 7668
extern int __isinfl(long double) throw(); 
# 7669
extern int __isnanl(long double) throw(); 
# 7719
extern float acosf(float x) throw(); 
# 7759
extern float asinf(float x) throw(); 
# 7799
extern float atanf(float x) throw(); 
# 7832
extern float atan2f(float y, float x) throw(); 
# 7856
extern float cosf(float x) throw(); 
# 7898
extern float sinf(float x) throw(); 
# 7940
extern float tanf(float x) throw(); 
# 7964
extern float coshf(float x) throw(); 
# 8005
extern float sinhf(float x) throw(); 
# 8035
extern float tanhf(float x) throw(); 
# 8086
extern float logf(float x) throw(); 
# 8136
extern float expf(float x) throw(); 
# 8187
extern float log10f(float x) throw(); 
# 8242
extern float modff(float x, float * iptr) throw(); 
# 8550
extern float powf(float x, float y) throw(); 
# 8619
extern float sqrtf(float x) throw(); 
# 8678
extern float ceilf(float x) throw(); 
# 8750
extern float floorf(float x) throw(); 
# 8809
extern float fmodf(float x, float y) throw(); 
# 8823
}
# 29 "/usr/include/math.h" 3
extern "C" {
# 28 "/usr/include/bits/mathdef.h" 3
typedef float float_t; 
# 29
typedef double double_t; 
# 54 "/usr/include/bits/mathcalls.h" 3
extern double acos(double __x) throw(); extern double __acos(double __x) throw(); 
# 56
extern double asin(double __x) throw(); extern double __asin(double __x) throw(); 
# 58
extern double atan(double __x) throw(); extern double __atan(double __x) throw(); 
# 60
extern double atan2(double __y, double __x) throw(); extern double __atan2(double __y, double __x) throw(); 
# 63
extern double cos(double __x) throw(); extern double __cos(double __x) throw(); 
# 65
extern double sin(double __x) throw(); extern double __sin(double __x) throw(); 
# 67
extern double tan(double __x) throw(); extern double __tan(double __x) throw(); 
# 72
extern double cosh(double __x) throw(); extern double __cosh(double __x) throw(); 
# 74
extern double sinh(double __x) throw(); extern double __sinh(double __x) throw(); 
# 76
extern double tanh(double __x) throw(); extern double __tanh(double __x) throw(); 
# 81
extern void sincos(double __x, double * __sinx, double * __cosx) throw(); extern void __sincos(double __x, double * __sinx, double * __cosx) throw(); 
# 88
extern double acosh(double __x) throw(); extern double __acosh(double __x) throw(); 
# 90
extern double asinh(double __x) throw(); extern double __asinh(double __x) throw(); 
# 92
extern double atanh(double __x) throw(); extern double __atanh(double __x) throw(); 
# 100
extern double exp(double __x) throw(); extern double __exp(double __x) throw(); 
# 103
extern double frexp(double __x, int * __exponent) throw(); extern double __frexp(double __x, int * __exponent) throw(); 
# 106
extern double ldexp(double __x, int __exponent) throw(); extern double __ldexp(double __x, int __exponent) throw(); 
# 109
extern double log(double __x) throw(); extern double __log(double __x) throw(); 
# 112
extern double log10(double __x) throw(); extern double __log10(double __x) throw(); 
# 115
extern double modf(double __x, double * __iptr) throw(); extern double __modf(double __x, double * __iptr) throw()
# 116
 __attribute((__nonnull__(2))); 
# 121
extern double exp10(double __x) throw(); extern double __exp10(double __x) throw(); 
# 123
extern double pow10(double __x) throw(); extern double __pow10(double __x) throw(); 
# 129
extern double expm1(double __x) throw(); extern double __expm1(double __x) throw(); 
# 132
extern double log1p(double __x) throw(); extern double __log1p(double __x) throw(); 
# 135
extern double logb(double __x) throw(); extern double __logb(double __x) throw(); 
# 142
extern double exp2(double __x) throw(); extern double __exp2(double __x) throw(); 
# 145
extern double log2(double __x) throw(); extern double __log2(double __x) throw(); 
# 154
extern double pow(double __x, double __y) throw(); extern double __pow(double __x, double __y) throw(); 
# 157
extern double sqrt(double __x) throw(); extern double __sqrt(double __x) throw(); 
# 163
extern double hypot(double __x, double __y) throw(); extern double __hypot(double __x, double __y) throw(); 
# 170
extern double cbrt(double __x) throw(); extern double __cbrt(double __x) throw(); 
# 179
extern double ceil(double __x) throw() __attribute((const)); extern double __ceil(double __x) throw() __attribute((const)); 
# 182
extern double fabs(double __x) throw() __attribute((const)); extern double __fabs(double __x) throw() __attribute((const)); 
# 185
extern double floor(double __x) throw() __attribute((const)); extern double __floor(double __x) throw() __attribute((const)); 
# 188
extern double fmod(double __x, double __y) throw(); extern double __fmod(double __x, double __y) throw(); 
# 193
extern int __isinf(double __value) throw() __attribute((const)); 
# 196
extern int __finite(double __value) throw() __attribute((const)); 
# 202
extern inline int isinf(double __value) throw() __attribute((const)); 
# 205
extern int finite(double __value) throw() __attribute((const)); 
# 208
extern double drem(double __x, double __y) throw(); extern double __drem(double __x, double __y) throw(); 
# 212
extern double significand(double __x) throw(); extern double __significand(double __x) throw(); 
# 218
extern double copysign(double __x, double __y) throw() __attribute((const)); extern double __copysign(double __x, double __y) throw() __attribute((const)); 
# 225
extern double nan(const char * __tagb) throw() __attribute((const)); extern double __nan(const char * __tagb) throw() __attribute((const)); 
# 231
extern int __isnan(double __value) throw() __attribute((const)); 
# 235
extern inline int isnan(double __value) throw() __attribute((const)); 
# 238
extern double j0(double) throw(); extern double __j0(double) throw(); 
# 239
extern double j1(double) throw(); extern double __j1(double) throw(); 
# 240
extern double jn(int, double) throw(); extern double __jn(int, double) throw(); 
# 241
extern double y0(double) throw(); extern double __y0(double) throw(); 
# 242
extern double y1(double) throw(); extern double __y1(double) throw(); 
# 243
extern double yn(int, double) throw(); extern double __yn(int, double) throw(); 
# 250
extern double erf(double) throw(); extern double __erf(double) throw(); 
# 251
extern double erfc(double) throw(); extern double __erfc(double) throw(); 
# 252
extern double lgamma(double) throw(); extern double __lgamma(double) throw(); 
# 259
extern double tgamma(double) throw(); extern double __tgamma(double) throw(); 
# 265
extern double gamma(double) throw(); extern double __gamma(double) throw(); 
# 272
extern double lgamma_r(double, int * __signgamp) throw(); extern double __lgamma_r(double, int * __signgamp) throw(); 
# 280
extern double rint(double __x) throw(); extern double __rint(double __x) throw(); 
# 283
extern double nextafter(double __x, double __y) throw() __attribute((const)); extern double __nextafter(double __x, double __y) throw() __attribute((const)); 
# 285
extern double nexttoward(double __x, long double __y) throw() __attribute((const)); extern double __nexttoward(double __x, long double __y) throw() __attribute((const)); 
# 289
extern double remainder(double __x, double __y) throw(); extern double __remainder(double __x, double __y) throw(); 
# 293
extern double scalbn(double __x, int __n) throw(); extern double __scalbn(double __x, int __n) throw(); 
# 297
extern int ilogb(double __x) throw(); extern int __ilogb(double __x) throw(); 
# 302
extern double scalbln(double __x, long __n) throw(); extern double __scalbln(double __x, long __n) throw(); 
# 306
extern double nearbyint(double __x) throw(); extern double __nearbyint(double __x) throw(); 
# 310
extern double round(double __x) throw() __attribute((const)); extern double __round(double __x) throw() __attribute((const)); 
# 314
extern double trunc(double __x) throw() __attribute((const)); extern double __trunc(double __x) throw() __attribute((const)); 
# 319
extern double remquo(double __x, double __y, int * __quo) throw(); extern double __remquo(double __x, double __y, int * __quo) throw(); 
# 326
extern long lrint(double __x) throw(); extern long __lrint(double __x) throw(); 
# 327
extern long long llrint(double __x) throw(); extern long long __llrint(double __x) throw(); 
# 331
extern long lround(double __x) throw(); extern long __lround(double __x) throw(); 
# 332
extern long long llround(double __x) throw(); extern long long __llround(double __x) throw(); 
# 336
extern double fdim(double __x, double __y) throw(); extern double __fdim(double __x, double __y) throw(); 
# 339
extern double fmax(double __x, double __y) throw() __attribute((const)); extern double __fmax(double __x, double __y) throw() __attribute((const)); 
# 342
extern double fmin(double __x, double __y) throw() __attribute((const)); extern double __fmin(double __x, double __y) throw() __attribute((const)); 
# 346
extern int __fpclassify(double __value) throw()
# 347
 __attribute((const)); 
# 350
extern int __signbit(double __value) throw()
# 351
 __attribute((const)); 
# 355
extern double fma(double __x, double __y, double __z) throw(); extern double __fma(double __x, double __y, double __z) throw(); 
# 364
extern double scalb(double __x, double __n) throw(); extern double __scalb(double __x, double __n) throw(); 
# 54 "/usr/include/bits/mathcalls.h" 3
extern float acosf(float __x) throw(); extern float __acosf(float __x) throw(); 
# 56
extern float asinf(float __x) throw(); extern float __asinf(float __x) throw(); 
# 58
extern float atanf(float __x) throw(); extern float __atanf(float __x) throw(); 
# 60
extern float atan2f(float __y, float __x) throw(); extern float __atan2f(float __y, float __x) throw(); 
# 63
extern float cosf(float __x) throw(); 
# 65
extern float sinf(float __x) throw(); 
# 67
extern float tanf(float __x) throw(); 
# 72
extern float coshf(float __x) throw(); extern float __coshf(float __x) throw(); 
# 74
extern float sinhf(float __x) throw(); extern float __sinhf(float __x) throw(); 
# 76
extern float tanhf(float __x) throw(); extern float __tanhf(float __x) throw(); 
# 81
extern void sincosf(float __x, float * __sinx, float * __cosx) throw(); 
# 88
extern float acoshf(float __x) throw(); extern float __acoshf(float __x) throw(); 
# 90
extern float asinhf(float __x) throw(); extern float __asinhf(float __x) throw(); 
# 92
extern float atanhf(float __x) throw(); extern float __atanhf(float __x) throw(); 
# 100
extern float expf(float __x) throw(); 
# 103
extern float frexpf(float __x, int * __exponent) throw(); extern float __frexpf(float __x, int * __exponent) throw(); 
# 106
extern float ldexpf(float __x, int __exponent) throw(); extern float __ldexpf(float __x, int __exponent) throw(); 
# 109
extern float logf(float __x) throw(); 
# 112
extern float log10f(float __x) throw(); 
# 115
extern float modff(float __x, float * __iptr) throw(); extern float __modff(float __x, float * __iptr) throw()
# 116
 __attribute((__nonnull__(2))); 
# 121
extern float exp10f(float __x) throw(); 
# 123
extern float pow10f(float __x) throw(); extern float __pow10f(float __x) throw(); 
# 129
extern float expm1f(float __x) throw(); extern float __expm1f(float __x) throw(); 
# 132
extern float log1pf(float __x) throw(); extern float __log1pf(float __x) throw(); 
# 135
extern float logbf(float __x) throw(); extern float __logbf(float __x) throw(); 
# 142
extern float exp2f(float __x) throw(); extern float __exp2f(float __x) throw(); 
# 145
extern float log2f(float __x) throw(); 
# 154
extern float powf(float __x, float __y) throw(); 
# 157
extern float sqrtf(float __x) throw(); extern float __sqrtf(float __x) throw(); 
# 163
extern float hypotf(float __x, float __y) throw(); extern float __hypotf(float __x, float __y) throw(); 
# 170
extern float cbrtf(float __x) throw(); extern float __cbrtf(float __x) throw(); 
# 179
extern float ceilf(float __x) throw() __attribute((const)); extern float __ceilf(float __x) throw() __attribute((const)); 
# 182
extern float fabsf(float __x) throw() __attribute((const)); extern float __fabsf(float __x) throw() __attribute((const)); 
# 185
extern float floorf(float __x) throw() __attribute((const)); extern float __floorf(float __x) throw() __attribute((const)); 
# 188
extern float fmodf(float __x, float __y) throw(); extern float __fmodf(float __x, float __y) throw(); 
# 193
extern int __isinff(float __value) throw() __attribute((const)); 
# 196
extern int __finitef(float __value) throw() __attribute((const)); 
# 202
extern int isinff(float __value) throw() __attribute((const)); 
# 205
extern int finitef(float __value) throw() __attribute((const)); 
# 208
extern float dremf(float __x, float __y) throw(); extern float __dremf(float __x, float __y) throw(); 
# 212
extern float significandf(float __x) throw(); extern float __significandf(float __x) throw(); 
# 218
extern float copysignf(float __x, float __y) throw() __attribute((const)); extern float __copysignf(float __x, float __y) throw() __attribute((const)); 
# 225
extern float nanf(const char * __tagb) throw() __attribute((const)); extern float __nanf(const char * __tagb) throw() __attribute((const)); 
# 231
extern int __isnanf(float __value) throw() __attribute((const)); 
# 235
extern int isnanf(float __value) throw() __attribute((const)); 
# 238
extern float j0f(float) throw(); extern float __j0f(float) throw(); 
# 239
extern float j1f(float) throw(); extern float __j1f(float) throw(); 
# 240
extern float jnf(int, float) throw(); extern float __jnf(int, float) throw(); 
# 241
extern float y0f(float) throw(); extern float __y0f(float) throw(); 
# 242
extern float y1f(float) throw(); extern float __y1f(float) throw(); 
# 243
extern float ynf(int, float) throw(); extern float __ynf(int, float) throw(); 
# 250
extern float erff(float) throw(); extern float __erff(float) throw(); 
# 251
extern float erfcf(float) throw(); extern float __erfcf(float) throw(); 
# 252
extern float lgammaf(float) throw(); extern float __lgammaf(float) throw(); 
# 259
extern float tgammaf(float) throw(); extern float __tgammaf(float) throw(); 
# 265
extern float gammaf(float) throw(); extern float __gammaf(float) throw(); 
# 272
extern float lgammaf_r(float, int * __signgamp) throw(); extern float __lgammaf_r(float, int * __signgamp) throw(); 
# 280
extern float rintf(float __x) throw(); extern float __rintf(float __x) throw(); 
# 283
extern float nextafterf(float __x, float __y) throw() __attribute((const)); extern float __nextafterf(float __x, float __y) throw() __attribute((const)); 
# 285
extern float nexttowardf(float __x, long double __y) throw() __attribute((const)); extern float __nexttowardf(float __x, long double __y) throw() __attribute((const)); 
# 289
extern float remainderf(float __x, float __y) throw(); extern float __remainderf(float __x, float __y) throw(); 
# 293
extern float scalbnf(float __x, int __n) throw(); extern float __scalbnf(float __x, int __n) throw(); 
# 297
extern int ilogbf(float __x) throw(); extern int __ilogbf(float __x) throw(); 
# 302
extern float scalblnf(float __x, long __n) throw(); extern float __scalblnf(float __x, long __n) throw(); 
# 306
extern float nearbyintf(float __x) throw(); extern float __nearbyintf(float __x) throw(); 
# 310
extern float roundf(float __x) throw() __attribute((const)); extern float __roundf(float __x) throw() __attribute((const)); 
# 314
extern float truncf(float __x) throw() __attribute((const)); extern float __truncf(float __x) throw() __attribute((const)); 
# 319
extern float remquof(float __x, float __y, int * __quo) throw(); extern float __remquof(float __x, float __y, int * __quo) throw(); 
# 326
extern long lrintf(float __x) throw(); extern long __lrintf(float __x) throw(); 
# 327
extern long long llrintf(float __x) throw(); extern long long __llrintf(float __x) throw(); 
# 331
extern long lroundf(float __x) throw(); extern long __lroundf(float __x) throw(); 
# 332
extern long long llroundf(float __x) throw(); extern long long __llroundf(float __x) throw(); 
# 336
extern float fdimf(float __x, float __y) throw(); extern float __fdimf(float __x, float __y) throw(); 
# 339
extern float fmaxf(float __x, float __y) throw() __attribute((const)); extern float __fmaxf(float __x, float __y) throw() __attribute((const)); 
# 342
extern float fminf(float __x, float __y) throw() __attribute((const)); extern float __fminf(float __x, float __y) throw() __attribute((const)); 
# 346
extern int __fpclassifyf(float __value) throw()
# 347
 __attribute((const)); 
# 350
extern int __signbitf(float __value) throw()
# 351
 __attribute((const)); 
# 355
extern float fmaf(float __x, float __y, float __z) throw(); extern float __fmaf(float __x, float __y, float __z) throw(); 
# 364
extern float scalbf(float __x, float __n) throw(); extern float __scalbf(float __x, float __n) throw(); 
# 54 "/usr/include/bits/mathcalls.h" 3
extern long double acosl(long double __x) throw(); extern long double __acosl(long double __x) throw(); 
# 56
extern long double asinl(long double __x) throw(); extern long double __asinl(long double __x) throw(); 
# 58
extern long double atanl(long double __x) throw(); extern long double __atanl(long double __x) throw(); 
# 60
extern long double atan2l(long double __y, long double __x) throw(); extern long double __atan2l(long double __y, long double __x) throw(); 
# 63
extern long double cosl(long double __x) throw(); extern long double __cosl(long double __x) throw(); 
# 65
extern long double sinl(long double __x) throw(); extern long double __sinl(long double __x) throw(); 
# 67
extern long double tanl(long double __x) throw(); extern long double __tanl(long double __x) throw(); 
# 72
extern long double coshl(long double __x) throw(); extern long double __coshl(long double __x) throw(); 
# 74
extern long double sinhl(long double __x) throw(); extern long double __sinhl(long double __x) throw(); 
# 76
extern long double tanhl(long double __x) throw(); extern long double __tanhl(long double __x) throw(); 
# 81
extern void sincosl(long double __x, long double * __sinx, long double * __cosx) throw(); extern void __sincosl(long double __x, long double * __sinx, long double * __cosx) throw(); 
# 88
extern long double acoshl(long double __x) throw(); extern long double __acoshl(long double __x) throw(); 
# 90
extern long double asinhl(long double __x) throw(); extern long double __asinhl(long double __x) throw(); 
# 92
extern long double atanhl(long double __x) throw(); extern long double __atanhl(long double __x) throw(); 
# 100
extern long double expl(long double __x) throw(); extern long double __expl(long double __x) throw(); 
# 103
extern long double frexpl(long double __x, int * __exponent) throw(); extern long double __frexpl(long double __x, int * __exponent) throw(); 
# 106
extern long double ldexpl(long double __x, int __exponent) throw(); extern long double __ldexpl(long double __x, int __exponent) throw(); 
# 109
extern long double logl(long double __x) throw(); extern long double __logl(long double __x) throw(); 
# 112
extern long double log10l(long double __x) throw(); extern long double __log10l(long double __x) throw(); 
# 115
extern long double modfl(long double __x, long double * __iptr) throw(); extern long double __modfl(long double __x, long double * __iptr) throw()
# 116
 __attribute((__nonnull__(2))); 
# 121
extern long double exp10l(long double __x) throw(); extern long double __exp10l(long double __x) throw(); 
# 123
extern long double pow10l(long double __x) throw(); extern long double __pow10l(long double __x) throw(); 
# 129
extern long double expm1l(long double __x) throw(); extern long double __expm1l(long double __x) throw(); 
# 132
extern long double log1pl(long double __x) throw(); extern long double __log1pl(long double __x) throw(); 
# 135
extern long double logbl(long double __x) throw(); extern long double __logbl(long double __x) throw(); 
# 142
extern long double exp2l(long double __x) throw(); extern long double __exp2l(long double __x) throw(); 
# 145
extern long double log2l(long double __x) throw(); extern long double __log2l(long double __x) throw(); 
# 154
extern long double powl(long double __x, long double __y) throw(); extern long double __powl(long double __x, long double __y) throw(); 
# 157
extern long double sqrtl(long double __x) throw(); extern long double __sqrtl(long double __x) throw(); 
# 163
extern long double hypotl(long double __x, long double __y) throw(); extern long double __hypotl(long double __x, long double __y) throw(); 
# 170
extern long double cbrtl(long double __x) throw(); extern long double __cbrtl(long double __x) throw(); 
# 179
extern long double ceill(long double __x) throw() __attribute((const)); extern long double __ceill(long double __x) throw() __attribute((const)); 
# 182
extern long double fabsl(long double __x) throw() __attribute((const)); extern long double __fabsl(long double __x) throw() __attribute((const)); 
# 185
extern long double floorl(long double __x) throw() __attribute((const)); extern long double __floorl(long double __x) throw() __attribute((const)); 
# 188
extern long double fmodl(long double __x, long double __y) throw(); extern long double __fmodl(long double __x, long double __y) throw(); 
# 193
extern int __isinfl(long double __value) throw() __attribute((const)); 
# 196
extern int __finitel(long double __value) throw() __attribute((const)); 
# 202
extern int isinfl(long double __value) throw() __attribute((const)); 
# 205
extern int finitel(long double __value) throw() __attribute((const)); 
# 208
extern long double dreml(long double __x, long double __y) throw(); extern long double __dreml(long double __x, long double __y) throw(); 
# 212
extern long double significandl(long double __x) throw(); extern long double __significandl(long double __x) throw(); 
# 218
extern long double copysignl(long double __x, long double __y) throw() __attribute((const)); extern long double __copysignl(long double __x, long double __y) throw() __attribute((const)); 
# 225
extern long double nanl(const char * __tagb) throw() __attribute((const)); extern long double __nanl(const char * __tagb) throw() __attribute((const)); 
# 231
extern int __isnanl(long double __value) throw() __attribute((const)); 
# 235
extern int isnanl(long double __value) throw() __attribute((const)); 
# 238
extern long double j0l(long double) throw(); extern long double __j0l(long double) throw(); 
# 239
extern long double j1l(long double) throw(); extern long double __j1l(long double) throw(); 
# 240
extern long double jnl(int, long double) throw(); extern long double __jnl(int, long double) throw(); 
# 241
extern long double y0l(long double) throw(); extern long double __y0l(long double) throw(); 
# 242
extern long double y1l(long double) throw(); extern long double __y1l(long double) throw(); 
# 243
extern long double ynl(int, long double) throw(); extern long double __ynl(int, long double) throw(); 
# 250
extern long double erfl(long double) throw(); extern long double __erfl(long double) throw(); 
# 251
extern long double erfcl(long double) throw(); extern long double __erfcl(long double) throw(); 
# 252
extern long double lgammal(long double) throw(); extern long double __lgammal(long double) throw(); 
# 259
extern long double tgammal(long double) throw(); extern long double __tgammal(long double) throw(); 
# 265
extern long double gammal(long double) throw(); extern long double __gammal(long double) throw(); 
# 272
extern long double lgammal_r(long double, int * __signgamp) throw(); extern long double __lgammal_r(long double, int * __signgamp) throw(); 
# 280
extern long double rintl(long double __x) throw(); extern long double __rintl(long double __x) throw(); 
# 283
extern long double nextafterl(long double __x, long double __y) throw() __attribute((const)); extern long double __nextafterl(long double __x, long double __y) throw() __attribute((const)); 
# 285
extern long double nexttowardl(long double __x, long double __y) throw() __attribute((const)); extern long double __nexttowardl(long double __x, long double __y) throw() __attribute((const)); 
# 289
extern long double remainderl(long double __x, long double __y) throw(); extern long double __remainderl(long double __x, long double __y) throw(); 
# 293
extern long double scalbnl(long double __x, int __n) throw(); extern long double __scalbnl(long double __x, int __n) throw(); 
# 297
extern int ilogbl(long double __x) throw(); extern int __ilogbl(long double __x) throw(); 
# 302
extern long double scalblnl(long double __x, long __n) throw(); extern long double __scalblnl(long double __x, long __n) throw(); 
# 306
extern long double nearbyintl(long double __x) throw(); extern long double __nearbyintl(long double __x) throw(); 
# 310
extern long double roundl(long double __x) throw() __attribute((const)); extern long double __roundl(long double __x) throw() __attribute((const)); 
# 314
extern long double truncl(long double __x) throw() __attribute((const)); extern long double __truncl(long double __x) throw() __attribute((const)); 
# 319
extern long double remquol(long double __x, long double __y, int * __quo) throw(); extern long double __remquol(long double __x, long double __y, int * __quo) throw(); 
# 326
extern long lrintl(long double __x) throw(); extern long __lrintl(long double __x) throw(); 
# 327
extern long long llrintl(long double __x) throw(); extern long long __llrintl(long double __x) throw(); 
# 331
extern long lroundl(long double __x) throw(); extern long __lroundl(long double __x) throw(); 
# 332
extern long long llroundl(long double __x) throw(); extern long long __llroundl(long double __x) throw(); 
# 336
extern long double fdiml(long double __x, long double __y) throw(); extern long double __fdiml(long double __x, long double __y) throw(); 
# 339
extern long double fmaxl(long double __x, long double __y) throw() __attribute((const)); extern long double __fmaxl(long double __x, long double __y) throw() __attribute((const)); 
# 342
extern long double fminl(long double __x, long double __y) throw() __attribute((const)); extern long double __fminl(long double __x, long double __y) throw() __attribute((const)); 
# 346
extern int __fpclassifyl(long double __value) throw()
# 347
 __attribute((const)); 
# 350
extern int __signbitl(long double __value) throw()
# 351
 __attribute((const)); 
# 355
extern long double fmal(long double __x, long double __y, long double __z) throw(); extern long double __fmal(long double __x, long double __y, long double __z) throw(); 
# 364
extern long double scalbl(long double __x, long double __n) throw(); extern long double __scalbl(long double __x, long double __n) throw(); 
# 149 "/usr/include/math.h" 3
extern int signgam; 
# 191
enum { 
# 192
FP_NAN, 
# 195
FP_INFINITE, 
# 198
FP_ZERO, 
# 201
FP_SUBNORMAL, 
# 204
FP_NORMAL
# 207
}; 
# 295
typedef 
# 289
enum { 
# 290
_IEEE_ = (-1), 
# 291
_SVID_ = 0, 
# 292
_XOPEN_, 
# 293
_POSIX_, 
# 294
_ISOC_
# 295
} _LIB_VERSION_TYPE; 
# 300
extern _LIB_VERSION_TYPE _LIB_VERSION; 
# 311
struct __exception { 
# 316
int type; 
# 317
char *name; 
# 318
double arg1; 
# 319
double arg2; 
# 320
double retval; 
# 321
}; 
# 324
extern int matherr(__exception * __exc) throw(); 
# 475
}
# 34 "/usr/include/stdlib.h" 3
extern "C" {
# 45 "/usr/include/bits/byteswap.h" 3
static inline unsigned __bswap_32(unsigned __bsx) 
# 46
{ 
# 47
return __builtin_bswap32(__bsx); 
# 48
} 
# 109
static inline __uint64_t __bswap_64(__uint64_t __bsx) 
# 110
{ 
# 111
return __builtin_bswap64(__bsx); 
# 112
} 
# 66 "/usr/include/bits/waitstatus.h" 3
union wait { 
# 68
int w_status; 
# 70
struct { 
# 72
unsigned __w_termsig:7; 
# 73
unsigned __w_coredump:1; 
# 74
unsigned __w_retcode:8; 
# 75
unsigned:16; 
# 83
} __wait_terminated; 
# 85
struct { 
# 87
unsigned __w_stopval:8; 
# 88
unsigned __w_stopsig:8; 
# 89
unsigned:16; 
# 96
} __wait_stopped; 
# 97
}; 
# 101 "/usr/include/stdlib.h" 3
typedef 
# 98
struct { 
# 99
int quot; 
# 100
int rem; 
# 101
} div_t; 
# 109
typedef 
# 106
struct { 
# 107
long quot; 
# 108
long rem; 
# 109
} ldiv_t; 
# 121
__extension__ typedef 
# 118
struct { 
# 119
long long quot; 
# 120
long long rem; 
# 121
} lldiv_t; 
# 139
extern ::size_t __ctype_get_mb_cur_max() throw(); 
# 144
extern double atof(const char * __nptr) throw()
# 145
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 147
extern int atoi(const char * __nptr) throw()
# 148
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 150
extern long atol(const char * __nptr) throw()
# 151
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 157
__extension__ extern long long atoll(const char * __nptr) throw()
# 158
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 164
extern double strtod(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 166
 __attribute((__nonnull__(1))); 
# 172
extern float strtof(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 173
 __attribute((__nonnull__(1))); 
# 175
extern long double strtold(const char *__restrict__ __nptr, char **__restrict__ __endptr) throw()
# 177
 __attribute((__nonnull__(1))); 
# 183
extern long strtol(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 185
 __attribute((__nonnull__(1))); 
# 187
extern unsigned long strtoul(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 189
 __attribute((__nonnull__(1))); 
# 195
__extension__ extern long long strtoq(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 197
 __attribute((__nonnull__(1))); 
# 200
__extension__ extern unsigned long long strtouq(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 202
 __attribute((__nonnull__(1))); 
# 209
__extension__ extern long long strtoll(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 211
 __attribute((__nonnull__(1))); 
# 214
__extension__ extern unsigned long long strtoull(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base) throw()
# 216
 __attribute((__nonnull__(1))); 
# 239
extern long strtol_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base, __locale_t __loc) throw()
# 241
 __attribute((__nonnull__(1, 4))); 
# 243
extern unsigned long strtoul_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base, __locale_t __loc) throw()
# 246
 __attribute((__nonnull__(1, 4))); 
# 249
__extension__ extern long long strtoll_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base, __locale_t __loc) throw()
# 252
 __attribute((__nonnull__(1, 4))); 
# 255
__extension__ extern unsigned long long strtoull_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, int __base, __locale_t __loc) throw()
# 258
 __attribute((__nonnull__(1, 4))); 
# 260
extern double strtod_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, __locale_t __loc) throw()
# 262
 __attribute((__nonnull__(1, 3))); 
# 264
extern float strtof_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, __locale_t __loc) throw()
# 266
 __attribute((__nonnull__(1, 3))); 
# 268
extern long double strtold_l(const char *__restrict__ __nptr, char **__restrict__ __endptr, __locale_t __loc) throw()
# 271
 __attribute((__nonnull__(1, 3))); 
# 305
extern char *l64a(long __n) throw(); 
# 308
extern long a64l(const char * __s) throw()
# 309
 __attribute((__pure__)) __attribute((__nonnull__(1))); 
# 27 "/usr/include/sys/types.h" 3
extern "C" {
# 33
typedef __u_char u_char; 
# 34
typedef __u_short u_short; 
# 35
typedef __u_int u_int; 
# 36
typedef __u_long u_long; 
# 37
typedef __quad_t quad_t; 
# 38
typedef __u_quad_t u_quad_t; 
# 39
typedef __fsid_t fsid_t; 
# 44
typedef __loff_t loff_t; 
# 48
typedef __ino_t ino_t; 
# 55
typedef __ino64_t ino64_t; 
# 60
typedef __dev_t dev_t; 
# 65
typedef __gid_t gid_t; 
# 70
typedef __mode_t mode_t; 
# 75
typedef __nlink_t nlink_t; 
# 80
typedef __uid_t uid_t; 
# 86
typedef __off_t off_t; 
# 93
typedef __off64_t off64_t; 
# 104
typedef __id_t id_t; 
# 109
typedef __ssize_t ssize_t; 
# 115
typedef __daddr_t daddr_t; 
# 116
typedef __caddr_t caddr_t; 
# 122
typedef __key_t key_t; 
# 136
typedef __useconds_t useconds_t; 
# 140
typedef __suseconds_t suseconds_t; 
# 150
typedef unsigned long ulong; 
# 151
typedef unsigned short ushort; 
# 152
typedef unsigned uint; 
# 194
typedef signed char int8_t __attribute((__mode__(__QI__))); 
# 195
typedef short int16_t __attribute((__mode__(__HI__))); 
# 196
typedef int int32_t __attribute((__mode__(__SI__))); 
# 197
typedef long int64_t __attribute((__mode__(__DI__))); 
# 200
typedef unsigned char u_int8_t __attribute((__mode__(__QI__))); 
# 201
typedef unsigned short u_int16_t __attribute((__mode__(__HI__))); 
# 202
typedef unsigned u_int32_t __attribute((__mode__(__SI__))); 
# 203
typedef unsigned long u_int64_t __attribute((__mode__(__DI__))); 
# 205
typedef long register_t __attribute((__mode__(__word__))); 
# 23 "/usr/include/bits/sigset.h" 3
typedef int __sig_atomic_t; 
# 31
typedef 
# 29
struct { 
# 30
unsigned long __val[(1024) / ((8) * sizeof(unsigned long))]; 
# 31
} __sigset_t; 
# 37 "/usr/include/sys/select.h" 3
typedef __sigset_t sigset_t; 
# 54
typedef long __fd_mask; 
# 75
typedef 
# 65
struct { 
# 69
__fd_mask fds_bits[1024 / (8 * ((int)sizeof(__fd_mask)))]; 
# 75
} fd_set; 
# 82
typedef __fd_mask fd_mask; 
# 96
extern "C" {
# 106
extern int select(int __nfds, fd_set *__restrict__ __readfds, fd_set *__restrict__ __writefds, fd_set *__restrict__ __exceptfds, timeval *__restrict__ __timeout); 
# 118
extern int pselect(int __nfds, fd_set *__restrict__ __readfds, fd_set *__restrict__ __writefds, fd_set *__restrict__ __exceptfds, const timespec *__restrict__ __timeout, const __sigset_t *__restrict__ __sigmask); 
# 131
}
# 29 "/usr/include/sys/sysmacros.h" 3
extern "C" {
# 32
__extension__ extern unsigned gnu_dev_major(unsigned long long __dev) throw()
# 33
 __attribute((const)); 
# 35
__extension__ extern unsigned gnu_dev_minor(unsigned long long __dev) throw()
# 36
 __attribute((const)); 
# 38
__extension__ extern unsigned long long gnu_dev_makedev(unsigned __major, unsigned __minor) throw()
# 40
 __attribute((const)); 
# 63
}
# 228 "/usr/include/sys/types.h" 3
typedef __blksize_t blksize_t; 
# 235
typedef __blkcnt_t blkcnt_t; 
# 239
typedef __fsblkcnt_t fsblkcnt_t; 
# 243
typedef __fsfilcnt_t fsfilcnt_t; 
# 262
typedef __blkcnt64_t blkcnt64_t; 
# 263
typedef __fsblkcnt64_t fsblkcnt64_t; 
# 264
typedef __fsfilcnt64_t fsfilcnt64_t; 
# 60 "/usr/include/bits/pthreadtypes.h" 3
typedef unsigned long pthread_t; 
# 63
union pthread_attr_t { 
# 65
char __size[56]; 
# 66
long __align; 
# 67
}; 
# 69
typedef pthread_attr_t pthread_attr_t; 
# 79
typedef 
# 75
struct __pthread_internal_list { 
# 77
__pthread_internal_list *__prev; 
# 78
__pthread_internal_list *__next; 
# 79
} __pthread_list_t; 
# 127
typedef 
# 91
union { 
# 92
struct __pthread_mutex_s { 
# 94
int __lock; 
# 95
unsigned __count; 
# 96
int __owner; 
# 98
unsigned __nusers; 
# 102
int __kind; 
# 104
short __spins; 
# 105
short __elision; 
# 106
__pthread_list_t __list; 
# 124
} __data; 
# 125
char __size[40]; 
# 126
long __align; 
# 127
} pthread_mutex_t; 
# 133
typedef 
# 130
union { 
# 131
char __size[4]; 
# 132
int __align; 
# 133
} pthread_mutexattr_t; 
# 153
typedef 
# 139
union { 
# 141
struct { 
# 142
int __lock; 
# 143
unsigned __futex; 
# 144
__extension__ unsigned long long __total_seq; 
# 145
__extension__ unsigned long long __wakeup_seq; 
# 146
__extension__ unsigned long long __woken_seq; 
# 147
void *__mutex; 
# 148
unsigned __nwaiters; 
# 149
unsigned __broadcast_seq; 
# 150
} __data; 
# 151
char __size[48]; 
# 152
__extension__ long long __align; 
# 153
} pthread_cond_t; 
# 159
typedef 
# 156
union { 
# 157
char __size[4]; 
# 158
int __align; 
# 159
} pthread_condattr_t; 
# 163
typedef unsigned pthread_key_t; 
# 167
typedef int pthread_once_t; 
# 213
typedef 
# 174
union { 
# 177
struct { 
# 178
int __lock; 
# 179
unsigned __nr_readers; 
# 180
unsigned __readers_wakeup; 
# 181
unsigned __writer_wakeup; 
# 182
unsigned __nr_readers_queued; 
# 183
unsigned __nr_writers_queued; 
# 184
int __writer; 
# 185
int __shared; 
# 186
unsigned long __pad1; 
# 187
unsigned long __pad2; 
# 190
unsigned __flags; 
# 192
} __data; 
# 211
char __size[56]; 
# 212
long __align; 
# 213
} pthread_rwlock_t; 
# 219
typedef 
# 216
union { 
# 217
char __size[8]; 
# 218
long __align; 
# 219
} pthread_rwlockattr_t; 
# 225
typedef volatile int pthread_spinlock_t; 
# 234
typedef 
# 231
union { 
# 232
char __size[32]; 
# 233
long __align; 
# 234
} pthread_barrier_t; 
# 240
typedef 
# 237
union { 
# 238
char __size[4]; 
# 239
int __align; 
# 240
} pthread_barrierattr_t; 
# 273 "/usr/include/sys/types.h" 3
}
# 321 "/usr/include/stdlib.h" 3
extern long random() throw(); 
# 324
extern void srandom(unsigned __seed) throw(); 
# 330
extern char *initstate(unsigned __seed, char * __statebuf, ::size_t __statelen) throw()
# 331
 __attribute((__nonnull__(2))); 
# 335
extern char *setstate(char * __statebuf) throw() __attribute((__nonnull__(1))); 
# 343
struct random_data { 
# 345
int32_t *fptr; 
# 346
int32_t *rptr; 
# 347
int32_t *state; 
# 348
int rand_type; 
# 349
int rand_deg; 
# 350
int rand_sep; 
# 351
int32_t *end_ptr; 
# 352
}; 
# 354
extern int random_r(random_data *__restrict__ __buf, int32_t *__restrict__ __result) throw()
# 355
 __attribute((__nonnull__(1, 2))); 
# 357
extern int srandom_r(unsigned __seed, random_data * __buf) throw()
# 358
 __attribute((__nonnull__(2))); 
# 360
extern int initstate_r(unsigned __seed, char *__restrict__ __statebuf, ::size_t __statelen, random_data *__restrict__ __buf) throw()
# 363
 __attribute((__nonnull__(2, 4))); 
# 365
extern int setstate_r(char *__restrict__ __statebuf, random_data *__restrict__ __buf) throw()
# 367
 __attribute((__nonnull__(1, 2))); 
# 374
extern int rand() throw(); 
# 376
extern void srand(unsigned __seed) throw(); 
# 381
extern int rand_r(unsigned * __seed) throw(); 
# 389
extern double drand48() throw(); 
# 390
extern double erand48(unsigned short  __xsubi[3]) throw() __attribute((__nonnull__(1))); 
# 393
extern long lrand48() throw(); 
# 394
extern long nrand48(unsigned short  __xsubi[3]) throw()
# 395
 __attribute((__nonnull__(1))); 
# 398
extern long mrand48() throw(); 
# 399
extern long jrand48(unsigned short  __xsubi[3]) throw()
# 400
 __attribute((__nonnull__(1))); 
# 403
extern void srand48(long __seedval) throw(); 
# 404
extern unsigned short *seed48(unsigned short  __seed16v[3]) throw()
# 405
 __attribute((__nonnull__(1))); 
# 406
extern void lcong48(unsigned short  __param[7]) throw() __attribute((__nonnull__(1))); 
# 412
struct drand48_data { 
# 414
unsigned short __x[3]; 
# 415
unsigned short __old_x[3]; 
# 416
unsigned short __c; 
# 417
unsigned short __init; 
# 418
unsigned long long __a; 
# 419
}; 
# 422
extern int drand48_r(drand48_data *__restrict__ __buffer, double *__restrict__ __result) throw()
# 423
 __attribute((__nonnull__(1, 2))); 
# 424
extern int erand48_r(unsigned short  __xsubi[3], drand48_data *__restrict__ __buffer, double *__restrict__ __result) throw()
# 426
 __attribute((__nonnull__(1, 2))); 
# 429
extern int lrand48_r(drand48_data *__restrict__ __buffer, long *__restrict__ __result) throw()
# 431
 __attribute((__nonnull__(1, 2))); 
# 432
extern int nrand48_r(unsigned short  __xsubi[3], drand48_data *__restrict__ __buffer, long *__restrict__ __result) throw()
# 435
 __attribute((__nonnull__(1, 2))); 
# 438
extern int mrand48_r(drand48_data *__restrict__ __buffer, long *__restrict__ __result) throw()
# 440
 __attribute((__nonnull__(1, 2))); 
# 441
extern int jrand48_r(unsigned short  __xsubi[3], drand48_data *__restrict__ __buffer, long *__restrict__ __result) throw()
# 444
 __attribute((__nonnull__(1, 2))); 
# 447
extern int srand48_r(long __seedval, drand48_data * __buffer) throw()
# 448
 __attribute((__nonnull__(2))); 
# 450
extern int seed48_r(unsigned short  __seed16v[3], drand48_data * __buffer) throw()
# 451
 __attribute((__nonnull__(1, 2))); 
# 453
extern int lcong48_r(unsigned short  __param[7], drand48_data * __buffer) throw()
# 455
 __attribute((__nonnull__(1, 2))); 
# 465
extern void *malloc(::size_t __size) throw() __attribute((__malloc__)); 
# 467
extern void *calloc(::size_t __nmemb, ::size_t __size) throw()
# 468
 __attribute((__malloc__)); 
# 479
extern void *realloc(void * __ptr, ::size_t __size) throw()
# 480
 __attribute((__warn_unused_result__)); 
# 482
extern void free(void * __ptr) throw(); 
# 487
extern void cfree(void * __ptr) throw(); 
# 26 "/usr/include/alloca.h" 3
extern "C" {
# 32
extern void *alloca(::size_t __size) throw(); 
# 38
}
# 497 "/usr/include/stdlib.h" 3
extern void *valloc(::size_t __size) throw() __attribute((__malloc__)); 
# 502
extern int posix_memalign(void ** __memptr, ::size_t __alignment, ::size_t __size) throw()
# 503
 __attribute((__nonnull__(1))); 
# 508
extern void *aligned_alloc(::size_t __alignment, ::size_t __size) throw()
# 509
 __attribute((__malloc__, __alloc_size__(2))); 
# 514
extern void abort() throw() __attribute((__noreturn__)); 
# 518
extern int atexit(void (* __func)(void)) throw() __attribute((__nonnull__(1))); 
# 523
extern "C++" int at_quick_exit(void (* __func)(void)) throw() __asm__("at_quick_exit")
# 524
 __attribute((__nonnull__(1))); 
# 534
extern int on_exit(void (* __func)(int __status, void * __arg), void * __arg) throw()
# 535
 __attribute((__nonnull__(1))); 
# 542
extern void exit(int __status) throw() __attribute((__noreturn__)); 
# 548
extern void quick_exit(int __status) throw() __attribute((__noreturn__)); 
# 556
extern void _Exit(int __status) throw() __attribute((__noreturn__)); 
# 563
extern char *getenv(const char * __name) throw() __attribute((__nonnull__(1))); 
# 569
extern char *secure_getenv(const char * __name) throw()
# 570
 __attribute((__nonnull__(1))); 
# 577
extern int putenv(char * __string) throw() __attribute((__nonnull__(1))); 
# 583
extern int setenv(const char * __name, const char * __value, int __replace) throw()
# 584
 __attribute((__nonnull__(2))); 
# 587
extern int unsetenv(const char * __name) throw() __attribute((__nonnull__(1))); 
# 594
extern int clearenv() throw(); 
# 605
extern char *mktemp(char * __template) throw() __attribute((__nonnull__(1))); 
# 619
extern int mkstemp(char * __template) __attribute((__nonnull__(1))); 
# 629
extern int mkstemp64(char * __template) __attribute((__nonnull__(1))); 
# 641
extern int mkstemps(char * __template, int __suffixlen) __attribute((__nonnull__(1))); 
# 651
extern int mkstemps64(char * __template, int __suffixlen)
# 652
 __attribute((__nonnull__(1))); 
# 662
extern char *mkdtemp(char * __template) throw() __attribute((__nonnull__(1))); 
# 673
extern int mkostemp(char * __template, int __flags) __attribute((__nonnull__(1))); 
# 683
extern int mkostemp64(char * __template, int __flags) __attribute((__nonnull__(1))); 
# 693
extern int mkostemps(char * __template, int __suffixlen, int __flags)
# 694
 __attribute((__nonnull__(1))); 
# 705
extern int mkostemps64(char * __template, int __suffixlen, int __flags)
# 706
 __attribute((__nonnull__(1))); 
# 716
extern int system(const char * __command); 
# 723
extern char *canonicalize_file_name(const char * __name) throw()
# 724
 __attribute((__nonnull__(1))); 
# 733
extern char *realpath(const char *__restrict__ __name, char *__restrict__ __resolved) throw(); 
# 741
typedef int (*__compar_fn_t)(const void *, const void *); 
# 744
typedef __compar_fn_t comparison_fn_t; 
# 748
typedef int (*__compar_d_fn_t)(const void *, const void *, void *); 
# 754
extern void *bsearch(const void * __key, const void * __base, ::size_t __nmemb, ::size_t __size, __compar_fn_t __compar)
# 756
 __attribute((__nonnull__(1, 2, 5))); 
# 760
extern void qsort(void * __base, ::size_t __nmemb, ::size_t __size, __compar_fn_t __compar)
# 761
 __attribute((__nonnull__(1, 4))); 
# 763
extern void qsort_r(void * __base, ::size_t __nmemb, ::size_t __size, __compar_d_fn_t __compar, void * __arg)
# 765
 __attribute((__nonnull__(1, 4))); 
# 770
extern int abs(int __x) throw() __attribute((const)); 
# 771
extern long labs(long __x) throw() __attribute((const)); 
# 775
__extension__ extern long long llabs(long long __x) throw()
# 776
 __attribute((const)); 
# 784
extern div_t div(int __numer, int __denom) throw()
# 785
 __attribute((const)); 
# 786
extern ldiv_t ldiv(long __numer, long __denom) throw()
# 787
 __attribute((const)); 
# 792
__extension__ extern lldiv_t lldiv(long long __numer, long long __denom) throw()
# 794
 __attribute((const)); 
# 807
extern char *ecvt(double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign) throw()
# 808
 __attribute((__nonnull__(3, 4))); 
# 813
extern char *fcvt(double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign) throw()
# 814
 __attribute((__nonnull__(3, 4))); 
# 819
extern char *gcvt(double __value, int __ndigit, char * __buf) throw()
# 820
 __attribute((__nonnull__(3))); 
# 825
extern char *qecvt(long double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign) throw()
# 827
 __attribute((__nonnull__(3, 4))); 
# 828
extern char *qfcvt(long double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign) throw()
# 830
 __attribute((__nonnull__(3, 4))); 
# 831
extern char *qgcvt(long double __value, int __ndigit, char * __buf) throw()
# 832
 __attribute((__nonnull__(3))); 
# 837
extern int ecvt_r(double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign, char *__restrict__ __buf, ::size_t __len) throw()
# 839
 __attribute((__nonnull__(3, 4, 5))); 
# 840
extern int fcvt_r(double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign, char *__restrict__ __buf, ::size_t __len) throw()
# 842
 __attribute((__nonnull__(3, 4, 5))); 
# 844
extern int qecvt_r(long double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign, char *__restrict__ __buf, ::size_t __len) throw()
# 847
 __attribute((__nonnull__(3, 4, 5))); 
# 848
extern int qfcvt_r(long double __value, int __ndigit, int *__restrict__ __decpt, int *__restrict__ __sign, char *__restrict__ __buf, ::size_t __len) throw()
# 851
 __attribute((__nonnull__(3, 4, 5))); 
# 859
extern int mblen(const char * __s, ::size_t __n) throw(); 
# 862
extern int mbtowc(wchar_t *__restrict__ __pwc, const char *__restrict__ __s, ::size_t __n) throw(); 
# 866
extern int wctomb(char * __s, wchar_t __wchar) throw(); 
# 870
extern ::size_t mbstowcs(wchar_t *__restrict__ __pwcs, const char *__restrict__ __s, ::size_t __n) throw(); 
# 873
extern ::size_t wcstombs(char *__restrict__ __s, const wchar_t *__restrict__ __pwcs, ::size_t __n) throw(); 
# 884
extern int rpmatch(const char * __response) throw() __attribute((__nonnull__(1))); 
# 895
extern int getsubopt(char **__restrict__ __optionp, char *const *__restrict__ __tokens, char **__restrict__ __valuep) throw()
# 898
 __attribute((__nonnull__(1, 2, 3))); 
# 904
extern void setkey(const char * __key) throw() __attribute((__nonnull__(1))); 
# 912
extern int posix_openpt(int __oflag); 
# 920
extern int grantpt(int __fd) throw(); 
# 924
extern int unlockpt(int __fd) throw(); 
# 929
extern char *ptsname(int __fd) throw(); 
# 936
extern int ptsname_r(int __fd, char * __buf, ::size_t __buflen) throw()
# 937
 __attribute((__nonnull__(2))); 
# 940
extern int getpt(); 
# 947
extern int getloadavg(double  __loadavg[], int __nelem) throw()
# 948
 __attribute((__nonnull__(1))); 
# 964
}
# 1855 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/c++config.h" 3
namespace std { 
# 1857
typedef unsigned long size_t; 
# 1858
typedef long ptrdiff_t; 
# 1863
}
# 68 "/usr/include/c++/4.8.2/bits/cpp_type_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 72
template< class _Iterator, class _Container> class __normal_iterator; 
# 76
}
# 78
namespace std __attribute((__visibility__("default"))) { 
# 82
struct __true_type { }; 
# 83
struct __false_type { }; 
# 85
template< bool > 
# 86
struct __truth_type { 
# 87
typedef __false_type __type; }; 
# 90
template<> struct __truth_type< true>  { 
# 91
typedef __true_type __type; }; 
# 95
template< class _Sp, class _Tp> 
# 96
struct __traitor { 
# 98
enum { __value = ((bool)_Sp::__value) || ((bool)_Tp::__value)}; 
# 99
typedef typename __truth_type< __value> ::__type __type; 
# 100
}; 
# 103
template< class , class > 
# 104
struct __are_same { 
# 106
enum { __value}; 
# 107
typedef __false_type __type; 
# 108
}; 
# 110
template< class _Tp> 
# 111
struct __are_same< _Tp, _Tp>  { 
# 113
enum { __value = 1}; 
# 114
typedef __true_type __type; 
# 115
}; 
# 118
template< class _Tp> 
# 119
struct __is_void { 
# 121
enum { __value}; 
# 122
typedef __false_type __type; 
# 123
}; 
# 126
template<> struct __is_void< void>  { 
# 128
enum { __value = 1}; 
# 129
typedef __true_type __type; 
# 130
}; 
# 135
template< class _Tp> 
# 136
struct __is_integer { 
# 138
enum { __value}; 
# 139
typedef __false_type __type; 
# 140
}; 
# 146
template<> struct __is_integer< bool>  { 
# 148
enum { __value = 1}; 
# 149
typedef __true_type __type; 
# 150
}; 
# 153
template<> struct __is_integer< char>  { 
# 155
enum { __value = 1}; 
# 156
typedef __true_type __type; 
# 157
}; 
# 160
template<> struct __is_integer< signed char>  { 
# 162
enum { __value = 1}; 
# 163
typedef __true_type __type; 
# 164
}; 
# 167
template<> struct __is_integer< unsigned char>  { 
# 169
enum { __value = 1}; 
# 170
typedef __true_type __type; 
# 171
}; 
# 175
template<> struct __is_integer< wchar_t>  { 
# 177
enum { __value = 1}; 
# 178
typedef __true_type __type; 
# 179
}; 
# 199
template<> struct __is_integer< short>  { 
# 201
enum { __value = 1}; 
# 202
typedef __true_type __type; 
# 203
}; 
# 206
template<> struct __is_integer< unsigned short>  { 
# 208
enum { __value = 1}; 
# 209
typedef __true_type __type; 
# 210
}; 
# 213
template<> struct __is_integer< int>  { 
# 215
enum { __value = 1}; 
# 216
typedef __true_type __type; 
# 217
}; 
# 220
template<> struct __is_integer< unsigned>  { 
# 222
enum { __value = 1}; 
# 223
typedef __true_type __type; 
# 224
}; 
# 227
template<> struct __is_integer< long>  { 
# 229
enum { __value = 1}; 
# 230
typedef __true_type __type; 
# 231
}; 
# 234
template<> struct __is_integer< unsigned long>  { 
# 236
enum { __value = 1}; 
# 237
typedef __true_type __type; 
# 238
}; 
# 241
template<> struct __is_integer< long long>  { 
# 243
enum { __value = 1}; 
# 244
typedef __true_type __type; 
# 245
}; 
# 248
template<> struct __is_integer< unsigned long long>  { 
# 250
enum { __value = 1}; 
# 251
typedef __true_type __type; 
# 252
}; 
# 257
template< class _Tp> 
# 258
struct __is_floating { 
# 260
enum { __value}; 
# 261
typedef __false_type __type; 
# 262
}; 
# 266
template<> struct __is_floating< float>  { 
# 268
enum { __value = 1}; 
# 269
typedef __true_type __type; 
# 270
}; 
# 273
template<> struct __is_floating< double>  { 
# 275
enum { __value = 1}; 
# 276
typedef __true_type __type; 
# 277
}; 
# 280
template<> struct __is_floating< long double>  { 
# 282
enum { __value = 1}; 
# 283
typedef __true_type __type; 
# 284
}; 
# 289
template< class _Tp> 
# 290
struct __is_pointer { 
# 292
enum { __value}; 
# 293
typedef __false_type __type; 
# 294
}; 
# 296
template< class _Tp> 
# 297
struct __is_pointer< _Tp *>  { 
# 299
enum { __value = 1}; 
# 300
typedef __true_type __type; 
# 301
}; 
# 306
template< class _Tp> 
# 307
struct __is_normal_iterator { 
# 309
enum { __value}; 
# 310
typedef __false_type __type; 
# 311
}; 
# 313
template< class _Iterator, class _Container> 
# 314
struct __is_normal_iterator< __gnu_cxx::__normal_iterator< _Iterator, _Container> >  { 
# 317
enum { __value = 1}; 
# 318
typedef __true_type __type; 
# 319
}; 
# 324
template< class _Tp> 
# 325
struct __is_arithmetic : public __traitor< __is_integer< _Tp> , __is_floating< _Tp> >  { 
# 327
}; 
# 332
template< class _Tp> 
# 333
struct __is_fundamental : public __traitor< __is_void< _Tp> , __is_arithmetic< _Tp> >  { 
# 335
}; 
# 340
template< class _Tp> 
# 341
struct __is_scalar : public __traitor< __is_arithmetic< _Tp> , __is_pointer< _Tp> >  { 
# 343
}; 
# 348
template< class _Tp> 
# 349
struct __is_char { 
# 351
enum { __value}; 
# 352
typedef __false_type __type; 
# 353
}; 
# 356
template<> struct __is_char< char>  { 
# 358
enum { __value = 1}; 
# 359
typedef __true_type __type; 
# 360
}; 
# 364
template<> struct __is_char< wchar_t>  { 
# 366
enum { __value = 1}; 
# 367
typedef __true_type __type; 
# 368
}; 
# 371
template< class _Tp> 
# 372
struct __is_byte { 
# 374
enum { __value}; 
# 375
typedef __false_type __type; 
# 376
}; 
# 379
template<> struct __is_byte< char>  { 
# 381
enum { __value = 1}; 
# 382
typedef __true_type __type; 
# 383
}; 
# 386
template<> struct __is_byte< signed char>  { 
# 388
enum { __value = 1}; 
# 389
typedef __true_type __type; 
# 390
}; 
# 393
template<> struct __is_byte< unsigned char>  { 
# 395
enum { __value = 1}; 
# 396
typedef __true_type __type; 
# 397
}; 
# 402
template< class _Tp> 
# 403
struct __is_move_iterator { 
# 405
enum { __value}; 
# 406
typedef __false_type __type; 
# 407
}; 
# 422
}
# 37 "/usr/include/c++/4.8.2/ext/type_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 42
template< bool , class > 
# 43
struct __enable_if { 
# 44
}; 
# 46
template< class _Tp> 
# 47
struct __enable_if< true, _Tp>  { 
# 48
typedef _Tp __type; }; 
# 52
template< bool _Cond, class _Iftrue, class _Iffalse> 
# 53
struct __conditional_type { 
# 54
typedef _Iftrue __type; }; 
# 56
template< class _Iftrue, class _Iffalse> 
# 57
struct __conditional_type< false, _Iftrue, _Iffalse>  { 
# 58
typedef _Iffalse __type; }; 
# 62
template< class _Tp> 
# 63
struct __add_unsigned { 
# 66
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp>  __if_type; 
# 69
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type; 
# 70
}; 
# 73
template<> struct __add_unsigned< char>  { 
# 74
typedef unsigned char __type; }; 
# 77
template<> struct __add_unsigned< signed char>  { 
# 78
typedef unsigned char __type; }; 
# 81
template<> struct __add_unsigned< short>  { 
# 82
typedef unsigned short __type; }; 
# 85
template<> struct __add_unsigned< int>  { 
# 86
typedef unsigned __type; }; 
# 89
template<> struct __add_unsigned< long>  { 
# 90
typedef unsigned long __type; }; 
# 93
template<> struct __add_unsigned< long long>  { 
# 94
typedef unsigned long long __type; }; 
# 98
template<> struct __add_unsigned< bool> ; 
# 101
template<> struct __add_unsigned< wchar_t> ; 
# 105
template< class _Tp> 
# 106
struct __remove_unsigned { 
# 109
private: typedef __enable_if< std::__is_integer< _Tp> ::__value, _Tp>  __if_type; 
# 112
public: typedef typename __enable_if< std::__is_integer< _Tp> ::__value, _Tp> ::__type __type; 
# 113
}; 
# 116
template<> struct __remove_unsigned< char>  { 
# 117
typedef signed char __type; }; 
# 120
template<> struct __remove_unsigned< unsigned char>  { 
# 121
typedef signed char __type; }; 
# 124
template<> struct __remove_unsigned< unsigned short>  { 
# 125
typedef short __type; }; 
# 128
template<> struct __remove_unsigned< unsigned>  { 
# 129
typedef int __type; }; 
# 132
template<> struct __remove_unsigned< unsigned long>  { 
# 133
typedef long __type; }; 
# 136
template<> struct __remove_unsigned< unsigned long long>  { 
# 137
typedef long long __type; }; 
# 141
template<> struct __remove_unsigned< bool> ; 
# 144
template<> struct __remove_unsigned< wchar_t> ; 
# 148
template< class _Type> inline bool 
# 150
__is_null_pointer(_Type *__ptr) 
# 151
{ return __ptr == 0; } 
# 153
template< class _Type> inline bool 
# 155
__is_null_pointer(_Type) 
# 156
{ return false; } 
# 160
template< class _Tp, bool  = std::__is_integer< _Tp> ::__value> 
# 161
struct __promote { 
# 162
typedef double __type; }; 
# 167
template< class _Tp> 
# 168
struct __promote< _Tp, false>  { 
# 169
}; 
# 172
template<> struct __promote< long double>  { 
# 173
typedef long double __type; }; 
# 176
template<> struct __promote< double>  { 
# 177
typedef double __type; }; 
# 180
template<> struct __promote< float>  { 
# 181
typedef float __type; }; 
# 183
template< class _Tp, class _Up, class 
# 184
_Tp2 = typename __promote< _Tp> ::__type, class 
# 185
_Up2 = typename __promote< _Up> ::__type> 
# 186
struct __promote_2 { 
# 188
typedef __typeof__(_Tp2() + _Up2()) __type; 
# 189
}; 
# 191
template< class _Tp, class _Up, class _Vp, class 
# 192
_Tp2 = typename __promote< _Tp> ::__type, class 
# 193
_Up2 = typename __promote< _Up> ::__type, class 
# 194
_Vp2 = typename __promote< _Vp> ::__type> 
# 195
struct __promote_3 { 
# 197
typedef __typeof__((_Tp2() + _Up2()) + _Vp2()) __type; 
# 198
}; 
# 200
template< class _Tp, class _Up, class _Vp, class _Wp, class 
# 201
_Tp2 = typename __promote< _Tp> ::__type, class 
# 202
_Up2 = typename __promote< _Up> ::__type, class 
# 203
_Vp2 = typename __promote< _Vp> ::__type, class 
# 204
_Wp2 = typename __promote< _Wp> ::__type> 
# 205
struct __promote_4 { 
# 207
typedef __typeof__(((_Tp2() + _Up2()) + _Vp2()) + _Wp2()) __type; 
# 208
}; 
# 211
}
# 75 "/usr/include/c++/4.8.2/cmath" 3
namespace std __attribute((__visibility__("default"))) { 
# 81
inline double abs(double __x) 
# 82
{ return __builtin_fabs(__x); } 
# 87
inline float abs(float __x) 
# 88
{ return __builtin_fabsf(__x); } 
# 91
inline long double abs(long double __x) 
# 92
{ return __builtin_fabsl(__x); } 
# 95
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 99
abs(_Tp __x) 
# 100
{ return __builtin_fabs(__x); } 
# 102
using ::acos;
# 106
inline float acos(float __x) 
# 107
{ return __builtin_acosf(__x); } 
# 110
inline long double acos(long double __x) 
# 111
{ return __builtin_acosl(__x); } 
# 114
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 118
acos(_Tp __x) 
# 119
{ return __builtin_acos(__x); } 
# 121
using ::asin;
# 125
inline float asin(float __x) 
# 126
{ return __builtin_asinf(__x); } 
# 129
inline long double asin(long double __x) 
# 130
{ return __builtin_asinl(__x); } 
# 133
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 137
asin(_Tp __x) 
# 138
{ return __builtin_asin(__x); } 
# 140
using ::atan;
# 144
inline float atan(float __x) 
# 145
{ return __builtin_atanf(__x); } 
# 148
inline long double atan(long double __x) 
# 149
{ return __builtin_atanl(__x); } 
# 152
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 156
atan(_Tp __x) 
# 157
{ return __builtin_atan(__x); } 
# 159
using ::atan2;
# 163
inline float atan2(float __y, float __x) 
# 164
{ return __builtin_atan2f(__y, __x); } 
# 167
inline long double atan2(long double __y, long double __x) 
# 168
{ return __builtin_atan2l(__y, __x); } 
# 171
template< class _Tp, class _Up> inline typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 174
atan2(_Tp __y, _Up __x) 
# 175
{ 
# 176
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 177
return atan2((__type)__y, (__type)__x); 
# 178
} 
# 180
using ::ceil;
# 184
inline float ceil(float __x) 
# 185
{ return __builtin_ceilf(__x); } 
# 188
inline long double ceil(long double __x) 
# 189
{ return __builtin_ceill(__x); } 
# 192
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 196
ceil(_Tp __x) 
# 197
{ return __builtin_ceil(__x); } 
# 199
using ::cos;
# 203
inline float cos(float __x) 
# 204
{ return __builtin_cosf(__x); } 
# 207
inline long double cos(long double __x) 
# 208
{ return __builtin_cosl(__x); } 
# 211
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 215
cos(_Tp __x) 
# 216
{ return __builtin_cos(__x); } 
# 218
using ::cosh;
# 222
inline float cosh(float __x) 
# 223
{ return __builtin_coshf(__x); } 
# 226
inline long double cosh(long double __x) 
# 227
{ return __builtin_coshl(__x); } 
# 230
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 234
cosh(_Tp __x) 
# 235
{ return __builtin_cosh(__x); } 
# 237
using ::exp;
# 241
inline float exp(float __x) 
# 242
{ return __builtin_expf(__x); } 
# 245
inline long double exp(long double __x) 
# 246
{ return __builtin_expl(__x); } 
# 249
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 253
exp(_Tp __x) 
# 254
{ return __builtin_exp(__x); } 
# 256
using ::fabs;
# 260
inline float fabs(float __x) 
# 261
{ return __builtin_fabsf(__x); } 
# 264
inline long double fabs(long double __x) 
# 265
{ return __builtin_fabsl(__x); } 
# 268
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 272
fabs(_Tp __x) 
# 273
{ return __builtin_fabs(__x); } 
# 275
using ::floor;
# 279
inline float floor(float __x) 
# 280
{ return __builtin_floorf(__x); } 
# 283
inline long double floor(long double __x) 
# 284
{ return __builtin_floorl(__x); } 
# 287
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 291
floor(_Tp __x) 
# 292
{ return __builtin_floor(__x); } 
# 294
using ::fmod;
# 298
inline float fmod(float __x, float __y) 
# 299
{ return __builtin_fmodf(__x, __y); } 
# 302
inline long double fmod(long double __x, long double __y) 
# 303
{ return __builtin_fmodl(__x, __y); } 
# 306
template< class _Tp, class _Up> inline typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 309
fmod(_Tp __x, _Up __y) 
# 310
{ 
# 311
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 312
return fmod((__type)__x, (__type)__y); 
# 313
} 
# 315
using ::frexp;
# 319
inline float frexp(float __x, int *__exp) 
# 320
{ return __builtin_frexpf(__x, __exp); } 
# 323
inline long double frexp(long double __x, int *__exp) 
# 324
{ return __builtin_frexpl(__x, __exp); } 
# 327
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 331
frexp(_Tp __x, int *__exp) 
# 332
{ return __builtin_frexp(__x, __exp); } 
# 334
using ::ldexp;
# 338
inline float ldexp(float __x, int __exp) 
# 339
{ return __builtin_ldexpf(__x, __exp); } 
# 342
inline long double ldexp(long double __x, int __exp) 
# 343
{ return __builtin_ldexpl(__x, __exp); } 
# 346
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 350
ldexp(_Tp __x, int __exp) 
# 351
{ return __builtin_ldexp(__x, __exp); } 
# 353
using ::log;
# 357
inline float log(float __x) 
# 358
{ return __builtin_logf(__x); } 
# 361
inline long double log(long double __x) 
# 362
{ return __builtin_logl(__x); } 
# 365
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 369
log(_Tp __x) 
# 370
{ return __builtin_log(__x); } 
# 372
using ::log10;
# 376
inline float log10(float __x) 
# 377
{ return __builtin_log10f(__x); } 
# 380
inline long double log10(long double __x) 
# 381
{ return __builtin_log10l(__x); } 
# 384
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 388
log10(_Tp __x) 
# 389
{ return __builtin_log10(__x); } 
# 391
using ::modf;
# 395
inline float modf(float __x, float *__iptr) 
# 396
{ return __builtin_modff(__x, __iptr); } 
# 399
inline long double modf(long double __x, long double *__iptr) 
# 400
{ return __builtin_modfl(__x, __iptr); } 
# 403
using ::pow;
# 407
inline float pow(float __x, float __y) 
# 408
{ return __builtin_powf(__x, __y); } 
# 411
inline long double pow(long double __x, long double __y) 
# 412
{ return __builtin_powl(__x, __y); } 
# 418
inline double pow(double __x, int __i) 
# 419
{ return __builtin_powi(__x, __i); } 
# 422
inline float pow(float __x, int __n) 
# 423
{ return __builtin_powif(__x, __n); } 
# 426
inline long double pow(long double __x, int __n) 
# 427
{ return __builtin_powil(__x, __n); } 
# 431
template< class _Tp, class _Up> inline typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type 
# 434
pow(_Tp __x, _Up __y) 
# 435
{ 
# 436
typedef typename __gnu_cxx::__promote_2< _Tp, _Up> ::__type __type; 
# 437
return pow((__type)__x, (__type)__y); 
# 438
} 
# 440
using ::sin;
# 444
inline float sin(float __x) 
# 445
{ return __builtin_sinf(__x); } 
# 448
inline long double sin(long double __x) 
# 449
{ return __builtin_sinl(__x); } 
# 452
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 456
sin(_Tp __x) 
# 457
{ return __builtin_sin(__x); } 
# 459
using ::sinh;
# 463
inline float sinh(float __x) 
# 464
{ return __builtin_sinhf(__x); } 
# 467
inline long double sinh(long double __x) 
# 468
{ return __builtin_sinhl(__x); } 
# 471
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 475
sinh(_Tp __x) 
# 476
{ return __builtin_sinh(__x); } 
# 478
using ::sqrt;
# 482
inline float sqrt(float __x) 
# 483
{ return __builtin_sqrtf(__x); } 
# 486
inline long double sqrt(long double __x) 
# 487
{ return __builtin_sqrtl(__x); } 
# 490
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 494
sqrt(_Tp __x) 
# 495
{ return __builtin_sqrt(__x); } 
# 497
using ::tan;
# 501
inline float tan(float __x) 
# 502
{ return __builtin_tanf(__x); } 
# 505
inline long double tan(long double __x) 
# 506
{ return __builtin_tanl(__x); } 
# 509
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 513
tan(_Tp __x) 
# 514
{ return __builtin_tan(__x); } 
# 516
using ::tanh;
# 520
inline float tanh(float __x) 
# 521
{ return __builtin_tanhf(__x); } 
# 524
inline long double tanh(long double __x) 
# 525
{ return __builtin_tanhl(__x); } 
# 528
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_integer< _Tp> ::__value, double> ::__type 
# 532
tanh(_Tp __x) 
# 533
{ return __builtin_tanh(__x); } 
# 536
}
# 555
namespace std __attribute((__visibility__("default"))) { 
# 805
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 808
fpclassify(_Tp __f) 
# 809
{ 
# 810
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 811
return __builtin_fpclassify(0, 1, 4, 3, 2, (__type)__f); 
# 813
} 
# 815
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 818
isfinite(_Tp __f) 
# 819
{ 
# 820
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 821
return __builtin_isfinite((__type)__f); 
# 822
} 
# 824
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 827
isinf(_Tp __f) 
# 828
{ 
# 829
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 830
return __builtin_isinf((__type)__f); 
# 831
} 
# 833
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 836
isnan(_Tp __f) 
# 837
{ 
# 838
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 839
return __builtin_isnan((__type)__f); 
# 840
} 
# 842
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 845
isnormal(_Tp __f) 
# 846
{ 
# 847
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 848
return __builtin_isnormal((__type)__f); 
# 849
} 
# 851
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 854
signbit(_Tp __f) 
# 855
{ 
# 856
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 857
return __builtin_signbit((__type)__f); 
# 858
} 
# 860
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 863
isgreater(_Tp __f1, _Tp __f2) 
# 864
{ 
# 865
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 866
return __builtin_isgreater((__type)__f1, (__type)__f2); 
# 867
} 
# 869
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 872
isgreaterequal(_Tp __f1, _Tp __f2) 
# 873
{ 
# 874
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 875
return __builtin_isgreaterequal((__type)__f1, (__type)__f2); 
# 876
} 
# 878
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 881
isless(_Tp __f1, _Tp __f2) 
# 882
{ 
# 883
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 884
return __builtin_isless((__type)__f1, (__type)__f2); 
# 885
} 
# 887
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 890
islessequal(_Tp __f1, _Tp __f2) 
# 891
{ 
# 892
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 893
return __builtin_islessequal((__type)__f1, (__type)__f2); 
# 894
} 
# 896
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 899
islessgreater(_Tp __f1, _Tp __f2) 
# 900
{ 
# 901
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 902
return __builtin_islessgreater((__type)__f1, (__type)__f2); 
# 903
} 
# 905
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_arithmetic< _Tp> ::__value, int> ::__type 
# 908
isunordered(_Tp __f1, _Tp __f2) 
# 909
{ 
# 910
typedef typename __gnu_cxx::__promote< _Tp> ::__type __type; 
# 911
return __builtin_isunordered((__type)__f1, (__type)__f2); 
# 912
} 
# 917
}
# 114 "/usr/include/c++/4.8.2/cstdlib" 3
namespace std __attribute((__visibility__("default"))) { 
# 118
using ::div_t;
# 119
using ::ldiv_t;
# 121
using ::abort;
# 122
using ::abs;
# 123
using ::atexit;
# 129
using ::atof;
# 130
using ::atoi;
# 131
using ::atol;
# 132
using ::bsearch;
# 133
using ::calloc;
# 134
using ::div;
# 135
using ::exit;
# 136
using ::free;
# 137
using ::getenv;
# 138
using ::labs;
# 139
using ::ldiv;
# 140
using ::malloc;
# 142
using ::mblen;
# 143
using ::mbstowcs;
# 144
using ::mbtowc;
# 146
using ::qsort;
# 152
using ::rand;
# 153
using ::realloc;
# 154
using ::srand;
# 155
using ::strtod;
# 156
using ::strtol;
# 157
using ::strtoul;
# 158
using ::system;
# 160
using ::wcstombs;
# 161
using ::wctomb;
# 166
inline long abs(long __i) { return __builtin_labs(__i); } 
# 169
inline ldiv_t div(long __i, long __j) { return ldiv(__i, __j); } 
# 174
inline long long abs(long long __x) { return __builtin_llabs(__x); } 
# 179
inline __int128_t abs(__int128_t __x) { return (__x >= (0)) ? __x : (-__x); } 
# 183
}
# 196
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 201
using ::lldiv_t;
# 207
using ::_Exit;
# 211
using ::llabs;
# 214
inline lldiv_t div(long long __n, long long __d) 
# 215
{ lldiv_t __q; (__q.quot) = (__n / __d); (__q.rem) = (__n % __d); return __q; } 
# 217
using ::lldiv;
# 228
using ::atoll;
# 229
using ::strtoll;
# 230
using ::strtoull;
# 232
using ::strtof;
# 233
using ::strtold;
# 236
}
# 238
namespace std { 
# 241
using __gnu_cxx::lldiv_t;
# 243
using __gnu_cxx::_Exit;
# 245
using __gnu_cxx::llabs;
# 246
using __gnu_cxx::div;
# 247
using __gnu_cxx::lldiv;
# 249
using __gnu_cxx::atoll;
# 250
using __gnu_cxx::strtof;
# 251
using __gnu_cxx::strtoll;
# 252
using __gnu_cxx::strtoull;
# 253
using __gnu_cxx::strtold;
# 254
}
# 8925 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/math_functions.h"
__attribute((always_inline)) inline int signbit(float x); 
# 8929
__attribute((always_inline)) inline int signbit(double x); 
# 8931
__attribute((always_inline)) inline int signbit(long double x); 
# 8933
__attribute((always_inline)) inline int isfinite(float x); 
# 8937
__attribute((always_inline)) inline int isfinite(double x); 
# 8939
__attribute((always_inline)) inline int isfinite(long double x); 
# 8941
__attribute((always_inline)) inline int isnan(float x); 
# 8945
extern "C" __attribute((always_inline)) inline int isnan(double x) throw(); 
# 8947
__attribute((always_inline)) inline int isnan(long double x); 
# 8949
__attribute((always_inline)) inline int isinf(float x); 
# 8953
extern "C" __attribute((always_inline)) inline int isinf(double x) throw(); 
# 8955
__attribute((always_inline)) inline int isinf(long double x); 
# 9002
namespace std { 
# 9004
template< class T> extern T __pow_helper(T, int); 
# 9005
template< class T> extern T __cmath_power(T, unsigned); 
# 9006
}
# 9008
using std::abs;
# 9009
using std::fabs;
# 9010
using std::ceil;
# 9011
using std::floor;
# 9012
using std::sqrt;
# 9013
using std::pow;
# 9014
using std::log;
# 9015
using std::log10;
# 9016
using std::fmod;
# 9017
using std::modf;
# 9018
using std::exp;
# 9019
using std::frexp;
# 9020
using std::ldexp;
# 9021
using std::asin;
# 9022
using std::sin;
# 9023
using std::sinh;
# 9024
using std::acos;
# 9025
using std::cos;
# 9026
using std::cosh;
# 9027
using std::atan;
# 9028
using std::atan2;
# 9029
using std::tan;
# 9030
using std::tanh;
# 9393
namespace std { 
# 9406
extern inline long long abs(long long); 
# 9412
extern inline long abs(long); 
# 9413
extern inline float abs(float); 
# 9414
extern inline double abs(double); 
# 9415
extern inline float fabs(float); 
# 9416
extern inline float ceil(float); 
# 9417
extern inline float floor(float); 
# 9418
extern inline float sqrt(float); 
# 9419
extern inline float pow(float, float); 
# 9428
extern inline float pow(float, int); 
# 9429
extern inline double pow(double, int); 
# 9434
extern inline float log(float); 
# 9435
extern inline float log10(float); 
# 9436
extern inline float fmod(float, float); 
# 9437
extern inline float modf(float, float *); 
# 9438
extern inline float exp(float); 
# 9439
extern inline float frexp(float, int *); 
# 9440
extern inline float ldexp(float, int); 
# 9441
extern inline float asin(float); 
# 9442
extern inline float sin(float); 
# 9443
extern inline float sinh(float); 
# 9444
extern inline float acos(float); 
# 9445
extern inline float cos(float); 
# 9446
extern inline float cosh(float); 
# 9447
extern inline float atan(float); 
# 9448
extern inline float atan2(float, float); 
# 9449
extern inline float tan(float); 
# 9450
extern inline float tanh(float); 
# 9518
}
# 9609
static inline float logb(float a); 
# 9611
static inline int ilogb(float a); 
# 9613
static inline float scalbn(float a, int b); 
# 9615
static inline float scalbln(float a, long b); 
# 9617
static inline float exp2(float a); 
# 9619
static inline float expm1(float a); 
# 9621
static inline float log2(float a); 
# 9623
static inline float log1p(float a); 
# 9625
static inline float acosh(float a); 
# 9627
static inline float asinh(float a); 
# 9629
static inline float atanh(float a); 
# 9631
static inline float hypot(float a, float b); 
# 9633
static inline float norm3d(float a, float b, float c); 
# 9635
static inline float norm4d(float a, float b, float c, float d); 
# 9637
static inline float cbrt(float a); 
# 9639
static inline float erf(float a); 
# 9641
static inline float erfc(float a); 
# 9643
static inline float lgamma(float a); 
# 9645
static inline float tgamma(float a); 
# 9647
static inline float copysign(float a, float b); 
# 9649
static inline float nextafter(float a, float b); 
# 9651
static inline float remainder(float a, float b); 
# 9653
static inline float remquo(float a, float b, int * quo); 
# 9655
static inline float round(float a); 
# 9657
static inline long lround(float a); 
# 9659
static inline long long llround(float a); 
# 9661
static inline float trunc(float a); 
# 9663
static inline float rint(float a); 
# 9665
static inline long lrint(float a); 
# 9667
static inline long long llrint(float a); 
# 9669
static inline float nearbyint(float a); 
# 9671
static inline float fdim(float a, float b); 
# 9673
static inline float fma(float a, float b, float c); 
# 9675
static inline float fmax(float a, float b); 
# 9677
static inline float fmin(float a, float b); 
# 9718
static inline float exp10(float a); 
# 9720
static inline float rsqrt(float a); 
# 9722
static inline float rcbrt(float a); 
# 9724
static inline float sinpi(float a); 
# 9726
static inline float cospi(float a); 
# 9728
static inline void sincospi(float a, float * sptr, float * cptr); 
# 9730
static inline void sincos(float a, float * sptr, float * cptr); 
# 9732
static inline float j0(float a); 
# 9734
static inline float j1(float a); 
# 9736
static inline float jn(int n, float a); 
# 9738
static inline float y0(float a); 
# 9740
static inline float y1(float a); 
# 9742
static inline float yn(int n, float a); 
# 9744
static inline float cyl_bessel_i0(float a); 
# 9746
static inline float cyl_bessel_i1(float a); 
# 9748
static inline float erfinv(float a); 
# 9750
static inline float erfcinv(float a); 
# 9752
static inline float normcdfinv(float a); 
# 9754
static inline float normcdf(float a); 
# 9756
static inline float erfcx(float a); 
# 9758
static inline double copysign(double a, float b); 
# 9760
static inline float copysign(float a, double b); 
# 9762
static inline unsigned min(unsigned a, unsigned b); 
# 9764
static inline unsigned min(int a, unsigned b); 
# 9766
static inline unsigned min(unsigned a, int b); 
# 9768
static inline long min(long a, long b); 
# 9770
static inline unsigned long min(unsigned long a, unsigned long b); 
# 9772
static inline unsigned long min(long a, unsigned long b); 
# 9774
static inline unsigned long min(unsigned long a, long b); 
# 9776
static inline long long min(long long a, long long b); 
# 9778
static inline unsigned long long min(unsigned long long a, unsigned long long b); 
# 9780
static inline unsigned long long min(long long a, unsigned long long b); 
# 9782
static inline unsigned long long min(unsigned long long a, long long b); 
# 9784
static inline float min(float a, float b); 
# 9786
static inline double min(double a, double b); 
# 9788
static inline double min(float a, double b); 
# 9790
static inline double min(double a, float b); 
# 9792
static inline unsigned max(unsigned a, unsigned b); 
# 9794
static inline unsigned max(int a, unsigned b); 
# 9796
static inline unsigned max(unsigned a, int b); 
# 9798
static inline long max(long a, long b); 
# 9800
static inline unsigned long max(unsigned long a, unsigned long b); 
# 9802
static inline unsigned long max(long a, unsigned long b); 
# 9804
static inline unsigned long max(unsigned long a, long b); 
# 9806
static inline long long max(long long a, long long b); 
# 9808
static inline unsigned long long max(unsigned long long a, unsigned long long b); 
# 9810
static inline unsigned long long max(long long a, unsigned long long b); 
# 9812
static inline unsigned long long max(unsigned long long a, long long b); 
# 9814
static inline float max(float a, float b); 
# 9816
static inline double max(double a, double b); 
# 9818
static inline double max(float a, double b); 
# 9820
static inline double max(double a, float b); 
# 248 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/math_functions.hpp"
__attribute((always_inline)) inline int signbit(float x) { return __signbitf(x); } 
# 252
__attribute((always_inline)) inline int signbit(double x) { return __signbit(x); } 
# 254
__attribute((always_inline)) inline int signbit(long double x) { return __signbitl(x); } 
# 265
__attribute((always_inline)) inline int isfinite(float x) { return __finitef(x); } 
# 280
__attribute((always_inline)) inline int isfinite(double x) { return __finite(x); } 
# 293
__attribute((always_inline)) inline int isfinite(long double x) { return __finitel(x); } 
# 296
__attribute((always_inline)) inline int isnan(float x) { return __isnanf(x); } 
# 300
extern "C" __attribute((always_inline)) inline int isnan(double x) throw() { return __isnan(x); } 
# 302
__attribute((always_inline)) inline int isnan(long double x) { return __isnanl(x); } 
# 304
__attribute((always_inline)) inline int isinf(float x) { return __isinff(x); } 
# 308
extern "C" __attribute((always_inline)) inline int isinf(double x) throw() { return __isinf(x); } 
# 310
__attribute((always_inline)) inline int isinf(long double x) { return __isinfl(x); } 
# 503
static inline float logb(float a) 
# 504
{ 
# 505
return logbf(a); 
# 506
} 
# 508
static inline int ilogb(float a) 
# 509
{ 
# 510
return ilogbf(a); 
# 511
} 
# 513
static inline float scalbn(float a, int b) 
# 514
{ 
# 515
return scalbnf(a, b); 
# 516
} 
# 518
static inline float scalbln(float a, long b) 
# 519
{ 
# 520
return scalblnf(a, b); 
# 521
} 
# 523
static inline float exp2(float a) 
# 524
{ 
# 525
return exp2f(a); 
# 526
} 
# 528
static inline float expm1(float a) 
# 529
{ 
# 530
return expm1f(a); 
# 531
} 
# 533
static inline float log2(float a) 
# 534
{ 
# 535
return log2f(a); 
# 536
} 
# 538
static inline float log1p(float a) 
# 539
{ 
# 540
return log1pf(a); 
# 541
} 
# 543
static inline float acosh(float a) 
# 544
{ 
# 545
return acoshf(a); 
# 546
} 
# 548
static inline float asinh(float a) 
# 549
{ 
# 550
return asinhf(a); 
# 551
} 
# 553
static inline float atanh(float a) 
# 554
{ 
# 555
return atanhf(a); 
# 556
} 
# 558
static inline float hypot(float a, float b) 
# 559
{ 
# 560
return hypotf(a, b); 
# 561
} 
# 563
static inline float norm3d(float a, float b, float c) 
# 564
{ 
# 565
return norm3df(a, b, c); 
# 566
} 
# 568
static inline float norm4d(float a, float b, float c, float d) 
# 569
{ 
# 570
return norm4df(a, b, c, d); 
# 571
} 
# 573
static inline float cbrt(float a) 
# 574
{ 
# 575
return cbrtf(a); 
# 576
} 
# 578
static inline float erf(float a) 
# 579
{ 
# 580
return erff(a); 
# 581
} 
# 583
static inline float erfc(float a) 
# 584
{ 
# 585
return erfcf(a); 
# 586
} 
# 588
static inline float lgamma(float a) 
# 589
{ 
# 590
return lgammaf(a); 
# 591
} 
# 593
static inline float tgamma(float a) 
# 594
{ 
# 595
return tgammaf(a); 
# 596
} 
# 598
static inline float copysign(float a, float b) 
# 599
{ 
# 600
return copysignf(a, b); 
# 601
} 
# 603
static inline float nextafter(float a, float b) 
# 604
{ 
# 605
return nextafterf(a, b); 
# 606
} 
# 608
static inline float remainder(float a, float b) 
# 609
{ 
# 610
return remainderf(a, b); 
# 611
} 
# 613
static inline float remquo(float a, float b, int *quo) 
# 614
{ 
# 615
return remquof(a, b, quo); 
# 616
} 
# 618
static inline float round(float a) 
# 619
{ 
# 620
return roundf(a); 
# 621
} 
# 623
static inline long lround(float a) 
# 624
{ 
# 625
return lroundf(a); 
# 626
} 
# 628
static inline long long llround(float a) 
# 629
{ 
# 630
return llroundf(a); 
# 631
} 
# 633
static inline float trunc(float a) 
# 634
{ 
# 635
return truncf(a); 
# 636
} 
# 638
static inline float rint(float a) 
# 639
{ 
# 640
return rintf(a); 
# 641
} 
# 643
static inline long lrint(float a) 
# 644
{ 
# 645
return lrintf(a); 
# 646
} 
# 648
static inline long long llrint(float a) 
# 649
{ 
# 650
return llrintf(a); 
# 651
} 
# 653
static inline float nearbyint(float a) 
# 654
{ 
# 655
return nearbyintf(a); 
# 656
} 
# 658
static inline float fdim(float a, float b) 
# 659
{ 
# 660
return fdimf(a, b); 
# 661
} 
# 663
static inline float fma(float a, float b, float c) 
# 664
{ 
# 665
return fmaf(a, b, c); 
# 666
} 
# 668
static inline float fmax(float a, float b) 
# 669
{ 
# 670
return fmaxf(a, b); 
# 671
} 
# 673
static inline float fmin(float a, float b) 
# 674
{ 
# 675
return fminf(a, b); 
# 676
} 
# 681
static inline float exp10(float a) 
# 682
{ 
# 683
return exp10f(a); 
# 684
} 
# 686
static inline float rsqrt(float a) 
# 687
{ 
# 688
return rsqrtf(a); 
# 689
} 
# 691
static inline float rcbrt(float a) 
# 692
{ 
# 693
return rcbrtf(a); 
# 694
} 
# 696
static inline float sinpi(float a) 
# 697
{ 
# 698
return sinpif(a); 
# 699
} 
# 701
static inline float cospi(float a) 
# 702
{ 
# 703
return cospif(a); 
# 704
} 
# 706
static inline void sincospi(float a, float *sptr, float *cptr) 
# 707
{ 
# 708
sincospif(a, sptr, cptr); 
# 709
} 
# 711
static inline void sincos(float a, float *sptr, float *cptr) 
# 712
{ 
# 713
sincosf(a, sptr, cptr); 
# 714
} 
# 716
static inline float j0(float a) 
# 717
{ 
# 718
return j0f(a); 
# 719
} 
# 721
static inline float j1(float a) 
# 722
{ 
# 723
return j1f(a); 
# 724
} 
# 726
static inline float jn(int n, float a) 
# 727
{ 
# 728
return jnf(n, a); 
# 729
} 
# 731
static inline float y0(float a) 
# 732
{ 
# 733
return y0f(a); 
# 734
} 
# 736
static inline float y1(float a) 
# 737
{ 
# 738
return y1f(a); 
# 739
} 
# 741
static inline float yn(int n, float a) 
# 742
{ 
# 743
return ynf(n, a); 
# 744
} 
# 746
static inline float cyl_bessel_i0(float a) 
# 747
{ 
# 748
return cyl_bessel_i0f(a); 
# 749
} 
# 751
static inline float cyl_bessel_i1(float a) 
# 752
{ 
# 753
return cyl_bessel_i1f(a); 
# 754
} 
# 756
static inline float erfinv(float a) 
# 757
{ 
# 758
return erfinvf(a); 
# 759
} 
# 761
static inline float erfcinv(float a) 
# 762
{ 
# 763
return erfcinvf(a); 
# 764
} 
# 766
static inline float normcdfinv(float a) 
# 767
{ 
# 768
return normcdfinvf(a); 
# 769
} 
# 771
static inline float normcdf(float a) 
# 772
{ 
# 773
return normcdff(a); 
# 774
} 
# 776
static inline float erfcx(float a) 
# 777
{ 
# 778
return erfcxf(a); 
# 779
} 
# 781
static inline double copysign(double a, float b) 
# 782
{ 
# 783
return copysign(a, (double)b); 
# 784
} 
# 786
static inline float copysign(float a, double b) 
# 787
{ 
# 788
return copysignf(a, (float)b); 
# 789
} 
# 791
static inline unsigned min(unsigned a, unsigned b) 
# 792
{ 
# 793
return umin(a, b); 
# 794
} 
# 796
static inline unsigned min(int a, unsigned b) 
# 797
{ 
# 798
return umin((unsigned)a, b); 
# 799
} 
# 801
static inline unsigned min(unsigned a, int b) 
# 802
{ 
# 803
return umin(a, (unsigned)b); 
# 804
} 
# 806
static inline long min(long a, long b) 
# 807
{ 
# 813
if (sizeof(long) == sizeof(int)) { 
# 817
return (long)min((int)a, (int)b); 
# 818
} else { 
# 819
return (long)llmin((long long)a, (long long)b); 
# 820
}  
# 821
} 
# 823
static inline unsigned long min(unsigned long a, unsigned long b) 
# 824
{ 
# 828
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 832
return (unsigned long)umin((unsigned)a, (unsigned)b); 
# 833
} else { 
# 834
return (unsigned long)ullmin((unsigned long long)a, (unsigned long long)b); 
# 835
}  
# 836
} 
# 838
static inline unsigned long min(long a, unsigned long b) 
# 839
{ 
# 843
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 847
return (unsigned long)umin((unsigned)a, (unsigned)b); 
# 848
} else { 
# 849
return (unsigned long)ullmin((unsigned long long)a, (unsigned long long)b); 
# 850
}  
# 851
} 
# 853
static inline unsigned long min(unsigned long a, long b) 
# 854
{ 
# 858
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 862
return (unsigned long)umin((unsigned)a, (unsigned)b); 
# 863
} else { 
# 864
return (unsigned long)ullmin((unsigned long long)a, (unsigned long long)b); 
# 865
}  
# 866
} 
# 868
static inline long long min(long long a, long long b) 
# 869
{ 
# 870
return llmin(a, b); 
# 871
} 
# 873
static inline unsigned long long min(unsigned long long a, unsigned long long b) 
# 874
{ 
# 875
return ullmin(a, b); 
# 876
} 
# 878
static inline unsigned long long min(long long a, unsigned long long b) 
# 879
{ 
# 880
return ullmin((unsigned long long)a, b); 
# 881
} 
# 883
static inline unsigned long long min(unsigned long long a, long long b) 
# 884
{ 
# 885
return ullmin(a, (unsigned long long)b); 
# 886
} 
# 888
static inline float min(float a, float b) 
# 889
{ 
# 890
return fminf(a, b); 
# 891
} 
# 893
static inline double min(double a, double b) 
# 894
{ 
# 895
return fmin(a, b); 
# 896
} 
# 898
static inline double min(float a, double b) 
# 899
{ 
# 900
return fmin((double)a, b); 
# 901
} 
# 903
static inline double min(double a, float b) 
# 904
{ 
# 905
return fmin(a, (double)b); 
# 906
} 
# 908
static inline unsigned max(unsigned a, unsigned b) 
# 909
{ 
# 910
return umax(a, b); 
# 911
} 
# 913
static inline unsigned max(int a, unsigned b) 
# 914
{ 
# 915
return umax((unsigned)a, b); 
# 916
} 
# 918
static inline unsigned max(unsigned a, int b) 
# 919
{ 
# 920
return umax(a, (unsigned)b); 
# 921
} 
# 923
static inline long max(long a, long b) 
# 924
{ 
# 929
if (sizeof(long) == sizeof(int)) { 
# 933
return (long)max((int)a, (int)b); 
# 934
} else { 
# 935
return (long)llmax((long long)a, (long long)b); 
# 936
}  
# 937
} 
# 939
static inline unsigned long max(unsigned long a, unsigned long b) 
# 940
{ 
# 944
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 948
return (unsigned long)umax((unsigned)a, (unsigned)b); 
# 949
} else { 
# 950
return (unsigned long)ullmax((unsigned long long)a, (unsigned long long)b); 
# 951
}  
# 952
} 
# 954
static inline unsigned long max(long a, unsigned long b) 
# 955
{ 
# 959
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 963
return (unsigned long)umax((unsigned)a, (unsigned)b); 
# 964
} else { 
# 965
return (unsigned long)ullmax((unsigned long long)a, (unsigned long long)b); 
# 966
}  
# 967
} 
# 969
static inline unsigned long max(unsigned long a, long b) 
# 970
{ 
# 974
if (sizeof(unsigned long) == sizeof(unsigned)) { 
# 978
return (unsigned long)umax((unsigned)a, (unsigned)b); 
# 979
} else { 
# 980
return (unsigned long)ullmax((unsigned long long)a, (unsigned long long)b); 
# 981
}  
# 982
} 
# 984
static inline long long max(long long a, long long b) 
# 985
{ 
# 986
return llmax(a, b); 
# 987
} 
# 989
static inline unsigned long long max(unsigned long long a, unsigned long long b) 
# 990
{ 
# 991
return ullmax(a, b); 
# 992
} 
# 994
static inline unsigned long long max(long long a, unsigned long long b) 
# 995
{ 
# 996
return ullmax((unsigned long long)a, b); 
# 997
} 
# 999
static inline unsigned long long max(unsigned long long a, long long b) 
# 1000
{ 
# 1001
return ullmax(a, (unsigned long long)b); 
# 1002
} 
# 1004
static inline float max(float a, float b) 
# 1005
{ 
# 1006
return fmaxf(a, b); 
# 1007
} 
# 1009
static inline double max(double a, double b) 
# 1010
{ 
# 1011
return fmax(a, b); 
# 1012
} 
# 1014
static inline double max(float a, double b) 
# 1015
{ 
# 1016
return fmax((double)a, b); 
# 1017
} 
# 1019
static inline double max(double a, float b) 
# 1020
{ 
# 1021
return fmax(a, (double)b); 
# 1022
} 
# 1033
extern "C" inline int min(int a, int b) 
# 1034
{ 
# 1035
return (a < b) ? a : b; 
# 1036
} 
# 1038
extern "C" inline unsigned umin(unsigned a, unsigned b) 
# 1039
{ 
# 1040
return (a < b) ? a : b; 
# 1041
} 
# 1043
extern "C" inline long long llmin(long long a, long long b) 
# 1044
{ 
# 1045
return (a < b) ? a : b; 
# 1046
} 
# 1048
extern "C" inline unsigned long long ullmin(unsigned long long a, unsigned long long 
# 1049
b) 
# 1050
{ 
# 1051
return (a < b) ? a : b; 
# 1052
} 
# 1054
extern "C" inline int max(int a, int b) 
# 1055
{ 
# 1056
return (a > b) ? a : b; 
# 1057
} 
# 1059
extern "C" inline unsigned umax(unsigned a, unsigned b) 
# 1060
{ 
# 1061
return (a > b) ? a : b; 
# 1062
} 
# 1064
extern "C" inline long long llmax(long long a, long long b) 
# 1065
{ 
# 1066
return (a > b) ? a : b; 
# 1067
} 
# 1069
extern "C" inline unsigned long long ullmax(unsigned long long a, unsigned long long 
# 1070
b) 
# 1071
{ 
# 1072
return (a > b) ? a : b; 
# 1073
} 
# 77 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda_surface_types.h"
template< class T, int dim = 1> 
# 78
struct surface : public surfaceReference { 
# 81
surface() 
# 82
{ 
# 83
(surfaceReference::channelDesc) = cudaCreateChannelDesc< T> (); 
# 84
} 
# 86
surface(cudaChannelFormatDesc desc) 
# 87
{ 
# 88
(surfaceReference::channelDesc) = desc; 
# 89
} 
# 91
}; 
# 93
template< int dim> 
# 94
struct surface< void, dim>  : public surfaceReference { 
# 97
surface() 
# 98
{ 
# 99
(surfaceReference::channelDesc) = cudaCreateChannelDesc< void> (); 
# 100
} 
# 102
}; 
# 77 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda_texture_types.h"
template< class T, int texType = 1, cudaTextureReadMode mode = cudaReadModeElementType> 
# 78
struct texture : public textureReference { 
# 81
texture(int norm = 0, cudaTextureFilterMode 
# 82
fMode = cudaFilterModePoint, cudaTextureAddressMode 
# 83
aMode = cudaAddressModeClamp) 
# 84
{ 
# 85
(textureReference::normalized) = norm; 
# 86
(textureReference::filterMode) = fMode; 
# 87
((textureReference::addressMode)[0]) = aMode; 
# 88
((textureReference::addressMode)[1]) = aMode; 
# 89
((textureReference::addressMode)[2]) = aMode; 
# 90
(textureReference::channelDesc) = cudaCreateChannelDesc< T> (); 
# 91
(textureReference::sRGB) = 0; 
# 92
} 
# 94
texture(int norm, cudaTextureFilterMode 
# 95
fMode, cudaTextureAddressMode 
# 96
aMode, cudaChannelFormatDesc 
# 97
desc) 
# 98
{ 
# 99
(textureReference::normalized) = norm; 
# 100
(textureReference::filterMode) = fMode; 
# 101
((textureReference::addressMode)[0]) = aMode; 
# 102
((textureReference::addressMode)[1]) = aMode; 
# 103
((textureReference::addressMode)[2]) = aMode; 
# 104
(textureReference::channelDesc) = desc; 
# 105
(textureReference::sRGB) = 0; 
# 106
} 
# 108
}; 
# 90 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.h"
extern "C" {
# 3230
}
# 3238
__attribute__((unused)) static inline int mulhi(int a, int b); 
# 3240
__attribute__((unused)) static inline unsigned mulhi(unsigned a, unsigned b); 
# 3242
__attribute__((unused)) static inline unsigned mulhi(int a, unsigned b); 
# 3244
__attribute__((unused)) static inline unsigned mulhi(unsigned a, int b); 
# 3246
__attribute__((unused)) static inline long long mul64hi(long long a, long long b); 
# 3248
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b); 
# 3250
__attribute__((unused)) static inline unsigned long long mul64hi(long long a, unsigned long long b); 
# 3252
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, long long b); 
# 3254
__attribute__((unused)) static inline int float_as_int(float a); 
# 3256
__attribute__((unused)) static inline float int_as_float(int a); 
# 3258
__attribute__((unused)) static inline unsigned float_as_uint(float a); 
# 3260
__attribute__((unused)) static inline float uint_as_float(unsigned a); 
# 3262
__attribute__((unused)) static inline float saturate(float a); 
# 3264
__attribute__((unused)) static inline int mul24(int a, int b); 
# 3266
__attribute__((unused)) static inline unsigned umul24(unsigned a, unsigned b); 
# 3268
__attribute((deprecated("Please use __trap() instead."))) __attribute__((unused)) static inline void trap(); 
# 3271
__attribute((deprecated("Please use __brkpt() instead."))) __attribute__((unused)) static inline void brkpt(int c = 0); 
# 3273
__attribute((deprecated("Please use __syncthreads() instead."))) __attribute__((unused)) static inline void syncthreads(); 
# 3275
__attribute((deprecated("Please use __prof_trigger() instead."))) __attribute__((unused)) static inline void prof_trigger(int e); 
# 3277
__attribute((deprecated("Please use __threadfence() instead."))) __attribute__((unused)) static inline void threadfence(bool global = true); 
# 3279
__attribute__((unused)) static inline int float2int(float a, cudaRoundMode mode = cudaRoundZero); 
# 3281
__attribute__((unused)) static inline unsigned float2uint(float a, cudaRoundMode mode = cudaRoundZero); 
# 3283
__attribute__((unused)) static inline float int2float(int a, cudaRoundMode mode = cudaRoundNearest); 
# 3285
__attribute__((unused)) static inline float uint2float(unsigned a, cudaRoundMode mode = cudaRoundNearest); 
# 83 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline int mulhi(int a, int b) 
# 84
{int volatile ___ = 1;(void)a;(void)b;
# 86
::exit(___);}
#if 0
# 84
{ 
# 85
return __mulhi(a, b); 
# 86
} 
#endif
# 88 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, unsigned b) 
# 89
{int volatile ___ = 1;(void)a;(void)b;
# 91
::exit(___);}
#if 0
# 89
{ 
# 90
return __umulhi(a, b); 
# 91
} 
#endif
# 93 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned mulhi(int a, unsigned b) 
# 94
{int volatile ___ = 1;(void)a;(void)b;
# 96
::exit(___);}
#if 0
# 94
{ 
# 95
return __umulhi((unsigned)a, b); 
# 96
} 
#endif
# 98 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned mulhi(unsigned a, int b) 
# 99
{int volatile ___ = 1;(void)a;(void)b;
# 101
::exit(___);}
#if 0
# 99
{ 
# 100
return __umulhi(a, (unsigned)b); 
# 101
} 
#endif
# 103 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline long long mul64hi(long long a, long long b) 
# 104
{int volatile ___ = 1;(void)a;(void)b;
# 106
::exit(___);}
#if 0
# 104
{ 
# 105
return __mul64hi(a, b); 
# 106
} 
#endif
# 108 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, unsigned long long b) 
# 109
{int volatile ___ = 1;(void)a;(void)b;
# 111
::exit(___);}
#if 0
# 109
{ 
# 110
return __umul64hi(a, b); 
# 111
} 
#endif
# 113 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned long long mul64hi(long long a, unsigned long long b) 
# 114
{int volatile ___ = 1;(void)a;(void)b;
# 116
::exit(___);}
#if 0
# 114
{ 
# 115
return __umul64hi((unsigned long long)a, b); 
# 116
} 
#endif
# 118 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned long long mul64hi(unsigned long long a, long long b) 
# 119
{int volatile ___ = 1;(void)a;(void)b;
# 121
::exit(___);}
#if 0
# 119
{ 
# 120
return __umul64hi(a, (unsigned long long)b); 
# 121
} 
#endif
# 123 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline int float_as_int(float a) 
# 124
{int volatile ___ = 1;(void)a;
# 126
::exit(___);}
#if 0
# 124
{ 
# 125
return __float_as_int(a); 
# 126
} 
#endif
# 128 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline float int_as_float(int a) 
# 129
{int volatile ___ = 1;(void)a;
# 131
::exit(___);}
#if 0
# 129
{ 
# 130
return __int_as_float(a); 
# 131
} 
#endif
# 133 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned float_as_uint(float a) 
# 134
{int volatile ___ = 1;(void)a;
# 136
::exit(___);}
#if 0
# 134
{ 
# 135
return __float_as_uint(a); 
# 136
} 
#endif
# 138 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline float uint_as_float(unsigned a) 
# 139
{int volatile ___ = 1;(void)a;
# 141
::exit(___);}
#if 0
# 139
{ 
# 140
return __uint_as_float(a); 
# 141
} 
#endif
# 142 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline float saturate(float a) 
# 143
{int volatile ___ = 1;(void)a;
# 145
::exit(___);}
#if 0
# 143
{ 
# 144
return __saturatef(a); 
# 145
} 
#endif
# 147 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline int mul24(int a, int b) 
# 148
{int volatile ___ = 1;(void)a;(void)b;
# 150
::exit(___);}
#if 0
# 148
{ 
# 149
return __mul24(a, b); 
# 150
} 
#endif
# 152 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned umul24(unsigned a, unsigned b) 
# 153
{int volatile ___ = 1;(void)a;(void)b;
# 155
::exit(___);}
#if 0
# 153
{ 
# 154
return __umul24(a, b); 
# 155
} 
#endif
# 157 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline void trap() 
# 158
{int volatile ___ = 1;
# 160
::exit(___);}
#if 0
# 158
{ 
# 159
__trap(); 
# 160
} 
#endif
# 163 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline void brkpt(int c) 
# 164
{int volatile ___ = 1;(void)c;
# 166
::exit(___);}
#if 0
# 164
{ 
# 165
__brkpt(c); 
# 166
} 
#endif
# 168 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline void syncthreads() 
# 169
{int volatile ___ = 1;
# 171
::exit(___);}
#if 0
# 169
{ 
# 170
__syncthreads(); 
# 171
} 
#endif
# 173 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline void prof_trigger(int e) 
# 174
{int volatile ___ = 1;(void)e;
# 191
::exit(___);}
#if 0
# 174
{ 
# 175
if (e == 0) { __prof_trigger(0); } else { 
# 176
if (e == 1) { __prof_trigger(1); } else { 
# 177
if (e == 2) { __prof_trigger(2); } else { 
# 178
if (e == 3) { __prof_trigger(3); } else { 
# 179
if (e == 4) { __prof_trigger(4); } else { 
# 180
if (e == 5) { __prof_trigger(5); } else { 
# 181
if (e == 6) { __prof_trigger(6); } else { 
# 182
if (e == 7) { __prof_trigger(7); } else { 
# 183
if (e == 8) { __prof_trigger(8); } else { 
# 184
if (e == 9) { __prof_trigger(9); } else { 
# 185
if (e == 10) { __prof_trigger(10); } else { 
# 186
if (e == 11) { __prof_trigger(11); } else { 
# 187
if (e == 12) { __prof_trigger(12); } else { 
# 188
if (e == 13) { __prof_trigger(13); } else { 
# 189
if (e == 14) { __prof_trigger(14); } else { 
# 190
if (e == 15) { __prof_trigger(15); }  }  }  }  }  }  }  }  }  }  }  }  }  }  }  }  
# 191
} 
#endif
# 193 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline void threadfence(bool global) 
# 194
{int volatile ___ = 1;(void)global;
# 196
::exit(___);}
#if 0
# 194
{ 
# 195
global ? __threadfence() : __threadfence_block(); 
# 196
} 
#endif
# 198 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline int float2int(float a, cudaRoundMode mode) 
# 199
{int volatile ___ = 1;(void)a;(void)mode;
# 204
::exit(___);}
#if 0
# 199
{ 
# 200
return (mode == (cudaRoundNearest)) ? __float2int_rn(a) : ((mode == (cudaRoundPosInf)) ? __float2int_ru(a) : ((mode == (cudaRoundMinInf)) ? __float2int_rd(a) : __float2int_rz(a))); 
# 204
} 
#endif
# 206 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline unsigned float2uint(float a, cudaRoundMode mode) 
# 207
{int volatile ___ = 1;(void)a;(void)mode;
# 212
::exit(___);}
#if 0
# 207
{ 
# 208
return (mode == (cudaRoundNearest)) ? __float2uint_rn(a) : ((mode == (cudaRoundPosInf)) ? __float2uint_ru(a) : ((mode == (cudaRoundMinInf)) ? __float2uint_rd(a) : __float2uint_rz(a))); 
# 212
} 
#endif
# 214 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline float int2float(int a, cudaRoundMode mode) 
# 215
{int volatile ___ = 1;(void)a;(void)mode;
# 220
::exit(___);}
#if 0
# 215
{ 
# 216
return (mode == (cudaRoundZero)) ? __int2float_rz(a) : ((mode == (cudaRoundPosInf)) ? __int2float_ru(a) : ((mode == (cudaRoundMinInf)) ? __int2float_rd(a) : __int2float_rn(a))); 
# 220
} 
#endif
# 222 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_functions.hpp"
__attribute__((unused)) static inline float uint2float(unsigned a, cudaRoundMode mode) 
# 223
{int volatile ___ = 1;(void)a;(void)mode;
# 228
::exit(___);}
#if 0
# 223
{ 
# 224
return (mode == (cudaRoundZero)) ? __uint2float_rz(a) : ((mode == (cudaRoundPosInf)) ? __uint2float_ru(a) : ((mode == (cudaRoundMinInf)) ? __uint2float_rd(a) : __uint2float_rn(a))); 
# 228
} 
#endif
# 111 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 111
{ } 
#endif
# 113 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 113
{ } 
#endif
# 115 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicSub(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 115
{ } 
#endif
# 117 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicSub(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 117
{ } 
#endif
# 119 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 119
{ } 
#endif
# 121 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 121
{ } 
#endif
# 123 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 123
{ } 
#endif
# 125 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 125
{ } 
#endif
# 127 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 127
{ } 
#endif
# 129 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 129
{ } 
#endif
# 131 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 131
{ } 
#endif
# 133 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 133
{ } 
#endif
# 135 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 135
{ } 
#endif
# 137 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 137
{ } 
#endif
# 139 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 139
{ } 
#endif
# 141 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 141
{ } 
#endif
# 143 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 143
{ } 
#endif
# 145 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 145
{ } 
#endif
# 147 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 147
{ } 
#endif
# 149 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 149
{ } 
#endif
# 151 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 151
{ } 
#endif
# 164 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
extern "C" {
# 175
}
# 185
__attribute__((unused)) static inline unsigned long long atomicAdd(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 185
{ } 
#endif
# 187 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 187
{ } 
#endif
# 189 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS(unsigned long long *address, unsigned long long compare, unsigned long long val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 189
{ } 
#endif
# 191 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline bool any(bool cond) {int volatile ___ = 1;(void)cond;::exit(___);}
#if 0
# 191
{ } 
#endif
# 193 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_atomic_functions.h"
__attribute__((unused)) static inline bool all(bool cond) {int volatile ___ = 1;(void)cond;::exit(___);}
#if 0
# 193
{ } 
#endif
# 80 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.h"
extern "C" {
# 1134
}
# 1143
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode); 
# 1145
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
# 1147
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
# 1149
__attribute__((unused)) static inline double dsub(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
# 1151
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode = cudaRoundZero); 
# 1153
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero); 
# 1155
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode = cudaRoundZero); 
# 1157
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode = cudaRoundZero); 
# 1159
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode = cudaRoundNearest); 
# 1161
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode = cudaRoundNearest); 
# 1163
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest); 
# 1165
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest); 
# 1167
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest); 
# 85 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double fma(double a, double b, double c, cudaRoundMode mode) 
# 86
{int volatile ___ = 1;(void)a;(void)b;(void)c;(void)mode;
# 91
::exit(___);}
#if 0
# 86
{ 
# 87
return (mode == (cudaRoundZero)) ? __fma_rz(a, b, c) : ((mode == (cudaRoundPosInf)) ? __fma_ru(a, b, c) : ((mode == (cudaRoundMinInf)) ? __fma_rd(a, b, c) : __fma_rn(a, b, c))); 
# 91
} 
#endif
# 93 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double dmul(double a, double b, cudaRoundMode mode) 
# 94
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 99
::exit(___);}
#if 0
# 94
{ 
# 95
return (mode == (cudaRoundZero)) ? __dmul_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dmul_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dmul_rd(a, b) : __dmul_rn(a, b))); 
# 99
} 
#endif
# 101 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double dadd(double a, double b, cudaRoundMode mode) 
# 102
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 107
::exit(___);}
#if 0
# 102
{ 
# 103
return (mode == (cudaRoundZero)) ? __dadd_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dadd_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dadd_rd(a, b) : __dadd_rn(a, b))); 
# 107
} 
#endif
# 109 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double dsub(double a, double b, cudaRoundMode mode) 
# 110
{int volatile ___ = 1;(void)a;(void)b;(void)mode;
# 115
::exit(___);}
#if 0
# 110
{ 
# 111
return (mode == (cudaRoundZero)) ? __dsub_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dsub_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dsub_rd(a, b) : __dsub_rn(a, b))); 
# 115
} 
#endif
# 117 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline int double2int(double a, cudaRoundMode mode) 
# 118
{int volatile ___ = 1;(void)a;(void)mode;
# 123
::exit(___);}
#if 0
# 118
{ 
# 119
return (mode == (cudaRoundNearest)) ? __double2int_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2int_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2int_rd(a) : __double2int_rz(a))); 
# 123
} 
#endif
# 125 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline unsigned double2uint(double a, cudaRoundMode mode) 
# 126
{int volatile ___ = 1;(void)a;(void)mode;
# 131
::exit(___);}
#if 0
# 126
{ 
# 127
return (mode == (cudaRoundNearest)) ? __double2uint_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2uint_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2uint_rd(a) : __double2uint_rz(a))); 
# 131
} 
#endif
# 133 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline long long double2ll(double a, cudaRoundMode mode) 
# 134
{int volatile ___ = 1;(void)a;(void)mode;
# 139
::exit(___);}
#if 0
# 134
{ 
# 135
return (mode == (cudaRoundNearest)) ? __double2ll_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ll_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ll_rd(a) : __double2ll_rz(a))); 
# 139
} 
#endif
# 141 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline unsigned long long double2ull(double a, cudaRoundMode mode) 
# 142
{int volatile ___ = 1;(void)a;(void)mode;
# 147
::exit(___);}
#if 0
# 142
{ 
# 143
return (mode == (cudaRoundNearest)) ? __double2ull_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ull_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ull_rd(a) : __double2ull_rz(a))); 
# 147
} 
#endif
# 149 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double ll2double(long long a, cudaRoundMode mode) 
# 150
{int volatile ___ = 1;(void)a;(void)mode;
# 155
::exit(___);}
#if 0
# 150
{ 
# 151
return (mode == (cudaRoundZero)) ? __ll2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ll2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ll2double_rd(a) : __ll2double_rn(a))); 
# 155
} 
#endif
# 157 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double ull2double(unsigned long long a, cudaRoundMode mode) 
# 158
{int volatile ___ = 1;(void)a;(void)mode;
# 163
::exit(___);}
#if 0
# 158
{ 
# 159
return (mode == (cudaRoundZero)) ? __ull2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ull2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ull2double_rd(a) : __ull2double_rn(a))); 
# 163
} 
#endif
# 165 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double int2double(int a, cudaRoundMode mode) 
# 166
{int volatile ___ = 1;(void)a;(void)mode;
# 168
::exit(___);}
#if 0
# 166
{ 
# 167
return (double)a; 
# 168
} 
#endif
# 170 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double uint2double(unsigned a, cudaRoundMode mode) 
# 171
{int volatile ___ = 1;(void)a;(void)mode;
# 173
::exit(___);}
#if 0
# 171
{ 
# 172
return (double)a; 
# 173
} 
#endif
# 175 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_double_functions.hpp"
__attribute__((unused)) static inline double float2double(float a, cudaRoundMode mode) 
# 176
{int volatile ___ = 1;(void)a;(void)mode;
# 178
::exit(___);}
#if 0
# 176
{ 
# 177
return (double)a; 
# 178
} 
#endif
# 94 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_20_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 94
{ } 
#endif
# 102 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMin(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 102
{ } 
#endif
# 104 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMax(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 104
{ } 
#endif
# 106 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMin(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 106
{ } 
#endif
# 108 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMax(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 108
{ } 
#endif
# 110 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAnd(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 110
{ } 
#endif
# 112 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicOr(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 112
{ } 
#endif
# 114 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicXor(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 114
{ } 
#endif
# 308 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline double atomicAdd(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 308
{ } 
#endif
# 311 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 311
{ } 
#endif
# 314 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicAdd_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 314
{ } 
#endif
# 317 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 317
{ } 
#endif
# 320 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAdd_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 320
{ } 
#endif
# 323 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 323
{ } 
#endif
# 326 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAdd_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 326
{ } 
#endif
# 329 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd_block(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 329
{ } 
#endif
# 332 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline float atomicAdd_system(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 332
{ } 
#endif
# 335 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline double atomicAdd_block(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 335
{ } 
#endif
# 338 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline double atomicAdd_system(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 338
{ } 
#endif
# 341 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 341
{ } 
#endif
# 344 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicExch_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 344
{ } 
#endif
# 347 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 347
{ } 
#endif
# 350 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicExch_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 350
{ } 
#endif
# 353 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 353
{ } 
#endif
# 356 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicExch_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 356
{ } 
#endif
# 359 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch_block(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 359
{ } 
#endif
# 362 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline float atomicExch_system(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 362
{ } 
#endif
# 365 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 365
{ } 
#endif
# 368 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicMin_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 368
{ } 
#endif
# 371 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMin_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 371
{ } 
#endif
# 374 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMin_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 374
{ } 
#endif
# 377 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 377
{ } 
#endif
# 380 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMin_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 380
{ } 
#endif
# 383 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMin_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 383
{ } 
#endif
# 386 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMin_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 386
{ } 
#endif
# 389 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 389
{ } 
#endif
# 392 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicMax_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 392
{ } 
#endif
# 395 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMax_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 395
{ } 
#endif
# 398 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicMax_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 398
{ } 
#endif
# 401 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 401
{ } 
#endif
# 404 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicMax_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 404
{ } 
#endif
# 407 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMax_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 407
{ } 
#endif
# 410 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicMax_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 410
{ } 
#endif
# 413 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 413
{ } 
#endif
# 416 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicInc_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 416
{ } 
#endif
# 419 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 419
{ } 
#endif
# 422 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicDec_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 422
{ } 
#endif
# 425 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS_block(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 425
{ } 
#endif
# 428 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicCAS_system(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 428
{ } 
#endif
# 431 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS_block(unsigned *address, unsigned compare, unsigned 
# 432
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 432
{ } 
#endif
# 435 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicCAS_system(unsigned *address, unsigned compare, unsigned 
# 436
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 436
{ } 
#endif
# 439 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS_block(unsigned long long *address, unsigned long long 
# 440
compare, unsigned long long 
# 441
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 441
{ } 
#endif
# 444 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicCAS_system(unsigned long long *address, unsigned long long 
# 445
compare, unsigned long long 
# 446
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
# 446
{ } 
#endif
# 449 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 449
{ } 
#endif
# 452 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicAnd_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 452
{ } 
#endif
# 455 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicAnd_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 455
{ } 
#endif
# 458 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicAnd_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 458
{ } 
#endif
# 461 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 461
{ } 
#endif
# 464 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicAnd_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 464
{ } 
#endif
# 467 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAnd_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 467
{ } 
#endif
# 470 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicAnd_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 470
{ } 
#endif
# 473 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 473
{ } 
#endif
# 476 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicOr_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 476
{ } 
#endif
# 479 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicOr_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 479
{ } 
#endif
# 482 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicOr_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 482
{ } 
#endif
# 485 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 485
{ } 
#endif
# 488 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicOr_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 488
{ } 
#endif
# 491 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicOr_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 491
{ } 
#endif
# 494 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicOr_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 494
{ } 
#endif
# 497 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 497
{ } 
#endif
# 500 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline int atomicXor_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 500
{ } 
#endif
# 503 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicXor_block(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 503
{ } 
#endif
# 506 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline long long atomicXor_system(long long *address, long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 506
{ } 
#endif
# 509 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 509
{ } 
#endif
# 512 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned atomicXor_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 512
{ } 
#endif
# 515 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicXor_block(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 515
{ } 
#endif
# 518 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_60_atomic_functions.h"
__attribute__((unused)) static inline unsigned long long atomicXor_system(unsigned long long *address, unsigned long long val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
# 518
{ } 
#endif
# 79 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
extern "C" {
# 1466
}
# 1475
__attribute__((unused)) static inline unsigned ballot(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
# 1475
{ } 
#endif
# 1477 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline int syncthreads_count(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
# 1477
{ } 
#endif
# 1479 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_and(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
# 1479
{ } 
#endif
# 1481 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline bool syncthreads_or(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
# 1481
{ } 
#endif
# 1486 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_20_intrinsics.h"
__attribute__((unused)) static inline unsigned __isGlobal(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 1486
{ } 
#endif
# 98 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __shfl(int var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 98
{ } 
#endif
# 100 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __shfl(unsigned var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 100
{ } 
#endif
# 102 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __shfl_up(int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 102
{ } 
#endif
# 103 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __shfl_up(unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 103
{ } 
#endif
# 105 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __shfl_down(int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 105
{ } 
#endif
# 107 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __shfl_down(unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 107
{ } 
#endif
# 109 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline int __shfl_xor(int var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 109
{ } 
#endif
# 111 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned __shfl_xor(unsigned var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 111
{ } 
#endif
# 113 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline float __shfl(float var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 113
{ } 
#endif
# 115 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline float __shfl_up(float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 115
{ } 
#endif
# 117 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline float __shfl_down(float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 117
{ } 
#endif
# 119 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline float __shfl_xor(float var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 119
{ } 
#endif
# 122 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long long __shfl(long long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 122
{ } 
#endif
# 124 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __shfl(unsigned long long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 124
{ } 
#endif
# 126 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long long __shfl_up(long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 126
{ } 
#endif
# 128 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __shfl_up(unsigned long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 128
{ } 
#endif
# 130 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long long __shfl_down(long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 130
{ } 
#endif
# 132 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __shfl_down(unsigned long long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 132
{ } 
#endif
# 134 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long long __shfl_xor(long long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 134
{ } 
#endif
# 136 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __shfl_xor(unsigned long long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 136
{ } 
#endif
# 138 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline double __shfl(double var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 138
{ } 
#endif
# 140 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline double __shfl_up(double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 140
{ } 
#endif
# 142 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline double __shfl_down(double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 142
{ } 
#endif
# 144 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline double __shfl_xor(double var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 144
{ } 
#endif
# 148 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long __shfl(long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 148
{ } 
#endif
# 150 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long __shfl(unsigned long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
# 150
{ } 
#endif
# 152 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long __shfl_up(long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 152
{ } 
#endif
# 154 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long __shfl_up(unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 154
{ } 
#endif
# 156 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long __shfl_down(long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 156
{ } 
#endif
# 158 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long __shfl_down(unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
# 158
{ } 
#endif
# 160 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline long __shfl_xor(long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 160
{ } 
#endif
# 162 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_30_intrinsics.h"
__attribute__((unused)) static inline unsigned long __shfl_xor(unsigned long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
# 162
{ } 
#endif
# 89 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldg(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 89
{ } 
#endif
# 90 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldg(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 90
{ } 
#endif
# 92 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldg(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 92
{ } 
#endif
# 93 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldg(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 93
{ } 
#endif
# 94 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldg(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 94
{ } 
#endif
# 95 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldg(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 95
{ } 
#endif
# 96 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldg(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 96
{ } 
#endif
# 97 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldg(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 97
{ } 
#endif
# 98 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldg(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 98
{ } 
#endif
# 99 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldg(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 99
{ } 
#endif
# 100 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldg(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 100
{ } 
#endif
# 101 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldg(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 101
{ } 
#endif
# 102 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldg(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 102
{ } 
#endif
# 103 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldg(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 103
{ } 
#endif
# 105 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldg(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 105
{ } 
#endif
# 106 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldg(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 106
{ } 
#endif
# 107 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldg(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 107
{ } 
#endif
# 108 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldg(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 108
{ } 
#endif
# 109 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldg(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 109
{ } 
#endif
# 110 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldg(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 110
{ } 
#endif
# 111 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldg(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 111
{ } 
#endif
# 112 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldg(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 112
{ } 
#endif
# 113 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldg(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 113
{ } 
#endif
# 114 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldg(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 114
{ } 
#endif
# 115 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldg(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 115
{ } 
#endif
# 117 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldg(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 117
{ } 
#endif
# 118 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldg(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 118
{ } 
#endif
# 119 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldg(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 119
{ } 
#endif
# 120 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldg(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 120
{ } 
#endif
# 121 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldg(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 121
{ } 
#endif
# 125 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldcg(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 125
{ } 
#endif
# 126 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldcg(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 126
{ } 
#endif
# 128 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldcg(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 128
{ } 
#endif
# 129 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldcg(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 129
{ } 
#endif
# 130 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldcg(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 130
{ } 
#endif
# 131 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldcg(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 131
{ } 
#endif
# 132 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldcg(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 132
{ } 
#endif
# 133 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldcg(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 133
{ } 
#endif
# 134 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldcg(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 134
{ } 
#endif
# 135 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldcg(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 135
{ } 
#endif
# 136 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldcg(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 136
{ } 
#endif
# 137 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldcg(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 137
{ } 
#endif
# 138 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldcg(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 138
{ } 
#endif
# 139 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldcg(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 139
{ } 
#endif
# 141 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldcg(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 141
{ } 
#endif
# 142 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldcg(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 142
{ } 
#endif
# 143 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldcg(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 143
{ } 
#endif
# 144 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldcg(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 144
{ } 
#endif
# 145 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldcg(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 145
{ } 
#endif
# 146 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldcg(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 146
{ } 
#endif
# 147 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldcg(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 147
{ } 
#endif
# 148 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldcg(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 148
{ } 
#endif
# 149 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldcg(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 149
{ } 
#endif
# 150 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldcg(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 150
{ } 
#endif
# 151 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldcg(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 151
{ } 
#endif
# 153 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldcg(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 153
{ } 
#endif
# 154 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldcg(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 154
{ } 
#endif
# 155 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldcg(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 155
{ } 
#endif
# 156 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldcg(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 156
{ } 
#endif
# 157 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldcg(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 157
{ } 
#endif
# 161 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldca(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 161
{ } 
#endif
# 162 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldca(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 162
{ } 
#endif
# 164 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldca(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 164
{ } 
#endif
# 165 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldca(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 165
{ } 
#endif
# 166 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldca(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 166
{ } 
#endif
# 167 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldca(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 167
{ } 
#endif
# 168 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldca(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 168
{ } 
#endif
# 169 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldca(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 169
{ } 
#endif
# 170 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldca(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 170
{ } 
#endif
# 171 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldca(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 171
{ } 
#endif
# 172 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldca(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 172
{ } 
#endif
# 173 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldca(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 173
{ } 
#endif
# 174 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldca(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 174
{ } 
#endif
# 175 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldca(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 175
{ } 
#endif
# 177 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldca(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 177
{ } 
#endif
# 178 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldca(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 178
{ } 
#endif
# 179 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldca(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 179
{ } 
#endif
# 180 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldca(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 180
{ } 
#endif
# 181 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldca(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 181
{ } 
#endif
# 182 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldca(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 182
{ } 
#endif
# 183 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldca(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 183
{ } 
#endif
# 184 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldca(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 184
{ } 
#endif
# 185 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldca(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 185
{ } 
#endif
# 186 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldca(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 186
{ } 
#endif
# 187 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldca(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 187
{ } 
#endif
# 189 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldca(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 189
{ } 
#endif
# 190 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldca(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 190
{ } 
#endif
# 191 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldca(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 191
{ } 
#endif
# 192 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldca(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 192
{ } 
#endif
# 193 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldca(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 193
{ } 
#endif
# 197 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long __ldcs(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 197
{ } 
#endif
# 198 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long __ldcs(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 198
{ } 
#endif
# 200 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char __ldcs(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 200
{ } 
#endif
# 201 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline signed char __ldcs(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 201
{ } 
#endif
# 202 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short __ldcs(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 202
{ } 
#endif
# 203 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int __ldcs(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 203
{ } 
#endif
# 204 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline long long __ldcs(const long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 204
{ } 
#endif
# 205 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char2 __ldcs(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 205
{ } 
#endif
# 206 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline char4 __ldcs(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 206
{ } 
#endif
# 207 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short2 __ldcs(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 207
{ } 
#endif
# 208 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline short4 __ldcs(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 208
{ } 
#endif
# 209 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int2 __ldcs(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 209
{ } 
#endif
# 210 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline int4 __ldcs(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 210
{ } 
#endif
# 211 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline longlong2 __ldcs(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 211
{ } 
#endif
# 213 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned char __ldcs(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 213
{ } 
#endif
# 214 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned short __ldcs(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 214
{ } 
#endif
# 215 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __ldcs(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 215
{ } 
#endif
# 216 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned long long __ldcs(const unsigned long long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 216
{ } 
#endif
# 217 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar2 __ldcs(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 217
{ } 
#endif
# 218 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uchar4 __ldcs(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 218
{ } 
#endif
# 219 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort2 __ldcs(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 219
{ } 
#endif
# 220 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ushort4 __ldcs(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 220
{ } 
#endif
# 221 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint2 __ldcs(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 221
{ } 
#endif
# 222 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline uint4 __ldcs(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 222
{ } 
#endif
# 223 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline ulonglong2 __ldcs(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 223
{ } 
#endif
# 225 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float __ldcs(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 225
{ } 
#endif
# 226 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double __ldcs(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 226
{ } 
#endif
# 227 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float2 __ldcs(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 227
{ } 
#endif
# 228 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline float4 __ldcs(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 228
{ } 
#endif
# 229 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline double2 __ldcs(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
# 229
{ } 
#endif
# 236 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __funnelshift_l(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
# 236
{ } 
#endif
# 237 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __funnelshift_lc(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
# 237
{ } 
#endif
# 240 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __funnelshift_r(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
# 240
{ } 
#endif
# 241 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_32_intrinsics.h"
__attribute__((unused)) static inline unsigned __funnelshift_rc(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
# 241
{ } 
#endif
# 91 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp2a_lo(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 91
{ } 
#endif
# 92 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp2a_lo(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 92
{ } 
#endif
# 94 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp2a_lo(short2 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 94
{ } 
#endif
# 95 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp2a_lo(ushort2 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 95
{ } 
#endif
# 97 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp2a_hi(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 97
{ } 
#endif
# 98 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp2a_hi(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 98
{ } 
#endif
# 100 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp2a_hi(short2 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 100
{ } 
#endif
# 101 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp2a_hi(ushort2 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 101
{ } 
#endif
# 108 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp4a(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 108
{ } 
#endif
# 109 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp4a(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 109
{ } 
#endif
# 111 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline int __dp4a(char4 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 111
{ } 
#endif
# 112 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/sm_61_intrinsics.h"
__attribute__((unused)) static inline unsigned __dp4a(uchar4 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
# 112
{ } 
#endif
# 100 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 101
__attribute((always_inline)) __attribute__((unused)) inline void surf1Dread(T *res, surface< void, 1>  surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 102
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)s;(void)mode;
# 111
::exit(___);}
#if 0
# 102
{ 
# 111
} 
#endif
# 113 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 114
__attribute((always_inline)) __attribute__((unused)) inline T surf1Dread(surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 115
{int volatile ___ = 1;(void)surf;(void)x;(void)mode;
# 123
::exit(___);}
#if 0
# 115
{ 
# 123
} 
#endif
# 125 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 126
__attribute((always_inline)) __attribute__((unused)) inline void surf1Dread(T *res, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 127
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)mode;
# 131
::exit(___);}
#if 0
# 127
{ 
# 131
} 
#endif
# 260 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 261
__attribute((always_inline)) __attribute__((unused)) inline void surf2Dread(T *res, surface< void, 2>  surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 262
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)s;(void)mode;
# 271
::exit(___);}
#if 0
# 262
{ 
# 271
} 
#endif
# 273 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 274
__attribute((always_inline)) __attribute__((unused)) inline T surf2Dread(surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 275
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)mode;
# 283
::exit(___);}
#if 0
# 275
{ 
# 283
} 
#endif
# 285 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 286
__attribute((always_inline)) __attribute__((unused)) inline void surf2Dread(T *res, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 287
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)mode;
# 291
::exit(___);}
#if 0
# 287
{ 
# 291
} 
#endif
# 422 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 423
__attribute((always_inline)) __attribute__((unused)) inline void surf3Dread(T *res, surface< void, 3>  surf, int x, int y, int z, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 424
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)z;(void)s;(void)mode;
# 433
::exit(___);}
#if 0
# 424
{ 
# 433
} 
#endif
# 435 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 436
__attribute((always_inline)) __attribute__((unused)) inline T surf3Dread(surface< void, 3>  surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 437
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 445
::exit(___);}
#if 0
# 437
{ 
# 445
} 
#endif
# 447 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 448
__attribute((always_inline)) __attribute__((unused)) inline void surf3Dread(T *res, surface< void, 3>  surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 449
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 453
::exit(___);}
#if 0
# 449
{ 
# 453
} 
#endif
# 582 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 583
__attribute((always_inline)) __attribute__((unused)) inline void surf1DLayeredread(T *res, surface< void, 241>  surf, int x, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 584
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)layer;(void)s;(void)mode;
# 593
::exit(___);}
#if 0
# 584
{ 
# 593
} 
#endif
# 595 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 596
__attribute((always_inline)) __attribute__((unused)) inline T surf1DLayeredread(surface< void, 241>  surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 597
{int volatile ___ = 1;(void)surf;(void)x;(void)layer;(void)mode;
# 605
::exit(___);}
#if 0
# 597
{ 
# 605
} 
#endif
# 607 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 608
__attribute((always_inline)) __attribute__((unused)) inline void surf1DLayeredread(T *res, surface< void, 241>  surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 609
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)layer;(void)mode;
# 613
::exit(___);}
#if 0
# 609
{ 
# 613
} 
#endif
# 768 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 769
__attribute((always_inline)) __attribute__((unused)) inline void surf2DLayeredread(T *res, surface< void, 242>  surf, int x, int y, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 770
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layer;(void)s;(void)mode;
# 779
::exit(___);}
#if 0
# 770
{ 
# 779
} 
#endif
# 781 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 782
__attribute((always_inline)) __attribute__((unused)) inline T surf2DLayeredread(surface< void, 242>  surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 783
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 791
::exit(___);}
#if 0
# 783
{ 
# 791
} 
#endif
# 793 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 794
__attribute((always_inline)) __attribute__((unused)) inline void surf2DLayeredread(T *res, surface< void, 242>  surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 795
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 799
::exit(___);}
#if 0
# 795
{ 
# 799
} 
#endif
# 919 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 920
__attribute((always_inline)) __attribute__((unused)) inline void surfCubemapread(T *res, surface< void, 12>  surf, int x, int y, int face, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 921
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)face;(void)s;(void)mode;
# 930
::exit(___);}
#if 0
# 921
{ 
# 930
} 
#endif
# 932 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 933
__attribute((always_inline)) __attribute__((unused)) inline T surfCubemapread(surface< void, 12>  surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 934
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 942
::exit(___);}
#if 0
# 934
{ 
# 942
} 
#endif
# 944 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 945
__attribute((always_inline)) __attribute__((unused)) inline void surfCubemapread(T *res, surface< void, 12>  surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 946
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 950
::exit(___);}
#if 0
# 946
{ 
# 950
} 
#endif
# 1070 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1071
__attribute((always_inline)) __attribute__((unused)) inline void surfCubemapLayeredread(T *res, surface< void, 252>  surf, int x, int y, int layerFace, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1072
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layerFace;(void)s;(void)mode;
# 1081
::exit(___);}
#if 0
# 1072
{ 
# 1081
} 
#endif
# 1083 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1084
__attribute((always_inline)) __attribute__((unused)) inline T surfCubemapLayeredread(surface< void, 252>  surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1085
{int volatile ___ = 1;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 1093
::exit(___);}
#if 0
# 1085
{ 
# 1093
} 
#endif
# 1095 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1096
__attribute((always_inline)) __attribute__((unused)) inline void surfCubemapLayeredread(T *res, surface< void, 252>  surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1097
{int volatile ___ = 1;(void)res;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 1101
::exit(___);}
#if 0
# 1097
{ 
# 1101
} 
#endif
# 1232 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1233
__attribute((always_inline)) __attribute__((unused)) inline void surf1Dwrite(T val, surface< void, 1>  surf, int x, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1234
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)s;(void)mode;
# 1254
::exit(___);}
#if 0
# 1234
{ 
# 1254
} 
#endif
# 1256 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1257
__attribute((always_inline)) __attribute__((unused)) inline void surf1Dwrite(T val, surface< void, 1>  surf, int x, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1258
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)mode;
# 1262
::exit(___);}
#if 0
# 1258
{ 
# 1262
} 
#endif
# 1377 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1378
__attribute((always_inline)) __attribute__((unused)) inline void surf2Dwrite(T val, surface< void, 2>  surf, int x, int y, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1379
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)s;(void)mode;
# 1399
::exit(___);}
#if 0
# 1379
{ 
# 1399
} 
#endif
# 1401 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1402
__attribute((always_inline)) __attribute__((unused)) inline void surf2Dwrite(T val, surface< void, 2>  surf, int x, int y, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1403
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)mode;
# 1407
::exit(___);}
#if 0
# 1403
{ 
# 1407
} 
#endif
# 1520 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1521
__attribute((always_inline)) __attribute__((unused)) inline void surf3Dwrite(T val, surface< void, 3>  surf, int x, int y, int z, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1522
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)s;(void)mode;
# 1542
::exit(___);}
#if 0
# 1522
{ 
# 1542
} 
#endif
# 1544 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1545
__attribute((always_inline)) __attribute__((unused)) inline void surf3Dwrite(T val, surface< void, 3>  surf, int x, int y, int z, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1546
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)z;(void)mode;
# 1550
::exit(___);}
#if 0
# 1546
{ 
# 1550
} 
#endif
# 1666 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1667
__attribute((always_inline)) __attribute__((unused)) static inline void surf1DLayeredwrite(T val, surface< void, 241>  surf, int x, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1668
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)s;(void)mode;
# 1688
::exit(___);}
#if 0
# 1668
{ 
# 1688
} 
#endif
# 1690 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1691
__attribute((always_inline)) __attribute__((unused)) static inline void surf1DLayeredwrite(T val, surface< void, 241>  surf, int x, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1692
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)layer;(void)mode;
# 1696
::exit(___);}
#if 0
# 1692
{ 
# 1696
} 
#endif
# 1822 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1823
__attribute((always_inline)) __attribute__((unused)) inline void surf2DLayeredwrite(T val, surface< void, 242>  surf, int x, int y, int layer, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1824
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)s;(void)mode;
# 1844
::exit(___);}
#if 0
# 1824
{ 
# 1844
} 
#endif
# 1846 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1847
__attribute((always_inline)) __attribute__((unused)) inline void surf2DLayeredwrite(T val, surface< void, 242>  surf, int x, int y, int layer, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1848
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layer;(void)mode;
# 1852
::exit(___);}
#if 0
# 1848
{ 
# 1852
} 
#endif
# 1958 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1959
__attribute((always_inline)) __attribute__((unused)) inline void surfCubemapwrite(T val, surface< void, 12>  surf, int x, int y, int face, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1960
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)s;(void)mode;
# 1980
::exit(___);}
#if 0
# 1960
{ 
# 1980
} 
#endif
# 1982 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 1983
__attribute((always_inline)) __attribute__((unused)) inline void surfCubemapwrite(T val, surface< void, 12>  surf, int x, int y, int face, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 1984
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)face;(void)mode;
# 1988
::exit(___);}
#if 0
# 1984
{ 
# 1988
} 
#endif
# 2093 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 2094
__attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapLayeredwrite(T val, surface< void, 252>  surf, int x, int y, int layerFace, int s, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 2095
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)s;(void)mode;
# 2115
::exit(___);}
#if 0
# 2095
{ 
# 2115
} 
#endif
# 2117 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_functions.h"
template< class T> 
# 2118
__attribute((always_inline)) __attribute__((unused)) static inline void surfCubemapLayeredwrite(T val, surface< void, 252>  surf, int x, int y, int layerFace, cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) 
# 2119
{int volatile ___ = 1;(void)val;(void)surf;(void)x;(void)y;(void)layerFace;(void)mode;
# 2123
::exit(___);}
#if 0
# 2119
{ 
# 2123
} 
#endif
# 70 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 71
tex1Dfetch(texture< T, 1, cudaReadModeElementType> , int) {int volatile ___ = 1;::exit(___);}
#if 0
# 71
{ } 
#endif
# 73 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 74
struct __nv_tex_rmnf_ret { }; 
# 76
template<> struct __nv_tex_rmnf_ret< char>  { typedef float type; }; 
# 77
template<> struct __nv_tex_rmnf_ret< signed char>  { typedef float type; }; 
# 78
template<> struct __nv_tex_rmnf_ret< unsigned char>  { typedef float type; }; 
# 79
template<> struct __nv_tex_rmnf_ret< short>  { typedef float type; }; 
# 80
template<> struct __nv_tex_rmnf_ret< unsigned short>  { typedef float type; }; 
# 81
template<> struct __nv_tex_rmnf_ret< char1>  { typedef float1 type; }; 
# 82
template<> struct __nv_tex_rmnf_ret< uchar1>  { typedef float1 type; }; 
# 83
template<> struct __nv_tex_rmnf_ret< short1>  { typedef float1 type; }; 
# 84
template<> struct __nv_tex_rmnf_ret< ushort1>  { typedef float1 type; }; 
# 85
template<> struct __nv_tex_rmnf_ret< char2>  { typedef float2 type; }; 
# 86
template<> struct __nv_tex_rmnf_ret< uchar2>  { typedef float2 type; }; 
# 87
template<> struct __nv_tex_rmnf_ret< short2>  { typedef float2 type; }; 
# 88
template<> struct __nv_tex_rmnf_ret< ushort2>  { typedef float2 type; }; 
# 89
template<> struct __nv_tex_rmnf_ret< char4>  { typedef float4 type; }; 
# 90
template<> struct __nv_tex_rmnf_ret< uchar4>  { typedef float4 type; }; 
# 91
template<> struct __nv_tex_rmnf_ret< short4>  { typedef float4 type; }; 
# 92
template<> struct __nv_tex_rmnf_ret< ushort4>  { typedef float4 type; }; 
# 94
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 95
tex1Dfetch(texture< T, 1, cudaReadModeNormalizedFloat> , int) {int volatile ___ = 1;::exit(___);}
#if 0
# 95
{ } 
#endif
# 215 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 216
tex1D(texture< T, 1, cudaReadModeElementType> , float) {int volatile ___ = 1;::exit(___);}
#if 0
# 216
{ } 
#endif
# 218 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 219
tex1D(texture< T, 1, cudaReadModeNormalizedFloat> , float) {int volatile ___ = 1;::exit(___);}
#if 0
# 219
{ } 
#endif
# 345 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 346
tex2D(texture< T, 2, cudaReadModeElementType> , float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 346
{ } 
#endif
# 348 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 349
tex2D(texture< T, 2, cudaReadModeNormalizedFloat> , float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 349
{ } 
#endif
# 475 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 476
tex1DLayered(texture< T, 241, cudaReadModeElementType> , float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 476
{ } 
#endif
# 478 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 479
tex1DLayered(texture< T, 241, cudaReadModeNormalizedFloat> , float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 479
{ } 
#endif
# 603 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 604
tex2DLayered(texture< T, 242, cudaReadModeElementType> , float, float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 604
{ } 
#endif
# 606 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 607
tex2DLayered(texture< T, 242, cudaReadModeNormalizedFloat> , float, float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 607
{ } 
#endif
# 735 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 736
tex3D(texture< T, 3, cudaReadModeElementType> , float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 736
{ } 
#endif
# 738 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 739
tex3D(texture< T, 3, cudaReadModeNormalizedFloat> , float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 739
{ } 
#endif
# 864 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 865
texCubemap(texture< T, 12, cudaReadModeElementType> , float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 865
{ } 
#endif
# 867 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 868
texCubemap(texture< T, 12, cudaReadModeNormalizedFloat> , float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 868
{ } 
#endif
# 992 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 993
texCubemapLayered(texture< T, 252, cudaReadModeElementType> , float, float, float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 993
{ } 
#endif
# 995 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 996
texCubemapLayered(texture< T, 252, cudaReadModeNormalizedFloat> , float, float, float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 996
{ } 
#endif
# 1121 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> 
# 1122
struct __nv_tex2dgather_ret { }; 
# 1123
template<> struct __nv_tex2dgather_ret< char>  { typedef char4 type; }; 
# 1124
template<> struct __nv_tex2dgather_ret< signed char>  { typedef char4 type; }; 
# 1125
template<> struct __nv_tex2dgather_ret< char1>  { typedef char4 type; }; 
# 1126
template<> struct __nv_tex2dgather_ret< char2>  { typedef char4 type; }; 
# 1127
template<> struct __nv_tex2dgather_ret< char3>  { typedef char4 type; }; 
# 1128
template<> struct __nv_tex2dgather_ret< char4>  { typedef char4 type; }; 
# 1129
template<> struct __nv_tex2dgather_ret< unsigned char>  { typedef uchar4 type; }; 
# 1130
template<> struct __nv_tex2dgather_ret< uchar1>  { typedef uchar4 type; }; 
# 1131
template<> struct __nv_tex2dgather_ret< uchar2>  { typedef uchar4 type; }; 
# 1132
template<> struct __nv_tex2dgather_ret< uchar3>  { typedef uchar4 type; }; 
# 1133
template<> struct __nv_tex2dgather_ret< uchar4>  { typedef uchar4 type; }; 
# 1135
template<> struct __nv_tex2dgather_ret< short>  { typedef short4 type; }; 
# 1136
template<> struct __nv_tex2dgather_ret< short1>  { typedef short4 type; }; 
# 1137
template<> struct __nv_tex2dgather_ret< short2>  { typedef short4 type; }; 
# 1138
template<> struct __nv_tex2dgather_ret< short3>  { typedef short4 type; }; 
# 1139
template<> struct __nv_tex2dgather_ret< short4>  { typedef short4 type; }; 
# 1140
template<> struct __nv_tex2dgather_ret< unsigned short>  { typedef ushort4 type; }; 
# 1141
template<> struct __nv_tex2dgather_ret< ushort1>  { typedef ushort4 type; }; 
# 1142
template<> struct __nv_tex2dgather_ret< ushort2>  { typedef ushort4 type; }; 
# 1143
template<> struct __nv_tex2dgather_ret< ushort3>  { typedef ushort4 type; }; 
# 1144
template<> struct __nv_tex2dgather_ret< ushort4>  { typedef ushort4 type; }; 
# 1146
template<> struct __nv_tex2dgather_ret< int>  { typedef int4 type; }; 
# 1147
template<> struct __nv_tex2dgather_ret< int1>  { typedef int4 type; }; 
# 1148
template<> struct __nv_tex2dgather_ret< int2>  { typedef int4 type; }; 
# 1149
template<> struct __nv_tex2dgather_ret< int3>  { typedef int4 type; }; 
# 1150
template<> struct __nv_tex2dgather_ret< int4>  { typedef int4 type; }; 
# 1151
template<> struct __nv_tex2dgather_ret< unsigned>  { typedef uint4 type; }; 
# 1152
template<> struct __nv_tex2dgather_ret< uint1>  { typedef uint4 type; }; 
# 1153
template<> struct __nv_tex2dgather_ret< uint2>  { typedef uint4 type; }; 
# 1154
template<> struct __nv_tex2dgather_ret< uint3>  { typedef uint4 type; }; 
# 1155
template<> struct __nv_tex2dgather_ret< uint4>  { typedef uint4 type; }; 
# 1157
template<> struct __nv_tex2dgather_ret< float>  { typedef float4 type; }; 
# 1158
template<> struct __nv_tex2dgather_ret< float1>  { typedef float4 type; }; 
# 1159
template<> struct __nv_tex2dgather_ret< float2>  { typedef float4 type; }; 
# 1160
template<> struct __nv_tex2dgather_ret< float3>  { typedef float4 type; }; 
# 1161
template<> struct __nv_tex2dgather_ret< float4>  { typedef float4 type; }; 
# 1163
template< class T> __attribute__((unused)) static typename __nv_tex2dgather_ret< T> ::type 
# 1164
tex2Dgather(texture< T, 2, cudaReadModeElementType> , float, float, int = 0) {int volatile ___ = 1;::exit(___);}
#if 0
# 1164
{ } 
#endif
# 1166 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static float4 
# 1167
tex2Dgather(texture< T, 2, cudaReadModeNormalizedFloat> , float, float, int = 0) {int volatile ___ = 1;::exit(___);}
#if 0
# 1167
{ } 
#endif
# 1232 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 1233
tex1DLod(texture< T, 1, cudaReadModeElementType> , float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1233
{ } 
#endif
# 1235 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 1236
tex1DLod(texture< T, 1, cudaReadModeNormalizedFloat> , float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1236
{ } 
#endif
# 1360 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 1361
tex2DLod(texture< T, 2, cudaReadModeElementType> , float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1361
{ } 
#endif
# 1363 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 1364
tex2DLod(texture< T, 2, cudaReadModeNormalizedFloat> , float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1364
{ } 
#endif
# 1484 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 1485
tex1DLayeredLod(texture< T, 241, cudaReadModeElementType> , float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1485
{ } 
#endif
# 1487 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 1488
tex1DLayeredLod(texture< T, 241, cudaReadModeNormalizedFloat> , float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1488
{ } 
#endif
# 1612 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 1613
tex2DLayeredLod(texture< T, 242, cudaReadModeElementType> , float, float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1613
{ } 
#endif
# 1615 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 1616
tex2DLayeredLod(texture< T, 242, cudaReadModeNormalizedFloat> , float, float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1616
{ } 
#endif
# 1740 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 1741
tex3DLod(texture< T, 3, cudaReadModeElementType> , float, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1741
{ } 
#endif
# 1743 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 1744
tex3DLod(texture< T, 3, cudaReadModeNormalizedFloat> , float, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1744
{ } 
#endif
# 1868 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 1869
texCubemapLod(texture< T, 12, cudaReadModeElementType> , float, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1869
{ } 
#endif
# 1871 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 1872
texCubemapLod(texture< T, 12, cudaReadModeNormalizedFloat> , float, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1872
{ } 
#endif
# 1996 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 1997
texCubemapLayeredLod(texture< T, 252, cudaReadModeElementType> , float, float, float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1997
{ } 
#endif
# 1999 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 2000
texCubemapLayeredLod(texture< T, 252, cudaReadModeNormalizedFloat> , float, float, float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 2000
{ } 
#endif
# 2124 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 2125
tex1DGrad(texture< T, 1, cudaReadModeElementType> , float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 2125
{ } 
#endif
# 2127 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 2128
tex1DGrad(texture< T, 1, cudaReadModeNormalizedFloat> , float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 2128
{ } 
#endif
# 2252 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 2253
tex2DGrad(texture< T, 2, cudaReadModeElementType> , float, float, float2, float2) {int volatile ___ = 1;::exit(___);}
#if 0
# 2253
{ } 
#endif
# 2255 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 2256
tex2DGrad(texture< T, 2, cudaReadModeNormalizedFloat> , float, float, float2, float2) {int volatile ___ = 1;::exit(___);}
#if 0
# 2256
{ } 
#endif
# 2380 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 2381
tex1DLayeredGrad(texture< T, 241, cudaReadModeElementType> , float, int, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 2381
{ } 
#endif
# 2383 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 2384
tex1DLayeredGrad(texture< T, 241, cudaReadModeNormalizedFloat> , float, int, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 2384
{ } 
#endif
# 2509 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 2510
tex2DLayeredGrad(texture< T, 242, cudaReadModeElementType> , float, float, int, float2, float2) {int volatile ___ = 1;::exit(___);}
#if 0
# 2510
{ } 
#endif
# 2512 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 2513
tex2DLayeredGrad(texture< T, 242, cudaReadModeNormalizedFloat> , float, float, int, float2, float2) {int volatile ___ = 1;::exit(___);}
#if 0
# 2513
{ } 
#endif
# 2637 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static T 
# 2638
tex3DGrad(texture< T, 3, cudaReadModeElementType> , float, float, float, float4, float4) {int volatile ___ = 1;::exit(___);}
#if 0
# 2638
{ } 
#endif
# 2640 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_fetch_functions.h"
template< class T> __attribute__((unused)) static typename __nv_tex_rmnf_ret< T> ::type 
# 2641
tex3DGrad(texture< T, 3, cudaReadModeNormalizedFloat> , float, float, float, float4, float4) {int volatile ___ = 1;::exit(___);}
#if 0
# 2641
{ } 
#endif
# 67 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 68
tex1Dfetch(T *, cudaTextureObject_t, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 68
{ } 
#endif
# 121 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 122
tex1Dfetch(cudaTextureObject_t texObject, int x) 
# 123
{int volatile ___ = 1;(void)texObject;(void)x;
# 127
::exit(___);}
#if 0
# 123
{ 
# 124
T ret; 
# 125
tex1Dfetch(&ret, texObject, x); 
# 126
return ret; 
# 127
} 
#endif
# 135 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 136
tex1D(T *, cudaTextureObject_t, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 136
{ } 
#endif
# 190 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 191
tex1D(cudaTextureObject_t texObject, float x) 
# 192
{int volatile ___ = 1;(void)texObject;(void)x;
# 196
::exit(___);}
#if 0
# 192
{ 
# 193
T ret; 
# 194
tex1D(&ret, texObject, x); 
# 195
return ret; 
# 196
} 
#endif
# 205 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 206
tex2D(T *, cudaTextureObject_t, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 206
{ } 
#endif
# 258 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 259
tex2D(cudaTextureObject_t texObject, float x, float y) 
# 260
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;
# 264
::exit(___);}
#if 0
# 260
{ 
# 261
T ret; 
# 262
tex2D(&ret, texObject, x, y); 
# 263
return ret; 
# 264
} 
#endif
# 272 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 273
tex3D(T *, cudaTextureObject_t, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 273
{ } 
#endif
# 325 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 326
tex3D(cudaTextureObject_t texObject, float x, float y, float z) 
# 327
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;
# 331
::exit(___);}
#if 0
# 327
{ 
# 328
T ret; 
# 329
tex3D(&ret, texObject, x, y, z); 
# 330
return ret; 
# 331
} 
#endif
# 340 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 341
tex1DLayered(T *, cudaTextureObject_t, float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 341
{ } 
#endif
# 393 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 394
tex1DLayered(cudaTextureObject_t texObject, float x, int layer) 
# 395
{int volatile ___ = 1;(void)texObject;(void)x;(void)layer;
# 399
::exit(___);}
#if 0
# 395
{ 
# 396
T ret; 
# 397
tex1DLayered(&ret, texObject, x, layer); 
# 398
return ret; 
# 399
} 
#endif
# 408 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 409
tex2DLayered(T *, cudaTextureObject_t, float, float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 409
{ } 
#endif
# 461 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 462
tex2DLayered(cudaTextureObject_t texObject, float x, float y, int layer) 
# 463
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;
# 467
::exit(___);}
#if 0
# 463
{ 
# 464
T ret; 
# 465
tex2DLayered(&ret, texObject, x, y, layer); 
# 466
return ret; 
# 467
} 
#endif
# 476 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 477
texCubemap(T *, cudaTextureObject_t, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 477
{ } 
#endif
# 529 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 530
texCubemap(cudaTextureObject_t texObject, float x, float y, float z) 
# 531
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;
# 535
::exit(___);}
#if 0
# 531
{ 
# 532
T ret; 
# 533
texCubemap(&ret, texObject, x, y, z); 
# 534
return ret; 
# 535
} 
#endif
# 544 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 545
texCubemapLayered(T *, cudaTextureObject_t, float, float, float, int) {int volatile ___ = 1;::exit(___);}
#if 0
# 545
{ } 
#endif
# 598 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 599
texCubemapLayered(cudaTextureObject_t texObject, float x, float y, float z, int layer) 
# 600
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;
# 604
::exit(___);}
#if 0
# 600
{ 
# 601
T ret; 
# 602
texCubemapLayered(&ret, texObject, x, y, z, layer); 
# 603
return ret; 
# 604
} 
#endif
# 613 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 614
tex2Dgather(T *, cudaTextureObject_t, float, float, int = 0) {int volatile ___ = 1;::exit(___);}
#if 0
# 614
{ } 
#endif
# 660 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 661
tex2Dgather(cudaTextureObject_t to, float x, float y, int comp = 0) 
# 662
{int volatile ___ = 1;(void)to;(void)x;(void)y;(void)comp;
# 666
::exit(___);}
#if 0
# 662
{ 
# 663
T ret; 
# 664
tex2Dgather(&ret, to, x, y, comp); 
# 665
return ret; 
# 666
} 
#endif
# 675 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 676
tex1DLod(T *, cudaTextureObject_t, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 676
{ } 
#endif
# 728 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 729
tex1DLod(cudaTextureObject_t texObject, float x, float level) 
# 730
{int volatile ___ = 1;(void)texObject;(void)x;(void)level;
# 734
::exit(___);}
#if 0
# 730
{ 
# 731
T ret; 
# 732
tex1DLod(&ret, texObject, x, level); 
# 733
return ret; 
# 734
} 
#endif
# 743 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 744
tex2DLod(T *, cudaTextureObject_t, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 744
{ } 
#endif
# 797 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 798
tex2DLod(cudaTextureObject_t texObject, float x, float y, float level) 
# 799
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)level;
# 803
::exit(___);}
#if 0
# 799
{ 
# 800
T ret; 
# 801
tex2DLod(&ret, texObject, x, y, level); 
# 802
return ret; 
# 803
} 
#endif
# 812 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 813
tex3DLod(T *, cudaTextureObject_t, float, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 813
{ } 
#endif
# 865 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 866
tex3DLod(cudaTextureObject_t texObject, float x, float y, float z, float level) 
# 867
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;
# 871
::exit(___);}
#if 0
# 867
{ 
# 868
T ret; 
# 869
tex3DLod(&ret, texObject, x, y, z, level); 
# 870
return ret; 
# 871
} 
#endif
# 879 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 880
tex1DLayeredLod(T *, cudaTextureObject_t, float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 880
{ } 
#endif
# 932 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 933
tex1DLayeredLod(cudaTextureObject_t texObject, float x, int layer, float level) 
# 934
{int volatile ___ = 1;(void)texObject;(void)x;(void)layer;(void)level;
# 938
::exit(___);}
#if 0
# 934
{ 
# 935
T ret; 
# 936
tex1DLayeredLod(&ret, texObject, x, layer, level); 
# 937
return ret; 
# 938
} 
#endif
# 947 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 948
tex2DLayeredLod(T *, cudaTextureObject_t, float, float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 948
{ } 
#endif
# 1000 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 1001
tex2DLayeredLod(cudaTextureObject_t texObject, float x, float y, int layer, float level) 
# 1002
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)level;
# 1006
::exit(___);}
#if 0
# 1002
{ 
# 1003
T ret; 
# 1004
tex2DLayeredLod(&ret, texObject, x, y, layer, level); 
# 1005
return ret; 
# 1006
} 
#endif
# 1014 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 1015
texCubemapLod(T *, cudaTextureObject_t, float, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1015
{ } 
#endif
# 1067 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 1068
texCubemapLod(cudaTextureObject_t texObject, float x, float y, float z, float level) 
# 1069
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;
# 1073
::exit(___);}
#if 0
# 1069
{ 
# 1070
T ret; 
# 1071
texCubemapLod(&ret, texObject, x, y, z, level); 
# 1072
return ret; 
# 1073
} 
#endif
# 1081 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 1082
texCubemapLayeredLod(T *, cudaTextureObject_t, float, float, float, int, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1082
{ } 
#endif
# 1134 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 1135
texCubemapLayeredLod(cudaTextureObject_t texObject, float x, float y, float z, int layer, float level) 
# 1136
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;(void)level;
# 1140
::exit(___);}
#if 0
# 1136
{ 
# 1137
T ret; 
# 1138
texCubemapLayeredLod(&ret, texObject, x, y, z, layer, level); 
# 1139
return ret; 
# 1140
} 
#endif
# 1148 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 1149
tex1DGrad(T *, cudaTextureObject_t, float, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1149
{ } 
#endif
# 1202 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 1203
tex1DGrad(cudaTextureObject_t texObject, float x, float dPdx, float dPdy) 
# 1204
{int volatile ___ = 1;(void)texObject;(void)x;(void)dPdx;(void)dPdy;
# 1208
::exit(___);}
#if 0
# 1204
{ 
# 1205
T ret; 
# 1206
tex1DGrad(&ret, texObject, x, dPdx, dPdy); 
# 1207
return ret; 
# 1208
} 
#endif
# 1216 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 1217
tex2DGrad(T *, cudaTextureObject_t, float, float, float2, float2) {int volatile ___ = 1;::exit(___);}
#if 0
# 1217
{ } 
#endif
# 1269 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 1270
tex2DGrad(cudaTextureObject_t texObject, float x, float y, float2 dPdx, float2 dPdy) 
# 1271
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)dPdx;(void)dPdy;
# 1275
::exit(___);}
#if 0
# 1271
{ 
# 1272
T ret; 
# 1273
tex2DGrad(&ret, texObject, x, y, dPdx, dPdy); 
# 1274
return ret; 
# 1275
} 
#endif
# 1283 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 1284
tex3DGrad(T *, cudaTextureObject_t, float, float, float, float4, float4) {int volatile ___ = 1;::exit(___);}
#if 0
# 1284
{ } 
#endif
# 1336 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 1337
tex3DGrad(cudaTextureObject_t texObject, float x, float y, float z, float4 dPdx, float4 dPdy) 
# 1338
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;
# 1342
::exit(___);}
#if 0
# 1338
{ 
# 1339
T ret; 
# 1340
tex3DGrad(&ret, texObject, x, y, z, dPdx, dPdy); 
# 1341
return ret; 
# 1342
} 
#endif
# 1350 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 1351
tex1DLayeredGrad(T *, cudaTextureObject_t, float, int, float, float) {int volatile ___ = 1;::exit(___);}
#if 0
# 1351
{ } 
#endif
# 1404 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 1405
tex1DLayeredGrad(cudaTextureObject_t texObject, float x, int layer, float dPdx, float dPdy) 
# 1406
{int volatile ___ = 1;(void)texObject;(void)x;(void)layer;(void)dPdx;(void)dPdy;
# 1410
::exit(___);}
#if 0
# 1406
{ 
# 1407
T ret; 
# 1408
tex1DLayeredGrad(&ret, texObject, x, layer, dPdx, dPdy); 
# 1409
return ret; 
# 1410
} 
#endif
# 1418 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 1419
tex2DLayeredGrad(T *, cudaTextureObject_t, float, float, int, float2, float2) {int volatile ___ = 1;::exit(___);}
#if 0
# 1419
{ } 
#endif
# 1471 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/texture_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 1472
tex2DLayeredGrad(cudaTextureObject_t texObject, float x, float y, int layer, float2 dPdx, float2 dPdy) 
# 1473
{int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;
# 1477
::exit(___);}
#if 0
# 1473
{ 
# 1474
T ret; 
# 1475
tex2DLayeredGrad(&ret, texObject, x, y, layer, dPdx, dPdy); 
# 1476
return ret; 
# 1477
} 
#endif
# 68 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 69
surf1Dread(T *, cudaSurfaceObject_t, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 69
{ } 
#endif
# 111 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 112
surf1Dread(cudaSurfaceObject_t surfObject, int x, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 113
{int volatile ___ = 1;(void)surfObject;(void)x;(void)boundaryMode;
# 119
::exit(___);}
#if 0
# 113
{ 
# 119
} 
#endif
# 128 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 129
surf2Dread(T *, cudaSurfaceObject_t, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 129
{ } 
#endif
# 172 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 173
surf2Dread(cudaSurfaceObject_t surfObject, int x, int y, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 174
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)boundaryMode;
# 180
::exit(___);}
#if 0
# 174
{ 
# 180
} 
#endif
# 189 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 190
surf3Dread(T *, cudaSurfaceObject_t, int, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 190
{ } 
#endif
# 231 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 232
surf3Dread(cudaSurfaceObject_t surfObject, int x, int y, int z, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 233
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)z;(void)boundaryMode;
# 239
::exit(___);}
#if 0
# 233
{ 
# 239
} 
#endif
# 247 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 248
surf1DLayeredread(T *, cudaSurfaceObject_t, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 248
{ } 
#endif
# 290 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 291
surf1DLayeredread(cudaSurfaceObject_t surfObject, int x, int layer, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 292
{int volatile ___ = 1;(void)surfObject;(void)x;(void)layer;(void)boundaryMode;
# 298
::exit(___);}
#if 0
# 292
{ 
# 298
} 
#endif
# 306 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 307
surf2DLayeredread(T *, cudaSurfaceObject_t, int, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 307
{ } 
#endif
# 348 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 349
surf2DLayeredread(cudaSurfaceObject_t surfObject, int x, int y, int layer, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 350
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)layer;(void)boundaryMode;
# 356
::exit(___);}
#if 0
# 350
{ 
# 356
} 
#endif
# 364 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 365
surfCubemapread(T *, cudaSurfaceObject_t, int, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 365
{ } 
#endif
# 406 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 407
surfCubemapread(cudaSurfaceObject_t surfObject, int x, int y, int face, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 408
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)face;(void)boundaryMode;
# 414
::exit(___);}
#if 0
# 408
{ 
# 414
} 
#endif
# 422 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 423
surfCubemapLayeredread(T *, cudaSurfaceObject_t, int, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 423
{ } 
#endif
# 464 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static T 
# 465
surfCubemapLayeredread(cudaSurfaceObject_t surfObject, int x, int y, int layerface, cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) 
# 466
{int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)layerface;(void)boundaryMode;
# 472
::exit(___);}
#if 0
# 466
{ 
# 472
} 
#endif
# 480 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 481
surf1Dwrite(T, cudaSurfaceObject_t, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 481
{ } 
#endif
# 528 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 529
surf2Dwrite(T, cudaSurfaceObject_t, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 529
{ } 
#endif
# 576 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 577
surf3Dwrite(T, cudaSurfaceObject_t, int, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 577
{ } 
#endif
# 626 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 627
surf1DLayeredwrite(T, cudaSurfaceObject_t, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 627
{ } 
#endif
# 675 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 676
surf2DLayeredwrite(T, cudaSurfaceObject_t, int, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 676
{ } 
#endif
# 723 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 724
surfCubemapwrite(T, cudaSurfaceObject_t, int, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 724
{ } 
#endif
# 771 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/surface_indirect_functions.h"
template< class T> __attribute__((unused)) static void 
# 772
surfCubemapLayeredwrite(T, cudaSurfaceObject_t, int, int, int, cudaSurfaceBoundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;::exit(___);}
#if 0
# 772
{ } 
#endif
# 68 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_launch_parameters.h"
extern "C" {
# 71
extern const uint3 __device_builtin_variable_threadIdx; 
# 72
extern const uint3 __device_builtin_variable_blockIdx; 
# 73
extern const dim3 __device_builtin_variable_blockDim; 
# 74
extern const dim3 __device_builtin_variable_gridDim; 
# 75
extern const int __device_builtin_variable_warpSize; 
# 80
}
# 183 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda_runtime.h"
template< class T> static inline cudaError_t 
# 184
cudaLaunchKernel(const T *
# 185
func, dim3 
# 186
gridDim, dim3 
# 187
blockDim, void **
# 188
args, ::size_t 
# 189
sharedMem = 0, cudaStream_t 
# 190
stream = 0) 
# 192
{ 
# 193
return ::cudaLaunchKernel((const void *)func, gridDim, blockDim, args, sharedMem, stream); 
# 194
} 
# 221
template< class T> static inline cudaError_t 
# 222
cudaSetupArgument(T 
# 223
arg, ::size_t 
# 224
offset) 
# 226
{ 
# 227
return ::cudaSetupArgument((const void *)(&arg), sizeof(T), offset); 
# 228
} 
# 260
static inline cudaError_t cudaEventCreate(cudaEvent_t *
# 261
event, unsigned 
# 262
flags) 
# 264
{ 
# 265
return ::cudaEventCreateWithFlags(event, flags); 
# 266
} 
# 323
static inline cudaError_t cudaMallocHost(void **
# 324
ptr, ::size_t 
# 325
size, unsigned 
# 326
flags) 
# 328
{ 
# 329
return ::cudaHostAlloc(ptr, size, flags); 
# 330
} 
# 332
template< class T> static inline cudaError_t 
# 333
cudaHostAlloc(T **
# 334
ptr, ::size_t 
# 335
size, unsigned 
# 336
flags) 
# 338
{ 
# 339
return ::cudaHostAlloc((void **)((void *)ptr), size, flags); 
# 340
} 
# 342
template< class T> static inline cudaError_t 
# 343
cudaHostGetDevicePointer(T **
# 344
pDevice, void *
# 345
pHost, unsigned 
# 346
flags) 
# 348
{ 
# 349
return ::cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags); 
# 350
} 
# 449
template< class T> static inline cudaError_t 
# 450
cudaMallocManaged(T **
# 451
devPtr, ::size_t 
# 452
size, unsigned 
# 453
flags = 1) 
# 455
{ 
# 456
return ::cudaMallocManaged((void **)((void *)devPtr), size, flags); 
# 457
} 
# 528
template< class T> static inline cudaError_t 
# 529
cudaStreamAttachMemAsync(cudaStream_t 
# 530
stream, T *
# 531
devPtr, ::size_t 
# 532
length = 0, unsigned 
# 533
flags = 4) 
# 535
{ 
# 536
return ::cudaStreamAttachMemAsync(stream, (void *)devPtr, length, flags); 
# 537
} 
# 539
template< class T> inline cudaError_t 
# 540
cudaMalloc(T **
# 541
devPtr, ::size_t 
# 542
size) 
# 544
{ 
# 545
return ::cudaMalloc((void **)((void *)devPtr), size); 
# 546
} 
# 548
template< class T> static inline cudaError_t 
# 549
cudaMallocHost(T **
# 550
ptr, ::size_t 
# 551
size, unsigned 
# 552
flags = 0) 
# 554
{ 
# 555
return cudaMallocHost((void **)((void *)ptr), size, flags); 
# 556
} 
# 558
template< class T> static inline cudaError_t 
# 559
cudaMallocPitch(T **
# 560
devPtr, ::size_t *
# 561
pitch, ::size_t 
# 562
width, ::size_t 
# 563
height) 
# 565
{ 
# 566
return ::cudaMallocPitch((void **)((void *)devPtr), pitch, width, height); 
# 567
} 
# 604
template< class T> static inline cudaError_t 
# 605
cudaMemcpyToSymbol(const T &
# 606
symbol, const void *
# 607
src, ::size_t 
# 608
count, ::size_t 
# 609
offset = 0, cudaMemcpyKind 
# 610
kind = cudaMemcpyHostToDevice) 
# 612
{ 
# 613
return ::cudaMemcpyToSymbol((const void *)(&symbol), src, count, offset, kind); 
# 614
} 
# 656
template< class T> static inline cudaError_t 
# 657
cudaMemcpyToSymbolAsync(const T &
# 658
symbol, const void *
# 659
src, ::size_t 
# 660
count, ::size_t 
# 661
offset = 0, cudaMemcpyKind 
# 662
kind = cudaMemcpyHostToDevice, cudaStream_t 
# 663
stream = 0) 
# 665
{ 
# 666
return ::cudaMemcpyToSymbolAsync((const void *)(&symbol), src, count, offset, kind, stream); 
# 667
} 
# 702
template< class T> static inline cudaError_t 
# 703
cudaMemcpyFromSymbol(void *
# 704
dst, const T &
# 705
symbol, ::size_t 
# 706
count, ::size_t 
# 707
offset = 0, cudaMemcpyKind 
# 708
kind = cudaMemcpyDeviceToHost) 
# 710
{ 
# 711
return ::cudaMemcpyFromSymbol(dst, (const void *)(&symbol), count, offset, kind); 
# 712
} 
# 754
template< class T> static inline cudaError_t 
# 755
cudaMemcpyFromSymbolAsync(void *
# 756
dst, const T &
# 757
symbol, ::size_t 
# 758
count, ::size_t 
# 759
offset = 0, cudaMemcpyKind 
# 760
kind = cudaMemcpyDeviceToHost, cudaStream_t 
# 761
stream = 0) 
# 763
{ 
# 764
return ::cudaMemcpyFromSymbolAsync(dst, (const void *)(&symbol), count, offset, kind, stream); 
# 765
} 
# 787
template< class T> static inline cudaError_t 
# 788
cudaGetSymbolAddress(void **
# 789
devPtr, const T &
# 790
symbol) 
# 792
{ 
# 793
return ::cudaGetSymbolAddress(devPtr, (const void *)(&symbol)); 
# 794
} 
# 816
template< class T> static inline cudaError_t 
# 817
cudaGetSymbolSize(::size_t *
# 818
size, const T &
# 819
symbol) 
# 821
{ 
# 822
return ::cudaGetSymbolSize(size, (const void *)(&symbol)); 
# 823
} 
# 859
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 860
cudaBindTexture(::size_t *
# 861
offset, const texture< T, dim, readMode>  &
# 862
tex, const void *
# 863
devPtr, const cudaChannelFormatDesc &
# 864
desc, ::size_t 
# 865
size = ((2147483647) * 2U) + 1U) 
# 867
{ 
# 868
return ::cudaBindTexture(offset, &tex, devPtr, &desc, size); 
# 869
} 
# 904
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 905
cudaBindTexture(::size_t *
# 906
offset, const texture< T, dim, readMode>  &
# 907
tex, const void *
# 908
devPtr, ::size_t 
# 909
size = ((2147483647) * 2U) + 1U) 
# 911
{ 
# 912
return cudaBindTexture(offset, tex, devPtr, (tex.channelDesc), size); 
# 913
} 
# 960
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 961
cudaBindTexture2D(::size_t *
# 962
offset, const texture< T, dim, readMode>  &
# 963
tex, const void *
# 964
devPtr, const cudaChannelFormatDesc &
# 965
desc, ::size_t 
# 966
width, ::size_t 
# 967
height, ::size_t 
# 968
pitch) 
# 970
{ 
# 971
return ::cudaBindTexture2D(offset, &tex, devPtr, &desc, width, height, pitch); 
# 972
} 
# 1018
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 1019
cudaBindTexture2D(::size_t *
# 1020
offset, const texture< T, dim, readMode>  &
# 1021
tex, const void *
# 1022
devPtr, ::size_t 
# 1023
width, ::size_t 
# 1024
height, ::size_t 
# 1025
pitch) 
# 1027
{ 
# 1028
return ::cudaBindTexture2D(offset, &tex, devPtr, &(tex.channelDesc), width, height, pitch); 
# 1029
} 
# 1060
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 1061
cudaBindTextureToArray(const texture< T, dim, readMode>  &
# 1062
tex, cudaArray_const_t 
# 1063
array, const cudaChannelFormatDesc &
# 1064
desc) 
# 1066
{ 
# 1067
return ::cudaBindTextureToArray(&tex, array, &desc); 
# 1068
} 
# 1098
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 1099
cudaBindTextureToArray(const texture< T, dim, readMode>  &
# 1100
tex, cudaArray_const_t 
# 1101
array) 
# 1103
{ 
# 1104
cudaChannelFormatDesc desc; 
# 1105
cudaError_t err = ::cudaGetChannelDesc(&desc, array); 
# 1107
return (err == (cudaSuccess)) ? cudaBindTextureToArray(tex, array, desc) : err; 
# 1108
} 
# 1139
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 1140
cudaBindTextureToMipmappedArray(const texture< T, dim, readMode>  &
# 1141
tex, cudaMipmappedArray_const_t 
# 1142
mipmappedArray, const cudaChannelFormatDesc &
# 1143
desc) 
# 1145
{ 
# 1146
return ::cudaBindTextureToMipmappedArray(&tex, mipmappedArray, &desc); 
# 1147
} 
# 1177
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 1178
cudaBindTextureToMipmappedArray(const texture< T, dim, readMode>  &
# 1179
tex, cudaMipmappedArray_const_t 
# 1180
mipmappedArray) 
# 1182
{ 
# 1183
cudaChannelFormatDesc desc; 
# 1184
cudaArray_t levelArray; 
# 1185
cudaError_t err = ::cudaGetMipmappedArrayLevel(&levelArray, mipmappedArray, 0); 
# 1187
if (err != (cudaSuccess)) { 
# 1188
return err; 
# 1189
}  
# 1190
err = ::cudaGetChannelDesc(&desc, levelArray); 
# 1192
return (err == (cudaSuccess)) ? cudaBindTextureToMipmappedArray(tex, mipmappedArray, desc) : err; 
# 1193
} 
# 1216
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 1217
cudaUnbindTexture(const texture< T, dim, readMode>  &
# 1218
tex) 
# 1220
{ 
# 1221
return ::cudaUnbindTexture(&tex); 
# 1222
} 
# 1250
template< class T, int dim, cudaTextureReadMode readMode> static inline cudaError_t 
# 1251
cudaGetTextureAlignmentOffset(::size_t *
# 1252
offset, const texture< T, dim, readMode>  &
# 1253
tex) 
# 1255
{ 
# 1256
return ::cudaGetTextureAlignmentOffset(offset, &tex); 
# 1257
} 
# 1302
template< class T> static inline cudaError_t 
# 1303
cudaFuncSetCacheConfig(T *
# 1304
func, cudaFuncCache 
# 1305
cacheConfig) 
# 1307
{ 
# 1308
return ::cudaFuncSetCacheConfig((const void *)func, cacheConfig); 
# 1309
} 
# 1311
template< class T> static inline cudaError_t 
# 1312
cudaFuncSetSharedMemConfig(T *
# 1313
func, cudaSharedMemConfig 
# 1314
config) 
# 1316
{ 
# 1317
return ::cudaFuncSetSharedMemConfig((const void *)func, config); 
# 1318
} 
# 1347
template< class T> inline cudaError_t 
# 1348
cudaOccupancyMaxActiveBlocksPerMultiprocessor(int *
# 1349
numBlocks, T 
# 1350
func, int 
# 1351
blockSize, ::size_t 
# 1352
dynamicSMemSize) 
# 1353
{ 
# 1354
return ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, (const void *)func, blockSize, dynamicSMemSize, 0); 
# 1355
} 
# 1398
template< class T> inline cudaError_t 
# 1399
cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *
# 1400
numBlocks, T 
# 1401
func, int 
# 1402
blockSize, ::size_t 
# 1403
dynamicSMemSize, unsigned 
# 1404
flags) 
# 1405
{ 
# 1406
return ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, (const void *)func, blockSize, dynamicSMemSize, flags); 
# 1407
} 
# 1412
class __cudaOccupancyB2DHelper { 
# 1413
::size_t n; 
# 1415
public: __cudaOccupancyB2DHelper(::size_t n_) : n(n_) { } 
# 1416
::size_t operator()(int) 
# 1417
{ 
# 1418
return n; 
# 1419
} 
# 1420
}; 
# 1467
template< class UnaryFunction, class T> static inline cudaError_t 
# 1468
cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(int *
# 1469
minGridSize, int *
# 1470
blockSize, T 
# 1471
func, UnaryFunction 
# 1472
blockSizeToDynamicSMemSize, int 
# 1473
blockSizeLimit = 0, unsigned 
# 1474
flags = 0) 
# 1475
{ 
# 1476
cudaError_t status; 
# 1479
int device; 
# 1480
cudaFuncAttributes attr; 
# 1483
int maxThreadsPerMultiProcessor; 
# 1484
int warpSize; 
# 1485
int devMaxThreadsPerBlock; 
# 1486
int multiProcessorCount; 
# 1487
int funcMaxThreadsPerBlock; 
# 1488
int occupancyLimit; 
# 1489
int granularity; 
# 1492
int maxBlockSize = 0; 
# 1493
int numBlocks = 0; 
# 1494
int maxOccupancy = 0; 
# 1497
int blockSizeToTryAligned; 
# 1498
int blockSizeToTry; 
# 1499
int blockSizeLimitAligned; 
# 1500
int occupancyInBlocks; 
# 1501
int occupancyInThreads; 
# 1502
::size_t dynamicSMemSize; 
# 1508
if (((!minGridSize) || (!blockSize)) || (!func)) { 
# 1509
return cudaErrorInvalidValue; 
# 1510
}  
# 1516
status = ::cudaGetDevice(&device); 
# 1517
if (status != (cudaSuccess)) { 
# 1518
return status; 
# 1519
}  
# 1521
status = cudaDeviceGetAttribute(&maxThreadsPerMultiProcessor, cudaDevAttrMaxThreadsPerMultiProcessor, device); 
# 1525
if (status != (cudaSuccess)) { 
# 1526
return status; 
# 1527
}  
# 1529
status = cudaDeviceGetAttribute(&warpSize, cudaDevAttrWarpSize, device); 
# 1533
if (status != (cudaSuccess)) { 
# 1534
return status; 
# 1535
}  
# 1537
status = cudaDeviceGetAttribute(&devMaxThreadsPerBlock, cudaDevAttrMaxThreadsPerBlock, device); 
# 1541
if (status != (cudaSuccess)) { 
# 1542
return status; 
# 1543
}  
# 1545
status = cudaDeviceGetAttribute(&multiProcessorCount, cudaDevAttrMultiProcessorCount, device); 
# 1549
if (status != (cudaSuccess)) { 
# 1550
return status; 
# 1551
}  
# 1553
status = cudaFuncGetAttributes(&attr, func); 
# 1554
if (status != (cudaSuccess)) { 
# 1555
return status; 
# 1556
}  
# 1558
funcMaxThreadsPerBlock = (attr.maxThreadsPerBlock); 
# 1564
occupancyLimit = maxThreadsPerMultiProcessor; 
# 1565
granularity = warpSize; 
# 1567
if (blockSizeLimit == 0) { 
# 1568
blockSizeLimit = devMaxThreadsPerBlock; 
# 1569
}  
# 1571
if (devMaxThreadsPerBlock < blockSizeLimit) { 
# 1572
blockSizeLimit = devMaxThreadsPerBlock; 
# 1573
}  
# 1575
if (funcMaxThreadsPerBlock < blockSizeLimit) { 
# 1576
blockSizeLimit = funcMaxThreadsPerBlock; 
# 1577
}  
# 1579
blockSizeLimitAligned = (((blockSizeLimit + (granularity - 1)) / granularity) * granularity); 
# 1581
for (blockSizeToTryAligned = blockSizeLimitAligned; blockSizeToTryAligned > 0; blockSizeToTryAligned -= granularity) { 
# 1585
if (blockSizeLimit < blockSizeToTryAligned) { 
# 1586
blockSizeToTry = blockSizeLimit; 
# 1587
} else { 
# 1588
blockSizeToTry = blockSizeToTryAligned; 
# 1589
}  
# 1591
dynamicSMemSize = blockSizeToDynamicSMemSize(blockSizeToTry); 
# 1593
status = cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(&occupancyInBlocks, func, blockSizeToTry, dynamicSMemSize, flags); 
# 1600
if (status != (cudaSuccess)) { 
# 1601
return status; 
# 1602
}  
# 1604
occupancyInThreads = (blockSizeToTry * occupancyInBlocks); 
# 1606
if (occupancyInThreads > maxOccupancy) { 
# 1607
maxBlockSize = blockSizeToTry; 
# 1608
numBlocks = occupancyInBlocks; 
# 1609
maxOccupancy = occupancyInThreads; 
# 1610
}  
# 1614
if (occupancyLimit == maxOccupancy) { 
# 1615
break; 
# 1616
}  
# 1617
}  
# 1625
(*minGridSize) = (numBlocks * multiProcessorCount); 
# 1626
(*blockSize) = maxBlockSize; 
# 1628
return status; 
# 1629
} 
# 1662
template< class UnaryFunction, class T> static inline cudaError_t 
# 1663
cudaOccupancyMaxPotentialBlockSizeVariableSMem(int *
# 1664
minGridSize, int *
# 1665
blockSize, T 
# 1666
func, UnaryFunction 
# 1667
blockSizeToDynamicSMemSize, int 
# 1668
blockSizeLimit = 0) 
# 1669
{ 
# 1670
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, blockSizeLimit, 0); 
# 1671
} 
# 1707
template< class T> static inline cudaError_t 
# 1708
cudaOccupancyMaxPotentialBlockSize(int *
# 1709
minGridSize, int *
# 1710
blockSize, T 
# 1711
func, ::size_t 
# 1712
dynamicSMemSize = 0, int 
# 1713
blockSizeLimit = 0) 
# 1714
{ 
# 1715
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, ((__cudaOccupancyB2DHelper)(dynamicSMemSize)), blockSizeLimit, 0); 
# 1716
} 
# 1766
template< class T> static inline cudaError_t 
# 1767
cudaOccupancyMaxPotentialBlockSizeWithFlags(int *
# 1768
minGridSize, int *
# 1769
blockSize, T 
# 1770
func, ::size_t 
# 1771
dynamicSMemSize = 0, int 
# 1772
blockSizeLimit = 0, unsigned 
# 1773
flags = 0) 
# 1774
{ 
# 1775
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, ((__cudaOccupancyB2DHelper)(dynamicSMemSize)), blockSizeLimit, flags); 
# 1776
} 
# 1814
template< class T> static inline cudaError_t 
# 1815
cudaLaunch(T *
# 1816
func) 
# 1818
{ 
# 1819
return ::cudaLaunch((const void *)func); 
# 1820
} 
# 1851
template< class T> inline cudaError_t 
# 1852
cudaFuncGetAttributes(cudaFuncAttributes *
# 1853
attr, T *
# 1854
entry) 
# 1856
{ 
# 1857
return ::cudaFuncGetAttributes(attr, (const void *)entry); 
# 1858
} 
# 1880
template< class T, int dim> static inline cudaError_t 
# 1881
cudaBindSurfaceToArray(const surface< T, dim>  &
# 1882
surf, cudaArray_const_t 
# 1883
array, const cudaChannelFormatDesc &
# 1884
desc) 
# 1886
{ 
# 1887
return ::cudaBindSurfaceToArray(&surf, array, &desc); 
# 1888
} 
# 1909
template< class T, int dim> static inline cudaError_t 
# 1910
cudaBindSurfaceToArray(const surface< T, dim>  &
# 1911
surf, cudaArray_const_t 
# 1912
array) 
# 1914
{ 
# 1915
cudaChannelFormatDesc desc; 
# 1916
cudaError_t err = ::cudaGetChannelDesc(&desc, array); 
# 1918
return (err == (cudaSuccess)) ? cudaBindSurfaceToArray(surf, array, desc) : err; 
# 1919
} 
# 1930
#pragma GCC diagnostic pop
# 29 "/usr/include/stdio.h" 3
extern "C" {
# 44
struct _IO_FILE; 
# 48
typedef _IO_FILE FILE; 
# 64
typedef _IO_FILE __FILE; 
# 94 "/usr/include/wchar.h" 3
typedef 
# 83
struct { 
# 84
int __count; 
# 86
union { 
# 88
unsigned __wch; 
# 92
char __wchb[4]; 
# 93
} __value; 
# 94
} __mbstate_t; 
# 25 "/usr/include/_G_config.h" 3
typedef 
# 22
struct { 
# 23
__off_t __pos; 
# 24
__mbstate_t __state; 
# 25
} _G_fpos_t; 
# 30
typedef 
# 27
struct { 
# 28
__off64_t __pos; 
# 29
__mbstate_t __state; 
# 30
} _G_fpos64_t; 
# 40 "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list; 
# 145 "/usr/include/libio.h" 3
struct _IO_jump_t; struct _IO_FILE; 
# 155
typedef void _IO_lock_t; 
# 161
struct _IO_marker { 
# 162
_IO_marker *_next; 
# 163
_IO_FILE *_sbuf; 
# 167
int _pos; 
# 178
}; 
# 181
enum __codecvt_result { 
# 183
__codecvt_ok, 
# 184
__codecvt_partial, 
# 185
__codecvt_error, 
# 186
__codecvt_noconv
# 187
}; 
# 246
struct _IO_FILE { 
# 247
int _flags; 
# 252
char *_IO_read_ptr; 
# 253
char *_IO_read_end; 
# 254
char *_IO_read_base; 
# 255
char *_IO_write_base; 
# 256
char *_IO_write_ptr; 
# 257
char *_IO_write_end; 
# 258
char *_IO_buf_base; 
# 259
char *_IO_buf_end; 
# 261
char *_IO_save_base; 
# 262
char *_IO_backup_base; 
# 263
char *_IO_save_end; 
# 265
_IO_marker *_markers; 
# 267
_IO_FILE *_chain; 
# 269
int _fileno; 
# 273
int _flags2; 
# 275
__off_t _old_offset; 
# 279
unsigned short _cur_column; 
# 280
signed char _vtable_offset; 
# 281
char _shortbuf[1]; 
# 285
_IO_lock_t *_lock; 
# 294
__off64_t _offset; 
# 303
void *__pad1; 
# 304
void *__pad2; 
# 305
void *__pad3; 
# 306
void *__pad4; 
# 307
::size_t __pad5; 
# 309
int _mode; 
# 311
char _unused2[(((15) * sizeof(int)) - ((4) * sizeof(void *))) - sizeof(::size_t)]; 
# 313
}; 
# 319
struct _IO_FILE_plus; 
# 321
extern _IO_FILE_plus _IO_2_1_stdin_; 
# 322
extern _IO_FILE_plus _IO_2_1_stdout_; 
# 323
extern _IO_FILE_plus _IO_2_1_stderr_; 
# 339
typedef __ssize_t __io_read_fn(void * __cookie, char * __buf, ::size_t __nbytes); 
# 347
typedef __ssize_t __io_write_fn(void * __cookie, const char * __buf, ::size_t __n); 
# 356
typedef int __io_seek_fn(void * __cookie, __off64_t * __pos, int __w); 
# 359
typedef int __io_close_fn(void * __cookie); 
# 364
typedef __io_read_fn cookie_read_function_t; 
# 365
typedef __io_write_fn cookie_write_function_t; 
# 366
typedef __io_seek_fn cookie_seek_function_t; 
# 367
typedef __io_close_fn cookie_close_function_t; 
# 376
typedef 
# 371
struct { 
# 372
__io_read_fn *read; 
# 373
__io_write_fn *write; 
# 374
__io_seek_fn *seek; 
# 375
__io_close_fn *close; 
# 376
} _IO_cookie_io_functions_t; 
# 377
typedef _IO_cookie_io_functions_t cookie_io_functions_t; 
# 379
struct _IO_cookie_file; 
# 382
extern void _IO_cookie_init(_IO_cookie_file * __cfile, int __read_write, void * __cookie, _IO_cookie_io_functions_t __fns); 
# 388
extern "C" {
# 391
extern int __underflow(_IO_FILE *); 
# 392
extern int __uflow(_IO_FILE *); 
# 393
extern int __overflow(_IO_FILE *, int); 
# 435
extern int _IO_getc(_IO_FILE * __fp); 
# 436
extern int _IO_putc(int __c, _IO_FILE * __fp); 
# 437
extern int _IO_feof(_IO_FILE * __fp) throw(); 
# 438
extern int _IO_ferror(_IO_FILE * __fp) throw(); 
# 440
extern int _IO_peekc_locked(_IO_FILE * __fp); 
# 446
extern void _IO_flockfile(_IO_FILE *) throw(); 
# 447
extern void _IO_funlockfile(_IO_FILE *) throw(); 
# 448
extern int _IO_ftrylockfile(_IO_FILE *) throw(); 
# 465
extern int _IO_vfscanf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list, int *__restrict__); 
# 467
extern int _IO_vfprintf(_IO_FILE *__restrict__, const char *__restrict__, __gnuc_va_list); 
# 469
extern __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t); 
# 470
extern ::size_t _IO_sgetn(_IO_FILE *, void *, ::size_t); 
# 472
extern __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int); 
# 473
extern __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int); 
# 475
extern void _IO_free_backup_area(_IO_FILE *) throw(); 
# 527
}
# 79 "/usr/include/stdio.h" 3
typedef __gnuc_va_list va_list; 
# 110
typedef _G_fpos_t fpos_t; 
# 116
typedef _G_fpos64_t fpos64_t; 
# 168
extern _IO_FILE *stdin; 
# 169
extern _IO_FILE *stdout; 
# 170
extern _IO_FILE *stderr; 
# 178
extern int remove(const char * __filename) throw(); 
# 180
extern int rename(const char * __old, const char * __new) throw(); 
# 185
extern int renameat(int __oldfd, const char * __old, int __newfd, const char * __new) throw(); 
# 195
extern FILE *tmpfile(); 
# 205
extern FILE *tmpfile64(); 
# 209
extern char *tmpnam(char * __s) throw(); 
# 215
extern char *tmpnam_r(char * __s) throw(); 
# 227
extern char *tempnam(const char * __dir, const char * __pfx) throw()
# 228
 __attribute((__malloc__)); 
# 237
extern int fclose(FILE * __stream); 
# 242
extern int fflush(FILE * __stream); 
# 252
extern int fflush_unlocked(FILE * __stream); 
# 262
extern int fcloseall(); 
# 272
extern FILE *fopen(const char *__restrict__ __filename, const char *__restrict__ __modes); 
# 278
extern FILE *freopen(const char *__restrict__ __filename, const char *__restrict__ __modes, FILE *__restrict__ __stream); 
# 297
extern FILE *fopen64(const char *__restrict__ __filename, const char *__restrict__ __modes); 
# 299
extern FILE *freopen64(const char *__restrict__ __filename, const char *__restrict__ __modes, FILE *__restrict__ __stream); 
# 306
extern FILE *fdopen(int __fd, const char * __modes) throw(); 
# 312
extern FILE *fopencookie(void *__restrict__ __magic_cookie, const char *__restrict__ __modes, _IO_cookie_io_functions_t __io_funcs) throw(); 
# 319
extern FILE *fmemopen(void * __s, ::size_t __len, const char * __modes) throw(); 
# 325
extern FILE *open_memstream(char ** __bufloc, ::size_t * __sizeloc) throw(); 
# 332
extern void setbuf(FILE *__restrict__ __stream, char *__restrict__ __buf) throw(); 
# 336
extern int setvbuf(FILE *__restrict__ __stream, char *__restrict__ __buf, int __modes, ::size_t __n) throw(); 
# 343
extern void setbuffer(FILE *__restrict__ __stream, char *__restrict__ __buf, ::size_t __size) throw(); 
# 347
extern void setlinebuf(FILE * __stream) throw(); 
# 356
extern int fprintf(FILE *__restrict__ __stream, const char *__restrict__ __format, ...); 
# 362
extern int printf(const char *__restrict__ __format, ...); 
# 364
extern int sprintf(char *__restrict__ __s, const char *__restrict__ __format, ...) throw(); 
# 371
extern int vfprintf(FILE *__restrict__ __s, const char *__restrict__ __format, __gnuc_va_list __arg); 
# 377
extern int vprintf(const char *__restrict__ __format, __gnuc_va_list __arg); 
# 379
extern int vsprintf(char *__restrict__ __s, const char *__restrict__ __format, __gnuc_va_list __arg) throw(); 
# 386
extern int snprintf(char *__restrict__ __s, ::size_t __maxlen, const char *__restrict__ __format, ...) throw()
# 388
 __attribute((__format__(__printf__, 3, 4))); 
# 390
extern int vsnprintf(char *__restrict__ __s, ::size_t __maxlen, const char *__restrict__ __format, __gnuc_va_list __arg) throw()
# 392
 __attribute((__format__(__printf__, 3, 0))); 
# 399
extern int vasprintf(char **__restrict__ __ptr, const char *__restrict__ __f, __gnuc_va_list __arg) throw()
# 401
 __attribute((__format__(__printf__, 2, 0))); 
# 402
extern int __asprintf(char **__restrict__ __ptr, const char *__restrict__ __fmt, ...) throw()
# 404
 __attribute((__format__(__printf__, 2, 3))); 
# 405
extern int asprintf(char **__restrict__ __ptr, const char *__restrict__ __fmt, ...) throw()
# 407
 __attribute((__format__(__printf__, 2, 3))); 
# 412
extern int vdprintf(int __fd, const char *__restrict__ __fmt, __gnuc_va_list __arg)
# 414
 __attribute((__format__(__printf__, 2, 0))); 
# 415
extern int dprintf(int __fd, const char *__restrict__ __fmt, ...)
# 416
 __attribute((__format__(__printf__, 2, 3))); 
# 425
extern int fscanf(FILE *__restrict__ __stream, const char *__restrict__ __format, ...); 
# 431
extern int scanf(const char *__restrict__ __format, ...); 
# 433
extern int sscanf(const char *__restrict__ __s, const char *__restrict__ __format, ...) throw(); 
# 471
extern int vfscanf(FILE *__restrict__ __s, const char *__restrict__ __format, __gnuc_va_list __arg)
# 473
 __attribute((__format__(__scanf__, 2, 0))); 
# 479
extern int vscanf(const char *__restrict__ __format, __gnuc_va_list __arg)
# 480
 __attribute((__format__(__scanf__, 1, 0))); 
# 483
extern int vsscanf(const char *__restrict__ __s, const char *__restrict__ __format, __gnuc_va_list __arg) throw()
# 485
 __attribute((__format__(__scanf__, 2, 0))); 
# 531
extern int fgetc(FILE * __stream); 
# 532
extern int getc(FILE * __stream); 
# 538
extern int getchar(); 
# 550
extern int getc_unlocked(FILE * __stream); 
# 551
extern int getchar_unlocked(); 
# 561
extern int fgetc_unlocked(FILE * __stream); 
# 573
extern int fputc(int __c, FILE * __stream); 
# 574
extern int putc(int __c, FILE * __stream); 
# 580
extern int putchar(int __c); 
# 594
extern int fputc_unlocked(int __c, FILE * __stream); 
# 602
extern int putc_unlocked(int __c, FILE * __stream); 
# 603
extern int putchar_unlocked(int __c); 
# 610
extern int getw(FILE * __stream); 
# 613
extern int putw(int __w, FILE * __stream); 
# 622
extern char *fgets(char *__restrict__ __s, int __n, FILE *__restrict__ __stream); 
# 638
extern char *gets(char * __s) __attribute((__deprecated__)); 
# 649
extern char *fgets_unlocked(char *__restrict__ __s, int __n, FILE *__restrict__ __stream); 
# 665
extern __ssize_t __getdelim(char **__restrict__ __lineptr, ::size_t *__restrict__ __n, int __delimiter, FILE *__restrict__ __stream); 
# 668
extern __ssize_t getdelim(char **__restrict__ __lineptr, ::size_t *__restrict__ __n, int __delimiter, FILE *__restrict__ __stream); 
# 678
extern __ssize_t getline(char **__restrict__ __lineptr, ::size_t *__restrict__ __n, FILE *__restrict__ __stream); 
# 689
extern int fputs(const char *__restrict__ __s, FILE *__restrict__ __stream); 
# 695
extern int puts(const char * __s); 
# 702
extern int ungetc(int __c, FILE * __stream); 
# 709
extern ::size_t fread(void *__restrict__ __ptr, ::size_t __size, ::size_t __n, FILE *__restrict__ __stream); 
# 715
extern ::size_t fwrite(const void *__restrict__ __ptr, ::size_t __size, ::size_t __n, FILE *__restrict__ __s); 
# 726
extern int fputs_unlocked(const char *__restrict__ __s, FILE *__restrict__ __stream); 
# 737
extern ::size_t fread_unlocked(void *__restrict__ __ptr, ::size_t __size, ::size_t __n, FILE *__restrict__ __stream); 
# 739
extern ::size_t fwrite_unlocked(const void *__restrict__ __ptr, ::size_t __size, ::size_t __n, FILE *__restrict__ __stream); 
# 749
extern int fseek(FILE * __stream, long __off, int __whence); 
# 754
extern long ftell(FILE * __stream); 
# 759
extern void rewind(FILE * __stream); 
# 773
extern int fseeko(FILE * __stream, __off_t __off, int __whence); 
# 778
extern __off_t ftello(FILE * __stream); 
# 798
extern int fgetpos(FILE *__restrict__ __stream, fpos_t *__restrict__ __pos); 
# 803
extern int fsetpos(FILE * __stream, const fpos_t * __pos); 
# 818
extern int fseeko64(FILE * __stream, __off64_t __off, int __whence); 
# 819
extern __off64_t ftello64(FILE * __stream); 
# 820
extern int fgetpos64(FILE *__restrict__ __stream, fpos64_t *__restrict__ __pos); 
# 821
extern int fsetpos64(FILE * __stream, const fpos64_t * __pos); 
# 826
extern void clearerr(FILE * __stream) throw(); 
# 828
extern int feof(FILE * __stream) throw(); 
# 830
extern int ferror(FILE * __stream) throw(); 
# 835
extern void clearerr_unlocked(FILE * __stream) throw(); 
# 836
extern int feof_unlocked(FILE * __stream) throw(); 
# 837
extern int ferror_unlocked(FILE * __stream) throw(); 
# 846
extern void perror(const char * __s); 
# 26 "/usr/include/bits/sys_errlist.h" 3
extern int sys_nerr; 
# 27
extern const char *const sys_errlist[]; 
# 30
extern int _sys_nerr; 
# 31
extern const char *const _sys_errlist[]; 
# 858 "/usr/include/stdio.h" 3
extern int fileno(FILE * __stream) throw(); 
# 863
extern int fileno_unlocked(FILE * __stream) throw(); 
# 873
extern FILE *popen(const char * __command, const char * __modes); 
# 879
extern int pclose(FILE * __stream); 
# 885
extern char *ctermid(char * __s) throw(); 
# 891
extern char *cuserid(char * __s); 
# 896
struct obstack; 
# 899
extern int obstack_printf(obstack *__restrict__ __obstack, const char *__restrict__ __format, ...) throw()
# 901
 __attribute((__format__(__printf__, 2, 3))); 
# 902
extern int obstack_vprintf(obstack *__restrict__ __obstack, const char *__restrict__ __format, __gnuc_va_list __args) throw()
# 905
 __attribute((__format__(__printf__, 2, 0))); 
# 913
extern void flockfile(FILE * __stream) throw(); 
# 917
extern int ftrylockfile(FILE * __stream) throw(); 
# 920
extern void funlockfile(FILE * __stream) throw(); 
# 943
}
# 50 "/usr/include/c++/4.8.2/bits/memoryfwd.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 63
template< class > class allocator; 
# 67
template<> class allocator< void> ; 
# 70
template< class , class > struct uses_allocator; 
# 76
}
# 42 "/usr/include/c++/4.8.2/bits/stringfwd.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 52
template< class _CharT> struct char_traits; 
# 55
template< class _CharT, class _Traits = char_traits< _CharT> , class 
# 56
_Alloc = allocator< _CharT> > class basic_string; 
# 59
template<> struct char_traits< char> ; 
# 62
typedef basic_string< char>  string; 
# 65
template<> struct char_traits< wchar_t> ; 
# 68
typedef basic_string< wchar_t>  wstring; 
# 87
}
# 353 "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h" 3
typedef unsigned wint_t; 
# 106 "/usr/include/wchar.h" 3
typedef __mbstate_t mbstate_t; 
# 132
extern "C" {
# 137
struct tm; 
# 147
extern wchar_t *wcscpy(wchar_t *__restrict__ __dest, const wchar_t *__restrict__ __src) throw(); 
# 150
extern wchar_t *wcsncpy(wchar_t *__restrict__ __dest, const wchar_t *__restrict__ __src, ::size_t __n) throw(); 
# 155
extern wchar_t *wcscat(wchar_t *__restrict__ __dest, const wchar_t *__restrict__ __src) throw(); 
# 158
extern wchar_t *wcsncat(wchar_t *__restrict__ __dest, const wchar_t *__restrict__ __src, ::size_t __n) throw(); 
# 163
extern int wcscmp(const wchar_t * __s1, const wchar_t * __s2) throw()
# 164
 __attribute((__pure__)); 
# 166
extern int wcsncmp(const wchar_t * __s1, const wchar_t * __s2, ::size_t __n) throw()
# 167
 __attribute((__pure__)); 
# 172
extern int wcscasecmp(const wchar_t * __s1, const wchar_t * __s2) throw(); 
# 175
extern int wcsncasecmp(const wchar_t * __s1, const wchar_t * __s2, ::size_t __n) throw(); 
# 182
extern int wcscasecmp_l(const wchar_t * __s1, const wchar_t * __s2, __locale_t __loc) throw(); 
# 185
extern int wcsncasecmp_l(const wchar_t * __s1, const wchar_t * __s2, ::size_t __n, __locale_t __loc) throw(); 
# 192
extern int wcscoll(const wchar_t * __s1, const wchar_t * __s2) throw(); 
# 196
extern ::size_t wcsxfrm(wchar_t *__restrict__ __s1, const wchar_t *__restrict__ __s2, ::size_t __n) throw(); 
# 206
extern int wcscoll_l(const wchar_t * __s1, const wchar_t * __s2, __locale_t __loc) throw(); 
# 212
extern ::size_t wcsxfrm_l(wchar_t * __s1, const wchar_t * __s2, ::size_t __n, __locale_t __loc) throw(); 
# 216
extern wchar_t *wcsdup(const wchar_t * __s) throw() __attribute((__malloc__)); 
# 222
extern "C++" wchar_t *wcschr(wchar_t * __wcs, wchar_t __wc) throw() __asm__("wcschr")
# 223
 __attribute((__pure__)); 
# 224
extern "C++" const wchar_t *wcschr(const wchar_t * __wcs, wchar_t __wc) throw() __asm__("wcschr")
# 225
 __attribute((__pure__)); 
# 232
extern "C++" wchar_t *wcsrchr(wchar_t * __wcs, wchar_t __wc) throw() __asm__("wcsrchr")
# 233
 __attribute((__pure__)); 
# 234
extern "C++" const wchar_t *wcsrchr(const wchar_t * __wcs, wchar_t __wc) throw() __asm__("wcsrchr")
# 235
 __attribute((__pure__)); 
# 245
extern wchar_t *wcschrnul(const wchar_t * __s, wchar_t __wc) throw()
# 246
 __attribute((__pure__)); 
# 252
extern ::size_t wcscspn(const wchar_t * __wcs, const wchar_t * __reject) throw()
# 253
 __attribute((__pure__)); 
# 256
extern ::size_t wcsspn(const wchar_t * __wcs, const wchar_t * __accept) throw()
# 257
 __attribute((__pure__)); 
# 260
extern "C++" wchar_t *wcspbrk(wchar_t * __wcs, const wchar_t * __accept) throw() __asm__("wcspbrk")
# 261
 __attribute((__pure__)); 
# 262
extern "C++" const wchar_t *wcspbrk(const wchar_t * __wcs, const wchar_t * __accept) throw() __asm__("wcspbrk")
# 264
 __attribute((__pure__)); 
# 271
extern "C++" wchar_t *wcsstr(wchar_t * __haystack, const wchar_t * __needle) throw() __asm__("wcsstr")
# 272
 __attribute((__pure__)); 
# 273
extern "C++" const wchar_t *wcsstr(const wchar_t * __haystack, const wchar_t * __needle) throw() __asm__("wcsstr")
# 275
 __attribute((__pure__)); 
# 282
extern wchar_t *wcstok(wchar_t *__restrict__ __s, const wchar_t *__restrict__ __delim, wchar_t **__restrict__ __ptr) throw(); 
# 287
extern ::size_t wcslen(const wchar_t * __s) throw() __attribute((__pure__)); 
# 293
extern "C++" wchar_t *wcswcs(wchar_t * __haystack, const wchar_t * __needle) throw() __asm__("wcswcs")
# 294
 __attribute((__pure__)); 
# 295
extern "C++" const wchar_t *wcswcs(const wchar_t * __haystack, const wchar_t * __needle) throw() __asm__("wcswcs")
# 297
 __attribute((__pure__)); 
# 306
extern ::size_t wcsnlen(const wchar_t * __s, ::size_t __maxlen) throw()
# 307
 __attribute((__pure__)); 
# 314
extern "C++" wchar_t *wmemchr(wchar_t * __s, wchar_t __c, ::size_t __n) throw() __asm__("wmemchr")
# 315
 __attribute((__pure__)); 
# 316
extern "C++" const wchar_t *wmemchr(const wchar_t * __s, wchar_t __c, ::size_t __n) throw() __asm__("wmemchr")
# 318
 __attribute((__pure__)); 
# 325
extern int wmemcmp(const wchar_t * __s1, const wchar_t * __s2, ::size_t __n) throw()
# 326
 __attribute((__pure__)); 
# 329
extern wchar_t *wmemcpy(wchar_t *__restrict__ __s1, const wchar_t *__restrict__ __s2, ::size_t __n) throw(); 
# 334
extern wchar_t *wmemmove(wchar_t * __s1, const wchar_t * __s2, ::size_t __n) throw(); 
# 338
extern wchar_t *wmemset(wchar_t * __s, wchar_t __c, ::size_t __n) throw(); 
# 344
extern wchar_t *wmempcpy(wchar_t *__restrict__ __s1, const wchar_t *__restrict__ __s2, ::size_t __n) throw(); 
# 353
extern wint_t btowc(int __c) throw(); 
# 357
extern int wctob(wint_t __c) throw(); 
# 361
extern int mbsinit(const mbstate_t * __ps) throw() __attribute((__pure__)); 
# 365
extern ::size_t mbrtowc(wchar_t *__restrict__ __pwc, const char *__restrict__ __s, ::size_t __n, mbstate_t *__restrict__ __p) throw(); 
# 370
extern ::size_t wcrtomb(char *__restrict__ __s, wchar_t __wc, mbstate_t *__restrict__ __ps) throw(); 
# 374
extern ::size_t __mbrlen(const char *__restrict__ __s, ::size_t __n, mbstate_t *__restrict__ __ps) throw(); 
# 376
extern ::size_t mbrlen(const char *__restrict__ __s, ::size_t __n, mbstate_t *__restrict__ __ps) throw(); 
# 408
extern ::size_t mbsrtowcs(wchar_t *__restrict__ __dst, const char **__restrict__ __src, ::size_t __len, mbstate_t *__restrict__ __ps) throw(); 
# 414
extern ::size_t wcsrtombs(char *__restrict__ __dst, const wchar_t **__restrict__ __src, ::size_t __len, mbstate_t *__restrict__ __ps) throw(); 
# 423
extern ::size_t mbsnrtowcs(wchar_t *__restrict__ __dst, const char **__restrict__ __src, ::size_t __nmc, ::size_t __len, mbstate_t *__restrict__ __ps) throw(); 
# 429
extern ::size_t wcsnrtombs(char *__restrict__ __dst, const wchar_t **__restrict__ __src, ::size_t __nwc, ::size_t __len, mbstate_t *__restrict__ __ps) throw(); 
# 439
extern int wcwidth(wchar_t __c) throw(); 
# 443
extern int wcswidth(const wchar_t * __s, ::size_t __n) throw(); 
# 450
extern double wcstod(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr) throw(); 
# 457
extern float wcstof(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr) throw(); 
# 459
extern long double wcstold(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr) throw(); 
# 468
extern long wcstol(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base) throw(); 
# 473
extern unsigned long wcstoul(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base) throw(); 
# 483
__extension__ extern long long wcstoll(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base) throw(); 
# 490
__extension__ extern unsigned long long wcstoull(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base) throw(); 
# 500
__extension__ extern long long wcstoq(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base) throw(); 
# 507
__extension__ extern unsigned long long wcstouq(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base) throw(); 
# 530
extern long wcstol_l(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base, __locale_t __loc) throw(); 
# 534
extern unsigned long wcstoul_l(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base, __locale_t __loc) throw(); 
# 539
__extension__ extern long long wcstoll_l(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base, __locale_t __loc) throw(); 
# 544
__extension__ extern unsigned long long wcstoull_l(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, int __base, __locale_t __loc) throw(); 
# 549
extern double wcstod_l(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, __locale_t __loc) throw(); 
# 553
extern float wcstof_l(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, __locale_t __loc) throw(); 
# 557
extern long double wcstold_l(const wchar_t *__restrict__ __nptr, wchar_t **__restrict__ __endptr, __locale_t __loc) throw(); 
# 566
extern wchar_t *wcpcpy(wchar_t *__restrict__ __dest, const wchar_t *__restrict__ __src) throw(); 
# 571
extern wchar_t *wcpncpy(wchar_t *__restrict__ __dest, const wchar_t *__restrict__ __src, ::size_t __n) throw(); 
# 580
extern __FILE *open_wmemstream(wchar_t ** __bufloc, ::size_t * __sizeloc) throw(); 
# 587
extern int fwide(__FILE * __fp, int __mode) throw(); 
# 594
extern int fwprintf(__FILE *__restrict__ __stream, const wchar_t *__restrict__ __format, ...); 
# 601
extern int wprintf(const wchar_t *__restrict__ __format, ...); 
# 604
extern int swprintf(wchar_t *__restrict__ __s, ::size_t __n, const wchar_t *__restrict__ __format, ...) throw(); 
# 612
extern int vfwprintf(__FILE *__restrict__ __s, const wchar_t *__restrict__ __format, __gnuc_va_list __arg); 
# 620
extern int vwprintf(const wchar_t *__restrict__ __format, __gnuc_va_list __arg); 
# 625
extern int vswprintf(wchar_t *__restrict__ __s, ::size_t __n, const wchar_t *__restrict__ __format, __gnuc_va_list __arg) throw(); 
# 635
extern int fwscanf(__FILE *__restrict__ __stream, const wchar_t *__restrict__ __format, ...); 
# 642
extern int wscanf(const wchar_t *__restrict__ __format, ...); 
# 645
extern int swscanf(const wchar_t *__restrict__ __s, const wchar_t *__restrict__ __format, ...) throw(); 
# 689
extern int vfwscanf(__FILE *__restrict__ __s, const wchar_t *__restrict__ __format, __gnuc_va_list __arg); 
# 697
extern int vwscanf(const wchar_t *__restrict__ __format, __gnuc_va_list __arg); 
# 701
extern int vswscanf(const wchar_t *__restrict__ __s, const wchar_t *__restrict__ __format, __gnuc_va_list __arg) throw(); 
# 745
extern wint_t fgetwc(__FILE * __stream); 
# 746
extern wint_t getwc(__FILE * __stream); 
# 752
extern wint_t getwchar(); 
# 759
extern wint_t fputwc(wchar_t __wc, __FILE * __stream); 
# 760
extern wint_t putwc(wchar_t __wc, __FILE * __stream); 
# 766
extern wint_t putwchar(wchar_t __wc); 
# 774
extern wchar_t *fgetws(wchar_t *__restrict__ __ws, int __n, __FILE *__restrict__ __stream); 
# 781
extern int fputws(const wchar_t *__restrict__ __ws, __FILE *__restrict__ __stream); 
# 789
extern wint_t ungetwc(wint_t __wc, __FILE * __stream); 
# 801
extern wint_t getwc_unlocked(__FILE * __stream); 
# 802
extern wint_t getwchar_unlocked(); 
# 810
extern wint_t fgetwc_unlocked(__FILE * __stream); 
# 818
extern wint_t fputwc_unlocked(wchar_t __wc, __FILE * __stream); 
# 827
extern wint_t putwc_unlocked(wchar_t __wc, __FILE * __stream); 
# 828
extern wint_t putwchar_unlocked(wchar_t __wc); 
# 837
extern wchar_t *fgetws_unlocked(wchar_t *__restrict__ __ws, int __n, __FILE *__restrict__ __stream); 
# 846
extern int fputws_unlocked(const wchar_t *__restrict__ __ws, __FILE *__restrict__ __stream); 
# 855
extern ::size_t wcsftime(wchar_t *__restrict__ __s, ::size_t __maxsize, const wchar_t *__restrict__ __format, const tm *__restrict__ __tp) throw(); 
# 865
extern ::size_t wcsftime_l(wchar_t *__restrict__ __s, ::size_t __maxsize, const wchar_t *__restrict__ __format, const tm *__restrict__ __tp, __locale_t __loc) throw(); 
# 891
}
# 62 "/usr/include/c++/4.8.2/cwchar" 3
namespace std { 
# 64
using ::mbstate_t;
# 65
}
# 135
namespace std __attribute((__visibility__("default"))) { 
# 139
using ::wint_t;
# 141
using ::btowc;
# 142
using ::fgetwc;
# 143
using ::fgetws;
# 144
using ::fputwc;
# 145
using ::fputws;
# 146
using ::fwide;
# 147
using ::fwprintf;
# 148
using ::fwscanf;
# 149
using ::getwc;
# 150
using ::getwchar;
# 151
using ::mbrlen;
# 152
using ::mbrtowc;
# 153
using ::mbsinit;
# 154
using ::mbsrtowcs;
# 155
using ::putwc;
# 156
using ::putwchar;
# 158
using ::swprintf;
# 160
using ::swscanf;
# 161
using ::ungetwc;
# 162
using ::vfwprintf;
# 164
using ::vfwscanf;
# 167
using ::vswprintf;
# 170
using ::vswscanf;
# 172
using ::vwprintf;
# 174
using ::vwscanf;
# 176
using ::wcrtomb;
# 177
using ::wcscat;
# 178
using ::wcscmp;
# 179
using ::wcscoll;
# 180
using ::wcscpy;
# 181
using ::wcscspn;
# 182
using ::wcsftime;
# 183
using ::wcslen;
# 184
using ::wcsncat;
# 185
using ::wcsncmp;
# 186
using ::wcsncpy;
# 187
using ::wcsrtombs;
# 188
using ::wcsspn;
# 189
using ::wcstod;
# 191
using ::wcstof;
# 193
using ::wcstok;
# 194
using ::wcstol;
# 195
using ::wcstoul;
# 196
using ::wcsxfrm;
# 197
using ::wctob;
# 198
using ::wmemcmp;
# 199
using ::wmemcpy;
# 200
using ::wmemmove;
# 201
using ::wmemset;
# 202
using ::wprintf;
# 203
using ::wscanf;
# 204
using ::wcschr;
# 205
using ::wcspbrk;
# 206
using ::wcsrchr;
# 207
using ::wcsstr;
# 208
using ::wmemchr;
# 233
}
# 241
namespace __gnu_cxx { 
# 248
using ::wcstold;
# 257
using ::wcstoll;
# 258
using ::wcstoull;
# 260
}
# 262
namespace std { 
# 264
using __gnu_cxx::wcstold;
# 265
using __gnu_cxx::wcstoll;
# 266
using __gnu_cxx::wcstoull;
# 267
}
# 68 "/usr/include/c++/4.8.2/bits/postypes.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 88
typedef long streamoff; 
# 98
typedef ptrdiff_t streamsize; 
# 111
template< class _StateT> 
# 112
class fpos { 
# 115
streamoff _M_off; 
# 116
_StateT _M_state; 
# 123
public: fpos() : _M_off((0)), _M_state() 
# 124
{ } 
# 133
fpos(streamoff __off) : _M_off(__off), _M_state() 
# 134
{ } 
# 137
operator streamoff() const { return _M_off; } 
# 141
void state(_StateT __st) 
# 142
{ (_M_state) = __st; } 
# 146
_StateT state() const 
# 147
{ return _M_state; } 
# 154
fpos &operator+=(streamoff __off) 
# 155
{ 
# 156
(_M_off) += __off; 
# 157
return *this; 
# 158
} 
# 165
fpos &operator-=(streamoff __off) 
# 166
{ 
# 167
(_M_off) -= __off; 
# 168
return *this; 
# 169
} 
# 178
fpos operator+(streamoff __off) const 
# 179
{ 
# 180
fpos __pos(*this); 
# 181
__pos += __off; 
# 182
return __pos; 
# 183
} 
# 192
fpos operator-(streamoff __off) const 
# 193
{ 
# 194
fpos __pos(*this); 
# 195
__pos -= __off; 
# 196
return __pos; 
# 197
} 
# 205
streamoff operator-(const fpos &__other) const 
# 206
{ return (_M_off) - (__other._M_off); } 
# 207
}; 
# 214
template< class _StateT> inline bool 
# 216
operator==(const fpos< _StateT>  &__lhs, const fpos< _StateT>  &__rhs) 
# 217
{ return ((streamoff)__lhs) == ((streamoff)__rhs); } 
# 219
template< class _StateT> inline bool 
# 221
operator!=(const fpos< _StateT>  &__lhs, const fpos< _StateT>  &__rhs) 
# 222
{ return ((streamoff)__lhs) != ((streamoff)__rhs); } 
# 228
typedef fpos< __mbstate_t>  streampos; 
# 230
typedef fpos< __mbstate_t>  wstreampos; 
# 240
}
# 42 "/usr/include/c++/4.8.2/iosfwd" 3
namespace std __attribute((__visibility__("default"))) { 
# 74
class ios_base; 
# 76
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_ios; 
# 79
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_streambuf; 
# 82
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_istream; 
# 85
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_ostream; 
# 88
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_iostream; 
# 91
template< class _CharT, class _Traits = char_traits< _CharT> , class 
# 92
_Alloc = allocator< _CharT> > class basic_stringbuf; 
# 95
template< class _CharT, class _Traits = char_traits< _CharT> , class 
# 96
_Alloc = allocator< _CharT> > class basic_istringstream; 
# 99
template< class _CharT, class _Traits = char_traits< _CharT> , class 
# 100
_Alloc = allocator< _CharT> > class basic_ostringstream; 
# 103
template< class _CharT, class _Traits = char_traits< _CharT> , class 
# 104
_Alloc = allocator< _CharT> > class basic_stringstream; 
# 107
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_filebuf; 
# 110
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_ifstream; 
# 113
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_ofstream; 
# 116
template< class _CharT, class _Traits = char_traits< _CharT> > class basic_fstream; 
# 119
template< class _CharT, class _Traits = char_traits< _CharT> > class istreambuf_iterator; 
# 122
template< class _CharT, class _Traits = char_traits< _CharT> > class ostreambuf_iterator; 
# 127
typedef basic_ios< char>  ios; 
# 130
typedef basic_streambuf< char>  streambuf; 
# 133
typedef basic_istream< char>  istream; 
# 136
typedef basic_ostream< char>  ostream; 
# 139
typedef basic_iostream< char>  iostream; 
# 142
typedef basic_stringbuf< char>  stringbuf; 
# 145
typedef basic_istringstream< char>  istringstream; 
# 148
typedef basic_ostringstream< char>  ostringstream; 
# 151
typedef basic_stringstream< char>  stringstream; 
# 154
typedef basic_filebuf< char>  filebuf; 
# 157
typedef basic_ifstream< char>  ifstream; 
# 160
typedef basic_ofstream< char>  ofstream; 
# 163
typedef basic_fstream< char>  fstream; 
# 167
typedef basic_ios< wchar_t>  wios; 
# 170
typedef basic_streambuf< wchar_t>  wstreambuf; 
# 173
typedef basic_istream< wchar_t>  wistream; 
# 176
typedef basic_ostream< wchar_t>  wostream; 
# 179
typedef basic_iostream< wchar_t>  wiostream; 
# 182
typedef basic_stringbuf< wchar_t>  wstringbuf; 
# 185
typedef basic_istringstream< wchar_t>  wistringstream; 
# 188
typedef basic_ostringstream< wchar_t>  wostringstream; 
# 191
typedef basic_stringstream< wchar_t>  wstringstream; 
# 194
typedef basic_filebuf< wchar_t>  wfilebuf; 
# 197
typedef basic_ifstream< wchar_t>  wifstream; 
# 200
typedef basic_ofstream< wchar_t>  wofstream; 
# 203
typedef basic_fstream< wchar_t>  wfstream; 
# 208
}
# 35 "/usr/include/c++/4.8.2/exception" 3
#pragma GCC visibility push ( default )
# 40
extern "C++" {
# 42
namespace std { 
# 60
class exception { 
# 63
public: exception() throw() { } 
# 64
virtual ~exception() throw(); 
# 68
virtual const char *what() const throw(); 
# 69
}; 
# 73
class bad_exception : public exception { 
# 76
public: bad_exception() throw() { } 
# 80
virtual ~bad_exception() throw(); 
# 83
virtual const char *what() const throw(); 
# 84
}; 
# 87
typedef void (*terminate_handler)(void); 
# 90
typedef void (*unexpected_handler)(void); 
# 93
terminate_handler set_terminate(terminate_handler) throw(); 
# 97
void terminate() throw() __attribute((__noreturn__)); 
# 100
unexpected_handler set_unexpected(unexpected_handler) throw(); 
# 104
void unexpected() __attribute((__noreturn__)); 
# 117
bool uncaught_exception() throw() __attribute((__pure__)); 
# 120
}
# 122
namespace __gnu_cxx { 
# 142
void __verbose_terminate_handler(); 
# 145
}
# 147
}
# 149
#pragma GCC visibility pop
# 42 "/usr/include/c++/4.8.2/bits/functexcept.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 48
void __throw_bad_exception() __attribute((__noreturn__)); 
# 52
void __throw_bad_alloc() __attribute((__noreturn__)); 
# 56
void __throw_bad_cast() __attribute((__noreturn__)); 
# 59
void __throw_bad_typeid() __attribute((__noreturn__)); 
# 63
void __throw_logic_error(const char *) __attribute((__noreturn__)); 
# 66
void __throw_domain_error(const char *) __attribute((__noreturn__)); 
# 69
void __throw_invalid_argument(const char *) __attribute((__noreturn__)); 
# 72
void __throw_length_error(const char *) __attribute((__noreturn__)); 
# 75
void __throw_out_of_range(const char *) __attribute((__noreturn__)); 
# 78
void __throw_runtime_error(const char *) __attribute((__noreturn__)); 
# 81
void __throw_range_error(const char *) __attribute((__noreturn__)); 
# 84
void __throw_overflow_error(const char *) __attribute((__noreturn__)); 
# 87
void __throw_underflow_error(const char *) __attribute((__noreturn__)); 
# 91
void __throw_ios_failure(const char *) __attribute((__noreturn__)); 
# 94
void __throw_system_error(int) __attribute((__noreturn__)); 
# 97
void __throw_future_error(int) __attribute((__noreturn__)); 
# 101
void __throw_bad_function_call() __attribute((__noreturn__)); 
# 104
}
# 37 "/usr/include/c++/4.8.2/ext/numeric_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 54
template< class _Value> 
# 55
struct __numeric_traits_integer { 
# 58
static const _Value __min = ((((_Value)(-1)) < 0) ? ((_Value)1) << ((sizeof(_Value) * (8)) - (((_Value)(-1)) < 0)) : ((_Value)0)); 
# 59
static const _Value __max = ((((_Value)(-1)) < 0) ? (((((_Value)1) << (((sizeof(_Value) * (8)) - (((_Value)(-1)) < 0)) - (1))) - 1) << 1) + 1 : (~((_Value)0))); 
# 63
static const bool __is_signed = (((_Value)(-1)) < 0); 
# 64
static const int __digits = ((sizeof(_Value) * (8)) - (((_Value)(-1)) < 0)); 
# 65
}; 
# 67
template< class _Value> const _Value 
# 68
__numeric_traits_integer< _Value> ::__min; 
# 70
template< class _Value> const _Value 
# 71
__numeric_traits_integer< _Value> ::__max; 
# 73
template< class _Value> const bool 
# 74
__numeric_traits_integer< _Value> ::__is_signed; 
# 76
template< class _Value> const int 
# 77
__numeric_traits_integer< _Value> ::__digits; 
# 99
template< class _Value> 
# 100
struct __numeric_traits_floating { 
# 103
static const int __max_digits10 = ((2) + ((((std::__are_same< _Value, float> ::__value) ? 24 : ((std::__are_same< _Value, double> ::__value) ? 53 : 64)) * 643L) / (2136))); 
# 106
static const bool __is_signed = true; 
# 107
static const int __digits10 = ((std::__are_same< _Value, float> ::__value) ? 6 : ((std::__are_same< _Value, double> ::__value) ? 15 : 18)); 
# 108
static const int __max_exponent10 = ((std::__are_same< _Value, float> ::__value) ? 38 : ((std::__are_same< _Value, double> ::__value) ? 308 : 4932)); 
# 109
}; 
# 111
template< class _Value> const int 
# 112
__numeric_traits_floating< _Value> ::__max_digits10; 
# 114
template< class _Value> const bool 
# 115
__numeric_traits_floating< _Value> ::__is_signed; 
# 117
template< class _Value> const int 
# 118
__numeric_traits_floating< _Value> ::__digits10; 
# 120
template< class _Value> const int 
# 121
__numeric_traits_floating< _Value> ::__max_exponent10; 
# 123
template< class _Value> 
# 124
struct __numeric_traits : public __conditional_type< std::__is_integer< _Value> ::__value, __numeric_traits_integer< _Value> , __numeric_traits_floating< _Value> > ::__type { 
# 128
}; 
# 131
}
# 36 "/usr/include/c++/4.8.2/bits/move.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 45
template< class _Tp> inline _Tp *
# 47
__addressof(_Tp &__r) 
# 48
{ 
# 49
return reinterpret_cast< _Tp *>(&(const_cast< char &>(reinterpret_cast< const volatile char &>(__r)))); 
# 51
} 
# 54
}
# 149
namespace std __attribute((__visibility__("default"))) { 
# 164
template< class _Tp> inline void 
# 166
swap(_Tp &__a, _Tp &__b) 
# 171
{ 
# 175
_Tp __tmp = __a; 
# 176
__a = __b; 
# 177
__b = __tmp; 
# 178
} 
# 183
template< class _Tp, size_t _Nm> inline void 
# 185
swap(_Tp (&__a)[_Nm], _Tp (&__b)[_Nm]) 
# 189
{ 
# 190
for (size_t __n = (0); __n < _Nm; ++__n) { 
# 191
swap((__a)[__n], (__b)[__n]); }  
# 192
} 
# 196
}
# 65 "/usr/include/c++/4.8.2/bits/stl_pair.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 95
template< class _T1, class _T2> 
# 96
struct pair { 
# 98
typedef _T1 first_type; 
# 99
typedef _T2 second_type; 
# 101
_T1 first; 
# 102
_T2 second; 
# 108
pair() : first(), second() 
# 109
{ } 
# 112
pair(const _T1 &__a, const _T2 &__b) : first(__a), second(__b) 
# 113
{ } 
# 117
template< class _U1, class _U2> 
# 118
pair(const std::pair< _U1, _U2>  &__p) : first((__p.first)), second((__p.second)) 
# 119
{ } 
# 209
}; 
# 212
template< class _T1, class _T2> inline bool 
# 214
operator==(const pair< _T1, _T2>  &__x, const pair< _T1, _T2>  &__y) 
# 215
{ return ((__x.first) == (__y.first)) && ((__x.second) == (__y.second)); } 
# 218
template< class _T1, class _T2> inline bool 
# 220
operator<(const pair< _T1, _T2>  &__x, const pair< _T1, _T2>  &__y) 
# 221
{ return ((__x.first) < (__y.first)) || ((!((__y.first) < (__x.first))) && ((__x.second) < (__y.second))); 
# 222
} 
# 225
template< class _T1, class _T2> inline bool 
# 227
operator!=(const pair< _T1, _T2>  &__x, const pair< _T1, _T2>  &__y) 
# 228
{ return !(__x == __y); } 
# 231
template< class _T1, class _T2> inline bool 
# 233
operator>(const pair< _T1, _T2>  &__x, const pair< _T1, _T2>  &__y) 
# 234
{ return __y < __x; } 
# 237
template< class _T1, class _T2> inline bool 
# 239
operator<=(const pair< _T1, _T2>  &__x, const pair< _T1, _T2>  &__y) 
# 240
{ return !(__y < __x); } 
# 243
template< class _T1, class _T2> inline bool 
# 245
operator>=(const pair< _T1, _T2>  &__x, const pair< _T1, _T2>  &__y) 
# 246
{ return !(__x < __y); } 
# 284
template< class _T1, class _T2> inline pair< _T1, _T2>  
# 286
make_pair(_T1 __x, _T2 __y) 
# 287
{ return pair< _T1, _T2> (__x, __y); } 
# 293
}
# 70 "/usr/include/c++/4.8.2/bits/stl_iterator_base_types.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 89
struct input_iterator_tag { }; 
# 92
struct output_iterator_tag { }; 
# 95
struct forward_iterator_tag : public input_iterator_tag { }; 
# 99
struct bidirectional_iterator_tag : public forward_iterator_tag { }; 
# 103
struct random_access_iterator_tag : public bidirectional_iterator_tag { }; 
# 116
template< class _Category, class _Tp, class _Distance = ptrdiff_t, class 
# 117
_Pointer = _Tp *, class _Reference = _Tp &> 
# 118
struct iterator { 
# 121
typedef _Category iterator_category; 
# 123
typedef _Tp value_type; 
# 125
typedef _Distance difference_type; 
# 127
typedef _Pointer pointer; 
# 129
typedef _Reference reference; 
# 130
}; 
# 162
template< class _Iterator> 
# 163
struct iterator_traits { 
# 165
typedef typename _Iterator::iterator_category iterator_category; 
# 166
typedef typename _Iterator::value_type value_type; 
# 167
typedef typename _Iterator::difference_type difference_type; 
# 168
typedef typename _Iterator::pointer pointer; 
# 169
typedef typename _Iterator::reference reference; 
# 170
}; 
# 174
template< class _Tp> 
# 175
struct iterator_traits< _Tp *>  { 
# 177
typedef random_access_iterator_tag iterator_category; 
# 178
typedef _Tp value_type; 
# 179
typedef ptrdiff_t difference_type; 
# 180
typedef _Tp *pointer; 
# 181
typedef _Tp &reference; 
# 182
}; 
# 185
template< class _Tp> 
# 186
struct iterator_traits< const _Tp *>  { 
# 188
typedef random_access_iterator_tag iterator_category; 
# 189
typedef _Tp value_type; 
# 190
typedef ptrdiff_t difference_type; 
# 191
typedef const _Tp *pointer; 
# 192
typedef const _Tp &reference; 
# 193
}; 
# 199
template< class _Iter> inline typename iterator_traits< _Iter> ::iterator_category 
# 201
__iterator_category(const _Iter &) 
# 202
{ return typename iterator_traits< _Iter> ::iterator_category(); } 
# 208
template< class _Iterator, bool _HasBase> 
# 209
struct _Iter_base { 
# 211
typedef _Iterator iterator_type; 
# 212
static iterator_type _S_base(_Iterator __it) 
# 213
{ return __it; } 
# 214
}; 
# 216
template< class _Iterator> 
# 217
struct _Iter_base< _Iterator, true>  { 
# 219
typedef typename _Iterator::iterator_type iterator_type; 
# 220
static iterator_type _S_base(_Iterator __it) 
# 221
{ return (__it.base()); } 
# 222
}; 
# 233
}
# 46 "/usr/include/c++/4.8.2/debug/debug.h" 3
namespace std { 
# 48
namespace __debug { }
# 49
}
# 54
namespace __gnu_debug { 
# 56
using namespace std::__debug;
# 57
}
# 67 "/usr/include/c++/4.8.2/bits/stl_iterator_base_funcs.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 71
template< class _InputIterator> inline typename iterator_traits< _InputIterator> ::difference_type 
# 73
__distance(_InputIterator __first, _InputIterator __last, input_iterator_tag) 
# 75
{ 
# 79
typename iterator_traits< _InputIterator> ::difference_type __n = (0); 
# 80
while (__first != __last) 
# 81
{ 
# 82
++__first; 
# 83
++__n; 
# 84
}  
# 85
return __n; 
# 86
} 
# 88
template< class _RandomAccessIterator> inline typename iterator_traits< _RandomAccessIterator> ::difference_type 
# 90
__distance(_RandomAccessIterator __first, _RandomAccessIterator __last, random_access_iterator_tag) 
# 92
{ 
# 96
return __last - __first; 
# 97
} 
# 112
template< class _InputIterator> inline typename iterator_traits< _InputIterator> ::difference_type 
# 114
distance(_InputIterator __first, _InputIterator __last) 
# 115
{ 
# 117
return std::__distance(__first, __last, std::__iterator_category(__first)); 
# 119
} 
# 121
template< class _InputIterator, class _Distance> inline void 
# 123
__advance(_InputIterator &__i, _Distance __n, input_iterator_tag) 
# 124
{ 
# 127
; 
# 128
while (__n--) { 
# 129
++__i; }  
# 130
} 
# 132
template< class _BidirectionalIterator, class _Distance> inline void 
# 134
__advance(_BidirectionalIterator &__i, _Distance __n, bidirectional_iterator_tag) 
# 136
{ 
# 140
if (__n > 0) { 
# 141
while (__n--) { 
# 142
++__i; }  } else { 
# 144
while (__n++) { 
# 145
--__i; }  }  
# 146
} 
# 148
template< class _RandomAccessIterator, class _Distance> inline void 
# 150
__advance(_RandomAccessIterator &__i, _Distance __n, random_access_iterator_tag) 
# 152
{ 
# 156
__i += __n; 
# 157
} 
# 171
template< class _InputIterator, class _Distance> inline void 
# 173
advance(_InputIterator &__i, _Distance __n) 
# 174
{ 
# 176
typename iterator_traits< _InputIterator> ::difference_type __d = __n; 
# 177
std::__advance(__i, __d, std::__iterator_category(__i)); 
# 178
} 
# 203
}
# 67 "/usr/include/c++/4.8.2/bits/stl_iterator.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 95
template< class _Iterator> 
# 96
class reverse_iterator : public iterator< typename iterator_traits< _Iterator> ::iterator_category, typename iterator_traits< _Iterator> ::value_type, typename iterator_traits< _Iterator> ::difference_type, typename iterator_traits< _Iterator> ::pointer, typename iterator_traits< _Iterator> ::reference>  { 
# 104
protected: _Iterator current; 
# 106
typedef iterator_traits< _Iterator>  __traits_type; 
# 109
public: typedef _Iterator iterator_type; 
# 110
typedef typename iterator_traits< _Iterator> ::difference_type difference_type; 
# 111
typedef typename iterator_traits< _Iterator> ::pointer pointer; 
# 112
typedef typename iterator_traits< _Iterator> ::reference reference; 
# 120
reverse_iterator() : current() { } 
# 126
explicit reverse_iterator(iterator_type __x) : current(__x) { } 
# 131
reverse_iterator(const reverse_iterator &__x) : current(__x.current) 
# 132
{ } 
# 138
template< class _Iter> 
# 139
reverse_iterator(const ::std::reverse_iterator< _Iter>  &__x) : current((__x.base())) 
# 140
{ } 
# 146
iterator_type base() const 
# 147
{ return current; } 
# 160
reference operator*() const 
# 161
{ 
# 162
_Iterator __tmp = current; 
# 163
return *(--__tmp); 
# 164
} 
# 172
pointer operator->() const 
# 173
{ return &operator*(); } 
# 181
reverse_iterator &operator++() 
# 182
{ 
# 183
--(current); 
# 184
return *this; 
# 185
} 
# 193
reverse_iterator operator++(int) 
# 194
{ 
# 195
reverse_iterator __tmp = *this; 
# 196
--(current); 
# 197
return __tmp; 
# 198
} 
# 206
reverse_iterator &operator--() 
# 207
{ 
# 208
++(current); 
# 209
return *this; 
# 210
} 
# 218
reverse_iterator operator--(int) 
# 219
{ 
# 220
reverse_iterator __tmp = *this; 
# 221
++(current); 
# 222
return __tmp; 
# 223
} 
# 231
reverse_iterator operator+(difference_type __n) const 
# 232
{ return ((reverse_iterator)((current) - __n)); } 
# 241
reverse_iterator &operator+=(difference_type __n) 
# 242
{ 
# 243
(current) -= __n; 
# 244
return *this; 
# 245
} 
# 253
reverse_iterator operator-(difference_type __n) const 
# 254
{ return ((reverse_iterator)((current) + __n)); } 
# 263
reverse_iterator &operator-=(difference_type __n) 
# 264
{ 
# 265
(current) += __n; 
# 266
return *this; 
# 267
} 
# 275
reference operator[](difference_type __n) const 
# 276
{ return *((*this) + __n); } 
# 277
}; 
# 289
template< class _Iterator> inline bool 
# 291
operator==(const reverse_iterator< _Iterator>  &__x, const reverse_iterator< _Iterator>  &
# 292
__y) 
# 293
{ return (__x.base()) == (__y.base()); } 
# 295
template< class _Iterator> inline bool 
# 297
operator<(const reverse_iterator< _Iterator>  &__x, const reverse_iterator< _Iterator>  &
# 298
__y) 
# 299
{ return (__y.base()) < (__x.base()); } 
# 301
template< class _Iterator> inline bool 
# 303
operator!=(const reverse_iterator< _Iterator>  &__x, const reverse_iterator< _Iterator>  &
# 304
__y) 
# 305
{ return !(__x == __y); } 
# 307
template< class _Iterator> inline bool 
# 309
operator>(const reverse_iterator< _Iterator>  &__x, const reverse_iterator< _Iterator>  &
# 310
__y) 
# 311
{ return __y < __x; } 
# 313
template< class _Iterator> inline bool 
# 315
operator<=(const reverse_iterator< _Iterator>  &__x, const reverse_iterator< _Iterator>  &
# 316
__y) 
# 317
{ return !(__y < __x); } 
# 319
template< class _Iterator> inline bool 
# 321
operator>=(const reverse_iterator< _Iterator>  &__x, const reverse_iterator< _Iterator>  &
# 322
__y) 
# 323
{ return !(__x < __y); } 
# 325
template< class _Iterator> inline typename reverse_iterator< _Iterator> ::difference_type 
# 327
operator-(const reverse_iterator< _Iterator>  &__x, const reverse_iterator< _Iterator>  &
# 328
__y) 
# 329
{ return (__y.base()) - (__x.base()); } 
# 331
template< class _Iterator> inline reverse_iterator< _Iterator>  
# 333
operator+(typename reverse_iterator< _Iterator> ::difference_type __n, const reverse_iterator< _Iterator>  &
# 334
__x) 
# 335
{ return ((reverse_iterator< _Iterator> )((__x.base()) - __n)); } 
# 339
template< class _IteratorL, class _IteratorR> inline bool 
# 341
operator==(const reverse_iterator< _IteratorL>  &__x, const reverse_iterator< _IteratorR>  &
# 342
__y) 
# 343
{ return (__x.base()) == (__y.base()); } 
# 345
template< class _IteratorL, class _IteratorR> inline bool 
# 347
operator<(const reverse_iterator< _IteratorL>  &__x, const reverse_iterator< _IteratorR>  &
# 348
__y) 
# 349
{ return (__y.base()) < (__x.base()); } 
# 351
template< class _IteratorL, class _IteratorR> inline bool 
# 353
operator!=(const reverse_iterator< _IteratorL>  &__x, const reverse_iterator< _IteratorR>  &
# 354
__y) 
# 355
{ return !(__x == __y); } 
# 357
template< class _IteratorL, class _IteratorR> inline bool 
# 359
operator>(const reverse_iterator< _IteratorL>  &__x, const reverse_iterator< _IteratorR>  &
# 360
__y) 
# 361
{ return __y < __x; } 
# 363
template< class _IteratorL, class _IteratorR> inline bool 
# 365
operator<=(const reverse_iterator< _IteratorL>  &__x, const reverse_iterator< _IteratorR>  &
# 366
__y) 
# 367
{ return !(__y < __x); } 
# 369
template< class _IteratorL, class _IteratorR> inline bool 
# 371
operator>=(const reverse_iterator< _IteratorL>  &__x, const reverse_iterator< _IteratorR>  &
# 372
__y) 
# 373
{ return !(__x < __y); } 
# 375
template< class _IteratorL, class _IteratorR> inline typename reverse_iterator< _IteratorL> ::difference_type 
# 384
operator-(const reverse_iterator< _IteratorL>  &__x, const reverse_iterator< _IteratorR>  &
# 385
__y) 
# 387
{ return (__y.base()) - (__x.base()); } 
# 401
template< class _Container> 
# 402
class back_insert_iterator : public iterator< output_iterator_tag, void, void, void, void>  { 
# 406
protected: _Container *container; 
# 410
public: typedef _Container container_type; 
# 414
explicit back_insert_iterator(_Container &__x) : container((&__x)) { } 
# 429
back_insert_iterator &operator=(typename _Container::const_reference __value) 
# 430
{ 
# 431
((container)->push_back(__value)); 
# 432
return *this; 
# 433
} 
# 452
back_insert_iterator &operator*() 
# 453
{ return *this; } 
# 457
back_insert_iterator &operator++() 
# 458
{ return *this; } 
# 462
back_insert_iterator operator++(int) 
# 463
{ return *this; } 
# 464
}; 
# 477
template< class _Container> inline back_insert_iterator< _Container>  
# 479
back_inserter(_Container &__x) 
# 480
{ return ((back_insert_iterator< _Container> )(__x)); } 
# 492
template< class _Container> 
# 493
class front_insert_iterator : public iterator< output_iterator_tag, void, void, void, void>  { 
# 497
protected: _Container *container; 
# 501
public: typedef _Container container_type; 
# 504
explicit front_insert_iterator(_Container &__x) : container((&__x)) { } 
# 519
front_insert_iterator &operator=(typename _Container::const_reference __value) 
# 520
{ 
# 521
((container)->push_front(__value)); 
# 522
return *this; 
# 523
} 
# 542
front_insert_iterator &operator*() 
# 543
{ return *this; } 
# 547
front_insert_iterator &operator++() 
# 548
{ return *this; } 
# 552
front_insert_iterator operator++(int) 
# 553
{ return *this; } 
# 554
}; 
# 567
template< class _Container> inline front_insert_iterator< _Container>  
# 569
front_inserter(_Container &__x) 
# 570
{ return ((front_insert_iterator< _Container> )(__x)); } 
# 586
template< class _Container> 
# 587
class insert_iterator : public iterator< output_iterator_tag, void, void, void, void>  { 
# 591
protected: _Container *container; 
# 592
typename _Container::iterator iter; 
# 596
public: typedef _Container container_type; 
# 602
insert_iterator(_Container &__x, typename _Container::iterator __i) : container((&__x)), iter(__i) 
# 603
{ } 
# 630
insert_iterator &operator=(typename _Container::const_reference __value) 
# 631
{ 
# 632
(iter) = ((container)->insert(iter, __value)); 
# 633
++(iter); 
# 634
return *this; 
# 635
} 
# 656
insert_iterator &operator*() 
# 657
{ return *this; } 
# 661
insert_iterator &operator++() 
# 662
{ return *this; } 
# 666
insert_iterator &operator++(int) 
# 667
{ return *this; } 
# 668
}; 
# 681
template< class _Container, class _Iterator> inline insert_iterator< _Container>  
# 683
inserter(_Container &__x, _Iterator __i) 
# 684
{ 
# 685
return insert_iterator< _Container> (__x, (typename _Container::iterator)__i); 
# 687
} 
# 692
}
# 694
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 705
using std::iterator_traits;
# 706
using std::iterator;
# 707
template< class _Iterator, class _Container> 
# 708
class __normal_iterator { 
# 711
protected: _Iterator _M_current; 
# 713
typedef std::iterator_traits< _Iterator>  __traits_type; 
# 716
public: typedef _Iterator iterator_type; 
# 717
typedef typename std::iterator_traits< _Iterator> ::iterator_category iterator_category; 
# 718
typedef typename std::iterator_traits< _Iterator> ::value_type value_type; 
# 719
typedef typename std::iterator_traits< _Iterator> ::difference_type difference_type; 
# 720
typedef typename std::iterator_traits< _Iterator> ::reference reference; 
# 721
typedef typename std::iterator_traits< _Iterator> ::pointer pointer; 
# 723
__normal_iterator() : _M_current(_Iterator()) { } 
# 726
explicit __normal_iterator(const _Iterator &__i) : _M_current(__i) { } 
# 729
template< class _Iter> 
# 730
__normal_iterator(const __gnu_cxx::__normal_iterator< _Iter, typename __enable_if< std::__are_same< _Iter, typename _Container::pointer> ::__value, _Container> ::__type>  &
# 733
__i) : _M_current((__i.base())) 
# 734
{ } 
# 738
reference operator*() const 
# 739
{ return *(_M_current); } 
# 742
pointer operator->() const 
# 743
{ return _M_current; } 
# 746
__normal_iterator &operator++() 
# 747
{ 
# 748
++(_M_current); 
# 749
return *this; 
# 750
} 
# 753
__normal_iterator operator++(int) 
# 754
{ return ((__normal_iterator)((_M_current)++)); } 
# 758
__normal_iterator &operator--() 
# 759
{ 
# 760
--(_M_current); 
# 761
return *this; 
# 762
} 
# 765
__normal_iterator operator--(int) 
# 766
{ return ((__normal_iterator)((_M_current)--)); } 
# 770
reference operator[](const difference_type &__n) const 
# 771
{ return (_M_current)[__n]; } 
# 774
__normal_iterator &operator+=(const difference_type &__n) 
# 775
{ (_M_current) += __n; return *this; } 
# 778
__normal_iterator operator+(const difference_type &__n) const 
# 779
{ return ((__normal_iterator)((_M_current) + __n)); } 
# 782
__normal_iterator &operator-=(const difference_type &__n) 
# 783
{ (_M_current) -= __n; return *this; } 
# 786
__normal_iterator operator-(const difference_type &__n) const 
# 787
{ return ((__normal_iterator)((_M_current) - __n)); } 
# 790
const _Iterator &base() const 
# 791
{ return _M_current; } 
# 792
}; 
# 803
template< class _IteratorL, class _IteratorR, class _Container> inline bool 
# 805
operator==(const __normal_iterator< _IteratorL, _Container>  &__lhs, const __normal_iterator< _IteratorR, _Container>  &
# 806
__rhs) 
# 807
{ return (__lhs.base()) == (__rhs.base()); } 
# 809
template< class _Iterator, class _Container> inline bool 
# 811
operator==(const __normal_iterator< _Iterator, _Container>  &__lhs, const __normal_iterator< _Iterator, _Container>  &
# 812
__rhs) 
# 813
{ return (__lhs.base()) == (__rhs.base()); } 
# 815
template< class _IteratorL, class _IteratorR, class _Container> inline bool 
# 817
operator!=(const __normal_iterator< _IteratorL, _Container>  &__lhs, const __normal_iterator< _IteratorR, _Container>  &
# 818
__rhs) 
# 819
{ return (__lhs.base()) != (__rhs.base()); } 
# 821
template< class _Iterator, class _Container> inline bool 
# 823
operator!=(const __normal_iterator< _Iterator, _Container>  &__lhs, const __normal_iterator< _Iterator, _Container>  &
# 824
__rhs) 
# 825
{ return (__lhs.base()) != (__rhs.base()); } 
# 828
template< class _IteratorL, class _IteratorR, class _Container> inline bool 
# 830
operator<(const __normal_iterator< _IteratorL, _Container>  &__lhs, const __normal_iterator< _IteratorR, _Container>  &
# 831
__rhs) 
# 832
{ return (__lhs.base()) < (__rhs.base()); } 
# 834
template< class _Iterator, class _Container> inline bool 
# 836
operator<(const __normal_iterator< _Iterator, _Container>  &__lhs, const __normal_iterator< _Iterator, _Container>  &
# 837
__rhs) 
# 838
{ return (__lhs.base()) < (__rhs.base()); } 
# 840
template< class _IteratorL, class _IteratorR, class _Container> inline bool 
# 842
operator>(const __normal_iterator< _IteratorL, _Container>  &__lhs, const __normal_iterator< _IteratorR, _Container>  &
# 843
__rhs) 
# 844
{ return (__lhs.base()) > (__rhs.base()); } 
# 846
template< class _Iterator, class _Container> inline bool 
# 848
operator>(const __normal_iterator< _Iterator, _Container>  &__lhs, const __normal_iterator< _Iterator, _Container>  &
# 849
__rhs) 
# 850
{ return (__lhs.base()) > (__rhs.base()); } 
# 852
template< class _IteratorL, class _IteratorR, class _Container> inline bool 
# 854
operator<=(const __normal_iterator< _IteratorL, _Container>  &__lhs, const __normal_iterator< _IteratorR, _Container>  &
# 855
__rhs) 
# 856
{ return (__lhs.base()) <= (__rhs.base()); } 
# 858
template< class _Iterator, class _Container> inline bool 
# 860
operator<=(const __normal_iterator< _Iterator, _Container>  &__lhs, const __normal_iterator< _Iterator, _Container>  &
# 861
__rhs) 
# 862
{ return (__lhs.base()) <= (__rhs.base()); } 
# 864
template< class _IteratorL, class _IteratorR, class _Container> inline bool 
# 866
operator>=(const __normal_iterator< _IteratorL, _Container>  &__lhs, const __normal_iterator< _IteratorR, _Container>  &
# 867
__rhs) 
# 868
{ return (__lhs.base()) >= (__rhs.base()); } 
# 870
template< class _Iterator, class _Container> inline bool 
# 872
operator>=(const __normal_iterator< _Iterator, _Container>  &__lhs, const __normal_iterator< _Iterator, _Container>  &
# 873
__rhs) 
# 874
{ return (__lhs.base()) >= (__rhs.base()); } 
# 880
template< class _IteratorL, class _IteratorR, class _Container> inline typename __normal_iterator< _IteratorL, _Container> ::difference_type 
# 889
operator-(const __normal_iterator< _IteratorL, _Container>  &__lhs, const __normal_iterator< _IteratorR, _Container>  &
# 890
__rhs) 
# 892
{ return (__lhs.base()) - (__rhs.base()); } 
# 894
template< class _Iterator, class _Container> inline typename __normal_iterator< _Iterator, _Container> ::difference_type 
# 896
operator-(const __normal_iterator< _Iterator, _Container>  &__lhs, const __normal_iterator< _Iterator, _Container>  &
# 897
__rhs) 
# 898
{ return (__lhs.base()) - (__rhs.base()); } 
# 900
template< class _Iterator, class _Container> inline __normal_iterator< _Iterator, _Container>  
# 902
operator+(typename __normal_iterator< _Iterator, _Container> ::difference_type 
# 903
__n, const __normal_iterator< _Iterator, _Container>  &__i) 
# 904
{ return ((__normal_iterator< _Iterator, _Container> )((__i.base()) + __n)); } 
# 907
}
# 72 "/usr/include/c++/4.8.2/bits/stl_algobase.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 80
template< bool _BoolType> 
# 81
struct __iter_swap { 
# 83
template< class _ForwardIterator1, class _ForwardIterator2> static void 
# 85
iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b) 
# 86
{ 
# 88
typedef typename iterator_traits< _ForwardIterator1> ::value_type _ValueType1; 
# 89
_ValueType1 __tmp = *__a; 
# 90
(*__a) = (*__b); 
# 91
(*__b) = __tmp; 
# 92
} 
# 93
}; 
# 96
template<> struct __iter_swap< true>  { 
# 98
template< class _ForwardIterator1, class _ForwardIterator2> static void 
# 100
iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b) 
# 101
{ 
# 102
swap(*__a, *__b); 
# 103
} 
# 104
}; 
# 117
template< class _ForwardIterator1, class _ForwardIterator2> inline void 
# 119
iter_swap(_ForwardIterator1 __a, _ForwardIterator2 __b) 
# 120
{ 
# 129
typedef typename iterator_traits< _ForwardIterator1> ::value_type _ValueType1; 
# 131
typedef typename iterator_traits< _ForwardIterator2> ::value_type _ValueType2; 
# 139
typedef typename iterator_traits< _ForwardIterator1> ::reference _ReferenceType1; 
# 141
typedef typename iterator_traits< _ForwardIterator2> ::reference _ReferenceType2; 
# 142
std::__iter_swap< __are_same< typename iterator_traits< _ForwardIterator1> ::value_type, typename iterator_traits< _ForwardIterator2> ::value_type> ::__value && __are_same< typename iterator_traits< _ForwardIterator1> ::value_type &, typename iterator_traits< _ForwardIterator1> ::reference> ::__value && __are_same< typename iterator_traits< _ForwardIterator2> ::value_type &, typename iterator_traits< _ForwardIterator2> ::reference> ::__value> ::iter_swap(__a, __b); 
# 149
} 
# 163
template< class _ForwardIterator1, class _ForwardIterator2> _ForwardIterator2 
# 165
swap_ranges(_ForwardIterator1 __first1, _ForwardIterator1 __last1, _ForwardIterator2 
# 166
__first2) 
# 167
{ 
# 173
; 
# 175
for (; __first1 != __last1; (++__first1), (++__first2)) { 
# 176
std::iter_swap(__first1, __first2); }  
# 177
return __first2; 
# 178
} 
# 191
template< class _Tp> inline const _Tp &
# 193
min(const _Tp &__a, const _Tp &__b) 
# 194
{ 
# 198
if (__b < __a) { 
# 199
return __b; }  
# 200
return __a; 
# 201
} 
# 214
template< class _Tp> inline const _Tp &
# 216
max(const _Tp &__a, const _Tp &__b) 
# 217
{ 
# 221
if (__a < __b) { 
# 222
return __b; }  
# 223
return __a; 
# 224
} 
# 237
template< class _Tp, class _Compare> inline const _Tp &
# 239
min(const _Tp &__a, const _Tp &__b, _Compare __comp) 
# 240
{ 
# 242
if (__comp(__b, __a)) { 
# 243
return __b; }  
# 244
return __a; 
# 245
} 
# 258
template< class _Tp, class _Compare> inline const _Tp &
# 260
max(const _Tp &__a, const _Tp &__b, _Compare __comp) 
# 261
{ 
# 263
if (__comp(__a, __b)) { 
# 264
return __b; }  
# 265
return __a; 
# 266
} 
# 270
template< class _Iterator> 
# 271
struct _Niter_base : public _Iter_base< _Iterator, __is_normal_iterator< _Iterator> ::__value>  { 
# 273
}; 
# 275
template< class _Iterator> inline typename _Niter_base< _Iterator> ::iterator_type 
# 277
__niter_base(_Iterator __it) 
# 278
{ return std::_Niter_base< _Iterator> ::_S_base(__it); } 
# 281
template< class _Iterator> 
# 282
struct _Miter_base : public _Iter_base< _Iterator, __is_move_iterator< _Iterator> ::__value>  { 
# 284
}; 
# 286
template< class _Iterator> inline typename _Miter_base< _Iterator> ::iterator_type 
# 288
__miter_base(_Iterator __it) 
# 289
{ return std::_Miter_base< _Iterator> ::_S_base(__it); } 
# 297
template< bool , bool , class > 
# 298
struct __copy_move { 
# 300
template< class _II, class _OI> static _OI 
# 302
__copy_m(_II __first, _II __last, _OI __result) 
# 303
{ 
# 304
for (; __first != __last; (++__result), (++__first)) { 
# 305
(*__result) = (*__first); }  
# 306
return __result; 
# 307
} 
# 308
}; 
# 326
template<> struct __copy_move< false, false, random_access_iterator_tag>  { 
# 328
template< class _II, class _OI> static _OI 
# 330
__copy_m(_II __first, _II __last, _OI __result) 
# 331
{ 
# 332
typedef typename iterator_traits< _II> ::difference_type _Distance; 
# 333
for (_Distance __n = __last - __first; __n > 0; --__n) 
# 334
{ 
# 335
(*__result) = (*__first); 
# 336
++__first; 
# 337
++__result; 
# 338
}  
# 339
return __result; 
# 340
} 
# 341
}; 
# 363
template< bool _IsMove> 
# 364
struct __copy_move< _IsMove, true, random_access_iterator_tag>  { 
# 366
template< class _Tp> static _Tp *
# 368
__copy_m(const _Tp *__first, const _Tp *__last, _Tp *__result) 
# 369
{ 
# 370
const ptrdiff_t _Num = __last - __first; 
# 371
if (_Num) { 
# 372
__builtin_memmove(__result, __first, sizeof(_Tp) * _Num); }  
# 373
return __result + _Num; 
# 374
} 
# 375
}; 
# 377
template< bool _IsMove, class _II, class _OI> inline _OI 
# 379
__copy_move_a(_II __first, _II __last, _OI __result) 
# 380
{ 
# 381
typedef typename iterator_traits< _II> ::value_type _ValueTypeI; 
# 382
typedef typename iterator_traits< _OI> ::value_type _ValueTypeO; 
# 383
typedef typename iterator_traits< _II> ::iterator_category _Category; 
# 384
const bool __simple = (__is_trivial(_ValueTypeI) && __is_pointer< _II> ::__value && __is_pointer< _OI> ::__value && __are_same< typename iterator_traits< _II> ::value_type, typename iterator_traits< _OI> ::value_type> ::__value); 
# 389
return std::__copy_move< _IsMove, __simple, typename iterator_traits< _II> ::iterator_category> ::__copy_m(__first, __last, __result); 
# 391
} 
# 395
template< class _CharT> struct char_traits; 
# 398
template< class _CharT, class _Traits> class istreambuf_iterator; 
# 401
template< class _CharT, class _Traits> class ostreambuf_iterator; 
# 404
template< bool _IsMove, class _CharT> typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, ostreambuf_iterator< _CharT, char_traits< _CharT> > > ::__type __copy_move_a2(_CharT *, _CharT *, ostreambuf_iterator< _CharT, char_traits< _CharT> > ); 
# 410
template< bool _IsMove, class _CharT> typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, ostreambuf_iterator< _CharT, char_traits< _CharT> > > ::__type __copy_move_a2(const _CharT *, const _CharT *, ostreambuf_iterator< _CharT, char_traits< _CharT> > ); 
# 416
template< bool _IsMove, class _CharT> typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, _CharT *> ::__type __copy_move_a2(istreambuf_iterator< _CharT, char_traits< _CharT> > , istreambuf_iterator< _CharT, char_traits< _CharT> > , _CharT *); 
# 422
template< bool _IsMove, class _II, class _OI> inline _OI 
# 424
__copy_move_a2(_II __first, _II __last, _OI __result) 
# 425
{ 
# 426
return (_OI)std::__copy_move_a< _IsMove> (std::__niter_base(__first), std::__niter_base(__last), std::__niter_base(__result)); 
# 429
} 
# 448
template< class _II, class _OI> inline _OI 
# 450
copy(_II __first, _II __last, _OI __result) 
# 451
{ 
# 456
; 
# 458
return std::__copy_move_a2< __is_move_iterator< _II> ::__value> (std::__miter_base(__first), std::__miter_base(__last), __result); 
# 461
} 
# 500
template< bool , bool , class > 
# 501
struct __copy_move_backward { 
# 503
template< class _BI1, class _BI2> static _BI2 
# 505
__copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result) 
# 506
{ 
# 507
while (__first != __last) { 
# 508
(*(--__result)) = (*(--__last)); }  
# 509
return __result; 
# 510
} 
# 511
}; 
# 529
template<> struct __copy_move_backward< false, false, random_access_iterator_tag>  { 
# 531
template< class _BI1, class _BI2> static _BI2 
# 533
__copy_move_b(_BI1 __first, _BI1 __last, _BI2 __result) 
# 534
{ 
# 535
typename iterator_traits< _BI1> ::difference_type __n; 
# 536
for (__n = (__last - __first); __n > 0; --__n) { 
# 537
(*(--__result)) = (*(--__last)); }  
# 538
return __result; 
# 539
} 
# 540
}; 
# 558
template< bool _IsMove> 
# 559
struct __copy_move_backward< _IsMove, true, random_access_iterator_tag>  { 
# 561
template< class _Tp> static _Tp *
# 563
__copy_move_b(const _Tp *__first, const _Tp *__last, _Tp *__result) 
# 564
{ 
# 565
const ptrdiff_t _Num = __last - __first; 
# 566
if (_Num) { 
# 567
__builtin_memmove(__result - _Num, __first, sizeof(_Tp) * _Num); }  
# 568
return __result - _Num; 
# 569
} 
# 570
}; 
# 572
template< bool _IsMove, class _BI1, class _BI2> inline _BI2 
# 574
__copy_move_backward_a(_BI1 __first, _BI1 __last, _BI2 __result) 
# 575
{ 
# 576
typedef typename iterator_traits< _BI1> ::value_type _ValueType1; 
# 577
typedef typename iterator_traits< _BI2> ::value_type _ValueType2; 
# 578
typedef typename iterator_traits< _BI1> ::iterator_category _Category; 
# 579
const bool __simple = (__is_trivial(_ValueType1) && __is_pointer< _BI1> ::__value && __is_pointer< _BI2> ::__value && __are_same< typename iterator_traits< _BI1> ::value_type, typename iterator_traits< _BI2> ::value_type> ::__value); 
# 584
return std::__copy_move_backward< _IsMove, __simple, typename iterator_traits< _BI1> ::iterator_category> ::__copy_move_b(__first, __last, __result); 
# 588
} 
# 590
template< bool _IsMove, class _BI1, class _BI2> inline _BI2 
# 592
__copy_move_backward_a2(_BI1 __first, _BI1 __last, _BI2 __result) 
# 593
{ 
# 594
return (_BI2)std::__copy_move_backward_a< _IsMove> (std::__niter_base(__first), std::__niter_base(__last), std::__niter_base(__result)); 
# 597
} 
# 617
template< class _BI1, class _BI2> inline _BI2 
# 619
copy_backward(_BI1 __first, _BI1 __last, _BI2 __result) 
# 620
{ 
# 627
; 
# 629
return std::__copy_move_backward_a2< __is_move_iterator< _BI1> ::__value> (std::__miter_base(__first), std::__miter_base(__last), __result); 
# 632
} 
# 675
template< class _ForwardIterator, class _Tp> inline typename __gnu_cxx::__enable_if< !__is_scalar< _Tp> ::__value, void> ::__type 
# 678
__fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &
# 679
__value) 
# 680
{ 
# 681
for (; __first != __last; ++__first) { 
# 682
(*__first) = __value; }  
# 683
} 
# 685
template< class _ForwardIterator, class _Tp> inline typename __gnu_cxx::__enable_if< __is_scalar< _Tp> ::__value, void> ::__type 
# 688
__fill_a(_ForwardIterator __first, _ForwardIterator __last, const _Tp &
# 689
__value) 
# 690
{ 
# 691
const _Tp __tmp = __value; 
# 692
for (; __first != __last; ++__first) { 
# 693
(*__first) = __tmp; }  
# 694
} 
# 697
template< class _Tp> inline typename __gnu_cxx::__enable_if< __is_byte< _Tp> ::__value, void> ::__type 
# 700
__fill_a(_Tp *__first, _Tp *__last, const _Tp &__c) 
# 701
{ 
# 702
const _Tp __tmp = __c; 
# 703
__builtin_memset(__first, static_cast< unsigned char>(__tmp), __last - __first); 
# 705
} 
# 719
template< class _ForwardIterator, class _Tp> inline void 
# 721
fill(_ForwardIterator __first, _ForwardIterator __last, const _Tp &__value) 
# 722
{ 
# 726
; 
# 728
std::__fill_a(std::__niter_base(__first), std::__niter_base(__last), __value); 
# 730
} 
# 732
template< class _OutputIterator, class _Size, class _Tp> inline typename __gnu_cxx::__enable_if< !__is_scalar< _Tp> ::__value, _OutputIterator> ::__type 
# 735
__fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value) 
# 736
{ 
# 737
for (__decltype((__n + 0)) __niter = __n; __niter > 0; (--__niter), (++__first)) { 
# 739
(*__first) = __value; }  
# 740
return __first; 
# 741
} 
# 743
template< class _OutputIterator, class _Size, class _Tp> inline typename __gnu_cxx::__enable_if< __is_scalar< _Tp> ::__value, _OutputIterator> ::__type 
# 746
__fill_n_a(_OutputIterator __first, _Size __n, const _Tp &__value) 
# 747
{ 
# 748
const _Tp __tmp = __value; 
# 749
for (__decltype((__n + 0)) __niter = __n; __niter > 0; (--__niter), (++__first)) { 
# 751
(*__first) = __tmp; }  
# 752
return __first; 
# 753
} 
# 755
template< class _Size, class _Tp> inline typename __gnu_cxx::__enable_if< __is_byte< _Tp> ::__value, _Tp *> ::__type 
# 758
__fill_n_a(_Tp *__first, _Size __n, const _Tp &__c) 
# 759
{ 
# 760
std::__fill_a(__first, __first + __n, __c); 
# 761
return __first + __n; 
# 762
} 
# 779
template< class _OI, class _Size, class _Tp> inline _OI 
# 781
fill_n(_OI __first, _Size __n, const _Tp &__value) 
# 782
{ 
# 786
return (_OI)std::__fill_n_a(std::__niter_base(__first), __n, __value); 
# 787
} 
# 789
template< bool _BoolType> 
# 790
struct __equal { 
# 792
template< class _II1, class _II2> static bool 
# 794
equal(_II1 __first1, _II1 __last1, _II2 __first2) 
# 795
{ 
# 796
for (; __first1 != __last1; (++__first1), (++__first2)) { 
# 797
if (!((*__first1) == (*__first2))) { 
# 798
return false; }  }  
# 799
return true; 
# 800
} 
# 801
}; 
# 804
template<> struct __equal< true>  { 
# 806
template< class _Tp> static bool 
# 808
equal(const _Tp *__first1, const _Tp *__last1, const _Tp *__first2) 
# 809
{ 
# 810
return !(__builtin_memcmp(__first1, __first2, sizeof(_Tp) * (__last1 - __first1))); 
# 812
} 
# 813
}; 
# 815
template< class _II1, class _II2> inline bool 
# 817
__equal_aux(_II1 __first1, _II1 __last1, _II2 __first2) 
# 818
{ 
# 819
typedef typename iterator_traits< _II1> ::value_type _ValueType1; 
# 820
typedef typename iterator_traits< _II2> ::value_type _ValueType2; 
# 821
const bool __simple = ((__is_integer< typename iterator_traits< _II1> ::value_type> ::__value || __is_pointer< typename iterator_traits< _II1> ::value_type> ::__value) && __is_pointer< _II1> ::__value && __is_pointer< _II2> ::__value && __are_same< typename iterator_traits< _II1> ::value_type, typename iterator_traits< _II2> ::value_type> ::__value); 
# 827
return std::__equal< __simple> ::equal(__first1, __last1, __first2); 
# 828
} 
# 831
template< class , class > 
# 832
struct __lc_rai { 
# 834
template< class _II1, class _II2> static _II1 
# 836
__newlast1(_II1, _II1 __last1, _II2, _II2) 
# 837
{ return __last1; } 
# 839
template< class _II> static bool 
# 841
__cnd2(_II __first, _II __last) 
# 842
{ return __first != __last; } 
# 843
}; 
# 846
template<> struct __lc_rai< random_access_iterator_tag, random_access_iterator_tag>  { 
# 848
template< class _RAI1, class _RAI2> static _RAI1 
# 850
__newlast1(_RAI1 __first1, _RAI1 __last1, _RAI2 
# 851
__first2, _RAI2 __last2) 
# 852
{ 
# 854
const typename iterator_traits< _RAI1> ::difference_type __diff1 = __last1 - __first1; 
# 856
const typename iterator_traits< _RAI2> ::difference_type __diff2 = __last2 - __first2; 
# 857
return (__diff2 < __diff1) ? __first1 + __diff2 : __last1; 
# 858
} 
# 860
template< class _RAI> static bool 
# 862
__cnd2(_RAI, _RAI) 
# 863
{ return true; } 
# 864
}; 
# 866
template< bool _BoolType> 
# 867
struct __lexicographical_compare { 
# 869
template< class _II1, class _II2> static bool __lc(_II1, _II1, _II2, _II2); 
# 871
}; 
# 873
template< bool _BoolType> 
# 874
template< class _II1, class _II2> bool 
# 877
__lexicographical_compare< _BoolType> ::__lc(_II1 __first1, _II1 __last1, _II2 __first2, _II2 __last2) 
# 878
{ 
# 879
typedef typename iterator_traits< _II1> ::iterator_category _Category1; 
# 880
typedef typename iterator_traits< _II2> ::iterator_category _Category2; 
# 881
typedef __lc_rai< typename iterator_traits< _II1> ::iterator_category, typename iterator_traits< _II2> ::iterator_category>  __rai_type; 
# 883
__last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2); 
# 885
for (; (__first1 != __last1) && __rai_type::__cnd2(__first2, __last2); (++__first1), (++__first2)) 
# 887
{ 
# 888
if ((*__first1) < (*__first2)) { 
# 889
return true; }  
# 890
if ((*__first2) < (*__first1)) { 
# 891
return false; }  
# 892
}  
# 893
return (__first1 == __last1) && (__first2 != __last2); 
# 894
} 
# 897
template<> struct __lexicographical_compare< true>  { 
# 899
template< class _Tp, class _Up> static bool 
# 901
__lc(const _Tp *__first1, const _Tp *__last1, const _Up *
# 902
__first2, const _Up *__last2) 
# 903
{ 
# 904
const size_t __len1 = __last1 - __first1; 
# 905
const size_t __len2 = __last2 - __first2; 
# 906
const int __result = __builtin_memcmp(__first1, __first2, std::min(__len1, __len2)); 
# 908
return (__result != 0) ? __result < 0 : (__len1 < __len2); 
# 909
} 
# 910
}; 
# 912
template< class _II1, class _II2> inline bool 
# 914
__lexicographical_compare_aux(_II1 __first1, _II1 __last1, _II2 
# 915
__first2, _II2 __last2) 
# 916
{ 
# 917
typedef typename iterator_traits< _II1> ::value_type _ValueType1; 
# 918
typedef typename iterator_traits< _II2> ::value_type _ValueType2; 
# 919
const bool __simple = (__is_byte< typename iterator_traits< _II1> ::value_type> ::__value && __is_byte< typename iterator_traits< _II2> ::value_type> ::__value && (!__gnu_cxx::__numeric_traits< typename iterator_traits< _II1> ::value_type> ::__is_signed) && (!__gnu_cxx::__numeric_traits< typename iterator_traits< _II2> ::value_type> ::__is_signed) && __is_pointer< _II1> ::__value && __is_pointer< _II2> ::__value); 
# 926
return std::__lexicographical_compare< __simple> ::__lc(__first1, __last1, __first2, __last2); 
# 928
} 
# 941
template< class _ForwardIterator, class _Tp> _ForwardIterator 
# 943
lower_bound(_ForwardIterator __first, _ForwardIterator __last, const _Tp &
# 944
__val) 
# 945
{ 
# 951
typedef typename iterator_traits< _ForwardIterator> ::difference_type _DistanceType; 
# 956
; 
# 958
_DistanceType __len = std::distance(__first, __last); 
# 960
while (__len > 0) 
# 961
{ 
# 962
_DistanceType __half = __len >> 1; 
# 963
_ForwardIterator __middle = __first; 
# 964
std::advance(__middle, __half); 
# 965
if ((*__middle) < __val) 
# 966
{ 
# 967
__first = __middle; 
# 968
++__first; 
# 969
__len = ((__len - __half) - 1); 
# 970
} else { 
# 972
__len = __half; }  
# 973
}  
# 974
return __first; 
# 975
} 
# 980
inline int __lg(int __n) 
# 981
{ return ((sizeof(int) * (8)) - (1)) - (__builtin_clz(__n)); } 
# 984
inline unsigned __lg(unsigned __n) 
# 985
{ return ((sizeof(int) * (8)) - (1)) - (__builtin_clz(__n)); } 
# 988
inline long __lg(long __n) 
# 989
{ return ((sizeof(long) * (8)) - (1)) - (__builtin_clzl(__n)); } 
# 992
inline unsigned long __lg(unsigned long __n) 
# 993
{ return ((sizeof(long) * (8)) - (1)) - (__builtin_clzl(__n)); } 
# 996
inline long long __lg(long long __n) 
# 997
{ return ((sizeof(long long) * (8)) - (1)) - (__builtin_clzll(__n)); } 
# 1000
inline unsigned long long __lg(unsigned long long __n) 
# 1001
{ return ((sizeof(long long) * (8)) - (1)) - (__builtin_clzll(__n)); } 
# 1019
template< class _II1, class _II2> inline bool 
# 1021
equal(_II1 __first1, _II1 __last1, _II2 __first2) 
# 1022
{ 
# 1029
; 
# 1031
return std::__equal_aux(std::__niter_base(__first1), std::__niter_base(__last1), std::__niter_base(__first2)); 
# 1034
} 
# 1051
template< class _IIter1, class _IIter2, class _BinaryPredicate> inline bool 
# 1053
equal(_IIter1 __first1, _IIter1 __last1, _IIter2 
# 1054
__first2, _BinaryPredicate __binary_pred) 
# 1055
{ 
# 1059
; 
# 1061
for (; __first1 != __last1; (++__first1), (++__first2)) { 
# 1062
if (!((bool)__binary_pred(*__first1, *__first2))) { 
# 1063
return false; }  }  
# 1064
return true; 
# 1065
} 
# 1082
template< class _II1, class _II2> inline bool 
# 1084
lexicographical_compare(_II1 __first1, _II1 __last1, _II2 
# 1085
__first2, _II2 __last2) 
# 1086
{ 
# 1096
; 
# 1097
; 
# 1099
return std::__lexicographical_compare_aux(std::__niter_base(__first1), std::__niter_base(__last1), std::__niter_base(__first2), std::__niter_base(__last2)); 
# 1103
} 
# 1118
template< class _II1, class _II2, class _Compare> bool 
# 1120
lexicographical_compare(_II1 __first1, _II1 __last1, _II2 
# 1121
__first2, _II2 __last2, _Compare __comp) 
# 1122
{ 
# 1123
typedef typename iterator_traits< _II1> ::iterator_category _Category1; 
# 1124
typedef typename iterator_traits< _II2> ::iterator_category _Category2; 
# 1125
typedef __lc_rai< typename iterator_traits< _II1> ::iterator_category, typename iterator_traits< _II2> ::iterator_category>  __rai_type; 
# 1130
; 
# 1131
; 
# 1133
__last1 = __rai_type::__newlast1(__first1, __last1, __first2, __last2); 
# 1134
for (; (__first1 != __last1) && __rai_type::__cnd2(__first2, __last2); (++__first1), (++__first2)) 
# 1136
{ 
# 1137
if (__comp(*__first1, *__first2)) { 
# 1138
return true; }  
# 1139
if (__comp(*__first2, *__first1)) { 
# 1140
return false; }  
# 1141
}  
# 1142
return (__first1 == __last1) && (__first2 != __last2); 
# 1143
} 
# 1158
template< class _InputIterator1, class _InputIterator2> pair< _InputIterator1, _InputIterator2>  
# 1160
mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 
# 1161
__first2) 
# 1162
{ 
# 1169
; 
# 1171
while ((__first1 != __last1) && ((*__first1) == (*__first2))) 
# 1172
{ 
# 1173
++__first1; 
# 1174
++__first2; 
# 1175
}  
# 1176
return pair< _InputIterator1, _InputIterator2> (__first1, __first2); 
# 1177
} 
# 1195
template< class _InputIterator1, class _InputIterator2, class 
# 1196
_BinaryPredicate> pair< _InputIterator1, _InputIterator2>  
# 1198
mismatch(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 
# 1199
__first2, _BinaryPredicate __binary_pred) 
# 1200
{ 
# 1204
; 
# 1206
while ((__first1 != __last1) && ((bool)__binary_pred(*__first1, *__first2))) 
# 1207
{ 
# 1208
++__first1; 
# 1209
++__first2; 
# 1210
}  
# 1211
return pair< _InputIterator1, _InputIterator2> (__first1, __first2); 
# 1212
} 
# 1215
}
# 43 "/usr/include/c++/4.8.2/bits/char_traits.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 57
template< class _CharT> 
# 58
struct _Char_types { 
# 60
typedef unsigned long int_type; 
# 61
typedef std::streampos pos_type; 
# 62
typedef std::streamoff off_type; 
# 63
typedef mbstate_t state_type; 
# 64
}; 
# 82
template< class _CharT> 
# 83
struct char_traits { 
# 85
typedef _CharT char_type; 
# 86
typedef typename _Char_types< _CharT> ::int_type int_type; 
# 87
typedef typename _Char_types< _CharT> ::pos_type pos_type; 
# 88
typedef typename _Char_types< _CharT> ::off_type off_type; 
# 89
typedef typename _Char_types< _CharT> ::state_type state_type; 
# 92
static void assign(char_type &__c1, const char_type &__c2) 
# 93
{ __c1 = __c2; } 
# 96
static bool eq(const char_type &__c1, const char_type &__c2) 
# 97
{ return __c1 == __c2; } 
# 100
static bool lt(const char_type &__c1, const char_type &__c2) 
# 101
{ return __c1 < __c2; } 
# 104
static int compare(const char_type * __s1, const char_type * __s2, std::size_t __n); 
# 107
static std::size_t length(const char_type * __s); 
# 110
static const char_type *find(const char_type * __s, std::size_t __n, const char_type & __a); 
# 113
static char_type *move(char_type * __s1, const char_type * __s2, std::size_t __n); 
# 116
static char_type *copy(char_type * __s1, const char_type * __s2, std::size_t __n); 
# 119
static char_type *assign(char_type * __s, std::size_t __n, char_type __a); 
# 122
static char_type to_char_type(const int_type &__c) 
# 123
{ return static_cast< char_type>(__c); } 
# 126
static int_type to_int_type(const char_type &__c) 
# 127
{ return static_cast< int_type>(__c); } 
# 130
static bool eq_int_type(const int_type &__c1, const int_type &__c2) 
# 131
{ return __c1 == __c2; } 
# 134
static int_type eof() 
# 135
{ return static_cast< int_type>(-1); } 
# 138
static int_type not_eof(const int_type &__c) 
# 139
{ return (!(eq_int_type)(__c, (eof)())) ? __c : (to_int_type)(char_type()); } 
# 140
}; 
# 142
template< class _CharT> int 
# 145
char_traits< _CharT> ::compare(const char_type *__s1, const char_type *__s2, std::size_t __n) 
# 146
{ 
# 147
for (std::size_t __i = (0); __i < __n; ++__i) { 
# 148
if ((lt)(__s1[__i], __s2[__i])) { 
# 149
return -1; } else { 
# 150
if ((lt)(__s2[__i], __s1[__i])) { 
# 151
return 1; }  }  }  
# 152
return 0; 
# 153
} 
# 155
template< class _CharT> std::size_t 
# 158
char_traits< _CharT> ::length(const char_type *__p) 
# 159
{ 
# 160
std::size_t __i = (0); 
# 161
while (!(eq)(__p[__i], char_type())) { 
# 162
++__i; }  
# 163
return __i; 
# 164
} 
# 166
template< class _CharT> const typename char_traits< _CharT> ::char_type *
# 169
char_traits< _CharT> ::find(const char_type *__s, std::size_t __n, const char_type &__a) 
# 170
{ 
# 171
for (std::size_t __i = (0); __i < __n; ++__i) { 
# 172
if ((eq)(__s[__i], __a)) { 
# 173
return __s + __i; }  }  
# 174
return 0; 
# 175
} 
# 177
template< class _CharT> typename char_traits< _CharT> ::char_type *
# 180
char_traits< _CharT> ::move(char_type *__s1, const char_type *__s2, std::size_t __n) 
# 181
{ 
# 182
return static_cast< _CharT *>(__builtin_memmove(__s1, __s2, __n * sizeof(char_type))); 
# 184
} 
# 186
template< class _CharT> typename char_traits< _CharT> ::char_type *
# 189
char_traits< _CharT> ::copy(char_type *__s1, const char_type *__s2, std::size_t __n) 
# 190
{ 
# 192
std::copy(__s2, __s2 + __n, __s1); 
# 193
return __s1; 
# 194
} 
# 196
template< class _CharT> typename char_traits< _CharT> ::char_type *
# 199
char_traits< _CharT> ::assign(char_type *__s, std::size_t __n, char_type __a) 
# 200
{ 
# 202
std::fill_n(__s, __n, __a); 
# 203
return __s; 
# 204
} 
# 207
}
# 209
namespace std __attribute((__visibility__("default"))) { 
# 226
template< class _CharT> 
# 227
struct char_traits : public __gnu_cxx::char_traits< _CharT>  { 
# 228
}; 
# 233
template<> struct char_traits< char>  { 
# 235
typedef char char_type; 
# 236
typedef int int_type; 
# 237
typedef streampos pos_type; 
# 238
typedef streamoff off_type; 
# 239
typedef mbstate_t state_type; 
# 242
static void assign(char_type &__c1, const char_type &__c2) 
# 243
{ __c1 = __c2; } 
# 246
static bool eq(const char_type &__c1, const char_type &__c2) 
# 247
{ return __c1 == __c2; } 
# 250
static bool lt(const char_type &__c1, const char_type &__c2) 
# 251
{ return __c1 < __c2; } 
# 254
static int compare(const char_type *__s1, const char_type *__s2, size_t __n) 
# 255
{ return __builtin_memcmp(__s1, __s2, __n); } 
# 258
static size_t length(const char_type *__s) 
# 259
{ return __builtin_strlen(__s); } 
# 262
static const char_type *find(const char_type *__s, size_t __n, const char_type &__a) 
# 263
{ return static_cast< const char_type *>(__builtin_memchr(__s, __a, __n)); } 
# 266
static char_type *move(char_type *__s1, const char_type *__s2, size_t __n) 
# 267
{ return static_cast< char_type *>(__builtin_memmove(__s1, __s2, __n)); } 
# 270
static char_type *copy(char_type *__s1, const char_type *__s2, size_t __n) 
# 271
{ return static_cast< char_type *>(__builtin_memcpy(__s1, __s2, __n)); } 
# 274
static char_type *assign(char_type *__s, size_t __n, char_type __a) 
# 275
{ return static_cast< char_type *>(__builtin_memset(__s, __a, __n)); } 
# 278
static char_type to_char_type(const int_type &__c) 
# 279
{ return static_cast< char_type>(__c); } 
# 284
static int_type to_int_type(const char_type &__c) 
# 285
{ return static_cast< int_type>(static_cast< unsigned char>(__c)); } 
# 288
static bool eq_int_type(const int_type &__c1, const int_type &__c2) 
# 289
{ return __c1 == __c2; } 
# 292
static int_type eof() 
# 293
{ return static_cast< int_type>(-1); } 
# 296
static int_type not_eof(const int_type &__c) 
# 297
{ return (__c == eof()) ? 0 : __c; } 
# 298
}; 
# 304
template<> struct char_traits< wchar_t>  { 
# 306
typedef wchar_t char_type; 
# 307
typedef wint_t int_type; 
# 308
typedef streamoff off_type; 
# 309
typedef wstreampos pos_type; 
# 310
typedef mbstate_t state_type; 
# 313
static void assign(char_type &__c1, const char_type &__c2) 
# 314
{ __c1 = __c2; } 
# 317
static bool eq(const char_type &__c1, const char_type &__c2) 
# 318
{ return __c1 == __c2; } 
# 321
static bool lt(const char_type &__c1, const char_type &__c2) 
# 322
{ return __c1 < __c2; } 
# 325
static int compare(const char_type *__s1, const char_type *__s2, size_t __n) 
# 326
{ return wmemcmp(__s1, __s2, __n); } 
# 329
static size_t length(const char_type *__s) 
# 330
{ return wcslen(__s); } 
# 333
static const char_type *find(const char_type *__s, size_t __n, const char_type &__a) 
# 334
{ return wmemchr(__s, __a, __n); } 
# 337
static char_type *move(char_type *__s1, const char_type *__s2, size_t __n) 
# 338
{ return wmemmove(__s1, __s2, __n); } 
# 341
static char_type *copy(char_type *__s1, const char_type *__s2, size_t __n) 
# 342
{ return wmemcpy(__s1, __s2, __n); } 
# 345
static char_type *assign(char_type *__s, size_t __n, char_type __a) 
# 346
{ return wmemset(__s, __a, __n); } 
# 349
static char_type to_char_type(const int_type &__c) 
# 350
{ return (char_type)__c; } 
# 353
static int_type to_int_type(const char_type &__c) 
# 354
{ return (int_type)__c; } 
# 357
static bool eq_int_type(const int_type &__c1, const int_type &__c2) 
# 358
{ return __c1 == __c2; } 
# 361
static int_type eof() 
# 362
{ return static_cast< int_type>(4294967295U); } 
# 365
static int_type not_eof(const int_type &__c) 
# 366
{ return eq_int_type(__c, eof()) ? 0 : __c; } 
# 367
}; 
# 371
}
# 32 "/usr/include/locale.h" 3
extern "C" {
# 54
struct lconv { 
# 58
char *decimal_point; 
# 59
char *thousands_sep; 
# 65
char *grouping; 
# 71
char *int_curr_symbol; 
# 72
char *currency_symbol; 
# 73
char *mon_decimal_point; 
# 74
char *mon_thousands_sep; 
# 75
char *mon_grouping; 
# 76
char *positive_sign; 
# 77
char *negative_sign; 
# 78
char int_frac_digits; 
# 79
char frac_digits; 
# 81
char p_cs_precedes; 
# 83
char p_sep_by_space; 
# 85
char n_cs_precedes; 
# 87
char n_sep_by_space; 
# 94
char p_sign_posn; 
# 95
char n_sign_posn; 
# 98
char int_p_cs_precedes; 
# 100
char int_p_sep_by_space; 
# 102
char int_n_cs_precedes; 
# 104
char int_n_sep_by_space; 
# 111
char int_p_sign_posn; 
# 112
char int_n_sign_posn; 
# 121
}; 
# 125
extern char *setlocale(int __category, const char * __locale) throw(); 
# 128
extern lconv *localeconv() throw(); 
# 152
extern __locale_t newlocale(int __category_mask, const char * __locale, __locale_t __base) throw(); 
# 187
extern __locale_t duplocale(__locale_t __dataset) throw(); 
# 191
extern void freelocale(__locale_t __dataset) throw(); 
# 198
extern __locale_t uselocale(__locale_t __dataset) throw(); 
# 206
}
# 51 "/usr/include/c++/4.8.2/clocale" 3
namespace std { 
# 53
using ::lconv;
# 54
using ::setlocale;
# 55
using ::localeconv;
# 56
}
# 48 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/c++locale.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 52
extern "C" __typeof__(uselocale) __uselocale; 
# 55
}
# 58
namespace std __attribute((__visibility__("default"))) { 
# 62
typedef __locale_t __c_locale; 
# 69
inline int __convert_from_v(const __c_locale &__cloc __attribute((__unused__)), char *
# 70
__out, const int 
# 71
__size __attribute((__unused__)), const char *
# 72
__fmt, ...) 
# 73
{ 
# 75
__c_locale __old = __gnu_cxx::__uselocale(__cloc); 
# 88
__builtin_va_list __args; 
# 89
__builtin_va_start((__args),__fmt); 
# 92
const int __ret = __builtin_vsnprintf(__out, __size, __fmt, __args); 
# 97
__builtin_va_end(__args); 
# 100
__gnu_cxx::__uselocale(__old); 
# 108
return __ret; 
# 109
} 
# 112
}
# 29 "/usr/include/ctype.h" 3
extern "C" {
# 48
enum { 
# 49
_ISupper = 256, 
# 50
_ISlower = 512, 
# 51
_ISalpha = 1024, 
# 52
_ISdigit = 2048, 
# 53
_ISxdigit = 4096, 
# 54
_ISspace = 8192, 
# 55
_ISprint = 16384, 
# 56
_ISgraph = 32768, 
# 57
_ISblank = 1, 
# 58
_IScntrl, 
# 59
_ISpunct = 4, 
# 60
_ISalnum = 8
# 61
}; 
# 80
extern const unsigned short **__ctype_b_loc() throw()
# 81
 __attribute((const)); 
# 82
extern const __int32_t **__ctype_tolower_loc() throw()
# 83
 __attribute((const)); 
# 84
extern const __int32_t **__ctype_toupper_loc() throw()
# 85
 __attribute((const)); 
# 111
extern int isalnum(int) throw(); 
# 112
extern int isalpha(int) throw(); 
# 113
extern int iscntrl(int) throw(); 
# 114
extern int isdigit(int) throw(); 
# 115
extern int islower(int) throw(); 
# 116
extern int isgraph(int) throw(); 
# 117
extern int isprint(int) throw(); 
# 118
extern int ispunct(int) throw(); 
# 119
extern int isspace(int) throw(); 
# 120
extern int isupper(int) throw(); 
# 121
extern int isxdigit(int) throw(); 
# 125
extern int tolower(int __c) throw(); 
# 128
extern int toupper(int __c) throw(); 
# 137
extern int isblank(int) throw(); 
# 144
extern int isctype(int __c, int __mask) throw(); 
# 151
extern int isascii(int __c) throw(); 
# 155
extern int toascii(int __c) throw(); 
# 159
extern int _toupper(int) throw(); 
# 160
extern int _tolower(int) throw(); 
# 272
extern int isalnum_l(int, __locale_t) throw(); 
# 273
extern int isalpha_l(int, __locale_t) throw(); 
# 274
extern int iscntrl_l(int, __locale_t) throw(); 
# 275
extern int isdigit_l(int, __locale_t) throw(); 
# 276
extern int islower_l(int, __locale_t) throw(); 
# 277
extern int isgraph_l(int, __locale_t) throw(); 
# 278
extern int isprint_l(int, __locale_t) throw(); 
# 279
extern int ispunct_l(int, __locale_t) throw(); 
# 280
extern int isspace_l(int, __locale_t) throw(); 
# 281
extern int isupper_l(int, __locale_t) throw(); 
# 282
extern int isxdigit_l(int, __locale_t) throw(); 
# 284
extern int isblank_l(int, __locale_t) throw(); 
# 288
extern int __tolower_l(int __c, __locale_t __l) throw(); 
# 289
extern int tolower_l(int __c, __locale_t __l) throw(); 
# 292
extern int __toupper_l(int __c, __locale_t __l) throw(); 
# 293
extern int toupper_l(int __c, __locale_t __l) throw(); 
# 348
}
# 62 "/usr/include/c++/4.8.2/cctype" 3
namespace std { 
# 64
using ::isalnum;
# 65
using ::isalpha;
# 66
using ::iscntrl;
# 67
using ::isdigit;
# 68
using ::isgraph;
# 69
using ::islower;
# 70
using ::isprint;
# 71
using ::ispunct;
# 72
using ::isspace;
# 73
using ::isupper;
# 74
using ::isxdigit;
# 75
using ::tolower;
# 76
using ::toupper;
# 77
}
# 44 "/usr/include/c++/4.8.2/bits/localefwd.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 55
class locale; 
# 57
template< class _Facet> bool has_facet(const locale &) throw(); 
# 61
template< class _Facet> const _Facet &use_facet(const locale &); 
# 66
template< class _CharT> inline bool isspace(_CharT, const locale &); 
# 70
template< class _CharT> inline bool isprint(_CharT, const locale &); 
# 74
template< class _CharT> inline bool iscntrl(_CharT, const locale &); 
# 78
template< class _CharT> inline bool isupper(_CharT, const locale &); 
# 82
template< class _CharT> inline bool islower(_CharT, const locale &); 
# 86
template< class _CharT> inline bool isalpha(_CharT, const locale &); 
# 90
template< class _CharT> inline bool isdigit(_CharT, const locale &); 
# 94
template< class _CharT> inline bool ispunct(_CharT, const locale &); 
# 98
template< class _CharT> inline bool isxdigit(_CharT, const locale &); 
# 102
template< class _CharT> inline bool isalnum(_CharT, const locale &); 
# 106
template< class _CharT> inline bool isgraph(_CharT, const locale &); 
# 110
template< class _CharT> inline _CharT toupper(_CharT, const locale &); 
# 114
template< class _CharT> inline _CharT tolower(_CharT, const locale &); 
# 119
struct ctype_base; 
# 120
template< class _CharT> class ctype; 
# 122
template<> class ctype< char> ; 
# 124
template<> class ctype< wchar_t> ; 
# 126
template< class _CharT> class ctype_byname; 
# 130
class codecvt_base; 
# 131
template< class _InternT, class _ExternT, class _StateT> class codecvt; 
# 133
template<> class codecvt< char, char, __mbstate_t> ; 
# 135
template<> class codecvt< wchar_t, char, __mbstate_t> ; 
# 137
template< class _InternT, class _ExternT, class _StateT> class codecvt_byname; 
# 142
template< class _CharT, class _InIter = istreambuf_iterator< _CharT, char_traits< _CharT> > > class num_get; 
# 144
template< class _CharT, class _OutIter = ostreambuf_iterator< _CharT, char_traits< _CharT> > > class num_put; 
# 147
template< class _CharT> class numpunct; 
# 148
template< class _CharT> class numpunct_byname; 
# 151
template< class _CharT> class collate; 
# 153
template< class _CharT> class collate_byname; 
# 157
class time_base; 
# 158
template< class _CharT, class _InIter = istreambuf_iterator< _CharT, char_traits< _CharT> > > class time_get; 
# 160
template< class _CharT, class _InIter = istreambuf_iterator< _CharT, char_traits< _CharT> > > class time_get_byname; 
# 162
template< class _CharT, class _OutIter = ostreambuf_iterator< _CharT, char_traits< _CharT> > > class time_put; 
# 164
template< class _CharT, class _OutIter = ostreambuf_iterator< _CharT, char_traits< _CharT> > > class time_put_byname; 
# 168
class money_base; 
# 170
template< class _CharT, class _InIter = istreambuf_iterator< _CharT, char_traits< _CharT> > > class money_get; 
# 172
template< class _CharT, class _OutIter = ostreambuf_iterator< _CharT, char_traits< _CharT> > > class money_put; 
# 175
template< class _CharT, bool _Intl = false> class moneypunct; 
# 177
template< class _CharT, bool _Intl = false> class moneypunct_byname; 
# 181
class messages_base; 
# 182
template< class _CharT> class messages; 
# 184
template< class _CharT> class messages_byname; 
# 188
}
# 30 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/gthr.h" 3
#pragma GCC visibility push ( default )
# 73 "/usr/include/bits/sched.h" 3
struct sched_param { 
# 75
int __sched_priority; 
# 76
}; 
# 78
extern "C" {
# 82
extern int clone(int (* __fn)(void * __arg), void * __child_stack, int __flags, void * __arg, ...) throw(); 
# 86
extern int unshare(int __flags) throw(); 
# 89
extern int sched_getcpu() throw(); 
# 92
extern int setns(int __fd, int __nstype) throw(); 
# 96
}
# 104
struct __sched_param { 
# 106
int __sched_priority; 
# 107
}; 
# 119
typedef unsigned long __cpu_mask; 
# 129
typedef 
# 127
struct { 
# 128
__cpu_mask __bits[(1024) / ((8) * sizeof(__cpu_mask))]; 
# 129
} cpu_set_t; 
# 202
extern "C" {
# 204
extern int __sched_cpucount(::size_t __setsize, const cpu_set_t * __setp) throw(); 
# 206
extern cpu_set_t *__sched_cpualloc(::size_t __count) throw(); 
# 207
extern void __sched_cpufree(cpu_set_t * __set) throw(); 
# 209
}
# 47 "/usr/include/sched.h" 3
extern "C" {
# 50
extern int sched_setparam(__pid_t __pid, const sched_param * __param) throw(); 
# 54
extern int sched_getparam(__pid_t __pid, sched_param * __param) throw(); 
# 57
extern int sched_setscheduler(__pid_t __pid, int __policy, const sched_param * __param) throw(); 
# 61
extern int sched_getscheduler(__pid_t __pid) throw(); 
# 64
extern int sched_yield() throw(); 
# 67
extern int sched_get_priority_max(int __algorithm) throw(); 
# 70
extern int sched_get_priority_min(int __algorithm) throw(); 
# 73
extern int sched_rr_get_interval(__pid_t __pid, timespec * __t) throw(); 
# 117
extern int sched_setaffinity(__pid_t __pid, ::size_t __cpusetsize, const cpu_set_t * __cpuset) throw(); 
# 121
extern int sched_getaffinity(__pid_t __pid, ::size_t __cpusetsize, cpu_set_t * __cpuset) throw(); 
# 125
}
# 31 "/usr/include/bits/setjmp.h" 3
typedef long __jmp_buf[8]; 
# 33 "/usr/include/pthread.h" 3
enum { 
# 34
PTHREAD_CREATE_JOINABLE, 
# 36
PTHREAD_CREATE_DETACHED
# 38
}; 
# 43
enum { 
# 44
PTHREAD_MUTEX_TIMED_NP, 
# 45
PTHREAD_MUTEX_RECURSIVE_NP, 
# 46
PTHREAD_MUTEX_ERRORCHECK_NP, 
# 47
PTHREAD_MUTEX_ADAPTIVE_NP, 
# 50
PTHREAD_MUTEX_NORMAL = 0, 
# 51
PTHREAD_MUTEX_RECURSIVE, 
# 52
PTHREAD_MUTEX_ERRORCHECK, 
# 53
PTHREAD_MUTEX_DEFAULT = 0, 
# 57
PTHREAD_MUTEX_FAST_NP = 0
# 59
}; 
# 65
enum { 
# 66
PTHREAD_MUTEX_STALLED, 
# 67
PTHREAD_MUTEX_STALLED_NP = 0, 
# 68
PTHREAD_MUTEX_ROBUST, 
# 69
PTHREAD_MUTEX_ROBUST_NP = 1
# 70
}; 
# 77
enum { 
# 78
PTHREAD_PRIO_NONE, 
# 79
PTHREAD_PRIO_INHERIT, 
# 80
PTHREAD_PRIO_PROTECT
# 81
}; 
# 126
enum { 
# 127
PTHREAD_RWLOCK_PREFER_READER_NP, 
# 128
PTHREAD_RWLOCK_PREFER_WRITER_NP, 
# 129
PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP, 
# 130
PTHREAD_RWLOCK_DEFAULT_NP = 0
# 131
}; 
# 167
enum { 
# 168
PTHREAD_INHERIT_SCHED, 
# 170
PTHREAD_EXPLICIT_SCHED
# 172
}; 
# 177
enum { 
# 178
PTHREAD_SCOPE_SYSTEM, 
# 180
PTHREAD_SCOPE_PROCESS
# 182
}; 
# 187
enum { 
# 188
PTHREAD_PROCESS_PRIVATE, 
# 190
PTHREAD_PROCESS_SHARED
# 192
}; 
# 201
struct _pthread_cleanup_buffer { 
# 203
void (*__routine)(void *); 
# 204
void *__arg; 
# 205
int __canceltype; 
# 206
_pthread_cleanup_buffer *__prev; 
# 207
}; 
# 211
enum { 
# 212
PTHREAD_CANCEL_ENABLE, 
# 214
PTHREAD_CANCEL_DISABLE
# 216
}; 
# 218
enum { 
# 219
PTHREAD_CANCEL_DEFERRED, 
# 221
PTHREAD_CANCEL_ASYNCHRONOUS
# 223
}; 
# 239
extern "C" {
# 244
extern int pthread_create(pthread_t *__restrict__ __newthread, const pthread_attr_t *__restrict__ __attr, void *(* __start_routine)(void *), void *__restrict__ __arg) throw()
# 247
 __attribute((__nonnull__(1, 3))); 
# 253
extern void pthread_exit(void * __retval) __attribute((__noreturn__)); 
# 261
extern int pthread_join(pthread_t __th, void ** __thread_return); 
# 266
extern int pthread_tryjoin_np(pthread_t __th, void ** __thread_return) throw(); 
# 274
extern int pthread_timedjoin_np(pthread_t __th, void ** __thread_return, const timespec * __abstime); 
# 282
extern int pthread_detach(pthread_t __th) throw(); 
# 286
extern pthread_t pthread_self() throw() __attribute((const)); 
# 289
extern int pthread_equal(pthread_t __thread1, pthread_t __thread2) throw()
# 290
 __attribute((const)); 
# 298
extern int pthread_attr_init(pthread_attr_t * __attr) throw() __attribute((__nonnull__(1))); 
# 301
extern int pthread_attr_destroy(pthread_attr_t * __attr) throw()
# 302
 __attribute((__nonnull__(1))); 
# 305
extern int pthread_attr_getdetachstate(const pthread_attr_t * __attr, int * __detachstate) throw()
# 307
 __attribute((__nonnull__(1, 2))); 
# 310
extern int pthread_attr_setdetachstate(pthread_attr_t * __attr, int __detachstate) throw()
# 312
 __attribute((__nonnull__(1))); 
# 316
extern int pthread_attr_getguardsize(const pthread_attr_t * __attr, ::size_t * __guardsize) throw()
# 318
 __attribute((__nonnull__(1, 2))); 
# 321
extern int pthread_attr_setguardsize(pthread_attr_t * __attr, ::size_t __guardsize) throw()
# 323
 __attribute((__nonnull__(1))); 
# 327
extern int pthread_attr_getschedparam(const pthread_attr_t *__restrict__ __attr, sched_param *__restrict__ __param) throw()
# 329
 __attribute((__nonnull__(1, 2))); 
# 332
extern int pthread_attr_setschedparam(pthread_attr_t *__restrict__ __attr, const sched_param *__restrict__ __param) throw()
# 334
 __attribute((__nonnull__(1, 2))); 
# 337
extern int pthread_attr_getschedpolicy(const pthread_attr_t *__restrict__ __attr, int *__restrict__ __policy) throw()
# 339
 __attribute((__nonnull__(1, 2))); 
# 342
extern int pthread_attr_setschedpolicy(pthread_attr_t * __attr, int __policy) throw()
# 343
 __attribute((__nonnull__(1))); 
# 346
extern int pthread_attr_getinheritsched(const pthread_attr_t *__restrict__ __attr, int *__restrict__ __inherit) throw()
# 348
 __attribute((__nonnull__(1, 2))); 
# 351
extern int pthread_attr_setinheritsched(pthread_attr_t * __attr, int __inherit) throw()
# 353
 __attribute((__nonnull__(1))); 
# 357
extern int pthread_attr_getscope(const pthread_attr_t *__restrict__ __attr, int *__restrict__ __scope) throw()
# 359
 __attribute((__nonnull__(1, 2))); 
# 362
extern int pthread_attr_setscope(pthread_attr_t * __attr, int __scope) throw()
# 363
 __attribute((__nonnull__(1))); 
# 366
extern int pthread_attr_getstackaddr(const pthread_attr_t *__restrict__ __attr, void **__restrict__ __stackaddr) throw()
# 368
 __attribute((__nonnull__(1, 2))) __attribute((__deprecated__)); 
# 374
extern int pthread_attr_setstackaddr(pthread_attr_t * __attr, void * __stackaddr) throw()
# 376
 __attribute((__nonnull__(1))) __attribute((__deprecated__)); 
# 379
extern int pthread_attr_getstacksize(const pthread_attr_t *__restrict__ __attr, ::size_t *__restrict__ __stacksize) throw()
# 381
 __attribute((__nonnull__(1, 2))); 
# 386
extern int pthread_attr_setstacksize(pthread_attr_t * __attr, ::size_t __stacksize) throw()
# 388
 __attribute((__nonnull__(1))); 
# 392
extern int pthread_attr_getstack(const pthread_attr_t *__restrict__ __attr, void **__restrict__ __stackaddr, ::size_t *__restrict__ __stacksize) throw()
# 395
 __attribute((__nonnull__(1, 2, 3))); 
# 400
extern int pthread_attr_setstack(pthread_attr_t * __attr, void * __stackaddr, ::size_t __stacksize) throw()
# 401
 __attribute((__nonnull__(1))); 
# 407
extern int pthread_attr_setaffinity_np(pthread_attr_t * __attr, ::size_t __cpusetsize, const cpu_set_t * __cpuset) throw()
# 410
 __attribute((__nonnull__(1, 3))); 
# 414
extern int pthread_attr_getaffinity_np(const pthread_attr_t * __attr, ::size_t __cpusetsize, cpu_set_t * __cpuset) throw()
# 417
 __attribute((__nonnull__(1, 3))); 
# 423
extern int pthread_getattr_np(pthread_t __th, pthread_attr_t * __attr) throw()
# 424
 __attribute((__nonnull__(2))); 
# 432
extern int pthread_setschedparam(pthread_t __target_thread, int __policy, const sched_param * __param) throw()
# 434
 __attribute((__nonnull__(3))); 
# 437
extern int pthread_getschedparam(pthread_t __target_thread, int *__restrict__ __policy, sched_param *__restrict__ __param) throw()
# 440
 __attribute((__nonnull__(2, 3))); 
# 443
extern int pthread_setschedprio(pthread_t __target_thread, int __prio) throw(); 
# 449
extern int pthread_getname_np(pthread_t __target_thread, char * __buf, ::size_t __buflen) throw()
# 451
 __attribute((__nonnull__(2))); 
# 454
extern int pthread_setname_np(pthread_t __target_thread, const char * __name) throw()
# 455
 __attribute((__nonnull__(2))); 
# 461
extern int pthread_getconcurrency() throw(); 
# 464
extern int pthread_setconcurrency(int __level) throw(); 
# 472
extern int pthread_yield() throw(); 
# 477
extern int pthread_setaffinity_np(pthread_t __th, ::size_t __cpusetsize, const cpu_set_t * __cpuset) throw()
# 479
 __attribute((__nonnull__(3))); 
# 482
extern int pthread_getaffinity_np(pthread_t __th, ::size_t __cpusetsize, cpu_set_t * __cpuset) throw()
# 484
 __attribute((__nonnull__(3))); 
# 497
extern int pthread_once(pthread_once_t * __once_control, void (* __init_routine)(void))
# 498
 __attribute((__nonnull__(1, 2))); 
# 509
extern int pthread_setcancelstate(int __state, int * __oldstate); 
# 513
extern int pthread_setcanceltype(int __type, int * __oldtype); 
# 516
extern int pthread_cancel(pthread_t __th); 
# 521
extern void pthread_testcancel(); 
# 534
typedef 
# 527
struct { 
# 529
struct { 
# 530
__jmp_buf __cancel_jmp_buf; 
# 531
int __mask_was_saved; 
# 532
} __cancel_jmp_buf[1]; 
# 533
void *__pad[4]; 
# 534
} __pthread_unwind_buf_t __attribute((__aligned__)); 
# 543
struct __pthread_cleanup_frame { 
# 545
void (*__cancel_routine)(void *); 
# 546
void *__cancel_arg; 
# 547
int __do_it; 
# 548
int __cancel_type; 
# 549
}; 
# 554
class __pthread_cleanup_class { 
# 556
void (*__cancel_routine)(void *); 
# 557
void *__cancel_arg; 
# 558
int __do_it; 
# 559
int __cancel_type; 
# 562
public: __pthread_cleanup_class(void (*__fct)(void *), void *__arg) : __cancel_routine(__fct), __cancel_arg(__arg), __do_it(1) 
# 563
{ } 
# 564
~__pthread_cleanup_class() { if (__do_it) { (__cancel_routine)(__cancel_arg); }  } 
# 565
void __setdoit(int __newval) { (__do_it) = __newval; } 
# 566
void __defer() { pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &(__cancel_type)); 
# 567
} 
# 568
void __restore() const { pthread_setcanceltype(__cancel_type, 0); } 
# 569
}; 
# 745
struct __jmp_buf_tag; 
# 746
extern int __sigsetjmp(__jmp_buf_tag * __env, int __savemask) throw(); 
# 752
extern int pthread_mutex_init(pthread_mutex_t * __mutex, const pthread_mutexattr_t * __mutexattr) throw()
# 754
 __attribute((__nonnull__(1))); 
# 757
extern int pthread_mutex_destroy(pthread_mutex_t * __mutex) throw()
# 758
 __attribute((__nonnull__(1))); 
# 761
extern int pthread_mutex_trylock(pthread_mutex_t * __mutex) throw()
# 762
 __attribute((__nonnull__(1))); 
# 765
extern int pthread_mutex_lock(pthread_mutex_t * __mutex) throw()
# 766
 __attribute((__nonnull__(1))); 
# 770
extern int pthread_mutex_timedlock(pthread_mutex_t *__restrict__ __mutex, const timespec *__restrict__ __abstime) throw()
# 772
 __attribute((__nonnull__(1, 2))); 
# 776
extern int pthread_mutex_unlock(pthread_mutex_t * __mutex) throw()
# 777
 __attribute((__nonnull__(1))); 
# 781
extern int pthread_mutex_getprioceiling(const pthread_mutex_t *__restrict__ __mutex, int *__restrict__ __prioceiling) throw()
# 784
 __attribute((__nonnull__(1, 2))); 
# 788
extern int pthread_mutex_setprioceiling(pthread_mutex_t *__restrict__ __mutex, int __prioceiling, int *__restrict__ __old_ceiling) throw()
# 791
 __attribute((__nonnull__(1, 3))); 
# 796
extern int pthread_mutex_consistent(pthread_mutex_t * __mutex) throw()
# 797
 __attribute((__nonnull__(1))); 
# 799
extern int pthread_mutex_consistent_np(pthread_mutex_t * __mutex) throw()
# 800
 __attribute((__nonnull__(1))); 
# 809
extern int pthread_mutexattr_init(pthread_mutexattr_t * __attr) throw()
# 810
 __attribute((__nonnull__(1))); 
# 813
extern int pthread_mutexattr_destroy(pthread_mutexattr_t * __attr) throw()
# 814
 __attribute((__nonnull__(1))); 
# 817
extern int pthread_mutexattr_getpshared(const pthread_mutexattr_t *__restrict__ __attr, int *__restrict__ __pshared) throw()
# 820
 __attribute((__nonnull__(1, 2))); 
# 823
extern int pthread_mutexattr_setpshared(pthread_mutexattr_t * __attr, int __pshared) throw()
# 825
 __attribute((__nonnull__(1))); 
# 829
extern int pthread_mutexattr_gettype(const pthread_mutexattr_t *__restrict__ __attr, int *__restrict__ __kind) throw()
# 831
 __attribute((__nonnull__(1, 2))); 
# 836
extern int pthread_mutexattr_settype(pthread_mutexattr_t * __attr, int __kind) throw()
# 837
 __attribute((__nonnull__(1))); 
# 841
extern int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *__restrict__ __attr, int *__restrict__ __protocol) throw()
# 844
 __attribute((__nonnull__(1, 2))); 
# 848
extern int pthread_mutexattr_setprotocol(pthread_mutexattr_t * __attr, int __protocol) throw()
# 850
 __attribute((__nonnull__(1))); 
# 853
extern int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *__restrict__ __attr, int *__restrict__ __prioceiling) throw()
# 856
 __attribute((__nonnull__(1, 2))); 
# 859
extern int pthread_mutexattr_setprioceiling(pthread_mutexattr_t * __attr, int __prioceiling) throw()
# 861
 __attribute((__nonnull__(1))); 
# 865
extern int pthread_mutexattr_getrobust(const pthread_mutexattr_t * __attr, int * __robustness) throw()
# 867
 __attribute((__nonnull__(1, 2))); 
# 869
extern int pthread_mutexattr_getrobust_np(const pthread_mutexattr_t * __attr, int * __robustness) throw()
# 871
 __attribute((__nonnull__(1, 2))); 
# 875
extern int pthread_mutexattr_setrobust(pthread_mutexattr_t * __attr, int __robustness) throw()
# 877
 __attribute((__nonnull__(1))); 
# 879
extern int pthread_mutexattr_setrobust_np(pthread_mutexattr_t * __attr, int __robustness) throw()
# 881
 __attribute((__nonnull__(1))); 
# 891
extern int pthread_rwlock_init(pthread_rwlock_t *__restrict__ __rwlock, const pthread_rwlockattr_t *__restrict__ __attr) throw()
# 893
 __attribute((__nonnull__(1))); 
# 896
extern int pthread_rwlock_destroy(pthread_rwlock_t * __rwlock) throw()
# 897
 __attribute((__nonnull__(1))); 
# 900
extern int pthread_rwlock_rdlock(pthread_rwlock_t * __rwlock) throw()
# 901
 __attribute((__nonnull__(1))); 
# 904
extern int pthread_rwlock_tryrdlock(pthread_rwlock_t * __rwlock) throw()
# 905
 __attribute((__nonnull__(1))); 
# 909
extern int pthread_rwlock_timedrdlock(pthread_rwlock_t *__restrict__ __rwlock, const timespec *__restrict__ __abstime) throw()
# 911
 __attribute((__nonnull__(1, 2))); 
# 915
extern int pthread_rwlock_wrlock(pthread_rwlock_t * __rwlock) throw()
# 916
 __attribute((__nonnull__(1))); 
# 919
extern int pthread_rwlock_trywrlock(pthread_rwlock_t * __rwlock) throw()
# 920
 __attribute((__nonnull__(1))); 
# 924
extern int pthread_rwlock_timedwrlock(pthread_rwlock_t *__restrict__ __rwlock, const timespec *__restrict__ __abstime) throw()
# 926
 __attribute((__nonnull__(1, 2))); 
# 930
extern int pthread_rwlock_unlock(pthread_rwlock_t * __rwlock) throw()
# 931
 __attribute((__nonnull__(1))); 
# 937
extern int pthread_rwlockattr_init(pthread_rwlockattr_t * __attr) throw()
# 938
 __attribute((__nonnull__(1))); 
# 941
extern int pthread_rwlockattr_destroy(pthread_rwlockattr_t * __attr) throw()
# 942
 __attribute((__nonnull__(1))); 
# 945
extern int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *__restrict__ __attr, int *__restrict__ __pshared) throw()
# 948
 __attribute((__nonnull__(1, 2))); 
# 951
extern int pthread_rwlockattr_setpshared(pthread_rwlockattr_t * __attr, int __pshared) throw()
# 953
 __attribute((__nonnull__(1))); 
# 956
extern int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *__restrict__ __attr, int *__restrict__ __pref) throw()
# 959
 __attribute((__nonnull__(1, 2))); 
# 962
extern int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t * __attr, int __pref) throw()
# 963
 __attribute((__nonnull__(1))); 
# 971
extern int pthread_cond_init(pthread_cond_t *__restrict__ __cond, const pthread_condattr_t *__restrict__ __cond_attr) throw()
# 973
 __attribute((__nonnull__(1))); 
# 976
extern int pthread_cond_destroy(pthread_cond_t * __cond) throw()
# 977
 __attribute((__nonnull__(1))); 
# 980
extern int pthread_cond_signal(pthread_cond_t * __cond) throw()
# 981
 __attribute((__nonnull__(1))); 
# 984
extern int pthread_cond_broadcast(pthread_cond_t * __cond) throw()
# 985
 __attribute((__nonnull__(1))); 
# 992
extern int pthread_cond_wait(pthread_cond_t *__restrict__ __cond, pthread_mutex_t *__restrict__ __mutex)
# 994
 __attribute((__nonnull__(1, 2))); 
# 1003
extern int pthread_cond_timedwait(pthread_cond_t *__restrict__ __cond, pthread_mutex_t *__restrict__ __mutex, const timespec *__restrict__ __abstime)
# 1006
 __attribute((__nonnull__(1, 2, 3))); 
# 1011
extern int pthread_condattr_init(pthread_condattr_t * __attr) throw()
# 1012
 __attribute((__nonnull__(1))); 
# 1015
extern int pthread_condattr_destroy(pthread_condattr_t * __attr) throw()
# 1016
 __attribute((__nonnull__(1))); 
# 1019
extern int pthread_condattr_getpshared(const pthread_condattr_t *__restrict__ __attr, int *__restrict__ __pshared) throw()
# 1022
 __attribute((__nonnull__(1, 2))); 
# 1025
extern int pthread_condattr_setpshared(pthread_condattr_t * __attr, int __pshared) throw()
# 1026
 __attribute((__nonnull__(1))); 
# 1030
extern int pthread_condattr_getclock(const pthread_condattr_t *__restrict__ __attr, __clockid_t *__restrict__ __clock_id) throw()
# 1033
 __attribute((__nonnull__(1, 2))); 
# 1036
extern int pthread_condattr_setclock(pthread_condattr_t * __attr, __clockid_t __clock_id) throw()
# 1038
 __attribute((__nonnull__(1))); 
# 1047
extern int pthread_spin_init(pthread_spinlock_t * __lock, int __pshared) throw()
# 1048
 __attribute((__nonnull__(1))); 
# 1051
extern int pthread_spin_destroy(pthread_spinlock_t * __lock) throw()
# 1052
 __attribute((__nonnull__(1))); 
# 1055
extern int pthread_spin_lock(pthread_spinlock_t * __lock) throw()
# 1056
 __attribute((__nonnull__(1))); 
# 1059
extern int pthread_spin_trylock(pthread_spinlock_t * __lock) throw()
# 1060
 __attribute((__nonnull__(1))); 
# 1063
extern int pthread_spin_unlock(pthread_spinlock_t * __lock) throw()
# 1064
 __attribute((__nonnull__(1))); 
# 1071
extern int pthread_barrier_init(pthread_barrier_t *__restrict__ __barrier, const pthread_barrierattr_t *__restrict__ __attr, unsigned __count) throw()
# 1074
 __attribute((__nonnull__(1))); 
# 1077
extern int pthread_barrier_destroy(pthread_barrier_t * __barrier) throw()
# 1078
 __attribute((__nonnull__(1))); 
# 1081
extern int pthread_barrier_wait(pthread_barrier_t * __barrier) throw()
# 1082
 __attribute((__nonnull__(1))); 
# 1086
extern int pthread_barrierattr_init(pthread_barrierattr_t * __attr) throw()
# 1087
 __attribute((__nonnull__(1))); 
# 1090
extern int pthread_barrierattr_destroy(pthread_barrierattr_t * __attr) throw()
# 1091
 __attribute((__nonnull__(1))); 
# 1094
extern int pthread_barrierattr_getpshared(const pthread_barrierattr_t *__restrict__ __attr, int *__restrict__ __pshared) throw()
# 1097
 __attribute((__nonnull__(1, 2))); 
# 1100
extern int pthread_barrierattr_setpshared(pthread_barrierattr_t * __attr, int __pshared) throw()
# 1102
 __attribute((__nonnull__(1))); 
# 1114
extern int pthread_key_create(pthread_key_t * __key, void (* __destr_function)(void *)) throw()
# 1116
 __attribute((__nonnull__(1))); 
# 1119
extern int pthread_key_delete(pthread_key_t __key) throw(); 
# 1122
extern void *pthread_getspecific(pthread_key_t __key) throw(); 
# 1125
extern int pthread_setspecific(pthread_key_t __key, const void * __pointer) throw(); 
# 1131
extern int pthread_getcpuclockid(pthread_t __thread_id, __clockid_t * __clock_id) throw()
# 1133
 __attribute((__nonnull__(2))); 
# 1148
extern int pthread_atfork(void (* __prepare)(void), void (* __parent)(void), void (* __child)(void)) throw(); 
# 1162
}
# 47 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/gthr-default.h" 3
typedef pthread_t __gthread_t; 
# 48
typedef pthread_key_t __gthread_key_t; 
# 49
typedef pthread_once_t __gthread_once_t; 
# 50
typedef pthread_mutex_t __gthread_mutex_t; 
# 51
typedef pthread_mutex_t __gthread_recursive_mutex_t; 
# 52
typedef pthread_cond_t __gthread_cond_t; 
# 53
typedef timespec __gthread_time_t; 
# 101
static __typeof__(pthread_once) __gthrw_pthread_once __attribute((__weakref__("pthread_once"))); 
# 102
static __typeof__(pthread_getspecific) __gthrw_pthread_getspecific __attribute((__weakref__("pthread_getspecific"))); 
# 103
static __typeof__(pthread_setspecific) __gthrw_pthread_setspecific __attribute((__weakref__("pthread_setspecific"))); 
# 105
static __typeof__(pthread_create) __gthrw_pthread_create __attribute((__weakref__("pthread_create"))); 
# 106
static __typeof__(pthread_join) __gthrw_pthread_join __attribute((__weakref__("pthread_join"))); 
# 107
static __typeof__(pthread_equal) __gthrw_pthread_equal __attribute((__weakref__("pthread_equal"))); 
# 108
static __typeof__(pthread_self) __gthrw_pthread_self __attribute((__weakref__("pthread_self"))); 
# 109
static __typeof__(pthread_detach) __gthrw_pthread_detach __attribute((__weakref__("pthread_detach"))); 
# 111
static __typeof__(pthread_cancel) __gthrw_pthread_cancel __attribute((__weakref__("pthread_cancel"))); 
# 113
static __typeof__(sched_yield) __gthrw_sched_yield __attribute((__weakref__("sched_yield"))); 
# 115
static __typeof__(pthread_mutex_lock) __gthrw_pthread_mutex_lock __attribute((__weakref__("pthread_mutex_lock"))); 
# 116
static __typeof__(pthread_mutex_trylock) __gthrw_pthread_mutex_trylock __attribute((__weakref__("pthread_mutex_trylock"))); 
# 118
static __typeof__(pthread_mutex_timedlock) __gthrw_pthread_mutex_timedlock __attribute((__weakref__("pthread_mutex_timedlock"))); 
# 120
static __typeof__(pthread_mutex_unlock) __gthrw_pthread_mutex_unlock __attribute((__weakref__("pthread_mutex_unlock"))); 
# 121
static __typeof__(pthread_mutex_init) __gthrw_pthread_mutex_init __attribute((__weakref__("pthread_mutex_init"))); 
# 122
static __typeof__(pthread_mutex_destroy) __gthrw_pthread_mutex_destroy __attribute((__weakref__("pthread_mutex_destroy"))); 
# 124
static __typeof__(pthread_cond_init) __gthrw_pthread_cond_init __attribute((__weakref__("pthread_cond_init"))); 
# 125
static __typeof__(pthread_cond_broadcast) __gthrw_pthread_cond_broadcast __attribute((__weakref__("pthread_cond_broadcast"))); 
# 126
static __typeof__(pthread_cond_signal) __gthrw_pthread_cond_signal __attribute((__weakref__("pthread_cond_signal"))); 
# 127
static __typeof__(pthread_cond_wait) __gthrw_pthread_cond_wait __attribute((__weakref__("pthread_cond_wait"))); 
# 128
static __typeof__(pthread_cond_timedwait) __gthrw_pthread_cond_timedwait __attribute((__weakref__("pthread_cond_timedwait"))); 
# 129
static __typeof__(pthread_cond_destroy) __gthrw_pthread_cond_destroy __attribute((__weakref__("pthread_cond_destroy"))); 
# 131
static __typeof__(pthread_key_create) __gthrw_pthread_key_create __attribute((__weakref__("pthread_key_create"))); 
# 132
static __typeof__(pthread_key_delete) __gthrw_pthread_key_delete __attribute((__weakref__("pthread_key_delete"))); 
# 133
static __typeof__(pthread_mutexattr_init) __gthrw_pthread_mutexattr_init __attribute((__weakref__("pthread_mutexattr_init"))); 
# 134
static __typeof__(pthread_mutexattr_settype) __gthrw_pthread_mutexattr_settype __attribute((__weakref__("pthread_mutexattr_settype"))); 
# 135
static __typeof__(pthread_mutexattr_destroy) __gthrw_pthread_mutexattr_destroy __attribute((__weakref__("pthread_mutexattr_destroy"))); 
# 236
static __typeof__(pthread_key_create) __gthrw___pthread_key_create __attribute((__weakref__("__pthread_key_create"))); 
# 247
static inline int __gthread_active_p() 
# 248
{ 
# 249
static void *const __gthread_active_ptr = __extension__ ((void *)(&__gthrw___pthread_key_create)); 
# 251
return __gthread_active_ptr != (0); 
# 252
} 
# 659
static inline int __gthread_create(__gthread_t *__threadid, void *(*__func)(void *), void *
# 660
__args) 
# 661
{ 
# 662
return __gthrw_pthread_create(__threadid, __null, __func, __args); 
# 663
} 
# 666
static inline int __gthread_join(__gthread_t __threadid, void **__value_ptr) 
# 667
{ 
# 668
return __gthrw_pthread_join(__threadid, __value_ptr); 
# 669
} 
# 672
static inline int __gthread_detach(__gthread_t __threadid) 
# 673
{ 
# 674
return __gthrw_pthread_detach(__threadid); 
# 675
} 
# 678
static inline int __gthread_equal(__gthread_t __t1, __gthread_t __t2) 
# 679
{ 
# 680
return __gthrw_pthread_equal(__t1, __t2); 
# 681
} 
# 684
static inline __gthread_t __gthread_self() 
# 685
{ 
# 686
return __gthrw_pthread_self(); 
# 687
} 
# 690
static inline int __gthread_yield() 
# 691
{ 
# 692
return __gthrw_sched_yield(); 
# 693
} 
# 696
static inline int __gthread_once(__gthread_once_t *__once, void (*__func)(void)) 
# 697
{ 
# 698
if (__gthread_active_p()) { 
# 699
return __gthrw_pthread_once(__once, __func); } else { 
# 701
return -1; }  
# 702
} 
# 705
static inline int __gthread_key_create(__gthread_key_t *__key, void (*__dtor)(void *)) 
# 706
{ 
# 707
return __gthrw_pthread_key_create(__key, __dtor); 
# 708
} 
# 711
static inline int __gthread_key_delete(__gthread_key_t __key) 
# 712
{ 
# 713
return __gthrw_pthread_key_delete(__key); 
# 714
} 
# 717
static inline void *__gthread_getspecific(__gthread_key_t __key) 
# 718
{ 
# 719
return __gthrw_pthread_getspecific(__key); 
# 720
} 
# 723
static inline int __gthread_setspecific(__gthread_key_t __key, const void *__ptr) 
# 724
{ 
# 725
return __gthrw_pthread_setspecific(__key, __ptr); 
# 726
} 
# 729
static inline void __gthread_mutex_init_function(__gthread_mutex_t *__mutex) 
# 730
{ 
# 731
if (__gthread_active_p()) { 
# 732
__gthrw_pthread_mutex_init(__mutex, __null); }  
# 733
} 
# 736
static inline int __gthread_mutex_destroy(__gthread_mutex_t *__mutex) 
# 737
{ 
# 738
if (__gthread_active_p()) { 
# 739
return __gthrw_pthread_mutex_destroy(__mutex); } else { 
# 741
return 0; }  
# 742
} 
# 745
static inline int __gthread_mutex_lock(__gthread_mutex_t *__mutex) 
# 746
{ 
# 747
if (__gthread_active_p()) { 
# 748
return __gthrw_pthread_mutex_lock(__mutex); } else { 
# 750
return 0; }  
# 751
} 
# 754
static inline int __gthread_mutex_trylock(__gthread_mutex_t *__mutex) 
# 755
{ 
# 756
if (__gthread_active_p()) { 
# 757
return __gthrw_pthread_mutex_trylock(__mutex); } else { 
# 759
return 0; }  
# 760
} 
# 764
static inline int __gthread_mutex_timedlock(__gthread_mutex_t *__mutex, const __gthread_time_t *
# 765
__abs_timeout) 
# 766
{ 
# 767
if (__gthread_active_p()) { 
# 768
return __gthrw_pthread_mutex_timedlock(__mutex, __abs_timeout); } else { 
# 770
return 0; }  
# 771
} 
# 775
static inline int __gthread_mutex_unlock(__gthread_mutex_t *__mutex) 
# 776
{ 
# 777
if (__gthread_active_p()) { 
# 778
return __gthrw_pthread_mutex_unlock(__mutex); } else { 
# 780
return 0; }  
# 781
} 
# 808
static inline int __gthread_recursive_mutex_lock(__gthread_recursive_mutex_t *__mutex) 
# 809
{ 
# 810
return __gthread_mutex_lock(__mutex); 
# 811
} 
# 814
static inline int __gthread_recursive_mutex_trylock(__gthread_recursive_mutex_t *__mutex) 
# 815
{ 
# 816
return __gthread_mutex_trylock(__mutex); 
# 817
} 
# 821
static inline int __gthread_recursive_mutex_timedlock(__gthread_recursive_mutex_t *__mutex, const __gthread_time_t *
# 822
__abs_timeout) 
# 823
{ 
# 824
return __gthread_mutex_timedlock(__mutex, __abs_timeout); 
# 825
} 
# 829
static inline int __gthread_recursive_mutex_unlock(__gthread_recursive_mutex_t *__mutex) 
# 830
{ 
# 831
return __gthread_mutex_unlock(__mutex); 
# 832
} 
# 835
static inline int __gthread_recursive_mutex_destroy(__gthread_recursive_mutex_t *__mutex) 
# 836
{ 
# 837
return __gthread_mutex_destroy(__mutex); 
# 838
} 
# 850
static inline int __gthread_cond_broadcast(__gthread_cond_t *__cond) 
# 851
{ 
# 852
return __gthrw_pthread_cond_broadcast(__cond); 
# 853
} 
# 856
static inline int __gthread_cond_signal(__gthread_cond_t *__cond) 
# 857
{ 
# 858
return __gthrw_pthread_cond_signal(__cond); 
# 859
} 
# 862
static inline int __gthread_cond_wait(__gthread_cond_t *__cond, __gthread_mutex_t *__mutex) 
# 863
{ 
# 864
return __gthrw_pthread_cond_wait(__cond, __mutex); 
# 865
} 
# 868
static inline int __gthread_cond_timedwait(__gthread_cond_t *__cond, __gthread_mutex_t *__mutex, const __gthread_time_t *
# 869
__abs_timeout) 
# 870
{ 
# 871
return __gthrw_pthread_cond_timedwait(__cond, __mutex, __abs_timeout); 
# 872
} 
# 875
static inline int __gthread_cond_wait_recursive(__gthread_cond_t *__cond, __gthread_recursive_mutex_t *
# 876
__mutex) 
# 877
{ 
# 878
return __gthread_cond_wait(__cond, __mutex); 
# 879
} 
# 882
static inline int __gthread_cond_destroy(__gthread_cond_t *__cond) 
# 883
{ 
# 884
return __gthrw_pthread_cond_destroy(__cond); 
# 885
} 
# 151 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/gthr.h" 3
#pragma GCC visibility pop
# 32 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/atomic_word.h" 3
typedef int _Atomic_word; 
# 38 "/usr/include/c++/4.8.2/ext/atomicity.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 48
static inline _Atomic_word __exchange_and_add(volatile _Atomic_word *__mem, int __val) 
# 49
{ return __atomic_fetch_add(__mem, __val, 4); } 
# 52
static inline void __atomic_add(volatile _Atomic_word *__mem, int __val) 
# 53
{ __atomic_fetch_add(__mem, __val, 4); } 
# 65
static inline _Atomic_word __exchange_and_add_single(_Atomic_word *__mem, int __val) 
# 66
{ 
# 67
_Atomic_word __result = *__mem; 
# 68
(*__mem) += __val; 
# 69
return __result; 
# 70
} 
# 73
static inline void __atomic_add_single(_Atomic_word *__mem, int __val) 
# 74
{ (*__mem) += __val; } 
# 77
__attribute((__unused__)) static inline _Atomic_word 
# 78
__exchange_and_add_dispatch(_Atomic_word *__mem, int __val) 
# 79
{ 
# 81
if (__gthread_active_p()) { 
# 82
return __exchange_and_add(__mem, __val); } else { 
# 84
return __exchange_and_add_single(__mem, __val); }  
# 88
} 
# 91
__attribute((__unused__)) static inline void 
# 92
__atomic_add_dispatch(_Atomic_word *__mem, int __val) 
# 93
{ 
# 95
if (__gthread_active_p()) { 
# 96
__atomic_add(__mem, __val); } else { 
# 98
__atomic_add_single(__mem, __val); }  
# 102
} 
# 105
}
# 42 "/usr/include/c++/4.8.2/new" 3
#pragma GCC visibility push ( default )
# 44
extern "C++" {
# 46
namespace std { 
# 54
class bad_alloc : public exception { 
# 57
public: bad_alloc() throw() { } 
# 61
virtual ~bad_alloc() throw(); 
# 64
virtual const char *what() const throw(); 
# 65
}; 
# 67
struct nothrow_t { }; 
# 69
extern const nothrow_t nothrow; 
# 73
typedef void (*new_handler)(void); 
# 77
new_handler set_new_handler(new_handler) throw(); 
# 78
}
# 91
void *operator new(std::size_t) throw(std::bad_alloc)
# 92
 __attribute((__externally_visible__)); 
# 93
void *operator new[](std::size_t) throw(std::bad_alloc)
# 94
 __attribute((__externally_visible__)); 
# 95
void operator delete(void *) throw()
# 96
 __attribute((__externally_visible__)); 
# 97
void operator delete[](void *) throw()
# 98
 __attribute((__externally_visible__)); 
# 99
void *operator new(std::size_t, const std::nothrow_t &) throw()
# 100
 __attribute((__externally_visible__)); 
# 101
void *operator new[](std::size_t, const std::nothrow_t &) throw()
# 102
 __attribute((__externally_visible__)); 
# 103
void operator delete(void *, const std::nothrow_t &) throw()
# 104
 __attribute((__externally_visible__)); 
# 105
void operator delete[](void *, const std::nothrow_t &) throw()
# 106
 __attribute((__externally_visible__)); 
# 109
inline void *operator new(std::size_t, void *__p) throw() 
# 110
{ return __p; } 
# 111
inline void *operator new[](std::size_t, void *__p) throw() 
# 112
{ return __p; } 
# 115
inline void operator delete(void *, void *) throw() { } 
# 116
inline void operator delete[](void *, void *) throw() { } 
# 118
}
# 120
#pragma GCC visibility pop
# 40 "/usr/include/c++/4.8.2/ext/new_allocator.h" 3
namespace __gnu_cxx __attribute((__visibility__("default"))) { 
# 44
using std::size_t;
# 45
using std::ptrdiff_t;
# 57
template< class _Tp> 
# 58
class new_allocator { 
# 61
public: typedef std::size_t size_type; 
# 62
typedef std::ptrdiff_t difference_type; 
# 63
typedef _Tp *pointer; 
# 64
typedef const _Tp *const_pointer; 
# 65
typedef _Tp &reference; 
# 66
typedef const _Tp &const_reference; 
# 67
typedef _Tp value_type; 
# 69
template< class _Tp1> 
# 70
struct rebind { 
# 71
typedef __gnu_cxx::new_allocator< _Tp1>  other; }; 
# 79
new_allocator() throw() { } 
# 81
new_allocator(const new_allocator &) throw() { } 
# 83
template< class _Tp1> 
# 84
new_allocator(const __gnu_cxx::new_allocator< _Tp1>  &) throw() { } 
# 86
~new_allocator() throw() { } 
# 89
pointer address(reference __x) const 
# 90
{ return std::__addressof(__x); } 
# 93
const_pointer address(const_reference __x) const 
# 94
{ return std::__addressof(__x); } 
# 99
pointer allocate(size_type __n, const void * = 0) 
# 100
{ 
# 101
if (__n > this->max_size()) { 
# 102
std::__throw_bad_alloc(); }  
# 104
return static_cast< _Tp *>(::operator new(__n * sizeof(_Tp))); 
# 105
} 
# 109
void deallocate(pointer __p, size_type) 
# 110
{ ::operator delete(__p); } 
# 113
size_type max_size() const throw() 
# 114
{ return ((std::size_t)(-1)) / sizeof(_Tp); } 
# 129
void construct(pointer __p, const _Tp &__val) 
# 130
{ ::new ((void *)__p) (_Tp)(__val); } 
# 133
void destroy(pointer __p) { (__p->~_Tp()); } 
# 135
}; 
# 137
template< class _Tp> inline bool 
# 139
operator==(const new_allocator< _Tp>  &, const new_allocator< _Tp>  &) 
# 140
{ return true; } 
# 142
template< class _Tp> inline bool 
# 144
operator!=(const new_allocator< _Tp>  &, const new_allocator< _Tp>  &) 
# 145
{ return false; } 
# 148
}
# 52 "/usr/include/c++/4.8.2/bits/allocator.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 63
template<> class allocator< void>  { 
# 66
public: typedef size_t size_type; 
# 67
typedef ptrdiff_t difference_type; 
# 68
typedef void *pointer; 
# 69
typedef const void *const_pointer; 
# 70
typedef void value_type; 
# 72
template< class _Tp1> 
# 73
struct rebind { 
# 74
typedef std::allocator< _Tp1>  other; }; 
# 81
}; 
# 91
template< class _Tp> 
# 92
class allocator : public __gnu_cxx::new_allocator< _Tp>  { 
# 95
public: typedef ::std::size_t size_type; 
# 96
typedef ::std::ptrdiff_t difference_type; 
# 97
typedef _Tp *pointer; 
# 98
typedef const _Tp *const_pointer; 
# 99
typedef _Tp &reference; 
# 100
typedef const _Tp &const_reference; 
# 101
typedef _Tp value_type; 
# 103
template< class _Tp1> 
# 104
struct rebind { 
# 105
typedef ::std::allocator< _Tp1>  other; }; 
# 113
allocator() throw() { } 
# 115
allocator(const allocator &__a) throw() : ::__gnu_cxx::new_allocator< _Tp> (__a) 
# 116
{ } 
# 118
template< class _Tp1> 
# 119
allocator(const ::std::allocator< _Tp1>  &) throw() { } 
# 121
~allocator() throw() { } 
# 124
}; 
# 126
template< class _T1, class _T2> inline bool 
# 128
operator==(const allocator< _T1>  &, const allocator< _T2>  &) 
# 129
{ return true; } 
# 131
template< class _Tp> inline bool 
# 133
operator==(const allocator< _Tp>  &, const allocator< _Tp>  &) 
# 134
{ return true; } 
# 136
template< class _T1, class _T2> inline bool 
# 138
operator!=(const allocator< _T1>  &, const allocator< _T2>  &) 
# 139
{ return false; } 
# 141
template< class _Tp> inline bool 
# 143
operator!=(const allocator< _Tp>  &, const allocator< _Tp>  &) 
# 144
{ return false; } 
# 151
extern template class allocator< char> ;
# 152
extern template class allocator< wchar_t> ;
# 159
template< class _Alloc, bool  = __is_empty(_Alloc)> 
# 160
struct __alloc_swap { 
# 161
static void _S_do_it(_Alloc &, _Alloc &) { } }; 
# 163
template< class _Alloc> 
# 164
struct __alloc_swap< _Alloc, false>  { 
# 167
static void _S_do_it(_Alloc &__one, _Alloc &__two) 
# 168
{ 
# 170
if (__one != __two) { 
# 171
swap(__one, __two); }  
# 172
} 
# 173
}; 
# 176
template< class _Alloc, bool  = __is_empty(_Alloc)> 
# 177
struct __alloc_neq { 
# 180
static bool _S_do_it(const _Alloc &, const _Alloc &) 
# 181
{ return false; } 
# 182
}; 
# 184
template< class _Alloc> 
# 185
struct __alloc_neq< _Alloc, false>  { 
# 188
static bool _S_do_it(const _Alloc &__one, const _Alloc &__two) 
# 189
{ return __one != __two; } 
# 190
}; 
# 219
}
# 36 "/usr/include/c++/4.8.2/bits/cxxabi_forced.h" 3
#pragma GCC visibility push ( default )
# 39
namespace __cxxabiv1 { 
# 48
class __forced_unwind { 
# 50
virtual ~__forced_unwind() throw(); 
# 53
virtual void __pure_dummy() = 0; 
# 54
}; 
# 55
}
# 58
#pragma GCC visibility pop
# 38 "/usr/include/c++/4.8.2/bits/ostream_insert.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 42
template< class _CharT, class _Traits> inline void 
# 44
__ostream_write(basic_ostream< _CharT, _Traits>  &__out, const _CharT *
# 45
__s, streamsize __n) 
# 46
{ 
# 47
typedef basic_ostream< _CharT, _Traits>  __ostream_type; 
# 48
typedef typename basic_ostream< _CharT, _Traits> ::ios_base __ios_base; 
# 50
const streamsize __put = ((__out.rdbuf())->sputn(__s, __n)); 
# 51
if (__put != __n) { 
# 52
(__out.setstate(__ios_base::badbit)); }  
# 53
} 
# 55
template< class _CharT, class _Traits> inline void 
# 57
__ostream_fill(basic_ostream< _CharT, _Traits>  &__out, streamsize __n) 
# 58
{ 
# 59
typedef basic_ostream< _CharT, _Traits>  __ostream_type; 
# 60
typedef typename basic_ostream< _CharT, _Traits> ::ios_base __ios_base; 
# 62
const _CharT __c = (__out.fill()); 
# 63
for (; __n > (0); --__n) 
# 64
{ 
# 65
const typename _Traits::int_type __put = ((__out.rdbuf())->sputc(__c)); 
# 66
if (_Traits::eq_int_type(__put, _Traits::eof())) 
# 67
{ 
# 68
(__out.setstate(__ios_base::badbit)); 
# 69
break; 
# 70
}  
# 71
}  
# 72
} 
# 74
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 76
__ostream_insert(basic_ostream< _CharT, _Traits>  &__out, const _CharT *
# 77
__s, streamsize __n) 
# 78
{ 
# 79
typedef basic_ostream< _CharT, _Traits>  __ostream_type; 
# 80
typedef typename basic_ostream< _CharT, _Traits> ::ios_base __ios_base; 
# 82
typename basic_ostream< _CharT, _Traits> ::sentry __cerb(__out); 
# 83
if (__cerb) 
# 84
{ 
# 85
try 
# 86
{ 
# 87
const streamsize __w = (__out.width()); 
# 88
if (__w > __n) 
# 89
{ 
# 90
const bool __left = ((__out.flags()) & __ios_base::adjustfield) == __ios_base::left; 
# 93
if (!__left) { 
# 94
__ostream_fill(__out, __w - __n); }  
# 95
if ((__out.good())) { 
# 96
__ostream_write(__out, __s, __n); }  
# 97
if (__left && (__out.good())) { 
# 98
__ostream_fill(__out, __w - __n); }  
# 99
} else { 
# 101
__ostream_write(__out, __s, __n); }  
# 102
(__out.width(0)); 
# 103
} 
# 104
catch (__cxxabiv1::__forced_unwind &) 
# 105
{ 
# 106
(__out._M_setstate(__ios_base::badbit)); 
# 107
throw; 
# 108
} 
# 109
catch (...) 
# 110
{ (__out._M_setstate(__ios_base::badbit)); }  
# 111
}  
# 112
return __out; 
# 113
} 
# 118
extern template basic_ostream< char>  &__ostream_insert(basic_ostream< char>  & __out, const char * __s, streamsize __n);
# 121
extern template basic_ostream< wchar_t>  &__ostream_insert(basic_ostream< wchar_t>  & __out, const wchar_t * __s, streamsize __n);
# 127
}
# 59 "/usr/include/c++/4.8.2/bits/stl_function.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 100
template< class _Arg, class _Result> 
# 101
struct unary_function { 
# 104
typedef _Arg argument_type; 
# 107
typedef _Result result_type; 
# 108
}; 
# 113
template< class _Arg1, class _Arg2, class _Result> 
# 114
struct binary_function { 
# 117
typedef _Arg1 first_argument_type; 
# 120
typedef _Arg2 second_argument_type; 
# 123
typedef _Result result_type; 
# 124
}; 
# 139
template< class _Tp> 
# 140
struct plus : public binary_function< _Tp, _Tp, _Tp>  { 
# 143
_Tp operator()(const _Tp &__x, const _Tp &__y) const 
# 144
{ return __x + __y; } 
# 145
}; 
# 148
template< class _Tp> 
# 149
struct minus : public binary_function< _Tp, _Tp, _Tp>  { 
# 152
_Tp operator()(const _Tp &__x, const _Tp &__y) const 
# 153
{ return __x - __y; } 
# 154
}; 
# 157
template< class _Tp> 
# 158
struct multiplies : public binary_function< _Tp, _Tp, _Tp>  { 
# 161
_Tp operator()(const _Tp &__x, const _Tp &__y) const 
# 162
{ return __x * __y; } 
# 163
}; 
# 166
template< class _Tp> 
# 167
struct divides : public binary_function< _Tp, _Tp, _Tp>  { 
# 170
_Tp operator()(const _Tp &__x, const _Tp &__y) const 
# 171
{ return __x / __y; } 
# 172
}; 
# 175
template< class _Tp> 
# 176
struct modulus : public binary_function< _Tp, _Tp, _Tp>  { 
# 179
_Tp operator()(const _Tp &__x, const _Tp &__y) const 
# 180
{ return __x % __y; } 
# 181
}; 
# 184
template< class _Tp> 
# 185
struct negate : public unary_function< _Tp, _Tp>  { 
# 188
_Tp operator()(const _Tp &__x) const 
# 189
{ return -__x; } 
# 190
}; 
# 203
template< class _Tp> 
# 204
struct equal_to : public binary_function< _Tp, _Tp, bool>  { 
# 207
bool operator()(const _Tp &__x, const _Tp &__y) const 
# 208
{ return __x == __y; } 
# 209
}; 
# 212
template< class _Tp> 
# 213
struct not_equal_to : public binary_function< _Tp, _Tp, bool>  { 
# 216
bool operator()(const _Tp &__x, const _Tp &__y) const 
# 217
{ return __x != __y; } 
# 218
}; 
# 221
template< class _Tp> 
# 222
struct greater : public binary_function< _Tp, _Tp, bool>  { 
# 225
bool operator()(const _Tp &__x, const _Tp &__y) const 
# 226
{ return __x > __y; } 
# 227
}; 
# 230
template< class _Tp> 
# 231
struct less : public binary_function< _Tp, _Tp, bool>  { 
# 234
bool operator()(const _Tp &__x, const _Tp &__y) const 
# 235
{ return __x < __y; } 
# 236
}; 
# 239
template< class _Tp> 
# 240
struct greater_equal : public binary_function< _Tp, _Tp, bool>  { 
# 243
bool operator()(const _Tp &__x, const _Tp &__y) const 
# 244
{ return __x >= __y; } 
# 245
}; 
# 248
template< class _Tp> 
# 249
struct less_equal : public binary_function< _Tp, _Tp, bool>  { 
# 252
bool operator()(const _Tp &__x, const _Tp &__y) const 
# 253
{ return __x <= __y; } 
# 254
}; 
# 267
template< class _Tp> 
# 268
struct logical_and : public binary_function< _Tp, _Tp, bool>  { 
# 271
bool operator()(const _Tp &__x, const _Tp &__y) const 
# 272
{ return __x && __y; } 
# 273
}; 
# 276
template< class _Tp> 
# 277
struct logical_or : public binary_function< _Tp, _Tp, bool>  { 
# 280
bool operator()(const _Tp &__x, const _Tp &__y) const 
# 281
{ return __x || __y; } 
# 282
}; 
# 285
template< class _Tp> 
# 286
struct logical_not : public unary_function< _Tp, bool>  { 
# 289
bool operator()(const _Tp &__x) const 
# 290
{ return !__x; } 
# 291
}; 
# 296
template< class _Tp> 
# 297
struct bit_and : public binary_function< _Tp, _Tp, _Tp>  { 
# 300
_Tp operator()(const _Tp &__x, const _Tp &__y) const 
# 301
{ return __x & __y; } 
# 302
}; 
# 304
template< class _Tp> 
# 305
struct bit_or : public binary_function< _Tp, _Tp, _Tp>  { 
# 308
_Tp operator()(const _Tp &__x, const _Tp &__y) const 
# 309
{ return __x | __y; } 
# 310
}; 
# 312
template< class _Tp> 
# 313
struct bit_xor : public binary_function< _Tp, _Tp, _Tp>  { 
# 316
_Tp operator()(const _Tp &__x, const _Tp &__y) const 
# 317
{ return __x ^ __y; } 
# 318
}; 
# 350
template< class _Predicate> 
# 351
class unary_negate : public unary_function< typename _Predicate::argument_type, bool>  { 
# 355
protected: _Predicate _M_pred; 
# 359
public: explicit unary_negate(const _Predicate &__x) : _M_pred(__x) { } 
# 362
bool operator()(const typename _Predicate::argument_type &__x) const 
# 363
{ return !(_M_pred)(__x); } 
# 364
}; 
# 367
template< class _Predicate> inline unary_negate< _Predicate>  
# 369
not1(const _Predicate &__pred) 
# 370
{ return ((unary_negate< _Predicate> )(__pred)); } 
# 373
template< class _Predicate> 
# 374
class binary_negate : public binary_function< typename _Predicate::first_argument_type, typename _Predicate::second_argument_type, bool>  { 
# 379
protected: _Predicate _M_pred; 
# 383
public: explicit binary_negate(const _Predicate &__x) : _M_pred(__x) { } 
# 386
bool operator()(const typename _Predicate::first_argument_type &__x, const typename _Predicate::second_argument_type &
# 387
__y) const 
# 388
{ return !(_M_pred)(__x, __y); } 
# 389
}; 
# 392
template< class _Predicate> inline binary_negate< _Predicate>  
# 394
not2(const _Predicate &__pred) 
# 395
{ return ((binary_negate< _Predicate> )(__pred)); } 
# 421
template< class _Arg, class _Result> 
# 422
class pointer_to_unary_function : public unary_function< _Arg, _Result>  { 
# 425
protected: _Result (*_M_ptr)(_Arg); 
# 428
public: pointer_to_unary_function() { } 
# 431
explicit pointer_to_unary_function(_Result (*__x)(_Arg)) : _M_ptr(__x) 
# 432
{ } 
# 435
_Result operator()(_Arg __x) const 
# 436
{ return (_M_ptr)(__x); } 
# 437
}; 
# 440
template< class _Arg, class _Result> inline pointer_to_unary_function< _Arg, _Result>  
# 442
ptr_fun(_Result (*__x)(_Arg)) 
# 443
{ return ((pointer_to_unary_function< _Arg, _Result> )(__x)); } 
# 446
template< class _Arg1, class _Arg2, class _Result> 
# 447
class pointer_to_binary_function : public binary_function< _Arg1, _Arg2, _Result>  { 
# 451
protected: _Result (*_M_ptr)(_Arg1, _Arg2); 
# 454
public: pointer_to_binary_function() { } 
# 457
explicit pointer_to_binary_function(_Result (*__x)(_Arg1, _Arg2)) : _M_ptr(__x) 
# 458
{ } 
# 461
_Result operator()(_Arg1 __x, _Arg2 __y) const 
# 462
{ return (_M_ptr)(__x, __y); } 
# 463
}; 
# 466
template< class _Arg1, class _Arg2, class _Result> inline pointer_to_binary_function< _Arg1, _Arg2, _Result>  
# 468
ptr_fun(_Result (*__x)(_Arg1, _Arg2)) 
# 469
{ return ((pointer_to_binary_function< _Arg1, _Arg2, _Result> )(__x)); } 
# 472
template< class _Tp> 
# 473
struct _Identity : public unary_function< _Tp, _Tp>  { 
# 477
_Tp &operator()(_Tp &__x) const 
# 478
{ return __x; } 
# 481
const _Tp &operator()(const _Tp &__x) const 
# 482
{ return __x; } 
# 483
}; 
# 485
template< class _Pair> 
# 486
struct _Select1st : public unary_function< _Pair, typename _Pair::first_type>  { 
# 490
typename _Pair::first_type &operator()(_Pair &__x) const 
# 491
{ return __x.first; } 
# 494
const typename _Pair::first_type &operator()(const _Pair &__x) const 
# 495
{ return __x.first; } 
# 508
}; 
# 510
template< class _Pair> 
# 511
struct _Select2nd : public unary_function< _Pair, typename _Pair::second_type>  { 
# 515
typename _Pair::second_type &operator()(_Pair &__x) const 
# 516
{ return __x.second; } 
# 519
const typename _Pair::second_type &operator()(const _Pair &__x) const 
# 520
{ return __x.second; } 
# 521
}; 
# 541
template< class _Ret, class _Tp> 
# 542
class mem_fun_t : public unary_function< _Tp *, _Ret>  { 
# 546
public: explicit mem_fun_t(_Ret (_Tp::*__pf)(void)) : _M_f(__pf) 
# 547
{ } 
# 550
_Ret operator()(_Tp *__p) const 
# 551
{ return (__p->*(_M_f))(); } 
# 554
private: _Ret (_Tp::*_M_f)(void); 
# 555
}; 
# 559
template< class _Ret, class _Tp> 
# 560
class const_mem_fun_t : public unary_function< const _Tp *, _Ret>  { 
# 564
public: explicit const_mem_fun_t(_Ret (_Tp::*__pf)(void) const) : _M_f(__pf) 
# 565
{ } 
# 568
_Ret operator()(const _Tp *__p) const 
# 569
{ return (__p->*(_M_f))(); } 
# 572
private: _Ret (_Tp::*_M_f)(void) const; 
# 573
}; 
# 577
template< class _Ret, class _Tp> 
# 578
class mem_fun_ref_t : public unary_function< _Tp, _Ret>  { 
# 582
public: explicit mem_fun_ref_t(_Ret (_Tp::*__pf)(void)) : _M_f(__pf) 
# 583
{ } 
# 586
_Ret operator()(_Tp &__r) const 
# 587
{ return (__r.*(_M_f))(); } 
# 590
private: _Ret (_Tp::*_M_f)(void); 
# 591
}; 
# 595
template< class _Ret, class _Tp> 
# 596
class const_mem_fun_ref_t : public unary_function< _Tp, _Ret>  { 
# 600
public: explicit const_mem_fun_ref_t(_Ret (_Tp::*__pf)(void) const) : _M_f(__pf) 
# 601
{ } 
# 604
_Ret operator()(const _Tp &__r) const 
# 605
{ return (__r.*(_M_f))(); } 
# 608
private: _Ret (_Tp::*_M_f)(void) const; 
# 609
}; 
# 613
template< class _Ret, class _Tp, class _Arg> 
# 614
class mem_fun1_t : public binary_function< _Tp *, _Arg, _Ret>  { 
# 618
public: explicit mem_fun1_t(_Ret (_Tp::*__pf)(_Arg)) : _M_f(__pf) 
# 619
{ } 
# 622
_Ret operator()(_Tp *__p, _Arg __x) const 
# 623
{ return (__p->*(_M_f))(__x); } 
# 626
private: _Ret (_Tp::*_M_f)(_Arg); 
# 627
}; 
# 631
template< class _Ret, class _Tp, class _Arg> 
# 632
class const_mem_fun1_t : public binary_function< const _Tp *, _Arg, _Ret>  { 
# 636
public: explicit const_mem_fun1_t(_Ret (_Tp::*__pf)(_Arg) const) : _M_f(__pf) 
# 637
{ } 
# 640
_Ret operator()(const _Tp *__p, _Arg __x) const 
# 641
{ return (__p->*(_M_f))(__x); } 
# 644
private: _Ret (_Tp::*_M_f)(_Arg) const; 
# 645
}; 
# 649
template< class _Ret, class _Tp, class _Arg> 
# 650
class mem_fun1_ref_t : public binary_function< _Tp, _Arg, _Ret>  { 
# 654
public: explicit mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg)) : _M_f(__pf) 
# 655
{ } 
# 658
_Ret operator()(_Tp &__r, _Arg __x) const 
# 659
{ return (__r.*(_M_f))(__x); } 
# 662
private: _Ret (_Tp::*_M_f)(_Arg); 
# 663
}; 
# 667
template< class _Ret, class _Tp, class _Arg> 
# 668
class const_mem_fun1_ref_t : public binary_function< _Tp, _Arg, _Ret>  { 
# 672
public: explicit const_mem_fun1_ref_t(_Ret (_Tp::*__pf)(_Arg) const) : _M_f(__pf) 
# 673
{ } 
# 676
_Ret operator()(const _Tp &__r, _Arg __x) const 
# 677
{ return (__r.*(_M_f))(__x); } 
# 680
private: _Ret (_Tp::*_M_f)(_Arg) const; 
# 681
}; 
# 685
template< class _Ret, class _Tp> inline mem_fun_t< _Ret, _Tp>  
# 687
mem_fun(_Ret (_Tp::*__f)(void)) 
# 688
{ return ((mem_fun_t< _Ret, _Tp> )(__f)); } 
# 690
template< class _Ret, class _Tp> inline const_mem_fun_t< _Ret, _Tp>  
# 692
mem_fun(_Ret (_Tp::*__f)(void) const) 
# 693
{ return ((const_mem_fun_t< _Ret, _Tp> )(__f)); } 
# 695
template< class _Ret, class _Tp> inline mem_fun_ref_t< _Ret, _Tp>  
# 697
mem_fun_ref(_Ret (_Tp::*__f)(void)) 
# 698
{ return ((mem_fun_ref_t< _Ret, _Tp> )(__f)); } 
# 700
template< class _Ret, class _Tp> inline const_mem_fun_ref_t< _Ret, _Tp>  
# 702
mem_fun_ref(_Ret (_Tp::*__f)(void) const) 
# 703
{ return ((const_mem_fun_ref_t< _Ret, _Tp> )(__f)); } 
# 705
template< class _Ret, class _Tp, class _Arg> inline mem_fun1_t< _Ret, _Tp, _Arg>  
# 707
mem_fun(_Ret (_Tp::*__f)(_Arg)) 
# 708
{ return ((mem_fun1_t< _Ret, _Tp, _Arg> )(__f)); } 
# 710
template< class _Ret, class _Tp, class _Arg> inline const_mem_fun1_t< _Ret, _Tp, _Arg>  
# 712
mem_fun(_Ret (_Tp::*__f)(_Arg) const) 
# 713
{ return ((const_mem_fun1_t< _Ret, _Tp, _Arg> )(__f)); } 
# 715
template< class _Ret, class _Tp, class _Arg> inline mem_fun1_ref_t< _Ret, _Tp, _Arg>  
# 717
mem_fun_ref(_Ret (_Tp::*__f)(_Arg)) 
# 718
{ return ((mem_fun1_ref_t< _Ret, _Tp, _Arg> )(__f)); } 
# 720
template< class _Ret, class _Tp, class _Arg> inline const_mem_fun1_ref_t< _Ret, _Tp, _Arg>  
# 722
mem_fun_ref(_Ret (_Tp::*__f)(_Arg) const) 
# 723
{ return ((const_mem_fun1_ref_t< _Ret, _Tp, _Arg> )(__f)); } 
# 728
}
# 59 "/usr/include/c++/4.8.2/backward/binders.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 103
template< class _Operation> 
# 104
class binder1st : public unary_function< typename _Operation::second_argument_type, typename _Operation::result_type>  { 
# 109
protected: _Operation op; 
# 110
typename _Operation::first_argument_type value; 
# 113
public: binder1st(const _Operation &__x, const typename _Operation::first_argument_type &
# 114
__y) : op(__x), value(__y) 
# 115
{ } 
# 118
typename _Operation::result_type operator()(const typename _Operation::second_argument_type &__x) const 
# 119
{ return (op)(value, __x); } 
# 124
typename _Operation::result_type operator()(typename _Operation::second_argument_type &__x) const 
# 125
{ return (op)(value, __x); } 
# 126
}; 
# 129
template< class _Operation, class _Tp> inline binder1st< _Operation>  
# 131
bind1st(const _Operation &__fn, const _Tp &__x) 
# 132
{ 
# 133
typedef typename _Operation::first_argument_type _Arg1_type; 
# 134
return binder1st< _Operation> (__fn, (_Arg1_type)__x); 
# 135
} 
# 138
template< class _Operation> 
# 139
class binder2nd : public unary_function< typename _Operation::first_argument_type, typename _Operation::result_type>  { 
# 144
protected: _Operation op; 
# 145
typename _Operation::second_argument_type value; 
# 148
public: binder2nd(const _Operation &__x, const typename _Operation::second_argument_type &
# 149
__y) : op(__x), value(__y) 
# 150
{ } 
# 153
typename _Operation::result_type operator()(const typename _Operation::first_argument_type &__x) const 
# 154
{ return (op)(__x, value); } 
# 159
typename _Operation::result_type operator()(typename _Operation::first_argument_type &__x) const 
# 160
{ return (op)(__x, value); } 
# 161
}; 
# 164
template< class _Operation, class _Tp> inline binder2nd< _Operation>  
# 166
bind2nd(const _Operation &__fn, const _Tp &__x) 
# 167
{ 
# 168
typedef typename _Operation::second_argument_type _Arg2_type; 
# 169
return binder2nd< _Operation> (__fn, (_Arg2_type)__x); 
# 170
} 
# 174
}
# 45 "/usr/include/c++/4.8.2/bits/basic_string.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 111
template< class _CharT, class _Traits, class _Alloc> 
# 112
class basic_string { 
# 114
typedef typename _Alloc::template rebind< _CharT> ::other _CharT_alloc_type; 
# 118
public: typedef _Traits traits_type; 
# 119
typedef typename _Traits::char_type value_type; 
# 120
typedef _Alloc allocator_type; 
# 121
typedef typename _Alloc::template rebind< _CharT> ::other::size_type size_type; 
# 122
typedef typename _Alloc::template rebind< _CharT> ::other::difference_type difference_type; 
# 123
typedef typename _Alloc::template rebind< _CharT> ::other::reference reference; 
# 124
typedef typename _Alloc::template rebind< _CharT> ::other::const_reference const_reference; 
# 125
typedef typename _Alloc::template rebind< _CharT> ::other::pointer pointer; 
# 126
typedef typename _Alloc::template rebind< _CharT> ::other::const_pointer const_pointer; 
# 127
typedef __gnu_cxx::__normal_iterator< typename _Alloc::template rebind< _CharT> ::other::pointer, basic_string>  iterator; 
# 129
typedef __gnu_cxx::__normal_iterator< typename _Alloc::template rebind< _CharT> ::other::const_pointer, basic_string>  const_iterator; 
# 130
typedef std::reverse_iterator< __gnu_cxx::__normal_iterator< typename _Alloc::template rebind< _CharT> ::other::const_pointer, basic_string> >  const_reverse_iterator; 
# 131
typedef std::reverse_iterator< __gnu_cxx::__normal_iterator< typename _Alloc::template rebind< _CharT> ::other::pointer, basic_string> >  reverse_iterator; 
# 148
private: struct _Rep_base { 
# 150
size_type _M_length; 
# 151
size_type _M_capacity; 
# 152
_Atomic_word _M_refcount; 
# 153
}; 
# 155
struct _Rep : public _Rep_base { 
# 158
typedef typename _Alloc::template rebind< char> ::other _Raw_bytes_alloc; 
# 173
static const typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type _S_max_size; 
# 174
static const _CharT _S_terminal; 
# 178
static typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type _S_empty_rep_storage[]; 
# 181
static _Rep &_S_empty_rep() 
# 182
{ 
# 186
void *__p = (reinterpret_cast< void *>(&_S_empty_rep_storage)); 
# 187
return *(reinterpret_cast< _Rep *>(__p)); 
# 188
} 
# 191
bool _M_is_leaked() const 
# 192
{ return (this->_M_refcount) < 0; } 
# 195
bool _M_is_shared() const 
# 196
{ return (this->_M_refcount) > 0; } 
# 199
void _M_set_leaked() 
# 200
{ (this->_M_refcount) = (-1); } 
# 203
void _M_set_sharable() 
# 204
{ (this->_M_refcount) = 0; } 
# 207
void _M_set_length_and_sharable(typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __n) 
# 208
{ 
# 210
if (__builtin_expect(this != (&(_S_empty_rep)()), false)) 
# 212
{ 
# 213
this->_M_set_sharable(); 
# 214
(this->_M_length) = __n; 
# 215
traits_type::assign(this->_M_refdata()[__n], _S_terminal); 
# 218
}  
# 219
} 
# 222
_CharT *_M_refdata() throw() 
# 223
{ return reinterpret_cast< _CharT *>(this + 1); } 
# 226
_CharT *_M_grab(const _Alloc &__alloc1, const _Alloc &__alloc2) 
# 227
{ 
# 228
return ((!_M_is_leaked()) && (__alloc1 == __alloc2)) ? _M_refcopy() : _M_clone(__alloc1); 
# 230
} 
# 234
static _Rep *_S_create(typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type, typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type, const _Alloc &); 
# 237
void _M_dispose(const _Alloc &__a) 
# 238
{ 
# 240
if (__builtin_expect(this != (&(_S_empty_rep)()), false)) 
# 242
{ 
# 244
; 
# 245
if (::__gnu_cxx::__exchange_and_add_dispatch(&(this->_M_refcount), -1) <= 0) 
# 247
{ 
# 248
; 
# 249
_M_destroy(__a); 
# 250
}  
# 251
}  
# 252
} 
# 255
void _M_destroy(const _Alloc &) throw(); 
# 258
_CharT *_M_refcopy() throw() 
# 259
{ 
# 261
if (__builtin_expect(this != (&(_S_empty_rep)()), false)) { 
# 263
::__gnu_cxx::__atomic_add_dispatch(&(this->_M_refcount), 1); }  
# 264
return _M_refdata(); 
# 265
} 
# 268
_CharT *_M_clone(const _Alloc &, typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __res = 0); 
# 269
}; 
# 272
struct _Alloc_hider : public _Alloc { 
# 274
_Alloc_hider(_CharT *__dat, const _Alloc &__a) : _Alloc(__a), _M_p(__dat) 
# 275
{ } 
# 277
_CharT *_M_p; 
# 278
}; 
# 285
public: static const size_type npos = (static_cast< size_type>(-1)); 
# 289
private: mutable _Alloc_hider _M_dataplus; 
# 292
_CharT *_M_data() const 
# 293
{ return (_M_dataplus)._M_p; } 
# 296
_CharT *_M_data(_CharT *__p) 
# 297
{ return ((_M_dataplus)._M_p) = __p; } 
# 300
_Rep *_M_rep() const 
# 301
{ return &((reinterpret_cast< _Rep *>(_M_data()))[-1]); } 
# 306
iterator _M_ibegin() const 
# 307
{ return ((iterator)(_M_data())); } 
# 310
iterator _M_iend() const 
# 311
{ return ((iterator)(_M_data() + this->size())); } 
# 314
void _M_leak() 
# 315
{ 
# 316
if (!(_M_rep()->_M_is_leaked())) { 
# 317
_M_leak_hard(); }  
# 318
} 
# 321
size_type _M_check(size_type __pos, const char *__s) const 
# 322
{ 
# 323
if (__pos > this->size()) { 
# 324
__throw_out_of_range(__s); }  
# 325
return __pos; 
# 326
} 
# 329
void _M_check_length(size_type __n1, size_type __n2, const char *__s) const 
# 330
{ 
# 331
if ((this->max_size() - (this->size() - __n1)) < __n2) { 
# 332
__throw_length_error(__s); }  
# 333
} 
# 337
size_type _M_limit(size_type __pos, size_type __off) const 
# 338
{ 
# 339
const bool __testoff = __off < (this->size() - __pos); 
# 340
return __testoff ? __off : (this->size() - __pos); 
# 341
} 
# 345
bool _M_disjunct(const _CharT *__s) const 
# 346
{ 
# 347
return less< const _CharT *> ()(__s, _M_data()) || less< const _CharT *> ()(_M_data() + this->size(), __s); 
# 349
} 
# 354
static void _M_copy(_CharT *__d, const _CharT *__s, size_type __n) 
# 355
{ 
# 356
if (__n == 1) { 
# 357
traits_type::assign(*__d, *__s); } else { 
# 359
traits_type::copy(__d, __s, __n); }  
# 360
} 
# 363
static void _M_move(_CharT *__d, const _CharT *__s, size_type __n) 
# 364
{ 
# 365
if (__n == 1) { 
# 366
traits_type::assign(*__d, *__s); } else { 
# 368
traits_type::move(__d, __s, __n); }  
# 369
} 
# 372
static void _M_assign(_CharT *__d, size_type __n, _CharT __c) 
# 373
{ 
# 374
if (__n == 1) { 
# 375
traits_type::assign(*__d, __c); } else { 
# 377
traits_type::assign(__d, __n, __c); }  
# 378
} 
# 382
template< class _Iterator> static void 
# 384
_S_copy_chars(_CharT *__p, _Iterator __k1, _Iterator __k2) 
# 385
{ 
# 386
for (; __k1 != __k2; (++__k1), (++__p)) { 
# 387
traits_type::assign(*__p, *__k1); }  
# 388
} 
# 391
static void _S_copy_chars(_CharT *__p, iterator __k1, iterator __k2) 
# 392
{ _S_copy_chars(__p, (__k1.base()), (__k2.base())); } 
# 395
static void _S_copy_chars(_CharT *__p, const_iterator __k1, const_iterator __k2) 
# 396
{ _S_copy_chars(__p, (__k1.base()), (__k2.base())); } 
# 399
static void _S_copy_chars(_CharT *__p, _CharT *__k1, _CharT *__k2) 
# 400
{ (_M_copy)(__p, __k1, __k2 - __k1); } 
# 403
static void _S_copy_chars(_CharT *__p, const _CharT *__k1, const _CharT *__k2) 
# 404
{ (_M_copy)(__p, __k1, __k2 - __k1); } 
# 407
static int _S_compare(size_type __n1, size_type __n2) 
# 408
{ 
# 409
const difference_type __d = (difference_type)(__n1 - __n2); 
# 411
if (__d > __gnu_cxx::__numeric_traits< int> ::__max) { 
# 412
return __gnu_cxx::__numeric_traits_integer< int> ::__max; } else { 
# 413
if (__d < __gnu_cxx::__numeric_traits< int> ::__min) { 
# 414
return __gnu_cxx::__numeric_traits_integer< int> ::__min; } else { 
# 416
return (int)__d; }  }  
# 417
} 
# 420
void _M_mutate(size_type __pos, size_type __len1, size_type __len2); 
# 423
void _M_leak_hard(); 
# 426
static _Rep &_S_empty_rep() 
# 427
{ return _Rep::_S_empty_rep(); } 
# 437
public: basic_string() : _M_dataplus(((_S_empty_rep)()._M_refdata()), _Alloc()) 
# 439
{ } 
# 448
explicit basic_string(const _Alloc & __a); 
# 455
basic_string(const basic_string & __str); 
# 462
basic_string(const basic_string & __str, size_type __pos, size_type __n = npos); 
# 471
basic_string(const basic_string & __str, size_type __pos, size_type __n, const _Alloc & __a); 
# 483
basic_string(const _CharT * __s, size_type __n, const _Alloc & __a = _Alloc()); 
# 490
basic_string(const _CharT * __s, const _Alloc & __a = _Alloc()); 
# 497
basic_string(size_type __n, _CharT __c, const _Alloc & __a = _Alloc()); 
# 531
template< class _InputIterator> basic_string(_InputIterator __beg, _InputIterator __end, const _Alloc & __a = _Alloc()); 
# 538
~basic_string() 
# 539
{ (_M_rep()->_M_dispose(this->get_allocator())); } 
# 546
basic_string &operator=(const basic_string &__str) 
# 547
{ return (this->assign(__str)); } 
# 554
basic_string &operator=(const _CharT *__s) 
# 555
{ return (this->assign(__s)); } 
# 565
basic_string &operator=(_CharT __c) 
# 566
{ 
# 567
(this->assign(1, __c)); 
# 568
return *this; 
# 569
} 
# 605
iterator begin() 
# 606
{ 
# 607
_M_leak(); 
# 608
return ((iterator)(_M_data())); 
# 609
} 
# 616
const_iterator begin() const 
# 617
{ return ((const_iterator)(_M_data())); } 
# 624
iterator end() 
# 625
{ 
# 626
_M_leak(); 
# 627
return ((iterator)(_M_data() + this->size())); 
# 628
} 
# 635
const_iterator end() const 
# 636
{ return ((const_iterator)(_M_data() + this->size())); } 
# 644
reverse_iterator rbegin() 
# 645
{ return ((reverse_iterator)(this->end())); } 
# 653
const_reverse_iterator rbegin() const 
# 654
{ return ((const_reverse_iterator)(this->end())); } 
# 662
reverse_iterator rend() 
# 663
{ return ((reverse_iterator)(this->begin())); } 
# 671
const_reverse_iterator rend() const 
# 672
{ return ((const_reverse_iterator)(this->begin())); } 
# 715
size_type size() const 
# 716
{ return _M_rep()->_M_length; } 
# 721
size_type length() const 
# 722
{ return _M_rep()->_M_length; } 
# 726
size_type max_size() const 
# 727
{ return _Rep::_S_max_size; } 
# 740
void resize(size_type __n, _CharT __c); 
# 753
void resize(size_type __n) 
# 754
{ (this->resize(__n, _CharT())); } 
# 776
size_type capacity() const 
# 777
{ return _M_rep()->_M_capacity; } 
# 797
void reserve(size_type __res_arg = 0); 
# 803
void clear() 
# 804
{ _M_mutate(0, this->size(), 0); } 
# 811
bool empty() const 
# 812
{ return this->size() == 0; } 
# 826
const_reference operator[](size_type __pos) const 
# 827
{ 
# 828
; 
# 829
return _M_data()[__pos]; 
# 830
} 
# 843
reference operator[](size_type __pos) 
# 844
{ 
# 846
; 
# 848
; 
# 849
_M_leak(); 
# 850
return _M_data()[__pos]; 
# 851
} 
# 864
const_reference at(size_type __n) const 
# 865
{ 
# 866
if (__n >= this->size()) { 
# 867
__throw_out_of_range("basic_string::at"); }  
# 868
return _M_data()[__n]; 
# 869
} 
# 883
reference at(size_type __n) 
# 884
{ 
# 885
if (__n >= size()) { 
# 886
__throw_out_of_range("basic_string::at"); }  
# 887
_M_leak(); 
# 888
return _M_data()[__n]; 
# 889
} 
# 932
basic_string &operator+=(const basic_string &__str) 
# 933
{ return (this->append(__str)); } 
# 941
basic_string &operator+=(const _CharT *__s) 
# 942
{ return (this->append(__s)); } 
# 950
basic_string &operator+=(_CharT __c) 
# 951
{ 
# 952
this->push_back(__c); 
# 953
return *this; 
# 954
} 
# 973
basic_string &append(const basic_string & __str); 
# 989
basic_string &append(const basic_string & __str, size_type __pos, size_type __n); 
# 998
basic_string &append(const _CharT * __s, size_type __n); 
# 1006
basic_string &append(const _CharT *__s) 
# 1007
{ 
# 1008
; 
# 1009
return (this->append(__s, traits_type::length(__s))); 
# 1010
} 
# 1021
basic_string &append(size_type __n, _CharT __c); 
# 1042
template< class _InputIterator> basic_string &
# 1044
append(_InputIterator __first, _InputIterator __last) 
# 1045
{ return (this->replace(_M_iend(), _M_iend(), __first, __last)); } 
# 1052
void push_back(_CharT __c) 
# 1053
{ 
# 1054
const size_type __len = 1 + this->size(); 
# 1055
if ((__len > this->capacity()) || (_M_rep()->_M_is_shared())) { 
# 1056
this->reserve(__len); }  
# 1057
traits_type::assign(_M_data()[this->size()], __c); 
# 1058
(_M_rep()->_M_set_length_and_sharable(__len)); 
# 1059
} 
# 1067
basic_string &assign(const basic_string & __str); 
# 1100
basic_string &assign(const basic_string &__str, size_type __pos, size_type __n) 
# 1101
{ return (this->assign((__str._M_data()) + __str._M_check(__pos, "basic_string::assign"), __str._M_limit(__pos, __n))); 
# 1103
} 
# 1116
basic_string &assign(const _CharT * __s, size_type __n); 
# 1128
basic_string &assign(const _CharT *__s) 
# 1129
{ 
# 1130
; 
# 1131
return (this->assign(__s, traits_type::length(__s))); 
# 1132
} 
# 1144
basic_string &assign(size_type __n, _CharT __c) 
# 1145
{ return _M_replace_aux((size_type)0, this->size(), __n, __c); } 
# 1155
template< class _InputIterator> basic_string &
# 1157
assign(_InputIterator __first, _InputIterator __last) 
# 1158
{ return (this->replace(_M_ibegin(), _M_iend(), __first, __last)); } 
# 1185
void insert(iterator __p, size_type __n, _CharT __c) 
# 1186
{ (this->replace(__p, __p, __n, __c)); } 
# 1200
template< class _InputIterator> void 
# 1202
insert(iterator __p, _InputIterator __beg, _InputIterator __end) 
# 1203
{ (this->replace(__p, __p, __beg, __end)); } 
# 1233
basic_string &insert(size_type __pos1, const basic_string &__str) 
# 1234
{ return (this->insert(__pos1, __str, (size_type)0, __str.size())); } 
# 1255
basic_string &insert(size_type __pos1, const basic_string &__str, size_type 
# 1256
__pos2, size_type __n) 
# 1257
{ return (this->insert(__pos1, (__str._M_data()) + __str._M_check(__pos2, "basic_string::insert"), __str._M_limit(__pos2, __n))); 
# 1259
} 
# 1278
basic_string &insert(size_type __pos, const _CharT * __s, size_type __n); 
# 1296
basic_string &insert(size_type __pos, const _CharT *__s) 
# 1297
{ 
# 1298
; 
# 1299
return (this->insert(__pos, __s, traits_type::length(__s))); 
# 1300
} 
# 1319
basic_string &insert(size_type __pos, size_type __n, _CharT __c) 
# 1320
{ return _M_replace_aux(_M_check(__pos, "basic_string::insert"), (size_type)0, __n, __c); 
# 1321
} 
# 1337
iterator insert(iterator __p, _CharT __c) 
# 1338
{ 
# 1339
; 
# 1340
const size_type __pos = __p - _M_ibegin(); 
# 1341
_M_replace_aux(__pos, (size_type)0, (size_type)1, __c); 
# 1342
(_M_rep()->_M_set_leaked()); 
# 1343
return ((iterator)(_M_data() + __pos)); 
# 1344
} 
# 1362
basic_string &erase(size_type __pos = 0, size_type __n = npos) 
# 1363
{ 
# 1364
_M_mutate(_M_check(__pos, "basic_string::erase"), _M_limit(__pos, __n), (size_type)0); 
# 1366
return *this; 
# 1367
} 
# 1378
iterator erase(iterator __position) 
# 1379
{ 
# 1381
; 
# 1382
const size_type __pos = __position - _M_ibegin(); 
# 1383
_M_mutate(__pos, (size_type)1, (size_type)0); 
# 1384
(_M_rep()->_M_set_leaked()); 
# 1385
return ((iterator)(_M_data() + __pos)); 
# 1386
} 
# 1398
iterator erase(iterator __first, iterator __last); 
# 1429
basic_string &replace(size_type __pos, size_type __n, const basic_string &__str) 
# 1430
{ return (this->replace(__pos, __n, (__str._M_data()), __str.size())); } 
# 1451
basic_string &replace(size_type __pos1, size_type __n1, const basic_string &__str, size_type 
# 1452
__pos2, size_type __n2) 
# 1453
{ return (this->replace(__pos1, __n1, (__str._M_data()) + __str._M_check(__pos2, "basic_string::replace"), __str._M_limit(__pos2, __n2))); 
# 1455
} 
# 1476
basic_string &replace(size_type __pos, size_type __n1, const _CharT * __s, size_type __n2); 
# 1496
basic_string &replace(size_type __pos, size_type __n1, const _CharT *__s) 
# 1497
{ 
# 1498
; 
# 1499
return (this->replace(__pos, __n1, __s, traits_type::length(__s))); 
# 1500
} 
# 1520
basic_string &replace(size_type __pos, size_type __n1, size_type __n2, _CharT __c) 
# 1521
{ return _M_replace_aux(_M_check(__pos, "basic_string::replace"), _M_limit(__pos, __n1), __n2, __c); 
# 1522
} 
# 1538
basic_string &replace(iterator __i1, iterator __i2, const basic_string &__str) 
# 1539
{ return (this->replace(__i1, __i2, (__str._M_data()), __str.size())); } 
# 1557
basic_string &replace(iterator __i1, iterator __i2, const _CharT *__s, size_type __n) 
# 1558
{ 
# 1560
; 
# 1561
return (this->replace(__i1 - _M_ibegin(), __i2 - __i1, __s, __n)); 
# 1562
} 
# 1578
basic_string &replace(iterator __i1, iterator __i2, const _CharT *__s) 
# 1579
{ 
# 1580
; 
# 1581
return (this->replace(__i1, __i2, __s, traits_type::length(__s))); 
# 1582
} 
# 1599
basic_string &replace(iterator __i1, iterator __i2, size_type __n, _CharT __c) 
# 1600
{ 
# 1602
; 
# 1603
return _M_replace_aux(__i1 - _M_ibegin(), __i2 - __i1, __n, __c); 
# 1604
} 
# 1621
template< class _InputIterator> basic_string &
# 1623
replace(iterator __i1, iterator __i2, _InputIterator 
# 1624
__k1, _InputIterator __k2) 
# 1625
{ 
# 1627
; 
# 1628
; 
# 1629
typedef typename __is_integer< _InputIterator> ::__type _Integral; 
# 1630
return _M_replace_dispatch(__i1, __i2, __k1, __k2, _Integral()); 
# 1631
} 
# 1636
basic_string &replace(iterator __i1, iterator __i2, _CharT *__k1, _CharT *__k2) 
# 1637
{ 
# 1639
; 
# 1640
; 
# 1641
return (this->replace(__i1 - _M_ibegin(), __i2 - __i1, __k1, __k2 - __k1)); 
# 1643
} 
# 1646
basic_string &replace(iterator __i1, iterator __i2, const _CharT *
# 1647
__k1, const _CharT *__k2) 
# 1648
{ 
# 1650
; 
# 1651
; 
# 1652
return (this->replace(__i1 - _M_ibegin(), __i2 - __i1, __k1, __k2 - __k1)); 
# 1654
} 
# 1657
basic_string &replace(iterator __i1, iterator __i2, iterator __k1, iterator __k2) 
# 1658
{ 
# 1660
; 
# 1661
; 
# 1662
return (this->replace(__i1 - _M_ibegin(), __i2 - __i1, (__k1.base()), __k2 - __k1)); 
# 1664
} 
# 1667
basic_string &replace(iterator __i1, iterator __i2, const_iterator 
# 1668
__k1, const_iterator __k2) 
# 1669
{ 
# 1671
; 
# 1672
; 
# 1673
return (this->replace(__i1 - _M_ibegin(), __i2 - __i1, (__k1.base()), __k2 - __k1)); 
# 1675
} 
# 1700
private: 
# 1698
template< class _Integer> basic_string &
# 1700
_M_replace_dispatch(iterator __i1, iterator __i2, _Integer __n, _Integer 
# 1701
__val, __true_type) 
# 1702
{ return _M_replace_aux(__i1 - _M_ibegin(), __i2 - __i1, __n, __val); } 
# 1704
template< class _InputIterator> basic_string &_M_replace_dispatch(iterator __i1, iterator __i2, _InputIterator __k1, _InputIterator __k2, __false_type); 
# 1710
basic_string &_M_replace_aux(size_type __pos1, size_type __n1, size_type __n2, _CharT __c); 
# 1714
basic_string &_M_replace_safe(size_type __pos1, size_type __n1, const _CharT * __s, size_type __n2); 
# 1719
template< class _InIterator> static _CharT *
# 1721
_S_construct_aux(_InIterator __beg, _InIterator __end, const _Alloc &
# 1722
__a, __false_type) 
# 1723
{ 
# 1724
typedef typename iterator_traits< _InIterator> ::iterator_category _Tag; 
# 1725
return _S_construct(__beg, __end, __a, _Tag()); 
# 1726
} 
# 1730
template< class _Integer> static _CharT *
# 1732
_S_construct_aux(_Integer __beg, _Integer __end, const _Alloc &
# 1733
__a, __true_type) 
# 1734
{ return (_S_construct_aux_2)(static_cast< size_type>(__beg), __end, __a); 
# 1735
} 
# 1738
static _CharT *_S_construct_aux_2(size_type __req, _CharT __c, const _Alloc &__a) 
# 1739
{ return _S_construct(__req, __c, __a); } 
# 1741
template< class _InIterator> static _CharT *
# 1743
_S_construct(_InIterator __beg, _InIterator __end, const _Alloc &__a) 
# 1744
{ 
# 1745
typedef typename __is_integer< _InIterator> ::__type _Integral; 
# 1746
return _S_construct_aux(__beg, __end, __a, _Integral()); 
# 1747
} 
# 1750
template< class _InIterator> static _CharT *_S_construct(_InIterator __beg, _InIterator __end, const _Alloc & __a, input_iterator_tag); 
# 1757
template< class _FwdIterator> static _CharT *_S_construct(_FwdIterator __beg, _FwdIterator __end, const _Alloc & __a, forward_iterator_tag); 
# 1763
static _CharT *_S_construct(size_type __req, _CharT __c, const _Alloc & __a); 
# 1780
public: size_type copy(_CharT * __s, size_type __n, size_type __pos = 0) const; 
# 1790
void swap(basic_string & __s); 
# 1800
const _CharT *c_str() const 
# 1801
{ return _M_data(); } 
# 1810
const _CharT *data() const 
# 1811
{ return _M_data(); } 
# 1817
allocator_type get_allocator() const 
# 1818
{ return _M_dataplus; } 
# 1833
size_type find(const _CharT * __s, size_type __pos, size_type __n) const; 
# 1846
size_type find(const basic_string &__str, size_type __pos = 0) const 
# 1848
{ return (this->find(__str.data(), __pos, __str.size())); } 
# 1861
size_type find(const _CharT *__s, size_type __pos = 0) const 
# 1862
{ 
# 1863
; 
# 1864
return (this->find(__s, __pos, traits_type::length(__s))); 
# 1865
} 
# 1878
size_type find(_CharT __c, size_type __pos = 0) const; 
# 1891
size_type rfind(const basic_string &__str, size_type __pos = npos) const 
# 1893
{ return (this->rfind(__str.data(), __pos, __str.size())); } 
# 1908
size_type rfind(const _CharT * __s, size_type __pos, size_type __n) const; 
# 1921
size_type rfind(const _CharT *__s, size_type __pos = npos) const 
# 1922
{ 
# 1923
; 
# 1924
return (this->rfind(__s, __pos, traits_type::length(__s))); 
# 1925
} 
# 1938
size_type rfind(_CharT __c, size_type __pos = npos) const; 
# 1952
size_type find_first_of(const basic_string &__str, size_type __pos = 0) const 
# 1954
{ return (this->find_first_of(__str.data(), __pos, __str.size())); } 
# 1969
size_type find_first_of(const _CharT * __s, size_type __pos, size_type __n) const; 
# 1982
size_type find_first_of(const _CharT *__s, size_type __pos = 0) const 
# 1983
{ 
# 1984
; 
# 1985
return (this->find_first_of(__s, __pos, traits_type::length(__s))); 
# 1986
} 
# 2001
size_type find_first_of(_CharT __c, size_type __pos = 0) const 
# 2002
{ return (this->find(__c, __pos)); } 
# 2016
size_type find_last_of(const basic_string &__str, size_type __pos = npos) const 
# 2018
{ return (this->find_last_of(__str.data(), __pos, __str.size())); } 
# 2033
size_type find_last_of(const _CharT * __s, size_type __pos, size_type __n) const; 
# 2046
size_type find_last_of(const _CharT *__s, size_type __pos = npos) const 
# 2047
{ 
# 2048
; 
# 2049
return (this->find_last_of(__s, __pos, traits_type::length(__s))); 
# 2050
} 
# 2065
size_type find_last_of(_CharT __c, size_type __pos = npos) const 
# 2066
{ return (this->rfind(__c, __pos)); } 
# 2079
size_type find_first_not_of(const basic_string &__str, size_type __pos = 0) const 
# 2081
{ return (this->find_first_not_of(__str.data(), __pos, __str.size())); } 
# 2096
size_type find_first_not_of(const _CharT * __s, size_type __pos, size_type __n) const; 
# 2110
size_type find_first_not_of(const _CharT *__s, size_type __pos = 0) const 
# 2111
{ 
# 2112
; 
# 2113
return (this->find_first_not_of(__s, __pos, traits_type::length(__s))); 
# 2114
} 
# 2127
size_type find_first_not_of(_CharT __c, size_type __pos = 0) const; 
# 2142
size_type find_last_not_of(const basic_string &__str, size_type __pos = npos) const 
# 2144
{ return (this->find_last_not_of(__str.data(), __pos, __str.size())); } 
# 2159
size_type find_last_not_of(const _CharT * __s, size_type __pos, size_type __n) const; 
# 2173
size_type find_last_not_of(const _CharT *__s, size_type __pos = npos) const 
# 2174
{ 
# 2175
; 
# 2176
return (this->find_last_not_of(__s, __pos, traits_type::length(__s))); 
# 2177
} 
# 2190
size_type find_last_not_of(_CharT __c, size_type __pos = npos) const; 
# 2206
basic_string substr(size_type __pos = 0, size_type __n = npos) const 
# 2207
{ return basic_string(*this, _M_check(__pos, "basic_string::substr"), __n); 
# 2208
} 
# 2225
int compare(const basic_string &__str) const 
# 2226
{ 
# 2227
const size_type __size = this->size(); 
# 2228
const size_type __osize = __str.size(); 
# 2229
const size_type __len = std::min(__size, __osize); 
# 2231
int __r = traits_type::compare(_M_data(), __str.data(), __len); 
# 2232
if (!__r) { 
# 2233
__r = (_S_compare)(__size, __osize); }  
# 2234
return __r; 
# 2235
} 
# 2257
int compare(size_type __pos, size_type __n, const basic_string & __str) const; 
# 2283
int compare(size_type __pos1, size_type __n1, const basic_string & __str, size_type __pos2, size_type __n2) const; 
# 2301
int compare(const _CharT * __s) const; 
# 2325
int compare(size_type __pos, size_type __n1, const _CharT * __s) const; 
# 2352
int compare(size_type __pos, size_type __n1, const _CharT * __s, size_type __n2) const; 
# 2354
}; 
# 2363
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  
# 2365
operator+(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2366
__rhs) 
# 2367
{ 
# 2368
basic_string< _CharT, _Traits, _Alloc>  __str(__lhs); 
# 2369
(__str.append(__rhs)); 
# 2370
return __str; 
# 2371
} 
# 2379
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  operator+(const _CharT * __lhs, const basic_string< _CharT, _Traits, _Alloc>  & __rhs); 
# 2390
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  operator+(_CharT __lhs, const basic_string< _CharT, _Traits, _Alloc>  & __rhs); 
# 2400
template< class _CharT, class _Traits, class _Alloc> inline basic_string< _CharT, _Traits, _Alloc>  
# 2402
operator+(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const _CharT *
# 2403
__rhs) 
# 2404
{ 
# 2405
basic_string< _CharT, _Traits, _Alloc>  __str(__lhs); 
# 2406
(__str.append(__rhs)); 
# 2407
return __str; 
# 2408
} 
# 2416
template< class _CharT, class _Traits, class _Alloc> inline basic_string< _CharT, _Traits, _Alloc>  
# 2418
operator+(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, _CharT __rhs) 
# 2419
{ 
# 2420
typedef basic_string< _CharT, _Traits, _Alloc>  __string_type; 
# 2421
typedef typename basic_string< _CharT, _Traits, _Alloc> ::size_type __size_type; 
# 2422
__string_type __str(__lhs); 
# 2423
(__str.append((__size_type)1, __rhs)); 
# 2424
return __str; 
# 2425
} 
# 2484
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2486
operator==(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2487
__rhs) 
# 2488
{ return (__lhs.compare(__rhs)) == 0; } 
# 2490
template< class _CharT> inline typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, bool> ::__type 
# 2493
operator==(const basic_string< _CharT, char_traits< _CharT> , allocator< _CharT> >  &__lhs, const basic_string< _CharT, char_traits< _CharT> , allocator< _CharT> >  &
# 2494
__rhs) 
# 2495
{ return ((__lhs.size()) == (__rhs.size())) && (!std::char_traits< _CharT> ::compare((__lhs.data()), (__rhs.data()), (__lhs.size()))); 
# 2497
} 
# 2505
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2507
operator==(const _CharT *__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2508
__rhs) 
# 2509
{ return (__rhs.compare(__lhs)) == 0; } 
# 2517
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2519
operator==(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const _CharT *
# 2520
__rhs) 
# 2521
{ return (__lhs.compare(__rhs)) == 0; } 
# 2530
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2532
operator!=(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2533
__rhs) 
# 2534
{ return !(__lhs == __rhs); } 
# 2542
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2544
operator!=(const _CharT *__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2545
__rhs) 
# 2546
{ return !(__lhs == __rhs); } 
# 2554
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2556
operator!=(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const _CharT *
# 2557
__rhs) 
# 2558
{ return !(__lhs == __rhs); } 
# 2567
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2569
operator<(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2570
__rhs) 
# 2571
{ return (__lhs.compare(__rhs)) < 0; } 
# 2579
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2581
operator<(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const _CharT *
# 2582
__rhs) 
# 2583
{ return (__lhs.compare(__rhs)) < 0; } 
# 2591
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2593
operator<(const _CharT *__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2594
__rhs) 
# 2595
{ return (__rhs.compare(__lhs)) > 0; } 
# 2604
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2606
operator>(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2607
__rhs) 
# 2608
{ return (__lhs.compare(__rhs)) > 0; } 
# 2616
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2618
operator>(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const _CharT *
# 2619
__rhs) 
# 2620
{ return (__lhs.compare(__rhs)) > 0; } 
# 2628
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2630
operator>(const _CharT *__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2631
__rhs) 
# 2632
{ return (__rhs.compare(__lhs)) < 0; } 
# 2641
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2643
operator<=(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2644
__rhs) 
# 2645
{ return (__lhs.compare(__rhs)) <= 0; } 
# 2653
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2655
operator<=(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const _CharT *
# 2656
__rhs) 
# 2657
{ return (__lhs.compare(__rhs)) <= 0; } 
# 2665
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2667
operator<=(const _CharT *__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2668
__rhs) 
# 2669
{ return (__rhs.compare(__lhs)) >= 0; } 
# 2678
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2680
operator>=(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2681
__rhs) 
# 2682
{ return (__lhs.compare(__rhs)) >= 0; } 
# 2690
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2692
operator>=(const basic_string< _CharT, _Traits, _Alloc>  &__lhs, const _CharT *
# 2693
__rhs) 
# 2694
{ return (__lhs.compare(__rhs)) >= 0; } 
# 2702
template< class _CharT, class _Traits, class _Alloc> inline bool 
# 2704
operator>=(const _CharT *__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 2705
__rhs) 
# 2706
{ return (__rhs.compare(__lhs)) <= 0; } 
# 2715
template< class _CharT, class _Traits, class _Alloc> inline void 
# 2717
swap(basic_string< _CharT, _Traits, _Alloc>  &__lhs, basic_string< _CharT, _Traits, _Alloc>  &
# 2718
__rhs) 
# 2719
{ (__lhs.swap(__rhs)); } 
# 2733
template< class _CharT, class _Traits, class _Alloc> basic_istream< _CharT, _Traits>  &operator>>(basic_istream< _CharT, _Traits>  & __is, basic_string< _CharT, _Traits, _Alloc>  & __str); 
# 2740
template<> basic_istream< char>  &operator>>(basic_istream< char>  & __is, basic_string< char, char_traits< char> , allocator< char> >  & __str); 
# 2751
template< class _CharT, class _Traits, class _Alloc> inline basic_ostream< _CharT, _Traits>  &
# 2753
operator<<(basic_ostream< _CharT, _Traits>  &__os, const basic_string< _CharT, _Traits, _Alloc>  &
# 2754
__str) 
# 2755
{ 
# 2758
return __ostream_insert(__os, (__str.data()), (__str.size())); 
# 2759
} 
# 2774
template< class _CharT, class _Traits, class _Alloc> basic_istream< _CharT, _Traits>  &getline(basic_istream< _CharT, _Traits>  & __is, basic_string< _CharT, _Traits, _Alloc>  & __str, _CharT __delim); 
# 2791
template< class _CharT, class _Traits, class _Alloc> inline basic_istream< _CharT, _Traits>  &
# 2793
getline(basic_istream< _CharT, _Traits>  &__is, basic_string< _CharT, _Traits, _Alloc>  &
# 2794
__str) 
# 2795
{ return getline(__is, __str, (__is.widen('\n'))); } 
# 2799
template<> basic_istream< char>  &getline(basic_istream< char>  & __in, basic_string< char, char_traits< char> , allocator< char> >  & __str, char __delim); 
# 2805
template<> basic_istream< wchar_t>  &getline(basic_istream< wchar_t>  & __in, basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str, wchar_t __delim); 
# 2810
}
# 44 "/usr/include/c++/4.8.2/bits/basic_string.tcc" 3
namespace std __attribute((__visibility__("default"))) { 
# 48
template< class _CharT, class _Traits, class _Alloc> const typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 51
basic_string< _CharT, _Traits, _Alloc> ::_Rep::_S_max_size = (((npos - sizeof(typename ::std::basic_string< _CharT, _Traits, _Alloc> ::_Rep_base)) / sizeof(_CharT)) - 1) / 4; 
# 53
template< class _CharT, class _Traits, class _Alloc> const _CharT 
# 56
basic_string< _CharT, _Traits, _Alloc> ::_Rep::_S_terminal = (_CharT()); 
# 58
template< class _CharT, class _Traits, class _Alloc> const typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 60
basic_string< _CharT, _Traits, _Alloc> ::npos; 
# 64
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 66
basic_string< _CharT, _Traits, _Alloc> ::_Rep::_S_empty_rep_storage[(((sizeof(typename ::std::basic_string< _CharT, _Traits, _Alloc> ::_Rep_base) + sizeof(_CharT)) + sizeof(typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type)) - (1)) / sizeof(typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type)]; 
# 74
template< class _CharT, class _Traits, class _Alloc> 
# 75
template< class _InIterator> _CharT *
# 78
basic_string< _CharT, _Traits, _Alloc> ::_S_construct(_InIterator __beg, _InIterator __end, const _Alloc &__a, input_iterator_tag) 
# 80
{ 
# 82
if ((__beg == __end) && (__a == _Alloc())) { 
# 83
return ((_S_empty_rep)()._M_refdata()); }  
# 86
_CharT __buf[128]; 
# 87
size_type __len = (0); 
# 88
while ((__beg != __end) && (__len < (sizeof(__buf) / sizeof(_CharT)))) 
# 89
{ 
# 90
(__buf[__len++]) = (*__beg); 
# 91
++__beg; 
# 92
}  
# 93
_Rep *__r = _Rep::_S_create(__len, (size_type)0, __a); 
# 94
(_M_copy)((__r->_M_refdata()), __buf, __len); 
# 95
try 
# 96
{ 
# 97
while (__beg != __end) 
# 98
{ 
# 99
if (__len == (__r->_M_capacity)) 
# 100
{ 
# 102
_Rep *__another = _Rep::_S_create(__len + 1, __len, __a); 
# 103
(_M_copy)((__another->_M_refdata()), (__r->_M_refdata()), __len); 
# 104
(__r->_M_destroy(__a)); 
# 105
__r = __another; 
# 106
}  
# 107
((__r->_M_refdata())[__len++]) = (*__beg); 
# 108
++__beg; 
# 109
}  
# 110
} 
# 111
catch (...) 
# 112
{ 
# 113
(__r->_M_destroy(__a)); 
# 114
throw; 
# 115
}  
# 116
(__r->_M_set_length_and_sharable(__len)); 
# 117
return (__r->_M_refdata()); 
# 118
} 
# 120
template< class _CharT, class _Traits, class _Alloc> 
# 121
template< class _InIterator> _CharT *
# 124
basic_string< _CharT, _Traits, _Alloc> ::_S_construct(_InIterator __beg, _InIterator __end, const _Alloc &__a, forward_iterator_tag) 
# 126
{ 
# 128
if ((__beg == __end) && (__a == _Alloc())) { 
# 129
return ((_S_empty_rep)()._M_refdata()); }  
# 132
if (__gnu_cxx::__is_null_pointer(__beg) && (__beg != __end)) { 
# 133
__throw_logic_error("basic_string::_S_construct null not valid"); }  
# 135
const size_type __dnew = static_cast< size_type>(std::distance(__beg, __end)); 
# 138
_Rep *__r = _Rep::_S_create(__dnew, (size_type)0, __a); 
# 139
try 
# 140
{ _S_copy_chars((__r->_M_refdata()), __beg, __end); } 
# 141
catch (...) 
# 142
{ 
# 143
(__r->_M_destroy(__a)); 
# 144
throw; 
# 145
}  
# 146
(__r->_M_set_length_and_sharable(__dnew)); 
# 147
return (__r->_M_refdata()); 
# 148
} 
# 150
template< class _CharT, class _Traits, class _Alloc> _CharT *
# 153
basic_string< _CharT, _Traits, _Alloc> ::_S_construct(size_type __n, _CharT __c, const _Alloc &__a) 
# 154
{ 
# 156
if ((__n == 0) && (__a == _Alloc())) { 
# 157
return ((_S_empty_rep)()._M_refdata()); }  
# 160
_Rep *__r = _Rep::_S_create(__n, (size_type)0, __a); 
# 161
if (__n) { 
# 162
(_M_assign)((__r->_M_refdata()), __n, __c); }  
# 164
(__r->_M_set_length_and_sharable(__n)); 
# 165
return (__r->_M_refdata()); 
# 166
} 
# 168
template< class _CharT, class _Traits, class _Alloc> 
# 170
basic_string< _CharT, _Traits, _Alloc> ::basic_string(const basic_string &__str) : _M_dataplus((__str._M_rep()->_M_grab((_Alloc)__str.get_allocator(), __str.get_allocator())), __str.get_allocator()) 
# 174
{ } 
# 176
template< class _CharT, class _Traits, class _Alloc> 
# 178
basic_string< _CharT, _Traits, _Alloc> ::basic_string(const _Alloc &__a) : _M_dataplus(_S_construct(size_type(), _CharT(), __a), __a) 
# 180
{ } 
# 182
template< class _CharT, class _Traits, class _Alloc> 
# 184
basic_string< _CharT, _Traits, _Alloc> ::basic_string(const basic_string &__str, size_type __pos, size_type __n) : _M_dataplus(_S_construct((__str._M_data()) + __str._M_check(__pos, "basic_string::basic_string"), ((__str._M_data()) + __str._M_limit(__pos, __n)) + __pos, _Alloc()), _Alloc()) 
# 190
{ } 
# 192
template< class _CharT, class _Traits, class _Alloc> 
# 194
basic_string< _CharT, _Traits, _Alloc> ::basic_string(const basic_string &__str, size_type __pos, size_type 
# 195
__n, const _Alloc &__a) : _M_dataplus(_S_construct((__str._M_data()) + __str._M_check(__pos, "basic_string::basic_string"), ((__str._M_data()) + __str._M_limit(__pos, __n)) + __pos, __a), __a) 
# 201
{ } 
# 204
template< class _CharT, class _Traits, class _Alloc> 
# 206
basic_string< _CharT, _Traits, _Alloc> ::basic_string(const _CharT *__s, size_type __n, const _Alloc &__a) : _M_dataplus(_S_construct(__s, __s + __n, __a), __a) 
# 208
{ } 
# 211
template< class _CharT, class _Traits, class _Alloc> 
# 213
basic_string< _CharT, _Traits, _Alloc> ::basic_string(const _CharT *__s, const _Alloc &__a) : _M_dataplus(_S_construct(__s, (__s) ? __s + traits_type::length(__s) : (__s + npos), __a), __a) 
# 216
{ } 
# 218
template< class _CharT, class _Traits, class _Alloc> 
# 220
basic_string< _CharT, _Traits, _Alloc> ::basic_string(size_type __n, _CharT __c, const _Alloc &__a) : _M_dataplus(_S_construct(__n, __c, __a), __a) 
# 222
{ } 
# 225
template< class _CharT, class _Traits, class _Alloc> 
# 226
template< class _InputIterator> 
# 228
basic_string< _CharT, _Traits, _Alloc> ::basic_string(_InputIterator __beg, _InputIterator __end, const _Alloc &__a) : _M_dataplus(_S_construct(__beg, __end, __a), __a) 
# 230
{ } 
# 240
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 243
basic_string< _CharT, _Traits, _Alloc> ::assign(const basic_string &__str) 
# 244
{ 
# 245
if (_M_rep() != __str._M_rep()) 
# 246
{ 
# 248
const allocator_type __a = this->get_allocator(); 
# 249
_CharT *__tmp = (__str._M_rep()->_M_grab(__a, __str.get_allocator())); 
# 250
(_M_rep()->_M_dispose(__a)); 
# 251
_M_data(__tmp); 
# 252
}  
# 253
return *this; 
# 254
} 
# 256
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 259
basic_string< _CharT, _Traits, _Alloc> ::assign(const _CharT *__s, size_type __n) 
# 260
{ 
# 261
; 
# 262
_M_check_length(this->size(), __n, "basic_string::assign"); 
# 263
if (_M_disjunct(__s) || (_M_rep()->_M_is_shared())) { 
# 264
return _M_replace_safe((size_type)0, this->size(), __s, __n); } else 
# 266
{ 
# 268
const size_type __pos = __s - _M_data(); 
# 269
if (__pos >= __n) { 
# 270
(_M_copy)(_M_data(), __s, __n); } else { 
# 271
if (__pos) { 
# 272
(_M_move)(_M_data(), __s, __n); }  }  
# 273
(_M_rep()->_M_set_length_and_sharable(__n)); 
# 274
return *this; 
# 275
}  
# 276
} 
# 278
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 281
basic_string< _CharT, _Traits, _Alloc> ::append(size_type __n, _CharT __c) 
# 282
{ 
# 283
if (__n) 
# 284
{ 
# 285
_M_check_length((size_type)0, __n, "basic_string::append"); 
# 286
const size_type __len = __n + this->size(); 
# 287
if ((__len > this->capacity()) || (_M_rep()->_M_is_shared())) { 
# 288
this->reserve(__len); }  
# 289
(_M_assign)(_M_data() + this->size(), __n, __c); 
# 290
(_M_rep()->_M_set_length_and_sharable(__len)); 
# 291
}  
# 292
return *this; 
# 293
} 
# 295
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 298
basic_string< _CharT, _Traits, _Alloc> ::append(const _CharT *__s, size_type __n) 
# 299
{ 
# 300
; 
# 301
if (__n) 
# 302
{ 
# 303
_M_check_length((size_type)0, __n, "basic_string::append"); 
# 304
const size_type __len = __n + this->size(); 
# 305
if ((__len > this->capacity()) || (_M_rep()->_M_is_shared())) 
# 306
{ 
# 307
if (_M_disjunct(__s)) { 
# 308
this->reserve(__len); } else 
# 310
{ 
# 311
const size_type __off = __s - _M_data(); 
# 312
this->reserve(__len); 
# 313
__s = (_M_data() + __off); 
# 314
}  
# 315
}  
# 316
(_M_copy)(_M_data() + this->size(), __s, __n); 
# 317
(_M_rep()->_M_set_length_and_sharable(__len)); 
# 318
}  
# 319
return *this; 
# 320
} 
# 322
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 325
basic_string< _CharT, _Traits, _Alloc> ::append(const basic_string &__str) 
# 326
{ 
# 327
const size_type __size = __str.size(); 
# 328
if (__size) 
# 329
{ 
# 330
const size_type __len = __size + this->size(); 
# 331
if ((__len > this->capacity()) || (_M_rep()->_M_is_shared())) { 
# 332
this->reserve(__len); }  
# 333
(_M_copy)(_M_data() + this->size(), (__str._M_data()), __size); 
# 334
(_M_rep()->_M_set_length_and_sharable(__len)); 
# 335
}  
# 336
return *this; 
# 337
} 
# 339
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 342
basic_string< _CharT, _Traits, _Alloc> ::append(const basic_string &__str, size_type __pos, size_type __n) 
# 343
{ 
# 344
__str._M_check(__pos, "basic_string::append"); 
# 345
__n = __str._M_limit(__pos, __n); 
# 346
if (__n) 
# 347
{ 
# 348
const size_type __len = __n + this->size(); 
# 349
if ((__len > this->capacity()) || (_M_rep()->_M_is_shared())) { 
# 350
this->reserve(__len); }  
# 351
(_M_copy)(_M_data() + this->size(), (__str._M_data()) + __pos, __n); 
# 352
(_M_rep()->_M_set_length_and_sharable(__len)); 
# 353
}  
# 354
return *this; 
# 355
} 
# 357
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 360
basic_string< _CharT, _Traits, _Alloc> ::insert(size_type __pos, const _CharT *__s, size_type __n) 
# 361
{ 
# 362
; 
# 363
_M_check(__pos, "basic_string::insert"); 
# 364
_M_check_length((size_type)0, __n, "basic_string::insert"); 
# 365
if (_M_disjunct(__s) || (_M_rep()->_M_is_shared())) { 
# 366
return _M_replace_safe(__pos, (size_type)0, __s, __n); } else 
# 368
{ 
# 370
const size_type __off = __s - _M_data(); 
# 371
_M_mutate(__pos, 0, __n); 
# 372
__s = (_M_data() + __off); 
# 373
_CharT *__p = _M_data() + __pos; 
# 374
if ((__s + __n) <= __p) { 
# 375
(_M_copy)(__p, __s, __n); } else { 
# 376
if (__s >= __p) { 
# 377
(_M_copy)(__p, __s + __n, __n); } else 
# 379
{ 
# 380
const size_type __nleft = __p - __s; 
# 381
(_M_copy)(__p, __s, __nleft); 
# 382
(_M_copy)(__p + __nleft, __p + __n, __n - __nleft); 
# 383
}  }  
# 384
return *this; 
# 385
}  
# 386
} 
# 388
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::iterator 
# 391
basic_string< _CharT, _Traits, _Alloc> ::erase(iterator __first, iterator __last) 
# 392
{ 
# 394
; 
# 399
const size_type __size = __last - __first; 
# 400
if (__size) 
# 401
{ 
# 402
const size_type __pos = __first - _M_ibegin(); 
# 403
_M_mutate(__pos, __size, (size_type)0); 
# 404
(_M_rep()->_M_set_leaked()); 
# 405
return ((iterator)(_M_data() + __pos)); 
# 406
} else { 
# 408
return __first; }  
# 409
} 
# 411
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 414
basic_string< _CharT, _Traits, _Alloc> ::replace(size_type __pos, size_type __n1, const _CharT *__s, size_type 
# 415
__n2) 
# 416
{ 
# 417
; 
# 418
_M_check(__pos, "basic_string::replace"); 
# 419
__n1 = _M_limit(__pos, __n1); 
# 420
_M_check_length(__n1, __n2, "basic_string::replace"); 
# 421
bool __left; 
# 422
if (_M_disjunct(__s) || (_M_rep()->_M_is_shared())) { 
# 423
return _M_replace_safe(__pos, __n1, __s, __n2); } else { 
# 424
if ((__left = ((__s + __n2) <= (_M_data() + __pos))) || (((_M_data() + __pos) + __n1) <= __s)) 
# 426
{ 
# 428
size_type __off = __s - _M_data(); 
# 429
__left ? __off : (__off += (__n2 - __n1)); 
# 430
_M_mutate(__pos, __n1, __n2); 
# 431
(_M_copy)(_M_data() + __pos, _M_data() + __off, __n2); 
# 432
return *this; 
# 433
} else 
# 435
{ 
# 437
const basic_string __tmp(__s, __n2); 
# 438
return _M_replace_safe(__pos, __n1, (__tmp._M_data()), __n2); 
# 439
}  }  
# 440
} 
# 442
template< class _CharT, class _Traits, class _Alloc> void 
# 445
basic_string< _CharT, _Traits, _Alloc> ::_Rep::_M_destroy(const _Alloc &__a) throw() 
# 446
{ 
# 447
const typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __size = sizeof(typename ::std::basic_string< _CharT, _Traits, _Alloc> ::_Rep_base) + (((this->_M_capacity) + 1) * sizeof(_CharT)); 
# 449
(((_Raw_bytes_alloc)__a).deallocate(reinterpret_cast< char *>(this), __size)); 
# 450
} 
# 452
template< class _CharT, class _Traits, class _Alloc> void 
# 455
basic_string< _CharT, _Traits, _Alloc> ::_M_leak_hard() 
# 456
{ 
# 458
if (_M_rep() == (&(_S_empty_rep)())) { 
# 459
return; }  
# 461
if ((_M_rep()->_M_is_shared())) { 
# 462
_M_mutate(0, 0, 0); }  
# 463
(_M_rep()->_M_set_leaked()); 
# 464
} 
# 466
template< class _CharT, class _Traits, class _Alloc> void 
# 469
basic_string< _CharT, _Traits, _Alloc> ::_M_mutate(size_type __pos, size_type __len1, size_type __len2) 
# 470
{ 
# 471
const size_type __old_size = this->size(); 
# 472
const size_type __new_size = (__old_size + __len2) - __len1; 
# 473
const size_type __how_much = (__old_size - __pos) - __len1; 
# 475
if ((__new_size > this->capacity()) || (_M_rep()->_M_is_shared())) 
# 476
{ 
# 478
const allocator_type __a = get_allocator(); 
# 479
_Rep *__r = _Rep::_S_create(__new_size, this->capacity(), __a); 
# 481
if (__pos) { 
# 482
(_M_copy)((__r->_M_refdata()), _M_data(), __pos); }  
# 483
if (__how_much) { 
# 484
(_M_copy)(((__r->_M_refdata()) + __pos) + __len2, (_M_data() + __pos) + __len1, __how_much); }  
# 487
(_M_rep()->_M_dispose(__a)); 
# 488
_M_data((__r->_M_refdata())); 
# 489
} else { 
# 490
if (__how_much && (__len1 != __len2)) 
# 491
{ 
# 493
(_M_move)((_M_data() + __pos) + __len2, (_M_data() + __pos) + __len1, __how_much); 
# 495
}  }  
# 496
(_M_rep()->_M_set_length_and_sharable(__new_size)); 
# 497
} 
# 499
template< class _CharT, class _Traits, class _Alloc> void 
# 502
basic_string< _CharT, _Traits, _Alloc> ::reserve(size_type __res) 
# 503
{ 
# 504
if ((__res != this->capacity()) || (_M_rep()->_M_is_shared())) 
# 505
{ 
# 507
if (__res < this->size()) { 
# 508
__res = this->size(); }  
# 509
const allocator_type __a = get_allocator(); 
# 510
_CharT *__tmp = (_M_rep()->_M_clone(__a, __res - this->size())); 
# 511
(_M_rep()->_M_dispose(__a)); 
# 512
_M_data(__tmp); 
# 513
}  
# 514
} 
# 516
template< class _CharT, class _Traits, class _Alloc> void 
# 519
basic_string< _CharT, _Traits, _Alloc> ::swap(basic_string &__s) 
# 520
{ 
# 521
if ((_M_rep()->_M_is_leaked())) { 
# 522
(_M_rep()->_M_set_sharable()); }  
# 523
if ((__s._M_rep()->_M_is_leaked())) { 
# 524
(__s._M_rep()->_M_set_sharable()); }  
# 525
if (this->get_allocator() == __s.get_allocator()) 
# 526
{ 
# 527
_CharT *__tmp = _M_data(); 
# 528
_M_data((__s._M_data())); 
# 529
(__s._M_data(__tmp)); 
# 530
} else 
# 533
{ 
# 534
const basic_string __tmp1(_M_ibegin(), _M_iend(), __s.get_allocator()); 
# 536
const basic_string __tmp2(__s._M_ibegin(), __s._M_iend(), this->get_allocator()); 
# 538
(*this) = __tmp2; 
# 539
__s = __tmp1; 
# 540
}  
# 541
} 
# 543
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::_Rep *
# 546
basic_string< _CharT, _Traits, _Alloc> ::_Rep::_S_create(typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __capacity, typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __old_capacity, const _Alloc &
# 547
__alloc) 
# 548
{ 
# 551
if (__capacity > _S_max_size) { 
# 552
__throw_length_error("basic_string::_S_create"); }  
# 577
const typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __pagesize = (4096); 
# 578
const typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __malloc_header_size = ((4) * sizeof(void *)); 
# 586
if ((__capacity > __old_capacity) && (__capacity < (2 * __old_capacity))) { 
# 587
__capacity = (2 * __old_capacity); }  
# 592
typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __size = ((__capacity + 1) * sizeof(_CharT)) + sizeof(_Rep); 
# 594
const typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __adj_size = __size + __malloc_header_size; 
# 595
if ((__adj_size > __pagesize) && (__capacity > __old_capacity)) 
# 596
{ 
# 597
const typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __extra = __pagesize - (__adj_size % __pagesize); 
# 598
__capacity += (__extra / sizeof(_CharT)); 
# 600
if (__capacity > _S_max_size) { 
# 601
__capacity = _S_max_size; }  
# 602
__size = (((__capacity + 1) * sizeof(_CharT)) + sizeof(_Rep)); 
# 603
}  
# 607
void *__place = (((_Raw_bytes_alloc)__alloc).allocate(__size)); 
# 608
_Rep *__p = new (__place) _Rep; 
# 609
(__p->_M_capacity) = __capacity; 
# 617
__p->_M_set_sharable(); 
# 618
return __p; 
# 619
} 
# 621
template< class _CharT, class _Traits, class _Alloc> _CharT *
# 624
basic_string< _CharT, _Traits, _Alloc> ::_Rep::_M_clone(const _Alloc &__alloc, typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __res) 
# 625
{ 
# 627
const typename ::std::basic_string< _CharT, _Traits, _Alloc> ::size_type __requested_cap = (this->_M_length) + __res; 
# 628
_Rep *__r = (_S_create)(__requested_cap, (this->_M_capacity), __alloc); 
# 630
if (this->_M_length) { 
# 631
(::std::basic_string< _CharT, _Traits, _Alloc> ::_M_copy)(__r->_M_refdata(), _M_refdata(), (this->_M_length)); }  
# 633
__r->_M_set_length_and_sharable((this->_M_length)); 
# 634
return __r->_M_refdata(); 
# 635
} 
# 637
template< class _CharT, class _Traits, class _Alloc> void 
# 640
basic_string< _CharT, _Traits, _Alloc> ::resize(size_type __n, _CharT __c) 
# 641
{ 
# 642
const size_type __size = this->size(); 
# 643
_M_check_length(__size, __n, "basic_string::resize"); 
# 644
if (__size < __n) { 
# 645
(this->append(__n - __size, __c)); } else { 
# 646
if (__n < __size) { 
# 647
(this->erase(__n)); }  }  
# 649
} 
# 651
template< class _CharT, class _Traits, class _Alloc> 
# 652
template< class _InputIterator> basic_string< _CharT, _Traits, _Alloc>  &
# 655
basic_string< _CharT, _Traits, _Alloc> ::_M_replace_dispatch(iterator __i1, iterator __i2, _InputIterator __k1, _InputIterator 
# 656
__k2, __false_type) 
# 657
{ 
# 658
const basic_string __s(__k1, __k2); 
# 659
const size_type __n1 = __i2 - __i1; 
# 660
_M_check_length(__n1, __s.size(), "basic_string::_M_replace_dispatch"); 
# 661
return _M_replace_safe(__i1 - _M_ibegin(), __n1, (__s._M_data()), __s.size()); 
# 663
} 
# 665
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 668
basic_string< _CharT, _Traits, _Alloc> ::_M_replace_aux(size_type __pos1, size_type __n1, size_type __n2, _CharT 
# 669
__c) 
# 670
{ 
# 671
_M_check_length(__n1, __n2, "basic_string::_M_replace_aux"); 
# 672
_M_mutate(__pos1, __n1, __n2); 
# 673
if (__n2) { 
# 674
(_M_assign)(_M_data() + __pos1, __n2, __c); }  
# 675
return *this; 
# 676
} 
# 678
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  &
# 681
basic_string< _CharT, _Traits, _Alloc> ::_M_replace_safe(size_type __pos1, size_type __n1, const _CharT *__s, size_type 
# 682
__n2) 
# 683
{ 
# 684
_M_mutate(__pos1, __n1, __n2); 
# 685
if (__n2) { 
# 686
(_M_copy)(_M_data() + __pos1, __s, __n2); }  
# 687
return *this; 
# 688
} 
# 690
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  
# 692
operator+(const _CharT *__lhs, const basic_string< _CharT, _Traits, _Alloc>  &
# 693
__rhs) 
# 694
{ 
# 695
; 
# 696
typedef basic_string< _CharT, _Traits, _Alloc>  __string_type; 
# 697
typedef typename basic_string< _CharT, _Traits, _Alloc> ::size_type __size_type; 
# 698
const __size_type __len = _Traits::length(__lhs); 
# 699
__string_type __str; 
# 700
(__str.reserve(__len + (__rhs.size()))); 
# 701
(__str.append(__lhs, __len)); 
# 702
(__str.append(__rhs)); 
# 703
return __str; 
# 704
} 
# 706
template< class _CharT, class _Traits, class _Alloc> basic_string< _CharT, _Traits, _Alloc>  
# 708
operator+(_CharT __lhs, const basic_string< _CharT, _Traits, _Alloc>  &__rhs) 
# 709
{ 
# 710
typedef basic_string< _CharT, _Traits, _Alloc>  __string_type; 
# 711
typedef typename basic_string< _CharT, _Traits, _Alloc> ::size_type __size_type; 
# 712
__string_type __str; 
# 713
const __size_type __len = (__rhs.size()); 
# 714
(__str.reserve(__len + 1)); 
# 715
(__str.append((__size_type)1, __lhs)); 
# 716
(__str.append(__rhs)); 
# 717
return __str; 
# 718
} 
# 720
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 723
basic_string< _CharT, _Traits, _Alloc> ::copy(_CharT *__s, size_type __n, size_type __pos) const 
# 724
{ 
# 725
_M_check(__pos, "basic_string::copy"); 
# 726
__n = _M_limit(__pos, __n); 
# 727
; 
# 728
if (__n) { 
# 729
(_M_copy)(__s, _M_data() + __pos, __n); }  
# 731
return __n; 
# 732
} 
# 734
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 737
basic_string< _CharT, _Traits, _Alloc> ::find(const _CharT *__s, size_type __pos, size_type __n) const 
# 738
{ 
# 739
; 
# 740
const size_type __size = this->size(); 
# 741
const _CharT *__data = _M_data(); 
# 743
if (__n == 0) { 
# 744
return (__pos <= __size) ? __pos : npos; }  
# 746
if (__n <= __size) 
# 747
{ 
# 748
for (; __pos <= (__size - __n); ++__pos) { 
# 749
if (traits_type::eq(__data[__pos], __s[0]) && (traits_type::compare((__data + __pos) + 1, __s + 1, __n - 1) == 0)) { 
# 752
return __pos; }  }  
# 753
}  
# 754
return npos; 
# 755
} 
# 757
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 760
basic_string< _CharT, _Traits, _Alloc> ::find(_CharT __c, size_type __pos) const 
# 761
{ 
# 762
size_type __ret = npos; 
# 763
const size_type __size = this->size(); 
# 764
if (__pos < __size) 
# 765
{ 
# 766
const _CharT *__data = _M_data(); 
# 767
const size_type __n = __size - __pos; 
# 768
const _CharT *__p = traits_type::find(__data + __pos, __n, __c); 
# 769
if (__p) { 
# 770
__ret = (__p - __data); }  
# 771
}  
# 772
return __ret; 
# 773
} 
# 775
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 778
basic_string< _CharT, _Traits, _Alloc> ::rfind(const _CharT *__s, size_type __pos, size_type __n) const 
# 779
{ 
# 780
; 
# 781
const size_type __size = this->size(); 
# 782
if (__n <= __size) 
# 783
{ 
# 784
__pos = std::min((size_type)(__size - __n), __pos); 
# 785
const _CharT *__data = _M_data(); 
# 786
do 
# 787
{ 
# 788
if (traits_type::compare(__data + __pos, __s, __n) == 0) { 
# 789
return __pos; }  
# 790
} 
# 791
while ((__pos--) > 0); 
# 792
}  
# 793
return npos; 
# 794
} 
# 796
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 799
basic_string< _CharT, _Traits, _Alloc> ::rfind(_CharT __c, size_type __pos) const 
# 800
{ 
# 801
size_type __size = this->size(); 
# 802
if (__size) 
# 803
{ 
# 804
if ((--__size) > __pos) { 
# 805
__size = __pos; }  
# 806
for (++__size; (__size--) > 0;) { 
# 807
if (traits_type::eq(_M_data()[__size], __c)) { 
# 808
return __size; }  }  
# 809
}  
# 810
return npos; 
# 811
} 
# 813
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 816
basic_string< _CharT, _Traits, _Alloc> ::find_first_of(const _CharT *__s, size_type __pos, size_type __n) const 
# 817
{ 
# 818
; 
# 819
for (; __n && (__pos < this->size()); ++__pos) 
# 820
{ 
# 821
const _CharT *__p = traits_type::find(__s, __n, _M_data()[__pos]); 
# 822
if (__p) { 
# 823
return __pos; }  
# 824
}  
# 825
return npos; 
# 826
} 
# 828
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 831
basic_string< _CharT, _Traits, _Alloc> ::find_last_of(const _CharT *__s, size_type __pos, size_type __n) const 
# 832
{ 
# 833
; 
# 834
size_type __size = this->size(); 
# 835
if (__size && __n) 
# 836
{ 
# 837
if ((--__size) > __pos) { 
# 838
__size = __pos; }  
# 839
do 
# 840
{ 
# 841
if (traits_type::find(__s, __n, _M_data()[__size])) { 
# 842
return __size; }  
# 843
} 
# 844
while ((__size--) != 0); 
# 845
}  
# 846
return npos; 
# 847
} 
# 849
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 852
basic_string< _CharT, _Traits, _Alloc> ::find_first_not_of(const _CharT *__s, size_type __pos, size_type __n) const 
# 853
{ 
# 854
; 
# 855
for (; __pos < this->size(); ++__pos) { 
# 856
if (!traits_type::find(__s, __n, _M_data()[__pos])) { 
# 857
return __pos; }  }  
# 858
return npos; 
# 859
} 
# 861
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 864
basic_string< _CharT, _Traits, _Alloc> ::find_first_not_of(_CharT __c, size_type __pos) const 
# 865
{ 
# 866
for (; __pos < this->size(); ++__pos) { 
# 867
if (!traits_type::eq(_M_data()[__pos], __c)) { 
# 868
return __pos; }  }  
# 869
return npos; 
# 870
} 
# 872
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 875
basic_string< _CharT, _Traits, _Alloc> ::find_last_not_of(const _CharT *__s, size_type __pos, size_type __n) const 
# 876
{ 
# 877
; 
# 878
size_type __size = this->size(); 
# 879
if (__size) 
# 880
{ 
# 881
if ((--__size) > __pos) { 
# 882
__size = __pos; }  
# 883
do 
# 884
{ 
# 885
if (!traits_type::find(__s, __n, _M_data()[__size])) { 
# 886
return __size; }  
# 887
} 
# 888
while (__size--); 
# 889
}  
# 890
return npos; 
# 891
} 
# 893
template< class _CharT, class _Traits, class _Alloc> typename basic_string< _CharT, _Traits, _Alloc> ::size_type 
# 896
basic_string< _CharT, _Traits, _Alloc> ::find_last_not_of(_CharT __c, size_type __pos) const 
# 897
{ 
# 898
size_type __size = this->size(); 
# 899
if (__size) 
# 900
{ 
# 901
if ((--__size) > __pos) { 
# 902
__size = __pos; }  
# 903
do 
# 904
{ 
# 905
if (!traits_type::eq(_M_data()[__size], __c)) { 
# 906
return __size; }  
# 907
} 
# 908
while (__size--); 
# 909
}  
# 910
return npos; 
# 911
} 
# 913
template< class _CharT, class _Traits, class _Alloc> int 
# 916
basic_string< _CharT, _Traits, _Alloc> ::compare(size_type __pos, size_type __n, const basic_string &__str) const 
# 917
{ 
# 918
_M_check(__pos, "basic_string::compare"); 
# 919
__n = _M_limit(__pos, __n); 
# 920
const size_type __osize = __str.size(); 
# 921
const size_type __len = std::min(__n, __osize); 
# 922
int __r = traits_type::compare(_M_data() + __pos, __str.data(), __len); 
# 923
if (!__r) { 
# 924
__r = (_S_compare)(__n, __osize); }  
# 925
return __r; 
# 926
} 
# 928
template< class _CharT, class _Traits, class _Alloc> int 
# 931
basic_string< _CharT, _Traits, _Alloc> ::compare(size_type __pos1, size_type __n1, const basic_string &__str, size_type 
# 932
__pos2, size_type __n2) const 
# 933
{ 
# 934
_M_check(__pos1, "basic_string::compare"); 
# 935
__str._M_check(__pos2, "basic_string::compare"); 
# 936
__n1 = _M_limit(__pos1, __n1); 
# 937
__n2 = __str._M_limit(__pos2, __n2); 
# 938
const size_type __len = std::min(__n1, __n2); 
# 939
int __r = traits_type::compare(_M_data() + __pos1, __str.data() + __pos2, __len); 
# 941
if (!__r) { 
# 942
__r = (_S_compare)(__n1, __n2); }  
# 943
return __r; 
# 944
} 
# 946
template< class _CharT, class _Traits, class _Alloc> int 
# 949
basic_string< _CharT, _Traits, _Alloc> ::compare(const _CharT *__s) const 
# 950
{ 
# 951
; 
# 952
const size_type __size = this->size(); 
# 953
const size_type __osize = traits_type::length(__s); 
# 954
const size_type __len = std::min(__size, __osize); 
# 955
int __r = traits_type::compare(_M_data(), __s, __len); 
# 956
if (!__r) { 
# 957
__r = (_S_compare)(__size, __osize); }  
# 958
return __r; 
# 959
} 
# 961
template< class _CharT, class _Traits, class _Alloc> int 
# 964
basic_string< _CharT, _Traits, _Alloc> ::compare(size_type __pos, size_type __n1, const _CharT *__s) const 
# 965
{ 
# 966
; 
# 967
_M_check(__pos, "basic_string::compare"); 
# 968
__n1 = _M_limit(__pos, __n1); 
# 969
const size_type __osize = traits_type::length(__s); 
# 970
const size_type __len = std::min(__n1, __osize); 
# 971
int __r = traits_type::compare(_M_data() + __pos, __s, __len); 
# 972
if (!__r) { 
# 973
__r = (_S_compare)(__n1, __osize); }  
# 974
return __r; 
# 975
} 
# 977
template< class _CharT, class _Traits, class _Alloc> int 
# 980
basic_string< _CharT, _Traits, _Alloc> ::compare(size_type __pos, size_type __n1, const _CharT *__s, size_type 
# 981
__n2) const 
# 982
{ 
# 983
; 
# 984
_M_check(__pos, "basic_string::compare"); 
# 985
__n1 = _M_limit(__pos, __n1); 
# 986
const size_type __len = std::min(__n1, __n2); 
# 987
int __r = traits_type::compare(_M_data() + __pos, __s, __len); 
# 988
if (!__r) { 
# 989
__r = (_S_compare)(__n1, __n2); }  
# 990
return __r; 
# 991
} 
# 994
template< class _CharT, class _Traits, class _Alloc> basic_istream< _CharT, _Traits>  &
# 996
operator>>(basic_istream< _CharT, _Traits>  &__in, basic_string< _CharT, _Traits, _Alloc>  &
# 997
__str) 
# 998
{ 
# 999
typedef basic_istream< _CharT, _Traits>  __istream_type; 
# 1000
typedef basic_string< _CharT, _Traits, _Alloc>  __string_type; 
# 1001
typedef typename basic_istream< _CharT, _Traits> ::ios_base __ios_base; 
# 1002
typedef typename basic_istream< _CharT, _Traits> ::int_type __int_type; 
# 1003
typedef typename basic_string< _CharT, _Traits, _Alloc> ::size_type __size_type; 
# 1004
typedef ctype< _CharT>  __ctype_type; 
# 1005
typedef typename ctype< _CharT> ::ctype_base __ctype_base; 
# 1007
__size_type __extracted = (0); 
# 1008
typename basic_istream< _CharT, _Traits> ::ios_base::iostate __err = (__ios_base::goodbit); 
# 1009
typename basic_istream< _CharT, _Traits> ::sentry __cerb(__in, false); 
# 1010
if (__cerb) 
# 1011
{ 
# 1012
try 
# 1013
{ 
# 1015
(__str.erase()); 
# 1016
_CharT __buf[128]; 
# 1017
__size_type __len = (0); 
# 1018
const streamsize __w = (__in.width()); 
# 1019
const __size_type __n = (__w > (0)) ? static_cast< __size_type>(__w) : (__str.max_size()); 
# 1021
const __ctype_type &__ct = use_facet< ctype< _CharT> > ((__in.getloc())); 
# 1022
const __int_type __eof = _Traits::eof(); 
# 1023
__int_type __c = ((__in.rdbuf())->sgetc()); 
# 1025
while ((__extracted < __n) && (!_Traits::eq_int_type(__c, __eof)) && (!(__ct.is(__ctype_base::space, _Traits::to_char_type(__c))))) 
# 1029
{ 
# 1030
if (__len == (sizeof(__buf) / sizeof(_CharT))) 
# 1031
{ 
# 1032
(__str.append(__buf, sizeof(__buf) / sizeof(_CharT))); 
# 1033
__len = 0; 
# 1034
}  
# 1035
(__buf[__len++]) = _Traits::to_char_type(__c); 
# 1036
++__extracted; 
# 1037
__c = ((__in.rdbuf())->snextc()); 
# 1038
}  
# 1039
(__str.append(__buf, __len)); 
# 1041
if (_Traits::eq_int_type(__c, __eof)) { 
# 1042
__err |= __ios_base::eofbit; }  
# 1043
(__in.width(0)); 
# 1044
} 
# 1045
catch (__cxxabiv1::__forced_unwind &) 
# 1046
{ 
# 1047
(__in._M_setstate(__ios_base::badbit)); 
# 1048
throw; 
# 1049
} 
# 1050
catch (...) 
# 1051
{ 
# 1055
(__in._M_setstate(__ios_base::badbit)); 
# 1056
}  
# 1057
}  
# 1059
if (!__extracted) { 
# 1060
__err |= __ios_base::failbit; }  
# 1061
if (__err) { 
# 1062
(__in.setstate(__err)); }  
# 1063
return __in; 
# 1064
} 
# 1066
template< class _CharT, class _Traits, class _Alloc> basic_istream< _CharT, _Traits>  &
# 1068
getline(basic_istream< _CharT, _Traits>  &__in, basic_string< _CharT, _Traits, _Alloc>  &
# 1069
__str, _CharT __delim) 
# 1070
{ 
# 1071
typedef basic_istream< _CharT, _Traits>  __istream_type; 
# 1072
typedef basic_string< _CharT, _Traits, _Alloc>  __string_type; 
# 1073
typedef typename basic_istream< _CharT, _Traits> ::ios_base __ios_base; 
# 1074
typedef typename basic_istream< _CharT, _Traits> ::int_type __int_type; 
# 1075
typedef typename basic_string< _CharT, _Traits, _Alloc> ::size_type __size_type; 
# 1077
__size_type __extracted = (0); 
# 1078
const __size_type __n = (__str.max_size()); 
# 1079
typename basic_istream< _CharT, _Traits> ::ios_base::iostate __err = (__ios_base::goodbit); 
# 1080
typename basic_istream< _CharT, _Traits> ::sentry __cerb(__in, true); 
# 1081
if (__cerb) 
# 1082
{ 
# 1083
try 
# 1084
{ 
# 1085
(__str.erase()); 
# 1086
const __int_type __idelim = _Traits::to_int_type(__delim); 
# 1087
const __int_type __eof = _Traits::eof(); 
# 1088
__int_type __c = ((__in.rdbuf())->sgetc()); 
# 1090
while ((__extracted < __n) && (!_Traits::eq_int_type(__c, __eof)) && (!_Traits::eq_int_type(__c, __idelim))) 
# 1093
{ 
# 1094
__str += _Traits::to_char_type(__c); 
# 1095
++__extracted; 
# 1096
__c = ((__in.rdbuf())->snextc()); 
# 1097
}  
# 1099
if (_Traits::eq_int_type(__c, __eof)) { 
# 1100
__err |= __ios_base::eofbit; } else { 
# 1101
if (_Traits::eq_int_type(__c, __idelim)) 
# 1102
{ 
# 1103
++__extracted; 
# 1104
((__in.rdbuf())->sbumpc()); 
# 1105
} else { 
# 1107
__err |= __ios_base::failbit; }  }  
# 1108
} 
# 1109
catch (__cxxabiv1::__forced_unwind &) 
# 1110
{ 
# 1111
(__in._M_setstate(__ios_base::badbit)); 
# 1112
throw; 
# 1113
} 
# 1114
catch (...) 
# 1115
{ 
# 1119
(__in._M_setstate(__ios_base::badbit)); 
# 1120
}  
# 1121
}  
# 1122
if (!__extracted) { 
# 1123
__err |= __ios_base::failbit; }  
# 1124
if (__err) { 
# 1125
(__in.setstate(__err)); }  
# 1126
return __in; 
# 1127
} 
# 1132
extern template class basic_string< char, char_traits< char> , allocator< char> > ;
# 1133
extern template basic_istream< char>  &operator>>(basic_istream< char>  & __is, basic_string< char, char_traits< char> , allocator< char> >  & __str);
# 1136
extern template basic_ostream< char>  &operator<<(basic_ostream< char>  & __os, const basic_string< char, char_traits< char> , allocator< char> >  & __str);
# 1139
extern template basic_istream< char>  &getline(basic_istream< char>  & __is, basic_string< char, char_traits< char> , allocator< char> >  & __str, char __delim);
# 1142
extern template basic_istream< char>  &getline(basic_istream< char>  & __is, basic_string< char, char_traits< char> , allocator< char> >  & __str);
# 1147
extern template class basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> > ;
# 1148
extern template basic_istream< wchar_t>  &operator>>(basic_istream< wchar_t>  & __is, basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str);
# 1151
extern template basic_ostream< wchar_t>  &operator<<(basic_ostream< wchar_t>  & __os, const basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str);
# 1154
extern template basic_istream< wchar_t>  &getline(basic_istream< wchar_t>  & __is, basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str, wchar_t __delim);
# 1157
extern template basic_istream< wchar_t>  &getline(basic_istream< wchar_t>  & __is, basic_string< wchar_t, char_traits< wchar_t> , allocator< wchar_t> >  & __str);
# 1164
}
# 43 "/usr/include/c++/4.8.2/bits/locale_classes.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 62
class locale { 
# 67
public: typedef int category; 
# 70
class facet; 
# 71
class id; 
# 72
class _Impl; 
# 74
friend class facet; 
# 75
friend class _Impl; 
# 77
template< class _Facet> friend bool has_facet(const locale &) throw(); 
# 81
template< class _Facet> friend const _Facet &use_facet(const locale &); 
# 85
template< class _Cache> friend struct __use_cache; 
# 98
static const category none = 0; 
# 99
static const category ctype = (1L << 0); 
# 100
static const category numeric = (1L << 1); 
# 101
static const category collate = (1L << 2); 
# 102
static const category time = (1L << 3); 
# 103
static const category monetary = (1L << 4); 
# 104
static const category messages = (1L << 5); 
# 105
static const category all = (((((ctype | numeric) | collate) | time) | monetary) | messages); 
# 117
locale() throw(); 
# 126
locale(const locale & __other) throw(); 
# 137
explicit locale(const char * __s); 
# 151
locale(const locale & __base, const char * __s, category __cat); 
# 164
locale(const locale & __base, const locale & __add, category __cat); 
# 177
template< class _Facet> locale(const locale & __other, _Facet * __f); 
# 181
~locale() throw(); 
# 192
const locale &operator=(const locale & __other) throw(); 
# 206
template< class _Facet> locale combine(const locale & __other) const; 
# 216
string name() const; 
# 226
bool operator==(const locale & __other) const throw(); 
# 235
bool operator!=(const locale &__other) const throw() 
# 236
{ return !this->operator==(__other); } 
# 253
template< class _Char, class _Traits, class _Alloc> bool operator()(const basic_string< _Char, _Traits, _Alloc>  & __s1, const basic_string< _Char, _Traits, _Alloc>  & __s2) const; 
# 270
static locale global(const locale & __loc); 
# 276
static const locale &classic(); 
# 280
private: _Impl *_M_impl; 
# 283
static _Impl *_S_classic; 
# 286
static _Impl *_S_global; 
# 292
static const char *const *const _S_categories; 
# 304
enum { _S_categories_size = 12}; 
# 307
static __gthread_once_t _S_once; 
# 311
explicit locale(_Impl *) throw(); 
# 314
static void _S_initialize(); 
# 317
static void _S_initialize_once() throw(); 
# 320
static category _S_normalize_category(category); 
# 323
void _M_coalesce(const locale & __base, const locale & __add, category __cat); 
# 324
}; 
# 338
class locale::facet { 
# 341
friend class locale; 
# 342
friend class _Impl; 
# 344
mutable _Atomic_word _M_refcount; 
# 347
static __c_locale _S_c_locale; 
# 350
static const char _S_c_name[2]; 
# 353
static __gthread_once_t _S_once; 
# 357
static void _S_initialize_once(); 
# 370
protected: explicit facet(size_t __refs = 0) throw() : _M_refcount((__refs) ? 1 : 0) 
# 371
{ } 
# 375
virtual ~facet(); 
# 378
static void _S_create_c_locale(__c_locale & __cloc, const char * __s, __c_locale __old = 0); 
# 382
static __c_locale _S_clone_c_locale(__c_locale & __cloc) throw(); 
# 385
static void _S_destroy_c_locale(__c_locale & __cloc); 
# 388
static __c_locale _S_lc_ctype_c_locale(__c_locale __cloc, const char * __s); 
# 393
static __c_locale _S_get_c_locale(); 
# 395
__attribute((const)) static const char *
# 396
_S_get_c_name() throw(); 
# 400
private: void _M_add_reference() const throw() 
# 401
{ __gnu_cxx::__atomic_add_dispatch(&(_M_refcount), 1); } 
# 404
void _M_remove_reference() const throw() 
# 405
{ 
# 407
; 
# 408
if (__gnu_cxx::__exchange_and_add_dispatch(&(_M_refcount), -1) == 1) 
# 409
{ 
# 410
; 
# 411
try 
# 412
{ delete this; } 
# 413
catch (...) 
# 414
{ }  
# 415
}  
# 416
} 
# 418
facet(const facet &); 
# 421
facet &operator=(const facet &); 
# 422
}; 
# 436
class locale::id { 
# 439
friend class locale; 
# 440
friend class _Impl; 
# 442
template< class _Facet> friend const _Facet &use_facet(const locale &); 
# 446
template< class _Facet> friend bool has_facet(const locale &) throw(); 
# 453
mutable size_t _M_index; 
# 456
static _Atomic_word _S_refcount; 
# 459
void operator=(const id &); 
# 461
id(const id &); 
# 467
public: id() { } 
# 470
size_t _M_id() const throw(); 
# 471
}; 
# 475
class locale::_Impl { 
# 479
friend class locale; 
# 480
friend class facet; 
# 482
template< class _Facet> friend bool has_facet(const locale &) throw(); 
# 486
template< class _Facet> friend const _Facet &use_facet(const locale &); 
# 490
template< class _Cache> friend struct __use_cache; 
# 495
_Atomic_word _M_refcount; 
# 496
const facet **_M_facets; 
# 497
size_t _M_facets_size; 
# 498
const facet **_M_caches; 
# 499
char **_M_names; 
# 500
static const id *const _S_id_ctype[]; 
# 501
static const id *const _S_id_numeric[]; 
# 502
static const id *const _S_id_collate[]; 
# 503
static const id *const _S_id_time[]; 
# 504
static const id *const _S_id_monetary[]; 
# 505
static const id *const _S_id_messages[]; 
# 506
static const id *const *const _S_facet_categories[]; 
# 509
void _M_add_reference() throw() 
# 510
{ __gnu_cxx::__atomic_add_dispatch(&(_M_refcount), 1); } 
# 513
void _M_remove_reference() throw() 
# 514
{ 
# 516
; 
# 517
if (__gnu_cxx::__exchange_and_add_dispatch(&(_M_refcount), -1) == 1) 
# 518
{ 
# 519
; 
# 520
try 
# 521
{ delete this; } 
# 522
catch (...) 
# 523
{ }  
# 524
}  
# 525
} 
# 527
_Impl(const _Impl &, size_t); 
# 528
_Impl(const char *, size_t); 
# 529
_Impl(size_t) throw(); 
# 531
~_Impl() throw(); 
# 533
_Impl(const _Impl &); 
# 536
void operator=(const _Impl &); 
# 539
bool _M_check_same_name() 
# 540
{ 
# 541
bool __ret = true; 
# 542
if ((_M_names)[1]) { 
# 544
for (size_t __i = (0); __ret && (__i < ((_S_categories_size) - 1)); ++__i) { 
# 545
__ret = (__builtin_strcmp((_M_names)[__i], (_M_names)[__i + (1)]) == 0); }  }  
# 546
return __ret; 
# 547
} 
# 550
void _M_replace_categories(const _Impl *, category); 
# 553
void _M_replace_category(const _Impl *, const id *const *); 
# 556
void _M_replace_facet(const _Impl *, const id *); 
# 559
void _M_install_facet(const id *, const facet *); 
# 561
template< class _Facet> void 
# 563
_M_init_facet(_Facet *__facet) 
# 564
{ this->_M_install_facet(&_Facet::id, __facet); } 
# 567
void _M_install_cache(const facet *, size_t); 
# 568
}; 
# 583
template< class _CharT> 
# 584
class collate : public locale::facet { 
# 590
public: typedef _CharT char_type; 
# 591
typedef basic_string< _CharT, char_traits< _CharT> , allocator< _CharT> >  string_type; 
# 597
protected: __c_locale _M_c_locale_collate; 
# 601
public: static locale::id id; 
# 611
explicit collate(size_t __refs = 0) : locale::facet(__refs), _M_c_locale_collate(_S_get_c_locale()) 
# 613
{ } 
# 625
explicit collate(__c_locale __cloc, size_t __refs = 0) : locale::facet(__refs), _M_c_locale_collate(_S_clone_c_locale(__cloc)) 
# 627
{ } 
# 642
int compare(const _CharT *__lo1, const _CharT *__hi1, const _CharT *
# 643
__lo2, const _CharT *__hi2) const 
# 644
{ return this->do_compare(__lo1, __hi1, __lo2, __hi2); } 
# 661
string_type transform(const _CharT *__lo, const _CharT *__hi) const 
# 662
{ return this->do_transform(__lo, __hi); } 
# 675
long hash(const _CharT *__lo, const _CharT *__hi) const 
# 676
{ return this->do_hash(__lo, __hi); } 
# 680
int _M_compare(const _CharT *, const _CharT *) const throw(); 
# 683
size_t _M_transform(_CharT *, const _CharT *, size_t) const throw(); 
# 688
protected: virtual ~collate() 
# 689
{ _S_destroy_c_locale(_M_c_locale_collate); } 
# 704
virtual int do_compare(const _CharT * __lo1, const _CharT * __hi1, const _CharT * __lo2, const _CharT * __hi2) const; 
# 718
virtual string_type do_transform(const _CharT * __lo, const _CharT * __hi) const; 
# 731
virtual long do_hash(const _CharT * __lo, const _CharT * __hi) const; 
# 732
}; 
# 734
template< class _CharT> locale::id 
# 735
collate< _CharT> ::id; 
# 740
template<> int collate< char> ::_M_compare(const char *, const char *) const throw(); 
# 744
template<> size_t collate< char> ::_M_transform(char *, const char *, size_t) const throw(); 
# 749
template<> int collate< wchar_t> ::_M_compare(const wchar_t *, const wchar_t *) const throw(); 
# 753
template<> size_t collate< wchar_t> ::_M_transform(wchar_t *, const wchar_t *, size_t) const throw(); 
# 757
template< class _CharT> 
# 758
class collate_byname : public collate< _CharT>  { 
# 763
public: typedef _CharT char_type; 
# 764
typedef basic_string< _CharT, char_traits< _CharT> , allocator< _CharT> >  string_type; 
# 768
explicit collate_byname(const char *__s, ::std::size_t __refs = 0) : ::std::collate< _CharT> (__refs) 
# 770
{ 
# 771
if ((__builtin_strcmp(__s, "C") != 0) && (__builtin_strcmp(__s, "POSIX") != 0)) 
# 773
{ 
# 774
(this->_S_destroy_c_locale((this->_M_c_locale_collate))); 
# 775
(this->_S_create_c_locale((this->_M_c_locale_collate), __s)); 
# 776
}  
# 777
} 
# 781
protected: virtual ~collate_byname() { } 
# 782
}; 
# 785
}
# 39 "/usr/include/c++/4.8.2/bits/locale_classes.tcc" 3
namespace std __attribute((__visibility__("default"))) { 
# 43
template< class _Facet> 
# 45
locale::locale(const locale &__other, _Facet *__f) 
# 46
{ 
# 47
(_M_impl) = (new _Impl(*(__other._M_impl), 1)); 
# 49
try 
# 50
{ (_M_impl)->_M_install_facet(&_Facet::id, __f); } 
# 51
catch (...) 
# 52
{ 
# 53
(_M_impl)->_M_remove_reference(); 
# 54
throw; 
# 55
}  
# 56
delete [] (((_M_impl)->_M_names)[0]); 
# 57
(((_M_impl)->_M_names)[0]) = (0); 
# 58
} 
# 60
template< class _Facet> locale 
# 63
locale::combine(const locale &__other) const 
# 64
{ 
# 65
_Impl *__tmp = new _Impl(*(_M_impl), 1); 
# 66
try 
# 67
{ 
# 68
__tmp->_M_replace_facet(__other._M_impl, &_Facet::id); 
# 69
} 
# 70
catch (...) 
# 71
{ 
# 72
__tmp->_M_remove_reference(); 
# 73
throw; 
# 74
}  
# 75
return ((locale)(__tmp)); 
# 76
} 
# 78
template< class _CharT, class _Traits, class _Alloc> bool 
# 81
locale::operator()(const basic_string< _CharT, _Traits, _Alloc>  &__s1, const basic_string< _CharT, _Traits, _Alloc>  &
# 82
__s2) const 
# 83
{ 
# 84
typedef std::collate< _CharT>  __collate_type; 
# 85
const __collate_type &__collate = use_facet< std::collate< _CharT> > (*this); 
# 86
return (__collate.compare((__s1.data()), (__s1.data()) + (__s1.length()), (__s2.data()), (__s2.data()) + (__s2.length()))) < 0; 
# 88
} 
# 102
template< class _Facet> bool 
# 104
has_facet(const locale &__loc) throw() 
# 105
{ 
# 106
const size_t __i = (_Facet::id._M_id)(); 
# 107
const locale::facet **__facets = (__loc._M_impl)->_M_facets; 
# 108
return (__i < ((__loc._M_impl)->_M_facets_size)) && (dynamic_cast< const _Facet *>(__facets[__i])); 
# 114
} 
# 130
template< class _Facet> const _Facet &
# 132
use_facet(const locale &__loc) 
# 133
{ 
# 134
const size_t __i = (_Facet::id._M_id)(); 
# 135
const locale::facet **__facets = (__loc._M_impl)->_M_facets; 
# 136
if ((__i >= ((__loc._M_impl)->_M_facets_size)) || (!(__facets[__i]))) { 
# 137
__throw_bad_cast(); }  
# 139
return dynamic_cast< const _Facet &>(*(__facets[__i])); 
# 143
} 
# 147
template< class _CharT> int 
# 149
collate< _CharT> ::_M_compare(const _CharT *, const _CharT *) const throw() 
# 150
{ return 0; } 
# 153
template< class _CharT> size_t 
# 155
collate< _CharT> ::_M_transform(_CharT *, const _CharT *, size_t) const throw() 
# 156
{ return 0; } 
# 158
template< class _CharT> int 
# 161
collate< _CharT> ::do_compare(const _CharT *__lo1, const _CharT *__hi1, const _CharT *
# 162
__lo2, const _CharT *__hi2) const 
# 163
{ 
# 166
const string_type __one(__lo1, __hi1); 
# 167
const string_type __two(__lo2, __hi2); 
# 169
const _CharT *__p = (__one.c_str()); 
# 170
const _CharT *__pend = (__one.data()) + (__one.length()); 
# 171
const _CharT *__q = (__two.c_str()); 
# 172
const _CharT *__qend = (__two.data()) + (__two.length()); 
# 177
for (; ;) 
# 178
{ 
# 179
const int __res = _M_compare(__p, __q); 
# 180
if (__res) { 
# 181
return __res; }  
# 183
__p += char_traits< _CharT> ::length(__p); 
# 184
__q += char_traits< _CharT> ::length(__q); 
# 185
if ((__p == __pend) && (__q == __qend)) { 
# 186
return 0; } else { 
# 187
if (__p == __pend) { 
# 188
return -1; } else { 
# 189
if (__q == __qend) { 
# 190
return 1; }  }  }  
# 192
__p++; 
# 193
__q++; 
# 194
}  
# 195
} 
# 197
template< class _CharT> typename collate< _CharT> ::string_type 
# 200
collate< _CharT> ::do_transform(const _CharT *__lo, const _CharT *__hi) const 
# 201
{ 
# 202
string_type __ret; 
# 205
const string_type __str(__lo, __hi); 
# 207
const _CharT *__p = (__str.c_str()); 
# 208
const _CharT *__pend = (__str.data()) + (__str.length()); 
# 210
size_t __len = (__hi - __lo) * 2; 
# 212
_CharT *__c = new _CharT [__len]; 
# 214
try 
# 215
{ 
# 219
for (; ;) 
# 220
{ 
# 222
size_t __res = _M_transform(__c, __p, __len); 
# 225
if (__res >= __len) 
# 226
{ 
# 227
__len = (__res + (1)); 
# 228
(delete [] __c), (__c = 0); 
# 229
__c = (new _CharT [__len]); 
# 230
__res = _M_transform(__c, __p, __len); 
# 231
}  
# 233
(__ret.append(__c, __res)); 
# 234
__p += char_traits< _CharT> ::length(__p); 
# 235
if (__p == __pend) { 
# 236
break; }  
# 238
__p++; 
# 239
(__ret.push_back(_CharT())); 
# 240
}  
# 241
} 
# 242
catch (...) 
# 243
{ 
# 244
delete [] __c; 
# 245
throw; 
# 246
}  
# 248
delete [] __c; 
# 250
return __ret; 
# 251
} 
# 253
template< class _CharT> long 
# 256
collate< _CharT> ::do_hash(const _CharT *__lo, const _CharT *__hi) const 
# 257
{ 
# 258
unsigned long __val = (0); 
# 259
for (; __lo < __hi; ++__lo) { 
# 260
__val = ((*__lo) + ((__val << 7) | (__val >> (__gnu_cxx::__numeric_traits_integer< unsigned long> ::__digits - 7)))); }  
# 264
return static_cast< long>(__val); 
# 265
} 
# 270
extern template class collate< char> ;
# 271
extern template class collate_byname< char> ;
# 273
extern template const collate< char>  &use_facet< collate< char> > (const locale &);
# 277
extern template bool has_facet< collate< char> > (const locale &) throw();
# 282
extern template class collate< wchar_t> ;
# 283
extern template class collate_byname< wchar_t> ;
# 285
extern template const collate< wchar_t>  &use_facet< collate< wchar_t> > (const locale &);
# 289
extern template bool has_facet< collate< wchar_t> > (const locale &) throw();
# 296
}
# 43 "/usr/include/c++/4.8.2/bits/ios_base.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 51
enum _Ios_Fmtflags { 
# 53
_S_boolalpha = 1, 
# 54
_S_dec, 
# 55
_S_fixed = 4, 
# 56
_S_hex = 8, 
# 57
_S_internal = 16, 
# 58
_S_left = 32, 
# 59
_S_oct = 64, 
# 60
_S_right = 128, 
# 61
_S_scientific = 256, 
# 62
_S_showbase = 512, 
# 63
_S_showpoint = 1024, 
# 64
_S_showpos = 2048, 
# 65
_S_skipws = 4096, 
# 66
_S_unitbuf = 8192, 
# 67
_S_uppercase = 16384, 
# 68
_S_adjustfield = 176, 
# 69
_S_basefield = 74, 
# 70
_S_floatfield = 260, 
# 71
_S_ios_fmtflags_end = 65536
# 72
}; 
# 75
inline _Ios_Fmtflags operator&(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
# 76
{ return (_Ios_Fmtflags)((static_cast< int>(__a)) & (static_cast< int>(__b))); } 
# 79
inline _Ios_Fmtflags operator|(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
# 80
{ return (_Ios_Fmtflags)((static_cast< int>(__a)) | (static_cast< int>(__b))); } 
# 83
inline _Ios_Fmtflags operator^(_Ios_Fmtflags __a, _Ios_Fmtflags __b) 
# 84
{ return (_Ios_Fmtflags)((static_cast< int>(__a)) ^ (static_cast< int>(__b))); } 
# 87
inline _Ios_Fmtflags operator~(_Ios_Fmtflags __a) 
# 88
{ return (_Ios_Fmtflags)(~(static_cast< int>(__a))); } 
# 91
inline const _Ios_Fmtflags &operator|=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b) 
# 92
{ return __a = ((__a | __b)); } 
# 95
inline const _Ios_Fmtflags &operator&=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b) 
# 96
{ return __a = ((__a & __b)); } 
# 99
inline const _Ios_Fmtflags &operator^=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b) 
# 100
{ return __a = ((__a ^ __b)); } 
# 103
enum _Ios_Openmode { 
# 105
_S_app = 1, 
# 106
_S_ate, 
# 107
_S_bin = 4, 
# 108
_S_in = 8, 
# 109
_S_out = 16, 
# 110
_S_trunc = 32, 
# 111
_S_ios_openmode_end = 65536
# 112
}; 
# 115
inline _Ios_Openmode operator&(_Ios_Openmode __a, _Ios_Openmode __b) 
# 116
{ return (_Ios_Openmode)((static_cast< int>(__a)) & (static_cast< int>(__b))); } 
# 119
inline _Ios_Openmode operator|(_Ios_Openmode __a, _Ios_Openmode __b) 
# 120
{ return (_Ios_Openmode)((static_cast< int>(__a)) | (static_cast< int>(__b))); } 
# 123
inline _Ios_Openmode operator^(_Ios_Openmode __a, _Ios_Openmode __b) 
# 124
{ return (_Ios_Openmode)((static_cast< int>(__a)) ^ (static_cast< int>(__b))); } 
# 127
inline _Ios_Openmode operator~(_Ios_Openmode __a) 
# 128
{ return (_Ios_Openmode)(~(static_cast< int>(__a))); } 
# 131
inline const _Ios_Openmode &operator|=(_Ios_Openmode &__a, _Ios_Openmode __b) 
# 132
{ return __a = ((__a | __b)); } 
# 135
inline const _Ios_Openmode &operator&=(_Ios_Openmode &__a, _Ios_Openmode __b) 
# 136
{ return __a = ((__a & __b)); } 
# 139
inline const _Ios_Openmode &operator^=(_Ios_Openmode &__a, _Ios_Openmode __b) 
# 140
{ return __a = ((__a ^ __b)); } 
# 143
enum _Ios_Iostate { 
# 145
_S_goodbit, 
# 146
_S_badbit, 
# 147
_S_eofbit, 
# 148
_S_failbit = 4, 
# 149
_S_ios_iostate_end = 65536
# 150
}; 
# 153
inline _Ios_Iostate operator&(_Ios_Iostate __a, _Ios_Iostate __b) 
# 154
{ return (_Ios_Iostate)((static_cast< int>(__a)) & (static_cast< int>(__b))); } 
# 157
inline _Ios_Iostate operator|(_Ios_Iostate __a, _Ios_Iostate __b) 
# 158
{ return (_Ios_Iostate)((static_cast< int>(__a)) | (static_cast< int>(__b))); } 
# 161
inline _Ios_Iostate operator^(_Ios_Iostate __a, _Ios_Iostate __b) 
# 162
{ return (_Ios_Iostate)((static_cast< int>(__a)) ^ (static_cast< int>(__b))); } 
# 165
inline _Ios_Iostate operator~(_Ios_Iostate __a) 
# 166
{ return (_Ios_Iostate)(~(static_cast< int>(__a))); } 
# 169
inline const _Ios_Iostate &operator|=(_Ios_Iostate &__a, _Ios_Iostate __b) 
# 170
{ return __a = ((__a | __b)); } 
# 173
inline const _Ios_Iostate &operator&=(_Ios_Iostate &__a, _Ios_Iostate __b) 
# 174
{ return __a = ((__a & __b)); } 
# 177
inline const _Ios_Iostate &operator^=(_Ios_Iostate &__a, _Ios_Iostate __b) 
# 178
{ return __a = ((__a ^ __b)); } 
# 181
enum _Ios_Seekdir { 
# 183
_S_beg, 
# 184
_S_cur, 
# 185
_S_end, 
# 186
_S_ios_seekdir_end = 65536
# 187
}; 
# 199
class ios_base { 
# 209
public: class failure : public exception { 
# 215
public: explicit failure(const string & __str) throw(); 
# 220
virtual ~failure() throw(); 
# 223
virtual const char *what() const throw(); 
# 226
private: string _M_msg; 
# 227
}; 
# 255
typedef _Ios_Fmtflags fmtflags; 
# 258
static const fmtflags boolalpha = _S_boolalpha; 
# 261
static const fmtflags dec = _S_dec; 
# 264
static const fmtflags fixed = _S_fixed; 
# 267
static const fmtflags hex = _S_hex; 
# 272
static const fmtflags internal = _S_internal; 
# 276
static const fmtflags left = _S_left; 
# 279
static const fmtflags oct = _S_oct; 
# 283
static const fmtflags right = _S_right; 
# 286
static const fmtflags scientific = _S_scientific; 
# 290
static const fmtflags showbase = _S_showbase; 
# 294
static const fmtflags showpoint = _S_showpoint; 
# 297
static const fmtflags showpos = _S_showpos; 
# 300
static const fmtflags skipws = _S_skipws; 
# 303
static const fmtflags unitbuf = _S_unitbuf; 
# 307
static const fmtflags uppercase = _S_uppercase; 
# 310
static const fmtflags adjustfield = _S_adjustfield; 
# 313
static const fmtflags basefield = _S_basefield; 
# 316
static const fmtflags floatfield = _S_floatfield; 
# 330
typedef _Ios_Iostate iostate; 
# 334
static const iostate badbit = _S_badbit; 
# 337
static const iostate eofbit = _S_eofbit; 
# 342
static const iostate failbit = _S_failbit; 
# 345
static const iostate goodbit = _S_goodbit; 
# 361
typedef _Ios_Openmode openmode; 
# 364
static const openmode app = _S_app; 
# 367
static const openmode ate = _S_ate; 
# 372
static const openmode binary = _S_bin; 
# 375
static const openmode in = _S_in; 
# 378
static const openmode out = _S_out; 
# 381
static const openmode trunc = _S_trunc; 
# 393
typedef _Ios_Seekdir seekdir; 
# 396
static const seekdir beg = _S_beg; 
# 399
static const seekdir cur = _S_cur; 
# 402
static const seekdir end = _S_end; 
# 405
typedef int io_state; 
# 406
typedef int open_mode; 
# 407
typedef int seek_dir; 
# 409
typedef std::streampos streampos; 
# 410
typedef std::streamoff streamoff; 
# 419
enum event { 
# 421
erase_event, 
# 422
imbue_event, 
# 423
copyfmt_event
# 424
}; 
# 436
typedef void (*event_callback)(event __e, ios_base & __b, int __i); 
# 449
void register_callback(event_callback __fn, int __index); 
# 452
protected: streamsize _M_precision; 
# 453
streamsize _M_width; 
# 454
fmtflags _M_flags; 
# 455
iostate _M_exception; 
# 456
iostate _M_streambuf_state; 
# 460
struct _Callback_list { 
# 463
_Callback_list *_M_next; 
# 464
event_callback _M_fn; 
# 465
int _M_index; 
# 466
_Atomic_word _M_refcount; 
# 468
_Callback_list(event_callback __fn, int __index, _Callback_list *
# 469
__cb) : _M_next(__cb), _M_fn(__fn), _M_index(__index), _M_refcount(0) 
# 470
{ } 
# 473
void _M_add_reference() { __gnu_cxx::__atomic_add_dispatch(&(_M_refcount), 1); } 
# 477
int _M_remove_reference() 
# 478
{ 
# 480
; 
# 481
int __res = __gnu_cxx::__exchange_and_add_dispatch(&(_M_refcount), -1); 
# 482
if (__res == 0) 
# 483
{ 
# 484
; 
# 485
}  
# 486
return __res; 
# 487
} 
# 488
}; 
# 490
_Callback_list *_M_callbacks; 
# 493
void _M_call_callbacks(event __ev) throw(); 
# 496
void _M_dispose_callbacks() throw(); 
# 499
struct _Words { 
# 501
void *_M_pword; 
# 502
long _M_iword; 
# 503
_Words() : _M_pword((0)), _M_iword((0)) { } 
# 504
}; 
# 507
_Words _M_word_zero; 
# 511
enum { _S_local_word_size = 8}; 
# 512
_Words _M_local_word[_S_local_word_size]; 
# 515
int _M_word_size; 
# 516
_Words *_M_word; 
# 519
_Words &_M_grow_words(int __index, bool __iword); 
# 522
locale _M_ios_locale; 
# 525
void _M_init() throw(); 
# 533
public: class Init { 
# 535
friend class ios_base; 
# 537
public: Init(); 
# 538
~Init(); 
# 541
private: static _Atomic_word _S_refcount; 
# 542
static bool _S_synced_with_stdio; 
# 543
}; 
# 551
fmtflags flags() const 
# 552
{ return _M_flags; } 
# 562
fmtflags flags(fmtflags __fmtfl) 
# 563
{ 
# 564
fmtflags __old = _M_flags; 
# 565
(_M_flags) = __fmtfl; 
# 566
return __old; 
# 567
} 
# 578
fmtflags setf(fmtflags __fmtfl) 
# 579
{ 
# 580
fmtflags __old = _M_flags; 
# 581
((_M_flags) |= __fmtfl); 
# 582
return __old; 
# 583
} 
# 595
fmtflags setf(fmtflags __fmtfl, fmtflags __mask) 
# 596
{ 
# 597
fmtflags __old = _M_flags; 
# 598
((_M_flags) &= ((~__mask))); 
# 599
((_M_flags) |= ((__fmtfl & __mask))); 
# 600
return __old; 
# 601
} 
# 610
void unsetf(fmtflags __mask) 
# 611
{ ((_M_flags) &= ((~__mask))); } 
# 621
streamsize precision() const 
# 622
{ return _M_precision; } 
# 630
streamsize precision(streamsize __prec) 
# 631
{ 
# 632
streamsize __old = _M_precision; 
# 633
(_M_precision) = __prec; 
# 634
return __old; 
# 635
} 
# 644
streamsize width() const 
# 645
{ return _M_width; } 
# 653
streamsize width(streamsize __wide) 
# 654
{ 
# 655
streamsize __old = _M_width; 
# 656
(_M_width) = __wide; 
# 657
return __old; 
# 658
} 
# 672
static bool sync_with_stdio(bool __sync = true); 
# 684
locale imbue(const locale & __loc) throw(); 
# 695
locale getloc() const 
# 696
{ return _M_ios_locale; } 
# 706
const locale &_M_getloc() const 
# 707
{ return _M_ios_locale; } 
# 725
static int xalloc() throw(); 
# 741
long &iword(int __ix) 
# 742
{ 
# 743
_Words &__word = (__ix < (_M_word_size)) ? (_M_word)[__ix] : this->_M_grow_words(__ix, true); 
# 745
return __word._M_iword; 
# 746
} 
# 762
void *&pword(int __ix) 
# 763
{ 
# 764
_Words &__word = (__ix < (_M_word_size)) ? (_M_word)[__ix] : this->_M_grow_words(__ix, false); 
# 766
return __word._M_pword; 
# 767
} 
# 778
virtual ~ios_base(); 
# 781
protected: ios_base() throw(); 
# 786
private: ios_base(const ios_base &); 
# 789
ios_base &operator=(const ios_base &); 
# 790
}; 
# 795
inline ios_base &boolalpha(ios_base &__base) 
# 796
{ 
# 797
__base.setf(ios_base::boolalpha); 
# 798
return __base; 
# 799
} 
# 803
inline ios_base &noboolalpha(ios_base &__base) 
# 804
{ 
# 805
__base.unsetf(ios_base::boolalpha); 
# 806
return __base; 
# 807
} 
# 811
inline ios_base &showbase(ios_base &__base) 
# 812
{ 
# 813
__base.setf(ios_base::showbase); 
# 814
return __base; 
# 815
} 
# 819
inline ios_base &noshowbase(ios_base &__base) 
# 820
{ 
# 821
__base.unsetf(ios_base::showbase); 
# 822
return __base; 
# 823
} 
# 827
inline ios_base &showpoint(ios_base &__base) 
# 828
{ 
# 829
__base.setf(ios_base::showpoint); 
# 830
return __base; 
# 831
} 
# 835
inline ios_base &noshowpoint(ios_base &__base) 
# 836
{ 
# 837
__base.unsetf(ios_base::showpoint); 
# 838
return __base; 
# 839
} 
# 843
inline ios_base &showpos(ios_base &__base) 
# 844
{ 
# 845
__base.setf(ios_base::showpos); 
# 846
return __base; 
# 847
} 
# 851
inline ios_base &noshowpos(ios_base &__base) 
# 852
{ 
# 853
__base.unsetf(ios_base::showpos); 
# 854
return __base; 
# 855
} 
# 859
inline ios_base &skipws(ios_base &__base) 
# 860
{ 
# 861
__base.setf(ios_base::skipws); 
# 862
return __base; 
# 863
} 
# 867
inline ios_base &noskipws(ios_base &__base) 
# 868
{ 
# 869
__base.unsetf(ios_base::skipws); 
# 870
return __base; 
# 871
} 
# 875
inline ios_base &uppercase(ios_base &__base) 
# 876
{ 
# 877
__base.setf(ios_base::uppercase); 
# 878
return __base; 
# 879
} 
# 883
inline ios_base &nouppercase(ios_base &__base) 
# 884
{ 
# 885
__base.unsetf(ios_base::uppercase); 
# 886
return __base; 
# 887
} 
# 891
inline ios_base &unitbuf(ios_base &__base) 
# 892
{ 
# 893
__base.setf(ios_base::unitbuf); 
# 894
return __base; 
# 895
} 
# 899
inline ios_base &nounitbuf(ios_base &__base) 
# 900
{ 
# 901
__base.unsetf(ios_base::unitbuf); 
# 902
return __base; 
# 903
} 
# 908
inline ios_base &internal(ios_base &__base) 
# 909
{ 
# 910
__base.setf(ios_base::internal, ios_base::adjustfield); 
# 911
return __base; 
# 912
} 
# 916
inline ios_base &left(ios_base &__base) 
# 917
{ 
# 918
__base.setf(ios_base::left, ios_base::adjustfield); 
# 919
return __base; 
# 920
} 
# 924
inline ios_base &right(ios_base &__base) 
# 925
{ 
# 926
__base.setf(ios_base::right, ios_base::adjustfield); 
# 927
return __base; 
# 928
} 
# 933
inline ios_base &dec(ios_base &__base) 
# 934
{ 
# 935
__base.setf(ios_base::dec, ios_base::basefield); 
# 936
return __base; 
# 937
} 
# 941
inline ios_base &hex(ios_base &__base) 
# 942
{ 
# 943
__base.setf(ios_base::hex, ios_base::basefield); 
# 944
return __base; 
# 945
} 
# 949
inline ios_base &oct(ios_base &__base) 
# 950
{ 
# 951
__base.setf(ios_base::oct, ios_base::basefield); 
# 952
return __base; 
# 953
} 
# 958
inline ios_base &fixed(ios_base &__base) 
# 959
{ 
# 960
__base.setf(ios_base::fixed, ios_base::floatfield); 
# 961
return __base; 
# 962
} 
# 966
inline ios_base &scientific(ios_base &__base) 
# 967
{ 
# 968
__base.setf(ios_base::scientific, ios_base::floatfield); 
# 969
return __base; 
# 970
} 
# 973
}
# 45 "/usr/include/c++/4.8.2/streambuf" 3
namespace std __attribute((__visibility__("default"))) { 
# 49
template< class _CharT, class _Traits> streamsize __copy_streambufs_eof(basic_streambuf< _CharT, _Traits>  *, basic_streambuf< _CharT, _Traits>  *, bool &); 
# 119
template< class _CharT, class _Traits> 
# 120
class basic_streambuf { 
# 129
public: typedef _CharT char_type; 
# 130
typedef _Traits traits_type; 
# 131
typedef typename _Traits::int_type int_type; 
# 132
typedef typename _Traits::pos_type pos_type; 
# 133
typedef typename _Traits::off_type off_type; 
# 138
typedef basic_streambuf __streambuf_type; 
# 141
friend class basic_ios< _CharT, _Traits> ; 
# 142
friend class basic_istream< _CharT, _Traits> ; 
# 143
friend class basic_ostream< _CharT, _Traits> ; 
# 144
friend class istreambuf_iterator< _CharT, _Traits> ; 
# 145
friend class ostreambuf_iterator< _CharT, _Traits> ; 
# 148
friend streamsize __copy_streambufs_eof<> (basic_streambuf *, basic_streambuf *, bool &); 
# 150
template< bool _IsMove, class _CharT2> friend typename __gnu_cxx::__enable_if< __is_char< _CharT2> ::__value, _CharT2 *> ::__type __copy_move_a2(istreambuf_iterator< _CharT2, char_traits< _CharT2> > , istreambuf_iterator< _CharT2, char_traits< _CharT2> > , _CharT2 *); 
# 156
template< class _CharT2> friend typename __gnu_cxx::__enable_if< __is_char< _CharT2> ::__value, istreambuf_iterator< _CharT2, char_traits< _CharT2> > > ::__type find(istreambuf_iterator< _CharT2, char_traits< _CharT2> > , istreambuf_iterator< _CharT2, char_traits< _CharT2> > , const _CharT2 &); 
# 162
template< class _CharT2, class _Traits2> friend basic_istream< _CharT2, _Traits2>  &operator>>(basic_istream< _CharT2, _Traits2>  &, _CharT2 *); 
# 166
template< class _CharT2, class _Traits2, class _Alloc> friend basic_istream< _CharT2, _Traits2>  &operator>>(basic_istream< _CharT2, _Traits2>  &, basic_string< _CharT2, _Traits2, _Alloc>  &); 
# 171
template< class _CharT2, class _Traits2, class _Alloc> friend basic_istream< _CharT2, _Traits2>  &getline(basic_istream< _CharT2, _Traits2>  &, basic_string< _CharT2, _Traits2, _Alloc>  &, _CharT2); 
# 184
protected: char_type *_M_in_beg; 
# 185
char_type *_M_in_cur; 
# 186
char_type *_M_in_end; 
# 187
char_type *_M_out_beg; 
# 188
char_type *_M_out_cur; 
# 189
char_type *_M_out_end; 
# 192
locale _M_buf_locale; 
# 197
public: virtual ~basic_streambuf() 
# 198
{ } 
# 209
locale pubimbue(const locale &__loc) 
# 210
{ 
# 211
locale __tmp(this->getloc()); 
# 212
this->imbue(__loc); 
# 213
((_M_buf_locale) = __loc); 
# 214
return __tmp; 
# 215
} 
# 226
locale getloc() const 
# 227
{ return _M_buf_locale; } 
# 239
basic_streambuf *pubsetbuf(char_type *__s, streamsize __n) 
# 240
{ return this->setbuf(__s, __n); } 
# 251
pos_type pubseekoff(off_type __off, ios_base::seekdir __way, ios_base::openmode 
# 252
__mode = (ios_base::in | ios_base::out)) 
# 253
{ return this->seekoff(__off, __way, __mode); } 
# 263
pos_type pubseekpos(pos_type __sp, ios_base::openmode 
# 264
__mode = (ios_base::in | ios_base::out)) 
# 265
{ return this->seekpos(__sp, __mode); } 
# 271
int pubsync() { return this->sync(); } 
# 284
streamsize in_avail() 
# 285
{ 
# 286
const streamsize __ret = this->egptr() - this->gptr(); 
# 287
return (__ret) ? __ret : this->showmanyc(); 
# 288
} 
# 298
int_type snextc() 
# 299
{ 
# 300
int_type __ret = traits_type::eof(); 
# 301
if (__builtin_expect(!traits_type::eq_int_type(this->sbumpc(), __ret), true)) { 
# 303
__ret = this->sgetc(); }  
# 304
return __ret; 
# 305
} 
# 316
int_type sbumpc() 
# 317
{ 
# 318
int_type __ret; 
# 319
if (__builtin_expect(this->gptr() < this->egptr(), true)) 
# 320
{ 
# 321
__ret = traits_type::to_int_type(*this->gptr()); 
# 322
this->gbump(1); 
# 323
} else { 
# 325
__ret = this->uflow(); }  
# 326
return __ret; 
# 327
} 
# 338
int_type sgetc() 
# 339
{ 
# 340
int_type __ret; 
# 341
if (__builtin_expect(this->gptr() < this->egptr(), true)) { 
# 342
__ret = traits_type::to_int_type(*this->gptr()); } else { 
# 344
__ret = this->underflow(); }  
# 345
return __ret; 
# 346
} 
# 357
streamsize sgetn(char_type *__s, streamsize __n) 
# 358
{ return this->xsgetn(__s, __n); } 
# 372
int_type sputbackc(char_type __c) 
# 373
{ 
# 374
int_type __ret; 
# 375
const bool __testpos = this->eback() < this->gptr(); 
# 376
if (__builtin_expect((!__testpos) || (!traits_type::eq(__c, this->gptr()[-1])), false)) { 
# 378
__ret = this->pbackfail(traits_type::to_int_type(__c)); } else 
# 380
{ 
# 381
this->gbump(-1); 
# 382
__ret = traits_type::to_int_type(*this->gptr()); 
# 383
}  
# 384
return __ret; 
# 385
} 
# 397
int_type sungetc() 
# 398
{ 
# 399
int_type __ret; 
# 400
if (__builtin_expect(this->eback() < this->gptr(), true)) 
# 401
{ 
# 402
this->gbump(-1); 
# 403
__ret = traits_type::to_int_type(*this->gptr()); 
# 404
} else { 
# 406
__ret = this->pbackfail(); }  
# 407
return __ret; 
# 408
} 
# 424
int_type sputc(char_type __c) 
# 425
{ 
# 426
int_type __ret; 
# 427
if (__builtin_expect(this->pptr() < this->epptr(), true)) 
# 428
{ 
# 429
(*this->pptr()) = __c; 
# 430
this->pbump(1); 
# 431
__ret = traits_type::to_int_type(__c); 
# 432
} else { 
# 434
__ret = this->overflow(traits_type::to_int_type(__c)); }  
# 435
return __ret; 
# 436
} 
# 450
streamsize sputn(const char_type *__s, streamsize __n) 
# 451
{ return this->xsputn(__s, __n); } 
# 463
protected: basic_streambuf() : _M_in_beg((0)), _M_in_cur((0)), _M_in_end((0)), _M_out_beg((0)), _M_out_cur((0)), _M_out_end((0)), _M_buf_locale(locale()) 
# 467
{ } 
# 482
char_type *eback() const { return _M_in_beg; } 
# 485
char_type *gptr() const { return _M_in_cur; } 
# 488
char_type *egptr() const { return _M_in_end; } 
# 498
void gbump(int __n) { (_M_in_cur) += __n; } 
# 509
void setg(char_type *__gbeg, char_type *__gnext, char_type *__gend) 
# 510
{ 
# 511
(_M_in_beg) = __gbeg; 
# 512
(_M_in_cur) = __gnext; 
# 513
(_M_in_end) = __gend; 
# 514
} 
# 529
char_type *pbase() const { return _M_out_beg; } 
# 532
char_type *pptr() const { return _M_out_cur; } 
# 535
char_type *epptr() const { return _M_out_end; } 
# 545
void pbump(int __n) { (_M_out_cur) += __n; } 
# 555
void setp(char_type *__pbeg, char_type *__pend) 
# 556
{ 
# 557
(_M_out_beg) = ((_M_out_cur) = __pbeg); 
# 558
(_M_out_end) = __pend; 
# 559
} 
# 576
virtual void imbue(const locale &__loc) 
# 577
{ } 
# 591
virtual basic_streambuf *setbuf(char_type *, streamsize) 
# 592
{ return this; } 
# 602
virtual pos_type seekoff(off_type, ios_base::seekdir, ios_base::openmode = (ios_base::in | ios_base::out)) 
# 604
{ return (pos_type)((off_type)(-1)); } 
# 614
virtual pos_type seekpos(pos_type, ios_base::openmode = (ios_base::in | ios_base::out)) 
# 616
{ return (pos_type)((off_type)(-1)); } 
# 627
virtual int sync() { return 0; } 
# 649
virtual streamsize showmanyc() { return 0; } 
# 665
virtual streamsize xsgetn(char_type * __s, streamsize __n); 
# 687
virtual int_type underflow() 
# 688
{ return traits_type::eof(); } 
# 700
virtual int_type uflow() 
# 701
{ 
# 702
int_type __ret = traits_type::eof(); 
# 703
const bool __testeof = traits_type::eq_int_type(this->underflow(), __ret); 
# 705
if (!__testeof) 
# 706
{ 
# 707
__ret = traits_type::to_int_type(*this->gptr()); 
# 708
this->gbump(1); 
# 709
}  
# 710
return __ret; 
# 711
} 
# 724
virtual int_type pbackfail(int_type __c = traits_type::eof()) 
# 725
{ return traits_type::eof(); } 
# 742
virtual streamsize xsputn(const char_type * __s, streamsize __n); 
# 768
virtual int_type overflow(int_type __c = traits_type::eof()) 
# 769
{ return traits_type::eof(); } 
# 783
public: void stossc() 
# 784
{ 
# 785
if (this->gptr() < this->egptr()) { 
# 786
this->gbump(1); } else { 
# 788
this->uflow(); }  
# 789
} 
# 794
void __safe_gbump(streamsize __n) { (_M_in_cur) += __n; } 
# 797
void __safe_pbump(streamsize __n) { (_M_out_cur) += __n; } 
# 802
private: basic_streambuf(const basic_streambuf &__sb) : _M_in_beg(__sb._M_in_beg), _M_in_cur(__sb._M_in_cur), _M_in_end(__sb._M_in_end), _M_out_beg(__sb._M_out_beg), _M_out_cur(__sb._M_out_cur), _M_out_end(__sb._M_out_end), _M_buf_locale(__sb._M_buf_locale) 
# 807
{ } 
# 810
basic_streambuf &operator=(const basic_streambuf &__sb) 
# 811
{ 
# 812
(_M_in_beg) = (__sb._M_in_beg); 
# 813
(_M_in_cur) = (__sb._M_in_cur); 
# 814
(_M_in_end) = (__sb._M_in_end); 
# 815
(_M_out_beg) = (__sb._M_out_beg); 
# 816
(_M_out_cur) = (__sb._M_out_cur); 
# 817
(_M_out_end) = (__sb._M_out_end); 
# 818
((_M_buf_locale) = (__sb._M_buf_locale)); 
# 819
return *this; 
# 820
} 
# 821
}; 
# 826
template<> streamsize __copy_streambufs_eof(basic_streambuf< char, char_traits< char> >  * __sbin, basic_streambuf< char, char_traits< char> >  * __sbout, bool & __ineof); 
# 831
template<> streamsize __copy_streambufs_eof(basic_streambuf< wchar_t, char_traits< wchar_t> >  * __sbin, basic_streambuf< wchar_t, char_traits< wchar_t> >  * __sbout, bool & __ineof); 
# 836
}
# 39 "/usr/include/c++/4.8.2/bits/streambuf.tcc" 3
namespace std __attribute((__visibility__("default"))) { 
# 43
template< class _CharT, class _Traits> streamsize 
# 46
basic_streambuf< _CharT, _Traits> ::xsgetn(char_type *__s, streamsize __n) 
# 47
{ 
# 48
streamsize __ret = (0); 
# 49
while (__ret < __n) 
# 50
{ 
# 51
const streamsize __buf_len = this->egptr() - this->gptr(); 
# 52
if (__buf_len) 
# 53
{ 
# 54
const streamsize __remaining = __n - __ret; 
# 55
const streamsize __len = std::min(__buf_len, __remaining); 
# 56
traits_type::copy(__s, this->gptr(), __len); 
# 57
__ret += __len; 
# 58
__s += __len; 
# 59
this->__safe_gbump(__len); 
# 60
}  
# 62
if (__ret < __n) 
# 63
{ 
# 64
const int_type __c = this->uflow(); 
# 65
if (!traits_type::eq_int_type(__c, traits_type::eof())) 
# 66
{ 
# 67
traits_type::assign(*(__s++), traits_type::to_char_type(__c)); 
# 68
++__ret; 
# 69
} else { 
# 71
break; }  
# 72
}  
# 73
}  
# 74
return __ret; 
# 75
} 
# 77
template< class _CharT, class _Traits> streamsize 
# 80
basic_streambuf< _CharT, _Traits> ::xsputn(const char_type *__s, streamsize __n) 
# 81
{ 
# 82
streamsize __ret = (0); 
# 83
while (__ret < __n) 
# 84
{ 
# 85
const streamsize __buf_len = this->epptr() - this->pptr(); 
# 86
if (__buf_len) 
# 87
{ 
# 88
const streamsize __remaining = __n - __ret; 
# 89
const streamsize __len = std::min(__buf_len, __remaining); 
# 90
traits_type::copy(this->pptr(), __s, __len); 
# 91
__ret += __len; 
# 92
__s += __len; 
# 93
this->__safe_pbump(__len); 
# 94
}  
# 96
if (__ret < __n) 
# 97
{ 
# 98
int_type __c = this->overflow(traits_type::to_int_type(*__s)); 
# 99
if (!traits_type::eq_int_type(__c, traits_type::eof())) 
# 100
{ 
# 101
++__ret; 
# 102
++__s; 
# 103
} else { 
# 105
break; }  
# 106
}  
# 107
}  
# 108
return __ret; 
# 109
} 
# 114
template< class _CharT, class _Traits> streamsize 
# 116
__copy_streambufs_eof(basic_streambuf< _CharT, _Traits>  *__sbin, basic_streambuf< _CharT, _Traits>  *
# 117
__sbout, bool &
# 118
__ineof) 
# 119
{ 
# 120
streamsize __ret = (0); 
# 121
__ineof = true; 
# 122
typename _Traits::int_type __c = (__sbin->sgetc()); 
# 123
while (!_Traits::eq_int_type(__c, _Traits::eof())) 
# 124
{ 
# 125
__c = (__sbout->sputc(_Traits::to_char_type(__c))); 
# 126
if (_Traits::eq_int_type(__c, _Traits::eof())) 
# 127
{ 
# 128
__ineof = false; 
# 129
break; 
# 130
}  
# 131
++__ret; 
# 132
__c = (__sbin->snextc()); 
# 133
}  
# 134
return __ret; 
# 135
} 
# 137
template< class _CharT, class _Traits> inline streamsize 
# 139
__copy_streambufs(basic_streambuf< _CharT, _Traits>  *__sbin, basic_streambuf< _CharT, _Traits>  *
# 140
__sbout) 
# 141
{ 
# 142
bool __ineof; 
# 143
return __copy_streambufs_eof(__sbin, __sbout, __ineof); 
# 144
} 
# 149
extern template class basic_streambuf< char, char_traits< char> > ;
# 150
extern template streamsize __copy_streambufs(basic_streambuf< char, char_traits< char> >  * __sbin, basic_streambuf< char, char_traits< char> >  * __sbout);
# 154
extern template streamsize __copy_streambufs_eof< char, char_traits< char> > (basic_streambuf< char, char_traits< char> >  *, basic_streambuf< char, char_traits< char> >  *, bool &);
# 160
extern template class basic_streambuf< wchar_t, char_traits< wchar_t> > ;
# 161
extern template streamsize __copy_streambufs(basic_streambuf< wchar_t, char_traits< wchar_t> >  * __sbin, basic_streambuf< wchar_t, char_traits< wchar_t> >  * __sbout);
# 165
extern template streamsize __copy_streambufs_eof< wchar_t, char_traits< wchar_t> > (basic_streambuf< wchar_t, char_traits< wchar_t> >  *, basic_streambuf< wchar_t, char_traits< wchar_t> >  *, bool &);
# 173
}
# 52 "/usr/include/wctype.h" 3
typedef unsigned long wctype_t; 
# 72
enum { 
# 73
__ISwupper, 
# 74
__ISwlower, 
# 75
__ISwalpha, 
# 76
__ISwdigit, 
# 77
__ISwxdigit, 
# 78
__ISwspace, 
# 79
__ISwprint, 
# 80
__ISwgraph, 
# 81
__ISwblank, 
# 82
__ISwcntrl, 
# 83
__ISwpunct, 
# 84
__ISwalnum, 
# 86
_ISwupper = 16777216, 
# 87
_ISwlower = 33554432, 
# 88
_ISwalpha = 67108864, 
# 89
_ISwdigit = 134217728, 
# 90
_ISwxdigit = 268435456, 
# 91
_ISwspace = 536870912, 
# 92
_ISwprint = 1073741824, 
# 93
_ISwgraph = (-2147483647-1), 
# 94
_ISwblank = 65536, 
# 95
_ISwcntrl = 131072, 
# 96
_ISwpunct = 262144, 
# 97
_ISwalnum = 524288
# 98
}; 
# 102
extern "C" {
# 111
extern int iswalnum(wint_t __wc) throw(); 
# 117
extern int iswalpha(wint_t __wc) throw(); 
# 120
extern int iswcntrl(wint_t __wc) throw(); 
# 124
extern int iswdigit(wint_t __wc) throw(); 
# 128
extern int iswgraph(wint_t __wc) throw(); 
# 133
extern int iswlower(wint_t __wc) throw(); 
# 136
extern int iswprint(wint_t __wc) throw(); 
# 141
extern int iswpunct(wint_t __wc) throw(); 
# 146
extern int iswspace(wint_t __wc) throw(); 
# 151
extern int iswupper(wint_t __wc) throw(); 
# 156
extern int iswxdigit(wint_t __wc) throw(); 
# 162
extern int iswblank(wint_t __wc) throw(); 
# 171
extern wctype_t wctype(const char * __property) throw(); 
# 175
extern int iswctype(wint_t __wc, wctype_t __desc) throw(); 
# 186
typedef const __int32_t *wctrans_t; 
# 194
extern wint_t towlower(wint_t __wc) throw(); 
# 197
extern wint_t towupper(wint_t __wc) throw(); 
# 200
}
# 213
extern "C" {
# 218
extern wctrans_t wctrans(const char * __property) throw(); 
# 221
extern wint_t towctrans(wint_t __wc, wctrans_t __desc) throw(); 
# 230
extern int iswalnum_l(wint_t __wc, __locale_t __locale) throw(); 
# 236
extern int iswalpha_l(wint_t __wc, __locale_t __locale) throw(); 
# 239
extern int iswcntrl_l(wint_t __wc, __locale_t __locale) throw(); 
# 243
extern int iswdigit_l(wint_t __wc, __locale_t __locale) throw(); 
# 247
extern int iswgraph_l(wint_t __wc, __locale_t __locale) throw(); 
# 252
extern int iswlower_l(wint_t __wc, __locale_t __locale) throw(); 
# 255
extern int iswprint_l(wint_t __wc, __locale_t __locale) throw(); 
# 260
extern int iswpunct_l(wint_t __wc, __locale_t __locale) throw(); 
# 265
extern int iswspace_l(wint_t __wc, __locale_t __locale) throw(); 
# 270
extern int iswupper_l(wint_t __wc, __locale_t __locale) throw(); 
# 275
extern int iswxdigit_l(wint_t __wc, __locale_t __locale) throw(); 
# 280
extern int iswblank_l(wint_t __wc, __locale_t __locale) throw(); 
# 284
extern wctype_t wctype_l(const char * __property, __locale_t __locale) throw(); 
# 289
extern int iswctype_l(wint_t __wc, wctype_t __desc, __locale_t __locale) throw(); 
# 298
extern wint_t towlower_l(wint_t __wc, __locale_t __locale) throw(); 
# 301
extern wint_t towupper_l(wint_t __wc, __locale_t __locale) throw(); 
# 305
extern wctrans_t wctrans_l(const char * __property, __locale_t __locale) throw(); 
# 309
extern wint_t towctrans_l(wint_t __wc, wctrans_t __desc, __locale_t __locale) throw(); 
# 314
}
# 80 "/usr/include/c++/4.8.2/cwctype" 3
namespace std { 
# 82
using ::wctrans_t;
# 83
using ::wctype_t;
# 86
using ::iswalnum;
# 87
using ::iswalpha;
# 89
using ::iswblank;
# 91
using ::iswcntrl;
# 92
using ::iswctype;
# 93
using ::iswdigit;
# 94
using ::iswgraph;
# 95
using ::iswlower;
# 96
using ::iswprint;
# 97
using ::iswpunct;
# 98
using ::iswspace;
# 99
using ::iswupper;
# 100
using ::iswxdigit;
# 101
using ::towctrans;
# 102
using ::towlower;
# 103
using ::towupper;
# 104
using ::wctrans;
# 105
using ::wctype;
# 106
}
# 36 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/ctype_base.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 41
struct ctype_base { 
# 44
typedef const int *__to_type; 
# 48
typedef unsigned short mask; 
# 49
static const mask upper = (_ISupper); 
# 50
static const mask lower = (_ISlower); 
# 51
static const mask alpha = (_ISalpha); 
# 52
static const mask digit = (_ISdigit); 
# 53
static const mask xdigit = (_ISxdigit); 
# 54
static const mask space = (_ISspace); 
# 55
static const mask print = (_ISprint); 
# 56
static const mask graph = (((_ISalpha) | (_ISdigit)) | (_ISpunct)); 
# 57
static const mask cntrl = (_IScntrl); 
# 58
static const mask punct = (_ISpunct); 
# 59
static const mask alnum = ((_ISalpha) | (_ISdigit)); 
# 60
}; 
# 63
}
# 38 "/usr/include/c++/4.8.2/bits/streambuf_iterator.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 49
template< class _CharT, class _Traits> 
# 50
class istreambuf_iterator : public iterator< input_iterator_tag, _CharT, typename _Traits::off_type, _CharT *, _CharT &>  { 
# 64
public: typedef _CharT char_type; 
# 65
typedef _Traits traits_type; 
# 66
typedef typename _Traits::int_type int_type; 
# 67
typedef basic_streambuf< _CharT, _Traits>  streambuf_type; 
# 68
typedef basic_istream< _CharT, _Traits>  istream_type; 
# 71
template< class _CharT2> friend typename ::__gnu_cxx::__enable_if< __is_char< _CharT2> ::__value, ostreambuf_iterator< _CharT2, char_traits< _CharT2> > > ::__type copy(::std::istreambuf_iterator< _CharT2, char_traits< _CharT2> > , ::std::istreambuf_iterator< _CharT2, char_traits< _CharT2> > , ostreambuf_iterator< _CharT2, char_traits< _CharT2> > ); 
# 77
template< bool _IsMove, class _CharT2> friend typename ::__gnu_cxx::__enable_if< __is_char< _CharT2> ::__value, _CharT2 *> ::__type __copy_move_a2(::std::istreambuf_iterator< _CharT2, char_traits< _CharT2> > , ::std::istreambuf_iterator< _CharT2, char_traits< _CharT2> > , _CharT2 *); 
# 83
template< class _CharT2> friend typename ::__gnu_cxx::__enable_if< __is_char< _CharT2> ::__value, ::std::istreambuf_iterator< _CharT2, char_traits< _CharT2> > > ::__type find(::std::istreambuf_iterator< _CharT2, char_traits< _CharT2> > , ::std::istreambuf_iterator< _CharT2, char_traits< _CharT2> > , const _CharT2 &); 
# 97
private: mutable streambuf_type *_M_sbuf; 
# 98
mutable int_type _M_c; 
# 102
public: istreambuf_iterator() throw() : _M_sbuf((0)), _M_c(traits_type::eof()) 
# 103
{ } 
# 112
istreambuf_iterator(istream_type &__s) throw() : _M_sbuf((__s.rdbuf())), _M_c(traits_type::eof()) 
# 113
{ } 
# 116
istreambuf_iterator(streambuf_type *__s) throw() : _M_sbuf(__s), _M_c(traits_type::eof()) 
# 117
{ } 
# 123
char_type operator*() const 
# 124
{ 
# 132
return traits_type::to_char_type(_M_get()); 
# 133
} 
# 137
istreambuf_iterator &operator++() 
# 138
{ 
# 141
; 
# 142
if (_M_sbuf) 
# 143
{ 
# 144
((_M_sbuf)->sbumpc()); 
# 145
(_M_c) = traits_type::eof(); 
# 146
}  
# 147
return *this; 
# 148
} 
# 152
istreambuf_iterator operator++(int) 
# 153
{ 
# 156
; 
# 158
istreambuf_iterator __old = *this; 
# 159
if (_M_sbuf) 
# 160
{ 
# 161
(__old._M_c) = ((_M_sbuf)->sbumpc()); 
# 162
(_M_c) = traits_type::eof(); 
# 163
}  
# 164
return __old; 
# 165
} 
# 172
bool equal(const istreambuf_iterator &__b) const 
# 173
{ return _M_at_eof() == __b._M_at_eof(); } 
# 177
private: int_type _M_get() const 
# 178
{ 
# 179
const int_type __eof = traits_type::eof(); 
# 180
int_type __ret = __eof; 
# 181
if (_M_sbuf) 
# 182
{ 
# 183
if (!traits_type::eq_int_type(_M_c, __eof)) { 
# 184
__ret = (_M_c); } else { 
# 185
if (!traits_type::eq_int_type(__ret = ((_M_sbuf)->sgetc()), __eof)) { 
# 187
(_M_c) = __ret; } else { 
# 189
(_M_sbuf) = 0; }  }  
# 190
}  
# 191
return __ret; 
# 192
} 
# 195
bool _M_at_eof() const 
# 196
{ 
# 197
const int_type __eof = traits_type::eof(); 
# 198
return traits_type::eq_int_type(_M_get(), __eof); 
# 199
} 
# 200
}; 
# 202
template< class _CharT, class _Traits> inline bool 
# 204
operator==(const istreambuf_iterator< _CharT, _Traits>  &__a, const istreambuf_iterator< _CharT, _Traits>  &
# 205
__b) 
# 206
{ return (__a.equal(__b)); } 
# 208
template< class _CharT, class _Traits> inline bool 
# 210
operator!=(const istreambuf_iterator< _CharT, _Traits>  &__a, const istreambuf_iterator< _CharT, _Traits>  &
# 211
__b) 
# 212
{ return !(__a.equal(__b)); } 
# 215
template< class _CharT, class _Traits> 
# 216
class ostreambuf_iterator : public iterator< output_iterator_tag, void, void, void, void>  { 
# 223
public: typedef _CharT char_type; 
# 224
typedef _Traits traits_type; 
# 225
typedef basic_streambuf< _CharT, _Traits>  streambuf_type; 
# 226
typedef basic_ostream< _CharT, _Traits>  ostream_type; 
# 229
template< class _CharT2> friend typename __gnu_cxx::__enable_if< __is_char< _CharT2> ::__value, std::ostreambuf_iterator< _CharT2, char_traits< _CharT2> > > ::__type copy(istreambuf_iterator< _CharT2, char_traits< _CharT2> > , istreambuf_iterator< _CharT2, char_traits< _CharT2> > , std::ostreambuf_iterator< _CharT2, char_traits< _CharT2> > ); 
# 236
private: streambuf_type *_M_sbuf; 
# 237
bool _M_failed; 
# 241
public: ostreambuf_iterator(ostream_type &__s) throw() : _M_sbuf((__s.rdbuf())), _M_failed(!(_M_sbuf)) 
# 242
{ } 
# 245
ostreambuf_iterator(streambuf_type *__s) throw() : _M_sbuf(__s), _M_failed(!(_M_sbuf)) 
# 246
{ } 
# 250
ostreambuf_iterator &operator=(_CharT __c) 
# 251
{ 
# 252
if ((!(_M_failed)) && _Traits::eq_int_type(((_M_sbuf)->sputc(__c)), _Traits::eof())) { 
# 254
(_M_failed) = true; }  
# 255
return *this; 
# 256
} 
# 260
ostreambuf_iterator &operator*() 
# 261
{ return *this; } 
# 265
ostreambuf_iterator &operator++(int) 
# 266
{ return *this; } 
# 270
ostreambuf_iterator &operator++() 
# 271
{ return *this; } 
# 275
bool failed() const throw() 
# 276
{ return _M_failed; } 
# 279
ostreambuf_iterator &_M_put(const _CharT *__ws, streamsize __len) 
# 280
{ 
# 281
if ((__builtin_expect(!(_M_failed), true)) && (__builtin_expect(((this->_M_sbuf)->sputn(__ws, __len)) != __len, false))) { 
# 284
(_M_failed) = true; }  
# 285
return *this; 
# 286
} 
# 287
}; 
# 290
template< class _CharT> typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, ostreambuf_iterator< _CharT, char_traits< _CharT> > > ::__type 
# 293
copy(istreambuf_iterator< _CharT, char_traits< _CharT> >  __first, istreambuf_iterator< _CharT, char_traits< _CharT> >  
# 294
__last, ostreambuf_iterator< _CharT, char_traits< _CharT> >  
# 295
__result) 
# 296
{ 
# 297
if ((__first._M_sbuf) && (!(__last._M_sbuf)) && (!(__result._M_failed))) 
# 298
{ 
# 299
bool __ineof; 
# 300
__copy_streambufs_eof((__first._M_sbuf), (__result._M_sbuf), __ineof); 
# 301
if (!__ineof) { 
# 302
(__result._M_failed) = true; }  
# 303
}  
# 304
return __result; 
# 305
} 
# 307
template< bool _IsMove, class _CharT> typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, ostreambuf_iterator< _CharT, char_traits< _CharT> > > ::__type 
# 310
__copy_move_a2(_CharT *__first, _CharT *__last, ostreambuf_iterator< _CharT, char_traits< _CharT> >  
# 311
__result) 
# 312
{ 
# 313
const streamsize __num = __last - __first; 
# 314
if (__num > (0)) { 
# 315
(__result._M_put(__first, __num)); }  
# 316
return __result; 
# 317
} 
# 319
template< bool _IsMove, class _CharT> typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, ostreambuf_iterator< _CharT, char_traits< _CharT> > > ::__type 
# 322
__copy_move_a2(const _CharT *__first, const _CharT *__last, ostreambuf_iterator< _CharT, char_traits< _CharT> >  
# 323
__result) 
# 324
{ 
# 325
const streamsize __num = __last - __first; 
# 326
if (__num > (0)) { 
# 327
(__result._M_put(__first, __num)); }  
# 328
return __result; 
# 329
} 
# 331
template< bool _IsMove, class _CharT> typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, _CharT *> ::__type 
# 334
__copy_move_a2(istreambuf_iterator< _CharT, char_traits< _CharT> >  __first, istreambuf_iterator< _CharT, char_traits< _CharT> >  
# 335
__last, _CharT *__result) 
# 336
{ 
# 337
typedef istreambuf_iterator< _CharT, char_traits< _CharT> >  __is_iterator_type; 
# 338
typedef typename istreambuf_iterator< _CharT, char_traits< _CharT> > ::traits_type traits_type; 
# 339
typedef typename istreambuf_iterator< _CharT, char_traits< _CharT> > ::streambuf_type streambuf_type; 
# 340
typedef typename istreambuf_iterator< _CharT, char_traits< _CharT> > ::traits_type::int_type int_type; 
# 342
if ((__first._M_sbuf) && (!(__last._M_sbuf))) 
# 343
{ 
# 344
streambuf_type *__sb = ((__first._M_sbuf)); 
# 345
int_type __c = (__sb->sgetc()); 
# 346
while (!traits_type::eq_int_type(__c, traits_type::eof())) 
# 347
{ 
# 348
const streamsize __n = (__sb->egptr()) - (__sb->gptr()); 
# 349
if (__n > (1)) 
# 350
{ 
# 351
traits_type::copy(__result, (__sb->gptr()), __n); 
# 352
(__sb->__safe_gbump(__n)); 
# 353
__result += __n; 
# 354
__c = (__sb->underflow()); 
# 355
} else 
# 357
{ 
# 358
(*(__result++)) = traits_type::to_char_type(__c); 
# 359
__c = (__sb->snextc()); 
# 360
}  
# 361
}  
# 362
}  
# 363
return __result; 
# 364
} 
# 366
template< class _CharT> typename __gnu_cxx::__enable_if< __is_char< _CharT> ::__value, istreambuf_iterator< _CharT, char_traits< _CharT> > > ::__type 
# 369
find(istreambuf_iterator< _CharT, char_traits< _CharT> >  __first, istreambuf_iterator< _CharT, char_traits< _CharT> >  
# 370
__last, const _CharT &__val) 
# 371
{ 
# 372
typedef istreambuf_iterator< _CharT, char_traits< _CharT> >  __is_iterator_type; 
# 373
typedef typename istreambuf_iterator< _CharT, char_traits< _CharT> > ::traits_type traits_type; 
# 374
typedef typename istreambuf_iterator< _CharT, char_traits< _CharT> > ::streambuf_type streambuf_type; 
# 375
typedef typename istreambuf_iterator< _CharT, char_traits< _CharT> > ::traits_type::int_type int_type; 
# 377
if ((__first._M_sbuf) && (!(__last._M_sbuf))) 
# 378
{ 
# 379
const int_type __ival = traits_type::to_int_type(__val); 
# 380
streambuf_type *__sb = ((__first._M_sbuf)); 
# 381
int_type __c = (__sb->sgetc()); 
# 382
while ((!traits_type::eq_int_type(__c, traits_type::eof())) && (!traits_type::eq_int_type(__c, __ival))) 
# 384
{ 
# 385
streamsize __n = (__sb->egptr()) - (__sb->gptr()); 
# 386
if (__n > (1)) 
# 387
{ 
# 388
const _CharT *__p = traits_type::find((__sb->gptr()), __n, __val); 
# 390
if (__p) { 
# 391
__n = (__p - (__sb->gptr())); }  
# 392
(__sb->__safe_gbump(__n)); 
# 393
__c = (__sb->sgetc()); 
# 394
} else { 
# 396
__c = (__sb->snextc()); }  
# 397
}  
# 399
if (!traits_type::eq_int_type(__c, traits_type::eof())) { 
# 400
(__first._M_c) = __c; } else { 
# 402
(__first._M_sbuf) = 0; }  
# 403
}  
# 404
return __first; 
# 405
} 
# 410
}
# 50 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 64
template< class _Tp> void __convert_to_v(const char *, _Tp &, ios_base::iostate &, const __c_locale &) throw(); 
# 72
template<> void __convert_to_v(const char *, float &, ios_base::iostate &, const __c_locale &) throw(); 
# 77
template<> void __convert_to_v(const char *, double &, ios_base::iostate &, const __c_locale &) throw(); 
# 82
template<> void __convert_to_v(const char *, long double &, ios_base::iostate &, const __c_locale &) throw(); 
# 87
template< class _CharT, class _Traits> 
# 88
struct __pad { 
# 91
static void _S_pad(ios_base & __io, _CharT __fill, _CharT * __news, const _CharT * __olds, streamsize __newlen, streamsize __oldlen); 
# 93
}; 
# 100
template< class _CharT> _CharT *__add_grouping(_CharT * __s, _CharT __sep, const char * __gbeg, size_t __gsize, const _CharT * __first, const _CharT * __last); 
# 109
template< class _CharT> inline ostreambuf_iterator< _CharT, char_traits< _CharT> >  
# 112
__write(ostreambuf_iterator< _CharT, char_traits< _CharT> >  __s, const _CharT *__ws, int __len) 
# 113
{ 
# 114
(__s._M_put(__ws, __len)); 
# 115
return __s; 
# 116
} 
# 119
template< class _CharT, class _OutIter> inline _OutIter 
# 122
__write(_OutIter __s, const _CharT *__ws, int __len) 
# 123
{ 
# 124
for (int __j = 0; __j < __len; (__j++), (++__s)) { 
# 125
(*__s) = (__ws[__j]); }  
# 126
return __s; 
# 127
} 
# 142
template< class _CharT> 
# 143
class __ctype_abstract_base : public locale::facet, public ctype_base { 
# 148
public: typedef _CharT char_type; 
# 162
bool is(mask __m, char_type __c) const 
# 163
{ return (this->do_is(__m, __c)); } 
# 179
const char_type *is(const char_type *__lo, const char_type *__hi, mask *__vec) const 
# 180
{ return (this->do_is(__lo, __hi, __vec)); } 
# 195
const char_type *scan_is(mask __m, const char_type *__lo, const char_type *__hi) const 
# 196
{ return this->do_scan_is(__m, __lo, __hi); } 
# 211
const char_type *scan_not(mask __m, const char_type *__lo, const char_type *__hi) const 
# 212
{ return this->do_scan_not(__m, __lo, __hi); } 
# 225
char_type toupper(char_type __c) const 
# 226
{ return (this->do_toupper(__c)); } 
# 240
const char_type *toupper(char_type *__lo, const char_type *__hi) const 
# 241
{ return (this->do_toupper(__lo, __hi)); } 
# 254
char_type tolower(char_type __c) const 
# 255
{ return (this->do_tolower(__c)); } 
# 269
const char_type *tolower(char_type *__lo, const char_type *__hi) const 
# 270
{ return (this->do_tolower(__lo, __hi)); } 
# 286
char_type widen(char __c) const 
# 287
{ return (this->do_widen(__c)); } 
# 305
const char *widen(const char *__lo, const char *__hi, char_type *__to) const 
# 306
{ return (this->do_widen(__lo, __hi, __to)); } 
# 324
char narrow(char_type __c, char __dfault) const 
# 325
{ return (this->do_narrow(__c, __dfault)); } 
# 346
const char_type *narrow(const char_type *__lo, const char_type *__hi, char 
# 347
__dfault, char *__to) const 
# 348
{ return (this->do_narrow(__lo, __hi, __dfault, __to)); } 
# 352
protected: explicit __ctype_abstract_base(size_t __refs = 0) : locale::facet(__refs) { } 
# 355
virtual ~__ctype_abstract_base() { } 
# 371
virtual bool do_is(mask __m, char_type __c) const = 0; 
# 390
virtual const char_type *do_is(const char_type * __lo, const char_type * __hi, mask * __vec) const = 0; 
# 409
virtual const char_type *do_scan_is(mask __m, const char_type * __lo, const char_type * __hi) const = 0; 
# 428
virtual const char_type *do_scan_not(mask __m, const char_type * __lo, const char_type * __hi) const = 0; 
# 446
virtual char_type do_toupper(char_type __c) const = 0; 
# 463
virtual const char_type *do_toupper(char_type * __lo, const char_type * __hi) const = 0; 
# 479
virtual char_type do_tolower(char_type __c) const = 0; 
# 496
virtual const char_type *do_tolower(char_type * __lo, const char_type * __hi) const = 0; 
# 515
virtual char_type do_widen(char __c) const = 0; 
# 536
virtual const char *do_widen(const char * __lo, const char * __hi, char_type * __to) const = 0; 
# 557
virtual char do_narrow(char_type __c, char __dfault) const = 0; 
# 582
virtual const char_type *do_narrow(const char_type * __lo, const char_type * __hi, char __dfault, char * __to) const = 0; 
# 584
}; 
# 604
template< class _CharT> 
# 605
class ctype : public __ctype_abstract_base< _CharT>  { 
# 609
public: typedef _CharT char_type; 
# 610
typedef typename ::std::__ctype_abstract_base< _CharT> ::mask mask; 
# 613
static ::std::locale::id id; 
# 616
explicit ctype(::std::size_t __refs = 0) : ::std::__ctype_abstract_base< _CharT> (__refs) { } 
# 620
protected: virtual ~ctype(); 
# 623
virtual bool do_is(mask __m, char_type __c) const; 
# 626
virtual const char_type *do_is(const char_type * __lo, const char_type * __hi, mask * __vec) const; 
# 629
virtual const char_type *do_scan_is(mask __m, const char_type * __lo, const char_type * __hi) const; 
# 632
virtual const char_type *do_scan_not(mask __m, const char_type * __lo, const char_type * __hi) const; 
# 636
virtual char_type do_toupper(char_type __c) const; 
# 639
virtual const char_type *do_toupper(char_type * __lo, const char_type * __hi) const; 
# 642
virtual char_type do_tolower(char_type __c) const; 
# 645
virtual const char_type *do_tolower(char_type * __lo, const char_type * __hi) const; 
# 648
virtual char_type do_widen(char __c) const; 
# 651
virtual const char *do_widen(const char * __lo, const char * __hi, char_type * __dest) const; 
# 654
virtual char do_narrow(char_type, char __dfault) const; 
# 657
virtual const char_type *do_narrow(const char_type * __lo, const char_type * __hi, char __dfault, char * __to) const; 
# 659
}; 
# 661
template< class _CharT> locale::id 
# 662
ctype< _CharT> ::id; 
# 674
template<> class ctype< char>  : public locale::facet, public ctype_base { 
# 679
public: typedef char char_type; 
# 683
protected: __c_locale _M_c_locale_ctype; 
# 684
bool _M_del; 
# 685
__to_type _M_toupper; 
# 686
__to_type _M_tolower; 
# 687
const mask *_M_table; 
# 688
mutable char _M_widen_ok; 
# 689
mutable char _M_widen[1 + (static_cast< unsigned char>(-1))]; 
# 690
mutable char _M_narrow[1 + (static_cast< unsigned char>(-1))]; 
# 691
mutable char _M_narrow_ok; 
# 696
public: static locale::id id; 
# 698
static const size_t table_size = (1 + (static_cast< unsigned char>(-1))); 
# 711
explicit ctype(const mask * __table = 0, bool __del = false, size_t __refs = 0); 
# 724
explicit ctype(__c_locale __cloc, const mask * __table = 0, bool __del = false, size_t __refs = 0); 
# 737
inline bool is(mask __m, char __c) const; 
# 752
inline const char *is(const char * __lo, const char * __hi, mask * __vec) const; 
# 766
inline const char *scan_is(mask __m, const char * __lo, const char * __hi) const; 
# 780
inline const char *scan_not(mask __m, const char * __lo, const char * __hi) const; 
# 795
char_type toupper(char_type __c) const 
# 796
{ return this->do_toupper(__c); } 
# 812
const char_type *toupper(char_type *__lo, const char_type *__hi) const 
# 813
{ return this->do_toupper(__lo, __hi); } 
# 828
char_type tolower(char_type __c) const 
# 829
{ return this->do_tolower(__c); } 
# 845
const char_type *tolower(char_type *__lo, const char_type *__hi) const 
# 846
{ return this->do_tolower(__lo, __hi); } 
# 865
char_type widen(char __c) const 
# 866
{ 
# 867
if (_M_widen_ok) { 
# 868
return (_M_widen)[static_cast< unsigned char>(__c)]; }  
# 869
this->_M_widen_init(); 
# 870
return this->do_widen(__c); 
# 871
} 
# 892
const char *widen(const char *__lo, const char *__hi, char_type *__to) const 
# 893
{ 
# 894
if ((_M_widen_ok) == 1) 
# 895
{ 
# 896
__builtin_memcpy(__to, __lo, __hi - __lo); 
# 897
return __hi; 
# 898
}  
# 899
if (!(_M_widen_ok)) { 
# 900
this->_M_widen_init(); }  
# 901
return this->do_widen(__lo, __hi, __to); 
# 902
} 
# 923
char narrow(char_type __c, char __dfault) const 
# 924
{ 
# 925
if ((_M_narrow)[static_cast< unsigned char>(__c)]) { 
# 926
return (_M_narrow)[static_cast< unsigned char>(__c)]; }  
# 927
const char __t = this->do_narrow(__c, __dfault); 
# 928
if (__t != __dfault) { 
# 929
((_M_narrow)[static_cast< unsigned char>(__c)]) = __t; }  
# 930
return __t; 
# 931
} 
# 956
const char_type *narrow(const char_type *__lo, const char_type *__hi, char 
# 957
__dfault, char *__to) const 
# 958
{ 
# 959
if (__builtin_expect((_M_narrow_ok) == 1, true)) 
# 960
{ 
# 961
__builtin_memcpy(__to, __lo, __hi - __lo); 
# 962
return __hi; 
# 963
}  
# 964
if (!(_M_narrow_ok)) { 
# 965
this->_M_narrow_init(); }  
# 966
return this->do_narrow(__lo, __hi, __dfault, __to); 
# 967
} 
# 974
const mask *table() const throw() 
# 975
{ return _M_table; } 
# 979
static const mask *classic_table() throw(); 
# 989
protected: virtual ~ctype(); 
# 1005
virtual char_type do_toupper(char_type __c) const; 
# 1022
virtual const char_type *do_toupper(char_type * __lo, const char_type * __hi) const; 
# 1038
virtual char_type do_tolower(char_type __c) const; 
# 1055
virtual const char_type *do_tolower(char_type * __lo, const char_type * __hi) const; 
# 1075
virtual char_type do_widen(char __c) const 
# 1076
{ return __c; } 
# 1098
virtual const char *do_widen(const char *__lo, const char *__hi, char_type *__to) const 
# 1099
{ 
# 1100
__builtin_memcpy(__to, __lo, __hi - __lo); 
# 1101
return __hi; 
# 1102
} 
# 1124
virtual char do_narrow(char_type __c, char __dfault) const 
# 1125
{ return __c; } 
# 1150
virtual const char_type *do_narrow(const char_type *__lo, const char_type *__hi, char 
# 1151
__dfault, char *__to) const 
# 1152
{ 
# 1153
__builtin_memcpy(__to, __lo, __hi - __lo); 
# 1154
return __hi; 
# 1155
} 
# 1158
private: void _M_narrow_init() const; 
# 1159
void _M_widen_init() const; 
# 1160
}; 
# 1175
template<> class ctype< wchar_t>  : public __ctype_abstract_base< wchar_t>  { 
# 1180
public: typedef wchar_t char_type; 
# 1181
typedef wctype_t __wmask_type; 
# 1184
protected: __c_locale _M_c_locale_ctype; 
# 1187
bool _M_narrow_ok; 
# 1188
char _M_narrow[128]; 
# 1189
wint_t _M_widen[1 + (static_cast< unsigned char>(-1))]; 
# 1192
mask _M_bit[16]; 
# 1193
__wmask_type _M_wmask[16]; 
# 1198
public: static locale::id id; 
# 1208
explicit ctype(size_t __refs = 0); 
# 1219
explicit ctype(__c_locale __cloc, size_t __refs = 0); 
# 1223
protected: __wmask_type _M_convert_to_wmask(const mask __m) const throw(); 
# 1227
virtual ~ctype(); 
# 1243
virtual bool do_is(mask __m, char_type __c) const; 
# 1262
virtual const char_type *do_is(const char_type * __lo, const char_type * __hi, mask * __vec) const; 
# 1280
virtual const char_type *do_scan_is(mask __m, const char_type * __lo, const char_type * __hi) const; 
# 1298
virtual const char_type *do_scan_not(mask __m, const char_type * __lo, const char_type * __hi) const; 
# 1315
virtual char_type do_toupper(char_type __c) const; 
# 1332
virtual const char_type *do_toupper(char_type * __lo, const char_type * __hi) const; 
# 1348
virtual char_type do_tolower(char_type __c) const; 
# 1365
virtual const char_type *do_tolower(char_type * __lo, const char_type * __hi) const; 
# 1385
virtual char_type do_widen(char __c) const; 
# 1407
virtual const char *do_widen(const char * __lo, const char * __hi, char_type * __to) const; 
# 1430
virtual char do_narrow(char_type __c, char __dfault) const; 
# 1456
virtual const char_type *do_narrow(const char_type * __lo, const char_type * __hi, char __dfault, char * __to) const; 
# 1461
void _M_initialize_ctype() throw(); 
# 1462
}; 
# 1466
template< class _CharT> 
# 1467
class ctype_byname : public ctype< _CharT>  { 
# 1470
public: typedef typename ::std::ctype< _CharT> ::mask mask; 
# 1473
explicit ctype_byname(const char * __s, ::std::size_t __refs = 0); 
# 1477
protected: virtual ~ctype_byname() { } 
# 1478
}; 
# 1482
template<> class ctype_byname< char>  : public ctype< char>  { 
# 1486
public: explicit ctype_byname(const char * __s, size_t __refs = 0); 
# 1490
protected: virtual ~ctype_byname(); 
# 1491
}; 
# 1495
template<> class ctype_byname< wchar_t>  : public ctype< wchar_t>  { 
# 1499
public: explicit ctype_byname(const char * __s, size_t __refs = 0); 
# 1503
protected: virtual ~ctype_byname(); 
# 1504
}; 
# 1508
}
# 37 "/usr/include/c++/4.8.2/x86_64-redhat-linux/bits/ctype_inline.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 43
inline bool ctype< char> ::is(mask __m, char __c) const 
# 44
{ return ((_M_table)[static_cast< unsigned char>(__c)]) & __m; } 
# 48
inline const char *ctype< char> ::is(const char *__low, const char *__high, mask *__vec) const 
# 49
{ 
# 50
while (__low < __high) { 
# 51
(*(__vec++)) = ((_M_table)[static_cast< unsigned char>(*(__low++))]); }  
# 52
return __high; 
# 53
} 
# 57
inline const char *ctype< char> ::scan_is(mask __m, const char *__low, const char *__high) const 
# 58
{ 
# 59
while ((__low < __high) && (!(((_M_table)[static_cast< unsigned char>(*__low)]) & __m))) { 
# 61
++__low; }  
# 62
return __low; 
# 63
} 
# 67
inline const char *ctype< char> ::scan_not(mask __m, const char *__low, const char *__high) const 
# 68
{ 
# 69
while ((__low < __high) && ((((_M_table)[static_cast< unsigned char>(*__low)]) & __m) != 0)) { 
# 71
++__low; }  
# 72
return __low; 
# 73
} 
# 76
}
# 1513 "/usr/include/c++/4.8.2/bits/locale_facets.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 1518
class __num_base { 
# 1524
public: enum { 
# 1525
_S_ominus, 
# 1526
_S_oplus, 
# 1527
_S_ox, 
# 1528
_S_oX, 
# 1529
_S_odigits, 
# 1530
_S_odigits_end = 20, 
# 1531
_S_oudigits = 20, 
# 1532
_S_oudigits_end = 36, 
# 1533
_S_oe = 18, 
# 1534
_S_oE = 34, 
# 1535
_S_oend = 36
# 1536
}; 
# 1543
static const char *_S_atoms_out; 
# 1547
static const char *_S_atoms_in; 
# 1550
enum { 
# 1551
_S_iminus, 
# 1552
_S_iplus, 
# 1553
_S_ix, 
# 1554
_S_iX, 
# 1555
_S_izero, 
# 1556
_S_ie = 18, 
# 1557
_S_iE = 24, 
# 1558
_S_iend = 26
# 1559
}; 
# 1564
static void _S_format_float(const ios_base & __io, char * __fptr, char __mod) throw(); 
# 1565
}; 
# 1567
template< class _CharT> 
# 1568
struct __numpunct_cache : public locale::facet { 
# 1570
const char *_M_grouping; 
# 1571
size_t _M_grouping_size; 
# 1572
bool _M_use_grouping; 
# 1573
const _CharT *_M_truename; 
# 1574
size_t _M_truename_size; 
# 1575
const _CharT *_M_falsename; 
# 1576
size_t _M_falsename_size; 
# 1577
_CharT _M_decimal_point; 
# 1578
_CharT _M_thousands_sep; 
# 1584
_CharT _M_atoms_out[__num_base::_S_oend]; 
# 1590
_CharT _M_atoms_in[__num_base::_S_iend]; 
# 1592
bool _M_allocated; 
# 1594
__numpunct_cache(size_t __refs = 0) : locale::facet(__refs), _M_grouping((0)), _M_grouping_size((0)), _M_use_grouping(false), _M_truename((0)), _M_truename_size((0)), _M_falsename((0)), _M_falsename_size((0)), _M_decimal_point(_CharT()), _M_thousands_sep(_CharT()), _M_allocated(false) 
# 1600
{ } 
# 1602
virtual ~__numpunct_cache(); 
# 1605
void _M_cache(const locale & __loc); 
# 1609
private: __numpunct_cache &operator=(const __numpunct_cache &); 
# 1612
explicit __numpunct_cache(const __numpunct_cache &); 
# 1613
}; 
# 1615
template< class _CharT> 
# 1616
__numpunct_cache< _CharT> ::~__numpunct_cache() 
# 1617
{ 
# 1618
if (_M_allocated) 
# 1619
{ 
# 1620
delete [] (_M_grouping); 
# 1621
delete [] (_M_truename); 
# 1622
delete [] (_M_falsename); 
# 1623
}  
# 1624
} 
# 1640
template< class _CharT> 
# 1641
class numpunct : public locale::facet { 
# 1647
public: typedef _CharT char_type; 
# 1648
typedef basic_string< _CharT, char_traits< _CharT> , allocator< _CharT> >  string_type; 
# 1650
typedef __numpunct_cache< _CharT>  __cache_type; 
# 1653
protected: __cache_type *_M_data; 
# 1657
public: static locale::id id; 
# 1665
explicit numpunct(size_t __refs = 0) : locale::facet(__refs), _M_data((0)) 
# 1667
{ _M_initialize_numpunct(); } 
# 1679
explicit numpunct(__cache_type *__cache, size_t __refs = 0) : locale::facet(__refs), _M_data(__cache) 
# 1681
{ _M_initialize_numpunct(); } 
# 1693
explicit numpunct(__c_locale __cloc, size_t __refs = 0) : locale::facet(__refs), _M_data((0)) 
# 1695
{ _M_initialize_numpunct(__cloc); } 
# 1707
char_type decimal_point() const 
# 1708
{ return this->do_decimal_point(); } 
# 1720
char_type thousands_sep() const 
# 1721
{ return this->do_thousands_sep(); } 
# 1751
string grouping() const 
# 1752
{ return this->do_grouping(); } 
# 1764
string_type truename() const 
# 1765
{ return this->do_truename(); } 
# 1777
string_type falsename() const 
# 1778
{ return this->do_falsename(); } 
# 1783
protected: virtual ~numpunct(); 
# 1794
virtual char_type do_decimal_point() const 
# 1795
{ return (_M_data)->_M_decimal_point; } 
# 1806
virtual char_type do_thousands_sep() const 
# 1807
{ return (_M_data)->_M_thousands_sep; } 
# 1819
virtual string do_grouping() const 
# 1820
{ return ((_M_data)->_M_grouping); } 
# 1832
virtual string_type do_truename() const 
# 1833
{ return ((_M_data)->_M_truename); } 
# 1845
virtual string_type do_falsename() const 
# 1846
{ return ((_M_data)->_M_falsename); } 
# 1850
void _M_initialize_numpunct(__c_locale __cloc = 0); 
# 1851
}; 
# 1853
template< class _CharT> locale::id 
# 1854
numpunct< _CharT> ::id; 
# 1857
template<> numpunct< char> ::~numpunct(); 
# 1861
template<> void numpunct< char> ::_M_initialize_numpunct(__c_locale __cloc); 
# 1865
template<> numpunct< wchar_t> ::~numpunct(); 
# 1869
template<> void numpunct< wchar_t> ::_M_initialize_numpunct(__c_locale __cloc); 
# 1873
template< class _CharT> 
# 1874
class numpunct_byname : public numpunct< _CharT>  { 
# 1877
public: typedef _CharT char_type; 
# 1878
typedef basic_string< _CharT, char_traits< _CharT> , allocator< _CharT> >  string_type; 
# 1881
explicit numpunct_byname(const char *__s, ::std::size_t __refs = 0) : ::std::numpunct< _CharT> (__refs) 
# 1883
{ 
# 1884
if ((__builtin_strcmp(__s, "C") != 0) && (__builtin_strcmp(__s, "POSIX") != 0)) 
# 1886
{ 
# 1887
::std::__c_locale __tmp; 
# 1888
(this->_S_create_c_locale(__tmp, __s)); 
# 1889
(this->_M_initialize_numpunct(__tmp)); 
# 1890
(this->_S_destroy_c_locale(__tmp)); 
# 1891
}  
# 1892
} 
# 1896
protected: virtual ~numpunct_byname() { } 
# 1897
}; 
# 1914
template< class _CharT, class _InIter> 
# 1915
class num_get : public locale::facet { 
# 1921
public: typedef _CharT char_type; 
# 1922
typedef _InIter iter_type; 
# 1926
static locale::id id; 
# 1936
explicit num_get(size_t __refs = 0) : locale::facet(__refs) { } 
# 1962
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 1963
__err, bool &__v) const 
# 1964
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 1999
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2000
__err, long &__v) const 
# 2001
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2004
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2005
__err, unsigned short &__v) const 
# 2006
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2009
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2010
__err, unsigned &__v) const 
# 2011
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2014
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2015
__err, unsigned long &__v) const 
# 2016
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2020
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2021
__err, long long &__v) const 
# 2022
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2025
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2026
__err, unsigned long long &__v) const 
# 2027
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2059
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2060
__err, float &__v) const 
# 2061
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2064
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2065
__err, double &__v) const 
# 2066
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2069
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2070
__err, long double &__v) const 
# 2071
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2102
iter_type get(iter_type __in, iter_type __end, ios_base &__io, ios_base::iostate &
# 2103
__err, void *&__v) const 
# 2104
{ return (this->do_get(__in, __end, __io, __err, __v)); } 
# 2108
protected: virtual ~num_get() { } 
# 2111
iter_type _M_extract_float(iter_type, iter_type, ios_base &, ios_base::iostate &, string &) const; 
# 2114
template< class _ValueT> iter_type _M_extract_int(iter_type, iter_type, ios_base &, ios_base::iostate &, _ValueT &) const; 
# 2119
template< class _CharT2> typename __gnu_cxx::__enable_if< __is_char< _CharT2> ::__value, int> ::__type 
# 2121
_M_find(const _CharT2 *, size_t __len, _CharT2 __c) const 
# 2122
{ 
# 2123
int __ret = (-1); 
# 2124
if (__len <= (10)) 
# 2125
{ 
# 2126
if ((__c >= ((_CharT2)'0')) && (__c < ((_CharT2)(((_CharT2)'0') + __len)))) { 
# 2127
__ret = (__c - ((_CharT2)'0')); }  
# 2128
} else 
# 2130
{ 
# 2131
if ((__c >= ((_CharT2)'0')) && (__c <= ((_CharT2)'9'))) { 
# 2132
__ret = (__c - ((_CharT2)'0')); } else { 
# 2133
if ((__c >= ((_CharT2)'a')) && (__c <= ((_CharT2)'f'))) { 
# 2134
__ret = (10 + (__c - ((_CharT2)'a'))); } else { 
# 2135
if ((__c >= ((_CharT2)'A')) && (__c <= ((_CharT2)'F'))) { 
# 2136
__ret = (10 + (__c - ((_CharT2)'A'))); }  }  }  
# 2137
}  
# 2138
return __ret; 
# 2139
} 
# 2141
template< class _CharT2> typename __gnu_cxx::__enable_if< !__is_char< _CharT2> ::__value, int> ::__type 
# 2144
_M_find(const _CharT2 *__zero, size_t __len, _CharT2 __c) const 
# 2145
{ 
# 2146
int __ret = (-1); 
# 2147
const char_type *__q = char_traits< _CharT2> ::find(__zero, __len, __c); 
# 2148
if (__q) 
# 2149
{ 
# 2150
__ret = (__q - __zero); 
# 2151
if (__ret > 15) { 
# 2152
__ret -= 6; }  
# 2153
}  
# 2154
return __ret; 
# 2155
} 
# 2173
virtual iter_type do_get(iter_type, iter_type, ios_base &, ios_base::iostate &, bool &) const; 
# 2176
virtual iter_type do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 2177
__err, long &__v) const 
# 2178
{ return _M_extract_int(__beg, __end, __io, __err, __v); } 
# 2181
virtual iter_type do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 2182
__err, unsigned short &__v) const 
# 2183
{ return _M_extract_int(__beg, __end, __io, __err, __v); } 
# 2186
virtual iter_type do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 2187
__err, unsigned &__v) const 
# 2188
{ return _M_extract_int(__beg, __end, __io, __err, __v); } 
# 2191
virtual iter_type do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 2192
__err, unsigned long &__v) const 
# 2193
{ return _M_extract_int(__beg, __end, __io, __err, __v); } 
# 2197
virtual iter_type do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 2198
__err, long long &__v) const 
# 2199
{ return _M_extract_int(__beg, __end, __io, __err, __v); } 
# 2202
virtual iter_type do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 2203
__err, unsigned long long &__v) const 
# 2204
{ return _M_extract_int(__beg, __end, __io, __err, __v); } 
# 2208
virtual iter_type do_get(iter_type, iter_type, ios_base &, ios_base::iostate &, float &) const; 
# 2211
virtual iter_type do_get(iter_type, iter_type, ios_base &, ios_base::iostate &, double &) const; 
# 2221
virtual iter_type do_get(iter_type, iter_type, ios_base &, ios_base::iostate &, long double &) const; 
# 2226
virtual iter_type do_get(iter_type, iter_type, ios_base &, ios_base::iostate &, void *&) const; 
# 2235
}; 
# 2237
template< class _CharT, class _InIter> locale::id 
# 2238
num_get< _CharT, _InIter> ::id; 
# 2253
template< class _CharT, class _OutIter> 
# 2254
class num_put : public locale::facet { 
# 2260
public: typedef _CharT char_type; 
# 2261
typedef _OutIter iter_type; 
# 2265
static locale::id id; 
# 2275
explicit num_put(size_t __refs = 0) : locale::facet(__refs) { } 
# 2293
iter_type put(iter_type __s, ios_base &__io, char_type __fill, bool __v) const 
# 2294
{ return (this->do_put(__s, __io, __fill, __v)); } 
# 2335
iter_type put(iter_type __s, ios_base &__io, char_type __fill, long __v) const 
# 2336
{ return (this->do_put(__s, __io, __fill, __v)); } 
# 2339
iter_type put(iter_type __s, ios_base &__io, char_type __fill, unsigned long 
# 2340
__v) const 
# 2341
{ return (this->do_put(__s, __io, __fill, __v)); } 
# 2345
iter_type put(iter_type __s, ios_base &__io, char_type __fill, long long __v) const 
# 2346
{ return (this->do_put(__s, __io, __fill, __v)); } 
# 2349
iter_type put(iter_type __s, ios_base &__io, char_type __fill, unsigned long long 
# 2350
__v) const 
# 2351
{ return (this->do_put(__s, __io, __fill, __v)); } 
# 2398
iter_type put(iter_type __s, ios_base &__io, char_type __fill, double __v) const 
# 2399
{ return (this->do_put(__s, __io, __fill, __v)); } 
# 2402
iter_type put(iter_type __s, ios_base &__io, char_type __fill, long double 
# 2403
__v) const 
# 2404
{ return (this->do_put(__s, __io, __fill, __v)); } 
# 2423
iter_type put(iter_type __s, ios_base &__io, char_type __fill, const void *
# 2424
__v) const 
# 2425
{ return (this->do_put(__s, __io, __fill, __v)); } 
# 2428
protected: template< class _ValueT> iter_type _M_insert_float(iter_type, ios_base & __io, char_type __fill, char __mod, _ValueT __v) const; 
# 2434
void _M_group_float(const char * __grouping, size_t __grouping_size, char_type __sep, const char_type * __p, char_type * __new, char_type * __cs, int & __len) const; 
# 2438
template< class _ValueT> iter_type _M_insert_int(iter_type, ios_base & __io, char_type __fill, _ValueT __v) const; 
# 2444
void _M_group_int(const char * __grouping, size_t __grouping_size, char_type __sep, ios_base & __io, char_type * __new, char_type * __cs, int & __len) const; 
# 2449
void _M_pad(char_type __fill, streamsize __w, ios_base & __io, char_type * __new, const char_type * __cs, int & __len) const; 
# 2454
virtual ~num_put() { } 
# 2471
virtual iter_type do_put(iter_type __s, ios_base & __io, char_type __fill, bool __v) const; 
# 2474
virtual iter_type do_put(iter_type __s, ios_base &__io, char_type __fill, long __v) const 
# 2475
{ return _M_insert_int(__s, __io, __fill, __v); } 
# 2478
virtual iter_type do_put(iter_type __s, ios_base &__io, char_type __fill, unsigned long 
# 2479
__v) const 
# 2480
{ return _M_insert_int(__s, __io, __fill, __v); } 
# 2484
virtual iter_type do_put(iter_type __s, ios_base &__io, char_type __fill, long long 
# 2485
__v) const 
# 2486
{ return _M_insert_int(__s, __io, __fill, __v); } 
# 2489
virtual iter_type do_put(iter_type __s, ios_base &__io, char_type __fill, unsigned long long 
# 2490
__v) const 
# 2491
{ return _M_insert_int(__s, __io, __fill, __v); } 
# 2495
virtual iter_type do_put(iter_type, ios_base &, char_type, double) const; 
# 2503
virtual iter_type do_put(iter_type, ios_base &, char_type, long double) const; 
# 2507
virtual iter_type do_put(iter_type, ios_base &, char_type, const void *) const; 
# 2515
}; 
# 2517
template< class _CharT, class _OutIter> locale::id 
# 2518
num_put< _CharT, _OutIter> ::id; 
# 2528
template< class _CharT> inline bool 
# 2530
isspace(_CharT __c, const locale &__loc) 
# 2531
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::space, __c)); } 
# 2534
template< class _CharT> inline bool 
# 2536
isprint(_CharT __c, const locale &__loc) 
# 2537
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::print, __c)); } 
# 2540
template< class _CharT> inline bool 
# 2542
iscntrl(_CharT __c, const locale &__loc) 
# 2543
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::cntrl, __c)); } 
# 2546
template< class _CharT> inline bool 
# 2548
isupper(_CharT __c, const locale &__loc) 
# 2549
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::upper, __c)); } 
# 2552
template< class _CharT> inline bool 
# 2554
islower(_CharT __c, const locale &__loc) 
# 2555
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::lower, __c)); } 
# 2558
template< class _CharT> inline bool 
# 2560
isalpha(_CharT __c, const locale &__loc) 
# 2561
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::alpha, __c)); } 
# 2564
template< class _CharT> inline bool 
# 2566
isdigit(_CharT __c, const locale &__loc) 
# 2567
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::digit, __c)); } 
# 2570
template< class _CharT> inline bool 
# 2572
ispunct(_CharT __c, const locale &__loc) 
# 2573
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::punct, __c)); } 
# 2576
template< class _CharT> inline bool 
# 2578
isxdigit(_CharT __c, const locale &__loc) 
# 2579
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::xdigit, __c)); } 
# 2582
template< class _CharT> inline bool 
# 2584
isalnum(_CharT __c, const locale &__loc) 
# 2585
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::alnum, __c)); } 
# 2588
template< class _CharT> inline bool 
# 2590
isgraph(_CharT __c, const locale &__loc) 
# 2591
{ return (use_facet< ctype< _CharT> > (__loc).is(ctype_base::graph, __c)); } 
# 2594
template< class _CharT> inline _CharT 
# 2596
toupper(_CharT __c, const locale &__loc) 
# 2597
{ return (use_facet< ctype< _CharT> > (__loc).toupper(__c)); } 
# 2600
template< class _CharT> inline _CharT 
# 2602
tolower(_CharT __c, const locale &__loc) 
# 2603
{ return (use_facet< ctype< _CharT> > (__loc).tolower(__c)); } 
# 2606
}
# 35 "/usr/include/c++/4.8.2/bits/locale_facets.tcc" 3
namespace std __attribute((__visibility__("default"))) { 
# 41
template< class _Facet> 
# 42
struct __use_cache { 
# 45
const _Facet *operator()(const locale & __loc) const; 
# 46
}; 
# 49
template< class _CharT> 
# 50
struct __use_cache< __numpunct_cache< _CharT> >  { 
# 53
const __numpunct_cache< _CharT>  *operator()(const locale &__loc) const 
# 54
{ 
# 55
const size_t __i = (numpunct< _CharT> ::id._M_id)(); 
# 56
const locale::facet **__caches = (__loc._M_impl)->_M_caches; 
# 57
if (!(__caches[__i])) 
# 58
{ 
# 59
__numpunct_cache< _CharT>  *__tmp = (0); 
# 60
try 
# 61
{ 
# 62
__tmp = (new __numpunct_cache< _CharT> ); 
# 63
(__tmp->_M_cache(__loc)); 
# 64
} 
# 65
catch (...) 
# 66
{ 
# 67
delete __tmp; 
# 68
throw; 
# 69
}  
# 70
(__loc._M_impl)->_M_install_cache(__tmp, __i); 
# 71
}  
# 72
return static_cast< const __numpunct_cache< _CharT>  *>(__caches[__i]); 
# 73
} 
# 74
}; 
# 76
template< class _CharT> void 
# 78
__numpunct_cache< _CharT> ::_M_cache(const locale &__loc) 
# 79
{ 
# 80
(_M_allocated) = true; 
# 82
const numpunct< _CharT>  &__np = use_facet< numpunct< _CharT> > (__loc); 
# 84
char *__grouping = (0); 
# 85
_CharT *__truename = (0); 
# 86
_CharT *__falsename = (0); 
# 87
try 
# 88
{ 
# 89
(_M_grouping_size) = ((__np.grouping()).size()); 
# 90
__grouping = (new char [_M_grouping_size]); 
# 91
((__np.grouping()).copy(__grouping, _M_grouping_size)); 
# 92
(_M_grouping) = __grouping; 
# 93
(_M_use_grouping) = ((_M_grouping_size) && ((static_cast< signed char>((_M_grouping)[0])) > 0) && (((_M_grouping)[0]) != __gnu_cxx::__numeric_traits_integer< char> ::__max)); 
# 98
(_M_truename_size) = ((__np.truename()).size()); 
# 99
__truename = (new _CharT [_M_truename_size]); 
# 100
((__np.truename()).copy(__truename, _M_truename_size)); 
# 101
(_M_truename) = __truename; 
# 103
(_M_falsename_size) = ((__np.falsename()).size()); 
# 104
__falsename = (new _CharT [_M_falsename_size]); 
# 105
((__np.falsename()).copy(__falsename, _M_falsename_size)); 
# 106
(_M_falsename) = __falsename; 
# 108
(_M_decimal_point) = (__np.decimal_point()); 
# 109
(_M_thousands_sep) = (__np.thousands_sep()); 
# 111
const ctype< _CharT>  &__ct = use_facet< ctype< _CharT> > (__loc); 
# 112
(__ct.widen(__num_base::_S_atoms_out, __num_base::_S_atoms_out + __num_base::_S_oend, _M_atoms_out)); 
# 115
(__ct.widen(__num_base::_S_atoms_in, __num_base::_S_atoms_in + __num_base::_S_iend, _M_atoms_in)); 
# 118
} 
# 119
catch (...) 
# 120
{ 
# 121
delete [] __grouping; 
# 122
delete [] __truename; 
# 123
delete [] __falsename; 
# 124
throw; 
# 125
}  
# 126
} 
# 136
__attribute((__pure__)) bool 
# 137
__verify_grouping(const char * __grouping, size_t __grouping_size, const string & __grouping_tmp) throw(); 
# 142
template< class _CharT, class _InIter> _InIter 
# 145
num_get< _CharT, _InIter> ::_M_extract_float(_InIter __beg, _InIter __end, ios_base &__io, ios_base::iostate &
# 146
__err, string &__xtrc) const 
# 147
{ 
# 148
typedef char_traits< _CharT>  __traits_type; 
# 149
typedef __numpunct_cache< _CharT>  __cache_type; 
# 150
__use_cache< __numpunct_cache< _CharT> >  __uc; 
# 151
const locale &__loc = __io._M_getloc(); 
# 152
const __cache_type *__lc = __uc(__loc); 
# 153
const _CharT *__lit = ((__lc->_M_atoms_in)); 
# 154
char_type __c = (char_type()); 
# 157
bool __testeof = __beg == __end; 
# 160
if (!__testeof) 
# 161
{ 
# 162
__c = (*__beg); 
# 163
const bool __plus = __c == (__lit[__num_base::_S_iplus]); 
# 164
if ((__plus || (__c == (__lit[__num_base::_S_iminus]))) && (!((__lc->_M_use_grouping) && (__c == (__lc->_M_thousands_sep)))) && (!(__c == (__lc->_M_decimal_point)))) 
# 167
{ 
# 168
(__xtrc += (__plus ? '+' : '-')); 
# 169
if ((++__beg) != __end) { 
# 170
__c = (*__beg); } else { 
# 172
__testeof = true; }  
# 173
}  
# 174
}  
# 177
bool __found_mantissa = false; 
# 178
int __sep_pos = 0; 
# 179
while (!__testeof) 
# 180
{ 
# 181
if (((__lc->_M_use_grouping) && (__c == (__lc->_M_thousands_sep))) || (__c == (__lc->_M_decimal_point))) { 
# 183
break; } else { 
# 184
if (__c == (__lit[__num_base::_S_izero])) 
# 185
{ 
# 186
if (!__found_mantissa) 
# 187
{ 
# 188
(__xtrc += ('0')); 
# 189
__found_mantissa = true; 
# 190
}  
# 191
++__sep_pos; 
# 193
if ((++__beg) != __end) { 
# 194
__c = (*__beg); } else { 
# 196
__testeof = true; }  
# 197
} else { 
# 199
break; }  }  
# 200
}  
# 203
bool __found_dec = false; 
# 204
bool __found_sci = false; 
# 205
string __found_grouping; 
# 206
if (__lc->_M_use_grouping) { 
# 207
__found_grouping.reserve(32); }  
# 208
const char_type *__lit_zero = __lit + __num_base::_S_izero; 
# 210
if (!(__lc->_M_allocated)) { 
# 212
while (!__testeof) { 
# 213
{ 
# 214
const int __digit = _M_find(__lit_zero, 10, __c); 
# 215
if (__digit != (-1)) 
# 216
{ 
# 217
(__xtrc += (('0') + __digit)); 
# 218
__found_mantissa = true; 
# 219
} else { 
# 220
if ((__c == (__lc->_M_decimal_point)) && (!__found_dec) && (!__found_sci)) 
# 222
{ 
# 223
(__xtrc += ('.')); 
# 224
__found_dec = true; 
# 225
} else { 
# 226
if (((__c == (__lit[__num_base::_S_ie])) || (__c == (__lit[__num_base::_S_iE]))) && (!__found_sci) && __found_mantissa) 
# 229
{ 
# 231
(__xtrc += ('e')); 
# 232
__found_sci = true; 
# 235
if ((++__beg) != __end) 
# 236
{ 
# 237
__c = (*__beg); 
# 238
const bool __plus = __c == (__lit[__num_base::_S_iplus]); 
# 239
if (__plus || (__c == (__lit[__num_base::_S_iminus]))) { 
# 240
(__xtrc += (__plus ? '+' : '-')); } else { 
# 242
continue; }  
# 243
} else 
# 245
{ 
# 246
__testeof = true; 
# 247
break; 
# 248
}  
# 249
} else { 
# 251
break; }  }  }  
# 253
if ((++__beg) != __end) { 
# 254
__c = (*__beg); } else { 
# 256
__testeof = true; }  
# 257
} }  } else { 
# 259
while (!__testeof) { 
# 260
{ 
# 263
if ((__lc->_M_use_grouping) && (__c == (__lc->_M_thousands_sep))) 
# 264
{ 
# 265
if ((!__found_dec) && (!__found_sci)) 
# 266
{ 
# 269
if (__sep_pos) 
# 270
{ 
# 271
(__found_grouping += (static_cast< char>(__sep_pos))); 
# 272
__sep_pos = 0; 
# 273
} else 
# 275
{ 
# 278
__xtrc.clear(); 
# 279
break; 
# 280
}  
# 281
} else { 
# 283
break; }  
# 284
} else { 
# 285
if (__c == (__lc->_M_decimal_point)) 
# 286
{ 
# 287
if ((!__found_dec) && (!__found_sci)) 
# 288
{ 
# 292
if (__found_grouping.size()) { 
# 293
(__found_grouping += (static_cast< char>(__sep_pos))); }  
# 294
(__xtrc += ('.')); 
# 295
__found_dec = true; 
# 296
} else { 
# 298
break; }  
# 299
} else 
# 301
{ 
# 302
const char_type *__q = __traits_type::find(__lit_zero, 10, __c); 
# 304
if (__q) 
# 305
{ 
# 306
__xtrc += ('0' + (__q - __lit_zero)); 
# 307
__found_mantissa = true; 
# 308
++__sep_pos; 
# 309
} else { 
# 310
if (((__c == (__lit[__num_base::_S_ie])) || (__c == (__lit[__num_base::_S_iE]))) && (!__found_sci) && __found_mantissa) 
# 313
{ 
# 315
if ((__found_grouping.size()) && (!__found_dec)) { 
# 316
(__found_grouping += (static_cast< char>(__sep_pos))); }  
# 317
(__xtrc += ('e')); 
# 318
__found_sci = true; 
# 321
if ((++__beg) != __end) 
# 322
{ 
# 323
__c = (*__beg); 
# 324
const bool __plus = __c == (__lit[__num_base::_S_iplus]); 
# 325
if ((__plus || (__c == (__lit[__num_base::_S_iminus]))) && (!((__lc->_M_use_grouping) && (__c == (__lc->_M_thousands_sep)))) && (!(__c == (__lc->_M_decimal_point)))) { 
# 329
(__xtrc += (__plus ? '+' : '-')); } else { 
# 331
continue; }  
# 332
} else 
# 334
{ 
# 335
__testeof = true; 
# 336
break; 
# 337
}  
# 338
} else { 
# 340
break; }  }  
# 341
}  }  
# 343
if ((++__beg) != __end) { 
# 344
__c = (*__beg); } else { 
# 346
__testeof = true; }  
# 347
} }  }  
# 351
if (__found_grouping.size()) 
# 352
{ 
# 354
if ((!__found_dec) && (!__found_sci)) { 
# 355
(__found_grouping += (static_cast< char>(__sep_pos))); }  
# 357
if (!std::__verify_grouping((__lc->_M_grouping), (__lc->_M_grouping_size), __found_grouping)) { 
# 360
__err = ios_base::failbit; }  
# 361
}  
# 363
return __beg; 
# 364
} 
# 366
template< class _CharT, class _InIter> 
# 367
template< class _ValueT> _InIter 
# 370
num_get< _CharT, _InIter> ::_M_extract_int(_InIter __beg, _InIter __end, ios_base &__io, ios_base::iostate &
# 371
__err, _ValueT &__v) const 
# 372
{ 
# 373
typedef char_traits< _CharT>  __traits_type; 
# 374
using __gnu_cxx::__add_unsigned;
# 375
typedef typename __gnu_cxx::__add_unsigned< _ValueT> ::__type __unsigned_type; 
# 376
typedef __numpunct_cache< _CharT>  __cache_type; 
# 377
__use_cache< __numpunct_cache< _CharT> >  __uc; 
# 378
const locale &__loc = __io._M_getloc(); 
# 379
const __cache_type *__lc = __uc(__loc); 
# 380
const _CharT *__lit = ((__lc->_M_atoms_in)); 
# 381
char_type __c = (char_type()); 
# 384
const ios_base::fmtflags __basefield = ((__io.flags()) & ios_base::basefield); 
# 386
const bool __oct = __basefield == ios_base::oct; 
# 387
int __base = __oct ? 8 : ((__basefield == ios_base::hex) ? 16 : 10); 
# 390
bool __testeof = __beg == __end; 
# 393
bool __negative = false; 
# 394
if (!__testeof) 
# 395
{ 
# 396
__c = (*__beg); 
# 397
__negative = (__c == (__lit[__num_base::_S_iminus])); 
# 398
if ((__negative || (__c == (__lit[__num_base::_S_iplus]))) && (!((__lc->_M_use_grouping) && (__c == (__lc->_M_thousands_sep)))) && (!(__c == (__lc->_M_decimal_point)))) 
# 401
{ 
# 402
if ((++__beg) != __end) { 
# 403
__c = (*__beg); } else { 
# 405
__testeof = true; }  
# 406
}  
# 407
}  
# 411
bool __found_zero = false; 
# 412
int __sep_pos = 0; 
# 413
while (!__testeof) 
# 414
{ 
# 415
if (((__lc->_M_use_grouping) && (__c == (__lc->_M_thousands_sep))) || (__c == (__lc->_M_decimal_point))) { 
# 417
break; } else { 
# 418
if ((__c == (__lit[__num_base::_S_izero])) && ((!__found_zero) || (__base == 10))) 
# 420
{ 
# 421
__found_zero = true; 
# 422
++__sep_pos; 
# 423
if (__basefield == 0) { 
# 424
__base = 8; }  
# 425
if (__base == 8) { 
# 426
__sep_pos = 0; }  
# 427
} else { 
# 428
if (__found_zero && ((__c == (__lit[__num_base::_S_ix])) || (__c == (__lit[__num_base::_S_iX])))) 
# 431
{ 
# 432
if (__basefield == 0) { 
# 433
__base = 16; }  
# 434
if (__base == 16) 
# 435
{ 
# 436
__found_zero = false; 
# 437
__sep_pos = 0; 
# 438
} else { 
# 440
break; }  
# 441
} else { 
# 443
break; }  }  }  
# 445
if ((++__beg) != __end) 
# 446
{ 
# 447
__c = (*__beg); 
# 448
if (!__found_zero) { 
# 449
break; }  
# 450
} else { 
# 452
__testeof = true; }  
# 453
}  
# 457
const size_t __len = (__base == 16) ? (__num_base::_S_iend) - (__num_base::_S_izero) : __base; 
# 461
string __found_grouping; 
# 462
if (__lc->_M_use_grouping) { 
# 463
__found_grouping.reserve(32); }  
# 464
bool __testfail = false; 
# 465
bool __testoverflow = false; 
# 466
const __unsigned_type __max = (__negative && __gnu_cxx::__numeric_traits< _ValueT> ::__is_signed) ? -__gnu_cxx::__numeric_traits< _ValueT> ::__min : __gnu_cxx::__numeric_traits< _ValueT> ::__max; 
# 470
const __unsigned_type __smax = __max / __base; 
# 471
__unsigned_type __result = (0); 
# 472
int __digit = 0; 
# 473
const char_type *__lit_zero = __lit + __num_base::_S_izero; 
# 475
if (!(__lc->_M_allocated)) { 
# 477
while (!__testeof) 
# 478
{ 
# 479
__digit = _M_find(__lit_zero, __len, __c); 
# 480
if (__digit == (-1)) { 
# 481
break; }  
# 483
if (__result > __smax) { 
# 484
__testoverflow = true; } else 
# 486
{ 
# 487
__result *= __base; 
# 488
__testoverflow |= (__result > (__max - __digit)); 
# 489
__result += __digit; 
# 490
++__sep_pos; 
# 491
}  
# 493
if ((++__beg) != __end) { 
# 494
__c = (*__beg); } else { 
# 496
__testeof = true; }  
# 497
}  } else { 
# 499
while (!__testeof) 
# 500
{ 
# 503
if ((__lc->_M_use_grouping) && (__c == (__lc->_M_thousands_sep))) 
# 504
{ 
# 507
if (__sep_pos) 
# 508
{ 
# 509
(__found_grouping += (static_cast< char>(__sep_pos))); 
# 510
__sep_pos = 0; 
# 511
} else 
# 513
{ 
# 514
__testfail = true; 
# 515
break; 
# 516
}  
# 517
} else { 
# 518
if (__c == (__lc->_M_decimal_point)) { 
# 519
break; } else 
# 521
{ 
# 522
const char_type *__q = __traits_type::find(__lit_zero, __len, __c); 
# 524
if (!__q) { 
# 525
break; }  
# 527
__digit = (__q - __lit_zero); 
# 528
if (__digit > 15) { 
# 529
__digit -= 6; }  
# 530
if (__result > __smax) { 
# 531
__testoverflow = true; } else 
# 533
{ 
# 534
__result *= __base; 
# 535
__testoverflow |= (__result > (__max - __digit)); 
# 536
__result += __digit; 
# 537
++__sep_pos; 
# 538
}  
# 539
}  }  
# 541
if ((++__beg) != __end) { 
# 542
__c = (*__beg); } else { 
# 544
__testeof = true; }  
# 545
}  }  
# 549
if (__found_grouping.size()) 
# 550
{ 
# 552
(__found_grouping += (static_cast< char>(__sep_pos))); 
# 554
if (!std::__verify_grouping((__lc->_M_grouping), (__lc->_M_grouping_size), __found_grouping)) { 
# 557
__err = ios_base::failbit; }  
# 558
}  
# 562
if (((!__sep_pos) && (!__found_zero) && (!(__found_grouping.size()))) || __testfail) 
# 564
{ 
# 565
__v = 0; 
# 566
__err = ios_base::failbit; 
# 567
} else { 
# 568
if (__testoverflow) 
# 569
{ 
# 570
if (__negative && __gnu_cxx::__numeric_traits< _ValueT> ::__is_signed) { 
# 572
__v = __gnu_cxx::__numeric_traits< _ValueT> ::__min; } else { 
# 574
__v = __gnu_cxx::__numeric_traits< _ValueT> ::__max; }  
# 575
__err = ios_base::failbit; 
# 576
} else { 
# 578
__v = (__negative ? -__result : __result); }  }  
# 580
if (__testeof) { 
# 581
(__err |= ios_base::eofbit); }  
# 582
return __beg; 
# 583
} 
# 587
template< class _CharT, class _InIter> _InIter 
# 590
num_get< _CharT, _InIter> ::do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 591
__err, bool &__v) const 
# 592
{ 
# 593
if (!(((__io.flags()) & ios_base::boolalpha))) 
# 594
{ 
# 598
long __l = (-1); 
# 599
__beg = _M_extract_int(__beg, __end, __io, __err, __l); 
# 600
if ((__l == (0)) || (__l == (1))) { 
# 601
__v = ((bool)__l); } else 
# 603
{ 
# 606
__v = true; 
# 607
__err = ios_base::failbit; 
# 608
if (__beg == __end) { 
# 609
(__err |= ios_base::eofbit); }  
# 610
}  
# 611
} else 
# 613
{ 
# 615
typedef __numpunct_cache< _CharT>  __cache_type; 
# 616
__use_cache< __numpunct_cache< _CharT> >  __uc; 
# 617
const locale &__loc = __io._M_getloc(); 
# 618
const __cache_type *__lc = __uc(__loc); 
# 620
bool __testf = true; 
# 621
bool __testt = true; 
# 622
bool __donef = (__lc->_M_falsename_size) == 0; 
# 623
bool __donet = (__lc->_M_truename_size) == 0; 
# 624
bool __testeof = false; 
# 625
size_t __n = (0); 
# 626
while ((!__donef) || (!__donet)) 
# 627
{ 
# 628
if (__beg == __end) 
# 629
{ 
# 630
__testeof = true; 
# 631
break; 
# 632
}  
# 634
const char_type __c = *__beg; 
# 636
if (!__donef) { 
# 637
__testf = (__c == ((__lc->_M_falsename)[__n])); }  
# 639
if ((!__testf) && __donet) { 
# 640
break; }  
# 642
if (!__donet) { 
# 643
__testt = (__c == ((__lc->_M_truename)[__n])); }  
# 645
if ((!__testt) && __donef) { 
# 646
break; }  
# 648
if ((!__testt) && (!__testf)) { 
# 649
break; }  
# 651
++__n; 
# 652
++__beg; 
# 654
__donef = ((!__testf) || (__n >= (__lc->_M_falsename_size))); 
# 655
__donet = ((!__testt) || (__n >= (__lc->_M_truename_size))); 
# 656
}  
# 657
if (__testf && (__n == (__lc->_M_falsename_size)) && __n) 
# 658
{ 
# 659
__v = false; 
# 660
if (__testt && (__n == (__lc->_M_truename_size))) { 
# 661
__err = ios_base::failbit; } else { 
# 663
__err = (__testeof ? ios_base::eofbit : ios_base::goodbit); }  
# 664
} else { 
# 665
if (__testt && (__n == (__lc->_M_truename_size)) && __n) 
# 666
{ 
# 667
__v = true; 
# 668
__err = (__testeof ? ios_base::eofbit : ios_base::goodbit); 
# 669
} else 
# 671
{ 
# 674
__v = false; 
# 675
__err = ios_base::failbit; 
# 676
if (__testeof) { 
# 677
(__err |= ios_base::eofbit); }  
# 678
}  }  
# 679
}  
# 680
return __beg; 
# 681
} 
# 683
template< class _CharT, class _InIter> _InIter 
# 686
num_get< _CharT, _InIter> ::do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 687
__err, float &__v) const 
# 688
{ 
# 689
string __xtrc; 
# 690
__xtrc.reserve(32); 
# 691
__beg = _M_extract_float(__beg, __end, __io, __err, __xtrc); 
# 692
std::__convert_to_v(__xtrc.c_str(), __v, __err, _S_get_c_locale()); 
# 693
if (__beg == __end) { 
# 694
(__err |= ios_base::eofbit); }  
# 695
return __beg; 
# 696
} 
# 698
template< class _CharT, class _InIter> _InIter 
# 701
num_get< _CharT, _InIter> ::do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 702
__err, double &__v) const 
# 703
{ 
# 704
string __xtrc; 
# 705
__xtrc.reserve(32); 
# 706
__beg = _M_extract_float(__beg, __end, __io, __err, __xtrc); 
# 707
std::__convert_to_v(__xtrc.c_str(), __v, __err, _S_get_c_locale()); 
# 708
if (__beg == __end) { 
# 709
(__err |= ios_base::eofbit); }  
# 710
return __beg; 
# 711
} 
# 730
template< class _CharT, class _InIter> _InIter 
# 733
num_get< _CharT, _InIter> ::do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 734
__err, long double &__v) const 
# 735
{ 
# 736
string __xtrc; 
# 737
__xtrc.reserve(32); 
# 738
__beg = _M_extract_float(__beg, __end, __io, __err, __xtrc); 
# 739
std::__convert_to_v(__xtrc.c_str(), __v, __err, _S_get_c_locale()); 
# 740
if (__beg == __end) { 
# 741
(__err |= ios_base::eofbit); }  
# 742
return __beg; 
# 743
} 
# 745
template< class _CharT, class _InIter> _InIter 
# 748
num_get< _CharT, _InIter> ::do_get(iter_type __beg, iter_type __end, ios_base &__io, ios_base::iostate &
# 749
__err, void *&__v) const 
# 750
{ 
# 752
typedef ios_base::fmtflags fmtflags; 
# 753
const fmtflags __fmt = __io.flags(); 
# 754
__io.flags((((__fmt & ((~ios_base::basefield)))) | ios_base::hex)); 
# 758
typedef __gnu_cxx::__conditional_type< true, unsigned long, unsigned long long> ::__type _UIntPtrType; 
# 760
_UIntPtrType __ul; 
# 761
__beg = _M_extract_int(__beg, __end, __io, __err, __ul); 
# 764
__io.flags(__fmt); 
# 766
__v = (reinterpret_cast< void *>(__ul)); 
# 767
return __beg; 
# 768
} 
# 772
template< class _CharT, class _OutIter> void 
# 775
num_put< _CharT, _OutIter> ::_M_pad(_CharT __fill, streamsize __w, ios_base &__io, _CharT *
# 776
__new, const _CharT *__cs, int &__len) const 
# 777
{ 
# 780
__pad< _CharT, char_traits< _CharT> > ::_S_pad(__io, __fill, __new, __cs, __w, __len); 
# 782
__len = (static_cast< int>(__w)); 
# 783
} 
# 787
template< class _CharT, class _ValueT> int 
# 789
__int_to_char(_CharT *__bufend, _ValueT __v, const _CharT *__lit, ios_base::fmtflags 
# 790
__flags, bool __dec) 
# 791
{ 
# 792
_CharT *__buf = __bufend; 
# 793
if (__builtin_expect(__dec, true)) 
# 794
{ 
# 796
do 
# 797
{ 
# 798
(*(--__buf)) = (__lit[(__v % 10) + __num_base::_S_odigits]); 
# 799
__v /= 10; 
# 800
} 
# 801
while (__v != 0); 
# 802
} else { 
# 803
if (((__flags & ios_base::basefield)) == ios_base::oct) 
# 804
{ 
# 806
do 
# 807
{ 
# 808
(*(--__buf)) = (__lit[(__v & 7) + __num_base::_S_odigits]); 
# 809
__v >>= 3; 
# 810
} 
# 811
while (__v != 0); 
# 812
} else 
# 814
{ 
# 816
const bool __uppercase = (__flags & ios_base::uppercase); 
# 817
const int __case_offset = __uppercase ? __num_base::_S_oudigits : __num_base::_S_odigits; 
# 819
do 
# 820
{ 
# 821
(*(--__buf)) = (__lit[(__v & 15) + __case_offset]); 
# 822
__v >>= 4; 
# 823
} 
# 824
while (__v != 0); 
# 825
}  }  
# 826
return __bufend - __buf; 
# 827
} 
# 831
template< class _CharT, class _OutIter> void 
# 834
num_put< _CharT, _OutIter> ::_M_group_int(const char *__grouping, size_t __grouping_size, _CharT __sep, ios_base &, _CharT *
# 835
__new, _CharT *__cs, int &__len) const 
# 836
{ 
# 837
_CharT *__p = std::__add_grouping(__new, __sep, __grouping, __grouping_size, __cs, __cs + __len); 
# 839
__len = (__p - __new); 
# 840
} 
# 842
template< class _CharT, class _OutIter> 
# 843
template< class _ValueT> _OutIter 
# 846
num_put< _CharT, _OutIter> ::_M_insert_int(_OutIter __s, ios_base &__io, _CharT __fill, _ValueT 
# 847
__v) const 
# 848
{ 
# 849
using __gnu_cxx::__add_unsigned;
# 850
typedef typename __gnu_cxx::__add_unsigned< _ValueT> ::__type __unsigned_type; 
# 851
typedef __numpunct_cache< _CharT>  __cache_type; 
# 852
__use_cache< __numpunct_cache< _CharT> >  __uc; 
# 853
const locale &__loc = __io._M_getloc(); 
# 854
const __cache_type *__lc = __uc(__loc); 
# 855
const _CharT *__lit = ((__lc->_M_atoms_out)); 
# 856
const ios_base::fmtflags __flags = __io.flags(); 
# 859
const int __ilen = ((5) * sizeof(_ValueT)); 
# 860
_CharT *__cs = static_cast< _CharT *>(__builtin_alloca(sizeof(_CharT) * __ilen)); 
# 865
const ios_base::fmtflags __basefield = (__flags & ios_base::basefield); 
# 866
const bool __dec = (__basefield != ios_base::oct) && (__basefield != ios_base::hex); 
# 868
const __unsigned_type __u = ((__v > 0) || (!__dec)) ? (__unsigned_type)__v : (-((__unsigned_type)__v)); 
# 871
int __len = __int_to_char(__cs + __ilen, __u, __lit, __flags, __dec); 
# 872
__cs += (__ilen - __len); 
# 875
if (__lc->_M_use_grouping) 
# 876
{ 
# 879
_CharT *__cs2 = static_cast< _CharT *>(__builtin_alloca((sizeof(_CharT) * (__len + 1)) * (2))); 
# 882
_M_group_int((__lc->_M_grouping), (__lc->_M_grouping_size), (__lc->_M_thousands_sep), __io, __cs2 + 2, __cs, __len); 
# 884
__cs = (__cs2 + 2); 
# 885
}  
# 888
if (__builtin_expect(__dec, true)) 
# 889
{ 
# 891
if (__v >= 0) 
# 892
{ 
# 893
if (((bool)((__flags & ios_base::showpos))) && __gnu_cxx::__numeric_traits< _ValueT> ::__is_signed) { 
# 895
((*(--__cs)) = (__lit[__num_base::_S_oplus])), (++__len); }  
# 896
} else { 
# 898
((*(--__cs)) = (__lit[__num_base::_S_ominus])), (++__len); }  
# 899
} else { 
# 900
if (((bool)((__flags & ios_base::showbase))) && __v) 
# 901
{ 
# 902
if (__basefield == ios_base::oct) { 
# 903
((*(--__cs)) = (__lit[__num_base::_S_odigits])), (++__len); } else 
# 905
{ 
# 907
const bool __uppercase = (__flags & ios_base::uppercase); 
# 908
(*(--__cs)) = (__lit[(__num_base::_S_ox) + __uppercase]); 
# 910
(*(--__cs)) = (__lit[__num_base::_S_odigits]); 
# 911
__len += 2; 
# 912
}  
# 913
}  }  
# 916
const streamsize __w = __io.width(); 
# 917
if (__w > (static_cast< streamsize>(__len))) 
# 918
{ 
# 919
_CharT *__cs3 = static_cast< _CharT *>(__builtin_alloca(sizeof(_CharT) * __w)); 
# 921
_M_pad(__fill, __w, __io, __cs3, __cs, __len); 
# 922
__cs = __cs3; 
# 923
}  
# 924
__io.width(0); 
# 928
return std::__write(__s, __cs, __len); 
# 929
} 
# 931
template< class _CharT, class _OutIter> void 
# 934
num_put< _CharT, _OutIter> ::_M_group_float(const char *__grouping, size_t __grouping_size, _CharT 
# 935
__sep, const _CharT *__p, _CharT *__new, _CharT *
# 936
__cs, int &__len) const 
# 937
{ 
# 941
const int __declen = (__p) ? __p - __cs : __len; 
# 942
_CharT *__p2 = std::__add_grouping(__new, __sep, __grouping, __grouping_size, __cs, __cs + __declen); 
# 947
int __newlen = __p2 - __new; 
# 948
if (__p) 
# 949
{ 
# 950
char_traits< _CharT> ::copy(__p2, __p, __len - __declen); 
# 951
__newlen += (__len - __declen); 
# 952
}  
# 953
__len = __newlen; 
# 954
} 
# 966
template< class _CharT, class _OutIter> 
# 967
template< class _ValueT> _OutIter 
# 970
num_put< _CharT, _OutIter> ::_M_insert_float(_OutIter __s, ios_base &__io, _CharT __fill, char __mod, _ValueT 
# 971
__v) const 
# 972
{ 
# 973
typedef __numpunct_cache< _CharT>  __cache_type; 
# 974
__use_cache< __numpunct_cache< _CharT> >  __uc; 
# 975
const locale &__loc = __io._M_getloc(); 
# 976
const __cache_type *__lc = __uc(__loc); 
# 979
const streamsize __prec = (__io.precision() < (0)) ? 6 : __io.precision(); 
# 981
const int __max_digits = (__gnu_cxx::__numeric_traits< _ValueT> ::__digits10); 
# 985
int __len; 
# 987
char __fbuf[16]; 
# 988
__num_base::_S_format_float(__io, __fbuf, __mod); 
# 993
int __cs_size = (__max_digits * 3); 
# 994
char *__cs = static_cast< char *>(__builtin_alloca(__cs_size)); 
# 995
__len = std::__convert_from_v(_S_get_c_locale(), __cs, __cs_size, __fbuf, __prec, __v); 
# 999
if (__len >= __cs_size) 
# 1000
{ 
# 1001
__cs_size = (__len + 1); 
# 1002
__cs = (static_cast< char *>(__builtin_alloca(__cs_size))); 
# 1003
__len = std::__convert_from_v(_S_get_c_locale(), __cs, __cs_size, __fbuf, __prec, __v); 
# 1005
}  
# 1027
const ctype< _CharT>  &__ctype = use_facet< ctype< _CharT> > (__loc); 
# 1029
_CharT *__ws = static_cast< _CharT *>(__builtin_alloca(sizeof(_CharT) * __len)); 
# 1031
(__ctype.widen(__cs, __cs + __len, __ws)); 
# 1034
_CharT *__wp = (0); 
# 1035
const char *__p = char_traits< char> ::find(__cs, __len, '.'); 
# 1036
if (__p) 
# 1037
{ 
# 1038
__wp = (__ws + (__p - __cs)); 
# 1039
(*__wp) = (__lc->_M_decimal_point); 
# 1040
}  
# 1045
if ((__lc->_M_use_grouping) && ((__wp || (__len < 3)) || (((__cs[1]) <= ('9')) && ((__cs[2]) <= ('9')) && ((__cs[1]) >= ('0')) && ((__cs[2]) >= ('0'))))) 
# 1048
{ 
# 1051
_CharT *__ws2 = static_cast< _CharT *>(__builtin_alloca((sizeof(_CharT) * __len) * (2))); 
# 1054
streamsize __off = (0); 
# 1055
if (((__cs[0]) == ('-')) || ((__cs[0]) == ('+'))) 
# 1056
{ 
# 1057
__off = (1); 
# 1058
(__ws2[0]) = (__ws[0]); 
# 1059
__len -= 1; 
# 1060
}  
# 1062
_M_group_float((__lc->_M_grouping), (__lc->_M_grouping_size), (__lc->_M_thousands_sep), __wp, __ws2 + __off, __ws + __off, __len); 
# 1065
__len += __off; 
# 1067
__ws = __ws2; 
# 1068
}  
# 1071
const streamsize __w = __io.width(); 
# 1072
if (__w > (static_cast< streamsize>(__len))) 
# 1073
{ 
# 1074
_CharT *__ws3 = static_cast< _CharT *>(__builtin_alloca(sizeof(_CharT) * __w)); 
# 1076
_M_pad(__fill, __w, __io, __ws3, __ws, __len); 
# 1077
__ws = __ws3; 
# 1078
}  
# 1079
__io.width(0); 
# 1083
return std::__write(__s, __ws, __len); 
# 1084
} 
# 1086
template< class _CharT, class _OutIter> _OutIter 
# 1089
num_put< _CharT, _OutIter> ::do_put(iter_type __s, ios_base &__io, char_type __fill, bool __v) const 
# 1090
{ 
# 1091
const ios_base::fmtflags __flags = __io.flags(); 
# 1092
if (((__flags & ios_base::boolalpha)) == 0) 
# 1093
{ 
# 1094
const long __l = __v; 
# 1095
__s = _M_insert_int(__s, __io, __fill, __l); 
# 1096
} else 
# 1098
{ 
# 1099
typedef __numpunct_cache< _CharT>  __cache_type; 
# 1100
__use_cache< __numpunct_cache< _CharT> >  __uc; 
# 1101
const locale &__loc = __io._M_getloc(); 
# 1102
const __cache_type *__lc = __uc(__loc); 
# 1104
const _CharT *__name = __v ? __lc->_M_truename : (__lc->_M_falsename); 
# 1106
int __len = __v ? __lc->_M_truename_size : (__lc->_M_falsename_size); 
# 1109
const streamsize __w = __io.width(); 
# 1110
if (__w > (static_cast< streamsize>(__len))) 
# 1111
{ 
# 1112
const streamsize __plen = __w - __len; 
# 1113
_CharT *__ps = static_cast< _CharT *>(__builtin_alloca(sizeof(_CharT) * __plen)); 
# 1117
char_traits< _CharT> ::assign(__ps, __plen, __fill); 
# 1118
__io.width(0); 
# 1120
if (((__flags & ios_base::adjustfield)) == ios_base::left) 
# 1121
{ 
# 1122
__s = std::__write(__s, __name, __len); 
# 1123
__s = std::__write(__s, __ps, __plen); 
# 1124
} else 
# 1126
{ 
# 1127
__s = std::__write(__s, __ps, __plen); 
# 1128
__s = std::__write(__s, __name, __len); 
# 1129
}  
# 1130
return __s; 
# 1131
}  
# 1132
__io.width(0); 
# 1133
__s = std::__write(__s, __name, __len); 
# 1134
}  
# 1135
return __s; 
# 1136
} 
# 1138
template< class _CharT, class _OutIter> _OutIter 
# 1141
num_put< _CharT, _OutIter> ::do_put(iter_type __s, ios_base &__io, char_type __fill, double __v) const 
# 1142
{ return _M_insert_float(__s, __io, __fill, ((char)0), __v); } 
# 1152
template< class _CharT, class _OutIter> _OutIter 
# 1155
num_put< _CharT, _OutIter> ::do_put(iter_type __s, ios_base &__io, char_type __fill, long double 
# 1156
__v) const 
# 1157
{ return _M_insert_float(__s, __io, __fill, 'L', __v); } 
# 1159
template< class _CharT, class _OutIter> _OutIter 
# 1162
num_put< _CharT, _OutIter> ::do_put(iter_type __s, ios_base &__io, char_type __fill, const void *
# 1163
__v) const 
# 1164
{ 
# 1165
const ios_base::fmtflags __flags = __io.flags(); 
# 1166
const ios_base::fmtflags __fmt = (~((ios_base::basefield | ios_base::uppercase))); 
# 1168
__io.flags((((__flags & __fmt)) | ((ios_base::hex | ios_base::showbase)))); 
# 1172
typedef __gnu_cxx::__conditional_type< true, unsigned long, unsigned long long> ::__type _UIntPtrType; 
# 1174
__s = _M_insert_int(__s, __io, __fill, reinterpret_cast< _UIntPtrType>(__v)); 
# 1176
__io.flags(__flags); 
# 1177
return __s; 
# 1178
} 
# 1189
template< class _CharT, class _Traits> void 
# 1191
__pad< _CharT, _Traits> ::_S_pad(ios_base &__io, _CharT __fill, _CharT *
# 1192
__news, const _CharT *__olds, streamsize 
# 1193
__newlen, streamsize __oldlen) 
# 1194
{ 
# 1195
const size_t __plen = static_cast< size_t>(__newlen - __oldlen); 
# 1196
const ios_base::fmtflags __adjust = ((__io.flags()) & ios_base::adjustfield); 
# 1199
if (__adjust == ios_base::left) 
# 1200
{ 
# 1201
_Traits::copy(__news, __olds, __oldlen); 
# 1202
_Traits::assign(__news + __oldlen, __plen, __fill); 
# 1203
return; 
# 1204
}  
# 1206
size_t __mod = (0); 
# 1207
if (__adjust == ios_base::internal) 
# 1208
{ 
# 1212
const locale &__loc = __io._M_getloc(); 
# 1213
const ctype< _CharT>  &__ctype = use_facet< ctype< _CharT> > (__loc); 
# 1215
if (((__ctype.widen('-')) == (__olds[0])) || ((__ctype.widen('+')) == (__olds[0]))) 
# 1217
{ 
# 1218
(__news[0]) = (__olds[0]); 
# 1219
__mod = (1); 
# 1220
++__news; 
# 1221
} else { 
# 1222
if (((__ctype.widen('0')) == (__olds[0])) && (__oldlen > (1)) && (((__ctype.widen('x')) == (__olds[1])) || ((__ctype.widen('X')) == (__olds[1])))) 
# 1226
{ 
# 1227
(__news[0]) = (__olds[0]); 
# 1228
(__news[1]) = (__olds[1]); 
# 1229
__mod = (2); 
# 1230
__news += 2; 
# 1231
}  }  
# 1233
}  
# 1234
_Traits::assign(__news, __plen, __fill); 
# 1235
_Traits::copy(__news + __plen, __olds + __mod, __oldlen - __mod); 
# 1236
} 
# 1238
template< class _CharT> _CharT *
# 1240
__add_grouping(_CharT *__s, _CharT __sep, const char *
# 1241
__gbeg, size_t __gsize, const _CharT *
# 1242
__first, const _CharT *__last) 
# 1243
{ 
# 1244
size_t __idx = (0); 
# 1245
size_t __ctr = (0); 
# 1247
while (((__last - __first) > (__gbeg[__idx])) && ((static_cast< signed char>(__gbeg[__idx])) > 0) && ((__gbeg[__idx]) != __gnu_cxx::__numeric_traits_integer< char> ::__max)) 
# 1250
{ 
# 1251
__last -= (__gbeg[__idx]); 
# 1252
(__idx < (__gsize - (1))) ? ++__idx : (++__ctr); 
# 1253
}  
# 1255
while (__first != __last) { 
# 1256
(*(__s++)) = (*(__first++)); }  
# 1258
while (__ctr--) 
# 1259
{ 
# 1260
(*(__s++)) = __sep; 
# 1261
for (char __i = __gbeg[__idx]; __i > 0; --__i) { 
# 1262
(*(__s++)) = (*(__first++)); }  
# 1263
}  
# 1265
while (__idx--) 
# 1266
{ 
# 1267
(*(__s++)) = __sep; 
# 1268
for (char __i = __gbeg[__idx]; __i > 0; --__i) { 
# 1269
(*(__s++)) = (*(__first++)); }  
# 1270
}  
# 1272
return __s; 
# 1273
} 
# 1278
extern template class numpunct< char> ;
# 1279
extern template class numpunct_byname< char> ;
# 1280
extern template class num_get< char, istreambuf_iterator< char, char_traits< char> > > ;
# 1281
extern template class num_put< char, ostreambuf_iterator< char, char_traits< char> > > ;
# 1284
extern template const ctype< char>  &use_facet< ctype< char> > (const locale &);
# 1288
extern template const numpunct< char>  &use_facet< numpunct< char> > (const locale &);
# 1292
extern template const num_put< char, ostreambuf_iterator< char, char_traits< char> > >  &use_facet< num_put< char, ostreambuf_iterator< char, char_traits< char> > > > (const locale &);
# 1296
extern template const num_get< char, istreambuf_iterator< char, char_traits< char> > >  &use_facet< num_get< char, istreambuf_iterator< char, char_traits< char> > > > (const locale &);
# 1300
extern template bool has_facet< ctype< char> > (const locale &) throw();
# 1304
extern template bool has_facet< numpunct< char> > (const locale &) throw();
# 1308
extern template bool has_facet< num_put< char, ostreambuf_iterator< char, char_traits< char> > > > (const locale &) throw();
# 1312
extern template bool has_facet< num_get< char, istreambuf_iterator< char, char_traits< char> > > > (const locale &) throw();
# 1317
extern template class numpunct< wchar_t> ;
# 1318
extern template class numpunct_byname< wchar_t> ;
# 1319
extern template class num_get< wchar_t, istreambuf_iterator< wchar_t, char_traits< wchar_t> > > ;
# 1320
extern template class num_put< wchar_t, ostreambuf_iterator< wchar_t, char_traits< wchar_t> > > ;
# 1323
extern template const ctype< wchar_t>  &use_facet< ctype< wchar_t> > (const locale &);
# 1327
extern template const numpunct< wchar_t>  &use_facet< numpunct< wchar_t> > (const locale &);
# 1331
extern template const num_put< wchar_t, ostreambuf_iterator< wchar_t, char_traits< wchar_t> > >  &use_facet< num_put< wchar_t, ostreambuf_iterator< wchar_t, char_traits< wchar_t> > > > (const locale &);
# 1335
extern template const num_get< wchar_t, istreambuf_iterator< wchar_t, char_traits< wchar_t> > >  &use_facet< num_get< wchar_t, istreambuf_iterator< wchar_t, char_traits< wchar_t> > > > (const locale &);
# 1339
extern template bool has_facet< ctype< wchar_t> > (const locale &) throw();
# 1343
extern template bool has_facet< numpunct< wchar_t> > (const locale &) throw();
# 1347
extern template bool has_facet< num_put< wchar_t, ostreambuf_iterator< wchar_t, char_traits< wchar_t> > > > (const locale &) throw();
# 1351
extern template bool has_facet< num_get< wchar_t, istreambuf_iterator< wchar_t, char_traits< wchar_t> > > > (const locale &) throw();
# 1358
}
# 40 "/usr/include/c++/4.8.2/bits/basic_ios.h" 3
namespace std __attribute((__visibility__("default"))) { 
# 44
template< class _Facet> inline const _Facet &
# 46
__check_facet(const _Facet *__f) 
# 47
{ 
# 48
if (!__f) { 
# 49
__throw_bad_cast(); }  
# 50
return *__f; 
# 51
} 
# 65
template< class _CharT, class _Traits> 
# 66
class basic_ios : public ios_base { 
# 75
public: typedef _CharT char_type; 
# 76
typedef typename _Traits::int_type int_type; 
# 77
typedef typename _Traits::pos_type pos_type; 
# 78
typedef typename _Traits::off_type off_type; 
# 79
typedef _Traits traits_type; 
# 86
typedef ctype< _CharT>  __ctype_type; 
# 88
typedef num_put< _CharT, ostreambuf_iterator< _CharT, _Traits> >  __num_put_type; 
# 90
typedef num_get< _CharT, istreambuf_iterator< _CharT, _Traits> >  __num_get_type; 
# 95
protected: basic_ostream< _CharT, _Traits>  *_M_tie; 
# 96
mutable char_type _M_fill; 
# 97
mutable bool _M_fill_init; 
# 98
basic_streambuf< _CharT, _Traits>  *_M_streambuf; 
# 101
const __ctype_type *_M_ctype; 
# 103
const __num_put_type *_M_num_put; 
# 105
const __num_get_type *_M_num_get; 
# 115
public: operator void *() const 
# 116
{ return this->fail() ? 0 : (const_cast< basic_ios *>(this)); } 
# 119
bool operator!() const 
# 120
{ return this->fail(); } 
# 131
iostate rdstate() const 
# 132
{ return ios_base::_M_streambuf_state; } 
# 142
void clear(iostate __state = goodbit); 
# 151
void setstate(iostate __state) 
# 152
{ this->clear(((this->rdstate()) | __state)); } 
# 158
void _M_setstate(iostate __state) 
# 159
{ 
# 162
((ios_base::_M_streambuf_state) |= __state); 
# 163
if (((this->exceptions()) & __state)) { 
# 164
throw; }  
# 165
} 
# 174
bool good() const 
# 175
{ return (this->rdstate()) == 0; } 
# 184
bool eof() const 
# 185
{ return (((this->rdstate()) & eofbit)) != 0; } 
# 195
bool fail() const 
# 196
{ return (((this->rdstate()) & ((badbit | failbit)))) != 0; } 
# 205
bool bad() const 
# 206
{ return (((this->rdstate()) & badbit)) != 0; } 
# 216
iostate exceptions() const 
# 217
{ return ios_base::_M_exception; } 
# 251
void exceptions(iostate __except) 
# 252
{ 
# 253
(ios_base::_M_exception) = __except; 
# 254
this->clear(ios_base::_M_streambuf_state); 
# 255
} 
# 264
explicit basic_ios(basic_streambuf< _CharT, _Traits>  *__sb) : ios_base(), _M_tie((0)), _M_fill(), _M_fill_init(false), _M_streambuf((0)), _M_ctype((0)), _M_num_put((0)), _M_num_get((0)) 
# 267
{ this->init(__sb); } 
# 276
virtual ~basic_ios() { } 
# 289
basic_ostream< _CharT, _Traits>  *tie() const 
# 290
{ return _M_tie; } 
# 301
basic_ostream< _CharT, _Traits>  *tie(basic_ostream< _CharT, _Traits>  *__tiestr) 
# 302
{ 
# 303
basic_ostream< _CharT, _Traits>  *__old = _M_tie; 
# 304
(_M_tie) = __tiestr; 
# 305
return __old; 
# 306
} 
# 315
basic_streambuf< _CharT, _Traits>  *rdbuf() const 
# 316
{ return _M_streambuf; } 
# 341
basic_streambuf< _CharT, _Traits>  *rdbuf(basic_streambuf< _CharT, _Traits>  * __sb); 
# 355
basic_ios &copyfmt(const basic_ios & __rhs); 
# 364
char_type fill() const 
# 365
{ 
# 366
if (!(_M_fill_init)) 
# 367
{ 
# 368
(_M_fill) = this->widen(' '); 
# 369
(_M_fill_init) = true; 
# 370
}  
# 371
return _M_fill; 
# 372
} 
# 384
char_type fill(char_type __ch) 
# 385
{ 
# 386
char_type __old = (this->fill()); 
# 387
(_M_fill) = __ch; 
# 388
return __old; 
# 389
} 
# 404
locale imbue(const locale & __loc); 
# 424
char narrow(char_type __c, char __dfault) const 
# 425
{ return (__check_facet(_M_ctype).narrow(__c, __dfault)); } 
# 443
char_type widen(char __c) const 
# 444
{ return (__check_facet(_M_ctype).widen(__c)); } 
# 454
protected: basic_ios() : ios_base(), _M_tie((0)), _M_fill(char_type()), _M_fill_init(false), _M_streambuf((0)), _M_ctype((0)), _M_num_put((0)), _M_num_get((0)) 
# 457
{ } 
# 466
void init(basic_streambuf< _CharT, _Traits>  * __sb); 
# 469
void _M_cache_locale(const locale & __loc); 
# 470
}; 
# 473
}
# 35 "/usr/include/c++/4.8.2/bits/basic_ios.tcc" 3
namespace std __attribute((__visibility__("default"))) { 
# 39
template< class _CharT, class _Traits> void 
# 41
basic_ios< _CharT, _Traits> ::clear(iostate __state) 
# 42
{ 
# 43
if ((this->rdbuf())) { 
# 44
(ios_base::_M_streambuf_state) = __state; } else { 
# 46
(ios_base::_M_streambuf_state) = ((__state | badbit)); }  
# 47
if (((this->exceptions()) & (this->rdstate()))) { 
# 48
__throw_ios_failure("basic_ios::clear"); }  
# 49
} 
# 51
template< class _CharT, class _Traits> basic_streambuf< _CharT, _Traits>  *
# 53
basic_ios< _CharT, _Traits> ::rdbuf(basic_streambuf< _CharT, _Traits>  *__sb) 
# 54
{ 
# 55
basic_streambuf< _CharT, _Traits>  *__old = _M_streambuf; 
# 56
(_M_streambuf) = __sb; 
# 57
this->clear(); 
# 58
return __old; 
# 59
} 
# 61
template< class _CharT, class _Traits> basic_ios< _CharT, _Traits>  &
# 63
basic_ios< _CharT, _Traits> ::copyfmt(const basic_ios &__rhs) 
# 64
{ 
# 67
if (this != (&__rhs)) 
# 68
{ 
# 73
_Words *__words = ((__rhs.ios_base::_M_word_size) <= (_S_local_word_size)) ? ios_base::_M_local_word : (new _Words [__rhs.ios_base::_M_word_size]); 
# 77
_Callback_list *__cb = __rhs.ios_base::_M_callbacks; 
# 78
if (__cb) { 
# 79
__cb->_M_add_reference(); }  
# 80
this->ios_base::_M_call_callbacks(erase_event); 
# 81
if ((ios_base::_M_word) != (ios_base::_M_local_word)) 
# 82
{ 
# 83
delete [] (ios_base::_M_word); 
# 84
(ios_base::_M_word) = (0); 
# 85
}  
# 86
this->ios_base::_M_dispose_callbacks(); 
# 89
(ios_base::_M_callbacks) = __cb; 
# 90
for (int __i = 0; __i < (__rhs.ios_base::_M_word_size); ++__i) { 
# 91
(__words[__i]) = ((__rhs.ios_base::_M_word)[__i]); }  
# 92
(ios_base::_M_word) = __words; 
# 93
(ios_base::_M_word_size) = (__rhs.ios_base::_M_word_size); 
# 95
this->flags(__rhs.flags()); 
# 96
this->width(__rhs.width()); 
# 97
this->precision(__rhs.precision()); 
# 98
(this->tie((__rhs.tie()))); 
# 99
(this->fill((__rhs.fill()))); 
# 100
((ios_base::_M_ios_locale) = (__rhs.getloc())); 
# 101
_M_cache_locale(ios_base::_M_ios_locale); 
# 103
this->ios_base::_M_call_callbacks(copyfmt_event); 
# 106
this->exceptions(__rhs.exceptions()); 
# 107
}  
# 108
return *this; 
# 109
} 
# 112
template< class _CharT, class _Traits> locale 
# 114
basic_ios< _CharT, _Traits> ::imbue(const locale &__loc) 
# 115
{ 
# 116
locale __old(this->getloc()); 
# 117
this->ios_base::imbue(__loc); 
# 118
_M_cache_locale(__loc); 
# 119
if ((this->rdbuf()) != 0) { 
# 120
((this->rdbuf())->pubimbue(__loc)); }  
# 121
return __old; 
# 122
} 
# 124
template< class _CharT, class _Traits> void 
# 126
basic_ios< _CharT, _Traits> ::init(basic_streambuf< _CharT, _Traits>  *__sb) 
# 127
{ 
# 129
this->ios_base::_M_init(); 
# 132
_M_cache_locale(ios_base::_M_ios_locale); 
# 146
(_M_fill) = _CharT(); 
# 147
(_M_fill_init) = false; 
# 149
(_M_tie) = 0; 
# 150
(ios_base::_M_exception) = goodbit; 
# 151
(_M_streambuf) = __sb; 
# 152
(ios_base::_M_streambuf_state) = ((__sb) ? goodbit : badbit); 
# 153
} 
# 155
template< class _CharT, class _Traits> void 
# 157
basic_ios< _CharT, _Traits> ::_M_cache_locale(const locale &__loc) 
# 158
{ 
# 159
if (__builtin_expect(has_facet< __ctype_type> (__loc), true)) { 
# 160
(_M_ctype) = (&use_facet< __ctype_type> (__loc)); } else { 
# 162
(_M_ctype) = 0; }  
# 164
if (__builtin_expect(has_facet< __num_put_type> (__loc), true)) { 
# 165
(_M_num_put) = (&use_facet< __num_put_type> (__loc)); } else { 
# 167
(_M_num_put) = 0; }  
# 169
if (__builtin_expect(has_facet< __num_get_type> (__loc), true)) { 
# 170
(_M_num_get) = (&use_facet< __num_get_type> (__loc)); } else { 
# 172
(_M_num_get) = 0; }  
# 173
} 
# 178
extern template class basic_ios< char, char_traits< char> > ;
# 181
extern template class basic_ios< wchar_t, char_traits< wchar_t> > ;
# 186
}
# 41 "/usr/include/c++/4.8.2/ostream" 3
namespace std __attribute((__visibility__("default"))) { 
# 57
template< class _CharT, class _Traits> 
# 58
class basic_ostream : virtual public basic_ios< _CharT, _Traits>  { 
# 62
public: typedef _CharT char_type; 
# 63
typedef typename _Traits::int_type int_type; 
# 64
typedef typename _Traits::pos_type pos_type; 
# 65
typedef typename _Traits::off_type off_type; 
# 66
typedef _Traits traits_type; 
# 69
typedef basic_streambuf< _CharT, _Traits>  __streambuf_type; 
# 70
typedef ::std::basic_ios< _CharT, _Traits>  __ios_type; 
# 71
typedef basic_ostream __ostream_type; 
# 73
typedef num_put< _CharT, ostreambuf_iterator< _CharT, _Traits> >  __num_put_type; 
# 74
typedef ctype< _CharT>  __ctype_type; 
# 84
explicit basic_ostream(__streambuf_type *__sb) 
# 85
{ (this->init(__sb)); } 
# 93
virtual ~basic_ostream() { } 
# 96
class sentry; 
# 97
friend class sentry; 
# 108
__ostream_type &operator<<(__ostream_type &(*__pf)(__ostream_type &)) 
# 109
{ 
# 113
return __pf(*this); 
# 114
} 
# 117
__ostream_type &operator<<(__ios_type &(*__pf)(__ios_type &)) 
# 118
{ 
# 122
__pf(*this); 
# 123
return *this; 
# 124
} 
# 127
__ostream_type &operator<<(::std::ios_base &(*__pf)(::std::ios_base &)) 
# 128
{ 
# 132
__pf(*this); 
# 133
return *this; 
# 134
} 
# 166
__ostream_type &operator<<(long __n) 
# 167
{ return _M_insert(__n); } 
# 170
__ostream_type &operator<<(unsigned long __n) 
# 171
{ return _M_insert(__n); } 
# 174
__ostream_type &operator<<(bool __n) 
# 175
{ return _M_insert(__n); } 
# 178
__ostream_type &operator<<(short __n); 
# 181
__ostream_type &operator<<(unsigned short __n) 
# 182
{ 
# 185
return _M_insert(static_cast< unsigned long>(__n)); 
# 186
} 
# 189
__ostream_type &operator<<(int __n); 
# 192
__ostream_type &operator<<(unsigned __n) 
# 193
{ 
# 196
return _M_insert(static_cast< unsigned long>(__n)); 
# 197
} 
# 201
__ostream_type &operator<<(long long __n) 
# 202
{ return _M_insert(__n); } 
# 205
__ostream_type &operator<<(unsigned long long __n) 
# 206
{ return _M_insert(__n); } 
# 220
__ostream_type &operator<<(double __f) 
# 221
{ return _M_insert(__f); } 
# 224
__ostream_type &operator<<(float __f) 
# 225
{ 
# 228
return _M_insert(static_cast< double>(__f)); 
# 229
} 
# 232
__ostream_type &operator<<(long double __f) 
# 233
{ return _M_insert(__f); } 
# 245
__ostream_type &operator<<(const void *__p) 
# 246
{ return _M_insert(__p); } 
# 270
__ostream_type &operator<<(__streambuf_type * __sb); 
# 303
__ostream_type &put(char_type __c); 
# 311
void _M_write(const char_type *__s, ::std::streamsize __n) 
# 312
{ 
# 313
const ::std::streamsize __put = ((this->rdbuf())->sputn(__s, __n)); 
# 314
if (__put != __n) { 
# 315
(this->setstate(ios_base::badbit)); }  
# 316
} 
# 335
__ostream_type &write(const char_type * __s, ::std::streamsize __n); 
# 348
__ostream_type &flush(); 
# 358
pos_type tellp(); 
# 369
__ostream_type &seekp(pos_type); 
# 381
__ostream_type &seekp(off_type, ::std::ios_base::seekdir); 
# 384
protected: basic_ostream() 
# 385
{ (this->init(0)); } 
# 387
template< class _ValueT> __ostream_type &_M_insert(_ValueT __v); 
# 390
}; 
# 399
template< class _CharT, class _Traits> 
# 400
class basic_ostream< _CharT, _Traits> ::sentry { 
# 403
bool _M_ok; 
# 404
basic_ostream &_M_os; 
# 419
public: explicit sentry(basic_ostream & __os); 
# 428
~sentry() 
# 429
{ 
# 431
if (((bool)(((_M_os).flags()) & ios_base::unitbuf)) && (!uncaught_exception())) 
# 432
{ 
# 434
if (((_M_os).rdbuf()) && ((((_M_os).rdbuf())->pubsync()) == (-1))) { 
# 435
((_M_os).setstate(ios_base::badbit)); }  
# 436
}  
# 437
} 
# 449
operator bool() const 
# 450
{ return _M_ok; } 
# 451
}; 
# 469
template< class _CharT, class _Traits> inline basic_ostream< _CharT, _Traits>  &
# 471
operator<<(basic_ostream< _CharT, _Traits>  &__out, _CharT __c) 
# 472
{ return __ostream_insert(__out, &__c, 1); } 
# 474
template< class _CharT, class _Traits> inline basic_ostream< _CharT, _Traits>  &
# 476
operator<<(basic_ostream< _CharT, _Traits>  &__out, char __c) 
# 477
{ return __out << (__out.widen(__c)); } 
# 480
template< class _Traits> inline basic_ostream< char, _Traits>  &
# 482
operator<<(basic_ostream< char, _Traits>  &__out, char __c) 
# 483
{ return __ostream_insert(__out, &__c, 1); } 
# 486
template< class _Traits> inline basic_ostream< char, _Traits>  &
# 488
operator<<(basic_ostream< char, _Traits>  &__out, signed char __c) 
# 489
{ return __out << (static_cast< char>(__c)); } 
# 491
template< class _Traits> inline basic_ostream< char, _Traits>  &
# 493
operator<<(basic_ostream< char, _Traits>  &__out, unsigned char __c) 
# 494
{ return __out << (static_cast< char>(__c)); } 
# 511
template< class _CharT, class _Traits> inline basic_ostream< _CharT, _Traits>  &
# 513
operator<<(basic_ostream< _CharT, _Traits>  &__out, const _CharT *__s) 
# 514
{ 
# 515
if (!__s) { 
# 516
(__out.setstate(ios_base::badbit)); } else { 
# 518
__ostream_insert(__out, __s, static_cast< streamsize>(_Traits::length(__s))); }  
# 520
return __out; 
# 521
} 
# 523
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &operator<<(basic_ostream< _CharT, _Traits>  & __out, const char * __s); 
# 528
template< class _Traits> inline basic_ostream< char, _Traits>  &
# 530
operator<<(basic_ostream< char, _Traits>  &__out, const char *__s) 
# 531
{ 
# 532
if (!__s) { 
# 533
(__out.setstate(ios_base::badbit)); } else { 
# 535
__ostream_insert(__out, __s, static_cast< streamsize>(_Traits::length(__s))); }  
# 537
return __out; 
# 538
} 
# 541
template< class _Traits> inline basic_ostream< char, _Traits>  &
# 543
operator<<(basic_ostream< char, _Traits>  &__out, const signed char *__s) 
# 544
{ return __out << (reinterpret_cast< const char *>(__s)); } 
# 546
template< class _Traits> inline basic_ostream< char, _Traits>  &
# 548
operator<<(basic_ostream< char, _Traits>  &__out, const unsigned char *__s) 
# 549
{ return __out << (reinterpret_cast< const char *>(__s)); } 
# 562
template< class _CharT, class _Traits> inline basic_ostream< _CharT, _Traits>  &
# 564
endl(basic_ostream< _CharT, _Traits>  &__os) 
# 565
{ return flush((__os.put((__os.widen('\n'))))); } 
# 574
template< class _CharT, class _Traits> inline basic_ostream< _CharT, _Traits>  &
# 576
ends(basic_ostream< _CharT, _Traits>  &__os) 
# 577
{ return (__os.put(_CharT())); } 
# 584
template< class _CharT, class _Traits> inline basic_ostream< _CharT, _Traits>  &
# 586
flush(basic_ostream< _CharT, _Traits>  &__os) 
# 587
{ return (__os.flush()); } 
# 610
}
# 41 "/usr/include/c++/4.8.2/bits/ostream.tcc" 3
namespace std __attribute((__visibility__("default"))) { 
# 45
template< class _CharT, class _Traits> 
# 47
basic_ostream< _CharT, _Traits> ::sentry::sentry(basic_ostream &__os) : _M_ok(false), _M_os(__os) 
# 49
{ 
# 51
if ((__os.tie()) && (__os.good())) { 
# 52
((__os.tie())->flush()); }  
# 54
if ((__os.good())) { 
# 55
(_M_ok) = true; } else { 
# 57
(__os.setstate(ios_base::failbit)); }  
# 58
} 
# 60
template< class _CharT, class _Traits> 
# 61
template< class _ValueT> basic_ostream< _CharT, _Traits>  &
# 64
basic_ostream< _CharT, _Traits> ::_M_insert(_ValueT __v) 
# 65
{ 
# 66
sentry __cerb(*this); 
# 67
if (__cerb) 
# 68
{ 
# 69
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 70
try 
# 71
{ 
# 72
const __num_put_type &__np = __check_facet((this->_M_num_put)); 
# 73
if (((__np.put(*this, *this, (this->fill()), __v)).failed())) { 
# 74
(__err |= ::std::ios_base::badbit); }  
# 75
} 
# 76
catch (::__cxxabiv1::__forced_unwind &) 
# 77
{ 
# 78
(this->_M_setstate(ios_base::badbit)); 
# 79
throw; 
# 80
} 
# 81
catch (...) 
# 82
{ (this->_M_setstate(ios_base::badbit)); }  
# 83
if (__err) { 
# 84
(this->setstate(__err)); }  
# 85
}  
# 86
return *this; 
# 87
} 
# 89
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 92
basic_ostream< _CharT, _Traits> ::operator<<(short __n) 
# 93
{ 
# 96
const ::std::ios_base::fmtflags __fmt = (this->flags()) & ios_base::basefield; 
# 97
if ((__fmt == ::std::ios_base::oct) || (__fmt == ::std::ios_base::hex)) { 
# 98
return _M_insert(static_cast< long>(static_cast< unsigned short>(__n))); } else { 
# 100
return _M_insert(static_cast< long>(__n)); }  
# 101
} 
# 103
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 106
basic_ostream< _CharT, _Traits> ::operator<<(int __n) 
# 107
{ 
# 110
const ::std::ios_base::fmtflags __fmt = (this->flags()) & ios_base::basefield; 
# 111
if ((__fmt == ::std::ios_base::oct) || (__fmt == ::std::ios_base::hex)) { 
# 112
return _M_insert(static_cast< long>(static_cast< unsigned>(__n))); } else { 
# 114
return _M_insert(static_cast< long>(__n)); }  
# 115
} 
# 117
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 120
basic_ostream< _CharT, _Traits> ::operator<<(__streambuf_type *__sbin) 
# 121
{ 
# 122
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 123
sentry __cerb(*this); 
# 124
if (__cerb && __sbin) 
# 125
{ 
# 126
try 
# 127
{ 
# 128
if (!__copy_streambufs(__sbin, (this->rdbuf()))) { 
# 129
(__err |= ::std::ios_base::failbit); }  
# 130
} 
# 131
catch (::__cxxabiv1::__forced_unwind &) 
# 132
{ 
# 133
(this->_M_setstate(ios_base::badbit)); 
# 134
throw; 
# 135
} 
# 136
catch (...) 
# 137
{ (this->_M_setstate(ios_base::failbit)); }  
# 138
} else { 
# 139
if (!__sbin) { 
# 140
(__err |= ::std::ios_base::badbit); }  }  
# 141
if (__err) { 
# 142
(this->setstate(__err)); }  
# 143
return *this; 
# 144
} 
# 146
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 149
basic_ostream< _CharT, _Traits> ::put(char_type __c) 
# 150
{ 
# 157
sentry __cerb(*this); 
# 158
if (__cerb) 
# 159
{ 
# 160
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 161
try 
# 162
{ 
# 163
const int_type __put = ((this->rdbuf())->sputc(__c)); 
# 164
if (traits_type::eq_int_type(__put, traits_type::eof())) { 
# 165
(__err |= ::std::ios_base::badbit); }  
# 166
} 
# 167
catch (::__cxxabiv1::__forced_unwind &) 
# 168
{ 
# 169
(this->_M_setstate(ios_base::badbit)); 
# 170
throw; 
# 171
} 
# 172
catch (...) 
# 173
{ (this->_M_setstate(ios_base::badbit)); }  
# 174
if (__err) { 
# 175
(this->setstate(__err)); }  
# 176
}  
# 177
return *this; 
# 178
} 
# 180
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 183
basic_ostream< _CharT, _Traits> ::write(const _CharT *__s, ::std::streamsize __n) 
# 184
{ 
# 192
sentry __cerb(*this); 
# 193
if (__cerb) 
# 194
{ 
# 195
try 
# 196
{ _M_write(__s, __n); } 
# 197
catch (::__cxxabiv1::__forced_unwind &) 
# 198
{ 
# 199
(this->_M_setstate(ios_base::badbit)); 
# 200
throw; 
# 201
} 
# 202
catch (...) 
# 203
{ (this->_M_setstate(ios_base::badbit)); }  
# 204
}  
# 205
return *this; 
# 206
} 
# 208
template< class _CharT, class _Traits> typename basic_ostream< _CharT, _Traits> ::__ostream_type &
# 211
basic_ostream< _CharT, _Traits> ::flush() 
# 212
{ 
# 216
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 217
try 
# 218
{ 
# 219
if ((this->rdbuf()) && (((this->rdbuf())->pubsync()) == (-1))) { 
# 220
(__err |= ::std::ios_base::badbit); }  
# 221
} 
# 222
catch (::__cxxabiv1::__forced_unwind &) 
# 223
{ 
# 224
(this->_M_setstate(ios_base::badbit)); 
# 225
throw; 
# 226
} 
# 227
catch (...) 
# 228
{ (this->_M_setstate(ios_base::badbit)); }  
# 229
if (__err) { 
# 230
(this->setstate(__err)); }  
# 231
return *this; 
# 232
} 
# 234
template< class _CharT, class _Traits> typename basic_ostream< _CharT, _Traits> ::pos_type 
# 237
basic_ostream< _CharT, _Traits> ::tellp() 
# 238
{ 
# 239
pos_type __ret = ((pos_type)(-1)); 
# 240
try 
# 241
{ 
# 242
if (!(this->fail())) { 
# 243
__ret = ((this->rdbuf())->pubseekoff(0, ios_base::cur, ios_base::out)); }  
# 244
} 
# 245
catch (::__cxxabiv1::__forced_unwind &) 
# 246
{ 
# 247
(this->_M_setstate(ios_base::badbit)); 
# 248
throw; 
# 249
} 
# 250
catch (...) 
# 251
{ (this->_M_setstate(ios_base::badbit)); }  
# 252
return __ret; 
# 253
} 
# 255
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 258
basic_ostream< _CharT, _Traits> ::seekp(pos_type __pos) 
# 259
{ 
# 260
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 261
try 
# 262
{ 
# 263
if (!(this->fail())) 
# 264
{ 
# 267
const pos_type __p = ((this->rdbuf())->pubseekpos(__pos, ios_base::out)); 
# 271
if (__p == ((pos_type)((off_type)(-1)))) { 
# 272
(__err |= ::std::ios_base::failbit); }  
# 273
}  
# 274
} 
# 275
catch (::__cxxabiv1::__forced_unwind &) 
# 276
{ 
# 277
(this->_M_setstate(ios_base::badbit)); 
# 278
throw; 
# 279
} 
# 280
catch (...) 
# 281
{ (this->_M_setstate(ios_base::badbit)); }  
# 282
if (__err) { 
# 283
(this->setstate(__err)); }  
# 284
return *this; 
# 285
} 
# 287
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 290
basic_ostream< _CharT, _Traits> ::seekp(off_type __off, ::std::ios_base::seekdir __dir) 
# 291
{ 
# 292
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 293
try 
# 294
{ 
# 295
if (!(this->fail())) 
# 296
{ 
# 299
const pos_type __p = ((this->rdbuf())->pubseekoff(__off, __dir, ios_base::out)); 
# 303
if (__p == ((pos_type)((off_type)(-1)))) { 
# 304
(__err |= ::std::ios_base::failbit); }  
# 305
}  
# 306
} 
# 307
catch (::__cxxabiv1::__forced_unwind &) 
# 308
{ 
# 309
(this->_M_setstate(ios_base::badbit)); 
# 310
throw; 
# 311
} 
# 312
catch (...) 
# 313
{ (this->_M_setstate(ios_base::badbit)); }  
# 314
if (__err) { 
# 315
(this->setstate(__err)); }  
# 316
return *this; 
# 317
} 
# 319
template< class _CharT, class _Traits> basic_ostream< _CharT, _Traits>  &
# 321
operator<<(basic_ostream< _CharT, _Traits>  &__out, const char *__s) 
# 322
{ 
# 323
if (!__s) { 
# 324
(__out.setstate(ios_base::badbit)); } else 
# 326
{ 
# 329
const size_t __clen = char_traits< char> ::length(__s); 
# 330
try 
# 331
{ 
# 332
struct __ptr_guard { 
# 334
_CharT *__p; 
# 335
__ptr_guard(_CharT *__ip) : __p(__ip) { } 
# 336
~__ptr_guard() { delete [] (__p); } 
# 337
_CharT *__get() { return __p; } 
# 338
} __pg(new _CharT [__clen]); 
# 340
_CharT *__ws = __pg.__get(); 
# 341
for (size_t __i = (0); __i < __clen; ++__i) { 
# 342
(__ws[__i]) = (__out.widen(__s[__i])); }  
# 343
__ostream_insert(__out, __ws, __clen); 
# 344
} 
# 345
catch (__cxxabiv1::__forced_unwind &) 
# 346
{ 
# 347
(__out._M_setstate(ios_base::badbit)); 
# 348
throw; 
# 349
} 
# 350
catch (...) 
# 351
{ (__out._M_setstate(ios_base::badbit)); }  
# 352
}  
# 353
return __out; 
# 354
} 
# 359
extern template class basic_ostream< char, char_traits< char> > ;
# 360
extern template basic_ostream< char, char_traits< char> >  &endl(basic_ostream< char, char_traits< char> >  & __os);
# 361
extern template basic_ostream< char, char_traits< char> >  &ends(basic_ostream< char, char_traits< char> >  & __os);
# 362
extern template basic_ostream< char, char_traits< char> >  &flush(basic_ostream< char, char_traits< char> >  & __os);
# 363
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, char __c);
# 364
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, unsigned char __c);
# 365
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, signed char __c);
# 366
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, const char * __s);
# 367
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, const unsigned char * __s);
# 368
extern template basic_ostream< char, char_traits< char> >  &operator<<(basic_ostream< char, char_traits< char> >  & __out, const signed char * __s);
# 370
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(long __v);
# 371
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(unsigned long __v);
# 372
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(bool __v);
# 374
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(long long __v);
# 375
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(unsigned long long __v);
# 377
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(double __v);
# 378
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(long double __v);
# 379
extern template basic_ostream< char, char_traits< char> > ::__ostream_type &basic_ostream< char, char_traits< char> > ::_M_insert(const void * __v);
# 382
extern template class basic_ostream< wchar_t, char_traits< wchar_t> > ;
# 383
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &endl(basic_ostream< wchar_t, char_traits< wchar_t> >  & __os);
# 384
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &ends(basic_ostream< wchar_t, char_traits< wchar_t> >  & __os);
# 385
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &flush(basic_ostream< wchar_t, char_traits< wchar_t> >  & __os);
# 386
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &operator<<(basic_ostream< wchar_t, char_traits< wchar_t> >  & __out, wchar_t __c);
# 387
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &operator<<(basic_ostream< wchar_t, char_traits< wchar_t> >  & __out, char __c);
# 388
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &operator<<(basic_ostream< wchar_t, char_traits< wchar_t> >  & __out, const wchar_t * __s);
# 389
extern template basic_ostream< wchar_t, char_traits< wchar_t> >  &operator<<(basic_ostream< wchar_t, char_traits< wchar_t> >  & __out, const char * __s);
# 391
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(long __v);
# 392
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(unsigned long __v);
# 393
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(bool __v);
# 395
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(long long __v);
# 396
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(unsigned long long __v);
# 398
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(double __v);
# 399
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(long double __v);
# 400
extern template basic_ostream< wchar_t, char_traits< wchar_t> > ::__ostream_type &basic_ostream< wchar_t, char_traits< wchar_t> > ::_M_insert(const void * __v);
# 405
}
# 41 "/usr/include/c++/4.8.2/istream" 3
namespace std __attribute((__visibility__("default"))) { 
# 57
template< class _CharT, class _Traits> 
# 58
class basic_istream : virtual public basic_ios< _CharT, _Traits>  { 
# 62
public: typedef _CharT char_type; 
# 63
typedef typename _Traits::int_type int_type; 
# 64
typedef typename _Traits::pos_type pos_type; 
# 65
typedef typename _Traits::off_type off_type; 
# 66
typedef _Traits traits_type; 
# 69
typedef basic_streambuf< _CharT, _Traits>  __streambuf_type; 
# 70
typedef ::std::basic_ios< _CharT, _Traits>  __ios_type; 
# 71
typedef basic_istream __istream_type; 
# 73
typedef num_get< _CharT, istreambuf_iterator< _CharT, _Traits> >  __num_get_type; 
# 74
typedef ctype< _CharT>  __ctype_type; 
# 82
protected: ::std::streamsize _M_gcount; 
# 93
public: explicit basic_istream(__streambuf_type *__sb) : _M_gcount(((::std::streamsize)0)) 
# 95
{ (this->init(__sb)); } 
# 103
virtual ~basic_istream() 
# 104
{ (_M_gcount) = ((::std::streamsize)0); } 
# 107
class sentry; 
# 108
friend class sentry; 
# 120
__istream_type &operator>>(__istream_type &(*__pf)(__istream_type &)) 
# 121
{ return __pf(*this); } 
# 124
__istream_type &operator>>(__ios_type &(*__pf)(__ios_type &)) 
# 125
{ 
# 126
__pf(*this); 
# 127
return *this; 
# 128
} 
# 131
__istream_type &operator>>(::std::ios_base &(*__pf)(::std::ios_base &)) 
# 132
{ 
# 133
__pf(*this); 
# 134
return *this; 
# 135
} 
# 168
__istream_type &operator>>(bool &__n) 
# 169
{ return _M_extract(__n); } 
# 172
__istream_type &operator>>(short & __n); 
# 175
__istream_type &operator>>(unsigned short &__n) 
# 176
{ return _M_extract(__n); } 
# 179
__istream_type &operator>>(int & __n); 
# 182
__istream_type &operator>>(unsigned &__n) 
# 183
{ return _M_extract(__n); } 
# 186
__istream_type &operator>>(long &__n) 
# 187
{ return _M_extract(__n); } 
# 190
__istream_type &operator>>(unsigned long &__n) 
# 191
{ return _M_extract(__n); } 
# 195
__istream_type &operator>>(long long &__n) 
# 196
{ return _M_extract(__n); } 
# 199
__istream_type &operator>>(unsigned long long &__n) 
# 200
{ return _M_extract(__n); } 
# 214
__istream_type &operator>>(float &__f) 
# 215
{ return _M_extract(__f); } 
# 218
__istream_type &operator>>(double &__f) 
# 219
{ return _M_extract(__f); } 
# 222
__istream_type &operator>>(long double &__f) 
# 223
{ return _M_extract(__f); } 
# 235
__istream_type &operator>>(void *&__p) 
# 236
{ return _M_extract(__p); } 
# 259
__istream_type &operator>>(__streambuf_type * __sb); 
# 269
::std::streamsize gcount() const 
# 270
{ return _M_gcount; } 
# 302
int_type get(); 
# 316
__istream_type &get(char_type & __c); 
# 343
__istream_type &get(char_type * __s, ::std::streamsize __n, char_type __delim); 
# 354
__istream_type &get(char_type *__s, ::std::streamsize __n) 
# 355
{ return (this->get(__s, __n, (this->widen('\n')))); } 
# 377
__istream_type &get(__streambuf_type & __sb, char_type __delim); 
# 387
__istream_type &get(__streambuf_type &__sb) 
# 388
{ return (this->get(__sb, (this->widen('\n')))); } 
# 416
__istream_type &getline(char_type * __s, ::std::streamsize __n, char_type __delim); 
# 427
__istream_type &getline(char_type *__s, ::std::streamsize __n) 
# 428
{ return (this->getline(__s, __n, (this->widen('\n')))); } 
# 451
__istream_type &ignore(::std::streamsize __n, int_type __delim); 
# 454
__istream_type &ignore(::std::streamsize __n); 
# 457
__istream_type &ignore(); 
# 468
int_type peek(); 
# 486
__istream_type &read(char_type * __s, ::std::streamsize __n); 
# 505
::std::streamsize readsome(char_type * __s, ::std::streamsize __n); 
# 522
__istream_type &putback(char_type __c); 
# 538
__istream_type &unget(); 
# 556
int sync(); 
# 571
pos_type tellg(); 
# 586
__istream_type &seekg(pos_type); 
# 602
__istream_type &seekg(off_type, ::std::ios_base::seekdir); 
# 606
protected: basic_istream() : _M_gcount(((::std::streamsize)0)) 
# 608
{ (this->init(0)); } 
# 610
template< class _ValueT> __istream_type &_M_extract(_ValueT & __v); 
# 613
}; 
# 619
template<> basic_istream< char, char_traits< char> >  &basic_istream< char, char_traits< char> > ::getline(char_type * __s, streamsize __n, char_type __delim); 
# 624
template<> basic_istream< char, char_traits< char> >  &basic_istream< char, char_traits< char> > ::ignore(streamsize __n); 
# 629
template<> basic_istream< char, char_traits< char> >  &basic_istream< char, char_traits< char> > ::ignore(streamsize __n, int_type __delim); 
# 635
template<> basic_istream< wchar_t, char_traits< wchar_t> >  &basic_istream< wchar_t, char_traits< wchar_t> > ::getline(char_type * __s, streamsize __n, char_type __delim); 
# 640
template<> basic_istream< wchar_t, char_traits< wchar_t> >  &basic_istream< wchar_t, char_traits< wchar_t> > ::ignore(streamsize __n); 
# 645
template<> basic_istream< wchar_t, char_traits< wchar_t> >  &basic_istream< wchar_t, char_traits< wchar_t> > ::ignore(streamsize __n, int_type __delim); 
# 656
template< class _CharT, class _Traits> 
# 657
class basic_istream< _CharT, _Traits> ::sentry { 
# 660
bool _M_ok; 
# 664
public: typedef _Traits traits_type; 
# 665
typedef basic_streambuf< _CharT, _Traits>  __streambuf_type; 
# 666
typedef basic_istream __istream_type; 
# 667
typedef typename ::std::basic_istream< _CharT, _Traits> ::__ctype_type __ctype_type; 
# 668
typedef typename _Traits::int_type __int_type; 
# 693
explicit sentry(basic_istream & __is, bool __noskipws = false); 
# 705
operator bool() const 
# 706
{ return _M_ok; } 
# 707
}; 
# 721
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &operator>>(basic_istream< _CharT, _Traits>  & __in, _CharT & __c); 
# 725
template< class _Traits> inline basic_istream< char, _Traits>  &
# 727
operator>>(basic_istream< char, _Traits>  &__in, unsigned char &__c) 
# 728
{ return __in >> (reinterpret_cast< char &>(__c)); } 
# 730
template< class _Traits> inline basic_istream< char, _Traits>  &
# 732
operator>>(basic_istream< char, _Traits>  &__in, signed char &__c) 
# 733
{ return __in >> (reinterpret_cast< char &>(__c)); } 
# 763
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &operator>>(basic_istream< _CharT, _Traits>  & __in, _CharT * __s); 
# 770
template<> basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, char * __s); 
# 772
template< class _Traits> inline basic_istream< char, _Traits>  &
# 774
operator>>(basic_istream< char, _Traits>  &__in, unsigned char *__s) 
# 775
{ return __in >> (reinterpret_cast< char *>(__s)); } 
# 777
template< class _Traits> inline basic_istream< char, _Traits>  &
# 779
operator>>(basic_istream< char, _Traits>  &__in, signed char *__s) 
# 780
{ return __in >> (reinterpret_cast< char *>(__s)); } 
# 794
template< class _CharT, class _Traits> 
# 795
class basic_iostream : public basic_istream< _CharT, _Traits> , public basic_ostream< _CharT, _Traits>  { 
# 803
public: typedef _CharT char_type; 
# 804
typedef typename _Traits::int_type int_type; 
# 805
typedef typename _Traits::pos_type pos_type; 
# 806
typedef typename _Traits::off_type off_type; 
# 807
typedef _Traits traits_type; 
# 810
typedef ::std::basic_istream< _CharT, _Traits>  __istream_type; 
# 811
typedef ::std::basic_ostream< _CharT, _Traits>  __ostream_type; 
# 820
explicit basic_iostream(basic_streambuf< _CharT, _Traits>  *__sb) : __istream_type(__sb), __ostream_type(__sb) 
# 821
{ } 
# 827
virtual ~basic_iostream() { } 
# 830
protected: basic_iostream() : __istream_type(), __ostream_type() 
# 831
{ } 
# 832
}; 
# 854
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &ws(basic_istream< _CharT, _Traits>  & __is); 
# 880
}
# 41 "/usr/include/c++/4.8.2/bits/istream.tcc" 3
namespace std __attribute((__visibility__("default"))) { 
# 45
template< class _CharT, class _Traits> 
# 47
basic_istream< _CharT, _Traits> ::sentry::sentry(basic_istream &__in, bool __noskip) : _M_ok(false) 
# 48
{ 
# 49
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 50
if ((__in.good())) 
# 51
{ 
# 52
if ((__in.tie())) { 
# 53
((__in.tie())->flush()); }  
# 54
if ((!__noskip) && ((bool)((__in.flags()) & ios_base::skipws))) 
# 55
{ 
# 56
const __int_type __eof = traits_type::eof(); 
# 57
__streambuf_type *__sb = (__in.rdbuf()); 
# 58
__int_type __c = (__sb->sgetc()); 
# 60
const __ctype_type &__ct = __check_facet((__in._M_ctype)); 
# 61
while ((!traits_type::eq_int_type(__c, __eof)) && (__ct.is(ctype_base::space, traits_type::to_char_type(__c)))) { 
# 64
__c = (__sb->snextc()); }  
# 69
if (traits_type::eq_int_type(__c, __eof)) { 
# 70
(__err |= ::std::ios_base::eofbit); }  
# 71
}  
# 72
}  
# 74
if ((__in.good()) && (__err == ::std::ios_base::goodbit)) { 
# 75
(_M_ok) = true; } else 
# 77
{ 
# 78
(__err |= ::std::ios_base::failbit); 
# 79
(__in.setstate(__err)); 
# 80
}  
# 81
} 
# 83
template< class _CharT, class _Traits> 
# 84
template< class _ValueT> basic_istream< _CharT, _Traits>  &
# 87
basic_istream< _CharT, _Traits> ::_M_extract(_ValueT &__v) 
# 88
{ 
# 89
sentry __cerb(*this, false); 
# 90
if (__cerb) 
# 91
{ 
# 92
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 93
try 
# 94
{ 
# 95
const __num_get_type &__ng = __check_facet((this->_M_num_get)); 
# 96
(__ng.get(*this, 0, *this, __err, __v)); 
# 97
} 
# 98
catch (::__cxxabiv1::__forced_unwind &) 
# 99
{ 
# 100
(this->_M_setstate(ios_base::badbit)); 
# 101
throw; 
# 102
} 
# 103
catch (...) 
# 104
{ (this->_M_setstate(ios_base::badbit)); }  
# 105
if (__err) { 
# 106
(this->setstate(__err)); }  
# 107
}  
# 108
return *this; 
# 109
} 
# 111
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 114
basic_istream< _CharT, _Traits> ::operator>>(short &__n) 
# 115
{ 
# 118
sentry __cerb(*this, false); 
# 119
if (__cerb) 
# 120
{ 
# 121
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 122
try 
# 123
{ 
# 124
long __l; 
# 125
const __num_get_type &__ng = __check_facet((this->_M_num_get)); 
# 126
(__ng.get(*this, 0, *this, __err, __l)); 
# 130
if (__l < ::__gnu_cxx::__numeric_traits_integer< short> ::__min) 
# 131
{ 
# 132
(__err |= ::std::ios_base::failbit); 
# 133
__n = ::__gnu_cxx::__numeric_traits_integer< short> ::__min; 
# 134
} else { 
# 135
if (__l > ::__gnu_cxx::__numeric_traits_integer< short> ::__max) 
# 136
{ 
# 137
(__err |= ::std::ios_base::failbit); 
# 138
__n = ::__gnu_cxx::__numeric_traits_integer< short> ::__max; 
# 139
} else { 
# 141
__n = ((short)__l); }  }  
# 142
} 
# 143
catch (::__cxxabiv1::__forced_unwind &) 
# 144
{ 
# 145
(this->_M_setstate(ios_base::badbit)); 
# 146
throw; 
# 147
} 
# 148
catch (...) 
# 149
{ (this->_M_setstate(ios_base::badbit)); }  
# 150
if (__err) { 
# 151
(this->setstate(__err)); }  
# 152
}  
# 153
return *this; 
# 154
} 
# 156
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 159
basic_istream< _CharT, _Traits> ::operator>>(int &__n) 
# 160
{ 
# 163
sentry __cerb(*this, false); 
# 164
if (__cerb) 
# 165
{ 
# 166
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 167
try 
# 168
{ 
# 169
long __l; 
# 170
const __num_get_type &__ng = __check_facet((this->_M_num_get)); 
# 171
(__ng.get(*this, 0, *this, __err, __l)); 
# 175
if (__l < ::__gnu_cxx::__numeric_traits_integer< int> ::__min) 
# 176
{ 
# 177
(__err |= ::std::ios_base::failbit); 
# 178
__n = ::__gnu_cxx::__numeric_traits_integer< int> ::__min; 
# 179
} else { 
# 180
if (__l > ::__gnu_cxx::__numeric_traits_integer< int> ::__max) 
# 181
{ 
# 182
(__err |= ::std::ios_base::failbit); 
# 183
__n = ::__gnu_cxx::__numeric_traits_integer< int> ::__max; 
# 184
} else { 
# 186
__n = ((int)__l); }  }  
# 187
} 
# 188
catch (::__cxxabiv1::__forced_unwind &) 
# 189
{ 
# 190
(this->_M_setstate(ios_base::badbit)); 
# 191
throw; 
# 192
} 
# 193
catch (...) 
# 194
{ (this->_M_setstate(ios_base::badbit)); }  
# 195
if (__err) { 
# 196
(this->setstate(__err)); }  
# 197
}  
# 198
return *this; 
# 199
} 
# 201
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 204
basic_istream< _CharT, _Traits> ::operator>>(__streambuf_type *__sbout) 
# 205
{ 
# 206
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 207
sentry __cerb(*this, false); 
# 208
if (__cerb && __sbout) 
# 209
{ 
# 210
try 
# 211
{ 
# 212
bool __ineof; 
# 213
if (!__copy_streambufs_eof((this->rdbuf()), __sbout, __ineof)) { 
# 214
(__err |= ::std::ios_base::failbit); }  
# 215
if (__ineof) { 
# 216
(__err |= ::std::ios_base::eofbit); }  
# 217
} 
# 218
catch (::__cxxabiv1::__forced_unwind &) 
# 219
{ 
# 220
(this->_M_setstate(ios_base::failbit)); 
# 221
throw; 
# 222
} 
# 223
catch (...) 
# 224
{ (this->_M_setstate(ios_base::failbit)); }  
# 225
} else { 
# 226
if (!__sbout) { 
# 227
(__err |= ::std::ios_base::failbit); }  }  
# 228
if (__err) { 
# 229
(this->setstate(__err)); }  
# 230
return *this; 
# 231
} 
# 233
template< class _CharT, class _Traits> typename basic_istream< _CharT, _Traits> ::int_type 
# 236
basic_istream< _CharT, _Traits> ::get() 
# 237
{ 
# 238
const int_type __eof = traits_type::eof(); 
# 239
int_type __c = __eof; 
# 240
(_M_gcount) = (0); 
# 241
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 242
sentry __cerb(*this, true); 
# 243
if (__cerb) 
# 244
{ 
# 245
try 
# 246
{ 
# 247
__c = ((this->rdbuf())->sbumpc()); 
# 249
if (!traits_type::eq_int_type(__c, __eof)) { 
# 250
(_M_gcount) = (1); } else { 
# 252
(__err |= ::std::ios_base::eofbit); }  
# 253
} 
# 254
catch (::__cxxabiv1::__forced_unwind &) 
# 255
{ 
# 256
(this->_M_setstate(ios_base::badbit)); 
# 257
throw; 
# 258
} 
# 259
catch (...) 
# 260
{ (this->_M_setstate(ios_base::badbit)); }  
# 261
}  
# 262
if (!(_M_gcount)) { 
# 263
(__err |= ::std::ios_base::failbit); }  
# 264
if (__err) { 
# 265
(this->setstate(__err)); }  
# 266
return __c; 
# 267
} 
# 269
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 272
basic_istream< _CharT, _Traits> ::get(char_type &__c) 
# 273
{ 
# 274
(_M_gcount) = (0); 
# 275
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 276
sentry __cerb(*this, true); 
# 277
if (__cerb) 
# 278
{ 
# 279
try 
# 280
{ 
# 281
const int_type __cb = ((this->rdbuf())->sbumpc()); 
# 283
if (!traits_type::eq_int_type(__cb, traits_type::eof())) 
# 284
{ 
# 285
(_M_gcount) = (1); 
# 286
__c = traits_type::to_char_type(__cb); 
# 287
} else { 
# 289
(__err |= ::std::ios_base::eofbit); }  
# 290
} 
# 291
catch (::__cxxabiv1::__forced_unwind &) 
# 292
{ 
# 293
(this->_M_setstate(ios_base::badbit)); 
# 294
throw; 
# 295
} 
# 296
catch (...) 
# 297
{ (this->_M_setstate(ios_base::badbit)); }  
# 298
}  
# 299
if (!(_M_gcount)) { 
# 300
(__err |= ::std::ios_base::failbit); }  
# 301
if (__err) { 
# 302
(this->setstate(__err)); }  
# 303
return *this; 
# 304
} 
# 306
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 309
basic_istream< _CharT, _Traits> ::get(char_type *__s, ::std::streamsize __n, char_type __delim) 
# 310
{ 
# 311
(_M_gcount) = (0); 
# 312
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 313
sentry __cerb(*this, true); 
# 314
if (__cerb) 
# 315
{ 
# 316
try 
# 317
{ 
# 318
const int_type __idelim = traits_type::to_int_type(__delim); 
# 319
const int_type __eof = traits_type::eof(); 
# 320
__streambuf_type *__sb = (this->rdbuf()); 
# 321
int_type __c = (__sb->sgetc()); 
# 323
while ((((_M_gcount) + (1)) < __n) && (!traits_type::eq_int_type(__c, __eof)) && (!traits_type::eq_int_type(__c, __idelim))) 
# 326
{ 
# 327
(*(__s++)) = traits_type::to_char_type(__c); 
# 328
++(_M_gcount); 
# 329
__c = (__sb->snextc()); 
# 330
}  
# 331
if (traits_type::eq_int_type(__c, __eof)) { 
# 332
(__err |= ::std::ios_base::eofbit); }  
# 333
} 
# 334
catch (::__cxxabiv1::__forced_unwind &) 
# 335
{ 
# 336
(this->_M_setstate(ios_base::badbit)); 
# 337
throw; 
# 338
} 
# 339
catch (...) 
# 340
{ (this->_M_setstate(ios_base::badbit)); }  
# 341
}  
# 344
if (__n > (0)) { 
# 345
(*__s) = char_type(); }  
# 346
if (!(_M_gcount)) { 
# 347
(__err |= ::std::ios_base::failbit); }  
# 348
if (__err) { 
# 349
(this->setstate(__err)); }  
# 350
return *this; 
# 351
} 
# 353
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 356
basic_istream< _CharT, _Traits> ::get(__streambuf_type &__sb, char_type __delim) 
# 357
{ 
# 358
(_M_gcount) = (0); 
# 359
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 360
sentry __cerb(*this, true); 
# 361
if (__cerb) 
# 362
{ 
# 363
try 
# 364
{ 
# 365
const int_type __idelim = traits_type::to_int_type(__delim); 
# 366
const int_type __eof = traits_type::eof(); 
# 367
__streambuf_type *__this_sb = (this->rdbuf()); 
# 368
int_type __c = (__this_sb->sgetc()); 
# 369
char_type __c2 = traits_type::to_char_type(__c); 
# 371
while ((!traits_type::eq_int_type(__c, __eof)) && (!traits_type::eq_int_type(__c, __idelim)) && (!traits_type::eq_int_type((__sb.sputc(__c2)), __eof))) 
# 374
{ 
# 375
++(_M_gcount); 
# 376
__c = (__this_sb->snextc()); 
# 377
__c2 = traits_type::to_char_type(__c); 
# 378
}  
# 379
if (traits_type::eq_int_type(__c, __eof)) { 
# 380
(__err |= ::std::ios_base::eofbit); }  
# 381
} 
# 382
catch (::__cxxabiv1::__forced_unwind &) 
# 383
{ 
# 384
(this->_M_setstate(ios_base::badbit)); 
# 385
throw; 
# 386
} 
# 387
catch (...) 
# 388
{ (this->_M_setstate(ios_base::badbit)); }  
# 389
}  
# 390
if (!(_M_gcount)) { 
# 391
(__err |= ::std::ios_base::failbit); }  
# 392
if (__err) { 
# 393
(this->setstate(__err)); }  
# 394
return *this; 
# 395
} 
# 397
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 400
basic_istream< _CharT, _Traits> ::getline(char_type *__s, ::std::streamsize __n, char_type __delim) 
# 401
{ 
# 402
(_M_gcount) = (0); 
# 403
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 404
sentry __cerb(*this, true); 
# 405
if (__cerb) 
# 406
{ 
# 407
try 
# 408
{ 
# 409
const int_type __idelim = traits_type::to_int_type(__delim); 
# 410
const int_type __eof = traits_type::eof(); 
# 411
__streambuf_type *__sb = (this->rdbuf()); 
# 412
int_type __c = (__sb->sgetc()); 
# 414
while ((((_M_gcount) + (1)) < __n) && (!traits_type::eq_int_type(__c, __eof)) && (!traits_type::eq_int_type(__c, __idelim))) 
# 417
{ 
# 418
(*(__s++)) = traits_type::to_char_type(__c); 
# 419
__c = (__sb->snextc()); 
# 420
++(_M_gcount); 
# 421
}  
# 422
if (traits_type::eq_int_type(__c, __eof)) { 
# 423
(__err |= ::std::ios_base::eofbit); } else 
# 425
{ 
# 426
if (traits_type::eq_int_type(__c, __idelim)) 
# 427
{ 
# 428
(__sb->sbumpc()); 
# 429
++(_M_gcount); 
# 430
} else { 
# 432
(__err |= ::std::ios_base::failbit); }  
# 433
}  
# 434
} 
# 435
catch (::__cxxabiv1::__forced_unwind &) 
# 436
{ 
# 437
(this->_M_setstate(ios_base::badbit)); 
# 438
throw; 
# 439
} 
# 440
catch (...) 
# 441
{ (this->_M_setstate(ios_base::badbit)); }  
# 442
}  
# 445
if (__n > (0)) { 
# 446
(*__s) = char_type(); }  
# 447
if (!(_M_gcount)) { 
# 448
(__err |= ::std::ios_base::failbit); }  
# 449
if (__err) { 
# 450
(this->setstate(__err)); }  
# 451
return *this; 
# 452
} 
# 457
template< class _CharT, class _Traits> typename basic_istream< _CharT, _Traits> ::__istream_type &
# 460
basic_istream< _CharT, _Traits> ::ignore() 
# 461
{ 
# 462
(_M_gcount) = (0); 
# 463
sentry __cerb(*this, true); 
# 464
if (__cerb) 
# 465
{ 
# 466
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 467
try 
# 468
{ 
# 469
const int_type __eof = traits_type::eof(); 
# 470
__streambuf_type *__sb = (this->rdbuf()); 
# 472
if (traits_type::eq_int_type((__sb->sbumpc()), __eof)) { 
# 473
(__err |= ::std::ios_base::eofbit); } else { 
# 475
(_M_gcount) = (1); }  
# 476
} 
# 477
catch (::__cxxabiv1::__forced_unwind &) 
# 478
{ 
# 479
(this->_M_setstate(ios_base::badbit)); 
# 480
throw; 
# 481
} 
# 482
catch (...) 
# 483
{ (this->_M_setstate(ios_base::badbit)); }  
# 484
if (__err) { 
# 485
(this->setstate(__err)); }  
# 486
}  
# 487
return *this; 
# 488
} 
# 490
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 493
basic_istream< _CharT, _Traits> ::ignore(::std::streamsize __n) 
# 494
{ 
# 495
(_M_gcount) = (0); 
# 496
sentry __cerb(*this, true); 
# 497
if (__cerb && (__n > (0))) 
# 498
{ 
# 499
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 500
try 
# 501
{ 
# 502
const int_type __eof = traits_type::eof(); 
# 503
__streambuf_type *__sb = (this->rdbuf()); 
# 504
int_type __c = (__sb->sgetc()); 
# 513
bool __large_ignore = false; 
# 514
while (true) 
# 515
{ 
# 516
while (((_M_gcount) < __n) && (!traits_type::eq_int_type(__c, __eof))) 
# 518
{ 
# 519
++(_M_gcount); 
# 520
__c = (__sb->snextc()); 
# 521
}  
# 522
if ((__n == ::__gnu_cxx::__numeric_traits_integer< long> ::__max) && (!traits_type::eq_int_type(__c, __eof))) 
# 524
{ 
# 525
(_M_gcount) = ::__gnu_cxx::__numeric_traits_integer< long> ::__min; 
# 527
__large_ignore = true; 
# 528
} else { 
# 530
break; }  
# 531
}  
# 533
if (__large_ignore) { 
# 534
(_M_gcount) = ::__gnu_cxx::__numeric_traits_integer< long> ::__max; }  
# 536
if (traits_type::eq_int_type(__c, __eof)) { 
# 537
(__err |= ::std::ios_base::eofbit); }  
# 538
} 
# 539
catch (::__cxxabiv1::__forced_unwind &) 
# 540
{ 
# 541
(this->_M_setstate(ios_base::badbit)); 
# 542
throw; 
# 543
} 
# 544
catch (...) 
# 545
{ (this->_M_setstate(ios_base::badbit)); }  
# 546
if (__err) { 
# 547
(this->setstate(__err)); }  
# 548
}  
# 549
return *this; 
# 550
} 
# 552
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 555
basic_istream< _CharT, _Traits> ::ignore(::std::streamsize __n, int_type __delim) 
# 556
{ 
# 557
(_M_gcount) = (0); 
# 558
sentry __cerb(*this, true); 
# 559
if (__cerb && (__n > (0))) 
# 560
{ 
# 561
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 562
try 
# 563
{ 
# 564
const int_type __eof = traits_type::eof(); 
# 565
__streambuf_type *__sb = (this->rdbuf()); 
# 566
int_type __c = (__sb->sgetc()); 
# 569
bool __large_ignore = false; 
# 570
while (true) 
# 571
{ 
# 572
while (((_M_gcount) < __n) && (!traits_type::eq_int_type(__c, __eof)) && (!traits_type::eq_int_type(__c, __delim))) 
# 575
{ 
# 576
++(_M_gcount); 
# 577
__c = (__sb->snextc()); 
# 578
}  
# 579
if ((__n == ::__gnu_cxx::__numeric_traits_integer< long> ::__max) && (!traits_type::eq_int_type(__c, __eof)) && (!traits_type::eq_int_type(__c, __delim))) 
# 582
{ 
# 583
(_M_gcount) = ::__gnu_cxx::__numeric_traits_integer< long> ::__min; 
# 585
__large_ignore = true; 
# 586
} else { 
# 588
break; }  
# 589
}  
# 591
if (__large_ignore) { 
# 592
(_M_gcount) = ::__gnu_cxx::__numeric_traits_integer< long> ::__max; }  
# 594
if (traits_type::eq_int_type(__c, __eof)) { 
# 595
(__err |= ::std::ios_base::eofbit); } else { 
# 596
if (traits_type::eq_int_type(__c, __delim)) 
# 597
{ 
# 598
if ((_M_gcount) < ::__gnu_cxx::__numeric_traits_integer< long> ::__max) { 
# 600
++(_M_gcount); }  
# 601
(__sb->sbumpc()); 
# 602
}  }  
# 603
} 
# 604
catch (::__cxxabiv1::__forced_unwind &) 
# 605
{ 
# 606
(this->_M_setstate(ios_base::badbit)); 
# 607
throw; 
# 608
} 
# 609
catch (...) 
# 610
{ (this->_M_setstate(ios_base::badbit)); }  
# 611
if (__err) { 
# 612
(this->setstate(__err)); }  
# 613
}  
# 614
return *this; 
# 615
} 
# 617
template< class _CharT, class _Traits> typename basic_istream< _CharT, _Traits> ::int_type 
# 620
basic_istream< _CharT, _Traits> ::peek() 
# 621
{ 
# 622
int_type __c = traits_type::eof(); 
# 623
(_M_gcount) = (0); 
# 624
sentry __cerb(*this, true); 
# 625
if (__cerb) 
# 626
{ 
# 627
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 628
try 
# 629
{ 
# 630
__c = ((this->rdbuf())->sgetc()); 
# 631
if (traits_type::eq_int_type(__c, traits_type::eof())) { 
# 632
(__err |= ::std::ios_base::eofbit); }  
# 633
} 
# 634
catch (::__cxxabiv1::__forced_unwind &) 
# 635
{ 
# 636
(this->_M_setstate(ios_base::badbit)); 
# 637
throw; 
# 638
} 
# 639
catch (...) 
# 640
{ (this->_M_setstate(ios_base::badbit)); }  
# 641
if (__err) { 
# 642
(this->setstate(__err)); }  
# 643
}  
# 644
return __c; 
# 645
} 
# 647
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 650
basic_istream< _CharT, _Traits> ::read(char_type *__s, ::std::streamsize __n) 
# 651
{ 
# 652
(_M_gcount) = (0); 
# 653
sentry __cerb(*this, true); 
# 654
if (__cerb) 
# 655
{ 
# 656
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 657
try 
# 658
{ 
# 659
(_M_gcount) = ((this->rdbuf())->sgetn(__s, __n)); 
# 660
if ((_M_gcount) != __n) { 
# 661
(__err |= ((::std::ios_base::eofbit | ::std::ios_base::failbit))); }  
# 662
} 
# 663
catch (::__cxxabiv1::__forced_unwind &) 
# 664
{ 
# 665
(this->_M_setstate(ios_base::badbit)); 
# 666
throw; 
# 667
} 
# 668
catch (...) 
# 669
{ (this->_M_setstate(ios_base::badbit)); }  
# 670
if (__err) { 
# 671
(this->setstate(__err)); }  
# 672
}  
# 673
return *this; 
# 674
} 
# 676
template< class _CharT, class _Traits> streamsize 
# 679
basic_istream< _CharT, _Traits> ::readsome(char_type *__s, ::std::streamsize __n) 
# 680
{ 
# 681
(_M_gcount) = (0); 
# 682
sentry __cerb(*this, true); 
# 683
if (__cerb) 
# 684
{ 
# 685
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 686
try 
# 687
{ 
# 689
const ::std::streamsize __num = ((this->rdbuf())->in_avail()); 
# 690
if (__num > (0)) { 
# 691
(_M_gcount) = ((this->rdbuf())->sgetn(__s, std::min(__num, __n))); } else { 
# 692
if (__num == (-1)) { 
# 693
(__err |= ::std::ios_base::eofbit); }  }  
# 694
} 
# 695
catch (::__cxxabiv1::__forced_unwind &) 
# 696
{ 
# 697
(this->_M_setstate(ios_base::badbit)); 
# 698
throw; 
# 699
} 
# 700
catch (...) 
# 701
{ (this->_M_setstate(ios_base::badbit)); }  
# 702
if (__err) { 
# 703
(this->setstate(__err)); }  
# 704
}  
# 705
return _M_gcount; 
# 706
} 
# 708
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 711
basic_istream< _CharT, _Traits> ::putback(char_type __c) 
# 712
{ 
# 715
(_M_gcount) = (0); 
# 717
(this->clear((this->rdstate()) & ((~::std::ios_base::eofbit)))); 
# 718
sentry __cerb(*this, true); 
# 719
if (__cerb) 
# 720
{ 
# 721
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 722
try 
# 723
{ 
# 724
const int_type __eof = traits_type::eof(); 
# 725
__streambuf_type *__sb = (this->rdbuf()); 
# 726
if ((!__sb) || traits_type::eq_int_type((__sb->sputbackc(__c)), __eof)) { 
# 728
(__err |= ::std::ios_base::badbit); }  
# 729
} 
# 730
catch (::__cxxabiv1::__forced_unwind &) 
# 731
{ 
# 732
(this->_M_setstate(ios_base::badbit)); 
# 733
throw; 
# 734
} 
# 735
catch (...) 
# 736
{ (this->_M_setstate(ios_base::badbit)); }  
# 737
if (__err) { 
# 738
(this->setstate(__err)); }  
# 739
}  
# 740
return *this; 
# 741
} 
# 743
template< class _CharT, class _Traits> typename basic_istream< _CharT, _Traits> ::__istream_type &
# 746
basic_istream< _CharT, _Traits> ::unget() 
# 747
{ 
# 750
(_M_gcount) = (0); 
# 752
(this->clear((this->rdstate()) & ((~::std::ios_base::eofbit)))); 
# 753
sentry __cerb(*this, true); 
# 754
if (__cerb) 
# 755
{ 
# 756
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 757
try 
# 758
{ 
# 759
const int_type __eof = traits_type::eof(); 
# 760
__streambuf_type *__sb = (this->rdbuf()); 
# 761
if ((!__sb) || traits_type::eq_int_type((__sb->sungetc()), __eof)) { 
# 763
(__err |= ::std::ios_base::badbit); }  
# 764
} 
# 765
catch (::__cxxabiv1::__forced_unwind &) 
# 766
{ 
# 767
(this->_M_setstate(ios_base::badbit)); 
# 768
throw; 
# 769
} 
# 770
catch (...) 
# 771
{ (this->_M_setstate(ios_base::badbit)); }  
# 772
if (__err) { 
# 773
(this->setstate(__err)); }  
# 774
}  
# 775
return *this; 
# 776
} 
# 778
template< class _CharT, class _Traits> int 
# 781
basic_istream< _CharT, _Traits> ::sync() 
# 782
{ 
# 785
int __ret = (-1); 
# 786
sentry __cerb(*this, true); 
# 787
if (__cerb) 
# 788
{ 
# 789
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 790
try 
# 791
{ 
# 792
__streambuf_type *__sb = (this->rdbuf()); 
# 793
if (__sb) 
# 794
{ 
# 795
if ((__sb->pubsync()) == (-1)) { 
# 796
(__err |= ::std::ios_base::badbit); } else { 
# 798
__ret = 0; }  
# 799
}  
# 800
} 
# 801
catch (::__cxxabiv1::__forced_unwind &) 
# 802
{ 
# 803
(this->_M_setstate(ios_base::badbit)); 
# 804
throw; 
# 805
} 
# 806
catch (...) 
# 807
{ (this->_M_setstate(ios_base::badbit)); }  
# 808
if (__err) { 
# 809
(this->setstate(__err)); }  
# 810
}  
# 811
return __ret; 
# 812
} 
# 814
template< class _CharT, class _Traits> typename basic_istream< _CharT, _Traits> ::pos_type 
# 817
basic_istream< _CharT, _Traits> ::tellg() 
# 818
{ 
# 821
pos_type __ret = ((pos_type)(-1)); 
# 822
sentry __cerb(*this, true); 
# 823
if (__cerb) 
# 824
{ 
# 825
try 
# 826
{ 
# 827
if (!(this->fail())) { 
# 828
__ret = ((this->rdbuf())->pubseekoff(0, ios_base::cur, ios_base::in)); }  
# 830
} 
# 831
catch (::__cxxabiv1::__forced_unwind &) 
# 832
{ 
# 833
(this->_M_setstate(ios_base::badbit)); 
# 834
throw; 
# 835
} 
# 836
catch (...) 
# 837
{ (this->_M_setstate(ios_base::badbit)); }  
# 838
}  
# 839
return __ret; 
# 840
} 
# 842
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 845
basic_istream< _CharT, _Traits> ::seekg(pos_type __pos) 
# 846
{ 
# 850
(this->clear((this->rdstate()) & ((~::std::ios_base::eofbit)))); 
# 851
sentry __cerb(*this, true); 
# 852
if (__cerb) 
# 853
{ 
# 854
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 855
try 
# 856
{ 
# 857
if (!(this->fail())) 
# 858
{ 
# 860
const pos_type __p = ((this->rdbuf())->pubseekpos(__pos, ios_base::in)); 
# 864
if (__p == ((pos_type)((off_type)(-1)))) { 
# 865
(__err |= ::std::ios_base::failbit); }  
# 866
}  
# 867
} 
# 868
catch (::__cxxabiv1::__forced_unwind &) 
# 869
{ 
# 870
(this->_M_setstate(ios_base::badbit)); 
# 871
throw; 
# 872
} 
# 873
catch (...) 
# 874
{ (this->_M_setstate(ios_base::badbit)); }  
# 875
if (__err) { 
# 876
(this->setstate(__err)); }  
# 877
}  
# 878
return *this; 
# 879
} 
# 881
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 884
basic_istream< _CharT, _Traits> ::seekg(off_type __off, ::std::ios_base::seekdir __dir) 
# 885
{ 
# 889
(this->clear((this->rdstate()) & ((~::std::ios_base::eofbit)))); 
# 890
sentry __cerb(*this, true); 
# 891
if (__cerb) 
# 892
{ 
# 893
::std::ios_base::iostate __err = ::std::ios_base::goodbit; 
# 894
try 
# 895
{ 
# 896
if (!(this->fail())) 
# 897
{ 
# 899
const pos_type __p = ((this->rdbuf())->pubseekoff(__off, __dir, ios_base::in)); 
# 903
if (__p == ((pos_type)((off_type)(-1)))) { 
# 904
(__err |= ::std::ios_base::failbit); }  
# 905
}  
# 906
} 
# 907
catch (::__cxxabiv1::__forced_unwind &) 
# 908
{ 
# 909
(this->_M_setstate(ios_base::badbit)); 
# 910
throw; 
# 911
} 
# 912
catch (...) 
# 913
{ (this->_M_setstate(ios_base::badbit)); }  
# 914
if (__err) { 
# 915
(this->setstate(__err)); }  
# 916
}  
# 917
return *this; 
# 918
} 
# 921
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 923
operator>>(basic_istream< _CharT, _Traits>  &__in, _CharT &__c) 
# 924
{ 
# 925
typedef basic_istream< _CharT, _Traits>  __istream_type; 
# 926
typedef typename basic_istream< _CharT, _Traits> ::int_type __int_type; 
# 928
typename basic_istream< _CharT, _Traits> ::sentry __cerb(__in, false); 
# 929
if (__cerb) 
# 930
{ 
# 931
ios_base::iostate __err = ios_base::goodbit; 
# 932
try 
# 933
{ 
# 934
const __int_type __cb = ((__in.rdbuf())->sbumpc()); 
# 935
if (!_Traits::eq_int_type(__cb, _Traits::eof())) { 
# 936
__c = _Traits::to_char_type(__cb); } else { 
# 938
(__err |= ((ios_base::eofbit | ios_base::failbit))); }  
# 939
} 
# 940
catch (__cxxabiv1::__forced_unwind &) 
# 941
{ 
# 942
(__in._M_setstate(ios_base::badbit)); 
# 943
throw; 
# 944
} 
# 945
catch (...) 
# 946
{ (__in._M_setstate(ios_base::badbit)); }  
# 947
if (__err) { 
# 948
(__in.setstate(__err)); }  
# 949
}  
# 950
return __in; 
# 951
} 
# 953
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 955
operator>>(basic_istream< _CharT, _Traits>  &__in, _CharT *__s) 
# 956
{ 
# 957
typedef basic_istream< _CharT, _Traits>  __istream_type; 
# 958
typedef basic_streambuf< _CharT, _Traits>  __streambuf_type; 
# 959
typedef typename _Traits::int_type int_type; 
# 960
typedef _CharT char_type; 
# 961
typedef ctype< _CharT>  __ctype_type; 
# 963
streamsize __extracted = (0); 
# 964
ios_base::iostate __err = ios_base::goodbit; 
# 965
typename basic_istream< _CharT, _Traits> ::sentry __cerb(__in, false); 
# 966
if (__cerb) 
# 967
{ 
# 968
try 
# 969
{ 
# 971
streamsize __num = (__in.width()); 
# 972
if (__num <= (0)) { 
# 973
__num = __gnu_cxx::__numeric_traits_integer< long> ::__max; }  
# 975
const __ctype_type &__ct = use_facet< ctype< _CharT> > ((__in.getloc())); 
# 977
const int_type __eof = _Traits::eof(); 
# 978
__streambuf_type *__sb = (__in.rdbuf()); 
# 979
int_type __c = (__sb->sgetc()); 
# 981
while ((__extracted < (__num - (1))) && (!_Traits::eq_int_type(__c, __eof)) && (!(__ct.is(ctype_base::space, _Traits::to_char_type(__c))))) 
# 985
{ 
# 986
(*(__s++)) = _Traits::to_char_type(__c); 
# 987
++__extracted; 
# 988
__c = (__sb->snextc()); 
# 989
}  
# 990
if (_Traits::eq_int_type(__c, __eof)) { 
# 991
(__err |= ios_base::eofbit); }  
# 995
(*__s) = char_type(); 
# 996
(__in.width(0)); 
# 997
} 
# 998
catch (__cxxabiv1::__forced_unwind &) 
# 999
{ 
# 1000
(__in._M_setstate(ios_base::badbit)); 
# 1001
throw; 
# 1002
} 
# 1003
catch (...) 
# 1004
{ (__in._M_setstate(ios_base::badbit)); }  
# 1005
}  
# 1006
if (!__extracted) { 
# 1007
(__err |= ios_base::failbit); }  
# 1008
if (__err) { 
# 1009
(__in.setstate(__err)); }  
# 1010
return __in; 
# 1011
} 
# 1014
template< class _CharT, class _Traits> basic_istream< _CharT, _Traits>  &
# 1016
ws(basic_istream< _CharT, _Traits>  &__in) 
# 1017
{ 
# 1018
typedef basic_istream< _CharT, _Traits>  __istream_type; 
# 1019
typedef basic_streambuf< _CharT, _Traits>  __streambuf_type; 
# 1020
typedef typename basic_istream< _CharT, _Traits> ::int_type __int_type; 
# 1021
typedef ctype< _CharT>  __ctype_type; 
# 1023
const __ctype_type &__ct = use_facet< ctype< _CharT> > ((__in.getloc())); 
# 1024
const __int_type __eof = _Traits::eof(); 
# 1025
__streambuf_type *__sb = (__in.rdbuf()); 
# 1026
__int_type __c = (__sb->sgetc()); 
# 1028
while ((!_Traits::eq_int_type(__c, __eof)) && (__ct.is(ctype_base::space, _Traits::to_char_type(__c)))) { 
# 1030
__c = (__sb->snextc()); }  
# 1032
if (_Traits::eq_int_type(__c, __eof)) { 
# 1033
(__in.setstate(ios_base::eofbit)); }  
# 1034
return __in; 
# 1035
} 
# 1040
extern template class basic_istream< char, char_traits< char> > ;
# 1041
extern template basic_istream< char, char_traits< char> >  &ws(basic_istream< char, char_traits< char> >  & __is);
# 1042
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, char & __c);
# 1043
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  &, char *);
# 1044
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, unsigned char & __c);
# 1045
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, signed char & __c);
# 1046
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, unsigned char * __s);
# 1047
extern template basic_istream< char, char_traits< char> >  &operator>>(basic_istream< char, char_traits< char> >  & __in, signed char * __s);
# 1049
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(unsigned short & __v);
# 1050
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(unsigned & __v);
# 1051
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(long & __v);
# 1052
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(unsigned long & __v);
# 1053
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(bool & __v);
# 1055
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(long long & __v);
# 1056
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(unsigned long long & __v);
# 1058
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(float & __v);
# 1059
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(double & __v);
# 1060
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(long double & __v);
# 1061
extern template basic_istream< char, char_traits< char> > ::__istream_type &basic_istream< char, char_traits< char> > ::_M_extract(void *& __v);
# 1063
extern template class basic_iostream< char, char_traits< char> > ;
# 1066
extern template class basic_istream< wchar_t, char_traits< wchar_t> > ;
# 1067
extern template basic_istream< wchar_t, char_traits< wchar_t> >  &ws(basic_istream< wchar_t, char_traits< wchar_t> >  & __is);
# 1068
extern template basic_istream< wchar_t, char_traits< wchar_t> >  &operator>>(basic_istream< wchar_t, char_traits< wchar_t> >  & __in, wchar_t & __c);
# 1069
extern template basic_istream< wchar_t, char_traits< wchar_t> >  &operator>>(basic_istream< wchar_t, char_traits< wchar_t> >  &, wchar_t *);
# 1071
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(unsigned short & __v);
# 1072
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(unsigned & __v);
# 1073
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(long & __v);
# 1074
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(unsigned long & __v);
# 1075
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(bool & __v);
# 1077
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(long long & __v);
# 1078
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(unsigned long long & __v);
# 1080
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(float & __v);
# 1081
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(double & __v);
# 1082
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(long double & __v);
# 1083
extern template basic_istream< wchar_t, char_traits< wchar_t> > ::__istream_type &basic_istream< wchar_t, char_traits< wchar_t> > ::_M_extract(void *& __v);
# 1085
extern template class basic_iostream< wchar_t, char_traits< wchar_t> > ;
# 1090
}
# 42 "/usr/include/c++/4.8.2/iostream" 3
namespace std __attribute((__visibility__("default"))) { 
# 60
extern istream cin; 
# 61
extern ostream cout; 
# 62
extern ostream cerr; 
# 63
extern ostream clog; 
# 66
extern wistream wcin; 
# 67
extern wostream wcout; 
# 68
extern wostream wcerr; 
# 69
extern wostream wclog; 
# 74
static ios_base::Init __ioinit; 
# 77
}
# 48 "/usr/include/stdint.h" 3
typedef unsigned char uint8_t; 
# 49
typedef unsigned short uint16_t; 
# 51
typedef unsigned uint32_t; 
# 55
typedef unsigned long uint64_t; 
# 65
typedef signed char int_least8_t; 
# 66
typedef short int_least16_t; 
# 67
typedef int int_least32_t; 
# 69
typedef long int_least64_t; 
# 76
typedef unsigned char uint_least8_t; 
# 77
typedef unsigned short uint_least16_t; 
# 78
typedef unsigned uint_least32_t; 
# 80
typedef unsigned long uint_least64_t; 
# 90
typedef signed char int_fast8_t; 
# 92
typedef long int_fast16_t; 
# 93
typedef long int_fast32_t; 
# 94
typedef long int_fast64_t; 
# 103
typedef unsigned char uint_fast8_t; 
# 105
typedef unsigned long uint_fast16_t; 
# 106
typedef unsigned long uint_fast32_t; 
# 107
typedef unsigned long uint_fast64_t; 
# 119
typedef long intptr_t; 
# 122
typedef unsigned long uintptr_t; 
# 134
typedef long intmax_t; 
# 135
typedef unsigned long uintmax_t; 
# 59 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/cuda.h"
typedef uint32_t cuuint32_t; 
# 60
typedef uint64_t cuuint64_t; 
# 211
extern "C" {
# 221
typedef unsigned long long CUdeviceptr; 
# 228
typedef int CUdevice; 
# 229
typedef struct CUctx_st *CUcontext; 
# 230
typedef struct CUmod_st *CUmodule; 
# 231
typedef struct CUfunc_st *CUfunction; 
# 232
typedef struct CUarray_st *CUarray; 
# 233
typedef struct CUmipmappedArray_st *CUmipmappedArray; 
# 234
typedef struct CUtexref_st *CUtexref; 
# 235
typedef struct CUsurfref_st *CUsurfref; 
# 236
typedef CUevent_st *CUevent; 
# 237
typedef CUstream_st *CUstream; 
# 238
typedef struct CUgraphicsResource_st *CUgraphicsResource; 
# 239
typedef unsigned long long CUtexObject; 
# 240
typedef unsigned long long CUsurfObject; 
# 244
typedef 
# 242
struct CUuuid_st { 
# 243
char bytes[16]; 
# 244
} CUuuid; 
# 259
typedef 
# 257
struct CUipcEventHandle_st { 
# 258
char reserved[64]; 
# 259
} CUipcEventHandle; 
# 266
typedef 
# 264
struct CUipcMemHandle_st { 
# 265
char reserved[64]; 
# 266
} CUipcMemHandle; 
# 273
typedef 
# 271
enum CUipcMem_flags_enum { 
# 272
CU_IPC_MEM_LAZY_ENABLE_PEER_ACCESS = 1
# 273
} CUipcMem_flags; 
# 284
typedef 
# 280
enum CUmemAttach_flags_enum { 
# 281
CU_MEM_ATTACH_GLOBAL = 1, 
# 282
CU_MEM_ATTACH_HOST, 
# 283
CU_MEM_ATTACH_SINGLE = 4
# 284
} CUmemAttach_flags; 
# 301
typedef 
# 289
enum CUctx_flags_enum { 
# 290
CU_CTX_SCHED_AUTO, 
# 291
CU_CTX_SCHED_SPIN, 
# 292
CU_CTX_SCHED_YIELD, 
# 293
CU_CTX_SCHED_BLOCKING_SYNC = 4, 
# 294
CU_CTX_BLOCKING_SYNC = 4, 
# 297
CU_CTX_SCHED_MASK = 7, 
# 298
CU_CTX_MAP_HOST, 
# 299
CU_CTX_LMEM_RESIZE_TO_MAX = 16, 
# 300
CU_CTX_FLAGS_MASK = 31
# 301
} CUctx_flags; 
# 309
typedef 
# 306
enum CUstream_flags_enum { 
# 307
CU_STREAM_DEFAULT, 
# 308
CU_STREAM_NON_BLOCKING
# 309
} CUstream_flags; 
# 339
typedef 
# 334
enum CUevent_flags_enum { 
# 335
CU_EVENT_DEFAULT, 
# 336
CU_EVENT_BLOCKING_SYNC, 
# 337
CU_EVENT_DISABLE_TIMING, 
# 338
CU_EVENT_INTERPROCESS = 4
# 339
} CUevent_flags; 
# 357
typedef 
# 345
enum CUstreamWaitValue_flags_enum { 
# 346
CU_STREAM_WAIT_VALUE_GEQ, 
# 348
CU_STREAM_WAIT_VALUE_EQ, 
# 349
CU_STREAM_WAIT_VALUE_AND, 
# 350
CU_STREAM_WAIT_VALUE_FLUSH = 1073741824
# 357
} CUstreamWaitValue_flags; 
# 370
typedef 
# 362
enum CUstreamWriteValue_flags_enum { 
# 363
CU_STREAM_WRITE_VALUE_DEFAULT, 
# 364
CU_STREAM_WRITE_VALUE_NO_MEMORY_BARRIER
# 370
} CUstreamWriteValue_flags; 
# 380
typedef 
# 375
enum CUstreamBatchMemOpType_enum { 
# 376
CU_STREAM_MEM_OP_WAIT_VALUE_32 = 1, 
# 377
CU_STREAM_MEM_OP_WRITE_VALUE_32, 
# 378
CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES
# 380
} CUstreamBatchMemOpType; 
# 412
typedef 
# 385
union CUstreamBatchMemOpParams_union { 
# 386
CUstreamBatchMemOpType operation; 
# 387
struct CUstreamMemOpWaitValueParams_st { 
# 388
CUstreamBatchMemOpType operation; 
# 389
CUdeviceptr address; 
# 390
union { 
# 391
cuuint32_t value; 
# 392
cuuint64_t pad; 
# 393
}; 
# 394
unsigned flags; 
# 395
CUdeviceptr alias; 
# 396
} waitValue; 
# 397
struct CUstreamMemOpWriteValueParams_st { 
# 398
CUstreamBatchMemOpType operation; 
# 399
CUdeviceptr address; 
# 400
union { 
# 401
cuuint32_t value; 
# 402
cuuint64_t pad; 
# 403
}; 
# 404
unsigned flags; 
# 405
CUdeviceptr alias; 
# 406
} writeValue; 
# 407
struct CUstreamMemOpFlushRemoteWritesParams_st { 
# 408
CUstreamBatchMemOpType operation; 
# 409
unsigned flags; 
# 410
} flushRemoteWrites; 
# 411
cuuint64_t pad[6]; 
# 412
} CUstreamBatchMemOpParams; 
# 421
typedef 
# 418
enum CUoccupancy_flags_enum { 
# 419
CU_OCCUPANCY_DEFAULT, 
# 420
CU_OCCUPANCY_DISABLE_CACHING_OVERRIDE
# 421
} CUoccupancy_flags; 
# 435
typedef 
# 426
enum CUarray_format_enum { 
# 427
CU_AD_FORMAT_UNSIGNED_INT8 = 1, 
# 428
CU_AD_FORMAT_UNSIGNED_INT16, 
# 429
CU_AD_FORMAT_UNSIGNED_INT32, 
# 430
CU_AD_FORMAT_SIGNED_INT8 = 8, 
# 431
CU_AD_FORMAT_SIGNED_INT16, 
# 432
CU_AD_FORMAT_SIGNED_INT32, 
# 433
CU_AD_FORMAT_HALF = 16, 
# 434
CU_AD_FORMAT_FLOAT = 32
# 435
} CUarray_format; 
# 445
typedef 
# 440
enum CUaddress_mode_enum { 
# 441
CU_TR_ADDRESS_MODE_WRAP, 
# 442
CU_TR_ADDRESS_MODE_CLAMP, 
# 443
CU_TR_ADDRESS_MODE_MIRROR, 
# 444
CU_TR_ADDRESS_MODE_BORDER
# 445
} CUaddress_mode; 
# 453
typedef 
# 450
enum CUfilter_mode_enum { 
# 451
CU_TR_FILTER_MODE_POINT, 
# 452
CU_TR_FILTER_MODE_LINEAR
# 453
} CUfilter_mode; 
# 556
typedef 
# 458
enum CUdevice_attribute_enum { 
# 459
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_BLOCK = 1, 
# 460
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_X, 
# 461
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Y, 
# 462
CU_DEVICE_ATTRIBUTE_MAX_BLOCK_DIM_Z, 
# 463
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_X, 
# 464
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Y, 
# 465
CU_DEVICE_ATTRIBUTE_MAX_GRID_DIM_Z, 
# 466
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_BLOCK, 
# 467
CU_DEVICE_ATTRIBUTE_SHARED_MEMORY_PER_BLOCK = 8, 
# 468
CU_DEVICE_ATTRIBUTE_TOTAL_CONSTANT_MEMORY, 
# 469
CU_DEVICE_ATTRIBUTE_WARP_SIZE, 
# 470
CU_DEVICE_ATTRIBUTE_MAX_PITCH, 
# 471
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_BLOCK, 
# 472
CU_DEVICE_ATTRIBUTE_REGISTERS_PER_BLOCK = 12, 
# 473
CU_DEVICE_ATTRIBUTE_CLOCK_RATE, 
# 474
CU_DEVICE_ATTRIBUTE_TEXTURE_ALIGNMENT, 
# 475
CU_DEVICE_ATTRIBUTE_GPU_OVERLAP, 
# 476
CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, 
# 477
CU_DEVICE_ATTRIBUTE_KERNEL_EXEC_TIMEOUT, 
# 478
CU_DEVICE_ATTRIBUTE_INTEGRATED, 
# 479
CU_DEVICE_ATTRIBUTE_CAN_MAP_HOST_MEMORY, 
# 480
CU_DEVICE_ATTRIBUTE_COMPUTE_MODE, 
# 481
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_WIDTH, 
# 482
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_WIDTH, 
# 483
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_HEIGHT, 
# 484
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH, 
# 485
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT, 
# 486
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH, 
# 487
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_WIDTH, 
# 488
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_HEIGHT, 
# 489
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LAYERED_LAYERS, 
# 490
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_WIDTH = 27, 
# 491
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_HEIGHT, 
# 492
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_ARRAY_NUMSLICES, 
# 493
CU_DEVICE_ATTRIBUTE_SURFACE_ALIGNMENT, 
# 494
CU_DEVICE_ATTRIBUTE_CONCURRENT_KERNELS, 
# 495
CU_DEVICE_ATTRIBUTE_ECC_ENABLED, 
# 496
CU_DEVICE_ATTRIBUTE_PCI_BUS_ID, 
# 497
CU_DEVICE_ATTRIBUTE_PCI_DEVICE_ID, 
# 498
CU_DEVICE_ATTRIBUTE_TCC_DRIVER, 
# 499
CU_DEVICE_ATTRIBUTE_MEMORY_CLOCK_RATE, 
# 500
CU_DEVICE_ATTRIBUTE_GLOBAL_MEMORY_BUS_WIDTH, 
# 501
CU_DEVICE_ATTRIBUTE_L2_CACHE_SIZE, 
# 502
CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR, 
# 503
CU_DEVICE_ATTRIBUTE_ASYNC_ENGINE_COUNT, 
# 504
CU_DEVICE_ATTRIBUTE_UNIFIED_ADDRESSING, 
# 505
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_WIDTH, 
# 506
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LAYERED_LAYERS, 
# 507
CU_DEVICE_ATTRIBUTE_CAN_TEX2D_GATHER, 
# 508
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_WIDTH, 
# 509
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_GATHER_HEIGHT, 
# 510
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_WIDTH_ALTERNATE, 
# 511
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_HEIGHT_ALTERNATE, 
# 512
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE3D_DEPTH_ALTERNATE, 
# 513
CU_DEVICE_ATTRIBUTE_PCI_DOMAIN_ID, 
# 514
CU_DEVICE_ATTRIBUTE_TEXTURE_PITCH_ALIGNMENT, 
# 515
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_WIDTH, 
# 516
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_WIDTH, 
# 517
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURECUBEMAP_LAYERED_LAYERS, 
# 518
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_WIDTH, 
# 519
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_WIDTH, 
# 520
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_HEIGHT, 
# 521
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_WIDTH, 
# 522
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_HEIGHT, 
# 523
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE3D_DEPTH, 
# 524
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_WIDTH, 
# 525
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE1D_LAYERED_LAYERS, 
# 526
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_WIDTH, 
# 527
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_HEIGHT, 
# 528
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACE2D_LAYERED_LAYERS, 
# 529
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_WIDTH, 
# 530
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_WIDTH, 
# 531
CU_DEVICE_ATTRIBUTE_MAXIMUM_SURFACECUBEMAP_LAYERED_LAYERS, 
# 532
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_LINEAR_WIDTH, 
# 533
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_WIDTH, 
# 534
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_HEIGHT, 
# 535
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_LINEAR_PITCH, 
# 536
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_WIDTH, 
# 537
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE2D_MIPMAPPED_HEIGHT, 
# 538
CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MAJOR, 
# 539
CU_DEVICE_ATTRIBUTE_COMPUTE_CAPABILITY_MINOR, 
# 540
CU_DEVICE_ATTRIBUTE_MAXIMUM_TEXTURE1D_MIPMAPPED_WIDTH, 
# 541
CU_DEVICE_ATTRIBUTE_STREAM_PRIORITIES_SUPPORTED, 
# 542
CU_DEVICE_ATTRIBUTE_GLOBAL_L1_CACHE_SUPPORTED, 
# 543
CU_DEVICE_ATTRIBUTE_LOCAL_L1_CACHE_SUPPORTED, 
# 544
CU_DEVICE_ATTRIBUTE_MAX_SHARED_MEMORY_PER_MULTIPROCESSOR, 
# 545
CU_DEVICE_ATTRIBUTE_MAX_REGISTERS_PER_MULTIPROCESSOR, 
# 546
CU_DEVICE_ATTRIBUTE_MANAGED_MEMORY, 
# 547
CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD, 
# 548
CU_DEVICE_ATTRIBUTE_MULTI_GPU_BOARD_GROUP_ID, 
# 549
CU_DEVICE_ATTRIBUTE_HOST_NATIVE_ATOMIC_SUPPORTED, 
# 550
CU_DEVICE_ATTRIBUTE_SINGLE_TO_DOUBLE_PRECISION_PERF_RATIO, 
# 551
CU_DEVICE_ATTRIBUTE_PAGEABLE_MEMORY_ACCESS, 
# 552
CU_DEVICE_ATTRIBUTE_CONCURRENT_MANAGED_ACCESS, 
# 553
CU_DEVICE_ATTRIBUTE_COMPUTE_PREEMPTION_SUPPORTED, 
# 554
CU_DEVICE_ATTRIBUTE_CAN_USE_HOST_POINTER_FOR_REGISTERED_MEM, 
# 555
CU_DEVICE_ATTRIBUTE_MAX
# 556
} CUdevice_attribute; 
# 572
typedef 
# 561
struct CUdevprop_st { 
# 562
int maxThreadsPerBlock; 
# 563
int maxThreadsDim[3]; 
# 564
int maxGridSize[3]; 
# 565
int sharedMemPerBlock; 
# 566
int totalConstantMemory; 
# 567
int SIMDWidth; 
# 568
int memPitch; 
# 569
int regsPerBlock; 
# 570
int clockRate; 
# 571
int textureAlign; 
# 572
} CUdevprop; 
# 586
typedef 
# 577
enum CUpointer_attribute_enum { 
# 578
CU_POINTER_ATTRIBUTE_CONTEXT = 1, 
# 579
CU_POINTER_ATTRIBUTE_MEMORY_TYPE, 
# 580
CU_POINTER_ATTRIBUTE_DEVICE_POINTER, 
# 581
CU_POINTER_ATTRIBUTE_HOST_POINTER, 
# 582
CU_POINTER_ATTRIBUTE_P2P_TOKENS, 
# 583
CU_POINTER_ATTRIBUTE_SYNC_MEMOPS, 
# 584
CU_POINTER_ATTRIBUTE_BUFFER_ID, 
# 585
CU_POINTER_ATTRIBUTE_IS_MANAGED
# 586
} CUpointer_attribute; 
# 647
typedef 
# 591
enum CUfunction_attribute_enum { 
# 597
CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK, 
# 604
CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES, 
# 610
CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES, 
# 615
CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES, 
# 620
CU_FUNC_ATTRIBUTE_NUM_REGS, 
# 629
CU_FUNC_ATTRIBUTE_PTX_VERSION, 
# 638
CU_FUNC_ATTRIBUTE_BINARY_VERSION, 
# 644
CU_FUNC_ATTRIBUTE_CACHE_MODE_CA, 
# 646
CU_FUNC_ATTRIBUTE_MAX
# 647
} CUfunction_attribute; 
# 657
typedef 
# 652
enum CUfunc_cache_enum { 
# 653
CU_FUNC_CACHE_PREFER_NONE, 
# 654
CU_FUNC_CACHE_PREFER_SHARED, 
# 655
CU_FUNC_CACHE_PREFER_L1, 
# 656
CU_FUNC_CACHE_PREFER_EQUAL
# 657
} CUfunc_cache; 
# 666
typedef 
# 662
enum CUsharedconfig_enum { 
# 663
CU_SHARED_MEM_CONFIG_DEFAULT_BANK_SIZE, 
# 664
CU_SHARED_MEM_CONFIG_FOUR_BYTE_BANK_SIZE, 
# 665
CU_SHARED_MEM_CONFIG_EIGHT_BYTE_BANK_SIZE
# 666
} CUsharedconfig; 
# 676
typedef 
# 671
enum CUmemorytype_enum { 
# 672
CU_MEMORYTYPE_HOST = 1, 
# 673
CU_MEMORYTYPE_DEVICE, 
# 674
CU_MEMORYTYPE_ARRAY, 
# 675
CU_MEMORYTYPE_UNIFIED
# 676
} CUmemorytype; 
# 685
typedef 
# 681
enum CUcomputemode_enum { 
# 682
CU_COMPUTEMODE_DEFAULT, 
# 683
CU_COMPUTEMODE_PROHIBITED = 2, 
# 684
CU_COMPUTEMODE_EXCLUSIVE_PROCESS
# 685
} CUcomputemode; 
# 697
typedef 
# 690
enum CUmem_advise_enum { 
# 691
CU_MEM_ADVISE_SET_READ_MOSTLY = 1, 
# 692
CU_MEM_ADVISE_UNSET_READ_MOSTLY, 
# 693
CU_MEM_ADVISE_SET_PREFERRED_LOCATION, 
# 694
CU_MEM_ADVISE_UNSET_PREFERRED_LOCATION, 
# 695
CU_MEM_ADVISE_SET_ACCESSED_BY, 
# 696
CU_MEM_ADVISE_UNSET_ACCESSED_BY
# 697
} CUmem_advise; 
# 704
typedef 
# 699
enum CUmem_range_attribute_enum { 
# 700
CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY = 1, 
# 701
CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION, 
# 702
CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY, 
# 703
CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION
# 704
} CUmem_range_attribute; 
# 848
typedef 
# 709
enum CUjit_option_enum { 
# 716
CU_JIT_MAX_REGISTERS, 
# 731
CU_JIT_THREADS_PER_BLOCK, 
# 739
CU_JIT_WALL_TIME, 
# 748
CU_JIT_INFO_LOG_BUFFER, 
# 757
CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES, 
# 766
CU_JIT_ERROR_LOG_BUFFER, 
# 775
CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES, 
# 783
CU_JIT_OPTIMIZATION_LEVEL, 
# 791
CU_JIT_TARGET_FROM_CUCONTEXT, 
# 799
CU_JIT_TARGET, 
# 808
CU_JIT_FALLBACK_STRATEGY, 
# 816
CU_JIT_GENERATE_DEBUG_INFO, 
# 823
CU_JIT_LOG_VERBOSE, 
# 830
CU_JIT_GENERATE_LINE_INFO, 
# 838
CU_JIT_CACHE_MODE, 
# 843
CU_JIT_NEW_SM3X_OPT, 
# 844
CU_JIT_FAST_COMPILE, 
# 846
CU_JIT_NUM_OPTIONS
# 848
} CUjit_option; 
# 871
typedef 
# 853
enum CUjit_target_enum { 
# 855
CU_TARGET_COMPUTE_10 = 10, 
# 856
CU_TARGET_COMPUTE_11, 
# 857
CU_TARGET_COMPUTE_12, 
# 858
CU_TARGET_COMPUTE_13, 
# 859
CU_TARGET_COMPUTE_20 = 20, 
# 860
CU_TARGET_COMPUTE_21, 
# 861
CU_TARGET_COMPUTE_30 = 30, 
# 862
CU_TARGET_COMPUTE_32 = 32, 
# 863
CU_TARGET_COMPUTE_35 = 35, 
# 864
CU_TARGET_COMPUTE_37 = 37, 
# 865
CU_TARGET_COMPUTE_50 = 50, 
# 866
CU_TARGET_COMPUTE_52 = 52, 
# 867
CU_TARGET_COMPUTE_53, 
# 868
CU_TARGET_COMPUTE_60 = 60, 
# 869
CU_TARGET_COMPUTE_61, 
# 870
CU_TARGET_COMPUTE_62
# 871
} CUjit_target; 
# 882
typedef 
# 876
enum CUjit_fallback_enum { 
# 878
CU_PREFER_PTX, 
# 880
CU_PREFER_BINARY
# 882
} CUjit_fallback; 
# 892
typedef 
# 887
enum CUjit_cacheMode_enum { 
# 889
CU_JIT_CACHE_OPTION_NONE, 
# 890
CU_JIT_CACHE_OPTION_CG, 
# 891
CU_JIT_CACHE_OPTION_CA
# 892
} CUjit_cacheMode; 
# 930
typedef 
# 897
enum CUjitInputType_enum { 
# 903
CU_JIT_INPUT_CUBIN, 
# 909
CU_JIT_INPUT_PTX, 
# 915
CU_JIT_INPUT_FATBINARY, 
# 921
CU_JIT_INPUT_OBJECT, 
# 927
CU_JIT_INPUT_LIBRARY, 
# 929
CU_JIT_NUM_INPUT_TYPES
# 930
} CUjitInputType; 
# 933
typedef struct CUlinkState_st *CUlinkState; 
# 945
typedef 
# 939
enum CUgraphicsRegisterFlags_enum { 
# 940
CU_GRAPHICS_REGISTER_FLAGS_NONE, 
# 941
CU_GRAPHICS_REGISTER_FLAGS_READ_ONLY, 
# 942
CU_GRAPHICS_REGISTER_FLAGS_WRITE_DISCARD, 
# 943
CU_GRAPHICS_REGISTER_FLAGS_SURFACE_LDST = 4, 
# 944
CU_GRAPHICS_REGISTER_FLAGS_TEXTURE_GATHER = 8
# 945
} CUgraphicsRegisterFlags; 
# 954
typedef 
# 950
enum CUgraphicsMapResourceFlags_enum { 
# 951
CU_GRAPHICS_MAP_RESOURCE_FLAGS_NONE, 
# 952
CU_GRAPHICS_MAP_RESOURCE_FLAGS_READ_ONLY, 
# 953
CU_GRAPHICS_MAP_RESOURCE_FLAGS_WRITE_DISCARD
# 954
} CUgraphicsMapResourceFlags; 
# 966
typedef 
# 959
enum CUarray_cubemap_face_enum { 
# 960
CU_CUBEMAP_FACE_POSITIVE_X, 
# 961
CU_CUBEMAP_FACE_NEGATIVE_X, 
# 962
CU_CUBEMAP_FACE_POSITIVE_Y, 
# 963
CU_CUBEMAP_FACE_NEGATIVE_Y, 
# 964
CU_CUBEMAP_FACE_POSITIVE_Z, 
# 965
CU_CUBEMAP_FACE_NEGATIVE_Z
# 966
} CUarray_cubemap_face; 
# 978
typedef 
# 971
enum CUlimit_enum { 
# 972
CU_LIMIT_STACK_SIZE, 
# 973
CU_LIMIT_PRINTF_FIFO_SIZE, 
# 974
CU_LIMIT_MALLOC_HEAP_SIZE, 
# 975
CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH, 
# 976
CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT, 
# 977
CU_LIMIT_MAX
# 978
} CUlimit; 
# 988
typedef 
# 983
enum CUresourcetype_enum { 
# 984
CU_RESOURCE_TYPE_ARRAY, 
# 985
CU_RESOURCE_TYPE_MIPMAPPED_ARRAY, 
# 986
CU_RESOURCE_TYPE_LINEAR, 
# 987
CU_RESOURCE_TYPE_PITCH2D
# 988
} CUresourcetype; 
# 1390
typedef 
# 993
enum cudaError_enum { 
# 999
CUDA_SUCCESS, 
# 1005
CUDA_ERROR_INVALID_VALUE, 
# 1011
CUDA_ERROR_OUT_OF_MEMORY, 
# 1017
CUDA_ERROR_NOT_INITIALIZED, 
# 1022
CUDA_ERROR_DEINITIALIZED, 
# 1029
CUDA_ERROR_PROFILER_DISABLED, 
# 1037
CUDA_ERROR_PROFILER_NOT_INITIALIZED, 
# 1044
CUDA_ERROR_PROFILER_ALREADY_STARTED, 
# 1051
CUDA_ERROR_PROFILER_ALREADY_STOPPED, 
# 1057
CUDA_ERROR_NO_DEVICE = 100, 
# 1063
CUDA_ERROR_INVALID_DEVICE, 
# 1070
CUDA_ERROR_INVALID_IMAGE = 200, 
# 1080
CUDA_ERROR_INVALID_CONTEXT, 
# 1089
CUDA_ERROR_CONTEXT_ALREADY_CURRENT, 
# 1094
CUDA_ERROR_MAP_FAILED = 205, 
# 1099
CUDA_ERROR_UNMAP_FAILED, 
# 1105
CUDA_ERROR_ARRAY_IS_MAPPED, 
# 1110
CUDA_ERROR_ALREADY_MAPPED, 
# 1118
CUDA_ERROR_NO_BINARY_FOR_GPU, 
# 1123
CUDA_ERROR_ALREADY_ACQUIRED, 
# 1128
CUDA_ERROR_NOT_MAPPED, 
# 1134
CUDA_ERROR_NOT_MAPPED_AS_ARRAY, 
# 1140
CUDA_ERROR_NOT_MAPPED_AS_POINTER, 
# 1146
CUDA_ERROR_ECC_UNCORRECTABLE, 
# 1152
CUDA_ERROR_UNSUPPORTED_LIMIT, 
# 1159
CUDA_ERROR_CONTEXT_ALREADY_IN_USE, 
# 1165
CUDA_ERROR_PEER_ACCESS_UNSUPPORTED, 
# 1170
CUDA_ERROR_INVALID_PTX, 
# 1175
CUDA_ERROR_INVALID_GRAPHICS_CONTEXT, 
# 1181
CUDA_ERROR_NVLINK_UNCORRECTABLE, 
# 1186
CUDA_ERROR_INVALID_SOURCE = 300, 
# 1191
CUDA_ERROR_FILE_NOT_FOUND, 
# 1196
CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND, 
# 1201
CUDA_ERROR_SHARED_OBJECT_INIT_FAILED, 
# 1206
CUDA_ERROR_OPERATING_SYSTEM, 
# 1212
CUDA_ERROR_INVALID_HANDLE = 400, 
# 1218
CUDA_ERROR_NOT_FOUND = 500, 
# 1226
CUDA_ERROR_NOT_READY = 600, 
# 1235
CUDA_ERROR_ILLEGAL_ADDRESS = 700, 
# 1246
CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES, 
# 1257
CUDA_ERROR_LAUNCH_TIMEOUT, 
# 1263
CUDA_ERROR_LAUNCH_INCOMPATIBLE_TEXTURING, 
# 1270
CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED, 
# 1277
CUDA_ERROR_PEER_ACCESS_NOT_ENABLED, 
# 1283
CUDA_ERROR_PRIMARY_CONTEXT_ACTIVE = 708, 
# 1290
CUDA_ERROR_CONTEXT_IS_DESTROYED, 
# 1298
CUDA_ERROR_ASSERT, 
# 1305
CUDA_ERROR_TOO_MANY_PEERS, 
# 1311
CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED, 
# 1317
CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED, 
# 1326
CUDA_ERROR_HARDWARE_STACK_ERROR, 
# 1334
CUDA_ERROR_ILLEGAL_INSTRUCTION, 
# 1343
CUDA_ERROR_MISALIGNED_ADDRESS, 
# 1354
CUDA_ERROR_INVALID_ADDRESS_SPACE, 
# 1362
CUDA_ERROR_INVALID_PC, 
# 1372
CUDA_ERROR_LAUNCH_FAILED, 
# 1378
CUDA_ERROR_NOT_PERMITTED = 800, 
# 1384
CUDA_ERROR_NOT_SUPPORTED, 
# 1389
CUDA_ERROR_UNKNOWN = 999
# 1390
} CUresult; 
# 1399
typedef 
# 1395
enum CUdevice_P2PAttribute_enum { 
# 1396
CU_DEVICE_P2P_ATTRIBUTE_PERFORMANCE_RANK = 1, 
# 1397
CU_DEVICE_P2P_ATTRIBUTE_ACCESS_SUPPORTED, 
# 1398
CU_DEVICE_P2P_ATTRIBUTE_NATIVE_ATOMIC_SUPPORTED
# 1399
} CUdevice_P2PAttribute; 
# 1413
typedef void (*CUstreamCallback)(CUstream hStream, CUresult status, void * userData); 
# 1421
typedef ::size_t (*CUoccupancyB2DSize)(int blockSize); 
# 1497
typedef 
# 1476
struct CUDA_MEMCPY2D_st { 
# 1477
::size_t srcXInBytes; 
# 1478
::size_t srcY; 
# 1480
CUmemorytype srcMemoryType; 
# 1481
const void *srcHost; 
# 1482
CUdeviceptr srcDevice; 
# 1483
CUarray srcArray; 
# 1484
::size_t srcPitch; 
# 1486
::size_t dstXInBytes; 
# 1487
::size_t dstY; 
# 1489
CUmemorytype dstMemoryType; 
# 1490
void *dstHost; 
# 1491
CUdeviceptr dstDevice; 
# 1492
CUarray dstArray; 
# 1493
::size_t dstPitch; 
# 1495
::size_t WidthInBytes; 
# 1496
::size_t Height; 
# 1497
} CUDA_MEMCPY2D; 
# 1530
typedef 
# 1502
struct CUDA_MEMCPY3D_st { 
# 1503
::size_t srcXInBytes; 
# 1504
::size_t srcY; 
# 1505
::size_t srcZ; 
# 1506
::size_t srcLOD; 
# 1507
CUmemorytype srcMemoryType; 
# 1508
const void *srcHost; 
# 1509
CUdeviceptr srcDevice; 
# 1510
CUarray srcArray; 
# 1511
void *reserved0; 
# 1512
::size_t srcPitch; 
# 1513
::size_t srcHeight; 
# 1515
::size_t dstXInBytes; 
# 1516
::size_t dstY; 
# 1517
::size_t dstZ; 
# 1518
::size_t dstLOD; 
# 1519
CUmemorytype dstMemoryType; 
# 1520
void *dstHost; 
# 1521
CUdeviceptr dstDevice; 
# 1522
CUarray dstArray; 
# 1523
void *reserved1; 
# 1524
::size_t dstPitch; 
# 1525
::size_t dstHeight; 
# 1527
::size_t WidthInBytes; 
# 1528
::size_t Height; 
# 1529
::size_t Depth; 
# 1530
} CUDA_MEMCPY3D; 
# 1563
typedef 
# 1535
struct CUDA_MEMCPY3D_PEER_st { 
# 1536
::size_t srcXInBytes; 
# 1537
::size_t srcY; 
# 1538
::size_t srcZ; 
# 1539
::size_t srcLOD; 
# 1540
CUmemorytype srcMemoryType; 
# 1541
const void *srcHost; 
# 1542
CUdeviceptr srcDevice; 
# 1543
CUarray srcArray; 
# 1544
CUcontext srcContext; 
# 1545
::size_t srcPitch; 
# 1546
::size_t srcHeight; 
# 1548
::size_t dstXInBytes; 
# 1549
::size_t dstY; 
# 1550
::size_t dstZ; 
# 1551
::size_t dstLOD; 
# 1552
CUmemorytype dstMemoryType; 
# 1553
void *dstHost; 
# 1554
CUdeviceptr dstDevice; 
# 1555
CUarray dstArray; 
# 1556
CUcontext dstContext; 
# 1557
::size_t dstPitch; 
# 1558
::size_t dstHeight; 
# 1560
::size_t WidthInBytes; 
# 1561
::size_t Height; 
# 1562
::size_t Depth; 
# 1563
} CUDA_MEMCPY3D_PEER; 
# 1575
typedef 
# 1568
struct CUDA_ARRAY_DESCRIPTOR_st { 
# 1570
::size_t Width; 
# 1571
::size_t Height; 
# 1573
CUarray_format Format; 
# 1574
unsigned NumChannels; 
# 1575
} CUDA_ARRAY_DESCRIPTOR; 
# 1589
typedef 
# 1580
struct CUDA_ARRAY3D_DESCRIPTOR_st { 
# 1582
::size_t Width; 
# 1583
::size_t Height; 
# 1584
::size_t Depth; 
# 1586
CUarray_format Format; 
# 1587
unsigned NumChannels; 
# 1588
unsigned Flags; 
# 1589
} CUDA_ARRAY3D_DESCRIPTOR; 
# 1629
typedef 
# 1598
struct CUDA_RESOURCE_DESC_st { 
# 1600
CUresourcetype resType; 
# 1602
union { 
# 1603
struct { 
# 1604
CUarray hArray; 
# 1605
} array; 
# 1606
struct { 
# 1607
CUmipmappedArray hMipmappedArray; 
# 1608
} mipmap; 
# 1609
struct { 
# 1610
CUdeviceptr devPtr; 
# 1611
CUarray_format format; 
# 1612
unsigned numChannels; 
# 1613
::size_t sizeInBytes; 
# 1614
} linear; 
# 1615
struct { 
# 1616
CUdeviceptr devPtr; 
# 1617
CUarray_format format; 
# 1618
unsigned numChannels; 
# 1619
::size_t width; 
# 1620
::size_t height; 
# 1621
::size_t pitchInBytes; 
# 1622
} pitch2D; 
# 1623
struct { 
# 1624
int reserved[32]; 
# 1625
} reserved; 
# 1626
} res; 
# 1628
unsigned flags; 
# 1629
} CUDA_RESOURCE_DESC; 
# 1645
typedef 
# 1634
struct CUDA_TEXTURE_DESC_st { 
# 1635
CUaddress_mode addressMode[3]; 
# 1636
CUfilter_mode filterMode; 
# 1637
unsigned flags; 
# 1638
unsigned maxAnisotropy; 
# 1639
CUfilter_mode mipmapFilterMode; 
# 1640
float mipmapLevelBias; 
# 1641
float minMipmapLevelClamp; 
# 1642
float maxMipmapLevelClamp; 
# 1643
float borderColor[4]; 
# 1644
int reserved[12]; 
# 1645
} CUDA_TEXTURE_DESC; 
# 1687
typedef 
# 1650
enum CUresourceViewFormat_enum { 
# 1652
CU_RES_VIEW_FORMAT_NONE, 
# 1653
CU_RES_VIEW_FORMAT_UINT_1X8, 
# 1654
CU_RES_VIEW_FORMAT_UINT_2X8, 
# 1655
CU_RES_VIEW_FORMAT_UINT_4X8, 
# 1656
CU_RES_VIEW_FORMAT_SINT_1X8, 
# 1657
CU_RES_VIEW_FORMAT_SINT_2X8, 
# 1658
CU_RES_VIEW_FORMAT_SINT_4X8, 
# 1659
CU_RES_VIEW_FORMAT_UINT_1X16, 
# 1660
CU_RES_VIEW_FORMAT_UINT_2X16, 
# 1661
CU_RES_VIEW_FORMAT_UINT_4X16, 
# 1662
CU_RES_VIEW_FORMAT_SINT_1X16, 
# 1663
CU_RES_VIEW_FORMAT_SINT_2X16, 
# 1664
CU_RES_VIEW_FORMAT_SINT_4X16, 
# 1665
CU_RES_VIEW_FORMAT_UINT_1X32, 
# 1666
CU_RES_VIEW_FORMAT_UINT_2X32, 
# 1667
CU_RES_VIEW_FORMAT_UINT_4X32, 
# 1668
CU_RES_VIEW_FORMAT_SINT_1X32, 
# 1669
CU_RES_VIEW_FORMAT_SINT_2X32, 
# 1670
CU_RES_VIEW_FORMAT_SINT_4X32, 
# 1671
CU_RES_VIEW_FORMAT_FLOAT_1X16, 
# 1672
CU_RES_VIEW_FORMAT_FLOAT_2X16, 
# 1673
CU_RES_VIEW_FORMAT_FLOAT_4X16, 
# 1674
CU_RES_VIEW_FORMAT_FLOAT_1X32, 
# 1675
CU_RES_VIEW_FORMAT_FLOAT_2X32, 
# 1676
CU_RES_VIEW_FORMAT_FLOAT_4X32, 
# 1677
CU_RES_VIEW_FORMAT_UNSIGNED_BC1, 
# 1678
CU_RES_VIEW_FORMAT_UNSIGNED_BC2, 
# 1679
CU_RES_VIEW_FORMAT_UNSIGNED_BC3, 
# 1680
CU_RES_VIEW_FORMAT_UNSIGNED_BC4, 
# 1681
CU_RES_VIEW_FORMAT_SIGNED_BC4, 
# 1682
CU_RES_VIEW_FORMAT_UNSIGNED_BC5, 
# 1683
CU_RES_VIEW_FORMAT_SIGNED_BC5, 
# 1684
CU_RES_VIEW_FORMAT_UNSIGNED_BC6H, 
# 1685
CU_RES_VIEW_FORMAT_SIGNED_BC6H, 
# 1686
CU_RES_VIEW_FORMAT_UNSIGNED_BC7
# 1687
} CUresourceViewFormat; 
# 1703
typedef 
# 1692
struct CUDA_RESOURCE_VIEW_DESC_st { 
# 1694
CUresourceViewFormat format; 
# 1695
::size_t width; 
# 1696
::size_t height; 
# 1697
::size_t depth; 
# 1698
unsigned firstMipmapLevel; 
# 1699
unsigned lastMipmapLevel; 
# 1700
unsigned firstLayer; 
# 1701
unsigned lastLayer; 
# 1702
unsigned reserved[16]; 
# 1703
} CUDA_RESOURCE_VIEW_DESC; 
# 1711
typedef 
# 1708
struct CUDA_POINTER_ATTRIBUTE_P2P_TOKENS_st { 
# 1709
unsigned long long p2pToken; 
# 1710
unsigned vaSpaceToken; 
# 1711
} CUDA_POINTER_ATTRIBUTE_P2P_TOKENS; 
# 1858
CUresult cuGetErrorString(CUresult error, const char ** pStr); 
# 1877
CUresult cuGetErrorName(CUresult error, const char ** pStr); 
# 1909
CUresult cuInit(unsigned Flags); 
# 1939
CUresult cuDriverGetVersion(int * driverVersion); 
# 1979
CUresult cuDeviceGet(CUdevice * device, int ordinal); 
# 2004
CUresult cuDeviceGetCount(int * count); 
# 2032
CUresult cuDeviceGetName(char * name, int len, CUdevice dev); 
# 2059
CUresult cuDeviceTotalMem_v2(::size_t * bytes, CUdevice dev); 
# 2254
CUresult cuDeviceGetAttribute(int * pi, CUdevice_attribute attrib, CUdevice dev); 
# 2331
CUresult cuDeviceGetProperties(CUdevprop * prop, CUdevice dev); 
# 2364
CUresult cuDeviceComputeCapability(int * major, int * minor, CUdevice dev); 
# 2432
CUresult cuDevicePrimaryCtxRetain(CUcontext * pctx, CUdevice dev); 
# 2466
CUresult cuDevicePrimaryCtxRelease(CUdevice dev); 
# 2529
CUresult cuDevicePrimaryCtxSetFlags(CUdevice dev, unsigned flags); 
# 2553
CUresult cuDevicePrimaryCtxGetState(CUdevice dev, unsigned * flags, int * active); 
# 2591
CUresult cuDevicePrimaryCtxReset(CUdevice dev); 
# 2697
CUresult cuCtxCreate_v2(CUcontext * pctx, unsigned flags, CUdevice dev); 
# 2737
CUresult cuCtxDestroy_v2(CUcontext ctx); 
# 2773
CUresult cuCtxPushCurrent_v2(CUcontext ctx); 
# 2807
CUresult cuCtxPopCurrent_v2(CUcontext * pctx); 
# 2833
CUresult cuCtxSetCurrent(CUcontext ctx); 
# 2852
CUresult cuCtxGetCurrent(CUcontext * pctx); 
# 2882
CUresult cuCtxGetDevice(CUdevice * device); 
# 2910
CUresult cuCtxGetFlags(unsigned * flags); 
# 2940
CUresult cuCtxSynchronize(); 
# 3035
CUresult cuCtxSetLimit(CUlimit limit, ::size_t value); 
# 3074
CUresult cuCtxGetLimit(::size_t * pvalue, CUlimit limit); 
# 3117
CUresult cuCtxGetCacheConfig(CUfunc_cache * pconfig); 
# 3167
CUresult cuCtxSetCacheConfig(CUfunc_cache config); 
# 3209
CUresult cuCtxGetSharedMemConfig(CUsharedconfig * pConfig); 
# 3261
CUresult cuCtxSetSharedMemConfig(CUsharedconfig config); 
# 3299
CUresult cuCtxGetApiVersion(CUcontext ctx, unsigned * version); 
# 3338
CUresult cuCtxGetStreamPriorityRange(int * leastPriority, int * greatestPriority); 
# 3393
CUresult cuCtxAttach(CUcontext * pctx, unsigned flags); 
# 3429
CUresult cuCtxDetach(CUcontext ctx); 
# 3483
CUresult cuModuleLoad(CUmodule * module, const char * fname); 
# 3519
CUresult cuModuleLoadData(CUmodule * module, const void * image); 
# 3561
CUresult cuModuleLoadDataEx(CUmodule * module, const void * image, unsigned numOptions, CUjit_option * options, void ** optionValues); 
# 3602
CUresult cuModuleLoadFatBinary(CUmodule * module, const void * fatCubin); 
# 3627
CUresult cuModuleUnload(CUmodule hmod); 
# 3657
CUresult cuModuleGetFunction(CUfunction * hfunc, CUmodule hmod, const char * name); 
# 3691
CUresult cuModuleGetGlobal_v2(CUdeviceptr * dptr, ::size_t * bytes, CUmodule hmod, const char * name); 
# 3725
CUresult cuModuleGetTexRef(CUtexref * pTexRef, CUmodule hmod, const char * name); 
# 3756
CUresult cuModuleGetSurfRef(CUsurfref * pSurfRef, CUmodule hmod, const char * name); 
# 3798
CUresult cuLinkCreate_v2(unsigned numOptions, CUjit_option * options, void ** optionValues, CUlinkState * stateOut); 
# 3835
CUresult cuLinkAddData_v2(CUlinkState state, CUjitInputType type, void * data, ::size_t size, const char * name, unsigned numOptions, CUjit_option * options, void ** optionValues); 
# 3874
CUresult cuLinkAddFile_v2(CUlinkState state, CUjitInputType type, const char * path, unsigned numOptions, CUjit_option * options, void ** optionValues); 
# 3901
CUresult cuLinkComplete(CUlinkState state, void ** cubinOut, ::size_t * sizeOut); 
# 3915
CUresult cuLinkDestroy(CUlinkState state); 
# 3963
CUresult cuMemGetInfo_v2(::size_t * free, ::size_t * total); 
# 3996
CUresult cuMemAlloc_v2(CUdeviceptr * dptr, ::size_t bytesize); 
# 4057
CUresult cuMemAllocPitch_v2(CUdeviceptr * dptr, ::size_t * pPitch, ::size_t WidthInBytes, ::size_t Height, unsigned ElementSizeBytes); 
# 4086
CUresult cuMemFree_v2(CUdeviceptr dptr); 
# 4119
CUresult cuMemGetAddressRange_v2(CUdeviceptr * pbase, ::size_t * psize, CUdeviceptr dptr); 
# 4165
CUresult cuMemAllocHost_v2(void ** pp, ::size_t bytesize); 
# 4195
CUresult cuMemFreeHost(void * p); 
# 4277
CUresult cuMemHostAlloc(void ** pp, ::size_t bytesize, unsigned Flags); 
# 4330
CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr * pdptr, void * p, unsigned Flags); 
# 4355
CUresult cuMemHostGetFlags(unsigned * pFlags, void * p); 
# 4465
CUresult cuMemAllocManaged(CUdeviceptr * dptr, ::size_t bytesize, unsigned flags); 
# 4494
CUresult cuDeviceGetByPCIBusId(CUdevice * dev, const char * pciBusId); 
# 4522
CUresult cuDeviceGetPCIBusId(char * pciBusId, int len, CUdevice dev); 
# 4564
CUresult cuIpcGetEventHandle(CUipcEventHandle * pHandle, CUevent event); 
# 4601
CUresult cuIpcOpenEventHandle(CUevent * phEvent, CUipcEventHandle handle); 
# 4638
CUresult cuIpcGetMemHandle(CUipcMemHandle * pHandle, CUdeviceptr dptr); 
# 4689
CUresult cuIpcOpenMemHandle(CUdeviceptr * pdptr, CUipcMemHandle handle, unsigned Flags); 
# 4720
CUresult cuIpcCloseMemHandle(CUdeviceptr dptr); 
# 4803
CUresult cuMemHostRegister_v2(void * p, ::size_t bytesize, unsigned Flags); 
# 4827
CUresult cuMemHostUnregister(void * p); 
# 4863
CUresult cuMemcpy(CUdeviceptr dst, CUdeviceptr src, ::size_t ByteCount); 
# 4892
CUresult cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, ::size_t ByteCount); 
# 4928
CUresult cuMemcpyHtoD_v2(CUdeviceptr dstDevice, const void * srcHost, ::size_t ByteCount); 
# 4961
CUresult cuMemcpyDtoH_v2(void * dstHost, CUdeviceptr srcDevice, ::size_t ByteCount); 
# 4994
CUresult cuMemcpyDtoD_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, ::size_t ByteCount); 
# 5029
CUresult cuMemcpyDtoA_v2(CUarray dstArray, ::size_t dstOffset, CUdeviceptr srcDevice, ::size_t ByteCount); 
# 5066
CUresult cuMemcpyAtoD_v2(CUdeviceptr dstDevice, CUarray srcArray, ::size_t srcOffset, ::size_t ByteCount); 
# 5101
CUresult cuMemcpyHtoA_v2(CUarray dstArray, ::size_t dstOffset, const void * srcHost, ::size_t ByteCount); 
# 5136
CUresult cuMemcpyAtoH_v2(void * dstHost, CUarray srcArray, ::size_t srcOffset, ::size_t ByteCount); 
# 5175
CUresult cuMemcpyAtoA_v2(CUarray dstArray, ::size_t dstOffset, CUarray srcArray, ::size_t srcOffset, ::size_t ByteCount); 
# 5336
CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D * pCopy); 
# 5495
CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D * pCopy); 
# 5663
CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D * pCopy); 
# 5688
CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER * pCopy); 
# 5728
CUresult cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, ::size_t ByteCount, CUstream hStream); 
# 5759
CUresult cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, ::size_t ByteCount, CUstream hStream); 
# 5798
CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr dstDevice, const void * srcHost, ::size_t ByteCount, CUstream hStream); 
# 5835
CUresult cuMemcpyDtoHAsync_v2(void * dstHost, CUdeviceptr srcDevice, ::size_t ByteCount, CUstream hStream); 
# 5872
CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, ::size_t ByteCount, CUstream hStream); 
# 5911
CUresult cuMemcpyHtoAAsync_v2(CUarray dstArray, ::size_t dstOffset, const void * srcHost, ::size_t ByteCount, CUstream hStream); 
# 5950
CUresult cuMemcpyAtoHAsync_v2(void * dstHost, CUarray srcArray, ::size_t srcOffset, ::size_t ByteCount, CUstream hStream); 
# 6115
CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D * pCopy, CUstream hStream); 
# 6287
CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D * pCopy, CUstream hStream); 
# 6314
CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER * pCopy, CUstream hStream); 
# 6350
CUresult cuMemsetD8_v2(CUdeviceptr dstDevice, unsigned char uc, ::size_t N); 
# 6384
CUresult cuMemsetD16_v2(CUdeviceptr dstDevice, unsigned short us, ::size_t N); 
# 6418
CUresult cuMemsetD32_v2(CUdeviceptr dstDevice, unsigned ui, ::size_t N); 
# 6457
CUresult cuMemsetD2D8_v2(CUdeviceptr dstDevice, ::size_t dstPitch, unsigned char uc, ::size_t Width, ::size_t Height); 
# 6497
CUresult cuMemsetD2D16_v2(CUdeviceptr dstDevice, ::size_t dstPitch, unsigned short us, ::size_t Width, ::size_t Height); 
# 6537
CUresult cuMemsetD2D32_v2(CUdeviceptr dstDevice, ::size_t dstPitch, unsigned ui, ::size_t Width, ::size_t Height); 
# 6573
CUresult cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char uc, ::size_t N, CUstream hStream); 
# 6609
CUresult cuMemsetD16Async(CUdeviceptr dstDevice, unsigned short us, ::size_t N, CUstream hStream); 
# 6644
CUresult cuMemsetD32Async(CUdeviceptr dstDevice, unsigned ui, ::size_t N, CUstream hStream); 
# 6685
CUresult cuMemsetD2D8Async(CUdeviceptr dstDevice, ::size_t dstPitch, unsigned char uc, ::size_t Width, ::size_t Height, CUstream hStream); 
# 6727
CUresult cuMemsetD2D16Async(CUdeviceptr dstDevice, ::size_t dstPitch, unsigned short us, ::size_t Width, ::size_t Height, CUstream hStream); 
# 6769
CUresult cuMemsetD2D32Async(CUdeviceptr dstDevice, ::size_t dstPitch, unsigned ui, ::size_t Width, ::size_t Height, CUstream hStream); 
# 6872
CUresult cuArrayCreate_v2(CUarray * pHandle, const CUDA_ARRAY_DESCRIPTOR * pAllocateArray); 
# 6905
CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR * pArrayDescriptor, CUarray hArray); 
# 6936
CUresult cuArrayDestroy(CUarray hArray); 
# 7116
CUresult cuArray3DCreate_v2(CUarray * pHandle, const CUDA_ARRAY3D_DESCRIPTOR * pAllocateArray); 
# 7152
CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR * pArrayDescriptor, CUarray hArray); 
# 7279
CUresult cuMipmappedArrayCreate(CUmipmappedArray * pHandle, const CUDA_ARRAY3D_DESCRIPTOR * pMipmappedArrayDesc, unsigned numMipmapLevels); 
# 7305
CUresult cuMipmappedArrayGetLevel(CUarray * pLevelArray, CUmipmappedArray hMipmappedArray, unsigned level); 
# 7325
CUresult cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray); 
# 7571
CUresult cuPointerGetAttribute(void * data, CUpointer_attribute attribute, CUdeviceptr ptr); 
# 7640
CUresult cuMemPrefetchAsync(CUdeviceptr devPtr, ::size_t count, CUdevice dstDevice, CUstream hStream); 
# 7726
CUresult cuMemAdvise(CUdeviceptr devPtr, ::size_t count, CUmem_advise advice, CUdevice device); 
# 7783
CUresult cuMemRangeGetAttribute(void * data, ::size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, ::size_t count); 
# 7822
CUresult cuMemRangeGetAttributes(void ** data, ::size_t * dataSizes, CUmem_range_attribute * attributes, ::size_t numAttributes, CUdeviceptr devPtr, ::size_t count); 
# 7866
CUresult cuPointerSetAttribute(const void * value, CUpointer_attribute attribute, CUdeviceptr ptr); 
# 7908
CUresult cuPointerGetAttributes(unsigned numAttributes, CUpointer_attribute * attributes, void ** data, CUdeviceptr ptr); 
# 7956
CUresult cuStreamCreate(CUstream * phStream, unsigned Flags); 
# 8004
CUresult cuStreamCreateWithPriority(CUstream * phStream, unsigned flags, int priority); 
# 8034
CUresult cuStreamGetPriority(CUstream hStream, int * priority); 
# 8061
CUresult cuStreamGetFlags(CUstream hStream, unsigned * flags); 
# 8102
CUresult cuStreamWaitEvent(CUstream hStream, CUevent hEvent, unsigned Flags); 
# 8173
CUresult cuStreamAddCallback(CUstream hStream, CUstreamCallback callback, void * userData, unsigned flags); 
# 8252
CUresult cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr, ::size_t length, unsigned flags); 
# 8283
CUresult cuStreamQuery(CUstream hStream); 
# 8310
CUresult cuStreamSynchronize(CUstream hStream); 
# 8339
CUresult cuStreamDestroy_v2(CUstream hStream); 
# 8394
CUresult cuEventCreate(CUevent * phEvent, unsigned Flags); 
# 8430
CUresult cuEventRecord(CUevent hEvent, CUstream hStream); 
# 8464
CUresult cuEventQuery(CUevent hEvent); 
# 8498
CUresult cuEventSynchronize(CUevent hEvent); 
# 8527
CUresult cuEventDestroy_v2(CUevent hEvent); 
# 8571
CUresult cuEventElapsedTime(float * pMilliseconds, CUevent hStart, CUevent hEnd); 
# 8606
CUresult cuStreamWaitValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned flags); 
# 8639
CUresult cuStreamWriteValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned flags); 
# 8671
CUresult cuStreamBatchMemOp(CUstream stream, unsigned count, CUstreamBatchMemOpParams * paramArray, unsigned flags); 
# 8739
CUresult cuFuncGetAttribute(int * pi, CUfunction_attribute attrib, CUfunction hfunc); 
# 8782
CUresult cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config); 
# 8834
CUresult cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config); 
# 8948
CUresult cuLaunchKernel(CUfunction f, unsigned gridDimX, unsigned gridDimY, unsigned gridDimZ, unsigned blockDimX, unsigned blockDimY, unsigned blockDimZ, unsigned sharedMemBytes, CUstream hStream, void ** kernelParams, void ** extra); 
# 9009
CUresult cuFuncSetBlockShape(CUfunction hfunc, int x, int y, int z); 
# 9043
CUresult cuFuncSetSharedSize(CUfunction hfunc, unsigned bytes); 
# 9075
CUresult cuParamSetSize(CUfunction hfunc, unsigned numbytes); 
# 9108
CUresult cuParamSeti(CUfunction hfunc, int offset, unsigned value); 
# 9141
CUresult cuParamSetf(CUfunction hfunc, int offset, float value); 
# 9176
CUresult cuParamSetv(CUfunction hfunc, int offset, void * ptr, unsigned numbytes); 
# 9213
CUresult cuLaunch(CUfunction f); 
# 9252
CUresult cuLaunchGrid(CUfunction f, int grid_width, int grid_height); 
# 9299
CUresult cuLaunchGridAsync(CUfunction f, int grid_width, int grid_height, CUstream hStream); 
# 9324
CUresult cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef); 
# 9362
CUresult cuOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, CUfunction func, int blockSize, ::size_t dynamicSMemSize); 
# 9402
CUresult cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, CUfunction func, int blockSize, ::size_t dynamicSMemSize, unsigned flags); 
# 9452
CUresult cuOccupancyMaxPotentialBlockSize(int * minGridSize, int * blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, ::size_t dynamicSMemSize, int blockSizeLimit); 
# 9496
CUresult cuOccupancyMaxPotentialBlockSizeWithFlags(int * minGridSize, int * blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, ::size_t dynamicSMemSize, int blockSizeLimit, unsigned flags); 
# 9539
CUresult cuTexRefSetArray(CUtexref hTexRef, CUarray hArray, unsigned Flags); 
# 9566
CUresult cuTexRefSetMipmappedArray(CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned Flags); 
# 9610
CUresult cuTexRefSetAddress_v2(::size_t * ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, ::size_t bytes); 
# 9662
CUresult cuTexRefSetAddress2D_v3(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR * desc, CUdeviceptr dptr, ::size_t Pitch); 
# 9691
CUresult cuTexRefSetFormat(CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents); 
# 9731
CUresult cuTexRefSetAddressMode(CUtexref hTexRef, int dim, CUaddress_mode am); 
# 9764
CUresult cuTexRefSetFilterMode(CUtexref hTexRef, CUfilter_mode fm); 
# 9797
CUresult cuTexRefSetMipmapFilterMode(CUtexref hTexRef, CUfilter_mode fm); 
# 9823
CUresult cuTexRefSetMipmapLevelBias(CUtexref hTexRef, float bias); 
# 9851
CUresult cuTexRefSetMipmapLevelClamp(CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp); 
# 9877
CUresult cuTexRefSetMaxAnisotropy(CUtexref hTexRef, unsigned maxAniso); 
# 9907
CUresult cuTexRefSetBorderColor(CUtexref hTexRef, float * pBorderColor); 
# 9942
CUresult cuTexRefSetFlags(CUtexref hTexRef, unsigned Flags); 
# 9968
CUresult cuTexRefGetAddress_v2(CUdeviceptr * pdptr, CUtexref hTexRef); 
# 9994
CUresult cuTexRefGetArray(CUarray * phArray, CUtexref hTexRef); 
# 10019
CUresult cuTexRefGetMipmappedArray(CUmipmappedArray * phMipmappedArray, CUtexref hTexRef); 
# 10045
CUresult cuTexRefGetAddressMode(CUaddress_mode * pam, CUtexref hTexRef, int dim); 
# 10069
CUresult cuTexRefGetFilterMode(CUfilter_mode * pfm, CUtexref hTexRef); 
# 10095
CUresult cuTexRefGetFormat(CUarray_format * pFormat, int * pNumChannels, CUtexref hTexRef); 
# 10119
CUresult cuTexRefGetMipmapFilterMode(CUfilter_mode * pfm, CUtexref hTexRef); 
# 10143
CUresult cuTexRefGetMipmapLevelBias(float * pbias, CUtexref hTexRef); 
# 10168
CUresult cuTexRefGetMipmapLevelClamp(float * pminMipmapLevelClamp, float * pmaxMipmapLevelClamp, CUtexref hTexRef); 
# 10192
CUresult cuTexRefGetMaxAnisotropy(int * pmaxAniso, CUtexref hTexRef); 
# 10219
CUresult cuTexRefGetBorderColor(float * pBorderColor, CUtexref hTexRef); 
# 10242
CUresult cuTexRefGetFlags(unsigned * pFlags, CUtexref hTexRef); 
# 10281
CUresult cuTexRefCreate(CUtexref * pTexRef); 
# 10301
CUresult cuTexRefDestroy(CUtexref hTexRef); 
# 10340
CUresult cuSurfRefSetArray(CUsurfref hSurfRef, CUarray hArray, unsigned Flags); 
# 10361
CUresult cuSurfRefGetArray(CUarray * phArray, CUsurfref hSurfRef); 
# 10583
CUresult cuTexObjectCreate(CUtexObject * pTexObject, const CUDA_RESOURCE_DESC * pResDesc, const CUDA_TEXTURE_DESC * pTexDesc, const CUDA_RESOURCE_VIEW_DESC * pResViewDesc); 
# 10601
CUresult cuTexObjectDestroy(CUtexObject texObject); 
# 10620
CUresult cuTexObjectGetResourceDesc(CUDA_RESOURCE_DESC * pResDesc, CUtexObject texObject); 
# 10639
CUresult cuTexObjectGetTextureDesc(CUDA_TEXTURE_DESC * pTexDesc, CUtexObject texObject); 
# 10659
CUresult cuTexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC * pResViewDesc, CUtexObject texObject); 
# 10700
CUresult cuSurfObjectCreate(CUsurfObject * pSurfObject, const CUDA_RESOURCE_DESC * pResDesc); 
# 10718
CUresult cuSurfObjectDestroy(CUsurfObject surfObject); 
# 10737
CUresult cuSurfObjectGetResourceDesc(CUDA_RESOURCE_DESC * pResDesc, CUsurfObject surfObject); 
# 10779
CUresult cuDeviceCanAccessPeer(int * canAccessPeer, CUdevice dev, CUdevice peerDev); 
# 10816
CUresult cuDeviceGetP2PAttribute(int * value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice); 
# 10865
CUresult cuCtxEnablePeerAccess(CUcontext peerContext, unsigned Flags); 
# 10890
CUresult cuCtxDisablePeerAccess(CUcontext peerContext); 
# 10934
CUresult cuGraphicsUnregisterResource(CUgraphicsResource resource); 
# 10972
CUresult cuGraphicsSubResourceGetMappedArray(CUarray * pArray, CUgraphicsResource resource, unsigned arrayIndex, unsigned mipLevel); 
# 11003
CUresult cuGraphicsResourceGetMappedMipmappedArray(CUmipmappedArray * pMipmappedArray, CUgraphicsResource resource); 
# 11039
CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr * pDevPtr, ::size_t * pSize, CUgraphicsResource resource); 
# 11080
CUresult cuGraphicsResourceSetMapFlags_v2(CUgraphicsResource resource, unsigned flags); 
# 11119
CUresult cuGraphicsMapResources(unsigned count, CUgraphicsResource * resources, CUstream hStream); 
# 11155
CUresult cuGraphicsUnmapResources(unsigned count, CUgraphicsResource * resources, CUstream hStream); 
# 11159
CUresult cuGetExportTable(const void ** ppExportTable, const CUuuid * pExportTableId); 
# 11478
}
# 6 "t266.cu"
using namespace std;
# 9
const int N = 4; 
# 10
const int threadsPerBlock = 4; 
# 11
const int blocksPerGrid = 1; 
# 13
void dot(int *a) ;
#if 0
# 13
{ 
# 18
int tid = __device_builtin_variable_threadIdx.x; 
# 19
if (tid > 1) { 
# 20
int t0 = a[tid - 2]; 
# 21
int t1 = a[tid]; 
# 23
(a[tid]) = (t0 + t1); 
# 25
} else { 
# 26
int t0 = a[tid]; 
# 27
int t1 = a[tid + 2]; 
# 29
(a[tid]) = (t0 + t1); 
# 31
}  
# 35
} 
#endif
# 46 "t266.cu"
int main() { 
# 47
int *a; 
# 48
int *dev_a; 
# 50
a = (new int [N]); 
# 51
for (int i = 0; i < N; i++) { 
# 52
(a[i]) = i; 
# 53
}  
# 54
cudaMalloc((void **)(&dev_a), sizeof(int) * N); 
# 55
cudaMemcpy(dev_a, a, N * sizeof(int), cudaMemcpyHostToDevice); 
# 56
(cudaConfigureCall(blocksPerGrid, threadsPerBlock)) ? (void)0 : (dot)(dev_a); 
# 57
cudaMemcpy(a, dev_a, N * sizeof(int), cudaMemcpyDeviceToHost); 
# 60
for (int i = 0; i < N; i++) { 
# 61
printf("%d\n", a[i]); }  
# 62
cudaFree(dev_a); 
# 65
delete [] a; return 0; 
# 66
} 

# 1 "t266.cudafe1.stub.c"
#define _NV_ANON_NAMESPACE _GLOBAL__N__12_t266_cpp1_ii__Z3dotPi
# 1 "t266.cudafe1.stub.c"
#include "t266.cudafe1.stub.c"
# 1 "t266.cudafe1.stub.c"
#undef _NV_ANON_NAMESPACE
