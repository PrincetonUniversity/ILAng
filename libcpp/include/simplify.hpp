#ifndef __SIMPLIFY_HPP_DEFINED__
#define __SIMPLIFY_HPP_DEFINED__

#include <ast.hpp>
#include <smt.hpp>
#include <stack>

namespace ila
{
    class ITESimplifier : public NodeVisitorI
    {
        typedef std::stack<nptr_t> nptr_stack_t;
        nptr_stack_t assumps;
    public:
        // constructor.
        ITESimplifier(const nptr_t& assump);
        // destructor.
        virtual ~ITESimplifier();
        // add a vector of assumption.
        void addAssumptions(const nptr_vec_t& assumps);
        // add exactly one assumption.
        void addAssumption(const nptr_t& a);
        
        virtual void preVisit(const Node* n);
        virtual void postVisit(const Node* n);
    };
}
#endif
