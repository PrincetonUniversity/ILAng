
#include <abstraction.hpp>
#include <crossUnroller.hpp>
#include <memoryModel.hpp>
#include <logging.hpp>

using namespace ila;

 bool is_init_event(Step * p)
 {
    if( dynamic_cast<TraceStep *>(p) == NULL )
        return true;
    return false;
}

 void SC::bookKeepWrite( TraceStep * ts , TsNameToObj_t * p_TsNameToObj, TsThatWritesVars_t * p_TsThatWritesVars )
 {
    for (auto && sname_node : ts->m_pInstruction->updates) {
        ts->Writes.insert(sname_node.first);
    }
 }
 void SC::regWriteView ( const std::string & sname, z3::expr & z3def, TraceStep * ts, Node * type ) { } // Do Nothing
 void SC::createWriteView( TraceStep * ts, TsNameToObj_t * p_TsNameToObj , 
    TsThatWritesVars_t * p_TsThatWritesVars,  constraintList_t *ConstraintList ) { } // Do Nothing

 void SC::addPORelatedHB(constraintList_t *ConstraintList ,tsPOList_t *TsPOList) { } // Do Nothing


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

 void SC::make_thread_local_fence( TraceStep * fence_ts, tsPOList_t *TsPOList, constraintList_t *ConstraintList)
 {
    // Not supported (no fences in SC)
 }

 z3::expr SC::co_hb(Step * w1, Step * w2) { return ( w1->timestamp < w2->timestamp ) ; }
 z3::expr SC::fr_hb(Step * r,  Step * w ) { return ( r->timestamp < w->timestamp ) ; }
 z3::expr SC::build_rf_constraint(std::string & sname, z3::expr & piVar, TsThatWritesVars_t * p_TsThatWritesVars,
            Step * read, Step * write )
 {
    stepset_t & writerTraceSteps = (*p_TsThatWritesVars)[sname];
    constraintList_t CO_FR_HB;

    for (auto && w2 : writerTraceSteps) {
        if(w2 == read || w2 == write)
            continue;
        CO_FR_HB.push_back( co_hb(w2,write) ||  fr_hb(read,w2) );
    }
    /*
    z3::expr co_fr_hb;
    if(CO_FR_HB.size() == 0) 
        co_fr_hb = read->m_pContext.bool_val(true);
    else if( CO_FR_HB.size() == 1)
        co_fr_hb = CO_FR_HB[0];
    else
        co_fr_hb = z3And( CO_FR_HB );*/

    z3::expr co_fr_hb ( CO_FR_HB.size() == 0 ? read->m_pContext.bool_val(true) :
                        z3And( CO_FR_HB )  );

    auto pos = write->resultDict.find(sname);
    ILA_ASSERT(pos != write->resultDict.end() , "Definition: " + sname + " should exist in ts:" + write->getName() );

    //std::cout<<co_fr_hb<<std::endl;
    return (    ( piVar == pos->second ) && 
                ( *( write->decodeExpr.get() ) ) && 
                ( write->timestamp < read->timestamp ) &&
                co_fr_hb  );
 }


 void SC::DEBUG_printPossibleReadFrom(PiVarList_t * PiVarList, TsThatWritesVars_t * p_TsThatWritesVars)
 {
    for( auto && piVarIter : *PiVarList ) {
        auto & piVarElem = piVarIter.second;
        auto & sname     = std::get<0>( piVarElem );
        auto & piVar     = std::get<1>( piVarElem );
        auto & ts_pnt    = std::get<2>( piVarElem );


        log2("memoryModel.print") << "PI: " << piVar << " of state: " << sname << " on ts: "<<std::endl;
        log2("memoryModel.print") << ( ts_pnt->to_string() )   << std::endl;
        log2("memoryModel.print") << "possible read-from:" << std::endl;
        stepset_t & writerTraceSteps = (*p_TsThatWritesVars)[sname];

        for( auto && traceStep : writerTraceSteps) {
            if(traceStep == ts_pnt)
                continue; // not read from its own
            log2("memoryModel.print") << '\t' << ( ts_pnt->to_string() ) << std::endl;
        }

    }
 }
 void SC::DEBUG_extractViewResultForTs(TraceStep * ts, z3::model & model)
 {
    // TODO: No need for sc
 }


