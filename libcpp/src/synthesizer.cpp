#include <synthesizer.hpp>

namespace ila
{
    const char* Synthesizer::suffix1 = ":1";
    const char* Synthesizer::suffix2 = ":2";

    // ---------------------------------------------------------------------- //
    Synthesizer::Synthesizer(Abstraction& a)
      : abs(a)
      , MAX_SYN_ITER(200)
      , S(c)
      , c1(c, suffix1)
      , c2(c, suffix2)

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
    nptr_t Synthesizer::_synthesize(
        const std::string& name,
        const nptr_t& de_expr,
        const nptr_t& ex,
        PyObject* pyfun)
    {
        using namespace py;
        using namespace z3;

        S.push();
        _addExpr(de_expr, c1, c2);

        Node* ex_n = ex.get();
        // std::cout << "expression: " << *ex_n << std::endl;

        // create the expressions.
        // std::cout << "dfs done." << std::endl;
        expr ex1 = c1.getExpr(ex_n).simplify();
        expr cn1 = c1.getCnst(ex_n).simplify();
        // std::cout << "ex1=" << ex1 << std::endl;
        expr ex2 = c2.getExpr(ex_n).simplify();
        expr cn2 = c2.getCnst(ex_n).simplify();
        // std::cout << "ex2=" << ex2 << std::endl;
        std::string mitre_name(ex_n->name + "_mitre_output");
        expr y  = c.bool_const(mitre_name.c_str());

        // initial constraint.
        S.add((y == (ex1 != ex2)));
        S.add(cn1);
        S.add(cn2);

        // std::cout << S << std::endl;

        check_result r;
        int i = 0;
        dict args;

        // cegis loop.
        while (((r = S.check(1, &y)) == sat) && (i++ < MAX_SYN_ITER)) {
            // std::cout << "iteration #" << i++ << std::endl;

            // extract model.
            model m = S.get_model();
            _extractModelValues(c1, m, args);

            // std::cout << "model: " << m << std::endl;

            // run the python code.
            py::dict d = call<py::dict>(pyfun, args);
            py::object r = d[name];

            // now rewrite these expressions.
            Z3ExprRewritingAdapter cr1(c, m, c1, suffix1);
            Z3ExprRewritingAdapter cr2(c, m, c2, suffix2);

            expr er1 = cr1.getIOCnst(ex_n, r);
            expr er2 = cr2.getIOCnst(ex_n, r);

            // std::cout << "er1: " << er1 << std::endl;
            // std::cout << "er2: " << er2 << std::endl;

            expr es1 = er1.simplify();
            expr es2 = er2.simplify();

            // std::cout << "es1: " << es1 << std::endl;
            // std::cout << "es2: " << es2 << std::endl;

            std::string n1 = "i"+boost::lexical_cast<std::string>(i)+"a";
            std::string n2 = "i"+boost::lexical_cast<std::string>(i)+"b";
            S.add(es1, n1.c_str());
            S.add(es2, n2.c_str());
        }

        // std::cout << "finished after " << i << " SMT calls." << std::endl;

        expr ny = !y;
        r = S.check(1, &ny);
        if (r != sat) {
            std::cout << "unsat core: " << S.unsat_core() << std::endl;
            throw PyILAException(
                PyExc_RuntimeError, 
                "Unable to extract synthesis result after " + 
                boost::lexical_cast<std::string>(i) + " iterations.");
            return NULL;
        }

        model m = S.get_model();
        SynRewriter rw(m, c1);
        nptr_t nr = rw.rewrite(ex_n);
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
            std::string s_e = c.extractNumeralString(m, r.get());
            d[r->name] = to_pyint(s_e);
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
    // ---------------------------------------------------------------------- //
}

