#ifndef __GENCBMCVERIF_HPP_DEFINED
#define __GENCBMCVERIF_HPP_DEFINED

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <boost/shared_ptr.hpp>

//
// Here we make use of previous work
// This is only inteneded to be used 
// to generate C that works with CBMC
// It is a temporary workaround
// Don't rely on it too much.
//
// May life treat you gently.
//              --Hongce 
//

#include <fstream>

namespace ila
{
    class CVar;
    class CFun;
    class CVerifGen;

    // C variable
    class CVar 
    {
        friend class CFun;
        friend class CVerifGen;
    public:

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
        int _idxWidth; // addr width only for memory variables
        bool _isConst;
        
    public:
        // Constructor with nptr_t, used for ast nodes.
        CVar(nptr_t nptr, const std::string& name = "");
        // Constructor with Node*, used for ast nodes.
        CVar(const Node* node, const std::string& name = "");
        // Constructor for bv prototype, used for temp var and func return.
        CVar(int width);
        // Constructor for bv mask, used for bitvector mask.
        CVar(const std::string& name, const std::string& val);
        // Something like copy construction, except name.
        CVar(const CVar* var);
        // Destructor.
        ~CVar();

    public:
        // Define variable, ex."  int r0"
        std::string def() const;
        // Define reference, ex. " int& r0"
        std::string refDef() const;
        // Use variable, ex. " r0"
        std::string use() const;
        // Use variable as signed.
        std::string signedUse() const;
        // Use the exact length variable.
        std::string exactUse() const;
        // Use the casted variable.
        std::string castUse() const;

        // malloc in C
        std::string memdef() const;
        // Type used in C, ex. BV *
        std::string ctype() const;

        bool memberVar;

    private:
        void init(nptr_t n);
        void init(const Node* n);
    };

    class CFun
    {
        friend class CVerifGen;

    protected:
        std::string _name;
        std::vector<const CVar*> _args;
        std::vector<std::string> _codeList;
        std::vector<std::string> _varList;
        CVar* _ret;
        std::vector<std::pair<CVar*, CVar*>> _updates; // it seems that _updates is only used for the Update fun

    public:
        // Constructor.
        CFun(const std::string& name);
        // Destructor.
        ~CFun();

        bool retSet() {
            return (_ret != NULL);
        }
    
    protected:
        // Add argument.
        void addArg(const CVar* arg);
        // Add body.
        void addBody(const std::string& code);

        // Print the function declaration to the output stream.
        // If the modelname is not specified, assume declare within the class.
        void dumpDec(std::ostream& out, 
                     const std::string& modelName,
                     const int& indent, bool decl = false) const;
        // Print the variable declaration to output stream.
        void dumpVarDec(std::ostream& out, const int& indent) const;
        // Print the code (with tail) to output stream.
        void dumpCode(std::ostream& out, const int& indent) const;

        // Print C declaration main difference is, use struct as a pointer
        void dumpCDec(std::ostream& out, 
                     const std::string& modelName,
                     const int& indent) const;
    };

    // C CBMC Verification Code Generator.
    class CVerifGen
    {
    public: 
        // Define types.
        typedef std::map<std::string, CVar*> CVarMap;
        typedef std::map<std::string, CFun*> CFunMap;

    private:
        // Model name.
        std::string _modelName;

        // State variables and other global variables(const mem).
        CVarMap _states;
        // Input variables.
        CVarMap _inputs;
        // Functions. 
        CFunMap _funMap;

        // Uninterpreted function variables.
        CVarMap _unitpFuncVarMap;
        // Uninterpreted functions.
        CFunMap _unitpFuncMap;

        // Constant memory to be init.
        std::map<CVar*,const MemConst*> _memConst;

        // Constant bitvector mask.
        CVarMap _masks;

        // Function seeable variables. Update during function construction.
        std::map<CFun*, CVarMap*> _varInFun;
        // Current working function.
        CFun* _curFun;
        // Variable currently added.
        CVar* _curVar;
        // Var map for the current working function.
        CVarMap* _curVarMap;

        CVarMap _localArray;
        CVarMap _localConstVar; // because const are refered by their value (not name)
        // so why create a var that is never used/assigned to.

    public:
        // Constructor.
        CVerifGen(const std::string& prefix);

        // Destructor.
        ~CVerifGen();

        // ------------------------------------------------------------------- //
        // Create input variable and put it in the _varMap.
        CVar* addInput(const std::string& name, nptr_t node, bool ms = false);

        // Create state variable and put it in the _varMap.
        CVar* addState(const std::string& name, nptr_t node, bool ms = false);

        // Create new function and put it in the _funMap.
        CFun* addFun(const std::string& name, bool ms = false);
        // Create new uninterpreted function and put it in the _unitpFunMap.
        CVar* addFuncVar(const std::string& name, nptr_t node, bool ms = false);
        
        // ------------------------------------------------------------------- //
        // This will be used by depthFirstVisit.
        void operator() (const Node* n);

        // ------------------------------------------------------------------- //
        // Build function body with ast node.
        void buildFun(CFun* f, nptr_t nptr);

        // Set return variable for the function.
        void setFunReturn(CFun* f, nptr_t nptr);

        // Add a variable to be updated at the end of the function.
        void addFunUpdate(CFun* f, nptr_t lhs, nptr_t rhs);
        // Add a variable to be updated at the end of the function.
        void addFunUpdate(CFun* f, nptr_t lhs, CVar* rhs);

        // Terminate function building.
        void endFun(CFun* f);

        // Apply the function and return to some variable.
        CVar* appFun(CFun* appFun, CFun* envFun);

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
        // Convert a bool variable into c code.
        CVar* getBoolVarC(const BoolVar* n);
        // Convert a bool constant into c code.
        CVar* getBoolConstC(const BoolConst* n);
        // Convert a bool op into c code.
        CVar* getBoolOpC(const BoolOp* n);
        // Convert a bitvector variable into c code.
        CVar* getBvVarC(const BitvectorVar* n);
        // Convert a bitvector constant into c code.
        CVar* getBvConstC(const BitvectorConst* n);
        // Convert a bitvector op into c code.
        CVar* getBvOpC(const BitvectorOp* n);
        // Convert a memory variable into c code.
        CVar* getMemVarC(const MemVar* n);
        // Convert a memory const into c code.
        CVar* getMemConstC(const MemConst* n);
        // Convert a memory op into c code.
        CVar* getMemOpC(const MemOp* n);
        // Convert a function into c code.
        CVar* getFuncVarC(const FuncVar* n);
        // Check if the node ITE.
        bool isITE(nptr_t n);

        // ------------------------------------------------------------------- //
        // Traverse and generate code in depth-first order.
        void depthFirstTraverse(nptr_t n);

        // ------------------------------------------------------------------- //
        // Helper function for getting exact signed code for multiprecision int
        std::string getSignedCCode(CVar* var);

        // ------------------------------------------------------------------- //
        // Helper function for inserting element in map, with assertion on 1st.
        template <class T>
        void checkAndInsert(std::map<std::string, T*>& mp, 
                            const std::string& name,
                            T* var,
                            bool force = false);
        // Helper function for finding element in map, with assertion on find.
        CVar* findVar(CVarMap& mp, const std::string& name);

    };

}

#endif
