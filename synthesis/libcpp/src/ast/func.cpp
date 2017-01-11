#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
namespace ila
{
    // ---------------------------------------------------------------------- //
    FuncExpr::FuncExpr(int retWidth, const std::vector<int>& argsWidth)
        : Node(NodeType::getFunc(retWidth, argsWidth))
    {
    }

    FuncExpr::FuncExpr(NodeType t)
        : Node(t)
    {
        ILA_ASSERT(t.isFunc(), "FuncExpr type mismatch.");
    }

    FuncExpr::~FuncExpr()
    {
    }

    // ---------------------------------------------------------------------- //
    
    FuncVar::FuncVar(const std::string& name, 
                     int retWidth, const std::vector<int>& argsWidth)
        : FuncExpr(retWidth, argsWidth)
    {
        this->name = name;
    }

    FuncVar::~FuncVar()
    {
    }
    
    // ---------------------------------------------------------------------- //
    Node* FuncVar::clone() const
    {
        return new FuncVar(name, type.bitWidth, type.argsWidth);
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
