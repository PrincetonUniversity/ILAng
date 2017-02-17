#ifndef LINEBUFFER_H
#define LINEBUFFER_H

#include "Stencil.h"

#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include <hls_stream.h>

using hls::stream;

template <size_t IMG_EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3,
	  size_t IN_EXTENT_0,  size_t OUT_EXTENT_0, typename T>
class Linebuffer1D {
public:
static void call(stream<PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, OUT_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    static_assert(IMG_EXTENT_0 >= OUT_EXTENT_0, "image extent not is larger than output.");
    static_assert(OUT_EXTENT_0 > IN_EXTENT_0, "input extent is larger than output."); // TODO handle this situation.
    static_assert(IMG_EXTENT_0 % IN_EXTENT_0 == 0, "image extent is not divisible by input."); // TODO handle this situation.
    static_assert(OUT_EXTENT_0 % IN_EXTENT_0 == 0, "output extent is not divisible by input."); // TODO handle this situation.

    const size_t BUFFER_EXTENT = OUT_EXTENT_0 / IN_EXTENT_0;
    PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> buffer[BUFFER_EXTENT];  // shift register
#pragma HLS ARRAY_PARTITION variable=buffer complete dim=1

    PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> in_stencil;
    PackedStencil<T, OUT_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> out_stencil;

 LB1D_shiftreg:for (size_t i = 0; i < IMG_EXTENT_0; i += IN_EXTENT_0) {
#pragma HLS DEPENDENCE array inter false
#pragma HLS LOOP_FLATTEN off
#pragma HLS PIPELINE II=1
        for (size_t j = 0; j < BUFFER_EXTENT - 1; j++) {
            buffer[j] = buffer[j+1]; // left shift
        }
        // read new stencil
        in_stencil = in_stream.read();
        buffer[BUFFER_EXTENT - 1] = in_stencil;
        if (i >= OUT_EXTENT_0 - IN_EXTENT_0) {
            // convert buffer to out_stencil, doing bit shuffling essentially
            for (size_t idx_3 = 0; idx_3 < EXTENT_3; idx_3++)
            for (size_t idx_2 = 0; idx_2 < EXTENT_2; idx_2++)
            for (size_t idx_1 = 0; idx_1 < EXTENT_1; idx_1++)
            for (size_t idx_0 = 0; idx_0 < IN_EXTENT_0; idx_0++)
            for (size_t idx_buffer = 0; idx_buffer < BUFFER_EXTENT; idx_buffer++) {
                out_stencil(idx_0+idx_buffer*IN_EXTENT_0, idx_1, idx_2, idx_3)
                    = buffer[idx_buffer](idx_0, idx_1, idx_2, idx_3);
            }
            out_stream.write(out_stencil);
        }
    }
}
};

// A trivial bypass layer, where input dim 0 and output dim 0 are the same size
template <size_t IMG_EXTENT_0,
          size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3, typename T>
class Linebuffer1D<IMG_EXTENT_0,  EXTENT_1,  EXTENT_2,  EXTENT_3,
                 EXTENT_0, EXTENT_0, T> {
public:
static void call(stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                   stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    // TODO we are wasting register here. should do specialization at the caller
    for (size_t idx_0 = 0; idx_0 < IMG_EXTENT_0; idx_0 += EXTENT_0) {
        //#pragma HLS PIPELINE rewind // rewind causes a internal error in Vivado HLS 2015.4
#pragma HLS PIPELINE II=1
        out_stream.write(in_stream.read());
    }
}
};

// An serial-in-parallel-out 1D line buffer,
// where output dim 0 and image dim 0 are the same, respectivcely.
// TODO use shift register to implement this buffer.
template <size_t IMG_EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3,
	  size_t IN_EXTENT_0, typename T>
class Linebuffer1D<IMG_EXTENT_0, EXTENT_1,  EXTENT_2,  EXTENT_3,
                 IN_EXTENT_0,  IMG_EXTENT_0, T> {
public:
static void call(stream<PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, IMG_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    static_assert(IMG_EXTENT_0 % IN_EXTENT_0 == 0, "output extent is not divisible by input.");
    const size_t BUFFER_EXTENT_0 = IMG_EXTENT_0 / IN_EXTENT_0;

    PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> buffer[BUFFER_EXTENT_0];
#pragma HLS ARRAY_PARTITION variable=buffer complete dim=0

 LB1D_sipo:for (size_t idx_0 = 0; idx_0 < BUFFER_EXTENT_0; idx_0++) {
#pragma HLS DEPENDENCE array inter false
#pragma HLS LOOP_FLATTEN off
#pragma HLS PIPELINE II=1
        PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> in = in_stream.read();
        // TODO make it a shift register
        buffer[idx_0] = in;

        if (idx_0 == BUFFER_EXTENT_0 - 1) {
            PackedStencil<T, IMG_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> out;
            // convert the array of stencils to a longer packed stencil
            for (size_t i = 0; i < BUFFER_EXTENT_0; i++)
            for (size_t st_idx_3 = 0; st_idx_3 < EXTENT_3; st_idx_3++)
            for (size_t st_idx_2 = 0; st_idx_2 < EXTENT_2; st_idx_2++)
            for (size_t st_idx_1 = 0; st_idx_1 < EXTENT_1; st_idx_1++)
            for (size_t st_idx_0 = 0; st_idx_0 < IN_EXTENT_0; st_idx_0++)
                out(st_idx_0 + i*IN_EXTENT_0, st_idx_1, st_idx_2, st_idx_3)
                    = buffer[i](st_idx_0, st_idx_1, st_idx_2, st_idx_3);

            out_stream.write(out);
        }
    }
}
};

