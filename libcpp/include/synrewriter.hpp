#ifndef __SYN_HPP_DEFINED__
#define __SYN_HPP_DEFINED__

#include <ast.hpp>
#include <smt.hpp>

namespace ila
{
    // A function object that rewrites the AST according to the result
    // of the synthesis.
    class SynRewriter
    {
    public:
        // Define types.
        typedef std::unordered_map<
            const Node*, nptr_t,
            decltype(&nodeHash),
            decltype(&nodeEqual)> expr_map_t;
    protected:
        // the map between old and new nodes.
        expr_map_t exprmap;
        // the model we are examining.
        z3::model& m;
        // the expression converter we are using to evalute the model.
        Z3ExprAdapter& adapter;
        // find the rewritten args.
        void getNewArgs(const Node* n, nptr_vec_t& args);
    public:
        // Constructor.
        SynRewriter(z3::model& m, Z3ExprAdapter& a);

        // Destructor.
        ~SynRewriter();

        // This is used by depthFirstVisit.
        void operator() (const Node* n);

        // do the rewrite.
        nptr_t rewrite(const Node* n);
    private:
        template<typename T> 
        void _synChoiceExpr(const ChoiceExpr<T>* op)
        {
            int i = (int) op->nArgs() - 2;
            ILA_ASSERT(i >= 0, "Choice has too few args!");
            for (; i >= 0; i--) {
                bool ci = adapter.getChoiceBool<T>(m, op, i);
                if (ci) { break; }
            }
            nptr_vec_t args;
            getNewArgs(op, args);
            nptr_t nptr = args[i+1];
            // nptr->write(std::cout << "expr: ") << std::endl;
            exprmap.insert({(Node*)op, nptr});
        }
    };
}

#endif
