#include <fstream>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <logging.hpp>
#include <horn.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    HornVar::HornVar (const unsigned& id)
      : _id (id)
    {
    }

    HornVar::~HornVar ()
    {
    }

    const unsigned& HornVar::getId () const
    {
        return _id;
    }

    const std::string& HornVar::getName () const
    {
        return _name;
    }

    const std::string& HornVar::getType () const
    {
        return _type;
    }

    const std::string& HornVar::getExec () const
    {
        return _exec;
    }

    std::string HornVar::getPred () const
    {
        boost::format predFmt ("(%1%.%2%%3%)");
        std::string argStr = "";
        for (auto it = _ins.begin(); it != _ins.end(); it++) {
            argStr += " ";
            argStr += (*it)->getName();
        }
        for (auto it = _outs.begin(); it != _outs.end(); it++) {
            argStr += " ";
            argStr += (*it)->getName();
        }
        predFmt % "rel"
                % _name
                % argStr;
        return predFmt.str();
    }

    std::string HornVar::getRel () const
    {
        boost::format relFmt ("%1%.%2% (%3%)");
        std::string argStr = "";
        for (auto it = _ins.begin(); it != _ins.end(); it++) {
            argStr += (*it)->getType();
            argStr += " ";
        }
        for (auto it = _outs.begin(); it != _outs.end(); it++) {
            argStr += (*it)->getType();
            argStr += " ";
        }
        relFmt % "rel"
               % _name
               % argStr;
        return relFmt.str();
    }

    void HornVar::setName (const std::string& s)
    {
        _name = s;
    }

    void HornVar::setType (const std::string& s)
    {
        _type = s;
    }

    void HornVar::setExec (const std::string& s)
    {
        _exec = s;
    }

    void HornVar::addInVar (hvptr_t v)
    {
        _ins.insert (v);
    }

    void HornVar::addOutVar (hvptr_t v)
    {
        _outs.insert (v);
    }

    void HornVar::mergeInVars (hvptr_t v)
    {
        for (auto it = v->_ins.begin(); it != v->_ins.end(); it++) {
            _ins.insert (*it);
        }
    }

    void HornVar::mergeOutVars (hvptr_t v)
    {
        for (auto it = v->_outs.begin(); it != v->_outs.end(); it++) {
            _outs.insert (*it);
        }
    }

    // ---------------------------------------------------------------------- //
    HornLiteral::HornLiteral (hvptr_t v, bool r, bool s)
      : _var (v)
    {
        _rel = r;
        _sign = s;
    }

    HornLiteral::~HornLiteral ()
    {
    }

    hvptr_t HornLiteral::getVar () const
    {
        return _var;
    }

    bool HornLiteral::getSign () const
    {
        return _sign;
    }

    bool HornLiteral::isRel () const
    {
        return _rel;
    }

    // ---------------------------------------------------------------------- //
    HornClause::HornClause ()
    {
    }

    HornClause::~HornClause ()
    {
    }

    void HornClause::addBody (hlptr_t l) 
    {
        _body.insert (l);
    }

    void HornClause::setHead (hlptr_t l)
    {
        _head = l;
    }

    // ---------------------------------------------------------------------- //
    HornDB::HornDB ()
    {
    }

    HornDB::~HornDB ()
    {
    }

    void HornDB::addVar (hvptr_t v)
    {
        _vars.insert (v);
    }

    void HornDB::addRule (hvptr_t v)
    {
        _rules.insert (v);
    }

    void HornDB::addClause (hcptr_t c)
    {
        _clauses.insert (c);
    }

    void HornDB::print (std::ostream& out)
    {
        // TODO
    }

    // ---------------------------------------------------------------------- //
    HornTranslator::HornTranslator (Abstraction* abs)
      : _abs (abs)
    {
        _db = new HornDB();
    }

    HornTranslator::~HornTranslator ()
    {
        if (_db) delete _db;
        _db = NULL;
    }

    void HornTranslator::transAll (const std::string& fileName)
    {
        // TODO
    }

    void HornTranslator::transOne (NodeRef* node, const std::string& fileName)
    {
        // TODO
        log1 ("Horn") << "Trans on node " << node->getName() << std::endl;
        depthFirstTraverse (node->node);
    }

    void HornTranslator::depthFirstTraverse (nptr_t n)
    {
        // TODO
    }

    void HornTranslator::operator() (nptr_t n)
    {
        // TODO
    }

    bool HornTranslator::isITE (nptr_t n)
    {
        const BoolOp* boolop = NULL;
        const BitvectorOp* bvop = NULL;
        const MemOp* memop = NULL;

        if ((boolop = dynamic_cast <const BoolOp*> (n.get()))) {
            return (boolop->op == BoolOp::Op::IF);
        } else if ((bvop = dynamic_cast <const BitvectorOp*> (n.get()))) {
            return (bvop->op == BitvectorOp::Op::IF);
        } else if ((memop = dynamic_cast <const MemOp*> (n.get()))) {
            return (memop->op == MemOp::Op::ITE);
        } else {
            return false;
        }

    }

    void HornTranslator::setBoolVarHorn (const BoolVar* n, hvptr_t hv)
    {
        // TODO
    }
}

