
#include <abstraction.hpp>
#include <crossUnroller.hpp>
#include <memoryModel.hpp>
#include <logging.hpp>

//#include <boost/format.hpp>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace ila;


#define toStr(x) ( std::to_string(x) )
#define toTsName(n) ( std::string("n_") + (n) )

// configurations
const bool DEBUG = true;
const bool STRICT_TEMPLATE = true;
const bool ONLY_CONSTRAINT_ON_READABLE_PI = true;
const bool MAKE_ALL_SHARED_STATES = false;
    

std::string stepUniqueName()
{
    static int ctr = 0;
    return std::string("ts")+toStr(ctr++);
}
/*
 bool is_init_event(Step * p)
 {
    if( dynamic_cast<TraceStep *>(p) == NULL )
        return true;
    return false;
}*/

template <class T>
std::string seqToStr(const T &ins) {
    std::string retStr = "[";
    for (auto && e : ins) {
        retStr += std::string(e) + ",";
    }
    return retStr + "]";
}

void Step::initAndCheck()
{
    ILA_ASSERT( !IN_p(name,TsNameToObj) , name + " (step) : has a name conflict!" );
    (*TsNameToObj)[name] = this;

    // check that the local var is a subset of the vars in an abs
}

z3::context mcmUnroller::z3Context;

Step::Step( const std::string &p_entityName, 
            const std::string &p_name, 
            int p_tid, 
            TsThatWritesVars_t *p_TsThatWritesVars, TsNameToObj_t *p_TsNameToObj, 
            statelist_ptr_t p_localStates,  // we don't what to copy this all along
            z3::context &c,
            const z3::expr &p_decodeExpr,
            PiVarList_t *p_PiVarList) :
    entityName(p_entityName),name(p_name),tid(p_tid), 
    localStates(p_localStates), 
    decodeExpr(std::make_shared<z3::expr>( p_decodeExpr) ),
    TsThatWritesVars(p_TsThatWritesVars), TsNameToObj(p_TsNameToObj), 
    PiVarList(p_PiVarList),
    m_pContext(c),
    timestamp( c.int_const(toTsName(p_name).c_str()) )
{
    initAndCheck();
}

Step::Step( const std::string &p_entityName, 
            const std::string &p_name, 
            int p_tid, 
            TsThatWritesVars_t *p_TsThatWritesVars, TsNameToObj_t *p_TsNameToObj, 
            statelist_ptr_t p_localStates,  // we don't what to copy this all along
            z3::context &c,
            const z3::expr &p_decodeExpr,
            z3::expr overwriteTs,
            PiVarList_t *p_PiVarList) :
    entityName(p_entityName),name(p_name),tid(p_tid),  
    localStates(p_localStates), 
    decodeExpr(std::make_shared<z3::expr>( p_decodeExpr) ),
    TsThatWritesVars(p_TsThatWritesVars), TsNameToObj(p_TsNameToObj), 
    PiVarList(p_PiVarList),
    m_pContext(c),
    timestamp( overwriteTs )
{
    initAndCheck();
}

Step::~Step()
{

}

//------------------------------- Init Step ----------------------------------------//

InitStep::InitStep(const std::string &p_entityName, 
                TsThatWritesVars_t *p_TsThatWritesVars, TsNameToObj_t *p_TsNameToObj, 
                statelist_ptr_t p_localStates,  // we don't what to copy this all along
                z3::context &c,
                z3Converter &initAdapter,
                int p_tid,
                Abstraction * p_Abs,
                PiVarList_t *p_PiVarList
                 ) :
    Step(p_entityName,               // abs
        std::string("tid_") + toStr(p_tid) + "_init_" + stepUniqueName(), //name
        p_tid,                // tid
        p_TsThatWritesVars,    // TsThatWritesVars
        p_TsNameToObj,        //TsNameToObj
        p_localStates,        //localStates
        c,                  //z3::context
        c.bool_val(true),   //decodeExpr
        p_PiVarList
        ) , m_pAbs(p_Abs)
{
    init(initAdapter);
}

InitStep::InitStep(const std::string &p_entityName, 
                TsThatWritesVars_t *p_TsThatWritesVars, TsNameToObj_t *p_TsNameToObj, 
                statelist_ptr_t p_localStates,  // we don't what to copy this all along
                z3::context &c,
                z3::expr overwriteTs,
                z3Converter &initAdapter,
                int p_tid,
                Abstraction * p_Abs,
                PiVarList_t *p_PiVarList
                 ) :
    Step(p_entityName,               // abs
        std::string("tid_") + toStr(p_tid) + "_init_" + stepUniqueName(), //name
        p_tid,                // tid
        p_TsThatWritesVars,    // TsThatWritesVars
        p_TsNameToObj,        //TsNameToObj
        p_localStates,        //localStates
        c,                  //z3::context
        c.bool_val(true),   //decodeExpr
        overwriteTs,        //overwriteTs
        p_PiVarList
        ) , m_pAbs(p_Abs)
{
    init(initAdapter);
}

