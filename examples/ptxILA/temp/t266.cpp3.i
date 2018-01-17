# 1 "t266.cudafe2.gpu"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3
# 1 "<command-line>" 2
# 1 "t266.cudafe2.gpu"
# 212 "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h" 3
typedef unsigned long size_t;
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 1 3
# 38 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 3
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/host_defines.h" 1 3
# 39 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 2 3





typedef unsigned long long __texture_type__;
typedef unsigned long long __surface_type__;
# 284 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 3
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 1 3
# 56 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_types.h" 1 3
# 53 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_types.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/host_defines.h" 1 3
# 54 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_types.h" 2 3







enum cudaRoundMode
{
    cudaRoundNearest,
    cudaRoundZero,
    cudaRoundPosInf,
    cudaRoundMinInf
};
# 57 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3


# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 1 3
# 156 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
enum cudaError
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




enum cudaChannelFormatKind
{
    cudaChannelFormatKindSigned = 0,
    cudaChannelFormatKindUnsigned = 1,
    cudaChannelFormatKindFloat = 2,
    cudaChannelFormatKindNone = 3
};




struct cudaChannelFormatDesc
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




enum cudaMemoryType
{
    cudaMemoryTypeHost = 1,
    cudaMemoryTypeDevice = 2
};




enum cudaMemcpyKind
{
    cudaMemcpyHostToHost = 0,
    cudaMemcpyHostToDevice = 1,
    cudaMemcpyDeviceToHost = 2,
    cudaMemcpyDeviceToDevice = 3,
    cudaMemcpyDefault = 4
};






struct cudaPitchedPtr
{
    void *ptr;
    size_t pitch;
    size_t xsize;
    size_t ysize;
};






struct cudaExtent
{
    size_t width;
    size_t height;
    size_t depth;
};






struct cudaPos
{
    size_t x;
    size_t y;
    size_t z;
};




struct cudaMemcpy3DParms
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




struct cudaMemcpy3DPeerParms
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




enum cudaGraphicsRegisterFlags
{
    cudaGraphicsRegisterFlagsNone = 0,
    cudaGraphicsRegisterFlagsReadOnly = 1,
    cudaGraphicsRegisterFlagsWriteDiscard = 2,
    cudaGraphicsRegisterFlagsSurfaceLoadStore = 4,
    cudaGraphicsRegisterFlagsTextureGather = 8
};




enum cudaGraphicsMapFlags
{
    cudaGraphicsMapFlagsNone = 0,
    cudaGraphicsMapFlagsReadOnly = 1,
    cudaGraphicsMapFlagsWriteDiscard = 2
};




enum cudaGraphicsCubeFace
{
    cudaGraphicsCubeFacePositiveX = 0x00,
    cudaGraphicsCubeFaceNegativeX = 0x01,
    cudaGraphicsCubeFacePositiveY = 0x02,
    cudaGraphicsCubeFaceNegativeY = 0x03,
    cudaGraphicsCubeFacePositiveZ = 0x04,
    cudaGraphicsCubeFaceNegativeZ = 0x05
};




enum cudaResourceType
{
    cudaResourceTypeArray = 0x00,
    cudaResourceTypeMipmappedArray = 0x01,
    cudaResourceTypeLinear = 0x02,
    cudaResourceTypePitch2D = 0x03
};




enum cudaResourceViewFormat
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




struct cudaResourceDesc {
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




struct cudaResourceViewDesc
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




struct cudaPointerAttributes
{




    enum cudaMemoryType memoryType;
# 1044 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
    int device;





    void *devicePointer;





    void *hostPointer;




    int isManaged;
};




struct cudaFuncAttributes
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




enum cudaFuncCache
{
    cudaFuncCachePreferNone = 0,
    cudaFuncCachePreferShared = 1,
    cudaFuncCachePreferL1 = 2,
    cudaFuncCachePreferEqual = 3
};





enum cudaSharedMemConfig
{
    cudaSharedMemBankSizeDefault = 0,
    cudaSharedMemBankSizeFourByte = 1,
    cudaSharedMemBankSizeEightByte = 2
};




enum cudaComputeMode
{
    cudaComputeModeDefault = 0,
    cudaComputeModeExclusive = 1,
    cudaComputeModeProhibited = 2,
    cudaComputeModeExclusiveProcess = 3
};




enum cudaLimit
{
    cudaLimitStackSize = 0x00,
    cudaLimitPrintfFifoSize = 0x01,
    cudaLimitMallocHeapSize = 0x02,
    cudaLimitDevRuntimeSyncDepth = 0x03,
    cudaLimitDevRuntimePendingLaunchCount = 0x04
};




enum cudaMemoryAdvise
{
    cudaMemAdviseSetReadMostly = 1,
    cudaMemAdviseUnsetReadMostly = 2,
    cudaMemAdviseSetPreferredLocation = 3,
    cudaMemAdviseUnsetPreferredLocation = 4,
    cudaMemAdviseSetAccessedBy = 5,
    cudaMemAdviseUnsetAccessedBy = 6
};




enum cudaMemRangeAttribute
{
    cudaMemRangeAttributeReadMostly = 1,
    cudaMemRangeAttributePreferredLocation = 2,
    cudaMemRangeAttributeAccessedBy = 3,
    cudaMemRangeAttributeLastPrefetchLocation = 4
};




enum cudaOutputMode
{
    cudaKeyValuePair = 0x00,
    cudaCSV = 0x01
};




enum cudaDeviceAttr
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





enum cudaDeviceP2PAttr {
    cudaDevP2PAttrPerformanceRank = 1,
    cudaDevP2PAttrAccessSupported = 2,
    cudaDevP2PAttrNativeAtomicSupported = 3
};



struct cudaDeviceProp
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
typedef struct cudaIpcEventHandle_st
{
    char reserved[64];
}cudaIpcEventHandle_t;




typedef struct cudaIpcMemHandle_st
{
    char reserved[64];
}cudaIpcMemHandle_t;
# 1477 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 3
typedef enum cudaError cudaError_t;




typedef struct CUstream_st *cudaStream_t;




typedef struct CUevent_st *cudaEvent_t;




typedef struct cudaGraphicsResource *cudaGraphicsResource_t;




typedef struct CUuuid_st cudaUUID_t;




typedef enum cudaOutputMode cudaOutputMode_t;
# 60 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3


# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 1 3
# 59 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/driver_types.h" 1 3
# 60 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 2 3
# 84 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_types.h" 3
enum cudaSurfaceBoundaryMode
{
    cudaBoundaryModeZero = 0,
    cudaBoundaryModeClamp = 1,
    cudaBoundaryModeTrap = 2
};




enum cudaSurfaceFormatMode
{
    cudaFormatModeForced = 0,
    cudaFormatModeAuto = 1
};




struct surfaceReference
{



    struct cudaChannelFormatDesc channelDesc;
};




typedef unsigned long long cudaSurfaceObject_t;
# 63 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/texture_types.h" 1 3
# 84 "/usr/local/cuda-8.0/targets/x86_64-linux/include/texture_types.h" 3
enum cudaTextureAddressMode
{
    cudaAddressModeWrap = 0,
    cudaAddressModeClamp = 1,
    cudaAddressModeMirror = 2,
    cudaAddressModeBorder = 3
};




enum cudaTextureFilterMode
{
    cudaFilterModePoint = 0,
    cudaFilterModeLinear = 1
};




enum cudaTextureReadMode
{
    cudaReadModeElementType = 0,
    cudaReadModeNormalizedFloat = 1
};




struct textureReference
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




struct cudaTextureDesc
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




typedef unsigned long long cudaTextureObject_t;
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
struct char1
{
    signed char x;
};

struct uchar1
{
    unsigned char x;
};


struct __attribute__((aligned(2))) char2
{
    signed char x, y;
};

struct __attribute__((aligned(2))) uchar2
{
    unsigned char x, y;
};

struct char3
{
    signed char x, y, z;
};

struct uchar3
{
    unsigned char x, y, z;
};

struct __attribute__((aligned(4))) char4
{
    signed char x, y, z, w;
};

struct __attribute__((aligned(4))) uchar4
{
    unsigned char x, y, z, w;
};

struct short1
{
    short x;
};

struct ushort1
{
    unsigned short x;
};

struct __attribute__((aligned(4))) short2
{
    short x, y;
};

struct __attribute__((aligned(4))) ushort2
{
    unsigned short x, y;
};

struct short3
{
    short x, y, z;
};

struct ushort3
{
    unsigned short x, y, z;
};

struct __attribute__((aligned(8))) short4 { short x; short y; short z; short w; };
struct __attribute__((aligned(8))) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; };

struct int1
{
    int x;
};

struct uint1
{
    unsigned int x;
};

struct __attribute__((aligned(8))) int2 { int x; int y; };
struct __attribute__((aligned(8))) uint2 { unsigned int x; unsigned int y; };

struct int3
{
    int x, y, z;
};

struct uint3
{
    unsigned int x, y, z;
};

struct __attribute__((aligned(16))) int4
{
    int x, y, z, w;
};

struct __attribute__((aligned(16))) uint4
{
    unsigned int x, y, z, w;
};

struct long1
{
    long int x;
};

struct ulong1
{
    unsigned long x;
};






struct __attribute__((aligned(2*sizeof(long int)))) long2
{
    long int x, y;
};

struct __attribute__((aligned(2*sizeof(unsigned long int)))) ulong2
{
    unsigned long int x, y;
};



struct long3
{
    long int x, y, z;
};

struct ulong3
{
    unsigned long int x, y, z;
};

struct __attribute__((aligned(16))) long4
{
    long int x, y, z, w;
};

struct __attribute__((aligned(16))) ulong4
{
    unsigned long int x, y, z, w;
};

struct float1
{
    float x;
};
# 274 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 3
struct __attribute__((aligned(8))) float2 { float x; float y; };




struct float3
{
    float x, y, z;
};

struct __attribute__((aligned(16))) float4
{
    float x, y, z, w;
};

struct longlong1
{
    long long int x;
};

struct ulonglong1
{
    unsigned long long int x;
};

struct __attribute__((aligned(16))) longlong2
{
    long long int x, y;
};

struct __attribute__((aligned(16))) ulonglong2
{
    unsigned long long int x, y;
};

struct longlong3
{
    long long int x, y, z;
};

struct ulonglong3
{
    unsigned long long int x, y, z;
};

struct __attribute__((aligned(16))) longlong4
{
    long long int x, y, z ,w;
};

struct __attribute__((aligned(16))) ulonglong4
{
    unsigned long long int x, y, z, w;
};

struct double1
{
    double x;
};

struct __attribute__((aligned(16))) double2
{
    double x, y;
};

struct double3
{
    double x, y, z;
};

struct __attribute__((aligned(16))) double4
{
    double x, y, z, w;
};
# 362 "/usr/local/cuda-8.0/targets/x86_64-linux/include/vector_types.h" 3
typedef struct char1 char1;
typedef struct uchar1 uchar1;
typedef struct char2 char2;
typedef struct uchar2 uchar2;
typedef struct char3 char3;
typedef struct uchar3 uchar3;
typedef struct char4 char4;
typedef struct uchar4 uchar4;
typedef struct short1 short1;
typedef struct ushort1 ushort1;
typedef struct short2 short2;
typedef struct ushort2 ushort2;
typedef struct short3 short3;
typedef struct ushort3 ushort3;
typedef struct short4 short4;
typedef struct ushort4 ushort4;
typedef struct int1 int1;
typedef struct uint1 uint1;
typedef struct int2 int2;
typedef struct uint2 uint2;
typedef struct int3 int3;
typedef struct uint3 uint3;
typedef struct int4 int4;
typedef struct uint4 uint4;
typedef struct long1 long1;
typedef struct ulong1 ulong1;
typedef struct long2 long2;
typedef struct ulong2 ulong2;
typedef struct long3 long3;
typedef struct ulong3 ulong3;
typedef struct long4 long4;
typedef struct ulong4 ulong4;
typedef struct float1 float1;
typedef struct float2 float2;
typedef struct float3 float3;
typedef struct float4 float4;
typedef struct longlong1 longlong1;
typedef struct ulonglong1 ulonglong1;
typedef struct longlong2 longlong2;
typedef struct ulonglong2 ulonglong2;
typedef struct longlong3 longlong3;
typedef struct ulonglong3 ulonglong3;
typedef struct longlong4 longlong4;
typedef struct ulonglong4 ulonglong4;
typedef struct double1 double1;
typedef struct double2 double2;
typedef struct double3 double3;
typedef struct double4 double4;







struct dim3
{
    unsigned int x, y, z;





};

typedef struct dim3 dim3;
# 64 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/builtin_types.h" 2 3
# 285 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 2 3
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_launch_parameters.h" 1 3
# 71 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/device_launch_parameters.h" 3
uint3 extern const threadIdx;
uint3 extern const blockIdx;
dim3 extern const blockDim;
dim3 extern const gridDim;
int extern const warpSize;
# 286 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/crt/storage_class.h" 1 3
# 286 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 2 3
# 214 "/usr/lib/gcc/x86_64-redhat-linux/4.8.5/include/stddef.h" 2 3
# 196 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 3
extern __attribute__((__externally_visible__)) __attribute__((__used__)) __attribute__((visibility("default"))) void *malloc(size_t);
# 197 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/crt/device_runtime.h" 3
extern __attribute__((__externally_visible__)) __attribute__((__used__)) __attribute__((__nothrow__)) __attribute__((visibility("default"))) void free(void *);
# 13 "t266.cu"
__attribute__((global)) __attribute__((__used__)) extern void _Z3dotPi(int *);
# 1 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h" 1
# 249 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h"
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 1 3
# 9842 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 1 3
# 81 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_sinf(float x) ;
# 94 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_cosf(float x) ;
# 121 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_log2f(float x) ;
# 136 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_tanf(float x) ;
# 152 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 void __nv_fast_sincosf(float x, float *sptr, float *cptr) ;
# 203 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_expf(float x) ;
# 236 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_exp10f(float x) ;
# 265 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_log10f(float x) ;
# 310 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_logf(float x) ;
# 354 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_powf(float x, float y) ;
# 367 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_hadd(int x, int y) ;
# 381 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_rhadd(int x, int y) ;
# 394 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_uhadd(unsigned int x, unsigned int y) ;
# 408 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_urhadd(unsigned int x, unsigned int y) ;
# 421 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fsub_rn (float x, float y) ;
# 434 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fsub_rz (float x, float y) ;
# 447 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fsub_rd (float x, float y) ;
# 460 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fsub_ru (float x, float y) ;
# 500 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_frsqrt_rn (float x) ;
# 512 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_ffs(int x) ;
# 524 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_ffsll(long long int x) ;
# 536 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_rintf(float x) ;
# 549 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long int __nv_llrintf(float x) ;
# 599 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_nearbyintf(float x) ;
# 612 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_signbitf(float x) ;
# 622 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_copysignf(float x, float y) ;
# 633 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_finitef(float x) ;
# 646 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_isinff(float x) ;
# 658 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_isnanf(float x) ;
# 691 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_nextafterf(float x, float y) ;
# 704 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_nanf(const signed char *tagp) ;
# 746 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_sinf(float x) ;
# 780 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_cosf(float x) ;
# 796 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 void __nv_sincosf(float x, float *sptr, float *cptr) ;
# 857 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_sinpif(float x) ;
# 910 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_cospif(float x) ;
# 941 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 void __nv_sincospif(float x, float *sptr, float *cptr) ;
# 983 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_tanf(float x) ;
# 1035 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_log2f(float x) ;
# 1075 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_expf(float x) ;
# 1097 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_exp10f(float x) ;
# 1129 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_coshf(float x) ;
# 1160 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_sinhf(float x) ;
# 1191 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_tanhf(float x) ;
# 1225 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_atan2f(float x, float y) ;
# 1257 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_atanf(float x) ;
# 1290 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_asinf(float x) ;
# 1314 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_acosf(float x) ;
# 1386 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_logf(float x) ;
# 1438 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_log10f(float x) ;
# 1532 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_log1pf(float x) ;
# 1567 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_acoshf(float x) ;
# 1580 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_asinhf(float x) ;
# 1631 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_atanhf(float x) ;
# 1673 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_expm1f(float x) ;
# 1714 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_hypotf(float x, float y) ;
# 1760 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_rhypotf(float x, float y) ;
# 1812 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_rnormf(int dim, float const * a) ;
# 1858 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_normf(int dim, float const * a) ;
# 1904 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_norm3df(float a, float b, float c) ;
# 1954 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_rnorm3df(float a, float b, float c) ;
# 2004 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_norm4df(float a, float b, float c, float d) ;
# 2059 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_rnorm4df(float a, float b, float c, float d) ;
# 2142 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_cbrtf(float x) ;
# 2192 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_rcbrtf(float x) ;
# 2231 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_j0f(float x) ;
# 2289 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_j1f(float x) ;
# 2338 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_y0f(float x) ;
# 2387 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_y1f(float x) ;
# 2437 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ynf(int n, float x) ;
# 2477 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_jnf(int n, float x) ;
# 2504 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_cyl_bessel_i0f(float x) ;
# 2531 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_cyl_bessel_i1f(float x) ;
# 2610 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_erff(float x) ;
# 2668 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_erfinvf(float x) ;
# 2703 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_erfcf(float x) ;
# 2779 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_erfcxf(float x) ;
# 2836 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_erfcinvf(float x) ;
# 2895 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_normcdfinvf(float x) ;
# 2939 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_normcdff(float x) ;
# 3064 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_lgammaf(float x) ;
# 3121 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ldexpf(float x, int y) ;
# 3194 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_scalbnf(float x, int y) ;
# 3270 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_frexpf(float x, int *b) ;
# 3327 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_modff(float x, float *b) ;
# 3387 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmodf(float x, float y) ;
# 3473 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_remainderf(float x, float y) ;
# 3524 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_remquof(float x, float y, int* quo) ;
# 3679 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmaf(float x, float y, float z) ;
# 3988 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_powif(float x, int y) ;
# 4297 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_powi(double x, int y) ;
# 4606 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_powf(float x, float y) ;
# 4712 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_tgammaf(float x) ;
# 4726 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_roundf(float x) ;
# 4741 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long int __nv_llroundf(float x) ;
# 4764 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fdimf(float x, float y) ;
# 4791 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_ilogbf(float x) ;
# 4843 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_logbf(float x) ;
# 4855 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_rint(double x) ;
# 4868 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long int __nv_llrint(double x) ;
# 4918 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_nearbyint(double x) ;
# 4931 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_signbitd(double x) ;
# 4944 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_isfinited(double x) ;
# 4957 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_isinfd(double x) ;
# 4969 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_isnand(double x) ;
# 4979 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_copysign(double x, double y) ;
# 4995 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 void __nv_sincos(double x, double *sptr, double *cptr) ;
# 5026 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 void __nv_sincospi(double x, double *sptr, double *cptr) ;
# 5068 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_sin(double x) ;
# 5102 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_cos(double x) ;
# 5163 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_sinpi(double x) ;
# 5216 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_cospi(double x) ;
# 5258 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_tan(double x) ;
# 5330 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_log(double x) ;
# 5382 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_log2(double x) ;
# 5434 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_log10(double x) ;
# 5528 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_log1p(double x) ;
# 5568 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_exp(double x) ;
# 5590 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_exp2(double x) ;
# 5612 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_exp10(double x) ;
# 5654 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_expm1(double x) ;
# 5686 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_cosh(double x) ;
# 5717 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_sinh(double x) ;
# 5748 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_tanh(double x) ;
# 5782 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_atan2(double x, double y) ;
# 5814 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_atan(double x) ;
# 5847 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_asin(double x) ;
# 5871 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_acos(double x) ;
# 5906 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_acosh(double x) ;
# 5919 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_asinh(double x) ;
# 5970 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_atanh(double x) ;
# 6011 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_hypot(double x, double y) ;
# 6055 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_rhypot(double x, double y) ;
# 6098 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_norm3d(double a, double b, double c) ;
# 6148 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_rnorm3d(double a, double b, double c) ;
# 6197 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_norm4d(double a, double b, double c, double d) ;
# 6243 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_norm(int dim, double const * a) ;
# 6295 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_rnorm(int dim, double const * a) ;
# 6378 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_cbrt(double x) ;
# 6433 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_rnorm4d(double a, double b, double c, double d) ;
# 6483 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_rcbrt(double x) ;
# 6792 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_pow(double x, double y) ;
# 6831 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_j0(double x) ;
# 6889 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_j1(double x) ;
# 6938 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_y0(double x) ;
# 6987 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_y1(double x) ;
# 7037 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_yn(int n, double x) ;
# 7077 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_jn(int n, double x) ;
# 7104 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_cyl_bessel_i0(double x) ;
# 7131 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_cyl_bessel_i1(double x) ;
# 7210 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_erf(double x) ;
# 7268 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_erfinv(double x) ;
# 7325 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_erfcinv(double x) ;
# 7384 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_normcdfinv(double x) ;
# 7419 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_erfc(double x) ;
# 7495 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_erfcx(double x) ;
# 7539 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_normcdf(double x) ;
# 7645 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_tgamma(double x) ;
# 7770 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_lgamma(double x) ;
# 7827 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ldexp(double x, int y) ;
# 7900 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_scalbn(double x, int y) ;
# 7976 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_frexp(double x, int *b) ;
# 8033 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_modf(double x, double *b) ;
# 8093 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fmod(double x, double y) ;
# 8179 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_remainder(double x, double y) ;
# 8230 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_remquo(double x, double y, int *c) ;
# 8263 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_nextafter(double x, double y) ;
# 8276 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_nan(const signed char *tagp) ;
# 8290 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_round(double x) ;
# 8305 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long int __nv_llround(double x) ;
# 8328 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fdim(double x, double y) ;
# 8355 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_ilogb(double x) ;
# 8407 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_logb(double x) ;
# 8562 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fma(double x, double y, double z) ;
# 8572 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_clz(int x) ;
# 8581 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_clzll(long long x) ;
# 8591 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_popc(int x) ;
# 8600 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_popcll(long long x) ;
# 8625 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_byte_perm(unsigned int x, unsigned int y, unsigned int z) ;
# 8636 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_min(int x, int y) ;
# 8646 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_umin(unsigned int x, unsigned int y) ;
# 8656 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_llmin(long long x, long long y) ;
# 8666 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_ullmin(unsigned long long x, unsigned long long y) ;
# 8677 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_max(int x, int y) ;
# 8687 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_umax(unsigned int x, unsigned int y) ;
# 8697 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_llmax(long long x, long long y) ;
# 8707 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_ullmax(unsigned long long x, unsigned long long y) ;
# 8718 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_mulhi(int x, int y) ;
# 8728 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_umulhi(unsigned int x, unsigned int y) ;
# 8738 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_mul64hi(long long x, long long y) ;
# 8748 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_umul64hi(unsigned long long x, unsigned long long y) ;
# 8759 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_mul24(int x, int y) ;
# 8769 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_umul24(unsigned int x, unsigned int y) ;
# 8779 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_brev(unsigned int x) ;
# 8789 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_brevll(unsigned long long x) ;
# 8858 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_sad(int x, int y, int z) ;
# 8927 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_usad(unsigned int x, unsigned int y, unsigned int z) ;
# 8937 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_abs(int x) ;
# 8948 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_llabs(long long x) ;
# 9000 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_floorf(float f) ;
# 9052 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_floor(double f) ;
# 9094 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fabsf(float f) ;
# 9136 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fabs(double f) ;


 double __nv_rcp64h(double d) ;
