#include "Unroller.hpp"
#include "smt.hpp"
#include "abstraction.hpp"
#include "ast.hpp"
#include "rewriter.hpp"
#include <sstream>

using namespace std;

namespace ila
{

  // FIXME: this whole file needs to also call getCnst.

  void Unroller::_initVar(Z3ExprAdapter& z3expr, const npair_t& p, int& cnt)
  {
      unsigned nFrame = frame ();

      Node* var = p.var.get();
      Node* init = p.init.get();

      if (!var->equal(init) && setInit) {
          z3::expr c = z3expr.getExpr(init).simplify();
          m_vOutputs [nFrame].push_back(c);
      } else {
          z3::expr c = z3expr.getExpr(var).simplify();
          m_vOutputs [nFrame].push_back(c);
      }
      if ((bool) p.ipred) {
          z3::expr p1 = z3expr.getExpr(p.ipred.get()).simplify();
          m_pSolver->add(p1);
      }
      m_mStateIndices[p.var.get()] = cnt++;
  }

  void Unroller::addTr0 ()
  {
      unsigned nFrame = frame ();

      ILA_ASSERT (getOutputs (nFrame).size() == 0,
                  "Unexpected outputs");
      ILA_ASSERT (nFrame == 0, 
                  "Unexpected frame number.");

      Z3ExprAdapter z3expr(*m_pContext, "");
      z3expr.setNameSuffix("_" + m_sName);
      z3expr.simplify = true;
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
  bool Unroller::checkAbsNextExpNotNull()
  {
      for (auto b : m_pAbstraction->getBits()) {
          if(!b.second.next.get())
            throw PyILAException(
                PyExc_RuntimeError,
                b.first + " does not set next expression.");
      }

      for (auto r : m_pAbstraction->getRegs()) {
          if(!r.second.next.get())
            throw PyILAException(
                PyExc_RuntimeError,
                r.first + " does not set next expression.");
      }

      for (auto m : m_pAbstraction->getMems()) {
          if(!m.second.next.get())
            throw PyILAException(
                PyExc_RuntimeError,
                m.first + " does not set next expression.");        
      }
      return true;
  }

  void Unroller::addTrN()
  {
      unsigned nFrame = frame ();

      ILA_ASSERT (getOutputs (nFrame).size() == 0,
                    "Unexpected outputs");
      ILA_ASSERT (nFrame > 0, "Invalid frame number");

      Z3ExprAdapter z3expr(*m_pContext, "");
      z3expr.setNameSuffix("_" + boost::lexical_cast<string>(nFrame) +
                               + "_" + m_sName);

      for (auto i : m_pAbstraction->getInps()) {
          z3::expr pi = z3expr.getExpr(i.second.var.get());
          m_vPrimaryInputs[nFrame].push_back(pi);
      }

      z3::expr_vector sub_src(*m_pContext);
      z3::expr_vector sub_dst(*m_pContext);
      int i=0;
      for (auto b : m_pAbstraction->getBits()) {
          sub_src.push_back(z3expr.getExpr(b.second.var.get()));
          sub_dst.push_back(m_vOutputs[nFrame-1][i++]);
      }

      for (auto r : m_pAbstraction->getRegs()) {
          sub_src.push_back(z3expr.getExpr(r.second.var.get()));
          sub_dst.push_back(m_vOutputs[nFrame-1][i++]);
      }

      for (auto m : m_pAbstraction->getMems()) {
          sub_src.push_back(z3expr.getExpr(m.second.var.get()));
          sub_dst.push_back(m_vOutputs[nFrame-1][i++]);
      }

      for (auto b : m_pAbstraction->getBits()) {
          z3::expr e = z3expr.getExpr(b.second.next.get());
          m_vOutputs[nFrame].push_back(e.substitute(sub_src, sub_dst));
      }

      for (auto r : m_pAbstraction->getRegs()) {
          z3::expr e = z3expr.getExpr(r.second.next.get());
          m_vOutputs[nFrame].push_back(e.substitute(sub_src, sub_dst));
      }

      for (auto m : m_pAbstraction->getMems()) {
          z3::expr e = z3expr.getExpr(m.second.next.get());
          m_vOutputs[nFrame].push_back(e.substitute(sub_src, sub_dst));
      }
  }

  
    z3::expr Unroller::subsFormula(Node * n)
    {
        Z3ExprAdapter z3expr(*m_pContext, "");
        unsigned nFrame = frame();
        z3expr.setNameSuffix("_" + boost::lexical_cast<string>(nFrame+1) +
                               + "_" + m_sName);

        z3::expr_vector sub_src(*m_pContext);
        z3::expr_vector sub_dst(*m_pContext);

        unsigned i=0;
        for (auto b : m_pAbstraction->getBits() )  {
            sub_src.push_back(z3expr.getExpr(b.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame][i++]);
        }
        for (auto r : m_pAbstraction->getRegs() )  {
            sub_src.push_back(z3expr.getExpr(r.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame][i++]);
        }
        for (auto m : m_pAbstraction->getMems() )  {
            sub_src.push_back(z3expr.getExpr(m.second.var.get()));
            sub_dst.push_back(m_vOutputs[nFrame][i++]);
        }
        // now we have all of that
        // let's dump it
        //if(debug)  {
        //    ILA_ASSERT(sub_src.size()==sub_dst.size(),"unbalanced size");
        //    log2("Unroller")<<"(DEBUG) will replace:"<<std::endl;
        //    for (unsigned i=0;i<sub_src.size();i++)
        //            log2("Unroller")<<sub_src[i] <<" -> " <<sub_dst[i] <<std::endl;
        //}

        z3::expr assumptExpr = z3expr.getExpr( n );
        log2("Unroller")<<"Assumption before sub: "<<assumptExpr<<std::endl;
        z3::expr assumptExprSub = assumptExpr.substitute(sub_src,sub_dst);
        log2("Unroller")<<"Assumption after sub: "<<assumptExprSub<<std::endl;
        return assumptExprSub;
    }
    
    void Unroller::EvalEachFrame(z3::model &m, Unroller *u , std::ostream & cexf)
    {

        cexf << "Abstraction:"<<u->m_pAbstraction->getName()<<std::endl;
        cexf << "Model:"<<std::endl;
        cexf << m;
        cexf << "\nFrames Eval:" << std::endl;
        unsigned nFrame = u->frame();
        for(unsigned idx = 1; idx < nFrame; idx ++ ) {
            cexf << "<Frame "<<idx<< ">"<<std::endl;
            for(auto &ni: u->m_mStateIndices) {
                cexf << ni.first->getName() << ": ";
                z3::expr eval_result = m.eval( u->m_vOutputs[idx][ ni.second ] ).simplify();
                const MemVar* memvar;
                Z3ExprAdapter z3expr(*(u->m_pContext), "");
                if ((memvar = dynamic_cast<const MemVar*>(ni.first)))
                    cexf<<MemValues(z3expr,m,memvar)<<std::endl;
                else
                    cexf << eval_result <<std::endl;
            }
        }
    }
}
