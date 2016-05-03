#ifndef __CPPSIMGEN_HPP_DEFINED
#define __CPPSIMGEN_HPP_DEFINED

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <boost/shared_ptr.hpp>

namespace ila
{
    class CppVar;
    class CppFun;
    class CppSimFun;

    // Cpp variable
    class CppVar
    {
        friend class CppFun;
        friend class CppSimGen;
    public:
        // FIXME Change bvStr, ubvStr, sbvStr, maxBvVal if this is changed.
        typedef uint64_t cppBvType;

        // Variable count.
        static int varCnt;
        // Variable type.
        static std::string boolStr;
        static std::string bvStr;
        static std::string ubvStr;
        static std::string sbvStr;
        static std::string memStr;
        static std::string voidStr;
        static std::string maxBvVal;
    protected:
        std::string _type;
        std::string _name;
        std::string _val;
        int _width;
        bool _isConst;
        
    public:
        // Constructor with nptr_t
        CppVar(nptr_t nptr, const std::string& name = "");
        // Constructor with Node*
        CppVar(const Node* node, const std::string& name = "");
        // Constructor for bv prototype.
        CppVar(int width);
        // Destructor.
        ~CppVar();

    protected:
        // Define variable, ex."  int r0"
        std::string def() const;
        // Define reference, ex. " int& r0"
        std::string refDef() const;
        // Use variable, ex. " r0"
        std::string use() const;
        // Use variable as signed.
        std::string signedUse() const;
        // Use variable as unsigned.
        std::string unsignedUse() const;
        // Use the exact length variable.
        std::string exactUse() const;
        // Use a segment of the bits.
        std::string sliceUse(const int& msb, const int& lsb) const;

    private:
        void init(nptr_t n);
        void init(const Node* n);
    };

    class CppFun
    {
        friend class CppSimGen;

    protected:
        std::string _name;
        std::vector<const CppVar*> _args;
        std::vector<std::string> _codeList;
        CppVar* _ret;
        std::vector<std::pair<CppVar*, CppVar*>> _updates;

    public:
        // Constructor.
        CppFun(const std::string& name);
        // Destructor.
        ~CppFun();
    
    protected:
        // Add argument.
        void addArg(const CppVar* arg);
        // Add body.
        void addBody(const std::string& code);

        // Print the function declaration to the output stream.
        // If the modelname is not specified, assume declare within the class.
        void dumpDec(std::ostream& out, 
                     const std::string& modelName,
                     const int& indent) const;
        // Print the code (with tail) to output stream.
        void dumpCode(std::ostream& out, const int& indent) const;
    };

    // Cpp simulator generator.
    class CppSimGen
    {
    public: 
        // Define types.
        typedef std::map<std::string, CppVar*> CppVarMap;
        typedef std::map<std::string, CppFun*> CppFunMap;

    private:
        // Model name.
        std::string _modelName;

        // State variables and other global variables(const mem).
        CppVarMap _states;
        // Input variables.
        CppVarMap _inputs;
        // Functions. 
        CppFunMap _funMap;

        // Uninterpreted function variables.
        CppVarMap _unitpFuncVarMap;
        // Uninterpreted functions.
        CppFunMap _unitpFuncMap;

        // Constant memory to be init.
        std::map<CppVar*,const MemConst*> _memConst;

        // Function seeable variables. Update during function construction.
        std::map<CppFun*, CppVarMap*> _varInFun;
        // Current working function.
        CppFun* _curFun;
        // Variable currently added.
        CppVar* _curVar;
        // Var map for the current working function.
        CppVarMap* _curVarMap;

    public:
        // Constructor.
        CppSimGen(const std::string& prefix);

        // Destructor.
        ~CppSimGen();

        // ------------------------------------------------------------------- //
        // Create input variable and put it in the _varMap.
        CppVar* addInput(const std::string& name, nptr_t node);

        // Create state variable and put it in the _varMap.
        CppVar* addState(const std::string& name, nptr_t node);

        // Create new function and put it in the _funMap.
        CppFun* addFun(const std::string& name);
        // Create new uninterpreted function and put it in the _unitpFunMap.
        CppVar* addFuncVar(const std::string& name, nptr_t node);
        
        // ------------------------------------------------------------------- //
        // This will be used by depthFirstVisit.
        void operator() (const Node* n);

        // ------------------------------------------------------------------- //
        // Build function body with ast node.
        void buildFun(CppFun* f, nptr_t nptr);

        // Set return variable for the function.
        void setFunReturn(CppFun* f, nptr_t nptr);

        // Add a variable to be updated at the end of the function.
        void addFunUpdate(CppFun* f, nptr_t lhs, nptr_t rhs);

        // Terminate function building.
        void endFun(CppFun* f);

        // Export all code into the output stream.
        void exportAll(std::ostream& out) const;

    private:
        // ------------------------------------------------------------------- //
        // Create a class for memory representation.
        void defMemClass(std::ostream& out) const;

        // Initial constant memory.
        void setMemConst(std::ostream& out) const;
        
        // Create the main function.
        void genMain(std::ostream& out) const;

        // Create a class for the model.
        void genModel(std::ostream& out) const;

        // Declare uninterpreted function (extern).
        void defUnitpFunc(std::ostream& out) const;

        // ------------------------------------------------------------------- //
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
        // Convert a memory op into cpp code.
        CppVar* getMemOpCpp(const MemOp* n);
        // Convert a function into cpp code.
        CppVar* getFuncVarCpp(const FuncVar* n);

        // ------------------------------------------------------------------- //
        // Helper function for inserting element in map, with assertion on 1st.
        template <class T>
        void checkAndInsert(std::map<std::string, T*>& mp, 
                            const std::string& name,
                            T* var);
        // Helper function for finding element in map, with assertion on find.
        CppVar* findVar(CppVarMap& mp, const std::string& name);

    };

}

#endif
