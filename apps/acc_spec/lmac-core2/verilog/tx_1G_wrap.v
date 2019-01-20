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


module tx_1G_wrap(
    x_clk,				  			   //i-1 for encap clk
    usr_rst_,			

    mac_addr0,						   //i-48 input from top-level to (psaddr) and rx
    mac_pause_value,				   //i-32 input from top-level to (mac_pause_value)
    tx_b2b_dly,			 			    //i-2  input from top-level to (tx_b2b_dly)
   	
    txfifo_dout,					   //i-64 input data from tx_fifo
    txfifo_empty,					   //i-1  indicates tx_fifo is empty 
    pre_txfifo_rd_en_1G,  			   //o-1  read data from tx_fifo
    
	rx_pause,						   //i-1  input from rx 
    rx_pvalue,						   //i-16 input from rx
	pre_rx_pack_1G,					   //o-1  output to rx

	xreq,							   //i-1  input from internal wire in tcore (assign xreq = 0)
	xon,				  			   //i-1  input from internal wire in tcore (assign xon = 0)
	pre_xdone_1G,					   //o-1  output to internal wire in tcore
	
    pre_gmii_txd,			  		   //o-8 data output to tcore
    pre_gmii_txc,			  		   //o-1 ctrl output to tcore
    PRE_FMAC_TX_PKT_CNT_1G,			   //o-32 output to tcore
    PRE_FMAC_TX_BYTE_CNT_1G,		   //o-32 output to tcore
    fmac_tx_clr_en	  				   //i-1 output to internal wire in tcore

    );
    
	input 			x_clk;
	input 			usr_rst_;

	//tx_encap interface
	input [47:0] 	mac_addr0;			   //i-48 input from top-level to (psaddr) and rx
	input [31:0] 	mac_pause_value;	    //i-32 input from top-level to (mac_pause_value)
	input [1:0]  	tx_b2b_dly;			  //i-2  input from top-level to (tx_b2b_dly)
	
	input [63:0] 	txfifo_dout;		   //i-64 input data from tx_fifo
	input 			txfifo_empty;		   //i-1  indicates tx_fifo is empty
	output 			pre_txfifo_rd_en_1G;   //o-1  read data from tx_fifo
	
	input 			rx_pause;			   //i-1  input from rx
	input [15:0] 	rx_pvalue;			   //i-16 input from rx
	output 			pre_rx_pack_1G;		   //o-1  output to rx
	
	input			xreq;				   //i-1  input from internal wire in tcore (assign xreq = 0)
	input			xon;				   //i-1  input from internal wire in tcore (assign xon = 0)
	output			pre_xdone_1G;		   //o-1  output to internal wire in tcore
	
	output [7:0] 	pre_gmii_txd;		   //o-8 data output to tcore
	output 			pre_gmii_txc;			//o-1 ctrl output to tcore
	output [31:0] 	PRE_FMAC_TX_PKT_CNT_1G;	  //o-32 output to tcore
	output [31:0] 	PRE_FMAC_TX_BYTE_CNT_1G;  //o-32 output to tcore
	input 			fmac_tx_clr_en;			  //i-1 output to internal wire in tcore
	
	wire [63:0] 	entx2ram_wdata;
	wire [15:0] 	rbytes;
	wire 			rts_1G;
	wire 			cts_1G;
	


gige_tx_encap gige_tx_encap(
	
	.clk					(x_clk),     			//i, 156.25 Mhz clock	
	.rst_					(usr_rst_),             //i,      	

	.rts					(rts_1G),               //o,          	
	.wdata					(entx2ram_wdata),       //o-64, data output from encap     	
	.rbytes					(rbytes),               //o-16, holds data size    	
     
	.cts					(cts_1G),				//i, from gmii		
	
	.psaddr					(mac_addr0),					
	.mac_pause_value 		(mac_pause_value),	
	.tx_b2b_dly				(tx_b2b_dly),           	
	                                   	
	.rx_pause				(rx_pause),               	
	.rx_pvalue				(rx_pvalue),           
	.rx_pack				(pre_rx_pack_1G),	
	                                   	
	.txfifo_empty 			(txfifo_empty),      	  //i, Indicates is FIFO is empty or not
    .txfifo_rd_en 			(pre_txfifo_rd_en_1G), 	  //o, read request from Gmii to FIFO
	.txfifo_dout 			(txfifo_dout),        	  //i,64 input data to encap
	                                   	
	.xreq					(xreq),						
	.xon					(xon),							
	.xdone					(pre_xdone_1G)					
	                        			
	); 
	
gige_tx_gmii gige_tx_gmii(

	.clk250					(x_clk),					  //i, clock
	.clk125					(x_clk),   	
	.rst_					(usr_rst_),		

	.rts					(rts_1G),    				 //i, to gmii from encap
	.rdata					(entx2ram_wdata),			 //i-64 input data from encap to gmii
	.rbytes					(rbytes),					 //i-16, holds data size in Bytes
	.cts					(cts_1G),					 //o,
	                            	
	.gmii_txd				(pre_gmii_txd),				  //o-64,
	.gmii_txc				(pre_gmii_txc),				  //o,
	.gmii_tx_en				(),		
	.gmii_tx_vld			(),		
	
	.FMAC_TX_PKT_CNT		(PRE_FMAC_TX_PKT_CNT_1G),  
	.FMAC_TX_BYTE_CNT		(PRE_FMAC_TX_BYTE_CNT_1G),	
	.fmac_tx_clr_en			(fmac_tx_clr_en)  
	
    );   
    
    
endmodule