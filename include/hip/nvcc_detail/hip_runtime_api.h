/*
Copyright (c) 2015 - present Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef HIP_INCLUDE_HIP_NVCC_DETAIL_HIP_RUNTIME_API_H
#define HIP_INCLUDE_HIP_NVCC_DETAIL_HIP_RUNTIME_API_H

#include <cuda_runtime_api.h>
#include <cuda.h>
#include <cuda_profiler_api.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
#define __dparm(x) = x
#else
#define __dparm(x)
#endif

// TODO -move to include/hip_runtime_api.h as a common implementation.
/**
 * Memory copy types
 *
 */
typedef enum hipMemcpyKind {
    hipMemcpyHostToHost,
    hipMemcpyHostToDevice,
    hipMemcpyDeviceToHost,
    hipMemcpyDeviceToDevice,
    hipMemcpyDefault
} hipMemcpyKind;

// hipTextureAddressMode
#define hipTextureAddressMode cudaTextureAddressMode
#define hipAddressModeWrap cudaAddressModeWrap
#define hipAddressModeClamp cudaAddressModeClamp
#define hipAddressModeMirror cudaAddressModeMirror
#define hipAddressModeBorder cudaAddressModeBorder

// hipTextureFilterMode
#define hipTextureFilterMode cudaTextureFilterMode
#define hipFilterModePoint cudaFilterModePoint
#define hipFilterModeLinear cudaFilterModeLinear

// hipTextureReadMode
#define hipTextureReadMode cudaTextureReadMode
#define hipReadModeElementType cudaReadModeElementType
#define hipReadModeNormalizedFloat cudaReadModeNormalizedFloat

// hipChannelFormatKind
#define hipChannelFormatKind            cudaChannelFormatKind
#define hipChannelFormatKindSigned      cudaChannelFormatKindSigned
#define hipChannelFormatKindUnsigned    cudaChannelFormatKindUnsigned
#define hipChannelFormatKindFloat       cudaChannelFormatKindFloat
#define hipChannelFormatKindNone        cudaChannelFormatKindNone

#define hipSurfaceBoundaryMode cudaSurfaceBoundaryMode
#define hipBoundaryModeZero cudaBoundaryModeZero
#define hipBoundaryModeTrap cudaBoundaryModeTrap
#define hipBoundaryModeClamp cudaBoundaryModeClamp

// hipFuncCache
#define hipFuncCachePreferNone cudaFuncCachePreferNone
#define hipFuncCachePreferShared cudaFuncCachePreferShared
#define hipFuncCachePreferL1 cudaFuncCachePreferL1
#define hipFuncCachePreferEqual cudaFuncCachePreferEqual

// hipResourceType
#define hipResourceType cudaResourceType
#define hipResourceTypeArray cudaResourceTypeArray
#define hipResourceTypeMipmappedArray cudaResourceTypeMipmappedArray
#define hipResourceTypeLinear cudaResourceTypeLinear
#define hipResourceTypePitch2D cudaResourceTypePitch2D
//
// hipErrorNoDevice.


//! Flags that can be used with hipEventCreateWithFlags:
#define hipEventDefault cudaEventDefault
#define hipEventBlockingSync cudaEventBlockingSync
#define hipEventDisableTiming cudaEventDisableTiming
#define hipEventInterprocess cudaEventInterprocess
#define hipEventReleaseToDevice 0 /* no-op on CUDA platform */
#define hipEventReleaseToSystem 0 /* no-op on CUDA platform */


#define hipHostMallocDefault cudaHostAllocDefault
#define hipHostMallocPortable cudaHostAllocPortable
#define hipHostMallocMapped cudaHostAllocMapped
#define hipHostMallocWriteCombined cudaHostAllocWriteCombined
#define hipHostMallocCoherent 0x0
#define hipHostMallocNonCoherent 0x0

#define hipMemAttachGlobal cudaMemAttachGlobal
#define hipMemAttachHost cudaMemAttachHost

#define hipHostRegisterDefault cudaHostRegisterDefault
#define hipHostRegisterPortable cudaHostRegisterPortable
#define hipHostRegisterMapped cudaHostRegisterMapped
#define hipHostRegisterIoMemory cudaHostRegisterIoMemory

#define HIP_LAUNCH_PARAM_BUFFER_POINTER CU_LAUNCH_PARAM_BUFFER_POINTER
#define HIP_LAUNCH_PARAM_BUFFER_SIZE CU_LAUNCH_PARAM_BUFFER_SIZE
#define HIP_LAUNCH_PARAM_END CU_LAUNCH_PARAM_END
#define hipLimitMallocHeapSize cudaLimitMallocHeapSize
#define hipIpcMemLazyEnablePeerAccess cudaIpcMemLazyEnablePeerAccess

// enum CUjit_option redefines
#define hipJitOptionMaxRegisters CU_JIT_MAX_REGISTERS
#define hipJitOptionThreadsPerBlock CU_JIT_THREADS_PER_BLOCK
#define hipJitOptionWallTime CU_JIT_WALL_TIME
#define hipJitOptionInfoLogBuffer CU_JIT_INFO_LOG_BUFFER
#define hipJitOptionInfoLogBufferSizeBytes CU_JIT_INFO_LOG_BUFFER_SIZE_BYTES
#define hipJitOptionErrorLogBuffer CU_JIT_ERROR_LOG_BUFFER
#define hipJitOptionErrorLogBufferSizeBytes CU_JIT_ERROR_LOG_BUFFER_SIZE_BYTES
#define hipJitOptionOptimizationLevel CU_JIT_OPTIMIZATION_LEVEL
#define hipJitOptionTargetFromContext CU_JIT_TARGET_FROM_CUCONTEXT
#define hipJitOptionTarget CU_JIT_TARGET
#define hipJitOptionFallbackStrategy CU_JIT_FALLBACK_STRATEGY
#define hipJitOptionGenerateDebugInfo CU_JIT_GENERATE_DEBUG_INFO
#define hipJitOptionLogVerbose CU_JIT_LOG_VERBOSE
#define hipJitOptionGenerateLineInfo CU_JIT_GENERATE_LINE_INFO
#define hipJitOptionCacheMode CU_JIT_CACHE_MODE
#define hipJitOptionSm3xOpt CU_JIT_NEW_SM3X_OPT
#define hipJitOptionFastCompile CU_JIT_FAST_COMPILE
#define hipJitOptionNumOptions CU_JIT_NUM_OPTIONS

typedef cudaEvent_t hipEvent_t;
typedef cudaStream_t hipStream_t;
typedef cudaIpcEventHandle_t hipIpcEventHandle_t;
typedef cudaIpcMemHandle_t hipIpcMemHandle_t;
typedef enum cudaLimit hipLimit_t;
typedef enum cudaFuncCache hipFuncCache_t;
typedef CUcontext hipCtx_t;
typedef cudaSharedMemConfig hipSharedMemConfig;
typedef CUfunc_cache hipFuncCache;
typedef CUjit_option hipJitOption;
typedef CUdevice hipDevice_t;
typedef CUmodule hipModule_t;
typedef CUfunction hipFunction_t;
typedef CUdeviceptr hipDeviceptr_t;
typedef struct cudaArray hipArray;
typedef struct cudaArray* hipArray_t;
typedef struct cudaArray* hipArray_const_t;
typedef cudaFuncAttributes hipFuncAttributes;
typedef CUfunction_attribute hipFunction_attribute;
#define hip_Memcpy2D CUDA_MEMCPY2D
#define hipMemcpy3DParms cudaMemcpy3DParms
#define hipArrayDefault cudaArrayDefault
#define hipArrayLayered cudaArrayLayered
#define hipArraySurfaceLoadStore cudaArraySurfaceLoadStore
#define hipArrayCubemap cudaArrayCubemap
#define hipArrayTextureGather cudaArrayTextureGather

typedef cudaTextureObject_t hipTextureObject_t;
typedef cudaSurfaceObject_t hipSurfaceObject_t;
#define hipTextureType1D cudaTextureType1D
#define hipTextureType1DLayered cudaTextureType1DLayered
#define hipTextureType2D cudaTextureType2D
#define hipTextureType2DLayered cudaTextureType2DLayered
#define hipTextureType3D cudaTextureType3D
#define hipDeviceMapHost cudaDeviceMapHost

