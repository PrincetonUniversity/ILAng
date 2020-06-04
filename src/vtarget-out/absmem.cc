/// \file Source for generating abstract memory
// --- Hongce Zhang

#include <ilang/vtarget-out/absmem.h>

#include <cmath>
#include <sstream>

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

namespace ilang {

unsigned mem_count = 0;
std::string get_m_inst_name() {
  return std::string("mi") + std::to_string(mem_count++);
}

// ---------------------- class VlgAbsMem ------------------------------- //
VlgAbsMem::VlgAbsMem()
    : read_abstract(false), concrete_level(1), data_width(0), addr_width(0),
      checked(false) {}

/// SetAddrWidth
void VlgAbsMem::SetAddrWidth(unsigned w) {
  if (addr_width != 0 && addr_width != w) {
    ILA_ERROR << "Address width incompatible!";
    return;
  }
  addr_width = w;
}
/// SetDataWidth
void VlgAbsMem::SetDataWidth(unsigned w) {
  if (data_width != 0 && data_width != w) {
    ILA_ERROR << "Data width incompatible!";
    return;
  }
  data_width = w;
}

std::string VlgAbsMem::MemEQSignalName() const { return mem_name + "_EQ_"; }

// add signals and add instantiation statement;
std::string
VlgAbsMem::GeneratingMemModuleSignalsInstantiation(VerilogGeneratorBase& gen,
                                                   const std::string& endCond) {
  // eq ? signal
  // if not given,  use a name it self
  if (addr_width == 0 || data_width == 0) {
    ILA_ERROR << "Unknown addr/data width for absmem : " << ila_map_name;
    return "";
  }
  if (vlg_rports.size() > 1 || vlg_wports.size() > 1 || ila_rports.size() > 1 ||
      ila_wports.size() > 1) {
    ILA_ERROR << "Not implemented for support for abs mem w. more than 1 rport "
                 "and 1 wport";
    return "";
  }

  std::stringstream ret;
  std::string moduleName;
  auto inst_name = get_m_inst_name();
  if (concrete_level == 1)
    moduleName = "absmem";
  else
    moduleName = "absmemD" + std::to_string(concrete_level);
  if (read_abstract)
    moduleName += "_ra";
  ret << moduleName << " #( \n    .AW(" << addr_width << "),\n";
  if (read_abstract) {
    ret << "    .DW(" << data_width << ") )\n";
    // will not have TTS, because not used
    // and will create problem for jg
  } else {
    ret << "    .DW(" << data_width << "),\n";
    ret << "    .TTS(" << (long long)(std::pow(2, addr_width)) << ") )\n";
  }
  ret << inst_name << "(\n";
  ret << "    .clk(clk),\n";
  ret << "    .rst(rst),\n";

  auto vlg_rand_input_name = inst_name + "_vlg_r_rand_input";
  auto ila_rand_input_name = inst_name + "_ila_r_rand_input";
  auto read_assume_true = inst_name + "_read_assume_true";
  gen.add_input(vlg_rand_input_name, data_width);
  gen.add_input(ila_rand_input_name, data_width);
  gen.add_output(read_assume_true, 1);

  if (read_abstract)
    assumpts.push_back(read_assume_true + "==1'b1");

  ret << "    .vlg_r_rand_input( " << vlg_rand_input_name << "),\n";
  ret << "    .ila_r_rand_input( " << ila_rand_input_name << "),\n";
  ret << "    .equal(" << MemEQSignalName() << "),\n";
  ret << "    .issue( __ISSUE__ ),\n";
  if (read_abstract)
    ret << "    .read_assume_true(" << read_assume_true << "),\n";
  ret << "    .compare(" << endCond // "__IEND__ || __ENDED__"
      << ")";

  gen.add_wire(MemEQSignalName(), 1, true);
  if (ila_map_name == "")
    ILA_WARN_IF(ila_map_name == "")
        << "Empty mem abs name for (" << mem_name << ")";

    // connect ports, create
    // treat unconnected wire?
#define CONNECT(e, s, w, i)                                                    \
  do {                                                                         \
    std::string wn = (e);                                                      \
    if ((wn).size() == 0) {                                                    \
      (wn) = base_name + (s);                                                  \
      gen.add_wire((wn), (w), true);                                           \
      if (i)                                                                   \
        gen.add_input((wn), (w));                                              \
      else                                                                     \
        gen.add_output((wn), (w));                                             \
    }                                                                          \
    ret << ",\n    .vlg" s "(" << (wn) << ")";                                 \
  } while (false)

  for (auto&& np : vlg_wports) {
    auto n = np.first;
    auto& p = np.second;
    auto base_name = "__MEM_" +
                     VerilogGeneratorBase::sanitizeName(ila_map_name) + "_" +
                     std::to_string(n);

    CONNECT(p.waddr, "_waddr", addr_width, true);
    CONNECT(p.wdata, "_wdata", data_width, false);
    CONNECT(p.wen, "_wen", 1, true);
  }                             // the else case:
  if (vlg_wports.size() == 0) { // avoid write arbitrarily
    ret << ",\n    .vlg_wen(1'b0)";
    int n = 0;
    auto base_name = "__MEM_" +
                     VerilogGeneratorBase::sanitizeName(ila_map_name) + "_" +
                     std::to_string(n);
    CONNECT("", "_waddr", addr_width, true);
    CONNECT("", "_wdata", data_width, false);
  }

  for (auto&& np : vlg_rports) {
    auto n = np.first;
    auto& p = np.second;
    auto base_name = "__MEM_" +
                     VerilogGeneratorBase::sanitizeName(ila_map_name) + "_" +
                     std::to_string(n);

    CONNECT(p.raddr, "_raddr", addr_width, true);
    CONNECT(p.rdata, "_rdata", data_width, false);
    CONNECT(p.ren, "_ren", 1, true);
  } // else case
  if (vlg_rports.size() == 0) {
    ret << ",\n    .vlg_ren(1'b0)";
    int n = 0;
    auto base_name = "__MEM_" +
                     VerilogGeneratorBase::sanitizeName(ila_map_name) + "_" +
                     std::to_string(n);
    CONNECT("", "_raddr", addr_width, true);
    CONNECT("", "_rdata", data_width, false);
  }

  // ila ports should have been fully connected
  // NOTE: in multi inst
  for (auto&& np : ila_wports) {
    auto n = np.first;
    auto& p = np.second;
    auto base_name = "__IMEM_" +
                     VerilogGeneratorBase::sanitizeName(ila_map_name) + "_" +
                     std::to_string(n);

    ret << ",\n    .ila_waddr(" << base_name + "_waddr"
        << ")";
    ret << ",\n    .ila_wdata(" << base_name + "_wdata"
        << ")";
    ret << ",\n    .ila_wen  (" << base_name + "_wen"
        << ")";

    ILA_DLOG("VtargetGen.AbsMem")
        << ".ila_waddr(" << p.waddr << " or " << base_name + "_waddr"
        << ")";
    ILA_DLOG("VtargetGen.AbsMem")
        << ".ila_wdata(" << p.wdata << " or " << base_name + "_wdata"
        << ")";
    ILA_DLOG("VtargetGen.AbsMem")
        << ".ila_wen  (" << p.wen << " or " << base_name + "_wen"
        << ")";
  }
  if (ila_wports.size() == 0)
    ret << ",\n    .ila_wen  ( 1'b0 )"; // make sure we don't do any writes if
                                        // no write

  for (auto&& np : ila_rports) {
    auto n = np.first;
    auto& p = np.second;

    auto base_name = "__IMEM_" +
                     VerilogGeneratorBase::sanitizeName(ila_map_name) + "_" +
                     std::to_string(n);

    ret << ",\n    .ila_raddr(" << base_name + "_raddr"
        << ")";
    ret << ",\n    .ila_rdata(" << base_name + "_rdata"
        << ")";
    ret << ",\n    .ila_ren  (" << p.ren << ")"; // this is the start?
  }

  ret << " );\n\n";

  checked = true;
  // here negative means abstract its read
  concrete_level_encountered.insert(read_abstract ? -concrete_level
                                                  : concrete_level);

  return (ret.str());
}

bool VlgAbsMem::hasAbsMem() { return concrete_level_encountered.size() > 0; }

void VlgAbsMem::ClearAbsMemRecord() {
  mem_count = 0;
  concrete_level_encountered.clear();
}

// the parameters are :
// %%%AVOID_ISSUE%%%
//
//

std::string d1model = R"**##**(

// 1R 1W (x2) d=1 AW(V=I) DW(V=I) absmem
// only work for CoSA
// Hongce Zhang (hongcez@princeton.edu)

module absmem(
  clk,
  rst,
  vlg_raddr,
  vlg_rdata,
  vlg_ren,
  vlg_waddr,
  vlg_wdata,
  vlg_wen,

  vlg_r_rand_input,
  
  ila_raddr,
  ila_rdata,
  ila_ren,
  ila_waddr,
  ila_wdata,
  ila_wen,

  ila_r_rand_input,

  compare,
  equal,
  issue
  );


parameter AW = 16;
parameter DW = 8;
parameter TTS = 65536;

input clk;
input rst;

input  [AW-1:0] vlg_raddr;
output [DW-1:0] vlg_rdata;
input           vlg_ren;
input  [AW-1:0] vlg_waddr;
input  [DW-1:0] vlg_wdata;
input           vlg_wen;
input  [DW-1:0] vlg_r_rand_input;


input  [AW-1:0] ila_raddr;
output [DW-1:0] ila_rdata;
input           ila_ren;
input  [AW-1:0] ila_waddr;
input  [DW-1:0] ila_wdata;
input           ila_wen;
input  [DW-1:0] ila_r_rand_input;

input           compare;
output          equal;
input           issue;

(* keep *)  reg             start_and_on;
(* keep *)  reg [DW-1:0] mem[0:TTS-1];

wire vlg_ren_real;
wire vlg_wen_real;
wire ila_ren_real;
wire ila_wen_real;

(* keep *)  reg          vlg_m_e0;
(* keep *)  reg [AW-1:0] vlg_m_a0;
(* keep *)  reg [DW-1:0] vlg_m_d0;


(* keep *)  reg          ila_m_e0;
(* keep *)  reg [AW-1:0] ila_m_a0;
(* keep *)  reg [DW-1:0] ila_m_d0;

(* keep *)  reg vlg_match_ila;
(* keep *)  reg ila_match_vlg;

always @(posedge clk) begin
  if(rst)
    start_and_on <= 1'b%%%AVOID_ISSUE%%%;
  else if(issue)
    start_and_on <= 1'b1;
end

assign vlg_ren_real = vlg_ren & ~compare & start_and_on;
assign vlg_wen_real = vlg_wen & ~compare & start_and_on;
assign ila_ren_real = ila_ren & ~compare & start_and_on;
assign ila_wen_real = ila_wen & ~compare & start_and_on;


assign vlg_rdata = vlg_ren_real ? 
                      vlg_m_e0 && vlg_m_a0 == vlg_raddr ? vlg_m_d0
                   : 
                      mem[vlg_raddr] : vlg_r_rand_input;

assign ila_rdata = ila_ren_real ?
                      ila_m_e0 && ila_m_a0 == ila_raddr ? ila_m_d0
                   :
                      mem[ila_raddr] : ila_r_rand_input;

always @(posedge clk) begin 
  if( rst ) begin
    vlg_m_e0 <= 1'b0;
  end
  else begin 
    if(  vlg_m_e0 == 0 && vlg_wen_real) begin
      vlg_m_e0 <= 1'b1;
      vlg_m_a0 <= vlg_waddr;
      vlg_m_d0 <= vlg_wdata;
    end
  end
end

always @(posedge clk) begin 
  if( rst ) begin
    ila_m_e0 <= 1'b0;
  end
  else begin 
    if(  ila_m_e0 == 0 && ila_wen_real) begin
      ila_m_e0 <= 1'b1;
      ila_m_a0 <= ila_waddr;
      ila_m_d0 <= ila_wdata;
    end
  end
end

always @(*) begin
  vlg_match_ila = 0;
  if( vlg_m_e0 ) begin
    if(ila_m_e0 == 1 && ila_m_a0 == vlg_m_a0)
      vlg_match_ila = ila_m_d0 == vlg_m_d0;
    else if(vlg_m_d0 == mem[vlg_m_a0])
      vlg_match_ila = 1;
    else
      vlg_match_ila = 0;
  end
  else 
    vlg_match_ila = 1;
end

always @(*) begin
  ila_match_vlg = 0;
  if( ila_m_e0 ) begin
    if(vlg_m_e0 == 1 && ila_m_a0 == vlg_m_a0)
      ila_match_vlg = ila_m_d0 == vlg_m_d0;
    else if(ila_m_d0 == mem[ila_m_a0])
      ila_match_vlg = 1;
    else
      ila_match_vlg = 0;
  end
  else 
    ila_match_vlg = 1;
end

assign equal = compare && ila_match_vlg && vlg_match_ila;

endmodule

  )**##**";

