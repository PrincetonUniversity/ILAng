module testMem(input clk, input rst, output concrete_val);

reg [15:0] cnt;
always @(posedge clk) begin
    if(rst)
        cnt <= 0;
    else begin
        cnt <= cnt + 1;
    end
end


reg mem_w_en;
reg[15:0] mem_w_addr;
reg[15:0] mem_w_data;
reg mem_r_en;
reg[15:0] mem_r_addr;
wire[15:0] mem_r_data;
//wire concrete_val;

jasper_model_mpram #(.READ_PORTS(1),
.WRITE_PORTS(1),
.ADDR_WIDTH(16),
.DATA_WIDTH(16),
.MAX_DEPTH(256),
.MEM_STYLE(0),
.RESET_STYLE(0),
.RD_DATA_DLY(0)
)
my_mpram
(.clk(clk),
.rstN(~rst),
.write(1'b0),
.addr_wr(mem_w_addr),
.data_wr(mem_w_data),
.read(mem_r_en),
.addr_rd(mem_r_addr),
.data_rd(mem_r_data),
.read_allocate(mem_r_en),
.write_allocate(1'b0),
.concrete(concrete_val)
);


always @(posedge clk) begin
    if(rst) begin
        mem_w_en <= 1'b0;
    end
    else begin
        if( (cnt &2'b11) == 2'b01) begin
            mem_w_en <= 1'b1;
            mem_w_addr <= cnt;
            mem_w_data <= cnt + 1;
        end
        else begin
            mem_w_en <= 1'b0;
        end
    end
end

always @(posedge clk) begin
    if(rst) begin
        mem_r_en <= 1'b0;
    end
    else begin
        if( (cnt &2'b11) == 2'b10) begin
            mem_r_en <= 1'b1;
            mem_r_addr <= cnt&2'b11;
        end
        else begin
            mem_r_en <= 1'b0;
        end
    end
end

reg[15:0] old_value;
always @(posedge clk) begin
    if( (cnt &2'b11) == 2'b11 )
        old_value <= mem_r_data;
end

assert property ( ( (cnt>3) && ((cnt &2'b11) == 2'b11) ) |-> ( old_value ==  mem_r_data )  );
assume property ( ~(cnt == 4) | (old_value == 16'd10) );
assert property ( (cnt == 7) |-> (mem_r_data == 16'd10));
assert property ( ( (cnt &2'b11) == 2'b11) |-> (concrete_val) );

endmodule