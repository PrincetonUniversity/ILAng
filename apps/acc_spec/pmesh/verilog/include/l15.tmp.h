/*
Copyright (c) 2015 Princeton University
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Princeton University nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY PRINCETON UNIVERSITY "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL PRINCETON UNIVERSITY BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//l15.h
// Copyright (c) 2015 Princeton University
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Princeton University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY PRINCETON UNIVERSITY "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL PRINCETON UNIVERSITY BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

//==================================================================================================
//  Filename      : define.h
//  Created On    : 2014-02-20
//  Last Modified : 2018-11-16 17:14:11
//  Revision      :
//  Author        : Yaosheng Fu
//  Company       : Princeton University
//  Email         : yfu@princeton.edu
//
//  Description   : main header file defining global architecture parameters
//
//
//==================================================================================================

`ifndef DEFINE_VH
`define DEFINE_VH

// Uncomment to define USE_GENERIC_SRAM_IMPLEMENTATION to use the old unsynthesizable BRAM
// `define USE_GENERIC_SRAM_IMPLEMENTATION
`ifndef USE_GENERIC_SRAM_IMPLEMENTATION
`define SYNTHESIZABLE_BRAM
`endif

/*
Copyright (c) 2015 Princeton University
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Princeton University nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY PRINCETON UNIVERSITY "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL PRINCETON UNIVERSITY BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/////////////////////////////////////////////////////////////////////////////////////////////
// 63         50 49      42 41      34 33           30 29      22 21                 0   
// ------------------------------------------------------------------------------------
// |            |          |          |               |          |                    |
// |  Chip ID   |  Dest X  |  Dest Y  |  Final Route  |  Length  |    Header Payload  | 
// |            |          |          |               |          |                    |
// ------------------------------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////

`define    XY_WIDTH 8
`define    CHIP_ID_WIDTH 14
`define    PAYLOAD_LEN 8
`define    DATA_WIDTH 64
`define    HALF_DATA_WIDTH 32
`define    OFF_CHIP_NODE_X 0
`define    OFF_CHIP_NODE_Y 0
`define    MAX_FILE_SIZE 1024
`define    FINAL_BITS 4

 //whether the routing is based on chipid or x y position
 //`define    ROUTING_CHIP_ID
 `define    ROUTING_XY

 //defines for different topology, only one should be active
 //`define    NETWORK_TOPO_2D_MESH
 //`define    NETWORK_TOPO_3D_MESH
 `define    NETWORK_TOPO_XBAR

// Tile config

// /home/hongce/ila/openpiton/piton/verif/env/manycore/devices.xml
`define NUM_TILES 1
`define X_TILES 1
`define Y_TILES 1


// NoC interface

`define NOC_DATA_WIDTH      `DATA_WIDTH
`define NOC_CHIPID_WIDTH    `CHIP_ID_WIDTH
`define NOC_CHIPID_OFFCHIP  13
`define NOC_CHIPID_ONCHIP   12:0
`define NOC_X_WIDTH         `XY_WIDTH
`define NOC_Y_WIDTH         `XY_WIDTH
`define NOC_OFF_CHIP_NODE_X `OFF_CHIP_NODE_X
`define NOC_OFF_CHIP_NODE_Y `OFF_CHIP_NODE_Y

`define NOC_FBITS_WIDTH     `FINAL_BITS
`define NOC_FBITS_RESERVED  4'd1
`define NOC_FBITS_L1        4'd0
`define NOC_FBITS_L2        4'd0
`define NOC_FBITS_FP        4'd0
`define NOC_FBITS_MEM       4'd2

`define NOC_NODEID_WIDTH    34
`define NOC_DATACOUNT_WIDTH 5
`define NOC_EC_WIDTH        5

// NodeID decomposition
`define NOC_NODEID_ONCHIPID     32:20
`define NOC_NODEID_OFFCHIPID    33
`define NOC_NODEID_CHIPID       33:20
`define NOC_NODEID_X            19:12
`define NOC_NODEID_Y            11:4
`define NOC_NODEID_FBITS        3:0


//========================
//Packet format
//=========================

//Header decomposition
`define MSG_HEADER_WIDTH        192

`define MSG_LAST_SUBLINE        0
`define MSG_SUBLINE_ID          2:1
`define MSG_L2_MISS             3
`define MSG_MESI                5:4
`define MSG_OPTIONS_1           5:0
`define MSG_OPTIONS_4           5:0
`define MSG_MSHRID              13:6
`define MSG_TYPE                21:14
`define MSG_TYPE_LO             14
`define MSG_LENGTH              29:22
`define MSG_LENGTH_LO           22
`define MSG_DST_FBITS           33:30
`define MSG_DST_Y               41:34
`define MSG_DST_X               49:42
`define MSG_DST_CHIPID          63:50
`define MSG_DST_CHIPID_HI       63

`define MSG_DATA_SIZE           74:72
`define MSG_CACHE_TYPE          75
`define MSG_SUBLINE_VECTOR      79:76
`define MSG_ADDR                119:80

`define MSG_LSID                147:142
`define MSG_SDID                157:148
`define MSG_SRC_FBITS           161:158
`define MSG_SRC_Y               169:162
`define MSG_SRC_X               177:170
`define MSG_SRC_CHIPID          191:178

// these shifted fields are added for convienience
// HEADER 2
`define MSG_DATA_SIZE_           10:8
`define MSG_CACHE_TYPE_          11
`define MSG_SUBLINE_VECTOR_      15:12
`define MSG_OPTIONS_2_           15:0
`define MSG_ADDR_HI_             55
`define MSG_ADDR_                55:16

// HEADER 3
`define MSG_LSID_                19:14 // 147-128:142-128
`define MSG_SDID_                29:20
`define MSG_OPTIONS_3_           29:0
`define MSG_SRC_FBITS_           33:30
`define MSG_SRC_Y_               41:34
`define MSG_SRC_X_               49:42
`define MSG_SRC_CHIPID_          63:50

//NoC header information

`define MSG_FLIT_WIDTH          `NOC_DATA_WIDTH
`define MSG_DST_CHIPID_WIDTH    `NOC_CHIPID_WIDTH
`define MSG_DST_X_WIDTH         `NOC_X_WIDTH
`define MSG_DST_Y_WIDTH         `NOC_Y_WIDTH
`define MSG_DST_FBITS_WIDTH     `NOC_FBITS_WIDTH
`define MSG_DST_NODEID_WIDTH    `NOC_NODEID_WIDTH
`define MSG_LENGTH_WIDTH        8
`define MSG_OPTIONS_1_WIDTH     6

// Width of MSG_ADDR field - you're probably looking for PHY_ADDR_WIDTH
`define MSG_ADDR_WIDTH          48

//Coherence information

`define MSG_TYPE_WIDTH          8



//Requests from L15 to L2
// Should always make #0 an error
`define MSG_TYPE_RESERVED           8'd0
`define MSG_TYPE_LOAD_REQ           8'd31
`define MSG_TYPE_PREFETCH_REQ       8'd1
`define MSG_TYPE_STORE_REQ          8'd2
`define MSG_TYPE_BLK_STORE_REQ      8'd3
`define MSG_TYPE_BLKINIT_STORE_REQ  8'd4
`define MSG_TYPE_CAS_REQ            8'd5
`define MSG_TYPE_CAS_P1_REQ         8'd6
//condition satisfied
`define MSG_TYPE_CAS_P2Y_REQ        8'd7
//condition not satisfied
`define MSG_TYPE_CAS_P2N_REQ        8'd8
//Both SWAP and LDSTUB are the same for L2
`define MSG_TYPE_SWAP_REQ           8'd9
`define MSG_TYPE_SWAP_P1_REQ        8'd10
`define MSG_TYPE_SWAP_P2_REQ        8'd11
`define MSG_TYPE_WB_REQ             8'd12
`define MSG_TYPE_WBGUARD_REQ        8'd13
`define MSG_TYPE_NC_LOAD_REQ        8'd14
`define MSG_TYPE_NC_STORE_REQ       8'd15
`define MSG_TYPE_INTERRUPT_FWD       8'd32

//RISC-V AMO requests
`define MSG_TYPE_AMO_ADD_REQ         8'd36
`define MSG_TYPE_AMO_AND_REQ         8'd37
`define MSG_TYPE_AMO_OR_REQ          8'd38
`define MSG_TYPE_AMO_XOR_REQ         8'd39
`define MSG_TYPE_AMO_MAX_REQ         8'd40
`define MSG_TYPE_AMO_MAXU_REQ        8'd41
`define MSG_TYPE_AMO_MIN_REQ         8'd42
`define MSG_TYPE_AMO_MINU_REQ        8'd43

//RISC-V AMO L2-internal phase 1
`define MSG_TYPE_AMO_ADD_P1_REQ      8'd44
`define MSG_TYPE_AMO_AND_P1_REQ      8'd45
`define MSG_TYPE_AMO_OR_P1_REQ       8'd46
`define MSG_TYPE_AMO_XOR_P1_REQ      8'd47
`define MSG_TYPE_AMO_MAX_P1_REQ      8'd48
`define MSG_TYPE_AMO_MAXU_P1_REQ     8'd49
`define MSG_TYPE_AMO_MIN_P1_REQ      8'd50
`define MSG_TYPE_AMO_MINU_P1_REQ     8'd51

//RISC-V AMO L2-internal phase 2
`define MSG_TYPE_AMO_ADD_P2_REQ      8'd52
`define MSG_TYPE_AMO_AND_P2_REQ      8'd53
`define MSG_TYPE_AMO_OR_P2_REQ       8'd54
`define MSG_TYPE_AMO_XOR_P2_REQ      8'd55
`define MSG_TYPE_AMO_MAX_P2_REQ      8'd56
`define MSG_TYPE_AMO_MAXU_P2_REQ     8'd57
`define MSG_TYPE_AMO_MIN_P2_REQ      8'd58
`define MSG_TYPE_AMO_MINU_P2_REQ     8'd59


//Forward requests from L2 to L15
`define MSG_TYPE_LOAD_FWD           8'd16
`define MSG_TYPE_STORE_FWD          8'd17
`define MSG_TYPE_INV_FWD            8'd18




//Memory requests from L2 to DRAM
`define MSG_TYPE_LOAD_MEM           8'd19
`define MSG_TYPE_STORE_MEM          8'd20




//Forward acks from L15 to L2
`define MSG_TYPE_LOAD_FWDACK        8'd21
`define MSG_TYPE_STORE_FWDACK       8'd22
`define MSG_TYPE_INV_FWDACK         8'd23




//Memory acks from memory to L2
`define MSG_TYPE_LOAD_MEM_ACK       8'd24
`define MSG_TYPE_STORE_MEM_ACK      8'd25
`define MSG_TYPE_NC_LOAD_MEM_ACK    8'd26
`define MSG_TYPE_NC_STORE_MEM_ACK   8'd27





//Acks from L2 to L15
`define MSG_TYPE_NODATA_ACK         8'd28
`define MSG_TYPE_DATA_ACK           8'd29
//TODO
`define MSG_TYPE_ERROR              8'd30
`define MSG_TYPE_INTERRUPT          8'd33

//Only exist within L2

`define MSG_TYPE_L2_LINE_FLUSH_REQ   8'd34
`define MSG_TYPE_L2_DIS_FLUSH_REQ    8'd35


//`define MSG_TYPE_LOAD_REQ           8'd31 if this is enabled, don't use 31

`define MSG_CACHE_TYPE_WIDTH        1
`define MSG_CACHE_TYPE_DATA         1'b0
`define MSG_CACHE_TYPE_INS          1'b1

// These should be defined in l2.vh, not the global defines
`define MSG_MESI_BITS               2
`define MSG_MESI_I                  2'b00
`define MSG_MESI_S                  2'b01
`define MSG_MESI_E                  2'b10
`define MSG_MESI_M                  2'b11

`define MSG_SUBLINE_VECTOR_WIDTH    4
`define MSG_SUBLINE_ID_WIDTH        2
`define MSG_LAST_SUBLINE_WIDTH      1


//Physical address

`define PHY_ADDR_WIDTH          40

`define MSG_SRC_CHIPID_WIDTH    `NOC_CHIPID_WIDTH
`define MSG_SRC_X_WIDTH         `NOC_X_WIDTH
`define MSG_SRC_Y_WIDTH         `NOC_Y_WIDTH
`define MSG_SRC_FBITS_WIDTH     `NOC_FBITS_WIDTH
`define MSG_SRC_NODEID_WIDTH    `NOC_NODEID_WIDTH
`define MSG_MSHRID_WIDTH        8
`define MSG_L2_MISS_BITS        1
//Transition data size

`define MSG_DATA_SIZE_WIDTH     3
`define MSG_DATA_SIZE_0B        3'b000
`define MSG_DATA_SIZE_1B        3'b001
`define MSG_DATA_SIZE_2B        3'b010
`define MSG_DATA_SIZE_4B        3'b011
`define MSG_DATA_SIZE_8B        3'b100
`define MSG_DATA_SIZE_16B       3'b101
`define MSG_DATA_SIZE_32B       3'b110
`define MSG_DATA_SIZE_64B       3'b111


//`define HOME_ID_MASK_X          10:10
//Additional fields for Sharer Domain ID and Logical Sharer ID
//For coherence domain restriction only


// Tri: dynamically adjust these parameters based on how many tiles are available
//  Assumption: 8x8 topology
`ifdef RTL_SPARC63
`define HOME_ID_MASK_X          8:6
`define HOME_ID_MASK_X_ENABLE   1
`define HOME_ID_MASK_Y          11:9
`define HOME_ID_MASK_Y_ENABLE   1
`define TOTAL_NUM_TILE          64
`else
`ifdef RTL_SPARC31
`define HOME_ID_MASK_X          8:6
`define HOME_ID_MASK_X_ENABLE   1
`define HOME_ID_MASK_Y          10:9
`define HOME_ID_MASK_Y_ENABLE   1
`define TOTAL_NUM_TILE          32
`else
`ifdef RTL_SPARC15
`define HOME_ID_MASK_X          8:6
`define HOME_ID_MASK_X_ENABLE   1
`define HOME_ID_MASK_Y          9:9
`define HOME_ID_MASK_Y_ENABLE   1
`define TOTAL_NUM_TILE          16
`else
`ifdef RTL_SPARC7
`define HOME_ID_MASK_X          8:6
`define HOME_ID_MASK_X_ENABLE   1
`define HOME_ID_MASK_Y          0:0
`define HOME_ID_MASK_Y_ENABLE   0
`define TOTAL_NUM_TILE          8
`else
`ifdef RTL_SPARC3
`define HOME_ID_MASK_X          7:6
`define HOME_ID_MASK_X_ENABLE   1
`define HOME_ID_MASK_Y          0:0
`define HOME_ID_MASK_Y_ENABLE   0
`define TOTAL_NUM_TILE          4
`else
`ifdef RTL_SPARC1
`define HOME_ID_MASK_X          6:6
`define HOME_ID_MASK_X_ENABLE   1
`define HOME_ID_MASK_Y          0:0
`define HOME_ID_MASK_Y_ENABLE   0
`define TOTAL_NUM_TILE          2
`else
`define HOME_ID_MASK_X          6:6
`define HOME_ID_MASK_X_ENABLE   0
`define HOME_ID_MASK_Y          0:0
`define HOME_ID_MASK_Y_ENABLE   0
`define TOTAL_NUM_TILE          1
`endif
`endif
`endif
`endif
`endif
`endif


//`define DMBR_TAG_WIDTH 4

//Clumpy Shared Memory

`define ASI_IMMU_CSM_IN_REG             8'h0E
`define ASI_DMMU_CSM_IN_REG             8'h0F
`define ASI_IMMU_CSM_ACCESS_REG         8'h12
`define ASI_DMMU_CSM_ACCESS_REG         8'h13

////////////////////////////////////////////
// SOME CONFIGURATION REGISTERS DEFINES
////////////////////////////////////////////
// example: read/write to csm_en would be 0xba_0000_0100

// `define ASI_ADDRESS_MASK    `L15_ADDR_TYPE
// `define CONFIG_ASI_ADDRESS  `L15_ADDR_TYPE_WIDTH'hba

`define CONFIG_REG_ADDRESS_MASK 					15:8 // trin: important mask
`define CONFIG_REG_CHIPID_ADDRESS 					8'd0
`define CONFIG_REG_CSM_EN_ADDRESS 					8'd1
`define CONFIG_REG_DMBR_REG1_ADDRESS 				8'd2
`define CONFIG_REG_HMT_BASE_REG 					8'd3
`define CONFIG_SYSTEM_TILE_COUNT_ADDRESS		    8'd4
`define CONFIG_REG_DMBR_REG2_ADDRESS 				8'd5
`define CONFIG_REG_HOME_ALLOC_METHOD 				8'd6

// DMBR Config register 1 fields
`define CFG_DMBR_FUNC_EN_BIT						8'h0
`define CFG_DMBR_STALL_EN_BIT						8'h1
`define CFG_DMBR_PROC_LD_BIT						8'h2
`define CFG_DMBR_RD_CUR_VAL_BIT						8'h3
`define CFG_DMBR_CRED_BIN_0_BITS					 9:4
`define CFG_DMBR_CRED_BIN_1_BITS 					15:10
`define CFG_DMBR_CRED_BIN_2_BITS 					21:16
`define CFG_DMBR_CRED_BIN_3_BITS 					27:22
`define CFG_DMBR_CRED_BIN_4_BITS 					33:28
`define CFG_DMBR_CRED_BIN_5_BITS 					39:34
`define CFG_DMBR_CRED_BIN_6_BITS 					45:40
`define CFG_DMBR_CRED_BIN_7_BITS 					51:46
`define CFG_DMBR_CRED_BIN_8_BITS 					57:52
`define CFG_DMBR_CRED_BIN_9_BITS					63:58

// DMBR Config register 2 fields
`define CFG_DMBR_REPLENISH_BITS						15:0
`define CFG_DMBR_BIN_SCALE_BITS						25:16

//Home allocation method
`define HOME_ALLOC_METHOD_WIDTH                     2
`define HOME_ALLOC_LOW_ORDER_BITS                   2'd0
`define HOME_ALLOC_MIDDLE_ORDER_BITS                2'd1
`define HOME_ALLOC_HIGH_ORDER_BITS                  2'd2
`define HOME_ALLOC_MIXED_ORDER_BITS                 2'd3

//Additional fields for Sharer Domain ID and Logical Sharer ID
//For coherence domain restriction only

`define MSG_SDID_WIDTH          10
`define MSG_LSID_WIDTH          6
`define MSG_HDID_WIDTH          10
`define MSG_LHID_WIDTH          6


`define TLB_CSM_WIDTH           33
`define TLB_CSM                 32:0
`define TLB_CSM_STATE           32  //0 for local csm info, 1 for global info
`define TLB_CSM_STATE_LOCAL     1'b0
`define TLB_CSM_STATE_GLOBAL    1'b1

`define TLB_CSM_LOCAL           31:0
`define TLB_CSM_HDID            31:22
`define TLB_CSM_HD_SIZE         21:16
`define TLB_CSM_SDID            15:6
`define TLB_CSM_LSID            5:0

`define TLB_CSM_GLOBAL          29:0
`define TLB_CSM_CHIPID          29:16
`define TLB_CSM_Y               15:8
`define TLB_CSM_X               7:0


`define TTE_CSM_WIDTH           64
`define TTE_CSM                 63:0
`define TTE_CSM_HDID            31:22
`define TTE_CSM_HD_SIZE         21:16
`define TTE_CSM_SDID            15:6
`define TTE_CSM_LSID            5:0


//`define TTE_CSM_WIDTH           64
//`define TTE_CSM                 63:0
//`define TTE_CSM_VALID           63
//`define TTE_CSM_SZL             62:61
//`define TTE_CSM_NFO             60
//`define TTE_CSM_IE              59
//`define TTE_CSM_SOFT2           58:49
//`define TTE_CSM_SZH             48
//`define TTE_CSM_DIAG            47:40
//`define TTE_CSM_RES1            39
//`define TTE_CSM_SDID            38:29
//`define TTE_CSM_HDID            28:19
//`define TTE_CSM_LSID            18:13
//`define TTE_CSM_SOFT            12:8
//`define TTE_CSM_RES2            7
//`define TTE_CSM_LOCK            6
//`define TTE_CSM_CP              5
//`define TTE_CSM_CV              4
//`define TTE_CSM_E               3
//`define TTE_CSM_P               2
//`define TTE_CSM_W               1
//`define TTE_CSM_RES3            0



`define HOME_ID_WIDTH               `MSG_LHID_WIDTH
`define HOME_ID_ADDR_POS_LOW        `HOME_ID_WIDTH+5 : 6
`define HOME_ID_ADDR_POS_MIDDLE     `HOME_ID_WIDTH+13 : 14
`define HOME_ID_ADDR_POS_HIGH       `HOME_ID_WIDTH+23 : 24
`define HOME_ID_X_POS_WIDTH         3
`define HOME_ID_X_POS               2:0
`define HOME_ID_Y_POS_WIDTH         3
`define HOME_ID_Y_POS               5:3

// Packet format for home id
`define PACKET_HOME_ID_WIDTH        (`NOC_CHIPID_WIDTH+`NOC_X_WIDTH+`NOC_Y_WIDTH)
`define PACKET_HOME_ID_CHIP_MASK    (`PACKET_HOME_ID_WIDTH-1):(`NOC_X_WIDTH+`NOC_Y_WIDTH)
`define PACKET_HOME_ID_Y_MASK       `NOC_Y_WIDTH+`NOC_X_WIDTH-1:`NOC_X_WIDTH
`define PACKET_HOME_ID_X_MASK       `NOC_X_WIDTH-1:0

/////////////////////////////////////
// BIST
/////////////////////////////////////

// the data width from tap to individual sram wrappers
`define SRAM_WRAPPER_BUS_WIDTH 4
`define BIST_FUSE_WIDTH 100

//deprecated
`define BIST_FUSE_ID_WIDTH 8

`define BIST_ID_WIDTH 8
`define BIST_ID_L1_ICACHE_W10   8'd1
`define BIST_ID_L1_ICACHE_W32   8'd2
`define BIST_ID_L1_DCACHE_W01   8'd3
`define BIST_ID_L1_DCACHE_W23   8'd4
`define BIST_ID_L1_FRF          8'd5
`define BIST_ID_L15_DTAG        8'd6
`define BIST_ID_L15_DCACHE      8'd7
`define BIST_ID_L15_HMT         8'd8
`define BIST_ID_L1_ITAG         8'd9
`define BIST_ID_L1_DTAG         8'd10
`define BIST_ID_L1_ICV          8'd11
`define BIST_ID_L1_DCV          8'd12
`define BIST_ID_L2_DATA         8'd13
`define BIST_ID_L2_DIR          8'd14
`define BIST_ID_L2_STATE        8'd15
`define BIST_ID_L2_TAG          8'd16
`define BIST_ID_INVALID         8'b1111_1110
`define BIST_ID_BROADCAST       8'b1111_1111

`define BIST_OP_WIDTH 4
`define BIST_OP_READ 4'd1
`define BIST_OP_WRITE 4'd2
`define BIST_OP_WRITE_EFUSE 4'd3
`define BIST_OP_SHIFT_DATA 4'd4
`define BIST_OP_SHIFT_ADDRESS 4'd5
`define BIST_OP_SHIFT_ID 4'd6
`define BIST_OP_SHIFT_BSEL 4'd7

/////////////////////////////////////
// IDs for JTAG-Core interface
/////////////////////////////////////

// 48b for writing the PC reset vector
`define JTAG_CORE_BUS_WIDTH 48
// 94b for reading the sscan data
`define CORE_JTAG_BUS_WIDTH 94
`define JTAG_CORE_ID_WIDTH 4
`define JTAG_CORE_ID_LSU_CONTROL_BITS       4'd1
`define JTAG_CORE_ID_IFU_THRFSM             4'd2
`define JTAG_CORE_ID_IFU_PC                 4'd3
`define JTAG_CORE_ID_TLU_RSTVADDR_BASE      4'd4
`define JTAG_CORE_ID_IFU_SSCAN              4'd5
`define JTAG_CORE_ID_IRF                    4'd6
`define JTAG_CORE_ID_IFU_BREAKPOINT_PC      4'd7
`define JTAG_CORE_ID_IFU_ICACHE_EN          4'd8

// Execution Drafting Synchronization Method Values
`define ED_STSM             2'b00
`define ED_RTSM             2'b01
`define ED_HTSM             2'b10
`define ED_RCFG             2'b11

// Execution Drafting timeout counter bit width
`define ED_TIMEOUT_COUNTER_BIT_WIDTH    16

// Configuration registers
`define CFG_DATA_WIDTH      64
`define CFG_ED0_INDEX       0
`define CFG_ED1_INDEX       1
`define CFG_CSM_ITLB_INDEX  2
`define CFG_CSM_DTLB_INDEX  3
`define CFG_ED0_VA_ADDR     48'h0
`define CFG_ED1_VA_ADDR     48'h8
`define CFG_CSM_ITLB_ADDR   48'h10
`define CFG_CSM_DTLB_ADDR   48'h18
`define CFG_NUM_REGS        4
`define CFG_LOG2_NUM_REGS   2

// Execution Drafting configuration register bit positions
`define CFG_ED0_ENABLE_POS              0
`define CFG_ED0_SYNC_METHOD             2:1
`define CFG_ED0_LFSR_SEED_POS           18:3
`define CFG_ED0_LFSR_LOAD_POS           19
`define CFG_ED0_COUNTER_TIMEOUT         35:20

`define CFG_ED1_PC_DIFF_THRESH_POS 49:0

// Execution Drafting configuration register default values
// ED disabled, STSM sync method, LFSR seed = 16'b0, LFSR load = 1'b0,
// Counter Timeout = 16'd32
`define CFG_ED0_DEFAULT     {28'b0, 16'd32, 1'b0, 16'b0, `ED_STSM, 1'b0}
`define CFG_ED1_DEFAULT     {14'b0, 50'd100}

//Clumpy sharer memory configuration registers
`define CFG_CSM_STATE_WIDTH      2
`define CFG_CSM_STATE_POS        63:62
`define CFG_CSM_STATE_LOCAL      2'd0
`define CFG_CSM_STATE_GLOBAL     2'd1
`define CFG_CSM_STATE_FLOCAL     2'd2
`define CFG_CSM_STATE_FGLOBAL    2'd3
`define CFG_CSM_CHIPID_POS       61:48
`define CFG_CSM_Y_POS            47:40
`define CFG_CSM_X_POS            39:32
`define CFG_CSM_HDID_POS         31:22
`define CFG_CSM_HD_SIZE_POS      21:16
`define CFG_CSM_SDID_POS         15:6
`define CFG_CSM_LSID_POS         5:0

`define CFG_CSM_ITLB_DEFAULT     64'b0
`define CFG_CSM_DTLB_DEFAULT     64'b0

`define SPARC_TILE       0
`define PICORV32_TILE    1
`define ARIANE_RV64_TILE 2

`endif



// Modified by Princeton University on June 9th, 2015
/*
* ========== Copyright Header Begin ==========================================
* 
* OpenSPARC T1 Processor File: iop.h
* Copyright (c) 2006 Sun Microsystems, Inc.  All Rights Reserved.
* DO NOT ALTER OR REMOVE COPYRIGHT NOTICES.
* 
* The above named program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License version 2 as published by the Free Software Foundation.
* 
* The above named program is distributed in the hope that it will be 
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
* 
* You should have received a copy of the GNU General Public
* License along with this work; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
* 
* ========== Copyright Header End ============================================
*/
//-*- verilog -*-
////////////////////////////////////////////////////////////////////////
/*
//
//  Description:	Global header file that contain definitions that 
//                      are common/shared at the IOP chip level
*/
////////////////////////////////////////////////////////////////////////