//--------------------------- TSO ------------------------------------------------------//


 void TSO::bookKeepWrite( TraceStep * ts , TsNameToObj_t * p_TsNameToObj, TsThatWritesVars_t * p_TsThatWritesVars )
 {
    for (auto && sname_node : ts->m_pInstruction->updates) {
        ts->Writes.insert(sname_node.first);
    }
 }

// it will call per instruction per state
 void TSO::regWriteView ( const std::string & sname, z3::expr & z3def, TraceStep * ts , Node * type)
 {
    if( !IN_p(sname, ts->localStates ) ) {
        tsDefsGroup.push_back( make_tuple(sname, z3def, type) );
    }
 }

 // it will be called per instruction, time to reset 
 void TSO::createWriteView( TraceStep * ts, TsNameToObj_t * p_TsNameToObj , 
    TsThatWritesVars_t * p_TsThatWritesVars,  constraintList_t *ConstraintList )
 {
    if( tsDefsGroup.size() > 1 ) {
        info("memoryModel") << "Warning: assuming single-copy atomic TSO for ts:"<< (ts->getName())<<std::endl;
        info("memoryModel") << "Warning:     on stateVars:" ;
        for( auto && x : tsDefsGroup) 
            info("memoryModel") << std::get<0>(x) << ' ';
        info("memoryModel") << std::endl;
    }
    else if ( tsDefsGroup.size() == 0 ) {
        ts->m_wvopList.clear();
        tsDefsGroup.clear(); // no need actually
        return; // no wvop needed
    }

    // assuming it is on tid = 0
    ILA_ASSERT( IN_p("tid_0_end_global", p_TsNameToObj) , "Error: end ts: tid_0_end_global not found by createWriteView." );
    Step * endStep = (*p_TsNameToObj)["tid_0_end_global"];

    std::shared_ptr<wvop> ptr_wvop = std::make_shared<wvop>( *ts, tsDefsGroup, p_TsThatWritesVars, ConstraintList, endStep );
    std::shared_ptr<Step> wvop_ext = ptr_wvop;

    //std::shared_ptr<Step> wvop_ext = (Step *) new wvop ( *ts, tsDefsGroup, p_TsThatWritesVars, ConstraintList, endStep );
    ts->m_wvopList.push_back(wvop_ext);

    tsDefsGroup.clear();    
 }


 void TSO::addPORelatedHB(constraintList_t *ConstraintList ,tsPOList_t *TsPOList)
 {
    // This is TSO HB PO(W1,W2) => HB(WVOP1, WVOP2)
    for(unsigned tid1 = 0; tid1 < TsPOList->size(); tid1 ++ ) {
        for(unsigned tid2 = 0; tid2 < TsPOList->size(); tid2 ++ ) {
            if( tid1 == tid2 ) continue;
            if( (*TsPOList)[tid1][0]->_entity() != (*TsPOList)[tid2][0]->_entity() ) continue;
            for( auto && ts1 : (*TsPOList)[tid1] ) {
                TraceStep * ts1_pnt = dynamic_cast<TraceStep *>( ts1.get() );
                if( ts1_pnt == NULL ) continue;
                if( ts1_pnt->m_wvopList.size() == 0 ) continue;
                for( auto && ts2: (*TsPOList)[tid2] ) {
                    TraceStep * ts2_pnt = dynamic_cast<TraceStep *>( ts2.get() );
                    if( ts2_pnt == NULL ) continue;
                    if( ts2_pnt->m_wvopList.size() == 0 ) continue;
                    ConstraintList->push_back(
                        z3::implies( 
                            ts1_pnt->timestamp < ts2_pnt->timestamp , 
                            ts1_pnt->m_wvopList[0]->timestamp < ts2_pnt->m_wvopList[0]->timestamp )
                        );
                }
            }
        }
    }
    for ( auto && program : *TsPOList) {
        z3::expr * prevWVopStamp = NULL;
        for( auto && ts : program ) {
            TraceStep * ts_pnt = dynamic_cast<TraceStep *>( ts.get() );
            if( ts_pnt == NULL ) continue;
            if( ts_pnt->m_wvopList.size() == 0 ) continue;
            ILA_ASSERT( ts_pnt->m_wvopList.size() == 1, "Bug: more than one global wvop!" );
            ConstraintList->push_back(
                ts_pnt->timestamp < ts_pnt->m_wvopList[0]->timestamp
                ); // HB(write, write gloabl)

            if (prevWVopStamp) 
                ConstraintList->push_back(
                    *prevWVopStamp < ts_pnt->m_wvopList[0]->timestamp
                    ); // HB(to previous PO write)

            prevWVopStamp = &(ts_pnt->timestamp);
        }
    }
 }

 void TSO::make_thread_local_fence( TraceStep * fence_ts, tsPOList_t *TsPOList, constraintList_t *ConstraintList)
 {
    ILA_ASSERT(false, "Not implemented.");
 }

