// Main function of the planar data processor (PDP) software reference model.

/* Input variables:
 *  1. algorithm variable,
 *  2. input dimension,
 *  3. output dimension
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

// DATA_PRECISION
typedef uint8_t DATA;

// POOLING_METHOD
#define POOL_MAX 0
#define POOL_MIN 1
#define POOL_AVG 2

// DATA_TYPE
#define DLA_MEM_MC 0
#define DLA_MEM_CV 1
#define DLA_MEM_HW 2

struct AlgoParam {
  uint8_t pooling_mode; // (POOLING_METHOD, FLYING_MODE, SPLIT_NUM)
  uint8_t pooling_width; 
  uint8_t pooling_height;
  uint8_t stride_width;
  uint8_t stride_height;
  uint8_t padding_left;
  uint8_t padding_right;
  uint8_t padding_top;
  uint8_t padding_bottom;
  int32_t padding_value[7];
};

struct DataConfig {
  uint16_t data_type; // DATA_TYPE
  uint64_t address;
  uint16_t width;
  uint16_t height;
  uint16_t channel;
  uint32_t line_stride;
  uint32_t surface_stride;
};

// return the max (replaced by un-interpreted function)
DATA Max(DATA *buff, uint8_t size) {
  if (size == 0) 
    return 0;

  DATA max = buff[0];
  for (uint8_t i = 1; i < size; i++) {
    if (buff[i] > max) 
      max = buff[i];
  }
  return max;
}

#define KERNEL_BUFF_SIZE 64
bool Pooling(struct AlgoParam algo_param, struct DataConfig src_config,
             struct DataConfig dst_config) {

  DATA buff[KERNEL_BUFF_SIZE];

  uint8_t buff_size = algo_param.width * algo_param.height;

  // assume input/output dimension is correct
  for (uint8_t out_x = 0; out_x < dst_config.width; out_x++) {
    for (uint8_t out_y = 0; out_y < dst_config.height; out_y++) {
      // start virtual address: (out_x * stride_x, out_y * stride_y)
      // virtual address range: start + x + (y * virtual width)
      //                        x in [0, kernel width)
      //                        y in [0, kernel height)
      //                        virtual width = input width + stride width
      uint8_t virtual_address = 0;
    }
  }

  return true;
}

#define SRC_WIDTH 4
#define SRC_HEIGHT 4
#define SRC_CHANNEL 1
#define SRC_LINE_STRIDE 0
#define SRC_SURFACE_STRIDE 0

#define DST_WIDTH 3
#define DST_HEIGHT 3
#define DST_CHANNEL SRC_CHANNEL
#define DST_LINE_STRIDE 0
#define DST_SURFACE_STRIDE 0

bool Test() {
  struct AlgoParam algo_param;
  struct DataConfig src_config;
  struct DataConfig dst_config;

  // define algorithm parameters
  algo_param.pooling_mode = POOL_MAX;
  algo_param.pooling_width = 2;
  algo_param.pooling_height = 2;
  algo_param.stride_width = 2;
  algo_param.stride_height = 1;
  algo_param.padding_left = 1;
  algo_param.padding_right = 1;
  algo_param.padding_top = 0;
  algo_param.padding_bottom = 0;
  for (int i = 0; i < 7; i++) {
    algo_param.padding_value[i] = 0; // FIXME: not sure how does it operate
  }

  // create input data
  DATA input_data[SRC_WIDTH * SRC_HEIGHT * SRC_CHANNEL];
  src_config.data_type = DLA_MEM_HW;
  src_config.address = (uint64_t)input_data;
  src_config.width = SRC_WIDTH;
  src_config.height = SRC_HEIGHT;
  src_config.channel = SRC_CHANNEL;
  src_config.line_stride = SRC_LINE_STRIDE;
  src_config.surface_stride = SRC_SURFACE_STRIDE;

  for (int i = 0; i < SRC_WIDTH * SRC_HEIGHT * SRC_CHANNEL; i++) {
    input_data[i] = i;
  }

  // create output holder
  DATA output_data[DST_WIDTH * DST_HEIGHT * DST_CHANNEL];
  dst_config.data_type = DLA_MEM_MC;
  dst_config.address = (uint64_t)output_data;
  dst_config.width = DST_WIDTH;
  dst_config.height = DST_HEIGHT;
  dst_config.channel = DST_CHANNEL;
  dst_config.line_stride = DST_LINE_STRIDE;
  dst_config.surface_stride = DST_SURFACE_STRIDE;

  bool ret = Pooling(algo_param, src_config, dst_config);

  printf("Input: \n");
  for (int i = 0; i < SRC_WIDTH * SRC_HEIGHT * SRC_CHANNEL; i++) {
    printf("%u ", input_data[i]);
  }
  printf("\n");

  printf("Output: \n");
  for (int i = 0; i < DST_WIDTH * DST_HEIGHT * DST_CHANNEL; i++) {
    printf("%u ", output_data[i]);
  }
  printf("\n");

  return ret;
}

int main() {
  bool ret = Test();

  if (!ret)
    return -1;

  return 0;
}
