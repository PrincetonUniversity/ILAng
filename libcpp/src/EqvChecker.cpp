#include "EqvChecker.hpp"
#include <ast.hpp>
#include <abstraction.hpp>

using namespace std;

namespace ila
{


  bool NEQVarNotExist(const std::string & a1name, const std::string & a2name,
                    const std::string & notExistVarName)
  {
      std::cout <<"State "<<notExistVarName <<" of "<<a1name<<" does not exist in "
                <<a2name<<std::endl;
      return false;
  }
  bool NEQVarTypeMismatch(const std::string & a1name, const std::string & a2name,
                    const std::string & VarName)
  {
      std::cout <<"State "<<VarName <<" of "<<a1name<<" does not match the one in "
                <<a2name<<std::endl;
      return false;
  }  
  bool NEQArchVarUpdateMismatch(const std::string & a1name, const std::string & a2name,
                    const std::string & VarName)
  {
      std::cout <<"Update function of state "<<VarName <<" of "<<a1name<<" does not match the one in "
                <<a2name<<std::endl;
      return false;
  }   

  unsigned DetermineUnrollBound( Abstraction * pAbs, const std::string & nodeName)
  {
    bool NoUpdate = true;
    for(auto && uab : pAbs->uabs)
    {
        auto pos = uab.second.abs->findInMap(nodeName); // reg->first is the name
        
        if(! pos->second.next.get() )
            continue;
        NoUpdate = false;
        break;
    }
    if (NoUpdate)
    {
        std::cout<<"Note: "<<nodeName<<" in "<<(pAbs->name)<<" is not updated by micro/sub ILA."<<std::endl;
        return 1;
    }
    return -1;
  }

  
  bool checkMiter(z3::solver& S, z3::expr& e1, z3::expr& e2)
  {
      using namespace z3;
      auto r = S.check();
      if (r == sat) {
          z3::model m = S.get_model();
          z3::expr m1 = m.eval(e1);
          z3::expr m2 = m.eval(e2);
          std::cout << m << std::endl;
          std::cout << m1 << std::endl;
          std::cout << m2 << std::endl;
          return false;
      } else if (r == unsat) {
          return true;
      } else {
          throw PyILAException(PyExc_RuntimeError, "Indeterminate result from Z3.");
          return false;
      }
  }

}