#define hipExtent cudaExtent
#define hipPitchedPtr cudaPitchedPtr
#define make_hipExtent make_cudaExtent
#define make_hipPos make_cudaPos
#define make_hipPitchedPtr make_cudaPitchedPtr
// Flags that can be used with hipStreamCreateWithFlags
#define hipStreamDefault cudaStreamDefault
#define hipStreamNonBlocking cudaStreamNonBlocking

#define hipChannelFormatDesc cudaChannelFormatDesc
#define hipResourceDesc cudaResourceDesc
#define hipTextureDesc cudaTextureDesc
#define hipResourceViewDesc cudaResourceViewDesc
// adding code for hipmemSharedConfig
#define hipSharedMemBankSizeDefault cudaSharedMemBankSizeDefault
#define hipSharedMemBankSizeFourByte cudaSharedMemBankSizeFourByte
#define hipSharedMemBankSizeEightByte cudaSharedMemBankSizeEightByte

//Function Attributes
#define HIP_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK CU_FUNC_ATTRIBUTE_MAX_THREADS_PER_BLOCK
#define HIP_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES CU_FUNC_ATTRIBUTE_SHARED_SIZE_BYTES
#define HIP_FUNC_ATTRIBUTE_CONST_SIZE_BYTES CU_FUNC_ATTRIBUTE_CONST_SIZE_BYTES
#define HIP_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES CU_FUNC_ATTRIBUTE_LOCAL_SIZE_BYTES
#define HIP_FUNC_ATTRIBUTE_NUM_REGS CU_FUNC_ATTRIBUTE_NUM_REGS
#define HIP_FUNC_ATTRIBUTE_PTX_VERSION CU_FUNC_ATTRIBUTE_PTX_VERSION
#define HIP_FUNC_ATTRIBUTE_BINARY_VERSION CU_FUNC_ATTRIBUTE_BINARY_VERSION
#define HIP_FUNC_ATTRIBUTE_CACHE_MODE_CA CU_FUNC_ATTRIBUTE_CACHE_MODE_CA
#define HIP_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES CU_FUNC_ATTRIBUTE_MAX_DYNAMIC_SHARED_SIZE_BYTES
#define HIP_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT CU_FUNC_ATTRIBUTE_PREFERRED_SHARED_MEMORY_CARVEOUT
#define HIP_FUNC_ATTRIBUTE_MAX CU_FUNC_ATTRIBUTE_MAX

inline static hipError_t hipCUDAErrorTohipError(cudaError_t cuError) {
    switch (cuError) {
        case cudaSuccess:
            return hipSuccess;
        case cudaErrorProfilerDisabled:
            return hipErrorProfilerDisabled;
        case cudaErrorProfilerNotInitialized:
            return hipErrorProfilerNotInitialized;
        case cudaErrorProfilerAlreadyStarted:
            return hipErrorProfilerAlreadyStarted;
        case cudaErrorProfilerAlreadyStopped:
            return hipErrorProfilerAlreadyStopped;
        case cudaErrorInsufficientDriver:
            return hipErrorInsufficientDriver;
        case cudaErrorUnsupportedLimit:
            return hipErrorUnsupportedLimit;
        case cudaErrorPeerAccessUnsupported:
            return hipErrorPeerAccessUnsupported;
        case cudaErrorInvalidGraphicsContext:
            return hipErrorInvalidGraphicsContext;
        case cudaErrorSharedObjectSymbolNotFound:
            return hipErrorSharedObjectSymbolNotFound;
        case cudaErrorSharedObjectInitFailed:
            return hipErrorSharedObjectInitFailed;
        case cudaErrorOperatingSystem:
            return hipErrorOperatingSystem;
        case cudaErrorSetOnActiveProcess:
            return hipErrorSetOnActiveProcess;
        case cudaErrorIllegalAddress:
            return hipErrorIllegalAddress;
        case cudaErrorInvalidSymbol:
            return hipErrorInvalidSymbol;
        case cudaErrorMissingConfiguration:
            return hipErrorMissingConfiguration;
        case cudaErrorMemoryAllocation:
            return hipErrorMemoryAllocation;
        case cudaErrorInitializationError:
            return hipErrorInitializationError;
        case cudaErrorLaunchFailure:
            return hipErrorLaunchFailure;
        case cudaErrorPriorLaunchFailure:
            return hipErrorPriorLaunchFailure;
        case cudaErrorLaunchOutOfResources:
            return hipErrorLaunchOutOfResources;
        case cudaErrorInvalidDeviceFunction:
            return hipErrorInvalidDeviceFunction;
        case cudaErrorInvalidConfiguration:
            return hipErrorInvalidConfiguration;
        case cudaErrorInvalidDevice:
            return hipErrorInvalidDevice;
        case cudaErrorInvalidValue:
            return hipErrorInvalidValue;
        case cudaErrorInvalidDevicePointer:
            return hipErrorInvalidDevicePointer;
        case cudaErrorInvalidMemcpyDirection:
            return hipErrorInvalidMemcpyDirection;
        case cudaErrorUnknown:
            return hipErrorUnknown;
        case cudaErrorInvalidResourceHandle:
            return hipErrorInvalidResourceHandle;
        case cudaErrorNotReady:
            return hipErrorNotReady;
        case cudaErrorNoDevice:
            return hipErrorNoDevice;
        case cudaErrorPeerAccessAlreadyEnabled:
            return hipErrorPeerAccessAlreadyEnabled;
        case cudaErrorPeerAccessNotEnabled:
            return hipErrorPeerAccessNotEnabled;
        case cudaErrorHostMemoryAlreadyRegistered:
            return hipErrorHostMemoryAlreadyRegistered;
        case cudaErrorHostMemoryNotRegistered:
            return hipErrorHostMemoryNotRegistered;
        case cudaErrorMapBufferObjectFailed:
            return hipErrorMapBufferObjectFailed;
        case cudaErrorAssert:
            return hipErrorAssert;
        case cudaErrorNotSupported:
            return hipErrorNotSupported;
        default:
            return hipErrorUnknown;  // Note - translated error.
    }
}

inline static hipError_t hipCUResultTohipError(CUresult cuError) {  // TODO Populate further
    switch (cuError) {
        case CUDA_SUCCESS:
            return hipSuccess;
        case CUDA_ERROR_OUT_OF_MEMORY:
            return hipErrorMemoryAllocation;
        case CUDA_ERROR_INVALID_VALUE:
            return hipErrorInvalidValue;
        case CUDA_ERROR_INVALID_DEVICE:
            return hipErrorInvalidDevice;
        case CUDA_ERROR_DEINITIALIZED:
            return hipErrorDeinitialized;
        case CUDA_ERROR_NO_DEVICE:
            return hipErrorNoDevice;
        case CUDA_ERROR_INVALID_CONTEXT:
            return hipErrorInvalidContext;
        case CUDA_ERROR_NOT_INITIALIZED:
            return hipErrorNotInitialized;
        default:
            return hipErrorUnknown;  // Note - translated error.
    }
}

// TODO   match the error enum names of hip and cuda
inline static cudaError_t hipErrorToCudaError(hipError_t hError) {
    switch (hError) {
        case hipSuccess:
            return cudaSuccess;
        case hipErrorMemoryAllocation:
            return cudaErrorMemoryAllocation;
        case hipErrorLaunchOutOfResources:
            return cudaErrorLaunchOutOfResources;
        case hipErrorInvalidValue:
            return cudaErrorInvalidValue;
        case hipErrorInvalidResourceHandle:
            return cudaErrorInvalidResourceHandle;
        case hipErrorInvalidDevice:
            return cudaErrorInvalidDevice;
        case hipErrorInvalidMemcpyDirection:
            return cudaErrorInvalidMemcpyDirection;
        case hipErrorInvalidDevicePointer:
            return cudaErrorInvalidDevicePointer;
        case hipErrorInitializationError:
            return cudaErrorInitializationError;
        case hipErrorNoDevice:
            return cudaErrorNoDevice;
        case hipErrorNotReady:
            return cudaErrorNotReady;
        case hipErrorUnknown:
            return cudaErrorUnknown;
        case hipErrorPeerAccessNotEnabled:
            return cudaErrorPeerAccessNotEnabled;
        case hipErrorPeerAccessAlreadyEnabled:
            return cudaErrorPeerAccessAlreadyEnabled;
        case hipErrorRuntimeMemory:
            return cudaErrorUnknown;  // Does not exist in CUDA
        case hipErrorRuntimeOther:
            return cudaErrorUnknown;  // Does not exist in CUDA
        case hipErrorHostMemoryAlreadyRegistered:
            return cudaErrorHostMemoryAlreadyRegistered;
        case hipErrorHostMemoryNotRegistered:
            return cudaErrorHostMemoryNotRegistered;
        case hipErrorTbd:
            return cudaErrorUnknown;  // Note - translated error.
        default:
            return cudaErrorUnknown;  // Note - translated error.
    }
}

