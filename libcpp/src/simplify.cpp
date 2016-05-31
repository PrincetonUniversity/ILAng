#include <simplify.hpp>
#include <logging.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    ITESimplifier::ITESimplifier(const nptr_t& a)
      : ctx()
      , S(ctx)
      , adapter(ctx, "")
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
    void ITESimplifier::_add(const nptr_t& a)
    {
        z3::expr e_a = adapter.getExpr(a.get());
        z3::expr c_a = adapter.getCnst(a.get());
        S.add(e_a);
        S.add(c_a);
    }

    boost::logic::tribool ITESimplifier::_isConstant(const nptr_t& cond)
    {
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
    void ITESimplifier::preVisit(const Node* n)
    {
        auto bvop = dynamic_cast<const BitvectorOp*>(n);
        auto boolop = dynamic_cast<const BoolOp*>(n);
        auto memop = dynamic_cast<const MemOp*>(n);

        if ((bvop && bvop->getOp() == BitvectorOp::IF) ||
            (boolop && boolop->getOp() == BoolOp::IF)  ||
            (memop && memop->getOp() == MemOp::ITE))
        {
            const nptr_t& cond = n->arg(0);
            S.push();
            _add(cond);
        }
    }

    void ITESimplifier::postVisit(const Node* n)
    {
        auto bvop = dynamic_cast<const BitvectorOp*>(n);
        auto boolop = dynamic_cast<const BoolOp*>(n);
        auto memop = dynamic_cast<const MemOp*>(n);

        if ((bvop && bvop->getOp() == BitvectorOp::IF) ||
            (boolop && boolop->getOp() == BoolOp::IF)  ||
            (memop && memop->getOp() == MemOp::ITE))
        {
            S.pop();

            const nptr_t& cond = n->arg(0);
            auto iscnst = _isConstant(cond);
            if (iscnst == true) {
                log2() << *(cond.get()) << ": TRUE" << std::endl;
                rwmap[n] = n->arg(1);
            } else if(iscnst == false) {
                log2() << *(cond.get()) << ": FALSE" << std::endl;
                rwmap[n] = n->arg(2);
            } else {
                rwmap[n] = nptr_t(n->clone());
            }
        } else {
            rwmap[n] = nptr_t(n->clone());
        }
    }

    // ---------------------------------------------------------------------- //
    nptr_t ITESimplifier::simplify(Node* n)
    {
        n->visit(*this);
        auto pos = rwmap.find(n);
        ILA_ASSERT(pos != rwmap.end(), "Node not found in map after visit.");
        return pos->second;
    }
}
