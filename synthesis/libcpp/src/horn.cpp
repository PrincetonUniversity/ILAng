#include <fstream>
#include <iomanip>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <logging.hpp>
#include <common.hpp>
#include <horn.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    HornVar::HornVar (const unsigned& id)
      : _id (id)
    {
        _const = false;
        _lvl   = 0;
        _nd    = "";
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

    const std::set <std::string>& HornVar::getExec () const
    {
        return _exec;
    }

    std::string HornVar::getPred () const
    {
        // uninterpreted functions.
        if (isNd()) {
            return _nd;
        }

        boost::format predFmt ("(%1%%2%%3%)");
        std::string argStr = "";
        for (auto it = _ins.begin(); it != _ins.end(); it++) {
            argStr += " ";
            argStr += it->second->getName();
        }
        for (auto it = _outs.begin(); it != _outs.end(); it++) {
            argStr += " ";
            argStr += (*it)->getName();
        }

        if (_lvl == 0) {
            predFmt % "rel."
                    % _name
                    % argStr;
        } else {
            predFmt % ""
                    % _name
                    % argStr;
        }
        return predFmt.str();
    }

    std::string HornVar::getRel () const
    {
        // uninterpreted functions.
        if (isNd()) {
            std::string funRel = (_name + " " + _type);
            return funRel;
        }

        boost::format relFmt ("%1%%2% (%3%)");
        std::string argStr = "";
        for (auto it = _ins.begin(); it != _ins.end(); it++) {
            argStr += it->second->getType();
            argStr += " ";
        }
        for (auto it = _outs.begin(); it != _outs.end(); ) {
            argStr += (*it)->getType();
            if (++it != _outs.end()) {
                argStr += " ";
            }
        }

        if (_lvl == 0) {
            relFmt % "rel."
                   % _name
                   % argStr;
        } else {
            relFmt % ""
                   % _name
                   % argStr;
        }
        return relFmt.str();
    }

    bool HornVar::isConst () const
    {
        return _const;
    }

    void HornVar::setName (std::string s)
    {
        _name = s;
    }

    void HornVar::setType (std::string s)
    {
        _type = s;
    }

    void HornVar::setExec (std::string s)
    {
        _exec.insert (s);
    }

    void HornVar::eraseExec ()
    {
        _exec.clear ();
    }

    void HornVar::addInVar (hvptr_t v)
    {
        auto it = _ins.find (v->getName());
        if (it == _ins.end())
            _ins[v->getName()] = v;
    }

    void HornVar::addOutVar (hvptr_t v)
    {
        _outs.insert (v);
    }

    void HornVar::mergeInVars (hvptr_t v)
    {
        for (auto it = v->_ins.begin(); it != v->_ins.end(); it++) {
            _ins[it->first] = it->second;
        }
    }

    void HornVar::mergeOutVars (hvptr_t v)
    {
        for (auto it = v->_outs.begin(); it != v->_outs.end(); it++) {
            _outs.insert (*it);
        }
    }

    void HornVar::setConst ()
    {
        _const = true;
    }

    const int& HornVar::getLevel () const
    {
        return _lvl;
    }

    void HornVar::setLevel (const int& lvl)
    {
        _lvl = lvl;
    }

    size_t HornVar::getInNum () const
    {
        return _ins.size();
    }

    size_t HornVar::getOutNum () const
    {
        return _outs.size();
    }

    const std::map <std::string, hvptr_t>& HornVar::getInSet () const
    {
        return _ins;
    }

    const std::set <hvptr_t>& HornVar::getOutSet () const
    {
        return _outs;
    }

    hvptr_t HornVar::getOutVar () const
    {
        for (auto it : _outs) {
            return it;
        }
        return NULL;
    }

    void HornVar::setNd (const std::string& nd)
    {
        _nd = nd;
    }

    const std::string& HornVar::getNd () const
    {
        return _nd;
    }

    bool HornVar::isNd () const
    {
        return _nd != "";
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

    std::string HornLiteral::getPred () const
    {
        if (_sign) {
            return _var->getPred();
        } else {
            return ("(not " + _var->getPred() + ")");
        }
    }

    std::set <std::string> HornLiteral::getExec () const
    {
        std::set <std::string> res;
        for (auto e : _var->getExec()) {
            if (_sign) {
                res.insert (e);
            } else {
                res.insert ("(not " + e + ")");
            }
        }
        return res;
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
        _head = NULL;
    }

    HornClause::~HornClause ()
    {
        for (auto b : _body) {
            delete b;
        }
        delete _head;
    }

    void HornClause::addBody (hlptr_t l) 
    {
        _body.insert (l);
        // propogate input args to _head
        if (_head != NULL)
            _head->getVar()->mergeInVars (l->getVar());
    }

    void HornClause::setHead (hlptr_t l)
    {
        //ILA_ASSERT (_body.empty(), "body not empty, may fail.");
        _head = l;
    }

    void HornClause::print (std::ostream& out)
    {
        // uninterpreted functions.
        // (rule (fun a b c d))
        if (_head->getVar()->isNd()) {
            out << "(rule " << _head->getVar()->getNd() << ")\n";
            return;
        }

        // (rule (=> (and (body-1)
        //                (body-2)
        //                (body-3))
        //           head))
        std::set <std::string> allTerms;
        for (auto b : _body) {
            if (b->isRel()) {
                allTerms.insert (b->getPred());
            } else {
                auto set = b->getExec();
                for (auto it = set.begin(); it != set.end(); it++) {
                    if (*it != "true")
                        allTerms.insert (*it);
                }
            }
        }

        // ignore (A -> A)
        if ((allTerms.size() == 1) && 
            (*allTerms.begin() == _head->getVar()->getPred()))
            return;

        std::string endPar = "))\n";
        if (allTerms.empty()) {
            out << "(rule ";
            endPar = ")\n";
        } else if (allTerms.size() == 1) {
            out << "(rule (=> ";
            out << *allTerms.begin() << "\n";
            out << std::setw(10) << "";
        } else {
            out << "(rule (=> (and ";
            for (auto b = allTerms.begin(); b != allTerms.end(); ) {
                if (b != allTerms.begin())
                    out << std::setw(15) << "";
                out << (*b);
                if (++b != allTerms.end()) 
                    out << "\n";
            }
            out << ")\n";
            out << std::setw(10) << "";
        }

        if (_head->isRel()) {
            out << _head->getVar()->getPred() << endPar;
        } else {
            auto set = _head->getVar()->getExec();
            ILA_ASSERT (set.size() == 1, "Head should have only 1 term.");
            out << *set.begin() << endPar;
        }

    }

    // ---------------------------------------------------------------------- //
    HornDB::HornDB ()
    {
    }

    HornDB::~HornDB ()
    {
        for (auto v : _vars)
            delete v.second;
        for (auto d : _dupls)
            delete d;
        for (auto c : _clauses)
            delete c;
    }

    void HornDB::addVar (hvptr_t v)
    {
        auto it = _vars.find(v->getName());
        if (it == _vars.end())
            _vars[v->getName()] = v;
        else
            _dupls.insert (v);
    }

    void HornDB::addRel (hvptr_t v)
    {
        _rels.insert (v);
    }

    void HornDB::addClause (hcptr_t c)
    {
        _clauses.insert (c);
    }

    void HornDB::addWrapClause (hcptr_t c)
    {
        _wrapClauses.insert (c);
    }

    void HornDB::removeVar (const std::string& n)
    {
        _vars.erase (n);
    }

    void HornDB::removeRel (hvptr_t v)
    {
        _rels.erase (v);
    }

    void HornDB::print (std::ostream& out)
    {
        declareVar (out);
        declareRel (out);
        declareClause (out);
        declareWrapClause (out);
    }

    void HornDB::declareVar (std::ostream& out)
    {
        // (declare-var NAME TYPE)
        out << ";; variables\n";
        boost::format varFmt ("(declare-var %1% %2%)\n");
        for (auto i : _vars) {
            hvptr_t v = i.second;
            if (v->isConst()) continue;
            if (v->isNd()) continue;
            if (v->getType() == "") continue;
            if (v->getLevel() > 0) continue;
            varFmt % v->getName() % v->getType();
            out << varFmt.str();
        }
    }

    void HornDB::declareRel (std::ostream& out)
    {
        // (declare-rel NAME (ARG_i))
        out << ";; relations\n";
        boost::format relFmt ("(declare-rel %1%)\n");
        for (auto r : _rels) {
            relFmt % r->getRel();
            out << relFmt.str();
        }
    }

    void HornDB::declareClause (std::ostream& out)
    {
        out << ";; clauses\n";
        for (auto c : _clauses) {
            c->print (out);
        }
    }

    void HornDB::declareWrapClause (std::ostream& out)
    {
        out << ";; wrapping clauses\n";
        for (auto w : _wrapClauses) {
            w->print (out);
        }
    }

    // ---------------------------------------------------------------------- //
    HornTranslator::HornTranslator (Abstraction* abs, const std::string& name)
      : //_abs (abs),
        _name (name)
    {
        _db = new HornDB();
        _varCnt = 0;
        _curHc = NULL;
        _iteAsNode = true;
        _bvAsInt = false;
        _bvMaxSize = 32;
    }

    HornTranslator::~HornTranslator ()
    {
        if (_db) delete _db;
        _db = NULL;
    }

    void HornTranslator::hornifyAll (const std::string& fileName)
    {
        // TODO
    }

    hvptr_t HornTranslator::hornifyNode (NodeRef* node, 
                                      const std::string& ruleName)
    {
        nptr_t n = node->node;

        hvptr_t varNxt = getVar (n);
        hvptr_t topV = getVar (ruleName);
        hcptr_t topC = addClause (topV);
        topV->addOutVar (varNxt);
        topV->setType (varNxt->getType());

        _curHc = topC;
        depthFirstTraverse (n);

        topV->setLevel (1);
        return topV;
    }

    void HornTranslator::exportHorn (const std::string& fileName)
    {
        std::ofstream out (fileName.c_str());
        ILA_ASSERT (out.is_open(), "File " + fileName + " not open.");
        _db->print (out);
        out.close();
    }

    void HornTranslator::setIteAsNode (bool iteAsNode)
    {
        _iteAsNode = iteAsNode;
    }

    void HornTranslator::setBvAsInt (bool bvAsInt)
    {
        _bvAsInt = bvAsInt;
    }

    void HornTranslator::depthFirstTraverse (nptr_t n)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not defined.");

        if (!isITE (n) || _iteAsNode) {
            // normal non-ITE nodes
            unsigned argNum = n->nArgs();
            for (unsigned i = 0; i != argNum; i++) {
                const nptr_t arg_i = n->arg(i);
                depthFirstTraverse (arg_i);
            }
            (*this) (n);
        } else {
            // ITE nodes
            ILA_ASSERT (n->nArgs() == 3, "ITE should have 3 args.");
            
            hvptr_t hvIte  = getVar (n);
            hvptr_t hvCond = getVar (n->arg(0));
            hvptr_t hvThen = getVar (n->arg(1));
            hvptr_t hvElse = getVar (n->arg(2));

            hcptr_t hcPrev  = _curHc;
            hcptr_t hcCond  = addClause (hvCond);
            hcptr_t hcThen  = addClause (hvThen);
            hcptr_t hcElse  = addClause (hvElse);
            hcptr_t hcTrue  = addClause (hvIte);
            hcptr_t hcFalse = addClause (hvIte);

            // condition
            _curHc = hcCond;
            depthFirstTraverse (n->arg(0));
            // then
            _curHc = hcThen;
            depthFirstTraverse (n->arg(1));
            // else
            _curHc = hcElse;
            depthFirstTraverse (n->arg(2));

            // condition hold true. 
            // (cond a b c) (then d e) c (= e f) -> (ite a b d f)
            hvptr_t hvEqT = getEqVar (hvIte, hvThen);
            hvptr_t hvCT = getConVar (hvCond);
            hcTrue->addBody (new HornLiteral (hvCond, true, true));
            hcTrue->addBody (new HornLiteral (hvThen, true, true));
            hcTrue->addBody (new HornLiteral (hvCT, false, true));
            hcTrue->addBody (new HornLiteral (hvEqT, false, true));

            // condition not hold. 
            // (cond a b c) (else d e) (not c) (= e f) -> (ite a b d f)
            hvptr_t hvEqF = getEqVar (hvIte, hvElse);
            hvptr_t hvCF = getConVar (hvCond);
            hcFalse->addBody (new HornLiteral (hvCond, true, true));
            hcFalse->addBody (new HornLiteral (hvElse, true, true));
            hcFalse->addBody (new HornLiteral (hvCF, false, false));
            hcFalse->addBody (new HornLiteral (hvEqF, false, true));

            // add relation and reset to previous clause
            _curHc = hcPrev;
            (*this) (n);
        }
    }

    void HornTranslator::operator() (nptr_t node)
    {
        Node* n = node.get();
        hvptr_t v = getVar (node);

        const BoolOp* boolop = NULL;
        const BoolVar* boolvar = NULL;
        const BoolConst* boolconst = NULL;

        const BitvectorOp* bvop = NULL;
        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;

        const MemOp* memop = NULL;
        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;

        const FuncVar* funcvar = NULL;

        const BoolChoice* boolchoice = NULL;
        const BitvectorChoice* bvchoice = NULL;
        const MemChoice* memchoice = NULL;
        const ReadSlice* readslice = NULL;
        const WriteSlice* writeslice = NULL;

        //// Bool ////
        if ((boolop = dynamic_cast <BoolOp*> (n))) {
            addBoolOp (boolop, v);
        } else if ((boolvar = dynamic_cast <BoolVar*> (n))) {
            addBoolVar (boolvar, v);
        } else if ((boolconst = dynamic_cast <BoolConst*> (n))) {
            addBoolConst (boolconst, v);
        //// Bitvector ////
        } else if ((bvop = dynamic_cast <BitvectorOp*> (n))) {
            addBvOp (bvop, v);
        } else if ((bvvar = dynamic_cast <BitvectorVar*> (n))) {
            addBvVar (bvvar, v);
        } else if ((bvconst = dynamic_cast <BitvectorConst*> (n))) {
            addBvConst (bvconst, v);
        //// Memory ////
        } else if ((memop = dynamic_cast <MemOp*> (n))) {
            addMemOp (memop, v);
        } else if ((memvar = dynamic_cast <MemVar*> (n))) {
            addMemVar (memvar, v);
        } else if ((memconst = dynamic_cast <MemConst*> (n))) {
            addMemConst (memconst, v);
        //// Func ////
        } else if ((funcvar = dynamic_cast <FuncVar*> (n))) {
            addFuncVar (funcvar, v);
        //// Choice ////
        } else if ((boolchoice = dynamic_cast <BoolChoice*> (n))) {
            ILA_ASSERT (false, "BoolChoice not implemented.");
        } else if ((bvchoice = dynamic_cast <BitvectorChoice*> (n))) {
            ILA_ASSERT (false, "BitvectorChoice not implemented.");
        } else if ((memchoice = dynamic_cast <MemChoice*> (n))) {
            ILA_ASSERT (false, "MemChoice not imeplemented.");
        } else if ((readslice = dynamic_cast <ReadSlice*> (n))) {
            ILA_ASSERT (false, "ReadSlice not imeplemented.");
        } else if ((writeslice = dynamic_cast <WriteSlice*> (n))) {
            ILA_ASSERT (false, "WriteSlice not imeplemented.");
        } else {
            ILA_ASSERT (false, "Unknown node type.");
        }
    }

    hvptr_t HornTranslator::getVar (nptr_t n)
    {
        auto it = _nVarMap.find (n);
        if (it != _nVarMap.end()) {
            return it->second;
        } else {
            hvptr_t v = new HornVar (_varCnt++);
            initVar (v, n);
            _nVarMap[n] = v;
            _db->addVar (v);
            return v;
        }
    }

    hvptr_t HornTranslator::getVar (const std::string& s)
    {
        auto it = _sVarMap.find (s);
        if (it != _sVarMap.end()) {
            return it->second;
        } else {
            hvptr_t v = new HornVar (_varCnt++);
            initVar (v, s);
            _sVarMap[s] = v;
            _db->addVar (v);
            return v;
        }
    }

    hcptr_t HornTranslator::addClause (hvptr_t v)
    {
        hcptr_t c = new HornClause ();
        if (v != NULL) {
            c->setHead (new HornLiteral (v, true, true));
            _db->addRel (v);
            _db->addClause (c);
        } else {
            c->setHead (NULL);
            _db->addWrapClause (c);
        }
        return c;
    }

    void HornTranslator::initVar (hvptr_t v, nptr_t node)
    {
        if (_bvAsInt) {
            initVarInt (v, node);
        } else {
            initVarBv (v, node);
        }
    }

    void HornTranslator::initVarBv (hvptr_t v, nptr_t node)
    {
        Node* n = node.get();

        const BoolOp* boolop = NULL;
        const BoolVar* boolvar = NULL;
        const BoolConst* boolconst = NULL;

        const BitvectorOp* bvop = NULL;
        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;

        const MemOp* memop = NULL;
        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;

        const FuncVar* funcvar = NULL;

        const BoolChoice* boolchoice = NULL;
        const BitvectorChoice* bvchoice = NULL;
        const MemChoice* memchoice = NULL;
        const ReadSlice* readslice = NULL;
        const WriteSlice* writeslice = NULL;

        //// Bool ////
        if ((boolop = dynamic_cast <BoolOp*> (n))) {
            initBoolOp (boolop, v);
        } else if ((boolvar = dynamic_cast <BoolVar*> (n))) {
            initBoolVar (boolvar, v);
        } else if ((boolconst = dynamic_cast <BoolConst*> (n))) {
            initBoolConst (boolconst, v);
        //// Bitvector ////
        } else if ((bvop = dynamic_cast <BitvectorOp*> (n))) {
            initBvOp (bvop, v);
        } else if ((bvvar = dynamic_cast <BitvectorVar*> (n))) {
            initBvVar (bvvar, v);
        } else if ((bvconst = dynamic_cast <BitvectorConst*> (n))) {
            initBvConst (bvconst, v);
        //// Memory ////
        } else if ((memop = dynamic_cast <MemOp*> (n))) {
            initMemOp (memop, v);
        } else if ((memvar = dynamic_cast <MemVar*> (n))) {
            initMemVar (memvar, v);
        } else if ((memconst = dynamic_cast <MemConst*> (n))) {
            initMemConst (memconst, v);
        //// Func ////
        } else if ((funcvar = dynamic_cast <FuncVar*> (n))) {
            initFuncVar (funcvar, v);
        //// Choice ////
        } else if ((boolchoice = dynamic_cast <BoolChoice*> (n))) {
            ILA_ASSERT (false, "BoolChoice not implemented.");
        } else if ((bvchoice = dynamic_cast <BitvectorChoice*> (n))) {
            ILA_ASSERT (false, "BitvectorChoice not implemented.");
        } else if ((memchoice = dynamic_cast <MemChoice*> (n))) {
            ILA_ASSERT (false, "MemChoice not imeplemented.");
        } else if ((readslice = dynamic_cast <ReadSlice*> (n))) {
            ILA_ASSERT (false, "ReadSlice not imeplemented.");
        } else if ((writeslice = dynamic_cast <WriteSlice*> (n))) {
            ILA_ASSERT (false, "WriteSlice not imeplemented.");
        } else {
            ILA_ASSERT (false, "Unknown node type.");
        }
    }

    void HornTranslator::initVar (hvptr_t v, const std::string& s)
    {
        v->setName (s);
    }

    hvptr_t HornTranslator::getEqVar (hvptr_t a, hvptr_t b)
    {
        boost::format equFmt ("(= %1% %2%)");
        hvptr_t res = getVar ("eq" + a->getName() + b->getName());
        equFmt % a->getName() % b->getName();
        res->setExec (equFmt.str());
        return res;
    }

    hvptr_t HornTranslator::getConVar (hvptr_t c)
    {
        hvptr_t res = getVar ("cond_" + c->getName());
        res->setExec (c->getName());
        return res;
    }

    bool HornTranslator::isITE (nptr_t n) const
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

    void HornTranslator::initBoolOp (const BoolOp* n, hvptr_t v)
    {
        // name
        v->setName (_name + "_b" + boost::lexical_cast <std::string> (v->getId()));
        // type
        v->setType ("Bool");
        // in
        for (unsigned i = 0; i != n->nArgs(); i++) {
            hvptr_t arg_i = getVar (n->arg(i));
            v->mergeInVars (arg_i);
        }
        // out
        v->addOutVar (v);

        // exec
        static std::string boolOpNames[] = {
            "invalid",
            "not",                  // not
            "and", "or", "xor",     // and, or, xor
            "xor", "and", "or",     // xnor, nand, nor
            "=>",                   // imply,
            "bvslt", "bvsgt", "bvsle", "bvsge",
            "bvult", "bvugt", "bvule", "bvuge",
            "=", "distinct",        // equal, distinct
            "ite"                   // ite
        };

        //// Unary ////
        if (n->op == BoolOp::Op::NOT) {
            // z = !x --> (= z (not x))
            boost::format boolOpNotFmt ("(= %1% (not %2%))");
            hvptr_t arg0 = getVar (n->arg(0));
            boolOpNotFmt % v->getName() % arg0->getName();
            v->setExec (boolOpNotFmt.str());
        //// Binary ////
        } else if (n->op >= BoolOp::Op::AND &&
                   n->op <= BoolOp::Op::DISTINCT) {
            hvptr_t arg0 = getVar (n->arg(0));
            hvptr_t arg1 = getVar (n->arg(1));

            boost::format priFmt ("(= %1% (%2% %3% %4%))");
            boost::format negFmt ("(= %1% (not (%2% %3% %4%)))");

            if ((n->op >= BoolOp::Op::AND   &&
                 n->op <= BoolOp::Op::XOR)  ||
                (n->op >= BoolOp::Op::IMPLY &&
                 n->op <= BoolOp::Op::DISTINCT)) {
                // use primitive format (= z (op x y))
                priFmt % v->getName()    
                       % boolOpNames[n->op]
                       % arg0->getName() 
                       % arg1->getName();
                v->setExec (priFmt.str());
            } else if (n->op >= BoolOp::Op::XNOR && 
                       n->op <= BoolOp::Op::NOR) {
                // use negated format (= z (not (op x y)))
                negFmt % v->getName()
                       % boolOpNames[n->op]
                       % arg0->getName()
                       % arg1->getName();
                v->setExec (negFmt.str());
            } else {
                ILA_ASSERT (false, "Unknonw Binary BoolOp.");
            }
        //// Ternary ////
        } else if (n->op == BoolOp::Op::IF) {
            // ITE (c, t, e, z) --> (rel.z c t e z)
            // ITE (c, t, e, z) --> (= z (ite c t e))

            if (_iteAsNode) {
                hvptr_t vCond = getVar (n->arg(0));
                hvptr_t vThen = getVar (n->arg(1));
                hvptr_t vElse = getVar (n->arg(2));
                boost::format iteFmt ("(= %1% (%2% %3% %4% %5%))");
                iteFmt % v->getName()
                       % boolOpNames[n->op]
                       % vCond->getName()
                       % vThen->getName()
                       % vElse->getName();
                v->setExec (iteFmt.str());
            } else {
                v->setExec ("true"); 
            }
        } else {
            ILA_ASSERT (false, "Unknown BoolOp.");
        }

    }

    void HornTranslator::initBoolVar (const BoolVar* n, hvptr_t v)
    {
        // name should be exactly the same as the design.
        v->setName (n->getName());
        // type
        v->setType ("Bool");
        // exec
        v->setExec ("true");
        // ins
        v->addInVar (v);
        // outs
        v->addOutVar (v);
    }

    void HornTranslator::initBoolConst (const BoolConst* n, hvptr_t v)
    {
        // name is the value.
        std::string name = (n->val()) ? "true" : "false";
        v->setName (name);
        // type doesn't matter.
        v->setType ("Bool");
        // exec 
        v->setExec ("true");
        // ins
        // outs
        v->setConst ();
    }

    void HornTranslator::initBvOp (const BitvectorOp* n, hvptr_t v)
    {
        // name 
        v->setName (_name + "_bv" + boost::lexical_cast <std::string> (v->getId()));
        // type
        v->setType ("(_ BitVec " + 
                    boost::lexical_cast <std::string> (n->type.bitWidth) + 
                    ")");
        // in
        for (unsigned i = 0; i != n->nArgs(); i++) {
            hvptr_t arg_i = getVar (n->arg(i));
            v->mergeInVars (arg_i);
        }
        // out
        v->addOutVar (v);

        // exec
        // TODO Not supported operators: 
        // LROTATE, RROTATE, S_EXT 
        std::string bvOpNames[] = {
            "invalid",                      // not used 
            // unary
            "bvneg", "bvnot",
            "rotate-left", "rotate-right",  // not used
            "concat",
            "sign-extend",                  // not used
            "extract",
            // binary
            "bvadd", "bvsub", 
            "bvand", "bvor", "bvxor", "bvxnor", "bvnand", "bvnor",
            "bvsdiv", "bvudiv", "bvsrem", "bvurem", "bvsmod", 
            "bvshl", "bvlshr", "bvashr", "bvmul", "concat", 
            "get-bit",                      // not used
            "select", "read-block",
            // ternary
            "ite", "apply_fun", 
        };

        boost::format bvUnaryFmt ("(= %1% (%2% %3%))");
        boost::format bvBinaryFmt ("(= %1% (%2% %3% %4%))");
        //// Unary ////
        if (n->op >= BitvectorOp::Op::NEGATE && 
            n->op <= BitvectorOp::Op::EXTRACT) {

            hvptr_t arg0 = getVar (n->arg(0));

            if (n->op == BitvectorOp::Op::NEGATE) {
                // z = -x --> (=z (bvneg x))
                bvUnaryFmt % v->getName() 
                           % "bvneg"
                           % arg0->getName();
                v->setExec (bvUnaryFmt.str());
            } else if (n->op == BitvectorOp::Op::COMPLEMENT) {
                // z = ~x --> (=z (bvnot x))
                bvUnaryFmt % v->getName()
                           % "bvnot"
                           % arg0->getName();
                v->setExec (bvUnaryFmt.str());
            } else if (n->op == BitvectorOp::Op::LROTATE || 
                       n->op == BitvectorOp::Op::RROTATE) {
                // not supported yet
                ILA_ASSERT (false, "rotate op not supported yet.");
            } else if (n->op == BitvectorOp::Op::Z_EXT) {
                // z = zext(x) --> (=z (concat #b000 x))
                unsigned w = n->type.bitWidth;
                unsigned d = n->arg(0)->type.bitWidth;
                std::string zero = "#b";
                for (unsigned i = 0; i < w-d; i++) {
                    zero += "0";
                }
                bvBinaryFmt % v->getName()
                            % "concat"
                            % zero
                            % arg0->getName();
                v->setExec (bvBinaryFmt.str());
            } else if (n->op == BitvectorOp::Op::S_EXT) {
                // not supported yet
                ILA_ASSERT (false, "signed extend not supported yet.");
            } else if (n->op == BitvectorOp::Op::EXTRACT) {
                // z = x[m:l] --> (= z ((_ extract m l) x))
                boost::format extractOp ("(= %1% ((_ extract %2% %3%) %4%))");
                extractOp % v->getName()
                          % n->param(0)
                          % n->param(1)
                          % arg0->getName();
                v->setExec (extractOp.str());
            } else {
                ILA_ASSERT (false, "unknown unary BvOp.");
            }
        //// Binary ////
        } else if (n->op >= BitvectorOp::Op::ADD && 
                   n->op <= BitvectorOp::Op::READMEM) {

            hvptr_t arg0 = getVar (n->arg(0));
            hvptr_t arg1 = getVar (n->arg(1));

            if ((n->op >= BitvectorOp::Op::ADD &&
                n->op <= BitvectorOp::Op::CONCAT) || 
                n->op == BitvectorOp::Op::READMEM) {
                // z = x op y --> (= z (op x y))
                bvBinaryFmt % v->getName()
                            % bvOpNames[n->op]
                            % arg0->getName()
                            % arg1->getName();
                v->setExec (bvBinaryFmt.str());
            } else if (n->op == BitvectorOp::Op::GET_BIT) {
                // z = x[y] --> (= z ((_ extract 0 0) (bvlshr x y)))
                boost::format bvGetbitFmt (
                        "(= %1% ((_ extract 0 0) (bvlshr %2% %3%)))");
                bvGetbitFmt % v->getName()
                            % arg0->getName()
                            % arg1->getName();
                v->setExec (bvGetbitFmt.str());
            } else {
                ILA_ASSERT (false, "unknown binary BvOp.");
            }
        } else if (n->op == BitvectorOp::Op::READMEMBLOCK) {
            ILA_ASSERT (n->nArgs() == 2, "Two arguments expected.");
            hvptr_t mem  = getVar (n->arg(0));
            hvptr_t addr = getVar (n->arg(1));
            ILA_ASSERT (n->nParams() == 2, "Two parameters expected.");
            int blkSize = n->arg(0)->type.dataWidth;
            int blkNum  = n->param(0);
            bool isLittle = (n->param(1) == LITTLE_E);
            // big:
            // (= z (((concat (select A x) 
            //        (concat (select A (+ x w))
            //                (select A (+ x 2w)))))))
            // little:
            // (= z (((concat (select A (+ x 2w) 
            //        (concat (select A (+ x w))
            //                (select A x)))))))
            std::string exec = "";
            boost::format readBlkFmt ("(= %1% %2%)");

            if (isLittle) {
                exec = genReadMemBlkExecLit (mem->getName(),
                                             addr->getName(),
                                             blkSize,
                                             blkNum);
            } else {
                exec = genReadMemBlkExecBig (mem->getName(),
                                             addr->getName(),
                                             blkSize,
                                             blkNum,
                                             blkNum);
            }

            readBlkFmt % v->getName() % exec;
            v->setExec (readBlkFmt.str());
            
        //// Ternary ////
        } else if (n->op == BitvectorOp::Op::IF) {
            // z = ite (c, t, e) --> (=z (ite c, t, e))
            // z = ite (c, t, e) --> (rel.z c, t, e, z)
            
            if (_iteAsNode) {
                hvptr_t vCond = getVar (n->arg(0));
                hvptr_t vThen = getVar (n->arg(1));
                hvptr_t vElse = getVar (n->arg(2));
                boost::format iteFmt ("(= %1% (%2% %3% %4% %5%))");
                iteFmt % v->getName()
                       % bvOpNames[n->op]
                       % vCond->getName()
                       % vThen->getName()
                       % vElse->getName();
                v->setExec (iteFmt.str());
            } else {
                v->setExec ("true"); // FIXME
            }
        } else if (n->op == BitvectorOp::Op::APPLY_FUNC) {
            // z = foo (x, y) --> (foo x y z)
            std::string exec = "(";
            for (unsigned i = 0; i != n->nArgs(); i++) {
                exec += (getVar (n->arg(i))->getName() + " ");
            }
            exec += (v->getName() + ")");
            v->setExec (exec);
        } else {
            ILA_ASSERT (false, "Unknown BitvectorOp.");
        }
    }

    void HornTranslator::initBvVar (const BitvectorVar* n, hvptr_t v)
    {
        // name should be exactly the same as the design.
        v->setName (n->getName());
        // type
        v->setType ("(_ BitVec " + 
                    boost::lexical_cast <std::string> (n->type.bitWidth) + 
                    ")");
        // exec
        v->setExec ("true");
        // ins
        v->addInVar (v);
        // outs
        v->addOutVar (v);

    }

    void HornTranslator::initBvConst (const BitvectorConst* n, hvptr_t v)
    {
        // name is the value.
        v->setName (bvToString (n->val(), n->type.bitWidth));
        // type
        v->setType ("(_ BitVec " + 
                    boost::lexical_cast <std::string> (n->type.bitWidth) +
                    ")");
        // exec
        v->setExec ("true");
        // ins
        // outs
        v->setConst ();
    }
      
    void HornTranslator::initMemOp (const MemOp* n, hvptr_t v)
    {
        // name
        v->setName (_name + "_mem" + boost::lexical_cast <std::string> (v->getId()));
        // type
        boost::format memVarTypeFmt ("(Array (_ BitVec %1%) (_ BitVec %2%))");
        memVarTypeFmt % n->type.addrWidth
                      % n->type.dataWidth;
        //v->setType (memVarTypeFmt.str());
        v->setType ("(Array Int Int)");
        // in
        for (unsigned i = 0; i != n->nArgs(); i++) {
            hvptr_t arg_i = getVar (n->arg(i));
            v->mergeInVars (arg_i);
        }
        // out
        v->addOutVar (v);
        // exec
        ILA_ASSERT (n->nArgs() == 3, "MemOp should have 3 args.");
        hvptr_t arg0 = getVar (n->arg(0));
        hvptr_t arg1 = getVar (n->arg(1));
        hvptr_t arg2 = getVar (n->arg(2));

        if (n->op == MemOp::Op::STORE) {
            // z = store (A, addr, data) --> (= z (store A addr data))
            boost::format memStoreFmt ("(= %1% (store %2% %3% %4%))");
            memStoreFmt % v->getName()
                        % arg0->getName()
                        % arg1->getName()
                        % arg2->getName();
            v->setExec (memStoreFmt.str());
        } else if (n->op == MemOp::Op::ITE) {
            // z = ite (A, B, C) --> (= z (ite cond then else))
            // z = ite (A, B, C) --> (rel.z A B C Z)

            if (_iteAsNode) {
                hvptr_t vCond = getVar (n->arg(0));
                hvptr_t vThen = getVar (n->arg(1));
                hvptr_t vElse = getVar (n->arg(2));
                boost::format iteFmt ("(= %1% (ite %2% %3% %4%))");
                iteFmt % v->getName()
                       % vCond->getName()
                       % vThen->getName()
                       % vElse->getName();
                v->setExec (iteFmt.str());
            } else {
                v->setExec ("true"); // FIXME
            }
        } else if (n->op == MemOp::Op::STOREBLOCK) {
            bool isLittle = (n->endian == LITTLE_E);
            int addrSize  = n->arg(0)->type.addrWidth;
            int chunkSize = n->arg(0)->type.dataWidth;
            int chunkNum  = n->arg(2)->type.bitWidth / chunkSize;

            for (int i = 1; i < chunkNum; i++) {
                copyVar (v, i);
            }

            boost::format memBlkBvaddFmt (
              "(= %1% (store %2% (+ (bv2int %3%) %4%) (bv2int ((_ extract %5% %6%) %7%))))");
              //"(= %1% (store %2% (bvadd %3% %4%) ((_ extract %5% %6%) %7%)))");
            boost::format memBlkEmptyFmt (
              "(= %1% (store %2% (bv2int %3%) (bv2int ((_ extract %4% %5%) %6%))))");
              //"(= %1% (store %2% %3% ((_ extract %4% %5%) %6%)))");

            if (isLittle) {
                // (= z_2 (store A          addr     ((_ extract 7 0) val)))
                // (= z_1 (store z_2 (bvadd addr #1) ((_ extract 15 8) val)))
                // (= z   (store z_1 (bvadd addr #2) ((_ extract 23 16) val)))
                memBlkEmptyFmt % addSuffix (v->getName(), chunkNum-1)
                               % arg0->getName()
                               % arg1->getName()
                               % (chunkSize - 1)
                               % 0
                               % arg2->getName();
                v->setExec (memBlkEmptyFmt.str());

                for (int i = 1; i < chunkNum-1; i++) {
                    memBlkBvaddFmt % addSuffix (v->getName(), i)
                                   % addSuffix (v->getName(), i+1)
                                   % arg1->getName()
                                   //% bvToString (chunkNum-1-i, addrSize)
                                   % (chunkNum-1-i)
                                   % (chunkSize * (chunkNum-i) - 1)
                                   % (chunkSize * (chunkNum-i-1))
                                   % arg2->getName();
                    v->setExec (memBlkBvaddFmt.str());
                }

                memBlkBvaddFmt % v->getName()
                               % addSuffix (v->getName(), 1)
                               % arg1->getName()
                               % bvToString (chunkNum-1, addrSize)
                               % (chunkSize * chunkNum - 1)
                               % (chunkSize * (chunkNum-1))
                               % arg2->getName();
                v->setExec (memBlkBvaddFmt.str());
            } else {
                // (= z_2 (store A   (bvadd addr #2) ((_ extract 7 0) val)))
                // (= z_1 (store z_2 (bvadd addr #1) ((_ extract 15 8) val)))
                // (= z   (store z_1        addr     ((_ extract 23 16) val)))
                memBlkBvaddFmt % addSuffix (v->getName(), chunkNum-1)
                               % arg0->getName()
                               % arg1->getName()
                               % (chunkNum - 1)
                               % (chunkSize - 1)
                               % 0
                               % arg2->getName();
                v->setExec (memBlkBvaddFmt.str());

                for (int i = 1; i < chunkNum-1; i++) {
                    memBlkBvaddFmt % addSuffix (v->getName(), i)
                                   % addSuffix (v->getName(), i+1)
                                   % arg1->getName()
                                   % i
                                   % (chunkSize * (chunkNum-i) - 1)
                                   % (chunkSize * (chunkNum-i-1))
                                   % arg2->getName();
                    v->setExec (memBlkBvaddFmt.str());
                }

                memBlkEmptyFmt % v->getName()
                               % addSuffix (v->getName(), 1)
                               % arg1->getName()
                               % (chunkSize * chunkNum - 1)
                               % (chunkSize * (chunkNum-1))
                               % arg2->getName();
                v->setExec (memBlkEmptyFmt.str());
            }

            /*
            std::string exec = "(= ";
            exec += v->getName() + " ";

            if (isLittle) {
                exec += genStoreMemBlkExecLit (arg0->getName(),     // mem
                                               arg1->getName(),     // addr
                                               arg2->getName(),     // data
                                               chunkSize, chunkNum,
                                               addrSize, chunkNum);
            } else {
                exec += genStoreMemBlkExecBig (arg0->getName(),     // mem
                                               arg1->getName(),     // addr
                                               arg2->getName(),     // data
                                               chunkSize, chunkNum,
                                               addrSize, chunkNum);
            }

            exec += ")";
            //v->setExec (exec);
            */
        } else {
            ILA_ASSERT (false, "Unknown MemOp.");
        }
    }

    void HornTranslator::initMemVar (const MemVar* n, hvptr_t v)
    {
        // name should be the same in the design.
        v->setName (n->getName());
        // type
        boost::format memVarTypeFmt ("(Array (_ BitVec %1%) (_ BitVec %2%))");
        memVarTypeFmt % n->type.addrWidth
                      % n->type.dataWidth;
        //v->setType (memVarTypeFmt.str());
        v->setType ("(Array Int Int)");
        // exec
        v->setExec ("true");
        // in
        v->addInVar (v);
        // out
        v->addOutVar (v);
    }

    void HornTranslator::initMemConst (const MemConst* n, hvptr_t v)
    {
        // name is the value??
        v->setName (_name + "_mem" + boost::lexical_cast <std::string> (v->getId()));
        // type
        boost::format memVarTypeFmt ("(Array (_ BitVec %1%) (_ BitVec %2%))");
        memVarTypeFmt % n->type.addrWidth
                      % n->type.dataWidth;
        //v->setType (memVarTypeFmt.str());
        v->setType ("(Array Int Int)");
        // exec
        v->setExec (v->getPred()); 
        genMemConstRules (n, v);
        _db->addRel (v);
        // in
        // out
        v->addOutVar (v);
        v->setConst ();
    }

    void HornTranslator::initFuncVar (const FuncVar* n, hvptr_t v)
    {
        // FuncVar is actually a relation.
        // name should be the same as in the design
        v->setName (n->getName());
        // type (arg_i_type ret_type)
        std::string type = "(";
        for (unsigned i = 0; i != n->type.argsWidth.size(); i++) {
            type += "(_ BitVec " + 
                    boost::lexical_cast <std::string> (n->type.argsWidth[i]) +
                    ") ";
        }
        type += "(_ BitVec " + 
                boost::lexical_cast <std::string> (n->type.bitWidth) + 
                "))";
        v->setType (type);
        // exec
        v->setExec ("true");
        _db->addRel (v);
        // in
        // out
    }

    void HornTranslator::addBoolOp (const BoolOp* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");

        if (n->op == BoolOp::Op::IF && !_iteAsNode) {
            _curHc->addBody (new HornLiteral (v, true, true));
        } else {
            _curHc->addBody (new HornLiteral (v, false, true));
        }
    }

    void HornTranslator::addBoolVar (const BoolVar* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
        _curHc->addBody (new HornLiteral (v)); // _exec is "true"
    }

    void HornTranslator::addBoolConst (const BoolConst* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
    }

    void HornTranslator::addBvOp (const BitvectorOp* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");

        if (n->op == BitvectorOp::Op::IF && !_iteAsNode) {
            _curHc->addBody (new HornLiteral (v, true, true));
        } else {
            _curHc->addBody (new HornLiteral (v, false, true));
        }
    }

    void HornTranslator::addBvVar (const BitvectorVar* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
        _curHc->addBody (new HornLiteral (v)); // _exec is "true"; prop in
    }

    void HornTranslator::addBvConst (const BitvectorConst* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
    }

    void HornTranslator::addMemOp (const MemOp* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");

        if (n->op == MemOp::Op::ITE && !_iteAsNode) {
            _curHc->addBody (new HornLiteral (v, true, true));
        } else {
            _curHc->addBody (new HornLiteral (v, false, true));
        }
    }

    void HornTranslator::addMemVar (const MemVar* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
        _curHc->addBody (new HornLiteral (v)); // _exec is "true", prop in
    }

    void HornTranslator::addMemConst (const MemConst* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
        _curHc->addBody (new HornLiteral (v)); // need to create rules.
    }

    void HornTranslator::addFuncVar (const FuncVar* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
        _curHc->addBody (new HornLiteral (v)); // _exec is "true".
    }

    std::string HornTranslator::genReadMemBlkExecLit (
            const std::string& mem,
            const std::string& addr,
            int addrWidth, int idx) const
    {
        ILA_ASSERT (idx >= 0, "ReadMemBlock index < 0.");
        // little:
        // (((concat (select A (bvadd x 2w) 
        //   (concat (select A (bvadd x w))
        //           (select A x))))))
        if (idx == 0) {
            boost::format readBlkFmt ("(select %1% %2%)");
            readBlkFmt % mem % addr;
            return readBlkFmt.str();
        } else {
            boost::format readBlkFmt (
                    "(concat (select %1% (bvadd %2% %3%)) %4%)");
            readBlkFmt % mem
                       % addr 
                       % bvToString (idx, addrWidth)
                       % genReadMemBlkExecLit (mem, addr, 
                                               addrWidth, idx-1);
            return readBlkFmt.str();
        }
    }

    std::string HornTranslator::genReadMemBlkExecBig (
            const std::string& mem,
            const std::string& addr,
            int addrWidth, int idx, int num) const
    {
        ILA_ASSERT (num >= 0, "ReadMemBlock num < 0.");
        // big:
        // (((concat (select A x) 
        //   (concat (select A (bvadd x w))
        //           (select A (bvadd x 2w))))))
        if (idx == num - 1) {
            boost::format readBlkFmt ("(select %1% (bvadd %2% %3%)");
            readBlkFmt % mem 
                       % addr
                       % bvToString (idx, addrWidth);
            return readBlkFmt.str();
        } else if (idx == 0) {
            boost::format readBlkFmt ("(concat (select %1% %2%) %3%)");
            readBlkFmt % mem
                       % addr
                       % genReadMemBlkExecBig (mem, addr, 
                                               addrWidth, idx-1, num);
            return readBlkFmt.str();
        } else {
            boost::format readBlkFmt (
                    "(concat (select %1% (bvadd %2% %3%)) %4%)");
            readBlkFmt % mem
                       % addr
                       % bvToString (idx, addrWidth)
                       % genReadMemBlkExecBig (mem, addr, 
                                               addrWidth, idx-1, num);
            return readBlkFmt.str();
        }
    }

    std::string HornTranslator::genStoreMemBlkExecLit (
            const std::string& mem,
            const std::string& addr,
            const std::string& data,
            int chunkSize, int chunkNum,
            int addrWidth, int idx) const
    {
        // little:
        // (store (store (store A addr ((_ extract 7 0) val))
        //                        (+ addr 1) ((_ extract 15 8) val))
        //                        (+ addr 2) ((_ extract 23 16) val))
        ILA_ASSERT (idx > 0, "MemStoreBlk idx < 0.");

        if (idx == 1) {
            boost::format storeBlkFmt (
                    "(store %1% %2% ((_ extract %3% %4%) %5%))");
            storeBlkFmt % mem 
                        % addr
                        % (chunkSize - 1)
                        % 0
                        % data;
            return storeBlkFmt.str();
        } else {
            boost::format storeBlkFmt (
                    "(store %1% (+ %2% %3%) ((_extract %4% %5%) %6%))");
            std::string newMem = genStoreMemBlkExecLit (mem, addr, data,
                                                        chunkSize, chunkNum,
                                                        addrWidth, idx-1);
            storeBlkFmt % newMem
                        % addr
                        % bvToString (idx-1, addrWidth)
                        % (idx*chunkSize - 1)
                        % ((idx-1)*chunkSize - 1)
                        % data;
            return storeBlkFmt.str();
        }
    }

    std::string HornTranslator::genStoreMemBlkExecBig (
            const std::string& mem,
            const std::string& addr,
            const std::string& data,
            int chunkSize, int chunkNum,
            int addrWidth, int idx) const
    {
        // big:
        // (store (store (store A addr ((_ extract 23 16) val))
        //                        (+ addr 1) ((_ extract 15 8) val))
        //                        (+ addr 2) ((_ extract 7 0) val)))
        ILA_ASSERT (idx > 0, "MemStoreBlk idx < 0.");

        if (idx == 1) {
            boost::format storeBlkFmt (
                    "(store %1% %2% ((_ extract %3% %4%) %5%))");
            storeBlkFmt % mem
                        % addr
                        % (chunkNum * chunkSize - 1)
                        % ((chunkNum-1) * chunkSize)
                        % data;
            return storeBlkFmt.str();
        } else {
            boost::format storeBlkFmt (
                    "(store %1% (+ %2% %3%) ((_ extract %4% %5%) %6%))");
            std::string newMem = genStoreMemBlkExecBig (mem, addr, data,
                                                        chunkSize, chunkNum,
                                                        addrWidth, idx-1);
            storeBlkFmt % newMem
                        % addr
                        % bvToString (idx-1, addrWidth)
                        % (chunkSize * (chunkNum-idx+1) - 1)
                        % (chunkSize * (chunkNum-idx))
                        % data;
            return storeBlkFmt.str();
        }
    }

    std::string HornTranslator::bvToString (mp_int_t val, int addrWidth) const
    {
        std::string str = "";
        for (int i = 0; i < addrWidth; i++) {
            if (val % 2 == 1) {
                str = "1" + str;
            } else {
                str = "0" + str;
            }
            val = val >> 1;
        }
        return ("#b" + str);
    }

    std::string HornTranslator::bvToString (int val, int addrWidth) const
    {
        return bvToString ((mp_int_t) val, addrWidth);
    }

    void HornTranslator::genMemConstRules (const MemConst* n, hvptr_t v)
    {
        // (= val1 (select A addr1))
        // (= val2 (select A addr2))
        // (= val3 (select A addr3))
        hcptr_t hc = addClause (v);
        hvptr_t hv = getVar ("memConstIt");
        int dataWidth = n->type.dataWidth;
        int addrWidth = n->type.addrWidth;
       
        for (auto p : n->memvalues.values) {
            boost::format memConstFmt ("(= %1% (select %2% %3%))");
            if (_bvAsInt) {
                memConstFmt % p.second
                            % v->getName()
                            % p.first;
            } else {
                memConstFmt % bvToString (p.second, dataWidth)
                            % v->getName()
                            % bvToString (p.first, addrWidth);
            }
            hv->setExec (memConstFmt.str());
        }

        hc->addBody (new HornLiteral (hv));
    }

    std::string HornTranslator::addSuffix (const std::string& name, 
                                           const int& idx) const
    {
        return (name + "_" + boost::lexical_cast <std::string> (idx));
    }

    hvptr_t HornTranslator::copyVar (hvptr_t v, const int& suffix)
    {
        if (suffix == -1) {
            hvptr_t c = new HornVar (0);
            *c = *v;
            ILA_ASSERT (c != v, "Wrong");
            c->eraseExec ();
            _db->addVar (c);
            return c;
        }

        hvptr_t c = getVar (addSuffix (v->getName(), suffix));
        c->setType (v->getType());
        return c;
    }

}
