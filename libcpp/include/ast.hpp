#ifndef __AST_H_DEFINED__

#include <string>
#include <z3++.h>
#include <assert.h>

namespace ila 
{
    class NodeType { 
        enum Type { INVALID, BOOL, BITVECTOR, MEM } type;
        union { 
            int bitWidth;
            struct {
                int addrWidth;
                int dataWidth;
            };
        };
        NodeType(Type t) 
          : type(BOOL) 
        { 
            assert(type == BOOL); 
        }

        NodeType(Type t, int w)
          : type(BITVECTOR)
          , bitWidth(w) 
        { 
            assert(type == BITVECTOR); 
        }

        NodeType(Type t, int aw, int dw)
          : type(MEM)
          , addrWidth(aw)
          , dataWidth(dw)
        {
            assert(type == MEM);
        }

    };

    class Node {
    protected:
        std::string name;
    public:
        void setName(std::string n);
        std::string getName();
        void doSomething();
    };

    class BitvectorExpr : public Node {
    public:
        BitvectorExpr(int width) {}
        virtual ~BitvectorExpr();
    };

    class BitvectorVar : public BitvectorExpr {
    public:
        BitvectorVar(std::string n, int width) 
          : BitvectorExpr(width)
        {
            this->name = n;
        }

        virtual ~BitvectorVar();
    };

}

#endif // __AST_H_DEFINED__
