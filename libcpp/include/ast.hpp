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
         
        NodeRef* logicalAnd(NodeRef* other) const;
        NodeRef* logicalOr(NodeRef* other) const;
        NodeRef* logicalXor(NodeRef* other) const;

        NodeRef* add(NodeRef* other) const;
        NodeRef* addInt(int r) const;
        NodeRef* raddInt(int r) const;
        NodeRef* sub(NodeRef* other) const;
        NodeRef* subInt(int r) const;
        NodeRef* rsubInt(int r) const;
        NodeRef* udiv(NodeRef* other) const;
        NodeRef* udivInt(int r) const;
        NodeRef* rudivInt(int r) const;
        NodeRef* smod(NodeRef* other) const;
        NodeRef* smodInt(int r) const;
        NodeRef* rsmodInt(int r) const;
        NodeRef* shl(NodeRef* other) const;
        NodeRef* shlInt(int r) const;
        NodeRef* rshlInt(int r) const;
        NodeRef* lshr(NodeRef* other) const;
        NodeRef* lshrInt(int r) const;
        NodeRef* rlshrInt(int r) const;
        NodeRef* mul(NodeRef* other) const;
        NodeRef* mulInt(int r) const;
        NodeRef* rmulInt(int r) const;

        // TODO  nonzero(bvredand)

        // comparison operators.
        NodeRef* eq(NodeRef* other) const;
        NodeRef* neq(NodeRef* other) const;
        NodeRef* ult(NodeRef* other) const;
        NodeRef* ugt(NodeRef* other) const;
        NodeRef* ule(NodeRef* other) const;
        NodeRef* uge(NodeRef* other) const;

        // ite.
        NodeRef* ite(NodeRef* thenExp, NodeRef* elseExp) const;

        // does this object have a value?
        boost::python::object value() const;

        // static function for non-python operators.
        // logical functions.
        static NodeRef* logicalXnor(NodeRef* l, NodeRef* r);
        static NodeRef* logicalNand(NodeRef* l, NodeRef* r);
        static NodeRef* logicalNor(NodeRef* l, NodeRef* r);

        // arithmetic functions.
        static NodeRef* sdiv(NodeRef* l, NodeRef* r);
        static NodeRef* sdivInt(NodeRef* l, int r);
        static NodeRef* rsdivInt(int l, NodeRef* r);
        static NodeRef* srem(NodeRef* l, NodeRef* r);
        static NodeRef* sremInt(NodeRef* l, int r);
        static NodeRef* rsremInt(int l, NodeRef* r);
        static NodeRef* urem(NodeRef* l, NodeRef* r);
        static NodeRef* uremInt(NodeRef* l, int r);
        static NodeRef* ruremInt(int l, NodeRef* r);
        static NodeRef* ashr(NodeRef* l, NodeRef* r);
        static NodeRef* ashrInt(NodeRef* l, int r);
        static NodeRef* rashrInt(int l, NodeRef* r);

        // comparison functions.
        static NodeRef* slt(NodeRef* l, NodeRef* r);
        static NodeRef* sgt(NodeRef* l, NodeRef* r);
        static NodeRef* sle(NodeRef* l, NodeRef* r);
        static NodeRef* sge(NodeRef* l, NodeRef* r);

        // bit manipulate functions.
        static NodeRef* concat(NodeRef* l, NodeRef* r);
        static NodeRef* lrotate(NodeRef* obj, int par);
        static NodeRef* rrotate(NodeRef* obj, int par);

        static NodeRef* extract(NodeRef* obj, int beg, int end);
        // ite.
/*        static NodeRef* ite(NodeRef* cond,
                            NodeRef* trueExp,
                            NodeRef* falseExp);  */

    private:
        // ---------------------- HELPERS ----------------------------- //
        NodeRef* _unOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, const char* opName) const;
        NodeRef* _binOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, 
                        const char* opName, NodeRef* other) const;
        NodeRef* _binOp(BitvectorOp::Op op, NodeRef* other) const;
        NodeRef* _binOp(BitvectorOp::Op op, int r) const;
        NodeRef* _binOpR(BitvectorOp::Op op, int r) const;
        NodeRef* _cmpOp(BoolOp::Op op, NodeRef* other, bool bvtype) const;
        NodeRef* _triOp(BoolOp::Op op, BitvectorOp::Op bvOp,
                        const char* opName, NodeRef* exp1, NodeRef* exp2) const;

        static NodeRef* _binOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, 
                               const char* opName, NodeRef* l, NodeRef* r);
        static NodeRef* _binOp(BitvectorOp::Op op, NodeRef* l, NodeRef* r);
        static NodeRef* _binOp(BitvectorOp::Op Op, NodeRef* l, int r);
        static NodeRef* _binOpR(BitvectorOp::Op op, NodeRef* l, int r);
        static NodeRef* _cmpOp(BoolOp::Op op, NodeRef* l, NodeRef* r, bool bvtype);
        static NodeRef* _triOp(BitvectorOp::Op op, NodeRef* bv, int beg, int end);
    };

    // stream output.
    std::ostream& operator<<(std::ostream& out, const NodeRef& node);
}

#endif 
