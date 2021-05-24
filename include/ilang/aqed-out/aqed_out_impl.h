/// \file Header for generating information to support
/// AQED --- the implementation, not to be exposed
// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_AQED_OUT_AQED_OUT_IMPL_H__
#define ILANG_AQED_OUT_AQED_OUT_IMPL_H__

#include "nlohmann/json.hpp"

#include <ilang/aqed-out/aqed_out.h>
#include <ilang/aqed-out/aqed_vlog_out.h>
#include <ilang/verilog-in/verilog_analysis_wrapper.h>
#include <ilang/vtarget-out/supplementary_info.h>
#include <ilang/vtarget-out/var_extract.h>
#include <ilang/vtarget-out/vtarget_gen.h>


namespace ilang {


/// \brief the base class for info generator
/// will use a lot of other headers like
/// the verilog parser
class AQedInfoGeneratorImpl : public AQedInfoGenerator {
public:
  /// Type of record of extra info of a signal
  using ex_info_t = VlgVerifTgtGenBase::ex_info_t;
protected:
  /// The pointer to the instruction that is going to export
  const InstrLvlAbsCnstPtr& _ila_ptr;
  /// implementation top module name
  const std::string _vlg_impl_top_name;
  /// The name of verilog top module instance in the wrapper
  std::string _vlg_mod_inst_name;
  /// The name of ila-verilog top module instance in the wrapper
  std::string _ila_mod_inst_name;
  /// A pointer to create verilog analyzer
  VerilogInfo* vlg_info_ptr; // in case we want to share it
  /// store the vmap info
  nlohmann::json rf_vmap;
  /// store the condition
  nlohmann::json rf_cond;
  /// The supplementary information
  VlgTgtSupplementaryInfo supplementary_info;
  /// Var extractor
  VarExtractor _vext;
  /// record all the referred vlg names, so you can add (*keep*) if needed
  std::map<std::string, ex_info_t> _all_referred_vlg_names;
  /// in case we reference out variables
  /// vlgname, mod input name, width 
  std::vector<std::tuple<std::string, std::string, unsigned>> outer_var_reference;

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  AQedInfoGeneratorImpl(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions,
    const InstrLvlAbsCnstPtr& ila_ptr
  );
  // --------------------- DESTRUCTOR ---------------------------- //
  virtual ~AQedInfoGeneratorImpl();
  /// Return true if it is in bad state
  bool in_bad_state(void) const { return _bad_state; }
  /// Export the top-level io in  a file
  virtual void ExportVerilogTopLevelIOInfo(const std::string& fname) override;
  /// Export the decode function and etc
  virtual void ExportInstructionAndDecode(const std::string& filename) override;
  /// Export the signal references
  virtual void ExportExtraSignalReferenced(const std::string& fname) override;

protected:
  /// If it is bad state, return true and display a message
  bool bad_state_return(void);
  /// load json from a file name to the given j
  void load_json(const std::string& fname, nlohmann::json& j);
  /// Get instance name from rfmap
  void set_module_instantiation_name();
  // To check if we should precede
  std::string
  CheckNames(
    const VarExtractor::token& t, 
    const std::set<std::string>& ns,
    bool& has_ila_input_state_in_ns, bool& has_ila_input_state_outof_ns );
  /// To replace a string of expression
  std::string ModifyCondExprAndRecordVlgName(const VarExtractor::token& t,
    const std::set<std::string>& top_level_vlg_input_names);
  /// Add wires to vlg module
  void RegisterExtraVlgReferenceWire(VerilogGeneratorBase& vlg_gen);

private:
  /// If it is in a bad state
  bool _bad_state;

}; // // 

}; // namespace ilang

#endif // ILANG_AQED_OUT_AQED_OUT_IMPL_H__