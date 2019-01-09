/// \file the ila example of AES block encryption
///  Hongce Zhang (hongcez@princeton.edu)
///

#include "pmesh_l15_ila.h"

// some assumptions on the interface:
// amo_op : 0
// blockinitstore : 0
// blockstore : 0
// csm_data : 0
// data_next_entry : 0
// invalidate_cacheline : 0
// l1rplway : 0
// prefetch : 0
// threadid : 0

// a request if not hit
// go to the NoC
// if hit, ?

PMESH_L15::PMESH_L15()
    : // construct the model
      model("PMESH_L15"),
      // I/O interface: this is where the commands come from.
      address(model.NewBvInput("transducer_l15_address", 40)),
      data   (model.NewBvInput("transducer_l15_data",    64)),
      nc     (model.NewBvInput("transducer_l15_nc",       1)),
      rqtype (model.NewBvInput("transducer_l15_rqtype",   5)),
      size   (model.NewBvInput("transducer_l15_size",     3)),
      val    (model.NewBvInput("transducer_l15_val",      1)),
      
      
      // Output states: l1.5 --> noc1 requests
      l15_noc1buffer_req_address( model.NewBvState("l15_noc1buffer_req_address", 40) ),
      l15_noc1buffer_req_data0  ( model.NewBvState("l15_noc1buffer_req_data0"  , 64) ),
      l15_noc1buffer_req_data1  ( model.NewBvState("l15_noc1buffer_req_data1"  , 64) ),
      l15_noc1buffer_csm_data   ( model.NewBvState("l15_noc1buffer_csm_data  " , 33) ),
      l15_noc1buffer_csm_ticket ( model.NewBvState("l15_noc1buffer_csm_ticket" , 3) ),
      l15_noc1buffer_req_homeid ( model.NewBvState("l15_noc1buffer_req_homeid" , 30) ),
      l15_noc1buffer_req_mshrid ( model.NewBvState("l15_noc1buffer_req_mshrid" , 2) ),
      l15_noc1buffer_req_noncacheable( model.NewBvState("l15_noc1buffer_req_noncacheable" , 1) ),
      l15_noc1buffer_req_prefetch    ( model.NewBvState("l15_noc1buffer_req_prefetch    " , 1) ),
      l15_noc1buffer_req_size        ( model.NewBvState("l15_noc1buffer_req_size        " , 3) ),
      // l15_noc1buffer_req_threadid    ( model.NewBvState("") ), // not
      l15_noc1buffer_req_type        ( model.NewBvState("l15_noc1buffer_req_type        " , 5) )
    {

  // L1.5 fetch function -- what corresponds to instructions on L1.5 PCX interface
  model.SetFetch( lConcat({address, data, nc, rqtype, size, val })   );
  // Valid instruction: what means to have valid command (valid = 1)
  model.SetValid( val == 1 );

  // 
  // HZ's note about modeling cache
  // This is in some sense a shared memory
  // 1. we can model it as a memory, but this does not
  // mean it must have that size (The same address
  // and etc. of facet axiom function can be adjusted
  // to factor in the conflict-eviction and etc.
  // This part should be 
  // 2. It is a shared state
  // because we have multiple interface
  // This is in some sence similar to the ViCL approach
  // But hte difference is that we treat the Cache state
  // as "state", and encode the updates as SMT queries
  // 
  // For the verification, we need to somehow use an uninterpreted
  // function-like mapping on what it got from the mem
  // 

  // add instructions
  {
    auto instr = model.NewInstr("LOAD_normal");


  }


  { // WRITE_ADDRESS
    auto instr = model.NewInstr("WRITE_ADDRESS");

    instr.SetDecode( (cmd == CMD_WRITE) & (cmdaddr >= AES_ADDR) & (cmdaddr < AES_ADDR + 2) );

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
