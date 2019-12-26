/// \file Header for generating abstract memory
// --- Hongce Zhang

#ifndef ILANG_VTARGET_OUT_ABS_MEM_H__
#define ILANG_VTARGET_OUT_ABS_MEM_H__

#include <map>
#include <set>
#include <string>
#include <tuple>
#include <vector>

#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/absmem.h>

namespace ilang {

/// \brief a struct to store abstract memory
struct VlgAbsMem {
  // ---------------------- TYPES --------------- //
  /// type of read port
  using rport_t = VerilogGeneratorBase::rport_t;
  /// type of write port
  using wport_t = VerilogGeneratorBase::wport_t;

  // ---------------------- MEMBERS --------------- //
  /// verilog read ports
  std::map<unsigned, rport_t> vlg_rports;
  /// verilog write ports
  std::map<unsigned, wport_t> vlg_wports;
  /// ila read ports
  std::map<unsigned, rport_t> ila_rports;
  /// ila write ports
  std::map<unsigned, wport_t> ila_wports;

  /// whether to abstract the memory read
  bool read_abstract;
  /// how many are considered to be concrete
  unsigned concrete_level;
  /// widths , 0 stands for unknown
  unsigned data_width;
  /// widths , 0 stands for unknown
  unsigned addr_width;
  /// which ila state it is mapped to
  std::string ila_map_name;
  /// the name in rfmap
  std::string mem_name;
  /// the assumptions it has
  std::vector<std::string> assumpts;

private:
  /// Whether the module is checked to be okay
  bool checked;
  /// track what kind of memory need to export, positive for w-abs, negative for
  /// r-w-abs
  static std::set<int> concrete_level_encountered;

public:
  // ------------------CONSTRUCTOR ----------- //
  /// do nothing
  VlgAbsMem();
  // ------------------ MEMBERS ------------- //
  /// SetAddrWidth, if already set, and different -> error
  void SetAddrWidth(unsigned w);
  /// SetDataWidth
  void SetDataWidth(unsigned w);
  /// Get the memeq signal name
  std::string MemEQSignalName() const;
  /// Get the memory module instantiation string, it will also
  /// add signals when necessary
  std::string
  GeneratingMemModuleSignalsInstantiation(VerilogGeneratorBase& gen,
                                          const std::string& endCond);
  /// Output the memory module to the stream
  static void OutputMemFile(std::ostream& os, bool avoid_issue_stage);
  /// Return true if there are abs mem used (strategy : ALL -> AUTO)
  static bool hasAbsMem();
  /// reset concrete_level (per-target).
  static void ClearAbsMemRecord();

}; // class VlgAbsMem

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_ABS_MEM_H__
