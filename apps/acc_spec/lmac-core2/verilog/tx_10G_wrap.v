//
// Copyright (C) 2018 LeWiz Communications, Inc. 
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library release; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
// 
// LeWiz can be contacted at:  support@lewiz.com
// or address:  
// PO Box 9276
// San Jose, CA 95157-9276
// www.lewiz.com
// 
//    Author: LeWiz Communications, Inc.
//    Language: Verilog
//


// synopsys translate_off
`timescale 1ns/10ps
// synopsys translate_on


module tx_10G_wrap(
    usr_clk,				  	 //i-1 for gmii clk
    x_clk,				  	  	  //i-1	156.25 Mhz (really coreclkout)
    usr_rst_,				  
      
   	mode_10G ,				 //i-1, speed modes  
   	mode_1G ,				 //i-1, speed modes 
	mode_5G  ,				 //i-1, speed modes 
	mode_2p5G,				 //i-1, speed modes 

    mac_addr0,				 //i-48 input from top-level to (psaddr) and rx 
    mac_pause_value,		 //i-32 input from top-level to (mac_pause_value) 
    tx_b2b_dly,			 	 //i-2  input from top-level to (tx_b2b_dly) 
   	
    txfifo_dout,			  //i-64 input data from tx_fifo
    txfifo_empty,			  //i-1  indicates tx_fifo is empty   
    pre_txfifo_rd_en_10G,     //o-1  read data from tx_fifo
    
	rx_pause,				  //i-1  input from rx
    rx_pvalue,				  //i-16 input from rx
	pre_rx_pack_10G,		  //o-1  output to rx

	xreq,					   //i-1  input from internal wire in tcore (assign xreq = 0)
	xon,				       //i-1  input from internal wire in tcore (assign xon = 0)
	pre_xdone_10G,			   //o-1  output to internal wire in tcore
	
    xaui_mode,				   //i-1 input from internal wire in tcore (assign xaui_mode = 3'b000)
    
    pre_xgmii_txd,			   //o-64 data output to tcore
    pre_xgmii_txc,			   //o-8 ctrl output to tcore
    PRE_FMAC_TX_PKT_CNT_10G,   //o-32 output to tcore
    PRE_FMAC_TX_BYTE_CNT_10G,  //o-32 output to tcore
    
    fmac_tx_clr_en	  		   //i-1 output to internal wire in tcore
    
    );
    
	input 			usr_clk;
	input 			x_clk;
	input 			usr_rst_;
	
	input			mode_10G ;
	input			mode_1G  ;
	input			mode_5G  ;
	input			mode_2p5G;
	
	//tx_encap interface
	input [47:0] 	mac_addr0;
	input [31:0] 	mac_pause_value;
	input [1:0]  	tx_b2b_dly;
	
	input [63:0] 	txfifo_dout;
	input 			txfifo_empty;
	output 			pre_txfifo_rd_en_10G;
	
	input 			rx_pause;
	input [15:0] 	rx_pvalue;
	output 			pre_rx_pack_10G;
	
	input			xreq;
	input			xon;
	output			pre_xdone_10G;
	
	//tx_gmii interface
	input			xaui_mode;
	output [63:0] 	pre_xgmii_txd;
	output [7:0]	pre_xgmii_txc;
	output [31:0] 	PRE_FMAC_TX_PKT_CNT_10G;
	output [31:0] 	PRE_FMAC_TX_BYTE_CNT_10G;
	input 			fmac_tx_clr_en;
	
	wire [63:0] 	entx2ram_wdata;
	wire [15:0] 	rbytes;
	wire 			rts_10G;
	wire 			cts_10G;
	
	
	reg	mode_10G_buf ; 
	reg	mode_1G_buf  ; 
	reg	mode_5G_buf  ; 
	reg	mode_2p5G_buf; 

	
always @(posedge x_clk) 
	begin
	
		mode_10G_buf    <=	mode_10G ;
		mode_1G_buf    	<=	mode_1G ;
		mode_5G_buf     <=	mode_5G  ;
		mode_2p5G_buf	<=	mode_2p5G;
	
	end




tx_encap tx_encap(
	.clk					(x_clk),     			// i-1 	
	.rst_					(usr_rst_),             // i-1     
	 											   // i-3
	.mode_10G 				(mode_10G_buf), 		//i-1, speed modes	
	.mode_1G 				(mode_1G_buf), 			//i-1, speed modes	
	.mode_5G  				(mode_5G_buf), 			//i-1, speed modes	
                                  	        
	.rts					(rts_10G),               // o-1   
	.wdata					(entx2ram_wdata),        // o-64	   
	.rbytes					(rbytes),                // o-16   
 	
	.psaddr					(mac_addr0),				// i-48
	.mac_pause_value 		(mac_pause_value),			// i-32 
	.tx_b2b_dly				(tx_b2b_dly),           	// i-2 
	                                   	        
	.rx_pause				(rx_pause),               	// i-1
	.rx_pvalue				(rx_pvalue),             	// i-16
	.rx_pack				(pre_rx_pack_10G),          // o-1 
	                                   	        
	.txfifo_empty 			(txfifo_empty),      		 // i-1
    .txfifo_rd_en 			(pre_txfifo_rd_en_10G),      // o-1 
	.txfifo_dout 			(txfifo_dout),        		 // i-64
	                                   	         	
	.xreq					(xreq),						 // 	i-1
	.xon					(xon),						 // 	i-1
	.xdone					(pre_xdone_10G)				 // 	o-1
	                        			   	           	
	);
	  
tx_xgmii tx_xgmii(
	.clk250					(x_clk),					  // i-1
	.clk156					(x_clk),					  // i-1
	.rst_					(usr_rst_),					  // i-1
     
   	.mode_10G 				(mode_10G_buf), 			  // i-1
   	.mode_1G 				(mode_1G_buf), 				  // i-1
	.mode_5G  				(mode_5G_buf), 				  // i-1
	.mode_2p5G				(mode_2p5G_buf), 			  // i-1
                       									 
	.xaui_mode				(xaui_mode),					 // i-1
	
	.rts					(rts_10G),						  // i-1
	.rdata					(entx2ram_wdata),				   // i-64
	.rbytes					(rbytes),						    // i-16
	
	.cts					(cts_10G),						 //o-1
                            			
	.txd					(pre_xgmii_txd),				 // o-64, use this for OLDer TX_XGMII
	.txc					(pre_xgmii_txc),				 // o-8
	
	.FMAC_TX_PKT_CNT		(PRE_FMAC_TX_PKT_CNT_10G), 		  // o-32
	.FMAC_TX_BYTE_CNT		(PRE_FMAC_TX_BYTE_CNT_10G),		  // o-32
	.fmac_tx_clr_en			(fmac_tx_clr_en)				   // i-1
	); 
	
	
endmodule
