#include "../unit-include/validate_aes_model.h"
#include <cmath>
#include <string>

AES::AES()
    : // construct the model
      model("AES"),
      // I/O interface: this is where the commands come from.
      cmd(model.NewBvInput("cmd", 2)), cmdaddr(model.NewBvInput("cmdaddr", 16)),
      cmddata(model.NewBvInput("cmddata", 8)),
      // internal arch state.
      address(model.NewBvState("aes_address", 16)),
      length(model.NewBvState("aes_length", 16)),
      key(model.NewBvState("aes_key", 128)),
      counter(model.NewBvState("aes_counter", 128)),
      status(model.NewBvState("aes_status", 2)),
      // the memory: shared state
      xram(model.NewMemState("XRAM", 16, 8)),
      // The encryption function :
      // 128b plaintext x 128b key -> 128b ciphertext
      // FuncRef(name, range, domain1, domain2 )
      aes128(FuncRef("aes128",           // define a function
                     SortRef::BV(128),   // range: 128-bit
                     SortRef::BV(128),   // domain: 128-bit
                     SortRef::BV(128))), //      by 128-bit
      // the output
      outdata(model.NewBvState("outdata", 8)) {

  // AES fetch function -- what corresponds to instructions
  model.SetFetch(Concat(cmd, Concat(cmdaddr, cmddata)));
  // Valid instruction: cmd == 1 or cmd == 2
  model.SetValid((cmd == 1) | (cmd == 2));

  // some shortcuts
  auto is_status_idle = status == AES_STATE_IDLE;

  // add instructions

  { // WRITE_ADDRESS
    auto instr = model.NewInstr("WRITE_ADDRESS");

    instr.SetDecode((cmd == CMD_WRITE) & (cmdaddr >= AES_ADDR) &
                    (cmdaddr < AES_ADDR + 2));

    instr.SetUpdate(
        address,
        Ite(is_status_idle, // Check if it is idle
            Concat( // if idle, update one slice of the register at a time
                Ite(cmdaddr == AES_ADDR + 1, cmddata,
                    address(15, 8)), // the upper 8-bits
                Ite(cmdaddr == AES_ADDR, cmddata,
                    address(7, 0)) // the lower 8-bits
                ),
            address // if not idle, no change
            ));     // update a slice of the register. Slice selected by the cmd
                    // address

    // guarantees no change
    // if not specified, it means it allows any change
    instr.SetUpdate(length, Ite(is_status_idle, length + 1, length));
    instr.SetUpdate(key, key);
    instr.SetUpdate(counter, counter);
  }

  { // START_ENCRYPT
    // See child-ILA for details
    auto instr = model.NewInstr("START_ENCRYPT");

    instr.SetDecode((cmd == CMD_WRITE) & (cmdaddr == AES_START) &
                    (cmddata == 1));
    // if it is idle, we will start, if it is not idle, there is no guarantee
    // what it may become
    instr.SetUpdate(status, Ite(is_status_idle, BvConst(1, 2), unknown(2)()));

    AddChild(instr);
    // You can have a tighter guarantee there:
    // instr.SetUpdate( status,
    //    Ite( is_status_idle , BvConst(1,2) ,
    //         unknown_choice( status + 1 , BvConst(0,2) ) ) );

    // Another choice is that you make the is_status_idle condition as part of
    // the instruction decode That means, this instruction only talks about the
    // conidition when it is idle
  }

  { // READ_LENGTH
    auto instr = model.NewInstr("READ_LENGTH");

    instr.SetDecode((cmd == CMD_READ) & (cmdaddr >= AES_LENGTH) &
                    (cmdaddr < AES_LENGTH + 2));

    instr.SetUpdate(outdata, slice_read(length, cmdaddr, AES_LENGTH, 2, 8));

    // guarantees no change when the instruction executes
    // if you don't write them, that means no guarantees
    instr.SetUpdate(key, key);
    instr.SetUpdate(address, address);
    instr.SetUpdate(length, length);
    // but not the following two:
    // instr.SetUpdate(status, status);
    // instr.SetUpdate(counter, counter);
  }

  { // READ_ADDRESS
    auto instr = model.NewInstr("READ_ADDRESS");

    instr.SetDecode((cmd == CMD_READ) & (cmdaddr >= AES_ADDR) &
                    (cmdaddr < AES_ADDR + 2));

    instr.SetUpdate(outdata, slice_read(address, cmdaddr, AES_ADDR, 2, 8));

    // guarantee no change
    instr.SetUpdate(key, key);
    instr.SetUpdate(address, address);
    instr.SetUpdate(length, length);
    // but not the following two:
    // instr.SetUpdate(status, status);
    // instr.SetUpdate(counter, counter);
  }

  { // READ_KEY
    auto instr = model.NewInstr("READ_KEY");

    instr.SetDecode((cmd == CMD_READ) & (cmdaddr >= AES_KEY) &
                    (cmdaddr < AES_KEY + 16));

    instr.SetUpdate(outdata, slice_read(key, cmdaddr, AES_KEY, 16, 8));

    // guarantee no change
    instr.SetUpdate(key, key);
    instr.SetUpdate(address, address);
    instr.SetUpdate(length, length);

    // but not the following two:
    // instr.SetUpdate(status, status);
    // instr.SetUpdate(counter, counter);
  }

  { // READ_COUNTER
    auto instr = model.NewInstr("READ_COUNTER");

    instr.SetDecode((cmd == CMD_READ) & (cmdaddr >= AES_CNT) &
                    (cmdaddr < AES_CNT + 16));

    instr.SetUpdate(outdata, slice_read(counter, cmdaddr, AES_CNT, 16, 8));

    // guarantee no change
    instr.SetUpdate(key, key);
    instr.SetUpdate(address, address);
    instr.SetUpdate(length, length);
  }

  { // GET_STATUS
    auto instr = model.NewInstr("GET_STATUS");

    instr.SetDecode((cmd == CMD_READ) & (cmdaddr >= AES_CNT) &
                    (cmdaddr < AES_CNT + 16));

    instr.SetUpdate(outdata, slice_read(counter, cmdaddr, AES_CNT, 16, 8));

    // guarantee no change
    instr.SetUpdate(key, key);
    instr.SetUpdate(address, address);
    instr.SetUpdate(length, length);
  }

  { // WRITE_LENGTH
    auto instr = model.NewInstr("WRITE_LENGTH");

    instr.SetDecode((cmd == CMD_WRITE) & (cmdaddr >= AES_LENGTH) &
                    (cmdaddr < AES_LENGTH + 2));

    instr.SetUpdate(
        length,
        Ite(is_status_idle,
            slice_update(length, cmdaddr, cmddata, AES_LENGTH, 2, 8), length));

    // guarantee no change
    instr.SetUpdate(address, address);
    instr.SetUpdate(key, key);
    instr.SetUpdate(counter, counter);
    // but not for status
    // you can explicitly status how much you know about it
    // these are the non-deterministics in the spec
    instr.SetUpdate(status, Ite(is_status_idle, status, unknown(2)()));
  }

  { // WRITE_KEY
    auto instr = model.NewInstr("WRITE_KEY");

    instr.SetDecode((cmd == CMD_WRITE) & (cmdaddr >= AES_KEY) &
                    (cmdaddr < AES_KEY + 16));

    instr.SetUpdate(
        key, Ite(is_status_idle,
                 slice_update(key, cmdaddr, cmddata, AES_KEY, 16, 8), key));

    // guarantee no change
    instr.SetUpdate(address, address);
    instr.SetUpdate(length, length);
    instr.SetUpdate(counter, counter);
    // but not for status
  }

  { // WRITE_COUNTER
    auto instr = model.NewInstr("WRITE_COUNTER");

    instr.SetDecode((cmd == CMD_WRITE) & (cmdaddr >= AES_CNT) &
                    (cmdaddr < AES_CNT + 16));

    instr.SetUpdate(counter,
                    Ite(is_status_idle,
                        slice_update(counter, cmdaddr, cmddata, AES_CNT, 16, 8),
                        unknown(128)()));

    // if you want a more explicit sepcification
    // you can replace the last line with
    // unknown_choice(counter, counter + unknown_range(1,16) ) ) );

    // guarantee no change
    instr.SetUpdate(key, key);
    instr.SetUpdate(address, address);
    // but not for status
  }

  /// add child
}

