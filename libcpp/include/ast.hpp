#ifndef __AST_H_DEFINED__

#include <string>

namespace ila 
{
    class Node {
    public:
        enum Type { INVALID, BOOL, BITVECTOR, MEM };
    protected:
        Type nodetype;
        std::string name;
    public:
        void setName(std::string n);
        std::string getName();
    };
}

#endif // __AST_H_DEFINED__
