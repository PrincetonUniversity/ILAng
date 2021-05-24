/// \file Source for generating information to support
/// AQED -- implementation
// --- Hongce Zhang (hongcez@princeton.edu)

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/directive.h>
#include <ilang/vtarget-out/gen_util.h>
#include <ilang/aqed-out/aqed_out_impl.h>

namespace ilang {

AQedInfoGeneratorImpl::AQedInfoGeneratorImpl(
    const std::vector<std::string>& implementation_include_path,
    const std::vector<std::string>& implementation_srcs,
    const std::string& implementation_top_module,
    const std::string& refinement_variable_mapping,
    const std::string& refinement_conditions,
    const InstrLvlAbsCnstPtr& ila_ptr
  ): AQedInfoGenerator(),
      _ila_ptr(ila_ptr), 
      _vlg_impl_top_name(implementation_top_module),
      vlg_info_ptr(NULL),
      _vext(
          [this](const std::string& n) -> bool { return vtgutil::TryFindIlaState(n, this->_ila_ptr, this->_ila_mod_inst_name ); },
          [this](const std::string& n) -> bool { return vtgutil::TryFindIlaInput(n, this->_ila_ptr, this->_ila_mod_inst_name ); },
          [this](const std::string& n) -> bool { return vtgutil::TryFindVlgState(n, this->vlg_info_ptr, this->_vlg_mod_inst_name); }),
      _bad_state(false) {

  load_json(refinement_variable_mapping, rf_vmap);
  supplementary_info.FromJson(rf_vmap);
  load_json(refinement_conditions, rf_cond);
  set_module_instantiation_name();

  if (_ila_ptr == nullptr) {
    ILA_ERROR << "ILA should not be none";
    _bad_state = true;
  }

  vlg_info_ptr = new VerilogInfo(implementation_include_path, implementation_srcs,
                                 _vlg_mod_inst_name, _vlg_impl_top_name);

  if (vlg_info_ptr == NULL || vlg_info_ptr->in_bad_state()) {
    ILA_ERROR << "Unable to generate targets. Verilog parser failed.";
    return; //
  }

} // AQedInfoGeneratorImpl

AQedInfoGeneratorImpl::~AQedInfoGeneratorImpl() {
  if (vlg_info_ptr)
    delete vlg_info_ptr;
}


/// Export the top-level io in  a file
void AQedInfoGeneratorImpl::ExportVerilogTopLevelIOInfo(const std::string &fname) {
  ILA_NOT_NULL(vlg_info_ptr);
  std::ofstream fout(fname);
  ILA_ERROR_IF (!fout.is_open()) << "Unable to write to " << fname ;
  auto top_level_mod_info = vlg_info_ptr->get_top_module_io(supplementary_info.width_info);
  fout << top_level_mod_info.size() << std::endl;
  for (auto && n_sig_pair : top_level_mod_info) {
    fout << n_sig_pair.first << " ";
    auto sig_info = n_sig_pair.second;
    ILA_ASSERT( sig_info.is_io_sig() &&
      ( sig_info.is_input() || sig_info.is_output() ) );
       
    fout << ( sig_info.is_input() ? "input" : "output" ) << " "; 
    fout << ( sig_info.get_width() ) << std::endl;
  }
} // ExportVerilogTopLevelIOInfo

void AQedInfoGeneratorImpl::ExportExtraSignalReferenced(const std::string &fname) {

  std::ofstream fout(fname);
  ILA_ERROR_IF (!fout.is_open()) << "Unable to write to " << fname ;
  fout << outer_var_reference.size() << std::endl;
  for(const auto & vn_io_w: outer_var_reference) {
    const auto & vn = std::get<0>(vn_io_w);
    const auto & io = std::get<1>(vn_io_w);
    const auto & w  = std::get<2>(vn_io_w);
    fout << io << " input " << w << " " << vn << std::endl;
  }
} // ExportExtraSignalReferenced

/// Export the decode function and etc
void AQedInfoGeneratorImpl::ExportInstructionAndDecode(const std::string& filename) {
  ILA_ASSERT(_all_referred_vlg_names.empty());

  VerilogDecodeForAQedGenerator::VlgGenConfig vlg_cfg;
  VerilogDecodeForAQedGenerator vlg_gen(vlg_cfg, "decoder", "__DECODER_CLOCK__", "__DECODER_RESET__");

  // okay, add vlg_ports
  auto top_level_mod_info = vlg_info_ptr->get_top_module_io(supplementary_info.width_info);
  std::set<std::string> top_level_input_name;
  for (const auto & name_siginfo_pair : top_level_mod_info) {
    const auto & n = name_siginfo_pair.first;
    const auto & sig_info = name_siginfo_pair.second;
    if (sig_info.is_input()) { // only add module's input to this module
      vlg_gen.add_input(n, sig_info.get_width());
      top_level_input_name.insert(n);
    }
  }
  // TODO: get var use finder's var
  // do everything just wrt to the var
  std::set<ExprPtr> used_vars_in_decodes;
  vlg_gen.ExportDecode(_ila_ptr, used_vars_in_decodes);
  std::set<std::string> used_vars_names;
  for (auto && v : used_vars_in_decodes)
    used_vars_names.insert(v->name().str());
  
    
  { // add assigns from input directives
    auto& io_map = IN("interface mapping",rf_vmap) ? 
      rf_vmap["interface mapping"] : rf_vmap["interface-mapping"] ;
    
    for (const auto & name_siginfo_pair : top_level_mod_info) {
      if (!name_siginfo_pair.second.is_input())
        continue; // let's just care about the inputs
      std::string refstr =
        IN(name_siginfo_pair.first, io_map)
            ? io_map[name_siginfo_pair.first].get<std::string>()
            : "";
      ILA_ERROR_IF(refstr.empty())
        << "Verilog IO: " << name_siginfo_pair.first << "is missing in"
        << " interface-mapping";
      auto reset_sig = IntefaceDirectiveRecorder::isSpecialInputDirResetName(refstr);
      if (!reset_sig.empty()) 
        refstr = reset_sig;
      else if (IntefaceDirectiveRecorder::isSpecialInputDir(refstr))
        continue;
      if (!IN(refstr,used_vars_names))
        continue; // not referring to something we create with "__ILA_VAR_"
      // it maps to an ILA input
      auto ila_input = _ila_ptr->input(refstr);
      ILA_NOT_NULL(ila_input);
      ILA_ASSERT(ila_input->is_var());
      ILA_ERROR_IF(ila_input->is_mem()) << "Unable to connect input memory";
      auto ila_w = ila_input->sort()->bit_width();
      ILA_ASSERT(ila_w > 0);
      ILA_WARN_IF((unsigned)ila_w != name_siginfo_pair.second.get_width())
        << "ILA and Verilog input width incompatible";
      vlg_gen.add_assign_stmt("__ILA_VAR_"+refstr, name_siginfo_pair.first);
    }
  } // add assigns from input directives
  
  // add assumptions from input, for the reference to ila_top.input, replace it well
  if (IN("mapping control", rf_vmap) || IN("mapping-control", rf_vmap)) {
    auto & mp = IN("mapping control", rf_vmap) ?
      rf_vmap["mapping control"] : rf_vmap["mapping-control"] ;
    
    if (!mp.is_array())
      ILA_ERROR << "mapping-control field must be an array of string";
    for (auto&& c : mp) {
      if (!c.is_string()) {
        ILA_ERROR << "mapping-control field must be an array of string";
        continue;
      }
      _vext.ParseToExtract(c.get<std::string>(), false);
      bool has_in_var = false;
      bool has_out_var = false;
      _vext.ForEachTokenReplace([&](const VarExtractor::token& t) {
                         return CheckNames(t,used_vars_names,has_in_var,has_out_var);
                       });
      ILA_ERROR_IF(has_out_var) << "Assumption: " << c.get<std::string>() << " has out var";
      if (!has_in_var || has_out_var)
        continue;
      _vext.ForEachTokenReplace([this, &top_level_input_name](const VarExtractor::token& t) {
                         return ModifyCondExprAndRecordVlgName(t, top_level_input_name);
                       });
      vlg_gen.add_stmt("assume property (" + _vext.GenString() +");");
    } // for each mapping control  
  } 
  // Question: do we do the same for assumptions?
#if 0 // disable due to `trans` not present in current version
  vlg_gen.GenValidSequenceAssumption(_ila_ptr);
#endif
  // deal with the case that used_vars_in_decodes are not inputs
  // dump in ExportExtraSignalReferenced, but you need to add inputs
  RegisterExtraVlgReferenceWire(vlg_gen);
  vlg_gen.GenSequenceAssumtionsAny();
  vlg_gen.GenSequenceOneAtATime();
  
  std::ofstream fout(filename);
  ILA_ERROR_IF(!fout.is_open()) << "Unable to write to " << filename;
  vlg_gen.DumpToFile(fout);
}


void AQedInfoGeneratorImpl::RegisterExtraVlgReferenceWire(VerilogGeneratorBase& vlg_gen) {
  for (const auto& refered_vlg_item : _all_referred_vlg_names) {

    auto idx = refered_vlg_item.first.find("[");
    auto removed_range_name = refered_vlg_item.first.substr(0, idx);
    auto vlg_sig_info = vlg_info_ptr->get_signal(removed_range_name,
                                                 supplementary_info.width_info);

    auto vname = ReplaceAll(
        ReplaceAll(ReplaceAll(refered_vlg_item.first, ".", "__DOT__"), "[",
                   "_"),
        "]", "_");
    // + ReplaceAll(ReplaceAll(refered_vlg_item.second.range, "[","_"),"]","_");
    // // name for verilog
    auto width = vlg_sig_info.get_width();
    ILA_ASSERT(width > 0);
    vlg_gen.add_wire(vname, width, 1); // keep
    vlg_gen.add_input(vname, width);  // add as output of the wrapper
    outer_var_reference.push_back(
      std::make_tuple(
        refered_vlg_item.first, vname, (unsigned) width) );
    // these will be connected to the verilog module, so register as extra wires
    // so, later they will be connected
  }
} 

// we need to export all inputs
// relation of the wires and the inputs

} // namespace ilang
