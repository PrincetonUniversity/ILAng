#ifndef __SMT_HPP_DEFINED__
#define __SMT_HPP_DEFINED__

#include <z3++.h>
#include <unordered_map>

namespace ila 
{
    class Node;

    struct Z3AdapterI
    {
        virtual z3::expr expr(Node* obj) = 0;
        virtual z3::context& ctx() = 0;

        virtual z3::expr boolVar(const std::string& name) = 0;
        virtual z3::expr bitvectorVar(const std::string& name, int bitWidth) = 0;
    };

    /*
    class Z3Adapter : public Z3AdapterI
    {
    public:
        // first the types.
        typedef std::unordered_map<Node*, z3::expr> expr_map_t;
    private:
        // now member variables.
        z3::context& c;
        expr_map_t exprmap;
    public:
        Z3Adapter(z3::context& c);
        virtual ~Z3Adapter();

        virtual z3::expr expr(Node* obj);
        virtual z3::context& ctx();
    };
    */
}

#endif
