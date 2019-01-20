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


`timescale 1ns/1ns

module ctrl_2g_5g
	(

		clk			,  	//156Mhz Clock i-1                        
		reset_		,  	//i-1                                     
                       	                                          
		mode_10G 	,  	//i-1, speed modes                        
		mode_5G  	,  	//i-1,                                    
		mode_2p5G	,  	//i-1,                                    
		mode_1G  	,  	//i-1,                                    
		               	                                          
		data_in		,  	//i-64, input data                        
		ctrl_in		,  	//i-8, input control                      
		               	                                          
		data_out	,  	//o-64, output data                       
		ctrl_out	,  	//o-8, output control                     
		we_5g		,  	//o-1, write enable for 2.5G and 5G speeds
		x_byte_cnt	,  	//o-16, byte count for every packet       
		x_bcnt_we	,  	//o-1, write enable for byte count fifo   
		linkup_5g      	
	
	);
	
	
	input 			clk			;	//156Mhz Clock i-1
	input 			reset_		;	//i-1

	input			mode_10G 	;	//i-1, speed modes
	input			mode_5G  	;	//i-1, 
	input			mode_2p5G	; 	//i-1, 
	input			mode_1G  	;	//i-1, 
	       	
	input  	[63:0] 	data_in		;	//i-64, input data
	input  	[07:0]	ctrl_in		;	//i-8, input control
	       	
	output 	[63:0] 	data_out	;	//o-64, output data
    output 	[07:0]  ctrl_out	;	//o-8, output control
    output 			we_5g		;	//o-1, write enable for 2.5G and 5G speeds 
    output 	[15:0] 	x_byte_cnt	;	//o-16, byte count for every packet
    output			x_bcnt_we	;	//o-1, write enable for byte count fifo
    output			linkup_5g	;

    reg   	[63:0] 	data_out	; 
    reg  	[07:0]  ctrl_out	;
    reg 			we_5g		;
    reg	 	[15:0]	x_byte_cnt	;
    reg				x_bcnt_we	; 
    
    reg    	[02:0]	count		;
    reg				sof			;	//Start of packet
    reg				sof0		;	//Start of packet on Byte 0 of the first QWD
    reg				sof4		;	//Start of packet on Byte 4 of the first QWD
    reg				eof			;	//End of Packet
    reg				eof0		;	//End of Packet on Byte 0 of the last QWD
    reg				eof1		;	//End of Packet on Byte 1 of the last QWD
    reg				eof2		;	//End of Packet on Byte 2 of the last QWD
    reg				eof3		;	//End of Packet on Byte 3 of the last QWD
    reg				eof4		;	//End of Packet on Byte 4 of the last QWD
    reg				eof5		;	//End of Packet on Byte 5 of the last QWD
    reg				eof6		;	//End of Packet on Byte 6 of the last QWD
    reg				eof7		;	//End of Packet on Byte 7 of the last QWD	
    reg 			rx_dinvalid	;	//invalid data
    reg				linkup_5g	;
    
    reg				frame		;
    
    parameter [2:0]
    	
    	LINK_FAIL = 3'd1,
    	LINK_RCVR = 3'd2,
    	LINK_GOOD = 3'd4;
    	
    reg [2:0] state;
    reg [4:0] link_cnt;
    reg		  link_ok;
    reg		  link_bad;
    wire	  link_fault;
    assign link_fault = (data_in[39:32] == 8'h9c && ctrl_in[4]) || 
    					(data_in[7:0] == 8'h9c && ctrl_in[0]);
        
    
	always @ (posedge clk) begin
	
			if (!reset_)
				begin
					
					data_out   	<= 64'h0707_0707_0707_0707;
					ctrl_out   	<= 8'hff;
					we_5g	   	<= 1'b0;
					count	   	<= 3'd0;
					sof 	   	<= 1'b0;
					sof0	   	<= 1'b0;
					sof4       	<= 1'b0;
					eof		   	<= 1'b0;
					eof0       	<= 1'b0;
					eof1       	<= 1'b0;
					eof2       	<= 1'b0;
					eof3       	<= 1'b0;
					eof4       	<= 1'b0;
					eof5       	<= 1'b0;
					eof6       	<= 1'b0;
					eof7       	<= 1'b0;
					x_byte_cnt 	<= 16'd0;
					x_bcnt_we 	<= 1'b0;
					rx_dinvalid <= 1'b1;
					linkup_5g	<= 1'b0;
					link_ok		<= 1'b0;
					link_bad	<= 1'b0; 
					
					frame		<= 1'b0;
										
				end
			
			else
				begin
				
				if (mode_2p5G | mode_5G) begin
					
					frame <= ((ctrl_in[0] && data_in[7:0] == 8'hfb) ||
						     (ctrl_in[4] && data_in[39:32] == 8'hfb))?	1'b1 :
						     (eof)? 1'b0	:	frame;
						
					sof <= (ctrl_in[0] && data_in[7:0] == 8'hfb) ||				//Detect the the start of the packet based on
						   (ctrl_in[4] && data_in[39:32] == 8'hfb);				//the position of "fb"
						   
					sof0 <=  (ctrl_in[0] && data_in[7:0]   == 8'hfb);			//Packet starts on byte 0
					sof4 <=  (ctrl_in[4] && data_in[39:32] == 8'hfb);			//Packet starts on byte 4
					
					
					eof  <= (eof0 | eof1 | eof2 | eof3 | eof4 | eof5 | eof6 | eof7 );		//Detects the end of packet based on the position of "fd"
					eof0 <= (ctrl_in[0] && data_in[7:0] == 8'hfd)    ;						//Packet ends on byte 0	
					eof1 <=	(ctrl_in[1] && data_in[15:8] == 8'hfd)   ;						//Packet ends on byte 1
					eof2 <=	(ctrl_in[2] && data_in[23:16] == 8'hfd)  ;						//Packet ends on byte 2
					eof3 <=	(ctrl_in[3] && data_in[31:24] == 8'hfd)  ;						//Packet ends on byte 3
					eof4 <=	(ctrl_in[4] && data_in[39:32] == 8'hfd)  ;						//Packet ends on byte 4
					eof5 <=	(ctrl_in[5] && data_in[47:40] == 8'hfd)  ;						//Packet ends on byte 5
					eof6 <=	(ctrl_in[6] && data_in[55:48] == 8'hfd)  ;						//Packet ends on byte 6
					eof7 <=	(ctrl_in[7] && data_in[63:56] == 8'hfd)	 ;						//Packet ends on byte 7
					
					if (frame) begin
					
					x_byte_cnt[14:0] <= (sof0) ? 15'd8 :				//Byte count for the number of bytes in the given packet									     
							(sof4) ? 15'd4 :							//if packet start at B0 then you start with "8"									
							(!rx_dinvalid & we_5g) ?                   	//and if it starts at B4 then you start with "4"
							((eof0) ? x_byte_cnt[14:0] + 15'd1 :		//As the position of "fd" is not fixed															               
							 (eof1) ? x_byte_cnt[14:0] + 15'd2 :		//for the last QWD, we add different numbers based on the 										           
							 (eof2) ? x_byte_cnt[14:0] + 15'd3 :		//position of "fd"										                  	
							 (eof3) ? x_byte_cnt[14:0] + 15'd4 :
							 (eof4) ? x_byte_cnt[14:0] + 15'd5 :
							 (eof5) ? x_byte_cnt[14:0] + 15'd6 :
							 (eof6) ? x_byte_cnt[14:0] + 15'd7 :
							 x_byte_cnt[14:0] + 15'd8) :
							 (eof) ? 15'd0 : 
							x_byte_cnt;								                                 

					//set MSB if packet is sof4 type. set it zero if sof0 type
					x_byte_cnt[15] <= (sof0) ? 1'b0 :									     
										(sof4) ? 1'b1 : x_byte_cnt[15];						
																                                 
					x_bcnt_we <= (eof & count == 3'd1) ? 1'b1 :	
							1'b0;
							
					rx_dinvalid <= ((data_in == 64'h0707_0707_0707_0707) && (ctrl_in == 8'hff));
					
					we_5g <= (rx_dinvalid) ? 1'b0 :       //Write enable generated for the gige_fifo, to write the data onto the memory
						(count == 3'd1) ? 1'b0 :
						(!count) ? 1'b1 :
						we_5g
						;							     
					
					count <= (mode_2p5G) ?       	//Count is the count used to control the "we_5g" signal
						((rx_dinvalid) ? 3'd0:      //Its value is different for different speed
						(count == 3'd3) ? 3'd0 : 
						count + 1) :             
						(mode_5G) ?         	
						((rx_dinvalid) ? 3'd0:   
						(count == 3'd1) ? 3'd0 : 
						count + 1) :             
						count                    
						;                        
					
					data_out <= data_in;                  //No change in data
					
					ctrl_out <= ctrl_in;	              //No change in control
							
							linkup_5g <= state[2] ; 
							link_bad <= link_fault;
							link_ok <= (link_cnt == 5'd0) ;
					
					end		
					else begin
					
					x_byte_cnt	<= 16'b0;								                                 
																                                 
					x_bcnt_we 	<= 1'b0;
							
					rx_dinvalid <= 1'b0;
					
					we_5g 		<= 1'b0;							                             
					
					count 		<= 3'd0;                              	
					
					data_out 	<= 64'h0707070707070707;              
					         	
					ctrl_out 	<= 8'hFF;	             
							
					linkup_5g 	<= state[2] ; 
					link_bad 	<= link_fault;
					link_ok 	<= (link_cnt == 5'd0) ;
					
					end		
				end
				
       		end
	end        
        
	//for linkup-detection                
	always @ (posedge clk)
		begin 
			if (!reset_)
				begin
					state <= LINK_FAIL;        
                    link_cnt <= 5'd30;
                end
            else
            	begin
            	if (mode_2p5G | mode_5G) begin
            		case(state)
            		LINK_FAIL :
            			begin
            				state <= link_bad ? LINK_FAIL : LINK_RCVR ;
            				link_cnt <= 5'd30;
                    	end
                    	
                    LINK_RCVR :
                    	begin
                    		state <= link_bad ? LINK_FAIL : 
                    			( link_ok ? LINK_GOOD : LINK_RCVR )
                    			;
                    		link_cnt <= link_cnt - 5'd1 ;
                    	end
                    	
                    LINK_GOOD :
                    	begin
                    		state <= link_bad ? LINK_FAIL :
                    			LINK_GOOD
                    			;
                    		link_cnt <= 5'd30;
                    	end
                    
                    default : 
                    		state <= LINK_FAIL;
                    endcase
            	end     
            end
        end       
endmodule