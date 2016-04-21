#ifndef __CPPSIMGEN_HPP_DEFINED
#define __CPPSIMGEN_HPP_DEFINED

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <boost/shared_ptr.hpp>

namespace ila
{
    // Cpp variable
    class CppVar
    {
        // Variable count.
        static int varCnt;
    private:
        std::string _type;
        std::string _name;
    public:
        // Constructor with fully specified variables.
        CppVar(const std::string& type, const std::string& name);
        // Constructor with only type specified.
        CppVar(const std::string& type);
        // Destructor.
        ~CppVar();

        // Define variable, ex."  int r0"
        std::string def() const;

        // Use variable, ex. " r0"
        std::string use() const;
    };

    class CppFun
    {
        static int funCnt;
    private:
        std::string _type;
        std::string _name;
        std::vector<CppVar> _args;
        std::vector<std::string> _codeList;

    public:
        // Constructor with name specified.
        CppFun(const std::string& type, const std::string& name);
        // Constructor without name specified.
        CppFun(const std::string& type);
        // Destructor.
        ~CppFun();

        // Add argument.
        void addArg(const CppVar& arg);

        // Add body.
        void addBody(const std::string& code);

        // Add loop to body.
        // void addLoop(const std::string& loop);

        // Print the function declaration to the output stream.
        void dumpDef(std::ostream& out) const;
        // Print the code (with body) to output stream.
        void dumpCode(std::ostream& out) const;
    };


    // Cpp simulator generator.
    class CppSimGen
    {
    public: 
        // Define types.
        typedef std::map<std::string, const CppVar*> CppVarMap;
        typedef std::map<std::string, const CppFun*> CppFunMap;

    private:
        // Variables map. May have different name as ila.
        CppVarMap _varMap;
        // Functions map. May have differeny name as ila.
        CppFunMap _funMap;
       
        // Model prefix.
        std::string _prefix;
    public:
        // Constructor.
        CppSimGen(const std::string& prefix);

        // Destructor.
        ~CppSimGen();

        // Create variable and put it in the _varMap.
        const CppVar* addState(const std::string& type, const std::string& name);

        // Create new function and put it in the _funMap.
        const CppFun* addFun(const std::string& type, const std::string& name);
        
        // Build function body with ast node.
        void buildFun(const CppFun* f, nptr_t nptr) const;

    };

}

#endif
