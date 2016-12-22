#include <fstream>
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
        _exec.insert (s);
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
        _head = NULL;
    }

    HornClause::~HornClause ()
    {
    }

    void HornClause::addBody (hlptr_t l) 
    {
        _body.insert (l);
        // propogate input args to _head
        ILA_ASSERT (_head != NULL, "head not set yet.");
        _head->getVar()->mergeInVars (l->getVar());
    }

    void HornClause::setHead (hlptr_t l)
    {
        ILA_ASSERT (_body.empty(), "body not empty, may fail.");
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
        // TODO create rules for xor and xnor.
        _varCnt = 0;
        _curHc = NULL;
    }

    HornTranslator::~HornTranslator ()
    {
        if (_db) delete _db;
        _db = NULL;
        // TODO clear maps.
    }

    void HornTranslator::transAll (const std::string& fileName)
    {
        // TODO
    }

    void HornTranslator::transOne (NodeRef* node, 
                                   const std::string& ruleName,
                                   const std::string& fileName)
    {
        log1 ("Horn") << "Trans node " << node->getName() 
            << " as " << ruleName <<  std::endl;

        hvptr_t topV = getVar (ruleName);
        hcptr_t topC = addClause (topV);
        topV->addOutVar (getVar (node->node));

        _curHc = topC;
        depthFirstTraverse (node->node);

        // TODO dump to file
    }

    void HornTranslator::depthFirstTraverse (nptr_t n)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not defined.");

        if (!isITE (n)) {
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

            // condition hold true. Ex. (cond a b c) (then c d) -> (ite a b d)
            hcTrue->addBody (new HornLiteral (hvCond, true, true));
            hcTrue->addBody (new HornLiteral (hvThen, true, true));
            // condition not hold. Ex. !(cond a b c) (else c d) -> (ite a b d)
            hcFalse->addBody (new HornLiteral (hvCond, true, false));
            hcFalse->addBody (new HornLiteral (hvElse, true, true));

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
            _db->addRule (v);
        }
        _db->addClause (c);
        return c;
    }

    void HornTranslator::initVar (hvptr_t v, nptr_t node)
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
        // FIXME
    }

    bool HornTranslator::isITE (nptr_t n)
    {
        // FIXME SMT 2.0 has ite for core theory.
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
        // _name, _type, _exec, _ins, _outs
        // name
        v->setName ("b" + boost::lexical_cast <std::string> (v->getId()));
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
            "=>", "bvult",          // imply, ult
            ">", "<=", ">=", "<",   // sgt, sle, sge, slt
            "bvult", "bvult",       // ugt, ule
            "bvult",                // uge
            "=", "distinct",        // equal, distinct
            "if"                    // ite
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

            if (n->op == BoolOp::Op::AND   || 
                n->op == BoolOp::Op::OR    ||
                n->op == BoolOp::Op::XOR   || 
                n->op == BoolOp::Op::IMPLY ||
                n->op == BoolOp::Op::ULT   ||
                n->op == BoolOp::Op::EQUAL ||
                n->op == BoolOp::Op::DISTINCT) {
                // use primitive format (= z (op x y))
                priFmt % v->getName()    
                       % boolOpNames[n->op]
                       % arg0->getName() 
                       % arg1->getName();
                v->setExec (priFmt.str());
            } else if (n->op == BoolOp::Op::XNOR || 
                       n->op == BoolOp::Op::NAND ||
                       n->op == BoolOp::Op::NOR  ||
                       n->op == BoolOp::Op::UGE) {
                // use negated format (= z (not (op x y)))
                negFmt % v->getName()
                       % boolOpNames[n->op]
                       % arg0->getName()
                       % arg1->getName();
                v->setExec (negFmt.str());
            } else if (n->op == BoolOp::Op::UGT) {
                // z = x > y  --> (= z (ult y x))
                priFmt % v->getName() 
                       % boolOpNames[n->op]
                       % arg1->getName()
                       % arg0->getName();
                v->setExec (priFmt.str());
            } else if (n->op == BoolOp::Op::ULE) {
                // z = x <= y --> (= z (not (ult y x)))
                negFmt % v->getName()
                       % boolOpNames[n->op]
                       % arg1->getName()
                       % arg0->getName();
                v->setExec (negFmt.str());
            } else {
                std::string errMsg = "BoolOp" + 
                                     boost::lexical_cast <std::string> (n->op) +
                                     " not supported.";
                ILA_ASSERT (false, errMsg);
            }
        //// Ternary ////
        } else if (n->op == BoolOp::Op::IF) {
            // ITE (x, y, z) --> (rel.x y z)
            // FIXME ITE should never be "executed".
            // FIXME SMT 2.0 has ite for core theory.
            v->setExec ("true");
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
    }

    void HornTranslator::initBvOp (const BitvectorOp* n, hvptr_t v)
    {
        // name 
        v->setName ("bv" + boost::lexical_cast <std::string> (v->getId()));
        // type
        v->setType ("(_ BitVec " + 
                    boost::lexical_cast <std::string> (n->type.dataWidth) + 
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
        // LROTATE, RROTATE, S_EXT, SDIV, SMOD, SREM, ASHR
        std::string bvOpNames[] = {
            "invalid",                      // not used 
            // unary
            "bvneg", "bvnot",
            "rotate-left", "rotate-right",  // not used
            "concat",
            "sign-extend",                  // not used
            "extract",
            // binary
            "bvadd", "bvadd", "bvand", "bvor", 
            "xor", "xnor",                  // not used
            "bvand", "bvor",
            "div",                          // not used
            "udiv", 
            "rem",                          // not used
            "urem", 
            "mod",                          // not used
            "bvshl", 
            "bvlshr", 
            "ashr",                         // not used
            "bvmul", "concat", 
            "get-bit",                      // not used
            "select", "read-block",
            // ternary
            "if", "apply_fun", 
        };

        boost::format bvUnaryFmt ("(= %1% (%2% %3%))");
        boost::format bvBinaryFmt ("(= %1% (%2% %3% %4%))");
        boost::format bvBinaryNegFmt ("(= %1% (not (%2% %3% %4%)))");
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
                unsigned w = n->type.dataWidth;
                unsigned d = n->arg(0)->type.dataWidth;
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

            if (n->op == BitvectorOp::Op::ADD  || 
                n->op == BitvectorOp::Op::AND  ||
                n->op == BitvectorOp::Op::OR   ||
                n->op == BitvectorOp::Op::MUL  ||
                n->op == BitvectorOp::Op::UDIV ||
                n->op == BitvectorOp::Op::UREM ||
                n->op == BitvectorOp::Op::SHL  ||
                n->op == BitvectorOp::Op::LSHR ||
                n->op == BitvectorOp::Op::CONCAT ||
                n->op == BitvectorOp::Op::READMEM) {
                // z = x op y --> (= z (op x y))
                bvBinaryFmt % v->getName()
                            % bvOpNames[n->op]
                            % arg0->getName()
                            % arg1->getName();
                v->setExec (bvBinaryFmt.str());
            } else if (n->op == BitvectorOp::Op::SUB) {
                // z = x - y --> (= z (bvadd x (bvneg y)))
                bvBinaryFmt % v->getName()
                            % bvOpNames[n->op]
                            % arg0->getName()
                            % ("(bvneg " + arg1->getName() + ")");
                v->setExec (bvBinaryFmt.str());
            } else if (n->op == BitvectorOp::Op::NAND ||
                       n->op == BitvectorOp::Op::NOR) {
                // z = x op y --> (= z (not (op x y)))
                bvBinaryNegFmt % v->getName()
                               % bvOpNames[n->op]
                               % arg0->getName()
                               % arg1->getName();
                v->setExec (bvBinaryNegFmt.str());
            } else if (n->op == BitvectorOp::Op::XOR) {
                // z = x ^ y --> (xor x y z)
                boost::format bvXorFmt ("(xor %1% %2% %3%)");
                bvXorFmt % arg0->getName()
                         % arg1->getName()
                         % v->getName();
                v->setExec (bvXorFmt.str());
            } else if (n->op == BitvectorOp::Op::XNOR) {
                // z = x ^ y --> (xnor x y z)
                boost::format bvXnorFmt ("(xnor %1% %2% %3%)");
                bvXnorFmt % arg0->getName()
                          % arg1->getName()
                          % v->getName();
                v->setExec (bvXnorFmt.str());
            } else if (n->op == BitvectorOp::Op::SDIV ||
                       n->op == BitvectorOp::Op::SREM ||
                       n->op == BitvectorOp::Op::SMOD ||
                       n->op == BitvectorOp::Op::ASHR) {
                // not supported yet.
                ILA_ASSERT (false, "signed/arithmetic bvOp not supported yet.");
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
            endianness_t e = (endianness_t) n->param(1);
            // big:
            // z = readblk (A, x, n) --> (= z (((concat (select A x) 
            //                                  (concat (select A (+ x w))
            //                                  (concat (select A (+ x 2w))))))))
            // little:
            // z = readblk (A, x, n) --> (= z (((concat (select A (+ x 2w) 
            //                                  (concat (select A (+ x w))
            //                                  (concat (select A x))))))))
            std::string exec = "";
            boost::format readBlkFmt ("(= %1% %2%)");

            if (e == LITTLE_E) {
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
            // ITE will not be "executed"
            v->setExec ("true");
        } else if (n->op == BitvectorOp::Op::APPLY_FUNC) {
            // z = foo (x, y) --> (foo x y z)
            v->setExec (v->getPred());
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
                    boost::lexical_cast <std::string> (n->type.dataWidth) + 
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
        v->setName (bvToString (n->val(), n->type.dataWidth));
        // type
        v->setType ("(_ BitVec " + 
                    boost::lexical_cast <std::string> (n->type.dataWidth) +
                    ")");
        // exec
        v->setExec ("true");
        // ins
        // outs
    }
      
    void HornTranslator::initMemOp (const MemOp* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initMemVar (const MemVar* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initMemConst (const MemConst* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initFuncVar (const FuncVar* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::addBoolOp (const BoolOp* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");

        if (n->op == BoolOp::Op::IF) {
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

        // FIXME check it
        if (n->op == BitvectorOp::Op::IF) {
            _curHc->addBody (new HornLiteral (v, true, true));
        } else {
            _curHc->addBody (new HornLiteral (v, false, true));
        }
    }

    void HornTranslator::addBvVar (const BitvectorVar* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
        _curHc->addBody (new HornLiteral (v)); // _exec is "true"
    }

    void HornTranslator::addBvConst (const BitvectorConst* n, hvptr_t v)
    {
        ILA_ASSERT (_curHc != NULL, "working clause not exist.");
    }

    void HornTranslator::addMemOp (const MemOp* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::addMemVar (const MemVar* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::addMemConst (const MemConst* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::addFuncVar (const FuncVar* n, hvptr_t v)
    {
        // TODO
    }

    std::string HornTranslator::genReadMemBlkExecLit (
            const std::string& mem,
            const std::string& addr,
            int addrWidth, int idx)
    {
        ILA_ASSERT (idx >= 0, "ReadMemBlock index < 0.");
        // little:
        // (((concat (select A (+ x 2w) 
        //   (concat (select A (+ x w))
        //           (select A x))))))
        if (idx == 0) {
            boost::format readBlkFmt ("(select %1% %2%)");
            readBlkFmt % mem % addr;
            return readBlkFmt.str();
        } else {
            boost::format readBlkFmt ("(concat (select %1% (+ %2% %3%)) %4%)");
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
            int addrWidth, int idx, int num)
    {
        ILA_ASSERT (num >= 0, "ReadMemBlock num < 0.");
        // big:
        // (((concat (select A x) 
        //   (concat (select A (+ x w))
        //           (select A (+ x 2w))))))
        if (idx == num - 1) {
            boost::format readBlkFmt ("(select %1% (+ %2% %3%)");
            readBlkFmt % mem 
                       % addr
                       % bvToString (idx, addrWidth);
            return readBlkFmt.str();
        } else if (idx == 0) {
            boost::format readBlkFmt ("(concat (select %1% %2%) %3%)");
            readBlkFmt % mem
                       % addr
                       % genReadMemBlkExecBig (mem, addr, addrWidth, idx-1, num);
            return readBlkFmt.str();
        } else {
            boost::format readBlkFmt ("(concat (select %1% (+ %2% %3%)) %4%)");
            readBlkFmt % mem
                       % addr
                       % bvToString (idx, addrWidth)
                       % genReadMemBlkExecBig (mem, addr, addrWidth, idx-1, num);
            return readBlkFmt.str();
        }
    }

    std::string HornTranslator::bvToString (mp_int_t val, int addrWidth)
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
}

