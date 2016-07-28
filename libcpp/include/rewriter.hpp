#ifndef __REWRITER_HPP_DEFINED__
#define __REWRITER_HPP_DEFINED__

#include <common.hpp>
#include <ast.hpp>
#include <unordered_map>

namespace ila
{
    typedef std::unordered_map<
        const Node*, nptr_t, 
        decltype(&nodeHash), decltype(&nodeEqual)> rwmap_t;
    // A function object that rewrites the AST according to the result
    // of the synthesis.
    class Rewriter
    {
    public:
        // Define types.
    protected:
        // the map between old and new nodes.
        rwmap_t rwmap;
        // the map which nodes which are equal
        // to the old nodes.
        rwmap_t rweq_map;

        // the pass being performed.
        int pass;


        // find the rewritten args.
        void getNewArgs(const Node* n, nptr_vec_t& args);

        // get the nodes' replacement.
        nptr_t getRepl(const Node* n) const;

        // this is the first pass: populates rweq_map.
        void firstPass(const Node* n);
        // the second pass: copies values from rweq_map to rwmap
        void secondPass(const Node* n);
        // third pass: actual rewriting.
        void thirdPass(const Node* n);
    public:
        // Constructor.
        Rewriter();

        // Destructor.
        ~Rewriter();

        // This is used by depthFirstVisit.
        void operator() (const Node* n);

        // do the rewrite.
        nptr_t rewrite(const Node* n);

        // add a node to be rewritten.
        void addRewrite(const Node* n, const nptr_t& nprime);

    };
}
#endif
