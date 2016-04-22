#include <synthesizer.hpp>
#include <exception.hpp>
#include <util.hpp>
#include <rewriter.hpp>

namespace ila
{
    const char* Synthesizer::suffix1 = ":1";
    const char* Synthesizer::suffix2 = ":2";

    // ---------------------------------------------------------------------- //
    void SupportVars::operator() (const Node* n)
    {
        const BoolVar* boolvar = NULL; 
        const BitvectorVar* bvvar = NULL;
        const BitvectorOp* bvop = NULL;

        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            bools.insert(boolvar);
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            bitvecs.insert(bvvar);
        } else if((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            if (bvop->getOp() == BitvectorOp::READMEM) {
                const MemExpr* memexp = (const MemExpr*) bvop->arg(0).get();
                const BitvectorExpr* addr = (const BitvectorExpr*) bvop->arg(1).get();
                const MemVar* memvar = dynamic_cast<const MemVar*>(memexp);
                if (memvar) {
                    rdexprs.push_back({memvar, addr, bvop});
                } else {
                    canFixUp = false;
                }
            }
        }
    }

    void SupportVars::clear()
    {
        bools.clear();
        bitvecs.clear();
        rdexprs.clear();
    }

    void SupportVars::uniquifyRdExprs()
    {
        std::vector<mem_info_t> rdexprs2;
        for (auto&& rd : rdexprs) {
            if (rdexprs2.size() == 0) {
                rdexprs2.push_back(rd);
            } else {
                bool found = false;
                for (auto& it : rdexprs2) {
                    if (it == rd) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    rdexprs2.push_back(rd);
                }
            }
        }
        rdexprs.clear();
        std::copy(rdexprs2.begin(), rdexprs2.end(), std::back_inserter(rdexprs));
    }

    bool SupportVars::depCheck(z3::context& c, z3::solver& S, const nptr_t& ex)
    {
        // first rewrite.
        Rewriter r1, r2;
        for (auto b : bools) {
            r1.addRewrite(b, nptr_t(new BoolVar(b->context(), b->name+"__1")));
            r2.addRewrite(b, nptr_t(new BoolVar(b->context(), b->name+"__2")));
        }
        for (auto bv : bitvecs) {
            r1.addRewrite(bv, nptr_t(new BitvectorVar(
                bv->context(), "$" + bv->name+"__1", bv->type.bitWidth)));
            r2.addRewrite(bv, nptr_t(new BitvectorVar(
                bv->context(), "$" + bv->name+"__2", bv->type.bitWidth)));
        }
        for (auto&& mi : rdexprs) {
            r1.addRewrite(mi.rddata, nptr_t(new BitvectorVar(
                mi.rddata->context(), mi.rddata->name+"__1", 
                mi.rddata->type.bitWidth)));
            r2.addRewrite(mi.rddata, nptr_t(new BitvectorVar(
                mi.rddata->context(), mi.rddata->name+"__2", 
                mi.rddata->type.bitWidth)));
        }
        auto rwex1 = r1.rewrite(ex.get());
        auto rwex2 = r2.rewrite(ex.get());

        // now check using smt.
        Z3ExprAdapter adapter(c, "");
        auto expr1 = adapter.getExpr(rwex1.get());
        auto expr2 = adapter.getExpr(rwex2.get());
        S.push();
        S.add(expr1 != expr2);
        z3::check_result r = S.check();
        S.pop();
        bool dep = (r != z3::unsat);
        //std::cout << "dependency exists: " << (int) dep << std::endl;
        return dep;
    }

    // ---------------------------------------------------------------------- //
    DistInput::DistInput(
        Abstraction& abs, Z3ExprAdapter& c, z3::model& m, SupportVars& sv)
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

