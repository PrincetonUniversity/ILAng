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
        return c.bool_const(name.c_str());
    }

    z3::expr Z3Adapter::bitvectorVar(const std::string& n_, int w, bool syn)
    {
        std::string name(syn ? (n_ + suffix) : n_);
        return c.bv_const(name.c_str(), w);
    }

    std::string Z3Adapter::extractNumeralString(
        z3::model& m,
        boost::shared_ptr<Node>& r
    )
    {
        using namespace z3;

        z3::expr r_e = this->expr(r.get());
        z3::expr m_e = m.eval(r_e, true);
        std::string s_e(Z3_get_numeral_string(ctx(), m_e));
        return s_e;
    }

    int Z3Adapter::getNumeralInt(
        z3::model& m,
        boost::shared_ptr<Node>& r
    )
    {
        using namespace z3;

        z3::expr r_e = this->expr(r.get());
        z3::expr m_e = m.eval(r_e, true);
        int i_e;

        Z3_bool success = Z3_get_numeral_int(ctx(), m_e, &i_e);
        if (success != Z3_TRUE) {
            throw PyILAException(PyExc_RuntimeError,
                                "Unable to extract int from model.");
        }
        return i_e;
    }

    bool Z3Adapter::getBoolValue(
        z3::model& m,
        boost::shared_ptr<Node>& r
    )
    {
        using namespace z3;
        z3::expr r_e = this->expr(r.get());
        z3::expr m_e = m.eval(r_e, true);
        Z3_lbool b_e = Z3_get_bool_value(ctx(), m_e);
        if (b_e == Z3_L_UNDEF) {
            throw PyILAException(PyExc_RuntimeError,
                                 "Unable to extract bool from model.");
        }
        return b_e == Z3_L_TRUE;
    }

}
