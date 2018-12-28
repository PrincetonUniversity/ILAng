reg r1;
always @(posedge clk) begin
    if(rst)
        r1 <= 0;
    else
        r1 <= ~r1;
end



assign r = r1;
