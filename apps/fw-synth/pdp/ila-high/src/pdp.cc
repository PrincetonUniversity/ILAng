// The ILA for the NVDLA planar data processor (PDP)

#include "../include/addr_space.h"
#include "z3++.h"
#include <ilang/ilang++.h>
#include <iostream>

using namespace ilang;

#define MMIO_ADDR_SIZE 16
#define MMIO_DATA_SIZE 32

#define ADDR_SIZE 64
#define DATA_SIZE 8

#define CTRL_SIZE 8
#define INDX_SIZE 8

#define D_OPERATION_MODE_CFG_OP_BEG 0
#define D_OPERATION_MODE_CFG_OP_END 7
#define D_OPERATION_MODE_CFG_FLY_BEG 8
#define D_OPERATION_MODE_CFG_FLY_END 15
#define D_OPERATION_MODE_CFG_NUM_BEG 16
#define D_OPERATION_MODE_CFG_NUM_END 23

void GenPdpIla() {
  // create an ILA object
  auto m = Ila("PDP");

  /* specify state variables **************************************************/
  // command interface to/from memory controller
  auto mmio_rd_cmd = m.NewBvInput("mmio_rd_cmd", 1); // mcif2pdp_rd_req_valid
  auto mmio_wr_cmd = m.NewBvInput("mmio_wr_cmd", 1); // mcif2pdp_wr_req_valid
  auto mmio_addr = m.NewBvInput("mmio_addr", MMIO_ADDR_SIZE);
  auto mmio_wr_val = m.NewBvInput("mmio_wr_val", MMIO_DATA_SIZE);
  auto mmio_rd_val = m.NewBvState("mmio_rd_val", MMIO_DATA_SIZE);

  // hardware specific control signals
  // - S_STATUS
  // - D_OP_ENABLE
  auto status = m.NewBvState("status", CTRL_SIZE); // S_STATUS
  auto enable = m.NewBoolState("enable");          // D_OP_ENABLE
  // - XXX S_POINTER

  // algorithm paramters
  // - D_OPERATION_MODE_CFG
  auto op_mode = m.NewBvState("op_mode", 2);
  auto fly_mode = m.NewBvState("fly_mode", 1);
  auto split_num = m.NewBvState("split_num", CTRL_SIZE);
  // - D_POOLING_KERNEL_CFG
  auto ker_wid = m.NewBvState("kernel_width", CTRL_SIZE);
  auto ker_hgt = m.NewBvState("kernel_height", CTRL_SIZE);
  auto str_wid = m.NewBvState("stride_width", CTRL_SIZE);
  auto str_hgt = m.NewBvState("stride_height", CTRL_SIZE);
  // - D_POOLING_PADDING_CFG
  auto pad_top = m.NewBvState("padding_top", CTRL_SIZE);
  auto pad_bot = m.NewBvState("padding_bottom", CTRL_SIZE);
  auto pad_left = m.NewBvState("padding_left", CTRL_SIZE);
  auto pad_right = m.NewBvState("padding_right", CTRL_SIZE);
  // - D_POOLING_PADDING_VALUE_*_CFG (TODO)
  // - XXX D_NAN_FLUSH_TO_ZERO
  // - XXX D_PARTIAL_WIDTH_IN
  // - XXX D_PARTIAL_WIDTH_OUT
  // - XXX D_RECIP_KERNEL_WIDTH
  // - XXX D_RECIP_KERNEL_HRIGHT

  // input (source) data configuration
  // - D_SRC_BASE_ADDR_LOW/HIGH
  // - D_DATA_CUBE_IN_WIDTH
  // - D_DATA_CUBE_IN_HEIGHT
  // - D_DATA_CUBE_IN_CHANNEL
  auto src_addr = m.NewBvState("src_addr", ADDR_SIZE);
  auto src_wid = m.NewBvState("src_width", CTRL_SIZE);
  auto src_hgt = m.NewBvState("src_height", CTRL_SIZE);
  auto src_chl = m.NewBvState("src_channel", CTRL_SIZE);
  // - D_SRC_LINE_STRIDE (TODO)
  // - D_SRC_SURFACE_STRIDE (TODO)
  // - XXX D_DATA_FORMAT
  // - XXX D_INF_INPUT_NUM
  // - XXX D_NAN_INPUT_NUM

  // output (destination) data
  // - D_DST_BASE_ADDR_LOW/HIGH
  // - D_DATA_CUBE_OUT_WIDTH
  // - D_DATA_CUBE_OUT_HEIGHT
  // - D_DATA_CUBE_OUT_CHANNEL
  auto dst_addr = m.NewBvState("dst_addr", ADDR_SIZE);
  auto dst_wid = m.NewBvState("dst_width", CTRL_SIZE);
  auto dst_hgt = m.NewBvState("dst_height", CTRL_SIZE);
  auto dst_chl = m.NewBvState("dst_channel", CTRL_SIZE);
  // - D_DST_LINE_STRIDE (TODO)
  // - D_DST_SURFACE_STRIDE (TODO)
  // - XXX D_DST_RAM_CFG
  // - XXX D_NAN_OUTPUT_NUM

  // virtual memory for abstracting streaming I/O
  auto src_buff = m.NewMemState("src_buff", INDX_SIZE, DATA_SIZE);
  auto dst_buff = m.NewMemState("dst_buff", INDX_SIZE, DATA_SIZE);

  /* specify fetch function ***************************************************/
  m.SetFetch(Concat(mmio_rd_cmd, Concat(mmio_wr_cmd, mmio_addr)));

  /* specify valid function ***************************************************/
  m.SetValid((mmio_rd_cmd | mmio_wr_cmd) & (mmio_addr >= 0xD000) &
             (mmio_addr <= 0xDFFF));

  /* specify instructions *****************************************************/

  { // write to D_OPERATION_MODE_CFG
    auto instr = m.NewInstr("W_D_OPERATION_MODE_CFG");

    instr.SetDecode((mmio_wr_cmd == 1) &
                    (mmio_addr == ADDR_D_OPERATION_MODE_CFG));

    // from NV_NVDLA_PDP_REG_dual.v
    //  - pooling method: wr_data[1:0]
    //  - flying mode: wr_data[4]
    //  - split number: wr_data[15:8]
    instr.SetUpdate(op_mode, Extract(mmio_wr_val, 1, 0));
    instr.SetUpdate(fly_mode, SelectBit(mmio_wr_val, 4));
    instr.SetUpdate(split_num, Extract(mmio_wr_val, 15, 8));
  }

  { // write to D_SRC_BASE_ADDR_LOW
    auto instr = m.NewInstr("W_D_SRC_BASE_ADDR_LOW");

    instr.SetDecode((mmio_wr_cmd == 1) &
                    (mmio_addr == ADDR_D_SRC_BASE_ADDR_LOW));

    // set the lower 32-bit of the source (input) address
    auto src_addr_next = Concat(Extract(src_addr, 63, 32), mmio_wr_val);
    instr.SetUpdate(src_addr, src_addr_next);
  }

  { // write to D_SRC_BASE_ADDR_HIGH
    auto instr = m.NewInstr("W_D_SRC_BASE_ADDR_HIGH");

    instr.SetDecode((mmio_wr_cmd == 1) &
                    (mmio_addr == ADDR_D_SRC_BASE_ADDR_HIGH));

    // set the higher 32-bit of the source (input) address
    auto src_addr_next = Concat(mmio_wr_val, Extract(src_addr, 31, 0));
    instr.SetUpdate(src_addr, src_addr_next);
  }
}

int main() {
  try {
    GenPdpIla();
  } catch (...) {
    std::cout << "unexpected error.\n";
  }

  return 0;
}
