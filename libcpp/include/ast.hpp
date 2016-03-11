#ifndef __AST_H_DEFINED__

#include <iostream>
#include <string>
#include <z3++.h>
#include <assert.h>
#include <type.hpp>

namespace ila 
{
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
