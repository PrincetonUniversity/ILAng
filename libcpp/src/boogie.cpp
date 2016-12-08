#include <boogie.hpp>
#include <abstraction.hpp>

namespace ila
{
    BoogieTranslator::BoogieTranslator(Abstraction* a)
      : abs(a)
      , c(c_, "")
    {
        abs->fetchExpr->getSupportVars(fetchVars);
        std::unique_ptr<nodevec_t> init_state(new nodevec_t());
        for (auto n : fetchVars) {
            const npair_t* pair = abs->getMapEntry(n->getName());
            ILA_ASSERT(pair != NULL, "Variable not in map.");
            if (abs->isInput(n->getName())) {
                inpFV.push_back(n);
                std::cout << "inp  : " << n->getName() << std::endl;
            } else if (isConstant(pair)) {
                std::cout << "cnst : " << n->getName() << std::endl;
                constFV.push_back(n);
                constEx.push_back(c.getExpr(n));
            } else {
                varFV.push_back(n);
                std::cout << "var  : " << n->getName() << std::endl;
                init_state->push_back(pair->init.get());
            }
        }
    }


    BoogieTranslator::~BoogieTranslator()
    {
    }

    bool BoogieTranslator::isConstant(const npair_t* obj)
    {
        return obj->next->equal(obj->var.get());
    }

    void BoogieTranslator::translate()
    {
        z3::solver S(c_);

        while(states.size() > 0) {
        }
    }
}
