/// file
/// The implementation for LMAC ILA.

#include "lmac.h"

namespace ilang {

Ila GetLmacIla(const std::string& name) {
  auto lmac = Ila("LMAC");
  DefineArchState(lmac);
  DefineInstruction(lmac);
  return lmac;
}

void DefineArchState(Ila& m) {
  // --- implementation dependent
  auto clk = m.NewBoolInput("clk");         // positive edge
  auto reg_clk = m.NewBoolInput("reg_clk"); // positive edge
  auto rst = m.NewBoolInput("rst");         // low true
  auto phy_rst = m.NewBoolInput("phy_rst"); // low true

  // --- static signals
  auto link_up = m.NewBoolState("link_up");     // 1 indicating ethernet is up
  auto mac_ctrl = m.NewBvInput("mac_ctrl", 32); // configuration control signals
  auto mac_ctrl_1 = m.NewBvInput("mac_ctrl_1", 32); // the second set of config.
  auto mac_rxv_en = m.NewBoolInput("mac_rxv_en");   // 1 for receive path enable

  // --- register interface
  auto host_addr = m.NewBvInput("host_addr", 16);
  // byte address for selecting MMIO registers
  // valid 1 clock cycle before the "reg_read_start" signal

  auto reg_read_start = m.NewBoolInput("reg_read_start");
  // pulse (up for one and exactly one cycle)
  // 1 for starting the read for a register in the LMAC core
  // 0 for idle

  auto read_reg_done_out = m.NewBoolState("read_reg_done_out");
  // indicating the register read is done and its data is available on the
  // MAC_REGDOUT bus
  // pulse (up for one and exactly one cycle, even it is and output)
  // 1 for data is ready for the read to the register
  // 0 for data not available
  // * It is the 5-clock delay of the "reg_read_start" signal

  auto mac_reg_d_out = m.NewBvState("mac_reg_d_out", 32);
  // the 32-bit read data

  // --- MMIO registers
#define MMIO_REG_SIZE 32
  auto fmac_tx_pkt_cnt = m.NewBvState("FMAC_TX_PKT_CNT", MMIO_REG_SIZE);
  auto fmac_rx_pkt_cnt_lo = m.NewBvState("FMAC_RX_PKT_CNT_LO", MMIO_REG_SIZE);
  auto fmac_rx_pkt_cnt_hi = m.NewBvState("FMAC_RX_PKT_CNT_HI", MMIO_REG_SIZE);
  auto fmac_tx_byte_cnt = m.NewBvState("FMAC_TX_BYTE_CNT", MMIO_REG_SIZE);
  auto fmac_rx_byte_cnt_lo = m.NewBvState("FMAC_RX_BYTE_CNT_LO", MMIO_REG_SIZE);
  auto fmac_rx_byte_cnt_hi = m.NewBvState("FMAC_RX_BYTE_CNT_HI", MMIO_REG_SIZE);
  // TODO

  return;
}

void DefineInstruction(Ila& m) {
  auto instr_read_tx_pkt_cnt = m.NewInstr("READ_FMAC_TX_PKT_CNT");
  {
    // decode
    auto decode = (m.input("read_reg_start") == 1) &
                  (m.input("host_addr") == LMAC_MMIO_OFFSET_FMAC_TX_PKT_CNT);
    instr_read_tx_pkt_cnt.SetDecode(decode);
    // updates
    auto data_val = m.state("fmac_tx_pkt_cnt");
    instr_read_tx_pkt_cnt.SetUpdate(m.state("mac_reg_d_out"), data_val);

    // XXX to model at the cycle accurate level (5 cycles delay), we can use
    // child-instructions to model the 5 dummy instructios
    // XXX does the verification target generation handle edge dependent
    // properties? (one and exactly one cycle)
  }

  // TODO
  return;
}

}; // namespace ilang