inline static enum cudaMemcpyKind hipMemcpyKindToCudaMemcpyKind(hipMemcpyKind kind) {
    switch (kind) {
        case hipMemcpyHostToHost:
            return cudaMemcpyHostToHost;
        case hipMemcpyHostToDevice:
            return cudaMemcpyHostToDevice;
        case hipMemcpyDeviceToHost:
            return cudaMemcpyDeviceToHost;
        case hipMemcpyDeviceToDevice:
            return cudaMemcpyDeviceToDevice;
        default:
            return cudaMemcpyDefault;
    }
}

inline static cudaTextureAddressMode hipTextureAddressModeToCudaTextureAddressMode(
    hipTextureAddressMode kind) {
    switch (kind) {
        case hipAddressModeWrap:
            return cudaAddressModeWrap;
        case hipAddressModeClamp:
            return cudaAddressModeClamp;
        case hipAddressModeMirror:
            return cudaAddressModeMirror;
        case hipAddressModeBorder:
            return cudaAddressModeBorder;
        default:
            return cudaAddressModeWrap;
    }
}

inline static cudaTextureFilterMode hipTextureFilterModeToCudaTextureFilterMode(
    hipTextureFilterMode kind) {
    switch (kind) {
        case hipFilterModePoint:
            return cudaFilterModePoint;
        case hipFilterModeLinear:
            return cudaFilterModeLinear;
        default:
            return cudaFilterModePoint;
    }
}

inline static cudaTextureReadMode hipTextureReadModeToCudaTextureReadMode(hipTextureReadMode kind) {
    switch (kind) {
        case hipReadModeElementType:
            return cudaReadModeElementType;
        case hipReadModeNormalizedFloat:
            return cudaReadModeNormalizedFloat;
        default:
            return cudaReadModeElementType;
    }
}

inline static cudaChannelFormatKind hipChannelFormatKindToCudaChannelFormatKind(
    hipChannelFormatKind kind) {
    switch (kind) {
        case hipChannelFormatKindSigned:
            return cudaChannelFormatKindSigned;
        case hipChannelFormatKindUnsigned:
            return cudaChannelFormatKindUnsigned;
        case hipChannelFormatKindFloat:
            return cudaChannelFormatKindFloat;
        case hipChannelFormatKindNone:
            return cudaChannelFormatKindNone;
        default:
            return cudaChannelFormatKindNone;
    }
}

/**
 * Stream CallBack struct
 */
#define HIPRT_CB CUDART_CB
typedef void(HIPRT_CB* hipStreamCallback_t)(hipStream_t stream, hipError_t status, void* userData);
inline static hipError_t hipInit(unsigned int flags) {
    return hipCUResultTohipError(cuInit(flags));
}

inline static hipError_t hipDeviceReset() { return hipCUDAErrorTohipError(cudaDeviceReset()); }

inline static hipError_t hipGetLastError() { return hipCUDAErrorTohipError(cudaGetLastError()); }

inline static hipError_t hipPeekAtLastError() {
    return hipCUDAErrorTohipError(cudaPeekAtLastError());
}

inline static hipError_t hipMalloc(void** ptr, size_t size) {
    return hipCUDAErrorTohipError(cudaMalloc(ptr, size));
}

inline static hipError_t hipMallocPitch(void** ptr, size_t* pitch, size_t width, size_t height) {
    return hipCUDAErrorTohipError(cudaMallocPitch(ptr, pitch, width, height));
}

inline static hipError_t hipMalloc3D(hipPitchedPtr* pitchedDevPtr, hipExtent extent) {
    return hipCUDAErrorTohipError(cudaMalloc3D(pitchedDevPtr, extent));
}

inline static hipError_t hipFree(void* ptr) { return hipCUDAErrorTohipError(cudaFree(ptr)); }

inline static hipError_t hipMallocHost(void** ptr, size_t size)
    __attribute__((deprecated("use hipHostMalloc instead")));
inline static hipError_t hipMallocHost(void** ptr, size_t size) {
    return hipCUDAErrorTohipError(cudaMallocHost(ptr, size));
}

inline static hipError_t hipHostAlloc(void** ptr, size_t size, unsigned int flags)
    __attribute__((deprecated("use hipHostMalloc instead")));
inline static hipError_t hipHostAlloc(void** ptr, size_t size, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaHostAlloc(ptr, size, flags));
}

inline static hipError_t hipHostMalloc(void** ptr, size_t size, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaHostAlloc(ptr, size, flags));
}

inline static hipError_t hipMallocManaged(void** ptr, size_t size, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaMallocManaged(ptr, size, flags));
}

inline static hipError_t hipMallocArray(hipArray** array, const struct hipChannelFormatDesc* desc,
                                        size_t width, size_t height,
                                        unsigned int flags __dparm(hipArrayDefault)) {
    return hipCUDAErrorTohipError(cudaMallocArray(array, desc, width, height, flags));
}

inline static hipError_t hipMalloc3DArray(hipArray** array, const struct hipChannelFormatDesc* desc,
                            struct hipExtent extent, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaMalloc3DArray(array, desc, extent, flags));
}

inline static hipError_t hipFreeArray(hipArray* array) {
    return hipCUDAErrorTohipError(cudaFreeArray(array));
}

inline static hipError_t hipHostGetDevicePointer(void** devPtr, void* hostPtr, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaHostGetDevicePointer(devPtr, hostPtr, flags));
}

inline static hipError_t hipHostGetFlags(unsigned int* flagsPtr, void* hostPtr) {
    return hipCUDAErrorTohipError(cudaHostGetFlags(flagsPtr, hostPtr));
}

inline static hipError_t hipHostRegister(void* ptr, size_t size, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaHostRegister(ptr, size, flags));
}

inline static hipError_t hipHostUnregister(void* ptr) {
    return hipCUDAErrorTohipError(cudaHostUnregister(ptr));
}

inline static hipError_t hipFreeHost(void* ptr)
    __attribute__((deprecated("use hipHostFree instead")));
inline static hipError_t hipFreeHost(void* ptr) {
    return hipCUDAErrorTohipError(cudaFreeHost(ptr));
}

inline static hipError_t hipHostFree(void* ptr) {
    return hipCUDAErrorTohipError(cudaFreeHost(ptr));
}

inline static hipError_t hipSetDevice(int device) {
    return hipCUDAErrorTohipError(cudaSetDevice(device));
}

inline static hipError_t hipChooseDevice(int* device, const hipDeviceProp_t* prop) {
    struct cudaDeviceProp cdprop;
    memset(&cdprop, 0x0, sizeof(struct cudaDeviceProp));
    cdprop.major = prop->major;
    cdprop.minor = prop->minor;
    cdprop.totalGlobalMem = prop->totalGlobalMem;
    cdprop.sharedMemPerBlock = prop->sharedMemPerBlock;
    cdprop.regsPerBlock = prop->regsPerBlock;
    cdprop.warpSize = prop->warpSize;
    cdprop.maxThreadsPerBlock = prop->maxThreadsPerBlock;
    cdprop.clockRate = prop->clockRate;
    cdprop.totalConstMem = prop->totalConstMem;
    cdprop.multiProcessorCount = prop->multiProcessorCount;
    cdprop.l2CacheSize = prop->l2CacheSize;
    cdprop.maxThreadsPerMultiProcessor = prop->maxThreadsPerMultiProcessor;
    cdprop.computeMode = prop->computeMode;
    cdprop.canMapHostMemory = prop->canMapHostMemory;
    cdprop.memoryClockRate = prop->memoryClockRate;
    cdprop.memoryBusWidth = prop->memoryBusWidth;
    return hipCUDAErrorTohipError(cudaChooseDevice(device, &cdprop));
}

