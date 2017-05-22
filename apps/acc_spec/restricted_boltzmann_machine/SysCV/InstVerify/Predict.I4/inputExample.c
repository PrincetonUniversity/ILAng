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
   /*##LABEL##@upc@2##*/
      activateHiddenUnits_predict(pingpong, nh, nv); //getting preference
      return;

   /*##LABEL##@_target2##*/ 
         __Target_2:
   /*##LABEL##@predictUpc3##*/
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

   /*##LABEL##@upc@0##*/
   /*##LABEL##@upc@1##*/
   /*##LABEL##@upc@2##*/
   /*##LABEL##@upc@3##*/
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


   /*##LABEL##@_goto##*/ 

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
