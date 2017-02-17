#ifndef STENCIL_H
#define STENCIL_H

#include <stddef.h>
#include <stdint.h>
#include <assert.h>

///Forward declarations
template <typename T, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3> struct Stencil;
template <typename T, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3> struct PackedStencil;
template <typename T, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3> struct AxiPackedStencil;


#ifndef AP_INT_MAX_W
//#define AP_INT_MAX_W 32768
#define AP_INT_MAX_W 4554
//#define AP_INT_MAX_W 17280
//#define AP_INT_MAX_W 2048
#endif

#include <ap_int.h>

union single_cast {
    float f;
    uint32_t i;
};

union double_cast {
    float f;
    uint64_t i;
};

template<typename T>
inline T bitcast_to_uint(T in) {
#pragma HLS INLINE
    return in;
}

static inline ap_uint<32> bitcast_to_uint(float in) {
#pragma HLS INLINE
    union single_cast temp;
    temp.f = in;
    return temp.i;
}

static inline ap_uint<64> bitcast_to_uint(double in) {
#pragma HLS INLINE
    union double_cast temp;
    temp.f = in;
    return temp.i;
}

template<typename T, int N>
inline void bitcast_to_type(ap_uint<N>& in, T& out) {
#pragma HLS INLINE
    static_assert(sizeof(T) * 8 == N, "bitcast_to_type parameters are incorrect.\n");
    out = in;
}

static inline void bitcast_to_type(ap_uint<32>& in, float& out) {
#pragma HLS INLINE
    union single_cast temp;
    temp.i = in;
    out = temp.f;
}

static inline void bitcast_to_type(ap_uint<64>& in, double& out) {
#pragma HLS INLINE
    union double_cast temp;
    temp.i = in;
    out = temp.f;
}

template <typename T, size_t EXTENT_0, size_t EXTENT_1 = 1, size_t EXTENT_2 = 1, size_t EXTENT_3 = 1>
struct PackedStencil {
    ap_uint<8*sizeof(T)*EXTENT_3*EXTENT_2*EXTENT_1*EXTENT_0> value;

    /** writer
     */
    inline ap_range_ref<8*sizeof(T)*EXTENT_3*EXTENT_2*EXTENT_1*EXTENT_0, false>
    operator()(size_t index_0, size_t index_1 = 0, size_t index_2 = 0, size_t index_3 = 0) {
#pragma HLS INLINE
        assert(index_0 < EXTENT_0 && index_1 < EXTENT_1 && index_2 < EXTENT_2 && index_3 < EXTENT_3);
        const size_t word_length = sizeof(T) * 8; // in bits
        const size_t lo = index_0 * word_length +
                          index_1 * EXTENT_0 * word_length +
                          index_2 * EXTENT_0 * EXTENT_1 * word_length +
                          index_3 * EXTENT_0 * EXTENT_1 * EXTENT_2 * word_length;
        const size_t hi = lo + word_length - 1;
        return value.range(hi, lo);
    }

    /** reader
     */
    inline ap_range_ref<8*sizeof(T)*EXTENT_3*EXTENT_2*EXTENT_1*EXTENT_0, false>
    operator()(size_t index_0, size_t index_1 = 0, size_t index_2 = 0, size_t index_3 = 0) const {
#pragma HLS INLINE
        assert(index_0 < EXTENT_0 && index_1 < EXTENT_1 && index_2 < EXTENT_2 && index_3 < EXTENT_3);
        const size_t word_length = sizeof(T) * 8; // in bits
        const size_t lo = index_0 * word_length +
                          index_1 * EXTENT_0 * word_length +
                          index_2 * EXTENT_0 * EXTENT_1 * word_length +
                          index_3 * EXTENT_0 * EXTENT_1 * EXTENT_2 * word_length;
        const size_t hi = lo + word_length - 1;
        return value.range(hi, lo);
    }

    // convert to Stencil
    operator Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3>() {
#pragma HLS INLINE
        Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> res;
#pragma HLS ARRAY_PARTITION variable=res.value complete dim=0

        for(size_t idx_3 = 0; idx_3 < EXTENT_3; idx_3++)
#pragma HLS UNROLL
        for(size_t idx_2 = 0; idx_2 < EXTENT_2; idx_2++)
#pragma HLS UNROLL
        for(size_t idx_1 = 0; idx_1 < EXTENT_1; idx_1++)
#pragma HLS UNROLL
        for(size_t idx_0 = 0; idx_0 < EXTENT_0; idx_0++) {
#pragma HLS UNROLL
            ap_uint<sizeof(T) * 8> temp = operator()(idx_0, idx_1, idx_2, idx_3);
            bitcast_to_type(temp, res.value[idx_3][idx_2][idx_1][idx_0]);
        }
        return res;
    }

    // convert to AxiPackedStencil
    operator AxiPackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3>() {
#pragma HLS INLINE
        AxiPackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> res;
        res.value = value;
        return res;
    }

};

