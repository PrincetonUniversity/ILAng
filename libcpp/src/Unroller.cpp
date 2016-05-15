#include "Unroller.hpp"
#include "smt.hpp"
#include "abstraction.hpp"
#include "ast.hpp"

#include <sstream>

using namespace std;

namespace ila
{

  void Unroller::_initVar(Z3ExprAdapter& z3expr, const npair_t& p, int& cnt)
  {
      unsigned nFrame = frame ();

      Node* var = p.var.get();
      Node* init = p.init.get();

      if (!var->equal(init)) {
          z3::expr c = z3expr.getExpr(init);
          m_vOutputs [nFrame].push_back(c);
      } else {
          z3::expr c = z3expr.getExpr(var);
          m_vOutputs [nFrame].push_back(c);
      }
      m_mStateIndices[p.var.get()] = cnt++;
  }

  void Unroller::addTr0 ()
  {
      unsigned nFrame = frame ();

      ILA_ASSERT (getInputs (nFrame).size() == 0, 
                  "Unexpected inputs");
      ILA_ASSERT (getOutputs (nFrame).size() == 0,
                  "Unexpected outputs");
      ILA_ASSERT (nFrame == 0, 
                  "Unexpected frame number.");

      Z3ExprAdapter z3expr(*m_pContext, "");
      z3expr.setNameSuffix(string("_0_"));
      // add Init


      // -- register frame PIs
      int cnt=0;
      for (auto i : m_pAbstraction->getInps()) {
          z3::expr pi = z3expr.getExpr(i.second.var.get());
          m_vPrimaryInputs[nFrame].push_back(pi);
          m_mInputIndices[i.second.var.get()] = cnt++;
      }

      // -- register current state as the output
      cnt=0;
      for (auto b : m_pAbstraction->getBits()) {
          _initVar(z3expr, b.second, cnt);
      }

      for (auto r : m_pAbstraction->getRegs()) {
          _initVar(z3expr, r.second, cnt);
      }

      for (auto m : m_pAbstraction->getMems()) {
          _initVar(z3expr, m.second, cnt);
      }
  }

  void Unroller::addTrN()
  {
      unsigned nFrame = frame ();

      ILA_ASSERT (getInputs (nFrame).size() == 0,
                  "Unexpected inputs");
      ILA_ASSERT (getOutputs (nFrame).size() == 0,
                  "Unexpected outputs");
      ILA_ASSERT (nFrame > 0, "Invalid frame number");

      Z3ExprAdapter z3expr(*m_pContext, "");
      ostringstream s;
      s << "_" << nFrame << "_";
      z3expr.setNameSuffix(s.str());

      for (auto i : m_pAbstraction->getInps()) {
          z3::expr pi = z3expr.getExpr(i.second.var.get());
          m_vPrimaryInputs[nFrame].push_back(pi);
      }

      for (auto b : m_pAbstraction->getBits()) {
          z3::expr n = z3expr.getExpr(b.second.next.get());
          z3::expr c = z3expr.getExpr(b.second.var.get());

          m_vInputs [nFrame].push_back(c);
          m_vOutputs[nFrame].push_back(n);
      }

      for (auto r : m_pAbstraction->getRegs()) {
          z3::expr n = z3expr.getExpr(r.second.next.get());
          z3::expr c = z3expr.getExpr(r.second.var.get());

          m_vInputs [nFrame].push_back(c);
          m_vOutputs[nFrame].push_back(n);
      }

      for (auto m : m_pAbstraction->getMems()) {
          z3::expr n = z3expr.getExpr(m.second.next.get());
          z3::expr c = z3expr.getExpr(m.second.var.get());

          m_vInputs [nFrame].push_back(c);
          m_vOutputs[nFrame].push_back(n);
      }

      /// glue new In to old Out
      glueOutIn ();
  }
}
