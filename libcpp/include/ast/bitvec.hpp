
#ifndef __AST_BITVEC_HPP_DEFINED__
#define __AST_BITVEC_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <ast.hpp>

namespace ila 
{
    class BitvectorExpr : public Node {
    public:
        BitvectorExpr(int width) 
          : Node(NodeType::getBitvector(width))
        {}
        virtual ~BitvectorExpr();
    };

    class BitvectorVar : public BitvectorExpr {
    public:
        // constructor.
        BitvectorVar(std::string n, int width) 
          : BitvectorExpr(width)
        {
            this->name = n;
        }

        // destructor.
        virtual ~BitvectorVar();

        // clone.
        virtual Node* clone() const;

        // operators.
        virtual Node* complement() const;
    };

    class BitvectorOp : public BitvectorExpr {
    public:
        // Number of operands.
        enum Arity { UNARY, BINARY, TERNARY } arity; 

        // What is the operation?
        enum Op { 
            // unary
            NEGATE, COMPLEMENT, LNOT, NONZERO,  
            // binary.
            ADD, SUB, AND, OR, XOR, XNOR, NAND, NOR,
            // ternary
            IF
        } op;

        // the operands themselves.
        std::vector< std::unique_ptr<Node> > args;

        // Don't forget to update these helper functions below.
        static bool isUnary(Op op) { return op >= NEGATE && op <= NONZERO; }
        static bool isBinary(Op op) { return op >= ADD && op <= NOR; }
        static bool isTernary(Op op) { return op >= IF && op <= IF; }
        static int getUnaryResultWidth(Op op, const Node& n);
        static bool checkUnaryOpWidth(Op op, const Node& n, int width);

        // constructors.
        BitvectorOp(Op op, const Node& n1);
        BitvectorOp(Op op, const Node& n1, const Node& n2);

        // destructors.
        virtual ~BitvectorOp();

        // clone.
        virtual Node* clone() const;
    };
}
#endif
