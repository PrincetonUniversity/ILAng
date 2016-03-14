#ifndef __AST_H_DEFINED__

#include <iostream>
#include <string>
#include <z3++.h>
#include <assert.h>
#include <type.hpp>

namespace ila 
{
    class Node {
    public:
        // member variables.
        std::string name;
        NodeType type;

        // constructor.
        Node(NodeType t) : type(t) {}

        void setName(std::string n);
        std::string getName();
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
