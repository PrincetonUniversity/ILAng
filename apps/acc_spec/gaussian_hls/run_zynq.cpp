#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <math.h>

#include <fcntl.h>
#include <unistd.h>
#include "pipeline_zynq.h"
#include "pipeline_native.h"

#include "benchmark.h"
#include "halide_image.h"
#include "halide_image_io.h"

using namespace Halide::Tools;

class my_load_image {
public:
    my_load_image(const std::string &f) : filename(f) {}
    template<typename ImageType>
    inline operator ImageType() {
        ImageType im;
        (void) load<ImageType, Internal::CheckFail>(filename, &im);
        // shuffle data
        ImageType res(im.channels(), im.width(), im.height());
        for(int c = 0; c < res.extent(0); c++)
            for(int x = 0; x < res.extent(1); x++)
                for(int y = 0; y < res.extent(2); y++)
                    res(c, x, y) = im(x, y, c);
        return res;
    }
private:
  const std::string filename;
};

template<typename ImageType>
void my_save_image(ImageType &im, const std::string &filename) {
    int width = im.extent(1);
    int height = im.extent(2);
    int channels = im.extent(0);
    ImageType shuffled(width, height, channels);
    for(int x = 0; x < width; x++)
        for(int y = 0; y < height; y++)
            for(int c = 0; c < channels; c++)
                shuffled(x, y, c) = im(c, x, y);
    (void) save<ImageType, Internal::CheckFail>(shuffled, filename);
}

int main(int argc, char **argv) {
    // Open the buffer allocation device
    int cma = open("/dev/cmabuffer0", O_RDWR);
    if(cma == -1){
        printf("Failed to open cma provider!\n");
        return(0);
    }

    // open the hardware
    int hwacc = open("/dev/hwacc0", O_RDWR);
    if(hwacc == -1) {
        printf("Failed to open hardware device!\n");
        return(0);
    }

    Image<uint8_t> input = load_image(argv[1]);
    //Image<uint8_t> out_native(3, input.extent(1)-8, input.extent(2)-8);
    //Image<uint8_t> out_zynq(3, input.extent(1)-8, input.extent(2)-8);
    Image<uint8_t> out_native(2400, 3200);
    Image<uint8_t> out_zynq(480, 640);

    printf("start.\n");

    pipeline_native(input, out_native);
    save_image(out_native, "out_native.png");
    printf("cpu program results saved.\n");
    //out_native = load_image("out_native.png");
    //printf("cpu program results loaded.\n");

    pipeline_zynq(input, out_zynq, hwacc, cma);
    save_image(out_zynq, "out_zynq.png");
    printf("accelerator program results saved.\n");

    printf("checking results...\n");

    unsigned fails = 0;
    for (int y = 0; y < out_zynq.height(); y++) {
        for (int x = 0; x < out_zynq.width(); x++) {
            for (int c = 0; c < out_zynq.channels(); c++) {
                if (out_native(x, y, c) != out_zynq(x, y, c)) {
                    printf("out_native(%d, %d, %d) = %d, but out_c(%d, %d, %d) = %d\n",
                           x, y, c, out_native(x, y, c),
                           x, y, c, out_zynq(x, y, c));
                    fails++;
                }
          }
	}
    }
    if (!fails) {
        printf("passed.\n");
    } else  {
        printf("%u fails.\n", fails);
    }

    printf("\nstart timing code...\n");

    // Timing code. Timing doesn't include copying the input data to
    // the gpu or copying the output back.
    double min_t = benchmark(1, 10, [&]() {
            pipeline_native(input, out_native);
        });
    printf("CPU program runtime: %g\n", min_t * 1e3);

    // Timing code. Timing doesn't include copying the input data to
    // the gpu or copying the output back.
    double min_t2 = benchmark(5, 10, [&]() {
            pipeline_zynq(input, out_zynq, hwacc, cma);
        });
    printf("accelerator program runtime: %g\n", min_t2 * 1e3);

    close(hwacc);
    close(cma);
    return 0;
}
