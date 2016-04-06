#include <ast.hpp>
#include <type.hpp>
#include <ast/choice.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    Choice::Choice(
        const std::string& name,
        const std::vector< boost::shared_ptr<Node> >& args_)
      : args(args_)
    {
        for (unsigned i=1; i != args.size(); i++) {
            std::string var("choice." + name + "." + 
                            boost::lexical_cast<std::string>(i));
            choiceVars.push_back(var);
        }
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
    // ---------------------------------------------------------------------- //
}

