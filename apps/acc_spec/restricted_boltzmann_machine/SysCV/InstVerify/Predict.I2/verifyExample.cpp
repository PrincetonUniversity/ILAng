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
		unsigned per_v_pc;
		unsigned predict_upc;
		unsigned upc;
		// *** END of global annotation
 
// @_global

BIT_VEC _c_16_15(float in){
   return (BIT_VEC)(in*2)&0xffff;
}
float _b_16_15(BIT_VEC in){
   return ( in & 0xffff ) / 2.0;
}


void rbm::predict_rbm()
{
   init_done = 1;
   // Reset
   predict_start.write(false);
   predict_done.write(false);

   // Wait for configuratin
   do { wait(); }
   while (!init_done.read());

   // TODO:
   /*##LABEL##@localSync*/
       num_hidden.write( GM.num_hidden );
       num_visible.write( GM.num_visible );
       num_users.write( GM.num_users );
       num_loops.write( GM.num_loops );
       num_testusers.write( GM.num_testusers );
       num_movies.write( GM.num_movies );
   const u16 ntu = num_testusers.read();
   const u16 nv = num_visible.read();
   const u16 nh = num_hidden.read();
   const u16 nu = num_users.read();
   const u16 nlp = num_loops.read();

   u16 user = 0;
   u8 prediction, j;
   u8 count = 0;
   u16 i, tmp1, tmp2;
   bool pingpong;


   /*##LABEL##@_tampoline1##*/ 
   goto __Target_2;

PREDICT_LOOP:
   while (true)
   {

      if (user == ntu) //prediction done
      {
         // Wait for reset
         do { wait(); }
         while(true);

      }


      // 4-phase handshake
      do { wait(); }
      while (!predict_input_done.read());
      predict_start.write(true);
      do { wait(); }
      while (predict_input_done.read());
      predict_start.write(false);

      do { wait(); }
      while (!output_done.read());

      tmp1 = nlp * nu;
      tmp2 = tmp1 + user;
      pingpong = (tmp2) % 2;

   /*##LABEL##@_target1##*/ 
         __Target_1:
   		upc = 2;

      activateHiddenUnits_predict(pingpong, nh, nv); //getting preference
      return;

   /*##LABEL##@_target2##*/ 
         __Target_2:
   		predict_upc = 3;

      activateVisibleUnits_predict(nh, nv); //making rate based on existing edges value
      return;

   PREDICT_RATE:
      // Go through K visible units at a time
      for (i = 0; i < NUM_VISIBLE_MAX; i += K)
      {
         if(i == nv)
            break;
         prediction = 0;
      PREDICT_RESULT:
         for (j = 0; j < K; j++)
         {
            bool current_pv = predict_vector[i + j];
            wait();
            if (current_pv == 1)
            {
               prediction = j + 1;
            }
         }
         predict_result[0][count] = prediction;
         wait();
         count += 1;
      }
      count = 0;

      // 4-phase handshake with output, output current user's result
      predict_done.write(true);
      do { wait(); }
      while (!output_start.read());
      predict_done.write(false);
      do { wait(); }
      while (output_start.read());

      // This implementation is still computing debayer at once
      user += 1;
   }

   		upc = 0;

   		upc = 1;

   		upc = 2;

   		upc = 3;

}



void rbm::activateHiddenUnits_predict(bool pingpong, u16 nh, u16 nv)
{
   u16 h, v;
   DATA_sum_ sum, tmp;
   DATA01_D prob, tmp1;


   ACTIVATE_HIDDEN_PREDICT_H:
   for (h = 0; h < NUM_HIDDEN_MAX; h++)
   {
      if (h == nh)
         break;
      sum = 0;

   ACTIVATE_HIDDEN_PREDICT_V:
      for (v = 0; v < NUM_VISIBLE_MAX + 1; v++) // remove the +1 if you want to skip the bias (BIAS?)
      {
         if (v == nv + 1)
            break;


   		per_v_pc = 0;

   		predict_upc = 0;

   
   /*##LABEL##@predict.i0@END##*/
   
   
   /*##LABEL##@predict.i0@START##*/


         u8 current_data = data[pingpong][v];
         wait();
         if(current_data == 1)
         {
            tmp = edges[v][h];
            wait();
            sum += tmp;
         }
      }

      prob = _b_16_15 ( sigmoid(_c_16_15(sum) ) );

      bool comp = ((DATA01_D)0.5 < prob);
      bool th;
      if (comp)
         th = 1;
      else
         th = 0;
      hidden_unit[h] = th;
      wait();
   }

   hidden_unit[nh] = 1; // turn on bias
   wait();

		per_v_pc = 0;

		predict_upc = 1;

   /*##LABEL##@predict.i0@END##*/
}

