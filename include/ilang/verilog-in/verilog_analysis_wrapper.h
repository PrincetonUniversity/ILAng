/// \file Wrapper for the external interface of Verilog Analyzer
/// This file exposes the interface of verilog analyzer
/// and we hope to use it to hide the dependency on the header
/// of Verilog Parser. VerilogAnalyzerBase is just a base class
/// used for pointer and should not be instantiated.
/// VerilogInfo creates
///
///  --- Hongce Zhang

#ifndef ILANG_VERILOG_IN_VERILOG_ANALYSIS_WRAPPER_H__
#define ILANG_VERILOG_IN_VERILOG_ANALYSIS_WRAPPER_H__

#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace ilang {

class SignalInfoBase;

/// \brief VerilogAnalyzerBase should never be instantiated, only used as a
/// pointer type in class VerilogInfo
class VerilogAnalyzerBase {
public:
  /// type to store multiple paths
  typedef std::vector<std::string> path_vec_t;
  /// filename, line number pair : location type
  typedef std::pair<std::string, long> vlg_loc_t;
  /// A map of name -> names
  typedef std::map<std::string, std::vector<std::string>> name_names_map_t;
  /// type of modulename instance name : instance_name->module_name
  typedef std::map<std::string, std::string> mod_inst_t;
  /// A map of module name -> instantiation
  typedef std::map<std::string, mod_inst_t> name_insts_map_t;
  /// The result of querying a name (please don't change the order of them)
  typedef enum {
    NONE = 0,
    MODULE, /*1*/
    I_WIRE_wo_INTERNAL_DEF,
    /*2*/ // module (input [3:0] a, output reg b) ; no internal defininition
    O_WIRE_wo_INTERNAL_DEF,  /*3*/
    IO_WIRE_wo_INTERNAL_DEF, /*4*/
    I_WIRE_w_INTERNAL_DEF,
    /*5*/ // module (a,b,c); input c **OR** module (input [3:0] a) ; wire [3:0]
          // a;
    O_WIRE_w_INTERNAL_DEF,  /*6*/
    IO_WIRE_w_INTERNAL_DEF, /*7*/
    O_REG_wo_INTERNAL_DEF,  /*8*/
    O_REG_w_INTERNAL_DEF,   /*9*/
    REG /*10*/,
    WIRE /*11*/,
    OTHERS /*12*/
  } hierarchical_name_type;
  /// hierarchical name -> hierarchical_name_type  map
  typedef std::map<std::string, hierarchical_name_type> name_type_buffer_t;
  /// hierarchical name -> declaration pointer
  typedef std::map<std::string, void*> name_decl_buffer_t;
  /// Top module signal list
  typedef std::map<std::string, SignalInfoBase> module_io_vec_t;

public:
  // --------------------- HELPER FUNCTIONS ---------------------------- //
  /// decide if a type is a register (port w or wo internal def / internal)
  static bool is_reg(hierarchical_name_type tp_) {
    return tp_ == O_REG_wo_INTERNAL_DEF || tp_ == O_REG_w_INTERNAL_DEF ||
           tp_ == REG;
  }
  /// decide if the type is a wire (port w or wo internal def / internal)
  static bool is_wire(hierarchical_name_type tp_) {
    return (tp_ >= I_WIRE_wo_INTERNAL_DEF && tp_ <= IO_WIRE_w_INTERNAL_DEF) ||
           tp_ == WIRE;
  }
  ///  decide if a type has no internal def
  static bool no_internal_def(hierarchical_name_type tp_) {
    return (tp_ >= I_WIRE_wo_INTERNAL_DEF && tp_ <= IO_WIRE_wo_INTERNAL_DEF) ||
           tp_ == O_REG_wo_INTERNAL_DEF;
  }
  /// decide if a type is module
  static bool is_module(hierarchical_name_type tp_) {
    return tp_ == hierarchical_name_type::MODULE;
  }
  /// decide if it is port signal
  static bool is_io_sig(hierarchical_name_type tp_) {
    return tp_ >= I_WIRE_wo_INTERNAL_DEF && tp_ <= O_REG_w_INTERNAL_DEF;
  }
  /// decide if it is input signal
  static bool is_input(hierarchical_name_type tp_) {
    return (tp_ == I_WIRE_wo_INTERNAL_DEF) || (tp_ == I_WIRE_w_INTERNAL_DEF);
  }
  /// decide if it is output signal
  static bool is_output(hierarchical_name_type tp_) {
    return is_io_sig(tp_) && !is_input(tp_);
  }
  /// Print  location info
  static std::ostream& PrintLoc(std::ostream& os, const vlg_loc_t& loc) {
    return (os << (loc.first) << ":" << (loc.second));
  }

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  /// Constructor: do nothing
  VerilogAnalyzerBase(){};
  // --------------------- DESTRUCTOR ---------------------------- //
  /// do nothing!
  virtual ~VerilogAnalyzerBase(){};

  /// Please do not instantiate this class, only used as a pointer type
};

