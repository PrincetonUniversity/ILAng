#ifndef __AST_H_DEFINED__

#include <iostream>
#include <string>
#include <z3++.h>
#include <assert.h>
#include <type.hpp>

namespace ila 
{
    class Node {
        static int totalObjCnt;
    public:
        // member variables.
        std::string name;
        int id;
        NodeType type;

        // constructor.
        Node(NodeType t) 
          : id(totalObjCnt)
          , type(t) 
        {
            totalObjCnt += 1;
        }

        void doSomething();
    };

    class BitvectorExpr : public Node {
    public:
        BitvectorExpr(int width) 
          : Node(NodeType::getBitvector(width))
        {}
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
