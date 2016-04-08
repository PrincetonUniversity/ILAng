#include <ast.hpp>
#include <util.hpp>

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
    MemExpr* MemExpr::store(const mp_int_t& a, const mp_int_t& d) const
    {
        return new MemWr(*this, a, d);
    }

    MemExpr* MemExpr::store(int a, int d) const
    {
        return store(mp_int_t(a), mp_int_t(d));
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
    MemRd::MemRd(const MemExpr& m, const mp_int_t& a)
      : BitvectorExpr(m.context(), NodeType::getBitvector(mem.type.dataWidth))
      , mem(m)
      , addr(a)
    {
    }

    MemRd::MemRd(const MemRd& that)
      : BitvectorExpr(that.context(), that.type)
      , mem(that.mem)
      , addr(that.addr)
    {
    }

    MemRd::~MemRd()
    {
    }

    // ---------------------------------------------------------------------- //
    Node* MemRd::clone() const
    {
        return new MemRd(*this);
    }

    bool MemRd::equal(const Node* that_) const
    {
        auto that = dynamic_cast<const MemRd*>(that_);
        if (that) {
            return that->mem.equal(&mem) && that->addr == addr;
        } else {
            return false;
        }
    }

    std::ostream& MemRd::write(std::ostream& out) const
    {
        return out << "(rd " << mem << " " << addr << ")";
    }

    // ---------------------------------------------------------------------- //
    MemWr::MemWr(const MemExpr& m, int a, int d)
      : MemExpr(mem.context(), mem.type)
      , mem(m)
      , addr(a)
      , data(d)
    {
    }

    MemWr::MemWr(
        const MemExpr& m, 
        const mp_int_t& a, 
        const mp_int_t& d)

      : MemExpr(mem.context(), mem.type)
      , mem(m)
      , addr(a)
      , data(d)
    {
    }

    MemWr::MemWr(const MemWr& that)
      : MemExpr(that.mem.context(), that.type)
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
            return that->mem.equal(&mem) &&
                   that->addr == addr    &&
                   that->data == data;

        } else {
            return false;
        }
    }

    std::ostream& MemWr::write(std::ostream& out) const
    {
        out << "(wr " << mem << std::hex << " " << addr 
            << " " << data << std::dec << ")";
        return out;
    }
}