void rbm::activateVisibleUnits_predict(u16 nh, u16 nv)
{
   // Calculate activation energy for visible units
   u16 v, h; //u16;
   DATA_sum_ sum;
   DATA_sum_ max;
   DATA01_D probs;
   DATA_pow pow2[K];
   DATA_sum3 sumOfpow2;
   DATA05_D expectation;
   u8 prediction;
   s16 tmp;
   DATA_sum_ tmp1;
   bool tmp2;
   ACTIVATE_VISIBLE_PREDICT_V:


   
		goto __predict_i2__START;
 

   for (v = 0; v < NUM_VISIBLE_MAX; v += K)
   {
      if (v == nv)
         break;
      // Get the sum of energies
      u16 j;//u16
      max = -500;
   ACTIVATE_VISIBLE_PREDICT_ENERGY:
      for (j = 0; j < K; j++)
      {
         sum = 0; //TODO: maximum 500 k.1 added together, k>0
      ACTIVATE_VISIBLE_PREDICT_H:
         for (h = 0; h < NUM_HIDDEN_MAX + 1; h++) // remove the +1 if you want to skip the bias
         {
            if (h == nh + 1)
               break;

   /*##LABEL##@predict.i1@END##*/
   
   		per_v_pc = 0;

   		predict_upc = 1;

   
   /*##LABEL##@predict.i1@START##*/

            tmp2 = hidden_unit[h];
            wait();
            tmp1 = edges[v + j][h];
            wait();
            if(tmp2)
            {
               sum += tmp1;
            }
            wait();
         }
         visibleEnergies[j] = sum;
         wait();
         if ( sum > max )
            max = sum;
      }

   		per_v_pc = 1;

   		predict_upc = 1;

   
   /*##LABEL##@predict.i1@END##*/

      max -= 31;
   ACTIVATE_VISIBLE_PREDICT_ENERGY_UPDATE:
      for (j = 0; j < K; j++)
      {

   
__predict_i2__END:
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
		 __CPROVER_assert( upc == GM.upc , "upc_match" );
		 __CPROVER_assert( predict_input_done.read() ==  GM.predict_input_done , "predict_input_done_match");
		 __CPROVER_assert( sum == ( GM.predict_sum & 0xffff ) / 2.0 , "predict_sum_match");
		 __CPROVER_assert(  (((unsigned int) (max*2.0)) & 0xffff) == ( GM.predict_max & 0xffff ) , "predict_max_match");
		 __CPROVER_assert( sumOfpow2 == ( GM.sumOfpow2 & 0xffffffffffffffffL ) / 1.0 , "sumOfpow2_match");
		 __CPROVER_assert( per_v_pc == GM.per_v_pc , "per_v_pc_match" );
		 __CPROVER_assert( j == GM.jstate , "jstate_match");
		 __CPROVER_assert( predict_upc == GM.predict_upc , "predict_upc_match" );
		 __CPROVER_assert( v == GM.predict_v_cnt , "predict_v_cnt_match");
		 __CPROVER_assert( h == GM.predict_h_cnt , "predict_h_cnt_match");
		 __CPROVER_assert( __CPROVER_array_equal( GM.data.arrayPnt,  data[0] ) , "data_match" );
		 __CPROVER_assert( __CPROVER_array_equal( GM.predict_result.arrayPnt,  predict_result[0] ) , "predict_result_match" );
// edges is ignored for FixPoint
		 __CPROVER_assert( __CPROVER_array_equal( GM.hidden_unit.arrayPnt,  hidden_unit.arrayPnt ) , "hidden_unit_match");
// visibleEnergies is ignored for FixPoint
// pow2 is ignored for FixPoint
       __CPROVER_assert(j<K, "ind-inv"); //ind-inv

		return;
		// *** END of LABEL: @predict.i2@END

   

   
   
__predict_i2__START:
         per_v_pc = 1;

         predict_upc = 1;

		 init_done = 1 ; // __CPROVER_assume( init_done == 1 );
		 train_input_done = 0 ; // __CPROVER_assume( train_input_done == 0 );
		 GM.per_v_pc = 1 ; // __CPROVER_assume( GM.per_v_pc == 1 );
		 done = 0 ; // __CPROVER_assume( done == 0 );
		 rst_inp = 0 ; // __CPROVER_assume( rst_inp == 0 );
		 GM.upc = 2 ; // __CPROVER_assume( GM.upc == 2 );
		 predict_input_done = 1 ; // __CPROVER_assume( predict_input_done == 1 );
		 GM.predict_upc = 1 ; // __CPROVER_assume( GM.predict_upc == 1 );
		 upc = 2 ; // __CPROVER_assume( upc == 2 );
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
		 predict_input_done.write( GM.predict_input_done );
		 sum = ( GM.predict_sum & 0xffff ) / 2.0 ;
		 sumOfpow2 = ( GM.sumOfpow2 & 0xffffffffffffffffL ) / 1.0 ;
		 j = GM.jstate;
		 v = GM.predict_v_cnt;
		 h = GM.predict_h_cnt;
       if(j==0)
         max = ( GM.predict_max & 0xffff ) / 2.0 - 31.0;
       else
         max = ( GM.predict_max & 0xffff ) / 2.0;
		 __CPROVER_array_copy( data[0], GM.data.arrayPnt );
		 __CPROVER_array_copy( predict_result[0], GM.predict_result.arrayPnt );
		 __CPROVER_array_copy( edges.arrayPnt, GM.edges.arrayPnt );
		 __CPROVER_array_copy( hidden_unit.arrayPnt, GM.hidden_unit.arrayPnt );
		 __CPROVER_array_copy( visibleEnergies.arrayPnt, GM.visibleEnergies.arrayPnt );
		 __CPROVER_array_copy( pow2, GM.pow2.arrayPnt );
		// *** END of LABEL: @predict.i2@START
       __CPROVER_assume(j<K); //ind-inv


         tmp1 = visibleEnergies[j];
         wait();
         visibleEnergies[j] = tmp1 - max;
         wait();
      }

   		per_v_pc = 2;

   		predict_upc = 1;

   
__predict_i2__END2:
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
		 __CPROVER_assert( upc == GM.upc , "upc_match" );
		 __CPROVER_assert( predict_input_done.read() ==  GM.predict_input_done , "predict_input_done_match");
		 __CPROVER_assert( sum == ( GM.predict_sum & 0xffff ) / 2.0 , "predict_sum_match");
		 __CPROVER_assert( max == ( GM.predict_max & 0xffff ) / 2.0 , "predict_max_match");
		 __CPROVER_assert( sumOfpow2 == ( GM.sumOfpow2 & 0xffffffffffffffffL ) / 1.0 , "sumOfpow2_match");
		 __CPROVER_assert( per_v_pc == GM.per_v_pc , "per_v_pc_match" );
		 __CPROVER_assert( j == GM.jstate , "jstate_match");
		 __CPROVER_assert( predict_upc == GM.predict_upc , "predict_upc_match" );
		 __CPROVER_assert( v == GM.predict_v_cnt , "predict_v_cnt_match");
		 __CPROVER_assert( h == GM.predict_h_cnt , "predict_h_cnt_match");
		 __CPROVER_assert( __CPROVER_array_equal( GM.data.arrayPnt,  data[0] ) , "data_match" );
		 __CPROVER_assert( __CPROVER_array_equal( GM.predict_result.arrayPnt,  predict_result[0] ) , "predict_result_match" );
// edges is ignored for FixPoint
		 __CPROVER_assert( __CPROVER_array_equal( GM.hidden_unit.arrayPnt,  hidden_unit.arrayPnt ) , "hidden_unit_match");
// visibleEnergies is ignored for FixPoint
// pow2 is ignored for FixPoint

		return;
		// *** END of LABEL: @predict.i2@END


      sumOfpow2 = 0; // this is the numerator
      //TODO: maximum exp of 300 k.1 added together, k>0
   ACTIVATE_VISIBLE_PREDICT_SUM:
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@predict.i3@END##*/
   		per_v_pc = 2;

   		predict_upc = 1;

   /*##LABEL##@predict.i3@START##*/

         /*TODO:fix point; exp function*/
         tmp1 = visibleEnergies[j];
         wait();
         /*
         if (tmp1[0] == 0)
         {
            tmp = tmp1.to_int();
         }
         else if (tmp1 > 0)
         {
            tmp = tmp1.to_int() + 1;
         }
         else
            tmp = -1;

         DATA_pow dp;
         if (tmp < 0 )
            dp = 0;
         else
            dp = 1UL << tmp;
         */
         DATA_pow dp = _b_16_15( to_int_exp(_c_16_15( tmp1 ) ) );

         sumOfpow2 += dp;
         pow2[j] = dp;
      }

   		per_v_pc = 3;

   		predict_upc = 1;

   /*##LABEL##@predict.i3@END##*/

      // Getting the probabilities
      expectation = 0.0;
   ACTIVATE_VISIBLE_PREDICT_PROB:
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@predict.i4@END##*/
   		per_v_pc = 3;

   		predict_upc = 1;

   /*##LABEL##@predict.i4@START##*/

         DATA_pow dp = pow2[j];
         wait();
         //probs = sld::udiv_func<32, 32, 64, 64, 64, 1>(dp, sumOfpow2);
       probs  = dp/sumOfpow2;
         expectation += j * probs;
      }


   /*##LABEL##@vpc4##*/
   		predict_upc = 2;

   
   /*##LABEL##@predict.i4@END##*/

      prediction = round(expectation);
   ACTIVATE_VISIBLE_PREDICT_RATE:
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@vpc4##*/
   		predict_upc = 2;

   
   /*##LABEL##@predict.i5@END##*/

         if (j == prediction)
            predict_vector[v + j] = 1;
         else
            predict_vector[v + j] = 0;
         wait();
      }
   }

   predict_vector[nv] = 1; // turn on bias
   wait();



   		per_v_pc = 0;

   		predict_upc = 2;

   
   /*##LABEL##@predict.i5@END##*/
}