// A trivial bypass layer, where input dim0, output dim 0 and image dim 0
// are the same size. output dim0 is the same as image dim 0.
// Therefore, It is more specialized than the serial-in-parallel-out
// 1D line buffer specialization to avoid ambiguous instatiation.
template <size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3, typename T>
class Linebuffer1D<EXTENT_0,  EXTENT_1,  EXTENT_2,  EXTENT_3,
                 EXTENT_0, EXTENT_0, T> {
public:
static void call(stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    // TODO we are wasting register here. should do specialization at the caller
    out_stream.write(in_stream.read());
}
};

// 1D linebuffer interface, which will call the class template Linebuffer1D.
// Linebuffer1D class template has specializations for handling different
// cases using optimized implementations
template <size_t IMG_EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3,
	  size_t IN_EXTENT_0,  size_t OUT_EXTENT_0, typename T>
void linebuffer_1D(stream<PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
		   stream<PackedStencil<T, OUT_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    Linebuffer1D<IMG_EXTENT_0,  EXTENT_1,  EXTENT_2,  EXTENT_3,
                 IN_EXTENT_0,  OUT_EXTENT_0, T>::call(in_stream, out_stream);
}

template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1, size_t EXTENT_2, size_t EXTENT_3,
	  size_t IN_EXTENT_0, size_t IN_EXTENT_1,
	  size_t OUT_EXTENT_0, size_t OUT_EXTENT_1, typename T>
