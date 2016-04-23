#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    const std::string MemOp::operatorNames[] = {
        "invalid", "store", "ite"
    };
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
        Abstraction* c, const MemValues& mv)
      : MemExpr(c, mv.type)
      , memvalues(mv)
    {
    }

    MemConst::MemConst(const MemConst& that)
      : MemExpr(that.ctx, that.type.addrWidth, that.type.dataWidth)
      , memvalues(that.memvalues)
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
            return this->memvalues == that->memvalues;
        }
        return false;
    }

    std::ostream& MemConst::write(std::ostream& out) const
    {
        return out << memvalues;
    }

    // ---------------------------------------------------------------------- //
    MemOp::MemOp(Op o, const nptr_t& a0, const nptr_t& a1, const nptr_t& a2)
      : MemExpr(a0->context(), (o == MemOp::STORE ? a0->type : a1->type))
      , op(o)
    {
        ILA_ASSERT(op == MemOp::STORE || op == MemOp::ITE, "Invalid op value.");

        if (op == MemOp::STORE) {
            if (!a0->type.isMem()) {
                throw PyILAException(PyExc_TypeError, 
                    "Memory type error.");
            } else if(!a1->type.isBitvector(a0->type.addrWidth)) {
                throw PyILAException(PyExc_TypeError, 
                    "Address type error.");
            } else if(!a2->type.isBitvector(a0->type.dataWidth)) {
                throw PyILAException(PyExc_TypeError,
                    "Type error in data being written to memory.");
            }
        } else if (op == MemOp::ITE) {
            if (!a0->type.isBool()) {
                throw PyILAException(PyExc_TypeError,
                    "Condition must be a boolean.");
            } else if (!a1->type.isMem() || !a2->type.isMem()) {
                throw PyILAException(PyExc_TypeError,
                    "Two arguments to ite must be memories.");
            } else if (a1->type != a2->type) {
                throw PyILAException(PyExc_TypeError,
                    "ite arguments must have same memory types.");
            }
        }

        args.push_back(a0);
        args.push_back(a1);
        args.push_back(a2);
        ILA_ASSERT(args.size() == 3, "Mem op size mismatch.");
    }

    MemOp::MemOp(const MemOp& that)
      : MemExpr(that.mem->context(), that.type)
      , op(that.op)
      , args(that.args)
    {
        ILA_ASSERT(args.size() == 3, "Mem op size mismatch.");
    }

    MemOp::~MemOp()
    {
    }

    // ---------------------------------------------------------------------- //
    Node* MemOp::clone() const
    {
        return new MemOp(*this);
    }

    bool MemOp::equal(const Node* that_) const
    {
        auto that = dynamic_cast<const MemOp*>(that_);
        if (that) {
            if (that->op != op) return false;
            if (that->args.size() != args.size()) return false;
            for (unsigned i=0; i != args.size(); i++) {
                if (!args[i]->equal(that->args[i].get())) return false;
            }
            return true;
        } else {
            return false;
        }
    }

    std::ostream& MemOp::write(std::ostream& out) const
    {
        out << "(" << operatorNames[op] 
            << " " << *args[0].get()
            << " " << *args[1].get()
            << " " << *args[2].get()
            << ")";
        return out;
    }

    // ---------------------------------------------------------------------- //
    unsigned MemOp::nArgs() const
    {
        return args.size();
    }

    nptr_t MemOp::arg(unsigned i) const
    {
        if (i < args.size()) {
            return args[i];
        } else {
            return NULL;
        }
    }

    // ---------------------------------------------------------------------- //
}