std::string d1ra = R"**##**(

// 1R 1W (x2) d=1 AW(V=I) DW(V=I) absmem
// CoSA & Jasper
// --- ra : read abstraction (depth = 1)
//
// Hongce Zhang (hongcez@princeton.edu)

module absmem_ra(
  clk,
  rst,
  vlg_raddr,
  vlg_rdata,
  vlg_ren,
  vlg_waddr,
  vlg_wdata,
  vlg_wen,

  vlg_r_rand_input,
  
  ila_raddr,
  ila_rdata,
  ila_ren,
  ila_waddr,
  ila_wdata,
  ila_wen,

  ila_r_rand_input,

  compare,
  equal,
  issue,
  read_assume_true
  );


parameter AW = 16;
parameter DW = 8;
parameter TTS = 65536;

input clk;
input rst;

input  [AW-1:0] vlg_raddr;
output [DW-1:0] vlg_rdata;
input           vlg_ren;
input  [AW-1:0] vlg_waddr;
input  [DW-1:0] vlg_wdata;
input           vlg_wen;
input  [DW-1:0] vlg_r_rand_input;


input  [AW-1:0] ila_raddr;
output [DW-1:0] ila_rdata;
input           ila_ren;
input  [AW-1:0] ila_waddr;
input  [DW-1:0] ila_wdata;
input           ila_wen;
input  [DW-1:0] ila_r_rand_input;