inline static hipError_t hipMemcpyHtoD(hipDeviceptr_t dst, void* src, size_t size) {
    return hipCUResultTohipError(cuMemcpyHtoD(dst, src, size));
}

inline static hipError_t hipMemcpyDtoH(void* dst, hipDeviceptr_t src, size_t size) {
    return hipCUResultTohipError(cuMemcpyDtoH(dst, src, size));
}

inline static hipError_t hipMemcpyDtoD(hipDeviceptr_t dst, hipDeviceptr_t src, size_t size) {
    return hipCUResultTohipError(cuMemcpyDtoD(dst, src, size));
}

inline static hipError_t hipMemcpyHtoDAsync(hipDeviceptr_t dst, void* src, size_t size,
                                            hipStream_t stream) {
    return hipCUResultTohipError(cuMemcpyHtoDAsync(dst, src, size, stream));
}

inline static hipError_t hipMemcpyDtoHAsync(void* dst, hipDeviceptr_t src, size_t size,
                                            hipStream_t stream) {
    return hipCUResultTohipError(cuMemcpyDtoHAsync(dst, src, size, stream));
}

inline static hipError_t hipMemcpyDtoDAsync(hipDeviceptr_t dst, hipDeviceptr_t src, size_t size,
                                            hipStream_t stream) {
    return hipCUResultTohipError(cuMemcpyDtoDAsync(dst, src, size, stream));
}

inline static hipError_t hipMemcpy(void* dst, const void* src, size_t sizeBytes,
                                   hipMemcpyKind copyKind) {
    return hipCUDAErrorTohipError(
        cudaMemcpy(dst, src, sizeBytes, hipMemcpyKindToCudaMemcpyKind(copyKind)));
}


inline static hipError_t hipMemcpyAsync(void* dst, const void* src, size_t sizeBytes,
                                        hipMemcpyKind copyKind, hipStream_t stream __dparm(0)) {
    return hipCUDAErrorTohipError(
        cudaMemcpyAsync(dst, src, sizeBytes, hipMemcpyKindToCudaMemcpyKind(copyKind), stream));
}

inline static hipError_t hipMemcpyToSymbol(const void* symbol, const void* src, size_t sizeBytes,
                                           size_t offset __dparm(0),
                                           hipMemcpyKind copyType __dparm(hipMemcpyHostToDevice)) {
    return hipCUDAErrorTohipError(cudaMemcpyToSymbol(symbol, src, sizeBytes, offset,
                                                     hipMemcpyKindToCudaMemcpyKind(copyType)));
}

inline static hipError_t hipMemcpyToSymbolAsync(const void* symbol, const void* src,
                                                size_t sizeBytes, size_t offset,
                                                hipMemcpyKind copyType,
                                                hipStream_t stream __dparm(0)) {
    return hipCUDAErrorTohipError(cudaMemcpyToSymbolAsync(
        symbol, src, sizeBytes, offset, hipMemcpyKindToCudaMemcpyKind(copyType), stream));
}

inline static hipError_t hipMemcpyFromSymbol(void* dst, const void* symbolName, size_t sizeBytes,
                                             size_t offset __dparm(0),
                                             hipMemcpyKind kind __dparm(hipMemcpyDeviceToHost)) {
    return hipCUDAErrorTohipError(cudaMemcpyFromSymbol(dst, symbolName, sizeBytes, offset,
                                                       hipMemcpyKindToCudaMemcpyKind(kind)));
}

inline static hipError_t hipMemcpyFromSymbolAsync(void* dst, const void* symbolName,
                                                  size_t sizeBytes, size_t offset,
                                                  hipMemcpyKind kind,
                                                  hipStream_t stream __dparm(0)) {
    return hipCUDAErrorTohipError(cudaMemcpyFromSymbolAsync(
        dst, symbolName, sizeBytes, offset, hipMemcpyKindToCudaMemcpyKind(kind), stream));
}

inline static hipError_t hipGetSymbolAddress(void** devPtr, const void* symbolName) {
    return hipCUDAErrorTohipError(cudaGetSymbolAddress(devPtr, symbolName));
}

inline static hipError_t hipGetSymbolSize(size_t* size, const void* symbolName) {
    return hipCUDAErrorTohipError(cudaGetSymbolSize(size, symbolName));
}

inline static hipError_t hipMemcpy2D(void* dst, size_t dpitch, const void* src, size_t spitch,
                                     size_t width, size_t height, hipMemcpyKind kind) {
    return hipCUDAErrorTohipError(
        cudaMemcpy2D(dst, dpitch, src, spitch, width, height, hipMemcpyKindToCudaMemcpyKind(kind)));
}

inline static hipError_t hipMemcpyParam2D(const hip_Memcpy2D* pCopy) {
  return hipCUResultTohipError(cuMemcpy2D(pCopy));
}

inline static hipError_t hipMemcpyParam2DAsync(const hip_Memcpy2D* pCopy, hipStream_t stream __dparm(0)) {
  return hipCUResultTohipError(cuMemcpy2DAsync(pCopy, stream));
}

inline static hipError_t hipMemcpy3D(const struct hipMemcpy3DParms *p)
{
    return hipCUDAErrorTohipError(cudaMemcpy3D(p));
}

inline static hipError_t hipMemcpy3DAsync(const struct hipMemcpy3DParms *p, hipStream_t stream)
{
    return hipCUDAErrorTohipError(cudaMemcpy3DAsync(p, stream));
}

inline static hipError_t hipMemcpy2DAsync(void* dst, size_t dpitch, const void* src, size_t spitch,
                                          size_t width, size_t height, hipMemcpyKind kind,
                                          hipStream_t stream) {
    return hipCUDAErrorTohipError(cudaMemcpy2DAsync(dst, dpitch, src, spitch, width, height,
                                                    hipMemcpyKindToCudaMemcpyKind(kind), stream));
}

inline static hipError_t hipMemcpy2DToArray(hipArray* dst, size_t wOffset, size_t hOffset,
                                            const void* src, size_t spitch, size_t width,
                                            size_t height, hipMemcpyKind kind) {
    return hipCUDAErrorTohipError(cudaMemcpy2DToArray(dst, wOffset, hOffset, src, spitch, width,
                                                      height, hipMemcpyKindToCudaMemcpyKind(kind)));
}

inline static hipError_t hipMemcpyToArray(hipArray* dst, size_t wOffset, size_t hOffset,
                                          const void* src, size_t count, hipMemcpyKind kind) {
    return hipCUDAErrorTohipError(
        cudaMemcpyToArray(dst, wOffset, hOffset, src, count, hipMemcpyKindToCudaMemcpyKind(kind)));
}

inline static hipError_t hipMemcpyFromArray(void* dst, hipArray_const_t srcArray, size_t wOffset,
                                            size_t hOffset, size_t count, hipMemcpyKind kind) {
    return hipCUDAErrorTohipError(cudaMemcpyFromArray(dst, srcArray, wOffset, hOffset, count,
                                                      hipMemcpyKindToCudaMemcpyKind(kind)));
}

inline static hipError_t hipMemcpyAtoH(void* dst, hipArray* srcArray, size_t srcOffset,
                                       size_t count) {
    return hipCUResultTohipError(cuMemcpyAtoH(dst, (CUarray)srcArray, srcOffset, count));
}

inline static hipError_t hipMemcpyHtoA(hipArray* dstArray, size_t dstOffset, const void* srcHost,
                                       size_t count) {
    return hipCUResultTohipError(cuMemcpyHtoA((CUarray)dstArray, dstOffset, srcHost, count));
}

inline static hipError_t hipDeviceSynchronize() {
    return hipCUDAErrorTohipError(cudaDeviceSynchronize());
}

inline static hipError_t hipDeviceGetCacheConfig(hipFuncCache_t* pCacheConfig) {
    return hipCUDAErrorTohipError(cudaDeviceGetCacheConfig(pCacheConfig));
}

inline static hipError_t hipDeviceSetCacheConfig(hipFuncCache_t cacheConfig) {
    return hipCUDAErrorTohipError(cudaDeviceSetCacheConfig(cacheConfig));
}

inline static const char* hipGetErrorString(hipError_t error) {
    return cudaGetErrorString(hipErrorToCudaError(error));
}

inline static const char* hipGetErrorName(hipError_t error) {
    return cudaGetErrorName(hipErrorToCudaError(error));
}

