#include <smt.hpp>
#include <ast.hpp>

namespace ila
{

    // ---------------------------------------------------------------------- //
    Z3ExprAdapter::Z3ExprAdapter(z3::context& ctx, const std::string& s)
      : c(ctx)
      , suffix(s)
    {
    }

    Z3ExprAdapter::Z3ExprAdapter(z3::context& ctx, const char* s)
      : c(ctx)
      , suffix(s)
    {
    }

    Z3ExprAdapter::~Z3ExprAdapter()
    {
    }

    // ---------------------------------------------------------------------- //
    void Z3ExprAdapter::operator() (const Node* n)
    {
        // memoization.
        auto pos = exprmap.find(n);
        if (pos != exprmap.end()) {
            return;
        }

        // std::cout << "visiting: " << *n << std::endl;

        // now handle the various types.
        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;
        const BoolChoice* bchoiceop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;
        const BitvectorChoice* bvchoiceop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemWr*  memwr = NULL;

        //// booleans ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            z3::expr r = getBoolVarExpr(boolvar);
            exprmap.insert({n, r});
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            z3::expr r = c.bool_val(boolconst->val());
            exprmap.insert({n, r});
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            z3::expr r = getBoolOpExpr(boolop);
            exprmap.insert({n, r});
        } else if((bchoiceop = dynamic_cast<const BoolChoice*>(n))) {
            z3::expr r = getChoiceExpr(bchoiceop);
            exprmap.insert({n, r});

        //// bitvectors ////
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            z3::expr r = getBitvectorVarExpr(bvvar);
            exprmap.insert({n, r});
        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            z3::expr r = c.bv_val(bvconst->vstr().c_str(), bvconst->type.bitWidth);
            exprmap.insert({n, r});
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            z3::expr r = getBvOpExpr(bvop);
            exprmap.insert({n, r});
        } else if ((bvchoiceop = dynamic_cast<const BitvectorChoice*>(n))) {
            z3::expr r = getChoiceExpr(bvchoiceop);
            exprmap.insert({n, r});

        //// memories ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            z3::expr r = getMemVarExpr(memvar);
            exprmap.insert({n, r});
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            z3::expr r = memconst->memvalues.toZ3(c);
            exprmap.insert({n, r});
        } else if ((memwr = dynamic_cast<const MemWr*>(n))) {
            z3::expr r = getMemWrExpr(memwr);
            exprmap.insert({n, r});
        }
    }

    z3::expr Z3ExprAdapter::getExpr(const Node* n) 
    {
        n->depthFirstVisit(*this);
        auto pos = exprmap.find(n);
        ILA_ASSERT(pos != exprmap.end(), "expression not found in memo.");
        if (pos != exprmap.end()) {
            return pos->second;
        } else {
            return c.bool_val(false);
        }
    }

    // ---------------------------------------------------------------------- //

    std::string Z3ExprAdapter::extractNumeralString(z3::model& m, const Node* r)
    {
        using namespace z3;

        z3::expr r_e = getExpr(r);
        z3::expr m_e = m.eval(r_e, true);
        std::string s_e(Z3_get_numeral_string(c, m_e));
        return s_e;
    }

    int Z3ExprAdapter::getNumeralInt(z3::model& m, const Node* r)
    {
        using namespace z3;

        z3::expr r_e = getExpr(r);
        z3::expr m_e = m.eval(r_e, true);
        int i_e = 0;

        Z3_bool success = Z3_get_numeral_int(c, m_e, &i_e);
        ILA_ASSERT(success == Z3_TRUE, "Unable to extract int from model.");
        return i_e;
    }

    bool Z3ExprAdapter::getBoolValue(z3::model& m, const Node* r)
    {
        using namespace z3;
        z3::expr r_e = getExpr(r);
        z3::expr m_e = m.eval(r_e, true);
        Z3_lbool b_e = Z3_get_bool_value(c, m_e);
        ILA_ASSERT(b_e != Z3_L_UNDEF, "Unable to extract bool from model.");
        return b_e == Z3_L_TRUE;
    }

    // ---------------------------------------------------------------------- //
    z3::expr Z3ExprAdapter::getBoolVarExpr(const BoolVar* boolvar)
    {
        return c.bool_const(boolvar->name.c_str());
    }

    z3::expr Z3ExprAdapter::getBitvectorVarExpr(const BitvectorVar* bvvar)
    {
        return c.bv_const(bvvar->name.c_str(), bvvar->type.bitWidth);
    }

    z3::expr Z3ExprAdapter::getMemVarExpr(const MemVar* memvar)
    {
        auto addrsort = c.bv_sort(memvar->type.addrWidth);
        auto datasort = c.bv_sort(memvar->type.dataWidth);
        auto memsort = c.array_sort(addrsort, datasort);
        return c.constant(memvar->name.c_str(), memsort);
    }

    // ---------------------------------------------------------------------- //
    z3::expr Z3ExprAdapter::getBoolOpExpr(const BoolOp* boolop) 
    {
        using namespace z3;

        int arity = boolop->nArgs();
        const BoolOp::Op op = boolop->getOp();

        if (arity == 1) {
            expr arg = getArgExpr(boolop, 0);
            if (op == BoolOp::NOT) {
                return !arg;
            }
        } else if (arity == 2) {
            expr arg0 = getArgExpr(boolop, 0);
            expr arg1 = getArgExpr(boolop, 1);

            if (op == BoolOp::AND) {
                return (arg0 && arg1);
            } else if (op == BoolOp::OR) {
                return (arg0 || arg1);
            } else if (op == BoolOp::XOR) {
                Z3_ast r = Z3_mk_xor(c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::XNOR) {
                Z3_ast r = Z3_mk_xor(c, arg0, arg1);
                return !expr(c, r);
            } else if (op == BoolOp::NAND) {
                return !(arg0 && arg1);
            } else if (op == BoolOp::NOR) {
                return !(arg0 || arg1);
            } else if (op == BoolOp::IMPLY) {
                Z3_ast r = Z3_mk_implies(c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::SLT) {
                Z3_ast r = Z3_mk_bvslt( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::SGT) {
                Z3_ast r = Z3_mk_bvsgt( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::SLE) {
                Z3_ast r = Z3_mk_bvsle( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::SGE) {
                Z3_ast r = Z3_mk_bvsge( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::ULT) {
                Z3_ast r = Z3_mk_bvult( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::UGT) {
                Z3_ast r = Z3_mk_bvugt( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::ULE) {
                Z3_ast r = Z3_mk_bvule( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::UGE) {
                Z3_ast r = Z3_mk_bvuge( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BoolOp::EQUAL) {
                return (arg0 == arg1);
            } else if (op == BoolOp::DISTINCT) {
                return (arg0 != arg1);
            }
        } else if (arity == 3) {
            expr arg0 = getArgExpr(boolop, 0);
            expr arg1 = getArgExpr(boolop, 1);
            expr arg2 = getArgExpr(boolop, 2);

            if (op == BoolOp::IF) {
                return ite(arg0, arg1, arg2);
            }
        }
        ILA_ASSERT(false, "Unable to create Z3 expression for operator: " + 
                            BoolOp::operatorNames[op]);
        return c.bool_val(false);
    }

    z3::expr Z3ExprAdapter::getBvOpExpr(const BitvectorOp* bvop)
    {
        using namespace z3;
        int arity = bvop->nArgs();
        const BitvectorOp::Op op = bvop->getOp();

        if (arity == 1) {
            expr arg = getArgExpr(bvop, 0);
            if (op == BitvectorOp::NEGATE) {
                return -arg;
            } else if (op == BitvectorOp::COMPLEMENT) {
                return ~arg;
            } else if (op == BitvectorOp::LROTATE) {
                Z3_ast r = Z3_mk_rotate_left(c, bvop->param(0), arg);
                return expr(c, r);
            } else if (op == BitvectorOp::RROTATE) {
                Z3_ast r = Z3_mk_rotate_right(c, bvop->param(0), arg);
                return expr(c, r);
            } else if (op == BitvectorOp::Z_EXT) {
                unsigned outWidth = static_cast<unsigned> (bvop->param(0));
                unsigned bvWidth = static_cast<unsigned> (bvop->arg(0)->type.bitWidth);
                Z3_ast r = Z3_mk_zero_ext(c, outWidth - bvWidth, arg);
                return expr(c, r);
            } else if (op == BitvectorOp::S_EXT) {
                unsigned outWidth = static_cast<unsigned> (bvop->param(0));
                unsigned bvWidth = static_cast<unsigned> (bvop->arg(0)->type.bitWidth);
                Z3_ast r = Z3_mk_sign_ext(c, outWidth - bvWidth, arg);
                return expr(c, r);
            } else if (op == BitvectorOp::EXTRACT) {
                unsigned hi = static_cast<unsigned> (bvop->param(0));
                unsigned lo = static_cast<unsigned> (bvop->param(1));
                Z3_ast r = Z3_mk_extract(c, hi, lo, arg);
                return expr(c, r);
            }
        } else if (arity == 2) {
            expr arg0 = getArgExpr(bvop, 0);
            expr arg1 = getArgExpr(bvop, 1);

            if (op == BitvectorOp::ADD) {
                return arg0 + arg1;
            } else if (op == BitvectorOp::SUB) {
                return arg0 - arg1;
            } else if (op == BitvectorOp::AND) {
                return (arg0 & arg1);
            } else if (op == BitvectorOp::OR) {
                return (arg0 | arg1);
            } else if (op == BitvectorOp::XOR) {
                Z3_ast r = Z3_mk_bvxor(c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::XNOR) {
                Z3_ast r = Z3_mk_bvxnor(c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::NAND) {
                return ~(arg0 & arg1);
            } else if (op == BitvectorOp::NOR) {
                return ~(arg0 | arg1);
            } else if (op == BitvectorOp::SDIV) {
                Z3_ast r = Z3_mk_bvsdiv( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::UDIV) {
                Z3_ast r = Z3_mk_bvudiv( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::SREM) {
                Z3_ast r = Z3_mk_bvsrem( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::UREM) {
                Z3_ast r = Z3_mk_bvurem( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::SMOD) {
                Z3_ast r = Z3_mk_bvsmod( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::SHL) {
                Z3_ast r = Z3_mk_bvshl( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::LSHR) {
                Z3_ast r = Z3_mk_bvlshr( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::ASHR) {
                Z3_ast r = Z3_mk_bvashr( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::MUL) {
                Z3_ast r = Z3_mk_bvmul( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::CONCAT) {
                Z3_ast r = Z3_mk_concat( c, arg0, arg1);
                return expr(c, r);
            } else if (op == BitvectorOp::GET_BIT) {
                // If idx not in range, return bit 0
                unsigned wid = static_cast<unsigned>
                    (bvop->arg(0)->type.bitWidth);
                unsigned cmpWid = static_cast<unsigned> 
                    (bvop->arg(1)->type.bitWidth);
                expr vi = expr(c, Z3_mk_extract( c, 0, 0, arg0));
                for (unsigned i=0; i != wid; i++) {
                    expr num = c.bv_val(i, cmpWid);
                    expr cond = (arg1 == num);
                    expr vi_ = expr(c, Z3_mk_extract(c, i, i, arg0));
                    expr vi_next = ite(cond, vi_, vi);
                    vi = vi_next;
                }
                return vi;
            } else if (op == BitvectorOp::READMEM) {
                return select(arg0,arg1);
            }
        } else if (arity == 3) {
            expr arg0 = getArgExpr(bvop, 0);
            expr arg1 = getArgExpr(bvop, 1);
            expr arg2 = getArgExpr(bvop, 2);

            if (op == BitvectorOp::IF) {
                return ite(arg0, arg1, arg2);
            }
        }
        ILA_ASSERT(false, "Unable to create Z3 expression for operator: " + 
                            BitvectorOp::operatorNames[op]);
        return c.bool_val(false);
    }

    // ---------------------------------------------------------------------- //
    z3::expr Z3ExprAdapter::getMemWrExpr(const MemWr* mw)
    {
        using namespace z3;

        expr mem = getArgExpr(mw, 0);
        expr addr = getArgExpr(mw, 1);
        expr data = getArgExpr(mw, 2);

        return store(mem, addr, data);
    }

    // ---------------------------------------------------------------------- //
    z3::expr Z3ExprAdapter::getChoiceExpr(const BitvectorChoice* op)
    {
        return _getChoiceExpr(op);
    }

    z3::expr Z3ExprAdapter::getChoiceExpr(const BoolChoice* op)
    {
        return _getChoiceExpr(op);
    }

    // ---------------------------------------------------------------------- //

    z3::expr Z3ExprAdapter::getArgExpr(const Node* n, int i)
    {
        Node* arg = n->arg(i).get();
        auto pos = exprmap.find(arg);
        ILA_ASSERT(arg != NULL, "Invalid argument index.");
        if (pos == exprmap.end()) {
            std::cout << "Unable to find argument: " << *arg
                      << "; of node: " << *n << std::endl;
        }
        ILA_ASSERT(pos != exprmap.end(), "Unable to find argexpr in memo.");
        if (pos == exprmap.end()) {
            return c.bool_val(false);
        } else {
            return pos->second;
        }
    }

    // ---------------------------------------------------------------------- //

    Z3ExprRewritingAdapter::Z3ExprRewritingAdapter(
        z3::context& ctx, 
        z3::model& mod, 
        Z3ExprAdapter& a,
        const std::string& s)

      : Z3ExprAdapter(ctx, s)
      , m(mod)
      , adapter(a)
    {
    }

    Z3ExprRewritingAdapter::Z3ExprRewritingAdapter(
        z3::context& ctx, 
        z3::model& mod, 
        Z3ExprAdapter& a,
        const char* s)

      : Z3ExprAdapter(ctx, s)
      , m(mod)
      , adapter(a)
    {
    }

    Z3ExprRewritingAdapter::~Z3ExprRewritingAdapter()
    {
    }

    // ---------------------------------------------------------------------- //
    z3::expr Z3ExprRewritingAdapter::getBoolVarExpr(const BoolVar* boolvar)
    {
        bool value = adapter.getBoolValue(m, boolvar);
        return c.bool_val(value);
    }

    z3::expr Z3ExprRewritingAdapter::getBitvectorVarExpr(const BitvectorVar* bvvar)
    {
        std::string value = adapter.extractNumeralString(m, bvvar);
        return c.bv_val(value.c_str(), bvvar->type.bitWidth);
    }

    z3::expr Z3ExprRewritingAdapter::getExpr(const Node* n, const boost::python::object& result)
    {
        z3::expr r_e = Z3ExprAdapter::getExpr(n);

        if (n->type.isBool()) {
            bool value = boost::python::extract<int>(result) != 0;
            return r_e == c.bool_val(value);
        } else if(n->type.isBitvector()) {
            std::string string_result = 
                boost::python::extract<std::string>(boost::python::str(result));
            return r_e == c.bv_val(string_result.c_str(), n->type.bitWidth);
        } else {
            ILA_ASSERT(false, "Unimplemented type.");
            return c.bool_val(false);
        }
    }
}
