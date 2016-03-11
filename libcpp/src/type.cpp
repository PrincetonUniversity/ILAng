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

    NodeType::NodeType(Type t) : type(BOOL) 
    { 
        if (t != BOOL) {
            throw PyILAException(PyExc_ValueError, "Invalid type in constructor.");
        }
    }
}