inline static hipError_t hipGetDeviceCount(int* count) {
    return hipCUDAErrorTohipError(cudaGetDeviceCount(count));
}

inline static hipError_t hipGetDevice(int* device) {
    return hipCUDAErrorTohipError(cudaGetDevice(device));
}

inline static hipError_t hipIpcCloseMemHandle(void* devPtr) {
    return hipCUDAErrorTohipError(cudaIpcCloseMemHandle(devPtr));
}

inline static hipError_t hipIpcGetEventHandle(hipIpcEventHandle_t* handle, hipEvent_t event) {
    return hipCUDAErrorTohipError(cudaIpcGetEventHandle(handle, event));
}

inline static hipError_t hipIpcGetMemHandle(hipIpcMemHandle_t* handle, void* devPtr) {
    return hipCUDAErrorTohipError(cudaIpcGetMemHandle(handle, devPtr));
}

inline static hipError_t hipIpcOpenEventHandle(hipEvent_t* event, hipIpcEventHandle_t handle) {
    return hipCUDAErrorTohipError(cudaIpcOpenEventHandle(event, handle));
}

inline static hipError_t hipIpcOpenMemHandle(void** devPtr, hipIpcMemHandle_t handle,
                                             unsigned int flags) {
    return hipCUDAErrorTohipError(cudaIpcOpenMemHandle(devPtr, handle, flags));
}

inline static hipError_t hipMemset(void* devPtr, int value, size_t count) {
    return hipCUDAErrorTohipError(cudaMemset(devPtr, value, count));
}

inline static hipError_t hipMemsetD32(hipDeviceptr_t devPtr, int value, size_t count) {
    return hipCUResultTohipError(cuMemsetD32(devPtr, value, count));
}

inline static hipError_t hipMemsetAsync(void* devPtr, int value, size_t count,
                                        hipStream_t stream __dparm(0)) {
    return hipCUDAErrorTohipError(cudaMemsetAsync(devPtr, value, count, stream));
}

inline static hipError_t hipMemsetD32Async(hipDeviceptr_t devPtr, int value, size_t count,
                                           hipStream_t stream __dparm(0)) {
    return hipCUResultTohipError(cuMemsetD32Async(devPtr, value, count, stream));
}

inline static hipError_t hipMemsetD8(hipDeviceptr_t dest, unsigned char value, size_t sizeBytes) {
    return hipCUResultTohipError(cuMemsetD8(dest, value, sizeBytes));
}

inline static hipError_t hipMemset2D(void* dst, size_t pitch, int value, size_t width, size_t height) {
    return hipCUDAErrorTohipError(cudaMemset2D(dst, pitch, value, width, height));
}

inline static hipError_t hipMemset2DAsync(void* dst, size_t pitch, int value, size_t width, size_t height, hipStream_t stream __dparm(0)) {
    return hipCUDAErrorTohipError(cudaMemset2DAsync(dst, pitch, value, width, height, stream));
}

inline static hipError_t hipMemset3D(hipPitchedPtr pitchedDevPtr, int  value, hipExtent extent ){
    return hipCUDAErrorTohipError(cudaMemset3D(pitchedDevPtr, value, extent));
}

inline static hipError_t hipMemset3DAsync(hipPitchedPtr pitchedDevPtr, int  value, hipExtent extent, hipStream_t stream __dparm(0) ){
    return hipCUDAErrorTohipError(cudaMemset3DAsync(pitchedDevPtr, value, extent, stream));
}

inline static hipError_t hipGetDeviceProperties(hipDeviceProp_t* p_prop, int device) {
    struct cudaDeviceProp cdprop;
    cudaError_t cerror;
    cerror = cudaGetDeviceProperties(&cdprop, device);

    strncpy(p_prop->name, cdprop.name, 256);
    p_prop->totalGlobalMem = cdprop.totalGlobalMem;
    p_prop->sharedMemPerBlock = cdprop.sharedMemPerBlock;
    p_prop->regsPerBlock = cdprop.regsPerBlock;
    p_prop->warpSize = cdprop.warpSize;
    p_prop->maxThreadsPerBlock = cdprop.maxThreadsPerBlock;
    for (int i = 0; i < 3; i++) {
        p_prop->maxThreadsDim[i] = cdprop.maxThreadsDim[i];
        p_prop->maxGridSize[i] = cdprop.maxGridSize[i];
    }
    p_prop->clockRate = cdprop.clockRate;
    p_prop->memoryClockRate = cdprop.memoryClockRate;
    p_prop->memoryBusWidth = cdprop.memoryBusWidth;
    p_prop->totalConstMem = cdprop.totalConstMem;
    p_prop->major = cdprop.major;
    p_prop->minor = cdprop.minor;
    p_prop->multiProcessorCount = cdprop.multiProcessorCount;
    p_prop->l2CacheSize = cdprop.l2CacheSize;
    p_prop->maxThreadsPerMultiProcessor = cdprop.maxThreadsPerMultiProcessor;
    p_prop->computeMode = cdprop.computeMode;
    p_prop->clockInstructionRate = cdprop.clockRate; // Same as clock-rate:

    int ccVers = p_prop->major * 100 + p_prop->minor * 10;
    p_prop->arch.hasGlobalInt32Atomics = (ccVers >= 110);
    p_prop->arch.hasGlobalFloatAtomicExch = (ccVers >= 110);
    p_prop->arch.hasSharedInt32Atomics = (ccVers >= 120);
    p_prop->arch.hasSharedFloatAtomicExch = (ccVers >= 120);
    p_prop->arch.hasFloatAtomicAdd = (ccVers >= 200);
    p_prop->arch.hasGlobalInt64Atomics = (ccVers >= 120);
    p_prop->arch.hasSharedInt64Atomics = (ccVers >= 110);
    p_prop->arch.hasDoubles = (ccVers >= 130);
    p_prop->arch.hasWarpVote = (ccVers >= 120);
    p_prop->arch.hasWarpBallot = (ccVers >= 200);
    p_prop->arch.hasWarpShuffle = (ccVers >= 300);
    p_prop->arch.hasFunnelShift = (ccVers >= 350);
    p_prop->arch.hasThreadFenceSystem = (ccVers >= 200);
    p_prop->arch.hasSyncThreadsExt = (ccVers >= 200);
    p_prop->arch.hasSurfaceFuncs = (ccVers >= 200);
    p_prop->arch.has3dGrid = (ccVers >= 200);
    p_prop->arch.hasDynamicParallelism = (ccVers >= 350);

    p_prop->concurrentKernels = cdprop.concurrentKernels;
    p_prop->pciDomainID = cdprop.pciDomainID;
    p_prop->pciBusID = cdprop.pciBusID;
    p_prop->pciDeviceID = cdprop.pciDeviceID;
    p_prop->maxSharedMemoryPerMultiProcessor = cdprop.sharedMemPerMultiprocessor;
    p_prop->isMultiGpuBoard = cdprop.isMultiGpuBoard;
    p_prop->canMapHostMemory = cdprop.canMapHostMemory;
    p_prop->gcnArch = 0; // Not a GCN arch
    p_prop->integrated = cdprop.integrated;
    p_prop->cooperativeLaunch = cdprop.cooperativeLaunch;
    p_prop->cooperativeMultiDeviceLaunch = cdprop.cooperativeMultiDeviceLaunch;

    p_prop->maxTexture1D    = cdprop.maxTexture1D;
    p_prop->maxTexture2D[0] = cdprop.maxTexture2D[0];
    p_prop->maxTexture2D[1] = cdprop.maxTexture2D[1];
    p_prop->maxTexture3D[0] = cdprop.maxTexture3D[0];
    p_prop->maxTexture3D[1] = cdprop.maxTexture3D[1];
    p_prop->maxTexture3D[2] = cdprop.maxTexture3D[2];

    return hipCUDAErrorTohipError(cerror);
}