TraceStep * TSO::convert_to_ts(Step * w)
{
    TraceStep * ts = dynamic_cast<TraceStep *> (w);
    ILA_ASSERT(ts, "Cannot cast Step to TraceStep.");
    return ts;
}

 z3::expr TSO::co_hb(Step * w1, Step * w2) 
 {  
    if(w1->_entity() == w2->_entity() || is_init_event(w1) )
        return w1->timestamp < w2->timestamp;
    // else
    if( is_init_event(w2) )
        return w1->m_pContext.bool_val(false);
    // else
    z3::expr *left;
    z3::expr *right;
    if( convert_to_ts(w1)->m_wvopList.size() == 0 ) {
        log1("memoryModel.TSO")<<"COE: w.o. views "<< w1->getName() <<"* -> "<<w2->getName()<<std::endl;
        left = & ( convert_to_ts(w1)->timestamp );
    }
    else
        left = & ( convert_to_ts(w1)->m_wvopList[0]->timestamp );

    if(  convert_to_ts(w2)->m_wvopList.size() == 0 ){
        log1("memoryModel.TSO")<<"COE: w.o. views "<< w1->getName() <<" -> *"<<w2->getName()<<std::endl;
        right = & ( convert_to_ts(w2)->timestamp );
    }
    else
        right = & ( convert_to_ts(w2)->m_wvopList[0]->timestamp );
    return  (*left) < (*right) ;
 }

 z3::expr TSO::fr_hb(Step * r,  Step * w ) 
 {  
    if( r->_entity() == w->_entity() )
        return r->timestamp < w->timestamp;
    //else
    if( is_init_event(w) )
        return w->m_pContext.bool_val(false);
    //else
    z3::expr *right;
    if(  convert_to_ts(w)->m_wvopList.size() == 0 ){
        log1("memoryModel.TSO")<<"FRE: w.o. views "<< r->getName() <<" -> *"<<w->getName()<<std::endl;
        right = & ( convert_to_ts(w)->timestamp );
    }
    else
        right = & ( convert_to_ts(w)->m_wvopList[0]->timestamp );
    return r->timestamp < *right;
 }

 z3::expr TSO::build_rf_constraint(std::string & sname, z3::expr & piVar, TsThatWritesVars_t * p_TsThatWritesVars,
            Step * read, Step * write )
 {
    stepset_t & writerTraceSteps = (*p_TsThatWritesVars)[sname];
    constraintList_t CO_FR_HB;

    for (auto && w2 : writerTraceSteps) {
        if(w2 == read || w2 == write) // pointer comparison
            continue;
        CO_FR_HB.push_back( co_hb(w2,write) ||  fr_hb(read,w2) );
    }

    /*
    z3::expr co_fr_hb;
    if(CO_FR_HB.size() == 0) 
        co_fr_hb = read->m_pContext.bool_val(true);
    else if( CO_FR_HB.size() == 1)
        co_fr_hb = CO_FR_HB[0];
    else
        co_fr_hb = z3And(CO_FR_HB);
    */
    z3::expr co_fr_hb = CO_FR_HB.size() == 0 ? read->m_pContext.bool_val(true) : z3And(CO_FR_HB) ;

    Step * w;
    if( is_init_event(write) || write->_entity() == read->_entity() ) // either read from initstep or read from the same entity
        w = write;
    else if(convert_to_ts( write ) ->m_wvopList.size() == 0) {
        w = write;
        log1("memoryModel.TSO")<<"RFE: w.o. views "<< w->getName() <<" -> *"<<read->getName()<<std::endl;
    }
    else
        w = convert_to_ts( write ) ->m_wvopList[0].get();

    auto pos = write->resultDict.find(sname);
    ILA_ASSERT(pos != write->resultDict.end() , "Definition: " + sname + " should exist in ts:" + write->getName() );

    return (    ( piVar == pos->second ) && 
                ( *( w->decodeExpr.get())  ) && 
                ( w->timestamp < read->timestamp ) &&
                co_fr_hb  );
 }

 void TSO::DEBUG_printPossibleReadFrom(PiVarList_t * PiVarList, TsThatWritesVars_t * p_TsThatWritesVars)
 {
    for( auto && piVarIter : *PiVarList ) {
        auto & piVarElem = piVarIter.second;
        auto & sname     = std::get<0>( piVarElem );
        auto & piVar     = std::get<1>( piVarElem );
        auto & ts_pnt    = std::get<2>( piVarElem );


        log2("memoryModel.print") << "PI: " << piVar << " of state: " << sname << " on ts: "<<std::endl;
        log2("memoryModel.print") << ( ts_pnt->to_string() )   << std::endl;
        log2("memoryModel.print") << "possible read-from:" << std::endl;
        stepset_t & writerTraceSteps = (*p_TsThatWritesVars)[sname];

        for( auto && traceStep : writerTraceSteps) {
            if(traceStep == ts_pnt)
                continue; // not read from its own
            log2("memoryModel.print") << '\t' << ( ts_pnt->to_string() ) ;
            if( traceStep->_entity() == ts_pnt->_entity() )
                log2("memoryModel.print") << "RFI " << std::endl;
            else if( is_init_event(traceStep) )
                log2("memoryModel.print") << "RF_init " << std::endl ;
            else {
                if ( convert_to_ts(traceStep) ->m_wvopList.size() == 0)
                     log2("memoryModel.print") << "RFE w.o. view: " << traceStep->to_string() <<std::endl;
                else
                    log2("memoryModel.print") << "RFE " << ( convert_to_ts(traceStep) ->m_wvopList[0]->to_string()) << std::endl;
            }
        }

    }
 }

 void TSO::DEBUG_extractViewResultForTs(TraceStep * ts, z3::model & model)
 {
    for (auto && wv : ts->m_wvopList ) {
        for ( auto && sname_definition_pair : wv->resultDict ) {
            auto & sname = sname_definition_pair.first;
            auto & definition = sname_definition_pair.second;

            log2("memoryModel.print") << "\t\t updating global: " << sname << " = " << model.eval(definition) 
                                << " @ "<< model.eval(wv->timestamp) << std::endl;

        }
    }
 }



