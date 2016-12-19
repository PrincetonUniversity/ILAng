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
        _name = _type = _exec = _pred = "";
        _init = false;
        _id = 0;
    }
    
    // ---------------------------------------------------------------------- //
    HornNode::HornNode (const unsigned& id)
      : _id (id)
    {
        _name = _type = _exec = _pred = "";
        _init = false;
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
    const std::string& HornNode::getExec() const
    {
        return _exec;
    }

    // ---------------------------------------------------------------------- //
    void HornNode::setExec(const std::string& s)
    {
        _exec = s;
    }

    // ---------------------------------------------------------------------- //
    const std::string& HornNode::getPred() const
    {
        return _pred;
    }

    // ---------------------------------------------------------------------- //
    void HornNode::setPred(const std::string& s)
    {
        _pred = s;
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
    bool HornNode::isInit() const
    {
        return _init;
    }

    // ---------------------------------------------------------------------- //
    void HornNode::setInit()
    {
        _init = true;
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
    void HornClause::addBody(hnptr_t n, bool l)
    {
        _body.insert (std::make_pair (n,l));
    }

    // ---------------------------------------------------------------------- //
    void HornClause::setHead(hnptr_t n, bool l)
    {
        _head = std::make_pair (n, l);
    }

    // ---------------------------------------------------------------------- //
    void HornClause::addInput(hnptr_t n, bool l)
    {
        _inputs.insert (std::make_pair (n, l));
    }

    // ---------------------------------------------------------------------- //
    void HornClause::addOutput(hnptr_t n, bool l)
    {
        _outputs.insert (std::make_pair (n, l));
    }

    // ---------------------------------------------------------------------- //
    void HornClause::setInput (hnptr_set_t nVec)
    {
        _inputs.clear ();
        for (auto it = nVec.begin(); it != nVec.end(); it++) {
            _inputs.insert (*it);
        }
    }

    // ---------------------------------------------------------------------- //
    void HornClause::setOutput (hnptr_set_t nVec)
    {
        _outputs.clear ();
        for (auto it = nVec.begin(); it != nVec.end(); it++) {
            _outputs.insert (*it);
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
    hnptr_t HornCtx::getHornNode (nptr_t n)
    {
        auto it = _nodes.find (n);
        if (it != _nodes.end()) {
            return it->second;
        } else {
            hnptr_t hn = new hn_t;
            hn->setId (_nodeCnt++);
            _nodes[n] = hn;
            return hn;
        }
    }

    // ---------------------------------------------------------------------- //
    hcptr_t HornCtx::addHornClause ()
    {
        hcptr_t hc = new hc_t;
        _clauses.insert (hc);
        return hc;
    }

    // ---------------------------------------------------------------------- //
    void HornCtx::print (std::ostream& out)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    void HornCtx::clear ()
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
