#include <smt.hpp>
#include <ast.hpp>
#include <synthesizer.hpp>
#include <logging.hpp>
#include <memory>

namespace ila
{

    // ---------------------------------------------------------------------- //
    Z3ExprAdapter::Z3ExprAdapter(z3::context& ctx, const std::string& s)
      : exprmap(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
      , cnstmap(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
      , c(ctx)
      , suffix(s)
      , name_suffix("")
    {
        simplify = false;
    }

    Z3ExprAdapter::Z3ExprAdapter(z3::context& ctx, const char* s)
      : exprmap(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
      , cnstmap(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
      , c(ctx)
      , suffix(s)
      , name_suffix("")
    {
        simplify = false;
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

        log2("Z3ExprAdapter.operator()") << *n << std::endl;
        try {
            _populateExprMap(n);
            _populateCnstMap(n);
        } catch (z3::exception& e) {
            ILA_ASSERT(false, e.msg());
        }

    }

    void Z3ExprAdapter::_populateExprMap(const Node* n)
    {
        // handle the various types.
        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;
        const BoolChoice* bchoiceop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;
        const BitvectorChoice* bvchoiceop = NULL;
        const BVInRange* inrangeop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemOp*  memop = NULL;
        const MemChoice* mchoiceop = NULL;

        const FuncVar* funcvar = NULL;

        log2("Z3ExprAdapter._populateExprMap") << "entering: " << *n << std::endl;

        //// booleans ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            z3::expr r = getBoolVarExpr(boolvar);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            z3::expr r = c.bool_val(boolconst->val());
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            z3::expr r = getBoolOpExpr(boolop);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if((bchoiceop = dynamic_cast<const BoolChoice*>(n))) {
            z3::expr r = getChoiceExpr(bchoiceop);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});

        //// bitvectors ////
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            z3::expr r = getBitvectorVarExpr(bvvar);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            z3::expr r = c.bv_val(bvconst->vstr().c_str(), bvconst->type.bitWidth);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            z3::expr r = getBvOpExpr(bvop);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if ((bvchoiceop = dynamic_cast<const BitvectorChoice*>(n))) {
            z3::expr r = getChoiceExpr(bvchoiceop);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if ((inrangeop = dynamic_cast<const BVInRange*>(n))) {
            z3::expr r = getBVInRangeExpr(inrangeop);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});

        //// memories ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            z3::expr r = getMemVarExpr(memvar);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            z3::expr r = memconst->memvalues.toZ3(c);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            z3::expr r = getMemOpExpr(memop);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        } else if ((mchoiceop = dynamic_cast<const MemChoice*>(n))) {
            z3::expr r = getChoiceExpr(mchoiceop);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});

        //// Functions ////
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            z3::expr r = getFuncVarExpr(funcvar);
            if (simplify) r = r.simplify();
            log2("Z3ExprAdapter._populateExprMap") << *n << " --> " << r << std::endl;
            exprmap.insert({n, r});
        }
    }

