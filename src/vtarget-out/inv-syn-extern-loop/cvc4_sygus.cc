/// \file The source for invariant synthesis --- using the SyGuS method
// ---Hongce Zhang

#include <ilang/util/fs.h>
#include <ilang/vtarget-out/inv-syn-extern-loop/cvc4_sygus.h>

namespace ilang {


ExternalSygusTargetGen::ExternalSygusTargetGen(
  const std::string& output_path,
  const additional_width_info_t& width_info ,
  const vtg_config_t& vtg_config,
  TraceDataPoints * dp, // datapoint can be NULL if th configuration is transfer function
  const std::vector<std::string> & var_name_set,
  std::shared_ptr<smt::YosysSmtParser> _design_smt_info,
  bool _enumerate) :
    _output_path(output_path),
    _width_info(width_info), _vtg_config(vtg_config),
    datapoints(dp), var_names(var_name_set),
    design_smt_info(_design_smt_info), enumerate(_enumerate) { }


ExternalSygusTargetGen::correction_t ExternalSygusTargetGen::GenerateSygusSynthesisTarget(
  const std::string & script_name,
  const std::string & sygus_problem_name) {

  Cvc4SygusInputGenerator gen_sygus_input(
  *(design_smt_info.get()), var_names, _vtg_config.SygusOptions, datapoints, _width_info );

  auto sygus_fname = os_portable_append_dir(_output_path, sygus_problem_name);
  gen_sygus_input.ExportToFile(sygus_fname);

  return correction_t(gen_sygus_input.GetCorrectionMap());
}


}; // namespace ilang