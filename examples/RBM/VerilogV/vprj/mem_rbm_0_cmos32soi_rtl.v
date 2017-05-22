/**
 * Copyright (c) 2014-2015, Columbia University
 *
 * @author Christian Pilato <pilato@cs.columbia.edu>
 */

 `define NUM_MOVIE_MAX 100
 `define NUM_VISIBLE_MAX_1 501

module rbm_0_data(CLK, 
    rbm_0_data_CE0, 
    rbm_0_data_A0, 
    rbm_0_data_D0, 
    rbm_0_data_WE0, 
    rbm_0_data_WEM0, 
    rbm_0_data_CE2, 
    rbm_0_data_A2, 
    rbm_0_data_Q2, 
    rbm_0_data_CE1, 
    rbm_0_data_A1, 
    rbm_0_data_Q1,

    gm_raddr0,
    gm_rdata0,

    gm_waddr0,
    gm_wen0,
    gm_wdata0,

    gm_step,
    gm_sel,
    gm_compare,
    impl_rec,
    mismatch,
    RST
    );
  input CLK;
  //buffer: data - process: load - interface: W
  input rbm_0_data_CE0;
  input [9:0] rbm_0_data_A0;
  input [7:0] rbm_0_data_D0;
  input rbm_0_data_WE0;
  input [7:0] rbm_0_data_WEM0;
  //buffer: data - process: train_rbm - interface: R
  input rbm_0_data_CE2;
  input [9:0] rbm_0_data_A2;
  output [7:0] rbm_0_data_Q2;
  //buffer: data - process: predict_rbm - interface: R
  input rbm_0_data_CE1;
  input [9:0] rbm_0_data_A1;
  output [7:0] rbm_0_data_Q1;

  // newly added
  input RST;
  input gm_step;
  input gm_sel;
  input gm_compare;
  input impl_rec;
  output mismatch;

  input [8:0] gm_raddr0;
  output [7:0] gm_rdata0;

  input [8:0] gm_waddr0;
  input gm_wen0;
  input [7:0] gm_wdata0;

  wire [8:0] gm_praddr = gm_raddr0 ; // gm_sel ? {1'b0,gm_raddr0} + `NUM_VISIBLE_MAX_1 : {1'b0,gm_raddr0} ;
  wire [8:0] gm_pwaddr = gm_waddr0 ; // gm_sel ? {1'b0,gm_waddr0} + `NUM_VISIBLE_MAX_1 : {1'b0,gm_waddr0} ;

  wire [8:0] rbm_0_data_A0_r = rbm_0_data_A0 >= `NUM_VISIBLE_MAX_1 ? rbm_0_data_A0-1 : rbm_0_data_A0;
  wire [8:0] rbm_0_data_A1_r = rbm_0_data_A1 >= `NUM_VISIBLE_MAX_1 ? rbm_0_data_A1-1 : rbm_0_data_A1;
  wire [8:0] rbm_0_data_A2_r = rbm_0_data_A2 >= `NUM_VISIBLE_MAX_1 ? rbm_0_data_A2-1 : rbm_0_data_A2;


// Let's use jg for read 
   wire concrete_val_0;
   wire concrete_val_1;
   wire concrete_val_2;
    jasper_model_mpram #( 
        .READ_PORTS(2+1),
        .WRITE_PORTS(1),
        .ADDR_WIDTH(9),
        .DATA_WIDTH(8),
        .MAX_DEPTH(4),
        .MEM_STYLE(0),
        .RESET_STYLE(0),
        .RD_DATA_DLY(0)
        )
    mem_mpram
    (
        .clk(CLK),
        .rstN(~RST),
        .addr_rd( 
            { rbm_0_data_A1_r, rbm_0_data_A2_r, gm_praddr }),
        .data_rd(
            { rbm_0_data_Q1_d, rbm_0_data_Q2_d, gm_rdata0}),
        .read_allocate(
            {   impl_rec & rbm_0_data_CE1, 
                impl_rec & rbm_0_data_CE2,
                gm_step} ),
        .read( {1'b1,1'b1,1'b1} ),

        .write( {1'b0} ),
        .write_allocate( {1'b0} ),
        .addr_wr({10'd0}),
        .data_wr({8'd0}),
        .concrete({concrete_val_0, concrete_val_1, concrete_val_2 })
    );
    

  wire [7:0] rbm_0_data_Q1_d;
  reg  [7:0] rbm_0_data_Q1_q;
  wire [7:0] rbm_0_data_Q2_d;
  reg  [7:0] rbm_0_data_Q2_q;
  assign rbm_0_data_Q1 = rbm_0_data_Q1_q;
  assign rbm_0_data_Q2 = rbm_0_data_Q2_q;
  always @(posedge CLK) begin
    rbm_0_data_Q1_q <= rbm_0_data_Q1_d;
  end
  always @(posedge CLK) begin
    rbm_0_data_Q2_q <= rbm_0_data_Q2_d;
  end

// And buffer for write

    reg [7:0] IMPL_data;
    reg [8:0] IMPL_addr;
    reg       IMPL_dirty;

    reg [7:0] GM_data;
    reg [8:0] GM_addr;
    reg       GM_dirty;

    always @(posedge CLK) begin
        if(RST) begin
            IMPL_dirty <= 1'b0;
            GM_dirty <= 1'b0;
        end
        else begin
            if(impl_rec & rbm_0_data_WE0 & rbm_0_data_CE0)  begin
                IMPL_dirty <= 1'b1;
                IMPL_addr  <= rbm_0_data_A0_r;
                IMPL_data  <= rbm_0_data_D0;
            end

            if (gm_step & gm_wen0) begin
                GM_dirty <= 1'b1;
                GM_addr  <= gm_pwaddr;
                GM_data  <= gm_wdata0;
            end
        end
    end

    assign mismatch = (~gm_compare) ? 1'b0 :
                      (IMPL_dirty != GM_dirty) ? 1'b1 :
                      (IMPL_dirty == 1'b0) ? 1'b0 :
                      (IMPL_addr != GM_addr) ? 1'b1 :
                      (IMPL_data != GM_data) ? 1'b1 :
                      1'b0;
endmodule




module rbm_0_edges(CLK, rbm_0_edges_CE0, rbm_0_edges_A0, rbm_0_edges_D0, rbm_0_edges_WE0, rbm_0_edges_WEM0, rbm_0_edges_CE2, rbm_0_edges_A2, rbm_0_edges_Q2, rbm_0_edges_CE1, rbm_0_edges_A1, rbm_0_edges_Q1,

    gm_raddr0,
    gm_rdata0,

    gm_waddr0,
    gm_wen0,
    gm_wdata0,

    gm_step,
    gm_compare,
    impl_rec,
    mismatch,
    RST );
  input CLK;
  //buffer: edges - process: train_rbm - interface: W
  input rbm_0_edges_CE0;
  input [15:0] rbm_0_edges_A0;
  input [7:0] rbm_0_edges_D0;
  input rbm_0_edges_WE0;
  input [7:0] rbm_0_edges_WEM0;
  //buffer: edges - process: train_rbm - interface: R
  input rbm_0_edges_CE2;
  input [15:0] rbm_0_edges_A2;
  output [7:0] rbm_0_edges_Q2;
  //buffer: edges - process: predict_rbm - interface: R
  input rbm_0_edges_CE1;
  input [15:0] rbm_0_edges_A1;
  output [7:0] rbm_0_edges_Q1;


  // newly added
  input RST;
  input impl_rec;
  input gm_step;
  input gm_compare;
  output mismatch;

  input [15:0] gm_raddr0;
  output [7:0] gm_rdata0;

  input [15:0] gm_waddr0;
  input gm_wen0;
  input [7:0] gm_wdata0;


// Let's use jg for read 
   wire concrete_val_0;
   wire concrete_val_1;
   wire concrete_val_2;
    jasper_model_mpram #( 
        .READ_PORTS(2+1),
        .WRITE_PORTS(1),
        .ADDR_WIDTH(10),
        .DATA_WIDTH(8),
        .MAX_DEPTH(4),
        .MEM_STYLE(0),
        .RESET_STYLE(0),
        .RD_DATA_DLY(0)
        )
    mem_mpram
    (
        .clk(CLK),
        .rstN(~RST),
        .addr_rd( 
            { rbm_0_edges_A1, rbm_0_edges_A2, { gm_raddr0}  }),
        .data_rd(
            { rbm_0_edges_Q1_d, rbm_0_edges_Q2_d, gm_rdata0}),
        .read_allocate(
            {   impl_rec & rbm_0_edges_CE1, 
                impl_rec & rbm_0_edges_CE2,
                gm_step} ),
        .read( {1'b1,1'b1,1'b1} ),

        .write( {1'b0} ),
        .write_allocate( {1'b0} ),
        .addr_wr({10'd0}),
        .data_wr({8'd0}),
        .concrete({concrete_val_0, concrete_val_1, concrete_val_2 })
    );
    
  wire [7:0] rbm_0_edges_Q1_d;
  reg  [7:0] rbm_0_edges_Q1_q;
  wire [7:0] rbm_0_edges_Q2_d;
  reg  [7:0] rbm_0_edges_Q2_q;
  assign rbm_0_edges_Q1 = rbm_0_edges_Q1_q;
  assign rbm_0_edges_Q2 = rbm_0_edges_Q2_q;
  always @(posedge CLK) begin
    rbm_0_edges_Q1_q <= rbm_0_edges_Q1_d;
  end
  always @(posedge CLK) begin
    rbm_0_edges_Q2_q <= rbm_0_edges_Q2_d;
  end

// And buffer for write

    reg [7:0] IMPL_data;
    reg [15:0] IMPL_addr;
    reg       IMPL_dirty;

    reg [7:0] GM_data;
    reg [15:0] GM_addr;
    reg       GM_dirty;

    always @(posedge CLK) begin
        if(RST) begin
            IMPL_dirty <= 1'b0;
            GM_dirty <= 1'b0;
        end
        else begin
            if(impl_rec & rbm_0_edges_WE0 & rbm_0_edges_CE0)  begin
                IMPL_dirty <= 1'b1;
                IMPL_addr  <= rbm_0_edges_A0;
                IMPL_data  <= rbm_0_edges_D0;
            end

            if (gm_step & gm_wen0) begin
                GM_dirty <= 1'b1;
                GM_addr  <= {gm_waddr0};
                GM_data  <= gm_wdata0;
            end
        end
    end

    assign mismatch = (~gm_compare) ? 1'b0 :
                      (IMPL_dirty != GM_dirty) ? 1'b1 :
                      (IMPL_dirty == 1'b0) ? 1'b0 :
                      (IMPL_addr != GM_addr) ? 1'b1 :
                      (IMPL_data != GM_data) ? 1'b1 :
                      1'b0;
endmodule

// ** PLEASE CONTINUE TO WORK FROM HERE! ** //

module rbm_0_hidden_unit(CLK, rbm_0_hidden_unit_CE1, rbm_0_hidden_unit_A1, rbm_0_hidden_unit_D1, rbm_0_hidden_unit_WE1, rbm_0_hidden_unit_WEM1, rbm_0_hidden_unit_CE3, rbm_0_hidden_unit_A3, rbm_0_hidden_unit_Q3, rbm_0_hidden_unit_CE0, rbm_0_hidden_unit_A0, rbm_0_hidden_unit_D0, rbm_0_hidden_unit_WE0, rbm_0_hidden_unit_WEM0, rbm_0_hidden_unit_CE2, rbm_0_hidden_unit_A2, rbm_0_hidden_unit_Q2,

    gm_raddr0,
    gm_rdata0,

    gm_waddr0,
    gm_wen0,
    gm_wdata0,

    gm_waddr1,
    gm_wen1,
    gm_wdata1,

    gm_step,
    gm_compare,
    impl_rec,
    impl_sel,
    mismatch,
    RST 
    );
  input CLK;
  //buffer: hidden_unit - process: train_rbm - interface: W
  input rbm_0_hidden_unit_CE1;
  input [6:0] rbm_0_hidden_unit_A1;
  input rbm_0_hidden_unit_D1;
  input rbm_0_hidden_unit_WE1;
  input rbm_0_hidden_unit_WEM1;
  //buffer: hidden_unit - process: train_rbm - interface: R
  input rbm_0_hidden_unit_CE3;
  input [6:0] rbm_0_hidden_unit_A3;
  output rbm_0_hidden_unit_Q3;
  //buffer: hidden_unit - process: predict_rbm - interface: W
  input rbm_0_hidden_unit_CE0;
  input [6:0] rbm_0_hidden_unit_A0;
  input rbm_0_hidden_unit_D0;
  input rbm_0_hidden_unit_WE0;
  input rbm_0_hidden_unit_WEM0;
  //buffer: hidden_unit - process: predict_rbm - interface: R
  input rbm_0_hidden_unit_CE2;
  input [6:0] rbm_0_hidden_unit_A2;
  output rbm_0_hidden_unit_Q2;



  // newly added
  input RST;
  input impl_rec;
  input impl_sel;

  input gm_step;
  input gm_compare;
  output mismatch;

  input [ 6:0] gm_raddr0;
  output       gm_rdata0;

  input [ 6:0] gm_waddr0;
  input        gm_wen0;
  input        gm_wdata0;

  input [ 6:0] gm_waddr1;
  input        gm_wen1;
  input        gm_wdata1;

  wire IMPL_CE          = impl_sel ? rbm_0_hidden_unit_CE1 : rbm_0_hidden_unit_CE0;
  wire [6:0] IMPL_A     = impl_sel ? rbm_0_hidden_unit_A1  : rbm_0_hidden_unit_A0;
  wire        IMPL_D    = impl_sel ? rbm_0_hidden_unit_D1  : rbm_0_hidden_unit_D0;
  wire IMPL_WE          = impl_sel ? rbm_0_hidden_unit_WE1 : rbm_0_hidden_unit_WE0;


// Let's use jg for read 
   wire concrete_val_0;
   wire concrete_val_1;
   wire concrete_val_2;
    jasper_model_mpram #( 
        .READ_PORTS(2+1),
        .WRITE_PORTS(1),
        .ADDR_WIDTH(7),
        .DATA_WIDTH(1),
        .MAX_DEPTH(8),
        .MEM_STYLE(0),
        .RESET_STYLE(0),
        .RD_DATA_DLY(0)
        )
    mem_mpram
    (
        .clk(CLK),
        .rstN(~RST),
        .addr_rd( 
            { rbm_0_hidden_unit_A2, rbm_0_hidden_unit_A3, { gm_raddr0}  }),
        .data_rd(
            { rbm_0_hidden_unit_Q2_d, rbm_0_hidden_unit_Q3_d,  gm_rdata0 }),
        .read_allocate(
            {   impl_rec & rbm_0_hidden_unit_CE2, 
                impl_rec & rbm_0_hidden_unit_CE3,
                gm_step} ),
        .read( {1'b1,1'b1,1'b1} ),

        .write( {1'b0} ),
        .write_allocate( {1'b0} ),
        .addr_wr({7'd0}),
        .data_wr({1'd0}),
        .concrete({concrete_val_0, concrete_val_1, concrete_val_2 })
    );
    
  wire rbm_0_hidden_unit_Q3_d;
  reg  rbm_0_hidden_unit_Q3_q;
  wire rbm_0_hidden_unit_Q2_d;
  reg  rbm_0_hidden_unit_Q2_q;
  assign rbm_0_hidden_unit_Q3 = rbm_0_hidden_unit_Q3_q;
  assign rbm_0_hidden_unit_Q2 = rbm_0_hidden_unit_Q2_q;
  always @(posedge CLK) begin
    rbm_0_hidden_unit_Q3_q <= rbm_0_hidden_unit_Q3_d;
  end
  always @(posedge CLK) begin
    rbm_0_hidden_unit_Q2_q <= rbm_0_hidden_unit_Q2_d;
  end

// And buffer for write

    reg        IMPL_data0;
    reg [ 6:0] IMPL_addr0;
    reg        IMPL_dirty0;

    reg        IMPL_data1;
    reg [ 6:0] IMPL_addr1;
    reg        IMPL_dirty1;

    reg        GM_data0;
    reg [ 6:0] GM_addr0;
    reg        GM_dirty0;

    reg        GM_data1;
    reg [ 6:0] GM_addr1;
    reg        GM_dirty1;

    always @(posedge CLK) begin
        if(RST) begin
            IMPL_dirty0 <= 1'b0;
            IMPL_dirty1 <= 1'b0;
        end
        else begin
            if(impl_rec & IMPL_CE & IMPL_WE  & ~ IMPL_dirty0 ) begin
                IMPL_dirty0 <= 1'b1;
                IMPL_addr0  <= IMPL_A;
                IMPL_data0  <= IMPL_D;
            end
            else if(impl_rec & IMPL_CE & IMPL_WE  & IMPL_dirty0 ) begin
                IMPL_dirty1 <= 1'b1;
                IMPL_addr1  <= IMPL_A;
                IMPL_data1  <= IMPL_D;
            end
        end
    end

    always @(posedge CLK) begin
        if(RST) begin
            GM_dirty0 <= 1'b0;
            GM_dirty1 <= 1'b0;
        end
        else begin
            if(gm_step & gm_wen0 ) begin
                GM_dirty0 <= 1'b1;
                GM_addr0  <= IMPL_A;
                GM_data0  <= IMPL_D;
            end
            else if(gm_step & gm_wen1 ) begin
                GM_dirty1 <= 1'b1;
                GM_addr1  <= IMPL_A;
                GM_data1  <= IMPL_D;
            end
        end
    end

    wire mismatch_0 = (~gm_compare) ? 1'b0 :
                      (IMPL_dirty0 != GM_dirty0) ? 1'b1 :
                      (IMPL_dirty0 == 0) ? 1'b0 :
                      (IMPL_addr0 != GM_addr0) ? 1'b1 :
                      (IMPL_data0 != GM_data0) ? 1'b1 :
                      1'b0;

    wire mismatch_1 = (~gm_compare) ? 1'b0 :
                      (IMPL_dirty1 != GM_dirty1) ? 1'b1 :
                      (IMPL_dirty1 == 0) ? 1'b0 :
                      (IMPL_addr1 != GM_addr1) ? 1'b1 :
                      (IMPL_data1 != GM_data1) ? 1'b1 :
                      1'b0;
    assign mismatch = mismatch_0 | mismatch_1;

endmodule




module rbm_0_mt(CLK, rbm_0_mt_CE0, rbm_0_mt_A0, rbm_0_mt_D0, rbm_0_mt_WE0, rbm_0_mt_WEM0, rbm_0_mt_CE1, rbm_0_mt_A1, rbm_0_mt_Q1, 
     RST);
  input CLK;
  //buffer: mt - process: train_rbm - interface: W
  input rbm_0_mt_CE0;
  input [9:0] rbm_0_mt_A0;
  input [31:0] rbm_0_mt_D0;
  input rbm_0_mt_WE0;
  input [31:0] rbm_0_mt_WEM0;
  //buffer: mt - process: train_rbm - interface: R
  input rbm_0_mt_CE1;
  input [9:0] rbm_0_mt_A1;
  output [31:0] rbm_0_mt_Q1;

  input RST;


   wire concrete_val_0;
    jasper_model_mpram #( 
        .READ_PORTS(1),
        .WRITE_PORTS(1),
        .ADDR_WIDTH(10),
        .DATA_WIDTH(32),
        .MAX_DEPTH(4),
        .MEM_STYLE(0),
        .RESET_STYLE(0),
        .RD_DATA_DLY(1)
        )
    mem_mpram
    (
        .clk(CLK),
        .rstN(~RST),
        .addr_rd( 
            { rbm_0_mt_A1 }),
        .data_rd(
            { rbm_0_mt_Q1 }),
        .read_allocate(
            {   rbm_0_mt_CE1 } ),
        .read( {1'b1 } ),

        .write( {rbm_0_mt_WE0} ),
        .write_allocate( {rbm_0_mt_CE0} ),
        .addr_wr({rbm_0_mt_A0}),
        .data_wr({rbm_0_mt_D0}),
        .concrete({concrete_val_0 })
    );


endmodule

module rbm_0_neg(CLK, rbm_0_neg_CE0, rbm_0_neg_A0, rbm_0_neg_D0, rbm_0_neg_WE0, rbm_0_neg_WEM0, rbm_0_neg_CE1, rbm_0_neg_A1, rbm_0_neg_Q1,
         RST);
  input CLK;
  //buffer: neg - process: train_rbm - interface: W
  input rbm_0_neg_CE0;
  input [15:0] rbm_0_neg_A0;
  input rbm_0_neg_D0;
  input rbm_0_neg_WE0;
  input rbm_0_neg_WEM0;
  //buffer: neg - process: train_rbm - interface: R
  input rbm_0_neg_CE1;
  input [15:0] rbm_0_neg_A1;
  output rbm_0_neg_Q1;


  input RST;

  // Let's apply jg abstraction


   wire concrete_val_0;
    jasper_model_mpram #( 
        .READ_PORTS(1),
        .WRITE_PORTS(1),
        .ADDR_WIDTH(16),
        .DATA_WIDTH(1),
        .MAX_DEPTH(4),
        .MEM_STYLE(0),
        .RESET_STYLE(0),
        .RD_DATA_DLY(1)
        )
    mem_mpram
    (
        .clk(CLK),
        .rstN(~RST),
        .addr_rd( 
            { rbm_0_neg_A1 }),
        .data_rd(
            { rbm_0_neg_Q1 }),
        .read_allocate(
            {   rbm_0_neg_CE1 } ),
        .read( {1'b1 } ),

        .write( {rbm_0_neg_WE0} ),
        .write_allocate( {rbm_0_neg_CE0} ),
        .addr_wr({rbm_0_neg_A0}),
        .data_wr({rbm_0_neg_D0}),
        .concrete({concrete_val_0 })
    );

    endmodule

module rbm_0_pos(CLK, rbm_0_pos_CE0, rbm_0_pos_A0, rbm_0_pos_D0, rbm_0_pos_WE0, rbm_0_pos_WEM0, rbm_0_pos_CE1, rbm_0_pos_A1, rbm_0_pos_Q1,

    gm_raddr0,
    gm_rdata0,

    gm_waddr0,
    gm_wen0,
    gm_wdata0,

    gm_step,
    gm_compare,
    impl_rec,
    mismatch,
    RST );
  input CLK;
  //buffer: pos - process: train_rbm - interface: W
  input rbm_0_pos_CE0;
  input [15:0] rbm_0_pos_A0;
  input rbm_0_pos_D0;
  input rbm_0_pos_WE0;
  input rbm_0_pos_WEM0;
  //buffer: pos - process: train_rbm - interface: R
  input rbm_0_pos_CE1;
  input [15:0] rbm_0_pos_A1;
  output rbm_0_pos_Q1;

  // newly added
  input RST;
  input impl_rec;
  input gm_step;
  input gm_compare;
  output mismatch;

  input [15:0] gm_raddr0;
  output       gm_rdata0;

  input [15:0] gm_waddr0;
  input        gm_wen0;
  input        gm_wdata0;


// Let's use jg for read 
   wire concrete_val_0;
   wire concrete_val_1;
    jasper_model_mpram #( 
        .READ_PORTS(1+1),
        .WRITE_PORTS(1),
        .ADDR_WIDTH(16),
        .DATA_WIDTH(1),
        .MAX_DEPTH(8),
        .MEM_STYLE(0),
        .RESET_STYLE(0),
        .RD_DATA_DLY(0)
        )
    mem_mpram
    (
        .clk(CLK),
        .rstN(~RST),
        .addr_rd( 
            { rbm_0_pos_A1, { gm_raddr0}  }),
        .data_rd(
            { rbm_0_pos_Q1_d, gm_rdata0}),
        .read_allocate(
            {   impl_rec & rbm_0_pos_CE1, 
                gm_step} ),
        .read( {1'b1,1'b1} ),

        .write( {1'b0} ),
        .write_allocate( {1'b0} ),
        .addr_wr({16'd0}),
        .data_wr({1'd0}),
        .concrete({concrete_val_0, concrete_val_1 })
    );

    wire rbm_0_pos_Q1_d;
    reg  rbm_0_pos_Q1_q;
    assign rbm_0_pos_Q1 = rbm_0_pos_Q1_q;
    always @(posedge CLK) begin
      rbm_0_pos_Q1_q <= rbm_0_pos_Q1_d;
    end
    

// And buffer for write

    reg        IMPL_data;
    reg [15:0] IMPL_addr;
    reg        IMPL_dirty;

    reg        GM_data;
    reg [15:0] GM_addr;
    reg        GM_dirty;

    always @(posedge CLK) begin
        if(RST) begin
            IMPL_dirty <= 1'b0;
            GM_dirty <= 1'b0;
        end
        else begin
            if(impl_rec & rbm_0_pos_WE0 & rbm_0_pos_CE0)  begin
                IMPL_dirty <= 1'b1;
                IMPL_addr  <= rbm_0_pos_A0;
                IMPL_data  <= rbm_0_pos_D0;
            end

            if (gm_step & gm_wen0) begin
                GM_dirty <= 1'b1;
                GM_addr  <= {gm_waddr0};
                GM_data  <= gm_wdata0;
            end
        end
    end

    assign mismatch = (~gm_compare) ? 1'b0 :
                      (IMPL_dirty != GM_dirty) ? 1'b1 :
                      (IMPL_dirty == 0) ? 1'b0:
                      (IMPL_addr != GM_addr) ? 1'b1 :
                      (IMPL_data != GM_data) ? 1'b1 :
                      1'b0;
endmodule


module rbm_0_predict_result(CLK, rbm_0_predict_result_CE1, rbm_0_predict_result_A1, rbm_0_predict_result_Q1, rbm_0_predict_result_CE0, rbm_0_predict_result_A0, rbm_0_predict_result_D0, rbm_0_predict_result_WE0, rbm_0_predict_result_WEM0,

    gm_raddr0,
    gm_rdata0,

    gm_waddr0,
    gm_wen0,
    gm_wdata0,

    gm_sel,
    gm_step,
    gm_compare,
    impl_rec,
    mismatch,
    RST );
  input CLK;
  //buffer: predict_result - process: store - interface: R
  input rbm_0_predict_result_CE1;
  input [6:0] rbm_0_predict_result_A1;
  output [3:0] rbm_0_predict_result_Q1;
  //buffer: predict_result - process: predict_rbm - interface: W
  input rbm_0_predict_result_CE0;
  input [6:0] rbm_0_predict_result_A0;
  input [3:0] rbm_0_predict_result_D0;
  input rbm_0_predict_result_WE0;
  input [3:0] rbm_0_predict_result_WEM0;


  // newly added
  input RST;
  input impl_rec;
  input gm_sel;
  input gm_step;
  input gm_compare;
  output mismatch;

  input [5:0] gm_raddr0;
  output [3:0]  gm_rdata0;

  input [5:0] gm_waddr0;
  input        gm_wen0;
  input [3:0]  gm_wdata0;

  wire [5:0] gm_praddr = gm_raddr0; //gm_sel ? {1'b0,gm_raddr0} + `NUM_MOVIE_MAX : {1'b0,gm_raddr0} ;
  wire [5:0] gm_pwaddr = gm_waddr0; // gm_sel ? {1'b0,gm_waddr0} + `NUM_MOVIE_MAX : {1'b0,gm_waddr0} ;

  wire [5:0] rbm_0_predict_result_A0_r = rbm_0_predict_result_A0 >= `NUM_MOVIE_MAX ? rbm_0_predict_result_A0-`NUM_MOVIE_MAX : rbm_0_predict_result_A0;
  wire [5:0] rbm_0_predict_result_A1_r = rbm_0_predict_result_A1 >= `NUM_MOVIE_MAX ? rbm_0_predict_result_A1-`NUM_MOVIE_MAX : rbm_0_predict_result_A1;

// Let's use jg for read 
   wire concrete_val_0;
   wire concrete_val_1;
    jasper_model_mpram #( 
        .READ_PORTS(1+1),
        .WRITE_PORTS(1),
        .ADDR_WIDTH(6),
        .DATA_WIDTH(4),
        .MAX_DEPTH(8),
        .MEM_STYLE(0),
        .RESET_STYLE(0),
        .RD_DATA_DLY(0)
        )
    mem_mpram
    (
        .clk(CLK),
        .rstN(~RST),
        .addr_rd( 
            { rbm_0_predict_result_A1_r, gm_praddr  }),
        .data_rd(
            { rbm_0_predict_result_Q1_d, gm_rdata0}),
        .read(
            {   impl_rec & rbm_0_predict_result_CE1, 
                gm_step} ),
        .read_allocate( {1'b1,1'b1} ),

        .write( {1'b0} ),
        .write_allocate( {1'b0} ),
        .addr_wr({16'd0}),
        .data_wr({1'd0}),
        .concrete({concrete_val_0, concrete_val_1 })
    );
    

    wire [3:0] rbm_0_predict_result_Q1_d;
    reg  [3:0] rbm_0_predict_result_Q1_q;
    assign rbm_0_predict_result_Q1 = rbm_0_predict_result_Q1_q;
    always @(posedge CLK) begin
      rbm_0_predict_result_Q1_q <= rbm_0_predict_result_Q1_d;
    end
// And buffer for write

    reg [3:0]  IMPL_data;
    reg [6:0] IMPL_addr;
    reg        IMPL_dirty;

    reg [3:0]  GM_data;
    reg [6:0] GM_addr;
    reg        GM_dirty;

    always @(posedge CLK) begin
        if(RST) begin
            IMPL_dirty <= 1'b0;
            GM_dirty <= 1'b0;
        end
        else begin
            if(impl_rec & rbm_0_predict_result_WE0 & rbm_0_predict_result_CE0)  begin
                IMPL_dirty <= 1'b1;
                IMPL_addr  <= rbm_0_predict_result_A0_r;
                IMPL_data  <= rbm_0_predict_result_D0;
            end

            if (gm_step & gm_wen0) begin
                GM_dirty <= 1'b1;
                GM_addr  <= gm_pwaddr;
                GM_data  <= gm_wdata0;
            end
        end
    end

    assign mismatch = (~gm_compare) ? 1'b0 :
                      (IMPL_dirty != GM_dirty) ? 1'b1 :
                      (IMPL_dirty == 0) ? 1'b0:
                      (IMPL_addr != GM_addr) ? 1'b1 :
                      (IMPL_data != GM_data) ? 1'b1 :
                      1'b0;
    endmodule


module rbm_0_visibleEnergies(CLK, rbm_0_visibleEnergies_CE1, rbm_0_visibleEnergies_A1, rbm_0_visibleEnergies_D1, rbm_0_visibleEnergies_WE1, rbm_0_visibleEnergies_WEM1, rbm_0_visibleEnergies_CE3, rbm_0_visibleEnergies_A3, rbm_0_visibleEnergies_Q3, rbm_0_visibleEnergies_CE0, rbm_0_visibleEnergies_A0, rbm_0_visibleEnergies_D0, rbm_0_visibleEnergies_WE0, rbm_0_visibleEnergies_WEM0, rbm_0_visibleEnergies_CE2, rbm_0_visibleEnergies_A2, rbm_0_visibleEnergies_Q2,

    impl_rec,
    impl_sel, // select between port 0 write / port 1 write
   
    gm_raddr0,
    gm_rdata0,

    gm_waddr0,
    gm_wen0,
    gm_wdata0,

    gm_sel,
    gm_step,
    gm_compare,
    mismatch,
    RST  );
  input CLK;
  //buffer: visibleEnergies - process: train_rbm - interface: W
  input rbm_0_visibleEnergies_CE1;
  input [2:0] rbm_0_visibleEnergies_A1;
  input [15:0] rbm_0_visibleEnergies_D1;
  input rbm_0_visibleEnergies_WE1;
  input [15:0] rbm_0_visibleEnergies_WEM1;
  //buffer: visibleEnergies - process: train_rbm - interface: R
  input rbm_0_visibleEnergies_CE3;
  input [2:0] rbm_0_visibleEnergies_A3;
  output [15:0] rbm_0_visibleEnergies_Q3;
  //buffer: visibleEnergies - process: predict_rbm - interface: W
  input rbm_0_visibleEnergies_CE0;
  input [2:0] rbm_0_visibleEnergies_A0;
  input [15:0] rbm_0_visibleEnergies_D0;
  input rbm_0_visibleEnergies_WE0;
  input [15:0] rbm_0_visibleEnergies_WEM0;
  //buffer: visibleEnergies - process: predict_rbm - interface: R
  input rbm_0_visibleEnergies_CE2;
  input [2:0] rbm_0_visibleEnergies_A2;
  output [15:0] rbm_0_visibleEnergies_Q2;


  wire IMPL_CE = impl_sel ? rbm_0_visibleEnergies_CE1 : rbm_0_visibleEnergies_CE0;
  wire [2:0] IMPL_A = impl_sel ? rbm_0_visibleEnergies_A1 : rbm_0_visibleEnergies_A0;
  wire [15:0] IMPL_D = impl_sel ? rbm_0_visibleEnergies_D1 : rbm_0_visibleEnergies_D0;
  wire IMPL_WE = impl_sel ? rbm_0_visibleEnergies_WE1 : rbm_0_visibleEnergies_WE0;


  // newly added
  input RST;
  input impl_rec;
  input impl_sel;

  input gm_sel;
  input gm_step;
  input gm_compare;
  output mismatch;

  input [2:0]    gm_raddr0;
  output [15:0]  gm_rdata0;

  input [2:0]   gm_waddr0;
  input         gm_wen0;
  input [15:0]  gm_wdata0;



// Let's use jg for read 
   wire concrete_val_0;
   wire concrete_val_1;
   wire concrete_val_2;
    jasper_model_mpram #( 
        .READ_PORTS(2+1),
        .WRITE_PORTS(1),
        .ADDR_WIDTH(3),
        .DATA_WIDTH(16),
        .MAX_DEPTH(8),
        .MEM_STYLE(0),
        .RESET_STYLE(0),
        .RD_DATA_DLY(0)
        )
    mem_mpram
    (
        .clk(CLK),
        .rstN(~RST),
        .addr_rd( 
            { rbm_0_visibleEnergies_A2, rbm_0_visibleEnergies_A3, gm_raddr0  }),
        .data_rd(
            { rbm_0_visibleEnergies_Q2_d, rbm_0_visibleEnergies_Q3_d, gm_rdata0 }),
        .read_allocate(
            {   impl_rec & rbm_0_visibleEnergies_CE2, 
                impl_rec & rbm_0_visibleEnergies_CE3, 
                gm_step} ),
        .read( {1'b1,1'b1, 1'b1} ),

        .write( {1'b0} ),
        .write_allocate( {1'b0} ),
        .addr_wr({3'd0}),
        .data_wr({16'd0}),
        .concrete({concrete_val_0, concrete_val_1 , concrete_val_2})
    );
    

    wire [15:0] rbm_0_visibleEnergies_Q2_d;
    reg  [15:0] rbm_0_visibleEnergies_Q2_q;
    wire [15:0] rbm_0_visibleEnergies_Q3_d;
    reg  [15:0] rbm_0_visibleEnergies_Q3_q;
    assign rbm_0_visibleEnergies_Q2 = rbm_0_visibleEnergies_Q2_q;
    assign rbm_0_visibleEnergies_Q3 = rbm_0_visibleEnergies_Q3_q;
    always @(posedge CLK) begin
      rbm_0_visibleEnergies_Q2_q <= rbm_0_visibleEnergies_Q2_d;
      rbm_0_visibleEnergies_Q3_q <= rbm_0_visibleEnergies_Q3_d;
    end
// And buffer for write

    reg [15:0]  IMPL_data;
    reg [2:0]  IMPL_addr;
    reg        IMPL_dirty;

    reg [15:0]  GM_data;
    reg [2:0]  GM_addr;
    reg        GM_dirty;

    always @(posedge CLK) begin
        if(RST) begin
            IMPL_dirty <= 1'b0;
            GM_dirty <= 1'b0;
        end
        else begin
            if(impl_rec & IMPL_WE & IMPL_CE)  begin
                IMPL_dirty <= 1'b1;
                IMPL_addr  <= IMPL_A;
                IMPL_data  <= IMPL_D;
            end

            if (gm_step & gm_wen0) begin
                GM_dirty <= 1'b1;
                GM_addr  <= gm_waddr0;
                GM_data  <= gm_wdata0;
            end
        end
    end

    assign mismatch = (~gm_compare) ? 1'b0 :
                      (IMPL_dirty != GM_dirty) ? 1'b1 :
                      (IMPL_dirty == 0) ? 1'b0:
                      (IMPL_addr != GM_addr) ? 1'b1 :
                      (IMPL_data != GM_data) ? 1'b1 :
                      1'b0;


endmodule


module pow2_mem(CLK, RST, waddr, wdata, wen, raddr, rdata, gm_step);
    input CLK;
    input RST;

    input [2:0] waddr;
    input [31:0] wdata;
    input wen;

    input [2:0] raddr;
    output [31:0] rdata;

    input gm_step;

    reg[159:0] mem;

    always @(posedge CLK) begin
        if(gm_step & wen)
            mem[{waddr,5'd0}+:32] <= wdata;
    end

    assign rdata = mem[{raddr,5'd0}+:32];

endmodule


module predict_vector_mem(CLK, RST, waddr, wdata,wen, raddr, rdata, gm_step);
    input CLK;
    input RST;

    input [8:0] waddr;
    input wdata;
    input wen;

    input [8:0] raddr;
    output  rdata;

    input gm_step;

    reg[500:0] mem;

    always @(posedge CLK) begin
        if(gm_step & wen)
            mem[{waddr}] <= wdata;
    end

    assign rdata = mem[{raddr}];

endmodule


module visible_unit_mem(CLK, RST, waddr0, wdata0, wen0, waddr1, wdata1, wen1, raddr, rdata, gm_step);
    
    input CLK;
    input RST;

    input [8:0] waddr0;
    input wdata0;
    input wen0;

    input [8:0] waddr1;
    input wdata1;
    input wen1;

    input [8:0] raddr;
    output  rdata;

    input gm_step;

    reg[500:0] mem;
    reg[500:0] mem_nxt;

    always @(*) begin
        mem_nxt = mem;
        if(wen0)
            mem_nxt[waddr0] = wdata0;
        if(wen1)
            mem_nxt[waddr1] = wdata1;
    end
    
    always @(posedge CLK) begin
        if(gm_step)
            mem <= mem_nxt;
    end

    assign rdata = mem[{raddr}];

endmodule