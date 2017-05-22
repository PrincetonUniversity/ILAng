// Let's try some example
#include "rbm.hpp"

/*##LABEL##@_global##*/ 
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

   const u32 nv = num_visible.read();
   const u32 ntu = num_testusers.read();
   const u32 nu = num_users.read();
   const u32 nlp = num_loops.read();
   const u32 nm = num_movies.read();
   // std::cout<<"conf result: nv-ntu-nu-nlp"<<nv<<" "<<ntu<<" "<<nu<<" "<<nlp<<std::endl;
   u16 index = 0;
   u16 loop_count = 0;
   bool pingpong = 0;
   u16 tmp1, tmp2;
LOAD_FIRST_INPUT:
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
   do { wait(); /*##LABEL##@rdGrantInst@START@0##*/  }
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
      //cout<<data[i];
   }
   wait();
   data[pingpong][nv] = 1;

LOAD_INPUT_WHILE:
   while(true)
   {
     //??
      if ( loop_count != nlp ) //loading training data done
      {
         // 4-phase handshake with train
         train_input_done.write(true);
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
         do { wait(); }
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
       
         //cout<<data[i];
      }
      wait();
      data[pingpong][nv] = 1;


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

   /*##LABEL##@_goto##*/ 

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
      }

      output_done.write(true);

   }
}