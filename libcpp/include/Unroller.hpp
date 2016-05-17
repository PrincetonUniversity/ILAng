#ifndef _UNROLLER_H_
#define _UNROLLER_H_

#include <cassert>

#include <unordered_map>
#include <vector>

#include "boost/foreach.hpp"
#include "boost/dynamic_bitset.hpp"
#include "boost/logic/tribool.hpp"
#include <z3++.h>
#include <util.hpp>

#include <ast.hpp>

namespace ila
{
  class Abstraction;

  class Unroller
  {
    const char* m_sName;

    Abstraction* m_pAbstraction;
    z3::context* m_pContext;
    z3::solver* m_pSolver;
    unsigned m_nFrames;

    /// Map between primary input pointers and indices into m_vPrimaryInputs
    std::unordered_map<Node*, int> m_mInputIndices;
    /// Primary Inputs, by frame
    std::vector<std::vector<z3::expr> > m_vPrimaryInputs;

    /// Map between state pointers and indices into m_vInputs and m_vOutputs
    std::unordered_map<Node*, int> m_mStateIndices;
    /// Inputs, by frame
    std::vector<std::vector<z3::expr> > m_vInputs;
    /// Outputs, by frame
    std::vector<std::vector<z3::expr> > m_vOutputs;

    /// All assumptions
    std::vector<z3::expr> m_Assumps;
    
    /// Expr for assertion to be checked
    z3::expr *m_pAssertion;

    /// Outputs, by frame
    std::vector<std::vector<Node*> > m_vExprOutputs;
  
  
  public:
    Unroller(const char* suffix, Abstraction& abs, z3::context &c, z3::solver &s)
      : m_sName(suffix)
      , m_pAbstraction(&abs)
      , m_pContext(&c)
      , m_pSolver (&s)
      , m_nFrames(0)
      , m_pAssertion(NULL)
    { newFrame (); }

    ~Unroller () { reset (NULL); }


    void setAssertion (z3::expr& a) { m_pAssertion = &a; }
    z3::expr& getAssertion ()
    {
      return *m_pAssertion;
    }
    
    void pushAssertion ()
    {
      z3::expr& a = getAssertion();
      m_pSolver->add(a);
    }
    

    /** Reset everything */
    void reset (z3::solver *solver)
    {
      m_vPrimaryInputs.clear ();
      m_vInputs.clear ();
      m_vOutputs.clear ();
      m_vExprOutputs.clear(); //TODO: Memory leak

      m_Assumps.clear ();

      m_nFrames = 0;
      
      if (solver)
        {
          m_pSolver = solver;
          newFrame ();
        }
    }

    /// register literal as an assumption
    void addAssump (z3::expr& a) { m_Assumps.push_back (a); }
  
    /// return all assumptions
    std::vector<z3::expr> &getAssumps () { return m_Assumps; }
  
    void _initVar(Z3ExprAdapter& z3expr, const npair_t& p, int& cnt);
  
    unsigned frame () { return m_nFrames - 1; }
    
    void newFrame ()
    {
      m_nFrames++;
      m_vPrimaryInputs.resize(m_nFrames);
      m_vInputs.resize(m_nFrames);
      m_vOutputs.resize(m_nFrames);
      m_vExprOutputs.resize(m_nFrames);
    }
    
    unsigned frames () { return m_nFrames; }
    
    
    void addPrimaryInput (z3::expr in)
    { m_vPrimaryInputs.at (frame ()).push_back(in); }

    z3::expr& getPrimaryInput (unsigned nFrame, int nNum)
    { return m_vPrimaryInputs.at (nFrame)[nNum]; }

    std::vector<z3::expr>& getPrimaryInputs (unsigned nFrame) { return m_vPrimaryInputs.at (nFrame); }

    void addInput (z3::expr in)
    { m_vInputs.at (frame ()).push_back(in); }

    z3::expr& getInput (unsigned nFrame, int nNum)
    { return m_vInputs.at (nFrame)[nNum]; }
  
    std::vector<z3::expr>& getInputs (unsigned nFrame) { return m_vInputs.at (nFrame); }

    void addOutput (z3::expr out)
    { m_vOutputs.at (frame ()).push_back(out); }

    z3::expr& getOutput (unsigned nFrame, Node* var) {
        auto pos = m_mStateIndices.find(var);
        ILA_ASSERT (pos != m_mStateIndices.end(), "Unable to find var in map.");
        return getOutput(nFrame, pos->second);
    }

    z3::expr& getOutput (unsigned nFrame, int nNum)
    { return m_vOutputs.at (nFrame)[nNum]; }

    std::vector<z3::expr>& getOutputs (unsigned nFrame) { return m_vOutputs.at (nFrame); }
    std::vector<std::vector<z3::expr> > &getAllOutputs () { return m_vOutputs; }
    

    /** Add glue clauses between current Inputs and previous frame outputs */
    void glueOutIn ()
    {
      assert (m_nFrames > 1);
      assert (m_vOutputs.at (frame () - 1).size() ==
              m_vInputs.at (frame ()).size());
    
      std::vector<z3::expr>& ins = m_vInputs.at (frame ());
      std::vector<z3::expr>& outs = m_vOutputs.at (frame () - 1);

      for (unsigned i=0; i < ins.size(); i++)
        {
          z3::expr& inVar = ins[i];
          z3::expr& outVar = outs[i];
          m_pSolver->add(inVar == outVar);
        }
    }

    void addTr ()
    {
      unsigned nFrame = frame ();
      if (nFrame == 0) addTr0 ();
      else addTrN ();
    }

      private:
        void addTr0  ();
        void addTrN  ();
        void addTrN2 ();
  };
}


#endif /* _UNROLLER_H_ */