# 9156 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fminf(float x, float y) ;
# 9173 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmaxf(float x, float y) ;
# 9243 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_rsqrtf(float x) ;
# 9260 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fmin(double x, double y) ;
# 9277 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fmax(double x, double y) ;
# 9347 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_rsqrt(double x) ;
# 9407 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ceil(double x) ;
# 9419 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_trunc(double x) ;
# 9441 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_exp2f(float x) ;
# 9453 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_truncf(float x) ;
# 9513 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ceilf(float x) ;
# 9537 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_saturatef(float x) ;
# 9691 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmaf_rn(float x, float y, float z) ;
# 9844 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmaf_rz(float x, float y, float z) ;
# 9997 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmaf_rd(float x, float y, float z) ;
# 10150 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmaf_ru(float x, float y, float z) ;


 float __nv_fmaf_ieee_rn(float x, float y, float z) ;

 float __nv_fmaf_ieee_rz(float x, float y, float z) ;

 float __nv_fmaf_ieee_rd(float x, float y, float z) ;

 float __nv_fmaf_ieee_ru(float x, float y, float z) ;
# 10317 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fma_rn(double x, double y, double z) ;
# 10474 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fma_rz(double x, double y, double z) ;
# 10631 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fma_rd(double x, double y, double z) ;
# 10788 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_fma_ru(double x, double y, double z) ;
# 10864 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fast_fdividef(float x, float y) ;
# 10876 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fdiv_rn(float x, float y) ;
# 10887 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fdiv_rz(float x, float y) ;
# 10898 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fdiv_rd(float x, float y) ;
# 10909 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fdiv_ru(float x, float y) ;
# 10943 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_frcp_rn(float x) ;
# 10976 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_frcp_rz(float x) ;
# 11009 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_frcp_rd(float x) ;
# 11042 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_frcp_ru(float x) ;
# 11074 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fsqrt_rn(float x) ;
# 11105 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fsqrt_rz(float x) ;
# 11136 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fsqrt_rd(float x) ;
# 11167 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fsqrt_ru(float x) ;
# 11180 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ddiv_rn(double x, double y) ;
# 11192 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ddiv_rz(double x, double y) ;
# 11204 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ddiv_rd(double x, double y) ;
# 11216 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ddiv_ru(double x, double y) ;
# 11251 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_drcp_rn(double x) ;
# 11285 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_drcp_rz(double x) ;
# 11319 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_drcp_rd(double x) ;
# 11353 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_drcp_ru(double x) ;
# 11386 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dsqrt_rn(double x) ;
# 11419 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dsqrt_rz(double x) ;
# 11451 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dsqrt_rd(double x) ;
# 11483 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dsqrt_ru(double x) ;
# 11553 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_sqrtf(float x) ;
# 11623 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_sqrt(double x) ;
# 11636 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dadd_rn(double x, double y) ;
# 11648 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dadd_rz(double x, double y) ;
# 11660 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dadd_rd(double x, double y) ;
# 11672 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dadd_ru(double x, double y) ;
# 11685 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dmul_rn(double x, double y) ;
# 11697 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dmul_rz(double x, double y) ;
# 11709 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dmul_rd(double x, double y) ;
# 11721 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_dmul_ru(double x, double y) ;
# 11734 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fadd_rd(float x, float y) ;
# 11746 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fadd_ru(float x, float y) ;
# 11759 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmul_rd(float x, float y) ;
# 11771 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmul_ru(float x, float y) ;
# 11784 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fadd_rn(float x, float y) ;
# 11796 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fadd_rz(float x, float y) ;
# 11809 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmul_rn(float x, float y) ;
# 11821 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_fmul_rz(float x, float y) ;
# 11831 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_double2float_rn(double d) ;
# 11840 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_double2float_rz(double d) ;
# 11849 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_double2float_rd(double d) ;
# 11858 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_double2float_ru(double d) ;
# 11868 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_double2int_rn(double d) ;
# 11877 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_double2int_rz(double d) ;
# 11886 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_double2int_rd(double d) ;
# 11895 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_double2int_ru(double d) ;
# 11905 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_double2uint_rn(double d) ;
# 11914 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_double2uint_rz(double d) ;
# 11923 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_double2uint_rd(double d) ;
# 11932 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_double2uint_ru(double d) ;
# 11941 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_int2double_rn(int i) ;
# 11950 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_uint2double_rn(unsigned int i) ;
# 11960 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_float2int_rn(float in) ;
# 11969 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_float2int_rz(float in) ;
# 11978 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_float2int_rd(float in) ;
# 11987 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_float2int_ru(float in) ;
# 11996 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_float2uint_rn(float in) ;
# 12005 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_float2uint_rz(float in) ;
# 12014 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_float2uint_rd(float in) ;
# 12023 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_float2uint_ru(float in) ;
# 12033 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_int2float_rn(int in) ;
# 12042 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_int2float_rz(int in) ;
# 12051 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_int2float_rd(int in) ;
# 12060 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_int2float_ru(int in) ;
# 12070 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_uint2float_rn(unsigned int in) ;
# 12079 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_uint2float_rz(unsigned int in) ;
# 12088 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_uint2float_rd(unsigned int in) ;
# 12097 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_uint2float_ru(unsigned int in) ;
# 12108 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_hiloint2double(int x, int y) ;
# 12117 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_double2loint(double d) ;
# 12126 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_double2hiint(double d) ;
# 12136 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_float2ll_rn(float f) ;
# 12145 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_float2ll_rz(float f) ;
# 12154 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_float2ll_rd(float f) ;
# 12163 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_float2ll_ru(float f) ;
# 12172 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_float2ull_rn(float f) ;
# 12181 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_float2ull_rz(float f) ;
# 12190 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_float2ull_rd(float f) ;
# 12199 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_float2ull_ru(float f) ;
# 12209 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_double2ll_rn(double f) ;
# 12218 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_double2ll_rz(double f) ;
# 12227 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_double2ll_rd(double f) ;
# 12236 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_double2ll_ru(double f) ;
# 12246 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_double2ull_rn(double f) ;
# 12255 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_double2ull_rz(double f) ;
# 12264 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_double2ull_rd(double f) ;
# 12273 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned long long __nv_double2ull_ru(double f) ;
# 12283 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ll2float_rn(long long l) ;
# 12292 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ll2float_rz(long long l) ;
# 12301 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ll2float_rd(long long l) ;
# 12310 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ll2float_ru(long long l) ;
# 12320 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ull2float_rn(unsigned long long l) ;
# 12329 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ull2float_rz(unsigned long long l) ;
# 12338 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ull2float_rd(unsigned long long l) ;
# 12347 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_ull2float_ru(unsigned long long l) ;
# 12357 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ll2double_rn(long long l) ;
# 12366 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ll2double_rz(long long l) ;
# 12375 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ll2double_rd(long long l) ;
# 12384 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ll2double_ru(long long l) ;
# 12394 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ull2double_rn(unsigned long long l) ;
# 12403 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ull2double_rz(unsigned long long l) ;
# 12412 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ull2double_rd(unsigned long long l) ;
# 12421 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_ull2double_ru(unsigned long long l) ;
# 12431 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned short __nv_float2half_rn(float f) ;
# 12440 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_half2float(unsigned short h) ;
# 12449 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_int_as_float(int x) ;
# 12459 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 int __nv_float_as_int(float x) ;
# 12469 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 float __nv_uint_as_float(unsigned int x) ;
# 12479 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 unsigned int __nv_float_as_uint(float x) ;
# 12489 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 double __nv_longlong_as_double(long long x) ;
# 12499 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions_decls.h" 3
 long long __nv_double_as_longlong (double x) ;
# 9843 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 2 3


# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 1 3
# 3320 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 3
static __inline__ __attribute__((always_inline)) int __syncthreads_count(int predicate);

static __inline__ __attribute__((always_inline)) int __syncthreads_and(int predicate);

static __inline__ __attribute__((always_inline)) int __syncthreads_or(int predicate);






static __inline__ __attribute__((always_inline)) void __threadfence_block();

static __inline__ __attribute__((always_inline)) void __threadfence();

static __inline__ __attribute__((always_inline)) void __threadfence_system();






static __inline__ __attribute__((always_inline)) int __all(int a);

static __inline__ __attribute__((always_inline)) int __any(int a);

static __inline__ __attribute__((always_inline))



int

__ballot(int a);
# 3362 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 3
static __inline__ __attribute__((always_inline)) void __brkpt();


static __inline__ __attribute__((always_inline))



int

clock() ;

static __inline__ __attribute__((always_inline)) long long clock64();



static __inline__ __attribute__((always_inline)) unsigned int __pm0(void);

static __inline__ __attribute__((always_inline)) unsigned int __pm1(void);

static __inline__ __attribute__((always_inline)) unsigned int __pm2(void);

static __inline__ __attribute__((always_inline)) unsigned int __pm3(void);

static __inline__ __attribute__((always_inline)) void __trap(void);

static __inline__ __attribute__((always_inline)) void* memcpy(void *dest, const void *src, size_t n) ;

static __inline__ __attribute__((always_inline)) void* memset(void *dest, int c, size_t n) ;






static __inline__ __attribute__((always_inline)) int __clz(int x);

static __inline__ __attribute__((always_inline)) int __clzll(long long x);




static __inline__ __attribute__((always_inline)) int __popc(int x);





static __inline__ __attribute__((always_inline)) int __popcll(long long x);


static __inline__ __attribute__((always_inline)) unsigned int __byte_perm(unsigned int a,
                                                unsigned int b,
                                                unsigned int c);






static __inline__ __attribute__((always_inline)) int min(int x, int y);

static __inline__ __attribute__((always_inline)) unsigned int umin(unsigned int x, unsigned int y);

static __inline__ __attribute__((always_inline)) long long llmin(long long x, long long y);

static __inline__ __attribute__((always_inline)) unsigned long long ullmin(unsigned long long x,
                                                 unsigned long long y);

static __inline__ __attribute__((always_inline)) int max(int x, int y);

static __inline__ __attribute__((always_inline)) unsigned int umax(unsigned int x, unsigned int y);

static __inline__ __attribute__((always_inline)) long long llmax(long long x, long long y);

static __inline__ __attribute__((always_inline)) unsigned long long ullmax(unsigned long long x,
                                                 unsigned long long y);

static __inline__ __attribute__((always_inline)) int __mulhi(int x, int y);

static __inline__ __attribute__((always_inline)) unsigned int __umulhi(unsigned int x, unsigned int y);

static __inline__ __attribute__((always_inline)) long long __mul64hi(long long x, long long y);

static __inline__ __attribute__((always_inline)) unsigned long long __umul64hi(unsigned long long x,
                                                     unsigned long long y);

static __inline__ __attribute__((always_inline)) int __mul24(int x, int y);

static __inline__ __attribute__((always_inline)) unsigned int __umul24(unsigned int x, unsigned int y);

static __inline__ __attribute__((always_inline)) unsigned int __brev(unsigned int x);

static __inline__ __attribute__((always_inline)) unsigned long long __brevll(unsigned long long x);




static __inline__ __attribute__((always_inline)) int __sad(int x, int y, int z);


static __inline__ __attribute__((always_inline)) unsigned int __usad(unsigned int x,
                                           unsigned int y,
                                           unsigned int z);

static __inline__ __attribute__((always_inline)) int abs(int x) ;

static __inline__ __attribute__((always_inline)) long labs(long x) ;

static __inline__ __attribute__((always_inline)) long long llabs(long long x) ;






static __inline__ __attribute__((always_inline)) float floorf(float f);

static __inline__ __attribute__((always_inline)) double floor(double f);

static __inline__ __attribute__((always_inline)) float fabsf(float f);

static __inline__ __attribute__((always_inline)) double fabs(double f);

static __inline__ __attribute__((always_inline)) float fminf(float x, float y);

static __inline__ __attribute__((always_inline)) float fmaxf(float x, float y);

static __inline__ __attribute__((always_inline)) float rsqrtf(float x);

static __inline__ __attribute__((always_inline)) double fmin(double x, double y);

static __inline__ __attribute__((always_inline)) double fmax(double x, double y);

static __inline__ __attribute__((always_inline)) double rsqrt(double x);

static __inline__ __attribute__((always_inline)) double ceil(double x);

static __inline__ __attribute__((always_inline)) double trunc(double x);

static __inline__ __attribute__((always_inline)) float exp2f(float x);

static __inline__ __attribute__((always_inline)) float truncf(float x);

static __inline__ __attribute__((always_inline)) float ceilf(float x);

static __inline__ __attribute__((always_inline)) float __saturatef(float x);






static __inline__ __attribute__((always_inline)) float __fmaf_rn(float x, float y, float z);

static __inline__ __attribute__((always_inline)) float __fmaf_rz(float x, float y, float z);

static __inline__ __attribute__((always_inline)) float __fmaf_rd(float x, float y, float z);

static __inline__ __attribute__((always_inline)) float __fmaf_ru(float x, float y, float z);






static __inline__ __attribute__((always_inline)) float __fmaf_ieee_rn(float x, float y, float z);

static __inline__ __attribute__((always_inline)) float __fmaf_ieee_rz(float x, float y, float z);

static __inline__ __attribute__((always_inline)) float __fmaf_ieee_rd(float x, float y, float z);

static __inline__ __attribute__((always_inline)) float __fmaf_ieee_ru(float x, float y, float z);






static __inline__ __attribute__((always_inline)) double __fma_rn(double x, double y, double z);

static __inline__ __attribute__((always_inline)) double __fma_rz(double x, double y, double z);

static __inline__ __attribute__((always_inline)) double __fma_rd(double x, double y, double z);

static __inline__ __attribute__((always_inline)) double __fma_ru(double x, double y, double z);

static __inline__ __attribute__((always_inline)) float __fdividef(float x, float y);






static __inline__ __attribute__((always_inline)) float __fdiv_rn(float x, float y);

static __inline__ __attribute__((always_inline)) float __fdiv_rz(float x, float y);

static __inline__ __attribute__((always_inline)) float __fdiv_rd(float x, float y);

static __inline__ __attribute__((always_inline)) float __fdiv_ru(float x, float y);






static __inline__ __attribute__((always_inline)) float __frcp_rn(float x);

static __inline__ __attribute__((always_inline)) float __frcp_rz(float x);

static __inline__ __attribute__((always_inline)) float __frcp_rd(float x);

static __inline__ __attribute__((always_inline)) float __frcp_ru(float x);






static __inline__ __attribute__((always_inline)) float __fsqrt_rn(float x);

static __inline__ __attribute__((always_inline)) float __fsqrt_rz(float x);

static __inline__ __attribute__((always_inline)) float __fsqrt_rd(float x);

static __inline__ __attribute__((always_inline)) float __fsqrt_ru(float x);






static __inline__ __attribute__((always_inline)) double __ddiv_rn(double x, double y);

static __inline__ __attribute__((always_inline)) double __ddiv_rz(double x, double y);

static __inline__ __attribute__((always_inline)) double __ddiv_rd(double x, double y);

static __inline__ __attribute__((always_inline)) double __ddiv_ru(double x, double y);






static __inline__ __attribute__((always_inline)) double __drcp_rn(double x);

static __inline__ __attribute__((always_inline)) double __drcp_rz(double x);

static __inline__ __attribute__((always_inline)) double __drcp_rd(double x);

static __inline__ __attribute__((always_inline)) double __drcp_ru(double x);






static __inline__ __attribute__((always_inline)) double __dsqrt_rn(double x);

static __inline__ __attribute__((always_inline)) double __dsqrt_rz(double x);

static __inline__ __attribute__((always_inline)) double __dsqrt_rd(double x);

static __inline__ __attribute__((always_inline)) double __dsqrt_ru(double x);

static __inline__ __attribute__((always_inline)) float sqrtf(float x);

static __inline__ __attribute__((always_inline)) double sqrt(double x);






static __inline__ __attribute__((always_inline)) double __dadd_rn(double x, double y);

static __inline__ __attribute__((always_inline)) double __dadd_rz(double x, double y);

static __inline__ __attribute__((always_inline)) double __dadd_rd(double x, double y);

static __inline__ __attribute__((always_inline)) double __dadd_ru(double x, double y);






static __inline__ __attribute__((always_inline)) double __dmul_rn(double x, double y);

static __inline__ __attribute__((always_inline)) double __dmul_rz(double x, double y);

static __inline__ __attribute__((always_inline)) double __dmul_rd(double x, double y);

static __inline__ __attribute__((always_inline)) double __dmul_ru(double x, double y);






static __inline__ __attribute__((always_inline)) float __fadd_rd(float x, float y);

static __inline__ __attribute__((always_inline)) float __fadd_ru(float x, float y);

static __inline__ __attribute__((always_inline)) float __fadd_rn(float x, float y);

static __inline__ __attribute__((always_inline)) float __fadd_rz(float x, float y);






static __inline__ __attribute__((always_inline)) float __fmul_rd(float x, float y);

static __inline__ __attribute__((always_inline)) float __fmul_ru(float x, float y);

static __inline__ __attribute__((always_inline)) float __fmul_rn(float x, float y);

static __inline__ __attribute__((always_inline)) float __fmul_rz(float x, float y);







static __inline__ __attribute__((always_inline)) float __double2float_rn(double d);

static __inline__ __attribute__((always_inline)) float __double2float_rz(double d);

static __inline__ __attribute__((always_inline)) float __double2float_rd(double d);

static __inline__ __attribute__((always_inline)) float __double2float_ru(double d);


static __inline__ __attribute__((always_inline)) int __double2int_rn(double d);

static __inline__ __attribute__((always_inline)) int __double2int_rz(double d);

static __inline__ __attribute__((always_inline)) int __double2int_rd(double d);

static __inline__ __attribute__((always_inline)) int __double2int_ru(double d);


static __inline__ __attribute__((always_inline)) unsigned int __double2uint_rn(double d);

static __inline__ __attribute__((always_inline)) unsigned int __double2uint_rz(double d);

static __inline__ __attribute__((always_inline)) unsigned int __double2uint_rd(double d);

static __inline__ __attribute__((always_inline)) unsigned int __double2uint_ru(double d);


static __inline__ __attribute__((always_inline)) double __int2double_rn(int i);


static __inline__ __attribute__((always_inline)) double __uint2double_rn(unsigned int i);


static __inline__ __attribute__((always_inline)) int __float2int_rn(float in);

static __inline__ __attribute__((always_inline)) int __float2int_rz(float in);

static __inline__ __attribute__((always_inline)) int __float2int_rd(float in);

static __inline__ __attribute__((always_inline)) int __float2int_ru(float in);


static __inline__ __attribute__((always_inline)) unsigned int __float2uint_rn(float in);

static __inline__ __attribute__((always_inline)) unsigned int __float2uint_rz(float in);

static __inline__ __attribute__((always_inline)) unsigned int __float2uint_rd(float in);

static __inline__ __attribute__((always_inline)) unsigned int __float2uint_ru(float in);


static __inline__ __attribute__((always_inline)) float __int2float_rn(int in);

static __inline__ __attribute__((always_inline)) float __int2float_rz(int in);

static __inline__ __attribute__((always_inline)) float __int2float_rd(int in);

static __inline__ __attribute__((always_inline)) float __int2float_ru(int in);


static __inline__ __attribute__((always_inline)) float __uint2float_rn(unsigned int in);

static __inline__ __attribute__((always_inline)) float __uint2float_rz(unsigned int in);

static __inline__ __attribute__((always_inline)) float __uint2float_rd(unsigned int in);

static __inline__ __attribute__((always_inline)) float __uint2float_ru(unsigned int in);


static __inline__ __attribute__((always_inline)) double __hiloint2double(int a, int b);

static __inline__ __attribute__((always_inline)) int __double2loint(double d);

static __inline__ __attribute__((always_inline)) int __double2hiint(double d);


static __inline__ __attribute__((always_inline)) long long __float2ll_rn(float f);

static __inline__ __attribute__((always_inline)) long long __float2ll_rz(float f);

static __inline__ __attribute__((always_inline)) long long __float2ll_rd(float f);

static __inline__ __attribute__((always_inline)) long long __float2ll_ru(float f);


static __inline__ __attribute__((always_inline)) unsigned long long __float2ull_rn(float f);

static __inline__ __attribute__((always_inline)) unsigned long long __float2ull_rz(float f);

static __inline__ __attribute__((always_inline)) unsigned long long __float2ull_rd(float f);

static __inline__ __attribute__((always_inline)) unsigned long long __float2ull_ru(float f);


static __inline__ __attribute__((always_inline)) long long __double2ll_rn(double f);

static __inline__ __attribute__((always_inline)) long long __double2ll_rz(double f);

static __inline__ __attribute__((always_inline)) long long __double2ll_rd(double f);

static __inline__ __attribute__((always_inline)) long long __double2ll_ru(double f);


static __inline__ __attribute__((always_inline)) unsigned long long __double2ull_rn(double f);

static __inline__ __attribute__((always_inline)) unsigned long long __double2ull_rz(double f);

static __inline__ __attribute__((always_inline)) unsigned long long __double2ull_rd(double f);

