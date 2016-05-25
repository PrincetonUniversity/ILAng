#include <simplify.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    ITESimplifier::ITESimplifier(const nptr_t& a)
    {
        assumps.push(a);
    }

    ITESimplifier::~ITESimplifier()
    {
    }

    // ---------------------------------------------------------------------- //
    void ITESimplifier::addAssumptions(const nptr_vec_t& avec)
    {
        for (auto&& a : avec) {
            assumps.push(a);
        }
    }

    void ITESimplifier::addAssumption(const nptr_t& a)
    {
        assumps.push(a);
    }

    // ---------------------------------------------------------------------- //
    void ITESimplifier::preVisit(const Node* n)
    {
        auto bvop = dynamic_cast<const BitvectorOp*>(n);
        auto boolop = dynamic_cast<const BoolOp*>(n);
        auto memop = dynamic_cast<const MemOp*>(n);

        // TODO
        if ((bvop && bvop->getOp() == BitvectorOp::IF) ||
            (boolop && boolop->getOp() == BoolOp::IF)  ||
            (memop && memop->getOp() == MemOp::ITE))
        {
            const nptr_t& cond = n->arg(0);
            assumps.push(cond);
        }
    }

    void ITESimplifier::postVisit(const Node* n)
    {
    }
    // ---------------------------------------------------------------------- //
}
