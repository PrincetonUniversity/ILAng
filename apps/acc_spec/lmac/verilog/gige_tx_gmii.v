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

module gige_tx_gmii(
	clk250,			 // i-1
	clk125,   		// i-1
	rst_,  		   // i-1
	fmac_speed ,   //i-2
	
	rts,    	   // i-1
	rdata,  	   // i-64
	rbytes,		   // i-16
	cts,		   // o-1
	
	gmii_txd,		// o-8
	gmii_txc,		// o-1
	gmii_tx_en,		// o-1
	gmii_tx_vld,	// o-1
	linkup,			// i-1
	
	FMAC_TX_PKT_CNT,  		// o-32
	FMAC_TX_BYTE_CNT,		// o-32
	fmac_tx_byte_cnt_clr	// i-1	
	);

input clk250;		   
input clk125;
input rst_;
input [1:0] fmac_speed    ;	   //speed mode register. 

input   rts;				//request to send signal.
input   [63:0] rdata;
input   [15:0] rbytes;	   //Size of packet,
output	cts;			   // clear to send from gmii to encap.

output [7:0] gmii_txd;		   //0-8 1 byte output.
output 		 gmii_txc;		   // control output.
output 		 gmii_tx_en;	   
output 		 gmii_tx_vld;	   // To indicate valid data. 
input		 linkup;

output [31:0] FMAC_TX_PKT_CNT;		// counts the number of packet transmitted.
output [31:0] FMAC_TX_BYTE_CNT;		// total bytes transmitted.
input		  fmac_tx_byte_cnt_clr;
	
reg	   [63:0] pdin;			 // use this with gige_crc32x64 to support giving data that are not consec clk
reg    [63:0] bdata1;		 // buffer the incoming data
reg    [63:0] bdata2;		 //buffer twice the incoming data.
reg    [15:0] wcnt;			 //  write count.

wire	[15:0] nbytes;
reg  	[15:0] nbytes_reg;
reg 	[15:0] rbytes_reg;

reg    [63:0] txd;			  //data output of gmii. 
reg    [07:0] txc;			  //control output of gmii. 
reg    [07:0] txc_int;

reg    IDLE_sel;
reg    insert_crc;		   // Indication of inserting the crc frame. 

reg    crc_we_;
reg    crc_last_;		   
reg    crc_clr_;
reg    [15:0] crc_cnt;
wire   [31:0] crc32;	  // 32 bits crc. 

reg		sent;
reg		sent_dly;
reg		statistic_ok;
reg		[31:0]   pkt_transmitted;
reg		[31:0]   FMAC_TX_PKT_CNT;
reg 	[31:0]   accumulated_bcnt;
reg		[31:0]   FMAC_TX_BYTE_CNT;

