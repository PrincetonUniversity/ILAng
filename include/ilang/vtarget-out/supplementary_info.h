/// \file Header for Verilog Verification Supplementary Information
/// this is useful to provide our tool information that it cannot
/// or may not be able to figure out itself


#ifndef SUPPLEMENTARY_INFO_H__
#define SUPPLEMENTARY_INFO_H__

#include "nlohmann/json.hpp"

#include <map>
#include <set>
#include <string>

namespace ilang {

/// \brief the class to hold supplementary information
struct VlgTgtSupplementaryInfo {
  /// whether the configuration should overwrite the tool's
  bool overwrite;
  /// the width info
  std::map<std::string, int>  width_info;
  /// the port to keep : memory_name -> (port and its connector)
  std::map<std::string,std::map<std::string,std::string>> memory_ports;
  /// Constructor - default
  VlgTgtSupplementaryInfo();
  /// from Json 
  void FromJson(nlohmann::json & vmap);
}; // struct VlgTgtSupplementaryInfo

}; // namespace ilang

#endif // SUPPLEMENTARY_INFO_H__
