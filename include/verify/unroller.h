/// \file
/// Header for unrolling ILA execution.

#ifndef UNROLLER_H__
#define UNROLLER_H__

#include "ila/instr_lvl_abs.h"
#include "ila/z3_expr_adapter.h"
#include "z3++.h"
#include <set>
#include <vector>

namespace ila {

/// \brief Class for unrolling ILA execution in different settings.
class Unroller {
public:
  typedef z3::expr ZExpr;
  typedef std::vector<ZExpr> ZExprVec;
  typedef std::set<ExprPtr> IExprSet;
  typedef ExprPtrVec IExprVec;
  typedef std::vector<InstrPtr> InstrVec;

  Unroller(z3::context& ctx);
  virtual ~Unroller();

  inline z3::context& ctx() const { return ctx_; }

  void AddGlobPred(const ExprPtr p);
  void AddInitPred(const ExprPtr p);
  void BootStrap();

  //
  ZExpr InstrSeq(const std::vector<InstrPtr>& seq, const int& pos = 0);

  ZExpr InstrSeqAssn(const std::vector<InstrPtr>& seq, const int& pos = 0);

  ZExpr InstrSeqSubs(const std::vector<InstrPtr>& seq, const int& pos = 0);

  ZExpr IlaBulkAssn(const InstrLvlAbsPtr top, const int& length,
                    const int& pos = 0);

  ZExpr IlaBulkSubs(const InstrLvlAbsPtr top, const int& length,
                    const int& pos = 0);

private:
  z3::context& ctx_;

protected:
  Z3ExprAdapter gen_;

  IExprSet g_pred_;
  IExprSet i_pred_;
  IExprSet ivar_;
  ZExprVec zvar_prev_;
  ZExprVec zvar_next_;
  ZExprVec cstr_;

  virtual void CollectVar() = 0;
  // virtual void CollectVar(const std::vector<InstrPtr>& seq);

  z3::expr InstrUpdDflt(const InstrLvlAbsPtr ila, const std::string& prev,
                        const std::string& next);

  z3::expr InstrUpdCmpl(const InstrPtr instr, const std::string& prev,
                        const std::string& next);

  z3::expr StateUpdCmpl(const InstrPtr instr, const ExprPtr var,
                        const std::string& prev);

  std::set<ExprPtr> GetAllVar(const std::vector<InstrPtr>& seq) const;

}; // class Unroller

class ListUnroll : public Unroller {
public:
  ListUnroll(z3::context& ctx, const InstrVec& seq);
  ~ListUnroll();

private:
  InstrVec seq_;

  void CollectVar();
};

class BulkUnroll : public Unroller {
public:
  BulkUnroll(z3::context& ctx, const InstrLvlAbsPtr top);
  ~BulkUnroll();

private:
  InstrLvlAbsPtr top_;

  void CollectVar();

  void VisitHierCollectVar(const InstrLvlAbsPtr m);
};

} // namespace ila

#endif // UNROLLER_H__

