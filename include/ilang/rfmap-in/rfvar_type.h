/// \file Verilog Verification Refinement Map Interface Class
/// Variable Types
/// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_RFMAP_VARTYPE_H__
#define ILANG_RFMAP_VARTYPE_H__

#include <string>

namespace ilang {
namespace rfmap {

// define type
struct RfMapVarType {
  enum class TYPE { BV, MEM, UNKNOWN } type;
  unsigned width;
  unsigned addr_width;
  unsigned data_width;

  bool is_unknown() const { return type == TYPE::UNKNOWN; }
  bool is_bv() const { return type == TYPE::BV; }
  bool is_array() const { return type == TYPE::MEM; }

  /// for unknown type
  RfMapVarType() : type(TYPE::UNKNOWN) {}
  /// for bit-vector type
  RfMapVarType(unsigned w) : type(TYPE::BV), width(w) {}
  /// for array type
  RfMapVarType(unsigned a, unsigned d)
      : type(TYPE::MEM), addr_width(a), data_width(d) {}
  unsigned unified_width() const {
    return type == RfMapVarType::TYPE::BV ? width : data_width;
  }

  std::string to_string() const {
    if (is_unknown())
      return "(unknown)";
    if (is_bv())
      return "(_ BitVec " + std::to_string(width) + ")";
    return "(Array (_ BitVec " + std::to_string(addr_width) + ") (_ BitVec " +
           std::to_string(data_width) + "))";
  }
};

class RfVarTypeOrig {
public:
  enum class VARTYPE {
    NOTVAR,     /*also unknown type*/
    ILAS,       /*state var*/
    ILAI,       /*ila input*/
    RTLV,       /*rtl signal*/
    DEFINE_VAR, /*defined vars*/
    INTERNAL    /* those already translated:
       like  __CYCLE_CNT__, __START__*/
  };

  VARTYPE var_ref_type;
  RfMapVarType type;

  // constructur
  RfVarTypeOrig() : var_ref_type(VARTYPE::NOTVAR) {}
  RfVarTypeOrig(const RfVarTypeOrig& r)
      : var_ref_type(r.var_ref_type), type(r.type) {}

  RfVarTypeOrig& operator=(const RfVarTypeOrig&) = default;

}; // class RfVarType

} // namespace rfmap
} // namespace ilang

#endif // ILANG_RFMAP_VARTYPE_H__
