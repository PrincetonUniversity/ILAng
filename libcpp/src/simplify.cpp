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
    void preVisit(const Node* n)
    {
        auto bvop = dynamic_cast<const BitvectorOp*>(n);
        auto boolop = dynamic_cast<const BoolOp*>(n);

        if (bvop && bvop->getOp() == BitvectorOp::IF) {
        }
    }
}