input           compare;
output          equal;
input           issue;
(* keep *) output          read_assume_true;

(* keep *)  reg             start_and_on;

wire vlg_ren_real;
wire vlg_wen_real;
wire ila_ren_real;
wire ila_wen_real;

(* keep *)  reg          vlg_r_e0;
(* keep *)  reg [AW-1:0] vlg_r_a0;
(* keep *)  reg [DW-1:0] vlg_r_d0;


(* keep *)  reg          ila_r_e0;
(* keep *)  reg [AW-1:0] ila_r_a0;
(* keep *)  reg [DW-1:0] ila_r_d0;

(* keep *)  reg          vlg_m_e0;
(* keep *)  reg [AW-1:0] vlg_m_a0;
(* keep *)  reg [DW-1:0] vlg_m_d0;


(* keep *)  reg          ila_m_e0;
(* keep *)  reg [AW-1:0] ila_m_a0;
(* keep *)  reg [DW-1:0] ila_m_d0;

(* keep *)  reg vlg_match_ila;
(* keep *)  reg ila_match_vlg;

always @(posedge clk) begin
  if(rst)
    start_and_on <= 1'b%%%AVOID_ISSUE%%%;
  else if(issue)
    start_and_on <= 1'b1;
end

assign vlg_ren_real = vlg_ren & ~compare & start_and_on;
assign vlg_wen_real = vlg_wen & ~compare & start_and_on;
assign ila_ren_real = ila_ren & ~compare & start_and_on;
assign ila_wen_real = ila_wen & ~compare & start_and_on;


