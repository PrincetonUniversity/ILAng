/// \file the ila example of AES block encryption
///  Hongce Zhang (hongcez@princeton.edu)
///

#ifndef PMESH_L15_ILA_H__
#define PMESH_L15_ILA_H__

#include <ilang/ilang++.h>
#include <vector>

#define MESI_INVALID 0

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
  /// a helper function to concat a vector of express
  static ExprRef lConcat(const std::vector<ExprRef> & l);


protected:
  // ------------ STATE ------------ //
  // I/O interface: this is where the commands come from.
  ExprRef address;
  ExprRef data   ;
  ExprRef nc     ;
  ExprRef rqtype ;
  ExprRef size   ;
  ExprRef val    ;

  // arch state.
  ExprRef l15_noc1buffer_req_address;
  ExprRef l15_noc1buffer_req_noncacheable;
  ExprRef l15_noc1buffer_req_size        ;
  ExprRef l15_noc1buffer_req_type        ;

  // output state l15->core
  ExprRef l15_transducer_val       ;
  ExprRef l15_transducer_returntype;
  ExprRef l15_transducer_data_0    ;

  // internal state : map (mem)
  ExprRef mesi_state;
  ExprRef data_state;

}; // class AES


#endif // PMESH_L15_ILA_H__


