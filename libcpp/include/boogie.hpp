#ifndef __BOOGIE_HPP_DEFINED__
#define __BOOGIE_HPP_DEFINED__

#include <cassert>

#include <unordered_map>
#include <vector>

#include "boost/foreach.hpp"
#include "boost/dynamic_bitset.hpp"
#include "boost/logic/tribool.hpp"
#include <z3++.h>
#include <util.hpp>
#include <stack>

#include <ast.hpp>

namespace ila
{
    class Abstraction;
    class BoogieTranslator
    {
        // pointer to the abstraction we are translating.
        Abstraction* abs;  
        nodeset_t fetchVars;
        nodeset_t constFV, inpFV, varFV;

        // is constant.
        bool isConstant(const npair_t* obj);

        typedef std::stack<nptr_vec_t> states;
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
