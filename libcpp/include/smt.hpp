#ifndef __SMT_HPP_DEFINED__
#define __SMT_HPP_DEFINED__

#include <z3++.h>
#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <unordered_map>
#include <boost/shared_ptr.hpp>

namespace ila 
{
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
        // Convert a choice op into a Z3 expression. (bitvectors)
        virtual z3::expr getChoiceExpr(const BitvectorChoice* op);
        // for booleans
        virtual z3::expr getChoiceExpr(const BoolChoice* op);

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
        // Return the value of the ith choice boolean
        template<typename T>
        bool getChoiceBool(z3::model& m, const ChoiceExpr<T>* op, int i)
        {
            using namespace z3;
            std::string name = op->getChoiceVarName(i) + suffix;
            expr ci = c.bool_const(name.c_str());
            z3::expr mi = m.eval(ci, true);
            Z3_lbool bi = Z3_get_bool_value(c, mi);
            ILA_ASSERT(bi != Z3_L_UNDEF, "Unable to extract bool from model.");
            return bi == Z3_L_TRUE;
        }
    private:
        // Helper to convert choices into z3 expressions.
        template<typename T>
        z3::expr _getChoiceExpr(const ChoiceExpr<T>* op)
        {
            using namespace z3;

            expr vi_ = getArgExpr(op, 0);
            unsigned nargs = op->nArgs();
            for (unsigned i=1; i != nargs; i++) {
                std::string name = op->getChoiceVarName(i-1) + suffix;
                expr ci = c.bool_const(name.c_str());
                expr vi = getArgExpr(op, i);
                expr vi_next = ite(ci, vi, vi_);
                vi_ = vi_next;
            }
            return vi_;
        }

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
