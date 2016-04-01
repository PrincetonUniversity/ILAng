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
        node->setNodeRef(this);
    }

    NodeRef::NodeRef(Node* n)
      : node(n)
    {
        node->setNodeRef(this);
    }

    NodeRef::NodeRef(const NodeRef& nr)
      : node(nr.node)
    {
        node->setNodeRef(this);
    }

    NodeRef::~NodeRef()
    {
    }

    NodeRef& NodeRef::operator=(const NodeRef& other)
    {
        if(this != &other) { 
            node = other.node;
            node->setNodeRef(this);
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

    void NodeRef::doSomething() 
    {
        return node->doSomething();
    }

    bool NodeRef::equal(NodeRef* other) const
    {
        return node->equal(other->node.get());
    }

    // ---------------------------------------------------------------------- //
    NodeRef* NodeRef::complement() const
    {
        return _unOp(
            BoolOp::NOT,
            BitvectorOp::COMPLEMENT,
            "complement");
    }

    NodeRef* NodeRef::negate() const
    {
        return _unOp(
            BoolOp::INVALID,
            BitvectorOp::NEGATE,
            "negate");
    }

    NodeRef* NodeRef::logicalNot() const
    {
        return _unOp(
            BoolOp::NOT,
            BitvectorOp::INVALID,
            "not");
    }

    NodeRef* NodeRef::logicalAnd(NodeRef* other) const
    {
        return _binOp(BoolOp::AND, BitvectorOp::AND,
                        "and", other);
    }

    NodeRef* NodeRef::logicalOr(NodeRef* other) const
    {
        return _binOp(BoolOp::OR, BitvectorOp::OR,
                        "or", other);
    }

    NodeRef* NodeRef::logicalXor(NodeRef* other) const
    {
        return _binOp(BoolOp::XOR, BitvectorOp::XOR,
                        "xor", other);
    }

    NodeRef* NodeRef::logicalXnor(NodeRef* other) const
    {
        return _binOp(BoolOp::XNOR, BitvectorOp::XNOR,
                        "xnor", other);
    }

    NodeRef* NodeRef::logicalNand(NodeRef* other) const
    {
        return _binOp(BoolOp::NAND, BitvectorOp::NAND,
                        "nand", other);
    }

    NodeRef* NodeRef::logicalNor(NodeRef* other) const
    {
        return _binOp(BoolOp::NOR, BitvectorOp::NOR,
                        "nor", other);
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

    NodeRef* NodeRef::sdiv(NodeRef* other) const
    {
        return _binOp(BitvectorOp::SDIV, other);
    }

    NodeRef* NodeRef::udiv(NodeRef* other) const
    {
        return _binOp(BitvectorOp::UDIV, other);
    }

    NodeRef* NodeRef::sdivInt(int r) const
    {
        return _binOp(BitvectorOp::SDIV, r);
    }

    NodeRef* NodeRef::udivInt(int r) const
    {
        return _binOp(BitvectorOp::UDIV, r);
    }

    NodeRef* NodeRef::rsdivInt(int r) const
    {
        return _binOpR(BitvectorOp::SDIV, r);
    }

    NodeRef* NodeRef::rudivInt(int r) const
    {
        return _binOpR(BitvectorOp::UDIV, r);
    }

    NodeRef* NodeRef::srem(NodeRef* other) const
    {
        return _binOp(BitvectorOp::SREM, other);
    }

    NodeRef* NodeRef::urem(NodeRef* other) const
    {
        return _binOp(BitvectorOp::UREM, other);
    }

    NodeRef* NodeRef::sremInt(int r) const
    {
        return _binOp(BitvectorOp::SREM, r);
    }

    NodeRef* NodeRef::uremInt(int r) const
    {
        return _binOp(BitvectorOp::UREM, r);
    }

    NodeRef* NodeRef::smod(NodeRef* other) const
    {
        return _binOp(BitvectorOp::SMOD, other);
    }

    NodeRef* NodeRef::smodInt(int r) const
    {
        return _binOp(BitvectorOp::SMOD, r);
    }

    NodeRef* NodeRef::shl(NodeRef* other) const
    {
        return _binOp(BitvectorOp::SHL, other);
    }

    NodeRef* NodeRef::shlInt(int r) const
    {
        return _binOp(BitvectorOp::SHL, r);
    }

    NodeRef* NodeRef::lshr(NodeRef* other) const
    {
        return _binOp(BitvectorOp::LSHR, other);
    }

    NodeRef* NodeRef::lshrInt(int r) const
    {
        return _binOp(BitvectorOp::LSHR, r);
    }

    NodeRef* NodeRef::ashr(NodeRef* other) const
    {
        return _binOp(BitvectorOp::LSHR, other);
    }

    NodeRef* NodeRef::ashrInt(int r) const
    {
        return _binOp(BitvectorOp::LSHR, r);
    }

    NodeRef* NodeRef::mul(NodeRef* other) const
    {
        return _binOp(BitvectorOp::MUL, other);
    }

    NodeRef* NodeRef::mulInt(int r) const
    {
        return _binOp(BitvectorOp::MUL, r);
    }

    NodeRef* NodeRef::concat(NodeRef* other) const
    {
        return _binOp(BitvectorOp::CONCAT, other);
    }

    NodeRef* NodeRef::eq(NodeRef* other) const
    {
        return _cmpOp(BoolOp::EQUAL, other);
    }

    NodeRef* NodeRef::neq(NodeRef* other) const
    {
        return _cmpOp(BoolOp::DISTINCT, other);
    }

    NodeRef* NodeRef::slt(NodeRef* other) const
    {
        return _cmpOp(BoolOp::SLT, other);
    }

    NodeRef* NodeRef::sgt(NodeRef* other) const
    {
        return _cmpOp(BoolOp::SGT, other);
    }

    NodeRef* NodeRef::sle(NodeRef* other) const
    {
        return _cmpOp(BoolOp::SLE, other);
    }

    NodeRef* NodeRef::sge(NodeRef* other) const
    {
        return _cmpOp(BoolOp::SGE, other);
    }

    NodeRef* NodeRef::ult(NodeRef* other) const
    {
        return _cmpOp(BoolOp::ULT, other);
    }

    NodeRef* NodeRef::ugt(NodeRef* other) const
    {
        return _cmpOp(BoolOp::UGT, other);
    }

    NodeRef* NodeRef::ule(NodeRef* other) const
    {
        return _cmpOp(BoolOp::ULE, other);
    }

    NodeRef* NodeRef::uge(NodeRef* other) const
    {
        return _cmpOp(BoolOp::UGE, other);
    }

    NodeRef* NodeRef::ite(NodeRef* thenExp, NodeRef* elseExp) const
    {
        return _triOp(BoolOp::IF, BitvectorOp::IF, "if", thenExp, elseExp);
    }

    boost::python::object NodeRef::value() const
    {
        return node->getValue();
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
            throw PyILAException(PyExc_TypeError,
                                 std::string("Incorrect type for ") + 
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
        if (node->ctx != other->node->ctx) {
            throw PyILAException(
                PyExc_RuntimeError,
                "Both operands of a binary operator must be from the same Abstraction.");
            return NULL;
        } else if (boolOp != BoolOp::INVALID && node->type.isBool()) {
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
        if (node->ctx != other->node->ctx) {
            throw PyILAException(
                PyExc_RuntimeError,
                "Both operands of a binary operator must be from the same Abstraction.");
            return NULL;
        } else if (node->type.isBitvector()) {
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
            boost::shared_ptr<Node> node_r(
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
            boost::shared_ptr<Node> node_r(
                new BitvectorConst(node->ctx, r, node->type.bitWidth));

            return new NodeRef(new BitvectorOp(
                        node->ctx, op, node_r, node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
        }
    }

    NodeRef* NodeRef::_cmpOp(BoolOp::Op op, 
                             NodeRef* other) const
    {
        if (node->ctx != other->node->ctx) {
            throw PyILAException(
                PyExc_RuntimeError,
                "Operands must belong to the same Abstraction.");
            return NULL;
        } else if (node->type == other->node->type) {
            return new NodeRef(
                        new BoolOp(node->ctx, op, node, other->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                  "Incorrect type for " + 
                                  BoolOp::operatorNames[op]);
            return NULL;
        }
    }

    NodeRef* NodeRef::_triOp(
        BoolOp::Op opBool,
        BitvectorOp::Op opBv,
        const char* opName,
        NodeRef* exp1,
        NodeRef* exp2) const
    {
        if (exp1->node->ctx != exp2->node->ctx) {
            throw PyILAException(
                PyExc_RuntimeError,
                "2nd and 3rd operands of a ternary operator must be from the same Abstraction.");
            return NULL;
        } else if (exp1->node->type == exp2->node->type) {
            std::vector< boost::shared_ptr<Node> > args_;
            args_.push_back(node);
            args_.push_back(exp1->node);
            args_.push_back(exp2->node);
            if (opBool != BoolOp::INVALID && exp1->node->type.isBool()) {
                return new NodeRef( new BoolOp(node->ctx, opBool, args_) );
            } else if (opBv != BitvectorOp::INVALID && 
                       exp1->node->type.isBitvector()) {
                return new NodeRef( new BitvectorOp(node->ctx, opBv, args_) );
            } else {
                throw PyILAException(PyExc_TypeError, 
                        std::string("Incorrect type for") + opName); 
                return NULL;
            }
        } else {
            throw PyILAException(PyExc_TypeError, 
                    std::string("Incorrect type for ") + opName); 
            return NULL;
        } 
    }

    // ---------------------------------------------------------------------- //
    std::ostream& operator<<(std::ostream& out, const NodeRef& n)
    {
        return (n.node->write(out));
    }
}
