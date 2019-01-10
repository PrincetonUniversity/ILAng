/// \file the ila example of AES block encryption
///  Hongce Zhang (hongcez@princeton.edu)
///

#include "pmesh_l15_ila.h"

// some assumptions on the interface:
// amo_op : 0
// blockinitstore : 0
// blockstore : 0
// csm_data : 0
// data_next_entry : 0
// invalidate_cacheline : 0
// l1rplway : 0
// prefetch : 0
// threadid : 0

// a request if not hit
// go to the NoC
// if hit, ?

PMESH_L15::PMESH_L15()
    : // construct the model
      model("PMESH_L15"),
      // I/O interface: this is where the commands come from.
      address(model.NewBvInput("transducer_l15_address", 40)),
      data   (model.NewBvInput("transducer_l15_data",    64)),
      nc     (model.NewBvInput("transducer_l15_nc",       1)),
      rqtype (model.NewBvInput("transducer_l15_rqtype",   5)),
      size   (model.NewBvInput("transducer_l15_size",     3)),
      val    (model.NewBvInput("transducer_l15_val",      1)),
      
      
      // Output states: l1.5 --> noc1 requests
      l15_noc1buffer_req_address( model.NewBvState("l15_noc1buffer_req_address", 40) ),
      l15_noc1buffer_req_data0  ( model.NewBvState("l15_noc1buffer_req_data0"  , 64) ),
      l15_noc1buffer_req_data1  ( model.NewBvState("l15_noc1buffer_req_data1"  , 64) ),
      l15_noc1buffer_csm_data   ( model.NewBvState("l15_noc1buffer_csm_data  " , 33) ),
      l15_noc1buffer_csm_ticket ( model.NewBvState("l15_noc1buffer_csm_ticket" , 3) ),
      l15_noc1buffer_req_homeid ( model.NewBvState("l15_noc1buffer_req_homeid" , 30) ),
      l15_noc1buffer_req_mshrid ( model.NewBvState("l15_noc1buffer_req_mshrid" , 2) ),
      l15_noc1buffer_req_noncacheable( model.NewBvState("l15_noc1buffer_req_noncacheable" , 1) ),
      l15_noc1buffer_req_prefetch    ( model.NewBvState("l15_noc1buffer_req_prefetch"     , 1) ),
      l15_noc1buffer_req_size        ( model.NewBvState("l15_noc1buffer_req_size"         , 3) ),
      // l15_noc1buffer_req_threadid    ( model.NewBvState("") ), // not
      l15_noc1buffer_req_type        ( model.NewBvState("l15_noc1buffer_req_type"         , 5) ),
      
      l15_transducer_val             ( model.NewBvState("l15_transducer_val", 1) ),
      l15_transducer_returntype      ( model.NewBvState("l15_transducer_returntype", 4) ), // 0 if hit
      l15_transducer_data_0          ( model.NewBvState("l15_transducer_data_0", 64) ),

      // We made the map as a mem (although in the design, it does not need to be so large)
      mesi_state( model.NewMemState( "address_to_mesi_map", 40, 2 ) ),
      data_state( model.NewMemState( "address_to_data_map", 40, 64) )
      

    {

  // L1.5 fetch function -- what corresponds to instructions on L1.5 PCX interface
  model.SetFetch( lConcat({address, data, nc, rqtype, size, val })   );
  // Valid instruction: what means to have valid command (valid = 1)
  model.SetValid( val == 1 );

  // 
  // HZ's note about modeling cache
  // This is in some sense a shared memory
  // 1. we can model it as a memory, but this does not
  // mean it must have that size (The same address
  // and etc. of facet axiom function can be adjusted
  // to factor in the conflict-eviction and etc.
  // This part should be 
  // 2. It is a shared state
  // because we have multiple interface
  // This is in some sence similar to the ViCL approach
  // But hte difference is that we treat the Cache state
  // as "state", and encode the updates as SMT queries
  // 
  // For the verification, we need to somehow use an uninterpreted
  // function-like mapping on what it got from the mem
  // 

  // add instructions
  {
    auto instr = model.NewInstr("LOAD_normal");

    instr.SetDecode( ( rqtype == 0) & (nc == 0) );

    auto MESI_state = Load( mesi_state, address ); // Use the map
    auto DATA_cache = Load( data_state, address ); // Use the map

    auto hit = MESI_state != MESI_INVALID;

    instr.SetUpdate(l15_noc1buffer_req_address,      Ite(! hit, address,       unknown(40)() ) );
    instr.SetUpdate(l15_noc1buffer_req_noncacheable, Ite(! hit, BvConst(0,1) , unknown(1)()  ) );
    instr.SetUpdate(l15_noc1buffer_req_size,         Ite(! hit, size ,         unknown(3)()  ) );
    instr.SetUpdate(l15_noc1buffer_req_type,         Ite(! hit, rqtype ,       unknown(5)()  ) );


// not specifying these updates:
// l15_noc1buffer_req_data0  
// l15_noc1buffer_req_data1  
// l15_noc1buffer_csm_data   
// l15_noc1buffer_csm_ticket 
// l15_noc1buffer_req_homeid 
// l15_noc1buffer_req_mshrid 
// l15_noc1buffer_req_noncacheable
// l15_noc1buffer_req_prefetch   
// l15_noc1buffer_req_threadid 

    // on the hit side ...

    instr.SetUpdate( l15_transducer_val, Ite( hit , BvConst(1,1), unknown(1)() ) );
    instr.SetUpdate( l15_transducer_returntype, Ite( hit , BvConst(0,4) , unknown(4)() ) );
    instr.SetUpdate( l15_transducer_data_0, Ite( hit , DATA_cache , unknown(64)()  ) );
    
  }

}
