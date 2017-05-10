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
		// *** END of global annotation
 
// @_global

void rbm::config()
{
// GOTO: FuncStart
    
		goto __confDoneInst__START;
 

RESET_CONFIG:  // Initialization
   num_hidden.write(0);
   num_visible.write(0);
   num_users.write(0);
   num_loops.write(0);
   num_movies.write(0);
   init_done.write(false);

   wait();

CONFIG_REGISTER_WHILE:
   do { wait(); 
__confDoneInst__START:
		 rst_inp = 0 ; // __CPROVER_assume( rst_inp == 0 );
		 init_done = 0 ; // __CPROVER_assume( init_done == 0 );
		 conf_done_inp = 1 ; // __CPROVER_assume( conf_done_inp == 1 );
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
		 num_hidden.write( GM.num_hidden );
		 num_visible.write( GM.num_visible );
		 num_users.write( GM.num_users );
		 num_loops.write( GM.num_loops );
		 num_testusers.write( GM.num_testusers );
		 num_movies.write( GM.num_movies );
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
		 __CPROVER_array_copy( data[0], GM.data.arrayPnt );
		 __CPROVER_array_copy( predict_result[0], GM.predict_result.arrayPnt );
		// *** END of LABEL: @confDoneInst@START
 }
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
      
__confDoneInst__END:
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
		 __CPROVER_assert( __CPROVER_array_equal( GM.data.arrayPnt,  data[0] ) , "data_match" );
		 __CPROVER_assert( __CPROVER_array_equal( GM.predict_result.arrayPnt,  predict_result[0] ) , "predict_result_match" );

		return;
		// *** END of LABEL: @confDoneInst@END

      wait();
   }
}


