// Let's try some example
#include "rbm.hpp"

/*##LABEL##@_global##*/ 
// @_global

BIT_VEC _c_16_15(float in){
   return (BIT_VEC)(in*2)&0xffff;
}
float _b_16_15(BIT_VEC in){
   return ( in & 0xffff ) / 2.0;
}

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
   const u32 nv = num_visible.read();
   const u32 ntu = num_testusers.read();
   const u32 nu = num_users.read();
   const u32 nlp = num_loops.read();
   const u32 nm = num_movies.read();
   // std::cout<<"conf result: nv-ntu-nu-nlp"<<nv<<" "<<ntu<<" "<<nu<<" "<<nlp<<std::endl;


LOAD_FIRST_INPUT:
   /*##LABEL##@upc@0##*/
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
   /*##LABEL##@upc@1##*/ 
   /*##LABEL##@compute.StartRead@END##*/ 

   /*##LABEL##@compute.WaitReadComplete@END##*/ 
   /*##LABEL##@compute.WaitReadComplete@START##*/ 
      /*##LABEL##@rd_complete0##*/
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
      /*##LABEL##@rd_complete0##*/
     /*##LABEL##@load@END@0##*/

     /*##LABEL##@load@START@0##*/
      //cout<<data[i];
   }
   wait();
   data[pingpong][nv] = 1;

     /*##LABEL##@load@END@0##*/
   /*##LABEL##@compute.WaitReadComplete@END##*/ 
   /*##LABEL##@upc@2##*/ 
   /*##LABEL##@compute.StartTrainOrPredict@START##*/ 
      /*##LABEL##@rd_complete1##*/
