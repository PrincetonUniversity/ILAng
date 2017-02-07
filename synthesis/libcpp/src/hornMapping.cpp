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
        // TODO
        for (auto it : _body) {
            out << it << "\n";
        }
        out << _head << "\n";
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
                HornRewriter* loopRW = new HornRewriter (this);
                for (auto uName : instr->_childInstrs) {
                    ILA_ASSERT (_childs.find (uName) != _childs.end(), 
                                "uInstr not found.");
                    auto uInstr = _childs.find (uName)->second;

                    lVar->mergeInVars (uInstr->_decodeFunc);
                    for (auto itUN  = uInstr->_nxtFuncs.begin();
                              itUN != uInstr->_nxtFuncs.end(); itUN++) {
                        auto uNxt = itUN->second;
                        log1 ("Horn") << "merge in " << uNxt->getName() << "\n";
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
                    log1 ("Horn") << "print Loop\n";
                    L->print (std::cout);
                }

                delete loopRW;
                loopRW = NULL;

                // L & D & N & L --> M
                // entry loop predicate         -- L(s_0, s)
                // decode for instr             -- D(s, b)
                //                              -- b
                // nxt of instr                 -- N(s, n)
                // exit loop predicate          -- L(n, s_1)
                // head: exit instr predicate   -- M(s_0, s_1)
                hvptr_t mVar = getVar (instr->_name);
                fcptr_t M = new FixClause ();

                _db->addRel (mVar);
                _db->addFixClause (M);
                log1 ("Horn") << "print M\n";
                M->print (std::cout);
            }
        }
    }

    void HornTranslator::generateBlockingMapping ()
    { 
        // TODO
    }

    std::string HornTranslator::rewritePred (hvptr_t v, const int& i, 
                                             const int& o) const
    {
        // TODO
        return "";
    }

}