// Address Map Defines
// ===================
`define ADDR_MAP_HI      39
`define ADDR_MAP_LO      32
`define IO_ADDR_BIT      39

// CMP space
`define DRAM_DATA_LO     8'h00
`define DRAM_DATA_HI     8'h7f

// IOP space
`define JBUS1            8'h80
`define RESERVED_5	 8'h81 //`define HASH_TBL_NRAM_CSR 8'h81
`define RESERVED_1       8'h82
`define RESERVED_6_LO    8'h83 //`define ENET_MAC_CSR     8'h83
                               //`define ENET_ING_CSR     8'h84
                               //`define ENET_EGR_CMD_CSR 8'h85
`define RESERVED_6_HI    8'h86 //`define ENET_EGR_DP_CSR  8'h86
`define RESERVED_2_LO    8'h87
`define RESERVED_2_HI    8'h92
`define RESERVED_7       8'h93 //`define BSC_CSR          8'h93
`define RESERVED_3       8'h94
`define RESERVED_8       8'h95 //`define RAND_GEN_CSR     8'h95
`define CLOCK_UNIT_CSR   8'h96
`define DRAM_CSR         8'h97
`define IOB_MAN_CSR      8'h98
`define TAP_CSR          8'h99
`define RESERVED_4_L0    8'h9a
`define RESERVED_4_HI    8'h9d
`define CPU_ASI          8'h9e
`define IOB_INT_CSR      8'h9f

