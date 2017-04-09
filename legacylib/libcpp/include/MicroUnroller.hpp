#ifndef _MICRO_UNROLLER_H_
#define _MICRO_UNROLLER_H_

#include <cassert>

#include <unordered_map>
#include <vector>

#include "boost/python.hpp"
#include "boost/foreach.hpp"
#include "boost/dynamic_bitset.hpp"
#include "boost/logic/tribool.hpp"
#include <z3++.h>
#include <util.hpp>

#include <ast.hpp>

namespace ila
{
  class Abstraction;
  class AbstractionWrapper;

  class MicroUnroller
  {
    std::string m_sName;

    Abstraction* m_pAbstraction;
    Abstraction* m_pUAbstraction; // currently we are only able to handle one valid Uabs
    
    z3::context* m_pContext;
    z3::solver* m_pSolver;
    unsigned m_nFrames;

    /// Map between primary input pointers and indices into m_vPrimaryInputs
    std::unordered_map<Node*, int,
        decltype(&nodeHash), decltype(&nodeEqual)> m_mInputIndices;
    /// Primary Inputs, by frame
    std::vector<z3::expr> m_vPrimaryInputs;

    
    /// Map between state pointers and indices into m_vOutputs
    std::unordered_map<Node*, unsigned,
        decltype(&nodeHash), decltype(&nodeEqual)> m_mStateIndices;
    /// Outputs, by frame
    std::vector<std::vector<z3::expr> > m_vOutputs;

    /// All assumptions
    std::vector<z3::expr> m_Assumps;
    

    static z3::context MicroUnrollContext;
    static z3::solver MicroUnrollSolver;

  public:
    static MicroUnroller * NewUnroller(AbstractionWrapper *Abs, AbstractionWrapper *Uabs, bool InitCond);
    static void EqOffline(const std::string & fileName, MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2);
    static void EqOffline(const std::string & fileName, MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2, py::list & assumps);
    static bool EqCheck(MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2);
    static bool EqCheck(MicroUnroller *m1, MicroUnroller *m2, const std::string &n1, const std::string &n2, py::list & assumps);
  
  public:
    MicroUnroller(
        const char* suffix, Abstraction& abs, 
        Abstraction &uabs,
        z3::context &c, z3::solver &s,
        bool InitCond)
      : m_sName(suffix)
      , m_pAbstraction(&abs)
      , m_pUAbstraction(&uabs)
      , m_pContext(&c)
      , m_pSolver (&s)
      , m_nFrames(0)
      , m_mInputIndices(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
      , m_mStateIndices(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
    { newFrame ();debug = false; setup2Frames(InitCond); }

    ~MicroUnroller () { reset (NULL); }

      

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
    
    unsigned frame () { return m_nFrames - 1; }
    
    void newFrame ()
    {
      m_nFrames++;
      m_vOutputs.resize(m_nFrames);
    }
    
    unsigned frames () { return m_nFrames; }
    
    
    unsigned addPrimaryInput (z3::expr in)
    {   
        unsigned idx = m_vPrimaryInputs.size();
        m_vPrimaryInputs.push_back(in);
        return idx;
    }

    // inputs are only at 0
    z3::expr& getPrimaryInput (int nNum)
    { return m_vPrimaryInputs[nNum]; }
    z3::expr& getPrimaryInput(Node* var) {
        auto pos = m_mInputIndices.find(var);
        ILA_ASSERT (pos != m_mInputIndices.end(), "Unable to find var in input.");
        return getPrimaryInput(pos->second);
    }

    std::vector<z3::expr>& getPrimaryInputs () { return m_vPrimaryInputs; }

    unsigned addOutput (z3::expr out)
    { 
        unsigned idx = m_vOutputs.at(frame()).size(); 
        m_vOutputs.at (frame ()).push_back(out); 
        return idx;
    }

    z3::expr& getOutput (Node* var) {
        auto pos = m_mStateIndices.find(var);
        ILA_ASSERT (pos != m_mStateIndices.end(), "Unable to find var in map.");
        return getOutput(frame(), pos->second);
    }

    z3::expr& getOutput (unsigned nFrame, Node* var) {
        auto pos = m_mStateIndices.find(var);
        ILA_ASSERT (pos != m_mStateIndices.end(), "Unable to find var in map.");
        return getOutput(nFrame, pos->second);
    }

    z3::expr& getOutput (unsigned nFrame, int nNum)
    { return m_vOutputs.at (nFrame)[nNum]; }

    std::vector<z3::expr>& getOutputs (unsigned nFrame) { return m_vOutputs.at (nFrame); }
    std::vector<std::vector<z3::expr> > &getAllOutputs () { return m_vOutputs; }
    
public:

    bool debug;

    bool checkAssertion(NodeRef * assertion);
    void dumpAssertion(NodeRef * assertion, const std::string & fileName);
    void addAssumption(NodeRef * assumption);
    z3::expr subsFormulaOnFrame(unsigned nframe, nptr_t & formula);
    z3::expr getNodeOnFrame(unsigned nframe, nptr_t & node);
    void unrollToStep(unsigned bound);
    void InsertAssumptions();
    void InsertAssumptSub(z3::expr_vector &src, z3::expr_vector &dest);


private:
    void setup2Frames(bool initCond);

    std::string static frame2suffix(unsigned fr, bool init = false);

    void _initVar(Z3ExprAdapter& z3expr, const npair_t& p, bool allowInit);
    void addInputNodes();
    void addArchStatesToFirstFrame();
    void addAllStatesToSecondFrame(bool initCondSet);
    void addAllStatesToLaterFrame();

    z3::expr subsFormula(Node * n);
    void debugFrame();

    void static EvalEachFrame(z3::model &m, MicroUnroller *u , std::ostream & cexf);

    bool static checkMiter(z3::solver& S, z3::expr& e1, z3::expr& e2, MicroUnroller *u1, MicroUnroller *u2);
  };


}


#endif /* _UNROLLER_H_ */