void InitStep::_initVar(z3Converter& z3expr, const std::string &name, const npair_t& p, bool allowInit)
{
    Node* var = p.var.get();
    Node* init = p.init.get();

    // var_  : aes_state_
    if(!allowInit || var->equal(init))
        resultDict.insert( make_pair( name, z3expr.getExpr(var).simplify() ) );
    else
        resultDict.insert( make_pair( name, z3expr.getExpr(init).simplify() ) );
}

void InitStep::init(z3Converter &initAdapter) {
    // set read/write
    // ts that write vars
    // resultDict (init value set)
    ILA_ASSERT(m_pAbs , "You will need a dummy Abs for global init function!");

    for (auto i : m_pAbs->getInps()) {
        //FIXME: input is always treated as local varss
        resultDict.insert( make_pair( i.first , initAdapter.getExpr(i.second.var.get()) ) );
        //resultDict[i.first] = ;
    }
    for (auto &b : m_pAbs->getBits() )  
        if( IN_p(b.first, localStates) ) // if * in *
            _initVar(initAdapter, b.first, b.second, true);
    for (auto &r : m_pAbs->getRegs() )  
        if( IN_p(r.first, localStates) ) // if * in *
            _initVar(initAdapter, r.first, r.second, true);
    for (auto &m : m_pAbs->getMems() ) 
        if( IN_p(m.first, localStates) ) // if * in *
            _initVar(initAdapter, m.first, m.second, true);

    Writes = *localStates; // write to all given "local" states (some of them may not appear to be local)

    for (auto && sname : *localStates) {
        auto pos = TsThatWritesVars->find(sname);
        if( pos == TsThatWritesVars->end() )
            (*TsThatWritesVars)[sname] = stepset_t({this});
        else
            pos->second.insert(this) ;
    }
    // Read empty
}

std::string InitStep::to_string() const
{
    return ( _entity() + ":" + toStr(tid) + ", #INIT#, W:" + seqToStr(Writes) );
}

//-------------------------------- End Step -------------------------------------------//


EndStep::EndStep(const std::string &p_entityName, 
                TsThatWritesVars_t *p_TsThatWritesVars, TsNameToObj_t *p_TsNameToObj, 
                statelist_ptr_t p_localStates,  // we don't what to copy this all along
                z3::context &c,
                z3Converter &p_endAdapter, // should bear ending suffix!
                int p_tid, 
                PiVarList_t *p_PiVarList):
        Step(   p_entityName,               // abs
                std::string("tid_") + toStr(p_tid) + "_end_global", //name
                p_tid,                // tid
                p_TsThatWritesVars,    // TsThatWritesVars
                p_TsNameToObj,        //TsNameToObj
                p_localStates,        //localStates
                c,                  //z3::context
                c.bool_val(true),   //decodeExpr
                p_PiVarList
                ),
        endAdapter(p_endAdapter)
{
    // writes to none
    endAdapter.setNameSuffix(name);
}

EndStep::EndStep(const std::string &p_entityName, 
                TsThatWritesVars_t *p_TsThatWritesVars, TsNameToObj_t *p_TsNameToObj, 
                statelist_ptr_t p_localStates,  // we don't want to copy this all along
                z3::context &c,
                z3::expr overwriteTs,       // overwrite version
                z3Converter &p_endAdapter, // should bear ending suffix!
                int p_tid, 
                PiVarList_t *p_PiVarList ):
        Step(   p_entityName,               // abs
                std::string("tid_") + toStr(p_tid) + "_end_global", //name
                p_tid,                // tid
                p_TsThatWritesVars,    // TsThatWritesVars
                p_TsNameToObj,        //TsNameToObj
                p_localStates,        //localStates
                c,                  //z3::context
                c.bool_val(true),   //decodeExpr
                overwriteTs,        //overwriteTs
                p_PiVarList
                ),
        endAdapter(p_endAdapter)
{
    // writes to none
    //endAdapter.setNameSuffix(name);
}


z3::expr EndStep::getAssertFormula(Node *n)
{
    // the end adapter
    return endAdapter.getExpr(n);
    // todo: you need to check whether this is right!
}

std::string EndStep::to_string() const
{
    return ( _entity() + ":" + toStr(tid) + ", #END#, W:" + seqToStr(Writes) );
}



