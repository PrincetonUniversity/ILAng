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
    HornRewriter::HornRewriter (HornTranslator* tr, hvptr_t p) 
        : _tr (tr),
          _pred (p)
    {
    }

    HornRewriter::~HornRewriter ()
    {
    }

    void HornRewriter::configOutput (const std::string& state, hvptr_t arg)
    {
        auto outSet = _pred->getOutSet ();

        // find output state.
        bool found = false;
        for (auto outVar : outSet) {
            if (outVar == arg) {
                ILA_ASSERT (_mapOS.find (arg) == _mapOS.end(),
                            arg->getName() + " has been configured.");
                _mapOS[arg] = state;
                found = true;
                break;
            }
        }

        ILA_ASSERT (found, "Arguement " + arg->getName() + " not found.");
    }

    void HornRewriter::configInput ()
    {
        auto inSet = _pred->getInSet ();

        for (auto itIn = inSet.begin(); itIn != inSet.end(); itIn++) {
            _mapIS[itIn->second] = itIn->first;
            _mapSI[itIn->first] = itIn->second;
        }
    }

    void HornRewriter::update (const std::string& state,
                               hvptr_t inArg, hvptr_t outArg)
    {
        if (inArg != NULL) _mapSI[state] = inArg;
        if (outArg != NULL) _mapSO[state] = outArg;
    }

    std::string HornRewriter::rewrite (char inType, int inSuff, 
                                       char outType, int outSuff) 
    {
        if (_pred->getInNum() == 0) {
            ILA_ASSERT (_pred->isConst(),
                    "Non-const empty predicate " + _pred->getName() + ".");
            return _pred->getNd();
        }

        auto inSet = _pred->getInSet();
        auto outSet = _pred->getOutSet();

        std::string inArgs = "";
        for (auto itIn = inSet.begin(); itIn != inSet.end(); itIn++) {
            // input (not state)
            if (_mapSO.find (_mapIS[ itIn->second ]) == _mapSO.end()) {
                inArgs += " " + itIn->first;
                continue;
            }
            // state
            hvptr_t var = (inType == 'I') ? _mapSI[ _mapIS[ itIn->second ]]
                                          : _mapSO[ _mapIS[ itIn->second ]];
            inArgs += " ";
            inArgs += (inSuff == -1) ? var->getName()
                                     : _tr->copyVar (var, inSuff)->getName();
        }

        std::string outArgs = "";
        for (auto outVar : outSet) {
            hvptr_t var = (outType == 'I') ? _mapSI[ _mapOS[ outVar ]]
                                           : _mapSO[ _mapOS[ outVar ]];
            outArgs += " ";
            outArgs += (outSuff == -1) ? var->getName()
                                       : _tr->copyVar (var, outSuff)->getName();
        }
        
        boost::format rewriteFmt ("(%1%%2%%3%)");
        rewriteFmt % _pred->getName() % inArgs % outArgs;
        return rewriteFmt.str();
    }

    void HornRewriter::addRewriteRule (hcptr_t C, char aType, int aSuff,
                                                  char bType, int bSuff)
    {
        boost::format eqFmt ("(= %1% %2%)");
        auto outSet = _pred->getOutSet();
        for (auto outVar : outSet) {
            hvptr_t varA = (aType == 'I') ? _mapSI[ _mapOS[ outVar ]]
                                          : _mapSO[ _mapOS[ outVar ]];
            hvptr_t varB = (bType == 'I') ? _mapSI[ _mapOS[ outVar ]]
                                          : _mapSO[ _mapOS[ outVar ]];
            varA = (aSuff == -1) ? varA : _tr->copyVar (varA, aSuff);
            varB = (bSuff == -1) ? varB : _tr->copyVar (varB, bSuff);

            eqFmt % varA->getName() % varB->getName();
            hvptr_t ruleVar = _tr->copyVar (_pred, -1);
            ruleVar->setExec (eqFmt.str());
            C->addBody (new HornLiteral (ruleVar));
        }
    }

    hvptr_t HornRewriter::getRewriteVar (char inTy, int inSu, 
                                         char outTy, int outSu) 
    {
        hvptr_t ret = _tr->copyVar (_pred, -1);
        ret->setExec (rewrite (inTy, inSu, outTy, outSu));
        return ret;
    }

    // ---------------------------------------------------------------------- //
    void HornTranslator::generateMapping (const std::string& type)
    {
        // Type Options: Interleave / Blocking
        if (type == "Interleave") {
            //generateInterleaveMapping ();
            allInterleaveMapping ();
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
    }

    void HornTranslator::addNext (const std::string& i, const std::string& s,
                                  NodeRef* n)
    {
        auto it = _instrs.find (i);
        if (it == _instrs.end()) {
            it = _childs.find (i);
            if (it == _childs.end()) {
                ILA_ASSERT (false, "Instruction " + i + " not exist.");
            }
        }

        struct Instr_t* instr = it->second;
        instr->_nxtFuncs[s] = hornifyNode (n, i + "." + s);
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
    }


    void HornTranslator::generateInterleaveMapping () 
    { 
        for (auto itI = _instrs.begin(); itI != _instrs.end(); itI++) {
            auto instr = itI->second;

            // Create and register loop predicate.
            hvptr_t lVar = getVar ("L_" + instr->_name);
            lVar->setLevel (1);
            _db->addRel (lVar);

            HornRewriter* loopRW = new HornRewriter (this, lVar);
            // Collect dependent/updated states. Run on first child-instr.
            for (auto uName : instr->_childInstrs) {
                ILA_ASSERT (_childs.find (uName) != _childs.end(), 
                            "uInstr " + uName + " not found.");
                auto uInstr = _childs.find (uName)->second;

                lVar->mergeInVars (uInstr->_decodeFunc);
                for (auto itUN  = uInstr->_nxtFuncs.begin();
                          itUN != uInstr->_nxtFuncs.end(); itUN++) {
                    auto uNxt = itUN->second;

                    lVar->mergeInVars (uNxt);
                    lVar->mergeOutVars (uNxt);

                    loopRW->configOutput (itUN->first, uNxt->getOutVar());
                }

                loopRW->configInput();
                break;
            }
            
            // Create a clause for each loop step (each child-instr).
            // Body ************************************************
            // Entry loop predicate                     -- L(s_0, s)
            // Decode of uInstr                         -- D(s, b)
            // Decode true                              -- b
            // Next state functions                     -- N(s, n)
            // Head ************************************************
            // Exit loop predicate                      -- L(s_0, n)

            for (auto uName : instr->_childInstrs) {
                auto uInstr = _childs.find (uName)->second;

                // Create and register the clause.
                hvptr_t lVarCopy = copyVar (lVar, -1);
                hcptr_t L = addClause ();

                // Add decode function to the body.
                hvptr_t dOut = copyVar (uInstr->_decodeFunc->getOutVar(), -1);
                dOut->setExec (dOut->getName());
                L->addBody (new HornLiteral (uInstr->_decodeFunc, true, true));
                L->addBody (new HornLiteral (dOut));

                // Update the loop rewriter and add next state functions.
                for (auto itUN  = uInstr->_nxtFuncs.begin();
                          itUN != uInstr->_nxtFuncs.end(); itUN++) {
                    L->addBody (new HornLiteral (itUN->second, true, true));

                    loopRW->update (itUN->first, 
                                    NULL,
                                    itUN->second->getOutVar());
                }

                // Add entry loop predicate to the body.
                hvptr_t lEntry = copyVar (lVar, -1);
                lEntry->setExec (loopRW->rewrite ('I', 0, 'I', -1));
                L->addBody (new HornLiteral (lEntry));
                // Add exit loop predicate to the head.
                lVarCopy->setExec (loopRW->rewrite ('I', 0, 'O', -1));
                L->setHead (new HornLiteral (lVarCopy));
            }

            // Create a clause for the loop init point.
            // Head ************************************************
            // Instr predicate                          -- L(s, s)
            if (!instr->_childInstrs.empty()) {
                hcptr_t L = addClause();
                hvptr_t lVarCopy = copyVar (lVar, -1);
                lVarCopy->setExec (loopRW->rewrite ('I', -1, 'I', -1));
                L->setHead (new HornLiteral (lVarCopy));
            }

            // Create a clause for the instruction (w/ loop).
            // Body ************************************************
            // Entry loop predicate                     -- L(s_0, s)
            // Decode for instr                         -- D(s, b)
            // Decode true                              -- b
            // Next state functions                     -- N(s, n)
            // Exit loop predicate                      -- L(n, s_1)
            // Head ************************************************
            // Instr predicate                          -- M(s_0, s_1)

            // Create and register the predicate/clause.
            hvptr_t mVar = getVar (instr->_name);
            mVar->setLevel (1);
            _db->addRel (mVar);
            hcptr_t M = addClause ();

            HornRewriter* mRW = new HornRewriter (this, mVar);

            // Add decode to the body.
            hvptr_t dOut = copyVar (instr->_decodeFunc->getOutVar(), -1);
            dOut->setExec (dOut->getName());
            M->addBody (new HornLiteral (dOut));
            M->addBody (new HornLiteral (instr->_decodeFunc, true, true));

            mVar->mergeInVars (instr->_decodeFunc);

            // Update loop rewriter, instr rewriter, and add next functions.
            for (auto itN  = instr->_nxtFuncs.begin(); 
                      itN != instr->_nxtFuncs.end(); itN++) {
                auto nxt = itN->second;
                M->addBody (new HornLiteral (nxt, true, true));

                mVar->mergeInVars (nxt);
                mVar->mergeOutVars (nxt);
                mRW->configOutput (itN->first, nxt->getOutVar());

                mRW->update (itN->first,
                             NULL,
                             itN->second->getOutVar());

                loopRW->update (itN->first,
                                NULL, 
                                itN->second->getOutVar());
            }

            mRW->configInput();

            if (instr->_childInstrs.empty()) {
                _db->removeRel (lVar);
                hvptr_t mOut = copyVar (mVar, -1);
                //mOut->setExec (mRW->rewrite ('I', -1, 'O', -1));
                mOut->setExec (mRW->rewrite ('I', 0, 'I', 1));
                M->setHead (new HornLiteral (mOut));
                mRW->addRewriteRule (M, 'I', -1, 'I', 0);
                mRW->addRewriteRule (M, 'O', -1, 'I', 1);
            } else {
                hvptr_t lEntry = copyVar (lVar, -1);
                hvptr_t lExit = copyVar (lVar, -1);
                lEntry->setExec (loopRW->rewrite ('I', 0, 'I', -1));
                lExit->setExec (loopRW->rewrite ('O', -1, 'I', 1));
                M->addBody (new HornLiteral (lEntry));
                M->addBody (new HornLiteral (lExit));

                hvptr_t mOut = copyVar (mVar, -1);
                mOut->setExec (mRW->rewrite ('I', 0, 'I', 1));
                M->setHead (new HornLiteral (mOut));
            }

            if (loopRW != NULL) delete loopRW;
            if (mRW != NULL) delete mRW;
        }
    }

    void HornTranslator::generateBlockingMapping ()
    { 
        for (auto itI = _instrs.begin(); itI != _instrs.end(); itI++) {
            auto instr = itI->second;

            // Create and register child-entry predicate.
            hvptr_t cVar = getVar ("C_" + instr->_name);
            cVar->setLevel (1);
            _db->addRel (cVar); 

            // Create and register omstrictopm predicate/
            hvptr_t mVar = getVar (instr->_name);
            mVar->setLevel (1);
            _db->addRel (mVar);

            HornRewriter* cRW = new HornRewriter (this, cVar);
            HornRewriter* mRW = new HornRewriter (this, mVar);
            // Collect dependent arguments. Configure cVar and cRW.
            cVar->mergeInVars (instr->_decodeFunc);
            mVar->mergeInVars (instr->_decodeFunc);
            for (auto itN  = instr->_nxtFuncs.begin(); 
                      itN != instr->_nxtFuncs.end(); itN++) {
                auto nxt = itN->second;
                cVar->mergeInVars (nxt);
                cVar->mergeOutVars (nxt);

                mVar->mergeInVars (nxt);
                mVar->mergeOutVars (nxt);

                cRW->configOutput (itN->first, nxt->getOutVar());
                mRW->configOutput (itN->first, nxt->getOutVar());
                cRW->update (itN->first, NULL, nxt->getOutVar());
                mRW->update (itN->first, NULL, nxt->getOutVar());
            }
            cRW->configInput();
            mRW->configInput();

            // Create a clause for the child-entry point (instr exe).
            // Body ************************************************
            // Decode for instr                         -- D(s, b)
            // Decode true                              -- b
            // Next state functions                     -- N(s, n)
            // Head ************************************************
            // Child-entry predicate                    -- C(s, n)

            hcptr_t C = addClause ();

            // Add decode function to the body.
            hvptr_t d = copyVar (instr->_decodeFunc->getOutVar(), -1);
            d->setExec (d->getName());
            C->addBody (new HornLiteral (d));
            C->addBody (new HornLiteral (instr->_decodeFunc, true, true));

            // Add next state function to the body.
            for (auto itN  = instr->_nxtFuncs.begin();
                      itN != instr->_nxtFuncs.end(); itN++) {
                C->addBody (new HornLiteral (itN->second, true, true));
            }

            // Set the head.
            C->setHead (new HornLiteral (cVar, true, true));

            // Create a clause for each child-instr.
            // Body ************************************************
            // Child-entry predicate                    -- C(s_0, s)
            // Decode of uInstr                         -- D(s, b)
            // Decode true                              -- b
            // Next state functions                     -- N(s, n)
            // Head ************************************************
            // Exit of child-entry predicate            -- C(s_0, n)

            for (auto uName : instr->_childInstrs) {
                auto uInstr = _childs.find (uName)->second;

                // Create and register the clause.
                hvptr_t cVarCopy = copyVar (cVar, -1);
                hcptr_t uC = addClause ();

                // Add decode function to the body.
                hvptr_t ud = copyVar (uInstr->_decodeFunc->getOutVar(), -1);
                ud->setExec (ud->getName());
                uC->addBody (new HornLiteral (ud));
                uC->addBody (new HornLiteral (uInstr->_decodeFunc, true, true));

                // Update the rewriter and add next state functions.
                for (auto itUN  = uInstr->_nxtFuncs.begin();
                          itUN != uInstr->_nxtFuncs.end(); itUN++) {
                    uC->addBody (new HornLiteral (itUN->second, true, true));

                    cRW->update (itUN->first, 
                                 NULL,
                                 itUN->second->getOutVar());
                }

                // Add entry predicate to the body.
                hvptr_t cEntry = copyVar (cVar, -1);
                cEntry->setExec (cRW->rewrite ('I', 0, 'I', -1));
                uC->addBody (new HornLiteral (cEntry));

                // Add exit predicate to the head.
                cVarCopy->setExec (cRW->rewrite ('I', 0, 'O', -1));
                uC->setHead (new HornLiteral (cVarCopy));
            }

            // Create a clause for instruction. 
            // Body ************************************************
            // Child-entry predicate                    -- C(s_0, s)
            // Decode of uInstr                         -- D(s, b)
            // Decode false                             -- (not b)
            // Head ************************************************
            // Instruction predicate                    -- M(s_0, s)

            hcptr_t M = addClause ();

            // Add predicate for child-entry
            hvptr_t cEntry = copyVar (cVar, -1);
            cEntry->setExec (cRW->rewrite ('I', 0, 'I', -1));
            M->addBody (new HornLiteral (cEntry));

            // All decode for u-Instr is false
            for (auto uName : instr->_childInstrs) {
                auto uInstr = _childs.find (uName)->second;
                hvptr_t ud = copyVar (uInstr->_decodeFunc->getOutVar(), -1);
                ud->setExec (ud->getName());
                M->addBody (new HornLiteral (uInstr->_decodeFunc, true, true));
                M->addBody (new HornLiteral (ud, false, false));
            }

            hvptr_t mCopy = copyVar (mVar, -1);
            //mCopy->setExec (mRW->rewrite ('I', 0, 'I', -1));
            mCopy->setExec (mRW->rewrite ('I', 0, 'I', 1));
            M->setHead (new HornLiteral (mCopy));
            mRW->addRewriteRule (M, 'I', -1, 'I', 1);

            if (mRW != NULL) delete mRW;
            if (cRW != NULL) delete cRW;
        }
    }

    HornRewriter* HornTranslator::generateLoopPredicate ()
    {
        // Create and register loop predicate.
        hvptr_t lVar = getVar ("L_" + _name);
        lVar->setLevel (1);
        _db->addRel (lVar);

        HornRewriter* loopRW = new HornRewriter (this, lVar);
        // Collect dependent/updated states. Run on first child-instr.
        for (auto itU = _childs.begin(); itU != _childs.end(); itU++) {
            auto uInstr = itU->second;
            
            lVar->mergeInVars (uInstr->_decodeFunc);
            for (auto itUN  = uInstr->_nxtFuncs.begin();
                      itUN != uInstr->_nxtFuncs.end(); itUN++) {
                auto uNxt = itUN->second;

                lVar->mergeInVars (uNxt);
                lVar->mergeOutVars (uNxt);

                loopRW->configOutput (itUN->first, uNxt->getOutVar());
            }

            loopRW->configInput();
            break;
        }
            
        // Create a clause for each loop step (each child-instr).
        // Body ************************************************
        // Entry loop predicate                     -- L(s_0, s)
        // Decode of uInstr                         -- D(s, b)
        // Decode true                              -- b
        // Next state functions                     -- N(s, n)
        // Head ************************************************
        // Exit loop predicate                      -- L(s_0, n)

        for (auto itU = _childs.begin(); itU != _childs.end(); itU++) {
            std::string uName = itU->first;
            auto uInstr = itU->second;

            // Create and register the clause.
            hvptr_t lVarCopy = copyVar (lVar, -1);
            hcptr_t L = addClause ();

            // Add decode function to the body.
            hvptr_t dOut = copyVar (uInstr->_decodeFunc->getOutVar(), -1);
            dOut->setExec (dOut->getName());
            L->addBody (new HornLiteral (uInstr->_decodeFunc, true, true));
            L->addBody (new HornLiteral (dOut));

            // Update the loop rewriter and add next state functions.
            for (auto itUN  = uInstr->_nxtFuncs.begin();
                      itUN != uInstr->_nxtFuncs.end(); itUN++) {
                L->addBody (new HornLiteral (itUN->second, true, true));

                loopRW->update (itUN->first, 
                                NULL,
                                itUN->second->getOutVar());
            }

            // Add entry loop predicate to the body.
            hvptr_t lEntry = copyVar (lVar, -1);
            lEntry->setExec (loopRW->rewrite ('I', 0, 'I', -1));
            L->addBody (new HornLiteral (lEntry));
            // Add exit loop predicate to the head.
            lVarCopy->setExec (loopRW->rewrite ('I', 0, 'O', -1));
            L->setHead (new HornLiteral (lVarCopy));
        }

        // Create a clause for the loop init point.
        // Head ************************************************
        // Instr predicate                          -- L(s, s)
        if (!_childs.empty()) {
            hcptr_t L = addClause();
            hvptr_t lVarCopy = copyVar (lVar, -1);
            lVarCopy->setExec (loopRW->rewrite ('I', -1, 'I', -1));
            L->setHead (new HornLiteral (lVarCopy));

            return loopRW;
        }

        return NULL;
    }

    void HornTranslator::allInterleaveMapping () 
    {
        HornRewriter* loopRW = generateLoopPredicate ();

        for (auto itN = _instrs.begin(); itN != _instrs.end(); itN++) {
            auto instr = itN->second;

            // Create a clause for the instruction (w/ loop).
            // Body ************************************************
            // Entry loop predicate                     -- L(s_0, s)
            // Decode for instr                         -- D(s, b)
            // Decode true                              -- b
            // Next state functions                     -- N(s, n)
            // Exit loop predicate                      -- L(n, s_1)
            // Head ************************************************
            // Instr predicate                          -- M(s_0, s_1)

            // Create and register the predicate/clause.
            hvptr_t mVar = getVar (instr->_name);
            mVar->setLevel (1);
            _db->addRel (mVar);
            hcptr_t M = addClause ();

            HornRewriter* mRW = new HornRewriter (this, mVar);

            // Add decode to the body.
            hvptr_t dOut = copyVar (instr->_decodeFunc->getOutVar(), -1);
            dOut->setExec (dOut->getName());
            M->addBody (new HornLiteral (dOut));
            M->addBody (new HornLiteral (instr->_decodeFunc, true, true));

            mVar->mergeInVars (instr->_decodeFunc);

            // Update loop rewriter, instr rewriter, and add next functions.
            for (auto itN  = instr->_nxtFuncs.begin(); 
                      itN != instr->_nxtFuncs.end(); itN++) {
                auto nxt = itN->second;
                M->addBody (new HornLiteral (nxt, true, true));

                mVar->mergeInVars (nxt);
                mVar->mergeOutVars (nxt);
                mRW->configOutput (itN->first, nxt->getOutVar());

                mRW->update (itN->first,
                             NULL,
                             itN->second->getOutVar());

                if (loopRW != NULL) {
                    loopRW->update (itN->first,
                                    NULL, 
                                    itN->second->getOutVar());
                }
            }

            mRW->configInput();

            if (loopRW == NULL) {
                hvptr_t mOut = copyVar (mVar, -1);
                mOut->setExec (mRW->rewrite ('I', 0, 'I', 1));
                M->setHead (new HornLiteral (mOut));
                mRW->addRewriteRule (M, 'I', -1, 'I', 0);
                mRW->addRewriteRule (M, 'O', -1, 'I', 1);
            } else {
                /*
                hvptr_t lEntry = loopRW->getRewriteVar ('I', 0, 'I', -1);
                hvptr_t lExit = loopRW->getRewriteVar ('O', -1, 'I', 1);
                M->addBody (new HornLiteral (lEntry));
                M->addBody (new HornLiteral (lExit));
                */
                // A temporary fix for mmio read.
                hvptr_t lEntry = loopRW->getRewriteVar ('I', 0, 'I', -1);
                M->addBody (new HornLiteral (lEntry));
                mRW->addRewriteRule (M, 'O', -1, 'I', 1);

                hvptr_t mOut = mRW->getRewriteVar ('I', 0, 'I', 1);
                M->setHead (new HornLiteral (mOut));
            }

            if (mRW != NULL) delete mRW;
        }
        if (loopRW != NULL) delete loopRW;
    }

}
