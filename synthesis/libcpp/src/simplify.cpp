#include <simplify.hpp>
#include <logging.hpp>
#include <util.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    ITESimplifier::ITESimplifier(const nptr_t& a)
      : ctx()
      , S(ctx)
      , adapter(ctx, "")
      , rwmap(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
    {
        adapter.simplify = true;
        _add(a);
    }

    ITESimplifier::~ITESimplifier()
    {
    }

    // ---------------------------------------------------------------------- //
    void ITESimplifier::addAssumptions(const nptr_vec_t& avec)
    {
        for (auto&& a : avec) {
            _add(a);
        }
    }

    void ITESimplifier::addAssumption(const nptr_t& a)
    {
        _add(a);
    }

    // ---------------------------------------------------------------------- //
    void ITESimplifier::_add(const nptr_t& a, bool negate)
    {
        z3::expr e_a = adapter.getExpr(a.get());
        z3::expr c_a = adapter.getCnst(a.get());

        if(negate) e_a = (!e_a).simplify();
        S.add(e_a);
        S.add(c_a);

        log2("ITESimplifier._add") << "assumption/expr: " << e_a << std::endl;
        log2("ITESimplifier._add") << "assumption/cnst: " << c_a << std::endl;
    }

    boost::logic::tribool ITESimplifier::_isConstant(const nptr_t& cond)
    {
        log2("ITESimplifier._isConstant") << *(cond.get()) << std::endl;

        using namespace boost::logic;
        using namespace z3;
        S.push();
        expr e_cond = adapter.getExpr(cond.get());
        expr c_cond = adapter.getCnst(cond.get()); 
        S.add(c_cond);

        tribool is_cnst = indeterminate;

        // can this be false?
        S.push();
        S.add(!e_cond);
        auto r_false = S.check();
        S.pop();

        // can this be true?
        S.push();
        S.add(e_cond);
        auto r_true = S.check();
        S.pop();

        // now check if it is constant.
        if ((r_false == unknown || r_true == unknown) ||
            (r_false == sat && r_true == sat)) 
        {
            is_cnst = indeterminate;
        } else if (r_false == sat) {
            is_cnst = false;
        } else {
            is_cnst = true;
        }
        S.pop();

        return is_cnst;
    }

    // ---------------------------------------------------------------------- //
    void ITESimplifier::createClone(const Node* n)
    {
        auto pos = rwmap.find(n);
        if (pos != rwmap.end()) {
            return;
        }

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

    nptr_t ITESimplifier::rewriteITE(const Node* n) 
    {
        S.pop();
        log2("ITESimplifier.rewriteITE") << "S.pop(): " << *n << std::endl;

        const nptr_t& cond = n->arg(0);
        auto iscnst = _isConstant(cond);
        if (iscnst == true) {
            log2("ITESimplifier.rewriteITE") << *(cond.get()) << ": TRUE" << std::endl;
            return getRepl(n->arg(1).get());
        } else if(iscnst == false) {
            log2("ITESimplifier.rewriteITE") << *(cond.get()) << ": FALSE" << std::endl;
            return getRepl(n->arg(2).get());
        } else {
            return NULL;
        }
    }

    // ---------------------------------------------------------------------- //
    void ITESimplifier::getNewArgs(
        const Node* op, 
        nptr_vec_t& args)
    {
        unsigned n = op->nArgs();
        for (unsigned i=0; i < n; i++) {
            const Node* n = op->arg(i).get();
            args.push_back(getRepl(n));
        }
    }

    nptr_t ITESimplifier::getRepl(const Node* n) const 
    {
        auto pos = rwmap.find(n);
        log2("ITESimplifier.getRepl") << *n << std::endl;
        ILA_ASSERT(pos != rwmap.end(), "Unable to find node in memo.");
        return pos->second;
    }

    void ITESimplifier::dfs(const Node* n)
    {
        auto pos = rwmap.find(n);
        if (pos != rwmap.end()) {
            return;
        }

        auto bvop = dynamic_cast<const BitvectorOp*>(n);
        auto boolop = dynamic_cast<const BoolOp*>(n);
        auto memop = dynamic_cast<const MemOp*>(n);

        // special handling of ITEs
        if ((bvop && bvop->getOp() == BitvectorOp::IF) ||
            (boolop && boolop->getOp() == BoolOp::IF)  ||
            (memop && memop->getOp() == MemOp::ITE))
        {
            log2("ITESimplifier.dfs") << "ite: " << *n << std::endl;

            const nptr_t& cond = n->arg(0);
            const nptr_t& t_val = n->arg(1);
            const nptr_t& f_val = n->arg(2);

            // into the condition.
            dfs(cond.get());

            // true
            S.push();
            _add(cond, false);
            auto r_true = S.check();
            ILA_ASSERT(r_true != z3::unknown, "Undef result from SMT.");
            if (r_true == z3::sat) {
                log2("ITESimplifier.dfs") << "ite: TRUE sat: " << *(cond.get()) << std::endl;
                dfs(t_val.get());
            }
            S.pop();

            // false.
            S.push();
            _add(cond, true);
            auto r_false = S.check();
            ILA_ASSERT(r_false != z3::unknown, "Undef result from SMT.");
            if (r_false == z3::sat) {
                log2("ITESimplifier.dfs") << "ite: FALSE sat: " << *(cond.get()) << std::endl;
                dfs(f_val.get());
            }
            S.pop();

            // sanity check.
            ILA_ASSERT(r_true == z3::sat || r_false == z3::sat,
                       "At least one branch of the ite must be true.");

            // create the new node.

            // check which branch needs to be created.
            if (r_true == z3::unsat) {
                nptr_t f_val_p = getRepl(f_val.get());
                log2("ITESimplifier.dfs") << "ite: TRUE unsat: " << *(cond.get()) 
                       << " --> " << *f_val_p.get() << std::endl;
                rwmap.insert({n, f_val_p});
            } else if (r_false == z3::unsat) {
                nptr_t t_val_p = getRepl(t_val.get());
                log2("ITESimplifier.dfs") << "ite: FALSE unsat: " << *(cond.get()) 
                       << " --> " << *t_val_p.get() << std::endl;
                rwmap.insert({n, t_val_p});
            } else {
                nptr_vec_t args;
                getNewArgs(n, args);

                if (boolop) {
                    nptr_t nptr(new BoolOp(boolop, args));
                    rwmap.insert({n, nptr});
                } else if (bvop) {
                    nptr_t nptr(new BitvectorOp(bvop, args));
                    rwmap.insert({n, nptr});
                } else if (memop) {
                    nptr_t nptr(new MemOp(memop, args));
                    rwmap.insert({n, nptr});
                } else {
                    ILA_ASSERT(false, "Should never get here!");
                }
            }
        } else {
            log2("ITESimplifier.dfs") << "node: " << *n << std::endl;

            // the rest are handled here.
            for (unsigned i=0, cnt = n->nArgs(); i != cnt; i++) {
                dfs(n->arg(i).get());
            }
            createClone(n);
        }
    }

    // ---------------------------------------------------------------------- //
    nptr_t ITESimplifier::simplify(Node* n)
    {
        dfs(n);

        auto pos = rwmap.find(n);
        log2("ITESimplifier.simplify") << *n << std::endl;
        ILA_ASSERT(pos != rwmap.end(), "Node not found in map after visit.");
        return pos->second;
    }
}
