#ifndef __TYPE_HPP_DEFINED__
#define __TYPE_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

namespace ila {
    // Class for types of nodes.
    struct NodeType { 
        enum Type { INVALID, BOOL, BITVECTOR, MEM, FUNC } type;
        int bitWidth;
        int addrWidth;
        int dataWidth;
        std::vector<int> argsWidth;
        size_t hash_val;

        // default constructor.
        NodeType() : type(INVALID), bitWidth(0) { }
        // construct a bool.
        NodeType(Type t);
        // construct a bitvector.
        NodeType(Type t, int w);
        // construct a memory.
        NodeType(Type t, int aw, int dw);
        // construct a func.
        NodeType(Type t, int rw, const std::vector<int>& aw);

        bool operator! (void) const;

        // Is this a bool?
        bool isBool() const {
            return type == BOOL;
        }
        // Is this a bitvector with the specified width?
        // -1 means any width.
        bool isBitvector(int width = -1) const {
            return 
                type == BITVECTOR && 
                (bitWidth == width || width == -1);
        }
        // Is this a memory with the correct dimensions?
        bool isMem(int aw = -1, int dw = -1) const {
            return 
                (type == MEM)                   && 
                (aw == -1 || addrWidth == aw)   && 
                (dw == -1 || dataWidth == dw);
        }

        // Is this a func with the correct dimensions?
        bool isFunc(int rw = -1, std::vector<int> aw = {}) const {
            if (type != FUNC) { 
                return false; 
            } else if (rw == -1) {
                return true;
            } else if (aw.size() != argsWidth.size()){
                return false;
            } else if (rw == bitWidth) {
                for (unsigned i = 0; i != aw.size(); i++) {
                    if (aw[i] != argsWidth[i]) { return false; }
                }
            }
            return true;
        }

        bool operator==(const NodeType& t) const;
        bool operator!=(const NodeType& t) const {
            return !operator==(t);
        }

        // static helper construction functions.
        static NodeType getBool();
        static NodeType getBitvector(int w);
        static NodeType getMem(int aw, int dw);
        static NodeType getFunc(int rw, const std::vector<int>& aw);
    };

    // stream output operator, required for boost::lexical_cast<>
    std::ostream& operator<<(std::ostream& out, NodeType const& ntype);
}

#endif // __TYPE_HPP_DEFINED__
