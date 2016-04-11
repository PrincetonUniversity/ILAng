#ifndef __AST_HPP_DEFINED__
#define __AST_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <utility>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <common.hpp>
#include <ast/node.hpp>
#include <ast/bool.hpp>
#include <ast/bitvec.hpp>
#include <ast/mem.hpp>
#include <ast/choice.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    struct NodeRef 
    {
        // ------------------------ MEMBERS ----------------------------- //
        nptr_t node;

        // --------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
        // Default constructor. DO NOT USE. Will throw an exception.
        NodeRef(); 
        // Constructor. DO NOT USE. Call factory methods in Context instead.
        NodeRef(Node* node);
        // Constructor from an existing shared_ptr.
        NodeRef(const nptr_t& ptr);
        // Copy constructor.
        NodeRef(const NodeRef& nr);
        // Destructor.
        ~NodeRef();

        // assignment operator.
        NodeRef& operator=(const NodeRef& other);

        // ---------------------- METHODS ------------------------------- //
        std::string getName() const;
        NodeType getType() const;
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

        // comparison operators.
        NodeRef* eq(NodeRef* other) const;
        NodeRef* neq(NodeRef* other) const;
        NodeRef* ult(NodeRef* other) const;
        NodeRef* ugt(NodeRef* other) const;
        NodeRef* ule(NodeRef* other) const;
        NodeRef* uge(NodeRef* other) const;
        NodeRef* eqInt(int r) const;
        NodeRef* neqInt(int r) const;
        NodeRef* ultInt(int r) const;
        NodeRef* ugtInt(int r) const;
        NodeRef* uleInt(int r) const;
        NodeRef* ugeInt(int r) const;

        // slicing.
        NodeRef* slice(int hi, int lo) const;
        // get bit.
        NodeRef* getItem(NodeRef* idx) const;
        NodeRef* getItemInt(int idx) const;


        // does this object have a value?
        py::object value() const;

        // static function for non-python operators.

        // write to memory.
        static NodeRef* store(NodeRef* mem, NodeRef* addr, NodeRef* data);

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
        static NodeRef* sltInt(NodeRef* l, int r);
        static NodeRef* sgtInt(NodeRef* l, int r);
        static NodeRef* sleInt(NodeRef* l, int r);
        static NodeRef* sgeInt(NodeRef* l, int r);

        // bit manipulate functions.
        static NodeRef* concat(NodeRef* lo, NodeRef* hi);
        static NodeRef* lrotate(NodeRef* obj, int par);
        static NodeRef* rrotate(NodeRef* obj, int par);
        static NodeRef* extract(const NodeRef* obj, int hi, int lo);
        static NodeRef* zero_extend(NodeRef* obj, int outWidth);
        static NodeRef* sign_extend(NodeRef* obg, int outWidth);

        // nnonzero
        static NodeRef* nonzero(NodeRef* obj);

        // imply
        static NodeRef* imply(NodeRef* p, NodeRef* q);

        // ite.
        static NodeRef* ite(NodeRef* cond,
                            NodeRef* trueExp,
                            NodeRef* falseExp); 

    private:
        // ---------------------- HELPERS ----------------------------- //
        NodeRef* _unOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, const char* opName) const;
        NodeRef* _binOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, 
                        const char* opName, NodeRef* other) const;
        NodeRef* _binOp(BitvectorOp::Op op, NodeRef* other) const;
        NodeRef* _binOp(BitvectorOp::Op op, int r) const;
        NodeRef* _binOpR(BitvectorOp::Op op, int r) const;
        NodeRef* _cmpOp(BoolOp::Op op, NodeRef* other, bool bvtype) const;
        NodeRef* _cmpOp(BoolOp::Op op, int r) const;

        static NodeRef* _binOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, 
                               const char* opName, NodeRef* l, NodeRef* r);
        static NodeRef* _binOp(BoolOp::Op op, NodeRef* l, NodeRef* r);
        static NodeRef* _binOp(BitvectorOp::Op op, NodeRef* l, NodeRef* r);
        static NodeRef* _binOp(BitvectorOp::Op Op, NodeRef* l, int r);
        static NodeRef* _binOpR(BitvectorOp::Op op, int l, NodeRef* r);
        static NodeRef* _cmpOp(BoolOp::Op op, NodeRef* l, NodeRef* r, bool bvtype);
        static NodeRef* _cmpOp(BoolOp::Op op, NodeRef* l, int r);
        static NodeRef* _triOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp,
                            NodeRef* arg0, NodeRef* arg1, NodeRef* arg2);
        static NodeRef* _extractOp(const NodeRef* bv, int beg, int end);
    };

    // stream output.
    std::ostream& operator<<(std::ostream& out, const NodeRef& node);

    // utility functions to check whether two nodes have the same abstraction.
    bool checkAbstractions(const NodeRef* l1, const NodeRef* l2);
    bool checkAbstractions(const NodeRef* l1, const NodeRef* l2, const NodeRef* l3);

    // ---------------------------------------------------------------------- //
}

#endif 
