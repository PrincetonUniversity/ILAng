#ifndef _EQVCHECKER_H_
#define _EQVCHECKER_H_


#include "Unroller.hpp"
#include "MicroUnroller.hpp"
#include "abstraction.hpp"
#include "boost/foreach.hpp"

#include <vector>
namespace ila
{
  class Abstraction;
  class NodeRef;

  // Reasons print out

  bool NEQVarNotExist(const std::string & a1name, const std::string & a2name,
                    const std::string & notExistVarName);
  bool NEQVarTypeMismatch(const std::string & a1name, const std::string & a2name,
                    const std::string & VarName);
  bool NEQArchVarUpdateMismatch(const std::string & a1name, const std::string & a2name,
                      const std::string & VarName);

  unsigned DetermineUnrollBound( Abstraction * pAbs, const std::string & nodeName);
  
  // check after unrolling both
  bool bmc(
      unsigned n1, Abstraction* a1, NodeRef* r1, 
      unsigned n2, Abstraction* a2, NodeRef* r2);

  bool checkMiter(z3::solver& S, z3::expr& e1, z3::expr& e2);
}



#endif /* _SAFETYVC_H_ */
