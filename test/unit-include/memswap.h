/// \file
/// Example model -- memory swap

#ifndef MEM_SWAP_H__
#define MEM_SWAP_H__

namespace ilang {

class InstrLvlAbs;
class Ila;

class MemorySwap {

public:
  static Ila BuildModel();
  static Ila BuildSimpleSwapModel();
  static Ila BuildRfAsMemModel();
  static Ila BuildRfAsMemModelRegEntry6();
  static Ila BuildRdModel();
  static Ila BuildResetterTest();
  static Ila BuildSimpleLargeArray();

}; // class MemorySwap

}; // namespace ilang

#endif // MEM_SWAP_H__
