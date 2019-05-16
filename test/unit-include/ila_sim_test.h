#ifndef ILA_SIM_TEST_H__
#define ILA_SIM_TEST_H__

#include <ilang/ilang++.h>

using namespace ilang;

#define START 0xff00
#define ADDR 0xff02

#define CMD_NOP 0
#define CMD_READ 1
#define CMD_WRITE 2

#define STATE_IDLE 0
#define STATE_READ_DATA 1
#define STATE_OPERATE 2
#define STATE_WRITE_DATA 3

class IlaSimTest {

public:
  IlaSimTest();
  Ila model;

protected:
  static ExprRef slice_read(const ExprRef& reg, const ExprRef& idx,
                            unsigned long base_addr, unsigned no_slice,
                            unsigned slice_width);

  static ExprRef slice_update(const ExprRef& reg, const ExprRef& idx,
                              const ExprRef& input_slice,
                              unsigned long base_addr, unsigned no_slice,
                              unsigned slice_width);

  ExprRef unknown_range(unsigned low, unsigned high);
  /// a nondeterministic choice of a or b
  static ExprRef unknown_choice(const ExprRef& a, const ExprRef& b);
  /// a nondeterminstic bitvector const of width
  FuncRef unknown(unsigned width);

protected:
  ExprRef cmd;
  ExprRef cmdaddr;
  ExprRef cmddata;
  ExprRef status;
  ExprRef address;
  ExprRef length;
  ExprRef counter;
  ExprRef xram;
  FuncRef process128;

  int nondet_counter;

}; // class IlaSimTest

#endif // SIMGEN_TEST_H__
