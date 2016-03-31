#ifndef __SMT_HPP_DEFINED__
#define __SMT_HPP_DEFINED__

#include <z3++.h>
#include <exception.hpp>
#include <unordered_map>
#include <boost/shared_ptr.hpp>

namespace ila 
{
    class Node;

    struct Z3AdapterI
    {
        virtual z3::expr expr(Node* obj) = 0;
        virtual z3::context& ctx() = 0;

        virtual z3::expr boolVar(const std::string& name, bool syn) = 0;
        virtual z3::expr bitvectorVar(const std::string& name, int bitWidth, bool syn) = 0;
        virtual std::string extractNumeralString(
                    z3::model& m, boost::shared_ptr<Node>& r) = 0;
        virtual int getNumeralInt(
                    z3::model& m, boost::shared_ptr<Node>& r) = 0;
        virtual bool getBoolValue(
                    z3::model& m, boost::shared_ptr<Node>& r) = 0;
    };

    class Z3Adapter : public Z3AdapterI
    {
    public:
        // first the types.
        typedef std::unordered_map<Node*, z3::expr> expr_map_t;
    private:
        // now member variables.
        z3::context& c;
        expr_map_t exprmap;
        std::string suffix;
    public:
        Z3Adapter(z3::context& c, const std::string& suffix);
        Z3Adapter(z3::context& c, const char* suffix);
        virtual ~Z3Adapter();

        virtual z3::expr expr(Node* obj);
        virtual z3::context& ctx();
        virtual z3::expr boolVar(const std::string& name, bool syn);
        virtual z3::expr bitvectorVar(const std::string& name, int w, bool syn);
        virtual std::string extractNumeralString(
                    z3::model& m, boost::shared_ptr<Node>& r);
        virtual int getNumeralInt(
                    z3::model& m, boost::shared_ptr<Node>& r);
        virtual bool getBoolValue(
                    z3::model& m, boost::shared_ptr<Node>& r);
    };
}

#endif
