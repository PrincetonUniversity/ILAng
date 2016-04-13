#ifndef __ABSTRACTION_HPP_DEFINED__
#define __ABSTRACTION_HPP_DEFINED__

#include <common.hpp>
#include <string>
#include <ast.hpp>
#include <smt.hpp>
#include <boost/python.hpp>
#include <list>

namespace ila
{
    class Abstraction
    {
    private:
        int objCnt;
        int MAX_SYN_ITER;
    protected:
        // Get a new ID.
        int getObjId();
        // list of registers.
        nptr_vec_t regs;
        // list of bits.
        nptr_vec_t bits;
        // list of memories.
        nptr_vec_t mems;

        // fetch
        nptr_t fetchExpr;
        nptr_t fetchValid;

        // decode
        nptr_vec_t decodeExprs;

        void extractModelValues(
            Z3ExprAdapter& c,
            z3::model& m, 
            py::dict& result
        );

    public:
        // Constructor.
        Abstraction();
        // Destructor.
        ~Abstraction();

        // Create a boolean variable.
        NodeRef* addBit(const std::string& name);
        // Create a bitvector variable.
        NodeRef* addReg(const std::string& name, int width);
        // Create a memory.
        NodeRef* addMem(const std::string& name, int addrW, int dataW);

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

        // the real synthesize function.
        void synthesizeAll(PyObject* fun);

        // the synthesis function.
        NodeRef* synthesize(NodeRef* expr, PyObject* fun);

        // check equality function.
        bool areEqual(NodeRef* left, NodeRef* right) const;

        friend class Node;
    };
}
#endif
