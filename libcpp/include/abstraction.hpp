#ifndef __ABSTRACTION_HPP_DEFINED__
#define __ABSTRACTION_HPP_DEFINED__

#include <set>
#include <map>
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
        struct npair_t {
            nptr_t var;
            nptr_t next;

            npair_t(const nptr_t& v, const nptr_t& n) : var(v) , next(n) { }
            ~npair_t() { }
        };
        typedef std::map<std::string, npair_t> nmap_t;

    private:
        int objCnt;
        int MAX_SYN_ITER;
    protected:
        // Get a new ID.
        int getObjId();

        // list of known names.
        std::set<std::string> names;

        // list of inputs
        nmap_t inps;
        // list of registers.
        nmap_t regs;
        // list of bits.
        nmap_t bits;
        // list of memories.
        nmap_t mems;

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

        // Set the next template for this memory var.
        void setNext(const std::string& name, NodeRef* n);
        // Get the next template.
        NodeRef* getNext(const std::string& name) const;

        // Create a bitvector constant with a long integer.
        NodeRef* bvConstLong(py::long_ l, int width);
        // Create a bitvector constant with an integer.
        NodeRef* bvConstInt(int l, int width);

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

        // get memories.
        const nmap_t& getMems() const { return mems; }
        // get (bitvector) inputs.
        const nmap_t& getInps() const { return inps; }
        // get bitvectors.
        const nmap_t& getRegs() const { return regs; }
        // get booleans.
        const nmap_t& getBits() const { return bits; }

        friend class Node;
        friend class Synthesizer;

    protected:
        nptr_t _synthesize(
            const std::string& name, 
            const nptr_vec_t& assumps, const nptr_t& expr,
            PyObject* pyfun);

        bool checkAndInsertName(const std::string& name);

    };
}
#endif