void EndStep::printTsResultFromModel(z3::model & model)
{
    auto concreteTime = model.eval(timestamp);
    auto decodeCond   = model.eval(*(decodeExpr.get() ) );

    log2("mcmUnroller.print") << "@"<<concreteTime<<", "<<getName() << " : " << decodeCond << std::endl;

    /*
    for ( auto && sname_z3var : defVars ) {
        auto & sname = sname_z3var.first;
        auto & z3var = sname_z3var.second;
        log2("mcmUnroller.print") << "\t " <<  sname << ":" << model.eval(z3var) << std::endl;
    }
    */

    for( auto && piVarIter : *PiVarList ) {
        auto & piVarElem = piVarIter.second;
        auto & sname     = std::get<0>( piVarElem );
        auto & piVar     = std::get<1>( piVarElem );
        auto & ts_pnt    = std::get<2>( piVarElem );

        if ( ts_pnt->getName() == name ) { // okay we know it is from this step
            log2("mcmUnroller.print") << "\t (Read "<< sname <<" = "<< model.eval(piVar)<<" )" << std::endl;
        }
    }

}
//--------------------------- Trace Step !!! ------------------------------------------------------//

// for the first and the very last step, their "local state should be given explicitly"
// this is because they are not the same as any abstraction contains
// but for the tracestep in the middle, that should be determined from p_Abs

TraceStep::TraceStep(Abstraction *p_abs, 
                Instruction * p_Instruction,
                //statelist_ptr_t p_SysSharedState,
                TsThatWritesVars_t *p_TsThatWritesVars, TsNameToObj_t *p_TsNameToObj, 
                //statelist_ptr_t p_localStates,  // we don't what to copy this all along
                constraintList_t *p_ConstraintList,
                PiVarList_t *p_PiVarList,
                z3::context &c,
                int p_tid,
                MemoryModel &p_mm
                // z3::expr * overwriteTs = NULL not allowed?
                 ):
    Step(p_abs->getName(),               // abs
        p_Instruction->getName() + "_" + stepUniqueName() , // name
        p_tid,                // tid
        p_TsThatWritesVars,   // TsThatWritesVars
        p_TsNameToObj,        // TsNameToObj
        p_abs->getPntLocalStates(), // localStates
        c,                    // z3::context
        c.bool_val(true),     // decodeExpr
        p_PiVarList
        ),
    m_pAbs(p_abs),
    m_pConstraintList(p_ConstraintList), 
    m_pInstruction(p_Instruction),
    mm(p_mm),
    z3c(c, name, p_abs->getPntLocalStates(), p_abs->getPntSharedStates() , NULL, p_PiVarList, this) // we need to know the incoming result dict 
{
    //z3c.setNameSuffix(name);

    mm.bookKeepWrite(this, p_TsNameToObj, p_TsThatWritesVars);
    
    /* should be done in the above book keeping 
    for( auto && update : m_pInstruction->updates) {
        writes.insert(update.first);
    }
    */

    for (auto && write : Writes) {
        if ( !IN_p(write, TsThatWritesVars) ) {
            (*TsThatWritesVars)[write] = stepset_t({this});
        }
        else
            (*TsThatWritesVars)[write].insert(this); // self.TsThatWritesVars[write].add(self)
    }

    // TODO : set Write
    // TsThatWritesVars
    // mm.bookKeepWrite(self, self.TsNameToObj, self.TsThatWritesVars) ==> change this.Writes
    //    will initialize wvop if needed
    // based on the Writes, change 
}


void TraceStep::BuildFrame(Step * lastTraceStep)
{
    ILA_ASSERT( lastTraceStep, "Bug: lastTraceStep cannot be null!"  );
    z3c.setIncomingResultDict(& (lastTraceStep->resultDict) );
    ILA_ASSERT(  !z3c.useOld() , "Bug: unable to use the derived z3 translator.");

    
    //incomingResultDict = lastTraceStep.resultDict
    z3::expr decodeExprTmp = z3c.getExpr( m_pInstruction->decodeExpr.get() );
    if(STRICT_TEMPLATE) {
        z3::expr left = *( lastTraceStep->decodeExpr.get() );
        z3::expr right = decodeExprTmp;
        //std::cout<<left<<std::endl;
        //std::cout<<right<<std::endl;
        decodeExpr = std::make_shared<z3::expr>( left && right );
        //std::cout<< (left&&right) <<std::endl;
        //z3::expr t1 = (left&&right);
        //std::cout<< t1 <<std::endl;

    }
    else
        decodeExpr = std::make_shared<z3::expr>( decodeExprTmp );
    
    for (auto && sname_node_pair : m_pInstruction->updates ) {
        std::string sname = sname_node_pair.first;
        Node * n = sname_node_pair.second.get();
        z3::expr definition = z3c.newVar( "def_local_" + this->name + "_" + sname, sname_node_pair.second.get() );
        z3::expr value = z3c.getExpr( n ); // new value

        if (STRICT_TEMPLATE) 
            m_pConstraintList->push_back( definition == value );
        else
            m_pConstraintList->push_back( z3::ite( (*decodeExpr.get()), definition == value , definition == z3c.stateReadFunc(sname, n ) ) );
        
        resultDict.insert( make_pair(sname,definition) );

        mm.regWriteView(sname, definition, this , n );

        defVars.insert( make_pair(sname, definition) );

    }

    for (auto && name_expr_pair : lastTraceStep->resultDict ) {
            if ( IN_p( name_expr_pair.first , localStates ) ) { // only handle local states
                resultDict.insert( name_expr_pair ); // std::map will not overwrite
            } 
        }

    mm.createWriteView(this, this->TsNameToObj, this->TsThatWritesVars, this->m_pConstraintList);


    // initialize the z3c

    // local -> prev name
    // global -> the pi things
    // we will need the subs function
}



