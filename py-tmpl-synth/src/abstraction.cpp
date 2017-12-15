#include <abstraction.hpp>
#include <exception.hpp>
#include <smt.hpp>
#include <synthesizer.hpp>
#include <synrewriter.hpp>
#include <util.hpp>
#include <logging.hpp>
#include <Unroller.hpp>
#include <EqvChecker.hpp>
#include <VerilogExport.hpp>
#include <exportSMT.hpp>
#include <boogie.hpp>
#include <horn.hpp>

#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>

namespace ila
{
    // ---------------------------------------------------------------------- //
    int Abstraction::objCnt = 0;

    int Abstraction::getObjId()
    {
        return objCnt++;
    }

    Abstraction::Abstraction(const std::string& n)
      : MAX_SYN_ITER(200)
      , parent(NULL)
      , name(n)
      , fetchExpr(NULL)
      , fetchValid(BoolConst::get(true))
      , paramSyn(1)
      , reduceWhenImport(0)
      , _ht(NULL)
    {
    }

    Abstraction::Abstraction(Abstraction* p, const std::string& n)
      : MAX_SYN_ITER(200)
      , parent(p)
      , name(n)
      , fetchExpr(NULL)
      , fetchValid(BoolConst::get(true))
      , paramSyn(1)
      , reduceWhenImport(p->reduceWhenImport)
      , _ht(NULL)
    {
        ILA_ASSERT(parent != NULL, "parent must be non-NULL.");
        initMap(parent->inps, inps);
        initMap(parent->regs, regs);
        initMap(parent->bits, bits);
        initMap(parent->mems, mems);
        initMap(parent->funs, funs);
    }
        