assign vlg_rdata = vlg_ren_real ? (
                      (vlg_m_e0 && vlg_m_a0 == vlg_raddr) ? vlg_m_d0
                   :  vlg_r_rand_input ) : vlg_r_rand_input;

assign ila_rdata = ila_ren_real ? (
                      (ila_m_e0 && ila_m_a0 == ila_raddr) ? ila_m_d0
                   : ila_r_rand_input) : ila_r_rand_input;

always @(posedge clk) begin 
  if( rst ) begin
    vlg_r_e0 <= 1'b0;
  end
  else begin 
    //if( vlg_ren_real && ( vlg_r_e0 == 0 || (vlg_r_e0 == 1 && vlg_r_a0 == vlg_raddr) ) ) begin
    if( vlg_ren_real && ( vlg_r_e0 == 0) ) begin
      vlg_r_e0 <= 1'b1;
      vlg_r_a0 <= vlg_raddr;
      vlg_r_d0 <= vlg_r_rand_input; // vlg_rdata;
    end
  end
end

always @(posedge clk) begin 
  if( rst ) begin
    ila_r_e0 <= 1'b0;
  end
  else begin 
    // if( ( ila_ren_real && ( ila_r_e0 == 0 || (ila_r_e0 == 1 && ila_r_a0 == ila_raddr ) ) ) )
    if( ila_ren_real && ( ila_r_e0 == 0) ) begin
      ila_r_e0 <= 1'b1;
      ila_r_a0 <= ila_raddr;
      ila_r_d0 <= ila_r_rand_input; // ila_rdata;
    end
    /*
    else if (  ila_wen_real && ila_r_e0 && ila_r_a0 == ila_waddr  ) begin
      ila_r_e0 <= ila_r_e0;
      ila_r_a0 <= ila_r_a0;
      ila_r_d0 <= ila_wdata;
    end*/
  end
