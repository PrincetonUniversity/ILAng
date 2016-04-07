#include <abstraction.hpp>
#include <exception.hpp>
#include <smt.hpp>
#include <syn.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    int Abstraction::getObjId()
    {
        return objCnt++;
    }

    Abstraction::Abstraction()
      : objCnt(0)
    {
    }

    Abstraction::~Abstraction()
    {
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::addReg(const std::string& name, int width)
    {
        NodeRef* n = new NodeRef(new ila::BitvectorVar(this, name, width));
        regs.push_back(n->node);
        return n;
    }

    NodeRef* Abstraction::addBit(const std::string& name)
    {
        NodeRef* n = new NodeRef(new ila::BoolVar(this, name));
        bits.push_back(n->node);
        return n;
    }

    NodeRef* Abstraction::bvConstLong(boost::python::long_ l, int w)
    {
        return new NodeRef(new ila::BitvectorConst(this, l, w));
    }

    NodeRef* Abstraction::bvConstInt(int l, int w)
    {
        return new NodeRef(new ila::BitvectorConst(this, l, w));
    }

    NodeRef* Abstraction::boolConstB(bool b)
    {
        return new NodeRef(new ila::BoolConst(this, b));
    }

    NodeRef* Abstraction::boolConstI(int b)
    {
        return new NodeRef(new ila::BoolConst(this, b));
    }

    NodeRef* Abstraction::boolConstL(boost::python::long_ l)
    {
        return new NodeRef(new ila::BoolConst(this, l));
    }

    NodeRef* Abstraction::choice2(
        const std::string& name,
        NodeRef* e1, NodeRef* e2)
    {
        std::vector< boost::shared_ptr<Node> > args = { 
            e1->node,
            e2->node
        };
        NodeType t = Choice::getChoiceType(args);
        if (!t) {
            throw PyILAException(
                PyExc_TypeError,
                "Type error in choice arguments.");
            return NULL;
        } else {
            if (t.isBool()) {
                return new NodeRef(
                            new BoolChoice(this, name, args));
            } else if (t.isBitvector()) {
                return new NodeRef(
                            new BitvectorChoice(this, name, args));
            } else {
                throw PyILAException(
                    PyExc_ValueError,
                    "Unable to create choice of specified type.");
                return NULL;
            }
        }
    }


    NodeRef* Abstraction::synthesize(NodeRef* ex, PyObject* pyfun)
    {
        using namespace boost::python;
        using namespace z3;

        static const char* suffix1 = ":1";
        static const char* suffix2 = ":2";

        Node* ex_n = ex->node.get();

        // std::cout << "expression: " << *ex_n << std::endl;

        // create the expressions.
        context c_;
        Z3ExprAdapter c1(c_, suffix1);
        Z3ExprAdapter c2(c_, suffix2);
        std::cout << "dfs done." << std::endl;
        expr e1 = c1.getExpr(ex_n);
        std::cout << "e1=" << e1 << std::endl;
        expr e2 = c2.getExpr(ex_n);
        std::cout << "e2=" << e2 << std::endl;
        expr y  = c_.bool_const("_mitre.output");

        // solver.
        solver S(c_);

        // initial constraint.
        S.add((y == (e1 != e2)));

        std::cout << S << std::endl;

        check_result r;
        int i = 1;
        dict args;

        // cegis loop.
        while ((r = S.check(1, &y)) == sat) {
            std::cout << "iteration #" << i++ << std::endl;

            // extract model.
            model m = S.get_model();
            extractModelValues(c1, m, args);

            std::cout << "model: " << m << std::endl;

            // run the python code.
            boost::python::object result = 
                call<boost::python::object, dict>(pyfun, args);

            // now rewrite these expressions.
            Z3ExprRewritingAdapter cr1(c_, m, c1, suffix1);
            Z3ExprRewritingAdapter cr2(c_, m, c2, suffix2);

            expr er1 = cr1.getExpr(ex_n, result);
            expr er2 = cr2.getExpr(ex_n, result);

            std::cout << "er1: " << er1 << std::endl;
            std::cout << "er2: " << er2 << std::endl;

            S.add(er1);
            S.add(er2);
        }

        std::cout << "finished after " << i << " SMT calls." << std::endl;

        expr ny = !y;
        r = S.check(1, &ny);
        ILA_ASSERT(r == sat, "Unable to extract synthesis result.");

        model m = S.get_model();
        SynRewriter rw(m, c1);
        boost::shared_ptr<Node> nr = rw.rewrite(ex_n);
        std::cout << "synthesis result: " << *nr.get() << std::endl;
        return new NodeRef(nr);
    }

    void Abstraction::extractModelValues(Z3ExprAdapter& c, z3::model& m, boost::python::dict& d)
    {
        using namespace z3;
        using namespace boost::python;

        for (auto r : regs) {
            // extract int from z3.
            std::string s_e = c.extractNumeralString(m, r.get());
            // dump output.
            std::cout << r->name << "=" << s_e << std::endl;
            // convert to python.
            PyObject* l_e = PyLong_FromString((char*) s_e.c_str(), NULL, 0);
            boost::python::object o_e(handle<>(borrowed(l_e)));
            d[r->name] = o_e;
        }

        for (auto b : bits) {
            bool b_e = c.getBoolValue(m, b.get());
            std::cout << b->name << "=" << b_e << std::endl;
            d[b->name] = (int) b_e;
        }
    }

    bool Abstraction::areEqual(NodeRef* left, NodeRef* right) const
    {
        using namespace z3;

        context c_;
        Z3ExprAdapter c(c_, "");

        // std::cout << "left: " << *left->node.get() << std::endl;
        z3::expr e1 = c.getExpr(left->node.get());
        //std::cout << "e1:" << e1 << std::endl;

        // std::cout << "right: " << *right->node.get() << std::endl;
        z3::expr e2 = c.getExpr(right->node.get());
        //std::cout << "e2:" << e2 << std::endl;

        expr mitre = (e1 != e2);
        //std::cout << "mitre:" << mitre << std::endl;


        solver S(c_);
        S.add(mitre);
        auto r = S.check();
        if (r == sat) {
            return false;
        } else if (r == unsat) {
            return true;
        } else {
            throw PyILAException(PyExc_RuntimeError, "Indeterminate result from Z3.");
            return false;
        }
    }
}