void AES::AddChild(InstrRef& inst) {
  auto child = model.NewChild("AES_BLOCK");

  child.SetValid(status != 0);
  child.SetFetch(status);

  auto rd_data = child.NewBvState("rd_data", 128);
  auto enc_data = child.NewBvState("enc_data", 128);
  auto byte_cnt = child.NewBvState("byte_cnt", 4);
  auto blk_cnt = child.NewBvState("blk_cnt", 16);

  // init conditions : when doing verification
  // should be exported as the status update of the higher-level
  // triggering instruction
  child.AddInit(byte_cnt == 0);
  child.AddInit(blk_cnt == 0);
  // child.AddInit( oped_byte_cnt == 0 );

  { // LOAD byte-by-byte
    auto instr = child.NewInstr("LOAD");

    instr.SetDecode(status == AES_STATE_READ_DATA);

    instr.SetUpdate(byte_cnt, byte_cnt + 1);
    instr.SetUpdate(blk_cnt, blk_cnt);

    auto xram_read_addr = address + blk_cnt + ZExt(byte_cnt, 16);

    instr.SetUpdate(
        rd_data,
        slice_update(rd_data, byte_cnt, Load(xram, xram_read_addr), 0, 16, 8));

    instr.SetUpdate(status,
                    Ite(byte_cnt == 15, BvConst(AES_STATE_OPERATE, 2), status));
  }

  { // encrypt -- aes 128 function describe separately
    auto instr = child.NewInstr("OPERATE");

    instr.SetDecode(status == AES_STATE_OPERATE);

    // counter mode : ciphertext = E(ctr) ^ plaintext
    auto enc_ctr = counter + ZExt(blk_cnt, 128);

    instr.SetUpdate(enc_data, aes128(enc_ctr, key) ^ rd_data);

    instr.SetUpdate(blk_cnt, blk_cnt);

    instr.SetUpdate(status, BvConst(AES_STATE_WRITE_DATA, 2));
  }

  { // store byte-by-byte
    auto instr = child.NewInstr("STORE");

    instr.SetDecode(status == AES_STATE_WRITE_DATA);

    auto xram_write_addr = address + blk_cnt + ZExt(byte_cnt, 16);

    instr.SetUpdate(byte_cnt, byte_cnt + 1);

    instr.SetUpdate(xram, Store(xram, xram_write_addr,
                                slice_read(enc_data, byte_cnt, 0, 16, 8)));

    instr.SetUpdate(blk_cnt, Ite(byte_cnt == 15, Ite(blk_cnt + 16 < length,
                                                     blk_cnt + 16, blk_cnt),
                                 blk_cnt));

    instr.SetUpdate(status,
                    Ite(byte_cnt == 15, // the last byte has been written to
                        Ite(blk_cnt + 16 < length, // if we reach the length
                            BvConst(AES_STATE_READ_DATA, 2), //
                            BvConst(AES_STATE_IDLE, 2)),
                        status));
  }

  inst.SetProgram(child);
}

