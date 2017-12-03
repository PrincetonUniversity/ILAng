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
#include <ast/func.hpp>
#include <ast/mem.hpp>
#include <ast/choice.hpp>
#include <ast/bvinrange.hpp>

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
         
        // and
        NodeRef* logicalAnd(NodeRef* other) const;
        NodeRef* logicalAndInt(int r) const;
        NodeRef* logicalAndRInt(int r) const;
        // or
        NodeRef* logicalOr(NodeRef* other) const;
        NodeRef* logicalOrInt(int r) const;
        NodeRef* logicalOrRInt(int l) const;
        // xor
        NodeRef* logicalXor(NodeRef* other) const;
        NodeRef* logicalXorInt(int r) const;
        NodeRef* logicalXorRInt(int l) const;

        // add
        NodeRef* add(NodeRef* other) const;
        NodeRef* addInt(int r) const;
        NodeRef* raddInt(int r) const;
        // sub
        NodeRef* sub(NodeRef* other) const;
        NodeRef* subInt(int r) const;
        NodeRef* rsubInt(int r) const;
        // udiv
        NodeRef* udiv(NodeRef* other) const;
        NodeRef* udivInt(int r) const;
        NodeRef* rudivInt(int r) const;
        // urem
        NodeRef* urem(NodeRef* r);
        NodeRef* uremInt(int r);
        NodeRef* ruremInt(int l);
        // shl
        NodeRef* shl(NodeRef* other) const;
        NodeRef* shlInt(int r) const;
        NodeRef* rshlInt(int r) const;
        // shr
        NodeRef* lshr(NodeRef* other) const;
        NodeRef* lshrInt(int r) const;
        NodeRef* rlshrInt(int r) const;
        // mul
        NodeRef* mul(NodeRef* other) const;
        NodeRef* mulInt(int r) const;
        NodeRef* rmulInt(int r) const;

        // comparison operators.
        NodeRef* eq(NodeRef& other) const;
        NodeRef* neq(NodeRef& other) const;
        NodeRef* ult(NodeRef& other) const;
        NodeRef* ugt(NodeRef& other) const;
        NodeRef* ule(NodeRef& other) const;
        NodeRef* uge(NodeRef& other) const;
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

        // set reference name.
        void setRefName(const std::string & refName);
        // does this object have a value?
        py::object value() const;

        // static function for non-python operators.

        // read from memory.
        static NodeRef* load(NodeRef* mem, NodeRef* addr);
        static NodeRef* loadblock(NodeRef* mem, NodeRef* addr, int chunks);
        static NodeRef* loadblockB(NodeRef* mem, NodeRef* addr, int chunks);
        // write to memory.
        static NodeRef* store(NodeRef* mem, NodeRef* addr, NodeRef* data);
        static NodeRef* storeblock(NodeRef* mem, NodeRef* addr, NodeRef* data);
        static NodeRef* storeblockB(NodeRef* mem, NodeRef* addr, NodeRef* data);

        // logical functions.
        static NodeRef* logicalXnor(NodeRef* l, NodeRef* r);
        static NodeRef* logicalNand(NodeRef* l, NodeRef* r);
        static NodeRef* logicalNor(NodeRef* l, NodeRef* r);

        // arithmetic functions.
        // div.
        static NodeRef* sdiv(NodeRef* l, NodeRef* r);
        static NodeRef* sdivInt(NodeRef* l, int r);
        static NodeRef* rsdivInt(int l, NodeRef* r);
        // smod
        static NodeRef* smod(NodeRef* l, NodeRef* r);
        static NodeRef* smodInt(NodeRef* l, int r);
        static NodeRef* rsmodInt(int l, NodeRef* r);
        // srem
        static NodeRef* srem(NodeRef* l, NodeRef* r);
        static NodeRef* sremInt(NodeRef* l, int r);
        static NodeRef* rsremInt(int l, NodeRef* r);
        // shr
        static NodeRef* ashr(NodeRef* l, NodeRef* r);
        static NodeRef* ashrInt(NodeRef* l, int r);
        static NodeRef* rashrInt(int l, NodeRef* r);

        // comparison functions.
        static NodeRef* slt(NodeRef& l, NodeRef& r);
        static NodeRef* sgt(NodeRef& l, NodeRef& r);
        static NodeRef* sle(NodeRef& l, NodeRef& r);
        static NodeRef* sge(NodeRef& l, NodeRef& r);
        static NodeRef* sltInt(NodeRef& l, int r);
        static NodeRef* sgtInt(NodeRef& l, int r);
        static NodeRef* sleInt(NodeRef& l, int r);
        static NodeRef* sgeInt(NodeRef& l, int r);

        // bit manipulate functions.
        static NodeRef* concat(NodeRef* lo, NodeRef* hi);
        static NodeRef* concatList(const py::list& l);
        static NodeRef* lrotate(NodeRef* obj, int par);
        static NodeRef* rrotate(NodeRef* obj, int par);
        static NodeRef* extract(const NodeRef* obj, int hi, int lo);
        static NodeRef* zero_extend(NodeRef* obj, int outWidth);
        static NodeRef* sign_extend(NodeRef* obg, int outWidth);

        // nnonzero
        static NodeRef* nonzero(NodeRef* obj);

        // imply
        static NodeRef* imply(NodeRef& p, NodeRef& q);

        // ite.
        static NodeRef* ite(NodeRef& cond,
                            NodeRef& trueExp,
                            NodeRef& falseExp); 

        // apply function.
        static NodeRef* appfunc0(NodeRef* fun);
        static NodeRef* appfunc1(NodeRef* fun, NodeRef* arg);
        static NodeRef* appfunc2(NodeRef* fun, NodeRef* arg0, NodeRef* arg1);
        static NodeRef* appfuncL(NodeRef* fun, const py::list& l);

        // choices
        static NodeRef* choice2(const std::string& name, 
                                NodeRef* e1, NodeRef* e2);
        static NodeRef* choice3(const std::string& name, 
                                NodeRef* e1, NodeRef* e2, NodeRef* e3);
        static NodeRef* choice4(const std::string& name, 
                                NodeRef* e1, NodeRef* e2, 
                                NodeRef* e3, NodeRef* e4);
        static NodeRef* choice5(const std::string& name, 
                                NodeRef* e1, NodeRef* e2, 
                                NodeRef* e3, NodeRef* e4, NodeRef* e5);
        static NodeRef* choice6(const std::string& name, 
                                NodeRef* e1, NodeRef* e2, NodeRef* e3,
                                NodeRef* e4, NodeRef* e5, NodeRef* e6);
        static NodeRef* choiceL(const std::string& name, 
                                const py::list& l);
        // in-range. 
        static NodeRef* inRange(const std::string& name, 
                                NodeRef* lo, NodeRef* hi);
        // read-slice.
        static NodeRef* readSlice(const std::string& name, NodeRef* bv, int w);
        // read-chunk.
        static NodeRef* readChunk(const std::string& name, NodeRef* bv, int w);
        // write-slice.
        static NodeRef* writeSlice(const std::string& name, NodeRef* bv, NodeRef* wr);
        // write-chunk
        static NodeRef* writeChunk(const std::string& name, NodeRef* bv, NodeRef* wr);

        // simplify.
        static NodeRef* simplify(NodeRef& assump, NodeRef& exp);

        // hashing.
        size_t   hash() const;
    private:
        // ---------------------- HELPERS ----------------------------- //
        NodeRef* _unOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, const char* opName) const;
        NodeRef* _binOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, 
                        const char* opName, NodeRef* other) const;
        NodeRef* _binOp(BitvectorOp::Op op, NodeRef* other) const;
        NodeRef* _binOp(BitvectorOp::Op op, int r) const;
        NodeRef* _binOpR(BitvectorOp::Op op, int r) const;
        NodeRef* _cmpOp(BoolOp::Op op, NodeRef& other, bool bvtype) const;
        NodeRef* _cmpOp(BoolOp::Op op, int r) const;

        static NodeRef* _binOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, 
                               const char* opName, NodeRef* l, NodeRef* r);
        static NodeRef* _binOp(BoolOp::Op op, NodeRef& l, NodeRef& r);
        static NodeRef* _binOp(BitvectorOp::Op op, NodeRef* l, NodeRef* r);
        static NodeRef* _binOp(BitvectorOp::Op Op, NodeRef* l, int r);
        static NodeRef* _binOpR(BitvectorOp::Op op, int l, NodeRef* r);
        static NodeRef* _cmpOp(BoolOp::Op op, NodeRef& l, NodeRef& r, bool bvtype);
        static NodeRef* _cmpOp(BoolOp::Op op, NodeRef& l, int r);
        static NodeRef* _triOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, MemOp::Op memOp,
                            NodeRef& arg0, NodeRef& arg1, NodeRef& arg2);
        static NodeRef* _naryOp(BitvectorOp::Op bvOp, nptr_vec_t& args);
        static NodeRef* _extractOp(const NodeRef* bv, int beg, int end);
        static NodeRef* _choice(const std::string& name, 
                                const nptr_vec_t& args);
    };

    // stream output.
    std::ostream& operator<<(std::ostream& out, const NodeRef& node);

    // ---------------------------------------------------------------------- //
}

#endif 
