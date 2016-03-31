#include <abstraction.hpp>
#include <exception.hpp>
#include <smt.hpp>

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
            return new NodeRef(
                        new BitvectorChoice(this, name, args));
        }
    }


    void Abstraction::synthesize(NodeRef* ex, PyObject* pyfun)
    {
        using namespace boost::python;
        using namespace z3;

        context c_;
        Z3Adapter c1(c_, ":1");
        Z3Adapter c2(c_, ":2");

        expr e1 = c1.expr(ex->node.get());
        expr e2 = c2.expr(ex->node.get());
        expr y  = c_.bool_const("_mitre.output");

        solver S(c_);
        S.add((y == (e1 != e2)));

        std::cout << S << std::endl;

        check_result r;
        int i = 1;
        dict args;

        while ((r = S.check(1, &y)) == sat) {
            std::cout << "iterator #" << i++ << std::endl;
            model m = S.get_model();
            extractModelValues(c1, m, args);
            break;
        }
        std::cout << "i=" << i << std::endl;
        
        args["arg"] = 1;

        boost::python::object result = 
            call<boost::python::object, dict>(pyfun, args);
        extract<dict> res(result);

        if (res.check()) {
            int result = extract<int>(res()["arg"]);
            std::cout << "result=" << result << std::endl;
        } else {
            std::cout << "got nonsense." << std::endl;
        }
    }

    void Abstraction::extractModelValues(Z3AdapterI& c, z3::model& m, boost::python::dict& d)
    {
        using namespace z3;
        for (auto r : regs) {
            using namespace boost::python;

            // extract int from z3.
            std::string s_e = c.extractNumeralString(m, r);

            // dump output.
            std::cout << r->name << "=" << s_e << std::endl;

            // convert to python.
            PyObject* l_e = PyLong_FromString((char*) s_e.c_str(), NULL, 0);
            boost::python::object o_e(handle<>(borrowed(l_e)));
            d[r->name] = o_e;
        }
    }

    bool Abstraction::areEqual(NodeRef* left, NodeRef* right) const
    {
        using namespace z3;

        context c_;
        Z3Adapter c(c_, "");

        //left->node->write(std::cout << "left: ") << std::endl;
        //right->node->write(std::cout << "right: ") << std::endl;

        expr e1 = c.expr(left->node.get());
        //std::cout << "e1:" << e1 << std::endl;
        expr e2 = c.expr(right->node.get());
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
