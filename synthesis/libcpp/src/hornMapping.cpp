// File: hornMapping.cpp
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
    FixClause::FixClause ()
    {
    }

    FixClause::~FixClause ()
    {
    }

    void FixClause::addBody (const std::string& s)
    {
        _body.insert (s);
    }

    void FixClause::setHead (const std::string& s)
    {
        _head = s;
    }

    void FixClause::print (std::ostream& out)
    {
        out << "(rule (=> (and true\n";
        for (auto b : _body) {
            out << std::setw(15) << "";
            out << b << "\n";
        }
        out << std::setw(12) << ")\n";
        out << std::setw(10) << "";
        out << _head << "))\n";
    }

    // ---------------------------------------------------------------------- //
    HornRewriter::HornRewriter (HornTranslator* tr) 
        : _tr (tr)
    {
    }

    HornRewriter::~HornRewriter ()
    {
    }

    void HornRewriter::connect (const std::string& s, const std::string& o)
    {
        if (_mapSO.find (s) == _mapSO.end()) {
            _mapSO[s] = o;
        } else {
            ILA_ASSERT (_mapSO[s] == o, 
                "Output for state " + s + "has been connected.");
        }

        if (_mapOS.find (o) == _mapOS.end()) {
            _mapOS[o] = s;
        } else {
            ILA_ASSERT (_mapOS[o] == s,
                "Output for state " + s + "has been connected.");
        }
    }

    std::string HornRewriter::rewritePred (hvptr_t p, char entry, int entryId,
                                                      char exit, int exitId)
    {
        if (p->getInNum() == 0) {
            ILA_ASSERT (p->isConst(), 
                    "Non-const empty predicate " + p->getName() + ".");
            return p->getNd();
        }

        ILA_ASSERT (p->getInNum() == _mapSO.size(), 
                "Arg num mismatch. Connect all dependent states.");

        auto inSet = p->getInSet (); 
        auto outSet = p->getOutSet ();

        std::string inArgs = "";
        for (auto it = inSet.begin(); it != inSet.end(); it++) {
            ILA_ASSERT (_mapSO.find (it->first) != _mapSO.end(),
                    "State " + it->first + " not found.");
            inArgs += " ";
            hvptr_t var = NULL;
            if (entry == 'I') {
                var = it->second;
            } else if (entry == 'O') {
                std::string outName = _mapSO [it->first];
                for (auto outVar : outSet) {
                    if (outVar->getName() == outName) {
                        var = outVar;
                        break;
                    }
                }
            } else {
                ILA_ASSERT (false, "Unknown rewrite option.");
            }

            ILA_ASSERT (var != NULL, 
                    "var " + it->first + " to rewrite not found.");

            if (entryId == -1) {
                inArgs += var->getName();
            } else {
                inArgs += _tr->copyVar (var, entryId)->getName();
            }
        }

        std::string outArgs = "";
        for (auto out : outSet) {
            ILA_ASSERT (_mapOS.find (out->getName()) != _mapOS.end(),
                    "State " + out->getName() + " not found.");
            outArgs += " ";
            hvptr_t var = NULL;
            if (exit == 'O') {
                var = out;
            } else if (exit == 'I') {
                std::string inName = _mapOS [out->getName()];
                for (auto it = inSet.begin(); it != inSet.end(); it++) {
                    if (it->first == inName) {
                        var = it->second;
                        break;
                    }
                }
            } else {
                ILA_ASSERT (false, "Unknown rewrite option.");
            }

            ILA_ASSERT (var != NULL,
                    "var " + out->getName() + " to rewrite not found.");

            if (exitId == -1) {
                outArgs += var->getName();
            } else {
                outArgs += _tr->copyVar (var, exitId)->getName();
            }
        }

        boost::format rewriteFmt ("(%1%%2%%3%)");
        rewriteFmt % p->getName() % inArgs % outArgs;
        return rewriteFmt.str();
    }

    std::string HornRewriter::addSuffix (const std::string& name, 
                                         const int& idx) const
    {
        return (name + "_" + boost::lexical_cast <std::string> (idx));
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::generateMapping (const std::string& type)
    {
        // Type Options: Interleave / Blocking
        if (type == "Interleave") {
            generateInterleaveMapping ();
        } else if (type == "Blocking") {
            generateBlockingMapping ();
        } else {
            ILA_ASSERT (false, "Unknown Modeling " + type + ".");
        }
    }

    void HornTranslator::addInstr (const std::string& i, NodeRef* d)
    {
        auto it = _instrs.find (i);
        ILA_ASSERT (it == _instrs.end(), "Instruction "+i+" already created.");

        struct Instr_t* instr = new struct Instr_t;
        _instrs[i] = instr;
        instr->_name = i;
        instr->_decodeFunc = hornifyNode (d, i + ".decode");
        //instr->_decodeFunc = getVar (d->node);
    }

    void HornTranslator::addNext (const std::string& i, const std::string& s,
                                  NodeRef* n)
    {
        auto it = _instrs.find (i);
        if (it == _instrs.end()) {
            it = _childs.find (i);
            if (it == _childs.end()) {
                ILA_ASSERT (false, "Instruction "+i+" not exist.");
            }
        }

        struct Instr_t* instr = it->second;
        instr->_nxtFuncs[s] = hornifyNode (n, i + "." + s);
        //instr->_nxtFuncs[s] = getVar (n->node);
    }

    void HornTranslator::addChildInstr (const std::string& c, 
                                        const std::string& i,
                                        NodeRef* d)
    {
        auto itP = _instrs.find (i);
        ILA_ASSERT (itP != _instrs.end(), "Instruction "+i+" not exists.");
        auto itC = _childs.find (c);
        ILA_ASSERT (itC == _childs.end(), "Child-instr "+c+" already exists.");

        itP->second->_childInstrs.insert (c);

        struct Instr_t* instr = new struct Instr_t;
        _childs[c] = instr;
        instr->_name = c;
        instr->_decodeFunc = hornifyNode (d, c + ".decode");
        //instr->_decodeFunc = getVar (d->node);
    }


    void HornTranslator::generateInterleaveMapping () 
    { 
        for (auto itI = _instrs.begin(); itI != _instrs.end(); itI++) {
            auto instr = itI->second;
            if (instr->_childInstrs.empty()) {
                // No child-instructions
                // D & N --> M
                fcptr_t M = new FixClause ();
                hvptr_t m = getVar (instr->_name);

                // decode: merge input/output & add constraint
                m->mergeInVars (instr->_decodeFunc);
                m->mergeOutVars (instr->_decodeFunc);

                if (instr->_decodeFunc->isConst()) {
                    M->addBody (instr->_decodeFunc->getName());
                } else {
                    M->addBody (instr->_decodeFunc->getPred());
                    M->addBody (instr->_decodeFunc->getOutVar()->getName());
                }

                // next state: merge input/output & constraint
                for (auto itN  = instr->_nxtFuncs.begin(); 
                          itN != instr->_nxtFuncs.end(); itN++) {
                    auto nxt = itN->second;
                    M->addBody (nxt->getPred());
                    m->mergeInVars (nxt);
                    m->mergeOutVars (nxt);
                }

                // set predicate for head
                M->setHead (m->getPred());

                _db->addRel (m);
                _db->addFixClause (M);
            } else {
                // With child-instructions.
                // L & Du & Nu --> L'
                // L & D & N & L --> M

                // collect related states
                hvptr_t lVar = getVar ("L_" + instr->_name);
                lVar->setLevel (1);
                HornRewriter* loopRW = new HornRewriter (this);
                for (auto uName : instr->_childInstrs) {
                    ILA_ASSERT (_childs.find (uName) != _childs.end(), 
                                "uInstr not found.");
                    auto uInstr = _childs.find (uName)->second;

                    lVar->mergeInVars (uInstr->_decodeFunc);
                    for (auto itUN  = uInstr->_nxtFuncs.begin();
                              itUN != uInstr->_nxtFuncs.end(); itUN++) {
                        auto uNxt = itUN->second;
                        lVar->mergeInVars (uNxt);
                        lVar->mergeOutVars (uNxt);
                        // update rewriter.
                        loopRW->connect (itUN->first, 
                                         uNxt->getOutVar()->getName());
                    }
                }
                _db->addRel (lVar);
                
                // rewrite rules for loop predicate
                for (auto uName : instr->_childInstrs) {
                    auto uI = _childs.find (uName)->second;

                    fcptr_t L = new FixClause ();
                    // entry loop predicate         -- L(s_0, s)
                    // decode of uInstr             -- D(s, b)
                    //                              -- b
                    // nxt of uInstr                -- N(s, n)
                    // head: exit loop predicate    -- L(s_0, n)
                    L->addBody (loopRW->rewritePred (lVar, 'I', 0, 'I', -1));

                    if (uI->_decodeFunc->isConst()) {
                        L->addBody (uI->_decodeFunc->getName());
                    } else {
                        L->addBody (uI->_decodeFunc->getPred());
                        L->addBody (uI->_decodeFunc->getOutVar()->getName());
                    }

                    for (auto itUN  = uI->_nxtFuncs.begin();
                              itUN != uI->_nxtFuncs.end(); itUN++) {
                        L->addBody (itUN->second->getPred());
                    }

                    L->setHead (loopRW->rewritePred (lVar, 'I', 0, 'O', -1));
                    _db->addFixClause (L);
                }

                // L & D & N & L --> M
                // entry loop predicate         -- L(s_0, s)
                // decode for instr             -- D(s, b)
                //                              -- b
                // nxt of instr                 -- N(s, n)
                // exit loop predicate          -- L(n, s_1)
                // head: exit instr predicate   -- M(s_0, s_1)
                hvptr_t mVar = getVar (instr->_name);
                fcptr_t M = new FixClause ();
                mVar->setLevel (1);
                HornRewriter* mRW = new HornRewriter (this);

                M->addBody (loopRW->rewritePred (lVar, 'I', 0, 'I', -1));

                if (instr->_decodeFunc->isConst()) {
                    M->addBody (instr->_decodeFunc->getName());
                } else {
                    M->addBody (instr->_decodeFunc->getPred());
                    M->addBody (instr->_decodeFunc->getOutVar()->getName());

                    mVar->mergeInVars (instr->_decodeFunc);
                }

                for (auto itN  = instr->_nxtFuncs.begin(); 
                          itN != instr->_nxtFuncs.end(); itN++) {
                    auto nxt = itN->second;
                    M->addBody (nxt->getPred());

                    mVar->mergeInVars (nxt);
                    mVar->mergeOutVars (nxt);
                    mRW->connect (itN->first, 
                                  nxt->getOutVar()->getName());
                }

                M->addBody (loopRW->rewritePred (lVar, 'O', -1, 'I', 1));

                M->setHead (mRW->rewritePred (mVar, 'I', 0, 'I', 1));

                _db->addRel (mVar);
                _db->addFixClause (M);

                delete loopRW;
                delete mRW;
                loopRW = mRW = NULL;
            }
        }
    }

    void HornTranslator::generateBlockingMapping ()
    { 
        // TODO
    }

}
