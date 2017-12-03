#ifndef __SMT_HPP_DEFINED__
#define __SMT_HPP_DEFINED__

#include <z3++.h>
#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <unordered_map>
#include <boost/shared_ptr.hpp>
#include <ast/hash.hpp>

namespace ila 
{
    // A function object that converts nodes into Z3 expressions.
    class Z3ExprAdapter
    {
    public:
        // Define types.
        typedef std::unordered_map<
            const Node*, z3::expr,
            decltype(&nodeHash), decltype(&nodeEqual)> expr_map_t;
        // simplify flag.
        bool simplify;

    protected:
        // These are used during memoization.
        expr_map_t exprmap;
        expr_map_t cnstmap;

        // The underlying Z3 context.
        z3::context& c;
        // The "suffix" (used only for synthesis operators).
        std::string suffix;

        /// Added to every name
        std::string name_suffix;

        // Utility function extracts the Z3 expression corresponding
        // to the i-th argument of the Node n.
        z3::expr _getArg(const expr_map_t& m, const Node* n, int i);
        // This extracts expressions from exprmap.
        z3::expr getArgExpr(const Node* n, int i) {
            return _getArg(exprmap, n, i);
        }
        // This extracts expressions from cnstmap.
        z3::expr getArgCnst(const Node* n, int i) {
            return _getArg(cnstmap, n, i);
        }

        // These functions populate exprmap and cnstmap.
        void _populateExprMap(const Node* n);
        void _populateCnstMap(const Node* n);

        // Convert a boolean variable into a Z3 expression.
        virtual z3::expr getBoolVarExpr(const BoolVar* bv);
        // Convert a boolean op into a Z3 expression.
        virtual z3::expr getBoolOpExpr(const BoolOp* op);
        // for booleans
        virtual z3::expr getChoiceExpr(const BoolChoice* op);

        // Convert a bitvector variable into a Z3 expression.
        virtual z3::expr getBitvectorVarExpr(const BitvectorVar* bvv);
        // Convert a bitvector op into a Z3 expression.
        virtual z3::expr getBvOpExpr(const BitvectorOp* op);
        // Convert a choice op into a Z3 expression. (bitvectors)
        virtual z3::expr getChoiceExpr(const BitvectorChoice* op);
        // Convert a in-range expression to Z3.
        virtual z3::expr getBVInRangeExpr(const BVInRange* op);
        // Constraints for the in-range operator.
        virtual z3::expr getBVInRangeCnst(const BVInRange* op);

        // Convert a memory var into a Z3 expression.
        virtual z3::expr getMemVarExpr(const MemVar* mv);
        // Convert a mem write expression into Z3.
        virtual z3::expr getMemOpExpr(const MemOp* mw);
        // for memories.
        virtual z3::expr getChoiceExpr(const MemChoice* op);

        // Convert a function variable into a Z3 expression.
        virtual z3::expr getFuncVarExpr(const FuncVar* fv);

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
        // As will this.
        z3::expr getCnst(const Node* n);

        // return the context.
        z3::context& ctx() const { return c; }

        // clear the memo.
        void clear() { exprmap.clear(); cnstmap.clear(); }
        
        // Extract a string representation of the numeric value 
        // of node r in the model m.
        std::string extractNumeralString(z3::model& m, const Node* r);
        // Extract the integer value of node r in model m.
        int getNumeralInt(z3::model& m, const Node* r);
        // Extract the arbitrary precision int value of node r in model m.
        mp_int_t getNumeralCppInt(z3::model& m, const Node* r);
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

        void setNameSuffix(const std::string& ns) {name_suffix = ns;}
        const std::string & getNameSuffix() const {return name_suffix;}
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

    class DistInput;

    // The function object we use during synthesis to rewrite expressions.
    class Z3ExprRewritingAdapter : public Z3ExprAdapter 
    {
    protected:
        // The distinguishing input this is based on.
        const DistInput* distInp;
        // Convert a boolean variable into a Z3 expression.
        virtual z3::expr getBoolVarExpr(const BoolVar* bv);
        // Convert a bitvector variable into a Z3 expression.
        virtual z3::expr getBitvectorVarExpr(const BitvectorVar* bvv);
        // Convert a mem var into Z3.
        virtual z3::expr getMemVarExpr(const MemVar* mv);
    public:
        // Constructors.
        Z3ExprRewritingAdapter(
            z3::context& c, 
            const DistInput* di,
            const std::string& suffix);
        Z3ExprRewritingAdapter(
            z3::context& c, 
            const DistInput* di,
            const char* suffix);
        // Destructor.
        ~Z3ExprRewritingAdapter();
        // wrapper over getExpr and getCnst
        z3::expr getIOCnst(const Node* n, const py::object& result);
    };

    class Z3FixedpointAdapter : public Z3ExprAdapter
    {
    public:
        Z3FixedpointAdapter(z3::context& c, const std::string& suffix) :
            Z3ExprAdapter(c, suffix)
        {

        }

        ~Z3FixedpointAdapter() { }
    };
}

#endif
