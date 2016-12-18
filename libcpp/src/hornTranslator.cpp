#include <iostream>

#include <abstraction.hpp>
#include <hornTranslator.hpp>
#include <hornDB.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    HornTranslator::HornTranslator (Abstraction* a)
      : _abs (a)
    {
        _ctx = new HornCtx;
    }

    // ---------------------------------------------------------------------- //
    HornTranslator::~HornTranslator ()
    {
        delete _ctx;
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::transAll (const std::string& fileName)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::transOne (NodeRef* node, const std::string& fileName)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::depthFirstTraverse (nptr_t n)
    {
        // if reach ITE operation, need to create new clauses.
        // remember to maintain and reuse the previous clause.
        if (!isITE(n)) {
            unsigned argNum = n->nArgs();
            for (unsigned i = 0; i != argNum; i++) {
                const nptr_t arg_i = n->arg(i);
                depthFirstTraverse(arg_i);
            }
            (*this) (n);
        } else {
            // TODO
        }
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::operator() (nptr_t nptr)
    {
        // iteratively fill in the clause body to the current clause.
        // horn clause head should not be handled here.
        hnptr_t hn = _ctx->getHornForNode (nptr);
        // TODO
        // based on different node type, add constraints to the clause body.
    }

    // ---------------------------------------------------------------------- //
    bool HornTranslator::isITE (nptr_t n)
    {
        const BoolOp* boolop = NULL;
        const BitvectorOp* bvop = NULL;
        const MemOp* memop = NULL;

        if ((boolop = dynamic_cast <const BoolOp*> (n.get()))) {
            return (boolop->op == BoolOp::Op::IF);
        } else if ((bvop = dynamic_cast <const BitvectorOp*> (n.get()))) {
            return (bvop->op == BitvectorOp::Op::IF);
        } else if ((memop = dynamic_cast <const MemOp*> (n.get()))) {
            return (memop->op == MemOp::Op::ITE);
        } else {
            return false;
        }
    }
}
