#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    const std::string MemOp::operatorNames[] = {
        "invalid", "store", "storeblock", "ite"
    };
    // ---------------------------------------------------------------------- //
    MemExpr::MemExpr(int aw, int dw) 
      : Node(NodeType::getMem(aw, dw))
    {
    }

    MemExpr::MemExpr(NodeType t)
      : Node(t)
    {
        ILA_ASSERT(t.isMem(), "BitvectorExpr type mismatch.");
    }

    MemExpr::~MemExpr()
    {
    }

    
    // ---------------------------------------------------------------------- //
    MemVar::MemVar(
        const std::string& n, int aw, int dw)
      : MemExpr(aw, dw)
    {
        this->name = n;
    }

    MemVar::~MemVar()
    {
    }

    // ---------------------------------------------------------------------- //
    Node* MemVar::clone() const
    {
        return new MemVar(this->name, type.addrWidth, type.dataWidth);
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
        const MemValues& mv)
      : MemExpr(mv.type.addrWidth, mv.type.dataWidth)
      , memvalues(mv)
    {
    }

    MemConst::MemConst(const MemConst& that)
      : MemExpr(that.type.addrWidth, that.type.dataWidth)
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
      : MemExpr(o == MemOp::STORE ? a0->type : a1->type)
      , op(o)
      , endian(UNKNOWN_E)
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

    MemOp::MemOp(Op op, const nptr_t& mem, 
                        const nptr_t& addr, 
                        const nptr_t& data,
                        endianness_t e)
      : MemExpr(mem->type.addrWidth, mem->type.dataWidth)
      , op(STOREBLOCK)
      , endian(e)
    {
        ILA_ASSERT(op == STOREBLOCK, "Invalid op.");
        // check memory type //
        if (!mem->type.isMem()) {
            throw PyILAException(PyExc_TypeError, 
                    "First argument must be a memory.");
            return;
        }
        // check address type and width //
        if (!addr->type.isBitvector(mem->type.addrWidth)) {
            throw PyILAException(PyExc_TypeError, 
                    "Invalid address type.");
            return;
        }
        // check data type and width //
        if (!data->type.isBitvector() ||
             data->type.bitWidth % mem->type.dataWidth != 0)
        {
            throw PyILAException(PyExc_TypeError, 
                    "Invalid data type.");
            return;
        }

        args.push_back(mem);
        args.push_back(addr);
        args.push_back(data);
        ILA_ASSERT(args.size() == 3, "Mem op size mismatch.");
        ILA_ASSERT(op != STOREBLOCK || endian != UNKNOWN_E, "endian undefined!");
    }

    MemOp::MemOp(const MemOp& that)
      : MemExpr(that.type.addrWidth, that.type.dataWidth)
      , op(that.op)
      , endian(that.endian)
      , args(that.args)
    {
        ILA_ASSERT(args.size() == 3, "Mem op size mismatch.");
        ILA_ASSERT(op != STOREBLOCK || endian != UNKNOWN_E, "endian undefined!");
    }

    MemOp::MemOp(const MemOp* that, const nptr_vec_t& args)
      : MemExpr(that->type.addrWidth, that->type.dataWidth)
      , op(that->op)
      , endian(that->endian)
      , args(args)
    {
        ILA_ASSERT(args.size() == 3, "Mem op size mismatch.");
        ILA_ASSERT(op != STOREBLOCK || endian != UNKNOWN_E, "endian undefined!");
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
            << " " << *args[2].get();

        if (endian != UNKNOWN_E) {
            out << " #" << (endian == LITTLE_E ? "little-endian"
                                               : "big-endian");
        }
        
        out << ")";
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
