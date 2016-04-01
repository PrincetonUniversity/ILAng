#ifndef __AST_HPP_DEFINED__
#define __AST_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <ast/node.hpp>
#include <ast/bitvec.hpp>
#include <ast/bool.hpp>
#include <ast/syn.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

namespace ila
{
    struct NodeRef 
    {
        // ------------------------ MEMBERS ----------------------------- //
        boost::shared_ptr<Node> node;

        // --------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
        // Default constructor. DO NOT USE. Will throw an exception.
        NodeRef(); 
        // Constructor. DO NOT USE. Call factory methods in Context instead.
        NodeRef(Node* node);
        // Copy constructor.
        NodeRef(const NodeRef& nr);
        // Destructor.
        ~NodeRef();

        // assignment operator.
        NodeRef& operator=(const NodeRef& other);

        // ---------------------- METHODS ------------------------------- //
        std::string getName() const;
        NodeType getType() const;
        void doSomething();
        bool equal(NodeRef* other) const;

        // ---------------------- OPERATORS ----------------------------- //
        NodeRef* complement() const; 
        NodeRef* negate() const;

        NodeRef* logicalNot() const;
        NodeRef* logicalAnd(NodeRef* other) const;
        NodeRef* logicalOr(NodeRef* other) const;
        NodeRef* logicalXor(NodeRef* other) const;
        NodeRef* logicalXnor(NodeRef* other) const;
        NodeRef* logicalNand(NodeRef* other) const;
        NodeRef* logicalNor(NodeRef* other) const;

        NodeRef* add(NodeRef* other) const;
        NodeRef* addInt(int r) const;
        NodeRef* raddInt(int r) const;
        NodeRef* sub(NodeRef* other) const;
        NodeRef* subInt(int r) const;
        NodeRef* rsubInt(int r) const;
        NodeRef* sdiv(NodeRef* other) const;
        NodeRef* udiv(NodeRef* other) const;
        NodeRef* sdivInt(int r) const;
        NodeRef* udivInt(int r) const;
        NodeRef* rsdivInt(int r) const;
        NodeRef* rudivInt(int r) const;
        NodeRef* srem(NodeRef* other) const;
        NodeRef* urem(NodeRef* other) const;
        NodeRef* sremInt(int r) const;
        NodeRef* uremInt(int r) const;
        NodeRef* smod(NodeRef* other) const;
        NodeRef* smodInt(int r) const;
        NodeRef* shl(NodeRef* other) const;
        NodeRef* shlInt(int r) const;
        NodeRef* lshr(NodeRef* other) const;
        NodeRef* lshrInt(int r) const;
        NodeRef* ashr(NodeRef* other) const;
        NodeRef* ashrInt(int r) const;
        NodeRef* mul(NodeRef* other) const;
        NodeRef* mulInt(int r) const;
        NodeRef* concat(NodeRef* other) const;

        NodeRef* eq(NodeRef* other) const;
        NodeRef* neq(NodeRef* other) const;
        NodeRef* slt(NodeRef* other) const;
        NodeRef* sgt(NodeRef* other) const;
        NodeRef* sle(NodeRef* other) const;
        NodeRef* sge(NodeRef* other) const;
        NodeRef* ult(NodeRef* other) const;
        NodeRef* ugt(NodeRef* other) const;
        NodeRef* ule(NodeRef* other) const;
        NodeRef* uge(NodeRef* other) const;

        NodeRef* ite(NodeRef* thenExp, NodeRef* elseExp) const;

        boost::python::object value() const;


    private:
        // ---------------------- HELPERS ----------------------------- //
        NodeRef* _unOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, const char* opName) const;
        NodeRef* _binOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, 
                        const char* opName, NodeRef* other) const;
        NodeRef* _binOp(BitvectorOp::Op op, NodeRef* other) const;
        NodeRef* _binOp(BitvectorOp::Op op, int r) const;
        NodeRef* _binOpR(BitvectorOp::Op op, int r) const;
        NodeRef* _cmpOp(BoolOp::Op op,
                        NodeRef* other) const;
        NodeRef* _triOp(BoolOp::Op op,
                        BitvectorOp::Op bvOp,
                        const char* opName,
                        NodeRef* exp1,
                        NodeRef* exp2) const;
    };

    // stream output.
    std::ostream& operator<<(std::ostream& out, const NodeRef& node);
}

#endif 
