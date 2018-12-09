/// \file Verilog Wrapper Class
#include <ilang/util/log.h>
#include <ilang/verilog-in/verilog_analysis.h>

namespace ilang {

  VerilogInfo::VerilogInfo(const path_vec_t & include_path, const path_vec_t & srcs, const std::string & top_module_inst_name ):
  _analyzer( new VerilogAnalyzer( include_path,srcs, top_module_inst_name ) )
  {
  	// do nothing
  }
  VerilogInfo::~VerilogInfo() { delete _analyzer; }

  VerilogInfo::hierarchical_name_type VerilogInfo::check_hierarchical_name_type(const std::string & net_name) const
  {
  	// get the raw and convert -- a bit dangerous but we won't delete it, so should be fine
  	const VerilogAnalyzer * _ptr = dynamic_cast<const VerilogAnalyzer *>( _analyzer );
  	ILA_NOT_NULL(_ptr);
  	return _ptr->check_hierarchical_name_type(net_name);
  }
  /// Return the declaration of a name, which could be be converted to: ast_module_declaration, ast_net_declaration, ast_reg_declaration, ast_port_declaration
  void * VerilogInfo::find_declaration_of_name(const std::string & net_name) const
  {
  	// get the raw and convert -- a bit dangerous but we won't delete it, so should be fine
  	const VerilogAnalyzer * _ptr = dynamic_cast<const VerilogAnalyzer *>( _analyzer );
  	ILA_NOT_NULL(_ptr);
  	return _ptr->find_declaration_of_name(net_name);
  }
  /// Return the location of a hierarchical name
  VerilogInfo::vlg_loc_t VerilogInfo::name2loc(const std::string & net_name) const
  {
  	// get the raw and convert -- a bit dangerous but we won't delete it, so should be fine
  	const VerilogAnalyzer * _ptr = dynamic_cast<const VerilogAnalyzer *>( _analyzer );
  	ILA_NOT_NULL(_ptr);
  	return _ptr->name2loc(net_name);
  }

  /// Return top module name
  std::string VerilogInfo::get_top_module_name() const {
  	const VerilogAnalyzer * _ptr = dynamic_cast<const VerilogAnalyzer *>( _analyzer );
  	ILA_NOT_NULL(_ptr);
  	return _ptr->get_top_module_name();
  }
  /// Return top module signal
  VerilogInfo::module_io_vec_t VerilogInfo::get_top_module_io() const {
  	const VerilogAnalyzer * _ptr = dynamic_cast<const VerilogAnalyzer *>( _analyzer );
  	ILA_NOT_NULL(_ptr);
  	return _ptr->get_top_module_io();
  }


/// overload the operator << for printing location
std::ostream & operator<<(std::ostream & os, const VerilogAnalyzerBase::vlg_loc_t & obj ) { return VerilogAnalyzerBase::PrintLoc(os,obj); }

}; // namespace ilang