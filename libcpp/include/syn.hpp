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
            const Node*, boost::shared_ptr<Node> > expr_map_t;
    protected:
        // the map between old and new nodes.
        expr_map_t exprmap;
        // the model we are examining.
        z3::model& m;
        // the expression converter we are using to evalute the model.
        Z3ExprAdapter& adapter;
        // find the rewritten args.
        void getNewArgs(
            const Node* n, 
            std::vector< boost::shared_ptr<Node> >& args);
    public:
        // Constructor.
        SynRewriter(z3::model& m, Z3ExprAdapter& a);

        // Destructor.
        ~SynRewriter();

        // This is used by depthFirstVisit.
        void operator() (const Node* n);

        // do the rewrite.
        boost::shared_ptr<Node> rewrite(const Node* n);
    };
}

#endif