class Linebuffer2D {
public:
static void call(stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, OUT_EXTENT_0, OUT_EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
    static_assert(IMG_EXTENT_1 > OUT_EXTENT_1, "output extent is larger than image.");
    static_assert(OUT_EXTENT_1 > IN_EXTENT_1, "input extent is larger than output."); // TODO handle this situation.
    static_assert(IMG_EXTENT_1 % IN_EXTENT_1 == 0, "image extent is not divisible by input."); // TODO handle this situation.
    static_assert(OUT_EXTENT_1 % IN_EXTENT_1 == 0, "output extent is not divisible by input."); // TODO handle this situation.
    static_assert(IMG_EXTENT_0 % IN_EXTENT_0 == 0, "image extent is not divisible by input."); // TODO handle this situation.
    static_assert(IMG_EXTENT_0 > IN_EXTENT_0, "image extent is not larger than input."); // TODO handle this situation.
#pragma HLS INLINE off
#pragma HLS DATAFLOW

    // use a 2D storage to buffer lines of image,
    // and output a column stencil per input at steady state
    const size_t IDX_EXTENT_0 = IMG_EXTENT_0 / IN_EXTENT_0;
    const size_t IDX_EXTENT_1 = IMG_EXTENT_1 / IN_EXTENT_1;
    const size_t BUFFER_EXTENT_1 = OUT_EXTENT_1 / IN_EXTENT_1 - 1;
    PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> buffer[BUFFER_EXTENT_1][IDX_EXTENT_0];
#pragma HLS ARRAY_PARTITION variable=buffer complete dim=1

    PackedStencil<T, IN_EXTENT_0, OUT_EXTENT_1, EXTENT_2, EXTENT_3> slice;
    stream<PackedStencil<T, IN_EXTENT_0, OUT_EXTENT_1, EXTENT_2, EXTENT_3> > slice_stream;
#pragma HLS STREAM variable=slice_stream depth=1
#pragma HLS RESOURCE variable=slice_stream core=FIFO_SRL

    size_t write_idx_1 = 0; // the line index of coming stencil in the linebuffer
 LB2D_buf:for (size_t row = 0; row < IDX_EXTENT_1; row++) {
#pragma HLS LOOP_FLATTEN off
        for (size_t col = 0; col < IDX_EXTENT_0; col++) {
#pragma HLS DEPENDENCE array inter false
#pragma HLS PIPELINE II=1
            //size_t write_idx_1 = row % BUFFER_EXTENT_1; // the line index of coming stencil in the linebuffer
            if (write_idx_1 >= BUFFER_EXTENT_1) {
                write_idx_1 -= BUFFER_EXTENT_1;
            }
            PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> in_stencil = in_stream.read();
            if (row >= BUFFER_EXTENT_1) {
                // fetch data from buffer
                for (size_t idx_line = 0; idx_line < BUFFER_EXTENT_1; idx_line++) {
                    size_t idx_line_in_buffer = idx_line + write_idx_1;
                    if (idx_line_in_buffer >= BUFFER_EXTENT_1)
                        idx_line_in_buffer -= BUFFER_EXTENT_1;
                    for (size_t st_idx_3 = 0; st_idx_3 < EXTENT_3; st_idx_3++)
                    for (size_t st_idx_2 = 0; st_idx_2 < EXTENT_2; st_idx_2++)
                    for (size_t st_idx_1 = 0; st_idx_1 < IN_EXTENT_1; st_idx_1++)
                    for (size_t st_idx_0 = 0; st_idx_0 < IN_EXTENT_0; st_idx_0++)
                        slice(st_idx_0, idx_line*IN_EXTENT_1 + st_idx_1, st_idx_2, st_idx_3)
                            = buffer[idx_line_in_buffer][col](st_idx_0, st_idx_1, st_idx_2, st_idx_3);
                }
                // pass data from input
                for (size_t st_idx_3 = 0; st_idx_3 < EXTENT_3; st_idx_3++)
                for (size_t st_idx_2 = 0; st_idx_2 < EXTENT_2; st_idx_2++)
                for (size_t st_idx_1 = 0; st_idx_1 < IN_EXTENT_1; st_idx_1++)
                for (size_t st_idx_0 = 0; st_idx_0 < IN_EXTENT_0; st_idx_0++)
                    slice(st_idx_0, BUFFER_EXTENT_1*IN_EXTENT_1 + st_idx_1, st_idx_2, st_idx_3)
                        = in_stencil(st_idx_0, st_idx_1, st_idx_2, st_idx_3);
                slice_stream.write(slice);
            }
            buffer[write_idx_1][col] = in_stencil;  // store the input in the buffer
        }
        write_idx_1++;
    }

    // feed the column stencil stream to 1D line buffer
    const size_t NUM_OF_OUTPUT_1 = (IMG_EXTENT_1 - OUT_EXTENT_1) / IN_EXTENT_1 + 1;
 LB2D_shift:for (size_t n1 = 0; n1 < NUM_OF_OUTPUT_1; n1++) {
        linebuffer_1D<IMG_EXTENT_0>(slice_stream, out_stream);
    }
}
};


// Case 1: A trivial bypass layer, where input dim 1 and output dim 1 are the same size
template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1,
          size_t IN_EXTENT_0, size_t OUT_EXTENT_0,
          size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3, typename T>
class Linebuffer2D<IMG_EXTENT_0,  IMG_EXTENT_1,  EXTENT_2,  EXTENT_3,
                   IN_EXTENT_0,  EXTENT_1,  OUT_EXTENT_0,  EXTENT_1, T> {
public:
static void call(stream<PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, OUT_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    for (size_t idx_1 = 0; idx_1 < IMG_EXTENT_1; idx_1 += EXTENT_1) {
        linebuffer_1D<IMG_EXTENT_0>(in_stream, out_stream);
    }
}
};

// Case 2: Dim 0 is a trivial dimension, so a line buffer on dim 1 should be a shift register
template <size_t EXTENT_0, size_t IMG_EXTENT_1, size_t EXTENT_2, size_t EXTENT_3,
	  size_t IN_EXTENT_1, size_t OUT_EXTENT_1, typename T>
