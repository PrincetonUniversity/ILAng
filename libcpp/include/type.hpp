#ifndef __TYPE_HPP_DEFINED__
#define __TYPE_HPP_DEFINED__

#include <iostream>
#include <string>
#include <assert.h>

namespace ila {
    // Class for types of nodes.
    struct NodeType { 
        enum Type { INVALID, BOOL, BITVECTOR, MEM } type;
        int bitWidth;
        int addrWidth;
        int dataWidth;

        // default constructor.
        NodeType() : type(INVALID), bitWidth(0) { }
        // construct a bool.
        NodeType(Type t);
        // construct a bitvector.
        NodeType(Type t, int w);
        // construct a memory.
        NodeType(Type t, int aw, int dw);

        bool operator! (void) const;

        // Is this a bool?
        bool isBool() const {
            return type == BOOL;
        }
        // Is this a bitvector with the specified width?
        bool isBitvector(int width) const {
            return type == BITVECTOR && bitWidth == width;
        }
        // Is this a memory with the correct dimensions?
        bool isMem(int aw, int dw) const {
            return type == MEM && addrWidth == aw && dataWidth == dw;
        }

        bool operator==(const NodeType& t) const;

        // static helper construction functions.
        static NodeType getBool();
        static NodeType getBitvector(int w);
        static NodeType getMem(int aw, int dw);
    };

    // stream output operator, required for boost::lexical_cast<>
    std::ostream& operator<<(std::ostream& out, NodeType const& ntype);
}

#endif // __TYPE_HPP_DEFINED__
