/// \file the ila example of AES block encryption
///  Hongce Zhang (hongcez@princeton.edu)
///

#include "aes_ila.h"

AES::AES() : 
// construct the model
model("AES"),
// I/O interface: this is where the commands come from.
cmd     ( model.NewBvInput("cmd",      2)   ),
cmdaddr ( model.NewBvInput("cmdaddr", 16)   ),
cmddata ( model.NewBvInput("cmddata",  8)   ),
// internal arch state.
state   ( model.NewBvState('aes_state', 2)  ),
opaddr  ( model.NewBvState('aes_addr', 16)  ),
oplen   ( model.NewBvState('aes_len',  16)  ),
ctr     ( model.NewBvState('aes_ctr', 128)  ),
key     ( model.NewBvState('aes_key', 128)  ),
// the memory: shared state
xram    ( model.NewMemState('XRAM', 16, 8)  ),
// The encryption function : 
// 128b plaintext x 128b key -> 128b ciphertext
// FuncRef(name, range, domain1, domain2 )
aes128  ( FuncRef('aes128', 128, 128, 128 ) ), 
// the output
outdata ( model.NewBvState('outdata',   8 ) ),
{

  // AES fetch function -- what corresponds to instructions
  model.SetFetch( Concat( cmd, Concat(cmdaddr, cmddata) ) );
  // Valid instruction: cmd == 1 or cmd == 2
  model.SetValid( (cmd == 1) | (cmd == 2) )
  
  // some shortcuts
  auto is_idle = status == AES_STATE_IDLE; // change to status .. move to beginning

  // add instructions

  { // WRITE_ADDRESS
    auto instr = model.NewInstr("WRITE_ADDRESS");

    instr.SetDecode( ( cmd == CMD_WRITE ) & ( cmdaddr >= AES_ADDR  ) & ( cmdaddr < AES_ADDR + 2 ) );
    
    instr.SetUpdate( opaddr, 
      Ite( is_idle,                                                   
           slice_update( opaddr, cmdaddr, cmddata, AES_ADDR, 2, 8 ) , 
           // update part of opaddr, based on the cmdaddr
           opaddr ) );

    // guarantee no change
    instr.SetUpdate( oplen, oplen );
    instr.SetUpdate( key,   key   ); 
    instr.SetUpdate( ctr,   ctr   );
  }

  { // START_ENCRYPT 
    // See child-ILA for details
    auto instr = model.NewInstr("START_ENCRYPT"); 

    instr.SetDecode( ( cmd == CMD_WRITE ) & ( cmdaddr == AES_START  ) & ( cmddate == 1 ) );
    // if it is idle, we will start, if it is not idle, there is no guarantee what it may become
    instr.SetUpdate( state, Ite( is_idle , BvConst(1,2) , unknown(2)() ) );

    AddChild(instr);
    // You can have a tighter guarantee there:
    // instr.SetUpdate( state, 
    //    Ite( is_idle , BvConst(1,2) , 
    //         unknown_choice( state + 1 , BvConst(0,2) ) ) );

    // Another choice is that you make the is_idle condition as part of the instruction decode
    // That means, this instruction only talks about the conidition when 
    // it is idle
  }

  { // READ_LENGTH
    auto instr = model.NewInstr("READ_LENGTH");

    instr.SetDecode( ( cmd == CMD_READ ) & ( cmdaddr >= AES_LENGTH  ) & ( cmdaddr < AES_LENGTH + 2 ) );
    
    instr.SetUpdate( outdata, slice_read( oplen, cmdaddr, AES_LENGTH, 2, 8 ) );

    // guarantees no change when the instruction executes
    // if you don't write them, that means no guarantees
    instr.SetUpdate( key,    key    ); 
    instr.SetUpdate( opaddr, opaddr );
    instr.SetUpdate( oplen,  oplen  ); 
    instr.SetUpdate( state,  state  );
    instr.SetUpdate( ctr,    ctr    );
  }  

  { // READ_ADDRESS
    auto instr = model.NewInstr("READ_ADDRESS");

    instr.SetDecode( ( cmd == CMD_READ ) & ( cmdaddr >= AES_ADDR  ) & ( cmdaddr < AES_ADDR + 2 ) );

    instr.SetUpdate( outdata, slice_read( opaddr, cmdaddr, AES_ADDR, 2, 8 ) );

    // guarantee no change
    instr.SetUpdate( key,    key    ); 
    instr.SetUpdate( opaddr, opaddr );
    instr.SetUpdate( oplen,  oplen  ); 
    instr.SetUpdate( state,  state  );
    instr.SetUpdate( ctr,    ctr    );
  }


  { // READ_KEY
    auto instr = model.NewInstr("READ_KEY");

    instr.SetDecode( ( cmd == CMD_READ ) & ( cmdaddr >= AES_KEY  ) & ( cmdaddr < AES_KEY + 16 ) );

    instr.SetUpdate( outdata, slice_read( key, cmdaddr, AES_KEY, 16, 8 ) );

    // guarantee no change
    instr.SetUpdate( key,    key    ); 
    instr.SetUpdate( opaddr, opaddr );
    instr.SetUpdate( oplen,  oplen  ); 
    instr.SetUpdate( state,  state  );
    instr.SetUpdate( ctr,    ctr    );
  }

  { // READ_COUNTER
    auto instr = model.NewInstr("READ_COUNTER");

    instr.SetDecode( ( cmd == CMD_READ ) & ( cmdaddr >= AES_CNT  ) & ( cmdaddr < AES_CNT + 16 ) );

    instr.SetUpdate( outdata, slice_read( ctr, cmdaddr, AES_CNT, 16, 8 ) );

    // guarantee no change
    instr.SetUpdate( key,    key    ); 
    instr.SetUpdate( opaddr, opaddr );
    instr.SetUpdate( oplen,  oplen  ); 
    instr.SetUpdate( state,  state  );
    instr.SetUpdate( ctr,    ctr    );
  }

  { // GET_STATUS
    auto instr = model.NewInstr("GET_STATUS");

    instr.SetDecode( ( cmd == CMD_READ ) & ( cmdaddr >= AES_CNT  ) & ( cmdaddr < AES_CNT + 16 ) );

    instr.SetUpdate( outdata, slice_read( ctr, cmdaddr, AES_CNT, 16, 8 ) );

    // guarantee no change
    instr.SetUpdate( key,    key    ); 
    instr.SetUpdate( opaddr, opaddr );
    instr.SetUpdate( oplen,  oplen  ); 
    instr.SetUpdate( state,  state  );
    instr.SetUpdate( ctr,    ctr    );
  }

  { // WRITE_LENGTH
    auto instr = model.NewInstr("WRITE_LENGTH");

    instr.SetDecode( ( cmd == CMD_WRITE ) & ( cmdaddr >= AES_LENGTH  ) & ( cmdaddr < AES_LENGTH + 2 ) );
    
    instr.SetUpdate( oplen, 
      Ite( is_idle, 
           slice_update( oplen, cmdaddr, cmddate, AES_LENGTH, 2, 8 ) , 
           oplen ) );

    // guarantee no change
    instr.SetUpdate( opaddr, opaddr );
    instr.SetUpdate( key,   key ); 
    instr.SetUpdate( ctr,   ctr   );
    // but not for state
    // you can explicitly state how much you know about it
    // these are the non-deterministics in the spec
    instr.SetUpdate( state, Ite(is_idle, state, unknown(2)() ) );
  }

  { // WRITE_KEY
    auto instr = model.NewInstr("WRITE_KEY");

    instr.SetDecode( ( cmd == CMD_WRITE ) & ( cmdaddr >= AES_KEY  ) & ( cmdaddr < AES_KEY + 16 ) );
    
    instr.SetUpdate( key, 
      Ite( is_idle, 
           slice_update( key, cmdaddr, cmddate, AES_KEY, 16, 8 ) , 
           key ) );

    // guarantee no change
    instr.SetUpdate( opaddr, opaddr );
    instr.SetUpdate( oplen,  oplen  ); 
    instr.SetUpdate( ctr,   ctr   );
    // but not for state
  }

  { // WRITE_KEY
    auto instr = model.NewInstr("WRITE_CNT");

    instr.SetDecode( ( cmd == CMD_WRITE ) & ( cmdaddr >= AES_CNT  ) & ( cmdaddr < AES_CNT + 16 ) );
    
    instr.SetUpdate( ctr, 
      Ite( is_idle, 
           slice_update( ctr, cmdaddr, cmddate, AES_CNT, 16, 8 ) , 
           unknown(128) ) );

    // if you want a more explicit sepcification
    // you can replace the last line with
    // unknown_choice(ctr, ctr + unknown_range(1,16) ) ) );

    // guarantee no change
    instr.SetUpdate( key,    key    ); 
    instr.SetUpdate( opaddr, opaddr );
    instr.SetUpdate( ctr,   ctr   );
    // but not for state
  }

  /// add child
  
}