void TraceStep::printTsResultFromModel(z3::model & model)
{
    auto concreteTime = model.eval(timestamp);
    auto decodeCond   = model.eval(*(decodeExpr.get() ) );

    log2("mcmUnroller.print") << "@"<<concreteTime<<", "<<getName() << " : " << decodeCond << std::endl;

    for ( auto && sname_z3var : defVars ) {
        auto & sname = sname_z3var.first;
        auto & z3var = sname_z3var.second;
        log2("mcmUnroller.print") << "\t " <<  sname << ":" << model.eval(z3var) << std::endl;
    }

    for( auto && piVarIter : *PiVarList ) {
        auto & piVarElem = piVarIter.second;
        auto & sname     = std::get<0>( piVarElem );
        auto & piVar     = std::get<1>( piVarElem );
        auto & ts_pnt    = std::get<2>( piVarElem );

        if ( ts_pnt->name == name ) { // okay we know it is from this step
            log2("mcmUnroller.print") << "\t (Read "<< sname <<" = "<< model.eval(piVar)<<" )" << std::endl;
        }
    }

}

z3::expr TraceStep::getAssertFormula(Node *n)
{
    ILA_ASSERT( !z3c.useOld() , "build frame must be called first" );
    // we will need to use z3c!
    return z3c.getExpr(n);
}

std::string TraceStep::to_string() const
{
    return ( _entity() + ":" + toStr(tid) + "inst:" + m_pInstruction->getName() + ", W:" + seqToStr(Writes) );
}


//---------------------------- Unroller !!! -------------------------------------------//

// init adapter  suffix: init check false / default return
// end  adapter  suffix: end
// frame adapter 
// but you need to know their names right?



void mcmUnroller:: findSharedStates(void)
{


    SysSharedStates.clear();
    // first let's ask each Abs to caculate their states (all will be treated as local)
    m_pDummyGlobalAbs->assignLocalSharedStates();

    for( auto && pAbs : entities) 
        pAbs->assignLocalSharedStates(); // all NULL
    // second we caculate the intersection of these sets to find the shared states
    for(auto pos1 = entities.begin(); pos1 != entities.end(); ++ pos1) {
        
        std::copy((*pos1)->getPntLocalStates()->begin() , (*pos1)->getPntLocalStates()->end() , std::inserter(allStates,allStates.begin()) );

        if(MAKE_ALL_SHARED_STATES) {
            std::copy((*pos1)->getPntLocalStates()->begin() , (*pos1)->getPntLocalStates()->end() , std::inserter(SysSharedStates,SysSharedStates.begin()) );
        }
        else {
            for(auto pos2 = entities.begin(); pos2 != entities.end(); ++ pos2) {
                if(pos1 == pos2) continue; // skip the same
                INTERSECT( *((*pos1)->getPntLocalStates()) , *((*pos2)->getPntLocalStates()) , SysSharedStates );
            }
        }
    }
    // Finally recaculate each Abs's local and shared states
    for( auto && pAbs : entities) 
        pAbs->assignLocalSharedStates(NULL, &SysSharedStates );

    // make sure all the shared states are initalized in the dummy ILA
    statelist_t missingGlobalStates;
    std::set_difference( SysSharedStates.begin(), SysSharedStates.end() , 
        m_pDummyGlobalAbs->getPntLocalStates()->begin(), m_pDummyGlobalAbs->getPntLocalStates()->end(),
        std::inserter( missingGlobalStates, missingGlobalStates.begin() ) );
    for(auto && stateName : missingGlobalStates ) {
        ILA_ASSERT(false, "state:"+stateName+" should be define in dummy ILA:"+m_pDummyGlobalAbs->getName() );
    }
}

