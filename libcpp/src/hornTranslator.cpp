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
        log1 ("Horn") << "transOne on " << node->getName() << "\n";
        depthFirstTraverse (node->node);
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
                depthFirstTraverse (arg_i);
            }
            (*this) (n);
        } else {
            ILA_ASSERT (n->nArgs() == 3, "ITE should have 3 args.");

            hcptr_t tempHc = _curHc;

            // condition
            hcptr_t hcCond = _ctx->addHornClause();
            _curHc = hcCond;
            depthFirstTraverse (n->arg(0));
            ILA_ASSERT (_curHc == hcCond, "invariant of curHC not hold.");
            hnptr_t hnCond = _ctx->getHornNode (n->arg(0));
            ILA_ASSERT (hnCond->isInit(), "ITE condition node not init.");
            hcCond->addOutput (hnCond);
            hcCond->setHead (hnCond);

            // then
            hcptr_t hcThen = _ctx->addHornClause();
            _curHc = hcThen;
            depthFirstTraverse (n->arg(1));
            ILA_ASSERT (_curHc == hcThen, "invariant of curHC not hold.");
            hnptr_t hnThen = _ctx->getHornNode (n->arg(1));
            ILA_ASSERT (hnThen->isInit(), "ITE then node not init.");
            hcThen->addOutput (hnThen);
            hcThen->setHead (hnThen);
            
            // else
            hcptr_t hcElse = _ctx->addHornClause();
            _curHc = hcElse;
            depthFirstTraverse (n->arg(2));
            ILA_ASSERT (_curHc == hcElse, "invariant of curHc not hold.");
            hnptr_t hnElse = _ctx->getHornNode (n->arg(2));
            ILA_ASSERT (hnElse->isInit(), "ITE else node not init.");
            hcElse->addOutput (hnElse);
            hcElse->setHead (hnElse);

            // ite
            hcptr_t hcIteT = _ctx->addHornClause();
            hcptr_t hcIteF = _ctx->addHornClause();
            hnptr_t hnIte = _ctx->getHornNode (n);

            hcIteT->addBody (hnCond, true);
            hcIteT->addBody (hnThen);
            hcIteT->setHead (hnIte);

            hcIteF->addBody (hnCond, false);
            hcIteF->addBody (hnElse);
            hcIteF->setHead (hnIte);

            _curHc = tempHc;
        }
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::operator() (nptr_t nptr)
    {
        // iteratively fill in the clause body to the current clause.
        // horn clause head should not be handled here.
        hnptr_t hn = _ctx->getHornNode (nptr);
        if (!hn->isInit()) {
            genHornNode (hn, nptr);
            hn->setInit();
        }
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

    // ---------------------------------------------------------------------- //
    void HornTranslator::genHornNode (hnptr_t hn, nptr_t node)
    {
        if (hn->isInit()) return;

        Node* n = node.get();

        log2 ("horn") << n->getName() << "\n";

        const BoolVar* boolvar = NULL;
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemOp*  memop = NULL;

        const FuncVar* funcvar = NULL;

        const BitvectorChoice* bvchoice = NULL;
        const BoolChoice* boolchoice = NULL;
        const MemChoice* memchoice = NULL;
        const WriteSlice* writeslice = NULL;
        const ReadSlice* readslice = NULL;

        //// Bool ////
        if ((boolvar = dynamic_cast <const BoolVar*> (n))) {
            genBoolVarHorn (boolvar, hn);
        } else if ((boolconst = dynamic_cast <const BoolConst*> (n))) {
            genBoolConstHorn (boolconst, hn);
        } else if ((boolop = dynamic_cast <const BoolOp*> (n))) {
            genBoolOpHorn (boolop, hn);
        //// Bitvector ////
        } else if ((bvvar = dynamic_cast <const BitvectorVar*> (n))) {
            genBvVarHorn (bvvar, hn);
        } else if ((bvconst = dynamic_cast <const BitvectorConst*> (n))) {
            genBvConstHorn (bvconst, hn);
        } else if ((bvop = dynamic_cast <const BitvectorOp*> (n))) {
            genBvOpHorn (bvop, hn);
        //// Mem ////
        } else if ((memvar = dynamic_cast <const MemVar*> (n))) {
            genMemVarHorn (memvar, hn);
        } else if ((memconst = dynamic_cast <const MemConst*> (n))) {
            genMemConstHorn (memconst, hn);
        } else if ((memop = dynamic_cast <const MemOp*> (n))) {
            genMemOpHorn (memop, hn);
        //// Func ////
        } else if ((funcvar = dynamic_cast <const FuncVar*> (n))) {
            genFuncVarHorn (funcvar, hn);
        //// Choice ////
        } else if ((boolchoice = dynamic_cast <const BoolChoice*> (n))) {
            ILA_ASSERT(false, "BoolChoice not implemented.");
        } else if ((bvchoice = dynamic_cast <const BitvectorChoice*> (n))) {
            ILA_ASSERT(false, "BitvectorChoice not implemented.");
        } else if ((memchoice = dynamic_cast <const MemChoice*> (n))) {
            ILA_ASSERT(false, "MemChoice not implemented.");
        } else if ((writeslice = dynamic_cast <const WriteSlice*> (n))) {
            ILA_ASSERT(false, "WriteSlice not implemented.");
        } else if ((readslice = dynamic_cast <const ReadSlice*> (n))) {
            ILA_ASSERT(false, "ReadSlice not implemented.");
        } else {
            ILA_ASSERT(false, "Unknown node type.");
        }

        hn->setInit();
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genBoolVarHorn (const BoolVar* n, hnptr_t hn)
    {
        // var should keep the original name.
        hn->setType ("Bool");
        hn->setName (n->getName());
        hn->setExec ("");
        hn->setPred (_pred_prefix + n->getName());
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genBoolConstHorn (const BoolConst* n, hnptr_t hn)
    {
        hn->setType ("Bool");
        hn->setName (_bool_prefix + 
                     boost::lexical_cast <std::string> (hn->getId()));
        hn->setExec ("");
        hn->setPred (_pred_prefix + hn->getName());
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genBoolOpHorn (const BoolOp* n, hnptr_t hn)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genBvVarHorn (const BitvectorVar* n, hnptr_t hn)
    {
        // (_ BitVec n)
        hn->setType ("(_ BitVec " + 
                     boost::lexical_cast<std::string>(n->type.dataWidth) + 
                     ")");
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genBvOpHorn (const BitvectorOp* n, hnptr_t hn)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genBvConstHorn (const BitvectorConst* n, hnptr_t hn)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genMemConstHorn (const MemConst* n, hnptr_t hn)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genMemVarHorn (const MemVar* n, hnptr_t hn)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genMemOpHorn (const MemOp* n, hnptr_t hn)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::genFuncVarHorn (const FuncVar* n, hnptr_t hn)
    {
        // TODO
    }
}
