/// \file
/// Header for unrolling ILA execution.

#ifndef UNROLLER_H__
#define UNROLLER_H__

#include "ila/instr_lvl_abs.h"
#include "ila/z3_expr_adapter.h"
#include "z3++.h"

namespace ila {

/// \brief Class for unrolling ILA execution in different settings.
class Unroller {
public:
  Unroller(z3::context& ctx);
  virtual ~Unroller();

#if 0
  virtual z3::expr OneStepInstrNoDecode(const InstrPtr instr) const = 0;
  virtual z3::expr OneStepMonoIla() const = 0;
#endif

  inline z3::context& ctx() const { return ctx_; }

private:
  z3::context& ctx_;

  Z3ExprAdapter gen_;

  z3::expr InstrUpdCmpl(const InstrPtr instr, const std::string& prev,
                        const std::string& next);
#if 0
  z3::expr InstrUpdBare(const InstrPtr instr, const std::string& prev,
                        const std::string& next);
#endif

}; // class Unroller

} // namespace ila

#endif // UNROLLER_H__