// L2 space
`define L2C_CSR_LO       8'ha0
`define L2C_CSR_HI       8'hbf

// More IOP space
`define JBUS2_LO         8'hc0
`define JBUS2_HI         8'hfe
`define SPI_CSR          8'hff


//Cache Crossbar Width and Field Defines
//======================================
`define	PCX_WIDTH	124  //PCX payload packet width
`define	CPX_WIDTH	145  //CPX payload packet width

`define PCX_VLD         123  //PCX packet valid 
`define PCX_RQ_HI       122  //PCX request type field 
`define PCX_RQ_LO       118
`define PCX_NC          117  //PCX non-cacheable bit
`define PCX_R           117  //PCX read/!write bit 
`define PCX_CP_HI       116  //PCX cpu_id field
`define PCX_CP_LO       114
`define PCX_TH_HI       113  //PCX Thread field
`define PCX_TH_LO       112
`define PCX_BF_HI       111  //PCX buffer id field
`define PCX_INVALL      111
`define PCX_BF_LO       109
`define PCX_WY_HI       108  //PCX replaced L1 way field
`define PCX_WY_LO       107
`define PCX_P_HI        108  //PCX packet ID, 1st STQ - 10, 2nd - 01
`define PCX_P_LO        107
`define PCX_SZ_HI       106  //PCX load/store size field
`define PCX_SZ_LO       104
`define PCX_ERR_HI      106  //PCX error field
`define PCX_ERR_LO      104
`define PCX_AD_HI       103  //PCX address field
`define PCX_AD_LO        64
`define PCX_DA_HI        63  //PCX Store data
`define PCX_DA_LO         0  

`define PCX_SZ_1B    3'b000  // encoding for 1B access
`define PCX_SZ_2B    3'b001  // encoding for 2B access
`define PCX_SZ_4B    3'b010  // encoding for 4B access
`define PCX_SZ_8B    3'b011  // encoding for 8B access
`define PCX_SZ_16B   3'b111  // encoding for 16B access

`define CPX_VLD         144  //CPX payload packet valid

`define CPX_RQ_HI       143  //CPX Request type
`define CPX_RQ_LO       140
`define CPX_ERR_HI      139  //CPX error field
`define CPX_ERR_LO      137
`define CPX_NC          136  //CPX non-cacheable
`define CPX_R           136  //CPX read/!write bit
`define CPX_TH_HI       135  //CPX thread ID field 
`define CPX_TH_LO       134

//bits 133:128 are shared by different fields
//for different packet types.

`define CPX_IN_HI       133  //CPX Interrupt source 
`define CPX_IN_LO       128  

`define CPX_WYVLD       133  //CPX replaced way valid
`define CPX_WY_HI       132  //CPX replaced I$/D$ way
`define CPX_WY_LO       131
`define CPX_BF_HI       130  //CPX buffer ID field - 3 bits
`define CPX_BF_LO       128

`define CPX_SI_HI       132  //L1 set ID - PA[10:6]- 5 bits
`define CPX_SI_LO       128  //used for invalidates

`define CPX_P_HI        131  //CPX packet ID, 1st STQ - 10, 2nd - 01 
`define CPX_P_LO        130

`define CPX_ASI         130  //CPX forward request to ASI
`define CPX_IF4B        130
`define CPX_IINV        124
`define CPX_DINV        123
`define CPX_INVPA5      122
`define CPX_INVPA4      121
`define CPX_CPUID_HI    120
`define CPX_CPUID_LO    118
//`define CPX_INV_PA_HI   116
//`define CPX_INV_PA_LO   112
`define CPX_INV_IDX_HI   117
`define CPX_INV_IDX_LO   112

`define CPX_DA_HI       127  //CPX data payload
`define CPX_DA_LO         0

// cache invalidation format
// `define CPX_INV_DCACHE_WORD0_VAL 0
// `define CPX_INV_ICACHE_WORD0_VAL 1
// `define CPX_INV_WORD0_WAY 5:2
// `define CPX_INV_DCACHE_WORD0_VAL 6
// `define CPX_INV_ICACHE_WORD0_VAL 7
// `define CPX_INV_WORD0_WAY 11:8
// `define CPX_INV_DCACHE_WORD0_VAL 12
// // `define CPX_INV_ICACHE_WORD0_VAL 13
// `define CPX_INV_WORD0_WAY 17:14
// `define CPX_INV_DCACHE_WORD0_VAL 18
// // `define CPX_INV_ICACHE_WORD0_VAL 19
// `define CPX_INV_WORD0_WAY 23:20

`define CPX_INV_DCACHE_VAL 0
`define CPX_INV_ICACHE_VAL 1
`define CPX_INV_WAY 5:2
// 4 extra bits for bigger icache/dcache
// up to 512KB l1 icache, 256KB l1 dcache
`define CPX_INV_PA_15_12 27:24
`define CPX_INV_UNUSED 111:28

`define	LOAD_RQ		5'b00000
`define	IMISS_RQ	5'b10000
`define	STORE_RQ	5'b00001
`define	CAS1_RQ		5'b00010
`define	CAS2_RQ		5'b00011
`define	SWAP_RQ		5'b00110
`define	STRLOAD_RQ	5'b00100
`define	STRST_RQ	5'b00101
`define STQ_RQ          5'b00111
`define INT_RQ          5'b01001
`define FWD_RQ          5'b01101
`define FWD_RPY         5'b01110
`define RSVD_RQ         5'b11111

`define LOAD_RET        4'b0000
`define INV_RET         4'b0011
`define ST_ACK          4'b0100
`define AT_ACK          4'b0011
`define INT_RET         4'b0111
`define TEST_RET        4'b0101
`define FP_RET          4'b1000
`define IFILL_RET       4'b0001
`define	EVICT_REQ	4'b0011
`define	ERR_RET		4'b1100
`define STRLOAD_RET     4'b0010
`define STRST_ACK       4'b0110
`define FWD_RQ_RET      4'b1010
`define FWD_RPY_RET     4'b1011
`define RSVD_RET        4'b1111

//Pico defines
`define PICO_MEM_DATA_LO 0
`define PICO_MEM_DATA_HI 31
`define PICO_MEM_ADDR_LO 32
`define PICO_MEM_ADDR_HI 63
`define PICO_MEM_WSTRB_LO 64
`define PICO_MEM_WSTRB_HI 67
`define PICO_MEM_VALID    68

`define PICO_CPX_INT      32
`define PICO_INT_TYPE     17:16

`define PICO_PCX_UNUSED   123:69
`define PICO_CPX_UNUSED   144:33
//End cache crossbar defines


// Number of COS supported by EECU 
`define EECU_COS_NUM  	  2


// 
// BSC bus sizes
// =============
//

// General
`define BSC_ADDRESS      40
`define MAX_XFER_LEN     7'b0
`define XFER_LEN_WIDTH   6

// CTags
`define BSC_CTAG_SZ      12
`define EICU_CTAG_PRE    5'b11101
`define EICU_CTAG_REM    7
`define EIPU_CTAG_PRE    3'b011
`define EIPU_CTAG_REM    9
`define EECU_CTAG_PRE    8'b11010000
`define EECU_CTAG_REM    4
`define EEPU_CTAG_PRE    6'b010000
`define EEPU_CTAG_REM    6
`define L2C_CTAG_PRE     2'b00
`define L2C_CTAG_REM     10
`define JBI_CTAG_PRE     2'b10
`define JBI_CTAG_REM     10
// reinstated temporarily
`define PCI_CTAG_PRE     7'b1101100
`define PCI_CTAG_REM     5


// CoS
`define EICU_COS         1'b0
`define EIPU_COS         1'b1
`define EECU_COS         1'b0
`define EEPU_COS         1'b1
`define PCI_COS          1'b0

// L2$ Bank
`define BSC_L2_BNK_HI    8
`define BSC_L2_BNK_LO    6

// L2$ Req
`define BSC_L2_REQ_SZ   62
`define BSC_L2_REQ	`BSC_L2_REQ_SZ	// used by rams in L2 code
`define BSC_L2_BUS      64
`define BSC_L2_CTAG_HI  61
`define BSC_L2_CTAG_LO  50
`define BSC_L2_ADD_HI   49
`define BSC_L2_ADD_LO   10
`define BSC_L2_LEN_HI    9
`define BSC_L2_LEN_LO    3
`define BSC_L2_ALLOC     2
`define BSC_L2_COS       1
`define BSC_L2_READ      0   

// L2$ Ack
`define L2_BSC_ACK_SZ   16
`define L2_BSC_BUS      64
`define L2_BSC_CBA_HI   14    // CBA - Critical Byte Address
`define L2_BSC_CBA_LO   13
`define L2_BSC_READ     12
`define L2_BSC_CTAG_HI  11
`define L2_BSC_CTAG_LO   0

// Enet Egress Command Unit
`define EECU_REQ_BUS    44
`define EECU_REQ_SZ     44
`define EECU_R_QID_HI   43
`define EECU_R_QID_LO   40
`define EECU_R_ADD_HI   39
`define EECU_R_ADD_LO    0

`define EECU_ACK_BUS    64
`define EECU_ACK_SZ      5
`define EECU_A_NACK      4
`define EECU_A_QID_HI    3
`define EECU_A_QID_LO    0


// Enet Egress Packet Unit
`define EEPU_REQ_BUS    55
`define EEPU_REQ_SZ     55
`define EEPU_R_TLEN_HI  54
`define EEPU_R_TLEN_LO  48
`define EEPU_R_SOF      47
`define EEPU_R_EOF      46
`define EEPU_R_PORT_HI  45
`define EEPU_R_PORT_LO  44
`define EEPU_R_QID_HI   43
`define EEPU_R_QID_LO   40
`define EEPU_R_ADD_HI   39
`define EEPU_R_ADD_LO    0

// This is cleaved in between Egress Datapath Ack's
`define EEPU_ACK_BUS     6
`define EEPU_ACK_SZ      6
`define EEPU_A_EOF       5
`define EEPU_A_NACK      4
`define EEPU_A_QID_HI    3
`define EEPU_A_QID_LO    0


// Enet Egress Datapath
`define EEDP_ACK_BUS   128
`define EEDP_ACK_SZ     28
`define EEDP_A_NACK     27
`define EEDP_A_QID_HI   26
`define EEDP_A_QID_LO   21
`define EEDP_A_SOF      20
`define EEDP_A_EOF      19
`define EEDP_A_LEN_HI   18
`define EEDP_A_LEN_LO   12
`define EEDP_A_TAG_HI   11
`define EEDP_A_TAG_LO    0
`define EEDP_A_PORT_HI   5
`define EEDP_A_PORT_LO   4
`define EEDP_A_PORT_WIDTH 2


// In-Order / Ordered Queue: EEPU
// Tag is: TLEN, SOF, EOF, QID = 15
`define EEPU_TAG_ARY     (7+1+1+6)
`define EEPU_ENTRIES     16
`define EEPU_E_IDX        4
`define EEPU_PORTS        4
`define EEPU_P_IDX        2

// Nack + Tag Info + CTag
`define IOQ_TAG_ARY      (1+`EEPU_TAG_ARY+12)
`define EEPU_TAG_LOC     (`EEPU_P_IDX+`EEPU_E_IDX)


// ENET Ingress Queue Management Req
`define EICU_REQ_BUS     64 
`define EICU_REQ_SZ      62
`define EICU_R_CTAG_HI   61
`define EICU_R_CTAG_LO   50
`define EICU_R_ADD_HI    49
`define EICU_R_ADD_LO    10
`define EICU_R_LEN_HI     9
`define EICU_R_LEN_LO     3
`define EICU_R_COS        1
`define EICU_R_READ       0   


// ENET Ingress Queue Management Ack
`define EICU_ACK_BUS     64
`define EICU_ACK_SZ      14
`define EICU_A_NACK      13
`define EICU_A_READ      12
`define EICU_A_CTAG_HI   11
`define EICU_A_CTAG_LO    0


// Enet Ingress Packet Unit
`define EIPU_REQ_BUS    128 
`define EIPU_REQ_SZ      59
`define EIPU_R_CTAG_HI   58
`define EIPU_R_CTAG_LO   50
`define EIPU_R_ADD_HI    49
`define EIPU_R_ADD_LO    10
`define EIPU_R_LEN_HI     9
`define EIPU_R_LEN_LO     3
`define EIPU_R_COS        1
`define EIPU_R_READ       0   


// ENET Ingress Packet Unit Ack
`define EIPU_ACK_BUS      10
`define EIPU_ACK_SZ       10
`define EIPU_A_NACK       9
`define EIPU_A_CTAG_HI    8
`define EIPU_A_CTAG_LO    0


