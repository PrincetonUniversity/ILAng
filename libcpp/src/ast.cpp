#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>

namespace ila
{

    // ---------------------------------------------------------------------- //
    NodeRef::NodeRef()
      : node(new Node())
    {
        throw PyILAException(PyExc_RuntimeError, "Cannot create node's directly. Use the context object.");
    }

    NodeRef::NodeRef(Node* n)
      : node(n)
    {
    }

    NodeRef::NodeRef(const nptr_t& ptr)
      : node(ptr)
    {
    }

    NodeRef::NodeRef(const NodeRef& nr)
      : node(nr.node)
    {
    }

    NodeRef::~NodeRef()
    {
    }

    NodeRef& NodeRef::operator=(const NodeRef& other)
    {
        if(this != &other) { 
            node = other.node;
        }
        return *this;
    }

    // ---------------------------------------------------------------------- //
    std::string NodeRef::getName() const
    {
        return node->name;
    }

    NodeType NodeRef::getType() const
    {
        return node->type;
    }

    bool NodeRef::equal(NodeRef* other) const
    {
        return node->equal(other->node.get());
    }

    // ---------------------------------------------------------------------- //
    NodeRef* NodeRef::complement() const
    {
        return _unOp(BoolOp::NOT, BitvectorOp::COMPLEMENT, "complement");
    }

    NodeRef* NodeRef::negate() const
    {
        return _unOp(BoolOp::INVALID, BitvectorOp::NEGATE, "negate");
    }

    NodeRef* NodeRef::logicalAnd(NodeRef* other) const
    {
        return _binOp(BoolOp::AND, BitvectorOp::AND, "and", other);
    }

    NodeRef* NodeRef::logicalOr(NodeRef* other) const
    {
        return _binOp(BoolOp::OR, BitvectorOp::OR, "or", other);
    }

    NodeRef* NodeRef::logicalXor(NodeRef* other) const
    {
        return _binOp(BoolOp::XOR, BitvectorOp::XOR, "xor", other);
    }

    NodeRef* NodeRef::add(NodeRef* other) const
    {
        return _binOp(BitvectorOp::ADD, other);
    }

    NodeRef* NodeRef::addInt(int r) const
    {
        return _binOp(BitvectorOp::ADD, r);
    }

    NodeRef* NodeRef::raddInt(int r) const
    {
        return _binOpR(BitvectorOp::ADD, r);
    }

    NodeRef* NodeRef::sub(NodeRef* other) const
    {
        return _binOp(BitvectorOp::SUB, other);
    }

    NodeRef* NodeRef::subInt(int r) const
    {
        return _binOp(BitvectorOp::SUB, r);
    }

    NodeRef* NodeRef::rsubInt(int r) const
    {
        return _binOpR(BitvectorOp::SUB, r);
    }

    NodeRef* NodeRef::udiv(NodeRef* other) const
    {
        return _binOp(BitvectorOp::UDIV, other);
    }

    NodeRef* NodeRef::udivInt(int r) const
    {
        return _binOp(BitvectorOp::UDIV, r);
    }

    NodeRef* NodeRef::rudivInt(int r) const
    {
        return _binOpR(BitvectorOp::UDIV, r);
    }

    NodeRef* NodeRef::smod(NodeRef* other) const
    {
        return _binOp(BitvectorOp::SMOD, other);
    }

    NodeRef* NodeRef::smodInt(int r) const
    {
        return _binOp(BitvectorOp::SMOD, r);
    }

    NodeRef* NodeRef::rsmodInt(int r) const
    {
        return _binOpR(BitvectorOp::SMOD, r);
    }

    NodeRef* NodeRef::shl(NodeRef* other) const
    {
        return _binOp(BitvectorOp::SHL, other);
    }

    NodeRef* NodeRef::shlInt(int r) const
    {
        return _binOp(BitvectorOp::SHL, r);
    }

    NodeRef* NodeRef::rshlInt(int r) const
    {
        return _binOpR(BitvectorOp::SHL, r);
    }

    NodeRef* NodeRef::lshr(NodeRef* other) const
    {
        return _binOp(BitvectorOp::LSHR, other);
    }

    NodeRef* NodeRef::lshrInt(int r) const
    {
        return _binOp(BitvectorOp::LSHR, r);
    }

    NodeRef* NodeRef::rlshrInt(int r) const
    {
        return _binOpR(BitvectorOp::LSHR, r);
    }

