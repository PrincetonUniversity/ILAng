/// \file Header for Verilog Verification Supplementary Information
/// this is useful to provide our tool information that it cannot
/// or may not be able to figure out itself


#ifndef SUPPLEMENTARY_INFO_H__
#define SUPPLEMENTARY_INFO_H__

#include "nlohmann/json.hpp"

#include <map>
#include <string>

namespace ilang {

/// \brief the class to hold supplementary information
struct VlgTgtSupplementaryInfo {
  //  ----------------------- MEMBERS  ------------------------ //
  /// the width info
  std::map<std::string, int>  width_info;
  /// how to treat a memory
  typedef enum memory_export_type_t {INTERNAL, EXTERNAL} memory_export_type;
  /// the map of memory
  std::map<std::string, memory_export_type> memory_export;
  
  //  ----------------------- METHODS  ------------------------ //
  /// Constructor - default
  VlgTgtSupplementaryInfo();
  /// from Json 
  void FromJson(nlohmann::json & vmap);
}; // struct VlgTgtSupplementaryInfo

}; // namespace ilang

#endif // SUPPLEMENTARY_INFO_H__