class Linebuffer2D<EXTENT_0,  IMG_EXTENT_1,  EXTENT_2,  EXTENT_3,
                   EXTENT_0,  IN_EXTENT_1,  EXTENT_0,  OUT_EXTENT_1, T> {
public:
static void call(stream<PackedStencil<T, EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, EXTENT_0, OUT_EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE off
#pragma HLS DATAFLOW
    static_assert(IMG_EXTENT_1 >= OUT_EXTENT_1, "image extent not is larger than output.");
    static_assert(OUT_EXTENT_1 > IN_EXTENT_1, "input extent is larger than output."); // TODO handle this situation.
    static_assert(IMG_EXTENT_1 % IN_EXTENT_1 == 0, "image extent is not divisible by input."); // TODO handle this situation.
    static_assert(OUT_EXTENT_1 % IN_EXTENT_1 == 0, "output extent is not divisible by input."); // TODO handle this situation.

    const size_t BUFFER_EXTENT = OUT_EXTENT_1 / IN_EXTENT_1;
    PackedStencil<T, EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> buffer[BUFFER_EXTENT];  // shift register
#pragma HLS ARRAY_PARTITION variable=buffer complete dim=1

    PackedStencil<T, EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> in_stencil;
    PackedStencil<T, EXTENT_0, OUT_EXTENT_1, EXTENT_2, EXTENT_3> out_stencil;

    for (size_t i = 0; i < IMG_EXTENT_1; i += IN_EXTENT_1) {
#pragma HLS DEPENDENCE array inter false
#pragma HLS LOOP_FLATTEN off
#pragma HLS PIPELINE II=1
        for (size_t j = 0; j < BUFFER_EXTENT - 1; j++) {
            buffer[j] = buffer[j+1]; // left shift
        }
        // read new stencil
        in_stencil = in_stream.read();
        buffer[BUFFER_EXTENT - 1] = in_stencil;
        if (i >= OUT_EXTENT_1 - IN_EXTENT_1) {
            // convert buffer to out_stencil, doing bit shuffling essentially
            for (size_t idx_3 = 0; idx_3 < EXTENT_3; idx_3++)
            for (size_t idx_2 = 0; idx_2 < EXTENT_2; idx_2++)
            for (size_t idx_1 = 0; idx_1 < IN_EXTENT_1; idx_1++)
            for (size_t idx_0 = 0; idx_0 < EXTENT_0; idx_0++)
            for (size_t idx_buffer = 0; idx_buffer < BUFFER_EXTENT; idx_buffer++) {
                out_stencil(idx_0, idx_1+idx_buffer*IN_EXTENT_1, idx_2, idx_3)
                    = buffer[idx_buffer](idx_0, idx_1, idx_2, idx_3);
            }
            out_stream.write(out_stencil);
        }
    }
}
};

// Case 3: union of case 1 and case 2
template <size_t EXTENT_0, size_t IMG_EXTENT_1, size_t EXTENT_2, size_t EXTENT_3,
	  size_t EXTENT_1, typename T>
class Linebuffer2D<EXTENT_0,  IMG_EXTENT_1,  EXTENT_2,  EXTENT_3,
                   EXTENT_0,  EXTENT_1,  EXTENT_0,  EXTENT_1, T> {
public:
static void call(stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    for (size_t idx_1 = 0; idx_1 < IMG_EXTENT_1; idx_1 += EXTENT_1) {
        out_stream.write(in_stream.read());
    }
}
};

// Case 4: A trivial bypass layer, where input dim 1, output dim 1 and image dim 1
// are the same size
template <size_t IMG_EXTENT_0, size_t EXTENT_1,
          size_t IN_EXTENT_0, size_t OUT_EXTENT_0,
          size_t EXTENT_2, size_t EXTENT_3, typename T>
class Linebuffer2D<IMG_EXTENT_0,  EXTENT_1,  EXTENT_2,  EXTENT_3,
                   IN_EXTENT_0,  EXTENT_1,  OUT_EXTENT_0,  EXTENT_1, T> {
public:
static void call(stream<PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, OUT_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    linebuffer_1D<IMG_EXTENT_0>(in_stream, out_stream);
}
};

// Case 5: union of case 3 and case 4
template <size_t EXTENT_0, size_t EXTENT_2, size_t EXTENT_3,
	  size_t EXTENT_1, typename T>
class Linebuffer2D<EXTENT_0,  EXTENT_1,  EXTENT_2,  EXTENT_3,
                   EXTENT_0,  EXTENT_1,  EXTENT_0,  EXTENT_1, T> {
public:
static void call(stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    out_stream.write(in_stream.read());
}
};

// An serial-in-parallel-out 2D line buffer,
// where output dim 1/0 and image dim 1/0 are the same, respectivcely.
template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1,
          size_t IN_EXTENT_0, size_t IN_EXTENT_1,
          size_t EXTENT_2, size_t EXTENT_3, typename T>