end

// we only ensure that the initial read matches, not the read involve the new data (changed by write)
// if you change it, we guarantee nothing

assign read_assume_true = 
  (vlg_r_e0 && ila_r_e0 && vlg_r_a0 == ila_r_a0) == 0  || (vlg_r_d0 == ila_r_d0);

// ------------- WRITE LOGIC ---------------- //

always @(posedge clk) begin 
  if( rst ) begin
    vlg_m_e0 <= 1'b0;
  end
  else begin 
    if( vlg_wen_real && (  vlg_m_e0 == 0  || (vlg_m_e0 == 1'b1 && vlg_m_a0 == vlg_waddr) ) ) begin
      vlg_m_e0 <= 1'b1;
      vlg_m_a0 <= vlg_waddr;
      vlg_m_d0 <= vlg_wdata;
    end
  end
end

always @(posedge clk) begin 
  if( rst ) begin
    ila_m_e0 <= 1'b0;
  end
  else begin 
    if( ila_wen_real && ( ila_m_e0 == 0 || (ila_m_e0 == 1'b1 && ila_m_a0 == ila_waddr) ) ) begin
      ila_m_e0 <= 1'b1;
      ila_m_a0 <= ila_waddr;
      ila_m_d0 <= ila_wdata;
    end
  end
end


always @(*) begin
  vlg_match_ila = 0;
  if( vlg_m_e0 ) begin
    if(ila_m_e0 == 1 && ila_m_a0 == vlg_m_a0)
      vlg_match_ila = ila_m_d0 == vlg_m_d0;
    else if(ila_r_e0 == 1 && ila_r_a0 == vlg_m_a0)
      vlg_match_ila = ila_r_d0 == vlg_m_d0;
    //else if(vlg_m_d0 == mem[vlg_m_a0])
    //  vlg_match_ila = 1;
    //below is an over-approximation
    else
      vlg_match_ila = 0;
  end
  else 
    vlg_match_ila = 1;
end

always @(*) begin
  ila_match_vlg = 0;
  if( ila_m_e0 ) begin
    if(vlg_m_e0 == 1 && ila_m_a0 == vlg_m_a0)
      ila_match_vlg = ila_m_d0 == vlg_m_d0;
    else if(vlg_r_e0 == 1 && vlg_r_a0 == ila_m_a0)
      ila_match_vlg = ila_m_d0 == vlg_r_d0;
    //else if(ila_m_d0 == mem[ila_m_a0])
    //  ila_match_vlg = 1;
    else
      ila_match_vlg = 0;
  end
  else 
    ila_match_vlg = 1;
end

assign equal = compare && ila_match_vlg && vlg_match_ila;

endmodule


    )**##**";

void VlgAbsMem::OutputMemFile(std::ostream& os, bool avoid_issue_stage) {

  for (auto&& cl : concrete_level_encountered) {
    if (cl == 1)
      os << ReplaceAll(d1model, "%%%AVOID_ISSUE%%%",
                       avoid_issue_stage ? "1" : "0");
    else if (cl == -1)
      os << ReplaceAll(d1ra, "%%%AVOID_ISSUE%%%",
                       avoid_issue_stage ? "1" : "0");
    else
      ILA_ASSERT(false) << "depth :" << cl
                        << " abs mem model is not developed. Future work.";
  }
}

std::set<int> VlgAbsMem::concrete_level_encountered;

}; // namespace ilang