    NodeRef* NodeRef::mul(NodeRef* other) const
    {
        return _binOp(BitvectorOp::MUL, other);
    }

    NodeRef* NodeRef::mulInt(int r) const
    {
        return _binOp(BitvectorOp::MUL, r);
    }

    NodeRef* NodeRef::rmulInt(int r) const
    {
        return _binOpR(BitvectorOp::MUL, r);
    }

    NodeRef* NodeRef::eq(NodeRef* other) const
    {
        return _cmpOp(BoolOp::EQUAL, other, false);
    }

    NodeRef* NodeRef::neq(NodeRef* other) const
    {
        return _cmpOp(BoolOp::DISTINCT, other, false);
    }

    NodeRef* NodeRef::ult(NodeRef* other) const
    {
        return _cmpOp(BoolOp::ULT, other, true);
    }

    NodeRef* NodeRef::ugt(NodeRef* other) const
    {
        return _cmpOp(BoolOp::UGT, other, true);
    }

    NodeRef* NodeRef::ule(NodeRef* other) const
    {
        return _cmpOp(BoolOp::ULE, other, true);
    }

    NodeRef* NodeRef::uge(NodeRef* other) const
    {
        return _cmpOp(BoolOp::UGE, other, true);
    }

    NodeRef* NodeRef::slice(int hi, int lo) const 
    {
        return _extractOp(this, hi, lo);
    }

    NodeRef* NodeRef::getItem(NodeRef* idx) const
    {
        if (!checkAbstractions(this, idx)) return NULL;
        if (node->type.isBitvector()) {
            return _binOp(BitvectorOp::GET_BIT, idx);
        } else if (node->type.isMem()) {
            return _binOp(BitvectorOp::READMEM, idx);
        } else {
            throw PyILAException(
                PyExc_TypeError,
                "Incorrect types for indexing operator.");
            return NULL;
        }
    }

    NodeRef* NodeRef::getItemInt(int idx) const
    {
        return _extractOp(this, idx, idx); // TODO
    }

    NodeRef* NodeRef::eqInt(int r) const
    {
        return _cmpOp(BoolOp::EQUAL, r);
    }

    NodeRef* NodeRef::neqInt(int r) const
    {
        return _cmpOp(BoolOp::DISTINCT, r);
    }

    NodeRef* NodeRef::ultInt(int r) const
    {
        return _cmpOp(BoolOp::ULT, r);
    }

    NodeRef* NodeRef::ugtInt(int r) const
    {
        return _cmpOp(BoolOp::UGT, r);
    }

    NodeRef* NodeRef::uleInt(int r) const
    {
        return _cmpOp(BoolOp::ULE, r);
    }

    NodeRef* NodeRef::ugeInt(int r) const
    {
        return _cmpOp(BoolOp::UGE, r);
    }

    py::object NodeRef::value() const
    {
        return node->getValue();
    }

    // ---------------------------------------------------------------------- //
    // static functions.

    NodeRef* NodeRef::store(NodeRef* mem, NodeRef* addr, NodeRef* data)
    {
        if (!checkAbstractions(mem, addr, data)) return NULL;
        return new NodeRef(new MemWr(mem->node, addr->node, data->node));
    }

    NodeRef* NodeRef::logicalXnor(NodeRef* l, NodeRef* r)
    {
        return _binOp(BoolOp::XNOR, BitvectorOp::XNOR, "xnor", l, r);
    }

    NodeRef* NodeRef::logicalNand(NodeRef* l, NodeRef* r)
    {
        return _binOp(BoolOp::NAND, BitvectorOp::NAND, "nand", l, r);
    }

    NodeRef* NodeRef::logicalNor(NodeRef* l, NodeRef* r)
    {
        return _binOp(BoolOp::NOR, BitvectorOp::NOR, "nor", l, r);
    }

    NodeRef* NodeRef::sdiv(NodeRef* l, NodeRef* r)
    {
        return _binOp(BitvectorOp::SDIV, l, r);
    }

    NodeRef* NodeRef::sdivInt(NodeRef* l, int r)
    {
        return _binOp(BitvectorOp::SDIV, l, r);
    }

    NodeRef* NodeRef::rsdivInt(int l, NodeRef* r)
    {
        return _binOpR(BitvectorOp::SDIV, l, r);
    }

    NodeRef* NodeRef::srem(NodeRef* l, NodeRef* r)
    {
        return _binOp(BitvectorOp::SREM, l, r);
    }