void mcmUnroller::checkILANames(void) 
{
    ILA_ASSERT( noThread.size() == numOfEntity 
        && numOfEntity == templateProgram.size() ,
        "#thread, #entities, SIZE(templateProgram) must match!" );
    for(auto pos1 = entities.begin(); pos1 != entities.end() ; ++ pos1 ) {
        ILA_ASSERT( (*pos1)-> getName() != m_pDummyGlobalAbs->getName() , "Dummy ILA name should be distinct!" );
        for(auto pos2 = entities.begin(); pos2 != entities.end() ; ++ pos2 ) {
            if( pos1 == pos2 ) continue;
            ILA_ASSERT( (*pos1)-> getName() != (*pos2)->getName() , "ILA names should be distinct!" );
        }
    }
}

mcmUnroller::mcmUnroller(
    const noThread_t &p_noThread, 
    const entity_t  &p_entities, 
    const templateProgram_t & p_templateProgram,
    Abstraction * p_DummyGlobalAbs,
    MemoryModel &p_MM
    ) : 
    numOfEntity(p_entities.size()), 
    noThread(p_noThread) , entities( p_entities ) , 
    templateProgram (p_templateProgram), m_pDummyGlobalAbs(p_DummyGlobalAbs),
    globalBeginEvent(NULL),globalEndEvent(NULL),runTProp(NULL),
    slv(z3Context),
    initAdapter(z3Context,"init"),
    endAdapter(z3Context,"end_global", &noStates, &allStates , NULL , &PiVarList, NULL ),
    m_pMM(p_MM),
    p_model(NULL)
    {
        // find the shared states
        checkILANames();
        findSharedStates();
    }

mcmUnroller::~mcmUnroller()
{
    if(globalBeginEvent)
        delete globalBeginEvent;
    if(globalEndEvent)
        delete globalEndEvent;
    if(p_model)
        delete p_model;
    if(runTProp)
        delete runTProp;
}

void mcmUnroller::unroll()
{
    int tsCnt = 0; // number of trace steps
    int tid = 0;

/*
const std::string &p_entityName, 
                TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
                statelist_ptr_t localStates,  // we don't what to copy this all along
                z3::context &c,
                z3Converter &initAdapter,
                int tid, 
                Abstraction * p_Abs,
                PiVarList_t *PiVarList = NULL
*/

    globalBeginEvent = new InitStep( 
        "Global_" + m_pDummyGlobalAbs->getName() ,  // p_entityName
        &TsThatWritesVars,                          // TsThatWritesVars_t *TsThatWritesVars,
        &TsNameToObj,                               // TsNameToObj_t *TsNameToObj, 
        m_pDummyGlobalAbs->getPntLocalStates(),     // statelist_ptr_t localStates,
        z3Context,                                  // z3::context &c,
        z3Context.int_val(0),                               // z3::expr overwriteTs,
        initAdapter,                                // z3Converter &initAdapter,
        0,                                          // tid
        m_pDummyGlobalAbs                           // Abstraction * p_Abs,
        // PiVarList_t *PiVarList = NULL
         );

    globalEndEvent = new EndStep (
        "Global_" + m_pDummyGlobalAbs->getName(),   // p_entityName
        &TsThatWritesVars,                          // TsThatWritesVars_t *TsThatWritesVars,
        &TsNameToObj,                               // TsNameToObj_t *TsNameToObj, 
        m_pDummyGlobalAbs->getPntLocalStates(),     // statelist_ptr_t localStates,
        z3Context,                                  // z3::context &c,
        endAdapter,                                 // z3Converter &endAdapter,
        0,                                          // tid
        &PiVarList                                  // 
    );
    endAdapter.resetStepPointer(globalEndEvent);
    endAdapter.setIncomingResultDict(&emptyDict);
    ILA_ASSERT(!endAdapter.useOld() , "Cannot turn on new z3 adapter feature!");
    // self.TsNameToRelLookup[globalEndEvent.name] = "<rel_should_never_refer_to>"

    // Step 1 : create the events
    for (unsigned Eidx  = 0; Eidx < numOfEntity; ++ Eidx) {
        int nTh = noThread[Eidx];
        for (int noRound = 0; noRound < nTh ; ++noRound) {
            TsPOList.push_back(tsList_t()); // self.TsPOList.append([])
            tsList_t &tsL = TsPOList.back();
            auto pEntity = entities[Eidx];
            tid ++;

            tsL.push_back( std::make_shared<InitStep>(
                pEntity->getName(),                         // p_entityName (ILA name)
                &TsThatWritesVars,                          // TsThatWritesVars_t *TsThatWritesVars,
                &TsNameToObj,                               // TsNameToObj_t *TsNameToObj, 
                pEntity->getPntLocalStates(),               // statelist_ptr_t localStates,
                z3Context,                                  // z3::context &c,
                z3Context.int_val(0),                       // z3::expr overwriteTs,
                initAdapter,                                // z3Converter &initAdapter,
                0,                                          // int tid
                entities[Eidx]                              // Abstraction * p_Abs,
                ) );
            tsCnt ++;

            for (auto && instName : templateProgram[Eidx]) {
                ILA_ASSERT( IN(instName, pEntity->insts ) , "instruction : " + instName + " is not defined in abs:" + pEntity->getName() );

                tsL.push_back( std::make_shared<TraceStep>(
                    pEntity,                            // Abstraction *p_Abs, 
                    (pEntity->insts[instName]).get(),   // Instruction *pInstruction,
                    &TsThatWritesVars, &TsNameToObj,     // TsThatWritesVars_t *TsThatWritesVars, TsNameToObj_t *TsNameToObj, 
                    &ConstraintList,                    // constraintList_t *ConstraintList,
                    &PiVarList,                         // PiVarList_t *PiVarList,
                    z3Context,                          // z3::context &c,
                    tid,                                // int tid,
                    m_pMM                               // MemoryModel &p_mm
                    ) );

                tsCnt ++;

                /*
                    relTsLookupKey = (self.entityNameList[Eidx], inst.name, noRound+1 ) 
                    self.relTsLookupDict[relTsLookupKey] = ts
                    self.TsNameToRelLookup[ts.name] = relTsLookupKey
                */

            }

        }
    }
    // Step 2 : Add global ordering
    for ( auto && program : TsPOList) {
        auto tsBegin = program[1];
        auto tsEnd   = program.back();
        ConstraintList.push_back( tsBegin->timestamp > globalBeginEvent->timestamp );
        ConstraintList.push_back( tsEnd  ->timestamp < globalEndEvent  ->timestamp );
        // only constrain on the beginning and end, no need for others
    }

    // Step 3 : Add thread local PO HB
    for ( auto && program : TsPOList) {
        for( unsigned tsIdx = 0; tsIdx < program.size() -1 ; ++ tsIdx ) {
            ConstraintList.push_back( program[tsIdx]->timestamp < program[tsIdx + 1]->timestamp );
        }
    }

    // Step 4 : Each Ts do its own variable def
    for ( auto && program : TsPOList) {
        for( unsigned tsIdx = 1; tsIdx < program.size() ; ++ tsIdx ) {
            TraceStep  * ts = dynamic_cast<TraceStep *>(program[tsIdx].get());
            ILA_ASSERT(ts != NULL, "BUG: expect trace step, dynamic_cast failed.");
            ts->BuildFrame( program[tsIdx-1].get() );
        }
    }

    // Step 5 : ask MM if there is anything else to do
    m_pMM.addPORelatedHB( &ConstraintList, &TsPOList );

}