    void Z3ExprAdapter::_populateCnstMap(const Node* n)
    {
        using namespace z3;

        expr cnst = c.bool_val(true);
        for (unsigned i=0, num=n->nArgs(); i != num; i++) {
            expr cnst_i = getArgCnst(n, i);
            cnst = cnst && cnst_i;
        }
        const BVInRange* inrangeop = NULL;
        // only op which needs special handling is BVInRange.
        if ((inrangeop = dynamic_cast<const BVInRange*>(n))) {
            z3::expr c = getBVInRangeCnst(inrangeop);
            cnst = cnst && c;
        }
        expr cnst_s = cnst.simplify();
        cnstmap.insert({n, cnst_s});
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

    z3::expr Z3ExprAdapter::getCnst(const Node* n)
    {
        n->depthFirstVisit(*this);
        auto pos = cnstmap.find(n);
        ILA_ASSERT(pos != cnstmap.end(), "constraint not found in memo.");
        if (pos != cnstmap.end()) {
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

        expr r_e = getExpr(r);
        expr m_e = m.eval(r_e, true);
        int i_e = 0;

        Z3_bool success = Z3_get_numeral_int(c, m_e, &i_e);
        ILA_ASSERT(success == Z3_TRUE, "Unable to extract int from model.");
        return i_e;
    }

    mp_int_t Z3ExprAdapter::getNumeralCppInt(z3::model& m, const Node* r)
    {
        using namespace z3;
        std::string s_r = extractNumeralString(m, r);
        mp_int_t m_r = boost::lexical_cast<mp_int_t>(s_r);
        return m_r;
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
        return c.bool_const((boolvar->getName() + name_suffix).c_str());
    }

    z3::expr Z3ExprAdapter::getBitvectorVarExpr(const BitvectorVar* bvvar)
    {
        return c.bv_const((bvvar->getName() + name_suffix).c_str(), bvvar->type.bitWidth);
    }

    z3::expr Z3ExprAdapter::getMemVarExpr(const MemVar* memvar)
    {
        auto addrsort = c.bv_sort(memvar->type.addrWidth);
        auto datasort = c.bv_sort(memvar->type.dataWidth);
        auto memsort = c.array_sort(addrsort, datasort);
        return c.constant((memvar->getName() + name_suffix).c_str(), memsort);
    }

    z3::expr Z3ExprAdapter::getFuncVarExpr(const FuncVar* funcvar)
    {
        using namespace z3;
        Z3_symbol name  = Z3_mk_string_symbol(c, funcvar->getName().c_str());
        Z3_sort ressort = c.bv_sort(funcvar->type.bitWidth);
        Z3_sort* domain = new Z3_sort[funcvar->type.argsWidth.size()];
        for (unsigned i=0; i != funcvar->type.argsWidth.size(); i++) {
            domain[i] = c.bv_sort(funcvar->type.argsWidth[i]);
        }

        Z3_func_decl fun = Z3_mk_func_decl(c, 
                                name,
                                funcvar->type.argsWidth.size(),
                                domain, 
                                ressort);
        Z3_ast funAst = Z3_func_decl_to_ast(c, fun);
        return expr(c, funAst);
    }

    // ---------------------------------------------------------------------- //
    z3::expr Z3ExprAdapter::getBoolOpExpr(const BoolOp* boolop) 
    {
        using namespace z3;

        log2("Z3ExprAdapter.getBoolOpExpr") 
            << "boolop: " << *boolop << std::endl;

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
        log2("Z3ExprAdapter.getBvOpExpr") 
            << "bvop: " << *bvop << std::endl;

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
            } else if (op == BitvectorOp::READMEMBLOCK) {
                ILA_ASSERT(bvop->nParams() == 2, "Two parameters expected.");
                int chunks = bvop->param(0);
                endianness_t e = (endianness_t) bvop->param(1);
                ILA_ASSERT(chunks >= 1, "One or more chunks expected.");
                expr result(c);
                for (int i=0; i < chunks; i++) {
                    expr data_i = select(arg0, arg1+i);
                    if (i == 0) {
                        result = data_i;
                    } else {
                        if (e == LITTLE_E) {
                            result = expr(c, Z3_mk_concat(c, data_i, result));
                        } else {
                            result = expr(c, Z3_mk_concat(c, result, data_i));
                        }
                    }
                }
                return result;
            }
        } else if (arity == 3) {
            expr arg0 = getArgExpr(bvop, 0);
            expr arg1 = getArgExpr(bvop, 1);
            expr arg2 = getArgExpr(bvop, 2);

            log2("Z3ExprAdapter.getBvOpExpr") 
                << "arg(0): " << *bvop->arg(0).get() << std::endl;
            log2("Z3ExprAdapter.getBvOpExpr") 
                << "arg0: " << arg0 << std::endl;
            log2("Z3ExprAdapter.getBvOpExpr")
                << "arg(1): " << *bvop->arg(1).get() << std::endl;
            log2("Z3ExprAdapter.getBvOpExpr") 
                << "arg1: " << arg1 << std::endl;
            log2("Z3ExprAdapter.getBvOpExpr") 
                << "arg(2): " << *bvop->arg(2).get() << std::endl;
            log2("Z3ExprAdapter.getBvOpExpr") 
                << "arg2: " << arg2 << std::endl;


            if (op == BitvectorOp::IF) {
                return ite(arg0, arg1, arg2);
            }
        }
        if (op == BitvectorOp::APPLY_FUNC) {
            expr func_ast = getArgExpr(bvop, 0);
            cast_ast<func_decl> cast;
            func_decl func(c, cast(c, func_ast));
            expr_vector fun_args(c);
            for (int i = 1; i != arity; i++) {
                fun_args.push_back(getArgExpr(bvop, i));
            }
            return func(fun_args);
        }
        ILA_ASSERT(false, "Unable to create Z3 expression for operator: " + 
                            BitvectorOp::operatorNames[op]);
        return c.bool_val(false);
    }

