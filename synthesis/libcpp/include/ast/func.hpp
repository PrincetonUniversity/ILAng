
#ifndef __AST_FUNC_HPP_DEFINED__
#define __AST_FUNC_HPP_DEFINED__

#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/lexical_cast.hpp>

#include <type.hpp>
#include <ast.hpp>

namespace ila
{
    class Abstraction;

    // ---------------------------------------------------------------------- //
    // Function expression.
    class FuncExpr : public Node {
    public:
        // constructor.
        FuncExpr(int retWidth, const std::vector<int>& argsWidth);
        // constructor for ChoiceExpr. 
        FuncExpr(NodeType t);
        // destructor.
        virtual ~FuncExpr();
    };
    
    // ---------------------------------------------------------------------- //
    // Func variables.
    class FuncVar : public FuncExpr {
    public:
        // constructor.
        FuncVar(const std::string& name, 
                int retWidth, const std::vector<int>& argrsWidth) ;
        // destructor.
        virtual ~FuncVar();
        // clone.
        virtual Node* clone() const;
        // equality method.
        virtual bool equal(const Node* that) const;
        // stream output.
        virtual std::ostream& write(std::ostream& out) const;
    };
}
#endif
