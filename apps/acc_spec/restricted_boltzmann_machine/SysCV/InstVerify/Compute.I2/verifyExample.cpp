// Let's try some example
#include "rbm.hpp"

// global annotation
	BV1 conf_done_inp;
	BV32 conf_num_hidden_inp;
	BV32 conf_num_visible_inp;
	BV32 conf_num_users_inp;
	BV32 conf_num_loops_inp;
	BV32 conf_num_testusers_inp;
	BV32 conf_num_movies_inp;
	BV1 rst_inp;
	BV1 rd_grant_inp;
	BV32 data_in_inp;
	BV1 wr_grant_inp;
		unsigned upc;
		unsigned rd_complete;
		// *** END of global annotation
 
// @_global

void rbm::config()
{
// GOTO: FuncStart

RESET_CONFIG:  // Initialization
   num_hidden.write(0);
   num_visible.write(0);
   num_users.write(0);
   num_loops.write(0);
   num_movies.write(0);
   init_done.write(false);

   wait();

CONFIG_REGISTER_WHILE:
   do { wait(); /*##LABEL##@confDoneInst@START##*/ }
   while (!conf_done.read());

   ///read configuration parameters
   num_hidden.write(conf_num_hidden.read());
   num_visible.write(conf_num_visible.read());
   num_users.write(conf_num_users.read());
   num_loops.write(conf_num_loops.read());
   num_testusers.write(conf_num_testusers.read());
   num_movies.write(conf_num_movies.read());

   std::cout << "Config done" << std::endl;
   ///configuration done; start other processes
   
   
   init_done.write(true);
   
   
CONFIG_IDLE_WHILE:
   while (true)
   {
      /*##LABEL##@confDoneInst@END##*/
      wait();
   }
}




