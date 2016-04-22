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
        static std::string boolStr;
        static std::string bvStr;
        static std::string ubvStr;
        static std::string memStr;

    private:
        std::string _type;
        std::string _name;
        int _width;
    public:
        // Constructor with fully specified variables.
//        CppVar(const std::string& type, const std::string& name);
        // Constructor with only type specified.
//        CppVar(const std::string& type);
        // Constructor with nptr_t
        CppVar(nptr_t nptr);
        // Constructor with Node*
        CppVar(const Node* node);
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
        std::vector<const CppVar*> _args;
        std::vector<std::string> _codeList;

    public:
        // Constructor with name specified.
        CppFun(const std::string& type, const std::string& name);
        // Constructor without name specified.
        CppFun(const std::string& type);
        // Destructor.
        ~CppFun();

        // Add argument.
        void addArg(const CppVar* arg);

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
        typedef std::map<std::string, CppVar*> CppVarMap;
        typedef std::map<std::string, CppFun*> CppFunMap;

    private:
        // State variables.
        CppVarMap _states;
        // Input variables.
        CppVarMap _inputs;
        // All variables map. 
        CppVarMap _varMap;
        // Functions map. 
        CppFunMap _funMap;

        // Next state variables. Create when building functions.
        CppVarMap _nextStates;

        // Function seeable variables. Update during function construction.
        std::map<CppFun*, CppVarMap*> _varInFun;

        // Current working function.
        CppFun* _curFun;
        // Var map for the current working function.
        CppVarMap* _curVarMap;

        // Model prefix.
        std::string _prefix;
    public:
        // Constructor.
        CppSimGen(const std::string& prefix);

        // Destructor.
        ~CppSimGen();

        // Create input variable and put it in the _varMap.
        const CppVar* addInput(const std::string& name, nptr_t node);

        // Create state variable and put it in the _varMap.
        const CppVar* addState(const std::string& name, nptr_t node);

        // Create new function and put it in the _funMap.
        const CppFun* addFun(const std::string& type, const std::string& name);
        
        // This will be used by depthFirstVisit.
        void operator() (const Node* n);

        // Build function body with ast node.
        void buildFun(CppFun* f, nptr_t nptr);

        // Export all code into the output stream.
        void exportAll(std::ostream& out) const;

    protected:
        // Convert a bool variable into cpp code.
        CppVar* getBoolVarCpp(const BoolVar* n);
        // Convert a bool constant into cpp code.
        CppVar* getBoolConstCpp(const BoolConst* n);
        // Convert a bool op into cpp code.
        CppVar* getBoolOpCpp(const BoolOp* n);
        // Convert a bitvector variable into cpp code.
        CppVar* getBvVarCpp(const BitvectorVar* n);
        // Convert a bitvector constant into cpp code.
        CppVar* getBvConstCpp(const BitvectorConst* n);
        // Convert a bitvector op into cpp code.
        CppVar* getBvOpCpp(const BitvectorOp* n);
        // Convert a memory variable into cpp code.
        CppVar* getMemVarCpp(const MemVar* n);
        // Convert a memory const into cpp code.
        CppVar* getMemConstCpp(const MemConst* n);
        // Convert a memory write into cpp code.
        CppVar* getMemWrCpp(const MemWr* n);

    private:
        // Create a class to represent memory.
        void defMemClass(std::ostream& out) const;

        // Set the memvalues to the memory variable.
        void setMemValue(CppVar* var, MemValues values);

        template <class T>
        void checkAndInsert(std::map<std::string, T*>& mp, 
                            const std::string& name,
                            T* var);

        CppVar* findVar(CppVarMap& mp, const std::string& name);

    };

}

#endif
