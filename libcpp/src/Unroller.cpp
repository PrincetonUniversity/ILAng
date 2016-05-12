#include "Unroller.hpp"
#include "smt.hpp"
#include "abstraction.hpp"

#include <sstream>

using namespace std;

namespace ila
{
  void Unroller::addTr0 ()
  {
      unsigned nFrame = frame ();

      assert (getInputs (nFrame).size() == 0 &&
                  "Unexpected inputs");
      assert (getOutputs (nFrame).size() == 0 &&
                  "Unexpected outputs");
      assert (nFrame == 0);

      Z3ExprAdapter z3expr(*m_pContext, "");
      z3expr.setNameSuffix(string("_0_"));
      // add Init


      // -- register frame PIs
      for (auto i : m_pAbstraction->getInps()) {
          z3::expr pi = z3expr.getExpr(i.second.var.get());
          m_vPrimaryInputs[nFrame].push_back(pi);
      }

      // -- register current state as the output
      for (auto b : m_pAbstraction->getBits()) {
          z3::expr c = z3expr.getExpr(b.second.var.get());
          m_vInputs [nFrame].push_back(c);
      }

      for (auto r : m_pAbstraction->getRegs()) {
          z3::expr c = z3expr.getExpr(r.second.var.get());
          m_vInputs [nFrame].push_back(c);
      }

      for (auto m : m_pAbstraction->getMems()) {
          z3::expr c = z3expr.getExpr(m.second.var.get());
          m_vInputs [nFrame].push_back(c);
      }
  }

  void Unroller::addTrN()
  {
      unsigned nFrame = frame ();

      assert (getInputs (nFrame).size() == 0 &&
              "Unexpected inputs");
      assert (getOutputs (nFrame).size() == 0 &&
              "Unexpected outputs");
      assert (nFrame > 0);

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
