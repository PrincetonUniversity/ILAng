#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <abstraction.hpp>
#include <simplify.hpp>
#include <ast/hash.hpp>

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
        // stupid cout to help debug. need a better solution.
        // std::cout << "destroying: " << *node.get() << std::endl;
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

    NodeRef* NodeRef::logicalAndInt(int r) const 
    {
        return _binOp(BitvectorOp::AND, r);
    }

    NodeRef* NodeRef::logicalAndRInt(int l) const
    {
        return _binOpR(BitvectorOp::AND, l);
    }

    NodeRef* NodeRef::logicalOr(NodeRef* other) const
    {
        return _binOp(BoolOp::OR, BitvectorOp::OR, "or", other);
    }

    NodeRef* NodeRef::logicalOrInt(int r) const
    {
        return _binOp(BitvectorOp::OR, r);
    }

    NodeRef* NodeRef::logicalOrRInt(int l) const
    {
        return _binOpR(BitvectorOp::OR, l);
    }

    NodeRef* NodeRef::logicalXor(NodeRef* other) const
    {
        return _binOp(BoolOp::XOR, BitvectorOp::XOR, "xor", other);
    }

    NodeRef* NodeRef::logicalXorInt(int r) const
    {
        return _binOp(BitvectorOp::XOR, r);
    }

    NodeRef* NodeRef::logicalXorRInt(int l) const
    {
        return _binOpR(BitvectorOp::XOR, l);
    }

    // add //
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

    // sub //
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

    // udiv //
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

    // urem //
    NodeRef* NodeRef::urem(NodeRef* r)
    {
        return _binOp(BitvectorOp::UREM, r);
    }

    NodeRef* NodeRef::uremInt(int r)
    {
        return _binOp(BitvectorOp::UREM, r);
    }

    NodeRef* NodeRef::ruremInt(int l)
    {
        return _binOpR(BitvectorOp::UREM, l);
    }

    // shl
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

    // shr //
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

    // mul //
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

    // eq/neq //
    NodeRef* NodeRef::eq(NodeRef& other) const
    {
        return _cmpOp(BoolOp::EQUAL, other, false);
    }

    NodeRef* NodeRef::neq(NodeRef& other) const
    {
        return _cmpOp(BoolOp::DISTINCT, other, false);
    }

    // lt/gt //
    NodeRef* NodeRef::ult(NodeRef& other) const
    {
        return _cmpOp(BoolOp::ULT, other, true);
    }

    NodeRef* NodeRef::ugt(NodeRef& other) const
    {
        return _cmpOp(BoolOp::UGT, other, true);
    }

    // le/ge //
    NodeRef* NodeRef::ule(NodeRef& other) const
    {
        return _cmpOp(BoolOp::ULE, other, true);
    }

    NodeRef* NodeRef::uge(NodeRef& other) const
    {
        return _cmpOp(BoolOp::UGE, other, true);
    }

    // slice //
    NodeRef* NodeRef::slice(int hi, int lo) const 
    {
        return _extractOp(this, hi, lo);
    }

    void NodeRef::setRefName(const std::string & refName)
    {
        this->node->setRefName( refName );
    }
    
    NodeRef* NodeRef::getItem(NodeRef* idx) const
    {
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

    NodeRef* NodeRef::load(NodeRef* mem, NodeRef* addr)
    {
        const NodeType& mt = mem->node->type;
        const NodeType& at = addr->node->type;
        if (!mt.isMem()                     ||
            !at.isBitvector(mt.addrWidth))
        {
            throw PyILAException(PyExc_TypeError,
                "Type error in arguments.");
            return NULL;
        }
        return new NodeRef(new BitvectorOp(
            BitvectorOp::READMEM, 
            mem->node, addr->node));
    }

    NodeRef* NodeRef::loadblock(NodeRef* mem, NodeRef* addr, int chunks)
    {
        const NodeType& mt = mem->node->type;
        const NodeType& at = addr->node->type;
        if (!mt.isMem()                     ||
            !at.isBitvector(mt.addrWidth))
        {
            throw PyILAException(PyExc_TypeError,
                "Type error in arguments.");
            return NULL;
        }
        if (chunks <= 0) {
            throw PyILAException(PyExc_ValueError,
                "Invalid number of blocks.");
            return NULL;
        }

        return new NodeRef(new BitvectorOp(
            BitvectorOp::READMEMBLOCK, 
            mem->node, addr->node, chunks, 
            LITTLE_E));
    }

    NodeRef* NodeRef::loadblockB(NodeRef* mem, NodeRef* addr, int chunks)
    {
        const NodeType& mt = mem->node->type;
        const NodeType& at = addr->node->type;
        if (!mt.isMem()                     ||
            !at.isBitvector(mt.addrWidth))
        {
            throw PyILAException(PyExc_TypeError,
                "Type error in arguments.");
            return NULL;
        }
        if (chunks <= 0) {
            throw PyILAException(PyExc_ValueError,
                "Invalid number of blocks.");
            return NULL;
        }

        return new NodeRef(new BitvectorOp(
            BitvectorOp::READMEMBLOCK, 
            mem->node, addr->node, chunks, 
            BIG_E));
    }

    NodeRef* NodeRef::store(NodeRef* mem, NodeRef* addr, NodeRef* data)
    {
        const NodeType& mt = mem->node->type;
        const NodeType& at = addr->node->type;
        const NodeType& dt = data->node->type;
        if (!mt.isMem()                     ||
            !at.isBitvector(mt.addrWidth)   ||
            !dt.isBitvector(mt.dataWidth))
        {
            throw PyILAException(PyExc_TypeError,
                "Type error in arguments.");
            return NULL;
        }
        return new NodeRef(new MemOp(
            MemOp::STORE, mem->node, addr->node, data->node));
    }

    NodeRef* NodeRef::storeblock(NodeRef* mem, NodeRef* addr, NodeRef* data)
    {
        const NodeType& mt = mem->node->type;
        const NodeType& at = addr->node->type;
        const NodeType& dt = addr->node->type;
        if (!mt.isMem()                     ||
            !at.isBitvector(mt.addrWidth)   ||
            !dt.isBitvector()               ||
            dt.bitWidth % mt.dataWidth != 0)
        {
            throw PyILAException(PyExc_TypeError,
                "Type error in arguments.");
            return NULL;
        }
        return new NodeRef(new MemOp(
            MemOp::STOREBLOCK, 
            mem->node, addr->node, data->node,
            LITTLE_E));
    }

    NodeRef* NodeRef::storeblockB(NodeRef* mem, NodeRef* addr, NodeRef* data)
    {
        const NodeType& mt = mem->node->type;
        const NodeType& at = addr->node->type;
        const NodeType& dt = addr->node->type;
        if (!mt.isMem()                     ||
            !at.isBitvector(mt.addrWidth)   ||
            !dt.isBitvector()               ||
            dt.bitWidth % mt.dataWidth != 0)
        {
            throw PyILAException(PyExc_TypeError,
                "Type error in arguments.");
            return NULL;
        }
        return new NodeRef(new MemOp(
            MemOp::STOREBLOCK, 
            mem->node, addr->node, data->node,
            BIG_E));
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

    // sdiv //
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

    // smod //
    NodeRef* NodeRef::smod(NodeRef* l, NodeRef* r)
    {
        return _binOp(BitvectorOp::SMOD, l, r);
    }

    NodeRef* NodeRef::smodInt(NodeRef* l, int r)
    {
        return _binOp(BitvectorOp::SMOD, l, r);
    }

    NodeRef* NodeRef::rsmodInt(int l, NodeRef* r)
    {
        return _binOpR(BitvectorOp::SMOD, l, r);
    }

    // srem //
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

    NodeRef* NodeRef::concatList(const py::list& l)
    {
        nptr_vec_t args;
        // number of arguments.
        if (py::len(l) < 2) {
            throw PyILAException(
                PyExc_RuntimeError, "Must have two arguments.");
            return NULL;
        }
        // must all be nodes.
        for (unsigned i=0; i != py::len(l); i++) {
            py::extract<NodeRef&> ni(l[i]);
            if (ni.check()) {
                args.push_back(ni().node);
            } else {
                throw PyILAException(
                    PyExc_TypeError, "Argument to concat must be a node.");
                return NULL;
            }
        }
        // must all be bitvectors.
        for (unsigned i=0; i !=args.size(); i++) {
            if (!args[i]->type.isBitvector()) {
                throw PyILAException(
                    PyExc_TypeError, "Argument to concat must be a bitvector.");
                return NULL;
            }
        }

        // now finally create the expression.
        ILA_ASSERT(args.size() >= 2, "Must have two arguments.");
        nptr_t expr;
        for (int i=args.size()-2; i >= 0; i--) {
            const nptr_t& b1 = args[i];
            const nptr_t& b2 = args[i+1];
            if (i == (int)args.size()-2) {
                nptr_t arg(new BitvectorOp(
                    BitvectorOp::CONCAT,
                    b1, b2));
                expr = arg;
            } else {
                nptr_t arg(new BitvectorOp(
                    BitvectorOp::CONCAT,
                    b1, expr));
                expr = arg;
            }
        }
        return new NodeRef(expr);
    }

    NodeRef* NodeRef::lrotate(NodeRef* obj, int par)
    {
        return _binOp(BitvectorOp::LROTATE, obj, par);
    }

    NodeRef* NodeRef::rrotate(NodeRef* obj, int par)
    {
        return _binOp(BitvectorOp::RROTATE, obj, par);
    }

    NodeRef* NodeRef::slt(NodeRef& l, NodeRef& r) 
    {
        return _cmpOp(BoolOp::SLT, l, r, true);
    }

    NodeRef* NodeRef::sgt(NodeRef& l, NodeRef& r)
    {
        return _cmpOp(BoolOp::SGT, l, r, true);
    }

    NodeRef* NodeRef::sle(NodeRef& l, NodeRef& r)
    {
        return _cmpOp(BoolOp::SLE, l, r, true);
    }

    NodeRef* NodeRef::sge(NodeRef& l, NodeRef& r)
    {
        return _cmpOp(BoolOp::SGE, l, r, true);
    }

    NodeRef* NodeRef::sltInt(NodeRef& l, int r) 
    {
        return _cmpOp(BoolOp::SLT, l, r);
    }

    NodeRef* NodeRef::sgtInt(NodeRef& l, int r) 
    {
        return _cmpOp(BoolOp::SGT, l, r);
    }

    NodeRef* NodeRef::sleInt(NodeRef& l, int r) 
    {
        return _cmpOp(BoolOp::SLE, l, r);
    }

    NodeRef* NodeRef::sgeInt(NodeRef& l, int r) 
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

    NodeRef* NodeRef::imply(NodeRef& p, NodeRef& q)
    {
        return _binOp(BoolOp::IMPLY, p, q);
    }

    NodeRef* NodeRef::ite(NodeRef& cond, NodeRef& trueExp, NodeRef& falseExp)
    {
        return _triOp(BoolOp::IF, BitvectorOp::IF, MemOp::ITE, cond, trueExp, falseExp);
    }

    NodeRef* NodeRef::appfunc0(NodeRef* fun)
    {
        nptr_vec_t args = {fun->node};
        return _naryOp(BitvectorOp::APPLY_FUNC, args);
    }

    NodeRef* NodeRef::appfunc1(NodeRef* fun, NodeRef* arg)
    {
        nptr_vec_t args = {fun->node, arg->node};
        return _naryOp(BitvectorOp::APPLY_FUNC, args);
    }

    NodeRef* NodeRef::appfunc2(NodeRef* fun, NodeRef* arg0, NodeRef* arg1)
    {
        nptr_vec_t args = {fun->node, arg0->node, arg1->node};
        return _naryOp(BitvectorOp::APPLY_FUNC, args);
    }

    NodeRef* NodeRef::appfuncL(NodeRef* fun, const py::list& l)
    {
        nptr_vec_t args;
        args.push_back(fun->node);
        for (unsigned i=0; i != py::len(l); i++) {
            py::extract<NodeRef&> ni(l[i]);
            if (ni.check()) {
                args.push_back(ni().node);
            } else {
                throw PyILAException(
                    PyExc_TypeError,
                    "Argument to apply must be a node.");
            }
        }
        return _naryOp(BitvectorOp::APPLY_FUNC, args);
    }

    NodeRef* NodeRef::choice2(const std::string& name, NodeRef* e1, NodeRef* e2)
    {
        nptr_vec_t args = { e1->node, e2->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choice3(
        const std::string& name, NodeRef* e1, NodeRef* e2, NodeRef* e3)
    {
        nptr_vec_t args = { e1->node, e2->node, e3->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choice4(
        const std::string& name, NodeRef* e1, NodeRef* e2, NodeRef* e3, NodeRef* e4)
    {
        nptr_vec_t args = { e1->node, e2->node, e3->node, e4->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choice5(const std::string& name, 
                              NodeRef* e1, NodeRef* e2, 
                              NodeRef* e3, NodeRef* e4, NodeRef* e5)
    {
        nptr_vec_t args = 
            { e1->node, e2->node, e3->node, e4->node, e5->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choice6(const std::string& name, 
                              NodeRef* e1, NodeRef* e2, NodeRef* e3,
                              NodeRef* e4, NodeRef* e5, NodeRef* e6)
    {
        nptr_vec_t args = 
            { e1->node, e2->node, e3->node, e4->node, e5->node, e6->node };
        return _choice(name, args);
    }

    NodeRef* NodeRef::choiceL(const std::string& name, const py::list& l)
    {
        nptr_vec_t args;
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
        return new NodeRef(new BVInRange(name, lo->node, hi->node));
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
            ReadSlice::createReadSlice(name, bv->node, w, 1));
    }

    NodeRef* NodeRef::readChunk(const std::string& name, NodeRef* bv, int w)
    {
        if (!bv->node->type.isBitvector() || bv->node->type.bitWidth <= w || w <= 0) {
            throw PyILAException(
                PyExc_TypeError, 
                "Argument to readchunk must be a bitvector of width greater than result width.");
            return NULL;
        }
        if (!bv->node->type.bitWidth % w != 0) {
            throw PyILAException(
                PyExc_TypeError, 
                "Width of argument to readchunk must multiple of chunk size");
            return NULL;
        }

        return new NodeRef(
            ReadSlice::createReadSlice(name, bv->node, w, w));
    }

    NodeRef* NodeRef::writeSlice(const std::string& name, NodeRef* bv, NodeRef* wr)
    {
        if (!bv->node->type.isBitvector() || !wr->node->type.isBitvector() ||
            bv->node->type.bitWidth <= wr->node->type.bitWidth) {

            throw PyILAException(
                PyExc_TypeError, 
                "Incorrect types to writeslice arguments.");
            return NULL;
        }
        return new NodeRef(
            WriteSlice::createWriteSlice(name, bv->node, wr->node, 1));
    }

    NodeRef* NodeRef::writeChunk(const std::string& name, NodeRef* bv, NodeRef* wr)
    {
        if (!bv->node->type.isBitvector() || !wr->node->type.isBitvector() ||
            bv->node->type.bitWidth <= wr->node->type.bitWidth) {

            throw PyILAException(
                PyExc_TypeError, 
                "Incorrect types to writeslice arguments.");
            return NULL;
        }

        if (!bv->node->type.bitWidth % wr->node->type.bitWidth != 0) {
            throw PyILAException(
                PyExc_TypeError,
                "Bitwidth of bitvector not a multiple of data bitwidth."); 
        }
        return new NodeRef(
            WriteSlice::createWriteSlice(name, 
                bv->node, wr->node, wr->node->type.bitWidth));
    }

    NodeRef* NodeRef::simplify(NodeRef& n_assump, NodeRef& n_exp)
    {
        const nptr_t& assump = n_assump.node;
        const nptr_t& exp = n_exp.node;

        ITESimplifier ite_simp(assump);
        nptr_t simp_exp = ite_simp.simplify(exp.get());

        return new NodeRef(simp_exp);
    }

    size_t NodeRef::hash() const
    {
        return hash_value(*this->node.get());
    }

    // ---------------------------------------------------------------------- //
    NodeRef* NodeRef::_unOp(
        BoolOp::Op opBool, BitvectorOp::Op opBv, const char* opName) const
    {
        if (opBv != BitvectorOp::INVALID && node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(opBv, node));
        } else if (opBool != BoolOp::INVALID && node->type.isBool()) {
            return new NodeRef(new BoolOp(opBool, node));
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
        if (boolOp != BoolOp::INVALID && node->type.isBool()) {
            return new NodeRef(new BoolOp(
                        boolOp, node, other->node));
        } else if (bvOp != BitvectorOp::INVALID && node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        bvOp, node, other->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 std::string("Incorrect type for ")
                                 + opName);
        }
    }

    NodeRef* NodeRef::_binOp(BitvectorOp::Op op, NodeRef* other) const
    {
        if (node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        op, node, other->node));
        } else if (node->type.isMem() && other->node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        op, node, other->node));
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
                new BitvectorConst(r, node->type.bitWidth));

            return new NodeRef(new BitvectorOp(
                        op, node, node_r));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
        }
    }

    NodeRef* NodeRef::_binOpR(BitvectorOp::Op op, int r) const
    {
        if (node->type.isBitvector()) {
            nptr_t node_l(
                new BitvectorConst(r, node->type.bitWidth));

            return new NodeRef(new BitvectorOp(
                        op, node_l, node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
        }
    }

    // bvtype = true means this operator can only be applied
    // on bitvector type objects.
    NodeRef* NodeRef::_cmpOp(BoolOp::Op op, 
                             NodeRef& other,
                             bool bvtype) const
    {
        if (node->type == other.node->type &&
                   (!bvtype || node->type.isBitvector())) {
            return new NodeRef(
                        new BoolOp(op, node, other.node));
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
                new BitvectorConst(r, node->type.bitWidth));
            return new NodeRef(new BoolOp(op, node, node_r));
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
                             NodeRef& l, NodeRef& r, 
                             bool bvonly)
    {
        if (l.node->type == r.node->type &&
                   (!bvonly || l.node->type.isBitvector())) {
            return new NodeRef(
                        new BoolOp(op, l.node, r.node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                  "Incorrect type for " + 
                                  BoolOp::operatorNames[op]);
            return NULL;
        }
    }
    // Only bitvector can compare with int
    NodeRef* NodeRef::_cmpOp(BoolOp::Op op, NodeRef& l, int r)
    {
        if (l.node->type.isBitvector()) {
            nptr_t node_r(
                new BitvectorConst(r, l.node->type.bitWidth));
            return new NodeRef(new BoolOp(op, l.node, node_r));
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
        if (boolOp != BoolOp::INVALID && l->node->type.isBool()) {
            return new NodeRef(new BoolOp(
                        boolOp, l->node, r->node));
        } else if (bvOp != BitvectorOp::INVALID && l->node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(
                        bvOp, l->node, r->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 std::string("Incorrect type for ")
                                 + opName);
            return NULL;
        }
    }

    NodeRef* NodeRef::_binOp(BoolOp::Op op, NodeRef& l, NodeRef& r)
    {
        if (l.node->type.isBool() && r.node->type.isBool()) {
            return new NodeRef(new BoolOp(
                        op, l.node, r.node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " + 
                                 BoolOp::operatorNames[op]);
            return NULL;
        }
    }


    NodeRef* NodeRef::_binOp(BitvectorOp::Op op, NodeRef* l, NodeRef* r)
    {
        if (l->node->type.isBitvector()) {
            return new NodeRef(new BitvectorOp(op, l->node, r->node));
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
                return new NodeRef(new BitvectorOp(op, l->node, r));
            } else {
                nptr_t node_r(new BitvectorConst(r, l->node->type.bitWidth));
                return new NodeRef(new BitvectorOp(op, l->node, node_r));
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
            nptr_t node_l(new BitvectorConst(l, r->node->type.bitWidth));

            return new NodeRef(new BitvectorOp(op, node_l, r->node));
        } else {
            throw PyILAException(PyExc_TypeError,
                                 "Incorrect type for " +
                                 BitvectorOp::operatorNames[op]);
            return NULL;
        }
    }

    NodeRef* NodeRef::_triOp(BoolOp::Op boolOp, BitvectorOp::Op bvOp, MemOp::Op memOp,
                             NodeRef& cond, NodeRef& trueExp, NodeRef& falseExp)
    {
        if (trueExp.node->type != falseExp.node->type ||
            !cond.node->type.isBool())
        {
            throw PyILAException(PyExc_TypeError, "Incorrect type for ITE");
            return NULL;
        } else {
            nptr_vec_t args_;
            args_.push_back(cond.node);
            args_.push_back(trueExp.node);
            args_.push_back(falseExp.node);
            if (trueExp.node->type.isBool() && boolOp != BoolOp::INVALID) {
                return new NodeRef( 
                    new BoolOp(boolOp, args_));
            } else if (trueExp.node->type.isBitvector() && bvOp != BitvectorOp::INVALID) {
                return new NodeRef( 
                    new BitvectorOp(bvOp, args_));
            } else if (trueExp.node->type.isMem() && memOp == MemOp::ITE) {
                return new NodeRef( 
                    new MemOp(memOp, cond.node, trueExp.node, falseExp.node));
            } else {
                throw PyILAException(PyExc_TypeError, "Incorrect type for ITE");
                return NULL;
            }
        }
        return NULL;
    }

    NodeRef* NodeRef::_naryOp(BitvectorOp::Op bvOp, nptr_vec_t& args)
    {
        if (args.size() < 1) {
            throw PyILAException(PyExc_TypeError, "No function specified.");
            return NULL;
        }
        if (!args[0]->type.isFunc()) {
            throw PyILAException(PyExc_TypeError, 
                    "Incorrect type for apply function.");
            return NULL;
        } else {
            return new NodeRef(new BitvectorOp(BitvectorOp::APPLY_FUNC, args));
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
                new BitvectorOp(BitvectorOp::EXTRACT, obj->node, beg, end));
        }
    }

    NodeRef* NodeRef::_choice(const std::string& name, 
                              const nptr_vec_t& args)
    {

        NodeType t = Choice::getChoiceType(args);
        if (!t) {
            throw PyILAException(PyExc_TypeError, 
                "Type mismatch in choice arguments.");
            return NULL;
        } else {
            if (t.isBool()) {
                return new NodeRef(new BoolChoice(name, args));
            } else if (t.isBitvector()) {
                return new NodeRef(new BitvectorChoice(name, args));
            } else if (t.isMem()) {
                return new NodeRef(new MemChoice(name, args));
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
}
