#ifndef __ABSTRACTION_HPP_DEFINED__
#define __ABSTRACTION_HPP_DEFINED__

#include <string>
#include <ast.hpp>
#include <boost/python.hpp>

namespace ila
{
    class Abstraction
    {
    private:
        int objCnt;
    protected:
        // Get a new ID.
        int getObjId();
    public:
        // Constructor.
        Abstraction();
        // Destructor.
        ~Abstraction();

        // Create a bitvector variable.
        NodeRef* addRegister(const std::string& name, int width);
        // Create a boolean variable.
        NodeRef* addBooleanRegister(const std::string& name);
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
        // Create a choice operator.
        NodeRef* choice2(const std::string& name,
                        NodeRef* e1,
                        NodeRef* e2);

        // the synthesis function.
        void synthesize(NodeRef* expr, PyObject* fun);

        // check equality function.
        bool areEqual(NodeRef* left, NodeRef* right) const;

        friend class Node;
    };
}
#endif