// In-Order / Ordered Queue: PCI
// Tag is: CTAG
`define PCI_TAG_ARY     12
`define PCI_ENTRIES     16
`define PCI_E_IDX        4
`define PCI_PORTS        2

// PCI-X Request
`define PCI_REQ_BUS      64
`define PCI_REQ_SZ       62
`define PCI_R_CTAG_HI    61
`define PCI_R_CTAG_LO    50
`define PCI_R_ADD_HI     49
`define PCI_R_ADD_LO     10
`define PCI_R_LEN_HI      9
`define PCI_R_LEN_LO      3
`define PCI_R_COS         1
`define PCI_R_READ        0

// PCI_X Acknowledge
`define PCI_ACK_BUS      64
`define PCI_ACK_SZ       14
`define PCI_A_NACK       13
`define PCI_A_READ       12 
`define PCI_A_CTAG_HI    11
`define PCI_A_CTAG_LO     0


`define BSC_MAX_REQ_SZ   62


//
// BSC array sizes
//================
//
`define BSC_REQ_ARY_INDEX        6
`define BSC_REQ_ARY_DEPTH       64
`define BSC_REQ_ARY_WIDTH       62
`define BSC_REQ_NXT_WIDTH       12
`define BSC_ACK_ARY_INDEX        6
`define BSC_ACK_ARY_DEPTH       64
`define BSC_ACK_ARY_WIDTH       14
`define BSC_ACK_NXT_WIDTH       12
`define BSC_PAY_ARY_INDEX        6
`define BSC_PAY_ARY_DEPTH       64
`define BSC_PAY_ARY_WIDTH      256

// ECC syndrome bits per memory element
`define BSC_PAY_ECC             10
`define BSC_PAY_MEM_WIDTH       (`BSC_PAY_ECC+`BSC_PAY_ARY_WIDTH)


//
// BSC Port Definitions
// ====================
//
// Bits 7 to 4 of curr_port_id
`define BSC_PORT_NULL       4'h0
`define BSC_PORT_SC         4'h1
`define BSC_PORT_EICU       4'h2
`define BSC_PORT_EIPU       4'h3
`define BSC_PORT_EECU       4'h4
`define BSC_PORT_EEPU       4'h8
`define BSC_PORT_PCI        4'h9

// Number of ports of each type
`define BSC_PORT_SC_CNT     8

// Bits needed to represent above
`define BSC_PORT_SC_IDX     3

// How wide the linked list pointers are
// 60b for no payload (2CoS)
// 80b for payload (2CoS)

//`define BSC_OBJ_PTR   80
//`define BSC_HD1_HI    69
//`define BSC_HD1_LO    60
//`define BSC_TL1_HI    59
//`define BSC_TL1_LO    50
//`define BSC_CT1_HI    49
//`define BSC_CT1_LO    40
//`define BSC_HD0_HI    29
//`define BSC_HD0_LO    20
//`define BSC_TL0_HI    19
//`define BSC_TL0_LO    10
//`define BSC_CT0_HI     9
//`define BSC_CT0_LO     0

`define BSC_OBJP_PTR  48
`define BSC_PYP1_HI   47
`define BSC_PYP1_LO   42
`define BSC_HDP1_HI   41
`define BSC_HDP1_LO   36
`define BSC_TLP1_HI   35
`define BSC_TLP1_LO   30
`define BSC_CTP1_HI   29
`define BSC_CTP1_LO   24
`define BSC_PYP0_HI   23
`define BSC_PYP0_LO   18
`define BSC_HDP0_HI   17
`define BSC_HDP0_LO   12
`define BSC_TLP0_HI   11
`define BSC_TLP0_LO    6
`define BSC_CTP0_HI    5
`define BSC_CTP0_LO    0

`define BSC_PTR_WIDTH     192
`define BSC_PTR_REQ_HI    191
`define BSC_PTR_REQ_LO    144
`define BSC_PTR_REQP_HI   143
`define BSC_PTR_REQP_LO    96
`define BSC_PTR_ACK_HI     95
`define BSC_PTR_ACK_LO     48
`define BSC_PTR_ACKP_HI    47
`define BSC_PTR_ACKP_LO     0

`define BSC_PORT_SC_PTR    96       // R, R+P
`define BSC_PORT_EECU_PTR  48       // A+P
`define BSC_PORT_EICU_PTR  96       // A, A+P
`define BSC_PORT_EIPU_PTR  48       // A

// I2C STATES in DRAMctl
`define I2C_CMD_NOP   4'b0000
`define I2C_CMD_START 4'b0001
`define I2C_CMD_STOP  4'b0010
`define I2C_CMD_WRITE 4'b0100
`define I2C_CMD_READ  4'b1000


//
// IOB defines
// ===========
//
`define IOB_ADDR_WIDTH       40
`define IOB_LOCAL_ADDR_WIDTH 32

`define IOB_CPU_INDEX         3
`define IOB_CPU_WIDTH         8
`define IOB_THR_INDEX         2
`define IOB_THR_WIDTH         4
`define IOB_CPUTHR_INDEX      5
`define IOB_CPUTHR_WIDTH     32

`define IOB_MONDO_DATA_INDEX  5
`define IOB_MONDO_DATA_DEPTH 32
`define IOB_MONDO_DATA_WIDTH 64
`define IOB_MONDO_SRC_WIDTH   5
`define IOB_MONDO_BUSY        5

`define IOB_INT_TAB_INDEX     2
`define IOB_INT_TAB_DEPTH     4 

//`define IOB_INT_STAT_WIDTH   32
//`define IOB_INT_STAT_HI      31
//`define IOB_INT_STAT_LO       0

`define IOB_INT_VEC_WIDTH     6
`define IOB_INT_VEC_HI        5
`define IOB_INT_VEC_LO        0

`define IOB_INT_CPU_WIDTH     5
`define IOB_INT_CPU_HI       12 
`define IOB_INT_CPU_LO        8

`define IOB_INT_MASK          2
`define IOB_INT_CLEAR         1
`define IOB_INT_PEND          0

`define IOB_DISP_TYPE_HI     17
`define IOB_DISP_TYPE_LO     16
`define IOB_DISP_THR_HI      12
`define IOB_DISP_THR_LO       8
`define IOB_DISP_VEC_HI       5
`define IOB_DISP_VEC_LO       0

`define IOB_JBI_RESET         1
`define IOB_ENET_RESET        0

`define IOB_RESET_STAT_WIDTH  3
`define IOB_RESET_STAT_HI     3
`define IOB_RESET_STAT_LO     1

`define IOB_SERNUM_WIDTH     64

`define IOB_FUSE_WIDTH       22

`define IOB_TMSTAT_THERM     63

`define IOB_POR_TT            6'b01  // power-on-reset trap type

`define IOB_CPU_BUF_INDEX     4

`define IOB_INT_BUF_INDEX     4  
`define IOB_INT_BUF_WIDTH   153  // interrupt table read result buffer width

`define IOB_IO_BUF_INDEX      4
`define IOB_IO_BUF_WIDTH    153  // io-2-cpu return buffer width

`define IOB_L2_VIS_BUF_INDEX  5
`define IOB_L2_VIS_BUF_WIDTH 48  // l2 visibility buffer width

`define IOB_INT_AVEC_WIDTH    9  // availibility vector width
`define IOB_ACK_AVEC_WIDTH    9  // availibility vector width 

// fixme - double check address mapping
// CREG in `IOB_INT_CSR space
`define IOB_DEV_ADDR_MASK    32'hffffffe7
`define IOB_CREG_INTSTAT     32'h00000000
`define IOB_CREG_MDATA0      32'h00000400
`define IOB_CREG_MDATA1      32'h00000500
`define IOB_CREG_MBUSY       32'h00000900
`define IOB_THR_ADDR_MASK    32'hffffff07
`define IOB_CREG_MDATA0_ALIAS 32'h00000600
`define IOB_CREG_MDATA1_ALIAS 32'h00000700
`define IOB_CREG_MBUSY_ALIAS  32'h00000b00

// CREG in `IOB_MAN_CSR space
`define IOB_CREG_INTMAN      32'h00000000
`define IOB_CREG_INTCTL      32'h00000400
`define IOB_CREG_INTVECDISP  32'h00000800
`define IOB_CREG_RESETSTAT   32'h00000810
`define IOB_CREG_SERNUM      32'h00000820
`define IOB_CREG_TMSTATCTRL  32'h00000828
`define IOB_CREG_COREAVAIL   32'h00000830
`define IOB_CREG_SSYSRESET   32'h00000838
`define IOB_CREG_FUSESTAT    32'h00000840
`define IOB_CREG_MARGIN      32'h00000850
`define IOB_CREG_JINTV       32'h00000a00

`define IOB_CREG_DBG_L2VIS_CTRL    32'h00001800 
`define IOB_CREG_DBG_L2VIS_MASKA   32'h00001820 
`define IOB_CREG_DBG_L2VIS_MASKB   32'h00001828 
`define IOB_CREG_DBG_L2VIS_CMPA    32'h00001830
`define IOB_CREG_DBG_L2VIS_CMPB    32'h00001838
`define IOB_CREG_DBG_L2VIS_TRIG    32'h00001840
`define IOB_CREG_DBG_IOBVIS_CTRL   32'h00001000
`define IOB_CREG_DBG_ENET_CTRL     32'h00002000
`define IOB_CREG_DBG_ENET_IDLEVAL  32'h00002008
`define IOB_CREG_DBG_JBUS_CTRL     32'h00002100
`define IOB_CREG_DBG_JBUS_LO_MASK0 32'h00002140
`define IOB_CREG_DBG_JBUS_LO_MASK1 32'h00002160
`define IOB_CREG_DBG_JBUS_LO_CMP0  32'h00002148
`define IOB_CREG_DBG_JBUS_LO_CMP1  32'h00002168
`define IOB_CREG_DBG_JBUS_LO_CNT0  32'h00002150
`define IOB_CREG_DBG_JBUS_LO_CNT1  32'h00002170
`define IOB_CREG_DBG_JBUS_HI_MASK0 32'h00002180
`define IOB_CREG_DBG_JBUS_HI_MASK1 32'h000021a0
`define IOB_CREG_DBG_JBUS_HI_CMP0  32'h00002188
`define IOB_CREG_DBG_JBUS_HI_CMP1  32'h000021a8
`define IOB_CREG_DBG_JBUS_HI_CNT0  32'h00002190
`define IOB_CREG_DBG_JBUS_HI_CNT1  32'h000021b0

`define IOB_CREG_TESTSTUB    32'h80000000

// Address map for TAP access of SPARC ASI
`define IOB_ASI_PC            4'b0000
`define IOB_ASI_BIST          4'b0001
`define IOB_ASI_MARGIN        4'b0010
`define IOB_ASI_DEFEATURE     4'b0011
`define IOB_ASI_L1DD          4'b0100
`define IOB_ASI_L1ID          4'b0101
`define IOB_ASI_L1DT          4'b0110

`define IOB_INT               2'b00
`define IOB_RESET             2'b01
`define IOB_IDLE              2'b10
`define IOB_RESUME            2'b11

//
// CIOP UCB Bus Width
// ==================
//
//`define IOB_EECU_WIDTH       16  // ethernet egress command
//`define EECU_IOB_WIDTH       16

//`define IOB_NRAM_WIDTH       16  // NRAM (RLDRAM previously)
//`define NRAM_IOB_WIDTH        4

`define IOB_JBI_WIDTH        64  // JBI
`define JBI_IOB_WIDTH        16 

//`define IOB_ENET_ING_WIDTH   32  // ethernet ingress
//`define ENET_ING_IOB_WIDTH    8

//`define IOB_ENET_EGR_WIDTH    4  // ethernet egress
//`define ENET_EGR_IOB_WIDTH    4

//`define IOB_ENET_MAC_WIDTH    4  // ethernet MAC
//`define ENET_MAC_IOB_WIDTH    4

`define IOB_DRAM_WIDTH        4  // DRAM controller
`define DRAM_IOB_WIDTH        4

//`define IOB_BSC_WIDTH         4  // BSC
//`define BSC_IOB_WIDTH         4

`define IOB_SPI_WIDTH         4  // SPI (Boot ROM)
`define SPI_IOB_WIDTH         4

`define IOB_CLK_WIDTH         4  // clk unit
`define CLK_IOB_WIDTH         4

//`define IOB_CLSP_WIDTH        4  // clk spine unit
//`define CLSP_IOB_WIDTH        4

`define IOB_TAP_WIDTH         8  // TAP
`define TAP_IOB_WIDTH         8


//
// CIOP UCB Buf ID Type
// ====================
//
`define UCB_BID_CMP          2'b00
`define UCB_BID_TAP          2'b01

//
// Interrupt Device ID
// ===================
//
// Caution: DUMMY_DEV_ID has to be 9 bit wide
//          for fields to line up properly in the IOB.
`define DUMMY_DEV_ID         9'h00   // 0
`define UNCOR_ECC_DEV_ID     7'd1    // 1

//
// Soft Error related definitions 
// ==============================
//
`define COR_ECC_CNT_WIDTH   16


//
// CMP clock
// =========
//

`define CMP_CLK_PERIOD   1333


//
// NRAM/IO Interface
// =================
//

`define DRAM_CLK_PERIOD  6000

`define NRAM_IO_DQ_WIDTH   32
`define IO_NRAM_DQ_WIDTH   32

`define NRAM_IO_ADDR_WIDTH 15
`define NRAM_IO_BA_WIDTH    2


//
// NRAM/ENET Interface
// ===================
//

`define NRAM_ENET_DATA_WIDTH 64
`define ENET_NRAM_ADDR_WIDTH 20

`define NRAM_DBG_DATA_WIDTH  40


