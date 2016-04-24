#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
namespace ila
{
    // ---------------------------------------------------------------------- //
    FuncExpr::FuncExpr(Abstraction* c, int argNum, std::vector<int> argsWidth)
        : Node(c, NodeType::getFunc(argNum, argsWidth))
    {
    }

    FuncExpr::FuncExpr(Abstraction* c, NodeType t)
        : Node(c, t)
    {
        ILA_ASSERT(t.isFunc(), "FuncExpr type mismatch.");
    }

    FuncExpr::~FuncExpr()
    {
    }

    // ---------------------------------------------------------------------- //
    
    FuncVar::FuncVar(Abstraction* c, const std::string& name, 
                     int argNum, std::vector<int> argsWidth)
        : FuncExpr(c, argNum, argsWidth)
    {
        this->name = name;
    }

    FuncVar::~FuncVar()
    {
    }
    
    // ---------------------------------------------------------------------- //
    Node* FuncVar::clone() const
    {
        return new FuncVar(ctx, name, type.bitWidth, type.argsWidth);
    }

    bool FuncVar::equal(const Node* that_) const
    {
        const FuncVar* that = dynamic_cast<const FuncVar*>(that_);
        if (that != NULL) {
            return that->type == this->type &&
                that->name == this->name;
        } else {
            return false;
        }
    }

    std::ostream& FuncVar::write(std::ostream& out) const
    {
        return (out << name);
    }

}
