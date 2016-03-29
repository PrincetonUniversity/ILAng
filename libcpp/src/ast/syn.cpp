#include <ast.hpp>
#include <smt.hpp>
#include <type.hpp>
#include <ast/syn.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    Choice::Choice(
        const std::vector< boost::shared_ptr<Node> >& args_)
      : args(args_)
    {
    }

    Choice::~Choice()
    {
    }

    NodeType Choice::getChoiceType(
        const std::vector< boost::shared_ptr<Node> >& args)
    {
        if (args.size() <= 1) {
            return NodeType(NodeType::INVALID);
        }
        NodeType r = args[0]->type;
        for (unsigned i=1; i != args.size(); i++) {
            if (args[i]->type != r) {
                return NodeType(NodeType::INVALID);
            }
        }
        return r;
    }

    bool Choice::equal(const Choice& that) const
    {
        if (args.size() != that.args.size()) return false;
        for (unsigned i=0; i != args.size(); i++) {
            if (!args[i]->equal(that.args[i].get())) return false;
        }
        return true;
    }

    std::ostream& Choice::write(std::ostream& out) const
    {
        out << "(choice";
        for (auto arg : args) {
            arg->write(out << " ");
        }
        return (out << ")");
    }

    z3::expr Choice::toZ3(const std::string& name, Z3AdapterI& c) const
    {
        using namespace z3;

        expr vi_ = c.expr(args[0].get());
        for (unsigned i=1; i != args.size(); i++) {
            std::string var("choice." + name + "." + 
                            boost::lexical_cast<std::string>(i));
            expr ci = c.boolVar(var, true);
            expr vi = c.expr(args[i].get());
            expr vi_next = ite(ci, vi, vi_);
            vi_ = vi_next;
        }
        return vi_;
    }

    // ---------------------------------------------------------------------- //
    BitvectorChoice::BitvectorChoice(
        Abstraction* c, const std::string& n_, 
        const std::vector< boost::shared_ptr<Node> >& args_)
      : BitvectorExpr(c, Choice::getChoiceType(args_).bitWidth)
      , choice(args_)
    {
        name = n_;
    }

    BitvectorChoice::~BitvectorChoice()
    {
    }

    Node* BitvectorChoice::clone() const
    {
        return new BitvectorChoice(ctx, name, choice.args);
    }

    bool BitvectorChoice::equal(const Node* that_) const
    {
        const BitvectorChoice* that = 
            dynamic_cast<const BitvectorChoice*>(that_);
        if (that == NULL) return false;
        return choice.equal(that->choice);
    }

    std::ostream& BitvectorChoice::write(std::ostream& out) const
    {
        return choice.write(out);
    }

    z3::expr BitvectorChoice::toZ3(Z3AdapterI& c) const
    {
        return choice.toZ3(name, c);
    }
}

