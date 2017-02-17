#include "Linebuffer.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


template <size_t N, typename T, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3>
void gen_inputs(stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream_1,
		stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &in_stream_2) {
    for (int i = 0; i < N; i++) {
	Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> input;

	for(size_t idx_3 = 0; idx_3 < EXTENT_3; idx_3++)
	for(size_t idx_2 = 0; idx_2 < EXTENT_2; idx_2++)
	for(size_t idx_1 = 0; idx_1 < EXTENT_1; idx_1++)
        for(size_t idx_0 = 0; idx_0 < EXTENT_0; idx_0++)
            input(idx_0, idx_1, idx_2, idx_3) = (T) rand();

	in_stream_1.write(input);
	in_stream_2.write(input);
    }
}


template <size_t N, typename T, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3>
bool check_outputs(stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream_1,
		   stream<PackedStencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream_2) {
    bool success = true;
    for (int i = 0; i < N; i++) {
	Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> output_1 = out_stream_1.read();
	Stencil<T, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> output_2 = out_stream_2.read();

	for(size_t idx_3 = 0; idx_3 < EXTENT_3; idx_3++)
	for(size_t idx_2 = 0; idx_2 < EXTENT_2; idx_2++)
	for(size_t idx_1 = 0; idx_1 < EXTENT_1; idx_1++)
        for(size_t idx_0 = 0; idx_0 < EXTENT_0; idx_0++)
            if (output_1(idx_0, idx_1, idx_2, idx_3) != output_2(idx_0, idx_1, idx_2, idx_3)) {
                printf("check #%d: output_1(%lu, %lu, %lu, %lu) = %d, but output_2(%lu, %lu, %lu, %lu) = %d\n", i,
                       idx_0, idx_1, idx_2, idx_3, output_1(idx_0, idx_1, idx_2, idx_3),
                       idx_0, idx_1, idx_2, idx_3, output_2(idx_0, idx_1, idx_2, idx_3));
                success = false;
            }
    }
    return success;
}

template <size_t N, size_t EXTENT_0, size_t EXTENT_1, size_t EXTENT_2, size_t EXTENT_3>
bool check_outputs(stream<PackedStencil<float, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream_1,
		   stream<PackedStencil<float, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> > &out_stream_2) {
    bool success = true;
    for (int i = 0; i < N; i++) {
	Stencil<float, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> output_1 = out_stream_1.read();
	Stencil<float, EXTENT_0, EXTENT_1, EXTENT_2, EXTENT_3> output_2 = out_stream_2.read();

	for(size_t idx_3 = 0; idx_3 < EXTENT_3; idx_3++)
	for(size_t idx_2 = 0; idx_2 < EXTENT_2; idx_2++)
	for(size_t idx_1 = 0; idx_1 < EXTENT_1; idx_1++)
        for(size_t idx_0 = 0; idx_0 < EXTENT_0; idx_0++)
            if (fabs(output_1(idx_0, idx_1, idx_2, idx_3) - output_2(idx_0, idx_1, idx_2, idx_3)) > 1e-4) {
                printf("output_1(%lu, %lu, %lu, %lu) = %f, but output_2(%lu, %lu, %lu, %lu) = %f\n",
                       idx_0, idx_1, idx_2, idx_3, output_1(idx_0, idx_1, idx_2, idx_3),
                       idx_0, idx_1, idx_2, idx_3, output_2(idx_0, idx_1, idx_2, idx_3));
                success = false;
            }
    }
    return success;
}

void test_1D() {
    hls::stream<PackedStencil<uint8_t, 1> > input_stream, input_ref_stream;
    hls::stream<PackedStencil<uint8_t, 3> > output_stream, output_ref_stream;

    gen_inputs<10>(input_stream, input_ref_stream);

    printf("test linebuffer_1D()... ");
    linebuffer<10>(input_stream, output_stream);
    linebuffer_ref<10>(input_ref_stream, output_ref_stream);

    if (check_outputs<8>(output_stream, output_ref_stream))
	printf("passed!\n");
    else
	printf("failed!\n");
}

void syn_target(hls::stream<PackedStencil<uint8_t, 2, 1> > &input_stream,
                hls::stream<PackedStencil<uint8_t, 2, 3> > &output_stream);

void test_2D() {
    hls::stream<PackedStencil<uint8_t, 2, 1> > input_stream, input_ref_stream;
    hls::stream<PackedStencil<uint8_t, 2, 3> > output_stream, output_ref_stream;

    gen_inputs<10*12>(input_stream, input_ref_stream);

    printf("test linebuffer_2D()... ");
    //linebuffer<20, 12>(input_stream, output_stream);
    syn_target(input_stream, output_stream);

    linebuffer_ref<20, 12>(input_ref_stream, output_ref_stream);

    if (check_outputs<10*10>(output_stream, output_ref_stream))
	printf("passed!\n");
    else
	printf("failed!\n");
}

void test_3D() {
    hls::stream<PackedStencil<uint8_t, 2, 2, 1> > input_stream, input_ref_stream;
    hls::stream<PackedStencil<uint8_t, 2, 2, 3> > output_stream, output_ref_stream;

    gen_inputs<10*10*12>(input_stream, input_ref_stream);

    printf("test linebuffer_3D()... ");
    linebuffer<20, 20, 12>(input_stream, output_stream);

    linebuffer_ref<20, 20, 12>(input_ref_stream, output_ref_stream);

    if (check_outputs<10*10*10>(output_stream, output_ref_stream))
	printf("passed!\n");
    else
	printf("failed!\n");
}

void test_3D_float() {
    hls::stream<PackedStencil<float, 2, 2, 1> > input_stream, input_ref_stream;
    hls::stream<PackedStencil<float, 2, 2, 3> > output_stream, output_ref_stream;

    gen_inputs<10*10*12>(input_stream, input_ref_stream);

    printf("test linebuffer_3D_float()... ");
    linebuffer<20, 20, 12>(input_stream, output_stream);
    //hls_target(input_stream, output_stream);
    linebuffer_ref<20, 20, 12>(input_ref_stream, output_ref_stream);

    if (check_outputs<10*10*10>(output_stream, output_ref_stream))
	printf("passed!\n");
    else
	printf("failed!\n");
}


int main(int argc, char **argv) {
    test_1D();
    test_2D();
    test_3D();
    test_3D_float();
    return 0;
}
