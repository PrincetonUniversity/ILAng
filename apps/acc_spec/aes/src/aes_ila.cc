/// \file the ila example of AES block encryption
///  Hongce Zhang (hongcez@princeton.edu)
///

#include "aes_ila.h"

AES::AES()
    : // construct the model
      model("AES"),
      // I/O interface: this is where the commands come from.
      cmd    (model.NewBvInput("cmd"    , 2 )), 
      cmdaddr(model.NewBvInput("cmdaddr", 16)),
      cmddata(model.NewBvInput("cmddata", 8 )),
      // internal arch state.
      address(model.NewBvState("aes_address", 16 )),
      length (model.NewBvState("aes_length" , 16 )),
      key    (model.NewBvState("aes_key"    , 128)),
      counter(model.NewBvState("aes_counter", 128)),
      status (model.NewBvState("aes_status" , 2  )),
      // the memory: shared state
      xram   (model.NewMemState("XRAM"      , 16, 8)),
      // The encryption function :
      // 128b plaintext x 128b key -> 128b ciphertext
      // FuncRef(name, range, domain1, domain2 )
      aes128(FuncRef("aes128",               // define a function
                          SortRef::BV(128),  // range: 128-bit
                          SortRef::BV(128),  // domain: 128-bit
                          SortRef::BV(128))),//      by 128-bit
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

    instr.SetDecode(
      (cmd == CMD_WRITE) & (cmdaddr >= AES_ADDR) & (cmdaddr < AES_ADDR + 2) );

    instr.SetUpdate(address,
      Ite(is_status_idle, // Check if it is idle
          Concat(         // if idle, update one slice of the register at a time
            Ite(cmdaddr == AES_ADDR + 1, cmddata, address(15,8) ), // the upper 8-bits
            Ite(cmdaddr == AES_ADDR    , cmddata, address( 7,0) )  // the lower 8-bits
          ),
          address        // if not idle, no change
        )); // update a slice of the register. Slice selected by the cmd address

    // guarantees no change
    // if not specified, it means it allows any change
    instr.SetUpdate(length , length );
    instr.SetUpdate(key    , key    );
    instr.SetUpdate(counter, counter);

  }

  // in the above example, you can use :
  /*  
    instr.SetUpdate(address,
                    Ite(is_status_idle, // update only when idle
                        slice_update(address, cmdaddr, cmddata, AES_ADDR,   2,    8),
                        //    target, slice-select, new-value, base-addr, #slice, slice-width
                        //    - Update part (slice) of `target`, with `new-value`
                        //      where `slice-select` choose the slice (after subtracted by 
                        //      `base-addr`) 
                        //    - `#slice`: number of slices in `target`
                        //    - `slice-width`: the width of each slice
                        address));
  */

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
    //instr.SetUpdate(status, status);
    //instr.SetUpdate(counter, counter);
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