ExprRef AES::unknown_range(unsigned low, unsigned high) {
  unsigned width = (unsigned)std::ceil(std::log2(high + 1));
  auto val = unknown(width)();
  model.AddInit((val >= low) & (val <= high));
  return val;
}

ExprRef AES::unknown_choice(const ExprRef& a, const ExprRef& b) {
  return Ite(unknown(1)() == 1, a, b);
}

// input_slice.width == slice_width
// num_slice * slice_width == reg.width
ExprRef AES::slice_update(const ExprRef& reg, const ExprRef& idx,
                          const ExprRef& input_slice, unsigned long base_addr,
                          unsigned num_slice, unsigned slice_width) {
  auto new_value =
      Ite(idx - base_addr == 0, input_slice, reg(slice_width - 1, 0));
  for (int i = 1; i < num_slice; ++i)
    new_value =
        Concat(Ite(idx - base_addr == i, input_slice,
                   reg(slice_width * i + slice_width - 1, slice_width * i)),
               new_value);
  return new_value;
}

ExprRef AES::slice_read(const ExprRef& reg, const ExprRef& idx,
                        unsigned long base_addr, unsigned num_slice,
                        unsigned slice_width) {
  auto slice = reg(slice_width - 1, 0);
  for (int i = 1; i < num_slice; ++i)
    slice = Ite(idx - base_addr == i,
                reg(slice_width * i + slice_width - 1, slice_width * i), slice);
  return slice;
}

//---------------------------------------------------------------------

unsigned nondet_counter = 0;

FuncRef AES::unknown(unsigned width) {
  return FuncRef("unknown" + std::to_string(nondet_counter++),
                 SortRef::BV(width));
}
