/// \file Header for generating decode for each instruction
// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef ILANG_AQED_OUT_VLOG_OUT_H__
#define ILANG_AQED_OUT_VLOG_OUT_H__

#include <ilang/verilog-out/verilog_gen.h>

namespace ilang {

/// \brief Class of Verilog Decode AQed Generator
class VerilogDecodeForAQedGenerator : public VerilogGenerator {
public:
  // --------------------- TYPE DEFINITIONS ---------------------------- //
  /// let the test class use this module
  friend class TestVerilogExport;
  /// Type of Verilog id names'
  using vlg_name_t = VerilogGenerator::vlg_name_t;
  /// Type of Verilog statement
  using vlg_stmt_t = VerilogGenerator::vlg_stmt_t;
  /// Type of Verilog address
  using vlg_addr_t = VerilogGenerator::vlg_addr_t;
  /// Type of Verilog data
  using vlg_data_t = VerilogGenerator::vlg_data_t;
  /// Type of Verilog statements (a vector)
  using vlg_stmts_t = VerilogGenerator::vlg_stmts_t;
  /// Type of Verilog names (a vector)
  using vlg_names_t = VerilogGenerator::vlg_names_t;
  /// Type of Verilog signal, name & bw
  using vlg_sig_t = VerilogGenerator::vlg_sig_t;
  /// Type of Verilog signals (a vector)
  using vlg_sigs_t = VerilogGenerator::vlg_sigs_t;
  /// Type of a map: name -> need to add keep?
  using vlg_sig_keep_t = VerilogGenerator::vlg_sig_keep_t;
  /// Type of set of Verilog signals
  using vlg_sigs_set_t = VerilogGenerator::vlg_sigs_set_t;
  /// Type of Verilog ITEs (IN sequential block)
  using vlg_ite_stmt_t = VerilogGenerator::vlg_ite_stmt_t;
  /// Type of Verilog ITEs statements
  using vlg_ite_stmts_t = VerilogGenerator::vlg_ite_stmts_t;
  /// Type of the memorys that are going to be created
  using vlg_mem_t = VerilogGenerator::vlg_mem_t;
  /// Type of collection of memorys
  using vlg_mems_rec_t = VerilogGenerator::vlg_mems_rec_t;
  /// This is type of an individual write.
  using mem_write_entry_t = VerilogGenerator::mem_write_entry_t;
  /// This is type of a list of writes.
  using mem_write_entry_list_t = VerilogGenerator::mem_write_entry_list_t;
  /// Type of a stack of writes use in visitMemNodes
  using mem_write_entry_list_stack_t =
      VerilogGenerator::mem_write_entry_list_stack_t;
  /// This is the write and its associated condition.
  using mem_write_t = VerilogGenerator::mem_write_t;
  /// List of writes w. associated conditions.
  using mem_write_list_t = VerilogGenerator::mem_write_list_t;
  /// Type for caching the generated expressions.
  using ExprMap = VerilogGenerator::ExprMap;
  // VerilogGen Configure
  /// the structure to configure the verilog generator
  using VlgGenConfig = VerilogGenerator::VlgGenConfig;
  /// Type of function apply record
  using function_app_t = VerilogGenerator::function_app_t;
  /// Type of func app vector record
  using function_app_vec_t = VerilogGenerator::function_app_vec_t;

protected:
  // --------------------- MEMBERS ---------------------------- //
  vlg_names_t all_decode_signals;

  // --------------------- HELPER FUNCTIONS ---------------------------- //
  /// Handle function application , Caller: translateBoolOp, translateBvOp
  virtual vlg_name_t translateApplyFunc(std::shared_ptr<ExprOpAppFunc> func_app_ptr_) override;

  /// called by ParseNonMemUpdateExpr to deal with a boolop node
  virtual vlg_name_t translateBoolOp(const std::shared_ptr<ExprOp>& e) override;
  /// called by ParseNonMemUpdateExpr to deal with a bvop node
  virtual vlg_name_t translateBvOp(const std::shared_ptr<ExprOp>& e) override;
  /// travserse an expression, not used as mem-write subtree
  virtual void ParseNonMemUpdateExpr(const ExprPtr& e);

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  /// \param[in] Configuration
  /// \param[in] Top module name, if empty, get it from instruction name
  /// \param[in] clock signal name
  /// \param[in] reset signal name
  VerilogDecodeForAQedGenerator(const VlgGenConfig& config = VlgGenConfig(),
                   const std::string& modName = "",
                   const std::string& clk = "clk",
                   const std::string& rst = "rst");
  /// Parse an ILA, will gen all its instructions, and get the var used
  void ExportDecode(const InstrLvlAbsCnstPtr& ila_ptr_, 
    std::set<ExprPtr> & var_use_in_decodes);
  /// add a signel and assumption of the allowed sequences --- any single one is good
  void GenSequenceAssumtionsAny();
  void GenSequenceOneAtATime();

  // for the trans seq in ILA specification, generate the sequence for it
  // but you probably need to specify a bound
  void GenValidSequenceAssumption(const InstrLvlAbsCnstPtr& ila_ptr_);

  /// add a signel and assumption of the allowed sequences --- give a bad state and
  /// try enumerate sequence with out reaching that state
  // Not implemented yet
  void GenSequenceAssumtionsNotBadState();
}; // class VerilogDecodeForAQedGenerator

}; // namespace ilang

#endif // ILANG_AQED_OUT_VLOG_OUT_H__