template <typename T, size_t EXTENT_0, size_t EXTENT_1 = 1, size_t EXTENT_2 = 1, size_t EXTENT_3 = 1>
struct AxiPackedStencil {
    ap_uint<8*sizeof(T)*EXTENT_3*EXTENT_2*EXTENT_1*EXTENT_0> value;
    ap_uint<1> last;

    // convert to PackedStencil
    operator PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3>() {
#pragma HLS INLINE
        PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> res;
        res.value = value;
        return res;
    }

    // convert to Stencil
    operator Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3>() {
#pragma HLS INLINE
        PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> res = *this;
        return (Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3>)res;
    }
};

/** multi-dimension (up-to 4 dimensions) stencil struct
 */
template <typename T, size_t EXTENT_0, size_t EXTENT_1 = 1, size_t EXTENT_2 = 1, size_t EXTENT_3 = 1>
struct Stencil {
public:
    T value[EXTENT_3][EXTENT_2][EXTENT_1][EXTENT_0];

    /** writer
     */
    inline T& operator()(size_t index_0, size_t index_1 = 0, size_t index_2 = 0, size_t index_3 = 0) {
#pragma HLS INLINE
        assert(index_0 < EXTENT_0 && index_1 < EXTENT_1 && index_2 < EXTENT_2 && index_3 < EXTENT_3);
        return value[index_3][index_2][index_1][index_0];
    }

    /** reader
     */
    inline const T& operator()(size_t index_0, size_t index_1 = 0, size_t index_2 = 0, size_t index_3 = 0) const {
#pragma HLS INLINE
        assert(index_0 < EXTENT_0 && index_1 < EXTENT_1 && index_2 < EXTENT_2 && index_3 < EXTENT_3);
        return value[index_3][index_2][index_1][index_0];
    }

    // convert to PackedStencil
    operator PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3>() {
#pragma HLS INLINE
        PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> res;
        const size_t word_length = sizeof(T) * 8; // in bits

        for(size_t idx_3 = 0; idx_3 < EXTENT_3; idx_3++)
#pragma HLS UNROLL
        for(size_t idx_2 = 0; idx_2 < EXTENT_2; idx_2++)
#pragma HLS UNROLL
        for(size_t idx_1 = 0; idx_1 < EXTENT_1; idx_1++)
#pragma HLS UNROLL
        for(size_t idx_0 = 0; idx_0 < EXTENT_0; idx_0++) {
#pragma HLS UNROLL
            ap_uint<word_length> temp = bitcast_to_uint(value[idx_3][idx_2][idx_1][idx_0]);
            res(idx_0, idx_1, idx_2, idx_3) = temp;
        }
        return res;
    }

    // convert to AxiPackedStencil
    operator AxiPackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3>() {
#pragma HLS INLINE
        PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> res = *this;
        return (AxiPackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3>)res;
    }
};

#ifndef HALIDE_ATTRIBUTE_ALIGN
  #ifdef _MSC_VER
    #define HALIDE_ATTRIBUTE_ALIGN(x) __declspec(align(x))
  #else
    #define HALIDE_ATTRIBUTE_ALIGN(x) __attribute__((aligned(x)))
  #endif
#endif
#ifndef BUFFER_T_DEFINED
#define BUFFER_T_DEFINED
#include <stdbool.h>
#include <stdint.h>
typedef struct buffer_t {
    uint64_t dev;
    uint8_t* host;
    int32_t extent[4];
    int32_t stride[4];
    int32_t min[4];
    int32_t elem_size;
    HALIDE_ATTRIBUTE_ALIGN(1) bool host_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) bool dev_dirty;
    HALIDE_ATTRIBUTE_ALIGN(1) uint8_t _padding[10 - sizeof(void *)];
} buffer_t;
#endif


template <typename T, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3>
void buffer_to_stencil(const buffer_t *buffer,
                       Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> &stencil) {
    assert(EXTENT_0 == buffer->extent[0]);
    assert((EXTENT_1 == buffer->extent[1]) || (EXTENT_1 == 1 && buffer->extent[1] == 0));
    assert((EXTENT_2 == buffer->extent[2]) || (EXTENT_2 == 1 && buffer->extent[2] == 0));
    assert((EXTENT_3 == buffer->extent[3]) || (EXTENT_3 == 1 && buffer->extent[3] == 0));
    assert(sizeof(T) == buffer->elem_size);

    for(size_t idx_3 = 0; idx_3 < EXTENT_3; idx_3++)
    for(size_t idx_2 = 0; idx_2 < EXTENT_2; idx_2++)
    for(size_t idx_1 = 0; idx_1 < EXTENT_1; idx_1++)
    for(size_t idx_0 = 0; idx_0 < EXTENT_0; idx_0++) {
        const uint8_t *ptr = buffer->host;
        size_t offset = idx_0 * buffer->stride[0] +
            idx_1 * buffer->stride[1] +
            idx_2 * buffer->stride[2] +
            idx_3 * buffer->stride[3];
        const T *address =  (T *)(ptr + offset * buffer->elem_size);
        stencil(idx_0, idx_1, idx_2, idx_3) = *address;
    }
}