//--------------------------- wvop ------------------------------------------------------//


std::string wvopUniqueName()
{
    static int ctr = 0;
    return std::string("wvop")+std::to_string(ctr++);
}


std::string wvop::to_string() const
{
    return ("wvop:"+name);
}

wvop::wvop(const TraceStep & ts,
    tsDefsGroup_t & tsDefsGroup,
    TsThatWritesVars_t *TsThatWritesVars, 
    constraintList_t * p_ConstraintList,
    Step * globalEndStep) :
    Step(
        ts._entity(),                  // const std::string &p_entityName, 
        ts.getName() + "_" + wvopUniqueName(), // const std::string &name, 
        ts.tid,                         // int tid, 
        TsThatWritesVars,               // TsThatWritesVars_t *TsThatWritesVars,
        ts.TsNameToObj,                 // TsNameToObj_t *TsNameToObj, 
        ts.localStates,                 // statelist_ptr_t localStates,
        ts.m_pContext,                  // z3::context &c,
        *(ts.decodeExpr.get())          // z3::expr decodeExpr,
        // PiVarList_t *PiVarList = NULL
        )
{
    // Writes = {};
    // resultDict = {};
    // timestamp already created

    p_ConstraintList->push_back( timestamp < globalEndStep->timestamp );

    for ( auto && tsDefs : tsDefsGroup ) {
        auto & sname = std::get<0>(tsDefs);
        auto & definition = std::get<1>(tsDefs);
        Node * type_pnt = std::get<2>(tsDefs);
        Writes.insert(sname);

        z3::expr newDef = ts.z3c.newVar("def_global_" + name + "_"+sname, type_pnt);
        p_ConstraintList->push_back( newDef == definition );

        ILA_ASSERT( !IN(sname, resultDict) , "Bug: sname:" + sname + " already defined in wvop:" + name + "'s resultDict." );
        resultDict.insert( make_pair(sname, newDef) );
    }


}