class Linebuffer2D<IMG_EXTENT_0,  IMG_EXTENT_1,  EXTENT_2,  EXTENT_3,
                   IN_EXTENT_0,  IN_EXTENT_1,  IMG_EXTENT_0,  IMG_EXTENT_1, T> {
public:
static void call(stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, IMG_EXTENT_0, IMG_EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    static_assert(IMG_EXTENT_1 % IN_EXTENT_1 == 0, "output extent is not divisible by input.");
    static_assert(IMG_EXTENT_0 % IN_EXTENT_0 == 0, "output extent is not divisible by input.");
    const size_t BUFFER_EXTENT_0 = IMG_EXTENT_0 / IN_EXTENT_0;
    const size_t BUFFER_EXTENT_1 = IMG_EXTENT_1 / IN_EXTENT_1;

    PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> buffer[BUFFER_EXTENT_1][BUFFER_EXTENT_0];
#pragma HLS ARRAY_PARTITION variable=buffer complete dim=0

    for (size_t idx_1 = 0; idx_1 < BUFFER_EXTENT_1; idx_1++) {
        for (size_t idx_0 = 0; idx_0 < BUFFER_EXTENT_0; idx_0++) {
#pragma HLS DEPENDENCE array inter false
            //#pragma HLS LOOP_FLATTEN off
#pragma HLS PIPELINE II=1
            PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> in = in_stream.read();
            // TODO make it a shift register
            buffer[idx_1][idx_0] = in;

            if (idx_1 == BUFFER_EXTENT_1 - 1
                && idx_0 == BUFFER_EXTENT_0 - 1) {
                PackedStencil<T, IMG_EXTENT_0, IMG_EXTENT_1, EXTENT_2, EXTENT_3> out;
                // convert the array of stencils to a longer packed stencil
                for (size_t i = 0; i < BUFFER_EXTENT_1; i++)
                for (size_t j = 0; j < BUFFER_EXTENT_0; j++)
                for (size_t st_idx_3 = 0; st_idx_3 < EXTENT_3; st_idx_3++)
                for (size_t st_idx_2 = 0; st_idx_2 < EXTENT_2; st_idx_2++)
                for (size_t st_idx_1 = 0; st_idx_1 < IN_EXTENT_1; st_idx_1++)
                for (size_t st_idx_0 = 0; st_idx_0 < IN_EXTENT_0; st_idx_0++)
                    out(st_idx_0 + j*IN_EXTENT_0, st_idx_1 + i*IN_EXTENT_1, st_idx_2, st_idx_3)
                        = buffer[i][j](st_idx_0, st_idx_1, st_idx_2, st_idx_3);

                out_stream.write(out);
            }
        }
    }
}
};

// A trivial bypass layer, where input dim 1, output dim 1 and image dim 1
// are the same size. output dim0 is the same as image dim 0.
// Therefore, It is more specialized than the serial-in-parallel-out
// 2D line buffer specialization to avoid ambiguous instatiation.
template <size_t IMG_EXTENT_0, size_t EXTENT_1,
          size_t IN_EXTENT_0, size_t EXTENT_2, size_t EXTENT_3, typename T>
class Linebuffer2D<IMG_EXTENT_0,  EXTENT_1,  EXTENT_2,  EXTENT_3,
                   IN_EXTENT_0,  EXTENT_1, IMG_EXTENT_0,  EXTENT_1, T> {
public:
static void call(stream<PackedStencil<T, IN_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                 stream<PackedStencil<T, IMG_EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    linebuffer_1D<IMG_EXTENT_0>(in_stream, out_stream);
}
};

// 2D linebuffer interface, which will call the class template Linebuffer2D.
// Linebuffer2D class template has specializations for handling different
// cases using optimized implementations
template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1, size_t EXTENT_2, size_t EXTENT_3,
	  size_t IN_EXTENT_0, size_t IN_EXTENT_1,
	  size_t OUT_EXTENT_0, size_t OUT_EXTENT_1, typename T>
void linebuffer_2D(stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                   stream<PackedStencil<T, OUT_EXTENT_0, OUT_EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
    Linebuffer2D<IMG_EXTENT_0,  IMG_EXTENT_1,  EXTENT_2,  EXTENT_3,
                 IN_EXTENT_0,  IN_EXTENT_1,  OUT_EXTENT_0,  OUT_EXTENT_1, T>::call(in_stream, out_stream);
}

template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1, size_t IMG_EXTENT_2, size_t EXTENT_3,
	  size_t IN_EXTENT_0, size_t IN_EXTENT_1, size_t IN_EXTENT_2,
	  size_t OUT_EXTENT_0, size_t OUT_EXTENT_1,  size_t OUT_EXTENT_2, typename T>