static __inline__ __attribute__((always_inline)) unsigned long long __double2ull_ru(double f);


static __inline__ __attribute__((always_inline)) float __ll2float_rn(long long l);

static __inline__ __attribute__((always_inline)) float __ll2float_rz(long long l);

static __inline__ __attribute__((always_inline)) float __ll2float_rd(long long l);

static __inline__ __attribute__((always_inline)) float __ll2float_ru(long long l);


static __inline__ __attribute__((always_inline)) float __ull2float_rn(unsigned long long l);

static __inline__ __attribute__((always_inline)) float __ull2float_rz(unsigned long long l);

static __inline__ __attribute__((always_inline)) float __ull2float_rd(unsigned long long l);

static __inline__ __attribute__((always_inline)) float __ull2float_ru(unsigned long long l);


static __inline__ __attribute__((always_inline)) double __ll2double_rn(long long l);

static __inline__ __attribute__((always_inline)) double __ll2double_rz(long long l);

static __inline__ __attribute__((always_inline)) double __ll2double_rd(long long l);

static __inline__ __attribute__((always_inline)) double __ll2double_ru(long long l);


static __inline__ __attribute__((always_inline)) double __ull2double_rn(unsigned long long l);

static __inline__ __attribute__((always_inline)) double __ull2double_rz(unsigned long long l);

static __inline__ __attribute__((always_inline)) double __ull2double_rd(unsigned long long l);

static __inline__ __attribute__((always_inline)) double __ull2double_ru(unsigned long long l);

static __inline__ __attribute__((always_inline)) unsigned short __float2half_rn(float f);

static __inline__ __attribute__((always_inline)) float __half2float(unsigned short h);

static __inline__ __attribute__((always_inline)) float __int_as_float(int x);

static __inline__ __attribute__((always_inline)) int __float_as_int(float x);

static __inline__ __attribute__((always_inline)) float __uint_as_float(unsigned int x);

static __inline__ __attribute__((always_inline)) unsigned int __float_as_uint(float x);

static __inline__ __attribute__((always_inline)) double __longlong_as_double(long long x);

static __inline__ __attribute__((always_inline)) long long __double_as_longlong (double x);







static __inline__ __attribute__((always_inline)) float __sinf(float a) ;

static __inline__ __attribute__((always_inline)) float __cosf(float a) ;

static __inline__ __attribute__((always_inline)) float __log2f(float a) ;







static __inline__ __attribute__((always_inline)) float __tanf(float a) ;

static __inline__ __attribute__((always_inline)) void __sincosf(float a, float *sptr, float *cptr) ;

static __inline__ __attribute__((always_inline)) float __expf(float a) ;

static __inline__ __attribute__((always_inline)) float __exp10f(float a) ;

static __inline__ __attribute__((always_inline)) float __log10f(float a) ;

static __inline__ __attribute__((always_inline)) float __logf(float a) ;

static __inline__ __attribute__((always_inline)) float __powf(float a, float b) ;

static __inline__ __attribute__((always_inline)) float fdividef(float a, float b);

static __inline__ __attribute__((always_inline)) double fdivide(double a, double b);

static __inline__ __attribute__((always_inline)) int __hadd(int a, int b);

static __inline__ __attribute__((always_inline)) int __rhadd(int a, int b);