//
// IO/FCRAM Interface
// ==================
//

`define FCRAM_DATA1_HI       63
`define FCRAM_DATA1_LO       32
`define FCRAM_DATA0_HI       31
`define FCRAM_DATA0_LO        0

//
// PCI Interface
// ==================
// Load/store size encodings
// -------------------------
// Size encoding
// 000 - byte
// 001 - half-word
// 010 - word
// 011 - double-word
// 100 - quad
`define LDST_SZ_BYTE        3'b000
`define LDST_SZ_HALF_WORD   3'b001
`define LDST_SZ_WORD        3'b010
`define LDST_SZ_DOUBLE_WORD 3'b011
`define LDST_SZ_QUAD        3'b100

//
// JBI<->SCTAG Interface
// =======================
// Outbound Header Format
`define JBI_BTU_OUT_ADDR_LO      0
`define JBI_BTU_OUT_ADDR_HI     42
`define JBI_BTU_OUT_RSV0_LO     43
`define JBI_BTU_OUT_RSV0_HI     43
`define JBI_BTU_OUT_TYPE_LO     44
`define JBI_BTU_OUT_TYPE_HI     48
`define JBI_BTU_OUT_RSV1_LO     49
`define JBI_BTU_OUT_RSV1_HI     51
`define JBI_BTU_OUT_REPLACE_LO  52
`define JBI_BTU_OUT_REPLACE_HI  56
`define JBI_BTU_OUT_RSV2_LO     57
`define JBI_BTU_OUT_RSV2_HI     59
`define JBI_BTU_OUT_BTU_ID_LO   60
`define JBI_BTU_OUT_BTU_ID_HI   71
`define JBI_BTU_OUT_DATA_RTN    72
`define JBI_BTU_OUT_RSV3_LO     73
`define JBI_BTU_OUT_RSV3_HI     75
`define JBI_BTU_OUT_CE          76
`define JBI_BTU_OUT_RSV4_LO     77
`define JBI_BTU_OUT_RSV4_HI     79
`define JBI_BTU_OUT_UE          80
`define JBI_BTU_OUT_RSV5_LO     81
`define JBI_BTU_OUT_RSV5_HI     83
`define JBI_BTU_OUT_DRAM        84
`define JBI_BTU_OUT_RSV6_LO     85
`define JBI_BTU_OUT_RSV6_HI    127

// Inbound Header Format
`define JBI_SCTAG_IN_ADDR_LO   0
`define JBI_SCTAG_IN_ADDR_HI  39
`define JBI_SCTAG_IN_SZ_LO    40
`define JBI_SCTAG_IN_SZ_HI    42
`define JBI_SCTAG_IN_RSV0     43
`define JBI_SCTAG_IN_TAG_LO   44
`define JBI_SCTAG_IN_TAG_HI   55
`define JBI_SCTAG_IN_REQ_LO   56
`define JBI_SCTAG_IN_REQ_HI   58
`define JBI_SCTAG_IN_POISON   59
`define JBI_SCTAG_IN_RSV1_LO  60
`define JBI_SCTAG_IN_RSV1_HI  63

`define JBI_SCTAG_REQ_WRI   3'b100
`define JBI_SCTAG_REQ_WR8   3'b010
`define JBI_SCTAG_REQ_RDD   3'b001
`define JBI_SCTAG_REQ_WRI_BIT 2
`define JBI_SCTAG_REQ_WR8_BIT 1
`define JBI_SCTAG_REQ_RDD_BIT 0

//
// JBI->IOB Mondo Header Format
// ============================
//
`define JBI_IOB_MONDO_RSV1_HI       15 // reserved 1
`define JBI_IOB_MONDO_RSV1_LO       13
`define JBI_IOB_MONDO_TRG_HI        12 // interrupt target
`define JBI_IOB_MONDO_TRG_LO         8 
`define JBI_IOB_MONDO_RSV0_HI        7 // reserved 0
`define JBI_IOB_MONDO_RSV0_LO        5
`define JBI_IOB_MONDO_SRC_HI         4 // interrupt source
`define JBI_IOB_MONDO_SRC_LO         0

`define JBI_IOB_MONDO_RSV1_WIDTH     3 
`define JBI_IOB_MONDO_TRG_WIDTH      5
`define JBI_IOB_MONDO_RSV0_WIDTH     3 
`define JBI_IOB_MONDO_SRC_WIDTH      5

// JBI->IOB Mondo Bus Width/Cycle
// ==============================
// Cycle  1 Header[15:8]
// Cycle  2 Header[ 7:0]
// Cycle  3 J_AD[127:120]
// Cycle  4 J_AD[119:112]
// .....
// Cycle 18 J_AD[  7:  0]
`define JBI_IOB_MONDO_BUS_WIDTH      8
`define JBI_IOB_MONDO_BUS_CYCLE     18 // 2 header + 16 data

`ifndef L15_H
`define L15_H

// `define L15_CACHELINE_WIDTH 128
`define L15_HMT_ENTRY_WIDTH 32

`define L15_UNPARAM_1_0 1:0
`define L15_UNPARAM_2_0 2:0
`define L15_UNPARAM_3_0 3:0
`define L15_UNPARAM_7_0 7:0
`define L15_UNPARAM_5_0 5:0
`define L15_UNPARAM_11_0 11:0
`define L15_UNPARAM_15_0 15:0
`define L15_UNPARAM_63_0 63:0
`define L15_UNPARAM_127_0 127:0

`define L15_PADDR_HI 39
`define L15_PADDR_WIDTH 40
`define L15_PADDR_MASK 39:0


// /home/hongce/ila/openpiton/piton/verif/env/manycore/devices.xml
// this is used in the ariane SV packages to derive the parameterization
`define CONFIG_L1D_CACHELINE_WIDTH 128
`define CONFIG_L1I_CACHELINE_WIDTH 256
`define CONFIG_L15_SIZE 8192
`define CONFIG_L1D_SIZE 8192
`define CONFIG_L1I_SIZE 16384
`define CONFIG_L15_ASSOCIATIVITY 4
`define CONFIG_L1D_ASSOCIATIVITY 4
`define CONFIG_L1I_ASSOCIATIVITY 4



`define L15_NUM_ENTRIES 512
`define L15_NUM_ENTRIES_LOG2 9
`define L15_WAY_COUNT 4
`define L15_WAY_WIDTH 2
`define L15_CACHELINE_WIDTH 128


