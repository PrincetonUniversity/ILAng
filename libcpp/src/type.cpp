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
    NodeType::NodeType(Type t) : type(BOOL), bitWidth(0), addrWidth(0), dataWidth(0)
    { 
        if (t != BOOL) {
            throw PyILAException(PyExc_TypeError, "Invalid type argument in constructor for Type.");
        }
    }

    // constructor (bitvector).
    NodeType::NodeType(Type t, int w)
      : type(BITVECTOR)
      , bitWidth(w) 
      , addrWidth(0)
      , dataWidth(0)
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
      , bitWidth(0)
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

    // constructor (func)
    NodeType::NodeType(Type t, int rw, std::vector<int>& aw)
        : type(FUNC)
        , bitWidth(rw)
        , addrWidth(0)
        , dataWidth(0)
        , argsWidth(aw)
    {
        if (t != FUNC) {
            throw PyILAException(PyExc_TypeError, "Invalid type argument in constructor for Type.");
        }
        if (rw <= 0) {
            throw PyILAException(PyExc_TypeError, "Invalid bitvector width argument.");
        }
        for (unsigned i = 0; i != aw.size(); i++) {
            if (aw[i] <= 0) {
                throw PyILAException(PyExc_TypeError, "Invalid bitvector width argument.");
            }
    }

    // operator!
    bool NodeType::operator! (void) const
    {
        if (type == INVALID) {
            return true;
        } else {
            return false;
        }
    }

    bool NodeType::operator==(const NodeType& t) const
    {
        if (type == BOOL && t.type == BOOL) {
            return true;
        } else if (type == BITVECTOR && t.type == BITVECTOR) {
            return bitWidth == t.bitWidth;
        } else if (type == MEM && t.type == MEM) {
            return addrWidth == t.addrWidth &&
                   dataWidth == t.dataWidth;
        } else {
            return false;
        }
    }

    // static helper construction functions.
    NodeType NodeType::getBool() { return NodeType(BOOL); }
    NodeType NodeType::getBitvector(int w) { return NodeType(BITVECTOR, w); }
    NodeType NodeType::getMem(int aw, int dw) { return NodeType(MEM, aw, dw); }
}