inline static hipError_t hipDeviceGetAttribute(int* pi, hipDeviceAttribute_t attr, int device) {
    enum cudaDeviceAttr cdattr;
    cudaError_t cerror;

    switch (attr) {
        case hipDeviceAttributeMaxThreadsPerBlock:
            cdattr = cudaDevAttrMaxThreadsPerBlock;
            break;
        case hipDeviceAttributeMaxBlockDimX:
            cdattr = cudaDevAttrMaxBlockDimX;
            break;
        case hipDeviceAttributeMaxBlockDimY:
            cdattr = cudaDevAttrMaxBlockDimY;
            break;
        case hipDeviceAttributeMaxBlockDimZ:
            cdattr = cudaDevAttrMaxBlockDimZ;
            break;
        case hipDeviceAttributeMaxGridDimX:
            cdattr = cudaDevAttrMaxGridDimX;
            break;
        case hipDeviceAttributeMaxGridDimY:
            cdattr = cudaDevAttrMaxGridDimY;
            break;
        case hipDeviceAttributeMaxGridDimZ:
            cdattr = cudaDevAttrMaxGridDimZ;
            break;
        case hipDeviceAttributeMaxSharedMemoryPerBlock:
            cdattr = cudaDevAttrMaxSharedMemoryPerBlock;
            break;
        case hipDeviceAttributeTotalConstantMemory:
            cdattr = cudaDevAttrTotalConstantMemory;
            break;
        case hipDeviceAttributeWarpSize:
            cdattr = cudaDevAttrWarpSize;
            break;
        case hipDeviceAttributeMaxRegistersPerBlock:
            cdattr = cudaDevAttrMaxRegistersPerBlock;
            break;
        case hipDeviceAttributeClockRate:
            cdattr = cudaDevAttrClockRate;
            break;
        case hipDeviceAttributeMemoryClockRate:
            cdattr = cudaDevAttrMemoryClockRate;
            break;
        case hipDeviceAttributeMemoryBusWidth:
            cdattr = cudaDevAttrGlobalMemoryBusWidth;
            break;
        case hipDeviceAttributeMultiprocessorCount:
            cdattr = cudaDevAttrMultiProcessorCount;
            break;
        case hipDeviceAttributeComputeMode:
            cdattr = cudaDevAttrComputeMode;
            break;
        case hipDeviceAttributeL2CacheSize:
            cdattr = cudaDevAttrL2CacheSize;
            break;
        case hipDeviceAttributeMaxThreadsPerMultiProcessor:
            cdattr = cudaDevAttrMaxThreadsPerMultiProcessor;
            break;
        case hipDeviceAttributeComputeCapabilityMajor:
            cdattr = cudaDevAttrComputeCapabilityMajor;
            break;
        case hipDeviceAttributeComputeCapabilityMinor:
            cdattr = cudaDevAttrComputeCapabilityMinor;
            break;
        case hipDeviceAttributeConcurrentKernels:
            cdattr = cudaDevAttrConcurrentKernels;
            break;
        case hipDeviceAttributePciBusId:
            cdattr = cudaDevAttrPciBusId;
            break;
        case hipDeviceAttributePciDeviceId:
            cdattr = cudaDevAttrPciDeviceId;
            break;
        case hipDeviceAttributeMaxSharedMemoryPerMultiprocessor:
            cdattr = cudaDevAttrMaxSharedMemoryPerMultiprocessor;
            break;
        case hipDeviceAttributeIsMultiGpuBoard:
            cdattr = cudaDevAttrIsMultiGpuBoard;
            break;
        case hipDeviceAttributeIntegrated:
            cdattr = cudaDevAttrIntegrated;
            break;
        case hipDeviceAttributeMaxTexture1DWidth:
            cdattr = cudaDevAttrMaxTexture1DWidth;
            break;
        case hipDeviceAttributeMaxTexture2DWidth:
            cdattr = cudaDevAttrMaxTexture2DWidth;
            break;
        case hipDeviceAttributeMaxTexture2DHeight:
            cdattr = cudaDevAttrMaxTexture2DHeight;
            break;
        case hipDeviceAttributeMaxTexture3DWidth:
            cdattr = cudaDevAttrMaxTexture3DWidth;
            break;
        case hipDeviceAttributeMaxTexture3DHeight:
            cdattr = cudaDevAttrMaxTexture3DHeight;
            break;
        case hipDeviceAttributeMaxTexture3DDepth:
            cdattr = cudaDevAttrMaxTexture3DDepth;
            break;
        default:
            cerror = cudaErrorInvalidValue;
            break;
    }

    cerror = cudaDeviceGetAttribute(pi, cdattr, device);

    return hipCUDAErrorTohipError(cerror);
}

inline static hipError_t hipOccupancyMaxActiveBlocksPerMultiprocessor(int* numBlocks,
                                                                      const void* func,
                                                                      int blockSize,
                                                                      size_t dynamicSMemSize) {
    cudaError_t cerror;
    cerror =
        cudaOccupancyMaxActiveBlocksPerMultiprocessor(numBlocks, func, blockSize, dynamicSMemSize);
    return hipCUDAErrorTohipError(cerror);
}

inline static hipError_t hipPointerGetAttributes(hipPointerAttribute_t* attributes, const void* ptr) {
    struct cudaPointerAttributes cPA;
    hipError_t err = hipCUDAErrorTohipError(cudaPointerGetAttributes(&cPA, ptr));
    if (err == hipSuccess) {
        switch (cPA.memoryType) {
            case cudaMemoryTypeDevice:
                attributes->memoryType = hipMemoryTypeDevice;
                break;
            case cudaMemoryTypeHost:
                attributes->memoryType = hipMemoryTypeHost;
                break;
            default:
                return hipErrorUnknown;
        }
        attributes->device = cPA.device;
        attributes->devicePointer = cPA.devicePointer;
        attributes->hostPointer = cPA.hostPointer;
        attributes->isManaged = 0;
        attributes->allocationFlags = 0;
    }
    return err;
}


inline static hipError_t hipMemGetInfo(size_t* free, size_t* total) {
    return hipCUDAErrorTohipError(cudaMemGetInfo(free, total));
}

inline static hipError_t hipEventCreate(hipEvent_t* event) {
    return hipCUDAErrorTohipError(cudaEventCreate(event));
}

inline static hipError_t hipEventRecord(hipEvent_t event, hipStream_t stream __dparm(NULL)) {
    return hipCUDAErrorTohipError(cudaEventRecord(event, stream));
}

inline static hipError_t hipEventSynchronize(hipEvent_t event) {
    return hipCUDAErrorTohipError(cudaEventSynchronize(event));
}

inline static hipError_t hipEventElapsedTime(float* ms, hipEvent_t start, hipEvent_t stop) {
    return hipCUDAErrorTohipError(cudaEventElapsedTime(ms, start, stop));
}

inline static hipError_t hipEventDestroy(hipEvent_t event) {
    return hipCUDAErrorTohipError(cudaEventDestroy(event));
}


inline static hipError_t hipStreamCreateWithFlags(hipStream_t* stream, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaStreamCreateWithFlags(stream, flags));
}

inline static hipError_t hipStreamCreateWithPriority(hipStream_t* stream, unsigned int flags, int priority) {
    return hipCUDAErrorTohipError(cudaStreamCreateWithPriority(stream, flags, priority));
}

inline static hipError_t hipDeviceGetStreamPriorityRange(int* leastPriority, int* greatestPriority) {
    return hipCUDAErrorTohipError(cudaDeviceGetStreamPriorityRange(leastPriority, greatestPriority));
}

inline static hipError_t hipStreamCreate(hipStream_t* stream) {
    return hipCUDAErrorTohipError(cudaStreamCreate(stream));
}

inline static hipError_t hipStreamSynchronize(hipStream_t stream) {
    return hipCUDAErrorTohipError(cudaStreamSynchronize(stream));
}

inline static hipError_t hipStreamDestroy(hipStream_t stream) {
    return hipCUDAErrorTohipError(cudaStreamDestroy(stream));
}

inline static hipError_t hipStreamGetFlags(hipStream_t stream, unsigned int *flags) {
    return hipCUDAErrorTohipError(cudaStreamGetFlags(stream, flags));
}

inline static hipError_t hipStreamGetPriority(hipStream_t stream, int *priority) {
    return hipCUDAErrorTohipError(cudaStreamGetPriority(stream, priority));
}

inline static hipError_t hipStreamWaitEvent(hipStream_t stream, hipEvent_t event,
                                            unsigned int flags) {
    return hipCUDAErrorTohipError(cudaStreamWaitEvent(stream, event, flags));
}

inline static hipError_t hipStreamQuery(hipStream_t stream) {
    return hipCUDAErrorTohipError(cudaStreamQuery(stream));
}