wire    mode_1G   =   (fmac_speed == 2'b01) ;
wire    mode_100M =   (fmac_speed == 2'b10) ;
wire    mode_10M  =   (fmac_speed == 2'b11) ;

reg     [8:0] counter;
reg     pulse_0 ;
reg     pulse_1 ;

parameter[5:0] 
    IDLE		= 6'h01 ,
	GET_WAIT1   = 6'h02 ,
	GET_WAIT2   = 6'h04 ,
	TX_DAT		= 6'h08 ,
	TX_CRC		= 6'h10 ,
	WAIT_S		= 6'h20 ;
reg    [5:0] state;

wire st_IDLE;			assign	st_IDLE			=	state[0];
wire st_GET_WAIT1;  	assign	st_GET_WAIT1	=	state[1];
wire st_GET_WAIT2;  	assign	st_GET_WAIT2	=	state[2];
wire st_TX_DAT;     	assign	st_TX_DAT		=	state[3];
wire st_TX_CRC;        	assign	st_TX_CRC		=	state[4];
wire st_WAIT_S;			assign 	st_WAIT_S		=  	state[5];

wire st_DAT_0;
wire st_DAT_1;
wire st_DAT_4;
wire st_DAT_5; 
wire st_DAT_6;
wire st_DAT_7; 
reg  last_dat;

reg	[15:0] 	bcnt;
assign nbytes = {(rbytes[15:3] + |rbytes[2:0]),3'b000};

always@(posedge clk125)
begin
	bdata1 <=   (!rst_)? 64'hD5555555555555FB :
				mode_1G? rdata :
	            (pulse_0? rdata : bdata1);
	pdin  <= (!rst_)? 64'h0 :  
	       (crc_we_? pdin : rdata);     
	        
	bdata2 <=   (!rst_)? 64'hD5555555555555FB :
				mode_1G? bdata1 :
	            (pulse_0? bdata1 : bdata2);
	nbytes_reg <= (!rst_)? 16'b0 : 
				  mode_1G? nbytes :
	              (pulse_0? nbytes : nbytes_reg);
	rbytes_reg <= (!rst_)? 16'b0 :
				  mode_1G? rbytes :
	              (pulse_0? rbytes : rbytes_reg);
	
end

 //   FMAC_TX_PKT_CNT REGISTER
always@ (posedge clk125)
begin
	if (!rst_)
	begin
		sent	<=	1'b0;
		sent_dly <= 1'b0;
	end
	
	else
	begin
		sent	<=	mode_1G? (st_TX_CRC & st_DAT_4) :
		            (st_IDLE & st_DAT_5 & pulse_1);
		sent_dly <= mode_1G? sent :
		            (st_IDLE & st_DAT_6 & pulse_1);
	end
end

always@ (posedge clk125)
begin
	if (!rst_)
		pkt_transmitted	<=	32'h0;
	else
		pkt_transmitted	<=	(sent)? (pkt_transmitted + 32'h1) : pkt_transmitted ;
end

always @ (posedge clk250)
begin
	if (!rst_)
		statistic_ok <= 1'b0;
	else
		statistic_ok <= mode_1G? sent_dly :
		                (st_IDLE & st_DAT_7 & pulse_1);
		
end

always @ (posedge clk250)
begin
	if (!rst_)
		FMAC_TX_PKT_CNT <= 32'h0;
		
	else
		FMAC_TX_PKT_CNT <= statistic_ok? pkt_transmitted : FMAC_TX_PKT_CNT ;
end
// to store the accumulated total byte count of all the packets
always@ (posedge clk125)
begin
	if (!rst_ | fmac_tx_byte_cnt_clr)
		accumulated_bcnt	<=	32'h0;
	else
		accumulated_bcnt	<=	(sent)? (accumulated_bcnt + rbytes_reg) : accumulated_bcnt ;
end

always @ (posedge clk250)
begin
	if (!rst_ | fmac_tx_byte_cnt_clr)
		FMAC_TX_BYTE_CNT <= 32'h0;
		
	else
		FMAC_TX_BYTE_CNT <= statistic_ok? accumulated_bcnt : FMAC_TX_BYTE_CNT ;
end

always@(posedge clk125)
if(!rst_)
begin
	state <=   IDLE;
	txd   <=   64'hf7f7f7f7f7f7f7f7;   // IDLE for gmii interface (normal inter-frame)
	txc   <=   8'hff; 

	txc_int <=   8'hff;
	IDLE_sel  <=   1;
	insert_crc<=   0;

	wcnt <=   0;
	
	crc_we_ <=   1;
	crc_last_<=   1;
	crc_cnt  <=   0;
	crc_clr_ <=   1;
	
	last_dat <= 1'b0;	
end
else
begin		
	if (insert_crc)					 // insert the crc frame depending upon the valid data.
			begin 					//lower 3 bits of rbytes register stores the number of valid bytes in last qwd
			case (rbytes_reg[2:0])
			3'd0: txd <=   {32'hf7f7f7FD, crc32 };
			3'd1: txd <=   {64'hf7f7f7f7f7f7f7f7};
			3'd2: txd <=   {64'hf7f7f7f7f7f7f7f7};
			3'd3: txd <=   {64'hf7f7f7f7f7f7f7f7};
			3'd4: txd <=   {64'hf7f7f7f7f7f7f7FD};
			3'd5: txd <=   {32'hf7f7f7f7, 24'hf7f7FD, crc32[31:24] };
			3'd6: txd <=   {32'hf7f7f7f7, 16'hf7FD, crc32[31:16] };
			3'd7: txd <=   {32'hf7f7f7f7, 8'hFD, crc32[31:8] };
			endcase	
			end
		
	else
		begin					// before the crc frame, second last data frame according to the number of bytes valid.
		if((mode_1G & wcnt[15]& st_TX_DAT) | ((mode_100M | mode_10M) & wcnt[15] & st_TX_DAT & pulse_0) )
			begin
			case (rbytes_reg[2:0])
			3'd0: txd <=   {bdata2[63:32], bdata2[31:0] };
			3'd1: txd <=   {24'hf7f7FD, crc32[31:0], bdata2[7:0] };
			3'd2: txd <=   {16'hf7FD, crc32[31:0], bdata2[15:0] };
			3'd3: txd <=   {8'hFD, crc32[31:0], bdata2[23:0] };
			3'd4: txd <=   {crc32, bdata2[31:0]};
			3'd5: txd <=   {crc32[23:0], bdata2[39:0] };
			3'd6: txd <=   {crc32[15:0], bdata2[47:0] };
			3'd7: txd <=   {crc32[7:0], bdata2[55:0] };
			endcase
				
			end
		// if not last qwd
		else txd <= mode_1G? (st_TX_DAT? {bdata2[63:0]}: txd) :     
		            (st_TX_DAT? (pulse_0? {bdata2[63:0]}: txd) : txd);		     
		end
	
	txc <= mode_1G? txc_int :
	       (( (st_TX_DAT & pulse_0) || (st_TX_CRC & pulse_0) )?  txc_int : txc);
	
    insert_crc <= mode_1G? ((st_DAT_6 && last_dat)) :			//pulse indicating when to insert the crc frame
                  ((st_DAT_7 && pulse_1 && last_dat));
	
	crc_we_ <= mode_1G? (!(st_DAT_4 && !crc_cnt[15])) :
	           (!(st_DAT_5 && pulse_1 && !crc_cnt[15]));
	
	crc_last_ <= mode_1G? (!(st_DAT_4 && !crc_cnt[15] && wcnt[15])) :
	             (!(st_DAT_5 && pulse_1 && !crc_cnt[15] && wcnt[15]));
		
	crc_cnt <= mode_1G? (st_GET_WAIT1 ? (rbytes + 16'd7) : (st_TX_DAT? (crc_cnt - 16'd8) : crc_cnt)) :
	           ((st_GET_WAIT1 && pulse_0) ? (rbytes + 16'd7) : (st_TX_DAT? (pulse_0? (crc_cnt - 16'd8) : crc_cnt) : crc_cnt));
	
	crc_clr_   <=  mode_1G? (!(st_IDLE || st_TX_CRC)) :
	              ( (st_GET_WAIT1 & pulse_0)? 1'b1 :
	              (st_TX_CRC & st_DAT_7 & pulse_0)? 1'b0 :
	              crc_clr_);
    
	//state machine
	case(state)
	IDLE:
	begin
		state <= rts? GET_WAIT1: IDLE;
	end

	GET_WAIT1:
	begin
        state <= mode_1G? GET_WAIT2 :
                 ((pulse_0)? GET_WAIT2 : GET_WAIT1);
	end

	GET_WAIT2:
	begin
		state <= mode_1G? TX_DAT :
		         ((pulse_0)? TX_DAT : GET_WAIT2);
		
        wcnt     <= mode_1G? nbytes_reg - 16'd1 :
                    ((pulse_0)?  nbytes_reg - 16'd1 : wcnt);
        txc_int  <= mode_1G? 8'h01 :
                    ((pulse_0)? 8'h01 : txc_int);
        IDLE_sel <= mode_1G? 0 :
                    ((pulse_0)? 0 : IDLE_sel);
	end
	
	TX_DAT:
	begin
		state <= mode_1G? WAIT_S :
		         (pulse_0? WAIT_S : TX_DAT);
		
		wcnt <= mode_1G? wcnt - 16'd8 :
		        (pulse_0? wcnt - 16'd8 : wcnt);
		        
		last_dat <= mode_1G? wcnt[15] :
		            (pulse_0? wcnt[15] : last_dat);		
	end
	
	WAIT_S:
	begin
		state <= mode_1G? (st_DAT_6? (last_dat? TX_CRC : TX_DAT) : WAIT_S) :
		         (st_DAT_6? 
                         (|counter)? WAIT_S :
                         (last_dat? TX_CRC : TX_DAT) : 
                         WAIT_S);
		
		if ( (mode_1G & st_DAT_6) | ((mode_100M | mode_10M) & st_DAT_6 & pulse_0) )
		begin					//controls for the last qwd data
			if (wcnt[15]& last_dat)
				begin
				case (rbytes_reg[2:0])
				3'd0: txc_int <=   8'hF0;
				3'd1: txc_int <=   8'hFF;
				3'd2: txc_int <=   8'hFF;
				3'd3: txc_int <=   8'hFF;
				3'd4: txc_int <=   8'hFF;
				3'd5: txc_int <=   8'hFE;
				3'd6: txc_int <=   8'hFC;
				3'd7: txc_int <=   8'hF8;
				endcase
				end
			else
			begin		// control for the qwd if not last
			if (wcnt[15] & !last_dat)
				begin
				case (rbytes_reg[2:0])
				3'd0: txc_int <=   8'h00;
				3'd1: txc_int <=   8'hE0;
				3'd2: txc_int <=   8'hC0;
				3'd3: txc_int <=   8'h80;
				3'd4: txc_int <=   8'h00;
				3'd5: txc_int <=   8'h00;
				3'd6: txc_int <=   8'h00;
				3'd7: txc_int <=   8'h00;
				endcase
				end
			else txc_int <= 8'h00;
			end
		end
		
		else
			txc_int <=   txc_int; 
	end
	
	TX_CRC:		//after inserting CRC frame, wait if there is more data or else go to idle state.
	begin
		state <= mode_1G? (st_DAT_4? (rts? GET_WAIT1: IDLE) : TX_CRC) :
		         ((st_DAT_4 && pulse_0)? (rts? GET_WAIT1: IDLE) : TX_CRC);
		
		last_dat <= mode_1G? 1'b0 :
		            ((pulse_0)? 1'b0 : last_dat);
	end
		
	default:
	begin
		state <=   IDLE;
	end
	endcase
end

 // State machine that takes 64 bits data and output 8 bits at a time for gmii interface

parameter[8:0] 
	DAT_I  	= 9'h001 ,
	DAT_0	= 9'h002 ,
	DAT_1	= 9'h004 ,
	DAT_2	= 9'h008 ,
	DAT_3	= 9'h010 ,
	DAT_4	= 9'h020 ,
	DAT_5   = 9'h040 ,
	DAT_6   = 9'h080 ,
	DAT_7	= 9'h100 ;             
reg [8:0] gstate ;	// gmii state

wire 	st_DAT_I	= gstate[0];
assign 	st_DAT_0 	= gstate[1];
assign 	st_DAT_1 	= gstate[2];
assign 	st_DAT_4 	= gstate[5];
assign 	st_DAT_5 	= gstate[6];
assign 	st_DAT_6 	= gstate[7];
assign 	st_DAT_7 	= gstate[8];

reg [7:0] gmii_txd;						//output 8bit data 
reg 	  gmii_txc;						//output 1 bit control
reg		  gmii_tx_en;				
reg		  gmii_tx_vld;					//indicates valid data

reg		  cts;
reg		  gmii_start;					//pulse to start transmitting data
reg [7:0] idle1, idle2, idle3, idle4;

always @ (posedge clk125)
begin
	if (!rst_)
	begin
		cts <= 1'b0;
		gmii_start <= 1'b0;
		
		idle1 <= 8'hBC; 
		idle2 <= 8'hC5; 
		idle3 <= 8'hBC; 
		idle4 <= 8'h50;		
	end
	
	else
	begin
		cts <= mode_1G? (st_DAT_I & (idle3 == 8'h50)) :				//clear to send signal, for gige_encap showing gmii is ready to get data.
		       (st_DAT_I & (idle2 == 8'h50) & pulse_1);
		
		gmii_start <= mode_1G? (st_GET_WAIT2 | (st_DAT_6 & st_WAIT_S)) :
		              ((st_TX_DAT & pulse_1) | (st_DAT_7 & st_TX_CRC & pulse_1));
		
        idle1 <= mode_1G? (st_DAT_I? idle2 : 8'hBC) :
                (st_DAT_I? ((pulse_0)? idle2 : idle1) : 8'hBC);
		idle2 <= mode_1G? (st_DAT_I? idle3 : 8'hC5) :
		        (st_DAT_I? ((pulse_0)? idle3 : idle2) : 8'hC5);
		idle3 <= mode_1G? (st_DAT_I? idle4 : 8'hBC) :
		        (st_DAT_I? ((pulse_0)? idle4 : idle3) : 8'hBC);
		idle4 <= mode_1G? (st_DAT_I? idle1 : 8'h50) :
		        (st_DAT_I? ((pulse_0)? idle1 : idle4) : 8'h50);
	end
end

always@(posedge clk125)
if(!rst_)
begin
	gstate <= DAT_I;
	gmii_txd <= 8'hbc;
	gmii_txc <= 1'b1;
	gmii_tx_en	<=	1'b0;
	gmii_tx_vld	<=	1'b1;
   
	bcnt		<=	16'd0;
	
	pulse_0   <= 1'b0;
	pulse_1   <= 1'b0;
	
	//counter initilization 
	//for 100M count 10 clock cycle
	//for 10M count 100 clock cycle
	counter <= mode_1G? 8'd0 :
              (mode_100M? 8'd9 :
              8'd99);
end

else
begin                        
    gmii_tx_en	<=  mode_1G? ((gstate == DAT_I)? 1'b0 : (bcnt    ==    16'd0)?    1'b0    :    1'b1) :
                    ((bcnt != 16'd0 && st_DAT_0  && pulse_0)?  1'b1 : 
                       ((bcnt == 16'd0 & pulse_0 & (st_WAIT_S | st_TX_CRC | st_IDLE)))?  1'b0 : 
                       gmii_tx_en);
    
    gmii_tx_vld <=  mode_1G? (((bcnt	==	16'd1)|(bcnt	==	16'd0))?	1'b1	:	(!gmii_tx_en)) :
                    ((bcnt == 16'd1 && pulse_0)? 1'b1 :
                       (bcnt != 16'd0 && st_DAT_1  && pulse_0)?  (!gmii_tx_en) : 
                       gmii_tx_vld);
    
	counter <= mode_1G? counter :										//counter for different speed modes.
              (mode_100M? ((|counter)? counter - 8'd1 : 8'd9) :
              ((|counter)? counter - 8'd1 : 8'd99));
       
    pulse_0 <= mode_1G? pulse_0 : pulse_1; 
    pulse_1 <= mode_1G? pulse_1 : (counter == 8'd2);
    //state machine to output 8bits data.
	case(gstate)
	DAT_I:
	begin
		gstate <= gmii_start? DAT_0 : DAT_I;
        
        gmii_txd <= mode_1G? idle1 :
                    ((pulse_0)? idle1 : gmii_txd);
        gmii_txc <= mode_1G? (idle1 == 8'hbc) :
                    ((pulse_0)? (idle1 == 8'hbc) :gmii_txc);
        
		gmii_tx_en	<=	1'b0; 
		gmii_tx_vld	<=	1'b1; 
	
		//bcnt = 8 bytes (from start frame D555...55FB) + rbytes + 4 bytes CRC Data + 1 Byte for end frame (8'hFD)
		bcnt		<=	mode_1G? rbytes + 16'd13 :
		                ((pulse_0)? rbytes + 16'd13 : bcnt);

	end
	
	DAT_0:		 // Transmit Byte 0
	begin
		gstate <= mode_1G? DAT_1 :
		          (pulse_0? DAT_1 : DAT_0);
        
		gmii_txd <= mode_1G? txd[7:0] :
                    (pulse_0? txd[7:0] : gmii_txd);
        gmii_txc <= mode_1G? txc[0] :
                    (pulse_0? txc[0] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	DAT_1:	   // Transmit Byte 1
	begin
        gstate <= mode_1G? DAT_2 :
                  (pulse_0? DAT_2 : DAT_1);

		gmii_txd <= mode_1G? txd[15:8] :
		            (pulse_0? txd[15:8] : gmii_txd);
		gmii_txc <= mode_1G? txc[1] :
		            (pulse_0? txc[1] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	DAT_2:			// Transmit Byte 2
	begin
		gstate <= mode_1G? DAT_3 :
		          ((|counter)? DAT_2 : DAT_3);
        
        gmii_txd <= mode_1G? txd[23:16] :
                   (pulse_0? txd[23:16] : gmii_txd);
        gmii_txc <= mode_1G? txc[2] :
                    (pulse_0? txc[2] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	DAT_3:		   // Transmit Byte 3
	begin
		gstate <= mode_1G? DAT_4:
		          (pulse_0? DAT_4 : DAT_3);
		
		gmii_txd <= mode_1G? txd[31:24] :
		            (pulse_0? txd[31:24] : gmii_txd);
		gmii_txc <= mode_1G? txc[3] :
		            (pulse_0? txc[3] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));

	end
	
	DAT_4:			 // Transmit Byte 4
	begin
		gstate <= mode_1G? DAT_5 :
		          (pulse_0? DAT_5 : DAT_4);
        
		gmii_txd <= mode_1G? txd[39:32] :
		            (pulse_0? txd[39:32] : gmii_txd);
		gmii_txc <= mode_1G? txc[4] :
		            (pulse_0? txc[4] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));

	end
	
	DAT_5:			// Transmit Byte 5
	begin
		gstate <= mode_1G? DAT_6 :
		          (pulse_0? DAT_6 : DAT_5);
        
        gmii_txd <= mode_1G? txd[47:40] :
                    (pulse_0? txd[47:40] : gmii_txd);
        gmii_txc <= mode_1G? txc[5] :
                    (pulse_0? txc[5] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));

	end
	
	DAT_6:			 // Transmit Byte 6
	begin
		gstate <= mode_1G? DAT_7 :
		          (pulse_0? DAT_7 : DAT_6);
        	
        gmii_txd <= mode_1G? txd[55:48] :
                    (pulse_0? txd[55:48] : gmii_txd);
        gmii_txc <= mode_1G? txc[6] :
                    (pulse_0? txc[6] : gmii_txc);

        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                   ((bcnt == 16'd0)? 16'd0 : 
                   (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	DAT_7:			// Transmit Byte 7
	begin
        gstate <= mode_1G? ((gmii_start)? DAT_0 : DAT_I) :
                  (pulse_0? ((gmii_start)? DAT_0 : DAT_I) :
                  DAT_7);
		
		gmii_txd <= mode_1G? txd[63:56] :
		            (pulse_0? txd[63:56] : gmii_txd);
		gmii_txc <= mode_1G? txc[7] :
		            (pulse_0? txc[7] : gmii_txc);
		
        bcnt	<= mode_1G? ((bcnt == 16'd0)?	16'd0	:	(bcnt - 16'd1)) :
                               ((bcnt == 16'd0)? 16'd0 : 
                               (pulse_0? bcnt - 16'd1 : bcnt));
	end
	
	default:
	begin
		gstate <=  DAT_I;
	end
	endcase
end

gige_crc32x64 gige_crc32x64(
   	.clk(clk125),				//i, clock
   	.rst_(rst_),				//i, reset
	
   	.pulse_0(pulse_0),			//i, for slower speed modes
   	.pulse_1(pulse_1),			//i, for slower speed modes.
   	.mode_1G(mode_1G), 		
   	.mode_100M(mode_100M), 
   	.mode_10M(mode_10M),
   	.st_DAT_6(st_DAT_6),
   	.wcnt(wcnt),			
   	.crc_cnt(crc_cnt),
   	
   	.bytes  (rbytes_reg[2:0]),		//number of bytes valid in last qwd 	
   	.clr_  (crc_clr_),
   	.we_   (crc_we_),
   	.last_ (crc_last_),
   	.cdin  (rdata),
   	.pdin  (pdin),	
   	
   	.crc32({crc32[7:0],crc32[15:8],crc32[23:16],crc32[31:24]}),
   	.crc32_vld_()
    );
   
//synopsys translate_off
reg [(16 *8)-1:0] ascii_state, ascii_gstate;
always@(state)
begin
	case(state)
	IDLE: ascii_state = "IDLE";
	GET_WAIT1: ascii_state = "GET_WAIT1";
	GET_WAIT2: ascii_state = "GET_WAIT2";
	TX_DAT: ascii_state = "TX_DAT";
	TX_CRC: ascii_state = "TX_CRC";
	WAIT_S: ascii_state = "WAIT_S";
	default: ascii_state = "unknown";
	endcase
end

always@(gstate)
begin
	case(gstate)
	DAT_I: ascii_gstate = "DAT_I";
	DAT_0: ascii_gstate = "DAT_0";
	DAT_1: ascii_gstate = "DAT_1";
	DAT_2: ascii_gstate = "DAT_2";
	DAT_3: ascii_gstate = "DAT_3";
	DAT_4: ascii_gstate = "DAT_4";
	DAT_5: ascii_gstate = "DAT_5";
	DAT_6: ascii_gstate = "DAT_6";
	DAT_7: ascii_gstate = "DAT_7";
	default: ascii_state = "unknown";
	endcase
end
//synopsys translate_on
endmodule