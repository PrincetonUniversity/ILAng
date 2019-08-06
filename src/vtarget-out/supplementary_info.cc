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
  if (not IN("supplementary info", vmap ) ) 
    return;
  const auto & supplementary_info = vmap["supplementary info"];
  if (not supplementary_info.is_object()) {
    ILA_ERROR << "Unable to parse `supplementary info` field, expect a map.";
    return;
  }
  if ( IN("width-info", supplementary_info) and supplementary_info["width-info"].is_object() ) {
    for (auto && nw : supplementary_info["width-info"].items()) {
      width_info.insert(std::make_pair(nw.key(),nw.value().get<int>()));
    }
  }
  if ( IN("memory", supplementary_info) and supplementary_info["memory"].is_object() ) {
    for (auto && nw : supplementary_info["memory"].items()) {
      std::string memory_export_directive = nw.value().get<std::string>();
      memory_export_type directive = memory_export_type_t::EXTERNAL;
      if (memory_export_directive == "internal")
        directive = memory_export_type_t::INTERNAL;
      else if (memory_export_directive == "external")
        directive = memory_export_type_t::EXTERNAL;
      else
        ILA_ERROR << "Unsupported memory export directive:" << memory_export_directive 
        << ", expect internal/external";
      width_info.insert(std::make_pair(nw.key(),directive));
    }
  }
} // VlgTgtSupplementaryInfo

}; // namespace ilang

