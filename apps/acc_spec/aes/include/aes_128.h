/// \file AES 128 function ILA definition

#ifndef AES_128_H__
#define AES_128_H__

#include <ilang/ilang++.h>
#include <vector>

using namespace ilang;

class AES_128 {
  typedef std::vector<ExprRef> vec4;

public:
  // Constructor : build the model
  AES_128();
  // then you are free to use this model
  Ila model;

private:
  // -------------- HELPER Functions ---------------- //
  /// round -> round constant
  static ExprRef rcon(const ExprRef& rnd);
  /// read from s table
  static ExprRef s_table_read(const ExprRef& idx);
  /// read from xs table
  static ExprRef xs_table_read(const ExprRef& idx);
  /// Concat(l[4])
  static ExprRef combine_vec4(const vec4& l);
  /// slice 128 bv to vec4 of 32b
  static vec4 slice_128_to_32(const ExprRef& bv);
  /// slice 32 bv to vec4 of 8b
  static vec4 slice_32_to_8(const ExprRef& _32);
  /// A shortcut of s_table_read
  static ExprRef S(const ExprRef& inp);
  /// A shortcut of xs_table_read
  static ExprRef xS(const ExprRef& inp);
  /// S4 box
  static ExprRef S4(const ExprRef& inp);
  ///
  static vec4 T(const ExprRef& inp);
  /// round key for ciphertext
  static ExprRef expand_key_128_a(const ExprRef& in, const ExprRef& rc);
  /// round key for next round
  static ExprRef expand_key_128_b(const ExprRef& in, const ExprRef& rc);
  /// table lookup
  static vec4 table_lookup(const ExprRef& s32);
  /// Get ciphertext update for intermediate round
  static ExprRef GetCipherUpdate_MidRound(const ExprRef& state_in,
                                          const ExprRef rnd,
                                          const ExprRef& key);
  /// Get ciphertext update for the final round
  static ExprRef GetCipherUpdate_FinalRound(const ExprRef& state_in,
                                            const ExprRef rnd,
                                            const ExprRef& key);
  /// Gte the intermidiate round key update
  static ExprRef GetKeyUpdate_MidRound(const ExprRef& key, const ExprRef rnd);

}; // class AES_128

#endif // AES_128_H__