        for (auto&& rd : sv.rdexprs) {
            rdaddrs.push_back(c.extractNumeralString(m, rd.addr));
        }
    }

    void DistInput::fixUp(SupportVars& s, Z3ExprAdapter& c, z3::model& m)
    {
        // fixup bitvecors.
        for (auto bv : s.bitvecs) {
            const std::string& name = bv->name;
            std::string value = c.extractNumeralString(m, bv);
            bitvecs[name] = value;
        }

        // and booleans.
        for (auto bv : s.bools) {
            const std::string& name = bv->name;
            bool value = c.getBoolValue(m, bv);
            bools[name] = value;
        }

        // fixup memories
        int i = 0; 
        for (auto&& rdex : s.rdexprs) {
            auto pos = mems.find(rdex.mem->name);
            ILA_ASSERT(pos != mems.end(), 
                "Can't find memory: " + rdex.mem->name);
            MemValues& thismem (pos->second);

            MemValues mv(c, m, rdex.mem);
            std::string addr_s = c.extractNumeralString(m, rdex.addr);
            mp_int_t addr_that = boost::lexical_cast<mp_int_t>(rdaddrs[i]);
            mp_int_t addr_this = boost::lexical_cast<mp_int_t>(addr_s);
            mp_int_t data = mv.getItemInt(addr_that);
            // get the address from the "saved" model.
#ifdef DEBUG
            std::cout << "addr_that: " << addr_that 
                      << "; addr_this: " << addr_this
                      << "; data: " << data
                      << std::endl;
#endif
            thismem.values[addr_this] = data;
            i++;
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

    std::ostream& operator<<(std::ostream& out, const DistInput& di)
    {
        for (auto mem : di.mems) {
            out << mem.first << ": " << mem.second << "; ";
        }

        for (auto bv : di.bitvecs) {
            out << bv.first << ": " << bv.second << "; ";
        }

        for (auto b : di.bools) {
            out << b.first << ": " << (int) b.second << "; ";
        }

        out << "[ ";
        for (auto s : di.rdaddrs) {
            out << s << " ";
        }
        out << "]";
        return out;
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

    std::ostream& operator<<(std::ostream& out, const SimOutput& simout)
    {
        int which = simout.out.which();
        if (which == 0) {
            const MemValues& mv = boost::get<const MemValues&>(simout.out);
            return out << mv;
        } else if (which == 1) {
            const std::string& s = boost::get<const std::string&>(simout.out);
            return out << s;
        } else if (which == 2) {
            bool b = boost::get<bool>(simout.out);
            return out << (int)b;
        } else {
            ILA_ASSERT(false, "Unexpected which value in simout.");
            return out;
        }
    }

    // ---------------------------------------------------------------------- //

    DITreeNode::DITreeNode(
        Abstraction& a, Z3ExprAdapter& c, z3::model& m, SupportVars& sv)
      : inputs(new DistInput(a, c, m, sv))
      , result(NULL)
    {
    }

    DITreeNode::DITreeNode()
      : inputs(NULL)
      , result(NULL)
    {
    }

    DITreeNode::~DITreeNode()
    {
        outputs.clear();
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
    DITree::DITree(Synthesizer& s)
      : syn(s)
    {
        reset(false);
    }

    void DITree::reset(bool rm)
    {
      reuseModels = rm;
      // empty the tree.
      head.reset();
      // we don't have anything to reply.
      replay_ptr.reset();
      // we will insert at the head.
      insert_ptr = &head;
      // we will start in insert mode.
      mode = INSERT;
    }

    void DITree::rewind()
    {
        if (!(bool)head) {
            // if the tree is empty then we just reset.
            reset(reuseModels);
        } else {
            // else start in replay mode.
            mode = REPLAY;
            // replay points to the head.
            replay_ptr = head;
            // we don't have anyplace to insert yet.
            insert_ptr = NULL;
        }
    }

    DistInput* DITree::getDistInput(const z3::expr& y)
    {
        if (mode == INSERT) {
            // std::cout << "getDI: INSERT mode." << std::endl;

            // run the SMT solver.
            z3::expr assumps[1] = { y };
            z3::check_result r = syn.S.check(1, assumps);
            if (r == z3::sat) {
                // extract model.
                z3::model m = syn.S.get_model();
                // insert into the tree.
                dtree_ptr_t dnode(new DITreeNode(
                    syn.abs, syn.c1, m, syn.decodeSupport));
                *insert_ptr = dnode;
                // std::cout << "getDI: DI: " << *dnode->inputs << std::endl;
                return dnode->inputs.get();
            } else {
                // tree is empty.
                // std::cout << "getDI: No more DIs." << std::endl;
                if (reuseModels) {
                    dtree_ptr_t dnode(new DITreeNode());
                    *insert_ptr = dnode;
                }
                return NULL;
            }
        } else {
            // std::cout << "getDI: REPLAY mode." << std::endl;
            DistInput* di = replay_ptr->inputs.get();
            if (di != NULL) {
                z3::check_result r = syn.Sp.check();
                ILA_ASSERT(r == z3::sat, "Expected this to be SAT.");
                z3::model m = syn.Sp.get_model();
                // std::cout << "getDI: prefixUp DI: " << *di << std::endl;
                di->fixUp(syn.decodeSupport, syn.c1, m);
                // std::cout << "getDI: DI: " << *di << std::endl;
            } else {
                // std::cout << "getDI: end of trail." << std::endl;
            }
            return di;
        }
    }

    void DITree::setOutput(const simout_ptr_t& out)
    {
        if (mode == REPLAY) {
            // std::cout << "setOut: REPLAY mode." << std::endl;
            // std::cout << "setOut: out=" << *out << std::endl;

            bool found = false;
            // try to find an existing output which matches.
            for (unsigned i=0; i != replay_ptr->outputs.size(); i++) {
                if (*replay_ptr->outputs[i].first == *out) {
                    found = true;
                    // std::cout << "setOut: found output match." << std::endl;
                    replay_ptr = replay_ptr->outputs[i].second;
                    break;
                }
            }
            if (!found) {
                // not found, so switch to insert mode.
                mode = INSERT;
                // std::cout << "setOut: switch to insert mode as output not found." 
                //           << std::endl;
                int index = replay_ptr->outputs.size();
                replay_ptr->outputs.push_back({out, dtree_ptr_t()});
                insert_ptr = &replay_ptr->outputs[index].second;
                replay_ptr.reset();
            } else if (!(bool)replay_ptr) {
                ILA_ASSERT(!reuseModels, 
                    "reuseModels must be false if we got here.");
                // std::cout << "setOut: switch to insert mode at end of trail." 
                //          << std::endl;

                mode = INSERT;
                insert_ptr = &replay_ptr;
                replay_ptr.reset();
            }
        } else {
            // std::cout << "setOut: INSERT mode." << std::endl;
            // std::cout << "setOut: out=" << *out << std::endl;

            // now we are in INSERT mode.
            ILA_ASSERT ((*insert_ptr)->outputs.size() == 0, 
                        "insert_ptr can't have child nodes.");
            (*insert_ptr)->outputs.push_back({out, dtree_ptr_t()});
            insert_ptr = &(*insert_ptr)->outputs[0].second;
        }
    }

    nptr_t DITree::getExpr(const z3::expr& y, const nptr_t& ex, int i)
    {
        using namespace z3;
        if (mode == INSERT || !reuseModels) {
            expr assumps[1] = { !y };
            check_result r = syn.S.check(1, assumps);
            if (r != sat) {
                std::ostringstream uout;
                uout << "Unable to extract synthesis result. Unsat core: "
                     << syn.S.unsat_core() << "; iterations: " << i;
                throw PyILAException(PyExc_RuntimeError, uout.str());
                return nptr_t(NULL);
            }

            model m = syn.S.get_model();
            SynRewriter rw(m, syn.c1);
            nptr_t syn_expr = rw.rewrite(ex.get());
            if (reuseModels) {
                (*insert_ptr)->result = syn_expr;
            }
            return syn_expr;
        } else {
            return replay_ptr->result;
        }
    }

    // ---------------------------------------------------------------------- //
    Synthesizer::Synthesizer(Abstraction& a)
      : abs(a)
      , MAX_SYN_ITER(200)
      , S(c)
      , Sp(c)
      , c1(c, suffix1)
      , c2(c, suffix2)
      , ditree(*this)

    {
        z3::params p(c);
        p.set(":unsat-core", true);
        S.set(p);
    }

    Synthesizer::~Synthesizer()
    {
    }

    void Synthesizer::_initSynthesis()
    {
        // reset the decode support.
        decodeSupport.clear();
        // and initialize it again.
        for (auto de : abs.decodeExprs) {
            de->depthFirstVisit(decodeSupport);
        }
        decodeSupport.uniquifyRdExprs();

    }

    nptr_t Synthesizer::_synthesizeOp(
        const std::string& name,
        const nptr_t& var, 
        const nptr_t& next,
        PyObject* pyfun)
    {
        nptr_t ex = var;
        bool nodep = !decodeSupport.depCheck(c, Sp, next);
        ditree.reset(nodep);
        for (auto de : abs.decodeExprs) {
            std::cout << "decode: " << *de.get() << std::endl;
            ditree.rewind();
            nptr_t ex_n = (abs.paramSyn && decodeSupport.canFixUp)
                ? _synthesizeEx(name, de, next, pyfun)
                : _synthesize(name, de, next, pyfun);

            // create the final expression.
            nptr_t ex_p = Node::ite(de, ex_n, ex);
            ex = ex_p;

            std::cout << name << ": " 
                      << *de.get() << " -> "
                      << *ex_n.get() << std::endl;
        }
        std::cout << name << ": "
                  << *ex.get() << std::endl;
        return ex;
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

        _initSynthesis();
        S.push(); Sp.push();
        _initSolverAssumptions(abs.assumps, c1, c2);
        for (auto&& r : abs.regs) {
            r.second.next = _synthesizeOp(
                r.first, r.second.var, r.second.next, pyfun);
        }
        S.pop(); Sp.pop();
    }

    void Synthesizer::synthesizeReg(const std::string& name, PyObject* pyfun)
    {
        auto pos = abs.regs.find(name);
        if (pos == abs.regs.end()) {
            pos = abs.mems.find(name);
        }
        if (pos == abs.mems.end()) {
            pos = abs.bits.find(name);
        }
        if (pos == abs.bits.end()) {
            throw PyILAException(PyExc_RuntimeError,
                "Unable to find name: " + name);
            return;
        }
        _initSynthesis();
        S.push(); Sp.push();
        _initSolverAssumptions(abs.assumps, c1, c2);
        pos->second.next = _synthesizeOp(
                pos->first, 
                pos->second.var, 
                pos->second.next, 
                pyfun);
        S.pop(); Sp.pop();
    }

    // ---------------------------------------------------------------------- //
    std::unique_ptr<DistInput> Synthesizer::_getDistInput(z3::expr y)
    {
        using namespace z3;

        expr assumps[1] = { y };
        check_result r = S.check(1, assumps);
        if (r == sat) {
            model m = S.get_model();
            return std::unique_ptr<DistInput>(
                new DistInput(abs, c1, m, decodeSupport));
        } else {
            return std::unique_ptr<DistInput>(); // empty //;
        }
    }

    // ---------------------------------------------------------------------- //
    nptr_t Synthesizer::_synthesize(
        const std::string& name,
        const nptr_t& de_expr,
        const nptr_t& ex,
        PyObject* pyfun)
    {
        // std::cout << "synthesize" << std::endl;

        using namespace py;
        using namespace z3;
        using namespace boost;

        S.push(); Sp.push();
        _addExpr(de_expr, c1, c2);
        expr y = _createSynMiter(ex);

        int i = 0;
        dict args;
        std::unique_ptr<DistInput> di;
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

        expr syn_assumps[1] = { !y };
        check_result r = S.check(1, syn_assumps);
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
        S.pop(); Sp.pop();

        return nr;
    }

    nptr_t Synthesizer::_synthesizeEx(
        const std::string& name,
        const nptr_t& de_expr,
        const nptr_t& ex,
        PyObject* pyfun)
    {
        // std::cout << "synthesizeEx" << std::endl;

        using namespace py;
        using namespace z3;
        using namespace boost;

        S.push(); Sp.push();
        _addExpr(de_expr, c1, c2);
        expr y = _createSynMiter(ex);

        int i = 0;
        dict args;
        DistInput* di;
        while ((di = ditree.getDistInput(y)) && (i++ < MAX_SYN_ITER)) {
            // std::cout << "iteration #" << i++ << std::endl;

            // convert to python.
            di->toPython(args);
            // and run python.
            py::dict d = call<py::dict>(pyfun, args);
            py::object r = d[name];
            // extract output.
            simout_ptr_t simout(new SimOutput(ex->type, r));
            // record in the tree.
            ditree.setOutput(simout);

            // now rewrite these expressions.
            Z3ExprRewritingAdapter cr1(c, di, suffix1);
            Z3ExprRewritingAdapter cr2(c, di, suffix2);
            z3::expr er1 = apply_visitor(SimoutAdapter(cr1, ex.get()), simout->out);
            z3::expr er2 = apply_visitor(SimoutAdapter(cr2, ex.get()), simout->out);
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
        nptr_t nr = ditree.getExpr(y, ex, i);
        S.pop(); Sp.pop();

        return nr;
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

            S.add(aie1); Sp.add(aie1);
            S.add(aic1); Sp.add(aic1);
            S.add(aie2); Sp.add(aie2);
            S.add(aic2); Sp.add(aic2);
        } else {
            expr ei = c1.getExpr(ex.get()).simplify();
            expr ci = c1.getCnst(ex.get()).simplify();

            S.add(ei); Sp.add(ei);
            S.add(ci); Sp.add(ci);
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

