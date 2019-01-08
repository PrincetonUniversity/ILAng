/// \file the ila example of AES block encryption
///  Hongce Zhang (hongcez@princeton.edu)
///

#ifndef PMESH_L15_ILA_H__
#define PMESH_L15_ILA_H__

#include <ilang/ilang++.h>

using namespace ilang;

/// \brief the class of PMESH L1.5 ila
class PMESH_L15 {

public:
  // --------------- CONSTRUCTOR ------ //
  /// add state, add instructions, add child
  PMESH_L15();
  // --------------- MEMBERS ----------- //
  /// the ila mode
  Ila model;

private:
  /// Called by the constructor to create the child-ILA
  /// for block encryption
  void AddChild(InstrRef& inst);

protected:
  // --------------- HELPERS -------- //
  /// specify a nondeterministic value within range [low,high]
  ExprRef unknown_range(unsigned low, unsigned high);
  /// a nondeterministic choice of a or b
  static ExprRef unknown_choice(const ExprRef& a, const ExprRef& b);
  /// a nondeterminstic bitvector const of width
  static FuncRef unknown(unsigned width);

protected:
  // ------------ STATE ------------ //
  // I/O interface: this is where the commands come from.
  ExprRef address;
  ExprRef data   ;
  ExprRef nc     ;
  ExprRef rqtype ;
  ExprRef size   ;
  ExprRef val    ;

  // internal arch state.
  ExprRef status;
  ExprRef address;
  ExprRef length;
  ExprRef counter;
  ExprRef key;
  // the memory
  ExprRef xram;
  // The encryption function :
  // 128b plaintext x 128b key -> 128b ciphertext
  // FuncRef(name, range, domain1, domain2 )
  FuncRef aes128;
  // the output
  ExprRef outdata;

}; // class AES


#endif // PMESH_L15_ILA_H__


