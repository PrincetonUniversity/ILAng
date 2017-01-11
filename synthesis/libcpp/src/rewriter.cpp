#include <rewriter.hpp>
#include <util.hpp>

namespace ila
{
    Rewriter::Rewriter()
      : rwmap(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
    {
    }

    Rewriter::~Rewriter()
    {
    }

    // ---------------------------------------------------------------------- //
    void Rewriter::getNewArgs(
        const Node* op, 
        nptr_vec_t& args)
    {
        unsigned n = op->nArgs();
        for (unsigned i=0; i < n; i++) {
            const Node* n = op->arg(i).get();
            args.push_back(getRepl(n));
        }
    }

    nptr_t Rewriter::getRepl(const Node* n) const 
    {
        auto pos = rwmap.find(n);
        ILA_ASSERT(pos != rwmap.end(), "Unabel to find node in memo.");
        return pos->second;
    }

    void Rewriter::doRewrite(const Node* n) 
    {
        // memoization.
        auto pos = rwmap.find(n);
        if (pos != rwmap.end()) {
            return;
        }

        // n->write(std::cout << "visiting: ") << std::endl;
        // std::cout << "visiting: " << *n << std::endl;

        // now handle the various types.
        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;
        const BoolChoice* bchoiceop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;
        const ReadSlice* rdslice = NULL;
        const WriteSlice* wrslice = NULL;
        const BitvectorChoice* bvchoiceop = NULL;
        const BVInRange* inrangeop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemOp* memop = NULL;
        const MemChoice* mchoiceop = NULL;

        const FuncVar* funcvar = NULL;

        //// bools ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            nptr_t nptr(n->clone());
            rwmap.insert({n, nptr});
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            nptr_t nptr(n->clone());
            rwmap.insert({n, nptr});
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            nptr_vec_t args;
            getNewArgs(boolop, args);
            nptr_t nptr(new BoolOp(boolop, args));
            rwmap.insert({n, nptr});
        } else if ((bchoiceop = dynamic_cast<const BoolChoice*>(n))) {
            nptr_vec_t args;
            getNewArgs(bchoiceop, args);
            nptr_t nptr(bchoiceop->clone(args));
            rwmap.insert({n, nptr});
        //// bitvector ////
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            nptr_t nptr(n->clone());
            rwmap.insert({n, nptr});
        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            nptr_t nptr(n->clone());
            rwmap.insert({n, nptr});
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            nptr_vec_t args;
            getNewArgs(bvop, args);
            nptr_t nptr(new BitvectorOp(bvop, args));
            rwmap.insert({n, nptr});
        } else if ((rdslice = dynamic_cast<const ReadSlice*>(n))) {
            nptr_t bvp = getRepl(rdslice->bitvec.get());
            nptr_t nptr(ReadSlice::createReadSlice(
                rdslice->getName(), bvp, rdslice->width, rdslice->increment));
            rwmap.insert({n, nptr});
        } else if ((wrslice = dynamic_cast<const WriteSlice*>(n))) {
            nptr_t bvp = getRepl(wrslice->bitvec.get());
            nptr_t wrp = getRepl(wrslice->data.get());
            nptr_t nptr(WriteSlice::createWriteSlice(
                wrslice->getName(), bvp, wrp, wrslice->increment));
            rwmap.insert({n, nptr});
        } else if ((bvchoiceop = dynamic_cast<const BitvectorChoice*>(n))) {
            nptr_vec_t args;
            getNewArgs(bvchoiceop, args);
            nptr_t nptr(bvchoiceop->clone(args));
            rwmap.insert({n, nptr});
        } else if ((inrangeop = dynamic_cast<const BVInRange*>(n))) {
            nptr_t nptr(n->clone());
            rwmap.insert({n, nptr});
        //// memories ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            nptr_t nptr(n->clone());
            rwmap.insert({n, nptr});
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            nptr_t nptr(n->clone());
            rwmap.insert({n, nptr});
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            nptr_vec_t args;
            getNewArgs(memop, args);
            nptr_t nptr(new MemOp(memop, args));
            rwmap.insert({n, nptr});
        } else if ((mchoiceop = dynamic_cast<const MemChoice*>(n))) {
            nptr_vec_t args;
            getNewArgs(mchoiceop, args);
            nptr_t nptr(mchoiceop->clone(args));
            rwmap.insert({n, nptr});
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            nptr_t nptr(n->clone());
            rwmap.insert({n, nptr});
        }
    }


    // ---------------------------------------------------------------------- //
    void Rewriter::operator() (const Node* n)
    {
        doRewrite(n); 
    }

    // ---------------------------------------------------------------------- //
    nptr_t Rewriter::rewrite(const Node* n)
    {
        n->depthFirstVisit(*this);

        auto pos = rwmap.find(n);
        ILA_ASSERT(pos != rwmap.end(), "Unable to find node in memo.");
        return pos->second;
    }

    // ---------------------------------------------------------------------- //
    void Rewriter::addRewrite(const Node* n, const nptr_t& nprime)
    {
        rwmap[n] = nprime;
    }
}
