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
}

