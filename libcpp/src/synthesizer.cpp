#include <synthesizer.hpp>
#include <exception.hpp>
#include <util.hpp>

namespace ila
{
    const char* Synthesizer::suffix1 = ":1";
    const char* Synthesizer::suffix2 = ":2";

    // ---------------------------------------------------------------------- //
    void SupportVars::operator() (const Node* n)
    {
        const BoolVar* boolvar = NULL; 
        const BitvectorVar* bvvar = NULL;
        const MemVar* memvar = NULL;

        //// booleans ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))     ||
            (bvvar = dynamic_cast<const BitvectorVar*>(n))  ||
            (memvar = dynamic_cast<const MemVar*>(n)))
        {
            vars.insert(n);
        }
    }

    bool SupportVars::hasNode(const Node* v) const
    {
        return vars.find(v) != vars.end();
    }

    bool SupportVars::hasNode(const nptr_t& v) const
    {
        return hasNode(v.get());
    }

    // ---------------------------------------------------------------------- //
    DistInput::DistInput(Abstraction& abs, Z3ExprAdapter& c, z3::model& m)
    {
        using namespace z3;

        for (auto mem: abs.getMems()) {
            MemValues mv(c, m, dynamic_cast<MemVar*>(mem.second.var.get()));
            mems.insert({mem.first, mv});
        }

        for (auto r : abs.getInps()) {
            std::string s_e = c.extractNumeralString(m, r.second.var.get());
            bitvecs[r.first] = s_e;
        }

        for (auto r : abs.getRegs()) {
            std::string s_e = c.extractNumeralString(m, r.second.var.get());
            bitvecs[r.first] = s_e;
        }

        for (auto b : abs.getBits()) {
            bool b_e = c.getBoolValue(m, b.second.var.get());
            bools[b.first] = b_e;
        }
    }

    void DistInput::toPython(py::dict& d)
    {
        for (auto mem : mems) {
            d[mem.first] = mem.second;
        }

        for (auto bv : bitvecs) {
            d[bv.first] = to_pyint(bv.second);
        }

        for (auto b : bools) {
            d[b.first] = (int) b.second;
        }
    }

    bool DistInput::getBoolValue(const std::string& n) const
    {
        auto pos = bools.find(n);
        ILA_ASSERT(pos != bools.end(), "Unable to find variable in map.");
        return pos->second;
    }

    std::string DistInput::getBitvecStr(const std::string& n) const
    {
        auto pos = bitvecs.find(n);
        ILA_ASSERT(pos != bitvecs.end(), "Unable to find variable in map.");
        return pos->second;
    }

    const MemValues& DistInput::getMemValues(const std::string& n) const
    {
        auto pos = mems.find(n);
        ILA_ASSERT(pos != mems.end(), "Unable to find variable in map.");
        return pos->second;
    }

    // ---------------------------------------------------------------------- //
    SimOutput::SimOutput()
    {
    }

    SimOutput::SimOutput(const NodeType& nt, const py::object& r)
    {
        initOutput(nt, r);
    }

    SimOutput::SimOutput(const SimOutput& that)
      : out(that.out)
    {
    }

    SimOutput& SimOutput::operator=(const SimOutput& that)
    {
        out = that.out;
        return *this;
    }

    bool SimOutput::operator==(const SimOutput& that) const
    {
        if (out.which() != that.out.which()) return false;

        if (out.which() == 0) {
            // memories.
            const MemValues& m1 = boost::get<const MemValues&>(out);
            const MemValues& m2 = boost::get<const MemValues&>(that.out);
            return m1.semanticEqual(m2);
        } else if (out.which() == 1) {
            // bitvectors.
            const std::string& s1 = boost::get<const std::string&>(out);
            const std::string& s2 = boost::get<const std::string&>(that.out);
            try {
                mp_int_t i1 = boost::lexical_cast<mp_int_t>(s1);
                mp_int_t i2 = boost::lexical_cast<mp_int_t>(s2);
                return i1 == i2;
            } catch(const boost::bad_lexical_cast&) {
                return false;
            }
        } else if (out.which() == 2) {
            // booleans.
            bool b1 = boost::get<bool>(out);
            bool b2 = boost::get<bool>(that.out);
            return b1 == b2;
        } else {
            ILA_ASSERT(false, "Unknown value returned by which().");
            return false;
        }
    }

    void SimOutput::initOutput(const NodeType& nt, const py::object& r)
    {
        using namespace py;
        if (nt.isBool()) {
            // try to extract a bool.
            if (is_py_int(r)) {
                out = extract<int>(r);
            } else {
                throw PyILAException(PyExc_ValueError,
                    "Unable to convert result into a boolean.");
            }
        } else if(nt.isBitvector()) {
            // try to extract a bitvector.
            if (is_py_int_or_long(r)) {
                out = to_string(r);
            } else {
                throw PyILAException(PyExc_ValueError, 
                    "Unable to convert result into a bitvector.");
            }
        } else if (nt.isMem()) {
            // and now try to extract a memtype.
            extract<MemValues&> mv_r(r);
            if (mv_r.check()) {
                out = mv_r();
            } else {
                throw PyILAException(PyExc_ValueError,
                        "Unable to convert result into a MemValues object.");
            }
        } else {
            // should never happen.
            ILA_ASSERT(false, "Unimplemented type.");
        }
    }

    DistTreeNode::DistTreeNode(Abstraction& a, Z3ExprAdapter& c, z3::model& m)
      : inputs(a, c, m)
    {
    }

    // ---------------------------------------------------------------------- //
    SimoutAdapter::SimoutAdapter(Z3ExprRewritingAdapter& a, const Node* n)
      : adapter(a)
      , node(n)
      , r_expr(adapter.getExpr(n))
      , r_cnst(adapter.getCnst(n))
    {
    }

    z3::expr SimoutAdapter::operator() (bool res) const
    {
        return (r_expr == adapter.ctx().bool_val(res)) && r_cnst;
    }

    z3::expr SimoutAdapter::operator() (const std::string& res) const
    {
        return (r_expr == adapter.ctx().bv_val(res.c_str(), node->type.bitWidth)) 
               && r_cnst;
    }

    z3::expr SimoutAdapter::operator() (const MemValues& mv) const
    {
        return (r_expr == mv.toZ3(adapter.ctx())) && r_cnst;
    }
    // ---------------------------------------------------------------------- //
    Synthesizer::Synthesizer(Abstraction& a)
      : abs(a)
      , MAX_SYN_ITER(200)
      , S(c)
      , c1(c, suffix1)
      , c2(c, suffix2)
      , dtree(NULL)

    {
        z3::params p(c);
        p.set(":unsat-core", true);
        S.set(p);
    }

    Synthesizer::~Synthesizer()
    {
    }

    // ---------------------------------------------------------------------- //
    void Synthesizer::synthesizeAll(PyObject* pyfun)
    {
        for (auto r : abs.regs) {
            const std::string& name(r.first);
            const nptr_t& next(r.second.next);
            if (next == NULL) {
                throw PyILAException(PyExc_RuntimeError,
                            "Next expression not set for " + name);
                return;
            }
        }

        // reset the decode support.
        decodeSupport.vars.clear();
        // and initialize it again.
        for (auto de : abs.decodeExprs) {
            de->depthFirstVisit(decodeSupport);
        }

        for (auto r : abs.regs) {
            const std::string& name(r.first);
            const nptr_t& next(r.second.next);
            // std::cout << "trying to synthesize: " << name
            //           << "; expr: " << *next.get() << std::endl;

            S.push();
            _initSolverAssumptions(abs.assumps, c1, c2);

            for (auto de : abs.decodeExprs) {
                // std::cout << "decode: " << *de.get() << std::endl;

                auto nr = _synthesize(name, de, next, pyfun);
                std::cout << name << ": " 
                          << *de.get() << " -> "
                          << *nr.get() << std::endl;
            }
            S.pop();
        }
    }

    // ---------------------------------------------------------------------- //
    boost::shared_ptr<DistInput> Synthesizer::_getDistInput(z3::expr y)
    {
        using namespace z3;

        expr assumps[1] = { y };
        check_result r = S.check(1, assumps);
        if (r == sat) {
            model m = S.get_model();
            return boost::shared_ptr<DistInput>(new DistInput(abs, c1, m));
        } else {
            return boost::shared_ptr<DistInput>(); // empty //;
        }
    }

    // ---------------------------------------------------------------------- //
    nptr_t Synthesizer::_synthesize(
        const std::string& name,
        const nptr_t& de_expr,
        const nptr_t& ex,
        PyObject* pyfun)
    {
        using namespace py;
        using namespace z3;
        using namespace boost;

        S.push();
        _addExpr(de_expr, c1, c2);
        expr y = _createSynMiter(ex);
        expr syn_assumps[1] = { !y };

        check_result r;
        int i = 0;
        dict args;

        // cegis loop.
        boost::shared_ptr<DistInput> di;
        while ((di = _getDistInput(y)) && (i++ < MAX_SYN_ITER)) {
            // std::cout << "iteration #" << i++ << std::endl;

            // convert to python.
            di->toPython(args);
            // and run python.
            py::dict d = call<py::dict>(pyfun, args);
            py::object r = d[name];
            // extract output.
            SimOutput simout(ex->type, r);

            // now rewrite these expressions.
            Z3ExprRewritingAdapter cr1(c, di.get(), suffix1);
            Z3ExprRewritingAdapter cr2(c, di.get(), suffix2);
            z3::expr er1 = apply_visitor(SimoutAdapter(cr1, ex.get()), simout.out);
            z3::expr er2 = apply_visitor(SimoutAdapter(cr2, ex.get()), simout.out);
            expr es1 = er1.simplify();
            expr es2 = er2.simplify();

            // std::cout << "er1: " << er1 << std::endl;
            // std::cout << "er2: " << er2 << std::endl;
            // std::cout << "es1: " << es1 << std::endl;
            // std::cout << "es2: " << es2 << std::endl;

            std::string n1 = "i"+lexical_cast<std::string>(i)+"a";
            std::string n2 = "i"+lexical_cast<std::string>(i)+"b";
            S.add(es1, n1.c_str());
            S.add(es2, n2.c_str());
        }

        // std::cout << "finished after " << i << " SMT calls." << std::endl;

        r = S.check(1, syn_assumps);
        if (r != sat) {
            std::cout << "unsat core: " << S.unsat_core() << std::endl;
            throw PyILAException(
                PyExc_RuntimeError, 
                "Unable to extract synthesis result after " + 
                lexical_cast<std::string>(i) + " iterations.");
            return NULL;
        }

        model m = S.get_model();
        SynRewriter rw(m, c1);
        nptr_t nr = rw.rewrite(ex.get());
        S.pop();

        return nr;
    }

    nptr_t Synthesizer::_synthesizeEx(
        const std::string& name,
        const nptr_t& de_expr,
        const nptr_t& ex,
        PyObject* pyfun)
    {
        using namespace py;
        using namespace z3;
        using namespace boost;

        S.push();
        _addExpr(de_expr, c1, c2);
        expr y = _createSynMiter(ex);
        expr syn_assumps[1] = { !y };

        check_result r;
        int i = 0;
        dict args;

        // cegis loop.
        boost::shared_ptr<DistInput> di;
        while ((di = _getDistInput(y)) && (i++ < MAX_SYN_ITER)) {
            // std::cout << "iteration #" << i++ << std::endl;

            // convert to python.
            di->toPython(args);
            // and run python.
            py::dict d = call<py::dict>(pyfun, args);
            py::object r = d[name];
            // extract output.
            SimOutput simout(ex->type, r);

            // now rewrite these expressions.
            Z3ExprRewritingAdapter cr1(c, di.get(), suffix1);
            Z3ExprRewritingAdapter cr2(c, di.get(), suffix2);
            z3::expr er1 = apply_visitor(SimoutAdapter(cr1, ex.get()), simout.out);
            z3::expr er2 = apply_visitor(SimoutAdapter(cr2, ex.get()), simout.out);
            expr es1 = er1.simplify();
            expr es2 = er2.simplify();

            // std::cout << "er1: " << er1 << std::endl;
            // std::cout << "er2: " << er2 << std::endl;
            // std::cout << "es1: " << es1 << std::endl;
            // std::cout << "es2: " << es2 << std::endl;

            std::string n1 = "i"+lexical_cast<std::string>(i)+"a";
            std::string n2 = "i"+lexical_cast<std::string>(i)+"b";
            S.add(es1, n1.c_str());
            S.add(es2, n2.c_str());
        }

        // std::cout << "finished after " << i << " SMT calls." << std::endl;

        r = S.check(1, syn_assumps);
        if (r != sat) {
            std::cout << "unsat core: " << S.unsat_core() << std::endl;
            throw PyILAException(
                PyExc_RuntimeError, 
                "Unable to extract synthesis result after " + 
                lexical_cast<std::string>(i) + " iterations.");
            return NULL;
        }

        model m = S.get_model();
        SynRewriter rw(m, c1);
        nptr_t nr = rw.rewrite(ex.get());
        S.pop();

        return nr;
    }
    // ---------------------------------------------------------------------- //
    void Synthesizer::_extractModelValues(
        Z3ExprAdapter& c, z3::model& m, py::dict& d)
    {
        using namespace z3;
        using namespace py;

        for (auto mem: abs.mems) {
            MemValues mv(c, m, dynamic_cast<MemVar*>(mem.second.var.get()));
            d[mem.first] = mv;
        }

        for (auto r : abs.inps) {
            std::string s_e = c.extractNumeralString(m, r.second.var.get());
            d[r.first] = to_pyint(s_e);
        }

        for (auto r : abs.regs) {
            std::string s_e = c.extractNumeralString(m, r.second.var.get());
            d[r.first] = to_pyint(s_e);
        }

        for (auto b : abs.bits) {
            bool b_e = c.getBoolValue(m, b.second.var.get());
            d[b.first] = (int) b_e;
        }
    }

    // ---------------------------------------------------------------------- //
    void Synthesizer::_initSolverAssumptions(
        const nptr_vec_t& all_assumps,
        Z3ExprAdapter& c1,
        Z3ExprAdapter& c2)
    {
        // add all assumptions.
        for ( auto ai : all_assumps )  {
            _addExpr(ai, c1, c2);
        }
    }

    void Synthesizer::_addExpr(
        const nptr_t& ex,
        Z3ExprAdapter& c1,
        Z3ExprAdapter& c2)
    {
        using namespace z3;

        if (ex->hasSynthesisConstructs()) {
            expr aie1 = c1.getExpr(ex.get()).simplify();
            expr aic1 = c1.getCnst(ex.get()).simplify();
            expr aie2 = c2.getExpr(ex.get()).simplify();
            expr aic2 = c2.getCnst(ex.get()).simplify();
            S.add(aie1); S.add(aic1);
            S.add(aie2); S.add(aic2);
        } else {
            expr ei = c1.getExpr(ex.get()).simplify();
            expr ci = c1.getCnst(ex.get()).simplify();
            S.add(ei); S.add(ci);
        }
    }

    z3::expr Synthesizer::_createSynMiter(const nptr_t& ex)
    {
        using namespace z3;

        Node* exn = ex.get();
        // std::cout << "expression: " << *exn << std::endl;

        // create the expressions.
        // std::cout << "dfs done." << std::endl;
        expr ex1 = c1.getExpr(exn).simplify();
        expr cn1 = c1.getCnst(exn).simplify();
        // std::cout << "ex1=" << ex1 << std::endl;
        expr ex2 = c2.getExpr(exn).simplify();
        expr cn2 = c2.getCnst(exn).simplify();
        // std::cout << "ex2=" << ex2 << std::endl;
        std::string miter_name(exn->name + "_miter_output");
        expr y  = c.bool_const(miter_name.c_str());

        // initial constraint.
        S.add((y == (ex1 != ex2)));
        S.add(cn1);
        S.add(cn2);

        return y;
    }

    // ---------------------------------------------------------------------- //
}

