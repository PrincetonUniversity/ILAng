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

  //  ----------------------- TYPE  ------------------------ //
  struct reset_config_t {
    /// whether to enforce no reset constraint
    bool no_reset_after_starting_state;
    /// how many cycles should reset signal holds
    unsigned reset_cycles;
    /// the reset sequence: list of (signal name -> value) map (not supported
    /// yet)
    // we anticipate in the reset sequence, you don't need a wide signal
    std::vector<std::map<std::string, unsigned>> reset_sequence;
    /// Future work: reset state: signame -> signal value (valid vlog expr) (not
    /// supported yet)
    std::map<std::string, std::string> reset_state;
    /// Constructor, set default parameters
    reset_config_t() : no_reset_after_starting_state(false), reset_cycles(1) {}
  }; // struct reset_config_t

  //  ----------------------- MEMBERS  ------------------------ //
  /// the width info
  std::map<std::string, int> width_info;
  /// how to treat a memory , the reason of using bool instead of enum is
  /// because I don't want the verilog-out part to include this file, so its
  /// type should be a generic type
  typedef bool memory_export_type;
#define memory_export_type_internal false
#define memory_export_type_external true
  /// the map of memory
  std::map<std::string, memory_export_type> memory_export;
  /// the port to keep : memory_name -> (port and its connector)
  std::map<std::string, std::map<std::string, std::string>> memory_ports;
  /// The reset annotation for CoSA & Yosys (Jasper should be fine...)
  reset_config_t cosa_yosys_reset_config;

  //  ----------------------- METHODS  ------------------------ //
  /// Constructor - default
  VlgTgtSupplementaryInfo();
  /// Parse annotations from Json
  void FromJson(nlohmann::json& vmap);
}; // struct VlgTgtSupplementaryInfo

}; // namespace ilang

#endif // SUPPLEMENTARY_INFO_H__
