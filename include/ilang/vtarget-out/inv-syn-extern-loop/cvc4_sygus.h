/// \file The header for invariant synthesis --- using the SyGuS method
// ---Hongce Zhang

#ifndef EXT_CVC4_SYGUS_H__
#define EXT_CVC4_SYGUS_H__

#include <ilang/vtarget-out/vtarget_gen.h>
#include <ilang/smt-inout/yosys_smt_parser.h>
#include <ilang/vtarget-out/inv-syn/sygus/sygus_dp.h>
#include <ilang/vtarget-out/inv-syn/sygus/sygus_chc.h>

namespace ilang {

class ExternalSygusTargetGen {
public:
  // -------------------- TYPES ------------------ //
  /// the type of additional width information
  typedef std::map<std::string,int> additional_width_info_t;
  /// the type of configuration
  using vtg_config_t = VlgVerifTgtGenBase::vtg_config_t;
  /// the correction type
  using correction_t = Cvc4SygusBase::correction_t;

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  ExternalSygusTargetGen(
    const std::string& output_path,
    const additional_width_info_t& width_info ,
    const vtg_config_t& vtg_config,
    TraceDataPoints * dp, // datapoint can be NULL if th configuration is transfer function
    const std::vector<std::string> & var_name_set,
    std::shared_ptr<smt::YosysSmtParser> design_smt_info,
    bool enumerate
    );

  /// the only function
  correction_t GenerateSygusSynthesisTarget(const std::string & script_name,
    const std::string & sygus_problem_name, const Cvc4Syntax & syntax);
  /// return the runnable script name
  const std::vector<std::string> & GetRunnableScriptName() const;

protected:
  /// the output path
  const std::string _output_path;
  /// additional width info, if we don't know from elsewhere
  const additional_width_info_t _width_info;
  /// the configurations
  const vtg_config_t _vtg_config;
  /// the datapoints : no need to copy
  TraceDataPoints * datapoints; // datapoint can be NULL if th configuration is transfer function
  /// the varnames
  const std::vector<std::string> var_names;
  /// the shared design information
  std::shared_ptr<smt::YosysSmtParser> design_smt_info;
  /// whether to force the tool to enumerate
  bool enumerate;
  /// runnable script
  std::vector<std::string> runnable_script_name;
  /// generate script -- no need to call separately
  void GenerateSygusScript(const std::string & script_name, 
    const std::string & sygus_problem_name);
}; // class ExternalSygusTargetGen

}; // namespace ilang

#endif // EXT_CVC4_SYGUS_H__
