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
    HornNode::HornNode(const std::string& s)
      : _name (s)
    {
    }

    // ---------------------------------------------------------------------- //
    HornNode::HornNode(nptr_t n)
      : _name (n->getName())
    {
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
    void HornClause::print(std::ostream& out)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    HornCtx::HornCtx()
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
            _nodes[n] = hn;
            return hn;
        }
    }

    // ---------------------------------------------------------------------- //
    void HornCtx::addHornClause(HornClause* hc)
    {
        assert(hc);
        _clauses.insert(hc);
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
