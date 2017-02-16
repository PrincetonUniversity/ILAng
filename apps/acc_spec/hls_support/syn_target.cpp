#include "Linebuffer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void syn_target(hls::stream<PackedStencil<uint8_t, 2, 1> > &input_stream,
                hls::stream<PackedStencil<uint8_t, 2, 3> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<20, 12>(input_stream, output_stream);

}

void syn_target_3D2D1D(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                       hls::stream<PackedStencil<uint8_t, 3, 3, 3, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<32, 32, 32, 1>(input_stream, output_stream);
}

void syn_target_3D2D(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                     hls::stream<PackedStencil<uint8_t, 1, 3, 3, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<32, 32, 32, 1>(input_stream, output_stream);
}

void syn_target_3D1D(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                     hls::stream<PackedStencil<uint8_t, 3, 1, 3, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<32, 32, 32, 1>(input_stream, output_stream);
}

void syn_target_3D(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                   hls::stream<PackedStencil<uint8_t, 1, 1, 3, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<32, 32, 32, 1>(input_stream, output_stream);
}

void syn_target_2D1D(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                     hls::stream<PackedStencil<uint8_t, 3, 3, 1, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<32, 32, 1, 1>(input_stream, output_stream);
}

void syn_target_2D(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                   hls::stream<PackedStencil<uint8_t, 1, 3, 1, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<32, 32, 1, 1>(input_stream, output_stream);
}


void syn_target_1D(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                   hls::stream<PackedStencil<uint8_t, 3, 1, 1, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<32, 1, 1, 1>(input_stream, output_stream);
}


//2D and 3D linebuffer has latency bug when IMG_EXTENT_0=IN_EXTENT_0=OUT_EXTENT_0
void syn_target_3D2D_bug(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                         hls::stream<PackedStencil<uint8_t, 1, 3, 3, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<1, 32, 32, 1>(input_stream, output_stream);
}

void syn_target_2D_bug(hls::stream<PackedStencil<uint8_t, 1, 1, 1, 1> > &input_stream,
                       hls::stream<PackedStencil<uint8_t, 1, 3, 1, 1> > &output_stream) {
#pragma HLS DATAFLOW
    linebuffer<1, 32, 1, 1>(input_stream, output_stream);
}
