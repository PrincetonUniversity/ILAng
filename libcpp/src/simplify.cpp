#include <simplify.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    SimplifyVisitor::SimplifyVisitor(const nptr_vec_t& a)
      : assumps(a)
    {
    }

    SimplifyVisitor::~SimplifyVisitor()
    {
    }

    // ---------------------------------------------------------------------- //
    void SimplifyVisitor::preVisit(const Node* n)
    {
        auto bvop = dynamic_cast<const BitvectorOp*>(n);
        auto boolop = dynamic_cast<const BoolOp*>(n);

        // TODO
        if (bvop && bvop->getOp() == BitvectorOp::IF) {
            // TODO: push condition onto the stack.
        } else if(boolop && boolop->getOp() == BoolOp::IF) {
            // TODO: push condition onto the stack.
        }
    }

    void SimplifyVisitor::postVisit(const Node* n)
    {
    }
}
