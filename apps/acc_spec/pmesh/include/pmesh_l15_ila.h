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


#endif // PMESH_L15_ILA_H__