`define L15_MESI_STATE_WIDTH 2
`define L15_MESI_STATE_I 2'd0
`define L15_MESI_STATE_S 2'd1
`define L15_MESI_STATE_E 2'd2
`define L15_MESI_STATE_M 2'd3

`define L15_MESI_TRANS_STATE_WIDTH 2
`define L15_MESI_TRANSITION_STATE_SM 2'b01
`define L15_MESI_TRANSITION_STATE_IM 2'b10
`define L15_MESI_TRANSITION_STATE_WAIT_ACK 2'b11

`define L15_WAY_MASK `L15_WAY_WIDTH-1:0
`define L15_WAY_ARRAY_WIDTH `L15_WAY_COUNT
`define L15_WAY_ARRAY_MASK `L15_WAY_COUNT-1:0
`define L15_WAY_ARRAY_WAY0_MASK `L15_WAY_WIDTH'd0
`define L15_WAY_ARRAY_WAY1_MASK `L15_WAY_WIDTH'd1
`define L15_WAY_ARRAY_WAY2_MASK `L15_WAY_WIDTH'd2
`define L15_WAY_ARRAY_WAY3_MASK `L15_WAY_WIDTH'd3
`define L15_WAY_ARRAY_WAY4_MASK `L15_WAY_WIDTH'd4
`define L15_WAY_ARRAY_WAY5_MASK `L15_WAY_WIDTH'd5
`define L15_WAY_ARRAY_WAY6_MASK `L15_WAY_WIDTH'd6
`define L15_WAY_ARRAY_WAY7_MASK `L15_WAY_WIDTH'd7
`define L15_WAYID_WAY0 `L15_WAY_WIDTH'd0
`define L15_WAYID_WAY1 `L15_WAY_WIDTH'd1
`define L15_WAYID_WAY2 `L15_WAY_WIDTH'd2
`define L15_WAYID_WAY3 `L15_WAY_WIDTH'd3
`define L15_WAYID_WAY4 `L15_WAY_WIDTH'd4
`define L15_WAYID_WAY5 `L15_WAY_WIDTH'd5
`define L15_WAYID_WAY6 `L15_WAY_WIDTH'd6
`define L15_WAYID_WAY7 `L15_WAY_WIDTH'd7

// 7
`define L15_NUM_4WAY_ENTRIES_LOG2 (`L15_NUM_ENTRIES_LOG2-2)
// 7
`define L15_CACHE_INDEX_WIDTH (`L15_NUM_4WAY_ENTRIES_LOG2)
`define L15_CACHE_INDEX_MASK `L15_CACHE_INDEX_WIDTH-1:0
`define L15_CACHE_INDEX_VECTOR_WIDTH (`L15_NUM_ENTRIES/4)

// 16B cache lines
`define L15_IDX_LOW 4
// 10
`define L15_IDX_HI (`L15_CACHE_INDEX_WIDTH+`L15_IDX_LOW-1)

`define L15_CACHE_TAG_RAW_WIDTH 33
`define L15_CACHE_TAG_RAW_SRAM_WIDTH 33*`L15_WAY_COUNT
// 40 - 4 (16B line) - 7 (index width) = 29
`define L15_CACHE_TAG_WIDTH (`L15_PADDR_WIDTH - 4 - `L15_CACHE_INDEX_WIDTH)
// 11
`define L15_CACHE_TAG_LOW (`L15_IDX_HI + 1)
// 39
`define L15_CACHE_TAG_HI (`L15_PADDR_HI)

// this need to be defined when L1.5 has more sets than L1D
// for correct operations
// `define L15_WMT_EXTENDED_ALIAS

`ifdef L15_WMT_EXTENDED_ALIAS
// `define L15_WMT_ALIAS_WIDTH 4
// `define L15_WMT_ALIAS_LOW `L1D_SET_IDX_HI+1
`define L15_WMT_ALIAS_LOW `L1D_ADDRESS_HI+1
// `define L15_WMT_ALIAS_HI `L15_WMT_ALIAS_LOW + `L15_WMT_ALIAS_WIDTH - 1
`define L15_WMT_ALIAS_HI `L15_WMT_ALIAS_LOW + `L15_WMT_ALIAS_WIDTH - 1
`define L15_WMT_ALIAS_MASK `L15_WMT_ALIAS_HI:`L15_WMT_ALIAS_LOW
`else
`define L15_WMT_ALIAS_WIDTH 0
`endif

`define L15_WMT_DATA_WIDTH (`L15_WAY_WIDTH+`L15_WMT_ALIAS_WIDTH)
`define L15_WMT_DATA_MASK `L15_WMT_DATA_WIDTH-1:0
`define L15_WMT_VALID_MASK `L15_WMT_DATA_WIDTH
`define L15_WMT_ENTRY_WIDTH (`L15_WMT_DATA_WIDTH+1)
`define L15_WMT_ENTRY_MASK `L15_WMT_ENTRY_WIDTH-1:0

// `define L15_WMT_ENTRY_0_MASK 1*`L15_WMT_ENTRY_WIDTH-1 -: `L15_WMT_ENTRY_WIDTH
// `define L15_WMT_ENTRY_1_MASK 2*`L15_WMT_ENTRY_WIDTH-1 -: `L15_WMT_ENTRY_WIDTH
// `define L15_WMT_ENTRY_2_MASK 3*`L15_WMT_ENTRY_WIDTH-1 -: `L15_WMT_ENTRY_WIDTH
// `define L15_WMT_ENTRY_3_MASK 4*`L15_WMT_ENTRY_WIDTH-1 -: `L15_WMT_ENTRY_WIDTH
// `define L15_WMT_ENTRY_0_VALID_MASK 1*`L15_WMT_ENTRY_WIDTH-1
// `define L15_WMT_ENTRY_1_VALID_MASK 2*`L15_WMT_ENTRY_WIDTH-1
// `define L15_WMT_ENTRY_2_VALID_MASK 3*`L15_WMT_ENTRY_WIDTH-1
// `define L15_WMT_ENTRY_3_VALID_MASK 4*`L15_WMT_ENTRY_WIDTH-1


  `define L15_WMT_ENTRY_0_MASK (0+1)*`L15_WMT_ENTRY_WIDTH-1 -: `L15_WMT_ENTRY_WIDTH
  `define L15_WMT_ENTRY_0_VALID_MASK (0+1)*`L15_WMT_ENTRY_WIDTH-1


  `define L15_WMT_ENTRY_1_MASK (1+1)*`L15_WMT_ENTRY_WIDTH-1 -: `L15_WMT_ENTRY_WIDTH
  `define L15_WMT_ENTRY_1_VALID_MASK (1+1)*`L15_WMT_ENTRY_WIDTH-1


  `define L15_WMT_ENTRY_2_MASK (2+1)*`L15_WMT_ENTRY_WIDTH-1 -: `L15_WMT_ENTRY_WIDTH
  `define L15_WMT_ENTRY_2_VALID_MASK (2+1)*`L15_WMT_ENTRY_WIDTH-1


  `define L15_WMT_ENTRY_3_MASK (3+1)*`L15_WMT_ENTRY_WIDTH-1 -: `L15_WMT_ENTRY_WIDTH
  `define L15_WMT_ENTRY_3_VALID_MASK (3+1)*`L15_WMT_ENTRY_WIDTH-1



`define L15_WMT_WIDTH `L1D_WAY_COUNT*`L15_WMT_ENTRY_WIDTH
`define L15_WMT_MASK `L15_WMT_WIDTH-1:0
`define L15_WMT_ENTRY_COUNT `L1D_SET_COUNT

// LRU array storage
// keeps 6 bits per cache set: 4 "used" bits, 1 each cache line, and 2 bits for wayid round robin (4w)
`define L15_LRUARRAY_WIDTH (`L15_WAY_WIDTH + `L15_WAY_ARRAY_WIDTH)
`define L15_LRUARRAY_MASK (`L15_WAY_WIDTH + `L15_WAY_ARRAY_WIDTH)-1:0
`define L15_LRUARRAY_USED_MASK `L15_WAY_ARRAY_MASK
`define L15_LRUARRAY_RR_MASK `L15_WAY_ARRAY_WIDTH+`L15_WAY_WIDTH-1 -: `L15_WAY_WIDTH

// source
`define L15_PREDECODE_SOURCE_WIDTH 2
`define L15_PREDECODE_SOURCE_INVALID 2'd0
`define L15_PREDECODE_SOURCE_PCX 2'd1
`define L15_PREDECODE_SOURCE_NOC2 2'd2

// MSHR
`define L15_MSHR_WRITE_TYPE_WIDTH 3
`define L15_MSHR_WRITE_TYPE_ALLOCATION 3'b001
`define L15_MSHR_WRITE_TYPE_DEALLOCATION 3'b010
`define L15_MSHR_WRITE_TYPE_UPDATE_ST_STATE 3'b011
`define L15_MSHR_WRITE_TYPE_UPDATE_WRITE_CACHE 3'b100

// controls how many mshr there are
// `define L15_MSHR_COUNT 10
// should be more than the count above when 2^n
`define L15_MSHR_ID_WIDTH 2
`define L15_MSHR_ID_IFILL 2'd1
`define L15_MSHR_ID_LD 2'd2
`define L15_MSHR_ID_ST 2'd3

`define L15_NUM_THREADS 2
`define L15_THREADID_WIDTH 1
`define L15_THREADID_MASK 0:0
`define L15_THREAD_ARRAY_MASK 1:0
`define L15_NUM_MSHRID_PER_THREAD 4

// pipeline OPs
`define L15_S1_MSHR_OP_WIDTH 2
`define L15_S1_MSHR_OP_ALLOCATE 2'd1
`define L15_S1_MSHR_OP_UPDATE_WRITECACHE 2'd2

// `define L15_MSHR_ALLOCATE_TYPE_WIDTH 2
// `define L15_MSHR_ALLOCATE_TYPE_LD 2'd1
// `define L15_MSHR_ALLOCATE_TYPE_ST 2'd2
// `define L15_MSHR_ALLOCATE_TYPE_IFILL 2'd3


`define L15_S2_MSHR_OP_WIDTH 1
`define L15_S2_MSHR_OP_READ_WRITE_CACHE 1'd1

`define L15_S3_MSHR_OP_WIDTH 3
`define L15_S3_MSHR_OP_DEALLOCATION 3'd1
`define L15_S3_MSHR_OP_DEALLOCATION_IF_TAGCHECK_MES 3'd2
`define L15_S3_MSHR_OP_DEALLOCATION_IF_TAGCHECK_M_E_ELSE_UPDATE_STATE_STMSHR 3'd3
`define L15_S3_MSHR_OP_UPDATE_ST_MSHR_IM_IF_INDEX_TAGCHECK_WAY_MATCHES 3'd4
`define L15_S3_MSHR_OP_UPDATE_ST_MSHR_IM_IF_INDEX_LRU_WAY_MATCHES 3'd5
`define L15_S3_MSHR_OP_UPDATE_ST_MSHR_WAIT_ACK 3'd6

`define L15_MSHRS3_OP_DEALLOCATION 2'b01
`define L15_MSHRS3_OP_UPDATE 2'b10

`define L15_REQTYPE_WIDTH 6
`define L15_REQTYPE_NONE 6'd0
`define L15_REQTYPE_IGNORE 6'd1
`define L15_REQTYPE_IFILL 6'd2
`define L15_REQTYPE_STORE 6'd3
`define L15_REQTYPE_CAS 6'd4
`define L15_REQTYPE_SWP_LOADSTUB 6'd5
`define L15_REQTYPE_INVALIDATION 6'd6
`define L15_REQTYPE_DOWNGRADE 6'd7
`define L15_REQTYPE_ACKDT_LD_NC 6'd8
`define L15_REQTYPE_ACKDT_IFILL 6'd9
`define L15_REQTYPE_ACKDT_LD 6'd10
`define L15_REQTYPE_ACKDT_ST_IM 6'd11
`define L15_REQTYPE_ACKDT_ST_SM 6'd12
`define L15_REQTYPE_ACK_WRITETHROUGH 6'd13
`define L15_REQTYPE_ACK_ATOMIC 6'd14
`define L15_REQTYPE_LOAD_NC 6'd15
`define L15_REQTYPE_LOAD_PREFETCH 6'd16
`define L15_REQTYPE_WRITETHROUGH 6'd17
`define L15_REQTYPE_ICACHE_INVALIDATION 6'd18
`define L15_REQTYPE_PCX_INTERRUPT 6'd19
`define L15_REQTYPE_L2_INTERRUPT 6'd20
`define L15_REQTYPE_LOAD 6'd21
`define L15_REQTYPE_INT_VEC_DIS 6'd22
`define L15_REQTYPE_WRITE_CONFIG_REG 6'd23
`define L15_REQTYPE_LOAD_CONFIG_REG 6'd24
`define L15_REQTYPE_DIAG_LOAD 6'd25
`define L15_REQTYPE_DIAG_STORE 6'd26
`define L15_REQTYPE_LINE_FLUSH 6'd27
`define L15_REQTYPE_HMC_FILL 6'd28
`define L15_REQTYPE_HMC_DIAG_LOAD 6'd29
`define L15_REQTYPE_HMC_DIAG_STORE 6'd30
`define L15_REQTYPE_HMC_FLUSH 6'd31
`define L15_REQTYPE_ACK_PREFETCH 6'd32
`define L15_REQTYPE_ICACHE_SELF_INVALIDATION 6'd33
`define L15_REQTYPE_DCACHE_SELF_INVALIDATION 6'd34
`define L15_REQTYPE_AMO_LR    6'd35
`define L15_REQTYPE_AMO_SC    6'd36
`define L15_REQTYPE_AMO_ADD   6'd38
`define L15_REQTYPE_AMO_AND   6'd39
`define L15_REQTYPE_AMO_OR    6'd40
`define L15_REQTYPE_AMO_XOR   6'd41
`define L15_REQTYPE_AMO_MAX   6'd42
`define L15_REQTYPE_AMO_MAXU  6'd43
`define L15_REQTYPE_AMO_MIN   6'd44
`define L15_REQTYPE_AMO_MINU  6'd45


`define PCX_SIZE_WIDTH 3
`define PCX_SIZE_FIELD_WIDTH 3
`define PCX_REQTYPE_WIDTH 5
`define PCX_REQTYPE_LOAD `LOAD_RQ
`define PCX_REQTYPE_IFILL `IMISS_RQ
`define PCX_REQTYPE_STORE `STORE_RQ
`define PCX_REQTYPE_CAS1 `CAS1_RQ
`define PCX_REQTYPE_CAS2 `CAS2_RQ
`define PCX_REQTYPE_SWP_LOADSTUB `SWAP_RQ
`define PCX_REQTYPE_INTERRUPT `INT_RQ
`define PCX_REQTYPE_FP1 5'b01010
`define PCX_REQTYPE_FP2 5'b01011
`define PCX_REQTYPE_STREAM_LOAD `STRLOAD_RQ
`define PCX_REQTYPE_STREAM_STORE `STRST_RQ
`define PCX_REQTYPE_FWD_REQ `FWD_RQ
`define PCX_REQTYPE_FWD_REPLY `FWD_RPY
`define PCX_REQTYPE_AMO `SWAP_RQ

`define L15_AMO_OP_WIDTH 4
`define L15_AMO_OP_NONE  4'b0000
`define L15_AMO_OP_LR    4'b0001
`define L15_AMO_OP_SC    4'b0010
`define L15_AMO_OP_SWAP  4'b0011
`define L15_AMO_OP_ADD   4'b0100
`define L15_AMO_OP_AND   4'b0101
`define L15_AMO_OP_OR    4'b0110
`define L15_AMO_OP_XOR   4'b0111
`define L15_AMO_OP_MAX   4'b1000
`define L15_AMO_OP_MAXU  4'b1001
`define L15_AMO_OP_MIN   4'b1010
`define L15_AMO_OP_MINU  4'b1011
`define L15_AMO_OP_CAS1  4'b1100
`define L15_AMO_OP_CAS2  4'b1101

// `define PCX_REQ_SIZE_WIDTH 4
`define CPX_RESTYPE_WIDTH 4
`define CPX_RESTYPE_LOAD `LOAD_RET
`define CPX_RESTYPE_IFILL1 `IFILL_RET
`define CPX_RESTYPE_IFILL2 `IFILL_RET
`define CPX_RESTYPE_STREAM_LOAD `STRLOAD_RET
`define CPX_RESTYPE_INVAL `INV_RET
`define CPX_RESTYPE_STORE_ACK `ST_ACK
`define CPX_RESTYPE_STREAM_STORE_ACK `STRST_ACK
`define CPX_RESTYPE_INTERRUPT `INT_RET
`define CPX_RESTYPE_FP `FP_RET
`define CPX_RESTYPE_FWD_REQ `FWD_RQ_RET
`define CPX_RESTYPE_FWD_REPLY `FWD_RPY_RET
`define CPX_RESTYPE_ATOMIC_RES 4'b1110 // custom type

`define L15_CONTROL_PREFETCH_1B 0
`define L15_CONTROL_BLOCKSTOREINIT_1B (`L15_CONTROL_PREFETCH_1B + 1)
`define L15_CONTROL_LOAD (`L15_CONTROL_BLOCKSTOREINIT_1B + 1)
`define L15_CONTROL_ATOMIC (`L15_CONTROL_LOAD + 1)
`define L15_CONTROL_ICACHE (`L15_CONTROL_ATOMIC + 1)
`define L15_CONTROL_SIZE_3B (`L15_CONTROL_ICACHE + 3)
`define L15_CONTROL_THREADID (`L15_CONTROL_SIZE_3B + `L15_THREADID_WIDTH)
`define L15_CONTROL_L1_REPLACEMENT_WAY_2B (`L15_CONTROL_THREADID + `L15_WAY_WIDTH)
`define L15_CONTROL_NC_1B (`L15_CONTROL_L1_REPLACEMENT_WAY_2B + 1)
`define L15_CONTROL_BLOCKSTORE_1B (`L15_CONTROL_NC_1B + 1)
`define L15_CONTROL_WIDTH (`L15_CONTROL_BLOCKSTORE_1B + 1)

// define the width of the flattened, native L15 interface, used for ARIANE_RV64 option
`define L15_REQ_WIDTH  (14 + 40 + 2*64 +      \
                        `PCX_REQTYPE_WIDTH  + \
                        `L15_THREADID_WIDTH + \
                        `L15_WAY_WIDTH      + \
                        `TLB_CSM_WIDTH )

`define L15_RTRN_WIDTH (16 + 4*64 + (15 - 4 + 1) + \
                        `CPX_RESTYPE_WIDTH  +      \
                        `L15_THREADID_WIDTH +      \
                        2 * `L15_WAY_WIDTH)

`define L15_FETCH_STATE_WIDTH 3
`define L15_FETCH_STATE_NORMAL 3'd0
`define L15_FETCH_STATE_PCX_WRITEBACK_DONE 3'd1
`define L15_FETCH_STATE_INVAL_2 3'd2
`define L15_FETCH_STATE_INVAL_3 3'd3
`define L15_FETCH_STATE_INVAL_4 3'd4
`define L15_FETCH_STATE_NOC2_WRITEBACK_DONE 3'd5
`define L15_FETCH_STATE_ICACHE_INVAL_2 3'd6

`define L15_ACK_STAGE_WIDTH 2
`define L15_ACK_STAGE_NEVER 2'd0
`define L15_ACK_STAGE_S1 2'd1
`define L15_ACK_STAGE_S2 2'd2
`define L15_ACK_STAGE_S3 2'd3


// [L15_DTAG_OP_WIDTH-1:0]

`define L15_DTAG_OP_WIDTH 2
`define L15_DTAG_OP_READ 2'd1
`define L15_DTAG_OP_WRITE 2'd2

`define L15_DTAG_RW_READ 1'b1
`define L15_DTAG_RW_WRITE 1'b0

`define L15_S2_MESI_OP_WIDTH 1
`define L15_S2_MESI_READ 1'd1

`define L15_DCACHE_OP_WIDTH 4
`define L15_DCACHE_READ_TAGCHECK_WAY_IF_M 4'd1
`define L15_DCACHE_READ_TAGCHECK_WAY_IF_MES 4'd2
`define L15_DCACHE_READ_LRU_WAY_IF_M 4'd3
`define L15_DCACHE_WRITE_TAGCHECK_WAY_IF_ME_FROM_MSHR 4'd4
`define L15_DCACHE_WRITE_LRU_WAY_FROM_NOC2 4'd5
`define L15_DCACHE_WRITE_LRU_WAY_FROM_NOC2_AND_MSHR 4'd6
`define L15_DCACHE_WRITE_MSHR_WAY_FROM_MSHR 4'd7
`define L15_DCACHE_DIAG_READ 4'd8
`define L15_DCACHE_DIAG_WRITE 4'd9
`define L15_DCACHE_READ_FLUSH_WAY_IF_M 4'd10

`define L15_S3_MESI_OP_WIDTH 3
`define L15_S3_MESI_WRITE_TAGCHECK_WAY_S_IF_ME 3'd1
`define L15_S3_MESI_WRITE_TAGCHECK_WAY_M_IF_E 3'd2
`define L15_S3_MESI_INVALIDATE_TAGCHECK_WAY_IF_MES 3'd3
`define L15_S3_MESI_WRITE_LRU_WAY_ACK_STATE 3'd4
`define L15_S3_MESI_WRITE_MSHR_WAY_ACK_STATE 3'd5
`define L15_S3_MESI_INVALIDATE_FLUSH_WAY_IF_MES 3'd6

`define L15_WMT_READ_OP_WIDTH 1
`define L15_WMT_READ 1'd1

`define L15_WMT_WRITE_OP_WIDTH 3
`define L15_WMT_DEMAP_TAGCHECK_WAY_IF_MES 3'd1
`define L15_WMT_DEMAP_LRU_WAY_IF_MES 3'd2
`define L15_WMT_UPDATE_LRU_WAY_AND_DEDUP_ENTRY 3'd3
`define L15_WMT_UPDATE_TAGCHECK_WAY_AND_DEDUP_ENTRY_IF_TAGCHECK_WAY_IS_MES 3'd4
`define L15_WMT_DEMAP_FLUSH_WAY_IF_MES 3'd5

`define L15_WMT_COMPARE_OP_WIDTH 3
`define L15_WMT_COMPARE_LRU 3'd1
`define L15_WMT_COMPARE_TAGCHECK 3'd2
`define L15_WMT_COMPARE_FLUSH 3'd3
`define L15_WMT_COMPARE_STBUF 3'd4

`define L15_LRUARRAY_WRITE_OP_WIDTH 3
`define L15_LRU_UPDATE_ACCESS_BITS_IF_TAGCHECK_WAY_IS_MES 3'd1
`define L15_LRU_EVICTION 3'd2
`define L15_LRU_REPLACEMENT 3'd3
`define L15_LRU_INVALIDATE_IF_TAGCHECK_WAY_IS_MES 3'd4
`define L15_LRU_INVALIDATE_IF_FLUSH_WAY_IS_MES 3'd5

`define L15_CONFIG_OP_WIDTH 2
`define L15_CONFIG_LOAD 2'd1
`define L15_CONFIG_WRITE 2'd2

`define L15_CPX_OP_WIDTH 5
`define L15_CPX_GEN_INVALIDATION_IF_TAGCHECK_MES_AND_WAYMAP_VALID 5'd1
`define L15_CPX_GEN_LD_RESPONSE_BOGUS_DATA 5'd2
`define L15_CPX_GEN_LD_RESPONSE_BOGUS_DATA_IF_TAGCHECK_MES 5'd3
`define L15_CPX_GEN_LD_RESPONSE_IF_TAGCHECK_MES_FROM_DCACHE 5'd4
`define L15_CPX_GEN_LD_RESPONSE_FROM_NOC2 5'd5
`define L15_CPX_GEN_ST_ACK 5'd6
`define L15_CPX_GEN_ST_ACK_IF_TAGCHECK_M_E_WITH_POSSIBLE_INVAL 5'd7
`define L15_CPX_GEN_INVALIDATION_IF_LRU_MES_AND_WAYMAP_VALID 5'd8
`define L15_CPX_GEN_IFILL_RESPONSE_FROM_NOC2 5'd9
`define L15_CPX_GEN_ATOMIC_ACK_FROM_NOC2 5'd10
`define L15_CPX_GEN_ST_ACK_WITH_POSSIBLE_INVAL 5'd11
`define L15_CPX_GEN_BROADCAST_ACK 5'd12
`define L15_CPX_GEN_INTERRUPT 5'd13
`define L15_CPX_GEN_ICACHE_INVALIDATION 5'd14
`define L15_CPX_GEN_LOAD_CONFIG_REG_RESPONSE 5'd15
`define L15_CPX_GEN_LD_RESPONSE_FROM_DCACHE 5'd16
`define L15_CPX_GEN_INVALIDATION_IF_FLUSH_MES_AND_WAYMAP_VALID 5'd17
`define L15_CPX_GEN_LD_RESPONSE_FROM_CSM 5'd18
`define L15_CPX_GEN_DCACHE_INVALIDATION 5'd19

`define L15_NOC1_OP_WIDTH 5
`define L15_NOC1_GEN_DATA_LD_REQUEST 5'd1
`define L15_NOC1_GEN_DATA_LD_REQUEST_IF_TAGCHECK_MISS 5'd2
`define L15_NOC1_GEN_INSTRUCTION_LD_REQUEST 5'd3
`define L15_NOC1_GEN_DATA_ST_UPGRADE_IF_TAGCHECK_S_ELSE_ST_FILL_IF_TAGCHECK_I 5'd4
`define L15_NOC1_GEN_DATA_WRITETHROUGH_REQUEST_FROM_PCX 5'd5
`define L15_NOC1_GEN_DATA_CAS_REQUEST_FROM_PCX 5'd6
`define L15_NOC1_GEN_DATA_SWAP_REQUEST_FROM_PCX 5'd7
`define L15_NOC1_GEN_WRITEBACK_GUARD_IF_LRU_M 5'd8
`define L15_NOC1_GEN_WRITEBACK_GUARD_IF_TAGCHECK_M 5'd9
`define L15_NOC1_GEN_INTERRUPT_FWD 5'd10
// `define L15_NOC1_DUMMY_GEN_NOC1_CREDIT 5'd11
`define L15_NOC1_GEN_WRITEBACK_GUARD_IF_FLUSH_M 5'd12
`define L15_NOC1_GEN_DATA_ADD_REQUEST_FROM_PCX 5'd13
`define L15_NOC1_GEN_DATA_AND_REQUEST_FROM_PCX 5'd14
`define L15_NOC1_GEN_DATA_OR_REQUEST_FROM_PCX 5'd15
`define L15_NOC1_GEN_DATA_XOR_REQUEST_FROM_PCX 5'd16
`define L15_NOC1_GEN_DATA_MAX_REQUEST_FROM_PCX 5'd17
`define L15_NOC1_GEN_DATA_MAXU_REQUEST_FROM_PCX 5'd18
`define L15_NOC1_GEN_DATA_MIN_REQUEST_FROM_PCX 5'd19
`define L15_NOC1_GEN_DATA_MINU_REQUEST_FROM_PCX 5'd20

`define L15_NOC1_CAS_COMPARE_HI_64b 127
`define L15_NOC1_CAS_SWAP_HI_64b 63

`define L15_NOC3_OP_WIDTH 4
`define L15_NOC3_GEN_INVAL_ACK_FROM_DCACHE 4'd1
`define L15_NOC3_GEN_INVAL_ACK_IF_TAGCHECK_M_FROM_DCACHE 4'd2
`define L15_NOC3_GEN_DOWNGRADE_ACK_FROM_DCACHE 4'd3
`define L15_NOC3_GEN_DOWNGRADE_ACK_IF_TAGCHECK_M_FROM_DCACHE 4'd4
`define L15_NOC3_GEN_WRITEBACK_IF_TAGCHECK_M_FROM_DCACHE 4'd5
`define L15_NOC3_GEN_WRITEBACK_IF_LRU_M_FROM_DCACHE 4'd6
`define L15_NOC3_GEN_ICACHE_INVAL_ACK 4'd7
`define L15_NOC3_GEN_WRITEBACK_IF_FLUSH_M_FROM_DCACHE 4'd8

`define L15_CPX_SOURCE_WIDTH 3
`define L15_CPX_SOURCE_BOGUS 3'd0
`define L15_CPX_SOURCE_DCACHE 3'd1
`define L15_CPX_SOURCE_NOC2_BUFFER 3'd2
`define L15_CPX_SOURCE_CONFIG_REGS 3'd3
`define L15_CPX_SOURCE_CSM 3'd4

`define L15_NOC1_SOURCE_WIDTH 2
`define L15_NOC1_SOURCE_PCX_64B 2'd1
`define L15_NOC1_SOURCE_PCX_128B 2'd2

`define L15_DCACHE_SOURCE_WIDTH 3
`define L15_DCACHE_SOURCE_MSHR 3'd1
`define L15_DCACHE_SOURCE_NOC2 3'd2
`define L15_DCACHE_SOURCE_NOC2_AND_MSHR 3'd3
`define L15_DCACHE_SOURCE_PCX_DIAG 3'd4

// L2 shared states


// `define L15_NOC2_ACK_STATE_WIDTH 2
// `define L15_NOC2_ACK_STATE_S 2'd1
// `define L15_NOC2_ACK_STATE_E 2'd2
// `define L15_NOC2_ACK_STATE_M 2'd3

// `define L15_NOC1_REQTYPE_WIDTH `MSG_TYPE_WIDTH
// `define L15_NOC1_REQTYPE_WRITEBACK_GUARD `MSG_TYPE_WBGUARD_REQ
// `define L15_NOC1_REQTYPE_LD_REQUEST `MSG_TYPE_LOAD_REQ
// `define L15_NOC1_REQTYPE_LD_PREFETCH_REQUEST `MSG_TYPE_PREFETCH_REQ
// `define L15_NOC1_REQTYPE_LD_NC_REQUEST `MSG_TYPE_NC_LOAD_REQ
// `define L15_NOC1_REQTYPE_IFILL_REQUEST `MSG_TYPE_LOAD_REQ
// // `define L15_NOC1_REQTYPE_WRITETHROUGH_REQUEST 6'd4
// `define L15_NOC1_REQTYPE_ST_REQUEST `MSG_TYPE_STORE_REQ
// `define L15_NOC1_REQTYPE_BLK_ST_REQUEST `MSG_TYPE_BLK_STORE_REQ
// `define L15_NOC1_REQTYPE_BLK_ST_INIT_REQUEST `MSG_TYPE_BLKINIT_STORE_REQ
// // `define L15_NOC1_REQTYPE__REQUEST
// // `define L15_NOC1_REQTYPE__REQUEST
// // `define L15_NOC1_REQTYPE_ST_UPGRADE_REQUEST 6
// // `define L15_NOC1_REQTYPE_ST_FILL_REQUEST 6'd6
// `define L15_NOC1_REQTYPE_CAS_REQUEST `MSG_TYPE_CAS_REQ
// `define L15_NOC1_REQTYPE_SWAP_REQUEST `MSG_TYPE_SWAP_REQ

// `define L15_NOC3_REQTYPE_WIDTH `MSG_TYPE_WIDTH
// `define L15_NOC3_REQTYPE_WRITEBACK `MSG_TYPE_WB_REQ
// `define L15_NOC3_REQTYPE_NO_DATA_FWD_ACK `MSG_TYPE_NODATA_ACK
// `define L15_NOC3_REQTYPE_DATA_FWD_ACK `MSG_TYPE_DATA_ACK

// `define L2_REQTYPE_WIDTH `MSG_TYPE_WIDTH
// `define L2_REQTYPE_INVALIDATE 6'd1
// `define L2_REQTYPE_DOWNGRADE 6'd2
// `define L2_REQTYPE_ACKDT_LD_NC 6'd3
// `define L2_REQTYPE_ACKDT_IFILL 6'd4
// `define L2_REQTYPE_ACKDT_LD 6'd5
// `define L2_REQTYPE_ACKDT_ST_IM 6'd6
// `define L2_REQTYPE_ACKDT_ST_SM 6'd7
// `define L2_REQTYPE_ACK_WRITETHROUGH 6'd8
// `define L2_REQTYPE_ACK_ATOMIC 6'd9

`define L15_NOC1_REQTYPE_WIDTH 5
`define L15_NOC1_REQTYPE_WRITEBACK_GUARD 5'd1
`define L15_NOC1_REQTYPE_LD_REQUEST 5'd2
`define L15_NOC1_REQTYPE_IFILL_REQUEST 5'd3
`define L15_NOC1_REQTYPE_WRITETHROUGH_REQUEST 5'd4
`define L15_NOC1_REQTYPE_ST_UPGRADE_REQUEST 5'd5
`define L15_NOC1_REQTYPE_ST_FILL_REQUEST 5'd6
`define L15_NOC1_REQTYPE_CAS_REQUEST 5'd7
`define L15_NOC1_REQTYPE_SWAP_REQUEST 5'd8
`define L15_NOC1_REQTYPE_INTERRUPT_FWD 5'd9
`define L15_NOC1_REQTYPE_AMO_ADD_REQUEST 5'd10
`define L15_NOC1_REQTYPE_AMO_AND_REQUEST 5'd11
`define L15_NOC1_REQTYPE_AMO_OR_REQUEST 5'd12
`define L15_NOC1_REQTYPE_AMO_XOR_REQUEST 5'd13
`define L15_NOC1_REQTYPE_AMO_MAX_REQUEST 5'd14
`define L15_NOC1_REQTYPE_AMO_MAXU_REQUEST 5'd15
`define L15_NOC1_REQTYPE_AMO_MIN_REQUEST 5'd16
`define L15_NOC1_REQTYPE_AMO_MINU_REQUEST 5'd17

`define L15_NOC3_REQTYPE_WIDTH 3
`define L15_NOC3_REQTYPE_WRITEBACK 3'd1
`define L15_NOC3_REQTYPE_INVAL_ACK 3'd2
`define L15_NOC3_REQTYPE_DOWNGRADE_ACK 3'd3
`define L15_NOC3_REQTYPE_ICACHE_INVAL_ACK 3'd4

`define L2_REQTYPE_WIDTH 5
`define L2_REQTYPE_INVALIDATE 5'd1
`define L2_REQTYPE_DOWNGRADE 5'd2
`define L2_REQTYPE_ACKDT_LD_NC 5'd3
`define L2_REQTYPE_ACKDT_IFILL 5'd4
`define L2_REQTYPE_ACKDT_LD 5'd5
`define L2_REQTYPE_ACKDT_ST_IM 5'd6
`define L2_REQTYPE_ACKDT_ST_SM 5'd7
`define L2_REQTYPE_ACK_WRITETHROUGH 5'd8
`define L2_REQTYPE_ACK_ATOMIC 5'd9

// NOC1 ENCODER
`define NOC1_FLIT_STATE_WIDTH 4
`define NOC1_REQ_HEADER_1 4'd0
`define NOC1_REQ_HEADER_2 4'd1
`define NOC1_REQ_HEADER_3 4'd2
`define NOC1_REQ_DATA_1 4'd3
`define NOC1_REQ_DATA_2 4'd4

`define L15_NOC1ENCODER_SOURCE_WIDTH 1
`define L15_NOC1ENCODER_SOURCE_L15 1'b0
`define L15_NOC1ENCODER_SOURCE_CSM 1'b1

// NOC3 ENCODER
`define NOC3_FLIT_STATE_WIDTH 4
`define NOC3_REQ_HEADER_1 4'd0
`define NOC3_REQ_HEADER_2 4'd1
`define NOC3_REQ_HEADER_3 4'd2
`define NOC3_REQ_DATA_1 4'd3
`define NOC3_REQ_DATA_2 4'd4
`define NOC3_RES_HEADER_1 4'd0
`define NOC3_RES_DATA_1 4'd1
`define NOC3_RES_DATA_2 4'd2

// NOC2 BUFFER
`define NOC2_STATE_WIDTH 2
`define NOC2_STATE_IDLE 2'd0
`define NOC2_STATE_RECEIVING 2'd1
`define NOC2_STATE_WAITING_ACK 2'd2

// DMBR
// put this here for now, should be moved to a more appropriate location
`define DMBR_TAG_WIDTH 4

// NOC1 CREDIT MANAGEMENT
// becareful, the noc1buffer module assumes these are power of two
// also, please change the corresponding pyv value in noc1buffer.v.pyv
`define NOC1_BUFFER_NUM_SLOTS 8
`define NOC1_BUFFER_NUM_SLOTS_LOG 3
`define NOC1_BUFFER_NUM_DATA_SLOTS 2
`define NOC1_BUFFER_NUM_DATA_SLOTS_LOG 1

`define NOC1_BUFFER_ACK_DATA_WIDTH 2
`define NOC1_BUFFER_ACK_DATA_16B 2'd2
`define NOC1_BUFFER_ACK_DATA_8B 2'd1

`define L15_NOC1BUFFER_REQTYPE_LO 0
`define L15_NOC1BUFFER_REQTYPE_HI `L15_NOC1BUFFER_REQTYPE_LO + `L15_NOC1_REQTYPE_WIDTH - 1
`define L15_NOC1BUFFER_MSHRID_LO  `L15_NOC1BUFFER_REQTYPE_HI + 1
`define L15_NOC1BUFFER_MSHRID_HI  `L15_NOC1BUFFER_MSHRID_LO + `L15_MSHR_ID_WIDTH - 1
`define L15_NOC1BUFFER_THREADID_LO  `L15_NOC1BUFFER_MSHRID_HI + 1
`define L15_NOC1BUFFER_THREADID_HI  `L15_NOC1BUFFER_THREADID_LO + `L15_THREADID_WIDTH - 1
`define L15_NOC1BUFFER_ADDRESS_LO  `L15_NOC1BUFFER_THREADID_HI + 1
`define L15_NOC1BUFFER_ADDRESS_HI  `L15_NOC1BUFFER_ADDRESS_LO + 40 - 1
`define L15_NOC1BUFFER_NON_CACHEABLE_LO  `L15_NOC1BUFFER_ADDRESS_HI + 1
`define L15_NOC1BUFFER_NON_CACHEABLE_HI  `L15_NOC1BUFFER_NON_CACHEABLE_LO + 1 - 1
`define L15_NOC1BUFFER_SIZE_LO  `L15_NOC1BUFFER_NON_CACHEABLE_HI + 1
`define L15_NOC1BUFFER_SIZE_HI  `L15_NOC1BUFFER_SIZE_LO + `PCX_SIZE_WIDTH - 1
`define L15_NOC1BUFFER_PREFETCH_LO  `L15_NOC1BUFFER_SIZE_HI + 1
`define L15_NOC1BUFFER_PREFETCH_HI  `L15_NOC1BUFFER_PREFETCH_LO + 1 - 1
// `define L15_NOC1BUFFER_BLKSTORE_LO  `L15_NOC1BUFFER_PREFETCH_HI + 1
// `define L15_NOC1BUFFER_BLKSTORE_HI  `L15_NOC1BUFFER_BLKSTORE_LO + 1 - 1
// `define L15_NOC1BUFFER_BLKINITSTORE_LO  `L15_NOC1BUFFER_BLKSTORE_HI + 1
// `define L15_NOC1BUFFER_BLKINITSTORE_HI  `L15_NOC1BUFFER_BLKINITSTORE_LO + 1 - 1
// `define L15_NOC1BUFFER_DATA_INDEX_LO  `L15_NOC1BUFFER_BLKINITSTORE_HI + 1
`define L15_NOC1BUFFER_DATA_INDEX_LO  `L15_NOC1BUFFER_PREFETCH_HI + 1
`define L15_NOC1BUFFER_DATA_INDEX_HI  `L15_NOC1BUFFER_DATA_INDEX_LO + 1 - 1
`define L15_NOC1BUFFER_CSM_TICKET_LO  `L15_NOC1BUFFER_DATA_INDEX_HI + 1
`define L15_NOC1BUFFER_CSM_TICKET_HI  `L15_NOC1BUFFER_CSM_TICKET_LO + `L15_CSM_NUM_TICKETS_LOG2 - 1
`define L15_NOC1BUFFER_HOMEID_LO  `L15_NOC1BUFFER_CSM_TICKET_HI + 1
`define L15_NOC1BUFFER_HOMEID_HI  `L15_NOC1BUFFER_HOMEID_LO + `PACKET_HOME_ID_WIDTH - 1
`define L15_NOC1BUFFER_HOMEID_VAL_LO  `L15_NOC1BUFFER_HOMEID_HI + 1
`define L15_NOC1BUFFER_HOMEID_VAL_HI  `L15_NOC1BUFFER_HOMEID_VAL_LO + 1 - 1
`define L15_NOC1BUFFER_CSM_SDID_LO  `L15_NOC1BUFFER_HOMEID_VAL_HI + 1
`define L15_NOC1BUFFER_CSM_SDID_HI  `L15_NOC1BUFFER_CSM_SDID_LO + `MSG_SDID_WIDTH - 1
`define L15_NOC1BUFFER_CSM_LSID_LO  `L15_NOC1BUFFER_CSM_SDID_HI + 1
`define L15_NOC1BUFFER_CSM_LSID_HI  `L15_NOC1BUFFER_CSM_LSID_LO + `MSG_LSID_WIDTH - 1

`define L15_COMMAND_BUFFER_LEN `L15_NOC1BUFFER_CSM_LSID_HI + 1

`define L15_NOC1BUFFER_REQTYPE `L15_NOC1BUFFER_REQTYPE_HI:`L15_NOC1BUFFER_REQTYPE_LO
`define L15_NOC1BUFFER_MSHRID  `L15_NOC1BUFFER_MSHRID_HI:`L15_NOC1BUFFER_MSHRID_LO
`define L15_NOC1BUFFER_THREADID  `L15_NOC1BUFFER_THREADID_HI:`L15_NOC1BUFFER_THREADID_LO
`define L15_NOC1BUFFER_ADDRESS  `L15_NOC1BUFFER_ADDRESS_HI:`L15_NOC1BUFFER_ADDRESS_LO
`define L15_NOC1BUFFER_NON_CACHEABLE  `L15_NOC1BUFFER_NON_CACHEABLE_HI:`L15_NOC1BUFFER_NON_CACHEABLE_LO
`define L15_NOC1BUFFER_SIZE  `L15_NOC1BUFFER_SIZE_HI:`L15_NOC1BUFFER_SIZE_LO
`define L15_NOC1BUFFER_PREFETCH  `L15_NOC1BUFFER_PREFETCH_HI:`L15_NOC1BUFFER_PREFETCH_LO
`define L15_NOC1BUFFER_BLKSTORE  `L15_NOC1BUFFER_BLKSTORE_HI:`L15_NOC1BUFFER_BLKSTORE_LO
`define L15_NOC1BUFFER_BLKINITSTORE  `L15_NOC1BUFFER_BLKINITSTORE_HI:`L15_NOC1BUFFER_BLKINITSTORE_LO
`define L15_NOC1BUFFER_DATA_INDEX  `L15_NOC1BUFFER_DATA_INDEX_HI:`L15_NOC1BUFFER_DATA_INDEX_LO
`define L15_NOC1BUFFER_CSM_TICKET  `L15_NOC1BUFFER_CSM_TICKET_HI:`L15_NOC1BUFFER_CSM_TICKET_LO
`define L15_NOC1BUFFER_HOMEID  `L15_NOC1BUFFER_HOMEID_HI:`L15_NOC1BUFFER_HOMEID_LO
`define L15_NOC1BUFFER_HOMEID_VAL  `L15_NOC1BUFFER_HOMEID_VAL_HI:`L15_NOC1BUFFER_HOMEID_VAL_LO
`define L15_NOC1BUFFER_CSM_SDID  `L15_NOC1BUFFER_CSM_SDID_HI:`L15_NOC1BUFFER_CSM_SDID_LO
`define L15_NOC1BUFFER_CSM_LSID  `L15_NOC1BUFFER_CSM_LSID_HI:`L15_NOC1BUFFER_CSM_LSID_LO

`define L15_INT_VEC_DIS 40'h9800000800
// `define L15_CPUID_ADDRESS 40'h9800000900


`define L15_HMT_OP_WIDTH 1
`define L15_HMT_OP_WRITE 1'd1


////////////////
// CSM
////////////////
`define L15_CSM_NUM_TICKETS 8
`define L15_CSM_NUM_TICKETS_LOG2 3

// Tri: save space on l15 sram
`define L15_CSM_GHID_CHIPID_WIDTH 14
`define L15_CSM_GHID_XPOS_WIDTH 8
`define L15_CSM_GHID_YPOS_WIDTH 8
`define L15_CSM_GHID_WIDTH `L15_CSM_GHID_CHIPID_WIDTH + `L15_CSM_GHID_XPOS_WIDTH + `L15_CSM_GHID_YPOS_WIDTH
`define L15_CSM_GHID_CHIP_MASK `L15_CSM_GHID_WIDTH - 1 -:  `L15_CSM_GHID_CHIPID_WIDTH
`define L15_CSM_GHID_XPOS_MASK `L15_CSM_GHID_XPOS_WIDTH + `L15_CSM_GHID_YPOS_WIDTH - 1 -: `L15_CSM_GHID_XPOS_WIDTH
`define L15_CSM_GHID_YPOS_MASK `L15_CSM_GHID_YPOS_WIDTH - 1 -: `L15_CSM_GHID_YPOS_WIDTH


`define L15_CSM_OP_WIDTH 4
`define L15_CSM_OP_READ_GHID 4'd1
`define L15_CSM_OP_READ_GHID_IF_TAGCHECK_SI 4'd2
`define L15_CSM_OP_HMC_FILL 4'd3
`define L15_CSM_OP_HMC_DIAG_STORE 4'd4
`define L15_CSM_OP_HMC_DIAG_LOAD 4'd5
`define L15_CSM_OP_READ_GHID_IF_TAGCHECK_MISS 4'd6
`define L15_CSM_OP_HMC_FLUSH 4'd7
`define L15_CSM_OP_EVICT_IF_LRU_M 4'd8
`define L15_CSM_OP_EVICT_IF_FLUSH_M 4'd9
`define L15_CSM_OP_EVICT_IF_M 4'd10


//HMC array

`define L15_HMC_ENTRIES          16
`define L15_HMC_INDEX_WIDTH      4
`define L15_HMC_ADDR_WIDTH       16
`define L15_HMC_TAG_WIDTH        14
`define L15_HMC_OFFSET_WIDTH     2
`define L15_HMC_DATA_IN_WIDTH    128
`define L15_HMC_DATA_OUT_WIDTH   30
`define L15_HMC_VALID_WIDTH      4
`define L15_HMC_DATA_WIDTH       120
`define L15_HMC_DATA_NUM         4

`define L15_HMC_ADDR_TAG         15:2
`define L15_HMC_ADDR_OFFSET      1:0
`define L15_HMC_ADDR_INDEX       5:2
`define L15_HMC_ADDR_SDID        15:6
`define L15_HMC_ADDR_LSID        5:0


`define L15_HMC_ARRAY_WIDTH      138

`define L15_HMC_TAG              137:124
`define L15_HMC_VALID            123:120
`define L15_HMC_DATA             119:0
`define L15_HMC_SDID             137:128

`define L15_HMC_DATA_CHIPID      29:16
`define L15_HMC_DATA_X           15:8
`define L15_HMC_DATA_Y           7:0

`define L15_HMT_BASE_ADDR_WIDTH  22

//Special addresses for HMC
`define L15_HMC_ADDR_OP_WIDTH            2
`define L15_HMC_ADDR_OP                  31:30
//`define L15_ADDR_TYPE_TAG_ACCESS     8'hb4 // later
//`define L15_ADDR_TYPE_STATE_ACCESS   8'hb6 // later
//`define L15_ADDR_TYPE_DIR_ACCESS     8'hb1 // later
//`define L15_ADDR_TYPE_CTRL_REG       8'hb9
//`define L15_ADDR_TYPE_DIS_FLUSH      8'hbc, 8'hbd, 8'hbe, 8'hbf
// `define L15_ADDR_TYPE_HMT_BASE_REG      8'hb7


`define L15_ADDR_TYPE_WIDTH          8
`define L15_ADDR_TYPE                39:32

`define L15_ADDR_TYPE_DATA_ACCESS       8'hb0
`define L15_ADDR_TYPE_HMC_ACCESS        8'hb2 // todo
`define L15_ADDR_TYPE_LINE_FLUSH        8'hb3
`define L15_ADDR_TYPE_HMC_FLUSH         8'hb5 // todo
`define L15_ADDR_TYPE_CONFIG_REGS       8'hba

`define L15_HOMEID_SRC_WIDTH            2
`define L15_HOMEID_SRC_CSM_MODULE       2'd1
`define L15_HOMEID_SRC_NOC2_SOURCE      2'd2
`define L15_HOMEID_SRC_HMT              2'd3

`endif

