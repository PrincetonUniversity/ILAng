#include <iostream>
#include <boost/lexical_cast.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <hornDB.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    HornNode::HornNode()
    {
    }

    // ---------------------------------------------------------------------- //
    HornNode::HornNode(nptr_t n)
      : _name (n->getName())
    {
        extractType(n.get());
    }

    // ---------------------------------------------------------------------- //
    HornNode::HornNode(Node* n)
      : _name (n->getName())
    {
        extractType(n);
    }

    // ---------------------------------------------------------------------- //
    HornNode::~HornNode()
    {
    }

    // ---------------------------------------------------------------------- //
    const std::string& HornNode::getName() const
    {
        return _name;
    }

    // ---------------------------------------------------------------------- //
    void HornNode::setName(const std::string& s)
    {
        _name = s;
    }

    // ---------------------------------------------------------------------- //
    const std::string& HornNode::getType() const
    {
        return _type;
    }

    // ---------------------------------------------------------------------- //
    void HornNode::setType(const std::string& s)
    {
        _type = s;
    }

    // ---------------------------------------------------------------------- //
    const unsigned& HornNode::getId() const
    {
        return _id;
    }

    // ---------------------------------------------------------------------- //
    void HornNode::setId(const unsigned& i)
    {
        _id = i;
    }
    // ---------------------------------------------------------------------- //
    void HornNode::extractType(Node* n)
    {
        const BoolVar* boolvar = NULL;
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemOp*  memop = NULL;

        const FuncVar* funcvar = NULL;

        const BitvectorChoice* bvchoice = NULL;
        const BoolChoice* boolchoice = NULL;
        const MemChoice* memchoice = NULL;
        const WriteSlice* writeslice = NULL;
        const ReadSlice* readslice = NULL;

        //// Bool ////
        if ((boolvar = dynamic_cast <const BoolVar*> (n))) {
            _type = "Bool";
        } else if ((boolconst = dynamic_cast <const BoolConst*> (n))) {
            _type = "Const";
        } else if ((boolop = dynamic_cast <const BoolOp*> (n))) {
            _type = "Bool";
        //// Bitvector ////
        } else if ((bvvar = dynamic_cast <const BitvectorVar*> (n))) {
            // (_ BitVec n)
            _type = "(_ BitVec " +
                    boost::lexical_cast<std::string>(n->type.dataWidth) + 
                    ")";
        } else if ((bvconst = dynamic_cast <const BitvectorConst*> (n))) {
            _type = "Const";
        } else if ((bvop = dynamic_cast <const BitvectorOp*> (n))) {
            // TODO it can be bitvector or bool?
        //// Mem ////
        } else if ((memvar = dynamic_cast <const MemVar*> (n))) {
            // TODO
        } else if ((memconst = dynamic_cast <const MemConst*> (n))) {
            // TODO
        } else if ((memop = dynamic_cast <const MemOp*> (n))) {
            // TODO
        //// Func ////
        } else if ((funcvar = dynamic_cast <const FuncVar*> (n))) {
            // TODO
        //// Chpoce ////
        } else if ((boolchoice = dynamic_cast <const BoolChoice*> (n))) {
            ILA_ASSERT(false, "BoolChoice not implemented.");
        } else if ((bvchoice = dynamic_cast <const BitvectorChoice*> (n))) {
            ILA_ASSERT(false, "BitvectorChoice not implemented.");
        } else if ((memchoice = dynamic_cast <const MemChoice*> (n))) {
            ILA_ASSERT(false, "MemChoice not implemented.");
        } else if ((writeslice = dynamic_cast <const WriteSlice*> (n))) {
            ILA_ASSERT(false, "WriteSlice not implemented.");
        } else if ((readslice = dynamic_cast <const ReadSlice*> (n))) {
            ILA_ASSERT(false, "ReadSlice not implemented.");
        } else {
            ILA_ASSERT(false, "Unknown node type.");
        }
    }

    // ---------------------------------------------------------------------- //
    HornClause::HornClause()
    {
    }

    // ---------------------------------------------------------------------- //
    HornClause::~HornClause()
    {
    }

    // ---------------------------------------------------------------------- //
    void HornClause::addBody(hnptr_t n)
    {
        _body.push_back(n);
    }

    // ---------------------------------------------------------------------- //
    void HornClause::setHead(hnptr_t n)
    {
        _head = n;
    }

    // ---------------------------------------------------------------------- //
    void HornClause::addInput(hnptr_t n)
    {
        _inputs.push_back(n);
    }

    // ---------------------------------------------------------------------- //
    void HornClause::addOutput(hnptr_t n)
    {
        _outputs.push_back(n);
    }

    // ---------------------------------------------------------------------- //
    void HornClause::setInput (hnptr_vec_t nVec)
    {
        _inputs.clear ();
        for (unsigned i = 0; i < nVec.size(); i++) {
            _inputs.push_back (nVec[i]);
        }
    }

    // ---------------------------------------------------------------------- //
    void HornClause::setOutput (hnptr_vec_t nVec)
    {
        _outputs.clear ();
        for (unsigned i = 0; i < nVec.size(); i++) {
            _outputs.push_back (nVec[i]);
        }
    }

    // ---------------------------------------------------------------------- //
    void HornClause::print (std::ostream& out)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    HornCtx::HornCtx()
      : _nodeCnt (0)
    {
    }

    // ---------------------------------------------------------------------- //
    HornCtx::~HornCtx()
    {
        clear();
    }

    // ---------------------------------------------------------------------- //
    hnptr_t HornCtx::getHornForNode(nptr_t n)
    {
        auto it = _nodes.find(n);
        if (it != _nodes.end()) {
            return it->second;
        } else {
            hnptr_t hn = new hn_t(n);
            hn->setId(_nodeCnt++);
            _nodes[n] = hn;
            return hn;
        }
    }

    // ---------------------------------------------------------------------- //
    void HornCtx::addHornClause(hcptr_t hc)
    {
        assert(hc);
        _clauses.insert(hc);
    }

    // ---------------------------------------------------------------------- //
    void HornCtx::newHornClause()
    {
        _curHc = new hc_t;
        _clauses.insert (_curHc);
    }

    // ---------------------------------------------------------------------- //
    void HornCtx::print(std::ostream& out)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornCtx::clear()
    {
        // clear all nodes.
        for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
            delete it->second;
        }
        // clear all clauses.
        for (auto it = _clauses.begin(); it != _clauses.end(); it++) {
            delete *it;
        }
    }
}