void rbm::load()
{
   init_done = 1;
RESET_LOAD:
   //data_in.reset_get();
   rd_index.write(0);
   rd_length.write(0);
   rd_request.write(false);

   train_input_done.write(false);
   predict_input_done.write(false);

LOAD_INITIAL_WHILE:
   do {wait();}
   while(!init_done.read());

   u16 index = 0;
   u16 loop_count = 0;
   bool pingpong = 0;
   u16 tmp1, tmp2;
   /*##LABEL##@compute.StartRead@START##*/ 

   /*##LABEL##@localSync##*/
       num_hidden.write( GM.num_hidden );
       num_visible.write( GM.num_visible );
       num_users.write( GM.num_users );
       num_loops.write( GM.num_loops );
       num_testusers.write( GM.num_testusers );
       num_movies.write( GM.num_movies );
   const u32 nv = num_visible.read();
   const u32 ntu = num_testusers.read();
   const u32 nu = num_users.read();
   const u32 nlp = num_loops.read();
   const u32 nm = num_movies.read();
   // std::cout<<"conf result: nv-ntu-nu-nlp"<<nv<<" "<<ntu<<" "<<nu<<" "<<nlp<<std::endl;

   
		goto __compute_StartTrainOrPredict__START;
 

LOAD_FIRST_INPUT:
   		upc = 0;

   // Send DMA request
   rd_index.write(index);
   rd_length.write(5 * nm);
   //std::cout<<"DUT load index"<<index <<" loop #"<<loop_count<<std::endl;
   // 4-phase handshake

   if ( loop_count == nlp )
      do { wait(); }
      while (!train_done.read());

   //wait for training done
   rd_request.write(true);
   do { wait(); 
   /*##LABEL##@rdGrantInst@START@0##*/  
   		upc = 1;
 
   /*##LABEL##@compute.StartRead@END##*/ 

   /*##LABEL##@compute.WaitReadComplete@END##*/ 
   /*##LABEL##@compute.WaitReadComplete@START##*/ 
      		rd_complete = 0;

   }
   while(!rd_grant.read());
   rd_request.write(false);

   tmp1 = loop_count * nu;
   tmp2 = tmp1 + index;
   pingpong = tmp2 % 2;
   // cout<<"loading start user"<<index<<":"<<pingpong<<endl;

LOAD_FIRST_USER_DATA:
   for (u16 i = 0; i < NUM_VISIBLE_MAX; i++)
   {
      if (i == nv)
         break;
      u8 rate = (u8) data_in.read();
      wait();
      data[pingpong][i] = rate;
     
     /*##LABEL##@rdGrantInst@END@0##*/ 
      		rd_complete = 0;

     /*##LABEL##@load@END@0##*/

     /*##LABEL##@load@START@0##*/
      //cout<<data[i];
   }
   wait();
   data[pingpong][nv] = 1;

     /*##LABEL##@load@END@0##*/
   /*##LABEL##@compute.WaitReadComplete@END##*/ 
   		upc = 2;
 
   
__compute_StartTrainOrPredict__START:
		 rst_inp = 0 ; // __CPROVER_assume( rst_inp == 0 );
		 init_done = 1 ; // __CPROVER_assume( init_done == 1 );
		 GM.upc = 1 ; // __CPROVER_assume( GM.upc == 1 );
		 done = 0 ; // __CPROVER_assume( done == 0 );
		 conf_done.data = conf_done_inp;
		 conf_num_hidden.data = conf_num_hidden_inp;
		 conf_num_visible.data = conf_num_visible_inp;
		 conf_num_users.data = conf_num_users_inp;
		 conf_num_loops.data = conf_num_loops_inp;
		 conf_num_testusers.data = conf_num_testusers_inp;
		 conf_num_movies.data = conf_num_movies_inp;
		 rst.data = rst_inp;
		 init_done.write( GM.init_done );
		 done.write( GM.done );
		 rd_index.write( GM.rd_index );
		 rd_length.write( GM.rd_length );
		 rd_request.write( GM.rd_request );
		 rd_grant.data = rd_grant_inp;
		 data_in.data = data_in_inp;
		 wr_grant.data = wr_grant_inp;
		 wr_request.write( GM.wr_request );
		 wr_index.write( GM.wr_index );
		 wr_length.write( GM.wr_length );
		 data_out.write( GM.data_out );
		 index = GM.index;
		 loop_count = GM.loop_count;
		 train_input_done.write( GM.train_input_done );
		 predict_input_done.write( GM.predict_input_done );
		 __CPROVER_array_copy( data[0], GM.data.arrayPnt );
		 __CPROVER_array_copy( predict_result[0], GM.predict_result.arrayPnt );
		 __CPROVER_array_copy( edges.arrayPnt, GM.edges.arrayPnt );
		// *** END of LABEL: @compute.StartTrainOrPredict@START
      __CPROVER_assume(loop_count <= nlp);
      		GM.rd_complete = 1;
LOAD_INPUT_WHILE:
   while(true)
   {
     //??
      if ( loop_count != nlp ) //loading training data done
      {
         // 4-phase handshake with train
         train_input_done.write(true);

   		upc = 2;
 
   
__compute_StartTrainOrPredict__END:
		GM.update( conf_done_inp , conf_num_hidden_inp , conf_num_visible_inp , conf_num_users_inp , conf_num_loops_inp , conf_num_testusers_inp , conf_num_movies_inp , rst_inp , rd_grant_inp , data_in_inp , wr_grant_inp );
		 __CPROVER_assert( init_done.read() ==  GM.init_done , "init_done_match");
		 __CPROVER_assert( done.read() ==  GM.done , "done_match");
		 __CPROVER_assert( num_hidden.read() ==  GM.num_hidden , "num_hidden_match");
		 __CPROVER_assert( num_visible.read() ==  GM.num_visible , "num_visible_match");
		 __CPROVER_assert( num_users.read() ==  GM.num_users , "num_users_match");
		 __CPROVER_assert( num_loops.read() ==  GM.num_loops , "num_loops_match");
		 __CPROVER_assert( num_testusers.read() ==  GM.num_testusers , "num_testusers_match");
		 __CPROVER_assert( num_movies.read() ==  GM.num_movies , "num_movies_match");
		 __CPROVER_assert( rd_index.read() ==  GM.rd_index , "rd_index_match");
		 __CPROVER_assert( rd_length.read() ==  GM.rd_length , "rd_length_match");
		 __CPROVER_assert( rd_request.read() ==  GM.rd_request , "rd_request_match");
		 __CPROVER_assert( wr_request.read() ==  GM.wr_request , "wr_request_match");
		 __CPROVER_assert( wr_index.read() ==  GM.wr_index , "wr_index_match");
		 __CPROVER_assert( wr_length.read() ==  GM.wr_length , "wr_length_match");
		 __CPROVER_assert( data_out.read() ==  GM.data_out , "data_out_match");
		 //__CPROVER_assert( rd_complete == GM.rd_complete , "rd_complete_match" );
		 __CPROVER_assert( index == GM.index , "index_match");
		 __CPROVER_assert( loop_count == GM.loop_count , "loop_count_match");
		 __CPROVER_assert( upc == GM.upc , "upc_match" );
		 __CPROVER_assert( train_input_done.read() ==  GM.train_input_done , "train_input_done_match");
		 __CPROVER_assert( predict_input_done.read() ==  GM.predict_input_done , "predict_input_done_match");
		 __CPROVER_assert( __CPROVER_array_equal( GM.data.arrayPnt,  data[0] ) , "data_match" );
		 __CPROVER_assert( __CPROVER_array_equal( GM.predict_result.arrayPnt,  predict_result[0] ) , "predict_result_match" );

       __CPROVER_assert(GM.upc == 2, "whynot1");
// edges is ignored for FixPoint
		return;
		// *** END of LABEL: @compute.StartTrainOrPredict@END
 
         do { wait(); }
         while (!train_start.read());
         train_input_done.write(false);
         do { wait(); }
         while (train_start.read());
      }
      else//loading test data done
      {
         // 4-phase handshake with predict
         predict_input_done.write(true);

   		upc = 2;
 
   
__compute_StartTrainOrPredict__END2:
		GM.update( conf_done_inp , conf_num_hidden_inp , conf_num_visible_inp , conf_num_users_inp , conf_num_loops_inp , conf_num_testusers_inp , conf_num_movies_inp , rst_inp , rd_grant_inp , data_in_inp , wr_grant_inp );
		 __CPROVER_assert( init_done.read() ==  GM.init_done , "init_done_match");
		 __CPROVER_assert( done.read() ==  GM.done , "done_match");
		 __CPROVER_assert( num_hidden.read() ==  GM.num_hidden , "num_hidden_match");
		 __CPROVER_assert( num_visible.read() ==  GM.num_visible , "num_visible_match");
		 __CPROVER_assert( num_users.read() ==  GM.num_users , "num_users_match");
		 __CPROVER_assert( num_loops.read() ==  GM.num_loops , "num_loops_match");
		 __CPROVER_assert( num_testusers.read() ==  GM.num_testusers , "num_testusers_match");
		 __CPROVER_assert( num_movies.read() ==  GM.num_movies , "num_movies_match");
		 __CPROVER_assert( rd_index.read() ==  GM.rd_index , "rd_index_match");
		 __CPROVER_assert( rd_length.read() ==  GM.rd_length , "rd_length_match");
		 __CPROVER_assert( rd_request.read() ==  GM.rd_request , "rd_request_match");
		 __CPROVER_assert( wr_request.read() ==  GM.wr_request , "wr_request_match");
		 __CPROVER_assert( wr_index.read() ==  GM.wr_index , "wr_index_match");
		 __CPROVER_assert( wr_length.read() ==  GM.wr_length , "wr_length_match");
		 __CPROVER_assert( data_out.read() ==  GM.data_out , "data_out_match");
		 //__CPROVER_assert( rd_complete == GM.rd_complete , "rd_complete_match" );
		 __CPROVER_assert( index == GM.index , "index_match");
		 __CPROVER_assert( loop_count == GM.loop_count , "loop_count_match");
		 __CPROVER_assert( upc == GM.upc , "upc_match" );
		 __CPROVER_assert( train_input_done.read() ==  GM.train_input_done , "train_input_done_match");
		 __CPROVER_assert( predict_input_done.read() ==  GM.predict_input_done , "predict_input_done_match");
		 __CPROVER_assert( __CPROVER_array_equal( GM.data.arrayPnt,  data[0] ) , "data_match" );
		 __CPROVER_assert( __CPROVER_array_equal( GM.predict_result.arrayPnt,  predict_result[0] ) , "predict_result_match" );


       __CPROVER_assert(GM.upc == 2, "whynot2");
// edges is ignored for FixPoint
		return;
		// *** END of LABEL: @compute.StartTrainOrPredict@END
 
         do { wait(); }
         while (!predict_start.read());
         predict_input_done.write(false);
         do { wait(); }
         while (predict_start.read());
         //cout<<"ka"<<endl;
      }

      //upgrate index, check if train loop #
      index += 1;
      if( (index == nu) &&  (loop_count != nlp))
      {
         loop_count += 1;
         index = 0;
      }
      if( (index == ntu) && (loop_count == nlp))
         // Input complete; wait for reset
      LOAD_DONE:
         do { wait(); 
   /*##LABEL##@compute.Finish@END##*/ 

   /*##LABEL##@compute.Finish@START##*/ 
   		upc = 3;

    }
         while (true);
      
     /*##@@##  This is the end of a micro-inst */
      
      // Send DMA request
      unsigned dma_index = nv * (unsigned) index ;
      if (loop_count == nlp)
         dma_index += nv * nu;
      rd_index.write(dma_index);
      rd_length.write(5 * nm);
      //std::cout<<"DUT load index"<<index <<" loop #"<<loop_count<<std::endl;
      // 4-phase handshake
      if ( loop_count == nlp )
         do { wait(); }
         while (!train_done.read());

      //wait for training done
      rd_request.write(true);
      do { wait(); /*##LABEL##@rdGrantInst@START@1##*/}
      while(!rd_grant.read());
      rd_request.write(false);

      tmp1 = loop_count * nu;
      tmp2 = tmp1 + index;
      pingpong = tmp2 % 2;
      // cout<<"loading start user"<<index<<":"<<pingpong<<endl;

   LOAD_ONE_USER_DATA:
      for (u16 i = 0; i < NUM_VISIBLE_MAX; i++)
      {
         if (i == nv)
            break;
         u8 rate = data_in.read();
         wait();
         data[pingpong][i] = rate;
       /*##LABEL##@rdGrantInst@END@1##*/
         		rd_complete = 0;

      /*##LABEL##@load@END@1##*/
       
     /*##LABEL##@load@START@1##*/
         //cout<<data[i];
      }
      wait();
      data[pingpong][nv] = 1;


      		rd_complete = 1;

     /*##LABEL##@load@END@1##*/
   }
}



