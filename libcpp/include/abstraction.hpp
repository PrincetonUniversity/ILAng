#ifndef __ABSTRACTION_HPP_DEFINED__
#define __ABSTRACTION_HPP_DEFINED__

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
    protected:
        // Get a new ID.
        int getObjId();
        // list of registers.
        std::vector< boost::shared_ptr<Node> > regs;
        // list of bits.
        std::vector< boost::shared_ptr<Node> > bits;
        // list of memories.
        std::vector< boost::shared_ptr<Node> > mems;

        void extractModelValues(
            Z3ExprAdapter& c,
            z3::model& m, 
            boost::python::dict& result
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
        NodeRef* bvConstLong(boost::python::long_ l, int width);
        // Create a bitvector constant with an integer.
        NodeRef* bvConstInt(int l, int width);

        // Create a boolean constant (from a bool).
        NodeRef* boolConstB(bool b);
        // Create a boolean constant (from an integer: nonzero = true).
        NodeRef* boolConstI(int b);
        // Create a boolean constant (from an python long).
        NodeRef* boolConstL(boost::python::long_ b);

        // Create a memory constant (from a memvalues object).
        NodeRef* memConst(const MemValues& mv);

        // Create a choice operator.
        NodeRef* choice2(const std::string& name,
                        NodeRef* e1,
                        NodeRef* e2);

        // the synthesis function.
        NodeRef* synthesize(NodeRef* expr, PyObject* fun);

        // check equality function.
        bool areEqual(NodeRef* left, NodeRef* right) const;

        friend class Node;
    };
}
#endif
