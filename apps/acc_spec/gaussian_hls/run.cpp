#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <math.h>

#include "pipeline_hls.h"
#include "pipeline_native.h"

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
        //ImageType res(3, 256+8, 256+8);
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
    Image<uint8_t> input = load_image(argv[1]);
    Image<uint8_t> out_native(input.width()-8, input.height()-8);
    Image<uint8_t> out_hls(480, 640);

    printf("start.\n");

    pipeline_native(input, out_native);
    save_image(out_native, "out.png");

    printf("finish running native code\n");
    pipeline_hls(input, out_hls);

    printf("finish running HLS code\n");

    unsigned fails = 0;
    for (int y = 0; y < out_hls.height(); y++) {
        for (int x = 0; x < out_hls.width(); x++) {
            for (int c = 0; c < out_hls.channels(); c++) {
                if (out_native(x, y, c) != out_hls(x, y, c)) {
                    printf("out_native(%d, %d, %d) = %d, but out_c(%d, %d, %d) = %d\n",
                           x, y, c, out_native(x, y, c),
                           x, y, c, out_hls(x, y, c));
                    fails++;
                }
          }
	}
    }
    if (!fails) {
        printf("passed.\n");
        return 0;
    } else  {
        printf("%u fails.\n", fails);
        return 1;
    }
    return 0;
}