void rbm::store()
{
   init_done = 1;
RESET_STORE:
   //data_out.reset_put();
   wr_length.write(0);
   wr_index.write(0);
   wr_request.write(false);

   output_start.write(false);
   output_done.write(true);
   done.write(false);

   do {wait();}
   while(!init_done.read());

   const u16 ntu = num_testusers.read();
   const u16 nm = num_movies.read();

   int index = 0;
   u8 rating;


STORE_OUTPUT_WHILE:
   while(true)
   {

      if (index == ntu)
      {
         // RBM Done (need a reset)
         done.write(true);
         do { wait(); }
         while(true);
      }

      // 4-phase handshake with prediction
      do { wait(); }
      while (!predict_done.read());
      output_start.write(true);
      do { wait(); }
      while (predict_done.read());
      output_start.write(false);
      output_done.write(false);

      unsigned dma_index = nm * (unsigned) index;
      wr_index.write(dma_index);
      wr_length.write(num_movies.read());
      index += 1;


      // Send DMA request
      wr_request.write(true);
      do { wait(); /*##LABEL##@wrGrantInst@START##*/  }
      while(!wr_grant.read());
      wr_request.write(false);

   STORE_SINGLE_LOOP:
      for (u16 i = 0; i < NUM_MOVIE_MAX; i++)
      {
         if (i == nm)
            break;
         rating = predict_result[0][i];
         wait();
         data_out.write((u32)rating);

       /*##LABEL##@wrGrantInst@END##*/

         /*##LABEL##@wr_complete0##*/
       /*##LABEL##@store@END##*/


       /*##LABEL##@store@START##*/
      }

      output_done.write(true);
         /*##LABEL##@wr_complete1##*/
       /*##LABEL##@store@END##*/

   }
}