/// \file the ila example of AES block encryption
///  Hongce Zhang (hongcez@princeton.edu)
///

#ifndef AES_ILA_H__
#define AES_ILA_H__

#include <ilang/ilang++.h>

using namespace ilang;

#define AES_START 0xff00
#define AES_STATE 0xff01
#define AES_ADDR 0xff02
#define AES_LENGTH 0xff04
#define AES_KEY 0xff10
#define AES_CNT 0xff20

#define CMD_NOP 0
#define CMD_READ 1
#define CMD_WRITE 2

#define AES_STATE_IDLE 0
#define AES_STATE_READ_DATA 1
#define AES_STATE_OPERATE 2
#define AES_STATE_WRITE_DATA 3

/// \brief the class of AES ila
class AES {

public:
  // --------------- CONSTRUCTOR ------ //
  /// add state, add instructions, add child
  AES();
  // --------------- MEMBERS ----------- //
  /// the ila mode
  Ila model;

private:
  /// Called by the constructor to create the child-ILA
  /// for block encryption
  void AddChild(InstrRef& inst);

protected:
  // --------------- HELPERS -------- //
  /// To get a slide from the expression: reg
  /// \param[in] reg: the register to slice
  /// \param[in] idx: the address/index to select the slice
  /// \param[in] base_addr: the address to be substracted from address
  /// \param[in] no_slice: the number of slices
  /// \param[in] slice_width: the width of slice
  /// \return  the resulted read expression
  static ExprRef slice_read(const ExprRef& reg, const ExprRef& idx,
                            unsigned long base_addr, unsigned no_slice,
                            unsigned slice_width);

  /// update only part (slices) of a register
  /// \param[in] reg: the register to slice
  /// \param[in] idx: the address/index to select the slice
  /// \param[in] input_slice: the slice used to update
  /// \param[in] base_addr: the address to be substracted from address
  /// \param[in] no_slice: the number of slices
  /// \param[in] slice_width: the width of slice
  /// \return  the resulted read expression
  /// it assumes:
  /// input_slice.width == slice_width
  /// no_slice * slice_width == reg.width
  static ExprRef slice_update(const ExprRef& reg, const ExprRef& idx,
                              const ExprRef& input_slice,
                              unsigned long base_addr, unsigned no_slice,
                              unsigned slice_width);

  /// specify a nondeterministic value within range [low,high]
  ExprRef unknown_range(unsigned low, unsigned high);
  /// a nondeterministic choice of a or b
  static ExprRef unknown_choice(const ExprRef& a, const ExprRef& b);
  /// a nondeterminstic bitvector const of width
  static FuncRef unknown(unsigned width);

protected:
  // ------------ STATE ------------ //
  // I/O interface: this is where the commands come from.
  ExprRef cmd;
  ExprRef cmdaddr;
  ExprRef cmddata;
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

#endif // AES_ILA_H__