static z3::expr z3Or(constraintList_t & orList) {
    if( orList.size() == 1)
        return orList.front();
    bool begin = true;
    z3::expr ret = orList.front();
    for( auto && e : orList)
    {
        if(begin) {
            begin = false;
            continue;
        }
        ret = ret || e;
    }
    return ret;
}

static z3::expr z3And(constraintList_t & andList) {
    if( andList.size() == 1)
        return andList.front();
    bool begin = true;
    z3::expr ret = andList.front();
    for( auto && e : andList)
    {
        if(begin) {
            begin = false;
            continue;
        }
        ret = ret && e;
    }
    return ret;
}

void mcmUnroller::finalizePiFun(std::map<relId_t,relId_t> * rf_force)
{
    ILA_ASSERT(rf_force == NULL, "Bug: rf edge forcing is not implemented.");

    if( DEBUG )
        m_pMM.DEBUG_printPossibleReadFrom(&PiVarList, &TsThatWritesVars);
    for( auto && piVarIter : PiVarList ) {
        auto & piVarElem = piVarIter.second;
        auto & sname     = std::get<0>( piVarElem );
        auto & piVar     = std::get<1>( piVarElem );
        auto & ts_pnt    = std::get<2>( piVarElem );

        //auto & timestamp = ts_pnt->timestamp;
        stepset_t & writerTraceSteps = TsThatWritesVars[sname]; // it must be there
        // set of Step *
        
        constraintList_t orClauses;
        //read_relId_tuple = self.TsNameToRelLookup[ts.name]
        // not supported
        for (auto && write : writerTraceSteps) {
            ILA_ASSERT( EQ_b( write == ts_pnt, ts_pnt->name == write->name ),
                "Implementation bug, expected: pointer EQ <=> name EQ");
            if(write == ts_pnt) // if the pointer points to the same
                continue;
            auto constraint = m_pMM.build_rf_constraint( sname, piVar, &TsThatWritesVars, ts_pnt, write  );
            if(ONLY_CONSTRAINT_ON_READABLE_PI)
                constraint = z3::implies( (const z3::expr &) *(ts_pnt->decodeExpr.get()), (const z3::expr &) constraint );
            orClauses.push_back(constraint);
        }

        if(orClauses.size() == 0) 
            ILA_ASSERT(false,"No writer for state: " + sname + ". It should at least appear in the init steps.");
        if(orClauses.size() == 1)
            ConstraintList.push_back( orClauses.front() );
        else
            ConstraintList.push_back( z3Or(orClauses) );
    }   // end for each piVar

}   // end of function


