#ifndef __ABSTRACTION_HPP_DEFINED__
#define __ABSTRACTION_HPP_DEFINED__

#include <set>
#include <map>
#include <vector>
#include <string>
#include <boost/python.hpp>

#include <common.hpp>
#include <ast.hpp>
#include <smt.hpp>
#include <imexport.hpp>
#include <cppsimgen.hpp>

namespace ila
{
    class Abstraction
    {
    public:
        // type of the state element/input.
        enum state_t { INP, REG, BIT, MEM, FUN };

    private:
        static int objCnt;
        int MAX_SYN_ITER;
    protected:
        // Get a new ID.
        static int getObjId();

        // list of known names.
        std::map<std::string, state_t> names;

        // list of inputs
        nmap_t inps;
        // list of registers.
        nmap_t regs;
        // list of bits.
        nmap_t bits;
        // list of memories.
        nmap_t mems;
        // list of functions.
        nmap_t funs;

        // fetch
        nptr_t fetchExpr;
        nptr_t fetchValid;

        // decode
        nptr_vec_t decodeExprs;

        // assumptions.
        nptr_vec_t assumps;

        void extractModelValues(
            Z3ExprAdapter& c,
            z3::model& m, 
            py::dict& result
        );

        NodeRef* getVar(const nmap_t& m, const std::string& name);
        void addVar(state_t st, nmap_t& m, nptr_t& n);

    public:
        int paramSyn;

        // Constructor.
        Abstraction();
        // Destructor.
        ~Abstraction();

        // Create a bitvector input.
        NodeRef* addInp(const std::string& name, int width);

        // Create a boolean variable.
        NodeRef* addBit(const std::string& name);

        // Create a bitvector variable.
        NodeRef* addReg(const std::string& name, int width);

        // Create a memory.
        NodeRef* addMem(const std::string& name, int addrW, int dataW);

        // Create a function.
        NodeRef* addFun(const std::string& name, int retW, const py::list& l);

        // Get an existing boolean.
        NodeRef* getBit(const std::string& name);
        // Get an existing bitvector.
        NodeRef* getReg(const std::string& name);
        // Get an existing memory.
        NodeRef* getMem(const std::string& name);
        // Get an existing function.
        NodeRef* getFun(const std::string& name);

        // add a var if it does not exist.
        void addVar(nptr_t& nref);

        // Set the next template for this memory var.
        void setNext(const std::string& name, NodeRef* n);
        // Get the next template.
        NodeRef* getNext(const std::string& name) const;

        // Create a bitvector constant with a long integer.
        NodeRef* bvConstLong(py::long_ l, int width);
        // Create a bitvector constant with an integer.
        NodeRef* bvConstInt(unsigned int l, int width);

        // Create a boolean constant (from a bool).
        NodeRef* boolConstB(bool b);
        // Create a boolean constant (from an integer: nonzero = true).
        NodeRef* boolConstI(int b);
        // Create a boolean constant (from an python long).
        NodeRef* boolConstL(py::long_ b);

        // Create a memory constant (from a memvalues object).
        NodeRef* memConst(const MemValues& mv);

        // return the current fetch expression.
        NodeRef* getFetchExpr() const;
        // set the fetch expression.
        void setFetchExpr(NodeRef* expr);
        // return the fetch valid expression.
        NodeRef* getFetchValid() const;
        // set the fetch valid expresssion.
        void setFetchValid(NodeRef* expr);
        // set decode.
        void setDecodeExpressions(const py::list& l);
        // get decode expressions.
        py::list getDecodeExpressions() const;

        // add an assumption.
        void addAssumption(NodeRef* expr);
        // get all assumptions.
        py::list getAllAssumptions() const;

        // the real synthesize function.
        void synthesizeAll(PyObject* fun);

        // synthesize only one register.
        void synthesizeReg(const std::string& name, PyObject* fun);

        // the synthesis function.
        NodeRef* synthesizeElement(
            const std::string& name, 
            NodeRef* expr, PyObject* fun);

        // the export function that export only one expression.
        void exportOneToFile(NodeRef* node,
                             const std::string& fileName) const;
        // the export function that export the overall model.
        void exportAllToFile(const std::string& fileName) const;

        // the import function that import only one expression.
        NodeRef* importOneFromFile(const std::string& fileName);
        // the import function that import the overall model.
        void importAllFromFile(const std::string& fileName);

        // the simulator generating function.
        void generateSim(const std::string& fileName,
                         const std::string& modelName) const;

        // check equality function.
        bool areEqual(NodeRef* left, NodeRef* right) const;
        // check quality under assumption
        bool areEqualAssump(NodeRef* assump, NodeRef* left, NodeRef* right);

        // get memories.
        const nmap_t& getMems() const { return mems; }
        // get (bitvector) inputs.
        const nmap_t& getInps() const { return inps; }
        // get bitvectors.
        const nmap_t& getRegs() const { return regs; }
        // get booleans.
        const nmap_t& getBits() const { return bits; }
        // get functions.
        const nmap_t& getFuns() const { return funs; }

        friend class Node;
        friend class Synthesizer;

    protected:
        nptr_t _synthesize(
            const std::string& name, 
            const nptr_vec_t& assumps, const nptr_t& expr,
            PyObject* pyfun);

        bool checkAndInsertName(state_t st, const std::string& name);

        bool doesNextExist(const nmap_t& m) const;

    };
}
#endif
