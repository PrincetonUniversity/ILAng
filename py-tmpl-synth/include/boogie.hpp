#ifndef __BOOGIE_HPP_DEFINED__
#define __BOOGIE_HPP_DEFINED__

#include <cassert>

#include <unordered_map>
#include <vector>
#include <memory>

#include "boost/foreach.hpp"
#include "boost/dynamic_bitset.hpp"
#include "boost/logic/tribool.hpp"
#include <z3++.h>
#include <util.hpp>
#include <stack>
#include <smt.hpp>

#include <ast.hpp>

namespace ila
{
    class Abstraction;

    class BoogieTranslator
    {
    public:
        typedef std::vector<z3::expr> exprvec_t;
        typedef std::stack<exprvec_t> stack_t;
    private:
        // pointer to the abstraction we are translating.
        Abstraction* abs;  
        nodeset_t fetchVars;
        nodevec_t inpFV, varFV, constFV;
        exprvec_t constEx;

        // stack.
        stack_t states;

        // SMT.
        z3::context c_;
        Z3ExprAdapter c;

        // is constant.
        bool isConstant(const npair_t* obj);

    public:
        // constructor.
        BoogieTranslator(Abstraction* a);
        // destructor.
        virtual ~BoogieTranslator();
        // convert to boogie.
        void translate();
    };
}


#endif /* __BOOGIE_HPP_DEFINED__ */
