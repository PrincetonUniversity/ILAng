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

  inline z3::context& ctx() const { return ctx_; }

  z3::expr InstrSeq(const std::vector<InstrPtr>& seq, const int& pos = 0);

private:
  z3::context& ctx_;

  Z3ExprAdapter gen_;

  z3::expr InstrUpdDflt(const InstrLvlAbsPtr ila, const std::string& prev,
                        const std::string& next);

  z3::expr InstrUpdCmpl(const InstrPtr instr, const std::string& prev,
                        const std::string& next);
#if 0
  z3::expr InstrUpdBare(const InstrPtr instr, const std::string& prev,
                        const std::string& next);
#endif

  z3::expr StateUpdCmpl(const InstrPtr instr, const ExprPtr var,
                        const std::string& prev);

  std::set<ExprPtr> GetAllVar(const std::vector<InstrPtr>& seq) const;

}; // class Unroller

} // namespace ila

#endif // UNROLLER_H__

