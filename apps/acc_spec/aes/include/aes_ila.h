/// \file the ila example of AES block encryption

#ifndef AES_ILA_H__
#define AES_ILA_H__

#include <ilang/cpp_api.h>

using namespace ilang;

/// \brief the class of AES ila
class AES {
  
constexpr AES_START = 0xff00;
constexpr AES_STATE = 0xff01;
constexpr AES_ADDR  = 0xff02;
constexpr AES_LEN   = 0xff04;
constexpr AES_KEY   = 0xff10;
constexpr AES_CNT   = 0xff20;

protected:
  // --------------- MEMBERS ----------- //
  /// the ila mode
  Ila model;
public:
  // --------------- CONSTRUCTOR ------ //
  /// add state, add instructions, add child
  AES();

protected:
  // --------------- HELPERS -------- //
  void set_state_update();

protected:
  // ------------ STATE ------------ //
  // I/O interface: this is where the commands come from.
  ExprRef cmd     ;
  ExprRef cmdaddr ;
  ExprRef cmddata ;
  // internal arch state.
  ExprRef state   ;
  ExprRef opaddr  ;
  ExprRef oplen   ;
  ExprRef ctr     ;
  ExprRef key     ;
  // the memory
  ExprRef xram    ;
  // The encryption function : 
  // 128b plaintext x 128b key -> 128b ciphertext
  // FuncRef(name, range, domain1, domain2 )
  ExprRef aes128  ; 
  // the output
  ExprRef outdata ;

}; // class AES

#endif // AES_ILA_H__
