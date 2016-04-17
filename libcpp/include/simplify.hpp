#ifndef __SIMPLIFY_HPP_DEFINED__
#define __SIMPLIFY_HPP_DEFINED__

#include <ast.hpp>
#include <smt.hpp>
#include <vector>

namespace ila
{
    class SimplifyVisitor : public NodeVisitorI
    {
        nptr_vec_t assumps;
    public:
        // constructor.
        SimplifyVisitor(const nptr_vec_t& assumps);
        // destructor.
        virtual ~SimplifyVisitor();
        
        virtual void preVisit(const Node* n);
        virtual void postVisit(const Node* n);
    };
}
#endif
