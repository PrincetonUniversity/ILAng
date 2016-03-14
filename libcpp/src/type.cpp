#include <type.hpp>
#include <exception.hpp>

namespace ila
{
    // stream output operator, required for boost::lexical_cast<>
    std::ostream& operator<<(std::ostream& out, NodeType const& ntype)
    {
        switch(ntype.type) {
        case NodeType::BOOL:
            out << "(type bool)";
            break;
        case NodeType::BITVECTOR:
            out << "(type bitvector " << ntype.bitWidth << ")";
            break;
        case NodeType::MEM:
            out << "(type mem " << ntype.addrWidth << " "
                << ntype.dataWidth << ")";
            break;
        default:
            out << "(type invalid)";
            break;
        }
        return out;
    }

    // constructor (bool).
    NodeType::NodeType(Type t) : type(BOOL) 
    { 
        if (t != BOOL) {
            throw PyILAException(PyExc_TypeError, "Invalid type argument in constructor for Type.");
        }
    }

    // constructor (bitvector).
    NodeType::NodeType(Type t, int w)
      : type(BITVECTOR)
      , bitWidth(w) 
    { 
        if (t != BITVECTOR) {
            throw PyILAException(PyExc_TypeError, "Invalid type argument in constructor for Type.");
        }
        if (w <= 0) {
            throw PyILAException(PyExc_TypeError, "Invalid bitvector width argument.");
        }
    }

    // constructor (mem).
    NodeType::NodeType(Type t, int aw, int dw)
      : type(MEM)
      , addrWidth(aw)
      , dataWidth(dw)
    {
        if (t != MEM) {
            throw PyILAException(PyExc_TypeError, "Invalid type argument in constructor for Type.");
        }
        if (aw <= 0 || dw <= 0) {
            throw PyILAException(PyExc_TypeError, "Invalid bitvector width argument.");
        }
    }

    // constructor (operator!).
    bool NodeType::operator! (void) const
    {
        if (type == INVALID) {
            return true;
        } else {
            return false;
        }
    }
}
