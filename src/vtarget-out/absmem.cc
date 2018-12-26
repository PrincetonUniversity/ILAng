/// \file Source for generating abstract memory
// --- Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/absmem.h>
#include <sstream>
#include <cmath>

namespace ilang {

unsigned mem_count = 0;
std::string get_m_inst_name() {
  return std::string("mi") + std::to_string (mem_count ++ );
}

// ---------------------- class VlgAbsMem ------------------------------- //
VlgAbsMem::VlgAbsMem() : concrete_level(1), data_width(0), addr_width(0), checked(false) {} 

/// SetAddrWidth
void VlgAbsMem::SetAddrWidth(unsigned w) {
  if(addr_width != 0 && addr_width != w) {
    ILA_ERROR << "Address width incompatible!";
    return;
  }
  addr_width = w;
}
/// SetDataWidth
void VlgAbsMem::SetDataWidth(unsigned w) {
  if(data_width != 0 && data_width != w) {
    ILA_ERROR << "Data width incompatible!";
    return;
  }
  data_width = w;
}


std::string VlgAbsMem::MemEQSignalName() const {
  return mem_name + "_EQ_";
}

// add signals and add instantiation statement;
std::string VlgAbsMem::GeneratingMemModuleSignalsInstantiation(VerilogGeneratorBase & gen) {
  // eq ? signal
  // if not given,  use a name it self
  if(addr_width == 0 || data_width == 0) {
    ILA_ERROR << "Unknown data width for absmem : "<< ila_map_name;
    return "";
  }
  if (vlg_rports.size() > 1 || vlg_wports.size() > 1 || ila_rports.size() > 1 || ila_wports.size() > 1) {
    ILA_ERROR << "Not implemented for support for abs mem w. more than 1 rport and 1 wport";
    return "";
  }

  std::stringstream ret;
  std::string moduleName;
  auto inst_name = get_m_inst_name();
  if(concrete_level == 1)
    moduleName = "absmem";
  else
    moduleName = "absmemD" + std::to_string(concrete_level);
  ret << moduleName << " #( \n    .AW(" << addr_width << "),\n";
  ret << "    .DW("<<data_width<<"),\n";
  ret << "    .TTS("<<(long long)(std::pow(2,addr_width))<<") )\n";
  ret << inst_name <<"(\n";
  ret << "    .clk(clk),\n";
  ret << "    .rst(rst),\n";
  ret << "    .equal(" << MemEQSignalName() << "),\n";
  ret << "    .compare(" << "__IEND__ || __ENDED__" << ")";

  gen.add_wire(MemEQSignalName(),1,true);

  // connect ports, create
  // treat unconnected wire?
#define CONNECT(e,s,w) do {             \
    if( (e).size() == 0 ) {             \
      (e) = base_name + (s);              \
      gen.add_wire((e), (w), true);}          \
    ret << ",\n    .vlg" s "("<< (e) <<")";\
    }while(false)

  for(auto && np : vlg_wports) {
    auto n = np.first;
    auto & p = np.second;
    auto base_name = "__MEM_" +
                VerilogGeneratorBase::sanitizeName(ila_map_name) +
                "_" + std::to_string(n);

    CONNECT(p.waddr, "_waddr", addr_width);
    CONNECT(p.wdata, "_wdata", data_width);
    CONNECT(p.wen,   "_wen",   1);
  }

  for(auto && np : vlg_rports) {
    auto n = np.first;
    auto & p = np.second;
    auto base_name = "__MEM_" +
                VerilogGeneratorBase::sanitizeName(ila_map_name) +
                "_" + std::to_string(n);

    CONNECT(p.raddr, "_raddr", addr_width);
    CONNECT(p.rdata, "_rdata", data_width);
    CONNECT(p.ren,   "_ren",   1);
  }

  // ila ports should have been fully connected
  // NOTE: in multi inst
  for(auto && np : ila_wports) {
    auto n = np.first;
    auto & p = np.second;

    ret << ",\n    .ila_waddr("<< p.waddr <<")";
    ret << ",\n    .ila_wdata("<< p.wdata <<")";
    ret << ",\n    .ila_wen  ("<< p.wen <<  ")";
  }
  if( ila_wports.size() == 0 )
    ret << ",\n    .ila_wen  ( 1'b0 )"; // make sure we don't do any writes if no write

  for(auto && np : ila_rports) {
    auto n = np.first;
    auto & p = np.second;

    ret << ",\n    .ila_raddr("<< p.raddr <<")";
    ret << ",\n    .ila_rdata("<< p.rdata <<")";
    ret << ",\n    .ila_ren  ("<< p.ren <<  ")";
  }

  ret << " );\n\n";

  checked = true;
  concrete_level_encountered.insert(concrete_level);

  return (ret.str());
}

void VlgAbsMem::OutputMemFile(std::ostream & os) {

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
  equal
  );


parameter AW = 16;
parameter DW = 8;
parameter TTS = 65536;

input clk;
input rst;

input  [AW-1:0] vlg_raddr;
output [DW-1:0] vlg_rdata,
input           vlg_ren;
input  [AW-1:0] vlg_waddr;
input  [DW-1:0] vlg_wdata;
input           vlg_wen;
input  [DW-1:0] vlg_r_rand_input;


input  [AW-1:0] ila_raddr;
output [DW-1:0] ila_rdata,
input           ila_ren;
input  [AW-1:0] ila_waddr;
input  [DW-1:0] ila_wdata;
input           ila_wen;
input  [DW-1:0] ila_r_rand_input;

input           compare;
output          equal;

reg [DW-1:0] mem[0:TTS-1];

wire vlg_ren_real;
wire vlg_wen_real;
wire ila_ren_real;
wire ila_wen_real;

assign vlg_ren_real = vlg_ren & ~compare;
assign vlg_wen_real = vlg_wen & ~compare;
assign ila_ren_real = ila_ren & ~compare;
assign ila_wen_real = ila_wen & ~compare;


assign vlg_rdata = vlg_ren_real ? 
                      vlg_m_e0 && vlg_m_a0 == vlg_raddr ? vlg_m_d0
                   : 
                      mem[vlg_raddr] : vlg_r_rand_input;

assign ila_rdata = ila_ren_real ?
                      ila_m_e0 && ila_m_a0 == ila_raddr ? ila_m_d0
                   :
                      mem[ila_raddr] : ila_r_rand_input;

reg          vlg_m_e0;
reg [AW-1:0] vlg_m_a0;
reg [DW-1:0] vlg_m_d0;


reg          ila_m_e0;
reg [AW-1:0] ila_m_a0;
reg [DW-1:0] ila_m_d0;

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

reg vlg_match_ila;
reg ila_match_vlg;

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

  for (auto && cl : concrete_level_encountered) {
    if (cl == 1 )
      os << d1model;
    else
      ILA_ERROR << "depth :" << cl << " abs mem model is not developed. Future work.";
  }
}

std::set  <int>  VlgAbsMem::concrete_level_encountered;

}; // namespace ilang