static __inline__ __attribute__((always_inline)) unsigned int __uhadd(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __urhadd(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) float __fsub_rn (float a, float b);

static __inline__ __attribute__((always_inline)) float __fsub_rz (float a, float b);

static __inline__ __attribute__((always_inline)) float __fsub_rd (float a, float b);

static __inline__ __attribute__((always_inline)) float __fsub_ru (float a, float b);

static __inline__ __attribute__((always_inline)) float __frsqrt_rn (float a);

static __inline__ __attribute__((always_inline)) int __ffs(int a);

static __inline__ __attribute__((always_inline)) int __ffsll(long long int a);






static __inline__ __attribute__((always_inline))
int __iAtomicAdd(int *p, int val);


static __inline__ __attribute__((always_inline))
int __iAtomicAdd_block(int *p, int val);

static __inline__ __attribute__((always_inline))
int __iAtomicAdd_system(int *p, int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAdd(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAdd_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAdd_system(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAdd(unsigned long long *p, unsigned long long val);


static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAdd_block(unsigned long long *p, unsigned long long val);

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAdd_system(unsigned long long *p, unsigned long long val);


static __inline__ __attribute__((always_inline))
float __fAtomicAdd(float *p, float val);


static __inline__ __attribute__((always_inline))
float __fAtomicAdd_block(float *p, float val);

static __inline__ __attribute__((always_inline))
float __fAtomicAdd_system(float *p, float val);

static __inline__ __attribute__((always_inline))
double __dAtomicAdd(double *p, double val);

static __inline__ __attribute__((always_inline))
double __dAtomicAdd_block(double *p, double val);

static __inline__ __attribute__((always_inline))
double __dAtomicAdd_system(double *p, double val);


static __inline__ __attribute__((always_inline))
int __iAtomicExch(int *p, int val);


static __inline__ __attribute__((always_inline))
int __iAtomicExch_block(int *p, int val);

static __inline__ __attribute__((always_inline))
int __iAtomicExch_system(int *p, int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicExch(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicExch_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicExch_system(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicExch(unsigned long long *p,
                                   unsigned long long val);


static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicExch_block(unsigned long long *p, unsigned long long val);

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicExch_system(unsigned long long *p, unsigned long long val);


static __inline__ __attribute__((always_inline))
float __fAtomicExch(float *p, float val);


static __inline__ __attribute__((always_inline))
float __fAtomicExch_block(float *p, float val);

static __inline__ __attribute__((always_inline))
float __fAtomicExch_system(float *p, float val);


static __inline__ __attribute__((always_inline))
int __iAtomicMin(int *p, int val);


static __inline__ __attribute__((always_inline))
int __iAtomicMin_block(int *p, int val);

static __inline__ __attribute__((always_inline))
int __iAtomicMin_system(int *p, int val);



static __inline__ __attribute__((always_inline))
long long __illAtomicMin(long long *p, long long val);



static __inline__ __attribute__((always_inline))
long long __illAtomicMin_block(long long *p, long long val);

static __inline__ __attribute__((always_inline))
long long __illAtomicMin_system(long long *p, long long val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMin(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMin_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMin_system(unsigned int *p, unsigned int val);



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMin(unsigned long long *p, unsigned long long val);



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMin_block(unsigned long long *p, unsigned long long val);

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMin_system(unsigned long long *p, unsigned long long val);


static __inline__ __attribute__((always_inline))
int __iAtomicMax(int *p, int val);


static __inline__ __attribute__((always_inline))
int __iAtomicMax_block(int *p, int val);

static __inline__ __attribute__((always_inline))
int __iAtomicMax_system(int *p, int val);



static __inline__ __attribute__((always_inline))
long long __illAtomicMax(long long *p, long long val);



static __inline__ __attribute__((always_inline))
long long __illAtomicMax_block(long long *p, long long val);

static __inline__ __attribute__((always_inline))
long long __illAtomicMax_system(long long *p, long long val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMax(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMax_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMax_system(unsigned int *p, unsigned int val);



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMax(unsigned long long *p, unsigned long long val);



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMax_block(unsigned long long *p, unsigned long long val);

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMax_system(unsigned long long *p, unsigned long long val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicInc(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicInc_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicInc_system(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicDec(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicDec_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicDec_system(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
int __iAtomicCAS(int *p, int compare, int val);


static __inline__ __attribute__((always_inline))
int __iAtomicCAS_block(int *p, int compare, int val);

static __inline__ __attribute__((always_inline))
int __iAtomicCAS_system(int *p, int compare, int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicCAS(unsigned int *p, unsigned int compare,
                          unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicCAS_block(unsigned int *p, unsigned int compare,
                                unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicCAS_system(unsigned int *p, unsigned int compare,
                                 unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicCAS(unsigned long long int *p,
                                      unsigned long long int compare,
                                      unsigned long long int val);


static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicCAS_block(unsigned long long int *p,
                                            unsigned long long int compare,
                                            unsigned long long int val);

static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicCAS_system(unsigned long long int *p,
                                             unsigned long long int compare,
                                             unsigned long long int val);


static __inline__ __attribute__((always_inline))
int __iAtomicAnd(int *p, int val);


static __inline__ __attribute__((always_inline))
int __iAtomicAnd_block(int *p, int val);

static __inline__ __attribute__((always_inline))
int __iAtomicAnd_system(int *p, int val);



static __inline__ __attribute__((always_inline))
long long int __llAtomicAnd(long long int *p, long long int val);



static __inline__ __attribute__((always_inline))
long long __llAtomicAnd_block(long long *p, long long val);

static __inline__ __attribute__((always_inline))
long long __llAtomicAnd_system(long long *p, long long val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAnd(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAnd_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAnd_system(unsigned int *p, unsigned int val);



static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicAnd(unsigned long long int *p,
                                      unsigned long long int val);



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAnd_block(unsigned long long *p, unsigned long long val);

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAnd_system(unsigned long long *p, unsigned long long val);


static __inline__ __attribute__((always_inline))
int __iAtomicOr(int *p, int val);


static __inline__ __attribute__((always_inline))
int __iAtomicOr_block(int *p, int val);

static __inline__ __attribute__((always_inline))
int __iAtomicOr_system(int *p, int val);



static __inline__ __attribute__((always_inline))
long long int __llAtomicOr(long long int *p, long long int val);



static __inline__ __attribute__((always_inline))
long long __llAtomicOr_block(long long *p, long long val);

static __inline__ __attribute__((always_inline))
long long __llAtomicOr_system(long long *p, long long val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicOr(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicOr_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicOr_system(unsigned int *p, unsigned int val);



static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicOr(unsigned long long int *p,
                                     unsigned long long int val);



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicOr_block(unsigned long long *p, unsigned long long val);

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicOr_system(unsigned long long *p, unsigned long long val);


static __inline__ __attribute__((always_inline))
int __iAtomicXor(int *p, int val);


static __inline__ __attribute__((always_inline))
int __iAtomicXor_block(int *p, int val);

static __inline__ __attribute__((always_inline))
int __iAtomicXor_system(int *p, int val);



static __inline__ __attribute__((always_inline))
long long int __llAtomicXor(long long int *p, long long int val);



static __inline__ __attribute__((always_inline))
long long __llAtomicXor_block(long long *p, long long val);

static __inline__ __attribute__((always_inline))
long long __llAtomicXor_system(long long *p, long long val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicXor(unsigned int *p, unsigned int val);


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicXor_block(unsigned int *p, unsigned int val);

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicXor_system(unsigned int *p, unsigned int val);



static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicXor(unsigned long long int *p,
                                      unsigned long long int val);



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicXor_block(unsigned long long *p, unsigned long long val);

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicXor_system(unsigned long long *p, unsigned long long val);
# 4327 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 3
static __inline__ __attribute__((always_inline)) unsigned int __vabs2(unsigned int a);

static __inline__ __attribute__((always_inline)) unsigned int __vabsss2(unsigned int a);

static __inline__ __attribute__((always_inline)) unsigned int __vadd2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vaddss2 (unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vaddus2 (unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vavgs2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vavgu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vhaddu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpeq2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpges2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgeu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgts2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgtu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmples2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpleu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmplts2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpltu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpne2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vabsdiffu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vmaxs2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vmaxu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vmins2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vminu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vseteq2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetges2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetgeu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetgts2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetgtu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetles2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetleu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetlts2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetltu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetne2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsadu2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsub2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsubss2 (unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsubus2 (unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vneg2(unsigned int a);

static __inline__ __attribute__((always_inline)) unsigned int __vnegss2(unsigned int a);

static __inline__ __attribute__((always_inline)) unsigned int __vabsdiffs2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsads2(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vabs4(unsigned int a);

static __inline__ __attribute__((always_inline)) unsigned int __vabsss4(unsigned int a);

static __inline__ __attribute__((always_inline)) unsigned int __vadd4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vaddss4 (unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vaddus4 (unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vavgs4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vavgu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vhaddu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpeq4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpges4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgeu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgts4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgtu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmples4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpleu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmplts4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpltu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vcmpne4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vabsdiffu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vmaxs4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vmaxu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vmins4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vminu4(unsigned int a, unsigned int b);
static __inline__ __attribute__((always_inline)) unsigned int __vseteq4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetles4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetleu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetlts4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetltu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetges4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetgeu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetgts4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetgtu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsetne4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsadu4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsub4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsubss4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsubus4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vneg4(unsigned int a);

static __inline__ __attribute__((always_inline)) unsigned int __vnegss4(unsigned int a);

static __inline__ __attribute__((always_inline)) unsigned int __vabsdiffs4(unsigned int a, unsigned int b);

static __inline__ __attribute__((always_inline)) unsigned int __vsads4(unsigned int a, unsigned int b);
# 4511 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 1 3
# 256 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
static __inline__ __attribute__((always_inline)) int __syncthreads_count(int predicate)
{
  return __nvvm_bar0_popc(predicate);
}

static __inline__ __attribute__((always_inline)) int __syncthreads_and(int predicate)
{
  return __nvvm_bar0_and(predicate);
}

static __inline__ __attribute__((always_inline)) int __syncthreads_or(int predicate)
{
  return __nvvm_bar0_or(predicate);
}






static __inline__ __attribute__((always_inline)) void __threadfence_block()
{
  __nvvm_membar_cta();
}

static __inline__ __attribute__((always_inline)) void __threadfence()
{
  __nvvm_membar_gl();
}

static __inline__ __attribute__((always_inline)) void __threadfence_system()
{
  __nvvm_membar_sys();
}






static __inline__ __attribute__((always_inline)) int __all(int a)
{
  int result;
  asm __volatile__ ("{ \n\t"
        ".reg .pred \t%%p1; \n\t"
        ".reg .pred \t%%p2; \n\t"
        "setp.ne.u32 \t%%p1, %1, 0; \n\t"
        "vote.all.pred \t%%p2, %%p1; \n\t"
        "selp.s32 \t%0, 1, 0, %%p2; \n\t"
        "}" : "=r"(result) : "r"(a));
  return result;
}

static __inline__ __attribute__((always_inline)) int __any(int a)
{
  int result;
  asm __volatile__ ("{ \n\t"
        ".reg .pred \t%%p1; \n\t"
        ".reg .pred \t%%p2; \n\t"
        "setp.ne.u32 \t%%p1, %1, 0; \n\t"
        "vote.any.pred \t%%p2, %%p1; \n\t"
        "selp.s32 \t%0, 1, 0, %%p2; \n\t"
        "}" : "=r"(result) : "r"(a));
  return result;
}

static __inline__ __attribute__((always_inline))



int

__ballot(int a)
{
  int result;
  asm __volatile__ ("{ \n\t"
        ".reg .pred \t%%p1; \n\t"
        "setp.ne.u32 \t%%p1, %1, 0; \n\t"
        "vote.ballot.b32 \t%0, %%p1; \n\t"
        "}" : "=r"(result) : "r"(a));
  return result;
}
# 347 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
static __inline__ __attribute__((always_inline)) void __brkpt()

{
  asm __volatile__ ("brkpt;");
}




static __inline__ __attribute__((always_inline)) int clock()

{
  int r;
  asm __volatile__ ("mov.u32 \t%0, %%clock;" : "=r"(r));
  return r;
}

static __inline__ __attribute__((always_inline)) long long clock64()
{
  long long z;
  asm __volatile__ ("mov.u64 \t%0, %%clock64;" : "=l"(z));
  return z;
}



static __inline__ __attribute__((always_inline)) unsigned int __pm0(void)
{
  unsigned int r;
  asm("mov.u32 \t%0, %%pm0;" : "=r"(r));
  return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __pm1(void)
{
  unsigned int r;
  asm("mov.u32 \t%0, %%pm1;" : "=r"(r));
  return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __pm2(void)
{
  unsigned int r;
  asm("mov.u32 \t%0, %%pm2;" : "=r"(r));
  return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __pm3(void)
{
  unsigned int r;
  asm("mov.u32 \t%0, %%pm3;" : "=r"(r));
  return r;
}

static __inline__ __attribute__((always_inline)) void __trap(void)
{
  asm __volatile__ ("trap;");
}

static __inline__ __attribute__((always_inline)) void* memcpy(void *dest, const void *src, size_t n)
{



  __nvvm_memcpy((unsigned char *)dest, (unsigned char *)src, n,
                               1);
  return dest;

}

static __inline__ __attribute__((always_inline)) void* memset(void *dest, int c, size_t n)
{



  __nvvm_memset((unsigned char *)dest, (unsigned char)c, n,
                              1);
  return dest;


}






static __inline__ __attribute__((always_inline)) int __clz(int x)
{
  return __nv_clz(x);
}

static __inline__ __attribute__((always_inline)) int __clzll(long long x)
{
  return __nv_clzll(x);
}




static __inline__ __attribute__((always_inline)) int __popc(int x)

{
  return __nv_popc(x);
}




static __inline__ __attribute__((always_inline)) int __popcll(long long x)

{
  return __nv_popcll(x);
}

static __inline__ __attribute__((always_inline)) unsigned int __byte_perm(unsigned int a,
                                                unsigned int b,
                                                unsigned int c)
{
  return __nv_byte_perm(a, b, c);
}






static __inline__ __attribute__((always_inline)) int min(int x, int y)
{
  return __nv_min(x, y);
}

static __inline__ __attribute__((always_inline)) unsigned int umin(unsigned int x, unsigned int y)
{
  return __nv_umin(x, y);
}

static __inline__ __attribute__((always_inline)) long long llmin(long long x, long long y)
{
  return __nv_llmin(x, y);
}

static __inline__ __attribute__((always_inline)) unsigned long long ullmin(unsigned long long x,
                                                 unsigned long long y)
{
  return __nv_ullmin(x, y);
}

static __inline__ __attribute__((always_inline)) int max(int x, int y)
{
  return __nv_max(x, y);
}

static __inline__ __attribute__((always_inline)) unsigned int umax(unsigned int x, unsigned int y)
{
  return __nv_umax(x, y);
}

static __inline__ __attribute__((always_inline)) long long llmax(long long x, long long y)
{
  return __nv_llmax(x, y);
}

static __inline__ __attribute__((always_inline)) unsigned long long ullmax(unsigned long long x,
                                                 unsigned long long y)
{
  return __nv_ullmax(x, y);
}

static __inline__ __attribute__((always_inline)) int __mulhi(int x, int y)
{
  return __nv_mulhi(x, y);
}

static __inline__ __attribute__((always_inline)) unsigned int __umulhi(unsigned int x, unsigned int y)
{
  return __nv_umulhi(x, y);
}

static __inline__ __attribute__((always_inline)) long long __mul64hi(long long x, long long y)
{
  return __nv_mul64hi(x, y);
}

static __inline__ __attribute__((always_inline)) unsigned long long __umul64hi(unsigned long long x,
                                                     unsigned long long y)
{
  return __nv_umul64hi(x, y);
}

static __inline__ __attribute__((always_inline)) int __mul24(int x, int y)
{
  return __nv_mul24(x, y);
}

static __inline__ __attribute__((always_inline)) unsigned int __umul24(unsigned int x, unsigned int y)
{
  return __nv_umul24(x, y);
}

static __inline__ __attribute__((always_inline)) unsigned int __brev(unsigned int x)
{
  return __nv_brev(x);
}

static __inline__ __attribute__((always_inline)) unsigned long long __brevll(unsigned long long x)
{
  return __nv_brevll(x);
}




static __inline__ __attribute__((always_inline)) int __sad(int x, int y, int z)

{
  return __nv_sad(x, y, z);
}

static __inline__ __attribute__((always_inline)) unsigned int __usad(unsigned int x,
                                           unsigned int y,
                                           unsigned int z)
{
  return __nv_usad(x, y, z);
}

static __inline__ __attribute__((always_inline)) int abs(int x)
{
  return __nv_abs(x);
}

static __inline__ __attribute__((always_inline)) long labs(long x)
{

  return __nv_llabs((long long) x);



}

static __inline__ __attribute__((always_inline)) long long llabs(long long x)
{
  return __nv_llabs(x);
}






static __inline__ __attribute__((always_inline)) float floorf(float f)
{
  return __nv_floorf(f);
}

static __inline__ __attribute__((always_inline)) double floor(double f)
{
  return __nv_floor(f);
}

static __inline__ __attribute__((always_inline)) float fabsf(float f)
{
  return __nv_fabsf(f);
}

static __inline__ __attribute__((always_inline)) double fabs(double f)
{
  return __nv_fabs(f);
}

static __inline__ __attribute__((always_inline)) float fminf(float x, float y)
{
  return __nv_fminf(x, y);
}

static __inline__ __attribute__((always_inline)) float fmaxf(float x, float y)
{
  return __nv_fmaxf(x, y);
}

static __inline__ __attribute__((always_inline)) float rsqrtf(float x)
{
  return __nv_rsqrtf(x);
}

static __inline__ __attribute__((always_inline)) double fmin(double x, double y)
{
  return __nv_fmin(x, y);
}

static __inline__ __attribute__((always_inline)) double fmax(double x, double y)
{
  return __nv_fmax(x, y);
}

static __inline__ __attribute__((always_inline)) double rsqrt(double x)
{
  return __nv_rsqrt(x);
}

static __inline__ __attribute__((always_inline)) double ceil(double x)
{
  return __nv_ceil(x);
}

static __inline__ __attribute__((always_inline)) double trunc(double x)
{
  return __nv_trunc(x);
}

static __inline__ __attribute__((always_inline)) float exp2f(float x)
{
  return __nv_exp2f(x);
}

static __inline__ __attribute__((always_inline)) float truncf(float x)
{
  return __nv_truncf(x);
}

static __inline__ __attribute__((always_inline)) float ceilf(float x)
{
  return __nv_ceilf(x);
}

static __inline__ __attribute__((always_inline)) float __saturatef(float x)
{
  return __nv_saturatef(x);
}






static __inline__ __attribute__((always_inline)) float __fmaf_rn(float x, float y, float z)
{
  return __nv_fmaf_rn(x, y, z);
}

static __inline__ __attribute__((always_inline)) float __fmaf_rz(float x, float y, float z)
{
  return __nv_fmaf_rz(x, y, z);
}

static __inline__ __attribute__((always_inline)) float __fmaf_rd(float x, float y, float z)
{
  return __nv_fmaf_rd(x, y, z);
}

static __inline__ __attribute__((always_inline)) float __fmaf_ru(float x, float y, float z)
{
  return __nv_fmaf_ru(x, y, z);
}






static __inline__ __attribute__((always_inline)) float __fmaf_ieee_rn(float x, float y, float z)
{
  return __nv_fmaf_ieee_rn(x, y, z);
}

static __inline__ __attribute__((always_inline)) float __fmaf_ieee_rz(float x, float y, float z)
{
  return __nv_fmaf_ieee_rz(x, y, z);
}

static __inline__ __attribute__((always_inline)) float __fmaf_ieee_rd(float x, float y, float z)
{
  return __nv_fmaf_ieee_rd(x, y, z);
}

static __inline__ __attribute__((always_inline)) float __fmaf_ieee_ru(float x, float y, float z)
{
  return __nv_fmaf_ieee_ru(x, y, z);
}






static __inline__ __attribute__((always_inline)) double __fma_rn(double x, double y, double z)
{
  return __nv_fma_rn(x, y, z);
}

static __inline__ __attribute__((always_inline)) double __fma_rz(double x, double y, double z)
{
  return __nv_fma_rz(x, y, z);
}

static __inline__ __attribute__((always_inline)) double __fma_rd(double x, double y, double z)
{
  return __nv_fma_rd(x, y, z);
}

static __inline__ __attribute__((always_inline)) double __fma_ru(double x, double y, double z)
{
  return __nv_fma_ru(x, y, z);
}

static __inline__ __attribute__((always_inline)) float __fdividef(float x, float y)
{
  return __nv_fast_fdividef(x, y);
}






static __inline__ __attribute__((always_inline)) float __fdiv_rn(float x, float y)
{
  return __nv_fdiv_rn(x, y);
}

static __inline__ __attribute__((always_inline)) float __fdiv_rz(float x, float y)
{
  return __nv_fdiv_rz(x, y);
}

static __inline__ __attribute__((always_inline)) float __fdiv_rd(float x, float y)
{
  return __nv_fdiv_rd(x, y);
}

static __inline__ __attribute__((always_inline)) float __fdiv_ru(float x, float y)
{
  return __nv_fdiv_ru(x, y);
}






static __inline__ __attribute__((always_inline)) float __frcp_rn(float x)
{
  return __nv_frcp_rn(x);
}

static __inline__ __attribute__((always_inline)) float __frcp_rz(float x)
{
  return __nv_frcp_rz(x);
}

static __inline__ __attribute__((always_inline)) float __frcp_rd(float x)
{
  return __nv_frcp_rd(x);
}

static __inline__ __attribute__((always_inline)) float __frcp_ru(float x)
{
  return __nv_frcp_ru(x);
}






static __inline__ __attribute__((always_inline)) float __fsqrt_rn(float x)
{
  return __nv_fsqrt_rn(x);
}

static __inline__ __attribute__((always_inline)) float __fsqrt_rz(float x)
{
  return __nv_fsqrt_rz(x);
}

static __inline__ __attribute__((always_inline)) float __fsqrt_rd(float x)
{
  return __nv_fsqrt_rd(x);
}

static __inline__ __attribute__((always_inline)) float __fsqrt_ru(float x)
{
  return __nv_fsqrt_ru(x);
}






static __inline__ __attribute__((always_inline)) double __ddiv_rn(double x, double y)
{
  return __nv_ddiv_rn(x, y);
}

static __inline__ __attribute__((always_inline)) double __ddiv_rz(double x, double y)
{
  return __nv_ddiv_rz(x, y);
}

static __inline__ __attribute__((always_inline)) double __ddiv_rd(double x, double y)
{
  return __nv_ddiv_rd(x, y);
}

static __inline__ __attribute__((always_inline)) double __ddiv_ru(double x, double y)
{
  return __nv_ddiv_ru(x, y);
}






static __inline__ __attribute__((always_inline)) double __drcp_rn(double x)
{
  return __nv_drcp_rn(x);
}

static __inline__ __attribute__((always_inline)) double __drcp_rz(double x)
{
  return __nv_drcp_rz(x);
}

static __inline__ __attribute__((always_inline)) double __drcp_rd(double x)
{
  return __nv_drcp_rd(x);
}

static __inline__ __attribute__((always_inline)) double __drcp_ru(double x)
{
  return __nv_drcp_ru(x);
}






static __inline__ __attribute__((always_inline)) double __dsqrt_rn(double x)
{
  return __nv_dsqrt_rn(x);
}

static __inline__ __attribute__((always_inline)) double __dsqrt_rz(double x)
{
  return __nv_dsqrt_rz(x);
}

static __inline__ __attribute__((always_inline)) double __dsqrt_rd(double x)
{
  return __nv_dsqrt_rd(x);
}

static __inline__ __attribute__((always_inline)) double __dsqrt_ru(double x)
{
  return __nv_dsqrt_ru(x);
}

static __inline__ __attribute__((always_inline)) float sqrtf(float x)
{
  return __nv_sqrtf(x);
}

static __inline__ __attribute__((always_inline)) double sqrt(double x)
{
  return __nv_sqrt(x);
}






static __inline__ __attribute__((always_inline)) double __dadd_rn(double x, double y)
{
  return __nv_dadd_rn(x, y);
}

static __inline__ __attribute__((always_inline)) double __dadd_rz(double x, double y)
{
  return __nv_dadd_rz(x, y);
}

static __inline__ __attribute__((always_inline)) double __dadd_rd(double x, double y)
{
  return __nv_dadd_rd(x, y);
}

static __inline__ __attribute__((always_inline)) double __dadd_ru(double x, double y)
{
  return __nv_dadd_ru(x, y);
}






static __inline__ __attribute__((always_inline)) double __dmul_rn(double x, double y)
{
  return __nv_dmul_rn(x, y);
}

static __inline__ __attribute__((always_inline)) double __dmul_rz(double x, double y)
{
  return __nv_dmul_rz(x, y);
}

static __inline__ __attribute__((always_inline)) double __dmul_rd(double x, double y)
{
  return __nv_dmul_rd(x, y);
}

static __inline__ __attribute__((always_inline)) double __dmul_ru(double x, double y)
{
  return __nv_dmul_ru(x, y);
}






static __inline__ __attribute__((always_inline)) float __fadd_rd(float x, float y)
{
  return __nv_fadd_rd(x, y);
}

static __inline__ __attribute__((always_inline)) float __fadd_ru(float x, float y)
{
  return __nv_fadd_ru(x, y);
}

static __inline__ __attribute__((always_inline)) float __fadd_rn(float x, float y)
{
  return __nv_fadd_rn(x, y);
}

static __inline__ __attribute__((always_inline)) float __fadd_rz(float x, float y)
{
  return __nv_fadd_rz(x, y);
}






static __inline__ __attribute__((always_inline)) float __fmul_rd(float x, float y)
{
  return __nv_fmul_rd(x, y);
}

static __inline__ __attribute__((always_inline)) float __fmul_ru(float x, float y)
{
  return __nv_fmul_ru(x, y);
}

static __inline__ __attribute__((always_inline)) float __fmul_rn(float x, float y)
{
  return __nv_fmul_rn(x, y);
}

static __inline__ __attribute__((always_inline)) float __fmul_rz(float x, float y)
{
  return __nv_fmul_rz(x, y);
}







static __inline__ __attribute__((always_inline)) float __double2float_rn(double d)
{
  return __nv_double2float_rn(d);
}

static __inline__ __attribute__((always_inline)) float __double2float_rz(double d)
{
  return __nv_double2float_rz(d);
}

static __inline__ __attribute__((always_inline)) float __double2float_rd(double d)
{
  return __nv_double2float_rd(d);
}

static __inline__ __attribute__((always_inline)) float __double2float_ru(double d)
{
  return __nv_double2float_ru(d);
}


static __inline__ __attribute__((always_inline)) int __double2int_rn(double d)
{
  return __nv_double2int_rn(d);
}

static __inline__ __attribute__((always_inline)) int __double2int_rz(double d)
{
  return __nv_double2int_rz(d);
}

static __inline__ __attribute__((always_inline)) int __double2int_rd(double d)
{
  return __nv_double2int_rd(d);
}

static __inline__ __attribute__((always_inline)) int __double2int_ru(double d)
{
  return __nv_double2int_ru(d);
}


static __inline__ __attribute__((always_inline)) unsigned int __double2uint_rn(double d)
{
  return __nv_double2uint_rn(d);
}

static __inline__ __attribute__((always_inline)) unsigned int __double2uint_rz(double d)
{
  return __nv_double2uint_rz(d);
}

static __inline__ __attribute__((always_inline)) unsigned int __double2uint_rd(double d)
{
  return __nv_double2uint_rd(d);
}

static __inline__ __attribute__((always_inline)) unsigned int __double2uint_ru(double d)
{
  return __nv_double2uint_ru(d);
}


static __inline__ __attribute__((always_inline)) double __int2double_rn(int i)
{
  return __nv_int2double_rn(i);
}


static __inline__ __attribute__((always_inline)) double __uint2double_rn(unsigned int i)
{
  return __nv_uint2double_rn(i);
}


static __inline__ __attribute__((always_inline)) int __float2int_rn(float in)
{
  return __nv_float2int_rn(in);
}

static __inline__ __attribute__((always_inline)) int __float2int_rz(float in)
{
  return __nv_float2int_rz(in);
}

static __inline__ __attribute__((always_inline)) int __float2int_rd(float in)
{
  return __nv_float2int_rd(in);
}

static __inline__ __attribute__((always_inline)) int __float2int_ru(float in)
{
  return __nv_float2int_ru(in);
}


static __inline__ __attribute__((always_inline)) unsigned int __float2uint_rn(float in)
{
  return __nv_float2uint_rn(in);
}

static __inline__ __attribute__((always_inline)) unsigned int __float2uint_rz(float in)
{
  return __nv_float2uint_rz(in);
}

static __inline__ __attribute__((always_inline)) unsigned int __float2uint_rd(float in)
{
  return __nv_float2uint_rd(in);
}

static __inline__ __attribute__((always_inline)) unsigned int __float2uint_ru(float in)
{
  return __nv_float2uint_ru(in);
}


static __inline__ __attribute__((always_inline)) float __int2float_rn(int in)
{
  return __nv_int2float_rn(in);
}

static __inline__ __attribute__((always_inline)) float __int2float_rz(int in)
{
  return __nv_int2float_rz(in);
}

static __inline__ __attribute__((always_inline)) float __int2float_rd(int in)
{
  return __nv_int2float_rd(in);
}

static __inline__ __attribute__((always_inline)) float __int2float_ru(int in)
{
  return __nv_int2float_ru(in);
}


static __inline__ __attribute__((always_inline)) float __uint2float_rn(unsigned int in)
{
  return __nv_uint2float_rn(in);
}

static __inline__ __attribute__((always_inline)) float __uint2float_rz(unsigned int in)
{
  return __nv_uint2float_rz(in);
}

static __inline__ __attribute__((always_inline)) float __uint2float_rd(unsigned int in)
{
  return __nv_uint2float_rd(in);
}

static __inline__ __attribute__((always_inline)) float __uint2float_ru(unsigned int in)
{
  return __nv_uint2float_ru(in);
}


static __inline__ __attribute__((always_inline)) double __hiloint2double(int a, int b)
{
  return __nv_hiloint2double(a, b);
}

static __inline__ __attribute__((always_inline)) int __double2loint(double d)
{
  return __nv_double2loint(d);
}

static __inline__ __attribute__((always_inline)) int __double2hiint(double d)
{
  return __nv_double2hiint(d);
}


static __inline__ __attribute__((always_inline)) long long __float2ll_rn(float f)
{
  return __nv_float2ll_rn(f);
}

static __inline__ __attribute__((always_inline)) long long __float2ll_rz(float f)
{
  return __nv_float2ll_rz(f);
}

static __inline__ __attribute__((always_inline)) long long __float2ll_rd(float f)
{
  return __nv_float2ll_rd(f);
}

static __inline__ __attribute__((always_inline)) long long __float2ll_ru(float f)
{
  return __nv_float2ll_ru(f);
}


static __inline__ __attribute__((always_inline)) unsigned long long __float2ull_rn(float f)
{
  return __nv_float2ull_rn(f);
}

static __inline__ __attribute__((always_inline)) unsigned long long __float2ull_rz(float f)
{
  return __nv_float2ull_rz(f);
}

static __inline__ __attribute__((always_inline)) unsigned long long __float2ull_rd(float f)
{
  return __nv_float2ull_rd(f);
}

static __inline__ __attribute__((always_inline)) unsigned long long __float2ull_ru(float f)
{
  return __nv_float2ull_ru(f);
}


static __inline__ __attribute__((always_inline)) long long __double2ll_rn(double f)
{
  return __nv_double2ll_rn(f);
}

static __inline__ __attribute__((always_inline)) long long __double2ll_rz(double f)
{
  return __nv_double2ll_rz(f);
}

static __inline__ __attribute__((always_inline)) long long __double2ll_rd(double f)
{
  return __nv_double2ll_rd(f);
}

static __inline__ __attribute__((always_inline)) long long __double2ll_ru(double f)
{
  return __nv_double2ll_ru(f);
}


static __inline__ __attribute__((always_inline)) unsigned long long __double2ull_rn(double f)
{
  return __nv_double2ull_rn(f);
}

static __inline__ __attribute__((always_inline)) unsigned long long __double2ull_rz(double f)
{
  return __nv_double2ull_rz(f);
}

static __inline__ __attribute__((always_inline)) unsigned long long __double2ull_rd(double f)
{
  return __nv_double2ull_rd(f);
}

static __inline__ __attribute__((always_inline)) unsigned long long __double2ull_ru(double f)
{
  return __nv_double2ull_ru(f);
}


static __inline__ __attribute__((always_inline)) float __ll2float_rn(long long l)
{
  return __nv_ll2float_rn(l);
}

static __inline__ __attribute__((always_inline)) float __ll2float_rz(long long l)
{
  return __nv_ll2float_rz(l);
}

static __inline__ __attribute__((always_inline)) float __ll2float_rd(long long l)
{
  return __nv_ll2float_rd(l);
}

static __inline__ __attribute__((always_inline)) float __ll2float_ru(long long l)
{
  return __nv_ll2float_ru(l);
}


static __inline__ __attribute__((always_inline)) float __ull2float_rn(unsigned long long l)
{
  return __nv_ull2float_rn(l);
}

static __inline__ __attribute__((always_inline)) float __ull2float_rz(unsigned long long l)
{
  return __nv_ull2float_rz(l);
}

static __inline__ __attribute__((always_inline)) float __ull2float_rd(unsigned long long l)
{
  return __nv_ull2float_rd(l);
}

static __inline__ __attribute__((always_inline)) float __ull2float_ru(unsigned long long l)
{
  return __nv_ull2float_ru(l);
}


static __inline__ __attribute__((always_inline)) double __ll2double_rn(long long l)
{
  return __nv_ll2double_rn(l);
}

static __inline__ __attribute__((always_inline)) double __ll2double_rz(long long l)
{
  return __nv_ll2double_rz(l);
}

static __inline__ __attribute__((always_inline)) double __ll2double_rd(long long l)
{
  return __nv_ll2double_rd(l);
}

static __inline__ __attribute__((always_inline)) double __ll2double_ru(long long l)
{
  return __nv_ll2double_ru(l);
}


static __inline__ __attribute__((always_inline)) double __ull2double_rn(unsigned long long l)
{
  return __nv_ull2double_rn(l);
}

static __inline__ __attribute__((always_inline)) double __ull2double_rz(unsigned long long l)
{
  return __nv_ull2double_rz(l);
}

static __inline__ __attribute__((always_inline)) double __ull2double_rd(unsigned long long l)
{
  return __nv_ull2double_rd(l);
}

static __inline__ __attribute__((always_inline)) double __ull2double_ru(unsigned long long l)
{
  return __nv_ull2double_ru(l);
}

static __inline__ __attribute__((always_inline)) unsigned short __float2half_rn(float f)
{
  return __nv_float2half_rn(f);
}

static __inline__ __attribute__((always_inline)) float __half2float(unsigned short h)
{
  return __nv_half2float(h);
}

static __inline__ __attribute__((always_inline)) float __int_as_float(int x)
{
  return __nv_int_as_float(x);
}

static __inline__ __attribute__((always_inline)) int __float_as_int(float x)
{
  return __nv_float_as_int(x);
}

static __inline__ __attribute__((always_inline)) float __uint_as_float(unsigned int x)
{
  return __nv_uint_as_float(x);
}

static __inline__ __attribute__((always_inline)) unsigned int __float_as_uint(float x)
{
  return __nv_float_as_uint(x);
}

static __inline__ __attribute__((always_inline)) double __longlong_as_double(long long x)
{
  return __nv_longlong_as_double(x);
}

static __inline__ __attribute__((always_inline)) long long __double_as_longlong (double x)
{
  return __nv_double_as_longlong(x);
}







static __inline__ __attribute__((always_inline)) float __sinf(float a)
{
  return __nv_fast_sinf(a);
}

static __inline__ __attribute__((always_inline)) float __cosf(float a)
{
  return __nv_fast_cosf(a);
}

static __inline__ __attribute__((always_inline)) float __log2f(float a)
{
  return __nv_fast_log2f(a);
}







static __inline__ __attribute__((always_inline)) float __tanf(float a)
{
  return __nv_fast_tanf(a);
}

static __inline__ __attribute__((always_inline)) void __sincosf(float a, float *sptr, float *cptr)
{
  __nv_fast_sincosf(a, sptr, cptr);
}

static __inline__ __attribute__((always_inline)) float __expf(float a)
{
  return __nv_fast_expf(a);
}

static __inline__ __attribute__((always_inline)) float __exp10f(float a)
{
  return __nv_fast_exp10f(a);
}

static __inline__ __attribute__((always_inline)) float __log10f(float a)
{
  return __nv_fast_log10f(a);
}

static __inline__ __attribute__((always_inline)) float __logf(float a)
{
  return __nv_fast_logf(a);
}

static __inline__ __attribute__((always_inline)) float __powf(float a, float b)
{
  return __nv_fast_powf(a, b);
}

static __inline__ __attribute__((always_inline)) float fdividef(float a, float b)
{
  if (0 && !1) {
    return __nv_fast_fdividef(a, b);
  } else {
    return a / b;
  }
}

static __inline__ __attribute__((always_inline)) double fdivide(double a, double b)
{
  return a / b;
}

static __inline__ __attribute__((always_inline)) int __hadd(int a, int b)
{
  return __nv_hadd(a, b);
}

static __inline__ __attribute__((always_inline)) int __rhadd(int a, int b)
{
  return __nv_rhadd(a, b);
}

static __inline__ __attribute__((always_inline)) unsigned int __uhadd(unsigned int a, unsigned int b)
{
  return __nv_uhadd(a, b);
}

static __inline__ __attribute__((always_inline)) unsigned int __urhadd(unsigned int a, unsigned int b)
{
  return __nv_urhadd(a, b);
}

static __inline__ __attribute__((always_inline)) float __fsub_rn (float a, float b)
{
  return __nv_fsub_rn(a, b);
}

static __inline__ __attribute__((always_inline)) float __fsub_rz (float a, float b)
{
  return __nv_fsub_rz(a, b);
}

static __inline__ __attribute__((always_inline)) float __fsub_rd (float a, float b)
{
  return __nv_fsub_rd(a, b);
}

static __inline__ __attribute__((always_inline)) float __fsub_ru (float a, float b)
{
  return __nv_fsub_ru(a, b);
}

static __inline__ __attribute__((always_inline)) float __frsqrt_rn (float a)
{
  return __nv_frsqrt_rn(a);
}

static __inline__ __attribute__((always_inline)) int __ffs(int a)
{
  return __nv_ffs(a);
}

static __inline__ __attribute__((always_inline)) int __ffsll(long long int a)
{
  return __nv_ffsll(a);
}






static __inline__ __attribute__((always_inline))
int __iAtomicAdd(int *p, int val)
{
  return __nvvm_atom_add_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicAdd_block(int *p, int val)
{
  return __nvvm_atom_cta_add_gen_i((volatile int *)p, val);
}

static __inline__ __attribute__((always_inline))
int __iAtomicAdd_system(int *p, int val)
{
  return __nvvm_atom_sys_add_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAdd(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_add_gen_i((volatile int *)p, (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAdd_block(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_cta_add_gen_i((volatile int *)p, (int)val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAdd_system(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_sys_add_gen_i((volatile int *)p, (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAdd(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_add_gen_ll((volatile long long *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAdd_block(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_cta_add_gen_ll((volatile long long *)p, (long long)val);
}

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAdd_system(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_sys_add_gen_ll((volatile long long *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
float __fAtomicAdd(float *p, float val)
{
  return __nvvm_atom_add_gen_f((volatile float *)p, val);
}


static __inline__ __attribute__((always_inline))
float __fAtomicAdd_block(float *p, float val)
{
  return __nvvm_atom_cta_add_gen_f((volatile float *)p, val);
}

static __inline__ __attribute__((always_inline))
float __fAtomicAdd_system(float *p, float val)
{
  return __nvvm_atom_sys_add_gen_f((volatile float *)p, val);
}

static __inline__ __attribute__((always_inline))
double __dAtomicAdd(double *p, double val)
{
  return __nvvm_atom_add_gen_d((volatile double *)p, val);
}

static __inline__ __attribute__((always_inline))
double __dAtomicAdd_block(double *p, double val)
{
  return __nvvm_atom_cta_add_gen_d((volatile double *)p, val);
}

static __inline__ __attribute__((always_inline))
double __dAtomicAdd_system(double *p, double val)
{
  return __nvvm_atom_sys_add_gen_d((volatile double *)p, val);
}



static __inline__ __attribute__((always_inline))
int __iAtomicExch(int *p, int val)
{
  return __nvvm_atom_xchg_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicExch_block(int *p, int val)
{
  return __nvvm_atom_cta_xchg_gen_i((volatile int *)p, val);
}

static __inline__ __attribute__((always_inline))
int __iAtomicExch_system(int *p, int val)
{
  return __nvvm_atom_sys_xchg_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicExch(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_xchg_gen_i((volatile int *)p, (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicExch_block(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_cta_xchg_gen_i((volatile int *)p, (int)val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicExch_system(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_sys_xchg_gen_i((volatile int *)p, (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicExch(unsigned long long *p,
                                   unsigned long long val)
{
  return __nvvm_atom_xchg_gen_ll((volatile long long *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicExch_block(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_cta_xchg_gen_ll((volatile long long *)p, (long long)val);
}

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicExch_system(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_sys_xchg_gen_ll((volatile long long *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
float __fAtomicExch(float *p, float val)
{
  int old = __nvvm_atom_xchg_gen_i((volatile int *)p, __float_as_int(val));
  return __int_as_float(old);
}


static __inline__ __attribute__((always_inline))
float __fAtomicExch_block(float *p, float val)
{
  int old = __nvvm_atom_cta_xchg_gen_i((volatile int *)p, __float_as_int(val));
  return __int_as_float(old);
}

static __inline__ __attribute__((always_inline))
float __fAtomicExch_system(float *p, float val)
{
  int old = __nvvm_atom_sys_xchg_gen_i((volatile int *)p, __float_as_int(val));
  return __int_as_float(old);
}


static __inline__ __attribute__((always_inline))
int __iAtomicMin(int *p, int val)
{
  return __nvvm_atom_min_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicMin_block(int *p, int val)
{
  return __nvvm_atom_cta_min_gen_i((volatile int *)p, val);
}

static __inline__ __attribute__((always_inline))
int __iAtomicMin_system(int *p, int val)
{
  return __nvvm_atom_sys_min_gen_i((volatile int *)p, val);
}



static __inline__ __attribute__((always_inline))
long long __illAtomicMin(long long *p, long long val)
{
  return __nvvm_atom_min_gen_ll((volatile long long *)p, val);
}



static __inline__ __attribute__((always_inline))
long long __illAtomicMin_block(long long *p, long long val)
{
  return __nvvm_atom_cta_min_gen_ll((volatile long long *)p, val);
}

static __inline__ __attribute__((always_inline))
long long __illAtomicMin_system(long long *p, long long val)
{
  return __nvvm_atom_sys_min_gen_ll((volatile long long *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMin(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_min_gen_ui((volatile unsigned int *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMin_block(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_cta_min_gen_ui((volatile unsigned int *)p, val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMin_system(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_sys_min_gen_ui((volatile unsigned int *)p, val);
}



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMin(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_min_gen_ull((volatile unsigned long long *)p, val);
}



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMin_block(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_cta_min_gen_ull((volatile unsigned long long *)p, val);
}

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMin_system(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_sys_min_gen_ull((volatile unsigned long long *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicMax(int *p, int val)
{
  return __nvvm_atom_max_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicMax_block(int *p, int val)
{
  return __nvvm_atom_cta_max_gen_i((volatile int *)p, val);
}

static __inline__ __attribute__((always_inline))
int __iAtomicMax_system(int *p, int val)
{
  return __nvvm_atom_sys_max_gen_i((volatile int *)p, val);
}



static __inline__ __attribute__((always_inline))
long long __illAtomicMax(long long *p, long long val)
{
  return __nvvm_atom_max_gen_ll((volatile long long *)p, val);
}



static __inline__ __attribute__((always_inline))
long long __illAtomicMax_block(long long *p, long long val)
{
  return __nvvm_atom_cta_max_gen_ll((volatile long long *)p, val);
}

static __inline__ __attribute__((always_inline))
long long __illAtomicMax_system(long long *p, long long val)
{
  return __nvvm_atom_sys_max_gen_ll((volatile long long *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMax(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_max_gen_ui((unsigned int *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMax_block(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_cta_max_gen_ui((volatile unsigned int *)p, val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicMax_system(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_sys_max_gen_ui((volatile unsigned int *)p, val);
}



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMax(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_max_gen_ull((volatile unsigned long long *)p, val);
}



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMax_block(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_cta_max_gen_ull((volatile unsigned long long *)p, val);
}

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicMax_system(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_sys_max_gen_ull((volatile unsigned long long *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicInc(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_inc_gen_ui((unsigned int *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicInc_block(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_cta_inc_gen_ui((volatile unsigned int *)p, val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicInc_system(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_sys_inc_gen_ui((volatile unsigned int *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicDec(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_dec_gen_ui((unsigned int *)p, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicDec_block(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_cta_dec_gen_ui((volatile unsigned int *)p, val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicDec_system(unsigned int *p, unsigned int val)
{
  return __nvvm_atom_sys_dec_gen_ui((volatile unsigned int *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicCAS(int *p, int compare, int val)
{
  return __nvvm_atom_cas_gen_i((int *)p, compare, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicCAS_block(int *p, int compare, int val)
{
  return __nvvm_atom_cta_cas_gen_i((int *)p, compare, val);
}

static __inline__ __attribute__((always_inline))
int __iAtomicCAS_system(int *p, int compare, int val)
{
  return __nvvm_atom_sys_cas_gen_i((int *)p, compare, val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicCAS(unsigned int *p, unsigned int compare,
                          unsigned int val)
{
  return (unsigned int)__nvvm_atom_cas_gen_i((volatile int *)p,
                                             (int)compare,
                                             (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicCAS_block(unsigned int *p, unsigned int compare,
                                unsigned int val)
{
  return (unsigned int)__nvvm_atom_cta_cas_gen_i((volatile int *)p,
                                                 (int)compare,
                                                 (int)val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicCAS_system(unsigned int *p, unsigned int compare,
                                 unsigned int val)
{
  return (unsigned int)__nvvm_atom_sys_cas_gen_i((volatile int *)p,
                                                 (int)compare,
                                                 (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicCAS(unsigned long long int *p,
                                      unsigned long long int compare,
                                      unsigned long long int val)
{
  return
    (unsigned long long int)__nvvm_atom_cas_gen_ll((volatile long long int *)p,
                                                   (long long int)compare,
                                                   (long long int)val);
}


static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicCAS_block(unsigned long long int *p,
                                            unsigned long long int compare,
                                            unsigned long long int val)
{
  return
    (unsigned long long int)__nvvm_atom_cta_cas_gen_ll((volatile long long int *)p,
                                                       (long long int)compare,
                                                       (long long int)val);
}

static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicCAS_system(unsigned long long int *p,
                                             unsigned long long int compare,
                                             unsigned long long int val)
{
  return
    (unsigned long long int)__nvvm_atom_sys_cas_gen_ll((volatile long long int *)p,
                                                       (long long int)compare,
                                                       (long long int)val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicAnd(int *p, int val)
{
  return __nvvm_atom_and_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicAnd_block(int *p, int val)
{
  return __nvvm_atom_cta_and_gen_i((volatile int *)p, val);
}

static __inline__ __attribute__((always_inline))
int __iAtomicAnd_system(int *p, int val)
{
  return __nvvm_atom_sys_and_gen_i((volatile int *)p, val);
}



static __inline__ __attribute__((always_inline))
long long int __llAtomicAnd(long long int *p, long long int val)
{
  return __nvvm_atom_and_gen_ll((volatile long long int *)p, (long long)val);
}



static __inline__ __attribute__((always_inline))
long long int __llAtomicAnd_block(long long int *p, long long int val)
{
  return __nvvm_atom_cta_and_gen_ll((volatile long long int *)p, (long long)val);
}

static __inline__ __attribute__((always_inline))
long long int __llAtomicAnd_system(long long int *p, long long int val)
{
  return __nvvm_atom_sys_and_gen_ll((volatile long long int *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAnd(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_and_gen_i((volatile int *)p, (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAnd_block(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_cta_and_gen_i((volatile int *)p, (int)val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicAnd_system(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_sys_and_gen_i((volatile int *)p, (int)val);
}



static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicAnd(unsigned long long int *p,
                                      unsigned long long int val)
{
  return __nvvm_atom_and_gen_ll((volatile long long int *)p, (long long)val);
}



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAnd_block(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_cta_and_gen_ll((volatile long long *)p, (long long)val);
}

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicAnd_system(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_sys_and_gen_ll((volatile long long *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicOr(int *p, int val)
{
  return __nvvm_atom_or_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicOr_block(int *p, int val)
{
  return __nvvm_atom_cta_or_gen_i((volatile int *)p, val);
}

static __inline__ __attribute__((always_inline))
int __iAtomicOr_system(int *p, int val)
{
  return __nvvm_atom_sys_or_gen_i((volatile int *)p, val);
}



static __inline__ __attribute__((always_inline))
long long int __llAtomicOr(long long int *p, long long int val)
{
  return __nvvm_atom_or_gen_ll((volatile long long int *)p, (long long)val);
}



static __inline__ __attribute__((always_inline))
long long int __llAtomicOr_block(long long int *p, long long int val)
{
  return __nvvm_atom_cta_or_gen_ll((volatile long long int *)p, (long long)val);
}

static __inline__ __attribute__((always_inline))
long long int __llAtomicOr_system(long long int *p, long long int val)
{
  return __nvvm_atom_sys_or_gen_ll((volatile long long int *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicOr(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_or_gen_i((volatile int *)p, (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicOr_block(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_cta_or_gen_i((volatile int *)p, (int)val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicOr_system(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_sys_or_gen_i((volatile int *)p, (int)val);
}



static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicOr(unsigned long long int *p,
                                     unsigned long long int val)
{
  return __nvvm_atom_or_gen_ll((volatile long long int *)p, (long long)val);
}



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicOr_block(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_cta_or_gen_ll((volatile long long *)p, (long long)val);
}

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicOr_system(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_sys_or_gen_ll((volatile long long *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicXor(int *p, int val)
{
  return __nvvm_atom_xor_gen_i((volatile int *)p, val);
}


static __inline__ __attribute__((always_inline))
int __iAtomicXor_block(int *p, int val)
{
  return __nvvm_atom_cta_xor_gen_i((volatile int *)p, val);
}

static __inline__ __attribute__((always_inline))
int __iAtomicXor_system(int *p, int val)
{
  return __nvvm_atom_sys_xor_gen_i((volatile int *)p, val);
}



static __inline__ __attribute__((always_inline))
long long int __llAtomicXor(long long int *p, long long int val)
{
  return __nvvm_atom_xor_gen_ll((volatile long long int *)p, (long long)val);
}



static __inline__ __attribute__((always_inline))
long long int __llAtomicXor_block(long long int *p, long long int val)
{
  return __nvvm_atom_cta_xor_gen_ll((volatile long long int *)p, (long long)val);
}

static __inline__ __attribute__((always_inline))
long long int __llAtomicXor_system(long long int *p, long long int val)
{
  return __nvvm_atom_sys_xor_gen_ll((volatile long long int *)p, (long long)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicXor(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_xor_gen_i((volatile int *)p, (int)val);
}


static __inline__ __attribute__((always_inline))
unsigned int __uAtomicXor_block(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_cta_xor_gen_i((volatile int *)p, (int)val);
}

static __inline__ __attribute__((always_inline))
unsigned int __uAtomicXor_system(unsigned int *p, unsigned int val)
{
  return (unsigned int)__nvvm_atom_sys_xor_gen_i((volatile int *)p, (int)val);
}



static __inline__ __attribute__((always_inline))
unsigned long long int __ullAtomicXor(unsigned long long int *p,
                                      unsigned long long int val)
{
  return __nvvm_atom_xor_gen_ll((volatile long long int *)p, (long long)val);
}



static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicXor_block(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_cta_xor_gen_ll((volatile long long *)p, (long long)val);
}

static __inline__ __attribute__((always_inline))
unsigned long long __ullAtomicXor_system(unsigned long long *p, unsigned long long val)
{
  return __nvvm_atom_sys_xor_gen_ll((volatile long long *)p, (long long)val);
}
# 2277 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
static __inline__ __attribute__((always_inline)) unsigned int __vabs2(unsigned int a)
{
    unsigned int r;




    asm ("{                       \n\t"
         ".reg .u32 a,m,r;        \n\t"
         "mov.b32  a,%1;          \n\t"
         "prmt.b32 m,a,0,0xbb99;  \n\t"
         "xor.b32  r,a,m;         \n\t"
         "and.b32  m,m,0x00010001;\n\t"
         "add.u32  r,r,m;         \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vabsss2(unsigned int a)
{
    unsigned int r;




    asm ("{                       \n\t"
         ".reg .u32 a,m,r;        \n\t"
         "mov.b32  a,%1;          \n\t"
         "prmt.b32 m,a,0,0xbb99;  \n\t"
         "xor.b32  r,a,m;         \n\t"
         "and.b32  m,m,0x00010001;\n\t"
         "add.u32  r,r,m;         \n\t"
         "prmt.b32 m,r,0,0xbb99;  \n\t"
         "and.b32  m,m,0x00010001;\n\t"
         "sub.u32  r,r,m;         \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vadd2(unsigned int a, unsigned int b)
{
    unsigned int s, t;




    s = a ^ b;
    t = a + b;
    s = s ^ t;
    s = s & 0x00010000;
    t = t - s;

    return t;
}

static __inline__ __attribute__((always_inline)) unsigned int __vaddss2 (unsigned int a, unsigned int b)
{
    unsigned int r;




    int ahi, alo, blo, bhi, rhi, rlo;
    ahi = (int)((a & 0xffff0000U));
    bhi = (int)((b & 0xffff0000U));

    alo = (int)(a << 16);
    blo = (int)(b << 16);




    asm ("add.sat.s32 %0,%1,%2;" : "=r"(rlo) : "r"(alo), "r"(blo));
    asm ("add.sat.s32 %0,%1,%2;" : "=r"(rhi) : "r"(ahi), "r"(bhi));
    asm ("prmt.b32 %0,%1,%2,0x7632;" : "=r"(r) : "r"(rlo), "r"(rhi));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vaddus2 (unsigned int a, unsigned int b)
{
    unsigned int r;




    int alo, blo, rlo, ahi, bhi, rhi;
    asm ("{                              \n\t"
         "and.b32     %0, %4, 0xffff;    \n\t"
         "and.b32     %1, %5, 0xffff;    \n\t"

         "shr.u32     %2, %4, 16;        \n\t"
         "shr.u32     %3, %5, 16;        \n\t"




         "}"
         : "=r"(alo), "=r"(blo), "=r"(ahi), "=r"(bhi)
         : "r"(a), "r"(b));
    rlo = min (alo + blo, 65535);
    rhi = min (ahi + bhi, 65535);
    r = (rhi << 16) + rlo;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vavgs2(unsigned int a, unsigned int b)
{
    unsigned int r;
# 2407 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    asm ("{                      \n\t"
         ".reg .u32 a,b,c,r,s,t,u,v;\n\t"
         "mov.b32 a,%1;          \n\t"
         "mov.b32 b,%2;          \n\t"
         "and.b32 u,a,0xfffefffe;\n\t"
         "and.b32 v,b,0xfffefffe;\n\t"
         "xor.b32 s,a,b;         \n\t"
         "and.b32 t,a,b;         \n\t"
         "shr.u32 u,u,1;         \n\t"
         "shr.u32 v,v,1;         \n\t"
         "and.b32 c,s,0x00010001;\n\t"
         "and.b32 s,s,0x80008000;\n\t"
         "and.b32 t,t,0x00010001;\n\t"
         "add.u32 r,u,v;         \n\t"
         "add.u32 r,r,t;         \n\t"
         "xor.b32 r,r,s;         \n\t"
         "shr.u32 t,r,15;        \n\t"
         "not.b32 t,t;           \n\t"
         "and.b32 t,t,c;         \n\t"
         "add.u32 r,r,t;         \n\t"
         "mov.b32 %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vavgu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    c = a ^ b;
    r = a | b;
    c = c & 0xfffefffe;
    c = c >> 1;
    r = r - c;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vhaddu2(unsigned int a, unsigned int b)
{


    unsigned int r, s;
    s = a ^ b;
    r = a & b;
    s = s & 0xfffefffe;
    s = s >> 1;
    r = r + s;
    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpeq2(unsigned int a, unsigned int b)
{
    unsigned int r, c;
# 2476 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    r = a ^ b;
    c = r | 0x80008000;
    r = r ^ c;
    c = c - 0x00010001;
    c = r & ~c;
    asm ("prmt.b32 %0,%1,0,0xbb99;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpges2(unsigned int a, unsigned int b)
{
    unsigned int r;






    asm ("{                             \n\t"
         ".reg .u32 a, b, r, s, t, u;   \n\t"
         "mov.b32        a,%1;          \n\t"
         "mov.b32        b,%2;          \n\t"
         "and.b32        s,a,0xffff0000;\n\t"
         "and.b32        t,b,0xffff0000;\n\t"
         "set.ge.s32.s32 u,s,t;         \n\t"
         "cvt.s32.s16    s,a;           \n\t"
         "cvt.s32.s16    t,b;           \n\t"
         "set.ge.s32.s32 s,s,t;         \n\t"
         "prmt.b32       r,s,u,0x7632;  \n\t"
         "mov.b32        %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgeu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    asm ("not.b32 %0,%0;" : "+r"(b));
    c = __vavgu2 (a, b);
    asm ("prmt.b32 %0,%1,0,0xbb99;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgts2(unsigned int a, unsigned int b)
{
    unsigned int r;






    asm ("{                             \n\t"
         ".reg .u32 a, b, r, s, t, u;   \n\t"
         "mov.b32        a,%1;          \n\t"
         "mov.b32        b,%2;          \n\t"
         "and.b32        s,a,0xffff0000;\n\t"
         "and.b32        t,b,0xffff0000;\n\t"
         "set.gt.s32.s32 u,s,t;         \n\t"
         "cvt.s32.s16    s,a;           \n\t"
         "cvt.s32.s16    t,b;           \n\t"
         "set.gt.s32.s32 s,s,t;         \n\t"
         "prmt.b32       r,s,u,0x7632;  \n\t"
         "mov.b32        %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgtu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    asm ("not.b32 %0,%0;" : "+r"(b));
    c = __vhaddu2 (a, b);
    asm ("prmt.b32 %0,%1,0,0xbb99;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmples2(unsigned int a, unsigned int b)
{
    unsigned int r;






    asm ("{                             \n\t"
         ".reg .u32 a, b, r, s, t, u;   \n\t"
         "mov.b32        a,%1;          \n\t"
         "mov.b32        b,%2;          \n\t"
         "and.b32        s,a,0xffff0000;\n\t"
         "and.b32        t,b,0xffff0000;\n\t"
         "set.le.s32.s32 u,s,t;         \n\t"
         "cvt.s32.s16    s,a;           \n\t"
         "cvt.s32.s16    t,b;           \n\t"
         "set.le.s32.s32 s,s,t;         \n\t"
         "prmt.b32       r,s,u,0x7632;  \n\t"
         "mov.b32        %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpleu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    asm ("not.b32 %0,%0;" : "+r"(a));
    c = __vavgu2 (a, b);
    asm ("prmt.b32 %0,%1,0,0xbb99;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmplts2(unsigned int a, unsigned int b)
{
    unsigned int r;






    asm ("{                             \n\t"
         ".reg .u32 a, b, r, s, t, u;   \n\t"
         "mov.b32        a,%1;          \n\t"
         "mov.b32        b,%2;          \n\t"
         "and.b32        s,a,0xffff0000;\n\t"
         "and.b32        t,b,0xffff0000;\n\t"
         "set.lt.s32.s32 u,s,t;         \n\t"
         "cvt.s32.s16    s,a;           \n\t"
         "cvt.s32.s16    t,b;           \n\t"
         "set.lt.s32.s32 s,s,t;         \n\t"
         "prmt.b32       r,s,u,0x7632;  \n\t"
         "mov.b32        %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpltu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    asm ("not.b32 %0,%0;" : "+r"(a));
    c = __vhaddu2 (a, b);
    asm ("prmt.b32 %0,%1,0,0xbb99;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpne2(unsigned int a, unsigned int b)
{
    unsigned int r, c;
# 2669 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    r = a ^ b;
    c = r | 0x80008000;
    c = c - 0x00010001;
    c = r | c;
    asm ("prmt.b32 %0,%1,0,0xbb99;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vabsdiffu2(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    unsigned int t, u, v;
    s = a & 0x0000ffff;
    r = b & 0x0000ffff;
    u = umax (r, s);
    v = umin (r, s);
    s = a & 0xffff0000;
    r = b & 0xffff0000;
    t = umax (r, s);
    s = umin (r, s);
    r = u | t;
    s = v | s;
    r = r - s;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vmaxs2(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    unsigned int t, u;
    asm ("cvt.s32.s16 %0,%1;" : "=r"(r) : "r"(a));
    asm ("cvt.s32.s16 %0,%1;" : "=r"(s) : "r"(b));
    t = max((int)r,(int)s);
    r = a & 0xffff0000;
    s = b & 0xffff0000;
    u = max((int)r,(int)s);
    r = u | (t & 0xffff);

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vmaxu2(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    unsigned int t, u;
    r = a & 0x0000ffff;
    s = b & 0x0000ffff;
    t = umax (r, s);
    r = a & 0xffff0000;
    s = b & 0xffff0000;
    u = umax (r, s);
    r = t | u;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vmins2(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    unsigned int t, u;
    asm ("cvt.s32.s16 %0,%1;" : "=r"(r) : "r"(a));
    asm ("cvt.s32.s16 %0,%1;" : "=r"(s) : "r"(b));
    t = min((int)r,(int)s);
    r = a & 0xffff0000;
    s = b & 0xffff0000;
    u = min((int)r,(int)s);
    r = u | (t & 0xffff);

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vminu2(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    unsigned int t, u;
    r = a & 0x0000ffff;
    s = b & 0x0000ffff;
    t = umin (r, s);
    r = a & 0xffff0000;
    s = b & 0xffff0000;
    u = umin (r, s);
    r = t | u;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vseteq2(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    r = a ^ b;
    c = r | 0x80008000;
    r = r ^ c;
    c = c - 0x00010001;
    c = r & ~c;
    r = c >> 15;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetges2(unsigned int a, unsigned int b)
{
    unsigned int r;




    asm ("{                             \n\t"
         ".reg .u32 a, b, r, s, t, u;   \n\t"
         "mov.b32        a,%1;          \n\t"
         "mov.b32        b,%2;          \n\t"
         "and.b32        s,a,0xffff0000;\n\t"
         "and.b32        t,b,0xffff0000;\n\t"
         "set.ge.s32.s32 u,s,t;         \n\t"
         "cvt.s32.s16    s,a;           \n\t"
         "cvt.s32.s16    t,b;           \n\t"
         "set.ge.s32.s32 s,s,t;         \n\t"
         "prmt.b32       r,s,u,0x7632;  \n\t"
         "and.b32        r,r,0x00010001;\n\t"
         "mov.b32        %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetgeu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;




    asm ("not.b32 %0,%0;" : "+r"(b));
    c = __vavgu2 (a, b);
    c = c & 0x80008000;
    r = c >> 15;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetgts2(unsigned int a, unsigned int b)
{
    unsigned int r;




    asm ("{                             \n\t"
         ".reg .u32 a, b, r, s, t, u;   \n\t"
         "mov.b32        a,%1;          \n\t"
         "mov.b32        b,%2;          \n\t"
         "and.b32        s,a,0xffff0000;\n\t"
         "and.b32        t,b,0xffff0000;\n\t"
         "set.gt.s32.s32 u,s,t;         \n\t"
         "cvt.s32.s16    s,a;           \n\t"
         "cvt.s32.s16    t,b;           \n\t"
         "set.gt.s32.s32 s,s,t;         \n\t"
         "prmt.b32       r,s,u,0x7632;  \n\t"
         "and.b32        r,r,0x00010001;\n\t"
         "mov.b32        %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetgtu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;




    asm ("not.b32 %0,%0;" : "+r"(b));
    c = __vhaddu2 (a, b);
    c = c & 0x80008000;
    r = c >> 15;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetles2(unsigned int a, unsigned int b)
{
    unsigned int r;




    asm ("{                             \n\t"
         ".reg .u32 a, b, r, s, t, u;   \n\t"
         "mov.b32        a,%1;          \n\t"
         "mov.b32        b,%2;          \n\t"
         "and.b32        s,a,0xffff0000;\n\t"
         "and.b32        t,b,0xffff0000;\n\t"
         "set.le.s32.s32 u,s,t;         \n\t"
         "cvt.s32.s16    s,a;           \n\t"
         "cvt.s32.s16    t,b;           \n\t"
         "set.le.s32.s32 s,s,t;         \n\t"
         "prmt.b32       r,s,u,0x7632;  \n\t"
         "and.b32        r,r,0x00010001;\n\t"
         "mov.b32        %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetleu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;




    asm ("not.b32 %0,%0;" : "+r"(a));
    c = __vavgu2 (a, b);
    c = c & 0x80008000;
    r = c >> 15;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetlts2(unsigned int a, unsigned int b)
{
    unsigned int r;




    asm ("{                             \n\t"
         ".reg .u32 a, b, r, s, t, u;   \n\t"
         "mov.b32        a,%1;          \n\t"
         "mov.b32        b,%2;          \n\t"
         "and.b32        s,a,0xffff0000;\n\t"
         "and.b32        t,b,0xffff0000;\n\t"
         "set.lt.s32.s32 u,s,t;         \n\t"
         "cvt.s32.s16    s,a;           \n\t"
         "cvt.s32.s16    t,b;           \n\t"
         "set.lt.s32.s32 s,s,t;         \n\t"
         "prmt.b32       r,s,u,0x7632;  \n\t"
         "and.b32        r,r,0x00010001;\n\t"
         "mov.b32        %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetltu2(unsigned int a, unsigned int b)
{
    unsigned int r, c;




    asm ("not.b32 %0,%0;" : "+r"(a));
    c = __vhaddu2 (a, b);
    c = c & 0x80008000;
    r = c >> 15;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetne2(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    r = a ^ b;
    c = r | 0x80008000;
    c = c - 0x00010001;
    c = r | c;
    c = c & 0x80008000;
    r = c >> 15;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsadu2(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    unsigned int t, u, v;
    s = a & 0x0000ffff;
    r = b & 0x0000ffff;
    u = umax (r, s);
    v = umin (r, s);
    s = a & 0xffff0000;
    r = b & 0xffff0000;
    t = umax (r, s);
    s = umin (r, s);
    u = u - v;
    t = t - s;

    asm ("shr.u32 %0,%0,16;" : "+r"(t));



    r = t + u;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsub2(unsigned int a, unsigned int b)
{
    unsigned int s, t;




    s = a ^ b;
    t = a - b;
    s = s ^ t;
    s = s & 0x00010000;
    t = t + s;

    return t;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsubss2 (unsigned int a, unsigned int b)
{
    unsigned int r;




    int ahi, alo, blo, bhi, rhi, rlo;
    ahi = (int)((a & 0xffff0000U));
    bhi = (int)((b & 0xffff0000U));

    asm ("prmt.b32 %0,%1,0,0x1044;" : "=r"(alo) : "r"(a));
    asm ("prmt.b32 %0,%1,0,0x1044;" : "=r"(blo) : "r"(b));




    asm ("sub.sat.s32 %0,%1,%2;" : "=r"(rlo) : "r"(alo), "r"(blo));
    asm ("sub.sat.s32 %0,%1,%2;" : "=r"(rhi) : "r"(ahi), "r"(bhi));
    asm ("prmt.b32 %0,%1,%2,0x7632;" : "=r"(r) : "r"(rlo), "r"(rhi));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsubus2 (unsigned int a, unsigned int b)
{
    unsigned int r;




    int alo, blo, rlo, ahi, bhi, rhi;
    asm ("{                              \n\t"
         "and.b32     %0, %4, 0xffff;    \n\t"
         "and.b32     %1, %5, 0xffff;    \n\t"

         "shr.u32     %2, %4, 16;        \n\t"
         "shr.u32     %3, %5, 16;        \n\t"




         "}"
         : "=r"(alo), "=r"(blo), "=r"(ahi), "=r"(bhi)
         : "r"(a), "r"(b));
    rlo = max ((int)(alo - blo), 0);
    rhi = max ((int)(ahi - bhi), 0);
    r = rhi * 65536 + rlo;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vneg2(unsigned int a)
{
    return __vsub2 (0, a);
}

static __inline__ __attribute__((always_inline)) unsigned int __vnegss2(unsigned int a)
{
    return __vsubss2(0,a);
}

static __inline__ __attribute__((always_inline)) unsigned int __vabsdiffs2(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    s = __vcmpges2 (a, b);
    r = a ^ b;
    s = (r & s) ^ b;
    r = s ^ r;
    r = __vsub2 (s, r);

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsads2(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    s = __vabsdiffs2 (a, b);
    r = (s >> 16) + (s & 0x0000ffff);

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vabs4(unsigned int a)
{
    unsigned int r;




    asm ("{                       \n\t"
         ".reg .u32 a,m,r;        \n\t"
         "mov.b32  a,%1;          \n\t"
         "prmt.b32 m,a,0,0xba98;  \n\t"
         "xor.b32  r,a,m;         \n\t"
         "and.b32  m,m,0x01010101;\n\t"
         "add.u32  r,r,m;         \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vabsss4(unsigned int a)
{
    unsigned int r;




    asm ("{                       \n\t"
         ".reg .u32 a,m,r;        \n\t"
         "mov.b32  a,%1;          \n\t"
         "prmt.b32 m,a,0,0xba98;  \n\t"
         "xor.b32  r,a,m;         \n\t"
         "and.b32  m,m,0x01010101;\n\t"
         "add.u32  r,r,m;         \n\t"
         "prmt.b32 m,r,0,0xba98;  \n\t"
         "and.b32  m,m,0x01010101;\n\t"
         "sub.u32  r,r,m;         \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vadd4(unsigned int a, unsigned int b)
{




    unsigned int r, s, t;
    s = a ^ b;
    r = a & 0x7f7f7f7f;
    t = b & 0x7f7f7f7f;
    s = s & 0x80808080;
    r = r + t;
    r = r ^ s;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vaddss4 (unsigned int a, unsigned int b)
{
# 3214 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    unsigned int r;
    asm ("{                         \n\t"
         ".reg .u32 a,b,r,s,t,u;    \n\t"
         "mov.b32  a, %1;           \n\t"
         "mov.b32  b, %2;           \n\t"
         "and.b32  r, a, 0x7f7f7f7f;\n\t"
         "and.b32  t, b, 0x7f7f7f7f;\n\t"
         "xor.b32  s, a, b;         \n\t"
         "add.u32  r, r, t;         \n\t"
         "xor.b32  t, a, r;         \n\t"
         "not.b32  u, s;            \n\t"
         "and.b32  t, t, u;         \n\t"
         "and.b32  s, s, 0x80808080;\n\t"
         "xor.b32  r, r, s;         \n\t"
         "prmt.b32 s,a,0,0xba98;    \n\t"
         "xor.b32  s,s,0x7f7f7f7f;  \n\t"
         "prmt.b32 t,t,0,0xba98;    \n\t"
         "and.b32  s,s,t;           \n\t"
         "not.b32  t,t;             \n\t"
         "and.b32  r,r,t;           \n\t"
         "or.b32   r,r,s;           \n\t"
         "mov.b32  %0, r;           \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vaddus4 (unsigned int a, unsigned int b)
{
# 3279 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    unsigned int r;
    asm ("{                         \n\t"
         ".reg .u32 a,b,r,s,t,m;    \n\t"
         "mov.b32  a, %1;           \n\t"
         "mov.b32  b, %2;           \n\t"
         "or.b32   m, a, b;         \n\t"
         "and.b32  r, a, 0x7f7f7f7f;\n\t"
         "and.b32  t, b, 0x7f7f7f7f;\n\t"
         "and.b32  m, m, 0x80808080;\n\t"
         "add.u32  r, r, t;         \n\t"
         "and.b32  t, a, b;         \n\t"
         "or.b32   t, t, r;         \n\t"
         "or.b32   r, r, m;         \n\t"
         "and.b32  t, t, m;         \n\t"
         "prmt.b32 t, t, 0, 0xba98; \n\t"
         "or.b32   r, r, t;         \n\t"
         "mov.b32  %0, r;           \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vavgs4(unsigned int a, unsigned int b)
{
    unsigned int r;
# 3319 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    asm ("{                      \n\t"
         ".reg .u32 a,b,c,r,s,t,u,v;\n\t"
         "mov.b32 a,%1;          \n\t"
         "mov.b32 b,%2;          \n\t"
         "and.b32 u,a,0xfefefefe;\n\t"
         "and.b32 v,b,0xfefefefe;\n\t"
         "xor.b32 s,a,b;         \n\t"
         "and.b32 t,a,b;         \n\t"
         "shr.u32 u,u,1;         \n\t"
         "shr.u32 v,v,1;         \n\t"
         "and.b32 c,s,0x01010101;\n\t"
         "and.b32 s,s,0x80808080;\n\t"
         "and.b32 t,t,0x01010101;\n\t"
         "add.u32 r,u,v;         \n\t"
         "add.u32 r,r,t;         \n\t"
         "xor.b32 r,r,s;         \n\t"
         "shr.u32 t,r,7;         \n\t"
         "not.b32 t,t;           \n\t"
         "and.b32 t,t,c;         \n\t"
         "add.u32 r,r,t;         \n\t"
         "mov.b32 %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vavgu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    c = a ^ b;
    r = a | b;
    c = c & 0xfefefefe;
    c = c >> 1;
    r = r - c;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vhaddu4(unsigned int a, unsigned int b)
{


    unsigned int r, s;
    s = a ^ b;
    r = a & b;
    s = s & 0xfefefefe;
    s = s >> 1;
    s = r + s;
    return s;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpeq4(unsigned int a, unsigned int b)
{
    unsigned int c, r;
# 3388 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    r = a ^ b;
    c = r | 0x80808080;
    r = r ^ c;
    c = c - 0x01010101;
    c = r & ~c;
    asm ("prmt.b32 %0,%1,0,0xba98;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpges4(unsigned int a, unsigned int b)
{
    unsigned int r;






    asm ("{                          \n\t"
         ".reg .u32 a, b, r, s, t, u;\n\t"
         "mov.b32     a,%1;          \n\t"
         "mov.b32     b,%2;          \n\t"
         "xor.b32     s,a,b;         \n\t"
         "or.b32      r,a,0x80808080;\n\t"
         "and.b32     t,b,0x7f7f7f7f;\n\t"
         "sub.u32     r,r,t;         \n\t"
         "xor.b32     t,r,a;         \n\t"
         "xor.b32     r,r,s;         \n\t"
         "and.b32     t,t,s;         \n\t"
         "xor.b32     t,t,r;         \n\t"
         "prmt.b32    r,t,0,0xba98;  \n\t"
         "mov.b32     %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgeu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    asm ("not.b32 %0,%0;" : "+r"(b));
    c = __vavgu4 (a, b);
    asm ("prmt.b32 %0,%1,0,0xba98;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgts4(unsigned int a, unsigned int b)
{
    unsigned int r;







    asm ("{                       \n\t"
         ".reg .u32 a,b,r,s,t,u;  \n\t"
         "mov.b32  a,%1;          \n\t"
         "mov.b32  b,%2;          \n\t"
         "not.b32  b,b;           \n\t"
         "and.b32  r,a,0x7f7f7f7f;\n\t"
         "and.b32  t,b,0x7f7f7f7f;\n\t"
         "xor.b32  s,a,b;         \n\t"
         "add.u32  r,r,t;         \n\t"
         "xor.b32  t,a,r;         \n\t"
         "not.b32  u,s;           \n\t"
         "and.b32  t,t,u;         \n\t"
         "xor.b32  r,r,u;         \n\t"
         "xor.b32  t,t,r;         \n\t"
         "prmt.b32 r,t,0,0xba98;  \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpgtu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    asm ("not.b32 %0,%0;" : "+r"(b));
    c = __vhaddu4 (a, b);
    asm ("prmt.b32 %0,%1,0,0xba98;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmples4(unsigned int a, unsigned int b)
{
    unsigned int r;







    asm ("{                       \n\t"
         ".reg .u32 a,b,r,s,t,u;  \n\t"
         "mov.b32  a,%1;          \n\t"
         "mov.b32  b,%2;          \n\t"
         "not.b32  u,b;           \n\t"
         "and.b32  r,a,0x7f7f7f7f;\n\t"
         "and.b32  t,u,0x7f7f7f7f;\n\t"
         "xor.b32  u,a,b;         \n\t"
         "add.u32  r,r,t;         \n\t"
         "xor.b32  t,a,r;         \n\t"
         "not.b32  s,u;           \n\t"
         "and.b32  t,t,u;         \n\t"
         "xor.b32  r,r,s;         \n\t"
         "xor.b32  t,t,r;         \n\t"
         "prmt.b32 r,t,0,0xba98;  \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpleu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    asm ("not.b32 %0,%0;" : "+r"(a));
    c = __vavgu4 (a, b);
    asm ("prmt.b32 %0,%1,0,0xba98;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmplts4(unsigned int a, unsigned int b)
{
    unsigned int r;






    asm ("{                          \n\t"
         ".reg .u32 a, b, r, s, t, u;\n\t"
         "mov.b32     a,%1;          \n\t"
         "mov.b32     b,%2;          \n\t"
         "not.b32     u,b;           \n\t"
         "xor.b32     s,u,a;         \n\t"
         "or.b32      r,a,0x80808080;\n\t"
         "and.b32     t,b,0x7f7f7f7f;\n\t"
         "sub.u32     r,r,t;         \n\t"
         "xor.b32     t,r,a;         \n\t"
         "not.b32     u,s;           \n\t"
         "xor.b32     r,r,s;         \n\t"
         "and.b32     t,t,u;         \n\t"
         "xor.b32     t,t,r;         \n\t"
         "prmt.b32    r,t,0,0xba98;  \n\t"
         "mov.b32     %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpltu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    asm ("not.b32 %0,%0;" : "+r"(a));
    c = __vhaddu4 (a, b);
    asm ("prmt.b32 %0,%1,0,0xba98;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vcmpne4(unsigned int a, unsigned int b)
{
    unsigned int r, c;
# 3597 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    r = a ^ b;
    c = r | 0x80808080;
    c = c - 0x01010101;
    c = r | c;
    asm ("prmt.b32 %0,%1,0,0xba98;" : "=r"(r) : "r"(c));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vabsdiffu4(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    s = __vcmpgeu4 (a, b);
    r = a ^ b;
    s = (r & s) ^ b;
    r = s ^ r;
    r = s - r;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vmaxs4(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    s = __vcmpges4 (a, b);
    r = a & s;
    s = b & ~s;
    r = r | s;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vmaxu4(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    s = __vcmpgeu4 (a, b);
    r = a & s;
    s = b & ~s;
    r = r | s;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vmins4(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    s = __vcmpges4 (b, a);
    r = a & s;
    s = b & ~s;
    r = r | s;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vminu4(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    s = __vcmpgeu4 (b, a);
    r = a & s;
    s = b & ~s;
    r = r | s;

    return r;
}
static __inline__ __attribute__((always_inline)) unsigned int __vseteq4(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    r = a ^ b;
    c = r | 0x80808080;
    r = r ^ c;
    c = c - 0x01010101;
    c = r & ~c;
    r = c >> 7;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetles4(unsigned int a, unsigned int b)
{
    unsigned int r;





    asm ("{                       \n\t"
         ".reg .u32 a,b,r,s,t,u;  \n\t"
         "mov.b32  a,%1;          \n\t"
         "mov.b32  b,%2;          \n\t"
         "not.b32  u,b;           \n\t"
         "and.b32  r,a,0x7f7f7f7f;\n\t"
         "and.b32  t,u,0x7f7f7f7f;\n\t"
         "xor.b32  u,a,b;         \n\t"
         "add.u32  r,r,t;         \n\t"
         "xor.b32  t,a,r;         \n\t"
         "not.b32  s,u;           \n\t"
         "and.b32  t,t,u;         \n\t"
         "xor.b32  r,r,s;         \n\t"
         "xor.b32  t,t,r;         \n\t"
         "and.b32  t,t,0x80808080;\n\t"
         "shr.u32  r,t,7;         \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetleu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;




    asm ("not.b32 %0,%0;" : "+r"(a));
    c = __vavgu4 (a, b);
    c = c & 0x80808080;
    r = c >> 7;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetlts4(unsigned int a, unsigned int b)
{
    unsigned int r;




    asm ("{                          \n\t"
         ".reg .u32 a, b, r, s, t, u;\n\t"
         "mov.b32     a,%1;          \n\t"
         "mov.b32     b,%2;          \n\t"
         "not.b32     u,b;           \n\t"
         "or.b32      r,a,0x80808080;\n\t"
         "and.b32     t,b,0x7f7f7f7f;\n\t"
         "xor.b32     s,u,a;         \n\t"
         "sub.u32     r,r,t;         \n\t"
         "xor.b32     t,r,a;         \n\t"
         "not.b32     u,s;           \n\t"
         "xor.b32     r,r,s;         \n\t"
         "and.b32     t,t,u;         \n\t"
         "xor.b32     t,t,r;         \n\t"
         "and.b32     t,t,0x80808080;\n\t"
         "shr.u32     r,t,7;         \n\t"
         "mov.b32     %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetltu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;




    asm ("not.b32 %0,%0;" : "+r"(a));
    c = __vhaddu4 (a, b);
    c = c & 0x80808080;
    r = c >> 7;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetges4(unsigned int a, unsigned int b)
{
    unsigned int r;




    asm ("{                          \n\t"
         ".reg .u32 a, b, r, s, t, u;\n\t"
         "mov.b32     a,%1;          \n\t"
         "mov.b32     b,%2;          \n\t"
         "xor.b32     s,a,b;         \n\t"
         "or.b32      r,a,0x80808080;\n\t"
         "and.b32     t,b,0x7f7f7f7f;\n\t"
         "sub.u32     r,r,t;         \n\t"
         "xor.b32     t,r,a;         \n\t"
         "xor.b32     r,r,s;         \n\t"
         "and.b32     t,t,s;         \n\t"
         "xor.b32     t,t,r;         \n\t"
         "and.b32     t,t,0x80808080;\n\t"
         "shr.u32     r,t,7;         \n\t"
         "mov.b32     %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetgeu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;




    asm ("not.b32 %0,%0;" : "+r"(b));
    c = __vavgu4 (a, b);
    c = c & 0x80808080;
    r = c >> 7;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetgts4(unsigned int a, unsigned int b)
{
    unsigned int r;





    asm ("{                       \n\t"
         ".reg .u32 a,b,r,s,t,u;  \n\t"
         "mov.b32  a,%1;          \n\t"
         "mov.b32  b,%2;          \n\t"
         "not.b32  b,b;           \n\t"
         "and.b32  r,a,0x7f7f7f7f;\n\t"
         "and.b32  t,b,0x7f7f7f7f;\n\t"
         "xor.b32  s,a,b;         \n\t"
         "add.u32  r,r,t;         \n\t"
         "xor.b32  t,a,r;         \n\t"
         "not.b32  u,s;           \n\t"
         "and.b32  t,t,u;         \n\t"
         "xor.b32  r,r,u;         \n\t"
         "xor.b32  t,t,r;         \n\t"
         "and.b32  t,t,0x80808080;\n\t"
         "shr.u32  r,t,7;         \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetgtu4(unsigned int a, unsigned int b)
{
    unsigned int r, c;




    asm ("not.b32 %0,%0;" : "+r"(b));
    c = __vhaddu4 (a, b);
    c = c & 0x80808080;
    r = c >> 7;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsetne4(unsigned int a, unsigned int b)
{
    unsigned int r, c;






    r = a ^ b;
    c = r | 0x80808080;
    c = c - 0x01010101;
    c = r | c;
    c = c & 0x80808080;
    r = c >> 7;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsadu4(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    r = __vabsdiffu4 (a, b);
    s = r >> 8;
    r = (r & 0x00ff00ff) + (s & 0x00ff00ff);
    r = ((r << 16) + r) >> 16;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsub4(unsigned int a, unsigned int b)
{




    unsigned int r, s, t;
    s = a ^ ~b;
    r = a | 0x80808080;
    t = b & 0x7f7f7f7f;
    s = s & 0x80808080;
    r = r - t;
    r = r ^ s;

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsubss4(unsigned int a, unsigned int b)
{
    unsigned int r;
# 3970 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    asm ("{                          \n\t"
         ".reg .u32 a,b,r,s,t,u,v,w; \n\t"
         "mov.b32     a,%1;          \n\t"
         "mov.b32     b,%2;          \n\t"
         "not.b32     u,b;           \n\t"
         "xor.b32     s,u,a;         \n\t"
         "or.b32      r,a,0x80808080;\n\t"
         "and.b32     t,b,0x7f7f7f7f;\n\t"
         "sub.u32     r,r,t;         \n\t"
         "xor.b32     t,r,a;         \n\t"
         "not.b32     u,s;           \n\t"
         "and.b32     s,s,0x80808080;\n\t"
         "xor.b32     r,r,s;         \n\t"
         "and.b32     t,t,u;         \n\t"
         "prmt.b32    s,a,0,0xba98;  \n\t"
         "xor.b32     s,s,0x7f7f7f7f;\n\t"
         "prmt.b32    t,t,0,0xba98;  \n\t"
         "and.b32     s,s,t;         \n\t"
         "not.b32     t,t;           \n\t"
         "and.b32     r,r,t;         \n\t"
         "or.b32      r,r,s;         \n\t"
         "mov.b32     %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a), "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsubus4(unsigned int a, unsigned int b)
{
    unsigned int r;
# 4030 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.hpp" 3
    asm ("{                       \n\t"
         ".reg .u32 a,b,r,s,t,u;  \n\t"
         "mov.b32  a,%1;          \n\t"
         "mov.b32  b,%2;          \n\t"
         "not.b32  u,b;           \n\t"
         "xor.b32  s,u,a;         \n\t"
         "and.b32  u,u,a;         \n\t"
         "or.b32   r,a,0x80808080;\n\t"
         "and.b32  t,b,0x7f7f7f7f;\n\t"
         "sub.u32  r,r,t;         \n\t"
         "and.b32  t,r,s;         \n\t"
         "and.b32  s,s,0x80808080;\n\t"
         "xor.b32  r,r,s;         \n\t"
         "or.b32   t,t,u;         \n\t"
         "prmt.b32 t,t,0,0xba98;  \n\t"
         "and.b32  r,r,t;         \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "=r"(r) : "r"(a) , "r"(b));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vneg4(unsigned int a)
{
    return __vsub4 (0, a);
}

static __inline__ __attribute__((always_inline)) unsigned int __vnegss4(unsigned int a)
{
    unsigned int r;




    r = __vsub4 (0, a);
    asm ("{                       \n\t"
         ".reg .u32 a, r, s;      \n\t"
         "mov.b32  r,%0;          \n\t"
         "mov.b32  a,%1;          \n\t"
         "and.b32  a,a,0x80808080;\n\t"
         "and.b32  s,a,r;         \n\t"
         "shr.u32  s,s,7;         \n\t"
         "sub.u32  r,r,s;         \n\t"
         "mov.b32  %0,r;          \n\t"
         "}"
         : "+r"(r) : "r"(a));

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vabsdiffs4(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    s = __vcmpges4 (a, b);
    r = a ^ b;
    s = (r & s) ^ b;
    r = s ^ r;
    r = __vsub4 (s, r);

    return r;
}

static __inline__ __attribute__((always_inline)) unsigned int __vsads4(unsigned int a, unsigned int b)
{
    unsigned int r, s;




    r = __vabsdiffs4 (a, b);
    s = r >> 8;
    r = (r & 0x00ff00ff) + (s & 0x00ff00ff);
    r = ((r << 16) + r) >> 16;

    return r;
}
# 4512 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3


# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_atomic_functions.h" 1 3
# 201 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_atomic_functions.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_atomic_functions.hpp" 1 3
# 202 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_atomic_functions.h" 2 3
# 4515 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_double_functions.h" 1 3
# 1182 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_double_functions.h" 3
static __inline__ __attribute__((always_inline)) double __dsub_rn(double a, double b);

static __inline__ __attribute__((always_inline)) double __dsub_rz(double a, double b);

static __inline__ __attribute__((always_inline)) double __dsub_ru(double a, double b);

static __inline__ __attribute__((always_inline)) double __dsub_rd(double a, double b);






# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_double_functions.hpp" 1 3
# 193 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_double_functions.hpp" 3
static __inline__ __attribute__((always_inline)) double __dsub_rn(double a, double b)
{
  double res;
  asm ("sub.rn.f64 %0, %1, %2;" : "=d"(res) : "d"(a), "d"(b));
  return res;
}

static __inline__ __attribute__((always_inline)) double __dsub_rz(double a, double b)
{
  double res;
  asm ("sub.rz.f64 %0, %1, %2;" : "=d"(res) : "d"(a), "d"(b));
  return res;
}

static __inline__ __attribute__((always_inline)) double __dsub_ru(double a, double b)
{
  double res;
  asm ("sub.rp.f64 %0, %1, %2;" : "=d"(res) : "d"(a), "d"(b));
  return res;
}

static __inline__ __attribute__((always_inline)) double __dsub_rd(double a, double b)
{
  double res;
  asm ("sub.rm.f64 %0, %1, %2;" : "=d"(res) : "d"(a), "d"(b));
  return res;
}
# 1196 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_double_functions.h" 2 3
# 4516 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_20_atomic_functions.h" 1 3
# 102 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_20_atomic_functions.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_20_atomic_functions.hpp" 1 3
# 103 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_20_atomic_functions.h" 2 3
# 4517 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_32_atomic_functions.h" 1 3
# 124 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_32_atomic_functions.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_32_atomic_functions.hpp" 1 3
# 125 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_32_atomic_functions.h" 2 3
# 4518 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_35_atomic_functions.h" 1 3
# 4519 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_60_atomic_functions.h" 1 3
# 528 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_60_atomic_functions.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_60_atomic_functions.hpp" 1 3
# 529 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_60_atomic_functions.h" 2 3
# 4520 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_20_intrinsics.h" 1 3
# 1494 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_20_intrinsics.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_20_intrinsics.hpp" 1 3
# 1495 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_20_intrinsics.h" 2 3
# 4521 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_30_intrinsics.h" 1 3
# 177 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_30_intrinsics.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_30_intrinsics.hpp" 1 3
# 178 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_30_intrinsics.h" 2 3
# 4522 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_32_intrinsics.h" 1 3
# 251 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_32_intrinsics.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_32_intrinsics.hpp" 1 3
# 252 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_32_intrinsics.h" 2 3
# 4523 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_35_intrinsics.h" 1 3
# 4524 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_61_intrinsics.h" 1 3
# 122 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_61_intrinsics.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_61_intrinsics.hpp" 1 3
# 123 "/usr/local/cuda-8.0/targets/x86_64-linux/include/sm_61_intrinsics.h" 2 3
# 4525 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_functions.h" 1 3
# 2220 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_functions.h" 3
extern uchar1 __surf1Dreadc1(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern uchar2 __surf1Dreadc2(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern uchar4 __surf1Dreadc4(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern ushort1 __surf1Dreads1(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern ushort2 __surf1Dreads2(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern ushort4 __surf1Dreads4(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern uint1 __surf1Dreadu1(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern uint2 __surf1Dreadu2(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern uint4 __surf1Dreadu4(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern ulonglong1 __surf1Dreadl1(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern ulonglong2 __surf1Dreadl2(unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern uchar1 __surf2Dreadc1(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uchar2 __surf2Dreadc2(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uchar4 __surf2Dreadc4(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ushort1 __surf2Dreads1(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ushort2 __surf2Dreads2(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ushort4 __surf2Dreads4(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uint1 __surf2Dreadu1(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uint2 __surf2Dreadu2(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uint4 __surf2Dreadu4(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong1 __surf2Dreadl1(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong2 __surf2Dreadl2(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uchar1 __surf3Dreadc1(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uchar2 __surf3Dreadc2(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uchar4 __surf3Dreadc4(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ushort1 __surf3Dreads1(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ushort2 __surf3Dreads2(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ushort4 __surf3Dreads4(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uint1 __surf3Dreadu1(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uint2 __surf3Dreadu2(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uint4 __surf3Dreadu4(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong1 __surf3Dreadl1(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong2 __surf3Dreadl2(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uchar1 __surf1DLayeredreadc1(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uchar2 __surf1DLayeredreadc2(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uchar4 __surf1DLayeredreadc4(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ushort1 __surf1DLayeredreads1(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ushort2 __surf1DLayeredreads2(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ushort4 __surf1DLayeredreads4(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uint1 __surf1DLayeredreadu1(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uint2 __surf1DLayeredreadu2(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uint4 __surf1DLayeredreadu4(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong1 __surf1DLayeredreadl1(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong2 __surf1DLayeredreadl2(unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern uchar1 __surf2DLayeredreadc1(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uchar2 __surf2DLayeredreadc2(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uchar4 __surf2DLayeredreadc4(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ushort1 __surf2DLayeredreads1(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ushort2 __surf2DLayeredreads2(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ushort4 __surf2DLayeredreads4(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uint1 __surf2DLayeredreadu1(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uint2 __surf2DLayeredreadu2(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern uint4 __surf2DLayeredreadu4(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong1 __surf2DLayeredreadl1(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern ulonglong2 __surf2DLayeredreadl2(unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwritec1( uchar1, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwritec2( uchar2, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwritec4( uchar4, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwrites1( ushort1, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwrites2( ushort2, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwrites4( ushort4, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwriteu1( uint1, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwriteu2( uint2, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwriteu4( uint4, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwritel1(ulonglong1, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf1Dwritel2(ulonglong2, unsigned long long, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwritec1( uchar1, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwritec2( uchar2, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwritec4( uchar4, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwrites1( ushort1, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwrites2( ushort2, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwrites4( ushort4, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwriteu1( uint1, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwriteu2( uint2, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwriteu4( uint4, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwritel1(ulonglong1, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2Dwritel2(ulonglong2, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwritec1( uchar1 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwritec2( uchar2 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwritec4( uchar4 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwrites1( ushort1 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwrites2( ushort2 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwrites4( ushort4 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwriteu1( uint1 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwriteu2( uint2 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwriteu4( uint4 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwritel1(ulonglong1 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf3Dwritel2(ulonglong2 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwritec1( uchar1 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwritec2( uchar2 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwritec4( uchar4 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwrites1( ushort1 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwrites2( ushort2 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwrites4( ushort4 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwriteu1( uint1 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwriteu2( uint2 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwriteu4( uint4 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwritel1(ulonglong1 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf1DLayeredwritel2(ulonglong2 val, unsigned long long, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwritec1( uchar1 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwritec2( uchar2 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwritec4( uchar4 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwrites1( ushort1 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwrites2( ushort2 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwrites4( ushort4 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwriteu1( uint1 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwriteu2( uint2 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwriteu4( uint4 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwritel1(ulonglong1 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
extern void __surf2DLayeredwritel2(ulonglong2 val, unsigned long long, int, int, int, enum cudaSurfaceBoundaryMode);
# 4526 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/texture_fetch_functions.h" 1 3
# 4527 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/texture_indirect_functions.h" 1 3
# 4528 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/surface_indirect_functions.h" 1 3
# 4529 "/usr/local/cuda-8.0/targets/x86_64-linux/include/device_functions.h" 2 3
# 9846 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 2 3
# 9861 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 3
static __inline__ __attribute__((always_inline)) float rintf(float a);

static __inline__ __attribute__((always_inline)) long int lrintf(float a);

static __inline__ __attribute__((always_inline)) long long int llrintf(float a);

static __inline__ __attribute__((always_inline)) float nearbyintf(float a);

static __inline__ __attribute__((always_inline)) int __signbitf(float a);
# 9885 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 3
static __inline__ __attribute__((always_inline)) float copysignf(float a, float b);

static __inline__ __attribute__((always_inline)) int __finitef(float a);







static __inline__ __attribute__((always_inline)) int __isinff(float a);

static __inline__ __attribute__((always_inline)) int __isnanf(float a);

static __inline__ __attribute__((always_inline)) float nextafterf(float a, float b);

static __inline__ __attribute__((always_inline)) float nanf(const char *tagp);

static __inline__ __attribute__((always_inline)) float sinf(float a);

static __inline__ __attribute__((always_inline)) float cosf(float a);

static __inline__ __attribute__((always_inline)) void sincosf(float a, float *sptr, float *cptr);

static __inline__ __attribute__((always_inline)) float sinpif(float a);

static __inline__ __attribute__((always_inline)) float cospif(float a);

static __inline__ __attribute__((always_inline)) void sincospif(float a, float *sptr, float *cptr);

static __inline__ __attribute__((always_inline)) float tanf(float a);

static __inline__ __attribute__((always_inline)) float log2f(float a);

static __inline__ __attribute__((always_inline)) float expf(float a);

static __inline__ __attribute__((always_inline)) float exp10f(float a);

static __inline__ __attribute__((always_inline)) float coshf(float a);

static __inline__ __attribute__((always_inline)) float sinhf(float a);

static __inline__ __attribute__((always_inline)) float tanhf(float a);

static __inline__ __attribute__((always_inline)) float atan2f(float a, float b);

static __inline__ __attribute__((always_inline)) float atanf(float a);

static __inline__ __attribute__((always_inline)) float asinf(float a);

static __inline__ __attribute__((always_inline)) float acosf(float a);

static __inline__ __attribute__((always_inline)) float logf(float a);

static __inline__ __attribute__((always_inline)) float log10f(float a);

static __inline__ __attribute__((always_inline)) float log1pf(float a);

static __inline__ __attribute__((always_inline)) float acoshf(float a);

static __inline__ __attribute__((always_inline)) float asinhf(float a);

static __inline__ __attribute__((always_inline)) float atanhf(float a);

static __inline__ __attribute__((always_inline)) float expm1f(float a);

static __inline__ __attribute__((always_inline)) float hypotf(float a, float b);

static __inline__ __attribute__((always_inline)) float rhypotf(float a, float b) ;

static __inline__ __attribute__((always_inline)) float norm3df(float a, float b, float c) ;

static __inline__ __attribute__((always_inline)) float rnorm3df(float a, float b, float c) ;

static __inline__ __attribute__((always_inline)) float norm4df(float a, float b, float c, float d) ;

static __inline__ __attribute__((always_inline)) float cbrtf(float a);

static __inline__ __attribute__((always_inline)) float rcbrtf(float a);

static __inline__ __attribute__((always_inline)) float j0f(float a);

static __inline__ __attribute__((always_inline)) float j1f(float a);

static __inline__ __attribute__((always_inline)) float y0f(float a);

static __inline__ __attribute__((always_inline)) float y1f(float a);

static __inline__ __attribute__((always_inline)) float ynf(int n, float a);

static __inline__ __attribute__((always_inline)) float jnf(int n, float a);

static __inline__ __attribute__((always_inline)) float cyl_bessel_i0f(float a) ;

static __inline__ __attribute__((always_inline)) float cyl_bessel_i1f(float a) ;

static __inline__ __attribute__((always_inline)) float erff(float a);

static __inline__ __attribute__((always_inline)) float erfinvf(float a);

static __inline__ __attribute__((always_inline)) float erfcf(float a);

static __inline__ __attribute__((always_inline)) float erfcxf(float a);

static __inline__ __attribute__((always_inline)) float erfcinvf(float a);

static __inline__ __attribute__((always_inline)) float normcdfinvf(float a);

static __inline__ __attribute__((always_inline)) float normcdff(float a);

static __inline__ __attribute__((always_inline)) float lgammaf(float a);

static __inline__ __attribute__((always_inline)) float ldexpf(float a, int b);

static __inline__ __attribute__((always_inline)) float scalbnf(float a, int b);

static __inline__ __attribute__((always_inline)) float scalblnf(float a, long int b);

static __inline__ __attribute__((always_inline)) float frexpf(float a, int *b);

static __inline__ __attribute__((always_inline)) float modff(float a, float *b);

static __inline__ __attribute__((always_inline)) float fmodf(float a, float b);

static __inline__ __attribute__((always_inline)) float remainderf(float a, float b);

static __inline__ __attribute__((always_inline)) float remquof(float a, float b, int* quo);

static __inline__ __attribute__((always_inline)) float fmaf(float a, float b, float c);

static __inline__ __attribute__((always_inline)) float powif(float a, int b);

static __inline__ __attribute__((always_inline)) double powi(double a, int b);

static __inline__ __attribute__((always_inline)) float powf(float a, float b);

static __inline__ __attribute__((always_inline)) float tgammaf(float a);

static __inline__ __attribute__((always_inline)) float roundf(float a);

static __inline__ __attribute__((always_inline)) long long int llroundf(float a);

static __inline__ __attribute__((always_inline)) long int lroundf(float a);

static __inline__ __attribute__((always_inline)) float fdimf(float a, float b);

static __inline__ __attribute__((always_inline)) int ilogbf(float a);

static __inline__ __attribute__((always_inline)) float logbf(float a);
# 10327 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.hpp" 1 3
# 1095 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.hpp" 3
# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_constants.h" 1 3
# 1096 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.hpp" 2 3
# 1135 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.hpp" 3
static __inline__ __attribute__((always_inline)) float rintf(float a)
{
  return __nv_rintf(a);
}

static __inline__ __attribute__((always_inline)) long int lrintf(float a)
{

  return (long int)__float2ll_rn(a);



}

static __inline__ __attribute__((always_inline)) long long int llrintf(float a)
{
  return __nv_llrintf(a);
}

static __inline__ __attribute__((always_inline)) float nearbyintf(float a)
{
  return __nv_nearbyintf(a);
}







static __inline__ __attribute__((always_inline)) int __signbitf(float a)
{
  return __nv_signbitf(a);
}
# 1189 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.hpp" 3
static __inline__ __attribute__((always_inline)) float copysignf(float a, float b)
{
  return __nv_copysignf(a, b);
}

static __inline__ __attribute__((always_inline)) int __finitef(float a)
{
  return __nv_finitef(a);
}
# 1208 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.hpp" 3
static __inline__ __attribute__((always_inline)) int __isinff(float a)
{
  return __nv_isinff(a);
}

static __inline__ __attribute__((always_inline)) int __isnanf(float a)
{
  return __nv_isnanf(a);
}

static __inline__ __attribute__((always_inline)) float nextafterf(float a, float b)
{
  return __nv_nextafterf(a, b);
}

static __inline__ __attribute__((always_inline)) float nanf(const char *tagp)
{
  return __nv_nanf((const signed char *) tagp);
}







static __inline__ __attribute__((always_inline)) float sinf(float a)
{
  if (0) {
    return __nv_fast_sinf(a);
  } else {
    return __nv_sinf(a);
  }
}

static __inline__ __attribute__((always_inline)) float cosf(float a)
{
  if (0) {
    return __nv_fast_cosf(a);
  } else {
    return __nv_cosf(a);
  }
}

static __inline__ __attribute__((always_inline)) void sincosf(float a, float *sptr, float *cptr)
{
  if (0) {
    __nv_fast_sincosf(a, sptr, cptr);
  } else {
    __nv_sincosf(a, sptr, cptr);
  }
}

static __inline__ __attribute__((always_inline)) float sinpif(float a)
{
  return __nv_sinpif(a);
}

static __inline__ __attribute__((always_inline)) float cospif(float a)
{
  return __nv_cospif(a);
}

static __inline__ __attribute__((always_inline)) void sincospif(float a, float *sptr, float *cptr)
{
  __nv_sincospif(a, sptr, cptr);
}

static __inline__ __attribute__((always_inline)) float tanf(float a)
{
  if (0) {
    return __nv_fast_tanf(a);
  } else {
    return __nv_tanf(a);
  }
}

static __inline__ __attribute__((always_inline)) float log2f(float a)
{
  if (0) {
    return __nv_fast_log2f(a);
  } else {
    return __nv_log2f(a);
  }
}

static __inline__ __attribute__((always_inline)) float expf(float a)
{
  if (0) {
    return __nv_fast_expf(a);
  } else {
    return __nv_expf(a);
  }
}

static __inline__ __attribute__((always_inline)) float exp10f(float a)
{
  if (0) {
    return __nv_fast_exp10f(a);
  } else {
    return __nv_exp10f(a);
  }
}

static __inline__ __attribute__((always_inline)) float coshf(float a)
{
  return __nv_coshf(a);
}

static __inline__ __attribute__((always_inline)) float sinhf(float a)
{
  return __nv_sinhf(a);
}

static __inline__ __attribute__((always_inline)) float tanhf(float a)
{
  return __nv_tanhf(a);
}

static __inline__ __attribute__((always_inline)) float atan2f(float a, float b)
{
  return __nv_atan2f(a, b);
}

static __inline__ __attribute__((always_inline)) float atanf(float a)
{
  return __nv_atanf(a);
}

static __inline__ __attribute__((always_inline)) float asinf(float a)
{
  return __nv_asinf(a);
}

static __inline__ __attribute__((always_inline)) float acosf(float a)
{
  return __nv_acosf(a);
}

static __inline__ __attribute__((always_inline)) float logf(float a)
{
  if (0) {
    return __nv_fast_logf(a);
  } else {
    return __nv_logf(a);
  }
}

static __inline__ __attribute__((always_inline)) float log10f(float a)
{
  if (0) {
    return __nv_fast_log10f(a);
  } else {
    return __nv_log10f(a);
  }
}

static __inline__ __attribute__((always_inline)) float log1pf(float a)
{
  return __nv_log1pf(a);
}

static __inline__ __attribute__((always_inline)) float acoshf(float a)
{
  return __nv_acoshf(a);
}

static __inline__ __attribute__((always_inline)) float asinhf(float a)
{
  return __nv_asinhf(a);
}

static __inline__ __attribute__((always_inline)) float atanhf(float a)
{
  return __nv_atanhf(a);
}

static __inline__ __attribute__((always_inline)) float expm1f(float a)
{
  return __nv_expm1f(a);
}

static __inline__ __attribute__((always_inline)) float hypotf(float a, float b)
{
  return __nv_hypotf(a, b);
}

static __inline__ __attribute__((always_inline)) float rhypotf(float a, float b)
{
  return __nv_rhypotf(a, b);
}

static __inline__ __attribute__((always_inline)) float rnormf(int dim, float const * a)
{
  return __nv_rnormf(dim, a);
}

static __inline__ __attribute__((always_inline)) float normf(int dim, float const * a)
{
  return __nv_normf(dim, a);
}

static __inline__ __attribute__((always_inline)) float norm3df(float a, float b, float c)
{
  return __nv_norm3df(a, b, c);
}

static __inline__ __attribute__((always_inline)) float rnorm3df(float a, float b, float c)
{
  return __nv_rnorm3df(a, b, c);
}

static __inline__ __attribute__((always_inline)) float norm4df(float a, float b, float c, float d)
{
  return __nv_norm4df(a, b, c, d);
}

static __inline__ __attribute__((always_inline)) float rnorm4df(float a, float b, float c, float d)
{
  return __nv_rnorm4df(a, b, c, d);
}

static __inline__ __attribute__((always_inline)) float cbrtf(float a)
{
  return __nv_cbrtf(a);
}

static __inline__ __attribute__((always_inline)) float rcbrtf(float a)
{
  return __nv_rcbrtf(a);
}

static __inline__ __attribute__((always_inline)) float j0f(float a)
{
  return __nv_j0f(a);
}

static __inline__ __attribute__((always_inline)) float j1f(float a)
{
  return __nv_j1f(a);
}

static __inline__ __attribute__((always_inline)) float y0f(float a)
{
  return __nv_y0f(a);
}

static __inline__ __attribute__((always_inline)) float y1f(float a)
{
  return __nv_y1f(a);
}

static __inline__ __attribute__((always_inline)) float ynf(int n, float a)
{
  return __nv_ynf(n, a);
}

static __inline__ __attribute__((always_inline)) float jnf(int n, float a)
{
  return __nv_jnf(n, a);
}

static __inline__ __attribute__((always_inline)) float cyl_bessel_i0f(float a)
{
  return __nv_cyl_bessel_i0f(a);
}

static __inline__ __attribute__((always_inline)) float cyl_bessel_i1f(float a)
{
  return __nv_cyl_bessel_i1f(a);
}

static __inline__ __attribute__((always_inline)) float erff(float a)
{
  return __nv_erff(a);
}

static __inline__ __attribute__((always_inline)) float erfinvf(float a)
{
  return __nv_erfinvf(a);
}

static __inline__ __attribute__((always_inline)) float erfcf(float a)
{
  return __nv_erfcf(a);
}

static __inline__ __attribute__((always_inline)) float erfcxf(float a)
{
  return __nv_erfcxf(a);
}

static __inline__ __attribute__((always_inline)) float erfcinvf(float a)
{
  return __nv_erfcinvf(a);
}

static __inline__ __attribute__((always_inline)) float normcdfinvf(float a)
{
  return __nv_normcdfinvf(a);
}

static __inline__ __attribute__((always_inline)) float normcdff(float a)
{
  return __nv_normcdff(a);
}

static __inline__ __attribute__((always_inline)) float lgammaf(float a)
{
  return __nv_lgammaf(a);
}

static __inline__ __attribute__((always_inline)) float ldexpf(float a, int b)
{
  return __nv_ldexpf(a, b);
}

static __inline__ __attribute__((always_inline)) float scalbnf(float a, int b)
{
  return __nv_scalbnf(a, b);
}

static __inline__ __attribute__((always_inline)) float scalblnf(float a, long int b)
{
  int t;
  if (b > 2147483647L) {
    t = 2147483647;
  } else if (b < (-2147483647 - 1)) {
    t = (-2147483647 - 1);
  } else {
    t = (int)b;
  }
  return scalbnf(a, t);
}

static __inline__ __attribute__((always_inline)) float frexpf(float a, int *b)
{
  return __nv_frexpf(a, b);
}

static __inline__ __attribute__((always_inline)) float modff(float a, float *b)
{
  return __nv_modff(a, b);
}

static __inline__ __attribute__((always_inline)) float fmodf(float a, float b)
{
  return __nv_fmodf(a, b);
}

static __inline__ __attribute__((always_inline)) float remainderf(float a, float b)
{
  return __nv_remainderf(a, b);
}

static __inline__ __attribute__((always_inline)) float remquof(float a, float b, int* quo)
{
  return __nv_remquof(a, b, quo);
}

static __inline__ __attribute__((always_inline)) float fmaf(float a, float b, float c)
{
  return __nv_fmaf(a, b, c);
}

static __inline__ __attribute__((always_inline)) float powif(float a, int b)
{
  return __nv_powif(a, b);
}

static __inline__ __attribute__((always_inline)) double powi(double a, int b)
{
  return __nv_powi(a, b);
}

static __inline__ __attribute__((always_inline)) float powf(float a, float b)
{
  if (0) {
    return __nv_fast_powf(a, b);
  } else {
    return __nv_powf(a, b);
  }
}

static __inline__ __attribute__((always_inline)) float tgammaf(float a)
{
  return __nv_tgammaf(a);
}

static __inline__ __attribute__((always_inline)) float roundf(float a)
{
  return __nv_roundf(a);
}

static __inline__ __attribute__((always_inline)) long long int llroundf(float a)
{
  return __nv_llroundf(a);
}

static __inline__ __attribute__((always_inline)) long int lroundf(float a)
{

  return (long int)llroundf(a);



}

static __inline__ __attribute__((always_inline)) float fdimf(float a, float b)
{
  return __nv_fdimf(a, b);
}

static __inline__ __attribute__((always_inline)) int ilogbf(float a)
{
  return __nv_ilogbf(a);
}

static __inline__ __attribute__((always_inline)) float logbf(float a)
{
  return __nv_logbf(a);
}
# 10328 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 2 3



# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.h" 1 3
# 71 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.h" 3
static __inline__ __attribute__((always_inline)) double rint(double a) ;

static __inline__ __attribute__((always_inline)) long int lrint(double a) ;

static __inline__ __attribute__((always_inline)) long long int llrint(double a) ;

static __inline__ __attribute__((always_inline)) double nearbyint(double a) ;







static __inline__ __attribute__((always_inline)) int __signbitd(double a);

static __inline__ __attribute__((always_inline)) int __isfinited(double a);

static __inline__ __attribute__((always_inline)) int __isinfd(double a);

static __inline__ __attribute__((always_inline)) int __isnand(double a);
# 105 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.h" 3
static __inline__ __attribute__((always_inline)) int __signbit(double a) ;

static __inline__ __attribute__((always_inline)) int __signbitl( double a);

static __inline__ __attribute__((always_inline)) int __finite(double a) ;

static __inline__ __attribute__((always_inline)) int __finitel( double a);

static __inline__ __attribute__((always_inline)) int __isinf(double a) ;

static __inline__ __attribute__((always_inline)) int __isinfl( double a);

static __inline__ __attribute__((always_inline)) int __isnan(double a) ;

static __inline__ __attribute__((always_inline)) int __isnanl( double a);



static __inline__ __attribute__((always_inline)) double copysign(double a, double b) ;

static __inline__ __attribute__((always_inline)) void sincos(double a, double *sptr, double *cptr) ;

static __inline__ __attribute__((always_inline)) void sincospi(double a, double *sptr, double *cptr);

static __inline__ __attribute__((always_inline)) double sin(double a) ;

static __inline__ __attribute__((always_inline)) double cos(double a) ;

static __inline__ __attribute__((always_inline)) double sinpi(double a);

static __inline__ __attribute__((always_inline)) double cospi(double a);

static __inline__ __attribute__((always_inline)) double tan(double a) ;

static __inline__ __attribute__((always_inline)) double log(double a) ;

static __inline__ __attribute__((always_inline)) double log2(double a) ;

static __inline__ __attribute__((always_inline)) double log10(double a) ;

static __inline__ __attribute__((always_inline)) double log1p(double a) ;

static __inline__ __attribute__((always_inline)) double exp(double a) ;

static __inline__ __attribute__((always_inline)) double exp2(double a) ;

static __inline__ __attribute__((always_inline)) double exp10(double a) ;

static __inline__ __attribute__((always_inline)) double expm1(double a) ;

static __inline__ __attribute__((always_inline)) double cosh(double a) ;

static __inline__ __attribute__((always_inline)) double sinh(double a) ;

static __inline__ __attribute__((always_inline)) double tanh(double a) ;

static __inline__ __attribute__((always_inline)) double atan2(double a, double b) ;

static __inline__ __attribute__((always_inline)) double atan(double a) ;

static __inline__ __attribute__((always_inline)) double asin(double a) ;

static __inline__ __attribute__((always_inline)) double acos(double a) ;

static __inline__ __attribute__((always_inline)) double acosh(double a) ;

static __inline__ __attribute__((always_inline)) double asinh(double a) ;

static __inline__ __attribute__((always_inline)) double atanh(double a) ;

static __inline__ __attribute__((always_inline)) double hypot(double a, double b) ;

static __inline__ __attribute__((always_inline)) double rhypot(double a, double b) ;

static __inline__ __attribute__((always_inline)) double norm3d(double a, double b, double c) ;

static __inline__ __attribute__((always_inline)) double rnorm3d(double a, double b, double c) ;

static __inline__ __attribute__((always_inline)) double norm4d(double a, double b, double c, double d) ;

static __inline__ __attribute__((always_inline)) double rnorm4d(double a, double b, double c, double d) ;

static __inline__ __attribute__((always_inline)) double norm(int dim, double const * t) ;

static __inline__ __attribute__((always_inline)) double rnorm(int dim, double const * t) ;

static __inline__ __attribute__((always_inline)) double cbrt(double a) ;

static __inline__ __attribute__((always_inline)) double rcbrt(double a);

static __inline__ __attribute__((always_inline)) double pow(double a, double b) ;

static __inline__ __attribute__((always_inline)) double j0(double a) ;

static __inline__ __attribute__((always_inline)) double j1(double a) ;

static __inline__ __attribute__((always_inline)) double y0(double a) ;

static __inline__ __attribute__((always_inline)) double y1(double a) ;

static __inline__ __attribute__((always_inline)) double yn(int n, double a) ;

static __inline__ __attribute__((always_inline)) double jn(int n, double a) ;

static __inline__ __attribute__((always_inline)) double cyl_bessel_i0(double a) ;

static __inline__ __attribute__((always_inline)) double cyl_bessel_i1(double a) ;

static __inline__ __attribute__((always_inline)) double erf(double a) ;

static __inline__ __attribute__((always_inline)) double erfinv(double a);

static __inline__ __attribute__((always_inline)) double erfcinv(double a);

static __inline__ __attribute__((always_inline)) double normcdfinv(double a);

static __inline__ __attribute__((always_inline)) double erfc(double a) ;

static __inline__ __attribute__((always_inline)) double erfcx(double a);

static __inline__ __attribute__((always_inline)) double normcdf(double a);

static __inline__ __attribute__((always_inline)) double tgamma(double a) ;

static __inline__ __attribute__((always_inline)) double lgamma(double a) ;

static __inline__ __attribute__((always_inline)) double ldexp(double a, int b) ;

static __inline__ __attribute__((always_inline)) double scalbn(double a, int b) ;

static __inline__ __attribute__((always_inline)) double scalbln(double a, long int b) ;

static __inline__ __attribute__((always_inline)) double frexp(double a, int *b) ;

static __inline__ __attribute__((always_inline)) double modf(double a, double *b) ;

static __inline__ __attribute__((always_inline)) double fmod(double a, double b) ;

static __inline__ __attribute__((always_inline)) double remainder(double a, double b) ;

static __inline__ __attribute__((always_inline)) double remquo(double a, double b, int *c) ;

static __inline__ __attribute__((always_inline)) double nextafter(double a, double b) ;

static __inline__ __attribute__((always_inline)) double nan(const char *tagp) ;

static __inline__ __attribute__((always_inline)) double round(double a) ;

static __inline__ __attribute__((always_inline)) long long int llround(double a) ;

static __inline__ __attribute__((always_inline)) long int lround(double a) ;

static __inline__ __attribute__((always_inline)) double fdim(double a, double b) ;

static __inline__ __attribute__((always_inline)) int ilogb(double a) ;

static __inline__ __attribute__((always_inline)) double logb(double a) ;

static __inline__ __attribute__((always_inline)) double fma(double a, double b, double c) ;






# 1 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.hpp" 1 3
# 71 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.hpp" 3
static __inline__ __attribute__((always_inline)) double rint(double a)
{
  return __nv_rint(a);
}

static __inline__ __attribute__((always_inline)) long int lrint(double a)
{

  return (long int)__double2ll_rn(a);



}

static __inline__ __attribute__((always_inline)) long long int llrint(double a)
{
  return __nv_llrint(a);
}

static __inline__ __attribute__((always_inline)) double nearbyint(double a)
{
  return __nv_nearbyint(a);
}







static __inline__ __attribute__((always_inline)) int __signbitd(double a)
{
  return __nv_signbitd(a);
}

static __inline__ __attribute__((always_inline)) int __isfinited(double a)
{
  return __nv_isfinited(a);
}

static __inline__ __attribute__((always_inline)) int __isinfd(double a)
{
  return __nv_isinfd(a);
}

static __inline__ __attribute__((always_inline)) int __isnand(double a)
{
  return __nv_isnand(a);
}
# 145 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.hpp" 3
static __inline__ __attribute__((always_inline)) int __signbit(double a)
{
  return __signbitd(a);
}

static __inline__ __attribute__((always_inline)) int __signbitl( double a)
{
  return __signbit((double)a);
}

static __inline__ __attribute__((always_inline)) int __finite(double a)
{
  return __isfinited(a);
}

static __inline__ __attribute__((always_inline)) int __finitel( double a)
{
  return __finite((double)a);
}

static __inline__ __attribute__((always_inline)) int __isinf(double a)
{
  return __isinfd(a);
}

static __inline__ __attribute__((always_inline)) int __isinfl( double a)
{
  return __isinf((double)a);
}

static __inline__ __attribute__((always_inline)) int __isnan(double a)
{
  return __isnand(a);
}

static __inline__ __attribute__((always_inline)) int __isnanl( double a)
{
  return __isnan((double)a);
}



static __inline__ __attribute__((always_inline)) double copysign(double a, double b)
{
  return __nv_copysign(a, b);
}

static __inline__ __attribute__((always_inline)) void sincos(double a, double *sptr, double *cptr)
{
  __nv_sincos(a, sptr, cptr);
}

static __inline__ __attribute__((always_inline)) void sincospi(double a, double *sptr, double *cptr)
{
  __nv_sincospi(a, sptr, cptr);
}

static __inline__ __attribute__((always_inline)) double sin(double a)
{
  return __nv_sin(a);
}

static __inline__ __attribute__((always_inline)) double cos(double a)
{
  return __nv_cos(a);
}

static __inline__ __attribute__((always_inline)) double sinpi(double a)
{
  return __nv_sinpi(a);
}

static __inline__ __attribute__((always_inline)) double cospi(double a)
{
  return __nv_cospi(a);
}

static __inline__ __attribute__((always_inline)) double tan(double a)
{
  return __nv_tan(a);
}

static __inline__ __attribute__((always_inline)) double log(double a)
{
  return __nv_log(a);
}

static __inline__ __attribute__((always_inline)) double log2(double a)
{
  return __nv_log2(a);
}

static __inline__ __attribute__((always_inline)) double log10(double a)
{
  return __nv_log10(a);
}

static __inline__ __attribute__((always_inline)) double log1p(double a)
{
  return __nv_log1p(a);
}

static __inline__ __attribute__((always_inline)) double exp(double a)
{
  return __nv_exp(a);
}

static __inline__ __attribute__((always_inline)) double exp2(double a)
{
  return __nv_exp2(a);
}

static __inline__ __attribute__((always_inline)) double exp10(double a)
{
  return __nv_exp10(a);
}

static __inline__ __attribute__((always_inline)) double expm1(double a)
{
  return __nv_expm1(a);
}

static __inline__ __attribute__((always_inline)) double cosh(double a)
{
  return __nv_cosh(a);
}

static __inline__ __attribute__((always_inline)) double sinh(double a)
{
  return __nv_sinh(a);
}

static __inline__ __attribute__((always_inline)) double tanh(double a)
{
  return __nv_tanh(a);
}

static __inline__ __attribute__((always_inline)) double atan2(double a, double b)
{
  return __nv_atan2(a, b);
}

static __inline__ __attribute__((always_inline)) double atan(double a)
{
  return __nv_atan(a);
}

static __inline__ __attribute__((always_inline)) double asin(double a)
{
  return __nv_asin(a);
}

static __inline__ __attribute__((always_inline)) double acos(double a)
{
  return __nv_acos(a);
}

static __inline__ __attribute__((always_inline)) double acosh(double a)
{
  return __nv_acosh(a);
}

static __inline__ __attribute__((always_inline)) double asinh(double a)
{
  return __nv_asinh(a);
}

static __inline__ __attribute__((always_inline)) double atanh(double a)
{
  return __nv_atanh(a);
}

static __inline__ __attribute__((always_inline)) double hypot(double a, double b)
{
  return __nv_hypot(a, b);
}

static __inline__ __attribute__((always_inline)) double rhypot(double a, double b)
{
  return __nv_rhypot(a, b);
}

static __inline__ __attribute__((always_inline)) double norm3d(double a, double b, double c)
{
  return __nv_norm3d(a, b, c);
}

static __inline__ __attribute__((always_inline)) double rnorm3d(double a, double b, double c)
{
  return __nv_rnorm3d(a, b, c);
}

static __inline__ __attribute__((always_inline)) double norm4d(double a, double b, double c, double d)
{
  return __nv_norm4d(a, b, c, d);
}

static __inline__ __attribute__((always_inline)) double rnorm4d(double a, double b, double c, double d)
{
  return __nv_rnorm4d(a, b, c, d);
}

static __inline__ __attribute__((always_inline)) double norm(int dim, double const * t)
{
  return __nv_norm(dim, t);
}

static __inline__ __attribute__((always_inline)) double rnorm(int dim, double const * t)
{
  return __nv_rnorm(dim, t);
}

static __inline__ __attribute__((always_inline)) double cbrt(double a)
{
  return __nv_cbrt(a);
}

static __inline__ __attribute__((always_inline)) double rcbrt(double a)
{
  return __nv_rcbrt(a);
}

static __inline__ __attribute__((always_inline)) double pow(double a, double b)
{
  return __nv_pow(a, b);
}

static __inline__ __attribute__((always_inline)) double j0(double a)
{
  return __nv_j0(a);
}

static __inline__ __attribute__((always_inline)) double j1(double a)
{
  return __nv_j1(a);
}

static __inline__ __attribute__((always_inline)) double y0(double a)
{
  return __nv_y0(a);
}

static __inline__ __attribute__((always_inline)) double y1(double a)
{
  return __nv_y1(a);
}

static __inline__ __attribute__((always_inline)) double yn(int n, double a)
{
  return __nv_yn(n, a);
}

static __inline__ __attribute__((always_inline)) double jn(int n, double a)
{
  return __nv_jn(n, a);
}

static __inline__ __attribute__((always_inline)) double cyl_bessel_i0(double a)
{
  return __nv_cyl_bessel_i0(a);
}

static __inline__ __attribute__((always_inline)) double cyl_bessel_i1(double a)
{
  return __nv_cyl_bessel_i1(a);
}

static __inline__ __attribute__((always_inline)) double erf(double a)
{
  return __nv_erf(a);
}

static __inline__ __attribute__((always_inline)) double erfinv(double a)
{
  return __nv_erfinv(a);
}

static __inline__ __attribute__((always_inline)) double erfcinv(double a)
{
  return __nv_erfcinv(a);
}

static __inline__ __attribute__((always_inline)) double normcdfinv(double a)
{
  return __nv_normcdfinv(a);
}

static __inline__ __attribute__((always_inline)) double erfc(double a)
{
  return __nv_erfc(a);
}

static __inline__ __attribute__((always_inline)) double erfcx(double a)
{
  return __nv_erfcx(a);
}

static __inline__ __attribute__((always_inline)) double normcdf(double a)
{
  return __nv_normcdf(a);
}

static __inline__ __attribute__((always_inline)) double tgamma(double a)
{
  return __nv_tgamma(a);
}

static __inline__ __attribute__((always_inline)) double lgamma(double a)
{
  return __nv_lgamma(a);
}

static __inline__ __attribute__((always_inline)) double ldexp(double a, int b)
{
  return __nv_ldexp(a, b);
}

static __inline__ __attribute__((always_inline)) double scalbn(double a, int b)
{
  return __nv_scalbn(a, b);
}

static __inline__ __attribute__((always_inline)) double scalbln(double a, long int b)
{


  if (b < -2147483648L) b = -2147483648L;
  if (b > 2147483647L) b = 2147483647L;

  return scalbn(a, (int)b);
}

static __inline__ __attribute__((always_inline)) double frexp(double a, int *b)
{
  return __nv_frexp(a, b);
}

static __inline__ __attribute__((always_inline)) double modf(double a, double *b)
{
  return __nv_modf(a, b);
}

static __inline__ __attribute__((always_inline)) double fmod(double a, double b)
{
  return __nv_fmod(a, b);
}

static __inline__ __attribute__((always_inline)) double remainder(double a, double b)
{
  return __nv_remainder(a, b);
}

static __inline__ __attribute__((always_inline)) double remquo(double a, double b, int *c)
{
  return __nv_remquo(a, b, c);
}

static __inline__ __attribute__((always_inline)) double nextafter(double a, double b)
{
  return __nv_nextafter(a, b);
}

static __inline__ __attribute__((always_inline)) double nan(const char *tagp)
{
  return __nv_nan((const signed char *) tagp);
}

static __inline__ __attribute__((always_inline)) double round(double a)
{
  return __nv_round(a);
}

static __inline__ __attribute__((always_inline)) long long int llround(double a)
{
  return __nv_llround(a);
}

static __inline__ __attribute__((always_inline)) long int lround(double a)
{

  return (long int)llround(a);



}

static __inline__ __attribute__((always_inline)) double fdim(double a, double b)
{
  return __nv_fdim(a, b);
}

static __inline__ __attribute__((always_inline)) int ilogb(double a)
{
  return __nv_ilogb(a);
}

static __inline__ __attribute__((always_inline)) double logb(double a)
{
  return __nv_logb(a);
}

static __inline__ __attribute__((always_inline)) double fma(double a, double b, double c)
{
  return __nv_fma(a, b, c);
}
# 271 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions_dbl_ptx3.h" 2 3
# 10332 "/usr/local/cuda-8.0/targets/x86_64-linux/include/math_functions.h" 2 3
# 250 "/usr/local/cuda-8.0/bin/../targets/x86_64-linux/include/common_functions.h" 2
# 15 "t266.cu" 2
# 13 "t266.cu"
__attribute__((global)) __attribute__((__used__)) void _Z3dotPi(
# 13 "t266.cu"
int *a){
# 13 "t266.cu"
{
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
}
# 35 "t266.cu"
}}
