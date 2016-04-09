#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    MemExpr::MemExpr(Abstraction *c, int aw, int dw) 
      : Node(c, NodeType::getMem(aw, dw))
    {
    }

    MemExpr::MemExpr(Abstraction *c, NodeType t)
      : Node(c, t)
    {
        ILA_ASSERT(t.isMem(), "BitvectorExpr type mismatch.");
    }

    MemExpr::~MemExpr()
    {
    }

    
    // ---------------------------------------------------------------------- //
    MemVar::MemVar(
        Abstraction* c, 
        const std::string& n, int aw, int dw)
      : MemExpr(c, aw, dw)
    {
        this->name = n;
    }

    MemVar::~MemVar()
    {
    }

    // ---------------------------------------------------------------------- //
    Node* MemVar::clone() const
    {
        return new MemVar(ctx, this->name, type.addrWidth, type.dataWidth);
    }

    bool MemVar::equal(const Node* that_) const
    {
        auto that = dynamic_cast<const MemVar*>(that_);
        if (that) {
            return that->name == name &&
                   that->type == type;
        } else {
            return false;
        }
    }

    std::ostream& MemVar::write(std::ostream& out) const
    {
        return (out << name);
    }

    // ---------------------------------------------------------------------- //
    MemConst::MemConst(
        Abstraction* c, int aw, int dw, 
        const mp_int_t& v)
      : MemExpr(c, aw, dw)
      , def_value(v)
    {
    }

    MemConst::MemConst(Abstraction* c, int aw, int dw, int v)
      : MemExpr(c, aw, dw)
      , def_value(v)
    {
    }

    MemConst::MemConst(const MemConst& that)
      : MemExpr(that.ctx, that.type.addrWidth, that.type.dataWidth)
      , def_value(that.def_value)
      , mem_values(that.mem_values)
    {
    }

    MemConst::~MemConst()
    {
    }

    // ---------------------------------------------------------------------- //
    Node* MemConst::clone() const
    {
        return new MemConst(*this);
    }

    bool MemConst::equal(const Node* that_) const
    {
        auto that = dynamic_cast<const MemConst*>(that_);
        if (that) {
            if (that->def_value != def_value) return false;
            if (that->mem_values.size() != mem_values.size()) return false;
            for (unsigned i=0; i != mem_values.size(); i++) {
                if (that->mem_values[i] != mem_values[i]) return false;
            }
            return true;
        } else {
            return false;
        }
    }

    std::ostream& MemConst::write(std::ostream& out) const
    {
        bool first = true;
        out << "[";
        for (auto p : mem_values) {
            if (!first) { out << " "; }
            else { first = false; }

            out << std::hex << "0x" << p.first << ": "
                << std::hex << "0x" << p.second;
        }
        out << " default: 0x" << std::hex << def_value << std::dec << "]";
        return out;
    }

    // ---------------------------------------------------------------------- //
    MemWr::MemWr(
        boost::shared_ptr<Node> m,
        boost::shared_ptr<Node> a,
        boost::shared_ptr<Node> d)

      : MemExpr(m->context(), m->type)
      , mem(m)
      , addr(a)
      , data(d)
    {
        if (!m->type.isMem()) {
            throw PyILAException(PyExc_TypeError, 
                "Memory type error.");
        } else if(!addr->type.isBitvector(m->type.addrWidth)) {
            throw PyILAException(PyExc_TypeError, 
                "Address type error.");
        } else if(!data->type.isBitvector(m->type.dataWidth)) {
            throw PyILAException(PyExc_TypeError,
                "Type error in data being written to memory.");
        }
    }

    MemWr::MemWr(const MemWr& that)
      : MemExpr(that.mem->context(), that.type)
      , mem(that.mem)
      , addr(that.addr)
      , data(that.data)
    {
    }

    MemWr::~MemWr()
    {
    }

    // ---------------------------------------------------------------------- //
    Node* MemWr::clone() const
    {
        return new MemWr(*this);
    }

    bool MemWr::equal(const Node* that_) const
    {
        auto that = dynamic_cast<const MemWr*>(that_);
        if (that) {
            return that->mem->equal(mem.get())      &&
                   that->addr->equal(addr.get())    &&
                   that->data->equal(data.get());

        } else {
            return false;
        }
    }

    std::ostream& MemWr::write(std::ostream& out) const
    {
        out << "(wr " << *mem.get() 
            << std::hex << " " << *addr.get()
            << " " << *data.get() 
            << std::dec << ")";
        return out;
    }
}
