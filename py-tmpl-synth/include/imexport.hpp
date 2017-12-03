#ifndef __IMEXPORT_HPP_DEFINED__
#define __IMEXPORT_HPP_DEFINED__

#include <ast.hpp>

#include <funcReduct.hpp>

namespace ila 
{
    // A function object that export / import the synthesized AST.
    class ImExport
    {
    public:
        typedef std::map<std::string, nptr_t> nref_map_t;

    private:
        nref_map_t _nodeMap;
    
    public:
        // Constructor.
        ImExport(FuncReduction *funcRedPtr, int reduce = 0);

        // Destructor.
        ~ImExport();

        // Export the ast for a single node to stream output
        void exportAst(std::ostream& out, const Node* n);
        
        // Import one ast from input stream.
        nptr_t importAst(Abstraction* c, std::istream& in);

        // helper function for the _nodeMap.
        nptr_t mapFind(const std::string& name) const;
        void mapInsert(const std::string& name, nptr_t nptr);
        // add elements from the map to the abstraction.
        void addMapVars(Abstraction* c);

    protected:
        
    private:
        // Function Reduction Module
        FuncReduction *FuncReductor;
        
        int reduceWhenImport;
        // parsing helper function.
        char nextChar(std::istream& in) const;
        std::string next(std::istream& in) const;
        int eatIdx(std::istream& in) const;

        // figure out which bitvectorOp/boolOp is the opName specified.
        BitvectorOp::Op getBvOpType(const std::string& opName) const;
        BoolOp::Op getBoolOpType(const std::string& opName) const;
        MemOp::Op getMemOpType(const std::string& opName) const;

        // export memValue.
        void exportMemValues(std::ostream& out, const MemValues& val);
        // import memValue.
        MemValues importMemValue(std::istream& in, int aw, int dw);
    };

}

#endif
