#ifndef _EQVCHECKER_H_
#define _EQVCHECKER_H_


#include "Unroller.hpp"
#include "Abstraction.hpp"
#include "boost/foreach.hpp"

#include <vector>
namespace ila
{
  using namespace z3;
  
  /**
   * (Bounded) Equivalence checker
   */
  class EqvChecker
  {
    /// The Z3 context
    z3::context* m_pContext;
    z3::solver m_Solver;

    Unroller* m_pUnroller1;
    Unroller* m_pUnroller2;

    /// initialize given a circuit
    void init ();

  public:
    /// create a VC given from a circuit. Init is implicit.
    EqvChecker(z3::context& c, Unroller& u1, Unroller& u2) :
          m_pContext(&c)
        , m_Solver(c)
        , m_pUnroller1(&u1)
        , m_pUnroller2(&u2)
    { init (); }
    
    Abstraction* getUnroller1 () { return m_pUnroller1; }
    Abstraction* getUnroller2 () { return m_pUnroller2; }
    
    
  public:
    
    // Match the outputs
    void addBad (unsigned nFrame1, unsigned nFrame2)
    {
      std::vector<z3::expr>& outputs1 = m_pUnroller1->getOutputs(nFrame1);
      std::vector<z3::expr>& outputs2 = m_pUnroller2->getOutputs(nFrame2);
    }
    
  };
}



#endif /* _SAFETYVC_H_ */