LOAD_INPUT_WHILE:
   while(true)
   {
     //??
      if ( loop_count != nlp ) //loading training data done
      {
         // 4-phase handshake with train
         train_input_done.write(true);

   /*##LABEL##@upc@2##*/ 
   /*##LABEL##@compute.StartTrainOrPredict@END##*/ 
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

   /*##LABEL##@upc@2##*/ 
   /*##LABEL##@compute.StartTrainOrPredict@END##*/ 
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
   /*##LABEL##@upc@3##*/
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
         /*##LABEL##@rd_complete0##*/
      /*##LABEL##@load@END@1##*/
       
     /*##LABEL##@load@START@1##*/
         //cout<<data[i];
      }
      wait();
      data[pingpong][nv] = 1;


      /*##LABEL##@rd_complete1##*/
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

   /*##LABEL##@localSync*/
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




void rbm::train_rbm()
{
   init_done = 1;
   //reset
   train_start.write(false);
   train_done.write(false);
   mti_signal.write(625);

   // Wait for configuratin
   do { wait(); }
   while (!init_done.read());

   const u32 nv = num_visible.read();
   const u32 nh = num_hidden.read();
   const u32 nu = num_users.read();
   const u32 nlp = num_loops.read();

   u32 user;
   u32 current_loop = 0;

   u32 v;
   u32 h;
   u32 tmp3, tmp4;

   u8 tmp5;
   bool pingpong = 0;
   bool tmp1, tmp2, bool1, bool2;
   DATA_edge tmp;


   /*##LABEL##@_tampoline1##*/ 
   goto __Target_2;

   ///reset edges
RESET_LOOP_V:
   for (v = 0; v < NUM_VISIBLE_MAX + 1; v++)
   {
      if(v == nv + 1)
         break;
   RESET_LOOP_H:
      for (h = 0; h < NUM_HIDDEN_MAX + 1; h++)
      {
         if ( h == nh + 1)
            break;
         edges[v][h] = (fconst)0;
      }
   }
{
   u32 current_h = 0;
   u32 current_v = 0;
   u32 vlp = nv / NUM_VISIBLE_MAX ;
   u32 hlp  = nh / NUM_HIDDEN_MAX ;
   u32 vrest_ = nv - vlp * NUM_VISIBLE_MAX ;
   u32 hrest_ = nh - hlp * NUM_HIDDEN_MAX ;
   if (vrest_ != 0)
      vlp += 1;
   if (hrest_ != 0)
      hlp += 1;
   //std::cout << "Configuration: VISIBLE_LOOPS- " << vlp << "; HIDDEN_LOOPS-" << hlp << std::endl;
}
   ///start training loop
TRAIN_LOOP:
   while (true)
   {
      if (current_loop == nlp)
      {
         // training done
         train_done.write(true);
      TRAIN_IDLE:
         do { wait(); }
         while(true);
      }
      //cout << "Current training loop-" << current_loop << endl;
   TRAIN_USER:
      for (user = 0; user < nu; user++)
      {
         // ==> Phase 1: Activate hidden units
       
//##LABEL##@_train_rbm##//
// loop_count -> loop_cout
// index -> user
       
         // 4-phase handshake with load
         do { wait(); }
         while (!train_input_done.read());
         train_start.write(true);
         do { wait(); }
         while (train_input_done.read());
         train_start.write(false);

         tmp3 = current_loop * nu;
         tmp4 = tmp3 + user;
         pingpong = tmp4 % 2;

   /*##LABEL##@_target1##*/ 
         __Target_1:
   /*##LABEL##@upc@2##*/
         // Activate hidden units
         activateHiddenUnits_train(pingpong, nh, nv); //compute its activation energy a_i
         return;
         // Get positive association
      TRAIN_UPDATE_POS_V:
         for (v = 0; v < NUM_VISIBLE_MAX + 1; v++)
         {
            if(v == nv + 1)
               break;

   /*##LABEL##@train.i5@END##*/ 

   /*##LABEL##@upc@2##*/
   /*##LABEL##@trainUpc3##*/
   /*##LABEL##@train.i5@START##*/ 

            tmp5 = data[pingpong][v];
            wait();
            if (tmp5 != 2)
            {
            TRAIN_UPDATE_POS_H:
               for (h = 0; h < NUM_HIDDEN_MAX + 1; h++)
               {
                  if ( h == nh + 1)
                     break;
                  tmp2 = hidden_unit[h];
                  wait();
                  pos[v][h] = tmp5 && tmp2;
                  wait();
               }
            }
         }

   /*##LABEL##@trainUpc2##*/
   /*##LABEL##@train.i5@END##*/ 

         // ==> Phase 2: Reconstruction (activate visible units)
         // Activate visible units
   /*##LABEL##@_target2##*/ 
         __Target_2:
   /*##LABEL##@upc@2##*/
         activateVisibleUnits_train(nh, nv); //compute its activation energy a_i
         return;
         // Get negative association
      TRAIN_UPDATE_NEG_V:
         for (v = 0; v < NUM_VISIBLE_MAX + 1; v++)
         {
            if (v == nv + 1)
               break;
         
         //##LABEL##@_TRAIN_S2_BEGIN##//
            tmp5 = data[pingpong][v];
            wait();
         TRAIN_UPDATE_NEG_H:
            for (h = 0; h < NUM_HIDDEN_MAX + 1; h++)
            {
               if ( h == nh + 1)
                  break;
               if (tmp5 != 2)
               {
                  tmp1 = hidden_unit[h];
                  tmp2 = visible_unit[v];
                  wait();
                  neg[v][h] = tmp1 && tmp2;
                  wait();
               }
               tmp = edges[v][h];
               bool1 = pos[v][h];
               bool2 = neg[v][h];
               wait();
               // ==> Phase 3: Update the weights
               DATA_edge de;
               if(bool1 && !bool2)
               {
                  de = tmp + DATA_edge(LEARN_RATE);
               }
               else if(!bool1 && bool2)
               {
                  de = tmp - DATA_edge(LEARN_RATE);
               }
               else
               {
                  de = tmp;
               }

               edges[v][h] = de;
               wait();
            }
         }
      }
      // start next loop
      current_loop += 1;
   }
   //##LABEL##@_TRAIN_S2_END##//
}



void rbm::activateHiddenUnits_train(bool pingpong, u16 nh, u16 nv)//train_flag call random; visible is the real grading
{
   // Calculate activation energy for hidden units
   u16 h, v;   // can be u16
   DATA_sum_ sum, tmp;
   DATA01_D prob;
   DATA01_D RAND;
   u8 current_data;
   DATA01_D tmp1;// Activate hidden units

  ACTIVATE_HIDDEN_TRAIN_H:
   for (h = 0; h < NUM_HIDDEN_MAX; h++)
   {
      if (h == nh)
         break;
      // Get the sum of energies  //a_i=∑_jw_ijx_j
      sum = 0;//TODO: hiddenenergies maximum 300 k.1 added together, k>0
   ACTIVATE_HIDDEN_TRAIN_V:
      for (v = 0; v < NUM_VISIBLE_MAX + 1; v++) // remove the +1 if you want to skip the bias (BIAS?)
      {
        
         if (v == nv + 1)
            break;

   /*##LABEL##@vpc0##*/
   /*##LABEL##@trainUpc0##*/
   
   /*##LABEL##@train.i0@END##*/
   
   
   /*##LABEL##@train.i0@START##*/
         current_data = data[pingpong & 0][v];

         wait();
         if(current_data == 1)
         {
            tmp = edges[v][h];
            sum += tmp;
            wait();
         }
      } // extra assumptions are needed
      prob = _b_16_15 ( sigmoid(_c_16_15(sum) ) );

      RAND = rand_gen();

      bool comp = (RAND < prob);
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

/*##LABEL##@vpc0##*/
/*##LABEL##@trainUpc1##*/
   /*##LABEL##@train.i0@END##*/

}


void rbm::activateVisibleUnits_train(u16 nh, u16 nv)
{
   // Calculate activation energy for visible units
   u16 v, h; //u16;
   DATA_sum_ sum;
   DATA_sum_ max;
   DATA01_D probs;
   DATA01_D RAND;
   DATA_pow pow2[K];
   DATA_sum3 sumOfpow2;
   s16 tmp;
   DATA_sum_ tmp1;
   bool tmp2;

      u16 j;//u16
   
   ACTIVATE_VISIBLE_TRAIN_V: //0
   for (v = 0; v < NUM_VISIBLE_MAX; v += K)
   {
      if (v == nv)
         break;
      // Get the sum of energies
      max = -500;
   ACTIVATE_VISIBLE_TRAIN_ENERGY:
      for (j = 0; j < K; j++)
      {
         sum = 0;
      ACTIVATE_VISIBLE_TRAIN_H:
         for (h = 0; h < NUM_HIDDEN_MAX + 1; h++)
         {

            if (h == nh + 1)
               break;

   /*##LABEL##@train.i1@END##*/
   
   /*##LABEL##@vpc0##*/
   /*##LABEL##@trainUpc1##*/
   
   /*##LABEL##@train.i1@START##*/

            tmp2 = hidden_unit[h];
            wait();
            tmp1 = (DATA_sum_)edges[v + j][h];
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

   /*##LABEL##@vpc1##*/
   /*##LABEL##@trainUpc1##*/
   
   /*##LABEL##@train.i1@END##*/

      max -= 31;  // 1
   ACTIVATE_VISIBLE_TRAIN_ENERGY_UPDATE:
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@train.i2@END##*/
   
   /*##LABEL##@vpc1##*/
   /*##LABEL##@trainUpc1##*/
   
   /*##LABEL##@train.i2@START##*/

         tmp1 = visibleEnergies[j];
         wait();
         DATA_sum_ ve_current = tmp1 - max;
         wait();
         visibleEnergies[j] = ve_current;
         wait();
      }

   /*##LABEL##@vpc2##*/
   /*##LABEL##@trainUpc1##*/
   /*##LABEL##@train.i2@END##*/

      sumOfpow2 = 0; // this is the numerator

   ACTIVATE_VISIBLE_TRAIN_SUM: // 2
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@train.i3@END##*/
   /*##LABEL##@vpc2##*/
   /*##LABEL##@trainUpc1##*/
   /*##LABEL##@train.i3@START##*/


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
         DATA_pow dp = ( to_int_exp(_c_16_15(tmp1) ) );

         sumOfpow2 += dp;
         pow2[j] = dp;
      }

   /*##LABEL##@vpc3##*/
   /*##LABEL##@trainUpc1##*/
   /*##LABEL##@train.i3@END##*/


      // Getting the probabilities
   ACTIVATE_VISIBLE_TRAIN_PROB: // 3
      for (j = 0; j < K; j++)
      {
   /*##LABEL##@train.i4@END##*/
   /*##LABEL##@vpc3##*/
   /*##LABEL##@trainUpc1##*/
   /*##LABEL##@train.i4@START##*/

         RAND = (rand()&0xffffffffffffffffL)/9223372036854775808.0;
         DATA_pow dp = pow2[j];
         wait();
         //probs = sld::udiv_func<32, 32, 64, 64, 64, 1>(dp, sumOfpow2);
       probs = divide( ((BIT_VEC)(dp))&0xffffffff , sumOfpow2);
         bool tmpb = 0;
         if (RAND < probs)
            tmpb = 1;
         visible_unit[v + j] = tmpb;
         wait();
      }
   }
   visible_unit[nv] = 1; // turn on bias
   wait();

   /*##LABEL##@vpc0##*/
   /*##LABEL##@trainUpc2##*/
   
   /*##LABEL##@train.i4@END##*/
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
   goto __Target_1;

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
   /*##LABEL##@upc@2##*/
      activateHiddenUnits_predict(pingpong, nh, nv); //getting preference
      return;

   /*##LABEL##@_target2##*/ 
         __Target_2:
   /*##LABEL##@predictUpc3##*/
      activateVisibleUnits_predict(nh, nv); //making rate based on existing edges value
      return;

   PREDICT_RATE:
   /*##LABEL##@upc@2##*/
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
}



void rbm::activateHiddenUnits_predict(bool pingpong, u16 nh, u16 nv)
{
   u16 h, v;
   DATA_sum_ sum, tmp;
   DATA01_D prob, tmp1;

   /*##LABEL##@_goto##*/ 

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


   /*##LABEL##@vpc0##*/
   /*##LABEL##@predictUpc0##*/
   
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

/*##LABEL##@vpc0##*/
/*##LABEL##@predictUpc1##*/
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
   
   /*##LABEL##@vpc0##*/
   /*##LABEL##@predictUpc1##*/
   
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

   /*##LABEL##@vpc1##*/
   /*##LABEL##@predictUpc1##*/
   
   /*##LABEL##@predict.i1@END##*/

      max -= 31;
   ACTIVATE_VISIBLE_PREDICT_ENERGY_UPDATE:
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@predict.i2@END##*/
   
   /*##LABEL##@vpc1##*/
   /*##LABEL##@predictUpc1##*/
   
   /*##LABEL##@predict.i2@START##*/

         tmp1 = visibleEnergies[j];
         wait();
         visibleEnergies[j] = tmp1 - max;
         wait();
      }

   /*##LABEL##@vpc2##*/
   /*##LABEL##@predictUpc1##*/
   /*##LABEL##@predict.i2@END##*/

      sumOfpow2 = 0; // this is the numerator
      //TODO: maximum exp of 300 k.1 added together, k>0
   ACTIVATE_VISIBLE_PREDICT_SUM:
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@predict.i3@END##*/
   /*##LABEL##@vpc2##*/
   /*##LABEL##@predictUpc1##*/
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

   /*##LABEL##@vpc3##*/
   /*##LABEL##@predictUpc1##*/
   /*##LABEL##@predict.i3@END##*/

      // Getting the probabilities
      expectation = 0.0;
   ACTIVATE_VISIBLE_PREDICT_PROB:
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@predict.i4@END##*/
   /*##LABEL##@vpc3##*/
   /*##LABEL##@predictUpc1##*/
   /*##LABEL##@predict.i4@START##*/

         DATA_pow dp = pow2[j];
         wait();
         //probs = sld::udiv_func<32, 32, 64, 64, 64, 1>(dp, sumOfpow2);
       probs  = dp/sumOfpow2;
         expectation += j * probs;
      }


   /*##LABEL##@vpc4##*/
   /*##LABEL##@predictUpc2##*/
   
   /*##LABEL##@predict.i4@END##*/

      prediction = round(expectation);
   ACTIVATE_VISIBLE_PREDICT_RATE:
      for (j = 0; j < K; j++)
      {

   /*##LABEL##@vpc4##*/
   /*##LABEL##@predictUpc2##*/
   
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



   /*##LABEL##@vpc0##*/
   /*##LABEL##@predictUpc2##*/
   
   /*##LABEL##@predict.i5@END##*/
}
