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
}
