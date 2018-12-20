/// \file The child ila of block encryption
///  Hongce Zhang (hongcez@princeton.edu)

#include "aes_ila.h"

void AES::AddChild( InstrRef & inst) {
  auto child = model.NewChild("AES_BLOCK");

  child.SetValid( state != 0 );
  child.SetFetch( state );

  auto rd_data       = child.NewBvState( "rd_data" ,      128 );
  auto enc_data      = child.NewBvState( "enc_data",      128 );
  auto byte_cnt      = child.NewBvState( "byte_cnt",      4   );
  auto blk_cnt       = child.NewBvState( "blk_cnt",       16  );

  // init conditions : when doing verification
  // should be exported as the state update of the higher-level 
  // triggering instruction
  child.AddInit( byte_cnt      == 0 );
  child.AddInit( blk_cnt       == 0 );
  // child.AddInit( oped_byte_cnt == 0 );

  { // LOAD byte-by-byte
    auto instr = child.NewInstr("LOAD");

    instr.SetDecode( state ==  AES_STATE_READ_DATA );

    instr.SetUpdate( byte_cnt, byte_cnt + 1 );
    instr.SetUpdate( blk_cnt,  blk_cnt );

    auto xram_read_addr = opaddr + blk_cnt + ZExt( byte_cnt, 16 );

    instr.SetUpdate( rd_data,  
      slice_update(rd_data, byte_cnt, 
        Load(xram, xram_read_addr), 0, 16 , 8  ) );

    instr.SetUpdate( state, Ite(byte_cnt == 15, BvConst(AES_STATE_OPERATE,2) , state ) );
  }

  { // encrypt -- aes 128 function describe separately
    auto instr = child.NewInstr("OPERATE");

    instr.SetDecode( state ==  AES_STATE_OPERATE );

    // counter mode : ciphertext = E(ctr) ^ plaintext
    auto enc_ctr = ctr + blk_cnt;

    instr.SetUpdate( enc_data, aes128( enc_ctr , key ) ^ rd_data );

    instr.SetUpdate( blk_cnt,  blk_cnt );

    instr.SetUpdate( state, BvConst(AES_STATE_WRITE_DATA,2) ) ;

  }

  { // store byte-by-byte
    auto instr = child.NewInstr("STORE");

    instr.SetDecode( state == AES_STATE_WRITE_DATA );

    auto xram_write_addr = opaddr + blk_cnt + ZExt( byte_cnt, 16 );

    instr.SetUpdate( byte_cnt, byte_cnt + 1 );

    instr.SetUpdate( xram, slice_read(enc_data, byte_cnt, 0, 16, 8) );

    instr.SetUpdate( blk_cnt, 
      Ite( byte_cnt == 15, 
        Ite( blk_cnt + 16 < oplen, blk_cnt + 16, blk_cnt), blk_cnt ) );

    instr.SetUpdate( state, 
      Ite( byte_cnt == 15, // the last byte has been written to
        Ite( blk_cnt + 16 < oplen,              // if we reach the length
          BvConst(AES_STATE_IDLE, 2),            // 
          BvConst(AES_STATE_READ_DATA, 2) ) , 
        state  ) ) ;
  }


  inst.SetProgram(child);

}
