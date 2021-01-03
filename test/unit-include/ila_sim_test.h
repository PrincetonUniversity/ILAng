// A helper model containing all aspects of an ILA model, including
// all sorts of states, all sorts of operations, and sharead/external memory.
// This helper model will provide a complete test of ila_sim class.
// Note: this model is not built for verification or other usage.

#ifndef TEST_ILA_SIM_TEST_H__
#define TEST_ILA_SIM_TEST_H__

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
  IlaSimTest(const std::string& name = "TEST");
  Ila model;

protected:
  static ExprRef slice_read(const ExprRef& reg, const ExprRef& idx,
                            unsigned long base_addr, unsigned no_slice,
                            unsigned slice_width);

  static ExprRef slice_update(const ExprRef& reg, const ExprRef& idx,
                              const ExprRef& input_slice,
                              unsigned long base_addr, unsigned no_slice,
                              unsigned slice_width);

  FuncRef unknown(unsigned width);

protected:
  ExprRef cmd;
  ExprRef cmdaddr;
  ExprRef cmddata;
  ExprRef cmdflag;
  ExprRef status;
  ExprRef address;
  ExprRef length;
  ExprRef counter;
  ExprRef xram;
  ExprRef flag;
  ExprRef big_ram;
  FuncRef process128;

  int nondet_counter;

}; // class IlaSimTest

#endif // TEST_ILA_SIM_TEST_H__