void mcmUnroller::addPropertyOnSingleFrames( Node * runProperty, ts2bool_t frameCond ) {
    for (auto && program : TsPOList) {
        for (auto && ts: program ) {
            TraceStep * ts_pnt = dynamic_cast<TraceStep *>( ts.get() ); // try to cast to a subclass
            if( ts_pnt )
                if( frameCond(ts_pnt) )
                    runConstraintList.push_back( ts_pnt->getAssertFormula(runProperty) );
        }
    }
}

void mcmUnroller::addPropertyOnEnding( Node * runProperty ) {

    ILA_ASSERT(globalBeginEvent , "Please first unroll & finalizePiFun.");
    runConstraintList.push_back( globalEndEvent->getAssertFormula(runProperty) );
}

void mcmUnroller::buildAndRunProp() {
    runTProp = new z3::expr( z3And(runConstraintList) );
}
void mcmUnroller::buildOrRunProp() {
    runTProp = new z3::expr( z3Or (runConstraintList) );
}
bool mcmUnroller::pushInstConstraintAndCheck() {
    slv.reset(); // clear all

    int idx = 0;
    for ( auto && c : ConstraintList) {
        if (DEBUG) 
            log2("mcmUnroller.icheck") << idx <<" : "<< c << std::endl;
        slv.add( c, ("n"+toStr(idx)).c_str() );
        idx ++;
    }
    auto result = slv.check();
    log2("mcmUnroller.icheck")<<"w.o. run Property:" << result << std::endl;
    if (result == z3::sat) {
        if (p_model) delete p_model;
        p_model = new z3::model( slv.get_model() );
        return true;
    }
    else{
        if(DEBUG){
            z3::expr_vector core = slv.unsat_core();
            log2("mcmUnroller.icheck") << "BEGIN Unsat Core:" << std::endl;
            for (unsigned i = 0; i < core.size(); i++) 
                log2("mcmUnroller.icheck") << core[i] << "\n";
            log2("mcmUnroller.icheck") << "--------END------------"<< std::endl;
        }
        return false;
    }

}
bool mcmUnroller::check() { // true sat/ false unsat
    // we are not going to check if the model is consistent or not
    // python's responsibility
    ILA_ASSERT( runConstraintList.size() != 0 , "No run property specified!");
    ILA_ASSERT( runTProp !=  NULL, "Need to run build runProp first.");

    slv.add(*runTProp, "rp");
    if(DEBUG)
        log2("mcmUnroller.check") << "rp : "<< *runTProp << std::endl;

    auto result = slv.check();

    if (result == z3::sat) {
        if (p_model) delete p_model;
        p_model = new z3::model( slv.get_model() );
        return true;
    }
    else{
        if(DEBUG){
            z3::expr_vector core = slv.unsat_core();
            log2("mcmUnroller.check") << "BEGIN Unsat Core:" << std::endl;
            for (unsigned i = 0; i < core.size(); i++) 
                log2("mcmUnroller.check") << core[i] << "\n";
            log2("mcmUnroller.check") << "--------END------------"<< std::endl;
        }
        return false;
    }
}


void mcmUnroller::printModel(void)
{
    if(!p_model) {
        log2("mcmUnroller.print") << "No model available!" << std::endl;
        return;
    }

    for( auto && program : TsPOList ) {
        log2("mcmUnroller.print") << program[1]->_entity() << "#" << program[1]->tid << std::endl;
        for( auto && ts: program ) {
            TraceStep * ts_pnt = dynamic_cast<TraceStep *> ( ts.get() );
            if(ts_pnt == NULL) continue;
            ts_pnt->printTsResultFromModel(*p_model);
            m_pMM.DEBUG_extractViewResultForTs(ts_pnt, *p_model);
        }
    }
    log2("mcmUnroller.print")<<"-- END  STEP --" <<std::endl;

    globalEndEvent->printTsResultFromModel(*p_model);

    log2("mcmUnroller.print")<<"-- ---  ---- --" <<std::endl;

}


//---------------------------- z3Converter !!! -------------------------------------------//

z3::expr z3Converter::getBoolVarExpr(const BoolVar* boolvar)
{
    if (useOld())
        return Z3ExprAdapter::getBoolVarExpr(boolvar);
    else {
        std::string stateName = boolvar->getName();
        return stateReadFunc(stateName , boolvar);
    }        
}

