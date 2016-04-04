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
    class BoolVar;
    class BitvectorVar;
    class BoolOp;
    class BitvectorOp;
    class BitvectorChoice;

    // A function object that converts nodes into Z3 expressions.
    class Z3ExprAdapter
    {
    public:
        // Define types.
        typedef std::unordered_map<const Node*, z3::expr> expr_map_t;

    protected:
        // This is the "memo" used during memoization.
        expr_map_t exprmap;

        // The underlying Z3 context.
        z3::context& c;
        // The "suffix" (used only for synthesis operators).
        std::string suffix;

        // Utility function extracts the Z3 expression corresponding
        // to the i-th argument of the Node n.
        z3::expr getArgExpr(const Node* n, int i);

        // Convert a boolean variable into a Z3 expression.
        virtual z3::expr getBoolVarExpr(const BoolVar* bv);
        // Convert a bitvector variable into a Z3 expression.
        virtual z3::expr getBitvectorVarExpr(const BitvectorVar* bvv);
        // Convert a boolean op into a Z3 expression.
        virtual z3::expr getBoolOpExpr(const BoolOp* op);
        // Convert a bitvector op into a Z3 expression.
        virtual z3::expr getBvOpExpr(const BitvectorOp* op);
        // Convert a choice op into a Z3 expression.
        virtual z3::expr getChoiceExpr(const BitvectorChoice* op);

    public:
        // Constructors.
        Z3ExprAdapter(z3::context& c, const std::string& suffix);
        Z3ExprAdapter(z3::context& c, const char* suffix);
        // Destructor.
        virtual ~Z3ExprAdapter();

        // This is used by depthFirstVisit.
        virtual void operator() (const Node* n);

        // This will call node->depthFirstVisit.
        z3::expr getExpr(const Node* n);
        
        // Extract a string representation of the numeric value 
        // of node r in the model m.
        std::string extractNumeralString(z3::model& m, const Node* r);
        // Extract the integer value of node r in model m.
        int getNumeralInt(z3::model& m, const Node* r);
        // Extract the boolean value of node r in model m.
        bool getBoolValue(z3::model& m, const Node* r);
    };

    // The function object we use during synthesis to rewrite expressions.
    class Z3ExprRewritingAdapter : public Z3ExprAdapter 
    {
    protected:
        // model we will extract from.
        z3::model& m;
        // related expr adapter.
        Z3ExprAdapter& adapter;
        // Convert a boolean variable into a Z3 expression.
        virtual z3::expr getBoolVarExpr(const BoolVar* bv);
        // Convert a bitvector variable into a Z3 expression.
        virtual z3::expr getBitvectorVarExpr(const BitvectorVar* bvv);
    public:
        // Constructors.
        Z3ExprRewritingAdapter(
            z3::context& c, 
            z3::model& m, 
            Z3ExprAdapter& a,
            const std::string& suffix);
        Z3ExprRewritingAdapter(
            z3::context& c, 
            z3::model& m, 
            Z3ExprAdapter& a,
            const char* suffix);
        // Destructor.
        ~Z3ExprRewritingAdapter();
        // wrapper over getExpr
        z3::expr getExpr(const Node* n, const boost::python::object& result);
    };
}

#endif
