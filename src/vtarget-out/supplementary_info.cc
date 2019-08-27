/// \file Source for Verilog Verification Supplementary Information
/// this is useful to provide our tool information that it cannot
/// or may not be able to figure out itself

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/supplementary_info.h>

namespace ilang {

VlgTgtSupplementaryInfo::VlgTgtSupplementaryInfo() {}

void VlgTgtSupplementaryInfo::FromJson(nlohmann::json & vmap) {
  if (not IN("supplementary-info", vmap ) ) 
    return;
  const auto & supplementary_info = vmap["supplementary-info"];
  if (not supplementary_info.is_object()) {
    ILA_ERROR << "Unable to parse `supplementary-info` field, expect a map.";
    return;
  }
  if ( IN("overwrite", supplementary_info) and supplementary_info["overwrite"].is_boolean() ) {
    overwrite = supplementary_info["overwrite"].get<bool>();
  } else
    overwrite = false;
  if ( IN("width-info", supplementary_info) and supplementary_info["width-info"].is_object() ) {
    for (auto && nw : supplementary_info["width-info"].items()) {
      width_info.insert(std::make_pair(nw.key(),nw.value().get<int>()));
    }
  }
  if ( IN("memory-ports", supplementary_info) and supplementary_info["memory-ports"].is_object() ) {
    std::set<std::string> ports = {"ren","wen", "raddr","waddr", "rdata","wdata"};
    for (auto && p : supplementary_info["memory-ports"].items()) {
      std::string port = p.key();
      auto pos = port.find('.');
      
      ILA_ERROR_IF (pos == port.npos) << "memory-ports should follow NAME.PORT format";
      if (pos == port.npos) continue;

      if (!p.value().is_string()) {
        ILA_ERROR << "memory-ports's must be string->string map";
        continue;
      }

      auto port_expr = p.value().get<std::string>();

      auto mem_name = port.substr(0,pos);
      auto port_name = port.substr(pos+1);
      if (not IN(port_name,ports)) {
        ILA_ERROR << "port name : " << port_name << " should be one of ren/wen/raddr/waddr/rdata/wdata";
        continue;
      }
      memory_ports[mem_name].insert(std::make_pair(port_name,port_expr));
    }
  }
} // VlgTgtSupplementaryInfo

}; // namespace ilang

