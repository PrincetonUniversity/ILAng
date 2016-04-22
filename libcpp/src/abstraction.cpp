#include <abstraction.hpp>
#include <exception.hpp>
#include <smt.hpp>
#include <synthesizer.hpp>
#include <synrewriter.hpp>
#include <util.hpp>

#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>

namespace ila
{
    // ---------------------------------------------------------------------- //
    int Abstraction::getObjId()
    {
        return objCnt++;
    }

    Abstraction::Abstraction()
      : objCnt(0)
      , MAX_SYN_ITER(200)
      , fetchExpr(NULL)
      , fetchValid(new ila::BoolConst(this , true))
      , paramSyn(1)
    {
    }

    Abstraction::~Abstraction()
    {
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::addInp(const std::string& name, int width)
    {
        if(!checkAndInsertName(name)) return NULL;
        NodeRef* n = new NodeRef(new ila::BitvectorVar(this, name, width));
        inps.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::addBit(const std::string& name)
    {
        if(!checkAndInsertName(name)) return NULL;
        NodeRef* n = new NodeRef(new ila::BoolVar(this, name));
        bits.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    NodeRef* Abstraction::addReg(const std::string& name, int width)
    {
        if(!checkAndInsertName(name)) return NULL;
        NodeRef* n = new NodeRef(new ila::BitvectorVar(this, name, width));
        regs.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    NodeRef* Abstraction::addMem(const std::string& name, int aw, int dw)
    {
        if(!checkAndInsertName(name)) return NULL;
        NodeRef* n = new NodeRef(new ila::MemVar(this, name, aw, dw));
        mems.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::setNext(const std::string& name, NodeRef* n)
    {
        // try to find the map we are adding to.
        nmap_t* m = NULL;
        if (n->node->type.isBool()) { m = &bits; }
        else if (n->node->type.isBitvector()) { m = &regs; }
        else if (n->node->type.isMem()) { m = &mems; }
        else {
            throw PyILAException(PyExc_TypeError, 
                "Unexpected type.");
            return;
        }

        // now try to find the variable.
        auto pos = m->find(name);
        if (pos == m->end()) {
            throw PyILAException(PyExc_RuntimeError, 
                "Unable to find var: " + name);
            return;
        }

        // check types.
        if (n->node->type != pos->second.var->type) {
            throw PyILAException(PyExc_TypeError, 
                "Next expression not same type as variable");
        }

        // finally make the assignment.
        pos->second.next = n->node;
    }

    NodeRef* Abstraction::getNext(const std::string& name) const
    {
        // try to find in each of the maps.
        auto pos = bits.find(name);
        if (pos == bits.end()) pos = regs.find(name);
        if (pos == regs.end()) pos = mems.find(name);
        if (pos == mems.end()) {
            throw PyILAException(PyExc_RuntimeError, "Unable to find var: " + name);
            return NULL;
        }
        return new NodeRef(pos->second.next);
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::bvConstLong(py::long_ l_, int w)
    {
        auto l = to_cpp_int(l_);
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

    NodeRef* Abstraction::boolConstL(py::long_ l_)
    {
        auto l = to_cpp_int(l_);
        return new NodeRef(new ila::BoolConst(this, l));
    }

    NodeRef* Abstraction::memConst(const MemValues& mv)
    {
        return new NodeRef(new ila::MemConst(this, mv));
    }


    NodeRef* Abstraction::getFetchExpr() const
    {
        return new NodeRef(fetchExpr);
    }

    void Abstraction::setFetchExpr(NodeRef* fe)
    {
        if (!fe->node->type.isBitvector()) {
            throw PyILAException(
                PyExc_TypeError,
                "Fetch expression must be a bitvector.");
            return;
        }
        fetchExpr = fe->node;
    }

    NodeRef* Abstraction::getFetchValid() const
    {
        return new NodeRef(fetchValid);
    }

    void Abstraction::setFetchValid(NodeRef* fv)
    {
        if (!fv->node->type.isBool()) {
            throw PyILAException(
                PyExc_TypeError,
                "Fetch valid expression must be a boolean.");
        }
        fetchValid = fv->node;
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::setDecodeExpressions(const py::list& l)
    {
        unsigned sz = py::len(l);
        // check size.
        if (sz == 0) {
            throw PyILAException(PyExc_ValueError,
                "Must have at least one decode expression.");
            return;
        }
        // check the decode expresssions.
        for (unsigned i=0; i != sz; i++) {
            py::extract<NodeRef&> ni_(l[i]);
            if (ni_.check()) {
                NodeRef& ni(ni_());
                if (!ni.node->type.isBool()) {
                    throw PyILAException(PyExc_TypeError,
                        "Decode expressions must all be boolean.");
                    return;
                }
            }
        }

        // now stuff them into the vector.
        decodeExprs.clear();
        for (unsigned i=0; i != sz; i++) {
            py::extract<NodeRef&> ni_(l[i]);
            ILA_ASSERT (ni_.check(), "Must be a boolean.");
            NodeRef& ni(ni_());
            decodeExprs.push_back(ni.node);
        }
    }

    py::list Abstraction::getDecodeExpressions() const
    {
        py::list l;
        for ( auto de : decodeExprs ) {
            NodeRef* nr = new NodeRef(de);
            l.append(nr);
        }
        return l;
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::addAssumption(NodeRef* expr)
    {
        if (!expr->node->type.isBool()) {
            throw PyILAException(PyExc_TypeError,
                "Assumption must be a boolean.");
            return;
        }
        assumps.push_back(expr->node);
    }

    py::list Abstraction::getAllAssumptions() const
    {
        py::list l;
        for (auto assump : assumps) {
            NodeRef* nr = new NodeRef(assump);
            l.append(nr);
        }
        return l;
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::synthesizeAll(PyObject* pyfun)
    {
        Synthesizer syn(*this);
        syn.synthesizeAll(pyfun);
    }

    void Abstraction::synthesizeReg(
        const std::string& name, PyObject* pyfun)
    {
        Synthesizer syn(*this);
        syn.synthesizeReg(name, pyfun);
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::synthesizeElement(
        const std::string& name, 
        NodeRef* ex, PyObject* pyfun)
    {
        auto nr = _synthesize(name, assumps, ex->node, pyfun);
        return new NodeRef(nr);
    }

    void Abstraction::extractModelValues(
        Z3ExprAdapter& c, z3::model& m, py::dict& d)
    {
        using namespace z3;
        using namespace py;

        for (auto mem: mems) {
            MemValues mv(c, m, dynamic_cast<MemVar*>(mem.second.var.get()));
            d[mem.first] = mv;
        }

        for (auto r : inps) {
            std::string s_e = c.extractNumeralString(m, r.second.var.get());
            d[r.first] = to_pyint(s_e);
        }

        for (auto r : regs) {
            std::string s_e = c.extractNumeralString(m, r.second.var.get());
            d[r.first] = to_pyint(s_e);
        }

        for (auto b : bits) {
            bool b_e = c.getBoolValue(m, b.second.var.get());
            d[b.first] = (int) b_e;
        }
    }

    bool Abstraction::areEqual(NodeRef* left, NodeRef* right) const
    {
        using namespace z3;

        if (left->node->type != right->node->type) {
            throw PyILAException(PyExc_TypeError,
                "Types do not match.");
            return false;
        }

        context c_;
        Z3ExprAdapter c(c_, "");

        // std::cout << "left: " << *left->node.get() << std::endl;
        z3::expr ex1 = c.getExpr(left->node.get());
        z3::expr cn1 = c.getCnst(left->node.get());
        //std::cout << "ex1:" << ex1 << std::endl;

        // std::cout << "right: " << *right->node.get() << std::endl;
        z3::expr ex2 = c.getExpr(right->node.get());
        z3::expr cn2 = c.getCnst(right->node.get());
        //std::cout << "ex2:" << ex2 << std::endl;

        expr mitre = (ex1 != ex2);
        //std::cout << "mitre:" << mitre << std::endl;


        solver S(c_);
        S.add(mitre);
        S.add(cn1);
        S.add(cn2);
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

    // ---------------------------------------------------------------------- //
    void Abstraction::exportOneToFile(NodeRef* node,
                                      const std::string& fileName) const
    {
        std::ofstream out(fileName.c_str());
        ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");
        ImExport expt;

        expt.exportAst(out, node->node.get());
        out.close();
    }

    void Abstraction::exportAllToFile(const std::string& fileName) const
    {
        std::ofstream out(fileName.c_str());
        ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");
        ImExport expt;

        // names.
        out << ".names: ";
        for (std::set<std::string>::const_iterator it = names.begin();
             it != names.end(); it++) {
            out << " " << *it;
        }
        out << " .names_end\n";

        // inputs.
        out << ".inps: ";
        for (nmap_t::const_iterator it = inps.begin();
             it != inps.end(); it++) {
            out << " " << it->first << " ";
            expt.exportAst(out, it->second.var.get());
            out << " ";
            expt.exportAst(out, it->second.next.get());
        }
        out << " .inps_end\n";

        // registers.
        out << ".regs: ";
        for (nmap_t::const_iterator it = regs.begin();
             it != regs.end(); it++) {
            out << "\n" << it->first << " ";
            expt.exportAst(out, it->second.var.get());
            out << " ";
            expt.exportAst(out, it->second.next.get());
        }
        out << "\n.regs_end\n";

        // bits.
        out << ".bits: ";
        for (nmap_t::const_iterator it = bits.begin();
             it != bits.end(); it++) {
            out << "\n" << it->first << " ";
            expt.exportAst(out, it->second.var.get());
            out << " ";
            expt.exportAst(out, it->second.next.get());
        }
        out << "\n.bits_end\n";

        // mems.
        out << ".mems: ";
        for (nmap_t::const_iterator it = mems.begin();
             it != mems.end(); it++) {
            out << "\n" << it->first << " ";
            expt.exportAst(out, it->second.var.get());
            out << " ";
            expt.exportAst(out, it->second.next.get());
        }
        out << "\n.mems_end\n";

        // fetchExpr.
        out << ".fetchExpr: ";
        expt.exportAst(out, fetchExpr.get());
        out << "\n";

        // fetchValid.
        out << ".fetchValid: ";
        expt.exportAst(out, fetchValid.get());
        out << "\n";

        // decodeExpr.
        out << ".decode: ";
        for (unsigned i = 0; i != decodeExprs.size(); i++) {
            out << "\n" << i << " ";
            expt.exportAst(out, decodeExprs[i].get());
        }
        out << "\n.decode_end\n";

        // assumps.
        out << ".assumps: ";
        for (unsigned i = 0; i != assumps.size(); i++) {
            out << "\n";
            expt.exportAst(out, assumps[i].get());
        }
        out << "\n.assumps_end\n";

        out.close();
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::importOneFromFile(const std::string& fileName)
    {
        std::ifstream in;
        in.open(fileName.c_str());
        ILA_ASSERT(in.is_open(), "File " + fileName + " not found.");

        ImExport ipt;
        nptr_t res = ipt.importAst(this, in);
        NodeRef* wrap = new NodeRef(res);
        in.close();
        return wrap;
    }

    void Abstraction::importAllFromFile(const std::string& fileName) 
    {
        std::ifstream in;
        in.open(fileName.c_str());
        ILA_ASSERT(in.is_open(), "File " + fileName + " not found.");

        // Clear all variables.
        names.clear();
        inps.clear();
        regs.clear();
        bits.clear();
        mems.clear();
        fetchExpr = NULL;
        fetchValid = NULL;
        decodeExprs.clear();
        assumps.clear();

        ImExport ipt;

        std::string buf;
        in >> buf;

        // names.
        ILA_ASSERT(buf == ".names:", "Expect .names section");
        in >> buf;
        while (buf != ".names_end") {
            checkAndInsertName(buf);
            in >> buf;
        }

        // inputs.
        in >> buf;
        ILA_ASSERT(buf == ".inps:", "Expect .inps section");
        in >> buf;
        while (buf != ".inps_end") {
            nptr_t var = ipt.importAst(this, in);
            nptr_t next = ipt.importAst(this, in);
            inps.insert({buf, npair_t(var, next)});
            in >> buf;
        }

        // registers.
        in >> buf;
        ILA_ASSERT(buf == ".regs:", "Expect .regs section");
        in >> buf;
        while (buf != ".regs_end") {
            nptr_t var = ipt.importAst(this, in);
            nptr_t next = ipt.importAst(this, in);
            regs.insert({buf, npair_t(var, next)});
            in >> buf;
        }

        // bits.
        in >> buf;
        ILA_ASSERT(buf == ".bits:", "Expect .bits section");
        in >> buf;
        while (buf != ".bits_end") {
            nptr_t var = ipt.importAst(this, in);
            nptr_t next = ipt.importAst(this, in);
            bits.insert({buf, npair_t(var, next)});
            in >> buf;
        }

        // mems.
        in >> buf;
        ILA_ASSERT(buf == ".mems:", "Expect .mems section");
        in >> buf;
        while (buf != ".mems_end") {
            nptr_t var = ipt.importAst(this, in);
            nptr_t next = ipt.importAst(this, in);
            mems.insert({buf, npair_t(var, next)});
            in >> buf;
        }

        // fetchExpr.
        in >> buf;
        ILA_ASSERT(buf == ".fetchExpr:", "Expect .fetchExpr section");
        fetchExpr = ipt.importAst(this, in);

        // fetchValid.
        in >> buf;
        ILA_ASSERT(buf == ".fetchValid:", "Expect .fetchValid section");
        fetchValid = ipt.importAst(this, in);
        
        // decode.
        in >> buf;
        ILA_ASSERT(buf == ".decode:", "Expect .decode section");
        in >> buf;
        while (buf != ".decode_end") {
            nptr_t dec = ipt.importAst(this, in);
            decodeExprs.push_back(dec);
            in >> buf;
        }

        // assumptions.
        in >> buf;
        ILA_ASSERT(buf == ".assumps:", "Expect .assumps section");
        in >> buf;
        while (buf != ".assumps_end") {
            nptr_t ass = ipt.importAst(this, in);
            assumps.push_back(ass);
            in >> buf;
        }

    }

    void Abstraction::generateSim(const std::string& fileName) const
    {
        // TODO
        CppSimGen* gen = new CppSimGen("bal");
        for (auto it = inps.begin(); it != inps.end(); it++) {
            gen->addInput(it->first, it->second.var);
        }
        for (auto it = regs.begin(); it != regs.end(); it++) {
            gen->addState(it->first, it->second.var);
        }
        for (auto it = bits.begin(); it != bits.end(); it++) {
            gen->addState(it->first, it->second.var);
        }
    }

    // ---------------------------------------------------------------------- //
    nptr_t Abstraction::_synthesize(
        const std::string& name,
        const nptr_vec_t& all_assumps,
        const nptr_t& ex,
        PyObject* pyfun)
    {
        using namespace py;
        using namespace z3;

        static const char* suffix1 = ":1";
        static const char* suffix2 = ":2";

        Node* ex_n = ex.get();

        // std::cout << "expression: " << *ex_n << std::endl;

        // create the context and solver.
        context c_;
        solver S(c_);
        // set params.
        params p(c_);
        p.set(":unsat-core", true);
        S.set(p);

        // create the expressions.
        Z3ExprAdapter c1(c_, suffix1);
        Z3ExprAdapter c2(c_, suffix2);
        // std::cout << "dfs done." << std::endl;
        expr ex1 = c1.getExpr(ex_n).simplify();
        expr cn1 = c1.getCnst(ex_n).simplify();
        // std::cout << "ex1=" << ex1 << std::endl;
        expr ex2 = c2.getExpr(ex_n).simplify();
        expr cn2 = c2.getCnst(ex_n).simplify();
        // std::cout << "ex2=" << ex2 << std::endl;
        expr y  = c_.bool_const("_mitre.output");

        // add all assumptions.
        for ( auto ai : all_assumps )  {
            if (ai->hasSynthesisConstructs()) {
                expr aie1 = c1.getExpr(ai.get()).simplify();
                expr aic1 = c1.getCnst(ai.get()).simplify();
                expr aie2 = c2.getExpr(ai.get()).simplify();
                expr aic2 = c2.getCnst(ai.get()).simplify();
                S.add(aie1); S.add(aic1);
                S.add(aie2); S.add(aic2);
            } else {
                expr ei = c1.getExpr(ai.get()).simplify();
                expr ci = c1.getCnst(ai.get()).simplify();
                S.add(ei); S.add(ci);
            }
        }

        // initial constraint.
        S.add((y == (ex1 != ex2)));
        S.add(cn1);
        S.add(cn2);

        // std::cout << S << std::endl;

        check_result r;
        int i = 0;
        dict args;

        SupportVars sv;

        // cegis loop.
        while (((r = S.check(1, &y)) == sat) && (i++ < MAX_SYN_ITER)) {
            // std::cout << "iteration #" << i++ << std::endl;

            // extract model.
            model m = S.get_model();
            DistInput di(*this, c1, m, sv);
            di.toPython(args);

            // std::cout << "model: " << m << std::endl;

            // run the python code.
            py::dict d = call<py::dict>(pyfun, args);
            py::object r = d[name];

            // now rewrite these expressions.
            Z3ExprRewritingAdapter cr1(c_, &di, suffix1);
            Z3ExprRewritingAdapter cr2(c_, &di, suffix2);

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
        return nr;
    }
    // ---------------------------------------------------------------------- //
    bool Abstraction::checkAndInsertName(const std::string& name)
    {
        if (names.find(name) != names.end()) {
            throw PyILAException(PyExc_RuntimeError,
                "Variable with this name already exists.");
            return false;
        }
        return true;
    }
}