    NodeRef* NodeRef::sremInt(NodeRef* l, int r)
    {
        return _binOp(BitvectorOp::SREM, l, r);
    }

    NodeRef* NodeRef::rsremInt(int l, NodeRef* r)
    {
        return _binOpR(BitvectorOp::SREM, l, r);
    }

    NodeRef* NodeRef::urem(NodeRef* l, NodeRef* r)
    {
        return _binOp(BitvectorOp::UREM, l, r);
    }

    NodeRef* NodeRef::uremInt(NodeRef* l, int r)
    {
        return _binOp(BitvectorOp::UREM, l, r);
    }

    NodeRef* NodeRef::ruremInt(int l, NodeRef* r)
    {
        return _binOpR(BitvectorOp::UREM, l, r);
    }

    NodeRef* NodeRef::ashr(NodeRef* l, NodeRef* r)
    {
        return _binOp(BitvectorOp::ASHR, l, r);
    }

    NodeRef* NodeRef::ashrInt(NodeRef* l, int r)
    {
        return _binOp(BitvectorOp::ASHR, l, r);
    }

    NodeRef* NodeRef::rashrInt(int l, NodeRef* r)
    {
        return _binOp(BitvectorOp::ASHR, r, l);
    }

    NodeRef* NodeRef::concat(NodeRef* hi, NodeRef* lo)
    {
        return _binOp(BitvectorOp::CONCAT, hi, lo);
    }

    NodeRef* NodeRef::lrotate(NodeRef* obj, int par)
    {
        return _binOp(BitvectorOp::LROTATE, obj, par);
    }

    NodeRef* NodeRef::rrotate(NodeRef* obj, int par)
    {
        return _binOp(BitvectorOp::RROTATE, obj, par);
    }

    NodeRef* NodeRef::slt(NodeRef* l, NodeRef* r) 
    {
        return _cmpOp(BoolOp::SLT, l, r, true);
    }

    NodeRef* NodeRef::sgt(NodeRef* l, NodeRef* r)
    {
        return _cmpOp(BoolOp::SGT, l, r, true);
    }

    NodeRef* NodeRef::sle(NodeRef* l, NodeRef* r)
    {
        return _cmpOp(BoolOp::SLE, l, r, true);
    }

    NodeRef* NodeRef::sge(NodeRef* l, NodeRef* r)
    {
        return _cmpOp(BoolOp::SGE, l, r, true);
    }

    NodeRef* NodeRef::sltInt(NodeRef* l, int r) 
    {
        return _cmpOp(BoolOp::SLT, l, r);
    }

    NodeRef* NodeRef::sgtInt(NodeRef* l, int r) 
    {
        return _cmpOp(BoolOp::SGT, l, r);
    }

    NodeRef* NodeRef::sleInt(NodeRef* l, int r) 
    {
        return _cmpOp(BoolOp::SLE, l, r);
    }

    NodeRef* NodeRef::sgeInt(NodeRef* l, int r) 
    {
        return _cmpOp(BoolOp::SGE, l, r);
    }

    NodeRef* NodeRef::zero_extend(NodeRef* obj, int outWidth)
    {
        return _binOp(BitvectorOp::Z_EXT, obj, outWidth);
    }

    NodeRef* NodeRef::sign_extend(NodeRef* obj, int outWidth)
    {
        return _binOp(BitvectorOp::S_EXT, obj, outWidth);
    }

    NodeRef* NodeRef::nonzero(NodeRef* obj)
    {
        return obj->neqInt(0);
    }

    NodeRef* NodeRef::imply(NodeRef* p, NodeRef* q)
    {
        return _binOp(BoolOp::IMPLY, p, q);
    }

    NodeRef* NodeRef::ite(NodeRef* cond, NodeRef* trueExp, NodeRef* falseExp)
    {
        return _triOp(BoolOp::IF, BitvectorOp::IF, cond, trueExp, falseExp);
    }

