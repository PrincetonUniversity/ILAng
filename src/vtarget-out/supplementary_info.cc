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
  if (not IN("annotation", vmap ) ) 
    return;
  const auto & supplementary_info = vmap["annotation"];
  if (not supplementary_info.is_object()) {
    ILA_ERROR << "Unable to parse `annotation` field, expect a map.";
    return;
  }
  if ( IN("width", supplementary_info) and supplementary_info["width"].is_object() ) {
    for (auto && nw : supplementary_info["width"].items()) {
      width_info.insert(std::make_pair(nw.key(),nw.value().get<int>()));
    }
  }
  if ( IN("memory", supplementary_info) and supplementary_info["memory"].is_object() ) {
    for (auto && nw : supplementary_info["memory"].items()) {
      std::string memory_export_directive = nw.value().get<std::string>();
      memory_export_type directive = memory_export_type_external;
      if (memory_export_directive == "internal")
        directive = memory_export_type_internal;
      else if (memory_export_directive == "external")
        directive = memory_export_type_external;
      else
        ILA_ERROR << "Unsupported memory export directive:" << memory_export_directive 
        << ", expect internal/external";
      memory_export.insert(std::make_pair(nw.key(),directive));
    }
  }
} // VlgTgtSupplementaryInfo

}; // namespace ilang

