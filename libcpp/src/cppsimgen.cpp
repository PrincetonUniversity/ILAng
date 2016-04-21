#include <cppsimgen.hpp>
#include <boost/lexical_cast.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    int CppVar::varCnt = 0;

    // ---------------------------------------------------------------------- //
    CppVar::CppVar(const std::string& type, const std::string& name)
        : _type(type)
        , _name(name)
    {
    }

    CppVar::CppVar(const std::string& type)
        : _type(type)
    {
        _name = "cppVar_" + boost::lexical_cast<std::string>(varCnt++);
    }

    CppVar::~CppVar()
    {
    }

    // ---------------------------------------------------------------------- //
    std::string CppVar::def() const
    {
        return (" " + _type + " " + _name);
    }

    std::string CppVar::use() const
    {
        return (" " + _name);
    }

    // ---------------------------------------------------------------------- //
    int CppFun::funCnt = 0;

    // ---------------------------------------------------------------------- //
    CppFun::CppFun(const std::string& type, const std::string& name) 
        : _type(type)
        , _name(name)
    {
    }

    CppFun::CppFun(const std::string& type)
        : _type(type)
    {
        _name = "cppFun_" + boost::lexical_cast<std::string>(funCnt++);
    }

    CppFun::~CppFun()
    {
    }

    // ---------------------------------------------------------------------- //
    void CppFun::addArg(const CppVar& arg)
    {
        // TODO
    }

    void CppFun::addBody(const std::string& code)
    {
        // TODO
    }
        
    // ---------------------------------------------------------------------- //
    void CppFun::dumpDef(std::ostream& out) const
    {
        // TODO
    }

    void CppFun::dumpCode(std::ostream& out) const
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    CppSimGen::CppSimGen(const std::string& prefix)
        : _prefix(prefix)
    {
    }

    CppSimGen::~CppSimGen()
    {
    }

    // ---------------------------------------------------------------------- //
    const CppVar* CppSimGen::addState(const std::string& type,
                                      const std::string& name)
    {
        // TODO
        return NULL;
    }

    const CppFun* CppSimGen::addFun(const std::string& type,
                                    const std::string& name)
    {
        // TODO
        return NULL;
    }

    void CppSimGen::buildFun(const CppFun* f, nptr_t nptr) const
    {
        // TODO
    }

        


}