/// \brief Class to hold signal info
class SignalInfoBase {
protected:
  /// --------------------- MEMBERS ------------------- ///
  /// its own name
  const std::string _name;
  /// full name
  const std::string _hierarchical_name;
  /// width of the signal
  const unsigned _width;
  /// its type
  const VerilogAnalyzerBase::hierarchical_name_type _type;
  /// its location of definition
  const VerilogAnalyzerBase::vlg_loc_t _loc;
  /// addr range size of the array, 0 if not array
  const unsigned _addr_range_size;

public:
  /// --------------------- ACCESSORS ------------------- ///
  /// Return the width of the signal
  virtual unsigned get_width() const { return _width; }
  /// Return the addrwidth of the signal
  virtual unsigned get_addr_range_size() const {return _addr_range_size; }
  /// Whether is a IO signal
  virtual bool is_io_sig() const {
    return VerilogAnalyzerBase::is_io_sig(_type);
  }
  /// Whether it is defined only at the port
  virtual bool no_internal_def() const {
    return VerilogAnalyzerBase::no_internal_def(_type);
  }
  /// Whether it is a register
  virtual bool is_reg() const { return VerilogAnalyzerBase::is_reg(_type); }
  /// Whether it is an input signal
  virtual bool is_input() const { return VerilogAnalyzerBase::is_input(_type); }
  /// Whether it is an output signal
  virtual bool is_output() const {
    return VerilogAnalyzerBase::is_output(_type);
  }
  /// Whether this info is usable
  virtual bool is_bad_signal() const {
    return _type == VerilogAnalyzerBase::hierarchical_name_type::NONE;
  }
  /// return its type
  virtual VerilogAnalyzerBase::hierarchical_name_type get_type() const {
    return _type;
  }
  /// Return its location
  virtual VerilogAnalyzerBase::vlg_loc_t get_decl_loc() const { return _loc; }
  /// Return is own name
  virtual std::string get_signal_name() const { return _name; }
  /// Return its hierarchical name
  virtual std::string get_hierarchical_name() const {
    return _hierarchical_name;
  }

public:
  /// --------------------- ACCESSORS ------------------- ///
  SignalInfoBase(const std::string& n, const std::string& h, unsigned w,
                 const VerilogAnalyzerBase::hierarchical_name_type& typ,
                 const VerilogAnalyzerBase::vlg_loc_t& loc,
                 unsigned aw)
      : _name(n), _hierarchical_name(h), _width(w), _type(typ), _loc(loc), _addr_range_size(aw) {}
  /// implicit copy constructor
}; // class SignalInfoBase

/// \brief The class that invoke the analyzer
class VerilogInfo {

public:
  /// type to store multiple paths
  using path_vec_t = VerilogAnalyzerBase::path_vec_t;
  /// filename, line number pair : location type
  using vlg_loc_t = VerilogAnalyzerBase::vlg_loc_t;
  /// A map of name -> names
  using name_names_map_t = VerilogAnalyzerBase::name_names_map_t;
  /// type of modulename instance name : instance_name->module_name
  using mod_inst_t = VerilogAnalyzerBase::mod_inst_t;
  /// A map of module name -> instantiation
  using name_insts_map_t = VerilogAnalyzerBase::name_insts_map_t;
  /// The result of querying a name (please don't change the order of them)
  using hierarchical_name_type = VerilogAnalyzerBase::hierarchical_name_type;
  /// hierarchical name -> hierarchical_name_type  map
  using name_type_buffer_t = VerilogAnalyzerBase::name_type_buffer_t;
  /// hierarchical name -> declaration pointer
  using name_decl_buffer_t = VerilogAnalyzerBase::name_decl_buffer_t;
  /// Top module signal list
  using module_io_vec_t = VerilogAnalyzerBase::module_io_vec_t;

private:
  // --------------------- MEMBERS ---------------------------- //
  /// the pointer, it will be used to hold a pointer of the derived class
  VerilogAnalyzerBase* _analyzer;

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  /// Analyze a set of file
  /// [in] the path to search for include
  /// [in] the source files
  /// [in] the instance name given to the topmodule
  /// \param[in] an optional of the top module name, can be left empty
  VerilogInfo(const path_vec_t& include_path, const path_vec_t& srcs,
              const std::string& top_module_inst_name,
              const std::string& optional_top_module = "");
  /// Please don't make a copy of it
  VerilogInfo(const VerilogInfo&) = delete;
  /// Please don't use assignment over it
  VerilogInfo& operator=(const VerilogInfo&) = delete;
  // --------------------- DESTRUCTOR ---------------------------- //
  /// Destructor: no need to clean, unique_ptr does the job
  virtual ~VerilogInfo();

public:
  // --------------------- INTERFACE ---------------------------- //
  /// Return the type of a name (used externally, cached)
  hierarchical_name_type
  check_hierarchical_name_type(const std::string& net_name) const;
  /// Return the declaration of a name, which could be be converted to:
  /// ast_module_declaration, ast_net_declaration, ast_reg_declaration,
  /// ast_port_declaration (should not be used!) because you don't know what to
  /// convert left here for debugging purpose only
  void* find_declaration_of_name(const std::string& net_name) const;
  /// Return the location of a hierarchical name
  vlg_loc_t name2loc(const std::string& net_name) const;
  /// Return the location of a module instantiation
  vlg_loc_t get_module_inst_loc(const std::string& inst_name) const;
  /// Return the location of a module's endmodule statement
  vlg_loc_t get_endmodule_loc(const std::string& inst_name) const;
  /// Return top module name
  std::string get_top_module_name() const;
  /// Return top module signal with no hint on the width
  module_io_vec_t get_top_module_io() const;
  /// Return top module signal
  module_io_vec_t
  get_top_module_io(const std::map<std::string, int>& width_info) const;
  /// Find a signal
  SignalInfoBase get_signal(const std::string& net_name) const;
  /// Find a signal (and use the width info, if width is unknown)
  SignalInfoBase get_signal(const std::string& net_name,
                            const std::map<std::string, int>& width_info,
                            const std::map<std::string, int>& range_info) const;
  /// whether this analyzer is in bad state
  bool in_bad_state() const;

}; // class Verilog Info

/// overload the operator << for printing location
std::ostream& operator<<(std::ostream& os,
                         const VerilogAnalyzerBase::vlg_loc_t& obj);

}; // namespace ilang

#endif // ILANG_VERILOG_IN_VERILOG_ANALYSIS_WRAPPER_H__