void linebuffer_3D(stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, EXTENT_3> > &in_stream,
                   stream<PackedStencil<T, OUT_EXTENT_0, OUT_EXTENT_1, OUT_EXTENT_2, EXTENT_3> > &out_stream) {
    static_assert(IMG_EXTENT_2 > OUT_EXTENT_2, "output extent is larger than image.");
    static_assert(OUT_EXTENT_2 > IN_EXTENT_2, "input extent is larger than output."); // TODO handle this situation.
    static_assert(IMG_EXTENT_2 % IN_EXTENT_2 == 0, "image extent is not divisible by input."); // TODO handle this situation.
    static_assert(OUT_EXTENT_2 % IN_EXTENT_2 == 0, "output extent is not divisible by input."); // TODO handle this situation.
    static_assert(IMG_EXTENT_1 % IN_EXTENT_1 == 0, "image extent is not divisible by input."); // TODO handle this situation..
    static_assert(IMG_EXTENT_0 % IN_EXTENT_0 == 0, "image extent is not divisible by input."); // TODO handle this situation.
    static_assert(IMG_EXTENT_0 > IN_EXTENT_0 || IMG_EXTENT_1 > IN_EXTENT_1, "image extent is not larger than input."); // TODO handle this situation.
#pragma HLS INLINE off
#pragma HLS DATAFLOW

    // use a 3D storage to buffer plains of image,
    // and output a grid stencil per input at steady state
    const size_t IDX_EXTENT_0 = IMG_EXTENT_0 / IN_EXTENT_0;
    const size_t IDX_EXTENT_1 = IMG_EXTENT_1 / IN_EXTENT_1;
    const size_t IDX_EXTENT_2 = IMG_EXTENT_2 / IN_EXTENT_2;
    const size_t BUFFER_EXTENT_2 = OUT_EXTENT_2 / IN_EXTENT_2 - 1;
    PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, EXTENT_3> buffer[BUFFER_EXTENT_2][IDX_EXTENT_1][IDX_EXTENT_0];
#pragma HLS ARRAY_PARTITION variable=buffer complete dim=1

    PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, OUT_EXTENT_2, EXTENT_3> slice;
    stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, OUT_EXTENT_2, EXTENT_3> > slice_stream;
#pragma HLS STREAM variable=slice_stream depth=1
#pragma HLS RESOURCE variable=slice_stream core=FIFO_SRL

    size_t write_idx_2 = 0; // the line index of coming stencil in the linebuffer
 LB3D_buf:for (size_t idx_2 = 0; idx_2 < IDX_EXTENT_2; idx_2++) {
#pragma HLS LOOP_FLATTEN off
        for (size_t idx_1 = 0; idx_1 < IDX_EXTENT_1; idx_1++) {
            for (size_t idx_0 = 0; idx_0 < IDX_EXTENT_0; idx_0++) {
#pragma HLS DEPENDENCE array inter false
#pragma HLS PIPELINE II=1
                //size_t write_idx_2 = idx_2 % BUFFER_EXTENT_2; // the line index of coming stencil in the linebuffer
                if (write_idx_2 >= BUFFER_EXTENT_2) {
                    write_idx_2 -= BUFFER_EXTENT_2;
                }
                PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, EXTENT_3> in_stencil = in_stream.read();
                if (idx_2 >= BUFFER_EXTENT_2) {
                    // fetch data from buffer
                    for (size_t idx_2 = 0; idx_2 < BUFFER_EXTENT_2; idx_2++) {
                        size_t idx_2_in_buffer = idx_2 + write_idx_2;
                        if (idx_2_in_buffer >= BUFFER_EXTENT_2)
                            idx_2_in_buffer -= BUFFER_EXTENT_2;
                        for (size_t st_idx_3 = 0; st_idx_3 < EXTENT_3; st_idx_3++)
                        for (size_t st_idx_2 = 0; st_idx_2 < IN_EXTENT_2; st_idx_2++)
                        for (size_t st_idx_1 = 0; st_idx_1 < IN_EXTENT_1; st_idx_1++)
                        for (size_t st_idx_0 = 0; st_idx_0 < IN_EXTENT_0; st_idx_0++)
                            slice(st_idx_0, st_idx_1, idx_2*IN_EXTENT_2 + st_idx_2, st_idx_3)
                                = buffer[idx_2_in_buffer][idx_1][idx_0](st_idx_0, st_idx_1, st_idx_2, st_idx_3);
                    }
                    // pass data from input
                    for (size_t st_idx_3 = 0; st_idx_3 < EXTENT_3; st_idx_3++)
                    for (size_t st_idx_2 = 0; st_idx_2 < IN_EXTENT_2; st_idx_2++)
                    for (size_t st_idx_1 = 0; st_idx_1 < IN_EXTENT_1; st_idx_1++)
                    for (size_t st_idx_0 = 0; st_idx_0 < IN_EXTENT_0; st_idx_0++)
                        slice(st_idx_0, st_idx_1, BUFFER_EXTENT_2*IN_EXTENT_2 + st_idx_2, st_idx_3)
                                = in_stencil(st_idx_0, st_idx_1, st_idx_2, st_idx_3);
                    slice_stream.write(slice);
                }
                buffer[write_idx_2][idx_1][idx_0] = in_stencil;  // store the input in the buffer
            }
        }
        write_idx_2++;
    }

    // feed the column stencil stream to 2D line buffer
    const size_t NUM_OF_OUTPUT_2 = (IMG_EXTENT_2 - OUT_EXTENT_2) / IN_EXTENT_2 + 1;
 LB3D_shift:for (size_t n2 = 0; n2 < NUM_OF_OUTPUT_2; n2++) {
	linebuffer_2D<IMG_EXTENT_0, IMG_EXTENT_1>(slice_stream, out_stream);
    }
}