inline static hipError_t hipStreamAddCallback(hipStream_t stream, hipStreamCallback_t callback,
                                              void* userData, unsigned int flags) {
    return hipCUDAErrorTohipError(
        cudaStreamAddCallback(stream, (cudaStreamCallback_t)callback, userData, flags));
}

inline static hipError_t hipDriverGetVersion(int* driverVersion) {
    cudaError_t err = cudaDriverGetVersion(driverVersion);

    // Override driver version to match version reported on HCC side.
    *driverVersion = 4;

    return hipCUDAErrorTohipError(err);
}

inline static hipError_t hipRuntimeGetVersion(int* runtimeVersion) {
    return hipCUDAErrorTohipError(cudaRuntimeGetVersion(runtimeVersion));
}

inline static hipError_t hipDeviceCanAccessPeer(int* canAccessPeer, int device, int peerDevice) {
    return hipCUDAErrorTohipError(cudaDeviceCanAccessPeer(canAccessPeer, device, peerDevice));
}

inline static hipError_t hipDeviceDisablePeerAccess(int peerDevice) {
    return hipCUDAErrorTohipError(cudaDeviceDisablePeerAccess(peerDevice));
}

inline static hipError_t hipDeviceEnablePeerAccess(int peerDevice, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaDeviceEnablePeerAccess(peerDevice, flags));
}

inline static hipError_t hipCtxDisablePeerAccess(hipCtx_t peerCtx) {
    return hipCUResultTohipError(cuCtxDisablePeerAccess(peerCtx));
}

inline static hipError_t hipCtxEnablePeerAccess(hipCtx_t peerCtx, unsigned int flags) {
    return hipCUResultTohipError(cuCtxEnablePeerAccess(peerCtx, flags));
}

inline static hipError_t hipDevicePrimaryCtxGetState(hipDevice_t dev, unsigned int* flags,
                                                     int* active) {
    return hipCUResultTohipError(cuDevicePrimaryCtxGetState(dev, flags, active));
}

inline static hipError_t hipDevicePrimaryCtxRelease(hipDevice_t dev) {
    return hipCUResultTohipError(cuDevicePrimaryCtxRelease(dev));
}

inline static hipError_t hipDevicePrimaryCtxRetain(hipCtx_t* pctx, hipDevice_t dev) {
    return hipCUResultTohipError(cuDevicePrimaryCtxRetain(pctx, dev));
}

inline static hipError_t hipDevicePrimaryCtxReset(hipDevice_t dev) {
    return hipCUResultTohipError(cuDevicePrimaryCtxReset(dev));
}

inline static hipError_t hipDevicePrimaryCtxSetFlags(hipDevice_t dev, unsigned int flags) {
    return hipCUResultTohipError(cuDevicePrimaryCtxSetFlags(dev, flags));
}

inline static hipError_t hipMemGetAddressRange(hipDeviceptr_t* pbase, size_t* psize,
                                               hipDeviceptr_t dptr) {
    return hipCUResultTohipError(cuMemGetAddressRange(pbase, psize, dptr));
}

inline static hipError_t hipMemcpyPeer(void* dst, int dstDevice, const void* src, int srcDevice,
                                       size_t count) {
    return hipCUDAErrorTohipError(cudaMemcpyPeer(dst, dstDevice, src, srcDevice, count));
}

inline static hipError_t hipMemcpyPeerAsync(void* dst, int dstDevice, const void* src,
                                            int srcDevice, size_t count,
                                            hipStream_t stream __dparm(0)) {
    return hipCUDAErrorTohipError(
        cudaMemcpyPeerAsync(dst, dstDevice, src, srcDevice, count, stream));
}

// Profile APIs:
inline static hipError_t hipProfilerStart() { return hipCUDAErrorTohipError(cudaProfilerStart()); }

inline static hipError_t hipProfilerStop() { return hipCUDAErrorTohipError(cudaProfilerStop()); }

inline static hipError_t hipSetDeviceFlags(unsigned int flags) {
    return hipCUDAErrorTohipError(cudaSetDeviceFlags(flags));
}

inline static hipError_t hipEventCreateWithFlags(hipEvent_t* event, unsigned int flags) {
    return hipCUDAErrorTohipError(cudaEventCreateWithFlags(event, flags));
}

inline static hipError_t hipEventQuery(hipEvent_t event) {
    return hipCUDAErrorTohipError(cudaEventQuery(event));
}

inline static hipError_t hipCtxCreate(hipCtx_t* ctx, unsigned int flags, hipDevice_t device) {
    return hipCUResultTohipError(cuCtxCreate(ctx, flags, device));
}

inline static hipError_t hipCtxDestroy(hipCtx_t ctx) {
    return hipCUResultTohipError(cuCtxDestroy(ctx));
}

inline static hipError_t hipCtxPopCurrent(hipCtx_t* ctx) {
    return hipCUResultTohipError(cuCtxPopCurrent(ctx));
}

inline static hipError_t hipCtxPushCurrent(hipCtx_t ctx) {
    return hipCUResultTohipError(cuCtxPushCurrent(ctx));
}

inline static hipError_t hipCtxSetCurrent(hipCtx_t ctx) {
    return hipCUResultTohipError(cuCtxSetCurrent(ctx));
}

inline static hipError_t hipCtxGetCurrent(hipCtx_t* ctx) {
    return hipCUResultTohipError(cuCtxGetCurrent(ctx));
}

inline static hipError_t hipCtxGetDevice(hipDevice_t* device) {
    return hipCUResultTohipError(cuCtxGetDevice(device));
}

inline static hipError_t hipCtxGetApiVersion(hipCtx_t ctx, int* apiVersion) {
    return hipCUResultTohipError(cuCtxGetApiVersion(ctx, (unsigned int*)apiVersion));
}

inline static hipError_t hipCtxGetCacheConfig(hipFuncCache* cacheConfig) {
    return hipCUResultTohipError(cuCtxGetCacheConfig(cacheConfig));
}

inline static hipError_t hipCtxSetCacheConfig(hipFuncCache cacheConfig) {
    return hipCUResultTohipError(cuCtxSetCacheConfig(cacheConfig));
}

inline static hipError_t hipCtxSetSharedMemConfig(hipSharedMemConfig config) {
    return hipCUResultTohipError(cuCtxSetSharedMemConfig((CUsharedconfig)config));
}

inline static hipError_t hipCtxGetSharedMemConfig(hipSharedMemConfig* pConfig) {
    return hipCUResultTohipError(cuCtxGetSharedMemConfig((CUsharedconfig*)pConfig));
}

inline static hipError_t hipCtxSynchronize(void) {
    return hipCUResultTohipError(cuCtxSynchronize());
}

inline static hipError_t hipCtxGetFlags(unsigned int* flags) {
    return hipCUResultTohipError(cuCtxGetFlags(flags));
}

inline static hipError_t hipCtxDetach(hipCtx_t ctx) {
    return hipCUResultTohipError(cuCtxDetach(ctx));
}

inline static hipError_t hipDeviceGet(hipDevice_t* device, int ordinal) {
    return hipCUResultTohipError(cuDeviceGet(device, ordinal));
}

inline static hipError_t hipDeviceComputeCapability(int* major, int* minor, hipDevice_t device) {
    return hipCUResultTohipError(cuDeviceComputeCapability(major, minor, device));
}

inline static hipError_t hipDeviceGetName(char* name, int len, hipDevice_t device) {
    return hipCUResultTohipError(cuDeviceGetName(name, len, device));
}

inline static hipError_t hipDeviceGetPCIBusId(char* pciBusId, int len, hipDevice_t device) {
    return hipCUDAErrorTohipError(cudaDeviceGetPCIBusId(pciBusId, len, device));
}

inline static hipError_t hipDeviceGetByPCIBusId(int* device, const char* pciBusId) {
    return hipCUDAErrorTohipError(cudaDeviceGetByPCIBusId(device, pciBusId));
}

inline static hipError_t hipDeviceGetSharedMemConfig(hipSharedMemConfig* config) {
    return hipCUDAErrorTohipError(cudaDeviceGetSharedMemConfig(config));
}

inline static hipError_t hipDeviceSetSharedMemConfig(hipSharedMemConfig config) {
    return hipCUDAErrorTohipError(cudaDeviceSetSharedMemConfig(config));
}

