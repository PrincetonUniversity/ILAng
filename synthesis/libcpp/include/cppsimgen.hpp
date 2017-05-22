#ifndef __CPPSIMGEN_HPP_DEFINED
#define __CPPSIMGEN_HPP_DEFINED

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <boost/shared_ptr.hpp>

#include <fstream>

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
        typedef mp_int_t cppBvType;

        // Variable count.
        static int varCnt;
        // Variable type.
        static std::string boolStr;
        static std::string bvStr;
        static std::string memStr;
        static std::string voidStr;
    protected:
        std::string _type;
        std::string _name;
        std::string _val;
        int _width;
        int _idxwidth;
        bool _isConst;
        
    public:
        // Constructor with nptr_t, used for ast nodes.
        CppVar(nptr_t nptr, const std::string& name = "");
        // Constructor with Node*, used for ast nodes.
        CppVar(const Node* node, const std::string& name = "");
        // Constructor for bv prototype, used for temp var and func return.
        CppVar(int width);
        // Constructor for bv mask, used for bitvector mask.
        CppVar(const std::string& name, const std::string& val);
        // Something like copy construction, except name.
        CppVar(const CppVar* var);
        // Destructor.
        ~CppVar();

    public:
        // Define variable, ex."  int r0"
        std::string def() const;
        // Define reference, ex. " int& r0"
        std::string refDef() const;
        // Define constructor init requirement, ex. "type_mem(16,8) m1"
        std::string ctorDef() const;
        // Corrected Mem Type, ex "type_mem<BV?, depth>"
        std::string vType() const;
        // Use variable, ex. " r0"
        std::string use() const;
        // Use variable as signed.
        std::string signedUse() const;
        // Use the exact length variable.
        std::string exactUse() const;
        // Use the casted variable.
        std::string castUse() const;

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
        std::vector<std::string> _varList;
        CppVar* _ret;
        std::vector<std::pair<CppVar*, CppVar*>> _updates;

    public:
        // Constructor.
        CppFun(const std::string& name);
        // Destructor.
        ~CppFun();

        bool retSet() {
            return (_ret != NULL);
        }
    
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
        // Print the variable declaration to output stream.
        void dumpVarDec(std::ostream& out, const int& indent) const;
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

        // Constant bitvector mask.
        CppVarMap _masks;

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
        CppVar* addInput(const std::string& name, nptr_t node, bool ms = false);

        // Create state variable and put it in the _varMap.
        CppVar* addState(const std::string& name, nptr_t node, bool ms = false);

        // Create new function and put it in the _funMap.
        CppFun* addFun(const std::string& name, bool ms = false);
        // Create new uninterpreted function and put it in the _unitpFunMap.
        CppVar* addFuncVar(const std::string& name, nptr_t node, bool ms = false);
        
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
        // Add a variable to be updated at the end of the function.
        void addFunUpdate(CppFun* f, nptr_t lhs, CppVar* rhs);

        // Terminate function building.
        void endFun(CppFun* f);

        // Apply the function and return to some variable.
        CppVar* appFun(CppFun* appFun, CppFun* envFun);

        // Export all code into the output stream.
        void exportAllToFile(const std::string& fileName) const;

        // Export all code into the directory.
        void exportAllToDir(const std::string& dirName) const;

    private:
        // ------------------------------------------------------------------- //
        // Create a class for memory representation.
        void defMemClass(std::ostream& out) const;

        // Initial constant memory.
        void setMemConst(std::ostream& out) const;
        
        // Create a class for the model.
        void genModel(std::ostream& out) const;

        // Declare uninterpreted function (extern).
        void defUnitpFunc(std::ostream& out) const;

        // Create common headers, class definitions, type definitions, ...
        void createCommon(std::ostream& out) const;

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
        // Check if the node ITE.
        bool isITE(nptr_t n);

        // ------------------------------------------------------------------- //
        // Traverse and generate code in depth-first order.
        void depthFirstTraverse(nptr_t n);

        // ------------------------------------------------------------------- //
        // Helper function for getting exact signed code for multiprecision int
        std::string getSignedCppCode(CppVar* var);

        // ------------------------------------------------------------------- //
        // Helper function for inserting element in map, with assertion on 1st.
        template <class T>
        void checkAndInsert(std::map<std::string, T*>& mp, 
                            const std::string& name,
                            T* var,
                            bool force = false);
        // Helper function for finding element in map, with assertion on find.
        CppVar* findVar(CppVarMap& mp, const std::string& name);

    };

}

#endif