    // ---------------------------------------------------------------------- //
    z3::expr Z3ExprAdapter::getMemOpExpr(const MemOp* mw)
    {
        using namespace z3;

        if (mw->op == MemOp::STORE) {
            expr mem = getArgExpr(mw, 0);
            expr addr = getArgExpr(mw, 1);
            expr data = getArgExpr(mw, 2);

            return store(mem, addr, data);
        } else if (mw->op == MemOp::STOREBLOCK) {
            // full size.
            int fullDataSize = mw->arg(2)->type.bitWidth;
            // size of each chunk.
            int chunkSize = mw->arg(0)->type.dataWidth;
            // number of chunks.
            int chunks = fullDataSize / chunkSize;
            // this in the index added to the memory address
            int chunkIndex = 0;
            // this is index used to extract the data.
            int dataIndex = mw->endian == LITTLE_E ? 0 : fullDataSize - chunkSize;
            // fwd/backwd?
            int dataIncr  = mw->endian == LITTLE_E ? chunkSize : -chunkSize;
            // mem.
            expr mem = getArgExpr(mw, 0);
            expr addr = getArgExpr(mw, 1);
            // full chunk.
            expr data = getArgExpr(mw, 2);
            for (; chunkIndex < chunks; chunkIndex++, dataIndex += dataIncr)
            {
                expr addr_i = addr + chunkIndex;
                expr chunk_i = expr(c, Z3_mk_extract(
                    c, dataIndex+chunkSize-1, dataIndex, data));
                mem = store(mem, addr_i, chunk_i);
            }
            return mem;
        } else if (mw->op == MemOp::ITE) {
            expr cond = getArgExpr(mw, 0);
            expr m1 = getArgExpr(mw, 1);
            expr m2 = getArgExpr(mw, 2);

            return ite(cond, m1, m2);
        } else {
            ILA_ASSERT(false, "Unknown operator.");
            return c.bool_val(false);
        }
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

    z3::expr Z3ExprAdapter::getChoiceExpr(const MemChoice* op)
    {
        return _getChoiceExpr(op);
    }

    z3::expr Z3ExprAdapter::getBVInRangeExpr(const BVInRange* op)
    {
        using namespace z3;

        auto name = op->getName() + suffix;
        return c.bv_const(name.c_str(), op->type.bitWidth);
    }

    z3::expr Z3ExprAdapter::getBVInRangeCnst(const BVInRange* op)
    {
        using namespace z3;
        auto name = op->getName() + suffix;
        expr var = c.bv_const(name.c_str(), op->type.bitWidth);
        expr lo  = getArgExpr(op, 0);
        expr hi  = getArgExpr(op, 1);
        expr lc(c, Z3_mk_bvuge(c, var, lo));
        expr hc(c, Z3_mk_bvule(c, var, hi));
        return lc && hc;
    }

    // ---------------------------------------------------------------------- //

    z3::expr Z3ExprAdapter::_getArg(const expr_map_t& m, const Node* n, int i)
    {
        Node* arg = n->arg(i).get();
        auto pos = m.find(arg);
        ILA_ASSERT(arg != NULL, "Invalid argument index.");
        if (pos == m.end()) {
            std::cout << "Unable to find argument: " << *arg
                      << "; of node: " << *n << std::endl;
        }
        ILA_ASSERT(pos != m.end(), "Unable to find expression in memo.");
        if (pos == m.end()) {
            return c.bool_val(false);
        } else {
            return pos->second;
        }
    }

    // ---------------------------------------------------------------------- //

    Z3ExprRewritingAdapter::Z3ExprRewritingAdapter(
        z3::context& ctx, 
        const DistInput* di,
        const std::string& s)

      : Z3ExprAdapter(ctx, s)
      , distInp(di)
    {
    }

    Z3ExprRewritingAdapter::Z3ExprRewritingAdapter(
        z3::context& ctx, 
        const DistInput* di,
        const char* s)

      : Z3ExprAdapter(ctx, s)
      , distInp(di)
    {
    }

    Z3ExprRewritingAdapter::~Z3ExprRewritingAdapter()
    {
    }

    // ---------------------------------------------------------------------- //
    z3::expr Z3ExprRewritingAdapter::getBoolVarExpr(const BoolVar* boolvar)
    {
        bool value = distInp->getBoolValue(boolvar->getName());
        return c.bool_val(value);
    }

    z3::expr Z3ExprRewritingAdapter::getBitvectorVarExpr(const BitvectorVar* bvvar)
    {
        std::string value = distInp->getBitvecStr(bvvar->getName());
        return c.bv_val((value + name_suffix).c_str(), bvvar->type.bitWidth);
    }

    z3::expr Z3ExprRewritingAdapter::getMemVarExpr(const MemVar* mv)
    {
        const MemValues& memvals = distInp->getMemValues(mv->getName());
        return memvals.toZ3(c);
    }

    z3::expr Z3ExprRewritingAdapter::getIOCnst(const Node* n, const py::object& result)
    {
        using namespace py;
        z3::expr r_e = Z3ExprAdapter::getExpr(n);
        z3::expr c_e = Z3ExprAdapter::getCnst(n);

        if (n->type.isBool()) {
            // try to extract a bool.
            if (is_py_int(result)) {
                int er = extract<int>(result);
                return (r_e == c.bool_val(er != 0)) && c_e;
            } else {
                throw PyILAException(PyExc_ValueError,
                    "Unable to convert result into a boolean.");
            }
        } else if(n->type.isBitvector()) {
            // try to extract a bitvector.
            if (is_py_int_or_long(result)) {
                std::string sr = to_string(result);
                return (r_e == c.bv_val(sr.c_str(), n->type.bitWidth)) && c_e;
            } else {
                // we reach here only if there's an error.
                throw PyILAException(
                    PyExc_ValueError, 
                    "Unable to convert result into a bitvector.");
            }
        } else if (n->type.isMem()) {
            // and now try to extract a memtype.
            extract<MemValues&> mv_r(result);
            if (mv_r.check()) {
                return (r_e == mv_r().toZ3(c)) && c_e;
            } else {
                throw PyILAException(PyExc_ValueError,
                        "Unable to convert result into a MemValues object.");
            }
        } else {
            // should never happen.
            ILA_ASSERT(false, "Unimplemented type.");
            return c.bool_val(false);
        }
    }
}
