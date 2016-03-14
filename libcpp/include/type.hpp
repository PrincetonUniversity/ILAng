#ifndef __TYPE_HPP_DEFINED__
#define __TYPE_HPP_DEFINED__

#include <iostream>
#include <string>
#include <assert.h>

namespace ila {
    // Class for types of nodes.
    struct NodeType { 
        enum Type { INVALID, BOOL, BITVECTOR, MEM } type;
        union { 
            int bitWidth;
            struct {
                int addrWidth;
                int dataWidth;
            };
        };

        // default constructor.
        NodeType() : type(INVALID) { }
        // construct a bool.
        NodeType(Type t);
        // construct a bitvector.
        NodeType(Type t, int w);
        // construct a memory.
        NodeType(Type t, int aw, int dw);

        bool operator! (void) const;
    };

    // stream output operator, required for boost::lexical_cast<>
    std::ostream& operator<<(std::ostream& out, NodeType const& ntype);
}

#endif // __TYPE_HPP_DEFINED__
