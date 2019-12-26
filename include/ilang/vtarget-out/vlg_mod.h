/// \file The header for verilog modification class
/// The modification are mainly for CoSA
/// 1. Add (* keep *)
/// 2. Add interface wires
///   2a. module declaration
///   2b. module instantiation
///   2c. wire and assign
// ---Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_VTARGET_OUT_VLG_MOD_H__
#define ILANG_VTARGET_OUT_VLG_MOD_H__

#include <map>
#include <string>
#include <vector>

#include <ilang/verilog-in/verilog_analysis_wrapper.h>

namespace ilang {

/// \brief the class for modification to verilog
class VerilogModifier {
public:
  // ---------------------- TYPE ------------------------- //
  /// a tuple to store all related info for modification
  typedef std::tuple<long,        // lineno
                     std::string, // varname (short name)
                     bool>
      info_t;
  /// filename -> (lineno, varname, is_port_sig) vec
  typedef std::map<std::string, // file name
                   std::vector<info_t>>
      fn_l_map_t;
  /// type of a module decl modification item
  typedef std::tuple<long,        // lineno
                                  // std::string, // module name
                     std::string, // varname to add a__DOT__b__DOT__ ...
                     unsigned>    // width
      mod_decl_item_t;

  /// type of a module inst modification item
  typedef std::tuple<long,        // lineno
                                  // std::string, // instance name
                     std::string, // varname to add a__DOT__b__DOT__ ...
                     unsigned>    // width
      mod_inst_item_t;

  /// type of an wire assignment modification item
  typedef std::tuple<long,        // lineno
                     std::string, // varname
                     unsigned,    // width
                     std::string> // short_sig_name;
      assign_item_t;

  /// type of an additional statement of an module
  typedef std::tuple<long,        // lineno
                     std::string> // stmt
      add_stmt_t;

  /// type of decl modification record
  typedef std::map<std::string, // file name
                   std::vector<mod_decl_item_t>>
      mod_decl_map_t;

  /// type of a module inst modification record
  typedef std::map<std::string, // file name
                   std::vector<mod_inst_item_t>>
      mod_inst_map_t;

  /// type of an wire assignment modification record
  typedef std::map<std::string, // file name
                   std::vector<assign_item_t>>
      assign_map_t;

  /// type of additional stmt modification record
  typedef std::map<std::string, // filename
                   std::vector<add_stmt_t>>
      add_stmt_map_t;

  /// type of an wire name w. width
  typedef std::pair<std::string, unsigned> vlg_sig_t;

  /// The style or port declaration
  typedef enum { AUTO = 0, NEW = 1, OLD = 2 } port_decl_style_t;

public:
  /// \brief Constructor:
  /// \param[in] pointer to a verilog info  class
  /// \param[in] the style: 0 auto deteremined, 1 Old, 2 New
  VerilogModifier(VerilogInfo* _vlg_info_ptr, port_decl_style_t port_decl_style,
                  bool add_keep_or_not,
                  const std::map<std::string, int>& _sup_width_info); //
  /// Destructor:
  ~VerilogModifier();
  /// do the work : read from fin and append to fout, fout needs to be open with
  /// append option
  void ReadModifyWrite(const std::string& filename, std::istream& fin,
                       std::ostream& fout);
  /// do some work (sorting)
  void FinishRecording();
  /// record the name to add a keep there
  void RecordKeepSignalName(const std::string& vname);
  /// record the name to add related wires
  vlg_sig_t RecordConnectSigName(const std::string& vlg_sig_name,
                                 const std::string& suffix = "");
  /// record the stmt to be added to a module
  void RecordAdditionalVlgModuleStmt(const std::string& stmt,
                                     const std::string& mod_instance_name);

protected:
  // --------------- MEMBERS ---------------------------- //
  /// the record of where to insert keep
  fn_l_map_t fn_l_map;
  /// decl modification record
  mod_decl_map_t mod_decl_map;
  /// a module inst modification record
  mod_inst_map_t mod_inst_map;
  /// an wire assignment modification record
  assign_map_t assign_map;
  /// a additional stmt modification record
  add_stmt_map_t add_stmt_map;
  /// The pointer object so we can get verilog information of the implementation
  VerilogInfo* vlg_info_ptr;
  /// cache the style
  port_decl_style_t _port_decl_style;
  /// whether to add keep
  bool _add_keep_or_not;
  /// the supplementary width info
  const std::map<std::string, int>& sup_width_info;

protected:
  // --------------- HELPERS --------------------------- //
  static std::string add_keep_to_port(const std::string& line_in,
                                      const std::string& vname);
  static std::string add_keep_to_a_line(const std::string& line_in,
                                        const std::string& vname);
  static std::string
  add_assign_wire_to_this_line(const std::string& line_in,
                               const std::string& vname, unsigned width,
                               const std::string& short_name);
  bool add_mod_decl_wire_to_this_line(const std::string& line_in,
                                      std::string& line_out,
                                      const std::string& vname, unsigned width);
  bool add_mod_inst_wire_to_this_line(const std::string& line_in,
                                      std::string& line_out,
                                      const std::string& vname, unsigned width);

}; // class VerilogModifier

}; // namespace ilang

#endif // ILANG_VTARGET_OUT_VLG_MOD_H__
