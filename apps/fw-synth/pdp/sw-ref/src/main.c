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
  if (size == 0) {
    return 0;
  }

  DATA max = buff[0];
  for (uint8_t i = 1; i < size; i++) {
    if (buff[i] > max)
      max = buff[i];
  }
  return max;
}

DATA Min(DATA *buff, uint8_t size) {
  if (size == 0) {
    return 0;
  }

  DATA min = buff[0];
  for (uint8_t i = 1; i < size; i++) {
    if (buff[i] < min) {
      min = buff[i];
    }
  }
  return min;
}

DATA Avg(DATA *buff, uint8_t size) {
  if (size == 0) {
    return 0;
  }

  DATA acc = 0;
  for (uint8_t i = 0; i < size; i++) {
    acc += buff[i];
  }
  return acc / size;
}

#define KERNEL_BUFF_SIZE 64
bool Pooling(struct AlgoParam algo, struct DataConfig src,
             struct DataConfig dst) {

  DATA buff[KERNEL_BUFF_SIZE];

  uint8_t buff_size = algo.pooling_width * algo.pooling_height;
  uint8_t v_width = src.width + algo.padding_left + algo.padding_right;

  // assume input/output dimension is correct
  for (uint8_t out_x = 0; out_x < dst.width; out_x++) {
    for (uint8_t out_y = 0; out_y < dst.height; out_y++) {
      // start virtual address: (out_x * stride_x, out_y * stride_y)
      // virtual address range: v_start + x + (y * v_width)
      //    v_start = (out_x * stride_x) + (out_y * stride_y * v_width)
      //    v_width = input width + padding_left + padding_right
      //    x in [0, kernel width)
      //    y in [0, kernel height)
      for (uint8_t ker_x = 0; ker_x < algo.pooling_width; ker_x++) {
        for (uint8_t ker_y = 0; ker_y < algo.pooling_height; ker_y++) {
          // calculate the virtual address (serialized)
          uint8_t v_start = (out_x * algo.stride_width) +
                            (out_y * algo.stride_height * v_width);
          uint8_t v_addr = v_start + ker_x + (ker_y * v_width);

          // get the value from input data or padding
          DATA value = 0;
          // FIXME padding value
          if (v_addr < algo.padding_top * v_width) {
            value = 0; // padding top
          } else if (v_addr >= (algo.padding_top + src.height) * v_width) {
            value = 0; // padding bottom
          } else {
            uint8_t v_y_idx = v_addr / v_width;
            uint8_t v_x_idx = v_addr - v_y_idx * v_width;
            if (v_x_idx < algo.padding_left) {
              value = 0; // padding left
            } else if (v_x_idx >= algo.padding_left + src.width) {
              value = 0; // padding right
            } else {     // from inputt
              uint8_t p_addr = (v_y_idx - algo.padding_top) * src.width +
                               (v_x_idx - algo.padding_left);
              value = ((DATA *)src.address)[p_addr];
            }
          }

          // update output data
          uint8_t v_idx = ker_x + ker_y * algo.pooling_width;
          buff[v_idx] = value;
        }
      }

      DATA out_value = 0;
      if (algo.pooling_mode == POOL_MAX) {
        out_value = Max(buff, buff_size);
      } else if (algo.pooling_mode == POOL_MIN) {
        out_value = Min(buff, buff_size);
      } else {
        out_value = Avg(buff, buff_size);
      }
      uint8_t out_idx = out_x + out_y * dst.width;
      ((DATA *)dst.address)[out_idx] = out_value;
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
  algo_param.pooling_mode = POOL_AVG;
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
    if ((i + 1) % SRC_WIDTH == 0) {
      printf("\n");
    }
  }
  printf("\n");

  printf("Output: \n");
  for (int i = 0; i < DST_WIDTH * DST_HEIGHT * DST_CHANNEL; i++) {
    printf("%u ", output_data[i]);
    if ((i + 1) % DST_WIDTH == 0) {
      printf("\n");
    }
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
