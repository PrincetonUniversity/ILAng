#ifndef __RBM_H_
#define __RBM_H_

#include "systemc.h"
#include <ctos_flex_channels.h>

//This macro includes fixed-point into SystemC
#if defined(SC_FIXED_POINT)
#define SC_INCLUDE_FX
#endif

#if defined(__CTOS__) || defined(CTOS_MODEL) || defined(CTOS_SC_FIXED_POINT)
#include <ctos_fx/ctos_fx_macros.h>
#endif

#include <div.hpp>
#include "data.hpp"

SC_MODULE(rbm)
{
   sc_in<bool>       clk;        // clock
   sc_in<bool>       rst;        // reset

   // DMA requests interface from memory to device
   sc_out<u32>      rd_index;   // array index (offset from base address)
   sc_out<u32>      rd_length;  // burst size
   sc_out<bool>     rd_request; // transaction request
   sc_in<bool>      rd_grant;   // transaction grant
   //input data read by load
   b_get_initiator<u32>  data_in;    // input

   // DMA requests interface from device to memory
   sc_out<u32>      wr_index;   // array index (offset from base address)
   sc_out<u32>      wr_length;  // burst size (in words)
   sc_out<bool>     wr_request; // transaction request
   sc_in<bool>      wr_grant;   // transaction grant
   //output data wrtten by ourput
   put_initiator<u32>  data_out;   // output

   sc_out<bool>   done;

   sc_in<bool> conf_done;
   //input data by config
   sc_in<u32> conf_num_hidden;
   sc_in<u32> conf_num_visible;
   sc_in<u32> conf_num_users;
   sc_in<u32> conf_num_loops;
   sc_in<u32> conf_num_testusers;
   sc_in<u32> conf_num_movies;

   void config();
   void load();
   void store();
   void train_rbm();
   void predict_rbm();

   SC_CTOR(rbm)
      : clk("clk")
      , rst("rst")
      , rd_index("rd_index")
      , rd_length("rd_length")
      , rd_request("rd_request")
      , rd_grant("rd_grant")
      , data_in("data_in")
      , wr_index("wr_index")
      , wr_length("wr_length")
      , wr_request("wr_request")
      , wr_grant("wr_grant")
      , data_out("data_out")
      , done("done")
      , conf_done("cond_done")
      , conf_num_hidden("conf_num_hidden")
      , conf_num_visible("conf_num_visible")
      , conf_num_users("conf_num_users")
      , conf_num_testusers("conf_num_testusers")
      , conf_num_loops("conf_num_loops")
      , conf_num_movies("conf_num_movies")
   {
      ///config
      SC_CTHREAD(config, clk.pos());
      reset_signal_is(rst, false);
      ///load
      SC_CTHREAD(load, clk.pos());
      reset_signal_is(rst, false);
      ///compute
      SC_CTHREAD(train_rbm, clk.pos());
      reset_signal_is(rst, false);
      set_stack_size(0x500000);
      SC_CTHREAD(predict_rbm, clk.pos());
      reset_signal_is(rst, false);
      set_stack_size(0x500000);
      ///store
      SC_CTHREAD(store, clk.pos());
      reset_signal_is(rst, false);

      ///data channels
      data_in.clk_rst(clk, rst);
      data_out.clk_rst(clk, rst);
   }

   void activateHiddenUnits_train(bool pingpong, u16 nh, u16 nv);
   void activateVisibleUnits_train(u16 nh, u16 nv);
   void activateHiddenUnits_predict(bool pingpong, u16 nh, u16 nv);
   void activateVisibleUnits_predict(u16 nh, u16 nv);
   DATA01_D rand_gen();

   /// --- memory data structures ---
   ///input data
   u8 data[2][NUM_VISIBLE_MAX + 1];
   ///temporary
   bool visible_unit[NUM_VISIBLE_MAX + 1];
   bool hidden_unit[NUM_HIDDEN_MAX + 1];
   DATA_edge edges[NUM_VISIBLE_MAX + 1][NUM_HIDDEN_MAX + 1];
   bool pos[NUM_VISIBLE_MAX + 1][NUM_HIDDEN_MAX + 1];//u16 0/1
   bool neg[NUM_VISIBLE_MAX + 1][NUM_HIDDEN_MAX + 1];
   DATA_sum_ visibleEnergies[K]; //TODO: maximum 500 k.1 added together, k>0
   ///output data
   bool predict_vector[NUM_VISIBLE_MAX + 1];
   u8 predict_result[2][NUM_MOVIE_MAX];//max movies
   ///random generator numbers
   u32 mt[N];

   /// --- signals ---
   //Written by config_debayer
   sc_signal<u16>   num_hidden;
   sc_signal<u16>   num_visible;
   sc_signal<u16>   num_users;
   sc_signal<u16>   num_loops;
   sc_signal<u16>   num_testusers;
   sc_signal<u16>   num_movies;
   sc_signal<bool>  init_done;
   //Written by load_input
   sc_signal<bool>  train_input_done;
   sc_signal<bool>  predict_input_done;
   //Written by train_rbm
   sc_signal<bool>  train_start;
   sc_signal<bool>  train_done;
   sc_signal<int32> mti_signal;
   //Written by predict_rbm
   sc_signal<bool>  predict_start;
   sc_signal<bool>  predict_done;
   //Written by store_output
   sc_signal<bool>  output_start;
   sc_signal<bool>  output_done;
};

#endif
