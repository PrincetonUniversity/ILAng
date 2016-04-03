#ifndef __SMT_HPP_DEFINED__
#define __SMT_HPP_DEFINED__

#include <z3++.h>
#include <util.hpp>
#include <exception.hpp>
#include <unordered_map>
#include <boost/shared_ptr.hpp>

namespace ila 
{
    class Node;
    class BoolOp;
    class BitvectorOp;
    class BitvectorChoice;

    // A function object that converts nodes into Z3 expressions.
    class Z3ExprAdapter
    {
        typedef std::unordered_map<const Node*, z3::expr> expr_map_t;
        expr_map_t exprmap;

        z3::context& c;
        std::string suffix;

    protected:
        z3::expr getArgExpr(
            const Node* n, int i);

        virtual z3::expr getBoolOpExpr(
            const BoolOp* op);
        virtual z3::expr getBvOpExpr(
            const BitvectorOp* op);
        virtual z3::expr getChoiceExpr(
            const BitvectorChoice* op);

    public:
        Z3ExprAdapter(z3::context& c, const std::string& suffix);
        Z3ExprAdapter(z3::context& c, const char* suffix);
        ~Z3ExprAdapter();

        // This is used by depthFirstVisit.
        virtual void operator() (const Node* n);

        // This will call node->depthFirstVisit.
        z3::expr getExpr(const Node* n);
        
        // helper functions to get stuff out of the model.
        std::string extractNumeralString(z3::model& m, const Node* r);
        int getNumeralInt(z3::model& m, const Node* r);
        bool getBoolValue(z3::model& m, const Node* r);
    };

}

#endif
