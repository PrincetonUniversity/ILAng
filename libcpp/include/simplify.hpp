#ifndef __SIMPLIFY_HPP_DEFINED__
#define __SIMPLIFY_HPP_DEFINED__

#include <ast.hpp>
#include <smt.hpp>
#include <vector>

namespace ila
{
    class SimplifyVistor : public NodeVisitorI
    {
        nptr_vec_t assumps;
    public:
        // constructor.
        SimplifyVisitor(const nptr_vec_t& assumps);
        // destructor.
        virtual ~SimplifyVisitor();
        
        void preVisit(const Node* n);
        void postVisit(const Node* n);
    };
}
#endif
