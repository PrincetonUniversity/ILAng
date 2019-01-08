
// synopsys translate_off

`timescale 1ns/10ps

// synopsys translate_on

module reg256byte(clk, rst, en, wr, addr, data_in, data_out, reg_out);
    input           clk;
    input           rst;
    input           en;
    input           wr;
    input     [7:0] addr;
    input     [7:0] data_in;
    output    [7:0] data_out;
    output [2047:0] reg_out;

    reg [7:0] reg_save[255:0];

    assign data_out = reg_save[addr];
    assign reg_out = { reg_save[255], reg_save[254], reg_save[253], reg_save[252],
                       reg_save[251], reg_save[250], reg_save[249], reg_save[248],
                       reg_save[247], reg_save[246], reg_save[245], reg_save[244],
                       reg_save[243], reg_save[242], reg_save[241], reg_save[240],
                       reg_save[239], reg_save[238], reg_save[237], reg_save[236],
                       reg_save[235], reg_save[234], reg_save[233], reg_save[232],
                       reg_save[231], reg_save[230], reg_save[229], reg_save[228],
                       reg_save[227], reg_save[226], reg_save[225], reg_save[224],
                       reg_save[223], reg_save[222], reg_save[221], reg_save[220],
                       reg_save[219], reg_save[218], reg_save[217], reg_save[216],
                       reg_save[215], reg_save[214], reg_save[213], reg_save[212],
                       reg_save[211], reg_save[210], reg_save[209], reg_save[208],
                       reg_save[207], reg_save[206], reg_save[205], reg_save[204],
                       reg_save[203], reg_save[202], reg_save[201], reg_save[200],
                       reg_save[199], reg_save[198], reg_save[197], reg_save[196],
                       reg_save[195], reg_save[194], reg_save[193], reg_save[192],
                       reg_save[191], reg_save[190], reg_save[189], reg_save[188],
                       reg_save[187], reg_save[186], reg_save[185], reg_save[184],
                       reg_save[183], reg_save[182], reg_save[181], reg_save[180],
                       reg_save[179], reg_save[178], reg_save[177], reg_save[176],
                       reg_save[175], reg_save[174], reg_save[173], reg_save[172],
                       reg_save[171], reg_save[170], reg_save[169], reg_save[168],
                       reg_save[167], reg_save[166], reg_save[165], reg_save[164],
                       reg_save[163], reg_save[162], reg_save[161], reg_save[160],
                       reg_save[159], reg_save[158], reg_save[157], reg_save[156],
                       reg_save[155], reg_save[154], reg_save[153], reg_save[152],
                       reg_save[151], reg_save[150], reg_save[149], reg_save[148],
                       reg_save[147], reg_save[146], reg_save[145], reg_save[144],
                       reg_save[143], reg_save[142], reg_save[141], reg_save[140],
                       reg_save[139], reg_save[138], reg_save[137], reg_save[136],
                       reg_save[135], reg_save[134], reg_save[133], reg_save[132],
                       reg_save[131], reg_save[130], reg_save[129], reg_save[128],
                       reg_save[127], reg_save[126], reg_save[125], reg_save[124],
                       reg_save[123], reg_save[122], reg_save[121], reg_save[120],
                       reg_save[119], reg_save[118], reg_save[117], reg_save[116],
                       reg_save[115], reg_save[114], reg_save[113], reg_save[112],
                       reg_save[111], reg_save[110], reg_save[109], reg_save[108],
                       reg_save[107], reg_save[106], reg_save[105], reg_save[104],
                       reg_save[103], reg_save[102], reg_save[101], reg_save[100],
                       reg_save[99], reg_save[98], reg_save[97], reg_save[96],
                       reg_save[95], reg_save[94], reg_save[93], reg_save[92],
                       reg_save[91], reg_save[90], reg_save[89], reg_save[88],
                       reg_save[87], reg_save[86], reg_save[85], reg_save[84],
                       reg_save[83], reg_save[82], reg_save[81], reg_save[80],
                       reg_save[79], reg_save[78], reg_save[77], reg_save[76],
                       reg_save[75], reg_save[74], reg_save[73], reg_save[72],
                       reg_save[71], reg_save[70], reg_save[69], reg_save[68],
                       reg_save[67], reg_save[66], reg_save[65], reg_save[64],
                       reg_save[63], reg_save[62], reg_save[61], reg_save[60],
                       reg_save[59], reg_save[58], reg_save[57], reg_save[56],
                       reg_save[55], reg_save[54], reg_save[53], reg_save[52],
                       reg_save[51], reg_save[50], reg_save[49], reg_save[48],
                       reg_save[47], reg_save[46], reg_save[45], reg_save[44],
                       reg_save[43], reg_save[42], reg_save[41], reg_save[40],
                       reg_save[39], reg_save[38], reg_save[37], reg_save[36],
                       reg_save[35], reg_save[34], reg_save[33], reg_save[32],
                       reg_save[31], reg_save[30], reg_save[29], reg_save[28],
                       reg_save[27], reg_save[26], reg_save[25], reg_save[24],
                       reg_save[23], reg_save[22], reg_save[21], reg_save[20],
                       reg_save[19], reg_save[18], reg_save[17], reg_save[16],
                       reg_save[15], reg_save[14], reg_save[13], reg_save[12],
                       reg_save[11], reg_save[10], reg_save[9], reg_save[8],
                       reg_save[7], reg_save[6], reg_save[5], reg_save[4],
                       reg_save[3], reg_save[2], reg_save[1], reg_save[0]};

    integer i;
    always @(posedge clk)
    begin
        if (rst) begin
	  for(i=0;i<256;i=i+1)
	    reg_save[i] <= 8'b0;
        end
        else if(wr) begin
            reg_save[addr] <= data_in;
         end
    end
endmodule
