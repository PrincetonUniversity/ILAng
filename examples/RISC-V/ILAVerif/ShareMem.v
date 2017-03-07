module ShareMem(
    input clock, input reset,
    // *** DMEM Control outside
    input io_dmem_req_ready, // whether to accept or not
    //input io_dmem_replay_next, // --> reg --> io_dmem_resp_replay ( io_dmem_resp_valid )
    input io_dmem_replay_next_rand,   // can be 1 at any time (but only once , at the output)

    // *** IMEM Control outside
    input io_imem_resp_bits_replay,
    input io_imem_resp_valid, // you can keep valid and give more data than needed, untill the next cycle of a new valid request

    // *** DMEM Interface 
        // -- req
    input           io_dmem_s1_kill,
    input           io_dmem_req_valid,
    input [31:0]    io_dmem_req_bits_addr,
    input [6:0]     io_dmem_req_bits_tag,
    input [4:0]     io_dmem_req_bits_cmd,
    input [2:0]     io_dmem_req_bits_typ,
    input [31:0]    io_dmem_req_bits_data, // not this one
    input [31:0]    io_dmem_s1_data, // This is the true write data
        // -- resp
    output  [31:0] io_dmem_resp_bits_addr,
    output  [6:0] io_dmem_resp_bits_tag,
    output  [4:0] io_dmem_resp_bits_cmd,
    output  [2:0] io_dmem_resp_bits_typ,
    output  [31:0] io_dmem_resp_bits_data,
    output   io_dmem_resp_bits_has_data,

    output       io_dmem_s2_nack,
    output       io_dmem_replay_next,
    output   reg io_dmem_resp_valid,
    output       io_dmem_resp_bits_replay,
    output       io_dmem_ordered, // 

    // *** IMEM Interface
    input  io_imem_req_valid,
    input [31:0] io_imem_req_bits_pc,

    input   io_imem_resp_ready,
    output  [31:0] io_imem_resp_bits_pc,
    output  [31:0] io_imem_resp_bits_data,

    // *** Control Interface
    output      reg_mem_mismatch_nxt,

    // *** ILA Vlg Interface

    input [31:0] mem_raddr0,
    input [31:0] mem_raddr1,
    input [31:0] mem_raddr2,

    output  [31:0] mem_rdata0,
    output  [31:0] mem_rdata1,
    output  [31:0] mem_rdata2,

    input        mem_wen0,
    input [31:0] mem_waddr0,
    input [31:0] mem_wdata0,

    // *** additional port for fetch assertion

    input [29:0] pc_word_addr,
    output[31:0] pc_mem_inst,

    // additional s1_kill
    input ex_monitor,

    output load_not_ack_yet,
    output resp_a_non_monitored_req


     );
    reg [7:0] Mem[0:1023] ; // (12 bits) Finally it should be larger 0: 2**32-1  
    `define MEM_WIDTH 10

    // only for simulation purpose
    /*
    integer i;
    always @(posedge clock) begin
        if(reset) begin
            for(i=0;i<65536/4;i=i+1)
                {Mem[i*4+3],Mem[i*4+2],Mem[i*4+1],Mem[i*4+0]} <= 32'h42802e23; // 32'h3c0006f;
        end
    end
    */

    // only for jasperGold
    integer i;
    always @(posedge clock) begin
        for(i=0;i<=1023;i+=1)
            Mem[i] <= Mem[i];
    end

    // *** IMEM related interface control
    reg [31:0] io_imem_req_bits_pc_reg;
    wire[31:0] io_imem_req_bits_pc_reg_1 = io_imem_req_bits_pc_reg + 1;
    wire[31:0] io_imem_req_bits_pc_reg_2 = io_imem_req_bits_pc_reg + 2;
    wire[31:0] io_imem_req_bits_pc_reg_3 = io_imem_req_bits_pc_reg + 3;
    assign io_imem_resp_bits_data = {    Mem[io_imem_req_bits_pc_reg_3[`MEM_WIDTH-1:0]],
                                         Mem[io_imem_req_bits_pc_reg_2[`MEM_WIDTH-1:0]],
                                         Mem[io_imem_req_bits_pc_reg_1[`MEM_WIDTH-1:0]],
                                         Mem[io_imem_req_bits_pc_reg  [`MEM_WIDTH-1:0]]
                                         };
    always @(posedge clock) begin
         if (reset) begin
             io_imem_req_bits_pc_reg <= 32'd4096;
         end
         else begin
            if (io_imem_req_valid)  // req is ready all the time!
                io_imem_req_bits_pc_reg <= io_imem_req_bits_pc;
            else if (io_imem_resp_valid && io_imem_resp_ready) begin
                io_imem_req_bits_pc_reg <= io_imem_req_bits_pc_reg + 32'd4;
            end
        end
     end 
     assign io_imem_resp_bits_pc = io_imem_req_bits_pc_reg;
     // *** DMEM related interface control

     reg io_dmem_ordered_0;
     reg io_dmem_ordered_1;
     reg dmem_req_valid_buf_0;
     reg dmem_req_valid_buf_1;
     reg dmem_req_valid;

     wire valid_buf0_input = io_dmem_req_valid & io_dmem_req_ready;
     wire valid_buf1_input = dmem_req_valid_buf_0 & ~io_dmem_s1_kill; // use ex_monitor to kill unrelated (not belonging to this instruction)
     wire valid_buf__input = ( dmem_req_valid_buf_1 & ~io_dmem_s2_nack ) ?  dmem_req_valid_buf_1 :   ( io_dmem_resp_valid ? 1'b0 : dmem_req_valid );

     always @(posedge clock) begin
         if(reset) begin
             dmem_req_valid_buf_0 <= 1'b0;
             dmem_req_valid_buf_1 <= 1'b0;
             dmem_req_valid       <= 1'b0;
         end
         else begin
             dmem_req_valid_buf_0 <= valid_buf0_input;
             dmem_req_valid_buf_1 <= valid_buf1_input;
             dmem_req_valid <= valid_buf__input;
         end
     end

    assign io_dmem_s2_nack = dmem_req_valid_buf_1 & ( ( dmem_req_valid & ~ ( io_dmem_resp_valid ) ) | ~io_dmem_ordered_1 );
    assign io_dmem_replay_next = dmem_req_valid & ( ~ io_dmem_resp_valid ) & io_dmem_replay_next_rand;

    // if it is 1, then definitely it will be canceled
    assign io_dmem_ordered = ~( (valid_buf0_input & valid_buf1_input ) |
                                (valid_buf1_input & valid_buf__input ) |
                                (valid_buf0_input & valid_buf__input ) ) ;

    always @(posedge clock) begin
      io_dmem_resp_valid <= io_dmem_replay_next;
    end
    assign io_dmem_resp_bits_replay = io_dmem_resp_valid;


    always @(posedge clock) begin
        if (reset) begin
            io_dmem_ordered_0 <= 1'b0;
            io_dmem_ordered_1 <= 1'b0;
        end
        else begin
            io_dmem_ordered_0 <= io_dmem_ordered;
            io_dmem_ordered_1 <= io_dmem_ordered_0;
        end
    end

    // **** LOGGING **** //

    reg [31:0]    dmem_req_addr_0;
    reg [6:0]     dmem_req_tag_0;
    reg [4:0]     dmem_req_cmd_0;
    reg [2:0]     dmem_req_typ_0;
    reg [31:0]    dmem_req_data_0;

    reg [31:0]    dmem_req_addr_1;
    reg [6:0]     dmem_req_tag_1;
    reg [4:0]     dmem_req_cmd_1;
    reg [2:0]     dmem_req_typ_1;
    reg [31:0]    dmem_req_data_1;

    reg ex_monitor_1;
    reg ex_monitor_eff=0;

    reg [31:0]    dmem_req_addr;
    reg [6:0]     dmem_req_tag;
    reg [4:0]     dmem_req_cmd;
    reg [2:0]     dmem_req_typ;
    reg [31:0]    dmem_req_data;

    always @(posedge clock) begin
        if(reset) begin
            ex_monitor_eff <= 1'b0;
        end
        dmem_req_addr_0 <= io_dmem_req_bits_addr;
        dmem_req_tag_0  <= io_dmem_req_bits_tag;
        dmem_req_cmd_0  <= io_dmem_req_bits_cmd;
        dmem_req_typ_0  <= io_dmem_req_bits_typ;
        dmem_req_data_0 <= io_dmem_req_bits_data; // This is no use!

        dmem_req_addr_1 <= dmem_req_addr_0;
        dmem_req_tag_1  <= dmem_req_tag_0;
        dmem_req_cmd_1  <= dmem_req_cmd_0;
        dmem_req_typ_1  <= dmem_req_typ_0;
        dmem_req_data_1 <= io_dmem_s1_data;
        ex_monitor_1    <= ex_monitor;

        if(dmem_req_valid_buf_1 & ~io_dmem_s2_nack) begin
            dmem_req_addr <= dmem_req_addr_1;
            dmem_req_tag  <= dmem_req_tag_1;
            dmem_req_cmd  <= dmem_req_cmd_1;
            dmem_req_typ  <= dmem_req_typ_1;
            dmem_req_data <= dmem_req_data_1;
            ex_monitor_eff <= ex_monitor_1;
        end
    end

    // *** LOAD sequence monitor auxiliary output
    assign load_not_ack_yet =   (ex_monitor_eff & dmem_req_valid)  |  // REQ valid
                                (dmem_req_valid_buf_1 & ~io_dmem_s2_nack & ex_monitor_1);

    assign resp_a_non_monitored_req = (dmem_req_valid & ~ex_monitor_eff & io_dmem_resp_valid & (dmem_req_cmd == 0) ); // 
    
    // *** END of LOAD sequence monitor auxiliary output

    assign io_dmem_resp_bits_addr = dmem_req_addr;
    assign io_dmem_resp_bits_tag = dmem_req_tag;
    assign io_dmem_resp_bits_cmd = dmem_req_cmd;
    assign io_dmem_resp_bits_typ = dmem_req_typ;

    wire [31:0] dmem_req_addr1 = dmem_req_addr + 1;
    wire [31:0] dmem_req_addr2 = dmem_req_addr + 2;
    wire [31:0] dmem_req_addr3 = dmem_req_addr + 3;
    wire [31:0] dmem_req_rdata  = {Mem[dmem_req_addr3[`MEM_WIDTH-1:0]], Mem[dmem_req_addr2[`MEM_WIDTH-1:0]], Mem[dmem_req_addr1[`MEM_WIDTH-1:0]], Mem[dmem_req_addr[`MEM_WIDTH-1:0]]};

    assign io_dmem_resp_bits_data = ( io_dmem_resp_bits_cmd == 0 ) ? dmem_req_rdata : 32'hxxxxxxxx;
    assign io_dmem_resp_bits_has_data = ( io_dmem_resp_bits_cmd == 0 ); // if it is read(0),  then reply with data

    reg        IMPL_mod_dirty;
    reg [29:0] IMPL_mod_word_addr;
    reg [31:0] IMPL_mod_word_data;

    always @(posedge clock) begin
        if(reset)
            IMPL_mod_dirty <= 1'b0;
        else begin
            if( io_dmem_resp_bits_cmd == 1 && dmem_req_valid && ex_monitor_eff ) // ~inst_finished &
                IMPL_mod_dirty <= 1'b1;
        end
    end

    wire[1:0]  offset_wr_addr  = io_dmem_resp_bits_addr[1:0];
    wire[31:0] aligned_wr_addr = {io_dmem_resp_bits_addr[31:2], 2'b00};
    wire[31:0] aligned_wr_addr0 = aligned_wr_addr+32'd0;
    wire[31:0] aligned_wr_addr1 = aligned_wr_addr+32'd1;
    wire[31:0] aligned_wr_addr2 = aligned_wr_addr+32'd2;
    wire[31:0] aligned_wr_addr3 = aligned_wr_addr+32'd3;
    wire[31:0]  aligned_data    = { Mem[aligned_wr_addr3[`MEM_WIDTH-1:0]], Mem[aligned_wr_addr2[`MEM_WIDTH-1:0]], Mem[aligned_wr_addr1[`MEM_WIDTH-1:0]], Mem[aligned_wr_addr0[`MEM_WIDTH-1:0]] };

    reg[31:0]  Mask;
    reg[31:0]  OffsetData;
    always @(*) begin
        if(io_dmem_resp_bits_typ == 0)      // Byte
            Mask = 32'h000000ff << (offset_wr_addr)*8;
        else if(io_dmem_resp_bits_typ == 1) // Half
            Mask = 32'h0000ffff << (offset_wr_addr)*8;
        else if(io_dmem_resp_bits_typ == 2) // Word
            Mask = 32'hffffffff;
        else
            Mask = 32'hxxxxxxxx;
    end

    always @(*) begin
        if(io_dmem_resp_bits_typ == 0)      // Byte
            OffsetData = {24'h0, dmem_req_data[ 7:0] } << (offset_wr_addr)*8;
        else if(io_dmem_resp_bits_typ == 1) // Half
            OffsetData = {16'h0, dmem_req_data[15:0] } << (offset_wr_addr)*8;
        else if(io_dmem_resp_bits_typ == 2) // Word
            OffsetData = dmem_req_data;
        else
            OffsetData = 32'hxxxxxxxx;
    end

    always @(posedge clock) begin
        if( io_dmem_resp_bits_cmd == 1 && dmem_req_valid && ex_monitor_eff ) begin // ~inst_finished &&
            IMPL_mod_word_addr <= io_dmem_resp_bits_addr[31:2];
            IMPL_mod_word_data <= ( aligned_data & (~Mask) ) | ( OffsetData & Mask );
        end
    end


    // *** GM Part MEM

    wire[31:0] byteAddr0 = {mem_raddr0[29:0], 2'b00};
    wire[31:0] byteAddr00 = byteAddr0+32'd0;
    wire[31:0] byteAddr01 = byteAddr0+32'd1;
    wire[31:0] byteAddr02 = byteAddr0+32'd2;
    wire[31:0] byteAddr03 = byteAddr0+32'd3;

    assign mem_rdata0 = { Mem[ byteAddr03[`MEM_WIDTH-1:0] ] , Mem[byteAddr02[`MEM_WIDTH-1:0]] , Mem[byteAddr01[`MEM_WIDTH-1:0]] ,  Mem[byteAddr00[`MEM_WIDTH-1:0]]}; //Mem[byteAddr0+32'd0] }; 

    wire[31:0] byteAddr1 = {mem_raddr1[29:0], 2'b00};
    wire[31:0] byteAddr10 = byteAddr1+32'd0;
    wire[31:0] byteAddr11 = byteAddr1+32'd1;
    wire[31:0] byteAddr12 = byteAddr1+32'd2;
    wire[31:0] byteAddr13 = byteAddr1+32'd3;
    assign mem_rdata1 = { Mem[byteAddr13[`MEM_WIDTH-1:0]] , Mem[byteAddr12[`MEM_WIDTH-1:0]] , Mem[byteAddr11[`MEM_WIDTH-1:0]] , Mem[byteAddr10[`MEM_WIDTH-1:0]] }; 

    wire[31:0] byteAddr2 = {mem_raddr2[29:0], 2'b00};
    wire[31:0] byteAddr20 = byteAddr2+32'd0;
    wire[31:0] byteAddr21 = byteAddr2+32'd1;
    wire[31:0] byteAddr22 = byteAddr2+32'd2;
    wire[31:0] byteAddr23 = byteAddr2+32'd3;
    assign mem_rdata2 = { Mem[byteAddr23[`MEM_WIDTH-1:0]] , Mem[byteAddr22[`MEM_WIDTH-1:0]] , Mem[byteAddr21[`MEM_WIDTH-1:0]] , Mem[byteAddr20[`MEM_WIDTH-1:0]] }; 

    reg        GM_mod_dirty;
    reg [29:0] GM_mod_word_addr;
    reg [31:0] GM_mod_word_data;
    // need to apply mask!

    always @(posedge clock) begin
        if(reset)
            GM_mod_dirty <= 1'b0;
        else if(mem_wen0) begin
            GM_mod_dirty <= 1'b1;
            GM_mod_word_addr <= mem_waddr0[29:0];
            GM_mod_word_data <= mem_wdata0;
        end
    end

    // *** Mem Compare Logic
    assign reg_mem_mismatch_nxt = GM_mod_dirty != IMPL_mod_dirty ? 1'b1: (
                               (GM_mod_dirty == 0 && IMPL_mod_dirty == 0 ) ? 1'b0:
                               (GM_mod_word_addr != IMPL_mod_word_addr) || (GM_mod_word_data != IMPL_mod_word_data) );

    wire[31:0] pc_byte_addr0 = {pc_word_addr,2'd0};
    wire[31:0] pc_byte_addr1 = {pc_word_addr,2'd1};
    wire[31:0] pc_byte_addr2 = {pc_word_addr,2'd2};
    wire[31:0] pc_byte_addr3 = {pc_word_addr,2'd3};
    wire[7:0]  pc_index_test =  Mem[pc_byte_addr0[`MEM_WIDTH-1:0]];

    assign pc_mem_inst = { Mem[pc_byte_addr3[`MEM_WIDTH-1:0]], Mem[pc_byte_addr2[`MEM_WIDTH-1:0]], Mem[pc_byte_addr1[`MEM_WIDTH-1:0]], pc_index_test}; //Mem[pc_byte_addr0] };



endmodule