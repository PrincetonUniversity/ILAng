#include <string>

#include <ilang/ila/ast_hub.h>

#include "../unit-include/ila_sim_test.h"

IlaSimTest::IlaSimTest(const std::string& name)
    : model(name), cmd(model.NewBvInput("cmd", 2)),
      cmdaddr(model.NewBvInput("cmdaddr", 16)),
      cmddata(model.NewBvInput("cmddata", 8)),
      cmdflag(model.NewBoolInput("cmdflag")), flag(model.NewBoolState("flag")),
      address(model.NewBvState("address", 16)),
      length(model.NewBvState("length", 16)),
      counter(model.NewBvState("counter", 128)),
      status(model.NewBvState("status", 2)),
      xram(model.NewMemState("XRAM", 16, 8)),
      big_ram(model.NewMemState("big_ram", 32, 32)),
      process128(FuncRef("process128", SortRef::BV(128), SortRef::BV(128),
                         SortRef::BV(128))) {

  nondet_counter = 0;
  model.SetValid((cmd == 1) | (cmd == 2));

  auto is_status_idle = status == STATE_IDLE;

  { // WRITE_ADDRESS
    auto instr = model.NewInstr("WRITE_ADDRESS");
    auto flag_true = asthub::BoolConst(true);
    auto flag_false = asthub::BoolConst(false);

    instr.SetDecode((cmd == CMD_WRITE) & (cmdaddr >= ADDR) &
                    (cmdaddr < ADDR + 2));

    instr.SetUpdate(
        address,
        Ite(is_status_idle,
            Concat(Ite(cmdaddr == ADDR + 1, cmddata / cmddata, address(15, 8)),
                   Ite(cmdaddr == ADDR, cmddata * cmddata, address(7, 0))),
            address));

    instr.SetUpdate(flag, Ite(is_status_idle, flag_true, flag_false));

    instr.SetUpdate(length, length);
    instr.SetUpdate(counter, counter);
  }

  { // START_ENCRYPT
    auto instr = model.NewInstr("START_ENCRYPT");

    instr.SetDecode((cmd == CMD_WRITE) & (cmdaddr == START) & (cmddata == 1));
    instr.SetUpdate(status, Ite(is_status_idle, BvConst(1, 2), unknown(2)()));

    auto child_ila = model.NewChild("ENCRYPT");
    child_ila.SetValid(status != 0);

    auto rd_data = child_ila.NewBvState("rd_data", 128);
    auto enc_data = child_ila.NewBvState("enc_data", 128);
    auto byte_cnt = child_ila.NewBvState("byte_cnt", 4);
    auto blk_cnt = child_ila.NewBvState("blk_cnt", 16);

    child_ila.AddInit(byte_cnt == 0);
    child_ila.AddInit(blk_cnt == 0);
    { // LOAD
      auto child_instr = child_ila.NewInstr("LOAD");

      child_instr.SetDecode(status == STATE_READ_DATA);

      child_instr.SetUpdate(byte_cnt, byte_cnt + 1);
      child_instr.SetUpdate(blk_cnt, blk_cnt);

      auto xram_read_addr = address + blk_cnt + ZExt(byte_cnt, 16);

      child_instr.SetUpdate(rd_data,
                            slice_update(rd_data, byte_cnt,
                                         Load(xram, xram_read_addr), 0, 16, 8));

      child_instr.SetUpdate(
          status, Ite(byte_cnt == 15, BvConst(STATE_OPERATE, 2), status));
    }

    {
      auto child_instr = child_ila.NewInstr("ENC");
      child_instr.SetDecode(
          Imply(status == STATE_OPERATE, status == STATE_OPERATE));
      std::map<NumericType, NumericType> const_map;
      const_map[1] = 10;
      auto const_mem = MemConst(0, const_map, 4, 128);
      auto enc_ctr = counter + Load(const_mem, 1) + ZExt(blk_cnt, 128) +
                     SExt(blk_cnt, 128);
      child_instr.SetUpdate(enc_data, process128(enc_data, enc_ctr) ^ rd_data);
      child_instr.SetUpdate(blk_cnt, blk_cnt);
      child_instr.SetUpdate(status, BvConst(STATE_WRITE_DATA, 2));
    }

    { // store
      auto child_instr = child_ila.NewInstr("STORE");

      child_instr.SetDecode(status == STATE_WRITE_DATA);

      auto xram_write_addr = address + blk_cnt + ZExt(byte_cnt, 16);

      child_instr.SetUpdate(byte_cnt, byte_cnt + 1);

      child_instr.SetUpdate(xram,
                            Ite(flag,
                                Store(xram, xram_write_addr,
                                      slice_read(enc_data, byte_cnt, 0, 16, 8)),
                                xram));

      child_instr.SetUpdate(
          blk_cnt,
          Ite(byte_cnt == 15, Ite(blk_cnt + 16 < length, blk_cnt + 16, blk_cnt),
              blk_cnt));

      child_instr.SetUpdate(
          status, Ite(byte_cnt == 15,
                      Ite(blk_cnt + 16 < length, BvConst(STATE_READ_DATA, 2),
                          BvConst(STATE_IDLE, 2)),
                      status));
    }

    instr.SetProgram(child_ila);
  }
  /// add child
}

ExprRef IlaSimTest::slice_update(const ExprRef& reg, const ExprRef& idx,
                                 const ExprRef& input_slice,
                                 unsigned long base_addr, unsigned num_slice,
                                 unsigned slice_width) {
  auto new_value =
      Ite(idx - base_addr == 0, input_slice, reg(slice_width - 1, 0));
  for (int i = 1; i < num_slice; ++i)
    new_value =
        Concat(Ite(idx - base_addr == i, input_slice,
                   reg(slice_width * i + slice_width - 1, slice_width * i)),
               new_value);
  return new_value;
}

ExprRef IlaSimTest::slice_read(const ExprRef& reg, const ExprRef& idx,
                               unsigned long base_addr, unsigned num_slice,
                               unsigned slice_width) {
  auto slice = reg(slice_width - 1, 0);
  for (int i = 1; i < num_slice; ++i)
    slice = Ite(idx - base_addr == i,
                reg(slice_width * i + slice_width - 1, slice_width * i), slice);
  return slice;
}

FuncRef IlaSimTest::unknown(unsigned width) {
  return FuncRef("unknown" + std::to_string(nondet_counter++),
                 SortRef::BV(width));
}
