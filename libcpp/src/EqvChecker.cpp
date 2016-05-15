#include "EqvChecker.hpp"
#include <ast.hpp>
#include <abstraction.hpp>

using namespace std;

namespace ila
{


  bool checkMiter(z3::solver& S, z3::expr& e1, z3::expr& e2)
  {
      using namespace z3;
      auto r = S.check();
      if (r == sat) {
          z3::model m = S.get_model();
          z3::expr m1 = m.eval(e1);
          z3::expr m2 = m.eval(e1);
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
