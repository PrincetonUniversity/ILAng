/// \file
/// Example model -- simple stream buffer.

#include "../unit-include/stream_buffer.h"
#include <ilang/ilang++.h>
#include <ilang/util/log.h>

namespace ilang {

Ila ExmpStrmBuff::GetStrmBuffSpec(const std::string& name) {
  Ila m(name);

  // state var
  std::vector<ExprRef> buff;
  for (auto i = 0; i != buff_size(); i++) {
    buff.push_back(m.NewBvState("buff_" + std::to_string(i), reg_size()));
  }
  auto cnt = m.NewBvState("cnt", reg_size());
  auto out_wr_en = m.NewBoolState("wr_en");
  auto out_rd_en = m.NewBoolState("rd_en");
  auto out_data = m.NewBvState("out_data", reg_size());

  // inputs
  auto in_wr = m.NewBoolInput("wr");
  auto in_rd = m.NewBoolInput("rd");
  auto in_data = m.NewBvInput("in_data", reg_size());

  // valid
  m.SetValid(in_wr | in_rd);

  { // write instruction
    auto instr = m.NewInstr("write");
    instr.SetDecode(in_wr & out_wr_en);

    instr.SetUpdate(buff[0], in_data);
    for (auto i = 1; i != buff_size(); i++) {
      auto next_i = buff[i - 1];
      instr.SetUpdate(buff[i], next_i);
    }
    instr.SetUpdate(cnt, cnt + 1);
    instr.SetUpdate(out_wr_en, (cnt < buff_size() - 1));
    instr.SetUpdate(out_rd_en, (cnt >= 0)); // or true
  }

  { // read instruction
    auto instr = m.NewInstr("read");
    instr.SetDecode(in_rd & out_rd_en);
    // TODO use cnt as the pointer for reading (review write)
  }

  return m;
}

std::shared_ptr<InstrLvlAbs>
ExmpStrmBuff::GetStrmBuffSpecRaw(const std::string& name) {
  auto m = GetStrmBuffSpec(name);
  return m.get();
}

} // namespace ilang
