/// \file Verilog Wrapper Class

#include <ilang/verilog-in/verilog_analysis.h>

#include <ilang/util/log.h>

namespace ilang {

VerilogInfo::VerilogInfo(const path_vec_t& include_path, const path_vec_t& srcs,
                         const std::string& top_module_inst_name,
                         const std::string& optional_top_module)
    : _analyzer(new VerilogAnalyzer(include_path, srcs, top_module_inst_name,
                                    optional_top_module)) {
  // do nothing
}
VerilogInfo::~VerilogInfo() { delete _analyzer; }

VerilogInfo::hierarchical_name_type
VerilogInfo::check_hierarchical_name_type(const std::string& net_name) const {
  // get the raw and convert -- a bit dangerous but we won't delete it, so
  // should be fine
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->check_hierarchical_name_type(net_name);
}
/// Return the declaration of a name, which could be be converted to:
/// ast_module_declaration, ast_net_declaration, ast_reg_declaration,
/// ast_port_declaration
void* VerilogInfo::find_declaration_of_name(const std::string& net_name) const {
  // get the raw and convert -- a bit dangerous but we won't delete it, so
  // should be fine
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->find_declaration_of_name(net_name);
}
/// Return the location of a hierarchical name
VerilogInfo::vlg_loc_t
VerilogInfo::name2loc(const std::string& net_name) const {
  // get the raw and convert -- a bit dangerous but we won't delete it, so
  // should be fine
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->name2loc(net_name);
}

/// Return the location of a module instantiation
VerilogInfo::vlg_loc_t
VerilogInfo::get_module_inst_loc(const std::string& inst_name) const {
  // get the raw and convert -- a bit dangerous but we won't delete it, so
  // should be fine
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->get_module_inst_loc(inst_name);
}

/// Return top module name
std::string VerilogInfo::get_top_module_name() const {
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->get_top_module_name();
}
/// Return top module signal
VerilogInfo::module_io_vec_t VerilogInfo::get_top_module_io() const {
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->get_top_module_io();
}

VerilogInfo::module_io_vec_t VerilogInfo::get_top_module_io(
    const std::map<std::string, int>& width_info) const {
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->get_top_module_io(&width_info);
}

SignalInfoBase VerilogInfo::get_signal(const std::string& net_name) const {
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->get_signal(net_name);
}

/// Find a signal (and use the width info, if width is unknown)
SignalInfoBase
VerilogInfo::get_signal(const std::string& net_name,
                        const std::map<std::string, int>& width_info,
                        const std::map<std::string, int>& range_info) const {
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->get_signal(net_name, &width_info, &range_info);
}

bool VerilogInfo::in_bad_state() const {
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->in_bad_state();
}

/// Return the location of a module's endmodule statement
VerilogInfo::vlg_loc_t
VerilogInfo::get_endmodule_loc(const std::string& inst_name) const {
  const VerilogAnalyzer* _ptr = dynamic_cast<const VerilogAnalyzer*>(_analyzer);
  ILA_NOT_NULL(_ptr);
  return _ptr->get_endmodule_loc(inst_name);
}

/// overload the operator << for printing location
std::ostream& operator<<(std::ostream& os,
                         const VerilogAnalyzerBase::vlg_loc_t& obj) {
  return VerilogAnalyzerBase::PrintLoc(os, obj);
}

}; // namespace ilang
