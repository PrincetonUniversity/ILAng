#ifndef __AST_SYN_HPP_DEFINED__
#define __AST_SYN_HPP_DEFINED__

#include <ast.hpp>
#include <type.hpp>
#include <abstraction.hpp>
#include <smt.hpp>

namespace ila 
{
    class Choice {
    protected:
        // the operands themselves.
        std::vector< boost::shared_ptr<Node> > args;
        // is it valid?
        bool valid;
        // vector of names for boolean variables.
        std::vector< std::string > choiceVars;
    public:
        // constructor.
        Choice(const std::string& name, 
               const std::vector< boost::shared_ptr<Node> >& args);
        // destructor.
        ~Choice();
        
        // check types and return the result type.
        static NodeType getChoiceType(
            const std::vector< boost::shared_ptr<Node> >& args);

        // check equality.
        bool equal(const Choice& that) const;

        // dump to stream.
        std::ostream& write(std::ostream& out) const;

        // convert to SMT.
        virtual z3::expr toZ3(const std::string& name, Z3AdapterI& c) const;

        friend class BitvectorChoice;
        friend class BoolChoice;
    };

    class BitvectorChoice : public BitvectorExpr
    {
    protected:
        Choice choice;
    public:
        // constructor.
        BitvectorChoice(
            Abstraction* c, const std::string& name, 
            const std::vector< boost::shared_ptr<Node> >& args_);
        // destructor.
        virtual ~BitvectorChoice();

        // clone.
        virtual Node* clone() const;

        // equality method.
        virtual bool equal(const Node* that) const;

        // stream output.
        virtual std::ostream& write(std::ostream& out) const;

        // convert to an SMT expr.
        virtual z3::expr toZ3(Z3AdapterI& c) const;
    };
}

#endif
