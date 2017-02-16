
`timescale 1 ns / 1 ps

// synchronously-resettable D-flip flops (with synchronous write-enable)
module FlopSync #(parameter width=8)
     (input clk,
      input reset,
      input en,
      input [width-1:0] d,
      output reg [width-1:0] q);

   always @(posedge clk) begin
      if (reset)
        q <= 'b0;
      else if (en)
        q <= d;
   end

endmodule

module FIFOBypass #(parameter width=8, depth=1)
   (input clk,
    input              reset,
    input              enq,
    input              deq,
    input [width-1:0]  i,
    output             full_n,
    output             empty_n,
    output [width-1:0] o);

   //reg [utils::clog2(depth+1)-1:0]           capacity;
   reg [0:0]           capacity;
   // note: this implements the integer ceiling of the log function (base2)
   parameter clogDepth = 0; //utils::clog2(depth);
   reg [width-1:0]                         entry [depth-1:0];
   // read from head address, write to tail address
   wire [clogDepth-1:0]                     head, tail, nextHead, nextTail;
   parameter depthM1 = depth -1;
   wire                                      incTail;
   wire                                      incHead;
   // tell the world we’re empty if we’re empty AND no data arriving
   assign empty_n = ~((capacity == depth) && (~enq));
   assign full_n = ~(capacity == 0 );
   // write state iff we have space, and we’re not bypassing
   assign incTail = enq && (capacity != depth && capacity != 0 ||
		            capacity == 0 && deq ||
		            capacity == depth && !deq);
   // read state iff we have stuff to read and we’re not bypassing
   assign incHead = deq && capacity != depth;
   // bypass routing logic
   assign o = (capacity == depth)? i : entry[head];
   generate
      if (clogDepth == 0) begin
	 assign nextHead = 'b0;
	 assign nextTail = 'b0;
      end else begin
	 assign nextHead = (head == depthM1[clogDepth-1:0]) ? 'b0 : head + 1'b1;
	 assign nextTail = (tail == depthM1[clogDepth-1:0]) ? 'b0 : tail + 1'b1;
      end
   endgenerate
   // store data if queue isn’t full OR if deq is active
   always @(posedge clk) begin: queue_data
      if (!reset && incTail)
	entry[tail] <= i;
   end
   // queue capacity register tells how much space is free
   always @(posedge clk) begin: cap_logic
      if (reset)
	capacity <= depth;
      else begin
	 if (incTail && !deq) begin
	    capacity <= capacity - 1;
	 end else begin
	    if (incHead && !enq) begin
	       capacity <= capacity + 1;
	    end
	 end
      end
   end
   // synchronously-resettable D-flip flops (with synchronous write-enable)
   FlopSync #(.width(clogDepth)) headReg
     (.clk(clk), .reset(reset), .en(incHead), .d (nextHead), .q(head));
   FlopSync #(.width(clogDepth)) tailReg
     (.clk(clk), .reset(reset), .en(incTail), .d (nextTail), .q(tail));
endmodule