    Abstraction::~Abstraction()
    {
        delete _ht;
        _ht = NULL;
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::initMap(nmap_t& from_m, nmap_t& to_m)
    {
        ILA_ASSERT(to_m.size() == 0, "to_m should be empty.");
        for(auto&& fn : from_m) {
            to_m.insert({fn.first, npair_t(&(fn.second))});  // without & it uses the default copy constructor
        }
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::addInp(const std::string& name, int width)
    {
        if(!checkAndInsertName(INP, name)) return NULL;
        NodeRef* n = new NodeRef(new BitvectorVar(name, width));
        inps.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::getVar(const nmap_t& m, const std::string& n)
    {
        auto pos = m.find(n);
        if (pos == m.end()) {
            throw PyILAException(PyExc_IndexError, "Unable to find: " + n);
            return NULL;
        } else {
            return new NodeRef(pos->second.var);
        }
    }

    void Abstraction::addVar(state_t st, nmap_t& m, nptr_t& n)
    {
        auto pos = m.find(n->getName());
        if (pos == m.end() && names.find(n->getName()) == names.end()) {
            npair_t np(n, NULL);
            m.insert({n->getName(), np});
            names.insert({n->getName(), st});
        } else {
            if (pos == m.end() || pos->second.var->type != n->type) {
                throw PyILAException(PyExc_TypeError,
                    "Type mismatch of new node: " + n->getName() +
                    " with existing node of the same name.");
            }
        }
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::addBit(const std::string& name)
    {
        if(!checkAndInsertName(BIT, name)) return NULL;
        NodeRef* n = new NodeRef(new BoolVar(name));
        bits.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    NodeRef* Abstraction::addReg(const std::string& name, int w)
    {
        if(!checkAndInsertName(REG, name)) return NULL;
        NodeRef* n = new NodeRef(new BitvectorVar(name, w));
        regs.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    NodeRef* Abstraction::addMem(const std::string& name, int aw, int dw)
    {
        if(!checkAndInsertName(MEM, name)) return NULL;
        NodeRef* n = new NodeRef(new MemVar(name, aw, dw));
        mems.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    NodeRef* Abstraction::addFun(const std::string& name, int rw, const py::list& l)
    {
        if (!checkAndInsertName(FUN, name)) return NULL;
        std::vector<int> argW;
        unsigned sz = py::len(l);
        for (unsigned i=0; i != sz; i++) {
            py::extract<int> ni_(l[i]);
            if (ni_.check()) {
                argW.push_back(ni_);
            }
        }

        NodeRef* n = new NodeRef(new FuncVar(name, rw, argW));
        funs.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::getBit(const std::string& name)
    {
        return getVar(bits, name);
    }

    NodeRef* Abstraction::getReg(const std::string& name)
    {
        return getVar(regs, name);
    }

    NodeRef* Abstraction::getMem(const std::string& name)
    {
        return getVar(mems, name);
    }

    NodeRef* Abstraction::getFun(const std::string& name)
    {
        return getVar(funs, name);
    }
    
    NodeRef* Abstraction::getInp(const std::string& name)
    {
        return getVar(inps, name);
    }

    void Abstraction::addVar(nptr_t& n)
    {
        const BoolVar* boolvar = NULL;
        const BitvectorVar* bvvar = NULL;
        const MemVar* memvar = NULL;
        const FuncVar* funcvar = NULL;

        if ((boolvar = dynamic_cast<const BoolVar*>(n.get()))) {
            addVar(BIT, bits, n);
        } else if ((bvvar = dynamic_cast<const BitvectorVar*>(n.get()))) {
            // BitvectorVar can also refer to Inport
            // Let's do the test here
            auto pos = inps.find(n->getName());
            if (pos == inps.end())
                addVar(REG, regs, n);
            else
                addVar(INP, inps, n);
        } else if ((memvar = dynamic_cast<const MemVar*>(n.get()))) {
            addVar(MEM, mems, n);
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n.get()))) {
            addVar(FUN, funs, n);
        }
    }

    // ---------------------------------------------------------------------- //
    nmap_t* Abstraction::getMap(const std::string& name, NodeRef* n)
    {
        // try to find the map we are adding to.
        nmap_t* m = NULL;
        if (n->node->type.isBool()) { m = &bits; }
        else if (n->node->type.isBitvector()) { m = &regs; }
        else if (n->node->type.isMem()) { m = &mems; }
        else {
            throw PyILAException(PyExc_TypeError, 
                "Unexpected type.");
            return NULL;
        }

        // now try to find the variable.
        auto pos = m->find(name);
        if (pos == m->end()) {
            throw PyILAException(PyExc_RuntimeError, 
                "Unable to find var: " + name);
            return NULL;
        }
        return m;
    }
    // ---------------------------------------------------------------------- //
    nmap_t* Abstraction::getMap(const std::string& name)
    {
        // try to find the map we are adding to.
        if (bits.find(name) != bits.end()) return &bits;
        if (regs.find(name) != regs.end()) return &regs;
        if (mems.find(name) != mems.end()) return &mems;
        throw PyILAException(PyExc_RuntimeError, 
            "Unable to find var: " + name);
        return NULL;
    }

    // ---------------------------------------------------------------------- //
    nmap_t::const_iterator Abstraction::findInMap(const std::string& name) const
    {
        // try to find in each of the maps.
        nmap_t::const_iterator pos = bits.find(name);
        if (pos == bits.end()) pos = regs.find(name);
        if (pos == regs.end()) pos = mems.find(name);
        if (pos == mems.end()) {
            throw PyILAException(PyExc_RuntimeError, "Unable to find var: " + name);
        }
        return pos;
    }

    nmap_t::iterator Abstraction::findInMap(const std::string& name)
    {
        // try to find in each of the maps.
        nmap_t::iterator pos = bits.find(name);
        if (pos == bits.end()) pos = regs.find(name);
        if (pos == regs.end()) pos = mems.find(name);
        if (pos == mems.end()) {
            throw PyILAException(PyExc_RuntimeError, "Unable to find var: " + name);
        }
        return pos;
    }
    nmap_t::const_iterator Abstraction::findInMapNoExcept(const std::string& name) const
    {
        // try to find in each of the maps.
        nmap_t::const_iterator pos = inps.find(name);
        if (pos == inps.end()) pos = bits.find(name);
        if (pos == bits.end()) pos = regs.find(name);
        if (pos == regs.end()) pos = mems.find(name);
        
        return pos;
    }

    nmap_t::iterator Abstraction::findInMapNoExcept(const std::string& name)
    {
        // try to find in each of the maps.
        nmap_t::iterator pos = inps.find(name);
        if (pos == inps.end()) pos = bits.find(name);
        if (pos == bits.end()) pos = regs.find(name);
        if (pos == regs.end()) pos = mems.find(name);
        
        return pos;
    }
    nmap_t::const_iterator Abstraction::MapEnd() const
    {
        nmap_t::const_iterator pos = mems.end();
        return pos;
    }
    nmap_t::iterator Abstraction::MapEnd()
    {
        nmap_t::iterator pos = mems.end();
        return pos;
    }
    // ---------------------------------------------------------------------- //
    void Abstraction::setInit(const std::string& name, NodeRef* n)
    {
        // try to find the map we are adding to.
        nmap_t* m = getMap(name, n);
        if (m == NULL) return;
        auto pos = m->find(name);
        ILA_ASSERT(pos != m->end(), "Invalid iterator.");

        // check types.
        if (n->node->type != pos->second.var->type) {
            throw PyILAException(PyExc_TypeError, 
                "Next expression not same type as variable");
        }

        pos->second.init = n->node;
    }

    NodeRef* Abstraction::getInit(const std::string& name) const
    {
        auto pos = findInMap(name); // init can never be NULL based on the constructors
        ILA_ASSERT(pos->second.init.get() != NULL , "init function of " + name + " is not set.");
        return new NodeRef(pos->second.init);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::setIpred(const std::string& name, NodeRef* n)
    {
        // try to find the map we are adding to.
        nmap_t* m = getMap(name);
        if (m == NULL) return;
        auto pos = m->find(name);
        ILA_ASSERT(pos != m->end(), "Invalid iterator.");

        // check types.
        if (!n->node->type.isBool()) {
            throw PyILAException(PyExc_TypeError, 
                "Ipred expression must be boolean.");
        }

        pos->second.ipred = n->node;
    }

    NodeRef* Abstraction::getIpred(const std::string& name) const
    {
        auto pos = findInMap(name);
        return new NodeRef(pos->second.ipred);
    }


    // ---------------------------------------------------------------------- //
    void Abstraction::setNext(const std::string& name, NodeRef* n)
    {
        // try to find the map we are adding to.
        nmap_t* m = getMap(name, n);
        if (m == NULL) return;
        auto pos = m->find(name);
        ILA_ASSERT(pos != m->end(), "Invalid iterator.");

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
        auto pos = findInMap(name);
        if(!pos->second.next.get())
            throw PyILAException(PyExc_RuntimeError, 
                "Next expression has not been set for variable:"+name);
        return new NodeRef(pos->second.next);
    }

    NodeRef* Abstraction::getNextI(const std::string& name, int i) const
    {
        auto pos = findInMap(name);
        const npair_t& nstruct = pos->second;
        if (i < 0 || i >= static_cast<int>(nstruct.next_vec.size())) {
            return NULL;
        } else {
            return new NodeRef(nstruct.next_vec[i]);
        }
    }

    // ---------------------------------------------------------------------- //
    AbstractionWrapper* Abstraction::addUAbs(
        const std::string& name,
        NodeRef* validN)
    {
        const nptr_t& valid = validN->node;
        if (!valid->type.isBool()) {
            throw PyILAException(PyExc_TypeError, "Expected a boolean.");
            return NULL;
        }
        if (uabs.find(name) != uabs.end()) {
            throw PyILAException(
                PyExc_RuntimeError, "Abstraction already exists.");
            return NULL;
        }

        AbstractionWrapper *aw = new AbstractionWrapper(this, name);
        uabstraction_t uab = { valid, aw->abs };
        uabs[name] = uab;
        aw->abs->addAssumption(validN);
        aw->abs->fetchValid = valid;
        return aw;
    }

    AbstractionWrapper* Abstraction::getUAbs(const std::string& name)
    {
        auto pos = uabs.find(name);
        if(pos == uabs.end())
            throw PyILAException(PyExc_KeyError, 
                    "Unable to find microabstraction: " + name);
        return new AbstractionWrapper(pos->second.abs);
    }

    void Abstraction::connectUInst(
        const std::string& name, const abstraction_ptr_t& uab)
    {
        const std::string& uab_name = uab->name;
        auto upos = uabs.find(uab_name);
        if (upos == uabs.end() || upos->second.abs.get() != uab.get()) {
            throw PyILAException(PyExc_KeyError, 
                    "Unable to find microabstraction: " + uab_name);
            return;
        }
        // get the next objects.
        auto epos = findInMap(name);
        auto epos_u = uab->findInMap(name);
        const nptr_t& nxt = epos->second.next;
        const nptr_t& nxt_u = epos_u->second.next;
        if(!nxt.get() ) // this can happen when someone forgets to set "next" first
            throw PyILAException(PyExc_RuntimeError, 
                "Please specify next expr for:" +name +" before connecting.");

        if (nxt->type != nxt_u->type) {
            throw PyILAException(PyExc_TypeError,
                "Types don't match for: " + name);
            return;
        }
        nptr_t nc(Node::ite(upos->second.valid, nxt_u, nxt));
        epos->second.next = nc;
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::bvConstLong(py::long_ l_, int w)
    {
        auto l = to_cpp_int(l_);
        return new NodeRef(new BitvectorConst(l, w));
    }

    NodeRef* Abstraction::bvConstInt(unsigned int l, int w)
    {
        return new NodeRef(new BitvectorConst(l, w));
    }

    NodeRef* Abstraction::boolConstB(bool b)
    {
        return new NodeRef(BoolConst::get(b));
    }

    NodeRef* Abstraction::boolConstI(int b)
    {
        return new NodeRef(BoolConst::get(b != 0));
    }

    NodeRef* Abstraction::boolConstL(py::long_ l_)
    {
        auto l = to_cpp_int(l_);
        return new NodeRef(BoolConst::get(l != 0));
    }

    NodeRef* Abstraction::memConst(const MemValues& mv)
    {
        return new NodeRef(new MemConst(mv));
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
    nptr_t Abstraction::getFetchValidNode() const
    {
        return fetchValid;
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
    const nptr_vec_t& Abstraction::getDecodeNodes() const
    {
        return decodeExprs;
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
        if (!doesNextExist(regs)) return;
        if (!doesNextExist(bits)) return;
        if (!doesNextExist(mems)) return;

        std::vector<nmap_t*> maps = { &bits, &regs, &mems };
        Synthesizer syn(*this, maps);
        syn.synthesizeAll(pyfun);
    }

    void Abstraction::synthesizeReg(
        const std::string& name, PyObject* pyfun)
    {
        auto pos = regs.find(name);
        if (pos == regs.end()) {
            pos = mems.find(name);
        }
        if (pos == mems.end()) {
            pos = bits.find(name);
        }
        if (pos == bits.end()) {
            throw PyILAException(PyExc_RuntimeError,
                "Unable to find name: " + name);
            return;
        }
        if (pos->second.next.get() == NULL) {
            throw PyILAException(PyExc_RuntimeError,
                "Next expression is not set for: " + name);
            return;
        }

        std::vector<nmap_t*> maps = { &bits, &regs, &mems };
        Synthesizer syn(*this, maps);
        syn.synthesizeReg(pos, pyfun);
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::synthesizeElement(
        const std::string& name, 
        NodeRef* ex, PyObject* pyfun)
    {
        nptr_vec_t all_assumps;
        getAllAssumptions(all_assumps);
        auto nr = _synthesize(name, all_assumps, ex->node, pyfun);
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

    // ---------------------------------------------------------------------- //

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

        log2("Abstraction.areEqual") << "left: " << *left->node.get() << std::endl;
        z3::expr ex1 = c.getExpr(left->node.get());
        z3::expr cn1 = c.getCnst(left->node.get());
        log2("Abstraction.areEqual") << "ex1:" << ex1 << std::endl;

        log2("Abstraction.areEqual") << "right: " << *right->node.get() << std::endl;
        z3::expr ex2 = c.getExpr(right->node.get());
        z3::expr cn2 = c.getCnst(right->node.get());
        log2("Abstraction.areEqual") << "ex2:" << ex2 << std::endl;

        expr mitre = (ex1 != ex2);
        log2("Abstraction.areEqual") << "mitre:" << mitre << std::endl;


        solver S(c_);

        nptr_vec_t all_assumps;
        getAllAssumptions(all_assumps);
        for (auto&& a : all_assumps) {
            S.add(c.getExpr(a.get()));
        }

        S.add(mitre);
        S.add(cn1);
        S.add(cn2);
        return checkMiter(S, ex1, ex2);
    }

    bool Abstraction::areEqualAssump(NodeRef* assump, NodeRef* left, NodeRef* right)
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

        nptr_vec_t all_assumps;
        getAllAssumptions(all_assumps);
        for (auto&& a : all_assumps) {
            S.add(c.getExpr(a.get()));
        }
        S.add(c.getExpr(assump->node.get()));

        S.add(mitre);
        S.add(cn1);
        S.add(cn2);
        return checkMiter(S, ex1, ex2);
    }

    // ---------------------------------------------------------------------- //
    bool Abstraction::areEqualUnrolled(unsigned n, NodeRef* reg, NodeRef* exp)
    {
        using namespace z3;

        context c;
        solver S(c);
        Z3ExprAdapter adp(c, "");
        adp.setNameSuffix("_");

        Unroller u("", *this, c, S);
        for (unsigned i=0; i <= n; i++) {
            u.addTr();
            u.newFrame();
        }

        expr e_exp = adp.getExpr(exp->node.get()).simplify();
        expr c_exp = adp.getCnst(exp->node.get()).simplify();
        expr e_reg = u.getOutput(n, reg->node.get()).simplify();
        expr mitre = e_exp != e_reg;


        S.add(mitre.simplify());
        S.add(c_exp);

        //std::cout << "z3-expr  : " << e_reg << std::endl;
        //std::cout << "solver: " << S << std::endl;
        return checkMiter(S, e_exp, e_reg);
    }

#define CHECK_VARTYPE_CONTAINS(vartype,a1,a2) \
        for (auto && v : a1->vartype ) \
        {                             \
            auto pos = a2->vartype.find(v.first); \
            if(pos == a2->vartype.end())   \
                return NEQVarNotExist(a1->name,a2->name,v.first);    \
            if( (pos->second.var )->type != (v.second.var)->type )      \
                return NEQVarTypeMismatch(a1->name,a2->name,v.first); \
        }
        
    bool Abstraction::EQcheckSimple(Abstraction* a1, Abstraction *a2)
    {
        //check 1 -> 2

        // checking whether there are same variables
        // and also the types are correct
        CHECK_VARTYPE_CONTAINS(mems,a1,a2);
        CHECK_VARTYPE_CONTAINS(mems,a2,a1);
        CHECK_VARTYPE_CONTAINS(regs,a1,a2);
        CHECK_VARTYPE_CONTAINS(regs,a2,a1);
        CHECK_VARTYPE_CONTAINS(bits,a1,a2);
        CHECK_VARTYPE_CONTAINS(funs,a2,a1);
        //check all regs/bits/mems
        //if it is simple, in other words
        //no subILA's next has a valid expression
        //then they should be the same under bmc(1)

        for ( auto && reg : a1->regs ) // just iterate on one side
        {   
            std::string name(reg.first);
            if( DetermineUnrollBound(a1,name) == 1 && DetermineUnrollBound(a2,name) == 1 )
            {
                nptr_t n1 = (a1->findInMap(name))->second.var;
                nptr_t n2 = (a2->findInMap(name))->second.var;
                NodeRef var1(n1);
                NodeRef var2(n2);
                if( !bmc(1,a1,&var1,1,a2,&var2) ) {
                    return NEQArchVarUpdateMismatch(a1->name,a2->name,name);
                    return false;
                }
                std::cout<<"state:"<<name<<" is checked to be EQ."<<std::endl;  
            }
        }
        for ( auto && mem : a1->mems ) // just iterate on one side
        {   
            std::string name(mem.first);
            if( DetermineUnrollBound(a1,name) == 1 && DetermineUnrollBound(a2,name) == 1 )
            {
                nptr_t n1 = (a1->findInMap(name))->second.var;
                nptr_t n2 = (a2->findInMap(name))->second.var;
                NodeRef var1(n1);
                NodeRef var2(n2);
                if( !bmc(1,a1,&var1,1,a2,&var2) ) {
                    return NEQArchVarUpdateMismatch(a1->name,a2->name,name);
                    return false;
                }
                std::cout<<"state:"<<name<<" is checked to be EQ."<<std::endl;  
            }
        }
        for ( auto && bit : a1->bits ) // just iterate on one side
        {   
            std::string name(bit.first);
            if( DetermineUnrollBound(a1,name) == 1 && DetermineUnrollBound(a2,name) == 1 )
            {
                nptr_t n1 = (a1->findInMap(name))->second.var;
                nptr_t n2 = (a2->findInMap(name))->second.var;
                NodeRef var1(n1);
                NodeRef var2(n2);
                if( !bmc(1,a1,&var1,1,a2,&var2) ) {
                    return NEQArchVarUpdateMismatch(a1->name,a2->name,name);
                    return false;
                }
                std::cout<<"state:"<<name<<" is checked to be EQ."<<std::endl;  
            }
        }
        return true;

    }

    bool Abstraction::bmc(unsigned n, Abstraction *abs, NodeRef *r, bool init, NodeRef * initAssump)
    {
        using namespace z3;

        context c;
        solver S(c);
        // unroll 1
        Unroller u("", *abs, c, S);
        u.Fr0Init(init);
        //add assumptions on frame 0
        u.addTr();
        for (auto && a: abs->assumps) {
            S.add(u.subsFormula(a.get()));
        }        
        if (initAssump) {
            S.add(u.subsFormula(initAssump->node.get()));
        }
        
        for (unsigned i=1;i <= n; i++) {
            u.newFrame();
            u.addTr();
        }
        expr assertion = u.subsFormula(r->node.get());
        u.newFrame();
        auto assumptCheck = S.check();
        if(assumptCheck == unsat) {
            std::cout<<"<W>: assumption does not hold!"<<std::endl;
            return true;
        }
        S.add(!assertion);
        
        auto assertCheck = S.check();
        if ( assertCheck == unsat ) 
            return true;
        
        model m = S.get_model();
        Unroller::EvalEachFrame(m,&u,log2("BMCResult"));
        return false;        
            
    }

    bool Abstraction::bmc(
        unsigned n1, Abstraction* a1, NodeRef* r1, 
        unsigned n2, Abstraction* a2, NodeRef* r2)
    {
        using namespace z3;

        context c;
        solver S(c);

        // unroll 1
        Unroller u1("", *a1, c, S);
        for (unsigned i=0; i <= n1; i++) {
            u1.addTr();
            u1.newFrame();
        }

        // unroll 2
        Unroller u2("", *a2, c, S);
        for (unsigned i=0; i <= n2; i++) {
            u2.addTr();
            u2.newFrame();
        }

        expr e_r1 = u1.getOutput(n1, r1->node.get()).simplify();
        expr e_r2 = u2.getOutput(n2, r2->node.get()).simplify();
        expr mitre = (e_r1 != e_r2).simplify();

        S.add(mitre);
        //std::cout << "e_r1=" << e_r1 << std::endl;
        //std::cout << "e_r2=" << e_r2 << std::endl;
        //std::cout << S << std::endl;
        return checkMiter(S, e_r1, e_r2);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::toBoogie(const std::string& name)
    {
        BoogieTranslator bt(this);
        bt.translate();
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::hornifyAll(const std::string& fileName)
    {
        if (_ht == NULL) 
            _ht = new HornTranslator (this, name);
        _ht->hornifyAll(fileName);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::hornifyNode(NodeRef* node, const std::string& ruleName)
    {
        if (_ht == NULL) 
            _ht = new HornTranslator (this, name);
        _ht->hornifyNode(node, ruleName);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::generateHornMapping(const std::string& type)
    {
        if (_ht == NULL) 
            _ht = new HornTranslator (this, name);
        _ht->generateMapping (type);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::exportHornToFile(const std::string& fileName)
    {
        if (_ht == NULL) {
            log1 ("Horn") << "Nothing has been hornified.";
            return;
        }
        _ht->exportHorn(fileName);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::hornifyIteAsNode(bool iteAsNode)
    {
        if (_ht == NULL) 
            _ht = new HornTranslator (this, name);
        _ht->setIteAsNode(iteAsNode);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::hornifyBvAsInt(bool bvAsInt)
    {
        if (_ht == NULL) 
            _ht = new HornTranslator (this, name);
        _ht->setBvAsInt(bvAsInt);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::addHornInstr(const std::string& i, NodeRef* d)
    {
        if (_ht == NULL) 
            _ht = new HornTranslator (this, name);
        _ht->addInstr (i, d);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::addHornNext (const std::string& i, const std::string& s,
                                   NodeRef* n)
    {
        if (_ht == NULL)
            _ht = new HornTranslator (this, name);
        _ht->addNext (i, s, n);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::addHornChild (const std::string& c, const std::string& i,
                                    NodeRef* d)
    {
        if (_ht == NULL)
            _ht = new HornTranslator (this, name);
        _ht->addChildInstr (c, i, d);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::forEachAssump(assump_visitor_i& vis) const
    {
        // do all of our assumptions.
        for (auto && a: assumps) {
            vis.useAssump(a);
        }
        // and then the parent's.
        if (parent) {
            parent->forEachAssump(vis);
        }
    }

    void Abstraction::getAllAssumptions(nptr_vec_t& assump_vec) const
    {
        assump_collector_t assump_collector(assump_vec);
        forEachAssump(assump_collector);
    }

    void Abstraction::assump_collector_t::useAssump(const nptr_t& a)
    {
        vec.push_back(a);
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::exportOneToFile(NodeRef* node,
                                      const std::string& fileName) const
    {
        std::ofstream out(fileName.c_str());
        ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");
        ImExport expt(&funcReducer);

        ILA_ASSERT(node != NULL, "Export Node is Null\n"
                "Please make sure you synthesize before exporting");
        expt.exportAst(out, node->node.get());
        out.close();
    }

    void Abstraction::exportListToFile(const py::list& l,
                                      const std::string& fileName) const
    {
        if (py::len(l) < 2) {
            throw PyILAException(
                PyExc_RuntimeError,
                "Must have at least two asts.");
            return;
        }

        std::ofstream out(fileName.c_str());
        ILA_ASSERT (out.is_open(), "File " + fileName + " not open.");
        ImExport expt (&funcReducer);

        out << py::len(l) << "\n";

        for (unsigned i=0; i != py::len(l); i++) {
            py::extract<NodeRef&> ni(l[i]);
            if (ni.check()) {
                expt.exportAst (out, ni().node.get()); 
            out << "\n";
            } else {
                out.close();
                throw PyILAException(
                    PyExc_TypeError,
                    "Argument to choice must be a node.");
            }
        }
        out.close();
    }

    // ---------------------------------------------------------------------- //
    void Abstraction::generateVerilogToFile(const std::string &fileName) const
    {
        // FIXME: 
        //        1. take memory into consideration
        //        2. take u-inst into consideration
        
        std::ofstream out(fileName.c_str());
        ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");

        VerilogExport expt(name,"clk","rst", vlgExpConfig);
        for (auto const & inp : inps) 
            expt.exportInp(inp.first,inp.second);
        
        for (auto const & reg : regs)
            expt.exportReg(reg.first,reg.second);
        
        for (auto const & bit : bits)
            expt.exportBit(bit.first,bit.second);
        
        for (auto const & mem : mems)
            expt.exportMem(mem.first,mem.second);

        for (auto const & func : funs)
            expt.exportFunc(func.first,func.second);

        // FIXME: uabs not considered

        expt.finalExport(out);
        out.close();

    }

    void Abstraction::generateVerilogToFile(const std::string &fileName, const std::string &topModName) const
    {
        // FIXME: 
        //        1. take memory into consideration
        //        2. take u-inst into consideration
        
        std::ofstream out(fileName.c_str());
        ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");

        VerilogExport expt(topModName,"clk","rst", vlgExpConfig);
        for (auto const & inp : inps) 
            expt.exportInp(inp.first,inp.second);
        
        for (auto const & reg : regs)
            expt.exportReg(reg.first,reg.second);
        
        for (auto const & bit : bits)
            expt.exportBit(bit.first,bit.second);
        
        for (auto const & mem : mems)
            expt.exportMem(mem.first,mem.second);

        for (auto const & func : funs)
            expt.exportFunc(func.first,func.second);

        // FIXME: uabs not considered

        expt.finalExport(out);
        out.close();
    }
    
    void Abstraction::exportAllToStream(std::ofstream &out) const
    {
        ImExport expt(&funcReducer);

        // names.
        out << ".names: ";
        for (auto && it : names) {
            out << " " << it.first << " " << (int) it.second;
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
            expt.exportAst(out, it->second.init.get());
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
            expt.exportAst(out, it->second.init.get());
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
            expt.exportAst(out, it->second.init.get());
            out << " ";
            expt.exportAst(out, it->second.next.get());
        }
        out << "\n.mems_end\n";

        // funs.
        out << ".funs: ";
        for (nmap_t::const_iterator it = funs.begin();
             it != funs.end(); it++) {
            out << "\n" << it->first << " ";
            expt.exportAst(out, it->second.var.get());
        }
        out << "\n.funs_end\n";

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
            out << "\n" << i << " ";
            expt.exportAst(out, assumps[i].get());
        }
        out << "\n.assumps_end\n";

        // uabs name & valid
        out << ".uabs:";
        for (uabs_map_t::const_iterator it = uabs.begin();
             it != uabs.end(); it++) {
            out << "\n" << it->first << " ";
            expt.exportAst(out, it->second.valid.get());
        }
        out << "\n.uabs_end\n";
    }

    void Abstraction::exportAllToFile(const std::string& fileName) const
    {
        // FIXME Need to be fixed for uabstractions.
        std::ofstream out(fileName.c_str());
        ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");
        exportAllToStream(out);
        out.close();
    }

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::importOneFromFile(const std::string& fileName)
    {
        std::ifstream in;
        in.open(fileName.c_str());
        ILA_ASSERT(in.is_open(), "File " + fileName + " not found.");

        ImExport ipt(&funcReducer, reduceWhenImport);
        for (auto it = inps.begin(); it != inps.end(); it++)
        {
            ipt.mapInsert(it->first, it->second.var);
        }
        for (auto it = regs.begin(); it != regs.end(); it++)
        {
            ipt.mapInsert(it->first, it->second.var);
        }
        for (auto it = bits.begin(); it != bits.end(); it++)
        {
            ipt.mapInsert(it->first, it->second.var);
        }
        for (auto it = mems.begin(); it != mems.end(); it++)
        {
            ipt.mapInsert(it->first, it->second.var);
        }
        nptr_t res = ipt.importAst(this, in);
        if(reduceWhenImport==2) funcReducer.InsertOrDupNode(res);
        NodeRef* wrap = new NodeRef(res);
        // FIXME 
        ipt.addMapVars(this);
        in.close();
        return wrap;
    }

    py::list Abstraction::importListFromFile(const std::string& fileName)
    { 
        py::list l;
        //for ( auto de : decodeExprs ) {
        //    NodeRef* nr = new NodeRef(de);
        //   l.append(nr);
        //}

        std::ifstream in;
        in.open(fileName.c_str());
        ILA_ASSERT(in.is_open(), "File " + fileName + " not found.");

        ImExport ipt(&funcReducer, reduceWhenImport);
        for (auto it = inps.begin(); it != inps.end(); it++)
        {
            ipt.mapInsert(it->first, it->second.var);
        }
        for (auto it = regs.begin(); it != regs.end(); it++)
        {
            ipt.mapInsert(it->first, it->second.var);
        }
        for (auto it = bits.begin(); it != bits.end(); it++)
        {
            ipt.mapInsert(it->first, it->second.var);
        }
        for (auto it = mems.begin(); it != mems.end(); it++)
        {
            ipt.mapInsert(it->first, it->second.var);
        }

        std::string buff;
        in >> buff;
        int listSize = atoi (buff.c_str());

        for (int i = 0; i < listSize; i++) {
            nptr_t res = ipt.importAst(this, in);

            log1 ("Export") << "Import ast " << i << ".\n";

            funcReducer.InsertOrDupNode (res);
            NodeRef* wrap = new NodeRef(res);

            l.append (wrap);
        }
        
        ipt.addMapVars(this);
        in.close();

        return l;
    }
    
    void Abstraction::importAllFromStream(std::ifstream &in, bool Clear = true) // Clear is unset when called by parent ILA
    {
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

        ImExport ipt(&funcReducer, reduceWhenImport);

        std::string buf;
        in >> buf;

        // names.
        ILA_ASSERT(buf == ".names:", "Expect .names section");
        in >> buf;
        while (buf != ".names_end") {
            int i;
            in >> i;
            checkAndInsertName((state_t) i, buf);
            in >> buf;
        }

        // inputs.
        in >> buf;
        ILA_ASSERT(buf == ".inps:", "Expect .inps section");
        in >> buf;
        while (buf != ".inps_end") {
            nptr_t var = ipt.importAst(this, in);
            nptr_t next = ipt.importAst(this, in);
            npair_t  * p = NULL;
            if (parent)
            {
                auto pos = parent->findInMapNoExcept(buf);
                if(pos != parent->MapEnd())
                    p = &(pos->second);
            }
            inps.insert({buf, npair_t(var, next, var, p)});
            in >> buf;
        }

        // registers.
        in >> buf;
        ILA_ASSERT(buf == ".regs:", "Expect .regs section");
        in >> buf;
        while (buf != ".regs_end") {
            nptr_t var = ipt.importAst(this, in);
            nptr_t init = ipt.importAst(this, in);
            nptr_t next = ipt.importAst(this, in);
            npair_t  * p = NULL;
            if (parent)
            {
                auto pos = parent->findInMapNoExcept(buf);
                if(pos != parent->MapEnd())
                    p = &(pos->second);
            }
            regs.insert({buf, npair_t(var, next, init, p)});
            in >> buf;
        }

        // bits.
        in >> buf;
        ILA_ASSERT(buf == ".bits:", "Expect .bits section");
        in >> buf;
        while (buf != ".bits_end") {
            nptr_t var = ipt.importAst(this, in);
            nptr_t init = ipt.importAst(this, in);
            nptr_t next = ipt.importAst(this, in);
            npair_t  * p = NULL;
            if (parent)
            {
                auto pos = parent->findInMapNoExcept(buf);
                if(pos != parent->MapEnd())
                    p = &(pos->second);
            }
            bits.insert({buf, npair_t(var, next, init, p)});
            in >> buf;
        }

        // mems.
        in >> buf;
        ILA_ASSERT(buf == ".mems:", "Expect .mems section");
        in >> buf;
        while (buf != ".mems_end") {
            nptr_t var = ipt.importAst(this, in);
            nptr_t init = ipt.importAst(this, in);
            nptr_t next = ipt.importAst(this, in);
            npair_t  * p = NULL;
            if (parent)
            {
                auto pos = parent->findInMapNoExcept(buf);
                if(pos != parent->MapEnd())
                    p = &(pos->second);
            }
            mems.insert({buf, npair_t(var, next, init, p)});
            in >> buf;
        }

        // funs.
        in >> buf;
        ILA_ASSERT(buf == ".funs:", "Expect .funs section");
        in >> buf;
        while (buf != ".funs_end") {
            nptr_t var = ipt.importAst(this, in);
            funs.insert({buf, npair_t(var, NULL)});
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

        // uabs name & valid
        in >> buf;
        ILA_ASSERT(buf == ".uabs:", "Expect .uabs section, but get:" + buf);
        in >> buf;
        while (buf != ".uabs_end") {
            // we already have the name here
            nptr_t valid = ipt.importAst(this,in);
            NodeRef n(valid);
            addUAbs(buf,&n); // buf is the name
            in >> buf;
        }
    }

    void Abstraction::importAllFromFile(const std::string& fileName) 
    {
        // FIXME Need to be fixed for uabstractions.
        std::ifstream in;
        in.open(fileName.c_str());
        ILA_ASSERT(in.is_open(), "File " + fileName + " not found.");
        importAllFromStream(in);
    }

    void Abstraction::generateCbmcCtoFile(const std::string & fileName) const
    {
        CVerifGen* gen = generateCBMCC(false);
        gen->exportAllToFile(fileName);
    }
    
    void Abstraction::generateCbmcCtoDir(const std::string & dirName) const
    {
        CVerifGen* gen = generateCBMCC(true);
        gen->exportAllToDir(dirName);
    }
    
    void Abstraction::generateSimToFile(const std::string& fileName) const
    {
        CppSimGen* gen = generateSim(false);
        gen->exportAllToFile(fileName);
    }

    void Abstraction::generateSimToDir(const std::string& dirName) const
    {
        CppSimGen* gen = generateSim(true);
        gen->exportAllToDir(dirName);
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
            log2("Abstraction._synthesize") << "iteration #" << i++ << std::endl;

            // extract model.
            model m = S.get_model();
            DistInput di(*this, c1, m, sv);
            di.toPython(args);

            log2("Abstraction._synthesize") << "model: " << m << std::endl;

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

        log2("Abstraction._synthesize") << "finished after " << i << " SMT calls." << std::endl;

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
    const npair_t* Abstraction::getMapEntry(const std::string& name) const
    {
        auto pos = names.find(name);
        if (pos == names.end()) {
            return NULL;
        }
        const nmap_t* map = NULL;
        if (pos->second == INP) {
            map = &inps;
        } else if (pos->second == REG) {
            map = &regs;
        } else if (pos->second == BIT) {
            map = &bits;
        } else if (pos->second == MEM) {
            map = &mems; 
        } else if (pos->second == FUN) {
            map = &funs;
        } else {
            ILA_ASSERT(false, "Invalid value for entry in names.");
            return NULL;
        }

        auto pos2 = map->find(name);
        ILA_ASSERT(pos2 != map->end(), "Not found in the appropriate map!");
        return &(pos2->second);
    }

    // ---------------------------------------------------------------------- //
    bool Abstraction::checkAndInsertName(state_t st, const std::string& name)
    {
        if (names.find(name) != names.end()) {
            throw PyILAException(PyExc_RuntimeError,
                "Variable with this name already exists.");
            return false;
        }
        names.insert({name, st});
        return true;
    }

    // ---------------------------------------------------------------------- //
    bool Abstraction::doesNextExist(const nmap_t& m) const
    {
        for (auto&& r : m) {
            const nptr_t& next(r.second.next);
            if (next == NULL) {
                throw PyILAException(PyExc_RuntimeError,
                            "Next expression not set for " + r.first);
                return false;
            }
        }
        return true;
    }

    // ---------------------------------------------------------------------- //
    
    CVerifGen*  Abstraction::generateCBMCC(bool hier) const
    {
          
        CVerifGen* gen = new CVerifGen(name);

        // add var to it
        // Set inputs.
        for (auto it = inps.begin(); it != inps.end(); it++) {
            gen->addInput(it->first, it->second.var, parent != NULL);
        }
        // Set regs.
        for (auto it = regs.begin(); it != regs.end(); it++) {
            gen->addState(it->first, it->second.var, parent != NULL);
        }
        // Set bits.
        for (auto it = bits.begin(); it != bits.end(); it++) {
            gen->addState(it->first, it->second.var, parent != NULL);
        }
        // Set mems.
        for (auto it = mems.begin(); it != mems.end(); it++) {
            gen->addState(it->first, it->second.var, parent != NULL);
        }
        // Set funs.
        for (auto it = funs.begin(); it != funs.end(); it++) {
            gen->addFuncVar(it->first, it->second.var, parent != NULL);
        }
        
        // Create update function.
        CFun* updateFun = gen->addFun("update");

       
       std::set<std::string> used;
       std::pair<std::set<std::string>::iterator, bool> check;
       // First add current level variables.
       // Calculate the next value.
       for (auto it = regs.begin(); it != regs.end(); it++) {
           check = used.insert(it->first);
           if (check.second == false) continue;
           nptr_t nc = it->second.next;
           if (nc == NULL) continue;
           if (hier) {
               // Create new function for the state update.
               CFun* singleUpdateFunc = gen->addFun("cUpdateFun_" + it->first);
               gen->buildFun(singleUpdateFunc, nc);
               gen->setFunReturn(singleUpdateFunc, nc);
               gen->endFun(singleUpdateFunc);

               ILA_ASSERT(singleUpdateFunc->retSet(), "return not set succeefully");
               
               // Calculate next value in top function, and update at the end
               CVar* nxtVal = gen->appFun(singleUpdateFunc, updateFun);
               gen->addFunUpdate(updateFun, it->second.var, nxtVal);
           } else {
               gen->buildFun(updateFun, nc);
               gen->addFunUpdate(updateFun, it->second.var, nc);
           }
       }
       for (auto it = bits.begin(); it != bits.end(); it++) {
           check = used.insert(it->first);
           if (check.second == false) continue;
           nptr_t nc = it->second.next;
           if (nc == NULL) continue;
           if (hier) {
               // Create new function for the state update.
               CFun* singleUpdateFunc = gen->addFun("cUpdateFun_" + it->first);
               gen->buildFun(singleUpdateFunc, nc);
               gen->setFunReturn(singleUpdateFunc, nc);
               gen->endFun(singleUpdateFunc);
               
               ILA_ASSERT(singleUpdateFunc->retSet(), "return not set succeefully");
               
               // Calculate next value in top function, and update at the end
               CVar* nxtVal = gen->appFun(singleUpdateFunc, updateFun);
               gen->addFunUpdate(updateFun, it->second.var, nxtVal);
           } else {
               gen->buildFun(updateFun, nc);
               gen->addFunUpdate(updateFun, it->second.var, nc);
           }
       }
       for (auto it = mems.begin(); it != mems.end(); it++) {
           check = used.insert(it->first);
           if (check.second == false) continue;
           nptr_t nc = it->second.next;
           if (nc == NULL) continue;
           if (hier) {
               // Create new function for the state update.
               CFun* singleUpdateFunc = gen->addFun("cUpdateFun_" + it->first);
               gen->buildFun(singleUpdateFunc, nc);
               gen->setFunReturn(singleUpdateFunc, nc);
               gen->endFun(singleUpdateFunc);
               
               ILA_ASSERT(singleUpdateFunc->retSet(), "return not set successfully");
               
               // Calculate next value in top function, and update at the end
               CVar* nxtVal = gen->appFun(singleUpdateFunc, updateFun);
               gen->addFunUpdate(updateFun, it->second.var, nxtVal);
           } else {
               gen->buildFun(updateFun, nc);
               gen->addFunUpdate(updateFun, it->second.var, nc);
           }
       }
       
       gen->endFun(updateFun);
       
       // Assumps
       std::vector<CFun*> assVec;
       for (unsigned i = 0; i < assumps.size(); i++) {
           CFun* assFun = gen->addFun(
                   "assumps_" + boost::lexical_cast<std::string>(i));
           gen->buildFun(assFun, assumps[i]);
           gen->setFunReturn(assFun, assumps[i]);
           gen->endFun(assFun);
           assVec.push_back(assFun);
       }
       
       return gen;

   }
        
    
    // Set all information into simulator generator.
    CppSimGen* Abstraction::generateSim(bool hier) const
    {
        CppSimGen* gen = new CppSimGen(name);

        // Set variables to simulator generator.
        addVarToSimulator(gen);

        // Create update function.
        CppFun* updateFun = gen->addFun("update");
        setUpdateToFunction(gen, updateFun, NULL, hier);
        gen->endFun(updateFun);

        /*
        // FetchExpr
        CppFun* fetchExprFun = gen->addFun("fetch");
        gen->buildFun(fetchExprFun, fetchExpr);
        gen->setFunReturn(fetchExprFun, fetchExpr);
        gen->endFun(fetchExprFun);

        // FetchValid
        CppFun* fetchValidFun = gen->addFun("fetchValid");
        gen->buildFun(fetchValidFun, fetchValid);
        gen->setFunReturn(fetchValidFun, fetchValid);
        gen->endFun(fetchValidFun);

        // DecodeExprs
        std::vector<CppFun*> decodeVec;
        for (unsigned i = 0; i < decodeExprs.size(); i++) {
            CppFun* decFun = gen->addFun(
                    "decode_" + boost::lexical_cast<std::string>(i));
            gen->buildFun(decFun, decodeExprs[i]);
            gen->setFunReturn(decFun, decodeExprs[i]);
            gen->endFun(decFun);
            decodeVec.push_back(decFun);
        }
        */

        // Assumps
        std::vector<CppFun*> assVec;
        for (unsigned i = 0; i < assumps.size(); i++) {
            CppFun* assFun = gen->addFun(
                    "assumps_" + boost::lexical_cast<std::string>(i));
            gen->buildFun(assFun, assumps[i]);
            gen->setFunReturn(assFun, assumps[i]);
            gen->endFun(assFun);
            assVec.push_back(assFun);
        }

        return gen;
    }

    // Iteratively set inputs, states, and functions to the simulator generator.
    void Abstraction::addVarToSimulator(CppSimGen* gen) const
    {
        // First add current level states.
        // Set inputs.
        for (auto it = inps.begin(); it != inps.end(); it++) {
            gen->addInput(it->first, it->second.var, parent != NULL);
        }
        // Set regs.
        for (auto it = regs.begin(); it != regs.end(); it++) {
            gen->addState(it->first, it->second.var, parent != NULL);
        }
        // Set bits.
        for (auto it = bits.begin(); it != bits.end(); it++) {
            gen->addState(it->first, it->second.var, parent != NULL);
        }
        // Set mems.
        for (auto it = mems.begin(); it != mems.end(); it++) {
            gen->addState(it->first, it->second.var, parent != NULL);
        }
        // Set funs.
        for (auto it = funs.begin(); it != funs.end(); it++) {
            gen->addFuncVar(it->first, it->second.var, parent != NULL);
        }

        // Then next level micro abstraction.
        // No need, we will verify each level separately
        // because there is no inital values exported
        // you cannot expect to unroll the micro states
        //for (auto it = uabs.begin(); it != uabs.end(); it++) {
        //    it->second.abs->addVarToSimulator(gen);
        //}
    }

    void Abstraction::setUpdateToFunction(
            CppSimGen* gen, 
            CppFun* fun,
            nptr_t valid,
            bool doHier) const
    {
        static std::set<std::string> used;
        static std::pair<std::set<std::string>::iterator, bool> check;
        if (valid == NULL) used.clear();
        // First add current level variables.
        // Calculate the next value.
        for (auto it = regs.begin(); it != regs.end(); it++) {
            check = used.insert(it->first);
            if (check.second == false) continue;
            nptr_t nc = (valid == NULL) ? it->second.next : 
                    nptr_t(Node::ite(valid, it->second.next, it->second.var));
            if (nc == NULL) continue;
            if (doHier) {
                // Create new function for the state update.
                CppFun* singleUpdateFunc = gen->addFun("cppUpdateFun_" + it->first);
                gen->buildFun(singleUpdateFunc, nc);
                gen->setFunReturn(singleUpdateFunc, nc);
                gen->endFun(singleUpdateFunc);

                ILA_ASSERT(singleUpdateFunc->retSet(), "return not set succeefully");
                
                // Calculate next value in top function, and update at the end
                CppVar* nxtVal = gen->appFun(singleUpdateFunc, fun);
                gen->addFunUpdate(fun, it->second.var, nxtVal);
            } else {
                gen->buildFun(fun, nc);
                gen->addFunUpdate(fun, it->second.var, nc);
            }
        }
        for (auto it = bits.begin(); it != bits.end(); it++) {
            check = used.insert(it->first);
            if (check.second == false) continue;
            nptr_t nc = (valid == NULL) ? it->second.next : 
                    nptr_t(Node::ite(valid, it->second.next, it->second.var));
            if (nc == NULL) continue;
            if (doHier) {
                // Create new function for the state update.
                CppFun* singleUpdateFunc = gen->addFun("cppUpdateFun_" + it->first);
                gen->buildFun(singleUpdateFunc, nc);
                gen->setFunReturn(singleUpdateFunc, nc);
                gen->endFun(singleUpdateFunc);
                
                ILA_ASSERT(singleUpdateFunc->retSet(), "return not set succeefully");
                
                // Calculate next value in top function, and update at the end
                CppVar* nxtVal = gen->appFun(singleUpdateFunc, fun);
                gen->addFunUpdate(fun, it->second.var, nxtVal);
            } else {
                gen->buildFun(fun, nc);
                gen->addFunUpdate(fun, it->second.var, nc);
            }
        }
        for (auto it = mems.begin(); it != mems.end(); it++) {
            check = used.insert(it->first);
            if (check.second == false) continue;
            nptr_t nc = (valid == NULL) ? it->second.next : 
                    nptr_t(Node::ite(valid, it->second.next, it->second.var));
            if (nc == NULL) continue;
            if (doHier) {
                // Create new function for the state update.
                CppFun* singleUpdateFunc = gen->addFun("cppUpdateFun_" + it->first);
                gen->buildFun(singleUpdateFunc, nc);
                gen->setFunReturn(singleUpdateFunc, nc);
                gen->endFun(singleUpdateFunc);
                
                ILA_ASSERT(singleUpdateFunc->retSet(), "return not set successfully");
                
                // Calculate next value in top function, and update at the end
                CppVar* nxtVal = gen->appFun(singleUpdateFunc, fun);
                gen->addFunUpdate(fun, it->second.var, nxtVal);
            } else {
                gen->buildFun(fun, nc);
                gen->addFunUpdate(fun, it->second.var, nc);
            }
        }

        // Then next level micro abstraction.
        // No need, we will export separately
        //for (auto it = uabs.begin(); it != uabs.end(); it++) {
        //    it->second.abs->setUpdateToFunction(gen, fun, it->second.valid, doHier);
        //}
    }

}
