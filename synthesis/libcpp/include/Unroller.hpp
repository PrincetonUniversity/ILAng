#ifndef _UNROLLER_H_
#define _UNROLLER_H_

#include <cassert>

#include <unordered_map>
#include <vector>

#include "boost/foreach.hpp"
#include "boost/dynamic_bitset.hpp"
#include "boost/logic/tribool.hpp"
#include "logging.hpp"
#include <z3++.h>
#include <util.hpp>

#include <ast.hpp>

namespace ila
{
  class Abstraction;

  class Unroller
  {
    std::string m_sName;

    Abstraction* m_pAbstraction;
    z3::context* m_pContext;
    z3::solver* m_pSolver;
    unsigned m_nFrames;

    /// Map between primary input pointers and indices into m_vPrimaryInputs
    std::unordered_map<Node*, int,
        decltype(&nodeHash), decltype(&nodeEqual)> m_mInputIndices;
    /// Primary Inputs, by frame
    std::vector<std::vector<z3::expr> > m_vPrimaryInputs;

    /// Map between state pointers and indices into m_vOutputs
    std::unordered_map<Node*, int,
        decltype(&nodeHash), decltype(&nodeEqual)> m_mStateIndices;
    /// Outputs, by frame
    std::vector<std::vector<z3::expr> > m_vOutputs;

    /// All assumptions
    std::vector<z3::expr> m_Assumps;
    
    /// Expr for assertion to be checked
    z3::expr *m_pAssertion;

  
  public:
    Unroller(
        const char* suffix, Abstraction& abs, 
        z3::context &c, z3::solver &s)
      : m_sName(suffix)
      , m_pAbstraction(&abs)
      , m_pContext(&c)
      , m_pSolver (&s)
      , m_nFrames(0)
      , m_mInputIndices(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
      , m_mStateIndices(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
      , m_pAssertion(NULL)
    { newFrame (); setInit = true; checkAbsNextExpNotNull(); }

    ~Unroller () { reset (NULL); }

    void Fr0Init(bool init) {setInit = init;}

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
      m_vOutputs.clear ();

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
      m_vOutputs.resize(m_nFrames);
    }
    
    unsigned frames () { return m_nFrames; }
    
    
    void addPrimaryInput (z3::expr in)
    { m_vPrimaryInputs.at (frame ()).push_back(in); }

    z3::expr& getPrimaryInput (unsigned nFrame, int nNum)
    { return m_vPrimaryInputs.at (nFrame)[nNum]; }

    std::vector<z3::expr>& getPrimaryInputs (unsigned nFrame) { return m_vPrimaryInputs.at (nFrame); }

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
    

    void addTr ()
    {
      unsigned nFrame = frame ();
      if (nFrame == 0) addTr0 ();
      else addTrN ();
    }

    // use the current frame to replace the variable in a node
    z3::expr subsFormula(Node * n);
    void static EvalEachFrame(z3::model &m, Unroller *u , std::ostream & cexf);

      private:
        bool setInit;
        void addTr0  ();
        void addTrN ();

        bool checkAbsNextExpNotNull();
  };
}


#endif /* _UNROLLER_H_ */
