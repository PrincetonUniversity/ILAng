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
// the memory
xram    ( mdoel.NewMemState('XRAM', 16, 8)  ),
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
  
  set_state_update();
}

void AES::set_state_update() {
  
}