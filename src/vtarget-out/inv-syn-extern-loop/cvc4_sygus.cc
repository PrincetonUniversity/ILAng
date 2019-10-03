/// \file The source for invariant synthesis --- using the SyGuS method
// ---Hongce Zhang

#include <ilang/util/fs.h>
#include <ilang/util/log.h>
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
  const std::string & sygus_problem_name,
  const Cvc4Syntax & syntax) {
  
  ILA_WARN_IF(!os_portable_mkdir(_output_path) ) << "Cannot create folder: " << _output_path;

  if(datapoints) {

    Cvc4SygusInputGenerator gen_sygus_input(
    *(design_smt_info.get()), var_names, _vtg_config.SygusOptions, datapoints, _width_info, syntax );

    auto sygus_fname = os_portable_append_dir(_output_path, sygus_problem_name);
    gen_sygus_input.ExportToFile(sygus_fname);
    GenerateSygusScript(script_name, sygus_problem_name);

    runnable_script_name.push_back(os_portable_append_dir(_output_path, script_name));

    return correction_t(gen_sygus_input.GetCorrectionMap());
  } else {

    ILA_ASSERT (_vtg_config.YosysSmtFlattenDatatype)
      << "For SyGuS through passing transfer function, datatype must be flattened!";
    // now when you call load_smt_from_file, it has already been flattened

    std::string smt_converted;
    smt_converted = design_smt_info->Export();

    Cvc4SygusChcGenerator gen_sygus_input(
      *(design_smt_info.get()), var_names, _vtg_config.SygusOptions,
      smt_converted, _width_info, syntax);

    auto sygus_fname = os_portable_append_dir(_output_path, sygus_problem_name);
    gen_sygus_input.ExportToFile(sygus_fname);
    GenerateSygusScript(script_name, sygus_problem_name);

    runnable_script_name.push_back(os_portable_append_dir(_output_path, script_name));

    return correction_t(gen_sygus_input.GetCorrectionMap());
  }

}

const std::vector<std::string> & ExternalSygusTargetGen::GetRunnableScriptName() const {
  return runnable_script_name;
}

void ExternalSygusTargetGen::GenerateSygusScript(
  const std::string & script_name, 
  const std::string & sygus_problem_name) {
  auto fname = os_portable_append_dir(_output_path, script_name);
  std::ofstream fout(fname);
  if (!fout.is_open()) {
    ILA_ERROR << "Error writing to file:" << fname;
    return;
  }
  fout << "#!/bin/bash" << std::endl;
  //fout << "trap \"trap - SIGTERM && kill -- -$$\" SIGINT SIGTERM"<<std::endl;

  std::string runnable = "cvc4";
  std::string redirect_file = "../__synthesis_result.txt";
  std::string options; // = " --sygus-stream --sygus-pbe";
  if (enumerate)
    options = " --sygus-stream"; // force searching all 

  if (not _vtg_config.Cvc4Path.empty())
    runnable = os_portable_append_dir(_vtg_config.Cvc4Path, runnable);

  if (sygus_problem_name != "")
    fout << runnable << options << " --lang=sygus "<< sygus_problem_name  
         << " > " << redirect_file  << std::endl; // << " &"
  else
    fout << "echo 'Nothing to check!'" << std::endl;

  // we will always return as long as we see some answer
  /*
  fout << "inotifywait " << redirect_file << " -e modify\n";
  fout << "while [ ! -s \"" << redirect_file << "\" ]; do\n";
  fout << "  echo \"Empty file ... +1s\"\n";
  fout << "  sleep 1\n";
  fout << "done\n";
  fout << "trap 'kill $(jobs -p)' EXIT\n";*/
}
}; // namespace ilang