// An overloaded (trivial) 3D line buffer, where input dim 2 and output dim 2 are the same size
template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1, size_t IMG_EXTENT_2,
          size_t IN_EXTENT_0, size_t IN_EXTENT_1,
          size_t OUT_EXTENT_0, size_t OUT_EXTENT_1,
          size_t EXTENT_2, size_t EXTENT_3, typename T>
void linebuffer_3D(stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream,
                   stream<PackedStencil<T, OUT_EXTENT_0, OUT_EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
 LB_3D_pass:for (size_t idx_2 = 0; idx_2 < IMG_EXTENT_2; idx_2 += EXTENT_2) {
	linebuffer_2D<IMG_EXTENT_0, IMG_EXTENT_1>(in_stream, out_stream);
    }
}

// An overloaded (trivial) 4D line buffer, where input dim 3 and output dim 3 are the same size
template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1, size_t IMG_EXTENT_2, size_t IMG_EXTENT_3,
          size_t IN_EXTENT_0, size_t IN_EXTENT_1, size_t IN_EXTENT_2,
          size_t OUT_EXTENT_0, size_t OUT_EXTENT_1, size_t OUT_EXTENT_2,
          size_t EXTENT_3, typename T>
void linebuffer_4D(stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, EXTENT_3> > &in_stream,
                   stream<PackedStencil<T, OUT_EXTENT_0, OUT_EXTENT_1, OUT_EXTENT_2, EXTENT_3> > &out_stream) {
#pragma HLS INLINE
 LB_4D_pass:for (size_t idx_3 = 0; idx_3 < IMG_EXTENT_3; idx_3 += EXTENT_3) {
	linebuffer_3D<IMG_EXTENT_0, IMG_EXTENT_1, IMG_EXTENT_2>(in_stream, out_stream);
    }
}


/** A line buffer that buffers a image size [IMG_EXTENT_0, IMG_EXTENT_1, IMG_EXTENT_2].
 * The input is a stencil size [IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2], and it traversal
 * the image along dimensiO 0 first, and then dimension 1, and so on. The step of the
 * input stencil is the same as the size of input stencil, so there is no overlapping
 * between input stencils.
 * The output is a stencil size [OUT_EXTENT_0, OUT_EXTENT_1, OUT_EXTENT_2], and it traversal
 * the image the same as input (i.e. along dimension 0 first, and then dimension 1, and so on.
 * The step of the output stencil is the same as the size of input stencil, so the
 * throughputs of the inputs and outputs are balanced at the steady state. In other words,
 * the line buffer generates one output per input at the steady state.
 */
template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1=1, size_t IMG_EXTENT_2=1, size_t IMG_EXTENT_3=1,
	  size_t IN_EXTENT_0, size_t IN_EXTENT_1, size_t IN_EXTENT_2, size_t IN_EXTENT_3,
	  size_t OUT_EXTENT_0, size_t OUT_EXTENT_1, size_t OUT_EXTENT_2, size_t OUT_EXTENT_3,
	  typename T>
void linebuffer(stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, IN_EXTENT_3> > &in_stream,
		stream<PackedStencil<T, OUT_EXTENT_0, OUT_EXTENT_1, OUT_EXTENT_2, OUT_EXTENT_3> > &out_stream) {
    static_assert(OUT_EXTENT_3 == IN_EXTENT_3, "dont not support 4D line buffer yet.");
#pragma HLS INLINE off
#pragma HLS DATAFLOW
    linebuffer_4D<IMG_EXTENT_0, IMG_EXTENT_1, IMG_EXTENT_2, IMG_EXTENT_3>(in_stream, out_stream);
}

template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1=1, size_t IMG_EXTENT_2=1, size_t IMG_EXTENT_3=1,
	  size_t IN_EXTENT_0, size_t IN_EXTENT_1, size_t IN_EXTENT_2, size_t IN_EXTENT_3,
	  size_t OUT_EXTENT_0, size_t OUT_EXTENT_1, size_t OUT_EXTENT_2, size_t OUT_EXTENT_3,
	  typename T>
