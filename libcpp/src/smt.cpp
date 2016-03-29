#include <smt.hpp>
#include <ast.hpp>

namespace ila
{
    Z3Adapter::Z3Adapter(z3::context& c_, const std::string& s_)
      : c(c_)
      , suffix(s_)
    {
    }

    Z3Adapter::Z3Adapter(z3::context& c_, const char* s_)
      : c(c_)
      , suffix(s_)
    {
    }

    Z3Adapter::~Z3Adapter()
    {
    }

    z3::expr Z3Adapter::expr(Node* obj)
    {
        auto pos = exprmap.find(obj);
        if (pos == exprmap.end()) {
            z3::expr e = obj->toZ3(*this);
            exprmap.insert({obj, e});
            return e;
        } else {
            return pos->second;
        }
    }

    z3::context& Z3Adapter::ctx()
    {
        return c;
    }

    z3::expr Z3Adapter::boolVar(const std::string& n_, bool syn)
    {
        std::string name(syn ? (n_ + suffix) : n_);
        return c.bool_const(n_.c_str());
    }

    z3::expr Z3Adapter::bitvectorVar(const std::string& n_, int w, bool syn)
    {
        std::string name(syn ? (n_ + suffix) : n_);
        return c.bv_const(n_.c_str(), w);
    }
}