inline static hipError_t hipDeviceGetLimit(size_t* pValue, hipLimit_t limit) {
    return hipCUDAErrorTohipError(cudaDeviceGetLimit(pValue, limit));
}

inline static hipError_t hipDeviceTotalMem(size_t* bytes, hipDevice_t device) {
    return hipCUResultTohipError(cuDeviceTotalMem(bytes, device));
}

inline static hipError_t hipModuleLoad(hipModule_t* module, const char* fname) {
    return hipCUResultTohipError(cuModuleLoad(module, fname));
}

inline static hipError_t hipModuleUnload(hipModule_t hmod) {
    return hipCUResultTohipError(cuModuleUnload(hmod));
}

inline static hipError_t hipModuleGetFunction(hipFunction_t* function, hipModule_t module,
                                              const char* kname) {
    return hipCUResultTohipError(cuModuleGetFunction(function, module, kname));
}

inline static hipError_t hipFuncGetAttributes(hipFuncAttributes* attr, const void* func) {
    return hipCUDAErrorTohipError(cudaFuncGetAttributes(attr, func));
}

inline static hipError_t hipFuncGetAttribute (int* value, hipFunction_attribute attrib, hipFunction_t hfunc) {
    return hipCUResultTohipError(cuFuncGetAttribute(value, attrib, hfunc));
}

inline static hipError_t hipModuleGetGlobal(hipDeviceptr_t* dptr, size_t* bytes, hipModule_t hmod,
                                            const char* name) {
    return hipCUResultTohipError(cuModuleGetGlobal(dptr, bytes, hmod, name));
}

inline static hipError_t hipModuleLoadData(hipModule_t* module, const void* image) {
    return hipCUResultTohipError(cuModuleLoadData(module, image));
}

inline static hipError_t hipModuleLoadDataEx(hipModule_t* module, const void* image,
                                             unsigned int numOptions, hipJitOption* options,
                                             void** optionValues) {
    return hipCUResultTohipError(
        cuModuleLoadDataEx(module, image, numOptions, options, optionValues));
}

inline static hipError_t hipLaunchKernel(const void* function_address, dim3 numBlocks,
					 dim3 dimBlocks, void** args, size_t sharedMemBytes,
					 hipStream_t stream)
{
   return hipCUDAErrorTohipError(cudaLaunchKernel(function_address,numBlocks,dimBlocks,args,sharedMemBytes,stream));
}

inline static hipError_t hipModuleLaunchKernel(hipFunction_t f, unsigned int gridDimX,
                                               unsigned int gridDimY, unsigned int gridDimZ,
                                               unsigned int blockDimX, unsigned int blockDimY,
                                               unsigned int blockDimZ, unsigned int sharedMemBytes,
                                               hipStream_t stream, void** kernelParams,
                                               void** extra) {
    return hipCUResultTohipError(cuLaunchKernel(f, gridDimX, gridDimY, gridDimZ, blockDimX,
                                                blockDimY, blockDimZ, sharedMemBytes, stream,
                                                kernelParams, extra));
}


inline static hipError_t hipFuncSetCacheConfig(const void* func, hipFuncCache_t cacheConfig) {
    return hipCUDAErrorTohipError(cudaFuncSetCacheConfig(func, cacheConfig));
}

#ifdef __cplusplus
}
#endif

#ifdef __CUDACC__

template <class T>
inline static hipError_t hipOccupancyMaxPotentialBlockSize(int* minGridSize, int* blockSize, T func,
                                                           size_t dynamicSMemSize = 0,
                                                           int blockSizeLimit = 0) {
    cudaError_t cerror;
    cerror = cudaOccupancyMaxPotentialBlockSize(minGridSize, blockSize, func, dynamicSMemSize, blockSizeLimit);
    return hipCUDAErrorTohipError(cerror);
}

template <class T, int dim, enum hipTextureReadMode readMode>
inline static hipError_t hipBindTexture(size_t* offset, const struct texture<T, dim, readMode>& tex,
                                        const void* devPtr, size_t size = UINT_MAX) {
    return hipCUDAErrorTohipError(cudaBindTexture(offset, tex, devPtr, size));
}

template <class T, int dim, enum hipTextureReadMode readMode>
inline static hipError_t hipBindTexture(size_t* offset, struct texture<T, dim, readMode>& tex,
                                        const void* devPtr, const struct hipChannelFormatDesc& desc,
                                        size_t size = UINT_MAX) {
    return hipCUDAErrorTohipError(cudaBindTexture(offset, tex, devPtr, desc, size));
}

template <class T, int dim, enum hipTextureReadMode readMode>
inline static hipError_t hipUnbindTexture(struct texture<T, dim, readMode>* tex) {
    return hipCUDAErrorTohipError(cudaUnbindTexture(tex));
}

inline static hipError_t hipBindTexture(size_t* offset, textureReference* tex, const void* devPtr,
                                        const hipChannelFormatDesc* desc, size_t size = UINT_MAX){
    return hipCUDAErrorTohipError(cudaBindTexture(offset, tex, devPtr, desc, size));
}

template <class T, int dim, enum hipTextureReadMode readMode>
inline static hipError_t hipBindTextureToArray(struct texture<T, dim, readMode>& tex,
                                               hipArray_const_t array,
                                               const struct hipChannelFormatDesc& desc) {
    return hipCUDAErrorTohipError(cudaBindTextureToArray(tex, array, desc));
}

template <class T, int dim, enum hipTextureReadMode readMode>
inline static hipError_t hipBindTextureToArray(struct texture<T, dim, readMode> *tex,
                                               hipArray_const_t array,
                                               const struct hipChannelFormatDesc* desc) {
    return hipCUDAErrorTohipError(cudaBindTextureToArray(tex, array, desc));
}

template <class T, int dim, enum hipTextureReadMode readMode>
inline static hipError_t hipBindTextureToArray(struct texture<T, dim, readMode>& tex,
                                               hipArray_const_t array) {
    return hipCUDAErrorTohipError(cudaBindTextureToArray(tex, array));
}

template <class T>
inline static hipChannelFormatDesc hipCreateChannelDesc() {
    return cudaCreateChannelDesc<T>();
}

inline static hipChannelFormatDesc hipCreateChannelDesc(int x, int y, int z, int w,
                                                        hipChannelFormatKind f) {
    return cudaCreateChannelDesc(x, y, z, w, hipChannelFormatKindToCudaChannelFormatKind(f));
}

inline static hipError_t hipCreateTextureObject(hipTextureObject_t* pTexObject,
                                                const hipResourceDesc* pResDesc,
                                                const hipTextureDesc* pTexDesc,
                                                const hipResourceViewDesc* pResViewDesc) {
    return hipCUDAErrorTohipError(
        cudaCreateTextureObject(pTexObject, pResDesc, pTexDesc, pResViewDesc));
}

inline static hipError_t hipDestroyTextureObject(hipTextureObject_t textureObject) {
    return hipCUDAErrorTohipError(cudaDestroyTextureObject(textureObject));
}

inline static hipError_t hipCreateSurfaceObject(hipSurfaceObject_t* pSurfObject,
                                                const hipResourceDesc* pResDesc) {
    return hipCUDAErrorTohipError(cudaCreateSurfaceObject(pSurfObject, pResDesc));
}

inline static hipError_t hipDestroySurfaceObject(hipSurfaceObject_t surfaceObject) {
    return hipCUDAErrorTohipError(cudaDestroySurfaceObject(surfaceObject));
}

inline static hipError_t hipGetTextureObjectResourceDesc(hipResourceDesc* pResDesc,
                                           hipTextureObject_t textureObject) {
    return hipCUDAErrorTohipError(cudaGetTextureObjectResourceDesc( pResDesc, textureObject));
}

inline static hipError_t hipGetTextureAlignmentOffset(size_t* offset, const textureReference* texref)
{
    return hipCUDAErrorTohipError(cudaGetTextureAlignmentOffset(offset,texref));
}

inline static hipError_t hipGetChannelDesc(hipChannelFormatDesc* desc, hipArray_const_t array)
{
    return hipCUDAErrorTohipError(cudaGetChannelDesc(desc,array));
}
#endif  //__CUDACC__

#endif  // HIP_INCLUDE_HIP_NVCC_DETAIL_HIP_RUNTIME_API_H