    NodeRef* NodeRef::choice2(const std::string& name, NodeRef* e1, NodeRef* e2)
    {
        std::vector< nptr_t > args = { e1->node, e2->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choice3(
        const std::string& name, NodeRef* e1, NodeRef* e2, NodeRef* e3)
    {
        std::vector< nptr_t > args = { e1->node, e2->node, e3->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choice4(
        const std::string& name, NodeRef* e1, NodeRef* e2, NodeRef* e3, NodeRef* e4)
    {
        std::vector< nptr_t > args = { e1->node, e2->node, e3->node, e4->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choice5(const std::string& name, 
                              NodeRef* e1, NodeRef* e2, 
                              NodeRef* e3, NodeRef* e4, NodeRef* e5)
    {
        std::vector< nptr_t > args = 
            { e1->node, e2->node, e3->node, e4->node, e5->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choice6(const std::string& name, 
                              NodeRef* e1, NodeRef* e2, NodeRef* e3,
                              NodeRef* e4, NodeRef* e5, NodeRef* e6)
    {
        std::vector< nptr_t > args = 
            { e1->node, e2->node, e3->node, e4->node, e5->node, e6->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choiceL(const std::string& name, const py::list& l)
    {
        std::vector<nptr_t> args;
        if (py::len(l) < 2) {
            throw PyILAException(
                PyExc_RuntimeError,
                "Must have at least two choices.");
            return NULL;
        }

        for (unsigned i=0; i != py::len(l); i++) {
            py::extract<NodeRef&> ni(l[i]);
            if (ni.check()) {
                args.push_back(ni().node);
            } else {
                throw PyILAException(
                    PyExc_TypeError,
                    "Argument to choice must be a node.");
            }
        }
        return _choice(name, args);
    }

    NodeRef* NodeRef::inRange(const std::string& name, 
                              NodeRef* lo, NodeRef* hi)
    {
        if(!checkAbstractions(lo, hi)) return NULL;
        return new NodeRef(new BVInRange(lo->node->ctx, name, lo->node, hi->node));
    }

    NodeRef* NodeRef::readSlice(const std::string& name, NodeRef* bv, int w)
    {
        if (!bv->node->type.isBitvector() || bv->node->type.bitWidth <= w || w <= 0) {
            throw PyILAException(
                PyExc_TypeError, 
                "Argument to readslice must be a bitvector of width greater than result width.");
            return NULL;
        }
        return new NodeRef(
            ReadSlice::createReadSlice(bv->node->ctx, name, bv->node, w));
    }

    // ---------------------------------------------------------------------- //
    NodeRef* NodeRef::_unOp(
        BoolOp::Op opBool, BitvectorOp::Op opBv, const char* opName) const
    {
        if (opBv != BitvectorOp::INVALID && node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(node->ctx, opBv, node));
        } else if (opBool != BoolOp::INVALID && node->type.isBool()) {
            return new NodeRef(new BoolOp(node->ctx, opBool, node));
        } else {
            throw PyILAException(PyExc_TypeError, std::string("Incorrect type for ") + 
                                 opName);
            return NULL;
        }
    }

    NodeRef* NodeRef::_binOp(
        BoolOp::Op boolOp, 
        BitvectorOp::Op bvOp, 
        const char* opName,
        NodeRef* other) const
    {
        if (!checkAbstractions(this, other)) return NULL;

        if (boolOp != BoolOp::INVALID && node->type.isBool()) {
            return new NodeRef(new BoolOp(
                        node->ctx, boolOp, node, other->node));
        } else if (bvOp != BitvectorOp::INVALID && node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        node->ctx, bvOp, node, other->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 std::string("Incorrect type for ")
                                 + opName);
        }
    }

    NodeRef* NodeRef::_binOp(BitvectorOp::Op op, NodeRef* other) const
    {
        if (!checkAbstractions(this, other)) return NULL;

        if (node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        node->ctx, op, node, other->node));
        } else if (node->type.isMem() && other->node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        node->ctx, op, node, other->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " + 
                                 BitvectorOp::operatorNames[op]);
        }
    }

    NodeRef* NodeRef::_binOp(BitvectorOp::Op op, int r) const
    {
        if (node->type.isBitvector()) {
            nptr_t node_r(
                new BitvectorConst(node->ctx, r, node->type.bitWidth));

            return new NodeRef(new BitvectorOp(
                        node->ctx, op, node, node_r));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
        }
    }

    NodeRef* NodeRef::_binOpR(BitvectorOp::Op op, int r) const
    {
        if (node->type.isBitvector()) {
            nptr_t node_r(
                new BitvectorConst(node->ctx, r, node->type.bitWidth));

            return new NodeRef(new BitvectorOp(
                        node->ctx, op, node_r, node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
        }
    }

    // bvtype = true means this operator can only be applied
    // on bitvector type objects.
    NodeRef* NodeRef::_cmpOp(BoolOp::Op op, 
                             NodeRef* other,
                             bool bvtype) const
    {
        if (!checkAbstractions(this, other)) return NULL;
        if (node->ctx != other->node->ctx) {
            throw PyILAException(
                PyExc_RuntimeError,
                "Operands must belong to the same Abstraction.");
            return NULL;
        } else if (node->type == other->node->type &&
                   (!bvtype || node->type.isBitvector())) {
            return new NodeRef(
                        new BoolOp(node->ctx, op, node, other->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                  "Incorrect type for " + 
                                  BoolOp::operatorNames[op]);
            return NULL;
        }
    }

    NodeRef* NodeRef::_cmpOp(BoolOp::Op op, int r) const
    {
        if (node->type.isBitvector()) {
            nptr_t node_r(
                new BitvectorConst(node->ctx, r, node->type.bitWidth));
            return new NodeRef(new BoolOp(node->ctx, op, node, node_r));
        } else {
            throw PyILAException(PyExc_TypeError,
                                  "Incorrect type for " + 
                                  BoolOp::operatorNames[op]);
            return NULL;
        }
        return NULL;
    }

    // ---------------------------------------------------------------------- //
    // static methods

    // bvtype = true means this operator can only be applied
    // on bitvector type objects.
    NodeRef* NodeRef::_cmpOp(BoolOp::Op op, 
                             NodeRef* l, NodeRef* r, 
                             bool bvonly)
    {
        if (!checkAbstractions(l, r)) return NULL;
        if (l->node->type == r->node->type &&
                   (!bvonly || l->node->type.isBitvector())) {
            return new NodeRef(
                        new BoolOp(l->node->ctx, op, l->node, r->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                  "Incorrect type for " + 
                                  BoolOp::operatorNames[op]);
            return NULL;
        }
    }
    // Only bitvector can compare with int
    NodeRef* NodeRef::_cmpOp(BoolOp::Op op, NodeRef* l, int r)
    {
        if (l->node->type.isBitvector()) {
            nptr_t node_r(
                new BitvectorConst(l->node->ctx, r, l->node->type.bitWidth));
            return new NodeRef(new BoolOp(l->node->ctx, op, l->node, node_r));
        } else {
            throw PyILAException(PyExc_TypeError,
                                  "Incorrect type for " + 
                                  BoolOp::operatorNames[op]);
            return NULL;
        }
        return NULL;
    }

    NodeRef* NodeRef::_binOp(
        BoolOp::Op boolOp, 
        BitvectorOp::Op bvOp, 
        const char* opName,
        NodeRef* l,
        NodeRef* r)
    {
        if (!checkAbstractions(l, r)) return NULL;
        if (boolOp != BoolOp::INVALID && l->node->type.isBool()) {
            return new NodeRef(new BoolOp(
                        l->node->ctx, boolOp, l->node, r->node));
        } else if (bvOp != BitvectorOp::INVALID && l->node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        l->node->ctx, bvOp, l->node, r->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 std::string("Incorrect type for ")
                                 + opName);
            return NULL;
        }
    }

    NodeRef* NodeRef::_binOp(BoolOp::Op op, NodeRef* l, NodeRef* r)
    {
        if (!checkAbstractions(l, r)) return NULL;
        if (l->node->type.isBool() && r->node->type.isBool()) {
            return new NodeRef(new BoolOp(
                        l->node->ctx, op, l->node, r->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " + 
                                 BoolOp::operatorNames[op]);
            return NULL;
        }
    }


    NodeRef* NodeRef::_binOp(BitvectorOp::Op op, NodeRef* l, NodeRef* r)
    {
        if (!checkAbstractions(l, r)) return NULL;
        if (l->node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                       l->node->ctx, op, l->node, r->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " + 
                                 BitvectorOp::operatorNames[op]);
            return NULL;
        }
    }

    NodeRef* NodeRef::_binOp(BitvectorOp::Op op, NodeRef* l, int r)
    {
        if (l->node->type.isBitvector()) {
            if (op >= BitvectorOp::Op::LROTATE && 
                op <= BitvectorOp::Op::S_EXT)
            {
                return new NodeRef(new BitvectorOp(
                            l->node->ctx, op, l->node, r));
            } else {
                nptr_t node_r(
                    new BitvectorConst(l->node->ctx, r, l->node->type.bitWidth));

                return new NodeRef(new BitvectorOp(
                            l->node->ctx, op, l->node, node_r));
            }
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
            return NULL;
        }
    }

    NodeRef* NodeRef::_binOpR(BitvectorOp::Op op, int l, NodeRef* r)
    {
        if (r->node->type.isBitvector()) {
            nptr_t node_l(
                new BitvectorConst(r->node->ctx, l, r->node->type.bitWidth));

            return new NodeRef(new BitvectorOp(
                        r->node->ctx, op, node_l, r->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
            return NULL;
        }
    }

    NodeRef* NodeRef::_triOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp,
                             NodeRef* cond, NodeRef* trueExp, NodeRef* falseExp)
    {
        if (!checkAbstractions(cond, trueExp, falseExp)) return NULL;

        if (trueExp->node->type != falseExp->node->type ||
            !cond->node->type.isBool())
        {
            throw PyILAException(PyExc_TypeError, "Incorrect type for ITE");
            return NULL;
        } else {
            NodeRef* normCond = (cond->node->type.isBool())? cond : NodeRef::nonzero(cond);
            std::vector< nptr_t > args_;
            args_.push_back(normCond->node);
            args_.push_back(trueExp->node);
            args_.push_back(falseExp->node);
            if (trueExp->node->type.isBool() && boolOp != BoolOp::INVALID) {
                return new NodeRef( new BoolOp(normCond->node->ctx, boolOp, args_) );
            } else if (trueExp->node->type.isBitvector() && bvOp != BitvectorOp::INVALID) {
                return new NodeRef( new BitvectorOp(normCond->node->ctx, bvOp, args_) );
            } else {
                throw PyILAException(PyExc_TypeError, "Incorrect type for ITE");
                return NULL;
            }
        }
        return NULL;
    }

    NodeRef* NodeRef::_extractOp(const NodeRef* obj, int beg, int end)
    {
        if (!obj->node->type.isBitvector())
        {
            throw PyILAException(PyExc_TypeError, "Incorrect type for extract.");
            return NULL;
        } else {
            return new NodeRef( 
                new BitvectorOp(
                    obj->node->ctx, 
                    BitvectorOp::EXTRACT, 
                    obj->node, beg, end));
        }
    }

    NodeRef* NodeRef::_choice(const std::string& name, 
                              const std::vector<nptr_t>& args)
    {
        if (!checkAbstractions(args)) return NULL;

        NodeType t = Choice::getChoiceType(args);
        if (!t) {
            throw PyILAException(PyExc_TypeError, 
                "Type mismatch in choice arguments.");
            return NULL;
        } else {
            auto ctx = args[0]->context();
            if (t.isBool()) {
                return new NodeRef(new BoolChoice(ctx, name, args));
            } else if (t.isBitvector()) {
                return new NodeRef(new BitvectorChoice(ctx, name, args));
            } else if (t.isMem()) {
                return new NodeRef(new MemChoice(ctx, name, args));
            } else {
                throw PyILAException(PyExc_ValueError,
                    "Unable to create choice of specified type.");
                return NULL;
            }
        }
    }


    // ---------------------------------------------------------------------- //
    std::ostream& operator<<(std::ostream& out, const NodeRef& n)
    {
        return (out << *n.node.get());
    }

    // ---------------------------------------------------------------------- //
    bool checkAbstractions(const NodeRef* l1, const NodeRef* l2)
    {
        if (l1->node->context() != l2->node->context()) {
            throw PyILAException(PyExc_RuntimeError,
                "Operands must be from the same Abstraction.");
            return false;
        }
        return true;
    }

    bool checkAbstractions(const NodeRef* l1, const NodeRef* l2, const NodeRef* l3)
    {
        if (l1->node->context() != l2->node->context() || 
            l2->node->context() != l3->node->context()) 
        {
            throw PyILAException(PyExc_RuntimeError,
                "Operands must be from the same Abstraction.");
            return false;
        }
        return true;
    }

    bool checkAbstractions(const std::vector<nptr_t>& args)
    {
        if (args.size() == 0) {
            throw PyILAException(PyExc_RuntimeError,
                                 "At least one operand is required.");
            return false;
        }
        auto ctx = args[0]->context();
        for (auto a : args) {
            if (a->context() != ctx) {
                throw PyILAException(PyExc_RuntimeError,
                    "Operands must be from the same Abstraction.");
                return false;
            }
        }
        return true;
    }

}
