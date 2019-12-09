/// \file Source for Verilog Verification Supplementary Information
/// this is useful to provide our tool information that it cannot
/// or may not be able to figure out itself

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/supplementary_info.h>

namespace ilang {

VlgTgtSupplementaryInfo::VlgTgtSupplementaryInfo() {}

void VlgTgtSupplementaryInfo::FromJson(nlohmann::json& vmap) {
  if (!IN("annotation", vmap))
    return;
  const auto& supplementary_info = vmap["annotation"];
  if (!supplementary_info.is_object()) {
    ILA_ERROR << "Unable to parse `annotation` field, expect a map.";
    return;
  }
  if (IN("width", supplementary_info) &&
      supplementary_info["width"].is_object()) {
    for (auto&& nw : supplementary_info["width"].items()) {
      width_info.insert(std::make_pair(nw.key(), nw.value().get<int>()));
    }
  }

  if (IN("memory-ports", supplementary_info) &&
      supplementary_info["memory-ports"].is_object()) {
    std::set<std::string> ports = {"ren",   "wen",   "raddr",
                                   "waddr", "rdata", "wdata"};
    for (auto&& p : supplementary_info["memory-ports"].items()) {
      std::string port = p.key();
      auto pos = port.find('.');

      ILA_ERROR_IF(pos == port.npos)
          << "memory-ports should follow NAME.PORT format";
      if (pos == port.npos)
        continue;

      if (!p.value().is_string()) {
        ILA_ERROR << "memory-ports's must be string->string map";
        continue;
      }

      auto port_expr = p.value().get<std::string>();
      auto mem_name = port.substr(0, pos);
      auto port_name = port.substr(pos + 1);
      if (!IN(port_name, ports)) {
        ILA_ERROR << "port name : " << port_name
                  << " should be one of ren/wen/raddr/waddr/rdata/wdata";
        continue;
      }
      memory_ports[mem_name].insert(std::make_pair(port_name, port_expr));
    }
  }

  if (IN("memory", supplementary_info) &&
      supplementary_info["memory"].is_object()) {
    for (auto&& nw : supplementary_info["memory"].items()) {
      std::string memory_export_directive = nw.value().get<std::string>();
      memory_export_type directive = memory_export_type_external;
      if (memory_export_directive == "internal")
        directive = memory_export_type_internal;
      else if (memory_export_directive == "external")
        directive = memory_export_type_external;
      else
        ILA_ERROR << "Unsupported memory export directive:"
                  << memory_export_directive << ", expect internal/external";
      memory_export.insert(std::make_pair(nw.key(), directive));
    }
  }

  // reset sequence annotation
  if (IN("reset", supplementary_info) &&
      supplementary_info["reset"].is_object()) {
    if (IN("cycle", supplementary_info["reset"])) {
      if (supplementary_info["reset"]["cycle"].is_number_unsigned()) {
        unsigned cycle = supplementary_info["reset"]["cycle"].get<unsigned>();
        ILA_ERROR_IF(cycle == 0) << "reset cycle must >= 1";
        cosa_yosys_reset_config.reset_cycles = cycle;
      } else
        ILA_ERROR
            << "`cycle` field in `reset` annotation must be unsigned integer";
    }
    if (IN("no-reset-after", supplementary_info["reset"])) {
      if (supplementary_info["reset"]["no-reset-after"].is_boolean()) {
        cosa_yosys_reset_config.no_reset_after_starting_state =
            supplementary_info["reset"]["no-reset-after"].get<bool>();
      } else
        ILA_ERROR
            << "`no-reset-after` field in `reset` annotation must be boolean";
    }
    ILA_ERROR_IF(IN("reset-state", supplementary_info["reset"]))
        << "reset-state is not implemented yet.";
    ILA_ERROR_IF(IN("reset-sequence", supplementary_info["reset"]))
        << "reset-sequence is not implemented yet.";
  }

} // VlgTgtSupplementaryInfo

}; // namespace ilang
