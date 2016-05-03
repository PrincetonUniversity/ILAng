#include <uinst.hpp>
#include <ast.hpp>
#include <abstraction.hpp>
#include <algorithm>
#include <iterator>

namespace ila
{

    MicroInst::MicroInst(
        Abstraction& a, const std::string& n,
        const nptr_t& v, const nptr_t& f, const nptr_vec_t& decs)

      : abs(a)
      , name(n)
      , valid(v)
      , fetchExpr(f)
      , decodeExprs(decs)
    {
        if (!v->type.isBool()) {
            throw PyILAException(PyExc_TypeError, "Valid must boolean.");
        }
        if (!f->type.isBitvector()) {
            throw PyILAException(PyExc_TypeError, "Type of fetch must be bitvector.");
        }
        for (auto&& d : decodeExprs) {
            if (!d->type.isBool()) {
                throw PyILAException(PyExc_TypeError,
                    "Type of each decode expression must be boolean.");
            }
        }
    }

    MicroInst::~MicroInst()
    {
    }

    // ---------------------------------------------------------------------- //
    UInstWrapper::UInstWrapper()
      : uinst(nullptr)
    {
    }

    UInstWrapper::UInstWrapper(MicroInst* inst)
      : uinst(inst)
    {
    }

    UInstWrapper::UInstWrapper(const microinst_ptr_t& ui)
      : uinst(ui)
    {
    }

    UInstWrapper::~UInstWrapper()
    {
    }

    // ---------------------------------------------------------------------- //
    std::string UInstWrapper::getName() const
    {
        return uinst->name;
    }

    // ---------------------------------------------------------------------- //
    NodeRef* UInstWrapper::getValid() const
    {
        return new NodeRef(uinst->valid);
    }

    void UInstWrapper::setValid(NodeRef* nr)
    {
        const nptr_t& n(nr->node);
        if (!n->type.isBool()) {
            throw PyILAException(PyExc_TypeError, "Valid must be boolean.");
            return;
        }
        uinst->valid = n;
    }

    // ---------------------------------------------------------------------- //
    NodeRef* UInstWrapper::getFetch() const
    {
        return new NodeRef(uinst->fetchExpr);
    }

    void UInstWrapper::setFetch(NodeRef* nr)
    {
        const nptr_t& n(nr->node);
        if (!n->type.isBitvector()) {
            throw PyILAException(PyExc_TypeError, "Opcode must be a bitvector.");
            return;
        }
        uinst->fetchExpr = n;
    }

    // ---------------------------------------------------------------------- //
    py::list UInstWrapper::getDecode() const
    {
        py::list l;
        for (auto&& d : uinst->decodeExprs) {
            NodeRef* di = new NodeRef(d);
            l.append(di);
        }
        return l;
    }

    void UInstWrapper::setDecode(const py::list& decs)
    {
        // check type and insert into decvec.
        unsigned sz = py::len(decs);
        nptr_vec_t decvec;
        for (unsigned i=0; i != sz; i++) {
            py::extract<NodeRef&> ni_(decs[i]);
            if (ni_.check()) {
                NodeRef& ni(ni_());
                if (!ni.node->type.isBool()) {
                    throw PyILAException(PyExc_TypeError,
                        "Decode expressions must all be boolean.");
                    return;
                }
                decvec.push_back(ni.node);
            }
        }
        // all good if we got here.
        uinst->decodeExprs.clear();
        std::copy(decvec.begin(), decvec.end(), std::back_inserter(uinst->decodeExprs));
    }
    // ---------------------------------------------------------------------- //
    NodeRef* MicroInst::addBit(const std::string& name)
    {
        if(!checkAndInsertName(name)) return NULL;
        NodeRef* n = new NodeRef(new ila::BoolVar(&abs, name));
        bits.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    NodeRef* MicroInst::addReg(const std::string& name, int width)
    {
        if(!checkAndInsertName(name)) return NULL;
        NodeRef* n = new NodeRef(new ila::BitvectorVar(&abs, name, width));
        regs.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    NodeRef* MicroInst::addMem(const std::string& name, int aw, int dw)
    {
        if(!checkAndInsertName(name)) return NULL;
        NodeRef* n = new NodeRef(new ila::MemVar(&abs, name, aw, dw));
        mems.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    NodeRef* MicroInst::addFun(const std::string& name, 
                                 int retW, const py::list& l)
    {
        if (!checkAndInsertName(name)) return NULL;
        std::vector<int> argW;
        unsigned sz = py::len(l);
        for (unsigned i=0; i != sz; i++) {
            py::extract<int> ni_(l[i]);
            if (ni_.check()) {
                argW.push_back(ni_);
            }
        }

        NodeRef* n = new NodeRef(new ila::FuncVar(&abs, name, retW, argW));
        funs.insert({name, npair_t(n->node, NULL)});
        return n;
    }

    // ---------------------------------------------------------------------- //
    NodeRef* MicroInst::getBit(const std::string& name)
    {
        return getVar(bits, name);
    }

    NodeRef* MicroInst::getReg(const std::string& name)
    {
        return getVar(regs, name);
    }

    NodeRef* MicroInst::getMem(const std::string& name)
    {
        return getVar(mems, name);
    }

    NodeRef* MicroInst::getFun(const std::string& name)
    {
        return getVar(funs, name);
    }

    // ---------------------------------------------------------------------- //
    NodeRef* MicroInst::getVar(const nmap_t& m, const std::string& n)
    {
        auto pos = m.find(n);
        if (pos == m.end()) {
            throw PyILAException(PyExc_IndexError, "Unable to find: " + n);
            return NULL;
        } else {
            return new NodeRef(pos->second.var);
        }
    }

    void MicroInst::addVar(nmap_t& m, nptr_t& n)
    {
        auto pos = m.find(n->name);
        if (pos == m.end() && names.find(n->name) == names.end()) {
            npair_t np(n, NULL);
            m.insert({n->name, np});
            names.insert(n->name);
        } else {
            if (pos == m.end() || pos->second.var->type != n->type) {
                throw PyILAException(PyExc_TypeError,
                    "Type mismatch of new node: " + n->name +
                    " with existing node of the same name.");
            }
        }
    }

    void MicroInst::addVar(nptr_t& n)
    {
        const BoolVar* boolvar = NULL;
        const BitvectorVar* bvvar = NULL;
        const MemVar* memvar = NULL;
        const FuncVar* funcvar = NULL;

        if ((boolvar = dynamic_cast<const BoolVar*>(n.get()))) {
            addVar(bits, n);
        } else if ((bvvar = dynamic_cast<const BitvectorVar*>(n.get()))) {
            addVar(regs, n);
        } else if ((memvar = dynamic_cast<const MemVar*>(n.get()))) {
            addVar(mems, n);
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n.get()))) {
            addVar(funs, n);
        }
    }

    // ---------------------------------------------------------------------- //
    void MicroInst::setNext(const std::string& name, NodeRef* n)
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

    NodeRef* MicroInst::getNext(const std::string& name) const
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
    bool MicroInst::checkAndInsertName(const std::string& name)
    {
        if (names.find(name) != names.end()) {
            throw PyILAException(PyExc_RuntimeError,
                "Variable with this name already exists.");
            return false;
        }
        names.insert(name);
        return true;
    }

    // ---------------------------------------------------------------------- //
}

