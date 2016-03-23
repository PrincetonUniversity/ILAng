#ifndef __AST_BOOL_HPP_DEFINED__
#define __AST_BOOL_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <ast.hpp>

namespace ila 
{
    class Abstraction;

    // ---------------------------------------------------------------------- //
    // Boolean expressions are derived from this class.
    class BoolExpr : public Node {
    public:
        // constructor.
        BoolExpr(Abstraction* c);
        // destructor.
        virtual ~BoolExpr();
        // operators.
        /*
        virtual Node* complement() const;
        virtual Node* negate() const;
        virtual Node* logicalNot() const;
        virtual Node* add(boost::shared_ptr<Node> n2) const;
        virtual Node* addInt(int n2) const;
        virtual Node* raddInt(int n2) const;
        virtual Node* sub(boost::shared_ptr<Node> n2) const;
        virtual Node* subInt(int n2) const;
        virtual Node* rsubInt(int n2) const;
        */
    };
}
#endif