z3::expr z3Converter::getBitvectorVarExpr(const BitvectorVar* bvvar)
{
    if (useOld())
        return Z3ExprAdapter::getBitvectorVarExpr(bvvar);
    else {
        std::string stateName = bvvar->getName();
        return stateReadFunc(stateName, bvvar);
    }      
}

z3::expr z3Converter::getMemVarExpr(const MemVar* memvar)
{
    if (useOld())
        return Z3ExprAdapter::getMemVarExpr(memvar);
    else {
        std::string stateName = memvar->getName();
        return stateReadFunc(stateName, memvar);
    }   
}


z3::expr z3Converter::stateReadFunc( const std::string & stateName, const Node * type )
{
    if( IN_p(stateName, m_pLocalStates) ) {
            ILA_ASSERT( IN_p(stateName, m_pIncomingResultDict ) , (std::string("local state:")+stateName+" not in incoming result dict.").c_str() );
            auto pos = m_pIncomingResultDict->find(stateName);
            return pos->second;//(*m_pIncomingResultDict)[stateName];
        }
        std::string piVarName = "pi_" + suffix + "_" + stateName; // here is the name for pi vars
        if ( !IN_p( piVarName, m_pPiVarList ) ) {
            z3::expr piVar = newVar(piVarName, type);
            (*m_pPiVarList).insert( make_pair( piVarName, make_tuple(stateName, piVar, m_pStep) ) );
            return piVar;
        }
        else {
            auto pos = m_pPiVarList->find(piVarName);
            ILA_ASSERT(pos != m_pPiVarList->end() , "BUG: "+piVarName+" should exist in PiVarList.");
            return std::get<1>( pos->second );
        }
}

z3::expr z3Converter::newVar( const std::string & name, const Node * type) const
{
    if( type->type.isBool() ) {
         return c.bool_const( name.c_str() );
    }
    else if (type->type.isBitvector() ) {
        return c.bv_const( name.c_str() , type->type.bitWidth );
    }
    else if (type->type.isMem() ) {
        auto addrsort = c.bv_sort(type->type.addrWidth);
        auto datasort = c.bv_sort(type->type.dataWidth);
        auto memsort = c.array_sort(addrsort, datasort);
        return c.constant( name.c_str() , memsort );
    }
    else
        ILA_ASSERT(false, "cannot replicate a type that is not Bool/BV/Mem");
    // I want to get rid of the warning
    exit(1);
    // should never reach
}




//---------------------------- PYTHON Interface !!! -------------------------------------------//


mcmUnroller * mcmUnroller::py_NewMCMUnroller(const py::list & nTh,
    const py::list & entity, const py::list & program, AbstractionWrapper * dummyInit, MemoryModel * p_mm)
{
    noThread_t noThread;
    entity_t   entities;
    templateProgram_t templateProgram;

    boost::python::ssize_t len = boost::python::len( nTh );
    for( boost::python::ssize_t i=0;i<len;i++ ) {
        boost::python::object elem = nTh[i];
        boost::python::extract<unsigned> getItem(elem);

        if( !getItem.check() )
            throw PyILAException( PyExc_TypeError, "nTh must be unsigned integer"  );

        noThread.push_back( getItem() );
    }


    len = boost::python::len( entity );
    for( boost::python::ssize_t i=0;i<len;i++ ) {
        boost::python::object elem = entity[i];
        boost::python::extract<AbstractionWrapper *> getItem(elem);

        if( !getItem.check() )
            throw PyILAException( PyExc_TypeError, "entity must be an abstraction"  );

        entities.push_back( getItem()->abs.get() );
    }

    len = boost::python::len( program );
    for( boost::python::ssize_t i=0;i<len;i++ ) {
        boost::python::object elem = program[i];

        templateProgram.push_back( single_thread_program_t() );
        single_thread_program_t & cur = templateProgram.back();

        boost::python::extract<boost::python::list> getItem(elem);

        if( !getItem.check() )
            throw PyILAException( PyExc_TypeError, "Each thread program should be a list"  );

        boost::python::list thread_program = getItem();

        boost::python::ssize_t len_sub = boost::python::len( thread_program );
        for ( boost::python::ssize_t j = 0 ; j < len_sub; j ++ ) {
            boost::python::object inst_name_elem = thread_program[j];
            boost::python::extract<std::string> getInstName(inst_name_elem);
            if( !getInstName.check() )
                throw PyILAException( PyExc_TypeError, "Each thread inst should be a string"  );
            cur.push_back( getInstName() );
        }

    }

    return new mcmUnroller(noThread, entities, templateProgram, dummyInit->abs.get(), *p_mm );
}

void mcmUnroller::py_addPropertyOnEnding( NodeRef * n )
{
    addPropertyOnEnding(n->node.get());
}