void linebuffer(stream<AxiPackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, IN_EXTENT_3> > &in_axi_stream,
		stream<PackedStencil<T, OUT_EXTENT_0, OUT_EXTENT_1, OUT_EXTENT_2, OUT_EXTENT_3> > &out_stream) {
    static_assert(IMG_EXTENT_3 % IN_EXTENT_3 == 0, "image extent is not divisible by input.");
    static_assert(IMG_EXTENT_2 % IN_EXTENT_2 == 0, "image extent is not divisible by input.");
    static_assert(IMG_EXTENT_1 % IN_EXTENT_1 == 0, "image extent is not divisible by input.");
    static_assert(IMG_EXTENT_0 % IN_EXTENT_0 == 0, "image extent is not divisible by input.");
#pragma HLS INLINE off
#pragma HLS DATAFLOW
    stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, IN_EXTENT_3> > in_stream;
#pragma HLS STREAM variable=in_stream depth=1
#pragma HLS RESOURCE variable=in_stream core=FIFO_SRL

    for (size_t idx_3 = 0; idx_3 < IMG_EXTENT_3 / IN_EXTENT_3; idx_3++)
    for (size_t idx_2 = 0; idx_2 < IMG_EXTENT_2 / IN_EXTENT_2; idx_2++)
    for (size_t idx_1 = 0; idx_1 < IMG_EXTENT_1 / IN_EXTENT_1; idx_1++)
    for (size_t idx_0 = 0; idx_0 < IMG_EXTENT_0 / IN_EXTENT_0; idx_0++)
#pragma HLS PIPELINE II=1
        in_stream.write(in_axi_stream.read());

    linebuffer<IMG_EXTENT_0, IMG_EXTENT_1, IMG_EXTENT_2, IMG_EXTENT_3>(in_stream, out_stream);
}


template <size_t IMG_EXTENT_0, size_t IMG_EXTENT_1=1, size_t IMG_EXTENT_2=1, size_t IMG_EXTENT_3=1,
	  size_t IN_EXTENT_0, size_t IN_EXTENT_1, size_t IN_EXTENT_2, size_t IN_EXTENT_3,
          size_t OUT_EXTENT_0, size_t OUT_EXTENT_1, size_t OUT_EXTENT_2, size_t OUT_EXTENT_3,
          typename T>
void linebuffer_ref(stream<PackedStencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, IN_EXTENT_3> > &in_stream,
		    stream<PackedStencil<T, OUT_EXTENT_0, OUT_EXTENT_1, OUT_EXTENT_2, OUT_EXTENT_3> > &out_stream) {

    T buffer[IMG_EXTENT_3][IMG_EXTENT_2][IMG_EXTENT_1][IMG_EXTENT_0];

    for (size_t outer_3 = 0; outer_3 < IMG_EXTENT_3; outer_3 += IN_EXTENT_3)
    for (size_t outer_2 = 0; outer_2 < IMG_EXTENT_2; outer_2 += IN_EXTENT_2)
    for (size_t outer_1 = 0; outer_1 < IMG_EXTENT_1; outer_1 += IN_EXTENT_1)
    for (size_t outer_0 = 0; outer_0 < IMG_EXTENT_0; outer_0 += IN_EXTENT_0) {
        Stencil<T, IN_EXTENT_0, IN_EXTENT_1, IN_EXTENT_2, IN_EXTENT_3> stencil = in_stream.read();

        for (size_t inner_3 = 0; inner_3 < IN_EXTENT_3; inner_3++)
        for (size_t inner_2 = 0; inner_2 < IN_EXTENT_2; inner_2++)
        for (size_t inner_1 = 0; inner_1 < IN_EXTENT_1; inner_1++)
        for (size_t inner_0 = 0; inner_0 < IN_EXTENT_0; inner_0++)
            buffer[outer_3+inner_3][outer_2+inner_2][outer_1+inner_1][outer_0+inner_0]
                = stencil(inner_0, inner_1, inner_2, inner_3);
    }

    for (size_t outer_3 = 0; outer_3 <= IMG_EXTENT_3 - OUT_EXTENT_3; outer_3 += IN_EXTENT_3)
    for (size_t outer_2 = 0; outer_2 <= IMG_EXTENT_2 - OUT_EXTENT_2; outer_2 += IN_EXTENT_2)
    for (size_t outer_1 = 0; outer_1 <= IMG_EXTENT_1 - OUT_EXTENT_1; outer_1 += IN_EXTENT_1)
    for (size_t outer_0 = 0; outer_0 <= IMG_EXTENT_0 - OUT_EXTENT_0; outer_0 += IN_EXTENT_0) {
        Stencil<T, OUT_EXTENT_0, OUT_EXTENT_1, OUT_EXTENT_2, OUT_EXTENT_3> stencil;

        for (size_t inner_3 = 0; inner_3 < OUT_EXTENT_3; inner_3++)
        for (size_t inner_2 = 0; inner_2 < OUT_EXTENT_2; inner_2++)
        for (size_t inner_1 = 0; inner_1 < OUT_EXTENT_1; inner_1++)
        for (size_t inner_0 = 0; inner_0 < OUT_EXTENT_0; inner_0++)
            stencil(inner_0, inner_1, inner_2, inner_3)
                = buffer[outer_3+inner_3][outer_2+inner_2][outer_1+inner_1][outer_0+inner_0];

		out_stream.write(stencil);
    }
}


#endif
