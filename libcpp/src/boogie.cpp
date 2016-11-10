#include <boogie.hpp>
#include <abstraction.hpp>

namespace ila
{
    BoogieTranslator::BoogieTranslator(Abstraction* a)
      : abs(a)
    {
        abs->fetchExpr->getSupportVars(fetchVars);
        nptr_vec_t init_state;
        for (auto n : fetchVars) {
            const npair_t* pair = abs->getMapEntry(n->getName());
            ILA_ASSERT(pair != NULL, "Variable not in map.");
            if (abs->isInput(n->getName())) {
                inpFV.insert(n);
                std::cout << "inp  : " << n->getName() << std::endl;
            } else if (isConstant(pair)) {
                constFV.insert(n);
                std::cout << "cnst : " << n->getName() << std::endl;
            } else {
                varFV.insert(n);
                std::cout << "var  : " << n->getName() << std::endl;
                init_state.push_back(pair->init);
            }
        }
        states.push(init_state);
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
    }
}