template <typename T, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3>
void subimage_to_stream(const struct buffer_t *buf_noop,
                        hls::stream<AxiPackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &stream,
                        void *subimage,
                        int stride_0, int subimage_extent_0,
                        int stride_1 = 1, int subimage_extent_1 = 1,
                        int stride_2 = 1, int subimage_extent_2 = 1,
                        int stride_3 = 1, int subimage_extent_3 = 1) {
    assert(subimage_extent_0 % EXTENT_0 == 0);
    assert(subimage_extent_1 % EXTENT_1 == 0);
    assert(subimage_extent_2 % EXTENT_2 == 0);
    assert(subimage_extent_3 % EXTENT_3 == 0);
    (void) buf_noop;  // avoid unused warnning
    for(size_t idx_3 = 0; idx_3 < (unsigned)subimage_extent_3; idx_3 += EXTENT_3)
    for(size_t idx_2 = 0; idx_2 < (unsigned)subimage_extent_2; idx_2 += EXTENT_2)
    for(size_t idx_1 = 0; idx_1 < (unsigned)subimage_extent_1; idx_1 += EXTENT_1)
    for(size_t idx_0 = 0; idx_0 < (unsigned)subimage_extent_0; idx_0 += EXTENT_0) {
        Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> stencil;
        for(size_t st_idx_3 = 0; st_idx_3 < EXTENT_3; st_idx_3++)
        for(size_t st_idx_2 = 0; st_idx_2 < EXTENT_2; st_idx_2++)
        for(size_t st_idx_1 = 0; st_idx_1 < EXTENT_1; st_idx_1++)
        for(size_t st_idx_0 = 0; st_idx_0 < EXTENT_0; st_idx_0++) {
            int offset = (idx_0 + st_idx_0) * stride_0 +
                (idx_1 + st_idx_1) * stride_1 +
                (idx_2 + st_idx_2) * stride_2 +
                (idx_3 + st_idx_3) * stride_3;
            stencil(st_idx_0, st_idx_1, st_idx_2, st_idx_3) = *((T *)subimage + offset);
        }
        stream.write(stencil);
    }
}

template <typename T, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3>
void stream_to_subimage(const struct buffer_t *buf_noop,
                        hls::stream<AxiPackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &stream,
                        void *subimage,
                        int stride_0, int subimage_extent_0,
                        int stride_1 = 1, int subimage_extent_1 = 1,
                        int stride_2 = 1, int subimage_extent_2 = 1,
                        int stride_3 = 1, int subimage_extent_3 = 1) {
    assert(subimage_extent_0 % EXTENT_0 == 0);
    assert(subimage_extent_1 % EXTENT_1 == 0);
    assert(subimage_extent_2 % EXTENT_2 == 0);
    assert(subimage_extent_3 % EXTENT_3 == 0);
    (void) buf_noop;  // avoid unused warnning
    for(size_t idx_3 = 0; idx_3 < (unsigned)subimage_extent_3; idx_3 += EXTENT_3)
    for(size_t idx_2 = 0; idx_2 < (unsigned)subimage_extent_2; idx_2 += EXTENT_2)
    for(size_t idx_1 = 0; idx_1 < (unsigned)subimage_extent_1; idx_1 += EXTENT_1)
    for(size_t idx_0 = 0; idx_0 < (unsigned)subimage_extent_0; idx_0 += EXTENT_0) {
        AxiPackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> axi_stencil = stream.read();
        Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> stencil = axi_stencil;
        for(size_t st_idx_3 = 0; st_idx_3 < EXTENT_3; st_idx_3++)
        for(size_t st_idx_2 = 0; st_idx_2 < EXTENT_2; st_idx_2++)
        for(size_t st_idx_1 = 0; st_idx_1 < EXTENT_1; st_idx_1++)
        for(size_t st_idx_0 = 0; st_idx_0 < EXTENT_0; st_idx_0++) {
            int offset = (idx_0 + st_idx_0) * stride_0 +
                (idx_1 + st_idx_1) * stride_1 +
                (idx_2 + st_idx_2) * stride_2 +
                (idx_3 + st_idx_3) * stride_3;
            *((T *)subimage + offset) = stencil(st_idx_0, st_idx_1, st_idx_2, st_idx_3);
        }
        // check TLAST
        if (idx_3 == subimage_extent_3 - EXTENT_3 &&
            idx_2 == subimage_extent_2 - EXTENT_2 &&
            idx_1 == subimage_extent_1 - EXTENT_1 &&
            idx_0 == subimage_extent_0 - EXTENT_0) {
            if(axi_stencil.last != 1) {
                printf("TLAS check failed.\n");
            }
        } else {
            if(axi_stencil.last != 0) {
                printf("TLAS check failed.\n");
            }
        }
    }
}


#endif
