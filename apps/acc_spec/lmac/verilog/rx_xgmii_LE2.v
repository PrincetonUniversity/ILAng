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
`timescale 1ns / 1ns                                                                                                                                               
// synopsys translate_on

module tcore_rx_xgmii(
	clk156,						// i-1
	clk250,						// i-1
	rst_,						// i-1
                        		
	TCORE_MODE	,				//i-1
                    
	pkt_data	,		 		//o-64	Data output from xgmii
	pkt_start	,		 		//o-1   Indicates when the packet starts with valid data
	pkt_end		,		 		//o-1   Indicates when the packet ends. Ignores the end of packet pattern and CRC
	pkt_we		,		 		//o-1   Write enable signal for RX FIFO
	
	drx_pkt_data		,     	//o-64	Same as pkt_data
	drx_pkt_start 		,     	//o-1   Same as pkt_start
	drx_pkt_end 		,     	//o-1   Same as pkt_end
	drx_pkt_we 			,     	//o-1   Same as pkt_we
	drx_pkt_beat_bcnt	,  	  	//o-3   
	drx_pkt_be			,     	//o-8
	drx_crc32 			,     	//o-32
	drx_crc_vld 		,     	//o-1
	drx_crc_err 		,     	//o-1
	drx_crc_err_dly1 	,     	//o-1
	
	wen,						// o-1
	waddr,						// o-param
	wptr,						// o-param
	raddr_marker,				// i-param
	wdata,						// o-64
	                			
	rx_pause,					// o-1
	rx_pvalue,					// o-16
	rx_pack,					// i-1
	                			
	pause_en,					// i-1
	bcast_en,					// i-1
	pmode,						// i-1, promiscuous mode enable bit
	daddr0,						// i-48
	mcast_en,					// i-1
	mcast_saddr,				// i-48
             	
	rsize,						// i-12
	rxd,						// i-64 Input data from byte reordering module
	rxc,						// i-8  Input control corresponding to the data from byte reordering module
	br_sof4,					// i-1, byte_reordering's sof4_out
	rxp,						// i-8

	fmac_ctrl1_dly	,			//i-32, contains the max_pkt_size and enable
	fmac_rxd_en	,				//i-1, from TSPE_CTRL1  reg	                    		
	                    		
	FMAC_DCNT_OVERRUN,			// o-32  Indicates when the FIFO overrun
	FMAC_DCNT_LINK_ERR,			// o-32  Indicates when there is any link error
	FMAC_PKT_CNT_OVERSIZE, 		// o-32  Indicates when the incoming packet is more than 1518 bytes
	FIFO_OV_IPEND,				// o-1
	
	clr_pkt_cnt_oversize	,	//o-1
	
	add_lo_bcast	,		 	// o-1	for broadcast packet
	add_lo_mcast	,		 	// o-1  for multicast packet
	clr_carry_cast	,		 	// o-1
	add_hi_cast		,		 	// o-1
              	      
    vlan_ip,					//o-1   VLAN IP type packet
    normal_ip,					//o-1   Normal IP type packet
    non_ip,						//o-1   Neither VLAN nor Normal IP packet
    pkt_reject,					//o-1, EXTR use to drop the pkt at end
    pkt_jumbo_flag,				//o-1    (not used)
    pkt_ipver,					//o-4    (not used)
        
    wr_nbyte	,				//o-1   Indicates when nybytes should be written to the FIFO
    nbytes_out		,			//o-16, pkt byte cnt
    rxfifo_full					//i-1   Indicates that the rx fifo is full
	
	);

//These are parameters indiccated at instantiation
parameter	RX_DRAM_DEPTH = 3072;
parameter	RX_DRAM_ADDR_WIDTH = 12;

input 			clk156;				// i-1
input 			clk250;             // i-1
input 			rst_;               // i-1
      			                      
input 			TCORE_MODE	;       //i-1
      			                      
input 			pause_en;           // i-1
input 			bcast_en;           // i-1
input 			pmode;              // i-1
                                	
input	[47:0]	daddr0;            	// i-48

input       	mcast_en;			// i-1
input	[47:0]	mcast_saddr;		// i-48

input 			rx_pack;            // i-1
output 			rx_pause;           // o-1
output 	[15:0] 	rx_pvalue;          // o-16

output	[63:0]	pkt_data	;		//o-64
output			pkt_start	;		//o-1
output			pkt_end		;		//o-1
output			pkt_we		;

output	[63:0]	drx_pkt_data	;   //o-64          
output			drx_pkt_start ;     //o-1
output			drx_pkt_end ;       //o-1
output			drx_pkt_we ;        //o-1
output	[2:0]	drx_pkt_beat_bcnt;	//o-3
output	[7:0]	drx_pkt_be	;       //o-8
output	[31:0]	drx_crc32 ;         //o-32
output			drx_crc_vld ;       //o-1
output			drx_crc_err ;       //o-1
output			drx_crc_err_dly1 ;  //o-1

//output to the DRAM buffer where the pkt from the Ethernet port is 1st stored
output 								wen;                    	//o-1
output 	[RX_DRAM_ADDR_WIDTH-1:0] 	waddr;         				//o-param current DRAM buffer Write Addr
input  	[RX_DRAM_ADDR_WIDTH-1:0] 	raddr_marker;           	//i-param
output 	[RX_DRAM_ADDR_WIDTH:0] 		wptr; 						//o-param pointer of the start of the last pkt
output 	[63:0] 						wdata;                  	// o-64
                                                            	
input  	[63:0] 						rxd;                    	// i-64
input  	[07:0] 						rxc;                    	// i-8
input  	[07:0] 						rxp;                    	// i-8
input  	[11:0] 						rsize;                  	// i-12
input								br_sof4 ;               	// i-1
                                                            	
input 	[31:0]						fmac_ctrl1_dly;         	//i-32
                					                        	
input								fmac_rxd_en	;           	//i-1
                					                        	
output 	[31:0]						FMAC_DCNT_OVERRUN;      	// o-32
output 	[31:0]						FMAC_DCNT_LINK_ERR;     	// o-32
output 	[31:0]						FMAC_PKT_CNT_OVERSIZE;  	// o-32
output								FIFO_OV_IPEND;          	// o-1

input								clr_pkt_cnt_oversize	;	//o-1 control signal to clear the PKT_CNT_OVERSIZE reg

output								add_lo_bcast	;			// o-1, these signals are 250Mhz pre-synced
output								add_lo_mcast	;			// o-1                                     	
output								clr_carry_cast	;			// o-1 clr the carry of the B/Mcast group	
output								add_hi_cast		;			// o-1 add the HI reg of the B/Mcast group  	

output								vlan_ip ;                   //o-1
output								normal_ip ;                 //o-1
output								non_ip ;                    //o-1
output		    					pkt_reject;                 //o-1
output		    					pkt_jumbo_flag;				//o-1
output	[3:0]						pkt_ipver ;                 //o-4
      	
output								wr_nbyte	;               //o-1
output	[15:0]						nbytes_out		;           //o-16
input								rxfifo_full	;               //i-1

reg									wr_nbyte ;		   			//pulse if writing the NBYTE qwd
        							
wire								sof_n_eof ;
reg									sof_n_eof_dly1, sof_n_eof_dly2 ;

reg									pre_eof	;

reg		[13:0]						MAX_PKT_SIZE	;			//this is a dynamic parameter vary from system to system
reg									pkt_slice_en	;

parameter	[15:0]					MAX_RSVD_SIZE = (16'd1138 + 8'd16);			//MAX reserved size (=> jumbo pkt size) (regardless of the dynamic MAX_PKT_SIZE)
parameter	[15:0]					MAX_ALLOW		= (RX_DRAM_DEPTH - 8'd16)	;

reg		[RX_DRAM_ADDR_WIDTH-1:0] 	raddr_chk;  				// buffer the raddr_marker from rx_decap
   		
reg		[RX_DRAM_ADDR_WIDTH:0] 		wptr;
reg		[RX_DRAM_ADDR_WIDTH-1:0] 	wrusedw;					//current used qwd in the DRAM buffer

reg									wrfull	;					//if full do not write in any more new pkt until the old one had read out
reg									space_ok;

reg									has_pre_sof ;
reg		   							has_sof;					// use to detect a frame that has EOF but no SOF
reg		   							has_sof_dly1;

reg		   							valid_frame; 				// when see EOF, if does see that it has SOF, it is not valid

reg 	[03:0] 						bcnt;
reg									pre_sof;
reg 								sof;

reg 								sof_dly;
reg 								post_sof_dly;					//a 1 clk delay of SOF_DLY

reg									sof_pending ;					//must be quick enough to avoid racing conditions


reg 								rx_err0;
reg 								rx_err1;
reg 								err;
    								
reg 								eof0;
reg 								eof1;
wire 								eof;
wire								eof_qwd ;						//current incoming control qwd contains EOF (direct detect to be on time)
wire								eof_dqwd ;
reg									eof_dqwd_dly1 ;

reg 								eof_dly;
reg 								eof_dly2;

reg									ok_clk250	;
reg		[63:0] 						bdata1;
reg		[63:0] 						bdata2;
reg		[07:0] 						brxc1;

reg		[63:0]						pkt_data	;             		//same time as bdata2
reg									pkt_start, pkt_end, pkt_we ;

reg 	[15:0] 						nbytes, nbytes_out;
reg 	[63:0] 						wdata, pre_wdata;
reg 	[RX_DRAM_ADDR_WIDTH-1:0] 	waddr1; 
reg		   							b2b_pkt;						// indicate packets that have only 1 or no Idle gap in between
reg		  							reject;			

wire								pkt_reject = reject ;			//over all late rejection signal
reg									type_reject;					//protocol type reject

reg 	[RX_DRAM_ADDR_WIDTH-1:0] 	waddr, pre_waddr;  
reg 	[11:0] 						upd_cnt;

reg 								overwrite;
reg 								first_time;
reg  								wen1;
reg  								wen, pre_wen;
reg  								nowr;

reg 								daddr_hit0;
reg 								baddr_hit;
reg 								bcast_addr;						//if 1, MAC dest addr is broadcast addr
reg 								mcast_addr;

reg 								paddr_hit;

wire 	[47:0] 						chk_daddr_order;
wire 	[47:0] 						qchk_daddr_order;
     	       						
reg  	[31:0] 						chk_crc;
reg  	[15:0] 						rx_opcode;
reg  	[15:0] 						rx_type;
reg  	[15:0] 						rx_pvalue;
reg  	[47:0] 						chk_daddr;
reg  	[47:0] 						qchk_daddr;

reg  	[07:0]	 					rport;
reg  								mac_hit;
reg  								my_mac_hit;
reg  								mcast_hit;
     								
reg  								rx_pause;
reg  								sof_dly2;
reg  								opcode_pause;
reg  								port0_hit;
reg  								pmode_hit;

reg									vlan_ip	;
reg 								pppoe_ip ;
reg 								normal_ip ;
    								
reg									isl_frame ;

reg 	[3:0] 						pkt_ipver;
wire 								pkt_jumbo_flag;
reg 	[47:0]		 				mac_saddr ;
wire       							mac_saddr_vld  ;
wire       							saddr_filter_drop ;
reg 								saddr_filter_drop_flag ;

reg		[2:0]						count8 		;
reg									count8_en1 	;
reg									count8_en2 	;
reg									count8_en3  ;
reg		[63:0]						qwd0_data_dly1 	;
reg									qwd0_time	;    	 				//for 10G it's SOF time, for 1G, this is immediately after 1st qwd
                					
wire	[1:0]						fmac_speed 	= fmac_ctrl1_dly[17:16] ;
reg									xaui_mode;

assign	sof_n_eof	= sof & (eof & has_sof) ;							//both same time

assign chk_daddr_order = {chk_daddr[7:0],chk_daddr[15:8],chk_daddr[23:16],chk_daddr[31:24],chk_daddr[39:32],chk_daddr[47:40]};
assign qchk_daddr_order = {qchk_daddr[7:0],qchk_daddr[15:8],qchk_daddr[23:16],qchk_daddr[31:24],qchk_daddr[39:32],qchk_daddr[47:40]};

wire advance_wptr;


assign	advance_wptr = 
				//valid_frame is too late for sof_n_eof case (pre gated has_sof)
			!wrfull &  sof_n_eof                & mac_hit & !reject               & !overwrite & !saddr_filter_drop_flag |
			!wrfull & !sof_n_eof_dly1 & eof_dly & mac_hit & !reject & valid_frame & !overwrite & !saddr_filter_drop_flag ;

//2nd set of pre-detections for the packet
//7 reserved bits
wire	[7:0]	pre_stat2 = {isl_frame, 7'h0 };

always@(posedge clk156)
begin

	xaui_mode	<= (fmac_speed == 2'b00);

	bdata1   <=   rxd;
	bdata2   <=   bdata1;
		//control bytes, if all 0, has data otherwise control is presence
	brxc1    <=   rxc;
	
	pre_wdata    <=   
		//write the special parameter immediately after EOF
		//rport field is not used, and being used for pre_stat2
		//ETHER_TYPE field becomes the LEN field for ISL_FRAME, so need to gate this
		//  in IP detections.  Cannot gate at the start of the pkt due to timing events
																	
		(sof_n_eof |
		!sof_n_eof_dly1 & eof_dly ) ? {chk_crc,									
						{ (vlan_ip & !isl_frame), pkt_jumbo_flag,				
								(pppoe_ip & !isl_frame), (normal_ip & !isl_frame),
										pkt_ipver},								
							pre_stat2,											
							nbytes} : 											
							//otherwise write in the incoming data
							bdata2;
							
	wdata	<= pre_wdata ;
	
	//saving away the pkt's original CRC for checking later
	if(eof0 || eof1)
		//hold if EOF
		chk_crc <=   chk_crc;
	else
		//getting new values in
	begin
		//add 1G support
		if (xaui_mode)
			//data valid each clock
			case(brxc1)
			//extract the 32 bit CRC field continuously
			//if current incoming has only 1 byte (in BDATA1)
			//take the current byte, combine with previous 3 bytes
			8'hfe: chk_crc <=   {bdata1[7:0], bdata2[63:40]};
			8'hfc: chk_crc <=   {bdata1[15:0],bdata2[63:48]};
			8'hf8: chk_crc <=   {bdata1[23:0],bdata2[63:56]};
			8'hf0: chk_crc <=   bdata1[31:0];
			8'he0: chk_crc <=   bdata1[39:8];
			8'hc0: chk_crc <=   bdata1[47:16];
		8'h80: chk_crc <=   bdata1[55:24];	//7 bytes, take last 4 bytes
		default: chk_crc <=   bdata2[63:32];	//8 bytes, take last 4 bytes
			endcase
		else
			//gige must use chk_crc (32bit) since BDATA2 is not correct
			//data valid each 8th clk
			case(brxc1)
			8'hfe: chk_crc <=   {bdata1[7:0], chk_crc[31:8]};
			8'hfc: chk_crc <=   {bdata1[15:0],chk_crc[31:16]};
			8'hf8: chk_crc <=   {bdata1[23:0],chk_crc[31:24]};
			8'hf0: chk_crc <=   bdata1[31:0];
				//some CRC code is in upper data
			8'he0: chk_crc <=   bdata1[39:8];
			8'hc0: chk_crc <=   bdata1[47:16];
			8'h80: chk_crc <=   bdata1[55:24];
			8'h00: chk_crc <=   bdata1[63:32];
			default: chk_crc <=  chk_crc;
			endcase
		
	end
	
	//counting the byte of the current BDATA1
	case(brxc1)
	8'hfe: bcnt <=   4'd1;
	8'hfc: bcnt <=   4'd2;
	8'hf8: bcnt <=   4'd3;
	8'hf0: bcnt <=   4'd4;
	8'he0: bcnt <=   4'd5;
	8'hc0: bcnt <=   4'd6;
	8'h80: bcnt <=   4'd7;
	8'h00: bcnt <=   4'd8;		
		//control word can have DATA pattern h55 & cannot be counted as 8
	default: bcnt <=   4'd0;
	endcase
	
	//for GigE support
	qwd0_data_dly1	<= 
		!rst_ ? 64'h0 :
		(qwd0_time & !xaui_mode) ? bdata1[63:0] : 
		qwd0_data_dly1;
	
		//latching dest MAC addr
	chk_daddr <=   
		!rst_ ? 48'h0 :		
		//10G case
		(sof_dly & xaui_mode) ? bdata2[47:0] : 
		//1G case
		(qwd0_time & !xaui_mode) ? bdata1[47:0] : 
		//hold
		chk_daddr;
	port0_hit <=   daddr_hit0;
		//incoming MAC addr matches MAC ADDR (daddr0)
	daddr_hit0<=   (chk_daddr_order == daddr0);
		//Broadcast dest addr all F
	baddr_hit <=   (&chk_daddr) & bcast_en;
	
	bcast_addr	<=	(!rst_) ? 1'b0 : (&chk_daddr)	;
		//01-00-5E-{1'b0, 23 bit multicast group address}
	mcast_addr	<=	(!rst_) ? 1'b0 : ( chk_daddr_order[47:23] == {24'h01005E, 1'b0} );
	
	//------------ 11oct13 - FAST checking of dest MAC ADDR
	qchk_daddr <=   
		!rst_ ? 48'h0 :			
		rxd[47:0] ; 

	my_mac_hit	<=
		!rst_ |		
		TCORE_MODE & sof & (qchk_daddr_order[47:23] == {24'h01005E, 1'b0}) ? 1'b0 :		//mcast in TCORE_MODE
		
		sof & (qchk_daddr_order == daddr0) |											//uni
		sof & (&qchk_daddr_order) |														//bcast, all 1's
		!TCORE_MODE & sof & (qchk_daddr_order[47:23] == {24'h01005E, 1'b0}) ? 1'b1 :	//mcast
		sof & (qchk_daddr_order != daddr0) ? 1'b0 :										//uni
		my_mac_hit
		;
		
	mcast_hit	<=
		!rst_ ? 1'b0 :	
		sof & (qchk_daddr_order[47:23] == {24'h01005E, 1'b0}) ? 1'b1 :					//mcast
		mcast_hit
		;
	
	paddr_hit <=   (chk_daddr_order == 48'h0180C2000001) && (rx_type == 16'h8808);
	
	opcode_pause <=   (rx_opcode == 16'h0001);
	
		//detect Inter-Switch Link frame (ISL frame)
		//these are special multicast addr
		//chk_daddr_order is the same time as chk_daddr but re-wired to the correct order
	isl_frame	<= 
		(!rst_) ? 1'b0 : 
			//must keep the value until EOF_DLY
			//clear at the start of each frame to avoid spill over problems
		(pre_sof) ? 1'b0 : 
		(sof_dly2 ) &		
				( ( chk_daddr_order[47:8] == 40'h01000C_0000) |
				  ( chk_daddr_order[47:8] == 40'h03000C_0000) ) ? 1'b1 :
		isl_frame ;
			
end

assign eof = (eof0 || eof1);

wire 	[RX_DRAM_ADDR_WIDTH:0]	wptr_plus_upd_cnt;	//wptr plus updated count
wire	[RX_DRAM_ADDR_WIDTH:0]	new_wptr;
wire 	[RX_DRAM_ADDR_WIDTH:0]	new_wptr_plus1;

				//UPD_CNT is the number of QWD in the current pkt
				//the addr of the DRAM buffer is in QWD
assign			wptr_plus_upd_cnt = wptr + upd_cnt;
					//new pkt write ptr, ie the pkt after this current one
					//detect wrap around if old pkt length + current start location
					//  exceed the RAM max depth
					//if wrap, go to the DELTA location since RAM starts at addr 0 (a wrap does not need to inc 1)
					//normally not wrap so just incr by the update count of the current pkt
assign		    new_wptr = (wptr_plus_upd_cnt > (RX_DRAM_DEPTH-1))? (wptr_plus_upd_cnt - RX_DRAM_DEPTH) : wptr_plus_upd_cnt ;

assign 			new_wptr_plus1 = (wptr_plus_upd_cnt >= (RX_DRAM_DEPTH-1))? (wptr_plus_upd_cnt - (RX_DRAM_DEPTH-1)) : (wptr_plus_upd_cnt + 1);

wire	[RX_DRAM_ADDR_WIDTH:0]	wptr_plus1;

assign			wptr_plus1 = (wptr == (RX_DRAM_DEPTH-1))? 0 : (wptr[RX_DRAM_ADDR_WIDTH-1:0] + 8'd1);

wire	[RX_DRAM_ADDR_WIDTH-1:0]	waddr1_plus1;
							//if waddr1== BFF wrap to 0, otherwise add as normal
assign			waddr1_plus1	=	(waddr1 == (RX_DRAM_DEPTH-1))? 0 : (waddr1 + 8'd1);

always @ (posedge clk156)
begin
	//indicating very first pkt written into the DRAM buffer
	first_time	 <=		
		//reset (indicating 1st pkt)
		(!rst_ | !fmac_rxd_en)? 1'b1 : 
		//if wptr incremented, negate
		((wptr != 0)? 1'b0 : 
		//hold
		first_time);
		
end

//---------- PRE-detect some critical events ------------

assign	eof_qwd =  	(brxc1[0] && (bdata1[7:0] == 8'hFD))   || 
					(brxc1[1] && (bdata1[15:8] == 8'hFD))  || 
					(brxc1[2] && (bdata1[23:16] == 8'hFD)) || 
					(brxc1[3] && (bdata1[31:24] == 8'hFD)) ||
					
	         		(brxc1[4] && (bdata1[39:32] == 8'hFD)) || 
					(brxc1[5] && (bdata1[47:40] == 8'hFD)) || 
					(brxc1[6] && (bdata1[55:48] == 8'hFD)) || 
					(brxc1[7] && (bdata1[63:56] == 8'hFD));
	//EOF but contains data
					
assign	eof_dqwd =  eof_qwd & ( (brxc1 == 8'hE0) | (brxc1 == 8'hC0) | (brxc1 == 8'h80) ) ; 


always@(posedge clk156)
if( !rst_ | !fmac_rxd_en )
begin
	eof_dqwd_dly1	<= 1'b0;
	
	raddr_chk <=   0;
	wr_nbyte       <=   1'b0;
	pre_wen       <=   1'b0;
	wen       <=   1'b0;
	wen1      <=   1'b0;
	pre_sof	  <=   1'b0;
	sof       <=   1'b0;
	sof_pending       <=   1'b0;				
	
	eof0      <=   1'b0;
	eof1      <=   1'b0;
	err       <=   1'b0;
	nbytes    <=   16'h0;
	nbytes_out    <=   16'h0;
	rx_err0   <=   1'b0;
	rx_err1   <=   1'b0;

	eof_dly   <=   1'b0;
	eof_dly2  <=   1'b0;
	overwrite <=   1'b0;
	wptr      <=   0;
	upd_cnt   <=   12'h0;
	waddr1    <=   0;
	b2b_pkt	  <=   1'b0;
	reject	  <=   1'b0;
	waddr     <=   0;
	pre_waddr     <=   0;
	
	wrfull		<= 1'b0;
	wrusedw		<= 0;
	space_ok	<= 1'b1;
	
	nowr      <=   1'b0;
	sof_dly   <=   1'b0;
	post_sof_dly   <=   1'b0;
	
	sof_dly2  <=   1'b0;
	mac_hit   <=   1'b0;
	rx_pvalue <=   16'h0;
	rx_pause  <=   1'b0;
	rx_opcode <=   16'h0;
	rx_type   <=   16'h0;
	rport     <=   8'h0;
	pmode_hit <=   1'b0;
	has_pre_sof		<=	1'b0;
	has_sof		<=	1'b0;
	has_sof_dly1		<=	1'b0;
	
	valid_frame	<=	1'b0;
	
	count8 		<= 3'd7;
	count8_en1 	<= 1'b0;
	count8_en2 	<= 1'b0;
	count8_en3  <= 1'b0;
	qwd0_time	<= 1'b0;
	
end
else
begin

	raddr_chk <=  raddr_marker; 
	pmode_hit <=   pmode;
	
	rx_pause  <=   rx_pause ? !rx_pack : ((pause_en && !rport[0])? (eof_dly2 && paddr_hit && opcode_pause) : 1'b0);
	rx_opcode <=   (sof_dly)  ? {bdata1[55:48],bdata1[63:56]} : rx_opcode;	//for PAUSE frame
		//Ethernet Type field
	rx_type   <=   (sof_dly)  ? {bdata1[39:32],bdata1[47:40]} : rx_type;
	
	rx_pvalue <=   (sof_dly2) ? {bdata1[7:0],bdata1[15:8]} : rx_pvalue;
	mac_hit   <=   (port0_hit || baddr_hit || pmode_hit) && !paddr_hit;
	rport     <=   sof ? rxp : rport;	
	
	sof_dly   <=   
		xaui_mode ? sof :
		//gige support (note the count8 is 1 clk behind)
			//gige may need to recheck due to changes in byte_reorder(5jun13)
		(count8 == 3'd2) & count8_en2
		;
		
	post_sof_dly  <=   sof_dly;
	
	sof_dly2  <=   
		xaui_mode ? sof_dly :
		//gige support (note the count8 is 1 clk behind)
		(count8 == 3'd2) & count8_en3
		;
		//do not write on error codes
		//if the last incoming qwd is 4 bytes, 3 bytes, 2 bytes, or 1 byte
		//  ie the last qword contain only CRC info
	nowr      <=   (brxc1[7:0] == 8'hf0) || (brxc1[7:0] == 8'hf8) || (brxc1[7:0] == 8'hfc) || (brxc1[7:0] == 8'hfe);
	
		//pkt length in QWD count
		//NBYTE is the number of bytes in the current pkt
		// UPD_CNT = updated qwd count
		//if NBYTE has some extra bytes, add the extra qwd
		//this is used in calculating the next wptr
		//increment as pkt's qwd coming in
		//dynamic qwd cnt, increment on each qwd coming in
	upd_cnt   <=   
		//if NBYTE has extra bytes (not even number of qwd), add 2 qwds
		(|nbytes[2:0]) ? (nbytes[14:3] + 12'd2) : 	 
		//otherwise add 1 qwd
		(nbytes[14:3] + 12'd1);  	 // only need bits [14:0] to represent 16384 bytes
		
	overwrite	<= 1'b0 ;
	
	wr_nbyte	<=
		( wr_nbyte ) ? 1'b0 :
		//VERY last write (1 pulse), write in the NBYTE (if not rejected)
		(sof_n_eof & my_mac_hit & !type_reject |
		!sof_n_eof_dly1 & eof_dly & has_sof_dly1 & my_mac_hit & !type_reject ) ? 1'b1 : 
		1'b0 ;
		
	
	wen			<= pre_wen ;
	
	pre_wen     <=   
		//last data write for data mixing in EOF qwd (no CRC write.  Last eof_dqwd may have 1, 2, or 3 bytes)
		eof_dqwd_dly1 & space_ok & has_sof ? 1'b1 :
		//follows WEN1 pulse if
			//gating with sof_pending to avoid erroneous writes during boot or driver load
			//writing of the pkt
		(wen1 & sof_pending & space_ok
			//no error
			& !err & !rx_err0 & !rx_err1 
			//not overflow
			& !overwrite 
			//not start or end of frame or no write conditions
			//this prevents the PRE-AMBLE from writing in
			& !(sof |(nowr & eof)));
			
		//write en 1 if all lanes are good data (this is during the data phase, not begin or end)
		//WEN1 matched to BDATA1 timing (except for the very 1st pkt, or after long gap between pkts)
	wen1      <=   fmac_rxd_en & has_pre_sof 
						& !(&brxc1) 	
						& ( !eof_qwd  )
						& !err;
						
		//this is the WADDR for the DRAM buffer
		//WADDR1 is the consecutive writing (inc by 1 each time)
		//WPTR is the addr where the length of the packet is written if end_of_frame is reached
		//		WPTR is aligned to Qword
	pre_waddr     <=   
		//1st DRAM write addr is the WPTR aligned to Qwd
			//if full just keep the waddr
			(wrfull ) ? pre_waddr :
			//at end of normal write cycle, write the last one (NBYTE) to the beginning
			//cannot use EOF here due to uneven Qwd pkt
			(sof_n_eof |			
			!sof_n_eof_dly1 & eof_dly & !reject )  ? wptr[RX_DRAM_ADDR_WIDTH-1:0] : 
			//during write, keep if not OK (space OK does not change during the pkt)
			(!space_ok ) ? pre_waddr :
			//increment during write
		//subsequent write follows waddr1
			//increment during write
			waddr1;
			
	waddr	<= pre_waddr ;
			
			//should only check at EOF.  No because always guarantee enough space for a pkt at the beginning
	wrfull		<= rxfifo_full;
	
	wrusedw		<=		//TRUE WRUSEDW
		//init at reset time
		//NOTE:  raddr_chk may change on a clk basis during some interval
		//add during write, subtract on read out
		//just use the old raddr for calc the used size.  If raddr increment late it just implies we have
		//less available space than we actualy have
			//normal condition
		!(raddr_chk > wptr) ? (wptr - raddr_chk) :
		wptr + (RX_DRAM_DEPTH - raddr_chk)
		;
		
	space_ok	<= !rxfifo_full ;
	
	//back 2 back pkt, if next pkt (pre_sof) come in while previous GOOD pkt ending
	//pre_sof is of current pkt; has_sof_dly1 is of previous good pkt
	b2b_pkt	  <=   pre_sof & has_sof_dly1 & (eof | eof_dly);
	
	reject	  <=   
		//reject current data if EOF and got error or not enough space
			//not mac_hit must drop (if pmode, it will hit)
		eof ? (err | rx_err0 | rx_err1 | overwrite | !space_ok | !mac_hit) : 
		//clear
		(eof_dly2? 1'b0 : 
		//hold
		reject);
		
		
	has_pre_sof		<=	pre_sof? 1'b1: 	//assert
						(eof & !sof ? 1'b0 : 	//negate at the end
						has_pre_sof);		//hold
						
	has_sof		<=	sof? 1'b1: 	//assert
						(eof? 1'b0 : 	//negate at the end
						has_sof);		//hold
						
	has_sof_dly1	<= has_sof ;
							
		//only assert from EOF to EOF_DLY2 for advancing the WPTR
	valid_frame	<=	
		eof? has_sof : 
		eof_dly2? 1'b0 : 	
		valid_frame ; 
	
	err       <=   
		//clear
		pre_sof ? 1'b0 : 
		//capture error conditions
		(rx_err0 || rx_err1 || err); 
	eof_dly   <=   eof;
	eof_dly2  <=   eof_dly;
	
		//for XGMII (aligned data), FB only happens on lane 0
	pre_sof	  <=   (rxc[0] && (rxd[7:0] == 8'hFB)) | br_sof4 ;
		
	sof		  <=	pre_sof & fmac_rxd_en;
	
	sof_pending	<=
		//keep negate if NOT RXD enabled
		!fmac_rxd_en ? 1'b0 :
		//assert if seen SOF
		pre_sof & fmac_rxd_en ? 1'b1 :
		//negate on EOF
		eof & !sof ? 1'b0 :	//if got sof must keep 1
		//hold
		sof_pending ;
	
	eof0      <=   	fmac_rxd_en & (brxc1[0] && (bdata1[7:0] == 8'hFD))   || 
					fmac_rxd_en & (brxc1[1] && (bdata1[15:8] == 8'hFD))  || 
					fmac_rxd_en & (brxc1[2] && (bdata1[23:16] == 8'hFD)) || 
					fmac_rxd_en & (brxc1[3] && (bdata1[31:24] == 8'hFD));
					
	eof1      <=   	fmac_rxd_en & (brxc1[4] && (bdata1[39:32] == 8'hFD)) || 
					fmac_rxd_en & (brxc1[5] && (bdata1[47:40] == 8'hFD)) || 
					fmac_rxd_en & (brxc1[6] && (bdata1[55:48] == 8'hFD)) || 
					fmac_rxd_en & (brxc1[7] && (bdata1[63:56] == 8'hFD));
	
		//link err
	rx_err0   <=   (brxc1[0] && (bdata1[7:0] == 8'hFE)) || (brxc1[1] && (bdata1[15:8] == 8'hFE)) || (brxc1[2] && (bdata1[23:16] == 8'hFE)) || (brxc1[3] && (bdata1[31:24] == 8'hFE));
	rx_err1   <=   (brxc1[4] && (bdata1[39:32] == 8'hFE)) || (brxc1[5] && (bdata1[47:40] == 8'hFE)) || (brxc1[6] && (bdata1[55:48] == 8'hFE)) || (brxc1[7] && (bdata1[63:56] == 8'hFE));
	
		//bcnt is the byte cnt of each received QWD
		//but skip 1st 4 bytes in the count (ie pre-skip the CRC bytes)
	nbytes    <=   
		//init
		sof ? 16'hfffc : 
		//norm - adding the byte cnt coming in (dynamic)
		(wen1 |
			//ending, compensate for extra bytes in odd cases due to pre-skip of CRC
			eof & (bcnt < 8'd8) ? (nbytes + bcnt) :
		//hold
		nbytes);
		
	nbytes_out	<= nbytes	;
	
		//if got a good pkt advance wptr, else hold
		//don't advance if wrfull
		//only advance at end of a packet to guarantee the DECAP that it has a complete pkt
		//if wrap waddr1 should also wrap
		//advance at EOF_DLY time if the frame is valid
	wptr[RX_DRAM_ADDR_WIDTH-1:0]      <=   advance_wptr ? waddr1 : wptr;
	
	//============= FOR 1G SUPPORT
		//count every 8 clks (for assembling to 64 bits)
	count8 		<= (count8_en1 | count8_en2 | count8_en3)? (count8 - 3'd1) : 3'd7 ;
		//tracking 1st qwd (qwd0)
	count8_en1 	<= 
		//see SOF assert
		sof? 1'b1 : 
		//negate if signal currently tracking is asserted
		(qwd0_time? 1'b0 : 
		//hold
		count8_en1);
	count8_en2 	<= 	//tracking qwd1_time or same as SOF_DLY
		qwd0_time? 1'b1 : 
		(sof_dly ? 1'b0 : 
		count8_en2);
	count8_en3 	<= 
		sof_dly ? 1'b1 : 
		(sof_dly2? 1'b0 : 
		count8_en3);
	
	qwd0_time   <=   (count8 == 3'd2) & count8_en1;		//qwd0 time
	
	
	if (sof_n_eof )
		waddr1	<= waddr1 + 4'd1 ;
	else
	casez ({eof_dqwd_dly1, wrfull, sof, b2b_pkt, reject, wen1, has_sof})
		7'b0010??? :	waddr1	<=	wptr_plus1 ;		// restart, 2 or more gap between packets, wptr is already valid
		
		7'b00111?? :	waddr1	<=	wptr_plus1 ;		// 1 or 0 gap between packets but drop the packet, restart
		
		
		
		7'b00110?? : 	waddr1	<=	waddr1_plus1;		// 1 or 0 gap between packets, wptr is not valid yet, 
		
		7'b000??11 : 	waddr1	<=	waddr1_plus1 ;	// advance addr for consecutive write
		
			//case of very last data straddle into EOF qwd
		7'b100???1 :	waddr1	<=	waddr1_plus1 ;
		
		default	:	waddr1	<=	waddr1 ;			//hold if full
	endcase
	
	//for taking care of pkt with 1 to 3 bytes extra
	eof_dqwd_dly1	<= eof_dqwd;

end	

// ========================================================
// Logic : Pre-Detetcion of IPv version , Jumbo Pkt , Vlan
// ========================================================

wire	qvlan_type;
wire	vlan_type;
wire	pppoe_session_type;
wire	pppoe_disc_type;

wire	vlan_ip_type;	//VLAN and next layer is IP
wire	pppoe_ip_type;	//PPPoE and next layer is IP
wire	normal_ip_type;	//normal IP packet and next layer is IP
wire	qnormal_ip_type;	//normal IP packet and next layer is IP

wire	qenet_arp_pkt ;

	//decoding the various Ether Types
		//quick versions
assign	qnormal_ip_type 	= (rxd[39:32]==8'h08)&&(rxd[47:40]==8'h00) ;
assign	qvlan_type 			= (rxd[39:32]==8'h81)&&(rxd[47:40]==8'h00) ;
assign	qenet_arp_pkt		=
			(rxd[63:32] == 32'h0100_0608) ; 


assign	normal_ip_type 		= (bdata1[39:32]==8'h08)&&(bdata1[47:40]==8'h00) ;
assign	vlan_type 			= (bdata1[39:32]==8'h81)&&(bdata1[47:40]==8'h00) ;
assign	pppoe_session_type 	= (bdata1[39:32]==8'h88)&&(bdata1[47:40]==8'h64) ;
assign	pppoe_disc_type 	= (bdata1[39:32]==8'h88)&&(bdata1[47:40]==8'h63) ;

assign	vlan_ip_type		= 
			 xaui_mode & vlan_type & ( (rxd[7:0]   ==8'h08) & (rxd[15:8]   ==8'h00) ) |
			 	//Gige mode only look at BDATA1
			!xaui_mode & vlan_type & ( (bdata1[7:0]==8'h08) & (bdata1[15:8]==8'h00) ) 
			;

assign	pppoe_ip_type		= 
			 xaui_mode & pppoe_session_type & ( (rxd[39:32]   ==8'h00) & (rxd[47:40]   ==8'h21) ) |
			!xaui_mode & pppoe_session_type & ( (bdata1[39:32]==8'h00) & (bdata1[47:40]==8'h21) ) 
			;

	reg		non_ip ;
	
always@(posedge clk156)
if(!rst_)
begin
	normal_ip			<= 1'b0 ;
	vlan_ip				<= 1'b0 ;
	pppoe_ip		 	<= 1'b0 ;	// IP only
	
	pkt_ipver 		<= 4'd0 ;
	non_ip			<= 1'b0 ;
	type_reject		<= 1'b0 ;
end
else
begin
	normal_ip	<=	sof_dly ? normal_ip_type : normal_ip ;
	
	vlan_ip		<=	
		 xaui_mode & sof_dly  ? vlan_ip_type : 
		!xaui_mode & sof_dly2 ? vlan_ip_type : 
		vlan_ip ;
	
	non_ip		<= !(vlan_ip | normal_ip) ;
			
		//if had SOF, 2nd Qwd [47:32] = 0x8864 type means PPPoE_Session pkt
		//and potentially has IP layer if the next type is 0x0021
	pppoe_ip <= 
			//update PPPoE_Session IP field
			 xaui_mode & sof_dly  ? pppoe_ip_type :  
			!xaui_mode & sof_dly2 ? pppoe_ip_type :  
			//hold
			pppoe_ip ;

	//reject unwanted pkt types
	//only coded for 10G
	//!!!for VLAN, EXTR needs to check for IP type before accepting
	type_reject	<=	
		sof & !(qnormal_ip_type | qvlan_type | qenet_arp_pkt) ? 1'b1  :
		sof &  (qnormal_ip_type | qvlan_type | qenet_arp_pkt) ? 1'b0  :
		type_reject
		;
		
	pkt_ipver      <= 
		xaui_mode & sof_dly ? 
					//if VLAN & IP case, use next qwd bit 23:20
					( (vlan_ip_type) ? rxd[23:20] :  
					//if PPPoE_Session & IP Type
					  (pppoe_ip_type) ? rxd[55:52] :
					//if NORMAL IP Type
					  (normal_ip_type) ? bdata1[55:52] :
					  
					//if not VLAN & PPPoE Session & not normal IP case
					//put in junk
					//Note that this field will not be valid if not IP packet type
					  
					   4'he ) :    //E = error or junk
		//gige mode
					//if NORMAL IP Type
					!xaui_mode & sof_dly & (normal_ip_type) ? bdata1[55:52] : 
					//if VLAN & IP case, use next qwd bit 23:20
					!xaui_mode & sof_dly2 & (vlan_ip_type) ? bdata1[23:20] : 
					//if PPPoE_Session & IP Type
					!xaui_mode & sof_dly2 & (pppoe_ip_type) ? bdata1[55:52] : 
					//hold
					pkt_ipver ;
	
	
					
end


	//avoid latch condition, making this equation simpler since EOF_DLY is already gated
	// when pkt_jumbo_flag is used
assign pkt_jumbo_flag = (nbytes>16'd1500) ? 1'b1 : 1'b0 ;

//======================
// EXtract Mac Source Address
//======================

always@(posedge clk156)
if(!rst_)
begin
	mac_saddr <= 0 ;
end
else
begin
	mac_saddr <= 
		xaui_mode & sof ? {bdata1[55:48],bdata1[63:56],rxd[7:0],rxd[15:8],rxd[23:16],rxd[31:24] } :  
		//gige mode
		sof_dly ? {qwd0_data_dly1[55:48],qwd0_data_dly1[63:56],  bdata1[7:0],bdata1[15:8],bdata1[23:16],bdata1[31:24] } :
		mac_saddr ;
end

assign mac_saddr_vld =  
			 xaui_mode & sof_dly |
			!xaui_mode & post_sof_dly ;

//====================
// Mac Ipv6 Multicast
// Filter Function
//====================
			
fmac_saddr_filter fmac_saddr_filter_U1
(
.clk(clk156),				// i-1
.rst_(rst_),				// i-1
// Input from mac_regs
.mcast_en(mcast_en),				// i-1
.mcast_saddr(mcast_saddr),				// i-48
// Inputs from mac_ppr
.mac_saddr(mac_saddr),				// i-48
.mac_saddr_vld(mac_saddr_vld),				// i-1
// Output
.saddr_filter_drop(saddr_filter_drop)				// o-1
);


//======================
// EXtract Mac Source Address
//======================

always@(posedge clk156)
if(!rst_)
begin
	saddr_filter_drop_flag <= 0 ;
end
else
begin
	saddr_filter_drop_flag <= 
					saddr_filter_drop ? (pkt_ipver==4'h6) : 
					eof_dly2 ? 1'b0 : 
					//hold
					saddr_filter_drop_flag ;
end


// ========================================================
// REGISTER and SYNCHRONIZATION
// ========================================================
reg [31:0]	no_space_drop_cnt;
reg			no_space_drop;
reg [31:0]	FMAC_DCNT_OVERRUN;	// 250 Mhz


reg [31:0]	bad_link_drop_cnt;
reg			bad_link_drop;
reg [31:0]	FMAC_DCNT_LINK_ERR;	// 250 Mhz
reg			FIFO_OV_IPEND;		// 250 Mhz

reg [31:0]	FMAC_PKT_CNT_OVERSIZE;	// 250 Mhz
reg			pkt_oversize;

always @ (posedge clk156)
begin
	if (!rst_)
	begin
		no_space_drop_cnt <= 32'h0;
		no_space_drop <= 1'b0;
		
		bad_link_drop_cnt <= 32'h0;
		bad_link_drop <= 1'b0;
		
		MAX_PKT_SIZE	<=	14'd1518	;
		pkt_slice_en	<=	1'b0	;
		
		pkt_oversize <= 1'b0	;
		
		sof_n_eof_dly1	<= 1'b0 ;
		sof_n_eof_dly2	<= 1'b0 ;
	end
	
	else
	begin
		sof_n_eof_dly1	<= sof_n_eof ;
		sof_n_eof_dly2	<= sof_n_eof_dly1 ;
	
		MAX_PKT_SIZE	<=	fmac_ctrl1_dly[13:0]	;
		pkt_slice_en	<=	fmac_ctrl1_dly[15]		;
		
		no_space_drop_cnt <= no_space_drop? (no_space_drop_cnt + 32'd1) : no_space_drop_cnt;
			//does not allow the DRAM buffer to overwrite any more
			//so account only when got new pkt coming in & the buffer is full
		no_space_drop <= 
			sof & !space_ok;
		
		bad_link_drop_cnt <= bad_link_drop? (bad_link_drop_cnt + 32'd1) : bad_link_drop_cnt;
		bad_link_drop <= eof & (err | rx_err0 | rx_err1);
		
		pkt_oversize	<= 
				//clr
				eof_dly2 ? 1'b0 : 
				//set
				( eof & (nbytes > MAX_PKT_SIZE) ) ? 1'b1 : 
				//hold
				pkt_oversize;
				
	end
end

//============== SYNC the reg for output to internal logic

reg		no_space_drop0_clk250;
reg		no_space_drop1_clk250;

reg		bad_link_drop0_clk250;
reg		bad_link_drop1_clk250;

//detect the capture en for clk250 (if see 2 zeroes in a row)
wire	no_space_drop_clk250 = no_space_drop0_clk250 & no_space_drop1_clk250;
wire	bad_link_drop_clk250 = bad_link_drop0_clk250 & bad_link_drop1_clk250;

always @ (posedge clk250)
	begin
		//if see 2 zero in a row (not updating by clk156), can capture the data
	no_space_drop0_clk250	<= !no_space_drop;
	no_space_drop1_clk250	<=  no_space_drop0_clk250;
	
	bad_link_drop0_clk250	<= !bad_link_drop;
	bad_link_drop1_clk250	<=  bad_link_drop0_clk250;
	
	
	end

	
wire	no_space_drop_ok = no_space_drop_clk250;
wire	bad_link_drop_ok = bad_link_drop_clk250;

always @ (posedge clk250)
begin
	if (!rst_)
	begin
		FMAC_DCNT_OVERRUN <= 32'h0;
		FMAC_DCNT_LINK_ERR <= 32'h0;
		FIFO_OV_IPEND <= 1'b0;
	end
	
	else
	begin
		FMAC_DCNT_OVERRUN <= no_space_drop_ok? no_space_drop_cnt : FMAC_DCNT_OVERRUN;
		
			//sync the sampling - should be whenever EOF low for 2 clks in a row.
		FMAC_DCNT_LINK_ERR <= bad_link_drop_ok? bad_link_drop_cnt : FMAC_DCNT_LINK_ERR;
		
		FIFO_OV_IPEND <= no_space_drop_ok;
	end
end

// ========================================================
//====== SUPPORT FOR COUNTING B/MCAST, OverSize PKTS
//========================================================

reg		add_lo_bcast156	;
reg		add_lo_mcast156	;

reg		add_lo_bcast	;
reg		add_lo_mcast	;

reg		clr_carry_cast	;
reg		add_hi_cast		;

reg		eof_sync_wait	;
reg		eof_sync_wait_dly	;
reg		clr_pkt_cnt_oversize_dly	;


always @(posedge clk156)
	if (!rst_)
		begin
		add_lo_bcast156		<= 1'b0;
		add_lo_mcast156		<= 1'b0;	
		end
		
	else
		begin
		add_lo_bcast156		<= 
				//clr
				(eof_dly2) ? 1'b0 :
				//set
				(eof & bcast_addr) ? 1'b1 :
				//hold
				add_lo_bcast156
				;
		add_lo_mcast156		<= 
				//clr
				(eof_dly2) ? 1'b0 :
				//set
				(eof & mcast_addr) ? 1'b1 :
				//hold
				add_lo_mcast156
				;
		end

//250MHz domain
		
reg		ok_clk250_dly1;
reg		ok_clk250_dly2;
reg		ok_clk250_dly3;
reg		ok_clk250_dly4;


//clk 250 see EOF low for 2 clks in a row
always @(posedge clk250)
	if (!rst_)
		begin
		
		ok_clk250			<= 1'b0;
		
		ok_clk250_dly1		<= 1'b0 ;
		ok_clk250_dly2		<= 1'b0 ;
		ok_clk250_dly3		<= 1'b0 ;
		ok_clk250_dly4		<= 1'b0 ;
		
		eof_sync_wait		<= 1'b0;
		eof_sync_wait_dly	<= 1'b0;
		
		end
	
	else
		begin
		ok_clk250			<=
				//clear if set
				ok_clk250 ? 1'b0 :
				//asserts when seeing the 1st valid EOF
				(!ok_clk250 & !eof_sync_wait & eof_dly) ? 1'b1 :
				//hold
				ok_clk250;
				
				
		ok_clk250_dly1		<= ok_clk250 ;
		ok_clk250_dly2		<= ok_clk250_dly1 ;
		ok_clk250_dly3		<= ok_clk250_dly2 ;
		ok_clk250_dly4		<= ok_clk250_dly3 ;
		
		eof_sync_wait				<= 
							//Force clear at stat OK delay 4
							ok_clk250_dly4 ? 1'b0 :
							//set at stat ok
							ok_clk250 ? 1'b1 :
							//hold
							eof_sync_wait;
							
		eof_sync_wait_dly			<= eof_sync_wait ;

		end

//======== GENERATING 250MHz outputs
always @(posedge clk250)
	if (!rst_)
		begin
		add_lo_bcast	<= 1'b0 ;
		add_lo_mcast	<= 1'b0 ;
		clr_carry_cast	<= 1'b0 ;
		add_hi_cast		<= 1'b0 ;
		end
		
	else
		begin
		add_lo_bcast	<= add_lo_bcast156 & !eof_sync_wait & ok_clk250 ;
		add_lo_mcast	<= add_lo_mcast156 & !eof_sync_wait & ok_clk250 ;
		
		clr_carry_cast	<= ok_clk250_dly3 ;
		
		add_hi_cast		<= ok_clk250_dly1 & !eof_sync_wait_dly  ;		
		end

// ========================================================
// RECODE of registers
// ========================================================
		
always @(posedge clk250)
	if (!rst_)
		begin
		FMAC_PKT_CNT_OVERSIZE		<= 32'h0 ;
		
		clr_pkt_cnt_oversize_dly	<= 1'b0	;
		end
		
	else
		begin
		clr_pkt_cnt_oversize_dly <= clr_pkt_cnt_oversize;
		
		FMAC_PKT_CNT_OVERSIZE	<= 
				//clear
				(clr_pkt_cnt_oversize_dly ) ? 32'h0 :
				//add, pkt_oversize is 156MHz signal
				(ok_clk250 & !eof_sync_wait & pkt_oversize ) ? FMAC_PKT_CNT_OVERSIZE + 1'b1 :
				//keep
				FMAC_PKT_CNT_OVERSIZE;
		
		end
		

//================= PKT Info for saving into the FIFO

reg		[63:0]	pre_pkt_data	;
reg				pre_pkt_start	;

always@(posedge clk156)
if( !rst_ | !fmac_rxd_en )
	begin
	pre_pkt_data		<= 64'h0;
	pre_pkt_start		<= 1'b0;
	pkt_data		<= 64'h0;
	pkt_start		<= 1'b0;
	pkt_end			<= 1'b0;
	pkt_we			<= 1'b0;
	
	pre_eof		<= 1'b0 ;
	end
else
	begin
	pre_pkt_data		<= 
		bdata1;
	pre_pkt_start		<= 
		//case of SOF4 took care of in SOF
		sof;
		
	pkt_data	<= pre_pkt_data;
	pkt_start	<= pre_pkt_start & my_mac_hit & !type_reject;	
	pkt_end			<= 
		pkt_end ? 1'b0 :
		eof_dqwd ? 1'b0 :
		eof_dqwd_dly1 & pkt_we ? 1'b1 :
		pre_eof	& pkt_we
		;
		
	pkt_we		<=
		pkt_end ? 1'b0 :
		pre_pkt_start & my_mac_hit & !type_reject ? 1'b1 :
		pkt_we
		;		
	pre_eof		<=		//too late so need to delay the data
	   	fmac_rxd_en & (rxc[0] && (rxd[7:0] == 8'hFD))   || 
		fmac_rxd_en & (rxc[1] && (rxd[15:8] == 8'hFD))  || 
		fmac_rxd_en & (rxc[2] && (rxd[23:16] == 8'hFD)) || 
		fmac_rxd_en & (rxc[3] && (rxd[31:24] == 8'hFD)) ||
					
	   	fmac_rxd_en & (rxc[4] && (rxd[39:32] == 8'hFD)) || 
		fmac_rxd_en & (rxc[5] && (rxd[47:40] == 8'hFD)) ||       
		fmac_rxd_en & (rxc[6] && (rxd[55:48] == 8'hFD)) ||       
		fmac_rxd_en & (rxc[7] && (rxd[63:56] == 8'hFD))          
		;
		
		end

//========================================================
// CRC32
//========================================================
wire			pre_pkt_we_wire	;

wire			pre_pkt_eof	;
wire	[2:0]	pre_pkt_beat_bcnt_wire	;

reg		[2:0]	pre_pkt_beat_bcnt	;
reg		[2:0]	pre_pkt_beat_bcnt_dly1	;
wire	[31:0]	crc32_out ;
wire			crc32_vld ;
reg				pre_eof_dly1	;
reg				pre_eof_dly2	;
reg				eof_dqwd_dly2 ;



assign	pre_pkt_we_wire	=
		!rst_  ? 1'b0 :
		pre_eof_dly1 & !eof_dqwd_dly1 & pre_pkt_we_wire  ? 1'b0 :
		pre_eof_dly2 &  eof_dqwd_dly2 & pre_pkt_we_wire	 ? 1'b0 :
		pre_pkt_start & my_mac_hit & !type_reject 		 ? 1'b1 :
		pre_pkt_we_wire
		;		
	
// needed for eof with data			
assign	pre_pkt_eof	=
  			pre_eof 	 & !eof_dqwd 		? 1'b1 :
			pre_eof_dly1 & eof_dqwd_dly1 	? 1'b1 :
			1'b0 ;
		
assign	pre_pkt_beat_bcnt_wire	=
  			pre_eof 	 & !eof_dqwd 		? pre_pkt_beat_bcnt :
			pre_eof_dly1 & eof_dqwd_dly1 	? pre_pkt_beat_bcnt_dly1 :
			3'h0 ;
			

always@(posedge clk156)
begin

if( !rst_ | !fmac_rxd_en )
	begin
	pre_eof_dly1		<= 1'b0;
	pre_eof_dly2		<= 1'b0;
	pre_pkt_beat_bcnt	<= 3'b0;
	pre_pkt_beat_bcnt_dly1	<= 3'b0;
	
	eof_dqwd_dly2		<= 1'b0 ;
	end
else
	begin

	pre_eof_dly1		<= pre_eof;
	pre_eof_dly2		<= pre_eof_dly1;
	eof_dqwd_dly2		<= eof_dqwd_dly1 ;
	
		case(rxc)
			8'hff: pre_pkt_beat_bcnt <=   3'd4;
			8'hfe: pre_pkt_beat_bcnt <=   3'd5;
			8'hfc: pre_pkt_beat_bcnt <=   3'd6;
			8'hf8: pre_pkt_beat_bcnt <=   3'd7;
			8'hf0: pre_pkt_beat_bcnt <=   3'd0;
			8'he0: pre_pkt_beat_bcnt <=   3'd1;
			8'hc0: pre_pkt_beat_bcnt <=   3'd2;
			8'h80: pre_pkt_beat_bcnt <=   3'd3;
			8'h00: pre_pkt_beat_bcnt <=   3'd0;				
			
			default: pre_pkt_beat_bcnt <=   3'd0;
		endcase
	
	pre_pkt_beat_bcnt_dly1	<= pre_pkt_beat_bcnt ;
	 
	end
end


eth_crc32_gen eth_crc32_gen(
   .clk			(clk156),         				//clock
   .rst_n		(rst_),        	  				//active low reset
   .data_vld	(pre_pkt_we_wire),     			//data valid
   .data_eop	(pre_pkt_eof),    	   			//end of frame
   .data_sop	(pre_pkt_start),  				//start of frame
   .data_in		(pre_pkt_data),   				//align first byte on bit [7:0] ... last byte [63:56]
   .data_offset	(3'h0), 		  				//number of starting bytes invalid on SOF beat, non SOF should set to 0
   								  				//sdata_offset should be 0 for this module if contained in RX_GMII
   .data_be		(pre_pkt_beat_bcnt_wire),     	//0 - all bytes valid  (really is beat_bcnt)
   	             			 				  	//1 - 1 byte valid bit[7:0]
   	             			 				  	//..
   	             			 				  	//7 - 7 bytes valid bit[55:0]
   .crc_out		(crc32_out),     				//final generated crc32 value
   .crc_vld     (crc32_vld)		 				//crc check valid
 );


wire	crc32_ok ;
assign	crc32_ok	=	crc32_vld ? (crc32_out == chk_crc) : 1'b0 ;



//========================================================
// DRX_PKT_DATA
//========================================================
reg		[63:0]	drx_pkt_data	;             //same time as bdata2
reg				drx_pkt_start ; 
reg				drx_pkt_end ; 
reg				drx_pkt_we ;

reg		[2:0]	drx_pkt_beat_bcnt	;
reg		[7:0]	drx_pkt_be	;

wire	[31:0]	drx_crc32 ;
wire			drx_crc_vld ;
wire			drx_crc_err ;

reg				drx_crc_err_dly1 ;


assign		drx_crc_err = !crc32_ok ;
assign		drx_crc_vld = crc32_vld ;
assign		drx_crc32 	= crc32_out ;


always@(posedge clk156)
if( !rst_ | !fmac_rxd_en )
	begin
		drx_pkt_data		<= 64'h0;
		drx_pkt_start		<= 1'b0;
		drx_pkt_end			<= 1'b0;
		drx_pkt_we			<= 1'b0;
		
		drx_pkt_beat_bcnt	<= 3'h0;
		drx_pkt_be			<= 8'h0;
		
		drx_crc_err_dly1	<= 1'b0;
		
	end
else
	begin
		
		//support MCAST on this port
		drx_pkt_data	<= pre_pkt_data;
		drx_pkt_start	<= pre_pkt_start & (my_mac_hit | mcast_hit) & !type_reject;	
		drx_pkt_end			<= 
			drx_pkt_end ? 1'b0 :
			eof_dqwd ? 1'b0 :
			eof_dqwd_dly1 & drx_pkt_we ? 1'b1 :
			pre_eof	& drx_pkt_we	
			;
		drx_pkt_we		<=
			drx_pkt_end ? 1'b0 :
			pre_pkt_start & (my_mac_hit | mcast_hit) & !type_reject ? 1'b1 :
			drx_pkt_we
			;		
		drx_pkt_beat_bcnt	<=	pre_pkt_beat_bcnt_wire ;
		
		case(pre_pkt_beat_bcnt_wire)
			3'h0: drx_pkt_be <=   8'hff;
			3'h1: drx_pkt_be <=   8'h01;
			3'h2: drx_pkt_be <=   8'h03;
			3'h3: drx_pkt_be <=   8'h07;
			3'h4: drx_pkt_be <=   8'h0f;
			3'h5: drx_pkt_be <=   8'h1f;
			3'h6: drx_pkt_be <=   8'h3f;	
			3'h7: drx_pkt_be <=   8'h7f;	
			
			default: drx_pkt_be <=   8'hff;
		endcase
		
		drx_crc_err_dly1	<= drx_crc_err ;
		
		end


endmodule